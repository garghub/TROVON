static T_1 F_1 ( int V_1 , void * V_2 )
{
unsigned int V_3 = F_2 ( ( void V_4 * ) V_2 ) ;
F_3 ( F_4 ( V_3 ) ) ;
return V_5 ;
}
static int F_5 ( struct V_6 * V_7 , unsigned int V_8 )
{
return 0 ;
}
void T_2 F_6 ( void )
{
void V_4 * V_9 = F_7 ( 0xf0001000 ) ;
void V_4 * V_10 = F_7 ( 0xf0000100 ) ;
void V_4 * V_11 = F_8 ( 0xffd20100 , V_12 ) ;
F_9 ( 0 , 29 , V_9 , V_10 ) ;
V_13 . V_14 = F_5 ;
F_10 ( & V_15 ) ;
V_16 . V_17 = L_1 ;
V_16 . V_18 = F_1 ;
V_16 . V_2 = V_11 ;
F_11 ( F_12 ( 50 ) , & V_16 ) ;
}
