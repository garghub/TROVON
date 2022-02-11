static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
F_2 ( V_4 -> V_5 , V_6 , sizeof( V_4 -> V_5 ) ) ;
F_2 ( V_4 -> V_7 , V_8 ,
sizeof( V_4 -> V_7 ) ) ;
F_2 ( V_4 -> V_9 , F_3 ( V_2 -> V_10 . V_11 ) ,
sizeof( V_4 -> V_9 ) ) ;
}
static int F_4 ( struct V_1 * V_2 , int V_12 )
{
return ( V_12 == V_13 ) ? V_14 : - V_15 ;
}
static void F_5 ( struct V_1 * V_2 ,
struct V_16 * V_17 , T_1 * V_18 )
{
struct V_19 * V_20 = F_6 ( V_2 ) ;
struct V_21 V_22 ;
int V_23 ;
memset ( & V_22 , 0 , sizeof( V_22 ) ) ;
F_7 ( & V_20 -> V_24 ) ;
V_20 -> V_25 -> V_26 ( V_2 , & V_22 . V_27 ) ;
for ( V_23 = 0 ; V_23 < V_14 ; V_23 ++ ) {
char * V_28 = ( char * ) & V_22 + V_29 [ V_23 ] . V_30 ;
V_18 [ V_23 ] = ( V_29 [ V_23 ] . V_31 ==
sizeof( T_1 ) ) ? * ( T_1 * ) V_28 : * ( V_32 * ) V_28 ;
}
F_8 ( & V_20 -> V_24 ) ;
}
static void F_9 ( struct V_1 * V_2 , V_32 V_33 , T_2 * V_18 )
{
int V_23 ;
if ( V_33 != V_13 )
return;
for ( V_23 = 0 ; V_23 < V_14 ; V_23 ++ )
memcpy ( V_18 + V_23 * V_34 ,
V_29 [ V_23 ] . V_35 ,
V_34 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
V_2 -> V_36 = & V_37 ;
}
