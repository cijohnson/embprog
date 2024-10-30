#define SYSCTL_RCGCGPIO_R       (*((volatile unsigned long *)0x400FE608))
#define GPIO_PORTF_DIR_R        (*((volatile unsigned long *)0x40025400))
#define GPIO_PORTF_DEN_R        (*((volatile unsigned long *)0x4002551C))
#define GPIO_PORTF_DATA_R       (*((volatile unsigned long *)0x400253FC))


int main(void) {
    SYSCTL_RCGCGPIO_R = 0x20U;  // enable clock for GPIOF
    GPIO_PORTF_DIR_R = 0x0EU; // set pins 1,2, and 3 as outputs
    GPIO_PORTF_DEN_R = 0x0EU; // enable digital function on pins 1,2, and 3

    while (1) { // endless loop
        GPIO_PORTF_DATA_R = 0x02U; // turn the red-LED on

        int volatile counter = 0;
        while (counter < 1000000) {  // delay loop
            ++counter;
        }

        GPIO_PORTF_DATA_R = 0x00U; // turn the red-LED off
        counter = 0;
        while (counter < 1000000) {  // delay loop
            ++counter;
        }

    }
    //return 0; // unreachable code
}