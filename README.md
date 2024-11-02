# GPX-test-track
Grand Prix / Pinewood test track timer


/* March 2024 A six foot long test track for evaluating rolling performance of Grand Prix / Pinewood cars.
Using aluminum mounted to a wood frame, simulate the flat section of the grand prix track and encourage
car builders to spend more time on rolling resistance and wheel alignment.  A function of car build most often overlooked
in the weeks leading up to the race.  This test track has a timer to evaluate how well the car rolls over a six foot section.
The track can be adjusted to 1, 2, or 3 degree slope, changing the influence of gravity, see how well their cars roll.
Trimming the injection molding tabs from the tires, polishing the axles and even providing some camber to the alignment are
advantages that contribute to faster track times, or builders can tune for the turtle award. (slowest)   
Use an Atmega chip to count seconds between the starting pin and end pin. Uno or Mini,  Maybe Tiny85 for production.
9.999 is a failed attempt on the test track as well as race day.
IR detectors and emitters at the start and end will trigger the timer.  
Display the time after complete.
The timer will reset via the chip reset pin and an external button.
18650 batteries iside an external box for the controller.
CAT5 cable between the controller and the board because this can all be done with 8 wires.

September 2024 - first code development on UNO
October 2024 - working code with i2c 14seg display. Deploy on a Nano because its tiny and has a 5v regulator.  
Serial output can be enabled for debugging.
*/
