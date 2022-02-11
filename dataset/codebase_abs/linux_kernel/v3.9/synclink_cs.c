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
if ( V_1 -> V_27 . V_12 & V_165 ) {
if ( V_21 >= V_100 )
F_9 ( L_23 , V_1 -> V_76 ,
( V_1 -> V_138 & V_161 ) ? L_24 : L_25 ) ;
if ( V_1 -> V_138 & V_161 )
F_66 ( & V_1 -> V_27 . V_166 ) ;
else {
if ( V_21 >= V_100 )
F_9 ( L_26 ) ;
if ( V_10 )
F_71 ( V_10 ) ;
}
}
V_1 -> V_79 |= V_82 ;
}
static void F_72 ( T_1 * V_1 )
{
F_59 ( V_1 ) ;
if ( ( V_1 -> V_90 ) ++ >= V_152 )
F_73 ( V_1 , V_167 ) ;
V_1 -> V_106 . V_168 ++ ;
if ( V_1 -> V_138 & V_169 )
V_1 -> V_156 . V_170 ++ ;
else
V_1 -> V_156 . V_171 ++ ;
F_66 ( & V_1 -> V_35 ) ;
F_66 ( & V_1 -> V_36 ) ;
V_1 -> V_79 |= V_82 ;
}
static void F_74 ( T_1 * V_1 )
{
F_59 ( V_1 ) ;
if ( ( V_1 -> V_89 ) ++ >= V_152 )
F_73 ( V_1 , V_172 ) ;
V_1 -> V_106 . V_173 ++ ;
if ( V_1 -> V_138 & V_174 )
V_1 -> V_156 . V_175 ++ ;
else
V_1 -> V_156 . V_176 ++ ;
F_66 ( & V_1 -> V_35 ) ;
F_66 ( & V_1 -> V_36 ) ;
V_1 -> V_79 |= V_82 ;
}
static T_4 V_57 ( int V_177 , void * V_178 )
{
T_1 * V_1 = V_178 ;
struct V_9 * V_10 ;
unsigned short V_179 ;
unsigned char V_180 , V_181 ;
int V_13 = 0 ;
if ( V_21 >= V_100 )
F_9 ( L_27 , V_1 -> V_61 ) ;
if ( ! ( V_1 -> V_45 -> V_182 ) )
return V_183 ;
V_10 = F_45 ( & V_1 -> V_27 ) ;
F_75 ( & V_1 -> V_37 ) ;
while ( ( V_180 = F_33 ( V_1 , V_4 + V_184 ) ) ) {
if ( V_21 >= V_100 )
F_9 ( L_28 , V_1 -> V_76 , V_180 ) ;
if ( ( V_180 & 0x70 ) || V_13 > 1000 ) {
F_9 ( L_29 ) ;
break;
}
V_13 ++ ;
if ( V_180 & ( V_185 + V_186 ) ) {
V_179 = F_52 ( V_1 , V_8 + V_187 ) ;
if ( V_179 & V_159 )
F_68 ( V_1 , V_10 ) ;
if ( V_179 & V_153 )
F_65 ( V_1 , V_10 ) ;
}
if ( V_180 & ( V_188 + V_72 ) )
{
V_179 = F_52 ( V_1 , V_4 + V_187 ) ;
if ( V_179 & V_189 ) {
V_1 -> V_190 = true ;
F_1 ( V_1 , V_4 , V_189 ) ;
}
if ( V_179 & V_191 ) {
V_1 -> V_106 . V_192 ++ ;
F_66 ( & V_1 -> V_36 ) ;
}
if ( V_179 & V_193 ) {
V_1 -> V_106 . V_127 ++ ;
if ( V_1 -> V_27 . V_12 & V_194 )
F_76 ( V_10 ) ;
}
if ( V_179 & V_195 ) {
F_35 ( V_1 , V_4 , V_196 ) ;
}
if ( V_179 & ( V_197 + V_198 ) ) {
if ( V_1 -> V_39 . V_131 == V_145 )
F_51 ( V_1 , V_179 & V_197 ) ;
else
F_53 ( V_1 , V_179 & V_197 ) ;
}
if ( V_179 & V_199 ) {
if ( V_1 -> V_130 )
V_1 -> V_106 . V_200 ++ ;
else
V_1 -> V_106 . V_201 ++ ;
F_57 ( V_1 , V_10 ) ;
}
else if ( V_179 & V_202 ) {
V_1 -> V_106 . V_203 ++ ;
F_57 ( V_1 , V_10 ) ;
}
else if ( V_179 & V_204 )
F_62 ( V_1 , V_10 ) ;
}
if ( V_180 & V_119 ) {
V_181 = F_33 ( V_1 , V_4 + V_205 ) ;
if ( V_181 & V_185 )
F_72 ( V_1 ) ;
if ( V_181 & V_72 )
F_74 ( V_1 ) ;
}
}
if ( V_1 -> V_79 && ! V_1 -> V_83 && ! V_1 -> V_84 ) {
if ( V_21 >= V_100 )
F_9 ( L_30 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
F_77 ( & V_1 -> V_29 ) ;
V_1 -> V_84 = true ;
}
F_78 ( & V_1 -> V_37 ) ;
F_49 ( V_10 ) ;
if ( V_21 >= V_100 )
F_9 ( L_31 ,
__FILE__ , __LINE__ , V_1 -> V_61 ) ;
return V_183 ;
}
static int F_79 ( T_1 * V_1 , struct V_9 * V_10 )
{
int V_206 = 0 ;
if ( V_21 >= V_22 )
F_9 ( L_32 , __FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( V_1 -> V_27 . V_12 & V_207 )
return 0 ;
if ( ! V_1 -> V_148 ) {
V_1 -> V_148 = ( unsigned char * ) F_80 ( V_23 ) ;
if ( ! V_1 -> V_148 ) {
F_9 ( V_208 L_33 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
return - V_24 ;
}
}
V_1 -> V_79 = 0 ;
memset ( & V_1 -> V_106 , 0 , sizeof( V_1 -> V_106 ) ) ;
F_81 ( & V_1 -> V_136 , V_209 , ( unsigned long ) V_1 ) ;
V_206 = F_82 ( V_1 ) ;
if ( ! V_206 )
V_206 = F_83 ( V_1 ) ;
if ( V_206 ) {
if ( F_84 ( V_210 ) && V_10 )
F_85 ( V_211 , & V_10 -> V_12 ) ;
F_86 ( V_1 ) ;
return V_206 ;
}
F_87 ( V_1 , V_10 ) ;
if ( V_10 )
F_88 ( V_211 , & V_10 -> V_12 ) ;
V_1 -> V_27 . V_12 |= V_207 ;
return 0 ;
}
static void F_89 ( T_1 * V_1 , struct V_9 * V_10 )
{
unsigned long V_12 ;
if ( ! ( V_1 -> V_27 . V_12 & V_207 ) )
return;
if ( V_21 >= V_22 )
F_9 ( L_34 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
F_66 ( & V_1 -> V_35 ) ;
F_66 ( & V_1 -> V_36 ) ;
F_90 ( & V_1 -> V_136 ) ;
if ( V_1 -> V_148 ) {
F_91 ( ( unsigned long ) V_1 -> V_148 ) ;
V_1 -> V_148 = NULL ;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_92 ( V_1 ) ;
F_39 ( V_1 ) ;
F_93 ( V_1 ) ;
if ( ! V_10 || V_10 -> V_212 . V_213 & V_214 ) {
V_1 -> V_138 &= ~ ( V_139 | V_215 ) ;
F_60 ( V_1 ) ;
}
F_40 ( & V_1 -> V_37 , V_12 ) ;
F_86 ( V_1 ) ;
if ( V_10 )
F_85 ( V_211 , & V_10 -> V_12 ) ;
V_1 -> V_27 . V_12 &= ~ V_207 ;
}
static void F_94 ( T_1 * V_1 , struct V_9 * V_10 )
{
unsigned long V_12 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_92 ( V_1 ) ;
F_39 ( V_1 ) ;
V_1 -> V_133 = V_1 -> V_134 = V_1 -> V_135 = 0 ;
if ( V_1 -> V_39 . V_131 == V_145 || V_1 -> V_141 )
F_95 ( V_1 ) ;
else
F_96 ( V_1 ) ;
F_60 ( V_1 ) ;
V_1 -> V_91 = 0 ;
V_1 -> V_92 = 0 ;
V_1 -> V_89 = 0 ;
V_1 -> V_90 = 0 ;
F_3 ( V_1 , V_8 , V_159 | V_153 ) ;
F_97 ( V_1 , ( unsigned char ) V_167 | V_172 ) ;
F_59 ( V_1 ) ;
if ( V_1 -> V_141 || ( V_10 && ( V_10 -> V_212 . V_213 & V_216 ) ) )
F_98 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
static void F_87 ( T_1 * V_1 , struct V_9 * V_10 )
{
unsigned V_217 ;
int V_218 ;
if ( ! V_10 )
return;
if ( V_21 >= V_22 )
F_9 ( L_35 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
V_217 = V_10 -> V_212 . V_213 ;
if ( V_217 & V_219 )
V_1 -> V_138 |= V_139 | V_215 ;
else
V_1 -> V_138 &= ~ ( V_139 | V_215 ) ;
switch ( V_217 & V_220 ) {
case V_221 : V_1 -> V_39 . V_222 = 5 ; break;
case V_223 : V_1 -> V_39 . V_222 = 6 ; break;
case V_224 : V_1 -> V_39 . V_222 = 7 ; break;
case V_225 : V_1 -> V_39 . V_222 = 8 ; break;
default: V_1 -> V_39 . V_222 = 7 ; break;
}
if ( V_217 & V_226 )
V_1 -> V_39 . V_227 = 2 ;
else
V_1 -> V_39 . V_227 = 1 ;
V_1 -> V_39 . V_121 = V_228 ;
if ( V_217 & V_229 ) {
if ( V_217 & V_230 )
V_1 -> V_39 . V_121 = V_231 ;
else
V_1 -> V_39 . V_121 = V_232 ;
#ifdef F_99
if ( V_217 & F_99 )
V_1 -> V_39 . V_121 = V_233 ;
#endif
}
V_218 = V_1 -> V_39 . V_222 +
V_1 -> V_39 . V_227 + 1 ;
if ( V_1 -> V_39 . V_234 <= 460800 ) {
V_1 -> V_39 . V_234 = F_100 ( V_10 ) ;
}
if ( V_1 -> V_39 . V_234 ) {
V_1 -> V_235 = ( 32 * V_33 * V_218 ) /
V_1 -> V_39 . V_234 ;
}
V_1 -> V_235 += V_33 / 50 ;
if ( V_217 & V_236 )
V_1 -> V_27 . V_12 |= V_237 ;
else
V_1 -> V_27 . V_12 &= ~ V_237 ;
if ( V_217 & V_238 )
V_1 -> V_27 . V_12 &= ~ V_165 ;
else
V_1 -> V_27 . V_12 |= V_165 ;
V_1 -> V_124 = 0 ;
if ( F_101 ( V_10 ) )
V_1 -> V_124 |= V_119 | V_120 ;
if ( F_102 ( V_10 ) )
V_1 -> V_123 |= V_119 | V_120 ;
F_94 ( V_1 , V_10 ) ;
}
static int F_103 ( struct V_9 * V_10 , unsigned char V_239 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 ) {
F_9 ( L_36 ,
__FILE__ , __LINE__ , V_239 , V_1 -> V_76 ) ;
}
if ( F_30 ( V_1 , V_10 -> V_66 , L_37 ) )
return 0 ;
if ( ! V_1 -> V_148 )
return 0 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_1 -> V_39 . V_131 == V_132 || ! V_1 -> V_129 ) {
if ( V_1 -> V_133 < V_146 - 1 ) {
V_1 -> V_148 [ V_1 -> V_134 ++ ] = V_239 ;
V_1 -> V_134 &= V_146 - 1 ;
V_1 -> V_133 ++ ;
}
}
F_40 ( & V_1 -> V_37 , V_12 ) ;
return 1 ;
}
static void F_104 ( struct V_9 * V_10 )
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
static int F_105 ( struct V_9 * V_10 ,
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
goto V_240;
if ( V_1 -> V_39 . V_131 == V_145 ) {
if ( V_13 > V_146 ) {
V_20 = - V_241 ;
goto V_240;
}
if ( V_1 -> V_129 )
goto V_240;
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
V_240:
if ( V_21 >= V_22 )
F_9 ( L_43 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_20 ) ;
return V_20 ;
}
static int F_106 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
int V_20 ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_44 ) )
return 0 ;
if ( V_1 -> V_39 . V_131 == V_145 ) {
if ( V_1 -> V_129 )
return 0 ;
else
return V_242 ;
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
static int F_107 ( struct V_9 * V_10 )
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
static void F_108 ( struct V_9 * V_10 )
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
F_66 ( & V_10 -> V_243 ) ;
F_50 ( V_10 ) ;
}
static void F_109 ( struct V_9 * V_10 , char V_239 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_51 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_239 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_52 ) )
return;
V_1 -> V_244 = V_239 ;
if ( V_239 ) {
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( ! V_1 -> V_77 )
F_42 ( V_1 , V_10 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
}
static void F_110 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_53 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_54 ) )
return;
if ( F_111 ( V_10 ) )
F_109 ( V_10 , F_112 ( V_10 ) ) ;
if ( V_10 -> V_212 . V_213 & V_236 ) {
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_138 &= ~ V_139 ;
F_60 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
}
static void F_113 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_55 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_56 ) )
return;
if ( F_111 ( V_10 ) ) {
if ( V_1 -> V_244 )
V_1 -> V_244 = 0 ;
else
F_109 ( V_10 , F_114 ( V_10 ) ) ;
}
if ( V_10 -> V_212 . V_213 & V_236 ) {
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_138 |= V_139 ;
F_60 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
}
static int F_115 ( T_1 * V_1 , struct V_115 T_5 * V_245 )
{
int V_246 ;
if ( V_21 >= V_22 )
F_9 ( L_57 , V_1 -> V_76 ) ;
if ( ! V_245 ) {
memset ( & V_1 -> V_106 , 0 , sizeof( V_1 -> V_106 ) ) ;
} else {
F_116 ( V_246 , V_245 , & V_1 -> V_106 , sizeof( struct V_115 ) ) ;
if ( V_246 )
return - V_247 ;
}
return 0 ;
}
static int F_117 ( T_1 * V_1 , V_41 T_5 * V_248 )
{
int V_246 ;
if ( V_21 >= V_22 )
F_9 ( L_57 , V_1 -> V_76 ) ;
F_116 ( V_246 , V_248 , & V_1 -> V_39 , sizeof( V_41 ) ) ;
if ( V_246 )
return - V_247 ;
return 0 ;
}
static int F_118 ( T_1 * V_1 , V_41 T_5 * V_249 , struct V_9 * V_10 )
{
unsigned long V_12 ;
V_41 V_250 ;
int V_246 ;
if ( V_21 >= V_22 )
F_9 ( L_58 , __FILE__ , __LINE__ ,
V_1 -> V_76 ) ;
F_119 ( V_246 , & V_250 , V_249 , sizeof( V_41 ) ) ;
if ( V_246 ) {
if ( V_21 >= V_22 )
F_9 ( L_59 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
return - V_247 ;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
memcpy ( & V_1 -> V_39 , & V_250 , sizeof( V_41 ) ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
F_87 ( V_1 , V_10 ) ;
return 0 ;
}
static int F_120 ( T_1 * V_1 , int T_5 * V_42 )
{
int V_246 ;
if ( V_21 >= V_22 )
F_9 ( L_60 , V_1 -> V_76 , V_1 -> V_42 ) ;
F_116 ( V_246 , V_42 , & V_1 -> V_42 , sizeof( int ) ) ;
if ( V_246 )
return - V_247 ;
return 0 ;
}
static int F_121 ( T_1 * V_1 , int V_42 )
{
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_61 , V_1 -> V_76 , V_42 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_42 = V_42 ;
F_122 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_123 ( T_1 * V_1 , int T_5 * V_251 )
{
int V_246 ;
if ( V_21 >= V_22 )
F_9 ( L_62 , V_1 -> V_76 , V_1 -> V_251 ) ;
F_116 ( V_246 , V_251 , & V_1 -> V_251 , sizeof( int ) ) ;
if ( V_246 )
return - V_247 ;
return 0 ;
}
static int F_124 ( T_1 * V_1 , int V_251 )
{
unsigned long V_12 ;
unsigned char V_252 ;
if ( V_21 >= V_22 )
F_9 ( L_63 , V_1 -> V_76 , V_251 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_1 -> V_251 = V_251 ;
V_252 = F_33 ( V_1 , V_253 ) & 0x0f ;
switch ( V_1 -> V_251 )
{
case V_254 : V_252 |= V_255 ; break;
case V_256 : V_252 |= V_257 ; break;
case V_258 : V_252 |= V_259 ; break;
}
F_36 ( V_1 , V_253 , V_252 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_125 ( T_1 * V_1 , int V_260 , struct V_9 * V_10 )
{
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_64 , V_1 -> V_76 , V_260 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_260 ) {
if ( ! V_1 -> V_77 )
F_42 ( V_1 , V_10 ) ;
} else {
if ( V_1 -> V_77 )
F_39 ( V_1 ) ;
}
F_40 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_126 ( T_1 * V_1 )
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
static int F_127 ( T_1 * V_1 , int V_260 )
{
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_66 , V_1 -> V_76 , V_260 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_260 ) {
if ( ! V_1 -> V_101 )
F_98 ( V_1 ) ;
} else {
if ( V_1 -> V_101 )
F_92 ( V_1 ) ;
}
F_40 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_128 ( T_1 * V_1 , int T_5 * V_261 )
{
unsigned long V_12 ;
int V_262 ;
int V_78 = 0 ;
struct V_115 V_263 , V_264 ;
int V_265 ;
int V_3 ;
struct V_266 V_267 , V_268 ;
F_129 ( V_269 , V_270 ) ;
F_119 ( V_78 , & V_3 , V_261 , sizeof( int ) ) ;
if ( V_78 )
return - V_247 ;
if ( V_21 >= V_22 )
F_9 ( L_67 , V_1 -> V_76 , V_3 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_59 ( V_1 ) ;
V_262 = V_1 -> V_138 ;
V_265 = V_3 &
( ( ( V_262 & V_169 ) ? V_271 : V_272 ) +
( ( V_262 & V_161 ) ? V_273 : V_274 ) +
( ( V_262 & V_155 ) ? V_275 : V_276 ) +
( ( V_262 & V_174 ) ? V_277 : V_278 ) ) ;
if ( V_265 ) {
F_40 ( & V_1 -> V_37 , V_12 ) ;
goto exit;
}
V_263 = V_1 -> V_106 ;
V_267 = V_1 -> V_156 ;
if ( ( V_1 -> V_39 . V_131 == V_145 ) &&
( V_3 & V_279 ) )
F_3 ( V_1 , V_4 , V_191 ) ;
F_130 ( V_280 ) ;
F_131 ( & V_1 -> V_36 , & V_269 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
for(; ; ) {
F_132 () ;
if ( F_133 ( V_270 ) ) {
V_78 = - V_281 ;
break;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_264 = V_1 -> V_106 ;
V_268 = V_1 -> V_156 ;
F_130 ( V_280 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
if ( V_268 . V_170 == V_267 . V_170 &&
V_268 . V_171 == V_267 . V_171 &&
V_268 . V_162 == V_267 . V_162 &&
V_268 . V_163 == V_267 . V_163 &&
V_268 . V_157 == V_267 . V_157 &&
V_268 . V_158 == V_267 . V_158 &&
V_268 . V_175 == V_267 . V_175 &&
V_268 . V_176 == V_267 . V_176 &&
V_264 . V_192 == V_263 . V_192 &&
V_264 . V_282 == V_263 . V_282 ) {
V_78 = - V_241 ;
break;
}
V_265 = V_3 &
( ( V_268 . V_170 != V_267 . V_170 ? V_271 : 0 ) +
( V_268 . V_171 != V_267 . V_171 ? V_272 : 0 ) +
( V_268 . V_162 != V_267 . V_162 ? V_273 : 0 ) +
( V_268 . V_163 != V_267 . V_163 ? V_274 : 0 ) +
( V_268 . V_157 != V_267 . V_157 ? V_275 : 0 ) +
( V_268 . V_158 != V_267 . V_158 ? V_276 : 0 ) +
( V_268 . V_175 != V_267 . V_175 ? V_277 : 0 ) +
( V_268 . V_176 != V_267 . V_176 ? V_278 : 0 ) +
( V_264 . V_192 != V_263 . V_192 ? V_279 : 0 ) +
( V_264 . V_282 != V_263 . V_282 ? V_283 : 0 ) ) ;
if ( V_265 )
break;
V_263 = V_264 ;
V_267 = V_268 ;
}
F_134 ( & V_1 -> V_36 , & V_269 ) ;
F_130 ( V_284 ) ;
if ( V_3 & V_279 ) {
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( ! F_135 ( & V_1 -> V_36 ) )
F_1 ( V_1 , V_4 , V_191 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
exit:
if ( V_78 == 0 )
F_136 ( V_78 , V_265 , V_261 ) ;
return V_78 ;
}
static int F_137 ( T_1 * V_1 , int V_64 )
{
unsigned long V_12 ;
int V_78 ;
struct V_115 V_263 , V_264 ;
F_129 ( V_269 , V_270 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_263 = V_1 -> V_106 ;
F_131 ( & V_1 -> V_35 , & V_269 ) ;
F_130 ( V_280 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
for(; ; ) {
F_132 () ;
if ( F_133 ( V_270 ) ) {
V_78 = - V_281 ;
break;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_264 = V_1 -> V_106 ;
F_130 ( V_280 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
if ( V_264 . V_173 == V_263 . V_173 && V_264 . V_168 == V_263 . V_168 &&
V_264 . V_160 == V_263 . V_160 && V_264 . V_154 == V_263 . V_154 ) {
V_78 = - V_241 ;
break;
}
if ( ( V_64 & V_285 && V_264 . V_173 != V_263 . V_173 ) ||
( V_64 & V_286 && V_264 . V_168 != V_263 . V_168 ) ||
( V_64 & V_287 && V_264 . V_160 != V_263 . V_160 ) ||
( V_64 & V_288 && V_264 . V_154 != V_263 . V_154 ) ) {
V_78 = 0 ;
break;
}
V_263 = V_264 ;
}
F_134 ( & V_1 -> V_35 , & V_269 ) ;
F_130 ( V_284 ) ;
return V_78 ;
}
static int F_138 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned int V_289 ;
unsigned long V_12 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_59 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
V_289 = ( ( V_1 -> V_138 & V_139 ) ? V_290 : 0 ) +
( ( V_1 -> V_138 & V_215 ) ? V_291 : 0 ) +
( ( V_1 -> V_138 & V_161 ) ? V_292 : 0 ) +
( ( V_1 -> V_138 & V_174 ) ? V_285 : 0 ) +
( ( V_1 -> V_138 & V_169 ) ? V_286 : 0 ) +
( ( V_1 -> V_138 & V_155 ) ? V_288 : 0 ) ;
if ( V_21 >= V_22 )
F_9 ( L_68 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_289 ) ;
return V_289 ;
}
static int F_139 ( struct V_9 * V_10 ,
unsigned int V_293 , unsigned int V_294 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_69 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_293 , V_294 ) ;
if ( V_293 & V_290 )
V_1 -> V_138 |= V_139 ;
if ( V_293 & V_291 )
V_1 -> V_138 |= V_215 ;
if ( V_294 & V_290 )
V_1 -> V_138 &= ~ V_139 ;
if ( V_294 & V_291 )
V_1 -> V_138 &= ~ V_215 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_60 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_140 ( struct V_9 * V_10 , int V_295 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_70 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_295 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_71 ) )
return - V_296 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_295 == - 1 )
F_141 ( V_1 , V_4 + V_297 , V_120 ) ;
else
F_142 ( V_1 , V_4 + V_297 , V_120 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
return 0 ;
}
static int F_143 ( struct V_9 * V_10 ,
struct V_298 * V_106 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
struct V_115 V_264 ;
unsigned long V_12 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_264 = V_1 -> V_106 ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
V_106 -> V_154 = V_264 . V_154 ;
V_106 -> V_168 = V_264 . V_168 ;
V_106 -> V_173 = V_264 . V_173 ;
V_106 -> V_160 = V_264 . V_160 ;
V_106 -> V_117 = V_264 . V_117 ;
V_106 -> V_299 = V_264 . V_299 ;
V_106 -> V_122 = V_264 . V_122 ;
V_106 -> V_128 = V_264 . V_128 ;
V_106 -> V_121 = V_264 . V_121 ;
V_106 -> V_127 = V_264 . V_127 ;
V_106 -> V_107 = V_264 . V_107 ;
return 0 ;
}
static int F_144 ( struct V_9 * V_10 ,
unsigned int V_73 , unsigned long V_64 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
void T_5 * V_300 = ( void T_5 * ) V_64 ;
if ( V_21 >= V_22 )
F_9 ( L_72 , __FILE__ , __LINE__ ,
V_1 -> V_76 , V_73 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_73 ) )
return - V_63 ;
if ( ( V_73 != V_301 ) && ( V_73 != V_302 ) &&
( V_73 != V_303 ) ) {
if ( V_10 -> V_12 & ( 1 << V_211 ) )
return - V_241 ;
}
switch ( V_73 ) {
case V_304 :
return F_117 ( V_1 , V_300 ) ;
case V_305 :
return F_118 ( V_1 , V_300 , V_10 ) ;
case V_306 :
return F_120 ( V_1 , V_300 ) ;
case V_307 :
return F_121 ( V_1 , ( int ) V_64 ) ;
case V_308 :
return F_123 ( V_1 , V_300 ) ;
case V_309 :
return F_124 ( V_1 , ( int ) V_64 ) ;
case V_310 :
return F_125 ( V_1 , ( int ) V_64 , V_10 ) ;
case V_311 :
return F_127 ( V_1 , ( int ) V_64 ) ;
case V_312 :
return F_126 ( V_1 ) ;
case V_313 :
return F_115 ( V_1 , V_300 ) ;
case V_314 :
return F_128 ( V_1 , V_300 ) ;
case V_303 :
return F_137 ( V_1 , ( int ) V_64 ) ;
default:
return - V_315 ;
}
return 0 ;
}
static void F_145 ( struct V_9 * V_10 , struct V_316 * V_317 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_74 , __FILE__ , __LINE__ ,
V_10 -> V_318 -> V_66 ) ;
if ( ( V_10 -> V_212 . V_213 == V_317 -> V_213 )
&& ( F_146 ( V_10 -> V_212 . V_319 )
== F_146 ( V_317 -> V_319 ) ) )
return;
F_87 ( V_1 , V_10 ) ;
if ( V_317 -> V_213 & V_219 &&
! ( V_10 -> V_212 . V_213 & V_219 ) ) {
V_1 -> V_138 &= ~ ( V_139 | V_215 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_60 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
if ( ! ( V_317 -> V_213 & V_219 ) &&
V_10 -> V_212 . V_213 & V_219 ) {
V_1 -> V_138 |= V_215 ;
if ( ! ( V_10 -> V_212 . V_213 & V_236 ) ||
! F_147 ( V_320 , & V_10 -> V_12 ) ) {
V_1 -> V_138 |= V_139 ;
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_60 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
if ( V_317 -> V_213 & V_236 &&
! ( V_10 -> V_212 . V_213 & V_236 ) ) {
V_10 -> V_143 = 0 ;
F_41 ( V_10 ) ;
}
}
static void F_148 ( struct V_9 * V_10 , struct V_321 * V_322 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
struct V_113 * V_27 = & V_1 -> V_27 ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_75 ) )
return;
if ( V_21 >= V_22 )
F_9 ( L_76 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_27 -> V_13 ) ;
F_149 ( ! V_27 -> V_13 ) ;
if ( F_150 ( V_27 , V_10 , V_322 ) == 0 )
goto V_240;
if ( V_27 -> V_12 & V_207 )
F_151 ( V_10 , V_1 -> V_235 ) ;
F_108 ( V_10 ) ;
F_152 ( V_10 ) ;
F_89 ( V_1 , V_10 ) ;
F_153 ( V_27 , V_10 ) ;
F_154 ( V_27 , NULL ) ;
V_240:
if ( V_21 >= V_22 )
F_9 ( L_77 , __FILE__ , __LINE__ ,
V_10 -> V_318 -> V_66 , V_27 -> V_13 ) ;
}
static void F_151 ( struct V_9 * V_10 , int V_235 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
unsigned long V_323 , V_324 ;
if ( ! V_1 )
return;
if ( V_21 >= V_22 )
F_9 ( L_78 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_79 ) )
return;
if ( ! ( V_1 -> V_27 . V_12 & V_207 ) )
goto exit;
V_323 = V_325 ;
if ( V_1 -> V_39 . V_234 ) {
V_324 = V_1 -> V_235 / ( 32 * 5 ) ;
if ( ! V_324 )
V_324 ++ ;
} else
V_324 = 1 ;
if ( V_235 )
V_324 = F_64 (unsigned long, char_time, timeout) ;
if ( V_1 -> V_39 . V_131 == V_145 ) {
while ( V_1 -> V_129 ) {
F_155 ( F_156 ( V_324 ) ) ;
if ( F_133 ( V_270 ) )
break;
if ( V_235 && F_157 ( V_325 , V_323 + V_235 ) )
break;
}
} else {
while ( ( V_1 -> V_133 || V_1 -> V_129 ) &&
V_1 -> V_77 ) {
F_155 ( F_156 ( V_324 ) ) ;
if ( F_133 ( V_270 ) )
break;
if ( V_235 && F_157 ( V_325 , V_323 + V_235 ) )
break;
}
}
exit:
if ( V_21 >= V_22 )
F_9 ( L_80 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
}
static void F_158 ( struct V_9 * V_10 )
{
T_1 * V_1 = ( T_1 * ) V_10 -> V_75 ;
if ( V_21 >= V_22 )
F_9 ( L_81 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_82 ) )
return;
F_108 ( V_10 ) ;
F_89 ( V_1 , V_10 ) ;
F_159 ( & V_1 -> V_27 ) ;
}
static int F_160 ( struct V_113 * V_27 )
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
static void F_161 ( struct V_113 * V_27 , int V_326 )
{
T_1 * V_1 = F_44 ( V_27 , T_1 , V_27 ) ;
unsigned long V_12 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( V_326 )
V_1 -> V_138 |= V_139 | V_215 ;
else
V_1 -> V_138 &= ~ ( V_139 | V_215 ) ;
F_60 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
}
static int F_162 ( struct V_9 * V_10 , struct V_321 * V_322 )
{
T_1 * V_1 ;
struct V_113 * V_27 ;
int V_206 , line ;
unsigned long V_12 ;
line = V_10 -> V_327 ;
if ( line >= V_328 ) {
F_9 ( L_83 ,
__FILE__ , __LINE__ , line ) ;
return - V_63 ;
}
V_1 = V_329 ;
while( V_1 && V_1 -> line != line )
V_1 = V_1 -> V_330 ;
if ( F_30 ( V_1 , V_10 -> V_66 , L_84 ) )
return - V_63 ;
V_27 = & V_1 -> V_27 ;
V_10 -> V_75 = V_1 ;
F_154 ( V_27 , V_10 ) ;
if ( V_21 >= V_22 )
F_9 ( L_85 ,
__FILE__ , __LINE__ , V_10 -> V_318 -> V_66 , V_27 -> V_13 ) ;
if ( F_163 ( V_322 ) || V_27 -> V_12 & V_331 ) {
if ( V_27 -> V_12 & V_331 )
F_164 ( & V_27 -> V_332 ) ;
V_206 = ( ( V_27 -> V_12 & V_333 ) ?
- V_334 : - V_281 ) ;
goto V_240;
}
V_27 -> V_335 = ( V_27 -> V_12 & V_336 ) ? 1 : 0 ;
F_38 ( & V_1 -> V_38 , V_12 ) ;
if ( V_1 -> V_141 ) {
V_206 = - V_337 ;
F_40 ( & V_1 -> V_38 , V_12 ) ;
goto V_240;
}
F_75 ( & V_27 -> V_37 ) ;
V_27 -> V_13 ++ ;
F_78 ( & V_27 -> V_37 ) ;
F_40 ( & V_1 -> V_38 , V_12 ) ;
if ( V_27 -> V_13 == 1 ) {
V_206 = F_79 ( V_1 , V_10 ) ;
if ( V_206 < 0 )
goto V_240;
}
V_206 = F_165 ( & V_1 -> V_27 , V_10 , V_322 ) ;
if ( V_206 ) {
if ( V_21 >= V_22 )
F_9 ( L_86 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_206 ) ;
goto V_240;
}
if ( V_21 >= V_22 )
F_9 ( L_87 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
V_206 = 0 ;
V_240:
return V_206 ;
}
static inline void F_166 ( struct V_338 * V_339 , T_1 * V_1 )
{
char V_340 [ 30 ] ;
unsigned long V_12 ;
F_167 ( V_339 , L_88 ,
V_1 -> V_76 , V_1 -> V_58 , V_1 -> V_61 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_59 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
V_340 [ 0 ] = 0 ;
V_340 [ 1 ] = 0 ;
if ( V_1 -> V_138 & V_139 )
strcat ( V_340 , L_89 ) ;
if ( V_1 -> V_138 & V_155 )
strcat ( V_340 , L_90 ) ;
if ( V_1 -> V_138 & V_215 )
strcat ( V_340 , L_91 ) ;
if ( V_1 -> V_138 & V_169 )
strcat ( V_340 , L_92 ) ;
if ( V_1 -> V_138 & V_161 )
strcat ( V_340 , L_93 ) ;
if ( V_1 -> V_138 & V_174 )
strcat ( V_340 , L_94 ) ;
if ( V_1 -> V_39 . V_131 == V_145 ) {
F_167 ( V_339 , L_95 ,
V_1 -> V_106 . V_203 , V_1 -> V_106 . V_341 ) ;
if ( V_1 -> V_106 . V_201 )
F_167 ( V_339 , L_96 , V_1 -> V_106 . V_201 ) ;
if ( V_1 -> V_106 . V_200 )
F_167 ( V_339 , L_97 , V_1 -> V_106 . V_200 ) ;
if ( V_1 -> V_106 . V_342 )
F_167 ( V_339 , L_98 , V_1 -> V_106 . V_342 ) ;
if ( V_1 -> V_106 . V_343 )
F_167 ( V_339 , L_99 , V_1 -> V_106 . V_343 ) ;
if ( V_1 -> V_106 . V_344 )
F_167 ( V_339 , L_100 , V_1 -> V_106 . V_344 ) ;
if ( V_1 -> V_106 . V_345 )
F_167 ( V_339 , L_101 , V_1 -> V_106 . V_345 ) ;
} else {
F_167 ( V_339 , L_102 ,
V_1 -> V_106 . V_299 , V_1 -> V_106 . V_117 ) ;
if ( V_1 -> V_106 . V_122 )
F_167 ( V_339 , L_103 , V_1 -> V_106 . V_122 ) ;
if ( V_1 -> V_106 . V_121 )
F_167 ( V_339 , L_104 , V_1 -> V_106 . V_121 ) ;
if ( V_1 -> V_106 . V_127 )
F_167 ( V_339 , L_105 , V_1 -> V_106 . V_127 ) ;
if ( V_1 -> V_106 . V_128 )
F_167 ( V_339 , L_106 , V_1 -> V_106 . V_128 ) ;
}
F_167 ( V_339 , L_107 , V_340 + 1 ) ;
F_167 ( V_339 , L_108 ,
V_1 -> V_129 , V_1 -> V_84 , V_1 -> V_83 ,
V_1 -> V_79 ) ;
}
static int F_168 ( struct V_338 * V_339 , void * V_346 )
{
T_1 * V_1 ;
F_167 ( V_339 , L_109 , V_347 ) ;
V_1 = V_329 ;
while ( V_1 ) {
F_166 ( V_339 , V_1 ) ;
V_1 = V_1 -> V_330 ;
}
return 0 ;
}
static int F_169 ( struct V_348 * V_348 , struct V_321 * V_321 )
{
return F_170 ( V_321 , F_168 , NULL ) ;
}
static int F_171 ( T_1 * V_1 )
{
V_1 -> V_99 = sizeof( T_3 ) + V_1 -> V_31 ;
V_1 -> V_349 = V_1 -> V_99 * 8 ;
if ( V_1 -> V_349 > 0x10000 )
V_1 -> V_349 = 0x10000 ;
V_1 -> V_103 = V_1 -> V_349 / V_1 -> V_99 ;
V_1 -> V_97 = F_172 ( V_1 -> V_349 , V_23 ) ;
if ( V_1 -> V_97 == NULL )
return - V_24 ;
V_1 -> V_350 = F_10 ( V_1 -> V_31 , V_23 ) ;
if ( ! V_1 -> V_350 ) {
F_19 ( V_1 -> V_97 ) ;
V_1 -> V_97 = NULL ;
return - V_24 ;
}
F_173 ( V_1 ) ;
return 0 ;
}
static void F_174 ( T_1 * V_1 )
{
F_19 ( V_1 -> V_97 ) ;
V_1 -> V_97 = NULL ;
F_19 ( V_1 -> V_350 ) ;
V_1 -> V_350 = NULL ;
}
static int F_82 ( T_1 * V_1 )
{
if ( F_171 ( V_1 ) < 0 ) {
F_9 ( L_110 , V_1 -> V_76 ) ;
F_86 ( V_1 ) ;
return - V_63 ;
}
return 0 ;
}
static void F_86 ( T_1 * V_1 )
{
if ( V_21 >= V_22 )
F_9 ( L_111 , V_1 -> V_76 ) ;
F_174 ( V_1 ) ;
}
static int F_16 ( T_1 * V_1 )
{
T_1 * V_351 = NULL ;
struct V_352 * V_353 ;
int V_20 ;
V_1 -> V_330 = NULL ;
V_1 -> line = V_328 ;
sprintf ( V_1 -> V_76 , L_112 , V_1 -> line ) ;
if ( V_1 -> line < V_354 ) {
if ( V_355 [ V_1 -> line ] )
V_1 -> V_31 = V_355 [ V_1 -> line ] ;
}
V_328 ++ ;
if ( ! V_329 )
V_329 = V_1 ;
else {
V_351 = V_329 ;
while ( V_351 -> V_330 )
V_351 = V_351 -> V_330 ;
V_351 -> V_330 = V_1 ;
}
if ( V_1 -> V_31 < 4096 )
V_1 -> V_31 = 4096 ;
else if ( V_1 -> V_31 > 65535 )
V_1 -> V_31 = 65535 ;
F_9 ( L_113 ,
V_1 -> V_76 , V_1 -> V_58 , V_1 -> V_61 ) ;
#if V_140
V_20 = F_175 ( V_1 ) ;
if ( V_20 != 0 )
goto V_47;
#endif
V_353 = F_176 ( & V_1 -> V_27 , V_356 , V_1 -> line ,
& V_1 -> V_45 -> V_357 ) ;
if ( F_177 ( V_353 ) ) {
V_20 = F_178 ( V_353 ) ;
#if V_140
F_179 ( V_1 ) ;
#endif
goto V_47;
}
return 0 ;
V_47:
if ( V_351 )
V_351 -> V_330 = NULL ;
else
V_329 = NULL ;
V_328 -- ;
return V_20 ;
}
static void F_27 ( T_1 * V_358 )
{
T_1 * V_1 = V_329 ;
T_1 * V_359 = NULL ;
while( V_1 ) {
if ( V_1 == V_358 ) {
if ( V_359 )
V_359 -> V_330 = V_1 -> V_330 ;
else
V_329 = V_1 -> V_330 ;
F_180 ( V_356 , V_1 -> line ) ;
#if V_140
F_179 ( V_1 ) ;
#endif
F_86 ( V_1 ) ;
F_18 ( & V_1 -> V_27 ) ;
F_19 ( V_1 ) ;
V_328 -- ;
return;
}
V_359 = V_1 ;
V_1 = V_1 -> V_330 ;
}
}
static int T_6 F_181 ( void )
{
int V_78 ;
if ( V_360 ) {
F_4 () ;
F_182 () ;
}
V_356 = F_183 ( V_354 ,
V_361 |
V_362 ) ;
if ( F_177 ( V_356 ) ) {
V_78 = F_178 ( V_356 ) ;
goto V_246;
}
V_356 -> V_363 = L_114 ;
V_356 -> V_66 = L_115 ;
V_356 -> V_364 = V_365 ;
V_356 -> V_366 = 64 ;
V_356 -> type = V_367 ;
V_356 -> V_368 = V_369 ;
V_356 -> V_370 = V_371 ;
V_356 -> V_370 . V_213 =
V_372 | V_225 | V_216 | V_214 | V_238 ;
F_184 ( V_356 , & V_373 ) ;
V_78 = F_185 ( V_356 ) ;
if ( V_78 < 0 ) {
F_9 ( V_208 L_116 ,
__FILE__ , __LINE__ ) ;
goto V_374;
}
V_78 = F_186 ( & V_375 ) ;
if ( V_78 < 0 )
goto V_376;
F_9 ( V_377 L_117 , V_363 , V_347 ,
V_356 -> V_364 ) ;
return 0 ;
V_376:
F_187 ( V_356 ) ;
V_374:
F_188 ( V_356 ) ;
V_246:
return V_78 ;
}
static void T_7 F_189 ( void )
{
F_190 ( & V_375 ) ;
F_187 ( V_356 ) ;
F_188 ( V_356 ) ;
}
static void F_191 ( T_1 * V_1 , unsigned char V_2 , unsigned int V_378 )
{
unsigned int V_379 , V_380 ;
unsigned char V_252 ;
if ( V_378 ) {
V_380 = 3686400 / V_378 ;
if ( ! V_380 )
V_380 = 1 ;
V_380 >>= 1 ;
for ( V_379 = 1 ; V_380 > 64 && V_379 < 16 ; V_379 ++ )
V_380 >>= 1 ;
V_380 -- ;
F_36 ( V_1 , ( unsigned char ) ( V_2 + V_381 ) ,
( unsigned char ) ( ( V_379 << 6 ) + V_380 ) ) ;
V_252 = F_33 ( V_1 , ( unsigned char ) ( V_2 + V_382 ) ) & 0x3f ;
V_252 |= ( ( V_379 << 4 ) & 0xc0 ) ;
F_36 ( V_1 , ( unsigned char ) ( V_2 + V_382 ) , V_252 ) ;
}
}
static void F_192 ( T_1 * V_1 )
{
unsigned char V_252 ;
V_252 = 0x82 ;
if ( V_1 -> V_39 . V_131 == V_145 && V_1 -> V_39 . V_383 )
V_252 |= V_72 ;
F_36 ( V_1 , V_8 + V_384 , V_252 ) ;
F_36 ( V_1 , V_8 + V_385 , 0xc0 ) ;
F_36 ( V_1 , V_8 + V_386 , 0x17 ) ;
if ( V_1 -> V_39 . V_131 == V_145 && V_1 -> V_39 . V_383 )
F_36 ( V_1 , V_8 + V_382 , 0x38 ) ;
else
F_36 ( V_1 , V_8 + V_382 , 0x30 ) ;
F_36 ( V_1 , V_8 + V_387 , 0x50 ) ;
if ( V_1 -> V_39 . V_131 == V_145 && V_1 -> V_39 . V_383 )
F_191 ( V_1 , V_8 , V_1 -> V_39 . V_383 ) ;
else
F_191 ( V_1 , V_8 , 921600 ) ;
}
static void F_193 ( T_1 * V_1 )
{
unsigned char V_252 ;
V_252 = F_33 ( V_1 , V_4 + V_386 ) | ( V_72 + V_185 + V_186 ) ;
F_36 ( V_1 , V_4 + V_386 , V_252 ) ;
V_252 = F_33 ( V_1 , V_4 + V_382 ) | ( V_388 + V_116 ) ;
F_36 ( V_1 , V_4 + V_382 , V_252 ) ;
if ( V_1 -> V_39 . V_383 )
F_191 ( V_1 , V_4 , V_1 -> V_39 . V_383 ) ;
else
F_191 ( V_1 , V_4 , 1843200 ) ;
V_252 = F_33 ( V_1 , V_4 + V_384 ) | V_186 ;
F_36 ( V_1 , V_4 + V_384 , V_252 ) ;
}
static void F_95 ( T_1 * V_1 )
{
unsigned char V_252 ;
unsigned char V_389 , V_390 ;
F_1 ( V_1 , V_4 , 0xffff ) ;
F_1 ( V_1 , V_8 , 0xffff ) ;
F_73 ( V_1 , 0xff ) ;
V_389 = V_390 = 0 ;
if ( V_1 -> V_39 . V_12 & V_391
&& V_1 -> V_39 . V_12 & V_392 ) {
V_389 = 7 ;
} else if ( V_1 -> V_39 . V_12 & V_393
&& V_1 -> V_39 . V_12 & V_394 ) {
V_389 = 7 ;
V_390 = 1 ;
} else if ( V_1 -> V_39 . V_12 & V_391 ) {
if ( V_1 -> V_39 . V_12 & V_394 ) {
V_389 = 6 ;
V_390 = 1 ;
} else {
V_389 = 6 ;
}
} else if ( V_1 -> V_39 . V_12 & V_394 ) {
V_390 = 1 ;
}
V_252 = 0x82 ;
if ( V_1 -> V_39 . V_395 )
V_252 |= V_186 ;
if ( V_1 -> V_138 & V_139 )
V_252 |= V_72 ;
F_36 ( V_1 , V_4 + V_384 , V_252 ) ;
V_252 = 0xc0 ;
switch ( V_1 -> V_39 . V_396 )
{
case V_397 :
V_252 |= V_188 ;
break;
case V_398 :
V_252 |= V_388 ;
break;
case V_399 :
V_252 |= V_388 + V_72 ;
break;
case V_400 :
V_252 |= V_388 + V_188 ;
break;
}
F_36 ( V_1 , V_4 + V_385 , V_252 ) ;
V_252 = 0x10 + V_389 ;
F_36 ( V_1 , V_4 + V_386 , V_252 ) ;
V_252 = 0x00 ;
if ( V_389 == 2 || V_389 == 3 || V_389 == 6
|| V_389 == 7 || ( V_389 == 0 && V_390 == 1 ) )
V_252 |= V_116 ;
if ( V_390 )
V_252 |= V_388 ;
if ( V_1 -> V_39 . V_401 == V_402 )
V_252 |= V_185 ;
if ( V_1 -> V_39 . V_396 == V_403 )
V_252 |= V_186 ;
F_36 ( V_1 , V_4 + V_382 , V_252 ) ;
V_252 = 0x00 ;
if ( V_1 -> V_39 . V_401 == V_404 )
V_252 |= V_72 + V_185 ;
if ( V_1 -> V_39 . V_405 != V_406 )
V_252 |= V_116 ;
switch ( V_1 -> V_39 . V_407 )
{
case V_408 :
V_252 |= V_120 ;
break;
case V_409 :
V_252 |= V_120 ;
break;
case V_410 :
V_252 |= V_119 + V_120 ;
break;
}
F_36 ( V_1 , V_4 + V_411 , V_252 ) ;
V_252 = 0 ;
switch ( V_1 -> V_39 . V_405 )
{
case V_412 : V_252 = 0x7e ; break;
case V_413 : V_252 = 0xaa ; break;
case V_414 : V_252 = 0x55 ; break;
case V_415 : V_252 = 0xff ; break;
}
F_36 ( V_1 , V_4 + V_416 , V_252 ) ;
V_252 = 0x50 ;
F_36 ( V_1 , V_4 + V_387 , V_252 ) ;
if ( V_1 -> V_39 . V_12 & V_391 )
F_191 ( V_1 , V_4 , V_1 -> V_39 . V_383 * 16 ) ;
else
F_191 ( V_1 , V_4 , V_1 -> V_39 . V_383 ) ;
F_36 ( V_1 , V_4 + V_417 , 0 ) ;
V_252 = 0x00 ;
if ( V_1 -> V_39 . V_12 & V_418 )
V_252 |= V_116 ;
F_36 ( V_1 , V_4 + V_419 , V_252 ) ;
F_192 ( V_1 ) ;
if ( V_1 -> V_39 . V_395 || V_1 -> V_420 )
F_193 ( V_1 ) ;
if ( V_1 -> V_39 . V_12 & V_421 )
{
F_3 ( V_1 , V_8 , V_153 ) ;
F_141 ( V_1 , V_4 + V_253 , V_188 ) ;
} else
F_142 ( V_1 , V_4 + V_253 , V_188 ) ;
F_3 ( V_1 , V_4 ,
V_197 + V_198 + V_202 +
V_199 + V_204 ) ;
F_35 ( V_1 , V_4 , V_422 + V_104 ) ;
F_32 ( V_1 , V_4 ) ;
F_52 ( V_1 , V_4 + V_187 ) ;
if ( ! V_1 -> V_420 )
F_142 ( V_1 , V_4 + V_385 , V_120 ) ;
F_122 ( V_1 ) ;
F_39 ( V_1 ) ;
F_92 ( V_1 ) ;
}
static void F_92 ( T_1 * V_1 )
{
if ( V_21 >= V_100 )
F_9 ( L_118 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
F_142 ( V_1 , V_4 + V_384 , V_188 ) ;
V_1 -> V_101 = false ;
V_1 -> V_105 = false ;
}
static void F_98 ( T_1 * V_1 )
{
if ( V_21 >= V_100 )
F_9 ( L_119 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
F_173 ( V_1 ) ;
V_1 -> V_101 = false ;
V_1 -> V_105 = false ;
F_141 ( V_1 , V_4 + V_384 , V_188 ) ;
V_1 -> V_101 = true ;
}
static void F_42 ( T_1 * V_1 , struct V_9 * V_10 )
{
if ( V_21 >= V_100 )
F_9 ( L_120 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( V_1 -> V_133 ) {
V_1 -> V_137 = false ;
if ( V_1 -> V_39 . V_12 & V_423 ) {
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
F_194 ( & V_1 -> V_136 , V_325 +
F_195 ( 5000 ) ) ;
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
static void F_93 ( T_1 * V_1 )
{
F_36 ( V_1 , V_4 + V_385 , 0x80 ) ;
F_36 ( V_1 , V_8 + V_385 , 0x80 ) ;
F_36 ( V_1 , V_4 + V_384 , 0 ) ;
F_36 ( V_1 , V_8 + V_384 , 0 ) ;
F_1 ( V_1 , V_4 , 0xffff ) ;
F_1 ( V_1 , V_8 , 0xffff ) ;
F_73 ( V_1 , 0xff ) ;
F_36 ( V_1 , V_424 , 0x06 ) ;
F_36 ( V_1 , V_425 , 0x05 ) ;
}
static void F_96 ( T_1 * V_1 )
{
unsigned char V_252 ;
F_1 ( V_1 , V_4 , 0xffff ) ;
F_1 ( V_1 , V_8 , 0xffff ) ;
F_73 ( V_1 , 0xff ) ;
V_252 = 0x06 ;
if ( V_1 -> V_39 . V_395 )
V_252 |= V_186 ;
if ( ! ( V_1 -> V_138 & V_139 ) )
V_252 |= V_120 ;
F_36 ( V_1 , V_4 + V_384 , V_252 ) ;
F_36 ( V_1 , V_4 + V_385 , 0x83 ) ;
F_36 ( V_1 , V_4 + V_386 , 0x1f ) ;
F_36 ( V_1 , V_4 + V_382 , 0x10 ) ;
F_36 ( V_1 , V_4 + V_411 , 0 ) ;
F_36 ( V_1 , V_4 + V_387 , 0x50 ) ;
F_191 ( V_1 , V_4 , V_1 -> V_39 . V_234 * 16 ) ;
V_252 = 0x00 ;
if ( V_1 -> V_39 . V_222 != 8 )
V_252 |= V_186 ;
if ( V_1 -> V_39 . V_227 != 1 )
V_252 |= V_116 ;
if ( V_1 -> V_39 . V_121 != V_228 )
{
V_252 |= V_72 ;
if ( V_1 -> V_39 . V_121 == V_231 )
V_252 |= V_188 ;
else
V_252 |= V_388 ;
}
F_36 ( V_1 , V_4 + V_297 , V_252 ) ;
F_36 ( V_1 , V_4 + V_426 , 0x5c ) ;
F_36 ( V_1 , V_4 + V_417 , 0 ) ;
V_252 = 0x00 ;
if ( V_1 -> V_39 . V_12 & V_418 )
V_252 |= V_116 ;
F_36 ( V_1 , V_4 + V_419 , V_252 ) ;
if ( V_1 -> V_39 . V_12 & V_421 )
F_3 ( V_1 , V_4 , V_153 ) ;
F_141 ( V_1 , V_4 + V_384 , V_188 ) ;
F_192 ( V_1 ) ;
if ( V_1 -> V_39 . V_12 & V_421 ) {
F_3 ( V_1 , V_8 , V_153 ) ;
F_141 ( V_1 , V_4 + V_253 , V_188 ) ;
} else
F_142 ( V_1 , V_4 + V_253 , V_188 ) ;
F_3 ( V_1 , V_4 ,
V_197 + V_198 + V_193 + V_195 +
V_202 + V_204 ) ;
F_35 ( V_1 , V_4 , V_422 + V_104 ) ;
F_32 ( V_1 , V_4 ) ;
F_52 ( V_1 , V_4 + V_187 ) ;
}
static void F_122 ( T_1 * V_1 )
{
if ( V_1 -> V_42 == V_43 )
F_141 ( V_1 , V_4 + V_386 , V_188 ) ;
else
F_142 ( V_1 , V_4 + V_386 , V_188 ) ;
}
static void F_59 ( T_1 * V_1 )
{
unsigned char V_110 = 0 ;
V_1 -> V_138 &= V_139 | V_215 ;
if ( F_33 ( V_1 , V_8 + V_427 ) & V_119 )
V_1 -> V_138 |= V_161 ;
if ( F_33 ( V_1 , V_8 + V_71 ) & V_185 )
V_1 -> V_138 |= V_155 ;
V_110 = F_33 ( V_1 , V_4 + V_253 ) ;
if ( ! ( V_110 & V_172 ) )
V_1 -> V_138 |= V_174 ;
if ( ! ( V_110 & V_167 ) )
V_1 -> V_138 |= V_169 ;
}
static void F_60 ( T_1 * V_1 )
{
unsigned char V_252 ;
V_252 = F_33 ( V_1 , V_4 + V_384 ) ;
if ( V_1 -> V_39 . V_131 == V_132 ) {
if ( V_1 -> V_138 & V_139 )
V_252 &= ~ V_120 ;
else
V_252 |= V_120 ;
} else {
if ( V_1 -> V_138 & V_139 )
V_252 |= V_72 ;
else
V_252 &= ~ V_72 ;
}
F_36 ( V_1 , V_4 + V_384 , V_252 ) ;
if ( V_1 -> V_138 & V_215 )
F_142 ( V_1 , V_4 + V_253 , V_428 ) ;
else
F_141 ( V_1 , V_4 + V_253 , V_428 ) ;
}
static void F_173 ( T_1 * V_1 )
{
T_3 * V_96 ;
int V_70 ;
V_1 -> V_98 = 0 ;
V_1 -> V_429 = 0 ;
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
unsigned int V_430 = 0 ;
unsigned long V_12 ;
bool V_431 = false ;
if ( V_1 -> V_102 == 0 )
return false ;
V_96 = ( T_3 * ) ( V_1 -> V_97 + ( V_1 -> V_429 * V_1 -> V_99 ) ) ;
V_110 = V_96 -> V_110 ;
if ( ( V_110 & 0xf0 ) != 0xA0 ) {
if ( ! ( V_110 & V_119 ) || ( V_110 & V_388 ) )
V_1 -> V_106 . V_432 ++ ;
else if ( V_110 & V_120 )
V_1 -> V_106 . V_344 ++ ;
else if ( ! ( V_110 & V_116 ) ) {
V_1 -> V_106 . V_345 ++ ;
if ( V_1 -> V_39 . V_401 & V_433 )
V_431 = true ;
}
V_430 = 0 ;
#if V_140
{
V_1 -> V_164 -> V_434 . V_435 ++ ;
V_1 -> V_164 -> V_434 . V_436 ++ ;
}
#endif
} else
V_431 = true ;
if ( V_431 )
V_430 = V_96 -> V_13 ;
if ( V_21 >= V_88 )
F_9 ( L_122 ,
__FILE__ , __LINE__ , V_1 -> V_76 , V_110 , V_430 ) ;
if ( V_21 >= V_437 )
F_196 ( V_1 , V_96 -> V_11 , V_430 , 0 ) ;
if ( V_430 ) {
if ( ( V_1 -> V_39 . V_401 & V_433 &&
V_430 + 1 > V_1 -> V_31 ) ||
V_430 > V_1 -> V_31 )
V_1 -> V_106 . V_343 ++ ;
else {
if ( V_110 & V_116 )
V_1 -> V_106 . V_341 ++ ;
if ( V_1 -> V_39 . V_401 & V_433 ) {
* ( V_96 -> V_11 + V_430 ) = V_110 & V_116 ? V_438 : V_439 ;
++ V_430 ;
}
#if V_140
if ( V_1 -> V_141 )
F_197 ( V_1 , V_96 -> V_11 , V_430 ) ;
else
#endif
F_5 ( V_10 , V_96 -> V_11 , V_1 -> V_350 , V_430 ) ;
}
}
F_38 ( & V_1 -> V_37 , V_12 ) ;
V_96 -> V_110 = V_96 -> V_13 = 0 ;
V_1 -> V_102 -- ;
V_1 -> V_429 ++ ;
if ( V_1 -> V_429 >= V_1 -> V_103 )
V_1 -> V_429 = 0 ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
return true ;
}
static bool F_198 ( T_1 * V_1 )
{
static unsigned char V_440 [] =
{ 0x00 , 0xff , 0xaa , 0x55 , 0x69 , 0x96 , 0x0f } ;
static unsigned int V_13 = F_199 ( V_440 ) ;
unsigned int V_70 ;
bool V_78 = true ;
unsigned long V_12 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_93 ( V_1 ) ;
for ( V_70 = 0 ; V_70 < V_13 ; V_70 ++ ) {
F_36 ( V_1 , V_441 , V_440 [ V_70 ] ) ;
F_36 ( V_1 , V_442 , V_440 [ ( V_70 + 1 ) % V_13 ] ) ;
if ( ( F_33 ( V_1 , V_441 ) != V_440 [ V_70 ] ) ||
( F_33 ( V_1 , V_442 ) != V_440 [ ( V_70 + 1 ) % V_13 ] ) ) {
V_78 = false ;
break;
}
}
F_40 ( & V_1 -> V_37 , V_12 ) ;
return V_78 ;
}
static bool F_200 ( T_1 * V_1 )
{
unsigned long V_443 ;
unsigned long V_12 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_93 ( V_1 ) ;
V_1 -> V_420 = true ;
F_95 ( V_1 ) ;
V_1 -> V_190 = false ;
F_3 ( V_1 , V_4 , V_189 ) ;
F_36 ( V_1 , V_4 + V_444 , 0 ) ;
F_35 ( V_1 , V_4 , V_445 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
V_443 = 100 ;
while( V_443 -- && ! V_1 -> V_190 ) {
F_155 ( 10 ) ;
}
V_1 -> V_420 = false ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_93 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
return V_1 -> V_190 ;
}
static int F_83 ( T_1 * V_1 )
{
if ( ! F_198 ( V_1 ) ) {
V_1 -> V_446 = V_447 ;
F_9 ( L_123 ,
__FILE__ , __LINE__ , V_1 -> V_76 , ( unsigned short ) ( V_1 -> V_58 ) ) ;
return - V_63 ;
}
if ( ! F_200 ( V_1 ) ) {
V_1 -> V_446 = V_448 ;
F_9 ( L_124 ,
__FILE__ , __LINE__ , V_1 -> V_76 , ( unsigned short ) ( V_1 -> V_61 ) ) ;
return - V_63 ;
}
if ( V_21 >= V_22 )
F_9 ( L_125 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
return 0 ;
}
static void F_196 ( T_1 * V_1 , const char * V_11 , int V_13 , int V_449 )
{
int V_70 ;
int V_450 ;
if ( V_449 )
F_9 ( L_126 , V_1 -> V_76 ) ;
else
F_9 ( L_127 , V_1 -> V_76 ) ;
while( V_13 ) {
if ( V_13 > 16 )
V_450 = 16 ;
else
V_450 = V_13 ;
for( V_70 = 0 ; V_70 < V_450 ; V_70 ++ )
F_9 ( L_128 , ( unsigned char ) V_11 [ V_70 ] ) ;
for(; V_70 < 17 ; V_70 ++ )
F_9 ( L_129 ) ;
for( V_70 = 0 ; V_70 < V_450 ; V_70 ++ ) {
if ( V_11 [ V_70 ] >= 040 && V_11 [ V_70 ] <= 0176 )
F_9 ( L_130 , V_11 [ V_70 ] ) ;
else
F_9 ( L_131 ) ;
}
F_9 ( L_132 ) ;
V_11 += V_450 ;
V_13 -= V_450 ;
}
}
static void V_209 ( unsigned long V_451 )
{
T_1 * V_1 = ( T_1 * ) V_451 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_133 ,
__FILE__ , __LINE__ , V_1 -> V_76 ) ;
if ( V_1 -> V_129 &&
V_1 -> V_39 . V_131 == V_145 ) {
V_1 -> V_106 . V_452 ++ ;
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
static int F_201 ( struct V_453 * V_357 , unsigned short V_396 ,
unsigned short V_121 )
{
T_1 * V_1 = F_202 ( V_357 ) ;
struct V_9 * V_10 ;
unsigned char V_454 ;
unsigned short V_455 ;
if ( V_1 -> V_27 . V_13 )
return - V_337 ;
switch ( V_396 )
{
case V_456 : V_454 = V_457 ; break;
case V_458 : V_454 = V_459 ; break;
case V_460 : V_454 = V_399 ; break;
case V_461 : V_454 = V_398 ; break;
case V_462 : V_454 = V_400 ; break;
default: return - V_296 ;
}
switch ( V_121 )
{
case V_463 : V_455 = V_404 ; break;
case V_464 : V_455 = V_465 ; break;
case V_466 : V_455 = V_402 ; break;
default: return - V_296 ;
}
V_1 -> V_39 . V_396 = V_454 ;
V_1 -> V_39 . V_401 = V_455 ;
if ( V_1 -> V_141 ) {
V_10 = F_45 ( & V_1 -> V_27 ) ;
F_94 ( V_1 , V_10 ) ;
F_49 ( V_10 ) ;
}
return 0 ;
}
static T_8 F_203 ( struct V_467 * V_468 ,
struct V_453 * V_357 )
{
T_1 * V_1 = F_202 ( V_357 ) ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( V_377 L_134 , __FILE__ , V_357 -> V_66 ) ;
F_204 ( V_357 ) ;
F_205 ( V_468 , V_1 -> V_148 , V_468 -> V_469 ) ;
V_1 -> V_135 = 0 ;
V_1 -> V_134 = V_1 -> V_133 = V_468 -> V_469 ;
V_357 -> V_434 . V_470 ++ ;
V_357 -> V_434 . V_471 += V_468 -> V_469 ;
F_206 ( V_468 ) ;
V_357 -> V_472 = V_325 ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
if ( ! V_1 -> V_129 ) {
struct V_9 * V_10 = F_45 ( & V_1 -> V_27 ) ;
F_42 ( V_1 , V_10 ) ;
F_49 ( V_10 ) ;
}
F_40 ( & V_1 -> V_37 , V_12 ) ;
return V_473 ;
}
static int F_207 ( struct V_453 * V_357 )
{
T_1 * V_1 = F_202 ( V_357 ) ;
struct V_9 * V_10 ;
int V_78 ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_135 , __FILE__ , V_357 -> V_66 ) ;
V_78 = F_208 ( V_357 ) ;
if ( V_78 != 0 )
return V_78 ;
F_38 ( & V_1 -> V_38 , V_12 ) ;
if ( V_1 -> V_27 . V_13 != 0 || V_1 -> V_141 != 0 ) {
F_9 ( V_474 L_136 , V_357 -> V_66 ) ;
F_40 ( & V_1 -> V_38 , V_12 ) ;
return - V_337 ;
}
V_1 -> V_141 = 1 ;
F_40 ( & V_1 -> V_38 , V_12 ) ;
V_10 = F_45 ( & V_1 -> V_27 ) ;
V_78 = F_79 ( V_1 , V_10 ) ;
if ( V_78 != 0 ) {
F_49 ( V_10 ) ;
F_38 ( & V_1 -> V_38 , V_12 ) ;
V_1 -> V_141 = 0 ;
F_40 ( & V_1 -> V_38 , V_12 ) ;
return V_78 ;
}
V_1 -> V_138 |= V_139 | V_215 ;
F_94 ( V_1 , V_10 ) ;
F_49 ( V_10 ) ;
V_357 -> V_472 = V_325 ;
F_209 ( V_357 ) ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_59 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
if ( V_1 -> V_138 & V_161 )
F_69 ( V_357 ) ;
else
F_70 ( V_357 ) ;
return 0 ;
}
static int F_210 ( struct V_453 * V_357 )
{
T_1 * V_1 = F_202 ( V_357 ) ;
struct V_9 * V_10 = F_45 ( & V_1 -> V_27 ) ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_137 , __FILE__ , V_357 -> V_66 ) ;
F_204 ( V_357 ) ;
F_89 ( V_1 , V_10 ) ;
F_49 ( V_10 ) ;
F_211 ( V_357 ) ;
F_38 ( & V_1 -> V_38 , V_12 ) ;
V_1 -> V_141 = 0 ;
F_40 ( & V_1 -> V_38 , V_12 ) ;
return 0 ;
}
static int F_212 ( struct V_453 * V_357 , struct V_475 * V_476 , int V_73 )
{
const T_9 V_477 = sizeof( V_478 ) ;
V_478 V_479 ;
V_478 T_5 * line = V_476 -> V_480 . V_481 . V_482 ;
T_1 * V_1 = F_202 ( V_357 ) ;
unsigned int V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_138 , __FILE__ , V_357 -> V_66 ) ;
if ( V_1 -> V_27 . V_13 )
return - V_337 ;
if ( V_73 != V_483 )
return F_213 ( V_357 , V_476 , V_73 ) ;
memset ( & V_479 , 0 , V_477 ) ;
switch( V_476 -> V_480 . type ) {
case V_484 :
V_476 -> V_480 . type = V_485 ;
if ( V_476 -> V_480 . V_477 < V_477 ) {
V_476 -> V_480 . V_477 = V_477 ;
return - V_486 ;
}
V_12 = V_1 -> V_39 . V_12 & ( V_487 | V_391 |
V_393 | V_488 |
V_489 | V_392 |
V_394 | V_490 ) ;
switch ( V_12 ) {
case ( V_487 | V_489 ) : V_479 . V_491 = V_492 ; break;
case ( V_393 | V_394 ) : V_479 . V_491 = V_493 ; break;
case ( V_487 | V_394 ) : V_479 . V_491 = V_494 ; break;
case ( V_487 | V_490 ) : V_479 . V_491 = V_495 ; break;
default: V_479 . V_491 = V_496 ;
}
V_479 . V_497 = V_1 -> V_39 . V_383 ;
V_479 . V_395 = V_1 -> V_39 . V_395 ? 1 : 0 ;
if ( F_214 ( line , & V_479 , V_477 ) )
return - V_247 ;
return 0 ;
case V_485 :
if( ! F_84 ( V_498 ) )
return - V_499 ;
if ( F_215 ( & V_479 , line , V_477 ) )
return - V_247 ;
switch ( V_479 . V_491 )
{
case V_492 : V_12 = V_487 | V_489 ; break;
case V_495 : V_12 = V_487 | V_490 ; break;
case V_493 : V_12 = V_393 | V_394 ; break;
case V_494 : V_12 = V_487 | V_394 ; break;
case V_496 : V_12 = V_1 -> V_39 . V_12 &
( V_487 | V_391 |
V_393 | V_488 |
V_489 | V_392 |
V_394 | V_490 ) ; break;
default: return - V_296 ;
}
if ( V_479 . V_395 != 0 && V_479 . V_395 != 1 )
return - V_296 ;
V_1 -> V_39 . V_12 &= ~ ( V_487 | V_391 |
V_393 | V_488 |
V_489 | V_392 |
V_394 | V_490 ) ;
V_1 -> V_39 . V_12 |= V_12 ;
V_1 -> V_39 . V_395 = V_479 . V_395 ;
if ( V_12 & ( V_393 | V_394 ) )
V_1 -> V_39 . V_383 = V_479 . V_497 ;
else
V_1 -> V_39 . V_383 = 0 ;
if ( V_1 -> V_141 ) {
struct V_9 * V_10 = F_45 ( & V_1 -> V_27 ) ;
F_94 ( V_1 , V_10 ) ;
F_49 ( V_10 ) ;
}
return 0 ;
default:
return F_213 ( V_357 , V_476 , V_73 ) ;
}
}
static void F_216 ( struct V_453 * V_357 )
{
T_1 * V_1 = F_202 ( V_357 ) ;
unsigned long V_12 ;
if ( V_21 >= V_22 )
F_9 ( L_139 , V_357 -> V_66 ) ;
V_357 -> V_434 . V_500 ++ ;
V_357 -> V_434 . V_501 ++ ;
F_38 ( & V_1 -> V_37 , V_12 ) ;
F_39 ( V_1 ) ;
F_40 ( & V_1 -> V_37 , V_12 ) ;
F_217 ( V_357 ) ;
}
static void F_61 ( T_1 * V_1 )
{
if ( F_218 ( V_1 -> V_164 ) )
F_217 ( V_1 -> V_164 ) ;
}
static void F_197 ( T_1 * V_1 , char * V_96 , int V_477 )
{
struct V_467 * V_468 = F_219 ( V_477 ) ;
struct V_453 * V_357 = V_1 -> V_164 ;
if ( V_21 >= V_22 )
F_9 ( L_140 , V_357 -> V_66 ) ;
if ( V_468 == NULL ) {
F_9 ( V_502 L_141 , V_357 -> V_66 ) ;
V_357 -> V_434 . V_503 ++ ;
return;
}
memcpy ( F_220 ( V_468 , V_477 ) , V_96 , V_477 ) ;
V_468 -> V_504 = F_221 ( V_468 , V_357 ) ;
V_357 -> V_434 . V_505 ++ ;
V_357 -> V_434 . V_506 += V_477 ;
F_222 ( V_468 ) ;
}
static int F_175 ( T_1 * V_1 )
{
int V_78 ;
struct V_453 * V_357 ;
T_10 * V_507 ;
V_357 = F_223 ( V_1 ) ;
if ( V_357 == NULL ) {
F_9 ( V_208 L_142 , __FILE__ ) ;
return - V_24 ;
}
V_357 -> V_508 = V_1 -> V_58 ;
V_357 -> V_62 = V_1 -> V_61 ;
V_357 -> V_509 = & V_510 ;
V_357 -> V_511 = 10 * V_33 ;
V_357 -> V_512 = 50 ;
V_507 = F_224 ( V_357 ) ;
V_507 -> V_513 = F_201 ;
V_507 -> V_449 = F_203 ;
V_78 = F_225 ( V_357 ) ;
if ( V_78 ) {
F_9 ( V_474 L_143 , __FILE__ ) ;
F_226 ( V_357 ) ;
return V_78 ;
}
V_1 -> V_164 = V_357 ;
return 0 ;
}
static void F_179 ( T_1 * V_1 )
{
F_227 ( V_1 -> V_164 ) ;
F_226 ( V_1 -> V_164 ) ;
V_1 -> V_164 = NULL ;
}
