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
V_36 = * V_8 ++ ;
V_37 = * V_8 ++ ;
V_38 = V_47 [ V_36 ] . V_48 ;
V_39 = V_47 [ V_36 ] . V_49 ;
F_13 ( & V_45 -> V_50 ) ;
if ( ! V_47 [ V_36 ] . V_51 ) {
F_14 ( V_45 , V_38 , 0x2000CC00 ) ;
V_47 [ V_36 ] . V_51 = 1 ;
}
V_40 = 0x4 | V_37 ;
F_14 ( V_45 , V_39 , V_40 ) ;
F_15 ( & V_45 -> V_50 ) ;
return V_8 ;
}
static void F_16 ( struct V_7 * V_7 , const T_1 * V_8 )
{
T_4 V_52 ;
int V_53 ;
if ( ! V_8 )
return;
F_8 ( L_4 , V_54 [ * V_8 ] ) ;
V_8 ++ ;
while ( 1 ) {
V_53 = * V_8 ;
V_52 = V_55 [ V_53 ] ;
if ( ! V_52 ) {
F_17 ( L_5 ) ;
return;
}
V_8 ++ ;
V_8 = V_52 ( V_7 , V_8 ) ;
if ( * V_8 == 0x00 )
break;
}
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_41 * V_42 = V_7 -> V_43 . V_43 . V_42 ;
struct V_44 * V_45 = V_42 -> V_46 ;
const T_1 * V_56 ;
V_56 = V_45 -> V_57 . V_58 . V_56 [ V_59 ] ;
F_16 ( V_7 , V_56 ) ;
V_56 = V_45 -> V_57 . V_58 . V_56 [ V_60 ] ;
F_16 ( V_7 , V_56 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_41 * V_42 = V_7 -> V_43 . V_43 . V_42 ;
struct V_44 * V_45 = V_42 -> V_46 ;
const T_1 * V_56 ;
V_56 = V_45 -> V_57 . V_58 . V_56 [ V_61 ] ;
F_16 ( V_7 , V_56 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_41 * V_42 = V_7 -> V_43 . V_43 . V_42 ;
struct V_44 * V_45 = V_42 -> V_46 ;
const T_1 * V_56 ;
V_56 = V_45 -> V_57 . V_58 . V_56 [ V_62 ] ;
F_16 ( V_7 , V_56 ) ;
return 0 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_41 * V_42 = V_7 -> V_43 . V_43 . V_42 ;
struct V_44 * V_45 = V_42 -> V_46 ;
const T_1 * V_56 ;
V_56 = V_45 -> V_57 . V_58 . V_56 [ V_63 ] ;
F_16 ( V_7 , V_56 ) ;
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_41 * V_42 = V_7 -> V_43 . V_43 . V_42 ;
struct V_44 * V_45 = V_42 -> V_46 ;
struct V_64 * V_65 ;
if ( ! V_3 -> V_66 )
return 0 ;
V_65 = F_23 ( V_42 , V_45 -> V_57 . V_67 ) ;
if ( ! V_65 )
return 0 ;
V_65 -> type |= V_68 ;
F_24 ( V_3 -> V_66 , V_65 ) ;
return 1 ;
}
struct V_2 * F_25 ( struct V_7 * V_7 , T_2 V_69 )
{
struct V_41 * V_42 = V_7 -> V_43 . V_43 . V_42 ;
struct V_44 * V_45 = V_42 -> V_46 ;
struct V_70 * V_70 = V_45 -> V_57 . V_58 . V_71 ;
struct V_72 * V_73 = V_45 -> V_57 . V_58 . V_73 ;
struct V_64 * V_65 = V_45 -> V_57 . V_67 ;
struct V_1 * V_1 ;
T_3 V_74 = 24 ;
T_3 V_75 , V_76 , V_77 , V_78 ;
T_3 V_79 , V_80 ;
T_3 V_81 , V_82 , V_83 , V_84 ;
T_3 V_85 , V_86 ;
T_3 V_87 , V_88 ;
T_3 V_89 , V_90 ;
T_3 V_91 , V_92 ;
T_2 V_93 ;
enum V_4 V_4 ;
F_5 ( L_6 ) ;
V_7 -> V_94 = V_70 -> V_95 ? 0 : 1 ;
V_7 -> V_96 = V_70 -> V_97 ? 1 : 0 ;
V_7 -> V_98 = V_70 -> V_99 + 1 ;
V_7 -> V_100 = V_70 -> V_101 << 7 ;
V_7 -> V_102 = V_70 -> V_102 ;
V_7 -> V_103 = V_70 -> V_103 ;
if ( V_7 -> V_100 == V_104 )
V_74 = 18 ;
else if ( V_7 -> V_100 == V_105 )
V_74 = 16 ;
V_7 -> V_106 = V_70 -> V_107 ;
V_7 -> V_108 = V_70 -> V_109 ;
V_7 -> V_110 = V_70 -> V_111 ;
V_7 -> V_112 = V_70 -> V_112 ;
V_7 -> V_113 = V_70 -> V_114 ;
V_7 -> V_115 = V_70 -> V_116 ;
V_7 -> V_117 = V_70 -> V_118 ;
V_7 -> V_119 = V_70 -> V_120 ;
V_7 -> V_121 =
V_70 -> V_122 ? V_123 : 0 ;
V_91 = V_65 -> clock ;
if ( V_7 -> V_102 ) {
V_91 = V_91 / 2 ;
if ( V_7 -> V_102 == V_124 ) {
V_91 += F_26 ( V_65 -> V_125 *
V_7 -> V_103 *
60 , 1000 ) ;
}
}
if ( V_7 -> V_108 == V_126 ) {
if ( V_70 -> V_127 ) {
V_92 =
( V_91 * V_74 ) / V_7 -> V_98 ;
if ( V_70 -> V_127 <
V_92 ) {
F_17 ( L_7 ) ;
return NULL ;
}
V_93 = F_26 (
V_70 -> V_127 * 100 ,
V_92 ) ;
V_91 = F_26 ( V_91 * V_93 , 100 ) ;
} else {
F_17 ( L_8 ) ;
return NULL ;
}
} else
V_93 = 100 ;
V_7 -> V_93 = V_93 ;
V_7 -> V_91 = V_91 ;
V_77 = ( V_91 * V_74 ) / V_7 -> V_98 ;
switch ( V_7 -> V_110 ) {
case 0 :
V_75 = 50 ;
break;
case 1 :
V_75 = 100 ;
break;
case 2 :
V_75 = 200 ;
break;
default:
V_75 = 50 ;
break;
}
switch ( V_7 -> V_98 ) {
case 1 :
case 2 :
V_76 = 2 ;
break;
case 3 :
V_76 = 4 ;
break;
case 4 :
default:
V_76 = 3 ;
break;
}
V_79 = V_128 ;
V_80 = V_77 ;
V_87 = V_70 -> V_87 ;
V_88 = V_70 -> V_88 ;
V_7 -> V_129 = F_26 ( V_75 * V_80 , 8 * V_79 ) ;
V_85 = F_27 ( V_70 -> V_130 ,
V_70 -> V_131 ) ;
V_81 = F_26 ( V_85 * V_80 , V_79 * 2 ) ;
V_82 = F_26 (
( V_88 - V_85 ) * V_80 ,
V_79 * 2
) ;
if ( V_82 < ( 55 * V_80 / V_79 ) )
if ( ( 55 * V_80 ) % V_79 )
V_82 += 1 ;
V_83 = F_26 (
( V_87 - V_85 )
* V_80 , 2 * V_79 ) ;
V_86 = F_27 ( V_70 -> V_132 , V_70 -> V_133 ) ;
V_84 = F_26 ( V_86 * V_80 , 2 * V_79 ) ;
if ( V_81 > V_134 ||
V_82 > V_135 ||
V_83 > V_136 ||
V_84 > V_137 )
F_8 ( L_9 ) ;
if ( V_81 > V_134 )
V_81 = V_134 ;
if ( V_82 > V_135 )
V_82 = V_135 ;
if ( V_83 > V_136 )
V_83 = V_136 ;
if ( V_84 > V_137 )
V_84 = V_137 ;
V_7 -> V_138 = V_82 << 24 | V_84 << 16 |
V_83 << 8 | V_81 ;
V_78 = F_26 ( V_75 * V_80 , V_79 ) ;
V_89 = F_26 ( 4 * V_78 + V_81 * 2 +
V_82 * 2 + 10 , 8 ) ;
V_90 = F_26 ( V_70 -> V_133 + 2 * V_78 , 8 ) ;
V_7 -> V_139 = F_27 ( V_89 , V_90 ) ;
V_7 -> V_139 += V_76 ;
V_7 -> V_140 =
F_26 (
4 * V_78 + V_81 * 2 +
V_83 * 2 ,
8 ) ;
V_7 -> V_140 += V_76 ;
V_7 -> V_141 =
F_26 ( 2 * V_78 + V_84 * 2 + 8 ,
8 ) ;
V_7 -> V_141 += V_76 ;
F_5 ( L_10 , V_7 -> V_94 ? L_11 : L_12 ) ;
F_5 ( L_13 , V_7 -> V_96 ?
L_12 : L_11 ) ;
F_5 ( L_14 , V_7 -> V_106 ? L_15 : L_16 ) ;
if ( V_7 -> V_102 == V_124 )
F_5 ( L_17 ) ;
else if ( V_7 -> V_102 == V_142 )
F_5 ( L_18 ) ;
else
F_5 ( L_19 ) ;
F_5 ( L_20 , V_7 -> V_100 ) ;
F_5 ( L_21 , V_7 -> V_110 ) ;
F_5 ( L_22 , V_7 -> V_112 ) ;
F_5 ( L_23 , V_7 -> V_113 ) ;
F_5 ( L_24 , V_7 -> V_117 ) ;
F_5 ( L_25 , V_7 -> V_139 ) ;
F_5 ( L_26 , V_7 -> V_129 ) ;
F_5 ( L_27 , V_7 -> V_119 ) ;
F_5 ( L_28 , V_7 -> V_140 ) ;
F_5 ( L_29 , V_7 -> V_141 ) ;
F_5 ( L_30 ,
V_7 -> V_121 & V_123 ?
L_12 : L_11 ) ;
V_7 -> V_143 = V_73 -> V_144 / 10 ;
V_7 -> V_145 = V_73 -> V_146 / 10 ;
V_7 -> V_147 = V_73 -> V_147 / 10 ;
V_7 -> V_148 = V_73 -> V_148 / 10 ;
V_7 -> V_149 = V_73 -> V_150 / 10 ;
V_1 = F_28 ( V_42 -> V_42 , sizeof( * V_1 ) , V_151 ) ;
V_1 -> V_7 = V_7 ;
F_29 ( & V_1 -> V_3 ) ;
V_1 -> V_3 . V_152 = & V_153 ;
F_30 ( & V_1 -> V_3 ) ;
F_31 (port, intel_dsi->ports) {
F_32 ( V_7 -> V_16 [ V_4 ] -> V_17 ) ;
}
return & V_1 -> V_3 ;
}
