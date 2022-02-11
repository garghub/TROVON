static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 , V_5 ;
V_4 = ( int ) * ( V_6 * ) V_3 ;
F_2 ( V_2 , L_1 , V_7 [ V_4 ] . V_8 ,
F_3 ( V_7 [ V_4 ] . V_9 ) , & V_5 ) ;
F_2 ( V_2 , L_2 , 127 - V_5 , L_3 ) ;
return 0 ;
}
static void * F_4 ( struct V_1 * V_2 , V_6 * V_10 )
{
return ( * V_10 >= F_5 ( V_7 ) ) ? NULL : ( void * ) V_10 ;
}
static void F_6 ( struct V_1 * V_2 , void * V_3 )
{
}
static void * F_7 ( struct V_1 * V_2 , void * V_3 , V_6 * V_10 )
{
++ * V_10 ;
return ( * V_10 >= F_5 ( V_7 ) ) ? NULL : ( void * ) V_10 ;
}
static int F_8 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
return F_9 ( V_12 , & V_13 ) ;
}
void F_10 ( void )
{
struct V_14 * V_15 ;
V_15 = F_11 ( L_4 , 0 ,
V_16 , & V_17 ) ;
if ( ! V_15 )
F_12 ( L_5 ) ;
}
void F_13 ( void )
{
F_14 ( L_4 , V_16 ) ;
}
