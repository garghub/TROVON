static int T_1 F_1 ( void )
{
F_2 ( L_1 , L_2 ) ;
V_1 [ V_2 ]
= V_1 [ V_3 ]
= & V_4 ;
if ( V_5 == V_6 )
V_5 = & V_4 ;
return 0 ;
}
static void T_2 F_3 ( void )
{
F_4 ( & V_4 ) ;
}
static T_3 F_5 ( struct V_7 * V_8 , struct V_9 * V_10 )
{
struct V_11 * V_12 = (struct V_11 * ) V_8 -> V_13 ;
struct V_14 * V_15 = & V_12 -> V_15 . V_16 ;
int V_17 = V_18 + V_19 ;
F_6 ( V_8 ) ;
F_7 ( V_8 , V_17 ) ;
if ( V_12 -> V_20 . V_21 == 0 ) {
V_8 -> V_22 = V_23 ;
} else if ( V_10 -> V_24 & V_25 ) {
if ( V_12 -> V_20 . V_21 != V_10 -> V_26 [ 0 ] )
V_8 -> V_22 = V_27 ;
}
switch ( V_15 -> V_28 ) {
case V_2 :
return F_8 ( V_29 ) ;
case V_3 :
return F_8 ( V_30 ) ;
default:
V_10 -> V_31 . V_32 ++ ;
V_10 -> V_31 . V_33 ++ ;
return 0 ;
}
return F_8 ( V_29 ) ;
}
static void F_9 ( struct V_9 * V_10 , int V_34 ,
struct V_11 * V_35 , int V_36 )
{
struct V_37 * V_38 = F_10 ( V_10 ) ;
struct V_7 * V_8 ;
struct V_11 * V_12 = V_35 ;
int V_39 ;
F_11 ( V_40 , V_10 , L_3 , V_36 ) ;
if ( V_36 >= V_41 )
V_39 = 512 - V_36 ;
else
V_39 = 256 - V_36 ;
V_8 = F_12 ( V_36 + V_18 , V_42 ) ;
if ( ! V_8 ) {
V_10 -> V_31 . V_43 ++ ;
return;
}
F_13 ( V_8 , V_36 + V_18 ) ;
V_8 -> V_10 = V_10 ;
V_12 = (struct V_11 * ) V_8 -> V_13 ;
memcpy ( V_12 , V_35 , sizeof( struct V_11 ) ) ;
if ( V_36 > sizeof( V_12 -> V_15 ) )
V_38 -> V_44 . V_45 ( V_10 , V_34 , V_39 + sizeof( V_12 -> V_15 ) ,
V_12 -> V_15 . V_46 + sizeof( V_12 -> V_15 ) ,
V_36 - sizeof( V_12 -> V_15 ) ) ;
if ( F_14 ( V_47 ) )
F_15 ( V_10 , V_8 , L_4 ) ;
V_8 -> V_48 = F_5 ( V_8 , V_10 ) ;
F_16 ( V_8 ) ;
}
static int F_17 ( struct V_7 * V_8 , struct V_9 * V_10 ,
unsigned short type , T_4 V_49 )
{
int V_17 = V_18 + V_19 ;
struct V_11 * V_12 = F_18 ( V_8 , V_17 ) ;
struct V_14 * V_15 = & V_12 -> V_15 . V_16 ;
switch ( type ) {
case V_29 :
V_15 -> V_28 = V_2 ;
break;
case V_30 :
V_15 -> V_28 = V_3 ;
break;
default:
F_11 ( V_50 , V_10 , L_5 ,
type , type ) ;
V_10 -> V_31 . V_51 ++ ;
V_10 -> V_31 . V_52 ++ ;
return 0 ;
}
V_12 -> V_20 . V_53 = * V_10 -> V_26 ;
if ( V_10 -> V_24 & ( V_54 | V_55 ) ) {
V_12 -> V_20 . V_21 = 0 ;
return V_17 ;
}
V_12 -> V_20 . V_21 = V_49 ;
return V_17 ;
}
static int F_19 ( struct V_9 * V_10 , struct V_11 * V_12 , int V_36 ,
int V_34 )
{
struct V_37 * V_38 = F_10 ( V_10 ) ;
struct V_56 * V_20 = & V_12 -> V_20 ;
int V_39 ;
F_11 ( V_40 , V_10 , L_6 ,
V_38 -> V_57 , V_38 -> V_58 , V_34 ) ;
V_36 -= V_18 ;
if ( V_36 > V_59 ) {
F_11 ( V_50 , V_10 , L_7 ,
V_36 , V_59 ) ;
V_36 = V_59 ;
}
if ( V_36 > V_41 ) {
V_20 -> V_60 [ 0 ] = 0 ;
V_20 -> V_60 [ 1 ] = V_39 = 512 - V_36 ;
} else if ( V_36 > V_61 ) {
V_20 -> V_60 [ 0 ] = 0 ;
V_20 -> V_60 [ 1 ] = V_39 = 512 - V_36 - 3 ;
} else {
V_20 -> V_60 [ 0 ] = V_39 = 256 - V_36 ;
}
V_38 -> V_44 . V_62 ( V_10 , V_34 , 0 , V_20 , V_18 ) ;
V_38 -> V_44 . V_62 ( V_10 , V_34 , V_39 , & V_12 -> V_15 , V_36 ) ;
V_38 -> V_63 = V_20 -> V_21 ;
return 1 ;
}
