int F_1 ( void T_1 * V_1 , int V_2 , unsigned long V_3 )
{
F_2 ( V_1 , V_2 , V_4 , V_5 ) ;
F_3 ( V_1 , V_2 , V_6 , V_3 & 0xfffe ) ;
F_4 ( V_1 , V_2 , V_7 , 0x01 ) ;
F_4 ( V_1 , V_2 , V_8 , 0x1f ) ;
F_4 ( V_1 , V_2 , V_9 , 0x00 ) ;
return 0 ;
}
int F_5 ( void T_1 * V_1 , int V_2 , unsigned long V_3 )
{
F_2 ( V_1 , V_2 , V_4 , V_5 ) ;
F_3 ( V_1 , V_2 , V_6 , V_3 & 0xfffe ) ;
return 0 ;
}
void F_6 ( void T_1 * V_1 , int V_2 , int V_10 )
{
F_4 ( V_1 , V_2 , V_9 , V_10 ? 0x02 : 0x00 ) ;
}
void F_7 ( void T_1 * V_1 , int V_2 , int V_10 )
{
F_4 ( V_1 , V_2 , V_11 , V_10 ? 1 : 0 ) ;
}
