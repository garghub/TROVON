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
if ( V_84 ) {
V_31 -> V_50 |= F_13 ( V_85 |
V_86 ) ;
V_31 -> V_39 |= F_13 ( V_87 ) ;
}
if ( V_88 ) {
V_31 -> V_39 |= F_13 ( V_89 ) ;
V_31 -> V_50 |= F_13 ( V_90 ) ;
}
if ( V_91 )
V_31 -> V_39 |= F_13 ( V_92 ) ;
if ( V_93 )
V_31 -> V_39 |= F_13 ( V_94 ) ;
if ( V_2 -> V_21 -> V_22 )
memcpy ( & V_31 -> V_95 , V_96 ,
sizeof( V_96 ) ) ;
else
memcpy ( & V_31 -> V_95 , V_97 ,
sizeof( V_97 ) ) ;
memcpy ( V_31 -> V_98 , V_99 [ 0 ] . V_100 ,
sizeof( V_31 -> V_98 ) ) ;
memcpy ( V_31 -> V_101 , V_99 [ 0 ] . V_100 ,
sizeof( V_31 -> V_101 ) ) ;
memcpy ( & V_31 -> V_102 , V_103 ,
sizeof( V_103 ) ) ;
V_31 -> V_104 [ 0 ] = F_13 ( V_105 ) ;
V_31 -> V_104 [ 1 ] = F_13 ( V_106 ) ;
V_52:
memset ( & V_2 -> V_26 , 0 , sizeof( V_2 -> V_26 ) ) ;
memset ( & V_2 -> V_24 , 0 , sizeof( V_2 -> V_24 ) ) ;
V_13 = F_14 ( V_2 , & V_33 ) ;
F_15 ( V_31 ) ;
return V_13 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_107 * V_108 = & V_2 -> V_26 ;
T_2 V_109 = F_8 ( V_108 -> V_27 ) ;
T_2 V_110 = F_8 ( V_108 -> V_111 ) ;
struct V_30 * V_31 ;
T_3 V_112 , V_113 ;
struct V_32 V_33 = {
. V_34 = V_35 ,
. V_42 [ 0 ] = & V_31 ,
. V_36 = { sizeof( * V_31 ) , } ,
. V_37 = { V_38 , } ,
} ;
int V_13 = 0 ;
F_11 ( & V_2 -> V_43 ) ;
V_112 = V_114 [ V_110 ] [ V_109 ] ;
V_113 = V_115 [ V_110 ] [ V_109 ] ;
if ( V_2 -> V_116 [ 0 ] == V_112 &&
V_2 -> V_117 [ 0 ] == V_113 )
return 0 ;
V_2 -> V_116 [ 0 ] = V_112 ;
V_2 -> V_117 [ 0 ] = V_113 ;
V_31 = F_10 ( sizeof( * V_31 ) , V_40 ) ;
if ( ! V_31 )
return - V_41 ;
V_33 . V_42 [ 0 ] = V_31 ;
V_31 -> V_39 = F_13 ( V_64 ) ;
V_31 -> V_118 = F_13 ( V_119 [ V_112 ] ) ;
V_31 -> V_120 = F_13 ( V_119 [ V_113 ] ) ;
V_31 -> V_50 |= F_13 ( V_51 |
V_69 |
V_70 ) ;
V_13 = F_14 ( V_2 , & V_33 ) ;
F_15 ( V_31 ) ;
return V_13 ;
}
static int F_17 ( struct V_1 * V_2 , T_3 V_121 ,
bool V_122 )
{
struct V_30 * V_31 ;
struct V_32 V_33 = {
. V_34 = V_35 ,
. V_36 = { sizeof( * V_31 ) , } ,
. V_37 = { V_38 , } ,
. V_39 = V_123 ,
} ;
struct V_124 * V_125 ;
int V_13 ;
V_125 = F_18 ( V_2 , V_121 ) ;
if ( ! V_125 )
return 0 ;
if ( V_125 -> V_126 == V_122 )
return 0 ;
V_31 = F_10 ( sizeof( * V_31 ) , V_127 ) ;
if ( ! V_31 )
return - V_41 ;
V_33 . V_42 [ 0 ] = V_31 ;
V_31 -> V_39 = F_13 ( V_64 ) ;
V_31 -> V_50 =
F_13 ( V_51 | V_71 ) ;
V_31 -> V_128 = V_121 ;
if ( V_122 )
V_31 -> V_128 |= V_129 ;
F_19 ( V_2 , L_1 ,
V_122 ? L_2 : L_3 , V_121 ) ;
V_125 -> V_126 = V_122 ;
V_13 = F_14 ( V_2 , & V_33 ) ;
F_15 ( V_31 ) ;
return V_13 ;
}
static inline
void F_20 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
bool V_122 , int V_130 )
{
struct V_131 * V_132 = F_21 ( V_10 ) ;
V_132 -> V_133 . V_134 = V_130 ;
V_132 -> V_133 . V_135 =
V_122 ? - V_136 : 0 ;
V_132 -> V_133 . V_137 =
V_122 ? - V_138 : 0 ;
}
static void F_22 ( void * V_139 , T_3 * V_140 ,
struct V_9 * V_10 )
{
struct V_131 * V_132 = F_21 ( V_10 ) ;
struct V_141 * V_42 = V_139 ;
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_11 * V_12 ;
enum V_142 V_143 ;
T_2 V_111 ;
int V_144 ;
F_11 ( & V_2 -> V_43 ) ;
switch ( V_10 -> type ) {
case V_145 :
V_143 = V_146 ;
break;
case V_147 :
if ( ! V_132 -> V_148 )
return;
break;
default:
return;
}
V_12 = F_6 ( V_10 -> V_12 ) ;
if ( ( ! V_12 ||
V_12 -> V_15 . V_16 -> V_17 != V_18 ) ) {
if ( V_10 -> type == V_145 ) {
F_23 ( V_2 , V_10 , V_149 ,
V_143 ) ;
F_17 ( V_2 , V_132 -> V_150 ,
false ) ;
F_20 ( V_2 , V_10 , false , 0 ) ;
}
return;
}
V_111 = F_8 ( V_42 -> V_108 -> V_111 ) ;
if ( V_111 >= V_151 )
V_143 = V_152 ;
else if ( V_111 >= V_153 )
V_143 = V_10 -> type == V_147 ?
V_154 :
V_155 ;
if ( ! V_10 -> V_156 . V_157 )
V_143 = V_146 ;
if ( V_132 -> V_158 &&
V_42 -> V_108 -> V_159 & F_24 ( V_132 -> V_158 -> V_34 ) )
V_143 = V_146 ;
F_19 ( V_42 -> V_2 ,
L_4 ,
V_132 -> V_34 , V_42 -> V_108 -> V_160 , V_111 ,
V_143 ) ;
if ( V_10 -> type == V_145 )
F_23 ( V_2 , V_10 , V_149 ,
V_143 ) ;
if ( F_25 ( V_132 ) ) {
V_42 -> V_161 = true ;
V_42 -> V_162 = V_42 -> V_163 ;
V_42 -> V_163 = V_12 ;
}
if ( V_10 -> type == V_147 ) {
if ( ! V_132 -> V_148 )
return;
if ( V_12 == V_42 -> V_163 )
return;
if ( ! V_42 -> V_161 ) {
V_42 -> V_162 = V_42 -> V_163 ;
V_42 -> V_163 = V_12 ;
} else {
V_42 -> V_162 = V_12 ;
}
return;
}
if ( ! V_42 -> V_163 || V_42 -> V_163 == V_12 )
V_42 -> V_163 = V_12 ;
else if ( ! V_42 -> V_162 )
V_42 -> V_162 = V_12 ;
if ( F_4 ( V_2 , V_10 ) == V_164 ||
V_2 -> V_21 -> V_22 || ! V_10 -> V_156 . V_157 ||
! V_42 -> V_108 -> V_160 ) {
F_17 ( V_2 , V_132 -> V_150 , false ) ;
F_20 ( V_2 , V_10 , false , 0 ) ;
return;
}
V_144 = V_132 -> V_133 . V_165 ;
if ( ! V_144 )
V_144 = - 100 ;
if ( V_144 > - V_136 ) {
if ( F_17 ( V_2 , V_132 -> V_150 , true ) )
F_26 ( V_2 , L_5 ) ;
} else if ( V_144 < - V_138 ) {
if ( F_17 ( V_2 , V_132 -> V_150 , false ) )
F_26 ( V_2 , L_5 ) ;
}
F_20 ( V_2 , V_10 , true , V_144 ) ;
}
static void F_27 ( struct V_1 * V_2 )
{
struct V_141 V_42 = {
. V_2 = V_2 ,
. V_108 = & V_2 -> V_26 ,
} ;
struct V_166 V_33 = {} ;
T_3 V_167 ;
if ( F_2 ( V_2 -> V_3 != V_4 ) )
return;
F_5 () ;
F_28 (
V_2 -> V_168 , V_169 ,
F_22 , & V_42 ) ;
if ( V_42 . V_163 ) {
struct V_11 * V_16 = V_42 . V_163 ;
if ( F_12 ( ! V_16 -> V_15 . V_16 ) ) {
F_7 () ;
return;
}
if ( V_16 -> V_15 . V_170 < V_171 ) {
V_167 = 0 ;
V_33 . V_172 = 0 ;
} else {
V_33 . V_172 = 1 ;
if ( V_16 -> V_15 . V_173 >
V_16 -> V_15 . V_16 -> V_174 )
V_167 = 2 ;
else
V_167 = 1 ;
}
V_33 . V_175 =
V_176 [ V_16 -> V_15 . V_16 -> V_177 ] [ V_167 ] ;
V_33 . V_25 = * ( ( T_1 * ) V_42 . V_163 -> V_23 ) ;
}
if ( V_42 . V_162 ) {
struct V_11 * V_16 = V_42 . V_162 ;
if ( F_12 ( ! V_42 . V_162 -> V_15 . V_16 ) ) {
F_7 () ;
return;
}
if ( V_16 -> V_15 . V_170 < V_171 ) {
V_167 = 0 ;
V_33 . V_178 = 0 ;
} else {
V_33 . V_178 = 1 ;
if ( V_16 -> V_15 . V_173 >
V_16 -> V_15 . V_16 -> V_174 )
V_167 = 2 ;
else
V_167 = 1 ;
}
V_33 . V_179 =
V_176 [ V_16 -> V_15 . V_16 -> V_177 ] [ V_167 ] ;
V_33 . V_28 = * ( ( T_1 * ) V_42 . V_162 -> V_23 ) ;
}
F_7 () ;
if ( memcmp ( & V_33 , & V_2 -> V_24 , sizeof( V_33 ) ) ) {
if ( F_3 ( V_2 , V_180 , 0 ,
sizeof( V_33 ) , & V_33 ) )
F_26 ( V_2 , L_6 ) ;
memcpy ( & V_2 -> V_24 , & V_33 , sizeof( V_33 ) ) ;
}
if ( F_16 ( V_2 ) )
F_26 ( V_2 , L_7 ) ;
}
int F_29 ( struct V_1 * V_2 ,
struct V_181 * V_182 ,
struct V_183 * V_184 )
{
struct V_185 * V_186 = F_30 ( V_182 ) ;
struct V_107 * V_108 = ( void * ) V_186 -> V_42 ;
F_19 ( V_2 , L_8 ) ;
F_19 ( V_2 , L_9 ,
V_108 -> V_160 ? L_10 : L_11 ) ;
F_19 ( V_2 , L_12 , V_108 -> V_187 ) ;
F_19 ( V_2 , L_13 , V_108 -> V_188 ) ;
F_19 ( V_2 , L_14 ,
F_8 ( V_108 -> V_27 ) ) ;
F_19 ( V_2 , L_15 ,
F_8 ( V_108 -> V_29 ) ) ;
F_19 ( V_2 , L_16 ,
F_8 ( V_108 -> V_111 ) ) ;
F_19 ( V_2 , L_17 ,
V_108 -> V_189 ) ;
memcpy ( & V_2 -> V_26 , V_108 , sizeof( V_2 -> V_26 ) ) ;
F_27 ( V_2 ) ;
return 0 ;
}
static void F_31 ( void * V_139 , T_3 * V_140 ,
struct V_9 * V_10 )
{
struct V_131 * V_132 = F_21 ( V_10 ) ;
struct V_141 * V_42 = V_139 ;
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_190 * V_191 ;
struct V_124 * V_125 ;
struct V_11 * V_12 ;
F_5 () ;
V_12 = F_6 ( V_10 -> V_12 ) ;
if ( ! V_12 ||
V_12 -> V_15 . V_16 -> V_17 != V_18 ) {
F_7 () ;
return;
}
F_7 () ;
if ( V_10 -> type != V_145 ||
V_132 -> V_150 == V_192 )
return;
V_191 = F_32 ( V_2 -> V_193 [ V_132 -> V_150 ] ,
F_33 ( & V_2 -> V_43 ) ) ;
if ( F_34 ( V_191 ) )
return;
V_125 = F_35 ( V_191 ) ;
}
void F_36 ( struct V_1 * V_2 , struct V_9 * V_10 ,
enum V_194 V_195 )
{
struct V_131 * V_132 = F_21 ( V_10 ) ;
struct V_141 V_42 = {
. V_2 = V_2 ,
} ;
int V_13 ;
F_11 ( & V_2 -> V_43 ) ;
if ( F_2 ( V_2 -> V_3 != V_4 ) )
return;
if ( V_132 -> V_150 == V_192 )
return;
if ( ! V_2 -> V_26 . V_160 )
return;
F_19 ( V_2 , L_18 , V_10 -> V_156 . V_196 ,
V_195 == V_197 ? L_19 : L_20 ) ;
if ( V_195 == V_198 || V_2 -> V_21 -> V_22 ||
F_4 ( V_2 , V_10 ) == V_164 )
V_13 = F_17 ( V_2 , V_132 -> V_150 ,
false ) ;
else
V_13 = F_17 ( V_2 , V_132 -> V_150 , true ) ;
if ( V_13 )
F_26 ( V_2 , L_21 ) ;
F_28 (
V_2 -> V_168 , V_169 ,
F_31 , & V_42 ) ;
if ( F_16 ( V_2 ) )
F_26 ( V_2 , L_7 ) ;
}
T_1 F_37 ( struct V_1 * V_2 ,
struct V_190 * V_191 )
{
struct V_124 * V_125 = F_35 ( V_191 ) ;
enum V_8 V_199 ;
if ( F_8 ( V_2 -> V_26 . V_111 ) <
V_151 )
return V_200 ;
if ( V_2 -> V_26 . V_201 )
return V_200 ;
V_199 = F_4 ( V_2 , V_125 -> V_10 ) ;
if ( V_199 == V_164 || V_199 == V_19 )
return V_200 ;
return V_202 ;
}
bool F_38 ( struct V_1 * V_2 ,
struct V_190 * V_191 )
{
struct V_124 * V_125 = F_35 ( V_191 ) ;
enum V_8 V_199 ;
if ( V_2 -> V_26 . V_201 )
return true ;
if ( F_8 ( V_2 -> V_26 . V_111 ) <
V_151 )
return true ;
V_199 = F_4 ( V_2 , V_125 -> V_10 ) ;
return V_199 != V_164 ;
}
bool F_39 ( struct V_1 * V_2 , T_3 V_203 )
{
T_2 V_110 = F_8 ( V_2 -> V_26 . V_111 ) ;
return V_110 < V_151 ;
}
bool F_40 ( struct V_1 * V_2 )
{
T_2 V_110 = F_8 ( V_2 -> V_26 . V_111 ) ;
return V_110 == V_204 ;
}
bool F_41 ( struct V_1 * V_2 ,
enum V_205 V_17 )
{
T_2 V_206 =
F_8 ( V_2 -> V_26 . V_111 ) ;
if ( V_17 != V_18 )
return false ;
return V_206 >= V_153 ;
}
void F_42 ( struct V_1 * V_2 )
{
F_27 ( V_2 ) ;
}
int F_43 ( struct V_1 * V_2 ,
struct V_181 * V_182 ,
struct V_183 * V_184 )
{
struct V_185 * V_186 = F_30 ( V_182 ) ;
T_2 V_207 = F_44 ( ( void * ) V_186 -> V_42 ) ;
T_3 T_4 V_208 , V_209 ;
int V_13 ;
T_3 V_210 ;
struct V_30 * V_31 ;
struct V_32 V_33 = {
. V_34 = V_35 ,
. V_36 = { sizeof( * V_31 ) , } ,
. V_37 = { V_38 , } ,
} ;
if ( ! V_84 )
return 0 ;
F_11 ( & V_2 -> V_43 ) ;
if ( F_2 ( V_2 -> V_3 != V_4 ) )
return 0 ;
if ( V_207 == V_2 -> V_211 )
return 0 ;
for ( V_210 = 0 ; V_210 < F_45 ( V_99 ) - 1 ; V_210 ++ )
if ( V_207 < V_99 [ V_210 + 1 ] . V_212 )
break;
V_208 = V_99 [ V_210 ] . V_212 ;
if ( V_210 < F_45 ( V_99 ) - 1 )
V_209 = V_99 [ V_210 + 1 ] . V_212 ;
else
V_209 = V_99 [ V_210 ] . V_212 ;
F_19 ( V_2 , L_22 ,
V_207 , V_208 , V_209 , V_210 ) ;
V_2 -> V_211 = V_207 ;
if ( V_2 -> V_213 == V_210 )
return 0 ;
V_2 -> V_213 = V_210 ;
V_31 = F_10 ( sizeof( * V_31 ) , V_40 ) ;
if ( ! V_31 )
return 0 ;
V_33 . V_42 [ 0 ] = V_31 ;
V_31 -> V_39 = F_13 ( V_64 ) ;
V_31 -> V_50 |= F_13 ( V_51 |
V_85 |
V_86 ) ;
memcpy ( V_31 -> V_98 , V_99 [ V_210 ] . V_100 ,
sizeof( V_31 -> V_98 ) ) ;
memcpy ( V_31 -> V_101 , V_99 [ V_210 ] . V_100 ,
sizeof( V_31 -> V_101 ) ) ;
V_13 = F_14 ( V_2 , & V_33 ) ;
F_15 ( V_31 ) ;
return V_13 ;
}
