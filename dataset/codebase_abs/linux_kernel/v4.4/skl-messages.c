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
int F_7 ( struct V_29 * V_29 )
{
void T_2 * V_30 ;
struct V_6 * V_7 = & V_29 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_31 = V_9 -> V_31 ;
struct V_32 V_33 ;
int V_34 ;
V_33 . V_35 = F_1 ;
V_33 . V_36 = F_4 ;
F_8 ( & V_29 -> V_7 , true ) ;
F_9 ( & V_29 -> V_7 , true ) ;
V_30 = F_10 ( V_29 -> V_37 , 4 ) ;
if ( V_30 == NULL ) {
F_11 ( V_9 -> V_2 , L_1 ) ;
return - V_38 ;
}
V_34 = F_12 ( V_9 -> V_2 , V_30 , V_31 ,
V_33 , & V_29 -> V_15 ) ;
if ( V_34 < 0 )
return V_34 ;
F_5 ( V_29 -> V_15 , false ) ;
F_13 ( V_9 -> V_2 , L_2 , V_34 ) ;
return V_34 ;
}
void F_14 ( struct V_29 * V_29 )
{
struct V_6 * V_7 = & V_29 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_15 * V_16 = V_29 -> V_15 ;
F_9 ( & V_29 -> V_7 , false ) ;
F_15 ( V_9 -> V_2 , V_16 ) ;
if ( V_16 -> V_39 -> V_40 . V_41 )
F_16 ( V_16 -> V_39 -> V_40 . V_41 ) ;
}
int F_17 ( struct V_29 * V_29 )
{
struct V_15 * V_16 = V_29 -> V_15 ;
int V_34 ;
if ( ! V_29 -> V_7 . V_42 )
return 0 ;
V_34 = F_18 ( V_16 -> V_39 ) ;
if ( V_34 < 0 )
return V_34 ;
F_9 ( & V_29 -> V_7 , false ) ;
F_8 ( & V_29 -> V_7 , false ) ;
return 0 ;
}
int F_19 ( struct V_29 * V_29 )
{
struct V_15 * V_16 = V_29 -> V_15 ;
int V_34 ;
if ( ! V_29 -> V_7 . V_42 )
return 0 ;
F_8 ( & V_29 -> V_7 , true ) ;
F_9 ( & V_29 -> V_7 , true ) ;
V_34 = F_20 ( V_16 -> V_39 ) ;
if ( V_34 < 0 )
return V_34 ;
F_5 ( V_29 -> V_15 , false ) ;
return V_34 ;
}
enum V_43 F_21 ( int V_44 )
{
switch ( V_44 ) {
case 8 :
return V_45 ;
case 16 :
return V_46 ;
case 24 :
return V_47 ;
case 32 :
return V_48 ;
default:
return V_49 ;
}
}
static V_28 F_22 ( enum V_50 V_51 )
{
V_28 V_52 ;
switch ( V_51 ) {
case V_53 :
V_52 = ( 0xFFFFFFF0 | V_54 ) ;
break;
case V_55 :
V_52 = ( 0xFFFFFF00 | V_54
| ( V_56 << 4 ) ) ;
break;
case V_57 :
V_52 = ( 0xFFFFF000 | V_54
| ( V_56 << 4 )
| ( V_58 << 8 ) ) ;
break;
case V_59 :
V_52 = ( 0xFFFFF000 | V_54
| ( V_60 << 4 )
| ( V_56 << 8 ) ) ;
break;
case V_61 :
V_52 = ( 0xFFFF0000 | V_54
| ( V_60 << 4 )
| ( V_56 << 8 )
| ( V_58 << 12 ) ) ;
break;
case V_62 :
V_52 = ( 0xFFFF0000 | V_54
| ( V_56 << 4 )
| ( V_63 << 8 )
| ( V_64 << 12 ) ) ;
break;
case V_65 :
V_52 = ( 0xFFFF0000 | V_54
| ( V_60 << 4 )
| ( V_56 << 8 )
| ( V_66 << 12 ) ) ;
break;
case V_67 :
V_52 = ( 0xFFF00000 | V_54
| ( V_60 << 4 )
| ( V_56 << 8 )
| ( V_63 << 12 )
| ( V_64 << 16 ) ) ;
break;
case V_68 :
V_52 = ( 0xFF000000 | V_60
| ( V_54 << 4 )
| ( V_56 << 8 )
| ( V_63 << 12 )
| ( V_64 << 16 )
| ( V_58 << 20 ) ) ;
break;
case V_69 :
V_52 = ( 0xFFFFFF00 | V_54
| ( V_54 << 4 ) ) ;
break;
case V_70 :
V_52 = ( 0xFFFFFF00 | V_54
| ( V_56 << 4 ) ) ;
break;
case V_71 :
V_52 = ( 0xFFFF00FF | ( V_54 << 8 )
| ( V_56 << 12 ) ) ;
break;
default:
V_52 = 0xFFFFFFFF ;
break;
}
return V_52 ;
}
static void F_23 ( struct V_15 * V_16 ,
struct V_72 * V_73 ,
struct V_74 * V_75 )
{
struct V_76 * V_77 = & V_73 -> V_78 ;
V_75 -> V_79 . V_80 = ( V_81 ) V_77 -> V_82 ;
V_75 -> V_79 . V_83 = V_77 -> V_83 ;
V_75 -> V_79 . V_84 = V_77 -> V_84 ;
V_75 -> V_79 . V_85 = V_77 -> V_85 ;
V_75 -> V_79 . V_51 = V_77 -> V_51 ;
F_13 ( V_16 -> V_2 , L_3 ,
V_77 -> V_84 , V_77 -> V_85 ,
V_77 -> V_51 ) ;
V_75 -> V_79 . V_86 = F_22 (
V_75 -> V_79 . V_51 ) ;
V_75 -> V_79 . V_87 = V_88 ;
V_75 -> V_89 = V_73 -> V_90 ;
V_75 -> V_91 = V_73 -> V_91 ;
V_75 -> V_92 = V_73 -> V_92 ;
}
static void F_24 ( struct V_72 * V_73 ,
struct V_93 * V_94 )
{
if ( V_73 -> V_95 . V_96 == 0 )
return;
memcpy ( V_94 -> V_97 . V_98 ,
V_73 -> V_95 . V_99 ,
V_73 -> V_95 . V_96 ) ;
V_94 -> V_97 . V_100 =
( V_73 -> V_95 . V_96 ) / 4 ;
}
static void F_25 ( struct V_15 * V_16 ,
struct V_72 * V_73 ,
struct V_93 * V_94 )
{
union V_101 V_102 = { 0 } ;
union V_103 V_104 = { 0 } ;
struct V_105 * V_44 = V_73 -> V_106 -> V_107 ;
switch ( V_73 -> V_108 ) {
case V_109 :
V_102 . V_110 . V_111 =
( V_112 == V_73 -> V_113 ) ?
V_114 :
V_115 ;
V_102 . V_110 . V_116 = V_44 -> V_117 +
( V_73 -> V_118 << 3 ) ;
break;
case V_119 :
V_102 . V_110 . V_111 =
( V_112 == V_73 -> V_113 ) ?
V_114 :
V_115 ;
V_104 . V_120 . V_121 = V_73 -> V_122 ;
V_104 . V_120 . V_123 = V_73 -> V_118 ;
V_102 . V_110 . V_116 = V_104 . V_124 ;
break;
case V_125 :
V_102 . V_110 . V_111 = V_126 ;
V_102 . V_110 . V_116 = V_73 -> V_118 +
( V_73 -> V_122 ) ;
break;
case V_127 :
V_102 . V_110 . V_111 =
( V_112 == V_73 -> V_113 ) ?
V_128 :
V_129 ;
V_102 . V_110 . V_116 = V_44 -> V_130 ;
break;
case V_131 :
V_102 . V_110 . V_111 =
( V_112 == V_73 -> V_113 ) ?
V_132 :
V_133 ;
V_102 . V_110 . V_116 = V_44 -> V_117 ;
break;
default:
V_94 -> V_97 . V_102 = V_134 ;
V_94 -> V_135 = 0 ;
return;
}
V_94 -> V_97 . V_102 = V_102 . V_124 ;
if ( V_112 == V_73 -> V_113 )
V_94 -> V_97 . V_136 = 2 * V_73 -> V_92 ;
else
V_94 -> V_97 . V_136 = 2 * V_73 -> V_91 ;
V_94 -> V_135 = 0 ;
V_94 -> V_97 . V_100 = 0 ;
F_24 ( V_73 , V_94 ) ;
}
static void F_26 ( struct V_15 * V_16 ,
struct V_72 * V_73 ,
struct V_137 * V_138 )
{
struct V_76 * V_77 = & V_73 -> V_138 ;
V_138 -> V_80 = ( V_81 ) V_77 -> V_82 ;
V_138 -> V_83 = V_77 -> V_83 ;
V_138 -> V_84 = V_77 -> V_84 ;
V_138 -> V_85 = V_77 -> V_85 ;
V_138 -> V_51 = V_77 -> V_51 ;
V_138 -> V_86 = F_22 ( V_138 -> V_51 ) ;
V_138 -> V_87 = V_88 ;
F_13 ( V_16 -> V_2 , L_4 ,
V_138 -> V_80 , V_77 -> V_83 , V_77 -> V_84 ) ;
}
static void F_27 ( struct V_15 * V_16 ,
struct V_72 * V_73 ,
struct V_139 * V_140 )
{
struct V_76 * V_141 = & V_73 -> V_138 ;
F_23 ( V_16 , V_73 ,
(struct V_74 * ) V_140 ) ;
V_140 -> V_142 = V_141 -> V_83 ;
}
static void F_28 ( struct V_15 * V_16 ,
struct V_72 * V_73 ,
struct V_143 * V_144 )
{
struct V_76 * V_141 = & V_73 -> V_138 ;
int V_145 = 0 ;
F_23 ( V_16 , V_73 ,
(struct V_74 * ) V_144 ) ;
V_144 -> V_146 = V_141 -> V_51 ;
V_144 -> V_147 = 0x0 ;
for ( V_145 = 0 ; V_145 < V_148 ; V_145 ++ )
V_144 -> V_149 [ V_145 ] = 0xDEADBEEF ;
}
static void F_29 ( struct V_15 * V_16 ,
struct V_72 * V_73 ,
struct V_93 * V_94 )
{
struct V_137 * V_138 = & V_94 -> V_138 ;
struct V_74 * V_75 = (struct V_74 * ) V_94 ;
F_23 ( V_16 , V_73 , V_75 ) ;
F_26 ( V_16 , V_73 , V_138 ) ;
F_25 ( V_16 , V_73 , V_94 ) ;
}
static T_3 F_30 ( struct V_15 * V_16 ,
struct V_72 * V_73 )
{
T_3 V_150 ;
switch ( V_73 -> V_151 ) {
case V_152 :
V_150 = sizeof( struct V_93 ) ;
V_150 += V_73 -> V_95 . V_96 ;
return V_150 ;
case V_153 :
return sizeof( struct V_139 ) ;
case V_154 :
return sizeof( struct V_143 ) ;
default:
return sizeof( struct V_74 ) ;
}
return 0 ;
}
static int F_31 ( struct V_15 * V_16 ,
struct V_72 * V_155 ,
T_3 * V_156 ,
void * * V_157 )
{
T_3 V_150 ;
V_150 = F_30 ( V_16 , V_155 ) ;
* V_157 = F_32 ( V_150 , V_158 ) ;
if ( NULL == * V_157 )
return - V_159 ;
* V_156 = V_150 ;
switch ( V_155 -> V_151 ) {
case V_152 :
F_29 ( V_16 , V_155 , * V_157 ) ;
break;
case V_153 :
F_27 ( V_16 , V_155 , * V_157 ) ;
break;
case V_154 :
F_28 ( V_16 , V_155 , * V_157 ) ;
break;
default:
F_23 ( V_16 , V_155 , * V_157 ) ;
break;
}
F_13 ( V_16 -> V_2 , L_5 ,
V_155 -> V_160 . V_161 , V_150 ) ;
F_33 ( V_162 , L_6 , V_163 , 8 , 4 ,
* V_157 , V_150 , false ) ;
return 0 ;
}
static int F_34 ( struct V_164 * V_165 ,
struct V_166 V_160 , int V_167 )
{
int V_145 ;
for ( V_145 = 0 ; V_145 < V_167 ; V_145 ++ ) {
if ( V_165 [ V_145 ] . V_160 . V_161 == V_160 . V_161 &&
V_165 [ V_145 ] . V_160 . V_168 == V_160 . V_168 )
return V_145 ;
}
return - V_169 ;
}
static int F_35 ( struct V_164 * V_165 ,
struct V_166 V_160 , int V_167 )
{
int V_145 ;
for ( V_145 = 0 ; V_145 < V_167 ; V_145 ++ ) {
if ( V_165 [ V_145 ] . V_170 ) {
if ( ! V_165 [ V_145 ] . V_171 ) {
V_165 [ V_145 ] . V_171 = true ;
V_165 [ V_145 ] . V_160 . V_161 = V_160 . V_161 ;
V_165 [ V_145 ] . V_160 . V_168 = V_160 . V_168 ;
return V_145 ;
}
} else {
if ( V_165 [ V_145 ] . V_160 . V_161 == V_160 . V_161 &&
V_165 [ V_145 ] . V_160 . V_168 == V_160 . V_168 )
return V_145 ;
}
}
return - V_169 ;
}
static void F_36 ( struct V_164 * V_165 , int V_172 )
{
if ( V_165 [ V_172 ] . V_170 ) {
V_165 [ V_172 ] . V_171 = false ;
V_165 [ V_172 ] . V_160 . V_161 = 0 ;
V_165 [ V_172 ] . V_160 . V_168 = 0 ;
}
}
int F_37 ( struct V_15 * V_16 ,
struct V_72 * V_73 , char * V_173 )
{
T_3 V_156 = 0 ;
void * V_157 = NULL ;
int V_34 ;
struct V_174 V_21 ;
F_13 ( V_16 -> V_2 , L_7 , V_175 ,
V_73 -> V_160 . V_161 , V_73 -> V_160 . V_168 ) ;
if ( V_73 -> V_106 -> V_176 != V_177 ) {
F_11 ( V_16 -> V_2 , L_8 ,
V_73 -> V_106 -> V_176 , V_73 -> V_106 -> V_178 ) ;
return - V_179 ;
}
V_34 = F_31 ( V_16 , V_73 ,
& V_156 , & V_157 ) ;
if ( V_34 < 0 ) {
F_11 ( V_16 -> V_2 , L_9 , V_34 ) ;
return V_34 ;
}
V_21 . V_161 = V_73 -> V_160 . V_161 ;
V_21 . V_168 = V_73 -> V_160 . V_168 ;
V_21 . V_180 = V_73 -> V_106 -> V_178 ;
V_21 . V_26 = V_156 ;
V_21 . V_181 = V_73 -> V_181 ;
V_34 = F_38 ( & V_16 -> V_27 , & V_21 , V_157 ) ;
if ( V_34 < 0 ) {
F_11 ( V_16 -> V_2 , L_10 , V_34 ) ;
F_39 ( V_157 ) ;
return V_34 ;
}
V_73 -> V_182 = V_183 ;
return V_34 ;
}
static void F_40 ( struct V_15 * V_16 , struct V_72
* V_184 , struct V_72 * V_185 )
{
F_13 ( V_16 -> V_2 , L_11 ,
V_175 , V_184 -> V_160 . V_161 , V_184 -> V_160 . V_168 ) ;
F_13 ( V_16 -> V_2 , L_12 , V_175 ,
V_185 -> V_160 . V_161 , V_185 -> V_160 . V_168 ) ;
F_13 ( V_16 -> V_2 , L_13 ,
V_184 -> V_182 , V_185 -> V_182 ) ;
}
int F_41 ( struct V_15 * V_16 ,
struct V_72 * V_186 ,
struct V_72 * V_187 )
{
int V_34 ;
struct V_188 V_21 ;
struct V_166 V_189 = V_186 -> V_160 ;
struct V_166 V_190 = V_187 -> V_160 ;
int V_191 = V_187 -> V_192 ;
int V_193 = V_186 -> V_194 ;
int V_195 , V_196 ;
F_40 ( V_16 , V_186 , V_187 ) ;
if ( V_186 -> V_182 != V_197 )
return 0 ;
if ( ( V_186 -> V_106 -> V_178 != V_187 -> V_106 -> V_178 ) &&
V_187 -> V_182 != V_197 )
return 0 ;
else if ( V_186 -> V_182 < V_183 &&
V_187 -> V_182 < V_183 )
return 0 ;
V_195 = F_34 ( V_186 -> V_198 , V_190 , V_193 ) ;
if ( V_195 < 0 )
return - V_169 ;
V_21 . V_199 = V_186 -> V_198 [ V_195 ] . V_200 ;
V_196 = F_34 ( V_187 -> V_201 , V_189 , V_191 ) ;
if ( V_196 < 0 )
return - V_169 ;
V_21 . V_202 = V_187 -> V_201 [ V_196 ] . V_200 ;
V_21 . V_161 = V_186 -> V_160 . V_161 ;
V_21 . V_168 = V_186 -> V_160 . V_168 ;
V_21 . V_203 = V_187 -> V_160 . V_161 ;
V_21 . V_204 = V_187 -> V_160 . V_168 ;
V_21 . V_205 = false ;
V_34 = F_42 ( & V_16 -> V_27 , & V_21 ) ;
if ( ! V_34 ) {
V_186 -> V_182 = V_206 ;
F_36 ( V_186 -> V_198 , V_195 ) ;
F_36 ( V_187 -> V_201 , V_196 ) ;
}
return V_34 ;
}
int F_43 ( struct V_15 * V_16 ,
struct V_72 * V_186 ,
struct V_72 * V_187 )
{
int V_34 ;
struct V_188 V_21 ;
struct V_166 V_189 = V_186 -> V_160 ;
struct V_166 V_190 = V_187 -> V_160 ;
int V_191 = V_187 -> V_192 ;
int V_193 = V_186 -> V_194 ;
int V_195 , V_196 ;
F_40 ( V_16 , V_186 , V_187 ) ;
if ( V_186 -> V_182 < V_183 &&
V_187 -> V_182 < V_183 )
return 0 ;
V_195 = F_35 ( V_186 -> V_198 , V_190 , V_193 ) ;
if ( V_195 < 0 )
return - V_169 ;
V_21 . V_199 = V_186 -> V_198 [ V_195 ] . V_200 ;
V_196 = F_35 ( V_187 -> V_201 , V_189 , V_191 ) ;
if ( V_196 < 0 ) {
F_36 ( V_186 -> V_198 , V_195 ) ;
return - V_169 ;
}
V_21 . V_202 = V_187 -> V_201 [ V_196 ] . V_200 ;
F_13 ( V_16 -> V_2 , L_14 ,
V_21 . V_199 , V_21 . V_202 ) ;
V_21 . V_161 = V_186 -> V_160 . V_161 ;
V_21 . V_168 = V_186 -> V_160 . V_168 ;
V_21 . V_203 = V_187 -> V_160 . V_161 ;
V_21 . V_204 = V_187 -> V_160 . V_168 ;
V_21 . V_205 = true ;
V_34 = F_42 ( & V_16 -> V_27 , & V_21 ) ;
if ( ! V_34 ) {
V_186 -> V_182 = V_197 ;
} else {
F_36 ( V_186 -> V_198 , V_195 ) ;
F_36 ( V_187 -> V_201 , V_196 ) ;
}
return V_34 ;
}
static int F_44 ( struct V_15 * V_16 , struct V_207 * V_106 ,
enum V_208 V_176 )
{
F_13 ( V_16 -> V_2 , L_15 , V_175 , V_176 ) ;
return F_45 ( & V_16 -> V_27 , V_106 -> V_178 , V_176 ) ;
}
int F_46 ( struct V_15 * V_16 , struct V_207 * V_106 )
{
int V_34 ;
F_13 ( V_16 -> V_2 , L_16 , V_175 , V_106 -> V_178 ) ;
V_34 = F_47 ( & V_16 -> V_27 , V_106 -> V_209 ,
V_106 -> V_210 , V_106 -> V_178 ) ;
if ( V_34 < 0 ) {
F_11 ( V_16 -> V_2 , L_17 ) ;
return V_34 ;
}
V_106 -> V_176 = V_177 ;
return 0 ;
}
int F_48 ( struct V_15 * V_16 , struct V_207 * V_106 )
{
int V_34 ;
F_13 ( V_16 -> V_2 , L_18 , V_175 , V_106 -> V_178 ) ;
if ( V_106 -> V_176 > V_211 ) {
V_34 = F_44 ( V_16 , V_106 , V_212 ) ;
if ( V_34 < 0 ) {
F_11 ( V_16 -> V_2 , L_19 ) ;
return V_34 ;
}
V_106 -> V_176 = V_213 ;
} else {
if ( V_106 -> V_176 < V_177 )
return 0 ;
V_34 = F_49 ( & V_16 -> V_27 , V_106 -> V_178 ) ;
if ( V_34 < 0 )
F_11 ( V_16 -> V_2 , L_20 ) ;
}
return V_34 ;
}
int F_50 ( struct V_15 * V_16 , struct V_207 * V_106 )
{
int V_34 ;
F_13 ( V_16 -> V_2 , L_18 , V_175 , V_106 -> V_178 ) ;
if ( V_106 -> V_176 < V_177 )
return 0 ;
V_34 = F_44 ( V_16 , V_106 , V_212 ) ;
if ( V_34 < 0 ) {
F_11 ( V_16 -> V_2 , L_21 ) ;
return V_34 ;
}
V_106 -> V_176 = V_213 ;
V_34 = F_44 ( V_16 , V_106 , V_214 ) ;
if ( V_34 < 0 ) {
F_11 ( V_16 -> V_2 , L_22 ) ;
return V_34 ;
}
V_106 -> V_176 = V_211 ;
return 0 ;
}
int F_51 ( struct V_15 * V_16 , struct V_207 * V_106 )
{
int V_34 ;
F_13 ( V_16 -> V_2 , L_23 , V_175 , V_106 -> V_178 ) ;
if ( V_106 -> V_176 < V_213 )
return 0 ;
V_34 = F_44 ( V_16 , V_106 , V_212 ) ;
if ( V_34 < 0 ) {
F_13 ( V_16 -> V_2 , L_24 ) ;
return V_34 ;
}
V_106 -> V_176 = V_177 ;
return 0 ;
}
