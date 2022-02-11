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
static const T_1 * F_23 ( struct V_7 * V_7 , const T_1 * V_8 )
{
struct V_67 * V_68 = V_7 -> V_69 . V_69 . V_68 ;
struct V_36 * V_37 = F_24 ( V_68 ) ;
T_1 V_38 , V_39 ;
bool V_40 ;
F_5 ( L_1 ) ;
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
F_5 ( L_9 ) ;
return V_8 ;
}
static const T_1 * F_27 ( struct V_7 * V_7 , const T_1 * V_8 )
{
F_5 ( L_10 ) ;
return V_8 + * ( V_8 + 6 ) + 7 ;
}
static const T_1 * F_28 ( struct V_7 * V_7 , const T_1 * V_8 )
{
F_5 ( L_11 ) ;
return V_8 + * ( V_8 + 5 ) + 6 ;
}
static const T_1 * F_29 ( struct V_7 * V_7 , const T_1 * V_8 )
{
F_5 ( L_12 ) ;
return V_8 + 15 ;
}
static const char * F_30 ( enum V_70 V_71 )
{
if ( V_71 < F_13 ( V_72 ) && V_72 [ V_71 ] )
return V_72 [ V_71 ] ;
else
return L_13 ;
}
static void F_31 ( struct V_2 * V_3 , enum V_70 V_71 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_36 * V_37 = F_24 ( V_7 -> V_69 . V_69 . V_68 ) ;
const T_1 * V_8 ;
T_4 V_73 ;
if ( F_32 ( V_71 >= F_13 ( V_37 -> V_47 . V_48 . V_74 ) ) )
return;
V_8 = V_37 -> V_47 . V_48 . V_74 [ V_71 ] ;
if ( ! V_8 )
return;
F_32 ( * V_8 != V_71 ) ;
F_5 ( L_14 ,
V_71 , F_30 ( V_71 ) ) ;
V_8 ++ ;
if ( V_37 -> V_47 . V_48 . V_49 >= 3 )
V_8 += 4 ;
while ( 1 ) {
T_1 V_75 = * V_8 ++ ;
T_1 V_76 = 0 ;
if ( V_75 == V_77 )
break;
if ( V_75 < F_13 ( V_78 ) )
V_73 = V_78 [ V_75 ] ;
else
V_73 = NULL ;
if ( V_37 -> V_47 . V_48 . V_49 >= 3 )
V_76 = * V_8 ++ ;
if ( V_73 ) {
const T_1 * V_79 = V_8 + V_76 ;
V_8 = V_73 ( V_7 , V_8 ) ;
if ( V_76 && V_8 != V_79 ) {
F_33 ( L_15 ) ;
return;
}
} else if ( V_76 ) {
F_5 ( L_16 ,
V_75 ) ;
V_8 += V_76 ;
} else {
F_33 ( L_16 ,
V_75 ) ;
return;
}
}
}
static int F_34 ( struct V_2 * V_3 )
{
F_31 ( V_3 , V_80 ) ;
F_31 ( V_3 , V_81 ) ;
F_31 ( V_3 , V_82 ) ;
F_31 ( V_3 , V_83 ) ;
return 0 ;
}
static int F_35 ( struct V_2 * V_3 )
{
F_31 ( V_3 , V_80 ) ;
F_31 ( V_3 , V_84 ) ;
return 0 ;
}
static int F_36 ( struct V_2 * V_3 )
{
F_31 ( V_3 , V_85 ) ;
F_31 ( V_3 , V_86 ) ;
return 0 ;
}
static int F_37 ( struct V_2 * V_3 )
{
F_31 ( V_3 , V_87 ) ;
F_31 ( V_3 , V_88 ) ;
return 0 ;
}
static int F_38 ( struct V_2 * V_3 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_7 * V_7 = V_1 -> V_7 ;
struct V_67 * V_68 = V_7 -> V_69 . V_69 . V_68 ;
struct V_36 * V_37 = F_24 ( V_68 ) ;
struct V_89 * V_90 ;
if ( ! V_3 -> V_91 )
return 0 ;
V_90 = F_39 ( V_68 , V_37 -> V_47 . V_92 ) ;
if ( ! V_90 )
return 0 ;
V_90 -> type |= V_93 ;
F_40 ( V_3 -> V_91 , V_90 ) ;
return 1 ;
}
struct V_2 * F_41 ( struct V_7 * V_7 , T_2 V_94 )
{
struct V_67 * V_68 = V_7 -> V_69 . V_69 . V_68 ;
struct V_36 * V_37 = F_24 ( V_68 ) ;
struct V_95 * V_95 = V_37 -> V_47 . V_48 . V_96 ;
struct V_97 * V_98 = V_37 -> V_47 . V_48 . V_98 ;
struct V_89 * V_90 = V_37 -> V_47 . V_92 ;
struct V_1 * V_1 ;
T_3 V_99 ;
T_3 V_100 , V_101 , V_102 , V_103 ;
T_3 V_104 , V_105 ;
T_3 V_106 , V_107 , V_108 , V_109 ;
T_3 V_110 , V_111 ;
T_3 V_112 , V_113 ;
T_3 V_114 , V_115 ;
T_3 V_116 , V_117 ;
T_2 V_118 ;
enum V_4 V_4 ;
F_5 ( L_1 ) ;
V_7 -> V_119 = V_95 -> V_120 ? 0 : 1 ;
V_7 -> V_121 = V_95 -> V_122 ? 1 : 0 ;
V_7 -> V_123 = V_95 -> V_124 + 1 ;
V_7 -> V_125 =
F_42 (
V_95 -> V_126 << 7 ) ;
V_99 = F_43 ( V_7 -> V_125 ) ;
V_7 -> V_127 = V_95 -> V_127 ;
V_7 -> V_128 = V_95 -> V_128 ;
V_7 -> V_129 = V_95 -> V_130 ;
V_7 -> V_131 = V_95 -> V_132 ;
V_7 -> V_133 = V_95 -> V_134 ;
V_7 -> V_135 = V_95 -> V_135 ;
V_7 -> V_136 = V_95 -> V_137 ;
V_7 -> V_138 = V_95 -> V_139 ;
V_7 -> V_140 = V_95 -> V_141 ;
V_7 -> V_142 = V_95 -> V_143 ;
V_7 -> V_144 =
V_95 -> V_145 ? V_146 : 0 ;
V_116 = V_90 -> clock ;
if ( V_7 -> V_127 ) {
V_116 = V_116 / 2 ;
if ( V_7 -> V_127 == V_147 ) {
V_116 += F_44 ( V_90 -> V_148 *
V_7 -> V_128 *
60 , 1000 ) ;
}
}
if ( V_7 -> V_131 == V_149 ) {
if ( V_95 -> V_150 ) {
V_117 = ( V_116 * V_99 ) / V_7 -> V_123 ;
if ( V_95 -> V_150 <
V_117 ) {
F_33 ( L_17 ) ;
return NULL ;
}
V_118 = F_44 (
V_95 -> V_150 * 100 ,
V_117 ) ;
V_116 = F_44 ( V_116 * V_118 , 100 ) ;
} else {
F_33 ( L_18 ) ;
return NULL ;
}
} else
V_118 = 100 ;
V_7 -> V_118 = V_118 ;
V_7 -> V_116 = V_116 ;
V_102 = ( V_116 * V_99 ) / V_7 -> V_123 ;
switch ( V_7 -> V_133 ) {
case 0 :
V_100 = 50 ;
break;
case 1 :
V_100 = 100 ;
break;
case 2 :
V_100 = 200 ;
break;
default:
V_100 = 50 ;
break;
}
switch ( V_7 -> V_123 ) {
case 1 :
case 2 :
V_101 = 2 ;
break;
case 3 :
V_101 = 4 ;
break;
case 4 :
default:
V_101 = 3 ;
break;
}
V_104 = V_151 ;
V_105 = V_102 ;
V_112 = V_95 -> V_112 ;
V_113 = V_95 -> V_113 ;
V_7 -> V_152 = F_44 ( V_100 * V_105 , 8 * V_104 ) ;
V_110 = F_45 ( V_95 -> V_153 ,
V_95 -> V_154 ) ;
V_106 = F_44 ( V_110 * V_105 , V_104 * 2 ) ;
V_107 = F_44 (
( V_113 - V_110 ) * V_105 ,
V_104 * 2
) ;
if ( V_107 < ( 55 * V_105 / V_104 ) && ( 55 * V_105 ) % V_104 )
V_107 += 1 ;
V_108 = F_44 (
( V_112 - V_110 )
* V_105 , 2 * V_104 ) ;
V_111 = F_45 ( V_95 -> V_155 , V_95 -> V_156 ) ;
V_109 = F_44 ( V_111 * V_105 , 2 * V_104 ) ;
if ( V_106 > V_157 ||
V_107 > V_158 ||
V_108 > V_159 ||
V_109 > V_160 )
F_8 ( L_19 ) ;
if ( V_106 > V_157 )
V_106 = V_157 ;
if ( V_107 > V_158 )
V_107 = V_158 ;
if ( V_108 > V_159 )
V_108 = V_159 ;
if ( V_109 > V_160 )
V_109 = V_160 ;
V_7 -> V_161 = V_107 << 24 | V_109 << 16 |
V_108 << 8 | V_106 ;
V_103 = F_44 ( V_100 * V_105 , V_104 ) ;
V_114 = F_44 ( 4 * V_103 + V_106 * 2 +
V_107 * 2 + 10 , 8 ) ;
V_115 = F_44 ( V_95 -> V_156 + 2 * V_103 , 8 ) ;
V_7 -> V_162 = F_45 ( V_114 , V_115 ) ;
V_7 -> V_162 += V_101 ;
V_7 -> V_163 =
F_44 (
4 * V_103 + V_106 * 2 +
V_108 * 2 ,
8 ) ;
V_7 -> V_163 += V_101 ;
V_7 -> V_164 =
F_44 ( 2 * V_103 + V_109 * 2 + 8 ,
8 ) ;
V_7 -> V_164 += V_101 ;
F_5 ( L_20 , F_46 ( V_7 -> V_119 ) ) ;
F_5 ( L_21 , F_46 ( ! V_7 -> V_121 ) ) ;
F_5 ( L_22 , V_7 -> V_129 ? L_23 : L_24 ) ;
if ( V_7 -> V_127 == V_147 )
F_5 ( L_25 ) ;
else if ( V_7 -> V_127 == V_165 )
F_5 ( L_26 ) ;
else
F_5 ( L_27 ) ;
F_5 ( L_28 , V_7 -> V_125 ) ;
F_5 ( L_29 , V_7 -> V_133 ) ;
F_5 ( L_30 , V_7 -> V_135 ) ;
F_5 ( L_31 , V_7 -> V_136 ) ;
F_5 ( L_32 , V_7 -> V_140 ) ;
F_5 ( L_33 , V_7 -> V_162 ) ;
F_5 ( L_34 , V_7 -> V_152 ) ;
F_5 ( L_35 , V_7 -> V_142 ) ;
F_5 ( L_36 , V_7 -> V_163 ) ;
F_5 ( L_37 , V_7 -> V_164 ) ;
F_5 ( L_38 ,
F_46 ( ! ( V_7 -> V_144 & V_146 ) ) ) ;
V_7 -> V_166 = V_98 -> V_167 / 10 ;
V_7 -> V_168 = V_98 -> V_169 / 10 ;
V_7 -> V_170 = V_98 -> V_170 / 10 ;
V_7 -> V_171 = V_98 -> V_171 / 10 ;
V_7 -> V_172 = V_98 -> V_173 / 10 ;
V_1 = F_47 ( V_68 -> V_68 , sizeof( * V_1 ) , V_174 ) ;
if ( ! V_1 )
return NULL ;
V_1 -> V_7 = V_7 ;
F_48 ( & V_1 -> V_3 ) ;
V_1 -> V_3 . V_175 = & V_176 ;
F_49 ( & V_1 -> V_3 ) ;
F_50 (port, intel_dsi->ports) {
F_51 ( V_7 -> V_16 [ V_4 ] -> V_17 ) ;
}
return & V_1 -> V_3 ;
}
