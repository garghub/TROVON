static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_5 ) ;
F_3 ( L_1 ) ;
if ( V_6 != NULL )
V_6 ( V_4 ) ;
}
static void F_4 ( struct V_3 * V_4 )
{
F_5 ( & V_4 -> V_5 , F_1 ) ;
F_6 ( & V_4 -> V_5 ) ;
}
static void F_7 ( struct V_3 * V_4 )
{
F_8 ( & V_4 -> V_5 ) ;
}
int F_9 ( unsigned int V_7 , int V_8 )
{
long int V_9 = F_10 ( V_7 ) ;
int V_10 ;
do {
F_11 ( V_8 ? V_11 : V_12 ) ;
V_9 = F_12 ( V_9 ) ;
V_10 = V_8 ? F_13 ( V_13 ) : 0 ;
} while ( ! V_10 && V_9 );
return V_10 ;
}
static void F_14 ( struct V_3 * V_14 )
{
if ( V_14 == NULL )
return;
if ( V_14 -> V_15 != NULL ) {
F_15 ( L_2 ) ;
F_16 ( V_14 -> V_15 ) ;
V_14 -> V_15 = NULL ;
}
}
static void F_17 ( struct V_3 * V_14 , unsigned char * V_16 , int V_17 )
{
int V_18 ;
F_18 ( L_3 ) ;
for ( V_18 = 0 ; V_18 < V_17 ; V_18 ++ ) {
if ( 0 == ( V_18 % 16 ) )
F_18 ( L_4 , V_18 ) ;
F_19 ( V_19 L_5 , V_16 [ V_18 ] ) ;
if ( 15 == ( V_18 % 16 ) )
F_19 ( V_19 L_6 ) ;
}
}
void F_20 ( struct V_3 * V_14 , struct V_20 * V_21 )
{
struct V_22 V_23 ;
T_1 V_16 [ 256 ] ;
memset ( & V_23 , 0 , sizeof( V_23 ) ) ;
F_21 ( V_23 . V_24 , L_7 , sizeof( V_23 . V_24 ) ) ;
V_23 . V_25 = & V_14 -> V_26 [ 0 ] ;
V_23 . V_27 = 0xA0 >> 1 ;
memset ( V_21 , 0 , sizeof( * V_21 ) ) ;
if ( F_22 ( & V_23 , V_16 , sizeof( V_16 ) ) )
return;
switch ( V_14 -> V_28 -> type ) {
case V_29 :
case V_30 :
case V_31 :
F_23 ( & V_23 , V_21 , V_16 ) ;
break;
case V_32 :
case V_33 :
V_21 -> V_34 = 0x718 ;
F_17 ( V_14 , V_16 , sizeof( V_16 ) ) ;
F_18 ( L_8 ,
V_16 [ 2 ] , V_16 [ 1 ] , V_16 [ 4 ] , V_16 [ 3 ] ) ;
break;
default:
V_21 -> V_34 = 0xffffffff ;
F_17 ( V_14 , V_16 , sizeof( V_16 ) ) ;
break;
}
}
static void F_24 ( struct V_3 * V_14 )
{
struct V_20 V_21 ;
F_20 ( V_14 , & V_21 ) ;
switch ( V_21 . V_34 ) {
case 74301 :
case 74321 :
case 74351 :
case 74361 :
V_14 -> V_28 = F_25 ( V_31 ) ;
break;
case 74021 :
case 74031 :
case 74041 :
case 74141 :
case 74541 :
case 74551 :
case 74591 :
case 74651 :
case 74691 :
case 74751 :
case 74891 :
V_14 -> V_28 = F_25 ( V_29 ) ;
break;
case 0x718 :
return;
case 0xffffffff :
F_18 ( L_9 ) ;
return;
case 0 :
F_26 ( L_10 ) ;
return;
default:
F_26 ( L_11
L_12 , V_21 . V_34 ) ;
V_14 -> V_28 = F_25 ( V_29 ) ;
break;
}
V_14 -> V_35 = V_14 -> V_28 -> V_36 ;
V_14 -> V_37 = V_14 -> V_28 -> V_24 ;
V_14 -> V_38 = V_14 -> V_28 -> V_39 ;
F_18 ( L_13 , V_14 -> V_37 ) ;
if ( V_21 . V_40 == V_41 )
F_26 ( L_14 ) ;
if ( V_14 -> V_42 . V_43 == - 1 )
V_14 -> V_42 . V_43 = V_21 . V_40 ;
if ( V_14 -> V_42 . V_44 == - 1 )
V_14 -> V_42 . V_44 = ( V_21 . V_45 != 0 ) ;
if ( V_14 -> V_46 != 0 )
return;
#define F_27 (V4L2_STD_B | V4L2_STD_GH | \
V4L2_STD_MN | \
V4L2_STD_PAL_I | \
V4L2_STD_SECAM_L | V4L2_STD_SECAM_LC | \
V4L2_STD_DK)
if ( ( V_21 . V_47 & F_27 )
== F_27 ) {
F_15 ( L_15 ) ;
V_14 -> V_46 = V_48 ;
} else if ( V_21 . V_47 & V_49 ) {
F_15 ( L_16 ) ;
V_14 -> V_46 |= V_50 | V_51 ;
} else if ( V_21 . V_47 & V_52 ) {
F_15 ( L_17 ) ;
V_14 -> V_46 |= V_53 ;
} else if ( V_21 . V_47 & V_54 ) {
F_15 ( L_18 ) ;
V_14 -> V_46 |= V_55 ;
} else {
F_18 ( L_19 ) ;
V_14 -> V_46 |= V_53 ;
}
}
static T_2 F_28 ( struct V_3 * V_14 )
{
switch ( V_56 [ 0 ] ) {
case '6' :
return V_57 ;
case 'b' :
case 'B' :
case 'g' :
case 'G' :
return V_50 ;
case 'h' :
case 'H' :
return V_51 ;
case 'n' :
case 'N' :
if ( V_56 [ 1 ] == 'c' || V_56 [ 1 ] == 'C' )
return V_58 ;
return V_59 ;
case 'i' :
case 'I' :
return V_60 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_61 ;
case 'M' :
case 'm' :
return V_62 ;
case '-' :
break;
default:
F_29 ( L_20 ) ;
return 0 ;
}
switch ( V_63 [ 0 ] ) {
case 'b' :
case 'B' :
case 'g' :
case 'G' :
case 'h' :
case 'H' :
return V_64 | V_65 | V_66 ;
case 'd' :
case 'D' :
case 'k' :
case 'K' :
return V_67 ;
case 'l' :
case 'L' :
if ( V_63 [ 1 ] == 'C' || V_63 [ 1 ] == 'c' )
return V_68 ;
return V_55 ;
case '-' :
break;
default:
F_29 ( L_21 ) ;
return 0 ;
}
switch ( V_69 [ 0 ] ) {
case 'm' :
case 'M' :
return V_53 ;
case 'j' :
case 'J' :
return V_70 ;
case 'k' :
case 'K' :
return V_71 ;
case '-' :
break;
default:
F_29 ( L_22 ) ;
return 0 ;
}
return 0 ;
}
static void F_30 ( struct V_3 * V_14 )
{
int V_18 , V_72 ;
V_14 -> V_42 . V_73 [ V_74 ] = V_75 ;
V_14 -> V_42 . V_73 [ V_76 ] = V_77 ;
V_14 -> V_42 . V_73 [ V_78 ] = V_79 ;
V_14 -> V_42 . V_73 [ V_80 ] = V_81 ;
V_14 -> V_42 . V_73 [ V_82 ] = V_83 ;
V_14 -> V_42 . V_73 [ V_84 ] = V_85 ;
V_14 -> V_42 . V_73 [ V_86 ] = 0 ;
V_14 -> V_87 [ V_74 ] = V_88 ;
V_14 -> V_87 [ V_76 ] = V_89 ;
V_14 -> V_87 [ V_78 ] = V_90 ;
V_14 -> V_87 [ V_80 ] = V_91 ;
V_14 -> V_87 [ V_82 ] = V_92 ;
V_14 -> V_87 [ V_84 ] = V_93 ;
V_14 -> V_87 [ V_86 ] = 0 ;
V_14 -> V_94 [ V_74 ] = V_95 ;
V_14 -> V_94 [ V_76 ] = V_96 ;
V_14 -> V_94 [ V_78 ] = V_97 ;
V_14 -> V_94 [ V_80 ] = V_98 ;
V_14 -> V_94 [ V_82 ] = V_99 * 36 ;
V_14 -> V_94 [ V_84 ] = V_100 ;
V_14 -> V_94 [ V_86 ] = 0 ;
for ( V_18 = 0 ; V_18 < V_101 ; V_18 ++ ) {
if ( V_14 -> V_87 [ V_18 ] == 0 ||
V_14 -> V_42 . V_73 [ V_18 ] <= 0 ||
V_14 -> V_94 [ V_18 ] <= 0 ) {
V_14 -> V_42 . V_73 [ V_18 ] = 0 ;
V_14 -> V_87 [ V_18 ] = 0 ;
V_14 -> V_94 [ V_18 ] = 0 ;
continue;
}
if ( V_18 == V_80 ) {
V_14 -> V_94 [ V_18 ] *= 1024 ;
V_14 -> V_94 [ V_18 ] -=
( V_14 -> V_94 [ V_18 ] % V_102 ) ;
if ( V_14 -> V_94 [ V_18 ] < V_102 )
V_14 -> V_94 [ V_18 ] =
V_102 ;
} else if ( V_18 == V_78 ) {
V_14 -> V_94 [ V_18 ] *= 1024 ;
V_14 -> V_94 [ V_18 ] -=
( V_14 -> V_94 [ V_18 ] % V_103 ) ;
if ( V_14 -> V_94 [ V_18 ] < V_103 )
V_14 -> V_94 [ V_18 ] =
V_103 ;
}
if ( V_18 == V_82 ||
V_18 == V_80 ||
V_18 == V_78 ) {
if ( V_14 -> V_87 [ V_18 ] < 0 ) {
V_14 -> V_87 [ V_18 ] =
V_14 -> V_42 . V_73 [ V_18 ] * 1024 * 1024
/ V_14 -> V_94 [ V_18 ] ;
} else {
V_14 -> V_42 . V_73 [ V_18 ] =
V_14 -> V_87 [ V_18 ]
* V_14 -> V_94 [ V_18 ] / ( 1024 * 1024 ) ;
}
} else {
if ( V_14 -> V_87 [ V_18 ] < 0 ) {
V_14 -> V_87 [ V_18 ] =
V_14 -> V_42 . V_73 [ V_18 ] * 1024
/ V_14 -> V_94 [ V_18 ] ;
} else {
V_14 -> V_42 . V_73 [ V_18 ] =
V_14 -> V_87 [ V_18 ]
* V_14 -> V_94 [ V_18 ] / 1024 ;
}
V_14 -> V_94 [ V_18 ] *= 1024 ;
}
F_15 ( L_23
L_24 , V_18 , V_14 -> V_42 . V_73 [ V_18 ] ,
V_14 -> V_87 [ V_18 ] , V_14 -> V_94 [ V_18 ] ) ;
}
V_14 -> V_42 . V_104 = V_104 [ V_14 -> V_105 ] ;
V_14 -> V_42 . V_43 = V_43 [ V_14 -> V_105 ] ;
V_14 -> V_42 . V_44 = V_44 [ V_14 -> V_105 ] ;
V_14 -> V_46 = F_28 ( V_14 ) ;
if ( V_14 -> V_42 . V_104 == - 1 ) {
F_18 ( L_25 ) ;
return;
}
V_14 -> V_28 = F_25 ( V_14 -> V_42 . V_104 - 1 ) ;
if ( V_14 -> V_28 )
F_18 ( L_26 , V_14 -> V_28 -> V_24 ) ;
else if ( V_14 -> V_42 . V_104 != 0 )
F_26 ( L_27 ) ;
if ( V_14 -> V_28 == NULL ) {
if ( V_14 -> V_106 -> V_107 == V_108 ) {
V_14 -> V_28 = F_25 ( V_29 ) ;
F_18 ( L_28 ) ;
}
}
if ( V_14 -> V_28 == NULL ) {
for ( V_18 = 0 ; ( V_14 -> V_28 = F_25 ( V_18 ) ) ; V_18 ++ ) {
if ( V_14 -> V_28 -> V_109 == NULL )
continue;
for ( V_72 = 0 ; V_14 -> V_28 -> V_109 [ V_72 ] . V_110 ; V_72 ++ ) {
if ( V_14 -> V_106 -> V_110 !=
V_14 -> V_28 -> V_109 [ V_72 ] . V_110 )
continue;
if ( V_14 -> V_106 -> V_107 !=
V_14 -> V_28 -> V_109 [ V_72 ] . V_107 )
continue;
if ( V_14 -> V_106 -> V_111 !=
V_14 -> V_28 -> V_109 [ V_72 ] . V_111 )
continue;
F_18 ( L_29 , V_14 -> V_28 -> V_24 ) ;
goto V_112;
}
}
}
V_112:
if ( V_14 -> V_28 == NULL ) {
V_14 -> V_28 = F_25 ( V_29 ) ;
F_26 ( L_30 ,
V_14 -> V_106 -> V_113 , V_14 -> V_106 -> V_110 ) ;
F_26 ( L_31 ,
V_14 -> V_106 -> V_107 ,
V_14 -> V_106 -> V_111 ) ;
F_26 ( L_32 , V_14 -> V_28 -> V_24 ) ;
F_26 ( L_33 ) ;
F_26 ( L_34 ) ;
F_26 ( L_35 ) ;
}
V_14 -> V_35 = V_14 -> V_28 -> V_36 ;
V_14 -> V_37 = V_14 -> V_28 -> V_24 ;
V_14 -> V_38 = V_14 -> V_28 -> V_39 ;
}
static int T_3 F_31 ( struct V_3 * V_14 )
{
snprintf ( V_14 -> V_114 , sizeof( V_14 -> V_114 ) , L_36 ,
V_14 -> V_115 . V_24 ) ;
V_14 -> V_116 = F_32 ( V_14 -> V_114 , 0 ) ;
if ( V_14 -> V_116 == NULL ) {
F_26 ( L_37 ) ;
return - V_117 ;
}
return 0 ;
}
static void T_3 F_33 ( struct V_3 * V_14 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_118 ; V_18 ++ ) {
V_14 -> V_119 [ V_18 ] . V_14 = V_14 ;
V_14 -> V_119 [ V_18 ] . V_120 = V_14 -> V_121 ;
F_5 ( & V_14 -> V_119 [ V_18 ] . V_2 , V_122 ) ;
}
}
static int T_3 F_34 ( struct V_3 * V_14 )
{
int V_123 ;
V_14 -> V_124 = F_35 ( V_14 -> V_106 , 0 ) ;
F_36 ( & V_14 -> V_125 ) ;
F_36 ( & V_14 -> V_126 ) ;
F_36 ( & V_14 -> V_127 ) ;
F_36 ( & V_14 -> V_128 ) ;
V_123 = F_31 ( V_14 ) ;
if ( V_123 )
return V_123 ;
F_33 ( V_14 ) ;
V_14 -> V_129 = 1 ;
V_14 -> V_130 . V_131 = V_132 ;
V_14 -> V_130 . V_133 = V_134 | V_135 ;
V_14 -> V_130 . V_136 = & V_137 ;
V_14 -> V_130 . V_138 = V_139 ;
V_14 -> V_130 . V_140 = & V_14 -> V_141 [ V_76 ] ;
V_123 = F_37 ( & V_14 -> V_130 , 50 ) ;
if ( V_123 )
return V_123 ;
V_14 -> V_115 . V_142 = & V_14 -> V_130 . V_143 ;
V_14 -> V_144 = V_14 -> V_130 . V_145 -> V_146 . V_147 ;
V_14 -> V_148 = V_14 -> V_130 . V_149 -> V_146 . V_147 ;
V_14 -> V_150 = V_14 -> V_130 . V_151 -> V_146 . V_147 |
( V_14 -> V_130 . V_152 -> V_146 . V_147 << 1 ) |
( V_14 -> V_130 . V_153 -> V_146 . V_147 << 2 ) ;
F_38 ( & V_14 -> V_154 ) ;
F_38 ( & V_14 -> V_155 ) ;
F_38 ( & V_14 -> V_156 ) ;
F_38 ( & V_14 -> V_157 ) ;
V_14 -> V_158 . V_159 . type = V_160 ;
V_14 -> V_158 . V_161 = & V_14 -> V_158 . V_159 . V_162 . V_163 ;
F_39 ( & V_14 -> V_158 . V_164 . V_165 ) ;
F_39 ( & V_14 -> V_158 . V_166 . V_165 ) ;
F_39 ( & V_14 -> V_158 . V_166 . V_167 ) ;
F_40 ( & V_14 -> V_158 . V_164 . V_165 ,
& V_14 -> V_158 . V_166 . V_167 ) ;
return 0 ;
}
static void T_3 F_41 ( struct V_3 * V_14 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_168 ; V_18 ++ )
if ( V_14 -> V_28 -> V_169 [ V_18 ] . V_170 == 0 )
break;
V_14 -> V_171 = V_18 ;
for ( V_18 = 0 ; V_18 < V_172 ; V_18 ++ )
if ( V_14 -> V_28 -> V_173 [ V_18 ] . V_174 == 0 )
break;
V_14 -> V_175 = V_18 ;
for ( V_18 = 0 ; V_18 < V_14 -> V_171 ; V_18 ++ ) {
if ( V_14 -> V_28 -> V_169 [ V_18 ] . V_170 ==
V_176 )
break;
}
if ( V_18 == V_14 -> V_171 )
V_18 = 0 ;
V_14 -> V_177 = V_18 ;
V_14 -> V_178 = V_14 -> V_28 -> V_169 [ V_18 ] . V_179 ;
}
static int F_42 ( struct V_3 * V_14 , struct V_106 * V_106 ,
const struct V_180 * V_181 )
{
T_4 V_182 ;
unsigned char V_183 ;
F_15 ( L_38 ) ;
if ( F_43 ( V_106 ) ) {
F_26 ( L_39 , V_14 -> V_105 ) ;
return - V_184 ;
}
if ( F_44 ( V_106 , F_45 ( 32 ) ) ) {
F_26 ( L_40 , V_14 -> V_105 ) ;
return - V_184 ;
}
if ( ! F_46 ( V_14 -> V_124 , V_185 , L_41 ) ) {
F_26 ( L_42 ,
V_14 -> V_105 ) ;
return - V_184 ;
}
F_47 ( V_106 , V_186 , & V_182 ) ;
V_182 |= V_187 | V_188 ;
F_48 ( V_106 , V_186 , V_182 ) ;
V_14 -> V_189 = V_106 -> V_190 ;
F_49 ( V_106 , V_191 , & V_183 ) ;
if ( V_183 < 64 && V_192 ) {
F_18 ( L_43
L_44 , V_183 ) ;
F_50 ( V_106 , V_191 , 64 ) ;
F_49 ( V_106 , V_191 , & V_183 ) ;
}
F_15 ( L_45
L_46 ,
V_14 -> V_106 -> V_110 , V_14 -> V_189 , V_106 -> V_193 -> V_194 ,
F_51 ( V_106 -> V_195 ) , F_52 ( V_106 -> V_195 ) ,
V_14 -> V_106 -> V_196 , V_183 , ( V_197 ) V_14 -> V_124 ) ;
return 0 ;
}
static void F_53 ( struct V_3 * V_14 )
{
T_5 V_198 = V_14 -> V_28 -> V_199 ;
T_5 V_110 ;
int V_18 ;
for ( V_18 = 0 , V_110 = 1 ; V_18 < 32 ; V_18 ++ , V_110 <<= 1 ) {
if ( ! ( V_110 & V_198 ) )
continue;
switch ( V_110 ) {
case V_200 :
case V_201 :
V_14 -> V_202 |= V_110 ;
break;
case V_203 :
V_14 -> V_202 |= V_110 ;
break;
case V_204 :
break;
case V_205 :
if ( F_54 ( V_14 , V_110 ) == 0 )
V_14 -> V_202 |= V_110 ;
break;
default:
if ( F_55 ( V_14 , V_18 ) == 0 )
V_14 -> V_202 |= V_110 ;
break;
}
}
if ( V_14 -> V_202 & V_203 )
V_14 -> V_206 = F_56 ( V_14 , V_203 ) ;
if ( V_14 -> V_28 -> V_207 != 0 )
V_14 -> V_208 = F_56 ( V_14 , V_14 -> V_28 -> V_207 ) ;
}
static int T_3 F_57 ( struct V_106 * V_106 ,
const struct V_180 * V_181 )
{
int V_209 = 0 ;
int V_18 ;
T_5 V_210 ;
struct V_3 * V_14 ;
V_18 = F_58 ( & V_211 ) - 1 ;
if ( V_18 >= V_212 ) {
F_19 ( V_213 L_47
L_48 , V_18 , V_212 - 1 ) ;
return - V_117 ;
}
V_14 = F_59 ( sizeof( struct V_3 ) , V_214 ) ;
if ( V_14 == NULL ) {
F_19 ( V_213 L_49 ,
V_18 ) ;
return - V_117 ;
}
V_14 -> V_106 = V_106 ;
V_14 -> V_105 = V_18 ;
V_209 = F_60 ( & V_106 -> V_4 , & V_14 -> V_115 ) ;
if ( V_209 ) {
F_19 ( V_213 L_50
L_6 , V_14 -> V_105 ) ;
F_61 ( V_14 ) ;
return V_209 ;
}
snprintf ( V_14 -> V_115 . V_24 , sizeof( V_14 -> V_115 . V_24 ) , L_51 ,
V_14 -> V_105 ) ;
F_18 ( L_52 , V_14 -> V_105 ) ;
F_30 ( V_14 ) ;
if ( V_14 -> V_42 . V_104 == - 1 ) {
V_209 = - V_215 ;
goto V_216;
}
V_209 = F_34 ( V_14 ) ;
if ( V_209 )
goto V_216;
F_15 ( L_53 , ( V_197 ) V_14 -> V_124 ) ;
V_209 = F_42 ( V_14 , V_106 , V_181 ) ;
if ( V_209 != 0 )
goto V_217;
F_15 ( L_54 ,
( V_197 ) V_14 -> V_124 + V_218 , V_185 ) ;
V_14 -> V_15 = F_62 ( V_14 -> V_124 + V_218 ,
V_185 ) ;
if ( ! V_14 -> V_15 ) {
F_26 ( L_55
L_56 ) ;
F_26 ( L_57
L_58 ) ;
F_26 ( L_59 ) ;
F_26 ( L_60
L_61 ) ;
V_209 = - V_117 ;
goto V_219;
}
V_14 -> V_220 = V_14 -> V_15 + V_221 ;
V_210 = F_63 ( V_14 , 0xC72028 ) ;
switch ( V_210 & 0xff000000 ) {
case 0xff000000 :
F_18 ( L_62 , V_210 ) ;
break;
case 0x01000000 :
F_18 ( L_63 , V_210 ) ;
break;
default:
F_18 ( L_64 , V_210 ) ;
break;
}
F_64 ( V_14 , 1 ) ;
F_65 ( V_14 ) ;
V_14 -> V_222 = (struct V_223 V_224 * ) ( V_14 -> V_15 + V_225 ) ;
F_66 ( V_14 ) ;
F_67 ( V_14 ) ;
V_209 = F_68 ( V_14 ) ;
if ( V_209 ) {
F_26 ( L_65 ) ;
goto V_226;
}
if ( V_14 -> V_28 -> V_199 & V_204 ) {
if ( F_54 ( V_14 , V_204 ) != 0 )
F_29 ( L_66
L_67 ) ;
else
V_14 -> V_202 |= V_204 ;
}
F_15 ( L_68 ) ;
V_209 = F_69 ( V_14 ) ;
if ( V_209 ) {
F_26 ( L_69 ) ;
goto V_226;
}
if ( V_14 -> V_28 -> V_199 & V_201 ) {
const struct V_227 * V_228 = V_14 -> V_28 ;
F_24 ( V_14 ) ;
if ( V_14 -> V_28 != V_228 ) {
F_67 ( V_14 ) ;
F_70 ( V_14 , V_204 ,
V_229 , V_230 , ( T_5 ) V_231 ) ;
}
}
if ( V_14 -> V_28 -> V_232 )
F_18 ( L_70 , V_14 -> V_28 -> V_232 ) ;
if ( V_14 -> V_28 -> V_36 == 0 ) {
V_209 = - V_215 ;
goto V_233;
}
F_65 ( V_14 ) ;
F_66 ( V_14 ) ;
V_209 = F_71 ( V_14 -> V_106 -> V_196 , V_234 ,
V_235 | V_236 ,
V_14 -> V_115 . V_24 , ( void * ) V_14 ) ;
if ( V_209 ) {
F_26 ( L_71 , V_209 ) ;
goto V_233;
}
if ( V_14 -> V_46 == 0 )
V_14 -> V_46 = V_53 ;
if ( V_14 -> V_42 . V_43 == - 1 ) {
for ( V_18 = 0 ; V_18 < V_237 ; V_18 ++ ) {
if ( ( V_14 -> V_46 & V_14 -> V_28 -> V_238 [ V_18 ] . V_46 ) == 0 )
continue;
V_14 -> V_42 . V_43 = V_14 -> V_28 -> V_238 [ V_18 ] . V_43 ;
break;
}
}
if ( V_14 -> V_42 . V_43 == - 1 && V_14 -> V_28 -> V_238 [ 0 ] . V_46 ) {
V_14 -> V_46 = V_14 -> V_28 -> V_238 [ 0 ] . V_46 ;
if ( V_14 -> V_46 & V_49 )
V_14 -> V_46 = V_50 | V_51 ;
else if ( V_14 -> V_46 & V_52 )
V_14 -> V_46 = V_53 ;
else if ( V_14 -> V_46 & V_54 )
V_14 -> V_46 = V_55 ;
V_14 -> V_42 . V_43 = V_14 -> V_28 -> V_238 [ 0 ] . V_43 ;
}
if ( V_14 -> V_42 . V_44 == - 1 )
V_14 -> V_42 . V_44 = ( V_14 -> V_28 -> V_239 . V_174 != 0 ) ;
F_41 ( V_14 ) ;
F_53 ( V_14 ) ;
if ( V_14 -> V_46 & V_240 )
V_14 -> V_241 = 1 ;
else
V_14 -> V_242 = 1 ;
F_72 ( & V_14 -> V_130 , ! V_14 -> V_241 ) ;
if ( V_14 -> V_42 . V_44 > 0 )
V_14 -> V_35 |= V_243 ;
if ( V_14 -> V_42 . V_43 > - 1 ) {
struct V_244 V_245 ;
V_245 . V_27 = V_246 ;
V_245 . type = V_14 -> V_42 . V_43 ;
V_245 . V_247 = V_248 ;
if ( V_14 -> V_42 . V_44 > 0 )
V_245 . V_247 |= V_249 ;
V_245 . V_250 = ( V_245 . type == V_251 ) ?
V_252 : NULL ;
F_73 ( V_14 , V_43 , V_253 , & V_245 ) ;
if ( V_245 . type == V_251 ) {
static struct V_254 V_255 = {
. V_256 = V_257 ,
. V_258 = 64 ,
} ;
struct V_259 V_260 = {
. V_43 = V_14 -> V_42 . V_43 ,
. V_140 = & V_255 ,
} ;
F_73 ( V_14 , V_43 , V_261 , & V_260 ) ;
}
}
V_14 -> V_262 = V_14 -> V_46 ;
if ( V_14 -> V_46 == V_48 )
V_14 -> V_46 = V_53 ;
V_209 = F_74 ( V_14 ) ;
if ( V_209 ) {
F_26 ( L_72 , V_209 ) ;
goto V_263;
}
V_209 = F_75 ( V_14 ) ;
if ( V_209 ) {
F_26 ( L_73 , V_209 ) ;
goto V_264;
}
F_18 ( L_74 , V_14 -> V_37 ) ;
F_4 ( V_14 ) ;
return 0 ;
V_264:
F_76 ( V_14 , 1 ) ;
V_263:
V_263 ( V_14 -> V_106 -> V_196 , ( void * ) V_14 ) ;
V_233:
F_77 ( V_14 ) ;
V_226:
F_14 ( V_14 ) ;
V_219:
F_78 ( V_14 -> V_124 , V_185 ) ;
V_217:
F_79 ( V_14 -> V_116 ) ;
V_216:
if ( V_209 == 0 )
V_209 = - V_215 ;
F_26 ( L_75 , V_209 ) ;
F_80 ( & V_14 -> V_115 ) ;
F_61 ( V_14 ) ;
return V_209 ;
}
int F_81 ( struct V_3 * V_14 )
{
int V_265 ;
int V_266 = 3 ;
struct V_267 V_268 ;
struct V_269 V_270 ;
T_2 V_46 ;
V_270 . V_14 = V_14 ;
if ( F_82 ( V_271 , & V_14 -> V_272 ) )
return - V_273 ;
if ( F_83 ( V_274 , & V_14 -> V_272 ) )
return 0 ;
while ( -- V_266 > 0 ) {
if ( F_84 ( V_14 ) == 0 )
break;
if ( V_266 > 1 )
F_29 ( L_76 ) ;
}
if ( V_266 == 0 ) {
F_85 ( V_271 , & V_14 -> V_272 ) ;
return - V_273 ;
}
F_85 ( V_275 , & V_14 -> V_272 ) ;
F_86 ( V_14 , V_276 , 2 , V_277 | 0xb9 , 0 ) ;
F_86 ( V_14 , V_278 , 0 ) ;
F_86 ( V_14 , V_279 , 1 , V_277 ) ;
V_266 = 3 ;
while ( -- V_266 > 0 ) {
if ( F_84 ( V_14 ) == 0 )
break;
if ( V_266 > 1 )
F_29 ( L_76 ) ;
}
if ( V_266 == 0 ) {
F_85 ( V_271 , & V_14 -> V_272 ) ;
return - V_273 ;
}
F_86 ( V_14 , V_276 , 2 , V_277 | 0xb9 , 0 ) ;
F_86 ( V_14 , V_278 , 0 ) ;
F_86 ( V_14 , V_279 , 1 , V_277 ) ;
F_87 ( V_14 -> V_206 , V_229 , V_280 ) ;
V_268 . V_43 = 0 ;
V_268 . type = V_281 ;
V_268 . V_282 = 6400 ;
if ( V_14 -> V_46 == V_70 )
V_268 . V_282 = 1460 ;
else if ( V_14 -> V_46 & V_53 )
V_268 . V_282 = 1076 ;
V_265 = V_14 -> V_177 ;
V_14 -> V_177 ++ ;
F_88 ( NULL , & V_270 , V_265 ) ;
V_14 -> V_46 ++ ;
V_46 = ( V_14 -> V_262 == V_48 ) ? V_53 : V_14 -> V_262 ;
F_89 ( NULL , & V_270 , & V_46 ) ;
F_90 ( NULL , & V_270 , & V_268 ) ;
return 0 ;
}
static void F_91 ( struct V_3 * V_14 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_118 ; V_18 ++ )
F_92 ( & V_14 -> V_119 [ V_18 ] . V_2 ) ;
}
static void F_93 ( struct V_3 * V_14 )
{
int V_18 ;
for ( V_18 = 0 ; V_18 < V_101 ; V_18 ++ )
if ( & V_14 -> V_141 [ V_18 ] . V_283 != NULL )
F_92 ( & V_14 -> V_141 [ V_18 ] . V_284 ) ;
}
static void F_94 ( struct V_106 * V_106 )
{
struct V_285 * V_115 = F_95 ( V_106 ) ;
struct V_3 * V_14 = F_96 ( V_115 ) ;
int V_18 ;
F_15 ( L_77 ) ;
F_7 ( V_14 ) ;
F_15 ( L_78 ) ;
if ( F_97 ( & V_14 -> V_286 ) > 0 )
F_98 ( V_14 ) ;
F_99 ( V_14 , V_287 | V_288 ) ;
F_91 ( V_14 ) ;
F_93 ( V_14 ) ;
F_100 ( V_14 , V_289 | V_290 ) ;
F_101 ( V_14 ) ;
F_79 ( V_14 -> V_116 ) ;
F_76 ( V_14 , 1 ) ;
F_77 ( V_14 ) ;
V_263 ( V_14 -> V_106 -> V_196 , ( void * ) V_14 ) ;
F_14 ( V_14 ) ;
F_78 ( V_14 -> V_124 , V_185 ) ;
F_102 ( V_14 -> V_106 ) ;
if ( V_14 -> V_158 . V_291 [ 0 ] != NULL )
for ( V_18 = 0 ; V_18 < V_292 ; V_18 ++ )
F_61 ( V_14 -> V_158 . V_291 [ V_18 ] ) ;
F_103 ( & V_14 -> V_293 . V_143 ) ;
F_18 ( L_79 , V_14 -> V_37 ) ;
F_80 ( V_115 ) ;
F_61 ( V_14 ) ;
}
static int T_6 F_104 ( void )
{
F_19 ( V_294 L_80 ,
V_295 ) ;
if ( V_296 < 0 || V_296 >= V_212 ) {
F_19 ( V_213 L_81 ,
V_212 - 1 ) ;
return - 1 ;
}
if ( V_297 < 0 || V_297 > 511 ) {
V_297 = 0 ;
F_19 ( V_294 L_82 ) ;
}
if ( F_105 ( & V_298 ) ) {
F_19 ( V_213 L_83 ) ;
return - V_215 ;
}
F_19 ( V_294 L_84 ) ;
return 0 ;
}
static void T_7 F_106 ( void )
{
F_107 ( & V_298 ) ;
}
