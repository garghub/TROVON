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
V_7 . V_13 = ( (struct V_14 * ) V_3 -> V_12 ) -> V_15 ;
V_5 += sizeof( V_16 ) ;
memcpy ( & V_9 -> V_17 , & V_7 , sizeof( struct V_6 ) ) ;
F_3 ( V_3 , V_5 ) ;
V_9 -> V_11 . V_15 = F_4 ( V_3 -> V_18 + V_19 ) ;
memcpy ( F_2 ( V_2 , V_3 -> V_18 ) , V_3 -> V_12 , V_3 -> V_18 ) ;
* V_4 = ( 4 - ( ( unsigned long ) V_2 -> V_20 & 0x3 ) ) % 4 ;
return V_2 -> V_18 + * V_4 ;
}
static void
F_5 ( struct V_21 * V_22 ,
struct V_1 * V_23 )
{
struct V_24 * V_25 ;
struct V_26 * V_27 = F_6 ( V_23 ) ;
unsigned int V_4 ;
int V_28 = ( V_22 -> V_29 -> V_30 ==
V_31 ) ? 0 : V_32 ;
V_4 = ( ( void * ) V_23 -> V_12 - sizeof( * V_25 ) -
V_28 - NULL ) & ( V_33 - 1 ) ;
F_7 ( V_23 , V_4 ) ;
F_7 ( V_23 , sizeof( * V_25 ) ) ;
V_25 = (struct V_24 * ) V_23 -> V_12 ;
memset ( V_25 , 0 , sizeof( struct V_24 ) ) ;
V_25 -> V_34 = ( V_35 ) V_23 -> V_34 ;
V_25 -> V_36 =
F_8 ( V_22 , V_23 ) ;
V_25 -> V_37 = V_22 -> V_37 ;
V_25 -> V_38 = V_22 -> V_38 ;
V_25 -> V_39 = F_9 ( sizeof( struct V_24 ) +
V_4 ) ;
V_25 -> V_40 = F_9 ( V_41 ) ;
V_25 -> V_42 = F_9 ( V_23 -> V_18 -
sizeof( * V_25 ) -
V_4 ) ;
if ( V_27 -> V_43 & V_44 )
V_25 -> V_43 |= V_45 ;
if ( V_25 -> V_46 == 0 )
V_25 -> V_46 = F_10 ( V_22 -> V_47 ) ;
if ( F_11 ( V_22 ) == V_48 &&
V_22 -> V_29 -> V_49 ) {
if ( true == F_12 ( V_22 ) ) {
V_22 -> V_29 -> V_50 = true ;
V_25 -> V_43 =
V_51 ;
}
}
}
int
F_13 ( struct V_21 * V_22 ,
struct V_52 * V_53 ,
int V_54 , unsigned long V_55 )
__releases( &priv->wmm.ra_list_spinlock
