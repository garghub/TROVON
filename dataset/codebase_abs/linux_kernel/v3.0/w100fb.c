static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
return sprintf ( V_5 , L_1 , V_9 -> V_10 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 , struct V_3 * V_4 , const char * V_5 , T_2 V_11 )
{
unsigned int V_10 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
V_10 = F_4 ( V_5 , NULL , 10 ) ;
if ( V_10 > 0 )
V_9 -> V_10 = 1 ;
else
V_9 -> V_10 = 0 ;
F_5 () ;
F_6 ( V_9 ) ;
F_7 () ;
F_8 ( V_9 ) ;
return V_11 ;
}
static T_1 F_9 ( struct V_1 * V_2 , struct V_3 * V_4 , const char * V_5 , T_2 V_11 )
{
unsigned long V_12 , V_13 ;
V_12 = F_4 ( V_5 , NULL , 16 ) ;
V_13 = F_10 ( V_14 + V_12 ) ;
F_11 ( L_2 , V_12 , V_13 ) ;
return V_11 ;
}
static T_1 F_12 ( struct V_1 * V_2 , struct V_3 * V_4 , const char * V_5 , T_2 V_11 )
{
unsigned long V_12 , V_13 ;
sscanf ( V_5 , L_3 , & V_12 , & V_13 ) ;
if ( V_12 <= 0x2000 ) {
F_11 ( L_4 , V_12 , V_13 ) ;
F_13 ( V_13 , V_14 + V_12 ) ;
}
return V_11 ;
}
static T_1 F_14 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
return sprintf ( V_5 , L_1 , V_9 -> V_15 ) ;
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_3 * V_4 , const char * V_5 , T_2 V_11 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
if ( F_4 ( V_5 , NULL , 10 ) > 0 ) {
V_9 -> V_15 = 1 ;
F_11 ( L_5 ) ;
} else {
V_9 -> V_15 = 0 ;
F_11 ( L_6 ) ;
}
F_16 ( V_9 ) ;
F_8 ( V_9 ) ;
return V_11 ;
}
unsigned long F_17 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_9 -> V_16 )
return 0 ;
else
return V_9 -> V_17 ;
}
static void F_18 ( struct V_8 * V_9 )
{
F_19 ( V_18 + ( V_19 - V_20 ) , 0 , ( V_9 -> V_21 * V_9 -> V_22 * V_23 / 8 ) ) ;
}
static int F_20 ( T_3 V_24 , T_3 V_25 , T_3 V_26 , T_3 V_27 ,
T_3 V_28 , struct V_6 * V_7 )
{
unsigned int V_29 ;
int V_30 = 1 ;
if ( V_7 -> V_31 . V_32 )
V_25 = V_26 = V_27 = ( 19595 * V_25 + 38470 * V_26 + 7471 * V_27 ) >> 16 ;
if ( V_24 < V_33 ) {
T_4 * V_34 = V_7 -> V_35 ;
V_29 = ( V_25 & 0xf800 ) | ( ( V_26 & 0xfc00 ) >> 5 ) | ( ( V_27 & 0xf800 ) >> 11 ) ;
V_34 [ V_24 ] = V_29 ;
V_30 = 0 ;
}
return V_30 ;
}
static int F_21 ( int V_36 , struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_37 * V_38 = V_9 -> V_39 -> V_38 ;
switch( V_36 ) {
case V_40 :
case V_41 :
case V_42 :
case V_43 :
if ( V_9 -> V_16 == 0 ) {
if( V_38 && V_38 -> V_44 )
V_38 -> V_44 ( V_9 ) ;
V_9 -> V_16 = 1 ;
}
break;
case V_45 :
if ( V_9 -> V_16 != 0 ) {
if( V_38 && V_38 -> V_46 )
V_38 -> V_46 ( V_9 ) ;
V_9 -> V_16 = 0 ;
}
break;
}
return 0 ;
}
static void F_22 ( int V_47 )
{
union V_48 V_49 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < 2000000 ; V_50 ++ ) {
V_49 . V_29 = F_10 ( V_14 + V_51 ) ;
if ( V_49 . V_52 . V_53 >= V_47 )
return;
F_23 ( 1 ) ;
}
F_11 ( V_54 L_7 ) ;
}
static int F_24 ( struct V_6 * V_7 )
{
union V_48 V_49 ;
int V_50 ;
for ( V_50 = 0 ; V_50 < 2000000 ; V_50 ++ ) {
V_49 . V_29 = F_10 ( V_14 + V_51 ) ;
if ( ! V_49 . V_52 . V_55 )
return 0 ;
F_23 ( 1 ) ;
}
F_11 ( V_54 L_8 ) ;
return - V_56 ;
}
static void F_25 ( struct V_8 * V_9 )
{
union V_57 V_58 ;
union V_59 V_60 ;
union V_61 V_62 ;
union V_63 V_64 ;
F_22 ( 4 ) ;
F_13 ( V_19 , V_14 + V_65 ) ;
F_13 ( V_9 -> V_21 , V_14 + V_66 ) ;
F_13 ( V_19 , V_14 + V_67 ) ;
F_13 ( V_9 -> V_21 , V_14 + V_68 ) ;
F_22 ( 3 ) ;
F_13 ( 0 , V_14 + V_69 ) ;
F_13 ( ( V_9 -> V_22 << 16 ) | V_9 -> V_21 , V_14 + V_70 ) ;
F_13 ( 0x1fff1fff , V_14 + V_71 ) ;
F_22 ( 4 ) ;
V_64 . V_29 = 0 ;
V_64 . V_52 . V_72 = 1 ;
V_64 . V_52 . V_73 = 1 ;
V_64 . V_52 . V_74 = 1 ;
V_64 . V_52 . V_75 = 1 ;
V_64 . V_52 . V_76 = 1 ;
V_64 . V_52 . V_77 = 1 ;
F_13 ( V_64 . V_29 , V_14 + V_78 ) ;
V_58 . V_29 = 0 ;
V_58 . V_52 . V_79 = 1 ;
V_58 . V_52 . V_80 = 1 ;
V_58 . V_52 . V_81 = 1 ;
V_58 . V_52 . V_82 = 1 ;
V_58 . V_52 . V_83 = V_84 ;
V_58 . V_52 . V_85 = 3 ;
V_58 . V_52 . V_86 = V_87 ;
V_58 . V_52 . V_88 = 1 ;
V_58 . V_52 . V_89 = 0 ;
V_58 . V_52 . V_90 = V_91 ;
V_58 . V_52 . V_92 = V_93 ;
V_58 . V_52 . V_94 = 1 ;
V_58 . V_52 . V_95 = 1 ;
V_58 . V_52 . V_96 = V_97 ;
F_13 ( V_58 . V_29 , V_14 + V_98 ) ;
V_62 . V_29 = V_60 . V_29 = 0 ;
V_62 . V_52 . V_99 = V_58 . V_52 . V_85 ;
V_62 . V_52 . V_100 = V_58 . V_52 . V_83 ;
V_62 . V_52 . V_101 = 0 ;
V_62 . V_52 . V_102 = V_58 . V_52 . V_86 ;
V_62 . V_52 . V_103 = V_58 . V_52 . V_86 ;
V_62 . V_52 . V_104 = V_58 . V_52 . V_88 ;
F_13 ( V_62 . V_29 , V_14 + V_105 ) ;
V_60 . V_52 . V_106 = V_58 . V_52 . V_92 ;
V_60 . V_52 . V_107 = 1 ;
V_60 . V_52 . V_108 = V_58 . V_52 . V_90 ;
V_60 . V_52 . V_109 = V_58 . V_52 . V_96 ;
F_13 ( V_60 . V_29 , V_14 + V_110 ) ;
}
static void F_26 ( struct V_6 * V_7 ,
const struct V_111 * V_112 )
{
union V_57 V_58 ;
if ( V_7 -> V_113 != V_114 )
return;
if ( V_7 -> V_115 & V_116 ) {
F_27 ( V_7 , V_112 ) ;
return;
}
V_58 . V_29 = F_10 ( V_14 + V_98 ) ;
V_58 . V_52 . V_90 = V_117 ;
V_58 . V_52 . V_83 = V_118 ;
F_22 ( 2 ) ;
F_13 ( V_58 . V_29 , V_14 + V_98 ) ;
F_13 ( V_112 -> V_119 , V_14 + V_120 ) ;
F_22 ( 2 ) ;
F_13 ( ( V_112 -> V_121 << 16 ) | ( V_112 -> V_122 & 0xffff ) , V_14 + V_123 ) ;
F_13 ( ( V_112 -> V_124 << 16 ) | ( V_112 -> V_125 & 0xffff ) ,
V_14 + V_126 ) ;
}
static void F_28 ( struct V_6 * V_7 ,
const struct V_127 * V_128 )
{
T_4 V_122 = V_128 -> V_122 , V_121 = V_128 -> V_121 , V_129 = V_128 -> V_129 , V_130 = V_128 -> V_130 ;
T_4 V_131 = V_128 -> V_125 , V_132 = V_128 -> V_124 ;
union V_57 V_58 ;
if ( V_7 -> V_113 != V_114 )
return;
if ( V_7 -> V_115 & V_116 ) {
F_29 ( V_7 , V_128 ) ;
return;
}
V_58 . V_29 = F_10 ( V_14 + V_98 ) ;
V_58 . V_52 . V_90 = V_91 ;
V_58 . V_52 . V_83 = V_84 ;
F_22 ( 1 ) ;
F_13 ( V_58 . V_29 , V_14 + V_98 ) ;
F_22 ( 3 ) ;
F_13 ( ( V_130 << 16 ) | ( V_129 & 0xffff ) , V_14 + V_133 ) ;
F_13 ( ( V_121 << 16 ) | ( V_122 & 0xffff ) , V_14 + V_123 ) ;
F_13 ( ( V_132 << 16 ) | ( V_131 & 0xffff ) , V_14 + V_126 ) ;
}
static void F_30 ( struct V_8 * V_9 )
{
struct V_37 * V_38 = V_9 -> V_39 -> V_38 ;
F_31 ( V_9 ) ;
F_32 ( V_9 ) ;
F_16 ( V_9 ) ;
F_18 ( V_9 ) ;
F_33 () ;
F_5 () ;
F_34 ( V_9 ) ;
F_6 ( V_9 ) ;
F_7 () ;
F_25 ( V_9 ) ;
F_8 ( V_9 ) ;
if ( ! V_9 -> V_16 && V_38 && V_38 -> V_134 )
V_38 -> V_134 ( V_9 ) ;
}
static struct V_135 * F_35 ( struct V_8 * V_9 , unsigned int * V_136 , unsigned int * V_137 , int V_138 )
{
struct V_135 * V_139 = NULL ;
struct V_135 * V_140 = V_9 -> V_39 -> V_140 ;
unsigned int V_141 = 0xffffffff , V_142 = 0xffffffff ;
unsigned int V_50 ;
for ( V_50 = 0 ; V_50 < V_9 -> V_39 -> V_143 ; V_50 ++ ) {
if ( V_140 [ V_50 ] . V_21 >= * V_136 && V_140 [ V_50 ] . V_22 >= * V_137 &&
V_140 [ V_50 ] . V_21 < V_141 && V_140 [ V_50 ] . V_22 < V_142 ) {
V_141 = V_140 [ V_50 ] . V_21 ;
V_142 = V_140 [ V_50 ] . V_22 ;
V_139 = & V_140 [ V_50 ] ;
} else if( V_140 [ V_50 ] . V_21 >= * V_137 && V_140 [ V_50 ] . V_22 >= * V_136 &&
V_140 [ V_50 ] . V_21 < V_142 && V_140 [ V_50 ] . V_22 < V_141 ) {
V_141 = V_140 [ V_50 ] . V_22 ;
V_142 = V_140 [ V_50 ] . V_21 ;
V_139 = & V_140 [ V_50 ] ;
}
}
if ( V_139 && V_138 ) {
* V_136 = V_141 ;
* V_137 = V_142 ;
}
return V_139 ;
}
static int F_36 ( struct V_144 * V_31 , struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
if( ! F_35 ( V_9 , & V_31 -> V_21 , & V_31 -> V_22 , 1 ) )
return - V_145 ;
if ( V_9 -> V_39 -> V_146 && ( ( V_31 -> V_21 * V_31 -> V_22 * V_23 / 8 ) > ( V_9 -> V_39 -> V_146 -> V_147 + 1 ) ) )
return - V_145 ;
if ( ! V_9 -> V_39 -> V_146 && ( ( V_31 -> V_21 * V_31 -> V_22 * V_23 / 8 ) > ( V_148 + 1 ) ) )
return - V_145 ;
V_31 -> V_149 = F_37 ( V_31 -> V_149 , V_31 -> V_21 ) ;
V_31 -> V_150 = F_37 ( V_31 -> V_150 , V_31 -> V_22 ) ;
if ( V_31 -> V_151 > V_23 )
return - V_145 ;
else
V_31 -> V_151 = V_23 ;
V_31 -> V_25 . V_152 = 11 ;
V_31 -> V_25 . V_153 = 5 ;
V_31 -> V_26 . V_152 = 5 ;
V_31 -> V_26 . V_153 = 6 ;
V_31 -> V_27 . V_152 = 0 ;
V_31 -> V_27 . V_153 = 5 ;
V_31 -> V_154 . V_152 = V_31 -> V_154 . V_153 = 0 ;
V_31 -> V_155 = 0 ;
V_31 -> V_125 = - 1 ;
V_31 -> V_124 = - 1 ;
V_31 -> V_156 = V_157 ;
V_31 -> V_158 = 0 ;
V_31 -> V_159 = 0x04 ;
return 0 ;
}
static int F_38 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_9 -> V_21 != V_7 -> V_31 . V_21 || V_9 -> V_22 != V_7 -> V_31 . V_22 ) {
V_9 -> V_21 = V_7 -> V_31 . V_21 ;
V_9 -> V_22 = V_7 -> V_31 . V_22 ;
V_9 -> V_139 = F_35 ( V_9 , & V_9 -> V_21 , & V_9 -> V_22 , 0 ) ;
V_7 -> V_160 . V_161 = V_162 ;
V_7 -> V_160 . V_163 = 0 ;
V_7 -> V_160 . V_164 = 0 ;
V_7 -> V_160 . V_165 = V_9 -> V_21 * V_23 / 8 ;
F_39 ( & V_7 -> V_166 ) ;
if ( ( V_9 -> V_21 * V_9 -> V_22 * V_23 / 8 ) > ( V_148 + 1 ) ) {
V_9 -> V_167 = 1 ;
V_7 -> V_160 . V_168 = V_9 -> V_39 -> V_146 -> V_147 + 1 ;
} else {
V_9 -> V_167 = 0 ;
V_7 -> V_160 . V_168 = V_148 + 1 ;
}
F_40 ( & V_7 -> V_166 ) ;
F_30 ( V_9 ) ;
}
return 0 ;
}
static void F_41 ( struct V_8 * V_9 )
{
int V_169 ;
if ( V_9 -> V_167 ) {
V_169 = V_9 -> V_39 -> V_146 -> V_147 ;
V_9 -> V_170 = F_42 ( V_169 ) ;
if ( V_9 -> V_170 )
F_43 ( V_9 -> V_170 , V_18 + ( V_19 - V_20 ) , V_169 ) ;
}
V_169 = V_148 ;
V_9 -> V_171 = F_42 ( V_169 ) ;
if ( V_9 -> V_171 && V_9 -> V_167 )
F_43 ( V_9 -> V_171 , V_18 + ( V_19 - V_172 ) , V_169 ) ;
else if ( V_9 -> V_171 )
F_43 ( V_9 -> V_171 , V_18 + ( V_19 - V_20 ) , V_169 ) ;
}
static void F_44 ( struct V_8 * V_9 )
{
int V_169 ;
if ( V_9 -> V_167 && V_9 -> V_170 ) {
V_169 = V_9 -> V_39 -> V_146 -> V_147 ;
F_45 ( V_18 + ( V_19 - V_20 ) , V_9 -> V_170 , V_169 ) ;
F_46 ( V_9 -> V_170 ) ;
}
if ( V_9 -> V_171 ) {
V_169 = V_148 ;
if ( V_9 -> V_167 )
F_45 ( V_18 + ( V_19 - V_172 ) , V_9 -> V_171 , V_169 ) ;
else
F_45 ( V_18 + ( V_19 - V_20 ) , V_9 -> V_171 , V_169 ) ;
F_46 ( V_9 -> V_171 ) ;
}
}
static int F_47 ( struct V_173 * V_2 , T_5 V_113 )
{
struct V_6 * V_7 = F_48 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_37 * V_38 = V_9 -> V_39 -> V_38 ;
F_41 ( V_9 ) ;
if( V_38 && V_38 -> V_44 )
V_38 -> V_44 ( V_9 ) ;
F_49 ( V_174 ) ;
V_9 -> V_16 = 1 ;
return 0 ;
}
static int F_50 ( struct V_173 * V_2 )
{
struct V_6 * V_7 = F_48 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_37 * V_38 = V_9 -> V_39 -> V_38 ;
F_51 ( V_9 ) ;
F_30 ( V_9 ) ;
F_44 ( V_9 ) ;
if( V_38 && V_38 -> V_46 )
V_38 -> V_46 ( V_9 ) ;
V_9 -> V_16 = 0 ;
return 0 ;
}
int T_6 F_52 ( struct V_173 * V_175 )
{
int V_176 = - V_177 ;
struct V_178 * V_179 ;
struct V_6 * V_7 = NULL ;
struct V_8 * V_9 ;
struct V_180 * V_146 = F_53 ( V_175 , V_181 , 0 ) ;
unsigned int V_182 ;
if ( ! V_146 )
return - V_145 ;
V_183 = F_54 ( V_146 -> V_184 + V_185 , V_186 ) ;
if ( V_183 == NULL )
goto V_187;
V_14 = F_54 ( V_146 -> V_184 + V_188 , V_189 ) ;
if ( V_14 == NULL )
goto V_187;
F_11 ( L_9 ) ;
V_182 = F_10 ( V_14 + V_190 ) ;
switch( V_182 ) {
case V_191 : F_11 ( L_10 ) ; break;
case V_192 : F_11 ( L_11 ) ; break;
case V_193 : F_11 ( L_12 ) ; break;
default:
F_11 ( L_13 ) ;
V_176 = - V_194 ;
goto V_187;
}
F_11 ( L_14 , ( unsigned long ) V_146 -> V_184 + V_185 ) ;
V_18 = F_54 ( V_146 -> V_184 + V_20 , V_195 ) ;
if ( V_18 == NULL )
goto V_187;
V_7 = F_55 ( sizeof( struct V_8 ) , & V_175 -> V_2 ) ;
if ( ! V_7 ) {
V_176 = - V_196 ;
goto V_187;
}
V_9 = V_7 -> V_9 ;
F_56 ( V_175 , V_7 ) ;
V_179 = V_175 -> V_2 . V_197 ;
V_9 -> V_182 = V_182 ;
V_9 -> V_39 = V_179 ;
V_9 -> V_15 = 0 ;
V_9 -> V_16 = 0 ;
V_9 -> V_198 = F_57 ( V_179 -> V_199 ) ;
if ( ! V_9 -> V_198 ) {
F_11 ( V_54 L_15 ) ;
V_176 = - V_145 ;
goto V_187;
}
V_7 -> V_35 = F_58 ( sizeof ( T_4 ) * V_33 , V_200 ) ;
if ( ! V_7 -> V_35 ) {
V_176 = - V_196 ;
goto V_187;
}
V_7 -> V_201 = & V_202 ;
V_7 -> V_115 = V_203 | V_204 |
V_205 ;
V_7 -> V_206 = - 1 ;
V_7 -> V_207 = V_18 + ( V_19 - V_20 ) ;
V_7 -> V_208 = V_209 ;
strcpy ( V_7 -> V_160 . V_210 , L_16 ) ;
V_7 -> V_160 . type = V_211 ;
V_7 -> V_160 . V_212 = 0 ;
V_7 -> V_160 . V_213 = V_214 ;
V_7 -> V_160 . V_215 = V_146 -> V_184 + V_19 ;
V_7 -> V_160 . V_216 = V_146 -> V_184 + V_188 ;
V_7 -> V_160 . V_217 = V_189 ;
if ( F_59 ( & V_7 -> V_218 , 256 , 0 ) < 0 ) {
V_176 = - V_196 ;
goto V_187;
}
V_9 -> V_139 = & V_179 -> V_140 [ 0 ] ;
if( V_179 -> V_219 & V_220 ) {
V_7 -> V_31 . V_21 = V_9 -> V_139 -> V_22 ;
V_7 -> V_31 . V_22 = V_9 -> V_139 -> V_21 ;
}
else {
V_7 -> V_31 . V_21 = V_9 -> V_139 -> V_21 ;
V_7 -> V_31 . V_22 = V_9 -> V_139 -> V_22 ;
}
if( V_179 -> V_219 &= V_221 )
V_9 -> V_10 = 1 ;
else
V_9 -> V_10 = 0 ;
V_7 -> V_31 . V_149 = V_7 -> V_31 . V_21 ;
V_7 -> V_31 . V_150 = V_7 -> V_31 . V_22 ;
V_7 -> V_31 . V_159 = 0x04 ;
V_7 -> V_31 . V_158 = 0 ;
V_7 -> V_31 . V_32 = 0 ;
V_7 -> V_31 . V_222 = V_7 -> V_31 . V_223 = 0 ;
V_7 -> V_31 . V_224 = 0 ;
V_7 -> V_31 . V_225 = V_226 ;
F_51 ( V_9 ) ;
if ( F_36 ( & V_7 -> V_31 , V_7 ) < 0 ) {
V_176 = - V_145 ;
goto V_187;
}
if ( F_60 ( V_7 ) < 0 ) {
V_176 = - V_145 ;
goto V_187;
}
V_176 = F_61 ( & V_175 -> V_2 , & V_227 ) ;
V_176 |= F_61 ( & V_175 -> V_2 , & V_228 ) ;
V_176 |= F_61 ( & V_175 -> V_2 , & V_229 ) ;
V_176 |= F_61 ( & V_175 -> V_2 , & V_230 ) ;
if ( V_176 != 0 )
F_11 ( V_231 L_17 ,
V_7 -> V_206 , V_176 ) ;
F_11 ( V_232 L_18 , V_7 -> V_206 , V_7 -> V_160 . V_210 ) ;
return 0 ;
V_187:
if ( V_7 ) {
F_62 ( & V_7 -> V_218 ) ;
F_63 ( V_7 -> V_35 ) ;
}
if ( V_18 != NULL )
F_64 ( V_18 ) ;
if ( V_14 != NULL )
F_64 ( V_14 ) ;
if ( V_183 != NULL )
F_64 ( V_183 ) ;
if ( V_7 )
F_65 ( V_7 ) ;
return V_176 ;
}
static int T_7 F_66 ( struct V_173 * V_175 )
{
struct V_6 * V_7 = F_48 ( V_175 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
F_67 ( & V_175 -> V_2 , & V_227 ) ;
F_67 ( & V_175 -> V_2 , & V_228 ) ;
F_67 ( & V_175 -> V_2 , & V_229 ) ;
F_67 ( & V_175 -> V_2 , & V_230 ) ;
F_68 ( V_7 ) ;
F_46 ( V_9 -> V_171 ) ;
F_46 ( V_9 -> V_170 ) ;
F_63 ( V_7 -> V_35 ) ;
F_62 ( & V_7 -> V_218 ) ;
F_64 ( V_183 ) ;
F_64 ( V_14 ) ;
F_64 ( V_18 ) ;
F_65 ( V_7 ) ;
return 0 ;
}
static void F_69 ( void )
{
T_8 V_29 = F_70 ( ( T_8 * ) V_183 + V_233 ) ;
F_71 ( V_29 | 0x08 , ( T_8 * ) V_183 + V_233 ) ;
F_23 ( 100 ) ;
F_71 ( 0x00 , ( T_8 * ) V_183 + V_233 ) ;
F_23 ( 100 ) ;
}
static void F_5 ( void )
{
union V_234 V_235 ;
V_235 . V_52 . V_236 = 0x1e ;
V_235 . V_52 . V_237 = 0 ;
V_235 . V_52 . V_238 = 0 ;
F_13 ( ( T_4 ) ( V_235 . V_29 ) , V_14 + V_239 ) ;
}
static void F_7 ( void )
{
union V_234 V_235 ;
V_235 . V_52 . V_236 = 0x1e ;
V_235 . V_52 . V_237 = 1 ;
V_235 . V_52 . V_238 = 1 ;
F_13 ( ( T_4 ) ( V_235 . V_29 ) , V_14 + V_239 ) ;
}
unsigned long F_72 ( int V_240 )
{
unsigned long V_241 ;
if ( V_240 == V_242 )
V_241 = F_10 ( V_14 + V_243 ) ;
else
V_241 = F_10 ( V_14 + V_244 ) ;
return V_241 ;
}
void F_73 ( int V_240 , unsigned long V_241 )
{
if ( V_240 == V_242 )
F_13 ( V_241 , V_14 + V_243 ) ;
else
F_13 ( V_241 , V_14 + V_244 ) ;
}
static void F_51 ( struct V_8 * V_9 )
{
T_4 V_245 ;
union V_246 V_247 ;
union V_248 V_249 ;
union V_250 V_251 ;
union V_252 V_253 ;
union V_254 V_255 ;
union V_256 V_257 ;
union V_258 V_259 ;
union V_260 V_261 ;
union V_262 V_263 ;
struct V_264 * V_265 = V_9 -> V_39 -> V_265 ;
F_69 () ;
F_13 ( 0x31 , V_14 + V_266 ) ;
for ( V_245 = 0 ; V_245 < 10000 ; V_245 ++ )
F_10 ( V_14 + V_266 ) ;
F_13 ( 0x30 , V_14 + V_266 ) ;
V_263 . V_29 = V_267 ;
F_13 ( ( T_4 ) ( V_263 . V_29 ) , V_14 + V_268 ) ;
V_259 . V_29 = F_10 ( V_14 + V_269 ) ;
V_259 . V_52 . V_270 = 0 ;
V_259 . V_52 . V_271 = 1 ;
V_259 . V_52 . V_272 = 1 ;
F_13 ( ( T_4 ) ( V_259 . V_29 ) , V_14 + V_269 ) ;
V_255 . V_29 = F_10 ( V_14 + V_273 ) ;
V_255 . V_52 . V_274 = 1 ;
F_13 ( ( T_4 ) ( V_255 . V_29 ) , V_14 + V_273 ) ;
V_247 . V_29 = F_10 ( V_14 + V_275 ) ;
V_247 . V_52 . V_276 = 1 ;
V_247 . V_52 . V_277 = 1 ;
V_247 . V_52 . V_278 = 0 ;
V_247 . V_52 . V_279 = 1 ;
V_247 . V_52 . V_280 = 1 ;
F_13 ( ( T_4 ) ( V_247 . V_29 ) , V_14 + V_275 ) ;
V_249 . V_29 = V_281 ;
V_249 . V_52 . V_282 = 1 ;
V_249 . V_52 . V_283 = 1 ;
V_249 . V_52 . V_284 = 0 ;
V_249 . V_52 . V_285 = 0 ;
F_74 ( ( V_286 ) ( V_249 . V_29 ) , V_183 + V_287 ) ;
V_257 . V_29 = V_288 ;
V_257 . V_52 . V_289 = 1 ;
V_257 . V_52 . V_290 = 1 ;
V_257 . V_52 . V_291 = 1 ;
V_257 . V_52 . V_292 = 0 ;
F_74 ( ( V_286 ) ( V_257 . V_29 ) , V_183 + V_293 ) ;
F_74 ( ( V_286 ) ( V_188 >> 16 ) , V_183 + V_294 ) ;
V_251 . V_29 = V_295 ;
V_251 . V_52 . V_251 = V_185 ;
F_13 ( ( T_4 ) ( V_251 . V_29 ) , V_14 + V_296 ) ;
V_261 . V_29 = V_297 ;
V_261 . V_52 . V_298 = V_299 >> 1 ;
F_13 ( ( T_4 ) ( V_261 . V_29 ) , V_14 + V_300 ) ;
V_253 . V_29 = V_301 ;
V_253 . V_52 . V_302 = V_303 >> 1 ;
F_13 ( ( T_4 ) ( V_253 . V_29 ) , V_14 + V_304 ) ;
F_13 ( ( T_4 ) 0x2440 , V_14 + V_305 ) ;
V_245 = F_10 ( V_14 + V_306 ) ;
V_245 &= 0xff7fffff ;
V_245 |= 0x00800000 ;
F_13 ( V_245 , V_14 + V_306 ) ;
if ( V_265 ) {
F_13 ( V_265 -> V_307 , V_14 + V_243 ) ;
F_13 ( V_265 -> V_308 , V_14 + V_244 ) ;
F_13 ( V_265 -> V_309 , V_14 + V_310 ) ;
F_13 ( V_265 -> V_311 , V_14 + V_312 ) ;
F_13 ( V_265 -> V_313 , V_14 + V_314 ) ;
F_13 ( V_265 -> V_315 , V_14 + V_316 ) ;
}
}
struct V_317 T_6 * F_57 ( unsigned int V_318 )
{
struct V_319 * V_320 = V_321 ;
do {
if ( V_318 == V_320 -> V_199 )
return V_320 -> V_198 ;
V_320 ++ ;
} while ( V_320 -> V_199 );
return 0 ;
}
static unsigned int F_75 ( unsigned int V_322 )
{
union V_323 V_324 ;
F_23 ( 5 ) ;
V_324 . V_52 . V_325 = 0x0 ;
V_324 . V_52 . V_322 = V_322 ;
V_324 . V_52 . V_326 = 0x1 ;
F_13 ( ( T_4 ) ( V_324 . V_29 ) , V_14 + V_327 ) ;
V_324 . V_52 . V_326 = 0x0 ;
F_13 ( ( T_4 ) ( V_324 . V_29 ) , V_14 + V_327 ) ;
V_324 . V_52 . V_325 = 0x1 ;
F_13 ( ( T_4 ) ( V_324 . V_29 ) , V_14 + V_327 ) ;
F_23 ( 20 ) ;
V_324 . V_29 = F_10 ( V_14 + V_327 ) ;
V_324 . V_52 . V_325 = 0x0 ;
F_13 ( ( T_4 ) ( V_324 . V_29 ) , V_14 + V_327 ) ;
return V_324 . V_52 . V_328 ;
}
static int F_76 ( struct V_317 * V_329 )
{
unsigned int V_330 ;
unsigned int V_331 ;
V_332 . V_333 . V_52 . V_334 = 0x0 ;
V_332 . V_333 . V_52 . V_335 = 0x0 ;
V_332 . V_333 . V_52 . V_336 = 0x1 ;
V_332 . V_333 . V_52 . V_337 = 0x0 ;
V_332 . V_333 . V_52 . V_338 = 0x0 ;
V_332 . V_333 . V_52 . V_339 = 0x0 ;
V_332 . V_333 . V_52 . V_340 = 0x0 ;
do {
V_332 . V_333 . V_52 . V_341 = 0xd ;
F_13 ( ( T_4 ) ( V_332 . V_333 . V_29 ) , V_14 + V_342 ) ;
V_330 = F_75 ( V_343 ) ;
if ( V_330 >= ( V_329 -> V_344 ) ) {
V_332 . V_333 . V_52 . V_341 = 0x7 ;
F_13 ( ( T_4 ) ( V_332 . V_333 . V_29 ) , V_14 + V_342 ) ;
V_331 = F_75 ( V_343 ) ;
if ( V_331 <= ( V_329 -> V_344 ) )
return 1 ;
if ( ( V_332 . V_333 . V_52 . V_338 == 0x0 ) &&
( ( V_332 . V_333 . V_52 . V_337 == 0x7 ) ||
( V_332 . V_333 . V_52 . V_339 == 0x0 ) ) ) {
V_332 . V_333 . V_52 . V_338 = 0x1 ;
V_332 . V_333 . V_52 . V_337 = 0x0 ;
V_332 . V_333 . V_52 . V_339 = 0x0 ;
continue;
}
}
if ( ( V_332 . V_333 . V_52 . V_339 ) < 0x3 ) {
V_332 . V_333 . V_52 . V_339 += 0x1 ;
} else if ( ( V_332 . V_333 . V_52 . V_337 ) < 0x7 ) {
V_332 . V_333 . V_52 . V_339 = 0x0 ;
V_332 . V_333 . V_52 . V_337 += 0x1 ;
} else {
return 0 ;
}
} while( 1 );
}
static int F_77 ( struct V_317 * V_329 )
{
int V_49 ;
V_49 = F_76 ( V_329 ) ;
V_332 . V_333 . V_52 . V_341 = 0xa ;
F_13 ( ( T_4 ) ( V_332 . V_333 . V_29 ) , V_14 + V_342 ) ;
F_23 ( 1 ) ;
V_332 . V_333 . V_52 . V_336 = 0x0 ;
F_13 ( ( T_4 ) ( V_332 . V_333 . V_29 ) , V_14 + V_342 ) ;
V_332 . V_333 . V_52 . V_341 = 0x0 ;
F_13 ( ( T_4 ) ( V_332 . V_333 . V_29 ) , V_14 + V_342 ) ;
F_23 ( 400 ) ;
return V_49 ;
}
static int F_78 ( struct V_317 * V_329 )
{
int V_49 ;
if ( V_332 . V_345 == 1 )
{
V_332 . V_346 . V_52 . V_347 = 0x0 ;
V_332 . V_346 . V_52 . V_348 = 0x0 ;
F_13 ( ( T_4 ) ( V_332 . V_346 . V_29 ) , V_14 + V_349 ) ;
}
V_332 . V_350 . V_52 . V_351 = V_352 ;
F_13 ( ( T_4 ) ( V_332 . V_350 . V_29 ) , V_14 + V_353 ) ;
V_332 . V_354 . V_52 . V_355 = V_329 -> V_356 ;
V_332 . V_354 . V_52 . V_357 = V_329 -> V_358 ;
V_332 . V_354 . V_52 . V_359 = V_329 -> V_360 ;
V_332 . V_354 . V_52 . V_361 = V_329 -> V_362 ;
F_13 ( ( T_4 ) ( V_332 . V_354 . V_29 ) , V_14 + V_363 ) ;
V_332 . V_346 . V_52 . V_364 = 0 ;
F_13 ( ( T_4 ) ( V_332 . V_346 . V_29 ) , V_14 + V_349 ) ;
V_49 = F_77 ( V_329 ) ;
if ( V_332 . V_345 == 1 )
{
V_332 . V_346 . V_52 . V_347 = 0x1 ;
V_332 . V_346 . V_52 . V_348 = 0x1 ;
F_13 ( ( T_4 ) ( V_332 . V_346 . V_29 ) , V_14 + V_349 ) ;
}
return V_49 ;
}
static int F_79 ( struct V_8 * V_9 , unsigned int V_318 )
{
struct V_317 * V_329 = V_9 -> V_198 ;
do {
if ( V_318 == V_329 -> V_318 ) {
return F_78 ( V_329 ) ;
}
V_329 ++ ;
} while( V_329 -> V_318 );
return 0 ;
}
static void F_31 ( struct V_8 * V_9 )
{
V_332 . V_365 . V_52 . V_366 = 0x1 ;
V_332 . V_365 . V_52 . V_367 = 0x1f ;
V_332 . V_365 . V_52 . V_368 = 0x0 ;
V_332 . V_365 . V_52 . V_369 = 0x0 ;
V_332 . V_365 . V_52 . V_370 = V_9 -> V_39 -> V_371 ? 1 : 0 ;
V_332 . V_365 . V_52 . V_372 = 0x0 ;
F_13 ( ( T_4 ) ( V_332 . V_365 . V_29 ) , V_14 + V_373 ) ;
V_332 . V_350 . V_52 . V_351 = V_352 ;
V_332 . V_350 . V_52 . V_374 = 0x0 ;
V_332 . V_350 . V_52 . V_375 = 0x3 ;
V_332 . V_350 . V_52 . V_376 = 0x0 ;
V_332 . V_350 . V_52 . V_377 = 0x0 ;
V_332 . V_350 . V_52 . V_378 = 0x0 ;
V_332 . V_350 . V_52 . V_379 = 0x0 ;
V_332 . V_350 . V_52 . V_380 = 0x0 ;
V_332 . V_350 . V_52 . V_381 = 0x0 ;
V_332 . V_350 . V_52 . V_382 = 0x0 ;
V_332 . V_350 . V_52 . V_383 = 0x0 ;
V_332 . V_350 . V_52 . V_384 = 0x0 ;
V_332 . V_350 . V_52 . V_385 = 0x0 ;
V_332 . V_350 . V_52 . V_386 = 0x0 ;
V_332 . V_350 . V_52 . V_387 = 0x0 ;
V_332 . V_350 . V_52 . V_388 = 0x0 ;
V_332 . V_350 . V_52 . V_389 = 0x0 ;
V_332 . V_350 . V_52 . V_390 = 0x0 ;
F_13 ( ( T_4 ) ( V_332 . V_350 . V_29 ) , V_14 + V_353 ) ;
V_332 . V_391 . V_52 . V_392 = V_352 ;
V_332 . V_391 . V_52 . V_393 = 0x1 ;
V_332 . V_391 . V_52 . V_394 = 0x0 ;
F_13 ( ( T_4 ) ( V_332 . V_391 . V_29 ) , V_14 + V_395 ) ;
V_332 . V_354 . V_52 . V_355 = 0x0 ;
V_332 . V_354 . V_52 . V_357 = 0x0 ;
V_332 . V_354 . V_52 . V_359 = 0x0 ;
V_332 . V_354 . V_52 . V_396 = 0x5 ;
V_332 . V_354 . V_52 . V_361 = 0xff ;
F_13 ( ( T_4 ) ( V_332 . V_354 . V_29 ) , V_14 + V_363 ) ;
V_332 . V_333 . V_52 . V_334 = 0x1 ;
V_332 . V_333 . V_52 . V_335 = 0x1 ;
V_332 . V_333 . V_52 . V_397 = 0x0 ;
V_332 . V_333 . V_52 . V_398 = 0x0 ;
V_332 . V_333 . V_52 . V_399 = 0x0 ;
V_332 . V_333 . V_52 . V_400 = 0x0 ;
V_332 . V_333 . V_52 . V_336 = 0x0 ;
V_332 . V_333 . V_52 . V_401 = 0x4 ;
V_332 . V_333 . V_52 . V_337 = 0x0 ;
V_332 . V_333 . V_52 . V_338 = 0x0 ;
V_332 . V_333 . V_52 . V_339 = 0x0 ;
V_332 . V_333 . V_52 . V_402 = 0x0 ;
V_332 . V_333 . V_52 . V_403 = 0x0 ;
V_332 . V_333 . V_52 . V_341 = 0x0 ;
V_332 . V_333 . V_52 . V_404 = 0x3 ;
V_332 . V_333 . V_52 . V_405 = 0x2 ;
V_332 . V_333 . V_52 . V_406 = 0x2 ;
V_332 . V_333 . V_52 . V_340 = 0x0 ;
F_13 ( ( T_4 ) ( V_332 . V_333 . V_29 ) , V_14 + V_342 ) ;
V_332 . V_346 . V_52 . V_407 = 0x0 ;
V_332 . V_346 . V_52 . V_364 = 0x1 ;
V_332 . V_346 . V_52 . V_408 = 0x0 ;
V_332 . V_346 . V_52 . V_347 = 0x0 ;
V_332 . V_346 . V_52 . V_348 = 0x0 ;
V_332 . V_346 . V_52 . V_409 = 0x1 ;
V_332 . V_346 . V_52 . V_410 = 0x1 ;
V_332 . V_346 . V_52 . V_411 = 0xFF ;
V_332 . V_346 . V_52 . V_412 = 0xFF ;
F_13 ( ( T_4 ) ( V_332 . V_346 . V_29 ) , V_14 + V_349 ) ;
V_332 . V_345 = 0 ;
}
static void F_16 ( struct V_8 * V_9 )
{
struct V_135 * V_139 = V_9 -> V_139 ;
if ( V_139 -> V_413 == V_414 || V_139 -> V_415 == V_414 )
F_79 ( V_9 , ( V_9 -> V_15 && V_139 -> V_416 ) ? V_139 -> V_416 : V_139 -> V_417 ) ;
V_332 . V_350 . V_52 . V_351 = V_139 -> V_415 ;
V_332 . V_350 . V_52 . V_374 = V_139 -> V_418 ;
V_332 . V_350 . V_52 . V_376 = V_139 -> V_418 ;
F_13 ( ( T_4 ) ( V_332 . V_350 . V_29 ) , V_14 + V_353 ) ;
}
static void F_34 ( struct V_8 * V_9 )
{
T_4 V_245 ;
struct V_135 * V_139 = V_9 -> V_139 ;
struct V_419 * V_12 = V_9 -> V_39 -> V_12 ;
union V_420 V_421 ;
union V_422 V_423 ;
union V_424 V_425 ;
union V_426 V_427 ;
union V_428 V_429 ;
V_421 . V_29 = 0 ;
V_421 . V_52 . V_430 = V_139 -> V_431 ;
V_421 . V_52 . V_432 = V_139 -> V_431 + V_139 -> V_21 ;
F_13 ( V_421 . V_29 , V_14 + V_433 ) ;
V_423 . V_29 = 0 ;
V_423 . V_52 . V_434 = V_139 -> V_435 ;
V_423 . V_52 . V_436 = V_139 -> V_435 + V_139 -> V_22 ;
F_13 ( V_423 . V_29 , V_14 + V_437 ) ;
V_425 . V_29 = 0 ;
V_425 . V_52 . V_438 = V_139 -> V_431 ;
V_425 . V_52 . V_439 = V_139 -> V_431 + V_139 -> V_21 ;
F_13 ( V_425 . V_29 , V_14 + V_440 ) ;
V_427 . V_29 = 0 ;
V_427 . V_52 . V_441 = V_139 -> V_435 ;
V_427 . V_52 . V_442 = V_139 -> V_435 + V_139 -> V_22 ;
F_13 ( V_427 . V_29 , V_14 + V_443 ) ;
V_429 . V_29 = 0 ;
V_429 . V_52 . V_444 = V_139 -> V_431 + V_139 -> V_21 + V_139 -> V_445 ;
V_429 . V_52 . V_446 = V_139 -> V_435 + V_139 -> V_22 + V_139 -> V_447 ;
F_13 ( V_429 . V_29 , V_14 + V_448 ) ;
F_13 ( V_139 -> V_449 , V_14 + V_450 ) ;
F_13 ( V_139 -> V_451 , V_14 + V_452 ) ;
F_13 ( V_139 -> V_453 , V_14 + V_454 ) ;
F_13 ( V_139 -> V_455 , V_14 + V_456 ) ;
F_13 ( V_139 -> V_457 , V_14 + V_458 ) ;
F_13 ( V_139 -> V_459 , V_14 + V_460 ) ;
F_13 ( V_139 -> V_461 , V_14 + V_462 ) ;
F_13 ( V_139 -> V_463 , V_14 + V_464 ) ;
F_13 ( V_139 -> V_465 , V_14 + V_466 ) ;
F_13 ( V_12 -> V_467 , V_14 + V_468 ) ;
F_13 ( V_12 -> V_469 , V_14 + V_470 ) ;
F_13 ( V_12 -> V_471 , V_14 + V_472 ) ;
F_13 ( V_12 -> V_473 , V_14 + V_474 ) ;
F_13 ( V_12 -> V_475 , V_14 + V_476 ) ;
F_13 ( V_12 -> V_477 , V_14 + V_478 ) ;
F_13 ( 0x00000000 , V_14 + V_479 ) ;
F_13 ( 0x00000000 , V_14 + V_480 ) ;
F_13 ( 0x00000000 , V_14 + V_481 ) ;
F_13 ( 0x0000FF00 , V_14 + V_482 ) ;
V_245 = F_10 ( V_14 + V_306 ) ;
V_245 |= 0xc0000000 ;
F_13 ( V_245 , V_14 + V_306 ) ;
}
static void F_32 ( struct V_8 * V_9 )
{
union V_483 V_484 ;
union V_485 V_486 ;
struct V_487 * V_146 = V_9 -> V_39 -> V_146 ;
struct V_488 * V_489 = V_9 -> V_39 -> V_489 ;
if ( ! V_9 -> V_167 ) {
F_49 ( V_490 ) ;
V_486 . V_52 . V_491 = V_19 >> 8 ;
V_486 . V_52 . V_492 = ( V_19 + V_148 ) >> 8 ;
F_13 ( ( T_4 ) ( V_486 . V_29 ) , V_14 + V_493 ) ;
V_484 . V_52 . V_494 = V_495 >> 8 ;
V_484 . V_52 . V_496 = ( V_495 - 1 ) >> 8 ;
F_13 ( ( T_4 ) ( V_484 . V_29 ) , V_14 + V_497 ) ;
} else {
V_486 . V_52 . V_491 = V_172 >> 8 ;
V_486 . V_52 . V_492 = ( V_172 + V_148 ) >> 8 ;
F_13 ( ( T_4 ) ( V_486 . V_29 ) , V_14 + V_493 ) ;
V_484 . V_52 . V_494 = V_19 >> 8 ;
V_484 . V_52 . V_496 = ( V_19 + V_9 -> V_39 -> V_146 -> V_147 ) >> 8 ;
F_13 ( ( T_4 ) ( V_484 . V_29 ) , V_14 + V_497 ) ;
F_13 ( 0x00007800 , V_14 + V_498 ) ;
F_13 ( V_146 -> V_499 , V_14 + V_500 ) ;
F_13 ( 0x00200021 , V_14 + V_501 ) ;
F_23 ( 100 ) ;
F_13 ( 0x80200021 , V_14 + V_501 ) ;
F_23 ( 100 ) ;
F_13 ( V_146 -> V_502 , V_14 + V_501 ) ;
F_23 ( 100 ) ;
F_13 ( V_146 -> V_503 , V_14 + V_504 ) ;
F_13 ( V_146 -> V_505 , V_14 + V_506 ) ;
if ( V_489 ) {
F_13 ( V_489 -> V_507 , V_14 + V_508 ) ;
F_13 ( V_489 -> V_152 , V_14 + V_509 ) ;
F_13 ( V_489 -> V_510 , V_14 + V_511 ) ;
F_13 ( V_489 -> V_499 , V_14 + V_512 ) ;
F_13 ( V_489 -> V_513 , V_14 + V_514 ) ;
F_13 ( V_489 -> V_505 , V_14 + V_515 ) ;
F_13 ( V_489 -> V_516 , V_14 + V_517 ) ;
}
}
}
static void F_6 ( struct V_8 * V_9 )
{
unsigned long V_518 = 0 , V_519 , V_152 = 0 ;
union V_520 V_521 ;
if ( V_9 -> V_21 == V_9 -> V_139 -> V_21 ) {
if ( V_9 -> V_10 ) {
V_518 = 3 ;
V_152 = ( V_9 -> V_21 * V_9 -> V_22 ) - 1 ;
}
V_519 = V_9 -> V_139 -> V_522 ;
} else {
if ( V_9 -> V_10 ) {
V_518 = 2 ;
V_152 = V_9 -> V_21 - 1 ;
} else {
V_518 = 1 ;
V_152 = V_9 -> V_21 * ( V_9 -> V_22 - 1 ) ;
}
V_519 = V_9 -> V_139 -> V_523 ;
}
V_521 . V_29 = 0 ;
switch ( V_9 -> V_182 ) {
case V_191 :
V_521 . V_524 . V_525 = 6 ;
V_521 . V_524 . V_526 = 1 ;
V_521 . V_524 . V_527 = 1 ;
V_521 . V_524 . V_528 = 1 ;
V_521 . V_524 . V_529 = 1 ;
V_521 . V_524 . V_530 = 1 ;
V_521 . V_524 . V_531 = 0 ;
V_521 . V_524 . V_532 = 0 ;
V_521 . V_524 . V_533 = V_518 ;
switch( V_9 -> V_21 ) {
case 240 :
case 320 :
default:
V_521 . V_524 . V_534 = 0xa0 ;
break;
case 480 :
case 640 :
switch( V_518 ) {
case 0 :
case 3 :
V_521 . V_524 . V_531 = 1 ;
V_521 . V_524 . V_532 = 5 ;
break;
case 1 :
case 2 :
V_521 . V_524 . V_532 = 4 ;
break;
default:
break;
}
V_521 . V_524 . V_534 = 0xf0 ;
break;
}
break;
case V_192 :
case V_193 :
V_521 . V_535 . V_525 = 6 ;
V_521 . V_535 . V_526 = 1 ;
V_521 . V_535 . V_527 = 1 ;
V_521 . V_535 . V_528 = 1 ;
V_521 . V_535 . V_529 = 1 ;
V_521 . V_535 . V_530 = 1 ;
V_521 . V_535 . V_531 = 0 ;
V_521 . V_535 . V_532 = 0 ;
V_521 . V_535 . V_534 = V_9 -> V_139 -> V_21 >> 1 ;
V_521 . V_535 . V_533 = V_518 ;
break;
}
V_332 . V_391 . V_52 . V_392 = V_9 -> V_139 -> V_413 ;
V_332 . V_391 . V_52 . V_393 = V_519 ;
F_13 ( ( T_4 ) ( V_332 . V_391 . V_29 ) , V_14 + V_395 ) ;
F_13 ( V_521 . V_29 , V_14 + V_536 ) ;
F_13 ( V_19 + ( ( V_152 * V_23 / 8 ) & ~ 0x03UL ) , V_14 + V_537 ) ;
F_13 ( ( V_9 -> V_21 * V_23 / 8 ) , V_14 + V_538 ) ;
}
static void F_8 ( struct V_8 * V_9 )
{
unsigned long V_539 ;
struct V_135 * V_139 = V_9 -> V_139 ;
union V_540 V_449 ;
if ( V_139 -> V_413 == V_352 )
V_539 = V_9 -> V_39 -> V_199 ;
else
V_539 = ( ( V_9 -> V_15 && V_139 -> V_416 ) ? V_139 -> V_416 : V_139 -> V_417 ) * 100000 ;
V_539 /= ( V_332 . V_391 . V_52 . V_393 + 1 ) ;
V_449 . V_29 = F_10 ( V_14 + V_450 ) ;
if ( V_449 . V_29 )
V_9 -> V_17 = V_539 / ( V_449 . V_52 . V_541 - V_449 . V_52 . V_542 ) ;
else
V_9 -> V_17 = 0 ;
}
static void F_49 ( T_4 V_139 )
{
T_4 V_29 ;
F_13 ( 0x7FFF8000 , V_14 + V_497 ) ;
F_13 ( 0x00FF0000 , V_14 + V_543 ) ;
V_29 = F_10 ( V_14 + V_504 ) ;
V_29 &= ~ ( 0x00100000 ) ;
V_29 |= 0xFF000000 ;
F_13 ( V_29 , V_14 + V_504 ) ;
V_29 = F_10 ( V_14 + V_500 ) ;
V_29 &= ~ ( 0x00040000 ) ;
V_29 |= 0x00080000 ;
F_13 ( V_29 , V_14 + V_500 ) ;
F_23 ( 1 ) ;
if ( V_139 == V_490 ) {
V_29 = F_10 ( V_14 + V_500 ) ;
V_29 |= 0x40000000 ;
F_13 ( V_29 , V_14 + V_500 ) ;
V_29 = F_10 ( V_14 + V_500 ) ;
V_29 &= ~ ( 0x00000001 ) ;
F_13 ( V_29 , V_14 + V_500 ) ;
} else {
F_13 ( 0x00000000 , V_14 + V_353 ) ;
F_13 ( 0x000000BF , V_14 + V_373 ) ;
F_13 ( 0x00000015 , V_14 + V_349 ) ;
F_23 ( 5 ) ;
V_29 = F_10 ( V_14 + V_342 ) ;
V_29 |= 0x00000004 ;
F_13 ( V_29 , V_14 + V_342 ) ;
F_13 ( 0x0000001d , V_14 + V_349 ) ;
}
}
static void F_33 ( void )
{
T_4 V_544 ;
int V_545 = 30000 ;
V_544 = F_10 ( V_14 + V_437 ) ;
F_13 ( ( V_544 >> 16 ) & 0x3ff , V_14 + V_546 ) ;
V_544 = F_10 ( V_14 + V_547 ) ;
V_544 &= ~ 0x00000002 ;
F_13 ( V_544 , V_14 + V_547 ) ;
F_13 ( 0x00000002 , V_14 + V_548 ) ;
F_13 ( ( V_544 | 0x00000002 ) , V_14 + V_547 ) ;
F_13 ( 0x00000002 , V_14 + V_548 ) ;
while( V_545 > 0 ) {
if ( F_10 ( V_14 + V_548 ) & 0x00000002 )
break;
F_23 ( 1 ) ;
V_545 -- ;
}
F_13 ( V_544 , V_14 + V_547 ) ;
F_13 ( 0x00000002 , V_14 + V_548 ) ;
}
int T_9 F_80 ( void )
{
return F_81 ( & V_549 ) ;
}
void T_10 F_82 ( void )
{
F_83 ( & V_549 ) ;
}
