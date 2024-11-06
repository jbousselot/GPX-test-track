## GPX-test-track
Grand Prix / Pinewood test track timer


March 2024 - FINALLY put this idea into action and wrote it down on paper.
Build a six foot long test track for evaluating rolling performance of Grand Prix / Pinewood cars.
Using aluminum mounted to a wood frame, simulate the flat section of the grand prix track and encourage car builders to spend more time on rolling resistance and wheel alignment.  The flat section of Grand Prix/Pinewood is 3/4 of the race.
Coasting is a function of car build most often overlooked in the weeks leading up to the race.  

This test track has a timer to evaluate how well the car rolls over a six foot section with the same profile as a real track.
The track can be adjusted to 1, 2, or 3 degree slope, changing the influence of gravity, see how well their cars roll.

Trimming the injection molding tabs from the tires and polishing the axles or providing some camber to the alignment are
advantages that contribute to faster track times, or builders can tune for the turtle award. (slowest)  
See the Mark Rober video from April 6, 2014 titled "EASY Pinewood Derby Car WINS using Science!!!" 
https://www.youtube.com/watch?v=-RjJtO51ykY

7 Key Steps:
1.  Max weight ~1" in front of rear axle
2.  Reasonably aerodynamic
3.  Ride on 3 wheels
4.  Lightweight wheels
5.  Bent polished axles
6.  Railride/alignment
7.  Lots o' graphite
   
This track is to help builders address steps 3 through 7 with a track segment similar to the real race day.
Many clubs don't have their own track since the entire system can cost as much as $2000.  www.besttrack.com
For the low low price of $how_much_I_paid, you can provide a test segment easily deployed for the months leading up to actual race day.
The timer is to help builders reference what impact their changes make on car performance.  Adding LED to any project obviously makes it better.


>Use an Atmega chip to count seconds between the starting pin and end pin. Uno or Mini,  Maybe Tiny85 for production.
>9.999 is a failed attempt on the test track as well as race day.
>IR detectors and emitters at the start and end will trigger the timer.  
>Display the time after complete.
>The timer will reset via the chip reset pin and an external button.
>18650 batteries iside an external box for the controller.
>CAT5 cable between the controller and the board because this can all be done with 8 wires.


## Cost of goods in 2024:
-   1/4"x2"  6' 6061 aluminum bar  $22
-   1/8"x4"  6' 6061 aluminum plate  $22
-   1x6 wood base 6' (finish pine or another wood that is reliably straight and flat)
-   Arduino Uno r3 or Mini $15 to $3.  We want one with a 5v regulator so we can power it with batteries
-   2x 18650 batteries  $4 or $0 from a friend or you scrap them from other stuff like an e-scooter
-   2x 18650 battery holder  $3  can use two singles or a double holder.  Connect the cells in series for 7v to 8v
-   3d printer - ask a friend or go to the library.  The nicer the printer, the better it will look.
-   14 segment 4 character i2c backpack display with decimals.  These come in various colors, $12 for two.
-   2x 940nm Infrared LED emitters  
-   2x 940nm Infrared detectors  $7 for a pack of 30, 15 emitters, 15 detectors.
-   2x 100 ohm resistors  (cheap, ask a friend)
-   Rocker switch for power $1
-   Momentary push button for reset $1
-   Misc hookup wire or CAT5 stranded wire.  $0


## Other things you might need or want to make this.
-   Soldering iron and solder
-   Small hand tools
-   Shrink wrap
-   18650 battery charger
-   Hobby battery charger if you go with LiPo packs
-   Arduino IDE programming environment
-   USB Mini cable for Arduino Mini
-   USB huge cable for Uno
-   Dupont crimper and connectors (or solder directly to the board)
-   Pin headers for the arduino (or solder directly to the board)
-   Woodworking tools and wood finishes
-   Some metalworking tools to fabricate the track surface
-   Self tapping screws OR brass threaded inserts that press into plastic with heat

September 2024 - first code development on UNO
October 2024 - working code with i2c 14seg display. Deploy on a Nano because its tiny and has a 5v regulator.  
Serial output can be enabled for debugging.
