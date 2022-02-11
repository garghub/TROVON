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
void F_20 ( struct V_1 * V_2 ,
T_2 V_24 , T_2 V_25 )
{
V_2 -> V_4 . V_26 = V_24 ;
V_2 -> V_4 . V_27 = V_25 ;
F_17 ( V_2 , V_28 ) ;
}
void F_21 ( struct V_1 * V_2 ,
T_2 V_24 , T_2 V_25 )
{
V_2 -> V_4 . V_26 = V_24 ;
V_2 -> V_4 . V_27 = V_25 ;
F_17 ( V_2 , V_29 ) ;
}
void F_22 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_30 ) ;
}
void F_23 ( struct V_1 * V_2 , T_2 V_25 )
{
V_2 -> V_4 . V_27 = V_25 ;
F_17 ( V_2 , V_31 ) ;
}
static void F_24 ( struct V_1 * V_2 , T_2 V_24 ,
T_2 V_25 )
{
V_2 -> V_4 . V_26 = V_24 ;
V_2 -> V_4 . V_27 = V_25 ;
F_17 ( V_2 , V_32 ) ;
}
void F_25 ( struct V_1 * V_2 , T_2 V_25 )
{
V_2 -> V_4 . V_27 = V_25 ;
F_17 ( V_2 , V_33 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_34 ) ;
}
int F_27 ( struct V_1 * V_2 )
{
return F_28 ( V_34 , & V_2 -> V_4 . V_12 ) ;
}
void F_29 ( struct V_1 * V_2 )
{
F_30 ( V_34 , & V_2 -> V_4 . V_12 ) ;
}
void F_31 ( struct V_1 * V_2 ,
struct V_35 * V_36 )
{
unsigned int V_37 = V_38 ;
if ( V_36 -> V_36 == V_39 )
V_37 = V_40 ;
F_17 ( V_2 , V_37 ) ;
}
void F_32 ( struct V_1 * V_2 )
{
F_30 ( V_38 , & V_2 -> V_4 . V_12 ) ;
F_30 ( V_40 , & V_2 -> V_4 . V_12 ) ;
}
static void F_33 ( struct V_1 * V_2 )
{
F_17 ( V_2 , V_41 ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
F_30 ( V_41 , & V_2 -> V_4 . V_12 ) ;
}
static void F_35 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
F_36 ( V_2 , V_10 ) ;
F_37 ( V_2 , V_11 ) ;
}
static void F_38 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_42 = V_10 ;
V_2 -> V_4 . V_43 = V_11 ;
}
static void F_39 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
if ( F_40 ( V_44 ) ) {
V_2 -> V_4 . V_45 = V_10 ;
V_2 -> V_4 . V_46 = V_11 ;
} else {
F_38 ( V_2 , V_10 , V_11 ) ;
}
}
static void F_41 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_47 = V_10 ;
V_2 -> V_4 . V_48 = V_11 ;
}
static int F_42 ( struct V_1 * V_2 ,
unsigned int V_23 )
{
int V_49 = 0 ;
T_2 V_50 = 0 ;
bool V_51 = false , V_52 = false , V_53 = false ;
T_2 V_54 = V_2 -> V_4 . V_6 -> V_55 ;
T_2 V_56 = F_3 ( V_2 , 1 ) ;
bool V_57 ;
bool V_58 = false ;
enum V_59 V_59 ;
T_2 V_20 = V_2 -> V_4 . V_6 -> V_7 ;
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_60 ) ) {
V_54 &= 0xffffffff ;
V_56 &= 0xffffffff ;
}
V_57 = ( V_54 == V_56 ) ;
V_57 = V_57 && ! ( V_2 -> V_4 . V_6 -> V_7 & V_61 ) ;
if ( V_23 == V_40 ) {
V_23 = V_38 ;
V_58 = true ;
}
if ( ( V_23 == V_38 ) && V_2 -> V_4 . V_62 )
V_53 = true ;
switch ( V_23 ) {
case V_28 :
case V_29 :
case V_32 :
V_52 = true ;
case V_31 :
case V_33 :
V_51 = true ;
case V_30 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
V_49 = 1 ;
V_50 = V_69 | V_70 | V_18 ;
V_59 = V_71 ;
break;
case V_41 :
case V_72 :
case V_73 :
V_49 = V_2 -> V_4 . V_6 -> V_7 & V_69 ;
V_49 = V_49 && ! V_57 ;
V_50 = V_70 ;
V_59 = V_74 ;
break;
case V_75 :
V_49 = V_2 -> V_4 . V_6 -> V_7 & V_70 ;
V_49 = V_49 && ! V_57 ;
V_59 = V_76 ;
break;
case V_34 :
case V_77 :
V_58 = true ;
case V_38 :
case V_78 :
V_49 = V_2 -> V_4 . V_6 -> V_7 & V_79 ;
V_49 = V_49 && ! V_57 ;
V_50 = V_69 | V_70 | V_18 ;
V_59 = V_71 ;
break;
case V_80 :
V_49 = V_2 -> V_4 . V_6 -> V_7 & V_18 ;
V_49 = V_49 && ! V_57 ;
V_50 = V_70 ;
V_59 = V_74 ;
break;
}
if ( V_49 ) {
switch ( V_59 ) {
case V_71 :
F_35 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_74 :
F_38 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_81 :
F_39 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_76 :
F_41 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
}
V_2 -> V_4 . V_5 = V_2 -> V_4 . V_82 | V_2 -> V_4 . V_83 [ V_23 ] ;
if ( V_51 == true )
F_43 ( V_2 , V_2 -> V_4 . V_27 ) ;
if ( V_52 == true )
F_44 ( V_2 , V_2 -> V_4 . V_26 ) ;
if ( V_53 == true ) {
if ( V_2 -> V_4 . V_62 & V_84 )
F_45 ( V_85 , V_2 ) ;
else if ( V_2 -> V_4 . V_62 & V_86 ) {
F_46 ( V_2 -> V_4 . V_87 != V_88 ) ;
F_47 ( V_2 ) ;
}
}
V_20 &= V_50 ;
#if F_13 ( V_89 )
if ( V_2 -> V_4 . V_90 & V_91 )
V_20 |= V_92 ;
#endif
F_15 ( V_2 , V_20 ) ;
if ( ! V_58 )
F_30 ( V_23 , & V_2 -> V_4 . V_12 ) ;
}
#ifdef V_16
if ( V_2 -> V_4 . V_12 & V_93 )
F_48 ( V_2 , V_71 ) ;
if ( V_2 -> V_4 . V_12 & V_94 )
F_48 ( V_2 , V_74 ) ;
if ( V_2 -> V_4 . V_12 & V_75 )
F_48 ( V_2 , V_76 ) ;
#endif
return V_49 ;
}
static unsigned long F_49 ( struct V_1 * V_2 )
{
T_3 V_95 , V_96 , V_97 = 0 ;
T_3 V_98 = 0 ;
T_1 V_99 = F_50 ( V_2 -> V_4 . V_100 ) ;
V_96 = 1ULL << ( 63 - V_99 ) ;
V_95 = F_51 () ;
if ( V_95 & V_96 )
V_97 = V_96 ;
V_97 += V_96 - ( V_95 & ( V_96 - 1 ) ) ;
V_98 = V_97 ;
if ( F_52 ( V_98 , V_101 ) )
V_98 ++ ;
return F_53 (unsigned long long, nr_jiffies, NEXT_TIMER_MAX_DELTA) ;
}
static void F_54 ( struct V_1 * V_2 )
{
unsigned long V_98 ;
unsigned long V_102 ;
if ( ( V_2 -> V_4 . V_103 & ( V_104 | V_105 ) ) != ( V_104 | V_105 ) )
F_30 ( V_106 , & V_2 -> V_107 ) ;
F_55 ( & V_2 -> V_4 . V_108 , V_102 ) ;
V_98 = F_49 ( V_2 ) ;
if ( V_98 < V_109 )
F_56 ( & V_2 -> V_4 . V_110 , V_111 + V_98 ) ;
else
F_57 ( & V_2 -> V_4 . V_110 ) ;
F_58 ( & V_2 -> V_4 . V_108 , V_102 ) ;
}
void F_59 ( unsigned long V_112 )
{
struct V_1 * V_2 = (struct V_1 * ) V_112 ;
T_1 V_103 , V_113 ;
int V_114 ;
do {
V_113 = V_103 = V_2 -> V_4 . V_103 ;
V_114 = 0 ;
if ( V_103 & V_104 ) {
if ( V_103 & V_105 )
V_114 = 1 ;
else
V_113 = V_103 | V_105 ;
} else {
V_113 = V_103 | V_104 ;
}
} while ( F_60 ( & V_2 -> V_4 . V_103 , V_103 , V_113 ) != V_103 );
if ( V_113 & V_105 ) {
F_61 () ;
F_45 ( V_115 , V_2 ) ;
F_62 ( V_2 ) ;
}
if ( V_114 && ( V_2 -> V_4 . V_100 & V_116 ) &&
V_2 -> V_4 . V_117 ) {
F_61 () ;
F_45 ( V_106 , V_2 ) ;
F_62 ( V_2 ) ;
}
if ( ! V_114 )
F_54 ( V_2 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 . V_100 & V_118 ) && ( V_2 -> V_4 . V_103 & V_119 ) )
F_26 ( V_2 ) ;
else
F_29 ( V_2 ) ;
if ( ( V_2 -> V_4 . V_100 & V_120 ) && ( V_2 -> V_4 . V_103 & V_105 ) )
F_33 ( V_2 ) ;
else
F_34 ( V_2 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
unsigned long * V_121 = & V_2 -> V_4 . V_12 ;
unsigned int V_23 ;
V_23 = F_65 ( * V_121 ) ;
while ( V_23 < V_122 ) {
if ( F_42 ( V_2 , V_23 ) )
break;
V_23 = F_66 ( V_121 ,
V_123 * sizeof( * V_121 ) ,
V_23 + 1 ) ;
}
V_2 -> V_4 . V_6 -> V_124 = ! ! * V_121 ;
}
int F_67 ( struct V_1 * V_2 )
{
int V_125 = 0 ;
F_68 ( ! F_69 () ) ;
F_64 ( V_2 ) ;
if ( V_2 -> V_107 ) {
return 1 ;
}
if ( V_2 -> V_4 . V_6 -> V_7 & V_126 ) {
F_70 () ;
F_71 ( V_2 ) ;
F_30 ( V_127 , & V_2 -> V_107 ) ;
F_72 () ;
F_73 ( V_2 , V_128 ) ;
V_125 = 1 ;
} ;
return V_125 ;
}
int F_74 ( struct V_1 * V_2 )
{
int V_125 = 1 ;
if ( F_75 ( V_115 , V_2 ) )
F_63 ( V_2 ) ;
#if F_13 ( V_129 ) || F_13 ( V_130 )
if ( F_75 ( V_131 , V_2 ) )
F_76 ( V_2 ) ;
#endif
if ( F_75 ( V_106 , V_2 ) ) {
V_2 -> V_132 -> V_133 = V_134 ;
V_125 = 0 ;
}
if ( F_75 ( V_85 , V_2 ) ) {
V_2 -> V_132 -> V_135 . V_135 = 0 ;
V_2 -> V_4 . V_136 = true ;
V_2 -> V_132 -> V_133 = V_137 ;
V_125 = 0 ;
}
return V_125 ;
}
int F_77 ( struct V_138 * V_138 , struct V_1 * V_2 )
{
int V_139 , V_140 ;
struct V_141 V_142 ;
if ( ! V_2 -> V_4 . V_143 ) {
V_138 -> V_133 = V_144 ;
return - V_145 ;
}
V_140 = F_78 ( V_2 ) ;
if ( V_140 <= 0 ) {
V_139 = V_140 ;
goto V_146;
}
#ifdef V_15
F_79 () ;
V_2 -> V_147 = 1 ;
F_80 ( V_2 ) ;
#endif
V_142 = V_2 -> V_4 . V_148 ;
F_81 ( & V_142 ) ;
V_142 = V_149 -> V_150 . V_142 ;
V_149 -> V_150 . V_142 = V_2 -> V_4 . V_148 ;
V_2 -> V_4 . V_151 = V_149 -> V_152 -> V_153 ;
F_82 () ;
V_139 = F_83 ( V_138 , V_2 ) ;
F_81 ( & V_142 ) ;
V_149 -> V_150 . V_142 = V_142 ;
#ifdef V_15
F_84 ( V_2 ) ;
V_2 -> V_147 = 0 ;
#endif
V_146:
V_2 -> V_154 = V_155 ;
return V_139 ;
}
static int F_85 ( struct V_138 * V_132 , struct V_1 * V_2 )
{
enum V_156 V_157 ;
V_157 = F_86 ( V_132 , V_2 ) ;
switch ( V_157 ) {
case V_158 :
F_87 ( V_2 , V_159 ) ;
return V_160 ;
case V_161 :
return V_162 ;
case V_163 :
F_2 ( V_164 L_6 ,
V_165 , V_2 -> V_4 . V_5 , V_2 -> V_4 . V_166 ) ;
V_132 -> V_167 . V_168 = ~ 0ULL << 32 ;
V_132 -> V_167 . V_168 |= V_2 -> V_4 . V_166 ;
F_25 ( V_2 , V_169 ) ;
return V_170 ;
case V_171 :
return V_170 ;
default:
F_88 () ;
}
}
static int F_89 ( struct V_138 * V_132 , struct V_1 * V_2 )
{
struct V_141 * V_172 = & ( V_2 -> V_4 . V_148 ) ;
T_1 V_173 = V_2 -> V_4 . V_173 ;
V_132 -> V_142 . V_4 . V_174 = 0 ;
V_132 -> V_142 . V_4 . V_175 = V_2 -> V_4 . V_5 ;
if ( V_173 & ( V_176 | V_177 | V_178 | V_179 ) ) {
V_132 -> V_142 . V_4 . V_174 |= V_180 ;
} else {
if ( V_173 & ( V_181 | V_182 ) )
V_132 -> V_142 . V_4 . V_174 |= V_183 ;
else if ( V_173 & ( V_184 | V_185 ) )
V_132 -> V_142 . V_4 . V_174 |= V_186 ;
if ( V_173 & ( V_184 | V_181 ) )
V_132 -> V_142 . V_4 . V_175 = V_172 -> V_187 ;
else if ( V_173 & ( V_185 | V_182 ) )
V_132 -> V_142 . V_4 . V_175 = V_172 -> V_188 ;
}
return V_170 ;
}
static void F_90 ( struct V_189 * V_190 )
{
T_2 V_191 , V_192 , V_7 , V_8 ;
asm("mr %0, 1" : "=r"(r1));
asm("mflr %0" : "=r"(lr));
asm("mfmsr %0" : "=r"(msr));
asm("bl 1f; 1: mflr %0" : "=r"(ip));
memset ( V_190 , 0 , sizeof( * V_190 ) ) ;
V_190 -> V_193 [ 1 ] = V_191 ;
V_190 -> V_194 = V_192 ;
V_190 -> V_7 = V_7 ;
V_190 -> V_195 = V_8 ;
}
static void F_91 ( struct V_1 * V_2 ,
unsigned int V_196 )
{
struct V_189 V_190 ;
switch ( V_196 ) {
case V_197 :
F_90 ( & V_190 ) ;
F_92 ( & V_190 ) ;
break;
case V_198 :
F_90 ( & V_190 ) ;
F_93 ( & V_190 ) ;
break;
#if F_13 ( V_199 )
case V_200 :
F_90 ( & V_190 ) ;
F_94 ( & V_190 ) ;
break;
#endif
case V_201 :
break;
case V_202 :
F_90 ( & V_190 ) ;
F_95 ( & V_190 ) ;
break;
case V_203 :
F_90 ( & V_190 ) ;
#ifdef F_96
F_97 ( & V_190 ) ;
#else
F_98 ( & V_190 ) ;
#endif
break;
case V_204 :
F_98 ( & V_190 ) ;
break;
case V_205 :
V_2 -> V_4 . V_173 = F_99 ( V_206 ) ;
F_100 () ;
break;
}
}
static int F_101 ( struct V_138 * V_132 , struct V_1 * V_2 ,
enum V_156 V_207 , T_1 V_166 )
{
switch ( V_207 ) {
case V_161 :
return V_162 ;
case V_163 :
F_102 ( L_7 ,
V_165 , V_2 -> V_4 . V_5 ) ;
V_132 -> V_167 . V_168 = ~ 0ULL << 32 ;
V_132 -> V_167 . V_168 |= V_166 ;
F_25 ( V_2 , V_169 ) ;
return V_170 ;
default:
F_88 () ;
}
}
int F_103 ( struct V_138 * V_132 , struct V_1 * V_2 ,
unsigned int V_196 )
{
int V_125 = V_170 ;
int V_140 ;
int V_208 ;
T_1 V_166 = V_209 ;
enum V_156 V_207 = V_158 ;
F_104 ( V_2 ) ;
F_91 ( V_2 , V_196 ) ;
switch ( V_196 ) {
case V_210 :
case V_211 :
case V_212 :
V_207 = F_105 ( V_2 , false , & V_166 ) ;
break;
default:
break;
}
F_70 () ;
F_106 ( V_196 , V_2 ) ;
F_107 () ;
V_132 -> V_133 = V_213 ;
V_132 -> V_214 = 1 ;
if ( V_207 != V_158 ) {
V_125 = F_101 ( V_132 , V_2 , V_207 , V_166 ) ;
goto V_146;
}
switch ( V_196 ) {
case V_201 :
F_2 ( L_8 , F_99 ( V_215 ) ) ;
F_1 ( V_2 ) ;
V_132 -> V_167 . V_168 = ~ 1ULL << 32 ;
V_132 -> V_167 . V_168 |= F_99 ( V_215 ) ;
V_125 = V_170 ;
break;
case V_197 :
F_108 ( V_2 , V_216 ) ;
V_125 = V_162 ;
break;
case V_198 :
F_108 ( V_2 , V_217 ) ;
V_125 = V_162 ;
break;
case V_203 :
V_125 = V_162 ;
break;
case V_200 :
F_108 ( V_2 , V_218 ) ;
V_125 = V_162 ;
break;
case V_219 :
F_108 ( V_2 , V_220 ) ;
V_125 = V_162 ;
break;
case V_221 :
F_108 ( V_2 , V_220 ) ;
V_125 = V_162 ;
break;
case V_202 :
V_125 = V_162 ;
break;
case V_212 :
V_125 = F_85 ( V_132 , V_2 ) ;
break;
case V_222 :
if ( V_2 -> V_4 . V_6 -> V_7 & ( V_61 | V_22 ) ) {
F_25 ( V_2 , V_2 -> V_4 . V_223 ) ;
V_125 = V_162 ;
F_108 ( V_2 , V_224 ) ;
break;
}
V_125 = F_85 ( V_132 , V_2 ) ;
break;
case V_225 :
F_17 ( V_2 , V_64 ) ;
F_108 ( V_2 , V_226 ) ;
V_125 = V_162 ;
break;
#ifdef F_109
case V_227 : {
if ( V_2 -> V_4 . V_6 -> V_7 & V_14 )
F_9 ( V_2 ) ;
else
F_17 ( V_2 ,
V_65 ) ;
V_125 = V_162 ;
break;
}
case V_228 :
F_17 ( V_2 , V_66 ) ;
V_125 = V_162 ;
break;
case V_229 :
F_17 ( V_2 , V_67 ) ;
V_125 = V_162 ;
break;
#else
case V_227 :
F_25 ( V_2 , V_230 | V_231 ) ;
V_125 = V_162 ;
break;
case V_228 :
case V_229 :
F_2 ( V_164 L_9 ,
V_165 , V_196 , V_2 -> V_4 . V_5 ) ;
V_132 -> V_167 . V_168 = V_196 ;
V_125 = V_170 ;
break;
#endif
case V_210 :
F_21 ( V_2 , V_2 -> V_4 . V_232 ,
V_2 -> V_4 . V_223 ) ;
F_108 ( V_2 , V_233 ) ;
V_125 = V_162 ;
break;
case V_234 :
F_23 ( V_2 , V_2 -> V_4 . V_223 ) ;
F_108 ( V_2 , V_235 ) ;
V_125 = V_162 ;
break;
case V_236 :
F_24 ( V_2 , V_2 -> V_4 . V_232 ,
V_2 -> V_4 . V_223 ) ;
V_125 = V_162 ;
break;
#ifdef V_16
case V_237 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_61 ) ) {
F_110 ( V_2 , 3 , F_111 ( V_2 ) ) ;
} else {
F_25 ( V_2 , V_238 ) ;
}
V_125 = V_162 ;
break;
#else
case V_239 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_61 ) &&
( ( ( T_1 ) F_3 ( V_2 , 0 ) ) == V_240 ) ) {
F_110 ( V_2 , 3 , F_111 ( V_2 ) ) ;
V_125 = V_162 ;
} else {
F_17 ( V_2 , V_63 ) ;
}
F_108 ( V_2 , V_241 ) ;
V_125 = V_162 ;
break;
#endif
case V_211 : {
unsigned long V_242 = V_2 -> V_4 . V_232 ;
int V_243 ;
T_4 V_244 ;
T_5 V_245 ;
#ifdef V_129
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_61 ) &&
( V_242 & V_246 ) == V_2 -> V_4 . V_247 ) {
F_112 ( V_2 ) ;
F_108 ( V_2 , V_248 ) ;
V_125 = V_162 ;
break;
}
#endif
V_243 = F_113 ( V_2 , V_242 ) ;
if ( V_243 < 0 ) {
F_20 ( V_2 ,
V_2 -> V_4 . V_232 ,
V_2 -> V_4 . V_223 ) ;
F_114 ( V_2 ) ;
F_108 ( V_2 , V_249 ) ;
V_125 = V_162 ;
break;
}
V_208 = F_115 ( & V_2 -> V_250 -> V_251 ) ;
V_244 = F_116 ( V_2 , V_243 , V_242 ) ;
V_245 = V_244 >> V_252 ;
if ( F_117 ( V_2 -> V_250 , V_245 ) ) {
F_118 ( V_2 , V_242 , V_244 , V_243 ) ;
F_108 ( V_2 , V_248 ) ;
V_125 = V_162 ;
} else {
V_2 -> V_4 . V_253 = V_244 ;
V_2 -> V_4 . V_254 = V_242 ;
V_125 = F_119 ( V_132 , V_2 ) ;
F_108 ( V_2 , V_255 ) ;
}
F_120 ( & V_2 -> V_250 -> V_251 , V_208 ) ;
break;
}
case V_256 : {
unsigned long V_242 = V_2 -> V_4 . V_5 ;
T_4 V_244 ;
T_5 V_245 ;
int V_243 ;
V_125 = V_162 ;
V_243 = F_121 ( V_2 , V_242 ) ;
if ( V_243 < 0 ) {
F_17 ( V_2 , V_30 ) ;
F_122 ( V_2 ) ;
F_108 ( V_2 , V_257 ) ;
break;
}
F_108 ( V_2 , V_258 ) ;
V_208 = F_115 ( & V_2 -> V_250 -> V_251 ) ;
V_244 = F_116 ( V_2 , V_243 , V_242 ) ;
V_245 = V_244 >> V_252 ;
if ( F_117 ( V_2 -> V_250 , V_245 ) ) {
F_118 ( V_2 , V_242 , V_244 , V_243 ) ;
} else {
F_17 ( V_2 , V_75 ) ;
}
F_120 ( & V_2 -> V_250 -> V_251 , V_208 ) ;
break;
}
case V_205 : {
V_125 = F_89 ( V_132 , V_2 ) ;
if ( V_125 == V_170 )
V_132 -> V_133 = V_259 ;
F_108 ( V_2 , V_260 ) ;
break;
}
default:
F_2 ( V_261 L_10 , V_196 ) ;
F_88 () ;
}
V_146:
if ( ! ( V_125 & V_170 ) ) {
V_140 = F_78 ( V_2 ) ;
if ( V_140 <= 0 )
V_125 = ( V_140 << 2 ) | V_170 | ( V_125 & V_262 ) ;
else {
F_82 () ;
}
}
return V_125 ;
}
static void F_123 ( struct V_1 * V_2 , T_1 V_113 )
{
T_1 V_263 = V_2 -> V_4 . V_103 ;
V_2 -> V_4 . V_103 = V_113 ;
if ( ( V_263 ^ V_2 -> V_4 . V_103 ) & ( V_104 | V_105 ) )
F_54 ( V_2 ) ;
F_63 ( V_2 ) ;
}
int F_124 ( struct V_1 * V_2 )
{
int V_3 ;
int V_125 ;
V_2 -> V_4 . V_5 = 0 ;
V_2 -> V_4 . V_6 -> V_264 = V_2 -> V_265 ;
F_110 ( V_2 , 1 , ( 16 << 20 ) - 8 ) ;
F_15 ( V_2 , 0 ) ;
#ifndef V_16
V_2 -> V_4 . V_13 = V_266 | V_267 | V_268 ;
V_2 -> V_4 . V_269 = 1 ;
V_2 -> V_4 . V_6 -> V_7 = 0 ;
#endif
V_2 -> V_4 . V_82 = 0x55550000 ;
for ( V_3 = 0 ; V_3 < V_122 ; V_3 ++ )
V_2 -> V_4 . V_83 [ V_3 ] = 0x7700 | V_3 * 4 ;
F_125 ( V_2 ) ;
V_125 = F_126 ( V_2 ) ;
F_127 ( V_2 ) ;
return V_125 ;
}
int F_128 ( struct V_1 * V_2 )
{
F_129 ( & V_2 -> V_4 . V_108 ) ;
F_130 ( & V_2 -> V_4 . V_110 , F_59 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_131 ( struct V_1 * V_2 )
{
F_132 ( & V_2 -> V_4 . V_110 ) ;
}
int F_133 ( struct V_1 * V_2 , struct V_270 * V_190 )
{
int V_3 ;
V_190 -> V_5 = V_2 -> V_4 . V_5 ;
V_190 -> V_271 = F_134 ( V_2 ) ;
V_190 -> V_9 = V_2 -> V_4 . V_9 ;
V_190 -> V_8 = V_2 -> V_4 . V_8 ;
V_190 -> V_272 = F_135 ( V_2 ) ;
V_190 -> V_7 = V_2 -> V_4 . V_6 -> V_7 ;
V_190 -> V_10 = F_136 ( V_2 ) ;
V_190 -> V_11 = F_137 ( V_2 ) ;
V_190 -> V_273 = V_2 -> V_4 . V_273 ;
V_190 -> V_274 = F_138 ( V_2 ) ;
V_190 -> V_275 = F_139 ( V_2 ) ;
V_190 -> V_276 = F_140 ( V_2 ) ;
V_190 -> V_277 = F_141 ( V_2 ) ;
V_190 -> V_278 = F_142 ( V_2 ) ;
V_190 -> V_279 = F_143 ( V_2 ) ;
V_190 -> V_280 = F_144 ( V_2 ) ;
V_190 -> V_281 = F_145 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < F_146 ( V_190 -> V_193 ) ; V_3 ++ )
V_190 -> V_193 [ V_3 ] = F_3 ( V_2 , V_3 ) ;
return 0 ;
}
int F_147 ( struct V_1 * V_2 , struct V_270 * V_190 )
{
int V_3 ;
V_2 -> V_4 . V_5 = V_190 -> V_5 ;
F_148 ( V_2 , V_190 -> V_271 ) ;
V_2 -> V_4 . V_9 = V_190 -> V_9 ;
V_2 -> V_4 . V_8 = V_190 -> V_8 ;
F_149 ( V_2 , V_190 -> V_272 ) ;
F_15 ( V_2 , V_190 -> V_7 ) ;
F_36 ( V_2 , V_190 -> V_10 ) ;
F_37 ( V_2 , V_190 -> V_11 ) ;
F_150 ( V_2 , V_190 -> V_273 ) ;
F_151 ( V_2 , V_190 -> V_274 ) ;
F_152 ( V_2 , V_190 -> V_275 ) ;
F_153 ( V_2 , V_190 -> V_276 ) ;
F_154 ( V_2 , V_190 -> V_277 ) ;
F_155 ( V_2 , V_190 -> V_278 ) ;
F_156 ( V_2 , V_190 -> V_279 ) ;
F_157 ( V_2 , V_190 -> V_280 ) ;
F_158 ( V_2 , V_190 -> V_281 ) ;
for ( V_3 = 0 ; V_3 < F_146 ( V_190 -> V_193 ) ; V_3 ++ )
F_110 ( V_2 , V_3 , V_190 -> V_193 [ V_3 ] ) ;
return 0 ;
}
static void F_159 ( struct V_1 * V_2 ,
struct V_282 * V_283 )
{
T_3 V_95 = F_51 () ;
V_283 -> V_284 . V_285 . V_286 |= V_287 ;
V_283 -> V_284 . V_285 . V_42 = V_2 -> V_4 . V_42 ;
V_283 -> V_284 . V_285 . V_43 = V_2 -> V_4 . V_43 ;
V_283 -> V_284 . V_285 . V_288 = V_2 -> V_4 . V_288 ;
V_283 -> V_284 . V_285 . V_289 = F_160 ( V_2 ) ;
V_283 -> V_284 . V_285 . V_290 = F_161 ( V_2 ) ;
V_283 -> V_284 . V_285 . V_103 = V_2 -> V_4 . V_103 ;
V_283 -> V_284 . V_285 . V_100 = V_2 -> V_4 . V_100 ;
V_283 -> V_284 . V_285 . V_291 = F_162 ( V_2 , V_95 ) ;
V_283 -> V_284 . V_285 . V_95 = V_95 ;
V_283 -> V_284 . V_285 . V_292 = V_2 -> V_4 . V_292 ;
}
static int F_163 ( struct V_1 * V_2 ,
struct V_282 * V_283 )
{
if ( ! ( V_283 -> V_284 . V_285 . V_286 & V_287 ) )
return 0 ;
V_2 -> V_4 . V_42 = V_283 -> V_284 . V_285 . V_42 ;
V_2 -> V_4 . V_43 = V_283 -> V_284 . V_285 . V_43 ;
V_2 -> V_4 . V_288 = V_283 -> V_284 . V_285 . V_288 ;
F_43 ( V_2 , V_283 -> V_284 . V_285 . V_289 ) ;
F_44 ( V_2 , V_283 -> V_284 . V_285 . V_290 ) ;
V_2 -> V_4 . V_292 = V_283 -> V_284 . V_285 . V_292 ;
F_164 ( V_2 , V_283 -> V_284 . V_285 . V_100 ) ;
if ( V_283 -> V_284 . V_285 . V_293 & V_294 ) {
V_2 -> V_4 . V_291 = V_283 -> V_284 . V_285 . V_291 ;
F_165 ( V_2 ) ;
}
if ( V_283 -> V_284 . V_285 . V_293 & V_295 )
F_123 ( V_2 , V_283 -> V_284 . V_285 . V_103 ) ;
return 0 ;
}
static void F_166 ( struct V_1 * V_2 ,
struct V_282 * V_283 )
{
V_283 -> V_284 . V_285 . V_286 |= V_296 ;
V_283 -> V_284 . V_285 . V_264 = V_2 -> V_265 ;
V_283 -> V_284 . V_285 . V_47 = V_2 -> V_4 . V_47 ;
V_283 -> V_284 . V_285 . V_48 = V_2 -> V_4 . V_48 ;
V_283 -> V_284 . V_285 . V_297 = V_2 -> V_4 . V_297 ;
V_283 -> V_284 . V_285 . V_82 = V_2 -> V_4 . V_82 ;
}
static int F_167 ( struct V_1 * V_2 ,
struct V_282 * V_283 )
{
if ( ! ( V_283 -> V_284 . V_285 . V_286 & V_296 ) )
return 0 ;
if ( V_283 -> V_284 . V_285 . V_264 != V_2 -> V_265 )
return - V_145 ;
V_2 -> V_4 . V_47 = V_283 -> V_284 . V_285 . V_47 ;
V_2 -> V_4 . V_48 = V_283 -> V_284 . V_285 . V_48 ;
V_2 -> V_4 . V_297 = V_283 -> V_284 . V_285 . V_297 ;
V_2 -> V_4 . V_82 = V_283 -> V_284 . V_285 . V_82 ;
return 0 ;
}
int F_168 ( struct V_1 * V_2 , struct V_282 * V_283 )
{
V_283 -> V_284 . V_285 . V_286 |= V_298 ;
V_283 -> V_284 . V_285 . V_299 [ 0 ] = V_2 -> V_4 . V_83 [ V_72 ] ;
V_283 -> V_284 . V_285 . V_299 [ 1 ] = V_2 -> V_4 . V_83 [ V_75 ] ;
V_283 -> V_284 . V_285 . V_299 [ 2 ] = V_2 -> V_4 . V_83 [ V_29 ] ;
V_283 -> V_284 . V_285 . V_299 [ 3 ] = V_2 -> V_4 . V_83 [ V_31 ] ;
V_283 -> V_284 . V_285 . V_299 [ 4 ] = V_2 -> V_4 . V_83 [ V_38 ] ;
V_283 -> V_284 . V_285 . V_299 [ 5 ] = V_2 -> V_4 . V_83 [ V_32 ] ;
V_283 -> V_284 . V_285 . V_299 [ 6 ] = V_2 -> V_4 . V_83 [ V_33 ] ;
V_283 -> V_284 . V_285 . V_299 [ 7 ] = V_2 -> V_4 . V_83 [ V_64 ] ;
V_283 -> V_284 . V_285 . V_299 [ 8 ] = V_2 -> V_4 . V_83 [ V_63 ] ;
V_283 -> V_284 . V_285 . V_299 [ 9 ] = V_2 -> V_4 . V_83 [ V_68 ] ;
V_283 -> V_284 . V_285 . V_299 [ 10 ] = V_2 -> V_4 . V_83 [ V_34 ] ;
V_283 -> V_284 . V_285 . V_299 [ 11 ] = V_2 -> V_4 . V_83 [ V_77 ] ;
V_283 -> V_284 . V_285 . V_299 [ 12 ] = V_2 -> V_4 . V_83 [ V_41 ] ;
V_283 -> V_284 . V_285 . V_299 [ 13 ] = V_2 -> V_4 . V_83 [ V_28 ] ;
V_283 -> V_284 . V_285 . V_299 [ 14 ] = V_2 -> V_4 . V_83 [ V_30 ] ;
V_283 -> V_284 . V_285 . V_299 [ 15 ] = V_2 -> V_4 . V_83 [ V_80 ] ;
return 0 ;
}
int F_169 ( struct V_1 * V_2 , struct V_282 * V_283 )
{
if ( ! ( V_283 -> V_284 . V_285 . V_286 & V_298 ) )
return 0 ;
V_2 -> V_4 . V_83 [ V_72 ] = V_283 -> V_284 . V_285 . V_299 [ 0 ] ;
V_2 -> V_4 . V_83 [ V_75 ] = V_283 -> V_284 . V_285 . V_299 [ 1 ] ;
V_2 -> V_4 . V_83 [ V_29 ] = V_283 -> V_284 . V_285 . V_299 [ 2 ] ;
V_2 -> V_4 . V_83 [ V_31 ] = V_283 -> V_284 . V_285 . V_299 [ 3 ] ;
V_2 -> V_4 . V_83 [ V_38 ] = V_283 -> V_284 . V_285 . V_299 [ 4 ] ;
V_2 -> V_4 . V_83 [ V_32 ] = V_283 -> V_284 . V_285 . V_299 [ 5 ] ;
V_2 -> V_4 . V_83 [ V_33 ] = V_283 -> V_284 . V_285 . V_299 [ 6 ] ;
V_2 -> V_4 . V_83 [ V_64 ] = V_283 -> V_284 . V_285 . V_299 [ 7 ] ;
V_2 -> V_4 . V_83 [ V_63 ] = V_283 -> V_284 . V_285 . V_299 [ 8 ] ;
V_2 -> V_4 . V_83 [ V_68 ] = V_283 -> V_284 . V_285 . V_299 [ 9 ] ;
V_2 -> V_4 . V_83 [ V_34 ] = V_283 -> V_284 . V_285 . V_299 [ 10 ] ;
V_2 -> V_4 . V_83 [ V_77 ] = V_283 -> V_284 . V_285 . V_299 [ 11 ] ;
V_2 -> V_4 . V_83 [ V_41 ] = V_283 -> V_284 . V_285 . V_299 [ 12 ] ;
V_2 -> V_4 . V_83 [ V_28 ] = V_283 -> V_284 . V_285 . V_299 [ 13 ] ;
V_2 -> V_4 . V_83 [ V_30 ] = V_283 -> V_284 . V_285 . V_299 [ 14 ] ;
V_2 -> V_4 . V_83 [ V_80 ] = V_283 -> V_284 . V_285 . V_299 [ 15 ] ;
return 0 ;
}
int F_170 ( struct V_1 * V_2 ,
struct V_282 * V_283 )
{
V_283 -> V_300 = V_2 -> V_4 . V_300 ;
F_159 ( V_2 , V_283 ) ;
F_166 ( V_2 , V_283 ) ;
return V_2 -> V_250 -> V_4 . V_301 -> V_302 ( V_2 , V_283 ) ;
}
int F_171 ( struct V_1 * V_2 ,
struct V_282 * V_283 )
{
int V_139 ;
if ( V_2 -> V_4 . V_300 != V_283 -> V_300 )
return - V_145 ;
V_139 = F_163 ( V_2 , V_283 ) ;
if ( V_139 < 0 )
return V_139 ;
V_139 = F_167 ( V_2 , V_283 ) ;
if ( V_139 < 0 )
return V_139 ;
return V_2 -> V_250 -> V_4 . V_301 -> V_303 ( V_2 , V_283 ) ;
}
int F_172 ( struct V_1 * V_2 , struct V_304 * V_305 )
{
int V_125 = 0 ;
union V_306 V_307 ;
int V_308 ;
V_308 = F_173 ( V_305 -> V_309 ) ;
if ( V_308 > sizeof( V_307 ) )
return - V_145 ;
switch ( V_305 -> V_309 ) {
case V_310 :
V_307 = F_174 ( V_305 -> V_309 , V_2 -> V_4 . V_172 . V_311 ) ;
break;
case V_312 :
V_307 = F_174 ( V_305 -> V_309 , V_2 -> V_4 . V_172 . V_313 ) ;
break;
#if V_314 > 2
case V_315 :
V_307 = F_174 ( V_305 -> V_309 , V_2 -> V_4 . V_172 . V_316 ) ;
break;
case V_317 :
V_307 = F_174 ( V_305 -> V_309 , V_2 -> V_4 . V_172 . V_318 ) ;
break;
#endif
case V_319 :
V_307 = F_174 ( V_305 -> V_309 , V_2 -> V_4 . V_172 . V_187 ) ;
break;
case V_320 :
V_307 = F_174 ( V_305 -> V_309 , V_2 -> V_4 . V_172 . V_188 ) ;
break;
case V_321 : {
T_1 V_135 = F_175 ( V_2 ) ;
V_307 = F_174 ( V_305 -> V_309 , V_135 ) ;
break;
}
#if F_13 ( V_89 )
case V_322 :
V_307 = F_174 ( V_305 -> V_309 , V_2 -> V_4 . V_90 ) ;
break;
#endif
case V_323 :
V_307 = F_174 ( V_305 -> V_309 , V_2 -> V_4 . V_100 ) ;
break;
case V_324 :
V_307 = F_174 ( V_305 -> V_309 , V_2 -> V_4 . V_103 ) ;
break;
case V_325 :
V_307 = F_174 ( V_305 -> V_309 , V_326 ) ;
break;
case V_327 :
V_307 = F_174 ( V_305 -> V_309 , V_2 -> V_4 . V_292 ) ;
break;
default:
V_125 = V_2 -> V_250 -> V_4 . V_301 -> V_328 ( V_2 , V_305 -> V_309 , & V_307 ) ;
break;
}
if ( V_125 )
return V_125 ;
if ( F_176 ( ( char V_329 * ) ( unsigned long ) V_305 -> V_330 , & V_307 , V_308 ) )
V_125 = - V_331 ;
return V_125 ;
}
int F_177 ( struct V_1 * V_2 , struct V_304 * V_305 )
{
int V_125 = 0 ;
union V_306 V_307 ;
int V_308 ;
V_308 = F_173 ( V_305 -> V_309 ) ;
if ( V_308 > sizeof( V_307 ) )
return - V_145 ;
if ( F_178 ( & V_307 , ( char V_329 * ) ( unsigned long ) V_305 -> V_330 , V_308 ) )
return - V_331 ;
switch ( V_305 -> V_309 ) {
case V_310 :
V_2 -> V_4 . V_172 . V_311 = F_179 ( V_305 -> V_309 , V_307 ) ;
break;
case V_312 :
V_2 -> V_4 . V_172 . V_313 = F_179 ( V_305 -> V_309 , V_307 ) ;
break;
#if V_314 > 2
case V_315 :
V_2 -> V_4 . V_172 . V_316 = F_179 ( V_305 -> V_309 , V_307 ) ;
break;
case V_317 :
V_2 -> V_4 . V_172 . V_318 = F_179 ( V_305 -> V_309 , V_307 ) ;
break;
#endif
case V_319 :
V_2 -> V_4 . V_172 . V_187 = F_179 ( V_305 -> V_309 , V_307 ) ;
break;
case V_320 :
V_2 -> V_4 . V_172 . V_188 = F_179 ( V_305 -> V_309 , V_307 ) ;
break;
case V_321 : {
T_1 V_332 = F_179 ( V_305 -> V_309 , V_307 ) ;
F_180 ( V_2 , V_332 ) ;
break;
}
#if F_13 ( V_89 )
case V_322 : {
T_1 V_333 = F_179 ( V_305 -> V_309 , V_307 ) ;
F_181 ( V_2 , V_333 ) ;
break;
}
#endif
case V_334 : {
T_1 V_335 = F_179 ( V_305 -> V_309 , V_307 ) ;
F_182 ( V_2 , V_335 ) ;
break;
}
case V_336 : {
T_1 V_335 = F_179 ( V_305 -> V_309 , V_307 ) ;
F_183 ( V_2 , V_335 ) ;
break;
}
case V_324 : {
T_1 V_103 = F_179 ( V_305 -> V_309 , V_307 ) ;
F_123 ( V_2 , V_103 ) ;
break;
}
case V_323 : {
T_1 V_100 = F_179 ( V_305 -> V_309 , V_307 ) ;
F_164 ( V_2 , V_100 ) ;
break;
}
case V_327 :
V_2 -> V_4 . V_292 = F_179 ( V_305 -> V_309 , V_307 ) ;
break;
default:
V_125 = V_2 -> V_250 -> V_4 . V_301 -> V_337 ( V_2 , V_305 -> V_309 , & V_307 ) ;
break;
}
return V_125 ;
}
int F_184 ( struct V_1 * V_2 , struct V_338 * V_339 )
{
return - V_340 ;
}
int F_185 ( struct V_1 * V_2 , struct V_338 * V_339 )
{
return - V_340 ;
}
int F_186 ( struct V_1 * V_2 ,
struct V_341 * V_342 )
{
int V_125 ;
V_125 = F_187 ( V_2 , V_342 ) ;
return V_125 ;
}
int F_188 ( struct V_250 * V_250 , struct V_343 * log )
{
return - V_340 ;
}
void F_189 ( struct V_250 * V_250 , struct V_344 * free ,
struct V_344 * V_345 )
{
}
int F_190 ( struct V_250 * V_250 , struct V_344 * V_346 ,
unsigned long V_347 )
{
return 0 ;
}
int F_191 ( struct V_250 * V_250 ,
struct V_344 * V_348 ,
struct V_349 * V_350 )
{
return 0 ;
}
void F_192 ( struct V_250 * V_250 ,
struct V_349 * V_350 ,
const struct V_344 * V_351 )
{
}
void F_193 ( struct V_250 * V_250 , struct V_344 * V_348 )
{
}
void F_181 ( struct V_1 * V_2 , T_1 V_333 )
{
#if F_13 ( V_89 )
V_2 -> V_4 . V_90 = V_333 ;
#ifdef V_16
V_2 -> V_4 . V_352 &= ~ V_353 ;
if ( V_2 -> V_4 . V_90 & V_91 )
V_2 -> V_4 . V_352 |= V_353 ;
#endif
#endif
}
void F_164 ( struct V_1 * V_2 , T_1 V_354 )
{
V_2 -> V_4 . V_100 = V_354 ;
F_54 ( V_2 ) ;
F_63 ( V_2 ) ;
}
void F_182 ( struct V_1 * V_2 , T_1 V_335 )
{
F_194 ( V_335 , & V_2 -> V_4 . V_103 ) ;
F_61 () ;
F_45 ( V_115 , V_2 ) ;
F_62 ( V_2 ) ;
}
void F_183 ( struct V_1 * V_2 , T_1 V_335 )
{
F_195 ( V_335 , & V_2 -> V_4 . V_103 ) ;
if ( V_335 & ( V_104 | V_105 ) )
F_54 ( V_2 ) ;
F_63 ( V_2 ) ;
}
void F_196 ( unsigned long V_112 )
{
struct V_1 * V_2 = (struct V_1 * ) V_112 ;
if ( V_2 -> V_4 . V_100 & V_355 ) {
V_2 -> V_4 . V_291 = V_2 -> V_4 . V_297 ;
F_165 ( V_2 ) ;
}
F_182 ( V_2 , V_119 ) ;
}
static int F_197 ( struct V_141 * V_172 ,
T_6 V_330 , int V_356 )
{
switch ( V_356 ) {
case 0 :
V_172 -> V_357 |= V_358 ;
V_172 -> V_311 = V_330 ;
break;
case 1 :
V_172 -> V_357 |= V_359 ;
V_172 -> V_313 = V_330 ;
break;
#if V_314 > 2
case 2 :
V_172 -> V_357 |= V_360 ;
V_172 -> V_316 = V_330 ;
break;
case 3 :
V_172 -> V_357 |= V_361 ;
V_172 -> V_318 = V_330 ;
break;
#endif
default:
return - V_145 ;
}
V_172 -> V_357 |= V_362 ;
return 0 ;
}
static int F_198 ( struct V_141 * V_172 , T_6 V_330 ,
int type , int V_356 )
{
switch ( V_356 ) {
case 0 :
if ( type & V_186 )
V_172 -> V_357 |= V_363 ;
if ( type & V_183 )
V_172 -> V_357 |= V_364 ;
V_172 -> V_187 = V_330 ;
break;
case 1 :
if ( type & V_186 )
V_172 -> V_357 |= V_365 ;
if ( type & V_183 )
V_172 -> V_357 |= V_366 ;
V_172 -> V_188 = V_330 ;
break;
default:
return - V_145 ;
}
V_172 -> V_357 |= V_362 ;
return 0 ;
}
void F_199 ( struct V_1 * V_2 , T_2 V_367 , bool V_368 )
{
#ifdef V_16
F_46 ( V_367 & ~ ( V_369 | V_370 | V_371 ) ) ;
if ( V_368 ) {
if ( V_367 & V_372 )
V_2 -> V_4 . V_373 |= V_369 ;
if ( V_367 & V_18 )
V_2 -> V_4 . V_373 |= V_370 ;
if ( V_367 & V_374 )
V_2 -> V_4 . V_373 |= V_371 ;
} else {
if ( V_367 & V_372 )
V_2 -> V_4 . V_373 &= ~ V_369 ;
if ( V_367 & V_18 )
V_2 -> V_4 . V_373 &= ~ V_370 ;
if ( V_367 & V_374 )
V_2 -> V_4 . V_373 &= ~ V_371 ;
}
#endif
}
int F_200 ( struct V_1 * V_2 , T_2 V_242 , enum V_375 V_376 ,
enum V_377 V_378 , struct V_379 * V_380 )
{
int V_243 ;
T_4 V_244 ;
#ifdef V_129
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_61 ) &&
( V_242 & V_246 ) == V_2 -> V_4 . V_247 ) {
V_380 -> V_242 = V_242 ;
V_380 -> V_381 = ( V_2 -> V_4 . V_382 & V_246 ) |
( V_242 & ~ V_246 ) ;
V_380 -> V_383 = V_242 >> V_252 ;
V_380 -> V_384 = true ;
V_380 -> V_385 = true ;
V_380 -> V_386 = true ;
return 0 ;
}
#endif
switch ( V_376 ) {
case V_387 :
V_243 = F_121 ( V_2 , V_242 ) ;
break;
case V_388 :
V_243 = F_113 ( V_2 , V_242 ) ;
break;
default:
F_88 () ;
}
if ( V_243 < 0 )
return - V_389 ;
V_244 = F_116 ( V_2 , V_243 , V_242 ) ;
V_380 -> V_242 = V_242 ;
V_380 -> V_381 = ( V_244 & V_246 ) | ( V_242 & ~ V_246 ) ;
V_380 -> V_383 = V_242 >> V_252 ;
V_380 -> V_384 = true ;
V_380 -> V_385 = true ;
V_380 -> V_386 = true ;
return 0 ;
}
int F_201 ( struct V_1 * V_2 ,
struct V_390 * V_391 )
{
struct V_141 * V_172 ;
int V_392 , V_393 = 0 , V_394 = 0 ;
if ( ! ( V_391 -> V_395 & V_396 ) ) {
V_2 -> V_4 . V_148 . V_357 = 0 ;
V_2 -> V_19 = 0 ;
F_199 ( V_2 , V_18 , false ) ;
return 0 ;
}
F_199 ( V_2 , V_18 , true ) ;
V_2 -> V_19 = V_391 -> V_395 ;
V_2 -> V_4 . V_148 . V_357 = 0 ;
V_2 -> V_4 . V_172 . V_357 = V_397 ;
if ( V_2 -> V_19 & V_398 )
V_2 -> V_4 . V_148 . V_357 |= V_362 | V_399 ;
V_172 = & ( V_2 -> V_4 . V_148 ) ;
#ifdef V_16
V_172 -> V_400 = 0 ;
V_172 -> V_401 = 0 ;
#else
V_172 -> V_400 = V_402 | V_403 | V_404 |
V_405 ;
V_172 -> V_401 = V_406 | V_407 ;
#endif
if ( ! ( V_2 -> V_19 & V_408 ) )
return 0 ;
for ( V_392 = 0 ; V_392 < ( V_409 + V_410 ) ; V_392 ++ ) {
T_6 V_330 = V_391 -> V_4 . V_411 [ V_392 ] . V_330 ;
T_7 type = V_391 -> V_4 . V_411 [ V_392 ] . type ;
if ( type == V_412 )
continue;
if ( type & ! ( V_186 |
V_183 |
V_180 ) )
return - V_145 ;
if ( type & V_180 ) {
if ( F_197 ( V_172 , V_330 , V_393 ++ ) )
return - V_145 ;
} else {
if ( F_198 ( V_172 , V_330 ,
type , V_394 ++ ) )
return - V_145 ;
}
}
return 0 ;
}
void F_202 ( struct V_1 * V_2 , int V_413 )
{
V_2 -> V_413 = F_203 () ;
V_149 -> V_150 . V_1 = V_2 ;
}
void F_204 ( struct V_1 * V_2 )
{
V_149 -> V_150 . V_1 = NULL ;
V_2 -> V_413 = - 1 ;
F_100 () ;
}
void F_205 ( struct V_1 * V_2 )
{
V_2 -> V_250 -> V_4 . V_301 -> V_414 ( V_2 ) ;
}
int F_206 ( struct V_250 * V_250 )
{
return V_250 -> V_4 . V_301 -> V_415 ( V_250 ) ;
}
struct V_1 * F_207 ( struct V_250 * V_250 , unsigned int V_309 )
{
return V_250 -> V_4 . V_301 -> V_416 ( V_250 , V_309 ) ;
}
void F_208 ( struct V_1 * V_2 )
{
V_2 -> V_250 -> V_4 . V_301 -> V_417 ( V_2 ) ;
}
void F_209 ( struct V_250 * V_250 )
{
V_250 -> V_4 . V_301 -> V_418 ( V_250 ) ;
}
void F_210 ( struct V_1 * V_2 , int V_413 )
{
V_2 -> V_250 -> V_4 . V_301 -> V_419 ( V_2 , V_413 ) ;
}
void F_211 ( struct V_1 * V_2 )
{
V_2 -> V_250 -> V_4 . V_301 -> V_420 ( V_2 ) ;
}
int T_8 F_212 ( void )
{
#ifndef V_16
unsigned long V_83 [ 16 ] ;
unsigned long * V_421 = V_422 ;
unsigned long V_423 = 0 ;
unsigned long V_424 ;
int V_3 ;
V_425 = F_213 ( V_426 | V_427 ,
V_428 ) ;
if ( ! V_425 )
return - V_429 ;
V_83 [ 0 ] = F_99 ( V_430 ) ;
V_83 [ 1 ] = F_99 ( V_431 ) ;
V_83 [ 2 ] = F_99 ( V_432 ) ;
V_83 [ 3 ] = F_99 ( V_433 ) ;
V_83 [ 4 ] = F_99 ( V_434 ) ;
V_83 [ 5 ] = F_99 ( V_435 ) ;
V_83 [ 6 ] = F_99 ( V_436 ) ;
V_83 [ 7 ] = F_99 ( V_437 ) ;
V_83 [ 8 ] = F_99 ( V_438 ) ;
V_83 [ 9 ] = F_99 ( V_439 ) ;
V_83 [ 10 ] = F_99 ( V_440 ) ;
V_83 [ 11 ] = F_99 ( V_441 ) ;
V_83 [ 12 ] = F_99 ( V_442 ) ;
V_83 [ 13 ] = F_99 ( V_443 ) ;
V_83 [ 14 ] = F_99 ( V_444 ) ;
V_83 [ 15 ] = F_99 ( V_445 ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( V_83 [ V_3 ] > V_423 )
V_423 = V_3 ;
V_424 = V_421 [ V_3 + 1 ] - V_421 [ V_3 ] ;
memcpy ( ( void * ) V_425 + V_83 [ V_3 ] ,
( void * ) V_421 [ V_3 ] , V_424 ) ;
}
V_424 = V_421 [ V_423 + 1 ] - V_421 [ V_423 ] ;
F_214 ( V_425 , V_425 +
V_83 [ V_423 ] + V_424 ) ;
#endif
return 0 ;
}
void T_9 F_215 ( void )
{
F_216 ( V_425 , V_428 ) ;
F_217 () ;
}
