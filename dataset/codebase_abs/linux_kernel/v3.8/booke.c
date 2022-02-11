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
void F_22 ( struct V_1 * V_2 , T_2 V_23 )
{
V_2 -> V_4 . V_25 = V_23 ;
F_16 ( V_2 , V_29 ) ;
}
void F_23 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_30 ) ;
}
int F_24 ( struct V_1 * V_2 )
{
return F_25 ( V_30 , & V_2 -> V_4 . V_12 ) ;
}
void F_26 ( struct V_1 * V_2 )
{
F_27 ( V_30 , & V_2 -> V_4 . V_12 ) ;
}
void F_28 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
unsigned int V_33 = V_34 ;
if ( V_32 -> V_32 == V_35 )
V_33 = V_36 ;
F_16 ( V_2 , V_33 ) ;
}
void F_29 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
F_27 ( V_34 , & V_2 -> V_4 . V_12 ) ;
F_27 ( V_36 , & V_2 -> V_4 . V_12 ) ;
}
static void F_30 ( struct V_1 * V_2 )
{
F_16 ( V_2 , V_37 ) ;
}
static void F_31 ( struct V_1 * V_2 )
{
F_27 ( V_37 , & V_2 -> V_4 . V_12 ) ;
}
static void F_32 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
#ifdef V_16
F_33 ( V_38 , V_10 ) ;
F_33 ( V_39 , V_11 ) ;
#else
V_2 -> V_4 . V_6 -> V_10 = V_10 ;
V_2 -> V_4 . V_6 -> V_11 = V_11 ;
#endif
}
static void F_34 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_40 = V_10 ;
V_2 -> V_4 . V_41 = V_11 ;
}
static void F_35 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
if ( F_36 ( V_42 ) ) {
V_2 -> V_4 . V_43 = V_10 ;
V_2 -> V_4 . V_44 = V_11 ;
} else {
F_34 ( V_2 , V_10 , V_11 ) ;
}
}
static void F_37 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_45 = V_10 ;
V_2 -> V_4 . V_46 = V_11 ;
}
static unsigned long F_38 ( struct V_1 * V_2 )
{
#ifdef V_16
return F_39 ( V_47 ) ;
#else
return V_2 -> V_4 . V_6 -> V_48 ;
#endif
}
static void F_40 ( struct V_1 * V_2 , unsigned long V_49 )
{
#ifdef V_16
F_33 ( V_47 , V_49 ) ;
#else
V_2 -> V_4 . V_6 -> V_48 = V_49 ;
#endif
}
static unsigned long F_41 ( struct V_1 * V_2 )
{
#ifdef V_16
return F_39 ( V_50 ) ;
#else
return V_2 -> V_4 . V_6 -> V_51 ;
#endif
}
static void F_42 ( struct V_1 * V_2 , T_1 V_51 )
{
#ifdef V_16
F_33 ( V_50 , V_51 ) ;
#else
V_2 -> V_4 . V_6 -> V_51 = V_51 ;
#endif
}
static int F_43 ( struct V_1 * V_2 ,
unsigned int V_21 )
{
int V_52 = 0 ;
T_2 V_53 = 0 ;
bool V_54 = false , V_55 = false ;
T_2 V_56 = V_2 -> V_4 . V_6 -> V_57 ;
T_2 V_58 = F_3 ( V_2 , 1 ) ;
bool V_59 ;
bool V_60 = false ;
enum V_61 V_61 ;
T_2 V_18 = V_2 -> V_4 . V_6 -> V_7 ;
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_62 ) ) {
V_56 &= 0xffffffff ;
V_58 &= 0xffffffff ;
}
V_59 = ( V_56 == V_58 ) ;
V_59 = V_59 && ! ( V_2 -> V_4 . V_6 -> V_7 & V_63 ) ;
if ( V_21 == V_36 ) {
V_21 = V_34 ;
V_60 = true ;
}
switch ( V_21 ) {
case V_26 :
case V_27 :
V_55 = true ;
case V_28 :
case V_29 :
V_54 = true ;
case V_64 :
case V_65 :
case V_66 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
case V_71 :
V_52 = 1 ;
V_53 = V_72 | V_73 | V_74 ;
V_61 = V_75 ;
break;
case V_37 :
case V_76 :
case V_77 :
V_52 = V_2 -> V_4 . V_6 -> V_7 & V_72 ;
V_52 = V_52 && ! V_59 ;
V_53 = V_73 ;
V_61 = V_78 ;
break;
case V_79 :
V_52 = V_2 -> V_4 . V_6 -> V_7 & V_73 ;
V_52 = V_52 && ! V_59 ;
V_61 = V_80 ;
break;
case V_30 :
case V_81 :
V_60 = true ;
case V_34 :
case V_82 :
V_52 = V_2 -> V_4 . V_6 -> V_7 & V_83 ;
V_52 = V_52 && ! V_59 ;
V_53 = V_72 | V_73 | V_74 ;
V_61 = V_75 ;
break;
case V_84 :
V_52 = V_2 -> V_4 . V_6 -> V_7 & V_74 ;
V_52 = V_52 && ! V_59 ;
V_53 = V_73 ;
V_61 = V_78 ;
break;
}
if ( V_52 ) {
switch ( V_61 ) {
case V_75 :
F_32 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_78 :
F_34 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_85 :
F_35 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_80 :
F_37 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
}
V_2 -> V_4 . V_5 = V_2 -> V_4 . V_86 | V_2 -> V_4 . V_87 [ V_21 ] ;
if ( V_54 == true )
F_42 ( V_2 , V_2 -> V_4 . V_25 ) ;
if ( V_55 == true )
F_40 ( V_2 , V_2 -> V_4 . V_24 ) ;
V_18 &= V_53 ;
#if F_13 ( V_88 )
if ( V_2 -> V_4 . V_89 & V_90 )
V_18 |= V_91 ;
#endif
F_14 ( V_2 , V_18 ) ;
if ( ! V_60 )
F_27 ( V_21 , & V_2 -> V_4 . V_12 ) ;
}
#ifdef V_16
if ( V_2 -> V_4 . V_12 & V_92 )
F_44 ( V_2 , V_75 ) ;
if ( V_2 -> V_4 . V_12 & V_93 )
F_44 ( V_2 , V_78 ) ;
if ( V_2 -> V_4 . V_12 & V_79 )
F_44 ( V_2 , V_80 ) ;
#endif
return V_52 ;
}
static unsigned long F_45 ( struct V_1 * V_2 )
{
T_3 V_94 , V_95 , V_96 = 0 ;
T_3 V_97 = 0 ;
T_1 V_98 = F_46 ( V_2 -> V_4 . V_99 ) ;
V_95 = 1ULL << ( 63 - V_98 ) ;
V_94 = F_47 () ;
if ( V_94 & V_95 )
V_96 = V_95 ;
V_96 += V_95 - ( V_94 & ( V_95 - 1 ) ) ;
V_97 = V_96 ;
if ( F_48 ( V_97 , V_100 ) )
V_97 ++ ;
return F_49 (unsigned long long, nr_jiffies, NEXT_TIMER_MAX_DELTA) ;
}
static void F_50 ( struct V_1 * V_2 )
{
unsigned long V_97 ;
unsigned long V_101 ;
if ( ( V_2 -> V_4 . V_102 & ( V_103 | V_104 ) ) != ( V_103 | V_104 ) )
F_27 ( V_105 , & V_2 -> V_106 ) ;
F_51 ( & V_2 -> V_4 . V_107 , V_101 ) ;
V_97 = F_45 ( V_2 ) ;
if ( V_97 < V_108 )
F_52 ( & V_2 -> V_4 . V_109 , V_110 + V_97 ) ;
else
F_53 ( & V_2 -> V_4 . V_109 ) ;
F_54 ( & V_2 -> V_4 . V_107 , V_101 ) ;
}
void F_55 ( unsigned long V_111 )
{
struct V_1 * V_2 = (struct V_1 * ) V_111 ;
T_1 V_102 , V_112 ;
int V_113 ;
do {
V_112 = V_102 = V_2 -> V_4 . V_102 ;
V_113 = 0 ;
if ( V_102 & V_103 ) {
if ( V_102 & V_104 )
V_113 = 1 ;
else
V_112 = V_102 | V_104 ;
} else {
V_112 = V_102 | V_103 ;
}
} while ( F_56 ( & V_2 -> V_4 . V_102 , V_102 , V_112 ) != V_102 );
if ( V_112 & V_104 ) {
F_57 () ;
F_58 ( V_114 , V_2 ) ;
F_59 ( V_2 ) ;
}
if ( V_113 && ( V_2 -> V_4 . V_99 & V_115 ) &&
V_2 -> V_4 . V_116 ) {
F_57 () ;
F_58 ( V_105 , V_2 ) ;
F_59 ( V_2 ) ;
}
if ( ! V_113 )
F_50 ( V_2 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 . V_99 & V_117 ) && ( V_2 -> V_4 . V_102 & V_118 ) )
F_23 ( V_2 ) ;
else
F_26 ( V_2 ) ;
if ( ( V_2 -> V_4 . V_99 & V_119 ) && ( V_2 -> V_4 . V_102 & V_104 ) )
F_30 ( V_2 ) ;
else
F_31 ( V_2 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
unsigned long * V_120 = & V_2 -> V_4 . V_12 ;
unsigned int V_21 ;
V_21 = F_62 ( * V_120 ) ;
while ( V_21 < V_121 ) {
if ( F_43 ( V_2 , V_21 ) )
break;
V_21 = F_63 ( V_120 ,
V_122 * sizeof( * V_120 ) ,
V_21 + 1 ) ;
}
V_2 -> V_4 . V_6 -> V_123 = ! ! * V_120 ;
}
int F_64 ( struct V_1 * V_2 )
{
int V_124 = 0 ;
F_65 ( ! F_66 () ) ;
F_61 ( V_2 ) ;
if ( V_2 -> V_4 . V_6 -> V_7 & V_125 ) {
F_67 () ;
F_68 ( V_2 ) ;
F_27 ( V_126 , & V_2 -> V_106 ) ;
F_69 () ;
F_70 ( V_2 , V_127 ) ;
V_124 = 1 ;
} ;
return V_124 ;
}
int F_71 ( struct V_1 * V_2 )
{
int V_124 = 1 ;
if ( F_72 ( V_114 , V_2 ) )
F_60 ( V_2 ) ;
#if F_13 ( V_128 ) || F_13 ( V_129 )
if ( F_72 ( V_130 , V_2 ) )
F_73 ( V_2 ) ;
#endif
if ( F_72 ( V_105 , V_2 ) ) {
V_2 -> V_131 -> V_132 = V_133 ;
V_124 = 0 ;
}
return V_124 ;
}
int F_74 ( struct V_134 * V_134 , struct V_1 * V_2 )
{
int V_135 , V_136 ;
#ifdef V_15
unsigned int V_137 ;
int V_138 ;
T_3 V_139 [ 32 ] ;
#endif
if ( ! V_2 -> V_4 . V_140 ) {
V_134 -> V_132 = V_141 ;
return - V_142 ;
}
F_69 () ;
V_136 = F_75 ( V_2 ) ;
if ( V_136 <= 0 ) {
F_67 () ;
V_135 = V_136 ;
goto V_143;
}
F_76 () ;
F_77 () ;
#ifdef V_15
F_78 () ;
memcpy ( V_139 , V_144 -> V_145 . V_139 , sizeof( V_144 -> V_145 . V_139 ) ) ;
V_137 = V_144 -> V_145 . V_137 . V_146 ;
V_138 = V_144 -> V_145 . V_138 ;
memcpy ( V_144 -> V_145 . V_139 , V_2 -> V_4 . V_139 , sizeof( V_2 -> V_4 . V_139 ) ) ;
V_144 -> V_145 . V_137 . V_146 = V_2 -> V_4 . V_137 ;
V_2 -> V_147 = 1 ;
F_79 ( V_2 ) ;
#endif
V_135 = F_80 ( V_134 , V_2 ) ;
#ifdef V_15
F_81 ( V_2 ) ;
V_2 -> V_147 = 0 ;
memcpy ( V_2 -> V_4 . V_139 , V_144 -> V_145 . V_139 , sizeof( V_2 -> V_4 . V_139 ) ) ;
V_2 -> V_4 . V_137 = V_144 -> V_145 . V_137 . V_146 ;
memcpy ( V_144 -> V_145 . V_139 , V_139 , sizeof( V_144 -> V_145 . V_139 ) ) ;
V_144 -> V_145 . V_137 . V_146 = V_137 ;
V_144 -> V_145 . V_138 = V_138 ;
#endif
V_143:
V_2 -> V_148 = V_149 ;
return V_135 ;
}
static int F_82 ( struct V_134 * V_131 , struct V_1 * V_2 )
{
enum V_150 V_151 ;
V_151 = F_83 ( V_131 , V_2 ) ;
switch ( V_151 ) {
case V_152 :
F_84 ( V_2 , V_153 ) ;
return V_154 ;
case V_155 :
V_131 -> V_132 = V_156 ;
return V_157 ;
case V_158 :
F_2 ( V_159 L_6 ,
V_160 , V_2 -> V_4 . V_5 , V_2 -> V_4 . V_161 ) ;
V_131 -> V_162 . V_163 = ~ 0ULL << 32 ;
V_131 -> V_162 . V_163 |= V_2 -> V_4 . V_161 ;
F_22 ( V_2 , V_164 ) ;
return V_157 ;
default:
F_85 () ;
}
}
static void F_86 ( struct V_165 * V_166 )
{
T_2 V_167 , V_168 , V_7 , V_8 ;
asm("mr %0, 1" : "=r"(r1));
asm("mflr %0" : "=r"(lr));
asm("mfmsr %0" : "=r"(msr));
asm("bl 1f; 1: mflr %0" : "=r"(ip));
memset ( V_166 , 0 , sizeof( * V_166 ) ) ;
V_166 -> V_169 [ 1 ] = V_167 ;
V_166 -> V_170 = V_168 ;
V_166 -> V_7 = V_7 ;
V_166 -> V_171 = V_8 ;
}
static void F_87 ( struct V_1 * V_2 ,
unsigned int V_172 )
{
struct V_165 V_166 ;
switch ( V_172 ) {
case V_173 :
F_86 ( & V_166 ) ;
F_88 ( & V_166 ) ;
break;
case V_174 :
F_86 ( & V_166 ) ;
F_89 ( & V_166 ) ;
break;
#if F_13 ( V_175 ) || F_13 ( V_176 )
case V_177 :
F_86 ( & V_166 ) ;
F_90 ( & V_166 ) ;
break;
#endif
case V_178 :
break;
case V_179 :
F_86 ( & V_166 ) ;
F_91 ( & V_166 ) ;
break;
case V_180 :
F_86 ( & V_166 ) ;
#ifdef F_92
F_93 ( & V_166 ) ;
#else
F_94 ( & V_166 ) ;
#endif
break;
case V_181 :
F_94 ( & V_166 ) ;
break;
}
}
int F_95 ( struct V_134 * V_131 , struct V_1 * V_2 ,
unsigned int V_172 )
{
int V_124 = V_157 ;
int V_136 ;
F_96 ( V_2 ) ;
F_87 ( V_2 , V_172 ) ;
F_67 () ;
F_97 ( V_172 , V_2 ) ;
F_98 () ;
V_131 -> V_132 = V_182 ;
V_131 -> V_183 = 1 ;
switch ( V_172 ) {
case V_178 :
F_2 ( L_7 , F_39 ( V_184 ) ) ;
F_1 ( V_2 ) ;
V_131 -> V_162 . V_163 = ~ 1ULL << 32 ;
V_131 -> V_162 . V_163 |= F_39 ( V_184 ) ;
V_124 = V_157 ;
break;
case V_173 :
F_99 ( V_2 , V_185 ) ;
V_124 = V_186 ;
break;
case V_174 :
F_99 ( V_2 , V_187 ) ;
V_124 = V_186 ;
break;
case V_180 :
V_124 = V_186 ;
break;
case V_177 :
F_99 ( V_2 , V_188 ) ;
V_124 = V_186 ;
break;
case V_189 :
F_99 ( V_2 , V_190 ) ;
V_124 = V_186 ;
break;
case V_191 :
F_99 ( V_2 , V_190 ) ;
V_124 = V_186 ;
break;
case V_179 :
V_124 = V_186 ;
break;
case V_192 :
V_124 = F_82 ( V_131 , V_2 ) ;
break;
case V_193 :
if ( V_2 -> V_4 . V_6 -> V_7 & ( V_63 | V_20 ) ) {
F_22 ( V_2 , V_2 -> V_4 . V_194 ) ;
V_124 = V_186 ;
F_99 ( V_2 , V_195 ) ;
break;
}
V_124 = F_82 ( V_131 , V_2 ) ;
break;
case V_196 :
F_16 ( V_2 , V_66 ) ;
F_99 ( V_2 , V_197 ) ;
V_124 = V_186 ;
break;
#ifdef F_100
case V_198 : {
if ( V_2 -> V_4 . V_6 -> V_7 & V_14 )
F_9 ( V_2 ) ;
else
F_16 ( V_2 ,
V_67 ) ;
V_124 = V_186 ;
break;
}
case V_199 :
F_16 ( V_2 , V_68 ) ;
V_124 = V_186 ;
break;
case V_200 :
F_16 ( V_2 , V_69 ) ;
V_124 = V_186 ;
break;
#else
case V_198 :
F_22 ( V_2 , V_201 | V_202 ) ;
V_124 = V_186 ;
break;
case V_199 :
case V_200 :
F_2 ( V_159 L_8 ,
V_160 , V_172 , V_2 -> V_4 . V_5 ) ;
V_131 -> V_162 . V_163 = V_172 ;
V_124 = V_157 ;
break;
#endif
case V_203 :
F_20 ( V_2 , V_2 -> V_4 . V_204 ,
V_2 -> V_4 . V_194 ) ;
F_99 ( V_2 , V_205 ) ;
V_124 = V_186 ;
break;
case V_206 :
F_21 ( V_2 , V_2 -> V_4 . V_194 ) ;
F_99 ( V_2 , V_207 ) ;
V_124 = V_186 ;
break;
#ifdef V_16
case V_208 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_63 ) ) {
F_101 ( V_2 , 3 , F_102 ( V_2 ) ) ;
} else {
F_22 ( V_2 , V_209 ) ;
}
V_124 = V_186 ;
break;
#else
case V_210 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_63 ) &&
( ( ( T_1 ) F_3 ( V_2 , 0 ) ) == V_211 ) ) {
F_101 ( V_2 , 3 , F_102 ( V_2 ) ) ;
V_124 = V_186 ;
} else {
F_16 ( V_2 , V_65 ) ;
}
F_99 ( V_2 , V_212 ) ;
V_124 = V_186 ;
break;
#endif
case V_213 : {
unsigned long V_214 = V_2 -> V_4 . V_204 ;
int V_215 ;
T_4 V_216 ;
T_5 V_217 ;
#ifdef V_128
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_63 ) &&
( V_214 & V_218 ) == V_2 -> V_4 . V_219 ) {
F_103 ( V_2 ) ;
F_99 ( V_2 , V_220 ) ;
V_124 = V_186 ;
break;
}
#endif
V_215 = F_104 ( V_2 , V_214 ) ;
if ( V_215 < 0 ) {
F_19 ( V_2 ,
V_2 -> V_4 . V_204 ,
V_2 -> V_4 . V_194 ) ;
F_105 ( V_2 ) ;
F_99 ( V_2 , V_221 ) ;
V_124 = V_186 ;
break;
}
V_216 = F_106 ( V_2 , V_215 , V_214 ) ;
V_217 = V_216 >> V_222 ;
if ( F_107 ( V_2 -> V_223 , V_217 ) ) {
F_108 ( V_2 , V_214 , V_216 , V_215 ) ;
F_99 ( V_2 , V_220 ) ;
V_124 = V_186 ;
} else {
V_2 -> V_4 . V_224 = V_216 ;
V_2 -> V_4 . V_225 = V_214 ;
V_124 = F_109 ( V_131 , V_2 ) ;
F_99 ( V_2 , V_226 ) ;
}
break;
}
case V_227 : {
unsigned long V_214 = V_2 -> V_4 . V_5 ;
T_4 V_216 ;
T_5 V_217 ;
int V_215 ;
V_124 = V_186 ;
V_215 = F_110 ( V_2 , V_214 ) ;
if ( V_215 < 0 ) {
F_16 ( V_2 , V_64 ) ;
F_111 ( V_2 ) ;
F_99 ( V_2 , V_228 ) ;
break;
}
F_99 ( V_2 , V_229 ) ;
V_216 = F_106 ( V_2 , V_215 , V_214 ) ;
V_217 = V_216 >> V_222 ;
if ( F_107 ( V_2 -> V_223 , V_217 ) ) {
F_108 ( V_2 , V_214 , V_216 , V_215 ) ;
} else {
F_16 ( V_2 , V_79 ) ;
}
break;
}
case V_230 : {
T_1 V_231 ;
V_2 -> V_4 . V_5 = F_39 ( V_232 ) ;
V_231 = F_39 ( V_233 ) ;
V_231 &= V_234 | V_235 | V_236 | V_237 ;
F_33 ( V_233 , V_231 ) ;
V_131 -> V_132 = V_238 ;
F_99 ( V_2 , V_239 ) ;
V_124 = V_157 ;
break;
}
default:
F_2 ( V_240 L_9 , V_172 ) ;
F_85 () ;
}
if ( ! ( V_124 & V_157 ) ) {
F_69 () ;
V_136 = F_75 ( V_2 ) ;
if ( V_136 <= 0 ) {
F_67 () ;
V_124 = ( V_136 << 2 ) | V_157 | ( V_124 & V_241 ) ;
} else {
F_76 () ;
}
}
return V_124 ;
}
int F_112 ( struct V_1 * V_2 )
{
int V_3 ;
int V_124 ;
V_2 -> V_4 . V_5 = 0 ;
V_2 -> V_4 . V_6 -> V_242 = V_2 -> V_243 ;
F_101 ( V_2 , 1 , ( 16 << 20 ) - 8 ) ;
F_14 ( V_2 , 0 ) ;
#ifndef V_16
V_2 -> V_4 . V_13 = V_244 | V_74 | V_245 | V_246 ;
V_2 -> V_4 . V_247 = 1 ;
V_2 -> V_4 . V_6 -> V_7 = 0 ;
#endif
V_2 -> V_4 . V_86 = 0x55550000 ;
for ( V_3 = 0 ; V_3 < V_121 ; V_3 ++ )
V_2 -> V_4 . V_87 [ V_3 ] = 0x7700 | V_3 * 4 ;
F_113 ( V_2 ) ;
V_124 = F_114 ( V_2 ) ;
F_115 ( V_2 ) ;
return V_124 ;
}
int F_116 ( struct V_1 * V_2 )
{
F_117 ( & V_2 -> V_4 . V_107 ) ;
F_118 ( & V_2 -> V_4 . V_109 , F_55 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_119 ( struct V_1 * V_2 )
{
F_120 ( & V_2 -> V_4 . V_109 ) ;
}
int F_121 ( struct V_1 * V_2 , struct V_248 * V_166 )
{
int V_3 ;
V_166 -> V_5 = V_2 -> V_4 . V_5 ;
V_166 -> V_249 = F_122 ( V_2 ) ;
V_166 -> V_9 = V_2 -> V_4 . V_9 ;
V_166 -> V_8 = V_2 -> V_4 . V_8 ;
V_166 -> V_250 = F_123 ( V_2 ) ;
V_166 -> V_7 = V_2 -> V_4 . V_6 -> V_7 ;
V_166 -> V_10 = V_2 -> V_4 . V_6 -> V_10 ;
V_166 -> V_11 = V_2 -> V_4 . V_6 -> V_11 ;
V_166 -> V_251 = V_2 -> V_4 . V_251 ;
V_166 -> V_252 = V_2 -> V_4 . V_6 -> V_252 ;
V_166 -> V_253 = V_2 -> V_4 . V_6 -> V_253 ;
V_166 -> V_254 = V_2 -> V_4 . V_6 -> V_254 ;
V_166 -> V_255 = V_2 -> V_4 . V_6 -> V_255 ;
V_166 -> V_256 = V_2 -> V_4 . V_6 -> V_256 ;
V_166 -> V_257 = V_2 -> V_4 . V_6 -> V_257 ;
V_166 -> V_258 = V_2 -> V_4 . V_6 -> V_258 ;
V_166 -> V_259 = V_2 -> V_4 . V_6 -> V_259 ;
for ( V_3 = 0 ; V_3 < F_124 ( V_166 -> V_169 ) ; V_3 ++ )
V_166 -> V_169 [ V_3 ] = F_3 ( V_2 , V_3 ) ;
return 0 ;
}
int F_125 ( struct V_1 * V_2 , struct V_248 * V_166 )
{
int V_3 ;
V_2 -> V_4 . V_5 = V_166 -> V_5 ;
F_126 ( V_2 , V_166 -> V_249 ) ;
V_2 -> V_4 . V_9 = V_166 -> V_9 ;
V_2 -> V_4 . V_8 = V_166 -> V_8 ;
F_127 ( V_2 , V_166 -> V_250 ) ;
F_14 ( V_2 , V_166 -> V_7 ) ;
V_2 -> V_4 . V_6 -> V_10 = V_166 -> V_10 ;
V_2 -> V_4 . V_6 -> V_11 = V_166 -> V_11 ;
F_128 ( V_2 , V_166 -> V_251 ) ;
V_2 -> V_4 . V_6 -> V_252 = V_166 -> V_252 ;
V_2 -> V_4 . V_6 -> V_253 = V_166 -> V_253 ;
V_2 -> V_4 . V_6 -> V_254 = V_166 -> V_254 ;
V_2 -> V_4 . V_6 -> V_255 = V_166 -> V_255 ;
V_2 -> V_4 . V_6 -> V_256 = V_166 -> V_256 ;
V_2 -> V_4 . V_6 -> V_257 = V_166 -> V_257 ;
V_2 -> V_4 . V_6 -> V_258 = V_166 -> V_258 ;
V_2 -> V_4 . V_6 -> V_259 = V_166 -> V_259 ;
for ( V_3 = 0 ; V_3 < F_124 ( V_166 -> V_169 ) ; V_3 ++ )
F_101 ( V_2 , V_3 , V_166 -> V_169 [ V_3 ] ) ;
return 0 ;
}
static void F_129 ( struct V_1 * V_2 ,
struct V_260 * V_261 )
{
T_3 V_94 = F_47 () ;
V_261 -> V_262 . V_263 . V_264 |= V_265 ;
V_261 -> V_262 . V_263 . V_40 = V_2 -> V_4 . V_40 ;
V_261 -> V_262 . V_263 . V_41 = V_2 -> V_4 . V_41 ;
V_261 -> V_262 . V_263 . V_266 = V_2 -> V_4 . V_266 ;
V_261 -> V_262 . V_263 . V_51 = F_41 ( V_2 ) ;
V_261 -> V_262 . V_263 . V_49 = F_38 ( V_2 ) ;
V_261 -> V_262 . V_263 . V_102 = V_2 -> V_4 . V_102 ;
V_261 -> V_262 . V_263 . V_99 = V_2 -> V_4 . V_99 ;
V_261 -> V_262 . V_263 . V_267 = F_130 ( V_2 , V_94 ) ;
V_261 -> V_262 . V_263 . V_94 = V_94 ;
V_261 -> V_262 . V_263 . V_268 = V_2 -> V_4 . V_268 ;
}
static int F_131 ( struct V_1 * V_2 ,
struct V_260 * V_261 )
{
if ( ! ( V_261 -> V_262 . V_263 . V_264 & V_265 ) )
return 0 ;
V_2 -> V_4 . V_40 = V_261 -> V_262 . V_263 . V_40 ;
V_2 -> V_4 . V_41 = V_261 -> V_262 . V_263 . V_41 ;
V_2 -> V_4 . V_266 = V_261 -> V_262 . V_263 . V_266 ;
F_42 ( V_2 , V_261 -> V_262 . V_263 . V_51 ) ;
F_40 ( V_2 , V_261 -> V_262 . V_263 . V_49 ) ;
V_2 -> V_4 . V_268 = V_261 -> V_262 . V_263 . V_268 ;
F_132 ( V_2 , V_261 -> V_262 . V_263 . V_99 ) ;
if ( V_261 -> V_262 . V_263 . V_269 & V_270 ) {
V_2 -> V_4 . V_267 = V_261 -> V_262 . V_263 . V_267 ;
F_133 ( V_2 ) ;
}
if ( V_261 -> V_262 . V_263 . V_269 & V_271 ) {
T_1 V_272 = V_2 -> V_4 . V_102 ;
V_2 -> V_4 . V_102 = V_261 -> V_262 . V_263 . V_102 ;
if ( ( V_272 ^ V_2 -> V_4 . V_102 ) & ( V_103 | V_104 ) )
F_50 ( V_2 ) ;
F_60 ( V_2 ) ;
}
return 0 ;
}
static void F_134 ( struct V_1 * V_2 ,
struct V_260 * V_261 )
{
V_261 -> V_262 . V_263 . V_264 |= V_273 ;
V_261 -> V_262 . V_263 . V_242 = V_2 -> V_243 ;
V_261 -> V_262 . V_263 . V_45 = V_2 -> V_4 . V_45 ;
V_261 -> V_262 . V_263 . V_46 = V_2 -> V_4 . V_46 ;
V_261 -> V_262 . V_263 . V_274 = V_2 -> V_4 . V_274 ;
V_261 -> V_262 . V_263 . V_86 = V_2 -> V_4 . V_86 ;
}
static int F_135 ( struct V_1 * V_2 ,
struct V_260 * V_261 )
{
if ( ! ( V_261 -> V_262 . V_263 . V_264 & V_273 ) )
return 0 ;
if ( V_261 -> V_262 . V_263 . V_242 != V_2 -> V_243 )
return - V_142 ;
V_2 -> V_4 . V_45 = V_261 -> V_262 . V_263 . V_45 ;
V_2 -> V_4 . V_46 = V_261 -> V_262 . V_263 . V_46 ;
V_2 -> V_4 . V_274 = V_261 -> V_262 . V_263 . V_274 ;
V_2 -> V_4 . V_86 = V_261 -> V_262 . V_263 . V_86 ;
return 0 ;
}
void F_136 ( struct V_1 * V_2 , struct V_260 * V_261 )
{
V_261 -> V_262 . V_263 . V_264 |= V_275 ;
V_261 -> V_262 . V_263 . V_276 [ 0 ] = V_2 -> V_4 . V_87 [ V_76 ] ;
V_261 -> V_262 . V_263 . V_276 [ 1 ] = V_2 -> V_4 . V_87 [ V_79 ] ;
V_261 -> V_262 . V_263 . V_276 [ 2 ] = V_2 -> V_4 . V_87 [ V_27 ] ;
V_261 -> V_262 . V_263 . V_276 [ 3 ] = V_2 -> V_4 . V_87 [ V_28 ] ;
V_261 -> V_262 . V_263 . V_276 [ 4 ] = V_2 -> V_4 . V_87 [ V_34 ] ;
V_261 -> V_262 . V_263 . V_276 [ 5 ] = V_2 -> V_4 . V_87 [ V_71 ] ;
V_261 -> V_262 . V_263 . V_276 [ 6 ] = V_2 -> V_4 . V_87 [ V_29 ] ;
V_261 -> V_262 . V_263 . V_276 [ 7 ] = V_2 -> V_4 . V_87 [ V_66 ] ;
V_261 -> V_262 . V_263 . V_276 [ 8 ] = V_2 -> V_4 . V_87 [ V_65 ] ;
V_261 -> V_262 . V_263 . V_276 [ 9 ] = V_2 -> V_4 . V_87 [ V_70 ] ;
V_261 -> V_262 . V_263 . V_276 [ 10 ] = V_2 -> V_4 . V_87 [ V_30 ] ;
V_261 -> V_262 . V_263 . V_276 [ 11 ] = V_2 -> V_4 . V_87 [ V_81 ] ;
V_261 -> V_262 . V_263 . V_276 [ 12 ] = V_2 -> V_4 . V_87 [ V_37 ] ;
V_261 -> V_262 . V_263 . V_276 [ 13 ] = V_2 -> V_4 . V_87 [ V_26 ] ;
V_261 -> V_262 . V_263 . V_276 [ 14 ] = V_2 -> V_4 . V_87 [ V_64 ] ;
V_261 -> V_262 . V_263 . V_276 [ 15 ] = V_2 -> V_4 . V_87 [ V_84 ] ;
}
int F_137 ( struct V_1 * V_2 , struct V_260 * V_261 )
{
if ( ! ( V_261 -> V_262 . V_263 . V_264 & V_275 ) )
return 0 ;
V_2 -> V_4 . V_87 [ V_76 ] = V_261 -> V_262 . V_263 . V_276 [ 0 ] ;
V_2 -> V_4 . V_87 [ V_79 ] = V_261 -> V_262 . V_263 . V_276 [ 1 ] ;
V_2 -> V_4 . V_87 [ V_27 ] = V_261 -> V_262 . V_263 . V_276 [ 2 ] ;
V_2 -> V_4 . V_87 [ V_28 ] = V_261 -> V_262 . V_263 . V_276 [ 3 ] ;
V_2 -> V_4 . V_87 [ V_34 ] = V_261 -> V_262 . V_263 . V_276 [ 4 ] ;
V_2 -> V_4 . V_87 [ V_71 ] = V_261 -> V_262 . V_263 . V_276 [ 5 ] ;
V_2 -> V_4 . V_87 [ V_29 ] = V_261 -> V_262 . V_263 . V_276 [ 6 ] ;
V_2 -> V_4 . V_87 [ V_66 ] = V_261 -> V_262 . V_263 . V_276 [ 7 ] ;
V_2 -> V_4 . V_87 [ V_65 ] = V_261 -> V_262 . V_263 . V_276 [ 8 ] ;
V_2 -> V_4 . V_87 [ V_70 ] = V_261 -> V_262 . V_263 . V_276 [ 9 ] ;
V_2 -> V_4 . V_87 [ V_30 ] = V_261 -> V_262 . V_263 . V_276 [ 10 ] ;
V_2 -> V_4 . V_87 [ V_81 ] = V_261 -> V_262 . V_263 . V_276 [ 11 ] ;
V_2 -> V_4 . V_87 [ V_37 ] = V_261 -> V_262 . V_263 . V_276 [ 12 ] ;
V_2 -> V_4 . V_87 [ V_26 ] = V_261 -> V_262 . V_263 . V_276 [ 13 ] ;
V_2 -> V_4 . V_87 [ V_64 ] = V_261 -> V_262 . V_263 . V_276 [ 14 ] ;
V_2 -> V_4 . V_87 [ V_84 ] = V_261 -> V_262 . V_263 . V_276 [ 15 ] ;
return 0 ;
}
int F_138 ( struct V_1 * V_2 ,
struct V_260 * V_261 )
{
V_261 -> V_277 = V_2 -> V_4 . V_277 ;
F_129 ( V_2 , V_261 ) ;
F_134 ( V_2 , V_261 ) ;
F_139 ( V_2 , V_261 ) ;
return 0 ;
}
int F_140 ( struct V_1 * V_2 ,
struct V_260 * V_261 )
{
int V_135 ;
if ( V_2 -> V_4 . V_277 != V_261 -> V_277 )
return - V_142 ;
V_135 = F_131 ( V_2 , V_261 ) ;
if ( V_135 < 0 )
return V_135 ;
V_135 = F_135 ( V_2 , V_261 ) ;
if ( V_135 < 0 )
return V_135 ;
return F_141 ( V_2 , V_261 ) ;
}
int F_142 ( struct V_1 * V_2 , struct V_278 * V_279 )
{
int V_124 = - V_142 ;
switch ( V_279 -> V_280 ) {
case V_281 :
case V_282 :
case V_283 :
case V_284 : {
int V_285 = V_279 -> V_280 - V_281 ;
V_124 = F_143 ( ( T_3 V_286 * ) ( long ) V_279 -> V_287 ,
& V_2 -> V_4 . V_288 . V_285 [ V_285 ] , sizeof( T_3 ) ) ;
break;
}
case V_289 :
case V_290 : {
int V_291 = V_279 -> V_280 - V_289 ;
V_124 = F_143 ( ( T_3 V_286 * ) ( long ) V_279 -> V_287 ,
& V_2 -> V_4 . V_288 . V_291 [ V_291 ] , sizeof( T_3 ) ) ;
break;
}
#if F_13 ( V_88 )
case V_292 :
V_124 = F_144 ( V_2 -> V_4 . V_89 , ( T_1 V_286 * ) ( long ) V_279 -> V_287 ) ;
break;
#endif
default:
break;
}
return V_124 ;
}
int F_145 ( struct V_1 * V_2 , struct V_278 * V_279 )
{
int V_124 = - V_142 ;
switch ( V_279 -> V_280 ) {
case V_281 :
case V_282 :
case V_283 :
case V_284 : {
int V_285 = V_279 -> V_280 - V_281 ;
V_124 = F_146 ( & V_2 -> V_4 . V_288 . V_285 [ V_285 ] ,
( T_3 V_286 * ) ( long ) V_279 -> V_287 , sizeof( T_3 ) ) ;
break;
}
case V_289 :
case V_290 : {
int V_291 = V_279 -> V_280 - V_289 ;
V_124 = F_146 ( & V_2 -> V_4 . V_288 . V_291 [ V_291 ] ,
( T_3 V_286 * ) ( long ) V_279 -> V_287 , sizeof( T_3 ) ) ;
break;
}
#if F_13 ( V_88 )
case V_292 : {
T_1 V_293 ;
V_124 = F_147 ( V_293 , ( T_1 V_286 * ) ( long ) V_279 -> V_287 ) ;
if ( V_124 == 0 )
F_148 ( V_2 , V_293 ) ;
break;
}
#endif
default:
break;
}
return V_124 ;
}
int F_149 ( struct V_1 * V_2 , struct V_294 * V_295 )
{
return - V_296 ;
}
int F_150 ( struct V_1 * V_2 , struct V_294 * V_295 )
{
return - V_296 ;
}
int F_151 ( struct V_1 * V_2 ,
struct V_297 * V_298 )
{
int V_124 ;
V_124 = F_152 ( V_2 , V_298 ) ;
return V_124 ;
}
int F_153 ( struct V_223 * V_223 , struct V_299 * log )
{
return - V_296 ;
}
void F_154 ( struct V_300 * free ,
struct V_300 * V_301 )
{
}
int F_155 ( struct V_300 * V_302 ,
unsigned long V_303 )
{
return 0 ;
}
int F_156 ( struct V_223 * V_223 ,
struct V_300 * V_304 ,
struct V_305 * V_306 )
{
return 0 ;
}
void F_157 ( struct V_223 * V_223 ,
struct V_305 * V_306 ,
struct V_300 V_307 )
{
}
void F_158 ( struct V_223 * V_223 , struct V_300 * V_304 )
{
}
void F_148 ( struct V_1 * V_2 , T_1 V_293 )
{
#if F_13 ( V_88 )
V_2 -> V_4 . V_89 = V_293 ;
#ifdef V_16
V_2 -> V_4 . V_308 &= ~ V_309 ;
if ( V_2 -> V_4 . V_89 & V_90 )
V_2 -> V_4 . V_308 |= V_309 ;
#endif
#endif
}
void F_132 ( struct V_1 * V_2 , T_1 V_310 )
{
V_2 -> V_4 . V_99 = V_310 ;
F_50 ( V_2 ) ;
F_60 ( V_2 ) ;
}
void F_159 ( struct V_1 * V_2 , T_1 V_311 )
{
F_160 ( V_311 , & V_2 -> V_4 . V_102 ) ;
F_57 () ;
F_58 ( V_114 , V_2 ) ;
F_59 ( V_2 ) ;
}
void F_161 ( struct V_1 * V_2 , T_1 V_311 )
{
F_162 ( V_311 , & V_2 -> V_4 . V_102 ) ;
if ( V_311 & ( V_103 | V_104 ) )
F_50 ( V_2 ) ;
F_60 ( V_2 ) ;
}
void F_163 ( unsigned long V_111 )
{
struct V_1 * V_2 = (struct V_1 * ) V_111 ;
if ( V_2 -> V_4 . V_99 & V_312 ) {
V_2 -> V_4 . V_267 = V_2 -> V_4 . V_274 ;
F_133 ( V_2 ) ;
}
F_159 ( V_2 , V_118 ) ;
}
void F_164 ( struct V_1 * V_2 , int V_313 )
{
V_2 -> V_313 = F_165 () ;
V_144 -> V_145 . V_1 = V_2 ;
}
void F_166 ( struct V_1 * V_2 )
{
V_144 -> V_145 . V_1 = NULL ;
V_2 -> V_313 = - 1 ;
}
int T_6 F_167 ( void )
{
#ifndef V_16
unsigned long V_87 [ 16 ] ;
unsigned long V_314 = 0 ;
int V_3 ;
V_315 = F_168 ( V_316 | V_317 ,
V_318 ) ;
if ( ! V_315 )
return - V_319 ;
V_87 [ 0 ] = F_39 ( V_320 ) ;
V_87 [ 1 ] = F_39 ( V_321 ) ;
V_87 [ 2 ] = F_39 ( V_322 ) ;
V_87 [ 3 ] = F_39 ( V_323 ) ;
V_87 [ 4 ] = F_39 ( V_324 ) ;
V_87 [ 5 ] = F_39 ( V_325 ) ;
V_87 [ 6 ] = F_39 ( V_326 ) ;
V_87 [ 7 ] = F_39 ( V_327 ) ;
V_87 [ 8 ] = F_39 ( V_328 ) ;
V_87 [ 9 ] = F_39 ( V_329 ) ;
V_87 [ 10 ] = F_39 ( V_330 ) ;
V_87 [ 11 ] = F_39 ( V_331 ) ;
V_87 [ 12 ] = F_39 ( V_332 ) ;
V_87 [ 13 ] = F_39 ( V_333 ) ;
V_87 [ 14 ] = F_39 ( V_334 ) ;
V_87 [ 15 ] = F_39 ( V_335 ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( V_87 [ V_3 ] > V_314 )
V_314 = V_87 [ V_3 ] ;
memcpy ( ( void * ) V_315 + V_87 [ V_3 ] ,
V_336 + V_3 * V_337 ,
V_337 ) ;
}
F_169 ( V_315 ,
V_315 + V_314 + V_337 ) ;
#endif
return 0 ;
}
void T_7 F_170 ( void )
{
F_171 ( V_315 , V_318 ) ;
F_172 () ;
}
