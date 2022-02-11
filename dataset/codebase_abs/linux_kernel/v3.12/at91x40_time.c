static T_1 F_1 ( void )
{
return ( F_2 ( V_1 + V_2 ) * 1000000 /
( V_3 / 128 ) ) * 1000 ;
}
static T_2 F_3 ( int V_4 , void * V_5 )
{
F_2 ( V_1 + V_6 ) ;
F_4 () ;
return V_7 ;
}
void T_3 F_5 ( void )
{
unsigned int V_8 ;
V_9 = F_1 ;
F_6 ( V_10 , 0 ) ;
V_8 = F_2 ( V_11 ) ;
V_8 = ( V_8 & ~ V_12 ) | V_13 ;
F_6 ( V_11 , V_8 ) ;
F_6 ( V_1 + V_14 , V_15 ) ;
F_6 ( V_1 + V_16 , ( V_17 | V_18 ) ) ;
F_6 ( V_1 + V_19 , 0xffffffff ) ;
F_6 ( V_1 + V_20 , ( V_3 / 128 ) / V_21 - 1 ) ;
F_6 ( V_1 + V_22 , ( 1 << 4 ) ) ;
F_7 ( V_23 , & V_24 ) ;
F_6 ( V_1 + V_14 , ( V_25 | V_26 ) ) ;
}
