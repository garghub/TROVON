void T_1 F_1 ( void )
{
F_2 ( L_1 , - 1 , V_1 ,
F_3 ( V_1 ) ) ;
F_4 ( 0 ) ;
F_4 ( 1 ) ;
F_4 ( 2 ) ;
F_4 ( 3 ) ;
F_4 ( 4 ) ;
F_4 ( 5 ) ;
}
static inline void F_5 ( int V_2 )
{
F_6 ( & V_3 , L_2 , V_2 , & V_4 [ V_2 ] ,
sizeof( struct V_5 ) ) ;
}
void T_1 F_7 ( void )
{
F_5 ( V_6 ) ;
F_5 ( V_7 ) ;
F_5 ( V_8 ) ;
F_5 ( V_9 ) ;
F_5 ( V_10 ) ;
F_5 ( V_11 ) ;
F_5 ( V_12 ) ;
F_5 ( V_13 ) ;
F_5 ( V_14 ) ;
F_5 ( V_15 ) ;
F_8 ( 00 ) ;
}
void T_1 F_9 ( void )
{
F_7 () ;
F_10 ( 0 ) ;
F_11 () ;
}
T_2 T_1 F_12 ( void )
{
void T_3 * V_16 = F_13 ( V_17 , 4 ) ;
T_2 V_18 ;
F_14 ( ! V_16 ) ;
V_18 = F_15 ( V_16 ) ;
F_16 ( V_16 ) ;
return V_18 ;
}
void T_1 F_17 ( void )
{
#ifdef F_18
T_2 V_18 = F_12 () ;
void T_3 * V_19 ;
int V_20 = 0 ;
T_2 V_21 ;
switch ( V_18 & ( F_19 ( 14 ) | F_19 ( 13 ) ) ) {
case 0 :
V_20 = 15 ;
break;
case F_19 ( 13 ) :
V_20 = 20 ;
break;
case F_19 ( 14 ) :
V_20 = 26 ;
break;
case F_19 ( 13 ) | F_19 ( 14 ) :
V_20 = 30 ;
break;
}
V_21 = V_20 * ( 1000000 / 2 ) ;
V_19 = F_20 ( 0xe6080000 , V_22 ) ;
F_21 ( V_21 , V_19 + V_23 ) ;
asm volatile("mcr p15, 0, %0, c14, c0, 0" : : "r" (freq));
F_21 ( 1 , V_19 + V_24 ) ;
F_16 ( V_19 ) ;
#endif
F_22 () ;
}
void T_1 F_23 ( void )
{
#ifndef F_18
F_24 ( 1300 , 2 , 4 ) ;
#endif
}
