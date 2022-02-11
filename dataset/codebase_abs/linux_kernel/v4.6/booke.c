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
F_8 () ;
V_2 -> V_4 . V_13 &= ~ V_14 ;
F_9 () ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_5 () ;
F_6 () ;
F_11 ( V_2 ) ;
F_8 () ;
V_2 -> V_4 . V_13 |= V_14 ;
F_9 () ;
}
static void F_12 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_6 -> V_7 & V_14 ) {
if ( ! ( V_2 -> V_4 . V_13 & V_14 ) )
F_10 ( V_2 ) ;
} else if ( V_2 -> V_4 . V_13 & V_14 ) {
F_4 ( V_2 ) ;
}
}
static void F_12 ( struct V_1 * V_2 )
{
}
static inline void F_13 ( struct V_1 * V_2 )
{
#ifdef F_14
if ( ! ( V_15 -> V_16 . V_17 -> V_7 & V_18 ) ) {
F_15 () ;
F_16 ( & V_2 -> V_4 . V_19 ) ;
F_17 () ;
V_15 -> V_16 . V_20 = & V_2 -> V_4 . V_19 ;
V_15 -> V_16 . V_17 -> V_7 |= V_18 ;
}
#endif
}
static inline void F_18 ( struct V_1 * V_2 )
{
#ifdef F_14
if ( V_15 -> V_16 . V_17 -> V_7 & V_18 )
F_19 ( V_15 ) ;
V_15 -> V_16 . V_20 = NULL ;
#endif
}
static void F_20 ( struct V_1 * V_2 )
{
#if F_21 ( F_14 ) && ! F_21 ( V_21 )
V_2 -> V_4 . V_13 &= ~ V_18 ;
V_2 -> V_4 . V_13 |= V_2 -> V_4 . V_6 -> V_7 & V_18 ;
#endif
}
static inline void F_22 ( struct V_1 * V_2 )
{
#ifdef F_23
if ( F_24 ( V_22 ) ) {
if ( ! ( V_15 -> V_16 . V_17 -> V_7 & V_23 ) ) {
F_25 () ;
F_26 ( & V_2 -> V_4 . V_24 ) ;
F_27 () ;
V_15 -> V_16 . V_25 = & V_2 -> V_4 . V_24 ;
V_15 -> V_16 . V_17 -> V_7 |= V_23 ;
}
}
#endif
}
static inline void F_28 ( struct V_1 * V_2 )
{
#ifdef F_23
if ( F_24 ( V_22 ) ) {
if ( V_15 -> V_16 . V_17 -> V_7 & V_23 )
F_29 ( V_15 ) ;
V_15 -> V_16 . V_25 = NULL ;
}
#endif
}
static void F_30 ( struct V_1 * V_2 )
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
void F_31 ( struct V_1 * V_2 , T_1 V_28 )
{
T_1 V_29 = V_2 -> V_4 . V_6 -> V_7 ;
#ifdef V_21
V_28 |= V_30 ;
#endif
V_2 -> V_4 . V_6 -> V_7 = V_28 ;
F_32 ( V_2 , V_29 ) ;
F_12 ( V_2 ) ;
F_20 ( V_2 ) ;
F_30 ( V_2 ) ;
}
static void F_33 ( struct V_1 * V_2 ,
unsigned int V_31 )
{
F_34 ( V_2 , V_31 ) ;
F_35 ( V_31 , & V_2 -> V_4 . V_12 ) ;
}
void F_36 ( struct V_1 * V_2 ,
T_2 V_32 , T_2 V_33 )
{
V_2 -> V_4 . V_34 = V_32 ;
V_2 -> V_4 . V_35 = V_33 ;
F_33 ( V_2 , V_36 ) ;
}
void F_37 ( struct V_1 * V_2 ,
T_2 V_32 , T_2 V_33 )
{
V_2 -> V_4 . V_34 = V_32 ;
V_2 -> V_4 . V_35 = V_33 ;
F_33 ( V_2 , V_37 ) ;
}
void F_38 ( struct V_1 * V_2 )
{
F_33 ( V_2 , V_38 ) ;
}
void F_39 ( struct V_1 * V_2 , T_2 V_33 )
{
V_2 -> V_4 . V_35 = V_33 ;
F_33 ( V_2 , V_39 ) ;
}
static void F_40 ( struct V_1 * V_2 , T_2 V_32 ,
T_2 V_33 )
{
V_2 -> V_4 . V_34 = V_32 ;
V_2 -> V_4 . V_35 = V_33 ;
F_33 ( V_2 , V_40 ) ;
}
void F_41 ( struct V_1 * V_2 , T_2 V_33 )
{
V_2 -> V_4 . V_35 = V_33 ;
F_33 ( V_2 , V_41 ) ;
}
void F_42 ( struct V_1 * V_2 )
{
F_33 ( V_2 , V_42 ) ;
}
int F_43 ( struct V_1 * V_2 )
{
return F_44 ( V_42 , & V_2 -> V_4 . V_12 ) ;
}
void F_45 ( struct V_1 * V_2 )
{
F_46 ( V_42 , & V_2 -> V_4 . V_12 ) ;
}
void F_47 ( struct V_1 * V_2 ,
struct V_43 * V_44 )
{
unsigned int V_45 = V_46 ;
if ( V_44 -> V_44 == V_47 )
V_45 = V_48 ;
F_33 ( V_2 , V_45 ) ;
}
void F_48 ( struct V_1 * V_2 )
{
F_46 ( V_46 , & V_2 -> V_4 . V_12 ) ;
F_46 ( V_48 , & V_2 -> V_4 . V_12 ) ;
}
static void F_49 ( struct V_1 * V_2 )
{
F_33 ( V_2 , V_49 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_46 ( V_49 , & V_2 -> V_4 . V_12 ) ;
}
void F_51 ( struct V_1 * V_2 )
{
F_33 ( V_2 , V_50 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
F_46 ( V_50 , & V_2 -> V_4 . V_12 ) ;
}
static void F_53 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
F_54 ( V_2 , V_10 ) ;
F_55 ( V_2 , V_11 ) ;
}
static void F_56 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_51 = V_10 ;
V_2 -> V_4 . V_52 = V_11 ;
}
static void F_57 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
if ( F_24 ( V_53 ) ) {
V_2 -> V_4 . V_54 = V_10 ;
V_2 -> V_4 . V_55 = V_11 ;
} else {
F_56 ( V_2 , V_10 , V_11 ) ;
}
}
static void F_58 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_56 = V_10 ;
V_2 -> V_4 . V_57 = V_11 ;
}
static int F_59 ( struct V_1 * V_2 ,
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
#ifdef F_60
case V_74 :
case V_75 :
case V_76 :
#endif
#ifdef F_23
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
if ( F_24 ( V_53 ) )
V_68 = V_91 ;
else
V_68 = V_85 ;
break;
}
if ( V_58 ) {
switch ( V_68 ) {
case V_82 :
F_53 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_85 :
F_56 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_91 :
F_57 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_87 :
F_58 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
}
V_2 -> V_4 . V_5 = V_2 -> V_4 . V_92 | V_2 -> V_4 . V_93 [ V_31 ] ;
if ( V_60 == true )
F_61 ( V_2 , V_2 -> V_4 . V_35 ) ;
if ( V_61 == true )
F_62 ( V_2 , V_2 -> V_4 . V_34 ) ;
if ( V_62 == true ) {
if ( V_2 -> V_4 . V_71 & V_94 )
F_63 ( V_95 , V_2 ) ;
else if ( V_2 -> V_4 . V_71 & V_96 ) {
F_64 ( V_2 -> V_4 . V_97 != V_98 ) ;
F_65 ( V_2 ) ;
}
}
V_28 &= V_59 ;
#if F_21 ( V_99 )
if ( V_2 -> V_4 . V_100 & V_101 )
V_28 |= V_102 ;
#endif
F_31 ( V_2 , V_28 ) ;
if ( ! V_67 )
F_46 ( V_31 , & V_2 -> V_4 . V_12 ) ;
}
#ifdef V_21
if ( V_2 -> V_4 . V_12 & V_103 )
F_66 ( V_2 , V_82 ) ;
if ( V_2 -> V_4 . V_12 & V_104 )
F_66 ( V_2 , V_85 ) ;
if ( V_2 -> V_4 . V_12 & V_86 )
F_66 ( V_2 , V_87 ) ;
#endif
return V_58 ;
}
static unsigned long F_67 ( struct V_1 * V_2 )
{
T_3 V_105 , V_106 , V_107 = 0 ;
T_3 V_108 = 0 ;
T_1 V_109 = F_68 ( V_2 -> V_4 . V_110 ) ;
V_106 = 1ULL << ( 63 - V_109 ) ;
V_105 = F_69 () ;
if ( V_105 & V_106 )
V_107 = V_106 ;
V_107 += V_106 - ( V_105 & ( V_106 - 1 ) ) ;
V_108 = V_107 ;
if ( F_70 ( V_108 , V_111 ) )
V_108 ++ ;
return F_71 (unsigned long long, nr_jiffies, NEXT_TIMER_MAX_DELTA) ;
}
static void F_72 ( struct V_1 * V_2 )
{
unsigned long V_108 ;
unsigned long V_112 ;
if ( ( V_2 -> V_4 . V_113 & ( V_114 | V_115 ) ) != ( V_114 | V_115 ) )
F_46 ( V_116 , & V_2 -> V_117 ) ;
F_73 ( & V_2 -> V_4 . V_118 , V_112 ) ;
V_108 = F_67 ( V_2 ) ;
if ( V_108 < V_119 )
F_74 ( & V_2 -> V_4 . V_120 , V_121 + V_108 ) ;
else
F_75 ( & V_2 -> V_4 . V_120 ) ;
F_76 ( & V_2 -> V_4 . V_118 , V_112 ) ;
}
void F_77 ( unsigned long V_122 )
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
} while ( F_78 ( & V_2 -> V_4 . V_113 , V_113 , V_123 ) != V_113 );
if ( V_123 & V_115 ) {
F_79 () ;
F_63 ( V_125 , V_2 ) ;
F_80 ( V_2 ) ;
}
if ( V_124 && ( V_2 -> V_4 . V_110 & V_126 ) &&
V_2 -> V_4 . V_127 ) {
F_79 () ;
F_63 ( V_116 , V_2 ) ;
F_80 ( V_2 ) ;
}
if ( ! V_124 )
F_72 ( V_2 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 . V_110 & V_128 ) && ( V_2 -> V_4 . V_113 & V_129 ) )
F_42 ( V_2 ) ;
else
F_45 ( V_2 ) ;
if ( ( V_2 -> V_4 . V_110 & V_130 ) && ( V_2 -> V_4 . V_113 & V_115 ) )
F_49 ( V_2 ) ;
else
F_50 ( V_2 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
unsigned long * V_131 = & V_2 -> V_4 . V_12 ;
unsigned int V_31 ;
V_31 = F_83 ( * V_131 ) ;
while ( V_31 < V_132 ) {
if ( F_59 ( V_2 , V_31 ) )
break;
V_31 = F_84 ( V_131 ,
V_133 * sizeof( * V_131 ) ,
V_31 + 1 ) ;
}
V_2 -> V_4 . V_6 -> V_134 = ! ! * V_131 ;
}
int F_85 ( struct V_1 * V_2 )
{
int V_135 = 0 ;
F_86 ( ! F_87 () ) ;
F_82 ( V_2 ) ;
if ( V_2 -> V_117 ) {
return 1 ;
}
if ( V_2 -> V_4 . V_6 -> V_7 & V_136 ) {
F_88 () ;
F_89 ( V_2 ) ;
F_46 ( V_137 , & V_2 -> V_117 ) ;
F_90 () ;
F_91 ( V_2 , V_138 ) ;
V_135 = 1 ;
} ;
return V_135 ;
}
int F_92 ( struct V_1 * V_2 )
{
int V_135 = 1 ;
if ( F_93 ( V_125 , V_2 ) )
F_81 ( V_2 ) ;
#if F_21 ( V_139 ) || F_21 ( V_140 )
if ( F_93 ( V_141 , V_2 ) )
F_94 ( V_2 ) ;
#endif
if ( F_93 ( V_116 , V_2 ) ) {
V_2 -> V_142 -> V_143 = V_144 ;
V_135 = 0 ;
}
if ( F_93 ( V_95 , V_2 ) ) {
V_2 -> V_142 -> V_145 . V_145 = 0 ;
V_2 -> V_4 . V_146 = true ;
V_2 -> V_142 -> V_143 = V_147 ;
V_135 = 0 ;
}
return V_135 ;
}
int F_95 ( struct V_148 * V_148 , struct V_1 * V_2 )
{
int V_149 , V_150 ;
struct V_151 V_152 ;
if ( ! V_2 -> V_4 . V_153 ) {
V_148 -> V_143 = V_154 ;
return - V_155 ;
}
V_150 = F_96 ( V_2 ) ;
if ( V_150 <= 0 ) {
V_149 = V_150 ;
goto V_156;
}
#ifdef F_14
F_15 () ;
F_13 ( V_2 ) ;
#endif
#ifdef F_23
if ( F_24 ( V_22 ) )
F_25 () ;
F_22 ( V_2 ) ;
#endif
V_152 = V_2 -> V_4 . V_157 ;
F_97 ( & V_152 ) ;
V_152 = V_15 -> V_16 . V_152 ;
V_15 -> V_16 . V_152 = V_2 -> V_4 . V_157 ;
V_2 -> V_4 . V_158 = V_15 -> V_159 -> V_160 ;
F_98 () ;
V_149 = F_99 ( V_148 , V_2 ) ;
F_97 ( & V_152 ) ;
V_15 -> V_16 . V_152 = V_152 ;
#ifdef F_14
F_18 ( V_2 ) ;
#endif
#ifdef F_23
F_28 ( V_2 ) ;
#endif
V_156:
V_2 -> V_161 = V_162 ;
return V_149 ;
}
static int F_100 ( struct V_148 * V_142 , struct V_1 * V_2 )
{
enum V_163 V_164 ;
V_164 = F_101 ( V_142 , V_2 ) ;
switch ( V_164 ) {
case V_165 :
F_102 ( V_2 , V_166 ) ;
return V_167 ;
case V_168 :
return V_169 ;
case V_170 :
F_2 ( V_171 L_6 ,
V_172 , V_2 -> V_4 . V_5 , V_2 -> V_4 . V_173 ) ;
V_142 -> V_174 . V_175 = ~ 0ULL << 32 ;
V_142 -> V_174 . V_175 |= V_2 -> V_4 . V_173 ;
F_41 ( V_2 , V_176 ) ;
return V_177 ;
case V_178 :
return V_177 ;
default:
F_103 () ;
}
}
static int F_104 ( struct V_148 * V_142 , struct V_1 * V_2 )
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
F_51 ( V_2 ) ;
if ( ( V_179 & V_183 ) && ! ( V_2 -> V_4 . V_6 -> V_7 & V_26 ) )
F_41 ( V_2 , V_184 ) ;
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
static void F_105 ( struct V_200 * V_17 )
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
static void F_106 ( struct V_1 * V_2 ,
unsigned int V_206 )
{
struct V_200 V_17 ;
switch ( V_206 ) {
case V_207 :
F_105 ( & V_17 ) ;
F_107 ( & V_17 ) ;
break;
case V_208 :
F_105 ( & V_17 ) ;
F_108 ( & V_17 ) ;
break;
#if F_21 ( V_209 )
case V_210 :
F_105 ( & V_17 ) ;
F_109 ( & V_17 ) ;
break;
#endif
case V_211 :
break;
case V_212 :
F_105 ( & V_17 ) ;
F_110 ( & V_17 ) ;
break;
case V_213 :
F_105 ( & V_17 ) ;
#ifdef F_111
F_112 ( & V_17 ) ;
#else
F_113 ( & V_17 ) ;
#endif
break;
case V_214 :
F_105 ( & V_17 ) ;
F_113 ( & V_17 ) ;
break;
case V_215 :
V_2 -> V_4 . V_179 = F_114 ( V_216 ) ;
F_115 () ;
break;
}
}
static int F_116 ( struct V_148 * V_142 , struct V_1 * V_2 ,
enum V_163 V_217 , T_1 V_173 )
{
switch ( V_217 ) {
case V_168 :
return V_169 ;
case V_170 :
F_117 ( L_7 ,
V_172 , V_2 -> V_4 . V_5 ) ;
V_142 -> V_174 . V_175 = ~ 0ULL << 32 ;
V_142 -> V_174 . V_175 |= V_173 ;
F_41 ( V_2 , V_176 ) ;
return V_177 ;
default:
F_103 () ;
}
}
int F_118 ( struct V_148 * V_142 , struct V_1 * V_2 ,
unsigned int V_206 )
{
int V_135 = V_177 ;
int V_150 ;
int V_218 ;
T_1 V_173 = V_219 ;
enum V_163 V_217 = V_165 ;
F_119 ( V_2 ) ;
F_106 ( V_2 , V_206 ) ;
switch ( V_206 ) {
case V_220 :
case V_221 :
case V_222 :
V_217 = F_120 ( V_2 , V_223 , & V_173 ) ;
break;
case V_224 :
if ( V_2 -> V_27 & V_225 )
V_217 = F_120 ( V_2 , V_223 , & V_173 ) ;
break;
default:
break;
}
F_121 ( V_206 , V_2 ) ;
F_122 () ;
F_88 () ;
V_142 -> V_143 = V_226 ;
V_142 -> V_227 = 1 ;
if ( V_217 != V_165 ) {
V_135 = F_116 ( V_142 , V_2 , V_217 , V_173 ) ;
goto V_156;
}
switch ( V_206 ) {
case V_211 :
F_2 ( L_8 , F_114 ( V_228 ) ) ;
F_1 ( V_2 ) ;
V_142 -> V_174 . V_175 = ~ 1ULL << 32 ;
V_142 -> V_174 . V_175 |= F_114 ( V_228 ) ;
V_135 = V_177 ;
break;
case V_207 :
F_123 ( V_2 , V_229 ) ;
V_135 = V_169 ;
break;
case V_208 :
F_123 ( V_2 , V_230 ) ;
V_135 = V_169 ;
break;
case V_213 :
V_135 = V_169 ;
break;
case V_210 :
F_123 ( V_2 , V_231 ) ;
V_135 = V_169 ;
break;
case V_232 :
F_123 ( V_2 , V_233 ) ;
V_135 = V_169 ;
break;
case V_234 :
F_123 ( V_2 , V_233 ) ;
V_135 = V_169 ;
break;
case V_212 :
V_135 = V_169 ;
break;
case V_222 :
V_135 = F_100 ( V_142 , V_2 ) ;
break;
case V_224 :
if ( ( V_2 -> V_27 & V_225 ) &&
( V_173 == V_235 ) ) {
V_135 = F_104 ( V_142 , V_2 ) ;
V_142 -> V_143 = V_236 ;
F_123 ( V_2 , V_237 ) ;
break;
}
if ( V_2 -> V_4 . V_6 -> V_7 & ( V_70 | V_30 ) ) {
F_41 ( V_2 , V_2 -> V_4 . V_238 ) ;
V_135 = V_169 ;
F_123 ( V_2 , V_239 ) ;
break;
}
V_135 = F_100 ( V_142 , V_2 ) ;
break;
case V_240 :
F_33 ( V_2 , V_73 ) ;
F_123 ( V_2 , V_241 ) ;
V_135 = V_169 ;
break;
#ifdef F_124
case V_242 : {
if ( V_2 -> V_4 . V_6 -> V_7 & V_14 )
F_10 ( V_2 ) ;
else
F_33 ( V_2 ,
V_74 ) ;
V_135 = V_169 ;
break;
}
case V_243 :
F_33 ( V_2 , V_75 ) ;
V_135 = V_169 ;
break;
case V_244 :
F_33 ( V_2 , V_76 ) ;
V_135 = V_169 ;
break;
#elif F_21 ( F_60 )
case V_242 :
F_41 ( V_2 , V_245 | V_246 ) ;
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
#ifdef F_23
case V_247 :
F_33 ( V_2 , V_77 ) ;
V_135 = V_169 ;
break;
case V_248 :
F_33 ( V_2 , V_78 ) ;
V_135 = V_169 ;
break;
#endif
case V_220 :
F_37 ( V_2 , V_2 -> V_4 . V_249 ,
V_2 -> V_4 . V_238 ) ;
F_123 ( V_2 , V_250 ) ;
V_135 = V_169 ;
break;
case V_251 :
F_39 ( V_2 , V_2 -> V_4 . V_238 ) ;
F_123 ( V_2 , V_252 ) ;
V_135 = V_169 ;
break;
case V_253 :
F_40 ( V_2 , V_2 -> V_4 . V_249 ,
V_2 -> V_4 . V_238 ) ;
V_135 = V_169 ;
break;
#ifdef V_21
case V_254 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_70 ) ) {
F_125 ( V_2 , 3 , F_126 ( V_2 ) ) ;
} else {
F_41 ( V_2 , V_255 ) ;
}
V_135 = V_169 ;
break;
#else
case V_256 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_70 ) &&
( ( ( T_1 ) F_3 ( V_2 , 0 ) ) == V_257 ) ) {
F_125 ( V_2 , 3 , F_126 ( V_2 ) ) ;
V_135 = V_169 ;
} else {
F_33 ( V_2 , V_72 ) ;
}
F_123 ( V_2 , V_258 ) ;
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
F_127 ( V_2 ) ;
F_123 ( V_2 , V_265 ) ;
V_135 = V_169 ;
break;
}
#endif
V_260 = F_128 ( V_2 , V_259 ) ;
if ( V_260 < 0 ) {
F_36 ( V_2 ,
V_2 -> V_4 . V_249 ,
V_2 -> V_4 . V_238 ) ;
F_129 ( V_2 ) ;
F_123 ( V_2 , V_266 ) ;
V_135 = V_169 ;
break;
}
V_218 = F_130 ( & V_2 -> V_267 -> V_268 ) ;
V_261 = F_131 ( V_2 , V_260 , V_259 ) ;
V_262 = V_261 >> V_269 ;
if ( F_132 ( V_2 -> V_267 , V_262 ) ) {
F_133 ( V_2 , V_259 , V_261 , V_260 ) ;
F_123 ( V_2 , V_265 ) ;
V_135 = V_169 ;
} else {
V_2 -> V_4 . V_270 = V_261 ;
V_2 -> V_4 . V_271 = V_259 ;
V_135 = F_134 ( V_142 , V_2 ) ;
F_123 ( V_2 , V_272 ) ;
}
F_135 ( & V_2 -> V_267 -> V_268 , V_218 ) ;
break;
}
case V_273 : {
unsigned long V_259 = V_2 -> V_4 . V_5 ;
T_4 V_261 ;
T_5 V_262 ;
int V_260 ;
V_135 = V_169 ;
V_260 = F_136 ( V_2 , V_259 ) ;
if ( V_260 < 0 ) {
F_33 ( V_2 , V_38 ) ;
F_137 ( V_2 ) ;
F_123 ( V_2 , V_274 ) ;
break;
}
F_123 ( V_2 , V_275 ) ;
V_218 = F_130 ( & V_2 -> V_267 -> V_268 ) ;
V_261 = F_131 ( V_2 , V_260 , V_259 ) ;
V_262 = V_261 >> V_269 ;
if ( F_132 ( V_2 -> V_267 , V_262 ) ) {
F_133 ( V_2 , V_259 , V_261 , V_260 ) ;
} else {
F_33 ( V_2 , V_86 ) ;
}
F_135 ( & V_2 -> V_267 -> V_268 , V_218 ) ;
break;
}
case V_215 : {
V_135 = F_104 ( V_142 , V_2 ) ;
if ( V_135 == V_177 )
V_142 -> V_143 = V_236 ;
F_123 ( V_2 , V_237 ) ;
break;
}
default:
F_2 ( V_276 L_10 , V_206 ) ;
F_103 () ;
}
V_156:
if ( ! ( V_135 & V_177 ) ) {
V_150 = F_96 ( V_2 ) ;
if ( V_150 <= 0 )
V_135 = ( V_150 << 2 ) | V_177 | ( V_135 & V_277 ) ;
else {
F_98 () ;
F_13 ( V_2 ) ;
F_22 ( V_2 ) ;
}
}
return V_135 ;
}
static void F_138 ( struct V_1 * V_2 , T_1 V_123 )
{
T_1 V_278 = V_2 -> V_4 . V_113 ;
V_2 -> V_4 . V_113 = V_123 ;
if ( ( V_278 ^ V_2 -> V_4 . V_113 ) & ( V_114 | V_115 ) )
F_72 ( V_2 ) ;
F_81 ( V_2 ) ;
}
int F_139 ( struct V_1 * V_2 )
{
int V_3 ;
int V_135 ;
V_2 -> V_4 . V_5 = 0 ;
V_2 -> V_4 . V_6 -> V_279 = V_2 -> V_280 ;
F_125 ( V_2 , 1 , ( 16 << 20 ) - 8 ) ;
F_31 ( V_2 , 0 ) ;
#ifndef V_21
V_2 -> V_4 . V_13 = V_281 | V_282 | V_283 ;
V_2 -> V_4 . V_284 = 1 ;
V_2 -> V_4 . V_6 -> V_7 = 0 ;
#endif
V_2 -> V_4 . V_92 = 0x55550000 ;
for ( V_3 = 0 ; V_3 < V_132 ; V_3 ++ )
V_2 -> V_4 . V_93 [ V_3 ] = 0x7700 | V_3 * 4 ;
F_140 ( V_2 ) ;
V_135 = F_141 ( V_2 ) ;
F_142 ( V_2 ) ;
return V_135 ;
}
int F_143 ( struct V_1 * V_2 )
{
F_144 ( & V_2 -> V_4 . V_118 ) ;
F_145 ( & V_2 -> V_4 . V_120 , F_77 ,
( unsigned long ) V_2 ) ;
F_146 ( V_216 , V_285 ) ;
return 0 ;
}
void F_147 ( struct V_1 * V_2 )
{
F_148 ( & V_2 -> V_4 . V_120 ) ;
}
int F_149 ( struct V_1 * V_2 , struct V_286 * V_17 )
{
int V_3 ;
V_17 -> V_5 = V_2 -> V_4 . V_5 ;
V_17 -> V_287 = F_150 ( V_2 ) ;
V_17 -> V_9 = V_2 -> V_4 . V_9 ;
V_17 -> V_8 = V_2 -> V_4 . V_8 ;
V_17 -> V_288 = F_151 ( V_2 ) ;
V_17 -> V_7 = V_2 -> V_4 . V_6 -> V_7 ;
V_17 -> V_10 = F_152 ( V_2 ) ;
V_17 -> V_11 = F_153 ( V_2 ) ;
V_17 -> V_289 = V_2 -> V_4 . V_289 ;
V_17 -> V_290 = F_154 ( V_2 ) ;
V_17 -> V_291 = F_155 ( V_2 ) ;
V_17 -> V_292 = F_156 ( V_2 ) ;
V_17 -> V_293 = F_157 ( V_2 ) ;
V_17 -> V_294 = F_158 ( V_2 ) ;
V_17 -> V_295 = F_159 ( V_2 ) ;
V_17 -> V_296 = F_160 ( V_2 ) ;
V_17 -> V_297 = F_161 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < F_162 ( V_17 -> V_203 ) ; V_3 ++ )
V_17 -> V_203 [ V_3 ] = F_3 ( V_2 , V_3 ) ;
return 0 ;
}
int F_163 ( struct V_1 * V_2 , struct V_286 * V_17 )
{
int V_3 ;
V_2 -> V_4 . V_5 = V_17 -> V_5 ;
F_164 ( V_2 , V_17 -> V_287 ) ;
V_2 -> V_4 . V_9 = V_17 -> V_9 ;
V_2 -> V_4 . V_8 = V_17 -> V_8 ;
F_165 ( V_2 , V_17 -> V_288 ) ;
F_31 ( V_2 , V_17 -> V_7 ) ;
F_54 ( V_2 , V_17 -> V_10 ) ;
F_55 ( V_2 , V_17 -> V_11 ) ;
F_166 ( V_2 , V_17 -> V_289 ) ;
F_167 ( V_2 , V_17 -> V_290 ) ;
F_168 ( V_2 , V_17 -> V_291 ) ;
F_169 ( V_2 , V_17 -> V_292 ) ;
F_170 ( V_2 , V_17 -> V_293 ) ;
F_171 ( V_2 , V_17 -> V_294 ) ;
F_172 ( V_2 , V_17 -> V_295 ) ;
F_173 ( V_2 , V_17 -> V_296 ) ;
F_174 ( V_2 , V_17 -> V_297 ) ;
for ( V_3 = 0 ; V_3 < F_162 ( V_17 -> V_203 ) ; V_3 ++ )
F_125 ( V_2 , V_3 , V_17 -> V_203 [ V_3 ] ) ;
return 0 ;
}
static void F_175 ( struct V_1 * V_2 ,
struct V_298 * V_299 )
{
T_3 V_105 = F_69 () ;
V_299 -> V_300 . V_301 . V_302 |= V_303 ;
V_299 -> V_300 . V_301 . V_51 = V_2 -> V_4 . V_51 ;
V_299 -> V_300 . V_301 . V_52 = V_2 -> V_4 . V_52 ;
V_299 -> V_300 . V_301 . V_304 = V_2 -> V_4 . V_304 ;
V_299 -> V_300 . V_301 . V_305 = F_176 ( V_2 ) ;
V_299 -> V_300 . V_301 . V_306 = F_177 ( V_2 ) ;
V_299 -> V_300 . V_301 . V_113 = V_2 -> V_4 . V_113 ;
V_299 -> V_300 . V_301 . V_110 = V_2 -> V_4 . V_110 ;
V_299 -> V_300 . V_301 . V_307 = F_178 ( V_2 , V_105 ) ;
V_299 -> V_300 . V_301 . V_105 = V_105 ;
V_299 -> V_300 . V_301 . V_308 = V_2 -> V_4 . V_308 ;
}
static int F_179 ( struct V_1 * V_2 ,
struct V_298 * V_299 )
{
if ( ! ( V_299 -> V_300 . V_301 . V_302 & V_303 ) )
return 0 ;
V_2 -> V_4 . V_51 = V_299 -> V_300 . V_301 . V_51 ;
V_2 -> V_4 . V_52 = V_299 -> V_300 . V_301 . V_52 ;
V_2 -> V_4 . V_304 = V_299 -> V_300 . V_301 . V_304 ;
F_61 ( V_2 , V_299 -> V_300 . V_301 . V_305 ) ;
F_62 ( V_2 , V_299 -> V_300 . V_301 . V_306 ) ;
V_2 -> V_4 . V_308 = V_299 -> V_300 . V_301 . V_308 ;
F_180 ( V_2 , V_299 -> V_300 . V_301 . V_110 ) ;
if ( V_299 -> V_300 . V_301 . V_309 & V_310 ) {
V_2 -> V_4 . V_307 = V_299 -> V_300 . V_301 . V_307 ;
F_181 ( V_2 ) ;
}
if ( V_299 -> V_300 . V_301 . V_309 & V_311 )
F_138 ( V_2 , V_299 -> V_300 . V_301 . V_113 ) ;
return 0 ;
}
static void F_182 ( struct V_1 * V_2 ,
struct V_298 * V_299 )
{
V_299 -> V_300 . V_301 . V_302 |= V_312 ;
V_299 -> V_300 . V_301 . V_279 = V_2 -> V_280 ;
V_299 -> V_300 . V_301 . V_56 = V_2 -> V_4 . V_56 ;
V_299 -> V_300 . V_301 . V_57 = V_2 -> V_4 . V_57 ;
V_299 -> V_300 . V_301 . V_313 = V_2 -> V_4 . V_313 ;
V_299 -> V_300 . V_301 . V_92 = V_2 -> V_4 . V_92 ;
}
static int F_183 ( struct V_1 * V_2 ,
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
int F_184 ( struct V_1 * V_2 , struct V_298 * V_299 )
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
int F_185 ( struct V_1 * V_2 , struct V_298 * V_299 )
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
int F_186 ( struct V_1 * V_2 ,
struct V_298 * V_299 )
{
V_299 -> V_316 = V_2 -> V_4 . V_316 ;
F_175 ( V_2 , V_299 ) ;
F_182 ( V_2 , V_299 ) ;
return V_2 -> V_267 -> V_4 . V_317 -> V_318 ( V_2 , V_299 ) ;
}
int F_187 ( struct V_1 * V_2 ,
struct V_298 * V_299 )
{
int V_149 ;
if ( V_2 -> V_4 . V_316 != V_299 -> V_316 )
return - V_155 ;
V_149 = F_179 ( V_2 , V_299 ) ;
if ( V_149 < 0 )
return V_149 ;
V_149 = F_183 ( V_2 , V_299 ) ;
if ( V_149 < 0 )
return V_149 ;
return V_2 -> V_267 -> V_4 . V_317 -> V_319 ( V_2 , V_299 ) ;
}
int F_188 ( struct V_1 * V_2 , T_3 V_320 ,
union V_321 * V_322 )
{
int V_135 = 0 ;
switch ( V_320 ) {
case V_323 :
* V_322 = F_189 ( V_320 , V_2 -> V_4 . V_157 . V_324 ) ;
break;
case V_325 :
* V_322 = F_189 ( V_320 , V_2 -> V_4 . V_157 . V_326 ) ;
break;
#if V_327 > 2
case V_328 :
* V_322 = F_189 ( V_320 , V_2 -> V_4 . V_157 . V_329 ) ;
break;
case V_330 :
* V_322 = F_189 ( V_320 , V_2 -> V_4 . V_157 . V_331 ) ;
break;
#endif
case V_332 :
* V_322 = F_189 ( V_320 , V_2 -> V_4 . V_157 . V_198 ) ;
break;
case V_333 :
* V_322 = F_189 ( V_320 , V_2 -> V_4 . V_157 . V_199 ) ;
break;
case V_334 : {
T_1 V_145 = F_190 ( V_2 ) ;
* V_322 = F_189 ( V_320 , V_145 ) ;
break;
}
#if F_21 ( V_99 )
case V_335 :
* V_322 = F_189 ( V_320 , V_2 -> V_4 . V_100 ) ;
break;
#endif
case V_336 :
* V_322 = F_189 ( V_320 , V_2 -> V_4 . V_110 ) ;
break;
case V_337 :
* V_322 = F_189 ( V_320 , V_2 -> V_4 . V_113 ) ;
break;
case V_338 :
* V_322 = F_189 ( V_320 , V_235 ) ;
break;
case V_339 :
* V_322 = F_189 ( V_320 , V_2 -> V_4 . V_308 ) ;
break;
default:
V_135 = V_2 -> V_267 -> V_4 . V_317 -> V_340 ( V_2 , V_320 , V_322 ) ;
break;
}
return V_135 ;
}
int F_191 ( struct V_1 * V_2 , T_3 V_320 ,
union V_321 * V_322 )
{
int V_135 = 0 ;
switch ( V_320 ) {
case V_323 :
V_2 -> V_4 . V_157 . V_324 = F_192 ( V_320 , * V_322 ) ;
break;
case V_325 :
V_2 -> V_4 . V_157 . V_326 = F_192 ( V_320 , * V_322 ) ;
break;
#if V_327 > 2
case V_328 :
V_2 -> V_4 . V_157 . V_329 = F_192 ( V_320 , * V_322 ) ;
break;
case V_330 :
V_2 -> V_4 . V_157 . V_331 = F_192 ( V_320 , * V_322 ) ;
break;
#endif
case V_332 :
V_2 -> V_4 . V_157 . V_198 = F_192 ( V_320 , * V_322 ) ;
break;
case V_333 :
V_2 -> V_4 . V_157 . V_199 = F_192 ( V_320 , * V_322 ) ;
break;
case V_334 : {
T_1 V_341 = F_192 ( V_320 , * V_322 ) ;
F_193 ( V_2 , V_341 ) ;
break;
}
#if F_21 ( V_99 )
case V_335 : {
T_1 V_342 = F_192 ( V_320 , * V_322 ) ;
F_194 ( V_2 , V_342 ) ;
break;
}
#endif
case V_343 : {
T_1 V_344 = F_192 ( V_320 , * V_322 ) ;
F_195 ( V_2 , V_344 ) ;
break;
}
case V_345 : {
T_1 V_344 = F_192 ( V_320 , * V_322 ) ;
F_196 ( V_2 , V_344 ) ;
break;
}
case V_337 : {
T_1 V_113 = F_192 ( V_320 , * V_322 ) ;
F_138 ( V_2 , V_113 ) ;
break;
}
case V_336 : {
T_1 V_110 = F_192 ( V_320 , * V_322 ) ;
F_180 ( V_2 , V_110 ) ;
break;
}
case V_339 :
V_2 -> V_4 . V_308 = F_192 ( V_320 , * V_322 ) ;
break;
default:
V_135 = V_2 -> V_267 -> V_4 . V_317 -> V_346 ( V_2 , V_320 , V_322 ) ;
break;
}
return V_135 ;
}
int F_197 ( struct V_1 * V_2 , struct V_347 * V_348 )
{
return - V_349 ;
}
int F_198 ( struct V_1 * V_2 , struct V_347 * V_348 )
{
return - V_349 ;
}
int F_199 ( struct V_1 * V_2 ,
struct V_350 * V_351 )
{
int V_135 ;
V_135 = F_200 ( V_2 , V_351 ) ;
return V_135 ;
}
int F_201 ( struct V_267 * V_267 , struct V_352 * log )
{
return - V_349 ;
}
void F_202 ( struct V_267 * V_267 , struct V_353 * free ,
struct V_353 * V_354 )
{
}
int F_203 ( struct V_267 * V_267 , struct V_353 * V_355 ,
unsigned long V_356 )
{
return 0 ;
}
int F_204 ( struct V_267 * V_267 ,
struct V_353 * V_357 ,
const struct V_358 * V_359 )
{
return 0 ;
}
void F_205 ( struct V_267 * V_267 ,
const struct V_358 * V_359 ,
const struct V_353 * V_360 ,
const struct V_353 * V_361 )
{
}
void F_206 ( struct V_267 * V_267 , struct V_353 * V_357 )
{
}
void F_194 ( struct V_1 * V_2 , T_1 V_342 )
{
#if F_21 ( V_99 )
V_2 -> V_4 . V_100 = V_342 ;
#ifdef V_21
V_2 -> V_4 . V_362 &= ~ V_363 ;
if ( V_2 -> V_4 . V_100 & V_101 )
V_2 -> V_4 . V_362 |= V_363 ;
#endif
#endif
}
void F_180 ( struct V_1 * V_2 , T_1 V_364 )
{
V_2 -> V_4 . V_110 = V_364 ;
F_72 ( V_2 ) ;
F_81 ( V_2 ) ;
}
void F_195 ( struct V_1 * V_2 , T_1 V_344 )
{
F_207 ( V_344 , & V_2 -> V_4 . V_113 ) ;
F_79 () ;
F_63 ( V_125 , V_2 ) ;
F_80 ( V_2 ) ;
}
void F_196 ( struct V_1 * V_2 , T_1 V_344 )
{
F_208 ( V_344 , & V_2 -> V_4 . V_113 ) ;
if ( V_344 & ( V_114 | V_115 ) )
F_72 ( V_2 ) ;
F_81 ( V_2 ) ;
}
void F_209 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_110 & V_365 ) {
V_2 -> V_4 . V_307 = V_2 -> V_4 . V_313 ;
F_181 ( V_2 ) ;
}
F_195 ( V_2 , V_129 ) ;
}
static int F_210 ( struct V_151 * V_157 ,
T_6 V_366 , int V_367 )
{
switch ( V_367 ) {
case 0 :
V_157 -> V_181 |= V_368 ;
V_157 -> V_324 = V_366 ;
break;
case 1 :
V_157 -> V_181 |= V_369 ;
V_157 -> V_326 = V_366 ;
break;
#if V_327 > 2
case 2 :
V_157 -> V_181 |= V_370 ;
V_157 -> V_329 = V_366 ;
break;
case 3 :
V_157 -> V_181 |= V_371 ;
V_157 -> V_331 = V_366 ;
break;
#endif
default:
return - V_155 ;
}
V_157 -> V_181 |= V_182 ;
return 0 ;
}
static int F_211 ( struct V_151 * V_157 , T_6 V_366 ,
int type , int V_367 )
{
switch ( V_367 ) {
case 0 :
if ( type & V_197 )
V_157 -> V_181 |= V_372 ;
if ( type & V_194 )
V_157 -> V_181 |= V_373 ;
V_157 -> V_198 = V_366 ;
break;
case 1 :
if ( type & V_197 )
V_157 -> V_181 |= V_374 ;
if ( type & V_194 )
V_157 -> V_181 |= V_375 ;
V_157 -> V_199 = V_366 ;
break;
default:
return - V_155 ;
}
V_157 -> V_181 |= V_182 ;
return 0 ;
}
void F_212 ( struct V_1 * V_2 , T_2 V_376 , bool V_377 )
{
#ifdef V_21
F_64 ( V_376 & ~ ( V_378 | V_379 | V_380 ) ) ;
if ( V_377 ) {
if ( V_376 & V_381 )
V_2 -> V_4 . V_382 |= V_378 ;
if ( V_376 & V_26 )
V_2 -> V_4 . V_382 |= V_379 ;
if ( V_376 & V_383 )
V_2 -> V_4 . V_382 |= V_380 ;
} else {
if ( V_376 & V_381 )
V_2 -> V_4 . V_382 &= ~ V_378 ;
if ( V_376 & V_26 )
V_2 -> V_4 . V_382 &= ~ V_379 ;
if ( V_376 & V_383 )
V_2 -> V_4 . V_382 &= ~ V_380 ;
}
#endif
}
int F_213 ( struct V_1 * V_2 , T_2 V_259 , enum V_384 V_385 ,
enum V_386 V_387 , struct V_388 * V_389 )
{
int V_260 ;
T_4 V_261 ;
#ifdef V_139
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_70 ) &&
( V_259 & V_263 ) == V_2 -> V_4 . V_264 ) {
V_389 -> V_259 = V_259 ;
V_389 -> V_390 = ( V_2 -> V_4 . V_391 & V_263 ) |
( V_259 & ~ V_263 ) ;
V_389 -> V_392 = V_259 >> V_269 ;
V_389 -> V_393 = true ;
V_389 -> V_394 = true ;
V_389 -> V_395 = true ;
return 0 ;
}
#endif
switch ( V_385 ) {
case V_396 :
V_260 = F_136 ( V_2 , V_259 ) ;
break;
case V_397 :
V_260 = F_128 ( V_2 , V_259 ) ;
break;
default:
F_103 () ;
}
if ( V_260 < 0 )
return - V_398 ;
V_261 = F_131 ( V_2 , V_260 , V_259 ) ;
V_389 -> V_259 = V_259 ;
V_389 -> V_390 = ( V_261 & V_263 ) | ( V_259 & ~ V_263 ) ;
V_389 -> V_392 = V_259 >> V_269 ;
V_389 -> V_393 = true ;
V_389 -> V_394 = true ;
V_389 -> V_395 = true ;
return 0 ;
}
int F_214 ( struct V_1 * V_2 ,
struct V_399 * V_400 )
{
struct V_151 * V_157 ;
int V_401 , V_402 = 0 , V_403 = 0 ;
if ( ! ( V_400 -> V_404 & V_405 ) ) {
V_2 -> V_4 . V_157 . V_181 = 0 ;
V_2 -> V_27 = 0 ;
F_212 ( V_2 , V_26 , false ) ;
return 0 ;
}
F_212 ( V_2 , V_26 , true ) ;
V_2 -> V_27 = V_400 -> V_404 ;
V_2 -> V_4 . V_157 . V_181 = 0 ;
if ( V_2 -> V_27 & V_406 )
V_2 -> V_4 . V_157 . V_181 |= V_182 | V_407 ;
V_157 = & ( V_2 -> V_4 . V_157 ) ;
#ifdef V_21
V_157 -> V_408 = 0 ;
V_157 -> V_409 = 0 ;
#else
V_157 -> V_408 = V_410 | V_411 | V_412 |
V_413 ;
V_157 -> V_409 = V_414 | V_415 ;
#endif
if ( ! ( V_2 -> V_27 & V_416 ) )
return 0 ;
for ( V_401 = 0 ; V_401 < ( V_417 + V_418 ) ; V_401 ++ ) {
T_6 V_366 = V_400 -> V_4 . V_419 [ V_401 ] . V_366 ;
T_7 type = V_400 -> V_4 . V_419 [ V_401 ] . type ;
if ( type == V_420 )
continue;
if ( type & ! ( V_197 |
V_194 |
V_191 ) )
return - V_155 ;
if ( type & V_191 ) {
if ( F_210 ( V_157 , V_366 , V_402 ++ ) )
return - V_155 ;
} else {
if ( F_211 ( V_157 , V_366 ,
type , V_403 ++ ) )
return - V_155 ;
}
}
return 0 ;
}
void F_215 ( struct V_1 * V_2 , int V_421 )
{
V_2 -> V_421 = F_216 () ;
V_15 -> V_16 . V_1 = V_2 ;
}
void F_217 ( struct V_1 * V_2 )
{
V_15 -> V_16 . V_1 = NULL ;
V_2 -> V_421 = - 1 ;
F_115 () ;
}
void F_218 ( struct V_1 * V_2 )
{
V_2 -> V_267 -> V_4 . V_317 -> V_422 ( V_2 ) ;
}
int F_219 ( struct V_267 * V_267 )
{
return V_267 -> V_4 . V_317 -> V_423 ( V_267 ) ;
}
struct V_1 * F_220 ( struct V_267 * V_267 , unsigned int V_320 )
{
return V_267 -> V_4 . V_317 -> V_424 ( V_267 , V_320 ) ;
}
void F_221 ( struct V_1 * V_2 )
{
V_2 -> V_267 -> V_4 . V_317 -> V_425 ( V_2 ) ;
}
void F_222 ( struct V_267 * V_267 )
{
V_267 -> V_4 . V_317 -> V_426 ( V_267 ) ;
}
void F_223 ( struct V_1 * V_2 , int V_421 )
{
V_2 -> V_267 -> V_4 . V_317 -> V_427 ( V_2 , V_421 ) ;
}
void F_224 ( struct V_1 * V_2 )
{
V_2 -> V_267 -> V_4 . V_317 -> V_428 ( V_2 ) ;
}
int T_8 F_225 ( void )
{
#ifndef V_21
unsigned long V_93 [ 16 ] ;
unsigned long * V_429 = V_430 ;
unsigned long V_431 = 0 ;
unsigned long V_432 ;
int V_3 ;
V_433 = F_226 ( V_434 | V_435 ,
V_436 ) ;
if ( ! V_433 )
return - V_437 ;
V_93 [ 0 ] = F_114 ( V_438 ) ;
V_93 [ 1 ] = F_114 ( V_439 ) ;
V_93 [ 2 ] = F_114 ( V_440 ) ;
V_93 [ 3 ] = F_114 ( V_441 ) ;
V_93 [ 4 ] = F_114 ( V_442 ) ;
V_93 [ 5 ] = F_114 ( V_443 ) ;
V_93 [ 6 ] = F_114 ( V_444 ) ;
V_93 [ 7 ] = F_114 ( V_445 ) ;
V_93 [ 8 ] = F_114 ( V_446 ) ;
V_93 [ 9 ] = F_114 ( V_447 ) ;
V_93 [ 10 ] = F_114 ( V_448 ) ;
V_93 [ 11 ] = F_114 ( V_449 ) ;
V_93 [ 12 ] = F_114 ( V_450 ) ;
V_93 [ 13 ] = F_114 ( V_451 ) ;
V_93 [ 14 ] = F_114 ( V_452 ) ;
V_93 [ 15 ] = F_114 ( V_453 ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( V_93 [ V_3 ] > V_431 )
V_431 = V_3 ;
V_432 = V_429 [ V_3 + 1 ] - V_429 [ V_3 ] ;
memcpy ( ( void * ) V_433 + V_93 [ V_3 ] ,
( void * ) V_429 [ V_3 ] , V_432 ) ;
}
V_432 = V_429 [ V_431 + 1 ] - V_429 [ V_431 ] ;
F_227 ( V_433 , V_433 +
V_93 [ V_431 ] + V_432 ) ;
#endif
return 0 ;
}
void T_9 F_228 ( void )
{
F_229 ( V_433 , V_436 ) ;
F_230 () ;
}
