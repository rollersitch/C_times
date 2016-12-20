#include <stdio.h>
void motoparabolico(double v[], double g, double dt, double tf) {
     double x=0, y=0, t;

     for(t=0; t < tf; t+= dt) {
	printf("%lf %lf\n", x, y);
        x += v[0]*dt;
        y += v[1]*dt;
        v[1] -= g*dt;
     }
}


main() {
   double v[] = {30,60};
   double tf=10, dt=0.05, g=9.8;
   motoparabolico(v, g, dt, tf);

}
