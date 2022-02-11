static unsigned long F_1 ( void )
{
return ( F_2 ( V_1 + V_2 + V_3 ) * 1000000 / ( V_4 / 128 ) ) ;
}
static T_1 F_3 ( int V_5 , void * V_6 )
{
F_2 ( V_1 + V_2 + V_7 ) ;
F_4 () ;
return V_8 ;
}
void T_2 F_5 ( void )
{
unsigned int V_9 ;
F_6 ( V_1 + V_10 , 0 ) ;
V_9 = F_2 ( V_1 + V_11 ) ;
V_9 = ( V_9 & ~ V_12 ) | V_13 ;
F_6 ( V_1 + V_11 , V_9 ) ;
F_6 ( V_1 + V_2 + V_14 , V_15 ) ;
F_6 ( V_1 + V_2 + V_16 , ( V_17 | V_18 ) ) ;
F_6 ( V_1 + V_2 + V_19 , 0xffffffff ) ;
F_6 ( V_1 + V_2 + V_20 , ( V_4 / 128 ) / V_21 - 1 ) ;
F_6 ( V_1 + V_2 + V_22 , ( 1 << 4 ) ) ;
F_7 ( V_23 , & V_24 ) ;
F_6 ( V_1 + V_2 + V_14 , ( V_25 | V_26 ) ) ;
}
