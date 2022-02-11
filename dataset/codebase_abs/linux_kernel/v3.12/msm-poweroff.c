static void F_1 ( enum V_1 V_1 , const char * V_2 )
{
F_2 ( 0 , V_3 ) ;
F_3 ( 10000 ) ;
}
static void F_4 ( void )
{
F_1 ( V_4 , NULL ) ;
}
static int F_5 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = & V_6 -> V_8 ;
struct V_9 * V_10 ;
V_10 = F_6 ( V_6 , V_11 , 0 ) ;
V_3 = F_7 ( V_8 , V_10 ) ;
if ( F_8 ( V_3 ) )
return F_9 ( V_3 ) ;
V_12 = F_4 ;
V_13 = F_1 ;
return 0 ;
}
static int T_1 F_10 ( void )
{
return F_11 ( & V_14 ) ;
}
