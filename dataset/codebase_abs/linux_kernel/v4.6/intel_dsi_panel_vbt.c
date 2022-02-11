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
F_16 ( V_45 , V_55 , V_38 ,
0x2000CC00 ) ;
V_50 [ V_36 ] . V_54 = 1 ;
}
V_40 = 0x4 | V_37 ;
F_16 ( V_45 , V_55 , V_39 , V_40 ) ;
F_17 ( & V_45 -> V_53 ) ;
V_18:
return V_8 ;
}
static const T_1 * F_18 ( struct V_7 * V_7 , const T_1 * V_8 )
{
return V_8 + * ( V_8 + 6 ) + 7 ;
}
static const char * F_19 ( enum V_56 V_57 )
{
if ( V_57 < F_13 ( V_58 ) && V_58 [ V_57 ] )
return V_58 [ V_57 ] ;
else
return L_7 ;
}
static void F_20 ( struct V_2 * V_3 , enum V_56 V_57 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_44 * V_45 = F_21 ( V_7 -> V_43 . V_43 . V_42 ) ;
const T_1 * V_8 ;
T_4 V_59 ;
if ( F_22 ( V_57 >= F_13 ( V_45 -> V_47 . V_48 . V_60 ) ) )
return;
V_8 = V_45 -> V_47 . V_48 . V_60 [ V_57 ] ;
if ( ! V_8 ) {
F_5 ( L_8 ,
V_57 , F_19 ( V_57 ) ) ;
return;
}
F_22 ( * V_8 != V_57 ) ;
F_5 ( L_9 ,
V_57 , F_19 ( V_57 ) ) ;
V_8 ++ ;
if ( V_45 -> V_47 . V_48 . V_49 >= 3 )
V_8 += 4 ;
while ( 1 ) {
T_1 V_61 = * V_8 ++ ;
T_1 V_62 = 0 ;
if ( V_61 == V_63 )
break;
if ( V_61 < F_13 ( V_64 ) )
V_59 = V_64 [ V_61 ] ;
else
V_59 = NULL ;
if ( V_45 -> V_47 . V_48 . V_49 >= 3 )
V_62 = * V_8 ++ ;
if ( V_59 ) {
V_8 = V_59 ( V_7 , V_8 ) ;
} else if ( V_62 ) {
F_5 ( L_10 ,
V_61 ) ;
V_8 += V_62 ;
} else {
F_23 ( L_10 ,
V_61 ) ;
return;
}
}
}
static int F_24 ( struct V_2 * V_3 )
{
F_20 ( V_3 , V_65 ) ;
F_20 ( V_3 , V_66 ) ;
return 0 ;
}
static int F_25 ( struct V_2 * V_3 )
{
F_20 ( V_3 , V_67 ) ;
return 0 ;
}
static int F_26 ( struct V_2 * V_3 )
{
F_20 ( V_3 , V_68 ) ;
return 0 ;
}
static int F_27 ( struct V_2 * V_3 )
{
F_20 ( V_3 , V_69 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_41 * V_42 = V_7 -> V_43 . V_43 . V_42 ;
struct V_44 * V_45 = V_42 -> V_46 ;
struct V_70 * V_71 ;
if ( ! V_3 -> V_72 )
return 0 ;
V_71 = F_29 ( V_42 , V_45 -> V_47 . V_73 ) ;
if ( ! V_71 )
return 0 ;
V_71 -> type |= V_74 ;
F_30 ( V_3 -> V_72 , V_71 ) ;
return 1 ;
}
struct V_2 * F_31 ( struct V_7 * V_7 , T_2 V_75 )
{
struct V_41 * V_42 = V_7 -> V_43 . V_43 . V_42 ;
struct V_44 * V_45 = V_42 -> V_46 ;
struct V_76 * V_76 = V_45 -> V_47 . V_48 . V_77 ;
struct V_78 * V_79 = V_45 -> V_47 . V_48 . V_79 ;
struct V_70 * V_71 = V_45 -> V_47 . V_73 ;
struct V_1 * V_1 ;
T_3 V_80 = 24 ;
T_3 V_81 , V_82 , V_83 , V_84 ;
T_3 V_85 , V_86 ;
T_3 V_87 , V_88 , V_89 , V_90 ;
T_3 V_91 , V_92 ;
T_3 V_93 , V_94 ;
T_3 V_95 , V_96 ;
T_3 V_97 , V_98 ;
T_2 V_99 ;
enum V_4 V_4 ;
F_5 ( L_11 ) ;
V_7 -> V_100 = V_76 -> V_101 ? 0 : 1 ;
V_7 -> V_102 = V_76 -> V_103 ? 1 : 0 ;
V_7 -> V_104 = V_76 -> V_105 + 1 ;
V_7 -> V_106 = V_76 -> V_107 << 7 ;
V_7 -> V_108 = V_76 -> V_108 ;
V_7 -> V_109 = V_76 -> V_109 ;
V_80 = F_32 ( V_7 -> V_106 ) ;
V_7 -> V_110 = V_76 -> V_111 ;
V_7 -> V_112 = V_76 -> V_113 ;
V_7 -> V_114 = V_76 -> V_115 ;
V_7 -> V_116 = V_76 -> V_116 ;
V_7 -> V_117 = V_76 -> V_118 ;
V_7 -> V_119 = V_76 -> V_120 ;
V_7 -> V_121 = V_76 -> V_122 ;
V_7 -> V_123 = V_76 -> V_124 ;
V_7 -> V_125 =
V_76 -> V_126 ? V_127 : 0 ;
V_97 = V_71 -> clock ;
if ( V_7 -> V_108 ) {
V_97 = V_97 / 2 ;
if ( V_7 -> V_108 == V_128 ) {
V_97 += F_33 ( V_71 -> V_129 *
V_7 -> V_109 *
60 , 1000 ) ;
}
}
if ( V_7 -> V_112 == V_130 ) {
if ( V_76 -> V_131 ) {
V_98 =
( V_97 * V_80 ) / V_7 -> V_104 ;
if ( V_76 -> V_131 <
V_98 ) {
F_23 ( L_12 ) ;
return NULL ;
}
V_99 = F_33 (
V_76 -> V_131 * 100 ,
V_98 ) ;
V_97 = F_33 ( V_97 * V_99 , 100 ) ;
} else {
F_23 ( L_13 ) ;
return NULL ;
}
} else
V_99 = 100 ;
V_7 -> V_99 = V_99 ;
V_7 -> V_97 = V_97 ;
V_83 = ( V_97 * V_80 ) / V_7 -> V_104 ;
switch ( V_7 -> V_114 ) {
case 0 :
V_81 = 50 ;
break;
case 1 :
V_81 = 100 ;
break;
case 2 :
V_81 = 200 ;
break;
default:
V_81 = 50 ;
break;
}
switch ( V_7 -> V_104 ) {
case 1 :
case 2 :
V_82 = 2 ;
break;
case 3 :
V_82 = 4 ;
break;
case 4 :
default:
V_82 = 3 ;
break;
}
V_85 = V_132 ;
V_86 = V_83 ;
V_93 = V_76 -> V_93 ;
V_94 = V_76 -> V_94 ;
V_7 -> V_133 = F_33 ( V_81 * V_86 , 8 * V_85 ) ;
V_91 = F_34 ( V_76 -> V_134 ,
V_76 -> V_135 ) ;
V_87 = F_33 ( V_91 * V_86 , V_85 * 2 ) ;
V_88 = F_33 (
( V_94 - V_91 ) * V_86 ,
V_85 * 2
) ;
if ( V_88 < ( 55 * V_86 / V_85 ) )
if ( ( 55 * V_86 ) % V_85 )
V_88 += 1 ;
V_89 = F_33 (
( V_93 - V_91 )
* V_86 , 2 * V_85 ) ;
V_92 = F_34 ( V_76 -> V_136 , V_76 -> V_137 ) ;
V_90 = F_33 ( V_92 * V_86 , 2 * V_85 ) ;
if ( V_87 > V_138 ||
V_88 > V_139 ||
V_89 > V_140 ||
V_90 > V_141 )
F_8 ( L_14 ) ;
if ( V_87 > V_138 )
V_87 = V_138 ;
if ( V_88 > V_139 )
V_88 = V_139 ;
if ( V_89 > V_140 )
V_89 = V_140 ;
if ( V_90 > V_141 )
V_90 = V_141 ;
V_7 -> V_142 = V_88 << 24 | V_90 << 16 |
V_89 << 8 | V_87 ;
V_84 = F_33 ( V_81 * V_86 , V_85 ) ;
V_95 = F_33 ( 4 * V_84 + V_87 * 2 +
V_88 * 2 + 10 , 8 ) ;
V_96 = F_33 ( V_76 -> V_137 + 2 * V_84 , 8 ) ;
V_7 -> V_143 = F_34 ( V_95 , V_96 ) ;
V_7 -> V_143 += V_82 ;
V_7 -> V_144 =
F_33 (
4 * V_84 + V_87 * 2 +
V_89 * 2 ,
8 ) ;
V_7 -> V_144 += V_82 ;
V_7 -> V_145 =
F_33 ( 2 * V_84 + V_90 * 2 + 8 ,
8 ) ;
V_7 -> V_145 += V_82 ;
F_5 ( L_15 , V_7 -> V_100 ? L_16 : L_17 ) ;
F_5 ( L_18 , V_7 -> V_102 ?
L_17 : L_16 ) ;
F_5 ( L_19 , V_7 -> V_110 ? L_20 : L_21 ) ;
if ( V_7 -> V_108 == V_128 )
F_5 ( L_22 ) ;
else if ( V_7 -> V_108 == V_146 )
F_5 ( L_23 ) ;
else
F_5 ( L_24 ) ;
F_5 ( L_25 , V_7 -> V_106 ) ;
F_5 ( L_26 , V_7 -> V_114 ) ;
F_5 ( L_27 , V_7 -> V_116 ) ;
F_5 ( L_28 , V_7 -> V_117 ) ;
F_5 ( L_29 , V_7 -> V_121 ) ;
F_5 ( L_30 , V_7 -> V_143 ) ;
F_5 ( L_31 , V_7 -> V_133 ) ;
F_5 ( L_32 , V_7 -> V_123 ) ;
F_5 ( L_33 , V_7 -> V_144 ) ;
F_5 ( L_34 , V_7 -> V_145 ) ;
F_5 ( L_35 ,
V_7 -> V_125 & V_127 ?
L_17 : L_16 ) ;
V_7 -> V_147 = V_79 -> V_148 / 10 ;
V_7 -> V_149 = V_79 -> V_150 / 10 ;
V_7 -> V_151 = V_79 -> V_151 / 10 ;
V_7 -> V_152 = V_79 -> V_152 / 10 ;
V_7 -> V_153 = V_79 -> V_154 / 10 ;
V_1 = F_35 ( V_42 -> V_42 , sizeof( * V_1 ) , V_155 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_7 = V_7 ;
F_36 ( & V_1 -> V_3 ) ;
V_1 -> V_3 . V_156 = & V_157 ;
F_37 ( & V_1 -> V_3 ) ;
F_38 (port, intel_dsi->ports) {
F_39 ( V_7 -> V_16 [ V_4 ] -> V_17 ) ;
}
return & V_1 -> V_3 ;
}
