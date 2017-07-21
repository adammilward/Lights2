/*
 * Light.h
 *
 *  Created on: 5 Dec 2016
 *      Author: Adam Milward
 */

#include "Config.h"

#ifndef Light_h_
#define Light_h_

class Light{
public:
	// mode for automatic fading
    enum fadeMode { LIN, SIN, EXP, EXPSIN };
    static fadeMode fMode;

	float base;     // the base value <1, for deriving power <0 is off
	int power;      // led Power 1 to 255 derived from base

	Light();

	Light(
		const int inPin,
		const int ID,
		float inLower = 0, // lower limit 0 to 0.8
		float inUpper = 1  // upper limit 0.2 t0 1
	);
	void shift(int op, float shiftGain = DEF_GAIN);
	void set(float setBase, bool flash = false);
	void slide();
	void toHalf();
	void changeLower(int op, float change = 0.1);
	void changeUpper(int op, float change = 0.1);
	void flashOff();
	void flashHalf();
	void flashOn();

private:
	static constexpr float DEF_GAIN = 0.0625;     // default gain for use with Shift()

	int pin;            // the pin for this colour
	int id;             // 0 = red 1 = green 2 = blue
	// below are only used for fading
	int shiftOp = 1;    // 1 or -1  controls the direction of shift

	const float MIN_GAIN = 0.0002;
	float gain;         // for fading the lights <= 0.002
	float lower;        // lower limit 1 to 255
	float range;        // range/multiplier 0 to 1

	float randomize();
	void calcPow();     // called from Slide()
};

#endif /* LIGHT_H_ */
