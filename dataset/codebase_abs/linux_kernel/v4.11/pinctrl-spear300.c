static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_4 . V_5 = V_6 ;
V_4 . V_7 = F_2 ( V_6 ) ;
V_4 . V_8 = V_9 ;
V_4 . V_10 = F_2 ( V_9 ) ;
V_4 . V_11 = NULL ;
V_4 . V_12 = 0 ;
V_4 . V_13 = true ;
V_4 . V_14 = V_15 ;
V_4 . V_16 = F_2 ( V_15 ) ;
F_3 ( & V_4 , V_17 ) ;
V_3 = F_4 ( V_2 , & V_4 ) ;
if ( V_3 )
return V_3 ;
return 0 ;
}
static int T_1 F_5 ( void )
{
return F_6 ( & V_18 ) ;
}
