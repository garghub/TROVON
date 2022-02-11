static void F_1 ( T_1 * V_1 , unsigned char V_2 , unsigned short V_3 )
{
if ( V_2 == V_4 ) {
V_1 -> V_5 |= V_3 ;
F_2 ( V_1 , V_4 + V_6 , V_1 -> V_5 ) ;
} else {
V_1 -> V_7 |= V_3 ;
F_2 ( V_1 , V_8 + V_6 , V_1 -> V_7 ) ;
}
}
static void F_3 ( T_1 * V_1 , unsigned char V_2 , unsigned short V_3 )
{
if ( V_2 == V_4 ) {
V_1 -> V_5 &= ~ V_3 ;
F_2 ( V_1 , V_4 + V_6 , V_1 -> V_5 ) ;
} else {
V_1 -> V_7 &= ~ V_3 ;
F_2 ( V_1 , V_8 + V_6 , V_1 -> V_7 ) ;
}
}
static void * F_4 ( void )
{
return F_4 ;
}
static void F_5 ( struct V_9 * V_10 ,
const T_2 * V_11 , char * V_12 , int V_13 )
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
static int F_8 ( struct V_18 * V_19 )
{
T_1 * V_1 ;
int V_20 ;
if ( V_21 >= V_22 )
F_9 ( L_1 ) ;
V_1 = F_10 ( sizeof( T_1 ) , V_23 ) ;
if ( ! V_1 ) {
F_9 ( L_2 ) ;
return - V_24 ;
}
V_1 -> V_25 = V_26 ;
F_11 ( & V_1 -> V_27 ) ;
V_1 -> V_27 . V_16 = & V_28 ;
F_12 ( & V_1 -> V_29 , V_30 ) ;
V_1 -> V_31 = 4096 ;
V_1 -> V_27 . V_32 = 5 * V_33 / 10 ;
V_1 -> V_27 . V_34 = 30 * V_33 ;
F_13 ( & V_1 -> V_35 ) ;
F_13 ( & V_1 -> V_36 ) ;
F_14 ( & V_1 -> V_37 ) ;
F_14 ( & V_1 -> V_38 ) ;
memcpy ( & V_1 -> V_39 , & V_40 , sizeof( V_41 ) ) ;
V_1 -> V_42 = V_43 ;
V_1 -> V_5 = 0xffff ;
V_1 -> V_7 = 0xffff ;
V_1 -> V_44 = 0xff ;
V_1 -> V_45 = V_19 ;
V_19 -> V_46 = V_1 ;
V_20 = F_15 ( V_19 ) ;
if ( V_20 != 0 )
goto V_47;
V_20 = F_16 ( V_1 ) ;
if ( V_20 != 0 )
goto V_48;
return 0 ;
V_48:
F_17 ( ( V_49 ) V_19 ) ;
V_47:
F_18 ( & V_1 -> V_27 ) ;
F_19 ( V_1 ) ;
return V_20 ;
}
static int F_20 ( struct V_18 * V_45 , void * V_50 )
{
return F_21 ( V_45 ) ;
}
static int F_15 ( struct V_18 * V_19 )
{
T_1 * V_1 = V_19 -> V_46 ;
int V_20 ;
if ( V_21 >= V_22 )
F_9 ( L_3 , V_19 ) ;
V_19 -> V_51 |= V_52 | V_53 ;
V_20 = F_22 ( V_19 , F_20 , NULL ) ;
if ( V_20 != 0 )
goto V_47;
V_19 -> V_54 = 8 ;
V_19 -> V_55 = V_56 ;
V_20 = F_23 ( V_19 , V_57 ) ;
if ( V_20 )
goto V_47;
V_20 = F_24 ( V_19 ) ;
if ( V_20 )
goto V_47;
V_1 -> V_58 = V_19 -> V_59 [ 0 ] -> V_60 ;
V_1 -> V_61 = V_19 -> V_62 ;
return 0 ;
V_47:
F_17 ( ( V_49 ) V_19 ) ;
return - V_63 ;
}
static void F_17 ( V_49 V_64 )
{
struct V_18 * V_19 = (struct V_18 * ) V_64 ;
if ( V_21 >= V_22 )
F_9 ( L_4 , V_19 ) ;
F_25 ( V_19 ) ;
}
static void F_26 ( struct V_18 * V_19 )
{
if ( V_21 >= V_22 )
F_9 ( L_5 , V_19 ) ;
( ( T_1 * ) V_19 -> V_46 ) -> V_65 = 1 ;
F_17 ( ( V_49 ) V_19 ) ;
F_27 ( ( T_1 * ) V_19 -> V_46 ) ;
}
static int F_28 ( struct V_18 * V_19 )
{
T_1 * V_1 = V_19 -> V_46 ;
V_1 -> V_65 = 1 ;
return 0 ;
}
static int F_29 ( struct V_18 * V_19 )
{
T_1 * V_1 = V_19 -> V_46 ;
V_1 -> V_65 = 0 ;
return 0 ;
}
static inline bool F_30 ( T_1 * V_1 ,
char * V_66 , const char * V_67 )
{
#ifdef F_31
static const char * V_68 =
L_6 ;
static const char * V_69 =
L_7 ;
if ( ! V_1 ) {
F_9 ( V_69 , V_66 , V_67 ) ;
return true ;
}
if ( V_1 -> V_25 != V_26 ) {
F_9 ( V_68 , V_66 , V_67 ) ;
return true ;
}
#else
if ( ! V_1 )
return true ;
#endif
return false ;
}
static bool F_32 ( T_1 * V_1 , unsigned char V_2 )
{
int V_70 = 0 ;
while ( F_33 ( V_1 , ( unsigned char ) ( V_2 + V_71 ) ) & V_72 ) {
F_34 ( 1 ) ;
if ( V_70 ++ == 1000 )
return false ;
}
return true ;
}
static void F_35 ( T_1 * V_1 , unsigned char V_2 , unsigned char V_73 )
{
F_32 ( V_1 , V_2 ) ;
F_36 ( V_1 , ( unsigned char ) ( V_2 + V_74 ) , V_73 ) ;
}
static void F_37 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_8 ) )
return;
if ( V_21 >= V_22 )
F_9 ( L_9 , V_1 -> V_76 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_1 -> V_77 )
F_39 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
static void F_41 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_10 ) )
return;
if ( V_21 >= V_22 )
F_9 ( L_11 , V_1 -> V_76 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( ! V_1 -> V_77 )
F_42 ( V_1 , V_10 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
static int F_43 ( T_1 * V_1 )
{
unsigned long V_12 ;
int V_78 = 0 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_1 -> V_79 & V_80 ) {
V_1 -> V_79 &= ~ V_80 ;
V_78 = V_80 ;
} else if ( V_1 -> V_79 & V_81 ) {
V_1 -> V_79 &= ~ V_81 ;
V_78 = V_81 ;
} else if ( V_1 -> V_79 & V_82 ) {
V_1 -> V_79 &= ~ V_82 ;
V_78 = V_82 ;
}
if ( ! V_78 ) {
V_1 -> V_83 = false ;
V_1 -> V_84 = false ;
}
F_40 ( & V_1 -> V_37 , V_12 ) ;
return V_78 ;
}
static void V_30 ( struct V_85 * V_86 )
{
T_1 * V_1 = F_44 ( V_86 , T_1 , V_29 ) ;
struct V_9 * V_10 ;
int V_87 ;
if ( V_21 >= V_88 )
F_9 ( L_12 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
V_1 -> V_83 = true ;
V_10 = F_45 ( & V_1 -> V_27 ) ;
while( ( V_87 = F_43 ( V_1 ) ) != 0 ) {
if ( V_21 >= V_88 )
F_9 ( L_13 ,
__FILE__ , __LINE__ , V_87 ) ;
switch ( V_87 ) {
case V_80 :
while( F_46 ( V_1 , V_10 ) ) ;
break;
case V_81 :
F_47 ( V_1 , V_10 ) ;
break;
case V_82 :
F_48 ( V_1 ) ;
break;
default:
F_9 ( L_14 , V_87 ) ;
break;
}
}
F_49 ( V_10 ) ;
if ( V_21 >= V_88 )
F_9 ( L_15 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
}
static void F_47 ( T_1 * V_1 , struct V_9 * V_10 )
{
if ( V_21 >= V_88 )
F_9 ( L_16 , V_1 -> V_76 ) ;
if ( V_10 )
F_50 ( V_10 ) ;
}
static void F_48 ( T_1 * V_1 )
{
V_1 -> V_89 = 0 ;
V_1 -> V_90 = 0 ;
V_1 -> V_91 = 0 ;
V_1 -> V_92 = 0 ;
}
static void F_51 ( T_1 * V_1 , int V_93 )
{
unsigned char V_11 [ 2 ] ;
unsigned char V_94 , V_95 , V_70 ;
T_3 * V_96 = ( T_3 * ) ( V_1 -> V_97 + ( V_1 -> V_98 * V_1 -> V_99 ) ) ;
if ( V_21 >= V_100 )
F_9 ( L_17 , __FILE__ , __LINE__ , V_93 ) ;
if ( ! V_1 -> V_101 )
return;
if ( V_1 -> V_102 >= V_1 -> V_103 ) {
F_35 ( V_1 , V_4 , V_104 ) ;
V_1 -> V_79 |= V_80 ;
V_1 -> V_105 = true ;
V_1 -> V_106 . V_107 ++ ;
return;
}
if ( V_93 ) {
V_94 = ( unsigned char ) ( F_33 ( V_1 , V_4 + V_108 ) & 0x1f ) ;
if ( V_94 == 0 )
V_94 = 32 ;
} else
V_94 = 32 ;
do {
if ( V_94 == 1 ) {
V_95 = 1 ;
V_11 [ 0 ] = F_33 ( V_1 , V_4 + V_109 ) ;
} else {
V_95 = 2 ;
* ( ( unsigned short * ) V_11 ) = F_52 ( V_1 , V_4 + V_109 ) ;
}
V_94 -= V_95 ;
if ( ! V_94 && V_93 )
V_96 -> V_110 = V_11 [ -- V_95 ] ;
for ( V_70 = 0 ; V_70 < V_95 ; V_70 ++ ) {
if ( V_96 -> V_13 >= V_1 -> V_31 ) {
F_35 ( V_1 , V_4 , V_104 ) ;
V_96 -> V_13 = 0 ;
return;
}
* ( V_96 -> V_11 + V_96 -> V_13 ) = V_11 [ V_70 ] ;
V_96 -> V_13 ++ ;
}
} while ( V_94 );
if ( V_93 ) {
V_1 -> V_79 |= V_80 ;
V_1 -> V_102 ++ ;
V_1 -> V_98 ++ ;
if ( V_1 -> V_98 >= V_1 -> V_103 )
V_1 -> V_98 = 0 ;
}
F_35 ( V_1 , V_4 , V_111 ) ;
}
static void F_53 ( T_1 * V_1 , int V_112 )
{
struct V_113 * V_27 = & V_1 -> V_27 ;
unsigned char V_11 , V_110 , V_114 ;
int V_94 ;
int V_86 = 0 ;
struct V_115 * V_106 = & V_1 -> V_106 ;
if ( V_112 ) {
V_94 = ( unsigned char ) ( F_33 ( V_1 , V_4 + V_108 ) & 0x1f ) ;
if ( ! V_94 && ( F_33 ( V_1 , V_4 + V_71 ) & V_116 ) )
V_94 = 32 ;
} else
V_94 = 32 ;
F_54 ( V_27 , V_94 ) ;
while ( V_94 ) {
V_11 = F_33 ( V_1 , V_4 + V_109 ) ;
V_110 = F_33 ( V_1 , V_4 + V_109 ) ;
V_94 -= 2 ;
V_106 -> V_117 ++ ;
V_114 = V_118 ;
if ( V_110 & ( V_119 + V_120 ) ) {
if ( V_110 & V_119 )
V_106 -> V_121 ++ ;
else
V_106 -> V_122 ++ ;
if ( V_110 & V_1 -> V_123 )
continue;
V_110 &= V_1 -> V_124 ;
if ( V_110 & V_119 )
V_114 = V_125 ;
else if ( V_110 & V_120 )
V_114 = V_126 ;
}
V_86 += F_55 ( V_27 , V_11 , V_114 ) ;
}
F_35 ( V_1 , V_4 , V_111 ) ;
if ( V_21 >= V_100 ) {
F_9 ( L_18 ,
__FILE__ , __LINE__ ) ;
F_9 ( L_19 ,
__FILE__ , __LINE__ , V_106 -> V_117 , V_106 -> V_127 ,
V_106 -> V_121 , V_106 -> V_122 , V_106 -> V_128 ) ;
}
if ( V_86 )
F_56 ( V_27 ) ;
}
static void F_57 ( T_1 * V_1 , struct V_9 * V_10 )
{
if ( ! V_1 -> V_129 )
return;
V_1 -> V_129 = false ;
V_1 -> V_130 = false ;
if ( V_1 -> V_39 . V_131 == V_132 )
return;
V_1 -> V_133 = V_1 -> V_134 = V_1 -> V_135 = 0 ;
F_58 ( & V_1 -> V_136 ) ;
if ( V_1 -> V_137 ) {
F_59 ( V_1 ) ;
if ( V_1 -> V_138 & V_139 ) {
V_1 -> V_138 &= ~ V_139 ;
F_60 ( V_1 ) ;
}
V_1 -> V_137 = false ;
}
#if V_140
if ( V_1 -> V_141 )
F_61 ( V_1 ) ;
else
#endif
{
if ( V_10 && ( V_10 -> V_142 || V_10 -> V_143 ) ) {
F_39 ( V_1 ) ;
return;
}
V_1 -> V_79 |= V_81 ;
}
}
static void F_62 ( T_1 * V_1 , struct V_9 * V_10 )
{
unsigned char V_94 = 32 ;
int V_144 ;
if ( V_21 >= V_100 )
F_9 ( L_20 , __FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( V_1 -> V_39 . V_131 == V_145 ) {
if ( ! V_1 -> V_129 )
return;
} else {
if ( V_10 && ( V_10 -> V_142 || V_10 -> V_143 ) ) {
F_39 ( V_1 ) ;
return;
}
if ( ! V_1 -> V_133 )
V_1 -> V_129 = false ;
}
if ( ! V_1 -> V_133 )
return;
while ( V_1 -> V_133 && V_94 ) {
V_144 = F_63 ( 2 , F_64 ( int , V_94 , F_63 ( V_1 -> V_133 , V_146 - V_1 -> V_135 ) ) ) ;
if ( V_144 == 1 ) {
F_36 ( V_1 , V_4 + V_147 , * ( V_1 -> V_148 + V_1 -> V_135 ) ) ;
} else {
F_2 ( V_1 , V_4 + V_147 ,
* ( ( unsigned short * ) ( V_1 -> V_148 + V_1 -> V_135 ) ) ) ;
}
V_1 -> V_133 -= V_144 ;
V_1 -> V_135 = ( V_1 -> V_135 + V_144 ) & ( V_146 - 1 ) ;
V_94 -= V_144 ;
}
if ( V_1 -> V_39 . V_131 == V_132 ) {
if ( V_1 -> V_133 < V_149 )
V_1 -> V_79 |= V_81 ;
F_35 ( V_1 , V_4 , V_150 ) ;
} else {
if ( V_1 -> V_133 )
F_35 ( V_1 , V_4 , V_150 ) ;
else
F_35 ( V_1 , V_4 , V_150 + V_151 ) ;
}
}
static void F_65 ( T_1 * V_1 , struct V_9 * V_10 )
{
F_59 ( V_1 ) ;
if ( ( V_1 -> V_92 ) ++ >= V_152 )
F_1 ( V_1 , V_8 , V_153 ) ;
V_1 -> V_106 . V_154 ++ ;
if ( V_1 -> V_138 & V_155 )
V_1 -> V_156 . V_157 ++ ;
else
V_1 -> V_156 . V_158 ++ ;
F_66 ( & V_1 -> V_35 ) ;
F_66 ( & V_1 -> V_36 ) ;
if ( V_10 && F_67 ( & V_1 -> V_27 ) ) {
if ( V_10 -> V_143 ) {
if ( V_1 -> V_138 & V_155 ) {
if ( V_21 >= V_100 )
F_9 ( L_21 ) ;
V_10 -> V_143 = 0 ;
F_42 ( V_1 , V_10 ) ;
V_1 -> V_79 |= V_81 ;
return;
}
} else {
if ( ! ( V_1 -> V_138 & V_155 ) ) {
if ( V_21 >= V_100 )
F_9 ( L_22 ) ;
V_10 -> V_143 = 1 ;
F_39 ( V_1 ) ;
}
}
}
V_1 -> V_79 |= V_82 ;
}
static void F_68 ( T_1 * V_1 , struct V_9 * V_10 )
{
F_59 ( V_1 ) ;
if ( ( V_1 -> V_91 ) ++ >= V_152 )
F_1 ( V_1 , V_8 , V_159 ) ;
V_1 -> V_106 . V_160 ++ ;
if ( V_1 -> V_138 & V_161 ) {
V_1 -> V_156 . V_162 ++ ;
}
else
V_1 -> V_156 . V_163 ++ ;
#if V_140
if ( V_1 -> V_141 ) {
if ( V_1 -> V_138 & V_161 )
F_69 ( V_1 -> V_164 ) ;
else
F_70 ( V_1 -> V_164 ) ;
}
#endif
F_66 ( & V_1 -> V_35 ) ;
F_66 ( & V_1 -> V_36 ) ;
if ( F_71 ( & V_1 -> V_27 ) ) {
if ( V_21 >= V_100 )
F_9 ( L_23 , V_1 -> V_76 ,
( V_1 -> V_138 & V_161 ) ? L_24 : L_25 ) ;
if ( V_1 -> V_138 & V_161 )
F_66 ( & V_1 -> V_27 . V_165 ) ;
else {
if ( V_21 >= V_100 )
F_9 ( L_26 ) ;
if ( V_10 )
F_72 ( V_10 ) ;
}
}
V_1 -> V_79 |= V_82 ;
}
static void F_73 ( T_1 * V_1 )
{
F_59 ( V_1 ) ;
if ( ( V_1 -> V_90 ) ++ >= V_152 )
F_74 ( V_1 , V_166 ) ;
V_1 -> V_106 . V_167 ++ ;
if ( V_1 -> V_138 & V_168 )
V_1 -> V_156 . V_169 ++ ;
else
V_1 -> V_156 . V_170 ++ ;
F_66 ( & V_1 -> V_35 ) ;
F_66 ( & V_1 -> V_36 ) ;
V_1 -> V_79 |= V_82 ;
}
static void F_75 ( T_1 * V_1 )
{
F_59 ( V_1 ) ;
if ( ( V_1 -> V_89 ) ++ >= V_152 )
F_74 ( V_1 , V_171 ) ;
V_1 -> V_106 . V_172 ++ ;
if ( V_1 -> V_138 & V_173 )
V_1 -> V_156 . V_174 ++ ;
else
V_1 -> V_156 . V_175 ++ ;
F_66 ( & V_1 -> V_35 ) ;
F_66 ( & V_1 -> V_36 ) ;
V_1 -> V_79 |= V_82 ;
}
static T_4 V_57 ( int V_176 , void * V_177 )
{
T_1 * V_1 = V_177 ;
struct V_9 * V_10 ;
unsigned short V_178 ;
unsigned char V_179 , V_180 ;
int V_13 = 0 ;
if ( V_21 >= V_100 )
F_9 ( L_27 , V_1 -> V_61 ) ;
if ( ! ( V_1 -> V_45 -> V_181 ) )
return V_182 ;
V_10 = F_45 ( & V_1 -> V_27 ) ;
F_76 ( & V_1 -> V_37 ) ;
while ( ( V_179 = F_33 ( V_1 , V_4 + V_183 ) ) ) {
if ( V_21 >= V_100 )
F_9 ( L_28 , V_1 -> V_76 , V_179 ) ;
if ( ( V_179 & 0x70 ) || V_13 > 1000 ) {
F_9 ( L_29 ) ;
break;
}
V_13 ++ ;
if ( V_179 & ( V_184 | V_185 ) ) {
V_178 = F_52 ( V_1 , V_8 + V_186 ) ;
if ( V_178 & V_159 )
F_68 ( V_1 , V_10 ) ;
if ( V_178 & V_153 )
F_65 ( V_1 , V_10 ) ;
}
if ( V_179 & ( V_187 | V_72 ) )
{
V_178 = F_52 ( V_1 , V_4 + V_186 ) ;
if ( V_178 & V_188 ) {
V_1 -> V_189 = true ;
F_1 ( V_1 , V_4 , V_188 ) ;
}
if ( V_178 & V_190 ) {
V_1 -> V_106 . V_191 ++ ;
F_66 ( & V_1 -> V_36 ) ;
}
if ( V_178 & V_192 ) {
V_1 -> V_106 . V_127 ++ ;
if ( V_1 -> V_27 . V_12 & V_193 )
F_77 ( V_10 ) ;
}
if ( V_178 & V_194 ) {
F_35 ( V_1 , V_4 , V_195 ) ;
}
if ( V_178 & ( V_196 | V_197 ) ) {
if ( V_1 -> V_39 . V_131 == V_145 )
F_51 ( V_1 , V_178 & V_196 ) ;
else
F_53 ( V_1 , V_178 & V_196 ) ;
}
if ( V_178 & V_198 ) {
if ( V_1 -> V_130 )
V_1 -> V_106 . V_199 ++ ;
else
V_1 -> V_106 . V_200 ++ ;
F_57 ( V_1 , V_10 ) ;
}
else if ( V_178 & V_201 ) {
V_1 -> V_106 . V_202 ++ ;
F_57 ( V_1 , V_10 ) ;
}
else if ( V_178 & V_203 )
F_62 ( V_1 , V_10 ) ;
}
if ( V_179 & V_119 ) {
V_180 = F_33 ( V_1 , V_4 + V_204 ) ;
if ( V_180 & V_184 )
F_73 ( V_1 ) ;
if ( V_180 & V_72 )
F_75 ( V_1 ) ;
}
}
if ( V_1 -> V_79 && ! V_1 -> V_83 && ! V_1 -> V_84 ) {
if ( V_21 >= V_100 )
F_9 ( L_30 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
F_78 ( & V_1 -> V_29 ) ;
V_1 -> V_84 = true ;
}
F_79 ( & V_1 -> V_37 ) ;
F_49 ( V_10 ) ;
if ( V_21 >= V_100 )
F_9 ( L_31 ,
__FILE__ , __LINE__ , V_1 -> V_61 ) ;
return V_182 ;
}
static int F_80 ( T_1 * V_1 , struct V_9 * V_10 )
{
int V_205 = 0 ;
if ( V_21 >= V_22 )
F_9 ( L_32 , __FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( F_81 ( & V_1 -> V_27 ) )
return 0 ;
if ( ! V_1 -> V_148 ) {
V_1 -> V_148 = ( unsigned char * ) F_82 ( V_23 ) ;
if ( ! V_1 -> V_148 ) {
F_9 ( V_206 L_33 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
return - V_24 ;
}
}
V_1 -> V_79 = 0 ;
memset ( & V_1 -> V_106 , 0 , sizeof( V_1 -> V_106 ) ) ;
F_83 ( & V_1 -> V_136 , V_207 , ( unsigned long ) V_1 ) ;
V_205 = F_84 ( V_1 ) ;
if ( ! V_205 )
V_205 = F_85 ( V_1 ) ;
if ( V_205 ) {
if ( F_86 ( V_208 ) && V_10 )
F_87 ( V_209 , & V_10 -> V_12 ) ;
F_88 ( V_1 ) ;
return V_205 ;
}
F_89 ( V_1 , V_10 ) ;
if ( V_10 )
F_90 ( V_209 , & V_10 -> V_12 ) ;
F_91 ( & V_1 -> V_27 , 1 ) ;
return 0 ;
}
static void F_92 ( T_1 * V_1 , struct V_9 * V_10 )
{
unsigned long V_12 ;
if ( ! F_81 ( & V_1 -> V_27 ) )
return;
if ( V_21 >= V_22 )
F_9 ( L_34 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
F_66 ( & V_1 -> V_35 ) ;
F_66 ( & V_1 -> V_36 ) ;
F_93 ( & V_1 -> V_136 ) ;
if ( V_1 -> V_148 ) {
F_94 ( ( unsigned long ) V_1 -> V_148 ) ;
V_1 -> V_148 = NULL ;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_95 ( V_1 ) ;
F_39 ( V_1 ) ;
F_96 ( V_1 ) ;
if ( ! V_10 || F_97 ( V_10 ) ) {
V_1 -> V_138 &= ~ ( V_139 | V_210 ) ;
F_60 ( V_1 ) ;
}
F_40 ( & V_1 -> V_37 , V_12 ) ;
F_88 ( V_1 ) ;
if ( V_10 )
F_87 ( V_209 , & V_10 -> V_12 ) ;
F_91 ( & V_1 -> V_27 , 0 ) ;
}
static void F_98 ( T_1 * V_1 , struct V_9 * V_10 )
{
unsigned long V_12 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_95 ( V_1 ) ;
F_39 ( V_1 ) ;
V_1 -> V_133 = V_1 -> V_134 = V_1 -> V_135 = 0 ;
if ( V_1 -> V_39 . V_131 == V_145 || V_1 -> V_141 )
F_99 ( V_1 ) ;
else
F_100 ( V_1 ) ;
F_60 ( V_1 ) ;
V_1 -> V_91 = 0 ;
V_1 -> V_92 = 0 ;
V_1 -> V_89 = 0 ;
V_1 -> V_90 = 0 ;
F_3 ( V_1 , V_8 , V_159 | V_153 ) ;
F_101 ( V_1 , ( unsigned char ) V_166 | V_171 ) ;
F_59 ( V_1 ) ;
if ( V_1 -> V_141 || ( V_10 && F_102 ( V_10 ) ) )
F_103 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
static void F_89 ( T_1 * V_1 , struct V_9 * V_10 )
{
unsigned V_211 ;
int V_212 ;
if ( ! V_10 )
return;
if ( V_21 >= V_22 )
F_9 ( L_35 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
V_211 = V_10 -> V_213 . V_214 ;
if ( V_211 & V_215 )
V_1 -> V_138 |= V_139 | V_210 ;
else
V_1 -> V_138 &= ~ ( V_139 | V_210 ) ;
switch ( V_211 & V_216 ) {
case V_217 : V_1 -> V_39 . V_218 = 5 ; break;
case V_219 : V_1 -> V_39 . V_218 = 6 ; break;
case V_220 : V_1 -> V_39 . V_218 = 7 ; break;
case V_221 : V_1 -> V_39 . V_218 = 8 ; break;
default: V_1 -> V_39 . V_218 = 7 ; break;
}
if ( V_211 & V_222 )
V_1 -> V_39 . V_223 = 2 ;
else
V_1 -> V_39 . V_223 = 1 ;
V_1 -> V_39 . V_121 = V_224 ;
if ( V_211 & V_225 ) {
if ( V_211 & V_226 )
V_1 -> V_39 . V_121 = V_227 ;
else
V_1 -> V_39 . V_121 = V_228 ;
#ifdef F_104
if ( V_211 & F_104 )
V_1 -> V_39 . V_121 = V_229 ;
#endif
}
V_212 = V_1 -> V_39 . V_218 +
V_1 -> V_39 . V_223 + 1 ;
if ( V_1 -> V_39 . V_230 <= 460800 ) {
V_1 -> V_39 . V_230 = F_105 ( V_10 ) ;
}
if ( V_1 -> V_39 . V_230 ) {
V_1 -> V_231 = ( 32 * V_33 * V_212 ) /
V_1 -> V_39 . V_230 ;
}
V_1 -> V_231 += V_33 / 50 ;
F_106 ( & V_1 -> V_27 , V_211 & V_232 ) ;
F_107 ( & V_1 -> V_27 , ~ V_211 & V_233 ) ;
V_1 -> V_124 = 0 ;
if ( F_108 ( V_10 ) )
V_1 -> V_124 |= V_119 | V_120 ;
if ( F_109 ( V_10 ) )
V_1 -> V_123 |= V_119 | V_120 ;
F_98 ( V_1 , V_10 ) ;
}
static int F_110 ( struct V_9 * V_10 , unsigned char V_234 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 ) {
F_9 ( L_36 ,
__FILE__ , __LINE__ , V_234 , V_1 -> V_76 ) ;
}
if ( F_30 ( V_1 , V_10 -> V_66 , L_37 ) )
return 0 ;
if ( ! V_1 -> V_148 )
return 0 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_1 -> V_39 . V_131 == V_132 || ! V_1 -> V_129 ) {
if ( V_1 -> V_133 < V_146 - 1 ) {
V_1 -> V_148 [ V_1 -> V_134 ++ ] = V_234 ;
V_1 -> V_134 &= V_146 - 1 ;
V_1 -> V_133 ++ ;
}
}
F_40 ( & V_1 -> V_37 , V_12 ) ;
return 1 ;
}
static void F_111 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_38 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_1 -> V_133 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_39 ) )
return;
if ( V_1 -> V_133 <= 0 || V_10 -> V_142 ||
V_10 -> V_143 || ! V_1 -> V_148 )
return;
if ( V_21 >= V_22 )
F_9 ( L_40 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( ! V_1 -> V_129 )
F_42 ( V_1 , V_10 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
static int F_112 ( struct V_9 * V_10 ,
const unsigned char * V_96 , int V_13 )
{
int V_144 , V_20 = 0 ;
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_41 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_13 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_42 ) ||
! V_1 -> V_148 )
goto V_235;
if ( V_1 -> V_39 . V_131 == V_145 ) {
if ( V_13 > V_146 ) {
V_20 = - V_236 ;
goto V_235;
}
if ( V_1 -> V_129 )
goto V_235;
else if ( V_1 -> V_133 )
goto V_60;
}
for (; ; ) {
V_144 = F_63 ( V_13 ,
F_63 ( V_146 - V_1 -> V_133 - 1 ,
V_146 - V_1 -> V_134 ) ) ;
if ( V_144 <= 0 )
break;
memcpy ( V_1 -> V_148 + V_1 -> V_134 , V_96 , V_144 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_134 = ( V_1 -> V_134 + V_144 ) & ( V_146 - 1 ) ;
V_1 -> V_133 += V_144 ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
V_96 += V_144 ;
V_13 -= V_144 ;
V_20 += V_144 ;
}
V_60:
if ( V_1 -> V_133 && ! V_10 -> V_142 && ! V_10 -> V_143 ) {
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( ! V_1 -> V_129 )
F_42 ( V_1 , V_10 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
V_235:
if ( V_21 >= V_22 )
F_9 ( L_43 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_20 ) ;
return V_20 ;
}
static int F_113 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
int V_20 ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_44 ) )
return 0 ;
if ( V_1 -> V_39 . V_131 == V_145 ) {
if ( V_1 -> V_129 )
return 0 ;
else
return V_237 ;
} else {
V_20 = V_146 - V_1 -> V_133 - 1 ;
if ( V_20 < 0 )
V_20 = 0 ;
}
if ( V_21 >= V_22 )
F_9 ( L_45 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_20 ) ;
return V_20 ;
}
static int F_114 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
int V_78 ;
if ( V_21 >= V_22 )
F_9 ( L_46 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_47 ) )
return 0 ;
if ( V_1 -> V_39 . V_131 == V_145 )
V_78 = V_1 -> V_129 ? V_1 -> V_31 : 0 ;
else
V_78 = V_1 -> V_133 ;
if ( V_21 >= V_22 )
F_9 ( L_48 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_78 ) ;
return V_78 ;
}
static void F_115 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_49 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_50 ) )
return;
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_133 = V_1 -> V_134 = V_1 -> V_135 = 0 ;
F_58 ( & V_1 -> V_136 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
F_66 ( & V_10 -> V_238 ) ;
F_50 ( V_10 ) ;
}
static void F_116 ( struct V_9 * V_10 , char V_234 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_51 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_234 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_52 ) )
return;
V_1 -> V_239 = V_234 ;
if ( V_234 ) {
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( ! V_1 -> V_77 )
F_42 ( V_1 , V_10 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
}
static void F_117 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_53 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_54 ) )
return;
if ( F_118 ( V_10 ) )
F_116 ( V_10 , F_119 ( V_10 ) ) ;
if ( F_120 ( V_10 ) ) {
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_138 &= ~ V_139 ;
F_60 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
}
static void F_121 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_55 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_56 ) )
return;
if ( F_118 ( V_10 ) ) {
if ( V_1 -> V_239 )
V_1 -> V_239 = 0 ;
else
F_116 ( V_10 , F_122 ( V_10 ) ) ;
}
if ( F_120 ( V_10 ) ) {
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_138 |= V_139 ;
F_60 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
}
static int F_123 ( T_1 * V_1 , struct V_115 T_5 * V_240 )
{
int V_241 ;
if ( V_21 >= V_22 )
F_9 ( L_57 , V_1 -> V_76 ) ;
if ( ! V_240 ) {
memset ( & V_1 -> V_106 , 0 , sizeof( V_1 -> V_106 ) ) ;
} else {
F_124 ( V_241 , V_240 , & V_1 -> V_106 , sizeof( struct V_115 ) ) ;
if ( V_241 )
return - V_242 ;
}
return 0 ;
}
static int F_125 ( T_1 * V_1 , V_41 T_5 * V_243 )
{
int V_241 ;
if ( V_21 >= V_22 )
F_9 ( L_57 , V_1 -> V_76 ) ;
F_124 ( V_241 , V_243 , & V_1 -> V_39 , sizeof( V_41 ) ) ;
if ( V_241 )
return - V_242 ;
return 0 ;
}
static int F_126 ( T_1 * V_1 , V_41 T_5 * V_244 , struct V_9 * V_10 )
{
unsigned long V_12 ;
V_41 V_245 ;
int V_241 ;
if ( V_21 >= V_22 )
F_9 ( L_58 , __FILE__ , __LINE__ ,
V_1 -> V_76 ) ;
F_127 ( V_241 , & V_245 , V_244 , sizeof( V_41 ) ) ;
if ( V_241 ) {
if ( V_21 >= V_22 )
F_9 ( L_59 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
return - V_242 ;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
memcpy ( & V_1 -> V_39 , & V_245 , sizeof( V_41 ) ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
F_89 ( V_1 , V_10 ) ;
return 0 ;
}
static int F_128 ( T_1 * V_1 , int T_5 * V_42 )
{
int V_241 ;
if ( V_21 >= V_22 )
F_9 ( L_60 , V_1 -> V_76 , V_1 -> V_42 ) ;
F_124 ( V_241 , V_42 , & V_1 -> V_42 , sizeof( int ) ) ;
if ( V_241 )
return - V_242 ;
return 0 ;
}
static int F_129 ( T_1 * V_1 , int V_42 )
{
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_61 , V_1 -> V_76 , V_42 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_42 = V_42 ;
F_130 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_131 ( T_1 * V_1 , int T_5 * V_246 )
{
int V_241 ;
if ( V_21 >= V_22 )
F_9 ( L_62 , V_1 -> V_76 , V_1 -> V_246 ) ;
F_124 ( V_241 , V_246 , & V_1 -> V_246 , sizeof( int ) ) ;
if ( V_241 )
return - V_242 ;
return 0 ;
}
static int F_132 ( T_1 * V_1 , int V_246 )
{
unsigned long V_12 ;
unsigned char V_247 ;
if ( V_21 >= V_22 )
F_9 ( L_63 , V_1 -> V_76 , V_246 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_246 = V_246 ;
V_247 = F_33 ( V_1 , V_248 ) & 0x0f ;
switch ( V_1 -> V_246 )
{
case V_249 : V_247 |= V_250 ; break;
case V_251 : V_247 |= V_252 ; break;
case V_253 : V_247 |= V_254 ; break;
}
F_36 ( V_1 , V_248 , V_247 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_133 ( T_1 * V_1 , int V_255 , struct V_9 * V_10 )
{
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_64 , V_1 -> V_76 , V_255 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_255 ) {
if ( ! V_1 -> V_77 )
F_42 ( V_1 , V_10 ) ;
} else {
if ( V_1 -> V_77 )
F_39 ( V_1 ) ;
}
F_40 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_134 ( T_1 * V_1 )
{
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_65 , V_1 -> V_76 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_1 -> V_129 && V_1 -> V_133 &&
V_1 -> V_39 . V_131 == V_145 ) {
V_1 -> V_133 = V_1 -> V_134 = V_1 -> V_135 = 0 ;
V_1 -> V_130 = true ;
}
F_40 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_135 ( T_1 * V_1 , int V_255 )
{
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_66 , V_1 -> V_76 , V_255 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_255 ) {
if ( ! V_1 -> V_101 )
F_103 ( V_1 ) ;
} else {
if ( V_1 -> V_101 )
F_95 ( V_1 ) ;
}
F_40 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_136 ( T_1 * V_1 , int T_5 * V_256 )
{
unsigned long V_12 ;
int V_257 ;
int V_78 = 0 ;
struct V_115 V_258 , V_259 ;
int V_260 ;
int V_3 ;
struct V_261 V_262 , V_263 ;
F_137 ( V_264 , V_265 ) ;
F_127 ( V_78 , & V_3 , V_256 , sizeof( int ) ) ;
if ( V_78 )
return - V_242 ;
if ( V_21 >= V_22 )
F_9 ( L_67 , V_1 -> V_76 , V_3 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_59 ( V_1 ) ;
V_257 = V_1 -> V_138 ;
V_260 = V_3 &
( ( ( V_257 & V_168 ) ? V_266 : V_267 ) +
( ( V_257 & V_161 ) ? V_268 : V_269 ) +
( ( V_257 & V_155 ) ? V_270 : V_271 ) +
( ( V_257 & V_173 ) ? V_272 : V_273 ) ) ;
if ( V_260 ) {
F_40 ( & V_1 -> V_37 , V_12 ) ;
goto exit;
}
V_258 = V_1 -> V_106 ;
V_262 = V_1 -> V_156 ;
if ( ( V_1 -> V_39 . V_131 == V_145 ) &&
( V_3 & V_274 ) )
F_3 ( V_1 , V_4 , V_190 ) ;
F_138 ( V_275 ) ;
F_139 ( & V_1 -> V_36 , & V_264 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
for(; ; ) {
F_140 () ;
if ( F_141 ( V_265 ) ) {
V_78 = - V_276 ;
break;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_259 = V_1 -> V_106 ;
V_263 = V_1 -> V_156 ;
F_138 ( V_275 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
if ( V_263 . V_169 == V_262 . V_169 &&
V_263 . V_170 == V_262 . V_170 &&
V_263 . V_162 == V_262 . V_162 &&
V_263 . V_163 == V_262 . V_163 &&
V_263 . V_157 == V_262 . V_157 &&
V_263 . V_158 == V_262 . V_158 &&
V_263 . V_174 == V_262 . V_174 &&
V_263 . V_175 == V_262 . V_175 &&
V_259 . V_191 == V_258 . V_191 &&
V_259 . V_277 == V_258 . V_277 ) {
V_78 = - V_236 ;
break;
}
V_260 = V_3 &
( ( V_263 . V_169 != V_262 . V_169 ? V_266 : 0 ) +
( V_263 . V_170 != V_262 . V_170 ? V_267 : 0 ) +
( V_263 . V_162 != V_262 . V_162 ? V_268 : 0 ) +
( V_263 . V_163 != V_262 . V_163 ? V_269 : 0 ) +
( V_263 . V_157 != V_262 . V_157 ? V_270 : 0 ) +
( V_263 . V_158 != V_262 . V_158 ? V_271 : 0 ) +
( V_263 . V_174 != V_262 . V_174 ? V_272 : 0 ) +
( V_263 . V_175 != V_262 . V_175 ? V_273 : 0 ) +
( V_259 . V_191 != V_258 . V_191 ? V_274 : 0 ) +
( V_259 . V_277 != V_258 . V_277 ? V_278 : 0 ) ) ;
if ( V_260 )
break;
V_258 = V_259 ;
V_262 = V_263 ;
}
F_142 ( & V_1 -> V_36 , & V_264 ) ;
F_138 ( V_279 ) ;
if ( V_3 & V_274 ) {
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( ! F_143 ( & V_1 -> V_36 ) )
F_1 ( V_1 , V_4 , V_190 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
exit:
if ( V_78 == 0 )
F_144 ( V_78 , V_260 , V_256 ) ;
return V_78 ;
}
static int F_145 ( T_1 * V_1 , int V_64 )
{
unsigned long V_12 ;
int V_78 ;
struct V_115 V_258 , V_259 ;
F_137 ( V_264 , V_265 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_258 = V_1 -> V_106 ;
F_139 ( & V_1 -> V_35 , & V_264 ) ;
F_138 ( V_275 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
for(; ; ) {
F_140 () ;
if ( F_141 ( V_265 ) ) {
V_78 = - V_276 ;
break;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_259 = V_1 -> V_106 ;
F_138 ( V_275 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
if ( V_259 . V_172 == V_258 . V_172 && V_259 . V_167 == V_258 . V_167 &&
V_259 . V_160 == V_258 . V_160 && V_259 . V_154 == V_258 . V_154 ) {
V_78 = - V_236 ;
break;
}
if ( ( V_64 & V_280 && V_259 . V_172 != V_258 . V_172 ) ||
( V_64 & V_281 && V_259 . V_167 != V_258 . V_167 ) ||
( V_64 & V_282 && V_259 . V_160 != V_258 . V_160 ) ||
( V_64 & V_283 && V_259 . V_154 != V_258 . V_154 ) ) {
V_78 = 0 ;
break;
}
V_258 = V_259 ;
}
F_142 ( & V_1 -> V_35 , & V_264 ) ;
F_138 ( V_279 ) ;
return V_78 ;
}
static int F_146 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned int V_284 ;
unsigned long V_12 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_59 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
V_284 = ( ( V_1 -> V_138 & V_139 ) ? V_285 : 0 ) +
( ( V_1 -> V_138 & V_210 ) ? V_286 : 0 ) +
( ( V_1 -> V_138 & V_161 ) ? V_287 : 0 ) +
( ( V_1 -> V_138 & V_173 ) ? V_280 : 0 ) +
( ( V_1 -> V_138 & V_168 ) ? V_281 : 0 ) +
( ( V_1 -> V_138 & V_155 ) ? V_283 : 0 ) ;
if ( V_21 >= V_22 )
F_9 ( L_68 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_284 ) ;
return V_284 ;
}
static int F_147 ( struct V_9 * V_10 ,
unsigned int V_288 , unsigned int V_289 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_69 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_288 , V_289 ) ;
if ( V_288 & V_285 )
V_1 -> V_138 |= V_139 ;
if ( V_288 & V_286 )
V_1 -> V_138 |= V_210 ;
if ( V_289 & V_285 )
V_1 -> V_138 &= ~ V_139 ;
if ( V_289 & V_286 )
V_1 -> V_138 &= ~ V_210 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_60 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_148 ( struct V_9 * V_10 , int V_290 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_70 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_290 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_71 ) )
return - V_291 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_290 == - 1 )
F_149 ( V_1 , V_4 + V_292 , V_120 ) ;
else
F_150 ( V_1 , V_4 + V_292 , V_120 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_151 ( struct V_9 * V_10 ,
struct V_293 * V_106 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
struct V_115 V_259 ;
unsigned long V_12 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_259 = V_1 -> V_106 ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
V_106 -> V_154 = V_259 . V_154 ;
V_106 -> V_167 = V_259 . V_167 ;
V_106 -> V_172 = V_259 . V_172 ;
V_106 -> V_160 = V_259 . V_160 ;
V_106 -> V_117 = V_259 . V_117 ;
V_106 -> V_294 = V_259 . V_294 ;
V_106 -> V_122 = V_259 . V_122 ;
V_106 -> V_128 = V_259 . V_128 ;
V_106 -> V_121 = V_259 . V_121 ;
V_106 -> V_127 = V_259 . V_127 ;
V_106 -> V_107 = V_259 . V_107 ;
return 0 ;
}
static int F_152 ( struct V_9 * V_10 ,
unsigned int V_73 , unsigned long V_64 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
void T_5 * V_295 = ( void T_5 * ) V_64 ;
if ( V_21 >= V_22 )
F_9 ( L_72 , __FILE__ , __LINE__ ,
V_1 -> V_76 , V_73 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_73 ) )
return - V_63 ;
if ( ( V_73 != V_296 ) && ( V_73 != V_297 ) &&
( V_73 != V_298 ) ) {
if ( F_153 ( V_10 ) )
return - V_236 ;
}
switch ( V_73 ) {
case V_299 :
return F_125 ( V_1 , V_295 ) ;
case V_300 :
return F_126 ( V_1 , V_295 , V_10 ) ;
case V_301 :
return F_128 ( V_1 , V_295 ) ;
case V_302 :
return F_129 ( V_1 , ( int ) V_64 ) ;
case V_303 :
return F_131 ( V_1 , V_295 ) ;
case V_304 :
return F_132 ( V_1 , ( int ) V_64 ) ;
case V_305 :
return F_133 ( V_1 , ( int ) V_64 , V_10 ) ;
case V_306 :
return F_135 ( V_1 , ( int ) V_64 ) ;
case V_307 :
return F_134 ( V_1 ) ;
case V_308 :
return F_123 ( V_1 , V_295 ) ;
case V_309 :
return F_136 ( V_1 , V_295 ) ;
case V_298 :
return F_145 ( V_1 , ( int ) V_64 ) ;
default:
return - V_310 ;
}
return 0 ;
}
static void F_154 ( struct V_9 * V_10 , struct V_311 * V_312 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_74 , __FILE__ , __LINE__ ,
V_10 -> V_313 -> V_66 ) ;
if ( ( V_10 -> V_213 . V_214 == V_312 -> V_214 )
&& ( F_155 ( V_10 -> V_213 . V_314 )
== F_155 ( V_312 -> V_314 ) ) )
return;
F_89 ( V_1 , V_10 ) ;
if ( ( V_312 -> V_214 & V_215 ) && ! F_156 ( V_10 ) ) {
V_1 -> V_138 &= ~ ( V_139 | V_210 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_60 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
if ( ! ( V_312 -> V_214 & V_215 ) && F_156 ( V_10 ) ) {
V_1 -> V_138 |= V_210 ;
if ( ! F_120 ( V_10 ) || ! F_157 ( V_10 ) )
V_1 -> V_138 |= V_139 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_60 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
if ( V_312 -> V_214 & V_232 && ! F_120 ( V_10 ) ) {
V_10 -> V_143 = 0 ;
F_41 ( V_10 ) ;
}
}
static void F_158 ( struct V_9 * V_10 , struct V_315 * V_316 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
struct V_113 * V_27 = & V_1 -> V_27 ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_75 ) )
return;
if ( V_21 >= V_22 )
F_9 ( L_76 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_27 -> V_13 ) ;
if ( F_159 ( V_27 , V_10 , V_316 ) == 0 )
goto V_235;
if ( F_81 ( V_27 ) )
F_160 ( V_10 , V_1 -> V_231 ) ;
F_115 ( V_10 ) ;
F_161 ( V_10 ) ;
F_92 ( V_1 , V_10 ) ;
F_162 ( V_27 , V_10 ) ;
F_163 ( V_27 , NULL ) ;
V_235:
if ( V_21 >= V_22 )
F_9 ( L_77 , __FILE__ , __LINE__ ,
V_10 -> V_313 -> V_66 , V_27 -> V_13 ) ;
}
static void F_160 ( struct V_9 * V_10 , int V_231 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_317 , V_318 ;
if ( ! V_1 )
return;
if ( V_21 >= V_22 )
F_9 ( L_78 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_79 ) )
return;
if ( ! F_81 ( & V_1 -> V_27 ) )
goto exit;
V_317 = V_319 ;
if ( V_1 -> V_39 . V_230 ) {
V_318 = V_1 -> V_231 / ( 32 * 5 ) ;
if ( ! V_318 )
V_318 ++ ;
} else
V_318 = 1 ;
if ( V_231 )
V_318 = F_64 (unsigned long, char_time, timeout) ;
if ( V_1 -> V_39 . V_131 == V_145 ) {
while ( V_1 -> V_129 ) {
F_164 ( F_165 ( V_318 ) ) ;
if ( F_141 ( V_265 ) )
break;
if ( V_231 && F_166 ( V_319 , V_317 + V_231 ) )
break;
}
} else {
while ( ( V_1 -> V_133 || V_1 -> V_129 ) &&
V_1 -> V_77 ) {
F_164 ( F_165 ( V_318 ) ) ;
if ( F_141 ( V_265 ) )
break;
if ( V_231 && F_166 ( V_319 , V_317 + V_231 ) )
break;
}
}
exit:
if ( V_21 >= V_22 )
F_9 ( L_80 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
}
static void F_167 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
if ( V_21 >= V_22 )
F_9 ( L_81 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_82 ) )
return;
F_115 ( V_10 ) ;
F_92 ( V_1 , V_10 ) ;
F_168 ( & V_1 -> V_27 ) ;
}
static int F_169 ( struct V_113 * V_27 )
{
T_1 * V_1 = F_44 ( V_27 , T_1 , V_27 ) ;
unsigned long V_12 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_59 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
if ( V_1 -> V_138 & V_161 )
return 1 ;
return 0 ;
}
static void F_170 ( struct V_113 * V_27 , int V_320 )
{
T_1 * V_1 = F_44 ( V_27 , T_1 , V_27 ) ;
unsigned long V_12 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_320 )
V_1 -> V_138 |= V_139 | V_210 ;
else
V_1 -> V_138 &= ~ ( V_139 | V_210 ) ;
F_60 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
static int F_171 ( struct V_9 * V_10 , struct V_315 * V_316 )
{
T_1 * V_1 ;
struct V_113 * V_27 ;
int V_205 , line ;
unsigned long V_12 ;
line = V_10 -> V_321 ;
if ( line >= V_322 ) {
F_9 ( L_83 ,
__FILE__ , __LINE__ , line ) ;
return - V_63 ;
}
V_1 = V_323 ;
while( V_1 && V_1 -> line != line )
V_1 = V_1 -> V_324 ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_84 ) )
return - V_63 ;
V_27 = & V_1 -> V_27 ;
V_10 -> V_75 = V_1 ;
F_163 ( V_27 , V_10 ) ;
if ( V_21 >= V_22 )
F_9 ( L_85 ,
__FILE__ , __LINE__ , V_10 -> V_313 -> V_66 , V_27 -> V_13 ) ;
V_27 -> V_325 = ( V_27 -> V_12 & V_326 ) ? 1 : 0 ;
F_38 ( & V_1 -> V_38 , V_12 ) ;
if ( V_1 -> V_141 ) {
V_205 = - V_327 ;
F_40 ( & V_1 -> V_38 , V_12 ) ;
goto V_235;
}
F_76 ( & V_27 -> V_37 ) ;
V_27 -> V_13 ++ ;
F_79 ( & V_27 -> V_37 ) ;
F_40 ( & V_1 -> V_38 , V_12 ) ;
if ( V_27 -> V_13 == 1 ) {
V_205 = F_80 ( V_1 , V_10 ) ;
if ( V_205 < 0 )
goto V_235;
}
V_205 = F_172 ( & V_1 -> V_27 , V_10 , V_316 ) ;
if ( V_205 ) {
if ( V_21 >= V_22 )
F_9 ( L_86 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_205 ) ;
goto V_235;
}
if ( V_21 >= V_22 )
F_9 ( L_87 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
V_205 = 0 ;
V_235:
return V_205 ;
}
static inline void F_173 ( struct V_328 * V_329 , T_1 * V_1 )
{
char V_330 [ 30 ] ;
unsigned long V_12 ;
F_174 ( V_329 , L_88 ,
V_1 -> V_76 , V_1 -> V_58 , V_1 -> V_61 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_59 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
V_330 [ 0 ] = 0 ;
V_330 [ 1 ] = 0 ;
if ( V_1 -> V_138 & V_139 )
strcat ( V_330 , L_89 ) ;
if ( V_1 -> V_138 & V_155 )
strcat ( V_330 , L_90 ) ;
if ( V_1 -> V_138 & V_210 )
strcat ( V_330 , L_91 ) ;
if ( V_1 -> V_138 & V_168 )
strcat ( V_330 , L_92 ) ;
if ( V_1 -> V_138 & V_161 )
strcat ( V_330 , L_93 ) ;
if ( V_1 -> V_138 & V_173 )
strcat ( V_330 , L_94 ) ;
if ( V_1 -> V_39 . V_131 == V_145 ) {
F_174 ( V_329 , L_95 ,
V_1 -> V_106 . V_202 , V_1 -> V_106 . V_331 ) ;
if ( V_1 -> V_106 . V_200 )
F_174 ( V_329 , L_96 , V_1 -> V_106 . V_200 ) ;
if ( V_1 -> V_106 . V_199 )
F_174 ( V_329 , L_97 , V_1 -> V_106 . V_199 ) ;
if ( V_1 -> V_106 . V_332 )
F_174 ( V_329 , L_98 , V_1 -> V_106 . V_332 ) ;
if ( V_1 -> V_106 . V_333 )
F_174 ( V_329 , L_99 , V_1 -> V_106 . V_333 ) ;
if ( V_1 -> V_106 . V_334 )
F_174 ( V_329 , L_100 , V_1 -> V_106 . V_334 ) ;
if ( V_1 -> V_106 . V_335 )
F_174 ( V_329 , L_101 , V_1 -> V_106 . V_335 ) ;
} else {
F_174 ( V_329 , L_102 ,
V_1 -> V_106 . V_294 , V_1 -> V_106 . V_117 ) ;
if ( V_1 -> V_106 . V_122 )
F_174 ( V_329 , L_103 , V_1 -> V_106 . V_122 ) ;
if ( V_1 -> V_106 . V_121 )
F_174 ( V_329 , L_104 , V_1 -> V_106 . V_121 ) ;
if ( V_1 -> V_106 . V_127 )
F_174 ( V_329 , L_105 , V_1 -> V_106 . V_127 ) ;
if ( V_1 -> V_106 . V_128 )
F_174 ( V_329 , L_106 , V_1 -> V_106 . V_128 ) ;
}
F_174 ( V_329 , L_107 , V_330 + 1 ) ;
F_174 ( V_329 , L_108 ,
V_1 -> V_129 , V_1 -> V_84 , V_1 -> V_83 ,
V_1 -> V_79 ) ;
}
static int F_175 ( struct V_328 * V_329 , void * V_336 )
{
T_1 * V_1 ;
F_174 ( V_329 , L_109 , V_337 ) ;
V_1 = V_323 ;
while ( V_1 ) {
F_173 ( V_329 , V_1 ) ;
V_1 = V_1 -> V_324 ;
}
return 0 ;
}
static int F_176 ( struct V_338 * V_338 , struct V_315 * V_315 )
{
return F_177 ( V_315 , F_175 , NULL ) ;
}
static int F_178 ( T_1 * V_1 )
{
V_1 -> V_99 = sizeof( T_3 ) + V_1 -> V_31 ;
V_1 -> V_339 = V_1 -> V_99 * 8 ;
if ( V_1 -> V_339 > 0x10000 )
V_1 -> V_339 = 0x10000 ;
V_1 -> V_103 = V_1 -> V_339 / V_1 -> V_99 ;
V_1 -> V_97 = F_179 ( V_1 -> V_339 , V_23 ) ;
if ( V_1 -> V_97 == NULL )
return - V_24 ;
V_1 -> V_340 = F_10 ( V_1 -> V_31 , V_23 ) ;
if ( ! V_1 -> V_340 ) {
F_19 ( V_1 -> V_97 ) ;
V_1 -> V_97 = NULL ;
return - V_24 ;
}
F_180 ( V_1 ) ;
return 0 ;
}
static void F_181 ( T_1 * V_1 )
{
F_19 ( V_1 -> V_97 ) ;
V_1 -> V_97 = NULL ;
F_19 ( V_1 -> V_340 ) ;
V_1 -> V_340 = NULL ;
}
static int F_84 ( T_1 * V_1 )
{
if ( F_178 ( V_1 ) < 0 ) {
F_9 ( L_110 , V_1 -> V_76 ) ;
F_88 ( V_1 ) ;
return - V_63 ;
}
return 0 ;
}
static void F_88 ( T_1 * V_1 )
{
if ( V_21 >= V_22 )
F_9 ( L_111 , V_1 -> V_76 ) ;
F_181 ( V_1 ) ;
}
static int F_16 ( T_1 * V_1 )
{
T_1 * V_341 = NULL ;
struct V_342 * V_343 ;
int V_20 ;
V_1 -> V_324 = NULL ;
V_1 -> line = V_322 ;
sprintf ( V_1 -> V_76 , L_112 , V_1 -> line ) ;
if ( V_1 -> line < V_344 ) {
if ( V_345 [ V_1 -> line ] )
V_1 -> V_31 = V_345 [ V_1 -> line ] ;
}
V_322 ++ ;
if ( ! V_323 )
V_323 = V_1 ;
else {
V_341 = V_323 ;
while ( V_341 -> V_324 )
V_341 = V_341 -> V_324 ;
V_341 -> V_324 = V_1 ;
}
if ( V_1 -> V_31 < 4096 )
V_1 -> V_31 = 4096 ;
else if ( V_1 -> V_31 > 65535 )
V_1 -> V_31 = 65535 ;
F_9 ( L_113 ,
V_1 -> V_76 , V_1 -> V_58 , V_1 -> V_61 ) ;
#if V_140
V_20 = F_182 ( V_1 ) ;
if ( V_20 != 0 )
goto V_47;
#endif
V_343 = F_183 ( & V_1 -> V_27 , V_346 , V_1 -> line ,
& V_1 -> V_45 -> V_347 ) ;
if ( F_184 ( V_343 ) ) {
V_20 = F_185 ( V_343 ) ;
#if V_140
F_186 ( V_1 ) ;
#endif
goto V_47;
}
return 0 ;
V_47:
if ( V_341 )
V_341 -> V_324 = NULL ;
else
V_323 = NULL ;
V_322 -- ;
return V_20 ;
}
static void F_27 ( T_1 * V_348 )
{
T_1 * V_1 = V_323 ;
T_1 * V_349 = NULL ;
while( V_1 ) {
if ( V_1 == V_348 ) {
if ( V_349 )
V_349 -> V_324 = V_1 -> V_324 ;
else
V_323 = V_1 -> V_324 ;
F_187 ( V_346 , V_1 -> line ) ;
#if V_140
F_186 ( V_1 ) ;
#endif
F_88 ( V_1 ) ;
F_18 ( & V_1 -> V_27 ) ;
F_19 ( V_1 ) ;
V_322 -- ;
return;
}
V_349 = V_1 ;
V_1 = V_1 -> V_324 ;
}
}
static int T_6 F_188 ( void )
{
int V_78 ;
if ( V_350 ) {
F_4 () ;
F_189 () ;
}
V_346 = F_190 ( V_344 ,
V_351 |
V_352 ) ;
if ( F_184 ( V_346 ) ) {
V_78 = F_185 ( V_346 ) ;
goto V_241;
}
V_346 -> V_353 = L_114 ;
V_346 -> V_66 = L_115 ;
V_346 -> V_354 = V_355 ;
V_346 -> V_356 = 64 ;
V_346 -> type = V_357 ;
V_346 -> V_358 = V_359 ;
V_346 -> V_360 = V_361 ;
V_346 -> V_360 . V_214 =
V_362 | V_221 | V_363 | V_364 | V_233 ;
F_191 ( V_346 , & V_365 ) ;
V_78 = F_192 ( V_346 ) ;
if ( V_78 < 0 ) {
F_9 ( V_206 L_116 ,
__FILE__ , __LINE__ ) ;
goto V_366;
}
V_78 = F_193 ( & V_367 ) ;
if ( V_78 < 0 )
goto V_368;
F_9 ( V_369 L_117 , V_353 , V_337 ,
V_346 -> V_354 ) ;
return 0 ;
V_368:
F_194 ( V_346 ) ;
V_366:
F_195 ( V_346 ) ;
V_241:
return V_78 ;
}
static void T_7 F_196 ( void )
{
F_197 ( & V_367 ) ;
F_194 ( V_346 ) ;
F_195 ( V_346 ) ;
}
static void F_198 ( T_1 * V_1 , unsigned char V_2 , unsigned int V_370 )
{
unsigned int V_371 , V_372 ;
unsigned char V_247 ;
if ( V_370 ) {
V_372 = 3686400 / V_370 ;
if ( ! V_372 )
V_372 = 1 ;
V_372 >>= 1 ;
for ( V_371 = 1 ; V_372 > 64 && V_371 < 16 ; V_371 ++ )
V_372 >>= 1 ;
V_372 -- ;
F_36 ( V_1 , ( unsigned char ) ( V_2 + V_373 ) ,
( unsigned char ) ( ( V_371 << 6 ) + V_372 ) ) ;
V_247 = F_33 ( V_1 , ( unsigned char ) ( V_2 + V_374 ) ) & 0x3f ;
V_247 |= ( ( V_371 << 4 ) & 0xc0 ) ;
F_36 ( V_1 , ( unsigned char ) ( V_2 + V_374 ) , V_247 ) ;
}
}
static void F_199 ( T_1 * V_1 )
{
unsigned char V_247 ;
V_247 = 0x82 ;
if ( V_1 -> V_39 . V_131 == V_145 && V_1 -> V_39 . V_375 )
V_247 |= V_72 ;
F_36 ( V_1 , V_8 + V_376 , V_247 ) ;
F_36 ( V_1 , V_8 + V_377 , 0xc0 ) ;
F_36 ( V_1 , V_8 + V_378 , 0x17 ) ;
if ( V_1 -> V_39 . V_131 == V_145 && V_1 -> V_39 . V_375 )
F_36 ( V_1 , V_8 + V_374 , 0x38 ) ;
else
F_36 ( V_1 , V_8 + V_374 , 0x30 ) ;
F_36 ( V_1 , V_8 + V_379 , 0x50 ) ;
if ( V_1 -> V_39 . V_131 == V_145 && V_1 -> V_39 . V_375 )
F_198 ( V_1 , V_8 , V_1 -> V_39 . V_375 ) ;
else
F_198 ( V_1 , V_8 , 921600 ) ;
}
static void F_200 ( T_1 * V_1 )
{
unsigned char V_247 ;
V_247 = F_33 ( V_1 , V_4 + V_378 ) | ( V_72 | V_184 | V_185 ) ;
F_36 ( V_1 , V_4 + V_378 , V_247 ) ;
V_247 = F_33 ( V_1 , V_4 + V_374 ) | ( V_380 | V_116 ) ;
F_36 ( V_1 , V_4 + V_374 , V_247 ) ;
if ( V_1 -> V_39 . V_375 )
F_198 ( V_1 , V_4 , V_1 -> V_39 . V_375 ) ;
else
F_198 ( V_1 , V_4 , 1843200 ) ;
V_247 = F_33 ( V_1 , V_4 + V_376 ) | V_185 ;
F_36 ( V_1 , V_4 + V_376 , V_247 ) ;
}
static void F_99 ( T_1 * V_1 )
{
unsigned char V_247 ;
unsigned char V_381 , V_382 ;
F_1 ( V_1 , V_4 , 0xffff ) ;
F_1 ( V_1 , V_8 , 0xffff ) ;
F_74 ( V_1 , 0xff ) ;
V_381 = V_382 = 0 ;
if ( V_1 -> V_39 . V_12 & V_383
&& V_1 -> V_39 . V_12 & V_384 ) {
V_381 = 7 ;
} else if ( V_1 -> V_39 . V_12 & V_385
&& V_1 -> V_39 . V_12 & V_386 ) {
V_381 = 7 ;
V_382 = 1 ;
} else if ( V_1 -> V_39 . V_12 & V_383 ) {
if ( V_1 -> V_39 . V_12 & V_386 ) {
V_381 = 6 ;
V_382 = 1 ;
} else {
V_381 = 6 ;
}
} else if ( V_1 -> V_39 . V_12 & V_386 ) {
V_382 = 1 ;
}
V_247 = 0x82 ;
if ( V_1 -> V_39 . V_387 )
V_247 |= V_185 ;
if ( V_1 -> V_138 & V_139 )
V_247 |= V_72 ;
F_36 ( V_1 , V_4 + V_376 , V_247 ) ;
V_247 = 0xc0 ;
switch ( V_1 -> V_39 . V_388 )
{
case V_389 :
V_247 |= V_187 ;
break;
case V_390 :
V_247 |= V_380 ;
break;
case V_391 :
V_247 |= V_380 | V_72 ;
break;
case V_392 :
V_247 |= V_380 | V_187 ;
break;
}
F_36 ( V_1 , V_4 + V_377 , V_247 ) ;
V_247 = 0x10 + V_381 ;
F_36 ( V_1 , V_4 + V_378 , V_247 ) ;
V_247 = 0x00 ;
if ( V_381 == 2 || V_381 == 3 || V_381 == 6
|| V_381 == 7 || ( V_381 == 0 && V_382 == 1 ) )
V_247 |= V_116 ;
if ( V_382 )
V_247 |= V_380 ;
if ( V_1 -> V_39 . V_393 == V_394 )
V_247 |= V_184 ;
if ( V_1 -> V_39 . V_388 == V_395 )
V_247 |= V_185 ;
F_36 ( V_1 , V_4 + V_374 , V_247 ) ;
V_247 = 0x00 ;
if ( V_1 -> V_39 . V_393 == V_396 )
V_247 |= V_72 | V_184 ;
if ( V_1 -> V_39 . V_397 != V_398 )
V_247 |= V_116 ;
switch ( V_1 -> V_39 . V_399 )
{
case V_400 :
V_247 |= V_120 ;
break;
case V_401 :
V_247 |= V_120 ;
break;
case V_402 :
V_247 |= V_119 | V_120 ;
break;
}
F_36 ( V_1 , V_4 + V_403 , V_247 ) ;
V_247 = 0 ;
switch ( V_1 -> V_39 . V_397 )
{
case V_404 : V_247 = 0x7e ; break;
case V_405 : V_247 = 0xaa ; break;
case V_406 : V_247 = 0x55 ; break;
case V_407 : V_247 = 0xff ; break;
}
F_36 ( V_1 , V_4 + V_408 , V_247 ) ;
V_247 = 0x50 ;
F_36 ( V_1 , V_4 + V_379 , V_247 ) ;
if ( V_1 -> V_39 . V_12 & V_383 )
F_198 ( V_1 , V_4 , V_1 -> V_39 . V_375 * 16 ) ;
else
F_198 ( V_1 , V_4 , V_1 -> V_39 . V_375 ) ;
F_36 ( V_1 , V_4 + V_409 , 0 ) ;
V_247 = 0x00 ;
if ( V_1 -> V_39 . V_12 & V_410 )
V_247 |= V_116 ;
F_36 ( V_1 , V_4 + V_411 , V_247 ) ;
F_199 ( V_1 ) ;
if ( V_1 -> V_39 . V_387 || V_1 -> V_412 )
F_200 ( V_1 ) ;
if ( V_1 -> V_39 . V_12 & V_413 )
{
F_3 ( V_1 , V_8 , V_153 ) ;
F_149 ( V_1 , V_4 + V_248 , V_187 ) ;
} else
F_150 ( V_1 , V_4 + V_248 , V_187 ) ;
F_3 ( V_1 , V_4 ,
V_196 | V_197 | V_201 |
V_198 | V_203 ) ;
F_35 ( V_1 , V_4 , V_414 + V_104 ) ;
F_32 ( V_1 , V_4 ) ;
F_52 ( V_1 , V_4 + V_186 ) ;
if ( ! V_1 -> V_412 )
F_150 ( V_1 , V_4 + V_377 , V_120 ) ;
F_130 ( V_1 ) ;
F_39 ( V_1 ) ;
F_95 ( V_1 ) ;
}
static void F_95 ( T_1 * V_1 )
{
if ( V_21 >= V_100 )
F_9 ( L_118 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
F_150 ( V_1 , V_4 + V_376 , V_187 ) ;
V_1 -> V_101 = false ;
V_1 -> V_105 = false ;
}
static void F_103 ( T_1 * V_1 )
{
if ( V_21 >= V_100 )
F_9 ( L_119 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
F_180 ( V_1 ) ;
V_1 -> V_101 = false ;
V_1 -> V_105 = false ;
F_149 ( V_1 , V_4 + V_376 , V_187 ) ;
V_1 -> V_101 = true ;
}
static void F_42 ( T_1 * V_1 , struct V_9 * V_10 )
{
if ( V_21 >= V_100 )
F_9 ( L_120 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( V_1 -> V_133 ) {
V_1 -> V_137 = false ;
if ( V_1 -> V_39 . V_12 & V_415 ) {
F_59 ( V_1 ) ;
if ( ! ( V_1 -> V_138 & V_139 ) ) {
V_1 -> V_138 |= V_139 ;
F_60 ( V_1 ) ;
V_1 -> V_137 = true ;
}
}
if ( V_1 -> V_39 . V_131 == V_132 ) {
if ( ! V_1 -> V_129 ) {
V_1 -> V_129 = true ;
F_62 ( V_1 , V_10 ) ;
}
} else {
V_1 -> V_129 = true ;
F_62 ( V_1 , V_10 ) ;
F_201 ( & V_1 -> V_136 , V_319 +
F_202 ( 5000 ) ) ;
}
}
if ( ! V_1 -> V_77 )
V_1 -> V_77 = true ;
}
static void F_39 ( T_1 * V_1 )
{
if ( V_21 >= V_100 )
F_9 ( L_121 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
F_58 ( & V_1 -> V_136 ) ;
V_1 -> V_77 = false ;
V_1 -> V_129 = false ;
}
static void F_96 ( T_1 * V_1 )
{
F_36 ( V_1 , V_4 + V_377 , 0x80 ) ;
F_36 ( V_1 , V_8 + V_377 , 0x80 ) ;
F_36 ( V_1 , V_4 + V_376 , 0 ) ;
F_36 ( V_1 , V_8 + V_376 , 0 ) ;
F_1 ( V_1 , V_4 , 0xffff ) ;
F_1 ( V_1 , V_8 , 0xffff ) ;
F_74 ( V_1 , 0xff ) ;
F_36 ( V_1 , V_416 , 0x06 ) ;
F_36 ( V_1 , V_417 , 0x05 ) ;
}
static void F_100 ( T_1 * V_1 )
{
unsigned char V_247 ;
F_1 ( V_1 , V_4 , 0xffff ) ;
F_1 ( V_1 , V_8 , 0xffff ) ;
F_74 ( V_1 , 0xff ) ;
V_247 = 0x06 ;
if ( V_1 -> V_39 . V_387 )
V_247 |= V_185 ;
if ( ! ( V_1 -> V_138 & V_139 ) )
V_247 |= V_120 ;
F_36 ( V_1 , V_4 + V_376 , V_247 ) ;
F_36 ( V_1 , V_4 + V_377 , 0x83 ) ;
F_36 ( V_1 , V_4 + V_378 , 0x1f ) ;
F_36 ( V_1 , V_4 + V_374 , 0x10 ) ;
F_36 ( V_1 , V_4 + V_403 , 0 ) ;
F_36 ( V_1 , V_4 + V_379 , 0x50 ) ;
F_198 ( V_1 , V_4 , V_1 -> V_39 . V_230 * 16 ) ;
V_247 = 0x00 ;
if ( V_1 -> V_39 . V_218 != 8 )
V_247 |= V_185 ;
if ( V_1 -> V_39 . V_223 != 1 )
V_247 |= V_116 ;
if ( V_1 -> V_39 . V_121 != V_224 )
{
V_247 |= V_72 ;
if ( V_1 -> V_39 . V_121 == V_227 )
V_247 |= V_187 ;
else
V_247 |= V_380 ;
}
F_36 ( V_1 , V_4 + V_292 , V_247 ) ;
F_36 ( V_1 , V_4 + V_418 , 0x5c ) ;
F_36 ( V_1 , V_4 + V_409 , 0 ) ;
V_247 = 0x00 ;
if ( V_1 -> V_39 . V_12 & V_410 )
V_247 |= V_116 ;
F_36 ( V_1 , V_4 + V_411 , V_247 ) ;
if ( V_1 -> V_39 . V_12 & V_413 )
F_3 ( V_1 , V_4 , V_153 ) ;
F_149 ( V_1 , V_4 + V_376 , V_187 ) ;
F_199 ( V_1 ) ;
if ( V_1 -> V_39 . V_12 & V_413 ) {
F_3 ( V_1 , V_8 , V_153 ) ;
F_149 ( V_1 , V_4 + V_248 , V_187 ) ;
} else
F_150 ( V_1 , V_4 + V_248 , V_187 ) ;
F_3 ( V_1 , V_4 ,
V_196 | V_197 | V_192 | V_194 |
V_201 | V_203 ) ;
F_35 ( V_1 , V_4 , V_414 + V_104 ) ;
F_32 ( V_1 , V_4 ) ;
F_52 ( V_1 , V_4 + V_186 ) ;
}
static void F_130 ( T_1 * V_1 )
{
if ( V_1 -> V_42 == V_43 )
F_149 ( V_1 , V_4 + V_378 , V_187 ) ;
else
F_150 ( V_1 , V_4 + V_378 , V_187 ) ;
}
static void F_59 ( T_1 * V_1 )
{
unsigned char V_110 = 0 ;
V_1 -> V_138 &= V_139 | V_210 ;
if ( F_33 ( V_1 , V_8 + V_419 ) & V_119 )
V_1 -> V_138 |= V_161 ;
if ( F_33 ( V_1 , V_8 + V_71 ) & V_184 )
V_1 -> V_138 |= V_155 ;
V_110 = F_33 ( V_1 , V_4 + V_248 ) ;
if ( ! ( V_110 & V_171 ) )
V_1 -> V_138 |= V_173 ;
if ( ! ( V_110 & V_166 ) )
V_1 -> V_138 |= V_168 ;
}
static void F_60 ( T_1 * V_1 )
{
unsigned char V_247 ;
V_247 = F_33 ( V_1 , V_4 + V_376 ) ;
if ( V_1 -> V_39 . V_131 == V_132 ) {
if ( V_1 -> V_138 & V_139 )
V_247 &= ~ V_120 ;
else
V_247 |= V_120 ;
} else {
if ( V_1 -> V_138 & V_139 )
V_247 |= V_72 ;
else
V_247 &= ~ V_72 ;
}
F_36 ( V_1 , V_4 + V_376 , V_247 ) ;
if ( V_1 -> V_138 & V_210 )
F_150 ( V_1 , V_4 + V_248 , V_420 ) ;
else
F_149 ( V_1 , V_4 + V_248 , V_420 ) ;
}
static void F_180 ( T_1 * V_1 )
{
T_3 * V_96 ;
int V_70 ;
V_1 -> V_98 = 0 ;
V_1 -> V_421 = 0 ;
V_1 -> V_102 = 0 ;
for ( V_70 = 0 ; V_70 < V_1 -> V_103 ; V_70 ++ ) {
V_96 = ( T_3 * ) ( V_1 -> V_97 + ( V_70 * V_1 -> V_99 ) ) ;
V_96 -> V_110 = V_96 -> V_13 = 0 ;
}
}
static bool F_46 ( T_1 * V_1 , struct V_9 * V_10 )
{
unsigned short V_110 ;
T_3 * V_96 ;
unsigned int V_422 = 0 ;
unsigned long V_12 ;
bool V_423 = false ;
if ( V_1 -> V_102 == 0 )
return false ;
V_96 = ( T_3 * ) ( V_1 -> V_97 + ( V_1 -> V_421 * V_1 -> V_99 ) ) ;
V_110 = V_96 -> V_110 ;
if ( ( V_110 & 0xf0 ) != 0xA0 ) {
if ( ! ( V_110 & V_119 ) || ( V_110 & V_380 ) )
V_1 -> V_106 . V_424 ++ ;
else if ( V_110 & V_120 )
V_1 -> V_106 . V_334 ++ ;
else if ( ! ( V_110 & V_116 ) ) {
V_1 -> V_106 . V_335 ++ ;
if ( V_1 -> V_39 . V_393 & V_425 )
V_423 = true ;
}
V_422 = 0 ;
#if V_140
{
V_1 -> V_164 -> V_426 . V_427 ++ ;
V_1 -> V_164 -> V_426 . V_428 ++ ;
}
#endif
} else
V_423 = true ;
if ( V_423 )
V_422 = V_96 -> V_13 ;
if ( V_21 >= V_88 )
F_9 ( L_122 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_110 , V_422 ) ;
if ( V_21 >= V_429 )
F_203 ( V_1 , V_96 -> V_11 , V_422 , 0 ) ;
if ( V_422 ) {
if ( ( V_1 -> V_39 . V_393 & V_425 &&
V_422 + 1 > V_1 -> V_31 ) ||
V_422 > V_1 -> V_31 )
V_1 -> V_106 . V_333 ++ ;
else {
if ( V_110 & V_116 )
V_1 -> V_106 . V_331 ++ ;
if ( V_1 -> V_39 . V_393 & V_425 ) {
* ( V_96 -> V_11 + V_422 ) = V_110 & V_116 ? V_430 : V_431 ;
++ V_422 ;
}
#if V_140
if ( V_1 -> V_141 )
F_204 ( V_1 , V_96 -> V_11 , V_422 ) ;
else
#endif
F_5 ( V_10 , V_96 -> V_11 , V_1 -> V_340 , V_422 ) ;
}
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_96 -> V_110 = V_96 -> V_13 = 0 ;
V_1 -> V_102 -- ;
V_1 -> V_421 ++ ;
if ( V_1 -> V_421 >= V_1 -> V_103 )
V_1 -> V_421 = 0 ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
return true ;
}
static bool F_205 ( T_1 * V_1 )
{
static unsigned char V_432 [] =
{ 0x00 , 0xff , 0xaa , 0x55 , 0x69 , 0x96 , 0x0f } ;
static unsigned int V_13 = F_206 ( V_432 ) ;
unsigned int V_70 ;
bool V_78 = true ;
unsigned long V_12 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_96 ( V_1 ) ;
for ( V_70 = 0 ; V_70 < V_13 ; V_70 ++ ) {
F_36 ( V_1 , V_433 , V_432 [ V_70 ] ) ;
F_36 ( V_1 , V_434 , V_432 [ ( V_70 + 1 ) % V_13 ] ) ;
if ( ( F_33 ( V_1 , V_433 ) != V_432 [ V_70 ] ) ||
( F_33 ( V_1 , V_434 ) != V_432 [ ( V_70 + 1 ) % V_13 ] ) ) {
V_78 = false ;
break;
}
}
F_40 ( & V_1 -> V_37 , V_12 ) ;
return V_78 ;
}
static bool F_207 ( T_1 * V_1 )
{
unsigned long V_435 ;
unsigned long V_12 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_96 ( V_1 ) ;
V_1 -> V_412 = true ;
F_99 ( V_1 ) ;
V_1 -> V_189 = false ;
F_3 ( V_1 , V_4 , V_188 ) ;
F_36 ( V_1 , V_4 + V_436 , 0 ) ;
F_35 ( V_1 , V_4 , V_437 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
V_435 = 100 ;
while( V_435 -- && ! V_1 -> V_189 ) {
F_164 ( 10 ) ;
}
V_1 -> V_412 = false ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_96 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
return V_1 -> V_189 ;
}
static int F_85 ( T_1 * V_1 )
{
if ( ! F_205 ( V_1 ) ) {
V_1 -> V_438 = V_439 ;
F_9 ( L_123 ,
__FILE__ , __LINE__ , V_1 -> V_76 , ( unsigned short ) ( V_1 -> V_58 ) ) ;
return - V_63 ;
}
if ( ! F_207 ( V_1 ) ) {
V_1 -> V_438 = V_440 ;
F_9 ( L_124 ,
__FILE__ , __LINE__ , V_1 -> V_76 , ( unsigned short ) ( V_1 -> V_61 ) ) ;
return - V_63 ;
}
if ( V_21 >= V_22 )
F_9 ( L_125 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
return 0 ;
}
static void F_203 ( T_1 * V_1 , const char * V_11 , int V_13 , int V_441 )
{
int V_70 ;
int V_442 ;
if ( V_441 )
F_9 ( L_126 , V_1 -> V_76 ) ;
else
F_9 ( L_127 , V_1 -> V_76 ) ;
while( V_13 ) {
if ( V_13 > 16 )
V_442 = 16 ;
else
V_442 = V_13 ;
for( V_70 = 0 ; V_70 < V_442 ; V_70 ++ )
F_9 ( L_128 , ( unsigned char ) V_11 [ V_70 ] ) ;
for(; V_70 < 17 ; V_70 ++ )
F_9 ( L_129 ) ;
for( V_70 = 0 ; V_70 < V_442 ; V_70 ++ ) {
if ( V_11 [ V_70 ] >= 040 && V_11 [ V_70 ] <= 0176 )
F_9 ( L_130 , V_11 [ V_70 ] ) ;
else
F_9 ( L_131 ) ;
}
F_9 ( L_132 ) ;
V_11 += V_442 ;
V_13 -= V_442 ;
}
}
static void V_207 ( unsigned long V_443 )
{
T_1 * V_1 = ( T_1 * ) V_443 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_133 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( V_1 -> V_129 &&
V_1 -> V_39 . V_131 == V_145 ) {
V_1 -> V_106 . V_444 ++ ;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_129 = false ;
V_1 -> V_133 = V_1 -> V_134 = V_1 -> V_135 = 0 ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
#if V_140
if ( V_1 -> V_141 )
F_61 ( V_1 ) ;
else
#endif
{
struct V_9 * V_10 = F_45 ( & V_1 -> V_27 ) ;
F_47 ( V_1 , V_10 ) ;
F_49 ( V_10 ) ;
}
}
static int F_208 ( struct V_445 * V_347 , unsigned short V_388 ,
unsigned short V_121 )
{
T_1 * V_1 = F_209 ( V_347 ) ;
struct V_9 * V_10 ;
unsigned char V_446 ;
unsigned short V_447 ;
if ( V_1 -> V_27 . V_13 )
return - V_327 ;
switch ( V_388 )
{
case V_448 : V_446 = V_449 ; break;
case V_450 : V_446 = V_451 ; break;
case V_452 : V_446 = V_391 ; break;
case V_453 : V_446 = V_390 ; break;
case V_454 : V_446 = V_392 ; break;
default: return - V_291 ;
}
switch ( V_121 )
{
case V_455 : V_447 = V_396 ; break;
case V_456 : V_447 = V_457 ; break;
case V_458 : V_447 = V_394 ; break;
default: return - V_291 ;
}
V_1 -> V_39 . V_388 = V_446 ;
V_1 -> V_39 . V_393 = V_447 ;
if ( V_1 -> V_141 ) {
V_10 = F_45 ( & V_1 -> V_27 ) ;
F_98 ( V_1 , V_10 ) ;
F_49 ( V_10 ) ;
}
return 0 ;
}
static T_8 F_210 ( struct V_459 * V_460 ,
struct V_445 * V_347 )
{
T_1 * V_1 = F_209 ( V_347 ) ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( V_369 L_134 , __FILE__ , V_347 -> V_66 ) ;
F_211 ( V_347 ) ;
F_212 ( V_460 , V_1 -> V_148 , V_460 -> V_461 ) ;
V_1 -> V_135 = 0 ;
V_1 -> V_134 = V_1 -> V_133 = V_460 -> V_461 ;
V_347 -> V_426 . V_462 ++ ;
V_347 -> V_426 . V_463 += V_460 -> V_461 ;
F_213 ( V_460 ) ;
F_214 ( V_347 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( ! V_1 -> V_129 ) {
struct V_9 * V_10 = F_45 ( & V_1 -> V_27 ) ;
F_42 ( V_1 , V_10 ) ;
F_49 ( V_10 ) ;
}
F_40 ( & V_1 -> V_37 , V_12 ) ;
return V_464 ;
}
static int F_215 ( struct V_445 * V_347 )
{
T_1 * V_1 = F_209 ( V_347 ) ;
struct V_9 * V_10 ;
int V_78 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_135 , __FILE__ , V_347 -> V_66 ) ;
V_78 = F_216 ( V_347 ) ;
if ( V_78 != 0 )
return V_78 ;
F_38 ( & V_1 -> V_38 , V_12 ) ;
if ( V_1 -> V_27 . V_13 != 0 || V_1 -> V_141 != 0 ) {
F_9 ( V_465 L_136 , V_347 -> V_66 ) ;
F_40 ( & V_1 -> V_38 , V_12 ) ;
return - V_327 ;
}
V_1 -> V_141 = 1 ;
F_40 ( & V_1 -> V_38 , V_12 ) ;
V_10 = F_45 ( & V_1 -> V_27 ) ;
V_78 = F_80 ( V_1 , V_10 ) ;
if ( V_78 != 0 ) {
F_49 ( V_10 ) ;
F_38 ( & V_1 -> V_38 , V_12 ) ;
V_1 -> V_141 = 0 ;
F_40 ( & V_1 -> V_38 , V_12 ) ;
return V_78 ;
}
V_1 -> V_138 |= V_139 | V_210 ;
F_98 ( V_1 , V_10 ) ;
F_49 ( V_10 ) ;
F_214 ( V_347 ) ;
F_217 ( V_347 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_59 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
if ( V_1 -> V_138 & V_161 )
F_69 ( V_347 ) ;
else
F_70 ( V_347 ) ;
return 0 ;
}
static int F_218 ( struct V_445 * V_347 )
{
T_1 * V_1 = F_209 ( V_347 ) ;
struct V_9 * V_10 = F_45 ( & V_1 -> V_27 ) ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_137 , __FILE__ , V_347 -> V_66 ) ;
F_211 ( V_347 ) ;
F_92 ( V_1 , V_10 ) ;
F_49 ( V_10 ) ;
F_219 ( V_347 ) ;
F_38 ( & V_1 -> V_38 , V_12 ) ;
V_1 -> V_141 = 0 ;
F_40 ( & V_1 -> V_38 , V_12 ) ;
return 0 ;
}
static int F_220 ( struct V_445 * V_347 , struct V_466 * V_467 , int V_73 )
{
const T_9 V_468 = sizeof( V_469 ) ;
V_469 V_470 ;
V_469 T_5 * line = V_467 -> V_471 . V_472 . V_473 ;
T_1 * V_1 = F_209 ( V_347 ) ;
unsigned int V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_138 , __FILE__ , V_347 -> V_66 ) ;
if ( V_1 -> V_27 . V_13 )
return - V_327 ;
if ( V_73 != V_474 )
return F_221 ( V_347 , V_467 , V_73 ) ;
memset ( & V_470 , 0 , V_468 ) ;
switch( V_467 -> V_471 . type ) {
case V_475 :
V_467 -> V_471 . type = V_476 ;
if ( V_467 -> V_471 . V_468 < V_468 ) {
V_467 -> V_471 . V_468 = V_468 ;
return - V_477 ;
}
V_12 = V_1 -> V_39 . V_12 & ( V_478 | V_383 |
V_385 | V_479 |
V_480 | V_384 |
V_386 | V_481 ) ;
switch ( V_12 ) {
case ( V_478 | V_480 ) : V_470 . V_482 = V_483 ; break;
case ( V_385 | V_386 ) : V_470 . V_482 = V_484 ; break;
case ( V_478 | V_386 ) : V_470 . V_482 = V_485 ; break;
case ( V_478 | V_481 ) : V_470 . V_482 = V_486 ; break;
default: V_470 . V_482 = V_487 ;
}
V_470 . V_488 = V_1 -> V_39 . V_375 ;
V_470 . V_387 = V_1 -> V_39 . V_387 ? 1 : 0 ;
if ( F_222 ( line , & V_470 , V_468 ) )
return - V_242 ;
return 0 ;
case V_476 :
if( ! F_86 ( V_489 ) )
return - V_490 ;
if ( F_223 ( & V_470 , line , V_468 ) )
return - V_242 ;
switch ( V_470 . V_482 )
{
case V_483 : V_12 = V_478 | V_480 ; break;
case V_486 : V_12 = V_478 | V_481 ; break;
case V_484 : V_12 = V_385 | V_386 ; break;
case V_485 : V_12 = V_478 | V_386 ; break;
case V_487 : V_12 = V_1 -> V_39 . V_12 &
( V_478 | V_383 |
V_385 | V_479 |
V_480 | V_384 |
V_386 | V_481 ) ; break;
default: return - V_291 ;
}
if ( V_470 . V_387 != 0 && V_470 . V_387 != 1 )
return - V_291 ;
V_1 -> V_39 . V_12 &= ~ ( V_478 | V_383 |
V_385 | V_479 |
V_480 | V_384 |
V_386 | V_481 ) ;
V_1 -> V_39 . V_12 |= V_12 ;
V_1 -> V_39 . V_387 = V_470 . V_387 ;
if ( V_12 & ( V_385 | V_386 ) )
V_1 -> V_39 . V_375 = V_470 . V_488 ;
else
V_1 -> V_39 . V_375 = 0 ;
if ( V_1 -> V_141 ) {
struct V_9 * V_10 = F_45 ( & V_1 -> V_27 ) ;
F_98 ( V_1 , V_10 ) ;
F_49 ( V_10 ) ;
}
return 0 ;
default:
return F_221 ( V_347 , V_467 , V_73 ) ;
}
}
static void F_224 ( struct V_445 * V_347 )
{
T_1 * V_1 = F_209 ( V_347 ) ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_139 , V_347 -> V_66 ) ;
V_347 -> V_426 . V_491 ++ ;
V_347 -> V_426 . V_492 ++ ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_39 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
F_225 ( V_347 ) ;
}
static void F_61 ( T_1 * V_1 )
{
if ( F_226 ( V_1 -> V_164 ) )
F_225 ( V_1 -> V_164 ) ;
}
static void F_204 ( T_1 * V_1 , char * V_96 , int V_468 )
{
struct V_459 * V_460 = F_227 ( V_468 ) ;
struct V_445 * V_347 = V_1 -> V_164 ;
if ( V_21 >= V_22 )
F_9 ( L_140 , V_347 -> V_66 ) ;
if ( V_460 == NULL ) {
F_9 ( V_493 L_141 , V_347 -> V_66 ) ;
V_347 -> V_426 . V_494 ++ ;
return;
}
memcpy ( F_228 ( V_460 , V_468 ) , V_96 , V_468 ) ;
V_460 -> V_495 = F_229 ( V_460 , V_347 ) ;
V_347 -> V_426 . V_496 ++ ;
V_347 -> V_426 . V_497 += V_468 ;
F_230 ( V_460 ) ;
}
static int F_182 ( T_1 * V_1 )
{
int V_78 ;
struct V_445 * V_347 ;
T_10 * V_498 ;
V_347 = F_231 ( V_1 ) ;
if ( V_347 == NULL ) {
F_9 ( V_206 L_142 , __FILE__ ) ;
return - V_24 ;
}
V_347 -> V_499 = V_1 -> V_58 ;
V_347 -> V_62 = V_1 -> V_61 ;
V_347 -> V_500 = & V_501 ;
V_347 -> V_502 = 10 * V_33 ;
V_347 -> V_503 = 50 ;
V_498 = F_232 ( V_347 ) ;
V_498 -> V_504 = F_208 ;
V_498 -> V_441 = F_210 ;
V_78 = F_233 ( V_347 ) ;
if ( V_78 ) {
F_9 ( V_465 L_143 , __FILE__ ) ;
F_234 ( V_347 ) ;
return V_78 ;
}
V_1 -> V_164 = V_347 ;
return 0 ;
}
static void F_186 ( T_1 * V_1 )
{
F_235 ( V_1 -> V_164 ) ;
F_234 ( V_1 -> V_164 ) ;
V_1 -> V_164 = NULL ;
}
