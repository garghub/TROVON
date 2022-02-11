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
V_29 -> V_39 , V_33 , & V_29 -> V_15 ) ;
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
if ( V_16 -> V_40 -> V_41 . V_42 )
F_16 ( V_16 -> V_40 -> V_41 . V_42 ) ;
}
int F_17 ( struct V_29 * V_29 )
{
struct V_15 * V_16 = V_29 -> V_15 ;
int V_34 ;
if ( ! V_29 -> V_7 . V_43 )
return 0 ;
V_34 = F_18 ( V_16 -> V_40 ) ;
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
if ( ! V_29 -> V_7 . V_43 )
return 0 ;
F_8 ( & V_29 -> V_7 , true ) ;
F_9 ( & V_29 -> V_7 , true ) ;
V_34 = F_20 ( V_16 -> V_40 ) ;
if ( V_34 < 0 )
return V_34 ;
F_5 ( V_29 -> V_15 , false ) ;
return V_34 ;
}
enum V_44 F_21 ( int V_45 )
{
switch ( V_45 ) {
case 8 :
return V_46 ;
case 16 :
return V_47 ;
case 24 :
return V_48 ;
case 32 :
return V_49 ;
default:
return V_50 ;
}
}
static void F_22 ( struct V_15 * V_16 ,
struct V_51 * V_52 ,
struct V_53 * V_54 )
{
struct V_55 * V_56 = & V_52 -> V_57 [ 0 ] ;
V_54 -> V_58 . V_59 = ( V_60 ) V_56 -> V_61 ;
V_54 -> V_58 . V_62 = V_56 -> V_62 ;
V_54 -> V_58 . V_63 = V_56 -> V_63 ;
V_54 -> V_58 . V_64 = V_56 -> V_64 ;
V_54 -> V_58 . V_65 = V_56 -> V_65 ;
F_13 ( V_16 -> V_2 , L_3 ,
V_56 -> V_63 , V_56 -> V_64 ,
V_56 -> V_65 ) ;
V_54 -> V_58 . V_66 = V_56 -> V_67 ;
V_54 -> V_58 . V_68 = V_56 -> V_69 ;
V_54 -> V_70 = V_52 -> V_71 ;
V_54 -> V_72 = V_52 -> V_72 ;
V_54 -> V_73 = V_52 -> V_73 ;
V_54 -> V_74 = V_52 -> V_75 ;
}
static void F_23 ( struct V_51 * V_52 ,
struct V_76 * V_77 )
{
if ( V_52 -> V_78 . V_79 == 0 )
return;
memcpy ( V_77 -> V_80 . V_81 ,
V_52 -> V_78 . V_82 ,
V_52 -> V_78 . V_79 ) ;
V_77 -> V_80 . V_83 =
( V_52 -> V_78 . V_79 ) / 4 ;
}
static void F_24 ( struct V_15 * V_16 ,
struct V_51 * V_52 ,
struct V_76 * V_77 )
{
union V_84 V_85 = { 0 } ;
union V_86 V_87 = { 0 } ;
struct V_88 * V_45 = V_52 -> V_89 -> V_90 ;
switch ( V_52 -> V_91 ) {
case V_92 :
V_85 . V_93 . V_94 =
( V_95 == V_52 -> V_96 ) ?
V_97 :
V_98 ;
V_85 . V_93 . V_99 = V_45 -> V_100 +
( V_52 -> V_101 << 3 ) ;
break;
case V_102 :
V_85 . V_93 . V_94 =
( V_95 == V_52 -> V_96 ) ?
V_97 :
V_98 ;
V_87 . V_103 . V_104 = V_52 -> V_105 ;
V_87 . V_103 . V_106 = V_52 -> V_101 ;
V_85 . V_93 . V_99 = V_87 . V_107 ;
break;
case V_108 :
V_85 . V_93 . V_94 = V_109 ;
V_85 . V_93 . V_99 = V_52 -> V_101 +
( V_52 -> V_105 ) ;
break;
case V_110 :
V_85 . V_93 . V_94 =
( V_95 == V_52 -> V_96 ) ?
V_111 :
V_112 ;
V_85 . V_93 . V_99 = V_45 -> V_113 ;
break;
case V_114 :
V_85 . V_93 . V_94 =
( V_95 == V_52 -> V_96 ) ?
V_115 :
V_116 ;
V_85 . V_93 . V_99 = V_45 -> V_100 ;
break;
default:
V_77 -> V_80 . V_85 = V_117 ;
V_77 -> V_118 = 0 ;
return;
}
V_77 -> V_80 . V_85 = V_85 . V_107 ;
if ( V_95 == V_52 -> V_96 )
V_77 -> V_80 . V_119 = 2 * V_52 -> V_73 ;
else
V_77 -> V_80 . V_119 = 2 * V_52 -> V_72 ;
V_77 -> V_118 = 0 ;
V_77 -> V_80 . V_83 = 0 ;
F_23 ( V_52 , V_77 ) ;
}
static void F_25 ( struct V_15 * V_16 ,
struct V_51 * V_52 ,
struct V_120 * V_121 )
{
struct V_55 * V_56 = & V_52 -> V_121 [ 0 ] ;
V_121 -> V_59 = ( V_60 ) V_56 -> V_61 ;
V_121 -> V_62 = V_56 -> V_62 ;
V_121 -> V_63 = V_56 -> V_63 ;
V_121 -> V_64 = V_56 -> V_64 ;
V_121 -> V_65 = V_56 -> V_65 ;
V_121 -> V_66 = V_56 -> V_67 ;
V_121 -> V_68 = V_56 -> V_69 ;
V_121 -> V_122 = V_56 -> V_122 ;
F_13 ( V_16 -> V_2 , L_4 ,
V_121 -> V_59 , V_56 -> V_62 , V_56 -> V_63 ) ;
}
static void F_26 ( struct V_15 * V_16 ,
struct V_51 * V_52 ,
struct V_123 * V_124 )
{
struct V_55 * V_125 = & V_52 -> V_121 [ 0 ] ;
F_22 ( V_16 , V_52 ,
(struct V_53 * ) V_124 ) ;
V_124 -> V_126 = V_125 -> V_62 ;
}
static void F_27 ( struct V_15 * V_16 ,
struct V_51 * V_52 ,
struct V_127 * V_128 )
{
struct V_55 * V_125 = & V_52 -> V_121 [ 0 ] ;
int V_129 = 0 ;
F_22 ( V_16 , V_52 ,
(struct V_53 * ) V_128 ) ;
V_128 -> V_130 = V_125 -> V_65 ;
V_128 -> V_131 = 0x0 ;
for ( V_129 = 0 ; V_129 < V_132 ; V_129 ++ )
V_128 -> V_133 [ V_129 ] = 0xDEADBEEF ;
}
static void F_28 ( struct V_15 * V_16 ,
struct V_51 * V_52 ,
struct V_76 * V_77 )
{
struct V_120 * V_121 = & V_77 -> V_121 ;
struct V_53 * V_54 = (struct V_53 * ) V_77 ;
F_22 ( V_16 , V_52 , V_54 ) ;
F_25 ( V_16 , V_52 , V_121 ) ;
F_24 ( V_16 , V_52 , V_77 ) ;
}
static void F_29 ( struct V_15 * V_16 ,
struct V_51 * V_52 ,
struct V_134 * V_135 )
{
struct V_53 * V_54 = (struct V_53 * ) V_135 ;
F_22 ( V_16 , V_52 , V_54 ) ;
if ( V_52 -> V_78 . V_79 == 0 )
return;
memcpy ( V_135 -> V_45 ,
V_52 -> V_78 . V_82 ,
V_52 -> V_78 . V_79 ) ;
}
static void F_30 ( struct V_15 * V_16 ,
struct V_51 * V_52 ,
struct V_136 * V_137 )
{
struct V_120 * V_121 = & V_137 -> V_121 ;
struct V_53 * V_54 =
(struct V_53 * ) V_137 ;
F_22 ( V_16 , V_52 , V_54 ) ;
F_25 ( V_16 , V_52 , V_121 ) ;
}
static T_3 F_31 ( struct V_15 * V_16 ,
struct V_51 * V_52 )
{
T_3 V_138 ;
switch ( V_52 -> V_139 ) {
case V_140 :
V_138 = sizeof( struct V_76 ) ;
V_138 += V_52 -> V_78 . V_79 ;
return V_138 ;
case V_141 :
return sizeof( struct V_123 ) ;
case V_142 :
return sizeof( struct V_127 ) ;
case V_143 :
V_138 = sizeof( struct V_53 ) ;
V_138 += V_52 -> V_78 . V_79 ;
return V_138 ;
case V_144 :
return sizeof( struct V_136 ) ;
default:
return sizeof( struct V_53 ) ;
}
return 0 ;
}
static int F_32 ( struct V_15 * V_16 ,
struct V_51 * V_145 ,
T_3 * V_146 ,
void * * V_147 )
{
T_3 V_138 ;
V_138 = F_31 ( V_16 , V_145 ) ;
* V_147 = F_33 ( V_138 , V_148 ) ;
if ( NULL == * V_147 )
return - V_149 ;
* V_146 = V_138 ;
switch ( V_145 -> V_139 ) {
case V_140 :
F_28 ( V_16 , V_145 , * V_147 ) ;
break;
case V_141 :
F_26 ( V_16 , V_145 , * V_147 ) ;
break;
case V_142 :
F_27 ( V_16 , V_145 , * V_147 ) ;
break;
case V_143 :
F_29 ( V_16 , V_145 , * V_147 ) ;
break;
case V_144 :
F_30 ( V_16 , V_145 , * V_147 ) ;
break;
default:
F_22 ( V_16 , V_145 , * V_147 ) ;
break;
}
F_13 ( V_16 -> V_2 , L_5 ,
V_145 -> V_150 . V_151 , V_138 ) ;
F_34 ( V_152 , L_6 , V_153 , 8 , 4 ,
* V_147 , V_138 , false ) ;
return 0 ;
}
static int F_35 ( struct V_154 * V_155 ,
struct V_156 V_150 , int V_157 )
{
int V_129 ;
for ( V_129 = 0 ; V_129 < V_157 ; V_129 ++ ) {
if ( V_155 [ V_129 ] . V_150 . V_151 == V_150 . V_151 &&
V_155 [ V_129 ] . V_150 . V_158 == V_150 . V_158 )
return V_129 ;
}
return - V_159 ;
}
static int F_36 ( struct V_154 * V_155 ,
struct V_51 * V_160 , int V_157 )
{
int V_129 ;
struct V_156 V_150 = V_160 -> V_150 ;
for ( V_129 = 0 ; V_129 < V_157 ; V_129 ++ ) {
if ( V_155 [ V_129 ] . V_161 ) {
if ( ! V_155 [ V_129 ] . V_162 &&
V_155 [ V_129 ] . V_163 == V_164 ) {
V_155 [ V_129 ] . V_162 = true ;
V_155 [ V_129 ] . V_150 . V_151 = V_150 . V_151 ;
V_155 [ V_129 ] . V_150 . V_158 = V_150 . V_158 ;
V_155 [ V_129 ] . V_165 = V_160 ;
return V_129 ;
}
} else {
if ( V_155 [ V_129 ] . V_150 . V_151 == V_150 . V_151 &&
V_155 [ V_129 ] . V_150 . V_158 == V_150 . V_158 &&
V_155 [ V_129 ] . V_163 == V_164 ) {
V_155 [ V_129 ] . V_165 = V_160 ;
return V_129 ;
}
}
}
return - V_159 ;
}
static void F_37 ( struct V_154 * V_155 , int V_166 )
{
if ( V_155 [ V_166 ] . V_161 ) {
V_155 [ V_166 ] . V_162 = false ;
V_155 [ V_166 ] . V_150 . V_151 = 0 ;
V_155 [ V_166 ] . V_150 . V_158 = 0 ;
}
V_155 [ V_166 ] . V_163 = V_164 ;
V_155 [ V_166 ] . V_165 = NULL ;
}
static void F_38 ( struct V_154 * V_155 , int V_157 ,
struct V_51 * V_167 )
{
int V_129 ;
bool V_168 = false ;
for ( V_129 = 0 ; V_129 < V_157 ; V_129 ++ ) {
if ( V_155 [ V_129 ] . V_163 == V_164 )
continue;
V_168 = true ;
break;
}
if ( ! V_168 )
V_167 -> V_169 = V_170 ;
return;
}
int F_39 ( struct V_15 * V_16 ,
struct V_51 * V_52 )
{
T_3 V_146 = 0 ;
void * V_147 = NULL ;
int V_34 ;
struct V_171 V_21 ;
F_13 ( V_16 -> V_2 , L_7 , V_172 ,
V_52 -> V_150 . V_151 , V_52 -> V_150 . V_158 ) ;
if ( V_52 -> V_89 -> V_173 != V_174 ) {
F_11 ( V_16 -> V_2 , L_8 ,
V_52 -> V_89 -> V_173 , V_52 -> V_89 -> V_175 ) ;
return - V_176 ;
}
V_34 = F_32 ( V_16 , V_52 ,
& V_146 , & V_147 ) ;
if ( V_34 < 0 ) {
F_11 ( V_16 -> V_2 , L_9 , V_34 ) ;
return V_34 ;
}
V_21 . V_151 = V_52 -> V_150 . V_151 ;
V_21 . V_158 = V_52 -> V_150 . V_158 ;
V_21 . V_177 = V_52 -> V_89 -> V_175 ;
V_21 . V_26 = V_146 ;
V_21 . V_178 = V_52 -> V_178 ;
V_34 = F_40 ( & V_16 -> V_27 , & V_21 , V_147 ) ;
if ( V_34 < 0 ) {
F_11 ( V_16 -> V_2 , L_10 , V_34 ) ;
F_41 ( V_147 ) ;
return V_34 ;
}
V_52 -> V_169 = V_179 ;
return V_34 ;
}
static void F_42 ( struct V_15 * V_16 , struct V_51
* V_180 , struct V_51 * V_181 )
{
F_13 ( V_16 -> V_2 , L_11 ,
V_172 , V_180 -> V_150 . V_151 , V_180 -> V_150 . V_158 ) ;
F_13 ( V_16 -> V_2 , L_12 , V_172 ,
V_181 -> V_150 . V_151 , V_181 -> V_150 . V_158 ) ;
F_13 ( V_16 -> V_2 , L_13 ,
V_180 -> V_169 , V_181 -> V_169 ) ;
}
int F_43 ( struct V_15 * V_16 ,
struct V_51 * V_182 ,
struct V_51 * V_183 )
{
int V_34 ;
struct V_184 V_21 ;
struct V_156 V_185 = V_182 -> V_150 ;
struct V_156 V_186 = V_183 -> V_150 ;
int V_187 = V_183 -> V_188 ;
int V_189 = V_182 -> V_190 ;
int V_191 , V_192 , V_193 , V_194 ;
F_42 ( V_16 , V_182 , V_183 ) ;
V_191 = F_35 ( V_182 -> V_195 , V_186 , V_189 ) ;
if ( V_191 < 0 )
return 0 ;
V_21 . V_196 = V_191 ;
V_192 = F_35 ( V_183 -> V_197 , V_185 , V_187 ) ;
if ( V_192 < 0 )
return 0 ;
V_21 . V_198 = V_192 ;
V_193 = V_182 -> V_195 [ V_191 ] . V_163 ;
V_194 = V_183 -> V_197 [ V_192 ] . V_163 ;
if ( V_193 != V_199 ||
V_194 != V_199 )
return 0 ;
V_21 . V_151 = V_182 -> V_150 . V_151 ;
V_21 . V_158 = V_182 -> V_150 . V_158 ;
V_21 . V_200 = V_183 -> V_150 . V_151 ;
V_21 . V_201 = V_183 -> V_150 . V_158 ;
V_21 . V_202 = false ;
V_34 = F_44 ( & V_16 -> V_27 , & V_21 ) ;
if ( ! V_34 ) {
F_37 ( V_182 -> V_195 , V_191 ) ;
F_37 ( V_183 -> V_197 , V_192 ) ;
F_38 ( V_182 -> V_195 , V_189 , V_182 ) ;
}
return V_34 ;
}
int F_45 ( struct V_15 * V_16 ,
struct V_51 * V_182 ,
struct V_51 * V_183 )
{
int V_34 ;
struct V_184 V_21 ;
int V_187 = V_183 -> V_188 ;
int V_189 = V_182 -> V_190 ;
int V_191 , V_192 ;
F_42 ( V_16 , V_182 , V_183 ) ;
if ( V_182 -> V_169 < V_179 ||
V_183 -> V_169 < V_179 )
return 0 ;
V_191 = F_36 ( V_182 -> V_195 , V_183 , V_189 ) ;
if ( V_191 < 0 )
return - V_159 ;
V_21 . V_196 = V_191 ;
V_192 = F_36 ( V_183 -> V_197 , V_182 , V_187 ) ;
if ( V_192 < 0 ) {
F_37 ( V_182 -> V_195 , V_191 ) ;
return - V_159 ;
}
V_21 . V_198 = V_192 ;
F_13 ( V_16 -> V_2 , L_14 ,
V_21 . V_196 , V_21 . V_198 ) ;
V_21 . V_151 = V_182 -> V_150 . V_151 ;
V_21 . V_158 = V_182 -> V_150 . V_158 ;
V_21 . V_200 = V_183 -> V_150 . V_151 ;
V_21 . V_201 = V_183 -> V_150 . V_158 ;
V_21 . V_202 = true ;
V_34 = F_44 ( & V_16 -> V_27 , & V_21 ) ;
if ( ! V_34 ) {
V_182 -> V_169 = V_203 ;
V_182 -> V_195 [ V_191 ] . V_163 = V_199 ;
V_183 -> V_197 [ V_192 ] . V_163 = V_199 ;
} else {
F_37 ( V_182 -> V_195 , V_191 ) ;
F_37 ( V_183 -> V_197 , V_192 ) ;
}
return V_34 ;
}
static int F_46 ( struct V_15 * V_16 , struct V_204 * V_89 ,
enum V_205 V_173 )
{
F_13 ( V_16 -> V_2 , L_15 , V_172 , V_173 ) ;
return F_47 ( & V_16 -> V_27 , V_89 -> V_175 , V_173 ) ;
}
int F_48 ( struct V_15 * V_16 , struct V_204 * V_89 )
{
int V_34 ;
F_13 ( V_16 -> V_2 , L_16 , V_172 , V_89 -> V_175 ) ;
V_34 = F_49 ( & V_16 -> V_27 , V_89 -> V_206 ,
V_89 -> V_207 , V_89 -> V_175 ) ;
if ( V_34 < 0 ) {
F_11 ( V_16 -> V_2 , L_17 ) ;
return V_34 ;
}
V_89 -> V_173 = V_174 ;
return 0 ;
}
int F_50 ( struct V_15 * V_16 , struct V_204 * V_89 )
{
int V_34 ;
F_13 ( V_16 -> V_2 , L_18 , V_172 , V_89 -> V_175 ) ;
if ( V_89 -> V_173 > V_208 ) {
V_34 = F_46 ( V_16 , V_89 , V_209 ) ;
if ( V_34 < 0 ) {
F_11 ( V_16 -> V_2 , L_19 ) ;
return V_34 ;
}
V_89 -> V_173 = V_210 ;
} else {
if ( V_89 -> V_173 < V_174 )
return 0 ;
V_34 = F_51 ( & V_16 -> V_27 , V_89 -> V_175 ) ;
if ( V_34 < 0 )
F_11 ( V_16 -> V_2 , L_20 ) ;
V_89 -> V_173 = V_211 ;
}
return V_34 ;
}
int F_52 ( struct V_15 * V_16 , struct V_204 * V_89 )
{
int V_34 ;
F_13 ( V_16 -> V_2 , L_18 , V_172 , V_89 -> V_175 ) ;
if ( V_89 -> V_173 < V_174 )
return 0 ;
V_34 = F_46 ( V_16 , V_89 , V_209 ) ;
if ( V_34 < 0 ) {
F_11 ( V_16 -> V_2 , L_21 ) ;
return V_34 ;
}
V_89 -> V_173 = V_210 ;
V_34 = F_46 ( V_16 , V_89 , V_212 ) ;
if ( V_34 < 0 ) {
F_11 ( V_16 -> V_2 , L_22 ) ;
return V_34 ;
}
V_89 -> V_173 = V_208 ;
return 0 ;
}
int F_53 ( struct V_15 * V_16 , struct V_204 * V_89 )
{
int V_34 ;
F_13 ( V_16 -> V_2 , L_23 , V_172 , V_89 -> V_175 ) ;
if ( V_89 -> V_173 < V_210 )
return 0 ;
V_34 = F_46 ( V_16 , V_89 , V_209 ) ;
if ( V_34 < 0 ) {
F_13 ( V_16 -> V_2 , L_24 ) ;
return V_34 ;
}
V_89 -> V_173 = V_174 ;
return 0 ;
}
int F_54 ( struct V_15 * V_16 , V_28 * V_45 , int V_5 ,
V_28 V_213 , struct V_51 * V_167 )
{
struct V_20 V_21 ;
V_21 . V_151 = V_167 -> V_150 . V_151 ;
V_21 . V_158 = V_167 -> V_150 . V_158 ;
V_21 . V_26 = V_5 ;
V_21 . V_24 = V_213 ;
return F_6 ( & V_16 -> V_27 , & V_21 , V_45 ) ;
}
int F_55 ( struct V_15 * V_16 , V_28 * V_45 , int V_5 ,
V_28 V_213 , struct V_51 * V_167 )
{
struct V_20 V_21 ;
V_21 . V_151 = V_167 -> V_150 . V_151 ;
V_21 . V_158 = V_167 -> V_150 . V_158 ;
V_21 . V_26 = V_5 ;
V_21 . V_24 = V_213 ;
return F_56 ( & V_16 -> V_27 , & V_21 , V_45 ) ;
}
