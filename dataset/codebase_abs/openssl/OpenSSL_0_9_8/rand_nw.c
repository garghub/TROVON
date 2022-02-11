int F_1 ( void )
{
unsigned long V_1 ;
unsigned long V_2 ;
int V_3 ;
V_1 = F_2 () ;
F_3 ( & V_1 , sizeof( V_1 ) , 1 ) ;
V_1 = V_4 ;
F_3 ( & V_1 , sizeof( V_1 ) , 1 ) ;
for( V_3 = 2 ; V_3 < V_5 ; V_3 ++ )
{
#ifdef F_4
F_5
{
T_1
T_2 V_2 , V_6
}
#else
asm volatile("rdtsc":"=A" (tsc));
#endif
F_3 ( & V_2 , sizeof( V_2 ) , 1 ) ;
V_1 = F_6 () ;
F_3 ( & V_1 , sizeof( V_1 ) , 0 ) ;
# if F_7 ( V_7 )
F_8 () ;
# else
F_9 () ;
# endif
}
return 1 ;
}
