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
#ifdef V_15
struct V_151 V_152 ;
int V_153 ;
#endif
if ( ! V_2 -> V_4 . V_154 ) {
V_146 -> V_142 = V_155 ;
return - V_156 ;
}
F_74 () ;
V_148 = F_80 ( V_2 ) ;
if ( V_148 <= 0 ) {
F_72 () ;
V_147 = V_148 ;
goto V_157;
}
#ifdef V_15
F_81 () ;
V_152 = V_158 -> V_159 . V_160 ;
V_153 = V_158 -> V_159 . V_153 ;
memcpy ( V_158 -> V_159 . V_160 . V_161 , V_2 -> V_4 . V_161 ,
sizeof( V_2 -> V_4 . V_161 ) ) ;
V_158 -> V_159 . V_160 . V_162 = V_2 -> V_4 . V_162 ;
V_2 -> V_163 = 1 ;
F_82 ( V_2 ) ;
#endif
V_150 = V_2 -> V_4 . V_164 ;
F_83 ( & V_150 ) ;
V_150 = V_158 -> V_159 . V_150 ;
V_158 -> V_159 . V_150 = V_2 -> V_4 . V_164 ;
F_84 () ;
V_147 = F_85 ( V_146 , V_2 ) ;
F_83 ( & V_150 ) ;
V_158 -> V_159 . V_150 = V_150 ;
#ifdef V_15
F_86 ( V_2 ) ;
V_2 -> V_163 = 0 ;
memcpy ( V_2 -> V_4 . V_161 , V_158 -> V_159 . V_160 . V_161 ,
sizeof( V_2 -> V_4 . V_161 ) ) ;
V_2 -> V_4 . V_162 = V_158 -> V_159 . V_160 . V_162 ;
V_158 -> V_159 . V_160 = V_152 ;
V_158 -> V_159 . V_153 = V_153 ;
#endif
V_157:
V_2 -> V_165 = V_166 ;
return V_147 ;
}
static int F_87 ( struct V_146 * V_141 , struct V_1 * V_2 )
{
enum V_167 V_168 ;
V_168 = F_88 ( V_141 , V_2 ) ;
switch ( V_168 ) {
case V_169 :
F_89 ( V_2 , V_170 ) ;
return V_171 ;
case V_172 :
V_141 -> V_142 = V_173 ;
return V_174 ;
case V_175 :
F_2 ( V_176 L_6 ,
V_177 , V_2 -> V_4 . V_5 , V_2 -> V_4 . V_178 ) ;
V_141 -> V_179 . V_180 = ~ 0ULL << 32 ;
V_141 -> V_179 . V_180 |= V_2 -> V_4 . V_178 ;
F_24 ( V_2 , V_181 ) ;
return V_174 ;
case V_182 :
return V_174 ;
default:
F_90 () ;
}
}
static int F_91 ( struct V_146 * V_141 , struct V_1 * V_2 )
{
struct V_149 * V_183 = & ( V_2 -> V_4 . V_164 ) ;
T_1 V_184 = V_2 -> V_4 . V_184 ;
V_141 -> V_150 . V_4 . V_185 = 0 ;
V_141 -> V_150 . V_4 . V_186 = V_2 -> V_4 . V_5 ;
if ( V_184 & ( V_187 | V_188 | V_189 | V_190 ) ) {
V_141 -> V_150 . V_4 . V_185 |= V_191 ;
} else {
if ( V_184 & ( V_192 | V_193 ) )
V_141 -> V_150 . V_4 . V_185 |= V_194 ;
else if ( V_184 & ( V_195 | V_196 ) )
V_141 -> V_150 . V_4 . V_185 |= V_197 ;
if ( V_184 & ( V_195 | V_192 ) )
V_141 -> V_150 . V_4 . V_186 = V_183 -> V_198 ;
else if ( V_184 & ( V_196 | V_193 ) )
V_141 -> V_150 . V_4 . V_186 = V_183 -> V_199 ;
}
return V_174 ;
}
static void F_92 ( struct V_200 * V_201 )
{
T_2 V_202 , V_203 , V_7 , V_8 ;
asm("mr %0, 1" : "=r"(r1));
asm("mflr %0" : "=r"(lr));
asm("mfmsr %0" : "=r"(msr));
asm("bl 1f; 1: mflr %0" : "=r"(ip));
memset ( V_201 , 0 , sizeof( * V_201 ) ) ;
V_201 -> V_204 [ 1 ] = V_202 ;
V_201 -> V_205 = V_203 ;
V_201 -> V_7 = V_7 ;
V_201 -> V_206 = V_8 ;
}
static void F_93 ( struct V_1 * V_2 ,
unsigned int V_207 )
{
struct V_200 V_201 ;
switch ( V_207 ) {
case V_208 :
F_92 ( & V_201 ) ;
F_94 ( & V_201 ) ;
break;
case V_209 :
F_92 ( & V_201 ) ;
F_95 ( & V_201 ) ;
break;
#if F_13 ( V_210 )
case V_211 :
F_92 ( & V_201 ) ;
F_96 ( & V_201 ) ;
break;
#endif
case V_212 :
break;
case V_213 :
F_92 ( & V_201 ) ;
F_97 ( & V_201 ) ;
break;
case V_214 :
F_92 ( & V_201 ) ;
#ifdef F_98
F_99 ( & V_201 ) ;
#else
F_100 ( & V_201 ) ;
#endif
break;
case V_215 :
F_100 ( & V_201 ) ;
break;
case V_216 :
V_2 -> V_4 . V_184 = F_41 ( V_217 ) ;
F_101 () ;
break;
}
}
int F_102 ( struct V_146 * V_141 , struct V_1 * V_2 ,
unsigned int V_207 )
{
int V_134 = V_174 ;
int V_148 ;
int V_218 ;
#ifdef F_103
F_104 ( V_219 -> V_220 != 0 ) ;
#endif
F_105 () ;
F_106 ( V_2 ) ;
F_93 ( V_2 , V_207 ) ;
F_72 () ;
F_107 ( V_207 , V_2 ) ;
F_108 () ;
V_141 -> V_142 = V_221 ;
V_141 -> V_222 = 1 ;
switch ( V_207 ) {
case V_212 :
F_2 ( L_7 , F_41 ( V_223 ) ) ;
F_1 ( V_2 ) ;
V_141 -> V_179 . V_180 = ~ 1ULL << 32 ;
V_141 -> V_179 . V_180 |= F_41 ( V_223 ) ;
V_134 = V_174 ;
break;
case V_208 :
F_109 ( V_2 , V_224 ) ;
V_134 = V_225 ;
break;
case V_209 :
F_109 ( V_2 , V_226 ) ;
V_134 = V_225 ;
break;
case V_214 :
V_134 = V_225 ;
break;
case V_211 :
F_109 ( V_2 , V_227 ) ;
V_134 = V_225 ;
break;
case V_228 :
F_109 ( V_2 , V_229 ) ;
V_134 = V_225 ;
break;
case V_230 :
F_109 ( V_2 , V_229 ) ;
V_134 = V_225 ;
break;
case V_213 :
V_134 = V_225 ;
break;
case V_231 :
V_134 = F_87 ( V_141 , V_2 ) ;
break;
case V_232 :
if ( V_2 -> V_4 . V_6 -> V_7 & ( V_69 | V_22 ) ) {
F_24 ( V_2 , V_2 -> V_4 . V_233 ) ;
V_134 = V_225 ;
F_109 ( V_2 , V_234 ) ;
break;
}
V_134 = F_87 ( V_141 , V_2 ) ;
break;
case V_235 :
F_17 ( V_2 , V_73 ) ;
F_109 ( V_2 , V_236 ) ;
V_134 = V_225 ;
break;
#ifdef F_110
case V_237 : {
if ( V_2 -> V_4 . V_6 -> V_7 & V_14 )
F_9 ( V_2 ) ;
else
F_17 ( V_2 ,
V_74 ) ;
V_134 = V_225 ;
break;
}
case V_238 :
F_17 ( V_2 , V_75 ) ;
V_134 = V_225 ;
break;
case V_239 :
F_17 ( V_2 , V_76 ) ;
V_134 = V_225 ;
break;
#else
case V_237 :
F_24 ( V_2 , V_240 | V_241 ) ;
V_134 = V_225 ;
break;
case V_238 :
case V_239 :
F_2 ( V_176 L_8 ,
V_177 , V_207 , V_2 -> V_4 . V_5 ) ;
V_141 -> V_179 . V_180 = V_207 ;
V_134 = V_174 ;
break;
#endif
case V_242 :
F_21 ( V_2 , V_2 -> V_4 . V_243 ,
V_2 -> V_4 . V_233 ) ;
F_109 ( V_2 , V_244 ) ;
V_134 = V_225 ;
break;
case V_245 :
F_22 ( V_2 , V_2 -> V_4 . V_233 ) ;
F_109 ( V_2 , V_246 ) ;
V_134 = V_225 ;
break;
case V_247 :
F_23 ( V_2 , V_2 -> V_4 . V_243 ,
V_2 -> V_4 . V_233 ) ;
V_134 = V_225 ;
break;
#ifdef V_16
case V_248 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_69 ) ) {
F_111 ( V_2 , 3 , F_112 ( V_2 ) ) ;
} else {
F_24 ( V_2 , V_249 ) ;
}
V_134 = V_225 ;
break;
#else
case V_250 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_69 ) &&
( ( ( T_1 ) F_3 ( V_2 , 0 ) ) == V_251 ) ) {
F_111 ( V_2 , 3 , F_112 ( V_2 ) ) ;
V_134 = V_225 ;
} else {
F_17 ( V_2 , V_72 ) ;
}
F_109 ( V_2 , V_252 ) ;
V_134 = V_225 ;
break;
#endif
case V_253 : {
unsigned long V_254 = V_2 -> V_4 . V_243 ;
int V_255 ;
T_4 V_256 ;
T_5 V_257 ;
#ifdef V_138
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_69 ) &&
( V_254 & V_258 ) == V_2 -> V_4 . V_259 ) {
F_113 ( V_2 ) ;
F_109 ( V_2 , V_260 ) ;
V_134 = V_225 ;
break;
}
#endif
V_255 = F_114 ( V_2 , V_254 ) ;
if ( V_255 < 0 ) {
F_20 ( V_2 ,
V_2 -> V_4 . V_243 ,
V_2 -> V_4 . V_233 ) ;
F_115 ( V_2 ) ;
F_109 ( V_2 , V_261 ) ;
V_134 = V_225 ;
break;
}
V_218 = F_116 ( & V_2 -> V_262 -> V_263 ) ;
V_256 = F_117 ( V_2 , V_255 , V_254 ) ;
V_257 = V_256 >> V_264 ;
if ( F_118 ( V_2 -> V_262 , V_257 ) ) {
F_119 ( V_2 , V_254 , V_256 , V_255 ) ;
F_109 ( V_2 , V_260 ) ;
V_134 = V_225 ;
} else {
V_2 -> V_4 . V_265 = V_256 ;
V_2 -> V_4 . V_266 = V_254 ;
V_134 = F_120 ( V_141 , V_2 ) ;
F_109 ( V_2 , V_267 ) ;
}
F_121 ( & V_2 -> V_262 -> V_263 , V_218 ) ;
break;
}
case V_268 : {
unsigned long V_254 = V_2 -> V_4 . V_5 ;
T_4 V_256 ;
T_5 V_257 ;
int V_255 ;
V_134 = V_225 ;
V_255 = F_122 ( V_2 , V_254 ) ;
if ( V_255 < 0 ) {
F_17 ( V_2 , V_71 ) ;
F_123 ( V_2 ) ;
F_109 ( V_2 , V_269 ) ;
break;
}
F_109 ( V_2 , V_270 ) ;
V_218 = F_116 ( & V_2 -> V_262 -> V_263 ) ;
V_256 = F_117 ( V_2 , V_255 , V_254 ) ;
V_257 = V_256 >> V_264 ;
if ( F_118 ( V_2 -> V_262 , V_257 ) ) {
F_119 ( V_2 , V_254 , V_256 , V_255 ) ;
} else {
F_17 ( V_2 , V_84 ) ;
}
F_121 ( & V_2 -> V_262 -> V_263 , V_218 ) ;
break;
}
case V_216 : {
V_134 = F_91 ( V_141 , V_2 ) ;
if ( V_134 == V_174 )
V_141 -> V_142 = V_271 ;
F_109 ( V_2 , V_272 ) ;
break;
}
default:
F_2 ( V_273 L_9 , V_207 ) ;
F_90 () ;
}
if ( ! ( V_134 & V_174 ) ) {
F_74 () ;
V_148 = F_80 ( V_2 ) ;
if ( V_148 <= 0 ) {
F_72 () ;
V_134 = ( V_148 << 2 ) | V_174 | ( V_134 & V_274 ) ;
} else {
F_84 () ;
}
}
return V_134 ;
}
static void F_124 ( struct V_1 * V_2 , T_1 V_122 )
{
T_1 V_275 = V_2 -> V_4 . V_112 ;
V_2 -> V_4 . V_112 = V_122 ;
if ( ( V_275 ^ V_2 -> V_4 . V_112 ) & ( V_113 | V_114 ) )
F_56 ( V_2 ) ;
F_65 ( V_2 ) ;
}
int F_125 ( struct V_1 * V_2 )
{
int V_3 ;
int V_134 ;
V_2 -> V_4 . V_5 = 0 ;
V_2 -> V_4 . V_6 -> V_276 = V_2 -> V_277 ;
F_111 ( V_2 , 1 , ( 16 << 20 ) - 8 ) ;
F_15 ( V_2 , 0 ) ;
#ifndef V_16
V_2 -> V_4 . V_13 = V_278 | V_279 | V_280 ;
V_2 -> V_4 . V_281 = 1 ;
V_2 -> V_4 . V_6 -> V_7 = 0 ;
#endif
V_2 -> V_4 . V_91 = 0x55550000 ;
for ( V_3 = 0 ; V_3 < V_131 ; V_3 ++ )
V_2 -> V_4 . V_92 [ V_3 ] = 0x7700 | V_3 * 4 ;
F_126 ( V_2 ) ;
V_134 = F_127 ( V_2 ) ;
F_128 ( V_2 ) ;
return V_134 ;
}
int F_129 ( struct V_1 * V_2 )
{
F_130 ( & V_2 -> V_4 . V_117 ) ;
F_131 ( & V_2 -> V_4 . V_119 , F_61 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_132 ( struct V_1 * V_2 )
{
F_133 ( & V_2 -> V_4 . V_119 ) ;
}
int F_134 ( struct V_1 * V_2 , struct V_282 * V_201 )
{
int V_3 ;
V_201 -> V_5 = V_2 -> V_4 . V_5 ;
V_201 -> V_283 = F_135 ( V_2 ) ;
V_201 -> V_9 = V_2 -> V_4 . V_9 ;
V_201 -> V_8 = V_2 -> V_4 . V_8 ;
V_201 -> V_284 = F_136 ( V_2 ) ;
V_201 -> V_7 = V_2 -> V_4 . V_6 -> V_7 ;
V_201 -> V_10 = V_2 -> V_4 . V_6 -> V_10 ;
V_201 -> V_11 = V_2 -> V_4 . V_6 -> V_11 ;
V_201 -> V_285 = V_2 -> V_4 . V_285 ;
V_201 -> V_286 = V_2 -> V_4 . V_6 -> V_286 ;
V_201 -> V_287 = V_2 -> V_4 . V_6 -> V_287 ;
V_201 -> V_288 = V_2 -> V_4 . V_6 -> V_288 ;
V_201 -> V_289 = V_2 -> V_4 . V_6 -> V_289 ;
V_201 -> V_290 = V_2 -> V_4 . V_6 -> V_290 ;
V_201 -> V_291 = V_2 -> V_4 . V_6 -> V_291 ;
V_201 -> V_292 = V_2 -> V_4 . V_6 -> V_292 ;
V_201 -> V_293 = V_2 -> V_4 . V_6 -> V_293 ;
for ( V_3 = 0 ; V_3 < F_137 ( V_201 -> V_204 ) ; V_3 ++ )
V_201 -> V_204 [ V_3 ] = F_3 ( V_2 , V_3 ) ;
return 0 ;
}
int F_138 ( struct V_1 * V_2 , struct V_282 * V_201 )
{
int V_3 ;
V_2 -> V_4 . V_5 = V_201 -> V_5 ;
F_139 ( V_2 , V_201 -> V_283 ) ;
V_2 -> V_4 . V_9 = V_201 -> V_9 ;
V_2 -> V_4 . V_8 = V_201 -> V_8 ;
F_140 ( V_2 , V_201 -> V_284 ) ;
F_15 ( V_2 , V_201 -> V_7 ) ;
V_2 -> V_4 . V_6 -> V_10 = V_201 -> V_10 ;
V_2 -> V_4 . V_6 -> V_11 = V_201 -> V_11 ;
F_141 ( V_2 , V_201 -> V_285 ) ;
V_2 -> V_4 . V_6 -> V_286 = V_201 -> V_286 ;
V_2 -> V_4 . V_6 -> V_287 = V_201 -> V_287 ;
V_2 -> V_4 . V_6 -> V_288 = V_201 -> V_288 ;
V_2 -> V_4 . V_6 -> V_289 = V_201 -> V_289 ;
V_2 -> V_4 . V_6 -> V_290 = V_201 -> V_290 ;
V_2 -> V_4 . V_6 -> V_291 = V_201 -> V_291 ;
V_2 -> V_4 . V_6 -> V_292 = V_201 -> V_292 ;
V_2 -> V_4 . V_6 -> V_293 = V_201 -> V_293 ;
for ( V_3 = 0 ; V_3 < F_137 ( V_201 -> V_204 ) ; V_3 ++ )
F_111 ( V_2 , V_3 , V_201 -> V_204 [ V_3 ] ) ;
return 0 ;
}
static void F_142 ( struct V_1 * V_2 ,
struct V_294 * V_295 )
{
T_3 V_104 = F_53 () ;
V_295 -> V_296 . V_297 . V_298 |= V_299 ;
V_295 -> V_296 . V_297 . V_43 = V_2 -> V_4 . V_43 ;
V_295 -> V_296 . V_297 . V_44 = V_2 -> V_4 . V_44 ;
V_295 -> V_296 . V_297 . V_300 = V_2 -> V_4 . V_300 ;
V_295 -> V_296 . V_297 . V_54 = F_43 ( V_2 ) ;
V_295 -> V_296 . V_297 . V_52 = F_40 ( V_2 ) ;
V_295 -> V_296 . V_297 . V_112 = V_2 -> V_4 . V_112 ;
V_295 -> V_296 . V_297 . V_109 = V_2 -> V_4 . V_109 ;
V_295 -> V_296 . V_297 . V_301 = F_143 ( V_2 , V_104 ) ;
V_295 -> V_296 . V_297 . V_104 = V_104 ;
V_295 -> V_296 . V_297 . V_302 = V_2 -> V_4 . V_302 ;
}
static int F_144 ( struct V_1 * V_2 ,
struct V_294 * V_295 )
{
if ( ! ( V_295 -> V_296 . V_297 . V_298 & V_299 ) )
return 0 ;
V_2 -> V_4 . V_43 = V_295 -> V_296 . V_297 . V_43 ;
V_2 -> V_4 . V_44 = V_295 -> V_296 . V_297 . V_44 ;
V_2 -> V_4 . V_300 = V_295 -> V_296 . V_297 . V_300 ;
F_44 ( V_2 , V_295 -> V_296 . V_297 . V_54 ) ;
F_42 ( V_2 , V_295 -> V_296 . V_297 . V_52 ) ;
V_2 -> V_4 . V_302 = V_295 -> V_296 . V_297 . V_302 ;
F_145 ( V_2 , V_295 -> V_296 . V_297 . V_109 ) ;
if ( V_295 -> V_296 . V_297 . V_303 & V_304 ) {
V_2 -> V_4 . V_301 = V_295 -> V_296 . V_297 . V_301 ;
F_146 ( V_2 ) ;
}
if ( V_295 -> V_296 . V_297 . V_303 & V_305 )
F_124 ( V_2 , V_295 -> V_296 . V_297 . V_112 ) ;
return 0 ;
}
static void F_147 ( struct V_1 * V_2 ,
struct V_294 * V_295 )
{
V_295 -> V_296 . V_297 . V_298 |= V_306 ;
V_295 -> V_296 . V_297 . V_276 = V_2 -> V_277 ;
V_295 -> V_296 . V_297 . V_48 = V_2 -> V_4 . V_48 ;
V_295 -> V_296 . V_297 . V_49 = V_2 -> V_4 . V_49 ;
V_295 -> V_296 . V_297 . V_307 = V_2 -> V_4 . V_307 ;
V_295 -> V_296 . V_297 . V_91 = V_2 -> V_4 . V_91 ;
}
static int F_148 ( struct V_1 * V_2 ,
struct V_294 * V_295 )
{
if ( ! ( V_295 -> V_296 . V_297 . V_298 & V_306 ) )
return 0 ;
if ( V_295 -> V_296 . V_297 . V_276 != V_2 -> V_277 )
return - V_156 ;
V_2 -> V_4 . V_48 = V_295 -> V_296 . V_297 . V_48 ;
V_2 -> V_4 . V_49 = V_295 -> V_296 . V_297 . V_49 ;
V_2 -> V_4 . V_307 = V_295 -> V_296 . V_297 . V_307 ;
V_2 -> V_4 . V_91 = V_295 -> V_296 . V_297 . V_91 ;
return 0 ;
}
int F_149 ( struct V_1 * V_2 , struct V_294 * V_295 )
{
V_295 -> V_296 . V_297 . V_298 |= V_308 ;
V_295 -> V_296 . V_297 . V_309 [ 0 ] = V_2 -> V_4 . V_92 [ V_81 ] ;
V_295 -> V_296 . V_297 . V_309 [ 1 ] = V_2 -> V_4 . V_92 [ V_84 ] ;
V_295 -> V_296 . V_297 . V_309 [ 2 ] = V_2 -> V_4 . V_92 [ V_29 ] ;
V_295 -> V_296 . V_297 . V_309 [ 3 ] = V_2 -> V_4 . V_92 [ V_30 ] ;
V_295 -> V_296 . V_297 . V_309 [ 4 ] = V_2 -> V_4 . V_92 [ V_37 ] ;
V_295 -> V_296 . V_297 . V_309 [ 5 ] = V_2 -> V_4 . V_92 [ V_31 ] ;
V_295 -> V_296 . V_297 . V_309 [ 6 ] = V_2 -> V_4 . V_92 [ V_32 ] ;
V_295 -> V_296 . V_297 . V_309 [ 7 ] = V_2 -> V_4 . V_92 [ V_73 ] ;
V_295 -> V_296 . V_297 . V_309 [ 8 ] = V_2 -> V_4 . V_92 [ V_72 ] ;
V_295 -> V_296 . V_297 . V_309 [ 9 ] = V_2 -> V_4 . V_92 [ V_77 ] ;
V_295 -> V_296 . V_297 . V_309 [ 10 ] = V_2 -> V_4 . V_92 [ V_33 ] ;
V_295 -> V_296 . V_297 . V_309 [ 11 ] = V_2 -> V_4 . V_92 [ V_86 ] ;
V_295 -> V_296 . V_297 . V_309 [ 12 ] = V_2 -> V_4 . V_92 [ V_40 ] ;
V_295 -> V_296 . V_297 . V_309 [ 13 ] = V_2 -> V_4 . V_92 [ V_28 ] ;
V_295 -> V_296 . V_297 . V_309 [ 14 ] = V_2 -> V_4 . V_92 [ V_71 ] ;
V_295 -> V_296 . V_297 . V_309 [ 15 ] = V_2 -> V_4 . V_92 [ V_89 ] ;
return 0 ;
}
int F_150 ( struct V_1 * V_2 , struct V_294 * V_295 )
{
if ( ! ( V_295 -> V_296 . V_297 . V_298 & V_308 ) )
return 0 ;
V_2 -> V_4 . V_92 [ V_81 ] = V_295 -> V_296 . V_297 . V_309 [ 0 ] ;
V_2 -> V_4 . V_92 [ V_84 ] = V_295 -> V_296 . V_297 . V_309 [ 1 ] ;
V_2 -> V_4 . V_92 [ V_29 ] = V_295 -> V_296 . V_297 . V_309 [ 2 ] ;
V_2 -> V_4 . V_92 [ V_30 ] = V_295 -> V_296 . V_297 . V_309 [ 3 ] ;
V_2 -> V_4 . V_92 [ V_37 ] = V_295 -> V_296 . V_297 . V_309 [ 4 ] ;
V_2 -> V_4 . V_92 [ V_31 ] = V_295 -> V_296 . V_297 . V_309 [ 5 ] ;
V_2 -> V_4 . V_92 [ V_32 ] = V_295 -> V_296 . V_297 . V_309 [ 6 ] ;
V_2 -> V_4 . V_92 [ V_73 ] = V_295 -> V_296 . V_297 . V_309 [ 7 ] ;
V_2 -> V_4 . V_92 [ V_72 ] = V_295 -> V_296 . V_297 . V_309 [ 8 ] ;
V_2 -> V_4 . V_92 [ V_77 ] = V_295 -> V_296 . V_297 . V_309 [ 9 ] ;
V_2 -> V_4 . V_92 [ V_33 ] = V_295 -> V_296 . V_297 . V_309 [ 10 ] ;
V_2 -> V_4 . V_92 [ V_86 ] = V_295 -> V_296 . V_297 . V_309 [ 11 ] ;
V_2 -> V_4 . V_92 [ V_40 ] = V_295 -> V_296 . V_297 . V_309 [ 12 ] ;
V_2 -> V_4 . V_92 [ V_28 ] = V_295 -> V_296 . V_297 . V_309 [ 13 ] ;
V_2 -> V_4 . V_92 [ V_71 ] = V_295 -> V_296 . V_297 . V_309 [ 14 ] ;
V_2 -> V_4 . V_92 [ V_89 ] = V_295 -> V_296 . V_297 . V_309 [ 15 ] ;
return 0 ;
}
int F_151 ( struct V_1 * V_2 ,
struct V_294 * V_295 )
{
V_295 -> V_310 = V_2 -> V_4 . V_310 ;
F_142 ( V_2 , V_295 ) ;
F_147 ( V_2 , V_295 ) ;
return V_2 -> V_262 -> V_4 . V_311 -> V_312 ( V_2 , V_295 ) ;
}
int F_152 ( struct V_1 * V_2 ,
struct V_294 * V_295 )
{
int V_147 ;
if ( V_2 -> V_4 . V_310 != V_295 -> V_310 )
return - V_156 ;
V_147 = F_144 ( V_2 , V_295 ) ;
if ( V_147 < 0 )
return V_147 ;
V_147 = F_148 ( V_2 , V_295 ) ;
if ( V_147 < 0 )
return V_147 ;
return V_2 -> V_262 -> V_4 . V_311 -> V_313 ( V_2 , V_295 ) ;
}
int F_153 ( struct V_1 * V_2 , struct V_314 * V_315 )
{
int V_134 = 0 ;
union V_316 V_317 ;
int V_318 ;
V_318 = F_154 ( V_315 -> V_319 ) ;
if ( V_318 > sizeof( V_317 ) )
return - V_156 ;
switch ( V_315 -> V_319 ) {
case V_320 :
V_317 = F_155 ( V_315 -> V_319 , V_2 -> V_4 . V_183 . V_321 ) ;
break;
case V_322 :
V_317 = F_155 ( V_315 -> V_319 , V_2 -> V_4 . V_183 . V_323 ) ;
break;
#if V_324 > 2
case V_325 :
V_317 = F_155 ( V_315 -> V_319 , V_2 -> V_4 . V_183 . V_326 ) ;
break;
case V_327 :
V_317 = F_155 ( V_315 -> V_319 , V_2 -> V_4 . V_183 . V_328 ) ;
break;
#endif
case V_329 :
V_317 = F_155 ( V_315 -> V_319 , V_2 -> V_4 . V_183 . V_198 ) ;
break;
case V_330 :
V_317 = F_155 ( V_315 -> V_319 , V_2 -> V_4 . V_183 . V_199 ) ;
break;
case V_331 : {
T_1 V_56 = F_45 ( V_2 ) ;
V_317 = F_155 ( V_315 -> V_319 , V_56 ) ;
break;
}
#if F_13 ( V_98 )
case V_332 :
V_317 = F_155 ( V_315 -> V_319 , V_2 -> V_4 . V_99 ) ;
break;
#endif
case V_333 :
V_317 = F_155 ( V_315 -> V_319 , V_2 -> V_4 . V_109 ) ;
break;
case V_334 :
V_317 = F_155 ( V_315 -> V_319 , V_2 -> V_4 . V_112 ) ;
break;
case V_335 :
V_317 = F_155 ( V_315 -> V_319 , V_336 ) ;
break;
case V_337 :
V_317 = F_155 ( V_315 -> V_319 , V_2 -> V_4 . V_302 ) ;
break;
default:
V_134 = V_2 -> V_262 -> V_4 . V_311 -> V_338 ( V_2 , V_315 -> V_319 , & V_317 ) ;
break;
}
if ( V_134 )
return V_134 ;
if ( F_156 ( ( char V_339 * ) ( unsigned long ) V_315 -> V_340 , & V_317 , V_318 ) )
V_134 = - V_341 ;
return V_134 ;
}
int F_157 ( struct V_1 * V_2 , struct V_314 * V_315 )
{
int V_134 = 0 ;
union V_316 V_317 ;
int V_318 ;
V_318 = F_154 ( V_315 -> V_319 ) ;
if ( V_318 > sizeof( V_317 ) )
return - V_156 ;
if ( F_158 ( & V_317 , ( char V_339 * ) ( unsigned long ) V_315 -> V_340 , V_318 ) )
return - V_341 ;
switch ( V_315 -> V_319 ) {
case V_320 :
V_2 -> V_4 . V_183 . V_321 = F_159 ( V_315 -> V_319 , V_317 ) ;
break;
case V_322 :
V_2 -> V_4 . V_183 . V_323 = F_159 ( V_315 -> V_319 , V_317 ) ;
break;
#if V_324 > 2
case V_325 :
V_2 -> V_4 . V_183 . V_326 = F_159 ( V_315 -> V_319 , V_317 ) ;
break;
case V_327 :
V_2 -> V_4 . V_183 . V_328 = F_159 ( V_315 -> V_319 , V_317 ) ;
break;
#endif
case V_329 :
V_2 -> V_4 . V_183 . V_198 = F_159 ( V_315 -> V_319 , V_317 ) ;
break;
case V_330 :
V_2 -> V_4 . V_183 . V_199 = F_159 ( V_315 -> V_319 , V_317 ) ;
break;
case V_331 : {
T_1 V_342 = F_159 ( V_315 -> V_319 , V_317 ) ;
F_160 ( V_2 , V_342 ) ;
break;
}
#if F_13 ( V_98 )
case V_332 : {
T_1 V_343 = F_159 ( V_315 -> V_319 , V_317 ) ;
F_161 ( V_2 , V_343 ) ;
break;
}
#endif
case V_344 : {
T_1 V_345 = F_159 ( V_315 -> V_319 , V_317 ) ;
F_162 ( V_2 , V_345 ) ;
break;
}
case V_346 : {
T_1 V_345 = F_159 ( V_315 -> V_319 , V_317 ) ;
F_163 ( V_2 , V_345 ) ;
break;
}
case V_334 : {
T_1 V_112 = F_159 ( V_315 -> V_319 , V_317 ) ;
F_124 ( V_2 , V_112 ) ;
break;
}
case V_333 : {
T_1 V_109 = F_159 ( V_315 -> V_319 , V_317 ) ;
F_145 ( V_2 , V_109 ) ;
break;
}
case V_337 :
V_2 -> V_4 . V_302 = F_159 ( V_315 -> V_319 , V_317 ) ;
break;
default:
V_134 = V_2 -> V_262 -> V_4 . V_311 -> V_347 ( V_2 , V_315 -> V_319 , & V_317 ) ;
break;
}
return V_134 ;
}
int F_164 ( struct V_1 * V_2 , struct V_348 * V_349 )
{
return - V_350 ;
}
int F_165 ( struct V_1 * V_2 , struct V_348 * V_349 )
{
return - V_350 ;
}
int F_166 ( struct V_1 * V_2 ,
struct V_351 * V_352 )
{
int V_134 ;
V_134 = F_167 ( V_2 , V_352 ) ;
return V_134 ;
}
int F_168 ( struct V_262 * V_262 , struct V_353 * log )
{
return - V_350 ;
}
void F_169 ( struct V_262 * V_262 , struct V_354 * free ,
struct V_354 * V_355 )
{
}
int F_170 ( struct V_262 * V_262 , struct V_354 * V_356 ,
unsigned long V_357 )
{
return 0 ;
}
int F_171 ( struct V_262 * V_262 ,
struct V_354 * V_358 ,
struct V_359 * V_360 )
{
return 0 ;
}
void F_172 ( struct V_262 * V_262 ,
struct V_359 * V_360 ,
const struct V_354 * V_361 )
{
}
void F_173 ( struct V_262 * V_262 , struct V_354 * V_358 )
{
}
void F_161 ( struct V_1 * V_2 , T_1 V_343 )
{
#if F_13 ( V_98 )
V_2 -> V_4 . V_99 = V_343 ;
#ifdef V_16
V_2 -> V_4 . V_362 &= ~ V_363 ;
if ( V_2 -> V_4 . V_99 & V_100 )
V_2 -> V_4 . V_362 |= V_363 ;
#endif
#endif
}
void F_145 ( struct V_1 * V_2 , T_1 V_364 )
{
V_2 -> V_4 . V_109 = V_364 ;
F_56 ( V_2 ) ;
F_65 ( V_2 ) ;
}
void F_162 ( struct V_1 * V_2 , T_1 V_345 )
{
F_174 ( V_345 , & V_2 -> V_4 . V_112 ) ;
F_63 () ;
F_47 ( V_124 , V_2 ) ;
F_64 ( V_2 ) ;
}
void F_163 ( struct V_1 * V_2 , T_1 V_345 )
{
F_175 ( V_345 , & V_2 -> V_4 . V_112 ) ;
if ( V_345 & ( V_113 | V_114 ) )
F_56 ( V_2 ) ;
F_65 ( V_2 ) ;
}
void F_176 ( unsigned long V_121 )
{
struct V_1 * V_2 = (struct V_1 * ) V_121 ;
if ( V_2 -> V_4 . V_109 & V_365 ) {
V_2 -> V_4 . V_301 = V_2 -> V_4 . V_307 ;
F_146 ( V_2 ) ;
}
F_162 ( V_2 , V_128 ) ;
}
static int F_177 ( struct V_149 * V_183 ,
T_6 V_340 , int V_366 )
{
switch ( V_366 ) {
case 0 :
V_183 -> V_367 |= V_368 ;
V_183 -> V_321 = V_340 ;
break;
case 1 :
V_183 -> V_367 |= V_369 ;
V_183 -> V_323 = V_340 ;
break;
#if V_324 > 2
case 2 :
V_183 -> V_367 |= V_370 ;
V_183 -> V_326 = V_340 ;
break;
case 3 :
V_183 -> V_367 |= V_371 ;
V_183 -> V_328 = V_340 ;
break;
#endif
default:
return - V_156 ;
}
V_183 -> V_367 |= V_372 ;
return 0 ;
}
static int F_178 ( struct V_149 * V_183 , T_6 V_340 ,
int type , int V_366 )
{
switch ( V_366 ) {
case 0 :
if ( type & V_197 )
V_183 -> V_367 |= V_373 ;
if ( type & V_194 )
V_183 -> V_367 |= V_374 ;
V_183 -> V_198 = V_340 ;
break;
case 1 :
if ( type & V_197 )
V_183 -> V_367 |= V_375 ;
if ( type & V_194 )
V_183 -> V_367 |= V_376 ;
V_183 -> V_199 = V_340 ;
break;
default:
return - V_156 ;
}
V_183 -> V_367 |= V_372 ;
return 0 ;
}
void F_179 ( struct V_1 * V_2 , T_2 V_377 , bool V_378 )
{
#ifdef V_16
F_48 ( V_377 & ~ ( V_379 | V_380 | V_381 ) ) ;
if ( V_378 ) {
if ( V_377 & V_382 )
V_2 -> V_4 . V_383 |= V_379 ;
if ( V_377 & V_18 )
V_2 -> V_4 . V_383 |= V_380 ;
if ( V_377 & V_384 )
V_2 -> V_4 . V_383 |= V_381 ;
} else {
if ( V_377 & V_382 )
V_2 -> V_4 . V_383 &= ~ V_379 ;
if ( V_377 & V_18 )
V_2 -> V_4 . V_383 &= ~ V_380 ;
if ( V_377 & V_384 )
V_2 -> V_4 . V_383 &= ~ V_381 ;
}
#endif
}
int F_180 ( struct V_1 * V_2 ,
struct V_385 * V_386 )
{
struct V_149 * V_183 ;
int V_387 , V_388 = 0 , V_389 = 0 ;
if ( ! ( V_386 -> V_390 & V_391 ) ) {
V_2 -> V_4 . V_164 . V_367 = 0 ;
V_2 -> V_19 = 0 ;
F_179 ( V_2 , V_18 , false ) ;
return 0 ;
}
F_179 ( V_2 , V_18 , true ) ;
V_2 -> V_19 = V_386 -> V_390 ;
V_2 -> V_4 . V_164 . V_367 = 0 ;
V_2 -> V_4 . V_183 . V_367 = V_392 ;
if ( V_2 -> V_19 & V_393 )
V_2 -> V_4 . V_164 . V_367 |= V_372 | V_394 ;
V_183 = & ( V_2 -> V_4 . V_164 ) ;
#ifdef V_16
V_183 -> V_395 = 0 ;
V_183 -> V_396 = 0 ;
#else
V_183 -> V_395 = V_397 | V_398 | V_399 |
V_400 ;
V_183 -> V_396 = V_401 | V_402 ;
#endif
if ( ! ( V_2 -> V_19 & V_403 ) )
return 0 ;
for ( V_387 = 0 ; V_387 < ( V_404 + V_405 ) ; V_387 ++ ) {
T_6 V_340 = V_386 -> V_4 . V_406 [ V_387 ] . V_340 ;
T_7 type = V_386 -> V_4 . V_406 [ V_387 ] . type ;
if ( type == V_407 )
continue;
if ( type & ! ( V_197 |
V_194 |
V_191 ) )
return - V_156 ;
if ( type & V_191 ) {
if ( F_177 ( V_183 , V_340 , V_388 ++ ) )
return - V_156 ;
} else {
if ( F_178 ( V_183 , V_340 ,
type , V_389 ++ ) )
return - V_156 ;
}
}
return 0 ;
}
void F_181 ( struct V_1 * V_2 , int V_408 )
{
V_2 -> V_408 = F_182 () ;
V_158 -> V_159 . V_1 = V_2 ;
}
void F_183 ( struct V_1 * V_2 )
{
V_158 -> V_159 . V_1 = NULL ;
V_2 -> V_408 = - 1 ;
F_101 () ;
}
void F_184 ( struct V_1 * V_2 )
{
V_2 -> V_262 -> V_4 . V_311 -> V_409 ( V_2 ) ;
}
int F_185 ( struct V_262 * V_262 )
{
return V_262 -> V_4 . V_311 -> V_410 ( V_262 ) ;
}
struct V_1 * F_186 ( struct V_262 * V_262 , unsigned int V_319 )
{
return V_262 -> V_4 . V_311 -> V_411 ( V_262 , V_319 ) ;
}
void F_187 ( struct V_1 * V_2 )
{
V_2 -> V_262 -> V_4 . V_311 -> V_412 ( V_2 ) ;
}
void F_188 ( struct V_262 * V_262 )
{
V_262 -> V_4 . V_311 -> V_413 ( V_262 ) ;
}
void F_189 ( struct V_1 * V_2 , int V_408 )
{
V_2 -> V_262 -> V_4 . V_311 -> V_414 ( V_2 , V_408 ) ;
}
void F_190 ( struct V_1 * V_2 )
{
V_2 -> V_262 -> V_4 . V_311 -> V_415 ( V_2 ) ;
}
int T_8 F_191 ( void )
{
#ifndef V_16
unsigned long V_92 [ 16 ] ;
unsigned long * V_416 = V_417 ;
unsigned long V_418 = 0 ;
unsigned long V_419 ;
int V_3 ;
V_420 = F_192 ( V_421 | V_422 ,
V_423 ) ;
if ( ! V_420 )
return - V_424 ;
V_92 [ 0 ] = F_41 ( V_425 ) ;
V_92 [ 1 ] = F_41 ( V_426 ) ;
V_92 [ 2 ] = F_41 ( V_427 ) ;
V_92 [ 3 ] = F_41 ( V_428 ) ;
V_92 [ 4 ] = F_41 ( V_429 ) ;
V_92 [ 5 ] = F_41 ( V_430 ) ;
V_92 [ 6 ] = F_41 ( V_431 ) ;
V_92 [ 7 ] = F_41 ( V_432 ) ;
V_92 [ 8 ] = F_41 ( V_433 ) ;
V_92 [ 9 ] = F_41 ( V_434 ) ;
V_92 [ 10 ] = F_41 ( V_435 ) ;
V_92 [ 11 ] = F_41 ( V_436 ) ;
V_92 [ 12 ] = F_41 ( V_437 ) ;
V_92 [ 13 ] = F_41 ( V_438 ) ;
V_92 [ 14 ] = F_41 ( V_439 ) ;
V_92 [ 15 ] = F_41 ( V_440 ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( V_92 [ V_3 ] > V_418 )
V_418 = V_3 ;
V_419 = V_416 [ V_3 + 1 ] - V_416 [ V_3 ] ;
memcpy ( ( void * ) V_420 + V_92 [ V_3 ] ,
( void * ) V_416 [ V_3 ] , V_419 ) ;
}
V_419 = V_416 [ V_418 + 1 ] - V_416 [ V_418 ] ;
F_193 ( V_420 , V_420 +
V_92 [ V_418 ] + V_419 ) ;
#endif
return 0 ;
}
void T_9 F_194 ( void )
{
F_195 ( V_420 , V_423 ) ;
F_196 () ;
}
