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
#if F_7 ( V_4 ) || F_7 ( V_5 )
T_1 V_3 = F_1 () ;
#endif
#ifdef V_4
void T_3 * V_6 ;
int V_7 = 0 ;
T_1 V_8 ;
switch ( V_3 & ( F_8 ( 14 ) | F_8 ( 13 ) ) ) {
case 0 :
V_7 = 15 ;
break;
case F_8 ( 13 ) :
V_7 = 20 ;
break;
case F_8 ( 14 ) :
V_7 = 26 ;
break;
case F_8 ( 13 ) | F_8 ( 14 ) :
V_7 = 30 ;
break;
}
V_8 = V_7 * ( 1000000 / 2 ) ;
V_6 = F_9 ( 0xe6080000 , V_9 ) ;
if ( ( F_4 ( V_6 + V_10 ) & 1 ) == 0 ||
F_4 ( V_6 + V_11 ) != V_8 ) {
F_10 ( V_8 , V_6 + V_11 ) ;
asm volatile("mcr p15, 0, %0, c14, c0, 0" : : "r" (freq));
F_10 ( 1 , V_6 + V_10 ) ;
}
F_5 ( V_6 ) ;
#endif
#ifdef V_5
F_11 ( V_3 ) ;
#endif
F_12 () ;
}
