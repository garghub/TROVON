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
F_5 ( L_1 ) ;
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
F_5 ( L_2 , F_6 ( V_4 ) ) ;
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
F_8 ( L_3 ) ;
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
F_8 ( L_4 ) ;
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
F_5 ( L_1 ) ;
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
F_5 ( L_5 , V_39 ) ;
return;
}
V_42 = & V_46 [ V_39 ] ;
if ( V_37 -> V_47 . V_48 . V_49 >= 3 ) {
V_4 = V_50 ;
} else {
if ( V_38 == 0 ) {
V_4 = V_50 ;
} else if ( V_38 == 1 ) {
F_5 ( L_6 ) ;
return;
} else {
F_5 ( L_7 , V_38 ) ;
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
F_5 ( L_7 , V_38 ) ;
return;
}
if ( V_39 >= V_61 ) {
F_5 ( L_8 ,
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
V_65 | V_66 |
F_22 ( V_40 ) ) ;
F_18 ( & V_37 -> V_52 ) ;
}
static void F_23 ( struct V_36 * V_37 ,
T_1 V_38 , T_1 V_39 , bool V_40 )
{
static struct V_67 * V_68 [ V_69 + 1 ] ;
struct V_67 * V_67 = V_68 [ V_39 ] ;
if ( ! V_67 ) {
V_67 = F_24 ( V_37 -> V_70 . V_71 ,
L_9 , V_39 ,
V_40 ? V_72 :
V_73 ) ;
if ( F_25 ( V_67 ) ) {
F_26 ( L_10 ,
V_39 , F_27 ( V_67 ) ) ;
return;
}
V_68 [ V_39 ] = V_67 ;
}
F_28 ( V_67 , V_40 ) ;
}
static const T_1 * F_29 ( struct V_7 * V_7 , const T_1 * V_8 )
{
struct V_74 * V_71 = V_7 -> V_75 . V_75 . V_71 ;
struct V_36 * V_37 = F_30 ( V_71 ) ;
T_1 V_38 , V_39 = 0 , V_76 ;
bool V_40 ;
F_5 ( L_1 ) ;
if ( V_37 -> V_47 . V_48 . V_49 >= 3 )
V_39 = * V_8 ++ ;
V_76 = * V_8 ++ ;
if ( V_37 -> V_47 . V_48 . V_49 == 2 )
V_38 = ( * V_8 >> 1 ) & 3 ;
else
V_38 = 0 ;
V_40 = * V_8 ++ & 1 ;
if ( F_31 ( V_37 ) )
F_12 ( V_37 , V_38 , V_76 , V_40 ) ;
else if ( F_32 ( V_37 ) )
F_19 ( V_37 , V_38 , V_76 , V_40 ) ;
else
F_23 ( V_37 , V_38 , V_39 , V_40 ) ;
return V_8 ;
}
static const T_1 * F_33 ( struct V_7 * V_7 , const T_1 * V_8 )
{
F_5 ( L_11 ) ;
return V_8 + * ( V_8 + 6 ) + 7 ;
}
static const T_1 * F_34 ( struct V_7 * V_7 , const T_1 * V_8 )
{
F_5 ( L_12 ) ;
return V_8 + * ( V_8 + 5 ) + 6 ;
}
static const T_1 * F_35 ( struct V_7 * V_7 , const T_1 * V_8 )
{
F_5 ( L_13 ) ;
return V_8 + 15 ;
}
static const char * F_36 ( enum V_77 V_78 )
{
if ( V_78 < F_13 ( V_79 ) && V_79 [ V_78 ] )
return V_79 [ V_78 ] ;
else
return L_14 ;
}
static void F_37 ( struct V_2 * V_3 , enum V_77 V_78 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_36 * V_37 = F_30 ( V_7 -> V_75 . V_75 . V_71 ) ;
const T_1 * V_8 ;
T_4 V_80 ;
if ( F_38 ( V_78 >= F_13 ( V_37 -> V_47 . V_48 . V_81 ) ) )
return;
V_8 = V_37 -> V_47 . V_48 . V_81 [ V_78 ] ;
if ( ! V_8 )
return;
F_38 ( * V_8 != V_78 ) ;
F_5 ( L_15 ,
V_78 , F_36 ( V_78 ) ) ;
V_8 ++ ;
if ( V_37 -> V_47 . V_48 . V_49 >= 3 )
V_8 += 4 ;
while ( 1 ) {
T_1 V_82 = * V_8 ++ ;
T_1 V_83 = 0 ;
if ( V_82 == V_84 )
break;
if ( V_82 < F_13 ( V_85 ) )
V_80 = V_85 [ V_82 ] ;
else
V_80 = NULL ;
if ( V_37 -> V_47 . V_48 . V_49 >= 3 )
V_83 = * V_8 ++ ;
if ( V_80 ) {
const T_1 * V_86 = V_8 + V_83 ;
V_8 = V_80 ( V_7 , V_8 ) ;
if ( V_83 && V_8 != V_86 ) {
F_26 ( L_16 ) ;
return;
}
} else if ( V_83 ) {
F_5 ( L_17 ,
V_82 ) ;
V_8 += V_83 ;
} else {
F_26 ( L_17 ,
V_82 ) ;
return;
}
}
}
static int F_39 ( struct V_2 * V_3 )
{
F_37 ( V_3 , V_87 ) ;
F_37 ( V_3 , V_88 ) ;
F_37 ( V_3 , V_89 ) ;
F_37 ( V_3 , V_90 ) ;
return 0 ;
}
static int F_40 ( struct V_2 * V_3 )
{
F_37 ( V_3 , V_87 ) ;
F_37 ( V_3 , V_91 ) ;
return 0 ;
}
static int F_41 ( struct V_2 * V_3 )
{
F_37 ( V_3 , V_92 ) ;
F_37 ( V_3 , V_93 ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 )
{
F_37 ( V_3 , V_94 ) ;
F_37 ( V_3 , V_95 ) ;
return 0 ;
}
static int F_43 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_74 * V_71 = V_7 -> V_75 . V_75 . V_71 ;
struct V_36 * V_37 = F_30 ( V_71 ) ;
struct V_96 * V_97 ;
if ( ! V_3 -> V_98 )
return 0 ;
V_97 = F_44 ( V_71 , V_37 -> V_47 . V_99 ) ;
if ( ! V_97 )
return 0 ;
V_97 -> type |= V_100 ;
F_45 ( V_3 -> V_98 , V_97 ) ;
return 1 ;
}
struct V_2 * F_46 ( struct V_7 * V_7 , T_2 V_101 )
{
struct V_74 * V_71 = V_7 -> V_75 . V_75 . V_71 ;
struct V_36 * V_37 = F_30 ( V_71 ) ;
struct V_102 * V_102 = V_37 -> V_47 . V_48 . V_103 ;
struct V_104 * V_105 = V_37 -> V_47 . V_48 . V_105 ;
struct V_96 * V_97 = V_37 -> V_47 . V_99 ;
struct V_1 * V_1 ;
T_3 V_106 ;
T_3 V_107 , V_108 , V_109 , V_110 ;
T_3 V_111 , V_112 ;
T_3 V_113 , V_114 , V_115 , V_116 ;
T_3 V_117 , V_118 ;
T_3 V_119 , V_120 ;
T_3 V_121 , V_122 ;
T_3 V_123 , V_124 ;
T_2 V_125 ;
enum V_4 V_4 ;
F_5 ( L_1 ) ;
V_7 -> V_126 = V_102 -> V_127 ? 0 : 1 ;
V_7 -> V_128 = V_102 -> V_129 ? 1 : 0 ;
V_7 -> V_130 = V_102 -> V_131 + 1 ;
V_7 -> V_132 =
F_47 (
V_102 -> V_133 << 7 ) ;
V_106 = F_48 ( V_7 -> V_132 ) ;
V_7 -> V_134 = V_102 -> V_134 ;
V_7 -> V_135 = V_102 -> V_135 ;
V_7 -> V_136 = V_102 -> V_137 ;
V_7 -> V_138 = V_102 -> V_139 ;
V_7 -> V_140 = V_102 -> V_141 ;
V_7 -> V_142 = V_102 -> V_142 ;
V_7 -> V_143 = V_102 -> V_144 ;
V_7 -> V_145 = V_102 -> V_146 ;
V_7 -> V_147 = V_102 -> V_148 ;
V_7 -> V_149 = V_102 -> V_150 ;
V_7 -> V_151 =
V_102 -> V_152 ? V_153 : 0 ;
V_123 = V_97 -> clock ;
if ( V_7 -> V_134 ) {
V_123 = V_123 / 2 ;
if ( V_7 -> V_134 == V_154 ) {
V_123 += F_49 ( V_97 -> V_155 *
V_7 -> V_135 *
60 , 1000 ) ;
}
}
if ( V_7 -> V_138 == V_156 ) {
if ( V_102 -> V_157 ) {
V_124 = ( V_123 * V_106 ) / V_7 -> V_130 ;
if ( V_102 -> V_157 <
V_124 ) {
F_26 ( L_18 ) ;
return NULL ;
}
V_125 = F_49 (
V_102 -> V_157 * 100 ,
V_124 ) ;
V_123 = F_49 ( V_123 * V_125 , 100 ) ;
} else {
F_26 ( L_19 ) ;
return NULL ;
}
} else
V_125 = 100 ;
V_7 -> V_125 = V_125 ;
V_7 -> V_123 = V_123 ;
V_109 = ( V_123 * V_106 ) / V_7 -> V_130 ;
switch ( V_7 -> V_140 ) {
case 0 :
V_107 = 50 ;
break;
case 1 :
V_107 = 100 ;
break;
case 2 :
V_107 = 200 ;
break;
default:
V_107 = 50 ;
break;
}
switch ( V_7 -> V_130 ) {
case 1 :
case 2 :
V_108 = 2 ;
break;
case 3 :
V_108 = 4 ;
break;
case 4 :
default:
V_108 = 3 ;
break;
}
V_111 = V_158 ;
V_112 = V_109 ;
V_119 = V_102 -> V_119 ;
V_120 = V_102 -> V_120 ;
V_7 -> V_159 = F_49 ( V_107 * V_112 , 8 * V_111 ) ;
V_117 = F_50 ( V_102 -> V_160 ,
V_102 -> V_161 ) ;
V_113 = F_49 ( V_117 * V_112 , V_111 * 2 ) ;
V_114 = F_49 (
( V_120 - V_117 ) * V_112 ,
V_111 * 2
) ;
if ( V_114 < ( 55 * V_112 / V_111 ) && ( 55 * V_112 ) % V_111 )
V_114 += 1 ;
V_115 = F_49 (
( V_119 - V_117 )
* V_112 , 2 * V_111 ) ;
V_118 = F_50 ( V_102 -> V_162 , V_102 -> V_163 ) ;
V_116 = F_49 ( V_118 * V_112 , 2 * V_111 ) ;
if ( V_113 > V_164 ||
V_114 > V_165 ||
V_115 > V_166 ||
V_116 > V_167 )
F_8 ( L_20 ) ;
if ( V_113 > V_164 )
V_113 = V_164 ;
if ( V_114 > V_165 )
V_114 = V_165 ;
if ( V_115 > V_166 )
V_115 = V_166 ;
if ( V_116 > V_167 )
V_116 = V_167 ;
V_7 -> V_168 = V_114 << 24 | V_116 << 16 |
V_115 << 8 | V_113 ;
V_110 = F_49 ( V_107 * V_112 , V_111 ) ;
V_121 = F_49 ( 4 * V_110 + V_113 * 2 +
V_114 * 2 + 10 , 8 ) ;
V_122 = F_49 ( V_102 -> V_163 + 2 * V_110 , 8 ) ;
V_7 -> V_169 = F_50 ( V_121 , V_122 ) ;
V_7 -> V_169 += V_108 ;
V_7 -> V_170 =
F_49 (
4 * V_110 + V_113 * 2 +
V_115 * 2 ,
8 ) ;
V_7 -> V_170 += V_108 ;
V_7 -> V_171 =
F_49 ( 2 * V_110 + V_116 * 2 + 8 ,
8 ) ;
V_7 -> V_171 += V_108 ;
F_5 ( L_21 , F_51 ( V_7 -> V_126 ) ) ;
F_5 ( L_22 , F_51 ( ! V_7 -> V_128 ) ) ;
F_5 ( L_23 , V_7 -> V_136 ? L_24 : L_25 ) ;
if ( V_7 -> V_134 == V_154 )
F_5 ( L_26 ) ;
else if ( V_7 -> V_134 == V_172 )
F_5 ( L_27 ) ;
else
F_5 ( L_28 ) ;
F_5 ( L_29 , V_7 -> V_132 ) ;
F_5 ( L_30 , V_7 -> V_140 ) ;
F_5 ( L_31 , V_7 -> V_142 ) ;
F_5 ( L_32 , V_7 -> V_143 ) ;
F_5 ( L_33 , V_7 -> V_147 ) ;
F_5 ( L_34 , V_7 -> V_169 ) ;
F_5 ( L_35 , V_7 -> V_159 ) ;
F_5 ( L_36 , V_7 -> V_149 ) ;
F_5 ( L_37 , V_7 -> V_170 ) ;
F_5 ( L_38 , V_7 -> V_171 ) ;
F_5 ( L_39 ,
F_51 ( ! ( V_7 -> V_151 & V_153 ) ) ) ;
V_7 -> V_173 = V_105 -> V_174 / 10 ;
V_7 -> V_175 = V_105 -> V_176 / 10 ;
V_7 -> V_177 = V_105 -> V_177 / 10 ;
V_7 -> V_178 = V_105 -> V_178 / 10 ;
V_7 -> V_179 = V_105 -> V_180 / 10 ;
V_1 = F_52 ( V_71 -> V_71 , sizeof( * V_1 ) , V_181 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_7 = V_7 ;
F_53 ( & V_1 -> V_3 ) ;
V_1 -> V_3 . V_182 = & V_183 ;
F_54 ( & V_1 -> V_3 ) ;
F_55 (port, intel_dsi->ports) {
F_56 ( V_7 -> V_16 [ V_4 ] -> V_17 ) ;
}
return & V_1 -> V_3 ;
}
