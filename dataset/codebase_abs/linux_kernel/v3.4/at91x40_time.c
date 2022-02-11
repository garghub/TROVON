static unsigned long F_1 ( void )
{
return ( F_2 ( V_1 + V_2 ) * 1000000 / ( V_3 / 128 ) ) ;
}
static T_1 F_3 ( int V_4 , void * V_5 )
{
F_2 ( V_1 + V_6 ) ;
F_4 () ;
return V_7 ;
}
void T_2 F_5 ( void )
{
unsigned int V_8 ;
F_6 ( V_9 , 0 ) ;
V_8 = F_2 ( V_10 ) ;
V_8 = ( V_8 & ~ V_11 ) | V_12 ;
F_6 ( V_10 , V_8 ) ;
F_6 ( V_1 + V_13 , V_14 ) ;
F_6 ( V_1 + V_15 , ( V_16 | V_17 ) ) ;
F_6 ( V_1 + V_18 , 0xffffffff ) ;
F_6 ( V_1 + V_19 , ( V_3 / 128 ) / V_20 - 1 ) ;
F_6 ( V_1 + V_21 , ( 1 << 4 ) ) ;
F_7 ( V_22 , & V_23 ) ;
F_6 ( V_1 + V_13 , ( V_24 | V_25 ) ) ;
}
