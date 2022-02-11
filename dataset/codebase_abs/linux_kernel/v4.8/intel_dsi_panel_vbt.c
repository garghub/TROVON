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
V_4 = V_50 ;
} else {
if ( V_38 == 0 ) {
V_4 = V_50 ;
} else if ( V_38 == 1 ) {
F_5 ( L_5 ) ;
return;
} else {
F_5 ( L_6 , V_38 ) ;
return;
}
}
V_43 = F_14 ( V_42 -> V_51 ) ;
V_44 = F_15 ( V_42 -> V_51 ) ;
F_16 ( & V_37 -> V_52 ) ;
if ( ! V_42 -> V_53 ) {
F_17 ( V_37 , V_4 , V_43 , 0x2000CC00 ) ;
V_42 -> V_53 = true ;
}
V_45 = 0x4 | V_40 ;
F_17 ( V_37 , V_4 , V_44 , V_45 ) ;
F_18 ( & V_37 -> V_52 ) ;
}
static void F_19 ( struct V_36 * V_37 ,
T_1 V_38 , T_1 V_39 , bool V_40 )
{
T_2 V_54 , V_55 ;
T_2 V_56 ;
T_1 V_4 ;
if ( V_37 -> V_47 . V_48 . V_49 >= 3 ) {
if ( V_39 >= V_57 ) {
V_39 -= V_57 ;
V_4 = V_58 ;
} else if ( V_39 >= V_59 ) {
V_39 -= V_59 ;
V_4 = V_60 ;
} else if ( V_39 >= V_61 ) {
V_39 -= V_61 ;
V_4 = V_62 ;
} else {
V_4 = V_63 ;
}
} else {
if ( V_38 != 0 ) {
F_5 ( L_6 , V_38 ) ;
return;
}
if ( V_39 >= V_61 ) {
F_5 ( L_7 ,
V_39 ) ;
return;
}
V_4 = V_63 ;
}
V_56 = V_39 / V_64 ;
V_39 = V_39 % V_64 ;
V_54 = F_20 ( V_56 , V_39 ) ;
V_55 = F_21 ( V_56 , V_39 ) ;
F_16 ( & V_37 -> V_52 ) ;
F_17 ( V_37 , V_4 , V_55 , 0 ) ;
F_17 ( V_37 , V_4 , V_54 ,
V_65 | F_22 ( V_40 ) ) ;
F_18 ( & V_37 -> V_52 ) ;
}
static const T_1 * F_23 ( struct V_7 * V_7 , const T_1 * V_8 )
{
struct V_66 * V_67 = V_7 -> V_68 . V_68 . V_67 ;
struct V_36 * V_37 = F_24 ( V_67 ) ;
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
if ( F_25 ( V_37 ) )
F_12 ( V_37 , V_38 , V_39 , V_40 ) ;
else if ( F_26 ( V_37 ) )
F_19 ( V_37 , V_38 , V_39 , V_40 ) ;
else
F_5 ( L_8 ) ;
return V_8 ;
}
static const T_1 * F_27 ( struct V_7 * V_7 , const T_1 * V_8 )
{
return V_8 + * ( V_8 + 6 ) + 7 ;
}
static const char * F_28 ( enum V_69 V_70 )
{
if ( V_70 < F_13 ( V_71 ) && V_71 [ V_70 ] )
return V_71 [ V_70 ] ;
else
return L_9 ;
}
static void F_29 ( struct V_2 * V_3 , enum V_69 V_70 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_36 * V_37 = F_24 ( V_7 -> V_68 . V_68 . V_67 ) ;
const T_1 * V_8 ;
T_4 V_72 ;
if ( F_30 ( V_70 >= F_13 ( V_37 -> V_47 . V_48 . V_73 ) ) )
return;
V_8 = V_37 -> V_47 . V_48 . V_73 [ V_70 ] ;
if ( ! V_8 ) {
F_5 ( L_10 ,
V_70 , F_28 ( V_70 ) ) ;
return;
}
F_30 ( * V_8 != V_70 ) ;
F_5 ( L_11 ,
V_70 , F_28 ( V_70 ) ) ;
V_8 ++ ;
if ( V_37 -> V_47 . V_48 . V_49 >= 3 )
V_8 += 4 ;
while ( 1 ) {
T_1 V_74 = * V_8 ++ ;
T_1 V_75 = 0 ;
if ( V_74 == V_76 )
break;
if ( V_74 < F_13 ( V_77 ) )
V_72 = V_77 [ V_74 ] ;
else
V_72 = NULL ;
if ( V_37 -> V_47 . V_48 . V_49 >= 3 )
V_75 = * V_8 ++ ;
if ( V_72 ) {
V_8 = V_72 ( V_7 , V_8 ) ;
} else if ( V_75 ) {
F_5 ( L_12 ,
V_74 ) ;
V_8 += V_75 ;
} else {
F_31 ( L_12 ,
V_74 ) ;
return;
}
}
}
static int F_32 ( struct V_2 * V_3 )
{
F_29 ( V_3 , V_78 ) ;
F_29 ( V_3 , V_79 ) ;
return 0 ;
}
static int F_33 ( struct V_2 * V_3 )
{
F_29 ( V_3 , V_80 ) ;
return 0 ;
}
static int F_34 ( struct V_2 * V_3 )
{
F_29 ( V_3 , V_81 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 )
{
F_29 ( V_3 , V_82 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_66 * V_67 = V_7 -> V_68 . V_68 . V_67 ;
struct V_36 * V_37 = F_24 ( V_67 ) ;
struct V_83 * V_84 ;
if ( ! V_3 -> V_85 )
return 0 ;
V_84 = F_37 ( V_67 , V_37 -> V_47 . V_86 ) ;
if ( ! V_84 )
return 0 ;
V_84 -> type |= V_87 ;
F_38 ( V_3 -> V_85 , V_84 ) ;
return 1 ;
}
struct V_2 * F_39 ( struct V_7 * V_7 , T_2 V_88 )
{
struct V_66 * V_67 = V_7 -> V_68 . V_68 . V_67 ;
struct V_36 * V_37 = F_24 ( V_67 ) ;
struct V_89 * V_89 = V_37 -> V_47 . V_48 . V_90 ;
struct V_91 * V_92 = V_37 -> V_47 . V_48 . V_92 ;
struct V_83 * V_84 = V_37 -> V_47 . V_86 ;
struct V_1 * V_1 ;
T_3 V_93 ;
T_3 V_94 , V_95 , V_96 , V_97 ;
T_3 V_98 , V_99 ;
T_3 V_100 , V_101 , V_102 , V_103 ;
T_3 V_104 , V_105 ;
T_3 V_106 , V_107 ;
T_3 V_108 , V_109 ;
T_3 V_110 , V_111 ;
T_2 V_112 ;
enum V_4 V_4 ;
F_5 ( L_13 ) ;
V_7 -> V_113 = V_89 -> V_114 ? 0 : 1 ;
V_7 -> V_115 = V_89 -> V_116 ? 1 : 0 ;
V_7 -> V_117 = V_89 -> V_118 + 1 ;
V_7 -> V_119 =
F_40 (
V_89 -> V_120 << 7 ) ;
V_93 = F_41 ( V_7 -> V_119 ) ;
V_7 -> V_121 = V_89 -> V_121 ;
V_7 -> V_122 = V_89 -> V_122 ;
V_7 -> V_123 = V_89 -> V_124 ;
V_7 -> V_125 = V_89 -> V_126 ;
V_7 -> V_127 = V_89 -> V_128 ;
V_7 -> V_129 = V_89 -> V_129 ;
V_7 -> V_130 = V_89 -> V_131 ;
V_7 -> V_132 = V_89 -> V_133 ;
V_7 -> V_134 = V_89 -> V_135 ;
V_7 -> V_136 = V_89 -> V_137 ;
V_7 -> V_138 =
V_89 -> V_139 ? V_140 : 0 ;
V_110 = V_84 -> clock ;
if ( V_7 -> V_121 ) {
V_110 = V_110 / 2 ;
if ( V_7 -> V_121 == V_141 ) {
V_110 += F_42 ( V_84 -> V_142 *
V_7 -> V_122 *
60 , 1000 ) ;
}
}
if ( V_7 -> V_125 == V_143 ) {
if ( V_89 -> V_144 ) {
V_111 = ( V_110 * V_93 ) / V_7 -> V_117 ;
if ( V_89 -> V_144 <
V_111 ) {
F_31 ( L_14 ) ;
return NULL ;
}
V_112 = F_42 (
V_89 -> V_144 * 100 ,
V_111 ) ;
V_110 = F_42 ( V_110 * V_112 , 100 ) ;
} else {
F_31 ( L_15 ) ;
return NULL ;
}
} else
V_112 = 100 ;
V_7 -> V_112 = V_112 ;
V_7 -> V_110 = V_110 ;
V_96 = ( V_110 * V_93 ) / V_7 -> V_117 ;
switch ( V_7 -> V_127 ) {
case 0 :
V_94 = 50 ;
break;
case 1 :
V_94 = 100 ;
break;
case 2 :
V_94 = 200 ;
break;
default:
V_94 = 50 ;
break;
}
switch ( V_7 -> V_117 ) {
case 1 :
case 2 :
V_95 = 2 ;
break;
case 3 :
V_95 = 4 ;
break;
case 4 :
default:
V_95 = 3 ;
break;
}
V_98 = V_145 ;
V_99 = V_96 ;
V_106 = V_89 -> V_106 ;
V_107 = V_89 -> V_107 ;
V_7 -> V_146 = F_42 ( V_94 * V_99 , 8 * V_98 ) ;
V_104 = F_43 ( V_89 -> V_147 ,
V_89 -> V_148 ) ;
V_100 = F_42 ( V_104 * V_99 , V_98 * 2 ) ;
V_101 = F_42 (
( V_107 - V_104 ) * V_99 ,
V_98 * 2
) ;
if ( V_101 < ( 55 * V_99 / V_98 ) && ( 55 * V_99 ) % V_98 )
V_101 += 1 ;
V_102 = F_42 (
( V_106 - V_104 )
* V_99 , 2 * V_98 ) ;
V_105 = F_43 ( V_89 -> V_149 , V_89 -> V_150 ) ;
V_103 = F_42 ( V_105 * V_99 , 2 * V_98 ) ;
if ( V_100 > V_151 ||
V_101 > V_152 ||
V_102 > V_153 ||
V_103 > V_154 )
F_8 ( L_16 ) ;
if ( V_100 > V_151 )
V_100 = V_151 ;
if ( V_101 > V_152 )
V_101 = V_152 ;
if ( V_102 > V_153 )
V_102 = V_153 ;
if ( V_103 > V_154 )
V_103 = V_154 ;
V_7 -> V_155 = V_101 << 24 | V_103 << 16 |
V_102 << 8 | V_100 ;
V_97 = F_42 ( V_94 * V_99 , V_98 ) ;
V_108 = F_42 ( 4 * V_97 + V_100 * 2 +
V_101 * 2 + 10 , 8 ) ;
V_109 = F_42 ( V_89 -> V_150 + 2 * V_97 , 8 ) ;
V_7 -> V_156 = F_43 ( V_108 , V_109 ) ;
V_7 -> V_156 += V_95 ;
V_7 -> V_157 =
F_42 (
4 * V_97 + V_100 * 2 +
V_102 * 2 ,
8 ) ;
V_7 -> V_157 += V_95 ;
V_7 -> V_158 =
F_42 ( 2 * V_97 + V_103 * 2 + 8 ,
8 ) ;
V_7 -> V_158 += V_95 ;
F_5 ( L_17 , V_7 -> V_113 ? L_18 : L_19 ) ;
F_5 ( L_20 , V_7 -> V_115 ?
L_19 : L_18 ) ;
F_5 ( L_21 , V_7 -> V_123 ? L_22 : L_23 ) ;
if ( V_7 -> V_121 == V_141 )
F_5 ( L_24 ) ;
else if ( V_7 -> V_121 == V_159 )
F_5 ( L_25 ) ;
else
F_5 ( L_26 ) ;
F_5 ( L_27 , V_7 -> V_119 ) ;
F_5 ( L_28 , V_7 -> V_127 ) ;
F_5 ( L_29 , V_7 -> V_129 ) ;
F_5 ( L_30 , V_7 -> V_130 ) ;
F_5 ( L_31 , V_7 -> V_134 ) ;
F_5 ( L_32 , V_7 -> V_156 ) ;
F_5 ( L_33 , V_7 -> V_146 ) ;
F_5 ( L_34 , V_7 -> V_136 ) ;
F_5 ( L_35 , V_7 -> V_157 ) ;
F_5 ( L_36 , V_7 -> V_158 ) ;
F_5 ( L_37 ,
V_7 -> V_138 & V_140 ?
L_19 : L_18 ) ;
V_7 -> V_160 = V_92 -> V_161 / 10 ;
V_7 -> V_162 = V_92 -> V_163 / 10 ;
V_7 -> V_164 = V_92 -> V_164 / 10 ;
V_7 -> V_165 = V_92 -> V_165 / 10 ;
V_7 -> V_166 = V_92 -> V_167 / 10 ;
V_1 = F_44 ( V_67 -> V_67 , sizeof( * V_1 ) , V_168 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_7 = V_7 ;
F_45 ( & V_1 -> V_3 ) ;
V_1 -> V_3 . V_169 = & V_170 ;
F_46 ( & V_1 -> V_3 ) ;
F_47 (port, intel_dsi->ports) {
F_48 ( V_7 -> V_16 [ V_4 ] -> V_17 ) ;
}
return & V_1 -> V_3 ;
}
