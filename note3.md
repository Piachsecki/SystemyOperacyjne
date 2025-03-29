Thread deadlock
Date: 2025-03-29



Tags:
[#university]

Jest to sytuacja, kiedy pracujemy z watkami. Polega to na tym, ze mamy kilka watkow i kilka resource'ow, ktore te watki maja wspoldzielic. Jak jeden z nich z niego korzysta, to blokuje access do tego resource'a kazdemu innemu watkowi.

Ale np. do skonczenia dzialania tego 1 watka, bedziemy potrzebowac skorzystac z resource'a, ktory jest juz zablokowany przez 2gi watek.

W ten sposob znajdujemy sie w takiej petli, gdzie kazdy z watkow nie moze sie skonczyc, poniewaz potrzebuje dostep do jakiegos zasoby, ktory jest zablokowany przez inny watek.


Podsumowanie: System nie działa. Wszystkie procesy blokują się nawzajem i nikt nie może działać.

