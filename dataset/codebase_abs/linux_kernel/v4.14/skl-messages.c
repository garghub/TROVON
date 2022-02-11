static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( ! V_9 )
return - V_10 ;
return V_9 -> V_11 -> V_12 ( V_9 , V_13 , V_5 , V_4 ) ;
}
static int F_4 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( ! V_9 )
return - V_10 ;
V_9 -> V_11 -> V_14 ( V_9 , V_4 ) ;
return 0 ;
}
void F_5 ( struct V_15 * V_16 , bool V_17 )
{
struct V_18 V_19 ;
struct V_20 V_21 = { 0 } ;
V_19 . V_22 = V_23 ;
V_19 . V_17 = V_17 ;
V_21 . V_24 = V_25 ;
V_21 . V_26 = sizeof( V_19 ) ;
F_6 ( & V_16 -> V_27 , & V_21 , ( V_28 * ) & V_19 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_5 ,
int V_29 , int V_17 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_30 * V_31 = F_8 ( V_9 ,
V_32 , V_29 ) ;
struct V_33 * V_34 ;
if ( ! V_31 )
return - V_35 ;
V_34 = F_9 ( V_31 ) ;
F_10 ( V_7 , V_17 , V_31 -> V_36 ) ;
F_11 ( V_7 , V_34 , V_5 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 , unsigned int V_37 ,
unsigned int V_5 , struct V_3 * V_4 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_33 * V_34 ;
struct V_30 * V_31 ;
struct V_38 V_39 ;
int V_40 ;
if ( ! V_9 )
return - V_10 ;
memset ( & V_39 , 0 , sizeof( V_39 ) ) ;
V_39 . V_31 = V_32 ;
V_34 = F_13 ( V_7 , & V_39 ,
V_41 ) ;
if ( ! V_34 )
return - V_10 ;
V_31 = V_30 ( V_34 ) ;
V_40 = F_14 ( V_31 , V_37 , V_5 , V_4 ) ;
if ( V_40 < 0 )
return V_40 ;
F_7 ( V_2 , V_5 , V_31 -> V_29 , true ) ;
return V_31 -> V_29 ;
}
static int F_15 ( struct V_1 * V_2 , bool V_42 , int V_29 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_30 * V_31 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( ! V_9 )
return - V_10 ;
V_31 = F_8 ( V_9 ,
V_32 , V_29 ) ;
if ( ! V_31 )
return - V_35 ;
F_16 ( V_31 , V_42 ) ;
return 0 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_29 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_30 * V_31 ;
struct V_33 * V_34 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
if ( ! V_9 )
return - V_10 ;
V_31 = F_8 ( V_9 ,
V_32 , V_29 ) ;
if ( ! V_31 )
return - V_35 ;
V_34 = F_9 ( V_31 ) ;
F_7 ( V_2 , 0 , V_29 , false ) ;
F_18 ( V_34 , V_41 ) ;
F_19 ( V_31 , V_4 ) ;
return 0 ;
}
static struct V_43 F_20 ( void )
{
struct V_43 V_44 ;
memset ( & V_44 , 0 , sizeof( struct V_43 ) ) ;
V_44 . V_45 = F_1 ;
V_44 . V_46 = F_4 ;
return V_44 ;
}
static struct V_43 F_21 ( void )
{
struct V_43 V_44 ;
memset ( & V_44 , 0 , sizeof( V_44 ) ) ;
V_44 . V_45 = F_1 ;
V_44 . V_46 = F_4 ;
V_44 . V_47 = F_12 ;
V_44 . V_48 = F_15 ;
V_44 . V_49 = F_17 ;
return V_44 ;
}
const struct V_50 * F_22 ( int V_51 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < F_23 ( V_53 ) ; V_52 ++ ) {
if ( V_53 [ V_52 ] . V_54 == V_51 )
return & V_53 [ V_52 ] ;
}
return NULL ;
}
int F_24 ( struct V_55 * V_55 )
{
void T_2 * V_56 ;
struct V_6 * V_7 = & V_55 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_43 V_44 ;
int V_57 = V_9 -> V_57 ;
const struct V_50 * V_58 ;
struct V_59 * V_60 ;
int V_40 ;
F_25 ( & V_55 -> V_7 , true ) ;
F_26 ( & V_55 -> V_7 , true ) ;
V_56 = F_27 ( V_55 -> V_61 , 4 ) ;
if ( V_56 == NULL ) {
F_28 ( V_9 -> V_2 , L_1 ) ;
return - V_62 ;
}
V_58 = F_22 ( V_55 -> V_61 -> V_1 ) ;
if ( ! V_58 ) {
V_40 = - V_63 ;
goto V_64;
}
V_44 = V_58 -> V_44 () ;
V_40 = V_58 -> V_65 ( V_9 -> V_2 , V_56 , V_57 ,
V_55 -> V_66 , V_44 ,
& V_55 -> V_15 ) ;
if ( V_40 < 0 )
goto V_64;
V_55 -> V_15 -> V_53 = V_58 ;
V_60 = & V_55 -> V_15 -> V_60 ;
V_60 -> V_67 = V_58 -> V_68 ;
V_60 -> V_69 = F_29 ( V_60 -> V_67 , sizeof( * V_60 -> V_69 ) , V_70 ) ;
if ( ! V_60 -> V_69 ) {
V_40 = - V_71 ;
goto V_64;
}
V_60 -> V_72 = F_29 ( V_60 -> V_67 , sizeof( * V_60 -> V_72 ) ,
V_70 ) ;
if ( ! V_60 -> V_72 ) {
V_40 = - V_71 ;
goto V_73;
}
F_30 ( V_9 -> V_2 , L_2 , V_40 ) ;
return 0 ;
V_73:
F_31 ( V_60 -> V_69 ) ;
V_64:
F_32 ( V_56 ) ;
return V_40 ;
}
int F_33 ( struct V_55 * V_55 )
{
struct V_6 * V_7 = & V_55 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_15 * V_16 = V_55 -> V_15 ;
F_26 ( & V_55 -> V_7 , false ) ;
V_16 -> V_53 -> V_49 ( V_9 -> V_2 , V_16 ) ;
F_31 ( V_16 -> V_60 . V_69 ) ;
F_31 ( V_16 -> V_60 . V_72 ) ;
if ( V_16 -> V_74 -> V_75 . V_76 )
F_32 ( V_16 -> V_74 -> V_75 . V_76 ) ;
return 0 ;
}
int F_34 ( struct V_55 * V_55 )
{
struct V_15 * V_16 = V_55 -> V_15 ;
struct V_77 * V_78 ;
if ( ! V_16 )
return 0 ;
V_78 = & V_16 -> V_79 . V_80 ;
if ( V_78 -> V_80 . V_81 ) {
if ( V_55 -> V_82 )
F_35 ( V_78 ) ;
else
F_36 ( V_78 ) ;
}
return 0 ;
}
int F_37 ( struct V_55 * V_55 )
{
struct V_15 * V_16 = V_55 -> V_15 ;
int V_40 ;
if ( ! V_55 -> V_7 . V_9 . V_83 )
return 0 ;
V_40 = F_38 ( V_16 -> V_74 ) ;
if ( V_40 < 0 )
return V_40 ;
F_26 ( & V_55 -> V_7 , false ) ;
F_25 ( & V_55 -> V_7 , false ) ;
return 0 ;
}
int F_39 ( struct V_55 * V_55 )
{
struct V_15 * V_16 = V_55 -> V_15 ;
int V_40 ;
if ( ! V_55 -> V_7 . V_9 . V_83 )
return 0 ;
F_25 ( & V_55 -> V_7 , true ) ;
F_26 ( & V_55 -> V_7 , true ) ;
if ( V_55 -> V_15 -> V_84 == true )
return 0 ;
V_40 = F_40 ( V_16 -> V_74 ) ;
if ( V_40 < 0 )
return V_40 ;
F_5 ( V_55 -> V_15 , false ) ;
return V_40 ;
}
enum V_85 F_41 ( int V_86 )
{
switch ( V_86 ) {
case 8 :
return V_87 ;
case 16 :
return V_88 ;
case 24 :
return V_89 ;
case 32 :
return V_90 ;
default:
return V_91 ;
}
}
static void F_42 ( struct V_15 * V_16 ,
struct V_92 * V_93 ,
struct V_94 * V_95 )
{
struct V_96 * V_97 = V_93 -> V_97 ;
struct V_98 * V_99 = & V_97 -> V_100 [ V_93 -> V_101 ] ;
struct V_102 * V_103 = & V_97 -> V_104 [ V_93 -> V_105 ] ;
struct V_106 * V_37 = & V_103 -> V_107 [ 0 ] . V_103 ;
V_95 -> V_108 . V_109 = V_37 -> V_110 ;
V_95 -> V_108 . V_111 = V_37 -> V_111 ;
V_95 -> V_108 . V_112 = V_37 -> V_112 ;
V_95 -> V_108 . V_113 = V_37 -> V_113 ;
V_95 -> V_108 . V_114 = V_37 -> V_114 ;
F_30 ( V_16 -> V_2 , L_3 ,
V_37 -> V_112 , V_37 -> V_113 ,
V_37 -> V_114 ) ;
V_95 -> V_108 . V_115 = V_37 -> V_116 ;
V_95 -> V_108 . V_117 = V_37 -> V_118 ;
V_95 -> V_119 = V_99 -> V_119 ;
V_95 -> V_120 = V_99 -> V_120 ;
V_95 -> V_121 = V_99 -> V_121 ;
V_95 -> V_122 = V_99 -> V_122 ;
}
static void F_43 ( struct V_92 * V_93 ,
struct V_123 * V_124 )
{
if ( V_93 -> V_125 . V_126 == 0 )
return;
memcpy ( V_124 -> V_127 . V_128 ,
V_93 -> V_125 . V_129 ,
V_93 -> V_125 . V_126 ) ;
V_124 -> V_127 . V_130 =
( V_93 -> V_125 . V_126 ) / 4 ;
}
static V_28 F_44 ( struct V_15 * V_16 ,
struct V_92 * V_93 )
{
union V_131 V_132 = { 0 } ;
union V_133 V_134 = { 0 } ;
struct V_135 * V_86 = V_93 -> V_136 -> V_137 ;
switch ( V_93 -> V_138 ) {
case V_139 :
V_132 . V_140 . V_141 =
( V_142 == V_93 -> V_143 ) ?
V_144 :
V_145 ;
V_132 . V_140 . V_146 = V_86 -> V_147 +
( V_93 -> V_148 << 3 ) ;
break;
case V_149 :
V_132 . V_140 . V_141 =
( V_142 == V_93 -> V_143 ) ?
V_144 :
V_145 ;
V_134 . V_150 . V_151 = V_93 -> V_152 ;
V_134 . V_150 . V_153 = V_93 -> V_148 ;
V_132 . V_140 . V_146 = V_134 . V_154 ;
break;
case V_155 :
V_132 . V_140 . V_141 = V_156 ;
V_132 . V_140 . V_146 = V_93 -> V_148 +
( V_93 -> V_152 ) ;
break;
case V_157 :
V_132 . V_140 . V_141 =
( V_142 == V_93 -> V_143 ) ?
V_158 :
V_159 ;
V_132 . V_140 . V_146 = V_86 -> V_160 ;
break;
case V_161 :
V_132 . V_140 . V_141 =
( V_142 == V_93 -> V_143 ) ?
V_162 :
V_163 ;
V_132 . V_140 . V_146 = V_86 -> V_147 ;
break;
default:
V_132 . V_154 = 0xFFFFFFFF ;
break;
}
return V_132 . V_154 ;
}
static void F_45 ( struct V_15 * V_16 ,
struct V_92 * V_93 ,
struct V_123 * V_124 )
{
V_28 V_164 ;
struct V_98 * V_99 ;
int V_101 = V_93 -> V_101 ;
struct V_55 * V_55 = F_46 ( V_16 -> V_2 ) ;
V_124 -> V_127 . V_132 = F_44 ( V_16 , V_93 ) ;
if ( V_124 -> V_127 . V_132 == V_165 ) {
V_124 -> V_166 = 0 ;
return;
}
if ( V_55 -> V_167 ) {
V_99 = & V_93 -> V_97 -> V_100 [ V_93 -> V_101 ] ;
V_124 -> V_127 . V_168 = V_99 -> V_168 ;
goto V_169;
} else {
V_99 = & V_93 -> V_97 -> V_100 [ V_101 ] ;
}
switch ( V_93 -> V_143 ) {
case V_142 :
if ( V_93 -> V_138 == V_161 )
V_164 = V_99 -> V_120 ;
else
V_164 = V_99 -> V_121 ;
break;
case V_170 :
if ( V_93 -> V_138 == V_161 )
V_164 = V_99 -> V_121 ;
else
V_164 = V_99 -> V_120 ;
break;
default:
F_47 ( V_16 -> V_2 , L_4 ,
V_93 -> V_143 ) ;
return;
}
V_124 -> V_127 . V_168 =
V_93 -> V_168 * V_164 ;
if ( ! V_124 -> V_127 . V_168 ) {
if ( V_93 -> V_143 == V_142 )
V_124 -> V_127 . V_168 = 2 * V_99 -> V_121 ;
else
V_124 -> V_127 . V_168 = 2 * V_99 -> V_120 ;
}
V_169:
V_124 -> V_166 = 0 ;
V_124 -> V_127 . V_130 = 0 ;
F_43 ( V_93 , V_124 ) ;
}
int F_48 ( struct V_15 * V_16 , struct V_92 * V_93 )
{
struct V_171 * V_172 ;
struct V_20 V_21 = { 0 } ;
int V_173 = 0 ;
if ( V_93 -> V_125 . V_126 == 0 )
return 0 ;
V_21 . V_24 = V_174 ;
V_21 . V_26 = sizeof( struct V_171 ) +
V_93 -> V_125 . V_126 ;
V_172 = F_49 ( V_21 . V_26 , V_70 ) ;
if ( V_172 == NULL )
return - V_71 ;
V_172 -> V_132 = F_44 ( V_16 , V_93 ) ;
V_172 -> V_130 = V_93 -> V_125 . V_126 / 4 ;
memcpy ( V_172 -> V_128 , V_93 -> V_125 . V_129 ,
V_93 -> V_125 . V_126 ) ;
V_173 = F_6 ( & V_16 -> V_27 , & V_21 , ( V_28 * ) V_172 ) ;
F_31 ( V_172 ) ;
return V_173 ;
}
static void F_50 ( struct V_15 * V_16 ,
struct V_92 * V_93 ,
struct V_175 * V_176 )
{
struct V_96 * V_97 = V_93 -> V_97 ;
struct V_102 * V_103 = & V_97 -> V_104 [ V_93 -> V_105 ] ;
struct V_106 * V_37 = & V_103 -> V_177 [ 0 ] . V_103 ;
V_176 -> V_109 = ( V_178 ) V_37 -> V_110 ;
V_176 -> V_111 = V_37 -> V_111 ;
V_176 -> V_112 = V_37 -> V_112 ;
V_176 -> V_113 = V_37 -> V_113 ;
V_176 -> V_114 = V_37 -> V_114 ;
V_176 -> V_115 = V_37 -> V_116 ;
V_176 -> V_117 = V_37 -> V_118 ;
V_176 -> V_179 = V_37 -> V_179 ;
F_30 ( V_16 -> V_2 , L_5 ,
V_176 -> V_109 , V_37 -> V_111 , V_37 -> V_112 ) ;
}
static void F_51 ( struct V_15 * V_16 ,
struct V_92 * V_93 ,
struct V_180 * V_181 )
{
struct V_96 * V_97 = V_93 -> V_97 ;
struct V_102 * V_182 = & V_97 -> V_104 [ V_93 -> V_105 ] ;
struct V_106 * V_103 = & V_182 -> V_177 [ 0 ] . V_103 ;
F_42 ( V_16 , V_93 ,
(struct V_94 * ) V_181 ) ;
V_181 -> V_183 = V_103 -> V_111 ;
}
static void F_52 ( struct V_15 * V_16 ,
struct V_92 * V_93 ,
struct V_184 * V_185 )
{
struct V_96 * V_97 = V_93 -> V_97 ;
struct V_102 * V_182 = & V_97 -> V_104 [ V_93 -> V_105 ] ;
struct V_106 * V_103 = & V_182 -> V_177 [ 0 ] . V_103 ;
int V_52 = 0 ;
F_42 ( V_16 , V_93 ,
(struct V_94 * ) V_185 ) ;
V_185 -> V_186 = V_103 -> V_114 ;
V_185 -> V_187 = 0x0 ;
for ( V_52 = 0 ; V_52 < V_188 ; V_52 ++ )
V_185 -> V_189 [ V_52 ] = 0xDEADBEEF ;
}
static void F_53 ( struct V_15 * V_16 ,
struct V_92 * V_93 ,
struct V_123 * V_124 )
{
struct V_175 * V_176 = & V_124 -> V_176 ;
struct V_94 * V_95 = (struct V_94 * ) V_124 ;
F_42 ( V_16 , V_93 , V_95 ) ;
F_50 ( V_16 , V_93 , V_176 ) ;
F_45 ( V_16 , V_93 , V_124 ) ;
}
static void F_54 ( struct V_15 * V_16 ,
struct V_92 * V_93 ,
struct V_190 * V_191 )
{
struct V_94 * V_95 = (struct V_94 * ) V_191 ;
F_42 ( V_16 , V_93 , V_95 ) ;
if ( V_93 -> V_125 . V_126 == 0 )
return;
memcpy ( V_191 -> V_86 ,
V_93 -> V_125 . V_129 ,
V_93 -> V_125 . V_126 ) ;
}
static void F_55 ( struct V_15 * V_16 ,
struct V_92 * V_93 ,
struct V_192 * V_193 )
{
struct V_175 * V_176 = & V_193 -> V_176 ;
struct V_94 * V_95 =
(struct V_94 * ) V_193 ;
F_42 ( V_16 , V_93 , V_95 ) ;
F_50 ( V_16 , V_93 , V_176 ) ;
}
static T_3 F_56 ( struct V_15 * V_16 ,
struct V_92 * V_93 )
{
T_3 V_194 ;
switch ( V_93 -> V_195 ) {
case V_196 :
V_194 = sizeof( struct V_123 ) ;
V_194 += V_93 -> V_125 . V_126 ;
return V_194 ;
case V_197 :
return sizeof( struct V_180 ) ;
case V_198 :
return sizeof( struct V_184 ) ;
case V_199 :
V_194 = sizeof( struct V_94 ) ;
V_194 += V_93 -> V_125 . V_126 ;
return V_194 ;
case V_200 :
case V_201 :
case V_202 :
return sizeof( struct V_192 ) ;
default:
return sizeof( struct V_94 ) ;
}
return 0 ;
}
static int F_57 ( struct V_15 * V_16 ,
struct V_92 * V_203 ,
T_3 * V_204 ,
void * * V_205 )
{
T_3 V_194 ;
V_194 = F_56 ( V_16 , V_203 ) ;
* V_205 = F_49 ( V_194 , V_70 ) ;
if ( NULL == * V_205 )
return - V_71 ;
* V_204 = V_194 ;
switch ( V_203 -> V_195 ) {
case V_196 :
F_53 ( V_16 , V_203 , * V_205 ) ;
break;
case V_197 :
F_51 ( V_16 , V_203 , * V_205 ) ;
break;
case V_198 :
F_52 ( V_16 , V_203 , * V_205 ) ;
break;
case V_199 :
F_54 ( V_16 , V_203 , * V_205 ) ;
break;
case V_200 :
case V_201 :
case V_202 :
F_55 ( V_16 , V_203 , * V_205 ) ;
break;
default:
F_42 ( V_16 , V_203 , * V_205 ) ;
break;
}
F_30 ( V_16 -> V_2 , L_6 ,
V_203 -> V_54 . V_206 , V_194 ) ;
F_58 ( L_7 , V_207 , 8 , 4 ,
* V_205 , V_194 , false ) ;
return 0 ;
}
static int F_59 ( struct V_208 * V_209 ,
struct V_210 V_54 , int V_211 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_211 ; V_52 ++ ) {
if ( V_209 [ V_52 ] . V_54 . V_206 == V_54 . V_206 &&
V_209 [ V_52 ] . V_54 . V_212 == V_54 . V_212 )
return V_52 ;
}
return - V_35 ;
}
static int F_60 ( struct V_208 * V_209 ,
struct V_92 * V_213 , int V_211 )
{
int V_52 ;
struct V_210 V_54 = V_213 -> V_54 ;
for ( V_52 = 0 ; V_52 < V_211 ; V_52 ++ ) {
if ( V_209 [ V_52 ] . V_214 ) {
if ( ! V_209 [ V_52 ] . V_215 &&
V_209 [ V_52 ] . V_216 == V_217 ) {
V_209 [ V_52 ] . V_215 = true ;
V_209 [ V_52 ] . V_54 . V_206 = V_54 . V_206 ;
V_209 [ V_52 ] . V_54 . V_212 = V_54 . V_212 ;
V_209 [ V_52 ] . V_54 . V_218 = V_54 . V_218 ;
V_209 [ V_52 ] . V_219 = V_213 ;
return V_52 ;
}
} else {
if ( V_209 [ V_52 ] . V_54 . V_206 == V_54 . V_206 &&
V_209 [ V_52 ] . V_54 . V_212 == V_54 . V_212 &&
V_209 [ V_52 ] . V_216 == V_217 ) {
V_209 [ V_52 ] . V_219 = V_213 ;
return V_52 ;
}
}
}
return - V_35 ;
}
static void F_61 ( struct V_208 * V_209 , int V_220 )
{
if ( V_209 [ V_220 ] . V_214 ) {
V_209 [ V_220 ] . V_215 = false ;
V_209 [ V_220 ] . V_54 . V_206 = 0 ;
V_209 [ V_220 ] . V_54 . V_212 = 0 ;
V_209 [ V_220 ] . V_54 . V_218 = 0 ;
}
V_209 [ V_220 ] . V_216 = V_217 ;
V_209 [ V_220 ] . V_219 = NULL ;
}
static void F_62 ( struct V_208 * V_209 , int V_211 ,
struct V_92 * V_221 )
{
int V_52 ;
bool V_222 = false ;
for ( V_52 = 0 ; V_52 < V_211 ; V_52 ++ ) {
if ( V_209 [ V_52 ] . V_216 == V_217 )
continue;
V_222 = true ;
break;
}
if ( ! V_222 )
V_221 -> V_223 = V_224 ;
return;
}
int F_63 ( struct V_15 * V_16 ,
struct V_92 * V_93 )
{
T_3 V_204 = 0 ;
void * V_205 = NULL ;
int V_40 ;
struct V_225 V_21 ;
F_30 ( V_16 -> V_2 , L_8 , V_226 ,
V_93 -> V_54 . V_206 , V_93 -> V_54 . V_218 ) ;
if ( V_93 -> V_136 -> V_69 != V_227 ) {
F_28 ( V_16 -> V_2 , L_9 ,
V_93 -> V_136 -> V_69 , V_93 -> V_136 -> V_228 ) ;
return - V_63 ;
}
V_40 = F_57 ( V_16 , V_93 ,
& V_204 , & V_205 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_10 , V_40 ) ;
return V_40 ;
}
V_21 . V_206 = V_93 -> V_54 . V_206 ;
V_21 . V_212 = V_93 -> V_54 . V_218 ;
V_21 . V_229 = V_93 -> V_136 -> V_228 ;
V_21 . V_26 = V_204 ;
V_21 . V_230 = V_93 -> V_230 ;
V_21 . V_231 = V_93 -> V_231 ;
V_40 = F_64 ( & V_16 -> V_27 , & V_21 , V_205 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_11 , V_40 ) ;
F_31 ( V_205 ) ;
return V_40 ;
}
V_93 -> V_223 = V_224 ;
F_31 ( V_205 ) ;
return V_40 ;
}
static void F_65 ( struct V_15 * V_16 , struct V_92
* V_232 , struct V_92 * V_233 )
{
F_30 ( V_16 -> V_2 , L_12 ,
V_226 , V_232 -> V_54 . V_206 , V_232 -> V_54 . V_218 ) ;
F_30 ( V_16 -> V_2 , L_13 , V_226 ,
V_233 -> V_54 . V_206 , V_233 -> V_54 . V_218 ) ;
F_30 ( V_16 -> V_2 , L_14 ,
V_232 -> V_223 , V_233 -> V_223 ) ;
}
int F_66 ( struct V_15 * V_16 ,
struct V_92 * V_234 ,
struct V_92 * V_235 )
{
int V_40 ;
struct V_236 V_21 ;
struct V_210 V_237 = V_234 -> V_54 ;
struct V_210 V_238 = V_235 -> V_54 ;
int V_239 = V_235 -> V_97 -> V_240 ;
int V_241 = V_234 -> V_97 -> V_242 ;
int V_243 , V_244 , V_245 , V_246 ;
F_65 ( V_16 , V_234 , V_235 ) ;
V_243 = F_59 ( V_234 -> V_247 , V_238 , V_241 ) ;
if ( V_243 < 0 )
return 0 ;
V_21 . V_248 = V_243 ;
V_244 = F_59 ( V_235 -> V_249 , V_237 , V_239 ) ;
if ( V_244 < 0 )
return 0 ;
V_21 . V_250 = V_244 ;
V_245 = V_234 -> V_247 [ V_243 ] . V_216 ;
V_246 = V_235 -> V_249 [ V_244 ] . V_216 ;
if ( V_245 != V_251 ||
V_246 != V_251 )
return 0 ;
V_21 . V_206 = V_234 -> V_54 . V_206 ;
V_21 . V_212 = V_234 -> V_54 . V_218 ;
V_21 . V_252 = V_235 -> V_54 . V_206 ;
V_21 . V_253 = V_235 -> V_54 . V_218 ;
V_21 . V_254 = false ;
V_40 = F_67 ( & V_16 -> V_27 , & V_21 ) ;
if ( ! V_40 ) {
F_61 ( V_234 -> V_247 , V_243 ) ;
F_61 ( V_235 -> V_249 , V_244 ) ;
F_62 ( V_234 -> V_247 , V_241 , V_234 ) ;
}
return V_40 ;
}
static void F_68 ( struct V_175 * V_255 ,
struct V_106 * V_37 )
{
V_255 -> V_109 = V_37 -> V_110 ;
V_255 -> V_111 = V_37 -> V_111 ;
V_255 -> V_112 = V_37 -> V_112 ;
V_255 -> V_113 = V_37 -> V_113 ;
V_255 -> V_114 = V_37 -> V_114 ;
V_255 -> V_179 = V_37 -> V_179 ;
V_255 -> V_115 = V_37 -> V_116 ;
V_255 -> V_117 = V_37 -> V_118 ;
}
int F_69 ( struct V_15 * V_16 ,
struct V_92 * V_234 ,
struct V_92 * V_235 )
{
int V_40 = 0 ;
struct V_236 V_21 ;
int V_239 = V_235 -> V_97 -> V_240 ;
int V_241 = V_234 -> V_97 -> V_242 ;
int V_243 , V_244 ;
struct V_106 * V_37 ;
struct V_256 V_255 ;
struct V_96 * V_97 ;
struct V_102 * V_103 ;
F_65 ( V_16 , V_234 , V_235 ) ;
if ( V_234 -> V_223 < V_224 ||
V_235 -> V_223 < V_224 )
return 0 ;
V_243 = F_60 ( V_234 -> V_247 , V_235 , V_241 ) ;
if ( V_243 < 0 )
return - V_35 ;
V_21 . V_248 = V_243 ;
V_244 = F_60 ( V_235 -> V_249 , V_234 , V_239 ) ;
if ( V_244 < 0 ) {
F_61 ( V_234 -> V_247 , V_243 ) ;
return - V_35 ;
}
if ( V_234 -> V_195 == V_196 && V_243 > 0 ) {
V_255 . V_257 = V_243 ;
V_97 = V_234 -> V_97 ;
V_103 = & V_97 -> V_104 [ V_234 -> V_105 ] ;
V_37 = & V_103 -> V_107 [ 0 ] . V_103 ;
F_68 ( & ( V_255 . V_258 ) , V_37 ) ;
V_37 = & V_103 -> V_177 [ V_243 ] . V_103 ;
F_68 ( & ( V_255 . V_259 ) , V_37 ) ;
V_40 = F_70 ( V_16 , ( void * ) & V_255 ,
sizeof( struct V_256 ) ,
V_260 , V_234 ) ;
if ( V_40 < 0 )
goto V_261;
}
V_21 . V_250 = V_244 ;
F_30 ( V_16 -> V_2 , L_15 ,
V_21 . V_248 , V_21 . V_250 ) ;
V_21 . V_206 = V_234 -> V_54 . V_206 ;
V_21 . V_212 = V_234 -> V_54 . V_218 ;
V_21 . V_252 = V_235 -> V_54 . V_206 ;
V_21 . V_253 = V_235 -> V_54 . V_218 ;
V_21 . V_254 = true ;
V_40 = F_67 ( & V_16 -> V_27 , & V_21 ) ;
if ( ! V_40 ) {
V_234 -> V_223 = V_262 ;
V_234 -> V_247 [ V_243 ] . V_216 = V_251 ;
V_235 -> V_249 [ V_244 ] . V_216 = V_251 ;
return V_40 ;
}
V_261:
F_61 ( V_234 -> V_247 , V_243 ) ;
F_61 ( V_235 -> V_249 , V_244 ) ;
return V_40 ;
}
static int F_71 ( struct V_15 * V_16 , struct V_263 * V_136 ,
enum V_264 V_69 )
{
F_30 ( V_16 -> V_2 , L_16 , V_226 , V_69 ) ;
return F_72 ( & V_16 -> V_27 , V_136 -> V_228 , V_69 ) ;
}
int F_73 ( struct V_15 * V_16 , struct V_263 * V_136 )
{
int V_40 ;
F_30 ( V_16 -> V_2 , L_17 , V_226 , V_136 -> V_228 ) ;
V_40 = F_74 ( & V_16 -> V_27 , V_136 -> V_265 ,
V_136 -> V_266 , V_136 -> V_228 ,
V_136 -> V_267 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_18 ) ;
return V_40 ;
}
V_136 -> V_69 = V_227 ;
return 0 ;
}
int F_75 ( struct V_15 * V_16 , struct V_263 * V_136 )
{
int V_40 ;
F_30 ( V_16 -> V_2 , L_19 , V_226 , V_136 -> V_228 ) ;
if ( V_136 -> V_69 >= V_268 ) {
V_40 = F_71 ( V_16 , V_136 , V_269 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_20 ) ;
return V_40 ;
}
V_136 -> V_69 = V_270 ;
}
if ( V_136 -> V_69 < V_227 )
return 0 ;
V_40 = F_76 ( & V_16 -> V_27 , V_136 -> V_228 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_21 ) ;
return V_40 ;
}
V_136 -> V_69 = V_271 ;
return V_40 ;
}
int F_77 ( struct V_15 * V_16 , struct V_263 * V_136 )
{
int V_40 ;
F_30 ( V_16 -> V_2 , L_19 , V_226 , V_136 -> V_228 ) ;
if ( V_136 -> V_69 < V_227 )
return 0 ;
V_40 = F_71 ( V_16 , V_136 , V_269 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_22 ) ;
return V_40 ;
}
V_136 -> V_69 = V_270 ;
V_40 = F_71 ( V_16 , V_136 , V_272 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_23 ) ;
return V_40 ;
}
V_136 -> V_69 = V_268 ;
return 0 ;
}
int F_78 ( struct V_15 * V_16 , struct V_263 * V_136 )
{
int V_40 ;
F_30 ( V_16 -> V_2 , L_24 , V_226 , V_136 -> V_228 ) ;
if ( V_136 -> V_69 < V_270 )
return 0 ;
V_40 = F_71 ( V_16 , V_136 , V_269 ) ;
if ( V_40 < 0 ) {
F_30 ( V_16 -> V_2 , L_25 ) ;
return V_40 ;
}
V_136 -> V_69 = V_270 ;
return 0 ;
}
int F_79 ( struct V_15 * V_16 , struct V_263 * V_136 )
{
int V_40 ;
if ( V_136 -> V_69 < V_270 )
return 0 ;
V_40 = F_71 ( V_16 , V_136 , V_273 ) ;
if ( V_40 < 0 ) {
F_30 ( V_16 -> V_2 , L_26 , V_40 ) ;
return V_40 ;
}
V_136 -> V_69 = V_274 ;
return 0 ;
}
int F_70 ( struct V_15 * V_16 , V_28 * V_86 , int V_5 ,
V_28 V_275 , struct V_92 * V_221 )
{
struct V_20 V_21 ;
V_21 . V_206 = V_221 -> V_54 . V_206 ;
V_21 . V_212 = V_221 -> V_54 . V_218 ;
V_21 . V_26 = V_5 ;
V_21 . V_24 = V_275 ;
return F_6 ( & V_16 -> V_27 , & V_21 , V_86 ) ;
}
int F_80 ( struct V_15 * V_16 , V_28 * V_86 , int V_5 ,
V_28 V_275 , struct V_92 * V_221 )
{
struct V_20 V_21 ;
V_21 . V_206 = V_221 -> V_54 . V_206 ;
V_21 . V_212 = V_221 -> V_54 . V_218 ;
V_21 . V_26 = V_5 ;
V_21 . V_24 = V_275 ;
return F_81 ( & V_16 -> V_27 , & V_21 , V_86 ) ;
}
