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
V_9 = ( void * ) F_2 ( V_2 , sizeof( * V_9 ) ) ;
V_5 = 2 * V_10 ;
memcpy ( & V_9 -> V_11 , V_3 -> V_12 , V_5 ) ;
V_7 . V_13 =
F_3 ( * ( V_14 * ) ( ( V_15 * ) V_3 -> V_12 + V_5 ) ) ;
V_5 += sizeof( V_16 ) ;
memcpy ( & V_9 -> V_17 , & V_7 , sizeof( struct V_6 ) ) ;
F_4 ( V_3 , V_5 ) ;
V_9 -> V_11 . V_18 = F_5 ( V_3 -> V_19 + V_20 ) ;
memcpy ( F_2 ( V_2 , V_3 -> V_19 ) , V_3 -> V_12 , V_3 -> V_19 ) ;
* V_4 = ( 4 - ( ( unsigned long ) V_2 -> V_21 & 0x3 ) ) % 4 ;
return V_2 -> V_19 + * V_4 ;
}
static void
F_6 ( struct V_22 * V_23 ,
struct V_1 * V_24 )
{
struct V_25 * V_26 ;
F_7 ( V_24 , sizeof( * V_26 ) ) ;
V_26 = (struct V_25 * ) V_24 -> V_12 ;
memset ( V_26 , 0 , sizeof( struct V_25 ) ) ;
V_26 -> V_27 = ( V_15 ) V_24 -> V_27 ;
V_26 -> V_28 =
F_8 ( V_23 , V_24 ) ;
V_26 -> V_29 = V_23 -> V_29 ;
V_26 -> V_30 = V_23 -> V_30 ;
V_26 -> V_31 = F_9 ( sizeof( struct V_25 ) ) ;
V_26 -> V_32 = F_9 ( V_33 ) ;
V_26 -> V_34 = F_9 ( V_24 -> V_19 -
sizeof( * V_26 ) ) ;
if ( V_26 -> V_35 == 0 )
V_26 -> V_35 = F_10 ( V_23 -> V_36 ) ;
if ( F_11 ( V_23 ) == V_37 &&
V_23 -> V_38 -> V_39 ) {
if ( true == F_12 ( V_23 ) ) {
V_23 -> V_38 -> V_40 = true ;
V_26 -> V_41 =
V_42 ;
}
}
}
int
F_13 ( struct V_22 * V_23 ,
struct V_43 * V_44 ,
int V_45 , unsigned long V_46 )
__releases( &priv->wmm.ra_list_spinlock
