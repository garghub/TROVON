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
if ( ! V_2 )
return;
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
if ( V_49 & ( V_60 + V_61 ) ) {
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
if ( ( V_2 -> V_42 . V_12 & V_120 ) &&
( V_49 & V_93 ) ) {
if ( V_19 >= V_51 )
F_4 ( L_17 , V_2 -> V_21 ,
( V_49 & V_110 ) ? L_18 : L_19 ) ;
if ( V_49 & V_110 )
F_28 ( & V_2 -> V_42 . V_121 ) ;
else {
if ( V_19 >= V_51 )
F_4 ( L_20 ) ;
if ( V_2 -> V_42 . V_10 )
F_45 ( V_2 -> V_42 . V_10 ) ;
}
}
if ( ( V_2 -> V_42 . V_12 & V_122 ) &&
( V_49 & V_92 ) ) {
if ( V_2 -> V_42 . V_10 -> V_88 ) {
if ( V_49 & V_116 ) {
if ( V_19 >= V_51 )
F_4 ( L_21 ) ;
if ( V_2 -> V_42 . V_10 )
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
if ( V_49 & V_123 ) {
F_27 ( V_2 , V_124 ,
( unsigned short ) ( F_25 ( V_2 , V_124 ) & ~ ( V_125 + V_126 ) ) ) ;
F_41 ( V_2 , V_123 ) ;
V_2 -> V_127 = true ;
}
}
static void F_46 ( struct V_1 * V_2 )
{
if ( V_19 >= V_51 )
F_4 ( L_23 ,
__FILE__ , __LINE__ , V_2 -> V_78 ) ;
F_30 ( V_2 , V_128 ) ;
if ( V_2 -> V_42 . V_10 -> V_87 || V_2 -> V_42 . V_10 -> V_88 ) {
F_10 ( V_2 ) ;
return;
}
if ( V_2 -> V_78 )
F_47 ( V_2 ) ;
else
V_2 -> V_43 = false ;
if ( V_2 -> V_78 < V_129 )
V_2 -> V_25 |= V_27 ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_130 ;
T_2 V_49 ;
int V_32 = 0 ;
unsigned char V_131 ;
struct V_9 * V_10 = V_2 -> V_42 . V_10 ;
struct V_89 * V_54 = & V_2 -> V_54 ;
if ( V_19 >= V_51 )
F_4 ( L_24 ,
__FILE__ , __LINE__ ) ;
F_30 ( V_2 , V_132 ) ;
F_49 ( V_2 , V_133 ) ;
F_27 ( V_2 , V_59 + V_134 , ( T_2 ) ( F_25 ( V_2 , V_59 + V_134 ) & ~ V_135 ) ) ;
while( ( V_130 = ( F_25 ( V_2 , V_59 ) >> 8 ) ) ) {
int V_136 ;
F_50 ( ( F_51 ( V_2 -> V_137 + V_138 ) & 0x0780 ) | ( V_139 + V_134 ) ,
V_2 -> V_137 + V_138 ) ;
V_131 = F_52 ( V_2 -> V_137 + V_138 ) ;
V_49 = F_25 ( V_2 , V_50 ) ;
if ( V_49 & ( V_140 + V_141 +
V_65 + V_142 ) )
F_31 ( V_2 , V_143 ) ;
V_54 -> V_144 ++ ;
V_136 = 0 ;
if ( V_49 & ( V_140 + V_141 +
V_65 + V_142 ) ) {
F_4 ( L_25 , V_49 ) ;
if ( V_49 & V_142 ) {
V_49 &= ~ ( V_140 + V_141 ) ;
V_54 -> V_145 ++ ;
} else if ( V_49 & V_141 )
V_54 -> V_146 ++ ;
else if ( V_49 & V_140 )
V_54 -> V_147 ++ ;
else if ( V_49 & V_65 ) {
F_35 ( V_2 , V_148 ) ;
V_54 -> V_149 ++ ;
}
if ( V_49 & V_2 -> V_150 )
continue;
V_49 &= V_2 -> V_151 ;
if ( V_49 & V_142 ) {
V_136 = V_152 ;
if ( V_2 -> V_42 . V_12 & V_153 )
F_53 ( V_10 ) ;
} else if ( V_49 & V_141 )
V_136 = V_154 ;
else if ( V_49 & V_140 )
V_136 = V_155 ;
}
F_54 ( V_10 , V_131 , V_136 ) ;
if ( V_49 & V_65 ) {
V_32 += F_54 ( V_10 , 0 , V_156 ) ;
}
}
if ( V_19 >= V_51 ) {
F_4 ( L_26 ,
__FILE__ , __LINE__ , V_54 -> V_144 , V_54 -> V_145 ,
V_54 -> V_146 , V_54 -> V_147 , V_54 -> V_149 ) ;
}
if( V_32 )
F_55 ( V_10 ) ;
}
static void F_56 ( struct V_1 * V_2 )
{
T_2 V_49 = F_25 ( V_2 , V_90 ) ;
if ( V_19 >= V_51 )
F_4 ( L_27 ,
__FILE__ , __LINE__ , V_49 ) ;
if ( ( V_49 & V_157 ) &&
( V_2 -> V_36 . V_37 == V_38 ) ) {
F_57 ( V_2 , V_158 ) ;
F_34 ( V_2 , V_159 ) ;
F_31 ( V_2 , V_143 ) ;
F_30 ( V_2 , V_132 + V_67 ) ;
F_58 ( V_2 , V_132 + V_67 ) ;
V_2 -> V_25 |= V_26 ;
V_2 -> V_41 = true ;
}
F_30 ( V_2 , V_160 ) ;
F_59 ( V_2 , V_49 ) ;
}
static void F_60 ( struct V_1 * V_2 )
{
}
static void F_61 ( struct V_1 * V_2 )
{
T_2 V_49 ;
F_62 ( V_2 , V_161 , V_162 + V_163 ) ;
V_49 = F_63 ( V_2 , V_164 ) ;
if ( V_19 >= V_51 )
F_4 ( L_28 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_49 ) ;
V_2 -> V_25 |= V_26 ;
if ( V_49 & V_135 ) {
V_2 -> V_165 = true ;
V_2 -> V_54 . V_166 ++ ;
}
}
static void F_64 ( struct V_1 * V_2 )
{
T_2 V_49 ;
F_62 ( V_2 , V_161 , V_167 + V_168 ) ;
V_49 = F_63 ( V_2 , V_169 ) ;
if ( V_19 >= V_51 )
F_4 ( L_29 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_49 ) ;
if ( V_49 & V_170 ) {
-- V_2 -> V_171 ;
if ( F_65 ( V_2 ) ) {
V_2 -> V_25 |= V_27 ;
}
}
}
static T_3 F_66 ( int V_172 , void * V_173 )
{
struct V_1 * V_2 = V_173 ;
T_2 V_174 ;
T_2 V_175 ;
if ( V_19 >= V_51 )
F_4 ( V_176 L_30 ,
__FILE__ , __LINE__ , V_2 -> V_177 ) ;
F_67 ( & V_2 -> V_22 ) ;
for(; ; ) {
V_174 = F_25 ( V_2 , V_178 ) >> 9 ;
V_175 = F_63 ( V_2 , V_179 ) ;
if ( V_19 >= V_51 )
F_4 ( L_31 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_174 , V_175 ) ;
if ( ! V_174 && ! V_175 )
break;
if ( V_174 )
(* F_68 [ V_174 ])( V_2 ) ;
else if ( ( V_175 & ( V_180 | V_162 ) ) == V_180 )
F_64 ( V_2 ) ;
else
F_61 ( V_2 ) ;
if ( V_2 -> V_181 ) {
F_4 ( V_182 L_32 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_177 ) ;
F_69 ( V_2 ) ;
F_70 ( V_2 , V_183 ) ;
break;
}
}
if ( V_2 -> V_25 && ! V_2 -> V_29 && ! V_2 -> V_30 ) {
if ( V_19 >= V_51 )
F_4 ( L_33 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_71 ( & V_2 -> V_33 ) ;
V_2 -> V_30 = true ;
}
F_72 ( & V_2 -> V_22 ) ;
if ( V_19 >= V_51 )
F_4 ( V_176 L_34 ,
__FILE__ , __LINE__ , V_2 -> V_177 ) ;
return V_184 ;
}
static int F_73 ( struct V_1 * V_2 )
{
int V_185 = 0 ;
if ( V_19 >= V_20 )
F_4 ( L_35 , __FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( V_2 -> V_42 . V_12 & V_186 )
return 0 ;
if ( ! V_2 -> V_187 ) {
V_2 -> V_187 = ( unsigned char * ) F_74 ( V_188 ) ;
if ( ! V_2 -> V_187 ) {
F_4 ( V_182 L_36 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return - V_189 ;
}
}
V_2 -> V_25 = 0 ;
memset ( & V_2 -> V_54 , 0 , sizeof( V_2 -> V_54 ) ) ;
F_75 ( & V_2 -> V_81 , V_190 , ( unsigned long ) V_2 ) ;
V_185 = F_76 ( V_2 ) ;
if ( ! V_185 )
V_185 = F_77 ( V_2 ) ;
if ( V_185 ) {
if ( F_78 ( V_191 ) && V_2 -> V_42 . V_10 )
F_79 ( V_192 , & V_2 -> V_42 . V_10 -> V_12 ) ;
F_80 ( V_2 ) ;
return V_185 ;
}
F_81 ( V_2 ) ;
if ( V_2 -> V_42 . V_10 )
F_82 ( V_192 , & V_2 -> V_42 . V_10 -> V_12 ) ;
V_2 -> V_42 . V_12 |= V_186 ;
return 0 ;
}
static void F_83 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
if ( ! ( V_2 -> V_42 . V_12 & V_186 ) )
return;
if ( V_19 >= V_20 )
F_4 ( L_37 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_28 ( & V_2 -> V_119 ) ;
F_28 ( & V_2 -> V_64 ) ;
F_84 ( & V_2 -> V_81 ) ;
if ( V_2 -> V_187 ) {
F_85 ( ( unsigned long ) V_2 -> V_187 ) ;
V_2 -> V_187 = NULL ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_69 ( V_2 ) ;
F_86 ( V_2 ) ;
F_10 ( V_2 ) ;
F_58 ( V_2 , V_132 + V_67 +
V_128 + V_69 + V_91 + V_160 ) ;
F_70 ( V_2 , V_183 + V_193 + V_194 ) ;
F_27 ( V_2 , V_195 , ( T_2 ) ( ( F_25 ( V_2 , V_195 ) | V_196 ) | V_197 ) ) ;
F_27 ( V_2 , V_195 , ( T_2 ) ( ( F_25 ( V_2 , V_195 ) | V_57 ) | V_198 ) ) ;
if ( ! V_2 -> V_42 . V_10 || V_2 -> V_42 . V_10 -> V_199 -> V_200 & V_201 ) {
V_2 -> V_83 &= ~ ( V_202 + V_84 ) ;
F_38 ( V_2 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
F_80 ( V_2 ) ;
if ( V_2 -> V_42 . V_10 )
F_79 ( V_192 , & V_2 -> V_42 . V_10 -> V_12 ) ;
V_2 -> V_42 . V_12 &= ~ V_186 ;
}
static void F_87 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_86 ( V_2 ) ;
F_10 ( V_2 ) ;
V_2 -> V_78 = V_2 -> V_79 = V_2 -> V_80 = 0 ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_203 ||
V_2 -> V_86 )
F_88 ( V_2 ) ;
else
F_89 ( V_2 ) ;
F_38 ( V_2 ) ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_45 = 0 ;
V_2 -> V_46 = 0 ;
F_90 ( V_2 , V_114 + V_103 + V_108 + V_97 ) ;
F_91 ( V_2 , V_91 ) ;
F_37 ( V_2 ) ;
if ( V_2 -> V_86 || V_2 -> V_42 . V_10 -> V_199 -> V_200 & V_204 )
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static void F_81 ( struct V_1 * V_2 )
{
unsigned V_205 ;
int V_206 ;
if ( ! V_2 -> V_42 . V_10 || ! V_2 -> V_42 . V_10 -> V_199 )
return;
if ( V_19 >= V_20 )
F_4 ( L_38 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
V_205 = V_2 -> V_42 . V_10 -> V_199 -> V_200 ;
if ( V_205 & V_207 )
V_2 -> V_83 |= V_84 + V_202 ;
else
V_2 -> V_83 &= ~ ( V_84 + V_202 ) ;
switch ( V_205 & V_208 ) {
case V_209 : V_2 -> V_36 . V_210 = 5 ; break;
case V_211 : V_2 -> V_36 . V_210 = 6 ; break;
case V_212 : V_2 -> V_36 . V_210 = 7 ; break;
case V_213 : V_2 -> V_36 . V_210 = 8 ; break;
default: V_2 -> V_36 . V_210 = 7 ; break;
}
if ( V_205 & V_214 )
V_2 -> V_36 . V_215 = 2 ;
else
V_2 -> V_36 . V_215 = 1 ;
V_2 -> V_36 . V_146 = V_216 ;
if ( V_205 & V_217 ) {
if ( V_205 & V_218 )
V_2 -> V_36 . V_146 = V_219 ;
else
V_2 -> V_36 . V_146 = V_220 ;
#ifdef F_92
if ( V_205 & F_92 )
V_2 -> V_36 . V_146 = V_221 ;
#endif
}
V_206 = V_2 -> V_36 . V_210 +
V_2 -> V_36 . V_215 + 1 ;
if ( V_2 -> V_36 . V_222 <= 460800 )
V_2 -> V_36 . V_222 = F_93 ( V_2 -> V_42 . V_10 ) ;
if ( V_2 -> V_36 . V_222 ) {
V_2 -> V_223 = ( 32 * V_224 * V_206 ) /
V_2 -> V_36 . V_222 ;
}
V_2 -> V_223 += V_224 / 50 ;
if ( V_205 & V_225 )
V_2 -> V_42 . V_12 |= V_122 ;
else
V_2 -> V_42 . V_12 &= ~ V_122 ;
if ( V_205 & V_226 )
V_2 -> V_42 . V_12 &= ~ V_120 ;
else
V_2 -> V_42 . V_12 |= V_120 ;
V_2 -> V_151 = V_65 ;
if ( F_94 ( V_2 -> V_42 . V_10 ) )
V_2 -> V_151 |= V_141 | V_140 ;
if ( F_95 ( V_2 -> V_42 . V_10 ) || F_96 ( V_2 -> V_42 . V_10 ) )
V_2 -> V_151 |= V_142 ;
if ( F_97 ( V_2 -> V_42 . V_10 ) )
V_2 -> V_150 |= V_141 | V_140 ;
if ( F_98 ( V_2 -> V_42 . V_10 ) ) {
V_2 -> V_150 |= V_142 ;
if ( F_97 ( V_2 -> V_42 . V_10 ) )
V_2 -> V_150 |= V_65 ;
}
F_87 ( V_2 ) ;
}
static int F_99 ( struct V_9 * V_10 , unsigned char V_227 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
int V_228 = 0 ;
if ( V_19 >= V_20 ) {
F_4 ( V_176 L_39 ,
__FILE__ , __LINE__ , V_227 , V_2 -> V_21 ) ;
}
if ( F_2 ( V_2 , V_10 -> V_3 , L_40 ) )
return 0 ;
if ( ! V_2 -> V_187 )
return 0 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ( V_2 -> V_36 . V_37 == V_229 ) || ! V_2 -> V_43 ) {
if ( V_2 -> V_78 < V_230 - 1 ) {
V_2 -> V_187 [ V_2 -> V_79 ++ ] = V_227 ;
V_2 -> V_79 &= V_230 - 1 ;
V_2 -> V_78 ++ ;
V_228 = 1 ;
}
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_228 ;
}
static void F_100 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_41 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_78 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_42 ) )
return;
if ( V_2 -> V_78 <= 0 || V_10 -> V_87 || V_10 -> V_88 ||
! V_2 -> V_187 )
return;
if ( V_19 >= V_20 )
F_4 ( L_43 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! V_2 -> V_43 ) {
if ( ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_203 ) && V_2 -> V_78 ) {
F_101 ( V_2 ,
V_2 -> V_187 , V_2 -> V_78 ) ;
}
F_13 ( V_2 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static int F_102 ( struct V_9 * V_10 ,
const unsigned char * V_231 , int V_13 )
{
int V_232 , V_228 = 0 ;
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_44 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_13 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_45 ) )
goto V_233;
if ( ! V_2 -> V_187 )
goto V_233;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_203 ) {
if ( V_2 -> V_43 ) {
if ( V_2 -> V_36 . V_37 == V_38 ) {
V_228 = 0 ;
goto V_233;
}
if ( V_2 -> V_234 >= V_2 -> V_235 ) {
V_228 = 0 ;
goto V_233;
}
V_228 = V_13 ;
F_103 ( V_2 , V_231 , V_13 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_65 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
goto V_233;
}
if ( ( V_2 -> V_36 . V_12 & V_236 ) &&
! F_26 ( V_2 ) )
{
V_228 = 0 ;
goto V_233;
}
if ( V_2 -> V_78 ) {
V_228 = 0 ;
F_101 ( V_2 ,
V_2 -> V_187 , V_2 -> V_78 ) ;
if ( V_19 >= V_20 )
F_4 ( L_46 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
} else {
if ( V_19 >= V_20 )
F_4 ( L_47 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
V_228 = V_13 ;
V_2 -> V_78 = V_13 ;
F_101 ( V_2 , V_231 , V_13 ) ;
}
} else {
while ( 1 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_232 = F_104 ( int , V_13 ,
F_105 ( V_230 - V_2 -> V_78 - 1 ,
V_230 - V_2 -> V_79 ) ) ;
if ( V_232 <= 0 ) {
F_11 ( & V_2 -> V_22 , V_12 ) ;
break;
}
memcpy ( V_2 -> V_187 + V_2 -> V_79 , V_231 , V_232 ) ;
V_2 -> V_79 = ( ( V_2 -> V_79 + V_232 ) &
( V_230 - 1 ) ) ;
V_2 -> V_78 += V_232 ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_231 += V_232 ;
V_13 -= V_232 ;
V_228 += V_232 ;
}
}
if ( V_2 -> V_78 && ! V_10 -> V_87 && ! V_10 -> V_88 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! V_2 -> V_43 )
F_13 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
V_233:
if ( V_19 >= V_20 )
F_4 ( L_48 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_228 ) ;
return V_228 ;
}
static int F_106 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
int V_228 ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_49 ) )
return 0 ;
V_228 = V_230 - V_2 -> V_78 - 1 ;
if ( V_228 < 0 )
V_228 = 0 ;
if ( V_19 >= V_20 )
F_4 ( L_50 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_228 ) ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_203 ) {
if ( V_2 -> V_43 )
return 0 ;
else
return V_237 ;
}
return V_228 ;
}
static int F_107 ( struct V_9 * V_10 )
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
V_2 -> V_36 . V_37 == V_203 ) {
if ( V_2 -> V_43 )
return V_2 -> V_238 ;
else
return 0 ;
}
return V_2 -> V_78 ;
}
static void F_108 ( struct V_9 * V_10 )
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
static void F_109 ( struct V_9 * V_10 , char V_227 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_56 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_227 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_57 ) )
return;
V_2 -> V_239 = V_227 ;
if ( V_227 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! V_2 -> V_23 )
F_13 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
static void F_110 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_58 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_59 ) )
return;
if ( F_111 ( V_10 ) )
F_109 ( V_10 , F_112 ( V_10 ) ) ;
if ( V_10 -> V_199 -> V_200 & V_225 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_83 &= ~ V_84 ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
static void F_113 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_60 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_61 ) )
return;
if ( F_111 ( V_10 ) ) {
if ( V_2 -> V_239 )
V_2 -> V_239 = 0 ;
else
F_109 ( V_10 , F_114 ( V_10 ) ) ;
}
if ( V_10 -> V_199 -> V_200 & V_225 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_83 |= V_84 ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
static int F_115 ( struct V_1 * V_2 , struct V_89 T_4 * V_240 )
{
int V_241 ;
if ( V_19 >= V_20 )
F_4 ( L_62 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( ! V_240 ) {
memset ( & V_2 -> V_54 , 0 , sizeof( V_2 -> V_54 ) ) ;
} else {
F_116 ( & V_2 -> V_42 . V_242 ) ;
F_117 ( V_241 , V_240 , & V_2 -> V_54 , sizeof( struct V_89 ) ) ;
F_118 ( & V_2 -> V_42 . V_242 ) ;
if ( V_241 )
return - V_243 ;
}
return 0 ;
}
static int F_119 ( struct V_1 * V_2 , T_5 T_4 * V_244 )
{
int V_241 ;
if ( V_19 >= V_20 )
F_4 ( L_62 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_116 ( & V_2 -> V_42 . V_242 ) ;
F_117 ( V_241 , V_244 , & V_2 -> V_36 , sizeof( T_5 ) ) ;
F_118 ( & V_2 -> V_42 . V_242 ) ;
if ( V_241 ) {
if ( V_19 >= V_20 )
F_4 ( L_63 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return - V_243 ;
}
return 0 ;
}
static int F_120 ( struct V_1 * V_2 , T_5 T_4 * V_245 )
{
unsigned long V_12 ;
T_5 V_246 ;
int V_241 ;
if ( V_19 >= V_20 )
F_4 ( L_64 , __FILE__ , __LINE__ ,
V_2 -> V_21 ) ;
F_121 ( V_241 , & V_246 , V_245 , sizeof( T_5 ) ) ;
if ( V_241 ) {
if ( V_19 >= V_20 )
F_4 ( L_65 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return - V_243 ;
}
F_116 ( & V_2 -> V_42 . V_242 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
memcpy ( & V_2 -> V_36 , & V_246 , sizeof( T_5 ) ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
F_81 ( V_2 ) ;
F_118 ( & V_2 -> V_42 . V_242 ) ;
return 0 ;
}
static int F_122 ( struct V_1 * V_2 , int T_4 * V_247 )
{
int V_241 ;
if ( V_19 >= V_20 )
F_4 ( L_66 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_247 ) ;
F_117 ( V_241 , V_247 , & V_2 -> V_247 , sizeof( int ) ) ;
if ( V_241 ) {
if ( V_19 >= V_20 )
F_4 ( L_67 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return - V_243 ;
}
return 0 ;
}
static int F_123 ( struct V_1 * V_2 , int V_247 )
{
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_68 , __FILE__ , __LINE__ ,
V_2 -> V_21 , V_247 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_247 = V_247 ;
F_124 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_125 ( struct V_1 * V_2 , int V_248 )
{
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_69 , __FILE__ , __LINE__ ,
V_2 -> V_21 , V_248 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_248 ) {
if ( ! V_2 -> V_23 ) {
F_13 ( V_2 ) ;
if ( V_2 -> V_36 . V_12 & V_236 )
F_126 ( V_2 ) ;
}
} else {
if ( V_2 -> V_23 )
F_10 ( V_2 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_70 , __FILE__ , __LINE__ ,
V_2 -> V_21 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_2 -> V_43 && V_2 -> V_36 . V_37 == V_38 )
{
if ( V_2 -> V_36 . V_12 & V_236 )
F_128 ( V_2 ) ;
else
F_129 ( V_2 , V_249 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_130 ( struct V_1 * V_2 , int V_248 )
{
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_71 , __FILE__ , __LINE__ ,
V_2 -> V_21 , V_248 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_248 ) {
if ( ! V_2 -> V_250 )
F_21 ( V_2 ) ;
} else {
if ( V_2 -> V_250 )
F_86 ( V_2 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 , int T_4 * V_251 )
{
unsigned long V_12 ;
int V_252 ;
int V_24 = 0 ;
struct V_89 V_253 , V_254 ;
int V_255 ;
int V_256 ;
struct V_257 V_258 , V_259 ;
F_132 ( V_260 , V_261 ) ;
F_121 ( V_24 , & V_256 , V_251 , sizeof( int ) ) ;
if ( V_24 ) {
return - V_243 ;
}
if ( V_19 >= V_20 )
F_4 ( L_72 , __FILE__ , __LINE__ ,
V_2 -> V_21 , V_256 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
V_252 = V_2 -> V_83 ;
V_255 = V_256 &
( ( ( V_252 & V_262 ) ? V_263 : V_264 ) +
( ( V_252 & V_265 ) ? V_266 : V_267 ) +
( ( V_252 & V_268 ) ? V_269 : V_270 ) +
( ( V_252 & V_271 ) ? V_272 : V_273 ) ) ;
if ( V_255 ) {
F_11 ( & V_2 -> V_22 , V_12 ) ;
goto exit;
}
V_253 = V_2 -> V_54 ;
V_258 = V_2 -> V_100 ;
if ( V_256 & ( V_274 + V_275 ) ) {
T_2 V_276 = F_25 ( V_2 , V_59 ) ;
T_2 V_277 = V_276 +
( V_256 & V_274 ? V_60 : 0 ) +
( V_256 & V_275 ? V_61 : 0 ) ;
if ( V_276 != V_277 )
F_27 ( V_2 , V_59 , V_277 ) ;
}
F_133 ( V_278 ) ;
F_134 ( & V_2 -> V_64 , & V_260 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
for(; ; ) {
F_135 () ;
if ( F_136 ( V_261 ) ) {
V_24 = - V_279 ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_254 = V_2 -> V_54 ;
V_259 = V_2 -> V_100 ;
F_133 ( V_278 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( V_259 . V_106 == V_258 . V_106 &&
V_259 . V_107 == V_258 . V_107 &&
V_259 . V_111 == V_258 . V_111 &&
V_259 . V_112 == V_258 . V_112 &&
V_259 . V_117 == V_258 . V_117 &&
V_259 . V_118 == V_258 . V_118 &&
V_259 . V_101 == V_258 . V_101 &&
V_259 . V_102 == V_258 . V_102 &&
V_254 . V_62 == V_253 . V_62 &&
V_254 . V_63 == V_253 . V_63 ) {
V_24 = - V_280 ;
break;
}
V_255 = V_256 &
( ( V_259 . V_106 != V_258 . V_106 ? V_263 : 0 ) +
( V_259 . V_107 != V_258 . V_107 ? V_264 : 0 ) +
( V_259 . V_111 != V_258 . V_111 ? V_266 : 0 ) +
( V_259 . V_112 != V_258 . V_112 ? V_267 : 0 ) +
( V_259 . V_117 != V_258 . V_117 ? V_269 : 0 ) +
( V_259 . V_118 != V_258 . V_118 ? V_270 : 0 ) +
( V_259 . V_101 != V_258 . V_101 ? V_272 : 0 ) +
( V_259 . V_102 != V_258 . V_102 ? V_273 : 0 ) +
( V_254 . V_62 != V_253 . V_62 ? V_274 : 0 ) +
( V_254 . V_63 != V_253 . V_63 ? V_275 : 0 ) ) ;
if ( V_255 )
break;
V_253 = V_254 ;
V_258 = V_259 ;
}
F_137 ( & V_2 -> V_64 , & V_260 ) ;
F_133 ( V_281 ) ;
if ( V_256 & ( V_274 + V_275 ) ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! F_138 ( & V_2 -> V_64 ) ) {
F_27 ( V_2 , V_59 , F_25 ( V_2 , V_59 ) &
~ ( V_60 + V_61 ) ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
exit:
if ( V_24 == 0 )
F_139 ( V_24 , V_255 , V_251 ) ;
return V_24 ;
}
static int F_140 ( struct V_1 * V_2 , int V_282 )
{
unsigned long V_12 ;
int V_24 ;
struct V_89 V_253 , V_254 ;
F_132 ( V_260 , V_261 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_253 = V_2 -> V_54 ;
F_134 ( & V_2 -> V_119 , & V_260 ) ;
F_133 ( V_278 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
for(; ; ) {
F_135 () ;
if ( F_136 ( V_261 ) ) {
V_24 = - V_279 ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_254 = V_2 -> V_54 ;
F_133 ( V_278 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( V_254 . V_98 == V_253 . V_98 && V_254 . V_104 == V_253 . V_104 &&
V_254 . V_109 == V_253 . V_109 && V_254 . V_115 == V_253 . V_115 ) {
V_24 = - V_280 ;
break;
}
if ( ( V_282 & V_283 && V_254 . V_98 != V_253 . V_98 ) ||
( V_282 & V_284 && V_254 . V_104 != V_253 . V_104 ) ||
( V_282 & V_285 && V_254 . V_109 != V_253 . V_109 ) ||
( V_282 & V_286 && V_254 . V_115 != V_253 . V_115 ) ) {
V_24 = 0 ;
break;
}
V_253 = V_254 ;
}
F_137 ( & V_2 -> V_119 , & V_260 ) ;
F_133 ( V_281 ) ;
return V_24 ;
}
static int F_141 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned int V_287 ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_287 = ( ( V_2 -> V_83 & V_84 ) ? V_288 : 0 ) +
( ( V_2 -> V_83 & V_202 ) ? V_289 : 0 ) +
( ( V_2 -> V_83 & V_265 ) ? V_290 : 0 ) +
( ( V_2 -> V_83 & V_271 ) ? V_283 : 0 ) +
( ( V_2 -> V_83 & V_262 ) ? V_284 : 0 ) +
( ( V_2 -> V_83 & V_268 ) ? V_286 : 0 ) ;
if ( V_19 >= V_20 )
F_4 ( L_73 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_287 ) ;
return V_287 ;
}
static int F_142 ( struct V_9 * V_10 ,
unsigned int V_291 , unsigned int V_292 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_74 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_291 , V_292 ) ;
if ( V_291 & V_288 )
V_2 -> V_83 |= V_84 ;
if ( V_291 & V_289 )
V_2 -> V_83 |= V_202 ;
if ( V_292 & V_288 )
V_2 -> V_83 &= ~ V_84 ;
if ( V_292 & V_289 )
V_2 -> V_83 &= ~ V_202 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_143 ( struct V_9 * V_10 , int V_293 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_75 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_293 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_76 ) )
return - V_294 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_293 == - 1 )
F_27 ( V_2 , V_295 , ( T_2 ) ( F_25 ( V_2 , V_295 ) | V_296 ) ) ;
else
F_27 ( V_2 , V_295 , ( T_2 ) ( F_25 ( V_2 , V_295 ) & ~ V_296 ) ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_144 ( struct V_9 * V_10 ,
struct V_297 * V_54 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
struct V_89 V_254 ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_254 = V_2 -> V_54 ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_54 -> V_115 = V_254 . V_115 ;
V_54 -> V_104 = V_254 . V_104 ;
V_54 -> V_98 = V_254 . V_98 ;
V_54 -> V_109 = V_254 . V_109 ;
V_54 -> V_144 = V_254 . V_144 ;
V_54 -> V_298 = V_254 . V_298 ;
V_54 -> V_147 = V_254 . V_147 ;
V_54 -> V_149 = V_254 . V_149 ;
V_54 -> V_146 = V_254 . V_146 ;
V_54 -> V_145 = V_254 . V_145 ;
V_54 -> V_166 = V_254 . V_166 ;
return 0 ;
}
static int F_145 ( struct V_9 * V_10 ,
unsigned int V_299 , unsigned long V_282 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
if ( V_19 >= V_20 )
F_4 ( L_77 , __FILE__ , __LINE__ ,
V_2 -> V_21 , V_299 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_78 ) )
return - V_300 ;
if ( ( V_299 != V_301 ) && ( V_299 != V_302 ) &&
( V_299 != V_303 ) ) {
if ( V_10 -> V_12 & ( 1 << V_192 ) )
return - V_280 ;
}
return F_146 ( V_2 , V_299 , V_282 ) ;
}
static int F_146 ( struct V_1 * V_2 , unsigned int V_299 , unsigned long V_282 )
{
void T_4 * V_304 = ( void T_4 * ) V_282 ;
switch ( V_299 ) {
case V_305 :
return F_119 ( V_2 , V_304 ) ;
case V_306 :
return F_120 ( V_2 , V_304 ) ;
case V_307 :
return F_122 ( V_2 , V_304 ) ;
case V_308 :
return F_123 ( V_2 , ( int ) V_282 ) ;
case V_309 :
return F_125 ( V_2 , ( int ) V_282 ) ;
case V_310 :
return F_130 ( V_2 , ( int ) V_282 ) ;
case V_311 :
return F_127 ( V_2 ) ;
case V_312 :
return F_115 ( V_2 , V_304 ) ;
case V_313 :
return F_131 ( V_2 , V_304 ) ;
case V_314 :
return F_147 ( V_2 ) ;
case V_303 :
return F_140 ( V_2 , ( int ) V_282 ) ;
default:
return - V_315 ;
}
return 0 ;
}
static void F_148 ( struct V_9 * V_10 , struct V_316 * V_317 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_79 , __FILE__ , __LINE__ ,
V_10 -> V_318 -> V_3 ) ;
F_81 ( V_2 ) ;
if ( V_317 -> V_200 & V_207 &&
! ( V_10 -> V_199 -> V_200 & V_207 ) ) {
V_2 -> V_83 &= ~ ( V_84 + V_202 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
if ( ! ( V_317 -> V_200 & V_207 ) &&
V_10 -> V_199 -> V_200 & V_207 ) {
V_2 -> V_83 |= V_202 ;
if ( ! ( V_10 -> V_199 -> V_200 & V_225 ) ||
! F_149 ( V_319 , & V_10 -> V_12 ) ) {
V_2 -> V_83 |= V_84 ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
if ( V_317 -> V_200 & V_225 &&
! ( V_10 -> V_199 -> V_200 & V_225 ) ) {
V_10 -> V_88 = 0 ;
F_12 ( V_10 ) ;
}
}
static void F_150 ( struct V_9 * V_10 , struct V_320 * V_321 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_80 ) )
return;
if ( V_19 >= V_20 )
F_4 ( L_81 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_42 . V_13 ) ;
if ( F_151 ( & V_2 -> V_42 , V_10 , V_321 ) == 0 )
goto V_233;
F_116 ( & V_2 -> V_42 . V_242 ) ;
if ( V_2 -> V_42 . V_12 & V_186 )
F_152 ( V_10 , V_2 -> V_223 ) ;
F_108 ( V_10 ) ;
F_153 ( V_10 ) ;
F_83 ( V_2 ) ;
F_118 ( & V_2 -> V_42 . V_242 ) ;
F_154 ( & V_2 -> V_42 , V_10 ) ;
V_2 -> V_42 . V_10 = NULL ;
V_233:
if ( V_19 >= V_20 )
F_4 ( L_82 , __FILE__ , __LINE__ ,
V_10 -> V_318 -> V_3 , V_2 -> V_42 . V_13 ) ;
}
static void F_152 ( struct V_9 * V_10 , int V_223 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_322 , V_323 ;
if ( ! V_2 )
return;
if ( V_19 >= V_20 )
F_4 ( L_83 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_84 ) )
return;
if ( ! ( V_2 -> V_42 . V_12 & V_186 ) )
goto exit;
V_322 = V_324 ;
if ( V_2 -> V_36 . V_222 ) {
V_323 = V_2 -> V_223 / ( 32 * 5 ) ;
if ( ! V_323 )
V_323 ++ ;
} else
V_323 = 1 ;
if ( V_223 )
V_323 = F_104 (unsigned long, char_time, timeout) ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_203 ) {
while ( V_2 -> V_43 ) {
F_155 ( F_156 ( V_323 ) ) ;
if ( F_136 ( V_261 ) )
break;
if ( V_223 && F_157 ( V_324 , V_322 + V_223 ) )
break;
}
} else {
while ( ! ( F_25 ( V_2 , V_68 ) & V_325 ) &&
V_2 -> V_23 ) {
F_155 ( F_156 ( V_323 ) ) ;
if ( F_136 ( V_261 ) )
break;
if ( V_223 && F_157 ( V_324 , V_322 + V_223 ) )
break;
}
}
exit:
if ( V_19 >= V_20 )
F_4 ( L_85 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
}
static void F_158 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
if ( V_19 >= V_20 )
F_4 ( L_86 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_87 ) )
return;
F_108 ( V_10 ) ;
F_83 ( V_2 ) ;
V_2 -> V_42 . V_13 = 0 ;
V_2 -> V_42 . V_12 &= ~ V_326 ;
V_2 -> V_42 . V_10 = NULL ;
F_28 ( & V_2 -> V_42 . V_121 ) ;
}
static int F_159 ( struct V_327 * V_42 )
{
unsigned long V_12 ;
struct V_1 * V_2 = F_16 ( V_42 , struct V_1 , V_42 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return ( V_2 -> V_83 & V_265 ) ? 1 : 0 ;
}
static void F_160 ( struct V_327 * V_42 , int V_328 )
{
struct V_1 * V_2 = F_16 ( V_42 , struct V_1 , V_42 ) ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_328 )
V_2 -> V_83 |= V_84 + V_202 ;
else
V_2 -> V_83 &= ~ ( V_84 + V_202 ) ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static int F_161 ( struct V_9 * V_10 , struct V_320 * V_321 ,
struct V_1 * V_2 )
{
F_132 ( V_260 , V_261 ) ;
int V_185 ;
bool V_329 = false ;
bool V_330 = false ;
unsigned long V_12 ;
int V_109 ;
struct V_327 * V_42 = & V_2 -> V_42 ;
if ( V_19 >= V_20 )
F_4 ( L_88 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_3 ) ;
if ( V_321 -> V_331 & V_332 || V_10 -> V_12 & ( 1 << V_192 ) ) {
V_42 -> V_12 |= V_326 ;
return 0 ;
}
if ( V_10 -> V_199 -> V_200 & V_226 )
V_329 = true ;
V_185 = 0 ;
F_134 ( & V_42 -> V_121 , & V_260 ) ;
if ( V_19 >= V_20 )
F_4 ( L_89 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_3 , V_42 -> V_13 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! F_162 ( V_321 ) ) {
V_330 = true ;
V_42 -> V_13 -- ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_42 -> V_333 ++ ;
while ( 1 ) {
if ( V_10 -> V_199 -> V_200 & V_207 )
F_163 ( V_42 ) ;
F_133 ( V_278 ) ;
if ( F_162 ( V_321 ) || ! ( V_42 -> V_12 & V_186 ) ) {
V_185 = ( V_42 -> V_12 & V_334 ) ?
- V_335 : - V_279 ;
break;
}
V_109 = F_164 ( & V_2 -> V_42 ) ;
if ( ! ( V_42 -> V_12 & V_336 ) && ( V_329 || V_109 ) )
break;
if ( F_136 ( V_261 ) ) {
V_185 = - V_279 ;
break;
}
if ( V_19 >= V_20 )
F_4 ( L_90 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_3 , V_42 -> V_13 ) ;
F_165 () ;
F_135 () ;
F_166 () ;
}
F_133 ( V_281 ) ;
F_137 ( & V_42 -> V_121 , & V_260 ) ;
if ( V_330 )
V_42 -> V_13 ++ ;
V_42 -> V_333 -- ;
if ( V_19 >= V_20 )
F_4 ( L_91 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_3 , V_42 -> V_13 ) ;
if ( ! V_185 )
V_42 -> V_12 |= V_326 ;
return V_185 ;
}
static int F_167 ( struct V_9 * V_10 , struct V_320 * V_321 )
{
struct V_1 * V_2 ;
int V_185 , line ;
unsigned long V_12 ;
line = V_10 -> V_337 ;
if ( ( line < 0 ) || ( line >= V_338 ) ) {
F_4 ( L_92 ,
__FILE__ , __LINE__ , line ) ;
return - V_300 ;
}
V_2 = V_339 ;
while( V_2 && V_2 -> line != line )
V_2 = V_2 -> V_340 ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_93 ) )
return - V_300 ;
V_10 -> V_18 = V_2 ;
V_2 -> V_42 . V_10 = V_10 ;
if ( V_19 >= V_20 )
F_4 ( L_94 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_3 , V_2 -> V_42 . V_13 ) ;
if ( F_162 ( V_321 ) || V_2 -> V_42 . V_12 & V_336 ) {
if ( V_2 -> V_42 . V_12 & V_336 )
F_168 ( & V_2 -> V_42 . V_341 ) ;
V_185 = ( ( V_2 -> V_42 . V_12 & V_334 ) ?
- V_335 : - V_279 ) ;
goto V_233;
}
V_2 -> V_42 . V_10 -> V_342 = ( V_2 -> V_42 . V_12 & V_343 ) ? 1 : 0 ;
F_9 ( & V_2 -> V_344 , V_12 ) ;
if ( V_2 -> V_86 ) {
V_185 = - V_345 ;
F_11 ( & V_2 -> V_344 , V_12 ) ;
goto V_233;
}
V_2 -> V_42 . V_13 ++ ;
F_11 ( & V_2 -> V_344 , V_12 ) ;
if ( V_2 -> V_42 . V_13 == 1 ) {
V_185 = F_73 ( V_2 ) ;
if ( V_185 < 0 )
goto V_233;
}
V_185 = F_161 ( V_10 , V_321 , V_2 ) ;
if ( V_185 ) {
if ( V_19 >= V_20 )
F_4 ( L_95 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_185 ) ;
goto V_233;
}
if ( V_19 >= V_20 )
F_4 ( L_96 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
V_185 = 0 ;
V_233:
if ( V_185 ) {
if ( V_10 -> V_13 == 1 )
V_2 -> V_42 . V_10 = NULL ;
if( V_2 -> V_42 . V_13 )
V_2 -> V_42 . V_13 -- ;
}
return V_185 ;
}
static inline void F_169 ( struct V_346 * V_347 , struct V_1 * V_2 )
{
char V_348 [ 30 ] ;
unsigned long V_12 ;
if ( V_2 -> V_349 == V_350 ) {
F_170 ( V_347 , L_97 ,
V_2 -> V_21 , V_2 -> V_137 , V_2 -> V_177 ,
V_2 -> V_351 , V_2 -> V_352 ) ;
} else {
F_170 ( V_347 , L_98 ,
V_2 -> V_21 , V_2 -> V_137 ,
V_2 -> V_177 , V_2 -> V_353 ) ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_348 [ 0 ] = 0 ;
V_348 [ 1 ] = 0 ;
if ( V_2 -> V_83 & V_84 )
strcat ( V_348 , L_99 ) ;
if ( V_2 -> V_83 & V_268 )
strcat ( V_348 , L_100 ) ;
if ( V_2 -> V_83 & V_202 )
strcat ( V_348 , L_101 ) ;
if ( V_2 -> V_83 & V_262 )
strcat ( V_348 , L_102 ) ;
if ( V_2 -> V_83 & V_265 )
strcat ( V_348 , L_103 ) ;
if ( V_2 -> V_83 & V_271 )
strcat ( V_348 , L_104 ) ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_203 ) {
F_170 ( V_347 , L_105 ,
V_2 -> V_54 . V_75 , V_2 -> V_54 . V_354 ) ;
if ( V_2 -> V_54 . V_76 )
F_170 ( V_347 , L_106 , V_2 -> V_54 . V_76 ) ;
if ( V_2 -> V_54 . V_77 )
F_170 ( V_347 , L_107 , V_2 -> V_54 . V_77 ) ;
if ( V_2 -> V_54 . V_355 )
F_170 ( V_347 , L_108 , V_2 -> V_54 . V_355 ) ;
if ( V_2 -> V_54 . V_356 )
F_170 ( V_347 , L_109 , V_2 -> V_54 . V_356 ) ;
if ( V_2 -> V_54 . V_66 )
F_170 ( V_347 , L_110 , V_2 -> V_54 . V_66 ) ;
if ( V_2 -> V_54 . V_357 )
F_170 ( V_347 , L_111 , V_2 -> V_54 . V_357 ) ;
} else {
F_170 ( V_347 , L_112 ,
V_2 -> V_54 . V_298 , V_2 -> V_54 . V_144 ) ;
if ( V_2 -> V_54 . V_147 )
F_170 ( V_347 , L_113 , V_2 -> V_54 . V_147 ) ;
if ( V_2 -> V_54 . V_146 )
F_170 ( V_347 , L_114 , V_2 -> V_54 . V_146 ) ;
if ( V_2 -> V_54 . V_145 )
F_170 ( V_347 , L_115 , V_2 -> V_54 . V_145 ) ;
if ( V_2 -> V_54 . V_149 )
F_170 ( V_347 , L_116 , V_2 -> V_54 . V_149 ) ;
}
F_170 ( V_347 , L_117 , V_348 + 1 ) ;
F_170 ( V_347 , L_118 ,
V_2 -> V_43 , V_2 -> V_30 , V_2 -> V_29 ,
V_2 -> V_25 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
{
T_2 V_358 = F_25 ( V_2 , V_68 ) ;
T_2 V_359 = F_63 ( V_2 , V_169 ) ;
T_2 V_360 = F_25 ( V_2 , V_361 ) ;
T_2 V_362 = F_25 ( V_2 , V_50 ) ;
T_2 V_363 = F_63 ( V_2 , V_164 ) ;
T_2 V_364 = F_25 ( V_2 , V_59 ) ;
T_2 V_365 = F_25 ( V_2 , V_366 ) ;
T_2 V_367 = F_25 ( V_2 , V_368 ) ;
T_2 V_369 = F_25 ( V_2 , V_370 ) ;
T_2 V_371 = F_25 ( V_2 , V_372 ) ;
T_2 V_373 = F_51 ( V_2 -> V_137 + V_138 ) ;
F_170 ( V_347 , L_119
L_120 ,
V_358 , V_359 , V_360 , V_362 , V_363 , V_364 , V_365 , V_367 , V_369 , V_371 , V_373 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static int F_171 ( struct V_346 * V_347 , void * V_374 )
{
struct V_1 * V_2 ;
F_170 ( V_347 , L_121 , V_375 ) ;
V_2 = V_339 ;
while( V_2 ) {
F_169 ( V_347 , V_2 ) ;
V_2 = V_2 -> V_340 ;
}
return 0 ;
}
static int F_172 ( struct V_376 * V_376 , struct V_320 * V_320 )
{
return F_173 ( V_320 , F_171 , NULL ) ;
}
static int F_174 ( struct V_1 * V_2 )
{
unsigned short V_377 ;
V_2 -> V_378 = 0 ;
V_377 = ( unsigned short ) ( V_2 -> V_238 / V_379 ) ;
if ( V_2 -> V_238 % V_379 )
V_377 ++ ;
if ( V_2 -> V_349 == V_350 ) {
V_2 -> V_380 = V_2 -> V_381 * V_377 ;
V_2 -> V_382 = 62 - V_2 -> V_380 ;
} else {
V_2 -> V_380 = V_2 -> V_381 * V_377 ;
V_2 -> V_382 = ( V_377 * V_383 ) + 6 ;
if ( ( V_2 -> V_380 + V_2 -> V_382 ) > 62 )
V_2 -> V_382 = 62 - V_2 -> V_380 ;
}
if ( V_19 >= V_20 )
F_4 ( L_122 ,
__FILE__ , __LINE__ , V_2 -> V_380 , V_2 -> V_382 ) ;
if ( F_175 ( V_2 ) < 0 ||
F_176 ( V_2 , V_2 -> V_384 , V_2 -> V_382 ) < 0 ||
F_176 ( V_2 , V_2 -> V_385 , V_2 -> V_380 ) < 0 ||
F_177 ( V_2 ) < 0 ||
F_178 ( V_2 ) < 0 ) {
F_4 ( L_123 , __FILE__ , __LINE__ ) ;
return - V_189 ;
}
F_179 ( V_2 ) ;
F_180 ( V_2 ) ;
return 0 ;
}
static int F_175 ( struct V_1 * V_2 )
{
unsigned int V_386 ;
if ( V_2 -> V_349 == V_350 ) {
V_2 -> V_387 = V_2 -> V_388 + V_2 -> V_378 ;
V_2 -> V_389 = V_2 -> V_378 ;
V_2 -> V_378 += V_390 ;
} else {
V_2 -> V_387 = F_181 ( NULL , V_390 , & V_2 -> V_391 , V_188 ) ;
if ( V_2 -> V_387 == NULL )
return - V_189 ;
V_2 -> V_389 = ( V_392 ) ( V_2 -> V_391 ) ;
}
memset ( V_2 -> V_387 , 0 , V_390 ) ;
V_2 -> V_384 = ( V_393 * ) V_2 -> V_387 ;
V_2 -> V_385 = ( V_393 * ) V_2 -> V_387 ;
V_2 -> V_385 += V_2 -> V_382 ;
for ( V_386 = 0 ; V_386 < V_2 -> V_382 ; V_386 ++ ) {
V_2 -> V_384 [ V_386 ] . V_394 =
V_2 -> V_389 + ( V_386 * sizeof( V_393 ) ) ;
V_2 -> V_384 [ V_386 ] . V_395 = V_2 -> V_389 ;
if ( V_386 < V_2 -> V_382 - 1 )
V_2 -> V_384 [ V_386 ] . V_395 += ( V_386 + 1 ) * sizeof( V_393 ) ;
}
for ( V_386 = 0 ; V_386 < V_2 -> V_380 ; V_386 ++ ) {
V_2 -> V_385 [ V_386 ] . V_394 = V_2 -> V_389 +
( ( V_2 -> V_382 + V_386 ) * sizeof( V_393 ) ) ;
V_2 -> V_385 [ V_386 ] . V_395 = V_2 -> V_389 +
V_2 -> V_382 * sizeof( V_393 ) ;
if ( V_386 < V_2 -> V_380 - 1 )
V_2 -> V_385 [ V_386 ] . V_395 += ( V_386 + 1 ) * sizeof( V_393 ) ;
}
return 0 ;
}
static void F_182 ( struct V_1 * V_2 )
{
if ( V_2 -> V_387 && V_2 -> V_349 != V_350 )
F_183 ( NULL , V_390 , V_2 -> V_387 , V_2 -> V_391 ) ;
V_2 -> V_387 = NULL ;
V_2 -> V_384 = NULL ;
V_2 -> V_385 = NULL ;
}
static int F_176 ( struct V_1 * V_2 , V_393 * V_396 , int V_397 )
{
int V_386 ;
V_392 V_398 ;
for ( V_386 = 0 ; V_386 < V_397 ; V_386 ++ ) {
if ( V_2 -> V_349 == V_350 ) {
V_396 [ V_386 ] . V_399 = V_2 -> V_388 + V_2 -> V_378 ;
V_398 = V_2 -> V_378 ;
V_2 -> V_378 += V_379 ;
} else {
V_396 [ V_386 ] . V_399 = F_181 ( NULL , V_379 , & V_396 [ V_386 ] . V_400 , V_188 ) ;
if ( V_396 [ V_386 ] . V_399 == NULL )
return - V_189 ;
V_398 = ( V_392 ) ( V_396 [ V_386 ] . V_400 ) ;
}
V_396 [ V_386 ] . V_398 = V_398 ;
}
return 0 ;
}
static void F_184 ( struct V_1 * V_2 , V_393 * V_396 , int V_397 )
{
int V_386 ;
if ( V_396 ) {
for ( V_386 = 0 ; V_386 < V_397 ; V_386 ++ ) {
if ( V_396 [ V_386 ] . V_399 ) {
if ( V_2 -> V_349 != V_350 )
F_183 ( NULL , V_379 , V_396 [ V_386 ] . V_399 , V_396 [ V_386 ] . V_400 ) ;
V_396 [ V_386 ] . V_399 = NULL ;
}
}
}
}
static void F_185 ( struct V_1 * V_2 )
{
F_184 ( V_2 , V_2 -> V_384 , V_2 -> V_382 ) ;
F_184 ( V_2 , V_2 -> V_385 , V_2 -> V_380 ) ;
F_182 ( V_2 ) ;
}
static int F_177 ( struct V_1 * V_2 )
{
V_2 -> V_401 = F_186 ( V_2 -> V_238 , V_188 | V_402 ) ;
if ( V_2 -> V_401 == NULL )
return - V_189 ;
return 0 ;
}
static void F_187 ( struct V_1 * V_2 )
{
F_188 ( V_2 -> V_401 ) ;
V_2 -> V_401 = NULL ;
}
static int F_178 ( struct V_1 * V_2 )
{
int V_386 ;
if ( V_19 >= V_20 )
F_4 ( L_124 ,
V_2 -> V_21 , __FILE__ , __LINE__ , V_2 -> V_235 ) ;
memset ( V_2 -> V_403 , 0 , sizeof( V_2 -> V_403 ) ) ;
for ( V_386 = 0 ; V_386 < V_2 -> V_235 ; ++ V_386 ) {
V_2 -> V_403 [ V_386 ] . V_404 =
F_186 ( V_2 -> V_238 , V_188 ) ;
if ( V_2 -> V_403 [ V_386 ] . V_404 == NULL ) {
for ( -- V_386 ; V_386 >= 0 ; V_386 -- ) {
F_188 ( V_2 -> V_403 [ V_386 ] . V_404 ) ;
V_2 -> V_403 [ V_386 ] . V_404 = NULL ;
}
return - V_189 ;
}
}
return 0 ;
}
static void F_189 ( struct V_1 * V_2 )
{
int V_386 ;
for ( V_386 = 0 ; V_386 < V_2 -> V_235 ; ++ V_386 ) {
F_188 ( V_2 -> V_403 [ V_386 ] . V_404 ) ;
V_2 -> V_403 [ V_386 ] . V_404 = NULL ;
}
V_2 -> V_405 = 0 ;
V_2 -> V_406 = 0 ;
V_2 -> V_234 = 0 ;
}
static bool F_65 ( struct V_1 * V_2 )
{
bool V_228 = false ;
if ( V_2 -> V_234 ) {
struct V_407 * V_408 =
& V_2 -> V_403 [ V_2 -> V_405 ] ;
int V_409 = F_190 ( V_2 ) ;
int V_410 = V_408 -> V_411 / V_379 ;
if ( V_408 -> V_411 % V_379 )
++ V_410 ;
if ( V_410 <= V_409 ) {
V_2 -> V_78 = V_408 -> V_411 ;
F_101 ( V_2 , V_408 -> V_404 , V_408 -> V_411 ) ;
-- V_2 -> V_234 ;
if ( ++ V_2 -> V_405 >= V_2 -> V_235 )
V_2 -> V_405 = 0 ;
F_191 ( & V_2 -> V_81 , V_324 + F_192 ( 5000 ) ) ;
V_228 = true ;
}
}
return V_228 ;
}
static int F_103 ( struct V_1 * V_2 , const char * V_412 , unsigned int V_413 )
{
struct V_407 * V_408 ;
if ( V_2 -> V_234 >= V_2 -> V_235 ) {
return 0 ;
}
V_408 = & V_2 -> V_403 [ V_2 -> V_406 ] ;
V_408 -> V_411 = V_413 ;
memcpy ( V_408 -> V_404 , V_412 , V_413 ) ;
++ V_2 -> V_234 ;
if ( ++ V_2 -> V_406 >= V_2 -> V_235 )
V_2 -> V_406 = 0 ;
return 1 ;
}
static int F_76 ( struct V_1 * V_2 )
{
if ( F_193 ( V_2 -> V_137 , V_2 -> V_414 , L_125 ) == NULL ) {
F_4 ( L_126 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_137 ) ;
return - V_300 ;
}
V_2 -> V_415 = true ;
if ( F_194 ( V_2 -> V_177 , F_66 , V_2 -> V_416 ,
V_2 -> V_21 , V_2 ) < 0 ) {
F_4 ( L_127 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_177 ) ;
goto V_417;
}
V_2 -> V_418 = true ;
if ( V_2 -> V_349 == V_350 ) {
if ( F_195 ( V_2 -> V_351 , 0x40000 , L_125 ) == NULL ) {
F_4 ( L_128 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_351 ) ;
goto V_417;
}
V_2 -> V_419 = true ;
if ( F_195 ( V_2 -> V_352 + V_2 -> V_420 , 128 , L_125 ) == NULL ) {
F_4 ( L_129 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_352 + V_2 -> V_420 ) ;
goto V_417;
}
V_2 -> V_421 = true ;
V_2 -> V_388 = F_196 ( V_2 -> V_351 ,
0x40000 ) ;
if ( ! V_2 -> V_388 ) {
F_4 ( L_130 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_351 ) ;
goto V_417;
}
if ( ! F_197 ( V_2 ) ) {
F_4 ( L_131 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_351 ) ;
goto V_417;
}
V_2 -> V_422 = F_196 ( V_2 -> V_352 ,
V_423 ) ;
if ( ! V_2 -> V_422 ) {
F_4 ( L_132 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_352 ) ;
goto V_417;
}
V_2 -> V_422 += V_2 -> V_420 ;
} else {
if ( F_198 ( V_2 -> V_353 , V_2 -> V_21 ) < 0 ) {
F_4 ( L_133 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_353 ) ;
F_80 ( V_2 ) ;
return - V_300 ;
}
V_2 -> V_424 = true ;
F_199 ( V_2 -> V_353 , V_425 ) ;
F_200 ( V_2 -> V_353 ) ;
}
if ( F_174 ( V_2 ) < 0 ) {
F_4 ( L_134 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_353 ) ;
goto V_417;
}
return 0 ;
V_417:
F_80 ( V_2 ) ;
return - V_300 ;
}
static void F_80 ( struct V_1 * V_2 )
{
if ( V_19 >= V_20 )
F_4 ( L_135 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( V_2 -> V_418 ) {
F_201 ( V_2 -> V_177 , V_2 ) ;
V_2 -> V_418 = false ;
}
if ( V_2 -> V_424 ) {
F_202 ( V_2 -> V_353 ) ;
F_203 ( V_2 -> V_353 ) ;
V_2 -> V_424 = false ;
}
F_185 ( V_2 ) ;
F_187 ( V_2 ) ;
F_189 ( V_2 ) ;
if ( V_2 -> V_415 ) {
F_204 ( V_2 -> V_137 , V_2 -> V_414 ) ;
V_2 -> V_415 = false ;
}
if ( V_2 -> V_419 ) {
F_205 ( V_2 -> V_351 , 0x40000 ) ;
V_2 -> V_419 = false ;
}
if ( V_2 -> V_421 ) {
F_205 ( V_2 -> V_352 + V_2 -> V_420 , 128 ) ;
V_2 -> V_421 = false ;
}
if ( V_2 -> V_388 ) {
F_206 ( V_2 -> V_388 ) ;
V_2 -> V_388 = NULL ;
}
if ( V_2 -> V_422 ) {
F_206 ( V_2 -> V_422 - V_2 -> V_420 ) ;
V_2 -> V_422 = NULL ;
}
if ( V_19 >= V_20 )
F_4 ( L_136 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
}
static void F_207 ( struct V_1 * V_2 )
{
V_2 -> V_340 = NULL ;
V_2 -> line = V_338 ;
sprintf ( V_2 -> V_21 , L_137 , V_2 -> line ) ;
if ( V_2 -> line < V_426 ) {
if ( V_427 [ V_2 -> line ] )
V_2 -> V_238 = V_427 [ V_2 -> line ] ;
if ( V_428 [ V_2 -> line ] ) {
V_2 -> V_381 = V_428 [ V_2 -> line ] ;
if ( V_2 -> V_381 < 1 )
V_2 -> V_381 = 1 ;
}
if ( V_429 [ V_2 -> line ] ) {
V_2 -> V_235 = V_429 [ V_2 -> line ] ;
if ( V_2 -> V_235 < 1 )
V_2 -> V_235 = 1 ;
else if ( V_2 -> V_235 > V_430 )
V_2 -> V_235 = V_430 ;
}
}
V_338 ++ ;
if ( ! V_339 )
V_339 = V_2 ;
else {
struct V_1 * V_431 = V_339 ;
while( V_431 -> V_340 )
V_431 = V_431 -> V_340 ;
V_431 -> V_340 = V_2 ;
}
if ( V_2 -> V_238 < 4096 )
V_2 -> V_238 = 4096 ;
else if ( V_2 -> V_238 > 65535 )
V_2 -> V_238 = 65535 ;
if ( V_2 -> V_349 == V_350 ) {
F_4 ( L_138 ,
V_2 -> V_432 + 1 , V_2 -> V_21 , V_2 -> V_137 , V_2 -> V_177 ,
V_2 -> V_351 , V_2 -> V_352 ,
V_2 -> V_238 ) ;
} else {
F_4 ( L_139 ,
V_2 -> V_21 , V_2 -> V_137 , V_2 -> V_177 , V_2 -> V_353 ,
V_2 -> V_238 ) ;
}
#if V_85
F_208 ( V_2 ) ;
#endif
}
static struct V_1 * F_209 ( void )
{
struct V_1 * V_2 ;
V_2 = F_210 ( sizeof( struct V_1 ) ,
V_188 ) ;
if ( ! V_2 ) {
F_4 ( L_140 ) ;
} else {
F_211 ( & V_2 -> V_42 ) ;
V_2 -> V_42 . V_16 = & V_433 ;
V_2 -> V_7 = V_8 ;
F_212 ( & V_2 -> V_33 , F_15 ) ;
V_2 -> V_238 = 4096 ;
V_2 -> V_42 . V_434 = 5 * V_224 / 10 ;
V_2 -> V_42 . V_435 = 30 * V_224 ;
F_213 ( & V_2 -> V_119 ) ;
F_213 ( & V_2 -> V_64 ) ;
F_214 ( & V_2 -> V_22 ) ;
F_214 ( & V_2 -> V_344 ) ;
memcpy ( & V_2 -> V_36 , & V_436 , sizeof( T_5 ) ) ;
V_2 -> V_247 = V_437 ;
V_2 -> V_381 = 1 ;
V_2 -> V_235 = 0 ;
}
return V_2 ;
}
static int F_215 ( void )
{
int V_24 ;
V_438 = F_216 ( 128 ) ;
if ( ! V_438 )
return - V_189 ;
V_438 -> V_439 = V_440 ;
V_438 -> V_441 = L_125 ;
V_438 -> V_3 = L_141 ;
V_438 -> V_442 = V_443 ;
V_438 -> V_444 = 64 ;
V_438 -> type = V_445 ;
V_438 -> V_446 = V_447 ;
V_438 -> V_448 = V_449 ;
V_438 -> V_448 . V_200 =
V_450 | V_213 | V_204 | V_201 | V_226 ;
V_438 -> V_448 . V_451 = 9600 ;
V_438 -> V_448 . V_452 = 9600 ;
V_438 -> V_12 = V_453 ;
F_217 ( V_438 , & V_454 ) ;
if ( ( V_24 = F_218 ( V_438 ) ) < 0 ) {
F_4 ( L_142 ,
__FILE__ , __LINE__ ) ;
F_219 ( V_438 ) ;
V_438 = NULL ;
return V_24 ;
}
F_4 ( L_143 ,
V_441 , V_375 ,
V_438 -> V_442 ) ;
return 0 ;
}
static void F_220 ( void )
{
struct V_1 * V_2 ;
int V_386 ;
for ( V_386 = 0 ; ( V_386 < V_455 ) && V_456 [ V_386 ] && V_457 [ V_386 ] ; V_386 ++ ) {
if ( V_19 >= V_20 )
F_4 ( L_144 ,
V_456 [ V_386 ] , V_457 [ V_386 ] , V_458 [ V_386 ] ) ;
V_2 = F_209 () ;
if ( ! V_2 ) {
if ( V_19 >= V_459 )
F_4 ( L_145 ) ;
continue;
}
V_2 -> V_137 = ( unsigned int ) V_456 [ V_386 ] ;
V_2 -> V_177 = ( unsigned int ) V_457 [ V_386 ] ;
V_2 -> V_177 = F_221 ( V_2 -> V_177 ) ;
V_2 -> V_353 = ( unsigned int ) V_458 [ V_386 ] ;
V_2 -> V_349 = V_460 ;
V_2 -> V_414 = 16 ;
V_2 -> V_416 = 0 ;
F_207 ( V_2 ) ;
}
}
static void F_222 ( void )
{
int V_24 ;
struct V_1 * V_2 ;
struct V_1 * V_461 ;
F_4 ( L_146 , V_441 , V_375 ) ;
if ( V_438 ) {
if ( ( V_24 = F_223 ( V_438 ) ) )
F_4 ( L_147 ,
__FILE__ , __LINE__ , V_24 ) ;
F_219 ( V_438 ) ;
}
V_2 = V_339 ;
while( V_2 ) {
#if V_85
F_224 ( V_2 ) ;
#endif
F_80 ( V_2 ) ;
V_461 = V_2 ;
V_2 = V_2 -> V_340 ;
F_188 ( V_461 ) ;
}
if ( V_462 )
F_225 ( & V_463 ) ;
}
static int T_6 F_226 ( void )
{
int V_24 ;
if ( V_464 ) {
F_1 () ;
F_227 () ;
}
F_4 ( L_148 , V_441 , V_375 ) ;
F_220 () ;
if ( ( V_24 = F_228 ( & V_463 ) ) < 0 )
F_4 ( L_149 , __FILE__ , V_24 ) ;
else
V_462 = true ;
if ( ( V_24 = F_215 () ) < 0 )
goto error;
return 0 ;
error:
F_222 () ;
return V_24 ;
}
static void T_7 F_229 ( void )
{
F_222 () ;
}
static void F_35 ( struct V_1 * V_2 , T_2 V_465 )
{
F_50 ( V_465 + V_2 -> V_466 , V_2 -> V_137 + V_138 ) ;
if ( V_2 -> V_349 == V_350 )
F_51 ( V_2 -> V_137 + V_138 ) ;
}
static void F_34 ( struct V_1 * V_2 , T_2 V_465 )
{
F_50 ( V_465 + V_2 -> V_467 , V_2 -> V_137 ) ;
if ( V_2 -> V_349 == V_350 )
F_51 ( V_2 -> V_137 ) ;
}
static void F_62 ( struct V_1 * V_2 , T_2 V_468 , T_2 V_469 )
{
F_50 ( V_468 + V_2 -> V_467 , V_2 -> V_137 ) ;
F_50 ( V_469 , V_2 -> V_137 ) ;
if ( V_2 -> V_349 == V_350 )
F_51 ( V_2 -> V_137 ) ;
}
static T_2 F_63 ( struct V_1 * V_2 , T_2 V_468 )
{
F_50 ( V_468 + V_2 -> V_467 , V_2 -> V_137 ) ;
return F_51 ( V_2 -> V_137 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_2 V_468 , T_2 V_469 )
{
F_50 ( V_468 + V_2 -> V_466 , V_2 -> V_137 + V_138 ) ;
F_50 ( V_469 , V_2 -> V_137 + V_138 ) ;
if ( V_2 -> V_349 == V_350 )
F_51 ( V_2 -> V_137 + V_138 ) ;
}
static T_2 F_25 ( struct V_1 * V_2 , T_2 V_468 )
{
F_50 ( V_468 + V_2 -> V_466 , V_2 -> V_137 + V_138 ) ;
return F_51 ( V_2 -> V_137 + V_138 ) ;
}
static void F_230 ( struct V_1 * V_2 )
{
T_2 V_469 ;
bool V_470 ;
F_27 ( V_2 , V_471 , 0x1f ) ;
V_469 = F_25 ( V_2 , V_472 ) ;
V_470 = ( V_469 == V_473 ) ;
if ( V_2 -> V_36 . V_12 & V_236 )
{
V_469 = 0x8e06 ;
}
else
{
if ( V_2 -> V_36 . V_37 == V_203 ) {
V_469 = 0x0001 ;
F_27 ( V_2 , V_295 ,
( unsigned short ) ( ( F_25 ( V_2 , V_295 ) & ~ ( V_57 | V_198 ) ) | V_198 ) ) ;
V_469 |= 0x0400 ;
}
else {
V_469 = 0x0606 ;
if ( V_2 -> V_36 . V_12 & V_474 )
V_469 |= V_197 ;
else if ( V_2 -> V_36 . V_12 & V_475 )
V_469 |= V_196 ;
else if ( V_2 -> V_36 . V_12 & V_476 )
V_469 |= V_196 + V_197 ;
}
if ( V_2 -> V_36 . V_477 != V_478 )
V_469 |= V_57 ;
}
if ( V_2 -> V_36 . V_37 == V_38 &&
( V_2 -> V_36 . V_12 & V_479 ) )
V_469 |= V_198 ;
if ( V_2 -> V_36 . V_480 != 0xff )
{
F_27 ( V_2 , V_481 , V_2 -> V_36 . V_480 ) ;
V_469 |= V_482 ;
}
F_27 ( V_2 , V_58 , V_469 ) ;
V_2 -> V_56 = V_469 ;
V_469 = 0x0500 ;
switch ( V_2 -> V_36 . V_483 ) {
case V_484 : V_469 |= V_57 ; break;
case V_485 : V_469 |= V_197 ; break;
case V_486 : V_469 |= V_197 + V_57 ; break;
case V_487 : V_469 |= V_196 ; break;
case V_488 : V_469 |= V_196 + V_57 ; break;
case V_489 : V_469 |= V_196 + V_197 ; break;
case V_490 : V_469 |= V_196 + V_197 + V_57 ; break;
}
if ( ( V_2 -> V_36 . V_491 & V_492 ) == V_493 )
V_469 |= V_162 ;
else if ( ( V_2 -> V_36 . V_491 & V_492 ) == V_494 )
V_469 |= ( V_198 | V_180 | V_162 ) ;
F_27 ( V_2 , V_495 , V_469 ) ;
F_27 ( V_2 , V_496 , V_497 ) ;
F_49 ( V_2 , V_498 ) ;
V_469 = F_25 ( V_2 , V_59 ) & 0xc0 ;
if ( V_2 -> V_349 == V_350 )
F_27 ( V_2 , V_59 , ( T_2 ) ( 0x030a | V_469 ) ) ;
else
F_27 ( V_2 , V_59 , ( T_2 ) ( 0x140a | V_469 ) ) ;
F_31 ( V_2 , V_143 ) ;
F_30 ( V_2 , V_67 ) ;
V_469 = 0x0400 ;
switch ( V_2 -> V_36 . V_483 ) {
case V_484 : V_469 |= V_57 ; break;
case V_485 : V_469 |= V_197 ; break;
case V_486 : V_469 |= V_197 + V_57 ; break;
case V_487 : V_469 |= V_196 ; break;
case V_488 : V_469 |= V_196 + V_57 ; break;
case V_489 : V_469 |= V_196 + V_197 ; break;
case V_490 : V_469 |= V_196 + V_197 + V_57 ; break;
}
if ( ( V_2 -> V_36 . V_491 & V_492 ) == V_493 )
V_469 |= V_162 + V_167 ;
else if ( ( V_2 -> V_36 . V_491 & V_492 ) == V_494 )
V_469 |= ( V_198 | V_180 | V_162 | V_167 ) ;
F_27 ( V_2 , V_370 , V_469 ) ;
F_124 ( V_2 ) ;
F_129 ( V_2 , V_499 ) ;
if ( V_2 -> V_349 == V_350 )
F_27 ( V_2 , V_361 , 0x0736 ) ;
else
F_27 ( V_2 , V_361 , 0x1436 ) ;
F_33 ( V_2 , V_500 ) ;
F_30 ( V_2 , V_69 ) ;
V_2 -> V_501 = 0 ;
if ( ! V_470 )
V_2 -> V_501 |= V_502 ;
F_27 ( V_2 , V_68 , V_2 -> V_501 ) ;
V_469 = 0x0f40 ;
if ( V_2 -> V_36 . V_12 & V_503 )
V_469 |= 0x0003 ;
else if ( V_2 -> V_36 . V_12 & V_504 )
V_469 |= 0x0004 ;
else if ( V_2 -> V_36 . V_12 & V_505 )
V_469 |= 0x0006 ;
else
V_469 |= 0x0007 ;
if ( V_2 -> V_36 . V_12 & V_506 )
V_469 |= 0x0018 ;
else if ( V_2 -> V_36 . V_12 & V_507 )
V_469 |= 0x0020 ;
else if ( V_2 -> V_36 . V_12 & V_508 )
V_469 |= 0x0038 ;
else
V_469 |= 0x0030 ;
F_27 ( V_2 , V_509 , V_469 ) ;
V_469 = 0x0000 ;
if ( V_2 -> V_36 . V_12 & ( V_503 + V_506 ) ) {
V_392 V_510 ;
V_392 V_511 ;
T_2 V_512 ;
if ( V_2 -> V_349 == V_350 )
V_510 = 11059200 ;
else
V_510 = 14745600 ;
if ( V_2 -> V_36 . V_12 & V_513 ) {
V_511 = 16 ;
V_469 |= V_180 ;
}
else if ( V_2 -> V_36 . V_12 & V_514 ) {
V_511 = 8 ;
V_469 |= V_515 ;
}
else
V_511 = 32 ;
if ( V_2 -> V_36 . V_516 )
{
V_512 = ( T_2 ) ( ( V_510 / V_511 ) / V_2 -> V_36 . V_516 ) ;
if ( ! ( ( ( ( V_510 / V_511 ) % V_2 -> V_36 . V_516 ) * 2 )
/ V_2 -> V_36 . V_516 ) )
V_512 -- ;
}
else
V_512 = - 1 ;
F_27 ( V_2 , V_517 , V_512 ) ;
V_469 |= V_482 ;
switch ( V_2 -> V_36 . V_483 ) {
case V_518 :
case V_484 :
case V_485 :
case V_486 : V_469 |= V_167 ; break;
case V_487 :
case V_488 : V_469 |= V_162 ; break;
case V_489 :
case V_490 : V_469 |= V_162 + V_167 ; break;
}
}
F_27 ( V_2 , V_519 , V_469 ) ;
F_27 ( V_2 , V_520 , 0x1020 ) ;
if ( V_2 -> V_36 . V_12 & V_521 ) {
F_27 ( V_2 , V_124 ,
( T_2 ) ( F_25 ( V_2 , V_124 ) | V_522 ) ) ;
}
F_231 ( V_2 ) ;
F_30 ( V_2 , V_67 + V_132 +
V_69 + V_128 + V_160 ) ;
F_27 ( V_2 , V_124 , ( T_2 ) ( F_25 ( V_2 , V_124 ) | V_135 ) ) ;
F_91 ( V_2 , V_160 ) ;
V_2 -> V_467 = 0 ;
F_50 ( 0 , V_2 -> V_137 ) ;
F_34 ( V_2 , V_523 ) ;
V_2 -> V_467 = V_167 ;
F_50 ( V_167 , V_2 -> V_137 ) ;
if ( V_2 -> V_349 == V_460 ) {
F_27 ( V_2 , V_195 , ( T_2 ) ( ( F_25 ( V_2 , V_195 ) | V_196 ) & ~ V_197 ) ) ;
}
if ( V_2 -> V_349 == V_350 ) {
F_62 ( V_2 , V_524 , 0xa00b ) ;
}
else
F_62 ( V_2 , V_524 , 0x800b ) ;
F_62 ( V_2 , V_164 , 0xf200 ) ;
F_62 ( V_2 , V_169 , 0xf200 ) ;
F_62 ( V_2 , V_525 , 0x9000 ) ;
F_63 ( V_2 , V_164 ) ;
F_63 ( V_2 , V_169 ) ;
F_62 ( V_2 , V_161 , 0x0303 ) ;
V_469 = 0x8080 ;
switch ( V_2 -> V_36 . V_526 ) {
case V_527 : V_469 |= V_180 ; break;
case V_528 : V_469 |= V_515 ; break;
case V_529 : V_469 |= V_515 + V_180 ; break;
}
switch ( V_2 -> V_36 . V_477 ) {
case V_530 : V_469 |= V_167 + V_198 ; break;
case V_531 : V_469 |= V_167 ; break;
case V_532 : V_469 |= V_162 ; break;
case V_533 : V_469 |= V_162 + V_167 ; break;
}
F_27 ( V_2 , V_534 , V_469 ) ;
if ( V_2 -> V_349 == V_350 ) {
F_62 ( V_2 , V_535 , 0x0000 ) ;
}
else
F_62 ( V_2 , V_535 , 0x2000 ) ;
F_10 ( V_2 ) ;
F_86 ( V_2 ) ;
}
static void F_232 ( struct V_1 * V_2 , int V_248 )
{
if ( V_248 ) {
F_27 ( V_2 , V_295 , F_25 ( V_2 , V_295 ) | ( V_296 + V_536 ) ) ;
F_27 ( V_2 , V_509 , 0x0f64 ) ;
if ( V_2 -> V_36 . V_516 ) {
if ( V_2 -> V_349 == V_350 )
F_27 ( V_2 , V_537 , ( T_2 ) ( ( 11059200 / V_2 -> V_36 . V_516 ) - 1 ) ) ;
else
F_27 ( V_2 , V_537 , ( T_2 ) ( ( 14745600 / V_2 -> V_36 . V_516 ) - 1 ) ) ;
} else
F_27 ( V_2 , V_537 , ( T_2 ) 8 ) ;
F_27 ( V_2 , V_519 , ( T_2 ) ( ( F_25 ( V_2 , V_519 ) & ~ V_163 ) | V_168 ) ) ;
F_27 ( V_2 , V_295 , ( T_2 ) ( ( F_25 ( V_2 , V_295 ) & 0xfff8 ) | 0x0004 ) ) ;
V_2 -> V_466 = 0x300 ;
F_50 ( 0x0300 , V_2 -> V_137 + V_138 ) ;
} else {
F_27 ( V_2 , V_295 , F_25 ( V_2 , V_295 ) & ~ ( V_296 + V_536 ) ) ;
V_2 -> V_466 = 0 ;
F_50 ( 0 , V_2 -> V_137 + V_138 ) ;
}
}
static void F_233 ( struct V_1 * V_2 , V_392 V_222 )
{
V_392 V_510 ;
T_2 V_512 ;
if ( V_222 ) {
if ( V_2 -> V_349 == V_350 )
V_510 = 11059200 ;
else
V_510 = 14745600 ;
V_512 = ( T_2 ) ( V_510 / V_222 ) ;
if ( ! ( ( ( V_510 % V_222 ) * 2 ) / V_222 ) )
V_512 -- ;
F_27 ( V_2 , V_537 , V_512 ) ;
F_27 ( V_2 , V_519 , ( T_2 ) ( ( F_25 ( V_2 , V_519 ) & ~ V_163 ) | V_168 ) ) ;
F_27 ( V_2 , V_295 , ( T_2 ) ( ( F_25 ( V_2 , V_295 ) & 0xfff8 ) | 0x0004 ) ) ;
} else {
F_27 ( V_2 , V_519 , ( T_2 ) ( F_25 ( V_2 , V_519 ) & ~ V_168 ) ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
int V_538 ;
int V_539 ;
int V_540 ;
bool V_541 = false ;
bool V_542 = false ;
bool V_543 = false ;
V_393 * V_387 = V_2 -> V_384 ;
V_392 V_398 ;
F_34 ( V_2 , V_544 ) ;
F_49 ( V_2 , V_545 ) ;
F_35 ( V_2 , V_148 ) ;
V_540 = V_538 = V_539 = V_2 -> V_546 ;
while( ! V_387 [ V_539 ] . V_13 )
{
if ( ! V_541 )
{
V_541 = true ;
V_540 = V_539 ;
V_542 = false ;
}
if ( V_387 [ V_539 ] . V_49 )
{
V_541 = false ;
V_542 = true ;
}
V_539 ++ ;
if ( V_539 == V_2 -> V_382 )
V_539 = 0 ;
if ( V_538 == V_539 )
{
F_179 ( V_2 ) ;
V_540 = 0 ;
V_541 = false ;
V_543 = true ;
break;
}
}
if ( V_541 && ! V_542 )
{
V_538 = V_540 ;
do
{
* ( ( unsigned long * ) & ( V_2 -> V_384 [ V_538 ++ ] . V_13 ) ) = V_379 ;
if ( V_538 == V_2 -> V_382 )
V_538 = 0 ;
} while( V_538 != V_539 );
V_543 = true ;
}
if ( V_543 )
{
F_31 ( V_2 , V_143 ) ;
F_30 ( V_2 , V_132 | V_67 ) ;
F_31 ( V_2 , V_132 | V_67 ) ;
F_57 ( V_2 , V_158 ) ;
F_27 ( V_2 , V_520 , ( T_2 ) ( F_25 ( V_2 , V_520 ) | V_57 ) ) ;
V_398 = V_2 -> V_384 [ V_540 ] . V_394 ;
F_62 ( V_2 , V_547 , ( T_2 ) V_398 ) ;
F_62 ( V_2 , V_548 , ( T_2 ) ( V_398 >> 16 ) ) ;
F_31 ( V_2 , V_143 ) ;
F_30 ( V_2 , V_132 + V_67 ) ;
F_91 ( V_2 , V_67 ) ;
F_62 ( V_2 , V_549 , V_135 + V_170 ) ;
F_62 ( V_2 , V_525 , ( T_2 ) ( F_63 ( V_2 , V_525 ) | V_163 ) ) ;
F_34 ( V_2 , V_550 ) ;
if ( V_2 -> V_36 . V_12 & V_551 )
F_57 ( V_2 , V_552 ) ;
else
F_57 ( V_2 , V_553 ) ;
}
else
{
F_27 ( V_2 , V_520 , ( T_2 ) ( F_25 ( V_2 , V_520 ) | V_57 ) ) ;
F_35 ( V_2 , V_148 ) ;
}
}
static void F_86 ( struct V_1 * V_2 )
{
if ( V_19 >= V_51 )
F_4 ( L_150 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_34 ( V_2 , V_159 ) ;
F_31 ( V_2 , V_143 ) ;
F_30 ( V_2 , V_132 + V_67 ) ;
F_58 ( V_2 , V_132 + V_67 ) ;
F_57 ( V_2 , V_158 ) ;
F_27 ( V_2 , V_520 , ( T_2 ) ( F_25 ( V_2 , V_520 ) | V_57 ) ) ;
F_35 ( V_2 , V_148 ) ;
V_2 -> V_250 = false ;
V_2 -> V_165 = false ;
V_2 -> V_41 = false ;
}
static void F_21 ( struct V_1 * V_2 )
{
V_392 V_398 ;
if ( V_19 >= V_51 )
F_4 ( L_151 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_179 ( V_2 ) ;
F_86 ( V_2 ) ;
F_27 ( V_2 , V_520 , ( T_2 ) ( F_25 ( V_2 , V_520 ) | V_57 ) ) ;
F_35 ( V_2 , V_148 ) ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_203 ) {
V_398 = V_2 -> V_384 [ 0 ] . V_394 ;
F_62 ( V_2 , V_547 , ( T_2 ) V_398 ) ;
F_62 ( V_2 , V_548 , ( T_2 ) ( V_398 >> 16 ) ) ;
F_31 ( V_2 , V_143 ) ;
F_30 ( V_2 , V_132 + V_67 ) ;
F_91 ( V_2 , V_67 ) ;
F_62 ( V_2 , V_549 , V_135 + V_170 ) ;
F_62 ( V_2 , V_525 , ( T_2 ) ( F_63 ( V_2 , V_525 ) | V_163 ) ) ;
F_34 ( V_2 , V_550 ) ;
if ( V_2 -> V_36 . V_12 & V_551 )
F_57 ( V_2 , V_552 ) ;
else
F_57 ( V_2 , V_553 ) ;
} else {
F_31 ( V_2 , V_143 ) ;
F_30 ( V_2 , V_132 + V_67 ) ;
F_91 ( V_2 , V_132 ) ;
F_35 ( V_2 , V_148 ) ;
F_49 ( V_2 , V_545 ) ;
F_57 ( V_2 , V_553 ) ;
}
F_27 ( V_2 , V_520 , 0x1020 ) ;
V_2 -> V_250 = true ;
}
static void F_13 ( struct V_1 * V_2 )
{
V_392 V_398 ;
unsigned int V_554 ;
if ( V_19 >= V_51 )
F_4 ( L_152 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( V_2 -> V_78 ) {
V_2 -> V_82 = false ;
if ( V_2 -> V_36 . V_12 & V_555 ) {
F_37 ( V_2 ) ;
if ( ! ( V_2 -> V_83 & V_84 ) ) {
V_2 -> V_83 |= V_84 ;
F_38 ( V_2 ) ;
V_2 -> V_82 = true ;
}
}
if ( V_2 -> V_36 . V_37 == V_229 ) {
if ( ! V_2 -> V_43 ) {
F_33 ( V_2 , V_500 ) ;
F_30 ( V_2 , V_69 + V_128 ) ;
F_91 ( V_2 , V_128 ) ;
F_47 ( V_2 ) ;
}
} else {
F_34 ( V_2 , V_72 ) ;
V_554 = V_2 -> V_385 [ V_2 -> V_556 ] . V_557 ;
if ( V_2 -> V_36 . V_37 == V_203 )
V_2 -> V_385 [ V_2 -> V_556 ] . V_557 = 0 ;
F_27 ( V_2 , V_558 , ( T_2 ) V_554 ) ;
F_35 ( V_2 , V_73 ) ;
V_398 = V_2 -> V_385 [ V_2 -> V_556 ] . V_394 ;
F_62 ( V_2 , V_559 , ( T_2 ) V_398 ) ;
F_62 ( V_2 , V_560 , ( T_2 ) ( V_398 >> 16 ) ) ;
F_33 ( V_2 , V_500 ) ;
F_30 ( V_2 , V_69 ) ;
F_91 ( V_2 , V_69 ) ;
if ( V_2 -> V_36 . V_37 == V_203 &&
V_2 -> V_381 > 1 ) {
F_62 ( V_2 , V_561 , V_170 | V_135 ) ;
F_62 ( V_2 , V_525 , ( T_2 ) ( F_63 ( V_2 , V_525 ) | V_168 ) ) ;
}
F_34 ( V_2 , V_562 ) ;
F_129 ( V_2 , V_563 ) ;
F_191 ( & V_2 -> V_81 , V_324 +
F_192 ( 5000 ) ) ;
}
V_2 -> V_43 = true ;
}
if ( ! V_2 -> V_23 ) {
V_2 -> V_23 = true ;
if ( V_2 -> V_36 . V_12 & V_521 )
F_234 ( V_2 , V_564 ) ;
else
F_234 ( V_2 , V_553 ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_19 >= V_51 )
F_4 ( L_153 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_36 ( & V_2 -> V_81 ) ;
F_33 ( V_2 , V_500 ) ;
F_30 ( V_2 , V_69 + V_128 ) ;
F_58 ( V_2 , V_69 + V_128 ) ;
F_234 ( V_2 , V_158 ) ;
F_34 ( V_2 , V_72 ) ;
F_35 ( V_2 , V_73 ) ;
V_2 -> V_23 = false ;
V_2 -> V_43 = false ;
}
static void F_47 ( struct V_1 * V_2 )
{
int V_130 ;
T_8 V_565 [ 2 ] ;
if ( ! V_2 -> V_78 && ! V_2 -> V_239 )
return;
F_129 ( V_2 , V_566 ) ;
while( ( V_130 = F_25 ( V_2 , V_361 ) >> 8 ) && V_2 -> V_78 ) {
if ( ( V_2 -> V_78 > 1 ) && ( V_130 > 1 ) && ! V_2 -> V_239 ) {
V_565 [ 0 ] = V_2 -> V_187 [ V_2 -> V_80 ++ ] ;
V_2 -> V_80 = V_2 -> V_80 & ( V_230 - 1 ) ;
V_565 [ 1 ] = V_2 -> V_187 [ V_2 -> V_80 ++ ] ;
V_2 -> V_80 = V_2 -> V_80 & ( V_230 - 1 ) ;
F_50 ( * ( ( T_2 * ) V_565 ) , V_2 -> V_137 + V_567 ) ;
V_2 -> V_78 -= 2 ;
V_2 -> V_54 . V_298 += 2 ;
} else {
F_50 ( ( F_51 ( V_2 -> V_137 + V_138 ) & 0x0780 ) | ( V_568 + V_134 ) ,
V_2 -> V_137 + V_138 ) ;
if ( V_2 -> V_239 ) {
F_50 ( V_2 -> V_239 , V_2 -> V_137 + V_138 ) ;
V_2 -> V_239 = 0 ;
} else {
F_50 ( V_2 -> V_187 [ V_2 -> V_80 ++ ] , V_2 -> V_137 + V_138 ) ;
V_2 -> V_80 = V_2 -> V_80 & ( V_230 - 1 ) ;
V_2 -> V_78 -- ;
}
V_2 -> V_54 . V_298 ++ ;
}
}
}
static void F_235 ( struct V_1 * V_2 )
{
if ( V_2 -> V_349 == V_350 ) {
int V_386 ;
V_392 V_569 ;
volatile V_392 * V_570 = ( V_392 * ) ( V_2 -> V_422 + 0x50 ) ;
V_392 * V_571 = ( V_392 * ) ( V_2 -> V_422 + 0x28 ) ;
V_2 -> V_572 |= V_573 ;
* V_570 = V_2 -> V_572 ;
for( V_386 = 0 ; V_386 < 10 ; V_386 ++ )
V_569 = * V_570 ;
V_2 -> V_572 &= ~ V_573 ;
* V_570 = V_2 -> V_572 ;
* V_571 = F_236 (
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
F_237 ( 0 , V_2 -> V_137 + 8 ) ;
}
V_2 -> V_467 = 0 ;
V_2 -> V_466 = 0 ;
V_2 -> V_574 = 0 ;
F_50 ( 0x000c , V_2 -> V_137 + V_575 ) ;
F_50 ( 0 , V_2 -> V_137 ) ;
F_50 ( 0 , V_2 -> V_137 + V_138 ) ;
F_35 ( V_2 , V_576 ) ;
F_27 ( V_2 , V_195 , 0xf0f5 ) ;
F_27 ( V_2 , V_295 , 0x0004 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
T_2 V_469 ;
F_69 ( V_2 ) ;
F_50 ( 0 , V_2 -> V_137 ) ;
F_34 ( V_2 , V_523 ) ;
F_238 ( V_2 ) ;
V_469 = 0 ;
if ( V_2 -> V_36 . V_215 != 1 )
V_469 |= V_197 ;
F_27 ( V_2 , V_58 , V_469 ) ;
V_469 = 0 ;
if ( V_2 -> V_36 . V_210 != 8 )
V_469 |= V_482 + V_135 + V_170 ;
if ( V_2 -> V_36 . V_146 != V_216 ) {
V_469 |= V_577 ;
if ( V_2 -> V_36 . V_146 != V_219 )
V_469 |= V_536 ;
}
F_27 ( V_2 , V_495 , V_469 ) ;
F_49 ( V_2 , V_578 ) ;
F_27 ( V_2 , V_59 , 0x0000 ) ;
F_31 ( V_2 , V_143 ) ;
F_30 ( V_2 , V_67 ) ;
V_469 = 0 ;
if ( V_2 -> V_36 . V_210 != 8 )
V_469 |= V_482 + V_135 + V_170 ;
if ( V_2 -> V_36 . V_146 != V_216 ) {
V_469 |= V_577 ;
if ( V_2 -> V_36 . V_146 != V_219 )
V_469 |= V_536 ;
}
F_27 ( V_2 , V_370 , V_469 ) ;
F_124 ( V_2 ) ;
F_129 ( V_2 , V_579 ) ;
F_27 ( V_2 , V_361 , 0x1f40 ) ;
F_33 ( V_2 , V_500 ) ;
F_30 ( V_2 , V_69 ) ;
F_239 ( V_2 , V_2 -> V_36 . V_222 ) ;
F_27 ( V_2 , V_520 , 0x0020 ) ;
F_58 ( V_2 , V_69 + V_128 +
V_132 + V_67 ) ;
F_30 ( V_2 , V_69 + V_128 +
V_132 + V_67 ) ;
F_231 ( V_2 ) ;
if ( V_2 -> V_349 == V_460 ) {
F_27 ( V_2 , V_195 , ( T_2 ) ( ( F_25 ( V_2 , V_195 ) | V_57 ) & ~ V_198 ) ) ;
}
if ( V_2 -> V_36 . V_580 ) {
V_2 -> V_466 = 0x300 ;
F_50 ( 0x0300 , V_2 -> V_137 + V_138 ) ;
}
}
static void F_238 ( struct V_1 * V_2 )
{
int V_386 ;
unsigned long V_581 = V_2 -> V_36 . V_37 ;
V_2 -> V_36 . V_37 = V_38 ;
F_69 ( V_2 ) ;
F_230 ( V_2 ) ;
F_232 ( V_2 , 1 ) ;
F_27 ( V_2 , V_537 , 0 ) ;
F_27 ( V_2 , V_534 , 0x0100 ) ;
F_35 ( V_2 , V_148 ) ;
F_57 ( V_2 , V_553 ) ;
F_27 ( V_2 , V_558 , 2 ) ;
F_35 ( V_2 , V_73 ) ;
F_33 ( V_2 , V_500 ) ;
F_50 ( 0 , V_2 -> V_137 + V_567 ) ;
F_129 ( V_2 , V_563 ) ;
F_234 ( V_2 , V_553 ) ;
for ( V_386 = 0 ; V_386 < 1000 ; V_386 ++ )
if ( F_25 ( V_2 , V_50 ) & ( V_167 + V_482 + V_135 + V_163 ) )
break;
F_232 ( V_2 , 0 ) ;
F_231 ( V_2 ) ;
V_2 -> V_36 . V_37 = V_581 ;
}
static void F_88 ( struct V_1 * V_2 )
{
F_238 ( V_2 ) ;
F_230 ( V_2 ) ;
if ( V_2 -> V_349 == V_460 ) {
F_27 ( V_2 , V_195 , ( T_2 ) ( ( F_25 ( V_2 , V_195 ) | V_57 ) & ~ V_198 ) ) ;
}
F_233 ( V_2 , V_2 -> V_36 . V_516 ) ;
if ( V_2 -> V_36 . V_580 )
F_232 ( V_2 , 1 ) ;
}
static void F_124 ( struct V_1 * V_2 )
{
T_2 V_574 = V_582 ;
switch( V_2 -> V_247 ) {
case V_437 : V_574 = V_582 ; break;
case V_583 : V_574 = V_584 ; break;
case V_585 : V_574 = V_586 ; break;
case V_587 : V_574 = V_588 ; break;
case V_589 : V_574 = V_590 ; break;
case V_591 : V_574 = V_592 ; break;
case V_593 : V_574 = V_594 ; break;
}
V_2 -> V_574 = V_574 ;
V_2 -> V_501 &= ~ V_595 ;
V_2 -> V_501 += V_574 ;
F_27 ( V_2 , V_68 , V_2 -> V_501 ) ;
if ( V_2 -> V_36 . V_37 == V_203 ) {
unsigned char V_596 = 0 ;
switch( V_2 -> V_247 ) {
case V_437 :
V_596 = 0x7e ;
break;
case V_583 :
V_596 = 0x55 ;
break;
case V_585 :
case V_591 :
V_596 = 0x00 ;
break;
case V_587 :
case V_593 :
V_596 = 0xff ;
break;
case V_589 :
V_596 = 0xaa ;
break;
}
F_240 ( V_2 , V_596 , V_596 ) ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
T_2 V_49 ;
V_2 -> V_83 &= V_202 + V_84 ;
V_49 = F_25 ( V_2 , V_90 ) ;
if ( V_49 & V_116 )
V_2 -> V_83 |= V_268 ;
if ( V_49 & V_110 )
V_2 -> V_83 |= V_265 ;
if ( V_49 & V_99 )
V_2 -> V_83 |= V_271 ;
if ( V_49 & V_105 )
V_2 -> V_83 |= V_262 ;
}
static void F_38 ( struct V_1 * V_2 )
{
T_2 V_597 ;
unsigned char V_598 = V_2 -> V_83 ;
V_597 = F_25 ( V_2 , V_195 ) ;
if ( V_598 & V_84 )
V_597 &= ~ ( V_536 ) ;
else
V_597 |= V_536 ;
if ( V_598 & V_202 )
V_597 &= ~ ( V_482 ) ;
else
V_597 |= V_482 ;
F_27 ( V_2 , V_195 , V_597 ) ;
}
static void F_239 ( struct V_1 * V_2 , V_392 V_222 )
{
if ( V_222 ) {
F_27 ( V_2 , V_509 , 0x0f64 ) ;
if ( V_2 -> V_349 == V_350 )
F_27 ( V_2 , V_537 , ( T_2 ) ( ( 691200 / V_222 ) - 1 ) ) ;
else
F_27 ( V_2 , V_537 , ( T_2 ) ( ( 921600 / V_222 ) - 1 ) ) ;
F_27 ( V_2 , V_519 ,
( T_2 ) ( ( F_25 ( V_2 , V_519 ) & ~ V_163 ) | V_168 ) ) ;
F_27 ( V_2 , V_295 ,
( T_2 ) ( ( F_25 ( V_2 , V_295 ) & 0xfff8 ) | 0x0004 ) ) ;
} else {
F_27 ( V_2 , V_519 , ( T_2 ) ( F_25 ( V_2 , V_519 ) & ~ V_168 ) ) ;
}
}
static void F_180 ( struct V_1 * V_2 )
{
unsigned int V_386 ;
for ( V_386 = 0 ; V_386 < V_2 -> V_380 ; V_386 ++ ) {
* ( ( unsigned long * ) & ( V_2 -> V_385 [ V_386 ] . V_13 ) ) = 0 ;
}
V_2 -> V_599 = 0 ;
V_2 -> V_556 = 0 ;
V_2 -> V_171 = 0 ;
V_2 -> V_405 = 0 ;
V_2 -> V_406 = 0 ;
V_2 -> V_234 = 0 ;
}
static int F_190 ( struct V_1 * V_2 )
{
return V_2 -> V_380 - V_2 -> V_171 ;
}
static void F_179 ( struct V_1 * V_2 )
{
unsigned int V_386 ;
for ( V_386 = 0 ; V_386 < V_2 -> V_382 ; V_386 ++ ) {
* ( ( unsigned long * ) & ( V_2 -> V_384 [ V_386 ] . V_13 ) ) = V_379 ;
}
V_2 -> V_546 = 0 ;
}
static void F_241 ( struct V_1 * V_2 , unsigned int V_600 , unsigned int V_601 )
{
bool V_602 = false ;
V_393 * V_603 ;
unsigned int V_604 ;
V_604 = V_600 ;
while( ! V_602 ) {
V_603 = & ( V_2 -> V_384 [ V_604 ] ) ;
if ( V_604 == V_601 ) {
V_602 = true ;
}
* ( ( unsigned long * ) & ( V_603 -> V_13 ) ) = V_379 ;
V_604 ++ ;
if ( V_604 == V_2 -> V_382 )
V_604 = 0 ;
}
V_2 -> V_546 = V_604 ;
}
static bool V_39 ( struct V_1 * V_2 )
{
unsigned int V_600 , V_601 ;
unsigned short V_49 ;
V_393 * V_603 ;
unsigned int V_605 = 0 ;
bool V_606 = false ;
unsigned long V_12 ;
struct V_9 * V_10 = V_2 -> V_42 . V_10 ;
bool V_607 = false ;
V_600 = V_601 = V_2 -> V_546 ;
while( ! V_2 -> V_384 [ V_601 ] . V_49 ) {
if ( V_2 -> V_384 [ V_601 ] . V_13 )
goto V_608;
V_601 ++ ;
if ( V_601 == V_2 -> V_382 )
V_601 = 0 ;
if ( V_601 == V_600 ) {
if ( V_2 -> V_250 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
goto V_608;
}
}
V_49 = V_2 -> V_384 [ V_601 ] . V_49 ;
if ( V_49 & ( V_609 + V_65 +
V_610 + V_611 ) ) {
if ( V_49 & V_609 )
V_2 -> V_54 . V_355 ++ ;
else if ( V_49 & V_611 )
V_2 -> V_54 . V_55 ++ ;
else if ( V_49 & V_65 )
V_2 -> V_54 . V_66 ++ ;
else {
V_2 -> V_54 . V_357 ++ ;
if ( V_2 -> V_36 . V_491 & V_612 )
V_607 = true ;
}
V_605 = 0 ;
#if V_85
{
V_2 -> V_113 -> V_613 . V_614 ++ ;
V_2 -> V_113 -> V_613 . V_615 ++ ;
}
#endif
} else
V_607 = true ;
if ( V_607 ) {
V_605 = V_497 - V_2 -> V_384 [ V_601 ] . V_557 ;
if ( V_2 -> V_36 . V_491 == V_493 )
V_605 -= 2 ;
else if ( V_2 -> V_36 . V_491 == V_494 )
V_605 -= 4 ;
}
if ( V_19 >= V_35 )
F_4 ( L_154 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_49 , V_605 ) ;
if ( V_19 >= V_616 )
F_242 ( V_2 , V_2 -> V_384 [ V_600 ] . V_399 ,
F_104 ( int , V_605 , V_379 ) , 0 ) ;
if ( V_605 ) {
if ( ( ( V_2 -> V_36 . V_491 & V_612 ) &&
( ( V_605 + 1 ) > V_2 -> V_238 ) ) ||
( V_605 > V_2 -> V_238 ) )
V_2 -> V_54 . V_356 ++ ;
else {
int V_617 = V_605 ;
int V_337 = V_600 ;
unsigned char * V_618 = V_2 -> V_401 ;
if ( ! ( V_49 & V_610 ) )
V_2 -> V_54 . V_354 ++ ;
while( V_617 ) {
int V_619 ;
if ( V_617 > V_379 )
V_619 = V_379 ;
else
V_619 = V_617 ;
V_603 = & ( V_2 -> V_384 [ V_337 ] ) ;
memcpy ( V_618 , V_603 -> V_399 , V_619 ) ;
V_618 += V_619 ;
V_617 -= V_619 ;
if ( ++ V_337 == V_2 -> V_382 )
V_337 = 0 ;
}
if ( V_2 -> V_36 . V_491 & V_612 ) {
++ V_605 ;
* V_618 = ( V_49 & V_610 ?
V_620 :
V_621 ) ;
if ( V_19 >= V_616 )
F_4 ( L_155 ,
__FILE__ , __LINE__ , V_2 -> V_21 ,
* V_618 ) ;
}
#if V_85
if ( V_2 -> V_86 )
F_243 ( V_2 , V_2 -> V_401 , V_605 ) ;
else
#endif
F_5 ( V_10 , V_2 -> V_401 , V_2 -> V_622 , V_605 ) ;
}
}
F_241 ( V_2 , V_600 , V_601 ) ;
V_606 = true ;
V_608:
if ( V_2 -> V_250 && V_2 -> V_165 ) {
if ( ! V_2 -> V_384 [ V_601 ] . V_49 &&
V_2 -> V_384 [ V_601 ] . V_13 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
return V_606 ;
}
static bool V_40 ( struct V_1 * V_2 )
{
unsigned int V_623 , V_624 ;
unsigned short V_49 ;
V_393 * V_603 ;
unsigned int V_605 = 0 ;
bool V_606 = false ;
unsigned long V_12 ;
struct V_9 * V_10 = V_2 -> V_42 . V_10 ;
V_623 = V_624 = V_2 -> V_546 ;
++ V_624 ;
if ( V_624 == V_2 -> V_382 )
V_624 = 0 ;
if ( V_2 -> V_384 [ V_623 ] . V_49 != 0 ||
( V_2 -> V_384 [ V_623 ] . V_13 == 0 &&
V_2 -> V_384 [ V_624 ] . V_13 == 0 ) ) {
V_49 = V_2 -> V_384 [ V_623 ] . V_49 ;
if ( V_49 & ( V_609 + V_65 +
V_610 + V_611 ) ) {
if ( V_49 & V_609 )
V_2 -> V_54 . V_355 ++ ;
else if ( V_49 & V_611 )
V_2 -> V_54 . V_55 ++ ;
else if ( V_49 & V_65 )
V_2 -> V_54 . V_66 ++ ;
else
V_2 -> V_54 . V_357 ++ ;
V_605 = 0 ;
} else {
if ( V_49 ) {
if ( V_2 -> V_384 [ V_623 ] . V_557 )
V_605 = V_497 - V_2 -> V_384 [ V_623 ] . V_557 ;
else
V_605 = V_379 ;
}
else
V_605 = V_379 ;
}
if ( V_605 > V_379 ) {
V_605 = V_605 % V_379 ;
}
if ( V_19 >= V_35 )
F_4 ( L_156 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_49 , V_605 ) ;
if ( V_19 >= V_616 )
F_242 ( V_2 , V_2 -> V_384 [ V_623 ] . V_399 ,
F_104 ( int , V_605 , V_379 ) , 0 ) ;
if ( V_605 ) {
V_603 = & ( V_2 -> V_384 [ V_623 ] ) ;
memcpy ( V_2 -> V_401 , V_603 -> V_399 , V_605 ) ;
V_2 -> V_54 . V_354 ++ ;
F_5 ( V_10 , V_2 -> V_401 , V_2 -> V_622 , V_605 ) ;
}
F_241 ( V_2 , V_623 , V_623 ) ;
V_606 = true ;
}
if ( V_2 -> V_250 && V_2 -> V_165 ) {
if ( ! V_2 -> V_384 [ V_623 ] . V_49 &&
V_2 -> V_384 [ V_623 ] . V_13 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
return V_606 ;
}
static void F_101 ( struct V_1 * V_2 ,
const char * V_412 , unsigned int V_413 )
{
unsigned short V_625 ;
unsigned int V_386 = 0 ;
V_393 * V_603 ;
if ( V_19 >= V_616 )
F_242 ( V_2 , V_412 , F_104 ( int , V_413 , V_379 ) , 1 ) ;
if ( V_2 -> V_36 . V_12 & V_236 ) {
V_2 -> V_56 |= V_57 ;
}
V_386 = V_2 -> V_599 ;
V_2 -> V_556 = V_386 ;
V_2 -> V_385 [ V_386 ] . V_49 = V_2 -> V_56 & 0xf000 ;
V_2 -> V_385 [ V_386 ] . V_557 = V_413 ;
V_2 -> V_385 [ V_386 ] . V_13 = V_413 ;
while( V_413 ) {
V_603 = & V_2 -> V_385 [ V_386 ++ ] ;
if ( V_386 == V_2 -> V_380 )
V_386 = 0 ;
if ( V_413 > V_379 )
V_625 = V_379 ;
else
V_625 = V_413 ;
if ( V_2 -> V_349 == V_350 )
F_244 ( V_603 -> V_399 , V_412 , V_625 ) ;
else
memcpy ( V_603 -> V_399 , V_412 , V_625 ) ;
V_603 -> V_13 = V_625 ;
V_412 += V_625 ;
V_413 -= V_625 ;
++ V_2 -> V_171 ;
}
V_2 -> V_599 = V_386 ;
}
static bool F_245 ( struct V_1 * V_2 )
{
static unsigned short V_626 [] =
{ 0x0000 , 0xffff , 0xaaaa , 0x5555 , 0x1234 , 0x6969 , 0x9696 , 0x0f0f } ;
static unsigned int V_627 = F_246 ( V_626 ) ;
unsigned int V_386 ;
bool V_24 = true ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_235 ( V_2 ) ;
if ( ( F_25 ( V_2 , V_124 ) != 0 ) ||
( F_25 ( V_2 , V_178 ) != 0 ) ||
( F_63 ( V_2 , V_179 ) != 0 ) ) {
V_24 = false ;
}
if ( V_24 ) {
for ( V_386 = 0 ; V_386 < V_627 ; V_386 ++ ) {
F_27 ( V_2 , V_537 , V_626 [ V_386 ] ) ;
F_27 ( V_2 , V_517 , V_626 [ ( V_386 + 1 ) % V_627 ] ) ;
F_27 ( V_2 , V_558 , V_626 [ ( V_386 + 2 ) % V_627 ] ) ;
F_27 ( V_2 , V_496 , V_626 [ ( V_386 + 3 ) % V_627 ] ) ;
F_27 ( V_2 , V_481 , V_626 [ ( V_386 + 4 ) % V_627 ] ) ;
F_62 ( V_2 , V_628 , V_626 [ ( V_386 + 5 ) % V_627 ] ) ;
if ( ( F_25 ( V_2 , V_537 ) != V_626 [ V_386 ] ) ||
( F_25 ( V_2 , V_517 ) != V_626 [ ( V_386 + 1 ) % V_627 ] ) ||
( F_25 ( V_2 , V_558 ) != V_626 [ ( V_386 + 2 ) % V_627 ] ) ||
( F_25 ( V_2 , V_496 ) != V_626 [ ( V_386 + 3 ) % V_627 ] ) ||
( F_25 ( V_2 , V_481 ) != V_626 [ ( V_386 + 4 ) % V_627 ] ) ||
( F_63 ( V_2 , V_628 ) != V_626 [ ( V_386 + 5 ) % V_627 ] ) ) {
V_24 = false ;
break;
}
}
}
F_235 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_24 ;
}
static bool F_247 ( struct V_1 * V_2 )
{
unsigned long V_629 ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_235 ( V_2 ) ;
V_2 -> V_127 = false ;
F_27 ( V_2 , V_195 , ( unsigned short ) ( ( F_25 ( V_2 , V_195 ) | V_57 ) & ~ V_198 ) ) ;
F_231 ( V_2 ) ;
F_91 ( V_2 , V_91 ) ;
F_30 ( V_2 , V_91 ) ;
F_41 ( V_2 , V_123 ) ;
F_90 ( V_2 , V_125 + V_126 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_629 = 100 ;
while( V_629 -- && ! V_2 -> V_127 ) {
F_155 ( 10 ) ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_235 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_2 -> V_127 ;
}
static bool F_248 ( struct V_1 * V_2 )
{
unsigned short V_630 ;
unsigned long V_398 ;
unsigned int V_554 ;
unsigned int V_386 ;
char * V_631 ;
bool V_24 = true ;
unsigned short V_49 = 0 ;
unsigned long V_629 ;
unsigned long V_12 ;
T_5 V_246 ;
memcpy ( & V_246 , & V_2 -> V_36 , sizeof( T_5 ) ) ;
memcpy ( & V_2 -> V_36 , & V_436 , sizeof( T_5 ) ) ;
#define F_249 40
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_235 ( V_2 ) ;
F_230 ( V_2 ) ;
F_232 ( V_2 , 1 ) ;
F_62 ( V_2 , V_164 , 0xe200 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_554 = F_249 ;
V_2 -> V_385 [ 0 ] . V_13 = V_554 ;
V_2 -> V_385 [ 0 ] . V_557 = V_554 ;
V_2 -> V_385 [ 0 ] . V_49 = 0x4000 ;
V_631 = V_2 -> V_385 [ 0 ] . V_399 ;
for ( V_386 = 0 ; V_386 < V_554 ; V_386 ++ )
* V_631 ++ = V_386 ;
V_2 -> V_384 [ 0 ] . V_49 = 0 ;
V_2 -> V_384 [ 0 ] . V_13 = V_554 + 4 ;
memset ( V_2 -> V_384 [ 0 ] . V_399 , 0 , V_554 + 4 ) ;
V_2 -> V_385 [ 1 ] . V_13 = 0 ;
V_2 -> V_384 [ 1 ] . V_13 = 0 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_35 ( V_2 , V_148 ) ;
V_398 = V_2 -> V_384 [ 0 ] . V_394 ;
F_62 ( V_2 , V_547 , ( unsigned short ) V_398 ) ;
F_62 ( V_2 , V_548 , ( unsigned short ) ( V_398 >> 16 ) ) ;
F_63 ( V_2 , V_164 ) ;
F_34 ( V_2 , V_550 ) ;
F_27 ( V_2 , V_495 , ( unsigned short ) ( ( F_25 ( V_2 , V_495 ) & 0xfffc ) | 0x0002 ) ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_629 = V_324 + F_192 ( 100 ) ;
for(; ; ) {
if ( F_157 ( V_324 , V_629 ) ) {
V_24 = false ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_49 = F_63 ( V_2 , V_164 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( ! ( V_49 & V_482 ) && ( V_49 & V_577 ) ) {
break;
}
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_27 ( V_2 , V_558 , ( unsigned short ) V_2 -> V_385 [ 0 ] . V_13 ) ;
F_35 ( V_2 , V_73 ) ;
V_398 = V_2 -> V_385 [ 0 ] . V_394 ;
F_62 ( V_2 , V_559 , ( unsigned short ) V_398 ) ;
F_62 ( V_2 , V_560 , ( unsigned short ) ( V_398 >> 16 ) ) ;
F_27 ( V_2 , V_68 , ( unsigned short ) ( ( F_25 ( V_2 , V_68 ) & 0x0f00 ) | 0xfa ) ) ;
F_34 ( V_2 , V_562 ) ;
F_129 ( V_2 , V_566 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_629 = V_324 + F_192 ( 100 ) ;
for(; ; ) {
if ( F_157 ( V_324 , V_629 ) ) {
V_24 = false ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_630 = F_25 ( V_2 , V_361 ) >> 8 ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( V_630 < 16 )
break;
else
if ( V_554 < 32 ) {
if ( V_630 <= ( 32 - V_554 ) )
break;
}
}
if ( V_24 )
{
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_129 ( V_2 , V_563 ) ;
F_27 ( V_2 , V_370 , ( unsigned short ) ( ( F_25 ( V_2 , V_370 ) & 0xfffc ) | 0x0002 ) ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_629 = V_324 + F_192 ( 100 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_49 = F_25 ( V_2 , V_68 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
while ( ! ( V_49 & ( V_536 + V_577 + V_482 + V_170 + V_163 ) ) ) {
if ( F_157 ( V_324 , V_629 ) ) {
V_24 = false ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_49 = F_25 ( V_2 , V_68 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
if ( V_24 ) {
if ( V_49 & ( V_577 + V_163 ) )
V_24 = false ;
}
if ( V_24 ) {
V_629 = V_324 + F_192 ( 100 ) ;
V_49 = V_2 -> V_384 [ 0 ] . V_49 ;
while ( V_49 == 0 ) {
if ( F_157 ( V_324 , V_629 ) ) {
V_24 = false ;
break;
}
V_49 = V_2 -> V_384 [ 0 ] . V_49 ;
}
}
if ( V_24 ) {
V_49 = V_2 -> V_384 [ 0 ] . V_49 ;
if ( V_49 & ( V_167 + V_135 + V_163 ) ) {
V_24 = false ;
} else {
if ( memcmp ( V_2 -> V_385 [ 0 ] . V_399 ,
V_2 -> V_384 [ 0 ] . V_399 , V_554 ) ) {
V_24 = false ;
}
}
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_235 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
memcpy ( & V_2 -> V_36 , & V_246 , sizeof( T_5 ) ) ;
return V_24 ;
}
static int F_77 ( struct V_1 * V_2 )
{
if ( V_19 >= V_20 )
F_4 ( L_157 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( ! F_245 ( V_2 ) ) {
V_2 -> V_632 = V_633 ;
F_4 ( L_158 ,
__FILE__ , __LINE__ , V_2 -> V_21 , ( unsigned short ) ( V_2 -> V_137 ) ) ;
return - V_300 ;
}
if ( ! F_247 ( V_2 ) ) {
V_2 -> V_632 = V_634 ;
F_4 ( L_159 ,
__FILE__ , __LINE__ , V_2 -> V_21 , ( unsigned short ) ( V_2 -> V_177 ) ) ;
return - V_300 ;
}
if ( ! F_248 ( V_2 ) ) {
V_2 -> V_632 = V_635 ;
F_4 ( L_160 ,
__FILE__ , __LINE__ , V_2 -> V_21 , ( unsigned short ) ( V_2 -> V_353 ) ) ;
return - V_300 ;
}
if ( V_19 >= V_20 )
F_4 ( L_161 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return 0 ;
}
static bool F_197 ( struct V_1 * V_2 )
{
static unsigned long V_626 [] =
{ 0x0 , 0x55555555 , 0xaaaaaaaa , 0x66666666 , 0x99999999 , 0xffffffff , 0x12345678 } ;
unsigned long V_627 = F_246 ( V_626 ) ;
unsigned long V_386 ;
unsigned long V_636 = V_637 /sizeof( unsigned long ) ;
unsigned long * V_638 ;
if ( V_2 -> V_349 != V_350 )
return true ;
V_638 = ( unsigned long * ) V_2 -> V_388 ;
for ( V_386 = 0 ; V_386 < V_627 ; V_386 ++ ) {
* V_638 = V_626 [ V_386 ] ;
if ( * V_638 != V_626 [ V_386 ] )
return false ;
}
for ( V_386 = 0 ; V_386 < V_636 ; V_386 ++ ) {
* V_638 = V_386 * 4 ;
V_638 ++ ;
}
V_638 = ( unsigned long * ) V_2 -> V_388 ;
for ( V_386 = 0 ; V_386 < V_636 ; V_386 ++ ) {
if ( * V_638 != V_386 * 4 )
return false ;
V_638 ++ ;
}
memset ( V_2 -> V_388 , 0 , V_637 ) ;
return true ;
}
static void F_244 ( char * V_639 , const char * V_640 ,
unsigned short V_13 )
{
#define F_250 64
unsigned short V_641 = V_13 / F_250 ;
unsigned short V_604 ;
unsigned long V_642 ;
for ( V_604 = 0 ; V_604 < V_641 ; V_604 ++ )
{
memcpy ( V_639 , V_640 , F_250 ) ;
V_642 = * ( ( volatile unsigned long * ) V_639 ) ;
V_639 += F_250 ;
V_640 += F_250 ;
}
memcpy ( V_639 , V_640 , V_13 % F_250 ) ;
}
static void F_242 ( struct V_1 * V_2 , const char * V_11 , int V_13 , int V_643 )
{
int V_386 ;
int V_644 ;
if ( V_643 )
F_4 ( L_162 , V_2 -> V_21 ) ;
else
F_4 ( L_163 , V_2 -> V_21 ) ;
while( V_13 ) {
if ( V_13 > 16 )
V_644 = 16 ;
else
V_644 = V_13 ;
for( V_386 = 0 ; V_386 < V_644 ; V_386 ++ )
F_4 ( L_164 , ( unsigned char ) V_11 [ V_386 ] ) ;
for(; V_386 < 17 ; V_386 ++ )
F_4 ( L_165 ) ;
for( V_386 = 0 ; V_386 < V_644 ; V_386 ++ ) {
if ( V_11 [ V_386 ] >= 040 && V_11 [ V_386 ] <= 0176 )
F_4 ( L_166 , V_11 [ V_386 ] ) ;
else
F_4 ( L_167 ) ;
}
F_4 ( L_168 ) ;
V_11 += V_644 ;
V_13 -= V_644 ;
}
}
static void V_190 ( unsigned long V_645 )
{
struct V_1 * V_2 = (struct V_1 * ) V_645 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_169 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if( V_2 -> V_43 &&
( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_203 ) ) {
V_2 -> V_54 . V_646 ++ ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_43 = false ;
V_2 -> V_78 = V_2 -> V_79 = V_2 -> V_80 = 0 ;
if ( V_2 -> V_36 . V_12 & V_236 )
F_128 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
#if V_85
if ( V_2 -> V_86 )
F_39 ( V_2 ) ;
else
#endif
F_18 ( V_2 ) ;
}
static int F_147 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_2 -> V_36 . V_12 & V_236 ) {
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
static void F_128 ( struct V_1 * V_2 )
{
F_35 ( V_2 , V_73 ) ;
F_34 ( V_2 , V_72 ) ;
F_23 ( V_2 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
V_2 -> V_53 = true ;
F_27 ( V_2 , V_59 ,
( F_25 ( V_2 , V_59 ) | V_52 ) ) ;
V_2 -> V_56 |= V_57 ;
F_27 ( V_2 , V_58 , V_2 -> V_56 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
return F_25 ( V_2 , V_520 ) & V_296 ? 1 : 0 ;
}
static int F_251 ( struct V_647 * V_648 , unsigned short V_483 ,
unsigned short V_146 )
{
struct V_1 * V_2 = F_252 ( V_648 ) ;
unsigned char V_649 ;
unsigned short V_650 ;
if ( V_2 -> V_42 . V_13 )
return - V_345 ;
switch ( V_483 )
{
case V_651 : V_649 = V_518 ; break;
case V_652 : V_649 = V_486 ; break;
case V_653 : V_649 = V_487 ; break;
case V_654 : V_649 = V_488 ; break;
case V_655 : V_649 = V_489 ; break;
default: return - V_294 ;
}
switch ( V_146 )
{
case V_656 : V_650 = V_657 ; break;
case V_658 : V_650 = V_493 ; break;
case V_659 : V_650 = V_494 ; break;
default: return - V_294 ;
}
V_2 -> V_36 . V_483 = V_649 ;
V_2 -> V_36 . V_491 = V_650 ;
if ( V_2 -> V_86 )
F_87 ( V_2 ) ;
return 0 ;
}
static T_9 F_253 ( struct V_660 * V_661 ,
struct V_647 * V_648 )
{
struct V_1 * V_2 = F_252 ( V_648 ) ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( V_662 L_170 , __FILE__ , V_648 -> V_3 ) ;
F_254 ( V_648 ) ;
V_2 -> V_78 = V_661 -> V_663 ;
F_101 ( V_2 , V_661 -> V_11 , V_661 -> V_663 ) ;
V_648 -> V_613 . V_664 ++ ;
V_648 -> V_613 . V_665 += V_661 -> V_663 ;
F_255 ( V_661 ) ;
V_648 -> V_666 = V_324 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! V_2 -> V_43 )
F_13 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_667 ;
}
static int F_256 ( struct V_647 * V_648 )
{
struct V_1 * V_2 = F_252 ( V_648 ) ;
int V_24 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_171 , __FILE__ , V_648 -> V_3 ) ;
if ( ( V_24 = F_257 ( V_648 ) ) )
return V_24 ;
F_9 ( & V_2 -> V_344 , V_12 ) ;
if ( V_2 -> V_42 . V_13 != 0 || V_2 -> V_86 != 0 ) {
F_4 ( V_668 L_172 , V_648 -> V_3 ) ;
F_11 ( & V_2 -> V_344 , V_12 ) ;
return - V_345 ;
}
V_2 -> V_86 = 1 ;
F_11 ( & V_2 -> V_344 , V_12 ) ;
if ( ( V_24 = F_73 ( V_2 ) ) != 0 ) {
F_9 ( & V_2 -> V_344 , V_12 ) ;
V_2 -> V_86 = 0 ;
F_11 ( & V_2 -> V_344 , V_12 ) ;
return V_24 ;
}
V_2 -> V_83 |= V_84 + V_202 ;
F_87 ( V_2 ) ;
V_648 -> V_666 = V_324 ;
F_258 ( V_648 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( V_2 -> V_83 & V_265 )
F_43 ( V_648 ) ;
else
F_44 ( V_648 ) ;
return 0 ;
}
static int F_259 ( struct V_647 * V_648 )
{
struct V_1 * V_2 = F_252 ( V_648 ) ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_173 , __FILE__ , V_648 -> V_3 ) ;
F_254 ( V_648 ) ;
F_83 ( V_2 ) ;
F_260 ( V_648 ) ;
F_9 ( & V_2 -> V_344 , V_12 ) ;
V_2 -> V_86 = 0 ;
F_11 ( & V_2 -> V_344 , V_12 ) ;
return 0 ;
}
static int F_261 ( struct V_647 * V_648 , struct V_669 * V_670 , int V_299 )
{
const T_10 V_671 = sizeof( V_672 ) ;
V_672 V_673 ;
V_672 T_4 * line = V_670 -> V_674 . V_675 . V_676 ;
struct V_1 * V_2 = F_252 ( V_648 ) ;
unsigned int V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_174 , __FILE__ , V_648 -> V_3 ) ;
if ( V_2 -> V_42 . V_13 )
return - V_345 ;
if ( V_299 != V_677 )
return F_262 ( V_648 , V_670 , V_299 ) ;
switch( V_670 -> V_674 . type ) {
case V_678 :
V_670 -> V_674 . type = V_679 ;
if ( V_670 -> V_674 . V_671 < V_671 ) {
V_670 -> V_674 . V_671 = V_671 ;
return - V_680 ;
}
V_12 = V_2 -> V_36 . V_12 & ( V_681 | V_503 |
V_504 | V_505 |
V_682 | V_506 |
V_507 | V_508 ) ;
switch ( V_12 ) {
case ( V_681 | V_682 ) : V_673 . V_683 = V_684 ; break;
case ( V_504 | V_507 ) : V_673 . V_683 = V_685 ; break;
case ( V_681 | V_507 ) : V_673 . V_683 = V_686 ; break;
case ( V_681 | V_508 ) : V_673 . V_683 = V_687 ; break;
default: V_673 . V_683 = V_688 ;
}
V_673 . V_689 = V_2 -> V_36 . V_516 ;
V_673 . V_580 = V_2 -> V_36 . V_580 ? 1 : 0 ;
if ( F_263 ( line , & V_673 , V_671 ) )
return - V_243 ;
return 0 ;
case V_679 :
if( ! F_78 ( V_690 ) )
return - V_691 ;
if ( F_264 ( & V_673 , line , V_671 ) )
return - V_243 ;
switch ( V_673 . V_683 )
{
case V_684 : V_12 = V_681 | V_682 ; break;
case V_687 : V_12 = V_681 | V_508 ; break;
case V_685 : V_12 = V_504 | V_507 ; break;
case V_686 : V_12 = V_681 | V_507 ; break;
case V_688 : V_12 = V_2 -> V_36 . V_12 &
( V_681 | V_503 |
V_504 | V_505 |
V_682 | V_506 |
V_507 | V_508 ) ; break;
default: return - V_294 ;
}
if ( V_673 . V_580 != 0 && V_673 . V_580 != 1 )
return - V_294 ;
V_2 -> V_36 . V_12 &= ~ ( V_681 | V_503 |
V_504 | V_505 |
V_682 | V_506 |
V_507 | V_508 ) ;
V_2 -> V_36 . V_12 |= V_12 ;
V_2 -> V_36 . V_580 = V_673 . V_580 ;
if ( V_12 & ( V_504 | V_507 ) )
V_2 -> V_36 . V_516 = V_673 . V_689 ;
else
V_2 -> V_36 . V_516 = 0 ;
if ( V_2 -> V_86 )
F_87 ( V_2 ) ;
return 0 ;
default:
return F_262 ( V_648 , V_670 , V_299 ) ;
}
}
static void F_265 ( struct V_647 * V_648 )
{
struct V_1 * V_2 = F_252 ( V_648 ) ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_175 , V_648 -> V_3 ) ;
V_648 -> V_613 . V_692 ++ ;
V_648 -> V_613 . V_693 ++ ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_10 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
F_266 ( V_648 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( F_267 ( V_2 -> V_113 ) )
F_266 ( V_2 -> V_113 ) ;
}
static void F_243 ( struct V_1 * V_2 , char * V_231 , int V_671 )
{
struct V_660 * V_661 = F_268 ( V_671 ) ;
struct V_647 * V_648 = V_2 -> V_113 ;
if ( V_19 >= V_20 )
F_4 ( L_176 , V_648 -> V_3 ) ;
if ( V_661 == NULL ) {
F_4 ( V_694 L_177 ,
V_648 -> V_3 ) ;
V_648 -> V_613 . V_695 ++ ;
return;
}
memcpy ( F_269 ( V_661 , V_671 ) , V_231 , V_671 ) ;
V_661 -> V_696 = F_270 ( V_661 , V_648 ) ;
V_648 -> V_613 . V_697 ++ ;
V_648 -> V_613 . V_698 += V_671 ;
F_271 ( V_661 ) ;
}
static int F_208 ( struct V_1 * V_2 )
{
int V_24 ;
struct V_647 * V_648 ;
T_11 * V_699 ;
if ( ! ( V_648 = F_272 ( V_2 ) ) ) {
F_4 ( V_182 L_178 , __FILE__ ) ;
return - V_189 ;
}
V_648 -> V_700 = V_2 -> V_137 ;
V_648 -> V_457 = V_2 -> V_177 ;
V_648 -> V_458 = V_2 -> V_353 ;
V_648 -> V_701 = & V_702 ;
V_648 -> V_703 = 10 * V_224 ;
V_648 -> V_704 = 50 ;
V_699 = F_273 ( V_648 ) ;
V_699 -> V_705 = F_251 ;
V_699 -> V_643 = F_253 ;
if ( ( V_24 = F_274 ( V_648 ) ) ) {
F_4 ( V_668 L_179 , __FILE__ ) ;
F_275 ( V_648 ) ;
return V_24 ;
}
V_2 -> V_113 = V_648 ;
return 0 ;
}
static void F_224 ( struct V_1 * V_2 )
{
F_276 ( V_2 -> V_113 ) ;
F_275 ( V_2 -> V_113 ) ;
V_2 -> V_113 = NULL ;
}
static int T_12 F_277 ( struct V_706 * V_648 ,
const struct V_707 * V_708 )
{
struct V_1 * V_2 ;
if ( F_278 ( V_648 ) ) {
F_4 ( L_180 , V_648 ) ;
return - V_280 ;
}
if ( ! ( V_2 = F_209 () ) ) {
F_4 ( L_145 ) ;
return - V_280 ;
}
V_2 -> V_137 = F_279 ( V_648 , 2 ) ;
V_2 -> V_177 = V_648 -> V_457 ;
V_2 -> V_351 = F_279 ( V_648 , 3 ) ;
V_2 -> V_352 = F_279 ( V_648 , 0 ) ;
V_2 -> V_420 = V_2 -> V_352 & ( V_423 - 1 ) ;
V_2 -> V_352 &= ~ ( V_423 - 1 ) ;
V_2 -> V_349 = V_350 ;
V_2 -> V_414 = 8 ;
V_2 -> V_416 = V_709 ;
if ( V_648 -> V_710 == 0x0210 ) {
V_2 -> V_572 = 0x007c4080 ;
V_2 -> V_432 = 1 ;
} else {
V_2 -> V_572 = 0x087e4546 ;
V_2 -> V_432 = 0 ;
}
F_207 ( V_2 ) ;
return 0 ;
}
static void T_13 F_280 ( struct V_706 * V_648 )
{
}
