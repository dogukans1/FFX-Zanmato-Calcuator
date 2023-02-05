# FFX-Zanmato-Calcuator
This is a Zanmato possibility calcuator for Final Fantasy X, did it as a hobby lol.

Credits to https://gamefaqs.gamespot.com/ps2/197344-final-fantasy-x/faqs/24392 for making the calcuator, my version is based on Internal versions.

To compile simply use VS2022 I guess, am noob.

So, how it's done? In short, assuming you've picked the Option 3 when hired him
1. Find your compatibility with him, that is not shown in game and you need to use something like FFXED to find it. 
2. Then determine how much Gil you're gonna pay him, 0 instantly dismisses it
3. Divide your compatibility by 4 or 10 (this calcuator uses 4, 1.1 will use 10) and add it to a "motivation" value that is too long to be explained here, read GilMotivation.h to see the table.
4. If he's at his overdrive add 20 to current total
5. If enemy's Zanmato level is 1, 2 or three, multiple by 0.8, else 0.4
6. Total Number + a random number between 0-64 = x. If X is 80 then Yojimbo will use Zanmato. This calcuator calcuates the possibility of Zanmato happening.
