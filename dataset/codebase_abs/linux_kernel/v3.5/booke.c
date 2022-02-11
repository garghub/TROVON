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
void F_12 ( struct V_1 * V_2 , T_1 V_15 )
{
T_1 V_16 = V_2 -> V_4 . V_6 -> V_7 ;
#ifdef F_13
V_15 |= V_17 ;
#endif
V_2 -> V_4 . V_6 -> V_7 = V_15 ;
F_14 ( V_2 , V_16 ) ;
F_11 ( V_2 ) ;
}
static void F_15 ( struct V_1 * V_2 ,
unsigned int V_18 )
{
F_16 ( V_18 , & V_2 -> V_4 . V_12 ) ;
}
static void F_17 ( struct V_1 * V_2 ,
T_2 V_19 , T_2 V_20 )
{
V_2 -> V_4 . V_21 = V_19 ;
V_2 -> V_4 . V_22 = V_20 ;
F_15 ( V_2 , V_23 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
T_2 V_19 , T_2 V_20 )
{
V_2 -> V_4 . V_21 = V_19 ;
V_2 -> V_4 . V_22 = V_20 ;
F_15 ( V_2 , V_24 ) ;
}
static void F_19 ( struct V_1 * V_2 ,
T_2 V_20 )
{
V_2 -> V_4 . V_22 = V_20 ;
F_15 ( V_2 , V_25 ) ;
}
void F_20 ( struct V_1 * V_2 , T_2 V_20 )
{
V_2 -> V_4 . V_22 = V_20 ;
F_15 ( V_2 , V_26 ) ;
}
void F_21 ( struct V_1 * V_2 )
{
F_15 ( V_2 , V_27 ) ;
}
int F_22 ( struct V_1 * V_2 )
{
return F_23 ( V_27 , & V_2 -> V_4 . V_12 ) ;
}
void F_24 ( struct V_1 * V_2 )
{
F_25 ( V_27 , & V_2 -> V_4 . V_12 ) ;
}
void F_26 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
unsigned int V_30 = V_31 ;
if ( V_29 -> V_29 == V_32 )
V_30 = V_33 ;
F_15 ( V_2 , V_30 ) ;
}
void F_27 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
F_25 ( V_31 , & V_2 -> V_4 . V_12 ) ;
F_25 ( V_33 , & V_2 -> V_4 . V_12 ) ;
}
static void F_28 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
#ifdef F_13
F_29 ( V_34 , V_10 ) ;
F_29 ( V_35 , V_11 ) ;
#else
V_2 -> V_4 . V_6 -> V_10 = V_10 ;
V_2 -> V_4 . V_6 -> V_11 = V_11 ;
#endif
}
static void F_30 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_36 = V_10 ;
V_2 -> V_4 . V_37 = V_11 ;
}
static void F_31 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
if ( F_32 ( V_38 ) ) {
V_2 -> V_4 . V_39 = V_10 ;
V_2 -> V_4 . V_40 = V_11 ;
} else {
F_30 ( V_2 , V_10 , V_11 ) ;
}
}
static void F_33 ( struct V_1 * V_2 , unsigned long V_10 , T_1 V_11 )
{
V_2 -> V_4 . V_41 = V_10 ;
V_2 -> V_4 . V_42 = V_11 ;
}
static unsigned long F_34 ( struct V_1 * V_2 )
{
#ifdef F_13
return F_35 ( V_43 ) ;
#else
return V_2 -> V_4 . V_6 -> V_44 ;
#endif
}
static void F_36 ( struct V_1 * V_2 , unsigned long V_45 )
{
#ifdef F_13
F_29 ( V_43 , V_45 ) ;
#else
V_2 -> V_4 . V_6 -> V_44 = V_45 ;
#endif
}
static unsigned long F_37 ( struct V_1 * V_2 )
{
#ifdef F_13
return F_35 ( V_46 ) ;
#else
return V_2 -> V_4 . V_6 -> V_47 ;
#endif
}
static void F_38 ( struct V_1 * V_2 , T_1 V_47 )
{
#ifdef F_13
F_29 ( V_46 , V_47 ) ;
#else
V_2 -> V_4 . V_6 -> V_47 = V_47 ;
#endif
}
static int F_39 ( struct V_1 * V_2 ,
unsigned int V_18 )
{
int V_48 = 0 ;
T_2 V_49 = 0 ;
bool V_50 = false , V_51 = false ;
T_2 V_52 = V_2 -> V_4 . V_6 -> V_53 ;
T_2 V_54 = F_3 ( V_2 , 1 ) ;
bool V_55 ;
bool V_56 = false ;
enum V_57 V_57 ;
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_58 ) ) {
V_52 &= 0xffffffff ;
V_54 &= 0xffffffff ;
}
V_55 = ( V_52 == V_54 ) ;
V_55 = V_55 && ! ( V_2 -> V_4 . V_6 -> V_7 & V_59 ) ;
if ( V_18 == V_33 ) {
V_18 = V_31 ;
V_56 = true ;
}
switch ( V_18 ) {
case V_23 :
case V_24 :
V_51 = true ;
case V_25 :
case V_26 :
V_50 = true ;
case V_60 :
case V_61 :
case V_62 :
case V_63 :
case V_64 :
case V_65 :
case V_66 :
case V_67 :
V_48 = 1 ;
V_49 = V_68 | V_69 | V_70 ;
V_57 = V_71 ;
break;
case V_72 :
case V_73 :
V_48 = V_2 -> V_4 . V_6 -> V_7 & V_68 ;
V_48 = V_48 && ! V_55 ;
V_49 = V_69 ;
V_57 = V_74 ;
break;
case V_75 :
V_48 = V_2 -> V_4 . V_6 -> V_7 & V_69 ;
V_48 = V_48 && ! V_55 ;
V_57 = V_76 ;
break;
case V_27 :
case V_77 :
V_56 = true ;
case V_31 :
case V_78 :
V_48 = V_2 -> V_4 . V_6 -> V_7 & V_79 ;
V_48 = V_48 && ! V_55 ;
V_49 = V_68 | V_69 | V_70 ;
V_57 = V_71 ;
break;
case V_80 :
V_48 = V_2 -> V_4 . V_6 -> V_7 & V_70 ;
V_48 = V_48 && ! V_55 ;
V_49 = V_69 ;
V_57 = V_74 ;
break;
}
if ( V_48 ) {
switch ( V_57 ) {
case V_71 :
F_28 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_74 :
F_30 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_81 :
F_31 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
case V_76 :
F_33 ( V_2 , V_2 -> V_4 . V_5 ,
V_2 -> V_4 . V_6 -> V_7 ) ;
break;
}
V_2 -> V_4 . V_5 = V_2 -> V_4 . V_82 | V_2 -> V_4 . V_83 [ V_18 ] ;
if ( V_50 == true )
F_38 ( V_2 , V_2 -> V_4 . V_22 ) ;
if ( V_51 == true )
F_36 ( V_2 , V_2 -> V_4 . V_21 ) ;
F_12 ( V_2 , V_2 -> V_4 . V_6 -> V_7 & V_49 ) ;
if ( ! V_56 )
F_25 ( V_18 , & V_2 -> V_4 . V_12 ) ;
}
#ifdef F_13
if ( V_2 -> V_4 . V_12 & V_84 )
F_40 ( V_2 , V_71 ) ;
if ( V_2 -> V_4 . V_12 & V_85 )
F_40 ( V_2 , V_74 ) ;
if ( V_2 -> V_4 . V_12 & V_75 )
F_40 ( V_2 , V_76 ) ;
#endif
return V_48 ;
}
static void F_41 ( struct V_1 * V_2 )
{
if ( ( V_2 -> V_4 . V_86 & V_87 ) && ( V_2 -> V_4 . V_88 & V_89 ) )
F_21 ( V_2 ) ;
else
F_24 ( V_2 ) ;
}
static void F_42 ( struct V_1 * V_2 )
{
unsigned long * V_90 = & V_2 -> V_4 . V_12 ;
unsigned int V_18 ;
if ( V_2 -> V_91 ) {
if ( F_43 ( V_92 , V_2 ) ) {
F_44 () ;
F_41 ( V_2 ) ;
}
}
V_18 = F_45 ( * V_90 ) ;
while ( V_18 < V_93 ) {
if ( F_39 ( V_2 , V_18 ) )
break;
V_18 = F_46 ( V_90 ,
V_94 * sizeof( * V_90 ) ,
V_18 + 1 ) ;
}
V_2 -> V_4 . V_6 -> V_95 = ! ! * V_90 ;
}
int F_47 ( struct V_1 * V_2 )
{
int V_96 = 0 ;
F_48 ( ! F_49 () ) ;
F_42 ( V_2 ) ;
if ( V_2 -> V_4 . V_6 -> V_7 & V_97 ) {
F_50 () ;
F_51 ( V_2 ) ;
F_25 ( V_98 , & V_2 -> V_91 ) ;
F_52 () ;
F_53 ( V_2 , V_99 ) ;
V_96 = 1 ;
} ;
return V_96 ;
}
static int F_54 ( struct V_1 * V_2 )
{
int V_96 = 0 ;
F_48 ( ! F_49 () ) ;
while ( true ) {
if ( F_55 () ) {
F_50 () ;
F_56 () ;
F_52 () ;
continue;
}
if ( F_57 ( V_100 ) ) {
V_96 = 1 ;
break;
}
if ( F_47 ( V_2 ) ) {
continue;
}
break;
}
return V_96 ;
}
int F_58 ( struct V_101 * V_101 , struct V_1 * V_2 )
{
int V_102 ;
#ifdef F_59
unsigned int V_103 ;
int V_104 ;
T_3 V_105 [ 32 ] ;
#endif
if ( ! V_2 -> V_4 . V_106 ) {
V_101 -> V_107 = V_108 ;
return - V_109 ;
}
F_52 () ;
if ( F_54 ( V_2 ) ) {
V_101 -> V_107 = V_110 ;
V_102 = - V_111 ;
goto V_112;
}
F_60 () ;
#ifdef F_59
F_61 () ;
memcpy ( V_105 , V_100 -> V_113 . V_105 , sizeof( V_100 -> V_113 . V_105 ) ) ;
V_103 = V_100 -> V_113 . V_103 . V_114 ;
V_104 = V_100 -> V_113 . V_104 ;
memcpy ( V_100 -> V_113 . V_105 , V_2 -> V_4 . V_105 , sizeof( V_2 -> V_4 . V_105 ) ) ;
V_100 -> V_113 . V_103 . V_114 = V_2 -> V_4 . V_103 ;
V_2 -> V_115 = 1 ;
F_62 ( V_2 ) ;
#endif
V_102 = F_63 ( V_101 , V_2 ) ;
#ifdef F_59
F_64 ( V_2 ) ;
V_2 -> V_115 = 0 ;
memcpy ( V_2 -> V_4 . V_105 , V_100 -> V_113 . V_105 , sizeof( V_2 -> V_4 . V_105 ) ) ;
V_2 -> V_4 . V_103 = V_100 -> V_113 . V_103 . V_114 ;
memcpy ( V_100 -> V_113 . V_105 , V_105 , sizeof( V_100 -> V_113 . V_105 ) ) ;
V_100 -> V_113 . V_103 . V_114 = V_103 ;
V_100 -> V_113 . V_104 = V_104 ;
#endif
F_65 () ;
V_112:
F_50 () ;
return V_102 ;
}
static int F_66 ( struct V_101 * V_116 , struct V_1 * V_2 )
{
enum V_117 V_118 ;
V_118 = F_67 ( V_116 , V_2 ) ;
switch ( V_118 ) {
case V_119 :
F_68 ( V_2 , V_120 ) ;
return V_121 ;
case V_122 :
V_116 -> V_107 = V_123 ;
return V_124 ;
case V_125 :
F_2 ( V_126 L_6 ,
V_127 , V_2 -> V_4 . V_5 , V_2 -> V_4 . V_128 ) ;
V_116 -> V_129 . V_130 = ~ 0ULL << 32 ;
V_116 -> V_129 . V_130 |= V_2 -> V_4 . V_128 ;
F_20 ( V_2 , V_131 ) ;
return V_124 ;
default:
F_69 () ;
}
}
static void F_70 ( struct V_132 * V_133 )
{
T_2 V_134 , V_135 , V_7 , V_8 ;
asm("mr %0, 1" : "=r"(r1));
asm("mflr %0" : "=r"(lr));
asm("mfmsr %0" : "=r"(msr));
asm("bl 1f; 1: mflr %0" : "=r"(ip));
memset ( V_133 , 0 , sizeof( * V_133 ) ) ;
V_133 -> V_136 [ 1 ] = V_134 ;
V_133 -> V_137 = V_135 ;
V_133 -> V_7 = V_7 ;
V_133 -> V_138 = V_8 ;
}
static void F_71 ( struct V_1 * V_2 ,
unsigned int V_139 )
{
struct V_132 V_133 ;
switch ( V_139 ) {
case V_140 :
F_70 ( & V_133 ) ;
F_72 ( & V_133 ) ;
break;
case V_141 :
F_70 ( & V_133 ) ;
F_73 ( & V_133 ) ;
break;
#if F_74 ( V_142 ) || F_74 ( V_143 )
case V_144 :
F_70 ( & V_133 ) ;
F_75 ( & V_133 ) ;
break;
#endif
case V_145 :
break;
case V_146 :
F_70 ( & V_133 ) ;
F_76 ( & V_133 ) ;
break;
}
}
int F_77 ( struct V_101 * V_116 , struct V_1 * V_2 ,
unsigned int V_139 )
{
int V_96 = V_124 ;
F_78 ( V_2 ) ;
F_71 ( V_2 , V_139 ) ;
F_50 () ;
V_116 -> V_107 = V_147 ;
V_116 -> V_148 = 1 ;
switch ( V_139 ) {
case V_145 :
F_2 ( L_7 , F_35 ( V_149 ) ) ;
F_1 ( V_2 ) ;
V_116 -> V_129 . V_130 = ~ 1ULL << 32 ;
V_116 -> V_129 . V_130 |= F_35 ( V_149 ) ;
V_96 = V_124 ;
break;
case V_140 :
F_79 ( V_2 , V_150 ) ;
V_96 = V_151 ;
break;
case V_141 :
F_79 ( V_2 , V_152 ) ;
V_96 = V_151 ;
break;
case V_144 :
F_79 ( V_2 , V_153 ) ;
V_96 = V_151 ;
break;
case V_154 :
F_79 ( V_2 , V_155 ) ;
V_96 = V_151 ;
break;
case V_156 :
F_79 ( V_2 , V_155 ) ;
V_96 = V_151 ;
break;
case V_146 :
V_96 = V_151 ;
break;
case V_157 :
V_96 = F_66 ( V_116 , V_2 ) ;
break;
case V_158 :
if ( V_2 -> V_4 . V_6 -> V_7 & ( V_59 | V_17 ) ) {
F_20 ( V_2 , V_2 -> V_4 . V_159 ) ;
V_96 = V_151 ;
F_79 ( V_2 , V_160 ) ;
break;
}
V_96 = F_66 ( V_116 , V_2 ) ;
break;
case V_161 :
F_15 ( V_2 , V_62 ) ;
F_79 ( V_2 , V_162 ) ;
V_96 = V_151 ;
break;
#ifdef F_80
case V_163 : {
if ( V_2 -> V_4 . V_6 -> V_7 & V_14 )
F_9 ( V_2 ) ;
else
F_15 ( V_2 ,
V_63 ) ;
V_96 = V_151 ;
break;
}
case V_164 :
F_15 ( V_2 , V_64 ) ;
V_96 = V_151 ;
break;
case V_165 :
F_15 ( V_2 , V_65 ) ;
V_96 = V_151 ;
break;
#else
case V_163 :
F_20 ( V_2 , V_166 | V_167 ) ;
V_96 = V_151 ;
break;
case V_164 :
case V_165 :
F_2 ( V_126 L_8 ,
V_127 , V_139 , V_2 -> V_4 . V_5 ) ;
V_116 -> V_129 . V_130 = V_139 ;
V_96 = V_124 ;
break;
#endif
case V_168 :
F_18 ( V_2 , V_2 -> V_4 . V_169 ,
V_2 -> V_4 . V_159 ) ;
F_79 ( V_2 , V_170 ) ;
V_96 = V_151 ;
break;
case V_171 :
F_19 ( V_2 , V_2 -> V_4 . V_159 ) ;
F_79 ( V_2 , V_172 ) ;
V_96 = V_151 ;
break;
#ifdef F_13
case V_173 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_59 ) ) {
F_81 ( V_2 , 3 , F_82 ( V_2 ) ) ;
} else {
F_20 ( V_2 , V_174 ) ;
}
V_96 = V_151 ;
break;
#else
case V_175 :
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_59 ) &&
( ( ( T_1 ) F_3 ( V_2 , 0 ) ) == V_176 ) ) {
F_81 ( V_2 , 3 , F_82 ( V_2 ) ) ;
V_96 = V_151 ;
} else {
F_15 ( V_2 , V_61 ) ;
}
F_79 ( V_2 , V_177 ) ;
V_96 = V_151 ;
break;
#endif
case V_178 : {
unsigned long V_179 = V_2 -> V_4 . V_169 ;
int V_180 ;
T_4 V_181 ;
T_5 V_182 ;
#ifdef F_83
if ( ! ( V_2 -> V_4 . V_6 -> V_7 & V_59 ) &&
( V_179 & V_183 ) == V_2 -> V_4 . V_184 ) {
F_84 ( V_2 ) ;
F_79 ( V_2 , V_185 ) ;
V_96 = V_151 ;
break;
}
#endif
V_180 = F_85 ( V_2 , V_179 ) ;
if ( V_180 < 0 ) {
F_17 ( V_2 ,
V_2 -> V_4 . V_169 ,
V_2 -> V_4 . V_159 ) ;
F_86 ( V_2 ) ;
F_79 ( V_2 , V_186 ) ;
V_96 = V_151 ;
break;
}
V_181 = F_87 ( V_2 , V_180 , V_179 ) ;
V_182 = V_181 >> V_187 ;
if ( F_88 ( V_2 -> V_188 , V_182 ) ) {
F_89 ( V_2 , V_179 , V_181 , V_180 ) ;
F_79 ( V_2 , V_185 ) ;
V_96 = V_151 ;
} else {
V_2 -> V_4 . V_189 = V_181 ;
V_2 -> V_4 . V_190 = V_179 ;
V_96 = F_90 ( V_116 , V_2 ) ;
F_79 ( V_2 , V_191 ) ;
}
break;
}
case V_192 : {
unsigned long V_179 = V_2 -> V_4 . V_5 ;
T_4 V_181 ;
T_5 V_182 ;
int V_180 ;
V_96 = V_151 ;
V_180 = F_91 ( V_2 , V_179 ) ;
if ( V_180 < 0 ) {
F_15 ( V_2 , V_60 ) ;
F_92 ( V_2 ) ;
F_79 ( V_2 , V_193 ) ;
break;
}
F_79 ( V_2 , V_194 ) ;
V_181 = F_87 ( V_2 , V_180 , V_179 ) ;
V_182 = V_181 >> V_187 ;
if ( F_88 ( V_2 -> V_188 , V_182 ) ) {
F_89 ( V_2 , V_179 , V_181 , V_180 ) ;
} else {
F_15 ( V_2 , V_75 ) ;
}
break;
}
case V_195 : {
T_1 V_196 ;
V_2 -> V_4 . V_5 = F_35 ( V_197 ) ;
V_196 = F_35 ( V_198 ) ;
V_196 &= V_199 | V_200 | V_201 | V_202 ;
F_29 ( V_198 , V_196 ) ;
V_116 -> V_107 = V_203 ;
F_79 ( V_2 , V_204 ) ;
V_96 = V_124 ;
break;
}
default:
F_2 ( V_205 L_9 , V_139 ) ;
F_69 () ;
}
if ( ! ( V_96 & V_124 ) ) {
F_52 () ;
if ( F_54 ( V_2 ) ) {
V_116 -> V_107 = V_110 ;
V_96 = ( - V_111 << 2 ) | V_124 | ( V_96 & V_206 ) ;
F_79 ( V_2 , V_207 ) ;
}
}
return V_96 ;
}
int F_93 ( struct V_1 * V_2 )
{
int V_3 ;
int V_96 ;
V_2 -> V_4 . V_5 = 0 ;
V_2 -> V_4 . V_6 -> V_208 = V_2 -> V_209 ;
F_81 ( V_2 , 1 , ( 16 << 20 ) - 8 ) ;
F_12 ( V_2 , 0 ) ;
#ifndef F_13
V_2 -> V_4 . V_13 = V_210 | V_70 | V_211 | V_212 ;
V_2 -> V_4 . V_213 = 1 ;
V_2 -> V_4 . V_6 -> V_7 = 0 ;
#endif
V_2 -> V_4 . V_82 = 0x55550000 ;
for ( V_3 = 0 ; V_3 < V_93 ; V_3 ++ )
V_2 -> V_4 . V_83 [ V_3 ] = 0x7700 | V_3 * 4 ;
F_94 ( V_2 ) ;
V_96 = F_95 ( V_2 ) ;
F_96 ( V_2 ) ;
return V_96 ;
}
int F_97 ( struct V_1 * V_2 , struct V_214 * V_133 )
{
int V_3 ;
V_133 -> V_5 = V_2 -> V_4 . V_5 ;
V_133 -> V_215 = F_98 ( V_2 ) ;
V_133 -> V_9 = V_2 -> V_4 . V_9 ;
V_133 -> V_8 = V_2 -> V_4 . V_8 ;
V_133 -> V_216 = F_99 ( V_2 ) ;
V_133 -> V_7 = V_2 -> V_4 . V_6 -> V_7 ;
V_133 -> V_10 = V_2 -> V_4 . V_6 -> V_10 ;
V_133 -> V_11 = V_2 -> V_4 . V_6 -> V_11 ;
V_133 -> V_217 = V_2 -> V_4 . V_217 ;
V_133 -> V_218 = V_2 -> V_4 . V_6 -> V_218 ;
V_133 -> V_219 = V_2 -> V_4 . V_6 -> V_219 ;
V_133 -> V_220 = V_2 -> V_4 . V_6 -> V_220 ;
V_133 -> V_221 = V_2 -> V_4 . V_6 -> V_221 ;
V_133 -> V_222 = V_2 -> V_4 . V_6 -> V_222 ;
V_133 -> V_223 = V_2 -> V_4 . V_6 -> V_223 ;
V_133 -> V_224 = V_2 -> V_4 . V_6 -> V_224 ;
V_133 -> V_225 = V_2 -> V_4 . V_6 -> V_225 ;
for ( V_3 = 0 ; V_3 < F_100 ( V_133 -> V_136 ) ; V_3 ++ )
V_133 -> V_136 [ V_3 ] = F_3 ( V_2 , V_3 ) ;
return 0 ;
}
int F_101 ( struct V_1 * V_2 , struct V_214 * V_133 )
{
int V_3 ;
V_2 -> V_4 . V_5 = V_133 -> V_5 ;
F_102 ( V_2 , V_133 -> V_215 ) ;
V_2 -> V_4 . V_9 = V_133 -> V_9 ;
V_2 -> V_4 . V_8 = V_133 -> V_8 ;
F_103 ( V_2 , V_133 -> V_216 ) ;
F_12 ( V_2 , V_133 -> V_7 ) ;
V_2 -> V_4 . V_6 -> V_10 = V_133 -> V_10 ;
V_2 -> V_4 . V_6 -> V_11 = V_133 -> V_11 ;
F_104 ( V_2 , V_133 -> V_217 ) ;
V_2 -> V_4 . V_6 -> V_218 = V_133 -> V_218 ;
V_2 -> V_4 . V_6 -> V_219 = V_133 -> V_219 ;
V_2 -> V_4 . V_6 -> V_220 = V_133 -> V_220 ;
V_2 -> V_4 . V_6 -> V_221 = V_133 -> V_221 ;
V_2 -> V_4 . V_6 -> V_222 = V_133 -> V_222 ;
V_2 -> V_4 . V_6 -> V_223 = V_133 -> V_223 ;
V_2 -> V_4 . V_6 -> V_224 = V_133 -> V_224 ;
V_2 -> V_4 . V_6 -> V_225 = V_133 -> V_225 ;
for ( V_3 = 0 ; V_3 < F_100 ( V_133 -> V_136 ) ; V_3 ++ )
F_81 ( V_2 , V_3 , V_133 -> V_136 [ V_3 ] ) ;
return 0 ;
}
static void F_105 ( struct V_1 * V_2 ,
struct V_226 * V_227 )
{
T_3 V_228 = F_106 () ;
V_227 -> V_229 . V_230 . V_231 |= V_232 ;
V_227 -> V_229 . V_230 . V_36 = V_2 -> V_4 . V_36 ;
V_227 -> V_229 . V_230 . V_37 = V_2 -> V_4 . V_37 ;
V_227 -> V_229 . V_230 . V_233 = V_2 -> V_4 . V_233 ;
V_227 -> V_229 . V_230 . V_47 = F_37 ( V_2 ) ;
V_227 -> V_229 . V_230 . V_45 = F_34 ( V_2 ) ;
V_227 -> V_229 . V_230 . V_88 = V_2 -> V_4 . V_88 ;
V_227 -> V_229 . V_230 . V_86 = V_2 -> V_4 . V_86 ;
V_227 -> V_229 . V_230 . V_234 = F_107 ( V_2 , V_228 ) ;
V_227 -> V_229 . V_230 . V_228 = V_228 ;
V_227 -> V_229 . V_230 . V_235 = V_2 -> V_4 . V_235 ;
}
static int F_108 ( struct V_1 * V_2 ,
struct V_226 * V_227 )
{
if ( ! ( V_227 -> V_229 . V_230 . V_231 & V_232 ) )
return 0 ;
V_2 -> V_4 . V_36 = V_227 -> V_229 . V_230 . V_36 ;
V_2 -> V_4 . V_37 = V_227 -> V_229 . V_230 . V_37 ;
V_2 -> V_4 . V_233 = V_227 -> V_229 . V_230 . V_233 ;
F_38 ( V_2 , V_227 -> V_229 . V_230 . V_47 ) ;
F_36 ( V_2 , V_227 -> V_229 . V_230 . V_45 ) ;
V_2 -> V_4 . V_235 = V_227 -> V_229 . V_230 . V_235 ;
F_109 ( V_2 , V_227 -> V_229 . V_230 . V_86 ) ;
if ( V_227 -> V_229 . V_230 . V_236 & V_237 ) {
V_2 -> V_4 . V_234 = V_227 -> V_229 . V_230 . V_234 ;
F_110 ( V_2 ) ;
}
if ( V_227 -> V_229 . V_230 . V_236 & V_238 ) {
V_2 -> V_4 . V_88 = V_227 -> V_229 . V_230 . V_88 ;
F_41 ( V_2 ) ;
}
return 0 ;
}
static void F_111 ( struct V_1 * V_2 ,
struct V_226 * V_227 )
{
V_227 -> V_229 . V_230 . V_231 |= V_239 ;
V_227 -> V_229 . V_230 . V_208 = V_2 -> V_209 ;
V_227 -> V_229 . V_230 . V_41 = V_2 -> V_4 . V_41 ;
V_227 -> V_229 . V_230 . V_42 = V_2 -> V_4 . V_42 ;
V_227 -> V_229 . V_230 . V_240 = V_2 -> V_4 . V_240 ;
V_227 -> V_229 . V_230 . V_82 = V_2 -> V_4 . V_82 ;
}
static int F_112 ( struct V_1 * V_2 ,
struct V_226 * V_227 )
{
if ( ! ( V_227 -> V_229 . V_230 . V_231 & V_239 ) )
return 0 ;
if ( V_227 -> V_229 . V_230 . V_208 != V_2 -> V_209 )
return - V_109 ;
V_2 -> V_4 . V_41 = V_227 -> V_229 . V_230 . V_41 ;
V_2 -> V_4 . V_42 = V_227 -> V_229 . V_230 . V_42 ;
V_2 -> V_4 . V_240 = V_227 -> V_229 . V_230 . V_240 ;
V_2 -> V_4 . V_82 = V_227 -> V_229 . V_230 . V_82 ;
return 0 ;
}
void F_113 ( struct V_1 * V_2 , struct V_226 * V_227 )
{
V_227 -> V_229 . V_230 . V_231 |= V_241 ;
V_227 -> V_229 . V_230 . V_242 [ 0 ] = V_2 -> V_4 . V_83 [ V_72 ] ;
V_227 -> V_229 . V_230 . V_242 [ 1 ] = V_2 -> V_4 . V_83 [ V_75 ] ;
V_227 -> V_229 . V_230 . V_242 [ 2 ] = V_2 -> V_4 . V_83 [ V_24 ] ;
V_227 -> V_229 . V_230 . V_242 [ 3 ] = V_2 -> V_4 . V_83 [ V_25 ] ;
V_227 -> V_229 . V_230 . V_242 [ 4 ] = V_2 -> V_4 . V_83 [ V_31 ] ;
V_227 -> V_229 . V_230 . V_242 [ 5 ] = V_2 -> V_4 . V_83 [ V_67 ] ;
V_227 -> V_229 . V_230 . V_242 [ 6 ] = V_2 -> V_4 . V_83 [ V_26 ] ;
V_227 -> V_229 . V_230 . V_242 [ 7 ] = V_2 -> V_4 . V_83 [ V_62 ] ;
V_227 -> V_229 . V_230 . V_242 [ 8 ] = V_2 -> V_4 . V_83 [ V_61 ] ;
V_227 -> V_229 . V_230 . V_242 [ 9 ] = V_2 -> V_4 . V_83 [ V_66 ] ;
V_227 -> V_229 . V_230 . V_242 [ 10 ] = V_2 -> V_4 . V_83 [ V_27 ] ;
V_227 -> V_229 . V_230 . V_242 [ 11 ] = V_2 -> V_4 . V_83 [ V_77 ] ;
V_227 -> V_229 . V_230 . V_242 [ 12 ] = V_2 -> V_4 . V_83 [ V_243 ] ;
V_227 -> V_229 . V_230 . V_242 [ 13 ] = V_2 -> V_4 . V_83 [ V_23 ] ;
V_227 -> V_229 . V_230 . V_242 [ 14 ] = V_2 -> V_4 . V_83 [ V_60 ] ;
V_227 -> V_229 . V_230 . V_242 [ 15 ] = V_2 -> V_4 . V_83 [ V_80 ] ;
}
int F_114 ( struct V_1 * V_2 , struct V_226 * V_227 )
{
if ( ! ( V_227 -> V_229 . V_230 . V_231 & V_241 ) )
return 0 ;
V_2 -> V_4 . V_83 [ V_72 ] = V_227 -> V_229 . V_230 . V_242 [ 0 ] ;
V_2 -> V_4 . V_83 [ V_75 ] = V_227 -> V_229 . V_230 . V_242 [ 1 ] ;
V_2 -> V_4 . V_83 [ V_24 ] = V_227 -> V_229 . V_230 . V_242 [ 2 ] ;
V_2 -> V_4 . V_83 [ V_25 ] = V_227 -> V_229 . V_230 . V_242 [ 3 ] ;
V_2 -> V_4 . V_83 [ V_31 ] = V_227 -> V_229 . V_230 . V_242 [ 4 ] ;
V_2 -> V_4 . V_83 [ V_67 ] = V_227 -> V_229 . V_230 . V_242 [ 5 ] ;
V_2 -> V_4 . V_83 [ V_26 ] = V_227 -> V_229 . V_230 . V_242 [ 6 ] ;
V_2 -> V_4 . V_83 [ V_62 ] = V_227 -> V_229 . V_230 . V_242 [ 7 ] ;
V_2 -> V_4 . V_83 [ V_61 ] = V_227 -> V_229 . V_230 . V_242 [ 8 ] ;
V_2 -> V_4 . V_83 [ V_66 ] = V_227 -> V_229 . V_230 . V_242 [ 9 ] ;
V_2 -> V_4 . V_83 [ V_27 ] = V_227 -> V_229 . V_230 . V_242 [ 10 ] ;
V_2 -> V_4 . V_83 [ V_77 ] = V_227 -> V_229 . V_230 . V_242 [ 11 ] ;
V_2 -> V_4 . V_83 [ V_243 ] = V_227 -> V_229 . V_230 . V_242 [ 12 ] ;
V_2 -> V_4 . V_83 [ V_23 ] = V_227 -> V_229 . V_230 . V_242 [ 13 ] ;
V_2 -> V_4 . V_83 [ V_60 ] = V_227 -> V_229 . V_230 . V_242 [ 14 ] ;
V_2 -> V_4 . V_83 [ V_80 ] = V_227 -> V_229 . V_230 . V_242 [ 15 ] ;
return 0 ;
}
int F_115 ( struct V_1 * V_2 ,
struct V_226 * V_227 )
{
V_227 -> V_244 = V_2 -> V_4 . V_244 ;
F_105 ( V_2 , V_227 ) ;
F_111 ( V_2 , V_227 ) ;
F_116 ( V_2 , V_227 ) ;
return 0 ;
}
int F_117 ( struct V_1 * V_2 ,
struct V_226 * V_227 )
{
int V_102 ;
if ( V_2 -> V_4 . V_244 != V_227 -> V_244 )
return - V_109 ;
V_102 = F_108 ( V_2 , V_227 ) ;
if ( V_102 < 0 )
return V_102 ;
V_102 = F_112 ( V_2 , V_227 ) ;
if ( V_102 < 0 )
return V_102 ;
return F_118 ( V_2 , V_227 ) ;
}
int F_119 ( struct V_1 * V_2 , struct V_245 * V_246 )
{
return - V_109 ;
}
int F_120 ( struct V_1 * V_2 , struct V_245 * V_246 )
{
return - V_109 ;
}
int F_121 ( struct V_1 * V_2 , struct V_247 * V_248 )
{
return - V_249 ;
}
int F_122 ( struct V_1 * V_2 , struct V_247 * V_248 )
{
return - V_249 ;
}
int F_123 ( struct V_1 * V_2 ,
struct V_250 * V_251 )
{
int V_96 ;
V_96 = F_124 ( V_2 , V_251 ) ;
return V_96 ;
}
int F_125 ( struct V_188 * V_188 , struct V_252 * log )
{
return - V_249 ;
}
int F_126 ( struct V_188 * V_188 ,
struct V_253 * V_254 )
{
return 0 ;
}
void F_127 ( struct V_188 * V_188 ,
struct V_253 * V_254 )
{
}
void F_109 ( struct V_1 * V_2 , T_1 V_255 )
{
V_2 -> V_4 . V_86 = V_255 ;
F_41 ( V_2 ) ;
}
void F_128 ( struct V_1 * V_2 , T_1 V_256 )
{
F_129 ( V_256 , & V_2 -> V_4 . V_88 ) ;
F_130 () ;
F_131 ( V_92 , V_2 ) ;
F_132 ( V_2 ) ;
}
void F_133 ( struct V_1 * V_2 , T_1 V_256 )
{
F_134 ( V_256 , & V_2 -> V_4 . V_88 ) ;
F_41 ( V_2 ) ;
}
void F_135 ( unsigned long V_257 )
{
struct V_1 * V_2 = (struct V_1 * ) V_257 ;
F_128 ( V_2 , V_89 ) ;
}
void F_136 ( struct V_1 * V_2 , int V_258 )
{
V_100 -> V_113 . V_1 = V_2 ;
}
void F_137 ( struct V_1 * V_2 )
{
V_100 -> V_113 . V_1 = NULL ;
}
int T_6 F_138 ( void )
{
#ifndef F_13
unsigned long V_83 [ 16 ] ;
unsigned long V_259 = 0 ;
int V_3 ;
V_260 = F_139 ( V_261 | V_262 ,
V_263 ) ;
if ( ! V_260 )
return - V_264 ;
V_83 [ 0 ] = F_35 ( V_265 ) ;
V_83 [ 1 ] = F_35 ( V_266 ) ;
V_83 [ 2 ] = F_35 ( V_267 ) ;
V_83 [ 3 ] = F_35 ( V_268 ) ;
V_83 [ 4 ] = F_35 ( V_269 ) ;
V_83 [ 5 ] = F_35 ( V_270 ) ;
V_83 [ 6 ] = F_35 ( V_271 ) ;
V_83 [ 7 ] = F_35 ( V_272 ) ;
V_83 [ 8 ] = F_35 ( V_273 ) ;
V_83 [ 9 ] = F_35 ( V_274 ) ;
V_83 [ 10 ] = F_35 ( V_275 ) ;
V_83 [ 11 ] = F_35 ( V_276 ) ;
V_83 [ 12 ] = F_35 ( V_277 ) ;
V_83 [ 13 ] = F_35 ( V_278 ) ;
V_83 [ 14 ] = F_35 ( V_279 ) ;
V_83 [ 15 ] = F_35 ( V_280 ) ;
for ( V_3 = 0 ; V_3 < 16 ; V_3 ++ ) {
if ( V_83 [ V_3 ] > V_259 )
V_259 = V_83 [ V_3 ] ;
memcpy ( ( void * ) V_260 + V_83 [ V_3 ] ,
V_281 + V_3 * V_282 ,
V_282 ) ;
}
F_140 ( V_260 ,
V_260 + V_259 + V_282 ) ;
#endif
return 0 ;
}
void T_7 F_141 ( void )
{
F_142 ( V_260 , V_263 ) ;
F_143 () ;
}
