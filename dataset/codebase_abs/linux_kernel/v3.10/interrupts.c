static void * F_1 ( struct V_1 * V_2 , T_1 * V_3 )
{
return ( * V_3 <= V_4 ) ? V_3 : NULL ;
}
static void * F_2 ( struct V_1 * V_2 , void * V_5 , T_1 * V_3 )
{
( * V_3 ) ++ ;
if ( * V_3 > V_4 )
return NULL ;
return V_3 ;
}
static void F_3 ( struct V_1 * V_2 , void * V_5 )
{
}
static int F_4 ( struct V_6 * V_6 , struct V_7 * V_8 )
{
return F_5 ( V_8 , & V_9 ) ;
}
static int T_2 F_6 ( void )
{
F_7 ( L_1 , 0 , NULL , & V_10 ) ;
return 0 ;
}
