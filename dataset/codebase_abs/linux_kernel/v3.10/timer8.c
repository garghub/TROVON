static T_1 F_1 ( int V_1 , void * V_2 )
{
F_2 () ;
F_3 ( V_3 , V_4 + V_5 ) ;
return V_6 ;
}
void T_2 F_4 ( void )
{
unsigned int div ;
unsigned int V_7 ;
F_5 ( V_7 , div , V_8 , 0x10000 ) ;
div ++ ;
F_6 ( V_9 , & V_10 ) ;
#if F_7 ( V_11 )
F_3 ( 0 , MSTPCRL)
#endif
F_8 ( V_7 , V_4 + V_12 ) ;
F_8 ( 0x0000 , V_4 + V_5 ) ;
F_8 ( ( V_13 | V_14 | V_15 ) << 8 | div ,
V_4 + V_16 ) ;
}
