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
if ( V_136 == V_138 ) {
if ( ( V_145 & 0xf ) == 1 || ( F_3 ( V_2 ) & 0xf ) == 1 )
V_145 |= 0xf000 ;
}
F_1 ( V_145 , V_2 ) ;
return 0 ;
} else
return - V_146 ;
}
static void F_44 ( struct V_147 * V_148 )
{
if ( V_148 -> V_83 & V_149 ) {
if ( F_45 ( V_148 -> V_144 -> V_21 ) ) {
V_148 -> V_83 &= ~ V_149 ;
F_46 ( V_148 ,
L_12 ) ;
}
}
}
static int F_47 ( struct V_150 * V_151 )
{
struct V_143 * V_144 = V_151 -> V_152 -> V_144 ;
struct V_20 * V_21 = V_144 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
if ( V_27 -> V_103 & V_153 )
return V_154 ;
if ( F_48 ( V_21 -> V_155 ) ) {
if ( V_144 == V_21 -> V_155 ) {
if ( V_21 -> V_156 )
return V_154 ;
V_151 -> V_83 |= V_157 ;
return 0 ;
} else
return V_154 ;
}
if ( V_21 -> V_156 == 0 )
return 0 ;
if ( ( V_27 -> V_103 & V_104 ) &&
( V_27 -> V_103 & V_106 ) ) {
if ( F_49 ( V_151 -> V_158 . V_100 ) )
return 0 ;
else {
V_21 -> V_155 = V_144 ;
return V_154 ;
}
}
return V_154 ;
}
static void F_50 ( struct V_20 * V_21 , int V_101 , int V_159 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
void T_1 * V_25 ;
T_2 V_29 , * V_160 = & V_27 -> V_28 . V_29 ;
T_2 V_31 , * V_161 = & V_27 -> V_28 . V_31 ;
T_2 V_33 , * V_162 = & V_27 -> V_28 . V_33 ;
V_31 = * V_161 & ~ V_163 ;
V_33 = * V_162 | V_164 ;
if ( V_159 ) {
V_29 = * V_160 | V_165 ;
V_31 = * V_161 | V_163 ;
if ( V_101 )
V_33 &= ~ V_164 ;
else
V_29 |= V_166 ;
} else {
V_29 = * V_160 & ~ ( V_165 | V_166 ) ;
}
V_25 = F_11 ( V_21 ) ;
F_14 ( V_25 + V_30 , V_160 , V_29 ) ;
F_14 ( V_25 + V_32 , V_161 , V_31 ) ;
F_14 ( V_25 + V_34 , V_162 , V_33 ) ;
}
static void F_51 ( struct V_20 * V_21 , int V_101 )
{
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
T_2 V_37 , V_38 ;
V_37 = F_3 ( V_18 -> V_6 + V_167 ) ;
if ( V_101 )
V_38 = V_37 | ( 1 << 22 ) ;
else
V_38 = V_37 & ~ ( 1 << 22 ) ;
if ( V_38 != V_37 )
F_2 ( V_38 , V_18 -> V_6 + V_167 ) ;
}
static void F_52 ( struct V_20 * V_21 , int V_168 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
T_2 V_38 , * V_37 = & V_27 -> V_28 . V_35 ;
if ( V_168 )
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
T_2 V_169 ;
if ( V_18 -> V_170 & V_171 )
return;
V_18 -> V_170 |= V_171 ;
V_13 = F_7 ( F_10 ( V_16 ) , V_21 -> V_22 ) ;
V_169 = F_3 ( V_13 + V_172 ) ;
F_2 ( V_169 | V_173 , V_13 + V_172 ) ;
}
static void F_54 ( struct V_20 * V_21 )
{
struct V_15 * V_16 = V_21 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_13 ;
T_2 V_169 ;
unsigned int V_3 ;
if ( ! ( V_18 -> V_170 & V_171 ) )
return;
for ( V_3 = 0 ; V_3 < V_18 -> V_86 ; V_3 ++ ) {
struct V_20 * V_174 = V_16 -> V_175 [ V_3 ] ;
struct V_26 * V_27 = V_174 -> V_19 ;
if ( V_27 -> V_103 & V_106 )
return;
}
V_18 -> V_170 &= ~ V_171 ;
V_13 = F_7 ( F_10 ( V_16 ) , V_21 -> V_22 ) ;
V_169 = F_3 ( V_13 + V_172 ) ;
F_2 ( V_169 & ~ V_173 , V_13 + V_172 ) ;
}
static void F_29 ( struct V_20 * V_21 , int V_101 , int V_176 )
{
T_2 V_177 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
V_177 = V_178 ;
V_27 -> V_103 &=
~ ( V_179 | V_106 | V_180 ) ;
if ( F_25 ( V_18 ) )
V_177 |= ( 1 << 8 ) ;
else if ( F_55 ( V_18 ) ) {
V_177 |= V_181 | V_182 ;
F_51 ( V_21 , V_101 ) ;
} else if ( F_22 ( V_18 ) ) {
int V_159 = F_45 ( V_21 ) ;
V_159 &= V_101 ;
F_50 ( V_21 , V_101 , V_159 ) ;
if ( V_159 ) {
V_27 -> V_103 |= V_179 ;
V_177 |= V_183 ;
}
V_177 |= ( 1 << 23 ) ;
if ( V_176 ) {
V_177 |= ( 1 << 22 ) ;
if ( ! F_56 ( V_18 ) )
V_177 |= ( 1 << 18 ) ;
}
if ( V_18 -> V_170 & V_184 )
V_177 |= ( 1 << 17 ) ;
F_52 ( V_21 , ! V_176 ) ;
if ( F_56 ( V_18 ) ) {
if ( V_101 )
F_53 ( V_21 ) ;
else
F_54 ( V_21 ) ;
}
}
if ( V_101 ) {
V_177 |= V_185 ;
V_27 -> V_103 |= V_106 ;
}
F_1 ( V_177 , V_25 + V_186 ) ;
}
static void F_57 ( struct V_20 * V_21 )
{
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
struct V_26 * V_27 = V_21 -> V_19 ;
int V_187 ;
if ( V_27 -> V_188 ) {
F_58 ( V_18 -> V_189 , V_27 -> V_188 , V_27 -> V_44 ) ;
V_27 -> V_188 = NULL ;
}
if ( V_27 -> V_190 ) {
F_58 ( V_18 -> V_191 , V_27 -> V_190 , V_27 -> V_51 ) ;
V_27 -> V_190 = NULL ;
}
for ( V_187 = 0 ; V_187 < V_192 ; ++ V_187 ) {
if ( V_27 -> V_193 [ V_187 ] ) {
if ( V_187 == 0 || ! F_25 ( V_18 ) )
F_58 ( V_18 -> V_194 ,
V_27 -> V_193 [ V_187 ] ,
V_27 -> V_195 [ V_187 ] ) ;
V_27 -> V_193 [ V_187 ] = NULL ;
}
}
}
static int F_59 ( struct V_20 * V_21 )
{
struct V_196 * V_152 = V_21 -> V_16 -> V_152 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
struct V_26 * V_27 ;
unsigned long V_83 ;
int V_187 ;
V_27 = F_60 ( V_152 , sizeof( * V_27 ) , V_197 ) ;
if ( ! V_27 )
return - V_198 ;
V_21 -> V_19 = V_27 ;
V_27 -> V_188 = F_61 ( V_18 -> V_189 , V_197 , & V_27 -> V_44 ) ;
if ( ! V_27 -> V_188 )
return - V_198 ;
memset ( V_27 -> V_188 , 0 , V_199 ) ;
V_27 -> V_190 = F_61 ( V_18 -> V_191 , V_197 , & V_27 -> V_51 ) ;
if ( ! V_27 -> V_190 )
goto V_200;
memset ( V_27 -> V_190 , 0 , V_201 ) ;
if ( V_18 -> V_170 & V_202 )
V_21 -> V_83 |= V_203 ;
for ( V_187 = 0 ; V_187 < V_192 ; ++ V_187 ) {
if ( V_187 == 0 || ! F_25 ( V_18 ) ) {
V_27 -> V_193 [ V_187 ] = F_61 ( V_18 -> V_194 ,
V_197 , & V_27 -> V_195 [ V_187 ] ) ;
if ( ! V_27 -> V_193 [ V_187 ] )
goto V_200;
} else {
V_27 -> V_193 [ V_187 ] = V_27 -> V_193 [ 0 ] ;
V_27 -> V_195 [ V_187 ] = V_27 -> V_195 [ 0 ] ;
}
}
F_24 ( V_21 -> V_92 , V_83 ) ;
F_13 ( V_21 ) ;
F_29 ( V_21 , 0 , 0 ) ;
F_26 ( V_21 -> V_92 , V_83 ) ;
return 0 ;
V_200:
F_57 ( V_21 ) ;
return - V_198 ;
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
static void F_63 ( struct V_150 * V_151 )
{
struct V_26 * V_27 = V_151 -> V_21 -> V_19 ;
struct V_204 * V_205 ;
struct V_206 * V_206 , * V_207 = NULL ;
unsigned int V_208 ;
V_206 = V_27 -> V_193 [ V_151 -> V_187 ] ;
F_64 (qc->sg, sg, qc->n_elem, si) {
T_4 V_2 = F_65 ( V_205 ) ;
T_2 V_209 = F_66 ( V_205 ) ;
while ( V_209 ) {
T_2 V_210 = V_2 & 0xffff ;
T_2 V_211 = V_209 ;
if ( V_210 + V_211 > 0x10000 )
V_211 = 0x10000 - V_210 ;
V_206 -> V_2 = F_67 ( V_2 & 0xffffffff ) ;
V_206 -> V_212 = F_67 ( ( V_2 >> 16 ) >> 16 ) ;
V_206 -> V_213 = F_67 ( V_211 & 0xffff ) ;
V_206 -> V_214 = 0 ;
V_209 -= V_211 ;
V_2 += V_211 ;
V_207 = V_206 ;
V_206 ++ ;
}
}
if ( F_68 ( V_207 ) )
V_207 -> V_213 |= F_67 ( V_215 ) ;
F_69 () ;
}
static void F_70 ( T_5 * V_216 , T_3 V_1 , T_3 V_2 , unsigned V_217 )
{
T_6 V_218 = V_1 | ( V_2 << V_219 ) | V_220 |
( V_217 ? V_221 : 0 ) ;
* V_216 = F_71 ( V_218 ) ;
}
static void F_72 ( struct V_20 * V_21 )
{
F_21 ( V_21 , F_11 ( V_21 ) , V_72 ) ;
}
static int F_73 ( struct V_150 * V_151 )
{
struct V_222 * V_223 = V_151 -> V_224 ;
if ( V_223 ) {
switch ( V_223 -> V_225 [ 0 ] ) {
case V_226 :
case V_227 :
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
return 0 ;
}
}
return - V_235 ;
}
static void F_74 ( struct V_150 * V_151 )
{
struct V_20 * V_21 = V_151 -> V_21 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
F_63 ( V_151 ) ;
F_2 ( 0 , V_25 + V_236 ) ;
F_2 ( ( V_27 -> V_195 [ V_151 -> V_187 ] >> 16 ) >> 16 ,
V_25 + V_237 ) ;
F_1 ( V_27 -> V_195 [ V_151 -> V_187 ] ,
V_25 + V_238 ) ;
V_21 -> V_239 -> V_240 ( V_21 , & V_151 -> V_158 ) ;
}
static void F_75 ( struct V_150 * V_151 )
{
struct V_20 * V_21 = V_151 -> V_21 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
unsigned int V_241 = ( V_151 -> V_158 . V_83 & V_242 ) ;
T_2 V_243 = ( V_241 ? 0 : V_244 ) | V_245 ;
F_1 ( V_243 , V_25 + V_236 ) ;
}
static void F_76 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_243 ;
V_243 = F_3 ( V_25 + V_236 ) ;
if ( V_243 & V_245 ) {
V_243 &= ~ V_245 ;
F_1 ( V_243 , V_25 + V_236 ) ;
F_77 ( V_21 ) ;
}
}
static void F_78 ( struct V_150 * V_151 )
{
F_76 ( V_151 -> V_21 ) ;
}
static T_3 F_79 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_118 , V_246 ;
V_118 = F_3 ( V_25 + V_247 ) ;
if ( V_118 & V_248 )
V_246 = V_248 ;
else if ( V_118 & V_249 )
V_246 = ( V_118 & V_249 ) | V_250 ;
else {
F_76 ( V_21 ) ;
if ( F_80 ( V_21 -> V_251 . V_252 ) & V_253 )
V_246 = 0 ;
else
V_246 = V_250 ;
}
return V_246 ;
}
static void F_81 ( struct V_150 * V_151 )
{
struct V_254 * V_158 = & V_151 -> V_158 ;
if ( ( V_158 -> V_83 & V_242 ) && F_82 ( V_158 ) ) {
if ( V_151 -> V_152 -> V_255 > 7 ) {
switch ( V_158 -> V_256 ) {
case V_257 :
V_158 -> V_256 = V_258 ;
break;
case V_259 :
V_158 -> V_83 &= ~ V_260 ;
case V_261 :
V_158 -> V_256 = V_262 ;
break;
}
}
}
}
static void F_83 ( struct V_150 * V_151 )
{
struct V_20 * V_21 = V_151 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
T_5 * V_263 ;
struct V_254 * V_158 = & V_151 -> V_158 ;
T_6 V_83 = 0 ;
unsigned V_264 ;
switch ( V_158 -> V_100 ) {
case V_265 :
if ( V_158 -> V_256 == V_266 )
return;
case V_102 :
break;
case V_267 :
F_81 ( V_151 ) ;
return;
default:
return;
}
if ( ! ( V_158 -> V_83 & V_242 ) )
V_83 |= V_268 ;
F_16 ( V_192 <= V_151 -> V_187 ) ;
V_83 |= V_151 -> V_187 << V_269 ;
V_83 |= ( V_151 -> V_152 -> V_144 -> V_270 & 0xf ) << V_271 ;
V_264 = V_27 -> V_41 ;
V_27 -> V_188 [ V_264 ] . V_272 =
F_67 ( V_27 -> V_195 [ V_151 -> V_187 ] & 0xffffffff ) ;
V_27 -> V_188 [ V_264 ] . V_273 =
F_67 ( ( V_27 -> V_195 [ V_151 -> V_187 ] >> 16 ) >> 16 ) ;
V_27 -> V_188 [ V_264 ] . V_274 = F_71 ( V_83 ) ;
V_263 = & V_27 -> V_188 [ V_264 ] . V_275 [ 0 ] ;
switch ( V_158 -> V_256 ) {
case V_276 :
case V_277 :
case V_278 :
case V_279 :
case V_280 :
F_70 ( V_263 ++ , V_158 -> V_281 , V_282 , 0 ) ;
break;
case V_283 :
case V_284 :
F_70 ( V_263 ++ , V_158 -> V_285 , V_286 , 0 ) ;
F_70 ( V_263 ++ , V_158 -> V_287 , V_286 , 0 ) ;
break;
default:
F_84 ( V_158 -> V_256 ) ;
break;
}
F_70 ( V_263 ++ , V_158 -> V_288 , V_282 , 0 ) ;
F_70 ( V_263 ++ , V_158 -> V_289 , V_290 , 0 ) ;
F_70 ( V_263 ++ , V_158 -> V_291 , V_290 , 0 ) ;
F_70 ( V_263 ++ , V_158 -> V_292 , V_293 , 0 ) ;
F_70 ( V_263 ++ , V_158 -> V_294 , V_293 , 0 ) ;
F_70 ( V_263 ++ , V_158 -> V_295 , V_296 , 0 ) ;
F_70 ( V_263 ++ , V_158 -> V_297 , V_296 , 0 ) ;
F_70 ( V_263 ++ , V_158 -> V_196 , V_298 , 0 ) ;
F_70 ( V_263 ++ , V_158 -> V_256 , V_299 , 1 ) ;
if ( ! ( V_151 -> V_83 & V_300 ) )
return;
F_63 ( V_151 ) ;
}
static void F_85 ( struct V_150 * V_151 )
{
struct V_20 * V_21 = V_151 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_301 * V_188 ;
struct V_254 * V_158 = & V_151 -> V_158 ;
unsigned V_264 ;
T_2 V_83 = 0 ;
if ( ( V_158 -> V_100 != V_265 ) &&
( V_158 -> V_100 != V_102 ) )
return;
if ( V_158 -> V_256 == V_266 )
return;
if ( ! ( V_158 -> V_83 & V_242 ) )
V_83 |= V_268 ;
F_16 ( V_192 <= V_151 -> V_187 ) ;
V_83 |= V_151 -> V_187 << V_269 ;
V_83 |= V_151 -> V_187 << V_302 ;
V_83 |= ( V_151 -> V_152 -> V_144 -> V_270 & 0xf ) << V_271 ;
V_264 = V_27 -> V_41 ;
V_188 = (struct V_301 * ) & V_27 -> V_188 [ V_264 ] ;
V_188 -> V_2 = F_67 ( V_27 -> V_195 [ V_151 -> V_187 ] & 0xffffffff ) ;
V_188 -> V_212 = F_67 ( ( V_27 -> V_195 [ V_151 -> V_187 ] >> 16 ) >> 16 ) ;
V_188 -> V_83 = F_67 ( V_83 ) ;
V_188 -> V_275 [ 0 ] = F_67 (
( V_158 -> V_256 << 16 ) |
( V_158 -> V_287 << 24 )
) ;
V_188 -> V_275 [ 1 ] = F_67 (
( V_158 -> V_291 << 0 ) |
( V_158 -> V_294 << 8 ) |
( V_158 -> V_297 << 16 ) |
( V_158 -> V_196 << 24 )
) ;
V_188 -> V_275 [ 2 ] = F_67 (
( V_158 -> V_289 << 0 ) |
( V_158 -> V_292 << 8 ) |
( V_158 -> V_295 << 16 ) |
( V_158 -> V_285 << 24 )
) ;
V_188 -> V_275 [ 3 ] = F_67 (
( V_158 -> V_288 << 0 ) |
( V_158 -> V_281 << 8 )
) ;
if ( ! ( V_151 -> V_83 & V_300 ) )
return;
F_63 ( V_151 ) ;
}
static T_3 F_86 ( struct V_20 * V_21 )
{
T_3 V_303 = F_80 ( V_21 -> V_251 . V_304 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
if ( V_27 -> V_103 & V_180 ) {
if ( V_303 & ( V_253 | V_305 | V_306 ) )
V_27 -> V_103 &= ~ V_180 ;
else
V_303 = V_253 ;
}
return V_303 ;
}
static unsigned int F_87 ( struct V_20 * V_21 , T_2 * V_307 , int V_308 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_309 , V_310 , V_311 ;
int V_114 , V_113 = 200 , V_312 = V_308 - 1 ;
V_310 = F_3 ( V_25 + V_313 ) ;
V_309 = 0x100 | ( V_310 & 0xf ) ;
F_1 ( V_309 , V_25 + V_313 ) ;
for ( V_114 = 0 ; V_114 < V_312 ; ++ V_114 )
F_2 ( V_307 [ V_114 ] , V_25 + V_314 ) ;
F_1 ( V_309 | 0x200 , V_25 + V_313 ) ;
F_1 ( V_307 [ V_312 ] , V_25 + V_314 ) ;
do {
V_311 = F_3 ( V_25 + V_315 ) ;
} while ( ! ( V_311 & 0x1000 ) && -- V_113 );
F_1 ( V_310 , V_25 + V_313 ) ;
if ( ( V_311 & 0x3000 ) != 0x1000 ) {
F_88 ( V_21 , L_13 ,
V_316 , V_311 ) ;
return V_317 ;
}
return 0 ;
}
static unsigned int F_89 ( struct V_150 * V_151 )
{
struct V_20 * V_21 = V_151 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_143 * V_144 = V_151 -> V_152 -> V_144 ;
T_2 V_307 [ 5 ] ;
int V_120 = 0 ;
F_90 ( & V_151 -> V_158 , V_144 -> V_270 , 1 , ( void * ) V_307 ) ;
V_120 = F_87 ( V_21 , V_307 , F_91 ( V_307 ) ) ;
if ( V_120 )
return V_120 ;
switch ( V_151 -> V_158 . V_100 ) {
case V_318 :
V_27 -> V_103 |= V_180 ;
case V_319 :
V_21 -> V_320 = V_321 ;
break;
case V_267 :
V_27 -> V_103 |= V_180 ;
if ( V_151 -> V_158 . V_83 & V_242 )
V_21 -> V_320 = V_321 ;
else
V_21 -> V_320 = V_322 ;
break;
default:
V_21 -> V_320 = V_323 ;
break;
}
if ( V_151 -> V_158 . V_83 & V_324 )
F_92 ( V_144 , 0 ) ;
return 0 ;
}
static unsigned int F_93 ( struct V_150 * V_151 )
{
static int V_325 = 10 ;
struct V_20 * V_21 = V_151 -> V_21 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
T_2 V_264 ;
unsigned int V_73 ;
V_27 -> V_103 &= ~ V_180 ;
switch ( V_151 -> V_158 . V_100 ) {
case V_265 :
if ( V_151 -> V_158 . V_256 == V_266 ) {
if ( ! V_21 -> V_239 -> V_326 )
return V_317 ;
break;
}
case V_102 :
F_27 ( V_21 , V_25 , V_27 , V_151 -> V_158 . V_100 ) ;
V_27 -> V_41 = ( V_27 -> V_41 + 1 ) & V_42 ;
V_264 = V_27 -> V_41 << V_43 ;
F_1 ( ( V_27 -> V_44 & V_46 ) | V_264 ,
V_25 + V_47 ) ;
return 0 ;
case V_267 :
if ( V_325 > 0 && ( V_151 -> V_327 / V_151 -> V_328 ) > 1 ) {
-- V_325 ;
F_94 ( V_151 -> V_152 -> V_144 , V_329
L_14
L_15 ) ;
}
case V_330 :
case V_318 :
case V_319 :
if ( V_21 -> V_83 & V_331 )
V_151 -> V_158 . V_83 |= V_324 ;
break;
}
if ( V_151 -> V_158 . V_83 & V_324 )
V_73 = V_72 ;
else
V_73 = V_72 | V_71 ;
F_28 ( V_21 ) ;
F_21 ( V_21 , F_11 ( V_21 ) , V_73 ) ;
F_95 ( V_21 , V_151 -> V_152 -> V_144 -> V_270 ) ;
if ( V_151 -> V_158 . V_256 == V_332 ) {
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
if ( F_55 ( V_18 ) )
return F_89 ( V_151 ) ;
}
return F_96 ( V_151 ) ;
}
static struct V_150 * F_97 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_150 * V_151 ;
if ( V_27 -> V_103 & V_106 )
return NULL ;
V_151 = F_98 ( V_21 , V_21 -> V_144 . V_333 ) ;
if ( V_151 && ! ( V_151 -> V_158 . V_83 & V_324 ) )
return V_151 ;
return NULL ;
}
static void F_99 ( struct V_20 * V_21 )
{
unsigned int V_270 , V_334 ;
struct V_26 * V_27 = V_21 -> V_19 ;
if ( V_27 -> V_103 & V_153 ) {
V_334 = V_27 -> V_335 ;
V_27 -> V_103 &= ~ V_153 ;
for ( V_270 = 0 ; V_334 != 0 ; V_270 ++ ) {
unsigned int V_336 = ( 1 << V_270 ) ;
if ( V_334 & V_336 ) {
struct V_143 * V_144 = & V_21 -> V_337 [ V_270 ] ;
V_334 &= ~ V_336 ;
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
return F_3 ( V_25 + V_338 ) >> 16 ;
}
static void F_104 ( struct V_20 * V_21 , unsigned int V_334 )
{
struct V_339 * V_340 ;
unsigned int V_270 ;
V_340 = & V_21 -> V_144 . V_341 ;
for ( V_270 = 0 ; V_334 != 0 ; V_270 ++ ) {
unsigned int V_336 = ( 1 << V_270 ) ;
if ( V_334 & V_336 ) {
struct V_143 * V_144 = & V_21 -> V_337 [ V_270 ] ;
V_334 &= ~ V_336 ;
V_340 = & V_144 -> V_341 ;
F_105 ( V_340 ) ;
F_106 ( V_340 , L_16 ) ;
V_340 -> V_342 |= V_343 ;
V_340 -> V_344 |= V_345 ;
F_107 ( V_144 ) ;
}
}
}
static int F_108 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_346 , V_347 ;
V_346 = ( F_3 ( V_25 + V_47 )
>> V_43 ) & V_42 ;
V_347 = ( F_3 ( V_25 + V_48 )
>> V_43 ) & V_42 ;
return ( V_346 == V_347 ) ;
}
static int F_109 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
int V_348 ;
unsigned int V_349 , V_350 ;
if ( ! ( V_27 -> V_103 & V_153 ) ) {
V_27 -> V_103 |= V_153 ;
V_27 -> V_335 = 0 ;
}
V_349 = V_27 -> V_335 ;
V_350 = V_349 | F_103 ( V_21 ) ;
if ( V_349 != V_350 ) {
V_27 -> V_335 = V_350 ;
F_104 ( V_21 , V_350 & ~ V_349 ) ;
}
V_348 = F_110 ( V_350 ) ;
F_111 ( V_21 ,
L_17 ,
V_316 , V_27 -> V_335 ,
V_21 -> V_351 , V_348 ,
V_21 -> V_156 ) ;
if ( V_21 -> V_156 <= V_348 && F_108 ( V_21 ) ) {
F_112 ( V_21 , V_27 ) ;
F_28 ( V_21 ) ;
F_113 ( V_21 ) ;
F_111 ( V_21 , L_18 , V_316 ) ;
return 1 ;
}
F_111 ( V_21 , L_19 , V_316 ) ;
return 1 ;
}
static int F_114 ( struct V_20 * V_21 )
{
return 0 ;
}
static int F_115 ( struct V_20 * V_21 , T_2 V_352 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
if ( ! ( V_27 -> V_103 & V_104 ) )
return 0 ;
if ( ! ( V_27 -> V_103 & V_179 ) )
return 0 ;
if ( ! ( V_352 & V_164 ) )
return 0 ;
V_352 &= ~ V_353 ;
if ( V_352 & ~ ( V_164 | V_354 ) )
return 0 ;
if ( V_27 -> V_103 & V_106 ) {
if ( V_352 & V_354 ) {
F_88 ( V_21 , L_20 ,
V_316 , V_352 , V_27 -> V_103 ) ;
return 0 ;
}
return F_109 ( V_21 ) ;
} else {
if ( ! ( V_352 & V_354 ) ) {
F_88 ( V_21 , L_20 ,
V_316 , V_352 , V_27 -> V_103 ) ;
return 0 ;
}
return F_114 ( V_21 ) ;
}
return 0 ;
}
static void F_116 ( struct V_20 * V_21 , int V_355 )
{
struct V_339 * V_340 = & V_21 -> V_144 . V_341 ;
char * V_356 = L_21 ;
F_105 ( V_340 ) ;
if ( V_355 ) {
V_356 = L_22 ;
} else {
struct V_150 * V_151 = F_98 ( V_21 , V_21 -> V_144 . V_333 ) ;
if ( V_151 && ( V_151 -> V_158 . V_83 & V_324 ) )
V_356 = L_23 ;
}
F_106 ( V_340 , L_24 , V_356 ) ;
V_340 -> V_342 |= V_317 ;
V_340 -> V_344 |= V_345 ;
F_101 ( V_21 ) ;
}
static void F_117 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_352 , V_357 , V_358 = 0 ;
T_2 V_359 = 0 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
unsigned int V_344 = 0 , V_342 = 0 ;
struct V_339 * V_340 = & V_21 -> V_144 . V_341 ;
struct V_150 * V_151 ;
int abort = 0 ;
F_118 ( & V_21 -> V_144 , V_139 , & V_358 ) ;
F_119 ( & V_21 -> V_144 , V_139 , V_358 ) ;
V_352 = F_3 ( V_25 + V_75 ) ;
if ( F_22 ( V_18 ) && ( V_352 & V_360 ) ) {
V_359 = F_3 ( V_25 + V_79 ) ;
F_1 ( ~ V_359 , V_25 + V_79 ) ;
}
F_1 ( ~ V_352 , V_25 + V_75 ) ;
if ( V_352 & V_164 ) {
if ( F_115 ( V_21 , V_352 ) )
return;
}
V_151 = F_97 ( V_21 ) ;
F_105 ( V_340 ) ;
F_106 ( V_340 , L_25 ,
V_352 , V_27 -> V_103 ) ;
if ( F_22 ( V_18 ) && ( V_352 & V_360 ) ) {
F_106 ( V_340 , L_26 , V_359 ) ;
if ( V_359 & V_361 ) {
T_2 V_362 = V_352 &
~ ( V_360 | V_353 ) ;
F_120 ( V_21 ) ;
if ( ! V_362 )
return;
F_106 ( V_340 , L_27 ) ;
}
}
if ( V_352 & V_164 ) {
V_342 |= V_343 ;
V_344 |= V_345 ;
F_106 ( V_340 , L_28 ) ;
}
if ( V_352 & ( V_363 | V_364 |
V_365 | V_366 |
V_367 ) ) {
V_342 |= V_368 ;
V_344 |= V_345 ;
F_106 ( V_340 , L_29 ) ;
}
if ( V_352 & ( V_369 | V_370 ) ) {
F_121 ( V_340 ) ;
F_106 ( V_340 , V_352 & V_369 ?
L_30 : L_31 ) ;
V_344 |= V_345 ;
}
if ( F_25 ( V_18 ) ) {
V_357 = V_371 ;
if ( V_352 & V_372 ) {
V_27 -> V_103 &= ~ V_104 ;
F_106 ( V_340 , L_32 ) ;
}
} else {
V_357 = V_373 ;
if ( V_352 & V_354 ) {
V_27 -> V_103 &= ~ V_104 ;
F_106 ( V_340 , L_32 ) ;
}
if ( V_352 & V_374 ) {
F_106 ( V_340 , L_33 , V_358 ) ;
V_342 |= V_368 ;
V_344 |= V_345 ;
}
}
if ( ! V_342 ) {
V_342 = V_317 ;
V_344 |= V_345 ;
}
V_340 -> V_375 |= V_358 ;
V_340 -> V_344 |= V_344 ;
if ( V_151 )
V_151 -> V_342 |= V_342 ;
else
V_340 -> V_342 |= V_342 ;
if ( V_342 == V_343 ) {
F_113 ( V_21 ) ;
abort = 1 ;
} else if ( V_352 & V_357 ) {
F_101 ( V_21 ) ;
} else {
abort = 1 ;
}
if ( abort ) {
if ( V_151 )
F_107 ( V_151 -> V_152 -> V_144 ) ;
else
F_122 ( V_21 ) ;
}
}
static bool F_123 ( struct V_20 * V_21 ,
struct V_376 * V_377 , unsigned int V_187 , int V_378 )
{
T_3 V_379 ;
T_6 V_380 = F_124 ( V_377 -> V_83 ) ;
if ( ! V_378 ) {
T_3 V_381 = V_380 & 0xff & ~ V_164 ;
if ( V_381 ) {
return false ;
}
}
V_379 = V_380 >> V_382 ;
if ( ! F_125 ( V_379 ) )
return true ;
return false ;
}
static void F_112 ( struct V_20 * V_21 , struct V_26 * V_27 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
T_2 V_264 ;
bool V_383 = false ;
T_2 V_384 = 0 ;
int V_378 = ( V_27 -> V_103 & V_106 ) ;
V_264 = ( F_3 ( V_25 + V_53 )
>> V_50 ) & V_42 ;
while ( V_264 != V_27 -> V_49 ) {
unsigned int V_187 ;
struct V_376 * V_377 = & V_27 -> V_190 [ V_27 -> V_49 ] ;
V_27 -> V_49 = ( V_27 -> V_49 + 1 ) & V_42 ;
if ( F_25 ( V_18 ) ) {
V_187 = V_21 -> V_144 . V_333 ;
} else {
V_187 = F_124 ( V_377 -> V_385 ) & 0x1f ;
}
if ( F_123 ( V_21 , V_377 , V_187 , V_378 ) )
V_384 |= 1 << V_187 ;
V_383 = true ;
}
if ( V_383 ) {
F_126 ( V_21 , V_21 -> V_351 ^ V_384 ) ;
F_1 ( ( V_27 -> V_51 & V_54 ) |
( V_27 -> V_49 << V_50 ) ,
V_25 + V_55 ) ;
}
}
static void F_127 ( struct V_20 * V_21 , T_2 V_386 )
{
struct V_26 * V_27 ;
int V_355 ;
V_27 = V_21 -> V_19 ;
V_355 = ( V_27 -> V_103 & V_104 ) ;
if ( V_355 && ( V_386 & V_71 ) ) {
F_112 ( V_21 , V_27 ) ;
if ( V_27 -> V_103 & V_153 )
F_109 ( V_21 ) ;
}
if ( F_48 ( V_386 & V_72 ) ) {
F_117 ( V_21 ) ;
} else if ( ! V_355 ) {
struct V_150 * V_151 = F_97 ( V_21 ) ;
if ( V_151 )
F_128 ( V_21 , V_151 ) ;
else
F_116 ( V_21 , V_355 ) ;
}
}
static int F_129 ( struct V_15 * V_16 , T_2 V_387 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 , * V_13 ;
unsigned int V_388 = 0 , V_3 ;
if ( V_387 & V_57 )
F_2 ( ~ V_95 , V_12 + V_96 ) ;
for ( V_3 = 0 ; V_3 < V_18 -> V_86 ; V_3 ++ ) {
struct V_20 * V_21 = V_16 -> V_175 [ V_3 ] ;
unsigned int V_133 , V_69 , V_70 , V_386 ;
F_20 ( V_3 , V_69 , V_70 ) ;
if ( V_70 == 0 ) {
T_2 V_389 = ( V_387 >> V_69 ) & V_390 ;
T_2 V_391 , V_392 ;
if ( ! V_389 ) {
V_3 += V_87 - 1 ;
continue;
}
V_392 = 0 ;
if ( V_389 & V_58 )
V_392 = V_99 ;
for ( V_133 = 0 ; V_133 < V_87 ; ++ V_133 ) {
if ( ( V_3 + V_133 ) >= V_18 -> V_86 )
break;
V_391 = ( V_71 | V_72 ) << ( V_133 * 2 ) ;
if ( V_389 & V_391 )
V_392 |= ( V_77 | V_76 ) << V_133 ;
}
V_13 = F_7 ( V_12 , V_3 ) ;
F_1 ( ~ V_392 , V_13 + V_78 ) ;
V_388 = 1 ;
}
V_386 = ( V_387 >> V_69 ) & ( V_71 | V_72 ) ;
if ( V_386 )
F_127 ( V_21 , V_386 ) ;
}
return V_388 ;
}
static int F_130 ( struct V_15 * V_16 , void T_1 * V_12 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 ;
struct V_150 * V_151 ;
struct V_339 * V_340 ;
unsigned int V_114 , V_342 , V_393 = 0 ;
T_2 V_381 ;
V_381 = F_3 ( V_12 + V_18 -> V_394 ) ;
F_131 ( V_16 -> V_152 , L_34 , V_381 ) ;
F_35 ( L_35 ) ;
F_40 ( V_12 , - 1 , F_132 ( V_16 -> V_152 ) ) ;
F_1 ( 0 , V_12 + V_18 -> V_394 ) ;
for ( V_114 = 0 ; V_114 < V_16 -> V_86 ; V_114 ++ ) {
V_21 = V_16 -> V_175 [ V_114 ] ;
if ( ! F_133 ( & V_21 -> V_144 ) ) {
V_340 = & V_21 -> V_144 . V_341 ;
F_105 ( V_340 ) ;
if ( ! V_393 ++ )
F_106 ( V_340 ,
L_36 , V_381 ) ;
V_342 = V_395 ;
V_340 -> V_344 = V_345 ;
V_151 = F_98 ( V_21 , V_21 -> V_144 . V_333 ) ;
if ( V_151 )
V_151 -> V_342 |= V_342 ;
else
V_340 -> V_342 |= V_342 ;
F_101 ( V_21 ) ;
}
}
return 1 ;
}
static T_7 F_134 ( int V_396 , void * V_397 )
{
struct V_15 * V_16 = V_397 ;
struct V_17 * V_18 = V_16 -> V_19 ;
unsigned int V_388 = 0 ;
int V_398 = V_18 -> V_170 & V_399 ;
T_2 V_387 , V_400 ;
F_135 ( & V_16 -> V_92 ) ;
if ( V_398 )
F_17 ( 0 , V_18 ) ;
V_387 = F_3 ( V_18 -> V_401 ) ;
V_400 = V_387 & V_18 -> V_67 ;
if ( V_400 && V_387 != 0xffffffffU ) {
if ( F_48 ( ( V_400 & V_402 ) && ! F_56 ( V_18 ) ) )
V_388 = F_130 ( V_16 , V_18 -> V_6 ) ;
else
V_388 = F_129 ( V_16 , V_400 ) ;
}
if ( V_398 )
F_17 ( V_18 -> V_67 , V_18 ) ;
F_136 ( & V_16 -> V_92 ) ;
return F_137 ( V_388 ) ;
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
struct V_125 * V_126 = F_132 ( V_16 -> V_152 ) ;
int V_403 ;
V_403 = ( V_126 -> V_196 == 0x5080 ) && ( V_126 -> V_404 == 0 ) ;
if ( ! V_403 ) {
T_2 V_218 = F_3 ( V_12 + V_405 ) ;
V_218 |= ( 1 << 0 ) ;
F_2 ( V_218 , V_12 + V_405 ) ;
}
F_142 ( V_16 , V_12 ) ;
}
static void F_143 ( struct V_17 * V_18 , void T_1 * V_12 )
{
F_2 ( 0x0fcfffff , V_12 + V_406 ) ;
}
static void F_144 ( struct V_17 * V_18 , int V_407 ,
void T_1 * V_12 )
{
void T_1 * V_408 = F_9 ( V_12 , V_407 ) ;
T_2 V_218 ;
V_218 = F_3 ( V_408 + V_409 ) ;
V_18 -> signal [ V_407 ] . V_410 = V_218 & 0x1800 ;
V_18 -> signal [ V_407 ] . V_411 = V_218 & 0xe0 ;
}
static void F_145 ( struct V_17 * V_18 , void T_1 * V_12 )
{
T_2 V_218 ;
F_2 ( 0 , V_12 + V_167 ) ;
V_218 = F_3 ( V_12 + V_405 ) ;
V_218 |= ~ ( 1 << 0 ) ;
F_2 ( V_218 , V_12 + V_405 ) ;
}
static void F_146 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_3 )
{
void T_1 * V_408 = F_9 ( V_12 , V_3 ) ;
const T_2 V_56 = ( 1 << 12 ) | ( 1 << 11 ) | ( 1 << 7 ) | ( 1 << 6 ) | ( 1 << 5 ) ;
T_2 V_218 ;
int V_412 = ( V_18 -> V_170 & V_413 ) ;
if ( V_412 ) {
V_218 = F_3 ( V_408 + V_414 ) ;
V_218 |= ( 1 << 19 ) ;
F_2 ( V_218 , V_408 + V_414 ) ;
V_218 = F_3 ( V_408 + V_415 ) ;
V_218 &= ~ 0x3 ;
V_218 |= 0x1 ;
F_2 ( V_218 , V_408 + V_415 ) ;
}
V_218 = F_3 ( V_408 + V_409 ) ;
V_218 &= ~ V_56 ;
V_218 |= V_18 -> signal [ V_3 ] . V_410 ;
V_218 |= V_18 -> signal [ V_3 ] . V_411 ;
F_2 ( V_218 , V_408 + V_409 ) ;
}
static void F_147 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
F_148 ( V_18 , V_12 , V_3 ) ;
F_149 ( 0x028 ) ;
F_2 ( 0x11f , V_25 + V_186 ) ;
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
F_2 ( 0xbc , V_25 + V_416 ) ;
}
static void F_150 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_7 )
{
void T_1 * V_13 = F_6 ( V_12 , V_7 ) ;
T_2 V_218 ;
F_149 ( 0x00c ) ;
F_149 ( 0x010 ) ;
F_149 ( 0x014 ) ;
F_149 ( 0x018 ) ;
V_218 = F_3 ( V_13 + 0x20 ) ;
V_218 &= 0x1c1c1c1c ;
V_218 |= 0x03030303 ;
F_2 ( V_218 , V_13 + 0x20 ) ;
}
static int F_151 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_417 )
{
unsigned int V_7 , V_3 ;
for ( V_7 = 0 ; V_7 < V_417 ; V_7 ++ ) {
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
T_2 V_218 ;
V_218 = F_3 ( V_12 + V_418 ) ;
V_218 &= 0xff00ffff ;
F_2 ( V_218 , V_12 + V_418 ) ;
F_149 ( V_419 ) ;
F_149 ( V_420 ) ;
F_2 ( 0x000100ff , V_12 + V_421 ) ;
F_149 ( V_422 ) ;
F_149 ( V_18 -> V_394 ) ;
F_149 ( V_18 -> V_423 ) ;
F_149 ( V_424 ) ;
F_149 ( V_425 ) ;
F_149 ( V_426 ) ;
F_149 ( V_427 ) ;
}
static void F_152 ( struct V_17 * V_18 , void T_1 * V_12 )
{
T_2 V_218 ;
F_143 ( V_18 , V_12 ) ;
V_218 = F_3 ( V_12 + V_167 ) ;
V_218 &= 0x3 ;
V_218 |= ( 1 << 5 ) | ( 1 << 6 ) ;
F_2 ( V_218 , V_12 + V_167 ) ;
}
static int F_153 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_417 )
{
void T_1 * V_118 = V_12 + V_428 ;
int V_114 , V_429 = 0 ;
T_2 V_430 ;
V_430 = F_3 ( V_118 ) ;
F_2 ( V_430 | V_431 , V_118 ) ;
for ( V_114 = 0 ; V_114 < 1000 ; V_114 ++ ) {
F_31 ( 1 ) ;
V_430 = F_3 ( V_118 ) ;
if ( V_432 & V_430 )
break;
}
if ( ! ( V_432 & V_430 ) ) {
F_36 (KERN_ERR DRV_NAME L_37 ) ;
V_429 = 1 ;
goto V_433;
}
V_114 = 5 ;
do {
F_2 ( V_430 | V_434 , V_118 ) ;
V_430 = F_3 ( V_118 ) ;
F_31 ( 1 ) ;
} while ( ! ( V_434 & V_430 ) && ( V_114 -- > 0 ) );
if ( ! ( V_434 & V_430 ) ) {
F_36 (KERN_ERR DRV_NAME L_38 ) ;
V_429 = 1 ;
goto V_433;
}
V_114 = 5 ;
do {
F_2 ( V_430 & ~ ( V_434 | V_431 ) , V_118 ) ;
V_430 = F_3 ( V_118 ) ;
F_31 ( 1 ) ;
} while ( ( V_434 & V_430 ) && ( V_114 -- > 0 ) );
if ( V_434 & V_430 ) {
F_36 (KERN_ERR DRV_NAME L_39 ) ;
V_429 = 1 ;
}
V_433:
return V_429 ;
}
static void F_154 ( struct V_17 * V_18 , int V_407 ,
void T_1 * V_12 )
{
void T_1 * V_25 ;
T_2 V_218 ;
V_218 = F_3 ( V_12 + V_435 ) ;
if ( ( V_218 & ( 1 << 0 ) ) == 0 ) {
V_18 -> signal [ V_407 ] . V_411 = 0x7 << 8 ;
V_18 -> signal [ V_407 ] . V_410 = 0x1 << 5 ;
return;
}
V_25 = F_8 ( V_12 , V_407 ) ;
V_218 = F_3 ( V_25 + V_436 ) ;
V_18 -> signal [ V_407 ] . V_411 = V_218 & 0x700 ;
V_18 -> signal [ V_407 ] . V_410 = V_218 & 0xe0 ;
}
static void F_155 ( struct V_17 * V_18 , void T_1 * V_12 )
{
F_2 ( 0x00000060 , V_12 + V_167 ) ;
}
static void F_156 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
T_2 V_170 = V_18 -> V_170 ;
int V_437 =
V_170 & ( V_438 | V_202 ) ;
int V_439 =
V_170 & ( V_438 | V_202 ) ;
T_2 V_440 , V_441 ;
if ( V_437 ) {
V_440 = F_3 ( V_25 + V_436 ) ;
V_440 &= ~ ( 1 << 16 ) ;
V_440 |= ( 1 << 31 ) ;
F_2 ( V_440 , V_25 + V_436 ) ;
F_31 ( 200 ) ;
V_440 = F_3 ( V_25 + V_436 ) ;
V_440 &= ~ ( ( 1 << 16 ) | ( 1 << 31 ) ) ;
F_2 ( V_440 , V_25 + V_436 ) ;
F_31 ( 200 ) ;
}
V_441 = F_3 ( V_25 + V_442 ) ;
V_441 = ( V_441 & 0x1f ) | ( 0x5555601 << 5 ) ;
if ( F_56 ( V_18 ) )
V_441 &= ~ 0x1c ;
if ( V_439 ) {
T_2 V_443 = F_3 ( V_25 + V_444 ) ;
if ( F_22 ( V_18 ) )
V_443 = ( V_443 & ~ V_445 ) | V_446 ;
else
V_443 = ( V_443 & ~ V_447 ) | V_448 ;
F_2 ( V_443 , V_25 + V_444 ) ;
}
F_2 ( V_441 , V_25 + V_442 ) ;
V_440 = F_3 ( V_25 + V_436 ) ;
V_440 &= ~ V_449 ;
V_440 |= V_18 -> signal [ V_3 ] . V_411 ;
V_440 |= V_18 -> signal [ V_3 ] . V_410 ;
V_440 &= ~ ( 1 << 16 ) ;
if ( F_22 ( V_18 ) ) {
V_440 &= ~ 0xC30FF01F ;
V_440 |= 0x0000900F ;
}
F_2 ( V_440 , V_25 + V_436 ) ;
}
static void F_157 ( struct V_17 * V_18 ,
void T_1 * V_12 )
{
return;
}
static void F_158 ( struct V_17 * V_18 , int V_407 ,
void T_1 * V_12 )
{
void T_1 * V_25 ;
T_2 V_218 ;
V_25 = F_8 ( V_12 , V_407 ) ;
V_218 = F_3 ( V_25 + V_436 ) ;
V_18 -> signal [ V_407 ] . V_411 = V_218 & 0x700 ;
V_18 -> signal [ V_407 ] . V_410 = V_218 & 0xe0 ;
}
static void F_159 ( struct V_17 * V_18 ,
void T_1 * V_12 , unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
F_148 ( V_18 , V_12 , V_3 ) ;
F_149 ( 0x028 ) ;
F_2 ( 0x101f , V_25 + V_186 ) ;
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
F_2 ( 0x800 , V_25 + V_416 ) ;
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
void T_1 * V_12 , unsigned int V_417 )
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
V_118 = F_3 ( V_25 + V_442 ) ;
V_118 &= ~ ( 0x3 << 27 ) ;
V_118 |= ( 0x1 << 27 ) ;
V_118 &= ~ ( 0x3 << 29 ) ;
V_118 |= ( 0x1 << 29 ) ;
F_2 ( V_118 , V_25 + V_442 ) ;
V_118 = F_3 ( V_25 + V_444 ) ;
V_118 &= ~ 0x1 ;
V_118 |= ( 0x1 << 16 ) ;
F_2 ( V_118 , V_25 + V_444 ) ;
V_118 = F_3 ( V_25 + V_450 ) ;
V_118 &= ~ 0xf ;
V_118 |= 0x8 ;
V_118 &= ~ ( 0x1 << 14 ) ;
F_2 ( V_118 , V_25 + V_450 ) ;
V_118 = F_3 ( V_25 + V_451 ) ;
V_118 &= ~ 0xf ;
V_118 |= 0x8 ;
V_118 &= ~ ( 0x1 << 14 ) ;
F_2 ( V_118 , V_25 + V_451 ) ;
}
static bool F_165 ( struct V_17 * V_18 )
{
void T_1 * V_452 = F_8 ( V_18 -> V_6 , 0 ) ;
if ( F_3 ( V_452 + V_453 ) )
return true ;
return false ;
}
static void F_166 ( void T_1 * V_25 , int V_454 )
{
T_2 V_455 = F_3 ( V_25 + V_456 ) ;
V_455 = ( V_455 & 0xf7f ) | 0x9b1000 ;
if ( V_454 )
V_455 |= ( 1 << 7 ) ;
F_1 ( V_455 , V_25 + V_456 ) ;
}
static void F_148 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_22 )
{
void T_1 * V_25 = F_8 ( V_12 , V_22 ) ;
F_32 ( V_25 ) ;
F_1 ( V_457 , V_25 + V_108 ) ;
if ( ! F_25 ( V_18 ) ) {
F_166 ( V_25 , 1 ) ;
}
F_1 ( V_457 , V_25 + V_108 ) ;
F_31 ( 25 ) ;
F_1 ( 0 , V_25 + V_108 ) ;
V_18 -> V_239 -> V_458 ( V_18 , V_12 , V_22 ) ;
if ( F_25 ( V_18 ) )
F_167 ( 1 ) ;
}
static void F_95 ( struct V_20 * V_21 , int V_270 )
{
if ( F_168 ( V_21 ) ) {
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_118 = F_3 ( V_25 + V_313 ) ;
int V_37 = V_118 & 0xf ;
if ( V_37 != V_270 ) {
V_118 = ( V_118 & ~ 0xf ) | V_270 ;
F_1 ( V_118 , V_25 + V_313 ) ;
}
}
}
static int F_169 ( struct V_143 * V_144 , unsigned int * V_459 ,
unsigned long V_460 )
{
F_95 ( V_144 -> V_21 , F_170 ( V_144 ) ) ;
return F_171 ( V_144 , V_459 , V_460 ) ;
}
static int F_172 ( struct V_143 * V_144 , unsigned int * V_459 ,
unsigned long V_460 )
{
F_95 ( V_144 -> V_21 , F_170 ( V_144 ) ) ;
return F_173 ( V_144 , V_459 , V_460 ) ;
}
static int F_174 ( struct V_143 * V_144 , unsigned int * V_459 ,
unsigned long V_460 )
{
struct V_20 * V_21 = V_144 -> V_21 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
struct V_26 * V_27 = V_21 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
int V_429 , V_461 = 0 , V_462 = 0 ;
T_2 V_463 ;
bool V_464 ;
F_148 ( V_18 , V_12 , V_21 -> V_22 ) ;
V_27 -> V_103 &= ~ V_104 ;
V_27 -> V_103 &=
~ ( V_179 | V_106 | V_180 ) ;
do {
const unsigned long * V_465 =
F_175 ( & V_144 -> V_466 ) ;
V_429 = F_176 ( V_144 , V_465 , V_460 + V_462 ,
& V_464 , NULL ) ;
V_429 = V_464 ? - V_467 : V_429 ;
if ( V_429 )
return V_429 ;
F_118 ( V_144 , V_137 , & V_463 ) ;
if ( ! F_25 ( V_18 ) && ++ V_461 >= 5 && V_463 == 0x121 ) {
F_166 ( F_11 ( V_21 ) , 0 ) ;
if ( F_177 ( V_468 + V_469 , V_460 ) )
V_462 = V_469 ;
}
} while ( V_463 != 0x0 && V_463 != 0x113 && V_463 != 0x123 );
F_13 ( V_21 ) ;
F_29 ( V_21 , 0 , 0 ) ;
return V_429 ;
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
static void F_179 ( struct V_470 * V_3 , void T_1 * V_25 )
{
void T_1 * V_358 , * V_471 = V_25 + V_472 ;
V_3 -> V_473 = V_471 + ( sizeof( T_2 ) * V_474 ) ;
V_3 -> V_475 =
V_3 -> V_476 = V_471 + ( sizeof( T_2 ) * V_477 ) ;
V_3 -> V_478 = V_471 + ( sizeof( T_2 ) * V_282 ) ;
V_3 -> V_479 = V_471 + ( sizeof( T_2 ) * V_290 ) ;
V_3 -> V_480 = V_471 + ( sizeof( T_2 ) * V_293 ) ;
V_3 -> V_481 = V_471 + ( sizeof( T_2 ) * V_296 ) ;
V_3 -> V_482 = V_471 + ( sizeof( T_2 ) * V_298 ) ;
V_3 -> V_304 =
V_3 -> V_483 = V_471 + ( sizeof( T_2 ) * V_484 ) ;
V_3 -> V_252 = V_3 -> V_485 = V_471 + V_486 ;
V_358 = V_25 + F_41 ( V_139 ) ;
F_1 ( F_3 ( V_358 ) , V_358 ) ;
F_1 ( 0 , V_25 + V_75 ) ;
F_1 ( ~ V_353 , V_25 + V_487 ) ;
F_180 ( L_40 ,
F_3 ( V_25 + V_186 ) ,
F_3 ( V_25 + V_75 ) ,
F_3 ( V_25 + V_487 ) ) ;
}
static unsigned int F_181 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
T_2 V_118 ;
if ( F_56 ( V_18 ) || ! F_182 ( V_18 ) )
return 0 ;
V_118 = F_3 ( V_12 + V_418 ) ;
if ( ( V_118 & V_488 ) == 0 )
return 0 ;
return 1 ;
}
static int F_183 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
T_2 V_118 ;
if ( ! F_181 ( V_16 ) ) {
V_118 = F_3 ( V_12 + V_489 ) ;
if ( V_118 & V_490 )
return 0 ;
}
return 1 ;
}
static void F_184 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
if ( F_181 ( V_16 ) ) {
T_2 V_118 = F_3 ( V_12 + V_489 ) ;
F_1 ( V_118 & ~ V_491 , V_12 + V_489 ) ;
}
}
static int F_185 ( struct V_15 * V_16 , unsigned int V_492 )
{
struct V_125 * V_126 = F_132 ( V_16 -> V_152 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
T_2 V_170 = V_18 -> V_170 ;
switch ( V_492 ) {
case V_493 :
V_18 -> V_239 = & V_494 ;
V_170 |= V_495 ;
switch ( V_126 -> V_404 ) {
case 0x1 :
V_170 |= V_413 ;
break;
case 0x3 :
V_170 |= V_496 ;
break;
default:
F_186 ( & V_126 -> V_152 ,
L_41 ) ;
V_170 |= V_496 ;
break;
}
break;
case V_497 :
case V_498 :
V_18 -> V_239 = & V_494 ;
V_170 |= V_495 ;
switch ( V_126 -> V_404 ) {
case 0x0 :
V_170 |= V_413 ;
break;
case 0x3 :
V_170 |= V_496 ;
break;
default:
F_186 ( & V_126 -> V_152 ,
L_42 ) ;
V_170 |= V_496 ;
break;
}
break;
case V_499 :
case V_500 :
V_18 -> V_239 = & V_501 ;
V_170 |= V_502 ;
switch ( V_126 -> V_404 ) {
case 0x7 :
F_184 ( V_16 ) ;
V_170 |= V_438 ;
break;
case 0x9 :
V_170 |= V_202 ;
break;
default:
F_186 ( & V_126 -> V_152 ,
L_42 ) ;
V_170 |= V_438 ;
break;
}
break;
case V_503 :
V_170 |= V_504 | V_184 ;
if ( V_126 -> V_505 == V_506 &&
( V_126 -> V_196 == 0x2300 || V_126 -> V_196 == 0x2310 ) )
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
case V_507 :
V_18 -> V_239 = & V_501 ;
V_170 |= V_508 ;
if ( V_492 == V_507 && F_183 ( V_16 ) )
V_170 |= V_184 ;
switch ( V_126 -> V_404 ) {
case 0x2 :
V_170 |= V_202 ;
break;
default:
F_186 ( & V_126 -> V_152 ,
L_51 ) ;
V_170 |= V_202 ;
break;
}
break;
case V_509 :
if ( F_165 ( V_18 ) )
V_18 -> V_239 = & V_510 ;
else
V_18 -> V_239 = & V_511 ;
V_170 |= V_512 | V_508 |
V_202 ;
break;
default:
F_131 ( V_16 -> V_152 , L_52 , V_492 ) ;
return 1 ;
}
V_18 -> V_170 = V_170 ;
if ( V_170 & V_504 ) {
V_18 -> V_394 = V_513 ;
V_18 -> V_423 = V_514 ;
V_18 -> V_515 = V_516 ;
} else {
V_18 -> V_394 = V_517 ;
V_18 -> V_423 = V_518 ;
V_18 -> V_515 = V_519 ;
}
return 0 ;
}
static int F_187 ( struct V_15 * V_16 )
{
int V_429 = 0 , V_417 , V_3 , V_7 ;
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
V_429 = F_185 ( V_16 , V_18 -> V_492 ) ;
if ( V_429 )
goto V_433;
if ( F_56 ( V_18 ) ) {
V_18 -> V_401 = V_12 + V_520 ;
V_18 -> V_62 = V_12 + V_521 ;
} else {
V_18 -> V_401 = V_12 + V_522 ;
V_18 -> V_62 = V_12 + V_523 ;
}
V_18 -> V_67 = F_3 ( V_18 -> V_62 ) ;
F_18 ( V_16 , ~ 0 , 0 ) ;
V_417 = F_12 ( V_16 -> V_175 [ 0 ] -> V_83 ) ;
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ )
if ( V_18 -> V_239 -> V_524 )
V_18 -> V_239 -> V_524 ( V_18 , V_3 , V_12 ) ;
V_429 = V_18 -> V_239 -> V_525 ( V_18 , V_12 , V_417 ) ;
if ( V_429 )
goto V_433;
V_18 -> V_239 -> V_526 ( V_18 , V_12 ) ;
V_18 -> V_239 -> V_527 ( V_16 , V_12 ) ;
V_18 -> V_239 -> V_528 ( V_18 , V_12 ) ;
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ ) {
struct V_20 * V_21 = V_16 -> V_175 [ V_3 ] ;
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
F_179 ( & V_21 -> V_251 , V_25 ) ;
}
for ( V_7 = 0 ; V_7 < V_417 ; V_7 ++ ) {
void T_1 * V_13 = F_6 ( V_12 , V_7 ) ;
F_180 ( L_53
L_54 , V_7 ,
F_3 ( V_13 + V_529 ) ,
F_3 ( V_13 + V_78 ) ) ;
F_1 ( 0 , V_13 + V_78 ) ;
}
if ( ! F_56 ( V_18 ) ) {
F_1 ( 0 , V_12 + V_18 -> V_394 ) ;
F_1 ( V_18 -> V_515 , V_12 + V_18 -> V_423 ) ;
}
F_18 ( V_16 , 0 , V_402 ) ;
F_23 ( V_16 , V_530 ,
V_531 ) ;
V_433:
return V_429 ;
}
static int F_188 ( struct V_17 * V_18 , struct V_196 * V_152 )
{
V_18 -> V_189 = F_189 ( L_55 , V_152 , V_199 ,
V_199 , 0 ) ;
if ( ! V_18 -> V_189 )
return - V_198 ;
V_18 -> V_191 = F_189 ( L_56 , V_152 , V_201 ,
V_201 , 0 ) ;
if ( ! V_18 -> V_191 )
return - V_198 ;
V_18 -> V_194 = F_189 ( L_57 , V_152 , V_532 ,
V_532 , 0 ) ;
if ( ! V_18 -> V_194 )
return - V_198 ;
return 0 ;
}
static void F_190 ( struct V_17 * V_18 ,
const struct V_533 * V_534 )
{
int V_114 ;
for ( V_114 = 0 ; V_114 < 4 ; V_114 ++ ) {
F_2 ( 0 , V_18 -> V_6 + F_191 ( V_114 ) ) ;
F_2 ( 0 , V_18 -> V_6 + F_192 ( V_114 ) ) ;
}
for ( V_114 = 0 ; V_114 < V_534 -> V_535 ; V_114 ++ ) {
const struct V_536 * V_537 = V_534 -> V_537 + V_114 ;
F_2 ( ( ( V_537 -> V_538 - 1 ) & 0xffff0000 ) |
( V_537 -> V_539 << 8 ) |
( V_534 -> V_540 << 4 ) | 1 ,
V_18 -> V_6 + F_191 ( V_114 ) ) ;
F_2 ( V_537 -> V_6 , V_18 -> V_6 + F_192 ( V_114 ) ) ;
}
}
static int F_193 ( struct V_541 * V_126 )
{
const struct V_542 * V_543 ;
const struct V_533 * V_534 ;
const struct F_111 * V_544 [] =
{ & V_545 [ V_509 ] , NULL } ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_546 * V_547 ;
int V_86 = 0 , V_396 = 0 ;
int V_429 ;
#if F_194 ( V_548 )
int V_3 ;
#endif
F_195 ( & V_126 -> V_152 , V_549 ) ;
if ( F_48 ( V_126 -> V_550 != 2 ) ) {
F_131 ( & V_126 -> V_152 , L_58 ) ;
return - V_146 ;
}
V_547 = F_196 ( V_126 , V_551 , 0 ) ;
if ( V_547 == NULL )
return - V_146 ;
if ( V_126 -> V_152 . V_552 ) {
F_197 ( V_126 -> V_152 . V_552 , L_59 , & V_86 ) ;
V_396 = F_198 ( V_126 -> V_152 . V_552 , 0 ) ;
} else {
V_543 = V_126 -> V_152 . V_553 ;
V_86 = V_543 -> V_86 ;
V_396 = F_199 ( V_126 , 0 ) ;
}
V_16 = F_200 ( & V_126 -> V_152 , V_544 , V_86 ) ;
V_18 = F_60 ( & V_126 -> V_152 , sizeof( * V_18 ) , V_197 ) ;
if ( ! V_16 || ! V_18 )
return - V_198 ;
#if F_194 ( V_548 )
V_18 -> V_554 = F_60 ( & V_126 -> V_152 ,
sizeof( struct V_555 * ) * V_86 ,
V_197 ) ;
if ( ! V_18 -> V_554 )
return - V_198 ;
#endif
V_16 -> V_19 = V_18 ;
V_18 -> V_86 = V_86 ;
V_18 -> V_492 = V_509 ;
V_16 -> V_556 = NULL ;
V_18 -> V_6 = F_201 ( & V_126 -> V_152 , V_547 -> V_121 ,
F_202 ( V_547 ) ) ;
V_18 -> V_6 -= V_8 ;
#if F_194 ( V_548 )
V_18 -> V_555 = F_203 ( & V_126 -> V_152 , NULL ) ;
if ( F_204 ( V_18 -> V_555 ) )
F_205 ( & V_126 -> V_152 , L_60 ) ;
else
F_206 ( V_18 -> V_555 ) ;
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
char V_557 [ 16 ] ;
sprintf ( V_557 , L_61 , V_3 ) ;
V_18 -> V_554 [ V_3 ] = F_203 ( & V_126 -> V_152 , V_557 ) ;
if ( ! F_204 ( V_18 -> V_554 [ V_3 ] ) )
F_206 ( V_18 -> V_554 [ V_3 ] ) ;
}
#endif
V_534 = F_207 () ;
if ( V_534 )
F_190 ( V_18 , V_534 ) ;
V_429 = F_188 ( V_18 , & V_126 -> V_152 ) ;
if ( V_429 )
goto V_120;
V_429 = F_187 ( V_16 ) ;
if ( V_429 )
goto V_120;
F_208 ( & V_126 -> V_152 , L_62 ,
( unsigned ) V_192 , V_16 -> V_86 ) ;
V_429 = F_209 ( V_16 , V_396 , F_134 , V_558 , & V_559 ) ;
if ( ! V_429 )
return 0 ;
V_120:
#if F_194 ( V_548 )
if ( ! F_204 ( V_18 -> V_555 ) ) {
F_210 ( V_18 -> V_555 ) ;
F_211 ( V_18 -> V_555 ) ;
}
for ( V_3 = 0 ; V_3 < V_86 ; V_3 ++ ) {
if ( ! F_204 ( V_18 -> V_554 [ V_3 ] ) ) {
F_210 ( V_18 -> V_554 [ V_3 ] ) ;
F_211 ( V_18 -> V_554 [ V_3 ] ) ;
}
}
#endif
return V_429 ;
}
static int F_212 ( struct V_541 * V_126 )
{
struct V_15 * V_16 = F_213 ( V_126 ) ;
#if F_194 ( V_548 )
struct V_17 * V_18 = V_16 -> V_19 ;
int V_3 ;
#endif
F_214 ( V_16 ) ;
#if F_194 ( V_548 )
if ( ! F_204 ( V_18 -> V_555 ) ) {
F_210 ( V_18 -> V_555 ) ;
F_211 ( V_18 -> V_555 ) ;
}
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ ) {
if ( ! F_204 ( V_18 -> V_554 [ V_3 ] ) ) {
F_210 ( V_18 -> V_554 [ V_3 ] ) ;
F_211 ( V_18 -> V_554 [ V_3 ] ) ;
}
}
#endif
return 0 ;
}
static int F_215 ( struct V_541 * V_126 , T_8 V_560 )
{
struct V_15 * V_16 = F_213 ( V_126 ) ;
if ( V_16 )
return F_216 ( V_16 , V_560 ) ;
else
return 0 ;
}
static int F_217 ( struct V_541 * V_126 )
{
struct V_15 * V_16 = F_213 ( V_126 ) ;
const struct V_533 * V_534 ;
int V_561 ;
if ( V_16 ) {
struct V_17 * V_18 = V_16 -> V_19 ;
V_534 = F_207 () ;
if ( V_534 )
F_190 ( V_18 , V_534 ) ;
V_561 = F_187 ( V_16 ) ;
if ( V_561 ) {
F_36 (KERN_ERR DRV_NAME L_63 ) ;
return V_561 ;
}
F_218 ( V_16 ) ;
}
return 0 ;
}
static int F_219 ( struct V_125 * V_126 )
{
int V_429 ;
if ( ! F_220 ( V_126 , F_221 ( 64 ) ) ) {
V_429 = F_222 ( V_126 , F_221 ( 64 ) ) ;
if ( V_429 ) {
V_429 = F_222 ( V_126 , F_221 ( 32 ) ) ;
if ( V_429 ) {
F_131 ( & V_126 -> V_152 ,
L_64 ) ;
return V_429 ;
}
}
} else {
V_429 = F_220 ( V_126 , F_221 ( 32 ) ) ;
if ( V_429 ) {
F_131 ( & V_126 -> V_152 , L_65 ) ;
return V_429 ;
}
V_429 = F_222 ( V_126 , F_221 ( 32 ) ) ;
if ( V_429 ) {
F_131 ( & V_126 -> V_152 ,
L_66 ) ;
return V_429 ;
}
}
return V_429 ;
}
static void F_223 ( struct V_15 * V_16 )
{
struct V_125 * V_126 = F_132 ( V_16 -> V_152 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
T_3 V_562 ;
const char * V_563 , * V_564 ;
F_224 ( V_126 , V_565 , & V_562 ) ;
if ( V_562 == 0 )
V_563 = L_67 ;
else if ( V_562 == 0x01 )
V_563 = L_68 ;
else
V_563 = L_69 ;
if ( F_25 ( V_18 ) )
V_564 = L_70 ;
else if ( F_55 ( V_18 ) )
V_564 = L_71 ;
else if ( F_22 ( V_18 ) )
V_564 = L_72 ;
else
V_564 = L_69 ;
F_208 ( & V_126 -> V_152 , L_73 ,
V_564 , ( unsigned ) V_192 , V_16 -> V_86 ,
V_563 , ( V_399 & V_18 -> V_170 ) ? L_74 : L_75 ) ;
}
static int F_225 ( struct V_125 * V_126 ,
const struct V_566 * V_567 )
{
unsigned int V_492 = ( unsigned int ) V_567 -> V_568 ;
const struct F_111 * V_544 [] = { & V_545 [ V_492 ] , NULL } ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_86 , V_3 , V_429 ;
F_195 ( & V_126 -> V_152 , V_549 ) ;
V_86 = F_12 ( V_544 [ 0 ] -> V_83 ) * V_87 ;
V_16 = F_200 ( & V_126 -> V_152 , V_544 , V_86 ) ;
V_18 = F_60 ( & V_126 -> V_152 , sizeof( * V_18 ) , V_197 ) ;
if ( ! V_16 || ! V_18 )
return - V_198 ;
V_16 -> V_19 = V_18 ;
V_18 -> V_86 = V_86 ;
V_18 -> V_492 = V_492 ;
V_429 = F_226 ( V_126 ) ;
if ( V_429 )
return V_429 ;
V_429 = F_227 ( V_126 , 1 << V_569 , V_329 ) ;
if ( V_429 == - V_570 )
F_228 ( V_126 ) ;
if ( V_429 )
return V_429 ;
V_16 -> V_556 = F_229 ( V_126 ) ;
V_18 -> V_6 = V_16 -> V_556 [ V_569 ] ;
V_429 = F_219 ( V_126 ) ;
if ( V_429 )
return V_429 ;
V_429 = F_188 ( V_18 , & V_126 -> V_152 ) ;
if ( V_429 )
return V_429 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ ) {
struct V_20 * V_21 = V_16 -> V_175 [ V_3 ] ;
void T_1 * V_25 = F_8 ( V_18 -> V_6 , V_3 ) ;
unsigned int V_210 = V_25 - V_18 -> V_6 ;
F_230 ( V_21 , V_569 , - 1 , L_76 ) ;
F_230 ( V_21 , V_569 , V_210 , L_77 ) ;
}
V_429 = F_187 ( V_16 ) ;
if ( V_429 )
return V_429 ;
if ( V_571 && F_231 ( V_126 ) == 0 )
V_18 -> V_170 |= V_399 ;
F_37 ( V_126 , 0x68 ) ;
F_223 ( V_16 ) ;
F_232 ( V_126 ) ;
F_233 ( V_126 ) ;
return F_209 ( V_16 , V_126 -> V_396 , F_134 , V_558 ,
F_25 ( V_18 ) ? & V_572 : & V_559 ) ;
}
static int F_234 ( struct V_125 * V_126 )
{
struct V_15 * V_16 = F_235 ( V_126 ) ;
int V_429 ;
V_429 = F_236 ( V_126 ) ;
if ( V_429 )
return V_429 ;
V_429 = F_187 ( V_16 ) ;
if ( V_429 )
return V_429 ;
F_218 ( V_16 ) ;
return 0 ;
}
static int T_9 F_237 ( void )
{
int V_429 = - V_573 ;
#ifdef F_238
V_429 = F_239 ( & V_574 ) ;
if ( V_429 < 0 )
return V_429 ;
#endif
V_429 = F_240 ( & V_575 ) ;
#ifdef F_238
if ( V_429 < 0 )
F_241 ( & V_574 ) ;
#endif
return V_429 ;
}
static void T_10 F_242 ( void )
{
#ifdef F_238
F_241 ( & V_574 ) ;
#endif
F_243 ( & V_575 ) ;
}
