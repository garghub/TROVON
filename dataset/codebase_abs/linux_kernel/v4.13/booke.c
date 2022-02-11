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
void F_43 ( struct V_1 * V_2 )
{
F_33 ( V_2 , V_43 ) ;
}
int F_44 ( struct V_1 * V_2 )
{
return F_45 ( V_43 , & V_2 -> V_4 . V_12 ) ;
}
void F_46 ( struct V_1 * V_2 )
{
F_47 ( V_43 , & V_2 -> V_4 . V_12 ) ;
}
void F_48 ( struct V_1 * V_2 ,
struct V_44 * V_45 )
{
unsigned int V_46 = V_47 ;
if ( V_45 -> V_45 == V_48 )
V_46 = V_49 ;
F_33 ( V_2 , V_46 ) ;
}
void F_49 ( struct V_1 * V_2 )
{
F_47 ( V_47 , & V_2 -> V_4 . V_12 ) ;
F_47 ( V_49 , & V_2 -> V_4 . V_12 ) ;
}
static void F_50 ( struct V_1 * V_2 )
{
F_33 ( V_2 , V_50 ) ;
}
static void F_51 ( struct V_1 * V_2 )
{
F_47 ( V_50 , & V_2 -> V_4 . V_12 ) ;
}
void F_52 ( struct V_1 * V_2 )
{
F_33 ( V_2 , V_51 ) ;
}
void F_53 ( struct V_1 * V_2 )
{
F_47 ( V_51 , & V_2 -> V_4 . V_12 ) ;
}
static void F_54 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
F_55 ( V_2 , V_10 ) ;
F_56 ( V_2 , V_11 ) ;
}
static void F_57 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_52 = V_10 ;
V_2 -> V_4 . V_53 = V_11 ;
}
static void F_58 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
if ( F_24 ( V_54 ) ) {
V_2 -> V_4 . V_55 = V_10 ;
V_2 -> V_4 . V_56 = V_11 ;
} else {
F_57 ( V_2 , V_10 , V_11 ) ;
}
}
static void F_59 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_57 = V_10 ;
V_2 -> V_4 . V_58 = V_11 ;
}
static int F_60 ( struct V_1 * V_2 ,
unsigned int V_31 )
{
int V_59 = 0 ;
T_2 V_60 = 0 ;
bool V_61 = false , V_62 = false , V_63 = false ;
T_2 V_64 = V_2 -> V_4 . V_6 -> V_65 ;
T_2 V_66 = F_3 ( V_2 , 1 ) ;
bool V_67 ;
bool V_68 = false ;
enum V_69 V_69 ;
T_2 V_28 = V_2 -> V_4 . V_6 -> V_7 ;
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_70 ) ) {
V_64 &= 0xffffffff ;
V_66 &= 0xffffffff ;
}
V_67 = ( V_64 == V_66 ) ;
V_67 = V_67 && ! ( V_2 -> V_4 . V_6 -> V_7 & V_71 ) ;
if ( V_31 == V_49 ) {
V_31 = V_47 ;
V_68 = true ;
}
if ( ( V_31 == V_47 ) && V_2 -> V_4 . V_72 )
V_63 = true ;
switch ( V_31 ) {
case V_36 :
case V_37 :
case V_40 :
V_62 = true ;
case V_39 :
case V_41 :
V_61 = true ;
case V_38 :
case V_73 :
case V_42 :
#ifdef F_61
case V_74 :
case V_75 :
case V_76 :
#endif
#ifdef F_23
case V_77 :
case V_78 :
#endif
case V_79 :
V_59 = 1 ;
V_60 = V_80 | V_81 | V_26 ;
V_69 = V_82 ;
break;
case V_50 :
case V_83 :
case V_84 :
V_59 = V_2 -> V_4 . V_6 -> V_7 & V_80 ;
V_59 = V_59 && ! V_67 ;
V_60 = V_81 ;
V_69 = V_85 ;
break;
case V_86 :
V_59 = V_2 -> V_4 . V_6 -> V_7 & V_81 ;
V_59 = V_59 && ! V_67 ;
V_69 = V_87 ;
break;
case V_43 :
case V_88 :
V_68 = true ;
case V_47 :
case V_89 :
V_59 = V_2 -> V_4 . V_6 -> V_7 & V_90 ;
V_59 = V_59 && ! V_67 ;
V_60 = V_80 | V_81 | V_26 ;
V_69 = V_82 ;
break;
case V_51 :
V_59 = V_2 -> V_4 . V_6 -> V_7 & V_26 ;
V_59 = V_59 && ! V_67 ;
V_60 = V_81 ;
if ( F_24 ( V_54 ) )
V_69 = V_91 ;
else
V_69 = V_85 ;
break;
}
if ( V_59 ) {
switch ( V_69 ) {
case V_82 :
F_54 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_85 :
F_57 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_91 :
F_58 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_87 :
F_59 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
}
V_2 -> V_4 . V_5 = V_2 -> V_4 . V_92 | V_2 -> V_4 . V_93 [ V_31 ] ;
if ( V_61 == true )
F_62 ( V_2 , V_2 -> V_4 . V_35 ) ;
if ( V_62 == true )
F_63 ( V_2 , V_2 -> V_4 . V_34 ) ;
if ( V_63 == true ) {
if ( V_2 -> V_4 . V_72 & V_94 )
F_64 ( V_95 , V_2 ) ;
else if ( V_2 -> V_4 . V_72 & V_96 ) {
F_65 ( V_2 -> V_4 . V_97 != V_98 ) ;
F_66 ( V_2 ) ;
}
}
V_28 &= V_60 ;
#if F_21 ( V_99 )
if ( V_2 -> V_4 . V_100 & V_101 )
V_28 |= V_102 ;
#endif
F_31 ( V_2 , V_28 ) ;
if ( ! V_68 )
F_47 ( V_31 , & V_2 -> V_4 . V_12 ) ;
}
#ifdef V_21
if ( V_2 -> V_4 . V_12 & V_103 )
F_67 ( V_2 , V_82 ) ;
if ( V_2 -> V_4 . V_12 & V_104 )
F_67 ( V_2 , V_85 ) ;
if ( V_2 -> V_4 . V_12 & V_86 )
F_67 ( V_2 , V_87 ) ;
#endif
return V_59 ;
}
static unsigned long F_68 ( struct V_1 * V_2 )
{
T_3 V_105 , V_106 , V_107 = 0 ;
T_3 V_108 = 0 ;
T_1 V_109 = F_69 ( V_2 -> V_4 . V_110 ) ;
V_106 = 1ULL << ( 63 - V_109 ) ;
V_105 = F_70 () ;
if ( V_105 & V_106 )
V_107 = V_106 ;
V_107 += V_106 - ( V_105 & ( V_106 - 1 ) ) ;
V_108 = V_107 ;
if ( F_71 ( V_108 , V_111 ) )
V_108 ++ ;
return F_72 (unsigned long long, nr_jiffies, NEXT_TIMER_MAX_DELTA) ;
}
static void F_73 ( struct V_1 * V_2 )
{
unsigned long V_108 ;
unsigned long V_112 ;
if ( ( V_2 -> V_4 . V_113 & ( V_114 | V_115 ) ) != ( V_114 | V_115 ) )
F_74 ( V_116 , V_2 ) ;
F_75 ( & V_2 -> V_4 . V_117 , V_112 ) ;
V_108 = F_68 ( V_2 ) ;
if ( V_108 < V_118 )
F_76 ( & V_2 -> V_4 . V_119 , V_120 + V_108 ) ;
else
F_77 ( & V_2 -> V_4 . V_119 ) ;
F_78 ( & V_2 -> V_4 . V_117 , V_112 ) ;
}
void F_79 ( unsigned long V_121 )
{
struct V_1 * V_2 = (struct V_1 * ) V_121 ;
T_1 V_113 , V_122 ;
int V_123 ;
do {
V_122 = V_113 = V_2 -> V_4 . V_113 ;
V_123 = 0 ;
if ( V_113 & V_114 ) {
if ( V_113 & V_115 )
V_123 = 1 ;
else
V_122 = V_113 | V_115 ;
} else {
V_122 = V_113 | V_114 ;
}
} while ( F_80 ( & V_2 -> V_4 . V_113 , V_113 , V_122 ) != V_113 );
if ( V_122 & V_115 ) {
F_81 () ;
F_64 ( V_124 , V_2 ) ;
F_82 ( V_2 ) ;
}
if ( V_123 && ( V_2 -> V_4 . V_110 & V_125 ) &&
V_2 -> V_4 . V_126 ) {
F_81 () ;
F_64 ( V_116 , V_2 ) ;
F_82 ( V_2 ) ;
}
if ( ! V_123 )
F_73 ( V_2 ) ;
}
static void F_83 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 . V_110 & V_127 ) && ( V_2 -> V_4 . V_113 & V_128 ) )
F_43 ( V_2 ) ;
else
F_46 ( V_2 ) ;
if ( ( V_2 -> V_4 . V_110 & V_129 ) && ( V_2 -> V_4 . V_113 & V_115 ) )
F_50 ( V_2 ) ;
else
F_51 ( V_2 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
unsigned long * V_130 = & V_2 -> V_4 . V_12 ;
unsigned int V_31 ;
V_31 = F_85 ( * V_130 ) ;
while ( V_31 < V_131 ) {
if ( F_60 ( V_2 , V_31 ) )
break;
V_31 = F_86 ( V_130 ,
V_132 * sizeof( * V_130 ) ,
V_31 + 1 ) ;
}
V_2 -> V_4 . V_6 -> V_133 = ! ! * V_130 ;
}
int F_87 ( struct V_1 * V_2 )
{
int V_134 = 0 ;
F_88 ( ! F_89 () ) ;
F_84 ( V_2 ) ;
if ( F_90 ( V_2 ) ) {
return 1 ;
}
if ( V_2 -> V_4 . V_6 -> V_7 & V_135 ) {
F_91 () ;
F_92 ( V_2 ) ;
F_74 ( V_136 , V_2 ) ;
F_93 () ;
F_94 ( V_2 , V_137 ) ;
V_134 = 1 ;
} ;
return V_134 ;
}
int F_95 ( struct V_1 * V_2 )
{
int V_134 = 1 ;
if ( F_96 ( V_124 , V_2 ) )
F_83 ( V_2 ) ;
#if F_21 ( V_138 ) || F_21 ( V_139 )
if ( F_96 ( V_140 , V_2 ) )
F_97 ( V_2 ) ;
#endif
if ( F_96 ( V_116 , V_2 ) ) {
V_2 -> V_141 -> V_142 = V_143 ;
V_134 = 0 ;
}
if ( F_96 ( V_95 , V_2 ) ) {
V_2 -> V_141 -> V_144 . V_144 = 0 ;
V_2 -> V_4 . V_145 = true ;
V_2 -> V_141 -> V_142 = V_146 ;
V_134 = 0 ;
}
return V_134 ;
}
int F_98 ( struct V_147 * V_147 , struct V_1 * V_2 )
{
int V_148 , V_149 ;
struct V_150 V_151 ;
if ( ! V_2 -> V_4 . V_152 ) {
V_147 -> V_142 = V_153 ;
return - V_154 ;
}
V_149 = F_99 ( V_2 ) ;
if ( V_149 <= 0 ) {
V_148 = V_149 ;
goto V_155;
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
V_151 = V_2 -> V_4 . V_156 ;
F_100 ( & V_151 ) ;
V_151 = V_15 -> V_16 . V_151 ;
V_15 -> V_16 . V_151 = V_2 -> V_4 . V_156 ;
V_2 -> V_4 . V_157 = V_15 -> V_158 -> V_159 ;
F_101 () ;
V_148 = F_102 ( V_147 , V_2 ) ;
F_100 ( & V_151 ) ;
V_15 -> V_16 . V_151 = V_151 ;
#ifdef F_14
F_18 ( V_2 ) ;
#endif
#ifdef F_23
F_28 ( V_2 ) ;
#endif
V_155:
V_2 -> V_160 = V_161 ;
return V_148 ;
}
static int F_103 ( struct V_147 * V_141 , struct V_1 * V_2 )
{
enum V_162 V_163 ;
V_163 = F_104 ( V_141 , V_2 ) ;
switch ( V_163 ) {
case V_164 :
F_105 ( V_2 , V_165 ) ;
return V_166 ;
case V_167 :
return V_168 ;
case V_169 :
F_2 ( V_170 L_6 ,
V_171 , V_2 -> V_4 . V_5 , V_2 -> V_4 . V_172 ) ;
V_141 -> V_173 . V_174 = ~ 0ULL << 32 ;
V_141 -> V_173 . V_174 |= V_2 -> V_4 . V_172 ;
F_41 ( V_2 , V_175 ) ;
return V_176 ;
case V_177 :
return V_176 ;
default:
F_106 () ;
}
}
static int F_107 ( struct V_147 * V_141 , struct V_1 * V_2 )
{
struct V_150 * V_156 = & ( V_2 -> V_4 . V_156 ) ;
T_1 V_178 = V_2 -> V_4 . V_178 ;
if ( V_2 -> V_27 == 0 ) {
if ( V_178 & V_179 ) {
V_178 &= ~ V_179 ;
if ( ! V_178 )
return V_168 ;
}
if ( V_178 && ( V_2 -> V_4 . V_6 -> V_7 & V_26 ) &&
( V_2 -> V_4 . V_156 . V_180 & V_181 ) )
F_52 ( V_2 ) ;
if ( ( V_178 & V_182 ) && ! ( V_2 -> V_4 . V_6 -> V_7 & V_26 ) )
F_41 ( V_2 , V_183 ) ;
return V_168 ;
}
V_2 -> V_4 . V_178 = 0 ;
V_141 -> V_151 . V_4 . V_184 = 0 ;
V_141 -> V_151 . V_4 . V_185 = V_2 -> V_4 . V_5 ;
if ( V_178 & ( V_186 | V_187 | V_188 | V_189 ) ) {
V_141 -> V_151 . V_4 . V_184 |= V_190 ;
} else {
if ( V_178 & ( V_191 | V_192 ) )
V_141 -> V_151 . V_4 . V_184 |= V_193 ;
else if ( V_178 & ( V_194 | V_195 ) )
V_141 -> V_151 . V_4 . V_184 |= V_196 ;
if ( V_178 & ( V_194 | V_191 ) )
V_141 -> V_151 . V_4 . V_185 = V_156 -> V_197 ;
else if ( V_178 & ( V_195 | V_192 ) )
V_141 -> V_151 . V_4 . V_185 = V_156 -> V_198 ;
}
return V_176 ;
}
static void F_108 ( struct V_199 * V_17 )
{
T_2 V_200 , V_201 , V_7 , V_8 ;
asm("mr %0, 1" : "=r"(r1));
asm("mflr %0" : "=r"(lr));
asm("mfmsr %0" : "=r"(msr));
asm("bl 1f; 1: mflr %0" : "=r"(ip));
memset ( V_17 , 0 , sizeof( * V_17 ) ) ;
V_17 -> V_202 [ 1 ] = V_200 ;
V_17 -> V_203 = V_201 ;
V_17 -> V_7 = V_7 ;
V_17 -> V_204 = V_8 ;
}
static void F_109 ( struct V_1 * V_2 ,
unsigned int V_205 )
{
struct V_199 V_17 ;
switch ( V_205 ) {
case V_206 :
F_108 ( & V_17 ) ;
F_110 ( & V_17 ) ;
break;
case V_207 :
F_108 ( & V_17 ) ;
F_111 ( & V_17 ) ;
break;
#if F_21 ( V_208 )
case V_209 :
F_108 ( & V_17 ) ;
F_112 ( & V_17 ) ;
break;
#endif
case V_210 :
break;
case V_211 :
F_108 ( & V_17 ) ;
F_113 ( & V_17 ) ;
break;
case V_212 :
F_108 ( & V_17 ) ;
#ifdef F_114
F_115 ( & V_17 ) ;
#else
F_116 ( & V_17 ) ;
#endif
break;
case V_213 :
F_108 ( & V_17 ) ;
F_116 ( & V_17 ) ;
break;
case V_214 :
V_2 -> V_4 . V_178 = F_117 ( V_215 ) ;
F_118 () ;
break;
}
}
static int F_119 ( struct V_147 * V_141 , struct V_1 * V_2 ,
enum V_162 V_216 , T_1 V_172 )
{
switch ( V_216 ) {
case V_167 :
return V_168 ;
case V_169 :
F_120 ( L_7 ,
V_171 , V_2 -> V_4 . V_5 ) ;
V_141 -> V_173 . V_174 = ~ 0ULL << 32 ;
V_141 -> V_173 . V_174 |= V_172 ;
F_41 ( V_2 , V_175 ) ;
return V_176 ;
default:
F_106 () ;
}
}
int F_121 ( struct V_147 * V_141 , struct V_1 * V_2 ,
unsigned int V_205 )
{
int V_134 = V_176 ;
int V_149 ;
int V_217 ;
T_1 V_172 = V_218 ;
enum V_162 V_216 = V_164 ;
F_122 ( V_2 ) ;
F_109 ( V_2 , V_205 ) ;
switch ( V_205 ) {
case V_219 :
case V_220 :
case V_221 :
V_216 = F_123 ( V_2 , V_222 , & V_172 ) ;
break;
case V_223 :
if ( V_2 -> V_27 & V_224 )
V_216 = F_123 ( V_2 , V_222 , & V_172 ) ;
break;
default:
break;
}
F_124 ( V_205 , V_2 ) ;
F_125 () ;
F_91 () ;
V_141 -> V_142 = V_225 ;
V_141 -> V_226 = 1 ;
if ( V_216 != V_164 ) {
V_134 = F_119 ( V_141 , V_2 , V_216 , V_172 ) ;
goto V_155;
}
switch ( V_205 ) {
case V_210 :
F_2 ( L_8 , F_117 ( V_227 ) ) ;
F_1 ( V_2 ) ;
V_141 -> V_173 . V_174 = ~ 1ULL << 32 ;
V_141 -> V_173 . V_174 |= F_117 ( V_227 ) ;
V_134 = V_176 ;
break;
case V_206 :
F_126 ( V_2 , V_228 ) ;
V_134 = V_168 ;
break;
case V_207 :
F_126 ( V_2 , V_229 ) ;
V_134 = V_168 ;
break;
case V_212 :
V_134 = V_168 ;
break;
case V_209 :
F_126 ( V_2 , V_230 ) ;
V_134 = V_168 ;
break;
case V_231 :
F_126 ( V_2 , V_232 ) ;
V_134 = V_168 ;
break;
case V_233 :
F_126 ( V_2 , V_232 ) ;
V_134 = V_168 ;
break;
case V_211 :
V_134 = V_168 ;
break;
case V_221 :
V_134 = F_103 ( V_141 , V_2 ) ;
break;
case V_223 :
if ( ( V_2 -> V_27 & V_224 ) &&
( V_172 == V_234 ) ) {
V_134 = F_107 ( V_141 , V_2 ) ;
V_141 -> V_142 = V_235 ;
F_126 ( V_2 , V_236 ) ;
break;
}
if ( V_2 -> V_4 . V_6 -> V_7 & ( V_71 | V_30 ) ) {
F_41 ( V_2 , V_2 -> V_4 . V_237 ) ;
V_134 = V_168 ;
F_126 ( V_2 , V_238 ) ;
break;
}
V_134 = F_103 ( V_141 , V_2 ) ;
break;
case V_239 :
F_33 ( V_2 , V_42 ) ;
F_126 ( V_2 , V_240 ) ;
V_134 = V_168 ;
break;
#ifdef F_127
case V_241 : {
if ( V_2 -> V_4 . V_6 -> V_7 & V_14 )
F_10 ( V_2 ) ;
else
F_33 ( V_2 ,
V_74 ) ;
V_134 = V_168 ;
break;
}
case V_242 :
F_33 ( V_2 , V_75 ) ;
V_134 = V_168 ;
break;
case V_243 :
F_33 ( V_2 , V_76 ) ;
V_134 = V_168 ;
break;
#elif F_21 ( F_61 )
case V_241 :
F_41 ( V_2 , V_244 | V_245 ) ;
V_134 = V_168 ;
break;
case V_242 :
case V_243 :
F_2 ( V_170 L_9 ,
V_171 , V_205 , V_2 -> V_4 . V_5 ) ;
V_141 -> V_173 . V_174 = V_205 ;
V_134 = V_176 ;
break;
#endif
#ifdef F_23
case V_246 :
F_33 ( V_2 , V_77 ) ;
V_134 = V_168 ;
break;
case V_247 :
F_33 ( V_2 , V_78 ) ;
V_134 = V_168 ;
break;
#endif
case V_219 :
F_37 ( V_2 , V_2 -> V_4 . V_248 ,
V_2 -> V_4 . V_237 ) ;
F_126 ( V_2 , V_249 ) ;
V_134 = V_168 ;
break;
case V_250 :
F_39 ( V_2 , V_2 -> V_4 . V_237 ) ;
F_126 ( V_2 , V_251 ) ;
V_134 = V_168 ;
break;
case V_252 :
F_40 ( V_2 , V_2 -> V_4 . V_248 ,
V_2 -> V_4 . V_237 ) ;
V_134 = V_168 ;
break;
#ifdef V_21
case V_253 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_71 ) ) {
F_128 ( V_2 , 3 , F_129 ( V_2 ) ) ;
} else {
F_41 ( V_2 , V_254 ) ;
}
V_134 = V_168 ;
break;
#else
case V_255 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_71 ) &&
( ( ( T_1 ) F_3 ( V_2 , 0 ) ) == V_256 ) ) {
F_128 ( V_2 , 3 , F_129 ( V_2 ) ) ;
V_134 = V_168 ;
} else {
F_33 ( V_2 , V_73 ) ;
}
F_126 ( V_2 , V_257 ) ;
V_134 = V_168 ;
break;
#endif
case V_220 : {
unsigned long V_258 = V_2 -> V_4 . V_248 ;
int V_259 ;
T_4 V_260 ;
T_5 V_261 ;
#ifdef V_138
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_71 ) &&
( V_258 & V_262 ) == V_2 -> V_4 . V_263 ) {
F_130 ( V_2 ) ;
F_126 ( V_2 , V_264 ) ;
V_134 = V_168 ;
break;
}
#endif
V_259 = F_131 ( V_2 , V_258 ) ;
if ( V_259 < 0 ) {
F_36 ( V_2 ,
V_2 -> V_4 . V_248 ,
V_2 -> V_4 . V_237 ) ;
F_132 ( V_2 ) ;
F_126 ( V_2 , V_265 ) ;
V_134 = V_168 ;
break;
}
V_217 = F_133 ( & V_2 -> V_266 -> V_267 ) ;
V_260 = F_134 ( V_2 , V_259 , V_258 ) ;
V_261 = V_260 >> V_268 ;
if ( F_135 ( V_2 -> V_266 , V_261 ) ) {
F_136 ( V_2 , V_258 , V_260 , V_259 ) ;
F_126 ( V_2 , V_264 ) ;
V_134 = V_168 ;
} else {
V_2 -> V_4 . V_269 = V_260 ;
V_2 -> V_4 . V_270 = V_258 ;
V_134 = F_137 ( V_141 , V_2 ) ;
F_126 ( V_2 , V_271 ) ;
}
F_138 ( & V_2 -> V_266 -> V_267 , V_217 ) ;
break;
}
case V_272 : {
unsigned long V_258 = V_2 -> V_4 . V_5 ;
T_4 V_260 ;
T_5 V_261 ;
int V_259 ;
V_134 = V_168 ;
V_259 = F_139 ( V_2 , V_258 ) ;
if ( V_259 < 0 ) {
F_33 ( V_2 , V_38 ) ;
F_140 ( V_2 ) ;
F_126 ( V_2 , V_273 ) ;
break;
}
F_126 ( V_2 , V_274 ) ;
V_217 = F_133 ( & V_2 -> V_266 -> V_267 ) ;
V_260 = F_134 ( V_2 , V_259 , V_258 ) ;
V_261 = V_260 >> V_268 ;
if ( F_135 ( V_2 -> V_266 , V_261 ) ) {
F_136 ( V_2 , V_258 , V_260 , V_259 ) ;
} else {
F_33 ( V_2 , V_86 ) ;
}
F_138 ( & V_2 -> V_266 -> V_267 , V_217 ) ;
break;
}
case V_214 : {
V_134 = F_107 ( V_141 , V_2 ) ;
if ( V_134 == V_176 )
V_141 -> V_142 = V_235 ;
F_126 ( V_2 , V_236 ) ;
break;
}
default:
F_2 ( V_275 L_10 , V_205 ) ;
F_106 () ;
}
V_155:
if ( ! ( V_134 & V_176 ) ) {
V_149 = F_99 ( V_2 ) ;
if ( V_149 <= 0 )
V_134 = ( V_149 << 2 ) | V_176 | ( V_134 & V_276 ) ;
else {
F_101 () ;
F_13 ( V_2 ) ;
F_22 ( V_2 ) ;
}
}
return V_134 ;
}
static void F_141 ( struct V_1 * V_2 , T_1 V_122 )
{
T_1 V_277 = V_2 -> V_4 . V_113 ;
V_2 -> V_4 . V_113 = V_122 ;
if ( ( V_277 ^ V_2 -> V_4 . V_113 ) & ( V_114 | V_115 ) )
F_73 ( V_2 ) ;
F_83 ( V_2 ) ;
}
int F_142 ( struct V_1 * V_2 )
{
int V_3 ;
int V_134 ;
V_2 -> V_4 . V_5 = 0 ;
V_2 -> V_4 . V_6 -> V_278 = V_2 -> V_279 ;
F_128 ( V_2 , 1 , ( 16 << 20 ) - 8 ) ;
F_31 ( V_2 , 0 ) ;
#ifndef V_21
V_2 -> V_4 . V_13 = V_280 | V_281 | V_282 ;
V_2 -> V_4 . V_283 = 1 ;
V_2 -> V_4 . V_6 -> V_7 = 0 ;
#endif
V_2 -> V_4 . V_92 = 0x55550000 ;
for ( V_3 = 0 ; V_3 < V_131 ; V_3 ++ )
V_2 -> V_4 . V_93 [ V_3 ] = 0x7700 | V_3 * 4 ;
F_143 ( V_2 ) ;
V_134 = F_144 ( V_2 ) ;
F_145 ( V_2 ) ;
return V_134 ;
}
int F_146 ( struct V_1 * V_2 )
{
F_147 ( & V_2 -> V_4 . V_117 ) ;
F_148 ( & V_2 -> V_4 . V_119 , F_79 ,
( unsigned long ) V_2 ) ;
F_149 ( V_215 , V_284 ) ;
return 0 ;
}
void F_150 ( struct V_1 * V_2 )
{
F_151 ( & V_2 -> V_4 . V_119 ) ;
}
int F_152 ( struct V_1 * V_2 , struct V_285 * V_17 )
{
int V_3 ;
V_17 -> V_5 = V_2 -> V_4 . V_5 ;
V_17 -> V_286 = F_153 ( V_2 ) ;
V_17 -> V_9 = V_2 -> V_4 . V_9 ;
V_17 -> V_8 = V_2 -> V_4 . V_8 ;
V_17 -> V_287 = F_154 ( V_2 ) ;
V_17 -> V_7 = V_2 -> V_4 . V_6 -> V_7 ;
V_17 -> V_10 = F_155 ( V_2 ) ;
V_17 -> V_11 = F_156 ( V_2 ) ;
V_17 -> V_288 = V_2 -> V_4 . V_288 ;
V_17 -> V_289 = F_157 ( V_2 ) ;
V_17 -> V_290 = F_158 ( V_2 ) ;
V_17 -> V_291 = F_159 ( V_2 ) ;
V_17 -> V_292 = F_160 ( V_2 ) ;
V_17 -> V_293 = F_161 ( V_2 ) ;
V_17 -> V_294 = F_162 ( V_2 ) ;
V_17 -> V_295 = F_163 ( V_2 ) ;
V_17 -> V_296 = F_164 ( V_2 ) ;
for ( V_3 = 0 ; V_3 < F_165 ( V_17 -> V_202 ) ; V_3 ++ )
V_17 -> V_202 [ V_3 ] = F_3 ( V_2 , V_3 ) ;
return 0 ;
}
int F_166 ( struct V_1 * V_2 , struct V_285 * V_17 )
{
int V_3 ;
V_2 -> V_4 . V_5 = V_17 -> V_5 ;
F_167 ( V_2 , V_17 -> V_286 ) ;
V_2 -> V_4 . V_9 = V_17 -> V_9 ;
V_2 -> V_4 . V_8 = V_17 -> V_8 ;
F_168 ( V_2 , V_17 -> V_287 ) ;
F_31 ( V_2 , V_17 -> V_7 ) ;
F_55 ( V_2 , V_17 -> V_10 ) ;
F_56 ( V_2 , V_17 -> V_11 ) ;
F_169 ( V_2 , V_17 -> V_288 ) ;
F_170 ( V_2 , V_17 -> V_289 ) ;
F_171 ( V_2 , V_17 -> V_290 ) ;
F_172 ( V_2 , V_17 -> V_291 ) ;
F_173 ( V_2 , V_17 -> V_292 ) ;
F_174 ( V_2 , V_17 -> V_293 ) ;
F_175 ( V_2 , V_17 -> V_294 ) ;
F_176 ( V_2 , V_17 -> V_295 ) ;
F_177 ( V_2 , V_17 -> V_296 ) ;
for ( V_3 = 0 ; V_3 < F_165 ( V_17 -> V_202 ) ; V_3 ++ )
F_128 ( V_2 , V_3 , V_17 -> V_202 [ V_3 ] ) ;
return 0 ;
}
static void F_178 ( struct V_1 * V_2 ,
struct V_297 * V_298 )
{
T_3 V_105 = F_70 () ;
V_298 -> V_299 . V_300 . V_301 |= V_302 ;
V_298 -> V_299 . V_300 . V_52 = V_2 -> V_4 . V_52 ;
V_298 -> V_299 . V_300 . V_53 = V_2 -> V_4 . V_53 ;
V_298 -> V_299 . V_300 . V_303 = V_2 -> V_4 . V_303 ;
V_298 -> V_299 . V_300 . V_304 = F_179 ( V_2 ) ;
V_298 -> V_299 . V_300 . V_305 = F_180 ( V_2 ) ;
V_298 -> V_299 . V_300 . V_113 = V_2 -> V_4 . V_113 ;
V_298 -> V_299 . V_300 . V_110 = V_2 -> V_4 . V_110 ;
V_298 -> V_299 . V_300 . V_306 = F_181 ( V_2 , V_105 ) ;
V_298 -> V_299 . V_300 . V_105 = V_105 ;
V_298 -> V_299 . V_300 . V_307 = V_2 -> V_4 . V_307 ;
}
static int F_182 ( struct V_1 * V_2 ,
struct V_297 * V_298 )
{
if ( ! ( V_298 -> V_299 . V_300 . V_301 & V_302 ) )
return 0 ;
V_2 -> V_4 . V_52 = V_298 -> V_299 . V_300 . V_52 ;
V_2 -> V_4 . V_53 = V_298 -> V_299 . V_300 . V_53 ;
V_2 -> V_4 . V_303 = V_298 -> V_299 . V_300 . V_303 ;
F_62 ( V_2 , V_298 -> V_299 . V_300 . V_304 ) ;
F_63 ( V_2 , V_298 -> V_299 . V_300 . V_305 ) ;
V_2 -> V_4 . V_307 = V_298 -> V_299 . V_300 . V_307 ;
F_183 ( V_2 , V_298 -> V_299 . V_300 . V_110 ) ;
if ( V_298 -> V_299 . V_300 . V_308 & V_309 ) {
V_2 -> V_4 . V_306 = V_298 -> V_299 . V_300 . V_306 ;
F_184 ( V_2 ) ;
}
if ( V_298 -> V_299 . V_300 . V_308 & V_310 )
F_141 ( V_2 , V_298 -> V_299 . V_300 . V_113 ) ;
return 0 ;
}
static void F_185 ( struct V_1 * V_2 ,
struct V_297 * V_298 )
{
V_298 -> V_299 . V_300 . V_301 |= V_311 ;
V_298 -> V_299 . V_300 . V_278 = V_2 -> V_279 ;
V_298 -> V_299 . V_300 . V_57 = V_2 -> V_4 . V_57 ;
V_298 -> V_299 . V_300 . V_58 = V_2 -> V_4 . V_58 ;
V_298 -> V_299 . V_300 . V_312 = V_2 -> V_4 . V_312 ;
V_298 -> V_299 . V_300 . V_92 = V_2 -> V_4 . V_92 ;
}
static int F_186 ( struct V_1 * V_2 ,
struct V_297 * V_298 )
{
if ( ! ( V_298 -> V_299 . V_300 . V_301 & V_311 ) )
return 0 ;
if ( V_298 -> V_299 . V_300 . V_278 != V_2 -> V_279 )
return - V_154 ;
V_2 -> V_4 . V_57 = V_298 -> V_299 . V_300 . V_57 ;
V_2 -> V_4 . V_58 = V_298 -> V_299 . V_300 . V_58 ;
V_2 -> V_4 . V_312 = V_298 -> V_299 . V_300 . V_312 ;
V_2 -> V_4 . V_92 = V_298 -> V_299 . V_300 . V_92 ;
return 0 ;
}
int F_187 ( struct V_1 * V_2 , struct V_297 * V_298 )
{
V_298 -> V_299 . V_300 . V_301 |= V_313 ;
V_298 -> V_299 . V_300 . V_314 [ 0 ] = V_2 -> V_4 . V_93 [ V_83 ] ;
V_298 -> V_299 . V_300 . V_314 [ 1 ] = V_2 -> V_4 . V_93 [ V_86 ] ;
V_298 -> V_299 . V_300 . V_314 [ 2 ] = V_2 -> V_4 . V_93 [ V_37 ] ;
V_298 -> V_299 . V_300 . V_314 [ 3 ] = V_2 -> V_4 . V_93 [ V_39 ] ;
V_298 -> V_299 . V_300 . V_314 [ 4 ] = V_2 -> V_4 . V_93 [ V_47 ] ;
V_298 -> V_299 . V_300 . V_314 [ 5 ] = V_2 -> V_4 . V_93 [ V_40 ] ;
V_298 -> V_299 . V_300 . V_314 [ 6 ] = V_2 -> V_4 . V_93 [ V_41 ] ;
V_298 -> V_299 . V_300 . V_314 [ 7 ] = V_2 -> V_4 . V_93 [ V_42 ] ;
V_298 -> V_299 . V_300 . V_314 [ 8 ] = V_2 -> V_4 . V_93 [ V_73 ] ;
V_298 -> V_299 . V_300 . V_314 [ 9 ] = V_2 -> V_4 . V_93 [ V_79 ] ;
V_298 -> V_299 . V_300 . V_314 [ 10 ] = V_2 -> V_4 . V_93 [ V_43 ] ;
V_298 -> V_299 . V_300 . V_314 [ 11 ] = V_2 -> V_4 . V_93 [ V_88 ] ;
V_298 -> V_299 . V_300 . V_314 [ 12 ] = V_2 -> V_4 . V_93 [ V_50 ] ;
V_298 -> V_299 . V_300 . V_314 [ 13 ] = V_2 -> V_4 . V_93 [ V_36 ] ;
V_298 -> V_299 . V_300 . V_314 [ 14 ] = V_2 -> V_4 . V_93 [ V_38 ] ;
V_298 -> V_299 . V_300 . V_314 [ 15 ] = V_2 -> V_4 . V_93 [ V_51 ] ;
return 0 ;
}
int F_188 ( struct V_1 * V_2 , struct V_297 * V_298 )
{
if ( ! ( V_298 -> V_299 . V_300 . V_301 & V_313 ) )
return 0 ;
V_2 -> V_4 . V_93 [ V_83 ] = V_298 -> V_299 . V_300 . V_314 [ 0 ] ;
V_2 -> V_4 . V_93 [ V_86 ] = V_298 -> V_299 . V_300 . V_314 [ 1 ] ;
V_2 -> V_4 . V_93 [ V_37 ] = V_298 -> V_299 . V_300 . V_314 [ 2 ] ;
V_2 -> V_4 . V_93 [ V_39 ] = V_298 -> V_299 . V_300 . V_314 [ 3 ] ;
V_2 -> V_4 . V_93 [ V_47 ] = V_298 -> V_299 . V_300 . V_314 [ 4 ] ;
V_2 -> V_4 . V_93 [ V_40 ] = V_298 -> V_299 . V_300 . V_314 [ 5 ] ;
V_2 -> V_4 . V_93 [ V_41 ] = V_298 -> V_299 . V_300 . V_314 [ 6 ] ;
V_2 -> V_4 . V_93 [ V_42 ] = V_298 -> V_299 . V_300 . V_314 [ 7 ] ;
V_2 -> V_4 . V_93 [ V_73 ] = V_298 -> V_299 . V_300 . V_314 [ 8 ] ;
V_2 -> V_4 . V_93 [ V_79 ] = V_298 -> V_299 . V_300 . V_314 [ 9 ] ;
V_2 -> V_4 . V_93 [ V_43 ] = V_298 -> V_299 . V_300 . V_314 [ 10 ] ;
V_2 -> V_4 . V_93 [ V_88 ] = V_298 -> V_299 . V_300 . V_314 [ 11 ] ;
V_2 -> V_4 . V_93 [ V_50 ] = V_298 -> V_299 . V_300 . V_314 [ 12 ] ;
V_2 -> V_4 . V_93 [ V_36 ] = V_298 -> V_299 . V_300 . V_314 [ 13 ] ;
V_2 -> V_4 . V_93 [ V_38 ] = V_298 -> V_299 . V_300 . V_314 [ 14 ] ;
V_2 -> V_4 . V_93 [ V_51 ] = V_298 -> V_299 . V_300 . V_314 [ 15 ] ;
return 0 ;
}
int F_189 ( struct V_1 * V_2 ,
struct V_297 * V_298 )
{
V_298 -> V_315 = V_2 -> V_4 . V_315 ;
F_178 ( V_2 , V_298 ) ;
F_185 ( V_2 , V_298 ) ;
return V_2 -> V_266 -> V_4 . V_316 -> V_317 ( V_2 , V_298 ) ;
}
int F_190 ( struct V_1 * V_2 ,
struct V_297 * V_298 )
{
int V_148 ;
if ( V_2 -> V_4 . V_315 != V_298 -> V_315 )
return - V_154 ;
V_148 = F_182 ( V_2 , V_298 ) ;
if ( V_148 < 0 )
return V_148 ;
V_148 = F_186 ( V_2 , V_298 ) ;
if ( V_148 < 0 )
return V_148 ;
return V_2 -> V_266 -> V_4 . V_316 -> V_318 ( V_2 , V_298 ) ;
}
int F_191 ( struct V_1 * V_2 , T_3 V_319 ,
union V_320 * V_321 )
{
int V_134 = 0 ;
switch ( V_319 ) {
case V_322 :
* V_321 = F_192 ( V_319 , V_2 -> V_4 . V_156 . V_323 ) ;
break;
case V_324 :
* V_321 = F_192 ( V_319 , V_2 -> V_4 . V_156 . V_325 ) ;
break;
#if V_326 > 2
case V_327 :
* V_321 = F_192 ( V_319 , V_2 -> V_4 . V_156 . V_328 ) ;
break;
case V_329 :
* V_321 = F_192 ( V_319 , V_2 -> V_4 . V_156 . V_330 ) ;
break;
#endif
case V_331 :
* V_321 = F_192 ( V_319 , V_2 -> V_4 . V_156 . V_197 ) ;
break;
case V_332 :
* V_321 = F_192 ( V_319 , V_2 -> V_4 . V_156 . V_198 ) ;
break;
case V_333 : {
T_1 V_144 = F_193 ( V_2 ) ;
* V_321 = F_192 ( V_319 , V_144 ) ;
break;
}
#if F_21 ( V_99 )
case V_334 :
* V_321 = F_192 ( V_319 , V_2 -> V_4 . V_100 ) ;
break;
#endif
case V_335 :
* V_321 = F_192 ( V_319 , V_2 -> V_4 . V_110 ) ;
break;
case V_336 :
* V_321 = F_192 ( V_319 , V_2 -> V_4 . V_113 ) ;
break;
case V_337 :
* V_321 = F_192 ( V_319 , V_234 ) ;
break;
case V_338 :
* V_321 = F_192 ( V_319 , V_2 -> V_4 . V_307 ) ;
break;
default:
V_134 = V_2 -> V_266 -> V_4 . V_316 -> V_339 ( V_2 , V_319 , V_321 ) ;
break;
}
return V_134 ;
}
int F_194 ( struct V_1 * V_2 , T_3 V_319 ,
union V_320 * V_321 )
{
int V_134 = 0 ;
switch ( V_319 ) {
case V_322 :
V_2 -> V_4 . V_156 . V_323 = F_195 ( V_319 , * V_321 ) ;
break;
case V_324 :
V_2 -> V_4 . V_156 . V_325 = F_195 ( V_319 , * V_321 ) ;
break;
#if V_326 > 2
case V_327 :
V_2 -> V_4 . V_156 . V_328 = F_195 ( V_319 , * V_321 ) ;
break;
case V_329 :
V_2 -> V_4 . V_156 . V_330 = F_195 ( V_319 , * V_321 ) ;
break;
#endif
case V_331 :
V_2 -> V_4 . V_156 . V_197 = F_195 ( V_319 , * V_321 ) ;
break;
case V_332 :
V_2 -> V_4 . V_156 . V_198 = F_195 ( V_319 , * V_321 ) ;
break;
case V_333 : {
T_1 V_340 = F_195 ( V_319 , * V_321 ) ;
F_196 ( V_2 , V_340 ) ;
break;
}
#if F_21 ( V_99 )
case V_334 : {
T_1 V_341 = F_195 ( V_319 , * V_321 ) ;
F_197 ( V_2 , V_341 ) ;
break;
}
#endif
case V_342 : {
T_1 V_343 = F_195 ( V_319 , * V_321 ) ;
F_198 ( V_2 , V_343 ) ;
break;
}
case V_344 : {
T_1 V_343 = F_195 ( V_319 , * V_321 ) ;
F_199 ( V_2 , V_343 ) ;
break;
}
case V_336 : {
T_1 V_113 = F_195 ( V_319 , * V_321 ) ;
F_141 ( V_2 , V_113 ) ;
break;
}
case V_335 : {
T_1 V_110 = F_195 ( V_319 , * V_321 ) ;
F_183 ( V_2 , V_110 ) ;
break;
}
case V_338 :
V_2 -> V_4 . V_307 = F_195 ( V_319 , * V_321 ) ;
break;
default:
V_134 = V_2 -> V_266 -> V_4 . V_316 -> V_345 ( V_2 , V_319 , V_321 ) ;
break;
}
return V_134 ;
}
int F_200 ( struct V_1 * V_2 , struct V_346 * V_347 )
{
return - V_348 ;
}
int F_201 ( struct V_1 * V_2 , struct V_346 * V_347 )
{
return - V_348 ;
}
int F_202 ( struct V_1 * V_2 ,
struct V_349 * V_350 )
{
int V_134 ;
V_134 = F_203 ( V_2 , V_350 ) ;
return V_134 ;
}
int F_204 ( struct V_266 * V_266 , struct V_351 * log )
{
return - V_348 ;
}
void F_205 ( struct V_266 * V_266 , struct V_352 * free ,
struct V_352 * V_353 )
{
}
int F_206 ( struct V_266 * V_266 , struct V_352 * V_354 ,
unsigned long V_355 )
{
return 0 ;
}
int F_207 ( struct V_266 * V_266 ,
struct V_352 * V_356 ,
const struct V_357 * V_358 )
{
return 0 ;
}
void F_208 ( struct V_266 * V_266 ,
const struct V_357 * V_358 ,
const struct V_352 * V_359 ,
const struct V_352 * V_360 )
{
}
void F_209 ( struct V_266 * V_266 , struct V_352 * V_356 )
{
}
void F_197 ( struct V_1 * V_2 , T_1 V_341 )
{
#if F_21 ( V_99 )
V_2 -> V_4 . V_100 = V_341 ;
#ifdef V_21
V_2 -> V_4 . V_361 &= ~ V_362 ;
if ( V_2 -> V_4 . V_100 & V_101 )
V_2 -> V_4 . V_361 |= V_362 ;
#endif
#endif
}
void F_183 ( struct V_1 * V_2 , T_1 V_363 )
{
V_2 -> V_4 . V_110 = V_363 ;
F_73 ( V_2 ) ;
F_83 ( V_2 ) ;
}
void F_198 ( struct V_1 * V_2 , T_1 V_343 )
{
F_210 ( V_343 , & V_2 -> V_4 . V_113 ) ;
F_81 () ;
F_64 ( V_124 , V_2 ) ;
F_82 ( V_2 ) ;
}
void F_199 ( struct V_1 * V_2 , T_1 V_343 )
{
F_211 ( V_343 , & V_2 -> V_4 . V_113 ) ;
if ( V_343 & ( V_114 | V_115 ) )
F_73 ( V_2 ) ;
F_83 ( V_2 ) ;
}
void F_212 ( struct V_1 * V_2 )
{
if ( V_2 -> V_4 . V_110 & V_364 ) {
V_2 -> V_4 . V_306 = V_2 -> V_4 . V_312 ;
F_184 ( V_2 ) ;
}
F_198 ( V_2 , V_128 ) ;
}
static int F_213 ( struct V_150 * V_156 ,
T_6 V_365 , int V_366 )
{
switch ( V_366 ) {
case 0 :
V_156 -> V_180 |= V_367 ;
V_156 -> V_323 = V_365 ;
break;
case 1 :
V_156 -> V_180 |= V_368 ;
V_156 -> V_325 = V_365 ;
break;
#if V_326 > 2
case 2 :
V_156 -> V_180 |= V_369 ;
V_156 -> V_328 = V_365 ;
break;
case 3 :
V_156 -> V_180 |= V_370 ;
V_156 -> V_330 = V_365 ;
break;
#endif
default:
return - V_154 ;
}
V_156 -> V_180 |= V_181 ;
return 0 ;
}
static int F_214 ( struct V_150 * V_156 , T_6 V_365 ,
int type , int V_366 )
{
switch ( V_366 ) {
case 0 :
if ( type & V_196 )
V_156 -> V_180 |= V_371 ;
if ( type & V_193 )
V_156 -> V_180 |= V_372 ;
V_156 -> V_197 = V_365 ;
break;
case 1 :
if ( type & V_196 )
V_156 -> V_180 |= V_373 ;
if ( type & V_193 )
V_156 -> V_180 |= V_374 ;
V_156 -> V_198 = V_365 ;
break;
default:
return - V_154 ;
}
V_156 -> V_180 |= V_181 ;
return 0 ;
}
void F_215 ( struct V_1 * V_2 , T_2 V_375 , bool V_376 )
{
#ifdef V_21
F_65 ( V_375 & ~ ( V_377 | V_378 | V_379 ) ) ;
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
int F_216 ( struct V_1 * V_2 , T_2 V_258 , enum V_383 V_384 ,
enum V_385 V_386 , struct V_387 * V_388 )
{
int V_259 ;
T_4 V_260 ;
#ifdef V_138
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_71 ) &&
( V_258 & V_262 ) == V_2 -> V_4 . V_263 ) {
V_388 -> V_258 = V_258 ;
V_388 -> V_389 = ( V_2 -> V_4 . V_390 & V_262 ) |
( V_258 & ~ V_262 ) ;
V_388 -> V_391 = V_258 >> V_268 ;
V_388 -> V_392 = true ;
V_388 -> V_393 = true ;
V_388 -> V_394 = true ;
return 0 ;
}
#endif
switch ( V_384 ) {
case V_395 :
V_259 = F_139 ( V_2 , V_258 ) ;
break;
case V_396 :
V_259 = F_131 ( V_2 , V_258 ) ;
break;
default:
F_106 () ;
}
if ( V_259 < 0 )
return - V_397 ;
V_260 = F_134 ( V_2 , V_259 , V_258 ) ;
V_388 -> V_258 = V_258 ;
V_388 -> V_389 = ( V_260 & V_262 ) | ( V_258 & ~ V_262 ) ;
V_388 -> V_391 = V_258 >> V_268 ;
V_388 -> V_392 = true ;
V_388 -> V_393 = true ;
V_388 -> V_394 = true ;
return 0 ;
}
int F_217 ( struct V_1 * V_2 ,
struct V_398 * V_399 )
{
struct V_150 * V_156 ;
int V_400 , V_401 = 0 , V_402 = 0 ;
if ( ! ( V_399 -> V_403 & V_404 ) ) {
V_2 -> V_4 . V_156 . V_180 = 0 ;
V_2 -> V_27 = 0 ;
F_215 ( V_2 , V_26 , false ) ;
return 0 ;
}
F_215 ( V_2 , V_26 , true ) ;
V_2 -> V_27 = V_399 -> V_403 ;
V_2 -> V_4 . V_156 . V_180 = 0 ;
if ( V_2 -> V_27 & V_405 )
V_2 -> V_4 . V_156 . V_180 |= V_181 | V_406 ;
V_156 = & ( V_2 -> V_4 . V_156 ) ;
#ifdef V_21
V_156 -> V_407 = 0 ;
V_156 -> V_408 = 0 ;
#else
V_156 -> V_407 = V_409 | V_410 | V_411 |
V_412 ;
V_156 -> V_408 = V_413 | V_414 ;
#endif
if ( ! ( V_2 -> V_27 & V_415 ) )
return 0 ;
for ( V_400 = 0 ; V_400 < ( V_416 + V_417 ) ; V_400 ++ ) {
T_6 V_365 = V_399 -> V_4 . V_418 [ V_400 ] . V_365 ;
T_7 type = V_399 -> V_4 . V_418 [ V_400 ] . type ;
if ( type == V_419 )
continue;
if ( type & ~ ( V_196 |
V_193 |
V_190 ) )
return - V_154 ;
if ( type & V_190 ) {
if ( F_213 ( V_156 , V_365 , V_401 ++ ) )
return - V_154 ;
} else {
if ( F_214 ( V_156 , V_365 ,
type , V_402 ++ ) )
return - V_154 ;
}
}
return 0 ;
}
void F_218 ( struct V_1 * V_2 , int V_420 )
{
V_2 -> V_420 = F_219 () ;
V_15 -> V_16 . V_1 = V_2 ;
}
void F_220 ( struct V_1 * V_2 )
{
V_15 -> V_16 . V_1 = NULL ;
V_2 -> V_420 = - 1 ;
F_118 () ;
}
void F_221 ( struct V_1 * V_2 )
{
V_2 -> V_266 -> V_4 . V_316 -> V_421 ( V_2 ) ;
}
int F_222 ( struct V_266 * V_266 )
{
return V_266 -> V_4 . V_316 -> V_422 ( V_266 ) ;
}
struct V_1 * F_223 ( struct V_266 * V_266 , unsigned int V_319 )
{
return V_266 -> V_4 . V_316 -> V_423 ( V_266 , V_319 ) ;
}
void F_224 ( struct V_1 * V_2 )
{
V_2 -> V_266 -> V_4 . V_316 -> V_424 ( V_2 ) ;
}
void F_225 ( struct V_266 * V_266 )
{
V_266 -> V_4 . V_316 -> V_425 ( V_266 ) ;
}
void F_226 ( struct V_1 * V_2 , int V_420 )
{
V_2 -> V_266 -> V_4 . V_316 -> V_426 ( V_2 , V_420 ) ;
}
void F_227 ( struct V_1 * V_2 )
{
V_2 -> V_266 -> V_4 . V_316 -> V_427 ( V_2 ) ;
}
int T_8 F_228 ( void )
{
#ifndef V_21
unsigned long V_93 [ 16 ] ;
unsigned long * V_428 = V_429 ;
unsigned long V_430 = 0 ;
unsigned long V_431 ;
int V_3 ;
V_432 = F_229 ( V_433 | V_434 ,
V_435 ) ;
if ( ! V_432 )
return - V_436 ;
V_93 [ 0 ] = F_117 ( V_437 ) ;
V_93 [ 1 ] = F_117 ( V_438 ) ;
V_93 [ 2 ] = F_117 ( V_439 ) ;
V_93 [ 3 ] = F_117 ( V_440 ) ;
V_93 [ 4 ] = F_117 ( V_441 ) ;
V_93 [ 5 ] = F_117 ( V_442 ) ;
V_93 [ 6 ] = F_117 ( V_443 ) ;
V_93 [ 7 ] = F_117 ( V_444 ) ;
V_93 [ 8 ] = F_117 ( V_445 ) ;
V_93 [ 9 ] = F_117 ( V_446 ) ;
V_93 [ 10 ] = F_117 ( V_447 ) ;
V_93 [ 11 ] = F_117 ( V_448 ) ;
V_93 [ 12 ] = F_117 ( V_449 ) ;
V_93 [ 13 ] = F_117 ( V_450 ) ;
V_93 [ 14 ] = F_117 ( V_451 ) ;
V_93 [ 15 ] = F_117 ( V_452 ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( V_93 [ V_3 ] > V_430 )
V_430 = V_3 ;
V_431 = V_428 [ V_3 + 1 ] - V_428 [ V_3 ] ;
memcpy ( ( void * ) V_432 + V_93 [ V_3 ] ,
( void * ) V_428 [ V_3 ] , V_431 ) ;
}
V_431 = V_428 [ V_430 + 1 ] - V_428 [ V_430 ] ;
F_230 ( V_432 , V_432 +
V_93 [ V_430 ] + V_431 ) ;
#endif
return 0 ;
}
void T_9 F_231 ( void )
{
F_232 ( V_432 , V_435 ) ;
F_233 () ;
}
