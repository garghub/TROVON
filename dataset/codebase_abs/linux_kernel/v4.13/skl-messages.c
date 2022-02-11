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
int V_40 ;
F_25 ( & V_55 -> V_7 , true ) ;
F_26 ( & V_55 -> V_7 , true ) ;
V_56 = F_27 ( V_55 -> V_59 , 4 ) ;
if ( V_56 == NULL ) {
F_28 ( V_9 -> V_2 , L_1 ) ;
return - V_60 ;
}
V_58 = F_22 ( V_55 -> V_59 -> V_1 ) ;
if ( ! V_58 )
return - V_61 ;
V_44 = V_58 -> V_44 () ;
V_40 = V_58 -> V_62 ( V_9 -> V_2 , V_56 , V_57 ,
V_55 -> V_63 , V_44 ,
& V_55 -> V_15 ) ;
if ( V_40 < 0 )
return V_40 ;
V_55 -> V_15 -> V_53 = V_58 ;
F_29 ( V_9 -> V_2 , L_2 , V_40 ) ;
return V_40 ;
}
int F_30 ( struct V_55 * V_55 )
{
struct V_6 * V_7 = & V_55 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_15 * V_16 = V_55 -> V_15 ;
F_26 ( & V_55 -> V_7 , false ) ;
V_16 -> V_53 -> V_49 ( V_9 -> V_2 , V_16 ) ;
if ( V_16 -> V_64 -> V_65 . V_66 )
F_31 ( V_16 -> V_64 -> V_65 . V_66 ) ;
return 0 ;
}
int F_32 ( struct V_55 * V_55 )
{
struct V_15 * V_16 = V_55 -> V_15 ;
struct V_67 * V_68 ;
if ( ! V_16 )
return 0 ;
V_68 = & V_16 -> V_69 . V_70 ;
if ( V_68 -> V_70 . V_71 ) {
if ( V_55 -> V_72 )
F_33 ( V_68 ) ;
else
F_34 ( V_68 ) ;
}
return 0 ;
}
int F_35 ( struct V_55 * V_55 )
{
struct V_15 * V_16 = V_55 -> V_15 ;
int V_40 ;
if ( ! V_55 -> V_7 . V_9 . V_73 )
return 0 ;
V_40 = F_36 ( V_16 -> V_64 ) ;
if ( V_40 < 0 )
return V_40 ;
F_26 ( & V_55 -> V_7 , false ) ;
F_25 ( & V_55 -> V_7 , false ) ;
return 0 ;
}
int F_37 ( struct V_55 * V_55 )
{
struct V_15 * V_16 = V_55 -> V_15 ;
int V_40 ;
if ( ! V_55 -> V_7 . V_9 . V_73 )
return 0 ;
F_25 ( & V_55 -> V_7 , true ) ;
F_26 ( & V_55 -> V_7 , true ) ;
if ( V_55 -> V_15 -> V_74 == true )
return 0 ;
V_40 = F_38 ( V_16 -> V_64 ) ;
if ( V_40 < 0 )
return V_40 ;
F_5 ( V_55 -> V_15 , false ) ;
return V_40 ;
}
enum V_75 F_39 ( int V_76 )
{
switch ( V_76 ) {
case 8 :
return V_77 ;
case 16 :
return V_78 ;
case 24 :
return V_79 ;
case 32 :
return V_80 ;
default:
return V_81 ;
}
}
static void F_40 ( struct V_15 * V_16 ,
struct V_82 * V_83 ,
struct V_84 * V_85 )
{
struct V_86 * V_37 = & V_83 -> V_87 [ 0 ] ;
V_85 -> V_88 . V_89 = ( V_90 ) V_37 -> V_91 ;
V_85 -> V_88 . V_92 = V_37 -> V_92 ;
V_85 -> V_88 . V_93 = V_37 -> V_93 ;
V_85 -> V_88 . V_94 = V_37 -> V_94 ;
V_85 -> V_88 . V_95 = V_37 -> V_95 ;
F_29 ( V_16 -> V_2 , L_3 ,
V_37 -> V_93 , V_37 -> V_94 ,
V_37 -> V_95 ) ;
V_85 -> V_88 . V_96 = V_37 -> V_97 ;
V_85 -> V_88 . V_98 = V_37 -> V_99 ;
V_85 -> V_100 = V_83 -> V_101 ;
V_85 -> V_102 = V_83 -> V_102 ;
V_85 -> V_103 = V_83 -> V_103 ;
V_85 -> V_104 = V_83 -> V_105 ;
}
static void F_41 ( struct V_82 * V_83 ,
struct V_106 * V_107 )
{
if ( V_83 -> V_108 . V_109 == 0 )
return;
memcpy ( V_107 -> V_110 . V_111 ,
V_83 -> V_108 . V_112 ,
V_83 -> V_108 . V_109 ) ;
V_107 -> V_110 . V_113 =
( V_83 -> V_108 . V_109 ) / 4 ;
}
static V_28 F_42 ( struct V_15 * V_16 ,
struct V_82 * V_83 )
{
union V_114 V_115 = { 0 } ;
union V_116 V_117 = { 0 } ;
struct V_118 * V_76 = V_83 -> V_119 -> V_120 ;
switch ( V_83 -> V_121 ) {
case V_122 :
V_115 . V_123 . V_124 =
( V_125 == V_83 -> V_126 ) ?
V_127 :
V_128 ;
V_115 . V_123 . V_129 = V_76 -> V_130 +
( V_83 -> V_131 << 3 ) ;
break;
case V_132 :
V_115 . V_123 . V_124 =
( V_125 == V_83 -> V_126 ) ?
V_127 :
V_128 ;
V_117 . V_133 . V_134 = V_83 -> V_135 ;
V_117 . V_133 . V_136 = V_83 -> V_131 ;
V_115 . V_123 . V_129 = V_117 . V_137 ;
break;
case V_138 :
V_115 . V_123 . V_124 = V_139 ;
V_115 . V_123 . V_129 = V_83 -> V_131 +
( V_83 -> V_135 ) ;
break;
case V_140 :
V_115 . V_123 . V_124 =
( V_125 == V_83 -> V_126 ) ?
V_141 :
V_142 ;
V_115 . V_123 . V_129 = V_76 -> V_143 ;
break;
case V_144 :
V_115 . V_123 . V_124 =
( V_125 == V_83 -> V_126 ) ?
V_145 :
V_146 ;
V_115 . V_123 . V_129 = V_76 -> V_130 ;
break;
default:
V_115 . V_137 = 0xFFFFFFFF ;
break;
}
return V_115 . V_137 ;
}
static void F_43 ( struct V_15 * V_16 ,
struct V_82 * V_83 ,
struct V_106 * V_107 )
{
V_28 V_147 ;
V_107 -> V_110 . V_115 = F_42 ( V_16 , V_83 ) ;
if ( V_107 -> V_110 . V_115 == V_148 ) {
V_107 -> V_149 = 0 ;
return;
}
switch ( V_83 -> V_126 ) {
case V_125 :
if ( V_83 -> V_121 == V_144 )
V_147 = V_83 -> V_102 ;
else
V_147 = V_83 -> V_103 ;
break;
case V_150 :
if ( V_83 -> V_121 == V_144 )
V_147 = V_83 -> V_103 ;
else
V_147 = V_83 -> V_102 ;
break;
default:
F_44 ( V_16 -> V_2 , L_4 ,
V_83 -> V_126 ) ;
return;
}
V_107 -> V_110 . V_151 =
V_83 -> V_151 * V_147 ;
if ( ! V_107 -> V_110 . V_151 ) {
if ( V_83 -> V_126 == V_125 )
V_107 -> V_110 . V_151 = 2 * V_83 -> V_103 ;
else
V_107 -> V_110 . V_151 = 2 * V_83 -> V_102 ;
}
V_107 -> V_149 = 0 ;
V_107 -> V_110 . V_113 = 0 ;
F_41 ( V_83 , V_107 ) ;
}
int F_45 ( struct V_15 * V_16 , struct V_82 * V_83 )
{
struct V_152 * V_153 ;
struct V_20 V_21 = { 0 } ;
int V_154 = 0 ;
if ( V_83 -> V_108 . V_109 == 0 )
return 0 ;
V_21 . V_24 = V_155 ;
V_21 . V_26 = sizeof( struct V_152 ) +
V_83 -> V_108 . V_109 ;
V_153 = F_46 ( V_21 . V_26 , V_156 ) ;
if ( V_153 == NULL )
return - V_157 ;
V_153 -> V_115 = F_42 ( V_16 , V_83 ) ;
V_153 -> V_113 = V_83 -> V_108 . V_109 / 4 ;
memcpy ( V_153 -> V_111 , V_83 -> V_108 . V_112 ,
V_83 -> V_108 . V_109 ) ;
V_154 = F_6 ( & V_16 -> V_27 , & V_21 , ( V_28 * ) V_153 ) ;
F_47 ( V_153 ) ;
return V_154 ;
}
static void F_48 ( struct V_15 * V_16 ,
struct V_82 * V_83 ,
struct V_158 * V_159 )
{
struct V_86 * V_37 = & V_83 -> V_159 [ 0 ] ;
V_159 -> V_89 = ( V_90 ) V_37 -> V_91 ;
V_159 -> V_92 = V_37 -> V_92 ;
V_159 -> V_93 = V_37 -> V_93 ;
V_159 -> V_94 = V_37 -> V_94 ;
V_159 -> V_95 = V_37 -> V_95 ;
V_159 -> V_96 = V_37 -> V_97 ;
V_159 -> V_98 = V_37 -> V_99 ;
V_159 -> V_160 = V_37 -> V_160 ;
F_29 ( V_16 -> V_2 , L_5 ,
V_159 -> V_89 , V_37 -> V_92 , V_37 -> V_93 ) ;
}
static void F_49 ( struct V_15 * V_16 ,
struct V_82 * V_83 ,
struct V_161 * V_162 )
{
struct V_86 * V_163 = & V_83 -> V_159 [ 0 ] ;
F_40 ( V_16 , V_83 ,
(struct V_84 * ) V_162 ) ;
V_162 -> V_164 = V_163 -> V_92 ;
}
static void F_50 ( struct V_15 * V_16 ,
struct V_82 * V_83 ,
struct V_165 * V_166 )
{
struct V_86 * V_163 = & V_83 -> V_159 [ 0 ] ;
int V_52 = 0 ;
F_40 ( V_16 , V_83 ,
(struct V_84 * ) V_166 ) ;
V_166 -> V_167 = V_163 -> V_95 ;
V_166 -> V_168 = 0x0 ;
for ( V_52 = 0 ; V_52 < V_169 ; V_52 ++ )
V_166 -> V_170 [ V_52 ] = 0xDEADBEEF ;
}
static void F_51 ( struct V_15 * V_16 ,
struct V_82 * V_83 ,
struct V_106 * V_107 )
{
struct V_158 * V_159 = & V_107 -> V_159 ;
struct V_84 * V_85 = (struct V_84 * ) V_107 ;
F_40 ( V_16 , V_83 , V_85 ) ;
F_48 ( V_16 , V_83 , V_159 ) ;
F_43 ( V_16 , V_83 , V_107 ) ;
}
static void F_52 ( struct V_15 * V_16 ,
struct V_82 * V_83 ,
struct V_171 * V_172 )
{
struct V_84 * V_85 = (struct V_84 * ) V_172 ;
F_40 ( V_16 , V_83 , V_85 ) ;
if ( V_83 -> V_108 . V_109 == 0 )
return;
memcpy ( V_172 -> V_76 ,
V_83 -> V_108 . V_112 ,
V_83 -> V_108 . V_109 ) ;
}
static void F_53 ( struct V_15 * V_16 ,
struct V_82 * V_83 ,
struct V_173 * V_174 )
{
struct V_158 * V_159 = & V_174 -> V_159 ;
struct V_84 * V_85 =
(struct V_84 * ) V_174 ;
F_40 ( V_16 , V_83 , V_85 ) ;
F_48 ( V_16 , V_83 , V_159 ) ;
}
static T_3 F_54 ( struct V_15 * V_16 ,
struct V_82 * V_83 )
{
T_3 V_175 ;
switch ( V_83 -> V_176 ) {
case V_177 :
V_175 = sizeof( struct V_106 ) ;
V_175 += V_83 -> V_108 . V_109 ;
return V_175 ;
case V_178 :
return sizeof( struct V_161 ) ;
case V_179 :
return sizeof( struct V_165 ) ;
case V_180 :
V_175 = sizeof( struct V_84 ) ;
V_175 += V_83 -> V_108 . V_109 ;
return V_175 ;
case V_181 :
case V_182 :
case V_183 :
return sizeof( struct V_173 ) ;
default:
return sizeof( struct V_84 ) ;
}
return 0 ;
}
static int F_55 ( struct V_15 * V_16 ,
struct V_82 * V_184 ,
T_3 * V_185 ,
void * * V_186 )
{
T_3 V_175 ;
V_175 = F_54 ( V_16 , V_184 ) ;
* V_186 = F_46 ( V_175 , V_156 ) ;
if ( NULL == * V_186 )
return - V_157 ;
* V_185 = V_175 ;
switch ( V_184 -> V_176 ) {
case V_177 :
F_51 ( V_16 , V_184 , * V_186 ) ;
break;
case V_178 :
F_49 ( V_16 , V_184 , * V_186 ) ;
break;
case V_179 :
F_50 ( V_16 , V_184 , * V_186 ) ;
break;
case V_180 :
F_52 ( V_16 , V_184 , * V_186 ) ;
break;
case V_181 :
case V_182 :
case V_183 :
F_53 ( V_16 , V_184 , * V_186 ) ;
break;
default:
F_40 ( V_16 , V_184 , * V_186 ) ;
break;
}
F_29 ( V_16 -> V_2 , L_6 ,
V_184 -> V_54 . V_187 , V_175 ) ;
F_56 ( L_7 , V_188 , 8 , 4 ,
* V_186 , V_175 , false ) ;
return 0 ;
}
static int F_57 ( struct V_189 * V_190 ,
struct V_191 V_54 , int V_192 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_192 ; V_52 ++ ) {
if ( V_190 [ V_52 ] . V_54 . V_187 == V_54 . V_187 &&
V_190 [ V_52 ] . V_54 . V_193 == V_54 . V_193 )
return V_52 ;
}
return - V_35 ;
}
static int F_58 ( struct V_189 * V_190 ,
struct V_82 * V_194 , int V_192 )
{
int V_52 ;
struct V_191 V_54 = V_194 -> V_54 ;
for ( V_52 = 0 ; V_52 < V_192 ; V_52 ++ ) {
if ( V_190 [ V_52 ] . V_195 ) {
if ( ! V_190 [ V_52 ] . V_196 &&
V_190 [ V_52 ] . V_197 == V_198 ) {
V_190 [ V_52 ] . V_196 = true ;
V_190 [ V_52 ] . V_54 . V_187 = V_54 . V_187 ;
V_190 [ V_52 ] . V_54 . V_193 = V_54 . V_193 ;
V_190 [ V_52 ] . V_54 . V_199 = V_54 . V_199 ;
V_190 [ V_52 ] . V_200 = V_194 ;
return V_52 ;
}
} else {
if ( V_190 [ V_52 ] . V_54 . V_187 == V_54 . V_187 &&
V_190 [ V_52 ] . V_54 . V_193 == V_54 . V_193 &&
V_190 [ V_52 ] . V_197 == V_198 ) {
V_190 [ V_52 ] . V_200 = V_194 ;
return V_52 ;
}
}
}
return - V_35 ;
}
static void F_59 ( struct V_189 * V_190 , int V_201 )
{
if ( V_190 [ V_201 ] . V_195 ) {
V_190 [ V_201 ] . V_196 = false ;
V_190 [ V_201 ] . V_54 . V_187 = 0 ;
V_190 [ V_201 ] . V_54 . V_193 = 0 ;
V_190 [ V_201 ] . V_54 . V_199 = 0 ;
}
V_190 [ V_201 ] . V_197 = V_198 ;
V_190 [ V_201 ] . V_200 = NULL ;
}
static void F_60 ( struct V_189 * V_190 , int V_192 ,
struct V_82 * V_202 )
{
int V_52 ;
bool V_203 = false ;
for ( V_52 = 0 ; V_52 < V_192 ; V_52 ++ ) {
if ( V_190 [ V_52 ] . V_197 == V_198 )
continue;
V_203 = true ;
break;
}
if ( ! V_203 )
V_202 -> V_204 = V_205 ;
return;
}
int F_61 ( struct V_15 * V_16 ,
struct V_82 * V_83 )
{
T_3 V_185 = 0 ;
void * V_186 = NULL ;
int V_40 ;
struct V_206 V_21 ;
F_29 ( V_16 -> V_2 , L_8 , V_207 ,
V_83 -> V_54 . V_187 , V_83 -> V_54 . V_199 ) ;
if ( V_83 -> V_119 -> V_208 != V_209 ) {
F_28 ( V_16 -> V_2 , L_9 ,
V_83 -> V_119 -> V_208 , V_83 -> V_119 -> V_210 ) ;
return - V_61 ;
}
V_40 = F_55 ( V_16 , V_83 ,
& V_185 , & V_186 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_10 , V_40 ) ;
return V_40 ;
}
V_21 . V_187 = V_83 -> V_54 . V_187 ;
V_21 . V_193 = V_83 -> V_54 . V_199 ;
V_21 . V_211 = V_83 -> V_119 -> V_210 ;
V_21 . V_26 = V_185 ;
V_21 . V_212 = V_83 -> V_212 ;
V_21 . V_213 = V_83 -> V_213 ;
V_40 = F_62 ( & V_16 -> V_27 , & V_21 , V_186 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_11 , V_40 ) ;
F_47 ( V_186 ) ;
return V_40 ;
}
V_83 -> V_204 = V_205 ;
F_47 ( V_186 ) ;
return V_40 ;
}
static void F_63 ( struct V_15 * V_16 , struct V_82
* V_214 , struct V_82 * V_215 )
{
F_29 ( V_16 -> V_2 , L_12 ,
V_207 , V_214 -> V_54 . V_187 , V_214 -> V_54 . V_199 ) ;
F_29 ( V_16 -> V_2 , L_13 , V_207 ,
V_215 -> V_54 . V_187 , V_215 -> V_54 . V_199 ) ;
F_29 ( V_16 -> V_2 , L_14 ,
V_214 -> V_204 , V_215 -> V_204 ) ;
}
int F_64 ( struct V_15 * V_16 ,
struct V_82 * V_216 ,
struct V_82 * V_217 )
{
int V_40 ;
struct V_218 V_21 ;
struct V_191 V_219 = V_216 -> V_54 ;
struct V_191 V_220 = V_217 -> V_54 ;
int V_221 = V_217 -> V_222 ;
int V_223 = V_216 -> V_224 ;
int V_225 , V_226 , V_227 , V_228 ;
F_63 ( V_16 , V_216 , V_217 ) ;
V_225 = F_57 ( V_216 -> V_229 , V_220 , V_223 ) ;
if ( V_225 < 0 )
return 0 ;
V_21 . V_230 = V_225 ;
V_226 = F_57 ( V_217 -> V_231 , V_219 , V_221 ) ;
if ( V_226 < 0 )
return 0 ;
V_21 . V_232 = V_226 ;
V_227 = V_216 -> V_229 [ V_225 ] . V_197 ;
V_228 = V_217 -> V_231 [ V_226 ] . V_197 ;
if ( V_227 != V_233 ||
V_228 != V_233 )
return 0 ;
V_21 . V_187 = V_216 -> V_54 . V_187 ;
V_21 . V_193 = V_216 -> V_54 . V_199 ;
V_21 . V_234 = V_217 -> V_54 . V_187 ;
V_21 . V_235 = V_217 -> V_54 . V_199 ;
V_21 . V_236 = false ;
V_40 = F_65 ( & V_16 -> V_27 , & V_21 ) ;
if ( ! V_40 ) {
F_59 ( V_216 -> V_229 , V_225 ) ;
F_59 ( V_217 -> V_231 , V_226 ) ;
F_60 ( V_216 -> V_229 , V_223 , V_216 ) ;
}
return V_40 ;
}
int F_66 ( struct V_15 * V_16 ,
struct V_82 * V_216 ,
struct V_82 * V_217 )
{
int V_40 ;
struct V_218 V_21 ;
int V_221 = V_217 -> V_222 ;
int V_223 = V_216 -> V_224 ;
int V_225 , V_226 ;
F_63 ( V_16 , V_216 , V_217 ) ;
if ( V_216 -> V_204 < V_205 ||
V_217 -> V_204 < V_205 )
return 0 ;
V_225 = F_58 ( V_216 -> V_229 , V_217 , V_223 ) ;
if ( V_225 < 0 )
return - V_35 ;
V_21 . V_230 = V_225 ;
V_226 = F_58 ( V_217 -> V_231 , V_216 , V_221 ) ;
if ( V_226 < 0 ) {
F_59 ( V_216 -> V_229 , V_225 ) ;
return - V_35 ;
}
V_21 . V_232 = V_226 ;
F_29 ( V_16 -> V_2 , L_15 ,
V_21 . V_230 , V_21 . V_232 ) ;
V_21 . V_187 = V_216 -> V_54 . V_187 ;
V_21 . V_193 = V_216 -> V_54 . V_199 ;
V_21 . V_234 = V_217 -> V_54 . V_187 ;
V_21 . V_235 = V_217 -> V_54 . V_199 ;
V_21 . V_236 = true ;
V_40 = F_65 ( & V_16 -> V_27 , & V_21 ) ;
if ( ! V_40 ) {
V_216 -> V_204 = V_237 ;
V_216 -> V_229 [ V_225 ] . V_197 = V_233 ;
V_217 -> V_231 [ V_226 ] . V_197 = V_233 ;
} else {
F_59 ( V_216 -> V_229 , V_225 ) ;
F_59 ( V_217 -> V_231 , V_226 ) ;
}
return V_40 ;
}
static int F_67 ( struct V_15 * V_16 , struct V_238 * V_119 ,
enum V_239 V_208 )
{
F_29 ( V_16 -> V_2 , L_16 , V_207 , V_208 ) ;
return F_68 ( & V_16 -> V_27 , V_119 -> V_210 , V_208 ) ;
}
int F_69 ( struct V_15 * V_16 , struct V_238 * V_119 )
{
int V_40 ;
F_29 ( V_16 -> V_2 , L_17 , V_207 , V_119 -> V_210 ) ;
V_40 = F_70 ( & V_16 -> V_27 , V_119 -> V_240 ,
V_119 -> V_241 , V_119 -> V_210 ,
V_119 -> V_242 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_18 ) ;
return V_40 ;
}
V_119 -> V_208 = V_209 ;
return 0 ;
}
int F_71 ( struct V_15 * V_16 , struct V_238 * V_119 )
{
int V_40 ;
F_29 ( V_16 -> V_2 , L_19 , V_207 , V_119 -> V_210 ) ;
if ( V_119 -> V_208 >= V_243 ) {
V_40 = F_67 ( V_16 , V_119 , V_244 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_20 ) ;
return V_40 ;
}
V_119 -> V_208 = V_245 ;
}
if ( V_119 -> V_208 < V_209 )
return 0 ;
V_40 = F_72 ( & V_16 -> V_27 , V_119 -> V_210 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_21 ) ;
return V_40 ;
}
V_119 -> V_208 = V_246 ;
return V_40 ;
}
int F_73 ( struct V_15 * V_16 , struct V_238 * V_119 )
{
int V_40 ;
F_29 ( V_16 -> V_2 , L_19 , V_207 , V_119 -> V_210 ) ;
if ( V_119 -> V_208 < V_209 )
return 0 ;
V_40 = F_67 ( V_16 , V_119 , V_244 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_22 ) ;
return V_40 ;
}
V_119 -> V_208 = V_245 ;
V_40 = F_67 ( V_16 , V_119 , V_247 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_23 ) ;
return V_40 ;
}
V_119 -> V_208 = V_243 ;
return 0 ;
}
int F_74 ( struct V_15 * V_16 , struct V_238 * V_119 )
{
int V_40 ;
F_29 ( V_16 -> V_2 , L_24 , V_207 , V_119 -> V_210 ) ;
if ( V_119 -> V_208 < V_245 )
return 0 ;
V_40 = F_67 ( V_16 , V_119 , V_244 ) ;
if ( V_40 < 0 ) {
F_29 ( V_16 -> V_2 , L_25 ) ;
return V_40 ;
}
V_119 -> V_208 = V_245 ;
return 0 ;
}
int F_75 ( struct V_15 * V_16 , struct V_238 * V_119 )
{
int V_40 ;
if ( V_119 -> V_208 < V_245 )
return 0 ;
V_40 = F_67 ( V_16 , V_119 , V_248 ) ;
if ( V_40 < 0 ) {
F_29 ( V_16 -> V_2 , L_26 , V_40 ) ;
return V_40 ;
}
V_119 -> V_208 = V_249 ;
return 0 ;
}
int F_76 ( struct V_15 * V_16 , V_28 * V_76 , int V_5 ,
V_28 V_250 , struct V_82 * V_202 )
{
struct V_20 V_21 ;
V_21 . V_187 = V_202 -> V_54 . V_187 ;
V_21 . V_193 = V_202 -> V_54 . V_199 ;
V_21 . V_26 = V_5 ;
V_21 . V_24 = V_250 ;
return F_6 ( & V_16 -> V_27 , & V_21 , V_76 ) ;
}
int F_77 ( struct V_15 * V_16 , V_28 * V_76 , int V_5 ,
V_28 V_250 , struct V_82 * V_202 )
{
struct V_20 V_21 ;
V_21 . V_187 = V_202 -> V_54 . V_187 ;
V_21 . V_193 = V_202 -> V_54 . V_199 ;
V_21 . V_26 = V_5 ;
V_21 . V_24 = V_250 ;
return F_78 ( & V_16 -> V_27 , & V_21 , V_76 ) ;
}
