void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 , V_2 -> V_4 . V_5 , V_2 -> V_4 . V_6 -> V_7 ) ;
F_2 ( L_2 , V_2 -> V_4 . V_8 , V_2 -> V_4 . V_9 ) ;
F_2 ( L_3 , V_2 -> V_4 . V_6 -> V_10 ,
V_2 -> V_4 . V_6 -> V_11 ) ;
F_2 ( L_4 , V_2 -> V_4 . V_12 ) ;
for ( V_3 = 0 ; V_3 < 32 ; V_3 += 4 ) {
F_2 ( L_5 , V_3 ,
F_3 ( V_2 , V_3 ) ,
F_3 ( V_2 , V_3 + 1 ) ,
F_3 ( V_2 , V_3 + 2 ) ,
F_3 ( V_2 , V_3 + 3 ) ) ;
}
}
void F_4 ( struct V_1 * V_2 )
{
F_5 () ;
F_6 () ;
F_7 ( V_2 ) ;
V_2 -> V_4 . V_13 &= ~ V_14 ;
F_8 () ;
}
static void F_9 ( struct V_1 * V_2 )
{
F_5 () ;
F_6 () ;
F_10 ( V_2 ) ;
V_2 -> V_4 . V_13 |= V_14 ;
F_8 () ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_6 -> V_7 & V_14 ) {
if ( ! ( V_2 -> V_4 . V_13 & V_14 ) )
F_9 ( V_2 ) ;
} else if ( V_2 -> V_4 . V_13 & V_14 ) {
F_4 ( V_2 ) ;
}
}
static void F_11 ( struct V_1 * V_2 )
{
}
static void F_12 ( struct V_1 * V_2 )
{
#if F_13 ( V_15 ) && ! F_13 ( V_16 )
V_2 -> V_4 . V_13 &= ~ V_17 ;
V_2 -> V_4 . V_13 |= V_2 -> V_4 . V_6 -> V_7 & V_17 ;
#endif
}
static void F_14 ( struct V_1 * V_2 )
{
#ifndef V_16
V_2 -> V_4 . V_13 &= ~ V_18 ;
V_2 -> V_4 . V_13 |= V_2 -> V_4 . V_6 -> V_7 & V_18 ;
#endif
if ( V_2 -> V_19 ) {
#ifdef V_16
V_2 -> V_4 . V_6 -> V_7 |= V_18 ;
#else
V_2 -> V_4 . V_13 |= V_18 ;
V_2 -> V_4 . V_6 -> V_7 &= ~ V_18 ;
#endif
}
}
void F_15 ( struct V_1 * V_2 , T_1 V_20 )
{
T_1 V_21 = V_2 -> V_4 . V_6 -> V_7 ;
#ifdef V_16
V_20 |= V_22 ;
#endif
V_2 -> V_4 . V_6 -> V_7 = V_20 ;
F_16 ( V_2 , V_21 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
F_14 ( V_2 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
unsigned int V_23 )
{
F_18 ( V_2 , V_23 ) ;
F_19 ( V_23 , & V_2 -> V_4 . V_12 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
T_2 V_24 , T_2 V_25 )
{
V_2 -> V_4 . V_26 = V_24 ;
V_2 -> V_4 . V_27 = V_25 ;
F_17 ( V_2 , V_28 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
T_2 V_24 , T_2 V_25 )
{
V_2 -> V_4 . V_26 = V_24 ;
V_2 -> V_4 . V_27 = V_25 ;
F_17 ( V_2 , V_29 ) ;
}
static void F_22 ( struct V_1 * V_2 ,
T_2 V_25 )
{
V_2 -> V_4 . V_27 = V_25 ;
F_17 ( V_2 , V_30 ) ;
}
static void F_23 ( struct V_1 * V_2 , T_2 V_24 ,
T_2 V_25 )
{
V_2 -> V_4 . V_26 = V_24 ;
V_2 -> V_4 . V_27 = V_25 ;
F_17 ( V_2 , V_31 ) ;
}
void F_24 ( struct V_1 * V_2 , T_2 V_25 )
{
V_2 -> V_4 . V_27 = V_25 ;
F_17 ( V_2 , V_32 ) ;
}
void F_25 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_33 ) ;
}
int F_26 ( struct V_1 * V_2 )
{
return F_27 ( V_33 , & V_2 -> V_4 . V_12 ) ;
}
void F_28 ( struct V_1 * V_2 )
{
F_29 ( V_33 , & V_2 -> V_4 . V_12 ) ;
}
void F_30 ( struct V_1 * V_2 ,
struct V_34 * V_35 )
{
unsigned int V_36 = V_37 ;
if ( V_35 -> V_35 == V_38 )
V_36 = V_39 ;
F_17 ( V_2 , V_36 ) ;
}
void F_31 ( struct V_1 * V_2 )
{
F_29 ( V_37 , & V_2 -> V_4 . V_12 ) ;
F_29 ( V_39 , & V_2 -> V_4 . V_12 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_40 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_29 ( V_40 , & V_2 -> V_4 . V_12 ) ;
}
static void F_34 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
#ifdef V_16
F_35 ( V_41 , V_10 ) ;
F_35 ( V_42 , V_11 ) ;
#else
V_2 -> V_4 . V_6 -> V_10 = V_10 ;
V_2 -> V_4 . V_6 -> V_11 = V_11 ;
#endif
}
static void F_36 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_43 = V_10 ;
V_2 -> V_4 . V_44 = V_11 ;
}
static void F_37 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
if ( F_38 ( V_45 ) ) {
V_2 -> V_4 . V_46 = V_10 ;
V_2 -> V_4 . V_47 = V_11 ;
} else {
F_36 ( V_2 , V_10 , V_11 ) ;
}
}
static void F_39 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_48 = V_10 ;
V_2 -> V_4 . V_49 = V_11 ;
}
static unsigned long F_40 ( struct V_1 * V_2 )
{
#ifdef V_16
return F_41 ( V_50 ) ;
#else
return V_2 -> V_4 . V_6 -> V_51 ;
#endif
}
static void F_42 ( struct V_1 * V_2 , unsigned long V_52 )
{
#ifdef V_16
F_35 ( V_50 , V_52 ) ;
#else
V_2 -> V_4 . V_6 -> V_51 = V_52 ;
#endif
}
static unsigned long F_43 ( struct V_1 * V_2 )
{
#ifdef V_16
return F_41 ( V_53 ) ;
#else
return V_2 -> V_4 . V_6 -> V_54 ;
#endif
}
static void F_44 ( struct V_1 * V_2 , T_1 V_54 )
{
#ifdef V_16
F_35 ( V_53 , V_54 ) ;
#else
V_2 -> V_4 . V_6 -> V_54 = V_54 ;
#endif
}
static unsigned long F_45 ( struct V_1 * V_2 )
{
#ifdef V_16
return F_41 ( V_55 ) ;
#else
return V_2 -> V_4 . V_56 ;
#endif
}
static int F_46 ( struct V_1 * V_2 ,
unsigned int V_23 )
{
int V_57 = 0 ;
T_2 V_58 = 0 ;
bool V_59 = false , V_60 = false , V_61 = false ;
T_2 V_62 = V_2 -> V_4 . V_6 -> V_63 ;
T_2 V_64 = F_3 ( V_2 , 1 ) ;
bool V_65 ;
bool V_66 = false ;
enum V_67 V_67 ;
T_2 V_20 = V_2 -> V_4 . V_6 -> V_7 ;
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_68 ) ) {
V_62 &= 0xffffffff ;
V_64 &= 0xffffffff ;
}
V_65 = ( V_62 == V_64 ) ;
V_65 = V_65 && ! ( V_2 -> V_4 . V_6 -> V_7 & V_69 ) ;
if ( V_23 == V_39 ) {
V_23 = V_37 ;
V_66 = true ;
}
if ( ( V_23 == V_37 ) && V_2 -> V_4 . V_70 )
V_61 = true ;
switch ( V_23 ) {
case V_28 :
case V_29 :
case V_31 :
V_60 = true ;
case V_30 :
case V_32 :
V_59 = true ;
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
case V_76 :
case V_77 :
V_57 = 1 ;
V_58 = V_78 | V_79 | V_18 ;
V_67 = V_80 ;
break;
case V_40 :
case V_81 :
case V_82 :
V_57 = V_2 -> V_4 . V_6 -> V_7 & V_78 ;
V_57 = V_57 && ! V_65 ;
V_58 = V_79 ;
V_67 = V_83 ;
break;
case V_84 :
V_57 = V_2 -> V_4 . V_6 -> V_7 & V_79 ;
V_57 = V_57 && ! V_65 ;
V_67 = V_85 ;
break;
case V_33 :
case V_86 :
V_66 = true ;
case V_37 :
case V_87 :
V_57 = V_2 -> V_4 . V_6 -> V_7 & V_88 ;
V_57 = V_57 && ! V_65 ;
V_58 = V_78 | V_79 | V_18 ;
V_67 = V_80 ;
break;
case V_89 :
V_57 = V_2 -> V_4 . V_6 -> V_7 & V_18 ;
V_57 = V_57 && ! V_65 ;
V_58 = V_79 ;
V_67 = V_83 ;
break;
}
if ( V_57 ) {
switch ( V_67 ) {
case V_80 :
F_34 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_83 :
F_36 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_90 :
F_37 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_85 :
F_39 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
}
V_2 -> V_4 . V_5 = V_2 -> V_4 . V_91 | V_2 -> V_4 . V_92 [ V_23 ] ;
if ( V_59 == true )
F_44 ( V_2 , V_2 -> V_4 . V_27 ) ;
if ( V_60 == true )
F_42 ( V_2 , V_2 -> V_4 . V_26 ) ;
if ( V_61 == true ) {
if ( V_2 -> V_4 . V_70 & V_93 )
F_47 ( V_94 , V_2 ) ;
else if ( V_2 -> V_4 . V_70 & V_95 ) {
F_48 ( V_2 -> V_4 . V_96 != V_97 ) ;
F_49 ( V_2 ) ;
}
}
V_20 &= V_58 ;
#if F_13 ( V_98 )
if ( V_2 -> V_4 . V_99 & V_100 )
V_20 |= V_101 ;
#endif
F_15 ( V_2 , V_20 ) ;
if ( ! V_66 )
F_29 ( V_23 , & V_2 -> V_4 . V_12 ) ;
}
#ifdef V_16
if ( V_2 -> V_4 . V_12 & V_102 )
F_50 ( V_2 , V_80 ) ;
if ( V_2 -> V_4 . V_12 & V_103 )
F_50 ( V_2 , V_83 ) ;
if ( V_2 -> V_4 . V_12 & V_84 )
F_50 ( V_2 , V_85 ) ;
#endif
return V_57 ;
}
static unsigned long F_51 ( struct V_1 * V_2 )
{
T_3 V_104 , V_105 , V_106 = 0 ;
T_3 V_107 = 0 ;
T_1 V_108 = F_52 ( V_2 -> V_4 . V_109 ) ;
V_105 = 1ULL << ( 63 - V_108 ) ;
V_104 = F_53 () ;
if ( V_104 & V_105 )
V_106 = V_105 ;
V_106 += V_105 - ( V_104 & ( V_105 - 1 ) ) ;
V_107 = V_106 ;
if ( F_54 ( V_107 , V_110 ) )
V_107 ++ ;
return F_55 (unsigned long long, nr_jiffies, NEXT_TIMER_MAX_DELTA) ;
}
static void F_56 ( struct V_1 * V_2 )
{
unsigned long V_107 ;
unsigned long V_111 ;
if ( ( V_2 -> V_4 . V_112 & ( V_113 | V_114 ) ) != ( V_113 | V_114 ) )
F_29 ( V_115 , & V_2 -> V_116 ) ;
F_57 ( & V_2 -> V_4 . V_117 , V_111 ) ;
V_107 = F_51 ( V_2 ) ;
if ( V_107 < V_118 )
F_58 ( & V_2 -> V_4 . V_119 , V_120 + V_107 ) ;
else
F_59 ( & V_2 -> V_4 . V_119 ) ;
F_60 ( & V_2 -> V_4 . V_117 , V_111 ) ;
}
void F_61 ( unsigned long V_121 )
{
struct V_1 * V_2 = (struct V_1 * ) V_121 ;
T_1 V_112 , V_122 ;
int V_123 ;
do {
V_122 = V_112 = V_2 -> V_4 . V_112 ;
V_123 = 0 ;
if ( V_112 & V_113 ) {
if ( V_112 & V_114 )
V_123 = 1 ;
else
V_122 = V_112 | V_114 ;
} else {
V_122 = V_112 | V_113 ;
}
} while ( F_62 ( & V_2 -> V_4 . V_112 , V_112 , V_122 ) != V_112 );
if ( V_122 & V_114 ) {
F_63 () ;
F_47 ( V_124 , V_2 ) ;
F_64 ( V_2 ) ;
}
if ( V_123 && ( V_2 -> V_4 . V_109 & V_125 ) &&
V_2 -> V_4 . V_126 ) {
F_63 () ;
F_47 ( V_115 , V_2 ) ;
F_64 ( V_2 ) ;
}
if ( ! V_123 )
F_56 ( V_2 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 . V_109 & V_127 ) && ( V_2 -> V_4 . V_112 & V_128 ) )
F_25 ( V_2 ) ;
else
F_28 ( V_2 ) ;
if ( ( V_2 -> V_4 . V_109 & V_129 ) && ( V_2 -> V_4 . V_112 & V_114 ) )
F_32 ( V_2 ) ;
else
F_33 ( V_2 ) ;
}
static void F_66 ( struct V_1 * V_2 )
{
unsigned long * V_130 = & V_2 -> V_4 . V_12 ;
unsigned int V_23 ;
V_23 = F_67 ( * V_130 ) ;
while ( V_23 < V_131 ) {
if ( F_46 ( V_2 , V_23 ) )
break;
V_23 = F_68 ( V_130 ,
V_132 * sizeof( * V_130 ) ,
V_23 + 1 ) ;
}
V_2 -> V_4 . V_6 -> V_133 = ! ! * V_130 ;
}
int F_69 ( struct V_1 * V_2 )
{
int V_134 = 0 ;
F_70 ( ! F_71 () ) ;
F_66 ( V_2 ) ;
if ( V_2 -> V_116 ) {
return 1 ;
}
if ( V_2 -> V_4 . V_6 -> V_7 & V_135 ) {
F_72 () ;
F_73 ( V_2 ) ;
F_29 ( V_136 , & V_2 -> V_116 ) ;
F_74 () ;
F_75 ( V_2 , V_137 ) ;
V_134 = 1 ;
} ;
return V_134 ;
}
int F_76 ( struct V_1 * V_2 )
{
int V_134 = 1 ;
if ( F_77 ( V_124 , V_2 ) )
F_65 ( V_2 ) ;
#if F_13 ( V_138 ) || F_13 ( V_139 )
if ( F_77 ( V_140 , V_2 ) )
F_78 ( V_2 ) ;
#endif
if ( F_77 ( V_115 , V_2 ) ) {
V_2 -> V_141 -> V_142 = V_143 ;
V_134 = 0 ;
}
if ( F_77 ( V_94 , V_2 ) ) {
V_2 -> V_141 -> V_56 . V_56 = 0 ;
V_2 -> V_4 . V_144 = true ;
V_2 -> V_141 -> V_142 = V_145 ;
V_134 = 0 ;
}
return V_134 ;
}
int F_79 ( struct V_146 * V_146 , struct V_1 * V_2 )
{
int V_147 , V_148 ;
struct V_149 V_150 ;
if ( ! V_2 -> V_4 . V_151 ) {
V_146 -> V_142 = V_152 ;
return - V_153 ;
}
V_148 = F_80 ( V_2 ) ;
if ( V_148 <= 0 ) {
V_147 = V_148 ;
goto V_154;
}
#ifdef V_15
F_81 () ;
V_2 -> V_155 = 1 ;
F_82 ( V_2 ) ;
#endif
V_150 = V_2 -> V_4 . V_156 ;
F_83 ( & V_150 ) ;
V_150 = V_157 -> V_158 . V_150 ;
V_157 -> V_158 . V_150 = V_2 -> V_4 . V_156 ;
V_2 -> V_4 . V_159 = V_157 -> V_160 -> V_161 ;
F_84 () ;
V_147 = F_85 ( V_146 , V_2 ) ;
F_83 ( & V_150 ) ;
V_157 -> V_158 . V_150 = V_150 ;
#ifdef V_15
F_86 ( V_2 ) ;
V_2 -> V_155 = 0 ;
#endif
V_154:
V_2 -> V_162 = V_163 ;
return V_147 ;
}
static int F_87 ( struct V_146 * V_141 , struct V_1 * V_2 )
{
enum V_164 V_165 ;
V_165 = F_88 ( V_141 , V_2 ) ;
switch ( V_165 ) {
case V_166 :
F_89 ( V_2 , V_167 ) ;
return V_168 ;
case V_169 :
V_141 -> V_142 = V_170 ;
return V_171 ;
case V_172 :
F_2 ( V_173 L_6 ,
V_174 , V_2 -> V_4 . V_5 , V_2 -> V_4 . V_175 ) ;
V_141 -> V_176 . V_177 = ~ 0ULL << 32 ;
V_141 -> V_176 . V_177 |= V_2 -> V_4 . V_175 ;
F_24 ( V_2 , V_178 ) ;
return V_171 ;
case V_179 :
return V_171 ;
default:
F_90 () ;
}
}
static int F_91 ( struct V_146 * V_141 , struct V_1 * V_2 )
{
struct V_149 * V_180 = & ( V_2 -> V_4 . V_156 ) ;
T_1 V_181 = V_2 -> V_4 . V_181 ;
V_141 -> V_150 . V_4 . V_182 = 0 ;
V_141 -> V_150 . V_4 . V_183 = V_2 -> V_4 . V_5 ;
if ( V_181 & ( V_184 | V_185 | V_186 | V_187 ) ) {
V_141 -> V_150 . V_4 . V_182 |= V_188 ;
} else {
if ( V_181 & ( V_189 | V_190 ) )
V_141 -> V_150 . V_4 . V_182 |= V_191 ;
else if ( V_181 & ( V_192 | V_193 ) )
V_141 -> V_150 . V_4 . V_182 |= V_194 ;
if ( V_181 & ( V_192 | V_189 ) )
V_141 -> V_150 . V_4 . V_183 = V_180 -> V_195 ;
else if ( V_181 & ( V_193 | V_190 ) )
V_141 -> V_150 . V_4 . V_183 = V_180 -> V_196 ;
}
return V_171 ;
}
static void F_92 ( struct V_197 * V_198 )
{
T_2 V_199 , V_200 , V_7 , V_8 ;
asm("mr %0, 1" : "=r"(r1));
asm("mflr %0" : "=r"(lr));
asm("mfmsr %0" : "=r"(msr));
asm("bl 1f; 1: mflr %0" : "=r"(ip));
memset ( V_198 , 0 , sizeof( * V_198 ) ) ;
V_198 -> V_201 [ 1 ] = V_199 ;
V_198 -> V_202 = V_200 ;
V_198 -> V_7 = V_7 ;
V_198 -> V_203 = V_8 ;
}
static void F_93 ( struct V_1 * V_2 ,
unsigned int V_204 )
{
struct V_197 V_198 ;
switch ( V_204 ) {
case V_205 :
F_92 ( & V_198 ) ;
F_94 ( & V_198 ) ;
break;
case V_206 :
F_92 ( & V_198 ) ;
F_95 ( & V_198 ) ;
break;
#if F_13 ( V_207 )
case V_208 :
F_92 ( & V_198 ) ;
F_96 ( & V_198 ) ;
break;
#endif
case V_209 :
break;
case V_210 :
F_92 ( & V_198 ) ;
F_97 ( & V_198 ) ;
break;
case V_211 :
F_92 ( & V_198 ) ;
#ifdef F_98
F_99 ( & V_198 ) ;
#else
F_100 ( & V_198 ) ;
#endif
break;
case V_212 :
F_100 ( & V_198 ) ;
break;
case V_213 :
V_2 -> V_4 . V_181 = F_41 ( V_214 ) ;
F_101 () ;
break;
}
}
int F_102 ( struct V_146 * V_141 , struct V_1 * V_2 ,
unsigned int V_204 )
{
int V_134 = V_171 ;
int V_148 ;
int V_215 ;
F_103 ( V_2 ) ;
F_93 ( V_2 , V_204 ) ;
F_72 () ;
F_104 ( V_204 , V_2 ) ;
F_105 () ;
V_141 -> V_142 = V_216 ;
V_141 -> V_217 = 1 ;
switch ( V_204 ) {
case V_209 :
F_2 ( L_7 , F_41 ( V_218 ) ) ;
F_1 ( V_2 ) ;
V_141 -> V_176 . V_177 = ~ 1ULL << 32 ;
V_141 -> V_176 . V_177 |= F_41 ( V_218 ) ;
V_134 = V_171 ;
break;
case V_205 :
F_106 ( V_2 , V_219 ) ;
V_134 = V_220 ;
break;
case V_206 :
F_106 ( V_2 , V_221 ) ;
V_134 = V_220 ;
break;
case V_211 :
V_134 = V_220 ;
break;
case V_208 :
F_106 ( V_2 , V_222 ) ;
V_134 = V_220 ;
break;
case V_223 :
F_106 ( V_2 , V_224 ) ;
V_134 = V_220 ;
break;
case V_225 :
F_106 ( V_2 , V_224 ) ;
V_134 = V_220 ;
break;
case V_210 :
V_134 = V_220 ;
break;
case V_226 :
V_134 = F_87 ( V_141 , V_2 ) ;
break;
case V_227 :
if ( V_2 -> V_4 . V_6 -> V_7 & ( V_69 | V_22 ) ) {
F_24 ( V_2 , V_2 -> V_4 . V_228 ) ;
V_134 = V_220 ;
F_106 ( V_2 , V_229 ) ;
break;
}
V_134 = F_87 ( V_141 , V_2 ) ;
break;
case V_230 :
F_17 ( V_2 , V_73 ) ;
F_106 ( V_2 , V_231 ) ;
V_134 = V_220 ;
break;
#ifdef F_107
case V_232 : {
if ( V_2 -> V_4 . V_6 -> V_7 & V_14 )
F_9 ( V_2 ) ;
else
F_17 ( V_2 ,
V_74 ) ;
V_134 = V_220 ;
break;
}
case V_233 :
F_17 ( V_2 , V_75 ) ;
V_134 = V_220 ;
break;
case V_234 :
F_17 ( V_2 , V_76 ) ;
V_134 = V_220 ;
break;
#else
case V_232 :
F_24 ( V_2 , V_235 | V_236 ) ;
V_134 = V_220 ;
break;
case V_233 :
case V_234 :
F_2 ( V_173 L_8 ,
V_174 , V_204 , V_2 -> V_4 . V_5 ) ;
V_141 -> V_176 . V_177 = V_204 ;
V_134 = V_171 ;
break;
#endif
case V_237 :
F_21 ( V_2 , V_2 -> V_4 . V_238 ,
V_2 -> V_4 . V_228 ) ;
F_106 ( V_2 , V_239 ) ;
V_134 = V_220 ;
break;
case V_240 :
F_22 ( V_2 , V_2 -> V_4 . V_228 ) ;
F_106 ( V_2 , V_241 ) ;
V_134 = V_220 ;
break;
case V_242 :
F_23 ( V_2 , V_2 -> V_4 . V_238 ,
V_2 -> V_4 . V_228 ) ;
V_134 = V_220 ;
break;
#ifdef V_16
case V_243 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_69 ) ) {
F_108 ( V_2 , 3 , F_109 ( V_2 ) ) ;
} else {
F_24 ( V_2 , V_244 ) ;
}
V_134 = V_220 ;
break;
#else
case V_245 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_69 ) &&
( ( ( T_1 ) F_3 ( V_2 , 0 ) ) == V_246 ) ) {
F_108 ( V_2 , 3 , F_109 ( V_2 ) ) ;
V_134 = V_220 ;
} else {
F_17 ( V_2 , V_72 ) ;
}
F_106 ( V_2 , V_247 ) ;
V_134 = V_220 ;
break;
#endif
case V_248 : {
unsigned long V_249 = V_2 -> V_4 . V_238 ;
int V_250 ;
T_4 V_251 ;
T_5 V_252 ;
#ifdef V_138
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_69 ) &&
( V_249 & V_253 ) == V_2 -> V_4 . V_254 ) {
F_110 ( V_2 ) ;
F_106 ( V_2 , V_255 ) ;
V_134 = V_220 ;
break;
}
#endif
V_250 = F_111 ( V_2 , V_249 ) ;
if ( V_250 < 0 ) {
F_20 ( V_2 ,
V_2 -> V_4 . V_238 ,
V_2 -> V_4 . V_228 ) ;
F_112 ( V_2 ) ;
F_106 ( V_2 , V_256 ) ;
V_134 = V_220 ;
break;
}
V_215 = F_113 ( & V_2 -> V_257 -> V_258 ) ;
V_251 = F_114 ( V_2 , V_250 , V_249 ) ;
V_252 = V_251 >> V_259 ;
if ( F_115 ( V_2 -> V_257 , V_252 ) ) {
F_116 ( V_2 , V_249 , V_251 , V_250 ) ;
F_106 ( V_2 , V_255 ) ;
V_134 = V_220 ;
} else {
V_2 -> V_4 . V_260 = V_251 ;
V_2 -> V_4 . V_261 = V_249 ;
V_134 = F_117 ( V_141 , V_2 ) ;
F_106 ( V_2 , V_262 ) ;
}
F_118 ( & V_2 -> V_257 -> V_258 , V_215 ) ;
break;
}
case V_263 : {
unsigned long V_249 = V_2 -> V_4 . V_5 ;
T_4 V_251 ;
T_5 V_252 ;
int V_250 ;
V_134 = V_220 ;
V_250 = F_119 ( V_2 , V_249 ) ;
if ( V_250 < 0 ) {
F_17 ( V_2 , V_71 ) ;
F_120 ( V_2 ) ;
F_106 ( V_2 , V_264 ) ;
break;
}
F_106 ( V_2 , V_265 ) ;
V_215 = F_113 ( & V_2 -> V_257 -> V_258 ) ;
V_251 = F_114 ( V_2 , V_250 , V_249 ) ;
V_252 = V_251 >> V_259 ;
if ( F_115 ( V_2 -> V_257 , V_252 ) ) {
F_116 ( V_2 , V_249 , V_251 , V_250 ) ;
} else {
F_17 ( V_2 , V_84 ) ;
}
F_118 ( & V_2 -> V_257 -> V_258 , V_215 ) ;
break;
}
case V_213 : {
V_134 = F_91 ( V_141 , V_2 ) ;
if ( V_134 == V_171 )
V_141 -> V_142 = V_266 ;
F_106 ( V_2 , V_267 ) ;
break;
}
default:
F_2 ( V_268 L_9 , V_204 ) ;
F_90 () ;
}
if ( ! ( V_134 & V_171 ) ) {
V_148 = F_80 ( V_2 ) ;
if ( V_148 <= 0 )
V_134 = ( V_148 << 2 ) | V_171 | ( V_134 & V_269 ) ;
else {
F_84 () ;
}
}
return V_134 ;
}
static void F_121 ( struct V_1 * V_2 , T_1 V_122 )
{
T_1 V_270 = V_2 -> V_4 . V_112 ;
V_2 -> V_4 . V_112 = V_122 ;
if ( ( V_270 ^ V_2 -> V_4 . V_112 ) & ( V_113 | V_114 ) )
F_56 ( V_2 ) ;
F_65 ( V_2 ) ;
}
int F_122 ( struct V_1 * V_2 )
{
int V_3 ;
int V_134 ;
V_2 -> V_4 . V_5 = 0 ;
V_2 -> V_4 . V_6 -> V_271 = V_2 -> V_272 ;
F_108 ( V_2 , 1 , ( 16 << 20 ) - 8 ) ;
F_15 ( V_2 , 0 ) ;
#ifndef V_16
V_2 -> V_4 . V_13 = V_273 | V_274 | V_275 ;
V_2 -> V_4 . V_276 = 1 ;
V_2 -> V_4 . V_6 -> V_7 = 0 ;
#endif
V_2 -> V_4 . V_91 = 0x55550000 ;
for ( V_3 = 0 ; V_3 < V_131 ; V_3 ++ )
V_2 -> V_4 . V_92 [ V_3 ] = 0x7700 | V_3 * 4 ;
F_123 ( V_2 ) ;
V_134 = F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
return V_134 ;
}
int F_126 ( struct V_1 * V_2 )
{
F_127 ( & V_2 -> V_4 . V_117 ) ;
F_128 ( & V_2 -> V_4 . V_119 , F_61 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_129 ( struct V_1 * V_2 )
{
F_130 ( & V_2 -> V_4 . V_119 ) ;
}
int F_131 ( struct V_1 * V_2 , struct V_277 * V_198 )
{
int V_3 ;
V_198 -> V_5 = V_2 -> V_4 . V_5 ;
V_198 -> V_278 = F_132 ( V_2 ) ;
V_198 -> V_9 = V_2 -> V_4 . V_9 ;
V_198 -> V_8 = V_2 -> V_4 . V_8 ;
V_198 -> V_279 = F_133 ( V_2 ) ;
V_198 -> V_7 = V_2 -> V_4 . V_6 -> V_7 ;
V_198 -> V_10 = V_2 -> V_4 . V_6 -> V_10 ;
V_198 -> V_11 = V_2 -> V_4 . V_6 -> V_11 ;
V_198 -> V_280 = V_2 -> V_4 . V_280 ;
V_198 -> V_281 = V_2 -> V_4 . V_6 -> V_281 ;
V_198 -> V_282 = V_2 -> V_4 . V_6 -> V_282 ;
V_198 -> V_283 = V_2 -> V_4 . V_6 -> V_283 ;
V_198 -> V_284 = V_2 -> V_4 . V_6 -> V_284 ;
V_198 -> V_285 = V_2 -> V_4 . V_6 -> V_285 ;
V_198 -> V_286 = V_2 -> V_4 . V_6 -> V_286 ;
V_198 -> V_287 = V_2 -> V_4 . V_6 -> V_287 ;
V_198 -> V_288 = V_2 -> V_4 . V_6 -> V_288 ;
for ( V_3 = 0 ; V_3 < F_134 ( V_198 -> V_201 ) ; V_3 ++ )
V_198 -> V_201 [ V_3 ] = F_3 ( V_2 , V_3 ) ;
return 0 ;
}
int F_135 ( struct V_1 * V_2 , struct V_277 * V_198 )
{
int V_3 ;
V_2 -> V_4 . V_5 = V_198 -> V_5 ;
F_136 ( V_2 , V_198 -> V_278 ) ;
V_2 -> V_4 . V_9 = V_198 -> V_9 ;
V_2 -> V_4 . V_8 = V_198 -> V_8 ;
F_137 ( V_2 , V_198 -> V_279 ) ;
F_15 ( V_2 , V_198 -> V_7 ) ;
V_2 -> V_4 . V_6 -> V_10 = V_198 -> V_10 ;
V_2 -> V_4 . V_6 -> V_11 = V_198 -> V_11 ;
F_138 ( V_2 , V_198 -> V_280 ) ;
V_2 -> V_4 . V_6 -> V_281 = V_198 -> V_281 ;
V_2 -> V_4 . V_6 -> V_282 = V_198 -> V_282 ;
V_2 -> V_4 . V_6 -> V_283 = V_198 -> V_283 ;
V_2 -> V_4 . V_6 -> V_284 = V_198 -> V_284 ;
V_2 -> V_4 . V_6 -> V_285 = V_198 -> V_285 ;
V_2 -> V_4 . V_6 -> V_286 = V_198 -> V_286 ;
V_2 -> V_4 . V_6 -> V_287 = V_198 -> V_287 ;
V_2 -> V_4 . V_6 -> V_288 = V_198 -> V_288 ;
for ( V_3 = 0 ; V_3 < F_134 ( V_198 -> V_201 ) ; V_3 ++ )
F_108 ( V_2 , V_3 , V_198 -> V_201 [ V_3 ] ) ;
return 0 ;
}
static void F_139 ( struct V_1 * V_2 ,
struct V_289 * V_290 )
{
T_3 V_104 = F_53 () ;
V_290 -> V_291 . V_292 . V_293 |= V_294 ;
V_290 -> V_291 . V_292 . V_43 = V_2 -> V_4 . V_43 ;
V_290 -> V_291 . V_292 . V_44 = V_2 -> V_4 . V_44 ;
V_290 -> V_291 . V_292 . V_295 = V_2 -> V_4 . V_295 ;
V_290 -> V_291 . V_292 . V_54 = F_43 ( V_2 ) ;
V_290 -> V_291 . V_292 . V_52 = F_40 ( V_2 ) ;
V_290 -> V_291 . V_292 . V_112 = V_2 -> V_4 . V_112 ;
V_290 -> V_291 . V_292 . V_109 = V_2 -> V_4 . V_109 ;
V_290 -> V_291 . V_292 . V_296 = F_140 ( V_2 , V_104 ) ;
V_290 -> V_291 . V_292 . V_104 = V_104 ;
V_290 -> V_291 . V_292 . V_297 = V_2 -> V_4 . V_297 ;
}
static int F_141 ( struct V_1 * V_2 ,
struct V_289 * V_290 )
{
if ( ! ( V_290 -> V_291 . V_292 . V_293 & V_294 ) )
return 0 ;
V_2 -> V_4 . V_43 = V_290 -> V_291 . V_292 . V_43 ;
V_2 -> V_4 . V_44 = V_290 -> V_291 . V_292 . V_44 ;
V_2 -> V_4 . V_295 = V_290 -> V_291 . V_292 . V_295 ;
F_44 ( V_2 , V_290 -> V_291 . V_292 . V_54 ) ;
F_42 ( V_2 , V_290 -> V_291 . V_292 . V_52 ) ;
V_2 -> V_4 . V_297 = V_290 -> V_291 . V_292 . V_297 ;
F_142 ( V_2 , V_290 -> V_291 . V_292 . V_109 ) ;
if ( V_290 -> V_291 . V_292 . V_298 & V_299 ) {
V_2 -> V_4 . V_296 = V_290 -> V_291 . V_292 . V_296 ;
F_143 ( V_2 ) ;
}
if ( V_290 -> V_291 . V_292 . V_298 & V_300 )
F_121 ( V_2 , V_290 -> V_291 . V_292 . V_112 ) ;
return 0 ;
}
static void F_144 ( struct V_1 * V_2 ,
struct V_289 * V_290 )
{
V_290 -> V_291 . V_292 . V_293 |= V_301 ;
V_290 -> V_291 . V_292 . V_271 = V_2 -> V_272 ;
V_290 -> V_291 . V_292 . V_48 = V_2 -> V_4 . V_48 ;
V_290 -> V_291 . V_292 . V_49 = V_2 -> V_4 . V_49 ;
V_290 -> V_291 . V_292 . V_302 = V_2 -> V_4 . V_302 ;
V_290 -> V_291 . V_292 . V_91 = V_2 -> V_4 . V_91 ;
}
static int F_145 ( struct V_1 * V_2 ,
struct V_289 * V_290 )
{
if ( ! ( V_290 -> V_291 . V_292 . V_293 & V_301 ) )
return 0 ;
if ( V_290 -> V_291 . V_292 . V_271 != V_2 -> V_272 )
return - V_153 ;
V_2 -> V_4 . V_48 = V_290 -> V_291 . V_292 . V_48 ;
V_2 -> V_4 . V_49 = V_290 -> V_291 . V_292 . V_49 ;
V_2 -> V_4 . V_302 = V_290 -> V_291 . V_292 . V_302 ;
V_2 -> V_4 . V_91 = V_290 -> V_291 . V_292 . V_91 ;
return 0 ;
}
int F_146 ( struct V_1 * V_2 , struct V_289 * V_290 )
{
V_290 -> V_291 . V_292 . V_293 |= V_303 ;
V_290 -> V_291 . V_292 . V_304 [ 0 ] = V_2 -> V_4 . V_92 [ V_81 ] ;
V_290 -> V_291 . V_292 . V_304 [ 1 ] = V_2 -> V_4 . V_92 [ V_84 ] ;
V_290 -> V_291 . V_292 . V_304 [ 2 ] = V_2 -> V_4 . V_92 [ V_29 ] ;
V_290 -> V_291 . V_292 . V_304 [ 3 ] = V_2 -> V_4 . V_92 [ V_30 ] ;
V_290 -> V_291 . V_292 . V_304 [ 4 ] = V_2 -> V_4 . V_92 [ V_37 ] ;
V_290 -> V_291 . V_292 . V_304 [ 5 ] = V_2 -> V_4 . V_92 [ V_31 ] ;
V_290 -> V_291 . V_292 . V_304 [ 6 ] = V_2 -> V_4 . V_92 [ V_32 ] ;
V_290 -> V_291 . V_292 . V_304 [ 7 ] = V_2 -> V_4 . V_92 [ V_73 ] ;
V_290 -> V_291 . V_292 . V_304 [ 8 ] = V_2 -> V_4 . V_92 [ V_72 ] ;
V_290 -> V_291 . V_292 . V_304 [ 9 ] = V_2 -> V_4 . V_92 [ V_77 ] ;
V_290 -> V_291 . V_292 . V_304 [ 10 ] = V_2 -> V_4 . V_92 [ V_33 ] ;
V_290 -> V_291 . V_292 . V_304 [ 11 ] = V_2 -> V_4 . V_92 [ V_86 ] ;
V_290 -> V_291 . V_292 . V_304 [ 12 ] = V_2 -> V_4 . V_92 [ V_40 ] ;
V_290 -> V_291 . V_292 . V_304 [ 13 ] = V_2 -> V_4 . V_92 [ V_28 ] ;
V_290 -> V_291 . V_292 . V_304 [ 14 ] = V_2 -> V_4 . V_92 [ V_71 ] ;
V_290 -> V_291 . V_292 . V_304 [ 15 ] = V_2 -> V_4 . V_92 [ V_89 ] ;
return 0 ;
}
int F_147 ( struct V_1 * V_2 , struct V_289 * V_290 )
{
if ( ! ( V_290 -> V_291 . V_292 . V_293 & V_303 ) )
return 0 ;
V_2 -> V_4 . V_92 [ V_81 ] = V_290 -> V_291 . V_292 . V_304 [ 0 ] ;
V_2 -> V_4 . V_92 [ V_84 ] = V_290 -> V_291 . V_292 . V_304 [ 1 ] ;
V_2 -> V_4 . V_92 [ V_29 ] = V_290 -> V_291 . V_292 . V_304 [ 2 ] ;
V_2 -> V_4 . V_92 [ V_30 ] = V_290 -> V_291 . V_292 . V_304 [ 3 ] ;
V_2 -> V_4 . V_92 [ V_37 ] = V_290 -> V_291 . V_292 . V_304 [ 4 ] ;
V_2 -> V_4 . V_92 [ V_31 ] = V_290 -> V_291 . V_292 . V_304 [ 5 ] ;
V_2 -> V_4 . V_92 [ V_32 ] = V_290 -> V_291 . V_292 . V_304 [ 6 ] ;
V_2 -> V_4 . V_92 [ V_73 ] = V_290 -> V_291 . V_292 . V_304 [ 7 ] ;
V_2 -> V_4 . V_92 [ V_72 ] = V_290 -> V_291 . V_292 . V_304 [ 8 ] ;
V_2 -> V_4 . V_92 [ V_77 ] = V_290 -> V_291 . V_292 . V_304 [ 9 ] ;
V_2 -> V_4 . V_92 [ V_33 ] = V_290 -> V_291 . V_292 . V_304 [ 10 ] ;
V_2 -> V_4 . V_92 [ V_86 ] = V_290 -> V_291 . V_292 . V_304 [ 11 ] ;
V_2 -> V_4 . V_92 [ V_40 ] = V_290 -> V_291 . V_292 . V_304 [ 12 ] ;
V_2 -> V_4 . V_92 [ V_28 ] = V_290 -> V_291 . V_292 . V_304 [ 13 ] ;
V_2 -> V_4 . V_92 [ V_71 ] = V_290 -> V_291 . V_292 . V_304 [ 14 ] ;
V_2 -> V_4 . V_92 [ V_89 ] = V_290 -> V_291 . V_292 . V_304 [ 15 ] ;
return 0 ;
}
int F_148 ( struct V_1 * V_2 ,
struct V_289 * V_290 )
{
V_290 -> V_305 = V_2 -> V_4 . V_305 ;
F_139 ( V_2 , V_290 ) ;
F_144 ( V_2 , V_290 ) ;
return V_2 -> V_257 -> V_4 . V_306 -> V_307 ( V_2 , V_290 ) ;
}
int F_149 ( struct V_1 * V_2 ,
struct V_289 * V_290 )
{
int V_147 ;
if ( V_2 -> V_4 . V_305 != V_290 -> V_305 )
return - V_153 ;
V_147 = F_141 ( V_2 , V_290 ) ;
if ( V_147 < 0 )
return V_147 ;
V_147 = F_145 ( V_2 , V_290 ) ;
if ( V_147 < 0 )
return V_147 ;
return V_2 -> V_257 -> V_4 . V_306 -> V_308 ( V_2 , V_290 ) ;
}
int F_150 ( struct V_1 * V_2 , struct V_309 * V_310 )
{
int V_134 = 0 ;
union V_311 V_312 ;
int V_313 ;
V_313 = F_151 ( V_310 -> V_314 ) ;
if ( V_313 > sizeof( V_312 ) )
return - V_153 ;
switch ( V_310 -> V_314 ) {
case V_315 :
V_312 = F_152 ( V_310 -> V_314 , V_2 -> V_4 . V_180 . V_316 ) ;
break;
case V_317 :
V_312 = F_152 ( V_310 -> V_314 , V_2 -> V_4 . V_180 . V_318 ) ;
break;
#if V_319 > 2
case V_320 :
V_312 = F_152 ( V_310 -> V_314 , V_2 -> V_4 . V_180 . V_321 ) ;
break;
case V_322 :
V_312 = F_152 ( V_310 -> V_314 , V_2 -> V_4 . V_180 . V_323 ) ;
break;
#endif
case V_324 :
V_312 = F_152 ( V_310 -> V_314 , V_2 -> V_4 . V_180 . V_195 ) ;
break;
case V_325 :
V_312 = F_152 ( V_310 -> V_314 , V_2 -> V_4 . V_180 . V_196 ) ;
break;
case V_326 : {
T_1 V_56 = F_45 ( V_2 ) ;
V_312 = F_152 ( V_310 -> V_314 , V_56 ) ;
break;
}
#if F_13 ( V_98 )
case V_327 :
V_312 = F_152 ( V_310 -> V_314 , V_2 -> V_4 . V_99 ) ;
break;
#endif
case V_328 :
V_312 = F_152 ( V_310 -> V_314 , V_2 -> V_4 . V_109 ) ;
break;
case V_329 :
V_312 = F_152 ( V_310 -> V_314 , V_2 -> V_4 . V_112 ) ;
break;
case V_330 :
V_312 = F_152 ( V_310 -> V_314 , V_331 ) ;
break;
case V_332 :
V_312 = F_152 ( V_310 -> V_314 , V_2 -> V_4 . V_297 ) ;
break;
default:
V_134 = V_2 -> V_257 -> V_4 . V_306 -> V_333 ( V_2 , V_310 -> V_314 , & V_312 ) ;
break;
}
if ( V_134 )
return V_134 ;
if ( F_153 ( ( char V_334 * ) ( unsigned long ) V_310 -> V_335 , & V_312 , V_313 ) )
V_134 = - V_336 ;
return V_134 ;
}
int F_154 ( struct V_1 * V_2 , struct V_309 * V_310 )
{
int V_134 = 0 ;
union V_311 V_312 ;
int V_313 ;
V_313 = F_151 ( V_310 -> V_314 ) ;
if ( V_313 > sizeof( V_312 ) )
return - V_153 ;
if ( F_155 ( & V_312 , ( char V_334 * ) ( unsigned long ) V_310 -> V_335 , V_313 ) )
return - V_336 ;
switch ( V_310 -> V_314 ) {
case V_315 :
V_2 -> V_4 . V_180 . V_316 = F_156 ( V_310 -> V_314 , V_312 ) ;
break;
case V_317 :
V_2 -> V_4 . V_180 . V_318 = F_156 ( V_310 -> V_314 , V_312 ) ;
break;
#if V_319 > 2
case V_320 :
V_2 -> V_4 . V_180 . V_321 = F_156 ( V_310 -> V_314 , V_312 ) ;
break;
case V_322 :
V_2 -> V_4 . V_180 . V_323 = F_156 ( V_310 -> V_314 , V_312 ) ;
break;
#endif
case V_324 :
V_2 -> V_4 . V_180 . V_195 = F_156 ( V_310 -> V_314 , V_312 ) ;
break;
case V_325 :
V_2 -> V_4 . V_180 . V_196 = F_156 ( V_310 -> V_314 , V_312 ) ;
break;
case V_326 : {
T_1 V_337 = F_156 ( V_310 -> V_314 , V_312 ) ;
F_157 ( V_2 , V_337 ) ;
break;
}
#if F_13 ( V_98 )
case V_327 : {
T_1 V_338 = F_156 ( V_310 -> V_314 , V_312 ) ;
F_158 ( V_2 , V_338 ) ;
break;
}
#endif
case V_339 : {
T_1 V_340 = F_156 ( V_310 -> V_314 , V_312 ) ;
F_159 ( V_2 , V_340 ) ;
break;
}
case V_341 : {
T_1 V_340 = F_156 ( V_310 -> V_314 , V_312 ) ;
F_160 ( V_2 , V_340 ) ;
break;
}
case V_329 : {
T_1 V_112 = F_156 ( V_310 -> V_314 , V_312 ) ;
F_121 ( V_2 , V_112 ) ;
break;
}
case V_328 : {
T_1 V_109 = F_156 ( V_310 -> V_314 , V_312 ) ;
F_142 ( V_2 , V_109 ) ;
break;
}
case V_332 :
V_2 -> V_4 . V_297 = F_156 ( V_310 -> V_314 , V_312 ) ;
break;
default:
V_134 = V_2 -> V_257 -> V_4 . V_306 -> V_342 ( V_2 , V_310 -> V_314 , & V_312 ) ;
break;
}
return V_134 ;
}
int F_161 ( struct V_1 * V_2 , struct V_343 * V_344 )
{
return - V_345 ;
}
int F_162 ( struct V_1 * V_2 , struct V_343 * V_344 )
{
return - V_345 ;
}
int F_163 ( struct V_1 * V_2 ,
struct V_346 * V_347 )
{
int V_134 ;
V_134 = F_164 ( V_2 , V_347 ) ;
return V_134 ;
}
int F_165 ( struct V_257 * V_257 , struct V_348 * log )
{
return - V_345 ;
}
void F_166 ( struct V_257 * V_257 , struct V_349 * free ,
struct V_349 * V_350 )
{
}
int F_167 ( struct V_257 * V_257 , struct V_349 * V_351 ,
unsigned long V_352 )
{
return 0 ;
}
int F_168 ( struct V_257 * V_257 ,
struct V_349 * V_353 ,
struct V_354 * V_355 )
{
return 0 ;
}
void F_169 ( struct V_257 * V_257 ,
struct V_354 * V_355 ,
const struct V_349 * V_356 )
{
}
void F_170 ( struct V_257 * V_257 , struct V_349 * V_353 )
{
}
void F_158 ( struct V_1 * V_2 , T_1 V_338 )
{
#if F_13 ( V_98 )
V_2 -> V_4 . V_99 = V_338 ;
#ifdef V_16
V_2 -> V_4 . V_357 &= ~ V_358 ;
if ( V_2 -> V_4 . V_99 & V_100 )
V_2 -> V_4 . V_357 |= V_358 ;
#endif
#endif
}
void F_142 ( struct V_1 * V_2 , T_1 V_359 )
{
V_2 -> V_4 . V_109 = V_359 ;
F_56 ( V_2 ) ;
F_65 ( V_2 ) ;
}
void F_159 ( struct V_1 * V_2 , T_1 V_340 )
{
F_171 ( V_340 , & V_2 -> V_4 . V_112 ) ;
F_63 () ;
F_47 ( V_124 , V_2 ) ;
F_64 ( V_2 ) ;
}
void F_160 ( struct V_1 * V_2 , T_1 V_340 )
{
F_172 ( V_340 , & V_2 -> V_4 . V_112 ) ;
if ( V_340 & ( V_113 | V_114 ) )
F_56 ( V_2 ) ;
F_65 ( V_2 ) ;
}
void F_173 ( unsigned long V_121 )
{
struct V_1 * V_2 = (struct V_1 * ) V_121 ;
if ( V_2 -> V_4 . V_109 & V_360 ) {
V_2 -> V_4 . V_296 = V_2 -> V_4 . V_302 ;
F_143 ( V_2 ) ;
}
F_159 ( V_2 , V_128 ) ;
}
static int F_174 ( struct V_149 * V_180 ,
T_6 V_335 , int V_361 )
{
switch ( V_361 ) {
case 0 :
V_180 -> V_362 |= V_363 ;
V_180 -> V_316 = V_335 ;
break;
case 1 :
V_180 -> V_362 |= V_364 ;
V_180 -> V_318 = V_335 ;
break;
#if V_319 > 2
case 2 :
V_180 -> V_362 |= V_365 ;
V_180 -> V_321 = V_335 ;
break;
case 3 :
V_180 -> V_362 |= V_366 ;
V_180 -> V_323 = V_335 ;
break;
#endif
default:
return - V_153 ;
}
V_180 -> V_362 |= V_367 ;
return 0 ;
}
static int F_175 ( struct V_149 * V_180 , T_6 V_335 ,
int type , int V_361 )
{
switch ( V_361 ) {
case 0 :
if ( type & V_194 )
V_180 -> V_362 |= V_368 ;
if ( type & V_191 )
V_180 -> V_362 |= V_369 ;
V_180 -> V_195 = V_335 ;
break;
case 1 :
if ( type & V_194 )
V_180 -> V_362 |= V_370 ;
if ( type & V_191 )
V_180 -> V_362 |= V_371 ;
V_180 -> V_196 = V_335 ;
break;
default:
return - V_153 ;
}
V_180 -> V_362 |= V_367 ;
return 0 ;
}
void F_176 ( struct V_1 * V_2 , T_2 V_372 , bool V_373 )
{
#ifdef V_16
F_48 ( V_372 & ~ ( V_374 | V_375 | V_376 ) ) ;
if ( V_373 ) {
if ( V_372 & V_377 )
V_2 -> V_4 . V_378 |= V_374 ;
if ( V_372 & V_18 )
V_2 -> V_4 . V_378 |= V_375 ;
if ( V_372 & V_379 )
V_2 -> V_4 . V_378 |= V_376 ;
} else {
if ( V_372 & V_377 )
V_2 -> V_4 . V_378 &= ~ V_374 ;
if ( V_372 & V_18 )
V_2 -> V_4 . V_378 &= ~ V_375 ;
if ( V_372 & V_379 )
V_2 -> V_4 . V_378 &= ~ V_376 ;
}
#endif
}
int F_177 ( struct V_1 * V_2 ,
struct V_380 * V_381 )
{
struct V_149 * V_180 ;
int V_382 , V_383 = 0 , V_384 = 0 ;
if ( ! ( V_381 -> V_385 & V_386 ) ) {
V_2 -> V_4 . V_156 . V_362 = 0 ;
V_2 -> V_19 = 0 ;
F_176 ( V_2 , V_18 , false ) ;
return 0 ;
}
F_176 ( V_2 , V_18 , true ) ;
V_2 -> V_19 = V_381 -> V_385 ;
V_2 -> V_4 . V_156 . V_362 = 0 ;
V_2 -> V_4 . V_180 . V_362 = V_387 ;
if ( V_2 -> V_19 & V_388 )
V_2 -> V_4 . V_156 . V_362 |= V_367 | V_389 ;
V_180 = & ( V_2 -> V_4 . V_156 ) ;
#ifdef V_16
V_180 -> V_390 = 0 ;
V_180 -> V_391 = 0 ;
#else
V_180 -> V_390 = V_392 | V_393 | V_394 |
V_395 ;
V_180 -> V_391 = V_396 | V_397 ;
#endif
if ( ! ( V_2 -> V_19 & V_398 ) )
return 0 ;
for ( V_382 = 0 ; V_382 < ( V_399 + V_400 ) ; V_382 ++ ) {
T_6 V_335 = V_381 -> V_4 . V_401 [ V_382 ] . V_335 ;
T_7 type = V_381 -> V_4 . V_401 [ V_382 ] . type ;
if ( type == V_402 )
continue;
if ( type & ! ( V_194 |
V_191 |
V_188 ) )
return - V_153 ;
if ( type & V_188 ) {
if ( F_174 ( V_180 , V_335 , V_383 ++ ) )
return - V_153 ;
} else {
if ( F_175 ( V_180 , V_335 ,
type , V_384 ++ ) )
return - V_153 ;
}
}
return 0 ;
}
void F_178 ( struct V_1 * V_2 , int V_403 )
{
V_2 -> V_403 = F_179 () ;
V_157 -> V_158 . V_1 = V_2 ;
}
void F_180 ( struct V_1 * V_2 )
{
V_157 -> V_158 . V_1 = NULL ;
V_2 -> V_403 = - 1 ;
F_101 () ;
}
void F_181 ( struct V_1 * V_2 )
{
V_2 -> V_257 -> V_4 . V_306 -> V_404 ( V_2 ) ;
}
int F_182 ( struct V_257 * V_257 )
{
return V_257 -> V_4 . V_306 -> V_405 ( V_257 ) ;
}
struct V_1 * F_183 ( struct V_257 * V_257 , unsigned int V_314 )
{
return V_257 -> V_4 . V_306 -> V_406 ( V_257 , V_314 ) ;
}
void F_184 ( struct V_1 * V_2 )
{
V_2 -> V_257 -> V_4 . V_306 -> V_407 ( V_2 ) ;
}
void F_185 ( struct V_257 * V_257 )
{
V_257 -> V_4 . V_306 -> V_408 ( V_257 ) ;
}
void F_186 ( struct V_1 * V_2 , int V_403 )
{
V_2 -> V_257 -> V_4 . V_306 -> V_409 ( V_2 , V_403 ) ;
}
void F_187 ( struct V_1 * V_2 )
{
V_2 -> V_257 -> V_4 . V_306 -> V_410 ( V_2 ) ;
}
int T_8 F_188 ( void )
{
#ifndef V_16
unsigned long V_92 [ 16 ] ;
unsigned long * V_411 = V_412 ;
unsigned long V_413 = 0 ;
unsigned long V_414 ;
int V_3 ;
V_415 = F_189 ( V_416 | V_417 ,
V_418 ) ;
if ( ! V_415 )
return - V_419 ;
V_92 [ 0 ] = F_41 ( V_420 ) ;
V_92 [ 1 ] = F_41 ( V_421 ) ;
V_92 [ 2 ] = F_41 ( V_422 ) ;
V_92 [ 3 ] = F_41 ( V_423 ) ;
V_92 [ 4 ] = F_41 ( V_424 ) ;
V_92 [ 5 ] = F_41 ( V_425 ) ;
V_92 [ 6 ] = F_41 ( V_426 ) ;
V_92 [ 7 ] = F_41 ( V_427 ) ;
V_92 [ 8 ] = F_41 ( V_428 ) ;
V_92 [ 9 ] = F_41 ( V_429 ) ;
V_92 [ 10 ] = F_41 ( V_430 ) ;
V_92 [ 11 ] = F_41 ( V_431 ) ;
V_92 [ 12 ] = F_41 ( V_432 ) ;
V_92 [ 13 ] = F_41 ( V_433 ) ;
V_92 [ 14 ] = F_41 ( V_434 ) ;
V_92 [ 15 ] = F_41 ( V_435 ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( V_92 [ V_3 ] > V_413 )
V_413 = V_3 ;
V_414 = V_411 [ V_3 + 1 ] - V_411 [ V_3 ] ;
memcpy ( ( void * ) V_415 + V_92 [ V_3 ] ,
( void * ) V_411 [ V_3 ] , V_414 ) ;
}
V_414 = V_411 [ V_413 + 1 ] - V_411 [ V_413 ] ;
F_190 ( V_415 , V_415 +
V_92 [ V_413 ] + V_414 ) ;
#endif
return 0 ;
}
void T_9 F_191 ( void )
{
F_192 ( V_415 , V_418 ) ;
F_193 () ;
}
