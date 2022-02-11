static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline enum V_4 F_3 ( T_1 V_4 )
{
return V_4 ? V_5 : V_6 ;
}
static const T_1 * F_4 ( struct V_7 * V_7 ,
const T_1 * V_8 )
{
struct V_9 * V_10 ;
T_1 type , V_11 , V_12 ;
T_2 V_13 ;
enum V_4 V_4 ;
V_11 = * V_8 ++ ;
type = * V_8 ++ ;
V_13 = * ( ( T_2 * ) V_8 ) ;
V_8 += 2 ;
V_12 = ( V_11 >> V_14 ) & 3 ;
if ( V_7 -> V_15 == ( 1 << V_5 ) )
V_4 = V_5 ;
else
V_4 = F_3 ( V_12 ) ;
V_10 = V_7 -> V_16 [ V_4 ] -> V_17 ;
if ( ! V_10 ) {
F_5 ( L_1 , F_6 ( V_4 ) ) ;
goto V_18;
}
if ( ( V_11 >> V_19 ) & 1 )
V_10 -> V_20 &= ~ V_21 ;
else
V_10 -> V_20 |= V_21 ;
V_10 -> V_22 = ( V_11 >> V_23 ) & 3 ;
switch ( type ) {
case V_24 :
F_7 ( V_10 , NULL , 0 ) ;
break;
case V_25 :
F_7 ( V_10 , V_8 , 1 ) ;
break;
case V_26 :
F_7 ( V_10 , V_8 , 2 ) ;
break;
case V_27 :
case V_28 :
case V_29 :
F_8 ( L_2 ) ;
break;
case V_30 :
F_7 ( V_10 , V_8 , V_13 ) ;
break;
case V_31 :
F_9 ( V_10 , V_8 , 1 ) ;
break;
case V_32 :
F_9 ( V_10 , V_8 , 2 ) ;
break;
case V_33 :
F_8 ( L_3 ) ;
break;
case V_34 :
F_9 ( V_10 , V_8 , V_13 ) ;
break;
}
V_18:
V_8 += V_13 ;
return V_8 ;
}
static const T_1 * F_10 ( struct V_7 * V_7 , const T_1 * V_8 )
{
T_3 V_35 = * ( ( const T_3 * ) V_8 ) ;
F_11 ( V_35 , V_35 + 10 ) ;
V_8 += 4 ;
return V_8 ;
}
static const T_1 * F_12 ( struct V_7 * V_7 , const T_1 * V_8 )
{
T_1 V_36 , V_37 ;
T_2 V_38 , V_39 ;
T_3 V_40 ;
struct V_41 * V_42 = V_7 -> V_43 . V_43 . V_42 ;
struct V_44 * V_45 = V_42 -> V_46 ;
if ( V_45 -> V_47 . V_48 . V_49 >= 3 )
V_8 ++ ;
V_36 = * V_8 ++ ;
V_37 = * V_8 ++ & 1 ;
if ( V_36 >= F_13 ( V_50 ) ) {
F_5 ( L_4 , V_36 ) ;
goto V_18;
}
if ( ! F_14 ( V_45 ) ) {
F_5 ( L_5 ) ;
goto V_18;
}
if ( V_45 -> V_47 . V_48 . V_49 >= 3 ) {
F_5 ( L_6 ) ;
goto V_18;
}
V_38 = V_50 [ V_36 ] . V_51 ;
V_39 = V_50 [ V_36 ] . V_52 ;
F_15 ( & V_45 -> V_53 ) ;
if ( ! V_50 [ V_36 ] . V_54 ) {
F_16 ( V_45 , V_38 , 0x2000CC00 ) ;
V_50 [ V_36 ] . V_54 = 1 ;
}
V_40 = 0x4 | V_37 ;
F_16 ( V_45 , V_39 , V_40 ) ;
F_17 ( & V_45 -> V_53 ) ;
V_18:
return V_8 ;
}
static void F_18 ( struct V_7 * V_7 , const T_1 * V_8 )
{
T_4 V_55 ;
int V_56 ;
if ( ! V_8 )
return;
F_8 ( L_7 , V_57 [ * V_8 ] ) ;
V_8 ++ ;
while ( 1 ) {
V_56 = * V_8 ;
V_55 = V_58 [ V_56 ] ;
if ( ! V_55 ) {
F_19 ( L_8 ) ;
return;
}
V_8 ++ ;
V_8 = V_55 ( V_7 , V_8 ) ;
if ( * V_8 == 0x00 )
break;
}
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_41 * V_42 = V_7 -> V_43 . V_43 . V_42 ;
struct V_44 * V_45 = V_42 -> V_46 ;
const T_1 * V_59 ;
V_59 = V_45 -> V_47 . V_48 . V_59 [ V_60 ] ;
F_18 ( V_7 , V_59 ) ;
V_59 = V_45 -> V_47 . V_48 . V_59 [ V_61 ] ;
F_18 ( V_7 , V_59 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_41 * V_42 = V_7 -> V_43 . V_43 . V_42 ;
struct V_44 * V_45 = V_42 -> V_46 ;
const T_1 * V_59 ;
V_59 = V_45 -> V_47 . V_48 . V_59 [ V_62 ] ;
F_18 ( V_7 , V_59 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_41 * V_42 = V_7 -> V_43 . V_43 . V_42 ;
struct V_44 * V_45 = V_42 -> V_46 ;
const T_1 * V_59 ;
V_59 = V_45 -> V_47 . V_48 . V_59 [ V_63 ] ;
F_18 ( V_7 , V_59 ) ;
return 0 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_41 * V_42 = V_7 -> V_43 . V_43 . V_42 ;
struct V_44 * V_45 = V_42 -> V_46 ;
const T_1 * V_59 ;
V_59 = V_45 -> V_47 . V_48 . V_59 [ V_64 ] ;
F_18 ( V_7 , V_59 ) ;
return 0 ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_41 * V_42 = V_7 -> V_43 . V_43 . V_42 ;
struct V_44 * V_45 = V_42 -> V_46 ;
struct V_65 * V_66 ;
if ( ! V_3 -> V_67 )
return 0 ;
V_66 = F_25 ( V_42 , V_45 -> V_47 . V_68 ) ;
if ( ! V_66 )
return 0 ;
V_66 -> type |= V_69 ;
F_26 ( V_3 -> V_67 , V_66 ) ;
return 1 ;
}
struct V_2 * F_27 ( struct V_7 * V_7 , T_2 V_70 )
{
struct V_41 * V_42 = V_7 -> V_43 . V_43 . V_42 ;
struct V_44 * V_45 = V_42 -> V_46 ;
struct V_71 * V_71 = V_45 -> V_47 . V_48 . V_72 ;
struct V_73 * V_74 = V_45 -> V_47 . V_48 . V_74 ;
struct V_65 * V_66 = V_45 -> V_47 . V_68 ;
struct V_1 * V_1 ;
T_3 V_75 = 24 ;
T_3 V_76 , V_77 , V_78 , V_79 ;
T_3 V_80 , V_81 ;
T_3 V_82 , V_83 , V_84 , V_85 ;
T_3 V_86 , V_87 ;
T_3 V_88 , V_89 ;
T_3 V_90 , V_91 ;
T_3 V_92 , V_93 ;
T_2 V_94 ;
enum V_4 V_4 ;
F_5 ( L_9 ) ;
V_7 -> V_95 = V_71 -> V_96 ? 0 : 1 ;
V_7 -> V_97 = V_71 -> V_98 ? 1 : 0 ;
V_7 -> V_99 = V_71 -> V_100 + 1 ;
V_7 -> V_101 = V_71 -> V_102 << 7 ;
V_7 -> V_103 = V_71 -> V_103 ;
V_7 -> V_104 = V_71 -> V_104 ;
if ( V_7 -> V_101 == V_105 )
V_75 = 18 ;
else if ( V_7 -> V_101 == V_106 )
V_75 = 16 ;
V_7 -> V_107 = V_71 -> V_108 ;
V_7 -> V_109 = V_71 -> V_110 ;
V_7 -> V_111 = V_71 -> V_112 ;
V_7 -> V_113 = V_71 -> V_113 ;
V_7 -> V_114 = V_71 -> V_115 ;
V_7 -> V_116 = V_71 -> V_117 ;
V_7 -> V_118 = V_71 -> V_119 ;
V_7 -> V_120 = V_71 -> V_121 ;
V_7 -> V_122 =
V_71 -> V_123 ? V_124 : 0 ;
V_92 = V_66 -> clock ;
if ( V_7 -> V_103 ) {
V_92 = V_92 / 2 ;
if ( V_7 -> V_103 == V_125 ) {
V_92 += F_28 ( V_66 -> V_126 *
V_7 -> V_104 *
60 , 1000 ) ;
}
}
if ( V_7 -> V_109 == V_127 ) {
if ( V_71 -> V_128 ) {
V_93 =
( V_92 * V_75 ) / V_7 -> V_99 ;
if ( V_71 -> V_128 <
V_93 ) {
F_19 ( L_10 ) ;
return NULL ;
}
V_94 = F_28 (
V_71 -> V_128 * 100 ,
V_93 ) ;
V_92 = F_28 ( V_92 * V_94 , 100 ) ;
} else {
F_19 ( L_11 ) ;
return NULL ;
}
} else
V_94 = 100 ;
V_7 -> V_94 = V_94 ;
V_7 -> V_92 = V_92 ;
V_78 = ( V_92 * V_75 ) / V_7 -> V_99 ;
switch ( V_7 -> V_111 ) {
case 0 :
V_76 = 50 ;
break;
case 1 :
V_76 = 100 ;
break;
case 2 :
V_76 = 200 ;
break;
default:
V_76 = 50 ;
break;
}
switch ( V_7 -> V_99 ) {
case 1 :
case 2 :
V_77 = 2 ;
break;
case 3 :
V_77 = 4 ;
break;
case 4 :
default:
V_77 = 3 ;
break;
}
V_80 = V_129 ;
V_81 = V_78 ;
V_88 = V_71 -> V_88 ;
V_89 = V_71 -> V_89 ;
V_7 -> V_130 = F_28 ( V_76 * V_81 , 8 * V_80 ) ;
V_86 = F_29 ( V_71 -> V_131 ,
V_71 -> V_132 ) ;
V_82 = F_28 ( V_86 * V_81 , V_80 * 2 ) ;
V_83 = F_28 (
( V_89 - V_86 ) * V_81 ,
V_80 * 2
) ;
if ( V_83 < ( 55 * V_81 / V_80 ) )
if ( ( 55 * V_81 ) % V_80 )
V_83 += 1 ;
V_84 = F_28 (
( V_88 - V_86 )
* V_81 , 2 * V_80 ) ;
V_87 = F_29 ( V_71 -> V_133 , V_71 -> V_134 ) ;
V_85 = F_28 ( V_87 * V_81 , 2 * V_80 ) ;
if ( V_82 > V_135 ||
V_83 > V_136 ||
V_84 > V_137 ||
V_85 > V_138 )
F_8 ( L_12 ) ;
if ( V_82 > V_135 )
V_82 = V_135 ;
if ( V_83 > V_136 )
V_83 = V_136 ;
if ( V_84 > V_137 )
V_84 = V_137 ;
if ( V_85 > V_138 )
V_85 = V_138 ;
V_7 -> V_139 = V_83 << 24 | V_85 << 16 |
V_84 << 8 | V_82 ;
V_79 = F_28 ( V_76 * V_81 , V_80 ) ;
V_90 = F_28 ( 4 * V_79 + V_82 * 2 +
V_83 * 2 + 10 , 8 ) ;
V_91 = F_28 ( V_71 -> V_134 + 2 * V_79 , 8 ) ;
V_7 -> V_140 = F_29 ( V_90 , V_91 ) ;
V_7 -> V_140 += V_77 ;
V_7 -> V_141 =
F_28 (
4 * V_79 + V_82 * 2 +
V_84 * 2 ,
8 ) ;
V_7 -> V_141 += V_77 ;
V_7 -> V_142 =
F_28 ( 2 * V_79 + V_85 * 2 + 8 ,
8 ) ;
V_7 -> V_142 += V_77 ;
F_5 ( L_13 , V_7 -> V_95 ? L_14 : L_15 ) ;
F_5 ( L_16 , V_7 -> V_97 ?
L_15 : L_14 ) ;
F_5 ( L_17 , V_7 -> V_107 ? L_18 : L_19 ) ;
if ( V_7 -> V_103 == V_125 )
F_5 ( L_20 ) ;
else if ( V_7 -> V_103 == V_143 )
F_5 ( L_21 ) ;
else
F_5 ( L_22 ) ;
F_5 ( L_23 , V_7 -> V_101 ) ;
F_5 ( L_24 , V_7 -> V_111 ) ;
F_5 ( L_25 , V_7 -> V_113 ) ;
F_5 ( L_26 , V_7 -> V_114 ) ;
F_5 ( L_27 , V_7 -> V_118 ) ;
F_5 ( L_28 , V_7 -> V_140 ) ;
F_5 ( L_29 , V_7 -> V_130 ) ;
F_5 ( L_30 , V_7 -> V_120 ) ;
F_5 ( L_31 , V_7 -> V_141 ) ;
F_5 ( L_32 , V_7 -> V_142 ) ;
F_5 ( L_33 ,
V_7 -> V_122 & V_124 ?
L_15 : L_14 ) ;
V_7 -> V_144 = V_74 -> V_145 / 10 ;
V_7 -> V_146 = V_74 -> V_147 / 10 ;
V_7 -> V_148 = V_74 -> V_148 / 10 ;
V_7 -> V_149 = V_74 -> V_149 / 10 ;
V_7 -> V_150 = V_74 -> V_151 / 10 ;
V_1 = F_30 ( V_42 -> V_42 , sizeof( * V_1 ) , V_152 ) ;
V_1 -> V_7 = V_7 ;
F_31 ( & V_1 -> V_3 ) ;
V_1 -> V_3 . V_153 = & V_154 ;
F_32 ( & V_1 -> V_3 ) ;
F_33 (port, intel_dsi->ports) {
F_34 ( V_7 -> V_16 [ V_4 ] -> V_17 ) ;
}
return & V_1 -> V_3 ;
}
