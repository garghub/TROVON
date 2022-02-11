static int T_1 F_1 ( void )
{
F_2 ( V_1 ) ;
V_2 [ V_3 ]
= V_2 [ V_4 ]
= & V_5 ;
if ( V_6 == V_7 )
V_6 = & V_5 ;
return 0 ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_5 ) ;
}
static T_3 F_5 ( struct V_8 * V_9 , struct V_10 * V_11 )
{
struct V_12 * V_13 = (struct V_12 * ) V_9 -> V_14 ;
struct V_15 * V_16 = & V_13 -> V_16 . V_17 ;
int V_18 = V_19 + V_20 ;
F_6 ( V_9 ) ;
F_7 ( V_9 , V_18 ) ;
if ( V_13 -> V_21 . V_22 == 0 )
V_9 -> V_23 = V_24 ;
else if ( V_11 -> V_25 & V_26 ) {
if ( V_13 -> V_21 . V_22 != V_11 -> V_27 [ 0 ] )
V_9 -> V_23 = V_28 ;
}
switch ( V_16 -> V_29 ) {
case V_3 :
return F_8 ( V_30 ) ;
case V_4 :
return F_8 ( V_31 ) ;
default:
V_11 -> V_32 . V_33 ++ ;
V_11 -> V_32 . V_34 ++ ;
return 0 ;
}
return F_8 ( V_30 ) ;
}
static void F_9 ( struct V_10 * V_11 , int V_35 ,
struct V_12 * V_36 , int V_37 )
{
struct V_38 * V_39 = F_10 ( V_11 ) ;
struct V_8 * V_9 ;
struct V_12 * V_13 = V_36 ;
int V_40 ;
F_11 ( V_41 , L_1 , V_37 ) ;
if ( V_37 >= V_42 )
V_40 = 512 - V_37 ;
else
V_40 = 256 - V_37 ;
V_9 = F_12 ( V_37 + V_19 , V_43 ) ;
if ( V_9 == NULL ) {
F_11 ( V_44 , L_2 ) ;
V_11 -> V_32 . V_45 ++ ;
return;
}
F_13 ( V_9 , V_37 + V_19 ) ;
V_9 -> V_11 = V_11 ;
V_13 = (struct V_12 * ) V_9 -> V_14 ;
memcpy ( V_13 , V_36 , sizeof( struct V_12 ) ) ;
if ( V_37 > sizeof( V_13 -> V_16 ) )
V_39 -> V_46 . V_47 ( V_11 , V_35 , V_40 + sizeof( V_13 -> V_16 ) ,
V_13 -> V_16 . V_48 + sizeof( V_13 -> V_16 ) ,
V_37 - sizeof( V_13 -> V_16 ) ) ;
F_14 (D_SKB) F_15 ( V_11 , V_9 , L_3 ) ;
V_9 -> V_49 = F_5 ( V_9 , V_11 ) ;
F_16 ( V_9 ) ;
}
static int F_17 ( struct V_8 * V_9 , struct V_10 * V_11 ,
unsigned short type , T_4 V_50 )
{
int V_18 = V_19 + V_20 ;
struct V_12 * V_13 = (struct V_12 * ) F_18 ( V_9 , V_18 ) ;
struct V_15 * V_16 = & V_13 -> V_16 . V_17 ;
switch ( type ) {
case V_30 :
V_16 -> V_29 = V_3 ;
break;
case V_31 :
V_16 -> V_29 = V_4 ;
break;
default:
F_11 ( V_44 , L_4 ,
type , type ) ;
V_11 -> V_32 . V_51 ++ ;
V_11 -> V_32 . V_52 ++ ;
return 0 ;
}
V_13 -> V_21 . V_53 = * V_11 -> V_27 ;
if ( V_11 -> V_25 & ( V_54 | V_55 ) ) {
V_13 -> V_21 . V_22 = 0 ;
return V_18 ;
}
V_13 -> V_21 . V_22 = V_50 ;
return V_18 ;
}
static int F_19 ( struct V_10 * V_11 , struct V_12 * V_13 , int V_37 ,
int V_35 )
{
struct V_38 * V_39 = F_10 ( V_11 ) ;
struct V_56 * V_21 = & V_13 -> V_21 ;
int V_40 ;
F_11 ( V_41 , L_5 ,
V_39 -> V_57 , V_39 -> V_58 , V_35 ) ;
V_37 -= V_19 ;
if ( V_37 > V_59 ) {
F_11 ( V_44 , L_6 ,
V_37 , V_59 ) ;
V_37 = V_59 ;
}
if ( V_37 > V_42 ) {
V_21 -> V_60 [ 0 ] = 0 ;
V_21 -> V_60 [ 1 ] = V_40 = 512 - V_37 ;
} else if ( V_37 > V_61 ) {
V_21 -> V_60 [ 0 ] = 0 ;
V_21 -> V_60 [ 1 ] = V_40 = 512 - V_37 - 3 ;
} else
V_21 -> V_60 [ 0 ] = V_40 = 256 - V_37 ;
V_39 -> V_46 . V_62 ( V_11 , V_35 , 0 , V_21 , V_19 ) ;
V_39 -> V_46 . V_62 ( V_11 , V_35 , V_40 , & V_13 -> V_16 , V_37 ) ;
V_39 -> V_63 = V_21 -> V_22 ;
return 1 ;
}
