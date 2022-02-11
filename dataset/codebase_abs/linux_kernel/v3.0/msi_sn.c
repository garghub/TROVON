void F_1 ( unsigned int V_1 )
{
T_1 V_2 ;
int V_3 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_8 ;
struct V_9 * V_10 ;
struct V_11 * V_12 ;
V_8 = V_13 [ V_1 ] . V_8 ;
if ( V_8 == NULL || V_8 -> V_14 >= 0 )
return;
V_7 = (struct V_6 * ) V_8 -> V_15 ;
V_5 = V_7 -> V_16 ;
V_12 = F_2 ( V_5 ) ;
(* V_12 -> V_17 )( V_5 ,
V_13 [ V_1 ] . V_18 ,
V_19 ) ;
V_13 [ V_1 ] . V_18 = 0 ;
V_10 = F_3 ( V_5 ) ;
V_2 = F_4 ( V_10 -> V_20 ) ;
V_3 = ( V_2 & 1 ) ?
F_5 ( V_10 -> V_20 ) :
F_6 ( V_10 -> V_20 ) ;
F_7 ( V_2 , V_3 , V_8 ) ;
V_13 [ V_1 ] . V_8 = NULL ;
F_8 ( V_1 ) ;
}
int F_9 ( struct V_4 * V_5 , struct V_21 * V_22 )
{
struct V_23 V_24 ;
int V_3 ;
int V_25 ;
T_1 V_2 ;
T_2 V_26 ;
struct V_8 * V_8 ;
struct V_9 * V_10 = F_3 ( V_5 ) ;
struct V_11 * V_12 = F_2 ( V_5 ) ;
int V_1 ;
if ( ! V_22 -> V_27 . V_28 )
return - V_29 ;
if ( V_10 == NULL )
return - V_29 ;
if ( V_12 == NULL || V_12 -> V_30 == NULL )
return - V_29 ;
V_1 = F_10 () ;
if ( V_1 < 0 )
return V_1 ;
V_2 = F_4 ( V_10 -> V_20 ) ;
V_3 = ( V_2 & 1 ) ?
F_5 ( V_10 -> V_20 ) :
F_6 ( V_10 -> V_20 ) ;
V_8 = F_11 ( sizeof( struct V_8 ) , V_31 ) ;
if ( ! V_8 ) {
F_8 ( V_1 ) ;
return - V_32 ;
}
V_25 = F_12 ( V_2 , V_3 , V_8 , V_1 , - 1 , - 1 ) ;
if ( V_25 ) {
F_13 ( V_8 ) ;
F_8 ( V_1 ) ;
return - V_32 ;
}
V_8 -> V_14 = - 1 ;
F_14 ( V_5 , V_8 ) ;
V_8 -> V_33 = V_10 -> V_34 ;
V_8 -> V_35 = ( void * ) V_10 -> V_20 ;
V_26 = (* V_12 -> V_30 )( V_5 ,
V_8 -> V_36 ,
sizeof( V_8 -> V_36 ) ,
V_37 | V_38 ) ;
if ( ! V_26 ) {
F_7 ( V_2 , V_3 , V_8 ) ;
F_13 ( V_8 ) ;
F_8 ( V_1 ) ;
return - V_32 ;
}
V_13 [ V_1 ] . V_8 = V_8 ;
V_13 [ V_1 ] . V_18 = V_26 ;
V_24 . V_39 = ( V_40 ) ( V_26 >> 32 ) ;
V_24 . V_41 = ( V_40 ) ( V_26 & 0x00000000ffffffff ) ;
V_24 . V_42 = 0x100 + V_1 ;
F_15 ( V_1 , V_22 ) ;
F_16 ( V_1 , & V_24 ) ;
F_17 ( V_1 , & V_43 , V_44 ) ;
return 0 ;
}
static int F_18 ( struct V_45 * V_42 ,
const struct V_46 * V_47 , bool V_48 )
{
struct V_23 V_24 ;
int V_49 ;
T_1 V_2 ;
T_2 V_26 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_8 ;
struct V_8 * V_50 ;
struct V_11 * V_12 ;
unsigned int V_51 , V_1 = V_42 -> V_1 ;
V_51 = F_19 ( V_47 ) ;
V_8 = V_13 [ V_1 ] . V_8 ;
if ( V_8 == NULL || V_8 -> V_14 >= 0 )
return - 1 ;
F_20 ( V_1 , & V_24 ) ;
V_7 = (struct V_6 * ) V_8 -> V_15 ;
V_5 = V_7 -> V_16 ;
V_12 = F_2 ( V_5 ) ;
V_26 = ( T_2 ) ( V_24 . V_39 ) << 32 | ( T_2 ) ( V_24 . V_41 ) ;
(* V_12 -> V_17 )( V_5 , V_26 , V_19 ) ;
V_13 [ V_1 ] . V_18 = 0 ;
V_2 = F_21 ( V_51 ) ;
V_49 = F_22 ( V_51 ) ;
V_50 = F_23 ( V_8 , V_2 , V_49 ) ;
V_13 [ V_1 ] . V_8 = V_50 ;
if ( V_50 == NULL )
return - 1 ;
V_26 = (* V_12 -> V_30 )( V_5 ,
V_50 -> V_36 ,
sizeof( V_50 -> V_36 ) ,
V_37 | V_38 ) ;
V_13 [ V_1 ] . V_18 = V_26 ;
V_24 . V_39 = ( V_40 ) ( V_26 >> 32 ) ;
V_24 . V_41 = ( V_40 ) ( V_26 & 0x00000000ffffffff ) ;
F_16 ( V_1 , & V_24 ) ;
F_24 ( V_42 -> V_52 , V_47 ) ;
return 0 ;
}
static void F_25 ( struct V_45 * V_42 )
{
F_26 ( V_42 ) ;
F_27 () ;
}
static int F_28 ( struct V_45 * V_42 )
{
unsigned int V_53 = V_42 -> V_1 ;
F_29 ( V_53 ) ;
return 1 ;
}
