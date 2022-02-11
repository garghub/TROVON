static inline void F_1 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_2 ( V_2 -> V_3 ) ;
}
static inline void F_3 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_4 ( V_2 -> V_3 ) ;
}
static inline void F_5 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_6 ( V_2 -> V_3 ) ;
}
static inline void F_7 ( const struct V_1 * V_2 )
{
if ( V_2 -> V_3 )
F_8 ( V_2 -> V_3 ) ;
}
static inline void F_9 ( const struct V_1 * V_2 , bool V_4 )
{
if ( V_2 -> V_5 )
V_2 -> V_5 ( V_2 , V_4 ) ;
}
static inline int F_10 ( const struct V_1 * V_2 )
{
return ( V_2 -> V_6 & V_7 ) +
V_8 ;
}
static inline int F_11 ( const struct V_1 * V_2 )
{
return ( V_2 -> V_9 & V_7 ) +
V_8 ;
}
static T_1 F_12 ( struct V_1 * V_2 , enum V_10 V_11 )
{
T_1 V_12 = V_2 -> V_13 ( V_2 , V_11 ) ;
V_12 |= ( ( T_1 ) V_2 -> V_13 ( V_2 , V_11 + 1 ) ) << 16 ;
return V_12 ;
}
static void F_13 ( struct V_1 * V_2 ,
int V_4 )
{
unsigned int V_14 = V_2 -> V_13 ( V_2 ,
V_15 ) ;
if ( V_4 )
V_14 |= ( V_16 | V_17 | V_18 ) ;
else
V_14 &= ~ ( V_17 | V_18 | V_16 ) ;
V_2 -> V_19 ( V_2 , V_15 , V_14 ) ;
}
static inline int F_14 ( struct V_1 * V_2 , int V_20 )
{
int V_21 = V_22 ;
while ( V_21 && V_2 -> V_13 ( V_2 ,
F_15 ( V_23 , V_20 ) ) &
V_24 ) {
V_21 -- ;
F_16 ( 1 ) ;
}
if ( ! V_21 )
return 1 ;
return 0 ;
}
static inline void F_17 ( struct V_25 * V_26 ,
int V_20 , int V_27 , int V_28 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_29 , V_20 ) ,
F_19 ( V_28 ) ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_23 , V_20 ) ,
F_19 ( V_27 ) ) ;
if ( F_14 ( V_2 , V_20 ) )
F_20 ( V_26 , L_1 ) ;
}
static inline void F_21 ( struct V_25 * V_26 ,
int V_20 , int V_27 , int V_28 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_29 , V_20 ) ,
( V_30 | F_19 ( V_28 ) ) ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_23 , V_20 ) ,
F_19 ( V_27 ) ) ;
if ( F_14 ( V_2 , V_20 ) )
F_20 ( V_26 , L_2 ) ;
}
static void F_22 ( struct V_25 * V_26 ,
int V_20 , struct V_31 * V_32 , int V_27 )
{
int V_33 ;
T_2 V_34 = 0 ;
unsigned int V_35 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
if ( ! ( V_32 -> V_36 & V_37 ) )
V_34 |= V_38 ;
if ( V_32 -> V_36 & V_39 ) {
V_35 = V_32 -> V_36 & V_40 ;
V_34 |= V_41 ;
} else
V_35 = ( ( V_32 -> V_36 & V_42 ) << 18 ) ;
V_34 |= V_43 ;
V_2 -> V_19 ( V_2 , F_15 ( V_44 , V_20 ) ,
F_19 ( V_35 ) ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_45 , V_20 ) , V_34 |
F_23 ( V_35 ) ) ;
for ( V_33 = 0 ; V_33 < V_32 -> V_46 ; V_33 += 2 ) {
V_2 -> V_19 ( V_2 , F_15 ( V_47 , V_20 ) + V_33 / 2 ,
V_32 -> V_48 [ V_33 ] | ( V_32 -> V_48 [ V_33 + 1 ] << 8 ) ) ;
}
V_2 -> V_19 ( V_2 , F_15 ( V_49 , V_20 ) ,
V_50 | V_51 | V_52 |
V_32 -> V_46 ) ;
F_21 ( V_26 , V_20 , V_27 , V_53 ) ;
}
static inline void F_24 ( struct V_25 * V_26 ,
int V_20 , int V_54 ,
int V_55 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_49 , V_20 ) ,
V_54 & ~ ( V_56 | V_57 ) ) ;
F_21 ( V_26 , V_20 , V_55 , V_58 ) ;
}
static inline void F_25 ( struct V_25 * V_26 ,
int V_20 ,
int V_54 )
{
int V_33 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
for ( V_33 = V_59 ; V_33 <= V_60 ; V_33 ++ ) {
V_2 -> V_19 ( V_2 , F_15 ( V_49 , V_20 ) ,
V_54 & ~ ( V_56 |
V_57 | V_61 ) ) ;
F_21 ( V_26 , V_20 , V_33 , V_58 ) ;
}
}
static inline void F_26 ( struct V_25 * V_26 ,
int V_20 , int V_54 ,
int V_55 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_49 , V_20 ) ,
V_54 & ~ ( V_56 |
V_57 | V_61 ) ) ;
F_21 ( V_26 , V_20 , V_55 , V_58 ) ;
}
static void F_27 ( struct V_25 * V_26 ,
int V_20 , int V_27 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_62 * V_63 = & V_26 -> V_63 ;
struct V_64 * V_65 ;
struct V_31 * V_32 ;
F_20 ( V_26 , L_3 , V_27 ) ;
F_17 ( V_26 , V_20 , V_27 , V_53 & ~ V_66 ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_49 , V_20 ) ,
V_67 ) ;
F_21 ( V_26 , 0 , V_27 , V_58 ) ;
V_65 = F_28 ( V_26 , & V_32 ) ;
if ( F_29 ( ! V_65 ) )
return;
V_32 -> V_36 |= V_68 ;
V_32 -> V_48 [ 1 ] = V_69 ;
V_63 -> V_70 ++ ;
V_63 -> V_71 ++ ;
F_30 ( V_65 ) ;
}
static int F_31 ( struct V_25 * V_26 , int V_20 , int V_72 )
{
T_2 V_34 , V_48 ;
int V_33 ;
unsigned int V_12 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_62 * V_63 = & V_26 -> V_63 ;
struct V_64 * V_65 ;
struct V_31 * V_32 ;
V_65 = F_32 ( V_26 , & V_32 ) ;
if ( ! V_65 ) {
V_63 -> V_73 ++ ;
return - V_74 ;
}
V_32 -> V_46 = F_33 ( V_72 & 0x0F ) ;
V_34 = V_2 -> V_13 ( V_2 , F_15 ( V_45 , V_20 ) ) ;
V_12 = V_2 -> V_13 ( V_2 , F_15 ( V_44 , V_20 ) ) |
( V_34 << 16 ) ;
if ( V_34 & V_41 )
V_32 -> V_36 = ( V_12 & V_40 ) | V_39 ;
else
V_32 -> V_36 = ( V_12 >> 18 ) & V_42 ;
if ( V_34 & V_38 )
V_32 -> V_36 |= V_37 ;
else {
for ( V_33 = 0 ; V_33 < V_32 -> V_46 ; V_33 += 2 ) {
V_48 = V_2 -> V_13 ( V_2 ,
F_15 ( V_47 , V_20 ) + V_33 / 2 ) ;
V_32 -> V_48 [ V_33 ] = V_48 ;
V_32 -> V_48 [ V_33 + 1 ] = V_48 >> 8 ;
}
}
F_30 ( V_65 ) ;
V_63 -> V_75 ++ ;
V_63 -> V_76 += V_32 -> V_46 ;
return 0 ;
}
static void F_34 ( struct V_25 * V_26 , int V_20 ,
int V_27 , unsigned int V_28 ,
unsigned int V_35 , unsigned int V_77 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_78 , V_20 ) ,
F_19 ( V_28 ) ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_79 , V_20 ) ,
F_23 ( V_28 ) | F_35 ( 13 ) ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_44 , V_20 ) ,
F_19 ( V_35 ) ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_45 , V_20 ) ,
( V_43 | F_23 ( V_35 ) ) ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_49 , V_20 ) , V_77 ) ;
F_21 ( V_26 , V_20 , V_27 , V_53 & ~ V_66 ) ;
F_36 ( V_26 , L_4 , V_27 ,
F_12 ( V_2 , V_80 ) ) ;
}
static void F_37 ( struct V_25 * V_26 , int V_20 , int V_27 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_44 , V_20 ) , 0 ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_45 , V_20 ) , 0 ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_49 , V_20 ) , 0 ) ;
F_21 ( V_26 , V_20 , V_27 , V_81 | V_58 ) ;
F_36 ( V_26 , L_4 , V_27 ,
F_12 ( V_2 , V_80 ) ) ;
}
static inline int F_38 ( struct V_1 * V_2 , int V_27 )
{
int V_12 = F_12 ( V_2 , V_82 ) ;
if ( V_12 & ( 1 << ( V_27 - 1 ) ) )
return 1 ;
return 0 ;
}
static T_3 F_39 ( struct V_64 * V_65 ,
struct V_25 * V_26 )
{
T_1 V_83 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_31 * V_32 = (struct V_31 * ) V_65 -> V_48 ;
if ( F_40 ( V_26 , V_65 ) )
return V_84 ;
V_83 = F_10 ( V_2 ) ;
F_22 ( V_26 , 0 , V_32 , V_83 ) ;
F_41 ( V_65 , V_26 , V_83 - V_8 ) ;
V_2 -> V_6 ++ ;
if ( F_38 ( V_2 , F_10 ( V_2 ) ) ||
( V_2 -> V_6 & V_7 ) == 0 )
F_42 ( V_26 ) ;
return V_84 ;
}
static int F_43 ( struct V_25 * V_26 )
{
unsigned int V_85 , V_86 , V_87 ;
T_4 V_88 , V_89 , V_90 , V_91 , V_92 ;
T_1 V_93 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
const struct V_94 * V_95 = & V_2 -> V_96 . V_97 ;
V_93 = V_95 -> V_88 - 1 ;
V_88 = V_93 & V_98 ;
V_89 = V_93 >> 6 ;
V_90 = V_95 -> V_90 - 1 ;
V_91 = V_95 -> V_99 + V_95 -> V_100 - 1 ;
V_92 = V_95 -> V_101 - 1 ;
V_85 = V_88 | ( V_90 << V_102 ) | ( V_91 << V_103 ) |
( V_92 << V_104 ) ;
V_86 = V_89 & V_105 ;
F_44 ( V_26 ,
L_5 , V_85 , V_86 ) ;
V_87 = V_2 -> V_13 ( V_2 , V_15 ) ;
V_2 -> V_19 ( V_2 , V_15 ,
V_87 | V_106 | V_107 ) ;
V_2 -> V_19 ( V_2 , V_108 , V_85 ) ;
V_2 -> V_19 ( V_2 , V_109 , V_86 ) ;
V_2 -> V_19 ( V_2 , V_15 , V_87 ) ;
return 0 ;
}
static void F_45 ( struct V_25 * V_26 )
{
int V_33 ;
for ( V_33 = V_59 ; V_33 <= V_110 ; V_33 ++ )
F_37 ( V_26 , 0 , V_33 ) ;
for ( V_33 = V_59 ; V_33 < V_111 ; V_33 ++ )
F_34 ( V_26 , 0 , V_33 , 0 , 0 ,
( V_112 | V_113 ) & ~ V_52 ) ;
F_34 ( V_26 , 0 , V_111 , 0 , 0 ,
V_52 | V_112 | V_113 ) ;
}
static void F_46 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_2 -> V_19 ( V_2 , V_15 ,
V_114 ) ;
if ( ( V_2 -> V_96 . V_115 & V_116 ) &&
( V_2 -> V_96 . V_115 & V_117 ) ) {
V_2 -> V_19 ( V_2 , V_15 , V_17 |
V_16 | V_18 | V_118 ) ;
V_2 -> V_19 ( V_2 , V_119 ,
V_120 | V_121 ) ;
} else if ( V_2 -> V_96 . V_115 & V_117 ) {
V_2 -> V_19 ( V_2 , V_15 , V_17 |
V_16 | V_18 | V_118 ) ;
V_2 -> V_19 ( V_2 , V_119 , V_120 ) ;
} else if ( V_2 -> V_96 . V_115 & V_116 ) {
V_2 -> V_19 ( V_2 , V_15 , V_17 |
V_16 | V_18 | V_118 ) ;
V_2 -> V_19 ( V_2 , V_119 , V_121 ) ;
} else
V_2 -> V_19 ( V_2 , V_15 ,
V_17 | V_16 | V_18 ) ;
F_45 ( V_26 ) ;
V_2 -> V_19 ( V_2 , V_122 , V_123 ) ;
F_43 ( V_26 ) ;
}
static void F_47 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
F_46 ( V_26 ) ;
V_2 -> V_96 . V_124 = V_125 ;
V_2 -> V_6 = V_2 -> V_9 = 0 ;
F_13 ( V_2 , V_126 ) ;
}
static void F_48 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
F_13 ( V_2 , V_127 ) ;
V_2 -> V_96 . V_124 = V_128 ;
}
static int F_49 ( struct V_25 * V_26 , enum V_129 V_130 )
{
switch ( V_130 ) {
case V_131 :
F_47 ( V_26 ) ;
F_50 ( V_26 ) ;
break;
default:
return - V_132 ;
}
return 0 ;
}
static int F_51 ( const struct V_25 * V_26 ,
struct V_133 * V_134 )
{
unsigned int V_135 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
F_5 ( V_2 ) ;
V_135 = V_2 -> V_13 ( V_2 , V_136 ) ;
V_134 -> V_137 = ( V_135 & V_138 ) >>
V_139 ;
V_134 -> V_140 = V_135 & V_141 ;
F_7 ( V_2 ) ;
return 0 ;
}
static void F_52 ( struct V_25 * V_26 )
{
T_1 V_12 ;
T_1 V_83 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_62 * V_63 = & V_26 -> V_63 ;
for (; ( V_2 -> V_6 - V_2 -> V_9 ) > 0 ; V_2 -> V_9 ++ ) {
V_83 = F_11 ( V_2 ) ;
V_12 = F_12 ( V_2 , V_82 ) ;
if ( ! ( V_12 & ( 1 << ( V_83 - 1 ) ) ) ) {
F_53 ( V_26 ,
V_83 - V_8 ) ;
V_63 -> V_142 += V_2 -> V_13 ( V_2 ,
F_15 ( V_49 , 0 ) )
& V_143 ;
V_63 -> V_144 ++ ;
F_37 ( V_26 , 0 , V_83 ) ;
} else {
break;
}
}
if ( ( ( V_2 -> V_6 & V_7 ) != 0 ) ||
( ( V_2 -> V_9 & V_7 ) == 0 ) )
F_50 ( V_26 ) ;
}
static int F_54 ( struct V_25 * V_26 , int V_145 )
{
T_1 V_146 = 0 ;
unsigned int V_147 , V_148 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
T_1 V_12 = F_12 ( V_2 , V_149 ) ;
for ( V_147 = V_59 ;
V_147 <= V_111 && V_145 > 0 ;
V_12 = F_12 ( V_2 , V_149 ) ,
V_147 ++ ) {
if ( V_12 & ( 1 << ( V_147 - 1 ) ) ) {
F_17 ( V_26 , 0 , V_147 , V_53 &
~ V_66 ) ;
V_148 = V_2 -> V_13 ( V_2 ,
F_15 ( V_49 , 0 ) ) ;
if ( V_148 & V_52 )
return V_146 ;
if ( V_148 & V_56 ) {
F_27 ( V_26 , 0 , V_147 ) ;
V_146 ++ ;
V_145 -- ;
continue;
}
if ( ! ( V_148 & V_61 ) )
continue;
F_31 ( V_26 , 0 , V_148 ) ;
if ( V_147 < V_60 )
F_24 ( V_26 , 0 ,
V_148 , V_147 ) ;
else if ( V_147 > V_60 )
F_26 ( V_26 , 0 ,
V_148 , V_147 ) ;
else if ( V_147 == V_60 )
F_25 ( V_26 ,
0 , V_148 ) ;
V_146 ++ ;
V_145 -- ;
}
}
return V_146 ;
}
static inline int F_55 ( struct V_1 * V_2 )
{
return ( V_2 -> V_96 . V_115 & V_150 ) &&
( V_2 -> V_151 & V_123 ) ;
}
static int F_56 ( struct V_25 * V_26 ,
enum V_152 V_153 )
{
unsigned int V_135 ;
unsigned int V_154 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_62 * V_63 = & V_26 -> V_63 ;
struct V_31 * V_155 ;
struct V_64 * V_65 ;
struct V_133 V_134 ;
V_65 = F_28 ( V_26 , & V_155 ) ;
if ( F_29 ( ! V_65 ) )
return 0 ;
F_51 ( V_26 , & V_134 ) ;
V_135 = V_2 -> V_13 ( V_2 , V_136 ) ;
V_154 = ( V_135 & V_156 ) >>
V_157 ;
switch ( V_153 ) {
case V_158 :
V_2 -> V_96 . V_159 . V_160 ++ ;
V_2 -> V_96 . V_124 = V_161 ;
V_155 -> V_36 |= V_68 ;
V_155 -> V_48 [ 1 ] = ( V_134 . V_140 > V_134 . V_137 ) ?
V_162 :
V_163 ;
V_155 -> V_48 [ 6 ] = V_134 . V_140 ;
V_155 -> V_48 [ 7 ] = V_134 . V_137 ;
break;
case V_164 :
V_2 -> V_96 . V_159 . V_165 ++ ;
V_2 -> V_96 . V_124 = V_166 ;
V_155 -> V_36 |= V_68 ;
if ( V_154 )
V_155 -> V_48 [ 1 ] |= V_167 ;
if ( V_134 . V_140 > 127 )
V_155 -> V_48 [ 1 ] |= V_168 ;
V_155 -> V_48 [ 6 ] = V_134 . V_140 ;
V_155 -> V_48 [ 7 ] = V_134 . V_137 ;
break;
case V_169 :
V_2 -> V_96 . V_124 = V_170 ;
V_155 -> V_36 |= V_171 ;
F_13 ( V_2 , V_127 ) ;
F_57 ( V_26 ) ;
break;
default:
break;
}
F_30 ( V_65 ) ;
V_63 -> V_75 ++ ;
V_63 -> V_76 += V_155 -> V_46 ;
return 1 ;
}
static int F_58 ( struct V_25 * V_26 ,
enum V_172 V_173 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_62 * V_63 = & V_26 -> V_63 ;
struct V_31 * V_155 ;
struct V_64 * V_65 ;
if ( V_173 == V_123 || V_173 == V_174 )
return 0 ;
V_65 = F_28 ( V_26 , & V_155 ) ;
if ( F_29 ( ! V_65 ) )
return 0 ;
V_2 -> V_96 . V_159 . V_175 ++ ;
V_63 -> V_70 ++ ;
V_155 -> V_36 |= V_176 | V_177 ;
V_155 -> V_48 [ 2 ] |= V_178 ;
switch ( V_173 ) {
case V_179 :
F_36 ( V_26 , L_6 ) ;
V_155 -> V_48 [ 2 ] |= V_180 ;
break;
case V_181 :
F_36 ( V_26 , L_7 ) ;
V_155 -> V_48 [ 2 ] |= V_182 ;
break;
case V_183 :
F_36 ( V_26 , L_8 ) ;
V_155 -> V_48 [ 3 ] |= ( V_184 |
V_185 ) ;
break;
case V_186 :
F_36 ( V_26 , L_9 ) ;
V_155 -> V_48 [ 2 ] |= V_187 ;
break;
case V_188 :
F_36 ( V_26 , L_10 ) ;
V_155 -> V_48 [ 2 ] |= V_189 ;
break;
case V_190 :
F_36 ( V_26 , L_11 ) ;
V_155 -> V_48 [ 3 ] |= ( V_191 |
V_192 ) ;
break;
default:
break;
}
V_2 -> V_19 ( V_2 , V_122 , V_123 ) ;
F_30 ( V_65 ) ;
V_63 -> V_75 ++ ;
V_63 -> V_76 += V_155 -> V_46 ;
return 1 ;
}
static int F_59 ( struct V_193 * V_194 , int V_145 )
{
T_2 V_195 ;
int V_173 = 0 ;
int V_196 = 0 ;
struct V_25 * V_26 = V_194 -> V_26 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_195 = V_2 -> V_195 ;
if ( ! V_195 )
goto V_197;
if ( V_195 == V_198 ) {
V_2 -> V_151 = V_2 -> V_13 ( V_2 ,
V_122 ) ;
if ( V_2 -> V_151 & V_199 )
V_2 -> V_19 ( V_2 , V_122 ,
V_2 -> V_151 & ~ V_199 ) ;
if ( V_2 -> V_151 & V_200 )
V_2 -> V_19 ( V_2 , V_122 ,
V_2 -> V_151 & ~ V_200 ) ;
if ( ( V_2 -> V_151 & V_201 ) &&
( ! ( V_2 -> V_202 & V_201 ) ) ) {
F_36 ( V_26 , L_12 ) ;
V_196 += F_56 ( V_26 ,
V_158 ) ;
}
if ( ( V_2 -> V_151 & V_203 ) &&
( ! ( V_2 -> V_202 & V_203 ) ) ) {
F_36 ( V_26 , L_13 ) ;
V_196 += F_56 ( V_26 ,
V_164 ) ;
}
if ( ( V_2 -> V_151 & V_204 ) &&
( ! ( V_2 -> V_202 & V_204 ) ) ) {
F_36 ( V_26 , L_14 ) ;
V_196 += F_56 ( V_26 ,
V_169 ) ;
}
if ( ( ! ( V_2 -> V_151 & V_204 ) ) &&
( V_2 -> V_202 & V_204 ) ) {
F_36 ( V_26 , L_15 ) ;
V_2 -> V_96 . V_124 = V_125 ;
}
if ( ( ! ( V_2 -> V_151 & V_203 ) ) &&
( V_2 -> V_202 & V_203 ) ) {
F_36 ( V_26 , L_16 ) ;
V_2 -> V_96 . V_124 = V_125 ;
}
V_2 -> V_202 = V_2 -> V_151 ;
V_173 = F_55 ( V_2 ) ;
if ( V_173 )
V_196 += F_58 ( V_26 , V_173 ) ;
} else if ( ( V_195 >= V_59 ) &&
( V_195 <= V_111 ) ) {
V_196 += F_54 ( V_26 , ( V_145 - V_196 ) ) ;
} else if ( ( V_195 >= V_8 ) &&
( V_195 <= V_205 ) ) {
F_52 ( V_26 ) ;
}
V_197:
if ( V_196 < V_145 ) {
F_60 ( V_194 ) ;
F_13 ( V_2 , V_126 ) ;
}
return V_196 ;
}
static T_5 F_61 ( int V_206 , void * V_207 )
{
struct V_25 * V_26 = (struct V_25 * ) V_207 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_2 -> V_195 = V_2 -> V_13 ( V_2 , V_208 ) ;
if ( ! V_2 -> V_195 )
return V_209 ;
F_13 ( V_2 , V_127 ) ;
F_62 ( & V_2 -> V_194 ) ;
return V_210 ;
}
static int F_63 ( struct V_25 * V_26 )
{
int V_211 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
F_5 ( V_2 ) ;
F_9 ( V_2 , true ) ;
V_211 = F_64 ( V_26 ) ;
if ( V_211 ) {
F_20 ( V_26 , L_17 ) ;
goto V_212;
}
V_211 = F_65 ( V_26 -> V_206 , & F_61 , V_213 , V_26 -> V_214 ,
V_26 ) ;
if ( V_211 < 0 ) {
F_20 ( V_26 , L_18 ) ;
goto V_215;
}
F_66 ( & V_2 -> V_194 ) ;
F_47 ( V_26 ) ;
F_67 ( V_26 ) ;
return 0 ;
V_215:
F_68 ( V_26 ) ;
V_212:
F_9 ( V_2 , false ) ;
F_7 ( V_2 ) ;
return V_211 ;
}
static int F_69 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
F_42 ( V_26 ) ;
F_70 ( & V_2 -> V_194 ) ;
F_48 ( V_26 ) ;
F_71 ( V_26 -> V_206 , V_26 ) ;
F_68 ( V_26 ) ;
F_9 ( V_2 , false ) ;
F_7 ( V_2 ) ;
return 0 ;
}
struct V_25 * F_72 ( void )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
V_26 = F_73 ( sizeof( struct V_1 ) , V_216 ) ;
if ( ! V_26 )
return NULL ;
V_2 = F_18 ( V_26 ) ;
F_74 ( V_26 , & V_2 -> V_194 , F_59 , V_217 ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_96 . V_218 = & V_219 ;
V_2 -> V_96 . V_220 = F_49 ;
V_2 -> V_96 . V_221 = F_51 ;
V_2 -> V_96 . V_222 = V_117 |
V_116 |
V_150 ;
return V_26 ;
}
int F_75 ( struct V_25 * V_26 )
{
T_1 V_12 ;
unsigned long V_223 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
if ( ! ( V_26 -> V_34 & V_224 ) )
return 0 ;
F_76 ( V_2 -> type != V_225 ) ;
V_12 = V_2 -> V_13 ( V_2 , V_226 ) ;
V_12 |= V_227 ;
V_2 -> V_19 ( V_2 , V_226 , V_12 ) ;
V_223 = V_228 + F_77 ( V_229 ) ;
while ( ! ( V_2 -> V_13 ( V_2 , V_122 ) & V_230 ) &&
F_78 ( V_223 , V_228 ) )
F_79 () ;
if ( F_78 ( V_228 , V_223 ) )
return - V_231 ;
F_48 ( V_26 ) ;
F_9 ( V_2 , false ) ;
F_7 ( V_2 ) ;
return 0 ;
}
int F_80 ( struct V_25 * V_26 )
{
T_1 V_12 ;
unsigned long V_223 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
if ( ! ( V_26 -> V_34 & V_224 ) )
return 0 ;
F_76 ( V_2 -> type != V_225 ) ;
F_5 ( V_2 ) ;
F_9 ( V_2 , true ) ;
V_12 = V_2 -> V_13 ( V_2 , V_226 ) ;
V_12 &= ~ V_227 ;
V_2 -> V_19 ( V_2 , V_226 , V_12 ) ;
V_12 = V_2 -> V_13 ( V_2 , V_15 ) ;
V_12 &= ~ V_107 ;
V_2 -> V_19 ( V_2 , V_15 , V_12 ) ;
V_223 = V_228 + F_77 ( V_229 ) ;
while ( ( V_2 -> V_13 ( V_2 , V_122 ) & V_230 ) &&
F_78 ( V_223 , V_228 ) )
F_79 () ;
if ( F_78 ( V_228 , V_223 ) )
return - V_231 ;
F_47 ( V_26 ) ;
return 0 ;
}
void F_81 ( struct V_25 * V_26 )
{
F_82 ( V_26 ) ;
}
int F_83 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
int V_211 ;
F_1 ( V_2 ) ;
V_26 -> V_34 |= V_232 ;
V_26 -> V_233 = & V_234 ;
V_211 = F_84 ( V_26 ) ;
if ( V_211 )
F_3 ( V_2 ) ;
return V_211 ;
}
void F_85 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
F_86 ( V_26 ) ;
F_3 ( V_2 ) ;
}
