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
V_39 = ( long ) V_2 & 0xffff ;
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
if ( ( V_145 & 0xf0 ) == 0x10 )
F_1 ( 0x7 , V_149 ) ;
else
F_1 ( 0x227 , V_149 ) ;
}
}
F_1 ( V_145 , V_2 ) ;
return 0 ;
} else
return - V_146 ;
}
static void F_44 ( struct V_151 * V_152 )
{
if ( V_152 -> V_83 & V_153 ) {
if ( F_45 ( V_152 -> V_144 -> V_21 ) ) {
V_152 -> V_83 &= ~ V_153 ;
F_46 ( V_152 ,
L_12 ) ;
}
}
}
static int F_47 ( struct V_154 * V_155 )
{
struct V_143 * V_144 = V_155 -> V_156 -> V_144 ;
struct V_20 * V_21 = V_144 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
if ( V_27 -> V_103 & V_157 )
return V_158 ;
if ( F_48 ( V_21 -> V_159 ) ) {
if ( V_144 == V_21 -> V_159 ) {
if ( V_21 -> V_160 )
return V_158 ;
V_155 -> V_83 |= V_161 ;
return 0 ;
} else
return V_158 ;
}
if ( V_21 -> V_160 == 0 )
return 0 ;
if ( ( V_27 -> V_103 & V_104 ) &&
( V_27 -> V_103 & V_106 ) ) {
if ( F_49 ( V_155 -> V_162 . V_100 ) )
return 0 ;
else {
V_21 -> V_159 = V_144 ;
return V_158 ;
}
}
return V_158 ;
}
static void F_50 ( struct V_20 * V_21 , int V_101 , int V_163 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
void T_1 * V_25 ;
T_2 V_29 , * V_164 = & V_27 -> V_28 . V_29 ;
T_2 V_31 , * V_165 = & V_27 -> V_28 . V_31 ;
T_2 V_33 , * V_166 = & V_27 -> V_28 . V_33 ;
V_31 = * V_165 & ~ V_167 ;
V_33 = * V_166 | V_168 ;
if ( V_163 ) {
V_29 = * V_164 | V_169 ;
V_31 = * V_165 | V_167 ;
if ( V_101 )
V_33 &= ~ V_168 ;
else
V_29 |= V_170 ;
} else {
V_29 = * V_164 & ~ ( V_169 | V_170 ) ;
}
V_25 = F_11 ( V_21 ) ;
F_14 ( V_25 + V_30 , V_164 , V_29 ) ;
F_14 ( V_25 + V_32 , V_165 , V_31 ) ;
F_14 ( V_25 + V_34 , V_166 , V_33 ) ;
}
static void F_51 ( struct V_20 * V_21 , int V_101 )
{
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
T_2 V_37 , V_38 ;
V_37 = F_3 ( V_18 -> V_6 + V_171 ) ;
if ( V_101 )
V_38 = V_37 | ( 1 << 22 ) ;
else
V_38 = V_37 & ~ ( 1 << 22 ) ;
if ( V_38 != V_37 )
F_2 ( V_38 , V_18 -> V_6 + V_171 ) ;
}
static void F_52 ( struct V_20 * V_21 , int V_172 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
T_2 V_38 , * V_37 = & V_27 -> V_28 . V_35 ;
if ( V_172 )
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
T_2 V_173 ;
if ( V_18 -> V_147 & V_174 )
return;
V_18 -> V_147 |= V_174 ;
V_13 = F_7 ( F_10 ( V_16 ) , V_21 -> V_22 ) ;
V_173 = F_3 ( V_13 + V_175 ) ;
F_2 ( V_173 | V_176 , V_13 + V_175 ) ;
}
static void F_54 ( struct V_20 * V_21 )
{
struct V_15 * V_16 = V_21 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_13 ;
T_2 V_173 ;
unsigned int V_3 ;
if ( ! ( V_18 -> V_147 & V_174 ) )
return;
for ( V_3 = 0 ; V_3 < V_18 -> V_86 ; V_3 ++ ) {
struct V_20 * V_177 = V_16 -> V_178 [ V_3 ] ;
struct V_26 * V_27 = V_177 -> V_19 ;
if ( V_27 -> V_103 & V_106 )
return;
}
V_18 -> V_147 &= ~ V_174 ;
V_13 = F_7 ( F_10 ( V_16 ) , V_21 -> V_22 ) ;
V_173 = F_3 ( V_13 + V_175 ) ;
F_2 ( V_173 & ~ V_176 , V_13 + V_175 ) ;
}
static void F_29 ( struct V_20 * V_21 , int V_101 , int V_179 )
{
T_2 V_180 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
V_180 = V_181 ;
V_27 -> V_103 &=
~ ( V_182 | V_106 | V_183 ) ;
if ( F_25 ( V_18 ) )
V_180 |= ( 1 << 8 ) ;
else if ( F_55 ( V_18 ) ) {
V_180 |= V_184 | V_185 ;
F_51 ( V_21 , V_101 ) ;
} else if ( F_22 ( V_18 ) ) {
int V_163 = F_45 ( V_21 ) ;
V_163 &= V_101 ;
F_50 ( V_21 , V_101 , V_163 ) ;
if ( V_163 ) {
V_27 -> V_103 |= V_182 ;
V_180 |= V_186 ;
}
V_180 |= ( 1 << 23 ) ;
if ( V_179 ) {
V_180 |= ( 1 << 22 ) ;
if ( ! F_56 ( V_18 ) )
V_180 |= ( 1 << 18 ) ;
}
if ( V_18 -> V_147 & V_187 )
V_180 |= ( 1 << 17 ) ;
F_52 ( V_21 , ! V_179 ) ;
if ( F_56 ( V_18 ) ) {
if ( V_101 )
F_53 ( V_21 ) ;
else
F_54 ( V_21 ) ;
}
}
if ( V_101 ) {
V_180 |= V_188 ;
V_27 -> V_103 |= V_106 ;
}
F_1 ( V_180 , V_25 + V_189 ) ;
}
static void F_57 ( struct V_20 * V_21 )
{
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
struct V_26 * V_27 = V_21 -> V_19 ;
int V_190 ;
if ( V_27 -> V_191 ) {
F_58 ( V_18 -> V_192 , V_27 -> V_191 , V_27 -> V_44 ) ;
V_27 -> V_191 = NULL ;
}
if ( V_27 -> V_193 ) {
F_58 ( V_18 -> V_194 , V_27 -> V_193 , V_27 -> V_51 ) ;
V_27 -> V_193 = NULL ;
}
for ( V_190 = 0 ; V_190 < V_195 ; ++ V_190 ) {
if ( V_27 -> V_196 [ V_190 ] ) {
if ( V_190 == 0 || ! F_25 ( V_18 ) )
F_58 ( V_18 -> V_197 ,
V_27 -> V_196 [ V_190 ] ,
V_27 -> V_198 [ V_190 ] ) ;
V_27 -> V_196 [ V_190 ] = NULL ;
}
}
}
static int F_59 ( struct V_20 * V_21 )
{
struct V_199 * V_156 = V_21 -> V_16 -> V_156 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
struct V_26 * V_27 ;
unsigned long V_83 ;
int V_190 ;
V_27 = F_60 ( V_156 , sizeof( * V_27 ) , V_200 ) ;
if ( ! V_27 )
return - V_201 ;
V_21 -> V_19 = V_27 ;
V_27 -> V_191 = F_61 ( V_18 -> V_192 , V_200 , & V_27 -> V_44 ) ;
if ( ! V_27 -> V_191 )
return - V_201 ;
memset ( V_27 -> V_191 , 0 , V_202 ) ;
V_27 -> V_193 = F_61 ( V_18 -> V_194 , V_200 , & V_27 -> V_51 ) ;
if ( ! V_27 -> V_193 )
goto V_203;
memset ( V_27 -> V_193 , 0 , V_204 ) ;
if ( V_18 -> V_147 & V_205 )
V_21 -> V_83 |= V_206 ;
for ( V_190 = 0 ; V_190 < V_195 ; ++ V_190 ) {
if ( V_190 == 0 || ! F_25 ( V_18 ) ) {
V_27 -> V_196 [ V_190 ] = F_61 ( V_18 -> V_197 ,
V_200 , & V_27 -> V_198 [ V_190 ] ) ;
if ( ! V_27 -> V_196 [ V_190 ] )
goto V_203;
} else {
V_27 -> V_196 [ V_190 ] = V_27 -> V_196 [ 0 ] ;
V_27 -> V_198 [ V_190 ] = V_27 -> V_198 [ 0 ] ;
}
}
F_24 ( V_21 -> V_92 , V_83 ) ;
F_13 ( V_21 ) ;
F_29 ( V_21 , 0 , 0 ) ;
F_26 ( V_21 -> V_92 , V_83 ) ;
return 0 ;
V_203:
F_57 ( V_21 ) ;
return - V_201 ;
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
static void F_63 ( struct V_154 * V_155 )
{
struct V_26 * V_27 = V_155 -> V_21 -> V_19 ;
struct V_207 * V_208 ;
struct V_209 * V_209 , * V_210 = NULL ;
unsigned int V_211 ;
V_209 = V_27 -> V_196 [ V_155 -> V_190 ] ;
F_64 (qc->sg, sg, qc->n_elem, si) {
T_4 V_2 = F_65 ( V_208 ) ;
T_2 V_212 = F_66 ( V_208 ) ;
while ( V_212 ) {
T_2 V_213 = V_2 & 0xffff ;
T_2 V_214 = V_212 ;
if ( V_213 + V_214 > 0x10000 )
V_214 = 0x10000 - V_213 ;
V_209 -> V_2 = F_67 ( V_2 & 0xffffffff ) ;
V_209 -> V_215 = F_67 ( ( V_2 >> 16 ) >> 16 ) ;
V_209 -> V_216 = F_67 ( V_214 & 0xffff ) ;
V_209 -> V_217 = 0 ;
V_212 -= V_214 ;
V_2 += V_214 ;
V_210 = V_209 ;
V_209 ++ ;
}
}
if ( F_68 ( V_210 ) )
V_210 -> V_216 |= F_67 ( V_218 ) ;
F_69 () ;
}
static void F_70 ( T_5 * V_219 , T_3 V_1 , T_3 V_2 , unsigned V_220 )
{
T_6 V_221 = V_1 | ( V_2 << V_222 ) | V_223 |
( V_220 ? V_224 : 0 ) ;
* V_219 = F_71 ( V_221 ) ;
}
static void F_72 ( struct V_20 * V_21 )
{
F_21 ( V_21 , F_11 ( V_21 ) , V_72 ) ;
}
static int F_73 ( struct V_154 * V_155 )
{
struct V_225 * V_226 = V_155 -> V_227 ;
if ( V_226 ) {
switch ( V_226 -> V_228 [ 0 ] ) {
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
case V_237 :
return 0 ;
}
}
return - V_238 ;
}
static void F_74 ( struct V_154 * V_155 )
{
struct V_20 * V_21 = V_155 -> V_21 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
F_63 ( V_155 ) ;
F_2 ( 0 , V_25 + V_239 ) ;
F_2 ( ( V_27 -> V_198 [ V_155 -> V_190 ] >> 16 ) >> 16 ,
V_25 + V_240 ) ;
F_1 ( V_27 -> V_198 [ V_155 -> V_190 ] ,
V_25 + V_241 ) ;
V_21 -> V_242 -> V_243 ( V_21 , & V_155 -> V_162 ) ;
}
static void F_75 ( struct V_154 * V_155 )
{
struct V_20 * V_21 = V_155 -> V_21 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
unsigned int V_244 = ( V_155 -> V_162 . V_83 & V_245 ) ;
T_2 V_246 = ( V_244 ? 0 : V_247 ) | V_248 ;
F_1 ( V_246 , V_25 + V_239 ) ;
}
static void F_76 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_246 ;
V_246 = F_3 ( V_25 + V_239 ) ;
if ( V_246 & V_248 ) {
V_246 &= ~ V_248 ;
F_1 ( V_246 , V_25 + V_239 ) ;
F_77 ( V_21 ) ;
}
}
static void F_78 ( struct V_154 * V_155 )
{
F_76 ( V_155 -> V_21 ) ;
}
static T_3 F_79 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_118 , V_249 ;
V_118 = F_3 ( V_25 + V_250 ) ;
if ( V_118 & V_251 )
V_249 = V_251 ;
else if ( V_118 & V_252 )
V_249 = ( V_118 & V_252 ) | V_253 ;
else {
F_76 ( V_21 ) ;
if ( F_80 ( V_21 -> V_254 . V_255 ) & V_256 )
V_249 = 0 ;
else
V_249 = V_253 ;
}
return V_249 ;
}
static void F_81 ( struct V_154 * V_155 )
{
struct V_257 * V_162 = & V_155 -> V_162 ;
if ( ( V_162 -> V_83 & V_245 ) && F_82 ( V_162 ) ) {
if ( V_155 -> V_156 -> V_258 > 7 ) {
switch ( V_162 -> V_259 ) {
case V_260 :
V_162 -> V_259 = V_261 ;
break;
case V_262 :
V_162 -> V_83 &= ~ V_263 ;
case V_264 :
V_162 -> V_259 = V_265 ;
break;
}
}
}
}
static void F_83 ( struct V_154 * V_155 )
{
struct V_20 * V_21 = V_155 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
T_5 * V_266 ;
struct V_257 * V_162 = & V_155 -> V_162 ;
T_6 V_83 = 0 ;
unsigned V_267 ;
switch ( V_162 -> V_100 ) {
case V_268 :
if ( V_162 -> V_259 == V_269 )
return;
case V_102 :
break;
case V_270 :
F_81 ( V_155 ) ;
return;
default:
return;
}
if ( ! ( V_162 -> V_83 & V_245 ) )
V_83 |= V_271 ;
F_16 ( V_195 <= V_155 -> V_190 ) ;
V_83 |= V_155 -> V_190 << V_272 ;
V_83 |= ( V_155 -> V_156 -> V_144 -> V_273 & 0xf ) << V_274 ;
V_267 = V_27 -> V_41 ;
V_27 -> V_191 [ V_267 ] . V_275 =
F_67 ( V_27 -> V_198 [ V_155 -> V_190 ] & 0xffffffff ) ;
V_27 -> V_191 [ V_267 ] . V_276 =
F_67 ( ( V_27 -> V_198 [ V_155 -> V_190 ] >> 16 ) >> 16 ) ;
V_27 -> V_191 [ V_267 ] . V_277 = F_71 ( V_83 ) ;
V_266 = & V_27 -> V_191 [ V_267 ] . V_278 [ 0 ] ;
switch ( V_162 -> V_259 ) {
case V_279 :
case V_280 :
case V_281 :
case V_282 :
case V_283 :
F_70 ( V_266 ++ , V_162 -> V_284 , V_285 , 0 ) ;
break;
case V_286 :
case V_287 :
F_70 ( V_266 ++ , V_162 -> V_288 , V_289 , 0 ) ;
F_70 ( V_266 ++ , V_162 -> V_290 , V_289 , 0 ) ;
break;
default:
F_84 ( V_162 -> V_259 ) ;
break;
}
F_70 ( V_266 ++ , V_162 -> V_291 , V_285 , 0 ) ;
F_70 ( V_266 ++ , V_162 -> V_292 , V_293 , 0 ) ;
F_70 ( V_266 ++ , V_162 -> V_294 , V_293 , 0 ) ;
F_70 ( V_266 ++ , V_162 -> V_295 , V_296 , 0 ) ;
F_70 ( V_266 ++ , V_162 -> V_297 , V_296 , 0 ) ;
F_70 ( V_266 ++ , V_162 -> V_298 , V_299 , 0 ) ;
F_70 ( V_266 ++ , V_162 -> V_300 , V_299 , 0 ) ;
F_70 ( V_266 ++ , V_162 -> V_199 , V_301 , 0 ) ;
F_70 ( V_266 ++ , V_162 -> V_259 , V_302 , 1 ) ;
if ( ! ( V_155 -> V_83 & V_303 ) )
return;
F_63 ( V_155 ) ;
}
static void F_85 ( struct V_154 * V_155 )
{
struct V_20 * V_21 = V_155 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_304 * V_191 ;
struct V_257 * V_162 = & V_155 -> V_162 ;
unsigned V_267 ;
T_2 V_83 = 0 ;
if ( ( V_162 -> V_100 != V_268 ) &&
( V_162 -> V_100 != V_102 ) )
return;
if ( V_162 -> V_259 == V_269 )
return;
if ( ! ( V_162 -> V_83 & V_245 ) )
V_83 |= V_271 ;
F_16 ( V_195 <= V_155 -> V_190 ) ;
V_83 |= V_155 -> V_190 << V_272 ;
V_83 |= V_155 -> V_190 << V_305 ;
V_83 |= ( V_155 -> V_156 -> V_144 -> V_273 & 0xf ) << V_274 ;
V_267 = V_27 -> V_41 ;
V_191 = (struct V_304 * ) & V_27 -> V_191 [ V_267 ] ;
V_191 -> V_2 = F_67 ( V_27 -> V_198 [ V_155 -> V_190 ] & 0xffffffff ) ;
V_191 -> V_215 = F_67 ( ( V_27 -> V_198 [ V_155 -> V_190 ] >> 16 ) >> 16 ) ;
V_191 -> V_83 = F_67 ( V_83 ) ;
V_191 -> V_278 [ 0 ] = F_67 (
( V_162 -> V_259 << 16 ) |
( V_162 -> V_290 << 24 )
) ;
V_191 -> V_278 [ 1 ] = F_67 (
( V_162 -> V_294 << 0 ) |
( V_162 -> V_297 << 8 ) |
( V_162 -> V_300 << 16 ) |
( V_162 -> V_199 << 24 )
) ;
V_191 -> V_278 [ 2 ] = F_67 (
( V_162 -> V_292 << 0 ) |
( V_162 -> V_295 << 8 ) |
( V_162 -> V_298 << 16 ) |
( V_162 -> V_288 << 24 )
) ;
V_191 -> V_278 [ 3 ] = F_67 (
( V_162 -> V_291 << 0 ) |
( V_162 -> V_284 << 8 )
) ;
if ( ! ( V_155 -> V_83 & V_303 ) )
return;
F_63 ( V_155 ) ;
}
static T_3 F_86 ( struct V_20 * V_21 )
{
T_3 V_306 = F_80 ( V_21 -> V_254 . V_307 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
if ( V_27 -> V_103 & V_183 ) {
if ( V_306 & ( V_256 | V_308 | V_309 ) )
V_27 -> V_103 &= ~ V_183 ;
else
V_306 = V_256 ;
}
return V_306 ;
}
static unsigned int F_87 ( struct V_20 * V_21 , T_2 * V_310 , int V_311 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_312 , V_313 , V_314 ;
int V_114 , V_113 = 200 , V_315 = V_311 - 1 ;
V_313 = F_3 ( V_25 + V_316 ) ;
V_312 = 0x100 | ( V_313 & 0xf ) ;
F_1 ( V_312 , V_25 + V_316 ) ;
for ( V_114 = 0 ; V_114 < V_315 ; ++ V_114 )
F_2 ( V_310 [ V_114 ] , V_25 + V_317 ) ;
F_1 ( V_312 | 0x200 , V_25 + V_316 ) ;
F_1 ( V_310 [ V_315 ] , V_25 + V_317 ) ;
do {
V_314 = F_3 ( V_25 + V_318 ) ;
} while ( ! ( V_314 & 0x1000 ) && -- V_113 );
F_1 ( V_313 , V_25 + V_316 ) ;
if ( ( V_314 & 0x3000 ) != 0x1000 ) {
F_88 ( V_21 , L_13 ,
V_319 , V_314 ) ;
return V_320 ;
}
return 0 ;
}
static unsigned int F_89 ( struct V_154 * V_155 )
{
struct V_20 * V_21 = V_155 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_143 * V_144 = V_155 -> V_156 -> V_144 ;
T_2 V_310 [ 5 ] ;
int V_120 = 0 ;
F_90 ( & V_155 -> V_162 , V_144 -> V_273 , 1 , ( void * ) V_310 ) ;
V_120 = F_87 ( V_21 , V_310 , F_91 ( V_310 ) ) ;
if ( V_120 )
return V_120 ;
switch ( V_155 -> V_162 . V_100 ) {
case V_321 :
V_27 -> V_103 |= V_183 ;
case V_322 :
V_21 -> V_323 = V_324 ;
break;
case V_270 :
V_27 -> V_103 |= V_183 ;
if ( V_155 -> V_162 . V_83 & V_245 )
V_21 -> V_323 = V_324 ;
else
V_21 -> V_323 = V_325 ;
break;
default:
V_21 -> V_323 = V_326 ;
break;
}
if ( V_155 -> V_162 . V_83 & V_327 )
F_92 ( V_144 , 0 ) ;
return 0 ;
}
static unsigned int F_93 ( struct V_154 * V_155 )
{
static int V_328 = 10 ;
struct V_20 * V_21 = V_155 -> V_21 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
T_2 V_267 ;
unsigned int V_73 ;
V_27 -> V_103 &= ~ V_183 ;
switch ( V_155 -> V_162 . V_100 ) {
case V_268 :
if ( V_155 -> V_162 . V_259 == V_269 ) {
if ( ! V_21 -> V_242 -> V_329 )
return V_320 ;
break;
}
case V_102 :
F_27 ( V_21 , V_25 , V_27 , V_155 -> V_162 . V_100 ) ;
V_27 -> V_41 = ( V_27 -> V_41 + 1 ) & V_42 ;
V_267 = V_27 -> V_41 << V_43 ;
F_1 ( ( V_27 -> V_44 & V_46 ) | V_267 ,
V_25 + V_47 ) ;
return 0 ;
case V_270 :
if ( V_328 > 0 && ( V_155 -> V_330 / V_155 -> V_331 ) > 1 ) {
-- V_328 ;
F_94 ( V_155 -> V_156 -> V_144 , V_332
L_14
L_15 ) ;
}
case V_333 :
case V_321 :
case V_322 :
if ( V_21 -> V_83 & V_334 )
V_155 -> V_162 . V_83 |= V_327 ;
break;
}
if ( V_155 -> V_162 . V_83 & V_327 )
V_73 = V_72 ;
else
V_73 = V_72 | V_71 ;
F_28 ( V_21 ) ;
F_21 ( V_21 , F_11 ( V_21 ) , V_73 ) ;
F_95 ( V_21 , V_155 -> V_156 -> V_144 -> V_273 ) ;
if ( V_155 -> V_162 . V_259 == V_335 ) {
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
if ( F_55 ( V_18 ) )
return F_89 ( V_155 ) ;
}
return F_96 ( V_155 ) ;
}
static struct V_154 * F_97 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_154 * V_155 ;
if ( V_27 -> V_103 & V_106 )
return NULL ;
V_155 = F_98 ( V_21 , V_21 -> V_144 . V_336 ) ;
if ( V_155 && ! ( V_155 -> V_162 . V_83 & V_327 ) )
return V_155 ;
return NULL ;
}
static void F_99 ( struct V_20 * V_21 )
{
unsigned int V_273 , V_337 ;
struct V_26 * V_27 = V_21 -> V_19 ;
if ( V_27 -> V_103 & V_157 ) {
V_337 = V_27 -> V_338 ;
V_27 -> V_103 &= ~ V_157 ;
for ( V_273 = 0 ; V_337 != 0 ; V_273 ++ ) {
unsigned int V_339 = ( 1 << V_273 ) ;
if ( V_337 & V_339 ) {
struct V_143 * V_144 = & V_21 -> V_340 [ V_273 ] ;
V_337 &= ~ V_339 ;
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
return F_3 ( V_25 + V_341 ) >> 16 ;
}
static void F_104 ( struct V_20 * V_21 , unsigned int V_337 )
{
struct V_342 * V_343 ;
unsigned int V_273 ;
V_343 = & V_21 -> V_144 . V_344 ;
for ( V_273 = 0 ; V_337 != 0 ; V_273 ++ ) {
unsigned int V_339 = ( 1 << V_273 ) ;
if ( V_337 & V_339 ) {
struct V_143 * V_144 = & V_21 -> V_340 [ V_273 ] ;
V_337 &= ~ V_339 ;
V_343 = & V_144 -> V_344 ;
F_105 ( V_343 ) ;
F_106 ( V_343 , L_16 ) ;
V_343 -> V_345 |= V_346 ;
V_343 -> V_347 |= V_348 ;
F_107 ( V_144 ) ;
}
}
}
static int F_108 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_349 , V_350 ;
V_349 = ( F_3 ( V_25 + V_47 )
>> V_43 ) & V_42 ;
V_350 = ( F_3 ( V_25 + V_48 )
>> V_43 ) & V_42 ;
return ( V_349 == V_350 ) ;
}
static int F_109 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
int V_351 ;
unsigned int V_352 , V_353 ;
if ( ! ( V_27 -> V_103 & V_157 ) ) {
V_27 -> V_103 |= V_157 ;
V_27 -> V_338 = 0 ;
}
V_352 = V_27 -> V_338 ;
V_353 = V_352 | F_103 ( V_21 ) ;
if ( V_352 != V_353 ) {
V_27 -> V_338 = V_353 ;
F_104 ( V_21 , V_353 & ~ V_352 ) ;
}
V_351 = F_110 ( V_353 ) ;
F_111 ( V_21 ,
L_17 ,
V_319 , V_27 -> V_338 ,
V_21 -> V_354 , V_351 ,
V_21 -> V_160 ) ;
if ( V_21 -> V_160 <= V_351 && F_108 ( V_21 ) ) {
F_112 ( V_21 , V_27 ) ;
F_28 ( V_21 ) ;
F_113 ( V_21 ) ;
F_111 ( V_21 , L_18 , V_319 ) ;
return 1 ;
}
F_111 ( V_21 , L_19 , V_319 ) ;
return 1 ;
}
static int F_114 ( struct V_20 * V_21 )
{
return 0 ;
}
static int F_115 ( struct V_20 * V_21 , T_2 V_355 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
if ( ! ( V_27 -> V_103 & V_104 ) )
return 0 ;
if ( ! ( V_27 -> V_103 & V_182 ) )
return 0 ;
if ( ! ( V_355 & V_168 ) )
return 0 ;
V_355 &= ~ V_356 ;
if ( V_355 & ~ ( V_168 | V_357 ) )
return 0 ;
if ( V_27 -> V_103 & V_106 ) {
if ( V_355 & V_357 ) {
F_88 ( V_21 , L_20 ,
V_319 , V_355 , V_27 -> V_103 ) ;
return 0 ;
}
return F_109 ( V_21 ) ;
} else {
if ( ! ( V_355 & V_357 ) ) {
F_88 ( V_21 , L_20 ,
V_319 , V_355 , V_27 -> V_103 ) ;
return 0 ;
}
return F_114 ( V_21 ) ;
}
return 0 ;
}
static void F_116 ( struct V_20 * V_21 , int V_358 )
{
struct V_342 * V_343 = & V_21 -> V_144 . V_344 ;
char * V_359 = L_21 ;
F_105 ( V_343 ) ;
if ( V_358 ) {
V_359 = L_22 ;
} else {
struct V_154 * V_155 = F_98 ( V_21 , V_21 -> V_144 . V_336 ) ;
if ( V_155 && ( V_155 -> V_162 . V_83 & V_327 ) )
V_359 = L_23 ;
}
F_106 ( V_343 , L_24 , V_359 ) ;
V_343 -> V_345 |= V_320 ;
V_343 -> V_347 |= V_348 ;
F_101 ( V_21 ) ;
}
static void F_117 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_355 , V_360 , V_361 = 0 ;
T_2 V_362 = 0 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
unsigned int V_347 = 0 , V_345 = 0 ;
struct V_342 * V_343 = & V_21 -> V_144 . V_344 ;
struct V_154 * V_155 ;
int abort = 0 ;
F_118 ( & V_21 -> V_144 , V_139 , & V_361 ) ;
F_119 ( & V_21 -> V_144 , V_139 , V_361 ) ;
V_355 = F_3 ( V_25 + V_75 ) ;
if ( F_22 ( V_18 ) && ( V_355 & V_363 ) ) {
V_362 = F_3 ( V_25 + V_79 ) ;
F_1 ( ~ V_362 , V_25 + V_79 ) ;
}
F_1 ( ~ V_355 , V_25 + V_75 ) ;
if ( V_355 & V_168 ) {
if ( F_115 ( V_21 , V_355 ) )
return;
}
V_155 = F_97 ( V_21 ) ;
F_105 ( V_343 ) ;
F_106 ( V_343 , L_25 ,
V_355 , V_27 -> V_103 ) ;
if ( F_22 ( V_18 ) && ( V_355 & V_363 ) ) {
F_106 ( V_343 , L_26 , V_362 ) ;
if ( V_362 & V_364 ) {
T_2 V_365 = V_355 &
~ ( V_363 | V_356 ) ;
F_120 ( V_21 ) ;
if ( ! V_365 )
return;
F_106 ( V_343 , L_27 ) ;
}
}
if ( V_355 & V_168 ) {
V_345 |= V_346 ;
V_347 |= V_348 ;
F_106 ( V_343 , L_28 ) ;
}
if ( V_355 & ( V_366 | V_367 |
V_368 | V_369 |
V_370 ) ) {
V_345 |= V_371 ;
V_347 |= V_348 ;
F_106 ( V_343 , L_29 ) ;
}
if ( V_355 & ( V_372 | V_373 ) ) {
F_121 ( V_343 ) ;
F_106 ( V_343 , V_355 & V_372 ?
L_30 : L_31 ) ;
V_347 |= V_348 ;
}
if ( F_25 ( V_18 ) ) {
V_360 = V_374 ;
if ( V_355 & V_375 ) {
V_27 -> V_103 &= ~ V_104 ;
F_106 ( V_343 , L_32 ) ;
}
} else {
V_360 = V_376 ;
if ( V_355 & V_357 ) {
V_27 -> V_103 &= ~ V_104 ;
F_106 ( V_343 , L_32 ) ;
}
if ( V_355 & V_377 ) {
F_106 ( V_343 , L_33 , V_361 ) ;
V_345 |= V_371 ;
V_347 |= V_348 ;
}
}
if ( ! V_345 ) {
V_345 = V_320 ;
V_347 |= V_348 ;
}
V_343 -> V_378 |= V_361 ;
V_343 -> V_347 |= V_347 ;
if ( V_155 )
V_155 -> V_345 |= V_345 ;
else
V_343 -> V_345 |= V_345 ;
if ( V_345 == V_346 ) {
F_113 ( V_21 ) ;
abort = 1 ;
} else if ( V_355 & V_360 ) {
F_101 ( V_21 ) ;
} else {
abort = 1 ;
}
if ( abort ) {
if ( V_155 )
F_107 ( V_155 -> V_156 -> V_144 ) ;
else
F_122 ( V_21 ) ;
}
}
static bool F_123 ( struct V_20 * V_21 ,
struct V_379 * V_380 , unsigned int V_190 , int V_381 )
{
T_3 V_382 ;
T_6 V_383 = F_124 ( V_380 -> V_83 ) ;
if ( ! V_381 ) {
T_3 V_384 = V_383 & 0xff & ~ V_168 ;
if ( V_384 ) {
return false ;
}
}
V_382 = V_383 >> V_385 ;
if ( ! F_125 ( V_382 ) )
return true ;
return false ;
}
static void F_112 ( struct V_20 * V_21 , struct V_26 * V_27 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
T_2 V_267 ;
bool V_386 = false ;
T_2 V_387 = 0 ;
int V_381 = ( V_27 -> V_103 & V_106 ) ;
V_267 = ( F_3 ( V_25 + V_53 )
>> V_50 ) & V_42 ;
while ( V_267 != V_27 -> V_49 ) {
unsigned int V_190 ;
struct V_379 * V_380 = & V_27 -> V_193 [ V_27 -> V_49 ] ;
V_27 -> V_49 = ( V_27 -> V_49 + 1 ) & V_42 ;
if ( F_25 ( V_18 ) ) {
V_190 = V_21 -> V_144 . V_336 ;
} else {
V_190 = F_124 ( V_380 -> V_388 ) & 0x1f ;
}
if ( F_123 ( V_21 , V_380 , V_190 , V_381 ) )
V_387 |= 1 << V_190 ;
V_386 = true ;
}
if ( V_386 ) {
F_126 ( V_21 , V_21 -> V_354 ^ V_387 ) ;
F_1 ( ( V_27 -> V_51 & V_54 ) |
( V_27 -> V_49 << V_50 ) ,
V_25 + V_55 ) ;
}
}
static void F_127 ( struct V_20 * V_21 , T_2 V_389 )
{
struct V_26 * V_27 ;
int V_358 ;
V_27 = V_21 -> V_19 ;
V_358 = ( V_27 -> V_103 & V_104 ) ;
if ( V_358 && ( V_389 & V_71 ) ) {
F_112 ( V_21 , V_27 ) ;
if ( V_27 -> V_103 & V_157 )
F_109 ( V_21 ) ;
}
if ( F_48 ( V_389 & V_72 ) ) {
F_117 ( V_21 ) ;
} else if ( ! V_358 ) {
struct V_154 * V_155 = F_97 ( V_21 ) ;
if ( V_155 )
F_128 ( V_21 , V_155 ) ;
else
F_116 ( V_21 , V_358 ) ;
}
}
static int F_129 ( struct V_15 * V_16 , T_2 V_390 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 , * V_13 ;
unsigned int V_391 = 0 , V_3 ;
if ( V_390 & V_57 )
F_2 ( ~ V_95 , V_12 + V_96 ) ;
for ( V_3 = 0 ; V_3 < V_18 -> V_86 ; V_3 ++ ) {
struct V_20 * V_21 = V_16 -> V_178 [ V_3 ] ;
unsigned int V_133 , V_69 , V_70 , V_389 ;
F_20 ( V_3 , V_69 , V_70 ) ;
if ( V_70 == 0 ) {
T_2 V_392 = ( V_390 >> V_69 ) & V_393 ;
T_2 V_394 , V_395 ;
if ( ! V_392 ) {
V_3 += V_87 - 1 ;
continue;
}
V_395 = 0 ;
if ( V_392 & V_58 )
V_395 = V_99 ;
for ( V_133 = 0 ; V_133 < V_87 ; ++ V_133 ) {
if ( ( V_3 + V_133 ) >= V_18 -> V_86 )
break;
V_394 = ( V_71 | V_72 ) << ( V_133 * 2 ) ;
if ( V_392 & V_394 )
V_395 |= ( V_77 | V_76 ) << V_133 ;
}
V_13 = F_7 ( V_12 , V_3 ) ;
F_1 ( ~ V_395 , V_13 + V_78 ) ;
V_391 = 1 ;
}
V_389 = ( V_390 >> V_69 ) & ( V_71 | V_72 ) ;
if ( V_389 )
F_127 ( V_21 , V_389 ) ;
}
return V_391 ;
}
static int F_130 ( struct V_15 * V_16 , void T_1 * V_12 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 ;
struct V_154 * V_155 ;
struct V_342 * V_343 ;
unsigned int V_114 , V_345 , V_396 = 0 ;
T_2 V_384 ;
V_384 = F_3 ( V_12 + V_18 -> V_397 ) ;
F_131 ( V_16 -> V_156 , L_34 , V_384 ) ;
F_35 ( L_35 ) ;
F_40 ( V_12 , - 1 , F_132 ( V_16 -> V_156 ) ) ;
F_1 ( 0 , V_12 + V_18 -> V_397 ) ;
for ( V_114 = 0 ; V_114 < V_16 -> V_86 ; V_114 ++ ) {
V_21 = V_16 -> V_178 [ V_114 ] ;
if ( ! F_133 ( & V_21 -> V_144 ) ) {
V_343 = & V_21 -> V_144 . V_344 ;
F_105 ( V_343 ) ;
if ( ! V_396 ++ )
F_106 ( V_343 ,
L_36 , V_384 ) ;
V_345 = V_398 ;
V_343 -> V_347 = V_348 ;
V_155 = F_98 ( V_21 , V_21 -> V_144 . V_336 ) ;
if ( V_155 )
V_155 -> V_345 |= V_345 ;
else
V_343 -> V_345 |= V_345 ;
F_101 ( V_21 ) ;
}
}
return 1 ;
}
static T_7 F_134 ( int V_399 , void * V_400 )
{
struct V_15 * V_16 = V_400 ;
struct V_17 * V_18 = V_16 -> V_19 ;
unsigned int V_391 = 0 ;
int V_401 = V_18 -> V_147 & V_402 ;
T_2 V_390 , V_403 ;
F_135 ( & V_16 -> V_92 ) ;
if ( V_401 )
F_17 ( 0 , V_18 ) ;
V_390 = F_3 ( V_18 -> V_404 ) ;
V_403 = V_390 & V_18 -> V_67 ;
if ( V_403 && V_390 != 0xffffffffU ) {
if ( F_48 ( ( V_403 & V_405 ) && ! F_56 ( V_18 ) ) )
V_391 = F_130 ( V_16 , V_18 -> V_6 ) ;
else
V_391 = F_129 ( V_16 , V_403 ) ;
}
if ( V_401 )
F_17 ( V_18 -> V_67 , V_18 ) ;
F_136 ( & V_16 -> V_92 ) ;
return F_137 ( V_391 ) ;
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
struct V_125 * V_126 = F_132 ( V_16 -> V_156 ) ;
int V_406 ;
V_406 = ( V_126 -> V_199 == 0x5080 ) && ( V_126 -> V_407 == 0 ) ;
if ( ! V_406 ) {
T_2 V_221 = F_3 ( V_12 + V_408 ) ;
V_221 |= ( 1 << 0 ) ;
F_2 ( V_221 , V_12 + V_408 ) ;
}
F_142 ( V_16 , V_12 ) ;
}
static void F_143 ( struct V_17 * V_18 , void T_1 * V_12 )
{
F_2 ( 0x0fcfffff , V_12 + V_409 ) ;
}
static void F_144 ( struct V_17 * V_18 , int V_410 ,
void T_1 * V_12 )
{
void T_1 * V_411 = F_9 ( V_12 , V_410 ) ;
T_2 V_221 ;
V_221 = F_3 ( V_411 + V_412 ) ;
V_18 -> signal [ V_410 ] . V_413 = V_221 & 0x1800 ;
V_18 -> signal [ V_410 ] . V_414 = V_221 & 0xe0 ;
}
static void F_145 ( struct V_17 * V_18 , void T_1 * V_12 )
{
T_2 V_221 ;
F_2 ( 0 , V_12 + V_171 ) ;
V_221 = F_3 ( V_12 + V_408 ) ;
V_221 |= ~ ( 1 << 0 ) ;
F_2 ( V_221 , V_12 + V_408 ) ;
}
static void F_146 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_3 )
{
void T_1 * V_411 = F_9 ( V_12 , V_3 ) ;
const T_2 V_56 = ( 1 << 12 ) | ( 1 << 11 ) | ( 1 << 7 ) | ( 1 << 6 ) | ( 1 << 5 ) ;
T_2 V_221 ;
int V_415 = ( V_18 -> V_147 & V_416 ) ;
if ( V_415 ) {
V_221 = F_3 ( V_411 + V_417 ) ;
V_221 |= ( 1 << 19 ) ;
F_2 ( V_221 , V_411 + V_417 ) ;
V_221 = F_3 ( V_411 + V_418 ) ;
V_221 &= ~ 0x3 ;
V_221 |= 0x1 ;
F_2 ( V_221 , V_411 + V_418 ) ;
}
V_221 = F_3 ( V_411 + V_412 ) ;
V_221 &= ~ V_56 ;
V_221 |= V_18 -> signal [ V_3 ] . V_413 ;
V_221 |= V_18 -> signal [ V_3 ] . V_414 ;
F_2 ( V_221 , V_411 + V_412 ) ;
}
static void F_147 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
F_148 ( V_18 , V_12 , V_3 ) ;
F_149 ( 0x028 ) ;
F_2 ( 0x11f , V_25 + V_189 ) ;
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
F_2 ( 0xbc , V_25 + V_419 ) ;
}
static void F_150 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_7 )
{
void T_1 * V_13 = F_6 ( V_12 , V_7 ) ;
T_2 V_221 ;
F_149 ( 0x00c ) ;
F_149 ( 0x010 ) ;
F_149 ( 0x014 ) ;
F_149 ( 0x018 ) ;
V_221 = F_3 ( V_13 + 0x20 ) ;
V_221 &= 0x1c1c1c1c ;
V_221 |= 0x03030303 ;
F_2 ( V_221 , V_13 + 0x20 ) ;
}
static int F_151 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_420 )
{
unsigned int V_7 , V_3 ;
for ( V_7 = 0 ; V_7 < V_420 ; V_7 ++ ) {
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
T_2 V_221 ;
V_221 = F_3 ( V_12 + V_421 ) ;
V_221 &= 0xff00ffff ;
F_2 ( V_221 , V_12 + V_421 ) ;
F_149 ( V_422 ) ;
F_149 ( V_423 ) ;
F_2 ( 0x000100ff , V_12 + V_424 ) ;
F_149 ( V_425 ) ;
F_149 ( V_18 -> V_397 ) ;
F_149 ( V_18 -> V_426 ) ;
F_149 ( V_427 ) ;
F_149 ( V_428 ) ;
F_149 ( V_429 ) ;
F_149 ( V_430 ) ;
}
static void F_152 ( struct V_17 * V_18 , void T_1 * V_12 )
{
T_2 V_221 ;
F_143 ( V_18 , V_12 ) ;
V_221 = F_3 ( V_12 + V_171 ) ;
V_221 &= 0x3 ;
V_221 |= ( 1 << 5 ) | ( 1 << 6 ) ;
F_2 ( V_221 , V_12 + V_171 ) ;
}
static int F_153 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_420 )
{
void T_1 * V_118 = V_12 + V_431 ;
int V_114 , V_432 = 0 ;
T_2 V_433 ;
V_433 = F_3 ( V_118 ) ;
F_2 ( V_433 | V_434 , V_118 ) ;
for ( V_114 = 0 ; V_114 < 1000 ; V_114 ++ ) {
F_31 ( 1 ) ;
V_433 = F_3 ( V_118 ) ;
if ( V_435 & V_433 )
break;
}
if ( ! ( V_435 & V_433 ) ) {
F_36 (KERN_ERR DRV_NAME L_37 ) ;
V_432 = 1 ;
goto V_436;
}
V_114 = 5 ;
do {
F_2 ( V_433 | V_437 , V_118 ) ;
V_433 = F_3 ( V_118 ) ;
F_31 ( 1 ) ;
} while ( ! ( V_437 & V_433 ) && ( V_114 -- > 0 ) );
if ( ! ( V_437 & V_433 ) ) {
F_36 (KERN_ERR DRV_NAME L_38 ) ;
V_432 = 1 ;
goto V_436;
}
V_114 = 5 ;
do {
F_2 ( V_433 & ~ ( V_437 | V_434 ) , V_118 ) ;
V_433 = F_3 ( V_118 ) ;
F_31 ( 1 ) ;
} while ( ( V_437 & V_433 ) && ( V_114 -- > 0 ) );
if ( V_437 & V_433 ) {
F_36 (KERN_ERR DRV_NAME L_39 ) ;
V_432 = 1 ;
}
V_436:
return V_432 ;
}
static void F_154 ( struct V_17 * V_18 , int V_410 ,
void T_1 * V_12 )
{
void T_1 * V_25 ;
T_2 V_221 ;
V_221 = F_3 ( V_12 + V_438 ) ;
if ( ( V_221 & ( 1 << 0 ) ) == 0 ) {
V_18 -> signal [ V_410 ] . V_414 = 0x7 << 8 ;
V_18 -> signal [ V_410 ] . V_413 = 0x1 << 5 ;
return;
}
V_25 = F_8 ( V_12 , V_410 ) ;
V_221 = F_3 ( V_25 + V_439 ) ;
V_18 -> signal [ V_410 ] . V_414 = V_221 & 0x700 ;
V_18 -> signal [ V_410 ] . V_413 = V_221 & 0xe0 ;
}
static void F_155 ( struct V_17 * V_18 , void T_1 * V_12 )
{
F_2 ( 0x00000060 , V_12 + V_171 ) ;
}
static void F_156 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
T_2 V_147 = V_18 -> V_147 ;
int V_440 =
V_147 & ( V_441 | V_205 ) ;
int V_442 =
V_147 & ( V_441 | V_205 ) ;
T_2 V_443 , V_444 ;
if ( V_440 ) {
V_443 = F_3 ( V_25 + V_439 ) ;
V_443 &= ~ ( 1 << 16 ) ;
V_443 |= ( 1 << 31 ) ;
F_2 ( V_443 , V_25 + V_439 ) ;
F_31 ( 200 ) ;
V_443 = F_3 ( V_25 + V_439 ) ;
V_443 &= ~ ( ( 1 << 16 ) | ( 1 << 31 ) ) ;
F_2 ( V_443 , V_25 + V_439 ) ;
F_31 ( 200 ) ;
}
V_444 = F_3 ( V_25 + V_445 ) ;
V_444 = ( V_444 & 0x1f ) | ( 0x5555601 << 5 ) ;
if ( F_56 ( V_18 ) )
V_444 &= ~ 0x1c ;
if ( V_442 ) {
T_2 V_446 = F_3 ( V_25 + V_447 ) ;
if ( F_22 ( V_18 ) )
V_446 = ( V_446 & ~ V_448 ) | V_449 ;
else
V_446 = ( V_446 & ~ V_450 ) | V_451 ;
F_2 ( V_446 , V_25 + V_447 ) ;
}
F_2 ( V_444 , V_25 + V_445 ) ;
V_443 = F_3 ( V_25 + V_439 ) ;
V_443 &= ~ V_452 ;
V_443 |= V_18 -> signal [ V_3 ] . V_414 ;
V_443 |= V_18 -> signal [ V_3 ] . V_413 ;
V_443 &= ~ ( 1 << 16 ) ;
if ( F_22 ( V_18 ) ) {
V_443 &= ~ 0xC30FF01F ;
V_443 |= 0x0000900F ;
}
F_2 ( V_443 , V_25 + V_439 ) ;
}
static void F_157 ( struct V_17 * V_18 ,
void T_1 * V_12 )
{
return;
}
static void F_158 ( struct V_17 * V_18 , int V_410 ,
void T_1 * V_12 )
{
void T_1 * V_25 ;
T_2 V_221 ;
V_25 = F_8 ( V_12 , V_410 ) ;
V_221 = F_3 ( V_25 + V_439 ) ;
V_18 -> signal [ V_410 ] . V_414 = V_221 & 0x700 ;
V_18 -> signal [ V_410 ] . V_413 = V_221 & 0xe0 ;
}
static void F_159 ( struct V_17 * V_18 ,
void T_1 * V_12 , unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
F_148 ( V_18 , V_12 , V_3 ) ;
F_149 ( 0x028 ) ;
F_2 ( 0x101f , V_25 + V_189 ) ;
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
F_2 ( 0x800 , V_25 + V_419 ) ;
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
void T_1 * V_12 , unsigned int V_420 )
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
V_118 = F_3 ( V_25 + V_445 ) ;
V_118 &= ~ ( 0x3 << 27 ) ;
V_118 |= ( 0x1 << 27 ) ;
V_118 &= ~ ( 0x3 << 29 ) ;
V_118 |= ( 0x1 << 29 ) ;
F_2 ( V_118 , V_25 + V_445 ) ;
V_118 = F_3 ( V_25 + V_447 ) ;
V_118 &= ~ 0x1 ;
V_118 |= ( 0x1 << 16 ) ;
F_2 ( V_118 , V_25 + V_447 ) ;
V_118 = F_3 ( V_25 + V_453 ) ;
V_118 &= ~ 0xf ;
V_118 |= 0x8 ;
V_118 &= ~ ( 0x1 << 14 ) ;
F_2 ( V_118 , V_25 + V_453 ) ;
V_118 = F_3 ( V_25 + V_454 ) ;
V_118 &= ~ 0xf ;
V_118 |= 0x8 ;
V_118 &= ~ ( 0x1 << 14 ) ;
F_2 ( V_118 , V_25 + V_454 ) ;
}
static bool F_165 ( struct V_17 * V_18 )
{
void T_1 * V_455 = F_8 ( V_18 -> V_6 , 0 ) ;
if ( F_3 ( V_455 + V_456 ) )
return true ;
return false ;
}
static void F_166 ( void T_1 * V_25 , int V_457 )
{
T_2 V_458 = F_3 ( V_25 + V_459 ) ;
V_458 = ( V_458 & 0xf7f ) | 0x9b1000 ;
if ( V_457 )
V_458 |= ( 1 << 7 ) ;
F_1 ( V_458 , V_25 + V_459 ) ;
}
static void F_148 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_22 )
{
void T_1 * V_25 = F_8 ( V_12 , V_22 ) ;
F_32 ( V_25 ) ;
F_1 ( V_460 , V_25 + V_108 ) ;
if ( ! F_25 ( V_18 ) ) {
F_166 ( V_25 , 1 ) ;
}
F_1 ( V_460 , V_25 + V_108 ) ;
F_31 ( 25 ) ;
F_1 ( 0 , V_25 + V_108 ) ;
V_18 -> V_242 -> V_461 ( V_18 , V_12 , V_22 ) ;
if ( F_25 ( V_18 ) )
F_167 ( 1 ) ;
}
static void F_95 ( struct V_20 * V_21 , int V_273 )
{
if ( F_168 ( V_21 ) ) {
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_118 = F_3 ( V_25 + V_316 ) ;
int V_37 = V_118 & 0xf ;
if ( V_37 != V_273 ) {
V_118 = ( V_118 & ~ 0xf ) | V_273 ;
F_1 ( V_118 , V_25 + V_316 ) ;
}
}
}
static int F_169 ( struct V_143 * V_144 , unsigned int * V_462 ,
unsigned long V_463 )
{
F_95 ( V_144 -> V_21 , F_170 ( V_144 ) ) ;
return F_171 ( V_144 , V_462 , V_463 ) ;
}
static int F_172 ( struct V_143 * V_144 , unsigned int * V_462 ,
unsigned long V_463 )
{
F_95 ( V_144 -> V_21 , F_170 ( V_144 ) ) ;
return F_173 ( V_144 , V_462 , V_463 ) ;
}
static int F_174 ( struct V_143 * V_144 , unsigned int * V_462 ,
unsigned long V_463 )
{
struct V_20 * V_21 = V_144 -> V_21 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
struct V_26 * V_27 = V_21 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
int V_432 , V_464 = 0 , V_465 = 0 ;
T_2 V_466 ;
bool V_467 ;
F_148 ( V_18 , V_12 , V_21 -> V_22 ) ;
V_27 -> V_103 &= ~ V_104 ;
V_27 -> V_103 &=
~ ( V_182 | V_106 | V_183 ) ;
do {
const unsigned long * V_468 =
F_175 ( & V_144 -> V_469 ) ;
V_432 = F_176 ( V_144 , V_468 , V_463 + V_465 ,
& V_467 , NULL ) ;
V_432 = V_467 ? - V_470 : V_432 ;
if ( V_432 )
return V_432 ;
F_118 ( V_144 , V_137 , & V_466 ) ;
if ( ! F_25 ( V_18 ) && ++ V_464 >= 5 && V_466 == 0x121 ) {
F_166 ( F_11 ( V_21 ) , 0 ) ;
if ( F_177 ( V_471 + V_472 , V_463 ) )
V_465 = V_472 ;
}
} while ( V_466 != 0x0 && V_466 != 0x113 && V_466 != 0x123 );
F_13 ( V_21 ) ;
F_29 ( V_21 , 0 , 0 ) ;
return V_432 ;
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
static void F_179 ( struct V_473 * V_3 , void T_1 * V_25 )
{
void T_1 * V_361 , * V_474 = V_25 + V_475 ;
V_3 -> V_476 = V_474 + ( sizeof( T_2 ) * V_477 ) ;
V_3 -> V_478 =
V_3 -> V_479 = V_474 + ( sizeof( T_2 ) * V_480 ) ;
V_3 -> V_481 = V_474 + ( sizeof( T_2 ) * V_285 ) ;
V_3 -> V_482 = V_474 + ( sizeof( T_2 ) * V_293 ) ;
V_3 -> V_483 = V_474 + ( sizeof( T_2 ) * V_296 ) ;
V_3 -> V_484 = V_474 + ( sizeof( T_2 ) * V_299 ) ;
V_3 -> V_485 = V_474 + ( sizeof( T_2 ) * V_301 ) ;
V_3 -> V_307 =
V_3 -> V_486 = V_474 + ( sizeof( T_2 ) * V_487 ) ;
V_3 -> V_255 = V_3 -> V_488 = V_474 + V_489 ;
V_361 = V_25 + F_41 ( V_139 ) ;
F_1 ( F_3 ( V_361 ) , V_361 ) ;
F_1 ( 0 , V_25 + V_75 ) ;
F_1 ( ~ V_356 , V_25 + V_490 ) ;
F_180 ( L_40 ,
F_3 ( V_25 + V_189 ) ,
F_3 ( V_25 + V_75 ) ,
F_3 ( V_25 + V_490 ) ) ;
}
static unsigned int F_181 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
T_2 V_118 ;
if ( F_56 ( V_18 ) || ! F_182 ( V_18 ) )
return 0 ;
V_118 = F_3 ( V_12 + V_421 ) ;
if ( ( V_118 & V_491 ) == 0 )
return 0 ;
return 1 ;
}
static int F_183 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
T_2 V_118 ;
if ( ! F_181 ( V_16 ) ) {
V_118 = F_3 ( V_12 + V_492 ) ;
if ( V_118 & V_493 )
return 0 ;
}
return 1 ;
}
static void F_184 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
if ( F_181 ( V_16 ) ) {
T_2 V_118 = F_3 ( V_12 + V_492 ) ;
F_1 ( V_118 & ~ V_494 , V_12 + V_492 ) ;
}
}
static int F_185 ( struct V_15 * V_16 , unsigned int V_495 )
{
struct V_125 * V_126 = F_132 ( V_16 -> V_156 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
T_2 V_147 = V_18 -> V_147 ;
switch ( V_495 ) {
case V_496 :
V_18 -> V_242 = & V_497 ;
V_147 |= V_498 ;
switch ( V_126 -> V_407 ) {
case 0x1 :
V_147 |= V_416 ;
break;
case 0x3 :
V_147 |= V_499 ;
break;
default:
F_186 ( & V_126 -> V_156 ,
L_41 ) ;
V_147 |= V_499 ;
break;
}
break;
case V_500 :
case V_501 :
V_18 -> V_242 = & V_497 ;
V_147 |= V_498 ;
switch ( V_126 -> V_407 ) {
case 0x0 :
V_147 |= V_416 ;
break;
case 0x3 :
V_147 |= V_499 ;
break;
default:
F_186 ( & V_126 -> V_156 ,
L_42 ) ;
V_147 |= V_499 ;
break;
}
break;
case V_502 :
case V_503 :
V_18 -> V_242 = & V_504 ;
V_147 |= V_505 ;
switch ( V_126 -> V_407 ) {
case 0x7 :
F_184 ( V_16 ) ;
V_147 |= V_441 ;
break;
case 0x9 :
V_147 |= V_205 ;
break;
default:
F_186 ( & V_126 -> V_156 ,
L_42 ) ;
V_147 |= V_441 ;
break;
}
break;
case V_506 :
V_147 |= V_507 | V_187 ;
if ( V_126 -> V_508 == V_509 &&
( V_126 -> V_199 == 0x2300 || V_126 -> V_199 == 0x2310 ) )
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
case V_510 :
V_18 -> V_242 = & V_504 ;
V_147 |= V_511 ;
if ( V_495 == V_510 && F_183 ( V_16 ) )
V_147 |= V_187 ;
switch ( V_126 -> V_407 ) {
case 0x2 :
V_147 |= V_205 ;
break;
default:
F_186 ( & V_126 -> V_156 ,
L_51 ) ;
V_147 |= V_205 ;
break;
}
break;
case V_512 :
if ( F_165 ( V_18 ) )
V_18 -> V_242 = & V_513 ;
else
V_18 -> V_242 = & V_514 ;
V_147 |= V_515 | V_511 |
V_205 ;
break;
default:
F_131 ( V_16 -> V_156 , L_52 , V_495 ) ;
return 1 ;
}
V_18 -> V_147 = V_147 ;
if ( V_147 & V_507 ) {
V_18 -> V_397 = V_516 ;
V_18 -> V_426 = V_517 ;
V_18 -> V_518 = V_519 ;
} else {
V_18 -> V_397 = V_520 ;
V_18 -> V_426 = V_521 ;
V_18 -> V_518 = V_522 ;
}
return 0 ;
}
static int F_187 ( struct V_15 * V_16 )
{
int V_432 = 0 , V_420 , V_3 , V_7 ;
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
V_432 = F_185 ( V_16 , V_18 -> V_495 ) ;
if ( V_432 )
goto V_436;
if ( F_56 ( V_18 ) ) {
V_18 -> V_404 = V_12 + V_523 ;
V_18 -> V_62 = V_12 + V_524 ;
} else {
V_18 -> V_404 = V_12 + V_525 ;
V_18 -> V_62 = V_12 + V_526 ;
}
V_18 -> V_67 = F_3 ( V_18 -> V_62 ) ;
F_18 ( V_16 , ~ 0 , 0 ) ;
V_420 = F_12 ( V_16 -> V_178 [ 0 ] -> V_83 ) ;
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ )
if ( V_18 -> V_242 -> V_527 )
V_18 -> V_242 -> V_527 ( V_18 , V_3 , V_12 ) ;
V_432 = V_18 -> V_242 -> V_528 ( V_18 , V_12 , V_420 ) ;
if ( V_432 )
goto V_436;
V_18 -> V_242 -> V_529 ( V_18 , V_12 ) ;
V_18 -> V_242 -> V_530 ( V_16 , V_12 ) ;
V_18 -> V_242 -> V_531 ( V_18 , V_12 ) ;
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ ) {
struct V_20 * V_21 = V_16 -> V_178 [ V_3 ] ;
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
F_179 ( & V_21 -> V_254 , V_25 ) ;
}
for ( V_7 = 0 ; V_7 < V_420 ; V_7 ++ ) {
void T_1 * V_13 = F_6 ( V_12 , V_7 ) ;
F_180 ( L_53
L_54 , V_7 ,
F_3 ( V_13 + V_532 ) ,
F_3 ( V_13 + V_78 ) ) ;
F_1 ( 0 , V_13 + V_78 ) ;
}
if ( ! F_56 ( V_18 ) ) {
F_1 ( 0 , V_12 + V_18 -> V_397 ) ;
F_1 ( V_18 -> V_518 , V_12 + V_18 -> V_426 ) ;
}
F_18 ( V_16 , 0 , V_405 ) ;
F_23 ( V_16 , V_533 ,
V_534 ) ;
V_436:
return V_432 ;
}
static int F_188 ( struct V_17 * V_18 , struct V_199 * V_156 )
{
V_18 -> V_192 = F_189 ( L_55 , V_156 , V_202 ,
V_202 , 0 ) ;
if ( ! V_18 -> V_192 )
return - V_201 ;
V_18 -> V_194 = F_189 ( L_56 , V_156 , V_204 ,
V_204 , 0 ) ;
if ( ! V_18 -> V_194 )
return - V_201 ;
V_18 -> V_197 = F_189 ( L_57 , V_156 , V_535 ,
V_535 , 0 ) ;
if ( ! V_18 -> V_197 )
return - V_201 ;
return 0 ;
}
static void F_190 ( struct V_17 * V_18 ,
const struct V_536 * V_537 )
{
int V_114 ;
for ( V_114 = 0 ; V_114 < 4 ; V_114 ++ ) {
F_2 ( 0 , V_18 -> V_6 + F_191 ( V_114 ) ) ;
F_2 ( 0 , V_18 -> V_6 + F_192 ( V_114 ) ) ;
}
for ( V_114 = 0 ; V_114 < V_537 -> V_538 ; V_114 ++ ) {
const struct V_539 * V_540 = V_537 -> V_540 + V_114 ;
F_2 ( ( ( V_540 -> V_541 - 1 ) & 0xffff0000 ) |
( V_540 -> V_542 << 8 ) |
( V_537 -> V_543 << 4 ) | 1 ,
V_18 -> V_6 + F_191 ( V_114 ) ) ;
F_2 ( V_540 -> V_6 , V_18 -> V_6 + F_192 ( V_114 ) ) ;
}
}
static int F_193 ( struct V_544 * V_126 )
{
const struct V_545 * V_546 ;
const struct V_536 * V_537 ;
const struct F_111 * V_547 [] =
{ & V_548 [ V_512 ] , NULL } ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_549 * V_550 ;
int V_86 = 0 , V_399 = 0 ;
int V_432 ;
int V_3 ;
F_194 ( & V_126 -> V_156 , V_551 ) ;
if ( F_48 ( V_126 -> V_552 != 2 ) ) {
F_131 ( & V_126 -> V_156 , L_58 ) ;
return - V_146 ;
}
V_550 = F_195 ( V_126 , V_553 , 0 ) ;
if ( V_550 == NULL )
return - V_146 ;
if ( V_126 -> V_156 . V_554 ) {
F_196 ( V_126 -> V_156 . V_554 , L_59 , & V_86 ) ;
V_399 = F_197 ( V_126 -> V_156 . V_554 , 0 ) ;
} else {
V_546 = F_198 ( & V_126 -> V_156 ) ;
V_86 = V_546 -> V_86 ;
V_399 = F_199 ( V_126 , 0 ) ;
}
V_16 = F_200 ( & V_126 -> V_156 , V_547 , V_86 ) ;
V_18 = F_60 ( & V_126 -> V_156 , sizeof( * V_18 ) , V_200 ) ;
if ( ! V_16 || ! V_18 )
return - V_201 ;
V_18 -> V_555 = F_60 ( & V_126 -> V_156 ,
sizeof( struct V_556 * ) * V_86 ,
V_200 ) ;
if ( ! V_18 -> V_555 )
return - V_201 ;
V_18 -> V_557 = F_60 ( & V_126 -> V_156 ,
sizeof( struct V_558 * ) * V_86 ,
V_200 ) ;
if ( ! V_18 -> V_557 )
return - V_201 ;
V_16 -> V_19 = V_18 ;
V_18 -> V_495 = V_512 ;
V_16 -> V_559 = NULL ;
V_18 -> V_6 = F_201 ( & V_126 -> V_156 , V_550 -> V_121 ,
F_202 ( V_550 ) ) ;
V_18 -> V_6 -= V_8 ;
V_18 -> V_556 = F_203 ( & V_126 -> V_156 , NULL ) ;
if ( F_204 ( V_18 -> V_556 ) )
F_205 ( & V_126 -> V_156 , L_60 ) ;
else
F_206 ( V_18 -> V_556 ) ;
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
char V_560 [ 16 ] ;
sprintf ( V_560 , L_61 , V_3 ) ;
V_18 -> V_555 [ V_3 ] = F_203 ( & V_126 -> V_156 , V_560 ) ;
if ( ! F_204 ( V_18 -> V_555 [ V_3 ] ) )
F_206 ( V_18 -> V_555 [ V_3 ] ) ;
sprintf ( V_560 , L_62 , V_3 ) ;
V_18 -> V_557 [ V_3 ] = F_207 ( & V_126 -> V_156 ,
V_560 ) ;
if ( F_204 ( V_18 -> V_557 [ V_3 ] ) ) {
V_432 = F_208 ( V_18 -> V_557 [ V_3 ] ) ;
V_18 -> V_557 [ V_3 ] = NULL ;
if ( V_432 != - V_561 )
F_186 ( & V_126 -> V_156 , L_63 , V_432 ) ;
V_18 -> V_86 = V_3 ;
goto V_120;
} else
F_209 ( V_18 -> V_557 [ V_3 ] ) ;
}
V_18 -> V_86 = V_86 ;
V_537 = F_210 () ;
if ( V_537 )
F_190 ( V_18 , V_537 ) ;
V_432 = F_188 ( V_18 , & V_126 -> V_156 ) ;
if ( V_432 )
goto V_120;
if ( V_126 -> V_156 . V_554 &&
F_211 ( V_126 -> V_156 . V_554 ,
L_64 ) )
V_18 -> V_147 |= V_148 ;
V_432 = F_187 ( V_16 ) ;
if ( V_432 )
goto V_120;
F_212 ( & V_126 -> V_156 , L_65 ,
( unsigned ) V_195 , V_16 -> V_86 ) ;
V_432 = F_213 ( V_16 , V_399 , F_134 , V_562 , & V_563 ) ;
if ( ! V_432 )
return 0 ;
V_120:
if ( ! F_204 ( V_18 -> V_556 ) ) {
F_214 ( V_18 -> V_556 ) ;
F_215 ( V_18 -> V_556 ) ;
}
for ( V_3 = 0 ; V_3 < V_18 -> V_86 ; V_3 ++ ) {
if ( ! F_204 ( V_18 -> V_555 [ V_3 ] ) ) {
F_214 ( V_18 -> V_555 [ V_3 ] ) ;
F_215 ( V_18 -> V_555 [ V_3 ] ) ;
}
F_216 ( V_18 -> V_557 [ V_3 ] ) ;
}
return V_432 ;
}
static int F_217 ( struct V_544 * V_126 )
{
struct V_15 * V_16 = F_218 ( V_126 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
int V_3 ;
F_219 ( V_16 ) ;
if ( ! F_204 ( V_18 -> V_556 ) ) {
F_214 ( V_18 -> V_556 ) ;
F_215 ( V_18 -> V_556 ) ;
}
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ ) {
if ( ! F_204 ( V_18 -> V_555 [ V_3 ] ) ) {
F_214 ( V_18 -> V_555 [ V_3 ] ) ;
F_215 ( V_18 -> V_555 [ V_3 ] ) ;
}
F_216 ( V_18 -> V_557 [ V_3 ] ) ;
}
return 0 ;
}
static int F_220 ( struct V_544 * V_126 , T_8 V_564 )
{
struct V_15 * V_16 = F_218 ( V_126 ) ;
if ( V_16 )
return F_221 ( V_16 , V_564 ) ;
else
return 0 ;
}
static int F_222 ( struct V_544 * V_126 )
{
struct V_15 * V_16 = F_218 ( V_126 ) ;
const struct V_536 * V_537 ;
int V_565 ;
if ( V_16 ) {
struct V_17 * V_18 = V_16 -> V_19 ;
V_537 = F_210 () ;
if ( V_537 )
F_190 ( V_18 , V_537 ) ;
V_565 = F_187 ( V_16 ) ;
if ( V_565 ) {
F_36 (KERN_ERR DRV_NAME L_66 ) ;
return V_565 ;
}
F_223 ( V_16 ) ;
}
return 0 ;
}
static int F_224 ( struct V_125 * V_126 )
{
int V_432 ;
if ( ! F_225 ( V_126 , F_226 ( 64 ) ) ) {
V_432 = F_227 ( V_126 , F_226 ( 64 ) ) ;
if ( V_432 ) {
V_432 = F_227 ( V_126 , F_226 ( 32 ) ) ;
if ( V_432 ) {
F_131 ( & V_126 -> V_156 ,
L_67 ) ;
return V_432 ;
}
}
} else {
V_432 = F_225 ( V_126 , F_226 ( 32 ) ) ;
if ( V_432 ) {
F_131 ( & V_126 -> V_156 , L_68 ) ;
return V_432 ;
}
V_432 = F_227 ( V_126 , F_226 ( 32 ) ) ;
if ( V_432 ) {
F_131 ( & V_126 -> V_156 ,
L_69 ) ;
return V_432 ;
}
}
return V_432 ;
}
static void F_228 ( struct V_15 * V_16 )
{
struct V_125 * V_126 = F_132 ( V_16 -> V_156 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
T_3 V_566 ;
const char * V_567 , * V_568 ;
F_229 ( V_126 , V_569 , & V_566 ) ;
if ( V_566 == 0 )
V_567 = L_70 ;
else if ( V_566 == 0x01 )
V_567 = L_71 ;
else
V_567 = L_72 ;
if ( F_25 ( V_18 ) )
V_568 = L_73 ;
else if ( F_55 ( V_18 ) )
V_568 = L_74 ;
else if ( F_22 ( V_18 ) )
V_568 = L_75 ;
else
V_568 = L_72 ;
F_212 ( & V_126 -> V_156 , L_76 ,
V_568 , ( unsigned ) V_195 , V_16 -> V_86 ,
V_567 , ( V_402 & V_18 -> V_147 ) ? L_77 : L_78 ) ;
}
static int F_230 ( struct V_125 * V_126 ,
const struct V_570 * V_571 )
{
unsigned int V_495 = ( unsigned int ) V_571 -> V_572 ;
const struct F_111 * V_547 [] = { & V_548 [ V_495 ] , NULL } ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_86 , V_3 , V_432 ;
F_194 ( & V_126 -> V_156 , V_551 ) ;
V_86 = F_12 ( V_547 [ 0 ] -> V_83 ) * V_87 ;
V_16 = F_200 ( & V_126 -> V_156 , V_547 , V_86 ) ;
V_18 = F_60 ( & V_126 -> V_156 , sizeof( * V_18 ) , V_200 ) ;
if ( ! V_16 || ! V_18 )
return - V_201 ;
V_16 -> V_19 = V_18 ;
V_18 -> V_86 = V_86 ;
V_18 -> V_495 = V_495 ;
V_432 = F_231 ( V_126 ) ;
if ( V_432 )
return V_432 ;
V_432 = F_232 ( V_126 , 1 << V_573 , V_332 ) ;
if ( V_432 == - V_574 )
F_233 ( V_126 ) ;
if ( V_432 )
return V_432 ;
V_16 -> V_559 = F_234 ( V_126 ) ;
V_18 -> V_6 = V_16 -> V_559 [ V_573 ] ;
V_432 = F_224 ( V_126 ) ;
if ( V_432 )
return V_432 ;
V_432 = F_188 ( V_18 , & V_126 -> V_156 ) ;
if ( V_432 )
return V_432 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ ) {
struct V_20 * V_21 = V_16 -> V_178 [ V_3 ] ;
void T_1 * V_25 = F_8 ( V_18 -> V_6 , V_3 ) ;
unsigned int V_213 = V_25 - V_18 -> V_6 ;
F_235 ( V_21 , V_573 , - 1 , L_79 ) ;
F_235 ( V_21 , V_573 , V_213 , L_80 ) ;
}
V_432 = F_187 ( V_16 ) ;
if ( V_432 )
return V_432 ;
if ( V_575 && F_236 ( V_126 ) == 0 )
V_18 -> V_147 |= V_402 ;
F_37 ( V_126 , 0x68 ) ;
F_228 ( V_16 ) ;
F_237 ( V_126 ) ;
F_238 ( V_126 ) ;
return F_213 ( V_16 , V_126 -> V_399 , F_134 , V_562 ,
F_25 ( V_18 ) ? & V_576 : & V_563 ) ;
}
static int F_239 ( struct V_125 * V_126 )
{
struct V_15 * V_16 = F_240 ( V_126 ) ;
int V_432 ;
V_432 = F_241 ( V_126 ) ;
if ( V_432 )
return V_432 ;
V_432 = F_187 ( V_16 ) ;
if ( V_432 )
return V_432 ;
F_223 ( V_16 ) ;
return 0 ;
}
static int T_9 F_242 ( void )
{
int V_432 = - V_577 ;
#ifdef F_243
V_432 = F_244 ( & V_578 ) ;
if ( V_432 < 0 )
return V_432 ;
#endif
V_432 = F_245 ( & V_579 ) ;
#ifdef F_243
if ( V_432 < 0 )
F_246 ( & V_578 ) ;
#endif
return V_432 ;
}
static void T_10 F_247 ( void )
{
#ifdef F_243
F_246 ( & V_578 ) ;
#endif
F_248 ( & V_579 ) ;
}
