static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( V_4 )
F_2 ( V_5 , 0 ) ;
else
F_2 ( 0 , V_5 ) ;
}
static enum V_3 F_3 ( struct V_1 * V_2 )
{
return ( F_4 () & V_5 ) ? V_6 : V_7 ;
}
static int T_1 F_5 ( struct V_8 * V_9 )
{
return F_6 ( & V_9 -> V_10 , & V_11 ) ;
}
static int T_2 F_7 ( struct V_8 * V_9 )
{
F_8 ( & V_11 ) ;
return 0 ;
}
