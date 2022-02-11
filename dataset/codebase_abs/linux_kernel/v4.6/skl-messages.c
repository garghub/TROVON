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
static void F_5 ( struct V_15 * V_16 , bool V_17 )
{
struct V_18 V_19 ;
struct V_20 V_21 = { 0 } ;
V_19 . V_22 = V_23 ;
V_19 . V_17 = V_17 ;
V_21 . V_24 = V_25 ;
V_21 . V_26 = sizeof( V_19 ) ;
F_6 ( & V_16 -> V_27 , & V_21 , ( V_28 * ) & V_19 ) ;
}
static struct V_29 F_7 ( void )
{
struct V_29 V_30 ;
memset ( & V_30 , 0 , sizeof( struct V_29 ) ) ;
V_30 . V_31 = F_1 ;
V_30 . V_32 = F_4 ;
return V_30 ;
}
static int F_8 ( int V_33 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < F_9 ( V_35 ) ; V_34 ++ ) {
if ( V_35 [ V_34 ] . V_36 == V_33 )
return V_34 ;
}
return - V_37 ;
}
int F_10 ( struct V_38 * V_38 )
{
void T_2 * V_39 ;
struct V_6 * V_7 = & V_38 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_29 V_30 ;
int V_40 = V_9 -> V_40 ;
int V_41 , V_42 ;
F_11 ( & V_38 -> V_7 , true ) ;
F_12 ( & V_38 -> V_7 , true ) ;
V_39 = F_13 ( V_38 -> V_43 , 4 ) ;
if ( V_39 == NULL ) {
F_14 ( V_9 -> V_2 , L_1 ) ;
return - V_44 ;
}
V_42 = F_8 ( V_38 -> V_43 -> V_1 ) ;
if ( V_42 < 0 )
return - V_37 ;
V_30 = V_35 [ V_42 ] . V_30 () ;
V_41 = V_35 [ V_42 ] . F_15 ( V_9 -> V_2 , V_39 , V_40 ,
V_38 -> V_45 , V_30 , & V_38 -> V_15 ) ;
if ( V_41 < 0 )
return V_41 ;
F_5 ( V_38 -> V_15 , false ) ;
F_16 ( V_9 -> V_2 , L_2 , V_41 ) ;
return V_41 ;
}
int F_17 ( struct V_38 * V_38 )
{
struct V_6 * V_7 = & V_38 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_15 * V_16 = V_38 -> V_15 ;
int V_42 ;
F_12 ( & V_38 -> V_7 , false ) ;
V_42 = F_8 ( V_38 -> V_43 -> V_1 ) ;
if ( V_42 < 0 )
return - V_46 ;
V_35 [ V_42 ] . F_18 ( V_9 -> V_2 , V_16 ) ;
if ( V_16 -> V_47 -> V_48 . V_49 )
F_19 ( V_16 -> V_47 -> V_48 . V_49 ) ;
return 0 ;
}
int F_20 ( struct V_38 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_15 ;
int V_41 ;
if ( ! V_38 -> V_7 . V_50 )
return 0 ;
V_41 = F_21 ( V_16 -> V_47 ) ;
if ( V_41 < 0 )
return V_41 ;
F_12 ( & V_38 -> V_7 , false ) ;
F_11 ( & V_38 -> V_7 , false ) ;
return 0 ;
}
int F_22 ( struct V_38 * V_38 )
{
struct V_15 * V_16 = V_38 -> V_15 ;
int V_41 ;
if ( ! V_38 -> V_7 . V_50 )
return 0 ;
F_11 ( & V_38 -> V_7 , true ) ;
F_12 ( & V_38 -> V_7 , true ) ;
V_41 = F_23 ( V_16 -> V_47 ) ;
if ( V_41 < 0 )
return V_41 ;
F_5 ( V_38 -> V_15 , false ) ;
return V_41 ;
}
enum V_51 F_24 ( int V_52 )
{
switch ( V_52 ) {
case 8 :
return V_53 ;
case 16 :
return V_54 ;
case 24 :
return V_55 ;
case 32 :
return V_56 ;
default:
return V_57 ;
}
}
static void F_25 ( struct V_15 * V_16 ,
struct V_58 * V_59 ,
struct V_60 * V_61 )
{
struct V_62 * V_63 = & V_59 -> V_64 [ 0 ] ;
V_61 -> V_65 . V_66 = ( V_67 ) V_63 -> V_68 ;
V_61 -> V_65 . V_69 = V_63 -> V_69 ;
V_61 -> V_65 . V_70 = V_63 -> V_70 ;
V_61 -> V_65 . V_71 = V_63 -> V_71 ;
V_61 -> V_65 . V_72 = V_63 -> V_72 ;
F_16 ( V_16 -> V_2 , L_3 ,
V_63 -> V_70 , V_63 -> V_71 ,
V_63 -> V_72 ) ;
V_61 -> V_65 . V_73 = V_63 -> V_74 ;
V_61 -> V_65 . V_75 = V_63 -> V_76 ;
V_61 -> V_77 = V_59 -> V_78 ;
V_61 -> V_79 = V_59 -> V_79 ;
V_61 -> V_80 = V_59 -> V_80 ;
V_61 -> V_81 = V_59 -> V_82 ;
}
static void F_26 ( struct V_58 * V_59 ,
struct V_83 * V_84 )
{
if ( V_59 -> V_85 . V_86 == 0 )
return;
memcpy ( V_84 -> V_87 . V_88 ,
V_59 -> V_85 . V_89 ,
V_59 -> V_85 . V_86 ) ;
V_84 -> V_87 . V_90 =
( V_59 -> V_85 . V_86 ) / 4 ;
}
static V_28 F_27 ( struct V_15 * V_16 ,
struct V_58 * V_59 )
{
union V_91 V_92 = { 0 } ;
union V_93 V_94 = { 0 } ;
struct V_95 * V_52 = V_59 -> V_96 -> V_97 ;
switch ( V_59 -> V_98 ) {
case V_99 :
V_92 . V_100 . V_101 =
( V_102 == V_59 -> V_103 ) ?
V_104 :
V_105 ;
V_92 . V_100 . V_106 = V_52 -> V_107 +
( V_59 -> V_108 << 3 ) ;
break;
case V_109 :
V_92 . V_100 . V_101 =
( V_102 == V_59 -> V_103 ) ?
V_104 :
V_105 ;
V_94 . V_110 . V_111 = V_59 -> V_112 ;
V_94 . V_110 . V_113 = V_59 -> V_108 ;
V_92 . V_100 . V_106 = V_94 . V_114 ;
break;
case V_115 :
V_92 . V_100 . V_101 = V_116 ;
V_92 . V_100 . V_106 = V_59 -> V_108 +
( V_59 -> V_112 ) ;
break;
case V_117 :
V_92 . V_100 . V_101 =
( V_102 == V_59 -> V_103 ) ?
V_118 :
V_119 ;
V_92 . V_100 . V_106 = V_52 -> V_120 ;
break;
case V_121 :
V_92 . V_100 . V_101 =
( V_102 == V_59 -> V_103 ) ?
V_122 :
V_123 ;
V_92 . V_100 . V_106 = V_52 -> V_107 ;
break;
default:
V_92 . V_114 = 0xFFFFFFFF ;
break;
}
return V_92 . V_114 ;
}
static void F_28 ( struct V_15 * V_16 ,
struct V_58 * V_59 ,
struct V_83 * V_84 )
{
V_84 -> V_87 . V_92 = F_27 ( V_16 , V_59 ) ;
if ( V_84 -> V_87 . V_92 == V_124 ) {
V_84 -> V_125 = 0 ;
return;
}
if ( V_102 == V_59 -> V_103 )
V_84 -> V_87 . V_126 = 2 * V_59 -> V_80 ;
else
V_84 -> V_87 . V_126 = 2 * V_59 -> V_79 ;
V_84 -> V_125 = 0 ;
V_84 -> V_87 . V_90 = 0 ;
F_26 ( V_59 , V_84 ) ;
}
int F_29 ( struct V_15 * V_16 , struct V_58 * V_59 )
{
struct V_127 * V_128 ;
struct V_129 V_130 ;
struct V_20 V_21 = { 0 } ;
int V_131 = 0 ;
if ( V_59 -> V_85 . V_86 == sizeof( V_130 ) )
return 0 ;
V_21 . V_24 = V_132 ;
V_21 . V_26 = sizeof( struct V_127 ) +
V_59 -> V_85 . V_86 ;
V_128 = F_30 ( V_21 . V_26 , V_133 ) ;
if ( V_128 == NULL )
return - V_134 ;
V_128 -> V_92 = F_27 ( V_16 , V_59 ) ;
V_128 -> V_90 = sizeof( V_130 ) / 4 ;
memcpy ( V_128 -> V_88 , V_59 -> V_85 . V_89 ,
V_59 -> V_85 . V_86 ) ;
V_131 = F_6 ( & V_16 -> V_27 , & V_21 , ( V_28 * ) V_128 ) ;
F_31 ( V_128 ) ;
return V_131 ;
}
static void F_32 ( struct V_15 * V_16 ,
struct V_58 * V_59 ,
struct V_135 * V_136 )
{
struct V_62 * V_63 = & V_59 -> V_136 [ 0 ] ;
V_136 -> V_66 = ( V_67 ) V_63 -> V_68 ;
V_136 -> V_69 = V_63 -> V_69 ;
V_136 -> V_70 = V_63 -> V_70 ;
V_136 -> V_71 = V_63 -> V_71 ;
V_136 -> V_72 = V_63 -> V_72 ;
V_136 -> V_73 = V_63 -> V_74 ;
V_136 -> V_75 = V_63 -> V_76 ;
V_136 -> V_137 = V_63 -> V_137 ;
F_16 ( V_16 -> V_2 , L_4 ,
V_136 -> V_66 , V_63 -> V_69 , V_63 -> V_70 ) ;
}
static void F_33 ( struct V_15 * V_16 ,
struct V_58 * V_59 ,
struct V_138 * V_139 )
{
struct V_62 * V_140 = & V_59 -> V_136 [ 0 ] ;
F_25 ( V_16 , V_59 ,
(struct V_60 * ) V_139 ) ;
V_139 -> V_141 = V_140 -> V_69 ;
}
static void F_34 ( struct V_15 * V_16 ,
struct V_58 * V_59 ,
struct V_142 * V_143 )
{
struct V_62 * V_140 = & V_59 -> V_136 [ 0 ] ;
int V_34 = 0 ;
F_25 ( V_16 , V_59 ,
(struct V_60 * ) V_143 ) ;
V_143 -> V_144 = V_140 -> V_72 ;
V_143 -> V_145 = 0x0 ;
for ( V_34 = 0 ; V_34 < V_146 ; V_34 ++ )
V_143 -> V_147 [ V_34 ] = 0xDEADBEEF ;
}
static void F_35 ( struct V_15 * V_16 ,
struct V_58 * V_59 ,
struct V_83 * V_84 )
{
struct V_135 * V_136 = & V_84 -> V_136 ;
struct V_60 * V_61 = (struct V_60 * ) V_84 ;
F_25 ( V_16 , V_59 , V_61 ) ;
F_32 ( V_16 , V_59 , V_136 ) ;
F_28 ( V_16 , V_59 , V_84 ) ;
}
static void F_36 ( struct V_15 * V_16 ,
struct V_58 * V_59 ,
struct V_148 * V_149 )
{
struct V_60 * V_61 = (struct V_60 * ) V_149 ;
F_25 ( V_16 , V_59 , V_61 ) ;
if ( V_59 -> V_85 . V_86 == 0 )
return;
memcpy ( V_149 -> V_52 ,
V_59 -> V_85 . V_89 ,
V_59 -> V_85 . V_86 ) ;
}
static void F_37 ( struct V_15 * V_16 ,
struct V_58 * V_59 ,
struct V_150 * V_151 )
{
struct V_135 * V_136 = & V_151 -> V_136 ;
struct V_60 * V_61 =
(struct V_60 * ) V_151 ;
F_25 ( V_16 , V_59 , V_61 ) ;
F_32 ( V_16 , V_59 , V_136 ) ;
}
static T_3 F_38 ( struct V_15 * V_16 ,
struct V_58 * V_59 )
{
T_3 V_152 ;
switch ( V_59 -> V_153 ) {
case V_154 :
V_152 = sizeof( struct V_83 ) ;
V_152 += V_59 -> V_85 . V_86 ;
return V_152 ;
case V_155 :
return sizeof( struct V_138 ) ;
case V_156 :
return sizeof( struct V_142 ) ;
case V_157 :
V_152 = sizeof( struct V_60 ) ;
V_152 += V_59 -> V_85 . V_86 ;
return V_152 ;
case V_158 :
return sizeof( struct V_150 ) ;
default:
return sizeof( struct V_60 ) ;
}
return 0 ;
}
static int F_39 ( struct V_15 * V_16 ,
struct V_58 * V_159 ,
T_3 * V_160 ,
void * * V_161 )
{
T_3 V_152 ;
V_152 = F_38 ( V_16 , V_159 ) ;
* V_161 = F_30 ( V_152 , V_133 ) ;
if ( NULL == * V_161 )
return - V_134 ;
* V_160 = V_152 ;
switch ( V_159 -> V_153 ) {
case V_154 :
F_35 ( V_16 , V_159 , * V_161 ) ;
break;
case V_155 :
F_33 ( V_16 , V_159 , * V_161 ) ;
break;
case V_156 :
F_34 ( V_16 , V_159 , * V_161 ) ;
break;
case V_157 :
F_36 ( V_16 , V_159 , * V_161 ) ;
break;
case V_158 :
F_37 ( V_16 , V_159 , * V_161 ) ;
break;
default:
F_25 ( V_16 , V_159 , * V_161 ) ;
break;
}
F_16 ( V_16 -> V_2 , L_5 ,
V_159 -> V_36 . V_162 , V_152 ) ;
F_40 ( V_163 , L_6 , V_164 , 8 , 4 ,
* V_161 , V_152 , false ) ;
return 0 ;
}
static int F_41 ( struct V_165 * V_166 ,
struct V_167 V_36 , int V_168 )
{
int V_34 ;
for ( V_34 = 0 ; V_34 < V_168 ; V_34 ++ ) {
if ( V_166 [ V_34 ] . V_36 . V_162 == V_36 . V_162 &&
V_166 [ V_34 ] . V_36 . V_169 == V_36 . V_169 )
return V_34 ;
}
return - V_37 ;
}
static int F_42 ( struct V_165 * V_166 ,
struct V_58 * V_170 , int V_168 )
{
int V_34 ;
struct V_167 V_36 = V_170 -> V_36 ;
for ( V_34 = 0 ; V_34 < V_168 ; V_34 ++ ) {
if ( V_166 [ V_34 ] . V_171 ) {
if ( ! V_166 [ V_34 ] . V_172 &&
V_166 [ V_34 ] . V_173 == V_174 ) {
V_166 [ V_34 ] . V_172 = true ;
V_166 [ V_34 ] . V_36 . V_162 = V_36 . V_162 ;
V_166 [ V_34 ] . V_36 . V_169 = V_36 . V_169 ;
V_166 [ V_34 ] . V_175 = V_170 ;
return V_34 ;
}
} else {
if ( V_166 [ V_34 ] . V_36 . V_162 == V_36 . V_162 &&
V_166 [ V_34 ] . V_36 . V_169 == V_36 . V_169 &&
V_166 [ V_34 ] . V_173 == V_174 ) {
V_166 [ V_34 ] . V_175 = V_170 ;
return V_34 ;
}
}
}
return - V_37 ;
}
static void F_43 ( struct V_165 * V_166 , int V_176 )
{
if ( V_166 [ V_176 ] . V_171 ) {
V_166 [ V_176 ] . V_172 = false ;
V_166 [ V_176 ] . V_36 . V_162 = 0 ;
V_166 [ V_176 ] . V_36 . V_169 = 0 ;
}
V_166 [ V_176 ] . V_173 = V_174 ;
V_166 [ V_176 ] . V_175 = NULL ;
}
static void F_44 ( struct V_165 * V_166 , int V_168 ,
struct V_58 * V_177 )
{
int V_34 ;
bool V_178 = false ;
for ( V_34 = 0 ; V_34 < V_168 ; V_34 ++ ) {
if ( V_166 [ V_34 ] . V_173 == V_174 )
continue;
V_178 = true ;
break;
}
if ( ! V_178 )
V_177 -> V_179 = V_180 ;
return;
}
int F_45 ( struct V_15 * V_16 ,
struct V_58 * V_59 )
{
T_3 V_160 = 0 ;
void * V_161 = NULL ;
int V_41 ;
struct V_181 V_21 ;
F_16 ( V_16 -> V_2 , L_7 , V_182 ,
V_59 -> V_36 . V_162 , V_59 -> V_36 . V_169 ) ;
if ( V_59 -> V_96 -> V_183 != V_184 ) {
F_14 ( V_16 -> V_2 , L_8 ,
V_59 -> V_96 -> V_183 , V_59 -> V_96 -> V_185 ) ;
return - V_46 ;
}
V_41 = F_39 ( V_16 , V_59 ,
& V_160 , & V_161 ) ;
if ( V_41 < 0 ) {
F_14 ( V_16 -> V_2 , L_9 , V_41 ) ;
return V_41 ;
}
V_21 . V_162 = V_59 -> V_36 . V_162 ;
V_21 . V_169 = V_59 -> V_36 . V_169 ;
V_21 . V_186 = V_59 -> V_96 -> V_185 ;
V_21 . V_26 = V_160 ;
V_21 . V_187 = V_59 -> V_187 ;
V_41 = F_46 ( & V_16 -> V_27 , & V_21 , V_161 ) ;
if ( V_41 < 0 ) {
F_14 ( V_16 -> V_2 , L_10 , V_41 ) ;
F_31 ( V_161 ) ;
return V_41 ;
}
V_59 -> V_179 = V_188 ;
return V_41 ;
}
static void F_47 ( struct V_15 * V_16 , struct V_58
* V_189 , struct V_58 * V_190 )
{
F_16 ( V_16 -> V_2 , L_11 ,
V_182 , V_189 -> V_36 . V_162 , V_189 -> V_36 . V_169 ) ;
F_16 ( V_16 -> V_2 , L_12 , V_182 ,
V_190 -> V_36 . V_162 , V_190 -> V_36 . V_169 ) ;
F_16 ( V_16 -> V_2 , L_13 ,
V_189 -> V_179 , V_190 -> V_179 ) ;
}
int F_48 ( struct V_15 * V_16 ,
struct V_58 * V_191 ,
struct V_58 * V_192 )
{
int V_41 ;
struct V_193 V_21 ;
struct V_167 V_194 = V_191 -> V_36 ;
struct V_167 V_195 = V_192 -> V_36 ;
int V_196 = V_192 -> V_197 ;
int V_198 = V_191 -> V_199 ;
int V_200 , V_201 , V_202 , V_203 ;
F_47 ( V_16 , V_191 , V_192 ) ;
V_200 = F_41 ( V_191 -> V_204 , V_195 , V_198 ) ;
if ( V_200 < 0 )
return 0 ;
V_21 . V_205 = V_200 ;
V_201 = F_41 ( V_192 -> V_206 , V_194 , V_196 ) ;
if ( V_201 < 0 )
return 0 ;
V_21 . V_207 = V_201 ;
V_202 = V_191 -> V_204 [ V_200 ] . V_173 ;
V_203 = V_192 -> V_206 [ V_201 ] . V_173 ;
if ( V_202 != V_208 ||
V_203 != V_208 )
return 0 ;
V_21 . V_162 = V_191 -> V_36 . V_162 ;
V_21 . V_169 = V_191 -> V_36 . V_169 ;
V_21 . V_209 = V_192 -> V_36 . V_162 ;
V_21 . V_210 = V_192 -> V_36 . V_169 ;
V_21 . V_211 = false ;
V_41 = F_49 ( & V_16 -> V_27 , & V_21 ) ;
if ( ! V_41 ) {
F_43 ( V_191 -> V_204 , V_200 ) ;
F_43 ( V_192 -> V_206 , V_201 ) ;
F_44 ( V_191 -> V_204 , V_198 , V_191 ) ;
}
return V_41 ;
}
int F_50 ( struct V_15 * V_16 ,
struct V_58 * V_191 ,
struct V_58 * V_192 )
{
int V_41 ;
struct V_193 V_21 ;
int V_196 = V_192 -> V_197 ;
int V_198 = V_191 -> V_199 ;
int V_200 , V_201 ;
F_47 ( V_16 , V_191 , V_192 ) ;
if ( V_191 -> V_179 < V_188 ||
V_192 -> V_179 < V_188 )
return 0 ;
V_200 = F_42 ( V_191 -> V_204 , V_192 , V_198 ) ;
if ( V_200 < 0 )
return - V_37 ;
V_21 . V_205 = V_200 ;
V_201 = F_42 ( V_192 -> V_206 , V_191 , V_196 ) ;
if ( V_201 < 0 ) {
F_43 ( V_191 -> V_204 , V_200 ) ;
return - V_37 ;
}
V_21 . V_207 = V_201 ;
F_16 ( V_16 -> V_2 , L_14 ,
V_21 . V_205 , V_21 . V_207 ) ;
V_21 . V_162 = V_191 -> V_36 . V_162 ;
V_21 . V_169 = V_191 -> V_36 . V_169 ;
V_21 . V_209 = V_192 -> V_36 . V_162 ;
V_21 . V_210 = V_192 -> V_36 . V_169 ;
V_21 . V_211 = true ;
V_41 = F_49 ( & V_16 -> V_27 , & V_21 ) ;
if ( ! V_41 ) {
V_191 -> V_179 = V_212 ;
V_191 -> V_204 [ V_200 ] . V_173 = V_208 ;
V_192 -> V_206 [ V_201 ] . V_173 = V_208 ;
} else {
F_43 ( V_191 -> V_204 , V_200 ) ;
F_43 ( V_192 -> V_206 , V_201 ) ;
}
return V_41 ;
}
static int F_51 ( struct V_15 * V_16 , struct V_213 * V_96 ,
enum V_214 V_183 )
{
F_16 ( V_16 -> V_2 , L_15 , V_182 , V_183 ) ;
return F_52 ( & V_16 -> V_27 , V_96 -> V_185 , V_183 ) ;
}
int F_53 ( struct V_15 * V_16 , struct V_213 * V_96 )
{
int V_41 ;
F_16 ( V_16 -> V_2 , L_16 , V_182 , V_96 -> V_185 ) ;
V_41 = F_54 ( & V_16 -> V_27 , V_96 -> V_215 ,
V_96 -> V_216 , V_96 -> V_185 ) ;
if ( V_41 < 0 ) {
F_14 ( V_16 -> V_2 , L_17 ) ;
return V_41 ;
}
V_96 -> V_183 = V_184 ;
return 0 ;
}
int F_55 ( struct V_15 * V_16 , struct V_213 * V_96 )
{
int V_41 ;
F_16 ( V_16 -> V_2 , L_18 , V_182 , V_96 -> V_185 ) ;
if ( V_96 -> V_183 > V_217 ) {
V_41 = F_51 ( V_16 , V_96 , V_218 ) ;
if ( V_41 < 0 ) {
F_14 ( V_16 -> V_2 , L_19 ) ;
return V_41 ;
}
V_96 -> V_183 = V_219 ;
} else {
if ( V_96 -> V_183 < V_184 )
return 0 ;
V_41 = F_56 ( & V_16 -> V_27 , V_96 -> V_185 ) ;
if ( V_41 < 0 )
F_14 ( V_16 -> V_2 , L_20 ) ;
V_96 -> V_183 = V_220 ;
}
return V_41 ;
}
int F_57 ( struct V_15 * V_16 , struct V_213 * V_96 )
{
int V_41 ;
F_16 ( V_16 -> V_2 , L_18 , V_182 , V_96 -> V_185 ) ;
if ( V_96 -> V_183 < V_184 )
return 0 ;
V_41 = F_51 ( V_16 , V_96 , V_218 ) ;
if ( V_41 < 0 ) {
F_14 ( V_16 -> V_2 , L_21 ) ;
return V_41 ;
}
V_96 -> V_183 = V_219 ;
V_41 = F_51 ( V_16 , V_96 , V_221 ) ;
if ( V_41 < 0 ) {
F_14 ( V_16 -> V_2 , L_22 ) ;
return V_41 ;
}
V_96 -> V_183 = V_217 ;
return 0 ;
}
int F_58 ( struct V_15 * V_16 , struct V_213 * V_96 )
{
int V_41 ;
F_16 ( V_16 -> V_2 , L_23 , V_182 , V_96 -> V_185 ) ;
if ( V_96 -> V_183 < V_219 )
return 0 ;
V_41 = F_51 ( V_16 , V_96 , V_218 ) ;
if ( V_41 < 0 ) {
F_16 ( V_16 -> V_2 , L_24 ) ;
return V_41 ;
}
V_96 -> V_183 = V_184 ;
return 0 ;
}
int F_59 ( struct V_15 * V_16 , V_28 * V_52 , int V_5 ,
V_28 V_222 , struct V_58 * V_177 )
{
struct V_20 V_21 ;
V_21 . V_162 = V_177 -> V_36 . V_162 ;
V_21 . V_169 = V_177 -> V_36 . V_169 ;
V_21 . V_26 = V_5 ;
V_21 . V_24 = V_222 ;
return F_6 ( & V_16 -> V_27 , & V_21 , V_52 ) ;
}
int F_60 ( struct V_15 * V_16 , V_28 * V_52 , int V_5 ,
V_28 V_222 , struct V_58 * V_177 )
{
struct V_20 V_21 ;
V_21 . V_162 = V_177 -> V_36 . V_162 ;
V_21 . V_169 = V_177 -> V_36 . V_169 ;
V_21 . V_26 = V_5 ;
V_21 . V_24 = V_222 ;
return F_61 ( & V_16 -> V_27 , & V_21 , V_52 ) ;
}
