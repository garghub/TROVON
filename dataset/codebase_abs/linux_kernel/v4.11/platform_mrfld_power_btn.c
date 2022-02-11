static int F_1 ( struct V_1 * V_2 ,
unsigned long V_3 , void * V_4 )
{
if ( V_3 == V_5 ) {
F_2 ( & V_6 ) ;
return 0 ;
}
return F_3 ( & V_6 ) ;
}
static int T_1 F_4 ( void )
{
if ( F_5 () != V_7 )
return - V_8 ;
F_6 ( & V_9 ) ;
return 0 ;
}
static void T_1 * F_7 ( void * V_10 )
{
struct V_11 * V_12 = V_13 ;
struct V_14 * V_15 = V_10 ;
V_12 -> V_16 = V_12 -> V_17 = V_15 -> V_18 ;
return NULL ;
}
