static int F_1 ( struct V_1 * V_2 )
{
if ( F_2 ( V_2 -> V_3 != V_4 ) )
return 0 ;
return F_3 ( V_2 , V_5 , 0 ,
sizeof( struct V_6 ) ,
& V_7 ) ;
}
static enum V_8
F_4 ( struct V_1 * V_2 , const struct V_9 * V_10 )
{
struct V_11 * V_12 ;
enum V_8 V_13 ;
T_1 V_14 ;
F_5 () ;
V_12 = F_6 ( V_10 -> V_12 ) ;
if ( ! V_12 ||
V_12 -> V_15 . V_16 -> V_17 != V_18 ) {
F_7 () ;
return V_19 ;
}
V_13 = V_20 ;
if ( V_2 -> V_21 -> V_22 ) {
F_7 () ;
return V_13 ;
}
V_14 = * ( ( T_1 * ) V_12 -> V_23 ) ;
if ( V_2 -> V_24 . V_25 == V_14 )
V_13 = F_8 ( V_2 -> V_26 . V_27 ) ;
else if ( V_2 -> V_24 . V_28 == V_14 )
V_13 = F_8 ( V_2 -> V_26 . V_29 ) ;
F_7 () ;
return V_13 ;
}
int F_9 ( struct V_1 * V_2 )
{
struct V_30 * V_31 ;
struct V_32 V_33 = {
. V_34 = V_35 ,
. V_36 = { sizeof( * V_31 ) , } ,
. V_37 = { V_38 , } ,
} ;
int V_13 ;
T_2 V_39 ;
V_13 = F_1 ( V_2 ) ;
if ( V_13 )
return V_13 ;
V_31 = F_10 ( sizeof( * V_31 ) , V_40 ) ;
if ( ! V_31 )
return - V_41 ;
V_33 . V_42 [ 0 ] = V_31 ;
F_11 ( & V_2 -> V_43 ) ;
if ( F_2 ( V_2 -> V_3 != V_4 ) ) {
switch ( V_2 -> V_3 ) {
case V_44 :
V_39 = V_45 ;
break;
case V_46 :
V_39 = V_47 ;
break;
case V_48 :
V_39 = V_49 ;
break;
default:
F_12 ( 1 ) ;
V_39 = 0 ;
}
V_31 -> V_39 = F_13 ( V_39 ) ;
V_31 -> V_50 = F_13 ( V_51 ) ;
goto V_52;
}
V_31 -> V_53 = 5 ;
V_31 -> V_54 =
V_55 ;
V_31 -> V_56 = V_57 . V_58 ;
V_31 -> V_59 = 15 ;
V_31 -> V_60 = 15 ;
V_31 -> V_61 = V_19 ;
V_31 -> V_62 = V_19 ;
V_39 = V_57 . V_63 ?
V_64 : V_65 ;
V_31 -> V_39 = F_13 ( V_39 ) ;
V_31 -> V_50 = F_13 ( V_51 |
V_66 |
V_67 |
V_68 |
V_69 |
V_70 |
V_71 |
V_72 |
V_73 |
V_74 |
V_75 |
V_76 |
V_77 |
V_78 |
V_79 |
V_80 |
V_81 ) ;
if ( V_82 )
V_31 -> V_39 |= F_13 ( V_83 ) ;
if ( F_14 ( V_2 ) ) {
V_31 -> V_50 |= F_13 ( V_84 |
V_85 ) ;
V_31 -> V_39 |= F_13 ( V_86 ) ;
}
if ( V_87 ) {
V_31 -> V_39 |= F_13 ( V_88 ) ;
V_31 -> V_50 |= F_13 ( V_89 ) ;
}
if ( V_90 )
V_31 -> V_39 |= F_13 ( V_91 ) ;
if ( F_15 ( V_2 ) )
V_31 -> V_39 |= F_13 ( V_92 ) ;
if ( V_2 -> V_21 -> V_22 )
memcpy ( & V_31 -> V_93 , V_94 ,
sizeof( V_94 ) ) ;
else
memcpy ( & V_31 -> V_93 , V_95 ,
sizeof( V_95 ) ) ;
memcpy ( V_31 -> V_96 , V_97 [ 0 ] . V_98 ,
sizeof( V_31 -> V_96 ) ) ;
memcpy ( V_31 -> V_99 , V_97 [ 0 ] . V_98 ,
sizeof( V_31 -> V_99 ) ) ;
memcpy ( & V_31 -> V_100 , V_101 ,
sizeof( V_101 ) ) ;
V_31 -> V_102 [ 0 ] = F_13 ( V_103 ) ;
V_31 -> V_102 [ 1 ] = F_13 ( V_104 ) ;
V_52:
memset ( & V_2 -> V_26 , 0 , sizeof( V_2 -> V_26 ) ) ;
memset ( & V_2 -> V_24 , 0 , sizeof( V_2 -> V_24 ) ) ;
V_13 = F_16 ( V_2 , & V_33 ) ;
F_17 ( V_31 ) ;
return V_13 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_105 * V_106 = & V_2 -> V_26 ;
T_2 V_107 = F_8 ( V_106 -> V_27 ) ;
T_2 V_108 = F_8 ( V_106 -> V_109 ) ;
struct V_30 * V_31 ;
T_3 V_110 , V_111 ;
struct V_32 V_33 = {
. V_34 = V_35 ,
. V_42 [ 0 ] = & V_31 ,
. V_36 = { sizeof( * V_31 ) , } ,
. V_37 = { V_38 , } ,
} ;
int V_13 = 0 ;
F_11 ( & V_2 -> V_43 ) ;
V_110 = V_112 [ V_108 ] [ V_107 ] ;
V_111 = V_113 [ V_108 ] [ V_107 ] ;
if ( V_2 -> V_114 [ 0 ] == V_110 &&
V_2 -> V_115 [ 0 ] == V_111 )
return 0 ;
V_2 -> V_114 [ 0 ] = V_110 ;
V_2 -> V_115 [ 0 ] = V_111 ;
V_31 = F_10 ( sizeof( * V_31 ) , V_40 ) ;
if ( ! V_31 )
return - V_41 ;
V_33 . V_42 [ 0 ] = V_31 ;
V_31 -> V_39 = F_13 ( V_64 ) ;
V_31 -> V_116 = F_13 ( V_117 [ V_110 ] ) ;
V_31 -> V_118 = F_13 ( V_117 [ V_111 ] ) ;
V_31 -> V_50 |= F_13 ( V_51 |
V_69 |
V_70 ) ;
V_13 = F_16 ( V_2 , & V_33 ) ;
F_17 ( V_31 ) ;
return V_13 ;
}
static int F_19 ( struct V_1 * V_2 , T_3 V_119 ,
bool V_120 )
{
struct V_30 * V_31 ;
struct V_32 V_33 = {
. V_34 = V_35 ,
. V_36 = { sizeof( * V_31 ) , } ,
. V_37 = { V_121 , } ,
. V_39 = V_122 ,
} ;
struct V_123 * V_124 ;
int V_13 ;
V_124 = F_20 ( V_2 , V_119 ) ;
if ( ! V_124 )
return 0 ;
if ( V_124 -> V_125 == V_120 )
return 0 ;
V_31 = F_10 ( sizeof( * V_31 ) , V_126 ) ;
if ( ! V_31 )
return - V_41 ;
V_33 . V_42 [ 0 ] = V_31 ;
V_31 -> V_39 = F_13 ( V_64 ) ;
V_31 -> V_50 =
F_13 ( V_51 | V_71 ) ;
V_31 -> V_127 = V_119 ;
if ( V_120 )
V_31 -> V_127 |= V_128 ;
F_21 ( V_2 , L_1 ,
V_120 ? L_2 : L_3 , V_119 ) ;
V_124 -> V_125 = V_120 ;
V_13 = F_16 ( V_2 , & V_33 ) ;
F_17 ( V_31 ) ;
return V_13 ;
}
static inline
void F_22 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
bool V_120 , int V_129 )
{
struct V_130 * V_131 = F_23 ( V_10 ) ;
V_131 -> V_132 . V_133 = V_129 ;
V_131 -> V_132 . V_134 =
V_120 ? - V_135 : 0 ;
V_131 -> V_132 . V_136 =
V_120 ? - V_137 : 0 ;
}
static void F_24 ( void * V_138 , T_3 * V_139 ,
struct V_9 * V_10 )
{
struct V_130 * V_131 = F_23 ( V_10 ) ;
struct V_140 * V_42 = V_138 ;
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_11 * V_12 ;
enum V_141 V_142 ;
T_2 V_109 ;
int V_143 ;
F_11 ( & V_2 -> V_43 ) ;
switch ( V_10 -> type ) {
case V_144 :
V_142 = V_145 ;
break;
case V_146 :
if ( ! V_131 -> V_147 )
return;
break;
default:
return;
}
V_12 = F_6 ( V_10 -> V_12 ) ;
if ( ( ! V_12 ||
V_12 -> V_15 . V_16 -> V_17 != V_18 ) ) {
if ( V_10 -> type == V_144 ) {
F_25 ( V_2 , V_10 , V_148 ,
V_142 ) ;
F_19 ( V_2 , V_131 -> V_149 ,
false ) ;
F_22 ( V_2 , V_10 , false , 0 ) ;
}
return;
}
V_109 = F_8 ( V_42 -> V_106 -> V_109 ) ;
if ( V_109 >= V_150 )
V_142 = V_151 ;
else if ( V_109 >= V_152 )
V_142 = V_10 -> type == V_146 ?
V_153 :
V_154 ;
if ( ! V_10 -> V_155 . V_156 )
V_142 = V_145 ;
if ( V_131 -> V_157 &&
V_42 -> V_106 -> V_158 & F_26 ( V_131 -> V_157 -> V_34 ) )
V_142 = V_145 ;
F_21 ( V_42 -> V_2 ,
L_4 ,
V_131 -> V_34 , V_42 -> V_106 -> V_159 , V_109 ,
V_142 ) ;
if ( V_10 -> type == V_144 )
F_25 ( V_2 , V_10 , V_148 ,
V_142 ) ;
if ( F_27 ( V_131 ) ) {
V_42 -> V_160 = true ;
V_42 -> V_161 = V_42 -> V_162 ;
V_42 -> V_162 = V_12 ;
}
if ( V_10 -> type == V_146 ) {
if ( ! V_131 -> V_147 )
return;
if ( V_12 == V_42 -> V_162 )
return;
if ( ! V_42 -> V_160 ) {
V_42 -> V_161 = V_42 -> V_162 ;
V_42 -> V_162 = V_12 ;
} else {
V_42 -> V_161 = V_12 ;
}
return;
}
if ( ! V_42 -> V_162 || V_42 -> V_162 == V_12 )
V_42 -> V_162 = V_12 ;
else if ( ! V_42 -> V_161 )
V_42 -> V_161 = V_12 ;
if ( F_4 ( V_2 , V_10 ) == V_163 ||
V_2 -> V_21 -> V_22 || ! V_10 -> V_155 . V_156 ||
! V_42 -> V_106 -> V_159 ) {
F_19 ( V_2 , V_131 -> V_149 , false ) ;
F_22 ( V_2 , V_10 , false , 0 ) ;
return;
}
V_143 = V_131 -> V_132 . V_164 ;
if ( ! V_143 )
V_143 = - 100 ;
if ( V_143 > - V_135 ) {
if ( F_19 ( V_2 , V_131 -> V_149 , true ) )
F_28 ( V_2 , L_5 ) ;
} else if ( V_143 < - V_137 ) {
if ( F_19 ( V_2 , V_131 -> V_149 , false ) )
F_28 ( V_2 , L_5 ) ;
}
F_22 ( V_2 , V_10 , true , V_143 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_140 V_42 = {
. V_2 = V_2 ,
. V_106 = & V_2 -> V_26 ,
} ;
struct V_165 V_33 = {} ;
T_3 V_166 ;
if ( F_2 ( V_2 -> V_3 != V_4 ) )
return;
F_5 () ;
F_30 (
V_2 -> V_167 , V_168 ,
F_24 , & V_42 ) ;
if ( V_42 . V_162 ) {
struct V_11 * V_16 = V_42 . V_162 ;
if ( F_12 ( ! V_16 -> V_15 . V_16 ) ) {
F_7 () ;
return;
}
if ( V_16 -> V_15 . V_169 < V_170 ) {
V_166 = 0 ;
V_33 . V_171 = 0 ;
} else {
V_33 . V_171 = 1 ;
if ( V_16 -> V_15 . V_172 >
V_16 -> V_15 . V_16 -> V_173 )
V_166 = 2 ;
else
V_166 = 1 ;
}
V_33 . V_174 =
V_175 [ V_16 -> V_15 . V_16 -> V_176 ] [ V_166 ] ;
V_33 . V_25 = * ( ( T_1 * ) V_42 . V_162 -> V_23 ) ;
}
if ( V_42 . V_161 ) {
struct V_11 * V_16 = V_42 . V_161 ;
if ( F_12 ( ! V_42 . V_161 -> V_15 . V_16 ) ) {
F_7 () ;
return;
}
if ( V_16 -> V_15 . V_169 < V_170 ) {
V_166 = 0 ;
V_33 . V_177 = 0 ;
} else {
V_33 . V_177 = 1 ;
if ( V_16 -> V_15 . V_172 >
V_16 -> V_15 . V_16 -> V_173 )
V_166 = 2 ;
else
V_166 = 1 ;
}
V_33 . V_178 =
V_175 [ V_16 -> V_15 . V_16 -> V_176 ] [ V_166 ] ;
V_33 . V_28 = * ( ( T_1 * ) V_42 . V_161 -> V_23 ) ;
}
F_7 () ;
if ( memcmp ( & V_33 , & V_2 -> V_24 , sizeof( V_33 ) ) ) {
if ( F_3 ( V_2 , V_179 , 0 ,
sizeof( V_33 ) , & V_33 ) )
F_28 ( V_2 , L_6 ) ;
memcpy ( & V_2 -> V_24 , & V_33 , sizeof( V_33 ) ) ;
}
if ( F_18 ( V_2 ) )
F_28 ( V_2 , L_7 ) ;
}
void F_31 ( struct V_1 * V_2 ,
struct V_180 * V_181 )
{
struct V_182 * V_183 = F_32 ( V_181 ) ;
struct V_105 * V_106 = ( void * ) V_183 -> V_42 ;
F_21 ( V_2 , L_8 ) ;
F_21 ( V_2 , L_9 ,
V_106 -> V_159 ? L_10 : L_11 ) ;
F_21 ( V_2 , L_12 , V_106 -> V_184 ) ;
F_21 ( V_2 , L_13 , V_106 -> V_185 ) ;
F_21 ( V_2 , L_14 ,
F_8 ( V_106 -> V_27 ) ) ;
F_21 ( V_2 , L_15 ,
F_8 ( V_106 -> V_29 ) ) ;
F_21 ( V_2 , L_16 ,
F_8 ( V_106 -> V_109 ) ) ;
F_21 ( V_2 , L_17 ,
V_106 -> V_186 ) ;
memcpy ( & V_2 -> V_26 , V_106 , sizeof( V_2 -> V_26 ) ) ;
F_29 ( V_2 ) ;
}
static void F_33 ( void * V_138 , T_3 * V_139 ,
struct V_9 * V_10 )
{
struct V_130 * V_131 = F_23 ( V_10 ) ;
struct V_140 * V_42 = V_138 ;
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_187 * V_188 ;
struct V_123 * V_124 ;
struct V_11 * V_12 ;
F_5 () ;
V_12 = F_6 ( V_10 -> V_12 ) ;
if ( ! V_12 ||
V_12 -> V_15 . V_16 -> V_17 != V_18 ) {
F_7 () ;
return;
}
F_7 () ;
if ( V_10 -> type != V_144 ||
V_131 -> V_149 == V_189 )
return;
V_188 = F_34 ( V_2 -> V_190 [ V_131 -> V_149 ] ,
F_35 ( & V_2 -> V_43 ) ) ;
if ( F_36 ( V_188 ) )
return;
V_124 = F_37 ( V_188 ) ;
}
void F_38 ( struct V_1 * V_2 , struct V_9 * V_10 ,
enum V_191 V_192 )
{
struct V_130 * V_131 = F_23 ( V_10 ) ;
struct V_140 V_42 = {
. V_2 = V_2 ,
} ;
int V_13 ;
F_11 ( & V_2 -> V_43 ) ;
if ( F_2 ( V_2 -> V_3 != V_4 ) )
return;
if ( V_131 -> V_149 == V_189 )
return;
if ( ! V_2 -> V_26 . V_159 )
return;
F_21 ( V_2 , L_18 , V_10 -> V_155 . V_193 ,
V_192 == V_194 ? L_19 : L_20 ) ;
if ( V_192 == V_195 || V_2 -> V_21 -> V_22 ||
F_4 ( V_2 , V_10 ) == V_163 )
V_13 = F_19 ( V_2 , V_131 -> V_149 ,
false ) ;
else
V_13 = F_19 ( V_2 , V_131 -> V_149 , true ) ;
if ( V_13 )
F_28 ( V_2 , L_21 ) ;
F_30 (
V_2 -> V_167 , V_168 ,
F_33 , & V_42 ) ;
if ( F_18 ( V_2 ) )
F_28 ( V_2 , L_7 ) ;
}
T_1 F_39 ( struct V_1 * V_2 ,
struct V_187 * V_188 )
{
struct V_123 * V_124 = F_37 ( V_188 ) ;
enum V_8 V_196 ;
if ( F_8 ( V_2 -> V_26 . V_109 ) <
V_150 )
return V_197 ;
if ( V_2 -> V_26 . V_198 )
return V_197 ;
V_196 = F_4 ( V_2 , V_124 -> V_10 ) ;
if ( V_196 == V_163 || V_196 == V_19 )
return V_197 ;
return V_199 ;
}
bool F_40 ( struct V_1 * V_2 ,
struct V_187 * V_188 )
{
struct V_123 * V_124 = F_37 ( V_188 ) ;
enum V_8 V_196 ;
if ( V_2 -> V_26 . V_198 )
return true ;
if ( F_8 ( V_2 -> V_26 . V_109 ) <
V_150 )
return true ;
V_196 = F_4 ( V_2 , V_124 -> V_10 ) ;
return V_196 != V_163 ;
}
bool F_41 ( struct V_1 * V_2 )
{
T_2 V_108 = F_8 ( V_2 -> V_26 . V_109 ) ;
return V_108 < V_150 ;
}
bool F_42 ( struct V_1 * V_2 ,
enum V_200 V_17 )
{
T_2 V_201 =
F_8 ( V_2 -> V_26 . V_109 ) ;
if ( V_17 != V_18 )
return false ;
return V_201 >= V_152 ;
}
void F_43 ( struct V_1 * V_2 )
{
F_29 ( V_2 ) ;
}
void F_44 ( struct V_1 * V_2 ,
struct V_180 * V_181 )
{
struct V_182 * V_183 = F_32 ( V_181 ) ;
T_2 V_202 = F_45 ( ( void * ) V_183 -> V_42 ) ;
T_3 T_4 V_203 , V_204 ;
T_3 V_205 ;
struct V_30 * V_31 ;
struct V_32 V_33 = {
. V_34 = V_35 ,
. V_36 = { sizeof( * V_31 ) , } ,
. V_37 = { V_38 , } ,
} ;
if ( ! F_14 ( V_2 ) )
return;
F_11 ( & V_2 -> V_43 ) ;
if ( F_2 ( V_2 -> V_3 != V_4 ) )
return;
if ( V_202 == V_2 -> V_206 )
return;
for ( V_205 = 0 ; V_205 < F_46 ( V_97 ) - 1 ; V_205 ++ )
if ( V_202 < V_97 [ V_205 + 1 ] . V_207 )
break;
V_203 = V_97 [ V_205 ] . V_207 ;
if ( V_205 < F_46 ( V_97 ) - 1 )
V_204 = V_97 [ V_205 + 1 ] . V_207 ;
else
V_204 = V_97 [ V_205 ] . V_207 ;
F_21 ( V_2 , L_22 ,
V_202 , V_203 , V_204 , V_205 ) ;
V_2 -> V_206 = V_202 ;
if ( V_2 -> V_208 == V_205 )
return;
V_2 -> V_208 = V_205 ;
V_31 = F_10 ( sizeof( * V_31 ) , V_40 ) ;
if ( ! V_31 )
return;
V_33 . V_42 [ 0 ] = V_31 ;
V_31 -> V_39 = F_13 ( V_64 ) ;
V_31 -> V_50 |= F_13 ( V_51 |
V_84 |
V_85 ) ;
memcpy ( V_31 -> V_96 , V_97 [ V_205 ] . V_98 ,
sizeof( V_31 -> V_96 ) ) ;
memcpy ( V_31 -> V_99 , V_97 [ V_205 ] . V_98 ,
sizeof( V_31 -> V_99 ) ) ;
if ( F_16 ( V_2 , & V_33 ) )
F_28 ( V_2 , L_23 ) ;
F_17 ( V_31 ) ;
}
