static bool F_1 ( struct V_1 * V_2 )
{
T_1 V_3 ;
const T_1 V_4 = F_2 ( V_5 ) ;
T_1 * V_6 = V_5 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 += 2 ) {
T_1 V_7 = V_6 [ V_3 ] ;
T_1 V_8 = V_6 [ V_3 + 1 ] ;
if ( V_7 < 0xCDCDCDCD ) {
F_3 ( V_2 , V_7 , V_9 , V_8 ) ;
F_4 ( 1 ) ;
}
}
return true ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_10 , T_1 V_11 )
{
if ( V_10 == 0xfe ) {
F_6 ( 50 ) ;
} else if ( V_10 == 0xfd ) {
F_7 ( 5 ) ;
} else if ( V_10 == 0xfc ) {
F_7 ( 1 ) ;
} else if ( V_10 == 0xfb ) {
F_4 ( 50 ) ;
} else if ( V_10 == 0xfa ) {
F_4 ( 5 ) ;
} else if ( V_10 == 0xf9 ) {
F_4 ( 1 ) ;
} else {
F_3 ( V_2 , V_10 , V_9 , V_11 ) ;
F_4 ( 1 ) ;
}
}
static bool F_8 ( struct V_1 * V_2 )
{
T_1 V_3 ;
const T_1 V_4 = F_2 ( V_12 ) ;
T_1 * V_6 = V_12 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 += 2 ) {
T_1 V_7 = V_6 [ V_3 ] ;
T_1 V_8 = V_6 [ V_3 + 1 ] ;
if ( V_7 < 0xCDCDCDCD )
F_5 ( V_2 , V_7 , V_8 ) ;
}
return true ;
}
static void F_9 ( struct V_1 * V_1 ,
T_1 V_13 , T_1 V_14 , T_1 V_11 )
{
struct V_15 * V_16 = V_1 -> V_17 ;
T_1 * const V_18 =
V_16 -> V_19 [ V_16 -> V_20 ] ;
if ( V_13 == V_21 )
V_18 [ 0 ] = V_11 ;
if ( V_13 == V_22 )
V_18 [ 1 ] = V_11 ;
if ( V_13 == V_23 )
V_18 [ 6 ] = V_11 ;
if ( V_13 == V_24 && V_14 == 0xffffff00 )
V_18 [ 7 ] = V_11 ;
if ( V_13 == V_25 )
V_18 [ 2 ] = V_11 ;
if ( V_13 == V_26 )
V_18 [ 3 ] = V_11 ;
if ( V_13 == V_27 )
V_18 [ 4 ] = V_11 ;
if ( V_13 == V_28 ) {
V_18 [ 5 ] = V_11 ;
V_16 -> V_20 ++ ;
}
if ( V_13 == V_29 )
V_18 [ 8 ] = V_11 ;
if ( V_13 == V_30 )
V_18 [ 9 ] = V_11 ;
if ( V_13 == V_31 )
V_18 [ 14 ] = V_11 ;
if ( V_13 == V_24 && V_14 == 0x000000ff )
V_18 [ 15 ] = V_11 ;
if ( V_13 == V_32 )
V_18 [ 10 ] = V_11 ;
if ( V_13 == V_33 )
V_18 [ 11 ] = V_11 ;
if ( V_13 == V_34 )
V_18 [ 12 ] = V_11 ;
if ( V_13 == V_35 ) {
V_18 [ 13 ] = V_11 ;
}
}
static void F_10 ( struct V_1 * V_2 ,
T_1 V_10 , T_1 V_36 , T_1 V_11 )
{
switch ( V_10 ) {
case 0xfe :
F_6 ( 50 ) ;
break;
case 0xfd :
F_7 ( 5 ) ;
break;
case 0xfc :
F_7 ( 1 ) ;
break;
case 0xfb :
F_4 ( 50 ) ;
break;
case 0xfa :
F_4 ( 5 ) ;
break;
case 0xf9 :
F_4 ( 1 ) ;
break;
default:
F_9 ( V_2 , V_10 , V_36 , V_11 ) ;
}
}
static bool F_11 ( struct V_1 * V_2 )
{
T_1 V_3 ;
const T_1 V_4 = F_2 ( V_37 ) ;
T_1 * V_6 = V_37 ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 += 3 ) {
T_1 V_7 = V_6 [ V_3 ] ;
T_1 V_8 = V_6 [ V_3 + 1 ] ;
T_1 V_38 = V_6 [ V_3 + 2 ] ;
if ( V_7 < 0xCDCDCDCD )
F_10 ( V_2 , V_7 , V_8 , V_38 ) ;
}
return true ;
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_39 * V_40 [ 4 ] ;
V_40 [ V_41 ] = & V_1 -> V_17 -> V_42 [ V_41 ] ;
V_40 [ V_43 ] = & V_1 -> V_17 -> V_42 [ V_43 ] ;
V_40 [ V_41 ] -> V_44 = V_45 ;
V_40 [ V_43 ] -> V_44 = V_45 ;
V_40 [ V_41 ] -> V_46 = V_47 ;
V_40 [ V_43 ] -> V_46 = V_47 ;
V_40 [ V_41 ] -> V_48 = V_49 ;
V_40 [ V_43 ] -> V_48 = V_50 ;
V_40 [ V_41 ] -> V_51 = V_49 ;
V_40 [ V_43 ] -> V_51 = V_50 ;
V_40 [ V_41 ] -> V_52 = V_53 ;
V_40 [ V_43 ] -> V_52 = V_54 ;
V_40 [ V_41 ] -> V_55 = V_56 ;
V_40 [ V_43 ] -> V_55 = V_56 ;
V_40 [ V_41 ] -> V_57 = V_58 ;
V_40 [ V_43 ] -> V_57 = V_58 ;
V_40 [ V_41 ] -> V_59 = V_60 ;
V_40 [ V_43 ] -> V_59 = V_61 ;
V_40 [ V_41 ] -> V_62 = V_63 ;
V_40 [ V_43 ] -> V_62 = V_64 ;
V_40 [ V_41 ] -> V_65 = V_66 ;
V_40 [ V_43 ] -> V_65 = V_66 ;
V_40 [ V_41 ] -> V_67 = V_68 ;
V_40 [ V_43 ] -> V_67 = V_69 ;
V_40 [ V_41 ] -> V_70 = V_71 ;
V_40 [ V_43 ] -> V_70 = V_72 ;
V_40 [ V_41 ] -> V_73 = V_74 ;
V_40 [ V_43 ] -> V_73 = V_75 ;
V_40 [ V_41 ] -> V_76 = V_77 ;
V_40 [ V_43 ] -> V_76 = V_78 ;
V_40 [ V_41 ] -> V_79 = V_80 ;
V_40 [ V_43 ] -> V_79 = V_81 ;
V_40 [ V_41 ] -> V_82 = V_83 ;
V_40 [ V_43 ] -> V_82 = V_84 ;
V_40 [ V_41 ] -> V_85 = V_86 ;
V_40 [ V_43 ] -> V_85 = V_87 ;
V_40 [ V_41 ] -> V_88 = V_89 ;
V_40 [ V_43 ] -> V_88 = V_90 ;
}
static bool F_13 ( struct V_1 * V_2 )
{
struct V_91 * V_92 = F_14 ( V_2 ) ;
F_8 ( V_2 ) ;
if ( ! V_92 -> V_93 ) {
V_2 -> V_17 -> V_20 = 0 ;
F_11 ( V_2 ) ;
}
F_1 ( V_2 ) ;
return true ;
}
bool F_15 ( struct V_1 * V_2 )
{
int V_94 = true ;
T_1 V_95 ;
T_2 V_96 ;
F_12 ( V_2 ) ;
V_95 = F_16 ( V_2 , V_97 ) ;
F_17 ( V_2 , V_97 ,
( V_98 ) ( V_95 | F_18 ( 13 ) | F_18 ( 0 ) | F_18 ( 1 ) ) ) ;
F_19 ( V_2 , V_99 , V_100 | V_101 | V_102 ) ;
F_19 ( V_2 , V_97 , V_103 |
V_104 | V_105 | V_106 ) ;
V_94 = F_13 ( V_2 ) ;
V_96 = V_2 -> V_17 -> V_107 & 0x3F ;
F_3 ( V_2 , V_108 , 0x7ff800 ,
( V_96 | ( V_96 << 6 ) ) ) ;
return V_94 ;
}
