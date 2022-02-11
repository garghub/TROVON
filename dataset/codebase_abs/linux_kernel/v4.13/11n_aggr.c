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
V_9 = F_2 ( V_2 , sizeof( * V_9 ) ) ;
V_5 = 2 * V_10 ;
memcpy ( & V_9 -> V_11 , V_3 -> V_12 , V_5 ) ;
V_7 . V_13 = ( (struct V_14 * ) V_3 -> V_12 ) -> V_15 ;
V_5 += sizeof( V_16 ) ;
memcpy ( & V_9 -> V_17 , & V_7 , sizeof( struct V_6 ) ) ;
F_3 ( V_3 , V_5 ) ;
V_9 -> V_11 . V_15 = F_4 ( V_3 -> V_18 + V_19 ) ;
F_5 ( V_2 , V_3 -> V_12 , V_3 -> V_18 ) ;
* V_4 = ( 4 - ( ( unsigned long ) V_2 -> V_20 & 0x3 ) ) % 4 ;
return V_2 -> V_18 + * V_4 ;
}
static void
F_6 ( struct V_21 * V_22 ,
struct V_1 * V_23 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 = F_7 ( V_23 ) ;
F_8 ( V_23 , sizeof( * V_25 ) ) ;
V_25 = (struct V_24 * ) V_23 -> V_12 ;
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
V_25 -> V_28 = ( V_29 ) V_23 -> V_28 ;
V_25 -> V_30 =
F_9 ( V_22 , V_23 ) ;
V_25 -> V_31 = V_22 -> V_31 ;
V_25 -> V_32 = V_22 -> V_32 ;
V_25 -> V_33 = F_10 ( sizeof( struct V_24 ) ) ;
V_25 -> V_34 = F_10 ( V_35 ) ;
V_25 -> V_36 = F_10 ( V_23 -> V_18 -
sizeof( * V_25 ) ) ;
if ( V_27 -> V_37 & V_38 )
V_25 -> V_37 |= V_39 ;
if ( V_25 -> V_40 == 0 )
V_25 -> V_40 = F_11 ( V_22 -> V_41 ) ;
if ( F_12 ( V_22 ) == V_42 &&
V_22 -> V_43 -> V_44 ) {
if ( true == F_13 ( V_22 ) ) {
V_22 -> V_43 -> V_45 = true ;
V_25 -> V_37 =
V_46 ;
}
}
}
int
F_14 ( struct V_21 * V_22 ,
struct V_47 * V_48 ,
int V_49 , unsigned long V_50 )
__releases( &priv->wmm.ra_list_spinlock
