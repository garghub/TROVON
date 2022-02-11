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
static void F_12 ( struct V_36 * V_37 ,
T_1 V_38 , T_1 V_39 , bool V_40 )
{
struct V_41 * V_42 ;
T_2 V_43 , V_44 ;
T_3 V_45 ;
T_1 V_4 ;
if ( V_39 >= F_13 ( V_46 ) ) {
F_5 ( L_4 , V_39 ) ;
return;
}
V_42 = & V_46 [ V_39 ] ;
if ( V_37 -> V_47 . V_48 . V_49 >= 3 ) {
F_5 ( L_5 ) ;
return;
} else {
if ( V_38 == 0 ) {
V_4 = V_50 ;
} else if ( V_38 == 1 ) {
V_4 = V_51 ;
} else {
F_5 ( L_6 , V_38 ) ;
return;
}
}
V_43 = F_14 ( V_42 -> V_52 ) ;
V_44 = F_15 ( V_42 -> V_52 ) ;
F_16 ( & V_37 -> V_53 ) ;
if ( ! V_42 -> V_54 ) {
F_17 ( V_37 , V_4 , V_43 , 0x2000CC00 ) ;
V_42 -> V_54 = true ;
}
V_45 = 0x4 | V_40 ;
F_17 ( V_37 , V_4 , V_44 , V_45 ) ;
F_18 ( & V_37 -> V_53 ) ;
}
static const T_1 * F_19 ( struct V_7 * V_7 , const T_1 * V_8 )
{
struct V_55 * V_56 = V_7 -> V_57 . V_57 . V_56 ;
struct V_36 * V_37 = V_56 -> V_58 ;
T_1 V_38 , V_39 ;
bool V_40 ;
if ( V_37 -> V_47 . V_48 . V_49 >= 3 )
V_8 ++ ;
V_39 = * V_8 ++ ;
if ( V_37 -> V_47 . V_48 . V_49 == 2 )
V_38 = ( * V_8 >> 1 ) & 3 ;
else
V_38 = 0 ;
V_40 = * V_8 ++ & 1 ;
if ( F_20 ( V_37 ) )
F_12 ( V_37 , V_38 , V_39 , V_40 ) ;
else
F_5 ( L_7 ) ;
return V_8 ;
}
static const T_1 * F_21 ( struct V_7 * V_7 , const T_1 * V_8 )
{
return V_8 + * ( V_8 + 6 ) + 7 ;
}
static const char * F_22 ( enum V_59 V_60 )
{
if ( V_60 < F_13 ( V_61 ) && V_61 [ V_60 ] )
return V_61 [ V_60 ] ;
else
return L_8 ;
}
static void F_23 ( struct V_2 * V_3 , enum V_59 V_60 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_36 * V_37 = F_24 ( V_7 -> V_57 . V_57 . V_56 ) ;
const T_1 * V_8 ;
T_4 V_62 ;
if ( F_25 ( V_60 >= F_13 ( V_37 -> V_47 . V_48 . V_63 ) ) )
return;
V_8 = V_37 -> V_47 . V_48 . V_63 [ V_60 ] ;
if ( ! V_8 ) {
F_5 ( L_9 ,
V_60 , F_22 ( V_60 ) ) ;
return;
}
F_25 ( * V_8 != V_60 ) ;
F_5 ( L_10 ,
V_60 , F_22 ( V_60 ) ) ;
V_8 ++ ;
if ( V_37 -> V_47 . V_48 . V_49 >= 3 )
V_8 += 4 ;
while ( 1 ) {
T_1 V_64 = * V_8 ++ ;
T_1 V_65 = 0 ;
if ( V_64 == V_66 )
break;
if ( V_64 < F_13 ( V_67 ) )
V_62 = V_67 [ V_64 ] ;
else
V_62 = NULL ;
if ( V_37 -> V_47 . V_48 . V_49 >= 3 )
V_65 = * V_8 ++ ;
if ( V_62 ) {
V_8 = V_62 ( V_7 , V_8 ) ;
} else if ( V_65 ) {
F_5 ( L_11 ,
V_64 ) ;
V_8 += V_65 ;
} else {
F_26 ( L_11 ,
V_64 ) ;
return;
}
}
}
static int F_27 ( struct V_2 * V_3 )
{
F_23 ( V_3 , V_68 ) ;
F_23 ( V_3 , V_69 ) ;
return 0 ;
}
static int F_28 ( struct V_2 * V_3 )
{
F_23 ( V_3 , V_70 ) ;
return 0 ;
}
static int F_29 ( struct V_2 * V_3 )
{
F_23 ( V_3 , V_71 ) ;
return 0 ;
}
static int F_30 ( struct V_2 * V_3 )
{
F_23 ( V_3 , V_72 ) ;
return 0 ;
}
static int F_31 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_55 * V_56 = V_7 -> V_57 . V_57 . V_56 ;
struct V_36 * V_37 = V_56 -> V_58 ;
struct V_73 * V_74 ;
if ( ! V_3 -> V_75 )
return 0 ;
V_74 = F_32 ( V_56 , V_37 -> V_47 . V_76 ) ;
if ( ! V_74 )
return 0 ;
V_74 -> type |= V_77 ;
F_33 ( V_3 -> V_75 , V_74 ) ;
return 1 ;
}
struct V_2 * F_34 ( struct V_7 * V_7 , T_2 V_78 )
{
struct V_55 * V_56 = V_7 -> V_57 . V_57 . V_56 ;
struct V_36 * V_37 = V_56 -> V_58 ;
struct V_79 * V_79 = V_37 -> V_47 . V_48 . V_80 ;
struct V_81 * V_82 = V_37 -> V_47 . V_48 . V_82 ;
struct V_73 * V_74 = V_37 -> V_47 . V_76 ;
struct V_1 * V_1 ;
T_3 V_83 ;
T_3 V_84 , V_85 , V_86 , V_87 ;
T_3 V_88 , V_89 ;
T_3 V_90 , V_91 , V_92 , V_93 ;
T_3 V_94 , V_95 ;
T_3 V_96 , V_97 ;
T_3 V_98 , V_99 ;
T_3 V_100 , V_101 ;
T_2 V_102 ;
enum V_4 V_4 ;
F_5 ( L_12 ) ;
V_7 -> V_103 = V_79 -> V_104 ? 0 : 1 ;
V_7 -> V_105 = V_79 -> V_106 ? 1 : 0 ;
V_7 -> V_107 = V_79 -> V_108 + 1 ;
V_7 -> V_109 =
F_35 (
V_79 -> V_110 << 7 ) ;
V_83 = F_36 ( V_7 -> V_109 ) ;
V_7 -> V_111 = V_79 -> V_111 ;
V_7 -> V_112 = V_79 -> V_112 ;
V_7 -> V_113 = V_79 -> V_114 ;
V_7 -> V_115 = V_79 -> V_116 ;
V_7 -> V_117 = V_79 -> V_118 ;
V_7 -> V_119 = V_79 -> V_119 ;
V_7 -> V_120 = V_79 -> V_121 ;
V_7 -> V_122 = V_79 -> V_123 ;
V_7 -> V_124 = V_79 -> V_125 ;
V_7 -> V_126 = V_79 -> V_127 ;
V_7 -> V_128 =
V_79 -> V_129 ? V_130 : 0 ;
V_100 = V_74 -> clock ;
if ( V_7 -> V_111 ) {
V_100 = V_100 / 2 ;
if ( V_7 -> V_111 == V_131 ) {
V_100 += F_37 ( V_74 -> V_132 *
V_7 -> V_112 *
60 , 1000 ) ;
}
}
if ( V_7 -> V_115 == V_133 ) {
if ( V_79 -> V_134 ) {
V_101 = ( V_100 * V_83 ) / V_7 -> V_107 ;
if ( V_79 -> V_134 <
V_101 ) {
F_26 ( L_13 ) ;
return NULL ;
}
V_102 = F_37 (
V_79 -> V_134 * 100 ,
V_101 ) ;
V_100 = F_37 ( V_100 * V_102 , 100 ) ;
} else {
F_26 ( L_14 ) ;
return NULL ;
}
} else
V_102 = 100 ;
V_7 -> V_102 = V_102 ;
V_7 -> V_100 = V_100 ;
V_86 = ( V_100 * V_83 ) / V_7 -> V_107 ;
switch ( V_7 -> V_117 ) {
case 0 :
V_84 = 50 ;
break;
case 1 :
V_84 = 100 ;
break;
case 2 :
V_84 = 200 ;
break;
default:
V_84 = 50 ;
break;
}
switch ( V_7 -> V_107 ) {
case 1 :
case 2 :
V_85 = 2 ;
break;
case 3 :
V_85 = 4 ;
break;
case 4 :
default:
V_85 = 3 ;
break;
}
V_88 = V_135 ;
V_89 = V_86 ;
V_96 = V_79 -> V_96 ;
V_97 = V_79 -> V_97 ;
V_7 -> V_136 = F_37 ( V_84 * V_89 , 8 * V_88 ) ;
V_94 = F_38 ( V_79 -> V_137 ,
V_79 -> V_138 ) ;
V_90 = F_37 ( V_94 * V_89 , V_88 * 2 ) ;
V_91 = F_37 (
( V_97 - V_94 ) * V_89 ,
V_88 * 2
) ;
if ( V_91 < ( 55 * V_89 / V_88 ) )
if ( ( 55 * V_89 ) % V_88 )
V_91 += 1 ;
V_92 = F_37 (
( V_96 - V_94 )
* V_89 , 2 * V_88 ) ;
V_95 = F_38 ( V_79 -> V_139 , V_79 -> V_140 ) ;
V_93 = F_37 ( V_95 * V_89 , 2 * V_88 ) ;
if ( V_90 > V_141 ||
V_91 > V_142 ||
V_92 > V_143 ||
V_93 > V_144 )
F_8 ( L_15 ) ;
if ( V_90 > V_141 )
V_90 = V_141 ;
if ( V_91 > V_142 )
V_91 = V_142 ;
if ( V_92 > V_143 )
V_92 = V_143 ;
if ( V_93 > V_144 )
V_93 = V_144 ;
V_7 -> V_145 = V_91 << 24 | V_93 << 16 |
V_92 << 8 | V_90 ;
V_87 = F_37 ( V_84 * V_89 , V_88 ) ;
V_98 = F_37 ( 4 * V_87 + V_90 * 2 +
V_91 * 2 + 10 , 8 ) ;
V_99 = F_37 ( V_79 -> V_140 + 2 * V_87 , 8 ) ;
V_7 -> V_146 = F_38 ( V_98 , V_99 ) ;
V_7 -> V_146 += V_85 ;
V_7 -> V_147 =
F_37 (
4 * V_87 + V_90 * 2 +
V_92 * 2 ,
8 ) ;
V_7 -> V_147 += V_85 ;
V_7 -> V_148 =
F_37 ( 2 * V_87 + V_93 * 2 + 8 ,
8 ) ;
V_7 -> V_148 += V_85 ;
F_5 ( L_16 , V_7 -> V_103 ? L_17 : L_18 ) ;
F_5 ( L_19 , V_7 -> V_105 ?
L_18 : L_17 ) ;
F_5 ( L_20 , V_7 -> V_113 ? L_21 : L_22 ) ;
if ( V_7 -> V_111 == V_131 )
F_5 ( L_23 ) ;
else if ( V_7 -> V_111 == V_149 )
F_5 ( L_24 ) ;
else
F_5 ( L_25 ) ;
F_5 ( L_26 , V_7 -> V_109 ) ;
F_5 ( L_27 , V_7 -> V_117 ) ;
F_5 ( L_28 , V_7 -> V_119 ) ;
F_5 ( L_29 , V_7 -> V_120 ) ;
F_5 ( L_30 , V_7 -> V_124 ) ;
F_5 ( L_31 , V_7 -> V_146 ) ;
F_5 ( L_32 , V_7 -> V_136 ) ;
F_5 ( L_33 , V_7 -> V_126 ) ;
F_5 ( L_34 , V_7 -> V_147 ) ;
F_5 ( L_35 , V_7 -> V_148 ) ;
F_5 ( L_36 ,
V_7 -> V_128 & V_130 ?
L_18 : L_17 ) ;
V_7 -> V_150 = V_82 -> V_151 / 10 ;
V_7 -> V_152 = V_82 -> V_153 / 10 ;
V_7 -> V_154 = V_82 -> V_154 / 10 ;
V_7 -> V_155 = V_82 -> V_155 / 10 ;
V_7 -> V_156 = V_82 -> V_157 / 10 ;
V_1 = F_39 ( V_56 -> V_56 , sizeof( * V_1 ) , V_158 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_7 = V_7 ;
F_40 ( & V_1 -> V_3 ) ;
V_1 -> V_3 . V_159 = & V_160 ;
F_41 ( & V_1 -> V_3 ) ;
F_42 (port, intel_dsi->ports) {
F_43 ( V_7 -> V_16 [ V_4 ] -> V_17 ) ;
}
return & V_1 -> V_3 ;
}
