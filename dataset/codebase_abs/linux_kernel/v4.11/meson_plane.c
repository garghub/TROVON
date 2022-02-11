static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 V_8 = { 0 , } ;
if ( ! V_4 -> V_9 )
return 0 ;
V_6 = F_2 ( V_4 -> V_4 , V_4 -> V_9 ) ;
if ( F_3 ( V_6 ) )
return F_4 ( V_6 ) ;
V_8 . V_10 = V_6 -> V_11 . V_12 ;
V_8 . V_13 = V_6 -> V_11 . V_14 ;
return F_5 ( V_4 , & V_8 ,
V_15 ,
V_15 ,
true , true ) ;
}
static inline T_1 F_6 ( T_1 V_16 )
{
return V_16 >> 16 ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_3 * V_17 )
{
struct V_18 * V_18 = F_8 ( V_2 ) ;
struct V_3 * V_4 = V_2 -> V_4 ;
struct V_19 * V_20 = V_4 -> V_20 ;
struct V_21 * V_22 = V_18 -> V_22 ;
struct V_23 * V_24 ;
struct V_7 V_25 = {
. V_26 = ( V_4 -> V_27 ) ,
. y1 = ( V_4 -> V_28 ) ,
. V_10 = ( V_4 -> V_27 + V_4 -> V_29 ) ,
. V_13 = ( V_4 -> V_28 + V_4 -> V_30 ) ,
} ;
struct V_7 V_31 = {
. V_26 = V_4 -> V_32 ,
. y1 = V_4 -> V_33 ,
. V_10 = V_4 -> V_32 + V_4 -> V_34 ,
. V_13 = V_4 -> V_33 + V_4 -> V_35 ,
} ;
unsigned long V_36 ;
F_9 ( & V_22 -> V_37 -> V_38 , V_36 ) ;
V_22 -> V_39 . V_40 = V_41 |
( 0xFF << V_42 ) |
V_43 ;
V_22 -> V_39 . V_44 [ 0 ] = ( ( V_45 << V_46 ) |
V_47 ) ;
if ( F_10 ( V_22 , L_1 ) )
V_22 -> V_39 . V_44 [ 0 ] |= V_48 ;
switch ( V_20 -> V_49 -> V_49 ) {
case V_50 :
F_11 ( V_51 , V_51 ,
V_22 -> V_52 + F_12 ( V_53 ) ) ;
V_22 -> V_39 . V_44 [ 0 ] |= V_54 |
V_55 ;
break;
case V_56 :
F_11 ( V_51 , 0 ,
V_22 -> V_52 + F_12 ( V_53 ) ) ;
V_22 -> V_39 . V_44 [ 0 ] |= V_54 |
V_55 ;
break;
case V_57 :
V_22 -> V_39 . V_44 [ 0 ] |= V_58 |
V_59 ;
break;
case V_60 :
V_22 -> V_39 . V_44 [ 0 ] |= V_61 |
V_62 ;
break;
} ;
if ( V_4 -> V_9 -> V_11 . V_36 & V_63 ) {
V_22 -> V_39 . V_64 = true ;
V_31 . y1 /= 2 ;
V_31 . V_13 /= 2 ;
} else
V_22 -> V_39 . V_64 = false ;
V_22 -> V_39 . V_44 [ 1 ] = ( ( F_6 ( V_25 . V_10 ) - 1 ) << 16 ) |
F_6 ( V_25 . V_26 ) ;
V_22 -> V_39 . V_44 [ 2 ] = ( ( F_6 ( V_25 . V_13 ) - 1 ) << 16 ) |
F_6 ( V_25 . y1 ) ;
V_22 -> V_39 . V_44 [ 3 ] = ( ( V_31 . V_10 - 1 ) << 16 ) | V_31 . V_26 ;
V_22 -> V_39 . V_44 [ 4 ] = ( ( V_31 . V_13 - 1 ) << 16 ) | V_31 . y1 ;
V_24 = F_13 ( V_20 , 0 ) ;
F_14 ( V_22 , V_45 ,
V_24 -> V_65 , V_20 -> V_66 [ 0 ] ,
V_20 -> V_67 , V_68 ,
V_69 ) ;
F_15 ( & V_22 -> V_37 -> V_38 , V_36 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_3 * V_17 )
{
struct V_18 * V_18 = F_8 ( V_2 ) ;
struct V_21 * V_22 = V_18 -> V_22 ;
F_11 ( V_70 , 0 ,
V_22 -> V_52 + F_12 ( V_71 ) ) ;
}
int F_17 ( struct V_21 * V_22 )
{
struct V_18 * V_18 ;
struct V_1 * V_2 ;
V_18 = F_18 ( V_22 -> V_37 -> V_72 , sizeof( * V_18 ) ,
V_73 ) ;
if ( ! V_18 )
return - V_74 ;
V_18 -> V_22 = V_22 ;
V_2 = & V_18 -> V_75 ;
F_19 ( V_22 -> V_37 , V_2 , 0xFF ,
& V_76 ,
V_77 ,
F_20 ( V_77 ) ,
V_78 , L_2 ) ;
F_21 ( V_2 , & V_79 ) ;
V_22 -> V_80 = V_2 ;
return 0 ;
}
