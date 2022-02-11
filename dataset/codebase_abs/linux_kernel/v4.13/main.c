void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_4 ( V_2 ) ;
}
void F_2 ( struct V_1 * V_2 )
{
V_2 -> V_3 -> V_5 ( V_2 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_6 ( V_2 , false ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_3 -> V_6 ( V_2 , true ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 ;
struct V_9 * V_10 = F_6 ( V_2 -> V_11 -> V_12 ) ;
int V_13 ;
V_13 = F_7 ( & V_8 , V_14 , V_10 ) ;
if ( V_13 < 0 ) {
F_8 ( L_1 , V_13 ) ;
return V_13 ;
}
if ( V_8 -> V_15 % 4 ) {
F_8 ( L_2 ,
V_8 -> V_15 ) ;
V_13 = - V_16 ;
goto V_17;
}
V_2 -> V_18 = V_8 -> V_15 ;
V_2 -> V_8 = F_9 ( V_2 -> V_18 ) ;
if ( ! V_2 -> V_8 ) {
F_8 ( L_3 ) ;
V_13 = - V_19 ;
goto V_17;
}
memcpy ( V_2 -> V_8 , V_8 -> V_20 , V_2 -> V_18 ) ;
V_13 = 0 ;
V_17:
F_10 ( V_8 ) ;
return V_13 ;
}
static int F_11 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 ;
struct V_9 * V_10 = F_6 ( V_2 -> V_11 -> V_12 ) ;
int V_13 ;
V_13 = F_7 ( & V_8 , V_21 , V_10 ) ;
if ( V_13 < 0 ) {
F_8 ( L_4 , V_13 ) ;
return V_13 ;
}
if ( V_8 -> V_15 % 4 ) {
F_8 ( L_5 ,
V_8 -> V_15 ) ;
V_13 = - V_16 ;
goto V_17;
}
V_2 -> V_22 = V_8 -> V_15 ;
V_2 -> V_23 = F_12 ( V_8 -> V_20 , V_2 -> V_22 , V_24 ) ;
if ( ! V_2 -> V_23 ) {
F_8 ( L_6 ) ;
V_13 = - V_19 ;
goto V_17;
}
V_13 = 0 ;
V_17:
F_10 ( V_8 ) ;
return V_13 ;
}
static void F_13 ( struct V_1 * V_2 )
{
T_1 V_25 ;
V_25 = V_26 ;
F_14 ( V_2 , V_27 , V_25 ) ;
V_25 = F_15 ( V_2 , V_27 ) ;
if ( ! ( V_25 & V_28 ) )
F_16 ( L_7 ) ;
}
static int F_17 ( struct V_1 * V_2 )
{
int V_13 ;
V_13 = F_4 ( V_2 ) ;
if ( V_13 < 0 )
return V_13 ;
F_18 ( V_29 ) ;
V_2 -> V_3 -> V_30 ( V_2 ) ;
F_19 ( V_2 ,
0x00000000 ,
0x00000000 ,
V_31 ,
V_32 ) ;
F_13 ( V_2 ) ;
V_2 -> V_33 = F_20 ( V_2 , V_34 ) ;
switch ( V_2 -> V_33 ) {
case V_35 :
F_21 ( V_36 , L_8 ,
V_2 -> V_33 ) ;
break;
case V_37 :
F_21 ( V_36 , L_9 ,
V_2 -> V_33 ) ;
break;
case V_38 :
default:
F_8 ( L_10 , V_2 -> V_33 ) ;
V_13 = - V_39 ;
goto V_17;
}
if ( V_2 -> V_8 == NULL ) {
V_13 = F_5 ( V_2 ) ;
if ( V_13 < 0 )
goto V_17;
}
if ( V_2 -> V_23 == NULL && ! V_2 -> V_40 ) {
V_13 = F_11 ( V_2 ) ;
if ( V_13 < 0 )
goto V_17;
}
V_17:
return V_13 ;
}
static void F_22 ( struct V_41 * V_42 )
{
T_1 V_43 , V_44 = V_45 ;
struct V_1 * V_2 =
F_23 ( V_42 , struct V_1 , V_46 ) ;
int V_13 ;
F_24 ( & V_2 -> V_47 ) ;
F_21 ( V_48 , L_11 ) ;
if ( V_2 -> V_49 == V_50 )
goto V_17;
V_13 = F_25 ( V_2 ) ;
if ( V_13 < 0 )
goto V_17;
F_26 ( V_2 , V_51 , V_52 ) ;
V_43 = F_20 ( V_2 , V_53 ) ;
F_21 ( V_48 , L_12 , V_43 ) ;
do {
if ( V_2 -> V_54 ) {
V_2 -> V_55 = F_27 (
V_2 , V_2 -> V_54 -> V_56 ) ;
switch ( ( V_2 -> V_55 - V_2 -> V_57 ) & 0xf ) {
case 0 :
F_21 ( V_48 ,
L_13 ) ;
V_43 &= ~ V_58 ;
V_43 &= ~ V_59 ;
break;
case 1 :
F_21 ( V_48 , L_14 ) ;
V_43 |= V_58 ;
V_43 &= ~ V_59 ;
break;
case 2 :
F_21 ( V_48 , L_15 ) ;
V_43 |= V_58 ;
V_43 |= V_59 ;
break;
default:
F_16 (
L_16 ,
V_2 -> V_55 - V_2 -> V_57 ) ;
break;
}
V_2 -> V_57 = V_2 -> V_55 ;
F_21 ( V_48 , L_17 ,
V_2 -> V_55 ) ;
}
V_43 &= V_2 -> V_60 ;
if ( V_43 == 0 ) {
F_21 ( V_48 , L_18 ) ;
goto V_61;
}
if ( V_43 & V_58 ) {
F_21 ( V_48 , L_19 ) ;
F_28 ( V_2 ) ;
}
if ( V_43 & V_59 ) {
F_21 ( V_48 , L_20 ) ;
F_28 ( V_2 ) ;
}
if ( V_43 & V_62 ) {
F_21 ( V_48 , L_21 ) ;
F_29 ( V_2 ) ;
}
if ( V_43 & V_63 ) {
F_21 ( V_48 , L_22 ) ;
F_30 ( V_2 , 0 ) ;
}
if ( V_43 & V_64 ) {
F_21 ( V_48 , L_23 ) ;
F_30 ( V_2 , 1 ) ;
}
if ( V_43 & V_65 )
F_21 ( V_48 ,
L_24 ) ;
if ( -- V_44 == 0 )
break;
V_43 = F_20 ( V_2 , V_53 ) ;
} while ( V_43 );
V_61:
F_26 ( V_2 , V_51 , ~ ( V_2 -> V_60 ) ) ;
F_31 ( V_2 ) ;
V_17:
F_32 ( & V_2 -> V_47 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_2 V_66 , T_2 V_67 ,
T_3 V_68 , T_2 V_69 )
{
int V_13 ;
V_13 = F_34 ( V_2 , V_70 ,
V_71 ,
V_2 -> V_72 ,
V_2 -> V_73 ) ;
if ( V_13 < 0 )
goto V_17;
if ( F_35 ( V_2 -> V_74 ) )
V_2 -> V_75 &= ~ V_76 ;
V_13 = F_36 ( V_2 , V_66 , V_67 , V_68 ,
V_69 ) ;
if ( V_13 < 0 )
goto V_17;
V_13 = F_37 ( V_2 , V_77 , 100 ) ;
if ( V_13 < 0 )
F_16 ( L_25 ) ;
V_17:
return V_13 ;
}
static void F_38 ( struct V_78 * V_11 ,
struct V_79 * V_80 ,
struct V_81 * V_82 )
{
struct V_1 * V_2 = V_11 -> V_83 ;
unsigned long V_84 ;
F_39 ( & V_2 -> V_85 , V_82 ) ;
F_40 ( V_2 -> V_11 , & V_2 -> V_86 ) ;
if ( F_41 ( & V_2 -> V_85 ) >= V_87 ) {
F_21 ( V_88 , L_26 ) ;
F_42 ( & V_2 -> V_89 , V_84 ) ;
F_43 ( V_2 -> V_11 ) ;
V_2 -> V_90 = true ;
F_44 ( & V_2 -> V_89 , V_84 ) ;
}
}
static int F_45 ( struct V_78 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_83 ;
struct V_12 * V_12 = V_11 -> V_12 ;
int V_13 = 0 ;
F_21 ( V_91 , L_27 ) ;
F_24 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_49 != V_50 ) {
F_8 ( L_28 ,
V_2 -> V_49 ) ;
V_13 = - V_92 ;
goto V_17;
}
V_13 = F_17 ( V_2 ) ;
if ( V_13 < 0 )
goto V_17;
V_13 = F_46 ( V_2 ) ;
if ( V_13 < 0 )
goto V_17;
V_13 = F_47 ( V_2 ) ;
if ( V_13 < 0 )
goto V_17;
V_13 = F_48 ( V_2 ) ;
if ( V_13 < 0 )
goto V_17;
V_2 -> V_49 = V_93 ;
F_49 ( L_29 , V_2 -> V_94 ) ;
V_12 -> V_95 = V_2 -> V_33 ;
strncpy ( V_12 -> V_96 , V_2 -> V_94 , sizeof( V_12 -> V_96 ) ) ;
V_17:
if ( V_13 < 0 )
F_3 ( V_2 ) ;
F_32 ( & V_2 -> V_47 ) ;
return V_13 ;
}
static void F_50 ( struct V_78 * V_11 )
{
struct V_1 * V_2 = V_11 -> V_83 ;
F_49 ( L_30 ) ;
F_21 ( V_91 , L_31 ) ;
F_24 ( & V_2 -> V_47 ) ;
F_51 ( V_2 -> V_49 != V_93 ) ;
if ( V_2 -> V_97 ) {
struct V_98 V_99 = {
. V_100 = true ,
} ;
F_52 ( V_2 -> V_11 , & V_99 ) ;
V_2 -> V_97 = false ;
}
V_2 -> V_49 = V_50 ;
F_2 ( V_2 ) ;
F_32 ( & V_2 -> V_47 ) ;
F_53 ( & V_2 -> V_46 ) ;
F_53 ( & V_2 -> V_86 ) ;
F_54 ( & V_2 -> V_101 ) ;
F_24 ( & V_2 -> V_47 ) ;
F_55 ( V_2 ) ;
F_3 ( V_2 ) ;
F_56 ( V_2 -> V_74 ) ;
V_2 -> V_102 = 1 ;
V_2 -> V_66 = V_103 ;
V_2 -> V_104 = 0 ;
V_2 -> V_55 = 0 ;
V_2 -> V_57 = 0 ;
V_2 -> V_105 = 0 ;
V_2 -> V_106 = 0 ;
V_2 -> V_107 = 0 ;
V_2 -> V_108 = false ;
V_2 -> V_109 = V_110 ;
V_2 -> V_111 = 0 ;
V_2 -> V_90 = false ;
V_2 -> V_112 = V_113 ;
V_2 -> V_114 = 0 ;
V_2 -> V_67 = V_115 ;
V_2 -> V_116 = false ;
V_2 -> V_117 = false ;
F_57 ( V_2 ) ;
F_32 ( & V_2 -> V_47 ) ;
}
static int F_58 ( struct V_78 * V_11 ,
struct V_118 * V_119 )
{
struct V_1 * V_2 = V_11 -> V_83 ;
int V_13 = 0 ;
V_119 -> V_120 |= V_121 |
V_122 |
V_123 ;
F_21 ( V_91 , L_32 ,
V_119 -> type , V_119 -> V_124 ) ;
F_24 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_119 ) {
V_13 = - V_92 ;
goto V_17;
}
V_2 -> V_119 = V_119 ;
switch ( V_119 -> type ) {
case V_125 :
V_2 -> V_66 = V_126 ;
break;
case V_127 :
V_2 -> V_66 = V_128 ;
break;
default:
V_13 = - V_129 ;
goto V_17;
}
if ( ! F_59 ( V_2 -> V_130 , V_119 -> V_124 ) ) {
memcpy ( V_2 -> V_130 , V_119 -> V_124 , V_131 ) ;
F_60 ( V_2 -> V_11 , V_2 -> V_130 ) ;
V_13 = F_48 ( V_2 ) ;
if ( V_13 < 0 )
goto V_17;
}
V_17:
F_32 ( & V_2 -> V_47 ) ;
return V_13 ;
}
static void F_61 ( struct V_78 * V_11 ,
struct V_118 * V_119 )
{
struct V_1 * V_2 = V_11 -> V_83 ;
F_24 ( & V_2 -> V_47 ) ;
F_21 ( V_91 , L_33 ) ;
V_2 -> V_119 = NULL ;
F_56 ( V_2 -> V_74 ) ;
F_32 ( & V_2 -> V_47 ) ;
}
static int F_62 ( struct V_1 * V_2 )
{
struct V_81 * V_82 = NULL ;
int V_15 ;
void * V_132 ;
int V_13 = - V_19 ;
if ( V_2 -> V_66 == V_128 ) {
V_15 = sizeof( struct V_133 ) ;
V_132 = NULL ;
} else {
V_82 = F_63 ( V_2 -> V_11 , V_2 -> V_119 ) ;
if ( ! V_82 )
goto V_17;
V_15 = V_82 -> V_134 ;
V_132 = V_82 -> V_20 ;
}
V_13 = F_64 ( V_2 , V_135 , V_132 , V_15 ) ;
V_17:
F_65 ( V_82 ) ;
if ( V_13 )
F_16 ( L_34 , V_13 ) ;
return V_13 ;
}
static int F_66 ( struct V_1 * V_2 )
{
struct V_136 V_137 ;
memset ( & V_137 , 0 , sizeof( V_137 ) ) ;
memcpy ( V_137 . V_138 , V_2 -> V_74 , V_131 ) ;
memcpy ( V_137 . V_139 , V_2 -> V_130 , V_131 ) ;
memcpy ( V_137 . V_140 , V_2 -> V_74 , V_131 ) ;
V_137 . V_141 = F_67 ( V_142 |
V_143 |
V_144 ) ;
V_137 . V_145 = F_67 ( 0 ) ;
return F_64 ( V_2 , V_146 , & V_137 ,
sizeof( V_137 ) ) ;
}
static bool F_68 ( struct V_147 * V_148 , struct V_1 * V_2 )
{
return ( V_148 -> V_84 & V_149 ) && ! V_2 -> V_116 ;
}
static int F_69 ( struct V_78 * V_11 , T_1 V_150 )
{
struct V_1 * V_2 = V_11 -> V_83 ;
struct V_147 * V_148 = & V_11 -> V_148 ;
int V_67 , V_13 = 0 ;
V_67 = F_70 (
V_148 -> V_151 . V_152 -> V_153 ) ;
F_21 ( V_91 ,
L_35 ,
V_67 ,
V_148 -> V_84 & V_154 ? L_36 : L_37 ,
V_148 -> V_84 & V_149 ? L_36 : L_37 ,
V_148 -> V_112 ) ;
F_24 ( & V_2 -> V_47 ) ;
V_13 = F_25 ( V_2 ) ;
if ( V_13 < 0 )
goto V_17;
if ( V_150 & V_155 ) {
T_1 V_156 ;
if ( V_148 -> V_84 & V_154 ) {
V_2 -> V_116 = true ;
V_156 = V_157 | V_158 ;
} else {
V_2 -> V_116 = false ;
V_156 = 0 ;
}
V_13 = F_71 ( V_2 , V_156 ) ;
if ( V_13 < 0 )
goto V_61;
}
if ( V_67 != V_2 -> V_67 ) {
V_2 -> V_67 = V_67 ;
if ( V_2 -> V_119 == NULL ) {
V_2 -> V_117 = false ;
V_13 = F_72 ( V_2 , V_2 -> V_67 , 1 ) ;
} else {
V_13 = F_33 ( V_2 , V_2 -> V_66 , V_2 -> V_67 ,
V_2 -> V_159 , V_2 -> V_69 ) ;
}
if ( V_13 < 0 )
goto V_61;
}
if ( F_68 ( V_148 , V_2 ) && ! V_2 -> V_160 ) {
F_21 ( V_161 , L_38 ) ;
V_2 -> V_160 = true ;
V_2 -> V_69 = V_148 -> V_162 ;
V_13 = F_73 ( V_2 , V_2 -> V_159 ,
V_2 -> V_69 ) ;
V_13 = F_74 ( V_2 , V_163 ) ;
if ( V_13 < 0 )
goto V_61;
} else if ( ! F_68 ( V_148 , V_2 ) && V_2 -> V_160 ) {
F_21 ( V_161 , L_39 ) ;
V_2 -> V_160 = false ;
if ( V_2 -> V_109 != V_110 ) {
V_13 = F_74 ( V_2 , V_110 ) ;
if ( V_13 < 0 )
goto V_61;
}
}
if ( V_150 & V_164 && ! V_2 -> V_97 ) {
if ( V_148 -> V_84 & V_165 ) {
V_13 = F_74 ( V_2 , V_166 ) ;
if ( V_13 < 0 )
goto V_61;
} else {
V_13 = F_74 ( V_2 , V_110 ) ;
if ( V_13 < 0 )
goto V_61;
V_13 = F_33 ( V_2 , V_2 -> V_66 , V_2 -> V_67 ,
V_2 -> V_159 , V_2 -> V_69 ) ;
if ( V_13 < 0 )
goto V_61;
}
}
if ( V_148 -> V_112 != V_2 -> V_112 ) {
V_13 = F_75 ( V_2 , V_148 -> V_112 ) ;
if ( V_13 < 0 )
goto V_61;
V_2 -> V_112 = V_148 -> V_112 ;
}
V_61:
F_31 ( V_2 ) ;
V_17:
F_32 ( & V_2 -> V_47 ) ;
return V_13 ;
}
static T_4 F_76 ( struct V_78 * V_11 ,
struct V_167 * V_168 )
{
struct V_169 * V_170 ;
struct V_171 * V_172 ;
struct V_1 * V_2 = V_11 -> V_83 ;
if ( F_77 ( V_2 -> V_49 == V_50 ) )
return 0 ;
V_170 = F_78 ( sizeof( * V_170 ) , V_173 ) ;
if ( ! V_170 ) {
F_8 ( L_40 ) ;
return 0 ;
}
V_170 -> V_174 = 0 ;
if ( F_79 ( V_168 ) > V_175 ) {
V_170 -> V_176 = false ;
} else {
V_170 -> V_176 = true ;
F_80 (ha, mc_list) {
memcpy ( V_170 -> V_168 [ V_170 -> V_174 ] ,
V_172 -> V_124 , V_131 ) ;
V_170 -> V_174 ++ ;
}
}
return ( T_4 ) ( unsigned long ) V_170 ;
}
static void F_81 ( struct V_78 * V_11 ,
unsigned int V_150 ,
unsigned int * V_177 , T_4 V_178 )
{
struct V_169 * V_170 = ( void * ) ( unsigned long ) V_178 ;
struct V_1 * V_2 = V_11 -> V_83 ;
int V_13 ;
F_21 ( V_91 , L_41 ) ;
* V_177 &= V_179 ;
V_150 &= V_179 ;
if ( V_150 == 0 ) {
F_82 ( V_170 ) ;
return;
}
F_24 ( & V_2 -> V_47 ) ;
V_2 -> V_75 = V_180 ;
V_2 -> V_181 = V_182 ;
if ( * V_177 & V_183 )
V_2 -> V_75 &= ~ V_184 ;
if ( * V_177 & V_185 )
V_2 -> V_181 |= V_186 ;
if ( * V_177 & V_187 ) {
V_2 -> V_75 &= ~ V_76 ;
V_2 -> V_75 &= ~ V_188 ;
}
if ( * V_177 & V_189 )
V_2 -> V_181 |= V_190 ;
if ( * V_177 & V_191 || F_35 ( V_2 -> V_74 ) )
V_2 -> V_75 &= ~ V_76 ;
if ( * V_177 & V_192 )
V_2 -> V_181 |= V_193 ;
if ( V_2 -> V_49 == V_50 )
goto V_17;
V_13 = F_25 ( V_2 ) ;
if ( V_13 < 0 )
goto V_17;
if ( * V_177 & V_183 )
V_13 = F_83 ( V_2 , false , NULL , 0 ) ;
else if ( V_170 )
V_13 = F_83 ( V_2 , V_170 -> V_176 ,
V_170 -> V_168 ,
V_170 -> V_174 ) ;
if ( V_13 < 0 )
goto V_17;
F_84 ( V_2 , V_2 -> V_75 , V_2 -> V_181 ) ;
F_31 ( V_2 ) ;
V_17:
F_32 ( & V_2 -> V_47 ) ;
F_82 ( V_170 ) ;
}
static int F_85 ( struct V_1 * V_2 ,
struct V_194 * V_195 ,
enum V_196 V_197 ,
struct V_198 * V_199 ,
const T_2 * V_124 )
{
switch ( V_199 -> V_200 ) {
case V_201 :
case V_202 :
if ( F_86 ( V_124 ) )
V_195 -> V_203 = V_204 ;
else
V_195 -> V_203 = V_205 ;
V_199 -> V_206 = V_199 -> V_207 ;
break;
case V_208 :
if ( F_86 ( V_124 ) )
V_195 -> V_203 = V_209 ;
else
V_195 -> V_203 = V_210 ;
V_199 -> V_206 = V_199 -> V_207 ;
break;
case V_211 :
if ( F_86 ( V_124 ) )
V_195 -> V_203 = V_212 ;
else
V_195 -> V_203 = V_213 ;
V_199 -> V_84 |= V_214 ;
break;
default:
F_8 ( L_42 , V_199 -> V_200 ) ;
return - V_129 ;
}
return 0 ;
}
static int F_87 ( struct V_78 * V_11 , enum V_196 V_197 ,
struct V_118 * V_119 ,
struct V_215 * V_216 ,
struct V_198 * V_195 )
{
struct V_1 * V_2 = V_11 -> V_83 ;
struct V_194 * V_217 ;
const T_2 * V_124 ;
int V_13 ;
static const T_2 V_218 [ V_131 ] =
{ 0xff , 0xff , 0xff , 0xff , 0xff , 0xff } ;
F_21 ( V_91 , L_43 ) ;
V_217 = F_78 ( sizeof( * V_217 ) , V_24 ) ;
if ( ! V_217 ) {
V_13 = - V_19 ;
goto V_17;
}
V_124 = V_216 ? V_216 -> V_124 : V_218 ;
F_21 ( V_219 , L_44 , V_197 ) ;
F_88 ( V_219 , L_45 , V_124 , V_131 ) ;
F_21 ( V_219 , L_46 ,
V_195 -> V_200 , V_195 -> V_207 , V_195 -> V_220 , V_195 -> V_84 ) ;
F_88 ( V_219 , L_47 , V_195 -> V_195 , V_195 -> V_220 ) ;
if ( F_35 ( V_124 ) ) {
V_13 = - V_129 ;
goto V_17;
}
F_24 ( & V_2 -> V_47 ) ;
switch ( V_197 ) {
case V_221 :
if ( V_2 -> V_116 ) {
V_13 = - V_129 ;
goto V_222;
}
V_217 -> V_223 = V_224 ;
break;
case V_225 :
V_217 -> V_223 = V_226 ;
break;
default:
F_8 ( L_48 , V_197 ) ;
break;
}
V_13 = F_25 ( V_2 ) ;
if ( V_13 < 0 )
goto V_222;
V_13 = F_85 ( V_2 , V_217 , V_197 , V_195 , V_124 ) ;
if ( V_13 < 0 ) {
F_8 ( L_49 ) ;
goto V_61;
}
if ( V_217 -> V_203 != V_204 )
memcpy ( V_217 -> V_124 , V_124 , V_131 ) ;
if ( ( V_217 -> V_203 == V_209 ) ||
( V_217 -> V_203 == V_210 ) ) {
memcpy ( V_217 -> V_195 , V_195 -> V_195 , 16 ) ;
memcpy ( V_217 -> V_195 + 16 , V_195 -> V_195 + 24 , 8 ) ;
memcpy ( V_217 -> V_195 + 24 , V_195 -> V_195 + 16 , 8 ) ;
} else {
memcpy ( V_217 -> V_195 , V_195 -> V_195 , V_195 -> V_220 ) ;
}
V_217 -> V_227 = V_195 -> V_220 ;
V_217 -> V_228 = V_195 -> V_207 ;
V_217 -> V_229 = 0 ;
F_88 ( V_219 , L_50 , V_217 , sizeof( * V_217 ) ) ;
V_13 = F_89 ( V_2 , V_230 , V_217 , sizeof( * V_217 ) ) ;
if ( V_13 < 0 ) {
F_16 ( L_51 ) ;
goto V_61;
}
V_61:
F_31 ( V_2 ) ;
V_222:
F_32 ( & V_2 -> V_47 ) ;
V_17:
F_82 ( V_217 ) ;
return V_13 ;
}
static int F_90 ( struct V_78 * V_11 ,
struct V_118 * V_119 ,
struct V_231 * V_232 )
{
struct V_233 * V_234 = & V_232 -> V_234 ;
struct V_1 * V_2 = V_11 -> V_83 ;
struct V_81 * V_82 ;
T_5 V_235 = 0 ;
T_2 * V_236 = NULL ;
int V_13 ;
F_21 ( V_91 , L_52 ) ;
if ( V_234 -> V_237 ) {
V_236 = V_234 -> V_238 [ 0 ] . V_236 ;
V_235 = V_234 -> V_238 [ 0 ] . V_235 ;
}
F_24 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_97 ) {
F_21 ( V_239 , L_53 ) ;
V_13 = - V_240 ;
goto V_17;
}
V_13 = F_25 ( V_2 ) ;
if ( V_13 < 0 )
goto V_17;
if ( V_11 -> V_148 . V_84 & V_165 ) {
V_13 = F_74 ( V_2 , V_110 ) ;
if ( V_13 < 0 )
goto V_61;
V_13 = F_33 ( V_2 , V_2 -> V_66 , V_2 -> V_67 ,
V_2 -> V_159 , V_2 -> V_69 ) ;
if ( V_13 < 0 )
goto V_61;
}
V_82 = F_91 ( V_2 -> V_11 , V_2 -> V_119 -> V_124 , V_236 , V_235 ,
V_234 -> V_241 ) ;
if ( ! V_82 ) {
V_13 = - V_19 ;
goto V_242;
}
if ( V_234 -> V_241 )
F_92 ( V_82 , V_234 -> V_243 , V_234 -> V_241 ) ;
V_13 = F_64 ( V_2 , V_244 , V_82 -> V_20 ,
V_82 -> V_134 ) ;
F_65 ( V_82 ) ;
if ( V_13 < 0 )
goto V_242;
V_13 = F_93 ( V_2 , 0 ) ;
if ( V_13 < 0 )
goto V_242;
V_2 -> V_97 = true ;
V_13 = F_94 ( V_2 , V_236 , V_235 , V_234 -> V_245 ,
V_234 -> V_246 , V_247 ) ;
if ( V_13 < 0 ) {
F_21 ( V_239 , L_54 , V_13 ) ;
V_2 -> V_97 = false ;
goto V_242;
}
goto V_61;
V_242:
if ( V_11 -> V_148 . V_84 & V_165 )
V_13 = F_74 ( V_2 , V_166 ) ;
V_61:
F_31 ( V_2 ) ;
V_17:
F_32 ( & V_2 -> V_47 ) ;
return V_13 ;
}
static int F_95 ( struct V_78 * V_11 , T_1 V_248 )
{
struct V_1 * V_2 = V_11 -> V_83 ;
int V_13 ;
F_24 ( & V_2 -> V_47 ) ;
V_13 = F_25 ( V_2 ) ;
if ( V_13 < 0 )
goto V_17;
V_13 = F_96 ( V_2 , ( T_3 ) V_248 ) ;
if ( V_13 < 0 )
F_16 ( L_55 , V_13 ) ;
F_31 ( V_2 ) ;
V_17:
F_32 ( & V_2 -> V_47 ) ;
return V_13 ;
}
static void F_97 ( struct V_78 * V_11 ,
struct V_118 * V_119 ,
struct V_249 * V_250 ,
T_1 V_150 )
{
struct V_1 * V_2 = V_11 -> V_83 ;
struct V_81 * V_251 , * V_82 ;
bool V_252 ;
int V_13 ;
F_21 ( V_91 , L_56 ) ;
F_24 ( & V_2 -> V_47 ) ;
V_13 = F_25 ( V_2 ) ;
if ( V_13 < 0 )
goto V_17;
if ( V_150 & V_253 ) {
V_13 = F_98 ( V_2 , V_250 -> V_254 ,
V_255 ,
V_256 ,
V_257 ) ;
if ( V_13 < 0 )
goto V_17;
V_2 -> V_114 = V_250 -> V_254 ;
}
if ( ( V_150 & V_258 ) &&
memcmp ( V_2 -> V_74 , V_250 -> V_74 , V_131 ) ) {
memcpy ( V_2 -> V_74 , V_250 -> V_74 , V_131 ) ;
if ( ! F_35 ( V_2 -> V_74 ) ) {
V_13 = F_62 ( V_2 ) ;
if ( V_13 < 0 )
goto V_61;
V_13 = F_66 ( V_2 ) ;
if ( V_13 < 0 )
goto V_61;
V_13 = F_33 ( V_2 , V_2 -> V_66 , V_2 -> V_67 ,
V_2 -> V_159 , V_2 -> V_69 ) ;
if ( V_13 < 0 )
goto V_61;
}
}
if ( V_150 & V_259 ) {
if ( V_250 -> V_260 ) {
V_2 -> V_159 = V_250 -> V_159 ;
V_82 = F_99 ( V_2 -> V_11 , V_2 -> V_119 ) ;
if ( ! V_82 )
goto V_61;
V_13 = F_64 ( V_2 , V_261 ,
V_82 -> V_20 ,
V_82 -> V_134 ) ;
F_65 ( V_82 ) ;
if ( V_13 < 0 )
goto V_61;
V_13 = F_100 ( V_2 , V_250 -> V_262 ) ;
if ( V_13 < 0 )
goto V_61;
} else {
V_2 -> V_159 = V_263 ;
V_2 -> V_69 = V_264 ;
}
}
if ( V_150 & V_265 ) {
if ( V_250 -> V_266 )
V_13 = F_101 ( V_2 , V_267 ) ;
else
V_13 = F_101 ( V_2 , V_268 ) ;
if ( V_13 < 0 ) {
F_16 ( L_57 , V_13 ) ;
goto V_61;
}
}
if ( V_150 & V_269 ) {
if ( V_250 -> V_270 )
F_102 ( V_2 , V_271 ) ;
else
F_102 ( V_2 , V_272 ) ;
}
if ( V_150 & V_273 ) {
if ( V_250 -> V_274 )
V_13 = F_103 ( V_2 , V_275 ) ;
else
V_13 = F_103 ( V_2 , V_276 ) ;
if ( V_13 < 0 ) {
F_16 ( L_58 , V_13 ) ;
goto V_61;
}
}
if ( V_150 & V_277 ) {
T_6 V_124 = V_250 -> V_278 [ 0 ] ;
F_51 ( V_2 -> V_66 != V_126 ) ;
V_252 = V_250 -> V_279 == 1 && V_250 -> V_260 ;
F_104 ( V_2 , V_252 , V_124 ) ;
if ( V_13 < 0 )
goto V_61;
}
if ( V_150 & V_280 ) {
V_251 = F_105 ( V_11 , V_119 ) ;
if ( ! V_251 )
goto V_61;
V_13 = F_64 ( V_2 , V_281 , V_251 -> V_20 ,
V_251 -> V_134 ) ;
if ( V_13 < 0 ) {
F_65 ( V_251 ) ;
goto V_61;
}
V_13 = F_64 ( V_2 , V_282 , V_251 -> V_20 ,
V_251 -> V_134 ) ;
F_65 ( V_251 ) ;
if ( V_13 < 0 )
goto V_61;
V_13 = F_33 ( V_2 , V_2 -> V_66 , V_2 -> V_67 ,
V_2 -> V_159 , V_2 -> V_69 ) ;
if ( V_13 < 0 )
goto V_61;
}
V_61:
F_31 ( V_2 ) ;
V_17:
F_32 ( & V_2 -> V_47 ) ;
}
static int F_106 ( struct V_78 * V_11 ,
struct V_118 * V_119 , T_3 V_283 ,
const struct V_284 * V_285 )
{
enum V_286 V_287 ;
struct V_1 * V_2 = V_11 -> V_83 ;
int V_13 ;
F_24 ( & V_2 -> V_47 ) ;
F_21 ( V_91 , L_59 , V_283 ) ;
V_13 = F_25 ( V_2 ) ;
if ( V_13 < 0 )
goto V_17;
V_13 = F_107 ( V_2 , F_108 ( V_283 ) ,
V_285 -> V_288 , V_285 -> V_289 ,
V_285 -> V_290 , V_285 -> V_291 * 32 ) ;
if ( V_13 < 0 )
goto V_61;
if ( V_285 -> V_292 )
V_287 = V_293 ;
else
V_287 = V_294 ;
V_13 = F_109 ( V_2 , F_108 ( V_283 ) ,
V_295 ,
F_108 ( V_283 ) , V_287 ,
V_296 ) ;
if ( V_13 < 0 )
goto V_61;
V_61:
F_31 ( V_2 ) ;
V_17:
F_32 ( & V_2 -> V_47 ) ;
return V_13 ;
}
static int F_110 ( struct V_78 * V_11 , int V_297 ,
struct V_298 * V_299 )
{
struct V_1 * V_2 = V_11 -> V_83 ;
struct V_147 * V_148 = & V_11 -> V_148 ;
if ( V_297 != 0 )
return - V_300 ;
V_299 -> V_67 = V_148 -> V_151 . V_152 ;
V_299 -> V_301 = V_302 ;
V_299 -> V_303 = V_2 -> V_303 ;
return 0 ;
}
static int F_111 ( struct V_1 * V_2 , T_7 V_304 , T_2 * V_20 )
{
unsigned long V_305 ;
F_26 ( V_2 , V_306 , V_304 ) ;
F_26 ( V_2 , V_307 , V_308 ) ;
V_305 = V_309 + F_112 ( 100 ) ;
while ( 1 ) {
if ( ! ( F_20 ( V_2 , V_307 ) & V_308 ) )
break;
if ( F_113 ( V_309 , V_305 ) )
return - V_310 ;
F_18 ( 1 ) ;
}
* V_20 = F_20 ( V_2 , V_311 ) ;
return 0 ;
}
static int F_114 ( struct V_1 * V_2 , T_7 V_304 ,
T_2 * V_20 , T_5 V_134 )
{
T_5 V_312 ;
int V_13 ;
F_26 ( V_2 , V_313 , 0 ) ;
for ( V_312 = 0 ; V_312 < V_134 ; V_312 ++ ) {
V_13 = F_111 ( V_2 , V_304 + V_312 , & V_20 [ V_312 ] ) ;
if ( V_13 < 0 )
return V_13 ;
}
return 0 ;
}
static int F_115 ( struct V_1 * V_2 )
{
T_2 V_314 [ V_131 ] ;
int V_312 , V_13 ;
F_19 ( V_2 , 0 , 0 , V_31 , V_32 ) ;
V_13 = F_114 ( V_2 , 0x1c , V_314 , sizeof( V_314 ) ) ;
if ( V_13 < 0 ) {
F_16 ( L_60 ) ;
return V_13 ;
}
for ( V_312 = 0 ; V_312 < V_131 ; V_312 ++ )
V_2 -> V_130 [ V_312 ] = V_314 [ V_131 - V_312 - 1 ] ;
return 0 ;
}
static int F_116 ( struct V_1 * V_2 )
{
int V_13 ;
if ( V_2 -> V_315 )
return 0 ;
F_60 ( V_2 -> V_11 , V_2 -> V_130 ) ;
V_13 = F_117 ( V_2 -> V_11 ) ;
if ( V_13 < 0 ) {
F_8 ( L_61 , V_13 ) ;
return V_13 ;
}
V_2 -> V_315 = true ;
F_118 ( L_62 ) ;
return 0 ;
}
int F_119 ( struct V_1 * V_2 )
{
int V_13 ;
V_2 -> V_11 -> V_316 = sizeof( struct V_317 )
+ V_318 ;
F_120 ( V_2 -> V_11 , V_319 ) ;
F_120 ( V_2 -> V_11 , V_320 ) ;
V_2 -> V_11 -> V_12 -> V_321 = F_121 ( V_125 ) |
F_121 ( V_127 ) ;
V_2 -> V_11 -> V_12 -> V_322 = 1 ;
V_2 -> V_11 -> V_12 -> V_323 [ V_324 ] = & V_325 ;
V_2 -> V_11 -> V_326 = 4 ;
if ( V_2 -> V_40 )
F_115 ( V_2 ) ;
V_13 = F_116 ( V_2 ) ;
if ( V_13 )
goto V_17;
F_122 ( V_2 ) ;
F_118 ( L_63 ) ;
V_13 = 0 ;
V_17:
return V_13 ;
}
struct V_78 * F_123 ( void )
{
struct V_78 * V_11 ;
struct V_1 * V_2 ;
int V_312 ;
static const T_2 V_327 [ 3 ] = { 0x00 , 0x1f , 0xdf } ;
V_11 = F_124 ( sizeof( * V_2 ) , & V_328 ) ;
if ( ! V_11 ) {
F_8 ( L_64 ) ;
return F_125 ( - V_19 ) ;
}
V_2 = V_11 -> V_83 ;
memset ( V_2 , 0 , sizeof( * V_2 ) ) ;
V_2 -> V_11 = V_11 ;
V_2 -> V_104 = 0 ;
F_126 ( & V_2 -> V_85 ) ;
F_127 ( & V_2 -> V_101 , V_329 ) ;
V_2 -> V_67 = V_115 ;
V_2 -> V_116 = false ;
V_2 -> V_117 = false ;
V_2 -> V_97 = false ;
V_2 -> V_66 = V_103 ;
V_2 -> V_330 = 0 ;
V_2 -> V_102 = 1 ;
V_2 -> V_55 = 0 ;
V_2 -> V_57 = 0 ;
V_2 -> V_105 = 0 ;
V_2 -> V_106 = 0 ;
V_2 -> V_75 = V_180 ;
V_2 -> V_181 = V_182 ;
V_2 -> V_108 = false ;
V_2 -> V_109 = V_110 ;
V_2 -> V_160 = false ;
V_2 -> V_111 = 0 ;
V_2 -> V_90 = false ;
V_2 -> V_112 = V_113 ;
V_2 -> V_114 = 0 ;
V_2 -> V_159 = V_263 ;
V_2 -> V_69 = V_264 ;
V_2 -> V_119 = NULL ;
for ( V_312 = 0 ; V_312 < V_331 ; V_312 ++ )
V_2 -> V_332 [ V_312 ] = NULL ;
V_2 -> V_107 = 0 ;
F_128 ( & V_2 -> V_46 , F_22 ) ;
F_128 ( & V_2 -> V_86 , V_333 ) ;
memcpy ( V_2 -> V_130 , V_327 , 3 ) ;
F_129 ( V_2 -> V_130 + 3 , 3 ) ;
V_2 -> V_49 = V_50 ;
F_130 ( & V_2 -> V_47 ) ;
F_131 ( & V_2 -> V_89 ) ;
V_2 -> V_72 = V_70 ;
V_2 -> V_73 = V_71 ;
V_2 -> V_334 = F_132 ( sizeof( * V_2 -> V_334 ) , V_24 ) ;
if ( ! V_2 -> V_334 ) {
F_8 ( L_65 ) ;
F_133 ( V_11 ) ;
return F_125 ( - V_19 ) ;
}
return V_11 ;
}
int F_134 ( struct V_1 * V_2 )
{
F_135 ( V_2 -> V_11 ) ;
F_136 ( V_2 ) ;
F_82 ( V_2 -> V_335 ) ;
F_82 ( V_2 -> V_54 ) ;
F_137 ( V_2 -> V_8 ) ;
V_2 -> V_8 = NULL ;
F_82 ( V_2 -> V_23 ) ;
V_2 -> V_23 = NULL ;
F_82 ( V_2 -> V_334 ) ;
V_2 -> V_334 = NULL ;
F_133 ( V_2 -> V_11 ) ;
return 0 ;
}
