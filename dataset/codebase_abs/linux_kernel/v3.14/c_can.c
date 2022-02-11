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
F_34 ( V_26 , V_77 ) ;
return 0 ;
}
static void F_35 ( struct V_25 * V_26 , int V_20 ,
int V_27 , unsigned int V_28 ,
unsigned int V_35 , unsigned int V_78 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_79 , V_20 ) ,
F_19 ( V_28 ) ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_80 , V_20 ) ,
F_23 ( V_28 ) | F_36 ( 13 ) ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_44 , V_20 ) ,
F_19 ( V_35 ) ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_45 , V_20 ) ,
( V_43 | F_23 ( V_35 ) ) ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_49 , V_20 ) , V_78 ) ;
F_21 ( V_26 , V_20 , V_27 , V_53 & ~ V_66 ) ;
F_37 ( V_26 , L_4 , V_27 ,
F_12 ( V_2 , V_81 ) ) ;
}
static void F_38 ( struct V_25 * V_26 , int V_20 , int V_27 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_44 , V_20 ) , 0 ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_45 , V_20 ) , 0 ) ;
V_2 -> V_19 ( V_2 , F_15 ( V_49 , V_20 ) , 0 ) ;
F_21 ( V_26 , V_20 , V_27 , V_82 | V_58 ) ;
F_37 ( V_26 , L_4 , V_27 ,
F_12 ( V_2 , V_81 ) ) ;
}
static inline int F_39 ( struct V_1 * V_2 , int V_27 )
{
int V_12 = F_12 ( V_2 , V_83 ) ;
if ( V_12 & ( 1 << ( V_27 - 1 ) ) )
return 1 ;
return 0 ;
}
static T_3 F_40 ( struct V_64 * V_65 ,
struct V_25 * V_26 )
{
T_1 V_84 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_31 * V_32 = (struct V_31 * ) V_65 -> V_48 ;
if ( F_41 ( V_26 , V_65 ) )
return V_85 ;
V_84 = F_10 ( V_2 ) ;
F_22 ( V_26 , 0 , V_32 , V_84 ) ;
F_42 ( V_65 , V_26 , V_84 - V_8 ) ;
V_2 -> V_6 ++ ;
if ( F_39 ( V_2 , F_10 ( V_2 ) ) ||
( V_2 -> V_6 & V_7 ) == 0 )
F_43 ( V_26 ) ;
return V_85 ;
}
static int F_44 ( struct V_25 * V_26 )
{
unsigned int V_86 , V_87 , V_88 ;
T_4 V_89 , V_90 , V_91 , V_92 , V_93 ;
T_1 V_94 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
const struct V_95 * V_96 = & V_2 -> V_97 . V_98 ;
V_94 = V_96 -> V_89 - 1 ;
V_89 = V_94 & V_99 ;
V_90 = V_94 >> 6 ;
V_91 = V_96 -> V_91 - 1 ;
V_92 = V_96 -> V_100 + V_96 -> V_101 - 1 ;
V_93 = V_96 -> V_102 - 1 ;
V_86 = V_89 | ( V_91 << V_103 ) | ( V_92 << V_104 ) |
( V_93 << V_105 ) ;
V_87 = V_90 & V_106 ;
F_45 ( V_26 ,
L_5 , V_86 , V_87 ) ;
V_88 = V_2 -> V_13 ( V_2 , V_15 ) ;
V_2 -> V_19 ( V_2 , V_15 ,
V_88 | V_107 | V_108 ) ;
V_2 -> V_19 ( V_2 , V_109 , V_86 ) ;
V_2 -> V_19 ( V_2 , V_110 , V_87 ) ;
V_2 -> V_19 ( V_2 , V_15 , V_88 ) ;
return 0 ;
}
static void F_46 ( struct V_25 * V_26 )
{
int V_33 ;
for ( V_33 = V_59 ; V_33 <= V_111 ; V_33 ++ )
F_38 ( V_26 , 0 , V_33 ) ;
for ( V_33 = V_59 ; V_33 < V_112 ; V_33 ++ )
F_35 ( V_26 , 0 , V_33 , 0 , 0 ,
( V_113 | V_114 ) & ~ V_52 ) ;
F_35 ( V_26 , 0 , V_112 , 0 , 0 ,
V_52 | V_113 | V_114 ) ;
}
static void F_47 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_2 -> V_19 ( V_2 , V_15 ,
V_115 ) ;
if ( ( V_2 -> V_97 . V_116 & V_117 ) &&
( V_2 -> V_97 . V_116 & V_118 ) ) {
V_2 -> V_19 ( V_2 , V_15 , V_17 |
V_16 | V_18 | V_119 ) ;
V_2 -> V_19 ( V_2 , V_120 ,
V_121 | V_122 ) ;
} else if ( V_2 -> V_97 . V_116 & V_118 ) {
V_2 -> V_19 ( V_2 , V_15 , V_17 |
V_16 | V_18 | V_119 ) ;
V_2 -> V_19 ( V_2 , V_120 , V_121 ) ;
} else if ( V_2 -> V_97 . V_116 & V_117 ) {
V_2 -> V_19 ( V_2 , V_15 , V_17 |
V_16 | V_18 | V_119 ) ;
V_2 -> V_19 ( V_2 , V_120 , V_122 ) ;
} else
V_2 -> V_19 ( V_2 , V_15 ,
V_17 | V_16 | V_18 ) ;
F_46 ( V_26 ) ;
V_2 -> V_19 ( V_2 , V_123 , V_124 ) ;
F_44 ( V_26 ) ;
}
static void F_48 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
F_47 ( V_26 ) ;
V_2 -> V_97 . V_125 = V_126 ;
V_2 -> V_6 = V_2 -> V_9 = 0 ;
F_13 ( V_2 , V_127 ) ;
}
static void F_49 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
F_13 ( V_2 , V_128 ) ;
V_2 -> V_97 . V_125 = V_129 ;
}
static int F_50 ( struct V_25 * V_26 , enum V_130 V_131 )
{
switch ( V_131 ) {
case V_132 :
F_48 ( V_26 ) ;
F_51 ( V_26 ) ;
break;
default:
return - V_133 ;
}
return 0 ;
}
static int F_52 ( const struct V_25 * V_26 ,
struct V_134 * V_135 )
{
unsigned int V_136 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_136 = V_2 -> V_13 ( V_2 , V_137 ) ;
V_135 -> V_138 = ( V_136 & V_139 ) >>
V_140 ;
V_135 -> V_141 = V_136 & V_142 ;
return 0 ;
}
static int F_53 ( const struct V_25 * V_26 ,
struct V_134 * V_135 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
int V_143 ;
F_5 ( V_2 ) ;
V_143 = F_52 ( V_26 , V_135 ) ;
F_7 ( V_2 ) ;
return V_143 ;
}
static void F_54 ( struct V_25 * V_26 )
{
T_1 V_12 ;
T_1 V_84 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_62 * V_63 = & V_26 -> V_63 ;
for (; ( V_2 -> V_6 - V_2 -> V_9 ) > 0 ; V_2 -> V_9 ++ ) {
V_84 = F_11 ( V_2 ) ;
V_12 = F_12 ( V_2 , V_83 ) ;
if ( ! ( V_12 & ( 1 << ( V_84 - 1 ) ) ) ) {
F_55 ( V_26 ,
V_84 - V_8 ) ;
F_17 ( V_26 , 0 , V_84 , V_53 ) ;
V_63 -> V_144 += V_2 -> V_13 ( V_2 ,
F_15 ( V_49 , 0 ) )
& V_145 ;
V_63 -> V_146 ++ ;
F_34 ( V_26 , V_147 ) ;
F_38 ( V_26 , 0 , V_84 ) ;
} else {
break;
}
}
if ( ( ( V_2 -> V_6 & V_7 ) != 0 ) ||
( ( V_2 -> V_9 & V_7 ) == 0 ) )
F_51 ( V_26 ) ;
}
static int F_56 ( struct V_25 * V_26 , int V_148 )
{
T_1 V_149 = 0 ;
unsigned int V_150 , V_151 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
T_2 V_12 ;
F_57 ( V_112 > 16 ,
L_6 ) ;
while ( V_148 > 0 && ( V_12 = V_2 -> V_13 ( V_2 , V_152 ) ) ) {
while ( ( V_150 = F_58 ( V_12 ) ) && V_148 > 0 ) {
V_12 &= ~ F_36 ( V_150 - 1 ) ;
F_17 ( V_26 , 0 , V_150 , V_53 &
~ V_66 ) ;
V_151 = V_2 -> V_13 ( V_2 ,
F_15 ( V_49 , 0 ) ) ;
if ( V_151 & V_56 ) {
F_27 ( V_26 , 0 , V_150 ) ;
V_149 ++ ;
V_148 -- ;
continue;
}
if ( V_151 & V_52 )
return V_149 ;
if ( ! ( V_151 & V_61 ) )
continue;
F_31 ( V_26 , 0 , V_151 ) ;
if ( V_150 < V_60 )
F_24 ( V_26 , 0 ,
V_151 , V_150 ) ;
else if ( V_150 > V_60 )
F_26 ( V_26 , 0 ,
V_151 , V_150 ) ;
else if ( V_150 == V_60 )
F_25 ( V_26 ,
0 , V_151 ) ;
V_149 ++ ;
V_148 -- ;
}
}
return V_149 ;
}
static inline int F_59 ( struct V_1 * V_2 )
{
return ( V_2 -> V_97 . V_116 & V_153 ) &&
( V_2 -> V_154 & V_124 ) ;
}
static int F_60 ( struct V_25 * V_26 ,
enum V_155 V_156 )
{
unsigned int V_136 ;
unsigned int V_157 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_62 * V_63 = & V_26 -> V_63 ;
struct V_31 * V_158 ;
struct V_64 * V_65 ;
struct V_134 V_135 ;
V_65 = F_28 ( V_26 , & V_158 ) ;
if ( F_29 ( ! V_65 ) )
return 0 ;
F_52 ( V_26 , & V_135 ) ;
V_136 = V_2 -> V_13 ( V_2 , V_137 ) ;
V_157 = ( V_136 & V_159 ) >>
V_160 ;
switch ( V_156 ) {
case V_161 :
V_2 -> V_97 . V_162 . V_163 ++ ;
V_2 -> V_97 . V_125 = V_164 ;
V_158 -> V_36 |= V_68 ;
V_158 -> V_48 [ 1 ] = ( V_135 . V_141 > V_135 . V_138 ) ?
V_165 :
V_166 ;
V_158 -> V_48 [ 6 ] = V_135 . V_141 ;
V_158 -> V_48 [ 7 ] = V_135 . V_138 ;
break;
case V_167 :
V_2 -> V_97 . V_162 . V_168 ++ ;
V_2 -> V_97 . V_125 = V_169 ;
V_158 -> V_36 |= V_68 ;
if ( V_157 )
V_158 -> V_48 [ 1 ] |= V_170 ;
if ( V_135 . V_141 > 127 )
V_158 -> V_48 [ 1 ] |= V_171 ;
V_158 -> V_48 [ 6 ] = V_135 . V_141 ;
V_158 -> V_48 [ 7 ] = V_135 . V_138 ;
break;
case V_172 :
V_2 -> V_97 . V_125 = V_173 ;
V_158 -> V_36 |= V_174 ;
F_13 ( V_2 , V_128 ) ;
F_61 ( V_26 ) ;
break;
default:
break;
}
F_30 ( V_65 ) ;
V_63 -> V_75 ++ ;
V_63 -> V_76 += V_158 -> V_46 ;
return 1 ;
}
static int F_62 ( struct V_25 * V_26 ,
enum V_175 V_176 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
struct V_62 * V_63 = & V_26 -> V_63 ;
struct V_31 * V_158 ;
struct V_64 * V_65 ;
if ( V_176 == V_124 || V_176 == V_177 )
return 0 ;
V_65 = F_28 ( V_26 , & V_158 ) ;
if ( F_29 ( ! V_65 ) )
return 0 ;
V_2 -> V_97 . V_162 . V_178 ++ ;
V_63 -> V_70 ++ ;
V_158 -> V_36 |= V_179 | V_180 ;
V_158 -> V_48 [ 2 ] |= V_181 ;
switch ( V_176 ) {
case V_182 :
F_37 ( V_26 , L_7 ) ;
V_158 -> V_48 [ 2 ] |= V_183 ;
break;
case V_184 :
F_37 ( V_26 , L_8 ) ;
V_158 -> V_48 [ 2 ] |= V_185 ;
break;
case V_186 :
F_37 ( V_26 , L_9 ) ;
V_158 -> V_48 [ 3 ] |= ( V_187 |
V_188 ) ;
break;
case V_189 :
F_37 ( V_26 , L_10 ) ;
V_158 -> V_48 [ 2 ] |= V_190 ;
break;
case V_191 :
F_37 ( V_26 , L_11 ) ;
V_158 -> V_48 [ 2 ] |= V_192 ;
break;
case V_193 :
F_37 ( V_26 , L_12 ) ;
V_158 -> V_48 [ 3 ] |= ( V_194 |
V_195 ) ;
break;
default:
break;
}
V_2 -> V_19 ( V_2 , V_123 , V_124 ) ;
F_30 ( V_65 ) ;
V_63 -> V_75 ++ ;
V_63 -> V_76 += V_158 -> V_46 ;
return 1 ;
}
static int F_63 ( struct V_196 * V_197 , int V_148 )
{
T_2 V_198 ;
int V_176 = 0 ;
int V_199 = 0 ;
struct V_25 * V_26 = V_197 -> V_26 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_198 = V_2 -> V_198 ;
if ( ! V_198 )
goto V_200;
if ( V_198 == V_201 ) {
V_2 -> V_154 = V_2 -> V_13 ( V_2 ,
V_123 ) ;
if ( V_2 -> V_154 & V_202 )
V_2 -> V_19 ( V_2 , V_123 ,
V_2 -> V_154 & ~ V_202 ) ;
if ( V_2 -> V_154 & V_203 )
V_2 -> V_19 ( V_2 , V_123 ,
V_2 -> V_154 & ~ V_203 ) ;
if ( ( V_2 -> V_154 & V_204 ) &&
( ! ( V_2 -> V_205 & V_204 ) ) ) {
F_37 ( V_26 , L_13 ) ;
V_199 += F_60 ( V_26 ,
V_161 ) ;
}
if ( ( V_2 -> V_154 & V_206 ) &&
( ! ( V_2 -> V_205 & V_206 ) ) ) {
F_37 ( V_26 , L_14 ) ;
V_199 += F_60 ( V_26 ,
V_167 ) ;
}
if ( ( V_2 -> V_154 & V_207 ) &&
( ! ( V_2 -> V_205 & V_207 ) ) ) {
F_37 ( V_26 , L_15 ) ;
V_199 += F_60 ( V_26 ,
V_172 ) ;
}
if ( ( ! ( V_2 -> V_154 & V_207 ) ) &&
( V_2 -> V_205 & V_207 ) ) {
F_37 ( V_26 , L_16 ) ;
V_2 -> V_97 . V_125 = V_126 ;
}
if ( ( ! ( V_2 -> V_154 & V_206 ) ) &&
( V_2 -> V_205 & V_206 ) ) {
F_37 ( V_26 , L_17 ) ;
V_2 -> V_97 . V_125 = V_126 ;
}
V_2 -> V_205 = V_2 -> V_154 ;
V_176 = F_59 ( V_2 ) ;
if ( V_176 )
V_199 += F_62 ( V_26 , V_176 ) ;
} else if ( ( V_198 >= V_59 ) &&
( V_198 <= V_112 ) ) {
V_199 += F_56 ( V_26 , ( V_148 - V_199 ) ) ;
} else if ( ( V_198 >= V_8 ) &&
( V_198 <= V_208 ) ) {
F_54 ( V_26 ) ;
}
V_200:
if ( V_199 < V_148 ) {
F_64 ( V_197 ) ;
F_13 ( V_2 , V_127 ) ;
}
return V_199 ;
}
static T_5 F_65 ( int V_209 , void * V_210 )
{
struct V_25 * V_26 = (struct V_25 * ) V_210 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
V_2 -> V_198 = V_2 -> V_13 ( V_2 , V_211 ) ;
if ( ! V_2 -> V_198 )
return V_212 ;
F_13 ( V_2 , V_128 ) ;
F_66 ( & V_2 -> V_197 ) ;
return V_213 ;
}
static int F_67 ( struct V_25 * V_26 )
{
int V_143 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
F_5 ( V_2 ) ;
F_9 ( V_2 , true ) ;
V_143 = F_68 ( V_26 ) ;
if ( V_143 ) {
F_20 ( V_26 , L_18 ) ;
goto V_214;
}
V_143 = F_69 ( V_26 -> V_209 , & F_65 , V_215 , V_26 -> V_216 ,
V_26 ) ;
if ( V_143 < 0 ) {
F_20 ( V_26 , L_19 ) ;
goto V_217;
}
F_70 ( & V_2 -> V_197 ) ;
F_34 ( V_26 , V_218 ) ;
F_48 ( V_26 ) ;
F_71 ( V_26 ) ;
return 0 ;
V_217:
F_72 ( V_26 ) ;
V_214:
F_9 ( V_2 , false ) ;
F_7 ( V_2 ) ;
return V_143 ;
}
static int F_73 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
F_43 ( V_26 ) ;
F_74 ( & V_2 -> V_197 ) ;
F_49 ( V_26 ) ;
F_75 ( V_26 -> V_209 , V_26 ) ;
F_72 ( V_26 ) ;
F_9 ( V_2 , false ) ;
F_7 ( V_2 ) ;
F_34 ( V_26 , V_219 ) ;
return 0 ;
}
struct V_25 * F_76 ( void )
{
struct V_25 * V_26 ;
struct V_1 * V_2 ;
V_26 = F_77 ( sizeof( struct V_1 ) , V_220 ) ;
if ( ! V_26 )
return NULL ;
V_2 = F_18 ( V_26 ) ;
F_78 ( V_26 , & V_2 -> V_197 , F_63 , V_221 ) ;
V_2 -> V_26 = V_26 ;
V_2 -> V_97 . V_222 = & V_223 ;
V_2 -> V_97 . V_224 = F_50 ;
V_2 -> V_97 . V_225 = F_53 ;
V_2 -> V_97 . V_226 = V_118 |
V_117 |
V_153 ;
return V_26 ;
}
int F_79 ( struct V_25 * V_26 )
{
T_1 V_12 ;
unsigned long V_227 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
if ( ! ( V_26 -> V_34 & V_228 ) )
return 0 ;
F_80 ( V_2 -> type != V_229 ) ;
V_12 = V_2 -> V_13 ( V_2 , V_230 ) ;
V_12 |= V_231 ;
V_2 -> V_19 ( V_2 , V_230 , V_12 ) ;
V_227 = V_232 + F_81 ( V_233 ) ;
while ( ! ( V_2 -> V_13 ( V_2 , V_123 ) & V_234 ) &&
F_82 ( V_227 , V_232 ) )
F_83 () ;
if ( F_82 ( V_232 , V_227 ) )
return - V_235 ;
F_49 ( V_26 ) ;
F_9 ( V_2 , false ) ;
F_7 ( V_2 ) ;
return 0 ;
}
int F_84 ( struct V_25 * V_26 )
{
T_1 V_12 ;
unsigned long V_227 ;
struct V_1 * V_2 = F_18 ( V_26 ) ;
if ( ! ( V_26 -> V_34 & V_228 ) )
return 0 ;
F_80 ( V_2 -> type != V_229 ) ;
F_5 ( V_2 ) ;
F_9 ( V_2 , true ) ;
V_12 = V_2 -> V_13 ( V_2 , V_230 ) ;
V_12 &= ~ V_231 ;
V_2 -> V_19 ( V_2 , V_230 , V_12 ) ;
V_12 = V_2 -> V_13 ( V_2 , V_15 ) ;
V_12 &= ~ V_108 ;
V_2 -> V_19 ( V_2 , V_15 , V_12 ) ;
V_227 = V_232 + F_81 ( V_233 ) ;
while ( ( V_2 -> V_13 ( V_2 , V_123 ) & V_234 ) &&
F_82 ( V_227 , V_232 ) )
F_83 () ;
if ( F_82 ( V_232 , V_227 ) )
return - V_235 ;
F_48 ( V_26 ) ;
return 0 ;
}
void F_85 ( struct V_25 * V_26 )
{
F_86 ( V_26 ) ;
}
int F_87 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
int V_143 ;
F_1 ( V_2 ) ;
V_26 -> V_34 |= V_236 ;
V_26 -> V_237 = & V_238 ;
V_143 = F_88 ( V_26 ) ;
if ( V_143 )
F_3 ( V_2 ) ;
else
F_89 ( V_26 ) ;
return V_143 ;
}
void F_90 ( struct V_25 * V_26 )
{
struct V_1 * V_2 = F_18 ( V_26 ) ;
F_91 ( V_26 ) ;
F_3 ( V_2 ) ;
}
