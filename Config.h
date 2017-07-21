/*
 * Config.h
 *
 *  Created on: 11 Mar 2017
 *      Author: Adam Milward
 */

#ifndef CONFIG_H_
#define CONFIG_H_
class CONFIG {
public:
    static const int DELAY_MIN = 1;
    static const int DELAY_MAX = 256;
    /* Uno */                       //   ________
    static const int RED_PIN = 2;  //  |   __   |
    static const int GREEN_PIN = 3;//  |  /  \  |
    static const int BLUE_PIN = 4;  //  | |    | |
    static const int IREC_PIN = 12;  //  out  0  v+

    static const int RED_ID = 0;
    static const int GREEN_ID = 1;
    static const int BLUE_ID = 2;

    /* Mega
    static const int RED_PIN = 10;
    static const int GREEN_PIN = 9;
    static const int BLUE_PIN = 6;
    static const int IREC_PIN = 12;
     */
};
#endif /* CONFIG_H_ */
