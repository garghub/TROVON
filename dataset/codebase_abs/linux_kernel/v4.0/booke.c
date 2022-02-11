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
static inline void F_12 ( struct V_1 * V_2 )
{
#ifdef F_13
if ( ! ( V_15 -> V_16 . V_17 -> V_7 & V_18 ) ) {
F_14 () ;
F_15 ( & V_2 -> V_4 . V_19 ) ;
V_15 -> V_16 . V_20 = & V_2 -> V_4 . V_19 ;
V_15 -> V_16 . V_17 -> V_7 |= V_18 ;
}
#endif
}
static inline void F_16 ( struct V_1 * V_2 )
{
#ifdef F_13
if ( V_15 -> V_16 . V_17 -> V_7 & V_18 )
F_17 ( V_15 ) ;
V_15 -> V_16 . V_20 = NULL ;
#endif
}
static void F_18 ( struct V_1 * V_2 )
{
#if F_19 ( F_13 ) && ! F_19 ( V_21 )
V_2 -> V_4 . V_13 &= ~ V_18 ;
V_2 -> V_4 . V_13 |= V_2 -> V_4 . V_6 -> V_7 & V_18 ;
#endif
}
static inline void F_20 ( struct V_1 * V_2 )
{
#ifdef F_21
if ( F_22 ( V_22 ) ) {
if ( ! ( V_15 -> V_16 . V_17 -> V_7 & V_23 ) ) {
F_23 () ;
F_24 ( & V_2 -> V_4 . V_24 ) ;
V_15 -> V_16 . V_25 = & V_2 -> V_4 . V_24 ;
V_15 -> V_16 . V_17 -> V_7 |= V_23 ;
}
}
#endif
}
static inline void F_25 ( struct V_1 * V_2 )
{
#ifdef F_21
if ( F_22 ( V_22 ) ) {
if ( V_15 -> V_16 . V_17 -> V_7 & V_23 )
F_26 ( V_15 ) ;
V_15 -> V_16 . V_25 = NULL ;
}
#endif
}
static void F_27 ( struct V_1 * V_2 )
{
#ifndef V_21
V_2 -> V_4 . V_13 &= ~ V_26 ;
V_2 -> V_4 . V_13 |= V_2 -> V_4 . V_6 -> V_7 & V_26 ;
#endif
if ( V_2 -> V_27 ) {
#ifdef V_21
V_2 -> V_4 . V_6 -> V_7 |= V_26 ;
#else
V_2 -> V_4 . V_13 |= V_26 ;
V_2 -> V_4 . V_6 -> V_7 &= ~ V_26 ;
#endif
}
}
void F_28 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_29 = V_2 -> V_4 . V_6 -> V_7 ;
#ifdef V_21
V_28 |= V_30 ;
#endif
V_2 -> V_4 . V_6 -> V_7 = V_28 ;
F_29 ( V_2 , V_29 ) ;
F_11 ( V_2 ) ;
F_18 ( V_2 ) ;
F_27 ( V_2 ) ;
}
static void F_30 ( struct V_1 * V_2 ,
unsigned int V_31 )
{
F_31 ( V_2 , V_31 ) ;
F_32 ( V_31 , & V_2 -> V_4 . V_12 ) ;
}
void F_33 ( struct V_1 * V_2 ,
T_2 V_32 , T_2 V_33 )
{
V_2 -> V_4 . V_34 = V_32 ;
V_2 -> V_4 . V_35 = V_33 ;
F_30 ( V_2 , V_36 ) ;
}
void F_34 ( struct V_1 * V_2 ,
T_2 V_32 , T_2 V_33 )
{
V_2 -> V_4 . V_34 = V_32 ;
V_2 -> V_4 . V_35 = V_33 ;
F_30 ( V_2 , V_37 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_38 ) ;
}
void F_36 ( struct V_1 * V_2 , T_2 V_33 )
{
V_2 -> V_4 . V_35 = V_33 ;
F_30 ( V_2 , V_39 ) ;
}
static void F_37 ( struct V_1 * V_2 , T_2 V_32 ,
T_2 V_33 )
{
V_2 -> V_4 . V_34 = V_32 ;
V_2 -> V_4 . V_35 = V_33 ;
F_30 ( V_2 , V_40 ) ;
}
void F_38 ( struct V_1 * V_2 , T_2 V_33 )
{
V_2 -> V_4 . V_35 = V_33 ;
F_30 ( V_2 , V_41 ) ;
}
void F_39 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_42 ) ;
}
int F_40 ( struct V_1 * V_2 )
{
return F_41 ( V_42 , & V_2 -> V_4 . V_12 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
F_43 ( V_42 , & V_2 -> V_4 . V_12 ) ;
}
void F_44 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
unsigned int V_45 = V_46 ;
if ( V_44 -> V_44 == V_47 )
V_45 = V_48 ;
F_30 ( V_2 , V_45 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
F_43 ( V_46 , & V_2 -> V_4 . V_12 ) ;
F_43 ( V_48 , & V_2 -> V_4 . V_12 ) ;
}
static void F_46 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_49 ) ;
}
static void F_47 ( struct V_1 * V_2 )
{
F_43 ( V_49 , & V_2 -> V_4 . V_12 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
F_30 ( V_2 , V_50 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
F_43 ( V_50 , & V_2 -> V_4 . V_12 ) ;
}
static void F_50 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
F_51 ( V_2 , V_10 ) ;
F_52 ( V_2 , V_11 ) ;
}
static void F_53 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_51 = V_10 ;
V_2 -> V_4 . V_52 = V_11 ;
}
static void F_54 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
if ( F_22 ( V_53 ) ) {
V_2 -> V_4 . V_54 = V_10 ;
V_2 -> V_4 . V_55 = V_11 ;
} else {
F_53 ( V_2 , V_10 , V_11 ) ;
}
}
static void F_55 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_56 = V_10 ;
V_2 -> V_4 . V_57 = V_11 ;
}
static int F_56 ( struct V_1 * V_2 ,
unsigned int V_31 )
{
int V_58 = 0 ;
T_2 V_59 = 0 ;
bool V_60 = false , V_61 = false , V_62 = false ;
T_2 V_63 = V_2 -> V_4 . V_6 -> V_64 ;
T_2 V_65 = F_3 ( V_2 , 1 ) ;
bool V_66 ;
bool V_67 = false ;
enum V_68 V_68 ;
T_2 V_28 = V_2 -> V_4 . V_6 -> V_7 ;
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_69 ) ) {
V_63 &= 0xffffffff ;
V_65 &= 0xffffffff ;
}
V_66 = ( V_63 == V_65 ) ;
V_66 = V_66 && ! ( V_2 -> V_4 . V_6 -> V_7 & V_70 ) ;
if ( V_31 == V_48 ) {
V_31 = V_46 ;
V_67 = true ;
}
if ( ( V_31 == V_46 ) && V_2 -> V_4 . V_71 )
V_62 = true ;
switch ( V_31 ) {
case V_36 :
case V_37 :
case V_40 :
V_61 = true ;
case V_39 :
case V_41 :
V_60 = true ;
case V_38 :
case V_72 :
case V_73 :
#ifdef F_57
case V_74 :
case V_75 :
case V_76 :
#endif
#ifdef F_21
case V_77 :
case V_78 :
#endif
case V_79 :
V_58 = 1 ;
V_59 = V_80 | V_81 | V_26 ;
V_68 = V_82 ;
break;
case V_49 :
case V_83 :
case V_84 :
V_58 = V_2 -> V_4 . V_6 -> V_7 & V_80 ;
V_58 = V_58 && ! V_66 ;
V_59 = V_81 ;
V_68 = V_85 ;
break;
case V_86 :
V_58 = V_2 -> V_4 . V_6 -> V_7 & V_81 ;
V_58 = V_58 && ! V_66 ;
V_68 = V_87 ;
break;
case V_42 :
case V_88 :
V_67 = true ;
case V_46 :
case V_89 :
V_58 = V_2 -> V_4 . V_6 -> V_7 & V_90 ;
V_58 = V_58 && ! V_66 ;
V_59 = V_80 | V_81 | V_26 ;
V_68 = V_82 ;
break;
case V_50 :
V_58 = V_2 -> V_4 . V_6 -> V_7 & V_26 ;
V_58 = V_58 && ! V_66 ;
V_59 = V_81 ;
if ( F_22 ( V_53 ) )
V_68 = V_91 ;
else
V_68 = V_85 ;
break;
}
if ( V_58 ) {
switch ( V_68 ) {
case V_82 :
F_50 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_85 :
F_53 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_91 :
F_54 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_87 :
F_55 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
}
V_2 -> V_4 . V_5 = V_2 -> V_4 . V_92 | V_2 -> V_4 . V_93 [ V_31 ] ;
if ( V_60 == true )
F_58 ( V_2 , V_2 -> V_4 . V_35 ) ;
if ( V_61 == true )
F_59 ( V_2 , V_2 -> V_4 . V_34 ) ;
if ( V_62 == true ) {
if ( V_2 -> V_4 . V_71 & V_94 )
F_60 ( V_95 , V_2 ) ;
else if ( V_2 -> V_4 . V_71 & V_96 ) {
F_61 ( V_2 -> V_4 . V_97 != V_98 ) ;
F_62 ( V_2 ) ;
}
}
V_28 &= V_59 ;
#if F_19 ( V_99 )
if ( V_2 -> V_4 . V_100 & V_101 )
V_28 |= V_102 ;
#endif
F_28 ( V_2 , V_28 ) ;
if ( ! V_67 )
F_43 ( V_31 , & V_2 -> V_4 . V_12 ) ;
}
#ifdef V_21
if ( V_2 -> V_4 . V_12 & V_103 )
F_63 ( V_2 , V_82 ) ;
if ( V_2 -> V_4 . V_12 & V_104 )
F_63 ( V_2 , V_85 ) ;
if ( V_2 -> V_4 . V_12 & V_86 )
F_63 ( V_2 , V_87 ) ;
#endif
return V_58 ;
}
static unsigned long F_64 ( struct V_1 * V_2 )
{
T_3 V_105 , V_106 , V_107 = 0 ;
T_3 V_108 = 0 ;
T_1 V_109 = F_65 ( V_2 -> V_4 . V_110 ) ;
V_106 = 1ULL << ( 63 - V_109 ) ;
V_105 = F_66 () ;
if ( V_105 & V_106 )
V_107 = V_106 ;
V_107 += V_106 - ( V_105 & ( V_106 - 1 ) ) ;
V_108 = V_107 ;
if ( F_67 ( V_108 , V_111 ) )
V_108 ++ ;
return F_68 (unsigned long long, nr_jiffies, NEXT_TIMER_MAX_DELTA) ;
}
static void F_69 ( struct V_1 * V_2 )
{
unsigned long V_108 ;
unsigned long V_112 ;
if ( ( V_2 -> V_4 . V_113 & ( V_114 | V_115 ) ) != ( V_114 | V_115 ) )
F_43 ( V_116 , & V_2 -> V_117 ) ;
F_70 ( & V_2 -> V_4 . V_118 , V_112 ) ;
V_108 = F_64 ( V_2 ) ;
if ( V_108 < V_119 )
F_71 ( & V_2 -> V_4 . V_120 , V_121 + V_108 ) ;
else
F_72 ( & V_2 -> V_4 . V_120 ) ;
F_73 ( & V_2 -> V_4 . V_118 , V_112 ) ;
}
void F_74 ( unsigned long V_122 )
{
struct V_1 * V_2 = (struct V_1 * ) V_122 ;
T_1 V_113 , V_123 ;
int V_124 ;
do {
V_123 = V_113 = V_2 -> V_4 . V_113 ;
V_124 = 0 ;
if ( V_113 & V_114 ) {
if ( V_113 & V_115 )
V_124 = 1 ;
else
V_123 = V_113 | V_115 ;
} else {
V_123 = V_113 | V_114 ;
}
} while ( F_75 ( & V_2 -> V_4 . V_113 , V_113 , V_123 ) != V_113 );
if ( V_123 & V_115 ) {
F_76 () ;
F_60 ( V_125 , V_2 ) ;
F_77 ( V_2 ) ;
}
if ( V_124 && ( V_2 -> V_4 . V_110 & V_126 ) &&
V_2 -> V_4 . V_127 ) {
F_76 () ;
F_60 ( V_116 , V_2 ) ;
F_77 ( V_2 ) ;
}
if ( ! V_124 )
F_69 ( V_2 ) ;
}
static void F_78 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 . V_110 & V_128 ) && ( V_2 -> V_4 . V_113 & V_129 ) )
F_39 ( V_2 ) ;
else
F_42 ( V_2 ) ;
if ( ( V_2 -> V_4 . V_110 & V_130 ) && ( V_2 -> V_4 . V_113 & V_115 ) )
F_46 ( V_2 ) ;
else
F_47 ( V_2 ) ;
}
static void F_79 ( struct V_1 * V_2 )
{
unsigned long * V_131 = & V_2 -> V_4 . V_12 ;
unsigned int V_31 ;
V_31 = F_80 ( * V_131 ) ;
while ( V_31 < V_132 ) {
if ( F_56 ( V_2 , V_31 ) )
break;
V_31 = F_81 ( V_131 ,
V_133 * sizeof( * V_131 ) ,
V_31 + 1 ) ;
}
V_2 -> V_4 . V_6 -> V_134 = ! ! * V_131 ;
}
int F_82 ( struct V_1 * V_2 )
{
int V_135 = 0 ;
F_83 ( ! F_84 () ) ;
F_79 ( V_2 ) ;
if ( V_2 -> V_117 ) {
return 1 ;
}
if ( V_2 -> V_4 . V_6 -> V_7 & V_136 ) {
F_85 () ;
F_86 ( V_2 ) ;
F_43 ( V_137 , & V_2 -> V_117 ) ;
F_87 () ;
F_88 ( V_2 , V_138 ) ;
V_135 = 1 ;
} ;
return V_135 ;
}
int F_89 ( struct V_1 * V_2 )
{
int V_135 = 1 ;
if ( F_90 ( V_125 , V_2 ) )
F_78 ( V_2 ) ;
#if F_19 ( V_139 ) || F_19 ( V_140 )
if ( F_90 ( V_141 , V_2 ) )
F_91 ( V_2 ) ;
#endif
if ( F_90 ( V_116 , V_2 ) ) {
V_2 -> V_142 -> V_143 = V_144 ;
V_135 = 0 ;
}
if ( F_90 ( V_95 , V_2 ) ) {
V_2 -> V_142 -> V_145 . V_145 = 0 ;
V_2 -> V_4 . V_146 = true ;
V_2 -> V_142 -> V_143 = V_147 ;
V_135 = 0 ;
}
return V_135 ;
}
int F_92 ( struct V_148 * V_148 , struct V_1 * V_2 )
{
int V_149 , V_150 ;
struct V_151 V_152 ;
if ( ! V_2 -> V_4 . V_153 ) {
V_148 -> V_143 = V_154 ;
return - V_155 ;
}
V_150 = F_93 ( V_2 ) ;
if ( V_150 <= 0 ) {
V_149 = V_150 ;
goto V_156;
}
#ifdef F_13
F_14 () ;
F_12 ( V_2 ) ;
#endif
#ifdef F_21
if ( F_22 ( V_22 ) )
F_23 () ;
F_20 ( V_2 ) ;
#endif
V_152 = V_2 -> V_4 . V_157 ;
F_94 ( & V_152 ) ;
V_152 = V_15 -> V_16 . V_152 ;
V_15 -> V_16 . V_152 = V_2 -> V_4 . V_157 ;
V_2 -> V_4 . V_158 = V_15 -> V_159 -> V_160 ;
F_95 () ;
V_149 = F_96 ( V_148 , V_2 ) ;
F_94 ( & V_152 ) ;
V_15 -> V_16 . V_152 = V_152 ;
#ifdef F_13
F_16 ( V_2 ) ;
#endif
#ifdef F_21
F_25 ( V_2 ) ;
#endif
V_156:
V_2 -> V_161 = V_162 ;
return V_149 ;
}
static int F_97 ( struct V_148 * V_142 , struct V_1 * V_2 )
{
enum V_163 V_164 ;
V_164 = F_98 ( V_142 , V_2 ) ;
switch ( V_164 ) {
case V_165 :
F_99 ( V_2 , V_166 ) ;
return V_167 ;
case V_168 :
return V_169 ;
case V_170 :
F_2 ( V_171 L_6 ,
V_172 , V_2 -> V_4 . V_5 , V_2 -> V_4 . V_173 ) ;
V_142 -> V_174 . V_175 = ~ 0ULL << 32 ;
V_142 -> V_174 . V_175 |= V_2 -> V_4 . V_173 ;
F_38 ( V_2 , V_176 ) ;
return V_177 ;
case V_178 :
return V_177 ;
default:
F_100 () ;
}
}
static int F_101 ( struct V_148 * V_142 , struct V_1 * V_2 )
{
struct V_151 * V_157 = & ( V_2 -> V_4 . V_157 ) ;
T_1 V_179 = V_2 -> V_4 . V_179 ;
if ( V_2 -> V_27 == 0 ) {
if ( V_179 & V_180 ) {
V_179 &= ~ V_180 ;
if ( ! V_179 )
return V_169 ;
}
if ( V_179 && ( V_2 -> V_4 . V_6 -> V_7 & V_26 ) &&
( V_2 -> V_4 . V_157 . V_181 & V_182 ) )
F_48 ( V_2 ) ;
if ( ( V_179 & V_183 ) && ! ( V_2 -> V_4 . V_6 -> V_7 & V_26 ) )
F_38 ( V_2 , V_184 ) ;
return V_169 ;
}
V_2 -> V_4 . V_179 = 0 ;
V_142 -> V_152 . V_4 . V_185 = 0 ;
V_142 -> V_152 . V_4 . V_186 = V_2 -> V_4 . V_5 ;
if ( V_179 & ( V_187 | V_188 | V_189 | V_190 ) ) {
V_142 -> V_152 . V_4 . V_185 |= V_191 ;
} else {
if ( V_179 & ( V_192 | V_193 ) )
V_142 -> V_152 . V_4 . V_185 |= V_194 ;
else if ( V_179 & ( V_195 | V_196 ) )
V_142 -> V_152 . V_4 . V_185 |= V_197 ;
if ( V_179 & ( V_195 | V_192 ) )
V_142 -> V_152 . V_4 . V_186 = V_157 -> V_198 ;
else if ( V_179 & ( V_196 | V_193 ) )
V_142 -> V_152 . V_4 . V_186 = V_157 -> V_199 ;
}
return V_177 ;
}
static void F_102 ( struct V_200 * V_17 )
{
T_2 V_201 , V_202 , V_7 , V_8 ;
asm("mr %0, 1" : "=r"(r1));
asm("mflr %0" : "=r"(lr));
asm("mfmsr %0" : "=r"(msr));
asm("bl 1f; 1: mflr %0" : "=r"(ip));
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
V_17 -> V_203 [ 1 ] = V_201 ;
V_17 -> V_204 = V_202 ;
V_17 -> V_7 = V_7 ;
V_17 -> V_205 = V_8 ;
}
static void F_103 ( struct V_1 * V_2 ,
unsigned int V_206 )
{
struct V_200 V_17 ;
switch ( V_206 ) {
case V_207 :
F_102 ( & V_17 ) ;
F_104 ( & V_17 ) ;
break;
case V_208 :
F_102 ( & V_17 ) ;
F_105 ( & V_17 ) ;
break;
#if F_19 ( V_209 )
case V_210 :
F_102 ( & V_17 ) ;
F_106 ( & V_17 ) ;
break;
#endif
case V_211 :
break;
case V_212 :
F_102 ( & V_17 ) ;
F_107 ( & V_17 ) ;
break;
case V_213 :
F_102 ( & V_17 ) ;
#ifdef F_108
F_109 ( & V_17 ) ;
#else
F_110 ( & V_17 ) ;
#endif
break;
case V_214 :
F_110 ( & V_17 ) ;
break;
case V_215 :
V_2 -> V_4 . V_179 = F_111 ( V_216 ) ;
F_112 () ;
break;
}
}
static int F_113 ( struct V_148 * V_142 , struct V_1 * V_2 ,
enum V_163 V_217 , T_1 V_173 )
{
switch ( V_217 ) {
case V_168 :
return V_169 ;
case V_170 :
F_114 ( L_7 ,
V_172 , V_2 -> V_4 . V_5 ) ;
V_142 -> V_174 . V_175 = ~ 0ULL << 32 ;
V_142 -> V_174 . V_175 |= V_173 ;
F_38 ( V_2 , V_176 ) ;
return V_177 ;
default:
F_100 () ;
}
}
int F_115 ( struct V_148 * V_142 , struct V_1 * V_2 ,
unsigned int V_206 )
{
int V_135 = V_177 ;
int V_150 ;
int V_218 ;
T_1 V_173 = V_219 ;
enum V_163 V_217 = V_165 ;
F_116 ( V_2 ) ;
F_103 ( V_2 , V_206 ) ;
switch ( V_206 ) {
case V_220 :
case V_221 :
case V_222 :
V_217 = F_117 ( V_2 , V_223 , & V_173 ) ;
break;
case V_224 :
if ( V_2 -> V_27 & V_225 )
V_217 = F_117 ( V_2 , V_223 , & V_173 ) ;
break;
default:
break;
}
F_85 () ;
F_118 ( V_206 , V_2 ) ;
F_119 () ;
V_142 -> V_143 = V_226 ;
V_142 -> V_227 = 1 ;
if ( V_217 != V_165 ) {
V_135 = F_113 ( V_142 , V_2 , V_217 , V_173 ) ;
goto V_156;
}
switch ( V_206 ) {
case V_211 :
F_2 ( L_8 , F_111 ( V_228 ) ) ;
F_1 ( V_2 ) ;
V_142 -> V_174 . V_175 = ~ 1ULL << 32 ;
V_142 -> V_174 . V_175 |= F_111 ( V_228 ) ;
V_135 = V_177 ;
break;
case V_207 :
F_120 ( V_2 , V_229 ) ;
V_135 = V_169 ;
break;
case V_208 :
F_120 ( V_2 , V_230 ) ;
V_135 = V_169 ;
break;
case V_213 :
V_135 = V_169 ;
break;
case V_210 :
F_120 ( V_2 , V_231 ) ;
V_135 = V_169 ;
break;
case V_232 :
F_120 ( V_2 , V_233 ) ;
V_135 = V_169 ;
break;
case V_234 :
F_120 ( V_2 , V_233 ) ;
V_135 = V_169 ;
break;
case V_212 :
V_135 = V_169 ;
break;
case V_222 :
V_135 = F_97 ( V_142 , V_2 ) ;
break;
case V_224 :
if ( ( V_2 -> V_27 & V_225 ) &&
( V_173 == V_235 ) ) {
V_135 = F_101 ( V_142 , V_2 ) ;
V_142 -> V_143 = V_236 ;
F_120 ( V_2 , V_237 ) ;
break;
}
if ( V_2 -> V_4 . V_6 -> V_7 & ( V_70 | V_30 ) ) {
F_38 ( V_2 , V_2 -> V_4 . V_238 ) ;
V_135 = V_169 ;
F_120 ( V_2 , V_239 ) ;
break;
}
V_135 = F_97 ( V_142 , V_2 ) ;
break;
case V_240 :
F_30 ( V_2 , V_73 ) ;
F_120 ( V_2 , V_241 ) ;
V_135 = V_169 ;
break;
#ifdef F_121
case V_242 : {
if ( V_2 -> V_4 . V_6 -> V_7 & V_14 )
F_9 ( V_2 ) ;
else
F_30 ( V_2 ,
V_74 ) ;
V_135 = V_169 ;
break;
}
case V_243 :
F_30 ( V_2 , V_75 ) ;
V_135 = V_169 ;
break;
case V_244 :
F_30 ( V_2 , V_76 ) ;
V_135 = V_169 ;
break;
#elif F_19 ( F_57 )
case V_242 :
F_38 ( V_2 , V_245 | V_246 ) ;
V_135 = V_169 ;
break;
case V_243 :
case V_244 :
F_2 ( V_171 L_9 ,
V_172 , V_206 , V_2 -> V_4 . V_5 ) ;
V_142 -> V_174 . V_175 = V_206 ;
V_135 = V_177 ;
break;
#endif
#ifdef F_21
case V_247 :
F_30 ( V_2 , V_77 ) ;
V_135 = V_169 ;
break;
case V_248 :
F_30 ( V_2 , V_78 ) ;
V_135 = V_169 ;
break;
#endif
case V_220 :
F_34 ( V_2 , V_2 -> V_4 . V_249 ,
V_2 -> V_4 . V_238 ) ;
F_120 ( V_2 , V_250 ) ;
V_135 = V_169 ;
break;
case V_251 :
F_36 ( V_2 , V_2 -> V_4 . V_238 ) ;
F_120 ( V_2 , V_252 ) ;
V_135 = V_169 ;
break;
case V_253 :
F_37 ( V_2 , V_2 -> V_4 . V_249 ,
V_2 -> V_4 . V_238 ) ;
V_135 = V_169 ;
break;
#ifdef V_21
case V_254 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_70 ) ) {
F_122 ( V_2 , 3 , F_123 ( V_2 ) ) ;
} else {
F_38 ( V_2 , V_255 ) ;
}
V_135 = V_169 ;
break;
#else
case V_256 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_70 ) &&
( ( ( T_1 ) F_3 ( V_2 , 0 ) ) == V_257 ) ) {
F_122 ( V_2 , 3 , F_123 ( V_2 ) ) ;
V_135 = V_169 ;
} else {
F_30 ( V_2 , V_72 ) ;
}
F_120 ( V_2 , V_258 ) ;
V_135 = V_169 ;
break;
#endif
case V_221 : {
unsigned long V_259 = V_2 -> V_4 . V_249 ;
int V_260 ;
T_4 V_261 ;
T_5 V_262 ;
#ifdef V_139
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_70 ) &&
( V_259 & V_263 ) == V_2 -> V_4 . V_264 ) {
F_124 ( V_2 ) ;
F_120 ( V_2 , V_265 ) ;
V_135 = V_169 ;
break;
}
#endif
V_260 = F_125 ( V_2 , V_259 ) ;
if ( V_260 < 0 ) {
F_33 ( V_2 ,
V_2 -> V_4 . V_249 ,
V_2 -> V_4 . V_238 ) ;
F_126 ( V_2 ) ;
F_120 ( V_2 , V_266 ) ;
V_135 = V_169 ;
break;
}
V_218 = F_127 ( & V_2 -> V_267 -> V_268 ) ;
V_261 = F_128 ( V_2 , V_260 , V_259 ) ;
V_262 = V_261 >> V_269 ;
if ( F_129 ( V_2 -> V_267 , V_262 ) ) {
F_130 ( V_2 , V_259 , V_261 , V_260 ) ;
F_120 ( V_2 , V_265 ) ;
V_135 = V_169 ;
} else {
V_2 -> V_4 . V_270 = V_261 ;
V_2 -> V_4 . V_271 = V_259 ;
V_135 = F_131 ( V_142 , V_2 ) ;
F_120 ( V_2 , V_272 ) ;
}
F_132 ( & V_2 -> V_267 -> V_268 , V_218 ) ;
break;
}
case V_273 : {
unsigned long V_259 = V_2 -> V_4 . V_5 ;
T_4 V_261 ;
T_5 V_262 ;
int V_260 ;
V_135 = V_169 ;
V_260 = F_133 ( V_2 , V_259 ) ;
if ( V_260 < 0 ) {
F_30 ( V_2 , V_38 ) ;
F_134 ( V_2 ) ;
F_120 ( V_2 , V_274 ) ;
break;
}
F_120 ( V_2 , V_275 ) ;
V_218 = F_127 ( & V_2 -> V_267 -> V_268 ) ;
V_261 = F_128 ( V_2 , V_260 , V_259 ) ;
V_262 = V_261 >> V_269 ;
if ( F_129 ( V_2 -> V_267 , V_262 ) ) {
F_130 ( V_2 , V_259 , V_261 , V_260 ) ;
} else {
F_30 ( V_2 , V_86 ) ;
}
F_132 ( & V_2 -> V_267 -> V_268 , V_218 ) ;
break;
}
case V_215 : {
V_135 = F_101 ( V_142 , V_2 ) ;
if ( V_135 == V_177 )
V_142 -> V_143 = V_236 ;
F_120 ( V_2 , V_237 ) ;
break;
}
default:
F_2 ( V_276 L_10 , V_206 ) ;
F_100 () ;
}
V_156:
if ( ! ( V_135 & V_177 ) ) {
V_150 = F_93 ( V_2 ) ;
if ( V_150 <= 0 )
V_135 = ( V_150 << 2 ) | V_177 | ( V_135 & V_277 ) ;
else {
F_95 () ;
F_12 ( V_2 ) ;
F_20 ( V_2 ) ;
}
}
return V_135 ;
}
static void F_135 ( struct V_1 * V_2 , T_1 V_123 )
{
T_1 V_278 = V_2 -> V_4 . V_113 ;
V_2 -> V_4 . V_113 = V_123 ;
if ( ( V_278 ^ V_2 -> V_4 . V_113 ) & ( V_114 | V_115 ) )
F_69 ( V_2 ) ;
F_78 ( V_2 ) ;
}
int F_136 ( struct V_1 * V_2 )
{
int V_3 ;
int V_135 ;
V_2 -> V_4 . V_5 = 0 ;
V_2 -> V_4 . V_6 -> V_279 = V_2 -> V_280 ;
F_122 ( V_2 , 1 , ( 16 << 20 ) - 8 ) ;
F_28 ( V_2 , 0 ) ;
#ifndef V_21
V_2 -> V_4 . V_13 = V_281 | V_282 | V_283 ;
V_2 -> V_4 . V_284 = 1 ;
V_2 -> V_4 . V_6 -> V_7 = 0 ;
#endif
V_2 -> V_4 . V_92 = 0x55550000 ;
for ( V_3 = 0 ; V_3 < V_132 ; V_3 ++ )
V_2 -> V_4 . V_93 [ V_3 ] = 0x7700 | V_3 * 4 ;
F_137 ( V_2 ) ;
V_135 = F_138 ( V_2 ) ;
F_139 ( V_2 ) ;
return V_135 ;
}
int F_140 ( struct V_1 * V_2 )
{
F_141 ( & V_2 -> V_4 . V_118 ) ;
F_142 ( & V_2 -> V_4 . V_120 , F_74 ,
( unsigned long ) V_2 ) ;
F_143 ( V_216 , V_285 ) ;
return 0 ;
}
void F_144 ( struct V_1 * V_2 )
{
F_145 ( & V_2 -> V_4 . V_120 ) ;
}
int F_146 ( struct V_1 * V_2 , struct V_286 * V_17 )
{
int V_3 ;
V_17 -> V_5 = V_2 -> V_4 . V_5 ;
V_17 -> V_287 = F_147 ( V_2 ) ;
V_17 -> V_9 = V_2 -> V_4 . V_9 ;
V_17 -> V_8 = V_2 -> V_4 . V_8 ;
V_17 -> V_288 = F_148 ( V_2 ) ;
V_17 -> V_7 = V_2 -> V_4 . V_6 -> V_7 ;
V_17 -> V_10 = F_149 ( V_2 ) ;
V_17 -> V_11 = F_150 ( V_2 ) ;
V_17 -> V_289 = V_2 -> V_4 . V_289 ;
V_17 -> V_290 = F_151 ( V_2 ) ;
V_17 -> V_291 = F_152 ( V_2 ) ;
V_17 -> V_292 = F_153 ( V_2 ) ;
V_17 -> V_293 = F_154 ( V_2 ) ;
V_17 -> V_294 = F_155 ( V_2 ) ;
V_17 -> V_295 = F_156 ( V_2 ) ;
V_17 -> V_296 = F_157 ( V_2 ) ;
V_17 -> V_297 = F_158 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < F_159 ( V_17 -> V_203 ) ; V_3 ++ )
V_17 -> V_203 [ V_3 ] = F_3 ( V_2 , V_3 ) ;
return 0 ;
}
int F_160 ( struct V_1 * V_2 , struct V_286 * V_17 )
{
int V_3 ;
V_2 -> V_4 . V_5 = V_17 -> V_5 ;
F_161 ( V_2 , V_17 -> V_287 ) ;
V_2 -> V_4 . V_9 = V_17 -> V_9 ;
V_2 -> V_4 . V_8 = V_17 -> V_8 ;
F_162 ( V_2 , V_17 -> V_288 ) ;
F_28 ( V_2 , V_17 -> V_7 ) ;
F_51 ( V_2 , V_17 -> V_10 ) ;
F_52 ( V_2 , V_17 -> V_11 ) ;
F_163 ( V_2 , V_17 -> V_289 ) ;
F_164 ( V_2 , V_17 -> V_290 ) ;
F_165 ( V_2 , V_17 -> V_291 ) ;
F_166 ( V_2 , V_17 -> V_292 ) ;
F_167 ( V_2 , V_17 -> V_293 ) ;
F_168 ( V_2 , V_17 -> V_294 ) ;
F_169 ( V_2 , V_17 -> V_295 ) ;
F_170 ( V_2 , V_17 -> V_296 ) ;
F_171 ( V_2 , V_17 -> V_297 ) ;
for ( V_3 = 0 ; V_3 < F_159 ( V_17 -> V_203 ) ; V_3 ++ )
F_122 ( V_2 , V_3 , V_17 -> V_203 [ V_3 ] ) ;
return 0 ;
}
static void F_172 ( struct V_1 * V_2 ,
struct V_298 * V_299 )
{
T_3 V_105 = F_66 () ;
V_299 -> V_300 . V_301 . V_302 |= V_303 ;
V_299 -> V_300 . V_301 . V_51 = V_2 -> V_4 . V_51 ;
V_299 -> V_300 . V_301 . V_52 = V_2 -> V_4 . V_52 ;
V_299 -> V_300 . V_301 . V_304 = V_2 -> V_4 . V_304 ;
V_299 -> V_300 . V_301 . V_305 = F_173 ( V_2 ) ;
V_299 -> V_300 . V_301 . V_306 = F_174 ( V_2 ) ;
V_299 -> V_300 . V_301 . V_113 = V_2 -> V_4 . V_113 ;
V_299 -> V_300 . V_301 . V_110 = V_2 -> V_4 . V_110 ;
V_299 -> V_300 . V_301 . V_307 = F_175 ( V_2 , V_105 ) ;
V_299 -> V_300 . V_301 . V_105 = V_105 ;
V_299 -> V_300 . V_301 . V_308 = V_2 -> V_4 . V_308 ;
}
static int F_176 ( struct V_1 * V_2 ,
struct V_298 * V_299 )
{
if ( ! ( V_299 -> V_300 . V_301 . V_302 & V_303 ) )
return 0 ;
V_2 -> V_4 . V_51 = V_299 -> V_300 . V_301 . V_51 ;
V_2 -> V_4 . V_52 = V_299 -> V_300 . V_301 . V_52 ;
V_2 -> V_4 . V_304 = V_299 -> V_300 . V_301 . V_304 ;
F_58 ( V_2 , V_299 -> V_300 . V_301 . V_305 ) ;
F_59 ( V_2 , V_299 -> V_300 . V_301 . V_306 ) ;
V_2 -> V_4 . V_308 = V_299 -> V_300 . V_301 . V_308 ;
F_177 ( V_2 , V_299 -> V_300 . V_301 . V_110 ) ;
if ( V_299 -> V_300 . V_301 . V_309 & V_310 ) {
V_2 -> V_4 . V_307 = V_299 -> V_300 . V_301 . V_307 ;
F_178 ( V_2 ) ;
}
if ( V_299 -> V_300 . V_301 . V_309 & V_311 )
F_135 ( V_2 , V_299 -> V_300 . V_301 . V_113 ) ;
return 0 ;
}
static void F_179 ( struct V_1 * V_2 ,
struct V_298 * V_299 )
{
V_299 -> V_300 . V_301 . V_302 |= V_312 ;
V_299 -> V_300 . V_301 . V_279 = V_2 -> V_280 ;
V_299 -> V_300 . V_301 . V_56 = V_2 -> V_4 . V_56 ;
V_299 -> V_300 . V_301 . V_57 = V_2 -> V_4 . V_57 ;
V_299 -> V_300 . V_301 . V_313 = V_2 -> V_4 . V_313 ;
V_299 -> V_300 . V_301 . V_92 = V_2 -> V_4 . V_92 ;
}
static int F_180 ( struct V_1 * V_2 ,
struct V_298 * V_299 )
{
if ( ! ( V_299 -> V_300 . V_301 . V_302 & V_312 ) )
return 0 ;
if ( V_299 -> V_300 . V_301 . V_279 != V_2 -> V_280 )
return - V_155 ;
V_2 -> V_4 . V_56 = V_299 -> V_300 . V_301 . V_56 ;
V_2 -> V_4 . V_57 = V_299 -> V_300 . V_301 . V_57 ;
V_2 -> V_4 . V_313 = V_299 -> V_300 . V_301 . V_313 ;
V_2 -> V_4 . V_92 = V_299 -> V_300 . V_301 . V_92 ;
return 0 ;
}
int F_181 ( struct V_1 * V_2 , struct V_298 * V_299 )
{
V_299 -> V_300 . V_301 . V_302 |= V_314 ;
V_299 -> V_300 . V_301 . V_315 [ 0 ] = V_2 -> V_4 . V_93 [ V_83 ] ;
V_299 -> V_300 . V_301 . V_315 [ 1 ] = V_2 -> V_4 . V_93 [ V_86 ] ;
V_299 -> V_300 . V_301 . V_315 [ 2 ] = V_2 -> V_4 . V_93 [ V_37 ] ;
V_299 -> V_300 . V_301 . V_315 [ 3 ] = V_2 -> V_4 . V_93 [ V_39 ] ;
V_299 -> V_300 . V_301 . V_315 [ 4 ] = V_2 -> V_4 . V_93 [ V_46 ] ;
V_299 -> V_300 . V_301 . V_315 [ 5 ] = V_2 -> V_4 . V_93 [ V_40 ] ;
V_299 -> V_300 . V_301 . V_315 [ 6 ] = V_2 -> V_4 . V_93 [ V_41 ] ;
V_299 -> V_300 . V_301 . V_315 [ 7 ] = V_2 -> V_4 . V_93 [ V_73 ] ;
V_299 -> V_300 . V_301 . V_315 [ 8 ] = V_2 -> V_4 . V_93 [ V_72 ] ;
V_299 -> V_300 . V_301 . V_315 [ 9 ] = V_2 -> V_4 . V_93 [ V_79 ] ;
V_299 -> V_300 . V_301 . V_315 [ 10 ] = V_2 -> V_4 . V_93 [ V_42 ] ;
V_299 -> V_300 . V_301 . V_315 [ 11 ] = V_2 -> V_4 . V_93 [ V_88 ] ;
V_299 -> V_300 . V_301 . V_315 [ 12 ] = V_2 -> V_4 . V_93 [ V_49 ] ;
V_299 -> V_300 . V_301 . V_315 [ 13 ] = V_2 -> V_4 . V_93 [ V_36 ] ;
V_299 -> V_300 . V_301 . V_315 [ 14 ] = V_2 -> V_4 . V_93 [ V_38 ] ;
V_299 -> V_300 . V_301 . V_315 [ 15 ] = V_2 -> V_4 . V_93 [ V_50 ] ;
return 0 ;
}
int F_182 ( struct V_1 * V_2 , struct V_298 * V_299 )
{
if ( ! ( V_299 -> V_300 . V_301 . V_302 & V_314 ) )
return 0 ;
V_2 -> V_4 . V_93 [ V_83 ] = V_299 -> V_300 . V_301 . V_315 [ 0 ] ;
V_2 -> V_4 . V_93 [ V_86 ] = V_299 -> V_300 . V_301 . V_315 [ 1 ] ;
V_2 -> V_4 . V_93 [ V_37 ] = V_299 -> V_300 . V_301 . V_315 [ 2 ] ;
V_2 -> V_4 . V_93 [ V_39 ] = V_299 -> V_300 . V_301 . V_315 [ 3 ] ;
V_2 -> V_4 . V_93 [ V_46 ] = V_299 -> V_300 . V_301 . V_315 [ 4 ] ;
V_2 -> V_4 . V_93 [ V_40 ] = V_299 -> V_300 . V_301 . V_315 [ 5 ] ;
V_2 -> V_4 . V_93 [ V_41 ] = V_299 -> V_300 . V_301 . V_315 [ 6 ] ;
V_2 -> V_4 . V_93 [ V_73 ] = V_299 -> V_300 . V_301 . V_315 [ 7 ] ;
V_2 -> V_4 . V_93 [ V_72 ] = V_299 -> V_300 . V_301 . V_315 [ 8 ] ;
V_2 -> V_4 . V_93 [ V_79 ] = V_299 -> V_300 . V_301 . V_315 [ 9 ] ;
V_2 -> V_4 . V_93 [ V_42 ] = V_299 -> V_300 . V_301 . V_315 [ 10 ] ;
V_2 -> V_4 . V_93 [ V_88 ] = V_299 -> V_300 . V_301 . V_315 [ 11 ] ;
V_2 -> V_4 . V_93 [ V_49 ] = V_299 -> V_300 . V_301 . V_315 [ 12 ] ;
V_2 -> V_4 . V_93 [ V_36 ] = V_299 -> V_300 . V_301 . V_315 [ 13 ] ;
V_2 -> V_4 . V_93 [ V_38 ] = V_299 -> V_300 . V_301 . V_315 [ 14 ] ;
V_2 -> V_4 . V_93 [ V_50 ] = V_299 -> V_300 . V_301 . V_315 [ 15 ] ;
return 0 ;
}
int F_183 ( struct V_1 * V_2 ,
struct V_298 * V_299 )
{
V_299 -> V_316 = V_2 -> V_4 . V_316 ;
F_172 ( V_2 , V_299 ) ;
F_179 ( V_2 , V_299 ) ;
return V_2 -> V_267 -> V_4 . V_317 -> V_318 ( V_2 , V_299 ) ;
}
int F_184 ( struct V_1 * V_2 ,
struct V_298 * V_299 )
{
int V_149 ;
if ( V_2 -> V_4 . V_316 != V_299 -> V_316 )
return - V_155 ;
V_149 = F_176 ( V_2 , V_299 ) ;
if ( V_149 < 0 )
return V_149 ;
V_149 = F_180 ( V_2 , V_299 ) ;
if ( V_149 < 0 )
return V_149 ;
return V_2 -> V_267 -> V_4 . V_317 -> V_319 ( V_2 , V_299 ) ;
}
int F_185 ( struct V_1 * V_2 , T_3 V_320 ,
union V_321 * V_322 )
{
int V_135 = 0 ;
switch ( V_320 ) {
case V_323 :
* V_322 = F_186 ( V_320 , V_2 -> V_4 . V_157 . V_324 ) ;
break;
case V_325 :
* V_322 = F_186 ( V_320 , V_2 -> V_4 . V_157 . V_326 ) ;
break;
#if V_327 > 2
case V_328 :
* V_322 = F_186 ( V_320 , V_2 -> V_4 . V_157 . V_329 ) ;
break;
case V_330 :
* V_322 = F_186 ( V_320 , V_2 -> V_4 . V_157 . V_331 ) ;
break;
#endif
case V_332 :
* V_322 = F_186 ( V_320 , V_2 -> V_4 . V_157 . V_198 ) ;
break;
case V_333 :
* V_322 = F_186 ( V_320 , V_2 -> V_4 . V_157 . V_199 ) ;
break;
case V_334 : {
T_1 V_145 = F_187 ( V_2 ) ;
* V_322 = F_186 ( V_320 , V_145 ) ;
break;
}
#if F_19 ( V_99 )
case V_335 :
* V_322 = F_186 ( V_320 , V_2 -> V_4 . V_100 ) ;
break;
#endif
case V_336 :
* V_322 = F_186 ( V_320 , V_2 -> V_4 . V_110 ) ;
break;
case V_337 :
* V_322 = F_186 ( V_320 , V_2 -> V_4 . V_113 ) ;
break;
case V_338 :
* V_322 = F_186 ( V_320 , V_235 ) ;
break;
case V_339 :
* V_322 = F_186 ( V_320 , V_2 -> V_4 . V_308 ) ;
break;
default:
V_135 = V_2 -> V_267 -> V_4 . V_317 -> V_340 ( V_2 , V_320 , V_322 ) ;
break;
}
return V_135 ;
}
int F_188 ( struct V_1 * V_2 , T_3 V_320 ,
union V_321 * V_322 )
{
int V_135 = 0 ;
switch ( V_320 ) {
case V_323 :
V_2 -> V_4 . V_157 . V_324 = F_189 ( V_320 , * V_322 ) ;
break;
case V_325 :
V_2 -> V_4 . V_157 . V_326 = F_189 ( V_320 , * V_322 ) ;
break;
#if V_327 > 2
case V_328 :
V_2 -> V_4 . V_157 . V_329 = F_189 ( V_320 , * V_322 ) ;
break;
case V_330 :
V_2 -> V_4 . V_157 . V_331 = F_189 ( V_320 , * V_322 ) ;
break;
#endif
case V_332 :
V_2 -> V_4 . V_157 . V_198 = F_189 ( V_320 , * V_322 ) ;
break;
case V_333 :
V_2 -> V_4 . V_157 . V_199 = F_189 ( V_320 , * V_322 ) ;
break;
case V_334 : {
T_1 V_341 = F_189 ( V_320 , * V_322 ) ;
F_190 ( V_2 , V_341 ) ;
break;
}
#if F_19 ( V_99 )
case V_335 : {
T_1 V_342 = F_189 ( V_320 , * V_322 ) ;
F_191 ( V_2 , V_342 ) ;
break;
}
#endif
case V_343 : {
T_1 V_344 = F_189 ( V_320 , * V_322 ) ;
F_192 ( V_2 , V_344 ) ;
break;
}
case V_345 : {
T_1 V_344 = F_189 ( V_320 , * V_322 ) ;
F_193 ( V_2 , V_344 ) ;
break;
}
case V_337 : {
T_1 V_113 = F_189 ( V_320 , * V_322 ) ;
F_135 ( V_2 , V_113 ) ;
break;
}
case V_336 : {
T_1 V_110 = F_189 ( V_320 , * V_322 ) ;
F_177 ( V_2 , V_110 ) ;
break;
}
case V_339 :
V_2 -> V_4 . V_308 = F_189 ( V_320 , * V_322 ) ;
break;
default:
V_135 = V_2 -> V_267 -> V_4 . V_317 -> V_346 ( V_2 , V_320 , V_322 ) ;
break;
}
return V_135 ;
}
int F_194 ( struct V_1 * V_2 , struct V_347 * V_348 )
{
return - V_349 ;
}
int F_195 ( struct V_1 * V_2 , struct V_347 * V_348 )
{
return - V_349 ;
}
int F_196 ( struct V_1 * V_2 ,
struct V_350 * V_351 )
{
int V_135 ;
V_135 = F_197 ( V_2 , V_351 ) ;
return V_135 ;
}
int F_198 ( struct V_267 * V_267 , struct V_352 * log )
{
return - V_349 ;
}
void F_199 ( struct V_267 * V_267 , struct V_353 * free ,
struct V_353 * V_354 )
{
}
int F_200 ( struct V_267 * V_267 , struct V_353 * V_355 ,
unsigned long V_356 )
{
return 0 ;
}
int F_201 ( struct V_267 * V_267 ,
struct V_353 * V_357 ,
struct V_358 * V_359 )
{
return 0 ;
}
void F_202 ( struct V_267 * V_267 ,
struct V_358 * V_359 ,
const struct V_353 * V_360 )
{
}
void F_203 ( struct V_267 * V_267 , struct V_353 * V_357 )
{
}
void F_191 ( struct V_1 * V_2 , T_1 V_342 )
{
#if F_19 ( V_99 )
V_2 -> V_4 . V_100 = V_342 ;
#ifdef V_21
V_2 -> V_4 . V_361 &= ~ V_362 ;
if ( V_2 -> V_4 . V_100 & V_101 )
V_2 -> V_4 . V_361 |= V_362 ;
#endif
#endif
}
void F_177 ( struct V_1 * V_2 , T_1 V_363 )
{
V_2 -> V_4 . V_110 = V_363 ;
F_69 ( V_2 ) ;
F_78 ( V_2 ) ;
}
void F_192 ( struct V_1 * V_2 , T_1 V_344 )
{
F_204 ( V_344 , & V_2 -> V_4 . V_113 ) ;
F_76 () ;
F_60 ( V_125 , V_2 ) ;
F_77 ( V_2 ) ;
}
void F_193 ( struct V_1 * V_2 , T_1 V_344 )
{
F_205 ( V_344 , & V_2 -> V_4 . V_113 ) ;
if ( V_344 & ( V_114 | V_115 ) )
F_69 ( V_2 ) ;
F_78 ( V_2 ) ;
}
void F_206 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_110 & V_364 ) {
V_2 -> V_4 . V_307 = V_2 -> V_4 . V_313 ;
F_178 ( V_2 ) ;
}
F_192 ( V_2 , V_129 ) ;
}
static int F_207 ( struct V_151 * V_157 ,
T_6 V_365 , int V_366 )
{
switch ( V_366 ) {
case 0 :
V_157 -> V_181 |= V_367 ;
V_157 -> V_324 = V_365 ;
break;
case 1 :
V_157 -> V_181 |= V_368 ;
V_157 -> V_326 = V_365 ;
break;
#if V_327 > 2
case 2 :
V_157 -> V_181 |= V_369 ;
V_157 -> V_329 = V_365 ;
break;
case 3 :
V_157 -> V_181 |= V_370 ;
V_157 -> V_331 = V_365 ;
break;
#endif
default:
return - V_155 ;
}
V_157 -> V_181 |= V_182 ;
return 0 ;
}
static int F_208 ( struct V_151 * V_157 , T_6 V_365 ,
int type , int V_366 )
{
switch ( V_366 ) {
case 0 :
if ( type & V_197 )
V_157 -> V_181 |= V_371 ;
if ( type & V_194 )
V_157 -> V_181 |= V_372 ;
V_157 -> V_198 = V_365 ;
break;
case 1 :
if ( type & V_197 )
V_157 -> V_181 |= V_373 ;
if ( type & V_194 )
V_157 -> V_181 |= V_374 ;
V_157 -> V_199 = V_365 ;
break;
default:
return - V_155 ;
}
V_157 -> V_181 |= V_182 ;
return 0 ;
}
void F_209 ( struct V_1 * V_2 , T_2 V_375 , bool V_376 )
{
#ifdef V_21
F_61 ( V_375 & ~ ( V_377 | V_378 | V_379 ) ) ;
if ( V_376 ) {
if ( V_375 & V_380 )
V_2 -> V_4 . V_381 |= V_377 ;
if ( V_375 & V_26 )
V_2 -> V_4 . V_381 |= V_378 ;
if ( V_375 & V_382 )
V_2 -> V_4 . V_381 |= V_379 ;
} else {
if ( V_375 & V_380 )
V_2 -> V_4 . V_381 &= ~ V_377 ;
if ( V_375 & V_26 )
V_2 -> V_4 . V_381 &= ~ V_378 ;
if ( V_375 & V_382 )
V_2 -> V_4 . V_381 &= ~ V_379 ;
}
#endif
}
int F_210 ( struct V_1 * V_2 , T_2 V_259 , enum V_383 V_384 ,
enum V_385 V_386 , struct V_387 * V_388 )
{
int V_260 ;
T_4 V_261 ;
#ifdef V_139
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_70 ) &&
( V_259 & V_263 ) == V_2 -> V_4 . V_264 ) {
V_388 -> V_259 = V_259 ;
V_388 -> V_389 = ( V_2 -> V_4 . V_390 & V_263 ) |
( V_259 & ~ V_263 ) ;
V_388 -> V_391 = V_259 >> V_269 ;
V_388 -> V_392 = true ;
V_388 -> V_393 = true ;
V_388 -> V_394 = true ;
return 0 ;
}
#endif
switch ( V_384 ) {
case V_395 :
V_260 = F_133 ( V_2 , V_259 ) ;
break;
case V_396 :
V_260 = F_125 ( V_2 , V_259 ) ;
break;
default:
F_100 () ;
}
if ( V_260 < 0 )
return - V_397 ;
V_261 = F_128 ( V_2 , V_260 , V_259 ) ;
V_388 -> V_259 = V_259 ;
V_388 -> V_389 = ( V_261 & V_263 ) | ( V_259 & ~ V_263 ) ;
V_388 -> V_391 = V_259 >> V_269 ;
V_388 -> V_392 = true ;
V_388 -> V_393 = true ;
V_388 -> V_394 = true ;
return 0 ;
}
int F_211 ( struct V_1 * V_2 ,
struct V_398 * V_399 )
{
struct V_151 * V_157 ;
int V_400 , V_401 = 0 , V_402 = 0 ;
if ( ! ( V_399 -> V_403 & V_404 ) ) {
V_2 -> V_4 . V_157 . V_181 = 0 ;
V_2 -> V_27 = 0 ;
F_209 ( V_2 , V_26 , false ) ;
return 0 ;
}
F_209 ( V_2 , V_26 , true ) ;
V_2 -> V_27 = V_399 -> V_403 ;
V_2 -> V_4 . V_157 . V_181 = 0 ;
if ( V_2 -> V_27 & V_405 )
V_2 -> V_4 . V_157 . V_181 |= V_182 | V_406 ;
V_157 = & ( V_2 -> V_4 . V_157 ) ;
#ifdef V_21
V_157 -> V_407 = 0 ;
V_157 -> V_408 = 0 ;
#else
V_157 -> V_407 = V_409 | V_410 | V_411 |
V_412 ;
V_157 -> V_408 = V_413 | V_414 ;
#endif
if ( ! ( V_2 -> V_27 & V_415 ) )
return 0 ;
for ( V_400 = 0 ; V_400 < ( V_416 + V_417 ) ; V_400 ++ ) {
T_6 V_365 = V_399 -> V_4 . V_418 [ V_400 ] . V_365 ;
T_7 type = V_399 -> V_4 . V_418 [ V_400 ] . type ;
if ( type == V_419 )
continue;
if ( type & ! ( V_197 |
V_194 |
V_191 ) )
return - V_155 ;
if ( type & V_191 ) {
if ( F_207 ( V_157 , V_365 , V_401 ++ ) )
return - V_155 ;
} else {
if ( F_208 ( V_157 , V_365 ,
type , V_402 ++ ) )
return - V_155 ;
}
}
return 0 ;
}
void F_212 ( struct V_1 * V_2 , int V_420 )
{
V_2 -> V_420 = F_213 () ;
V_15 -> V_16 . V_1 = V_2 ;
}
void F_214 ( struct V_1 * V_2 )
{
V_15 -> V_16 . V_1 = NULL ;
V_2 -> V_420 = - 1 ;
F_112 () ;
}
void F_215 ( struct V_1 * V_2 )
{
V_2 -> V_267 -> V_4 . V_317 -> V_421 ( V_2 ) ;
}
int F_216 ( struct V_267 * V_267 )
{
return V_267 -> V_4 . V_317 -> V_422 ( V_267 ) ;
}
struct V_1 * F_217 ( struct V_267 * V_267 , unsigned int V_320 )
{
return V_267 -> V_4 . V_317 -> V_423 ( V_267 , V_320 ) ;
}
void F_218 ( struct V_1 * V_2 )
{
V_2 -> V_267 -> V_4 . V_317 -> V_424 ( V_2 ) ;
}
void F_219 ( struct V_267 * V_267 )
{
V_267 -> V_4 . V_317 -> V_425 ( V_267 ) ;
}
void F_220 ( struct V_1 * V_2 , int V_420 )
{
V_2 -> V_267 -> V_4 . V_317 -> V_426 ( V_2 , V_420 ) ;
}
void F_221 ( struct V_1 * V_2 )
{
V_2 -> V_267 -> V_4 . V_317 -> V_427 ( V_2 ) ;
}
int T_8 F_222 ( void )
{
#ifndef V_21
unsigned long V_93 [ 16 ] ;
unsigned long * V_428 = V_429 ;
unsigned long V_430 = 0 ;
unsigned long V_431 ;
int V_3 ;
V_432 = F_223 ( V_433 | V_434 ,
V_435 ) ;
if ( ! V_432 )
return - V_436 ;
V_93 [ 0 ] = F_111 ( V_437 ) ;
V_93 [ 1 ] = F_111 ( V_438 ) ;
V_93 [ 2 ] = F_111 ( V_439 ) ;
V_93 [ 3 ] = F_111 ( V_440 ) ;
V_93 [ 4 ] = F_111 ( V_441 ) ;
V_93 [ 5 ] = F_111 ( V_442 ) ;
V_93 [ 6 ] = F_111 ( V_443 ) ;
V_93 [ 7 ] = F_111 ( V_444 ) ;
V_93 [ 8 ] = F_111 ( V_445 ) ;
V_93 [ 9 ] = F_111 ( V_446 ) ;
V_93 [ 10 ] = F_111 ( V_447 ) ;
V_93 [ 11 ] = F_111 ( V_448 ) ;
V_93 [ 12 ] = F_111 ( V_449 ) ;
V_93 [ 13 ] = F_111 ( V_450 ) ;
V_93 [ 14 ] = F_111 ( V_451 ) ;
V_93 [ 15 ] = F_111 ( V_452 ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( V_93 [ V_3 ] > V_430 )
V_430 = V_3 ;
V_431 = V_428 [ V_3 + 1 ] - V_428 [ V_3 ] ;
memcpy ( ( void * ) V_432 + V_93 [ V_3 ] ,
( void * ) V_428 [ V_3 ] , V_431 ) ;
}
V_431 = V_428 [ V_430 + 1 ] - V_428 [ V_430 ] ;
F_224 ( V_432 , V_432 +
V_93 [ V_430 ] + V_431 ) ;
#endif
return 0 ;
}
void T_9 F_225 ( void )
{
F_226 ( V_432 , V_435 ) ;
F_227 () ;
}
