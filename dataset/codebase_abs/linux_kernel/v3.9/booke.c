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
void F_30 ( struct V_1 * V_2 ,
struct V_32 * V_33 )
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
if ( V_59 == true )
F_46 ( V_92 , V_2 ) ;
V_18 &= V_56 ;
#if F_13 ( V_93 )
if ( V_2 -> V_4 . V_94 & V_95 )
V_18 |= V_96 ;
#endif
F_14 ( V_2 , V_18 ) ;
if ( ! V_64 )
F_28 ( V_21 , & V_2 -> V_4 . V_12 ) ;
}
#ifdef V_16
if ( V_2 -> V_4 . V_12 & V_97 )
F_47 ( V_2 , V_79 ) ;
if ( V_2 -> V_4 . V_12 & V_98 )
F_47 ( V_2 , V_82 ) ;
if ( V_2 -> V_4 . V_12 & V_83 )
F_47 ( V_2 , V_84 ) ;
#endif
return V_55 ;
}
static unsigned long F_48 ( struct V_1 * V_2 )
{
T_3 V_99 , V_100 , V_101 = 0 ;
T_3 V_102 = 0 ;
T_1 V_103 = F_49 ( V_2 -> V_4 . V_104 ) ;
V_100 = 1ULL << ( 63 - V_103 ) ;
V_99 = F_50 () ;
if ( V_99 & V_100 )
V_101 = V_100 ;
V_101 += V_100 - ( V_99 & ( V_100 - 1 ) ) ;
V_102 = V_101 ;
if ( F_51 ( V_102 , V_105 ) )
V_102 ++ ;
return F_52 (unsigned long long, nr_jiffies, NEXT_TIMER_MAX_DELTA) ;
}
static void F_53 ( struct V_1 * V_2 )
{
unsigned long V_102 ;
unsigned long V_106 ;
if ( ( V_2 -> V_4 . V_107 & ( V_108 | V_109 ) ) != ( V_108 | V_109 ) )
F_28 ( V_110 , & V_2 -> V_111 ) ;
F_54 ( & V_2 -> V_4 . V_112 , V_106 ) ;
V_102 = F_48 ( V_2 ) ;
if ( V_102 < V_113 )
F_55 ( & V_2 -> V_4 . V_114 , V_115 + V_102 ) ;
else
F_56 ( & V_2 -> V_4 . V_114 ) ;
F_57 ( & V_2 -> V_4 . V_112 , V_106 ) ;
}
void F_58 ( unsigned long V_116 )
{
struct V_1 * V_2 = (struct V_1 * ) V_116 ;
T_1 V_107 , V_117 ;
int V_118 ;
do {
V_117 = V_107 = V_2 -> V_4 . V_107 ;
V_118 = 0 ;
if ( V_107 & V_108 ) {
if ( V_107 & V_109 )
V_118 = 1 ;
else
V_117 = V_107 | V_109 ;
} else {
V_117 = V_107 | V_108 ;
}
} while ( F_59 ( & V_2 -> V_4 . V_107 , V_107 , V_117 ) != V_107 );
if ( V_117 & V_109 ) {
F_60 () ;
F_46 ( V_119 , V_2 ) ;
F_61 ( V_2 ) ;
}
if ( V_118 && ( V_2 -> V_4 . V_104 & V_120 ) &&
V_2 -> V_4 . V_121 ) {
F_60 () ;
F_46 ( V_110 , V_2 ) ;
F_61 ( V_2 ) ;
}
if ( ! V_118 )
F_53 ( V_2 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 . V_104 & V_122 ) && ( V_2 -> V_4 . V_107 & V_123 ) )
F_24 ( V_2 ) ;
else
F_27 ( V_2 ) ;
if ( ( V_2 -> V_4 . V_104 & V_124 ) && ( V_2 -> V_4 . V_107 & V_109 ) )
F_31 ( V_2 ) ;
else
F_32 ( V_2 ) ;
}
static void F_63 ( struct V_1 * V_2 )
{
unsigned long * V_125 = & V_2 -> V_4 . V_12 ;
unsigned int V_21 ;
V_21 = F_64 ( * V_125 ) ;
while ( V_21 < V_126 ) {
if ( F_45 ( V_2 , V_21 ) )
break;
V_21 = F_65 ( V_125 ,
V_127 * sizeof( * V_125 ) ,
V_21 + 1 ) ;
}
V_2 -> V_4 . V_6 -> V_128 = ! ! * V_125 ;
}
int F_66 ( struct V_1 * V_2 )
{
int V_129 = 0 ;
F_67 ( ! F_68 () ) ;
F_63 ( V_2 ) ;
if ( V_2 -> V_111 ) {
return 1 ;
}
if ( V_2 -> V_4 . V_6 -> V_7 & V_130 ) {
F_69 () ;
F_70 ( V_2 ) ;
F_28 ( V_131 , & V_2 -> V_111 ) ;
F_71 () ;
F_72 ( V_2 , V_132 ) ;
V_129 = 1 ;
} ;
return V_129 ;
}
int F_73 ( struct V_1 * V_2 )
{
int V_129 = 1 ;
if ( F_74 ( V_119 , V_2 ) )
F_62 ( V_2 ) ;
#if F_13 ( V_133 ) || F_13 ( V_134 )
if ( F_74 ( V_135 , V_2 ) )
F_75 ( V_2 ) ;
#endif
if ( F_74 ( V_110 , V_2 ) ) {
V_2 -> V_136 -> V_137 = V_138 ;
V_129 = 0 ;
}
if ( F_74 ( V_92 , V_2 ) ) {
V_2 -> V_136 -> V_54 . V_54 = 0 ;
V_2 -> V_4 . V_139 = true ;
V_2 -> V_136 -> V_137 = V_140 ;
V_129 = 0 ;
}
return V_129 ;
}
int F_76 ( struct V_141 * V_141 , struct V_1 * V_2 )
{
int V_142 , V_143 ;
#ifdef V_15
unsigned int V_144 ;
int V_145 ;
T_3 V_146 [ 32 ] ;
#endif
if ( ! V_2 -> V_4 . V_147 ) {
V_141 -> V_137 = V_148 ;
return - V_149 ;
}
F_71 () ;
V_143 = F_77 ( V_2 ) ;
if ( V_143 <= 0 ) {
F_69 () ;
V_142 = V_143 ;
goto V_150;
}
F_78 () ;
F_79 () ;
#ifdef V_15
F_80 () ;
memcpy ( V_146 , V_151 -> V_152 . V_146 , sizeof( V_151 -> V_152 . V_146 ) ) ;
V_144 = V_151 -> V_152 . V_144 . V_153 ;
V_145 = V_151 -> V_152 . V_145 ;
memcpy ( V_151 -> V_152 . V_146 , V_2 -> V_4 . V_146 , sizeof( V_2 -> V_4 . V_146 ) ) ;
V_151 -> V_152 . V_144 . V_153 = V_2 -> V_4 . V_144 ;
V_2 -> V_154 = 1 ;
F_81 ( V_2 ) ;
#endif
V_142 = F_82 ( V_141 , V_2 ) ;
#ifdef V_15
F_83 ( V_2 ) ;
V_2 -> V_154 = 0 ;
memcpy ( V_2 -> V_4 . V_146 , V_151 -> V_152 . V_146 , sizeof( V_2 -> V_4 . V_146 ) ) ;
V_2 -> V_4 . V_144 = V_151 -> V_152 . V_144 . V_153 ;
memcpy ( V_151 -> V_152 . V_146 , V_146 , sizeof( V_151 -> V_152 . V_146 ) ) ;
V_151 -> V_152 . V_144 . V_153 = V_144 ;
V_151 -> V_152 . V_145 = V_145 ;
#endif
V_150:
V_2 -> V_155 = V_156 ;
return V_142 ;
}
static int F_84 ( struct V_141 * V_136 , struct V_1 * V_2 )
{
enum V_157 V_158 ;
V_158 = F_85 ( V_136 , V_2 ) ;
switch ( V_158 ) {
case V_159 :
F_86 ( V_2 , V_160 ) ;
return V_161 ;
case V_162 :
V_136 -> V_137 = V_163 ;
return V_164 ;
case V_165 :
F_2 ( V_166 L_6 ,
V_167 , V_2 -> V_4 . V_5 , V_2 -> V_4 . V_168 ) ;
V_136 -> V_169 . V_170 = ~ 0ULL << 32 ;
V_136 -> V_169 . V_170 |= V_2 -> V_4 . V_168 ;
F_23 ( V_2 , V_171 ) ;
return V_164 ;
default:
F_87 () ;
}
}
static void F_88 ( struct V_172 * V_173 )
{
T_2 V_174 , V_175 , V_7 , V_8 ;
asm("mr %0, 1" : "=r"(r1));
asm("mflr %0" : "=r"(lr));
asm("mfmsr %0" : "=r"(msr));
asm("bl 1f; 1: mflr %0" : "=r"(ip));
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
V_173 -> V_176 [ 1 ] = V_174 ;
V_173 -> V_177 = V_175 ;
V_173 -> V_7 = V_7 ;
V_173 -> V_178 = V_8 ;
}
static void F_89 ( struct V_1 * V_2 ,
unsigned int V_179 )
{
struct V_172 V_173 ;
switch ( V_179 ) {
case V_180 :
F_88 ( & V_173 ) ;
F_90 ( & V_173 ) ;
break;
case V_181 :
F_88 ( & V_173 ) ;
F_91 ( & V_173 ) ;
break;
#if F_13 ( V_182 ) || F_13 ( V_183 )
case V_184 :
F_88 ( & V_173 ) ;
F_92 ( & V_173 ) ;
break;
#endif
case V_185 :
break;
case V_186 :
F_88 ( & V_173 ) ;
F_93 ( & V_173 ) ;
break;
case V_187 :
F_88 ( & V_173 ) ;
#ifdef F_94
F_95 ( & V_173 ) ;
#else
F_96 ( & V_173 ) ;
#endif
break;
case V_188 :
F_96 ( & V_173 ) ;
break;
}
}
int F_97 ( struct V_141 * V_136 , struct V_1 * V_2 ,
unsigned int V_179 )
{
int V_129 = V_164 ;
int V_143 ;
F_98 ( V_2 ) ;
F_89 ( V_2 , V_179 ) ;
F_69 () ;
F_99 ( V_179 , V_2 ) ;
F_100 () ;
V_136 -> V_137 = V_189 ;
V_136 -> V_190 = 1 ;
switch ( V_179 ) {
case V_185 :
F_2 ( L_7 , F_40 ( V_191 ) ) ;
F_1 ( V_2 ) ;
V_136 -> V_169 . V_170 = ~ 1ULL << 32 ;
V_136 -> V_169 . V_170 |= F_40 ( V_191 ) ;
V_129 = V_164 ;
break;
case V_180 :
F_101 ( V_2 , V_192 ) ;
V_129 = V_193 ;
break;
case V_181 :
F_101 ( V_2 , V_194 ) ;
V_129 = V_193 ;
break;
case V_187 :
V_129 = V_193 ;
break;
case V_184 :
F_101 ( V_2 , V_195 ) ;
V_129 = V_193 ;
break;
case V_196 :
F_101 ( V_2 , V_197 ) ;
V_129 = V_193 ;
break;
case V_198 :
F_101 ( V_2 , V_197 ) ;
V_129 = V_193 ;
break;
case V_186 :
V_129 = V_193 ;
break;
case V_199 :
V_129 = F_84 ( V_136 , V_2 ) ;
break;
case V_200 :
if ( V_2 -> V_4 . V_6 -> V_7 & ( V_67 | V_20 ) ) {
F_23 ( V_2 , V_2 -> V_4 . V_201 ) ;
V_129 = V_193 ;
F_101 ( V_2 , V_202 ) ;
break;
}
V_129 = F_84 ( V_136 , V_2 ) ;
break;
case V_203 :
F_16 ( V_2 , V_71 ) ;
F_101 ( V_2 , V_204 ) ;
V_129 = V_193 ;
break;
#ifdef F_102
case V_205 : {
if ( V_2 -> V_4 . V_6 -> V_7 & V_14 )
F_9 ( V_2 ) ;
else
F_16 ( V_2 ,
V_72 ) ;
V_129 = V_193 ;
break;
}
case V_206 :
F_16 ( V_2 , V_73 ) ;
V_129 = V_193 ;
break;
case V_207 :
F_16 ( V_2 , V_74 ) ;
V_129 = V_193 ;
break;
#else
case V_205 :
F_23 ( V_2 , V_208 | V_209 ) ;
V_129 = V_193 ;
break;
case V_206 :
case V_207 :
F_2 ( V_166 L_8 ,
V_167 , V_179 , V_2 -> V_4 . V_5 ) ;
V_136 -> V_169 . V_170 = V_179 ;
V_129 = V_164 ;
break;
#endif
case V_210 :
F_20 ( V_2 , V_2 -> V_4 . V_211 ,
V_2 -> V_4 . V_201 ) ;
F_101 ( V_2 , V_212 ) ;
V_129 = V_193 ;
break;
case V_213 :
F_21 ( V_2 , V_2 -> V_4 . V_201 ) ;
F_101 ( V_2 , V_214 ) ;
V_129 = V_193 ;
break;
case V_215 :
F_22 ( V_2 , V_2 -> V_4 . V_211 ,
V_2 -> V_4 . V_201 ) ;
V_129 = V_193 ;
break;
#ifdef V_16
case V_216 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_67 ) ) {
F_103 ( V_2 , 3 , F_104 ( V_2 ) ) ;
} else {
F_23 ( V_2 , V_217 ) ;
}
V_129 = V_193 ;
break;
#else
case V_218 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_67 ) &&
( ( ( T_1 ) F_3 ( V_2 , 0 ) ) == V_219 ) ) {
F_103 ( V_2 , 3 , F_104 ( V_2 ) ) ;
V_129 = V_193 ;
} else {
F_16 ( V_2 , V_70 ) ;
}
F_101 ( V_2 , V_220 ) ;
V_129 = V_193 ;
break;
#endif
case V_221 : {
unsigned long V_222 = V_2 -> V_4 . V_211 ;
int V_223 ;
T_4 V_224 ;
T_5 V_225 ;
#ifdef V_133
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_67 ) &&
( V_222 & V_226 ) == V_2 -> V_4 . V_227 ) {
F_105 ( V_2 ) ;
F_101 ( V_2 , V_228 ) ;
V_129 = V_193 ;
break;
}
#endif
V_223 = F_106 ( V_2 , V_222 ) ;
if ( V_223 < 0 ) {
F_19 ( V_2 ,
V_2 -> V_4 . V_211 ,
V_2 -> V_4 . V_201 ) ;
F_107 ( V_2 ) ;
F_101 ( V_2 , V_229 ) ;
V_129 = V_193 ;
break;
}
V_224 = F_108 ( V_2 , V_223 , V_222 ) ;
V_225 = V_224 >> V_230 ;
if ( F_109 ( V_2 -> V_231 , V_225 ) ) {
F_110 ( V_2 , V_222 , V_224 , V_223 ) ;
F_101 ( V_2 , V_228 ) ;
V_129 = V_193 ;
} else {
V_2 -> V_4 . V_232 = V_224 ;
V_2 -> V_4 . V_233 = V_222 ;
V_129 = F_111 ( V_136 , V_2 ) ;
F_101 ( V_2 , V_234 ) ;
}
break;
}
case V_235 : {
unsigned long V_222 = V_2 -> V_4 . V_5 ;
T_4 V_224 ;
T_5 V_225 ;
int V_223 ;
V_129 = V_193 ;
V_223 = F_112 ( V_2 , V_222 ) ;
if ( V_223 < 0 ) {
F_16 ( V_2 , V_69 ) ;
F_113 ( V_2 ) ;
F_101 ( V_2 , V_236 ) ;
break;
}
F_101 ( V_2 , V_237 ) ;
V_224 = F_108 ( V_2 , V_223 , V_222 ) ;
V_225 = V_224 >> V_230 ;
if ( F_109 ( V_2 -> V_231 , V_225 ) ) {
F_110 ( V_2 , V_222 , V_224 , V_223 ) ;
} else {
F_16 ( V_2 , V_83 ) ;
}
break;
}
case V_238 : {
T_1 V_239 ;
V_2 -> V_4 . V_5 = F_40 ( V_240 ) ;
V_239 = F_40 ( V_241 ) ;
V_239 &= V_242 | V_243 | V_244 | V_245 ;
F_34 ( V_241 , V_239 ) ;
V_136 -> V_137 = V_246 ;
F_101 ( V_2 , V_247 ) ;
V_129 = V_164 ;
break;
}
default:
F_2 ( V_248 L_9 , V_179 ) ;
F_87 () ;
}
if ( ! ( V_129 & V_164 ) ) {
F_71 () ;
V_143 = F_77 ( V_2 ) ;
if ( V_143 <= 0 ) {
F_69 () ;
V_129 = ( V_143 << 2 ) | V_164 | ( V_129 & V_249 ) ;
} else {
F_78 () ;
}
}
return V_129 ;
}
int F_114 ( struct V_1 * V_2 )
{
int V_3 ;
int V_129 ;
V_2 -> V_4 . V_5 = 0 ;
V_2 -> V_4 . V_6 -> V_250 = V_2 -> V_251 ;
F_103 ( V_2 , 1 , ( 16 << 20 ) - 8 ) ;
F_14 ( V_2 , 0 ) ;
#ifndef V_16
V_2 -> V_4 . V_13 = V_252 | V_78 | V_253 | V_254 ;
V_2 -> V_4 . V_255 = 1 ;
V_2 -> V_4 . V_6 -> V_7 = 0 ;
#endif
V_2 -> V_4 . V_90 = 0x55550000 ;
for ( V_3 = 0 ; V_3 < V_126 ; V_3 ++ )
V_2 -> V_4 . V_91 [ V_3 ] = 0x7700 | V_3 * 4 ;
F_115 ( V_2 ) ;
V_129 = F_116 ( V_2 ) ;
F_117 ( V_2 ) ;
return V_129 ;
}
int F_118 ( struct V_1 * V_2 )
{
F_119 ( & V_2 -> V_4 . V_112 ) ;
F_120 ( & V_2 -> V_4 . V_114 , F_58 ,
( unsigned long ) V_2 ) ;
return 0 ;
}
void F_121 ( struct V_1 * V_2 )
{
F_122 ( & V_2 -> V_4 . V_114 ) ;
}
int F_123 ( struct V_1 * V_2 , struct V_256 * V_173 )
{
int V_3 ;
V_173 -> V_5 = V_2 -> V_4 . V_5 ;
V_173 -> V_257 = F_124 ( V_2 ) ;
V_173 -> V_9 = V_2 -> V_4 . V_9 ;
V_173 -> V_8 = V_2 -> V_4 . V_8 ;
V_173 -> V_258 = F_125 ( V_2 ) ;
V_173 -> V_7 = V_2 -> V_4 . V_6 -> V_7 ;
V_173 -> V_10 = V_2 -> V_4 . V_6 -> V_10 ;
V_173 -> V_11 = V_2 -> V_4 . V_6 -> V_11 ;
V_173 -> V_259 = V_2 -> V_4 . V_259 ;
V_173 -> V_260 = V_2 -> V_4 . V_6 -> V_260 ;
V_173 -> V_261 = V_2 -> V_4 . V_6 -> V_261 ;
V_173 -> V_262 = V_2 -> V_4 . V_6 -> V_262 ;
V_173 -> V_263 = V_2 -> V_4 . V_6 -> V_263 ;
V_173 -> V_264 = V_2 -> V_4 . V_6 -> V_264 ;
V_173 -> V_265 = V_2 -> V_4 . V_6 -> V_265 ;
V_173 -> V_266 = V_2 -> V_4 . V_6 -> V_266 ;
V_173 -> V_267 = V_2 -> V_4 . V_6 -> V_267 ;
for ( V_3 = 0 ; V_3 < F_126 ( V_173 -> V_176 ) ; V_3 ++ )
V_173 -> V_176 [ V_3 ] = F_3 ( V_2 , V_3 ) ;
return 0 ;
}
int F_127 ( struct V_1 * V_2 , struct V_256 * V_173 )
{
int V_3 ;
V_2 -> V_4 . V_5 = V_173 -> V_5 ;
F_128 ( V_2 , V_173 -> V_257 ) ;
V_2 -> V_4 . V_9 = V_173 -> V_9 ;
V_2 -> V_4 . V_8 = V_173 -> V_8 ;
F_129 ( V_2 , V_173 -> V_258 ) ;
F_14 ( V_2 , V_173 -> V_7 ) ;
V_2 -> V_4 . V_6 -> V_10 = V_173 -> V_10 ;
V_2 -> V_4 . V_6 -> V_11 = V_173 -> V_11 ;
F_130 ( V_2 , V_173 -> V_259 ) ;
V_2 -> V_4 . V_6 -> V_260 = V_173 -> V_260 ;
V_2 -> V_4 . V_6 -> V_261 = V_173 -> V_261 ;
V_2 -> V_4 . V_6 -> V_262 = V_173 -> V_262 ;
V_2 -> V_4 . V_6 -> V_263 = V_173 -> V_263 ;
V_2 -> V_4 . V_6 -> V_264 = V_173 -> V_264 ;
V_2 -> V_4 . V_6 -> V_265 = V_173 -> V_265 ;
V_2 -> V_4 . V_6 -> V_266 = V_173 -> V_266 ;
V_2 -> V_4 . V_6 -> V_267 = V_173 -> V_267 ;
for ( V_3 = 0 ; V_3 < F_126 ( V_173 -> V_176 ) ; V_3 ++ )
F_103 ( V_2 , V_3 , V_173 -> V_176 [ V_3 ] ) ;
return 0 ;
}
static void F_131 ( struct V_1 * V_2 ,
struct V_268 * V_269 )
{
T_3 V_99 = F_50 () ;
V_269 -> V_270 . V_271 . V_272 |= V_273 ;
V_269 -> V_270 . V_271 . V_41 = V_2 -> V_4 . V_41 ;
V_269 -> V_270 . V_271 . V_42 = V_2 -> V_4 . V_42 ;
V_269 -> V_270 . V_271 . V_274 = V_2 -> V_4 . V_274 ;
V_269 -> V_270 . V_271 . V_52 = F_42 ( V_2 ) ;
V_269 -> V_270 . V_271 . V_50 = F_39 ( V_2 ) ;
V_269 -> V_270 . V_271 . V_107 = V_2 -> V_4 . V_107 ;
V_269 -> V_270 . V_271 . V_104 = V_2 -> V_4 . V_104 ;
V_269 -> V_270 . V_271 . V_275 = F_132 ( V_2 , V_99 ) ;
V_269 -> V_270 . V_271 . V_99 = V_99 ;
V_269 -> V_270 . V_271 . V_276 = V_2 -> V_4 . V_276 ;
}
static int F_133 ( struct V_1 * V_2 ,
struct V_268 * V_269 )
{
if ( ! ( V_269 -> V_270 . V_271 . V_272 & V_273 ) )
return 0 ;
V_2 -> V_4 . V_41 = V_269 -> V_270 . V_271 . V_41 ;
V_2 -> V_4 . V_42 = V_269 -> V_270 . V_271 . V_42 ;
V_2 -> V_4 . V_274 = V_269 -> V_270 . V_271 . V_274 ;
F_43 ( V_2 , V_269 -> V_270 . V_271 . V_52 ) ;
F_41 ( V_2 , V_269 -> V_270 . V_271 . V_50 ) ;
V_2 -> V_4 . V_276 = V_269 -> V_270 . V_271 . V_276 ;
F_134 ( V_2 , V_269 -> V_270 . V_271 . V_104 ) ;
if ( V_269 -> V_270 . V_271 . V_277 & V_278 ) {
V_2 -> V_4 . V_275 = V_269 -> V_270 . V_271 . V_275 ;
F_135 ( V_2 ) ;
}
if ( V_269 -> V_270 . V_271 . V_277 & V_279 ) {
T_1 V_280 = V_2 -> V_4 . V_107 ;
V_2 -> V_4 . V_107 = V_269 -> V_270 . V_271 . V_107 ;
if ( ( V_280 ^ V_2 -> V_4 . V_107 ) & ( V_108 | V_109 ) )
F_53 ( V_2 ) ;
F_62 ( V_2 ) ;
}
return 0 ;
}
static void F_136 ( struct V_1 * V_2 ,
struct V_268 * V_269 )
{
V_269 -> V_270 . V_271 . V_272 |= V_281 ;
V_269 -> V_270 . V_271 . V_250 = V_2 -> V_251 ;
V_269 -> V_270 . V_271 . V_46 = V_2 -> V_4 . V_46 ;
V_269 -> V_270 . V_271 . V_47 = V_2 -> V_4 . V_47 ;
V_269 -> V_270 . V_271 . V_282 = V_2 -> V_4 . V_282 ;
V_269 -> V_270 . V_271 . V_90 = V_2 -> V_4 . V_90 ;
}
static int F_137 ( struct V_1 * V_2 ,
struct V_268 * V_269 )
{
if ( ! ( V_269 -> V_270 . V_271 . V_272 & V_281 ) )
return 0 ;
if ( V_269 -> V_270 . V_271 . V_250 != V_2 -> V_251 )
return - V_149 ;
V_2 -> V_4 . V_46 = V_269 -> V_270 . V_271 . V_46 ;
V_2 -> V_4 . V_47 = V_269 -> V_270 . V_271 . V_47 ;
V_2 -> V_4 . V_282 = V_269 -> V_270 . V_271 . V_282 ;
V_2 -> V_4 . V_90 = V_269 -> V_270 . V_271 . V_90 ;
return 0 ;
}
void F_138 ( struct V_1 * V_2 , struct V_268 * V_269 )
{
V_269 -> V_270 . V_271 . V_272 |= V_283 ;
V_269 -> V_270 . V_271 . V_284 [ 0 ] = V_2 -> V_4 . V_91 [ V_80 ] ;
V_269 -> V_270 . V_271 . V_284 [ 1 ] = V_2 -> V_4 . V_91 [ V_83 ] ;
V_269 -> V_270 . V_271 . V_284 [ 2 ] = V_2 -> V_4 . V_91 [ V_27 ] ;
V_269 -> V_270 . V_271 . V_284 [ 3 ] = V_2 -> V_4 . V_91 [ V_28 ] ;
V_269 -> V_270 . V_271 . V_284 [ 4 ] = V_2 -> V_4 . V_91 [ V_35 ] ;
V_269 -> V_270 . V_271 . V_284 [ 5 ] = V_2 -> V_4 . V_91 [ V_29 ] ;
V_269 -> V_270 . V_271 . V_284 [ 6 ] = V_2 -> V_4 . V_91 [ V_30 ] ;
V_269 -> V_270 . V_271 . V_284 [ 7 ] = V_2 -> V_4 . V_91 [ V_71 ] ;
V_269 -> V_270 . V_271 . V_284 [ 8 ] = V_2 -> V_4 . V_91 [ V_70 ] ;
V_269 -> V_270 . V_271 . V_284 [ 9 ] = V_2 -> V_4 . V_91 [ V_75 ] ;
V_269 -> V_270 . V_271 . V_284 [ 10 ] = V_2 -> V_4 . V_91 [ V_31 ] ;
V_269 -> V_270 . V_271 . V_284 [ 11 ] = V_2 -> V_4 . V_91 [ V_85 ] ;
V_269 -> V_270 . V_271 . V_284 [ 12 ] = V_2 -> V_4 . V_91 [ V_38 ] ;
V_269 -> V_270 . V_271 . V_284 [ 13 ] = V_2 -> V_4 . V_91 [ V_26 ] ;
V_269 -> V_270 . V_271 . V_284 [ 14 ] = V_2 -> V_4 . V_91 [ V_69 ] ;
V_269 -> V_270 . V_271 . V_284 [ 15 ] = V_2 -> V_4 . V_91 [ V_88 ] ;
}
int F_139 ( struct V_1 * V_2 , struct V_268 * V_269 )
{
if ( ! ( V_269 -> V_270 . V_271 . V_272 & V_283 ) )
return 0 ;
V_2 -> V_4 . V_91 [ V_80 ] = V_269 -> V_270 . V_271 . V_284 [ 0 ] ;
V_2 -> V_4 . V_91 [ V_83 ] = V_269 -> V_270 . V_271 . V_284 [ 1 ] ;
V_2 -> V_4 . V_91 [ V_27 ] = V_269 -> V_270 . V_271 . V_284 [ 2 ] ;
V_2 -> V_4 . V_91 [ V_28 ] = V_269 -> V_270 . V_271 . V_284 [ 3 ] ;
V_2 -> V_4 . V_91 [ V_35 ] = V_269 -> V_270 . V_271 . V_284 [ 4 ] ;
V_2 -> V_4 . V_91 [ V_29 ] = V_269 -> V_270 . V_271 . V_284 [ 5 ] ;
V_2 -> V_4 . V_91 [ V_30 ] = V_269 -> V_270 . V_271 . V_284 [ 6 ] ;
V_2 -> V_4 . V_91 [ V_71 ] = V_269 -> V_270 . V_271 . V_284 [ 7 ] ;
V_2 -> V_4 . V_91 [ V_70 ] = V_269 -> V_270 . V_271 . V_284 [ 8 ] ;
V_2 -> V_4 . V_91 [ V_75 ] = V_269 -> V_270 . V_271 . V_284 [ 9 ] ;
V_2 -> V_4 . V_91 [ V_31 ] = V_269 -> V_270 . V_271 . V_284 [ 10 ] ;
V_2 -> V_4 . V_91 [ V_85 ] = V_269 -> V_270 . V_271 . V_284 [ 11 ] ;
V_2 -> V_4 . V_91 [ V_38 ] = V_269 -> V_270 . V_271 . V_284 [ 12 ] ;
V_2 -> V_4 . V_91 [ V_26 ] = V_269 -> V_270 . V_271 . V_284 [ 13 ] ;
V_2 -> V_4 . V_91 [ V_69 ] = V_269 -> V_270 . V_271 . V_284 [ 14 ] ;
V_2 -> V_4 . V_91 [ V_88 ] = V_269 -> V_270 . V_271 . V_284 [ 15 ] ;
return 0 ;
}
int F_140 ( struct V_1 * V_2 ,
struct V_268 * V_269 )
{
V_269 -> V_285 = V_2 -> V_4 . V_285 ;
F_131 ( V_2 , V_269 ) ;
F_136 ( V_2 , V_269 ) ;
F_141 ( V_2 , V_269 ) ;
return 0 ;
}
int F_142 ( struct V_1 * V_2 ,
struct V_268 * V_269 )
{
int V_142 ;
if ( V_2 -> V_4 . V_285 != V_269 -> V_285 )
return - V_149 ;
V_142 = F_133 ( V_2 , V_269 ) ;
if ( V_142 < 0 )
return V_142 ;
V_142 = F_137 ( V_2 , V_269 ) ;
if ( V_142 < 0 )
return V_142 ;
return F_143 ( V_2 , V_269 ) ;
}
int F_144 ( struct V_1 * V_2 , struct V_286 * V_287 )
{
int V_129 = - V_149 ;
switch ( V_287 -> V_288 ) {
case V_289 :
case V_290 :
case V_291 :
case V_292 : {
int V_293 = V_287 -> V_288 - V_289 ;
V_129 = F_145 ( ( T_3 V_294 * ) ( long ) V_287 -> V_295 ,
& V_2 -> V_4 . V_296 . V_293 [ V_293 ] , sizeof( T_3 ) ) ;
break;
}
case V_297 :
case V_298 : {
int V_299 = V_287 -> V_288 - V_297 ;
V_129 = F_145 ( ( T_3 V_294 * ) ( long ) V_287 -> V_295 ,
& V_2 -> V_4 . V_296 . V_299 [ V_299 ] , sizeof( T_3 ) ) ;
break;
}
case V_300 : {
T_1 V_54 = F_44 ( V_2 ) ;
V_129 = F_146 ( V_54 , ( T_1 V_294 * ) ( long ) V_287 -> V_295 ) ;
break;
}
#if F_13 ( V_93 )
case V_301 :
V_129 = F_146 ( V_2 -> V_4 . V_94 , ( T_1 V_294 * ) ( long ) V_287 -> V_295 ) ;
break;
#endif
default:
break;
}
return V_129 ;
}
int F_147 ( struct V_1 * V_2 , struct V_286 * V_287 )
{
int V_129 = - V_149 ;
switch ( V_287 -> V_288 ) {
case V_289 :
case V_290 :
case V_291 :
case V_292 : {
int V_293 = V_287 -> V_288 - V_289 ;
V_129 = F_148 ( & V_2 -> V_4 . V_296 . V_293 [ V_293 ] ,
( T_3 V_294 * ) ( long ) V_287 -> V_295 , sizeof( T_3 ) ) ;
break;
}
case V_297 :
case V_298 : {
int V_299 = V_287 -> V_288 - V_297 ;
V_129 = F_148 ( & V_2 -> V_4 . V_296 . V_299 [ V_299 ] ,
( T_3 V_294 * ) ( long ) V_287 -> V_295 , sizeof( T_3 ) ) ;
break;
}
case V_300 : {
T_1 V_302 ;
V_129 = F_149 ( V_302 , ( T_1 V_294 * ) ( long ) V_287 -> V_295 ) ;
if ( ! V_129 )
F_150 ( V_2 , V_302 ) ;
break;
}
#if F_13 ( V_93 )
case V_301 : {
T_1 V_303 ;
V_129 = F_149 ( V_303 , ( T_1 V_294 * ) ( long ) V_287 -> V_295 ) ;
if ( V_129 == 0 )
F_151 ( V_2 , V_303 ) ;
break;
}
#endif
default:
break;
}
return V_129 ;
}
int F_152 ( struct V_1 * V_2 , struct V_304 * V_305 )
{
return - V_306 ;
}
int F_153 ( struct V_1 * V_2 , struct V_304 * V_305 )
{
return - V_306 ;
}
int F_154 ( struct V_1 * V_2 ,
struct V_307 * V_308 )
{
int V_129 ;
V_129 = F_155 ( V_2 , V_308 ) ;
return V_129 ;
}
int F_156 ( struct V_231 * V_231 , struct V_309 * log )
{
return - V_306 ;
}
void F_157 ( struct V_310 * free ,
struct V_310 * V_311 )
{
}
int F_158 ( struct V_310 * V_312 ,
unsigned long V_313 )
{
return 0 ;
}
int F_159 ( struct V_231 * V_231 ,
struct V_310 * V_314 ,
struct V_315 * V_316 )
{
return 0 ;
}
void F_160 ( struct V_231 * V_231 ,
struct V_315 * V_316 ,
struct V_310 V_317 )
{
}
void F_161 ( struct V_231 * V_231 , struct V_310 * V_314 )
{
}
void F_151 ( struct V_1 * V_2 , T_1 V_303 )
{
#if F_13 ( V_93 )
V_2 -> V_4 . V_94 = V_303 ;
#ifdef V_16
V_2 -> V_4 . V_318 &= ~ V_319 ;
if ( V_2 -> V_4 . V_94 & V_95 )
V_2 -> V_4 . V_318 |= V_319 ;
#endif
#endif
}
void F_134 ( struct V_1 * V_2 , T_1 V_320 )
{
V_2 -> V_4 . V_104 = V_320 ;
F_53 ( V_2 ) ;
F_62 ( V_2 ) ;
}
void F_162 ( struct V_1 * V_2 , T_1 V_321 )
{
F_163 ( V_321 , & V_2 -> V_4 . V_107 ) ;
F_60 () ;
F_46 ( V_119 , V_2 ) ;
F_61 ( V_2 ) ;
}
void F_164 ( struct V_1 * V_2 , T_1 V_321 )
{
F_165 ( V_321 , & V_2 -> V_4 . V_107 ) ;
if ( V_321 & ( V_108 | V_109 ) )
F_53 ( V_2 ) ;
F_62 ( V_2 ) ;
}
void F_166 ( unsigned long V_116 )
{
struct V_1 * V_2 = (struct V_1 * ) V_116 ;
if ( V_2 -> V_4 . V_104 & V_322 ) {
V_2 -> V_4 . V_275 = V_2 -> V_4 . V_282 ;
F_135 ( V_2 ) ;
}
F_162 ( V_2 , V_123 ) ;
}
void F_167 ( struct V_1 * V_2 , int V_323 )
{
V_2 -> V_323 = F_168 () ;
V_151 -> V_152 . V_1 = V_2 ;
}
void F_169 ( struct V_1 * V_2 )
{
V_151 -> V_152 . V_1 = NULL ;
V_2 -> V_323 = - 1 ;
}
int T_6 F_170 ( void )
{
#ifndef V_16
unsigned long V_91 [ 16 ] ;
unsigned long * V_324 = V_325 ;
unsigned long V_326 = 0 ;
unsigned long V_327 ;
int V_3 ;
V_328 = F_171 ( V_329 | V_330 ,
V_331 ) ;
if ( ! V_328 )
return - V_332 ;
V_91 [ 0 ] = F_40 ( V_333 ) ;
V_91 [ 1 ] = F_40 ( V_334 ) ;
V_91 [ 2 ] = F_40 ( V_335 ) ;
V_91 [ 3 ] = F_40 ( V_336 ) ;
V_91 [ 4 ] = F_40 ( V_337 ) ;
V_91 [ 5 ] = F_40 ( V_338 ) ;
V_91 [ 6 ] = F_40 ( V_339 ) ;
V_91 [ 7 ] = F_40 ( V_340 ) ;
V_91 [ 8 ] = F_40 ( V_341 ) ;
V_91 [ 9 ] = F_40 ( V_342 ) ;
V_91 [ 10 ] = F_40 ( V_343 ) ;
V_91 [ 11 ] = F_40 ( V_344 ) ;
V_91 [ 12 ] = F_40 ( V_345 ) ;
V_91 [ 13 ] = F_40 ( V_346 ) ;
V_91 [ 14 ] = F_40 ( V_347 ) ;
V_91 [ 15 ] = F_40 ( V_348 ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( V_91 [ V_3 ] > V_326 )
V_326 = V_3 ;
V_327 = V_324 [ V_3 + 1 ] - V_324 [ V_3 ] ;
memcpy ( ( void * ) V_328 + V_91 [ V_3 ] ,
( void * ) V_324 [ V_3 ] , V_327 ) ;
}
V_327 = V_324 [ V_326 + 1 ] - V_324 [ V_326 ] ;
F_172 ( V_328 , V_328 +
V_91 [ V_326 ] + V_327 ) ;
#endif
return 0 ;
}
void T_7 F_173 ( void )
{
F_174 ( V_328 , V_331 ) ;
F_175 () ;
}
