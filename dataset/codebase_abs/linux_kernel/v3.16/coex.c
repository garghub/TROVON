static int F_1 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , V_3 , 0 ,
sizeof( struct V_4 ) ,
& V_5 ) ;
}
static enum V_6
F_3 ( struct V_1 * V_2 , const struct V_7 * V_8 )
{
struct V_9 * V_10 ;
enum V_6 V_11 ;
T_1 V_12 ;
F_4 () ;
V_10 = F_5 ( V_8 -> V_10 ) ;
if ( ! V_10 ||
V_10 -> V_13 . V_14 -> V_15 != V_16 ) {
F_6 () ;
return V_17 ;
}
V_11 = V_18 ;
if ( V_2 -> V_19 -> V_20 ) {
F_6 () ;
return V_11 ;
}
V_12 = * ( ( T_1 * ) V_10 -> V_21 ) ;
if ( V_2 -> V_22 . V_23 == V_12 )
V_11 = F_7 ( V_2 -> V_24 . V_25 ) ;
else if ( V_2 -> V_22 . V_26 == V_12 )
V_11 = F_7 ( V_2 -> V_24 . V_27 ) ;
F_6 () ;
return V_11 ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_28 * V_29 ;
struct V_30 V_31 = {
. V_32 = V_33 ,
. V_34 = { sizeof( * V_29 ) , } ,
. V_35 = { V_36 , } ,
} ;
int V_11 ;
T_2 V_37 ;
V_11 = F_1 ( V_2 ) ;
if ( V_11 )
return V_11 ;
V_29 = F_9 ( sizeof( * V_29 ) , V_38 ) ;
if ( ! V_29 )
return - V_39 ;
V_31 . V_40 [ 0 ] = V_29 ;
V_29 -> V_41 = 5 ;
V_29 -> V_42 = V_43 ;
V_29 -> V_44 = V_45 . V_46 ;
V_29 -> V_47 = 15 ;
V_29 -> V_48 = 15 ;
V_29 -> V_49 = V_50 ;
V_29 -> V_51 = V_50 ;
V_37 = V_45 . V_52 ?
V_53 : V_54 ;
V_29 -> V_37 = F_10 ( V_37 ) ;
V_29 -> V_55 = F_10 ( V_56 |
V_57 |
V_58 |
V_59 |
V_60 |
V_61 |
V_62 |
V_63 |
V_64 |
V_65 |
V_66 |
V_67 |
V_68 |
V_69 |
V_70 ) ;
if ( V_71 )
V_29 -> V_37 |= F_10 ( V_72 ) ;
if ( V_73 ) {
V_29 -> V_55 |= F_10 ( V_74 |
V_75 ) ;
V_29 -> V_37 |= F_10 ( V_76 ) ;
}
if ( V_77 ) {
V_29 -> V_37 |= F_10 ( V_78 ) ;
V_29 -> V_55 |= F_10 ( V_79 ) ;
}
if ( V_2 -> V_19 -> V_20 )
memcpy ( & V_29 -> V_80 , V_81 ,
sizeof( V_81 ) ) ;
else
memcpy ( & V_29 -> V_80 , V_82 ,
sizeof( V_82 ) ) ;
memcpy ( V_29 -> V_83 , V_84 [ 0 ] . V_85 ,
sizeof( V_29 -> V_83 ) ) ;
memcpy ( V_29 -> V_86 , V_84 [ 0 ] . V_85 ,
sizeof( V_29 -> V_86 ) ) ;
memcpy ( & V_29 -> V_87 , V_88 ,
sizeof( V_88 ) ) ;
memcpy ( & V_29 -> V_89 , V_90 ,
sizeof( V_90 ) ) ;
V_29 -> V_91 =
F_10 ( V_92 [ V_93 ] ) ;
V_29 -> V_94 =
F_10 ( V_95 [ V_93 ] ) ;
memset ( & V_2 -> V_24 , 0 , sizeof( V_2 -> V_24 ) ) ;
memset ( & V_2 -> V_22 , 0 , sizeof( V_2 -> V_22 ) ) ;
V_11 = F_11 ( V_2 , & V_31 ) ;
F_12 ( V_29 ) ;
return V_11 ;
}
static int F_13 ( struct V_1 * V_2 ,
bool V_96 )
{
enum V_97 V_98 ;
struct V_28 * V_29 ;
struct V_99 * V_100 = & V_2 -> V_24 ;
struct V_30 V_31 = {
. V_32 = V_33 ,
. V_40 [ 0 ] = & V_29 ,
. V_34 = { sizeof( * V_29 ) , } ,
. V_35 = { V_36 , } ,
} ;
int V_11 = 0 ;
F_14 ( & V_2 -> V_101 ) ;
if ( V_96 ) {
V_98 = V_102 ;
} else {
if ( F_15 ( V_100 , 3 , V_103 ) ||
F_15 ( V_100 , 3 , V_104 ) ||
F_15 ( V_100 , 3 , V_105 ) )
V_98 = V_106 ;
else
V_98 = V_93 ;
}
F_16 ( V_2 ,
L_1 ,
V_98 ,
F_15 ( V_100 , 3 , V_103 ) ? L_2 : L_3 ,
F_15 ( V_100 , 3 , V_104 ) ? L_2 : L_3 ,
F_15 ( V_100 , 3 , V_105 ) ? L_2 : L_3 ) ;
if ( V_98 == V_2 -> V_98 )
return 0 ;
V_2 -> V_98 = V_98 ;
V_29 = F_9 ( sizeof( * V_29 ) , V_38 ) ;
if ( ! V_29 )
return - V_39 ;
V_31 . V_40 [ 0 ] = V_29 ;
V_29 -> V_37 = F_10 ( V_53 ) ;
V_29 -> V_91 = F_10 ( V_92 [ V_98 ] ) ;
V_29 -> V_94 = F_10 ( V_95 [ V_98 ] ) ;
V_29 -> V_55 |= F_10 ( V_56 |
V_60 |
V_61 ) ;
F_16 ( V_2 , L_4 ,
V_92 [ V_98 ] ,
V_95 [ V_98 ] ) ;
V_11 = F_11 ( V_2 , & V_31 ) ;
F_12 ( V_29 ) ;
return V_11 ;
}
static int F_17 ( struct V_1 * V_2 , T_3 V_107 ,
bool V_108 )
{
struct V_28 * V_29 ;
struct V_30 V_31 = {
. V_32 = V_33 ,
. V_34 = { sizeof( * V_29 ) , } ,
. V_35 = { V_36 , } ,
. V_37 = V_109 ,
} ;
struct V_110 * V_111 ;
int V_11 ;
V_111 = F_18 ( V_2 , V_107 ) ;
if ( ! V_111 )
return 0 ;
if ( V_111 -> V_112 == V_108 )
return 0 ;
V_29 = F_9 ( sizeof( * V_29 ) , V_113 ) ;
if ( ! V_29 )
return - V_39 ;
V_31 . V_40 [ 0 ] = V_29 ;
V_29 -> V_37 = F_10 ( V_53 ) ;
V_29 -> V_55 =
F_10 ( V_56 | V_62 ) ;
V_29 -> V_114 = V_107 ;
if ( V_108 )
V_29 -> V_114 |= V_115 ;
F_16 ( V_2 , L_5 ,
V_108 ? L_6 : L_7 , V_107 ) ;
V_111 -> V_112 = V_108 ;
V_11 = F_11 ( V_2 , & V_31 ) ;
F_12 ( V_29 ) ;
return V_11 ;
}
static inline
void F_19 ( struct V_1 * V_2 ,
struct V_7 * V_8 ,
bool V_108 , int V_116 )
{
struct V_117 * V_118 = F_20 ( V_8 ) ;
V_118 -> V_119 . V_120 = V_116 ;
V_118 -> V_119 . V_121 =
V_108 ? V_122 : 0 ;
V_118 -> V_119 . V_123 =
V_108 ? V_124 : 0 ;
}
static void F_21 ( void * V_125 , T_3 * V_126 ,
struct V_7 * V_8 )
{
struct V_117 * V_118 = F_20 ( V_8 ) ;
struct V_127 * V_40 = V_125 ;
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_9 * V_10 ;
enum V_128 V_129 ;
T_2 V_130 ;
int V_131 ;
F_14 ( & V_2 -> V_101 ) ;
switch ( V_8 -> type ) {
case V_132 :
V_40 -> V_133 ++ ;
V_129 = V_134 ;
break;
case V_135 :
V_129 = V_136 ;
if ( ! V_118 -> V_137 ) {
F_22 ( V_2 , V_8 , V_138 ,
V_129 ) ;
return;
}
V_40 -> V_96 = false ;
break;
default:
return;
}
V_10 = F_5 ( V_8 -> V_10 ) ;
if ( ( ! V_10 ||
V_10 -> V_13 . V_14 -> V_15 != V_16 ) ) {
F_22 ( V_2 , V_8 , V_138 ,
V_129 ) ;
V_40 -> V_96 = false ;
if ( V_8 -> type == V_132 ) {
F_17 ( V_2 , V_118 -> V_139 ,
false ) ;
F_19 ( V_2 , V_8 , false , 0 ) ;
}
return;
}
V_130 = F_7 ( V_40 -> V_100 -> V_130 ) ;
if ( V_130 >= V_140 )
V_129 = V_141 ;
else if ( V_130 >= V_142 )
V_129 = V_8 -> type == V_135 ?
V_136 :
V_143 ;
if ( ! V_8 -> V_144 . V_145 )
V_129 = V_134 ;
F_16 ( V_40 -> V_2 ,
L_8 ,
V_118 -> V_32 , V_40 -> V_100 -> V_146 , V_130 ,
V_129 ) ;
F_22 ( V_2 , V_8 , V_138 , V_129 ) ;
if ( F_23 ( V_118 ) ) {
V_40 -> V_147 = true ;
V_40 -> V_148 = V_40 -> V_149 ;
V_40 -> V_149 = V_10 ;
}
if ( V_8 -> type == V_135 ) {
if ( ! V_118 -> V_137 )
return;
if ( V_10 == V_40 -> V_149 )
return;
if ( ! V_40 -> V_147 ) {
V_40 -> V_148 = V_40 -> V_149 ;
V_40 -> V_149 = V_10 ;
} else {
V_40 -> V_148 = V_10 ;
}
return;
}
if ( ! V_40 -> V_149 || V_40 -> V_149 == V_10 )
V_40 -> V_149 = V_10 ;
else if ( ! V_40 -> V_148 )
V_40 -> V_148 = V_10 ;
if ( F_3 ( V_2 , V_8 ) == V_17 ||
V_2 -> V_19 -> V_20 || ! V_8 -> V_144 . V_145 ||
! V_40 -> V_100 -> V_146 ) {
V_40 -> V_96 = false ;
F_17 ( V_2 , V_118 -> V_139 , false ) ;
F_19 ( V_2 , V_8 , false , 0 ) ;
return;
}
V_131 = V_118 -> V_119 . V_150 ;
if ( ! V_131 )
V_131 = - 100 ;
if ( V_131 > V_122 ) {
if ( F_17 ( V_2 , V_118 -> V_139 , true ) )
F_24 ( V_2 , L_9 ) ;
} else if ( V_131 < V_124 ) {
if ( F_17 ( V_2 , V_118 -> V_139 , false ) )
F_24 ( V_2 , L_9 ) ;
V_40 -> V_96 = false ;
}
F_19 ( V_2 , V_8 , true , V_131 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_127 V_40 = {
. V_2 = V_2 ,
. V_100 = & V_2 -> V_24 ,
. V_96 = true ,
} ;
struct V_151 V_31 = {} ;
T_3 V_152 ;
F_4 () ;
F_26 (
V_2 -> V_153 , V_154 ,
F_21 , & V_40 ) ;
if ( V_40 . V_149 ) {
struct V_9 * V_14 = V_40 . V_149 ;
if ( F_27 ( ! V_14 -> V_13 . V_14 ) ) {
F_6 () ;
return;
}
if ( V_14 -> V_13 . V_155 < V_156 ) {
V_152 = 0 ;
V_31 . V_157 = 0 ;
} else {
V_31 . V_157 = 1 ;
if ( V_14 -> V_13 . V_158 >
V_14 -> V_13 . V_14 -> V_159 )
V_152 = 2 ;
else
V_152 = 1 ;
}
V_31 . V_160 =
V_161 [ V_14 -> V_13 . V_14 -> V_162 ] [ V_152 ] ;
V_31 . V_23 = * ( ( T_1 * ) V_40 . V_149 -> V_21 ) ;
}
if ( V_40 . V_148 ) {
struct V_9 * V_14 = V_40 . V_148 ;
if ( F_27 ( ! V_40 . V_148 -> V_13 . V_14 ) ) {
F_6 () ;
return;
}
if ( V_14 -> V_13 . V_155 < V_156 ) {
V_152 = 0 ;
V_31 . V_163 = 0 ;
} else {
V_31 . V_163 = 1 ;
if ( V_14 -> V_13 . V_158 >
V_14 -> V_13 . V_14 -> V_159 )
V_152 = 2 ;
else
V_152 = 1 ;
}
V_31 . V_164 =
V_161 [ V_14 -> V_13 . V_14 -> V_162 ] [ V_152 ] ;
V_31 . V_26 = * ( ( T_1 * ) V_40 . V_148 -> V_21 ) ;
}
F_6 () ;
if ( memcmp ( & V_31 , & V_2 -> V_22 , sizeof( V_31 ) ) ) {
if ( F_2 ( V_2 , V_165 , 0 ,
sizeof( V_31 ) , & V_31 ) )
F_24 ( V_2 , L_10 ) ;
memcpy ( & V_2 -> V_22 , & V_31 , sizeof( V_31 ) ) ;
}
V_40 . V_96 = V_40 . V_96 && V_40 . V_133 ;
if ( F_13 ( V_2 , V_40 . V_96 ) )
F_24 ( V_2 , L_11 ) ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_166 * V_167 ,
struct V_168 * V_169 )
{
struct V_170 * V_171 = F_29 ( V_167 ) ;
struct V_99 * V_100 = ( void * ) V_171 -> V_40 ;
F_16 ( V_2 , L_12 ) ;
F_16 ( V_2 , L_13 ,
V_100 -> V_146 ? L_14 : L_15 ) ;
F_16 ( V_2 , L_16 , V_100 -> V_172 ) ;
F_16 ( V_2 , L_17 , V_100 -> V_173 ) ;
F_16 ( V_2 , L_18 ,
F_7 ( V_100 -> V_25 ) ) ;
F_16 ( V_2 , L_19 ,
F_7 ( V_100 -> V_27 ) ) ;
F_16 ( V_2 , L_20 ,
F_7 ( V_100 -> V_130 ) ) ;
F_16 ( V_2 , L_21 ,
V_100 -> V_174 ) ;
memcpy ( & V_2 -> V_24 , V_100 , sizeof( V_2 -> V_24 ) ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static void F_30 ( void * V_125 , T_3 * V_126 ,
struct V_7 * V_8 )
{
struct V_117 * V_118 = ( void * ) V_8 -> V_21 ;
struct V_127 * V_40 = V_125 ;
struct V_1 * V_2 = V_40 -> V_2 ;
struct V_175 * V_176 ;
struct V_110 * V_111 ;
struct V_9 * V_10 ;
F_4 () ;
V_10 = F_5 ( V_8 -> V_10 ) ;
if ( ! V_10 ||
V_10 -> V_13 . V_14 -> V_15 != V_16 ) {
F_6 () ;
return;
}
F_6 () ;
if ( V_8 -> type != V_132 ||
V_118 -> V_139 == V_177 )
return;
V_176 = F_31 ( V_2 -> V_178 [ V_118 -> V_139 ] ,
F_32 ( & V_2 -> V_101 ) ) ;
if ( F_33 ( V_176 ) )
return;
V_111 = F_34 ( V_176 ) ;
V_40 -> V_133 ++ ;
if ( ! V_111 -> V_112 )
V_40 -> V_96 = false ;
}
void F_35 ( struct V_1 * V_2 , struct V_7 * V_8 ,
enum V_179 V_180 )
{
struct V_117 * V_118 = ( void * ) V_8 -> V_21 ;
struct V_127 V_40 = {
. V_2 = V_2 ,
. V_96 = true ,
} ;
int V_11 ;
F_14 ( & V_2 -> V_101 ) ;
if ( V_118 -> V_139 == V_177 )
return;
if ( ! V_2 -> V_24 . V_146 )
return;
F_16 ( V_2 , L_22 , V_8 -> V_144 . V_181 ,
V_180 == V_182 ? L_23 : L_24 ) ;
if ( V_180 == V_183 || V_2 -> V_19 -> V_20 ||
F_3 ( V_2 , V_8 ) == V_17 )
V_11 = F_17 ( V_2 , V_118 -> V_139 ,
false ) ;
else
V_11 = F_17 ( V_2 , V_118 -> V_139 , true ) ;
if ( V_11 )
F_24 ( V_2 , L_25 ) ;
F_26 (
V_2 -> V_153 , V_154 ,
F_30 , & V_40 ) ;
V_40 . V_96 = V_40 . V_96 && V_40 . V_133 ;
if ( F_13 ( V_2 , V_40 . V_96 ) )
F_24 ( V_2 , L_11 ) ;
}
T_1 F_36 ( struct V_1 * V_2 ,
struct V_175 * V_176 )
{
struct V_110 * V_111 = F_34 ( V_176 ) ;
enum V_6 V_184 ;
if ( F_7 ( V_2 -> V_24 . V_130 ) <
V_140 )
return V_185 ;
V_184 = F_3 ( V_2 , V_111 -> V_8 ) ;
if ( V_184 == V_17 )
return V_185 ;
return V_186 ;
}
bool F_37 ( struct V_1 * V_2 ,
struct V_175 * V_176 )
{
struct V_110 * V_111 = F_34 ( V_176 ) ;
if ( F_7 ( V_2 -> V_24 . V_130 ) <
V_140 )
return true ;
return F_3 ( V_2 , V_111 -> V_8 ) == V_187 ;
}
bool F_38 ( struct V_1 * V_2 ,
enum V_188 V_15 )
{
T_2 V_189 = F_7 ( V_2 -> V_24 . V_130 ) ;
if ( V_15 != V_16 )
return false ;
return V_189 >= V_142 ;
}
T_3 F_39 ( struct V_1 * V_2 , struct V_190 * V_191 ,
struct V_192 * V_193 , T_3 V_194 )
{
T_4 V_195 = V_191 -> V_196 ;
if ( V_193 -> V_15 != V_16 )
return 0 ;
if ( F_40 ( V_2 -> V_197 ) )
return V_2 -> V_197 - 1 ;
if ( V_193 -> V_198 . V_37 & V_199 ||
F_41 ( V_191 -> V_200 ) ||
F_42 ( V_195 ) || F_43 ( V_195 ) ||
F_44 ( V_195 ) || F_45 ( V_195 ) )
return 3 ;
switch ( V_194 ) {
case V_201 :
return 1 ;
case V_202 :
return 3 ;
case V_203 :
return 2 ;
default:
break;
}
return 0 ;
}
void F_46 ( struct V_1 * V_2 )
{
F_25 ( V_2 ) ;
}
int F_47 ( struct V_1 * V_2 ,
struct V_166 * V_167 ,
struct V_168 * V_169 )
{
struct V_170 * V_171 = F_29 ( V_167 ) ;
T_2 V_204 = F_48 ( ( void * ) V_171 -> V_40 ) ;
T_3 T_5 V_205 , V_206 ;
int V_11 ;
T_3 V_207 ;
struct V_28 * V_29 ;
struct V_30 V_31 = {
. V_32 = V_33 ,
. V_34 = { sizeof( * V_29 ) , } ,
. V_35 = { V_36 , } ,
} ;
if ( ! V_73 )
return 0 ;
F_14 ( & V_2 -> V_101 ) ;
if ( V_204 == V_2 -> V_208 )
return 0 ;
for ( V_207 = 0 ; V_207 < F_49 ( V_84 ) - 1 ; V_207 ++ )
if ( V_204 < V_84 [ V_207 + 1 ] . V_209 )
break;
V_205 = V_84 [ V_207 ] . V_209 ;
if ( V_207 < F_49 ( V_84 ) - 1 )
V_206 = V_84 [ V_207 + 1 ] . V_209 ;
else
V_206 = V_84 [ V_207 ] . V_209 ;
F_16 ( V_2 , L_26 ,
V_204 , V_205 , V_206 , V_207 ) ;
V_2 -> V_208 = V_204 ;
if ( V_2 -> V_210 == V_207 )
return 0 ;
V_2 -> V_210 = V_207 ;
V_29 = F_9 ( sizeof( * V_29 ) , V_38 ) ;
if ( ! V_29 )
return 0 ;
V_31 . V_40 [ 0 ] = V_29 ;
V_29 -> V_37 = F_10 ( V_53 ) ;
V_29 -> V_55 |= F_10 ( V_56 |
V_74 |
V_75 ) ;
memcpy ( V_29 -> V_83 , V_84 [ V_207 ] . V_85 ,
sizeof( V_29 -> V_83 ) ) ;
memcpy ( V_29 -> V_86 , V_84 [ V_207 ] . V_85 ,
sizeof( V_29 -> V_86 ) ) ;
V_11 = F_11 ( V_2 , & V_31 ) ;
F_12 ( V_29 ) ;
return V_11 ;
}
