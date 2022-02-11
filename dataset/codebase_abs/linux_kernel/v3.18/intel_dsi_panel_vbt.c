static T_1 * F_1 ( struct V_1 * V_1 , T_1 * V_2 )
{
T_1 type , V_3 , V_4 , V_5 , V_6 ;
T_2 V_7 ;
V_3 = * V_2 ++ ;
V_4 = ( V_3 >> V_8 ) & 0x1 ;
V_5 = ( V_3 >> V_9 ) & 0x3 ;
V_6 = ( V_3 >> V_10 ) & 0x3 ;
V_1 -> V_11 = V_4 ;
type = * V_2 ++ ;
V_7 = * ( ( T_2 * ) V_2 ) ;
V_2 += 2 ;
switch ( type ) {
case V_12 :
F_2 ( V_1 , V_5 ) ;
break;
case V_13 :
F_3 ( V_1 , V_5 , * V_2 ) ;
break;
case V_14 :
F_4 ( V_1 , V_5 , * V_2 , * ( V_2 + 1 ) ) ;
break;
case V_15 :
case V_16 :
case V_17 :
F_5 ( L_1 ) ;
break;
case V_18 :
F_6 ( V_1 , V_5 , V_2 , V_7 ) ;
break;
case V_19 :
F_7 ( V_1 , V_5 , * V_2 ) ;
break;
case V_20 :
F_8 ( V_1 , V_5 , * V_2 , * ( V_2 + 1 ) ) ;
break;
case V_21 :
F_5 ( L_2 ) ;
break;
case V_22 :
F_9 ( V_1 , V_5 , V_2 , V_7 ) ;
break;
}
V_2 += V_7 ;
return V_2 ;
}
static T_1 * F_10 ( struct V_1 * V_1 , T_1 * V_2 )
{
T_3 V_23 = * ( ( T_3 * ) V_2 ) ;
F_11 ( V_23 , V_23 + 10 ) ;
V_2 += 4 ;
return V_2 ;
}
static T_1 * F_12 ( struct V_1 * V_1 , T_1 * V_2 )
{
T_1 V_24 , V_25 ;
T_2 V_26 , V_27 ;
T_3 V_28 ;
struct V_29 * V_30 = V_1 -> V_31 . V_31 . V_30 ;
struct V_32 * V_33 = V_30 -> V_34 ;
V_24 = * V_2 ++ ;
V_25 = * V_2 ++ ;
V_26 = V_35 [ V_24 ] . V_36 ;
V_27 = V_35 [ V_24 ] . V_37 ;
F_13 ( & V_33 -> V_38 ) ;
if ( ! V_35 [ V_24 ] . V_39 ) {
F_14 ( V_33 , V_26 , 0x2000CC00 ) ;
V_35 [ V_24 ] . V_39 = 1 ;
}
V_28 = 0x4 | V_25 ;
F_14 ( V_33 , V_27 , V_28 ) ;
F_15 ( & V_33 -> V_38 ) ;
return V_2 ;
}
static void F_16 ( struct V_1 * V_1 , char * V_40 )
{
T_1 * V_2 = V_40 ;
T_4 V_41 ;
int V_42 ;
if ( ! V_40 )
return;
F_5 ( L_3 , V_43 [ * V_2 ] ) ;
V_2 ++ ;
while ( 1 ) {
V_42 = * V_2 ;
V_41 = V_44 [ V_42 ] ;
if ( ! V_41 ) {
F_17 ( L_4 ) ;
return;
}
V_2 ++ ;
V_2 = V_41 ( V_1 , V_2 ) ;
if ( * V_2 == 0x00 )
break;
}
}
static bool F_18 ( struct V_45 * V_46 )
{
struct V_1 * V_1 = F_19 ( V_46 , struct V_1 , V_30 ) ;
struct V_29 * V_30 = V_1 -> V_31 . V_31 . V_30 ;
struct V_32 * V_33 = V_30 -> V_34 ;
struct V_47 * V_47 = V_33 -> V_48 . V_46 . V_49 ;
struct V_50 * V_51 = V_33 -> V_48 . V_46 . V_51 ;
struct V_52 * V_4 = V_33 -> V_48 . V_53 ;
T_3 V_54 = 24 ;
T_3 V_55 , V_56 , V_57 , V_58 ;
T_3 V_59 , V_60 ;
T_3 V_61 , V_62 , V_63 , V_64 ;
T_3 V_65 , V_66 ;
T_3 V_67 , V_68 ;
T_3 V_69 , V_70 ;
T_3 V_71 , V_72 ;
T_2 V_73 ;
F_20 ( L_5 ) ;
V_1 -> V_74 = V_47 -> V_75 ? 0 : 1 ;
V_1 -> V_76 = V_47 -> V_77 ? 1 : 0 ;
V_1 -> V_78 = V_47 -> V_79 + 1 ;
V_1 -> V_80 = V_47 -> V_81 << 7 ;
if ( V_1 -> V_80 == V_82 )
V_54 = 18 ;
else if ( V_1 -> V_80 == V_83 )
V_54 = 16 ;
V_1 -> V_84 = V_47 -> V_85 ;
V_1 -> V_86 = V_47 -> V_87 ;
V_1 -> V_88 = V_47 -> V_89 ;
V_1 -> V_90 = V_47 -> V_90 ;
V_1 -> V_91 = V_47 -> V_92 ;
V_1 -> V_93 = V_47 -> V_94 ;
V_1 -> V_95 = V_47 -> V_96 ;
V_1 -> V_97 = V_47 -> V_98 ;
V_1 -> V_99 =
V_47 -> V_100 ? V_101 : 0 ;
V_71 = V_4 -> clock ;
if ( V_1 -> V_86 == V_102 ) {
if ( V_47 -> V_103 ) {
V_72 =
( V_71 * V_54 ) / V_1 -> V_78 ;
if ( V_47 -> V_103 <
V_72 ) {
F_17 ( L_6 ) ;
return false ;
}
V_73 = F_21 (
V_47 -> V_103 * 100 ,
V_72 ) ;
V_71 = F_21 ( V_71 * V_73 , 100 ) ;
} else {
F_17 ( L_7 ) ;
return false ;
}
} else
V_73 = 100 ;
V_1 -> V_73 = V_73 ;
V_1 -> V_71 = V_71 ;
V_57 = ( V_71 * V_54 ) / V_1 -> V_78 ;
switch ( V_1 -> V_88 ) {
case 0 :
V_55 = 50 ;
break;
case 1 :
V_55 = 100 ;
break;
case 2 :
V_55 = 200 ;
break;
default:
V_55 = 50 ;
break;
}
switch ( V_1 -> V_78 ) {
case 1 :
case 2 :
V_56 = 2 ;
break;
case 3 :
V_56 = 4 ;
break;
case 4 :
default:
V_56 = 3 ;
break;
}
V_59 = V_104 ;
V_60 = V_57 ;
V_67 = V_47 -> V_67 ;
V_68 = V_47 -> V_68 ;
V_1 -> V_105 = F_21 ( V_55 * V_60 , 8 * V_59 ) ;
V_65 = F_22 ( V_47 -> V_106 ,
V_47 -> V_107 ) ;
V_61 = F_21 ( V_65 * V_60 , V_59 * 2 ) ;
V_62 = F_21 (
( V_68 - V_65 ) * V_60 ,
V_59 * 2
) ;
if ( V_62 < ( 55 * V_60 / V_59 ) )
if ( ( 55 * V_60 ) % V_59 )
V_62 += 1 ;
V_63 = F_21 (
( V_67 - V_65 )
* V_60 , 2 * V_59 ) ;
V_66 = F_22 ( V_47 -> V_108 , V_47 -> V_109 ) ;
V_64 = F_21 ( V_66 * V_60 , 2 * V_59 ) ;
if ( V_61 > V_110 ||
V_62 > V_111 ||
V_63 > V_112 ||
V_64 > V_113 )
F_5 ( L_8 ) ;
if ( V_61 > V_110 )
V_61 = V_110 ;
if ( V_62 > V_111 )
V_62 = V_111 ;
if ( V_63 > V_112 )
V_63 = V_112 ;
if ( V_64 > V_113 )
V_64 = V_113 ;
V_1 -> V_114 = V_62 << 24 | V_64 << 16 |
V_63 << 8 | V_61 ;
V_58 = F_21 ( V_55 * V_60 , V_59 ) ;
V_69 = F_21 ( 4 * V_58 + V_61 * 2 +
V_62 * 2 + 10 , 8 ) ;
V_70 = F_21 ( V_47 -> V_109 + 2 * V_58 , 8 ) ;
V_1 -> V_115 = F_22 ( V_69 , V_70 ) ;
V_1 -> V_115 += V_56 ;
V_1 -> V_116 =
F_21 (
4 * V_58 + V_61 * 2 +
V_63 * 2 ,
8 ) ;
V_1 -> V_116 += V_56 ;
V_1 -> V_117 =
F_21 ( 2 * V_58 + V_64 * 2 + 8 ,
8 ) ;
V_1 -> V_117 += V_56 ;
F_20 ( L_9 , V_1 -> V_74 ? L_10 : L_11 ) ;
F_20 ( L_12 , V_1 -> V_76 ?
L_11 : L_10 ) ;
F_20 ( L_13 , V_1 -> V_84 ? L_14 : L_15 ) ;
F_20 ( L_16 , V_1 -> V_80 ) ;
F_20 ( L_17 , V_1 -> V_88 ) ;
F_20 ( L_18 , V_1 -> V_90 ) ;
F_20 ( L_19 , V_1 -> V_91 ) ;
F_20 ( L_20 , V_1 -> V_95 ) ;
F_20 ( L_21 , V_1 -> V_115 ) ;
F_20 ( L_22 , V_1 -> V_105 ) ;
F_20 ( L_23 , V_1 -> V_97 ) ;
F_20 ( L_24 , V_1 -> V_116 ) ;
F_20 ( L_25 , V_1 -> V_117 ) ;
F_20 ( L_26 ,
V_1 -> V_99 & V_101 ?
L_11 : L_10 ) ;
V_1 -> V_118 = V_51 -> V_119 / 10 ;
V_1 -> V_120 = V_51 -> V_121 / 10 ;
V_1 -> V_122 = V_51 -> V_122 / 10 ;
V_1 -> V_123 = V_51 -> V_123 / 10 ;
V_1 -> V_124 = V_51 -> V_125 / 10 ;
return true ;
}
static int F_23 ( struct V_45 * V_46 ,
struct V_52 * V_4 )
{
return V_126 ;
}
static bool F_24 ( struct V_45 * V_46 ,
const struct V_52 * V_4 ,
struct V_52 * V_127 ) {
return true ;
}
static void F_25 ( struct V_45 * V_46 )
{
struct V_1 * V_1 = F_19 ( V_46 , struct V_1 , V_30 ) ;
struct V_29 * V_30 = V_1 -> V_31 . V_31 . V_30 ;
struct V_32 * V_33 = V_30 -> V_34 ;
char * V_40 = V_33 -> V_48 . V_46 . V_40 [ V_128 ] ;
F_16 ( V_1 , V_40 ) ;
}
static void F_26 ( struct V_45 * V_46 )
{
struct V_1 * V_1 = F_19 ( V_46 , struct V_1 , V_30 ) ;
struct V_29 * V_30 = V_1 -> V_31 . V_31 . V_30 ;
struct V_32 * V_33 = V_30 -> V_34 ;
char * V_40 = V_33 -> V_48 . V_46 . V_40 [ V_129 ] ;
F_16 ( V_1 , V_40 ) ;
}
static void F_27 ( struct V_45 * V_46 )
{
struct V_1 * V_1 = F_19 ( V_46 , struct V_1 , V_30 ) ;
struct V_29 * V_30 = V_1 -> V_31 . V_31 . V_30 ;
struct V_32 * V_33 = V_30 -> V_34 ;
char * V_40 = V_33 -> V_48 . V_46 . V_40 [ V_130 ] ;
F_16 ( V_1 , V_40 ) ;
}
static void F_28 ( struct V_45 * V_46 )
{
struct V_1 * V_1 = F_19 ( V_46 , struct V_1 , V_30 ) ;
struct V_29 * V_30 = V_1 -> V_31 . V_31 . V_30 ;
struct V_32 * V_33 = V_30 -> V_34 ;
char * V_40 = V_33 -> V_48 . V_46 . V_40 [ V_131 ] ;
F_16 ( V_1 , V_40 ) ;
}
static void F_29 ( struct V_45 * V_46 )
{
struct V_1 * V_1 = F_19 ( V_46 , struct V_1 , V_30 ) ;
struct V_29 * V_30 = V_1 -> V_31 . V_31 . V_30 ;
struct V_32 * V_33 = V_30 -> V_34 ;
char * V_40 = V_33 -> V_48 . V_46 . V_40 [ V_132 ] ;
F_16 ( V_1 , V_40 ) ;
}
static enum V_133 F_30 ( struct V_45 * V_46 )
{
return V_134 ;
}
static bool F_31 ( struct V_45 * V_30 )
{
return true ;
}
static struct V_52 * F_32 ( struct V_45 * V_46 )
{
struct V_1 * V_1 = F_19 ( V_46 , struct V_1 , V_30 ) ;
struct V_29 * V_30 = V_1 -> V_31 . V_31 . V_30 ;
struct V_32 * V_33 = V_30 -> V_34 ;
V_33 -> V_48 . V_53 -> type |= V_135 ;
return V_33 -> V_48 . V_53 ;
}
static void F_33 ( struct V_45 * V_46 ) { }
