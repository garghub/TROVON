static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_7 * V_8 = & V_2 -> V_9 -> V_8 ;
F_4 ( * V_10 [] ) [ 4 ] [ 7 ] = { & V_4 -> V_11 . V_12 ,
& V_4 -> V_11 . V_13 } ;
int V_14 , V_15 , V_16 ;
T_1 V_17 = F_5 ( V_4 -> V_17 ) ;
T_2 V_18 = ( V_4 -> V_18 - 50 ) * ( V_19 / 100 ) ;
T_3 V_20 [] = { V_8 -> V_21 * V_19 ,
V_8 -> V_22 * V_19 } ;
F_6 ( V_20 [ 0 ] , V_17 * V_6 -> V_23 . V_21 ) ;
F_6 ( V_20 [ 1 ] , V_17 * V_6 -> V_23 . V_22 ) ;
for ( V_16 = 0 ; V_16 < 2 ; V_16 ++ ) {
V_20 [ V_16 ] = F_7 ( ( T_2 ) V_20 [ V_16 ] , V_24 ) ;
for ( V_15 = 0 ; V_15 < 4 ; V_15 ++ ) {
struct V_25 * V_26 = & V_27 [ V_16 ] [ V_15 ] ;
for ( V_14 = 0 ; V_14 < 7 ; V_14 ++ ) {
T_2 V_28 = ( V_26 -> V_29 + V_26 -> V_30 * V_14 + V_26 -> V_31 * V_14 * V_14 +
V_26 -> V_32 * V_14 * V_14 * V_14 )
+ ( V_26 -> V_33 + V_26 -> V_34 * V_14 + V_26 -> V_35 * V_14 * V_14 +
V_26 -> V_36 * V_14 * V_14 * V_14 ) * V_20 [ V_16 ]
+ ( V_26 -> V_37 + V_26 -> V_38 * V_14 + V_26 -> V_39 * V_14 * V_14 +
V_26 -> V_40 * V_14 * V_14 * V_14 ) * V_18
+ ( V_26 -> V_41 + V_26 -> V_42 * V_14 + V_26 -> V_43 * V_14 * V_14 +
V_26 -> V_44 * V_14 * V_14 * V_14 ) * V_18 * V_20 [ V_16 ] ;
( * V_10 [ V_16 ] ) [ V_15 ] [ V_14 ] = ( V_28 + V_45 / 2 ) >> 39
& ( 0x1 << 31 | 0x7f << 9 ) ;
}
}
}
}
static void F_8 ( struct V_46 * V_47 , F_4 V_48 ,
F_4 V_49 [ 4 ] [ 7 ] )
{
int V_14 , V_15 ;
F_4 V_50 [] = { V_48 , V_48 + 0x1c , V_48 + 0x40 , V_48 + 0x5c } ;
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
for ( V_15 = 0 ; V_15 < 7 ; V_15 ++ )
V_49 [ V_14 ] [ V_15 ] = F_9 ( V_47 , V_50 [ V_14 ] + 4 * V_15 ) ;
}
}
static void F_10 ( struct V_46 * V_47 , F_4 V_48 ,
F_4 V_49 [ 4 ] [ 7 ] )
{
int V_14 , V_15 ;
F_4 V_50 [] = { V_48 , V_48 + 0x1c , V_48 + 0x40 , V_48 + 0x5c } ;
for ( V_14 = 0 ; V_14 < 4 ; V_14 ++ ) {
for ( V_15 = 0 ; V_15 < 7 ; V_15 ++ )
F_11 ( V_47 , V_50 [ V_14 ] + 4 * V_15 , V_49 [ V_14 ] [ V_15 ] ) ;
}
}
void F_12 ( struct V_46 * V_47 , struct V_51 * V_11 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < 0x40 ; V_14 ++ )
V_11 -> V_4 [ V_14 ] = F_13 ( V_47 , V_14 ) ;
F_8 ( V_47 , V_52 , V_11 -> V_12 ) ;
F_8 ( V_47 , V_53 , V_11 -> V_54 ) ;
F_8 ( V_47 , V_55 , V_11 -> V_13 ) ;
F_14 ( V_47 , V_11 , 200 ) ;
F_14 ( V_47 , V_11 , 204 ) ;
F_14 ( V_47 , V_11 , 208 ) ;
F_14 ( V_47 , V_11 , 20c ) ;
F_14 ( V_47 , V_11 , 304 ) ;
F_14 ( V_47 , V_11 , 500 ) ;
F_14 ( V_47 , V_11 , 504 ) ;
F_14 ( V_47 , V_11 , 508 ) ;
F_14 ( V_47 , V_11 , 600 ) ;
F_14 ( V_47 , V_11 , 604 ) ;
F_14 ( V_47 , V_11 , 608 ) ;
F_14 ( V_47 , V_11 , 60c ) ;
F_14 ( V_47 , V_11 , 610 ) ;
F_14 ( V_47 , V_11 , 614 ) ;
}
void F_15 ( struct V_46 * V_47 , struct V_51 * V_11 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 < 0x40 ; V_14 ++ )
F_16 ( V_47 , V_14 , V_11 -> V_4 [ V_14 ] ) ;
F_10 ( V_47 , V_52 , V_11 -> V_12 ) ;
F_10 ( V_47 , V_53 , V_11 -> V_54 ) ;
F_10 ( V_47 , V_55 , V_11 -> V_13 ) ;
F_17 ( V_47 , V_11 , 200 ) ;
F_17 ( V_47 , V_11 , 204 ) ;
F_17 ( V_47 , V_11 , 208 ) ;
F_17 ( V_47 , V_11 , 20c ) ;
F_17 ( V_47 , V_11 , 304 ) ;
F_17 ( V_47 , V_11 , 500 ) ;
F_17 ( V_47 , V_11 , 504 ) ;
F_17 ( V_47 , V_11 , 508 ) ;
F_17 ( V_47 , V_11 , 600 ) ;
F_17 ( V_47 , V_11 , 604 ) ;
F_17 ( V_47 , V_11 , 608 ) ;
F_17 ( V_47 , V_11 , 60c ) ;
F_17 ( V_47 , V_11 , 610 ) ;
F_17 ( V_47 , V_11 , 614 ) ;
F_16 ( V_47 , 0x3e , 1 ) ;
F_16 ( V_47 , 0x3e , 0 ) ;
}
void F_18 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_51 * V_49 = & V_4 -> V_11 ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
int V_56 = V_4 -> V_57 ?
V_4 -> V_57 :
V_4 -> V_56 ;
switch ( V_56 ) {
case V_58 :
{
V_49 -> V_59 = 0x2 ;
if ( V_4 -> V_60 & 0x4 )
V_49 -> V_59 |= 0x010000 ;
else if ( V_4 -> V_60 & 0x2 )
V_49 -> V_59 |= 0x100000 ;
else
V_49 -> V_59 |= 0x110000 ;
V_49 -> V_4 [ 0x7 ] = 0x10 ;
break;
}
case V_61 :
V_49 -> V_59 = 0x11012 ;
V_49 -> V_4 [ 0x7 ] = 0x18 ;
break;
case V_62 :
V_49 -> V_59 = 0x111333 ;
V_49 -> V_4 [ 0x7 ] = 0x14 ;
break;
case V_63 :
V_49 -> V_59 = 0x111012 ;
V_49 -> V_4 [ 0x7 ] = 0x18 ;
break;
}
V_49 -> V_4 [ 0x20 ] = F_19 ( 0 , V_6 -> V_23 . V_4 [ 0x20 ] ,
255 , V_4 -> V_64 ) ;
V_49 -> V_4 [ 0x22 ] = F_19 ( 0 , V_6 -> V_23 . V_4 [ 0x22 ] ,
255 , V_4 -> V_64 ) ;
V_49 -> V_4 [ 0x25 ] = V_4 -> V_65 * 255 / 100 ;
F_17 ( V_47 , V_49 , 204 ) ;
F_20 ( V_47 , V_49 , 7 ) ;
F_20 ( V_47 , V_49 , 20 ) ;
F_20 ( V_47 , V_49 , 22 ) ;
F_20 ( V_47 , V_49 , 25 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_51 * V_49 = & V_4 -> V_11 ;
V_49 -> V_66 = 0x40 | ( F_5 ( V_4 -> V_17 ) << 8 ) ;
F_1 ( V_2 ) ;
F_17 ( V_47 , V_49 , 208 ) ;
F_10 ( V_47 , V_52 , V_49 -> V_12 ) ;
F_10 ( V_47 , V_53 , V_49 -> V_54 ) ;
F_10 ( V_47 , V_55 , V_49 -> V_13 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
struct V_46 * V_47 = V_2 -> V_47 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_67 = F_23 ( V_2 -> V_9 ) -> V_68 ;
struct V_69 * V_49 = & F_24 ( V_47 ) -> V_70 . V_71 [ V_67 ] ;
struct V_7 * V_72 = & V_2 -> V_9 -> V_8 ;
struct V_7 * V_73 =
& F_3 ( V_2 ) -> V_74 . V_8 ;
int V_17 , V_75 , V_76 , V_77 , V_78 ;
if ( V_73 -> V_79 & V_80 )
V_17 = 100 ;
else
V_17 = V_4 -> V_17 ;
V_75 = ( V_73 -> V_21 - V_72 -> V_21 ) / 2 ;
V_76 = ( V_73 -> V_22 - V_72 -> V_22 ) / 2 ;
V_75 = F_19 ( 0 , F_25 ( V_75 , V_73 -> V_21 / 20 ) ,
V_75 , V_17 ) ;
V_76 = F_19 ( 0 , F_25 ( V_76 , V_73 -> V_22 / 20 ) ,
V_76 , V_17 ) ;
V_77 = V_72 -> V_21 * 0x800 /
( V_73 -> V_21 - 2 * V_75 ) ;
V_78 = V_72 -> V_22 * 0x800 /
( V_73 -> V_22 - 2 * V_76 ) & ~ 3 ;
V_49 -> V_81 [ V_82 ] = V_75 ;
V_49 -> V_81 [ V_83 ] = V_73 -> V_21 - V_75 - 1 ;
V_49 -> V_84 [ V_82 ] = V_76 ;
V_49 -> V_84 [ V_83 ] = V_73 -> V_22 - V_76 - 1 ;
V_49 -> V_85 = V_86 |
F_26 ( V_78 , 0 , V_87 ) |
V_88 |
F_26 ( V_77 , 0 , V_89 ) ;
F_27 ( V_47 , V_67 , V_90 ,
V_49 -> V_81 [ V_82 ] ) ;
F_27 ( V_47 , V_67 , V_91 ,
V_49 -> V_81 [ V_83 ] ) ;
F_27 ( V_47 , V_67 , V_92 ,
V_49 -> V_84 [ V_82 ] ) ;
F_27 ( V_47 , V_67 , V_93 ,
V_49 -> V_84 [ V_83 ] ) ;
F_27 ( V_47 , V_67 , V_94 , V_49 -> V_85 ) ;
}
