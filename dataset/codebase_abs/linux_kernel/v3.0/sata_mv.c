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
F_33 ( V_21 , V_121 , L_1 ) ;
V_120 = - V_119 ;
}
F_29 ( V_21 , 0 , 0 ) ;
return V_120 ;
}
static void F_34 ( void T_1 * V_122 , unsigned V_123 )
{
int V_124 , V_125 ;
for ( V_124 = 0 ; V_124 < V_123 ; ) {
F_35 ( L_2 , V_122 + V_124 ) ;
for ( V_125 = 0 ; V_124 < V_123 && V_125 < 4 ; V_125 ++ ) {
F_36 ( L_3 , F_3 ( V_122 + V_124 ) ) ;
V_124 += sizeof( T_2 ) ;
}
F_36 ( L_4 ) ;
}
}
static void F_37 ( struct V_126 * V_127 , unsigned V_123 )
{
#ifdef F_38
int V_124 , V_125 ;
T_2 V_128 ;
for ( V_124 = 0 ; V_124 < V_123 ; ) {
F_35 ( L_5 , V_124 ) ;
for ( V_125 = 0 ; V_124 < V_123 && V_125 < 4 ; V_125 ++ ) {
( void ) F_39 ( V_127 , V_124 , & V_128 ) ;
F_36 ( L_3 , V_128 ) ;
V_124 += sizeof( T_2 ) ;
}
F_36 ( L_4 ) ;
}
#endif
}
static void F_40 ( void T_1 * V_129 , int V_3 ,
struct V_126 * V_127 )
{
#ifdef F_38
void T_1 * V_130 = F_6 ( V_129 ,
V_3 >> V_4 ) ;
void T_1 * V_131 ;
int V_132 , V_133 , V_134 , V_135 , V_136 , V_7 ;
if ( 0 > V_3 ) {
V_135 = V_132 = 0 ;
V_133 = 8 ;
V_136 = 2 ;
} else {
V_135 = V_3 >> V_4 ;
V_132 = V_3 ;
V_133 = V_136 = 1 ;
}
F_35 ( L_6 , V_132 ,
V_133 > 1 ? V_133 - 1 : V_132 ) ;
if ( NULL != V_127 ) {
F_35 ( L_7 ) ;
F_37 ( V_127 , 0x68 ) ;
}
F_35 ( L_8 ) ;
F_34 ( V_129 + 0xc00 , 0x3c ) ;
F_34 ( V_129 + 0xd00 , 0x34 ) ;
F_34 ( V_129 + 0xf00 , 0x4 ) ;
F_34 ( V_129 + 0x1d00 , 0x6c ) ;
for ( V_7 = V_135 ; V_7 < V_135 + V_136 ; V_7 ++ ) {
V_130 = F_6 ( V_129 , V_7 ) ;
F_35 ( L_9 , V_7 ) ;
F_34 ( V_130 , 0x1c ) ;
}
for ( V_134 = V_132 ; V_134 < V_132 + V_133 ; V_134 ++ ) {
V_131 = F_8 ( V_129 , V_134 ) ;
F_35 ( L_10 , V_134 ) ;
F_34 ( V_131 , 0x54 ) ;
F_35 ( L_11 , V_134 ) ;
F_34 ( V_131 + 0x300 , 0x60 ) ;
}
#endif
}
static unsigned int F_41 ( unsigned int V_137 )
{
unsigned int V_14 ;
switch ( V_137 ) {
case V_138 :
case V_139 :
case V_140 :
V_14 = V_141 + ( V_137 * sizeof( T_2 ) ) ;
break;
case V_142 :
V_14 = V_143 ;
break;
default:
V_14 = 0xffffffffU ;
break;
}
return V_14 ;
}
static int F_42 ( struct V_144 * V_145 , unsigned int V_137 , T_2 * V_146 )
{
unsigned int V_14 = F_41 ( V_137 ) ;
if ( V_14 != 0xffffffffU ) {
* V_146 = F_3 ( F_11 ( V_145 -> V_21 ) + V_14 ) ;
return 0 ;
} else
return - V_147 ;
}
static int F_43 ( struct V_144 * V_145 , unsigned int V_137 , T_2 V_146 )
{
unsigned int V_14 = F_41 ( V_137 ) ;
if ( V_14 != 0xffffffffU ) {
void T_1 * V_2 = F_11 ( V_145 -> V_21 ) + V_14 ;
if ( V_137 == V_139 ) {
if ( ( V_146 & 0xf ) == 1 || ( F_3 ( V_2 ) & 0xf ) == 1 )
V_146 |= 0xf000 ;
}
F_1 ( V_146 , V_2 ) ;
return 0 ;
} else
return - V_147 ;
}
static void F_44 ( struct V_148 * V_149 )
{
if ( V_149 -> V_83 & V_150 ) {
if ( F_45 ( V_149 -> V_145 -> V_21 ) ) {
V_149 -> V_83 &= ~ V_150 ;
F_46 ( V_149 , V_151 ,
L_12 ) ;
}
}
}
static int F_47 ( struct V_152 * V_153 )
{
struct V_144 * V_145 = V_153 -> V_154 -> V_145 ;
struct V_20 * V_21 = V_145 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
if ( V_27 -> V_103 & V_155 )
return V_156 ;
if ( F_48 ( V_21 -> V_157 ) ) {
if ( V_145 == V_21 -> V_157 ) {
if ( V_21 -> V_158 )
return V_156 ;
V_153 -> V_83 |= V_159 ;
return 0 ;
} else
return V_156 ;
}
if ( V_21 -> V_158 == 0 )
return 0 ;
if ( ( V_27 -> V_103 & V_104 ) &&
( V_27 -> V_103 & V_106 ) ) {
if ( F_49 ( V_153 -> V_160 . V_100 ) )
return 0 ;
else {
V_21 -> V_157 = V_145 ;
return V_156 ;
}
}
return V_156 ;
}
static void F_50 ( struct V_20 * V_21 , int V_101 , int V_161 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
void T_1 * V_25 ;
T_2 V_29 , * V_162 = & V_27 -> V_28 . V_29 ;
T_2 V_31 , * V_163 = & V_27 -> V_28 . V_31 ;
T_2 V_33 , * V_164 = & V_27 -> V_28 . V_33 ;
V_31 = * V_163 & ~ V_165 ;
V_33 = * V_164 | V_166 ;
if ( V_161 ) {
V_29 = * V_162 | V_167 ;
V_31 = * V_163 | V_165 ;
if ( V_101 )
V_33 &= ~ V_166 ;
else
V_29 |= V_168 ;
} else {
V_29 = * V_162 & ~ ( V_167 | V_168 ) ;
}
V_25 = F_11 ( V_21 ) ;
F_14 ( V_25 + V_30 , V_162 , V_29 ) ;
F_14 ( V_25 + V_32 , V_163 , V_31 ) ;
F_14 ( V_25 + V_34 , V_164 , V_33 ) ;
}
static void F_51 ( struct V_20 * V_21 , int V_101 )
{
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
T_2 V_37 , V_38 ;
V_37 = F_3 ( V_18 -> V_6 + V_169 ) ;
if ( V_101 )
V_38 = V_37 | ( 1 << 22 ) ;
else
V_38 = V_37 & ~ ( 1 << 22 ) ;
if ( V_38 != V_37 )
F_2 ( V_38 , V_18 -> V_6 + V_169 ) ;
}
static void F_52 ( struct V_20 * V_21 , int V_170 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
T_2 V_38 , * V_37 = & V_27 -> V_28 . V_35 ;
if ( V_170 )
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
T_2 V_171 ;
if ( V_18 -> V_172 & V_173 )
return;
V_18 -> V_172 |= V_173 ;
V_13 = F_7 ( F_10 ( V_16 ) , V_21 -> V_22 ) ;
V_171 = F_3 ( V_13 + V_174 ) ;
F_2 ( V_171 | V_175 , V_13 + V_174 ) ;
}
static void F_54 ( struct V_20 * V_21 )
{
struct V_15 * V_16 = V_21 -> V_16 ;
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_13 ;
T_2 V_171 ;
unsigned int V_3 ;
if ( ! ( V_18 -> V_172 & V_173 ) )
return;
for ( V_3 = 0 ; V_3 < V_18 -> V_86 ; V_3 ++ ) {
struct V_20 * V_176 = V_16 -> V_177 [ V_3 ] ;
struct V_26 * V_27 = V_176 -> V_19 ;
if ( V_27 -> V_103 & V_106 )
return;
}
V_18 -> V_172 &= ~ V_173 ;
V_13 = F_7 ( F_10 ( V_16 ) , V_21 -> V_22 ) ;
V_171 = F_3 ( V_13 + V_174 ) ;
F_2 ( V_171 & ~ V_175 , V_13 + V_174 ) ;
}
static void F_29 ( struct V_20 * V_21 , int V_101 , int V_178 )
{
T_2 V_179 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
V_179 = V_180 ;
V_27 -> V_103 &=
~ ( V_181 | V_106 | V_182 ) ;
if ( F_25 ( V_18 ) )
V_179 |= ( 1 << 8 ) ;
else if ( F_55 ( V_18 ) ) {
V_179 |= V_183 | V_184 ;
F_51 ( V_21 , V_101 ) ;
} else if ( F_22 ( V_18 ) ) {
int V_161 = F_45 ( V_21 ) ;
V_161 &= V_101 ;
F_50 ( V_21 , V_101 , V_161 ) ;
if ( V_161 ) {
V_27 -> V_103 |= V_181 ;
V_179 |= V_185 ;
}
V_179 |= ( 1 << 23 ) ;
if ( V_178 ) {
V_179 |= ( 1 << 22 ) ;
if ( ! F_56 ( V_18 ) )
V_179 |= ( 1 << 18 ) ;
}
if ( V_18 -> V_172 & V_186 )
V_179 |= ( 1 << 17 ) ;
F_52 ( V_21 , ! V_178 ) ;
if ( F_56 ( V_18 ) ) {
if ( V_101 )
F_53 ( V_21 ) ;
else
F_54 ( V_21 ) ;
}
}
if ( V_101 ) {
V_179 |= V_187 ;
V_27 -> V_103 |= V_106 ;
}
F_1 ( V_179 , V_25 + V_188 ) ;
}
static void F_57 ( struct V_20 * V_21 )
{
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
struct V_26 * V_27 = V_21 -> V_19 ;
int V_189 ;
if ( V_27 -> V_190 ) {
F_58 ( V_18 -> V_191 , V_27 -> V_190 , V_27 -> V_44 ) ;
V_27 -> V_190 = NULL ;
}
if ( V_27 -> V_192 ) {
F_58 ( V_18 -> V_193 , V_27 -> V_192 , V_27 -> V_51 ) ;
V_27 -> V_192 = NULL ;
}
for ( V_189 = 0 ; V_189 < V_194 ; ++ V_189 ) {
if ( V_27 -> V_195 [ V_189 ] ) {
if ( V_189 == 0 || ! F_25 ( V_18 ) )
F_58 ( V_18 -> V_196 ,
V_27 -> V_195 [ V_189 ] ,
V_27 -> V_197 [ V_189 ] ) ;
V_27 -> V_195 [ V_189 ] = NULL ;
}
}
}
static int F_59 ( struct V_20 * V_21 )
{
struct V_198 * V_154 = V_21 -> V_16 -> V_154 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
struct V_26 * V_27 ;
unsigned long V_83 ;
int V_189 ;
V_27 = F_60 ( V_154 , sizeof( * V_27 ) , V_199 ) ;
if ( ! V_27 )
return - V_200 ;
V_21 -> V_19 = V_27 ;
V_27 -> V_190 = F_61 ( V_18 -> V_191 , V_199 , & V_27 -> V_44 ) ;
if ( ! V_27 -> V_190 )
return - V_200 ;
memset ( V_27 -> V_190 , 0 , V_201 ) ;
V_27 -> V_192 = F_61 ( V_18 -> V_193 , V_199 , & V_27 -> V_51 ) ;
if ( ! V_27 -> V_192 )
goto V_202;
memset ( V_27 -> V_192 , 0 , V_203 ) ;
if ( V_18 -> V_172 & V_204 )
V_21 -> V_83 |= V_205 ;
for ( V_189 = 0 ; V_189 < V_194 ; ++ V_189 ) {
if ( V_189 == 0 || ! F_25 ( V_18 ) ) {
V_27 -> V_195 [ V_189 ] = F_61 ( V_18 -> V_196 ,
V_199 , & V_27 -> V_197 [ V_189 ] ) ;
if ( ! V_27 -> V_195 [ V_189 ] )
goto V_202;
} else {
V_27 -> V_195 [ V_189 ] = V_27 -> V_195 [ 0 ] ;
V_27 -> V_197 [ V_189 ] = V_27 -> V_197 [ 0 ] ;
}
}
F_24 ( V_21 -> V_92 , V_83 ) ;
F_13 ( V_21 ) ;
F_29 ( V_21 , 0 , 0 ) ;
F_26 ( V_21 -> V_92 , V_83 ) ;
return 0 ;
V_202:
F_57 ( V_21 ) ;
return - V_200 ;
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
static void F_63 ( struct V_152 * V_153 )
{
struct V_26 * V_27 = V_153 -> V_21 -> V_19 ;
struct V_206 * V_207 ;
struct V_208 * V_208 , * V_209 = NULL ;
unsigned int V_210 ;
V_208 = V_27 -> V_195 [ V_153 -> V_189 ] ;
F_64 (qc->sg, sg, qc->n_elem, si) {
T_4 V_2 = F_65 ( V_207 ) ;
T_2 V_211 = F_66 ( V_207 ) ;
while ( V_211 ) {
T_2 V_212 = V_2 & 0xffff ;
T_2 V_213 = V_211 ;
if ( V_212 + V_213 > 0x10000 )
V_213 = 0x10000 - V_212 ;
V_208 -> V_2 = F_67 ( V_2 & 0xffffffff ) ;
V_208 -> V_214 = F_67 ( ( V_2 >> 16 ) >> 16 ) ;
V_208 -> V_215 = F_67 ( V_213 & 0xffff ) ;
V_208 -> V_216 = 0 ;
V_211 -= V_213 ;
V_2 += V_213 ;
V_209 = V_208 ;
V_208 ++ ;
}
}
if ( F_68 ( V_209 ) )
V_209 -> V_215 |= F_67 ( V_217 ) ;
F_69 () ;
}
static void F_70 ( T_5 * V_218 , T_3 V_1 , T_3 V_2 , unsigned V_219 )
{
T_6 V_220 = V_1 | ( V_2 << V_221 ) | V_222 |
( V_219 ? V_223 : 0 ) ;
* V_218 = F_71 ( V_220 ) ;
}
static void F_72 ( struct V_20 * V_21 )
{
F_21 ( V_21 , F_11 ( V_21 ) , V_72 ) ;
}
static int F_73 ( struct V_152 * V_153 )
{
struct V_224 * V_225 = V_153 -> V_226 ;
if ( V_225 ) {
switch ( V_225 -> V_227 [ 0 ] ) {
case V_228 :
case V_229 :
case V_230 :
case V_231 :
case V_232 :
case V_233 :
case V_234 :
case V_235 :
case V_236 :
return 0 ;
}
}
return - V_237 ;
}
static void F_74 ( struct V_152 * V_153 )
{
struct V_20 * V_21 = V_153 -> V_21 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
F_63 ( V_153 ) ;
F_2 ( 0 , V_25 + V_238 ) ;
F_2 ( ( V_27 -> V_197 [ V_153 -> V_189 ] >> 16 ) >> 16 ,
V_25 + V_239 ) ;
F_1 ( V_27 -> V_197 [ V_153 -> V_189 ] ,
V_25 + V_240 ) ;
V_21 -> V_241 -> V_242 ( V_21 , & V_153 -> V_160 ) ;
}
static void F_75 ( struct V_152 * V_153 )
{
struct V_20 * V_21 = V_153 -> V_21 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
unsigned int V_243 = ( V_153 -> V_160 . V_83 & V_244 ) ;
T_2 V_245 = ( V_243 ? 0 : V_246 ) | V_247 ;
F_1 ( V_245 , V_25 + V_238 ) ;
}
static void F_76 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_245 ;
V_245 = F_3 ( V_25 + V_238 ) ;
if ( V_245 & V_247 ) {
V_245 &= ~ V_247 ;
F_1 ( V_245 , V_25 + V_238 ) ;
F_77 ( V_21 ) ;
}
}
static void F_78 ( struct V_152 * V_153 )
{
F_76 ( V_153 -> V_21 ) ;
}
static T_3 F_79 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_118 , V_248 ;
V_118 = F_3 ( V_25 + V_249 ) ;
if ( V_118 & V_250 )
V_248 = V_250 ;
else if ( V_118 & V_251 )
V_248 = ( V_118 & V_251 ) | V_252 ;
else {
F_76 ( V_21 ) ;
if ( F_80 ( V_21 -> V_253 . V_254 ) & V_255 )
V_248 = 0 ;
else
V_248 = V_252 ;
}
return V_248 ;
}
static void F_81 ( struct V_152 * V_153 )
{
struct V_256 * V_160 = & V_153 -> V_160 ;
if ( ( V_160 -> V_83 & V_244 ) && F_82 ( V_160 ) ) {
if ( V_153 -> V_154 -> V_257 > 7 ) {
switch ( V_160 -> V_258 ) {
case V_259 :
V_160 -> V_258 = V_260 ;
break;
case V_261 :
V_160 -> V_83 &= ~ V_262 ;
case V_263 :
V_160 -> V_258 = V_264 ;
break;
}
}
}
}
static void F_83 ( struct V_152 * V_153 )
{
struct V_20 * V_21 = V_153 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
T_5 * V_265 ;
struct V_256 * V_160 = & V_153 -> V_160 ;
T_6 V_83 = 0 ;
unsigned V_266 ;
switch ( V_160 -> V_100 ) {
case V_267 :
if ( V_160 -> V_258 == V_268 )
return;
case V_102 :
break;
case V_269 :
F_81 ( V_153 ) ;
return;
default:
return;
}
if ( ! ( V_160 -> V_83 & V_244 ) )
V_83 |= V_270 ;
F_16 ( V_194 <= V_153 -> V_189 ) ;
V_83 |= V_153 -> V_189 << V_271 ;
V_83 |= ( V_153 -> V_154 -> V_145 -> V_272 & 0xf ) << V_273 ;
V_266 = V_27 -> V_41 ;
V_27 -> V_190 [ V_266 ] . V_274 =
F_67 ( V_27 -> V_197 [ V_153 -> V_189 ] & 0xffffffff ) ;
V_27 -> V_190 [ V_266 ] . V_275 =
F_67 ( ( V_27 -> V_197 [ V_153 -> V_189 ] >> 16 ) >> 16 ) ;
V_27 -> V_190 [ V_266 ] . V_276 = F_71 ( V_83 ) ;
V_265 = & V_27 -> V_190 [ V_266 ] . V_277 [ 0 ] ;
switch ( V_160 -> V_258 ) {
case V_278 :
case V_279 :
case V_280 :
case V_281 :
case V_282 :
F_70 ( V_265 ++ , V_160 -> V_283 , V_284 , 0 ) ;
break;
case V_285 :
case V_286 :
F_70 ( V_265 ++ , V_160 -> V_287 , V_288 , 0 ) ;
F_70 ( V_265 ++ , V_160 -> V_289 , V_288 , 0 ) ;
break;
default:
F_84 ( V_160 -> V_258 ) ;
break;
}
F_70 ( V_265 ++ , V_160 -> V_290 , V_284 , 0 ) ;
F_70 ( V_265 ++ , V_160 -> V_291 , V_292 , 0 ) ;
F_70 ( V_265 ++ , V_160 -> V_293 , V_292 , 0 ) ;
F_70 ( V_265 ++ , V_160 -> V_294 , V_295 , 0 ) ;
F_70 ( V_265 ++ , V_160 -> V_296 , V_295 , 0 ) ;
F_70 ( V_265 ++ , V_160 -> V_297 , V_298 , 0 ) ;
F_70 ( V_265 ++ , V_160 -> V_299 , V_298 , 0 ) ;
F_70 ( V_265 ++ , V_160 -> V_198 , V_300 , 0 ) ;
F_70 ( V_265 ++ , V_160 -> V_258 , V_301 , 1 ) ;
if ( ! ( V_153 -> V_83 & V_302 ) )
return;
F_63 ( V_153 ) ;
}
static void F_85 ( struct V_152 * V_153 )
{
struct V_20 * V_21 = V_153 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_303 * V_190 ;
struct V_256 * V_160 = & V_153 -> V_160 ;
unsigned V_266 ;
T_2 V_83 = 0 ;
if ( ( V_160 -> V_100 != V_267 ) &&
( V_160 -> V_100 != V_102 ) )
return;
if ( V_160 -> V_258 == V_268 )
return;
if ( ! ( V_160 -> V_83 & V_244 ) )
V_83 |= V_270 ;
F_16 ( V_194 <= V_153 -> V_189 ) ;
V_83 |= V_153 -> V_189 << V_271 ;
V_83 |= V_153 -> V_189 << V_304 ;
V_83 |= ( V_153 -> V_154 -> V_145 -> V_272 & 0xf ) << V_273 ;
V_266 = V_27 -> V_41 ;
V_190 = (struct V_303 * ) & V_27 -> V_190 [ V_266 ] ;
V_190 -> V_2 = F_67 ( V_27 -> V_197 [ V_153 -> V_189 ] & 0xffffffff ) ;
V_190 -> V_214 = F_67 ( ( V_27 -> V_197 [ V_153 -> V_189 ] >> 16 ) >> 16 ) ;
V_190 -> V_83 = F_67 ( V_83 ) ;
V_190 -> V_277 [ 0 ] = F_67 (
( V_160 -> V_258 << 16 ) |
( V_160 -> V_289 << 24 )
) ;
V_190 -> V_277 [ 1 ] = F_67 (
( V_160 -> V_293 << 0 ) |
( V_160 -> V_296 << 8 ) |
( V_160 -> V_299 << 16 ) |
( V_160 -> V_198 << 24 )
) ;
V_190 -> V_277 [ 2 ] = F_67 (
( V_160 -> V_291 << 0 ) |
( V_160 -> V_294 << 8 ) |
( V_160 -> V_297 << 16 ) |
( V_160 -> V_287 << 24 )
) ;
V_190 -> V_277 [ 3 ] = F_67 (
( V_160 -> V_290 << 0 ) |
( V_160 -> V_283 << 8 )
) ;
if ( ! ( V_153 -> V_83 & V_302 ) )
return;
F_63 ( V_153 ) ;
}
static T_3 F_86 ( struct V_20 * V_21 )
{
T_3 V_305 = F_80 ( V_21 -> V_253 . V_306 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
if ( V_27 -> V_103 & V_182 ) {
if ( V_305 & ( V_255 | V_307 | V_308 ) )
V_27 -> V_103 &= ~ V_182 ;
else
V_305 = V_255 ;
}
return V_305 ;
}
static unsigned int F_87 ( struct V_20 * V_21 , T_2 * V_309 , int V_310 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_311 , V_312 , V_313 ;
int V_114 , V_113 = 200 , V_314 = V_310 - 1 ;
V_312 = F_3 ( V_25 + V_315 ) ;
V_311 = 0x100 | ( V_312 & 0xf ) ;
F_1 ( V_311 , V_25 + V_315 ) ;
for ( V_114 = 0 ; V_114 < V_314 ; ++ V_114 )
F_2 ( V_309 [ V_114 ] , V_25 + V_316 ) ;
F_1 ( V_311 | 0x200 , V_25 + V_315 ) ;
F_1 ( V_309 [ V_314 ] , V_25 + V_316 ) ;
do {
V_313 = F_3 ( V_25 + V_317 ) ;
} while ( ! ( V_313 & 0x1000 ) && -- V_113 );
F_1 ( V_312 , V_25 + V_315 ) ;
if ( ( V_313 & 0x3000 ) != 0x1000 ) {
F_33 ( V_21 , V_318 ,
L_13 ,
V_319 , V_313 ) ;
return V_320 ;
}
return 0 ;
}
static unsigned int F_88 ( struct V_152 * V_153 )
{
struct V_20 * V_21 = V_153 -> V_21 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_144 * V_145 = V_153 -> V_154 -> V_145 ;
T_2 V_309 [ 5 ] ;
int V_120 = 0 ;
F_89 ( & V_153 -> V_160 , V_145 -> V_272 , 1 , ( void * ) V_309 ) ;
V_120 = F_87 ( V_21 , V_309 , F_90 ( V_309 ) ) ;
if ( V_120 )
return V_120 ;
switch ( V_153 -> V_160 . V_100 ) {
case V_321 :
V_27 -> V_103 |= V_182 ;
case V_322 :
V_21 -> V_323 = V_324 ;
break;
case V_269 :
V_27 -> V_103 |= V_182 ;
if ( V_153 -> V_160 . V_83 & V_244 )
V_21 -> V_323 = V_324 ;
else
V_21 -> V_323 = V_325 ;
break;
default:
V_21 -> V_323 = V_326 ;
break;
}
if ( V_153 -> V_160 . V_83 & V_327 )
F_91 ( V_145 , 0 ) ;
return 0 ;
}
static unsigned int F_92 ( struct V_152 * V_153 )
{
static int V_328 = 10 ;
struct V_20 * V_21 = V_153 -> V_21 ;
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_26 * V_27 = V_21 -> V_19 ;
T_2 V_266 ;
unsigned int V_73 ;
V_27 -> V_103 &= ~ V_182 ;
switch ( V_153 -> V_160 . V_100 ) {
case V_267 :
if ( V_153 -> V_160 . V_258 == V_268 ) {
if ( ! V_21 -> V_241 -> V_329 )
return V_320 ;
break;
}
case V_102 :
F_27 ( V_21 , V_25 , V_27 , V_153 -> V_160 . V_100 ) ;
V_27 -> V_41 = ( V_27 -> V_41 + 1 ) & V_42 ;
V_266 = V_27 -> V_41 << V_43 ;
F_1 ( ( V_27 -> V_44 & V_46 ) | V_266 ,
V_25 + V_47 ) ;
return 0 ;
case V_269 :
if ( V_328 > 0 && ( V_153 -> V_330 / V_153 -> V_331 ) > 1 ) {
-- V_328 ;
F_93 ( V_153 -> V_154 -> V_145 , V_318 , V_332
L_14
L_15 ) ;
}
case V_333 :
case V_321 :
case V_322 :
if ( V_21 -> V_83 & V_334 )
V_153 -> V_160 . V_83 |= V_327 ;
break;
}
if ( V_153 -> V_160 . V_83 & V_327 )
V_73 = V_72 ;
else
V_73 = V_72 | V_71 ;
F_28 ( V_21 ) ;
F_21 ( V_21 , F_11 ( V_21 ) , V_73 ) ;
F_94 ( V_21 , V_153 -> V_154 -> V_145 -> V_272 ) ;
if ( V_153 -> V_160 . V_258 == V_335 ) {
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
if ( F_55 ( V_18 ) )
return F_88 ( V_153 ) ;
}
return F_95 ( V_153 ) ;
}
static struct V_152 * F_96 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_152 * V_153 ;
if ( V_27 -> V_103 & V_106 )
return NULL ;
V_153 = F_97 ( V_21 , V_21 -> V_145 . V_336 ) ;
if ( V_153 && ! ( V_153 -> V_160 . V_83 & V_327 ) )
return V_153 ;
return NULL ;
}
static void F_98 ( struct V_20 * V_21 )
{
unsigned int V_272 , V_337 ;
struct V_26 * V_27 = V_21 -> V_19 ;
if ( V_27 -> V_103 & V_155 ) {
V_337 = V_27 -> V_338 ;
V_27 -> V_103 &= ~ V_155 ;
for ( V_272 = 0 ; V_337 != 0 ; V_272 ++ ) {
unsigned int V_339 = ( 1 << V_272 ) ;
if ( V_337 & V_339 ) {
struct V_144 * V_145 = & V_21 -> V_340 [ V_272 ] ;
V_337 &= ~ V_339 ;
F_99 ( V_145 ) ;
}
}
F_100 ( V_21 ) ;
}
F_101 ( V_21 ) ;
}
static unsigned int F_102 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
return F_3 ( V_25 + V_341 ) >> 16 ;
}
static void F_103 ( struct V_20 * V_21 , unsigned int V_337 )
{
struct V_342 * V_343 ;
unsigned int V_272 ;
V_343 = & V_21 -> V_145 . V_344 ;
for ( V_272 = 0 ; V_337 != 0 ; V_272 ++ ) {
unsigned int V_339 = ( 1 << V_272 ) ;
if ( V_337 & V_339 ) {
struct V_144 * V_145 = & V_21 -> V_340 [ V_272 ] ;
V_337 &= ~ V_339 ;
V_343 = & V_145 -> V_344 ;
F_104 ( V_343 ) ;
F_105 ( V_343 , L_16 ) ;
V_343 -> V_345 |= V_346 ;
V_343 -> V_347 |= V_348 ;
F_106 ( V_145 ) ;
}
}
}
static int F_107 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_349 , V_350 ;
V_349 = ( F_3 ( V_25 + V_47 )
>> V_43 ) & V_42 ;
V_350 = ( F_3 ( V_25 + V_48 )
>> V_43 ) & V_42 ;
return ( V_349 == V_350 ) ;
}
static int F_108 ( struct V_20 * V_21 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
int V_351 ;
unsigned int V_352 , V_353 ;
if ( ! ( V_27 -> V_103 & V_155 ) ) {
V_27 -> V_103 |= V_155 ;
V_27 -> V_338 = 0 ;
}
V_352 = V_27 -> V_338 ;
V_353 = V_352 | F_102 ( V_21 ) ;
if ( V_352 != V_353 ) {
V_27 -> V_338 = V_353 ;
F_103 ( V_21 , V_353 & ~ V_352 ) ;
}
V_351 = F_109 ( V_353 ) ;
F_33 ( V_21 , V_151 , L_17
L_18 ,
V_319 , V_27 -> V_338 ,
V_21 -> V_354 , V_351 ,
V_21 -> V_158 ) ;
if ( V_21 -> V_158 <= V_351 && F_107 ( V_21 ) ) {
F_110 ( V_21 , V_27 ) ;
F_28 ( V_21 ) ;
F_111 ( V_21 ) ;
F_33 ( V_21 , V_151 , L_19 , V_319 ) ;
return 1 ;
}
F_33 ( V_21 , V_151 , L_20 , V_319 ) ;
return 1 ;
}
static int F_112 ( struct V_20 * V_21 )
{
return 0 ;
}
static int F_113 ( struct V_20 * V_21 , T_2 V_355 )
{
struct V_26 * V_27 = V_21 -> V_19 ;
if ( ! ( V_27 -> V_103 & V_104 ) )
return 0 ;
if ( ! ( V_27 -> V_103 & V_181 ) )
return 0 ;
if ( ! ( V_355 & V_166 ) )
return 0 ;
V_355 &= ~ V_356 ;
if ( V_355 & ~ ( V_166 | V_357 ) )
return 0 ;
if ( V_27 -> V_103 & V_106 ) {
if ( V_355 & V_357 ) {
F_33 ( V_21 , V_318 ,
L_21 ,
V_319 , V_355 , V_27 -> V_103 ) ;
return 0 ;
}
return F_108 ( V_21 ) ;
} else {
if ( ! ( V_355 & V_357 ) ) {
F_33 ( V_21 , V_318 ,
L_21 ,
V_319 , V_355 , V_27 -> V_103 ) ;
return 0 ;
}
return F_112 ( V_21 ) ;
}
return 0 ;
}
static void F_114 ( struct V_20 * V_21 , int V_358 )
{
struct V_342 * V_343 = & V_21 -> V_145 . V_344 ;
char * V_359 = L_22 ;
F_104 ( V_343 ) ;
if ( V_358 ) {
V_359 = L_23 ;
} else {
struct V_152 * V_153 = F_97 ( V_21 , V_21 -> V_145 . V_336 ) ;
if ( V_153 && ( V_153 -> V_160 . V_83 & V_327 ) )
V_359 = L_24 ;
}
F_105 ( V_343 , L_25 , V_359 ) ;
V_343 -> V_345 |= V_320 ;
V_343 -> V_347 |= V_348 ;
F_100 ( V_21 ) ;
}
static void F_115 ( struct V_20 * V_21 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_355 , V_360 , V_361 = 0 ;
T_2 V_362 = 0 ;
struct V_26 * V_27 = V_21 -> V_19 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
unsigned int V_347 = 0 , V_345 = 0 ;
struct V_342 * V_343 = & V_21 -> V_145 . V_344 ;
struct V_152 * V_153 ;
int abort = 0 ;
F_116 ( & V_21 -> V_145 , V_140 , & V_361 ) ;
F_117 ( & V_21 -> V_145 , V_140 , V_361 ) ;
V_355 = F_3 ( V_25 + V_75 ) ;
if ( F_22 ( V_18 ) && ( V_355 & V_363 ) ) {
V_362 = F_3 ( V_25 + V_79 ) ;
F_1 ( ~ V_362 , V_25 + V_79 ) ;
}
F_1 ( ~ V_355 , V_25 + V_75 ) ;
if ( V_355 & V_166 ) {
if ( F_113 ( V_21 , V_355 ) )
return;
}
V_153 = F_96 ( V_21 ) ;
F_104 ( V_343 ) ;
F_105 ( V_343 , L_26 ,
V_355 , V_27 -> V_103 ) ;
if ( F_22 ( V_18 ) && ( V_355 & V_363 ) ) {
F_105 ( V_343 , L_27 , V_362 ) ;
if ( V_362 & V_364 ) {
T_2 V_365 = V_355 &
~ ( V_363 | V_356 ) ;
F_118 ( V_21 ) ;
if ( ! V_365 )
return;
F_105 ( V_343 , L_28 ) ;
}
}
if ( V_355 & V_166 ) {
V_345 |= V_346 ;
V_347 |= V_348 ;
F_105 ( V_343 , L_29 ) ;
}
if ( V_355 & ( V_366 | V_367 |
V_368 | V_369 |
V_370 ) ) {
V_345 |= V_371 ;
V_347 |= V_348 ;
F_105 ( V_343 , L_30 ) ;
}
if ( V_355 & ( V_372 | V_373 ) ) {
F_119 ( V_343 ) ;
F_105 ( V_343 , V_355 & V_372 ?
L_31 : L_32 ) ;
V_347 |= V_348 ;
}
if ( F_25 ( V_18 ) ) {
V_360 = V_374 ;
if ( V_355 & V_375 ) {
V_27 -> V_103 &= ~ V_104 ;
F_105 ( V_343 , L_33 ) ;
}
} else {
V_360 = V_376 ;
if ( V_355 & V_357 ) {
V_27 -> V_103 &= ~ V_104 ;
F_105 ( V_343 , L_33 ) ;
}
if ( V_355 & V_377 ) {
F_105 ( V_343 , L_34 , V_361 ) ;
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
if ( V_153 )
V_153 -> V_345 |= V_345 ;
else
V_343 -> V_345 |= V_345 ;
if ( V_345 == V_346 ) {
F_111 ( V_21 ) ;
abort = 1 ;
} else if ( V_355 & V_360 ) {
F_100 ( V_21 ) ;
} else {
abort = 1 ;
}
if ( abort ) {
if ( V_153 )
F_106 ( V_153 -> V_154 -> V_145 ) ;
else
F_120 ( V_21 ) ;
}
}
static bool F_121 ( struct V_20 * V_21 ,
struct V_379 * V_380 , unsigned int V_189 , int V_381 )
{
T_3 V_382 ;
T_6 V_383 = F_122 ( V_380 -> V_83 ) ;
if ( ! V_381 ) {
T_3 V_384 = V_383 & 0xff & ~ V_166 ;
if ( V_384 ) {
return false ;
}
}
V_382 = V_383 >> V_385 ;
if ( ! F_123 ( V_382 ) )
return true ;
return false ;
}
static void F_110 ( struct V_20 * V_21 , struct V_26 * V_27 )
{
void T_1 * V_25 = F_11 ( V_21 ) ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
T_2 V_266 ;
bool V_386 = false ;
T_2 V_387 = 0 ;
int V_381 = ( V_27 -> V_103 & V_106 ) ;
V_266 = ( F_3 ( V_25 + V_53 )
>> V_50 ) & V_42 ;
while ( V_266 != V_27 -> V_49 ) {
unsigned int V_189 ;
struct V_379 * V_380 = & V_27 -> V_192 [ V_27 -> V_49 ] ;
V_27 -> V_49 = ( V_27 -> V_49 + 1 ) & V_42 ;
if ( F_25 ( V_18 ) ) {
V_189 = V_21 -> V_145 . V_336 ;
} else {
V_189 = F_122 ( V_380 -> V_388 ) & 0x1f ;
}
if ( F_121 ( V_21 , V_380 , V_189 , V_381 ) )
V_387 |= 1 << V_189 ;
V_386 = true ;
}
if ( V_386 ) {
F_124 ( V_21 , V_21 -> V_354 ^ V_387 ) ;
F_1 ( ( V_27 -> V_51 & V_54 ) |
( V_27 -> V_49 << V_50 ) ,
V_25 + V_55 ) ;
}
}
static void F_125 ( struct V_20 * V_21 , T_2 V_389 )
{
struct V_26 * V_27 ;
int V_358 ;
V_27 = V_21 -> V_19 ;
V_358 = ( V_27 -> V_103 & V_104 ) ;
if ( V_358 && ( V_389 & V_71 ) ) {
F_110 ( V_21 , V_27 ) ;
if ( V_27 -> V_103 & V_155 )
F_108 ( V_21 ) ;
}
if ( F_48 ( V_389 & V_72 ) ) {
F_115 ( V_21 ) ;
} else if ( ! V_358 ) {
struct V_152 * V_153 = F_96 ( V_21 ) ;
if ( V_153 )
F_126 ( V_21 , V_153 ) ;
else
F_114 ( V_21 , V_358 ) ;
}
}
static int F_127 ( struct V_15 * V_16 , T_2 V_390 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 , * V_13 ;
unsigned int V_391 = 0 , V_3 ;
if ( V_390 & V_57 )
F_2 ( ~ V_95 , V_12 + V_96 ) ;
for ( V_3 = 0 ; V_3 < V_18 -> V_86 ; V_3 ++ ) {
struct V_20 * V_21 = V_16 -> V_177 [ V_3 ] ;
unsigned int V_134 , V_69 , V_70 , V_389 ;
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
for ( V_134 = 0 ; V_134 < V_87 ; ++ V_134 ) {
if ( ( V_3 + V_134 ) >= V_18 -> V_86 )
break;
V_394 = ( V_71 | V_72 ) << ( V_134 * 2 ) ;
if ( V_392 & V_394 )
V_395 |= ( V_77 | V_76 ) << V_134 ;
}
V_13 = F_7 ( V_12 , V_3 ) ;
F_1 ( ~ V_395 , V_13 + V_78 ) ;
V_391 = 1 ;
}
V_389 = ( V_390 >> V_69 ) & ( V_71 | V_72 ) ;
if ( V_389 )
F_125 ( V_21 , V_389 ) ;
}
return V_391 ;
}
static int F_128 ( struct V_15 * V_16 , void T_1 * V_12 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
struct V_20 * V_21 ;
struct V_152 * V_153 ;
struct V_342 * V_343 ;
unsigned int V_114 , V_345 , V_396 = 0 ;
T_2 V_384 ;
V_384 = F_3 ( V_12 + V_18 -> V_397 ) ;
F_129 ( V_121 , V_16 -> V_154 , L_35 ,
V_384 ) ;
F_35 ( L_36 ) ;
F_40 ( V_12 , - 1 , F_130 ( V_16 -> V_154 ) ) ;
F_1 ( 0 , V_12 + V_18 -> V_397 ) ;
for ( V_114 = 0 ; V_114 < V_16 -> V_86 ; V_114 ++ ) {
V_21 = V_16 -> V_177 [ V_114 ] ;
if ( ! F_131 ( & V_21 -> V_145 ) ) {
V_343 = & V_21 -> V_145 . V_344 ;
F_104 ( V_343 ) ;
if ( ! V_396 ++ )
F_105 ( V_343 ,
L_37 , V_384 ) ;
V_345 = V_398 ;
V_343 -> V_347 = V_348 ;
V_153 = F_97 ( V_21 , V_21 -> V_145 . V_336 ) ;
if ( V_153 )
V_153 -> V_345 |= V_345 ;
else
V_343 -> V_345 |= V_345 ;
F_100 ( V_21 ) ;
}
}
return 1 ;
}
static T_7 F_132 ( int V_399 , void * V_400 )
{
struct V_15 * V_16 = V_400 ;
struct V_17 * V_18 = V_16 -> V_19 ;
unsigned int V_391 = 0 ;
int V_401 = V_18 -> V_172 & V_402 ;
T_2 V_390 , V_403 ;
F_133 ( & V_16 -> V_92 ) ;
if ( V_401 )
F_17 ( 0 , V_18 ) ;
V_390 = F_3 ( V_18 -> V_404 ) ;
V_403 = V_390 & V_18 -> V_67 ;
if ( V_403 && V_390 != 0xffffffffU ) {
if ( F_48 ( ( V_403 & V_405 ) && ! F_56 ( V_18 ) ) )
V_391 = F_128 ( V_16 , V_18 -> V_6 ) ;
else
V_391 = F_127 ( V_16 , V_403 ) ;
}
if ( V_401 )
F_17 ( V_18 -> V_67 , V_18 ) ;
F_134 ( & V_16 -> V_92 ) ;
return F_135 ( V_391 ) ;
}
static unsigned int F_136 ( unsigned int V_137 )
{
unsigned int V_14 ;
switch ( V_137 ) {
case V_138 :
case V_140 :
case V_139 :
V_14 = V_137 * sizeof( T_2 ) ;
break;
default:
V_14 = 0xffffffffU ;
break;
}
return V_14 ;
}
static int F_137 ( struct V_144 * V_145 , unsigned int V_137 , T_2 * V_146 )
{
struct V_17 * V_18 = V_145 -> V_21 -> V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
void T_1 * V_2 = F_9 ( V_12 , V_145 -> V_21 -> V_22 ) ;
unsigned int V_14 = F_136 ( V_137 ) ;
if ( V_14 != 0xffffffffU ) {
* V_146 = F_3 ( V_2 + V_14 ) ;
return 0 ;
} else
return - V_147 ;
}
static int F_138 ( struct V_144 * V_145 , unsigned int V_137 , T_2 V_146 )
{
struct V_17 * V_18 = V_145 -> V_21 -> V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
void T_1 * V_2 = F_9 ( V_12 , V_145 -> V_21 -> V_22 ) ;
unsigned int V_14 = F_136 ( V_137 ) ;
if ( V_14 != 0xffffffffU ) {
F_1 ( V_146 , V_2 + V_14 ) ;
return 0 ;
} else
return - V_147 ;
}
static void F_139 ( struct V_15 * V_16 , void T_1 * V_12 )
{
struct V_126 * V_127 = F_130 ( V_16 -> V_154 ) ;
int V_406 ;
V_406 = ( V_127 -> V_198 == 0x5080 ) && ( V_127 -> V_407 == 0 ) ;
if ( ! V_406 ) {
T_2 V_220 = F_3 ( V_12 + V_408 ) ;
V_220 |= ( 1 << 0 ) ;
F_2 ( V_220 , V_12 + V_408 ) ;
}
F_140 ( V_16 , V_12 ) ;
}
static void F_141 ( struct V_17 * V_18 , void T_1 * V_12 )
{
F_2 ( 0x0fcfffff , V_12 + V_409 ) ;
}
static void F_142 ( struct V_17 * V_18 , int V_410 ,
void T_1 * V_12 )
{
void T_1 * V_411 = F_9 ( V_12 , V_410 ) ;
T_2 V_220 ;
V_220 = F_3 ( V_411 + V_412 ) ;
V_18 -> signal [ V_410 ] . V_413 = V_220 & 0x1800 ;
V_18 -> signal [ V_410 ] . V_414 = V_220 & 0xe0 ;
}
static void F_143 ( struct V_17 * V_18 , void T_1 * V_12 )
{
T_2 V_220 ;
F_2 ( 0 , V_12 + V_169 ) ;
V_220 = F_3 ( V_12 + V_408 ) ;
V_220 |= ~ ( 1 << 0 ) ;
F_2 ( V_220 , V_12 + V_408 ) ;
}
static void F_144 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_3 )
{
void T_1 * V_411 = F_9 ( V_12 , V_3 ) ;
const T_2 V_56 = ( 1 << 12 ) | ( 1 << 11 ) | ( 1 << 7 ) | ( 1 << 6 ) | ( 1 << 5 ) ;
T_2 V_220 ;
int V_415 = ( V_18 -> V_172 & V_416 ) ;
if ( V_415 ) {
V_220 = F_3 ( V_411 + V_417 ) ;
V_220 |= ( 1 << 19 ) ;
F_2 ( V_220 , V_411 + V_417 ) ;
V_220 = F_3 ( V_411 + V_418 ) ;
V_220 &= ~ 0x3 ;
V_220 |= 0x1 ;
F_2 ( V_220 , V_411 + V_418 ) ;
}
V_220 = F_3 ( V_411 + V_412 ) ;
V_220 &= ~ V_56 ;
V_220 |= V_18 -> signal [ V_3 ] . V_413 ;
V_220 |= V_18 -> signal [ V_3 ] . V_414 ;
F_2 ( V_220 , V_411 + V_412 ) ;
}
static void F_145 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
F_146 ( V_18 , V_12 , V_3 ) ;
F_147 ( 0x028 ) ;
F_2 ( 0x11f , V_25 + V_188 ) ;
F_147 ( 0x004 ) ;
F_147 ( 0x008 ) ;
F_147 ( 0x00c ) ;
F_147 ( 0x010 ) ;
F_147 ( 0x014 ) ;
F_147 ( 0x018 ) ;
F_147 ( 0x01c ) ;
F_147 ( 0x024 ) ;
F_147 ( 0x020 ) ;
F_147 ( 0x02c ) ;
F_2 ( 0xbc , V_25 + V_419 ) ;
}
static void F_148 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_7 )
{
void T_1 * V_13 = F_6 ( V_12 , V_7 ) ;
T_2 V_220 ;
F_147 ( 0x00c ) ;
F_147 ( 0x010 ) ;
F_147 ( 0x014 ) ;
F_147 ( 0x018 ) ;
V_220 = F_3 ( V_13 + 0x20 ) ;
V_220 &= 0x1c1c1c1c ;
V_220 |= 0x03030303 ;
F_2 ( V_220 , V_13 + 0x20 ) ;
}
static int F_149 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_420 )
{
unsigned int V_7 , V_3 ;
for ( V_7 = 0 ; V_7 < V_420 ; V_7 ++ ) {
for ( V_3 = 0 ; V_3 < V_87 ; V_3 ++ )
F_145 ( V_18 , V_12 ,
( V_7 * V_87 ) + V_3 ) ;
F_148 ( V_18 , V_12 , V_7 ) ;
}
return 0 ;
}
static void F_140 ( struct V_15 * V_16 , void T_1 * V_12 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
T_2 V_220 ;
V_220 = F_3 ( V_12 + V_421 ) ;
V_220 &= 0xff00ffff ;
F_2 ( V_220 , V_12 + V_421 ) ;
F_147 ( V_422 ) ;
F_147 ( V_423 ) ;
F_2 ( 0x000100ff , V_12 + V_424 ) ;
F_147 ( V_425 ) ;
F_147 ( V_18 -> V_397 ) ;
F_147 ( V_18 -> V_426 ) ;
F_147 ( V_427 ) ;
F_147 ( V_428 ) ;
F_147 ( V_429 ) ;
F_147 ( V_430 ) ;
}
static void F_150 ( struct V_17 * V_18 , void T_1 * V_12 )
{
T_2 V_220 ;
F_141 ( V_18 , V_12 ) ;
V_220 = F_3 ( V_12 + V_169 ) ;
V_220 &= 0x3 ;
V_220 |= ( 1 << 5 ) | ( 1 << 6 ) ;
F_2 ( V_220 , V_12 + V_169 ) ;
}
static int F_151 ( struct V_17 * V_18 , void T_1 * V_12 ,
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
F_36 (KERN_ERR DRV_NAME L_38 ) ;
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
F_36 (KERN_ERR DRV_NAME L_39 ) ;
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
F_36 (KERN_ERR DRV_NAME L_40 ) ;
V_432 = 1 ;
}
V_436:
return V_432 ;
}
static void F_152 ( struct V_17 * V_18 , int V_410 ,
void T_1 * V_12 )
{
void T_1 * V_25 ;
T_2 V_220 ;
V_220 = F_3 ( V_12 + V_438 ) ;
if ( ( V_220 & ( 1 << 0 ) ) == 0 ) {
V_18 -> signal [ V_410 ] . V_414 = 0x7 << 8 ;
V_18 -> signal [ V_410 ] . V_413 = 0x1 << 5 ;
return;
}
V_25 = F_8 ( V_12 , V_410 ) ;
V_220 = F_3 ( V_25 + V_439 ) ;
V_18 -> signal [ V_410 ] . V_414 = V_220 & 0x700 ;
V_18 -> signal [ V_410 ] . V_413 = V_220 & 0xe0 ;
}
static void F_153 ( struct V_17 * V_18 , void T_1 * V_12 )
{
F_2 ( 0x00000060 , V_12 + V_169 ) ;
}
static void F_154 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
T_2 V_172 = V_18 -> V_172 ;
int V_440 =
V_172 & ( V_441 | V_204 ) ;
int V_442 =
V_172 & ( V_441 | V_204 ) ;
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
static void F_155 ( struct V_17 * V_18 ,
void T_1 * V_12 )
{
return;
}
static void F_156 ( struct V_17 * V_18 , int V_410 ,
void T_1 * V_12 )
{
void T_1 * V_25 ;
T_2 V_220 ;
V_25 = F_8 ( V_12 , V_410 ) ;
V_220 = F_3 ( V_25 + V_439 ) ;
V_18 -> signal [ V_410 ] . V_414 = V_220 & 0x700 ;
V_18 -> signal [ V_410 ] . V_413 = V_220 & 0xe0 ;
}
static void F_157 ( struct V_17 * V_18 ,
void T_1 * V_12 , unsigned int V_3 )
{
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
F_146 ( V_18 , V_12 , V_3 ) ;
F_147 ( 0x028 ) ;
F_2 ( 0x101f , V_25 + V_188 ) ;
F_147 ( 0x004 ) ;
F_147 ( 0x008 ) ;
F_147 ( 0x00c ) ;
F_147 ( 0x010 ) ;
F_147 ( 0x014 ) ;
F_147 ( 0x018 ) ;
F_147 ( 0x01c ) ;
F_147 ( 0x024 ) ;
F_147 ( 0x020 ) ;
F_147 ( 0x02c ) ;
F_2 ( 0x800 , V_25 + V_419 ) ;
}
static void F_158 ( struct V_17 * V_18 ,
void T_1 * V_12 )
{
void T_1 * V_13 = F_6 ( V_12 , 0 ) ;
F_147 ( 0x00c ) ;
F_147 ( 0x010 ) ;
F_147 ( 0x014 ) ;
}
static int F_159 ( struct V_17 * V_18 ,
void T_1 * V_12 , unsigned int V_420 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < V_18 -> V_86 ; V_3 ++ )
F_157 ( V_18 , V_12 , V_3 ) ;
F_158 ( V_18 , V_12 ) ;
return 0 ;
}
static void F_160 ( struct V_17 * V_18 ,
void T_1 * V_12 )
{
return;
}
static void F_161 ( struct V_15 * V_16 , void T_1 * V_12 )
{
return;
}
static void F_162 ( struct V_17 * V_18 ,
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
static bool F_163 ( struct V_17 * V_18 )
{
void T_1 * V_455 = F_8 ( V_18 -> V_6 , 0 ) ;
if ( F_3 ( V_455 + V_456 ) )
return true ;
return false ;
}
static void F_164 ( void T_1 * V_25 , int V_457 )
{
T_2 V_458 = F_3 ( V_25 + V_459 ) ;
V_458 = ( V_458 & 0xf7f ) | 0x9b1000 ;
if ( V_457 )
V_458 |= ( 1 << 7 ) ;
F_1 ( V_458 , V_25 + V_459 ) ;
}
static void F_146 ( struct V_17 * V_18 , void T_1 * V_12 ,
unsigned int V_22 )
{
void T_1 * V_25 = F_8 ( V_12 , V_22 ) ;
F_32 ( V_25 ) ;
F_1 ( V_460 , V_25 + V_108 ) ;
if ( ! F_25 ( V_18 ) ) {
F_164 ( V_25 , 1 ) ;
}
F_1 ( V_460 , V_25 + V_108 ) ;
F_31 ( 25 ) ;
F_1 ( 0 , V_25 + V_108 ) ;
V_18 -> V_241 -> V_461 ( V_18 , V_12 , V_22 ) ;
if ( F_25 ( V_18 ) )
F_165 ( 1 ) ;
}
static void F_94 ( struct V_20 * V_21 , int V_272 )
{
if ( F_166 ( V_21 ) ) {
void T_1 * V_25 = F_11 ( V_21 ) ;
T_2 V_118 = F_3 ( V_25 + V_315 ) ;
int V_37 = V_118 & 0xf ;
if ( V_37 != V_272 ) {
V_118 = ( V_118 & ~ 0xf ) | V_272 ;
F_1 ( V_118 , V_25 + V_315 ) ;
}
}
}
static int F_167 ( struct V_144 * V_145 , unsigned int * V_462 ,
unsigned long V_463 )
{
F_94 ( V_145 -> V_21 , F_168 ( V_145 ) ) ;
return F_169 ( V_145 , V_462 , V_463 ) ;
}
static int F_170 ( struct V_144 * V_145 , unsigned int * V_462 ,
unsigned long V_463 )
{
F_94 ( V_145 -> V_21 , F_168 ( V_145 ) ) ;
return F_171 ( V_145 , V_462 , V_463 ) ;
}
static int F_172 ( struct V_144 * V_145 , unsigned int * V_462 ,
unsigned long V_463 )
{
struct V_20 * V_21 = V_145 -> V_21 ;
struct V_17 * V_18 = V_21 -> V_16 -> V_19 ;
struct V_26 * V_27 = V_21 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
int V_432 , V_464 = 0 , V_465 = 0 ;
T_2 V_466 ;
bool V_467 ;
F_146 ( V_18 , V_12 , V_21 -> V_22 ) ;
V_27 -> V_103 &= ~ V_104 ;
V_27 -> V_103 &=
~ ( V_181 | V_106 | V_182 ) ;
do {
const unsigned long * V_468 =
F_173 ( & V_145 -> V_469 ) ;
V_432 = F_174 ( V_145 , V_468 , V_463 + V_465 ,
& V_467 , NULL ) ;
V_432 = V_467 ? - V_470 : V_432 ;
if ( V_432 )
return V_432 ;
F_116 ( V_145 , V_138 , & V_466 ) ;
if ( ! F_25 ( V_18 ) && ++ V_464 >= 5 && V_466 == 0x121 ) {
F_164 ( F_11 ( V_21 ) , 0 ) ;
if ( F_175 ( V_471 + V_472 , V_463 ) )
V_465 = V_472 ;
}
} while ( V_466 != 0x0 && V_466 != 0x113 && V_466 != 0x123 );
F_13 ( V_21 ) ;
F_29 ( V_21 , 0 , 0 ) ;
return V_432 ;
}
static void F_111 ( struct V_20 * V_21 )
{
F_28 ( V_21 ) ;
F_19 ( V_21 , 0 ) ;
}
static void F_176 ( struct V_20 * V_21 )
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
static void F_177 ( struct V_473 * V_3 , void T_1 * V_25 )
{
void T_1 * V_361 , * V_474 = V_25 + V_475 ;
V_3 -> V_476 = V_474 + ( sizeof( T_2 ) * V_477 ) ;
V_3 -> V_478 =
V_3 -> V_479 = V_474 + ( sizeof( T_2 ) * V_480 ) ;
V_3 -> V_481 = V_474 + ( sizeof( T_2 ) * V_284 ) ;
V_3 -> V_482 = V_474 + ( sizeof( T_2 ) * V_292 ) ;
V_3 -> V_483 = V_474 + ( sizeof( T_2 ) * V_295 ) ;
V_3 -> V_484 = V_474 + ( sizeof( T_2 ) * V_298 ) ;
V_3 -> V_485 = V_474 + ( sizeof( T_2 ) * V_300 ) ;
V_3 -> V_306 =
V_3 -> V_486 = V_474 + ( sizeof( T_2 ) * V_487 ) ;
V_3 -> V_254 = V_3 -> V_488 = V_474 + V_489 ;
V_361 = V_25 + F_41 ( V_140 ) ;
F_1 ( F_3 ( V_361 ) , V_361 ) ;
F_1 ( 0 , V_25 + V_75 ) ;
F_1 ( ~ V_356 , V_25 + V_490 ) ;
F_178 ( L_41 ,
F_3 ( V_25 + V_188 ) ,
F_3 ( V_25 + V_75 ) ,
F_3 ( V_25 + V_490 ) ) ;
}
static unsigned int F_179 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
T_2 V_118 ;
if ( F_56 ( V_18 ) || ! F_180 ( V_18 ) )
return 0 ;
V_118 = F_3 ( V_12 + V_421 ) ;
if ( ( V_118 & V_491 ) == 0 )
return 0 ;
return 1 ;
}
static int F_181 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
T_2 V_118 ;
if ( ! F_179 ( V_16 ) ) {
V_118 = F_3 ( V_12 + V_492 ) ;
if ( V_118 & V_493 )
return 0 ;
}
return 1 ;
}
static void F_182 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
if ( F_179 ( V_16 ) ) {
T_2 V_118 = F_3 ( V_12 + V_492 ) ;
F_1 ( V_118 & ~ V_494 , V_12 + V_492 ) ;
}
}
static int F_183 ( struct V_15 * V_16 , unsigned int V_495 )
{
struct V_126 * V_127 = F_130 ( V_16 -> V_154 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
T_2 V_172 = V_18 -> V_172 ;
switch ( V_495 ) {
case V_496 :
V_18 -> V_241 = & V_497 ;
V_172 |= V_498 ;
switch ( V_127 -> V_407 ) {
case 0x1 :
V_172 |= V_416 ;
break;
case 0x3 :
V_172 |= V_499 ;
break;
default:
F_129 ( V_318 , & V_127 -> V_154 ,
L_42 ) ;
V_172 |= V_499 ;
break;
}
break;
case V_500 :
case V_501 :
V_18 -> V_241 = & V_497 ;
V_172 |= V_498 ;
switch ( V_127 -> V_407 ) {
case 0x0 :
V_172 |= V_416 ;
break;
case 0x3 :
V_172 |= V_499 ;
break;
default:
F_129 ( V_318 , & V_127 -> V_154 ,
L_43 ) ;
V_172 |= V_499 ;
break;
}
break;
case V_502 :
case V_503 :
V_18 -> V_241 = & V_504 ;
V_172 |= V_505 ;
switch ( V_127 -> V_407 ) {
case 0x7 :
F_182 ( V_16 ) ;
V_172 |= V_441 ;
break;
case 0x9 :
V_172 |= V_204 ;
break;
default:
F_129 ( V_318 , & V_127 -> V_154 ,
L_43 ) ;
V_172 |= V_441 ;
break;
}
break;
case V_506 :
V_172 |= V_507 | V_186 ;
if ( V_127 -> V_508 == V_509 &&
( V_127 -> V_198 == 0x2300 || V_127 -> V_198 == 0x2310 ) )
{
F_36 (KERN_WARNING DRV_NAME L_44
L_45
L_46
L_47 ) ;
F_36 (KERN_WARNING DRV_NAME L_48
L_49
L_50
L_51 ) ;
}
case V_510 :
V_18 -> V_241 = & V_504 ;
V_172 |= V_511 ;
if ( V_495 == V_510 && F_181 ( V_16 ) )
V_172 |= V_186 ;
switch ( V_127 -> V_407 ) {
case 0x2 :
V_172 |= V_204 ;
break;
default:
F_129 ( V_318 , & V_127 -> V_154 ,
L_52 ) ;
V_172 |= V_204 ;
break;
}
break;
case V_512 :
if ( F_163 ( V_18 ) )
V_18 -> V_241 = & V_513 ;
else
V_18 -> V_241 = & V_514 ;
V_172 |= V_515 | V_511 |
V_204 ;
break;
default:
F_129 ( V_121 , V_16 -> V_154 ,
L_53 , V_495 ) ;
return 1 ;
}
V_18 -> V_172 = V_172 ;
if ( V_172 & V_507 ) {
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
static int F_184 ( struct V_15 * V_16 )
{
int V_432 = 0 , V_420 , V_3 , V_7 ;
struct V_17 * V_18 = V_16 -> V_19 ;
void T_1 * V_12 = V_18 -> V_6 ;
V_432 = F_183 ( V_16 , V_18 -> V_495 ) ;
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
V_420 = F_12 ( V_16 -> V_177 [ 0 ] -> V_83 ) ;
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ )
if ( V_18 -> V_241 -> V_527 )
V_18 -> V_241 -> V_527 ( V_18 , V_3 , V_12 ) ;
V_432 = V_18 -> V_241 -> V_528 ( V_18 , V_12 , V_420 ) ;
if ( V_432 )
goto V_436;
V_18 -> V_241 -> V_529 ( V_18 , V_12 ) ;
V_18 -> V_241 -> V_530 ( V_16 , V_12 ) ;
V_18 -> V_241 -> V_531 ( V_18 , V_12 ) ;
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ ) {
struct V_20 * V_21 = V_16 -> V_177 [ V_3 ] ;
void T_1 * V_25 = F_8 ( V_12 , V_3 ) ;
F_177 ( & V_21 -> V_253 , V_25 ) ;
}
for ( V_7 = 0 ; V_7 < V_420 ; V_7 ++ ) {
void T_1 * V_13 = F_6 ( V_12 , V_7 ) ;
F_178 ( L_54
L_55 , V_7 ,
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
static int F_185 ( struct V_17 * V_18 , struct V_198 * V_154 )
{
V_18 -> V_191 = F_186 ( L_56 , V_154 , V_201 ,
V_201 , 0 ) ;
if ( ! V_18 -> V_191 )
return - V_200 ;
V_18 -> V_193 = F_186 ( L_57 , V_154 , V_203 ,
V_203 , 0 ) ;
if ( ! V_18 -> V_193 )
return - V_200 ;
V_18 -> V_196 = F_186 ( L_58 , V_154 , V_535 ,
V_535 , 0 ) ;
if ( ! V_18 -> V_196 )
return - V_200 ;
return 0 ;
}
static void F_187 ( struct V_17 * V_18 ,
struct V_536 * V_537 )
{
int V_114 ;
for ( V_114 = 0 ; V_114 < 4 ; V_114 ++ ) {
F_2 ( 0 , V_18 -> V_6 + F_188 ( V_114 ) ) ;
F_2 ( 0 , V_18 -> V_6 + F_189 ( V_114 ) ) ;
}
for ( V_114 = 0 ; V_114 < V_537 -> V_538 ; V_114 ++ ) {
struct V_539 * V_540 = V_537 -> V_540 + V_114 ;
F_2 ( ( ( V_540 -> V_541 - 1 ) & 0xffff0000 ) |
( V_540 -> V_542 << 8 ) |
( V_537 -> V_543 << 4 ) | 1 ,
V_18 -> V_6 + F_188 ( V_114 ) ) ;
F_2 ( V_540 -> V_6 , V_18 -> V_6 + F_189 ( V_114 ) ) ;
}
}
static int F_190 ( struct V_544 * V_127 )
{
static int V_545 ;
const struct V_546 * V_547 ;
const struct V_548 * V_549 [] =
{ & V_550 [ V_512 ] , NULL } ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
struct V_551 * V_552 ;
int V_86 , V_432 ;
if ( ! V_545 ++ )
F_129 ( V_151 , & V_127 -> V_154 , L_59 V_553 L_4 ) ;
if ( F_48 ( V_127 -> V_554 != 2 ) ) {
F_191 ( & V_127 -> V_154 , L_60 ) ;
return - V_147 ;
}
V_552 = F_192 ( V_127 , V_555 , 0 ) ;
if ( V_552 == NULL )
return - V_147 ;
V_547 = V_127 -> V_154 . V_556 ;
V_86 = V_547 -> V_86 ;
V_16 = F_193 ( & V_127 -> V_154 , V_549 , V_86 ) ;
V_18 = F_60 ( & V_127 -> V_154 , sizeof( * V_18 ) , V_199 ) ;
if ( ! V_16 || ! V_18 )
return - V_200 ;
V_16 -> V_19 = V_18 ;
V_18 -> V_86 = V_86 ;
V_18 -> V_495 = V_512 ;
V_16 -> V_557 = NULL ;
V_18 -> V_6 = F_194 ( & V_127 -> V_154 , V_552 -> V_122 ,
F_195 ( V_552 ) ) ;
V_18 -> V_6 -= V_8 ;
#if F_196 ( V_558 )
V_18 -> V_559 = F_197 ( & V_127 -> V_154 , NULL ) ;
if ( F_198 ( V_18 -> V_559 ) )
F_199 ( & V_127 -> V_154 , L_61 ) ;
else
F_200 ( V_18 -> V_559 ) ;
#endif
if ( V_547 -> V_537 != NULL )
F_187 ( V_18 , V_547 -> V_537 ) ;
V_432 = F_185 ( V_18 , & V_127 -> V_154 ) ;
if ( V_432 )
goto V_120;
V_432 = F_184 ( V_16 ) ;
if ( V_432 )
goto V_120;
F_129 ( V_151 , & V_127 -> V_154 ,
L_62 , ( unsigned ) V_194 ,
V_16 -> V_86 ) ;
return F_201 ( V_16 , F_202 ( V_127 , 0 ) , F_132 ,
V_560 , & V_561 ) ;
V_120:
#if F_196 ( V_558 )
if ( ! F_198 ( V_18 -> V_559 ) ) {
F_203 ( V_18 -> V_559 ) ;
F_204 ( V_18 -> V_559 ) ;
}
#endif
return V_432 ;
}
static int T_8 F_205 ( struct V_544 * V_127 )
{
struct V_198 * V_154 = & V_127 -> V_154 ;
struct V_15 * V_16 = F_206 ( V_154 ) ;
#if F_196 ( V_558 )
struct V_17 * V_18 = V_16 -> V_19 ;
#endif
F_207 ( V_16 ) ;
#if F_196 ( V_558 )
if ( ! F_198 ( V_18 -> V_559 ) ) {
F_203 ( V_18 -> V_559 ) ;
F_204 ( V_18 -> V_559 ) ;
}
#endif
return 0 ;
}
static int F_208 ( struct V_544 * V_127 , T_9 V_562 )
{
struct V_15 * V_16 = F_206 ( & V_127 -> V_154 ) ;
if ( V_16 )
return F_209 ( V_16 , V_562 ) ;
else
return 0 ;
}
static int F_210 ( struct V_544 * V_127 )
{
struct V_15 * V_16 = F_206 ( & V_127 -> V_154 ) ;
int V_563 ;
if ( V_16 ) {
struct V_17 * V_18 = V_16 -> V_19 ;
const struct V_546 * V_547 = \
V_127 -> V_154 . V_556 ;
if ( V_547 -> V_537 != NULL )
F_187 ( V_18 , V_547 -> V_537 ) ;
V_563 = F_184 ( V_16 ) ;
if ( V_563 ) {
F_36 (KERN_ERR DRV_NAME L_63 ) ;
return V_563 ;
}
F_211 ( V_16 ) ;
}
return 0 ;
}
static int F_212 ( struct V_126 * V_127 )
{
int V_432 ;
if ( ! F_213 ( V_127 , F_214 ( 64 ) ) ) {
V_432 = F_215 ( V_127 , F_214 ( 64 ) ) ;
if ( V_432 ) {
V_432 = F_215 ( V_127 , F_214 ( 32 ) ) ;
if ( V_432 ) {
F_129 ( V_121 , & V_127 -> V_154 ,
L_64 ) ;
return V_432 ;
}
}
} else {
V_432 = F_213 ( V_127 , F_214 ( 32 ) ) ;
if ( V_432 ) {
F_129 ( V_121 , & V_127 -> V_154 ,
L_65 ) ;
return V_432 ;
}
V_432 = F_215 ( V_127 , F_214 ( 32 ) ) ;
if ( V_432 ) {
F_129 ( V_121 , & V_127 -> V_154 ,
L_66 ) ;
return V_432 ;
}
}
return V_432 ;
}
static void F_216 ( struct V_15 * V_16 )
{
struct V_126 * V_127 = F_130 ( V_16 -> V_154 ) ;
struct V_17 * V_18 = V_16 -> V_19 ;
T_3 V_564 ;
const char * V_565 , * V_566 ;
F_217 ( V_127 , V_567 , & V_564 ) ;
if ( V_564 == 0 )
V_565 = L_67 ;
else if ( V_564 == 0x01 )
V_565 = L_68 ;
else
V_565 = L_69 ;
if ( F_25 ( V_18 ) )
V_566 = L_70 ;
else if ( F_55 ( V_18 ) )
V_566 = L_71 ;
else if ( F_22 ( V_18 ) )
V_566 = L_72 ;
else
V_566 = L_69 ;
F_129 ( V_151 , & V_127 -> V_154 ,
L_73 ,
V_566 , ( unsigned ) V_194 , V_16 -> V_86 ,
V_565 , ( V_402 & V_18 -> V_172 ) ? L_74 : L_75 ) ;
}
static int F_218 ( struct V_126 * V_127 ,
const struct V_568 * V_569 )
{
static int V_545 ;
unsigned int V_495 = ( unsigned int ) V_569 -> V_570 ;
const struct V_548 * V_549 [] = { & V_550 [ V_495 ] , NULL } ;
struct V_15 * V_16 ;
struct V_17 * V_18 ;
int V_86 , V_3 , V_432 ;
if ( ! V_545 ++ )
F_129 ( V_151 , & V_127 -> V_154 , L_59 V_553 L_4 ) ;
V_86 = F_12 ( V_549 [ 0 ] -> V_83 ) * V_87 ;
V_16 = F_193 ( & V_127 -> V_154 , V_549 , V_86 ) ;
V_18 = F_60 ( & V_127 -> V_154 , sizeof( * V_18 ) , V_199 ) ;
if ( ! V_16 || ! V_18 )
return - V_200 ;
V_16 -> V_19 = V_18 ;
V_18 -> V_86 = V_86 ;
V_18 -> V_495 = V_495 ;
V_432 = F_219 ( V_127 ) ;
if ( V_432 )
return V_432 ;
V_432 = F_220 ( V_127 , 1 << V_571 , V_332 ) ;
if ( V_432 == - V_572 )
F_221 ( V_127 ) ;
if ( V_432 )
return V_432 ;
V_16 -> V_557 = F_222 ( V_127 ) ;
V_18 -> V_6 = V_16 -> V_557 [ V_571 ] ;
V_432 = F_212 ( V_127 ) ;
if ( V_432 )
return V_432 ;
V_432 = F_185 ( V_18 , & V_127 -> V_154 ) ;
if ( V_432 )
return V_432 ;
for ( V_3 = 0 ; V_3 < V_16 -> V_86 ; V_3 ++ ) {
struct V_20 * V_21 = V_16 -> V_177 [ V_3 ] ;
void T_1 * V_25 = F_8 ( V_18 -> V_6 , V_3 ) ;
unsigned int V_212 = V_25 - V_18 -> V_6 ;
F_223 ( V_21 , V_571 , - 1 , L_76 ) ;
F_223 ( V_21 , V_571 , V_212 , L_77 ) ;
}
V_432 = F_184 ( V_16 ) ;
if ( V_432 )
return V_432 ;
if ( V_573 && F_224 ( V_127 ) == 0 )
V_18 -> V_172 |= V_402 ;
F_37 ( V_127 , 0x68 ) ;
F_216 ( V_16 ) ;
F_225 ( V_127 ) ;
F_226 ( V_127 ) ;
return F_201 ( V_16 , V_127 -> V_399 , F_132 , V_560 ,
F_25 ( V_18 ) ? & V_574 : & V_561 ) ;
}
static int F_227 ( struct V_126 * V_127 )
{
struct V_15 * V_16 = F_206 ( & V_127 -> V_154 ) ;
int V_432 ;
V_432 = F_228 ( V_127 ) ;
if ( V_432 )
return V_432 ;
V_432 = F_184 ( V_16 ) ;
if ( V_432 )
return V_432 ;
F_211 ( V_16 ) ;
return 0 ;
}
static int T_10 F_229 ( void )
{
int V_432 = - V_575 ;
#ifdef F_230
V_432 = F_231 ( & V_576 ) ;
if ( V_432 < 0 )
return V_432 ;
#endif
V_432 = F_232 ( & V_577 ) ;
#ifdef F_230
if ( V_432 < 0 )
F_233 ( & V_576 ) ;
#endif
return V_432 ;
}
static void T_11 F_234 ( void )
{
#ifdef F_230
F_233 ( & V_576 ) ;
#endif
F_235 ( & V_577 ) ;
}
