static void * F_1 ( void )
{
return F_1 ;
}
static inline int F_2 ( struct V_1 * V_2 ,
char * V_3 , const char * V_4 )
{
#ifdef F_3
static const char * V_5 =
L_1 ;
static const char * V_6 =
L_2 ;
if ( ! V_2 ) {
F_4 ( V_6 , V_3 , V_4 ) ;
return 1 ;
}
if ( V_2 -> V_7 != V_8 ) {
F_4 ( V_5 , V_3 , V_4 ) ;
return 1 ;
}
#else
if ( ! V_2 )
return 1 ;
#endif
return 0 ;
}
static void F_5 ( struct V_9 * V_10 ,
const T_1 * V_11 , char * V_12 , int V_13 )
{
struct V_14 * V_15 ;
if ( ! V_10 )
return;
V_15 = F_6 ( V_10 ) ;
if ( V_15 ) {
if ( V_15 -> V_16 -> V_17 )
V_15 -> V_16 -> V_17 ( V_10 , V_11 , V_12 , V_13 ) ;
F_7 ( V_15 ) ;
}
}
static void F_8 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_3 ) )
return;
if ( V_19 >= V_20 )
F_4 ( L_4 , V_2 -> V_21 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_2 -> V_23 )
F_10 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static void F_12 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_5 ) )
return;
if ( V_19 >= V_20 )
F_4 ( L_6 , V_2 -> V_21 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! V_2 -> V_23 )
F_13 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static int F_14 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
int V_24 = 0 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_2 -> V_25 & V_26 ) {
V_2 -> V_25 &= ~ V_26 ;
V_24 = V_26 ;
} else if ( V_2 -> V_25 & V_27 ) {
V_2 -> V_25 &= ~ V_27 ;
V_24 = V_27 ;
} else if ( V_2 -> V_25 & V_28 ) {
V_2 -> V_25 &= ~ V_28 ;
V_24 = V_28 ;
}
if ( ! V_24 ) {
V_2 -> V_29 = false ;
V_2 -> V_30 = false ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_24 ;
}
static void F_15 ( struct V_31 * V_32 )
{
struct V_1 * V_2 =
F_16 ( V_32 , struct V_1 , V_33 ) ;
int V_34 ;
if ( V_19 >= V_35 )
F_4 ( L_7 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
V_2 -> V_29 = true ;
while( ( V_34 = F_14 ( V_2 ) ) != 0 ) {
if ( V_19 >= V_35 )
F_4 ( L_8 ,
__FILE__ , __LINE__ , V_34 ) ;
switch ( V_34 ) {
case V_26 :
F_17 ( V_2 ) ;
break;
case V_27 :
F_18 ( V_2 ) ;
break;
case V_28 :
F_19 ( V_2 ) ;
break;
default:
F_4 ( L_9 , V_34 ) ;
break;
}
}
if ( V_19 >= V_35 )
F_4 ( L_10 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
bool (* F_20)( struct V_1 * V_2 ) =
( V_2 -> V_36 . V_37 == V_38 ? V_39 : V_40 );
if ( V_19 >= V_35 )
F_4 ( L_11 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
do
{
if ( V_2 -> V_41 ) {
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return;
}
} while( F_20 ( V_2 ) );
}
static void F_18 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_42 . V_10 ;
unsigned long V_12 ;
if ( V_19 >= V_35 )
F_4 ( L_12 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( V_10 )
F_22 ( V_10 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! V_2 -> V_43 && V_2 -> V_44 )
F_23 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static void F_19 ( struct V_1 * V_2 )
{
if ( V_19 >= V_35 )
F_4 ( L_13 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
V_2 -> V_45 = 0 ;
V_2 -> V_46 = 0 ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = 0 ;
}
static void F_24 ( struct V_1 * V_2 )
{
T_2 V_49 = F_25 ( V_2 , V_50 ) ;
if ( V_19 >= V_51 )
F_4 ( L_14 ,
__FILE__ , __LINE__ , V_49 ) ;
if ( ( V_49 & V_52 ) &&
V_2 -> V_53 &&
F_26 ( V_2 ) )
{
++ V_2 -> V_54 . V_55 ;
V_2 -> V_53 = false ;
V_2 -> V_56 &= ~ V_57 ;
F_27 ( V_2 , V_58 , V_2 -> V_56 ) ;
F_27 ( V_2 , V_59 ,
( F_25 ( V_2 , V_59 ) & ~ V_52 ) ) ;
}
if ( V_49 & ( V_60 | V_61 ) ) {
if ( V_49 & V_60 )
V_2 -> V_54 . V_62 ++ ;
if ( V_49 & V_61 )
V_2 -> V_54 . V_63 ++ ;
F_28 ( & V_2 -> V_64 ) ;
}
if ( V_49 & V_65 ) {
V_2 -> V_54 . V_66 ++ ;
F_29 ( V_2 ) ;
}
F_30 ( V_2 , V_67 ) ;
F_31 ( V_2 , V_49 ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
T_2 V_49 = F_25 ( V_2 , V_68 ) ;
if ( V_19 >= V_51 )
F_4 ( L_15 ,
__FILE__ , __LINE__ , V_49 ) ;
F_30 ( V_2 , V_69 ) ;
F_33 ( V_2 , V_49 ) ;
if ( V_49 & ( V_70 | V_71 ) )
{
F_34 ( V_2 , V_72 ) ;
F_35 ( V_2 , V_73 ) ;
}
if ( V_49 & V_74 )
V_2 -> V_54 . V_75 ++ ;
else if ( V_49 & V_70 )
V_2 -> V_54 . V_76 ++ ;
else if ( V_49 & V_71 )
V_2 -> V_54 . V_77 ++ ;
else
V_2 -> V_54 . V_76 ++ ;
V_2 -> V_43 = false ;
V_2 -> V_78 = V_2 -> V_79 = V_2 -> V_80 = 0 ;
F_36 ( & V_2 -> V_81 ) ;
if ( V_2 -> V_82 ) {
F_37 ( V_2 ) ;
if ( V_2 -> V_83 & V_84 ) {
V_2 -> V_83 &= ~ V_84 ;
F_38 ( V_2 ) ;
}
V_2 -> V_82 = false ;
}
#if V_85
if ( V_2 -> V_86 )
F_39 ( V_2 ) ;
else
#endif
{
if ( V_2 -> V_42 . V_10 -> V_87 || V_2 -> V_42 . V_10 -> V_88 ) {
F_10 ( V_2 ) ;
return;
}
V_2 -> V_25 |= V_27 ;
}
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_89 * V_54 ;
T_2 V_49 = F_25 ( V_2 , V_90 ) ;
if ( V_19 >= V_51 )
F_4 ( L_16 ,
__FILE__ , __LINE__ , V_49 ) ;
F_30 ( V_2 , V_91 ) ;
F_41 ( V_2 , V_49 ) ;
if ( V_49 & ( V_92 | V_93 |
V_94 | V_95 ) ) {
V_54 = & V_2 -> V_54 ;
if ( V_49 & V_95 ) {
if ( ( V_2 -> V_45 ) ++ >= V_96 )
F_42 ( V_2 , V_97 ) ;
V_54 -> V_98 ++ ;
if ( V_49 & V_99 )
V_2 -> V_100 . V_101 ++ ;
else
V_2 -> V_100 . V_102 ++ ;
}
if ( V_49 & V_94 ) {
if ( ( V_2 -> V_46 ) ++ >= V_96 )
F_42 ( V_2 , V_103 ) ;
V_54 -> V_104 ++ ;
if ( V_49 & V_105 )
V_2 -> V_100 . V_106 ++ ;
else
V_2 -> V_100 . V_107 ++ ;
}
if ( V_49 & V_93 ) {
if ( ( V_2 -> V_47 ) ++ >= V_96 )
F_42 ( V_2 , V_108 ) ;
V_54 -> V_109 ++ ;
if ( V_49 & V_110 ) {
V_2 -> V_100 . V_111 ++ ;
} else
V_2 -> V_100 . V_112 ++ ;
#if V_85
if ( V_2 -> V_86 ) {
if ( V_49 & V_110 )
F_43 ( V_2 -> V_113 ) ;
else
F_44 ( V_2 -> V_113 ) ;
}
#endif
}
if ( V_49 & V_92 )
{
if ( ( V_2 -> V_48 ) ++ >= V_96 )
F_42 ( V_2 , V_114 ) ;
V_54 -> V_115 ++ ;
if ( V_49 & V_116 )
V_2 -> V_100 . V_117 ++ ;
else
V_2 -> V_100 . V_118 ++ ;
}
F_28 ( & V_2 -> V_119 ) ;
F_28 ( & V_2 -> V_64 ) ;
if ( F_45 ( & V_2 -> V_42 ) &&
( V_49 & V_93 ) ) {
if ( V_19 >= V_51 )
F_4 ( L_17 , V_2 -> V_21 ,
( V_49 & V_110 ) ? L_18 : L_19 ) ;
if ( V_49 & V_110 )
F_28 ( & V_2 -> V_42 . V_120 ) ;
else {
if ( V_19 >= V_51 )
F_4 ( L_20 ) ;
if ( V_2 -> V_42 . V_10 )
F_46 ( V_2 -> V_42 . V_10 ) ;
}
}
if ( F_47 ( & V_2 -> V_42 ) &&
( V_49 & V_92 ) ) {
if ( V_2 -> V_42 . V_10 -> V_88 ) {
if ( V_49 & V_116 ) {
if ( V_19 >= V_51 )
F_4 ( L_21 ) ;
V_2 -> V_42 . V_10 -> V_88 = 0 ;
F_13 ( V_2 ) ;
V_2 -> V_25 |= V_27 ;
return;
}
} else {
if ( ! ( V_49 & V_116 ) ) {
if ( V_19 >= V_51 )
F_4 ( L_22 ) ;
if ( V_2 -> V_42 . V_10 )
V_2 -> V_42 . V_10 -> V_88 = 1 ;
F_10 ( V_2 ) ;
}
}
}
}
V_2 -> V_25 |= V_28 ;
if ( V_49 & V_121 ) {
F_27 ( V_2 , V_122 ,
( unsigned short ) ( F_25 ( V_2 , V_122 ) & ~ ( V_123 + V_124 ) ) ) ;
F_41 ( V_2 , V_121 ) ;
V_2 -> V_125 = true ;
}
}
static void F_48 ( struct V_1 * V_2 )
{
if ( V_19 >= V_51 )
F_4 ( L_23 ,
__FILE__ , __LINE__ , V_2 -> V_78 ) ;
F_30 ( V_2 , V_126 ) ;
if ( V_2 -> V_42 . V_10 -> V_87 || V_2 -> V_42 . V_10 -> V_88 ) {
F_10 ( V_2 ) ;
return;
}
if ( V_2 -> V_78 )
F_49 ( V_2 ) ;
else
V_2 -> V_43 = false ;
if ( V_2 -> V_78 < V_127 )
V_2 -> V_25 |= V_27 ;
}
static void F_50 ( struct V_1 * V_2 )
{
int V_128 ;
T_2 V_49 ;
int V_32 = 0 ;
unsigned char V_129 ;
struct V_89 * V_54 = & V_2 -> V_54 ;
if ( V_19 >= V_51 )
F_4 ( L_24 ,
__FILE__ , __LINE__ ) ;
F_30 ( V_2 , V_130 ) ;
F_51 ( V_2 , V_131 ) ;
F_27 ( V_2 , V_59 + V_132 , ( T_2 ) ( F_25 ( V_2 , V_59 + V_132 ) & ~ V_133 ) ) ;
while( ( V_128 = ( F_25 ( V_2 , V_59 ) >> 8 ) ) ) {
int V_134 ;
F_52 ( ( F_53 ( V_2 -> V_135 + V_136 ) & 0x0780 ) | ( V_137 + V_132 ) ,
V_2 -> V_135 + V_136 ) ;
V_129 = F_54 ( V_2 -> V_135 + V_136 ) ;
V_49 = F_25 ( V_2 , V_50 ) ;
if ( V_49 & ( V_138 | V_139 |
V_65 | V_140 ) )
F_31 ( V_2 , V_141 ) ;
V_54 -> V_142 ++ ;
V_134 = 0 ;
if ( V_49 & ( V_138 | V_139 |
V_65 | V_140 ) ) {
F_4 ( L_25 , V_49 ) ;
if ( V_49 & V_140 ) {
V_49 &= ~ ( V_138 | V_139 ) ;
V_54 -> V_143 ++ ;
} else if ( V_49 & V_139 )
V_54 -> V_144 ++ ;
else if ( V_49 & V_138 )
V_54 -> V_145 ++ ;
else if ( V_49 & V_65 ) {
F_35 ( V_2 , V_146 ) ;
V_54 -> V_147 ++ ;
}
if ( V_49 & V_2 -> V_148 )
continue;
V_49 &= V_2 -> V_149 ;
if ( V_49 & V_140 ) {
V_134 = V_150 ;
if ( V_2 -> V_42 . V_12 & V_151 )
F_55 ( V_2 -> V_42 . V_10 ) ;
} else if ( V_49 & V_139 )
V_134 = V_152 ;
else if ( V_49 & V_138 )
V_134 = V_153 ;
}
F_56 ( & V_2 -> V_42 , V_129 , V_134 ) ;
if ( V_49 & V_65 ) {
V_32 += F_56 ( & V_2 -> V_42 , 0 , V_154 ) ;
}
}
if ( V_19 >= V_51 ) {
F_4 ( L_26 ,
__FILE__ , __LINE__ , V_54 -> V_142 , V_54 -> V_143 ,
V_54 -> V_144 , V_54 -> V_145 , V_54 -> V_147 ) ;
}
if( V_32 )
F_57 ( & V_2 -> V_42 ) ;
}
static void F_58 ( struct V_1 * V_2 )
{
T_2 V_49 = F_25 ( V_2 , V_90 ) ;
if ( V_19 >= V_51 )
F_4 ( L_27 ,
__FILE__ , __LINE__ , V_49 ) ;
if ( ( V_49 & V_155 ) &&
( V_2 -> V_36 . V_37 == V_38 ) ) {
F_59 ( V_2 , V_156 ) ;
F_34 ( V_2 , V_157 ) ;
F_31 ( V_2 , V_141 ) ;
F_30 ( V_2 , V_130 | V_67 ) ;
F_60 ( V_2 , V_130 | V_67 ) ;
V_2 -> V_25 |= V_26 ;
V_2 -> V_41 = true ;
}
F_30 ( V_2 , V_158 ) ;
F_61 ( V_2 , V_49 ) ;
}
static void F_62 ( struct V_1 * V_2 )
{
}
static void F_63 ( struct V_1 * V_2 )
{
T_2 V_49 ;
F_64 ( V_2 , V_159 , V_160 | V_161 ) ;
V_49 = F_65 ( V_2 , V_162 ) ;
if ( V_19 >= V_51 )
F_4 ( L_28 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_49 ) ;
V_2 -> V_25 |= V_26 ;
if ( V_49 & V_133 ) {
V_2 -> V_163 = true ;
V_2 -> V_54 . V_164 ++ ;
}
}
static void F_66 ( struct V_1 * V_2 )
{
T_2 V_49 ;
F_64 ( V_2 , V_159 , V_165 | V_166 ) ;
V_49 = F_65 ( V_2 , V_167 ) ;
if ( V_19 >= V_51 )
F_4 ( L_29 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_49 ) ;
if ( V_49 & V_168 ) {
-- V_2 -> V_169 ;
if ( F_67 ( V_2 ) ) {
V_2 -> V_25 |= V_27 ;
}
}
}
static T_3 F_68 ( int V_170 , void * V_171 )
{
struct V_1 * V_2 = V_171 ;
T_2 V_172 ;
T_2 V_173 ;
if ( V_19 >= V_51 )
F_4 ( V_174 L_30 ,
__FILE__ , __LINE__ , V_2 -> V_175 ) ;
F_69 ( & V_2 -> V_22 ) ;
for(; ; ) {
V_172 = F_25 ( V_2 , V_176 ) >> 9 ;
V_173 = F_65 ( V_2 , V_177 ) ;
if ( V_19 >= V_51 )
F_4 ( L_31 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_172 , V_173 ) ;
if ( ! V_172 && ! V_173 )
break;
if ( V_172 )
(* F_70 [ V_172 ])( V_2 ) ;
else if ( ( V_173 & ( V_178 | V_160 ) ) == V_178 )
F_66 ( V_2 ) ;
else
F_63 ( V_2 ) ;
if ( V_2 -> V_179 ) {
F_4 ( V_180 L_32 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_175 ) ;
F_71 ( V_2 ) ;
F_72 ( V_2 , V_181 ) ;
break;
}
}
if ( V_2 -> V_25 && ! V_2 -> V_29 && ! V_2 -> V_30 ) {
if ( V_19 >= V_51 )
F_4 ( L_33 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_73 ( & V_2 -> V_33 ) ;
V_2 -> V_30 = true ;
}
F_74 ( & V_2 -> V_22 ) ;
if ( V_19 >= V_51 )
F_4 ( V_174 L_34 ,
__FILE__ , __LINE__ , V_2 -> V_175 ) ;
return V_182 ;
}
static int F_75 ( struct V_1 * V_2 )
{
int V_183 = 0 ;
if ( V_19 >= V_20 )
F_4 ( L_35 , __FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( F_76 ( & V_2 -> V_42 ) )
return 0 ;
if ( ! V_2 -> V_184 ) {
V_2 -> V_184 = ( unsigned char * ) F_77 ( V_185 ) ;
if ( ! V_2 -> V_184 ) {
F_4 ( V_180 L_36 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return - V_186 ;
}
}
V_2 -> V_25 = 0 ;
memset ( & V_2 -> V_54 , 0 , sizeof( V_2 -> V_54 ) ) ;
F_78 ( & V_2 -> V_81 , V_187 , ( unsigned long ) V_2 ) ;
V_183 = F_79 ( V_2 ) ;
if ( ! V_183 )
V_183 = F_80 ( V_2 ) ;
if ( V_183 ) {
if ( F_81 ( V_188 ) && V_2 -> V_42 . V_10 )
F_82 ( V_189 , & V_2 -> V_42 . V_10 -> V_12 ) ;
F_83 ( V_2 ) ;
return V_183 ;
}
F_84 ( V_2 ) ;
if ( V_2 -> V_42 . V_10 )
F_85 ( V_189 , & V_2 -> V_42 . V_10 -> V_12 ) ;
F_86 ( & V_2 -> V_42 , 1 ) ;
return 0 ;
}
static void F_87 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
if ( ! F_76 ( & V_2 -> V_42 ) )
return;
if ( V_19 >= V_20 )
F_4 ( L_37 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_28 ( & V_2 -> V_119 ) ;
F_28 ( & V_2 -> V_64 ) ;
F_88 ( & V_2 -> V_81 ) ;
if ( V_2 -> V_184 ) {
F_89 ( ( unsigned long ) V_2 -> V_184 ) ;
V_2 -> V_184 = NULL ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_71 ( V_2 ) ;
F_90 ( V_2 ) ;
F_10 ( V_2 ) ;
F_60 ( V_2 , V_130 | V_67 |
V_126 | V_69 | V_91 | V_158 ) ;
F_72 ( V_2 , V_181 + V_190 + V_191 ) ;
F_27 ( V_2 , V_192 , ( T_2 ) ( ( F_25 ( V_2 , V_192 ) | V_193 ) | V_194 ) ) ;
F_27 ( V_2 , V_192 , ( T_2 ) ( ( F_25 ( V_2 , V_192 ) | V_57 ) | V_195 ) ) ;
if ( ! V_2 -> V_42 . V_10 || V_2 -> V_42 . V_10 -> V_196 . V_197 & V_198 ) {
V_2 -> V_83 &= ~ ( V_84 | V_199 ) ;
F_38 ( V_2 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
F_83 ( V_2 ) ;
if ( V_2 -> V_42 . V_10 )
F_82 ( V_189 , & V_2 -> V_42 . V_10 -> V_12 ) ;
F_86 ( & V_2 -> V_42 , 0 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_90 ( V_2 ) ;
F_10 ( V_2 ) ;
V_2 -> V_78 = V_2 -> V_79 = V_2 -> V_80 = 0 ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_200 ||
V_2 -> V_86 )
F_92 ( V_2 ) ;
else
F_93 ( V_2 ) ;
F_38 ( V_2 ) ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_45 = 0 ;
V_2 -> V_46 = 0 ;
F_94 ( V_2 , V_114 + V_103 + V_108 + V_97 ) ;
F_95 ( V_2 , V_91 ) ;
F_37 ( V_2 ) ;
if ( V_2 -> V_86 || V_2 -> V_42 . V_10 -> V_196 . V_197 & V_201 )
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static void F_84 ( struct V_1 * V_2 )
{
unsigned V_202 ;
int V_203 ;
if ( ! V_2 -> V_42 . V_10 )
return;
if ( V_19 >= V_20 )
F_4 ( L_38 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
V_202 = V_2 -> V_42 . V_10 -> V_196 . V_197 ;
if ( V_202 & V_204 )
V_2 -> V_83 |= V_84 | V_199 ;
else
V_2 -> V_83 &= ~ ( V_84 | V_199 ) ;
switch ( V_202 & V_205 ) {
case V_206 : V_2 -> V_36 . V_207 = 5 ; break;
case V_208 : V_2 -> V_36 . V_207 = 6 ; break;
case V_209 : V_2 -> V_36 . V_207 = 7 ; break;
case V_210 : V_2 -> V_36 . V_207 = 8 ; break;
default: V_2 -> V_36 . V_207 = 7 ; break;
}
if ( V_202 & V_211 )
V_2 -> V_36 . V_212 = 2 ;
else
V_2 -> V_36 . V_212 = 1 ;
V_2 -> V_36 . V_144 = V_213 ;
if ( V_202 & V_214 ) {
if ( V_202 & V_215 )
V_2 -> V_36 . V_144 = V_216 ;
else
V_2 -> V_36 . V_144 = V_217 ;
#ifdef F_96
if ( V_202 & F_96 )
V_2 -> V_36 . V_144 = V_218 ;
#endif
}
V_203 = V_2 -> V_36 . V_207 +
V_2 -> V_36 . V_212 + 1 ;
if ( V_2 -> V_36 . V_219 <= 460800 )
V_2 -> V_36 . V_219 = F_97 ( V_2 -> V_42 . V_10 ) ;
if ( V_2 -> V_36 . V_219 ) {
V_2 -> V_220 = ( 32 * V_221 * V_203 ) /
V_2 -> V_36 . V_219 ;
}
V_2 -> V_220 += V_221 / 50 ;
F_98 ( & V_2 -> V_42 , V_202 & V_222 ) ;
F_99 ( & V_2 -> V_42 , ~ V_202 & V_223 ) ;
V_2 -> V_149 = V_65 ;
if ( F_100 ( V_2 -> V_42 . V_10 ) )
V_2 -> V_149 |= V_139 | V_138 ;
if ( F_101 ( V_2 -> V_42 . V_10 ) || F_102 ( V_2 -> V_42 . V_10 ) )
V_2 -> V_149 |= V_140 ;
if ( F_103 ( V_2 -> V_42 . V_10 ) )
V_2 -> V_148 |= V_139 | V_138 ;
if ( F_104 ( V_2 -> V_42 . V_10 ) ) {
V_2 -> V_148 |= V_140 ;
if ( F_103 ( V_2 -> V_42 . V_10 ) )
V_2 -> V_148 |= V_65 ;
}
F_91 ( V_2 ) ;
}
static int F_105 ( struct V_9 * V_10 , unsigned char V_224 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
int V_225 = 0 ;
if ( V_19 >= V_20 ) {
F_4 ( V_174 L_39 ,
__FILE__ , __LINE__ , V_224 , V_2 -> V_21 ) ;
}
if ( F_2 ( V_2 , V_10 -> V_3 , L_40 ) )
return 0 ;
if ( ! V_2 -> V_184 )
return 0 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ( V_2 -> V_36 . V_37 == V_226 ) || ! V_2 -> V_43 ) {
if ( V_2 -> V_78 < V_227 - 1 ) {
V_2 -> V_184 [ V_2 -> V_79 ++ ] = V_224 ;
V_2 -> V_79 &= V_227 - 1 ;
V_2 -> V_78 ++ ;
V_225 = 1 ;
}
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_225 ;
}
static void F_106 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_41 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_78 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_42 ) )
return;
if ( V_2 -> V_78 <= 0 || V_10 -> V_87 || V_10 -> V_88 ||
! V_2 -> V_184 )
return;
if ( V_19 >= V_20 )
F_4 ( L_43 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! V_2 -> V_43 ) {
if ( ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_200 ) && V_2 -> V_78 ) {
F_107 ( V_2 ,
V_2 -> V_184 , V_2 -> V_78 ) ;
}
F_13 ( V_2 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static int F_108 ( struct V_9 * V_10 ,
const unsigned char * V_228 , int V_13 )
{
int V_229 , V_225 = 0 ;
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_44 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_13 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_45 ) )
goto V_230;
if ( ! V_2 -> V_184 )
goto V_230;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_200 ) {
if ( V_2 -> V_43 ) {
if ( V_2 -> V_36 . V_37 == V_38 ) {
V_225 = 0 ;
goto V_230;
}
if ( V_2 -> V_231 >= V_2 -> V_232 ) {
V_225 = 0 ;
goto V_230;
}
V_225 = V_13 ;
F_109 ( V_2 , V_228 , V_13 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_67 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
goto V_230;
}
if ( ( V_2 -> V_36 . V_12 & V_233 ) &&
! F_26 ( V_2 ) )
{
V_225 = 0 ;
goto V_230;
}
if ( V_2 -> V_78 ) {
V_225 = 0 ;
F_107 ( V_2 ,
V_2 -> V_184 , V_2 -> V_78 ) ;
if ( V_19 >= V_20 )
F_4 ( L_46 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
} else {
if ( V_19 >= V_20 )
F_4 ( L_47 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
V_225 = V_13 ;
V_2 -> V_78 = V_13 ;
F_107 ( V_2 , V_228 , V_13 ) ;
}
} else {
while ( 1 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_229 = F_110 ( int , V_13 ,
F_111 ( V_227 - V_2 -> V_78 - 1 ,
V_227 - V_2 -> V_79 ) ) ;
if ( V_229 <= 0 ) {
F_11 ( & V_2 -> V_22 , V_12 ) ;
break;
}
memcpy ( V_2 -> V_184 + V_2 -> V_79 , V_228 , V_229 ) ;
V_2 -> V_79 = ( ( V_2 -> V_79 + V_229 ) &
( V_227 - 1 ) ) ;
V_2 -> V_78 += V_229 ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_228 += V_229 ;
V_13 -= V_229 ;
V_225 += V_229 ;
}
}
if ( V_2 -> V_78 && ! V_10 -> V_87 && ! V_10 -> V_88 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! V_2 -> V_43 )
F_13 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
V_230:
if ( V_19 >= V_20 )
F_4 ( L_48 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_225 ) ;
return V_225 ;
}
static int F_112 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
int V_225 ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_49 ) )
return 0 ;
V_225 = V_227 - V_2 -> V_78 - 1 ;
if ( V_225 < 0 )
V_225 = 0 ;
if ( V_19 >= V_20 )
F_4 ( L_50 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_225 ) ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_200 ) {
if ( V_2 -> V_43 )
return 0 ;
else
return V_234 ;
}
return V_225 ;
}
static int F_113 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
if ( V_19 >= V_20 )
F_4 ( L_51 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_52 ) )
return 0 ;
if ( V_19 >= V_20 )
F_4 ( L_53 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_78 ) ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_200 ) {
if ( V_2 -> V_43 )
return V_2 -> V_235 ;
else
return 0 ;
}
return V_2 -> V_78 ;
}
static void F_114 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_54 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_55 ) )
return;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_78 = V_2 -> V_79 = V_2 -> V_80 = 0 ;
F_36 ( & V_2 -> V_81 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
F_22 ( V_10 ) ;
}
static void F_115 ( struct V_9 * V_10 , char V_224 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_56 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_224 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_57 ) )
return;
V_2 -> V_236 = V_224 ;
if ( V_224 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! V_2 -> V_23 )
F_13 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
static void F_116 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_58 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_59 ) )
return;
if ( F_117 ( V_10 ) )
F_115 ( V_10 , F_118 ( V_10 ) ) ;
if ( F_119 ( V_10 ) ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_83 &= ~ V_84 ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
static void F_120 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_60 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_61 ) )
return;
if ( F_117 ( V_10 ) ) {
if ( V_2 -> V_236 )
V_2 -> V_236 = 0 ;
else
F_115 ( V_10 , F_121 ( V_10 ) ) ;
}
if ( F_119 ( V_10 ) ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_83 |= V_84 ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
static int F_122 ( struct V_1 * V_2 , struct V_89 T_4 * V_237 )
{
int V_238 ;
if ( V_19 >= V_20 )
F_4 ( L_62 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( ! V_237 ) {
memset ( & V_2 -> V_54 , 0 , sizeof( V_2 -> V_54 ) ) ;
} else {
F_123 ( & V_2 -> V_42 . V_239 ) ;
F_124 ( V_238 , V_237 , & V_2 -> V_54 , sizeof( struct V_89 ) ) ;
F_125 ( & V_2 -> V_42 . V_239 ) ;
if ( V_238 )
return - V_240 ;
}
return 0 ;
}
static int F_126 ( struct V_1 * V_2 , T_5 T_4 * V_241 )
{
int V_238 ;
if ( V_19 >= V_20 )
F_4 ( L_62 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_123 ( & V_2 -> V_42 . V_239 ) ;
F_124 ( V_238 , V_241 , & V_2 -> V_36 , sizeof( T_5 ) ) ;
F_125 ( & V_2 -> V_42 . V_239 ) ;
if ( V_238 ) {
if ( V_19 >= V_20 )
F_4 ( L_63 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return - V_240 ;
}
return 0 ;
}
static int F_127 ( struct V_1 * V_2 , T_5 T_4 * V_242 )
{
unsigned long V_12 ;
T_5 V_243 ;
int V_238 ;
if ( V_19 >= V_20 )
F_4 ( L_64 , __FILE__ , __LINE__ ,
V_2 -> V_21 ) ;
F_128 ( V_238 , & V_243 , V_242 , sizeof( T_5 ) ) ;
if ( V_238 ) {
if ( V_19 >= V_20 )
F_4 ( L_65 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return - V_240 ;
}
F_123 ( & V_2 -> V_42 . V_239 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
memcpy ( & V_2 -> V_36 , & V_243 , sizeof( T_5 ) ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
F_84 ( V_2 ) ;
F_125 ( & V_2 -> V_42 . V_239 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 , int T_4 * V_244 )
{
int V_238 ;
if ( V_19 >= V_20 )
F_4 ( L_66 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_244 ) ;
F_124 ( V_238 , V_244 , & V_2 -> V_244 , sizeof( int ) ) ;
if ( V_238 ) {
if ( V_19 >= V_20 )
F_4 ( L_67 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return - V_240 ;
}
return 0 ;
}
static int F_130 ( struct V_1 * V_2 , int V_244 )
{
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_68 , __FILE__ , __LINE__ ,
V_2 -> V_21 , V_244 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_244 = V_244 ;
F_131 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 , int V_245 )
{
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_69 , __FILE__ , __LINE__ ,
V_2 -> V_21 , V_245 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_245 ) {
if ( ! V_2 -> V_23 ) {
F_13 ( V_2 ) ;
if ( V_2 -> V_36 . V_12 & V_233 )
F_133 ( V_2 ) ;
}
} else {
if ( V_2 -> V_23 )
F_10 ( V_2 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_134 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_70 , __FILE__ , __LINE__ ,
V_2 -> V_21 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_2 -> V_43 && V_2 -> V_36 . V_37 == V_38 )
{
if ( V_2 -> V_36 . V_12 & V_233 )
F_135 ( V_2 ) ;
else
F_136 ( V_2 , V_246 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_137 ( struct V_1 * V_2 , int V_245 )
{
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_71 , __FILE__ , __LINE__ ,
V_2 -> V_21 , V_245 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_245 ) {
if ( ! V_2 -> V_247 )
F_21 ( V_2 ) ;
} else {
if ( V_2 -> V_247 )
F_90 ( V_2 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_138 ( struct V_1 * V_2 , int T_4 * V_248 )
{
unsigned long V_12 ;
int V_249 ;
int V_24 = 0 ;
struct V_89 V_250 , V_251 ;
int V_252 ;
int V_253 ;
struct V_254 V_255 , V_256 ;
F_139 ( V_257 , V_258 ) ;
F_128 ( V_24 , & V_253 , V_248 , sizeof( int ) ) ;
if ( V_24 ) {
return - V_240 ;
}
if ( V_19 >= V_20 )
F_4 ( L_72 , __FILE__ , __LINE__ ,
V_2 -> V_21 , V_253 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
V_249 = V_2 -> V_83 ;
V_252 = V_253 &
( ( ( V_249 & V_259 ) ? V_260 : V_261 ) +
( ( V_249 & V_262 ) ? V_263 : V_264 ) +
( ( V_249 & V_265 ) ? V_266 : V_267 ) +
( ( V_249 & V_268 ) ? V_269 : V_270 ) ) ;
if ( V_252 ) {
F_11 ( & V_2 -> V_22 , V_12 ) ;
goto exit;
}
V_250 = V_2 -> V_54 ;
V_255 = V_2 -> V_100 ;
if ( V_253 & ( V_271 + V_272 ) ) {
T_2 V_273 = F_25 ( V_2 , V_59 ) ;
T_2 V_274 = V_273 +
( V_253 & V_271 ? V_60 : 0 ) +
( V_253 & V_272 ? V_61 : 0 ) ;
if ( V_273 != V_274 )
F_27 ( V_2 , V_59 , V_274 ) ;
}
F_140 ( V_275 ) ;
F_141 ( & V_2 -> V_64 , & V_257 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
for(; ; ) {
F_142 () ;
if ( F_143 ( V_258 ) ) {
V_24 = - V_276 ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_251 = V_2 -> V_54 ;
V_256 = V_2 -> V_100 ;
F_140 ( V_275 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( V_256 . V_106 == V_255 . V_106 &&
V_256 . V_107 == V_255 . V_107 &&
V_256 . V_111 == V_255 . V_111 &&
V_256 . V_112 == V_255 . V_112 &&
V_256 . V_117 == V_255 . V_117 &&
V_256 . V_118 == V_255 . V_118 &&
V_256 . V_101 == V_255 . V_101 &&
V_256 . V_102 == V_255 . V_102 &&
V_251 . V_62 == V_250 . V_62 &&
V_251 . V_63 == V_250 . V_63 ) {
V_24 = - V_277 ;
break;
}
V_252 = V_253 &
( ( V_256 . V_106 != V_255 . V_106 ? V_260 : 0 ) +
( V_256 . V_107 != V_255 . V_107 ? V_261 : 0 ) +
( V_256 . V_111 != V_255 . V_111 ? V_263 : 0 ) +
( V_256 . V_112 != V_255 . V_112 ? V_264 : 0 ) +
( V_256 . V_117 != V_255 . V_117 ? V_266 : 0 ) +
( V_256 . V_118 != V_255 . V_118 ? V_267 : 0 ) +
( V_256 . V_101 != V_255 . V_101 ? V_269 : 0 ) +
( V_256 . V_102 != V_255 . V_102 ? V_270 : 0 ) +
( V_251 . V_62 != V_250 . V_62 ? V_271 : 0 ) +
( V_251 . V_63 != V_250 . V_63 ? V_272 : 0 ) ) ;
if ( V_252 )
break;
V_250 = V_251 ;
V_255 = V_256 ;
}
F_144 ( & V_2 -> V_64 , & V_257 ) ;
F_140 ( V_278 ) ;
if ( V_253 & ( V_271 + V_272 ) ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! F_145 ( & V_2 -> V_64 ) ) {
F_27 ( V_2 , V_59 , F_25 ( V_2 , V_59 ) &
~ ( V_60 | V_61 ) ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
exit:
if ( V_24 == 0 )
F_146 ( V_24 , V_252 , V_248 ) ;
return V_24 ;
}
static int F_147 ( struct V_1 * V_2 , int V_279 )
{
unsigned long V_12 ;
int V_24 ;
struct V_89 V_250 , V_251 ;
F_139 ( V_257 , V_258 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_250 = V_2 -> V_54 ;
F_141 ( & V_2 -> V_119 , & V_257 ) ;
F_140 ( V_275 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
for(; ; ) {
F_142 () ;
if ( F_143 ( V_258 ) ) {
V_24 = - V_276 ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_251 = V_2 -> V_54 ;
F_140 ( V_275 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( V_251 . V_98 == V_250 . V_98 && V_251 . V_104 == V_250 . V_104 &&
V_251 . V_109 == V_250 . V_109 && V_251 . V_115 == V_250 . V_115 ) {
V_24 = - V_277 ;
break;
}
if ( ( V_279 & V_280 && V_251 . V_98 != V_250 . V_98 ) ||
( V_279 & V_281 && V_251 . V_104 != V_250 . V_104 ) ||
( V_279 & V_282 && V_251 . V_109 != V_250 . V_109 ) ||
( V_279 & V_283 && V_251 . V_115 != V_250 . V_115 ) ) {
V_24 = 0 ;
break;
}
V_250 = V_251 ;
}
F_144 ( & V_2 -> V_119 , & V_257 ) ;
F_140 ( V_278 ) ;
return V_24 ;
}
static int F_148 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned int V_284 ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_284 = ( ( V_2 -> V_83 & V_84 ) ? V_285 : 0 ) +
( ( V_2 -> V_83 & V_199 ) ? V_286 : 0 ) +
( ( V_2 -> V_83 & V_262 ) ? V_287 : 0 ) +
( ( V_2 -> V_83 & V_268 ) ? V_280 : 0 ) +
( ( V_2 -> V_83 & V_259 ) ? V_281 : 0 ) +
( ( V_2 -> V_83 & V_265 ) ? V_283 : 0 ) ;
if ( V_19 >= V_20 )
F_4 ( L_73 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_284 ) ;
return V_284 ;
}
static int F_149 ( struct V_9 * V_10 ,
unsigned int V_288 , unsigned int V_289 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_74 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_288 , V_289 ) ;
if ( V_288 & V_285 )
V_2 -> V_83 |= V_84 ;
if ( V_288 & V_286 )
V_2 -> V_83 |= V_199 ;
if ( V_289 & V_285 )
V_2 -> V_83 &= ~ V_84 ;
if ( V_289 & V_286 )
V_2 -> V_83 &= ~ V_199 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_150 ( struct V_9 * V_10 , int V_290 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_75 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_290 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_76 ) )
return - V_291 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_290 == - 1 )
F_27 ( V_2 , V_292 , ( T_2 ) ( F_25 ( V_2 , V_292 ) | V_293 ) ) ;
else
F_27 ( V_2 , V_292 , ( T_2 ) ( F_25 ( V_2 , V_292 ) & ~ V_293 ) ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_151 ( struct V_9 * V_10 ,
struct V_294 * V_54 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
struct V_89 V_251 ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_251 = V_2 -> V_54 ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_54 -> V_115 = V_251 . V_115 ;
V_54 -> V_104 = V_251 . V_104 ;
V_54 -> V_98 = V_251 . V_98 ;
V_54 -> V_109 = V_251 . V_109 ;
V_54 -> V_142 = V_251 . V_142 ;
V_54 -> V_295 = V_251 . V_295 ;
V_54 -> V_145 = V_251 . V_145 ;
V_54 -> V_147 = V_251 . V_147 ;
V_54 -> V_144 = V_251 . V_144 ;
V_54 -> V_143 = V_251 . V_143 ;
V_54 -> V_164 = V_251 . V_164 ;
return 0 ;
}
static int F_152 ( struct V_9 * V_10 ,
unsigned int V_296 , unsigned long V_279 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
if ( V_19 >= V_20 )
F_4 ( L_77 , __FILE__ , __LINE__ ,
V_2 -> V_21 , V_296 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_78 ) )
return - V_297 ;
if ( ( V_296 != V_298 ) && ( V_296 != V_299 ) &&
( V_296 != V_300 ) ) {
if ( F_153 ( V_10 ) )
return - V_277 ;
}
return F_154 ( V_2 , V_296 , V_279 ) ;
}
static int F_154 ( struct V_1 * V_2 , unsigned int V_296 , unsigned long V_279 )
{
void T_4 * V_301 = ( void T_4 * ) V_279 ;
switch ( V_296 ) {
case V_302 :
return F_126 ( V_2 , V_301 ) ;
case V_303 :
return F_127 ( V_2 , V_301 ) ;
case V_304 :
return F_129 ( V_2 , V_301 ) ;
case V_305 :
return F_130 ( V_2 , ( int ) V_279 ) ;
case V_306 :
return F_132 ( V_2 , ( int ) V_279 ) ;
case V_307 :
return F_137 ( V_2 , ( int ) V_279 ) ;
case V_308 :
return F_134 ( V_2 ) ;
case V_309 :
return F_122 ( V_2 , V_301 ) ;
case V_310 :
return F_138 ( V_2 , V_301 ) ;
case V_311 :
return F_155 ( V_2 ) ;
case V_300 :
return F_147 ( V_2 , ( int ) V_279 ) ;
default:
return - V_312 ;
}
return 0 ;
}
static void F_156 ( struct V_9 * V_10 , struct V_313 * V_314 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_79 , __FILE__ , __LINE__ ,
V_10 -> V_315 -> V_3 ) ;
F_84 ( V_2 ) ;
if ( ( V_314 -> V_197 & V_204 ) && ! F_157 ( V_10 ) ) {
V_2 -> V_83 &= ~ ( V_84 | V_199 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
if ( ! ( V_314 -> V_197 & V_204 ) && F_157 ( V_10 ) ) {
V_2 -> V_83 |= V_199 ;
if ( ! F_119 ( V_10 ) || ! F_158 ( V_10 ) )
V_2 -> V_83 |= V_84 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
if ( V_314 -> V_197 & V_222 && ! F_119 ( V_10 ) ) {
V_10 -> V_88 = 0 ;
F_12 ( V_10 ) ;
}
}
static void F_159 ( struct V_9 * V_10 , struct V_316 * V_317 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_80 ) )
return;
if ( V_19 >= V_20 )
F_4 ( L_81 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_42 . V_13 ) ;
if ( F_160 ( & V_2 -> V_42 , V_10 , V_317 ) == 0 )
goto V_230;
F_123 ( & V_2 -> V_42 . V_239 ) ;
if ( F_76 ( & V_2 -> V_42 ) )
F_161 ( V_10 , V_2 -> V_220 ) ;
F_114 ( V_10 ) ;
F_162 ( V_10 ) ;
F_87 ( V_2 ) ;
F_125 ( & V_2 -> V_42 . V_239 ) ;
F_163 ( & V_2 -> V_42 , V_10 ) ;
V_2 -> V_42 . V_10 = NULL ;
V_230:
if ( V_19 >= V_20 )
F_4 ( L_82 , __FILE__ , __LINE__ ,
V_10 -> V_315 -> V_3 , V_2 -> V_42 . V_13 ) ;
}
static void F_161 ( struct V_9 * V_10 , int V_220 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_318 , V_319 ;
if ( ! V_2 )
return;
if ( V_19 >= V_20 )
F_4 ( L_83 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_84 ) )
return;
if ( ! F_76 ( & V_2 -> V_42 ) )
goto exit;
V_318 = V_320 ;
if ( V_2 -> V_36 . V_219 ) {
V_319 = V_2 -> V_220 / ( 32 * 5 ) ;
if ( ! V_319 )
V_319 ++ ;
} else
V_319 = 1 ;
if ( V_220 )
V_319 = F_110 (unsigned long, char_time, timeout) ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_200 ) {
while ( V_2 -> V_43 ) {
F_164 ( F_165 ( V_319 ) ) ;
if ( F_143 ( V_258 ) )
break;
if ( V_220 && F_166 ( V_320 , V_318 + V_220 ) )
break;
}
} else {
while ( ! ( F_25 ( V_2 , V_68 ) & V_321 ) &&
V_2 -> V_23 ) {
F_164 ( F_165 ( V_319 ) ) ;
if ( F_143 ( V_258 ) )
break;
if ( V_220 && F_166 ( V_320 , V_318 + V_220 ) )
break;
}
}
exit:
if ( V_19 >= V_20 )
F_4 ( L_85 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
}
static void F_167 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
if ( V_19 >= V_20 )
F_4 ( L_86 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_87 ) )
return;
F_114 ( V_10 ) ;
F_87 ( V_2 ) ;
V_2 -> V_42 . V_13 = 0 ;
F_168 ( & V_2 -> V_42 , 0 ) ;
V_2 -> V_42 . V_10 = NULL ;
F_28 ( & V_2 -> V_42 . V_120 ) ;
}
static int F_169 ( struct V_322 * V_42 )
{
unsigned long V_12 ;
struct V_1 * V_2 = F_16 ( V_42 , struct V_1 , V_42 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return ( V_2 -> V_83 & V_262 ) ? 1 : 0 ;
}
static void F_170 ( struct V_322 * V_42 , int V_323 )
{
struct V_1 * V_2 = F_16 ( V_42 , struct V_1 , V_42 ) ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_323 )
V_2 -> V_83 |= V_84 | V_199 ;
else
V_2 -> V_83 &= ~ ( V_84 | V_199 ) ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static int F_171 ( struct V_9 * V_10 , struct V_316 * V_317 ,
struct V_1 * V_2 )
{
F_139 ( V_257 , V_258 ) ;
int V_183 ;
bool V_324 = false ;
unsigned long V_12 ;
int V_109 ;
struct V_322 * V_42 = & V_2 -> V_42 ;
if ( V_19 >= V_20 )
F_4 ( L_88 ,
__FILE__ , __LINE__ , V_10 -> V_315 -> V_3 ) ;
if ( V_317 -> V_325 & V_326 || F_153 ( V_10 ) ) {
F_168 ( V_42 , 1 ) ;
return 0 ;
}
if ( F_172 ( V_10 ) )
V_324 = true ;
V_183 = 0 ;
F_141 ( & V_42 -> V_120 , & V_257 ) ;
if ( V_19 >= V_20 )
F_4 ( L_89 ,
__FILE__ , __LINE__ , V_10 -> V_315 -> V_3 , V_42 -> V_13 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_42 -> V_13 -- ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_42 -> V_327 ++ ;
while ( 1 ) {
if ( F_157 ( V_10 ) && F_76 ( V_42 ) )
F_173 ( V_42 ) ;
F_140 ( V_275 ) ;
if ( F_174 ( V_317 ) || ! F_76 ( V_42 ) ) {
V_183 = ( V_42 -> V_12 & V_328 ) ?
- V_329 : - V_276 ;
break;
}
V_109 = F_175 ( & V_2 -> V_42 ) ;
if ( V_324 || V_109 )
break;
if ( F_143 ( V_258 ) ) {
V_183 = - V_276 ;
break;
}
if ( V_19 >= V_20 )
F_4 ( L_90 ,
__FILE__ , __LINE__ , V_10 -> V_315 -> V_3 , V_42 -> V_13 ) ;
F_176 ( V_10 ) ;
F_142 () ;
F_177 ( V_10 ) ;
}
F_140 ( V_278 ) ;
F_144 ( & V_42 -> V_120 , & V_257 ) ;
if ( ! F_174 ( V_317 ) )
V_42 -> V_13 ++ ;
V_42 -> V_327 -- ;
if ( V_19 >= V_20 )
F_4 ( L_91 ,
__FILE__ , __LINE__ , V_10 -> V_315 -> V_3 , V_42 -> V_13 ) ;
if ( ! V_183 )
F_168 ( V_42 , 1 ) ;
return V_183 ;
}
static int F_178 ( struct V_330 * V_315 , struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int line = V_10 -> V_331 ;
if ( line >= V_332 ) {
F_4 ( L_92 ,
__FILE__ , __LINE__ , line ) ;
return - V_297 ;
}
V_2 = V_333 ;
while ( V_2 && V_2 -> line != line )
V_2 = V_2 -> V_334 ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_93 ) )
return - V_297 ;
V_10 -> V_18 = V_2 ;
return F_179 ( & V_2 -> V_42 , V_315 , V_10 ) ;
}
static int F_180 ( struct V_9 * V_10 , struct V_316 * V_317 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
int V_183 ;
V_2 -> V_42 . V_10 = V_10 ;
if ( V_19 >= V_20 )
F_4 ( L_94 ,
__FILE__ , __LINE__ , V_10 -> V_315 -> V_3 , V_2 -> V_42 . V_13 ) ;
V_2 -> V_42 . V_335 = ( V_2 -> V_42 . V_12 & V_336 ) ? 1 : 0 ;
F_9 ( & V_2 -> V_337 , V_12 ) ;
if ( V_2 -> V_86 ) {
V_183 = - V_338 ;
F_11 ( & V_2 -> V_337 , V_12 ) ;
goto V_230;
}
V_2 -> V_42 . V_13 ++ ;
F_11 ( & V_2 -> V_337 , V_12 ) ;
if ( V_2 -> V_42 . V_13 == 1 ) {
V_183 = F_75 ( V_2 ) ;
if ( V_183 < 0 )
goto V_230;
}
V_183 = F_171 ( V_10 , V_317 , V_2 ) ;
if ( V_183 ) {
if ( V_19 >= V_20 )
F_4 ( L_95 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_183 ) ;
goto V_230;
}
if ( V_19 >= V_20 )
F_4 ( L_96 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
V_183 = 0 ;
V_230:
if ( V_183 ) {
if ( V_10 -> V_13 == 1 )
V_2 -> V_42 . V_10 = NULL ;
if( V_2 -> V_42 . V_13 )
V_2 -> V_42 . V_13 -- ;
}
return V_183 ;
}
static inline void F_181 ( struct V_339 * V_340 , struct V_1 * V_2 )
{
char V_341 [ 30 ] ;
unsigned long V_12 ;
if ( V_2 -> V_342 == V_343 ) {
F_182 ( V_340 , L_97 ,
V_2 -> V_21 , V_2 -> V_135 , V_2 -> V_175 ,
V_2 -> V_344 , V_2 -> V_345 ) ;
} else {
F_182 ( V_340 , L_98 ,
V_2 -> V_21 , V_2 -> V_135 ,
V_2 -> V_175 , V_2 -> V_346 ) ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_341 [ 0 ] = 0 ;
V_341 [ 1 ] = 0 ;
if ( V_2 -> V_83 & V_84 )
strcat ( V_341 , L_99 ) ;
if ( V_2 -> V_83 & V_265 )
strcat ( V_341 , L_100 ) ;
if ( V_2 -> V_83 & V_199 )
strcat ( V_341 , L_101 ) ;
if ( V_2 -> V_83 & V_259 )
strcat ( V_341 , L_102 ) ;
if ( V_2 -> V_83 & V_262 )
strcat ( V_341 , L_103 ) ;
if ( V_2 -> V_83 & V_268 )
strcat ( V_341 , L_104 ) ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_200 ) {
F_182 ( V_340 , L_105 ,
V_2 -> V_54 . V_75 , V_2 -> V_54 . V_347 ) ;
if ( V_2 -> V_54 . V_76 )
F_182 ( V_340 , L_106 , V_2 -> V_54 . V_76 ) ;
if ( V_2 -> V_54 . V_77 )
F_182 ( V_340 , L_107 , V_2 -> V_54 . V_77 ) ;
if ( V_2 -> V_54 . V_348 )
F_182 ( V_340 , L_108 , V_2 -> V_54 . V_348 ) ;
if ( V_2 -> V_54 . V_349 )
F_182 ( V_340 , L_109 , V_2 -> V_54 . V_349 ) ;
if ( V_2 -> V_54 . V_66 )
F_182 ( V_340 , L_110 , V_2 -> V_54 . V_66 ) ;
if ( V_2 -> V_54 . V_350 )
F_182 ( V_340 , L_111 , V_2 -> V_54 . V_350 ) ;
} else {
F_182 ( V_340 , L_112 ,
V_2 -> V_54 . V_295 , V_2 -> V_54 . V_142 ) ;
if ( V_2 -> V_54 . V_145 )
F_182 ( V_340 , L_113 , V_2 -> V_54 . V_145 ) ;
if ( V_2 -> V_54 . V_144 )
F_182 ( V_340 , L_114 , V_2 -> V_54 . V_144 ) ;
if ( V_2 -> V_54 . V_143 )
F_182 ( V_340 , L_115 , V_2 -> V_54 . V_143 ) ;
if ( V_2 -> V_54 . V_147 )
F_182 ( V_340 , L_116 , V_2 -> V_54 . V_147 ) ;
}
F_182 ( V_340 , L_117 , V_341 + 1 ) ;
F_182 ( V_340 , L_118 ,
V_2 -> V_43 , V_2 -> V_30 , V_2 -> V_29 ,
V_2 -> V_25 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
{
T_2 V_351 = F_25 ( V_2 , V_68 ) ;
T_2 V_352 = F_65 ( V_2 , V_167 ) ;
T_2 V_353 = F_25 ( V_2 , V_354 ) ;
T_2 V_355 = F_25 ( V_2 , V_50 ) ;
T_2 V_356 = F_65 ( V_2 , V_162 ) ;
T_2 V_357 = F_25 ( V_2 , V_59 ) ;
T_2 V_358 = F_25 ( V_2 , V_359 ) ;
T_2 V_360 = F_25 ( V_2 , V_361 ) ;
T_2 V_362 = F_25 ( V_2 , V_363 ) ;
T_2 V_364 = F_25 ( V_2 , V_365 ) ;
T_2 V_366 = F_53 ( V_2 -> V_135 + V_136 ) ;
F_182 ( V_340 , L_119
L_120 ,
V_351 , V_352 , V_353 , V_355 , V_356 , V_357 , V_358 , V_360 , V_362 , V_364 , V_366 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static int F_183 ( struct V_339 * V_340 , void * V_367 )
{
struct V_1 * V_2 ;
F_182 ( V_340 , L_121 , V_368 ) ;
V_2 = V_333 ;
while( V_2 ) {
F_181 ( V_340 , V_2 ) ;
V_2 = V_2 -> V_334 ;
}
return 0 ;
}
static int F_184 ( struct V_369 * V_369 , struct V_316 * V_316 )
{
return F_185 ( V_316 , F_183 , NULL ) ;
}
static int F_186 ( struct V_1 * V_2 )
{
unsigned short V_370 ;
V_2 -> V_371 = 0 ;
V_370 = ( unsigned short ) ( V_2 -> V_235 / V_372 ) ;
if ( V_2 -> V_235 % V_372 )
V_370 ++ ;
if ( V_2 -> V_342 == V_343 ) {
V_2 -> V_373 = V_2 -> V_374 * V_370 ;
V_2 -> V_375 = 62 - V_2 -> V_373 ;
} else {
V_2 -> V_373 = V_2 -> V_374 * V_370 ;
V_2 -> V_375 = ( V_370 * V_376 ) + 6 ;
if ( ( V_2 -> V_373 + V_2 -> V_375 ) > 62 )
V_2 -> V_375 = 62 - V_2 -> V_373 ;
}
if ( V_19 >= V_20 )
F_4 ( L_122 ,
__FILE__ , __LINE__ , V_2 -> V_373 , V_2 -> V_375 ) ;
if ( F_187 ( V_2 ) < 0 ||
F_188 ( V_2 , V_2 -> V_377 , V_2 -> V_375 ) < 0 ||
F_188 ( V_2 , V_2 -> V_378 , V_2 -> V_373 ) < 0 ||
F_189 ( V_2 ) < 0 ||
F_190 ( V_2 ) < 0 ) {
F_4 ( L_123 , __FILE__ , __LINE__ ) ;
return - V_186 ;
}
F_191 ( V_2 ) ;
F_192 ( V_2 ) ;
return 0 ;
}
static int F_187 ( struct V_1 * V_2 )
{
unsigned int V_379 ;
if ( V_2 -> V_342 == V_343 ) {
V_2 -> V_380 = V_2 -> V_381 + V_2 -> V_371 ;
V_2 -> V_382 = V_2 -> V_371 ;
V_2 -> V_371 += V_383 ;
} else {
V_2 -> V_380 = F_193 ( NULL , V_383 , & V_2 -> V_384 , V_185 ) ;
if ( V_2 -> V_380 == NULL )
return - V_186 ;
V_2 -> V_382 = ( V_385 ) ( V_2 -> V_384 ) ;
}
memset ( V_2 -> V_380 , 0 , V_383 ) ;
V_2 -> V_377 = ( V_386 * ) V_2 -> V_380 ;
V_2 -> V_378 = ( V_386 * ) V_2 -> V_380 ;
V_2 -> V_378 += V_2 -> V_375 ;
for ( V_379 = 0 ; V_379 < V_2 -> V_375 ; V_379 ++ ) {
V_2 -> V_377 [ V_379 ] . V_387 =
V_2 -> V_382 + ( V_379 * sizeof( V_386 ) ) ;
V_2 -> V_377 [ V_379 ] . V_388 = V_2 -> V_382 ;
if ( V_379 < V_2 -> V_375 - 1 )
V_2 -> V_377 [ V_379 ] . V_388 += ( V_379 + 1 ) * sizeof( V_386 ) ;
}
for ( V_379 = 0 ; V_379 < V_2 -> V_373 ; V_379 ++ ) {
V_2 -> V_378 [ V_379 ] . V_387 = V_2 -> V_382 +
( ( V_2 -> V_375 + V_379 ) * sizeof( V_386 ) ) ;
V_2 -> V_378 [ V_379 ] . V_388 = V_2 -> V_382 +
V_2 -> V_375 * sizeof( V_386 ) ;
if ( V_379 < V_2 -> V_373 - 1 )
V_2 -> V_378 [ V_379 ] . V_388 += ( V_379 + 1 ) * sizeof( V_386 ) ;
}
return 0 ;
}
static void F_194 ( struct V_1 * V_2 )
{
if ( V_2 -> V_380 && V_2 -> V_342 != V_343 )
F_195 ( NULL , V_383 , V_2 -> V_380 , V_2 -> V_384 ) ;
V_2 -> V_380 = NULL ;
V_2 -> V_377 = NULL ;
V_2 -> V_378 = NULL ;
}
static int F_188 ( struct V_1 * V_2 , V_386 * V_389 , int V_390 )
{
int V_379 ;
V_385 V_391 ;
for ( V_379 = 0 ; V_379 < V_390 ; V_379 ++ ) {
if ( V_2 -> V_342 == V_343 ) {
V_389 [ V_379 ] . V_392 = V_2 -> V_381 + V_2 -> V_371 ;
V_391 = V_2 -> V_371 ;
V_2 -> V_371 += V_372 ;
} else {
V_389 [ V_379 ] . V_392 = F_193 ( NULL , V_372 , & V_389 [ V_379 ] . V_393 , V_185 ) ;
if ( V_389 [ V_379 ] . V_392 == NULL )
return - V_186 ;
V_391 = ( V_385 ) ( V_389 [ V_379 ] . V_393 ) ;
}
V_389 [ V_379 ] . V_391 = V_391 ;
}
return 0 ;
}
static void F_196 ( struct V_1 * V_2 , V_386 * V_389 , int V_390 )
{
int V_379 ;
if ( V_389 ) {
for ( V_379 = 0 ; V_379 < V_390 ; V_379 ++ ) {
if ( V_389 [ V_379 ] . V_392 ) {
if ( V_2 -> V_342 != V_343 )
F_195 ( NULL , V_372 , V_389 [ V_379 ] . V_392 , V_389 [ V_379 ] . V_393 ) ;
V_389 [ V_379 ] . V_392 = NULL ;
}
}
}
}
static void F_197 ( struct V_1 * V_2 )
{
F_196 ( V_2 , V_2 -> V_377 , V_2 -> V_375 ) ;
F_196 ( V_2 , V_2 -> V_378 , V_2 -> V_373 ) ;
F_194 ( V_2 ) ;
}
static int F_189 ( struct V_1 * V_2 )
{
V_2 -> V_394 = F_198 ( V_2 -> V_235 , V_185 | V_395 ) ;
if ( V_2 -> V_394 == NULL )
return - V_186 ;
V_2 -> V_396 = F_199 ( V_2 -> V_235 , V_185 ) ;
if ( ! V_2 -> V_396 ) {
F_200 ( V_2 -> V_394 ) ;
V_2 -> V_394 = NULL ;
return - V_186 ;
}
return 0 ;
}
static void F_201 ( struct V_1 * V_2 )
{
F_200 ( V_2 -> V_394 ) ;
V_2 -> V_394 = NULL ;
F_200 ( V_2 -> V_396 ) ;
V_2 -> V_396 = NULL ;
}
static int F_190 ( struct V_1 * V_2 )
{
int V_379 ;
if ( V_19 >= V_20 )
F_4 ( L_124 ,
V_2 -> V_21 , __FILE__ , __LINE__ , V_2 -> V_232 ) ;
memset ( V_2 -> V_397 , 0 , sizeof( V_2 -> V_397 ) ) ;
for ( V_379 = 0 ; V_379 < V_2 -> V_232 ; ++ V_379 ) {
V_2 -> V_397 [ V_379 ] . V_398 =
F_198 ( V_2 -> V_235 , V_185 ) ;
if ( V_2 -> V_397 [ V_379 ] . V_398 == NULL ) {
for ( -- V_379 ; V_379 >= 0 ; V_379 -- ) {
F_200 ( V_2 -> V_397 [ V_379 ] . V_398 ) ;
V_2 -> V_397 [ V_379 ] . V_398 = NULL ;
}
return - V_186 ;
}
}
return 0 ;
}
static void F_202 ( struct V_1 * V_2 )
{
int V_379 ;
for ( V_379 = 0 ; V_379 < V_2 -> V_232 ; ++ V_379 ) {
F_200 ( V_2 -> V_397 [ V_379 ] . V_398 ) ;
V_2 -> V_397 [ V_379 ] . V_398 = NULL ;
}
V_2 -> V_399 = 0 ;
V_2 -> V_400 = 0 ;
V_2 -> V_231 = 0 ;
}
static bool F_67 ( struct V_1 * V_2 )
{
bool V_225 = false ;
if ( V_2 -> V_231 ) {
struct V_401 * V_402 =
& V_2 -> V_397 [ V_2 -> V_399 ] ;
int V_403 = F_203 ( V_2 ) ;
int V_404 = V_402 -> V_405 / V_372 ;
if ( V_402 -> V_405 % V_372 )
++ V_404 ;
if ( V_404 <= V_403 ) {
V_2 -> V_78 = V_402 -> V_405 ;
F_107 ( V_2 , V_402 -> V_398 , V_402 -> V_405 ) ;
-- V_2 -> V_231 ;
if ( ++ V_2 -> V_399 >= V_2 -> V_232 )
V_2 -> V_399 = 0 ;
F_204 ( & V_2 -> V_81 , V_320 + F_205 ( 5000 ) ) ;
V_225 = true ;
}
}
return V_225 ;
}
static int F_109 ( struct V_1 * V_2 , const char * V_406 , unsigned int V_407 )
{
struct V_401 * V_402 ;
if ( V_2 -> V_231 >= V_2 -> V_232 ) {
return 0 ;
}
V_402 = & V_2 -> V_397 [ V_2 -> V_400 ] ;
V_402 -> V_405 = V_407 ;
memcpy ( V_402 -> V_398 , V_406 , V_407 ) ;
++ V_2 -> V_231 ;
if ( ++ V_2 -> V_400 >= V_2 -> V_232 )
V_2 -> V_400 = 0 ;
return 1 ;
}
static int F_79 ( struct V_1 * V_2 )
{
if ( F_206 ( V_2 -> V_135 , V_2 -> V_408 , L_125 ) == NULL ) {
F_4 ( L_126 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_135 ) ;
return - V_297 ;
}
V_2 -> V_409 = true ;
if ( F_207 ( V_2 -> V_175 , F_68 , V_2 -> V_410 ,
V_2 -> V_21 , V_2 ) < 0 ) {
F_4 ( L_127 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_175 ) ;
goto V_411;
}
V_2 -> V_412 = true ;
if ( V_2 -> V_342 == V_343 ) {
if ( F_208 ( V_2 -> V_344 , 0x40000 , L_125 ) == NULL ) {
F_4 ( L_128 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_344 ) ;
goto V_411;
}
V_2 -> V_413 = true ;
if ( F_208 ( V_2 -> V_345 + V_2 -> V_414 , 128 , L_125 ) == NULL ) {
F_4 ( L_129 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_345 + V_2 -> V_414 ) ;
goto V_411;
}
V_2 -> V_415 = true ;
V_2 -> V_381 = F_209 ( V_2 -> V_344 ,
0x40000 ) ;
if ( ! V_2 -> V_381 ) {
F_4 ( L_130 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_344 ) ;
goto V_411;
}
if ( ! F_210 ( V_2 ) ) {
F_4 ( L_131 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_344 ) ;
goto V_411;
}
V_2 -> V_416 = F_209 ( V_2 -> V_345 ,
V_417 ) ;
if ( ! V_2 -> V_416 ) {
F_4 ( L_132 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_345 ) ;
goto V_411;
}
V_2 -> V_416 += V_2 -> V_414 ;
} else {
if ( F_211 ( V_2 -> V_346 , V_2 -> V_21 ) < 0 ) {
F_4 ( L_133 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_346 ) ;
F_83 ( V_2 ) ;
return - V_297 ;
}
V_2 -> V_418 = true ;
F_212 ( V_2 -> V_346 , V_419 ) ;
F_213 ( V_2 -> V_346 ) ;
}
if ( F_186 ( V_2 ) < 0 ) {
F_4 ( L_134 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_346 ) ;
goto V_411;
}
return 0 ;
V_411:
F_83 ( V_2 ) ;
return - V_297 ;
}
static void F_83 ( struct V_1 * V_2 )
{
if ( V_19 >= V_20 )
F_4 ( L_135 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( V_2 -> V_412 ) {
F_214 ( V_2 -> V_175 , V_2 ) ;
V_2 -> V_412 = false ;
}
if ( V_2 -> V_418 ) {
F_215 ( V_2 -> V_346 ) ;
F_216 ( V_2 -> V_346 ) ;
V_2 -> V_418 = false ;
}
F_197 ( V_2 ) ;
F_201 ( V_2 ) ;
F_202 ( V_2 ) ;
if ( V_2 -> V_409 ) {
F_217 ( V_2 -> V_135 , V_2 -> V_408 ) ;
V_2 -> V_409 = false ;
}
if ( V_2 -> V_413 ) {
F_218 ( V_2 -> V_344 , 0x40000 ) ;
V_2 -> V_413 = false ;
}
if ( V_2 -> V_415 ) {
F_218 ( V_2 -> V_345 + V_2 -> V_414 , 128 ) ;
V_2 -> V_415 = false ;
}
if ( V_2 -> V_381 ) {
F_219 ( V_2 -> V_381 ) ;
V_2 -> V_381 = NULL ;
}
if ( V_2 -> V_416 ) {
F_219 ( V_2 -> V_416 - V_2 -> V_414 ) ;
V_2 -> V_416 = NULL ;
}
if ( V_19 >= V_20 )
F_4 ( L_136 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
}
static void F_220 ( struct V_1 * V_2 )
{
V_2 -> V_334 = NULL ;
V_2 -> line = V_332 ;
sprintf ( V_2 -> V_21 , L_137 , V_2 -> line ) ;
if ( V_2 -> line < V_420 ) {
if ( V_421 [ V_2 -> line ] )
V_2 -> V_235 = V_421 [ V_2 -> line ] ;
if ( V_422 [ V_2 -> line ] ) {
V_2 -> V_374 = V_422 [ V_2 -> line ] ;
if ( V_2 -> V_374 < 1 )
V_2 -> V_374 = 1 ;
}
if ( V_423 [ V_2 -> line ] ) {
V_2 -> V_232 = V_423 [ V_2 -> line ] ;
if ( V_2 -> V_232 < 1 )
V_2 -> V_232 = 1 ;
else if ( V_2 -> V_232 > V_424 )
V_2 -> V_232 = V_424 ;
}
}
V_332 ++ ;
if ( ! V_333 )
V_333 = V_2 ;
else {
struct V_1 * V_425 = V_333 ;
while( V_425 -> V_334 )
V_425 = V_425 -> V_334 ;
V_425 -> V_334 = V_2 ;
}
if ( V_2 -> V_235 < 4096 )
V_2 -> V_235 = 4096 ;
else if ( V_2 -> V_235 > 65535 )
V_2 -> V_235 = 65535 ;
if ( V_2 -> V_342 == V_343 ) {
F_4 ( L_138 ,
V_2 -> V_426 + 1 , V_2 -> V_21 , V_2 -> V_135 , V_2 -> V_175 ,
V_2 -> V_344 , V_2 -> V_345 ,
V_2 -> V_235 ) ;
} else {
F_4 ( L_139 ,
V_2 -> V_21 , V_2 -> V_135 , V_2 -> V_175 , V_2 -> V_346 ,
V_2 -> V_235 ) ;
}
#if V_85
F_221 ( V_2 ) ;
#endif
}
static struct V_1 * F_222 ( void )
{
struct V_1 * V_2 ;
V_2 = F_199 ( sizeof( struct V_1 ) ,
V_185 ) ;
if ( ! V_2 ) {
F_4 ( L_140 ) ;
} else {
F_223 ( & V_2 -> V_42 ) ;
V_2 -> V_42 . V_16 = & V_427 ;
V_2 -> V_7 = V_8 ;
F_224 ( & V_2 -> V_33 , F_15 ) ;
V_2 -> V_235 = 4096 ;
V_2 -> V_42 . V_428 = 5 * V_221 / 10 ;
V_2 -> V_42 . V_429 = 30 * V_221 ;
F_225 ( & V_2 -> V_119 ) ;
F_225 ( & V_2 -> V_64 ) ;
F_226 ( & V_2 -> V_22 ) ;
F_226 ( & V_2 -> V_337 ) ;
memcpy ( & V_2 -> V_36 , & V_430 , sizeof( T_5 ) ) ;
V_2 -> V_244 = V_431 ;
V_2 -> V_374 = 1 ;
V_2 -> V_232 = 0 ;
}
return V_2 ;
}
static int F_227 ( void )
{
int V_24 ;
V_432 = F_228 ( 128 ) ;
if ( ! V_432 )
return - V_186 ;
V_432 -> V_433 = L_125 ;
V_432 -> V_3 = L_141 ;
V_432 -> V_434 = V_435 ;
V_432 -> V_436 = 64 ;
V_432 -> type = V_437 ;
V_432 -> V_438 = V_439 ;
V_432 -> V_440 = V_441 ;
V_432 -> V_440 . V_197 =
V_442 | V_210 | V_201 | V_198 | V_223 ;
V_432 -> V_440 . V_443 = 9600 ;
V_432 -> V_440 . V_444 = 9600 ;
V_432 -> V_12 = V_445 ;
F_229 ( V_432 , & V_446 ) ;
if ( ( V_24 = F_230 ( V_432 ) ) < 0 ) {
F_4 ( L_142 ,
__FILE__ , __LINE__ ) ;
F_231 ( V_432 ) ;
V_432 = NULL ;
return V_24 ;
}
F_4 ( L_143 ,
V_433 , V_368 ,
V_432 -> V_434 ) ;
return 0 ;
}
static void F_232 ( void )
{
struct V_1 * V_2 ;
int V_379 ;
for ( V_379 = 0 ; ( V_379 < V_447 ) && V_448 [ V_379 ] && V_449 [ V_379 ] ; V_379 ++ ) {
if ( V_19 >= V_20 )
F_4 ( L_144 ,
V_448 [ V_379 ] , V_449 [ V_379 ] , V_450 [ V_379 ] ) ;
V_2 = F_222 () ;
if ( ! V_2 ) {
if ( V_19 >= V_451 )
F_4 ( L_145 ) ;
continue;
}
V_2 -> V_135 = ( unsigned int ) V_448 [ V_379 ] ;
V_2 -> V_175 = ( unsigned int ) V_449 [ V_379 ] ;
V_2 -> V_175 = F_233 ( V_2 -> V_175 ) ;
V_2 -> V_346 = ( unsigned int ) V_450 [ V_379 ] ;
V_2 -> V_342 = V_452 ;
V_2 -> V_408 = 16 ;
V_2 -> V_410 = 0 ;
F_220 ( V_2 ) ;
}
}
static void F_234 ( void )
{
int V_24 ;
struct V_1 * V_2 ;
struct V_1 * V_453 ;
F_4 ( L_146 , V_433 , V_368 ) ;
if ( V_432 ) {
V_24 = F_235 ( V_432 ) ;
if ( V_24 )
F_4 ( L_147 ,
__FILE__ , __LINE__ , V_24 ) ;
F_231 ( V_432 ) ;
}
V_2 = V_333 ;
while( V_2 ) {
#if V_85
F_236 ( V_2 ) ;
#endif
F_83 ( V_2 ) ;
V_453 = V_2 ;
V_2 = V_2 -> V_334 ;
F_237 ( & V_453 -> V_42 ) ;
F_200 ( V_453 ) ;
}
if ( V_454 )
F_238 ( & V_455 ) ;
}
static int T_6 F_239 ( void )
{
int V_24 ;
if ( V_456 ) {
F_1 () ;
F_240 () ;
}
F_4 ( L_148 , V_433 , V_368 ) ;
F_232 () ;
if ( ( V_24 = F_241 ( & V_455 ) ) < 0 )
F_4 ( L_149 , __FILE__ , V_24 ) ;
else
V_454 = true ;
if ( ( V_24 = F_227 () ) < 0 )
goto error;
return 0 ;
error:
F_234 () ;
return V_24 ;
}
static void T_7 F_242 ( void )
{
F_234 () ;
}
static void F_35 ( struct V_1 * V_2 , T_2 V_457 )
{
F_52 ( V_457 + V_2 -> V_458 , V_2 -> V_135 + V_136 ) ;
if ( V_2 -> V_342 == V_343 )
F_53 ( V_2 -> V_135 + V_136 ) ;
}
static void F_34 ( struct V_1 * V_2 , T_2 V_457 )
{
F_52 ( V_457 + V_2 -> V_459 , V_2 -> V_135 ) ;
if ( V_2 -> V_342 == V_343 )
F_53 ( V_2 -> V_135 ) ;
}
static void F_64 ( struct V_1 * V_2 , T_2 V_460 , T_2 V_461 )
{
F_52 ( V_460 + V_2 -> V_459 , V_2 -> V_135 ) ;
F_52 ( V_461 , V_2 -> V_135 ) ;
if ( V_2 -> V_342 == V_343 )
F_53 ( V_2 -> V_135 ) ;
}
static T_2 F_65 ( struct V_1 * V_2 , T_2 V_460 )
{
F_52 ( V_460 + V_2 -> V_459 , V_2 -> V_135 ) ;
return F_53 ( V_2 -> V_135 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_2 V_460 , T_2 V_461 )
{
F_52 ( V_460 + V_2 -> V_458 , V_2 -> V_135 + V_136 ) ;
F_52 ( V_461 , V_2 -> V_135 + V_136 ) ;
if ( V_2 -> V_342 == V_343 )
F_53 ( V_2 -> V_135 + V_136 ) ;
}
static T_2 F_25 ( struct V_1 * V_2 , T_2 V_460 )
{
F_52 ( V_460 + V_2 -> V_458 , V_2 -> V_135 + V_136 ) ;
return F_53 ( V_2 -> V_135 + V_136 ) ;
}
static void F_243 ( struct V_1 * V_2 )
{
T_2 V_461 ;
bool V_462 ;
F_27 ( V_2 , V_463 , 0x1f ) ;
V_461 = F_25 ( V_2 , V_464 ) ;
V_462 = ( V_461 == V_465 ) ;
if ( V_2 -> V_36 . V_12 & V_233 )
{
V_461 = 0x8e06 ;
}
else
{
if ( V_2 -> V_36 . V_37 == V_200 ) {
V_461 = 0x0001 ;
F_27 ( V_2 , V_292 ,
( unsigned short ) ( ( F_25 ( V_2 , V_292 ) & ~ ( V_57 | V_195 ) ) | V_195 ) ) ;
V_461 |= 0x0400 ;
}
else {
V_461 = 0x0606 ;
if ( V_2 -> V_36 . V_12 & V_466 )
V_461 |= V_194 ;
else if ( V_2 -> V_36 . V_12 & V_467 )
V_461 |= V_193 ;
else if ( V_2 -> V_36 . V_12 & V_468 )
V_461 |= V_193 | V_194 ;
}
if ( V_2 -> V_36 . V_469 != V_470 )
V_461 |= V_57 ;
}
if ( V_2 -> V_36 . V_37 == V_38 &&
( V_2 -> V_36 . V_12 & V_471 ) )
V_461 |= V_195 ;
if ( V_2 -> V_36 . V_472 != 0xff )
{
F_27 ( V_2 , V_473 , V_2 -> V_36 . V_472 ) ;
V_461 |= V_474 ;
}
F_27 ( V_2 , V_58 , V_461 ) ;
V_2 -> V_56 = V_461 ;
V_461 = 0x0500 ;
switch ( V_2 -> V_36 . V_475 ) {
case V_476 : V_461 |= V_57 ; break;
case V_477 : V_461 |= V_194 ; break;
case V_478 : V_461 |= V_194 | V_57 ; break;
case V_479 : V_461 |= V_193 ; break;
case V_480 : V_461 |= V_193 | V_57 ; break;
case V_481 : V_461 |= V_193 | V_194 ; break;
case V_482 : V_461 |= V_193 | V_194 | V_57 ; break;
}
if ( ( V_2 -> V_36 . V_483 & V_484 ) == V_485 )
V_461 |= V_160 ;
else if ( ( V_2 -> V_36 . V_483 & V_484 ) == V_486 )
V_461 |= ( V_195 | V_178 | V_160 ) ;
F_27 ( V_2 , V_487 , V_461 ) ;
F_27 ( V_2 , V_488 , V_489 ) ;
F_51 ( V_2 , V_490 ) ;
V_461 = F_25 ( V_2 , V_59 ) & 0xc0 ;
if ( V_2 -> V_342 == V_343 )
F_27 ( V_2 , V_59 , ( T_2 ) ( 0x030a | V_461 ) ) ;
else
F_27 ( V_2 , V_59 , ( T_2 ) ( 0x140a | V_461 ) ) ;
F_31 ( V_2 , V_141 ) ;
F_30 ( V_2 , V_67 ) ;
V_461 = 0x0400 ;
switch ( V_2 -> V_36 . V_475 ) {
case V_476 : V_461 |= V_57 ; break;
case V_477 : V_461 |= V_194 ; break;
case V_478 : V_461 |= V_194 | V_57 ; break;
case V_479 : V_461 |= V_193 ; break;
case V_480 : V_461 |= V_193 | V_57 ; break;
case V_481 : V_461 |= V_193 | V_194 ; break;
case V_482 : V_461 |= V_193 | V_194 | V_57 ; break;
}
if ( ( V_2 -> V_36 . V_483 & V_484 ) == V_485 )
V_461 |= V_160 | V_165 ;
else if ( ( V_2 -> V_36 . V_483 & V_484 ) == V_486 )
V_461 |= ( V_195 | V_178 | V_160 | V_165 ) ;
F_27 ( V_2 , V_363 , V_461 ) ;
F_131 ( V_2 ) ;
F_136 ( V_2 , V_491 ) ;
if ( V_2 -> V_342 == V_343 )
F_27 ( V_2 , V_354 , 0x0736 ) ;
else
F_27 ( V_2 , V_354 , 0x1436 ) ;
F_33 ( V_2 , V_492 ) ;
F_30 ( V_2 , V_69 ) ;
V_2 -> V_493 = 0 ;
if ( ! V_462 )
V_2 -> V_493 |= V_494 ;
F_27 ( V_2 , V_68 , V_2 -> V_493 ) ;
V_461 = 0x0f40 ;
if ( V_2 -> V_36 . V_12 & V_495 )
V_461 |= 0x0003 ;
else if ( V_2 -> V_36 . V_12 & V_496 )
V_461 |= 0x0004 ;
else if ( V_2 -> V_36 . V_12 & V_497 )
V_461 |= 0x0006 ;
else
V_461 |= 0x0007 ;
if ( V_2 -> V_36 . V_12 & V_498 )
V_461 |= 0x0018 ;
else if ( V_2 -> V_36 . V_12 & V_499 )
V_461 |= 0x0020 ;
else if ( V_2 -> V_36 . V_12 & V_500 )
V_461 |= 0x0038 ;
else
V_461 |= 0x0030 ;
F_27 ( V_2 , V_501 , V_461 ) ;
V_461 = 0x0000 ;
if ( V_2 -> V_36 . V_12 & ( V_495 | V_498 ) ) {
V_385 V_502 ;
V_385 V_503 ;
T_2 V_504 ;
if ( V_2 -> V_342 == V_343 )
V_502 = 11059200 ;
else
V_502 = 14745600 ;
if ( V_2 -> V_36 . V_12 & V_505 ) {
V_503 = 16 ;
V_461 |= V_178 ;
}
else if ( V_2 -> V_36 . V_12 & V_506 ) {
V_503 = 8 ;
V_461 |= V_507 ;
}
else
V_503 = 32 ;
if ( V_2 -> V_36 . V_508 )
{
V_504 = ( T_2 ) ( ( V_502 / V_503 ) / V_2 -> V_36 . V_508 ) ;
if ( ! ( ( ( ( V_502 / V_503 ) % V_2 -> V_36 . V_508 ) * 2 )
/ V_2 -> V_36 . V_508 ) )
V_504 -- ;
}
else
V_504 = - 1 ;
F_27 ( V_2 , V_509 , V_504 ) ;
V_461 |= V_474 ;
switch ( V_2 -> V_36 . V_475 ) {
case V_510 :
case V_476 :
case V_477 :
case V_478 : V_461 |= V_165 ; break;
case V_479 :
case V_480 : V_461 |= V_160 ; break;
case V_481 :
case V_482 : V_461 |= V_160 | V_165 ; break;
}
}
F_27 ( V_2 , V_511 , V_461 ) ;
F_27 ( V_2 , V_512 , 0x1020 ) ;
if ( V_2 -> V_36 . V_12 & V_513 ) {
F_27 ( V_2 , V_122 ,
( T_2 ) ( F_25 ( V_2 , V_122 ) | V_514 ) ) ;
}
F_244 ( V_2 ) ;
F_30 ( V_2 , V_67 | V_130 |
V_69 | V_126 | V_158 ) ;
F_27 ( V_2 , V_122 , ( T_2 ) ( F_25 ( V_2 , V_122 ) | V_133 ) ) ;
F_95 ( V_2 , V_158 ) ;
V_2 -> V_459 = 0 ;
F_52 ( 0 , V_2 -> V_135 ) ;
F_34 ( V_2 , V_515 ) ;
V_2 -> V_459 = V_165 ;
F_52 ( V_165 , V_2 -> V_135 ) ;
if ( V_2 -> V_342 == V_452 ) {
F_27 ( V_2 , V_192 , ( T_2 ) ( ( F_25 ( V_2 , V_192 ) | V_193 ) & ~ V_194 ) ) ;
}
if ( V_2 -> V_342 == V_343 ) {
F_64 ( V_2 , V_516 , 0xa00b ) ;
}
else
F_64 ( V_2 , V_516 , 0x800b ) ;
F_64 ( V_2 , V_162 , 0xf200 ) ;
F_64 ( V_2 , V_167 , 0xf200 ) ;
F_64 ( V_2 , V_517 , 0x9000 ) ;
F_65 ( V_2 , V_162 ) ;
F_65 ( V_2 , V_167 ) ;
F_64 ( V_2 , V_159 , 0x0303 ) ;
V_461 = 0x8080 ;
switch ( V_2 -> V_36 . V_518 ) {
case V_519 : V_461 |= V_178 ; break;
case V_520 : V_461 |= V_507 ; break;
case V_521 : V_461 |= V_507 | V_178 ; break;
}
switch ( V_2 -> V_36 . V_469 ) {
case V_522 : V_461 |= V_165 | V_195 ; break;
case V_523 : V_461 |= V_165 ; break;
case V_524 : V_461 |= V_160 ; break;
case V_525 : V_461 |= V_160 | V_165 ; break;
}
F_27 ( V_2 , V_526 , V_461 ) ;
if ( V_2 -> V_342 == V_343 ) {
F_64 ( V_2 , V_527 , 0x0000 ) ;
}
else
F_64 ( V_2 , V_527 , 0x2000 ) ;
F_10 ( V_2 ) ;
F_90 ( V_2 ) ;
}
static void F_245 ( struct V_1 * V_2 , int V_245 )
{
if ( V_245 ) {
F_27 ( V_2 , V_292 , F_25 ( V_2 , V_292 ) | ( V_293 | V_528 ) ) ;
F_27 ( V_2 , V_501 , 0x0f64 ) ;
if ( V_2 -> V_36 . V_508 ) {
if ( V_2 -> V_342 == V_343 )
F_27 ( V_2 , V_529 , ( T_2 ) ( ( 11059200 / V_2 -> V_36 . V_508 ) - 1 ) ) ;
else
F_27 ( V_2 , V_529 , ( T_2 ) ( ( 14745600 / V_2 -> V_36 . V_508 ) - 1 ) ) ;
} else
F_27 ( V_2 , V_529 , ( T_2 ) 8 ) ;
F_27 ( V_2 , V_511 , ( T_2 ) ( ( F_25 ( V_2 , V_511 ) & ~ V_161 ) | V_166 ) ) ;
F_27 ( V_2 , V_292 , ( T_2 ) ( ( F_25 ( V_2 , V_292 ) & 0xfff8 ) | 0x0004 ) ) ;
V_2 -> V_458 = 0x300 ;
F_52 ( 0x0300 , V_2 -> V_135 + V_136 ) ;
} else {
F_27 ( V_2 , V_292 , F_25 ( V_2 , V_292 ) & ~ ( V_293 | V_528 ) ) ;
V_2 -> V_458 = 0 ;
F_52 ( 0 , V_2 -> V_135 + V_136 ) ;
}
}
static void F_246 ( struct V_1 * V_2 , V_385 V_219 )
{
V_385 V_502 ;
T_2 V_504 ;
if ( V_219 ) {
if ( V_2 -> V_342 == V_343 )
V_502 = 11059200 ;
else
V_502 = 14745600 ;
V_504 = ( T_2 ) ( V_502 / V_219 ) ;
if ( ! ( ( ( V_502 % V_219 ) * 2 ) / V_219 ) )
V_504 -- ;
F_27 ( V_2 , V_529 , V_504 ) ;
F_27 ( V_2 , V_511 , ( T_2 ) ( ( F_25 ( V_2 , V_511 ) & ~ V_161 ) | V_166 ) ) ;
F_27 ( V_2 , V_292 , ( T_2 ) ( ( F_25 ( V_2 , V_292 ) & 0xfff8 ) | 0x0004 ) ) ;
} else {
F_27 ( V_2 , V_511 , ( T_2 ) ( F_25 ( V_2 , V_511 ) & ~ V_166 ) ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
int V_530 ;
int V_531 ;
int V_532 ;
bool V_533 = false ;
bool V_534 = false ;
bool V_535 = false ;
V_386 * V_380 = V_2 -> V_377 ;
V_385 V_391 ;
F_34 ( V_2 , V_536 ) ;
F_51 ( V_2 , V_537 ) ;
F_35 ( V_2 , V_146 ) ;
V_532 = V_530 = V_531 = V_2 -> V_538 ;
while( ! V_380 [ V_531 ] . V_13 )
{
if ( ! V_533 )
{
V_533 = true ;
V_532 = V_531 ;
V_534 = false ;
}
if ( V_380 [ V_531 ] . V_49 )
{
V_533 = false ;
V_534 = true ;
}
V_531 ++ ;
if ( V_531 == V_2 -> V_375 )
V_531 = 0 ;
if ( V_530 == V_531 )
{
F_191 ( V_2 ) ;
V_532 = 0 ;
V_533 = false ;
V_535 = true ;
break;
}
}
if ( V_533 && ! V_534 )
{
V_530 = V_532 ;
do
{
* ( ( unsigned long * ) & ( V_2 -> V_377 [ V_530 ++ ] . V_13 ) ) = V_372 ;
if ( V_530 == V_2 -> V_375 )
V_530 = 0 ;
} while( V_530 != V_531 );
V_535 = true ;
}
if ( V_535 )
{
F_31 ( V_2 , V_141 ) ;
F_30 ( V_2 , V_130 | V_67 ) ;
F_31 ( V_2 , V_130 | V_67 ) ;
F_59 ( V_2 , V_156 ) ;
F_27 ( V_2 , V_512 , ( T_2 ) ( F_25 ( V_2 , V_512 ) | V_57 ) ) ;
V_391 = V_2 -> V_377 [ V_532 ] . V_387 ;
F_64 ( V_2 , V_539 , ( T_2 ) V_391 ) ;
F_64 ( V_2 , V_540 , ( T_2 ) ( V_391 >> 16 ) ) ;
F_31 ( V_2 , V_141 ) ;
F_30 ( V_2 , V_130 | V_67 ) ;
F_95 ( V_2 , V_67 ) ;
F_64 ( V_2 , V_541 , V_133 | V_168 ) ;
F_64 ( V_2 , V_517 , ( T_2 ) ( F_65 ( V_2 , V_517 ) | V_161 ) ) ;
F_34 ( V_2 , V_542 ) ;
if ( V_2 -> V_36 . V_12 & V_543 )
F_59 ( V_2 , V_544 ) ;
else
F_59 ( V_2 , V_545 ) ;
}
else
{
F_27 ( V_2 , V_512 , ( T_2 ) ( F_25 ( V_2 , V_512 ) | V_57 ) ) ;
F_35 ( V_2 , V_146 ) ;
}
}
static void F_90 ( struct V_1 * V_2 )
{
if ( V_19 >= V_51 )
F_4 ( L_150 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_34 ( V_2 , V_157 ) ;
F_31 ( V_2 , V_141 ) ;
F_30 ( V_2 , V_130 | V_67 ) ;
F_60 ( V_2 , V_130 | V_67 ) ;
F_59 ( V_2 , V_156 ) ;
F_27 ( V_2 , V_512 , ( T_2 ) ( F_25 ( V_2 , V_512 ) | V_57 ) ) ;
F_35 ( V_2 , V_146 ) ;
V_2 -> V_247 = false ;
V_2 -> V_163 = false ;
V_2 -> V_41 = false ;
}
static void F_21 ( struct V_1 * V_2 )
{
V_385 V_391 ;
if ( V_19 >= V_51 )
F_4 ( L_151 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_191 ( V_2 ) ;
F_90 ( V_2 ) ;
F_27 ( V_2 , V_512 , ( T_2 ) ( F_25 ( V_2 , V_512 ) | V_57 ) ) ;
F_35 ( V_2 , V_146 ) ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_200 ) {
V_391 = V_2 -> V_377 [ 0 ] . V_387 ;
F_64 ( V_2 , V_539 , ( T_2 ) V_391 ) ;
F_64 ( V_2 , V_540 , ( T_2 ) ( V_391 >> 16 ) ) ;
F_31 ( V_2 , V_141 ) ;
F_30 ( V_2 , V_130 | V_67 ) ;
F_95 ( V_2 , V_67 ) ;
F_64 ( V_2 , V_541 , V_133 | V_168 ) ;
F_64 ( V_2 , V_517 , ( T_2 ) ( F_65 ( V_2 , V_517 ) | V_161 ) ) ;
F_34 ( V_2 , V_542 ) ;
if ( V_2 -> V_36 . V_12 & V_543 )
F_59 ( V_2 , V_544 ) ;
else
F_59 ( V_2 , V_545 ) ;
} else {
F_31 ( V_2 , V_141 ) ;
F_30 ( V_2 , V_130 | V_67 ) ;
F_95 ( V_2 , V_130 ) ;
F_35 ( V_2 , V_146 ) ;
F_51 ( V_2 , V_537 ) ;
F_59 ( V_2 , V_545 ) ;
}
F_27 ( V_2 , V_512 , 0x1020 ) ;
V_2 -> V_247 = true ;
}
static void F_13 ( struct V_1 * V_2 )
{
V_385 V_391 ;
unsigned int V_546 ;
if ( V_19 >= V_51 )
F_4 ( L_152 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( V_2 -> V_78 ) {
V_2 -> V_82 = false ;
if ( V_2 -> V_36 . V_12 & V_547 ) {
F_37 ( V_2 ) ;
if ( ! ( V_2 -> V_83 & V_84 ) ) {
V_2 -> V_83 |= V_84 ;
F_38 ( V_2 ) ;
V_2 -> V_82 = true ;
}
}
if ( V_2 -> V_36 . V_37 == V_226 ) {
if ( ! V_2 -> V_43 ) {
F_33 ( V_2 , V_492 ) ;
F_30 ( V_2 , V_69 + V_126 ) ;
F_95 ( V_2 , V_126 ) ;
F_49 ( V_2 ) ;
}
} else {
F_34 ( V_2 , V_72 ) ;
V_546 = V_2 -> V_378 [ V_2 -> V_548 ] . V_549 ;
if ( V_2 -> V_36 . V_37 == V_200 )
V_2 -> V_378 [ V_2 -> V_548 ] . V_549 = 0 ;
F_27 ( V_2 , V_550 , ( T_2 ) V_546 ) ;
F_35 ( V_2 , V_73 ) ;
V_391 = V_2 -> V_378 [ V_2 -> V_548 ] . V_387 ;
F_64 ( V_2 , V_551 , ( T_2 ) V_391 ) ;
F_64 ( V_2 , V_552 , ( T_2 ) ( V_391 >> 16 ) ) ;
F_33 ( V_2 , V_492 ) ;
F_30 ( V_2 , V_69 ) ;
F_95 ( V_2 , V_69 ) ;
if ( V_2 -> V_36 . V_37 == V_200 &&
V_2 -> V_374 > 1 ) {
F_64 ( V_2 , V_553 , V_168 | V_133 ) ;
F_64 ( V_2 , V_517 , ( T_2 ) ( F_65 ( V_2 , V_517 ) | V_166 ) ) ;
}
F_34 ( V_2 , V_554 ) ;
F_136 ( V_2 , V_555 ) ;
F_204 ( & V_2 -> V_81 , V_320 +
F_205 ( 5000 ) ) ;
}
V_2 -> V_43 = true ;
}
if ( ! V_2 -> V_23 ) {
V_2 -> V_23 = true ;
if ( V_2 -> V_36 . V_12 & V_513 )
F_247 ( V_2 , V_556 ) ;
else
F_247 ( V_2 , V_545 ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_19 >= V_51 )
F_4 ( L_153 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_36 ( & V_2 -> V_81 ) ;
F_33 ( V_2 , V_492 ) ;
F_30 ( V_2 , V_69 + V_126 ) ;
F_60 ( V_2 , V_69 + V_126 ) ;
F_247 ( V_2 , V_156 ) ;
F_34 ( V_2 , V_72 ) ;
F_35 ( V_2 , V_73 ) ;
V_2 -> V_23 = false ;
V_2 -> V_43 = false ;
}
static void F_49 ( struct V_1 * V_2 )
{
int V_128 ;
T_8 V_557 [ 2 ] ;
if ( ! V_2 -> V_78 && ! V_2 -> V_236 )
return;
F_136 ( V_2 , V_558 ) ;
while( ( V_128 = F_25 ( V_2 , V_354 ) >> 8 ) && V_2 -> V_78 ) {
if ( ( V_2 -> V_78 > 1 ) && ( V_128 > 1 ) && ! V_2 -> V_236 ) {
V_557 [ 0 ] = V_2 -> V_184 [ V_2 -> V_80 ++ ] ;
V_2 -> V_80 = V_2 -> V_80 & ( V_227 - 1 ) ;
V_557 [ 1 ] = V_2 -> V_184 [ V_2 -> V_80 ++ ] ;
V_2 -> V_80 = V_2 -> V_80 & ( V_227 - 1 ) ;
F_52 ( * ( ( T_2 * ) V_557 ) , V_2 -> V_135 + V_559 ) ;
V_2 -> V_78 -= 2 ;
V_2 -> V_54 . V_295 += 2 ;
} else {
F_52 ( ( F_53 ( V_2 -> V_135 + V_136 ) & 0x0780 ) | ( V_560 + V_132 ) ,
V_2 -> V_135 + V_136 ) ;
if ( V_2 -> V_236 ) {
F_52 ( V_2 -> V_236 , V_2 -> V_135 + V_136 ) ;
V_2 -> V_236 = 0 ;
} else {
F_52 ( V_2 -> V_184 [ V_2 -> V_80 ++ ] , V_2 -> V_135 + V_136 ) ;
V_2 -> V_80 = V_2 -> V_80 & ( V_227 - 1 ) ;
V_2 -> V_78 -- ;
}
V_2 -> V_54 . V_295 ++ ;
}
}
}
static void F_248 ( struct V_1 * V_2 )
{
if ( V_2 -> V_342 == V_343 ) {
int V_379 ;
V_385 V_561 ;
volatile V_385 * V_562 = ( V_385 * ) ( V_2 -> V_416 + 0x50 ) ;
V_385 * V_563 = ( V_385 * ) ( V_2 -> V_416 + 0x28 ) ;
V_2 -> V_564 |= V_565 ;
* V_562 = V_2 -> V_564 ;
for( V_379 = 0 ; V_379 < 10 ; V_379 ++ )
V_561 = * V_562 ;
V_2 -> V_564 &= ~ V_565 ;
* V_562 = V_2 -> V_564 ;
* V_563 = F_249 (
1 ,
2 ,
2 ,
0 ,
4 ,
0 ,
0 ,
5
) ;
} else {
F_250 ( 0 , V_2 -> V_135 + 8 ) ;
}
V_2 -> V_459 = 0 ;
V_2 -> V_458 = 0 ;
V_2 -> V_566 = 0 ;
F_52 ( 0x000c , V_2 -> V_135 + V_567 ) ;
F_52 ( 0 , V_2 -> V_135 ) ;
F_52 ( 0 , V_2 -> V_135 + V_136 ) ;
F_35 ( V_2 , V_568 ) ;
F_27 ( V_2 , V_192 , 0xf0f5 ) ;
F_27 ( V_2 , V_292 , 0x0004 ) ;
}
static void F_93 ( struct V_1 * V_2 )
{
T_2 V_461 ;
F_71 ( V_2 ) ;
F_52 ( 0 , V_2 -> V_135 ) ;
F_34 ( V_2 , V_515 ) ;
F_251 ( V_2 ) ;
V_461 = 0 ;
if ( V_2 -> V_36 . V_212 != 1 )
V_461 |= V_194 ;
F_27 ( V_2 , V_58 , V_461 ) ;
V_461 = 0 ;
if ( V_2 -> V_36 . V_207 != 8 )
V_461 |= V_474 | V_133 | V_168 ;
if ( V_2 -> V_36 . V_144 != V_213 ) {
V_461 |= V_569 ;
if ( V_2 -> V_36 . V_144 != V_216 )
V_461 |= V_528 ;
}
F_27 ( V_2 , V_487 , V_461 ) ;
F_51 ( V_2 , V_570 ) ;
F_27 ( V_2 , V_59 , 0x0000 ) ;
F_31 ( V_2 , V_141 ) ;
F_30 ( V_2 , V_67 ) ;
V_461 = 0 ;
if ( V_2 -> V_36 . V_207 != 8 )
V_461 |= V_474 | V_133 | V_168 ;
if ( V_2 -> V_36 . V_144 != V_213 ) {
V_461 |= V_569 ;
if ( V_2 -> V_36 . V_144 != V_216 )
V_461 |= V_528 ;
}
F_27 ( V_2 , V_363 , V_461 ) ;
F_131 ( V_2 ) ;
F_136 ( V_2 , V_571 ) ;
F_27 ( V_2 , V_354 , 0x1f40 ) ;
F_33 ( V_2 , V_492 ) ;
F_30 ( V_2 , V_69 ) ;
F_252 ( V_2 , V_2 -> V_36 . V_219 ) ;
F_27 ( V_2 , V_512 , 0x0020 ) ;
F_60 ( V_2 , V_69 + V_126 +
V_130 + V_67 ) ;
F_30 ( V_2 , V_69 + V_126 +
V_130 + V_67 ) ;
F_244 ( V_2 ) ;
if ( V_2 -> V_342 == V_452 ) {
F_27 ( V_2 , V_192 , ( T_2 ) ( ( F_25 ( V_2 , V_192 ) | V_57 ) & ~ V_195 ) ) ;
}
if ( V_2 -> V_36 . V_572 ) {
V_2 -> V_458 = 0x300 ;
F_52 ( 0x0300 , V_2 -> V_135 + V_136 ) ;
}
}
static void F_251 ( struct V_1 * V_2 )
{
int V_379 ;
unsigned long V_573 = V_2 -> V_36 . V_37 ;
V_2 -> V_36 . V_37 = V_38 ;
F_71 ( V_2 ) ;
F_243 ( V_2 ) ;
F_245 ( V_2 , 1 ) ;
F_27 ( V_2 , V_529 , 0 ) ;
F_27 ( V_2 , V_526 , 0x0100 ) ;
F_35 ( V_2 , V_146 ) ;
F_59 ( V_2 , V_545 ) ;
F_27 ( V_2 , V_550 , 2 ) ;
F_35 ( V_2 , V_73 ) ;
F_33 ( V_2 , V_492 ) ;
F_52 ( 0 , V_2 -> V_135 + V_559 ) ;
F_136 ( V_2 , V_555 ) ;
F_247 ( V_2 , V_545 ) ;
for ( V_379 = 0 ; V_379 < 1000 ; V_379 ++ )
if ( F_25 ( V_2 , V_50 ) & ( V_165 | V_474 | V_133 | V_161 ) )
break;
F_245 ( V_2 , 0 ) ;
F_244 ( V_2 ) ;
V_2 -> V_36 . V_37 = V_573 ;
}
static void F_92 ( struct V_1 * V_2 )
{
F_251 ( V_2 ) ;
F_243 ( V_2 ) ;
if ( V_2 -> V_342 == V_452 ) {
F_27 ( V_2 , V_192 , ( T_2 ) ( ( F_25 ( V_2 , V_192 ) | V_57 ) & ~ V_195 ) ) ;
}
F_246 ( V_2 , V_2 -> V_36 . V_508 ) ;
if ( V_2 -> V_36 . V_572 )
F_245 ( V_2 , 1 ) ;
}
static void F_131 ( struct V_1 * V_2 )
{
T_2 V_566 = V_574 ;
switch( V_2 -> V_244 ) {
case V_431 : V_566 = V_574 ; break;
case V_575 : V_566 = V_576 ; break;
case V_577 : V_566 = V_578 ; break;
case V_579 : V_566 = V_580 ; break;
case V_581 : V_566 = V_582 ; break;
case V_583 : V_566 = V_584 ; break;
case V_585 : V_566 = V_586 ; break;
}
V_2 -> V_566 = V_566 ;
V_2 -> V_493 &= ~ V_587 ;
V_2 -> V_493 += V_566 ;
F_27 ( V_2 , V_68 , V_2 -> V_493 ) ;
if ( V_2 -> V_36 . V_37 == V_200 ) {
unsigned char V_588 = 0 ;
switch( V_2 -> V_244 ) {
case V_431 :
V_588 = 0x7e ;
break;
case V_575 :
V_588 = 0x55 ;
break;
case V_577 :
case V_583 :
V_588 = 0x00 ;
break;
case V_579 :
case V_585 :
V_588 = 0xff ;
break;
case V_581 :
V_588 = 0xaa ;
break;
}
F_253 ( V_2 , V_588 , V_588 ) ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
T_2 V_49 ;
V_2 -> V_83 &= V_84 | V_199 ;
V_49 = F_25 ( V_2 , V_90 ) ;
if ( V_49 & V_116 )
V_2 -> V_83 |= V_265 ;
if ( V_49 & V_110 )
V_2 -> V_83 |= V_262 ;
if ( V_49 & V_99 )
V_2 -> V_83 |= V_268 ;
if ( V_49 & V_105 )
V_2 -> V_83 |= V_259 ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_2 V_589 ;
unsigned char V_590 = V_2 -> V_83 ;
V_589 = F_25 ( V_2 , V_192 ) ;
if ( V_590 & V_84 )
V_589 &= ~ ( V_528 ) ;
else
V_589 |= V_528 ;
if ( V_590 & V_199 )
V_589 &= ~ ( V_474 ) ;
else
V_589 |= V_474 ;
F_27 ( V_2 , V_192 , V_589 ) ;
}
static void F_252 ( struct V_1 * V_2 , V_385 V_219 )
{
if ( V_219 ) {
F_27 ( V_2 , V_501 , 0x0f64 ) ;
if ( V_2 -> V_342 == V_343 )
F_27 ( V_2 , V_529 , ( T_2 ) ( ( 691200 / V_219 ) - 1 ) ) ;
else
F_27 ( V_2 , V_529 , ( T_2 ) ( ( 921600 / V_219 ) - 1 ) ) ;
F_27 ( V_2 , V_511 ,
( T_2 ) ( ( F_25 ( V_2 , V_511 ) & ~ V_161 ) | V_166 ) ) ;
F_27 ( V_2 , V_292 ,
( T_2 ) ( ( F_25 ( V_2 , V_292 ) & 0xfff8 ) | 0x0004 ) ) ;
} else {
F_27 ( V_2 , V_511 , ( T_2 ) ( F_25 ( V_2 , V_511 ) & ~ V_166 ) ) ;
}
}
static void F_192 ( struct V_1 * V_2 )
{
unsigned int V_379 ;
for ( V_379 = 0 ; V_379 < V_2 -> V_373 ; V_379 ++ ) {
* ( ( unsigned long * ) & ( V_2 -> V_378 [ V_379 ] . V_13 ) ) = 0 ;
}
V_2 -> V_591 = 0 ;
V_2 -> V_548 = 0 ;
V_2 -> V_169 = 0 ;
V_2 -> V_399 = 0 ;
V_2 -> V_400 = 0 ;
V_2 -> V_231 = 0 ;
}
static int F_203 ( struct V_1 * V_2 )
{
return V_2 -> V_373 - V_2 -> V_169 ;
}
static void F_191 ( struct V_1 * V_2 )
{
unsigned int V_379 ;
for ( V_379 = 0 ; V_379 < V_2 -> V_375 ; V_379 ++ ) {
* ( ( unsigned long * ) & ( V_2 -> V_377 [ V_379 ] . V_13 ) ) = V_372 ;
}
V_2 -> V_538 = 0 ;
}
static void F_254 ( struct V_1 * V_2 , unsigned int V_592 , unsigned int V_593 )
{
bool V_594 = false ;
V_386 * V_595 ;
unsigned int V_596 ;
V_596 = V_592 ;
while( ! V_594 ) {
V_595 = & ( V_2 -> V_377 [ V_596 ] ) ;
if ( V_596 == V_593 ) {
V_594 = true ;
}
* ( ( unsigned long * ) & ( V_595 -> V_13 ) ) = V_372 ;
V_596 ++ ;
if ( V_596 == V_2 -> V_375 )
V_596 = 0 ;
}
V_2 -> V_538 = V_596 ;
}
static bool V_39 ( struct V_1 * V_2 )
{
unsigned int V_592 , V_593 ;
unsigned short V_49 ;
V_386 * V_595 ;
unsigned int V_597 = 0 ;
bool V_598 = false ;
unsigned long V_12 ;
struct V_9 * V_10 = V_2 -> V_42 . V_10 ;
bool V_599 = false ;
V_592 = V_593 = V_2 -> V_538 ;
while( ! V_2 -> V_377 [ V_593 ] . V_49 ) {
if ( V_2 -> V_377 [ V_593 ] . V_13 )
goto V_600;
V_593 ++ ;
if ( V_593 == V_2 -> V_375 )
V_593 = 0 ;
if ( V_593 == V_592 ) {
if ( V_2 -> V_247 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
goto V_600;
}
}
V_49 = V_2 -> V_377 [ V_593 ] . V_49 ;
if ( V_49 & ( V_601 | V_65 |
V_602 | V_603 ) ) {
if ( V_49 & V_601 )
V_2 -> V_54 . V_348 ++ ;
else if ( V_49 & V_603 )
V_2 -> V_54 . V_55 ++ ;
else if ( V_49 & V_65 )
V_2 -> V_54 . V_66 ++ ;
else {
V_2 -> V_54 . V_350 ++ ;
if ( V_2 -> V_36 . V_483 & V_604 )
V_599 = true ;
}
V_597 = 0 ;
#if V_85
{
V_2 -> V_113 -> V_605 . V_606 ++ ;
V_2 -> V_113 -> V_605 . V_607 ++ ;
}
#endif
} else
V_599 = true ;
if ( V_599 ) {
V_597 = V_489 - V_2 -> V_377 [ V_593 ] . V_549 ;
if ( V_2 -> V_36 . V_483 == V_485 )
V_597 -= 2 ;
else if ( V_2 -> V_36 . V_483 == V_486 )
V_597 -= 4 ;
}
if ( V_19 >= V_35 )
F_4 ( L_154 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_49 , V_597 ) ;
if ( V_19 >= V_608 )
F_255 ( V_2 , V_2 -> V_377 [ V_592 ] . V_392 ,
F_110 ( int , V_597 , V_372 ) , 0 ) ;
if ( V_597 ) {
if ( ( ( V_2 -> V_36 . V_483 & V_604 ) &&
( ( V_597 + 1 ) > V_2 -> V_235 ) ) ||
( V_597 > V_2 -> V_235 ) )
V_2 -> V_54 . V_349 ++ ;
else {
int V_609 = V_597 ;
int V_331 = V_592 ;
unsigned char * V_610 = V_2 -> V_394 ;
if ( ! ( V_49 & V_602 ) )
V_2 -> V_54 . V_347 ++ ;
while( V_609 ) {
int V_611 ;
if ( V_609 > V_372 )
V_611 = V_372 ;
else
V_611 = V_609 ;
V_595 = & ( V_2 -> V_377 [ V_331 ] ) ;
memcpy ( V_610 , V_595 -> V_392 , V_611 ) ;
V_610 += V_611 ;
V_609 -= V_611 ;
if ( ++ V_331 == V_2 -> V_375 )
V_331 = 0 ;
}
if ( V_2 -> V_36 . V_483 & V_604 ) {
++ V_597 ;
* V_610 = ( V_49 & V_602 ?
V_612 :
V_613 ) ;
if ( V_19 >= V_608 )
F_4 ( L_155 ,
__FILE__ , __LINE__ , V_2 -> V_21 ,
* V_610 ) ;
}
#if V_85
if ( V_2 -> V_86 )
F_256 ( V_2 , V_2 -> V_394 , V_597 ) ;
else
#endif
F_5 ( V_10 , V_2 -> V_394 , V_2 -> V_396 , V_597 ) ;
}
}
F_254 ( V_2 , V_592 , V_593 ) ;
V_598 = true ;
V_600:
if ( V_2 -> V_247 && V_2 -> V_163 ) {
if ( ! V_2 -> V_377 [ V_593 ] . V_49 &&
V_2 -> V_377 [ V_593 ] . V_13 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
return V_598 ;
}
static bool V_40 ( struct V_1 * V_2 )
{
unsigned int V_614 , V_615 ;
unsigned short V_49 ;
V_386 * V_595 ;
unsigned int V_597 = 0 ;
bool V_598 = false ;
unsigned long V_12 ;
struct V_9 * V_10 = V_2 -> V_42 . V_10 ;
V_614 = V_615 = V_2 -> V_538 ;
++ V_615 ;
if ( V_615 == V_2 -> V_375 )
V_615 = 0 ;
if ( V_2 -> V_377 [ V_614 ] . V_49 != 0 ||
( V_2 -> V_377 [ V_614 ] . V_13 == 0 &&
V_2 -> V_377 [ V_615 ] . V_13 == 0 ) ) {
V_49 = V_2 -> V_377 [ V_614 ] . V_49 ;
if ( V_49 & ( V_601 | V_65 |
V_602 | V_603 ) ) {
if ( V_49 & V_601 )
V_2 -> V_54 . V_348 ++ ;
else if ( V_49 & V_603 )
V_2 -> V_54 . V_55 ++ ;
else if ( V_49 & V_65 )
V_2 -> V_54 . V_66 ++ ;
else
V_2 -> V_54 . V_350 ++ ;
V_597 = 0 ;
} else {
if ( V_49 ) {
if ( V_2 -> V_377 [ V_614 ] . V_549 )
V_597 = V_489 - V_2 -> V_377 [ V_614 ] . V_549 ;
else
V_597 = V_372 ;
}
else
V_597 = V_372 ;
}
if ( V_597 > V_372 ) {
V_597 = V_597 % V_372 ;
}
if ( V_19 >= V_35 )
F_4 ( L_156 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_49 , V_597 ) ;
if ( V_19 >= V_608 )
F_255 ( V_2 , V_2 -> V_377 [ V_614 ] . V_392 ,
F_110 ( int , V_597 , V_372 ) , 0 ) ;
if ( V_597 ) {
V_595 = & ( V_2 -> V_377 [ V_614 ] ) ;
memcpy ( V_2 -> V_394 , V_595 -> V_392 , V_597 ) ;
V_2 -> V_54 . V_347 ++ ;
F_5 ( V_10 , V_2 -> V_394 , V_2 -> V_396 , V_597 ) ;
}
F_254 ( V_2 , V_614 , V_614 ) ;
V_598 = true ;
}
if ( V_2 -> V_247 && V_2 -> V_163 ) {
if ( ! V_2 -> V_377 [ V_614 ] . V_49 &&
V_2 -> V_377 [ V_614 ] . V_13 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
return V_598 ;
}
static void F_107 ( struct V_1 * V_2 ,
const char * V_406 , unsigned int V_407 )
{
unsigned short V_616 ;
unsigned int V_379 = 0 ;
V_386 * V_595 ;
if ( V_19 >= V_608 )
F_255 ( V_2 , V_406 , F_110 ( int , V_407 , V_372 ) , 1 ) ;
if ( V_2 -> V_36 . V_12 & V_233 ) {
V_2 -> V_56 |= V_57 ;
}
V_379 = V_2 -> V_591 ;
V_2 -> V_548 = V_379 ;
V_2 -> V_378 [ V_379 ] . V_49 = V_2 -> V_56 & 0xf000 ;
V_2 -> V_378 [ V_379 ] . V_549 = V_407 ;
V_2 -> V_378 [ V_379 ] . V_13 = V_407 ;
while( V_407 ) {
V_595 = & V_2 -> V_378 [ V_379 ++ ] ;
if ( V_379 == V_2 -> V_373 )
V_379 = 0 ;
if ( V_407 > V_372 )
V_616 = V_372 ;
else
V_616 = V_407 ;
if ( V_2 -> V_342 == V_343 )
F_257 ( V_595 -> V_392 , V_406 , V_616 ) ;
else
memcpy ( V_595 -> V_392 , V_406 , V_616 ) ;
V_595 -> V_13 = V_616 ;
V_406 += V_616 ;
V_407 -= V_616 ;
++ V_2 -> V_169 ;
}
V_2 -> V_591 = V_379 ;
}
static bool F_258 ( struct V_1 * V_2 )
{
static unsigned short V_617 [] =
{ 0x0000 , 0xffff , 0xaaaa , 0x5555 , 0x1234 , 0x6969 , 0x9696 , 0x0f0f } ;
static unsigned int V_618 = F_259 ( V_617 ) ;
unsigned int V_379 ;
bool V_24 = true ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_248 ( V_2 ) ;
if ( ( F_25 ( V_2 , V_122 ) != 0 ) ||
( F_25 ( V_2 , V_176 ) != 0 ) ||
( F_65 ( V_2 , V_177 ) != 0 ) ) {
V_24 = false ;
}
if ( V_24 ) {
for ( V_379 = 0 ; V_379 < V_618 ; V_379 ++ ) {
F_27 ( V_2 , V_529 , V_617 [ V_379 ] ) ;
F_27 ( V_2 , V_509 , V_617 [ ( V_379 + 1 ) % V_618 ] ) ;
F_27 ( V_2 , V_550 , V_617 [ ( V_379 + 2 ) % V_618 ] ) ;
F_27 ( V_2 , V_488 , V_617 [ ( V_379 + 3 ) % V_618 ] ) ;
F_27 ( V_2 , V_473 , V_617 [ ( V_379 + 4 ) % V_618 ] ) ;
F_64 ( V_2 , V_619 , V_617 [ ( V_379 + 5 ) % V_618 ] ) ;
if ( ( F_25 ( V_2 , V_529 ) != V_617 [ V_379 ] ) ||
( F_25 ( V_2 , V_509 ) != V_617 [ ( V_379 + 1 ) % V_618 ] ) ||
( F_25 ( V_2 , V_550 ) != V_617 [ ( V_379 + 2 ) % V_618 ] ) ||
( F_25 ( V_2 , V_488 ) != V_617 [ ( V_379 + 3 ) % V_618 ] ) ||
( F_25 ( V_2 , V_473 ) != V_617 [ ( V_379 + 4 ) % V_618 ] ) ||
( F_65 ( V_2 , V_619 ) != V_617 [ ( V_379 + 5 ) % V_618 ] ) ) {
V_24 = false ;
break;
}
}
}
F_248 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_24 ;
}
static bool F_260 ( struct V_1 * V_2 )
{
unsigned long V_620 ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_248 ( V_2 ) ;
V_2 -> V_125 = false ;
F_27 ( V_2 , V_192 , ( unsigned short ) ( ( F_25 ( V_2 , V_192 ) | V_57 ) & ~ V_195 ) ) ;
F_244 ( V_2 ) ;
F_95 ( V_2 , V_91 ) ;
F_30 ( V_2 , V_91 ) ;
F_41 ( V_2 , V_121 ) ;
F_94 ( V_2 , V_123 + V_124 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_620 = 100 ;
while( V_620 -- && ! V_2 -> V_125 ) {
F_164 ( 10 ) ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_248 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_2 -> V_125 ;
}
static bool F_261 ( struct V_1 * V_2 )
{
unsigned short V_621 ;
unsigned long V_391 ;
unsigned int V_546 ;
unsigned int V_379 ;
char * V_622 ;
bool V_24 = true ;
unsigned short V_49 = 0 ;
unsigned long V_620 ;
unsigned long V_12 ;
T_5 V_243 ;
memcpy ( & V_243 , & V_2 -> V_36 , sizeof( T_5 ) ) ;
memcpy ( & V_2 -> V_36 , & V_430 , sizeof( T_5 ) ) ;
#define F_262 40
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_248 ( V_2 ) ;
F_243 ( V_2 ) ;
F_245 ( V_2 , 1 ) ;
F_64 ( V_2 , V_162 , 0xe200 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_546 = F_262 ;
V_2 -> V_378 [ 0 ] . V_13 = V_546 ;
V_2 -> V_378 [ 0 ] . V_549 = V_546 ;
V_2 -> V_378 [ 0 ] . V_49 = 0x4000 ;
V_622 = V_2 -> V_378 [ 0 ] . V_392 ;
for ( V_379 = 0 ; V_379 < V_546 ; V_379 ++ )
* V_622 ++ = V_379 ;
V_2 -> V_377 [ 0 ] . V_49 = 0 ;
V_2 -> V_377 [ 0 ] . V_13 = V_546 + 4 ;
memset ( V_2 -> V_377 [ 0 ] . V_392 , 0 , V_546 + 4 ) ;
V_2 -> V_378 [ 1 ] . V_13 = 0 ;
V_2 -> V_377 [ 1 ] . V_13 = 0 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_35 ( V_2 , V_146 ) ;
V_391 = V_2 -> V_377 [ 0 ] . V_387 ;
F_64 ( V_2 , V_539 , ( unsigned short ) V_391 ) ;
F_64 ( V_2 , V_540 , ( unsigned short ) ( V_391 >> 16 ) ) ;
F_65 ( V_2 , V_162 ) ;
F_34 ( V_2 , V_542 ) ;
F_27 ( V_2 , V_487 , ( unsigned short ) ( ( F_25 ( V_2 , V_487 ) & 0xfffc ) | 0x0002 ) ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_620 = V_320 + F_205 ( 100 ) ;
for(; ; ) {
if ( F_166 ( V_320 , V_620 ) ) {
V_24 = false ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_49 = F_65 ( V_2 , V_162 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( ! ( V_49 & V_474 ) && ( V_49 & V_569 ) ) {
break;
}
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_27 ( V_2 , V_550 , ( unsigned short ) V_2 -> V_378 [ 0 ] . V_13 ) ;
F_35 ( V_2 , V_73 ) ;
V_391 = V_2 -> V_378 [ 0 ] . V_387 ;
F_64 ( V_2 , V_551 , ( unsigned short ) V_391 ) ;
F_64 ( V_2 , V_552 , ( unsigned short ) ( V_391 >> 16 ) ) ;
F_27 ( V_2 , V_68 , ( unsigned short ) ( ( F_25 ( V_2 , V_68 ) & 0x0f00 ) | 0xfa ) ) ;
F_34 ( V_2 , V_554 ) ;
F_136 ( V_2 , V_558 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_620 = V_320 + F_205 ( 100 ) ;
for(; ; ) {
if ( F_166 ( V_320 , V_620 ) ) {
V_24 = false ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_621 = F_25 ( V_2 , V_354 ) >> 8 ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( V_621 < 16 )
break;
else
if ( V_546 < 32 ) {
if ( V_621 <= ( 32 - V_546 ) )
break;
}
}
if ( V_24 )
{
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_136 ( V_2 , V_555 ) ;
F_27 ( V_2 , V_363 , ( unsigned short ) ( ( F_25 ( V_2 , V_363 ) & 0xfffc ) | 0x0002 ) ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_620 = V_320 + F_205 ( 100 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_49 = F_25 ( V_2 , V_68 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
while ( ! ( V_49 & ( V_528 | V_569 | V_474 | V_168 | V_161 ) ) ) {
if ( F_166 ( V_320 , V_620 ) ) {
V_24 = false ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_49 = F_25 ( V_2 , V_68 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
if ( V_24 ) {
if ( V_49 & ( V_569 | V_161 ) )
V_24 = false ;
}
if ( V_24 ) {
V_620 = V_320 + F_205 ( 100 ) ;
V_49 = V_2 -> V_377 [ 0 ] . V_49 ;
while ( V_49 == 0 ) {
if ( F_166 ( V_320 , V_620 ) ) {
V_24 = false ;
break;
}
V_49 = V_2 -> V_377 [ 0 ] . V_49 ;
}
}
if ( V_24 ) {
V_49 = V_2 -> V_377 [ 0 ] . V_49 ;
if ( V_49 & ( V_165 | V_133 | V_161 ) ) {
V_24 = false ;
} else {
if ( memcmp ( V_2 -> V_378 [ 0 ] . V_392 ,
V_2 -> V_377 [ 0 ] . V_392 , V_546 ) ) {
V_24 = false ;
}
}
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_248 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
memcpy ( & V_2 -> V_36 , & V_243 , sizeof( T_5 ) ) ;
return V_24 ;
}
static int F_80 ( struct V_1 * V_2 )
{
if ( V_19 >= V_20 )
F_4 ( L_157 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( ! F_258 ( V_2 ) ) {
V_2 -> V_623 = V_624 ;
F_4 ( L_158 ,
__FILE__ , __LINE__ , V_2 -> V_21 , ( unsigned short ) ( V_2 -> V_135 ) ) ;
return - V_297 ;
}
if ( ! F_260 ( V_2 ) ) {
V_2 -> V_623 = V_625 ;
F_4 ( L_159 ,
__FILE__ , __LINE__ , V_2 -> V_21 , ( unsigned short ) ( V_2 -> V_175 ) ) ;
return - V_297 ;
}
if ( ! F_261 ( V_2 ) ) {
V_2 -> V_623 = V_626 ;
F_4 ( L_160 ,
__FILE__ , __LINE__ , V_2 -> V_21 , ( unsigned short ) ( V_2 -> V_346 ) ) ;
return - V_297 ;
}
if ( V_19 >= V_20 )
F_4 ( L_161 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return 0 ;
}
static bool F_210 ( struct V_1 * V_2 )
{
static unsigned long V_617 [] =
{ 0x0 , 0x55555555 , 0xaaaaaaaa , 0x66666666 , 0x99999999 , 0xffffffff , 0x12345678 } ;
unsigned long V_618 = F_259 ( V_617 ) ;
unsigned long V_379 ;
unsigned long V_627 = V_628 /sizeof( unsigned long ) ;
unsigned long * V_629 ;
if ( V_2 -> V_342 != V_343 )
return true ;
V_629 = ( unsigned long * ) V_2 -> V_381 ;
for ( V_379 = 0 ; V_379 < V_618 ; V_379 ++ ) {
* V_629 = V_617 [ V_379 ] ;
if ( * V_629 != V_617 [ V_379 ] )
return false ;
}
for ( V_379 = 0 ; V_379 < V_627 ; V_379 ++ ) {
* V_629 = V_379 * 4 ;
V_629 ++ ;
}
V_629 = ( unsigned long * ) V_2 -> V_381 ;
for ( V_379 = 0 ; V_379 < V_627 ; V_379 ++ ) {
if ( * V_629 != V_379 * 4 )
return false ;
V_629 ++ ;
}
memset ( V_2 -> V_381 , 0 , V_628 ) ;
return true ;
}
static void F_257 ( char * V_630 , const char * V_631 ,
unsigned short V_13 )
{
#define F_263 64
unsigned short V_632 = V_13 / F_263 ;
unsigned short V_596 ;
unsigned long V_633 ;
for ( V_596 = 0 ; V_596 < V_632 ; V_596 ++ )
{
memcpy ( V_630 , V_631 , F_263 ) ;
V_633 = * ( ( volatile unsigned long * ) V_630 ) ;
V_630 += F_263 ;
V_631 += F_263 ;
}
memcpy ( V_630 , V_631 , V_13 % F_263 ) ;
}
static void F_255 ( struct V_1 * V_2 , const char * V_11 , int V_13 , int V_634 )
{
int V_379 ;
int V_635 ;
if ( V_634 )
F_4 ( L_162 , V_2 -> V_21 ) ;
else
F_4 ( L_163 , V_2 -> V_21 ) ;
while( V_13 ) {
if ( V_13 > 16 )
V_635 = 16 ;
else
V_635 = V_13 ;
for( V_379 = 0 ; V_379 < V_635 ; V_379 ++ )
F_4 ( L_164 , ( unsigned char ) V_11 [ V_379 ] ) ;
for(; V_379 < 17 ; V_379 ++ )
F_4 ( L_165 ) ;
for( V_379 = 0 ; V_379 < V_635 ; V_379 ++ ) {
if ( V_11 [ V_379 ] >= 040 && V_11 [ V_379 ] <= 0176 )
F_4 ( L_166 , V_11 [ V_379 ] ) ;
else
F_4 ( L_167 ) ;
}
F_4 ( L_168 ) ;
V_11 += V_635 ;
V_13 -= V_635 ;
}
}
static void V_187 ( unsigned long V_636 )
{
struct V_1 * V_2 = (struct V_1 * ) V_636 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_169 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if( V_2 -> V_43 &&
( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_200 ) ) {
V_2 -> V_54 . V_637 ++ ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_43 = false ;
V_2 -> V_78 = V_2 -> V_79 = V_2 -> V_80 = 0 ;
if ( V_2 -> V_36 . V_12 & V_233 )
F_135 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
#if V_85
if ( V_2 -> V_86 )
F_39 ( V_2 ) ;
else
#endif
F_18 ( V_2 ) ;
}
static int F_155 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_2 -> V_36 . V_12 & V_233 ) {
if ( V_2 -> V_43 )
V_2 -> V_44 = true ;
else
F_23 ( V_2 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static void F_23 ( struct V_1 * V_2 )
{
V_2 -> V_44 = false ;
V_2 -> V_56 &= ~ V_57 ;
F_27 ( V_2 , V_58 , V_2 -> V_56 ) ;
}
static void F_135 ( struct V_1 * V_2 )
{
F_35 ( V_2 , V_73 ) ;
F_34 ( V_2 , V_72 ) ;
F_23 ( V_2 ) ;
}
static void F_133 ( struct V_1 * V_2 )
{
V_2 -> V_53 = true ;
F_27 ( V_2 , V_59 ,
( F_25 ( V_2 , V_59 ) | V_52 ) ) ;
V_2 -> V_56 |= V_57 ;
F_27 ( V_2 , V_58 , V_2 -> V_56 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
return F_25 ( V_2 , V_512 ) & V_293 ? 1 : 0 ;
}
static int F_264 ( struct V_638 * V_639 , unsigned short V_475 ,
unsigned short V_144 )
{
struct V_1 * V_2 = F_265 ( V_639 ) ;
unsigned char V_640 ;
unsigned short V_641 ;
if ( V_2 -> V_42 . V_13 )
return - V_338 ;
switch ( V_475 )
{
case V_642 : V_640 = V_510 ; break;
case V_643 : V_640 = V_478 ; break;
case V_644 : V_640 = V_479 ; break;
case V_645 : V_640 = V_480 ; break;
case V_646 : V_640 = V_481 ; break;
default: return - V_291 ;
}
switch ( V_144 )
{
case V_647 : V_641 = V_648 ; break;
case V_649 : V_641 = V_485 ; break;
case V_650 : V_641 = V_486 ; break;
default: return - V_291 ;
}
V_2 -> V_36 . V_475 = V_640 ;
V_2 -> V_36 . V_483 = V_641 ;
if ( V_2 -> V_86 )
F_91 ( V_2 ) ;
return 0 ;
}
static T_9 F_266 ( struct V_651 * V_652 ,
struct V_638 * V_639 )
{
struct V_1 * V_2 = F_265 ( V_639 ) ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( V_653 L_170 , __FILE__ , V_639 -> V_3 ) ;
F_267 ( V_639 ) ;
V_2 -> V_78 = V_652 -> V_654 ;
F_107 ( V_2 , V_652 -> V_11 , V_652 -> V_654 ) ;
V_639 -> V_605 . V_655 ++ ;
V_639 -> V_605 . V_656 += V_652 -> V_654 ;
F_268 ( V_652 ) ;
F_269 ( V_639 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! V_2 -> V_43 )
F_13 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_657 ;
}
static int F_270 ( struct V_638 * V_639 )
{
struct V_1 * V_2 = F_265 ( V_639 ) ;
int V_24 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_171 , __FILE__ , V_639 -> V_3 ) ;
V_24 = F_271 ( V_639 ) ;
if ( V_24 )
return V_24 ;
F_9 ( & V_2 -> V_337 , V_12 ) ;
if ( V_2 -> V_42 . V_13 != 0 || V_2 -> V_86 != 0 ) {
F_4 ( V_658 L_172 , V_639 -> V_3 ) ;
F_11 ( & V_2 -> V_337 , V_12 ) ;
return - V_338 ;
}
V_2 -> V_86 = 1 ;
F_11 ( & V_2 -> V_337 , V_12 ) ;
if ( ( V_24 = F_75 ( V_2 ) ) != 0 ) {
F_9 ( & V_2 -> V_337 , V_12 ) ;
V_2 -> V_86 = 0 ;
F_11 ( & V_2 -> V_337 , V_12 ) ;
return V_24 ;
}
V_2 -> V_83 |= V_84 | V_199 ;
F_91 ( V_2 ) ;
F_269 ( V_639 ) ;
F_272 ( V_639 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( V_2 -> V_83 & V_262 )
F_43 ( V_639 ) ;
else
F_44 ( V_639 ) ;
return 0 ;
}
static int F_273 ( struct V_638 * V_639 )
{
struct V_1 * V_2 = F_265 ( V_639 ) ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_173 , __FILE__ , V_639 -> V_3 ) ;
F_267 ( V_639 ) ;
F_87 ( V_2 ) ;
F_274 ( V_639 ) ;
F_9 ( & V_2 -> V_337 , V_12 ) ;
V_2 -> V_86 = 0 ;
F_11 ( & V_2 -> V_337 , V_12 ) ;
return 0 ;
}
static int F_275 ( struct V_638 * V_639 , struct V_659 * V_660 , int V_296 )
{
const T_10 V_661 = sizeof( V_662 ) ;
V_662 V_663 ;
V_662 T_4 * line = V_660 -> V_664 . V_665 . V_666 ;
struct V_1 * V_2 = F_265 ( V_639 ) ;
unsigned int V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_174 , __FILE__ , V_639 -> V_3 ) ;
if ( V_2 -> V_42 . V_13 )
return - V_338 ;
if ( V_296 != V_667 )
return F_276 ( V_639 , V_660 , V_296 ) ;
switch( V_660 -> V_664 . type ) {
case V_668 :
V_660 -> V_664 . type = V_669 ;
if ( V_660 -> V_664 . V_661 < V_661 ) {
V_660 -> V_664 . V_661 = V_661 ;
return - V_670 ;
}
V_12 = V_2 -> V_36 . V_12 & ( V_671 | V_495 |
V_496 | V_497 |
V_672 | V_498 |
V_499 | V_500 ) ;
memset ( & V_663 , 0 , sizeof( V_663 ) ) ;
switch ( V_12 ) {
case ( V_671 | V_672 ) : V_663 . V_673 = V_674 ; break;
case ( V_496 | V_499 ) : V_663 . V_673 = V_675 ; break;
case ( V_671 | V_499 ) : V_663 . V_673 = V_676 ; break;
case ( V_671 | V_500 ) : V_663 . V_673 = V_677 ; break;
default: V_663 . V_673 = V_678 ;
}
V_663 . V_679 = V_2 -> V_36 . V_508 ;
V_663 . V_572 = V_2 -> V_36 . V_572 ? 1 : 0 ;
if ( F_277 ( line , & V_663 , V_661 ) )
return - V_240 ;
return 0 ;
case V_669 :
if( ! F_81 ( V_680 ) )
return - V_681 ;
if ( F_278 ( & V_663 , line , V_661 ) )
return - V_240 ;
switch ( V_663 . V_673 )
{
case V_674 : V_12 = V_671 | V_672 ; break;
case V_677 : V_12 = V_671 | V_500 ; break;
case V_675 : V_12 = V_496 | V_499 ; break;
case V_676 : V_12 = V_671 | V_499 ; break;
case V_678 : V_12 = V_2 -> V_36 . V_12 &
( V_671 | V_495 |
V_496 | V_497 |
V_672 | V_498 |
V_499 | V_500 ) ; break;
default: return - V_291 ;
}
if ( V_663 . V_572 != 0 && V_663 . V_572 != 1 )
return - V_291 ;
V_2 -> V_36 . V_12 &= ~ ( V_671 | V_495 |
V_496 | V_497 |
V_672 | V_498 |
V_499 | V_500 ) ;
V_2 -> V_36 . V_12 |= V_12 ;
V_2 -> V_36 . V_572 = V_663 . V_572 ;
if ( V_12 & ( V_496 | V_499 ) )
V_2 -> V_36 . V_508 = V_663 . V_679 ;
else
V_2 -> V_36 . V_508 = 0 ;
if ( V_2 -> V_86 )
F_91 ( V_2 ) ;
return 0 ;
default:
return F_276 ( V_639 , V_660 , V_296 ) ;
}
}
static void F_279 ( struct V_638 * V_639 )
{
struct V_1 * V_2 = F_265 ( V_639 ) ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_175 , V_639 -> V_3 ) ;
V_639 -> V_605 . V_682 ++ ;
V_639 -> V_605 . V_683 ++ ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_10 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
F_280 ( V_639 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( F_281 ( V_2 -> V_113 ) )
F_280 ( V_2 -> V_113 ) ;
}
static void F_256 ( struct V_1 * V_2 , char * V_228 , int V_661 )
{
struct V_651 * V_652 = F_282 ( V_661 ) ;
struct V_638 * V_639 = V_2 -> V_113 ;
if ( V_19 >= V_20 )
F_4 ( L_176 , V_639 -> V_3 ) ;
if ( V_652 == NULL ) {
F_4 ( V_684 L_177 ,
V_639 -> V_3 ) ;
V_639 -> V_605 . V_685 ++ ;
return;
}
F_283 ( V_652 , V_228 , V_661 ) ;
V_652 -> V_686 = F_284 ( V_652 , V_639 ) ;
V_639 -> V_605 . V_687 ++ ;
V_639 -> V_605 . V_688 += V_661 ;
F_285 ( V_652 ) ;
}
static int F_221 ( struct V_1 * V_2 )
{
int V_24 ;
struct V_638 * V_639 ;
T_11 * V_689 ;
V_639 = F_286 ( V_2 ) ;
if ( ! V_639 ) {
F_4 ( V_180 L_178 , __FILE__ ) ;
return - V_186 ;
}
V_639 -> V_690 = V_2 -> V_135 ;
V_639 -> V_449 = V_2 -> V_175 ;
V_639 -> V_450 = V_2 -> V_346 ;
V_639 -> V_691 = & V_692 ;
V_639 -> V_693 = 10 * V_221 ;
V_639 -> V_694 = 50 ;
V_689 = F_287 ( V_639 ) ;
V_689 -> V_695 = F_264 ;
V_689 -> V_634 = F_266 ;
V_24 = F_288 ( V_639 ) ;
if ( V_24 ) {
F_4 ( V_658 L_179 , __FILE__ ) ;
F_289 ( V_639 ) ;
return V_24 ;
}
V_2 -> V_113 = V_639 ;
return 0 ;
}
static void F_236 ( struct V_1 * V_2 )
{
F_290 ( V_2 -> V_113 ) ;
F_289 ( V_2 -> V_113 ) ;
V_2 -> V_113 = NULL ;
}
static int F_291 ( struct V_696 * V_639 ,
const struct V_697 * V_698 )
{
struct V_1 * V_2 ;
if ( F_292 ( V_639 ) ) {
F_4 ( L_180 , V_639 ) ;
return - V_277 ;
}
V_2 = F_222 () ;
if ( ! V_2 ) {
F_4 ( L_145 ) ;
return - V_277 ;
}
V_2 -> V_135 = F_293 ( V_639 , 2 ) ;
V_2 -> V_175 = V_639 -> V_449 ;
V_2 -> V_344 = F_293 ( V_639 , 3 ) ;
V_2 -> V_345 = F_293 ( V_639 , 0 ) ;
V_2 -> V_414 = V_2 -> V_345 & ( V_417 - 1 ) ;
V_2 -> V_345 &= ~ ( V_417 - 1 ) ;
V_2 -> V_342 = V_343 ;
V_2 -> V_408 = 8 ;
V_2 -> V_410 = V_699 ;
if ( V_639 -> V_700 == 0x0210 ) {
V_2 -> V_564 = 0x007c4080 ;
V_2 -> V_426 = 1 ;
} else {
V_2 -> V_564 = 0x087e4546 ;
V_2 -> V_426 = 0 ;
}
F_220 ( V_2 ) ;
return 0 ;
}
static void F_294 ( struct V_696 * V_639 )
{
}
