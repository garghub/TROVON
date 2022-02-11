static int
F_1 ( struct V_1 * V_2 ,
struct V_1 * V_3 , int * V_4 )
{
int V_5 ;
struct V_6 V_7 = {
0xaa ,
0xaa ,
0x03 ,
{ 0x00 , 0x00 , 0x00 } ,
0x0000
} ;
struct V_8 * V_9 ;
F_2 ( V_2 , sizeof( * V_9 ) ) ;
V_9 = (struct V_8 * ) V_2 -> V_10 ;
V_5 = 2 * V_11 ;
memcpy ( & V_9 -> V_12 , V_3 -> V_10 , V_5 ) ;
V_7 . V_13 = * ( V_14 * ) ( ( V_15 * ) V_3 -> V_10 + V_5 ) ;
V_5 += sizeof( V_14 ) ;
memcpy ( & V_9 -> V_16 , & V_7 , sizeof( struct V_6 ) ) ;
F_3 ( V_3 , V_5 ) ;
V_9 -> V_12 . V_17 = F_4 ( V_3 -> V_18 + V_19 ) ;
F_2 ( V_2 , V_3 -> V_18 ) ;
memcpy ( V_2 -> V_10 + sizeof( * V_9 ) , V_3 -> V_10 ,
V_3 -> V_18 ) ;
* V_4 = ( ( ( V_3 -> V_18 + V_19 ) & 3 ) ) ? ( 4 - ( ( ( V_3 -> V_18 +
V_19 ) ) & 3 ) ) : 0 ;
F_2 ( V_2 , * V_4 ) ;
return V_2 -> V_18 + * V_4 ;
}
static void
F_5 ( struct V_20 * V_21 ,
struct V_1 * V_22 )
{
struct V_23 * V_24 ;
F_6 ( V_22 , sizeof( * V_24 ) ) ;
V_24 = (struct V_23 * ) V_22 -> V_10 ;
memset ( V_24 , 0 , sizeof( struct V_23 ) ) ;
V_24 -> V_25 = ( V_15 ) V_22 -> V_25 ;
V_24 -> V_26 =
F_7 ( V_21 , V_22 ) ;
V_24 -> V_27 = V_21 -> V_27 ;
V_24 -> V_28 = V_21 -> V_28 ;
V_24 -> V_29 = F_8 ( sizeof( struct V_23 ) ) ;
V_24 -> V_30 = F_8 ( V_31 ) ;
V_24 -> V_32 = F_8 ( V_22 -> V_18 -
sizeof( * V_24 ) ) ;
if ( V_24 -> V_33 == 0 )
V_24 -> V_33 = F_9 ( V_21 -> V_34 ) ;
if ( F_10 ( V_21 ) == V_35 &&
V_21 -> V_36 -> V_37 ) {
if ( true == F_11 ( V_21 ) ) {
V_21 -> V_36 -> V_38 = true ;
V_24 -> V_39 =
V_40 ;
}
}
}
int
F_12 ( struct V_20 * V_21 ,
struct V_41 * V_42 , int V_43 ,
int V_44 , unsigned long V_45 )
__releases( &priv->wmm.ra_list_spinlock
