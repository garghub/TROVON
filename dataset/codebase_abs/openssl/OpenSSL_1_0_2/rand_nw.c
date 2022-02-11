int F_1 ( void )
{
unsigned long V_1 ;
unsigned long V_2 ;
int V_3 ;
V_1 = F_2 () ;
F_3 ( & V_1 , sizeof( V_1 ) , 1 ) ;
V_1 = ( unsigned long ) V_4 ;
F_3 ( & V_1 , sizeof( V_1 ) , 1 ) ;
for ( V_3 = 2 ; V_3 < V_5 ; V_3 ++ ) {
# ifdef F_4
F_5 {
T_1 T_2 V_2 , V_6 }
# elif F_6 ( V_7 ) && V_7 >= 2 && ! F_6 ( V_8 ) && ! F_6 ( V_9 )
asm volatile ("rdtsc":"=a" (tsc)::"edx");
# endif
F_3 ( & V_2 , sizeof( V_2 ) , 1 ) ;
V_1 = F_7 () ;
F_3 ( & V_1 , sizeof( V_1 ) , 0 ) ;
# if F_6 ( V_10 )
F_8 () ;
# else
F_9 () ;
# endif
}
return 1 ;
}
