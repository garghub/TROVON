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
void F_14 ( struct V_1 * V_2 , T_1 V_18 )
{
T_1 V_19 = V_2 -> V_4 . V_6 -> V_7 ;
#ifdef V_16
V_18 |= V_20 ;
#endif
V_2 -> V_4 . V_6 -> V_7 = V_18 ;
F_15 ( V_2 , V_19 ) ;
F_11 ( V_2 ) ;
F_12 ( V_2 ) ;
}
static void F_16 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
F_17 ( V_2 , V_21 ) ;
F_18 ( V_21 , & V_2 -> V_4 . V_12 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
T_2 V_22 , T_2 V_23 )
{
V_2 -> V_4 . V_24 = V_22 ;
V_2 -> V_4 . V_25 = V_23 ;
F_16 ( V_2 , V_26 ) ;
}
static void F_20 ( struct V_1 * V_2 ,
T_2 V_22 , T_2 V_23 )
{
V_2 -> V_4 . V_24 = V_22 ;
V_2 -> V_4 . V_25 = V_23 ;
F_16 ( V_2 , V_27 ) ;
}
static void F_21 ( struct V_1 * V_2 ,
T_2 V_23 )
{
V_2 -> V_4 . V_25 = V_23 ;
F_16 ( V_2 , V_28 ) ;
}
static void F_22 ( struct V_1 * V_2 , T_2 V_22 ,
T_2 V_23 )
{
V_2 -> V_4 . V_24 = V_22 ;
V_2 -> V_4 . V_25 = V_23 ;
F_16 ( V_2 , V_29 ) ;
}
void F_23 ( struct V_1 * V_2 , T_2 V_23 )
{
V_2 -> V_4 . V_25 = V_23 ;
F_16 ( V_2 , V_30 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_31 ) ;
}
int F_25 ( struct V_1 * V_2 )
{
return F_26 ( V_31 , & V_2 -> V_4 . V_12 ) ;
}
void F_27 ( struct V_1 * V_2 )
{
F_28 ( V_31 , & V_2 -> V_4 . V_12 ) ;
}
void F_29 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
{
unsigned int V_34 = V_35 ;
if ( V_33 -> V_33 == V_36 )
V_34 = V_37 ;
F_16 ( V_2 , V_34 ) ;
}
void F_30 ( struct V_1 * V_2 )
{
F_28 ( V_35 , & V_2 -> V_4 . V_12 ) ;
F_28 ( V_37 , & V_2 -> V_4 . V_12 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_38 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
F_28 ( V_38 , & V_2 -> V_4 . V_12 ) ;
}
static void F_33 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
#ifdef V_16
F_34 ( V_39 , V_10 ) ;
F_34 ( V_40 , V_11 ) ;
#else
V_2 -> V_4 . V_6 -> V_10 = V_10 ;
V_2 -> V_4 . V_6 -> V_11 = V_11 ;
#endif
}
static void F_35 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_41 = V_10 ;
V_2 -> V_4 . V_42 = V_11 ;
}
static void F_36 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
if ( F_37 ( V_43 ) ) {
V_2 -> V_4 . V_44 = V_10 ;
V_2 -> V_4 . V_45 = V_11 ;
} else {
F_35 ( V_2 , V_10 , V_11 ) ;
}
}
static void F_38 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_46 = V_10 ;
V_2 -> V_4 . V_47 = V_11 ;
}
static unsigned long F_39 ( struct V_1 * V_2 )
{
#ifdef V_16
return F_40 ( V_48 ) ;
#else
return V_2 -> V_4 . V_6 -> V_49 ;
#endif
}
static void F_41 ( struct V_1 * V_2 , unsigned long V_50 )
{
#ifdef V_16
F_34 ( V_48 , V_50 ) ;
#else
V_2 -> V_4 . V_6 -> V_49 = V_50 ;
#endif
}
static unsigned long F_42 ( struct V_1 * V_2 )
{
#ifdef V_16
return F_40 ( V_51 ) ;
#else
return V_2 -> V_4 . V_6 -> V_52 ;
#endif
}
static void F_43 ( struct V_1 * V_2 , T_1 V_52 )
{
#ifdef V_16
F_34 ( V_51 , V_52 ) ;
#else
V_2 -> V_4 . V_6 -> V_52 = V_52 ;
#endif
}
static unsigned long F_44 ( struct V_1 * V_2 )
{
#ifdef V_16
return F_40 ( V_53 ) ;
#else
return V_2 -> V_4 . V_54 ;
#endif
}
static int F_45 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
int V_55 = 0 ;
T_2 V_56 = 0 ;
bool V_57 = false , V_58 = false , V_59 = false ;
T_2 V_60 = V_2 -> V_4 . V_6 -> V_61 ;
T_2 V_62 = F_3 ( V_2 , 1 ) ;
bool V_63 ;
bool V_64 = false ;
enum V_65 V_65 ;
T_2 V_18 = V_2 -> V_4 . V_6 -> V_7 ;
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_66 ) ) {
V_60 &= 0xffffffff ;
V_62 &= 0xffffffff ;
}
V_63 = ( V_60 == V_62 ) ;
V_63 = V_63 && ! ( V_2 -> V_4 . V_6 -> V_7 & V_67 ) ;
if ( V_21 == V_37 ) {
V_21 = V_35 ;
V_64 = true ;
}
if ( ( V_21 == V_35 ) && V_2 -> V_4 . V_68 )
V_59 = true ;
switch ( V_21 ) {
case V_26 :
case V_27 :
case V_29 :
V_58 = true ;
case V_28 :
case V_30 :
V_57 = true ;
case V_69 :
case V_70 :
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_55 = 1 ;
V_56 = V_76 | V_77 | V_78 ;
V_65 = V_79 ;
break;
case V_38 :
case V_80 :
case V_81 :
V_55 = V_2 -> V_4 . V_6 -> V_7 & V_76 ;
V_55 = V_55 && ! V_63 ;
V_56 = V_77 ;
V_65 = V_82 ;
break;
case V_83 :
V_55 = V_2 -> V_4 . V_6 -> V_7 & V_77 ;
V_55 = V_55 && ! V_63 ;
V_65 = V_84 ;
break;
case V_31 :
case V_85 :
V_64 = true ;
case V_35 :
case V_86 :
V_55 = V_2 -> V_4 . V_6 -> V_7 & V_87 ;
V_55 = V_55 && ! V_63 ;
V_56 = V_76 | V_77 | V_78 ;
V_65 = V_79 ;
break;
case V_88 :
V_55 = V_2 -> V_4 . V_6 -> V_7 & V_78 ;
V_55 = V_55 && ! V_63 ;
V_56 = V_77 ;
V_65 = V_82 ;
break;
}
if ( V_55 ) {
switch ( V_65 ) {
case V_79 :
F_33 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_82 :
F_35 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_89 :
F_36 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_84 :
F_38 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
}
V_2 -> V_4 . V_5 = V_2 -> V_4 . V_90 | V_2 -> V_4 . V_91 [ V_21 ] ;
if ( V_57 == true )
F_43 ( V_2 , V_2 -> V_4 . V_25 ) ;
if ( V_58 == true )
F_41 ( V_2 , V_2 -> V_4 . V_24 ) ;
if ( V_59 == true ) {
if ( V_2 -> V_4 . V_68 & V_92 )
F_46 ( V_93 , V_2 ) ;
else if ( V_2 -> V_4 . V_68 & V_94 ) {
F_47 ( V_2 -> V_4 . V_95 != V_96 ) ;
F_48 ( V_2 ) ;
}
}
V_18 &= V_56 ;
#if F_13 ( V_97 )
if ( V_2 -> V_4 . V_98 & V_99 )
V_18 |= V_100 ;
#endif
F_14 ( V_2 , V_18 ) ;
if ( ! V_64 )
F_28 ( V_21 , & V_2 -> V_4 . V_12 ) ;
}
#ifdef V_16
if ( V_2 -> V_4 . V_12 & V_101 )
F_49 ( V_2 , V_79 ) ;
if ( V_2 -> V_4 . V_12 & V_102 )
F_49 ( V_2 , V_82 ) ;
if ( V_2 -> V_4 . V_12 & V_83 )
F_49 ( V_2 , V_84 ) ;
#endif
return V_55 ;
}
static unsigned long F_50 ( struct V_1 * V_2 )
{
T_3 V_103 , V_104 , V_105 = 0 ;
T_3 V_106 = 0 ;
T_1 V_107 = F_51 ( V_2 -> V_4 . V_108 ) ;
V_104 = 1ULL << ( 63 - V_107 ) ;
V_103 = F_52 () ;
if ( V_103 & V_104 )
V_105 = V_104 ;
V_105 += V_104 - ( V_103 & ( V_104 - 1 ) ) ;
V_106 = V_105 ;
if ( F_53 ( V_106 , V_109 ) )
V_106 ++ ;
return F_54 (unsigned long long, nr_jiffies, NEXT_TIMER_MAX_DELTA) ;
}
static void F_55 ( struct V_1 * V_2 )
{
unsigned long V_106 ;
unsigned long V_110 ;
if ( ( V_2 -> V_4 . V_111 & ( V_112 | V_113 ) ) != ( V_112 | V_113 ) )
F_28 ( V_114 , & V_2 -> V_115 ) ;
F_56 ( & V_2 -> V_4 . V_116 , V_110 ) ;
V_106 = F_50 ( V_2 ) ;
if ( V_106 < V_117 )
F_57 ( & V_2 -> V_4 . V_118 , V_119 + V_106 ) ;
else
F_58 ( & V_2 -> V_4 . V_118 ) ;
F_59 ( & V_2 -> V_4 . V_116 , V_110 ) ;
}
void F_60 ( unsigned long V_120 )
{
struct V_1 * V_2 = (struct V_1 * ) V_120 ;
T_1 V_111 , V_121 ;
int V_122 ;
do {
V_121 = V_111 = V_2 -> V_4 . V_111 ;
V_122 = 0 ;
if ( V_111 & V_112 ) {
if ( V_111 & V_113 )
V_122 = 1 ;
else
V_121 = V_111 | V_113 ;
} else {
V_121 = V_111 | V_112 ;
}
} while ( F_61 ( & V_2 -> V_4 . V_111 , V_111 , V_121 ) != V_111 );
if ( V_121 & V_113 ) {
F_62 () ;
F_46 ( V_123 , V_2 ) ;
F_63 ( V_2 ) ;
}
if ( V_122 && ( V_2 -> V_4 . V_108 & V_124 ) &&
V_2 -> V_4 . V_125 ) {
F_62 () ;
F_46 ( V_114 , V_2 ) ;
F_63 ( V_2 ) ;
}
if ( ! V_122 )
F_55 ( V_2 ) ;
}
static void F_64 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 . V_108 & V_126 ) && ( V_2 -> V_4 . V_111 & V_127 ) )
F_24 ( V_2 ) ;
else
F_27 ( V_2 ) ;
if ( ( V_2 -> V_4 . V_108 & V_128 ) && ( V_2 -> V_4 . V_111 & V_113 ) )
F_31 ( V_2 ) ;
else
F_32 ( V_2 ) ;
}
static void F_65 ( struct V_1 * V_2 )
{
unsigned long * V_129 = & V_2 -> V_4 . V_12 ;
unsigned int V_21 ;
V_21 = F_66 ( * V_129 ) ;
while ( V_21 < V_130 ) {
if ( F_45 ( V_2 , V_21 ) )
break;
V_21 = F_67 ( V_129 ,
V_131 * sizeof( * V_129 ) ,
V_21 + 1 ) ;
}
V_2 -> V_4 . V_6 -> V_132 = ! ! * V_129 ;
}
int F_68 ( struct V_1 * V_2 )
{
int V_133 = 0 ;
F_69 ( ! F_70 () ) ;
F_65 ( V_2 ) ;
if ( V_2 -> V_115 ) {
return 1 ;
}
if ( V_2 -> V_4 . V_6 -> V_7 & V_134 ) {
F_71 () ;
F_72 ( V_2 ) ;
F_28 ( V_135 , & V_2 -> V_115 ) ;
F_73 () ;
F_74 ( V_2 , V_136 ) ;
V_133 = 1 ;
} ;
return V_133 ;
}
int F_75 ( struct V_1 * V_2 )
{
int V_133 = 1 ;
if ( F_76 ( V_123 , V_2 ) )
F_64 ( V_2 ) ;
#if F_13 ( V_137 ) || F_13 ( V_138 )
if ( F_76 ( V_139 , V_2 ) )
F_77 ( V_2 ) ;
#endif
if ( F_76 ( V_114 , V_2 ) ) {
V_2 -> V_140 -> V_141 = V_142 ;
V_133 = 0 ;
}
if ( F_76 ( V_93 , V_2 ) ) {
V_2 -> V_140 -> V_54 . V_54 = 0 ;
V_2 -> V_4 . V_143 = true ;
V_2 -> V_140 -> V_141 = V_144 ;
V_133 = 0 ;
}
return V_133 ;
}
int F_78 ( struct V_145 * V_145 , struct V_1 * V_2 )
{
int V_146 , V_147 ;
#ifdef V_15
unsigned int V_148 ;
int V_149 ;
T_3 V_150 [ 32 ] ;
#endif
if ( ! V_2 -> V_4 . V_151 ) {
V_145 -> V_141 = V_152 ;
return - V_153 ;
}
F_73 () ;
V_147 = F_79 ( V_2 ) ;
if ( V_147 <= 0 ) {
F_71 () ;
V_146 = V_147 ;
goto V_154;
}
F_80 () ;
#ifdef V_15
F_81 () ;
memcpy ( V_150 , V_155 -> V_156 . V_150 , sizeof( V_155 -> V_156 . V_150 ) ) ;
V_148 = V_155 -> V_156 . V_148 . V_157 ;
V_149 = V_155 -> V_156 . V_149 ;
memcpy ( V_155 -> V_156 . V_150 , V_2 -> V_4 . V_150 , sizeof( V_2 -> V_4 . V_150 ) ) ;
V_155 -> V_156 . V_148 . V_157 = V_2 -> V_4 . V_148 ;
V_2 -> V_158 = 1 ;
F_82 ( V_2 ) ;
#endif
F_83 () ;
V_146 = F_84 ( V_145 , V_2 ) ;
#ifdef V_15
F_85 ( V_2 ) ;
V_2 -> V_158 = 0 ;
memcpy ( V_2 -> V_4 . V_150 , V_155 -> V_156 . V_150 , sizeof( V_2 -> V_4 . V_150 ) ) ;
V_2 -> V_4 . V_148 = V_155 -> V_156 . V_148 . V_157 ;
memcpy ( V_155 -> V_156 . V_150 , V_150 , sizeof( V_155 -> V_156 . V_150 ) ) ;
V_155 -> V_156 . V_148 . V_157 = V_148 ;
V_155 -> V_156 . V_149 = V_149 ;
#endif
V_154:
V_2 -> V_159 = V_160 ;
return V_146 ;
}
static int F_86 ( struct V_145 * V_140 , struct V_1 * V_2 )
{
enum V_161 V_162 ;
V_162 = F_87 ( V_140 , V_2 ) ;
switch ( V_162 ) {
case V_163 :
F_88 ( V_2 , V_164 ) ;
return V_165 ;
case V_166 :
V_140 -> V_141 = V_167 ;
return V_168 ;
case V_169 :
F_2 ( V_170 L_6 ,
V_171 , V_2 -> V_4 . V_5 , V_2 -> V_4 . V_172 ) ;
V_140 -> V_173 . V_174 = ~ 0ULL << 32 ;
V_140 -> V_173 . V_174 |= V_2 -> V_4 . V_172 ;
F_23 ( V_2 , V_175 ) ;
return V_168 ;
case V_176 :
return V_168 ;
default:
F_89 () ;
}
}
static void F_90 ( struct V_177 * V_178 )
{
T_2 V_179 , V_180 , V_7 , V_8 ;
asm("mr %0, 1" : "=r"(r1));
asm("mflr %0" : "=r"(lr));
asm("mfmsr %0" : "=r"(msr));
asm("bl 1f; 1: mflr %0" : "=r"(ip));
memset ( V_178 , 0 , sizeof( * V_178 ) ) ;
V_178 -> V_181 [ 1 ] = V_179 ;
V_178 -> V_182 = V_180 ;
V_178 -> V_7 = V_7 ;
V_178 -> V_183 = V_8 ;
}
static void F_91 ( struct V_1 * V_2 ,
unsigned int V_184 )
{
struct V_177 V_178 ;
switch ( V_184 ) {
case V_185 :
F_90 ( & V_178 ) ;
F_92 ( & V_178 ) ;
break;
case V_186 :
F_90 ( & V_178 ) ;
F_93 ( & V_178 ) ;
break;
#if F_13 ( V_187 )
case V_188 :
F_90 ( & V_178 ) ;
F_94 ( & V_178 ) ;
break;
#endif
case V_189 :
break;
case V_190 :
F_90 ( & V_178 ) ;
F_95 ( & V_178 ) ;
break;
case V_191 :
F_90 ( & V_178 ) ;
#ifdef F_96
F_97 ( & V_178 ) ;
#else
F_98 ( & V_178 ) ;
#endif
break;
case V_192 :
F_98 ( & V_178 ) ;
break;
}
}
int F_99 ( struct V_145 * V_140 , struct V_1 * V_2 ,
unsigned int V_184 )
{
int V_133 = V_168 ;
int V_147 ;
int V_193 ;
#ifdef F_100
F_101 ( V_194 -> V_195 != 0 ) ;
#endif
F_102 () ;
F_103 ( V_2 ) ;
F_91 ( V_2 , V_184 ) ;
F_71 () ;
F_104 ( V_184 , V_2 ) ;
F_105 () ;
V_140 -> V_141 = V_196 ;
V_140 -> V_197 = 1 ;
switch ( V_184 ) {
case V_189 :
F_2 ( L_7 , F_40 ( V_198 ) ) ;
F_1 ( V_2 ) ;
V_140 -> V_173 . V_174 = ~ 1ULL << 32 ;
V_140 -> V_173 . V_174 |= F_40 ( V_198 ) ;
V_133 = V_168 ;
break;
case V_185 :
F_106 ( V_2 , V_199 ) ;
V_133 = V_200 ;
break;
case V_186 :
F_106 ( V_2 , V_201 ) ;
V_133 = V_200 ;
break;
case V_191 :
V_133 = V_200 ;
break;
case V_188 :
F_106 ( V_2 , V_202 ) ;
V_133 = V_200 ;
break;
case V_203 :
F_106 ( V_2 , V_204 ) ;
V_133 = V_200 ;
break;
case V_205 :
F_106 ( V_2 , V_204 ) ;
V_133 = V_200 ;
break;
case V_190 :
V_133 = V_200 ;
break;
case V_206 :
V_133 = F_86 ( V_140 , V_2 ) ;
break;
case V_207 :
if ( V_2 -> V_4 . V_6 -> V_7 & ( V_67 | V_20 ) ) {
F_23 ( V_2 , V_2 -> V_4 . V_208 ) ;
V_133 = V_200 ;
F_106 ( V_2 , V_209 ) ;
break;
}
V_133 = F_86 ( V_140 , V_2 ) ;
break;
case V_210 :
F_16 ( V_2 , V_71 ) ;
F_106 ( V_2 , V_211 ) ;
V_133 = V_200 ;
break;
#ifdef F_107
case V_212 : {
if ( V_2 -> V_4 . V_6 -> V_7 & V_14 )
F_9 ( V_2 ) ;
else
F_16 ( V_2 ,
V_72 ) ;
V_133 = V_200 ;
break;
}
case V_213 :
F_16 ( V_2 , V_73 ) ;
V_133 = V_200 ;
break;
case V_214 :
F_16 ( V_2 , V_74 ) ;
V_133 = V_200 ;
break;
#else
case V_212 :
F_23 ( V_2 , V_215 | V_216 ) ;
V_133 = V_200 ;
break;
case V_213 :
case V_214 :
F_2 ( V_170 L_8 ,
V_171 , V_184 , V_2 -> V_4 . V_5 ) ;
V_140 -> V_173 . V_174 = V_184 ;
V_133 = V_168 ;
break;
#endif
case V_217 :
F_20 ( V_2 , V_2 -> V_4 . V_218 ,
V_2 -> V_4 . V_208 ) ;
F_106 ( V_2 , V_219 ) ;
V_133 = V_200 ;
break;
case V_220 :
F_21 ( V_2 , V_2 -> V_4 . V_208 ) ;
F_106 ( V_2 , V_221 ) ;
V_133 = V_200 ;
break;
case V_222 :
F_22 ( V_2 , V_2 -> V_4 . V_218 ,
V_2 -> V_4 . V_208 ) ;
V_133 = V_200 ;
break;
#ifdef V_16
case V_223 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_67 ) ) {
F_108 ( V_2 , 3 , F_109 ( V_2 ) ) ;
} else {
F_23 ( V_2 , V_224 ) ;
}
V_133 = V_200 ;
break;
#else
case V_225 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_67 ) &&
( ( ( T_1 ) F_3 ( V_2 , 0 ) ) == V_226 ) ) {
F_108 ( V_2 , 3 , F_109 ( V_2 ) ) ;
V_133 = V_200 ;
} else {
F_16 ( V_2 , V_70 ) ;
}
F_106 ( V_2 , V_227 ) ;
V_133 = V_200 ;
break;
#endif
case V_228 : {
unsigned long V_229 = V_2 -> V_4 . V_218 ;
int V_230 ;
T_4 V_231 ;
T_5 V_232 ;
#ifdef V_137
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_67 ) &&
( V_229 & V_233 ) == V_2 -> V_4 . V_234 ) {
F_110 ( V_2 ) ;
F_106 ( V_2 , V_235 ) ;
V_133 = V_200 ;
break;
}
#endif
V_230 = F_111 ( V_2 , V_229 ) ;
if ( V_230 < 0 ) {
F_19 ( V_2 ,
V_2 -> V_4 . V_218 ,
V_2 -> V_4 . V_208 ) ;
F_112 ( V_2 ) ;
F_106 ( V_2 , V_236 ) ;
V_133 = V_200 ;
break;
}
V_193 = F_113 ( & V_2 -> V_237 -> V_238 ) ;
V_231 = F_114 ( V_2 , V_230 , V_229 ) ;
V_232 = V_231 >> V_239 ;
if ( F_115 ( V_2 -> V_237 , V_232 ) ) {
F_116 ( V_2 , V_229 , V_231 , V_230 ) ;
F_106 ( V_2 , V_235 ) ;
V_133 = V_200 ;
} else {
V_2 -> V_4 . V_240 = V_231 ;
V_2 -> V_4 . V_241 = V_229 ;
V_133 = F_117 ( V_140 , V_2 ) ;
F_106 ( V_2 , V_242 ) ;
}
F_118 ( & V_2 -> V_237 -> V_238 , V_193 ) ;
break;
}
case V_243 : {
unsigned long V_229 = V_2 -> V_4 . V_5 ;
T_4 V_231 ;
T_5 V_232 ;
int V_230 ;
V_133 = V_200 ;
V_230 = F_119 ( V_2 , V_229 ) ;
if ( V_230 < 0 ) {
F_16 ( V_2 , V_69 ) ;
F_120 ( V_2 ) ;
F_106 ( V_2 , V_244 ) ;
break;
}
F_106 ( V_2 , V_245 ) ;
V_193 = F_113 ( & V_2 -> V_237 -> V_238 ) ;
V_231 = F_114 ( V_2 , V_230 , V_229 ) ;
V_232 = V_231 >> V_239 ;
if ( F_115 ( V_2 -> V_237 , V_232 ) ) {
F_116 ( V_2 , V_229 , V_231 , V_230 ) ;
} else {
F_16 ( V_2 , V_83 ) ;
}
F_118 ( & V_2 -> V_237 -> V_238 , V_193 ) ;
break;
}
case V_246 : {
T_1 V_247 ;
V_2 -> V_4 . V_5 = F_40 ( V_248 ) ;
V_247 = F_40 ( V_249 ) ;
V_247 &= V_250 | V_251 | V_252 | V_253 ;
F_34 ( V_249 , V_247 ) ;
V_140 -> V_141 = V_254 ;
F_106 ( V_2 , V_255 ) ;
V_133 = V_168 ;
break;
}
default:
F_2 ( V_256 L_9 , V_184 ) ;
F_89 () ;
}
if ( ! ( V_133 & V_168 ) ) {
F_73 () ;
V_147 = F_79 ( V_2 ) ;
if ( V_147 <= 0 ) {
F_71 () ;
V_133 = ( V_147 << 2 ) | V_168 | ( V_133 & V_257 ) ;
} else {
F_83 () ;
}
}
return V_133 ;
}
static void F_121 ( struct V_1 * V_2 , T_1 V_121 )
{
T_1 V_258 = V_2 -> V_4 . V_111 ;
V_2 -> V_4 . V_111 = V_121 ;
if ( ( V_258 ^ V_2 -> V_4 . V_111 ) & ( V_112 | V_113 ) )
F_55 ( V_2 ) ;
F_64 ( V_2 ) ;
}
int F_122 ( struct V_1 * V_2 )
{
int V_3 ;
int V_133 ;
V_2 -> V_4 . V_5 = 0 ;
V_2 -> V_4 . V_6 -> V_259 = V_2 -> V_260 ;
F_108 ( V_2 , 1 , ( 16 << 20 ) - 8 ) ;
F_14 ( V_2 , 0 ) ;
#ifndef V_16
V_2 -> V_4 . V_13 = V_261 | V_78 | V_262 | V_263 ;
V_2 -> V_4 . V_264 = 1 ;
V_2 -> V_4 . V_6 -> V_7 = 0 ;
#endif
V_2 -> V_4 . V_90 = 0x55550000 ;
for ( V_3 = 0 ; V_3 < V_130 ; V_3 ++ )
V_2 -> V_4 . V_91 [ V_3 ] = 0x7700 | V_3 * 4 ;
F_123 ( V_2 ) ;
V_133 = F_124 ( V_2 ) ;
F_125 ( V_2 ) ;
return V_133 ;
}
int F_126 ( struct V_1 * V_2 )
{
F_127 ( & V_2 -> V_4 . V_116 ) ;
F_128 ( & V_2 -> V_4 . V_118 , F_60 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_129 ( struct V_1 * V_2 )
{
F_130 ( & V_2 -> V_4 . V_118 ) ;
}
int F_131 ( struct V_1 * V_2 , struct V_265 * V_178 )
{
int V_3 ;
V_178 -> V_5 = V_2 -> V_4 . V_5 ;
V_178 -> V_266 = F_132 ( V_2 ) ;
V_178 -> V_9 = V_2 -> V_4 . V_9 ;
V_178 -> V_8 = V_2 -> V_4 . V_8 ;
V_178 -> V_267 = F_133 ( V_2 ) ;
V_178 -> V_7 = V_2 -> V_4 . V_6 -> V_7 ;
V_178 -> V_10 = V_2 -> V_4 . V_6 -> V_10 ;
V_178 -> V_11 = V_2 -> V_4 . V_6 -> V_11 ;
V_178 -> V_268 = V_2 -> V_4 . V_268 ;
V_178 -> V_269 = V_2 -> V_4 . V_6 -> V_269 ;
V_178 -> V_270 = V_2 -> V_4 . V_6 -> V_270 ;
V_178 -> V_271 = V_2 -> V_4 . V_6 -> V_271 ;
V_178 -> V_272 = V_2 -> V_4 . V_6 -> V_272 ;
V_178 -> V_273 = V_2 -> V_4 . V_6 -> V_273 ;
V_178 -> V_274 = V_2 -> V_4 . V_6 -> V_274 ;
V_178 -> V_275 = V_2 -> V_4 . V_6 -> V_275 ;
V_178 -> V_276 = V_2 -> V_4 . V_6 -> V_276 ;
for ( V_3 = 0 ; V_3 < F_134 ( V_178 -> V_181 ) ; V_3 ++ )
V_178 -> V_181 [ V_3 ] = F_3 ( V_2 , V_3 ) ;
return 0 ;
}
int F_135 ( struct V_1 * V_2 , struct V_265 * V_178 )
{
int V_3 ;
V_2 -> V_4 . V_5 = V_178 -> V_5 ;
F_136 ( V_2 , V_178 -> V_266 ) ;
V_2 -> V_4 . V_9 = V_178 -> V_9 ;
V_2 -> V_4 . V_8 = V_178 -> V_8 ;
F_137 ( V_2 , V_178 -> V_267 ) ;
F_14 ( V_2 , V_178 -> V_7 ) ;
V_2 -> V_4 . V_6 -> V_10 = V_178 -> V_10 ;
V_2 -> V_4 . V_6 -> V_11 = V_178 -> V_11 ;
F_138 ( V_2 , V_178 -> V_268 ) ;
V_2 -> V_4 . V_6 -> V_269 = V_178 -> V_269 ;
V_2 -> V_4 . V_6 -> V_270 = V_178 -> V_270 ;
V_2 -> V_4 . V_6 -> V_271 = V_178 -> V_271 ;
V_2 -> V_4 . V_6 -> V_272 = V_178 -> V_272 ;
V_2 -> V_4 . V_6 -> V_273 = V_178 -> V_273 ;
V_2 -> V_4 . V_6 -> V_274 = V_178 -> V_274 ;
V_2 -> V_4 . V_6 -> V_275 = V_178 -> V_275 ;
V_2 -> V_4 . V_6 -> V_276 = V_178 -> V_276 ;
for ( V_3 = 0 ; V_3 < F_134 ( V_178 -> V_181 ) ; V_3 ++ )
F_108 ( V_2 , V_3 , V_178 -> V_181 [ V_3 ] ) ;
return 0 ;
}
static void F_139 ( struct V_1 * V_2 ,
struct V_277 * V_278 )
{
T_3 V_103 = F_52 () ;
V_278 -> V_279 . V_280 . V_281 |= V_282 ;
V_278 -> V_279 . V_280 . V_41 = V_2 -> V_4 . V_41 ;
V_278 -> V_279 . V_280 . V_42 = V_2 -> V_4 . V_42 ;
V_278 -> V_279 . V_280 . V_283 = V_2 -> V_4 . V_283 ;
V_278 -> V_279 . V_280 . V_52 = F_42 ( V_2 ) ;
V_278 -> V_279 . V_280 . V_50 = F_39 ( V_2 ) ;
V_278 -> V_279 . V_280 . V_111 = V_2 -> V_4 . V_111 ;
V_278 -> V_279 . V_280 . V_108 = V_2 -> V_4 . V_108 ;
V_278 -> V_279 . V_280 . V_284 = F_140 ( V_2 , V_103 ) ;
V_278 -> V_279 . V_280 . V_103 = V_103 ;
V_278 -> V_279 . V_280 . V_285 = V_2 -> V_4 . V_285 ;
}
static int F_141 ( struct V_1 * V_2 ,
struct V_277 * V_278 )
{
if ( ! ( V_278 -> V_279 . V_280 . V_281 & V_282 ) )
return 0 ;
V_2 -> V_4 . V_41 = V_278 -> V_279 . V_280 . V_41 ;
V_2 -> V_4 . V_42 = V_278 -> V_279 . V_280 . V_42 ;
V_2 -> V_4 . V_283 = V_278 -> V_279 . V_280 . V_283 ;
F_43 ( V_2 , V_278 -> V_279 . V_280 . V_52 ) ;
F_41 ( V_2 , V_278 -> V_279 . V_280 . V_50 ) ;
V_2 -> V_4 . V_285 = V_278 -> V_279 . V_280 . V_285 ;
F_142 ( V_2 , V_278 -> V_279 . V_280 . V_108 ) ;
if ( V_278 -> V_279 . V_280 . V_286 & V_287 ) {
V_2 -> V_4 . V_284 = V_278 -> V_279 . V_280 . V_284 ;
F_143 ( V_2 ) ;
}
if ( V_278 -> V_279 . V_280 . V_286 & V_288 )
F_121 ( V_2 , V_278 -> V_279 . V_280 . V_111 ) ;
return 0 ;
}
static void F_144 ( struct V_1 * V_2 ,
struct V_277 * V_278 )
{
V_278 -> V_279 . V_280 . V_281 |= V_289 ;
V_278 -> V_279 . V_280 . V_259 = V_2 -> V_260 ;
V_278 -> V_279 . V_280 . V_46 = V_2 -> V_4 . V_46 ;
V_278 -> V_279 . V_280 . V_47 = V_2 -> V_4 . V_47 ;
V_278 -> V_279 . V_280 . V_290 = V_2 -> V_4 . V_290 ;
V_278 -> V_279 . V_280 . V_90 = V_2 -> V_4 . V_90 ;
}
static int F_145 ( struct V_1 * V_2 ,
struct V_277 * V_278 )
{
if ( ! ( V_278 -> V_279 . V_280 . V_281 & V_289 ) )
return 0 ;
if ( V_278 -> V_279 . V_280 . V_259 != V_2 -> V_260 )
return - V_153 ;
V_2 -> V_4 . V_46 = V_278 -> V_279 . V_280 . V_46 ;
V_2 -> V_4 . V_47 = V_278 -> V_279 . V_280 . V_47 ;
V_2 -> V_4 . V_290 = V_278 -> V_279 . V_280 . V_290 ;
V_2 -> V_4 . V_90 = V_278 -> V_279 . V_280 . V_90 ;
return 0 ;
}
void F_146 ( struct V_1 * V_2 , struct V_277 * V_278 )
{
V_278 -> V_279 . V_280 . V_281 |= V_291 ;
V_278 -> V_279 . V_280 . V_292 [ 0 ] = V_2 -> V_4 . V_91 [ V_80 ] ;
V_278 -> V_279 . V_280 . V_292 [ 1 ] = V_2 -> V_4 . V_91 [ V_83 ] ;
V_278 -> V_279 . V_280 . V_292 [ 2 ] = V_2 -> V_4 . V_91 [ V_27 ] ;
V_278 -> V_279 . V_280 . V_292 [ 3 ] = V_2 -> V_4 . V_91 [ V_28 ] ;
V_278 -> V_279 . V_280 . V_292 [ 4 ] = V_2 -> V_4 . V_91 [ V_35 ] ;
V_278 -> V_279 . V_280 . V_292 [ 5 ] = V_2 -> V_4 . V_91 [ V_29 ] ;
V_278 -> V_279 . V_280 . V_292 [ 6 ] = V_2 -> V_4 . V_91 [ V_30 ] ;
V_278 -> V_279 . V_280 . V_292 [ 7 ] = V_2 -> V_4 . V_91 [ V_71 ] ;
V_278 -> V_279 . V_280 . V_292 [ 8 ] = V_2 -> V_4 . V_91 [ V_70 ] ;
V_278 -> V_279 . V_280 . V_292 [ 9 ] = V_2 -> V_4 . V_91 [ V_75 ] ;
V_278 -> V_279 . V_280 . V_292 [ 10 ] = V_2 -> V_4 . V_91 [ V_31 ] ;
V_278 -> V_279 . V_280 . V_292 [ 11 ] = V_2 -> V_4 . V_91 [ V_85 ] ;
V_278 -> V_279 . V_280 . V_292 [ 12 ] = V_2 -> V_4 . V_91 [ V_38 ] ;
V_278 -> V_279 . V_280 . V_292 [ 13 ] = V_2 -> V_4 . V_91 [ V_26 ] ;
V_278 -> V_279 . V_280 . V_292 [ 14 ] = V_2 -> V_4 . V_91 [ V_69 ] ;
V_278 -> V_279 . V_280 . V_292 [ 15 ] = V_2 -> V_4 . V_91 [ V_88 ] ;
}
int F_147 ( struct V_1 * V_2 , struct V_277 * V_278 )
{
if ( ! ( V_278 -> V_279 . V_280 . V_281 & V_291 ) )
return 0 ;
V_2 -> V_4 . V_91 [ V_80 ] = V_278 -> V_279 . V_280 . V_292 [ 0 ] ;
V_2 -> V_4 . V_91 [ V_83 ] = V_278 -> V_279 . V_280 . V_292 [ 1 ] ;
V_2 -> V_4 . V_91 [ V_27 ] = V_278 -> V_279 . V_280 . V_292 [ 2 ] ;
V_2 -> V_4 . V_91 [ V_28 ] = V_278 -> V_279 . V_280 . V_292 [ 3 ] ;
V_2 -> V_4 . V_91 [ V_35 ] = V_278 -> V_279 . V_280 . V_292 [ 4 ] ;
V_2 -> V_4 . V_91 [ V_29 ] = V_278 -> V_279 . V_280 . V_292 [ 5 ] ;
V_2 -> V_4 . V_91 [ V_30 ] = V_278 -> V_279 . V_280 . V_292 [ 6 ] ;
V_2 -> V_4 . V_91 [ V_71 ] = V_278 -> V_279 . V_280 . V_292 [ 7 ] ;
V_2 -> V_4 . V_91 [ V_70 ] = V_278 -> V_279 . V_280 . V_292 [ 8 ] ;
V_2 -> V_4 . V_91 [ V_75 ] = V_278 -> V_279 . V_280 . V_292 [ 9 ] ;
V_2 -> V_4 . V_91 [ V_31 ] = V_278 -> V_279 . V_280 . V_292 [ 10 ] ;
V_2 -> V_4 . V_91 [ V_85 ] = V_278 -> V_279 . V_280 . V_292 [ 11 ] ;
V_2 -> V_4 . V_91 [ V_38 ] = V_278 -> V_279 . V_280 . V_292 [ 12 ] ;
V_2 -> V_4 . V_91 [ V_26 ] = V_278 -> V_279 . V_280 . V_292 [ 13 ] ;
V_2 -> V_4 . V_91 [ V_69 ] = V_278 -> V_279 . V_280 . V_292 [ 14 ] ;
V_2 -> V_4 . V_91 [ V_88 ] = V_278 -> V_279 . V_280 . V_292 [ 15 ] ;
return 0 ;
}
int F_148 ( struct V_1 * V_2 ,
struct V_277 * V_278 )
{
V_278 -> V_293 = V_2 -> V_4 . V_293 ;
F_139 ( V_2 , V_278 ) ;
F_144 ( V_2 , V_278 ) ;
F_149 ( V_2 , V_278 ) ;
return 0 ;
}
int F_150 ( struct V_1 * V_2 ,
struct V_277 * V_278 )
{
int V_146 ;
if ( V_2 -> V_4 . V_293 != V_278 -> V_293 )
return - V_153 ;
V_146 = F_141 ( V_2 , V_278 ) ;
if ( V_146 < 0 )
return V_146 ;
V_146 = F_145 ( V_2 , V_278 ) ;
if ( V_146 < 0 )
return V_146 ;
return F_151 ( V_2 , V_278 ) ;
}
int F_152 ( struct V_1 * V_2 , struct V_294 * V_295 )
{
int V_133 = 0 ;
union V_296 V_157 ;
int V_297 ;
long int V_3 ;
V_297 = F_153 ( V_295 -> V_298 ) ;
if ( V_297 > sizeof( V_157 ) )
return - V_153 ;
switch ( V_295 -> V_298 ) {
case V_299 :
case V_300 :
case V_301 :
case V_302 :
V_3 = V_295 -> V_298 - V_299 ;
V_157 = F_154 ( V_295 -> V_298 , V_2 -> V_4 . V_303 . V_304 [ V_3 ] ) ;
break;
case V_305 :
case V_306 :
V_3 = V_295 -> V_298 - V_305 ;
V_157 = F_154 ( V_295 -> V_298 , V_2 -> V_4 . V_303 . V_307 [ V_3 ] ) ;
break;
case V_308 : {
T_1 V_54 = F_44 ( V_2 ) ;
V_157 = F_154 ( V_295 -> V_298 , V_54 ) ;
break;
}
#if F_13 ( V_97 )
case V_309 :
V_157 = F_154 ( V_295 -> V_298 , V_2 -> V_4 . V_98 ) ;
break;
#endif
case V_310 :
V_157 = F_154 ( V_295 -> V_298 , V_2 -> V_4 . V_108 ) ;
break;
case V_311 :
V_157 = F_154 ( V_295 -> V_298 , V_2 -> V_4 . V_111 ) ;
break;
case V_312 :
V_157 = F_154 ( V_295 -> V_298 , V_313 ) ;
break;
default:
V_133 = F_155 ( V_2 , V_295 -> V_298 , & V_157 ) ;
break;
}
if ( V_133 )
return V_133 ;
if ( F_156 ( ( char V_314 * ) ( unsigned long ) V_295 -> V_315 , & V_157 , V_297 ) )
V_133 = - V_316 ;
return V_133 ;
}
int F_157 ( struct V_1 * V_2 , struct V_294 * V_295 )
{
int V_133 = 0 ;
union V_296 V_157 ;
int V_297 ;
long int V_3 ;
V_297 = F_153 ( V_295 -> V_298 ) ;
if ( V_297 > sizeof( V_157 ) )
return - V_153 ;
if ( F_158 ( & V_157 , ( char V_314 * ) ( unsigned long ) V_295 -> V_315 , V_297 ) )
return - V_316 ;
switch ( V_295 -> V_298 ) {
case V_299 :
case V_300 :
case V_301 :
case V_302 :
V_3 = V_295 -> V_298 - V_299 ;
V_2 -> V_4 . V_303 . V_304 [ V_3 ] = F_159 ( V_295 -> V_298 , V_157 ) ;
break;
case V_305 :
case V_306 :
V_3 = V_295 -> V_298 - V_305 ;
V_2 -> V_4 . V_303 . V_307 [ V_3 ] = F_159 ( V_295 -> V_298 , V_157 ) ;
break;
case V_308 : {
T_1 V_317 = F_159 ( V_295 -> V_298 , V_157 ) ;
F_160 ( V_2 , V_317 ) ;
break;
}
#if F_13 ( V_97 )
case V_309 : {
T_1 V_318 = F_159 ( V_295 -> V_298 , V_157 ) ;
F_161 ( V_2 , V_318 ) ;
break;
}
#endif
case V_319 : {
T_1 V_320 = F_159 ( V_295 -> V_298 , V_157 ) ;
F_162 ( V_2 , V_320 ) ;
break;
}
case V_321 : {
T_1 V_320 = F_159 ( V_295 -> V_298 , V_157 ) ;
F_163 ( V_2 , V_320 ) ;
break;
}
case V_311 : {
T_1 V_111 = F_159 ( V_295 -> V_298 , V_157 ) ;
F_121 ( V_2 , V_111 ) ;
break;
}
case V_310 : {
T_1 V_108 = F_159 ( V_295 -> V_298 , V_157 ) ;
F_142 ( V_2 , V_108 ) ;
break;
}
default:
V_133 = F_164 ( V_2 , V_295 -> V_298 , & V_157 ) ;
break;
}
return V_133 ;
}
int F_165 ( struct V_1 * V_2 ,
struct V_322 * V_323 )
{
return - V_153 ;
}
int F_166 ( struct V_1 * V_2 , struct V_324 * V_325 )
{
return - V_326 ;
}
int F_167 ( struct V_1 * V_2 , struct V_324 * V_325 )
{
return - V_326 ;
}
int F_168 ( struct V_1 * V_2 ,
struct V_327 * V_328 )
{
int V_133 ;
V_133 = F_169 ( V_2 , V_328 ) ;
return V_133 ;
}
int F_170 ( struct V_237 * V_237 , struct V_329 * log )
{
return - V_326 ;
}
void F_171 ( struct V_330 * free ,
struct V_330 * V_331 )
{
}
int F_172 ( struct V_330 * V_332 ,
unsigned long V_333 )
{
return 0 ;
}
int F_173 ( struct V_237 * V_237 ,
struct V_330 * V_334 ,
struct V_335 * V_336 )
{
return 0 ;
}
void F_174 ( struct V_237 * V_237 ,
struct V_335 * V_336 ,
const struct V_330 * V_337 )
{
}
void F_175 ( struct V_237 * V_237 , struct V_330 * V_334 )
{
}
void F_161 ( struct V_1 * V_2 , T_1 V_318 )
{
#if F_13 ( V_97 )
V_2 -> V_4 . V_98 = V_318 ;
#ifdef V_16
V_2 -> V_4 . V_338 &= ~ V_339 ;
if ( V_2 -> V_4 . V_98 & V_99 )
V_2 -> V_4 . V_338 |= V_339 ;
#endif
#endif
}
void F_142 ( struct V_1 * V_2 , T_1 V_340 )
{
V_2 -> V_4 . V_108 = V_340 ;
F_55 ( V_2 ) ;
F_64 ( V_2 ) ;
}
void F_162 ( struct V_1 * V_2 , T_1 V_320 )
{
F_176 ( V_320 , & V_2 -> V_4 . V_111 ) ;
F_62 () ;
F_46 ( V_123 , V_2 ) ;
F_63 ( V_2 ) ;
}
void F_163 ( struct V_1 * V_2 , T_1 V_320 )
{
F_177 ( V_320 , & V_2 -> V_4 . V_111 ) ;
if ( V_320 & ( V_112 | V_113 ) )
F_55 ( V_2 ) ;
F_64 ( V_2 ) ;
}
void F_178 ( unsigned long V_120 )
{
struct V_1 * V_2 = (struct V_1 * ) V_120 ;
if ( V_2 -> V_4 . V_108 & V_341 ) {
V_2 -> V_4 . V_284 = V_2 -> V_4 . V_290 ;
F_143 ( V_2 ) ;
}
F_162 ( V_2 , V_127 ) ;
}
void F_179 ( struct V_1 * V_2 , int V_342 )
{
V_2 -> V_342 = F_180 () ;
V_155 -> V_156 . V_1 = V_2 ;
}
void F_181 ( struct V_1 * V_2 )
{
V_155 -> V_156 . V_1 = NULL ;
V_2 -> V_342 = - 1 ;
}
int T_6 F_182 ( void )
{
#ifndef V_16
unsigned long V_91 [ 16 ] ;
unsigned long * V_343 = V_344 ;
unsigned long V_345 = 0 ;
unsigned long V_346 ;
int V_3 ;
V_347 = F_183 ( V_348 | V_349 ,
V_350 ) ;
if ( ! V_347 )
return - V_351 ;
V_91 [ 0 ] = F_40 ( V_352 ) ;
V_91 [ 1 ] = F_40 ( V_353 ) ;
V_91 [ 2 ] = F_40 ( V_354 ) ;
V_91 [ 3 ] = F_40 ( V_355 ) ;
V_91 [ 4 ] = F_40 ( V_356 ) ;
V_91 [ 5 ] = F_40 ( V_357 ) ;
V_91 [ 6 ] = F_40 ( V_358 ) ;
V_91 [ 7 ] = F_40 ( V_359 ) ;
V_91 [ 8 ] = F_40 ( V_360 ) ;
V_91 [ 9 ] = F_40 ( V_361 ) ;
V_91 [ 10 ] = F_40 ( V_362 ) ;
V_91 [ 11 ] = F_40 ( V_363 ) ;
V_91 [ 12 ] = F_40 ( V_364 ) ;
V_91 [ 13 ] = F_40 ( V_365 ) ;
V_91 [ 14 ] = F_40 ( V_366 ) ;
V_91 [ 15 ] = F_40 ( V_367 ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( V_91 [ V_3 ] > V_345 )
V_345 = V_3 ;
V_346 = V_343 [ V_3 + 1 ] - V_343 [ V_3 ] ;
memcpy ( ( void * ) V_347 + V_91 [ V_3 ] ,
( void * ) V_343 [ V_3 ] , V_346 ) ;
}
V_346 = V_343 [ V_345 + 1 ] - V_343 [ V_345 ] ;
F_184 ( V_347 , V_347 +
V_91 [ V_345 ] + V_346 ) ;
#endif
return 0 ;
}
void T_7 F_185 ( void )
{
F_186 ( V_347 , V_350 ) ;
F_187 () ;
}
