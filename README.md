Ticking
=======

Sometimes you need to call a function every X times some other condition has occurred; using a Ticking instance, you can define the callback function to be called, the number of cycles at which the function is called. Then, every time the condition occurs, you just have to call the *tick* method.


Example
=======

	#include <Ticking.h>;

	void setup() {
	  Serial.begin(9600);
	}

	void cb() {
	  Serial.println("Callback called!");
	}

	Ticking ticker(cb, 10);

	void loop() {
	  ticker.tick();
	  delay(500);
	}

Every 10 times the *ticker.tick()* method is called, the *cb()* function is executed.


Author
======

Davide Alberani <da@erlug.linux.it> (C) 2013
http://www.mimante.net/

License
=======

The code is covered by the MIT.
