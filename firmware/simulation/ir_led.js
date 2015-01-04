/**
 * (3.3VSource)
 *  |
 *  +--(LED1)->|--(R_LED1)vvvv------+
 *                                  |
 *  (3.3VSignal)---vvv(R_BASE)----|-- (2SC1815)
 *                                |->
 *                                  |
 *                           (GND)--+
 * LED1 current (A) : LED1_AMPERE
 * LED1 current (V) : LED1_VOLTAGE
 * POWER SOURCE (V) : SOURCE_VOLTAGE
 */

"use strict"

var LED1_AMPERE = 0.2; // 100 mA
var LED1_VOLTAGE = 1.35; // 1.35 V
var SOURCE_VOLTAGE = 3.3; // 3.3 V
var TRANSISTOR_HFR = 100; // An amplification factor

var resistor_led1 = (SOURCE_VOLTAGE - LED1_VOLTAGE) / LED1_AMPERE
console.log("R_LED1: " + resistor_led1 + ' Ohm');

var BUFFER_FACTOR = 2.0;
var resistor_base = (SOURCE_VOLTAGE - 0.6) / (LED1_AMPERE / TRANSISTOR_HFR) * BUFFER_FACTOR
console.log("R_BASE: " + resistor_base + ' Ohm (' + resistor_base / 1000 + ' K Ohm)');
