static T_1 F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_3 ) ;
}
static int T_2 F_3 ( void )
{
F_4 ( 0x00 , V_4 ) ;
F_4 ( 0x00 , V_5 ) ;
F_5 ( 0x00000000 , V_6 ) ;
F_6 ( V_7 | V_8 , V_9 ) ;
V_10 . V_11 = F_7 ( V_12 ,
V_10 . V_13 ) ;
return F_8 ( & V_10 ) ;
}
static unsigned long long F_9 ( unsigned long V_14 )
{
return ( unsigned long long ) ( ( unsigned long long ) V_14 *
V_15 ) >> V_16 ;
}
unsigned long long F_10 ( void )
{
unsigned long V_14 = F_2 ( V_3 ) ;
return F_9 ( V_14 ) ;
}
