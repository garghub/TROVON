static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_4 . V_5 = V_6 ;
V_4 . V_7 = F_2 ( V_6 ) ;
V_4 . V_8 = V_9 ;
V_4 . V_10 = F_2 ( V_9 ) ;
F_3 ( & V_4 , V_11 ) ;
F_4 ( V_4 . V_12 ,
V_4 . V_13 , V_11 ) ;
V_4 . V_14 = false ;
V_3 = F_5 ( V_2 , & V_4 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return F_7 ( V_2 ) ;
}
static int T_1 F_8 ( void )
{
return F_9 ( & V_15 ) ;
}
static void T_2 F_10 ( void )
{
F_11 ( & V_15 ) ;
}
