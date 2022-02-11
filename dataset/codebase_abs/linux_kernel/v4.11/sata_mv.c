static inline void F_1 ( unsigned long V_1 , void T_1 * V_2 )
{
F_2 ( V_1 , V_2 ) ;
( void ) F_3 ( V_2 ) ;
}
static inline unsigned int F_4 ( unsigned int V_3 )
{
return V_3 >> V_4 ;
}
static inline unsigned int F_5 ( unsigned int V_3 )
{
return V_3 & V_5 ;
}
static inline void T_1 * F_6 ( void T_1 * V_6 , unsigned int V_7 )
{
return ( V_6 + V_8 + ( V_7 * V_9 ) ) ;
}
static inline void T_1 * F_7 ( void T_1 * V_6 ,
unsigned int V_3 )
{
return F_6 ( V_6 , F_4 ( V_3 ) ) ;
}
static inline void T_1 * F_8 ( void T_1 * V_6 , unsigned int V_3 )
{
return F_7 ( V_6 , V_3 ) +
V_10 +
( F_5 ( V_3 ) * V_11 ) ;
}
static void T_1 * F_9 ( void T_1 * V_12 , unsigned int V_3 )
{
void T_1 * V_13 = F_7 ( V_12 , V_3 ) ;
unsigned long V_14 = ( F_5 ( V_3 ) + 1 ) * 0x100UL ;
return V_13 + V_14 ;
}
static inline void T_1 * F_10 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
return V_18 -> V_6 ;
}
static inline void T_1 * F_11 ( struct V_20 * V_21 )
{
return F_8 ( F_10 ( V_21 -> V_16 ) , V_21 -> V_22 ) ;
}
static inline int F_12 ( unsigned long V_23 )
{
return ( ( V_23 & V_24 ) ? 2 : 1 ) ;
}
static void F_13 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
V_27 -> V_28 . V_29 = F_3 ( V_25 + V_30 ) ;
V_27 -> V_28 . V_31 = F_3 ( V_25 + V_32 ) ;
V_27 -> V_28 . V_33 = F_3 ( V_25 + V_34 ) ;
V_27 -> V_28 . V_35 = F_3 ( V_25 + V_36 ) ;
}
static inline void F_14 ( void T_1 * V_2 , T_2 * V_37 , T_2 V_38 )
{
if ( V_38 != * V_37 ) {
unsigned long V_39 ;
* V_37 = V_38 ;
V_39 = ( unsigned long ) V_2 & 0xffff ;
if ( V_39 >= 0x300 && V_39 <= 0x33c ) {
V_39 &= 0x000f ;
if ( V_39 == 0x4 || V_39 == 0xc ) {
F_1 ( V_38 , V_2 ) ;
return;
}
}
F_2 ( V_38 , V_2 ) ;
}
}
static void F_15 ( void T_1 * V_25 ,
struct V_17 * V_18 ,
struct V_26 * V_27 )
{
T_2 V_40 ;
V_27 -> V_41 &= V_42 ;
V_40 = V_27 -> V_41 << V_43 ;
F_16 ( V_27 -> V_44 & 0x3ff ) ;
F_2 ( ( V_27 -> V_44 >> 16 ) >> 16 , V_25 + V_45 ) ;
F_1 ( ( V_27 -> V_44 & V_46 ) | V_40 ,
V_25 + V_47 ) ;
F_1 ( V_40 , V_25 + V_48 ) ;
V_27 -> V_49 &= V_42 ;
V_40 = V_27 -> V_49 << V_50 ;
F_16 ( V_27 -> V_51 & 0xff ) ;
F_2 ( ( V_27 -> V_51 >> 16 ) >> 16 , V_25 + V_52 ) ;
F_1 ( V_40 , V_25 + V_53 ) ;
F_1 ( ( V_27 -> V_51 & V_54 ) | V_40 ,
V_25 + V_55 ) ;
}
static void F_17 ( T_2 V_56 , struct V_17 * V_18 )
{
if ( V_56 & ( V_57 | V_58 ) )
V_56 &= ~ V_59 ;
if ( V_56 & ( V_57 | V_60 ) )
V_56 &= ~ V_61 ;
F_1 ( V_56 , V_18 -> V_62 ) ;
}
static void F_18 ( struct V_15 * V_16 ,
T_2 V_63 , T_2 V_64 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
T_2 V_65 , V_66 ;
V_65 = V_18 -> V_67 ;
V_66 = ( V_65 & ~ V_63 ) | V_64 ;
if ( V_66 != V_65 ) {
V_18 -> V_67 = V_66 ;
F_17 ( V_66 , V_18 ) ;
}
}
static void F_19 ( struct V_20 * V_21 ,
unsigned int V_68 )
{
unsigned int V_69 , V_70 , V_3 = V_21 -> V_22 ;
T_2 V_63 , V_64 ;
F_20 ( V_3 , V_69 , V_70 ) ;
V_63 = ( V_71 | V_72 ) << V_69 ;
V_64 = V_68 << V_69 ;
F_18 ( V_21 -> V_16 , V_63 , V_64 ) ;
}
static void F_21 ( struct V_20 * V_21 ,
void T_1 * V_25 ,
unsigned int V_73 )
{
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
int V_70 = F_5 ( V_21 -> V_22 ) ;
void T_1 * V_13 = F_7 (
F_10 ( V_21 -> V_16 ) , V_21 -> V_22 ) ;
T_2 V_74 ;
F_1 ( 0 , V_25 + V_75 ) ;
V_74 = ~ ( ( V_76 | V_77 ) << V_70 ) ;
F_1 ( V_74 , V_13 + V_78 ) ;
if ( F_22 ( V_18 ) )
F_1 ( 0 , V_25 + V_79 ) ;
F_19 ( V_21 , V_73 ) ;
}
static void F_23 ( struct V_15 * V_16 ,
unsigned int V_80 , unsigned int V_81 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 , * V_13 ;
T_2 V_82 = 0 ;
unsigned long V_83 ;
unsigned int V_84 , V_85 = V_18 -> V_86 > V_87 ;
const T_2 V_88 = V_58 | V_60 |
V_57 ;
if ( ! V_81 || ! V_80 ) {
V_84 = V_80 = 0 ;
} else {
V_84 = V_81 * V_89 ;
if ( V_84 > V_90 )
V_84 = V_90 ;
if ( V_80 > V_91 )
V_80 = V_91 ;
}
F_24 ( & V_16 -> V_92 , V_83 ) ;
F_18 ( V_16 , V_88 , 0 ) ;
if ( V_85 && ! F_25 ( V_18 ) ) {
F_2 ( V_84 , V_12 + V_93 ) ;
F_2 ( V_80 , V_12 + V_94 ) ;
F_2 ( ~ V_95 , V_12 + V_96 ) ;
if ( V_80 )
V_82 = V_57 ;
V_84 = V_80 = 0 ;
}
V_13 = F_7 ( V_12 , 0 ) ;
F_2 ( V_84 , V_13 + V_97 ) ;
F_2 ( V_80 , V_13 + V_98 ) ;
F_2 ( ~ V_99 , V_13 + V_78 ) ;
if ( V_80 )
V_82 |= V_58 ;
if ( V_85 ) {
V_13 = F_7 ( V_12 , V_87 ) ;
F_2 ( V_84 , V_13 + V_97 ) ;
F_2 ( V_80 , V_13 + V_98 ) ;
F_2 ( ~ V_99 , V_13 + V_78 ) ;
if ( V_80 )
V_82 |= V_60 ;
}
F_18 ( V_16 , 0 , V_82 ) ;
F_26 ( & V_16 -> V_92 , V_83 ) ;
}
static void F_27 ( struct V_20 * V_21 , void T_1 * V_25 ,
struct V_26 * V_27 , T_3 V_100 )
{
int V_101 = ( V_100 == V_102 ) ;
if ( V_27 -> V_103 & V_104 ) {
int V_105 = ( ( V_27 -> V_103 & V_106 ) != 0 ) ;
if ( V_101 != V_105 )
F_28 ( V_21 ) ;
}
if ( ! ( V_27 -> V_103 & V_104 ) ) {
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
F_29 ( V_21 , V_101 , 1 ) ;
F_15 ( V_25 , V_18 , V_27 ) ;
F_21 ( V_21 , V_25 , V_71 | V_72 ) ;
F_1 ( V_107 , V_25 + V_108 ) ;
V_27 -> V_103 |= V_104 ;
}
}
static void F_30 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
const T_2 V_109 = ( V_110 | V_111 ) ;
const int V_112 = 5 , V_113 = ( 15 * 1000 / V_112 ) ;
int V_114 ;
for ( V_114 = 0 ; V_114 < V_113 ; ++ V_114 ) {
T_2 V_115 = F_3 ( V_25 + V_116 ) ;
if ( ( V_115 & V_109 ) == V_109 )
break;
F_31 ( V_112 ) ;
}
}
static int F_32 ( void T_1 * V_25 )
{
int V_114 ;
F_1 ( V_117 , V_25 + V_108 ) ;
for ( V_114 = 10000 ; V_114 > 0 ; V_114 -- ) {
T_2 V_118 = F_3 ( V_25 + V_108 ) ;
if ( ! ( V_118 & V_107 ) )
return 0 ;
F_31 ( 10 ) ;
}
return - V_119 ;
}
static int F_28 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
int V_120 = 0 ;
if ( ! ( V_27 -> V_103 & V_104 ) )
return 0 ;
V_27 -> V_103 &= ~ V_104 ;
F_30 ( V_21 ) ;
if ( F_32 ( V_25 ) ) {
F_33 ( V_21 , L_1 ) ;
V_120 = - V_119 ;
}
F_29 ( V_21 , 0 , 0 ) ;
return V_120 ;
}
static void F_34 ( void T_1 * V_121 , unsigned V_122 )
{
int V_123 , V_124 ;
for ( V_123 = 0 ; V_123 < V_122 ; ) {
F_35 ( L_2 , V_121 + V_123 ) ;
for ( V_124 = 0 ; V_123 < V_122 && V_124 < 4 ; V_124 ++ ) {
F_36 ( L_3 , F_3 ( V_121 + V_123 ) ) ;
V_123 += sizeof( T_2 ) ;
}
F_36 ( L_4 ) ;
}
}
static void F_37 ( struct V_125 * V_126 , unsigned V_122 )
{
#ifdef F_38
int V_123 , V_124 ;
T_2 V_127 ;
for ( V_123 = 0 ; V_123 < V_122 ; ) {
F_35 ( L_5 , V_123 ) ;
for ( V_124 = 0 ; V_123 < V_122 && V_124 < 4 ; V_124 ++ ) {
( void ) F_39 ( V_126 , V_123 , & V_127 ) ;
F_36 ( L_3 , V_127 ) ;
V_123 += sizeof( T_2 ) ;
}
F_36 ( L_4 ) ;
}
#endif
}
static void F_40 ( void T_1 * V_128 , int V_3 ,
struct V_125 * V_126 )
{
#ifdef F_38
void T_1 * V_129 = F_6 ( V_128 ,
V_3 >> V_4 ) ;
void T_1 * V_130 ;
int V_131 , V_132 , V_133 , V_134 , V_135 , V_7 ;
if ( 0 > V_3 ) {
V_134 = V_131 = 0 ;
V_132 = 8 ;
V_135 = 2 ;
} else {
V_134 = V_3 >> V_4 ;
V_131 = V_3 ;
V_132 = V_135 = 1 ;
}
F_35 ( L_6 , V_131 ,
V_132 > 1 ? V_132 - 1 : V_131 ) ;
if ( NULL != V_126 ) {
F_35 ( L_7 ) ;
F_37 ( V_126 , 0x68 ) ;
}
F_35 ( L_8 ) ;
F_34 ( V_128 + 0xc00 , 0x3c ) ;
F_34 ( V_128 + 0xd00 , 0x34 ) ;
F_34 ( V_128 + 0xf00 , 0x4 ) ;
F_34 ( V_128 + 0x1d00 , 0x6c ) ;
for ( V_7 = V_134 ; V_7 < V_134 + V_135 ; V_7 ++ ) {
V_129 = F_6 ( V_128 , V_7 ) ;
F_35 ( L_9 , V_7 ) ;
F_34 ( V_129 , 0x1c ) ;
}
for ( V_133 = V_131 ; V_133 < V_131 + V_132 ; V_133 ++ ) {
V_130 = F_8 ( V_128 , V_133 ) ;
F_35 ( L_10 , V_133 ) ;
F_34 ( V_130 , 0x54 ) ;
F_35 ( L_11 , V_133 ) ;
F_34 ( V_130 + 0x300 , 0x60 ) ;
}
#endif
}
static unsigned int F_41 ( unsigned int V_136 )
{
unsigned int V_14 ;
switch ( V_136 ) {
case V_137 :
case V_138 :
case V_139 :
V_14 = V_140 + ( V_136 * sizeof( T_2 ) ) ;
break;
case V_141 :
V_14 = V_142 ;
break;
default:
V_14 = 0xffffffffU ;
break;
}
return V_14 ;
}
static int F_42 ( struct V_143 * V_144 , unsigned int V_136 , T_2 * V_145 )
{
unsigned int V_14 = F_41 ( V_136 ) ;
if ( V_14 != 0xffffffffU ) {
* V_145 = F_3 ( F_11 ( V_144 -> V_21 ) + V_14 ) ;
return 0 ;
} else
return - V_146 ;
}
static int F_43 ( struct V_143 * V_144 , unsigned int V_136 , T_2 V_145 )
{
unsigned int V_14 = F_41 ( V_136 ) ;
if ( V_14 != 0xffffffffU ) {
void T_1 * V_2 = F_11 ( V_144 -> V_21 ) + V_14 ;
struct V_17 * V_18 = V_144 -> V_21 -> V_16 -> V_19 ;
if ( V_136 == V_138 ) {
if ( ( V_145 & 0xf ) == 1 || ( F_3 ( V_2 ) & 0xf ) == 1 )
V_145 |= 0xf000 ;
if ( V_18 -> V_147 & V_148 ) {
void T_1 * V_149 =
F_11 ( V_144 -> V_21 ) + V_150 ;
T_2 V_151 =
V_152 |
V_153 |
V_154 ;
if ( ( V_145 & 0xf0 ) != 0x10 )
V_151 |=
V_155 |
V_156 ;
F_1 ( V_151 , V_149 ) ;
}
}
F_1 ( V_145 , V_2 ) ;
return 0 ;
} else
return - V_146 ;
}
static void F_44 ( struct V_157 * V_158 )
{
if ( V_158 -> V_83 & V_159 ) {
if ( F_45 ( V_158 -> V_144 -> V_21 ) ) {
V_158 -> V_83 &= ~ V_159 ;
F_46 ( V_158 ,
L_12 ) ;
}
}
}
static int F_47 ( struct V_160 * V_161 )
{
struct V_143 * V_144 = V_161 -> V_162 -> V_144 ;
struct V_20 * V_21 = V_144 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
if ( V_27 -> V_103 & V_163 )
return V_164 ;
if ( F_48 ( V_21 -> V_165 ) ) {
if ( V_144 == V_21 -> V_165 ) {
if ( V_21 -> V_166 )
return V_164 ;
V_161 -> V_83 |= V_167 ;
return 0 ;
} else
return V_164 ;
}
if ( V_21 -> V_166 == 0 )
return 0 ;
if ( ( V_27 -> V_103 & V_104 ) &&
( V_27 -> V_103 & V_106 ) ) {
if ( F_49 ( V_161 -> V_168 . V_100 ) )
return 0 ;
else {
V_21 -> V_165 = V_144 ;
return V_164 ;
}
}
return V_164 ;
}
static void F_50 ( struct V_20 * V_21 , int V_101 , int V_169 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
void T_1 * V_25 ;
T_2 V_29 , * V_170 = & V_27 -> V_28 . V_29 ;
T_2 V_31 , * V_171 = & V_27 -> V_28 . V_31 ;
T_2 V_33 , * V_172 = & V_27 -> V_28 . V_33 ;
V_31 = * V_171 & ~ V_173 ;
V_33 = * V_172 | V_174 ;
if ( V_169 ) {
V_29 = * V_170 | V_175 ;
V_31 = * V_171 | V_173 ;
if ( V_101 )
V_33 &= ~ V_174 ;
else
V_29 |= V_176 ;
} else {
V_29 = * V_170 & ~ ( V_175 | V_176 ) ;
}
V_25 = F_11 ( V_21 ) ;
F_14 ( V_25 + V_30 , V_170 , V_29 ) ;
F_14 ( V_25 + V_32 , V_171 , V_31 ) ;
F_14 ( V_25 + V_34 , V_172 , V_33 ) ;
}
static void F_51 ( struct V_20 * V_21 , int V_101 )
{
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
T_2 V_37 , V_38 ;
V_37 = F_3 ( V_18 -> V_6 + V_177 ) ;
if ( V_101 )
V_38 = V_37 | ( 1 << 22 ) ;
else
V_38 = V_37 & ~ ( 1 << 22 ) ;
if ( V_38 != V_37 )
F_2 ( V_38 , V_18 -> V_6 + V_177 ) ;
}
static void F_52 ( struct V_20 * V_21 , int V_178 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
T_2 V_38 , * V_37 = & V_27 -> V_28 . V_35 ;
if ( V_178 )
V_38 = * V_37 | 1 ;
else
V_38 = * V_37 & ~ 1 ;
F_14 ( F_11 ( V_21 ) + V_36 , V_37 , V_38 ) ;
}
static void F_53 ( struct V_20 * V_21 )
{
struct V_15 * V_16 = V_21 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_13 ;
T_2 V_179 ;
if ( V_18 -> V_147 & V_180 )
return;
V_18 -> V_147 |= V_180 ;
V_13 = F_7 ( F_10 ( V_16 ) , V_21 -> V_22 ) ;
V_179 = F_3 ( V_13 + V_181 ) ;
F_2 ( V_179 | V_182 , V_13 + V_181 ) ;
}
static void F_54 ( struct V_20 * V_21 )
{
struct V_15 * V_16 = V_21 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_13 ;
T_2 V_179 ;
unsigned int V_3 ;
if ( ! ( V_18 -> V_147 & V_180 ) )
return;
for ( V_3 = 0 ; V_3 < V_18 -> V_86 ; V_3 ++ ) {
struct V_20 * V_183 = V_16 -> V_184 [ V_3 ] ;
struct V_26 * V_27 = V_183 -> V_19 ;
if ( V_27 -> V_103 & V_106 )
return;
}
V_18 -> V_147 &= ~ V_180 ;
V_13 = F_7 ( F_10 ( V_16 ) , V_21 -> V_22 ) ;
V_179 = F_3 ( V_13 + V_181 ) ;
F_2 ( V_179 & ~ V_182 , V_13 + V_181 ) ;
}
static void F_29 ( struct V_20 * V_21 , int V_101 , int V_185 )
{
T_2 V_186 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
V_186 = V_187 ;
V_27 -> V_103 &=
~ ( V_188 | V_106 | V_189 ) ;
if ( F_25 ( V_18 ) )
V_186 |= ( 1 << 8 ) ;
else if ( F_55 ( V_18 ) ) {
V_186 |= V_190 | V_191 ;
F_51 ( V_21 , V_101 ) ;
} else if ( F_22 ( V_18 ) ) {
int V_169 = F_45 ( V_21 ) ;
V_169 &= V_101 ;
F_50 ( V_21 , V_101 , V_169 ) ;
if ( V_169 ) {
V_27 -> V_103 |= V_188 ;
V_186 |= V_192 ;
}
V_186 |= ( 1 << 23 ) ;
if ( V_185 ) {
V_186 |= ( 1 << 22 ) ;
if ( ! F_56 ( V_18 ) )
V_186 |= ( 1 << 18 ) ;
}
if ( V_18 -> V_147 & V_193 )
V_186 |= ( 1 << 17 ) ;
F_52 ( V_21 , ! V_185 ) ;
if ( F_56 ( V_18 ) ) {
if ( V_101 )
F_53 ( V_21 ) ;
else
F_54 ( V_21 ) ;
}
}
if ( V_101 ) {
V_186 |= V_194 ;
V_27 -> V_103 |= V_106 ;
}
F_1 ( V_186 , V_25 + V_195 ) ;
}
static void F_57 ( struct V_20 * V_21 )
{
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
struct V_26 * V_27 = V_21 -> V_19 ;
int V_196 ;
if ( V_27 -> V_197 ) {
F_58 ( V_18 -> V_198 , V_27 -> V_197 , V_27 -> V_44 ) ;
V_27 -> V_197 = NULL ;
}
if ( V_27 -> V_199 ) {
F_58 ( V_18 -> V_200 , V_27 -> V_199 , V_27 -> V_51 ) ;
V_27 -> V_199 = NULL ;
}
for ( V_196 = 0 ; V_196 < V_201 ; ++ V_196 ) {
if ( V_27 -> V_202 [ V_196 ] ) {
if ( V_196 == 0 || ! F_25 ( V_18 ) )
F_58 ( V_18 -> V_203 ,
V_27 -> V_202 [ V_196 ] ,
V_27 -> V_204 [ V_196 ] ) ;
V_27 -> V_202 [ V_196 ] = NULL ;
}
}
}
static int F_59 ( struct V_20 * V_21 )
{
struct V_205 * V_162 = V_21 -> V_16 -> V_162 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
struct V_26 * V_27 ;
unsigned long V_83 ;
int V_196 ;
V_27 = F_60 ( V_162 , sizeof( * V_27 ) , V_206 ) ;
if ( ! V_27 )
return - V_207 ;
V_21 -> V_19 = V_27 ;
V_27 -> V_197 = F_61 ( V_18 -> V_198 , V_206 , & V_27 -> V_44 ) ;
if ( ! V_27 -> V_197 )
return - V_207 ;
V_27 -> V_199 = F_61 ( V_18 -> V_200 , V_206 , & V_27 -> V_51 ) ;
if ( ! V_27 -> V_199 )
goto V_208;
if ( V_18 -> V_147 & V_209 )
V_21 -> V_83 |= V_210 ;
for ( V_196 = 0 ; V_196 < V_201 ; ++ V_196 ) {
if ( V_196 == 0 || ! F_25 ( V_18 ) ) {
V_27 -> V_202 [ V_196 ] = F_62 ( V_18 -> V_203 ,
V_206 , & V_27 -> V_204 [ V_196 ] ) ;
if ( ! V_27 -> V_202 [ V_196 ] )
goto V_208;
} else {
V_27 -> V_202 [ V_196 ] = V_27 -> V_202 [ 0 ] ;
V_27 -> V_204 [ V_196 ] = V_27 -> V_204 [ 0 ] ;
}
}
F_24 ( V_21 -> V_92 , V_83 ) ;
F_13 ( V_21 ) ;
F_29 ( V_21 , 0 , 0 ) ;
F_26 ( V_21 -> V_92 , V_83 ) ;
return 0 ;
V_208:
F_57 ( V_21 ) ;
return - V_207 ;
}
static void F_63 ( struct V_20 * V_21 )
{
unsigned long V_83 ;
F_24 ( V_21 -> V_92 , V_83 ) ;
F_28 ( V_21 ) ;
F_19 ( V_21 , 0 ) ;
F_26 ( V_21 -> V_92 , V_83 ) ;
F_57 ( V_21 ) ;
}
static void F_64 ( struct V_160 * V_161 )
{
struct V_26 * V_27 = V_161 -> V_21 -> V_19 ;
struct V_211 * V_212 ;
struct V_213 * V_213 , * V_214 = NULL ;
unsigned int V_215 ;
V_213 = V_27 -> V_202 [ V_161 -> V_196 ] ;
F_65 (qc->sg, sg, qc->n_elem, si) {
T_4 V_2 = F_66 ( V_212 ) ;
T_2 V_216 = F_67 ( V_212 ) ;
while ( V_216 ) {
T_2 V_217 = V_2 & 0xffff ;
T_2 V_218 = V_216 ;
if ( V_217 + V_218 > 0x10000 )
V_218 = 0x10000 - V_217 ;
V_213 -> V_2 = F_68 ( V_2 & 0xffffffff ) ;
V_213 -> V_219 = F_68 ( ( V_2 >> 16 ) >> 16 ) ;
V_213 -> V_220 = F_68 ( V_218 & 0xffff ) ;
V_213 -> V_221 = 0 ;
V_216 -= V_218 ;
V_2 += V_218 ;
V_214 = V_213 ;
V_213 ++ ;
}
}
if ( F_69 ( V_214 ) )
V_214 -> V_220 |= F_68 ( V_222 ) ;
F_70 () ;
}
static void F_71 ( T_5 * V_223 , T_3 V_1 , T_3 V_2 , unsigned V_224 )
{
T_6 V_225 = V_1 | ( V_2 << V_226 ) | V_227 |
( V_224 ? V_228 : 0 ) ;
* V_223 = F_72 ( V_225 ) ;
}
static void F_73 ( struct V_20 * V_21 )
{
F_21 ( V_21 , F_11 ( V_21 ) , V_72 ) ;
}
static int F_74 ( struct V_160 * V_161 )
{
struct V_229 * V_230 = V_161 -> V_231 ;
if ( V_230 ) {
switch ( V_230 -> V_232 [ 0 ] ) {
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
return 0 ;
}
}
return - V_242 ;
}
static void F_75 ( struct V_160 * V_161 )
{
struct V_20 * V_21 = V_161 -> V_21 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
F_64 ( V_161 ) ;
F_2 ( 0 , V_25 + V_243 ) ;
F_2 ( ( V_27 -> V_204 [ V_161 -> V_196 ] >> 16 ) >> 16 ,
V_25 + V_244 ) ;
F_1 ( V_27 -> V_204 [ V_161 -> V_196 ] ,
V_25 + V_245 ) ;
V_21 -> V_246 -> V_247 ( V_21 , & V_161 -> V_168 ) ;
}
static void F_76 ( struct V_160 * V_161 )
{
struct V_20 * V_21 = V_161 -> V_21 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
unsigned int V_248 = ( V_161 -> V_168 . V_83 & V_249 ) ;
T_2 V_250 = ( V_248 ? 0 : V_251 ) | V_252 ;
F_1 ( V_250 , V_25 + V_243 ) ;
}
static void F_77 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_250 ;
V_250 = F_3 ( V_25 + V_243 ) ;
if ( V_250 & V_252 ) {
V_250 &= ~ V_252 ;
F_1 ( V_250 , V_25 + V_243 ) ;
F_78 ( V_21 ) ;
}
}
static void F_79 ( struct V_160 * V_161 )
{
F_77 ( V_161 -> V_21 ) ;
}
static T_3 F_80 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_118 , V_253 ;
V_118 = F_3 ( V_25 + V_254 ) ;
if ( V_118 & V_255 )
V_253 = V_255 ;
else if ( V_118 & V_256 )
V_253 = ( V_118 & V_256 ) | V_257 ;
else {
F_77 ( V_21 ) ;
if ( F_81 ( V_21 -> V_258 . V_259 ) & V_260 )
V_253 = 0 ;
else
V_253 = V_257 ;
}
return V_253 ;
}
static void F_82 ( struct V_160 * V_161 )
{
struct V_261 * V_168 = & V_161 -> V_168 ;
if ( ( V_168 -> V_83 & V_249 ) && F_83 ( V_168 ) ) {
if ( V_161 -> V_162 -> V_262 > 7 ) {
switch ( V_168 -> V_263 ) {
case V_264 :
V_168 -> V_263 = V_265 ;
break;
case V_266 :
V_168 -> V_83 &= ~ V_267 ;
case V_268 :
V_168 -> V_263 = V_269 ;
break;
}
}
}
}
static void F_84 ( struct V_160 * V_161 )
{
struct V_20 * V_21 = V_161 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
T_5 * V_270 ;
struct V_261 * V_168 = & V_161 -> V_168 ;
T_6 V_83 = 0 ;
unsigned V_271 ;
switch ( V_168 -> V_100 ) {
case V_272 :
if ( V_168 -> V_263 == V_273 )
return;
case V_102 :
break;
case V_274 :
F_82 ( V_161 ) ;
return;
default:
return;
}
if ( ! ( V_168 -> V_83 & V_249 ) )
V_83 |= V_275 ;
F_16 ( V_201 <= V_161 -> V_196 ) ;
V_83 |= V_161 -> V_196 << V_276 ;
V_83 |= ( V_161 -> V_162 -> V_144 -> V_277 & 0xf ) << V_278 ;
V_271 = V_27 -> V_41 ;
V_27 -> V_197 [ V_271 ] . V_279 =
F_68 ( V_27 -> V_204 [ V_161 -> V_196 ] & 0xffffffff ) ;
V_27 -> V_197 [ V_271 ] . V_280 =
F_68 ( ( V_27 -> V_204 [ V_161 -> V_196 ] >> 16 ) >> 16 ) ;
V_27 -> V_197 [ V_271 ] . V_281 = F_72 ( V_83 ) ;
V_270 = & V_27 -> V_197 [ V_271 ] . V_282 [ 0 ] ;
switch ( V_168 -> V_263 ) {
case V_283 :
case V_284 :
case V_285 :
case V_286 :
case V_287 :
F_71 ( V_270 ++ , V_168 -> V_288 , V_289 , 0 ) ;
break;
case V_290 :
case V_291 :
F_71 ( V_270 ++ , V_168 -> V_292 , V_293 , 0 ) ;
F_71 ( V_270 ++ , V_168 -> V_294 , V_293 , 0 ) ;
break;
default:
F_85 ( V_168 -> V_263 ) ;
break;
}
F_71 ( V_270 ++ , V_168 -> V_295 , V_289 , 0 ) ;
F_71 ( V_270 ++ , V_168 -> V_296 , V_297 , 0 ) ;
F_71 ( V_270 ++ , V_168 -> V_298 , V_297 , 0 ) ;
F_71 ( V_270 ++ , V_168 -> V_299 , V_300 , 0 ) ;
F_71 ( V_270 ++ , V_168 -> V_301 , V_300 , 0 ) ;
F_71 ( V_270 ++ , V_168 -> V_302 , V_303 , 0 ) ;
F_71 ( V_270 ++ , V_168 -> V_304 , V_303 , 0 ) ;
F_71 ( V_270 ++ , V_168 -> V_205 , V_305 , 0 ) ;
F_71 ( V_270 ++ , V_168 -> V_263 , V_306 , 1 ) ;
if ( ! ( V_161 -> V_83 & V_307 ) )
return;
F_64 ( V_161 ) ;
}
static void F_86 ( struct V_160 * V_161 )
{
struct V_20 * V_21 = V_161 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_308 * V_197 ;
struct V_261 * V_168 = & V_161 -> V_168 ;
unsigned V_271 ;
T_2 V_83 = 0 ;
if ( ( V_168 -> V_100 != V_272 ) &&
( V_168 -> V_100 != V_102 ) )
return;
if ( V_168 -> V_263 == V_273 )
return;
if ( ! ( V_168 -> V_83 & V_249 ) )
V_83 |= V_275 ;
F_16 ( V_201 <= V_161 -> V_196 ) ;
V_83 |= V_161 -> V_196 << V_276 ;
V_83 |= V_161 -> V_196 << V_309 ;
V_83 |= ( V_161 -> V_162 -> V_144 -> V_277 & 0xf ) << V_278 ;
V_271 = V_27 -> V_41 ;
V_197 = (struct V_308 * ) & V_27 -> V_197 [ V_271 ] ;
V_197 -> V_2 = F_68 ( V_27 -> V_204 [ V_161 -> V_196 ] & 0xffffffff ) ;
V_197 -> V_219 = F_68 ( ( V_27 -> V_204 [ V_161 -> V_196 ] >> 16 ) >> 16 ) ;
V_197 -> V_83 = F_68 ( V_83 ) ;
V_197 -> V_282 [ 0 ] = F_68 (
( V_168 -> V_263 << 16 ) |
( V_168 -> V_294 << 24 )
) ;
V_197 -> V_282 [ 1 ] = F_68 (
( V_168 -> V_298 << 0 ) |
( V_168 -> V_301 << 8 ) |
( V_168 -> V_304 << 16 ) |
( V_168 -> V_205 << 24 )
) ;
V_197 -> V_282 [ 2 ] = F_68 (
( V_168 -> V_296 << 0 ) |
( V_168 -> V_299 << 8 ) |
( V_168 -> V_302 << 16 ) |
( V_168 -> V_292 << 24 )
) ;
V_197 -> V_282 [ 3 ] = F_68 (
( V_168 -> V_295 << 0 ) |
( V_168 -> V_288 << 8 )
) ;
if ( ! ( V_161 -> V_83 & V_307 ) )
return;
F_64 ( V_161 ) ;
}
static T_3 F_87 ( struct V_20 * V_21 )
{
T_3 V_310 = F_81 ( V_21 -> V_258 . V_311 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
if ( V_27 -> V_103 & V_189 ) {
if ( V_310 & ( V_260 | V_312 | V_313 ) )
V_27 -> V_103 &= ~ V_189 ;
else
V_310 = V_260 ;
}
return V_310 ;
}
static unsigned int F_88 ( struct V_20 * V_21 , T_2 * V_314 , int V_315 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_316 , V_317 , V_318 ;
int V_114 , V_113 = 200 , V_319 = V_315 - 1 ;
V_317 = F_3 ( V_25 + V_320 ) ;
V_316 = 0x100 | ( V_317 & 0xf ) ;
F_1 ( V_316 , V_25 + V_320 ) ;
for ( V_114 = 0 ; V_114 < V_319 ; ++ V_114 )
F_2 ( V_314 [ V_114 ] , V_25 + V_321 ) ;
F_1 ( V_316 | 0x200 , V_25 + V_320 ) ;
F_1 ( V_314 [ V_319 ] , V_25 + V_321 ) ;
do {
V_318 = F_3 ( V_25 + V_322 ) ;
} while ( ! ( V_318 & 0x1000 ) && -- V_113 );
F_1 ( V_317 , V_25 + V_320 ) ;
if ( ( V_318 & 0x3000 ) != 0x1000 ) {
F_89 ( V_21 , L_13 ,
V_323 , V_318 ) ;
return V_324 ;
}
return 0 ;
}
static unsigned int F_90 ( struct V_160 * V_161 )
{
struct V_20 * V_21 = V_161 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_143 * V_144 = V_161 -> V_162 -> V_144 ;
T_2 V_314 [ 5 ] ;
int V_120 = 0 ;
F_91 ( & V_161 -> V_168 , V_144 -> V_277 , 1 , ( void * ) V_314 ) ;
V_120 = F_88 ( V_21 , V_314 , F_92 ( V_314 ) ) ;
if ( V_120 )
return V_120 ;
switch ( V_161 -> V_168 . V_100 ) {
case V_325 :
V_27 -> V_103 |= V_189 ;
case V_326 :
V_21 -> V_327 = V_328 ;
break;
case V_274 :
V_27 -> V_103 |= V_189 ;
if ( V_161 -> V_168 . V_83 & V_249 )
V_21 -> V_327 = V_328 ;
else
V_21 -> V_327 = V_329 ;
break;
default:
V_21 -> V_327 = V_330 ;
break;
}
if ( V_161 -> V_168 . V_83 & V_331 )
F_93 ( V_144 , 0 ) ;
return 0 ;
}
static unsigned int F_94 ( struct V_160 * V_161 )
{
static int V_332 = 10 ;
struct V_20 * V_21 = V_161 -> V_21 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
T_2 V_271 ;
unsigned int V_73 ;
V_27 -> V_103 &= ~ V_189 ;
switch ( V_161 -> V_168 . V_100 ) {
case V_272 :
if ( V_161 -> V_168 . V_263 == V_273 ) {
if ( ! V_21 -> V_246 -> V_333 )
return V_324 ;
break;
}
case V_102 :
F_27 ( V_21 , V_25 , V_27 , V_161 -> V_168 . V_100 ) ;
V_27 -> V_41 = ( V_27 -> V_41 + 1 ) & V_42 ;
V_271 = V_27 -> V_41 << V_43 ;
F_1 ( ( V_27 -> V_44 & V_46 ) | V_271 ,
V_25 + V_47 ) ;
return 0 ;
case V_274 :
if ( V_332 > 0 && ( V_161 -> V_334 / V_161 -> V_335 ) > 1 ) {
-- V_332 ;
F_95 ( V_161 -> V_162 -> V_144 , V_336
L_14
L_15 ) ;
}
case V_337 :
case V_325 :
case V_326 :
if ( V_21 -> V_83 & V_338 )
V_161 -> V_168 . V_83 |= V_331 ;
break;
}
if ( V_161 -> V_168 . V_83 & V_331 )
V_73 = V_72 ;
else
V_73 = V_72 | V_71 ;
F_28 ( V_21 ) ;
F_21 ( V_21 , F_11 ( V_21 ) , V_73 ) ;
F_96 ( V_21 , V_161 -> V_162 -> V_144 -> V_277 ) ;
if ( V_161 -> V_168 . V_263 == V_339 ) {
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
if ( F_55 ( V_18 ) )
return F_90 ( V_161 ) ;
}
return F_97 ( V_161 ) ;
}
static struct V_160 * F_98 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_160 * V_161 ;
if ( V_27 -> V_103 & V_106 )
return NULL ;
V_161 = F_99 ( V_21 , V_21 -> V_144 . V_340 ) ;
if ( V_161 && ! ( V_161 -> V_168 . V_83 & V_331 ) )
return V_161 ;
return NULL ;
}
static void F_100 ( struct V_20 * V_21 )
{
unsigned int V_277 , V_341 ;
struct V_26 * V_27 = V_21 -> V_19 ;
if ( V_27 -> V_103 & V_163 ) {
V_341 = V_27 -> V_342 ;
V_27 -> V_103 &= ~ V_163 ;
for ( V_277 = 0 ; V_341 != 0 ; V_277 ++ ) {
unsigned int V_343 = ( 1 << V_277 ) ;
if ( V_341 & V_343 ) {
struct V_143 * V_144 = & V_21 -> V_344 [ V_277 ] ;
V_341 &= ~ V_343 ;
F_101 ( V_144 ) ;
}
}
F_102 ( V_21 ) ;
}
F_103 ( V_21 ) ;
}
static unsigned int F_104 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
return F_3 ( V_25 + V_345 ) >> 16 ;
}
static void F_105 ( struct V_20 * V_21 , unsigned int V_341 )
{
struct V_346 * V_347 ;
unsigned int V_277 ;
V_347 = & V_21 -> V_144 . V_348 ;
for ( V_277 = 0 ; V_341 != 0 ; V_277 ++ ) {
unsigned int V_343 = ( 1 << V_277 ) ;
if ( V_341 & V_343 ) {
struct V_143 * V_144 = & V_21 -> V_344 [ V_277 ] ;
V_341 &= ~ V_343 ;
V_347 = & V_144 -> V_348 ;
F_106 ( V_347 ) ;
F_107 ( V_347 , L_16 ) ;
V_347 -> V_349 |= V_350 ;
V_347 -> V_351 |= V_352 ;
F_108 ( V_144 ) ;
}
}
}
static int F_109 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_353 , V_354 ;
V_353 = ( F_3 ( V_25 + V_47 )
>> V_43 ) & V_42 ;
V_354 = ( F_3 ( V_25 + V_48 )
>> V_43 ) & V_42 ;
return ( V_353 == V_354 ) ;
}
static int F_110 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
int V_355 ;
unsigned int V_356 , V_357 ;
if ( ! ( V_27 -> V_103 & V_163 ) ) {
V_27 -> V_103 |= V_163 ;
V_27 -> V_342 = 0 ;
}
V_356 = V_27 -> V_342 ;
V_357 = V_356 | F_104 ( V_21 ) ;
if ( V_356 != V_357 ) {
V_27 -> V_342 = V_357 ;
F_105 ( V_21 , V_357 & ~ V_356 ) ;
}
V_355 = F_111 ( V_357 ) ;
F_112 ( V_21 ,
L_17 ,
V_323 , V_27 -> V_342 ,
V_21 -> V_358 , V_355 ,
V_21 -> V_166 ) ;
if ( V_21 -> V_166 <= V_355 && F_109 ( V_21 ) ) {
F_113 ( V_21 , V_27 ) ;
F_28 ( V_21 ) ;
F_114 ( V_21 ) ;
F_112 ( V_21 , L_18 , V_323 ) ;
return 1 ;
}
F_112 ( V_21 , L_19 , V_323 ) ;
return 1 ;
}
static int F_115 ( struct V_20 * V_21 )
{
return 0 ;
}
static int F_116 ( struct V_20 * V_21 , T_2 V_359 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
if ( ! ( V_27 -> V_103 & V_104 ) )
return 0 ;
if ( ! ( V_27 -> V_103 & V_188 ) )
return 0 ;
if ( ! ( V_359 & V_174 ) )
return 0 ;
V_359 &= ~ V_360 ;
if ( V_359 & ~ ( V_174 | V_361 ) )
return 0 ;
if ( V_27 -> V_103 & V_106 ) {
if ( V_359 & V_361 ) {
F_89 ( V_21 , L_20 ,
V_323 , V_359 , V_27 -> V_103 ) ;
return 0 ;
}
return F_110 ( V_21 ) ;
} else {
if ( ! ( V_359 & V_361 ) ) {
F_89 ( V_21 , L_20 ,
V_323 , V_359 , V_27 -> V_103 ) ;
return 0 ;
}
return F_115 ( V_21 ) ;
}
return 0 ;
}
static void F_117 ( struct V_20 * V_21 , int V_362 )
{
struct V_346 * V_347 = & V_21 -> V_144 . V_348 ;
char * V_363 = L_21 ;
F_106 ( V_347 ) ;
if ( V_362 ) {
V_363 = L_22 ;
} else {
struct V_160 * V_161 = F_99 ( V_21 , V_21 -> V_144 . V_340 ) ;
if ( V_161 && ( V_161 -> V_168 . V_83 & V_331 ) )
V_363 = L_23 ;
}
F_107 ( V_347 , L_24 , V_363 ) ;
V_347 -> V_349 |= V_324 ;
V_347 -> V_351 |= V_352 ;
F_102 ( V_21 ) ;
}
static void F_118 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_359 , V_364 , V_365 = 0 ;
T_2 V_366 = 0 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
unsigned int V_351 = 0 , V_349 = 0 ;
struct V_346 * V_347 = & V_21 -> V_144 . V_348 ;
struct V_160 * V_161 ;
int abort = 0 ;
F_119 ( & V_21 -> V_144 , V_139 , & V_365 ) ;
F_120 ( & V_21 -> V_144 , V_139 , V_365 ) ;
V_359 = F_3 ( V_25 + V_75 ) ;
if ( F_22 ( V_18 ) && ( V_359 & V_367 ) ) {
V_366 = F_3 ( V_25 + V_79 ) ;
F_1 ( ~ V_366 , V_25 + V_79 ) ;
}
F_1 ( ~ V_359 , V_25 + V_75 ) ;
if ( V_359 & V_174 ) {
if ( F_116 ( V_21 , V_359 ) )
return;
}
V_161 = F_98 ( V_21 ) ;
F_106 ( V_347 ) ;
F_107 ( V_347 , L_25 ,
V_359 , V_27 -> V_103 ) ;
if ( F_22 ( V_18 ) && ( V_359 & V_367 ) ) {
F_107 ( V_347 , L_26 , V_366 ) ;
if ( V_366 & V_368 ) {
T_2 V_369 = V_359 &
~ ( V_367 | V_360 ) ;
F_121 ( V_21 ) ;
if ( ! V_369 )
return;
F_107 ( V_347 , L_27 ) ;
}
}
if ( V_359 & V_174 ) {
V_349 |= V_350 ;
V_351 |= V_352 ;
F_107 ( V_347 , L_28 ) ;
}
if ( V_359 & ( V_370 | V_371 |
V_372 | V_373 |
V_374 ) ) {
V_349 |= V_375 ;
V_351 |= V_352 ;
F_107 ( V_347 , L_29 ) ;
}
if ( V_359 & ( V_376 | V_377 ) ) {
F_122 ( V_347 ) ;
F_107 ( V_347 , V_359 & V_376 ?
L_30 : L_31 ) ;
V_351 |= V_352 ;
}
if ( F_25 ( V_18 ) ) {
V_364 = V_378 ;
if ( V_359 & V_379 ) {
V_27 -> V_103 &= ~ V_104 ;
F_107 ( V_347 , L_32 ) ;
}
} else {
V_364 = V_380 ;
if ( V_359 & V_361 ) {
V_27 -> V_103 &= ~ V_104 ;
F_107 ( V_347 , L_32 ) ;
}
if ( V_359 & V_381 ) {
F_107 ( V_347 , L_33 , V_365 ) ;
V_349 |= V_375 ;
V_351 |= V_352 ;
}
}
if ( ! V_349 ) {
V_349 = V_324 ;
V_351 |= V_352 ;
}
V_347 -> V_382 |= V_365 ;
V_347 -> V_351 |= V_351 ;
if ( V_161 )
V_161 -> V_349 |= V_349 ;
else
V_347 -> V_349 |= V_349 ;
if ( V_349 == V_350 ) {
F_114 ( V_21 ) ;
abort = 1 ;
} else if ( V_359 & V_364 ) {
F_102 ( V_21 ) ;
} else {
abort = 1 ;
}
if ( abort ) {
if ( V_161 )
F_108 ( V_161 -> V_162 -> V_144 ) ;
else
F_123 ( V_21 ) ;
}
}
static bool F_124 ( struct V_20 * V_21 ,
struct V_383 * V_384 , unsigned int V_196 , int V_385 )
{
T_3 V_386 ;
T_6 V_387 = F_125 ( V_384 -> V_83 ) ;
if ( ! V_385 ) {
T_3 V_388 = V_387 & 0xff & ~ V_174 ;
if ( V_388 ) {
return false ;
}
}
V_386 = V_387 >> V_389 ;
if ( ! F_126 ( V_386 ) )
return true ;
return false ;
}
static void F_113 ( struct V_20 * V_21 , struct V_26 * V_27 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
T_2 V_271 ;
bool V_390 = false ;
T_2 V_391 = 0 ;
int V_385 = ( V_27 -> V_103 & V_106 ) ;
V_271 = ( F_3 ( V_25 + V_53 )
>> V_50 ) & V_42 ;
while ( V_271 != V_27 -> V_49 ) {
unsigned int V_196 ;
struct V_383 * V_384 = & V_27 -> V_199 [ V_27 -> V_49 ] ;
V_27 -> V_49 = ( V_27 -> V_49 + 1 ) & V_42 ;
if ( F_25 ( V_18 ) ) {
V_196 = V_21 -> V_144 . V_340 ;
} else {
V_196 = F_125 ( V_384 -> V_392 ) & 0x1f ;
}
if ( F_124 ( V_21 , V_384 , V_196 , V_385 ) )
V_391 |= 1 << V_196 ;
V_390 = true ;
}
if ( V_390 ) {
F_127 ( V_21 , V_21 -> V_358 ^ V_391 ) ;
F_1 ( ( V_27 -> V_51 & V_54 ) |
( V_27 -> V_49 << V_50 ) ,
V_25 + V_55 ) ;
}
}
static void F_128 ( struct V_20 * V_21 , T_2 V_393 )
{
struct V_26 * V_27 ;
int V_362 ;
V_27 = V_21 -> V_19 ;
V_362 = ( V_27 -> V_103 & V_104 ) ;
if ( V_362 && ( V_393 & V_71 ) ) {
F_113 ( V_21 , V_27 ) ;
if ( V_27 -> V_103 & V_163 )
F_110 ( V_21 ) ;
}
if ( F_48 ( V_393 & V_72 ) ) {
F_118 ( V_21 ) ;
} else if ( ! V_362 ) {
struct V_160 * V_161 = F_98 ( V_21 ) ;
if ( V_161 )
F_129 ( V_21 , V_161 ) ;
else
F_117 ( V_21 , V_362 ) ;
}
}
static int F_130 ( struct V_15 * V_16 , T_2 V_394 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 , * V_13 ;
unsigned int V_395 = 0 , V_3 ;
if ( V_394 & V_57 )
F_2 ( ~ V_95 , V_12 + V_96 ) ;
for ( V_3 = 0 ; V_3 < V_18 -> V_86 ; V_3 ++ ) {
struct V_20 * V_21 = V_16 -> V_184 [ V_3 ] ;
unsigned int V_133 , V_69 , V_70 , V_393 ;
F_20 ( V_3 , V_69 , V_70 ) ;
if ( V_70 == 0 ) {
T_2 V_396 = ( V_394 >> V_69 ) & V_397 ;
T_2 V_398 , V_399 ;
if ( ! V_396 ) {
V_3 += V_87 - 1 ;
continue;
}
V_399 = 0 ;
if ( V_396 & V_58 )
V_399 = V_99 ;
for ( V_133 = 0 ; V_133 < V_87 ; ++ V_133 ) {
if ( ( V_3 + V_133 ) >= V_18 -> V_86 )
break;
V_398 = ( V_71 | V_72 ) << ( V_133 * 2 ) ;
if ( V_396 & V_398 )
V_399 |= ( V_77 | V_76 ) << V_133 ;
}
V_13 = F_7 ( V_12 , V_3 ) ;
F_1 ( ~ V_399 , V_13 + V_78 ) ;
V_395 = 1 ;
}
V_393 = ( V_394 >> V_69 ) & ( V_71 | V_72 ) ;
if ( V_393 )
F_128 ( V_21 , V_393 ) ;
}
return V_395 ;
}
static int F_131 ( struct V_15 * V_16 , void T_1 * V_12 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 ;
struct V_160 * V_161 ;
struct V_346 * V_347 ;
unsigned int V_114 , V_349 , V_400 = 0 ;
T_2 V_388 ;
V_388 = F_3 ( V_12 + V_18 -> V_401 ) ;
F_132 ( V_16 -> V_162 , L_34 , V_388 ) ;
F_35 ( L_35 ) ;
F_40 ( V_12 , - 1 , F_133 ( V_16 -> V_162 ) ) ;
F_1 ( 0 , V_12 + V_18 -> V_401 ) ;
for ( V_114 = 0 ; V_114 < V_16 -> V_86 ; V_114 ++ ) {
V_21 = V_16 -> V_184 [ V_114 ] ;
if ( ! F_134 ( & V_21 -> V_144 ) ) {
V_347 = & V_21 -> V_144 . V_348 ;
F_106 ( V_347 ) ;
if ( ! V_400 ++ )
F_107 ( V_347 ,
L_36 , V_388 ) ;
V_349 = V_402 ;
V_347 -> V_351 = V_352 ;
V_161 = F_99 ( V_21 , V_21 -> V_144 . V_340 ) ;
if ( V_161 )
V_161 -> V_349 |= V_349 ;
else
V_347 -> V_349 |= V_349 ;
F_102 ( V_21 ) ;
}
}
return 1 ;
}
static T_7 F_135 ( int V_403 , void * V_404 )
{
struct V_15 * V_16 = V_404 ;
struct V_17 * V_18 = V_16 -> V_19 ;
unsigned int V_395 = 0 ;
int V_405 = V_18 -> V_147 & V_406 ;
T_2 V_394 , V_407 ;
F_136 ( & V_16 -> V_92 ) ;
if ( V_405 )
F_17 ( 0 , V_18 ) ;
V_394 = F_3 ( V_18 -> V_408 ) ;
V_407 = V_394 & V_18 -> V_67 ;
if ( V_407 && V_394 != 0xffffffffU ) {
if ( F_48 ( ( V_407 & V_409 ) && ! F_56 ( V_18 ) ) )
V_395 = F_131 ( V_16 , V_18 -> V_6 ) ;
else
V_395 = F_130 ( V_16 , V_407 ) ;
}
if ( V_405 )
F_17 ( V_18 -> V_67 , V_18 ) ;
F_137 ( & V_16 -> V_92 ) ;
return F_138 ( V_395 ) ;
}
static unsigned int F_139 ( unsigned int V_136 )
{
unsigned int V_14 ;
switch ( V_136 ) {
case V_137 :
case V_139 :
case V_138 :
V_14 = V_136 * sizeof( T_2 ) ;
break;
default:
V_14 = 0xffffffffU ;
break;
}
return V_14 ;
}
static int F_140 ( struct V_143 * V_144 , unsigned int V_136 , T_2 * V_145 )
{
struct V_17 * V_18 = V_144 -> V_21 -> V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
void T_1 * V_2 = F_9 ( V_12 , V_144 -> V_21 -> V_22 ) ;
unsigned int V_14 = F_139 ( V_136 ) ;
if ( V_14 != 0xffffffffU ) {
* V_145 = F_3 ( V_2 + V_14 ) ;
return 0 ;
} else
return - V_146 ;
}
static int F_141 ( struct V_143 * V_144 , unsigned int V_136 , T_2 V_145 )
{
struct V_17 * V_18 = V_144 -> V_21 -> V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
void T_1 * V_2 = F_9 ( V_12 , V_144 -> V_21 -> V_22 ) ;
unsigned int V_14 = F_139 ( V_136 ) ;
if ( V_14 != 0xffffffffU ) {
F_1 ( V_145 , V_2 + V_14 ) ;
return 0 ;
} else
return - V_146 ;
}
static void F_142 ( struct V_15 * V_16 , void T_1 * V_12 )
{
struct V_125 * V_126 = F_133 ( V_16 -> V_162 ) ;
int V_410 ;
V_410 = ( V_126 -> V_205 == 0x5080 ) && ( V_126 -> V_411 == 0 ) ;
if ( ! V_410 ) {
T_2 V_225 = F_3 ( V_12 + V_412 ) ;
V_225 |= ( 1 << 0 ) ;
F_2 ( V_225 , V_12 + V_412 ) ;
}
F_143 ( V_16 , V_12 ) ;
}
static void F_144 ( struct V_17 * V_18 , void T_1 * V_12 )
{
F_2 ( 0x0fcfffff , V_12 + V_413 ) ;
}
static void F_145 ( struct V_17 * V_18 , int V_414 ,
void T_1 * V_12 )
{
void T_1 * V_415 = F_9 ( V_12 , V_414 ) ;
T_2 V_225 ;
V_225 = F_3 ( V_415 + V_416 ) ;
V_18 -> signal [ V_414 ] . V_417 = V_225 & 0x1800 ;
V_18 -> signal [ V_414 ] . V_418 = V_225 & 0xe0 ;
}
static void F_146 ( struct V_17 * V_18 , void T_1 * V_12 )
{
T_2 V_225 ;
F_2 ( 0 , V_12 + V_177 ) ;
V_225 = F_3 ( V_12 + V_412 ) ;
V_225 |= ~ ( 1 << 0 ) ;
F_2 ( V_225 , V_12 + V_412 ) ;
}
static void F_147 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_3 )
{
void T_1 * V_415 = F_9 ( V_12 , V_3 ) ;
const T_2 V_56 = ( 1 << 12 ) | ( 1 << 11 ) | ( 1 << 7 ) | ( 1 << 6 ) | ( 1 << 5 ) ;
T_2 V_225 ;
int V_419 = ( V_18 -> V_147 & V_420 ) ;
if ( V_419 ) {
V_225 = F_3 ( V_415 + V_421 ) ;
V_225 |= ( 1 << 19 ) ;
F_2 ( V_225 , V_415 + V_421 ) ;
V_225 = F_3 ( V_415 + V_422 ) ;
V_225 &= ~ 0x3 ;
V_225 |= 0x1 ;
F_2 ( V_225 , V_415 + V_422 ) ;
}
V_225 = F_3 ( V_415 + V_416 ) ;
V_225 &= ~ V_56 ;
V_225 |= V_18 -> signal [ V_3 ] . V_417 ;
V_225 |= V_18 -> signal [ V_3 ] . V_418 ;
F_2 ( V_225 , V_415 + V_416 ) ;
}
static void F_148 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
F_149 ( V_18 , V_12 , V_3 ) ;
F_150 ( 0x028 ) ;
F_2 ( 0x11f , V_25 + V_195 ) ;
F_150 ( 0x004 ) ;
F_150 ( 0x008 ) ;
F_150 ( 0x00c ) ;
F_150 ( 0x010 ) ;
F_150 ( 0x014 ) ;
F_150 ( 0x018 ) ;
F_150 ( 0x01c ) ;
F_150 ( 0x024 ) ;
F_150 ( 0x020 ) ;
F_150 ( 0x02c ) ;
F_2 ( 0xbc , V_25 + V_423 ) ;
}
static void F_151 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_7 )
{
void T_1 * V_13 = F_6 ( V_12 , V_7 ) ;
T_2 V_225 ;
F_150 ( 0x00c ) ;
F_150 ( 0x010 ) ;
F_150 ( 0x014 ) ;
F_150 ( 0x018 ) ;
V_225 = F_3 ( V_13 + 0x20 ) ;
V_225 &= 0x1c1c1c1c ;
V_225 |= 0x03030303 ;
F_2 ( V_225 , V_13 + 0x20 ) ;
}
static int F_152 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_424 )
{
unsigned int V_7 , V_3 ;
for ( V_7 = 0 ; V_7 < V_424 ; V_7 ++ ) {
for ( V_3 = 0 ; V_3 < V_87 ; V_3 ++ )
F_148 ( V_18 , V_12 ,
( V_7 * V_87 ) + V_3 ) ;
F_151 ( V_18 , V_12 , V_7 ) ;
}
return 0 ;
}
static void F_143 ( struct V_15 * V_16 , void T_1 * V_12 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
T_2 V_225 ;
V_225 = F_3 ( V_12 + V_425 ) ;
V_225 &= 0xff00ffff ;
F_2 ( V_225 , V_12 + V_425 ) ;
F_150 ( V_426 ) ;
F_150 ( V_427 ) ;
F_2 ( 0x000100ff , V_12 + V_428 ) ;
F_150 ( V_429 ) ;
F_150 ( V_18 -> V_401 ) ;
F_150 ( V_18 -> V_430 ) ;
F_150 ( V_431 ) ;
F_150 ( V_432 ) ;
F_150 ( V_433 ) ;
F_150 ( V_434 ) ;
}
static void F_153 ( struct V_17 * V_18 , void T_1 * V_12 )
{
T_2 V_225 ;
F_144 ( V_18 , V_12 ) ;
V_225 = F_3 ( V_12 + V_177 ) ;
V_225 &= 0x3 ;
V_225 |= ( 1 << 5 ) | ( 1 << 6 ) ;
F_2 ( V_225 , V_12 + V_177 ) ;
}
static int F_154 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_424 )
{
void T_1 * V_118 = V_12 + V_435 ;
int V_114 , V_436 = 0 ;
T_2 V_437 ;
V_437 = F_3 ( V_118 ) ;
F_2 ( V_437 | V_438 , V_118 ) ;
for ( V_114 = 0 ; V_114 < 1000 ; V_114 ++ ) {
F_31 ( 1 ) ;
V_437 = F_3 ( V_118 ) ;
if ( V_439 & V_437 )
break;
}
if ( ! ( V_439 & V_437 ) ) {
F_36 (KERN_ERR DRV_NAME L_37 ) ;
V_436 = 1 ;
goto V_440;
}
V_114 = 5 ;
do {
F_2 ( V_437 | V_441 , V_118 ) ;
V_437 = F_3 ( V_118 ) ;
F_31 ( 1 ) ;
} while ( ! ( V_441 & V_437 ) && ( V_114 -- > 0 ) );
if ( ! ( V_441 & V_437 ) ) {
F_36 (KERN_ERR DRV_NAME L_38 ) ;
V_436 = 1 ;
goto V_440;
}
V_114 = 5 ;
do {
F_2 ( V_437 & ~ ( V_441 | V_438 ) , V_118 ) ;
V_437 = F_3 ( V_118 ) ;
F_31 ( 1 ) ;
} while ( ( V_441 & V_437 ) && ( V_114 -- > 0 ) );
if ( V_441 & V_437 ) {
F_36 (KERN_ERR DRV_NAME L_39 ) ;
V_436 = 1 ;
}
V_440:
return V_436 ;
}
static void F_155 ( struct V_17 * V_18 , int V_414 ,
void T_1 * V_12 )
{
void T_1 * V_25 ;
T_2 V_225 ;
V_225 = F_3 ( V_12 + V_442 ) ;
if ( ( V_225 & ( 1 << 0 ) ) == 0 ) {
V_18 -> signal [ V_414 ] . V_418 = 0x7 << 8 ;
V_18 -> signal [ V_414 ] . V_417 = 0x1 << 5 ;
return;
}
V_25 = F_8 ( V_12 , V_414 ) ;
V_225 = F_3 ( V_25 + V_443 ) ;
V_18 -> signal [ V_414 ] . V_418 = V_225 & 0x700 ;
V_18 -> signal [ V_414 ] . V_417 = V_225 & 0xe0 ;
}
static void F_156 ( struct V_17 * V_18 , void T_1 * V_12 )
{
F_2 ( 0x00000060 , V_12 + V_177 ) ;
}
static void F_157 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
T_2 V_147 = V_18 -> V_147 ;
int V_444 =
V_147 & ( V_445 | V_209 ) ;
int V_446 =
V_147 & ( V_445 | V_209 ) ;
T_2 V_447 , V_448 ;
if ( V_444 ) {
V_447 = F_3 ( V_25 + V_443 ) ;
V_447 &= ~ ( 1 << 16 ) ;
V_447 |= ( 1 << 31 ) ;
F_2 ( V_447 , V_25 + V_443 ) ;
F_31 ( 200 ) ;
V_447 = F_3 ( V_25 + V_443 ) ;
V_447 &= ~ ( ( 1 << 16 ) | ( 1 << 31 ) ) ;
F_2 ( V_447 , V_25 + V_443 ) ;
F_31 ( 200 ) ;
}
V_448 = F_3 ( V_25 + V_449 ) ;
V_448 = ( V_448 & 0x1f ) | ( 0x5555601 << 5 ) ;
if ( F_56 ( V_18 ) )
V_448 &= ~ 0x1c ;
if ( V_446 ) {
T_2 V_450 = F_3 ( V_25 + V_451 ) ;
if ( F_22 ( V_18 ) )
V_450 = ( V_450 & ~ V_452 ) | V_453 ;
else
V_450 = ( V_450 & ~ V_454 ) | V_455 ;
F_2 ( V_450 , V_25 + V_451 ) ;
}
F_2 ( V_448 , V_25 + V_449 ) ;
V_447 = F_3 ( V_25 + V_443 ) ;
V_447 &= ~ V_456 ;
V_447 |= V_18 -> signal [ V_3 ] . V_418 ;
V_447 |= V_18 -> signal [ V_3 ] . V_417 ;
V_447 &= ~ ( 1 << 16 ) ;
if ( F_22 ( V_18 ) ) {
V_447 &= ~ 0xC30FF01F ;
V_447 |= 0x0000900F ;
}
F_2 ( V_447 , V_25 + V_443 ) ;
}
static void F_158 ( struct V_17 * V_18 ,
void T_1 * V_12 )
{
return;
}
static void F_159 ( struct V_17 * V_18 , int V_414 ,
void T_1 * V_12 )
{
void T_1 * V_25 ;
T_2 V_225 ;
V_25 = F_8 ( V_12 , V_414 ) ;
V_225 = F_3 ( V_25 + V_443 ) ;
V_18 -> signal [ V_414 ] . V_418 = V_225 & 0x700 ;
V_18 -> signal [ V_414 ] . V_417 = V_225 & 0xe0 ;
}
static void F_160 ( struct V_17 * V_18 ,
void T_1 * V_12 , unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
F_149 ( V_18 , V_12 , V_3 ) ;
F_150 ( 0x028 ) ;
F_2 ( 0x101f , V_25 + V_195 ) ;
F_150 ( 0x004 ) ;
F_150 ( 0x008 ) ;
F_150 ( 0x00c ) ;
F_150 ( 0x010 ) ;
F_150 ( 0x014 ) ;
F_150 ( 0x018 ) ;
F_150 ( 0x01c ) ;
F_150 ( 0x024 ) ;
F_150 ( 0x020 ) ;
F_150 ( 0x02c ) ;
F_2 ( 0x800 , V_25 + V_423 ) ;
}
static void F_161 ( struct V_17 * V_18 ,
void T_1 * V_12 )
{
void T_1 * V_13 = F_6 ( V_12 , 0 ) ;
F_150 ( 0x00c ) ;
F_150 ( 0x010 ) ;
F_150 ( 0x014 ) ;
}
static int F_162 ( struct V_17 * V_18 ,
void T_1 * V_12 , unsigned int V_424 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 -> V_86 ; V_3 ++ )
F_160 ( V_18 , V_12 , V_3 ) ;
F_161 ( V_18 , V_12 ) ;
return 0 ;
}
static void F_163 ( struct V_17 * V_18 ,
void T_1 * V_12 )
{
return;
}
static void F_164 ( struct V_15 * V_16 , void T_1 * V_12 )
{
return;
}
static void F_165 ( struct V_17 * V_18 ,
void T_1 * V_12 , unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
T_2 V_118 ;
V_118 = F_3 ( V_25 + V_449 ) ;
V_118 &= ~ ( 0x3 << 27 ) ;
V_118 |= ( 0x1 << 27 ) ;
V_118 &= ~ ( 0x3 << 29 ) ;
V_118 |= ( 0x1 << 29 ) ;
F_2 ( V_118 , V_25 + V_449 ) ;
V_118 = F_3 ( V_25 + V_451 ) ;
V_118 &= ~ 0x1 ;
V_118 |= ( 0x1 << 16 ) ;
F_2 ( V_118 , V_25 + V_451 ) ;
V_118 = F_3 ( V_25 + V_457 ) ;
V_118 &= ~ 0xf ;
V_118 |= 0x8 ;
V_118 &= ~ ( 0x1 << 14 ) ;
F_2 ( V_118 , V_25 + V_457 ) ;
V_118 = F_3 ( V_25 + V_458 ) ;
V_118 &= ~ 0xf ;
V_118 |= 0x8 ;
V_118 &= ~ ( 0x1 << 14 ) ;
F_2 ( V_118 , V_25 + V_458 ) ;
}
static bool F_166 ( struct V_17 * V_18 )
{
void T_1 * V_459 = F_8 ( V_18 -> V_6 , 0 ) ;
if ( F_3 ( V_459 + V_460 ) )
return true ;
return false ;
}
static void F_167 ( void T_1 * V_25 , int V_461 )
{
T_2 V_462 = F_3 ( V_25 + V_463 ) ;
V_462 = ( V_462 & 0xf7f ) | 0x9b1000 ;
if ( V_461 )
V_462 |= ( 1 << 7 ) ;
F_1 ( V_462 , V_25 + V_463 ) ;
}
static void F_149 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_22 )
{
void T_1 * V_25 = F_8 ( V_12 , V_22 ) ;
F_32 ( V_25 ) ;
F_1 ( V_464 , V_25 + V_108 ) ;
if ( ! F_25 ( V_18 ) ) {
F_167 ( V_25 , 1 ) ;
}
F_1 ( V_464 , V_25 + V_108 ) ;
F_31 ( 25 ) ;
F_1 ( 0 , V_25 + V_108 ) ;
V_18 -> V_246 -> V_465 ( V_18 , V_12 , V_22 ) ;
if ( F_25 ( V_18 ) )
F_168 ( 1 ) ;
}
static void F_96 ( struct V_20 * V_21 , int V_277 )
{
if ( F_169 ( V_21 ) ) {
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_118 = F_3 ( V_25 + V_320 ) ;
int V_37 = V_118 & 0xf ;
if ( V_37 != V_277 ) {
V_118 = ( V_118 & ~ 0xf ) | V_277 ;
F_1 ( V_118 , V_25 + V_320 ) ;
}
}
}
static int F_170 ( struct V_143 * V_144 , unsigned int * V_466 ,
unsigned long V_467 )
{
F_96 ( V_144 -> V_21 , F_171 ( V_144 ) ) ;
return F_172 ( V_144 , V_466 , V_467 ) ;
}
static int F_173 ( struct V_143 * V_144 , unsigned int * V_466 ,
unsigned long V_467 )
{
F_96 ( V_144 -> V_21 , F_171 ( V_144 ) ) ;
return F_174 ( V_144 , V_466 , V_467 ) ;
}
static int F_175 ( struct V_143 * V_144 , unsigned int * V_466 ,
unsigned long V_467 )
{
struct V_20 * V_21 = V_144 -> V_21 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
struct V_26 * V_27 = V_21 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
int V_436 , V_468 = 0 , V_469 = 0 ;
T_2 V_470 ;
bool V_471 ;
F_149 ( V_18 , V_12 , V_21 -> V_22 ) ;
V_27 -> V_103 &= ~ V_104 ;
V_27 -> V_103 &=
~ ( V_188 | V_106 | V_189 ) ;
do {
const unsigned long * V_472 =
F_176 ( & V_144 -> V_473 ) ;
V_436 = F_177 ( V_144 , V_472 , V_467 + V_469 ,
& V_471 , NULL ) ;
V_436 = V_471 ? - V_474 : V_436 ;
if ( V_436 )
return V_436 ;
F_119 ( V_144 , V_137 , & V_470 ) ;
if ( ! F_25 ( V_18 ) && ++ V_468 >= 5 && V_470 == 0x121 ) {
F_167 ( F_11 ( V_21 ) , 0 ) ;
if ( F_178 ( V_475 + V_476 , V_467 ) )
V_469 = V_476 ;
}
} while ( V_470 != 0x0 && V_470 != 0x113 && V_470 != 0x123 );
F_13 ( V_21 ) ;
F_29 ( V_21 , 0 , 0 ) ;
return V_436 ;
}
static void F_114 ( struct V_20 * V_21 )
{
F_28 ( V_21 ) ;
F_19 ( V_21 , 0 ) ;
}
static void F_179 ( struct V_20 * V_21 )
{
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
unsigned int V_3 = V_21 -> V_22 ;
unsigned int V_70 = F_5 ( V_3 ) ;
void T_1 * V_13 = F_7 ( V_18 -> V_6 , V_3 ) ;
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_74 ;
F_2 ( 0 , V_25 + V_75 ) ;
V_74 = ~ ( ( V_76 | V_77 ) << V_70 ) ;
F_1 ( V_74 , V_13 + V_78 ) ;
F_19 ( V_21 , V_72 ) ;
}
static void F_180 ( struct V_477 * V_3 , void T_1 * V_25 )
{
void T_1 * V_365 , * V_478 = V_25 + V_479 ;
V_3 -> V_480 = V_478 + ( sizeof( T_2 ) * V_481 ) ;
V_3 -> V_482 =
V_3 -> V_483 = V_478 + ( sizeof( T_2 ) * V_484 ) ;
V_3 -> V_485 = V_478 + ( sizeof( T_2 ) * V_289 ) ;
V_3 -> V_486 = V_478 + ( sizeof( T_2 ) * V_297 ) ;
V_3 -> V_487 = V_478 + ( sizeof( T_2 ) * V_300 ) ;
V_3 -> V_488 = V_478 + ( sizeof( T_2 ) * V_303 ) ;
V_3 -> V_489 = V_478 + ( sizeof( T_2 ) * V_305 ) ;
V_3 -> V_311 =
V_3 -> V_490 = V_478 + ( sizeof( T_2 ) * V_491 ) ;
V_3 -> V_259 = V_3 -> V_492 = V_478 + V_493 ;
V_365 = V_25 + F_41 ( V_139 ) ;
F_1 ( F_3 ( V_365 ) , V_365 ) ;
F_1 ( 0 , V_25 + V_75 ) ;
F_1 ( ~ V_360 , V_25 + V_494 ) ;
F_181 ( L_40 ,
F_3 ( V_25 + V_195 ) ,
F_3 ( V_25 + V_75 ) ,
F_3 ( V_25 + V_494 ) ) ;
}
static unsigned int F_182 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
T_2 V_118 ;
if ( F_56 ( V_18 ) || ! F_183 ( V_18 ) )
return 0 ;
V_118 = F_3 ( V_12 + V_425 ) ;
if ( ( V_118 & V_495 ) == 0 )
return 0 ;
return 1 ;
}
static int F_184 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
T_2 V_118 ;
if ( ! F_182 ( V_16 ) ) {
V_118 = F_3 ( V_12 + V_496 ) ;
if ( V_118 & V_497 )
return 0 ;
}
return 1 ;
}
static void F_185 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
if ( F_182 ( V_16 ) ) {
T_2 V_118 = F_3 ( V_12 + V_496 ) ;
F_1 ( V_118 & ~ V_498 , V_12 + V_496 ) ;
}
}
static int F_186 ( struct V_15 * V_16 , unsigned int V_499 )
{
struct V_125 * V_126 = F_133 ( V_16 -> V_162 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
T_2 V_147 = V_18 -> V_147 ;
switch ( V_499 ) {
case V_500 :
V_18 -> V_246 = & V_501 ;
V_147 |= V_502 ;
switch ( V_126 -> V_411 ) {
case 0x1 :
V_147 |= V_420 ;
break;
case 0x3 :
V_147 |= V_503 ;
break;
default:
F_187 ( & V_126 -> V_162 ,
L_41 ) ;
V_147 |= V_503 ;
break;
}
break;
case V_504 :
case V_505 :
V_18 -> V_246 = & V_501 ;
V_147 |= V_502 ;
switch ( V_126 -> V_411 ) {
case 0x0 :
V_147 |= V_420 ;
break;
case 0x3 :
V_147 |= V_503 ;
break;
default:
F_187 ( & V_126 -> V_162 ,
L_42 ) ;
V_147 |= V_503 ;
break;
}
break;
case V_506 :
case V_507 :
V_18 -> V_246 = & V_508 ;
V_147 |= V_509 ;
switch ( V_126 -> V_411 ) {
case 0x7 :
F_185 ( V_16 ) ;
V_147 |= V_445 ;
break;
case 0x9 :
V_147 |= V_209 ;
break;
default:
F_187 ( & V_126 -> V_162 ,
L_42 ) ;
V_147 |= V_445 ;
break;
}
break;
case V_510 :
V_147 |= V_511 | V_193 ;
if ( V_126 -> V_512 == V_513 &&
( V_126 -> V_205 == 0x2300 || V_126 -> V_205 == 0x2310 ) )
{
F_36 (KERN_WARNING DRV_NAME L_43
L_44
L_45
L_46 ) ;
F_36 (KERN_WARNING DRV_NAME L_47
L_48
L_49
L_50 ) ;
}
case V_514 :
V_18 -> V_246 = & V_508 ;
V_147 |= V_515 ;
if ( V_499 == V_514 && F_184 ( V_16 ) )
V_147 |= V_193 ;
switch ( V_126 -> V_411 ) {
case 0x2 :
V_147 |= V_209 ;
break;
default:
F_187 ( & V_126 -> V_162 ,
L_51 ) ;
V_147 |= V_209 ;
break;
}
break;
case V_516 :
if ( F_166 ( V_18 ) )
V_18 -> V_246 = & V_517 ;
else
V_18 -> V_246 = & V_518 ;
V_147 |= V_519 | V_515 |
V_209 ;
break;
default:
F_132 ( V_16 -> V_162 , L_52 , V_499 ) ;
return 1 ;
}
V_18 -> V_147 = V_147 ;
if ( V_147 & V_511 ) {
V_18 -> V_401 = V_520 ;
V_18 -> V_430 = V_521 ;
V_18 -> V_522 = V_523 ;
} else {
V_18 -> V_401 = V_524 ;
V_18 -> V_430 = V_525 ;
V_18 -> V_522 = V_526 ;
}
return 0 ;
}
static int F_188 ( struct V_15 * V_16 )
{
int V_436 = 0 , V_424 , V_3 , V_7 ;
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
V_436 = F_186 ( V_16 , V_18 -> V_499 ) ;
if ( V_436 )
goto V_440;
if ( F_56 ( V_18 ) ) {
V_18 -> V_408 = V_12 + V_527 ;
V_18 -> V_62 = V_12 + V_528 ;
} else {
V_18 -> V_408 = V_12 + V_529 ;
V_18 -> V_62 = V_12 + V_530 ;
}
V_18 -> V_67 = F_3 ( V_18 -> V_62 ) ;
F_18 ( V_16 , ~ 0 , 0 ) ;
V_424 = F_12 ( V_16 -> V_184 [ 0 ] -> V_83 ) ;
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ )
if ( V_18 -> V_246 -> V_531 )
V_18 -> V_246 -> V_531 ( V_18 , V_3 , V_12 ) ;
V_436 = V_18 -> V_246 -> V_532 ( V_18 , V_12 , V_424 ) ;
if ( V_436 )
goto V_440;
V_18 -> V_246 -> V_533 ( V_18 , V_12 ) ;
V_18 -> V_246 -> V_534 ( V_16 , V_12 ) ;
V_18 -> V_246 -> V_535 ( V_18 , V_12 ) ;
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ ) {
struct V_20 * V_21 = V_16 -> V_184 [ V_3 ] ;
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
F_180 ( & V_21 -> V_258 , V_25 ) ;
}
for ( V_7 = 0 ; V_7 < V_424 ; V_7 ++ ) {
void T_1 * V_13 = F_6 ( V_12 , V_7 ) ;
F_181 ( L_53
L_54 , V_7 ,
F_3 ( V_13 + V_536 ) ,
F_3 ( V_13 + V_78 ) ) ;
F_1 ( 0 , V_13 + V_78 ) ;
}
if ( ! F_56 ( V_18 ) ) {
F_1 ( 0 , V_12 + V_18 -> V_401 ) ;
F_1 ( V_18 -> V_522 , V_12 + V_18 -> V_430 ) ;
}
F_18 ( V_16 , 0 , V_409 ) ;
F_23 ( V_16 , V_537 ,
V_538 ) ;
V_440:
return V_436 ;
}
static int F_189 ( struct V_17 * V_18 , struct V_205 * V_162 )
{
V_18 -> V_198 = F_190 ( L_55 , V_162 , V_539 ,
V_539 , 0 ) ;
if ( ! V_18 -> V_198 )
return - V_207 ;
V_18 -> V_200 = F_190 ( L_56 , V_162 , V_540 ,
V_540 , 0 ) ;
if ( ! V_18 -> V_200 )
return - V_207 ;
V_18 -> V_203 = F_190 ( L_57 , V_162 , V_541 ,
V_541 , 0 ) ;
if ( ! V_18 -> V_203 )
return - V_207 ;
return 0 ;
}
static void F_191 ( struct V_17 * V_18 ,
const struct V_542 * V_543 )
{
int V_114 ;
for ( V_114 = 0 ; V_114 < 4 ; V_114 ++ ) {
F_2 ( 0 , V_18 -> V_6 + F_192 ( V_114 ) ) ;
F_2 ( 0 , V_18 -> V_6 + F_193 ( V_114 ) ) ;
}
for ( V_114 = 0 ; V_114 < V_543 -> V_544 ; V_114 ++ ) {
const struct V_545 * V_546 = V_543 -> V_546 + V_114 ;
F_2 ( ( ( V_546 -> V_547 - 1 ) & 0xffff0000 ) |
( V_546 -> V_548 << 8 ) |
( V_543 -> V_549 << 4 ) | 1 ,
V_18 -> V_6 + F_192 ( V_114 ) ) ;
F_2 ( V_546 -> V_6 , V_18 -> V_6 + F_193 ( V_114 ) ) ;
}
}
static int F_194 ( struct V_550 * V_126 )
{
const struct V_551 * V_552 ;
const struct V_542 * V_543 ;
const struct F_112 * V_553 [] =
{ & V_554 [ V_516 ] , NULL } ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_555 * V_556 ;
void T_1 * V_12 ;
int V_86 = 0 , V_403 = 0 ;
int V_436 ;
int V_3 ;
F_195 ( & V_126 -> V_162 , V_557 ) ;
if ( F_48 ( V_126 -> V_558 != 2 ) ) {
F_132 ( & V_126 -> V_162 , L_58 ) ;
return - V_146 ;
}
V_556 = F_196 ( V_126 , V_559 , 0 ) ;
V_12 = F_197 ( & V_126 -> V_162 , V_556 ) ;
if ( F_198 ( V_12 ) )
return F_199 ( V_12 ) ;
if ( V_126 -> V_162 . V_560 ) {
V_436 = F_200 ( V_126 -> V_162 . V_560 , L_59 ,
& V_86 ) ;
if ( V_436 ) {
F_132 ( & V_126 -> V_162 ,
L_60 , V_436 ) ;
return V_436 ;
}
if ( V_86 <= 0 ) {
F_132 ( & V_126 -> V_162 , L_61 ,
V_86 ) ;
return - V_146 ;
}
V_403 = F_201 ( V_126 -> V_162 . V_560 , 0 ) ;
} else {
V_552 = F_202 ( & V_126 -> V_162 ) ;
V_86 = V_552 -> V_86 ;
V_403 = F_203 ( V_126 , 0 ) ;
}
V_16 = F_204 ( & V_126 -> V_162 , V_553 , V_86 ) ;
V_18 = F_60 ( & V_126 -> V_162 , sizeof( * V_18 ) , V_206 ) ;
if ( ! V_16 || ! V_18 )
return - V_207 ;
V_18 -> V_561 = F_60 ( & V_126 -> V_162 ,
sizeof( struct V_562 * ) * V_86 ,
V_206 ) ;
if ( ! V_18 -> V_561 )
return - V_207 ;
V_18 -> V_563 = F_60 ( & V_126 -> V_162 ,
sizeof( struct V_564 * ) * V_86 ,
V_206 ) ;
if ( ! V_18 -> V_563 )
return - V_207 ;
V_16 -> V_19 = V_18 ;
V_18 -> V_499 = V_516 ;
V_16 -> V_565 = NULL ;
V_18 -> V_6 = V_12 - V_8 ;
V_18 -> V_562 = F_205 ( & V_126 -> V_162 , NULL ) ;
if ( F_198 ( V_18 -> V_562 ) )
F_206 ( & V_126 -> V_162 , L_62 ) ;
else
F_207 ( V_18 -> V_562 ) ;
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
char V_566 [ 16 ] ;
sprintf ( V_566 , L_63 , V_3 ) ;
V_18 -> V_561 [ V_3 ] = F_205 ( & V_126 -> V_162 , V_566 ) ;
if ( ! F_198 ( V_18 -> V_561 [ V_3 ] ) )
F_207 ( V_18 -> V_561 [ V_3 ] ) ;
sprintf ( V_566 , L_64 , V_3 ) ;
V_18 -> V_563 [ V_3 ] = F_208 ( & V_126 -> V_162 ,
V_566 ) ;
if ( F_198 ( V_18 -> V_563 [ V_3 ] ) ) {
V_436 = F_199 ( V_18 -> V_563 [ V_3 ] ) ;
V_18 -> V_563 [ V_3 ] = NULL ;
if ( V_436 != - V_567 )
F_187 ( & V_126 -> V_162 , L_65 , V_436 ) ;
V_18 -> V_86 = V_3 ;
goto V_120;
} else
F_209 ( V_18 -> V_563 [ V_3 ] ) ;
}
V_18 -> V_86 = V_86 ;
V_543 = F_210 () ;
if ( V_543 )
F_191 ( V_18 , V_543 ) ;
V_436 = F_189 ( V_18 , & V_126 -> V_162 ) ;
if ( V_436 )
goto V_120;
if ( V_126 -> V_162 . V_560 &&
F_211 ( V_126 -> V_162 . V_560 ,
L_66 ) )
V_18 -> V_147 |= V_148 ;
V_436 = F_188 ( V_16 ) ;
if ( V_436 )
goto V_120;
F_212 ( & V_126 -> V_162 , L_67 ,
( unsigned ) V_201 , V_16 -> V_86 ) ;
V_436 = F_213 ( V_16 , V_403 , F_135 , V_568 , & V_569 ) ;
if ( ! V_436 )
return 0 ;
V_120:
if ( ! F_198 ( V_18 -> V_562 ) ) {
F_214 ( V_18 -> V_562 ) ;
F_215 ( V_18 -> V_562 ) ;
}
for ( V_3 = 0 ; V_3 < V_18 -> V_86 ; V_3 ++ ) {
if ( ! F_198 ( V_18 -> V_561 [ V_3 ] ) ) {
F_214 ( V_18 -> V_561 [ V_3 ] ) ;
F_215 ( V_18 -> V_561 [ V_3 ] ) ;
}
F_216 ( V_18 -> V_563 [ V_3 ] ) ;
}
return V_436 ;
}
static int F_217 ( struct V_550 * V_126 )
{
struct V_15 * V_16 = F_218 ( V_126 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
int V_3 ;
F_219 ( V_16 ) ;
if ( ! F_198 ( V_18 -> V_562 ) ) {
F_214 ( V_18 -> V_562 ) ;
F_215 ( V_18 -> V_562 ) ;
}
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ ) {
if ( ! F_198 ( V_18 -> V_561 [ V_3 ] ) ) {
F_214 ( V_18 -> V_561 [ V_3 ] ) ;
F_215 ( V_18 -> V_561 [ V_3 ] ) ;
}
F_216 ( V_18 -> V_563 [ V_3 ] ) ;
}
return 0 ;
}
static int F_220 ( struct V_550 * V_126 , T_8 V_570 )
{
struct V_15 * V_16 = F_218 ( V_126 ) ;
if ( V_16 )
return F_221 ( V_16 , V_570 ) ;
else
return 0 ;
}
static int F_222 ( struct V_550 * V_126 )
{
struct V_15 * V_16 = F_218 ( V_126 ) ;
const struct V_542 * V_543 ;
int V_571 ;
if ( V_16 ) {
struct V_17 * V_18 = V_16 -> V_19 ;
V_543 = F_210 () ;
if ( V_543 )
F_191 ( V_18 , V_543 ) ;
V_571 = F_188 ( V_16 ) ;
if ( V_571 ) {
F_36 (KERN_ERR DRV_NAME L_68 ) ;
return V_571 ;
}
F_223 ( V_16 ) ;
}
return 0 ;
}
static int F_224 ( struct V_125 * V_126 )
{
int V_436 ;
if ( ! F_225 ( & V_126 -> V_162 , F_226 ( 64 ) ) ) {
V_436 = F_227 ( & V_126 -> V_162 , F_226 ( 64 ) ) ;
if ( V_436 ) {
V_436 = F_227 ( & V_126 -> V_162 , F_226 ( 32 ) ) ;
if ( V_436 ) {
F_132 ( & V_126 -> V_162 ,
L_69 ) ;
return V_436 ;
}
}
} else {
V_436 = F_225 ( & V_126 -> V_162 , F_226 ( 32 ) ) ;
if ( V_436 ) {
F_132 ( & V_126 -> V_162 , L_70 ) ;
return V_436 ;
}
V_436 = F_227 ( & V_126 -> V_162 , F_226 ( 32 ) ) ;
if ( V_436 ) {
F_132 ( & V_126 -> V_162 ,
L_71 ) ;
return V_436 ;
}
}
return V_436 ;
}
static void F_228 ( struct V_15 * V_16 )
{
struct V_125 * V_126 = F_133 ( V_16 -> V_162 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
T_3 V_572 ;
const char * V_573 , * V_574 ;
F_229 ( V_126 , V_575 , & V_572 ) ;
if ( V_572 == 0 )
V_573 = L_72 ;
else if ( V_572 == 0x01 )
V_573 = L_73 ;
else
V_573 = L_74 ;
if ( F_25 ( V_18 ) )
V_574 = L_75 ;
else if ( F_55 ( V_18 ) )
V_574 = L_76 ;
else if ( F_22 ( V_18 ) )
V_574 = L_77 ;
else
V_574 = L_74 ;
F_212 ( & V_126 -> V_162 , L_78 ,
V_574 , ( unsigned ) V_201 , V_16 -> V_86 ,
V_573 , ( V_406 & V_18 -> V_147 ) ? L_79 : L_80 ) ;
}
static int F_230 ( struct V_125 * V_126 ,
const struct V_576 * V_577 )
{
unsigned int V_499 = ( unsigned int ) V_577 -> V_578 ;
const struct F_112 * V_553 [] = { & V_554 [ V_499 ] , NULL } ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_86 , V_3 , V_436 ;
F_195 ( & V_126 -> V_162 , V_557 ) ;
V_86 = F_12 ( V_553 [ 0 ] -> V_83 ) * V_87 ;
V_16 = F_204 ( & V_126 -> V_162 , V_553 , V_86 ) ;
V_18 = F_60 ( & V_126 -> V_162 , sizeof( * V_18 ) , V_206 ) ;
if ( ! V_16 || ! V_18 )
return - V_207 ;
V_16 -> V_19 = V_18 ;
V_18 -> V_86 = V_86 ;
V_18 -> V_499 = V_499 ;
V_436 = F_231 ( V_126 ) ;
if ( V_436 )
return V_436 ;
V_436 = F_232 ( V_126 , 1 << V_579 , V_336 ) ;
if ( V_436 == - V_580 )
F_233 ( V_126 ) ;
if ( V_436 )
return V_436 ;
V_16 -> V_565 = F_234 ( V_126 ) ;
V_18 -> V_6 = V_16 -> V_565 [ V_579 ] ;
V_436 = F_224 ( V_126 ) ;
if ( V_436 )
return V_436 ;
V_436 = F_189 ( V_18 , & V_126 -> V_162 ) ;
if ( V_436 )
return V_436 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ ) {
struct V_20 * V_21 = V_16 -> V_184 [ V_3 ] ;
void T_1 * V_25 = F_8 ( V_18 -> V_6 , V_3 ) ;
unsigned int V_217 = V_25 - V_18 -> V_6 ;
F_235 ( V_21 , V_579 , - 1 , L_81 ) ;
F_235 ( V_21 , V_579 , V_217 , L_82 ) ;
}
V_436 = F_188 ( V_16 ) ;
if ( V_436 )
return V_436 ;
if ( V_581 && F_236 ( V_126 ) == 0 )
V_18 -> V_147 |= V_406 ;
F_37 ( V_126 , 0x68 ) ;
F_228 ( V_16 ) ;
F_237 ( V_126 ) ;
F_238 ( V_126 ) ;
return F_213 ( V_16 , V_126 -> V_403 , F_135 , V_568 ,
F_25 ( V_18 ) ? & V_582 : & V_569 ) ;
}
static int F_239 ( struct V_125 * V_126 )
{
struct V_15 * V_16 = F_240 ( V_126 ) ;
int V_436 ;
V_436 = F_241 ( V_126 ) ;
if ( V_436 )
return V_436 ;
V_436 = F_188 ( V_16 ) ;
if ( V_436 )
return V_436 ;
F_223 ( V_16 ) ;
return 0 ;
}
static int T_9 F_242 ( void )
{
int V_436 = - V_583 ;
#ifdef F_243
V_436 = F_244 ( & V_584 ) ;
if ( V_436 < 0 )
return V_436 ;
#endif
V_436 = F_245 ( & V_585 ) ;
#ifdef F_243
if ( V_436 < 0 )
F_246 ( & V_584 ) ;
#endif
return V_436 ;
}
static void T_10 F_247 ( void )
{
#ifdef F_243
F_246 ( & V_584 ) ;
#endif
F_248 ( & V_585 ) ;
}
