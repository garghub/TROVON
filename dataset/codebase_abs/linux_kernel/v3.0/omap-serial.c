static inline unsigned int F_1 ( struct V_1 * V_2 , int V_3 )
{
V_3 <<= V_2 -> V_4 . V_5 ;
return F_2 ( V_2 -> V_4 . V_6 + V_3 ) ;
}
static inline void F_3 ( struct V_1 * V_2 , int V_3 , int V_7 )
{
V_3 <<= V_2 -> V_4 . V_5 ;
F_4 ( V_7 , V_2 -> V_4 . V_6 + V_3 ) ;
}
static inline void F_5 ( struct V_1 * V_2 )
{
F_3 ( V_2 , V_8 , V_9 ) ;
F_3 ( V_2 , V_8 , V_9 |
V_10 | V_11 ) ;
F_3 ( V_2 , V_8 , 0 ) ;
}
static unsigned int
F_6 ( struct V_12 * V_4 , unsigned int V_13 )
{
unsigned int V_14 ;
if ( V_13 > V_15 && V_13 != 3000000 )
V_14 = 13 ;
else
V_14 = 16 ;
return V_4 -> V_16 / ( V_13 * V_14 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
if ( V_2 -> V_17 . V_18 ) {
F_8 ( & V_2 -> V_17 . V_19 ) ;
F_9 ( V_2 -> V_17 . V_20 ) ;
F_10 ( V_2 -> V_17 . V_20 ) ;
V_2 -> V_17 . V_20 = V_21 ;
V_2 -> V_17 . V_18 = false ;
}
}
static void F_11 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_12 ( V_2 -> V_4 . V_22 , L_1 , V_2 -> V_23 -> V_24 ) ;
V_2 -> V_25 |= V_26 ;
F_3 ( V_2 , V_27 , V_2 -> V_25 ) ;
}
static void F_13 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( V_2 -> V_28 &&
V_2 -> V_17 . V_29 != V_21 ) {
if ( F_14 ( V_2 -> V_17 . V_29 ) )
return;
F_9 ( V_2 -> V_17 . V_29 ) ;
F_10 ( V_2 -> V_17 . V_29 ) ;
V_2 -> V_17 . V_29 = V_21 ;
}
if ( V_2 -> V_25 & V_30 ) {
V_2 -> V_25 &= ~ V_30 ;
F_3 ( V_2 , V_27 , V_2 -> V_25 ) ;
}
}
static void F_15 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
if ( V_2 -> V_28 )
F_7 ( V_2 ) ;
V_2 -> V_25 &= ~ V_31 ;
V_2 -> V_4 . V_32 &= ~ V_33 ;
F_3 ( V_2 , V_27 , V_2 -> V_25 ) ;
}
static inline void F_16 ( struct V_1 * V_2 , int * V_34 )
{
struct V_35 * V_36 = V_2 -> V_4 . V_37 -> V_4 . V_36 ;
unsigned int V_38 ;
unsigned char V_39 , V_40 = * V_34 ;
int V_41 = 256 ;
do {
if ( F_17 ( V_40 & V_33 ) )
V_39 = F_1 ( V_2 , V_42 ) ;
V_38 = V_43 ;
V_2 -> V_4 . V_44 . V_45 ++ ;
if ( F_18 ( V_40 & V_46 ) ) {
if ( V_40 & V_47 ) {
V_40 &= ~ ( V_48 | V_49 ) ;
V_2 -> V_4 . V_44 . V_50 ++ ;
if ( F_19 ( & V_2 -> V_4 ) )
goto V_51;
} else if ( V_40 & V_49 ) {
V_2 -> V_4 . V_44 . V_52 ++ ;
} else if ( V_40 & V_48 ) {
V_2 -> V_4 . V_44 . V_53 ++ ;
}
if ( V_40 & V_54 )
V_2 -> V_4 . V_44 . V_55 ++ ;
V_40 &= V_2 -> V_4 . V_32 ;
#ifdef F_20
if ( V_2 -> V_4 . line == V_2 -> V_4 . V_56 -> V_57 ) {
V_40 |= V_2 -> V_58 ;
}
#endif
if ( V_40 & V_47 )
V_38 = V_59 ;
else if ( V_40 & V_49 )
V_38 = V_60 ;
else if ( V_40 & V_48 )
V_38 = V_61 ;
}
if ( F_21 ( & V_2 -> V_4 , V_39 ) )
goto V_51;
F_22 ( & V_2 -> V_4 , V_40 , V_54 , V_39 , V_38 ) ;
V_51:
V_40 = F_1 ( V_2 , V_62 ) ;
} while ( ( V_40 & ( V_33 | V_47 ) ) && ( V_41 -- > 0 ) );
F_23 ( & V_2 -> V_4 . V_63 ) ;
F_24 ( V_36 ) ;
F_25 ( & V_2 -> V_4 . V_63 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = & V_2 -> V_4 . V_37 -> V_65 ;
int V_66 ;
if ( V_2 -> V_4 . V_67 ) {
F_3 ( V_2 , V_68 , V_2 -> V_4 . V_67 ) ;
V_2 -> V_4 . V_44 . V_69 ++ ;
V_2 -> V_4 . V_67 = 0 ;
return;
}
if ( F_27 ( V_65 ) || F_28 ( & V_2 -> V_4 ) ) {
F_13 ( & V_2 -> V_4 ) ;
return;
}
V_66 = V_2 -> V_4 . V_70 / 4 ;
do {
F_3 ( V_2 , V_68 , V_65 -> V_71 [ V_65 -> V_72 ] ) ;
V_65 -> V_72 = ( V_65 -> V_72 + 1 ) & ( V_73 - 1 ) ;
V_2 -> V_4 . V_44 . V_69 ++ ;
if ( F_27 ( V_65 ) )
break;
} while ( -- V_66 > 0 );
if ( F_29 ( V_65 ) < V_74 )
F_30 ( & V_2 -> V_4 ) ;
if ( F_27 ( V_65 ) )
F_13 ( & V_2 -> V_4 ) ;
}
static inline void F_31 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_25 & V_30 ) ) {
V_2 -> V_25 |= V_30 ;
F_3 ( V_2 , V_27 , V_2 -> V_25 ) ;
}
}
static void F_32 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
struct V_64 * V_65 ;
unsigned int V_75 ;
int V_76 = 0 ;
if ( ! V_2 -> V_28 ) {
F_31 ( V_2 ) ;
return;
}
if ( V_2 -> V_17 . V_77 )
return;
V_65 = & V_2 -> V_4 . V_37 -> V_65 ;
if ( V_2 -> V_17 . V_29 == V_21 ) {
V_76 = F_33 ( V_2 -> V_17 . V_78 ,
L_2 ,
( void * ) V_79 , V_2 ,
& ( V_2 -> V_17 . V_29 ) ) ;
if ( V_76 < 0 ) {
F_31 ( V_2 ) ;
return;
}
}
F_25 ( & ( V_2 -> V_17 . V_80 ) ) ;
V_2 -> V_17 . V_77 = true ;
F_23 ( & ( V_2 -> V_17 . V_80 ) ) ;
V_75 = V_2 -> V_17 . V_81 +
( V_65 -> V_72 & ( V_73 - 1 ) ) ;
V_2 -> V_17 . V_82 = F_29 ( V_65 ) ;
if ( V_75 + V_2 -> V_17 . V_82 >=
V_2 -> V_17 . V_81 + V_73 )
V_2 -> V_17 . V_82 =
( V_2 -> V_17 . V_81 +
V_73 ) - V_75 ;
F_34 ( V_2 -> V_17 . V_29 , 0 ,
V_83 ,
V_2 -> V_17 . V_84 , 0 , 0 ) ;
F_35 ( V_2 -> V_17 . V_29 , 0 ,
V_85 , V_75 , 0 , 0 ) ;
F_36 ( V_2 -> V_17 . V_29 ,
V_86 ,
V_2 -> V_17 . V_82 , 1 ,
V_87 ,
V_2 -> V_17 . V_78 , 0 ) ;
F_37 ( V_2 -> V_17 . V_29 ) ;
}
static unsigned int F_38 ( struct V_1 * V_2 )
{
unsigned int V_34 ;
V_34 = F_1 ( V_2 , V_88 ) ;
V_34 |= V_2 -> V_89 ;
V_2 -> V_89 = 0 ;
if ( ( V_34 & V_90 ) == 0 )
return V_34 ;
if ( V_34 & V_90 && V_2 -> V_25 & V_26 &&
V_2 -> V_4 . V_37 != NULL ) {
if ( V_34 & V_91 )
V_2 -> V_4 . V_44 . V_92 ++ ;
if ( V_34 & V_93 )
V_2 -> V_4 . V_44 . V_94 ++ ;
if ( V_34 & V_95 )
F_39
( & V_2 -> V_4 , V_34 & V_96 ) ;
if ( V_34 & V_97 )
F_40
( & V_2 -> V_4 , V_34 & V_98 ) ;
F_41 ( & V_2 -> V_4 . V_37 -> V_4 . V_99 ) ;
}
return V_34 ;
}
static inline T_1 F_42 ( int V_100 , void * V_101 )
{
struct V_1 * V_2 = V_101 ;
unsigned int V_102 , V_40 ;
unsigned long V_103 ;
V_102 = F_1 ( V_2 , V_104 ) ;
if ( V_102 & V_105 )
return V_106 ;
F_43 ( & V_2 -> V_4 . V_63 , V_103 ) ;
V_40 = F_1 ( V_2 , V_62 ) ;
if ( V_102 & V_107 ) {
if ( ! V_2 -> V_28 ) {
if ( V_40 & V_33 )
F_16 ( V_2 , & V_40 ) ;
} else {
V_2 -> V_25 &= ~ ( V_108 | V_31 ) ;
F_3 ( V_2 , V_27 , V_2 -> V_25 ) ;
if ( ( F_44 ( V_2 ) != 0 ) &&
( V_40 & V_33 ) )
F_16 ( V_2 , & V_40 ) ;
}
}
F_38 ( V_2 ) ;
if ( ( V_40 & V_109 ) && ( V_102 & V_110 ) )
F_26 ( V_2 ) ;
F_45 ( & V_2 -> V_4 . V_63 , V_103 ) ;
V_2 -> V_111 = V_112 ;
return V_113 ;
}
static unsigned int F_46 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_103 = 0 ;
unsigned int V_76 = 0 ;
F_12 ( V_2 -> V_4 . V_22 , L_3 , V_2 -> V_23 -> V_24 ) ;
F_43 ( & V_2 -> V_4 . V_63 , V_103 ) ;
V_76 = F_1 ( V_2 , V_62 ) & V_114 ? V_115 : 0 ;
F_45 ( & V_2 -> V_4 . V_63 , V_103 ) ;
return V_76 ;
}
static unsigned int F_47 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_34 ;
unsigned int V_76 = 0 ;
V_34 = F_38 ( V_2 ) ;
F_12 ( V_2 -> V_4 . V_22 , L_4 , V_2 -> V_23 -> V_24 ) ;
if ( V_34 & V_96 )
V_76 |= V_116 ;
if ( V_34 & V_117 )
V_76 |= V_118 ;
if ( V_34 & V_119 )
V_76 |= V_120 ;
if ( V_34 & V_98 )
V_76 |= V_121 ;
return V_76 ;
}
static void F_48 ( struct V_12 * V_4 , unsigned int V_122 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_123 = 0 ;
F_12 ( V_2 -> V_4 . V_22 , L_5 , V_2 -> V_23 -> V_24 ) ;
if ( V_122 & V_124 )
V_123 |= V_125 ;
if ( V_122 & V_126 )
V_123 |= V_127 ;
if ( V_122 & V_128 )
V_123 |= V_129 ;
if ( V_122 & V_130 )
V_123 |= V_131 ;
if ( V_122 & V_132 )
V_123 |= V_133 ;
V_123 |= V_2 -> V_123 ;
F_3 ( V_2 , V_134 , V_123 ) ;
}
static void F_49 ( struct V_12 * V_4 , int V_135 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_103 = 0 ;
F_12 ( V_2 -> V_4 . V_22 , L_6 , V_2 -> V_23 -> V_24 ) ;
F_43 ( & V_2 -> V_4 . V_63 , V_103 ) ;
if ( V_135 == - 1 )
V_2 -> V_136 |= V_137 ;
else
V_2 -> V_136 &= ~ V_137 ;
F_3 ( V_2 , V_138 , V_2 -> V_136 ) ;
F_45 ( & V_2 -> V_4 . V_63 , V_103 ) ;
}
static int F_50 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_103 = 0 ;
int V_139 ;
V_139 = F_51 ( V_2 -> V_4 . V_100 , F_42 , V_2 -> V_4 . V_140 ,
V_2 -> V_141 , V_2 ) ;
if ( V_139 )
return V_139 ;
F_12 ( V_2 -> V_4 . V_22 , L_7 , V_2 -> V_23 -> V_24 ) ;
F_5 ( V_2 ) ;
F_3 ( V_2 , V_134 , V_125 ) ;
( void ) F_1 ( V_2 , V_62 ) ;
if ( F_1 ( V_2 , V_62 ) & V_33 )
( void ) F_1 ( V_2 , V_42 ) ;
( void ) F_1 ( V_2 , V_104 ) ;
( void ) F_1 ( V_2 , V_88 ) ;
F_3 ( V_2 , V_138 , V_142 ) ;
F_43 ( & V_2 -> V_4 . V_63 , V_103 ) ;
V_2 -> V_4 . V_122 |= V_130 ;
F_48 ( & V_2 -> V_4 , V_2 -> V_4 . V_122 ) ;
F_45 ( & V_2 -> V_4 . V_63 , V_103 ) ;
V_2 -> V_89 = 0 ;
if ( V_2 -> V_28 ) {
F_52 ( ( unsigned long ) V_2 -> V_4 . V_37 -> V_65 . V_71 ) ;
V_2 -> V_4 . V_37 -> V_65 . V_71 = F_53 ( NULL ,
V_73 ,
( V_143 * ) & ( V_2 -> V_17 . V_81 ) ,
0 ) ;
F_54 ( & ( V_2 -> V_17 . V_19 ) ) ;
V_2 -> V_17 . V_19 . V_144 = V_145 ;
V_2 -> V_17 . V_19 . V_146 = V_2 -> V_23 -> V_24 ;
V_2 -> V_17 . V_147 = F_53 ( NULL ,
V_2 -> V_17 . V_148 ,
( V_143 * ) & ( V_2 -> V_17 . V_149 ) , 0 ) ;
}
V_2 -> V_25 = V_31 | V_108 ;
F_3 ( V_2 , V_27 , V_2 -> V_25 ) ;
F_3 ( V_2 , V_150 , V_151 ) ;
V_2 -> V_111 = V_112 ;
return 0 ;
}
static void F_55 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned long V_103 = 0 ;
F_12 ( V_2 -> V_4 . V_22 , L_8 , V_2 -> V_23 -> V_24 ) ;
V_2 -> V_25 = 0 ;
F_3 ( V_2 , V_27 , 0 ) ;
F_43 ( & V_2 -> V_4 . V_63 , V_103 ) ;
V_2 -> V_4 . V_122 &= ~ V_130 ;
F_48 ( & V_2 -> V_4 , V_2 -> V_4 . V_122 ) ;
F_45 ( & V_2 -> V_4 . V_63 , V_103 ) ;
F_3 ( V_2 , V_138 , F_1 ( V_2 , V_138 ) & ~ V_137 ) ;
F_5 ( V_2 ) ;
if ( F_1 ( V_2 , V_62 ) & V_33 )
( void ) F_1 ( V_2 , V_42 ) ;
if ( V_2 -> V_28 ) {
F_56 ( V_2 -> V_4 . V_22 ,
V_73 , V_2 -> V_4 . V_37 -> V_65 . V_71 ,
V_2 -> V_17 . V_81 ) ;
V_2 -> V_4 . V_37 -> V_65 . V_71 = NULL ;
F_15 ( V_4 ) ;
F_56 ( V_2 -> V_4 . V_22 ,
V_2 -> V_17 . V_148 , V_2 -> V_17 . V_147 ,
V_2 -> V_17 . V_149 ) ;
V_2 -> V_17 . V_147 = NULL ;
}
F_57 ( V_2 -> V_4 . V_100 , V_2 ) ;
}
static inline void
F_58
( struct V_1 * V_2 , struct V_152 * V_153 )
{
unsigned char V_154 = 0 ;
V_2 -> V_136 = F_1 ( V_2 , V_138 ) ;
F_3 ( V_2 , V_138 , V_155 ) ;
V_2 -> V_154 = F_1 ( V_2 , V_156 ) ;
F_3 ( V_2 , V_156 , V_2 -> V_154 & ~ V_157 ) ;
F_3 ( V_2 , V_158 , V_153 -> V_159 [ V_160 ] ) ;
F_3 ( V_2 , V_161 , V_153 -> V_159 [ V_162 ] ) ;
V_154 = V_2 -> V_154 ;
V_154 &= V_163 ;
if ( V_153 -> V_164 & V_165 )
V_154 |= V_166 ;
if ( V_153 -> V_164 & V_167 )
V_154 |= V_168 ;
F_3 ( V_2 , V_156 , V_2 -> V_154 | V_157 ) ;
F_3 ( V_2 , V_138 , V_169 ) ;
V_2 -> V_123 = F_1 ( V_2 , V_134 ) ;
if ( V_153 -> V_164 & V_170 )
V_2 -> V_123 |= V_171 ;
F_3 ( V_2 , V_134 , V_2 -> V_123 | V_172 ) ;
F_3 ( V_2 , V_138 , V_155 ) ;
F_3 ( V_2 , V_173 , V_174 ) ;
F_3 ( V_2 , V_156 , V_154 | V_175 ) ;
F_3 ( V_2 , V_138 , V_169 ) ;
F_3 ( V_2 , V_134 , V_2 -> V_123 & ~ V_172 ) ;
F_3 ( V_2 , V_138 , V_2 -> V_136 ) ;
}
static void
F_59 ( struct V_12 * V_4 , struct V_152 * V_153 ,
struct V_152 * V_176 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_177 = 0 ;
unsigned char V_154 = 0 ;
unsigned long V_103 = 0 ;
unsigned int V_13 , V_178 ;
switch ( V_153 -> V_179 & V_180 ) {
case V_181 :
V_177 = V_182 ;
break;
case V_183 :
V_177 = V_184 ;
break;
case V_185 :
V_177 = V_186 ;
break;
default:
case V_187 :
V_177 = V_142 ;
break;
}
if ( V_153 -> V_179 & V_188 )
V_177 |= V_189 ;
if ( V_153 -> V_179 & V_190 )
V_177 |= V_191 ;
if ( ! ( V_153 -> V_179 & V_192 ) )
V_177 |= V_193 ;
V_13 = F_60 ( V_4 , V_153 , V_176 , 0 , V_4 -> V_16 / 13 ) ;
V_178 = F_6 ( V_4 , V_13 ) ;
V_2 -> V_194 = V_195 | V_196 |
V_9 ;
if ( V_2 -> V_28 )
V_2 -> V_194 |= V_197 ;
F_43 ( & V_2 -> V_4 . V_63 , V_103 ) ;
F_61 ( V_4 , V_153 -> V_179 , V_13 ) ;
V_2 -> V_4 . V_32 = V_54 | V_109 | V_33 ;
if ( V_153 -> V_164 & V_198 )
V_2 -> V_4 . V_32 |= V_48 | V_49 ;
if ( V_153 -> V_164 & ( V_199 | V_200 ) )
V_2 -> V_4 . V_32 |= V_47 ;
V_2 -> V_4 . V_201 = 0 ;
if ( V_153 -> V_164 & V_202 )
V_2 -> V_4 . V_201 |= V_49 | V_48 ;
if ( V_153 -> V_164 & V_203 ) {
V_2 -> V_4 . V_201 |= V_47 ;
if ( V_153 -> V_164 & V_202 )
V_2 -> V_4 . V_201 |= V_54 ;
}
if ( ( V_153 -> V_179 & V_204 ) == 0 )
V_2 -> V_4 . V_201 |= V_33 ;
V_2 -> V_25 &= ~ V_26 ;
if ( F_62 ( & V_2 -> V_4 , V_153 -> V_179 ) )
V_2 -> V_25 |= V_26 ;
F_3 ( V_2 , V_27 , V_2 -> V_25 ) ;
F_3 ( V_2 , V_138 , V_177 ) ;
F_3 ( V_2 , V_138 , V_169 ) ;
F_3 ( V_2 , V_205 , 0 ) ;
F_3 ( V_2 , V_206 , 0 ) ;
F_3 ( V_2 , V_138 , 0 ) ;
F_3 ( V_2 , V_138 , V_155 ) ;
V_2 -> V_154 = F_1 ( V_2 , V_156 ) ;
F_3 ( V_2 , V_156 , V_2 -> V_154 | V_157 ) ;
F_3 ( V_2 , V_138 , V_169 ) ;
V_2 -> V_123 = F_1 ( V_2 , V_134 ) ;
F_3 ( V_2 , V_134 , V_2 -> V_123 | V_172 ) ;
F_3 ( V_2 , V_8 , V_2 -> V_194 ) ;
F_3 ( V_2 , V_138 , V_155 ) ;
if ( V_2 -> V_28 ) {
F_3 ( V_2 , V_207 , 0 ) ;
F_3 ( V_2 , V_208 ,
( V_209 | V_210 ) ) ;
}
F_3 ( V_2 , V_156 , V_2 -> V_154 ) ;
F_3 ( V_2 , V_138 , V_169 ) ;
F_3 ( V_2 , V_134 , V_2 -> V_123 ) ;
F_3 ( V_2 , V_211 , V_212 ) ;
F_3 ( V_2 , V_138 , V_155 ) ;
V_2 -> V_154 = F_1 ( V_2 , V_156 ) ;
F_3 ( V_2 , V_156 , V_2 -> V_154 | V_157 ) ;
F_3 ( V_2 , V_138 , 0 ) ;
F_3 ( V_2 , V_27 , 0 ) ;
F_3 ( V_2 , V_138 , V_155 ) ;
F_3 ( V_2 , V_205 , V_178 & 0xff ) ;
F_3 ( V_2 , V_206 , V_178 >> 8 ) ;
F_3 ( V_2 , V_138 , 0 ) ;
F_3 ( V_2 , V_27 , V_2 -> V_25 ) ;
F_3 ( V_2 , V_138 , V_155 ) ;
F_3 ( V_2 , V_156 , V_2 -> V_154 ) ;
F_3 ( V_2 , V_138 , V_177 ) ;
if ( V_13 > 230400 && V_13 != 3000000 )
F_3 ( V_2 , V_211 , V_213 ) ;
else
F_3 ( V_2 , V_211 , V_214 ) ;
if ( V_153 -> V_179 & V_215 ) {
V_154 |= ( V_216 | V_217 ) ;
F_3 ( V_2 , V_138 , V_169 ) ;
V_2 -> V_123 = F_1 ( V_2 , V_134 ) ;
F_3 ( V_2 , V_134 , V_2 -> V_123 | V_172 ) ;
F_3 ( V_2 , V_138 , V_155 ) ;
V_2 -> V_154 = F_1 ( V_2 , V_156 ) ;
F_3 ( V_2 , V_156 , V_2 -> V_154 | V_157 ) ;
F_3 ( V_2 , V_173 , V_174 ) ;
F_3 ( V_2 , V_156 , V_154 ) ;
F_3 ( V_2 , V_138 , V_169 ) ;
F_3 ( V_2 , V_134 , V_2 -> V_123 | V_125 ) ;
F_3 ( V_2 , V_138 , V_177 ) ;
}
F_48 ( & V_2 -> V_4 , V_2 -> V_4 . V_122 ) ;
if ( V_153 -> V_164 & ( V_165 | V_167 ) )
F_58 ( V_2 , V_153 ) ;
F_45 ( & V_2 -> V_4 . V_63 , V_103 ) ;
F_12 ( V_2 -> V_4 . V_22 , L_9 , V_2 -> V_23 -> V_24 ) ;
}
static void
F_63 ( struct V_12 * V_4 , unsigned int V_37 ,
unsigned int V_218 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned char V_154 ;
F_12 ( V_2 -> V_4 . V_22 , L_10 , V_2 -> V_23 -> V_24 ) ;
F_3 ( V_2 , V_138 , V_155 ) ;
V_154 = F_1 ( V_2 , V_156 ) ;
F_3 ( V_2 , V_156 , V_154 | V_157 ) ;
F_3 ( V_2 , V_138 , 0 ) ;
F_3 ( V_2 , V_27 , ( V_37 != 0 ) ? V_219 : 0 ) ;
F_3 ( V_2 , V_138 , V_155 ) ;
F_3 ( V_2 , V_156 , V_154 ) ;
F_3 ( V_2 , V_138 , 0 ) ;
}
static void F_64 ( struct V_12 * V_4 )
{
F_12 ( V_4 -> V_22 , L_11 ) ;
}
static int F_65 ( struct V_12 * V_4 )
{
F_12 ( V_4 -> V_22 , L_12 ) ;
return 0 ;
}
static void F_66 ( struct V_12 * V_4 , int V_103 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_12 ( V_2 -> V_4 . V_22 , L_13 ,
V_2 -> V_23 -> V_24 ) ;
V_2 -> V_4 . type = V_220 ;
}
static int
F_67 ( struct V_12 * V_4 , struct V_221 * V_222 )
{
F_12 ( V_4 -> V_22 , L_14 ) ;
return - V_223 ;
}
static const char *
F_68 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_12 ( V_2 -> V_4 . V_22 , L_15 , V_2 -> V_23 -> V_24 ) ;
return V_2 -> V_141 ;
}
static inline void F_69 ( struct V_1 * V_2 )
{
unsigned int V_34 , V_224 = 10000 ;
do {
V_34 = F_1 ( V_2 , V_62 ) ;
if ( V_34 & V_47 )
V_2 -> V_58 = V_47 ;
if ( -- V_224 == 0 )
break;
F_70 ( 1 ) ;
} while ( ( V_34 & V_225 ) != V_225 );
if ( V_2 -> V_4 . V_103 & V_226 ) {
V_224 = 1000000 ;
for ( V_224 = 1000000 ; V_224 ; V_224 -- ) {
unsigned int V_227 = F_1 ( V_2 , V_88 ) ;
V_2 -> V_89 |= V_227 & V_228 ;
if ( V_227 & V_98 )
break;
F_70 ( 1 ) ;
}
}
}
static void F_71 ( struct V_12 * V_4 , unsigned char V_39 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_69 ( V_2 ) ;
F_3 ( V_2 , V_68 , V_39 ) ;
}
static int F_72 ( struct V_12 * V_4 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
unsigned int V_34 = F_1 ( V_2 , V_62 ) ;
if ( ! ( V_34 & V_33 ) )
return V_229 ;
return F_1 ( V_2 , V_42 ) ;
}
static void F_73 ( struct V_12 * V_4 , int V_39 )
{
struct V_1 * V_2 = (struct V_1 * ) V_4 ;
F_69 ( V_2 ) ;
F_3 ( V_2 , V_68 , V_39 ) ;
}
static void
F_74 ( struct V_230 * V_231 , const char * V_232 ,
unsigned int V_66 )
{
struct V_1 * V_2 = V_233 [ V_231 -> V_57 ] ;
unsigned long V_103 ;
unsigned int V_25 ;
int V_234 = 1 ;
F_75 ( V_103 ) ;
if ( V_2 -> V_4 . V_235 )
V_234 = 0 ;
else if ( V_236 )
V_234 = F_76 ( & V_2 -> V_4 . V_63 ) ;
else
F_25 ( & V_2 -> V_4 . V_63 ) ;
V_25 = F_1 ( V_2 , V_27 ) ;
F_3 ( V_2 , V_27 , 0 ) ;
F_77 ( & V_2 -> V_4 , V_232 , V_66 , F_73 ) ;
F_69 ( V_2 ) ;
F_3 ( V_2 , V_27 , V_25 ) ;
if ( V_2 -> V_89 )
F_38 ( V_2 ) ;
if ( V_234 )
F_23 ( & V_2 -> V_4 . V_63 ) ;
F_78 ( V_103 ) ;
}
static int T_2
F_79 ( struct V_230 * V_231 , char * V_237 )
{
struct V_1 * V_2 ;
int V_13 = 115200 ;
int V_238 = 8 ;
int V_52 = 'n' ;
int V_239 = 'n' ;
if ( V_233 [ V_231 -> V_57 ] == NULL )
return - V_240 ;
V_2 = V_233 [ V_231 -> V_57 ] ;
if ( V_237 )
F_80 ( V_237 , & V_13 , & V_52 , & V_238 , & V_239 ) ;
return F_81 ( & V_2 -> V_4 , V_231 , V_13 , V_52 , V_238 , V_239 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
V_233 [ V_2 -> V_23 -> V_24 ] = V_2 ;
}
static inline void F_82 ( struct V_1 * V_2 )
{}
static int
F_83 ( struct V_241 * V_23 , T_3 V_37 )
{
struct V_1 * V_2 = F_84 ( V_23 ) ;
if ( V_2 )
F_85 ( & V_242 , & V_2 -> V_4 ) ;
return 0 ;
}
static int F_86 ( struct V_241 * V_22 )
{
struct V_1 * V_2 = F_84 ( V_22 ) ;
if ( V_2 )
F_87 ( & V_242 , & V_2 -> V_4 ) ;
return 0 ;
}
static void V_145 ( unsigned long V_243 )
{
struct V_1 * V_2 = V_244 [ V_243 ] ;
unsigned int V_245 , V_246 ;
int V_76 = 0 ;
V_245 = F_88 ( V_2 -> V_17 . V_20 ) ;
if ( ( V_245 == V_2 -> V_17 . V_247 ) ||
( V_245 == 0 ) ) {
if ( F_89 ( V_112 - V_2 -> V_111 ) <
V_248 ) {
F_90 ( & V_2 -> V_17 . V_19 , V_112 +
F_91 ( V_2 -> V_17 . V_249 ) ) ;
} else {
F_7 ( V_2 ) ;
V_2 -> V_25 |= ( V_108 | V_31 ) ;
F_3 ( V_2 , V_27 , V_2 -> V_25 ) ;
}
return;
}
V_246 = V_245 -
V_2 -> V_17 . V_247 ;
V_2 -> V_4 . V_44 . V_45 += V_246 ;
F_92 ( V_2 -> V_4 . V_37 -> V_4 . V_36 ,
V_2 -> V_17 . V_147 +
( V_2 -> V_17 . V_247 -
V_2 -> V_17 . V_149 ) ,
V_246 ) ;
F_24 ( V_2 -> V_4 . V_37 -> V_4 . V_36 ) ;
V_2 -> V_17 . V_247 = V_245 ;
if ( V_2 -> V_17 . V_148 +
V_2 -> V_17 . V_149 == V_245 ) {
V_76 = F_44 ( V_2 ) ;
if ( V_76 < 0 ) {
F_7 ( V_2 ) ;
V_2 -> V_25 |= ( V_108 | V_31 ) ;
F_3 ( V_2 , V_27 , V_2 -> V_25 ) ;
}
} else {
F_90 ( & V_2 -> V_17 . V_19 , V_112 +
F_91 ( V_2 -> V_17 . V_249 ) ) ;
}
V_2 -> V_111 = V_112 ;
}
static void F_93 ( int V_250 , T_4 V_251 , void * V_146 )
{
return;
}
static int F_44 ( struct V_1 * V_2 )
{
int V_76 = 0 ;
if ( V_2 -> V_17 . V_20 == - 1 ) {
V_76 = F_33 ( V_2 -> V_17 . V_252 ,
L_16 ,
( void * ) F_93 , V_2 ,
& ( V_2 -> V_17 . V_20 ) ) ;
if ( V_76 < 0 )
return V_76 ;
F_35 ( V_2 -> V_17 . V_20 , 0 ,
V_83 ,
V_2 -> V_17 . V_84 , 0 , 0 ) ;
F_34 ( V_2 -> V_17 . V_20 , 0 ,
V_85 ,
V_2 -> V_17 . V_149 , 0 , 0 ) ;
F_36 ( V_2 -> V_17 . V_20 ,
V_86 ,
V_2 -> V_17 . V_148 , 1 ,
V_87 ,
V_2 -> V_17 . V_252 , 0 ) ;
}
V_2 -> V_17 . V_247 = V_2 -> V_17 . V_149 ;
F_37 ( V_2 -> V_17 . V_20 ) ;
F_90 ( & V_2 -> V_17 . V_19 , V_112 +
F_91 ( V_2 -> V_17 . V_249 ) ) ;
V_2 -> V_17 . V_18 = true ;
return V_76 ;
}
static void F_94 ( struct V_1 * V_2 )
{
struct V_64 * V_65 = & V_2 -> V_4 . V_37 -> V_65 ;
unsigned int V_75 = V_2 -> V_17 . V_81
+ ( V_65 -> V_72 & ( V_73 - 1 ) ) ;
if ( F_27 ( V_65 ) )
return;
V_2 -> V_17 . V_82 = F_29 ( V_65 ) ;
if ( V_75 + V_2 -> V_17 . V_82 >=
V_2 -> V_17 . V_81 + V_73 )
V_2 -> V_17 . V_82 =
( V_2 -> V_17 . V_81 + V_73 ) - V_75 ;
F_34 ( V_2 -> V_17 . V_29 , 0 ,
V_83 ,
V_2 -> V_17 . V_84 , 0 , 0 ) ;
F_35 ( V_2 -> V_17 . V_29 , 0 ,
V_85 , V_75 , 0 , 0 ) ;
F_36 ( V_2 -> V_17 . V_29 ,
V_86 ,
V_2 -> V_17 . V_82 , 1 ,
V_87 ,
V_2 -> V_17 . V_78 , 0 ) ;
F_37 ( V_2 -> V_17 . V_29 ) ;
}
static void V_79 ( int V_250 , T_4 V_251 , void * V_146 )
{
struct V_1 * V_2 = (struct V_1 * ) V_146 ;
struct V_64 * V_65 = & V_2 -> V_4 . V_37 -> V_65 ;
V_65 -> V_72 = ( V_65 -> V_72 + V_2 -> V_17 . V_82 ) & \
( V_73 - 1 ) ;
V_2 -> V_4 . V_44 . V_69 += V_2 -> V_17 . V_82 ;
if ( F_29 ( V_65 ) < V_74 )
F_30 ( & V_2 -> V_4 ) ;
if ( F_27 ( V_65 ) ) {
F_25 ( & ( V_2 -> V_17 . V_80 ) ) ;
F_13 ( & V_2 -> V_4 ) ;
V_2 -> V_17 . V_77 = false ;
F_23 ( & ( V_2 -> V_17 . V_80 ) ) ;
} else {
F_9 ( V_2 -> V_17 . V_29 ) ;
F_94 ( V_2 ) ;
}
V_2 -> V_111 = V_112 ;
return;
}
static int F_95 ( struct V_241 * V_23 )
{
struct V_1 * V_2 ;
struct V_253 * V_254 , * V_100 , * V_255 , * V_256 ;
struct V_257 * V_258 = V_23 -> V_22 . V_259 ;
int V_76 = - V_260 ;
V_254 = F_96 ( V_23 , V_261 , 0 ) ;
if ( ! V_254 ) {
F_97 ( & V_23 -> V_22 , L_17 ) ;
return - V_240 ;
}
V_100 = F_96 ( V_23 , V_262 , 0 ) ;
if ( ! V_100 ) {
F_97 ( & V_23 -> V_22 , L_18 ) ;
return - V_240 ;
}
if ( ! F_98 ( V_254 -> V_75 , ( V_254 -> V_263 - V_254 -> V_75 ) + 1 ,
V_23 -> V_22 . V_264 -> V_141 ) ) {
F_97 ( & V_23 -> V_22 , L_19 ) ;
return - V_265 ;
}
V_256 = F_99 ( V_23 , V_266 , L_20 ) ;
if ( ! V_256 ) {
V_76 = - V_223 ;
goto V_267;
}
V_255 = F_99 ( V_23 , V_266 , L_21 ) ;
if ( ! V_255 ) {
V_76 = - V_223 ;
goto V_267;
}
V_2 = F_100 ( sizeof( * V_2 ) , V_268 ) ;
if ( V_2 == NULL ) {
V_76 = - V_269 ;
goto V_270;
}
sprintf ( V_2 -> V_141 , L_22 , V_23 -> V_24 ) ;
V_2 -> V_23 = V_23 ;
V_2 -> V_4 . V_22 = & V_23 -> V_22 ;
V_2 -> V_4 . type = V_220 ;
V_2 -> V_4 . V_271 = V_272 ;
V_2 -> V_4 . V_100 = V_100 -> V_75 ;
V_2 -> V_4 . V_5 = 2 ;
V_2 -> V_4 . V_70 = 64 ;
V_2 -> V_4 . V_273 = & V_274 ;
V_2 -> V_4 . line = V_23 -> V_24 ;
V_2 -> V_4 . V_6 = V_258 -> V_6 ;
V_2 -> V_4 . V_275 = V_258 -> V_275 ;
V_2 -> V_4 . V_103 = V_258 -> V_103 ;
V_2 -> V_4 . V_140 = V_258 -> V_140 ;
V_2 -> V_4 . V_16 = V_258 -> V_16 ;
V_2 -> V_17 . V_84 = V_254 -> V_75 ;
if ( V_258 -> V_276 ) {
V_2 -> V_17 . V_78 = V_255 -> V_75 ;
V_2 -> V_17 . V_252 = V_256 -> V_75 ;
V_2 -> V_28 = 1 ;
V_2 -> V_17 . V_148 = 4096 ;
V_2 -> V_17 . V_249 = 2 ;
F_101 ( & ( V_2 -> V_17 . V_80 ) ) ;
F_101 ( & ( V_2 -> V_17 . V_277 ) ) ;
V_2 -> V_17 . V_29 = V_21 ;
V_2 -> V_17 . V_20 = V_21 ;
}
V_244 [ V_23 -> V_24 ] = V_2 ;
F_82 ( V_2 ) ;
V_76 = F_102 ( & V_242 , & V_2 -> V_4 ) ;
if ( V_76 != 0 )
goto V_270;
F_103 ( V_23 , V_2 ) ;
return 0 ;
V_267:
F_97 ( & V_23 -> V_22 , L_23 ,
V_23 -> V_24 , V_278 , V_76 ) ;
V_270:
F_104 ( V_254 -> V_75 , ( V_254 -> V_263 - V_254 -> V_75 ) + 1 ) ;
return V_76 ;
}
static int F_105 ( struct V_241 * V_22 )
{
struct V_1 * V_2 = F_84 ( V_22 ) ;
F_103 ( V_22 , NULL ) ;
if ( V_2 ) {
F_106 ( & V_242 , & V_2 -> V_4 ) ;
F_107 ( V_2 ) ;
}
return 0 ;
}
static int T_2 F_108 ( void )
{
int V_76 ;
V_76 = F_109 ( & V_242 ) ;
if ( V_76 != 0 )
return V_76 ;
V_76 = F_110 ( & V_279 ) ;
if ( V_76 != 0 )
F_111 ( & V_242 ) ;
return V_76 ;
}
static void T_5 F_112 ( void )
{
F_113 ( & V_279 ) ;
F_111 ( & V_242 ) ;
}
