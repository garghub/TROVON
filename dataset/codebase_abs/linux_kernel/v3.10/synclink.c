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
if ( V_49 & ( V_139 + V_140 +
V_65 + V_141 ) )
F_31 ( V_2 , V_142 ) ;
V_54 -> V_143 ++ ;
V_135 = 0 ;
if ( V_49 & ( V_139 + V_140 +
V_65 + V_141 ) ) {
F_4 ( L_25 , V_49 ) ;
if ( V_49 & V_141 ) {
V_49 &= ~ ( V_139 + V_140 ) ;
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
F_30 ( V_2 , V_131 + V_67 ) ;
F_59 ( V_2 , V_131 + V_67 ) ;
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
F_63 ( V_2 , V_160 , V_161 + V_162 ) ;
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
F_63 ( V_2 , V_160 , V_166 + V_167 ) ;
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
F_59 ( V_2 , V_131 + V_67 +
V_127 + V_69 + V_91 + V_159 ) ;
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
if ( V_10 -> V_198 . V_199 & V_224 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_83 &= ~ V_84 ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
static void F_114 ( struct V_9 * V_10 )
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
F_110 ( V_10 , F_115 ( V_10 ) ) ;
}
if ( V_10 -> V_198 . V_199 & V_224 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_83 |= V_84 ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
static int F_116 ( struct V_1 * V_2 , struct V_89 T_4 * V_240 )
{
int V_241 ;
if ( V_19 >= V_20 )
F_4 ( L_62 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( ! V_240 ) {
memset ( & V_2 -> V_54 , 0 , sizeof( V_2 -> V_54 ) ) ;
} else {
F_117 ( & V_2 -> V_42 . V_242 ) ;
F_118 ( V_241 , V_240 , & V_2 -> V_54 , sizeof( struct V_89 ) ) ;
F_119 ( & V_2 -> V_42 . V_242 ) ;
if ( V_241 )
return - V_243 ;
}
return 0 ;
}
static int F_120 ( struct V_1 * V_2 , T_5 T_4 * V_244 )
{
int V_241 ;
if ( V_19 >= V_20 )
F_4 ( L_62 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_117 ( & V_2 -> V_42 . V_242 ) ;
F_118 ( V_241 , V_244 , & V_2 -> V_36 , sizeof( T_5 ) ) ;
F_119 ( & V_2 -> V_42 . V_242 ) ;
if ( V_241 ) {
if ( V_19 >= V_20 )
F_4 ( L_63 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return - V_243 ;
}
return 0 ;
}
static int F_121 ( struct V_1 * V_2 , T_5 T_4 * V_245 )
{
unsigned long V_12 ;
T_5 V_246 ;
int V_241 ;
if ( V_19 >= V_20 )
F_4 ( L_64 , __FILE__ , __LINE__ ,
V_2 -> V_21 ) ;
F_122 ( V_241 , & V_246 , V_245 , sizeof( T_5 ) ) ;
if ( V_241 ) {
if ( V_19 >= V_20 )
F_4 ( L_65 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return - V_243 ;
}
F_117 ( & V_2 -> V_42 . V_242 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
memcpy ( & V_2 -> V_36 , & V_246 , sizeof( T_5 ) ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
F_82 ( V_2 ) ;
F_119 ( & V_2 -> V_42 . V_242 ) ;
return 0 ;
}
static int F_123 ( struct V_1 * V_2 , int T_4 * V_247 )
{
int V_241 ;
if ( V_19 >= V_20 )
F_4 ( L_66 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_247 ) ;
F_118 ( V_241 , V_247 , & V_2 -> V_247 , sizeof( int ) ) ;
if ( V_241 ) {
if ( V_19 >= V_20 )
F_4 ( L_67 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return - V_243 ;
}
return 0 ;
}
static int F_124 ( struct V_1 * V_2 , int V_247 )
{
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_68 , __FILE__ , __LINE__ ,
V_2 -> V_21 , V_247 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_247 = V_247 ;
F_125 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_126 ( struct V_1 * V_2 , int V_248 )
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
F_127 ( V_2 ) ;
}
} else {
if ( V_2 -> V_23 )
F_10 ( V_2 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_128 ( struct V_1 * V_2 )
{
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_70 , __FILE__ , __LINE__ ,
V_2 -> V_21 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( V_2 -> V_43 && V_2 -> V_36 . V_37 == V_38 )
{
if ( V_2 -> V_36 . V_12 & V_236 )
F_129 ( V_2 ) ;
else
F_130 ( V_2 , V_249 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
return 0 ;
}
static int F_131 ( struct V_1 * V_2 , int V_248 )
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
static int F_132 ( struct V_1 * V_2 , int T_4 * V_251 )
{
unsigned long V_12 ;
int V_252 ;
int V_24 = 0 ;
struct V_89 V_253 , V_254 ;
int V_255 ;
int V_256 ;
struct V_257 V_258 , V_259 ;
F_133 ( V_260 , V_261 ) ;
F_122 ( V_24 , & V_256 , V_251 , sizeof( int ) ) ;
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
F_134 ( V_278 ) ;
F_135 ( & V_2 -> V_64 , & V_260 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
for(; ; ) {
F_136 () ;
if ( F_137 ( V_261 ) ) {
V_24 = - V_279 ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_254 = V_2 -> V_54 ;
V_259 = V_2 -> V_100 ;
F_134 ( V_278 ) ;
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
F_138 ( & V_2 -> V_64 , & V_260 ) ;
F_134 ( V_281 ) ;
if ( V_256 & ( V_274 + V_275 ) ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! F_139 ( & V_2 -> V_64 ) ) {
F_27 ( V_2 , V_59 , F_25 ( V_2 , V_59 ) &
~ ( V_60 + V_61 ) ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
exit:
if ( V_24 == 0 )
F_140 ( V_24 , V_255 , V_251 ) ;
return V_24 ;
}
static int F_141 ( struct V_1 * V_2 , int V_282 )
{
unsigned long V_12 ;
int V_24 ;
struct V_89 V_253 , V_254 ;
F_133 ( V_260 , V_261 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_253 = V_2 -> V_54 ;
F_135 ( & V_2 -> V_119 , & V_260 ) ;
F_134 ( V_278 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
for(; ; ) {
F_136 () ;
if ( F_137 ( V_261 ) ) {
V_24 = - V_279 ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_254 = V_2 -> V_54 ;
F_134 ( V_278 ) ;
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
F_138 ( & V_2 -> V_119 , & V_260 ) ;
F_134 ( V_281 ) ;
return V_24 ;
}
static int F_142 ( struct V_9 * V_10 )
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
static int F_143 ( struct V_9 * V_10 ,
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
static int F_144 ( struct V_9 * V_10 , int V_293 )
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
static int F_145 ( struct V_9 * V_10 ,
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
static int F_146 ( struct V_9 * V_10 ,
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
return F_147 ( V_2 , V_299 , V_282 ) ;
}
static int F_147 ( struct V_1 * V_2 , unsigned int V_299 , unsigned long V_282 )
{
void T_4 * V_304 = ( void T_4 * ) V_282 ;
switch ( V_299 ) {
case V_305 :
return F_120 ( V_2 , V_304 ) ;
case V_306 :
return F_121 ( V_2 , V_304 ) ;
case V_307 :
return F_123 ( V_2 , V_304 ) ;
case V_308 :
return F_124 ( V_2 , ( int ) V_282 ) ;
case V_309 :
return F_126 ( V_2 , ( int ) V_282 ) ;
case V_310 :
return F_131 ( V_2 , ( int ) V_282 ) ;
case V_311 :
return F_128 ( V_2 ) ;
case V_312 :
return F_116 ( V_2 , V_304 ) ;
case V_313 :
return F_132 ( V_2 , V_304 ) ;
case V_314 :
return F_148 ( V_2 ) ;
case V_303 :
return F_141 ( V_2 , ( int ) V_282 ) ;
default:
return - V_315 ;
}
return 0 ;
}
static void F_149 ( struct V_9 * V_10 , struct V_316 * V_317 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_79 , __FILE__ , __LINE__ ,
V_10 -> V_318 -> V_3 ) ;
F_82 ( V_2 ) ;
if ( V_317 -> V_199 & V_206 &&
! ( V_10 -> V_198 . V_199 & V_206 ) ) {
V_2 -> V_83 &= ~ ( V_84 | V_201 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
if ( ! ( V_317 -> V_199 & V_206 ) &&
V_10 -> V_198 . V_199 & V_206 ) {
V_2 -> V_83 |= V_201 ;
if ( ! ( V_10 -> V_198 . V_199 & V_224 ) ||
! F_150 ( V_319 , & V_10 -> V_12 ) ) {
V_2 -> V_83 |= V_84 ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_38 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
if ( V_317 -> V_199 & V_224 &&
! ( V_10 -> V_198 . V_199 & V_224 ) ) {
V_10 -> V_88 = 0 ;
F_12 ( V_10 ) ;
}
}
static void F_151 ( struct V_9 * V_10 , struct V_320 * V_321 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_80 ) )
return;
if ( V_19 >= V_20 )
F_4 ( L_81 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_42 . V_13 ) ;
if ( F_152 ( & V_2 -> V_42 , V_10 , V_321 ) == 0 )
goto V_233;
F_117 ( & V_2 -> V_42 . V_242 ) ;
if ( V_2 -> V_42 . V_12 & V_185 )
F_153 ( V_10 , V_2 -> V_222 ) ;
F_109 ( V_10 ) ;
F_154 ( V_10 ) ;
F_84 ( V_2 ) ;
F_119 ( & V_2 -> V_42 . V_242 ) ;
F_155 ( & V_2 -> V_42 , V_10 ) ;
V_2 -> V_42 . V_10 = NULL ;
V_233:
if ( V_19 >= V_20 )
F_4 ( L_82 , __FILE__ , __LINE__ ,
V_10 -> V_318 -> V_3 , V_2 -> V_42 . V_13 ) ;
}
static void F_153 ( struct V_9 * V_10 , int V_222 )
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
F_156 ( F_157 ( V_323 ) ) ;
if ( F_137 ( V_261 ) )
break;
if ( V_222 && F_158 ( V_324 , V_322 + V_222 ) )
break;
}
} else {
while ( ! ( F_25 ( V_2 , V_68 ) & V_325 ) &&
V_2 -> V_23 ) {
F_156 ( F_157 ( V_323 ) ) ;
if ( F_137 ( V_261 ) )
break;
if ( V_222 && F_158 ( V_324 , V_322 + V_222 ) )
break;
}
}
exit:
if ( V_19 >= V_20 )
F_4 ( L_85 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
}
static void F_159 ( struct V_9 * V_10 )
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
static int F_160 ( struct V_327 * V_42 )
{
unsigned long V_12 ;
struct V_1 * V_2 = F_16 ( V_42 , struct V_1 , V_42 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return ( V_2 -> V_83 & V_265 ) ? 1 : 0 ;
}
static void F_161 ( struct V_327 * V_42 , int V_328 )
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
static int F_162 ( struct V_9 * V_10 , struct V_320 * V_321 ,
struct V_1 * V_2 )
{
F_133 ( V_260 , V_261 ) ;
int V_184 ;
bool V_329 = false ;
bool V_330 = false ;
unsigned long V_12 ;
int V_109 ;
struct V_327 * V_42 = & V_2 -> V_42 ;
if ( V_19 >= V_20 )
F_4 ( L_88 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_3 ) ;
if ( V_321 -> V_331 & V_332 || V_10 -> V_12 & ( 1 << V_191 ) ) {
V_42 -> V_12 |= V_326 ;
return 0 ;
}
if ( V_10 -> V_198 . V_199 & V_226 )
V_329 = true ;
V_184 = 0 ;
F_135 ( & V_42 -> V_121 , & V_260 ) ;
if ( V_19 >= V_20 )
F_4 ( L_89 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_3 , V_42 -> V_13 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! F_163 ( V_321 ) ) {
V_330 = true ;
V_42 -> V_13 -- ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_42 -> V_333 ++ ;
while ( 1 ) {
if ( F_164 ( V_10 ) && F_150 ( V_334 , & V_42 -> V_12 ) )
F_165 ( V_42 ) ;
F_134 ( V_278 ) ;
if ( F_163 ( V_321 ) || ! ( V_42 -> V_12 & V_185 ) ) {
V_184 = ( V_42 -> V_12 & V_335 ) ?
- V_336 : - V_279 ;
break;
}
V_109 = F_166 ( & V_2 -> V_42 ) ;
if ( ! ( V_42 -> V_12 & V_337 ) && ( V_329 || V_109 ) )
break;
if ( F_137 ( V_261 ) ) {
V_184 = - V_279 ;
break;
}
if ( V_19 >= V_20 )
F_4 ( L_90 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_3 , V_42 -> V_13 ) ;
F_167 ( V_10 ) ;
F_136 () ;
F_168 ( V_10 ) ;
}
F_134 ( V_281 ) ;
F_138 ( & V_42 -> V_121 , & V_260 ) ;
if ( V_330 )
V_42 -> V_13 ++ ;
V_42 -> V_333 -- ;
if ( V_19 >= V_20 )
F_4 ( L_91 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_3 , V_42 -> V_13 ) ;
if ( ! V_184 )
V_42 -> V_12 |= V_326 ;
return V_184 ;
}
static int F_169 ( struct V_338 * V_318 , struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int line = V_10 -> V_339 ;
if ( line >= V_340 ) {
F_4 ( L_92 ,
__FILE__ , __LINE__ , line ) ;
return - V_300 ;
}
V_2 = V_341 ;
while ( V_2 && V_2 -> line != line )
V_2 = V_2 -> V_342 ;
if ( F_2 ( V_2 , V_10 -> V_3 , L_93 ) )
return - V_300 ;
V_10 -> V_18 = V_2 ;
return F_170 ( & V_2 -> V_42 , V_318 , V_10 ) ;
}
static int F_171 ( struct V_9 * V_10 , struct V_320 * V_321 )
{
struct V_1 * V_2 = V_10 -> V_18 ;
unsigned long V_12 ;
int V_184 ;
V_2 -> V_42 . V_10 = V_10 ;
if ( V_19 >= V_20 )
F_4 ( L_94 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_3 , V_2 -> V_42 . V_13 ) ;
if ( F_163 ( V_321 ) || V_2 -> V_42 . V_12 & V_337 ) {
if ( V_2 -> V_42 . V_12 & V_337 )
F_172 ( & V_2 -> V_42 . V_343 ) ;
V_184 = ( ( V_2 -> V_42 . V_12 & V_335 ) ?
- V_336 : - V_279 ) ;
goto V_233;
}
V_2 -> V_42 . V_344 = ( V_2 -> V_42 . V_12 & V_345 ) ? 1 : 0 ;
F_9 ( & V_2 -> V_346 , V_12 ) ;
if ( V_2 -> V_86 ) {
V_184 = - V_347 ;
F_11 ( & V_2 -> V_346 , V_12 ) ;
goto V_233;
}
V_2 -> V_42 . V_13 ++ ;
F_11 ( & V_2 -> V_346 , V_12 ) ;
if ( V_2 -> V_42 . V_13 == 1 ) {
V_184 = F_74 ( V_2 ) ;
if ( V_184 < 0 )
goto V_233;
}
V_184 = F_162 ( V_10 , V_321 , V_2 ) ;
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
static inline void F_173 ( struct V_348 * V_349 , struct V_1 * V_2 )
{
char V_350 [ 30 ] ;
unsigned long V_12 ;
if ( V_2 -> V_351 == V_352 ) {
F_174 ( V_349 , L_97 ,
V_2 -> V_21 , V_2 -> V_136 , V_2 -> V_176 ,
V_2 -> V_353 , V_2 -> V_354 ) ;
} else {
F_174 ( V_349 , L_98 ,
V_2 -> V_21 , V_2 -> V_136 ,
V_2 -> V_176 , V_2 -> V_355 ) ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_350 [ 0 ] = 0 ;
V_350 [ 1 ] = 0 ;
if ( V_2 -> V_83 & V_84 )
strcat ( V_350 , L_99 ) ;
if ( V_2 -> V_83 & V_268 )
strcat ( V_350 , L_100 ) ;
if ( V_2 -> V_83 & V_201 )
strcat ( V_350 , L_101 ) ;
if ( V_2 -> V_83 & V_262 )
strcat ( V_350 , L_102 ) ;
if ( V_2 -> V_83 & V_265 )
strcat ( V_350 , L_103 ) ;
if ( V_2 -> V_83 & V_271 )
strcat ( V_350 , L_104 ) ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_202 ) {
F_174 ( V_349 , L_105 ,
V_2 -> V_54 . V_75 , V_2 -> V_54 . V_356 ) ;
if ( V_2 -> V_54 . V_76 )
F_174 ( V_349 , L_106 , V_2 -> V_54 . V_76 ) ;
if ( V_2 -> V_54 . V_77 )
F_174 ( V_349 , L_107 , V_2 -> V_54 . V_77 ) ;
if ( V_2 -> V_54 . V_357 )
F_174 ( V_349 , L_108 , V_2 -> V_54 . V_357 ) ;
if ( V_2 -> V_54 . V_358 )
F_174 ( V_349 , L_109 , V_2 -> V_54 . V_358 ) ;
if ( V_2 -> V_54 . V_66 )
F_174 ( V_349 , L_110 , V_2 -> V_54 . V_66 ) ;
if ( V_2 -> V_54 . V_359 )
F_174 ( V_349 , L_111 , V_2 -> V_54 . V_359 ) ;
} else {
F_174 ( V_349 , L_112 ,
V_2 -> V_54 . V_298 , V_2 -> V_54 . V_143 ) ;
if ( V_2 -> V_54 . V_146 )
F_174 ( V_349 , L_113 , V_2 -> V_54 . V_146 ) ;
if ( V_2 -> V_54 . V_145 )
F_174 ( V_349 , L_114 , V_2 -> V_54 . V_145 ) ;
if ( V_2 -> V_54 . V_144 )
F_174 ( V_349 , L_115 , V_2 -> V_54 . V_144 ) ;
if ( V_2 -> V_54 . V_148 )
F_174 ( V_349 , L_116 , V_2 -> V_54 . V_148 ) ;
}
F_174 ( V_349 , L_117 , V_350 + 1 ) ;
F_174 ( V_349 , L_118 ,
V_2 -> V_43 , V_2 -> V_30 , V_2 -> V_29 ,
V_2 -> V_25 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
{
T_2 V_360 = F_25 ( V_2 , V_68 ) ;
T_2 V_361 = F_64 ( V_2 , V_168 ) ;
T_2 V_362 = F_25 ( V_2 , V_363 ) ;
T_2 V_364 = F_25 ( V_2 , V_50 ) ;
T_2 V_365 = F_64 ( V_2 , V_163 ) ;
T_2 V_366 = F_25 ( V_2 , V_59 ) ;
T_2 V_367 = F_25 ( V_2 , V_368 ) ;
T_2 V_369 = F_25 ( V_2 , V_370 ) ;
T_2 V_371 = F_25 ( V_2 , V_372 ) ;
T_2 V_373 = F_25 ( V_2 , V_374 ) ;
T_2 V_375 = F_52 ( V_2 -> V_136 + V_137 ) ;
F_174 ( V_349 , L_119
L_120 ,
V_360 , V_361 , V_362 , V_364 , V_365 , V_366 , V_367 , V_369 , V_371 , V_373 , V_375 ) ;
}
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
static int F_175 ( struct V_348 * V_349 , void * V_376 )
{
struct V_1 * V_2 ;
F_174 ( V_349 , L_121 , V_377 ) ;
V_2 = V_341 ;
while( V_2 ) {
F_173 ( V_349 , V_2 ) ;
V_2 = V_2 -> V_342 ;
}
return 0 ;
}
static int F_176 ( struct V_378 * V_378 , struct V_320 * V_320 )
{
return F_177 ( V_320 , F_175 , NULL ) ;
}
static int F_178 ( struct V_1 * V_2 )
{
unsigned short V_379 ;
V_2 -> V_380 = 0 ;
V_379 = ( unsigned short ) ( V_2 -> V_238 / V_381 ) ;
if ( V_2 -> V_238 % V_381 )
V_379 ++ ;
if ( V_2 -> V_351 == V_352 ) {
V_2 -> V_382 = V_2 -> V_383 * V_379 ;
V_2 -> V_384 = 62 - V_2 -> V_382 ;
} else {
V_2 -> V_382 = V_2 -> V_383 * V_379 ;
V_2 -> V_384 = ( V_379 * V_385 ) + 6 ;
if ( ( V_2 -> V_382 + V_2 -> V_384 ) > 62 )
V_2 -> V_384 = 62 - V_2 -> V_382 ;
}
if ( V_19 >= V_20 )
F_4 ( L_122 ,
__FILE__ , __LINE__ , V_2 -> V_382 , V_2 -> V_384 ) ;
if ( F_179 ( V_2 ) < 0 ||
F_180 ( V_2 , V_2 -> V_386 , V_2 -> V_384 ) < 0 ||
F_180 ( V_2 , V_2 -> V_387 , V_2 -> V_382 ) < 0 ||
F_181 ( V_2 ) < 0 ||
F_182 ( V_2 ) < 0 ) {
F_4 ( L_123 , __FILE__ , __LINE__ ) ;
return - V_188 ;
}
F_183 ( V_2 ) ;
F_184 ( V_2 ) ;
return 0 ;
}
static int F_179 ( struct V_1 * V_2 )
{
unsigned int V_388 ;
if ( V_2 -> V_351 == V_352 ) {
V_2 -> V_389 = V_2 -> V_390 + V_2 -> V_380 ;
V_2 -> V_391 = V_2 -> V_380 ;
V_2 -> V_380 += V_392 ;
} else {
V_2 -> V_389 = F_185 ( NULL , V_392 , & V_2 -> V_393 , V_187 ) ;
if ( V_2 -> V_389 == NULL )
return - V_188 ;
V_2 -> V_391 = ( V_394 ) ( V_2 -> V_393 ) ;
}
memset ( V_2 -> V_389 , 0 , V_392 ) ;
V_2 -> V_386 = ( V_395 * ) V_2 -> V_389 ;
V_2 -> V_387 = ( V_395 * ) V_2 -> V_389 ;
V_2 -> V_387 += V_2 -> V_384 ;
for ( V_388 = 0 ; V_388 < V_2 -> V_384 ; V_388 ++ ) {
V_2 -> V_386 [ V_388 ] . V_396 =
V_2 -> V_391 + ( V_388 * sizeof( V_395 ) ) ;
V_2 -> V_386 [ V_388 ] . V_397 = V_2 -> V_391 ;
if ( V_388 < V_2 -> V_384 - 1 )
V_2 -> V_386 [ V_388 ] . V_397 += ( V_388 + 1 ) * sizeof( V_395 ) ;
}
for ( V_388 = 0 ; V_388 < V_2 -> V_382 ; V_388 ++ ) {
V_2 -> V_387 [ V_388 ] . V_396 = V_2 -> V_391 +
( ( V_2 -> V_384 + V_388 ) * sizeof( V_395 ) ) ;
V_2 -> V_387 [ V_388 ] . V_397 = V_2 -> V_391 +
V_2 -> V_384 * sizeof( V_395 ) ;
if ( V_388 < V_2 -> V_382 - 1 )
V_2 -> V_387 [ V_388 ] . V_397 += ( V_388 + 1 ) * sizeof( V_395 ) ;
}
return 0 ;
}
static void F_186 ( struct V_1 * V_2 )
{
if ( V_2 -> V_389 && V_2 -> V_351 != V_352 )
F_187 ( NULL , V_392 , V_2 -> V_389 , V_2 -> V_393 ) ;
V_2 -> V_389 = NULL ;
V_2 -> V_386 = NULL ;
V_2 -> V_387 = NULL ;
}
static int F_180 ( struct V_1 * V_2 , V_395 * V_398 , int V_399 )
{
int V_388 ;
V_394 V_400 ;
for ( V_388 = 0 ; V_388 < V_399 ; V_388 ++ ) {
if ( V_2 -> V_351 == V_352 ) {
V_398 [ V_388 ] . V_401 = V_2 -> V_390 + V_2 -> V_380 ;
V_400 = V_2 -> V_380 ;
V_2 -> V_380 += V_381 ;
} else {
V_398 [ V_388 ] . V_401 = F_185 ( NULL , V_381 , & V_398 [ V_388 ] . V_402 , V_187 ) ;
if ( V_398 [ V_388 ] . V_401 == NULL )
return - V_188 ;
V_400 = ( V_394 ) ( V_398 [ V_388 ] . V_402 ) ;
}
V_398 [ V_388 ] . V_400 = V_400 ;
}
return 0 ;
}
static void F_188 ( struct V_1 * V_2 , V_395 * V_398 , int V_399 )
{
int V_388 ;
if ( V_398 ) {
for ( V_388 = 0 ; V_388 < V_399 ; V_388 ++ ) {
if ( V_398 [ V_388 ] . V_401 ) {
if ( V_2 -> V_351 != V_352 )
F_187 ( NULL , V_381 , V_398 [ V_388 ] . V_401 , V_398 [ V_388 ] . V_402 ) ;
V_398 [ V_388 ] . V_401 = NULL ;
}
}
}
}
static void F_189 ( struct V_1 * V_2 )
{
F_188 ( V_2 , V_2 -> V_386 , V_2 -> V_384 ) ;
F_188 ( V_2 , V_2 -> V_387 , V_2 -> V_382 ) ;
F_186 ( V_2 ) ;
}
static int F_181 ( struct V_1 * V_2 )
{
V_2 -> V_403 = F_190 ( V_2 -> V_238 , V_187 | V_404 ) ;
if ( V_2 -> V_403 == NULL )
return - V_188 ;
V_2 -> V_405 = F_191 ( V_2 -> V_238 , V_187 ) ;
if ( ! V_2 -> V_405 ) {
F_192 ( V_2 -> V_403 ) ;
V_2 -> V_403 = NULL ;
return - V_188 ;
}
return 0 ;
}
static void F_193 ( struct V_1 * V_2 )
{
F_192 ( V_2 -> V_403 ) ;
V_2 -> V_403 = NULL ;
F_192 ( V_2 -> V_405 ) ;
V_2 -> V_405 = NULL ;
}
static int F_182 ( struct V_1 * V_2 )
{
int V_388 ;
if ( V_19 >= V_20 )
F_4 ( L_124 ,
V_2 -> V_21 , __FILE__ , __LINE__ , V_2 -> V_235 ) ;
memset ( V_2 -> V_406 , 0 , sizeof( V_2 -> V_406 ) ) ;
for ( V_388 = 0 ; V_388 < V_2 -> V_235 ; ++ V_388 ) {
V_2 -> V_406 [ V_388 ] . V_407 =
F_190 ( V_2 -> V_238 , V_187 ) ;
if ( V_2 -> V_406 [ V_388 ] . V_407 == NULL ) {
for ( -- V_388 ; V_388 >= 0 ; V_388 -- ) {
F_192 ( V_2 -> V_406 [ V_388 ] . V_407 ) ;
V_2 -> V_406 [ V_388 ] . V_407 = NULL ;
}
return - V_188 ;
}
}
return 0 ;
}
static void F_194 ( struct V_1 * V_2 )
{
int V_388 ;
for ( V_388 = 0 ; V_388 < V_2 -> V_235 ; ++ V_388 ) {
F_192 ( V_2 -> V_406 [ V_388 ] . V_407 ) ;
V_2 -> V_406 [ V_388 ] . V_407 = NULL ;
}
V_2 -> V_408 = 0 ;
V_2 -> V_409 = 0 ;
V_2 -> V_234 = 0 ;
}
static bool F_66 ( struct V_1 * V_2 )
{
bool V_228 = false ;
if ( V_2 -> V_234 ) {
struct V_410 * V_411 =
& V_2 -> V_406 [ V_2 -> V_408 ] ;
int V_412 = F_195 ( V_2 ) ;
int V_413 = V_411 -> V_414 / V_381 ;
if ( V_411 -> V_414 % V_381 )
++ V_413 ;
if ( V_413 <= V_412 ) {
V_2 -> V_78 = V_411 -> V_414 ;
F_102 ( V_2 , V_411 -> V_407 , V_411 -> V_414 ) ;
-- V_2 -> V_234 ;
if ( ++ V_2 -> V_408 >= V_2 -> V_235 )
V_2 -> V_408 = 0 ;
F_196 ( & V_2 -> V_81 , V_324 + F_197 ( 5000 ) ) ;
V_228 = true ;
}
}
return V_228 ;
}
static int F_104 ( struct V_1 * V_2 , const char * V_415 , unsigned int V_416 )
{
struct V_410 * V_411 ;
if ( V_2 -> V_234 >= V_2 -> V_235 ) {
return 0 ;
}
V_411 = & V_2 -> V_406 [ V_2 -> V_409 ] ;
V_411 -> V_414 = V_416 ;
memcpy ( V_411 -> V_407 , V_415 , V_416 ) ;
++ V_2 -> V_234 ;
if ( ++ V_2 -> V_409 >= V_2 -> V_235 )
V_2 -> V_409 = 0 ;
return 1 ;
}
static int F_77 ( struct V_1 * V_2 )
{
if ( F_198 ( V_2 -> V_136 , V_2 -> V_417 , L_125 ) == NULL ) {
F_4 ( L_126 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_136 ) ;
return - V_300 ;
}
V_2 -> V_418 = true ;
if ( F_199 ( V_2 -> V_176 , F_67 , V_2 -> V_419 ,
V_2 -> V_21 , V_2 ) < 0 ) {
F_4 ( L_127 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_176 ) ;
goto V_420;
}
V_2 -> V_421 = true ;
if ( V_2 -> V_351 == V_352 ) {
if ( F_200 ( V_2 -> V_353 , 0x40000 , L_125 ) == NULL ) {
F_4 ( L_128 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_353 ) ;
goto V_420;
}
V_2 -> V_422 = true ;
if ( F_200 ( V_2 -> V_354 + V_2 -> V_423 , 128 , L_125 ) == NULL ) {
F_4 ( L_129 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_354 + V_2 -> V_423 ) ;
goto V_420;
}
V_2 -> V_424 = true ;
V_2 -> V_390 = F_201 ( V_2 -> V_353 ,
0x40000 ) ;
if ( ! V_2 -> V_390 ) {
F_4 ( L_130 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_353 ) ;
goto V_420;
}
if ( ! F_202 ( V_2 ) ) {
F_4 ( L_131 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_353 ) ;
goto V_420;
}
V_2 -> V_425 = F_201 ( V_2 -> V_354 ,
V_426 ) ;
if ( ! V_2 -> V_425 ) {
F_4 ( L_132 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_354 ) ;
goto V_420;
}
V_2 -> V_425 += V_2 -> V_423 ;
} else {
if ( F_203 ( V_2 -> V_355 , V_2 -> V_21 ) < 0 ) {
F_4 ( L_133 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_355 ) ;
F_81 ( V_2 ) ;
return - V_300 ;
}
V_2 -> V_427 = true ;
F_204 ( V_2 -> V_355 , V_428 ) ;
F_205 ( V_2 -> V_355 ) ;
}
if ( F_178 ( V_2 ) < 0 ) {
F_4 ( L_134 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_2 -> V_355 ) ;
goto V_420;
}
return 0 ;
V_420:
F_81 ( V_2 ) ;
return - V_300 ;
}
static void F_81 ( struct V_1 * V_2 )
{
if ( V_19 >= V_20 )
F_4 ( L_135 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( V_2 -> V_421 ) {
F_206 ( V_2 -> V_176 , V_2 ) ;
V_2 -> V_421 = false ;
}
if ( V_2 -> V_427 ) {
F_207 ( V_2 -> V_355 ) ;
F_208 ( V_2 -> V_355 ) ;
V_2 -> V_427 = false ;
}
F_189 ( V_2 ) ;
F_193 ( V_2 ) ;
F_194 ( V_2 ) ;
if ( V_2 -> V_418 ) {
F_209 ( V_2 -> V_136 , V_2 -> V_417 ) ;
V_2 -> V_418 = false ;
}
if ( V_2 -> V_422 ) {
F_210 ( V_2 -> V_353 , 0x40000 ) ;
V_2 -> V_422 = false ;
}
if ( V_2 -> V_424 ) {
F_210 ( V_2 -> V_354 + V_2 -> V_423 , 128 ) ;
V_2 -> V_424 = false ;
}
if ( V_2 -> V_390 ) {
F_211 ( V_2 -> V_390 ) ;
V_2 -> V_390 = NULL ;
}
if ( V_2 -> V_425 ) {
F_211 ( V_2 -> V_425 - V_2 -> V_423 ) ;
V_2 -> V_425 = NULL ;
}
if ( V_19 >= V_20 )
F_4 ( L_136 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
}
static void F_212 ( struct V_1 * V_2 )
{
V_2 -> V_342 = NULL ;
V_2 -> line = V_340 ;
sprintf ( V_2 -> V_21 , L_137 , V_2 -> line ) ;
if ( V_2 -> line < V_429 ) {
if ( V_430 [ V_2 -> line ] )
V_2 -> V_238 = V_430 [ V_2 -> line ] ;
if ( V_431 [ V_2 -> line ] ) {
V_2 -> V_383 = V_431 [ V_2 -> line ] ;
if ( V_2 -> V_383 < 1 )
V_2 -> V_383 = 1 ;
}
if ( V_432 [ V_2 -> line ] ) {
V_2 -> V_235 = V_432 [ V_2 -> line ] ;
if ( V_2 -> V_235 < 1 )
V_2 -> V_235 = 1 ;
else if ( V_2 -> V_235 > V_433 )
V_2 -> V_235 = V_433 ;
}
}
V_340 ++ ;
if ( ! V_341 )
V_341 = V_2 ;
else {
struct V_1 * V_434 = V_341 ;
while( V_434 -> V_342 )
V_434 = V_434 -> V_342 ;
V_434 -> V_342 = V_2 ;
}
if ( V_2 -> V_238 < 4096 )
V_2 -> V_238 = 4096 ;
else if ( V_2 -> V_238 > 65535 )
V_2 -> V_238 = 65535 ;
if ( V_2 -> V_351 == V_352 ) {
F_4 ( L_138 ,
V_2 -> V_435 + 1 , V_2 -> V_21 , V_2 -> V_136 , V_2 -> V_176 ,
V_2 -> V_353 , V_2 -> V_354 ,
V_2 -> V_238 ) ;
} else {
F_4 ( L_139 ,
V_2 -> V_21 , V_2 -> V_136 , V_2 -> V_176 , V_2 -> V_355 ,
V_2 -> V_238 ) ;
}
#if V_85
F_213 ( V_2 ) ;
#endif
}
static struct V_1 * F_214 ( void )
{
struct V_1 * V_2 ;
V_2 = F_191 ( sizeof( struct V_1 ) ,
V_187 ) ;
if ( ! V_2 ) {
F_4 ( L_140 ) ;
} else {
F_215 ( & V_2 -> V_42 ) ;
V_2 -> V_42 . V_16 = & V_436 ;
V_2 -> V_7 = V_8 ;
F_216 ( & V_2 -> V_33 , F_15 ) ;
V_2 -> V_238 = 4096 ;
V_2 -> V_42 . V_437 = 5 * V_223 / 10 ;
V_2 -> V_42 . V_438 = 30 * V_223 ;
F_217 ( & V_2 -> V_119 ) ;
F_217 ( & V_2 -> V_64 ) ;
F_218 ( & V_2 -> V_22 ) ;
F_218 ( & V_2 -> V_346 ) ;
memcpy ( & V_2 -> V_36 , & V_439 , sizeof( T_5 ) ) ;
V_2 -> V_247 = V_440 ;
V_2 -> V_383 = 1 ;
V_2 -> V_235 = 0 ;
}
return V_2 ;
}
static int F_219 ( void )
{
int V_24 ;
V_441 = F_220 ( 128 ) ;
if ( ! V_441 )
return - V_188 ;
V_441 -> V_442 = L_125 ;
V_441 -> V_3 = L_141 ;
V_441 -> V_443 = V_444 ;
V_441 -> V_445 = 64 ;
V_441 -> type = V_446 ;
V_441 -> V_447 = V_448 ;
V_441 -> V_449 = V_450 ;
V_441 -> V_449 . V_199 =
V_451 | V_212 | V_203 | V_200 | V_226 ;
V_441 -> V_449 . V_452 = 9600 ;
V_441 -> V_449 . V_453 = 9600 ;
V_441 -> V_12 = V_454 ;
F_221 ( V_441 , & V_455 ) ;
if ( ( V_24 = F_222 ( V_441 ) ) < 0 ) {
F_4 ( L_142 ,
__FILE__ , __LINE__ ) ;
F_223 ( V_441 ) ;
V_441 = NULL ;
return V_24 ;
}
F_4 ( L_143 ,
V_442 , V_377 ,
V_441 -> V_443 ) ;
return 0 ;
}
static void F_224 ( void )
{
struct V_1 * V_2 ;
int V_388 ;
for ( V_388 = 0 ; ( V_388 < V_456 ) && V_457 [ V_388 ] && V_458 [ V_388 ] ; V_388 ++ ) {
if ( V_19 >= V_20 )
F_4 ( L_144 ,
V_457 [ V_388 ] , V_458 [ V_388 ] , V_459 [ V_388 ] ) ;
V_2 = F_214 () ;
if ( ! V_2 ) {
if ( V_19 >= V_460 )
F_4 ( L_145 ) ;
continue;
}
V_2 -> V_136 = ( unsigned int ) V_457 [ V_388 ] ;
V_2 -> V_176 = ( unsigned int ) V_458 [ V_388 ] ;
V_2 -> V_176 = F_225 ( V_2 -> V_176 ) ;
V_2 -> V_355 = ( unsigned int ) V_459 [ V_388 ] ;
V_2 -> V_351 = V_461 ;
V_2 -> V_417 = 16 ;
V_2 -> V_419 = 0 ;
F_212 ( V_2 ) ;
}
}
static void F_226 ( void )
{
int V_24 ;
struct V_1 * V_2 ;
struct V_1 * V_462 ;
F_4 ( L_146 , V_442 , V_377 ) ;
if ( V_441 ) {
if ( ( V_24 = F_227 ( V_441 ) ) )
F_4 ( L_147 ,
__FILE__ , __LINE__ , V_24 ) ;
F_223 ( V_441 ) ;
}
V_2 = V_341 ;
while( V_2 ) {
#if V_85
F_228 ( V_2 ) ;
#endif
F_81 ( V_2 ) ;
V_462 = V_2 ;
V_2 = V_2 -> V_342 ;
F_229 ( & V_462 -> V_42 ) ;
F_192 ( V_462 ) ;
}
if ( V_463 )
F_230 ( & V_464 ) ;
}
static int T_6 F_231 ( void )
{
int V_24 ;
if ( V_465 ) {
F_1 () ;
F_232 () ;
}
F_4 ( L_148 , V_442 , V_377 ) ;
F_224 () ;
if ( ( V_24 = F_233 ( & V_464 ) ) < 0 )
F_4 ( L_149 , __FILE__ , V_24 ) ;
else
V_463 = true ;
if ( ( V_24 = F_219 () ) < 0 )
goto error;
return 0 ;
error:
F_226 () ;
return V_24 ;
}
static void T_7 F_234 ( void )
{
F_226 () ;
}
static void F_35 ( struct V_1 * V_2 , T_2 V_466 )
{
F_51 ( V_466 + V_2 -> V_467 , V_2 -> V_136 + V_137 ) ;
if ( V_2 -> V_351 == V_352 )
F_52 ( V_2 -> V_136 + V_137 ) ;
}
static void F_34 ( struct V_1 * V_2 , T_2 V_466 )
{
F_51 ( V_466 + V_2 -> V_468 , V_2 -> V_136 ) ;
if ( V_2 -> V_351 == V_352 )
F_52 ( V_2 -> V_136 ) ;
}
static void F_63 ( struct V_1 * V_2 , T_2 V_469 , T_2 V_470 )
{
F_51 ( V_469 + V_2 -> V_468 , V_2 -> V_136 ) ;
F_51 ( V_470 , V_2 -> V_136 ) ;
if ( V_2 -> V_351 == V_352 )
F_52 ( V_2 -> V_136 ) ;
}
static T_2 F_64 ( struct V_1 * V_2 , T_2 V_469 )
{
F_51 ( V_469 + V_2 -> V_468 , V_2 -> V_136 ) ;
return F_52 ( V_2 -> V_136 ) ;
}
static void F_27 ( struct V_1 * V_2 , T_2 V_469 , T_2 V_470 )
{
F_51 ( V_469 + V_2 -> V_467 , V_2 -> V_136 + V_137 ) ;
F_51 ( V_470 , V_2 -> V_136 + V_137 ) ;
if ( V_2 -> V_351 == V_352 )
F_52 ( V_2 -> V_136 + V_137 ) ;
}
static T_2 F_25 ( struct V_1 * V_2 , T_2 V_469 )
{
F_51 ( V_469 + V_2 -> V_467 , V_2 -> V_136 + V_137 ) ;
return F_52 ( V_2 -> V_136 + V_137 ) ;
}
static void F_235 ( struct V_1 * V_2 )
{
T_2 V_470 ;
bool V_471 ;
F_27 ( V_2 , V_472 , 0x1f ) ;
V_470 = F_25 ( V_2 , V_473 ) ;
V_471 = ( V_470 == V_474 ) ;
if ( V_2 -> V_36 . V_12 & V_236 )
{
V_470 = 0x8e06 ;
}
else
{
if ( V_2 -> V_36 . V_37 == V_202 ) {
V_470 = 0x0001 ;
F_27 ( V_2 , V_295 ,
( unsigned short ) ( ( F_25 ( V_2 , V_295 ) & ~ ( V_57 | V_197 ) ) | V_197 ) ) ;
V_470 |= 0x0400 ;
}
else {
V_470 = 0x0606 ;
if ( V_2 -> V_36 . V_12 & V_475 )
V_470 |= V_196 ;
else if ( V_2 -> V_36 . V_12 & V_476 )
V_470 |= V_195 ;
else if ( V_2 -> V_36 . V_12 & V_477 )
V_470 |= V_195 + V_196 ;
}
if ( V_2 -> V_36 . V_478 != V_479 )
V_470 |= V_57 ;
}
if ( V_2 -> V_36 . V_37 == V_38 &&
( V_2 -> V_36 . V_12 & V_480 ) )
V_470 |= V_197 ;
if ( V_2 -> V_36 . V_481 != 0xff )
{
F_27 ( V_2 , V_482 , V_2 -> V_36 . V_481 ) ;
V_470 |= V_483 ;
}
F_27 ( V_2 , V_58 , V_470 ) ;
V_2 -> V_56 = V_470 ;
V_470 = 0x0500 ;
switch ( V_2 -> V_36 . V_484 ) {
case V_485 : V_470 |= V_57 ; break;
case V_486 : V_470 |= V_196 ; break;
case V_487 : V_470 |= V_196 + V_57 ; break;
case V_488 : V_470 |= V_195 ; break;
case V_489 : V_470 |= V_195 + V_57 ; break;
case V_490 : V_470 |= V_195 + V_196 ; break;
case V_491 : V_470 |= V_195 + V_196 + V_57 ; break;
}
if ( ( V_2 -> V_36 . V_492 & V_493 ) == V_494 )
V_470 |= V_161 ;
else if ( ( V_2 -> V_36 . V_492 & V_493 ) == V_495 )
V_470 |= ( V_197 | V_179 | V_161 ) ;
F_27 ( V_2 , V_496 , V_470 ) ;
F_27 ( V_2 , V_497 , V_498 ) ;
F_50 ( V_2 , V_499 ) ;
V_470 = F_25 ( V_2 , V_59 ) & 0xc0 ;
if ( V_2 -> V_351 == V_352 )
F_27 ( V_2 , V_59 , ( T_2 ) ( 0x030a | V_470 ) ) ;
else
F_27 ( V_2 , V_59 , ( T_2 ) ( 0x140a | V_470 ) ) ;
F_31 ( V_2 , V_142 ) ;
F_30 ( V_2 , V_67 ) ;
V_470 = 0x0400 ;
switch ( V_2 -> V_36 . V_484 ) {
case V_485 : V_470 |= V_57 ; break;
case V_486 : V_470 |= V_196 ; break;
case V_487 : V_470 |= V_196 + V_57 ; break;
case V_488 : V_470 |= V_195 ; break;
case V_489 : V_470 |= V_195 + V_57 ; break;
case V_490 : V_470 |= V_195 + V_196 ; break;
case V_491 : V_470 |= V_195 + V_196 + V_57 ; break;
}
if ( ( V_2 -> V_36 . V_492 & V_493 ) == V_494 )
V_470 |= V_161 + V_166 ;
else if ( ( V_2 -> V_36 . V_492 & V_493 ) == V_495 )
V_470 |= ( V_197 | V_179 | V_161 | V_166 ) ;
F_27 ( V_2 , V_372 , V_470 ) ;
F_125 ( V_2 ) ;
F_130 ( V_2 , V_500 ) ;
if ( V_2 -> V_351 == V_352 )
F_27 ( V_2 , V_363 , 0x0736 ) ;
else
F_27 ( V_2 , V_363 , 0x1436 ) ;
F_33 ( V_2 , V_501 ) ;
F_30 ( V_2 , V_69 ) ;
V_2 -> V_502 = 0 ;
if ( ! V_471 )
V_2 -> V_502 |= V_503 ;
F_27 ( V_2 , V_68 , V_2 -> V_502 ) ;
V_470 = 0x0f40 ;
if ( V_2 -> V_36 . V_12 & V_504 )
V_470 |= 0x0003 ;
else if ( V_2 -> V_36 . V_12 & V_505 )
V_470 |= 0x0004 ;
else if ( V_2 -> V_36 . V_12 & V_506 )
V_470 |= 0x0006 ;
else
V_470 |= 0x0007 ;
if ( V_2 -> V_36 . V_12 & V_507 )
V_470 |= 0x0018 ;
else if ( V_2 -> V_36 . V_12 & V_508 )
V_470 |= 0x0020 ;
else if ( V_2 -> V_36 . V_12 & V_509 )
V_470 |= 0x0038 ;
else
V_470 |= 0x0030 ;
F_27 ( V_2 , V_510 , V_470 ) ;
V_470 = 0x0000 ;
if ( V_2 -> V_36 . V_12 & ( V_504 + V_507 ) ) {
V_394 V_511 ;
V_394 V_512 ;
T_2 V_513 ;
if ( V_2 -> V_351 == V_352 )
V_511 = 11059200 ;
else
V_511 = 14745600 ;
if ( V_2 -> V_36 . V_12 & V_514 ) {
V_512 = 16 ;
V_470 |= V_179 ;
}
else if ( V_2 -> V_36 . V_12 & V_515 ) {
V_512 = 8 ;
V_470 |= V_516 ;
}
else
V_512 = 32 ;
if ( V_2 -> V_36 . V_517 )
{
V_513 = ( T_2 ) ( ( V_511 / V_512 ) / V_2 -> V_36 . V_517 ) ;
if ( ! ( ( ( ( V_511 / V_512 ) % V_2 -> V_36 . V_517 ) * 2 )
/ V_2 -> V_36 . V_517 ) )
V_513 -- ;
}
else
V_513 = - 1 ;
F_27 ( V_2 , V_518 , V_513 ) ;
V_470 |= V_483 ;
switch ( V_2 -> V_36 . V_484 ) {
case V_519 :
case V_485 :
case V_486 :
case V_487 : V_470 |= V_166 ; break;
case V_488 :
case V_489 : V_470 |= V_161 ; break;
case V_490 :
case V_491 : V_470 |= V_161 + V_166 ; break;
}
}
F_27 ( V_2 , V_520 , V_470 ) ;
F_27 ( V_2 , V_521 , 0x1020 ) ;
if ( V_2 -> V_36 . V_12 & V_522 ) {
F_27 ( V_2 , V_123 ,
( T_2 ) ( F_25 ( V_2 , V_123 ) | V_523 ) ) ;
}
F_236 ( V_2 ) ;
F_30 ( V_2 , V_67 + V_131 +
V_69 + V_127 + V_159 ) ;
F_27 ( V_2 , V_123 , ( T_2 ) ( F_25 ( V_2 , V_123 ) | V_134 ) ) ;
F_92 ( V_2 , V_159 ) ;
V_2 -> V_468 = 0 ;
F_51 ( 0 , V_2 -> V_136 ) ;
F_34 ( V_2 , V_524 ) ;
V_2 -> V_468 = V_166 ;
F_51 ( V_166 , V_2 -> V_136 ) ;
if ( V_2 -> V_351 == V_461 ) {
F_27 ( V_2 , V_194 , ( T_2 ) ( ( F_25 ( V_2 , V_194 ) | V_195 ) & ~ V_196 ) ) ;
}
if ( V_2 -> V_351 == V_352 ) {
F_63 ( V_2 , V_525 , 0xa00b ) ;
}
else
F_63 ( V_2 , V_525 , 0x800b ) ;
F_63 ( V_2 , V_163 , 0xf200 ) ;
F_63 ( V_2 , V_168 , 0xf200 ) ;
F_63 ( V_2 , V_526 , 0x9000 ) ;
F_64 ( V_2 , V_163 ) ;
F_64 ( V_2 , V_168 ) ;
F_63 ( V_2 , V_160 , 0x0303 ) ;
V_470 = 0x8080 ;
switch ( V_2 -> V_36 . V_527 ) {
case V_528 : V_470 |= V_179 ; break;
case V_529 : V_470 |= V_516 ; break;
case V_530 : V_470 |= V_516 + V_179 ; break;
}
switch ( V_2 -> V_36 . V_478 ) {
case V_531 : V_470 |= V_166 + V_197 ; break;
case V_532 : V_470 |= V_166 ; break;
case V_533 : V_470 |= V_161 ; break;
case V_534 : V_470 |= V_161 + V_166 ; break;
}
F_27 ( V_2 , V_535 , V_470 ) ;
if ( V_2 -> V_351 == V_352 ) {
F_63 ( V_2 , V_536 , 0x0000 ) ;
}
else
F_63 ( V_2 , V_536 , 0x2000 ) ;
F_10 ( V_2 ) ;
F_87 ( V_2 ) ;
}
static void F_237 ( struct V_1 * V_2 , int V_248 )
{
if ( V_248 ) {
F_27 ( V_2 , V_295 , F_25 ( V_2 , V_295 ) | ( V_296 + V_537 ) ) ;
F_27 ( V_2 , V_510 , 0x0f64 ) ;
if ( V_2 -> V_36 . V_517 ) {
if ( V_2 -> V_351 == V_352 )
F_27 ( V_2 , V_538 , ( T_2 ) ( ( 11059200 / V_2 -> V_36 . V_517 ) - 1 ) ) ;
else
F_27 ( V_2 , V_538 , ( T_2 ) ( ( 14745600 / V_2 -> V_36 . V_517 ) - 1 ) ) ;
} else
F_27 ( V_2 , V_538 , ( T_2 ) 8 ) ;
F_27 ( V_2 , V_520 , ( T_2 ) ( ( F_25 ( V_2 , V_520 ) & ~ V_162 ) | V_167 ) ) ;
F_27 ( V_2 , V_295 , ( T_2 ) ( ( F_25 ( V_2 , V_295 ) & 0xfff8 ) | 0x0004 ) ) ;
V_2 -> V_467 = 0x300 ;
F_51 ( 0x0300 , V_2 -> V_136 + V_137 ) ;
} else {
F_27 ( V_2 , V_295 , F_25 ( V_2 , V_295 ) & ~ ( V_296 + V_537 ) ) ;
V_2 -> V_467 = 0 ;
F_51 ( 0 , V_2 -> V_136 + V_137 ) ;
}
}
static void F_238 ( struct V_1 * V_2 , V_394 V_221 )
{
V_394 V_511 ;
T_2 V_513 ;
if ( V_221 ) {
if ( V_2 -> V_351 == V_352 )
V_511 = 11059200 ;
else
V_511 = 14745600 ;
V_513 = ( T_2 ) ( V_511 / V_221 ) ;
if ( ! ( ( ( V_511 % V_221 ) * 2 ) / V_221 ) )
V_513 -- ;
F_27 ( V_2 , V_538 , V_513 ) ;
F_27 ( V_2 , V_520 , ( T_2 ) ( ( F_25 ( V_2 , V_520 ) & ~ V_162 ) | V_167 ) ) ;
F_27 ( V_2 , V_295 , ( T_2 ) ( ( F_25 ( V_2 , V_295 ) & 0xfff8 ) | 0x0004 ) ) ;
} else {
F_27 ( V_2 , V_520 , ( T_2 ) ( F_25 ( V_2 , V_520 ) & ~ V_167 ) ) ;
}
}
static void F_29 ( struct V_1 * V_2 )
{
int V_539 ;
int V_540 ;
int V_541 ;
bool V_542 = false ;
bool V_543 = false ;
bool V_544 = false ;
V_395 * V_389 = V_2 -> V_386 ;
V_394 V_400 ;
F_34 ( V_2 , V_545 ) ;
F_50 ( V_2 , V_546 ) ;
F_35 ( V_2 , V_147 ) ;
V_541 = V_539 = V_540 = V_2 -> V_547 ;
while( ! V_389 [ V_540 ] . V_13 )
{
if ( ! V_542 )
{
V_542 = true ;
V_541 = V_540 ;
V_543 = false ;
}
if ( V_389 [ V_540 ] . V_49 )
{
V_542 = false ;
V_543 = true ;
}
V_540 ++ ;
if ( V_540 == V_2 -> V_384 )
V_540 = 0 ;
if ( V_539 == V_540 )
{
F_183 ( V_2 ) ;
V_541 = 0 ;
V_542 = false ;
V_544 = true ;
break;
}
}
if ( V_542 && ! V_543 )
{
V_539 = V_541 ;
do
{
* ( ( unsigned long * ) & ( V_2 -> V_386 [ V_539 ++ ] . V_13 ) ) = V_381 ;
if ( V_539 == V_2 -> V_384 )
V_539 = 0 ;
} while( V_539 != V_540 );
V_544 = true ;
}
if ( V_544 )
{
F_31 ( V_2 , V_142 ) ;
F_30 ( V_2 , V_131 | V_67 ) ;
F_31 ( V_2 , V_131 | V_67 ) ;
F_58 ( V_2 , V_157 ) ;
F_27 ( V_2 , V_521 , ( T_2 ) ( F_25 ( V_2 , V_521 ) | V_57 ) ) ;
V_400 = V_2 -> V_386 [ V_541 ] . V_396 ;
F_63 ( V_2 , V_548 , ( T_2 ) V_400 ) ;
F_63 ( V_2 , V_549 , ( T_2 ) ( V_400 >> 16 ) ) ;
F_31 ( V_2 , V_142 ) ;
F_30 ( V_2 , V_131 + V_67 ) ;
F_92 ( V_2 , V_67 ) ;
F_63 ( V_2 , V_550 , V_134 + V_169 ) ;
F_63 ( V_2 , V_526 , ( T_2 ) ( F_64 ( V_2 , V_526 ) | V_162 ) ) ;
F_34 ( V_2 , V_551 ) ;
if ( V_2 -> V_36 . V_12 & V_552 )
F_58 ( V_2 , V_553 ) ;
else
F_58 ( V_2 , V_554 ) ;
}
else
{
F_27 ( V_2 , V_521 , ( T_2 ) ( F_25 ( V_2 , V_521 ) | V_57 ) ) ;
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
F_30 ( V_2 , V_131 + V_67 ) ;
F_59 ( V_2 , V_131 + V_67 ) ;
F_58 ( V_2 , V_157 ) ;
F_27 ( V_2 , V_521 , ( T_2 ) ( F_25 ( V_2 , V_521 ) | V_57 ) ) ;
F_35 ( V_2 , V_147 ) ;
V_2 -> V_250 = false ;
V_2 -> V_164 = false ;
V_2 -> V_41 = false ;
}
static void F_21 ( struct V_1 * V_2 )
{
V_394 V_400 ;
if ( V_19 >= V_51 )
F_4 ( L_151 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_183 ( V_2 ) ;
F_87 ( V_2 ) ;
F_27 ( V_2 , V_521 , ( T_2 ) ( F_25 ( V_2 , V_521 ) | V_57 ) ) ;
F_35 ( V_2 , V_147 ) ;
if ( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_202 ) {
V_400 = V_2 -> V_386 [ 0 ] . V_396 ;
F_63 ( V_2 , V_548 , ( T_2 ) V_400 ) ;
F_63 ( V_2 , V_549 , ( T_2 ) ( V_400 >> 16 ) ) ;
F_31 ( V_2 , V_142 ) ;
F_30 ( V_2 , V_131 + V_67 ) ;
F_92 ( V_2 , V_67 ) ;
F_63 ( V_2 , V_550 , V_134 + V_169 ) ;
F_63 ( V_2 , V_526 , ( T_2 ) ( F_64 ( V_2 , V_526 ) | V_162 ) ) ;
F_34 ( V_2 , V_551 ) ;
if ( V_2 -> V_36 . V_12 & V_552 )
F_58 ( V_2 , V_553 ) ;
else
F_58 ( V_2 , V_554 ) ;
} else {
F_31 ( V_2 , V_142 ) ;
F_30 ( V_2 , V_131 + V_67 ) ;
F_92 ( V_2 , V_131 ) ;
F_35 ( V_2 , V_147 ) ;
F_50 ( V_2 , V_546 ) ;
F_58 ( V_2 , V_554 ) ;
}
F_27 ( V_2 , V_521 , 0x1020 ) ;
V_2 -> V_250 = true ;
}
static void F_13 ( struct V_1 * V_2 )
{
V_394 V_400 ;
unsigned int V_555 ;
if ( V_19 >= V_51 )
F_4 ( L_152 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( V_2 -> V_78 ) {
V_2 -> V_82 = false ;
if ( V_2 -> V_36 . V_12 & V_556 ) {
F_37 ( V_2 ) ;
if ( ! ( V_2 -> V_83 & V_84 ) ) {
V_2 -> V_83 |= V_84 ;
F_38 ( V_2 ) ;
V_2 -> V_82 = true ;
}
}
if ( V_2 -> V_36 . V_37 == V_229 ) {
if ( ! V_2 -> V_43 ) {
F_33 ( V_2 , V_501 ) ;
F_30 ( V_2 , V_69 + V_127 ) ;
F_92 ( V_2 , V_127 ) ;
F_48 ( V_2 ) ;
}
} else {
F_34 ( V_2 , V_72 ) ;
V_555 = V_2 -> V_387 [ V_2 -> V_557 ] . V_558 ;
if ( V_2 -> V_36 . V_37 == V_202 )
V_2 -> V_387 [ V_2 -> V_557 ] . V_558 = 0 ;
F_27 ( V_2 , V_559 , ( T_2 ) V_555 ) ;
F_35 ( V_2 , V_73 ) ;
V_400 = V_2 -> V_387 [ V_2 -> V_557 ] . V_396 ;
F_63 ( V_2 , V_560 , ( T_2 ) V_400 ) ;
F_63 ( V_2 , V_561 , ( T_2 ) ( V_400 >> 16 ) ) ;
F_33 ( V_2 , V_501 ) ;
F_30 ( V_2 , V_69 ) ;
F_92 ( V_2 , V_69 ) ;
if ( V_2 -> V_36 . V_37 == V_202 &&
V_2 -> V_383 > 1 ) {
F_63 ( V_2 , V_562 , V_169 | V_134 ) ;
F_63 ( V_2 , V_526 , ( T_2 ) ( F_64 ( V_2 , V_526 ) | V_167 ) ) ;
}
F_34 ( V_2 , V_563 ) ;
F_130 ( V_2 , V_564 ) ;
F_196 ( & V_2 -> V_81 , V_324 +
F_197 ( 5000 ) ) ;
}
V_2 -> V_43 = true ;
}
if ( ! V_2 -> V_23 ) {
V_2 -> V_23 = true ;
if ( V_2 -> V_36 . V_12 & V_522 )
F_239 ( V_2 , V_565 ) ;
else
F_239 ( V_2 , V_554 ) ;
}
}
static void F_10 ( struct V_1 * V_2 )
{
if ( V_19 >= V_51 )
F_4 ( L_153 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
F_36 ( & V_2 -> V_81 ) ;
F_33 ( V_2 , V_501 ) ;
F_30 ( V_2 , V_69 + V_127 ) ;
F_59 ( V_2 , V_69 + V_127 ) ;
F_239 ( V_2 , V_157 ) ;
F_34 ( V_2 , V_72 ) ;
F_35 ( V_2 , V_73 ) ;
V_2 -> V_23 = false ;
V_2 -> V_43 = false ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_129 ;
T_8 V_566 [ 2 ] ;
if ( ! V_2 -> V_78 && ! V_2 -> V_239 )
return;
F_130 ( V_2 , V_567 ) ;
while( ( V_129 = F_25 ( V_2 , V_363 ) >> 8 ) && V_2 -> V_78 ) {
if ( ( V_2 -> V_78 > 1 ) && ( V_129 > 1 ) && ! V_2 -> V_239 ) {
V_566 [ 0 ] = V_2 -> V_186 [ V_2 -> V_80 ++ ] ;
V_2 -> V_80 = V_2 -> V_80 & ( V_230 - 1 ) ;
V_566 [ 1 ] = V_2 -> V_186 [ V_2 -> V_80 ++ ] ;
V_2 -> V_80 = V_2 -> V_80 & ( V_230 - 1 ) ;
F_51 ( * ( ( T_2 * ) V_566 ) , V_2 -> V_136 + V_568 ) ;
V_2 -> V_78 -= 2 ;
V_2 -> V_54 . V_298 += 2 ;
} else {
F_51 ( ( F_52 ( V_2 -> V_136 + V_137 ) & 0x0780 ) | ( V_569 + V_133 ) ,
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
static void F_240 ( struct V_1 * V_2 )
{
if ( V_2 -> V_351 == V_352 ) {
int V_388 ;
V_394 V_570 ;
volatile V_394 * V_571 = ( V_394 * ) ( V_2 -> V_425 + 0x50 ) ;
V_394 * V_572 = ( V_394 * ) ( V_2 -> V_425 + 0x28 ) ;
V_2 -> V_573 |= V_574 ;
* V_571 = V_2 -> V_573 ;
for( V_388 = 0 ; V_388 < 10 ; V_388 ++ )
V_570 = * V_571 ;
V_2 -> V_573 &= ~ V_574 ;
* V_571 = V_2 -> V_573 ;
* V_572 = F_241 (
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
F_242 ( 0 , V_2 -> V_136 + 8 ) ;
}
V_2 -> V_468 = 0 ;
V_2 -> V_467 = 0 ;
V_2 -> V_575 = 0 ;
F_51 ( 0x000c , V_2 -> V_136 + V_576 ) ;
F_51 ( 0 , V_2 -> V_136 ) ;
F_51 ( 0 , V_2 -> V_136 + V_137 ) ;
F_35 ( V_2 , V_577 ) ;
F_27 ( V_2 , V_194 , 0xf0f5 ) ;
F_27 ( V_2 , V_295 , 0x0004 ) ;
}
static void F_90 ( struct V_1 * V_2 )
{
T_2 V_470 ;
F_70 ( V_2 ) ;
F_51 ( 0 , V_2 -> V_136 ) ;
F_34 ( V_2 , V_524 ) ;
F_243 ( V_2 ) ;
V_470 = 0 ;
if ( V_2 -> V_36 . V_214 != 1 )
V_470 |= V_196 ;
F_27 ( V_2 , V_58 , V_470 ) ;
V_470 = 0 ;
if ( V_2 -> V_36 . V_209 != 8 )
V_470 |= V_483 + V_134 + V_169 ;
if ( V_2 -> V_36 . V_145 != V_215 ) {
V_470 |= V_578 ;
if ( V_2 -> V_36 . V_145 != V_218 )
V_470 |= V_537 ;
}
F_27 ( V_2 , V_496 , V_470 ) ;
F_50 ( V_2 , V_579 ) ;
F_27 ( V_2 , V_59 , 0x0000 ) ;
F_31 ( V_2 , V_142 ) ;
F_30 ( V_2 , V_67 ) ;
V_470 = 0 ;
if ( V_2 -> V_36 . V_209 != 8 )
V_470 |= V_483 + V_134 + V_169 ;
if ( V_2 -> V_36 . V_145 != V_215 ) {
V_470 |= V_578 ;
if ( V_2 -> V_36 . V_145 != V_218 )
V_470 |= V_537 ;
}
F_27 ( V_2 , V_372 , V_470 ) ;
F_125 ( V_2 ) ;
F_130 ( V_2 , V_580 ) ;
F_27 ( V_2 , V_363 , 0x1f40 ) ;
F_33 ( V_2 , V_501 ) ;
F_30 ( V_2 , V_69 ) ;
F_244 ( V_2 , V_2 -> V_36 . V_221 ) ;
F_27 ( V_2 , V_521 , 0x0020 ) ;
F_59 ( V_2 , V_69 + V_127 +
V_131 + V_67 ) ;
F_30 ( V_2 , V_69 + V_127 +
V_131 + V_67 ) ;
F_236 ( V_2 ) ;
if ( V_2 -> V_351 == V_461 ) {
F_27 ( V_2 , V_194 , ( T_2 ) ( ( F_25 ( V_2 , V_194 ) | V_57 ) & ~ V_197 ) ) ;
}
if ( V_2 -> V_36 . V_581 ) {
V_2 -> V_467 = 0x300 ;
F_51 ( 0x0300 , V_2 -> V_136 + V_137 ) ;
}
}
static void F_243 ( struct V_1 * V_2 )
{
int V_388 ;
unsigned long V_582 = V_2 -> V_36 . V_37 ;
V_2 -> V_36 . V_37 = V_38 ;
F_70 ( V_2 ) ;
F_235 ( V_2 ) ;
F_237 ( V_2 , 1 ) ;
F_27 ( V_2 , V_538 , 0 ) ;
F_27 ( V_2 , V_535 , 0x0100 ) ;
F_35 ( V_2 , V_147 ) ;
F_58 ( V_2 , V_554 ) ;
F_27 ( V_2 , V_559 , 2 ) ;
F_35 ( V_2 , V_73 ) ;
F_33 ( V_2 , V_501 ) ;
F_51 ( 0 , V_2 -> V_136 + V_568 ) ;
F_130 ( V_2 , V_564 ) ;
F_239 ( V_2 , V_554 ) ;
for ( V_388 = 0 ; V_388 < 1000 ; V_388 ++ )
if ( F_25 ( V_2 , V_50 ) & ( V_166 + V_483 + V_134 + V_162 ) )
break;
F_237 ( V_2 , 0 ) ;
F_236 ( V_2 ) ;
V_2 -> V_36 . V_37 = V_582 ;
}
static void F_89 ( struct V_1 * V_2 )
{
F_243 ( V_2 ) ;
F_235 ( V_2 ) ;
if ( V_2 -> V_351 == V_461 ) {
F_27 ( V_2 , V_194 , ( T_2 ) ( ( F_25 ( V_2 , V_194 ) | V_57 ) & ~ V_197 ) ) ;
}
F_238 ( V_2 , V_2 -> V_36 . V_517 ) ;
if ( V_2 -> V_36 . V_581 )
F_237 ( V_2 , 1 ) ;
}
static void F_125 ( struct V_1 * V_2 )
{
T_2 V_575 = V_583 ;
switch( V_2 -> V_247 ) {
case V_440 : V_575 = V_583 ; break;
case V_584 : V_575 = V_585 ; break;
case V_586 : V_575 = V_587 ; break;
case V_588 : V_575 = V_589 ; break;
case V_590 : V_575 = V_591 ; break;
case V_592 : V_575 = V_593 ; break;
case V_594 : V_575 = V_595 ; break;
}
V_2 -> V_575 = V_575 ;
V_2 -> V_502 &= ~ V_596 ;
V_2 -> V_502 += V_575 ;
F_27 ( V_2 , V_68 , V_2 -> V_502 ) ;
if ( V_2 -> V_36 . V_37 == V_202 ) {
unsigned char V_597 = 0 ;
switch( V_2 -> V_247 ) {
case V_440 :
V_597 = 0x7e ;
break;
case V_584 :
V_597 = 0x55 ;
break;
case V_586 :
case V_592 :
V_597 = 0x00 ;
break;
case V_588 :
case V_594 :
V_597 = 0xff ;
break;
case V_590 :
V_597 = 0xaa ;
break;
}
F_245 ( V_2 , V_597 , V_597 ) ;
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
T_2 V_598 ;
unsigned char V_599 = V_2 -> V_83 ;
V_598 = F_25 ( V_2 , V_194 ) ;
if ( V_599 & V_84 )
V_598 &= ~ ( V_537 ) ;
else
V_598 |= V_537 ;
if ( V_599 & V_201 )
V_598 &= ~ ( V_483 ) ;
else
V_598 |= V_483 ;
F_27 ( V_2 , V_194 , V_598 ) ;
}
static void F_244 ( struct V_1 * V_2 , V_394 V_221 )
{
if ( V_221 ) {
F_27 ( V_2 , V_510 , 0x0f64 ) ;
if ( V_2 -> V_351 == V_352 )
F_27 ( V_2 , V_538 , ( T_2 ) ( ( 691200 / V_221 ) - 1 ) ) ;
else
F_27 ( V_2 , V_538 , ( T_2 ) ( ( 921600 / V_221 ) - 1 ) ) ;
F_27 ( V_2 , V_520 ,
( T_2 ) ( ( F_25 ( V_2 , V_520 ) & ~ V_162 ) | V_167 ) ) ;
F_27 ( V_2 , V_295 ,
( T_2 ) ( ( F_25 ( V_2 , V_295 ) & 0xfff8 ) | 0x0004 ) ) ;
} else {
F_27 ( V_2 , V_520 , ( T_2 ) ( F_25 ( V_2 , V_520 ) & ~ V_167 ) ) ;
}
}
static void F_184 ( struct V_1 * V_2 )
{
unsigned int V_388 ;
for ( V_388 = 0 ; V_388 < V_2 -> V_382 ; V_388 ++ ) {
* ( ( unsigned long * ) & ( V_2 -> V_387 [ V_388 ] . V_13 ) ) = 0 ;
}
V_2 -> V_600 = 0 ;
V_2 -> V_557 = 0 ;
V_2 -> V_170 = 0 ;
V_2 -> V_408 = 0 ;
V_2 -> V_409 = 0 ;
V_2 -> V_234 = 0 ;
}
static int F_195 ( struct V_1 * V_2 )
{
return V_2 -> V_382 - V_2 -> V_170 ;
}
static void F_183 ( struct V_1 * V_2 )
{
unsigned int V_388 ;
for ( V_388 = 0 ; V_388 < V_2 -> V_384 ; V_388 ++ ) {
* ( ( unsigned long * ) & ( V_2 -> V_386 [ V_388 ] . V_13 ) ) = V_381 ;
}
V_2 -> V_547 = 0 ;
}
static void F_246 ( struct V_1 * V_2 , unsigned int V_601 , unsigned int V_602 )
{
bool V_603 = false ;
V_395 * V_604 ;
unsigned int V_605 ;
V_605 = V_601 ;
while( ! V_603 ) {
V_604 = & ( V_2 -> V_386 [ V_605 ] ) ;
if ( V_605 == V_602 ) {
V_603 = true ;
}
* ( ( unsigned long * ) & ( V_604 -> V_13 ) ) = V_381 ;
V_605 ++ ;
if ( V_605 == V_2 -> V_384 )
V_605 = 0 ;
}
V_2 -> V_547 = V_605 ;
}
static bool V_39 ( struct V_1 * V_2 )
{
unsigned int V_601 , V_602 ;
unsigned short V_49 ;
V_395 * V_604 ;
unsigned int V_606 = 0 ;
bool V_607 = false ;
unsigned long V_12 ;
struct V_9 * V_10 = V_2 -> V_42 . V_10 ;
bool V_608 = false ;
V_601 = V_602 = V_2 -> V_547 ;
while( ! V_2 -> V_386 [ V_602 ] . V_49 ) {
if ( V_2 -> V_386 [ V_602 ] . V_13 )
goto V_609;
V_602 ++ ;
if ( V_602 == V_2 -> V_384 )
V_602 = 0 ;
if ( V_602 == V_601 ) {
if ( V_2 -> V_250 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
goto V_609;
}
}
V_49 = V_2 -> V_386 [ V_602 ] . V_49 ;
if ( V_49 & ( V_610 + V_65 +
V_611 + V_612 ) ) {
if ( V_49 & V_610 )
V_2 -> V_54 . V_357 ++ ;
else if ( V_49 & V_612 )
V_2 -> V_54 . V_55 ++ ;
else if ( V_49 & V_65 )
V_2 -> V_54 . V_66 ++ ;
else {
V_2 -> V_54 . V_359 ++ ;
if ( V_2 -> V_36 . V_492 & V_613 )
V_608 = true ;
}
V_606 = 0 ;
#if V_85
{
V_2 -> V_113 -> V_614 . V_615 ++ ;
V_2 -> V_113 -> V_614 . V_616 ++ ;
}
#endif
} else
V_608 = true ;
if ( V_608 ) {
V_606 = V_498 - V_2 -> V_386 [ V_602 ] . V_558 ;
if ( V_2 -> V_36 . V_492 == V_494 )
V_606 -= 2 ;
else if ( V_2 -> V_36 . V_492 == V_495 )
V_606 -= 4 ;
}
if ( V_19 >= V_35 )
F_4 ( L_154 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_49 , V_606 ) ;
if ( V_19 >= V_617 )
F_247 ( V_2 , V_2 -> V_386 [ V_601 ] . V_401 ,
F_105 ( int , V_606 , V_381 ) , 0 ) ;
if ( V_606 ) {
if ( ( ( V_2 -> V_36 . V_492 & V_613 ) &&
( ( V_606 + 1 ) > V_2 -> V_238 ) ) ||
( V_606 > V_2 -> V_238 ) )
V_2 -> V_54 . V_358 ++ ;
else {
int V_618 = V_606 ;
int V_339 = V_601 ;
unsigned char * V_619 = V_2 -> V_403 ;
if ( ! ( V_49 & V_611 ) )
V_2 -> V_54 . V_356 ++ ;
while( V_618 ) {
int V_620 ;
if ( V_618 > V_381 )
V_620 = V_381 ;
else
V_620 = V_618 ;
V_604 = & ( V_2 -> V_386 [ V_339 ] ) ;
memcpy ( V_619 , V_604 -> V_401 , V_620 ) ;
V_619 += V_620 ;
V_618 -= V_620 ;
if ( ++ V_339 == V_2 -> V_384 )
V_339 = 0 ;
}
if ( V_2 -> V_36 . V_492 & V_613 ) {
++ V_606 ;
* V_619 = ( V_49 & V_611 ?
V_621 :
V_622 ) ;
if ( V_19 >= V_617 )
F_4 ( L_155 ,
__FILE__ , __LINE__ , V_2 -> V_21 ,
* V_619 ) ;
}
#if V_85
if ( V_2 -> V_86 )
F_248 ( V_2 , V_2 -> V_403 , V_606 ) ;
else
#endif
F_5 ( V_10 , V_2 -> V_403 , V_2 -> V_405 , V_606 ) ;
}
}
F_246 ( V_2 , V_601 , V_602 ) ;
V_607 = true ;
V_609:
if ( V_2 -> V_250 && V_2 -> V_164 ) {
if ( ! V_2 -> V_386 [ V_602 ] . V_49 &&
V_2 -> V_386 [ V_602 ] . V_13 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
return V_607 ;
}
static bool V_40 ( struct V_1 * V_2 )
{
unsigned int V_623 , V_624 ;
unsigned short V_49 ;
V_395 * V_604 ;
unsigned int V_606 = 0 ;
bool V_607 = false ;
unsigned long V_12 ;
struct V_9 * V_10 = V_2 -> V_42 . V_10 ;
V_623 = V_624 = V_2 -> V_547 ;
++ V_624 ;
if ( V_624 == V_2 -> V_384 )
V_624 = 0 ;
if ( V_2 -> V_386 [ V_623 ] . V_49 != 0 ||
( V_2 -> V_386 [ V_623 ] . V_13 == 0 &&
V_2 -> V_386 [ V_624 ] . V_13 == 0 ) ) {
V_49 = V_2 -> V_386 [ V_623 ] . V_49 ;
if ( V_49 & ( V_610 + V_65 +
V_611 + V_612 ) ) {
if ( V_49 & V_610 )
V_2 -> V_54 . V_357 ++ ;
else if ( V_49 & V_612 )
V_2 -> V_54 . V_55 ++ ;
else if ( V_49 & V_65 )
V_2 -> V_54 . V_66 ++ ;
else
V_2 -> V_54 . V_359 ++ ;
V_606 = 0 ;
} else {
if ( V_49 ) {
if ( V_2 -> V_386 [ V_623 ] . V_558 )
V_606 = V_498 - V_2 -> V_386 [ V_623 ] . V_558 ;
else
V_606 = V_381 ;
}
else
V_606 = V_381 ;
}
if ( V_606 > V_381 ) {
V_606 = V_606 % V_381 ;
}
if ( V_19 >= V_35 )
F_4 ( L_156 ,
__FILE__ , __LINE__ , V_2 -> V_21 , V_49 , V_606 ) ;
if ( V_19 >= V_617 )
F_247 ( V_2 , V_2 -> V_386 [ V_623 ] . V_401 ,
F_105 ( int , V_606 , V_381 ) , 0 ) ;
if ( V_606 ) {
V_604 = & ( V_2 -> V_386 [ V_623 ] ) ;
memcpy ( V_2 -> V_403 , V_604 -> V_401 , V_606 ) ;
V_2 -> V_54 . V_356 ++ ;
F_5 ( V_10 , V_2 -> V_403 , V_2 -> V_405 , V_606 ) ;
}
F_246 ( V_2 , V_623 , V_623 ) ;
V_607 = true ;
}
if ( V_2 -> V_250 && V_2 -> V_164 ) {
if ( ! V_2 -> V_386 [ V_623 ] . V_49 &&
V_2 -> V_386 [ V_623 ] . V_13 ) {
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_21 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
return V_607 ;
}
static void F_102 ( struct V_1 * V_2 ,
const char * V_415 , unsigned int V_416 )
{
unsigned short V_625 ;
unsigned int V_388 = 0 ;
V_395 * V_604 ;
if ( V_19 >= V_617 )
F_247 ( V_2 , V_415 , F_105 ( int , V_416 , V_381 ) , 1 ) ;
if ( V_2 -> V_36 . V_12 & V_236 ) {
V_2 -> V_56 |= V_57 ;
}
V_388 = V_2 -> V_600 ;
V_2 -> V_557 = V_388 ;
V_2 -> V_387 [ V_388 ] . V_49 = V_2 -> V_56 & 0xf000 ;
V_2 -> V_387 [ V_388 ] . V_558 = V_416 ;
V_2 -> V_387 [ V_388 ] . V_13 = V_416 ;
while( V_416 ) {
V_604 = & V_2 -> V_387 [ V_388 ++ ] ;
if ( V_388 == V_2 -> V_382 )
V_388 = 0 ;
if ( V_416 > V_381 )
V_625 = V_381 ;
else
V_625 = V_416 ;
if ( V_2 -> V_351 == V_352 )
F_249 ( V_604 -> V_401 , V_415 , V_625 ) ;
else
memcpy ( V_604 -> V_401 , V_415 , V_625 ) ;
V_604 -> V_13 = V_625 ;
V_415 += V_625 ;
V_416 -= V_625 ;
++ V_2 -> V_170 ;
}
V_2 -> V_600 = V_388 ;
}
static bool F_250 ( struct V_1 * V_2 )
{
static unsigned short V_626 [] =
{ 0x0000 , 0xffff , 0xaaaa , 0x5555 , 0x1234 , 0x6969 , 0x9696 , 0x0f0f } ;
static unsigned int V_627 = F_251 ( V_626 ) ;
unsigned int V_388 ;
bool V_24 = true ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_240 ( V_2 ) ;
if ( ( F_25 ( V_2 , V_123 ) != 0 ) ||
( F_25 ( V_2 , V_177 ) != 0 ) ||
( F_64 ( V_2 , V_178 ) != 0 ) ) {
V_24 = false ;
}
if ( V_24 ) {
for ( V_388 = 0 ; V_388 < V_627 ; V_388 ++ ) {
F_27 ( V_2 , V_538 , V_626 [ V_388 ] ) ;
F_27 ( V_2 , V_518 , V_626 [ ( V_388 + 1 ) % V_627 ] ) ;
F_27 ( V_2 , V_559 , V_626 [ ( V_388 + 2 ) % V_627 ] ) ;
F_27 ( V_2 , V_497 , V_626 [ ( V_388 + 3 ) % V_627 ] ) ;
F_27 ( V_2 , V_482 , V_626 [ ( V_388 + 4 ) % V_627 ] ) ;
F_63 ( V_2 , V_628 , V_626 [ ( V_388 + 5 ) % V_627 ] ) ;
if ( ( F_25 ( V_2 , V_538 ) != V_626 [ V_388 ] ) ||
( F_25 ( V_2 , V_518 ) != V_626 [ ( V_388 + 1 ) % V_627 ] ) ||
( F_25 ( V_2 , V_559 ) != V_626 [ ( V_388 + 2 ) % V_627 ] ) ||
( F_25 ( V_2 , V_497 ) != V_626 [ ( V_388 + 3 ) % V_627 ] ) ||
( F_25 ( V_2 , V_482 ) != V_626 [ ( V_388 + 4 ) % V_627 ] ) ||
( F_64 ( V_2 , V_628 ) != V_626 [ ( V_388 + 5 ) % V_627 ] ) ) {
V_24 = false ;
break;
}
}
}
F_240 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_24 ;
}
static bool F_252 ( struct V_1 * V_2 )
{
unsigned long V_629 ;
unsigned long V_12 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_240 ( V_2 ) ;
V_2 -> V_126 = false ;
F_27 ( V_2 , V_194 , ( unsigned short ) ( ( F_25 ( V_2 , V_194 ) | V_57 ) & ~ V_197 ) ) ;
F_236 ( V_2 ) ;
F_92 ( V_2 , V_91 ) ;
F_30 ( V_2 , V_91 ) ;
F_41 ( V_2 , V_122 ) ;
F_91 ( V_2 , V_124 + V_125 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_629 = 100 ;
while( V_629 -- && ! V_2 -> V_126 ) {
F_156 ( 10 ) ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_240 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_2 -> V_126 ;
}
static bool F_253 ( struct V_1 * V_2 )
{
unsigned short V_630 ;
unsigned long V_400 ;
unsigned int V_555 ;
unsigned int V_388 ;
char * V_631 ;
bool V_24 = true ;
unsigned short V_49 = 0 ;
unsigned long V_629 ;
unsigned long V_12 ;
T_5 V_246 ;
memcpy ( & V_246 , & V_2 -> V_36 , sizeof( T_5 ) ) ;
memcpy ( & V_2 -> V_36 , & V_439 , sizeof( T_5 ) ) ;
#define F_254 40
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_240 ( V_2 ) ;
F_235 ( V_2 ) ;
F_237 ( V_2 , 1 ) ;
F_63 ( V_2 , V_163 , 0xe200 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_555 = F_254 ;
V_2 -> V_387 [ 0 ] . V_13 = V_555 ;
V_2 -> V_387 [ 0 ] . V_558 = V_555 ;
V_2 -> V_387 [ 0 ] . V_49 = 0x4000 ;
V_631 = V_2 -> V_387 [ 0 ] . V_401 ;
for ( V_388 = 0 ; V_388 < V_555 ; V_388 ++ )
* V_631 ++ = V_388 ;
V_2 -> V_386 [ 0 ] . V_49 = 0 ;
V_2 -> V_386 [ 0 ] . V_13 = V_555 + 4 ;
memset ( V_2 -> V_386 [ 0 ] . V_401 , 0 , V_555 + 4 ) ;
V_2 -> V_387 [ 1 ] . V_13 = 0 ;
V_2 -> V_386 [ 1 ] . V_13 = 0 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_35 ( V_2 , V_147 ) ;
V_400 = V_2 -> V_386 [ 0 ] . V_396 ;
F_63 ( V_2 , V_548 , ( unsigned short ) V_400 ) ;
F_63 ( V_2 , V_549 , ( unsigned short ) ( V_400 >> 16 ) ) ;
F_64 ( V_2 , V_163 ) ;
F_34 ( V_2 , V_551 ) ;
F_27 ( V_2 , V_496 , ( unsigned short ) ( ( F_25 ( V_2 , V_496 ) & 0xfffc ) | 0x0002 ) ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_629 = V_324 + F_197 ( 100 ) ;
for(; ; ) {
if ( F_158 ( V_324 , V_629 ) ) {
V_24 = false ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_49 = F_64 ( V_2 , V_163 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( ! ( V_49 & V_483 ) && ( V_49 & V_578 ) ) {
break;
}
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_27 ( V_2 , V_559 , ( unsigned short ) V_2 -> V_387 [ 0 ] . V_13 ) ;
F_35 ( V_2 , V_73 ) ;
V_400 = V_2 -> V_387 [ 0 ] . V_396 ;
F_63 ( V_2 , V_560 , ( unsigned short ) V_400 ) ;
F_63 ( V_2 , V_561 , ( unsigned short ) ( V_400 >> 16 ) ) ;
F_27 ( V_2 , V_68 , ( unsigned short ) ( ( F_25 ( V_2 , V_68 ) & 0x0f00 ) | 0xfa ) ) ;
F_34 ( V_2 , V_563 ) ;
F_130 ( V_2 , V_567 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_629 = V_324 + F_197 ( 100 ) ;
for(; ; ) {
if ( F_158 ( V_324 , V_629 ) ) {
V_24 = false ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_630 = F_25 ( V_2 , V_363 ) >> 8 ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( V_630 < 16 )
break;
else
if ( V_555 < 32 ) {
if ( V_630 <= ( 32 - V_555 ) )
break;
}
}
if ( V_24 )
{
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_130 ( V_2 , V_564 ) ;
F_27 ( V_2 , V_372 , ( unsigned short ) ( ( F_25 ( V_2 , V_372 ) & 0xfffc ) | 0x0002 ) ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
V_629 = V_324 + F_197 ( 100 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_49 = F_25 ( V_2 , V_68 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
while ( ! ( V_49 & ( V_537 + V_578 + V_483 + V_169 + V_162 ) ) ) {
if ( F_158 ( V_324 , V_629 ) ) {
V_24 = false ;
break;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_49 = F_25 ( V_2 , V_68 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
}
}
if ( V_24 ) {
if ( V_49 & ( V_578 + V_162 ) )
V_24 = false ;
}
if ( V_24 ) {
V_629 = V_324 + F_197 ( 100 ) ;
V_49 = V_2 -> V_386 [ 0 ] . V_49 ;
while ( V_49 == 0 ) {
if ( F_158 ( V_324 , V_629 ) ) {
V_24 = false ;
break;
}
V_49 = V_2 -> V_386 [ 0 ] . V_49 ;
}
}
if ( V_24 ) {
V_49 = V_2 -> V_386 [ 0 ] . V_49 ;
if ( V_49 & ( V_166 + V_134 + V_162 ) ) {
V_24 = false ;
} else {
if ( memcmp ( V_2 -> V_387 [ 0 ] . V_401 ,
V_2 -> V_386 [ 0 ] . V_401 , V_555 ) ) {
V_24 = false ;
}
}
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_240 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
memcpy ( & V_2 -> V_36 , & V_246 , sizeof( T_5 ) ) ;
return V_24 ;
}
static int F_78 ( struct V_1 * V_2 )
{
if ( V_19 >= V_20 )
F_4 ( L_157 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if ( ! F_250 ( V_2 ) ) {
V_2 -> V_632 = V_633 ;
F_4 ( L_158 ,
__FILE__ , __LINE__ , V_2 -> V_21 , ( unsigned short ) ( V_2 -> V_136 ) ) ;
return - V_300 ;
}
if ( ! F_252 ( V_2 ) ) {
V_2 -> V_632 = V_634 ;
F_4 ( L_159 ,
__FILE__ , __LINE__ , V_2 -> V_21 , ( unsigned short ) ( V_2 -> V_176 ) ) ;
return - V_300 ;
}
if ( ! F_253 ( V_2 ) ) {
V_2 -> V_632 = V_635 ;
F_4 ( L_160 ,
__FILE__ , __LINE__ , V_2 -> V_21 , ( unsigned short ) ( V_2 -> V_355 ) ) ;
return - V_300 ;
}
if ( V_19 >= V_20 )
F_4 ( L_161 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
return 0 ;
}
static bool F_202 ( struct V_1 * V_2 )
{
static unsigned long V_626 [] =
{ 0x0 , 0x55555555 , 0xaaaaaaaa , 0x66666666 , 0x99999999 , 0xffffffff , 0x12345678 } ;
unsigned long V_627 = F_251 ( V_626 ) ;
unsigned long V_388 ;
unsigned long V_636 = V_637 /sizeof( unsigned long ) ;
unsigned long * V_638 ;
if ( V_2 -> V_351 != V_352 )
return true ;
V_638 = ( unsigned long * ) V_2 -> V_390 ;
for ( V_388 = 0 ; V_388 < V_627 ; V_388 ++ ) {
* V_638 = V_626 [ V_388 ] ;
if ( * V_638 != V_626 [ V_388 ] )
return false ;
}
for ( V_388 = 0 ; V_388 < V_636 ; V_388 ++ ) {
* V_638 = V_388 * 4 ;
V_638 ++ ;
}
V_638 = ( unsigned long * ) V_2 -> V_390 ;
for ( V_388 = 0 ; V_388 < V_636 ; V_388 ++ ) {
if ( * V_638 != V_388 * 4 )
return false ;
V_638 ++ ;
}
memset ( V_2 -> V_390 , 0 , V_637 ) ;
return true ;
}
static void F_249 ( char * V_639 , const char * V_640 ,
unsigned short V_13 )
{
#define F_255 64
unsigned short V_641 = V_13 / F_255 ;
unsigned short V_605 ;
unsigned long V_642 ;
for ( V_605 = 0 ; V_605 < V_641 ; V_605 ++ )
{
memcpy ( V_639 , V_640 , F_255 ) ;
V_642 = * ( ( volatile unsigned long * ) V_639 ) ;
V_639 += F_255 ;
V_640 += F_255 ;
}
memcpy ( V_639 , V_640 , V_13 % F_255 ) ;
}
static void F_247 ( struct V_1 * V_2 , const char * V_11 , int V_13 , int V_643 )
{
int V_388 ;
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
for( V_388 = 0 ; V_388 < V_644 ; V_388 ++ )
F_4 ( L_164 , ( unsigned char ) V_11 [ V_388 ] ) ;
for(; V_388 < 17 ; V_388 ++ )
F_4 ( L_165 ) ;
for( V_388 = 0 ; V_388 < V_644 ; V_388 ++ ) {
if ( V_11 [ V_388 ] >= 040 && V_11 [ V_388 ] <= 0176 )
F_4 ( L_166 , V_11 [ V_388 ] ) ;
else
F_4 ( L_167 ) ;
}
F_4 ( L_168 ) ;
V_11 += V_644 ;
V_13 -= V_644 ;
}
}
static void V_189 ( unsigned long V_645 )
{
struct V_1 * V_2 = (struct V_1 * ) V_645 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_169 ,
__FILE__ , __LINE__ , V_2 -> V_21 ) ;
if( V_2 -> V_43 &&
( V_2 -> V_36 . V_37 == V_38 ||
V_2 -> V_36 . V_37 == V_202 ) ) {
V_2 -> V_54 . V_646 ++ ;
}
F_9 ( & V_2 -> V_22 , V_12 ) ;
V_2 -> V_43 = false ;
V_2 -> V_78 = V_2 -> V_79 = V_2 -> V_80 = 0 ;
if ( V_2 -> V_36 . V_12 & V_236 )
F_129 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
#if V_85
if ( V_2 -> V_86 )
F_39 ( V_2 ) ;
else
#endif
F_18 ( V_2 ) ;
}
static int F_148 ( struct V_1 * V_2 )
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
static void F_129 ( struct V_1 * V_2 )
{
F_35 ( V_2 , V_73 ) ;
F_34 ( V_2 , V_72 ) ;
F_23 ( V_2 ) ;
}
static void F_127 ( struct V_1 * V_2 )
{
V_2 -> V_53 = true ;
F_27 ( V_2 , V_59 ,
( F_25 ( V_2 , V_59 ) | V_52 ) ) ;
V_2 -> V_56 |= V_57 ;
F_27 ( V_2 , V_58 , V_2 -> V_56 ) ;
}
static int F_26 ( struct V_1 * V_2 )
{
return F_25 ( V_2 , V_521 ) & V_296 ? 1 : 0 ;
}
static int F_256 ( struct V_647 * V_648 , unsigned short V_484 ,
unsigned short V_145 )
{
struct V_1 * V_2 = F_257 ( V_648 ) ;
unsigned char V_649 ;
unsigned short V_650 ;
if ( V_2 -> V_42 . V_13 )
return - V_347 ;
switch ( V_484 )
{
case V_651 : V_649 = V_519 ; break;
case V_652 : V_649 = V_487 ; break;
case V_653 : V_649 = V_488 ; break;
case V_654 : V_649 = V_489 ; break;
case V_655 : V_649 = V_490 ; break;
default: return - V_294 ;
}
switch ( V_145 )
{
case V_656 : V_650 = V_657 ; break;
case V_658 : V_650 = V_494 ; break;
case V_659 : V_650 = V_495 ; break;
default: return - V_294 ;
}
V_2 -> V_36 . V_484 = V_649 ;
V_2 -> V_36 . V_492 = V_650 ;
if ( V_2 -> V_86 )
F_88 ( V_2 ) ;
return 0 ;
}
static T_9 F_258 ( struct V_660 * V_661 ,
struct V_647 * V_648 )
{
struct V_1 * V_2 = F_257 ( V_648 ) ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( V_662 L_170 , __FILE__ , V_648 -> V_3 ) ;
F_259 ( V_648 ) ;
V_2 -> V_78 = V_661 -> V_663 ;
F_102 ( V_2 , V_661 -> V_11 , V_661 -> V_663 ) ;
V_648 -> V_614 . V_664 ++ ;
V_648 -> V_614 . V_665 += V_661 -> V_663 ;
F_260 ( V_661 ) ;
V_648 -> V_666 = V_324 ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
if ( ! V_2 -> V_43 )
F_13 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
return V_667 ;
}
static int F_261 ( struct V_647 * V_648 )
{
struct V_1 * V_2 = F_257 ( V_648 ) ;
int V_24 ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_171 , __FILE__ , V_648 -> V_3 ) ;
if ( ( V_24 = F_262 ( V_648 ) ) )
return V_24 ;
F_9 ( & V_2 -> V_346 , V_12 ) ;
if ( V_2 -> V_42 . V_13 != 0 || V_2 -> V_86 != 0 ) {
F_4 ( V_668 L_172 , V_648 -> V_3 ) ;
F_11 ( & V_2 -> V_346 , V_12 ) ;
return - V_347 ;
}
V_2 -> V_86 = 1 ;
F_11 ( & V_2 -> V_346 , V_12 ) ;
if ( ( V_24 = F_74 ( V_2 ) ) != 0 ) {
F_9 ( & V_2 -> V_346 , V_12 ) ;
V_2 -> V_86 = 0 ;
F_11 ( & V_2 -> V_346 , V_12 ) ;
return V_24 ;
}
V_2 -> V_83 |= V_84 | V_201 ;
F_88 ( V_2 ) ;
V_648 -> V_666 = V_324 ;
F_263 ( V_648 ) ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_37 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
if ( V_2 -> V_83 & V_265 )
F_43 ( V_648 ) ;
else
F_44 ( V_648 ) ;
return 0 ;
}
static int F_264 ( struct V_647 * V_648 )
{
struct V_1 * V_2 = F_257 ( V_648 ) ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_173 , __FILE__ , V_648 -> V_3 ) ;
F_259 ( V_648 ) ;
F_84 ( V_2 ) ;
F_265 ( V_648 ) ;
F_9 ( & V_2 -> V_346 , V_12 ) ;
V_2 -> V_86 = 0 ;
F_11 ( & V_2 -> V_346 , V_12 ) ;
return 0 ;
}
static int F_266 ( struct V_647 * V_648 , struct V_669 * V_670 , int V_299 )
{
const T_10 V_671 = sizeof( V_672 ) ;
V_672 V_673 ;
V_672 T_4 * line = V_670 -> V_674 . V_675 . V_676 ;
struct V_1 * V_2 = F_257 ( V_648 ) ;
unsigned int V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_174 , __FILE__ , V_648 -> V_3 ) ;
if ( V_2 -> V_42 . V_13 )
return - V_347 ;
if ( V_299 != V_677 )
return F_267 ( V_648 , V_670 , V_299 ) ;
switch( V_670 -> V_674 . type ) {
case V_678 :
V_670 -> V_674 . type = V_679 ;
if ( V_670 -> V_674 . V_671 < V_671 ) {
V_670 -> V_674 . V_671 = V_671 ;
return - V_680 ;
}
V_12 = V_2 -> V_36 . V_12 & ( V_681 | V_504 |
V_505 | V_506 |
V_682 | V_507 |
V_508 | V_509 ) ;
switch ( V_12 ) {
case ( V_681 | V_682 ) : V_673 . V_683 = V_684 ; break;
case ( V_505 | V_508 ) : V_673 . V_683 = V_685 ; break;
case ( V_681 | V_508 ) : V_673 . V_683 = V_686 ; break;
case ( V_681 | V_509 ) : V_673 . V_683 = V_687 ; break;
default: V_673 . V_683 = V_688 ;
}
V_673 . V_689 = V_2 -> V_36 . V_517 ;
V_673 . V_581 = V_2 -> V_36 . V_581 ? 1 : 0 ;
if ( F_268 ( line , & V_673 , V_671 ) )
return - V_243 ;
return 0 ;
case V_679 :
if( ! F_79 ( V_690 ) )
return - V_691 ;
if ( F_269 ( & V_673 , line , V_671 ) )
return - V_243 ;
switch ( V_673 . V_683 )
{
case V_684 : V_12 = V_681 | V_682 ; break;
case V_687 : V_12 = V_681 | V_509 ; break;
case V_685 : V_12 = V_505 | V_508 ; break;
case V_686 : V_12 = V_681 | V_508 ; break;
case V_688 : V_12 = V_2 -> V_36 . V_12 &
( V_681 | V_504 |
V_505 | V_506 |
V_682 | V_507 |
V_508 | V_509 ) ; break;
default: return - V_294 ;
}
if ( V_673 . V_581 != 0 && V_673 . V_581 != 1 )
return - V_294 ;
V_2 -> V_36 . V_12 &= ~ ( V_681 | V_504 |
V_505 | V_506 |
V_682 | V_507 |
V_508 | V_509 ) ;
V_2 -> V_36 . V_12 |= V_12 ;
V_2 -> V_36 . V_581 = V_673 . V_581 ;
if ( V_12 & ( V_505 | V_508 ) )
V_2 -> V_36 . V_517 = V_673 . V_689 ;
else
V_2 -> V_36 . V_517 = 0 ;
if ( V_2 -> V_86 )
F_88 ( V_2 ) ;
return 0 ;
default:
return F_267 ( V_648 , V_670 , V_299 ) ;
}
}
static void F_270 ( struct V_647 * V_648 )
{
struct V_1 * V_2 = F_257 ( V_648 ) ;
unsigned long V_12 ;
if ( V_19 >= V_20 )
F_4 ( L_175 , V_648 -> V_3 ) ;
V_648 -> V_614 . V_692 ++ ;
V_648 -> V_614 . V_693 ++ ;
F_9 ( & V_2 -> V_22 , V_12 ) ;
F_10 ( V_2 ) ;
F_11 ( & V_2 -> V_22 , V_12 ) ;
F_271 ( V_648 ) ;
}
static void F_39 ( struct V_1 * V_2 )
{
if ( F_272 ( V_2 -> V_113 ) )
F_271 ( V_2 -> V_113 ) ;
}
static void F_248 ( struct V_1 * V_2 , char * V_231 , int V_671 )
{
struct V_660 * V_661 = F_273 ( V_671 ) ;
struct V_647 * V_648 = V_2 -> V_113 ;
if ( V_19 >= V_20 )
F_4 ( L_176 , V_648 -> V_3 ) ;
if ( V_661 == NULL ) {
F_4 ( V_694 L_177 ,
V_648 -> V_3 ) ;
V_648 -> V_614 . V_695 ++ ;
return;
}
memcpy ( F_274 ( V_661 , V_671 ) , V_231 , V_671 ) ;
V_661 -> V_696 = F_275 ( V_661 , V_648 ) ;
V_648 -> V_614 . V_697 ++ ;
V_648 -> V_614 . V_698 += V_671 ;
F_276 ( V_661 ) ;
}
static int F_213 ( struct V_1 * V_2 )
{
int V_24 ;
struct V_647 * V_648 ;
T_11 * V_699 ;
if ( ! ( V_648 = F_277 ( V_2 ) ) ) {
F_4 ( V_181 L_178 , __FILE__ ) ;
return - V_188 ;
}
V_648 -> V_700 = V_2 -> V_136 ;
V_648 -> V_458 = V_2 -> V_176 ;
V_648 -> V_459 = V_2 -> V_355 ;
V_648 -> V_701 = & V_702 ;
V_648 -> V_703 = 10 * V_223 ;
V_648 -> V_704 = 50 ;
V_699 = F_278 ( V_648 ) ;
V_699 -> V_705 = F_256 ;
V_699 -> V_643 = F_258 ;
if ( ( V_24 = F_279 ( V_648 ) ) ) {
F_4 ( V_668 L_179 , __FILE__ ) ;
F_280 ( V_648 ) ;
return V_24 ;
}
V_2 -> V_113 = V_648 ;
return 0 ;
}
static void F_228 ( struct V_1 * V_2 )
{
F_281 ( V_2 -> V_113 ) ;
F_280 ( V_2 -> V_113 ) ;
V_2 -> V_113 = NULL ;
}
static int F_282 ( struct V_706 * V_648 ,
const struct V_707 * V_708 )
{
struct V_1 * V_2 ;
if ( F_283 ( V_648 ) ) {
F_4 ( L_180 , V_648 ) ;
return - V_280 ;
}
if ( ! ( V_2 = F_214 () ) ) {
F_4 ( L_145 ) ;
return - V_280 ;
}
V_2 -> V_136 = F_284 ( V_648 , 2 ) ;
V_2 -> V_176 = V_648 -> V_458 ;
V_2 -> V_353 = F_284 ( V_648 , 3 ) ;
V_2 -> V_354 = F_284 ( V_648 , 0 ) ;
V_2 -> V_423 = V_2 -> V_354 & ( V_426 - 1 ) ;
V_2 -> V_354 &= ~ ( V_426 - 1 ) ;
V_2 -> V_351 = V_352 ;
V_2 -> V_417 = 8 ;
V_2 -> V_419 = V_709 ;
if ( V_648 -> V_710 == 0x0210 ) {
V_2 -> V_573 = 0x007c4080 ;
V_2 -> V_435 = 1 ;
} else {
V_2 -> V_573 = 0x087e4546 ;
V_2 -> V_435 = 0 ;
}
F_212 ( V_2 ) ;
return 0 ;
}
static void F_285 ( struct V_706 * V_648 )
{
}
