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
int F_5 ( struct V_15 * V_15 )
{
void T_2 * V_16 ;
struct V_6 * V_7 = & V_15 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
int V_17 = V_9 -> V_17 ;
struct V_18 V_19 ;
int V_20 ;
V_19 . V_21 = F_1 ;
V_19 . V_22 = F_4 ;
F_6 ( & V_15 -> V_7 , true ) ;
F_7 ( & V_15 -> V_7 , true ) ;
V_16 = F_8 ( V_15 -> V_23 , 4 ) ;
if ( V_16 == NULL ) {
F_9 ( V_9 -> V_2 , L_1 ) ;
return - V_24 ;
}
V_20 = F_10 ( V_9 -> V_2 , V_16 , V_17 ,
V_19 , & V_15 -> V_25 ) ;
F_11 ( V_9 -> V_2 , L_2 , V_20 ) ;
return V_20 ;
}
void F_12 ( struct V_15 * V_15 )
{
struct V_6 * V_7 = & V_15 -> V_7 ;
struct V_8 * V_9 = F_3 ( V_7 ) ;
struct V_25 * V_26 = V_15 -> V_25 ;
F_7 ( & V_15 -> V_7 , false ) ;
F_13 ( V_9 -> V_2 , V_26 ) ;
if ( V_26 -> V_27 -> V_28 . V_29 )
F_14 ( V_26 -> V_27 -> V_28 . V_29 ) ;
}
int F_15 ( struct V_15 * V_15 )
{
struct V_25 * V_26 = V_15 -> V_25 ;
int V_20 ;
if ( ! V_15 -> V_7 . V_30 )
return 0 ;
V_20 = F_16 ( V_26 -> V_27 ) ;
if ( V_20 < 0 )
return V_20 ;
F_7 ( & V_15 -> V_7 , false ) ;
F_6 ( & V_15 -> V_7 , false ) ;
return 0 ;
}
int F_17 ( struct V_15 * V_15 )
{
struct V_25 * V_26 = V_15 -> V_25 ;
if ( ! V_15 -> V_7 . V_30 )
return 0 ;
F_6 ( & V_15 -> V_7 , true ) ;
F_7 ( & V_15 -> V_7 , true ) ;
return F_18 ( V_26 -> V_27 ) ;
}
enum V_31 F_19 ( int V_32 )
{
switch ( V_32 ) {
case 8 :
return V_33 ;
case 16 :
return V_34 ;
case 24 :
return V_35 ;
case 32 :
return V_36 ;
default:
return V_37 ;
}
}
static T_3 F_20 ( enum V_38 V_39 )
{
T_3 V_40 ;
switch ( V_39 ) {
case V_41 :
V_40 = ( 0xFFFFFFF0 | V_42 ) ;
break;
case V_43 :
V_40 = ( 0xFFFFFF00 | V_42
| ( V_44 << 4 ) ) ;
break;
case V_45 :
V_40 = ( 0xFFFFF000 | V_42
| ( V_44 << 4 )
| ( V_46 << 8 ) ) ;
break;
case V_47 :
V_40 = ( 0xFFFFF000 | V_42
| ( V_48 << 4 )
| ( V_44 << 8 ) ) ;
break;
case V_49 :
V_40 = ( 0xFFFF0000 | V_42
| ( V_48 << 4 )
| ( V_44 << 8 )
| ( V_46 << 12 ) ) ;
break;
case V_50 :
V_40 = ( 0xFFFF0000 | V_42
| ( V_44 << 4 )
| ( V_51 << 8 )
| ( V_52 << 12 ) ) ;
break;
case V_53 :
V_40 = ( 0xFFFF0000 | V_42
| ( V_48 << 4 )
| ( V_44 << 8 )
| ( V_54 << 12 ) ) ;
break;
case V_55 :
V_40 = ( 0xFFF00000 | V_42
| ( V_48 << 4 )
| ( V_44 << 8 )
| ( V_51 << 12 )
| ( V_52 << 16 ) ) ;
break;
case V_56 :
V_40 = ( 0xFF000000 | V_48
| ( V_42 << 4 )
| ( V_44 << 8 )
| ( V_51 << 12 )
| ( V_52 << 16 )
| ( V_46 << 20 ) ) ;
break;
case V_57 :
V_40 = ( 0xFFFFFF00 | V_42
| ( V_42 << 4 ) ) ;
break;
case V_58 :
V_40 = ( 0xFFFFFF00 | V_42
| ( V_44 << 4 ) ) ;
break;
case V_59 :
V_40 = ( 0xFFFF00FF | ( V_42 << 8 )
| ( V_44 << 12 ) ) ;
break;
default:
V_40 = 0xFFFFFFFF ;
break;
}
return V_40 ;
}
static void F_21 ( struct V_25 * V_26 ,
struct V_60 * V_61 ,
struct V_62 * V_63 )
{
struct V_64 * V_65 = & V_61 -> V_66 ;
V_63 -> V_67 . V_68 = ( V_69 ) V_65 -> V_70 ;
V_63 -> V_67 . V_71 = V_65 -> V_71 ;
V_63 -> V_67 . V_72 = V_65 -> V_72 ;
V_63 -> V_67 . V_73 = V_65 -> V_73 ;
V_63 -> V_67 . V_39 = V_65 -> V_39 ;
F_11 ( V_26 -> V_2 , L_3 ,
V_65 -> V_72 , V_65 -> V_73 ,
V_65 -> V_39 ) ;
V_63 -> V_67 . V_74 = F_20 (
V_63 -> V_67 . V_39 ) ;
V_63 -> V_67 . V_75 = V_76 ;
V_63 -> V_77 = V_61 -> V_78 ;
V_63 -> V_79 = V_61 -> V_79 ;
V_63 -> V_80 = V_61 -> V_80 ;
}
static void F_22 ( struct V_60 * V_61 ,
struct V_81 * V_82 )
{
if ( V_61 -> V_83 . V_84 == 0 )
return;
memcpy ( V_82 -> V_85 . V_86 ,
V_61 -> V_83 . V_87 ,
V_61 -> V_83 . V_84 ) ;
V_82 -> V_85 . V_88 =
( V_61 -> V_83 . V_84 ) / 4 ;
}
static void F_23 ( struct V_25 * V_26 ,
struct V_60 * V_61 ,
struct V_81 * V_82 )
{
union V_89 V_90 = { 0 } ;
struct V_91 * V_32 = V_61 -> V_92 -> V_93 ;
switch ( V_61 -> V_94 ) {
case V_95 :
V_90 . V_96 . V_97 =
( V_98 == V_61 -> V_99 ) ?
V_100 :
V_101 ;
V_90 . V_96 . V_102 = V_32 -> V_103 +
( V_61 -> V_104 << 3 ) ;
break;
case V_105 :
V_90 . V_96 . V_97 =
( V_98 == V_61 -> V_99 ) ?
V_100 :
V_101 ;
V_90 . V_96 . V_102 = V_32 -> V_103 +
( V_61 -> V_106 << 1 ) +
( V_61 -> V_104 << 3 ) ;
break;
case V_107 :
V_90 . V_96 . V_97 = V_108 ;
V_90 . V_96 . V_102 = V_61 -> V_104 +
( V_61 -> V_106 ) ;
break;
case V_109 :
V_90 . V_96 . V_97 =
( V_98 == V_61 -> V_99 ) ?
V_110 :
V_111 ;
V_90 . V_96 . V_102 = V_32 -> V_112 ;
break;
default:
V_90 . V_96 . V_97 =
( V_98 == V_61 -> V_99 ) ?
V_113 :
V_114 ;
V_90 . V_96 . V_102 = V_32 -> V_103 ;
break;
}
V_82 -> V_85 . V_90 = V_90 . V_115 ;
if ( V_98 == V_61 -> V_99 )
V_82 -> V_85 . V_116 = 2 * V_61 -> V_80 ;
else
V_82 -> V_85 . V_116 = 2 * V_61 -> V_79 ;
V_82 -> V_117 = 0 ;
V_82 -> V_85 . V_88 = 0 ;
F_22 ( V_61 , V_82 ) ;
}
static void F_24 ( struct V_25 * V_26 ,
struct V_60 * V_61 ,
struct V_118 * V_119 )
{
struct V_64 * V_65 = & V_61 -> V_119 ;
V_119 -> V_68 = ( V_69 ) V_65 -> V_70 ;
V_119 -> V_71 = V_65 -> V_71 ;
V_119 -> V_72 = V_65 -> V_72 ;
V_119 -> V_73 = V_65 -> V_73 ;
V_119 -> V_39 = V_65 -> V_39 ;
V_119 -> V_74 = F_20 ( V_119 -> V_39 ) ;
V_119 -> V_75 = V_76 ;
F_11 ( V_26 -> V_2 , L_4 ,
V_119 -> V_68 , V_65 -> V_71 , V_65 -> V_72 ) ;
}
static void F_25 ( struct V_25 * V_26 ,
struct V_60 * V_61 ,
struct V_120 * V_121 )
{
struct V_64 * V_122 = & V_61 -> V_119 ;
F_21 ( V_26 , V_61 ,
(struct V_62 * ) V_121 ) ;
V_121 -> V_123 = V_122 -> V_71 ;
}
static void F_26 ( struct V_25 * V_26 ,
struct V_60 * V_61 ,
struct V_124 * V_125 )
{
struct V_64 * V_122 = & V_61 -> V_119 ;
int V_126 = 0 ;
F_21 ( V_26 , V_61 ,
(struct V_62 * ) V_125 ) ;
V_125 -> V_127 = V_122 -> V_39 ;
V_125 -> V_128 = 0x0 ;
for ( V_126 = 0 ; V_126 < V_129 ; V_126 ++ )
V_125 -> V_130 [ V_126 ] = 0xDEADBEEF ;
}
static void F_27 ( struct V_25 * V_26 ,
struct V_60 * V_61 ,
struct V_81 * V_82 )
{
struct V_118 * V_119 = & V_82 -> V_119 ;
struct V_62 * V_63 = (struct V_62 * ) V_82 ;
F_21 ( V_26 , V_61 , V_63 ) ;
F_24 ( V_26 , V_61 , V_119 ) ;
F_23 ( V_26 , V_61 , V_82 ) ;
}
static T_4 F_28 ( struct V_25 * V_26 ,
struct V_60 * V_61 )
{
T_4 V_131 ;
switch ( V_61 -> V_132 ) {
case V_133 :
V_131 = sizeof( struct V_81 ) ;
V_131 += V_61 -> V_83 . V_84 ;
return V_131 ;
case V_134 :
return sizeof( struct V_120 ) ;
case V_135 :
return sizeof( struct V_124 ) ;
default:
return sizeof( struct V_62 ) ;
}
return 0 ;
}
static int F_29 ( struct V_25 * V_26 ,
struct V_60 * V_136 ,
T_4 * V_137 ,
void * * V_138 )
{
T_4 V_131 ;
V_131 = F_28 ( V_26 , V_136 ) ;
* V_138 = F_30 ( V_131 , V_139 ) ;
if ( NULL == * V_138 )
return - V_140 ;
* V_137 = V_131 ;
switch ( V_136 -> V_132 ) {
case V_133 :
F_27 ( V_26 , V_136 , * V_138 ) ;
break;
case V_134 :
F_25 ( V_26 , V_136 , * V_138 ) ;
break;
case V_135 :
F_26 ( V_26 , V_136 , * V_138 ) ;
break;
default:
F_21 ( V_26 , V_136 , * V_138 ) ;
break;
}
F_11 ( V_26 -> V_2 , L_5 ,
V_136 -> V_141 . V_142 , V_131 ) ;
F_31 ( V_143 , L_6 , V_144 , 8 , 4 ,
* V_138 , V_131 , false ) ;
return 0 ;
}
static int F_32 ( struct V_145 * V_146 ,
struct V_147 V_141 , int V_148 )
{
int V_126 ;
for ( V_126 = 0 ; V_126 < V_148 ; V_126 ++ ) {
if ( V_146 [ V_126 ] . V_141 . V_142 == V_141 . V_142 &&
V_146 [ V_126 ] . V_141 . V_149 == V_141 . V_149 )
return V_126 ;
}
return - V_150 ;
}
static int F_33 ( struct V_145 * V_146 ,
struct V_147 V_141 , int V_148 )
{
int V_126 ;
for ( V_126 = 0 ; V_126 < V_148 ; V_126 ++ ) {
if ( V_146 [ V_126 ] . V_151 ) {
if ( ! V_146 [ V_126 ] . V_152 ) {
V_146 [ V_126 ] . V_152 = true ;
V_146 [ V_126 ] . V_141 . V_142 = V_141 . V_142 ;
V_146 [ V_126 ] . V_141 . V_149 = V_141 . V_149 ;
return V_126 ;
}
} else {
if ( V_146 [ V_126 ] . V_141 . V_142 == V_141 . V_142 &&
V_146 [ V_126 ] . V_141 . V_149 == V_141 . V_149 )
return V_126 ;
}
}
return - V_150 ;
}
static void F_34 ( struct V_145 * V_146 , int V_153 )
{
if ( V_146 [ V_153 ] . V_151 ) {
V_146 [ V_153 ] . V_152 = false ;
V_146 [ V_153 ] . V_141 . V_142 = 0 ;
V_146 [ V_153 ] . V_141 . V_149 = 0 ;
}
}
int F_35 ( struct V_25 * V_26 ,
struct V_60 * V_61 , char * V_154 )
{
T_4 V_137 = 0 ;
void * V_138 = NULL ;
int V_20 ;
struct V_155 V_156 ;
F_11 ( V_26 -> V_2 , L_7 , V_157 ,
V_61 -> V_141 . V_142 , V_61 -> V_141 . V_149 ) ;
if ( V_61 -> V_92 -> V_158 != V_159 ) {
F_9 ( V_26 -> V_2 , L_8 ,
V_61 -> V_92 -> V_158 , V_61 -> V_92 -> V_160 ) ;
return - V_161 ;
}
V_20 = F_29 ( V_26 , V_61 ,
& V_137 , & V_138 ) ;
if ( V_20 < 0 ) {
F_9 ( V_26 -> V_2 , L_9 , V_20 ) ;
return V_20 ;
}
V_156 . V_142 = V_61 -> V_141 . V_142 ;
V_156 . V_149 = V_61 -> V_141 . V_149 ;
V_156 . V_162 = V_61 -> V_92 -> V_160 ;
V_156 . V_163 = V_137 ;
V_156 . V_164 = V_61 -> V_164 ;
V_20 = F_36 ( & V_26 -> V_165 , & V_156 , V_138 ) ;
if ( V_20 < 0 ) {
F_9 ( V_26 -> V_2 , L_10 , V_20 ) ;
F_37 ( V_138 ) ;
return V_20 ;
}
V_61 -> V_166 = V_167 ;
return V_20 ;
}
static void F_38 ( struct V_25 * V_26 , struct V_60
* V_168 , struct V_60 * V_169 )
{
F_11 ( V_26 -> V_2 , L_11 ,
V_157 , V_168 -> V_141 . V_142 , V_168 -> V_141 . V_149 ) ;
F_11 ( V_26 -> V_2 , L_12 , V_157 ,
V_169 -> V_141 . V_142 , V_169 -> V_141 . V_149 ) ;
F_11 ( V_26 -> V_2 , L_13 ,
V_168 -> V_166 , V_169 -> V_166 ) ;
}
int F_39 ( struct V_25 * V_26 ,
struct V_60 * V_170 ,
struct V_60 * V_171 )
{
int V_20 ;
struct V_172 V_156 ;
struct V_147 V_173 = V_170 -> V_141 ;
struct V_147 V_174 = V_171 -> V_141 ;
int V_175 = V_171 -> V_176 ;
int V_177 = V_170 -> V_178 ;
int V_179 , V_180 ;
F_38 ( V_26 , V_170 , V_171 ) ;
if ( V_170 -> V_166 != V_181 )
return 0 ;
if ( ( V_170 -> V_92 -> V_160 != V_171 -> V_92 -> V_160 ) &&
V_171 -> V_166 != V_181 )
return 0 ;
else if ( V_170 -> V_166 < V_167 &&
V_171 -> V_166 < V_167 )
return 0 ;
V_179 = F_32 ( V_170 -> V_182 , V_174 , V_177 ) ;
if ( V_179 < 0 )
return - V_150 ;
V_156 . V_183 = V_170 -> V_182 [ V_179 ] . V_184 ;
V_180 = F_32 ( V_171 -> V_185 , V_173 , V_175 ) ;
if ( V_180 < 0 )
return - V_150 ;
V_156 . V_186 = V_171 -> V_185 [ V_180 ] . V_184 ;
V_156 . V_142 = V_170 -> V_141 . V_142 ;
V_156 . V_149 = V_170 -> V_141 . V_149 ;
V_156 . V_187 = V_171 -> V_141 . V_142 ;
V_156 . V_188 = V_171 -> V_141 . V_149 ;
V_156 . V_189 = false ;
V_20 = F_40 ( & V_26 -> V_165 , & V_156 ) ;
if ( ! V_20 ) {
V_170 -> V_166 = V_190 ;
F_34 ( V_170 -> V_182 , V_179 ) ;
F_34 ( V_171 -> V_185 , V_180 ) ;
}
return V_20 ;
}
int F_41 ( struct V_25 * V_26 ,
struct V_60 * V_170 ,
struct V_60 * V_171 )
{
int V_20 ;
struct V_172 V_156 ;
struct V_147 V_173 = V_170 -> V_141 ;
struct V_147 V_174 = V_171 -> V_141 ;
int V_175 = V_171 -> V_176 ;
int V_177 = V_170 -> V_178 ;
int V_179 , V_180 ;
F_38 ( V_26 , V_170 , V_171 ) ;
if ( V_170 -> V_166 < V_167 &&
V_171 -> V_166 < V_167 )
return 0 ;
V_179 = F_33 ( V_170 -> V_182 , V_174 , V_177 ) ;
if ( V_179 < 0 )
return - V_150 ;
V_156 . V_183 = V_170 -> V_182 [ V_179 ] . V_184 ;
V_180 = F_33 ( V_171 -> V_185 , V_173 , V_175 ) ;
if ( V_180 < 0 ) {
F_34 ( V_170 -> V_182 , V_179 ) ;
return - V_150 ;
}
V_156 . V_186 = V_171 -> V_185 [ V_180 ] . V_184 ;
F_11 ( V_26 -> V_2 , L_14 ,
V_156 . V_183 , V_156 . V_186 ) ;
V_156 . V_142 = V_170 -> V_141 . V_142 ;
V_156 . V_149 = V_170 -> V_141 . V_149 ;
V_156 . V_187 = V_171 -> V_141 . V_142 ;
V_156 . V_188 = V_171 -> V_141 . V_149 ;
V_156 . V_189 = true ;
V_20 = F_40 ( & V_26 -> V_165 , & V_156 ) ;
if ( ! V_20 ) {
V_170 -> V_166 = V_181 ;
} else {
F_34 ( V_170 -> V_182 , V_179 ) ;
F_34 ( V_171 -> V_185 , V_180 ) ;
}
return V_20 ;
}
static int F_42 ( struct V_25 * V_26 , struct V_191 * V_92 ,
enum V_192 V_158 )
{
F_11 ( V_26 -> V_2 , L_15 , V_157 , V_158 ) ;
return F_43 ( & V_26 -> V_165 , V_92 -> V_160 , V_158 ) ;
}
int F_44 ( struct V_25 * V_26 , struct V_191 * V_92 )
{
int V_20 ;
F_11 ( V_26 -> V_2 , L_16 , V_157 , V_92 -> V_160 ) ;
V_20 = F_45 ( & V_26 -> V_165 , V_92 -> V_193 ,
V_92 -> V_194 , V_92 -> V_160 ) ;
if ( V_20 < 0 ) {
F_9 ( V_26 -> V_2 , L_17 ) ;
return V_20 ;
}
V_92 -> V_158 = V_159 ;
return 0 ;
}
int F_46 ( struct V_25 * V_26 , struct V_191 * V_92 )
{
int V_20 ;
F_11 ( V_26 -> V_2 , L_18 , V_157 , V_92 -> V_160 ) ;
if ( V_92 -> V_158 > V_195 ) {
V_20 = F_42 ( V_26 , V_92 , V_196 ) ;
if ( V_20 < 0 ) {
F_9 ( V_26 -> V_2 , L_19 ) ;
return V_20 ;
}
V_92 -> V_158 = V_197 ;
} else {
if ( V_92 -> V_158 < V_159 )
return 0 ;
V_20 = F_47 ( & V_26 -> V_165 , V_92 -> V_160 ) ;
if ( V_20 < 0 )
F_9 ( V_26 -> V_2 , L_20 ) ;
}
return V_20 ;
}
int F_48 ( struct V_25 * V_26 , struct V_191 * V_92 )
{
int V_20 ;
F_11 ( V_26 -> V_2 , L_18 , V_157 , V_92 -> V_160 ) ;
if ( V_92 -> V_158 < V_159 )
return 0 ;
V_20 = F_42 ( V_26 , V_92 , V_196 ) ;
if ( V_20 < 0 ) {
F_9 ( V_26 -> V_2 , L_21 ) ;
return V_20 ;
}
V_92 -> V_158 = V_197 ;
V_20 = F_42 ( V_26 , V_92 , V_198 ) ;
if ( V_20 < 0 ) {
F_9 ( V_26 -> V_2 , L_22 ) ;
return V_20 ;
}
V_92 -> V_158 = V_195 ;
return 0 ;
}
int F_49 ( struct V_25 * V_26 , struct V_191 * V_92 )
{
int V_20 ;
F_11 ( V_26 -> V_2 , L_23 , V_157 , V_92 -> V_160 ) ;
if ( V_92 -> V_158 < V_197 )
return 0 ;
V_20 = F_42 ( V_26 , V_92 , V_196 ) ;
if ( V_20 < 0 ) {
F_11 ( V_26 -> V_2 , L_24 ) ;
return V_20 ;
}
V_92 -> V_158 = V_159 ;
return 0 ;
}
