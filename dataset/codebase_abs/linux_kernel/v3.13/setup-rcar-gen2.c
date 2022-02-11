T_1 T_2 F_1 ( void )
{
void T_3 * V_1 = F_2 ( V_2 , 4 ) ;
T_1 V_3 ;
F_3 ( ! V_1 ) ;
V_3 = F_4 ( V_1 ) ;
F_5 ( V_1 ) ;
return V_3 ;
}
void T_2 F_6 ( void )
{
#ifdef F_7
T_1 V_3 = F_1 () ;
void T_3 * V_4 ;
int V_5 = 0 ;
T_1 V_6 ;
switch ( V_3 & ( F_8 ( 14 ) | F_8 ( 13 ) ) ) {
case 0 :
V_5 = 15 ;
break;
case F_8 ( 13 ) :
V_5 = 20 ;
break;
case F_8 ( 14 ) :
V_5 = 26 ;
break;
case F_8 ( 13 ) | F_8 ( 14 ) :
V_5 = 30 ;
break;
}
V_6 = V_5 * ( 1000000 / 2 ) ;
V_4 = F_9 ( 0xe6080000 , V_7 ) ;
F_10 ( V_6 , V_4 + V_8 ) ;
asm volatile("mcr p15, 0, %0, c14, c0, 0" : : "r" (freq));
F_10 ( 1 , V_4 + V_9 ) ;
F_5 ( V_4 ) ;
#endif
F_11 () ;
}
