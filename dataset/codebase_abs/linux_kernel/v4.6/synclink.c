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
if ( F_46 ( & V_2 -> V_42 ) &&
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
if ( V_49 & V_122 ) {
F_27 ( V_2 , V_123 ,
( unsigned short ) ( F_25 ( V_2 , V_123 ) & ~ ( V_124 + V_125 ) ) ) ;
F_41 ( V_2 , V_122 ) ;
V_2 -> V_126 = true ;
}
}
static void F_47 ( struct V_1 * V_2 )
{
if ( V_19 >= V_51 )
F_4 ( L_23 ,
__FILE__ , __LINE__ , V_2 -> V_78 ) ;
F_30 ( V_2 , V_127 ) ;
if ( V_2 -> V_42 . V_10 -> V_87 || V_2 -> V_42 . V_10 -> V_88 ) {
F_10 ( V_2 ) ;
return;
}
if ( V_2 -> V_78 )
F_48 ( V_2 ) ;
else
V_2 -> V_43 = false ;
if ( V_2 -> V_78 < V_128 )
V_2 -> V_25 |= V_27 ;
}
static void F_49 ( struct V_1 * V_2 )
{
int V_129 ;
T_2 V_49 ;
int V_32 = 0 ;
unsigned char V_130 ;
struct V_89 * V_54 = & V_2 -> V_54 ;
if ( V_19 >= V_51 )
F_4 ( L_24 ,
__FILE__ , __LINE__ ) ;
F_30 ( V_2 , V_131 ) ;
F_50 ( V_2 , V_132 ) ;
F_27 ( V_2 , V_59 + V_133 , ( T_2 ) ( F_25 ( V_2 , V_59 + V_133 ) & ~ V_134 ) ) ;
while( ( V_129 = ( F_25 ( V_2 , V_59 ) >> 8 ) ) ) {
int V_135 ;
F_51 ( ( F_52 ( V_2 -> V_136 + V_137 ) & 0x0780 ) | ( V_138 + V_133 ) ,
V_2 -> V_136 + V_137 ) ;
V_130 = F_53 ( V_2 -> V_136 + V_137 ) ;
V_49 = F_25 ( V_2 , V_50 ) ;
if ( V_49 & ( V_139 | V_140 |
V_65 | V_141 ) )
F_31 ( V_2 , V_142 ) ;
V_54 -> V_143 ++ ;
V_135 = 0 ;
if ( V_49 & ( V_139 | V_140 |
V_65 | V_141 ) ) {
F_4 ( L_25 , V_49 ) ;
if ( V_49 & V_141 ) {
V_49 &= ~ ( V_139 | V_140 ) ;
V_54 -> V_144 ++ ;
} else if ( V_49 & V_140 )
V_54 -> V_145 ++ ;
else if ( V_49 & V_139 )
V_54 -> V_146 ++ ;
else if ( V_49 & V_65 ) {
F_35 ( V_2 , V_147 ) ;
V_54 -> V_148 ++ ;
}
if ( V_49 & V_2 -> V_149 )
continue;
V_49 &= V_2 -> V_150 ;
if ( V_49 & V_141 ) {
V_135 = V_151 ;
if ( V_2 -> V_42 . V_12 & V_152 )
F_54 ( V_2 -> V_42 . V_10 ) ;
} else if ( V_49 & V_140 )
V_135 = V_153 ;
else if ( V_49 & V_139 )
V_135 = V_154 ;
}
F_55 ( & V_2 -> V_42 , V_130 , V_135 ) ;
if ( V_49 & V_65 ) {
V_32 += F_55 ( & V_2 -> V_42 , 0 , V_155 ) ;
}
}
if ( V_19 >= V_51 ) {
F_4 ( L_26 ,
__FILE__ , __LINE__ , V_54 -> V_143 , V_54 -> V_144 ,
V_54 -> V_145 , V_54 -> V_146 , V_54 -> V_148 ) ;
}
if( V_32 )
F_56 ( & V_2 -> V_42 ) ;
}
static void F_57 ( struct V_1 * V_2 )
{
T_2 V_49 = F_25 ( V_2 , V_90 ) ;
if ( V_19 >= V_51 )
F_4 ( L_27 ,
__FILE__ , __LINE__ , V_49 ) ;
if ( ( V_49 & V_156 ) &&
( V_2 -> V_36 . V_37 == V_38 ) ) {
F_58 ( V_2 , V_157 ) ;
F_34 ( V_2 , V_158 ) ;
F_31 ( V_2 , V_142 ) ;
F_30 ( V_2 , V_131 | V_67 ) ;
F_59 ( V_2 , V_131 | V_67 ) ;
V_2 -> V_25 |= V_26 ;
V_2 -> V_41 = true ;
}
F_30 ( V_2 , V_159 ) ;
F_60 ( V_2 , V_49 ) ;
}
static void F_61 ( struct V_1 * V_2 )
{
}
static void F_62 ( struct V_1 * V_2 )
{
T_2 V_49 ;
F_63 ( V_2 , V_160 , V_161 | V_162 ) ;
V_49 = F_64 ( V_2 , V_163 ) ;
if ( V_19 >= V_51 )
F_4 ( L_28 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_49 ) ;
V_2 -> V_25 |= V_26 ;
if ( V_49 & V_134 ) {
V_2 -> V_164 = true ;
V_2 -> V_54 . V_165 ++ ;
}
}
static void F_65 ( struct V_1 * V_2 )
{
T_2 V_49 ;
F_63 ( V_2 , V_160 , V_166 | V_167 ) ;
V_49 = F_64 ( V_2 , V_168 ) ;
if ( V_19 >= V_51 )
F_4 ( L_29 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_49 ) ;
if ( V_49 & V_169 ) {
-- V_2 -> V_170 ;
if ( F_66 ( V_2 ) ) {
V_2 -> V_25 |= V_27 ;
}
}
}
static T_3 F_67 ( int V_171 , void * V_172 )
{
struct V_1 * V_2 = V_172 ;
T_2 V_173 ;
T_2 V_174 ;
if ( V_19 >= V_51 )
F_4 ( V_175 L_30 ,
__FILE__ , __LINE__ , V_2 -> V_176 ) ;
F_68 ( & V_2 -> V_22 ) ;
for(; ; ) {
V_173 = F_25 ( V_2 , V_177 ) >> 9 ;
V_174 = F_64 ( V_2 , V_178 ) ;
if ( V_19 >= V_51 )
F_4 ( L_31 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_173 , V_174 ) ;
if ( ! V_173 && ! V_174 )
break;
if ( V_173 )
(* F_69 [ V_173 ])( V_2 ) ;
else if ( ( V_174 & ( V_179 | V_161 ) ) == V_179 )
F_65 ( V_2 ) ;
else
F_62 ( V_2 ) ;
if ( V_2 -> V_180 ) {
F_4 ( V_181 L_32 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_176 ) ;
F_70 ( V_2 ) ;
F_71 ( V_2 , V_182 ) ;
break;
}
}
if ( V_2 -> V_25 && ! V_2 -> V_29 && ! V_2 -> V_30 ) {
if ( V_19 >= V_51 )
F_4 ( L_33 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_72 ( & V_2 -> V_33 ) ;
V_2 -> V_30 = true ;
}
F_73 ( & V_2 -> V_22 ) ;
if ( V_19 >= V_51 )
F_4 ( V_175 L_34 ,
__FILE__ , __LINE__ , V_2 -> V_176 ) ;
return V_183 ;
}
static int F_74 ( struct V_1 * V_2 )
{
int V_184 = 0 ;
if ( V_19 >= V_20 )
F_4 ( L_35 , __FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( V_2 -> V_42 . V_12 & V_185 )
return 0 ;
if ( ! V_2 -> V_186 ) {
V_2 -> V_186 = ( unsigned char * ) F_75 ( V_187 ) ;
if ( ! V_2 -> V_186 ) {
F_4 ( V_181 L_36 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return - V_188 ;
}
}
V_2 -> V_25 = 0 ;
memset ( & V_2 -> V_54 , 0 , sizeof( V_2 -> V_54 ) ) ;
F_76 ( & V_2 -> V_81 , V_189 , ( unsigned long ) V_2 ) ;
V_184 = F_77 ( V_2 ) ;
if ( ! V_184 )
V_184 = F_78 ( V_2 ) ;
if ( V_184 ) {
if ( F_79 ( V_190 ) && V_2 -> V_42 . V_10 )
F_80 ( V_191 , & V_2 -> V_42 . V_10 -> V_12 ) ;
F_81 ( V_2 ) ;
return V_184 ;
}
F_82 ( V_2 ) ;
if ( V_2 -> V_42 . V_10 )
F_83 ( V_191 , & V_2 -> V_42 . V_10 -> V_12 ) ;
V_2 -> V_42 . V_12 |= V_185 ;
return 0 ;
}
static void F_84 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
if ( ! ( V_2 -> V_42 . V_12 & V_185 ) )
return;
if ( V_19 >= V_20 )
F_4 ( L_37 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_28 ( & V_2 -> V_119 ) ;
F_28 ( & V_2 -> V_64 ) ;
F_85 ( & V_2 -> V_81 ) ;
if ( V_2 -> V_186 ) {
F_86 ( ( unsigned long ) V_2 -> V_186 ) ;
V_2 -> V_186 = NULL ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_70 ( V_2 ) ;
F_87 ( V_2 ) ;
F_10 ( V_2 ) ;
F_59 ( V_2 , V_131 | V_67 |
V_127 | V_69 | V_91 | V_159 ) ;
F_71 ( V_2 , V_182 + V_192 + V_193 ) ;
F_27 ( V_2 , V_194 , ( T_2 ) ( ( F_25 ( V_2 , V_194 ) | V_195 ) | V_196 ) ) ;
F_27 ( V_2 , V_194 , ( T_2 ) ( ( F_25 ( V_2 , V_194 ) | V_57 ) | V_197 ) ) ;
if ( ! V_2 -> V_42 . V_10 || V_2 -> V_42 . V_10 -> V_198 . V_199 & V_200 ) {
V_2 -> V_83 &= ~ ( V_84 | V_201 ) ;
F_38 ( V_2 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
F_81 ( V_2 ) ;
if ( V_2 -> V_42 . V_10 )
F_80 ( V_191 , & V_2 -> V_42 . V_10 -> V_12 ) ;
V_2 -> V_42 . V_12 &= ~ V_185 ;
}
static void F_88 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_87 ( V_2 ) ;
F_10 ( V_2 ) ;
V_2 -> V_78 = V_2 -> V_79 = V_2 -> V_80 = 0 ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_202 ||
V_2 -> V_86 )
F_89 ( V_2 ) ;
else
F_90 ( V_2 ) ;
F_38 ( V_2 ) ;
V_2 -> V_47 = 0 ;
V_2 -> V_48 = 0 ;
V_2 -> V_45 = 0 ;
V_2 -> V_46 = 0 ;
F_91 ( V_2 , V_114 + V_103 + V_108 + V_97 ) ;
F_92 ( V_2 , V_91 ) ;
F_37 ( V_2 ) ;
if ( V_2 -> V_86 || V_2 -> V_42 . V_10 -> V_198 . V_199 & V_203 )
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static void F_82 ( struct V_1 * V_2 )
{
unsigned V_204 ;
int V_205 ;
if ( ! V_2 -> V_42 . V_10 )
return;
if ( V_19 >= V_20 )
F_4 ( L_38 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
V_204 = V_2 -> V_42 . V_10 -> V_198 . V_199 ;
if ( V_204 & V_206 )
V_2 -> V_83 |= V_84 | V_201 ;
else
V_2 -> V_83 &= ~ ( V_84 | V_201 ) ;
switch ( V_204 & V_207 ) {
case V_208 : V_2 -> V_36 . V_209 = 5 ; break;
case V_210 : V_2 -> V_36 . V_209 = 6 ; break;
case V_211 : V_2 -> V_36 . V_209 = 7 ; break;
case V_212 : V_2 -> V_36 . V_209 = 8 ; break;
default: V_2 -> V_36 . V_209 = 7 ; break;
}
if ( V_204 & V_213 )
V_2 -> V_36 . V_214 = 2 ;
else
V_2 -> V_36 . V_214 = 1 ;
V_2 -> V_36 . V_145 = V_215 ;
if ( V_204 & V_216 ) {
if ( V_204 & V_217 )
V_2 -> V_36 . V_145 = V_218 ;
else
V_2 -> V_36 . V_145 = V_219 ;
#ifdef F_93
if ( V_204 & F_93 )
V_2 -> V_36 . V_145 = V_220 ;
#endif
}
V_205 = V_2 -> V_36 . V_209 +
V_2 -> V_36 . V_214 + 1 ;
if ( V_2 -> V_36 . V_221 <= 460800 )
V_2 -> V_36 . V_221 = F_94 ( V_2 -> V_42 . V_10 ) ;
if ( V_2 -> V_36 . V_221 ) {
V_2 -> V_222 = ( 32 * V_223 * V_205 ) /
V_2 -> V_36 . V_221 ;
}
V_2 -> V_222 += V_223 / 50 ;
if ( V_204 & V_224 )
V_2 -> V_42 . V_12 |= V_225 ;
else
V_2 -> V_42 . V_12 &= ~ V_225 ;
if ( V_204 & V_226 )
V_2 -> V_42 . V_12 &= ~ V_120 ;
else
V_2 -> V_42 . V_12 |= V_120 ;
V_2 -> V_150 = V_65 ;
if ( F_95 ( V_2 -> V_42 . V_10 ) )
V_2 -> V_150 |= V_140 | V_139 ;
if ( F_96 ( V_2 -> V_42 . V_10 ) || F_97 ( V_2 -> V_42 . V_10 ) )
V_2 -> V_150 |= V_141 ;
if ( F_98 ( V_2 -> V_42 . V_10 ) )
V_2 -> V_149 |= V_140 | V_139 ;
if ( F_99 ( V_2 -> V_42 . V_10 ) ) {
V_2 -> V_149 |= V_141 ;
if ( F_98 ( V_2 -> V_42 . V_10 ) )
V_2 -> V_149 |= V_65 ;
}
F_88 ( V_2 ) ;
}
static int F_100 ( struct V_9 * V_10 , unsigned char V_227 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
int V_228 = 0 ;
if ( V_19 >= V_20 ) {
F_4 ( V_175 L_39 ,
__FILE__ , __LINE__ , V_227 , V_2 -> V_21 ) ;
}
if ( F_2 ( V_2 , V_10 -> V_3 , L_40 ) )
return 0 ;
if ( ! V_2 -> V_186 )
return 0 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ( V_2 -> V_36 . V_37 == V_229 ) || ! V_2 -> V_43 ) {
if ( V_2 -> V_78 < V_230 - 1 ) {
V_2 -> V_186 [ V_2 -> V_79 ++ ] = V_227 ;
V_2 -> V_79 &= V_230 - 1 ;
V_2 -> V_78 ++ ;
V_228 = 1 ;
}
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_228 ;
}
static void F_101 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_41 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_78 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_42 ) )
return;
if ( V_2 -> V_78 <= 0 || V_10 -> V_87 || V_10 -> V_88 ||
! V_2 -> V_186 )
return;
if ( V_19 >= V_20 )
F_4 ( L_43 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! V_2 -> V_43 ) {
if ( ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_202 ) && V_2 -> V_78 ) {
F_102 ( V_2 ,
V_2 -> V_186 , V_2 -> V_78 ) ;
}
F_13 ( V_2 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static int F_103 ( struct V_9 * V_10 ,
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
if ( ! V_2 -> V_186 )
goto V_233;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_202 ) {
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
F_104 ( V_2 , V_231 , V_13 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_66 ( V_2 ) ;
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
F_102 ( V_2 ,
V_2 -> V_186 , V_2 -> V_78 ) ;
if ( V_19 >= V_20 )
F_4 ( L_46 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
} else {
if ( V_19 >= V_20 )
F_4 ( L_47 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
V_228 = V_13 ;
V_2 -> V_78 = V_13 ;
F_102 ( V_2 , V_231 , V_13 ) ;
}
} else {
while ( 1 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_232 = F_105 ( int , V_13 ,
F_106 ( V_230 - V_2 -> V_78 - 1 ,
V_230 - V_2 -> V_79 ) ) ;
if ( V_232 <= 0 ) {
F_11 ( & V_2 -> V_22 , V_12 ) ;
break;
}
memcpy ( V_2 -> V_186 + V_2 -> V_79 , V_231 , V_232 ) ;
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
static int F_107 ( struct V_9 * V_10 )
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
V_2 -> V_36 . V_37 == V_202 ) {
if ( V_2 -> V_43 )
return 0 ;
else
return V_237 ;
}
return V_228 ;
}
static int F_108 ( struct V_9 * V_10 )
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
V_2 -> V_36 . V_37 == V_202 ) {
if ( V_2 -> V_43 )
return V_2 -> V_238 ;
else
return 0 ;
}
return V_2 -> V_78 ;
}
static void F_109 ( struct V_9 * V_10 )
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
static void F_110 ( struct V_9 * V_10 , char V_227 )
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
static void F_111 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_58 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_59 ) )
return;
if ( F_112 ( V_10 ) )
F_110 ( V_10 , F_113 ( V_10 ) ) ;
if ( F_114 ( V_10 ) ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_83 &= ~ V_84 ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
static void F_115 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_60 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_61 ) )
return;
if ( F_112 ( V_10 ) ) {
if ( V_2 -> V_239 )
V_2 -> V_239 = 0 ;
else
F_110 ( V_10 , F_116 ( V_10 ) ) ;
}
if ( F_114 ( V_10 ) ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_83 |= V_84 ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
static int F_117 ( struct V_1 * V_2 , struct V_89 T_4 * V_240 )
{
int V_241 ;
if ( V_19 >= V_20 )
F_4 ( L_62 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( ! V_240 ) {
memset ( & V_2 -> V_54 , 0 , sizeof( V_2 -> V_54 ) ) ;
} else {
F_118 ( & V_2 -> V_42 . V_242 ) ;
F_119 ( V_241 , V_240 , & V_2 -> V_54 , sizeof( struct V_89 ) ) ;
F_120 ( & V_2 -> V_42 . V_242 ) ;
if ( V_241 )
return - V_243 ;
}
return 0 ;
}
static int F_121 ( struct V_1 * V_2 , T_5 T_4 * V_244 )
{
int V_241 ;
if ( V_19 >= V_20 )
F_4 ( L_62 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_118 ( & V_2 -> V_42 . V_242 ) ;
F_119 ( V_241 , V_244 , & V_2 -> V_36 , sizeof( T_5 ) ) ;
F_120 ( & V_2 -> V_42 . V_242 ) ;
if ( V_241 ) {
if ( V_19 >= V_20 )
F_4 ( L_63 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return - V_243 ;
}
return 0 ;
}
static int F_122 ( struct V_1 * V_2 , T_5 T_4 * V_245 )
{
unsigned long V_12 ;
T_5 V_246 ;
int V_241 ;
if ( V_19 >= V_20 )
F_4 ( L_64 , __FILE__ , __LINE__ ,
V_2 -> V_21 ) ;
F_123 ( V_241 , & V_246 , V_245 , sizeof( T_5 ) ) ;
if ( V_241 ) {
if ( V_19 >= V_20 )
F_4 ( L_65 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return - V_243 ;
}
F_118 ( & V_2 -> V_42 . V_242 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
memcpy ( & V_2 -> V_36 , & V_246 , sizeof( T_5 ) ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
F_82 ( V_2 ) ;
F_120 ( & V_2 -> V_42 . V_242 ) ;
return 0 ;
}
static int F_124 ( struct V_1 * V_2 , int T_4 * V_247 )
{
int V_241 ;
if ( V_19 >= V_20 )
F_4 ( L_66 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_247 ) ;
F_119 ( V_241 , V_247 , & V_2 -> V_247 , sizeof( int ) ) ;
if ( V_241 ) {
if ( V_19 >= V_20 )
F_4 ( L_67 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return - V_243 ;
}
return 0 ;
}
static int F_125 ( struct V_1 * V_2 , int V_247 )
{
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_68 , __FILE__ , __LINE__ ,
V_2 -> V_21 , V_247 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_247 = V_247 ;
F_126 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_127 ( struct V_1 * V_2 , int V_248 )
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
F_128 ( V_2 ) ;
}
} else {
if ( V_2 -> V_23 )
F_10 ( V_2 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_129 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_70 , __FILE__ , __LINE__ ,
V_2 -> V_21 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_2 -> V_43 && V_2 -> V_36 . V_37 == V_38 )
{
if ( V_2 -> V_36 . V_12 & V_236 )
F_130 ( V_2 ) ;
else
F_131 ( V_2 , V_249 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_132 ( struct V_1 * V_2 , int V_248 )
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
F_87 ( V_2 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_133 ( struct V_1 * V_2 , int T_4 * V_251 )
{
unsigned long V_12 ;
int V_252 ;
int V_24 = 0 ;
struct V_89 V_253 , V_254 ;
int V_255 ;
int V_256 ;
struct V_257 V_258 , V_259 ;
F_134 ( V_260 , V_261 ) ;
F_123 ( V_24 , & V_256 , V_251 , sizeof( int ) ) ;
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
F_135 ( V_278 ) ;
F_136 ( & V_2 -> V_64 , & V_260 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
for(; ; ) {
F_137 () ;
if ( F_138 ( V_261 ) ) {
V_24 = - V_279 ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_254 = V_2 -> V_54 ;
V_259 = V_2 -> V_100 ;
F_135 ( V_278 ) ;
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
F_139 ( & V_2 -> V_64 , & V_260 ) ;
F_135 ( V_281 ) ;
if ( V_256 & ( V_274 + V_275 ) ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! F_140 ( & V_2 -> V_64 ) ) {
F_27 ( V_2 , V_59 , F_25 ( V_2 , V_59 ) &
~ ( V_60 | V_61 ) ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
exit:
if ( V_24 == 0 )
F_141 ( V_24 , V_255 , V_251 ) ;
return V_24 ;
}
static int F_142 ( struct V_1 * V_2 , int V_282 )
{
unsigned long V_12 ;
int V_24 ;
struct V_89 V_253 , V_254 ;
F_134 ( V_260 , V_261 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_253 = V_2 -> V_54 ;
F_136 ( & V_2 -> V_119 , & V_260 ) ;
F_135 ( V_278 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
for(; ; ) {
F_137 () ;
if ( F_138 ( V_261 ) ) {
V_24 = - V_279 ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_254 = V_2 -> V_54 ;
F_135 ( V_278 ) ;
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
F_139 ( & V_2 -> V_119 , & V_260 ) ;
F_135 ( V_281 ) ;
return V_24 ;
}
static int F_143 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned int V_287 ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_287 = ( ( V_2 -> V_83 & V_84 ) ? V_288 : 0 ) +
( ( V_2 -> V_83 & V_201 ) ? V_289 : 0 ) +
( ( V_2 -> V_83 & V_265 ) ? V_290 : 0 ) +
( ( V_2 -> V_83 & V_271 ) ? V_283 : 0 ) +
( ( V_2 -> V_83 & V_262 ) ? V_284 : 0 ) +
( ( V_2 -> V_83 & V_268 ) ? V_286 : 0 ) ;
if ( V_19 >= V_20 )
F_4 ( L_73 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_287 ) ;
return V_287 ;
}
static int F_144 ( struct V_9 * V_10 ,
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
V_2 -> V_83 |= V_201 ;
if ( V_292 & V_288 )
V_2 -> V_83 &= ~ V_84 ;
if ( V_292 & V_289 )
V_2 -> V_83 &= ~ V_201 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_145 ( struct V_9 * V_10 , int V_293 )
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
static int F_146 ( struct V_9 * V_10 ,
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
V_54 -> V_143 = V_254 . V_143 ;
V_54 -> V_298 = V_254 . V_298 ;
V_54 -> V_146 = V_254 . V_146 ;
V_54 -> V_148 = V_254 . V_148 ;
V_54 -> V_145 = V_254 . V_145 ;
V_54 -> V_144 = V_254 . V_144 ;
V_54 -> V_165 = V_254 . V_165 ;
return 0 ;
}
static int F_147 ( struct V_9 * V_10 ,
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
if ( V_10 -> V_12 & ( 1 << V_191 ) )
return - V_280 ;
}
return F_148 ( V_2 , V_299 , V_282 ) ;
}
static int F_148 ( struct V_1 * V_2 , unsigned int V_299 , unsigned long V_282 )
{
void T_4 * V_304 = ( void T_4 * ) V_282 ;
switch ( V_299 ) {
case V_305 :
return F_121 ( V_2 , V_304 ) ;
case V_306 :
return F_122 ( V_2 , V_304 ) ;
case V_307 :
return F_124 ( V_2 , V_304 ) ;
case V_308 :
return F_125 ( V_2 , ( int ) V_282 ) ;
case V_309 :
return F_127 ( V_2 , ( int ) V_282 ) ;
case V_310 :
return F_132 ( V_2 , ( int ) V_282 ) ;
case V_311 :
return F_129 ( V_2 ) ;
case V_312 :
return F_117 ( V_2 , V_304 ) ;
case V_313 :
return F_133 ( V_2 , V_304 ) ;
case V_314 :
return F_149 ( V_2 ) ;
case V_303 :
return F_142 ( V_2 , ( int ) V_282 ) ;
default:
return - V_315 ;
}
return 0 ;
}
static void F_150 ( struct V_9 * V_10 , struct V_316 * V_317 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_79 , __FILE__ , __LINE__ ,
V_10 -> V_318 -> V_3 ) ;
F_82 ( V_2 ) ;
if ( ( V_317 -> V_199 & V_206 ) && ! F_151 ( V_10 ) ) {
V_2 -> V_83 &= ~ ( V_84 | V_201 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
if ( ! ( V_317 -> V_199 & V_206 ) && F_151 ( V_10 ) ) {
V_2 -> V_83 |= V_201 ;
if ( ! F_114 ( V_10 ) || ! F_152 ( V_319 , & V_10 -> V_12 ) )
V_2 -> V_83 |= V_84 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
if ( V_317 -> V_199 & V_224 && ! F_114 ( V_10 ) ) {
V_10 -> V_88 = 0 ;
F_12 ( V_10 ) ;
}
}
static void F_153 ( struct V_9 * V_10 , struct V_320 * V_321 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_80 ) )
return;
if ( V_19 >= V_20 )
F_4 ( L_81 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_42 . V_13 ) ;
if ( F_154 ( & V_2 -> V_42 , V_10 , V_321 ) == 0 )
goto V_233;
F_118 ( & V_2 -> V_42 . V_242 ) ;
if ( V_2 -> V_42 . V_12 & V_185 )
F_155 ( V_10 , V_2 -> V_222 ) ;
F_109 ( V_10 ) ;
F_156 ( V_10 ) ;
F_84 ( V_2 ) ;
F_120 ( & V_2 -> V_42 . V_242 ) ;
F_157 ( & V_2 -> V_42 , V_10 ) ;
V_2 -> V_42 . V_10 = NULL ;
V_233:
if ( V_19 >= V_20 )
F_4 ( L_82 , __FILE__ , __LINE__ ,
V_10 -> V_318 -> V_3 , V_2 -> V_42 . V_13 ) ;
}
static void F_155 ( struct V_9 * V_10 , int V_222 )
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
if ( ! ( V_2 -> V_42 . V_12 & V_185 ) )
goto exit;
V_322 = V_324 ;
if ( V_2 -> V_36 . V_221 ) {
V_323 = V_2 -> V_222 / ( 32 * 5 ) ;
if ( ! V_323 )
V_323 ++ ;
} else
V_323 = 1 ;
if ( V_222 )
V_323 = F_105 (unsigned long, char_time, timeout) ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_202 ) {
while ( V_2 -> V_43 ) {
F_158 ( F_159 ( V_323 ) ) ;
if ( F_138 ( V_261 ) )
break;
if ( V_222 && F_160 ( V_324 , V_322 + V_222 ) )
break;
}
} else {
while ( ! ( F_25 ( V_2 , V_68 ) & V_325 ) &&
V_2 -> V_23 ) {
F_158 ( F_159 ( V_323 ) ) ;
if ( F_138 ( V_261 ) )
break;
if ( V_222 && F_160 ( V_324 , V_322 + V_222 ) )
break;
}
}
exit:
if ( V_19 >= V_20 )
F_4 ( L_85 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
}
static void F_161 ( struct V_9 * V_10 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
if ( V_19 >= V_20 )
F_4 ( L_86 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_87 ) )
return;
F_109 ( V_10 ) ;
F_84 ( V_2 ) ;
V_2 -> V_42 . V_13 = 0 ;
V_2 -> V_42 . V_12 &= ~ V_326 ;
V_2 -> V_42 . V_10 = NULL ;
F_28 ( & V_2 -> V_42 . V_121 ) ;
}
static int F_162 ( struct V_327 * V_42 )
{
unsigned long V_12 ;
struct V_1 * V_2 = F_16 ( V_42 , struct V_1 , V_42 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return ( V_2 -> V_83 & V_265 ) ? 1 : 0 ;
}
static void F_163 ( struct V_327 * V_42 , int V_328 )
{
struct V_1 * V_2 = F_16 ( V_42 , struct V_1 , V_42 ) ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_328 )
V_2 -> V_83 |= V_84 | V_201 ;
else
V_2 -> V_83 &= ~ ( V_84 | V_201 ) ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static int F_164 ( struct V_9 * V_10 , struct V_320 * V_321 ,
struct V_1 * V_2 )
{
F_134 ( V_260 , V_261 ) ;
int V_184 ;
bool V_329 = false ;
unsigned long V_12 ;
int V_109 ;
struct V_327 * V_42 = & V_2 -> V_42 ;
if ( V_19 >= V_20 )
F_4 ( L_88 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_3 ) ;
if ( V_321 -> V_330 & V_331 || V_10 -> V_12 & ( 1 << V_191 ) ) {
V_42 -> V_12 |= V_326 ;
return 0 ;
}
if ( F_165 ( V_10 ) )
V_329 = true ;
V_184 = 0 ;
F_136 ( & V_42 -> V_121 , & V_260 ) ;
if ( V_19 >= V_20 )
F_4 ( L_89 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_3 , V_42 -> V_13 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_42 -> V_13 -- ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_42 -> V_332 ++ ;
while ( 1 ) {
if ( F_151 ( V_10 ) && F_152 ( V_333 , & V_42 -> V_12 ) )
F_166 ( V_42 ) ;
F_135 ( V_278 ) ;
if ( F_167 ( V_321 ) || ! ( V_42 -> V_12 & V_185 ) ) {
V_184 = ( V_42 -> V_12 & V_334 ) ?
- V_335 : - V_279 ;
break;
}
V_109 = F_168 ( & V_2 -> V_42 ) ;
if ( V_329 || V_109 )
break;
if ( F_138 ( V_261 ) ) {
V_184 = - V_279 ;
break;
}
if ( V_19 >= V_20 )
F_4 ( L_90 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_3 , V_42 -> V_13 ) ;
F_169 ( V_10 ) ;
F_137 () ;
F_170 ( V_10 ) ;
}
F_135 ( V_281 ) ;
F_139 ( & V_42 -> V_121 , & V_260 ) ;
if ( ! F_167 ( V_321 ) )
V_42 -> V_13 ++ ;
V_42 -> V_332 -- ;
if ( V_19 >= V_20 )
F_4 ( L_91 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_3 , V_42 -> V_13 ) ;
if ( ! V_184 )
V_42 -> V_12 |= V_326 ;
return V_184 ;
}
static int F_171 ( struct V_336 * V_318 , struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int line = V_10 -> V_337 ;
if ( line >= V_338 ) {
F_4 ( L_92 ,
__FILE__ , __LINE__ , line ) ;
return - V_300 ;
}
V_2 = V_339 ;
while ( V_2 && V_2 -> line != line )
V_2 = V_2 -> V_340 ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_93 ) )
return - V_300 ;
V_10 -> V_18 = V_2 ;
return F_172 ( & V_2 -> V_42 , V_318 , V_10 ) ;
}
static int F_173 ( struct V_9 * V_10 , struct V_320 * V_321 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
int V_184 ;
V_2 -> V_42 . V_10 = V_10 ;
if ( V_19 >= V_20 )
F_4 ( L_94 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_3 , V_2 -> V_42 . V_13 ) ;
V_2 -> V_42 . V_341 = ( V_2 -> V_42 . V_12 & V_342 ) ? 1 : 0 ;
F_9 ( & V_2 -> V_343 , V_12 ) ;
if ( V_2 -> V_86 ) {
V_184 = - V_344 ;
F_11 ( & V_2 -> V_343 , V_12 ) ;
goto V_233;
}
V_2 -> V_42 . V_13 ++ ;
F_11 ( & V_2 -> V_343 , V_12 ) ;
if ( V_2 -> V_42 . V_13 == 1 ) {
V_184 = F_74 ( V_2 ) ;
if ( V_184 < 0 )
goto V_233;
}
V_184 = F_164 ( V_10 , V_321 , V_2 ) ;
if ( V_184 ) {
if ( V_19 >= V_20 )
F_4 ( L_95 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_184 ) ;
goto V_233;
}
if ( V_19 >= V_20 )
F_4 ( L_96 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
V_184 = 0 ;
V_233:
if ( V_184 ) {
if ( V_10 -> V_13 == 1 )
V_2 -> V_42 . V_10 = NULL ;
if( V_2 -> V_42 . V_13 )
V_2 -> V_42 . V_13 -- ;
}
return V_184 ;
}
static inline void F_174 ( struct V_345 * V_346 , struct V_1 * V_2 )
{
char V_347 [ 30 ] ;
unsigned long V_12 ;
if ( V_2 -> V_348 == V_349 ) {
F_175 ( V_346 , L_97 ,
V_2 -> V_21 , V_2 -> V_136 , V_2 -> V_176 ,
V_2 -> V_350 , V_2 -> V_351 ) ;
} else {
F_175 ( V_346 , L_98 ,
V_2 -> V_21 , V_2 -> V_136 ,
V_2 -> V_176 , V_2 -> V_352 ) ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_347 [ 0 ] = 0 ;
V_347 [ 1 ] = 0 ;
if ( V_2 -> V_83 & V_84 )
strcat ( V_347 , L_99 ) ;
if ( V_2 -> V_83 & V_268 )
strcat ( V_347 , L_100 ) ;
if ( V_2 -> V_83 & V_201 )
strcat ( V_347 , L_101 ) ;
if ( V_2 -> V_83 & V_262 )
strcat ( V_347 , L_102 ) ;
if ( V_2 -> V_83 & V_265 )
strcat ( V_347 , L_103 ) ;
if ( V_2 -> V_83 & V_271 )
strcat ( V_347 , L_104 ) ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_202 ) {
F_175 ( V_346 , L_105 ,
V_2 -> V_54 . V_75 , V_2 -> V_54 . V_353 ) ;
if ( V_2 -> V_54 . V_76 )
F_175 ( V_346 , L_106 , V_2 -> V_54 . V_76 ) ;
if ( V_2 -> V_54 . V_77 )
F_175 ( V_346 , L_107 , V_2 -> V_54 . V_77 ) ;
if ( V_2 -> V_54 . V_354 )
F_175 ( V_346 , L_108 , V_2 -> V_54 . V_354 ) ;
if ( V_2 -> V_54 . V_355 )
F_175 ( V_346 , L_109 , V_2 -> V_54 . V_355 ) ;
if ( V_2 -> V_54 . V_66 )
F_175 ( V_346 , L_110 , V_2 -> V_54 . V_66 ) ;
if ( V_2 -> V_54 . V_356 )
F_175 ( V_346 , L_111 , V_2 -> V_54 . V_356 ) ;
} else {
F_175 ( V_346 , L_112 ,
V_2 -> V_54 . V_298 , V_2 -> V_54 . V_143 ) ;
if ( V_2 -> V_54 . V_146 )
F_175 ( V_346 , L_113 , V_2 -> V_54 . V_146 ) ;
if ( V_2 -> V_54 . V_145 )
F_175 ( V_346 , L_114 , V_2 -> V_54 . V_145 ) ;
if ( V_2 -> V_54 . V_144 )
F_175 ( V_346 , L_115 , V_2 -> V_54 . V_144 ) ;
if ( V_2 -> V_54 . V_148 )
F_175 ( V_346 , L_116 , V_2 -> V_54 . V_148 ) ;
}
F_175 ( V_346 , L_117 , V_347 + 1 ) ;
F_175 ( V_346 , L_118 ,
V_2 -> V_43 , V_2 -> V_30 , V_2 -> V_29 ,
V_2 -> V_25 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
{
T_2 V_357 = F_25 ( V_2 , V_68 ) ;
T_2 V_358 = F_64 ( V_2 , V_168 ) ;
T_2 V_359 = F_25 ( V_2 , V_360 ) ;
T_2 V_361 = F_25 ( V_2 , V_50 ) ;
T_2 V_362 = F_64 ( V_2 , V_163 ) ;
T_2 V_363 = F_25 ( V_2 , V_59 ) ;
T_2 V_364 = F_25 ( V_2 , V_365 ) ;
T_2 V_366 = F_25 ( V_2 , V_367 ) ;
T_2 V_368 = F_25 ( V_2 , V_369 ) ;
T_2 V_370 = F_25 ( V_2 , V_371 ) ;
T_2 V_372 = F_52 ( V_2 -> V_136 + V_137 ) ;
F_175 ( V_346 , L_119
L_120 ,
V_357 , V_358 , V_359 , V_361 , V_362 , V_363 , V_364 , V_366 , V_368 , V_370 , V_372 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static int F_176 ( struct V_345 * V_346 , void * V_373 )
{
struct V_1 * V_2 ;
F_175 ( V_346 , L_121 , V_374 ) ;
V_2 = V_339 ;
while( V_2 ) {
F_174 ( V_346 , V_2 ) ;
V_2 = V_2 -> V_340 ;
}
return 0 ;
}
static int F_177 ( struct V_375 * V_375 , struct V_320 * V_320 )
{
return F_178 ( V_320 , F_176 , NULL ) ;
}
static int F_179 ( struct V_1 * V_2 )
{
unsigned short V_376 ;
V_2 -> V_377 = 0 ;
V_376 = ( unsigned short ) ( V_2 -> V_238 / V_378 ) ;
if ( V_2 -> V_238 % V_378 )
V_376 ++ ;
if ( V_2 -> V_348 == V_349 ) {
V_2 -> V_379 = V_2 -> V_380 * V_376 ;
V_2 -> V_381 = 62 - V_2 -> V_379 ;
} else {
V_2 -> V_379 = V_2 -> V_380 * V_376 ;
V_2 -> V_381 = ( V_376 * V_382 ) + 6 ;
if ( ( V_2 -> V_379 + V_2 -> V_381 ) > 62 )
V_2 -> V_381 = 62 - V_2 -> V_379 ;
}
if ( V_19 >= V_20 )
F_4 ( L_122 ,
__FILE__ , __LINE__ , V_2 -> V_379 , V_2 -> V_381 ) ;
if ( F_180 ( V_2 ) < 0 ||
F_181 ( V_2 , V_2 -> V_383 , V_2 -> V_381 ) < 0 ||
F_181 ( V_2 , V_2 -> V_384 , V_2 -> V_379 ) < 0 ||
F_182 ( V_2 ) < 0 ||
F_183 ( V_2 ) < 0 ) {
F_4 ( L_123 , __FILE__ , __LINE__ ) ;
return - V_188 ;
}
F_184 ( V_2 ) ;
F_185 ( V_2 ) ;
return 0 ;
}
static int F_180 ( struct V_1 * V_2 )
{
unsigned int V_385 ;
if ( V_2 -> V_348 == V_349 ) {
V_2 -> V_386 = V_2 -> V_387 + V_2 -> V_377 ;
V_2 -> V_388 = V_2 -> V_377 ;
V_2 -> V_377 += V_389 ;
} else {
V_2 -> V_386 = F_186 ( NULL , V_389 , & V_2 -> V_390 , V_187 ) ;
if ( V_2 -> V_386 == NULL )
return - V_188 ;
V_2 -> V_388 = ( V_391 ) ( V_2 -> V_390 ) ;
}
memset ( V_2 -> V_386 , 0 , V_389 ) ;
V_2 -> V_383 = ( V_392 * ) V_2 -> V_386 ;
V_2 -> V_384 = ( V_392 * ) V_2 -> V_386 ;
V_2 -> V_384 += V_2 -> V_381 ;
for ( V_385 = 0 ; V_385 < V_2 -> V_381 ; V_385 ++ ) {
V_2 -> V_383 [ V_385 ] . V_393 =
V_2 -> V_388 + ( V_385 * sizeof( V_392 ) ) ;
V_2 -> V_383 [ V_385 ] . V_394 = V_2 -> V_388 ;
if ( V_385 < V_2 -> V_381 - 1 )
V_2 -> V_383 [ V_385 ] . V_394 += ( V_385 + 1 ) * sizeof( V_392 ) ;
}
for ( V_385 = 0 ; V_385 < V_2 -> V_379 ; V_385 ++ ) {
V_2 -> V_384 [ V_385 ] . V_393 = V_2 -> V_388 +
( ( V_2 -> V_381 + V_385 ) * sizeof( V_392 ) ) ;
V_2 -> V_384 [ V_385 ] . V_394 = V_2 -> V_388 +
V_2 -> V_381 * sizeof( V_392 ) ;
if ( V_385 < V_2 -> V_379 - 1 )
V_2 -> V_384 [ V_385 ] . V_394 += ( V_385 + 1 ) * sizeof( V_392 ) ;
}
return 0 ;
}
static void F_187 ( struct V_1 * V_2 )
{
if ( V_2 -> V_386 && V_2 -> V_348 != V_349 )
F_188 ( NULL , V_389 , V_2 -> V_386 , V_2 -> V_390 ) ;
V_2 -> V_386 = NULL ;
V_2 -> V_383 = NULL ;
V_2 -> V_384 = NULL ;
}
static int F_181 ( struct V_1 * V_2 , V_392 * V_395 , int V_396 )
{
int V_385 ;
V_391 V_397 ;
for ( V_385 = 0 ; V_385 < V_396 ; V_385 ++ ) {
if ( V_2 -> V_348 == V_349 ) {
V_395 [ V_385 ] . V_398 = V_2 -> V_387 + V_2 -> V_377 ;
V_397 = V_2 -> V_377 ;
V_2 -> V_377 += V_378 ;
} else {
V_395 [ V_385 ] . V_398 = F_186 ( NULL , V_378 , & V_395 [ V_385 ] . V_399 , V_187 ) ;
if ( V_395 [ V_385 ] . V_398 == NULL )
return - V_188 ;
V_397 = ( V_391 ) ( V_395 [ V_385 ] . V_399 ) ;
}
V_395 [ V_385 ] . V_397 = V_397 ;
}
return 0 ;
}
static void F_189 ( struct V_1 * V_2 , V_392 * V_395 , int V_396 )
{
int V_385 ;
if ( V_395 ) {
for ( V_385 = 0 ; V_385 < V_396 ; V_385 ++ ) {
if ( V_395 [ V_385 ] . V_398 ) {
if ( V_2 -> V_348 != V_349 )
F_188 ( NULL , V_378 , V_395 [ V_385 ] . V_398 , V_395 [ V_385 ] . V_399 ) ;
V_395 [ V_385 ] . V_398 = NULL ;
}
}
}
}
static void F_190 ( struct V_1 * V_2 )
{
F_189 ( V_2 , V_2 -> V_383 , V_2 -> V_381 ) ;
F_189 ( V_2 , V_2 -> V_384 , V_2 -> V_379 ) ;
F_187 ( V_2 ) ;
}
static int F_182 ( struct V_1 * V_2 )
{
V_2 -> V_400 = F_191 ( V_2 -> V_238 , V_187 | V_401 ) ;
if ( V_2 -> V_400 == NULL )
return - V_188 ;
V_2 -> V_402 = F_192 ( V_2 -> V_238 , V_187 ) ;
if ( ! V_2 -> V_402 ) {
F_193 ( V_2 -> V_400 ) ;
V_2 -> V_400 = NULL ;
return - V_188 ;
}
return 0 ;
}
static void F_194 ( struct V_1 * V_2 )
{
F_193 ( V_2 -> V_400 ) ;
V_2 -> V_400 = NULL ;
F_193 ( V_2 -> V_402 ) ;
V_2 -> V_402 = NULL ;
}
static int F_183 ( struct V_1 * V_2 )
{
int V_385 ;
if ( V_19 >= V_20 )
F_4 ( L_124 ,
V_2 -> V_21 , __FILE__ , __LINE__ , V_2 -> V_235 ) ;
memset ( V_2 -> V_403 , 0 , sizeof( V_2 -> V_403 ) ) ;
for ( V_385 = 0 ; V_385 < V_2 -> V_235 ; ++ V_385 ) {
V_2 -> V_403 [ V_385 ] . V_404 =
F_191 ( V_2 -> V_238 , V_187 ) ;
if ( V_2 -> V_403 [ V_385 ] . V_404 == NULL ) {
for ( -- V_385 ; V_385 >= 0 ; V_385 -- ) {
F_193 ( V_2 -> V_403 [ V_385 ] . V_404 ) ;
V_2 -> V_403 [ V_385 ] . V_404 = NULL ;
}
return - V_188 ;
}
}
return 0 ;
}
static void F_195 ( struct V_1 * V_2 )
{
int V_385 ;
for ( V_385 = 0 ; V_385 < V_2 -> V_235 ; ++ V_385 ) {
F_193 ( V_2 -> V_403 [ V_385 ] . V_404 ) ;
V_2 -> V_403 [ V_385 ] . V_404 = NULL ;
}
V_2 -> V_405 = 0 ;
V_2 -> V_406 = 0 ;
V_2 -> V_234 = 0 ;
}
static bool F_66 ( struct V_1 * V_2 )
{
bool V_228 = false ;
if ( V_2 -> V_234 ) {
struct V_407 * V_408 =
& V_2 -> V_403 [ V_2 -> V_405 ] ;
int V_409 = F_196 ( V_2 ) ;
int V_410 = V_408 -> V_411 / V_378 ;
if ( V_408 -> V_411 % V_378 )
++ V_410 ;
if ( V_410 <= V_409 ) {
V_2 -> V_78 = V_408 -> V_411 ;
F_102 ( V_2 , V_408 -> V_404 , V_408 -> V_411 ) ;
-- V_2 -> V_234 ;
if ( ++ V_2 -> V_405 >= V_2 -> V_235 )
V_2 -> V_405 = 0 ;
F_197 ( & V_2 -> V_81 , V_324 + F_198 ( 5000 ) ) ;
V_228 = true ;
}
}
return V_228 ;
}
static int F_104 ( struct V_1 * V_2 , const char * V_412 , unsigned int V_413 )
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
static int F_77 ( struct V_1 * V_2 )
{
if ( F_199 ( V_2 -> V_136 , V_2 -> V_414 , L_125 ) == NULL ) {
F_4 ( L_126 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_136 ) ;
return - V_300 ;
}
V_2 -> V_415 = true ;
if ( F_200 ( V_2 -> V_176 , F_67 , V_2 -> V_416 ,
V_2 -> V_21 , V_2 ) < 0 ) {
F_4 ( L_127 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_176 ) ;
goto V_417;
}
V_2 -> V_418 = true ;
if ( V_2 -> V_348 == V_349 ) {
if ( F_201 ( V_2 -> V_350 , 0x40000 , L_125 ) == NULL ) {
F_4 ( L_128 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_350 ) ;
goto V_417;
}
V_2 -> V_419 = true ;
if ( F_201 ( V_2 -> V_351 + V_2 -> V_420 , 128 , L_125 ) == NULL ) {
F_4 ( L_129 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_351 + V_2 -> V_420 ) ;
goto V_417;
}
V_2 -> V_421 = true ;
V_2 -> V_387 = F_202 ( V_2 -> V_350 ,
0x40000 ) ;
if ( ! V_2 -> V_387 ) {
F_4 ( L_130 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_350 ) ;
goto V_417;
}
if ( ! F_203 ( V_2 ) ) {
F_4 ( L_131 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_350 ) ;
goto V_417;
}
V_2 -> V_422 = F_202 ( V_2 -> V_351 ,
V_423 ) ;
if ( ! V_2 -> V_422 ) {
F_4 ( L_132 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_351 ) ;
goto V_417;
}
V_2 -> V_422 += V_2 -> V_420 ;
} else {
if ( F_204 ( V_2 -> V_352 , V_2 -> V_21 ) < 0 ) {
F_4 ( L_133 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_352 ) ;
F_81 ( V_2 ) ;
return - V_300 ;
}
V_2 -> V_424 = true ;
F_205 ( V_2 -> V_352 , V_425 ) ;
F_206 ( V_2 -> V_352 ) ;
}
if ( F_179 ( V_2 ) < 0 ) {
F_4 ( L_134 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_352 ) ;
goto V_417;
}
return 0 ;
V_417:
F_81 ( V_2 ) ;
return - V_300 ;
}
static void F_81 ( struct V_1 * V_2 )
{
if ( V_19 >= V_20 )
F_4 ( L_135 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( V_2 -> V_418 ) {
F_207 ( V_2 -> V_176 , V_2 ) ;
V_2 -> V_418 = false ;
}
if ( V_2 -> V_424 ) {
F_208 ( V_2 -> V_352 ) ;
F_209 ( V_2 -> V_352 ) ;
V_2 -> V_424 = false ;
}
F_190 ( V_2 ) ;
F_194 ( V_2 ) ;
F_195 ( V_2 ) ;
if ( V_2 -> V_415 ) {
F_210 ( V_2 -> V_136 , V_2 -> V_414 ) ;
V_2 -> V_415 = false ;
}
if ( V_2 -> V_419 ) {
F_211 ( V_2 -> V_350 , 0x40000 ) ;
V_2 -> V_419 = false ;
}
if ( V_2 -> V_421 ) {
F_211 ( V_2 -> V_351 + V_2 -> V_420 , 128 ) ;
V_2 -> V_421 = false ;
}
if ( V_2 -> V_387 ) {
F_212 ( V_2 -> V_387 ) ;
V_2 -> V_387 = NULL ;
}
if ( V_2 -> V_422 ) {
F_212 ( V_2 -> V_422 - V_2 -> V_420 ) ;
V_2 -> V_422 = NULL ;
}
if ( V_19 >= V_20 )
F_4 ( L_136 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
}
static void F_213 ( struct V_1 * V_2 )
{
V_2 -> V_340 = NULL ;
V_2 -> line = V_338 ;
sprintf ( V_2 -> V_21 , L_137 , V_2 -> line ) ;
if ( V_2 -> line < V_426 ) {
if ( V_427 [ V_2 -> line ] )
V_2 -> V_238 = V_427 [ V_2 -> line ] ;
if ( V_428 [ V_2 -> line ] ) {
V_2 -> V_380 = V_428 [ V_2 -> line ] ;
if ( V_2 -> V_380 < 1 )
V_2 -> V_380 = 1 ;
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
if ( V_2 -> V_348 == V_349 ) {
F_4 ( L_138 ,
V_2 -> V_432 + 1 , V_2 -> V_21 , V_2 -> V_136 , V_2 -> V_176 ,
V_2 -> V_350 , V_2 -> V_351 ,
V_2 -> V_238 ) ;
} else {
F_4 ( L_139 ,
V_2 -> V_21 , V_2 -> V_136 , V_2 -> V_176 , V_2 -> V_352 ,
V_2 -> V_238 ) ;
}
#if V_85
F_214 ( V_2 ) ;
#endif
}
static struct V_1 * F_215 ( void )
{
struct V_1 * V_2 ;
V_2 = F_192 ( sizeof( struct V_1 ) ,
V_187 ) ;
if ( ! V_2 ) {
F_4 ( L_140 ) ;
} else {
F_216 ( & V_2 -> V_42 ) ;
V_2 -> V_42 . V_16 = & V_433 ;
V_2 -> V_7 = V_8 ;
F_217 ( & V_2 -> V_33 , F_15 ) ;
V_2 -> V_238 = 4096 ;
V_2 -> V_42 . V_434 = 5 * V_223 / 10 ;
V_2 -> V_42 . V_435 = 30 * V_223 ;
F_218 ( & V_2 -> V_119 ) ;
F_218 ( & V_2 -> V_64 ) ;
F_219 ( & V_2 -> V_22 ) ;
F_219 ( & V_2 -> V_343 ) ;
memcpy ( & V_2 -> V_36 , & V_436 , sizeof( T_5 ) ) ;
V_2 -> V_247 = V_437 ;
V_2 -> V_380 = 1 ;
V_2 -> V_235 = 0 ;
}
return V_2 ;
}
static int F_220 ( void )
{
int V_24 ;
V_438 = F_221 ( 128 ) ;
if ( ! V_438 )
return - V_188 ;
V_438 -> V_439 = L_125 ;
V_438 -> V_3 = L_141 ;
V_438 -> V_440 = V_441 ;
V_438 -> V_442 = 64 ;
V_438 -> type = V_443 ;
V_438 -> V_444 = V_445 ;
V_438 -> V_446 = V_447 ;
V_438 -> V_446 . V_199 =
V_448 | V_212 | V_203 | V_200 | V_226 ;
V_438 -> V_446 . V_449 = 9600 ;
V_438 -> V_446 . V_450 = 9600 ;
V_438 -> V_12 = V_451 ;
F_222 ( V_438 , & V_452 ) ;
if ( ( V_24 = F_223 ( V_438 ) ) < 0 ) {
F_4 ( L_142 ,
__FILE__ , __LINE__ ) ;
F_224 ( V_438 ) ;
V_438 = NULL ;
return V_24 ;
}
F_4 ( L_143 ,
V_439 , V_374 ,
V_438 -> V_440 ) ;
return 0 ;
}
static void F_225 ( void )
{
struct V_1 * V_2 ;
int V_385 ;
for ( V_385 = 0 ; ( V_385 < V_453 ) && V_454 [ V_385 ] && V_455 [ V_385 ] ; V_385 ++ ) {
if ( V_19 >= V_20 )
F_4 ( L_144 ,
V_454 [ V_385 ] , V_455 [ V_385 ] , V_456 [ V_385 ] ) ;
V_2 = F_215 () ;
if ( ! V_2 ) {
if ( V_19 >= V_457 )
F_4 ( L_145 ) ;
continue;
}
V_2 -> V_136 = ( unsigned int ) V_454 [ V_385 ] ;
V_2 -> V_176 = ( unsigned int ) V_455 [ V_385 ] ;
V_2 -> V_176 = F_226 ( V_2 -> V_176 ) ;
V_2 -> V_352 = ( unsigned int ) V_456 [ V_385 ] ;
V_2 -> V_348 = V_458 ;
V_2 -> V_414 = 16 ;
V_2 -> V_416 = 0 ;
F_213 ( V_2 ) ;
}
}
static void F_227 ( void )
{
int V_24 ;
struct V_1 * V_2 ;
struct V_1 * V_459 ;
F_4 ( L_146 , V_439 , V_374 ) ;
if ( V_438 ) {
V_24 = F_228 ( V_438 ) ;
if ( V_24 )
F_4 ( L_147 ,
__FILE__ , __LINE__ , V_24 ) ;
F_224 ( V_438 ) ;
}
V_2 = V_339 ;
while( V_2 ) {
#if V_85
F_229 ( V_2 ) ;
#endif
F_81 ( V_2 ) ;
V_459 = V_2 ;
V_2 = V_2 -> V_340 ;
F_230 ( & V_459 -> V_42 ) ;
F_193 ( V_459 ) ;
}
if ( V_460 )
F_231 ( & V_461 ) ;
}
static int T_6 F_232 ( void )
{
int V_24 ;
if ( V_462 ) {
F_1 () ;
F_233 () ;
}
F_4 ( L_148 , V_439 , V_374 ) ;
F_225 () ;
if ( ( V_24 = F_234 ( & V_461 ) ) < 0 )
F_4 ( L_149 , __FILE__ , V_24 ) ;
else
V_460 = true ;
if ( ( V_24 = F_220 () ) < 0 )
goto error;
return 0 ;
error:
F_227 () ;
return V_24 ;
}
static void T_7 F_235 ( void )
{
F_227 () ;
}
static void F_35 ( struct V_1 * V_2 , T_2 V_463 )
{
F_51 ( V_463 + V_2 -> V_464 , V_2 -> V_136 + V_137 ) ;
if ( V_2 -> V_348 == V_349 )
F_52 ( V_2 -> V_136 + V_137 ) ;
}
static void F_34 ( struct V_1 * V_2 , T_2 V_463 )
{
F_51 ( V_463 + V_2 -> V_465 , V_2 -> V_136 ) ;
if ( V_2 -> V_348 == V_349 )
F_52 ( V_2 -> V_136 ) ;
}
static void F_63 ( struct V_1 * V_2 , T_2 V_466 , T_2 V_467 )
{
F_51 ( V_466 + V_2 -> V_465 , V_2 -> V_136 ) ;
F_51 ( V_467 , V_2 -> V_136 ) ;
if ( V_2 -> V_348 == V_349 )
F_52 ( V_2 -> V_136 ) ;
}
static T_2 F_64 ( struct V_1 * V_2 , T_2 V_466 )
{
F_51 ( V_466 + V_2 -> V_465 , V_2 -> V_136 ) ;
return F_52 ( V_2 -> V_136 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_2 V_466 , T_2 V_467 )
{
F_51 ( V_466 + V_2 -> V_464 , V_2 -> V_136 + V_137 ) ;
F_51 ( V_467 , V_2 -> V_136 + V_137 ) ;
if ( V_2 -> V_348 == V_349 )
F_52 ( V_2 -> V_136 + V_137 ) ;
}
static T_2 F_25 ( struct V_1 * V_2 , T_2 V_466 )
{
F_51 ( V_466 + V_2 -> V_464 , V_2 -> V_136 + V_137 ) ;
return F_52 ( V_2 -> V_136 + V_137 ) ;
}
static void F_236 ( struct V_1 * V_2 )
{
T_2 V_467 ;
bool V_468 ;
F_27 ( V_2 , V_469 , 0x1f ) ;
V_467 = F_25 ( V_2 , V_470 ) ;
V_468 = ( V_467 == V_471 ) ;
if ( V_2 -> V_36 . V_12 & V_236 )
{
V_467 = 0x8e06 ;
}
else
{
if ( V_2 -> V_36 . V_37 == V_202 ) {
V_467 = 0x0001 ;
F_27 ( V_2 , V_295 ,
( unsigned short ) ( ( F_25 ( V_2 , V_295 ) & ~ ( V_57 | V_197 ) ) | V_197 ) ) ;
V_467 |= 0x0400 ;
}
else {
V_467 = 0x0606 ;
if ( V_2 -> V_36 . V_12 & V_472 )
V_467 |= V_196 ;
else if ( V_2 -> V_36 . V_12 & V_473 )
V_467 |= V_195 ;
else if ( V_2 -> V_36 . V_12 & V_474 )
V_467 |= V_195 | V_196 ;
}
if ( V_2 -> V_36 . V_475 != V_476 )
V_467 |= V_57 ;
}
if ( V_2 -> V_36 . V_37 == V_38 &&
( V_2 -> V_36 . V_12 & V_477 ) )
V_467 |= V_197 ;
if ( V_2 -> V_36 . V_478 != 0xff )
{
F_27 ( V_2 , V_479 , V_2 -> V_36 . V_478 ) ;
V_467 |= V_480 ;
}
F_27 ( V_2 , V_58 , V_467 ) ;
V_2 -> V_56 = V_467 ;
V_467 = 0x0500 ;
switch ( V_2 -> V_36 . V_481 ) {
case V_482 : V_467 |= V_57 ; break;
case V_483 : V_467 |= V_196 ; break;
case V_484 : V_467 |= V_196 | V_57 ; break;
case V_485 : V_467 |= V_195 ; break;
case V_486 : V_467 |= V_195 | V_57 ; break;
case V_487 : V_467 |= V_195 | V_196 ; break;
case V_488 : V_467 |= V_195 | V_196 | V_57 ; break;
}
if ( ( V_2 -> V_36 . V_489 & V_490 ) == V_491 )
V_467 |= V_161 ;
else if ( ( V_2 -> V_36 . V_489 & V_490 ) == V_492 )
V_467 |= ( V_197 | V_179 | V_161 ) ;
F_27 ( V_2 , V_493 , V_467 ) ;
F_27 ( V_2 , V_494 , V_495 ) ;
F_50 ( V_2 , V_496 ) ;
V_467 = F_25 ( V_2 , V_59 ) & 0xc0 ;
if ( V_2 -> V_348 == V_349 )
F_27 ( V_2 , V_59 , ( T_2 ) ( 0x030a | V_467 ) ) ;
else
F_27 ( V_2 , V_59 , ( T_2 ) ( 0x140a | V_467 ) ) ;
F_31 ( V_2 , V_142 ) ;
F_30 ( V_2 , V_67 ) ;
V_467 = 0x0400 ;
switch ( V_2 -> V_36 . V_481 ) {
case V_482 : V_467 |= V_57 ; break;
case V_483 : V_467 |= V_196 ; break;
case V_484 : V_467 |= V_196 | V_57 ; break;
case V_485 : V_467 |= V_195 ; break;
case V_486 : V_467 |= V_195 | V_57 ; break;
case V_487 : V_467 |= V_195 | V_196 ; break;
case V_488 : V_467 |= V_195 | V_196 | V_57 ; break;
}
if ( ( V_2 -> V_36 . V_489 & V_490 ) == V_491 )
V_467 |= V_161 | V_166 ;
else if ( ( V_2 -> V_36 . V_489 & V_490 ) == V_492 )
V_467 |= ( V_197 | V_179 | V_161 | V_166 ) ;
F_27 ( V_2 , V_369 , V_467 ) ;
F_126 ( V_2 ) ;
F_131 ( V_2 , V_497 ) ;
if ( V_2 -> V_348 == V_349 )
F_27 ( V_2 , V_360 , 0x0736 ) ;
else
F_27 ( V_2 , V_360 , 0x1436 ) ;
F_33 ( V_2 , V_498 ) ;
F_30 ( V_2 , V_69 ) ;
V_2 -> V_499 = 0 ;
if ( ! V_468 )
V_2 -> V_499 |= V_500 ;
F_27 ( V_2 , V_68 , V_2 -> V_499 ) ;
V_467 = 0x0f40 ;
if ( V_2 -> V_36 . V_12 & V_501 )
V_467 |= 0x0003 ;
else if ( V_2 -> V_36 . V_12 & V_502 )
V_467 |= 0x0004 ;
else if ( V_2 -> V_36 . V_12 & V_503 )
V_467 |= 0x0006 ;
else
V_467 |= 0x0007 ;
if ( V_2 -> V_36 . V_12 & V_504 )
V_467 |= 0x0018 ;
else if ( V_2 -> V_36 . V_12 & V_505 )
V_467 |= 0x0020 ;
else if ( V_2 -> V_36 . V_12 & V_506 )
V_467 |= 0x0038 ;
else
V_467 |= 0x0030 ;
F_27 ( V_2 , V_507 , V_467 ) ;
V_467 = 0x0000 ;
if ( V_2 -> V_36 . V_12 & ( V_501 | V_504 ) ) {
V_391 V_508 ;
V_391 V_509 ;
T_2 V_510 ;
if ( V_2 -> V_348 == V_349 )
V_508 = 11059200 ;
else
V_508 = 14745600 ;
if ( V_2 -> V_36 . V_12 & V_511 ) {
V_509 = 16 ;
V_467 |= V_179 ;
}
else if ( V_2 -> V_36 . V_12 & V_512 ) {
V_509 = 8 ;
V_467 |= V_513 ;
}
else
V_509 = 32 ;
if ( V_2 -> V_36 . V_514 )
{
V_510 = ( T_2 ) ( ( V_508 / V_509 ) / V_2 -> V_36 . V_514 ) ;
if ( ! ( ( ( ( V_508 / V_509 ) % V_2 -> V_36 . V_514 ) * 2 )
/ V_2 -> V_36 . V_514 ) )
V_510 -- ;
}
else
V_510 = - 1 ;
F_27 ( V_2 , V_515 , V_510 ) ;
V_467 |= V_480 ;
switch ( V_2 -> V_36 . V_481 ) {
case V_516 :
case V_482 :
case V_483 :
case V_484 : V_467 |= V_166 ; break;
case V_485 :
case V_486 : V_467 |= V_161 ; break;
case V_487 :
case V_488 : V_467 |= V_161 | V_166 ; break;
}
}
F_27 ( V_2 , V_517 , V_467 ) ;
F_27 ( V_2 , V_518 , 0x1020 ) ;
if ( V_2 -> V_36 . V_12 & V_519 ) {
F_27 ( V_2 , V_123 ,
( T_2 ) ( F_25 ( V_2 , V_123 ) | V_520 ) ) ;
}
F_237 ( V_2 ) ;
F_30 ( V_2 , V_67 | V_131 |
V_69 | V_127 | V_159 ) ;
F_27 ( V_2 , V_123 , ( T_2 ) ( F_25 ( V_2 , V_123 ) | V_134 ) ) ;
F_92 ( V_2 , V_159 ) ;
V_2 -> V_465 = 0 ;
F_51 ( 0 , V_2 -> V_136 ) ;
F_34 ( V_2 , V_521 ) ;
V_2 -> V_465 = V_166 ;
F_51 ( V_166 , V_2 -> V_136 ) ;
if ( V_2 -> V_348 == V_458 ) {
F_27 ( V_2 , V_194 , ( T_2 ) ( ( F_25 ( V_2 , V_194 ) | V_195 ) & ~ V_196 ) ) ;
}
if ( V_2 -> V_348 == V_349 ) {
F_63 ( V_2 , V_522 , 0xa00b ) ;
}
else
F_63 ( V_2 , V_522 , 0x800b ) ;
F_63 ( V_2 , V_163 , 0xf200 ) ;
F_63 ( V_2 , V_168 , 0xf200 ) ;
F_63 ( V_2 , V_523 , 0x9000 ) ;
F_64 ( V_2 , V_163 ) ;
F_64 ( V_2 , V_168 ) ;
F_63 ( V_2 , V_160 , 0x0303 ) ;
V_467 = 0x8080 ;
switch ( V_2 -> V_36 . V_524 ) {
case V_525 : V_467 |= V_179 ; break;
case V_526 : V_467 |= V_513 ; break;
case V_527 : V_467 |= V_513 | V_179 ; break;
}
switch ( V_2 -> V_36 . V_475 ) {
case V_528 : V_467 |= V_166 | V_197 ; break;
case V_529 : V_467 |= V_166 ; break;
case V_530 : V_467 |= V_161 ; break;
case V_531 : V_467 |= V_161 | V_166 ; break;
}
F_27 ( V_2 , V_532 , V_467 ) ;
if ( V_2 -> V_348 == V_349 ) {
F_63 ( V_2 , V_533 , 0x0000 ) ;
}
else
F_63 ( V_2 , V_533 , 0x2000 ) ;
F_10 ( V_2 ) ;
F_87 ( V_2 ) ;
}
static void F_238 ( struct V_1 * V_2 , int V_248 )
{
if ( V_248 ) {
F_27 ( V_2 , V_295 , F_25 ( V_2 , V_295 ) | ( V_296 | V_534 ) ) ;
F_27 ( V_2 , V_507 , 0x0f64 ) ;
if ( V_2 -> V_36 . V_514 ) {
if ( V_2 -> V_348 == V_349 )
F_27 ( V_2 , V_535 , ( T_2 ) ( ( 11059200 / V_2 -> V_36 . V_514 ) - 1 ) ) ;
else
F_27 ( V_2 , V_535 , ( T_2 ) ( ( 14745600 / V_2 -> V_36 . V_514 ) - 1 ) ) ;
} else
F_27 ( V_2 , V_535 , ( T_2 ) 8 ) ;
F_27 ( V_2 , V_517 , ( T_2 ) ( ( F_25 ( V_2 , V_517 ) & ~ V_162 ) | V_167 ) ) ;
F_27 ( V_2 , V_295 , ( T_2 ) ( ( F_25 ( V_2 , V_295 ) & 0xfff8 ) | 0x0004 ) ) ;
V_2 -> V_464 = 0x300 ;
F_51 ( 0x0300 , V_2 -> V_136 + V_137 ) ;
} else {
F_27 ( V_2 , V_295 , F_25 ( V_2 , V_295 ) & ~ ( V_296 | V_534 ) ) ;
V_2 -> V_464 = 0 ;
F_51 ( 0 , V_2 -> V_136 + V_137 ) ;
}
}
static void F_239 ( struct V_1 * V_2 , V_391 V_221 )
{
V_391 V_508 ;
T_2 V_510 ;
if ( V_221 ) {
if ( V_2 -> V_348 == V_349 )
V_508 = 11059200 ;
else
V_508 = 14745600 ;
V_510 = ( T_2 ) ( V_508 / V_221 ) ;
if ( ! ( ( ( V_508 % V_221 ) * 2 ) / V_221 ) )
V_510 -- ;
F_27 ( V_2 , V_535 , V_510 ) ;
F_27 ( V_2 , V_517 , ( T_2 ) ( ( F_25 ( V_2 , V_517 ) & ~ V_162 ) | V_167 ) ) ;
F_27 ( V_2 , V_295 , ( T_2 ) ( ( F_25 ( V_2 , V_295 ) & 0xfff8 ) | 0x0004 ) ) ;
} else {
F_27 ( V_2 , V_517 , ( T_2 ) ( F_25 ( V_2 , V_517 ) & ~ V_167 ) ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
int V_536 ;
int V_537 ;
int V_538 ;
bool V_539 = false ;
bool V_540 = false ;
bool V_541 = false ;
V_392 * V_386 = V_2 -> V_383 ;
V_391 V_397 ;
F_34 ( V_2 , V_542 ) ;
F_50 ( V_2 , V_543 ) ;
F_35 ( V_2 , V_147 ) ;
V_538 = V_536 = V_537 = V_2 -> V_544 ;
while( ! V_386 [ V_537 ] . V_13 )
{
if ( ! V_539 )
{
V_539 = true ;
V_538 = V_537 ;
V_540 = false ;
}
if ( V_386 [ V_537 ] . V_49 )
{
V_539 = false ;
V_540 = true ;
}
V_537 ++ ;
if ( V_537 == V_2 -> V_381 )
V_537 = 0 ;
if ( V_536 == V_537 )
{
F_184 ( V_2 ) ;
V_538 = 0 ;
V_539 = false ;
V_541 = true ;
break;
}
}
if ( V_539 && ! V_540 )
{
V_536 = V_538 ;
do
{
* ( ( unsigned long * ) & ( V_2 -> V_383 [ V_536 ++ ] . V_13 ) ) = V_378 ;
if ( V_536 == V_2 -> V_381 )
V_536 = 0 ;
} while( V_536 != V_537 );
V_541 = true ;
}
if ( V_541 )
{
F_31 ( V_2 , V_142 ) ;
F_30 ( V_2 , V_131 | V_67 ) ;
F_31 ( V_2 , V_131 | V_67 ) ;
F_58 ( V_2 , V_157 ) ;
F_27 ( V_2 , V_518 , ( T_2 ) ( F_25 ( V_2 , V_518 ) | V_57 ) ) ;
V_397 = V_2 -> V_383 [ V_538 ] . V_393 ;
F_63 ( V_2 , V_545 , ( T_2 ) V_397 ) ;
F_63 ( V_2 , V_546 , ( T_2 ) ( V_397 >> 16 ) ) ;
F_31 ( V_2 , V_142 ) ;
F_30 ( V_2 , V_131 | V_67 ) ;
F_92 ( V_2 , V_67 ) ;
F_63 ( V_2 , V_547 , V_134 | V_169 ) ;
F_63 ( V_2 , V_523 , ( T_2 ) ( F_64 ( V_2 , V_523 ) | V_162 ) ) ;
F_34 ( V_2 , V_548 ) ;
if ( V_2 -> V_36 . V_12 & V_549 )
F_58 ( V_2 , V_550 ) ;
else
F_58 ( V_2 , V_551 ) ;
}
else
{
F_27 ( V_2 , V_518 , ( T_2 ) ( F_25 ( V_2 , V_518 ) | V_57 ) ) ;
F_35 ( V_2 , V_147 ) ;
}
}
static void F_87 ( struct V_1 * V_2 )
{
if ( V_19 >= V_51 )
F_4 ( L_150 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_34 ( V_2 , V_158 ) ;
F_31 ( V_2 , V_142 ) ;
F_30 ( V_2 , V_131 | V_67 ) ;
F_59 ( V_2 , V_131 | V_67 ) ;
F_58 ( V_2 , V_157 ) ;
F_27 ( V_2 , V_518 , ( T_2 ) ( F_25 ( V_2 , V_518 ) | V_57 ) ) ;
F_35 ( V_2 , V_147 ) ;
V_2 -> V_250 = false ;
V_2 -> V_164 = false ;
V_2 -> V_41 = false ;
}
static void F_21 ( struct V_1 * V_2 )
{
V_391 V_397 ;
if ( V_19 >= V_51 )
F_4 ( L_151 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_184 ( V_2 ) ;
F_87 ( V_2 ) ;
F_27 ( V_2 , V_518 , ( T_2 ) ( F_25 ( V_2 , V_518 ) | V_57 ) ) ;
F_35 ( V_2 , V_147 ) ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_202 ) {
V_397 = V_2 -> V_383 [ 0 ] . V_393 ;
F_63 ( V_2 , V_545 , ( T_2 ) V_397 ) ;
F_63 ( V_2 , V_546 , ( T_2 ) ( V_397 >> 16 ) ) ;
F_31 ( V_2 , V_142 ) ;
F_30 ( V_2 , V_131 | V_67 ) ;
F_92 ( V_2 , V_67 ) ;
F_63 ( V_2 , V_547 , V_134 | V_169 ) ;
F_63 ( V_2 , V_523 , ( T_2 ) ( F_64 ( V_2 , V_523 ) | V_162 ) ) ;
F_34 ( V_2 , V_548 ) ;
if ( V_2 -> V_36 . V_12 & V_549 )
F_58 ( V_2 , V_550 ) ;
else
F_58 ( V_2 , V_551 ) ;
} else {
F_31 ( V_2 , V_142 ) ;
F_30 ( V_2 , V_131 | V_67 ) ;
F_92 ( V_2 , V_131 ) ;
F_35 ( V_2 , V_147 ) ;
F_50 ( V_2 , V_543 ) ;
F_58 ( V_2 , V_551 ) ;
}
F_27 ( V_2 , V_518 , 0x1020 ) ;
V_2 -> V_250 = true ;
}
static void F_13 ( struct V_1 * V_2 )
{
V_391 V_397 ;
unsigned int V_552 ;
if ( V_19 >= V_51 )
F_4 ( L_152 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( V_2 -> V_78 ) {
V_2 -> V_82 = false ;
if ( V_2 -> V_36 . V_12 & V_553 ) {
F_37 ( V_2 ) ;
if ( ! ( V_2 -> V_83 & V_84 ) ) {
V_2 -> V_83 |= V_84 ;
F_38 ( V_2 ) ;
V_2 -> V_82 = true ;
}
}
if ( V_2 -> V_36 . V_37 == V_229 ) {
if ( ! V_2 -> V_43 ) {
F_33 ( V_2 , V_498 ) ;
F_30 ( V_2 , V_69 + V_127 ) ;
F_92 ( V_2 , V_127 ) ;
F_48 ( V_2 ) ;
}
} else {
F_34 ( V_2 , V_72 ) ;
V_552 = V_2 -> V_384 [ V_2 -> V_554 ] . V_555 ;
if ( V_2 -> V_36 . V_37 == V_202 )
V_2 -> V_384 [ V_2 -> V_554 ] . V_555 = 0 ;
F_27 ( V_2 , V_556 , ( T_2 ) V_552 ) ;
F_35 ( V_2 , V_73 ) ;
V_397 = V_2 -> V_384 [ V_2 -> V_554 ] . V_393 ;
F_63 ( V_2 , V_557 , ( T_2 ) V_397 ) ;
F_63 ( V_2 , V_558 , ( T_2 ) ( V_397 >> 16 ) ) ;
F_33 ( V_2 , V_498 ) ;
F_30 ( V_2 , V_69 ) ;
F_92 ( V_2 , V_69 ) ;
if ( V_2 -> V_36 . V_37 == V_202 &&
V_2 -> V_380 > 1 ) {
F_63 ( V_2 , V_559 , V_169 | V_134 ) ;
F_63 ( V_2 , V_523 , ( T_2 ) ( F_64 ( V_2 , V_523 ) | V_167 ) ) ;
}
F_34 ( V_2 , V_560 ) ;
F_131 ( V_2 , V_561 ) ;
F_197 ( & V_2 -> V_81 , V_324 +
F_198 ( 5000 ) ) ;
}
V_2 -> V_43 = true ;
}
if ( ! V_2 -> V_23 ) {
V_2 -> V_23 = true ;
if ( V_2 -> V_36 . V_12 & V_519 )
F_240 ( V_2 , V_562 ) ;
else
F_240 ( V_2 , V_551 ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_19 >= V_51 )
F_4 ( L_153 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_36 ( & V_2 -> V_81 ) ;
F_33 ( V_2 , V_498 ) ;
F_30 ( V_2 , V_69 + V_127 ) ;
F_59 ( V_2 , V_69 + V_127 ) ;
F_240 ( V_2 , V_157 ) ;
F_34 ( V_2 , V_72 ) ;
F_35 ( V_2 , V_73 ) ;
V_2 -> V_23 = false ;
V_2 -> V_43 = false ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_129 ;
T_8 V_563 [ 2 ] ;
if ( ! V_2 -> V_78 && ! V_2 -> V_239 )
return;
F_131 ( V_2 , V_564 ) ;
while( ( V_129 = F_25 ( V_2 , V_360 ) >> 8 ) && V_2 -> V_78 ) {
if ( ( V_2 -> V_78 > 1 ) && ( V_129 > 1 ) && ! V_2 -> V_239 ) {
V_563 [ 0 ] = V_2 -> V_186 [ V_2 -> V_80 ++ ] ;
V_2 -> V_80 = V_2 -> V_80 & ( V_230 - 1 ) ;
V_563 [ 1 ] = V_2 -> V_186 [ V_2 -> V_80 ++ ] ;
V_2 -> V_80 = V_2 -> V_80 & ( V_230 - 1 ) ;
F_51 ( * ( ( T_2 * ) V_563 ) , V_2 -> V_136 + V_565 ) ;
V_2 -> V_78 -= 2 ;
V_2 -> V_54 . V_298 += 2 ;
} else {
F_51 ( ( F_52 ( V_2 -> V_136 + V_137 ) & 0x0780 ) | ( V_566 + V_133 ) ,
V_2 -> V_136 + V_137 ) ;
if ( V_2 -> V_239 ) {
F_51 ( V_2 -> V_239 , V_2 -> V_136 + V_137 ) ;
V_2 -> V_239 = 0 ;
} else {
F_51 ( V_2 -> V_186 [ V_2 -> V_80 ++ ] , V_2 -> V_136 + V_137 ) ;
V_2 -> V_80 = V_2 -> V_80 & ( V_230 - 1 ) ;
V_2 -> V_78 -- ;
}
V_2 -> V_54 . V_298 ++ ;
}
}
}
static void F_241 ( struct V_1 * V_2 )
{
if ( V_2 -> V_348 == V_349 ) {
int V_385 ;
V_391 V_567 ;
volatile V_391 * V_568 = ( V_391 * ) ( V_2 -> V_422 + 0x50 ) ;
V_391 * V_569 = ( V_391 * ) ( V_2 -> V_422 + 0x28 ) ;
V_2 -> V_570 |= V_571 ;
* V_568 = V_2 -> V_570 ;
for( V_385 = 0 ; V_385 < 10 ; V_385 ++ )
V_567 = * V_568 ;
V_2 -> V_570 &= ~ V_571 ;
* V_568 = V_2 -> V_570 ;
* V_569 = F_242 (
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
F_243 ( 0 , V_2 -> V_136 + 8 ) ;
}
V_2 -> V_465 = 0 ;
V_2 -> V_464 = 0 ;
V_2 -> V_572 = 0 ;
F_51 ( 0x000c , V_2 -> V_136 + V_573 ) ;
F_51 ( 0 , V_2 -> V_136 ) ;
F_51 ( 0 , V_2 -> V_136 + V_137 ) ;
F_35 ( V_2 , V_574 ) ;
F_27 ( V_2 , V_194 , 0xf0f5 ) ;
F_27 ( V_2 , V_295 , 0x0004 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
T_2 V_467 ;
F_70 ( V_2 ) ;
F_51 ( 0 , V_2 -> V_136 ) ;
F_34 ( V_2 , V_521 ) ;
F_244 ( V_2 ) ;
V_467 = 0 ;
if ( V_2 -> V_36 . V_214 != 1 )
V_467 |= V_196 ;
F_27 ( V_2 , V_58 , V_467 ) ;
V_467 = 0 ;
if ( V_2 -> V_36 . V_209 != 8 )
V_467 |= V_480 | V_134 | V_169 ;
if ( V_2 -> V_36 . V_145 != V_215 ) {
V_467 |= V_575 ;
if ( V_2 -> V_36 . V_145 != V_218 )
V_467 |= V_534 ;
}
F_27 ( V_2 , V_493 , V_467 ) ;
F_50 ( V_2 , V_576 ) ;
F_27 ( V_2 , V_59 , 0x0000 ) ;
F_31 ( V_2 , V_142 ) ;
F_30 ( V_2 , V_67 ) ;
V_467 = 0 ;
if ( V_2 -> V_36 . V_209 != 8 )
V_467 |= V_480 | V_134 | V_169 ;
if ( V_2 -> V_36 . V_145 != V_215 ) {
V_467 |= V_575 ;
if ( V_2 -> V_36 . V_145 != V_218 )
V_467 |= V_534 ;
}
F_27 ( V_2 , V_369 , V_467 ) ;
F_126 ( V_2 ) ;
F_131 ( V_2 , V_577 ) ;
F_27 ( V_2 , V_360 , 0x1f40 ) ;
F_33 ( V_2 , V_498 ) ;
F_30 ( V_2 , V_69 ) ;
F_245 ( V_2 , V_2 -> V_36 . V_221 ) ;
F_27 ( V_2 , V_518 , 0x0020 ) ;
F_59 ( V_2 , V_69 + V_127 +
V_131 + V_67 ) ;
F_30 ( V_2 , V_69 + V_127 +
V_131 + V_67 ) ;
F_237 ( V_2 ) ;
if ( V_2 -> V_348 == V_458 ) {
F_27 ( V_2 , V_194 , ( T_2 ) ( ( F_25 ( V_2 , V_194 ) | V_57 ) & ~ V_197 ) ) ;
}
if ( V_2 -> V_36 . V_578 ) {
V_2 -> V_464 = 0x300 ;
F_51 ( 0x0300 , V_2 -> V_136 + V_137 ) ;
}
}
static void F_244 ( struct V_1 * V_2 )
{
int V_385 ;
unsigned long V_579 = V_2 -> V_36 . V_37 ;
V_2 -> V_36 . V_37 = V_38 ;
F_70 ( V_2 ) ;
F_236 ( V_2 ) ;
F_238 ( V_2 , 1 ) ;
F_27 ( V_2 , V_535 , 0 ) ;
F_27 ( V_2 , V_532 , 0x0100 ) ;
F_35 ( V_2 , V_147 ) ;
F_58 ( V_2 , V_551 ) ;
F_27 ( V_2 , V_556 , 2 ) ;
F_35 ( V_2 , V_73 ) ;
F_33 ( V_2 , V_498 ) ;
F_51 ( 0 , V_2 -> V_136 + V_565 ) ;
F_131 ( V_2 , V_561 ) ;
F_240 ( V_2 , V_551 ) ;
for ( V_385 = 0 ; V_385 < 1000 ; V_385 ++ )
if ( F_25 ( V_2 , V_50 ) & ( V_166 | V_480 | V_134 | V_162 ) )
break;
F_238 ( V_2 , 0 ) ;
F_237 ( V_2 ) ;
V_2 -> V_36 . V_37 = V_579 ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_244 ( V_2 ) ;
F_236 ( V_2 ) ;
if ( V_2 -> V_348 == V_458 ) {
F_27 ( V_2 , V_194 , ( T_2 ) ( ( F_25 ( V_2 , V_194 ) | V_57 ) & ~ V_197 ) ) ;
}
F_239 ( V_2 , V_2 -> V_36 . V_514 ) ;
if ( V_2 -> V_36 . V_578 )
F_238 ( V_2 , 1 ) ;
}
static void F_126 ( struct V_1 * V_2 )
{
T_2 V_572 = V_580 ;
switch( V_2 -> V_247 ) {
case V_437 : V_572 = V_580 ; break;
case V_581 : V_572 = V_582 ; break;
case V_583 : V_572 = V_584 ; break;
case V_585 : V_572 = V_586 ; break;
case V_587 : V_572 = V_588 ; break;
case V_589 : V_572 = V_590 ; break;
case V_591 : V_572 = V_592 ; break;
}
V_2 -> V_572 = V_572 ;
V_2 -> V_499 &= ~ V_593 ;
V_2 -> V_499 += V_572 ;
F_27 ( V_2 , V_68 , V_2 -> V_499 ) ;
if ( V_2 -> V_36 . V_37 == V_202 ) {
unsigned char V_594 = 0 ;
switch( V_2 -> V_247 ) {
case V_437 :
V_594 = 0x7e ;
break;
case V_581 :
V_594 = 0x55 ;
break;
case V_583 :
case V_589 :
V_594 = 0x00 ;
break;
case V_585 :
case V_591 :
V_594 = 0xff ;
break;
case V_587 :
V_594 = 0xaa ;
break;
}
F_246 ( V_2 , V_594 , V_594 ) ;
}
}
static void F_37 ( struct V_1 * V_2 )
{
T_2 V_49 ;
V_2 -> V_83 &= V_84 | V_201 ;
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
T_2 V_595 ;
unsigned char V_596 = V_2 -> V_83 ;
V_595 = F_25 ( V_2 , V_194 ) ;
if ( V_596 & V_84 )
V_595 &= ~ ( V_534 ) ;
else
V_595 |= V_534 ;
if ( V_596 & V_201 )
V_595 &= ~ ( V_480 ) ;
else
V_595 |= V_480 ;
F_27 ( V_2 , V_194 , V_595 ) ;
}
static void F_245 ( struct V_1 * V_2 , V_391 V_221 )
{
if ( V_221 ) {
F_27 ( V_2 , V_507 , 0x0f64 ) ;
if ( V_2 -> V_348 == V_349 )
F_27 ( V_2 , V_535 , ( T_2 ) ( ( 691200 / V_221 ) - 1 ) ) ;
else
F_27 ( V_2 , V_535 , ( T_2 ) ( ( 921600 / V_221 ) - 1 ) ) ;
F_27 ( V_2 , V_517 ,
( T_2 ) ( ( F_25 ( V_2 , V_517 ) & ~ V_162 ) | V_167 ) ) ;
F_27 ( V_2 , V_295 ,
( T_2 ) ( ( F_25 ( V_2 , V_295 ) & 0xfff8 ) | 0x0004 ) ) ;
} else {
F_27 ( V_2 , V_517 , ( T_2 ) ( F_25 ( V_2 , V_517 ) & ~ V_167 ) ) ;
}
}
static void F_185 ( struct V_1 * V_2 )
{
unsigned int V_385 ;
for ( V_385 = 0 ; V_385 < V_2 -> V_379 ; V_385 ++ ) {
* ( ( unsigned long * ) & ( V_2 -> V_384 [ V_385 ] . V_13 ) ) = 0 ;
}
V_2 -> V_597 = 0 ;
V_2 -> V_554 = 0 ;
V_2 -> V_170 = 0 ;
V_2 -> V_405 = 0 ;
V_2 -> V_406 = 0 ;
V_2 -> V_234 = 0 ;
}
static int F_196 ( struct V_1 * V_2 )
{
return V_2 -> V_379 - V_2 -> V_170 ;
}
static void F_184 ( struct V_1 * V_2 )
{
unsigned int V_385 ;
for ( V_385 = 0 ; V_385 < V_2 -> V_381 ; V_385 ++ ) {
* ( ( unsigned long * ) & ( V_2 -> V_383 [ V_385 ] . V_13 ) ) = V_378 ;
}
V_2 -> V_544 = 0 ;
}
static void F_247 ( struct V_1 * V_2 , unsigned int V_598 , unsigned int V_599 )
{
bool V_600 = false ;
V_392 * V_601 ;
unsigned int V_602 ;
V_602 = V_598 ;
while( ! V_600 ) {
V_601 = & ( V_2 -> V_383 [ V_602 ] ) ;
if ( V_602 == V_599 ) {
V_600 = true ;
}
* ( ( unsigned long * ) & ( V_601 -> V_13 ) ) = V_378 ;
V_602 ++ ;
if ( V_602 == V_2 -> V_381 )
V_602 = 0 ;
}
V_2 -> V_544 = V_602 ;
}
static bool V_39 ( struct V_1 * V_2 )
{
unsigned int V_598 , V_599 ;
unsigned short V_49 ;
V_392 * V_601 ;
unsigned int V_603 = 0 ;
bool V_604 = false ;
unsigned long V_12 ;
struct V_9 * V_10 = V_2 -> V_42 . V_10 ;
bool V_605 = false ;
V_598 = V_599 = V_2 -> V_544 ;
while( ! V_2 -> V_383 [ V_599 ] . V_49 ) {
if ( V_2 -> V_383 [ V_599 ] . V_13 )
goto V_606;
V_599 ++ ;
if ( V_599 == V_2 -> V_381 )
V_599 = 0 ;
if ( V_599 == V_598 ) {
if ( V_2 -> V_250 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
goto V_606;
}
}
V_49 = V_2 -> V_383 [ V_599 ] . V_49 ;
if ( V_49 & ( V_607 | V_65 |
V_608 | V_609 ) ) {
if ( V_49 & V_607 )
V_2 -> V_54 . V_354 ++ ;
else if ( V_49 & V_609 )
V_2 -> V_54 . V_55 ++ ;
else if ( V_49 & V_65 )
V_2 -> V_54 . V_66 ++ ;
else {
V_2 -> V_54 . V_356 ++ ;
if ( V_2 -> V_36 . V_489 & V_610 )
V_605 = true ;
}
V_603 = 0 ;
#if V_85
{
V_2 -> V_113 -> V_611 . V_612 ++ ;
V_2 -> V_113 -> V_611 . V_613 ++ ;
}
#endif
} else
V_605 = true ;
if ( V_605 ) {
V_603 = V_495 - V_2 -> V_383 [ V_599 ] . V_555 ;
if ( V_2 -> V_36 . V_489 == V_491 )
V_603 -= 2 ;
else if ( V_2 -> V_36 . V_489 == V_492 )
V_603 -= 4 ;
}
if ( V_19 >= V_35 )
F_4 ( L_154 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_49 , V_603 ) ;
if ( V_19 >= V_614 )
F_248 ( V_2 , V_2 -> V_383 [ V_598 ] . V_398 ,
F_105 ( int , V_603 , V_378 ) , 0 ) ;
if ( V_603 ) {
if ( ( ( V_2 -> V_36 . V_489 & V_610 ) &&
( ( V_603 + 1 ) > V_2 -> V_238 ) ) ||
( V_603 > V_2 -> V_238 ) )
V_2 -> V_54 . V_355 ++ ;
else {
int V_615 = V_603 ;
int V_337 = V_598 ;
unsigned char * V_616 = V_2 -> V_400 ;
if ( ! ( V_49 & V_608 ) )
V_2 -> V_54 . V_353 ++ ;
while( V_615 ) {
int V_617 ;
if ( V_615 > V_378 )
V_617 = V_378 ;
else
V_617 = V_615 ;
V_601 = & ( V_2 -> V_383 [ V_337 ] ) ;
memcpy ( V_616 , V_601 -> V_398 , V_617 ) ;
V_616 += V_617 ;
V_615 -= V_617 ;
if ( ++ V_337 == V_2 -> V_381 )
V_337 = 0 ;
}
if ( V_2 -> V_36 . V_489 & V_610 ) {
++ V_603 ;
* V_616 = ( V_49 & V_608 ?
V_618 :
V_619 ) ;
if ( V_19 >= V_614 )
F_4 ( L_155 ,
__FILE__ , __LINE__ , V_2 -> V_21 ,
* V_616 ) ;
}
#if V_85
if ( V_2 -> V_86 )
F_249 ( V_2 , V_2 -> V_400 , V_603 ) ;
else
#endif
F_5 ( V_10 , V_2 -> V_400 , V_2 -> V_402 , V_603 ) ;
}
}
F_247 ( V_2 , V_598 , V_599 ) ;
V_604 = true ;
V_606:
if ( V_2 -> V_250 && V_2 -> V_164 ) {
if ( ! V_2 -> V_383 [ V_599 ] . V_49 &&
V_2 -> V_383 [ V_599 ] . V_13 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
return V_604 ;
}
static bool V_40 ( struct V_1 * V_2 )
{
unsigned int V_620 , V_621 ;
unsigned short V_49 ;
V_392 * V_601 ;
unsigned int V_603 = 0 ;
bool V_604 = false ;
unsigned long V_12 ;
struct V_9 * V_10 = V_2 -> V_42 . V_10 ;
V_620 = V_621 = V_2 -> V_544 ;
++ V_621 ;
if ( V_621 == V_2 -> V_381 )
V_621 = 0 ;
if ( V_2 -> V_383 [ V_620 ] . V_49 != 0 ||
( V_2 -> V_383 [ V_620 ] . V_13 == 0 &&
V_2 -> V_383 [ V_621 ] . V_13 == 0 ) ) {
V_49 = V_2 -> V_383 [ V_620 ] . V_49 ;
if ( V_49 & ( V_607 | V_65 |
V_608 | V_609 ) ) {
if ( V_49 & V_607 )
V_2 -> V_54 . V_354 ++ ;
else if ( V_49 & V_609 )
V_2 -> V_54 . V_55 ++ ;
else if ( V_49 & V_65 )
V_2 -> V_54 . V_66 ++ ;
else
V_2 -> V_54 . V_356 ++ ;
V_603 = 0 ;
} else {
if ( V_49 ) {
if ( V_2 -> V_383 [ V_620 ] . V_555 )
V_603 = V_495 - V_2 -> V_383 [ V_620 ] . V_555 ;
else
V_603 = V_378 ;
}
else
V_603 = V_378 ;
}
if ( V_603 > V_378 ) {
V_603 = V_603 % V_378 ;
}
if ( V_19 >= V_35 )
F_4 ( L_156 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_49 , V_603 ) ;
if ( V_19 >= V_614 )
F_248 ( V_2 , V_2 -> V_383 [ V_620 ] . V_398 ,
F_105 ( int , V_603 , V_378 ) , 0 ) ;
if ( V_603 ) {
V_601 = & ( V_2 -> V_383 [ V_620 ] ) ;
memcpy ( V_2 -> V_400 , V_601 -> V_398 , V_603 ) ;
V_2 -> V_54 . V_353 ++ ;
F_5 ( V_10 , V_2 -> V_400 , V_2 -> V_402 , V_603 ) ;
}
F_247 ( V_2 , V_620 , V_620 ) ;
V_604 = true ;
}
if ( V_2 -> V_250 && V_2 -> V_164 ) {
if ( ! V_2 -> V_383 [ V_620 ] . V_49 &&
V_2 -> V_383 [ V_620 ] . V_13 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
return V_604 ;
}
static void F_102 ( struct V_1 * V_2 ,
const char * V_412 , unsigned int V_413 )
{
unsigned short V_622 ;
unsigned int V_385 = 0 ;
V_392 * V_601 ;
if ( V_19 >= V_614 )
F_248 ( V_2 , V_412 , F_105 ( int , V_413 , V_378 ) , 1 ) ;
if ( V_2 -> V_36 . V_12 & V_236 ) {
V_2 -> V_56 |= V_57 ;
}
V_385 = V_2 -> V_597 ;
V_2 -> V_554 = V_385 ;
V_2 -> V_384 [ V_385 ] . V_49 = V_2 -> V_56 & 0xf000 ;
V_2 -> V_384 [ V_385 ] . V_555 = V_413 ;
V_2 -> V_384 [ V_385 ] . V_13 = V_413 ;
while( V_413 ) {
V_601 = & V_2 -> V_384 [ V_385 ++ ] ;
if ( V_385 == V_2 -> V_379 )
V_385 = 0 ;
if ( V_413 > V_378 )
V_622 = V_378 ;
else
V_622 = V_413 ;
if ( V_2 -> V_348 == V_349 )
F_250 ( V_601 -> V_398 , V_412 , V_622 ) ;
else
memcpy ( V_601 -> V_398 , V_412 , V_622 ) ;
V_601 -> V_13 = V_622 ;
V_412 += V_622 ;
V_413 -= V_622 ;
++ V_2 -> V_170 ;
}
V_2 -> V_597 = V_385 ;
}
static bool F_251 ( struct V_1 * V_2 )
{
static unsigned short V_623 [] =
{ 0x0000 , 0xffff , 0xaaaa , 0x5555 , 0x1234 , 0x6969 , 0x9696 , 0x0f0f } ;
static unsigned int V_624 = F_252 ( V_623 ) ;
unsigned int V_385 ;
bool V_24 = true ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_241 ( V_2 ) ;
if ( ( F_25 ( V_2 , V_123 ) != 0 ) ||
( F_25 ( V_2 , V_177 ) != 0 ) ||
( F_64 ( V_2 , V_178 ) != 0 ) ) {
V_24 = false ;
}
if ( V_24 ) {
for ( V_385 = 0 ; V_385 < V_624 ; V_385 ++ ) {
F_27 ( V_2 , V_535 , V_623 [ V_385 ] ) ;
F_27 ( V_2 , V_515 , V_623 [ ( V_385 + 1 ) % V_624 ] ) ;
F_27 ( V_2 , V_556 , V_623 [ ( V_385 + 2 ) % V_624 ] ) ;
F_27 ( V_2 , V_494 , V_623 [ ( V_385 + 3 ) % V_624 ] ) ;
F_27 ( V_2 , V_479 , V_623 [ ( V_385 + 4 ) % V_624 ] ) ;
F_63 ( V_2 , V_625 , V_623 [ ( V_385 + 5 ) % V_624 ] ) ;
if ( ( F_25 ( V_2 , V_535 ) != V_623 [ V_385 ] ) ||
( F_25 ( V_2 , V_515 ) != V_623 [ ( V_385 + 1 ) % V_624 ] ) ||
( F_25 ( V_2 , V_556 ) != V_623 [ ( V_385 + 2 ) % V_624 ] ) ||
( F_25 ( V_2 , V_494 ) != V_623 [ ( V_385 + 3 ) % V_624 ] ) ||
( F_25 ( V_2 , V_479 ) != V_623 [ ( V_385 + 4 ) % V_624 ] ) ||
( F_64 ( V_2 , V_625 ) != V_623 [ ( V_385 + 5 ) % V_624 ] ) ) {
V_24 = false ;
break;
}
}
}
F_241 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_24 ;
}
static bool F_253 ( struct V_1 * V_2 )
{
unsigned long V_626 ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_241 ( V_2 ) ;
V_2 -> V_126 = false ;
F_27 ( V_2 , V_194 , ( unsigned short ) ( ( F_25 ( V_2 , V_194 ) | V_57 ) & ~ V_197 ) ) ;
F_237 ( V_2 ) ;
F_92 ( V_2 , V_91 ) ;
F_30 ( V_2 , V_91 ) ;
F_41 ( V_2 , V_122 ) ;
F_91 ( V_2 , V_124 + V_125 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_626 = 100 ;
while( V_626 -- && ! V_2 -> V_126 ) {
F_158 ( 10 ) ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_241 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_2 -> V_126 ;
}
static bool F_254 ( struct V_1 * V_2 )
{
unsigned short V_627 ;
unsigned long V_397 ;
unsigned int V_552 ;
unsigned int V_385 ;
char * V_628 ;
bool V_24 = true ;
unsigned short V_49 = 0 ;
unsigned long V_626 ;
unsigned long V_12 ;
T_5 V_246 ;
memcpy ( & V_246 , & V_2 -> V_36 , sizeof( T_5 ) ) ;
memcpy ( & V_2 -> V_36 , & V_436 , sizeof( T_5 ) ) ;
#define F_255 40
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_241 ( V_2 ) ;
F_236 ( V_2 ) ;
F_238 ( V_2 , 1 ) ;
F_63 ( V_2 , V_163 , 0xe200 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_552 = F_255 ;
V_2 -> V_384 [ 0 ] . V_13 = V_552 ;
V_2 -> V_384 [ 0 ] . V_555 = V_552 ;
V_2 -> V_384 [ 0 ] . V_49 = 0x4000 ;
V_628 = V_2 -> V_384 [ 0 ] . V_398 ;
for ( V_385 = 0 ; V_385 < V_552 ; V_385 ++ )
* V_628 ++ = V_385 ;
V_2 -> V_383 [ 0 ] . V_49 = 0 ;
V_2 -> V_383 [ 0 ] . V_13 = V_552 + 4 ;
memset ( V_2 -> V_383 [ 0 ] . V_398 , 0 , V_552 + 4 ) ;
V_2 -> V_384 [ 1 ] . V_13 = 0 ;
V_2 -> V_383 [ 1 ] . V_13 = 0 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_35 ( V_2 , V_147 ) ;
V_397 = V_2 -> V_383 [ 0 ] . V_393 ;
F_63 ( V_2 , V_545 , ( unsigned short ) V_397 ) ;
F_63 ( V_2 , V_546 , ( unsigned short ) ( V_397 >> 16 ) ) ;
F_64 ( V_2 , V_163 ) ;
F_34 ( V_2 , V_548 ) ;
F_27 ( V_2 , V_493 , ( unsigned short ) ( ( F_25 ( V_2 , V_493 ) & 0xfffc ) | 0x0002 ) ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_626 = V_324 + F_198 ( 100 ) ;
for(; ; ) {
if ( F_160 ( V_324 , V_626 ) ) {
V_24 = false ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_49 = F_64 ( V_2 , V_163 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( ! ( V_49 & V_480 ) && ( V_49 & V_575 ) ) {
break;
}
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_27 ( V_2 , V_556 , ( unsigned short ) V_2 -> V_384 [ 0 ] . V_13 ) ;
F_35 ( V_2 , V_73 ) ;
V_397 = V_2 -> V_384 [ 0 ] . V_393 ;
F_63 ( V_2 , V_557 , ( unsigned short ) V_397 ) ;
F_63 ( V_2 , V_558 , ( unsigned short ) ( V_397 >> 16 ) ) ;
F_27 ( V_2 , V_68 , ( unsigned short ) ( ( F_25 ( V_2 , V_68 ) & 0x0f00 ) | 0xfa ) ) ;
F_34 ( V_2 , V_560 ) ;
F_131 ( V_2 , V_564 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_626 = V_324 + F_198 ( 100 ) ;
for(; ; ) {
if ( F_160 ( V_324 , V_626 ) ) {
V_24 = false ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_627 = F_25 ( V_2 , V_360 ) >> 8 ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( V_627 < 16 )
break;
else
if ( V_552 < 32 ) {
if ( V_627 <= ( 32 - V_552 ) )
break;
}
}
if ( V_24 )
{
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_131 ( V_2 , V_561 ) ;
F_27 ( V_2 , V_369 , ( unsigned short ) ( ( F_25 ( V_2 , V_369 ) & 0xfffc ) | 0x0002 ) ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_626 = V_324 + F_198 ( 100 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_49 = F_25 ( V_2 , V_68 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
while ( ! ( V_49 & ( V_534 | V_575 | V_480 | V_169 | V_162 ) ) ) {
if ( F_160 ( V_324 , V_626 ) ) {
V_24 = false ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_49 = F_25 ( V_2 , V_68 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
if ( V_24 ) {
if ( V_49 & ( V_575 | V_162 ) )
V_24 = false ;
}
if ( V_24 ) {
V_626 = V_324 + F_198 ( 100 ) ;
V_49 = V_2 -> V_383 [ 0 ] . V_49 ;
while ( V_49 == 0 ) {
if ( F_160 ( V_324 , V_626 ) ) {
V_24 = false ;
break;
}
V_49 = V_2 -> V_383 [ 0 ] . V_49 ;
}
}
if ( V_24 ) {
V_49 = V_2 -> V_383 [ 0 ] . V_49 ;
if ( V_49 & ( V_166 | V_134 | V_162 ) ) {
V_24 = false ;
} else {
if ( memcmp ( V_2 -> V_384 [ 0 ] . V_398 ,
V_2 -> V_383 [ 0 ] . V_398 , V_552 ) ) {
V_24 = false ;
}
}
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_241 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
memcpy ( & V_2 -> V_36 , & V_246 , sizeof( T_5 ) ) ;
return V_24 ;
}
static int F_78 ( struct V_1 * V_2 )
{
if ( V_19 >= V_20 )
F_4 ( L_157 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( ! F_251 ( V_2 ) ) {
V_2 -> V_629 = V_630 ;
F_4 ( L_158 ,
__FILE__ , __LINE__ , V_2 -> V_21 , ( unsigned short ) ( V_2 -> V_136 ) ) ;
return - V_300 ;
}
if ( ! F_253 ( V_2 ) ) {
V_2 -> V_629 = V_631 ;
F_4 ( L_159 ,
__FILE__ , __LINE__ , V_2 -> V_21 , ( unsigned short ) ( V_2 -> V_176 ) ) ;
return - V_300 ;
}
if ( ! F_254 ( V_2 ) ) {
V_2 -> V_629 = V_632 ;
F_4 ( L_160 ,
__FILE__ , __LINE__ , V_2 -> V_21 , ( unsigned short ) ( V_2 -> V_352 ) ) ;
return - V_300 ;
}
if ( V_19 >= V_20 )
F_4 ( L_161 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return 0 ;
}
static bool F_203 ( struct V_1 * V_2 )
{
static unsigned long V_623 [] =
{ 0x0 , 0x55555555 , 0xaaaaaaaa , 0x66666666 , 0x99999999 , 0xffffffff , 0x12345678 } ;
unsigned long V_624 = F_252 ( V_623 ) ;
unsigned long V_385 ;
unsigned long V_633 = V_634 /sizeof( unsigned long ) ;
unsigned long * V_635 ;
if ( V_2 -> V_348 != V_349 )
return true ;
V_635 = ( unsigned long * ) V_2 -> V_387 ;
for ( V_385 = 0 ; V_385 < V_624 ; V_385 ++ ) {
* V_635 = V_623 [ V_385 ] ;
if ( * V_635 != V_623 [ V_385 ] )
return false ;
}
for ( V_385 = 0 ; V_385 < V_633 ; V_385 ++ ) {
* V_635 = V_385 * 4 ;
V_635 ++ ;
}
V_635 = ( unsigned long * ) V_2 -> V_387 ;
for ( V_385 = 0 ; V_385 < V_633 ; V_385 ++ ) {
if ( * V_635 != V_385 * 4 )
return false ;
V_635 ++ ;
}
memset ( V_2 -> V_387 , 0 , V_634 ) ;
return true ;
}
static void F_250 ( char * V_636 , const char * V_637 ,
unsigned short V_13 )
{
#define F_256 64
unsigned short V_638 = V_13 / F_256 ;
unsigned short V_602 ;
unsigned long V_639 ;
for ( V_602 = 0 ; V_602 < V_638 ; V_602 ++ )
{
memcpy ( V_636 , V_637 , F_256 ) ;
V_639 = * ( ( volatile unsigned long * ) V_636 ) ;
V_636 += F_256 ;
V_637 += F_256 ;
}
memcpy ( V_636 , V_637 , V_13 % F_256 ) ;
}
static void F_248 ( struct V_1 * V_2 , const char * V_11 , int V_13 , int V_640 )
{
int V_385 ;
int V_641 ;
if ( V_640 )
F_4 ( L_162 , V_2 -> V_21 ) ;
else
F_4 ( L_163 , V_2 -> V_21 ) ;
while( V_13 ) {
if ( V_13 > 16 )
V_641 = 16 ;
else
V_641 = V_13 ;
for( V_385 = 0 ; V_385 < V_641 ; V_385 ++ )
F_4 ( L_164 , ( unsigned char ) V_11 [ V_385 ] ) ;
for(; V_385 < 17 ; V_385 ++ )
F_4 ( L_165 ) ;
for( V_385 = 0 ; V_385 < V_641 ; V_385 ++ ) {
if ( V_11 [ V_385 ] >= 040 && V_11 [ V_385 ] <= 0176 )
F_4 ( L_166 , V_11 [ V_385 ] ) ;
else
F_4 ( L_167 ) ;
}
F_4 ( L_168 ) ;
V_11 += V_641 ;
V_13 -= V_641 ;
}
}
static void V_189 ( unsigned long V_642 )
{
struct V_1 * V_2 = (struct V_1 * ) V_642 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_169 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if( V_2 -> V_43 &&
( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_202 ) ) {
V_2 -> V_54 . V_643 ++ ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_43 = false ;
V_2 -> V_78 = V_2 -> V_79 = V_2 -> V_80 = 0 ;
if ( V_2 -> V_36 . V_12 & V_236 )
F_130 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
#if V_85
if ( V_2 -> V_86 )
F_39 ( V_2 ) ;
else
#endif
F_18 ( V_2 ) ;
}
static int F_149 ( struct V_1 * V_2 )
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
static void F_130 ( struct V_1 * V_2 )
{
F_35 ( V_2 , V_73 ) ;
F_34 ( V_2 , V_72 ) ;
F_23 ( V_2 ) ;
}
static void F_128 ( struct V_1 * V_2 )
{
V_2 -> V_53 = true ;
F_27 ( V_2 , V_59 ,
( F_25 ( V_2 , V_59 ) | V_52 ) ) ;
V_2 -> V_56 |= V_57 ;
F_27 ( V_2 , V_58 , V_2 -> V_56 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
return F_25 ( V_2 , V_518 ) & V_296 ? 1 : 0 ;
}
static int F_257 ( struct V_644 * V_645 , unsigned short V_481 ,
unsigned short V_145 )
{
struct V_1 * V_2 = F_258 ( V_645 ) ;
unsigned char V_646 ;
unsigned short V_647 ;
if ( V_2 -> V_42 . V_13 )
return - V_344 ;
switch ( V_481 )
{
case V_648 : V_646 = V_516 ; break;
case V_649 : V_646 = V_484 ; break;
case V_650 : V_646 = V_485 ; break;
case V_651 : V_646 = V_486 ; break;
case V_652 : V_646 = V_487 ; break;
default: return - V_294 ;
}
switch ( V_145 )
{
case V_653 : V_647 = V_654 ; break;
case V_655 : V_647 = V_491 ; break;
case V_656 : V_647 = V_492 ; break;
default: return - V_294 ;
}
V_2 -> V_36 . V_481 = V_646 ;
V_2 -> V_36 . V_489 = V_647 ;
if ( V_2 -> V_86 )
F_88 ( V_2 ) ;
return 0 ;
}
static T_9 F_259 ( struct V_657 * V_658 ,
struct V_644 * V_645 )
{
struct V_1 * V_2 = F_258 ( V_645 ) ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( V_659 L_170 , __FILE__ , V_645 -> V_3 ) ;
F_260 ( V_645 ) ;
V_2 -> V_78 = V_658 -> V_660 ;
F_102 ( V_2 , V_658 -> V_11 , V_658 -> V_660 ) ;
V_645 -> V_611 . V_661 ++ ;
V_645 -> V_611 . V_662 += V_658 -> V_660 ;
F_261 ( V_658 ) ;
V_645 -> V_663 = V_324 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! V_2 -> V_43 )
F_13 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_664 ;
}
static int F_262 ( struct V_644 * V_645 )
{
struct V_1 * V_2 = F_258 ( V_645 ) ;
int V_24 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_171 , __FILE__ , V_645 -> V_3 ) ;
V_24 = F_263 ( V_645 ) ;
if ( V_24 )
return V_24 ;
F_9 ( & V_2 -> V_343 , V_12 ) ;
if ( V_2 -> V_42 . V_13 != 0 || V_2 -> V_86 != 0 ) {
F_4 ( V_665 L_172 , V_645 -> V_3 ) ;
F_11 ( & V_2 -> V_343 , V_12 ) ;
return - V_344 ;
}
V_2 -> V_86 = 1 ;
F_11 ( & V_2 -> V_343 , V_12 ) ;
if ( ( V_24 = F_74 ( V_2 ) ) != 0 ) {
F_9 ( & V_2 -> V_343 , V_12 ) ;
V_2 -> V_86 = 0 ;
F_11 ( & V_2 -> V_343 , V_12 ) ;
return V_24 ;
}
V_2 -> V_83 |= V_84 | V_201 ;
F_88 ( V_2 ) ;
V_645 -> V_663 = V_324 ;
F_264 ( V_645 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( V_2 -> V_83 & V_265 )
F_43 ( V_645 ) ;
else
F_44 ( V_645 ) ;
return 0 ;
}
static int F_265 ( struct V_644 * V_645 )
{
struct V_1 * V_2 = F_258 ( V_645 ) ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_173 , __FILE__ , V_645 -> V_3 ) ;
F_260 ( V_645 ) ;
F_84 ( V_2 ) ;
F_266 ( V_645 ) ;
F_9 ( & V_2 -> V_343 , V_12 ) ;
V_2 -> V_86 = 0 ;
F_11 ( & V_2 -> V_343 , V_12 ) ;
return 0 ;
}
static int F_267 ( struct V_644 * V_645 , struct V_666 * V_667 , int V_299 )
{
const T_10 V_668 = sizeof( V_669 ) ;
V_669 V_670 ;
V_669 T_4 * line = V_667 -> V_671 . V_672 . V_673 ;
struct V_1 * V_2 = F_258 ( V_645 ) ;
unsigned int V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_174 , __FILE__ , V_645 -> V_3 ) ;
if ( V_2 -> V_42 . V_13 )
return - V_344 ;
if ( V_299 != V_674 )
return F_268 ( V_645 , V_667 , V_299 ) ;
switch( V_667 -> V_671 . type ) {
case V_675 :
V_667 -> V_671 . type = V_676 ;
if ( V_667 -> V_671 . V_668 < V_668 ) {
V_667 -> V_671 . V_668 = V_668 ;
return - V_677 ;
}
V_12 = V_2 -> V_36 . V_12 & ( V_678 | V_501 |
V_502 | V_503 |
V_679 | V_504 |
V_505 | V_506 ) ;
memset ( & V_670 , 0 , sizeof( V_670 ) ) ;
switch ( V_12 ) {
case ( V_678 | V_679 ) : V_670 . V_680 = V_681 ; break;
case ( V_502 | V_505 ) : V_670 . V_680 = V_682 ; break;
case ( V_678 | V_505 ) : V_670 . V_680 = V_683 ; break;
case ( V_678 | V_506 ) : V_670 . V_680 = V_684 ; break;
default: V_670 . V_680 = V_685 ;
}
V_670 . V_686 = V_2 -> V_36 . V_514 ;
V_670 . V_578 = V_2 -> V_36 . V_578 ? 1 : 0 ;
if ( F_269 ( line , & V_670 , V_668 ) )
return - V_243 ;
return 0 ;
case V_676 :
if( ! F_79 ( V_687 ) )
return - V_688 ;
if ( F_270 ( & V_670 , line , V_668 ) )
return - V_243 ;
switch ( V_670 . V_680 )
{
case V_681 : V_12 = V_678 | V_679 ; break;
case V_684 : V_12 = V_678 | V_506 ; break;
case V_682 : V_12 = V_502 | V_505 ; break;
case V_683 : V_12 = V_678 | V_505 ; break;
case V_685 : V_12 = V_2 -> V_36 . V_12 &
( V_678 | V_501 |
V_502 | V_503 |
V_679 | V_504 |
V_505 | V_506 ) ; break;
default: return - V_294 ;
}
if ( V_670 . V_578 != 0 && V_670 . V_578 != 1 )
return - V_294 ;
V_2 -> V_36 . V_12 &= ~ ( V_678 | V_501 |
V_502 | V_503 |
V_679 | V_504 |
V_505 | V_506 ) ;
V_2 -> V_36 . V_12 |= V_12 ;
V_2 -> V_36 . V_578 = V_670 . V_578 ;
if ( V_12 & ( V_502 | V_505 ) )
V_2 -> V_36 . V_514 = V_670 . V_686 ;
else
V_2 -> V_36 . V_514 = 0 ;
if ( V_2 -> V_86 )
F_88 ( V_2 ) ;
return 0 ;
default:
return F_268 ( V_645 , V_667 , V_299 ) ;
}
}
static void F_271 ( struct V_644 * V_645 )
{
struct V_1 * V_2 = F_258 ( V_645 ) ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_175 , V_645 -> V_3 ) ;
V_645 -> V_611 . V_689 ++ ;
V_645 -> V_611 . V_690 ++ ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_10 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
F_272 ( V_645 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( F_273 ( V_2 -> V_113 ) )
F_272 ( V_2 -> V_113 ) ;
}
static void F_249 ( struct V_1 * V_2 , char * V_231 , int V_668 )
{
struct V_657 * V_658 = F_274 ( V_668 ) ;
struct V_644 * V_645 = V_2 -> V_113 ;
if ( V_19 >= V_20 )
F_4 ( L_176 , V_645 -> V_3 ) ;
if ( V_658 == NULL ) {
F_4 ( V_691 L_177 ,
V_645 -> V_3 ) ;
V_645 -> V_611 . V_692 ++ ;
return;
}
memcpy ( F_275 ( V_658 , V_668 ) , V_231 , V_668 ) ;
V_658 -> V_693 = F_276 ( V_658 , V_645 ) ;
V_645 -> V_611 . V_694 ++ ;
V_645 -> V_611 . V_695 += V_668 ;
F_277 ( V_658 ) ;
}
static int F_214 ( struct V_1 * V_2 )
{
int V_24 ;
struct V_644 * V_645 ;
T_11 * V_696 ;
V_645 = F_278 ( V_2 ) ;
if ( ! V_645 ) {
F_4 ( V_181 L_178 , __FILE__ ) ;
return - V_188 ;
}
V_645 -> V_697 = V_2 -> V_136 ;
V_645 -> V_455 = V_2 -> V_176 ;
V_645 -> V_456 = V_2 -> V_352 ;
V_645 -> V_698 = & V_699 ;
V_645 -> V_700 = 10 * V_223 ;
V_645 -> V_701 = 50 ;
V_696 = F_279 ( V_645 ) ;
V_696 -> V_702 = F_257 ;
V_696 -> V_640 = F_259 ;
V_24 = F_280 ( V_645 ) ;
if ( V_24 ) {
F_4 ( V_665 L_179 , __FILE__ ) ;
F_281 ( V_645 ) ;
return V_24 ;
}
V_2 -> V_113 = V_645 ;
return 0 ;
}
static void F_229 ( struct V_1 * V_2 )
{
F_282 ( V_2 -> V_113 ) ;
F_281 ( V_2 -> V_113 ) ;
V_2 -> V_113 = NULL ;
}
static int F_283 ( struct V_703 * V_645 ,
const struct V_704 * V_705 )
{
struct V_1 * V_2 ;
if ( F_284 ( V_645 ) ) {
F_4 ( L_180 , V_645 ) ;
return - V_280 ;
}
V_2 = F_215 () ;
if ( ! V_2 ) {
F_4 ( L_145 ) ;
return - V_280 ;
}
V_2 -> V_136 = F_285 ( V_645 , 2 ) ;
V_2 -> V_176 = V_645 -> V_455 ;
V_2 -> V_350 = F_285 ( V_645 , 3 ) ;
V_2 -> V_351 = F_285 ( V_645 , 0 ) ;
V_2 -> V_420 = V_2 -> V_351 & ( V_423 - 1 ) ;
V_2 -> V_351 &= ~ ( V_423 - 1 ) ;
V_2 -> V_348 = V_349 ;
V_2 -> V_414 = 8 ;
V_2 -> V_416 = V_706 ;
if ( V_645 -> V_707 == 0x0210 ) {
V_2 -> V_570 = 0x007c4080 ;
V_2 -> V_432 = 1 ;
} else {
V_2 -> V_570 = 0x087e4546 ;
V_2 -> V_432 = 0 ;
}
F_213 ( V_2 ) ;
return 0 ;
}
static void F_286 ( struct V_703 * V_645 )
{
}
