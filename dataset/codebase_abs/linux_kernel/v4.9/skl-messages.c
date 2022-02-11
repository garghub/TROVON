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
F_29 ( V_9 -> V_2 , L_2 , V_40 ) ;
return V_40 ;
}
int F_30 ( struct V_55 * V_55 )
{
struct V_6 * V_7 = & V_55 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_15 * V_16 = V_55 -> V_15 ;
const struct V_50 * V_58 ;
F_26 ( & V_55 -> V_7 , false ) ;
V_58 = F_22 ( V_55 -> V_59 -> V_1 ) ;
if ( ! V_58 )
return - V_61 ;
V_58 -> V_49 ( V_9 -> V_2 , V_16 ) ;
if ( V_16 -> V_64 -> V_65 . V_66 )
F_31 ( V_16 -> V_64 -> V_65 . V_66 ) ;
return 0 ;
}
int F_32 ( struct V_55 * V_55 )
{
struct V_15 * V_16 = V_55 -> V_15 ;
int V_40 ;
if ( ! V_55 -> V_7 . V_9 . V_67 )
return 0 ;
V_40 = F_33 ( V_16 -> V_64 ) ;
if ( V_40 < 0 )
return V_40 ;
F_26 ( & V_55 -> V_7 , false ) ;
F_25 ( & V_55 -> V_7 , false ) ;
return 0 ;
}
int F_34 ( struct V_55 * V_55 )
{
struct V_15 * V_16 = V_55 -> V_15 ;
int V_40 ;
if ( ! V_55 -> V_7 . V_9 . V_67 )
return 0 ;
F_25 ( & V_55 -> V_7 , true ) ;
F_26 ( & V_55 -> V_7 , true ) ;
if ( V_55 -> V_15 -> V_68 == true )
return 0 ;
V_40 = F_35 ( V_16 -> V_64 ) ;
if ( V_40 < 0 )
return V_40 ;
F_5 ( V_55 -> V_15 , false ) ;
return V_40 ;
}
enum V_69 F_36 ( int V_70 )
{
switch ( V_70 ) {
case 8 :
return V_71 ;
case 16 :
return V_72 ;
case 24 :
return V_73 ;
case 32 :
return V_74 ;
default:
return V_75 ;
}
}
static void F_37 ( struct V_15 * V_16 ,
struct V_76 * V_77 ,
struct V_78 * V_79 )
{
struct V_80 * V_37 = & V_77 -> V_81 [ 0 ] ;
V_79 -> V_82 . V_83 = ( V_84 ) V_37 -> V_85 ;
V_79 -> V_82 . V_86 = V_37 -> V_86 ;
V_79 -> V_82 . V_87 = V_37 -> V_87 ;
V_79 -> V_82 . V_88 = V_37 -> V_88 ;
V_79 -> V_82 . V_89 = V_37 -> V_89 ;
F_29 ( V_16 -> V_2 , L_3 ,
V_37 -> V_87 , V_37 -> V_88 ,
V_37 -> V_89 ) ;
V_79 -> V_82 . V_90 = V_37 -> V_91 ;
V_79 -> V_82 . V_92 = V_37 -> V_93 ;
V_79 -> V_94 = V_77 -> V_95 ;
V_79 -> V_96 = V_77 -> V_96 ;
V_79 -> V_97 = V_77 -> V_97 ;
V_79 -> V_98 = V_77 -> V_99 ;
}
static void F_38 ( struct V_76 * V_77 ,
struct V_100 * V_101 )
{
if ( V_77 -> V_102 . V_103 == 0 )
return;
memcpy ( V_101 -> V_104 . V_105 ,
V_77 -> V_102 . V_106 ,
V_77 -> V_102 . V_103 ) ;
V_101 -> V_104 . V_107 =
( V_77 -> V_102 . V_103 ) / 4 ;
}
static V_28 F_39 ( struct V_15 * V_16 ,
struct V_76 * V_77 )
{
union V_108 V_109 = { 0 } ;
union V_110 V_111 = { 0 } ;
struct V_112 * V_70 = V_77 -> V_113 -> V_114 ;
switch ( V_77 -> V_115 ) {
case V_116 :
V_109 . V_117 . V_118 =
( V_119 == V_77 -> V_120 ) ?
V_121 :
V_122 ;
V_109 . V_117 . V_123 = V_70 -> V_124 +
( V_77 -> V_125 << 3 ) ;
break;
case V_126 :
V_109 . V_117 . V_118 =
( V_119 == V_77 -> V_120 ) ?
V_121 :
V_122 ;
V_111 . V_127 . V_128 = V_77 -> V_129 ;
V_111 . V_127 . V_130 = V_77 -> V_125 ;
V_109 . V_117 . V_123 = V_111 . V_131 ;
break;
case V_132 :
V_109 . V_117 . V_118 = V_133 ;
V_109 . V_117 . V_123 = V_77 -> V_125 +
( V_77 -> V_129 ) ;
break;
case V_134 :
V_109 . V_117 . V_118 =
( V_119 == V_77 -> V_120 ) ?
V_135 :
V_136 ;
V_109 . V_117 . V_123 = V_70 -> V_137 ;
break;
case V_138 :
V_109 . V_117 . V_118 =
( V_119 == V_77 -> V_120 ) ?
V_139 :
V_140 ;
V_109 . V_117 . V_123 = V_70 -> V_124 ;
break;
default:
V_109 . V_131 = 0xFFFFFFFF ;
break;
}
return V_109 . V_131 ;
}
static void F_40 ( struct V_15 * V_16 ,
struct V_76 * V_77 ,
struct V_100 * V_101 )
{
V_101 -> V_104 . V_109 = F_39 ( V_16 , V_77 ) ;
if ( V_101 -> V_104 . V_109 == V_141 ) {
V_101 -> V_142 = 0 ;
return;
}
if ( V_119 == V_77 -> V_120 )
V_101 -> V_104 . V_143 = 2 * V_77 -> V_97 ;
else
V_101 -> V_104 . V_143 = 2 * V_77 -> V_96 ;
V_101 -> V_142 = 0 ;
V_101 -> V_104 . V_107 = 0 ;
F_38 ( V_77 , V_101 ) ;
}
int F_41 ( struct V_15 * V_16 , struct V_76 * V_77 )
{
struct V_144 * V_145 ;
struct V_146 V_147 ;
struct V_20 V_21 = { 0 } ;
int V_148 = 0 ;
if ( V_77 -> V_102 . V_103 == sizeof( V_147 ) )
return 0 ;
V_21 . V_24 = V_149 ;
V_21 . V_26 = sizeof( struct V_144 ) +
V_77 -> V_102 . V_103 ;
V_145 = F_42 ( V_21 . V_26 , V_150 ) ;
if ( V_145 == NULL )
return - V_151 ;
V_145 -> V_109 = F_39 ( V_16 , V_77 ) ;
V_145 -> V_107 = sizeof( V_147 ) / 4 ;
memcpy ( V_145 -> V_105 , V_77 -> V_102 . V_106 ,
V_77 -> V_102 . V_103 ) ;
V_148 = F_6 ( & V_16 -> V_27 , & V_21 , ( V_28 * ) V_145 ) ;
F_43 ( V_145 ) ;
return V_148 ;
}
static void F_44 ( struct V_15 * V_16 ,
struct V_76 * V_77 ,
struct V_152 * V_153 )
{
struct V_80 * V_37 = & V_77 -> V_153 [ 0 ] ;
V_153 -> V_83 = ( V_84 ) V_37 -> V_85 ;
V_153 -> V_86 = V_37 -> V_86 ;
V_153 -> V_87 = V_37 -> V_87 ;
V_153 -> V_88 = V_37 -> V_88 ;
V_153 -> V_89 = V_37 -> V_89 ;
V_153 -> V_90 = V_37 -> V_91 ;
V_153 -> V_92 = V_37 -> V_93 ;
V_153 -> V_154 = V_37 -> V_154 ;
F_29 ( V_16 -> V_2 , L_4 ,
V_153 -> V_83 , V_37 -> V_86 , V_37 -> V_87 ) ;
}
static void F_45 ( struct V_15 * V_16 ,
struct V_76 * V_77 ,
struct V_155 * V_156 )
{
struct V_80 * V_157 = & V_77 -> V_153 [ 0 ] ;
F_37 ( V_16 , V_77 ,
(struct V_78 * ) V_156 ) ;
V_156 -> V_158 = V_157 -> V_86 ;
}
static void F_46 ( struct V_15 * V_16 ,
struct V_76 * V_77 ,
struct V_159 * V_160 )
{
struct V_80 * V_157 = & V_77 -> V_153 [ 0 ] ;
int V_52 = 0 ;
F_37 ( V_16 , V_77 ,
(struct V_78 * ) V_160 ) ;
V_160 -> V_161 = V_157 -> V_89 ;
V_160 -> V_162 = 0x0 ;
for ( V_52 = 0 ; V_52 < V_163 ; V_52 ++ )
V_160 -> V_164 [ V_52 ] = 0xDEADBEEF ;
}
static void F_47 ( struct V_15 * V_16 ,
struct V_76 * V_77 ,
struct V_100 * V_101 )
{
struct V_152 * V_153 = & V_101 -> V_153 ;
struct V_78 * V_79 = (struct V_78 * ) V_101 ;
F_37 ( V_16 , V_77 , V_79 ) ;
F_44 ( V_16 , V_77 , V_153 ) ;
F_40 ( V_16 , V_77 , V_101 ) ;
}
static void F_48 ( struct V_15 * V_16 ,
struct V_76 * V_77 ,
struct V_165 * V_166 )
{
struct V_78 * V_79 = (struct V_78 * ) V_166 ;
F_37 ( V_16 , V_77 , V_79 ) ;
if ( V_77 -> V_102 . V_103 == 0 )
return;
memcpy ( V_166 -> V_70 ,
V_77 -> V_102 . V_106 ,
V_77 -> V_102 . V_103 ) ;
}
static void F_49 ( struct V_15 * V_16 ,
struct V_76 * V_77 ,
struct V_167 * V_168 )
{
struct V_152 * V_153 = & V_168 -> V_153 ;
struct V_78 * V_79 =
(struct V_78 * ) V_168 ;
F_37 ( V_16 , V_77 , V_79 ) ;
F_44 ( V_16 , V_77 , V_153 ) ;
}
static T_3 F_50 ( struct V_15 * V_16 ,
struct V_76 * V_77 )
{
T_3 V_169 ;
switch ( V_77 -> V_170 ) {
case V_171 :
V_169 = sizeof( struct V_100 ) ;
V_169 += V_77 -> V_102 . V_103 ;
return V_169 ;
case V_172 :
return sizeof( struct V_155 ) ;
case V_173 :
return sizeof( struct V_159 ) ;
case V_174 :
V_169 = sizeof( struct V_78 ) ;
V_169 += V_77 -> V_102 . V_103 ;
return V_169 ;
case V_175 :
case V_176 :
return sizeof( struct V_167 ) ;
default:
return sizeof( struct V_78 ) ;
}
return 0 ;
}
static int F_51 ( struct V_15 * V_16 ,
struct V_76 * V_177 ,
T_3 * V_178 ,
void * * V_179 )
{
T_3 V_169 ;
V_169 = F_50 ( V_16 , V_177 ) ;
* V_179 = F_42 ( V_169 , V_150 ) ;
if ( NULL == * V_179 )
return - V_151 ;
* V_178 = V_169 ;
switch ( V_177 -> V_170 ) {
case V_171 :
F_47 ( V_16 , V_177 , * V_179 ) ;
break;
case V_172 :
F_45 ( V_16 , V_177 , * V_179 ) ;
break;
case V_173 :
F_46 ( V_16 , V_177 , * V_179 ) ;
break;
case V_174 :
F_48 ( V_16 , V_177 , * V_179 ) ;
break;
case V_175 :
case V_176 :
F_49 ( V_16 , V_177 , * V_179 ) ;
break;
default:
F_37 ( V_16 , V_177 , * V_179 ) ;
break;
}
F_29 ( V_16 -> V_2 , L_5 ,
V_177 -> V_54 . V_180 , V_169 ) ;
F_52 ( L_6 , V_181 , 8 , 4 ,
* V_179 , V_169 , false ) ;
return 0 ;
}
static int F_53 ( struct V_182 * V_183 ,
struct V_184 V_54 , int V_185 )
{
int V_52 ;
for ( V_52 = 0 ; V_52 < V_185 ; V_52 ++ ) {
if ( V_183 [ V_52 ] . V_54 . V_180 == V_54 . V_180 &&
V_183 [ V_52 ] . V_54 . V_186 == V_54 . V_186 )
return V_52 ;
}
return - V_35 ;
}
static int F_54 ( struct V_182 * V_183 ,
struct V_76 * V_187 , int V_185 )
{
int V_52 ;
struct V_184 V_54 = V_187 -> V_54 ;
for ( V_52 = 0 ; V_52 < V_185 ; V_52 ++ ) {
if ( V_183 [ V_52 ] . V_188 ) {
if ( ! V_183 [ V_52 ] . V_189 &&
V_183 [ V_52 ] . V_190 == V_191 ) {
V_183 [ V_52 ] . V_189 = true ;
V_183 [ V_52 ] . V_54 . V_180 = V_54 . V_180 ;
V_183 [ V_52 ] . V_54 . V_186 = V_54 . V_186 ;
V_183 [ V_52 ] . V_54 . V_192 = V_54 . V_192 ;
V_183 [ V_52 ] . V_193 = V_187 ;
return V_52 ;
}
} else {
if ( V_183 [ V_52 ] . V_54 . V_180 == V_54 . V_180 &&
V_183 [ V_52 ] . V_54 . V_186 == V_54 . V_186 &&
V_183 [ V_52 ] . V_190 == V_191 ) {
V_183 [ V_52 ] . V_193 = V_187 ;
return V_52 ;
}
}
}
return - V_35 ;
}
static void F_55 ( struct V_182 * V_183 , int V_194 )
{
if ( V_183 [ V_194 ] . V_188 ) {
V_183 [ V_194 ] . V_189 = false ;
V_183 [ V_194 ] . V_54 . V_180 = 0 ;
V_183 [ V_194 ] . V_54 . V_186 = 0 ;
V_183 [ V_194 ] . V_54 . V_192 = 0 ;
}
V_183 [ V_194 ] . V_190 = V_191 ;
V_183 [ V_194 ] . V_193 = NULL ;
}
static void F_56 ( struct V_182 * V_183 , int V_185 ,
struct V_76 * V_195 )
{
int V_52 ;
bool V_196 = false ;
for ( V_52 = 0 ; V_52 < V_185 ; V_52 ++ ) {
if ( V_183 [ V_52 ] . V_190 == V_191 )
continue;
V_196 = true ;
break;
}
if ( ! V_196 )
V_195 -> V_197 = V_198 ;
return;
}
int F_57 ( struct V_15 * V_16 ,
struct V_76 * V_77 )
{
T_3 V_178 = 0 ;
void * V_179 = NULL ;
int V_40 ;
struct V_199 V_21 ;
F_29 ( V_16 -> V_2 , L_7 , V_200 ,
V_77 -> V_54 . V_180 , V_77 -> V_54 . V_192 ) ;
if ( V_77 -> V_113 -> V_201 != V_202 ) {
F_28 ( V_16 -> V_2 , L_8 ,
V_77 -> V_113 -> V_201 , V_77 -> V_113 -> V_203 ) ;
return - V_61 ;
}
V_40 = F_51 ( V_16 , V_77 ,
& V_178 , & V_179 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_9 , V_40 ) ;
return V_40 ;
}
V_21 . V_180 = V_77 -> V_54 . V_180 ;
V_21 . V_186 = V_77 -> V_54 . V_192 ;
V_21 . V_204 = V_77 -> V_113 -> V_203 ;
V_21 . V_26 = V_178 ;
V_21 . V_205 = V_77 -> V_205 ;
V_21 . V_206 = V_77 -> V_206 ;
V_40 = F_58 ( & V_16 -> V_27 , & V_21 , V_179 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_10 , V_40 ) ;
F_43 ( V_179 ) ;
return V_40 ;
}
V_77 -> V_197 = V_207 ;
F_43 ( V_179 ) ;
return V_40 ;
}
static void F_59 ( struct V_15 * V_16 , struct V_76
* V_208 , struct V_76 * V_209 )
{
F_29 ( V_16 -> V_2 , L_11 ,
V_200 , V_208 -> V_54 . V_180 , V_208 -> V_54 . V_192 ) ;
F_29 ( V_16 -> V_2 , L_12 , V_200 ,
V_209 -> V_54 . V_180 , V_209 -> V_54 . V_192 ) ;
F_29 ( V_16 -> V_2 , L_13 ,
V_208 -> V_197 , V_209 -> V_197 ) ;
}
int F_60 ( struct V_15 * V_16 ,
struct V_76 * V_210 ,
struct V_76 * V_211 )
{
int V_40 ;
struct V_212 V_21 ;
struct V_184 V_213 = V_210 -> V_54 ;
struct V_184 V_214 = V_211 -> V_54 ;
int V_215 = V_211 -> V_216 ;
int V_217 = V_210 -> V_218 ;
int V_219 , V_220 , V_221 , V_222 ;
F_59 ( V_16 , V_210 , V_211 ) ;
V_219 = F_53 ( V_210 -> V_223 , V_214 , V_217 ) ;
if ( V_219 < 0 )
return 0 ;
V_21 . V_224 = V_219 ;
V_220 = F_53 ( V_211 -> V_225 , V_213 , V_215 ) ;
if ( V_220 < 0 )
return 0 ;
V_21 . V_226 = V_220 ;
V_221 = V_210 -> V_223 [ V_219 ] . V_190 ;
V_222 = V_211 -> V_225 [ V_220 ] . V_190 ;
if ( V_221 != V_227 ||
V_222 != V_227 )
return 0 ;
V_21 . V_180 = V_210 -> V_54 . V_180 ;
V_21 . V_186 = V_210 -> V_54 . V_192 ;
V_21 . V_228 = V_211 -> V_54 . V_180 ;
V_21 . V_229 = V_211 -> V_54 . V_192 ;
V_21 . V_230 = false ;
V_40 = F_61 ( & V_16 -> V_27 , & V_21 ) ;
if ( ! V_40 ) {
F_55 ( V_210 -> V_223 , V_219 ) ;
F_55 ( V_211 -> V_225 , V_220 ) ;
F_56 ( V_210 -> V_223 , V_217 , V_210 ) ;
}
return V_40 ;
}
int F_62 ( struct V_15 * V_16 ,
struct V_76 * V_210 ,
struct V_76 * V_211 )
{
int V_40 ;
struct V_212 V_21 ;
int V_215 = V_211 -> V_216 ;
int V_217 = V_210 -> V_218 ;
int V_219 , V_220 ;
F_59 ( V_16 , V_210 , V_211 ) ;
if ( V_210 -> V_197 < V_207 ||
V_211 -> V_197 < V_207 )
return 0 ;
V_219 = F_54 ( V_210 -> V_223 , V_211 , V_217 ) ;
if ( V_219 < 0 )
return - V_35 ;
V_21 . V_224 = V_219 ;
V_220 = F_54 ( V_211 -> V_225 , V_210 , V_215 ) ;
if ( V_220 < 0 ) {
F_55 ( V_210 -> V_223 , V_219 ) ;
return - V_35 ;
}
V_21 . V_226 = V_220 ;
F_29 ( V_16 -> V_2 , L_14 ,
V_21 . V_224 , V_21 . V_226 ) ;
V_21 . V_180 = V_210 -> V_54 . V_180 ;
V_21 . V_186 = V_210 -> V_54 . V_192 ;
V_21 . V_228 = V_211 -> V_54 . V_180 ;
V_21 . V_229 = V_211 -> V_54 . V_192 ;
V_21 . V_230 = true ;
V_40 = F_61 ( & V_16 -> V_27 , & V_21 ) ;
if ( ! V_40 ) {
V_210 -> V_197 = V_231 ;
V_210 -> V_223 [ V_219 ] . V_190 = V_227 ;
V_211 -> V_225 [ V_220 ] . V_190 = V_227 ;
} else {
F_55 ( V_210 -> V_223 , V_219 ) ;
F_55 ( V_211 -> V_225 , V_220 ) ;
}
return V_40 ;
}
static int F_63 ( struct V_15 * V_16 , struct V_232 * V_113 ,
enum V_233 V_201 )
{
F_29 ( V_16 -> V_2 , L_15 , V_200 , V_201 ) ;
return F_64 ( & V_16 -> V_27 , V_113 -> V_203 , V_201 ) ;
}
int F_65 ( struct V_15 * V_16 , struct V_232 * V_113 )
{
int V_40 ;
F_29 ( V_16 -> V_2 , L_16 , V_200 , V_113 -> V_203 ) ;
V_40 = F_66 ( & V_16 -> V_27 , V_113 -> V_234 ,
V_113 -> V_235 , V_113 -> V_203 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_17 ) ;
return V_40 ;
}
V_113 -> V_201 = V_202 ;
return 0 ;
}
int F_67 ( struct V_15 * V_16 , struct V_232 * V_113 )
{
int V_40 ;
F_29 ( V_16 -> V_2 , L_18 , V_200 , V_113 -> V_203 ) ;
if ( V_113 -> V_201 > V_236 ) {
V_40 = F_63 ( V_16 , V_113 , V_237 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_19 ) ;
return V_40 ;
}
V_113 -> V_201 = V_238 ;
}
if ( V_113 -> V_201 < V_202 )
return 0 ;
V_40 = F_68 ( & V_16 -> V_27 , V_113 -> V_203 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_20 ) ;
return V_40 ;
}
V_113 -> V_201 = V_239 ;
return V_40 ;
}
int F_69 ( struct V_15 * V_16 , struct V_232 * V_113 )
{
int V_40 ;
F_29 ( V_16 -> V_2 , L_18 , V_200 , V_113 -> V_203 ) ;
if ( V_113 -> V_201 < V_202 )
return 0 ;
V_40 = F_63 ( V_16 , V_113 , V_237 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_21 ) ;
return V_40 ;
}
V_113 -> V_201 = V_238 ;
V_40 = F_63 ( V_16 , V_113 , V_240 ) ;
if ( V_40 < 0 ) {
F_28 ( V_16 -> V_2 , L_22 ) ;
return V_40 ;
}
V_113 -> V_201 = V_236 ;
return 0 ;
}
int F_70 ( struct V_15 * V_16 , struct V_232 * V_113 )
{
int V_40 ;
F_29 ( V_16 -> V_2 , L_23 , V_200 , V_113 -> V_203 ) ;
if ( V_113 -> V_201 < V_238 )
return 0 ;
V_40 = F_63 ( V_16 , V_113 , V_237 ) ;
if ( V_40 < 0 ) {
F_29 ( V_16 -> V_2 , L_24 ) ;
return V_40 ;
}
V_113 -> V_201 = V_238 ;
return 0 ;
}
int F_71 ( struct V_15 * V_16 , struct V_232 * V_113 )
{
int V_40 ;
if ( V_113 -> V_201 < V_238 )
return 0 ;
V_40 = F_63 ( V_16 , V_113 , V_241 ) ;
if ( V_40 < 0 ) {
F_29 ( V_16 -> V_2 , L_25 , V_40 ) ;
return V_40 ;
}
V_113 -> V_201 = V_242 ;
return 0 ;
}
int F_72 ( struct V_15 * V_16 , V_28 * V_70 , int V_5 ,
V_28 V_243 , struct V_76 * V_195 )
{
struct V_20 V_21 ;
V_21 . V_180 = V_195 -> V_54 . V_180 ;
V_21 . V_186 = V_195 -> V_54 . V_192 ;
V_21 . V_26 = V_5 ;
V_21 . V_24 = V_243 ;
return F_6 ( & V_16 -> V_27 , & V_21 , V_70 ) ;
}
int F_73 ( struct V_15 * V_16 , V_28 * V_70 , int V_5 ,
V_28 V_243 , struct V_76 * V_195 )
{
struct V_20 V_21 ;
V_21 . V_180 = V_195 -> V_54 . V_180 ;
V_21 . V_186 = V_195 -> V_54 . V_192 ;
V_21 . V_26 = V_5 ;
V_21 . V_24 = V_243 ;
return F_74 ( & V_16 -> V_27 , & V_21 , V_70 ) ;
}
