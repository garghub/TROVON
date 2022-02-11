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
memset ( V_27 -> V_197 , 0 , V_208 ) ;
V_27 -> V_199 = F_61 ( V_18 -> V_200 , V_206 , & V_27 -> V_51 ) ;
if ( ! V_27 -> V_199 )
goto V_209;
memset ( V_27 -> V_199 , 0 , V_210 ) ;
if ( V_18 -> V_147 & V_211 )
V_21 -> V_83 |= V_212 ;
for ( V_196 = 0 ; V_196 < V_201 ; ++ V_196 ) {
if ( V_196 == 0 || ! F_25 ( V_18 ) ) {
V_27 -> V_202 [ V_196 ] = F_61 ( V_18 -> V_203 ,
V_206 , & V_27 -> V_204 [ V_196 ] ) ;
if ( ! V_27 -> V_202 [ V_196 ] )
goto V_209;
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
V_209:
F_57 ( V_21 ) ;
return - V_207 ;
}
static void F_62 ( struct V_20 * V_21 )
{
unsigned long V_83 ;
F_24 ( V_21 -> V_92 , V_83 ) ;
F_28 ( V_21 ) ;
F_19 ( V_21 , 0 ) ;
F_26 ( V_21 -> V_92 , V_83 ) ;
F_57 ( V_21 ) ;
}
static void F_63 ( struct V_160 * V_161 )
{
struct V_26 * V_27 = V_161 -> V_21 -> V_19 ;
struct V_213 * V_214 ;
struct V_215 * V_215 , * V_216 = NULL ;
unsigned int V_217 ;
V_215 = V_27 -> V_202 [ V_161 -> V_196 ] ;
F_64 (qc->sg, sg, qc->n_elem, si) {
T_4 V_2 = F_65 ( V_214 ) ;
T_2 V_218 = F_66 ( V_214 ) ;
while ( V_218 ) {
T_2 V_219 = V_2 & 0xffff ;
T_2 V_220 = V_218 ;
if ( V_219 + V_220 > 0x10000 )
V_220 = 0x10000 - V_219 ;
V_215 -> V_2 = F_67 ( V_2 & 0xffffffff ) ;
V_215 -> V_221 = F_67 ( ( V_2 >> 16 ) >> 16 ) ;
V_215 -> V_222 = F_67 ( V_220 & 0xffff ) ;
V_215 -> V_223 = 0 ;
V_218 -= V_220 ;
V_2 += V_220 ;
V_216 = V_215 ;
V_215 ++ ;
}
}
if ( F_68 ( V_216 ) )
V_216 -> V_222 |= F_67 ( V_224 ) ;
F_69 () ;
}
static void F_70 ( T_5 * V_225 , T_3 V_1 , T_3 V_2 , unsigned V_226 )
{
T_6 V_227 = V_1 | ( V_2 << V_228 ) | V_229 |
( V_226 ? V_230 : 0 ) ;
* V_225 = F_71 ( V_227 ) ;
}
static void F_72 ( struct V_20 * V_21 )
{
F_21 ( V_21 , F_11 ( V_21 ) , V_72 ) ;
}
static int F_73 ( struct V_160 * V_161 )
{
struct V_231 * V_232 = V_161 -> V_233 ;
if ( V_232 ) {
switch ( V_232 -> V_234 [ 0 ] ) {
case V_235 :
case V_236 :
case V_237 :
case V_238 :
case V_239 :
case V_240 :
case V_241 :
case V_242 :
case V_243 :
return 0 ;
}
}
return - V_244 ;
}
static void F_74 ( struct V_160 * V_161 )
{
struct V_20 * V_21 = V_161 -> V_21 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
F_63 ( V_161 ) ;
F_2 ( 0 , V_25 + V_245 ) ;
F_2 ( ( V_27 -> V_204 [ V_161 -> V_196 ] >> 16 ) >> 16 ,
V_25 + V_246 ) ;
F_1 ( V_27 -> V_204 [ V_161 -> V_196 ] ,
V_25 + V_247 ) ;
V_21 -> V_248 -> V_249 ( V_21 , & V_161 -> V_168 ) ;
}
static void F_75 ( struct V_160 * V_161 )
{
struct V_20 * V_21 = V_161 -> V_21 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
unsigned int V_250 = ( V_161 -> V_168 . V_83 & V_251 ) ;
T_2 V_252 = ( V_250 ? 0 : V_253 ) | V_254 ;
F_1 ( V_252 , V_25 + V_245 ) ;
}
static void F_76 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_252 ;
V_252 = F_3 ( V_25 + V_245 ) ;
if ( V_252 & V_254 ) {
V_252 &= ~ V_254 ;
F_1 ( V_252 , V_25 + V_245 ) ;
F_77 ( V_21 ) ;
}
}
static void F_78 ( struct V_160 * V_161 )
{
F_76 ( V_161 -> V_21 ) ;
}
static T_3 F_79 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_118 , V_255 ;
V_118 = F_3 ( V_25 + V_256 ) ;
if ( V_118 & V_257 )
V_255 = V_257 ;
else if ( V_118 & V_258 )
V_255 = ( V_118 & V_258 ) | V_259 ;
else {
F_76 ( V_21 ) ;
if ( F_80 ( V_21 -> V_260 . V_261 ) & V_262 )
V_255 = 0 ;
else
V_255 = V_259 ;
}
return V_255 ;
}
static void F_81 ( struct V_160 * V_161 )
{
struct V_263 * V_168 = & V_161 -> V_168 ;
if ( ( V_168 -> V_83 & V_251 ) && F_82 ( V_168 ) ) {
if ( V_161 -> V_162 -> V_264 > 7 ) {
switch ( V_168 -> V_265 ) {
case V_266 :
V_168 -> V_265 = V_267 ;
break;
case V_268 :
V_168 -> V_83 &= ~ V_269 ;
case V_270 :
V_168 -> V_265 = V_271 ;
break;
}
}
}
}
static void F_83 ( struct V_160 * V_161 )
{
struct V_20 * V_21 = V_161 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
T_5 * V_272 ;
struct V_263 * V_168 = & V_161 -> V_168 ;
T_6 V_83 = 0 ;
unsigned V_273 ;
switch ( V_168 -> V_100 ) {
case V_274 :
if ( V_168 -> V_265 == V_275 )
return;
case V_102 :
break;
case V_276 :
F_81 ( V_161 ) ;
return;
default:
return;
}
if ( ! ( V_168 -> V_83 & V_251 ) )
V_83 |= V_277 ;
F_16 ( V_201 <= V_161 -> V_196 ) ;
V_83 |= V_161 -> V_196 << V_278 ;
V_83 |= ( V_161 -> V_162 -> V_144 -> V_279 & 0xf ) << V_280 ;
V_273 = V_27 -> V_41 ;
V_27 -> V_197 [ V_273 ] . V_281 =
F_67 ( V_27 -> V_204 [ V_161 -> V_196 ] & 0xffffffff ) ;
V_27 -> V_197 [ V_273 ] . V_282 =
F_67 ( ( V_27 -> V_204 [ V_161 -> V_196 ] >> 16 ) >> 16 ) ;
V_27 -> V_197 [ V_273 ] . V_283 = F_71 ( V_83 ) ;
V_272 = & V_27 -> V_197 [ V_273 ] . V_284 [ 0 ] ;
switch ( V_168 -> V_265 ) {
case V_285 :
case V_286 :
case V_287 :
case V_288 :
case V_289 :
F_70 ( V_272 ++ , V_168 -> V_290 , V_291 , 0 ) ;
break;
case V_292 :
case V_293 :
F_70 ( V_272 ++ , V_168 -> V_294 , V_295 , 0 ) ;
F_70 ( V_272 ++ , V_168 -> V_296 , V_295 , 0 ) ;
break;
default:
F_84 ( V_168 -> V_265 ) ;
break;
}
F_70 ( V_272 ++ , V_168 -> V_297 , V_291 , 0 ) ;
F_70 ( V_272 ++ , V_168 -> V_298 , V_299 , 0 ) ;
F_70 ( V_272 ++ , V_168 -> V_300 , V_299 , 0 ) ;
F_70 ( V_272 ++ , V_168 -> V_301 , V_302 , 0 ) ;
F_70 ( V_272 ++ , V_168 -> V_303 , V_302 , 0 ) ;
F_70 ( V_272 ++ , V_168 -> V_304 , V_305 , 0 ) ;
F_70 ( V_272 ++ , V_168 -> V_306 , V_305 , 0 ) ;
F_70 ( V_272 ++ , V_168 -> V_205 , V_307 , 0 ) ;
F_70 ( V_272 ++ , V_168 -> V_265 , V_308 , 1 ) ;
if ( ! ( V_161 -> V_83 & V_309 ) )
return;
F_63 ( V_161 ) ;
}
static void F_85 ( struct V_160 * V_161 )
{
struct V_20 * V_21 = V_161 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_310 * V_197 ;
struct V_263 * V_168 = & V_161 -> V_168 ;
unsigned V_273 ;
T_2 V_83 = 0 ;
if ( ( V_168 -> V_100 != V_274 ) &&
( V_168 -> V_100 != V_102 ) )
return;
if ( V_168 -> V_265 == V_275 )
return;
if ( ! ( V_168 -> V_83 & V_251 ) )
V_83 |= V_277 ;
F_16 ( V_201 <= V_161 -> V_196 ) ;
V_83 |= V_161 -> V_196 << V_278 ;
V_83 |= V_161 -> V_196 << V_311 ;
V_83 |= ( V_161 -> V_162 -> V_144 -> V_279 & 0xf ) << V_280 ;
V_273 = V_27 -> V_41 ;
V_197 = (struct V_310 * ) & V_27 -> V_197 [ V_273 ] ;
V_197 -> V_2 = F_67 ( V_27 -> V_204 [ V_161 -> V_196 ] & 0xffffffff ) ;
V_197 -> V_221 = F_67 ( ( V_27 -> V_204 [ V_161 -> V_196 ] >> 16 ) >> 16 ) ;
V_197 -> V_83 = F_67 ( V_83 ) ;
V_197 -> V_284 [ 0 ] = F_67 (
( V_168 -> V_265 << 16 ) |
( V_168 -> V_296 << 24 )
) ;
V_197 -> V_284 [ 1 ] = F_67 (
( V_168 -> V_300 << 0 ) |
( V_168 -> V_303 << 8 ) |
( V_168 -> V_306 << 16 ) |
( V_168 -> V_205 << 24 )
) ;
V_197 -> V_284 [ 2 ] = F_67 (
( V_168 -> V_298 << 0 ) |
( V_168 -> V_301 << 8 ) |
( V_168 -> V_304 << 16 ) |
( V_168 -> V_294 << 24 )
) ;
V_197 -> V_284 [ 3 ] = F_67 (
( V_168 -> V_297 << 0 ) |
( V_168 -> V_290 << 8 )
) ;
if ( ! ( V_161 -> V_83 & V_309 ) )
return;
F_63 ( V_161 ) ;
}
static T_3 F_86 ( struct V_20 * V_21 )
{
T_3 V_312 = F_80 ( V_21 -> V_260 . V_313 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
if ( V_27 -> V_103 & V_189 ) {
if ( V_312 & ( V_262 | V_314 | V_315 ) )
V_27 -> V_103 &= ~ V_189 ;
else
V_312 = V_262 ;
}
return V_312 ;
}
static unsigned int F_87 ( struct V_20 * V_21 , T_2 * V_316 , int V_317 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_318 , V_319 , V_320 ;
int V_114 , V_113 = 200 , V_321 = V_317 - 1 ;
V_319 = F_3 ( V_25 + V_322 ) ;
V_318 = 0x100 | ( V_319 & 0xf ) ;
F_1 ( V_318 , V_25 + V_322 ) ;
for ( V_114 = 0 ; V_114 < V_321 ; ++ V_114 )
F_2 ( V_316 [ V_114 ] , V_25 + V_323 ) ;
F_1 ( V_318 | 0x200 , V_25 + V_322 ) ;
F_1 ( V_316 [ V_321 ] , V_25 + V_323 ) ;
do {
V_320 = F_3 ( V_25 + V_324 ) ;
} while ( ! ( V_320 & 0x1000 ) && -- V_113 );
F_1 ( V_319 , V_25 + V_322 ) ;
if ( ( V_320 & 0x3000 ) != 0x1000 ) {
F_88 ( V_21 , L_13 ,
V_325 , V_320 ) ;
return V_326 ;
}
return 0 ;
}
static unsigned int F_89 ( struct V_160 * V_161 )
{
struct V_20 * V_21 = V_161 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_143 * V_144 = V_161 -> V_162 -> V_144 ;
T_2 V_316 [ 5 ] ;
int V_120 = 0 ;
F_90 ( & V_161 -> V_168 , V_144 -> V_279 , 1 , ( void * ) V_316 ) ;
V_120 = F_87 ( V_21 , V_316 , F_91 ( V_316 ) ) ;
if ( V_120 )
return V_120 ;
switch ( V_161 -> V_168 . V_100 ) {
case V_327 :
V_27 -> V_103 |= V_189 ;
case V_328 :
V_21 -> V_329 = V_330 ;
break;
case V_276 :
V_27 -> V_103 |= V_189 ;
if ( V_161 -> V_168 . V_83 & V_251 )
V_21 -> V_329 = V_330 ;
else
V_21 -> V_329 = V_331 ;
break;
default:
V_21 -> V_329 = V_332 ;
break;
}
if ( V_161 -> V_168 . V_83 & V_333 )
F_92 ( V_144 , 0 ) ;
return 0 ;
}
static unsigned int F_93 ( struct V_160 * V_161 )
{
static int V_334 = 10 ;
struct V_20 * V_21 = V_161 -> V_21 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
T_2 V_273 ;
unsigned int V_73 ;
V_27 -> V_103 &= ~ V_189 ;
switch ( V_161 -> V_168 . V_100 ) {
case V_274 :
if ( V_161 -> V_168 . V_265 == V_275 ) {
if ( ! V_21 -> V_248 -> V_335 )
return V_326 ;
break;
}
case V_102 :
F_27 ( V_21 , V_25 , V_27 , V_161 -> V_168 . V_100 ) ;
V_27 -> V_41 = ( V_27 -> V_41 + 1 ) & V_42 ;
V_273 = V_27 -> V_41 << V_43 ;
F_1 ( ( V_27 -> V_44 & V_46 ) | V_273 ,
V_25 + V_47 ) ;
return 0 ;
case V_276 :
if ( V_334 > 0 && ( V_161 -> V_336 / V_161 -> V_337 ) > 1 ) {
-- V_334 ;
F_94 ( V_161 -> V_162 -> V_144 , V_338
L_14
L_15 ) ;
}
case V_339 :
case V_327 :
case V_328 :
if ( V_21 -> V_83 & V_340 )
V_161 -> V_168 . V_83 |= V_333 ;
break;
}
if ( V_161 -> V_168 . V_83 & V_333 )
V_73 = V_72 ;
else
V_73 = V_72 | V_71 ;
F_28 ( V_21 ) ;
F_21 ( V_21 , F_11 ( V_21 ) , V_73 ) ;
F_95 ( V_21 , V_161 -> V_162 -> V_144 -> V_279 ) ;
if ( V_161 -> V_168 . V_265 == V_341 ) {
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
if ( F_55 ( V_18 ) )
return F_89 ( V_161 ) ;
}
return F_96 ( V_161 ) ;
}
static struct V_160 * F_97 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_160 * V_161 ;
if ( V_27 -> V_103 & V_106 )
return NULL ;
V_161 = F_98 ( V_21 , V_21 -> V_144 . V_342 ) ;
if ( V_161 && ! ( V_161 -> V_168 . V_83 & V_333 ) )
return V_161 ;
return NULL ;
}
static void F_99 ( struct V_20 * V_21 )
{
unsigned int V_279 , V_343 ;
struct V_26 * V_27 = V_21 -> V_19 ;
if ( V_27 -> V_103 & V_163 ) {
V_343 = V_27 -> V_344 ;
V_27 -> V_103 &= ~ V_163 ;
for ( V_279 = 0 ; V_343 != 0 ; V_279 ++ ) {
unsigned int V_345 = ( 1 << V_279 ) ;
if ( V_343 & V_345 ) {
struct V_143 * V_144 = & V_21 -> V_346 [ V_279 ] ;
V_343 &= ~ V_345 ;
F_100 ( V_144 ) ;
}
}
F_101 ( V_21 ) ;
}
F_102 ( V_21 ) ;
}
static unsigned int F_103 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
return F_3 ( V_25 + V_347 ) >> 16 ;
}
static void F_104 ( struct V_20 * V_21 , unsigned int V_343 )
{
struct V_348 * V_349 ;
unsigned int V_279 ;
V_349 = & V_21 -> V_144 . V_350 ;
for ( V_279 = 0 ; V_343 != 0 ; V_279 ++ ) {
unsigned int V_345 = ( 1 << V_279 ) ;
if ( V_343 & V_345 ) {
struct V_143 * V_144 = & V_21 -> V_346 [ V_279 ] ;
V_343 &= ~ V_345 ;
V_349 = & V_144 -> V_350 ;
F_105 ( V_349 ) ;
F_106 ( V_349 , L_16 ) ;
V_349 -> V_351 |= V_352 ;
V_349 -> V_353 |= V_354 ;
F_107 ( V_144 ) ;
}
}
}
static int F_108 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_355 , V_356 ;
V_355 = ( F_3 ( V_25 + V_47 )
>> V_43 ) & V_42 ;
V_356 = ( F_3 ( V_25 + V_48 )
>> V_43 ) & V_42 ;
return ( V_355 == V_356 ) ;
}
static int F_109 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
int V_357 ;
unsigned int V_358 , V_359 ;
if ( ! ( V_27 -> V_103 & V_163 ) ) {
V_27 -> V_103 |= V_163 ;
V_27 -> V_344 = 0 ;
}
V_358 = V_27 -> V_344 ;
V_359 = V_358 | F_103 ( V_21 ) ;
if ( V_358 != V_359 ) {
V_27 -> V_344 = V_359 ;
F_104 ( V_21 , V_359 & ~ V_358 ) ;
}
V_357 = F_110 ( V_359 ) ;
F_111 ( V_21 ,
L_17 ,
V_325 , V_27 -> V_344 ,
V_21 -> V_360 , V_357 ,
V_21 -> V_166 ) ;
if ( V_21 -> V_166 <= V_357 && F_108 ( V_21 ) ) {
F_112 ( V_21 , V_27 ) ;
F_28 ( V_21 ) ;
F_113 ( V_21 ) ;
F_111 ( V_21 , L_18 , V_325 ) ;
return 1 ;
}
F_111 ( V_21 , L_19 , V_325 ) ;
return 1 ;
}
static int F_114 ( struct V_20 * V_21 )
{
return 0 ;
}
static int F_115 ( struct V_20 * V_21 , T_2 V_361 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
if ( ! ( V_27 -> V_103 & V_104 ) )
return 0 ;
if ( ! ( V_27 -> V_103 & V_188 ) )
return 0 ;
if ( ! ( V_361 & V_174 ) )
return 0 ;
V_361 &= ~ V_362 ;
if ( V_361 & ~ ( V_174 | V_363 ) )
return 0 ;
if ( V_27 -> V_103 & V_106 ) {
if ( V_361 & V_363 ) {
F_88 ( V_21 , L_20 ,
V_325 , V_361 , V_27 -> V_103 ) ;
return 0 ;
}
return F_109 ( V_21 ) ;
} else {
if ( ! ( V_361 & V_363 ) ) {
F_88 ( V_21 , L_20 ,
V_325 , V_361 , V_27 -> V_103 ) ;
return 0 ;
}
return F_114 ( V_21 ) ;
}
return 0 ;
}
static void F_116 ( struct V_20 * V_21 , int V_364 )
{
struct V_348 * V_349 = & V_21 -> V_144 . V_350 ;
char * V_365 = L_21 ;
F_105 ( V_349 ) ;
if ( V_364 ) {
V_365 = L_22 ;
} else {
struct V_160 * V_161 = F_98 ( V_21 , V_21 -> V_144 . V_342 ) ;
if ( V_161 && ( V_161 -> V_168 . V_83 & V_333 ) )
V_365 = L_23 ;
}
F_106 ( V_349 , L_24 , V_365 ) ;
V_349 -> V_351 |= V_326 ;
V_349 -> V_353 |= V_354 ;
F_101 ( V_21 ) ;
}
static void F_117 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_361 , V_366 , V_367 = 0 ;
T_2 V_368 = 0 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
unsigned int V_353 = 0 , V_351 = 0 ;
struct V_348 * V_349 = & V_21 -> V_144 . V_350 ;
struct V_160 * V_161 ;
int abort = 0 ;
F_118 ( & V_21 -> V_144 , V_139 , & V_367 ) ;
F_119 ( & V_21 -> V_144 , V_139 , V_367 ) ;
V_361 = F_3 ( V_25 + V_75 ) ;
if ( F_22 ( V_18 ) && ( V_361 & V_369 ) ) {
V_368 = F_3 ( V_25 + V_79 ) ;
F_1 ( ~ V_368 , V_25 + V_79 ) ;
}
F_1 ( ~ V_361 , V_25 + V_75 ) ;
if ( V_361 & V_174 ) {
if ( F_115 ( V_21 , V_361 ) )
return;
}
V_161 = F_97 ( V_21 ) ;
F_105 ( V_349 ) ;
F_106 ( V_349 , L_25 ,
V_361 , V_27 -> V_103 ) ;
if ( F_22 ( V_18 ) && ( V_361 & V_369 ) ) {
F_106 ( V_349 , L_26 , V_368 ) ;
if ( V_368 & V_370 ) {
T_2 V_371 = V_361 &
~ ( V_369 | V_362 ) ;
F_120 ( V_21 ) ;
if ( ! V_371 )
return;
F_106 ( V_349 , L_27 ) ;
}
}
if ( V_361 & V_174 ) {
V_351 |= V_352 ;
V_353 |= V_354 ;
F_106 ( V_349 , L_28 ) ;
}
if ( V_361 & ( V_372 | V_373 |
V_374 | V_375 |
V_376 ) ) {
V_351 |= V_377 ;
V_353 |= V_354 ;
F_106 ( V_349 , L_29 ) ;
}
if ( V_361 & ( V_378 | V_379 ) ) {
F_121 ( V_349 ) ;
F_106 ( V_349 , V_361 & V_378 ?
L_30 : L_31 ) ;
V_353 |= V_354 ;
}
if ( F_25 ( V_18 ) ) {
V_366 = V_380 ;
if ( V_361 & V_381 ) {
V_27 -> V_103 &= ~ V_104 ;
F_106 ( V_349 , L_32 ) ;
}
} else {
V_366 = V_382 ;
if ( V_361 & V_363 ) {
V_27 -> V_103 &= ~ V_104 ;
F_106 ( V_349 , L_32 ) ;
}
if ( V_361 & V_383 ) {
F_106 ( V_349 , L_33 , V_367 ) ;
V_351 |= V_377 ;
V_353 |= V_354 ;
}
}
if ( ! V_351 ) {
V_351 = V_326 ;
V_353 |= V_354 ;
}
V_349 -> V_384 |= V_367 ;
V_349 -> V_353 |= V_353 ;
if ( V_161 )
V_161 -> V_351 |= V_351 ;
else
V_349 -> V_351 |= V_351 ;
if ( V_351 == V_352 ) {
F_113 ( V_21 ) ;
abort = 1 ;
} else if ( V_361 & V_366 ) {
F_101 ( V_21 ) ;
} else {
abort = 1 ;
}
if ( abort ) {
if ( V_161 )
F_107 ( V_161 -> V_162 -> V_144 ) ;
else
F_122 ( V_21 ) ;
}
}
static bool F_123 ( struct V_20 * V_21 ,
struct V_385 * V_386 , unsigned int V_196 , int V_387 )
{
T_3 V_388 ;
T_6 V_389 = F_124 ( V_386 -> V_83 ) ;
if ( ! V_387 ) {
T_3 V_390 = V_389 & 0xff & ~ V_174 ;
if ( V_390 ) {
return false ;
}
}
V_388 = V_389 >> V_391 ;
if ( ! F_125 ( V_388 ) )
return true ;
return false ;
}
static void F_112 ( struct V_20 * V_21 , struct V_26 * V_27 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
T_2 V_273 ;
bool V_392 = false ;
T_2 V_393 = 0 ;
int V_387 = ( V_27 -> V_103 & V_106 ) ;
V_273 = ( F_3 ( V_25 + V_53 )
>> V_50 ) & V_42 ;
while ( V_273 != V_27 -> V_49 ) {
unsigned int V_196 ;
struct V_385 * V_386 = & V_27 -> V_199 [ V_27 -> V_49 ] ;
V_27 -> V_49 = ( V_27 -> V_49 + 1 ) & V_42 ;
if ( F_25 ( V_18 ) ) {
V_196 = V_21 -> V_144 . V_342 ;
} else {
V_196 = F_124 ( V_386 -> V_394 ) & 0x1f ;
}
if ( F_123 ( V_21 , V_386 , V_196 , V_387 ) )
V_393 |= 1 << V_196 ;
V_392 = true ;
}
if ( V_392 ) {
F_126 ( V_21 , V_21 -> V_360 ^ V_393 ) ;
F_1 ( ( V_27 -> V_51 & V_54 ) |
( V_27 -> V_49 << V_50 ) ,
V_25 + V_55 ) ;
}
}
static void F_127 ( struct V_20 * V_21 , T_2 V_395 )
{
struct V_26 * V_27 ;
int V_364 ;
V_27 = V_21 -> V_19 ;
V_364 = ( V_27 -> V_103 & V_104 ) ;
if ( V_364 && ( V_395 & V_71 ) ) {
F_112 ( V_21 , V_27 ) ;
if ( V_27 -> V_103 & V_163 )
F_109 ( V_21 ) ;
}
if ( F_48 ( V_395 & V_72 ) ) {
F_117 ( V_21 ) ;
} else if ( ! V_364 ) {
struct V_160 * V_161 = F_97 ( V_21 ) ;
if ( V_161 )
F_128 ( V_21 , V_161 ) ;
else
F_116 ( V_21 , V_364 ) ;
}
}
static int F_129 ( struct V_15 * V_16 , T_2 V_396 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 , * V_13 ;
unsigned int V_397 = 0 , V_3 ;
if ( V_396 & V_57 )
F_2 ( ~ V_95 , V_12 + V_96 ) ;
for ( V_3 = 0 ; V_3 < V_18 -> V_86 ; V_3 ++ ) {
struct V_20 * V_21 = V_16 -> V_184 [ V_3 ] ;
unsigned int V_133 , V_69 , V_70 , V_395 ;
F_20 ( V_3 , V_69 , V_70 ) ;
if ( V_70 == 0 ) {
T_2 V_398 = ( V_396 >> V_69 ) & V_399 ;
T_2 V_400 , V_401 ;
if ( ! V_398 ) {
V_3 += V_87 - 1 ;
continue;
}
V_401 = 0 ;
if ( V_398 & V_58 )
V_401 = V_99 ;
for ( V_133 = 0 ; V_133 < V_87 ; ++ V_133 ) {
if ( ( V_3 + V_133 ) >= V_18 -> V_86 )
break;
V_400 = ( V_71 | V_72 ) << ( V_133 * 2 ) ;
if ( V_398 & V_400 )
V_401 |= ( V_77 | V_76 ) << V_133 ;
}
V_13 = F_7 ( V_12 , V_3 ) ;
F_1 ( ~ V_401 , V_13 + V_78 ) ;
V_397 = 1 ;
}
V_395 = ( V_396 >> V_69 ) & ( V_71 | V_72 ) ;
if ( V_395 )
F_127 ( V_21 , V_395 ) ;
}
return V_397 ;
}
static int F_130 ( struct V_15 * V_16 , void T_1 * V_12 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 ;
struct V_160 * V_161 ;
struct V_348 * V_349 ;
unsigned int V_114 , V_351 , V_402 = 0 ;
T_2 V_390 ;
V_390 = F_3 ( V_12 + V_18 -> V_403 ) ;
F_131 ( V_16 -> V_162 , L_34 , V_390 ) ;
F_35 ( L_35 ) ;
F_40 ( V_12 , - 1 , F_132 ( V_16 -> V_162 ) ) ;
F_1 ( 0 , V_12 + V_18 -> V_403 ) ;
for ( V_114 = 0 ; V_114 < V_16 -> V_86 ; V_114 ++ ) {
V_21 = V_16 -> V_184 [ V_114 ] ;
if ( ! F_133 ( & V_21 -> V_144 ) ) {
V_349 = & V_21 -> V_144 . V_350 ;
F_105 ( V_349 ) ;
if ( ! V_402 ++ )
F_106 ( V_349 ,
L_36 , V_390 ) ;
V_351 = V_404 ;
V_349 -> V_353 = V_354 ;
V_161 = F_98 ( V_21 , V_21 -> V_144 . V_342 ) ;
if ( V_161 )
V_161 -> V_351 |= V_351 ;
else
V_349 -> V_351 |= V_351 ;
F_101 ( V_21 ) ;
}
}
return 1 ;
}
static T_7 F_134 ( int V_405 , void * V_406 )
{
struct V_15 * V_16 = V_406 ;
struct V_17 * V_18 = V_16 -> V_19 ;
unsigned int V_397 = 0 ;
int V_407 = V_18 -> V_147 & V_408 ;
T_2 V_396 , V_409 ;
F_135 ( & V_16 -> V_92 ) ;
if ( V_407 )
F_17 ( 0 , V_18 ) ;
V_396 = F_3 ( V_18 -> V_410 ) ;
V_409 = V_396 & V_18 -> V_67 ;
if ( V_409 && V_396 != 0xffffffffU ) {
if ( F_48 ( ( V_409 & V_411 ) && ! F_56 ( V_18 ) ) )
V_397 = F_130 ( V_16 , V_18 -> V_6 ) ;
else
V_397 = F_129 ( V_16 , V_409 ) ;
}
if ( V_407 )
F_17 ( V_18 -> V_67 , V_18 ) ;
F_136 ( & V_16 -> V_92 ) ;
return F_137 ( V_397 ) ;
}
static unsigned int F_138 ( unsigned int V_136 )
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
static int F_139 ( struct V_143 * V_144 , unsigned int V_136 , T_2 * V_145 )
{
struct V_17 * V_18 = V_144 -> V_21 -> V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
void T_1 * V_2 = F_9 ( V_12 , V_144 -> V_21 -> V_22 ) ;
unsigned int V_14 = F_138 ( V_136 ) ;
if ( V_14 != 0xffffffffU ) {
* V_145 = F_3 ( V_2 + V_14 ) ;
return 0 ;
} else
return - V_146 ;
}
static int F_140 ( struct V_143 * V_144 , unsigned int V_136 , T_2 V_145 )
{
struct V_17 * V_18 = V_144 -> V_21 -> V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
void T_1 * V_2 = F_9 ( V_12 , V_144 -> V_21 -> V_22 ) ;
unsigned int V_14 = F_138 ( V_136 ) ;
if ( V_14 != 0xffffffffU ) {
F_1 ( V_145 , V_2 + V_14 ) ;
return 0 ;
} else
return - V_146 ;
}
static void F_141 ( struct V_15 * V_16 , void T_1 * V_12 )
{
struct V_125 * V_126 = F_132 ( V_16 -> V_162 ) ;
int V_412 ;
V_412 = ( V_126 -> V_205 == 0x5080 ) && ( V_126 -> V_413 == 0 ) ;
if ( ! V_412 ) {
T_2 V_227 = F_3 ( V_12 + V_414 ) ;
V_227 |= ( 1 << 0 ) ;
F_2 ( V_227 , V_12 + V_414 ) ;
}
F_142 ( V_16 , V_12 ) ;
}
static void F_143 ( struct V_17 * V_18 , void T_1 * V_12 )
{
F_2 ( 0x0fcfffff , V_12 + V_415 ) ;
}
static void F_144 ( struct V_17 * V_18 , int V_416 ,
void T_1 * V_12 )
{
void T_1 * V_417 = F_9 ( V_12 , V_416 ) ;
T_2 V_227 ;
V_227 = F_3 ( V_417 + V_418 ) ;
V_18 -> signal [ V_416 ] . V_419 = V_227 & 0x1800 ;
V_18 -> signal [ V_416 ] . V_420 = V_227 & 0xe0 ;
}
static void F_145 ( struct V_17 * V_18 , void T_1 * V_12 )
{
T_2 V_227 ;
F_2 ( 0 , V_12 + V_177 ) ;
V_227 = F_3 ( V_12 + V_414 ) ;
V_227 |= ~ ( 1 << 0 ) ;
F_2 ( V_227 , V_12 + V_414 ) ;
}
static void F_146 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_3 )
{
void T_1 * V_417 = F_9 ( V_12 , V_3 ) ;
const T_2 V_56 = ( 1 << 12 ) | ( 1 << 11 ) | ( 1 << 7 ) | ( 1 << 6 ) | ( 1 << 5 ) ;
T_2 V_227 ;
int V_421 = ( V_18 -> V_147 & V_422 ) ;
if ( V_421 ) {
V_227 = F_3 ( V_417 + V_423 ) ;
V_227 |= ( 1 << 19 ) ;
F_2 ( V_227 , V_417 + V_423 ) ;
V_227 = F_3 ( V_417 + V_424 ) ;
V_227 &= ~ 0x3 ;
V_227 |= 0x1 ;
F_2 ( V_227 , V_417 + V_424 ) ;
}
V_227 = F_3 ( V_417 + V_418 ) ;
V_227 &= ~ V_56 ;
V_227 |= V_18 -> signal [ V_3 ] . V_419 ;
V_227 |= V_18 -> signal [ V_3 ] . V_420 ;
F_2 ( V_227 , V_417 + V_418 ) ;
}
static void F_147 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
F_148 ( V_18 , V_12 , V_3 ) ;
F_149 ( 0x028 ) ;
F_2 ( 0x11f , V_25 + V_195 ) ;
F_149 ( 0x004 ) ;
F_149 ( 0x008 ) ;
F_149 ( 0x00c ) ;
F_149 ( 0x010 ) ;
F_149 ( 0x014 ) ;
F_149 ( 0x018 ) ;
F_149 ( 0x01c ) ;
F_149 ( 0x024 ) ;
F_149 ( 0x020 ) ;
F_149 ( 0x02c ) ;
F_2 ( 0xbc , V_25 + V_425 ) ;
}
static void F_150 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_7 )
{
void T_1 * V_13 = F_6 ( V_12 , V_7 ) ;
T_2 V_227 ;
F_149 ( 0x00c ) ;
F_149 ( 0x010 ) ;
F_149 ( 0x014 ) ;
F_149 ( 0x018 ) ;
V_227 = F_3 ( V_13 + 0x20 ) ;
V_227 &= 0x1c1c1c1c ;
V_227 |= 0x03030303 ;
F_2 ( V_227 , V_13 + 0x20 ) ;
}
static int F_151 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_426 )
{
unsigned int V_7 , V_3 ;
for ( V_7 = 0 ; V_7 < V_426 ; V_7 ++ ) {
for ( V_3 = 0 ; V_3 < V_87 ; V_3 ++ )
F_147 ( V_18 , V_12 ,
( V_7 * V_87 ) + V_3 ) ;
F_150 ( V_18 , V_12 , V_7 ) ;
}
return 0 ;
}
static void F_142 ( struct V_15 * V_16 , void T_1 * V_12 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
T_2 V_227 ;
V_227 = F_3 ( V_12 + V_427 ) ;
V_227 &= 0xff00ffff ;
F_2 ( V_227 , V_12 + V_427 ) ;
F_149 ( V_428 ) ;
F_149 ( V_429 ) ;
F_2 ( 0x000100ff , V_12 + V_430 ) ;
F_149 ( V_431 ) ;
F_149 ( V_18 -> V_403 ) ;
F_149 ( V_18 -> V_432 ) ;
F_149 ( V_433 ) ;
F_149 ( V_434 ) ;
F_149 ( V_435 ) ;
F_149 ( V_436 ) ;
}
static void F_152 ( struct V_17 * V_18 , void T_1 * V_12 )
{
T_2 V_227 ;
F_143 ( V_18 , V_12 ) ;
V_227 = F_3 ( V_12 + V_177 ) ;
V_227 &= 0x3 ;
V_227 |= ( 1 << 5 ) | ( 1 << 6 ) ;
F_2 ( V_227 , V_12 + V_177 ) ;
}
static int F_153 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_426 )
{
void T_1 * V_118 = V_12 + V_437 ;
int V_114 , V_438 = 0 ;
T_2 V_439 ;
V_439 = F_3 ( V_118 ) ;
F_2 ( V_439 | V_440 , V_118 ) ;
for ( V_114 = 0 ; V_114 < 1000 ; V_114 ++ ) {
F_31 ( 1 ) ;
V_439 = F_3 ( V_118 ) ;
if ( V_441 & V_439 )
break;
}
if ( ! ( V_441 & V_439 ) ) {
F_36 (KERN_ERR DRV_NAME L_37 ) ;
V_438 = 1 ;
goto V_442;
}
V_114 = 5 ;
do {
F_2 ( V_439 | V_443 , V_118 ) ;
V_439 = F_3 ( V_118 ) ;
F_31 ( 1 ) ;
} while ( ! ( V_443 & V_439 ) && ( V_114 -- > 0 ) );
if ( ! ( V_443 & V_439 ) ) {
F_36 (KERN_ERR DRV_NAME L_38 ) ;
V_438 = 1 ;
goto V_442;
}
V_114 = 5 ;
do {
F_2 ( V_439 & ~ ( V_443 | V_440 ) , V_118 ) ;
V_439 = F_3 ( V_118 ) ;
F_31 ( 1 ) ;
} while ( ( V_443 & V_439 ) && ( V_114 -- > 0 ) );
if ( V_443 & V_439 ) {
F_36 (KERN_ERR DRV_NAME L_39 ) ;
V_438 = 1 ;
}
V_442:
return V_438 ;
}
static void F_154 ( struct V_17 * V_18 , int V_416 ,
void T_1 * V_12 )
{
void T_1 * V_25 ;
T_2 V_227 ;
V_227 = F_3 ( V_12 + V_444 ) ;
if ( ( V_227 & ( 1 << 0 ) ) == 0 ) {
V_18 -> signal [ V_416 ] . V_420 = 0x7 << 8 ;
V_18 -> signal [ V_416 ] . V_419 = 0x1 << 5 ;
return;
}
V_25 = F_8 ( V_12 , V_416 ) ;
V_227 = F_3 ( V_25 + V_445 ) ;
V_18 -> signal [ V_416 ] . V_420 = V_227 & 0x700 ;
V_18 -> signal [ V_416 ] . V_419 = V_227 & 0xe0 ;
}
static void F_155 ( struct V_17 * V_18 , void T_1 * V_12 )
{
F_2 ( 0x00000060 , V_12 + V_177 ) ;
}
static void F_156 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
T_2 V_147 = V_18 -> V_147 ;
int V_446 =
V_147 & ( V_447 | V_211 ) ;
int V_448 =
V_147 & ( V_447 | V_211 ) ;
T_2 V_449 , V_450 ;
if ( V_446 ) {
V_449 = F_3 ( V_25 + V_445 ) ;
V_449 &= ~ ( 1 << 16 ) ;
V_449 |= ( 1 << 31 ) ;
F_2 ( V_449 , V_25 + V_445 ) ;
F_31 ( 200 ) ;
V_449 = F_3 ( V_25 + V_445 ) ;
V_449 &= ~ ( ( 1 << 16 ) | ( 1 << 31 ) ) ;
F_2 ( V_449 , V_25 + V_445 ) ;
F_31 ( 200 ) ;
}
V_450 = F_3 ( V_25 + V_451 ) ;
V_450 = ( V_450 & 0x1f ) | ( 0x5555601 << 5 ) ;
if ( F_56 ( V_18 ) )
V_450 &= ~ 0x1c ;
if ( V_448 ) {
T_2 V_452 = F_3 ( V_25 + V_453 ) ;
if ( F_22 ( V_18 ) )
V_452 = ( V_452 & ~ V_454 ) | V_455 ;
else
V_452 = ( V_452 & ~ V_456 ) | V_457 ;
F_2 ( V_452 , V_25 + V_453 ) ;
}
F_2 ( V_450 , V_25 + V_451 ) ;
V_449 = F_3 ( V_25 + V_445 ) ;
V_449 &= ~ V_458 ;
V_449 |= V_18 -> signal [ V_3 ] . V_420 ;
V_449 |= V_18 -> signal [ V_3 ] . V_419 ;
V_449 &= ~ ( 1 << 16 ) ;
if ( F_22 ( V_18 ) ) {
V_449 &= ~ 0xC30FF01F ;
V_449 |= 0x0000900F ;
}
F_2 ( V_449 , V_25 + V_445 ) ;
}
static void F_157 ( struct V_17 * V_18 ,
void T_1 * V_12 )
{
return;
}
static void F_158 ( struct V_17 * V_18 , int V_416 ,
void T_1 * V_12 )
{
void T_1 * V_25 ;
T_2 V_227 ;
V_25 = F_8 ( V_12 , V_416 ) ;
V_227 = F_3 ( V_25 + V_445 ) ;
V_18 -> signal [ V_416 ] . V_420 = V_227 & 0x700 ;
V_18 -> signal [ V_416 ] . V_419 = V_227 & 0xe0 ;
}
static void F_159 ( struct V_17 * V_18 ,
void T_1 * V_12 , unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
F_148 ( V_18 , V_12 , V_3 ) ;
F_149 ( 0x028 ) ;
F_2 ( 0x101f , V_25 + V_195 ) ;
F_149 ( 0x004 ) ;
F_149 ( 0x008 ) ;
F_149 ( 0x00c ) ;
F_149 ( 0x010 ) ;
F_149 ( 0x014 ) ;
F_149 ( 0x018 ) ;
F_149 ( 0x01c ) ;
F_149 ( 0x024 ) ;
F_149 ( 0x020 ) ;
F_149 ( 0x02c ) ;
F_2 ( 0x800 , V_25 + V_425 ) ;
}
static void F_160 ( struct V_17 * V_18 ,
void T_1 * V_12 )
{
void T_1 * V_13 = F_6 ( V_12 , 0 ) ;
F_149 ( 0x00c ) ;
F_149 ( 0x010 ) ;
F_149 ( 0x014 ) ;
}
static int F_161 ( struct V_17 * V_18 ,
void T_1 * V_12 , unsigned int V_426 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 -> V_86 ; V_3 ++ )
F_159 ( V_18 , V_12 , V_3 ) ;
F_160 ( V_18 , V_12 ) ;
return 0 ;
}
static void F_162 ( struct V_17 * V_18 ,
void T_1 * V_12 )
{
return;
}
static void F_163 ( struct V_15 * V_16 , void T_1 * V_12 )
{
return;
}
static void F_164 ( struct V_17 * V_18 ,
void T_1 * V_12 , unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
T_2 V_118 ;
V_118 = F_3 ( V_25 + V_451 ) ;
V_118 &= ~ ( 0x3 << 27 ) ;
V_118 |= ( 0x1 << 27 ) ;
V_118 &= ~ ( 0x3 << 29 ) ;
V_118 |= ( 0x1 << 29 ) ;
F_2 ( V_118 , V_25 + V_451 ) ;
V_118 = F_3 ( V_25 + V_453 ) ;
V_118 &= ~ 0x1 ;
V_118 |= ( 0x1 << 16 ) ;
F_2 ( V_118 , V_25 + V_453 ) ;
V_118 = F_3 ( V_25 + V_459 ) ;
V_118 &= ~ 0xf ;
V_118 |= 0x8 ;
V_118 &= ~ ( 0x1 << 14 ) ;
F_2 ( V_118 , V_25 + V_459 ) ;
V_118 = F_3 ( V_25 + V_460 ) ;
V_118 &= ~ 0xf ;
V_118 |= 0x8 ;
V_118 &= ~ ( 0x1 << 14 ) ;
F_2 ( V_118 , V_25 + V_460 ) ;
}
static bool F_165 ( struct V_17 * V_18 )
{
void T_1 * V_461 = F_8 ( V_18 -> V_6 , 0 ) ;
if ( F_3 ( V_461 + V_462 ) )
return true ;
return false ;
}
static void F_166 ( void T_1 * V_25 , int V_463 )
{
T_2 V_464 = F_3 ( V_25 + V_465 ) ;
V_464 = ( V_464 & 0xf7f ) | 0x9b1000 ;
if ( V_463 )
V_464 |= ( 1 << 7 ) ;
F_1 ( V_464 , V_25 + V_465 ) ;
}
static void F_148 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_22 )
{
void T_1 * V_25 = F_8 ( V_12 , V_22 ) ;
F_32 ( V_25 ) ;
F_1 ( V_466 , V_25 + V_108 ) ;
if ( ! F_25 ( V_18 ) ) {
F_166 ( V_25 , 1 ) ;
}
F_1 ( V_466 , V_25 + V_108 ) ;
F_31 ( 25 ) ;
F_1 ( 0 , V_25 + V_108 ) ;
V_18 -> V_248 -> V_467 ( V_18 , V_12 , V_22 ) ;
if ( F_25 ( V_18 ) )
F_167 ( 1 ) ;
}
static void F_95 ( struct V_20 * V_21 , int V_279 )
{
if ( F_168 ( V_21 ) ) {
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_118 = F_3 ( V_25 + V_322 ) ;
int V_37 = V_118 & 0xf ;
if ( V_37 != V_279 ) {
V_118 = ( V_118 & ~ 0xf ) | V_279 ;
F_1 ( V_118 , V_25 + V_322 ) ;
}
}
}
static int F_169 ( struct V_143 * V_144 , unsigned int * V_468 ,
unsigned long V_469 )
{
F_95 ( V_144 -> V_21 , F_170 ( V_144 ) ) ;
return F_171 ( V_144 , V_468 , V_469 ) ;
}
static int F_172 ( struct V_143 * V_144 , unsigned int * V_468 ,
unsigned long V_469 )
{
F_95 ( V_144 -> V_21 , F_170 ( V_144 ) ) ;
return F_173 ( V_144 , V_468 , V_469 ) ;
}
static int F_174 ( struct V_143 * V_144 , unsigned int * V_468 ,
unsigned long V_469 )
{
struct V_20 * V_21 = V_144 -> V_21 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
struct V_26 * V_27 = V_21 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
int V_438 , V_470 = 0 , V_471 = 0 ;
T_2 V_472 ;
bool V_473 ;
F_148 ( V_18 , V_12 , V_21 -> V_22 ) ;
V_27 -> V_103 &= ~ V_104 ;
V_27 -> V_103 &=
~ ( V_188 | V_106 | V_189 ) ;
do {
const unsigned long * V_474 =
F_175 ( & V_144 -> V_475 ) ;
V_438 = F_176 ( V_144 , V_474 , V_469 + V_471 ,
& V_473 , NULL ) ;
V_438 = V_473 ? - V_476 : V_438 ;
if ( V_438 )
return V_438 ;
F_118 ( V_144 , V_137 , & V_472 ) ;
if ( ! F_25 ( V_18 ) && ++ V_470 >= 5 && V_472 == 0x121 ) {
F_166 ( F_11 ( V_21 ) , 0 ) ;
if ( F_177 ( V_477 + V_478 , V_469 ) )
V_471 = V_478 ;
}
} while ( V_472 != 0x0 && V_472 != 0x113 && V_472 != 0x123 );
F_13 ( V_21 ) ;
F_29 ( V_21 , 0 , 0 ) ;
return V_438 ;
}
static void F_113 ( struct V_20 * V_21 )
{
F_28 ( V_21 ) ;
F_19 ( V_21 , 0 ) ;
}
static void F_178 ( struct V_20 * V_21 )
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
static void F_179 ( struct V_479 * V_3 , void T_1 * V_25 )
{
void T_1 * V_367 , * V_480 = V_25 + V_481 ;
V_3 -> V_482 = V_480 + ( sizeof( T_2 ) * V_483 ) ;
V_3 -> V_484 =
V_3 -> V_485 = V_480 + ( sizeof( T_2 ) * V_486 ) ;
V_3 -> V_487 = V_480 + ( sizeof( T_2 ) * V_291 ) ;
V_3 -> V_488 = V_480 + ( sizeof( T_2 ) * V_299 ) ;
V_3 -> V_489 = V_480 + ( sizeof( T_2 ) * V_302 ) ;
V_3 -> V_490 = V_480 + ( sizeof( T_2 ) * V_305 ) ;
V_3 -> V_491 = V_480 + ( sizeof( T_2 ) * V_307 ) ;
V_3 -> V_313 =
V_3 -> V_492 = V_480 + ( sizeof( T_2 ) * V_493 ) ;
V_3 -> V_261 = V_3 -> V_494 = V_480 + V_495 ;
V_367 = V_25 + F_41 ( V_139 ) ;
F_1 ( F_3 ( V_367 ) , V_367 ) ;
F_1 ( 0 , V_25 + V_75 ) ;
F_1 ( ~ V_362 , V_25 + V_496 ) ;
F_180 ( L_40 ,
F_3 ( V_25 + V_195 ) ,
F_3 ( V_25 + V_75 ) ,
F_3 ( V_25 + V_496 ) ) ;
}
static unsigned int F_181 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
T_2 V_118 ;
if ( F_56 ( V_18 ) || ! F_182 ( V_18 ) )
return 0 ;
V_118 = F_3 ( V_12 + V_427 ) ;
if ( ( V_118 & V_497 ) == 0 )
return 0 ;
return 1 ;
}
static int F_183 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
T_2 V_118 ;
if ( ! F_181 ( V_16 ) ) {
V_118 = F_3 ( V_12 + V_498 ) ;
if ( V_118 & V_499 )
return 0 ;
}
return 1 ;
}
static void F_184 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
if ( F_181 ( V_16 ) ) {
T_2 V_118 = F_3 ( V_12 + V_498 ) ;
F_1 ( V_118 & ~ V_500 , V_12 + V_498 ) ;
}
}
static int F_185 ( struct V_15 * V_16 , unsigned int V_501 )
{
struct V_125 * V_126 = F_132 ( V_16 -> V_162 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
T_2 V_147 = V_18 -> V_147 ;
switch ( V_501 ) {
case V_502 :
V_18 -> V_248 = & V_503 ;
V_147 |= V_504 ;
switch ( V_126 -> V_413 ) {
case 0x1 :
V_147 |= V_422 ;
break;
case 0x3 :
V_147 |= V_505 ;
break;
default:
F_186 ( & V_126 -> V_162 ,
L_41 ) ;
V_147 |= V_505 ;
break;
}
break;
case V_506 :
case V_507 :
V_18 -> V_248 = & V_503 ;
V_147 |= V_504 ;
switch ( V_126 -> V_413 ) {
case 0x0 :
V_147 |= V_422 ;
break;
case 0x3 :
V_147 |= V_505 ;
break;
default:
F_186 ( & V_126 -> V_162 ,
L_42 ) ;
V_147 |= V_505 ;
break;
}
break;
case V_508 :
case V_509 :
V_18 -> V_248 = & V_510 ;
V_147 |= V_511 ;
switch ( V_126 -> V_413 ) {
case 0x7 :
F_184 ( V_16 ) ;
V_147 |= V_447 ;
break;
case 0x9 :
V_147 |= V_211 ;
break;
default:
F_186 ( & V_126 -> V_162 ,
L_42 ) ;
V_147 |= V_447 ;
break;
}
break;
case V_512 :
V_147 |= V_513 | V_193 ;
if ( V_126 -> V_514 == V_515 &&
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
case V_516 :
V_18 -> V_248 = & V_510 ;
V_147 |= V_517 ;
if ( V_501 == V_516 && F_183 ( V_16 ) )
V_147 |= V_193 ;
switch ( V_126 -> V_413 ) {
case 0x2 :
V_147 |= V_211 ;
break;
default:
F_186 ( & V_126 -> V_162 ,
L_51 ) ;
V_147 |= V_211 ;
break;
}
break;
case V_518 :
if ( F_165 ( V_18 ) )
V_18 -> V_248 = & V_519 ;
else
V_18 -> V_248 = & V_520 ;
V_147 |= V_521 | V_517 |
V_211 ;
break;
default:
F_131 ( V_16 -> V_162 , L_52 , V_501 ) ;
return 1 ;
}
V_18 -> V_147 = V_147 ;
if ( V_147 & V_513 ) {
V_18 -> V_403 = V_522 ;
V_18 -> V_432 = V_523 ;
V_18 -> V_524 = V_525 ;
} else {
V_18 -> V_403 = V_526 ;
V_18 -> V_432 = V_527 ;
V_18 -> V_524 = V_528 ;
}
return 0 ;
}
static int F_187 ( struct V_15 * V_16 )
{
int V_438 = 0 , V_426 , V_3 , V_7 ;
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
V_438 = F_185 ( V_16 , V_18 -> V_501 ) ;
if ( V_438 )
goto V_442;
if ( F_56 ( V_18 ) ) {
V_18 -> V_410 = V_12 + V_529 ;
V_18 -> V_62 = V_12 + V_530 ;
} else {
V_18 -> V_410 = V_12 + V_531 ;
V_18 -> V_62 = V_12 + V_532 ;
}
V_18 -> V_67 = F_3 ( V_18 -> V_62 ) ;
F_18 ( V_16 , ~ 0 , 0 ) ;
V_426 = F_12 ( V_16 -> V_184 [ 0 ] -> V_83 ) ;
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ )
if ( V_18 -> V_248 -> V_533 )
V_18 -> V_248 -> V_533 ( V_18 , V_3 , V_12 ) ;
V_438 = V_18 -> V_248 -> V_534 ( V_18 , V_12 , V_426 ) ;
if ( V_438 )
goto V_442;
V_18 -> V_248 -> V_535 ( V_18 , V_12 ) ;
V_18 -> V_248 -> V_536 ( V_16 , V_12 ) ;
V_18 -> V_248 -> V_537 ( V_18 , V_12 ) ;
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ ) {
struct V_20 * V_21 = V_16 -> V_184 [ V_3 ] ;
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
F_179 ( & V_21 -> V_260 , V_25 ) ;
}
for ( V_7 = 0 ; V_7 < V_426 ; V_7 ++ ) {
void T_1 * V_13 = F_6 ( V_12 , V_7 ) ;
F_180 ( L_53
L_54 , V_7 ,
F_3 ( V_13 + V_538 ) ,
F_3 ( V_13 + V_78 ) ) ;
F_1 ( 0 , V_13 + V_78 ) ;
}
if ( ! F_56 ( V_18 ) ) {
F_1 ( 0 , V_12 + V_18 -> V_403 ) ;
F_1 ( V_18 -> V_524 , V_12 + V_18 -> V_432 ) ;
}
F_18 ( V_16 , 0 , V_411 ) ;
F_23 ( V_16 , V_539 ,
V_540 ) ;
V_442:
return V_438 ;
}
static int F_188 ( struct V_17 * V_18 , struct V_205 * V_162 )
{
V_18 -> V_198 = F_189 ( L_55 , V_162 , V_208 ,
V_208 , 0 ) ;
if ( ! V_18 -> V_198 )
return - V_207 ;
V_18 -> V_200 = F_189 ( L_56 , V_162 , V_210 ,
V_210 , 0 ) ;
if ( ! V_18 -> V_200 )
return - V_207 ;
V_18 -> V_203 = F_189 ( L_57 , V_162 , V_541 ,
V_541 , 0 ) ;
if ( ! V_18 -> V_203 )
return - V_207 ;
return 0 ;
}
static void F_190 ( struct V_17 * V_18 ,
const struct V_542 * V_543 )
{
int V_114 ;
for ( V_114 = 0 ; V_114 < 4 ; V_114 ++ ) {
F_2 ( 0 , V_18 -> V_6 + F_191 ( V_114 ) ) ;
F_2 ( 0 , V_18 -> V_6 + F_192 ( V_114 ) ) ;
}
for ( V_114 = 0 ; V_114 < V_543 -> V_544 ; V_114 ++ ) {
const struct V_545 * V_546 = V_543 -> V_546 + V_114 ;
F_2 ( ( ( V_546 -> V_547 - 1 ) & 0xffff0000 ) |
( V_546 -> V_548 << 8 ) |
( V_543 -> V_549 << 4 ) | 1 ,
V_18 -> V_6 + F_191 ( V_114 ) ) ;
F_2 ( V_546 -> V_6 , V_18 -> V_6 + F_192 ( V_114 ) ) ;
}
}
static int F_193 ( struct V_550 * V_126 )
{
const struct V_551 * V_552 ;
const struct V_542 * V_543 ;
const struct F_111 * V_553 [] =
{ & V_554 [ V_518 ] , NULL } ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_555 * V_556 ;
int V_86 = 0 , V_405 = 0 ;
int V_438 ;
int V_3 ;
F_194 ( & V_126 -> V_162 , V_557 ) ;
if ( F_48 ( V_126 -> V_558 != 2 ) ) {
F_131 ( & V_126 -> V_162 , L_58 ) ;
return - V_146 ;
}
V_556 = F_195 ( V_126 , V_559 , 0 ) ;
if ( V_556 == NULL )
return - V_146 ;
if ( V_126 -> V_162 . V_560 ) {
F_196 ( V_126 -> V_162 . V_560 , L_59 , & V_86 ) ;
V_405 = F_197 ( V_126 -> V_162 . V_560 , 0 ) ;
} else {
V_552 = F_198 ( & V_126 -> V_162 ) ;
V_86 = V_552 -> V_86 ;
V_405 = F_199 ( V_126 , 0 ) ;
}
V_16 = F_200 ( & V_126 -> V_162 , V_553 , V_86 ) ;
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
V_18 -> V_501 = V_518 ;
V_16 -> V_565 = NULL ;
V_18 -> V_6 = F_201 ( & V_126 -> V_162 , V_556 -> V_121 ,
F_202 ( V_556 ) ) ;
V_18 -> V_6 -= V_8 ;
V_18 -> V_562 = F_203 ( & V_126 -> V_162 , NULL ) ;
if ( F_204 ( V_18 -> V_562 ) )
F_205 ( & V_126 -> V_162 , L_60 ) ;
else
F_206 ( V_18 -> V_562 ) ;
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
char V_566 [ 16 ] ;
sprintf ( V_566 , L_61 , V_3 ) ;
V_18 -> V_561 [ V_3 ] = F_203 ( & V_126 -> V_162 , V_566 ) ;
if ( ! F_204 ( V_18 -> V_561 [ V_3 ] ) )
F_206 ( V_18 -> V_561 [ V_3 ] ) ;
sprintf ( V_566 , L_62 , V_3 ) ;
V_18 -> V_563 [ V_3 ] = F_207 ( & V_126 -> V_162 ,
V_566 ) ;
if ( F_204 ( V_18 -> V_563 [ V_3 ] ) ) {
V_438 = F_208 ( V_18 -> V_563 [ V_3 ] ) ;
V_18 -> V_563 [ V_3 ] = NULL ;
if ( V_438 != - V_567 )
F_186 ( & V_126 -> V_162 , L_63 , V_438 ) ;
V_18 -> V_86 = V_3 ;
goto V_120;
} else
F_209 ( V_18 -> V_563 [ V_3 ] ) ;
}
V_18 -> V_86 = V_86 ;
V_543 = F_210 () ;
if ( V_543 )
F_190 ( V_18 , V_543 ) ;
V_438 = F_188 ( V_18 , & V_126 -> V_162 ) ;
if ( V_438 )
goto V_120;
if ( V_126 -> V_162 . V_560 &&
F_211 ( V_126 -> V_162 . V_560 ,
L_64 ) )
V_18 -> V_147 |= V_148 ;
V_438 = F_187 ( V_16 ) ;
if ( V_438 )
goto V_120;
F_212 ( & V_126 -> V_162 , L_65 ,
( unsigned ) V_201 , V_16 -> V_86 ) ;
V_438 = F_213 ( V_16 , V_405 , F_134 , V_568 , & V_569 ) ;
if ( ! V_438 )
return 0 ;
V_120:
if ( ! F_204 ( V_18 -> V_562 ) ) {
F_214 ( V_18 -> V_562 ) ;
F_215 ( V_18 -> V_562 ) ;
}
for ( V_3 = 0 ; V_3 < V_18 -> V_86 ; V_3 ++ ) {
if ( ! F_204 ( V_18 -> V_561 [ V_3 ] ) ) {
F_214 ( V_18 -> V_561 [ V_3 ] ) ;
F_215 ( V_18 -> V_561 [ V_3 ] ) ;
}
F_216 ( V_18 -> V_563 [ V_3 ] ) ;
}
return V_438 ;
}
static int F_217 ( struct V_550 * V_126 )
{
struct V_15 * V_16 = F_218 ( V_126 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
int V_3 ;
F_219 ( V_16 ) ;
if ( ! F_204 ( V_18 -> V_562 ) ) {
F_214 ( V_18 -> V_562 ) ;
F_215 ( V_18 -> V_562 ) ;
}
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ ) {
if ( ! F_204 ( V_18 -> V_561 [ V_3 ] ) ) {
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
F_190 ( V_18 , V_543 ) ;
V_571 = F_187 ( V_16 ) ;
if ( V_571 ) {
F_36 (KERN_ERR DRV_NAME L_66 ) ;
return V_571 ;
}
F_223 ( V_16 ) ;
}
return 0 ;
}
static int F_224 ( struct V_125 * V_126 )
{
int V_438 ;
if ( ! F_225 ( & V_126 -> V_162 , F_226 ( 64 ) ) ) {
V_438 = F_227 ( & V_126 -> V_162 , F_226 ( 64 ) ) ;
if ( V_438 ) {
V_438 = F_227 ( & V_126 -> V_162 , F_226 ( 32 ) ) ;
if ( V_438 ) {
F_131 ( & V_126 -> V_162 ,
L_67 ) ;
return V_438 ;
}
}
} else {
V_438 = F_225 ( & V_126 -> V_162 , F_226 ( 32 ) ) ;
if ( V_438 ) {
F_131 ( & V_126 -> V_162 , L_68 ) ;
return V_438 ;
}
V_438 = F_227 ( & V_126 -> V_162 , F_226 ( 32 ) ) ;
if ( V_438 ) {
F_131 ( & V_126 -> V_162 ,
L_69 ) ;
return V_438 ;
}
}
return V_438 ;
}
static void F_228 ( struct V_15 * V_16 )
{
struct V_125 * V_126 = F_132 ( V_16 -> V_162 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
T_3 V_572 ;
const char * V_573 , * V_574 ;
F_229 ( V_126 , V_575 , & V_572 ) ;
if ( V_572 == 0 )
V_573 = L_70 ;
else if ( V_572 == 0x01 )
V_573 = L_71 ;
else
V_573 = L_72 ;
if ( F_25 ( V_18 ) )
V_574 = L_73 ;
else if ( F_55 ( V_18 ) )
V_574 = L_74 ;
else if ( F_22 ( V_18 ) )
V_574 = L_75 ;
else
V_574 = L_72 ;
F_212 ( & V_126 -> V_162 , L_76 ,
V_574 , ( unsigned ) V_201 , V_16 -> V_86 ,
V_573 , ( V_408 & V_18 -> V_147 ) ? L_77 : L_78 ) ;
}
static int F_230 ( struct V_125 * V_126 ,
const struct V_576 * V_577 )
{
unsigned int V_501 = ( unsigned int ) V_577 -> V_578 ;
const struct F_111 * V_553 [] = { & V_554 [ V_501 ] , NULL } ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_86 , V_3 , V_438 ;
F_194 ( & V_126 -> V_162 , V_557 ) ;
V_86 = F_12 ( V_553 [ 0 ] -> V_83 ) * V_87 ;
V_16 = F_200 ( & V_126 -> V_162 , V_553 , V_86 ) ;
V_18 = F_60 ( & V_126 -> V_162 , sizeof( * V_18 ) , V_206 ) ;
if ( ! V_16 || ! V_18 )
return - V_207 ;
V_16 -> V_19 = V_18 ;
V_18 -> V_86 = V_86 ;
V_18 -> V_501 = V_501 ;
V_438 = F_231 ( V_126 ) ;
if ( V_438 )
return V_438 ;
V_438 = F_232 ( V_126 , 1 << V_579 , V_338 ) ;
if ( V_438 == - V_580 )
F_233 ( V_126 ) ;
if ( V_438 )
return V_438 ;
V_16 -> V_565 = F_234 ( V_126 ) ;
V_18 -> V_6 = V_16 -> V_565 [ V_579 ] ;
V_438 = F_224 ( V_126 ) ;
if ( V_438 )
return V_438 ;
V_438 = F_188 ( V_18 , & V_126 -> V_162 ) ;
if ( V_438 )
return V_438 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ ) {
struct V_20 * V_21 = V_16 -> V_184 [ V_3 ] ;
void T_1 * V_25 = F_8 ( V_18 -> V_6 , V_3 ) ;
unsigned int V_219 = V_25 - V_18 -> V_6 ;
F_235 ( V_21 , V_579 , - 1 , L_79 ) ;
F_235 ( V_21 , V_579 , V_219 , L_80 ) ;
}
V_438 = F_187 ( V_16 ) ;
if ( V_438 )
return V_438 ;
if ( V_581 && F_236 ( V_126 ) == 0 )
V_18 -> V_147 |= V_408 ;
F_37 ( V_126 , 0x68 ) ;
F_228 ( V_16 ) ;
F_237 ( V_126 ) ;
F_238 ( V_126 ) ;
return F_213 ( V_16 , V_126 -> V_405 , F_134 , V_568 ,
F_25 ( V_18 ) ? & V_582 : & V_569 ) ;
}
static int F_239 ( struct V_125 * V_126 )
{
struct V_15 * V_16 = F_240 ( V_126 ) ;
int V_438 ;
V_438 = F_241 ( V_126 ) ;
if ( V_438 )
return V_438 ;
V_438 = F_187 ( V_16 ) ;
if ( V_438 )
return V_438 ;
F_223 ( V_16 ) ;
return 0 ;
}
static int T_9 F_242 ( void )
{
int V_438 = - V_583 ;
#ifdef F_243
V_438 = F_244 ( & V_584 ) ;
if ( V_438 < 0 )
return V_438 ;
#endif
V_438 = F_245 ( & V_585 ) ;
#ifdef F_243
if ( V_438 < 0 )
F_246 ( & V_584 ) ;
#endif
return V_438 ;
}
static void T_10 F_247 ( void )
{
#ifdef F_243
F_246 ( & V_584 ) ;
#endif
F_248 ( & V_585 ) ;
}
