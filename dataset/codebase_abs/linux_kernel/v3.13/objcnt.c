static int F_1 ( struct V_1 * V_2 , void * V_3 )
{
int V_4 ;
V_4 = ( int ) * ( V_5 * ) V_3 ;
F_2 ( V_2 , 127 ) ;
F_3 ( V_2 , L_1 , V_6 [ V_4 ] . V_7 ,
F_4 ( V_6 [ V_4 ] . V_8 ) ) ;
F_5 ( V_2 , '\n' ) ;
return 0 ;
}
static void * F_6 ( struct V_1 * V_2 , V_5 * V_9 )
{
return ( * V_9 >= F_7 ( V_6 ) ) ? NULL : ( void * ) V_9 ;
}
static void F_8 ( struct V_1 * V_2 , void * V_3 )
{
}
static void * F_9 ( struct V_1 * V_2 , void * V_3 , V_5 * V_9 )
{
++ * V_9 ;
return ( * V_9 >= F_7 ( V_6 ) ) ? NULL : ( void * ) V_9 ;
}
static int F_10 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
return F_11 ( V_11 , & V_12 ) ;
}
void F_12 ( struct V_13 * V_13 )
{
struct V_14 * V_15 ;
V_15 = F_13 ( L_2 , 0 ,
V_13 -> V_16 . V_17 , & V_18 ) ;
if ( ! V_15 )
F_14 ( L_3 ) ;
}
void F_15 ( struct V_13 * V_13 )
{
F_16 ( L_2 , V_13 -> V_16 . V_17 ) ;
}
