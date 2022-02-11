int F_1 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_3 -> V_4 . V_5 & V_6 ) )
return 0 ;
return F_2 ( V_2 , V_7 , V_8 ,
sizeof( struct V_9 ) ,
& V_10 ) ;
}
static enum V_11
F_3 ( struct V_1 * V_2 , const struct V_12 * V_13 )
{
struct V_14 * V_15 ;
enum V_11 V_16 ;
T_1 V_17 ;
F_4 () ;
V_15 = F_5 ( V_13 -> V_15 ) ;
if ( ! V_15 ||
V_15 -> V_18 . V_19 -> V_20 != V_21 ) {
F_6 () ;
return V_22 ;
}
V_16 = V_23 ;
if ( V_2 -> V_24 -> V_25 ) {
F_6 () ;
return V_16 ;
}
V_17 = * ( ( T_1 * ) V_15 -> V_26 ) ;
if ( V_2 -> V_27 . V_28 == V_17 )
V_16 = F_7 ( V_2 -> V_29 . V_30 ) ;
else if ( V_2 -> V_27 . V_31 == V_17 )
V_16 = F_7 ( V_2 -> V_29 . V_32 ) ;
F_6 () ;
return V_16 ;
}
int F_8 ( struct V_1 * V_2 )
{
struct V_33 * V_34 ;
struct V_35 V_36 = {
. V_37 = V_38 ,
. V_39 = { sizeof( * V_34 ) , } ,
. V_40 = { V_41 , } ,
. V_5 = V_8 ,
} ;
int V_16 ;
T_2 V_5 ;
if ( ! ( V_2 -> V_3 -> V_4 . V_5 & V_6 ) )
return 0 ;
V_34 = F_9 ( sizeof( * V_34 ) , V_42 ) ;
if ( ! V_34 )
return - V_43 ;
V_36 . V_44 [ 0 ] = V_34 ;
V_34 -> V_45 = 5 ;
V_34 -> V_46 = V_47 ,
V_34 -> V_48 = V_49 . V_50 ,
V_34 -> V_51 = 15 ,
V_34 -> V_52 = 15 ,
V_5 = V_49 . V_53 ?
V_54 : V_55 ;
V_34 -> V_5 = F_10 ( V_5 ) ;
V_34 -> V_56 = F_10 ( V_57 |
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
V_70 |
V_71 ) ;
if ( V_72 )
V_34 -> V_5 |= F_10 ( V_73 ) ;
if ( V_74 ) {
V_34 -> V_56 |= F_10 ( V_75 |
V_76 ) ;
V_34 -> V_5 |= F_10 ( V_77 ) ;
}
if ( V_78 ) {
V_34 -> V_5 |= F_10 ( V_79 ) ;
V_34 -> V_56 |= F_10 ( V_80 ) ;
}
if ( V_2 -> V_24 -> V_25 )
memcpy ( & V_34 -> V_81 , V_82 ,
sizeof( V_82 ) ) ;
else
memcpy ( & V_34 -> V_81 , V_83 ,
sizeof( V_83 ) ) ;
memcpy ( V_34 -> V_84 , V_85 [ 0 ] . V_86 ,
sizeof( V_34 -> V_84 ) ) ;
memcpy ( V_34 -> V_87 , V_85 [ 0 ] . V_86 ,
sizeof( V_34 -> V_87 ) ) ;
memcpy ( & V_34 -> V_88 , V_89 ,
sizeof( V_89 ) ) ;
memcpy ( & V_34 -> V_90 , V_91 ,
sizeof( V_91 ) ) ;
V_34 -> V_92 =
F_10 ( V_93 [ V_94 ] ) ;
V_34 -> V_95 =
F_10 ( V_96 [ V_94 ] ) ;
memset ( & V_2 -> V_29 , 0 , sizeof( V_2 -> V_29 ) ) ;
memset ( & V_2 -> V_27 , 0 , sizeof( V_2 -> V_27 ) ) ;
V_16 = F_11 ( V_2 , & V_36 ) ;
F_12 ( V_34 ) ;
return V_16 ;
}
static int F_13 ( struct V_1 * V_2 ,
bool V_97 )
{
enum V_98 V_99 ;
struct V_33 * V_34 ;
struct V_100 * V_101 = & V_2 -> V_29 ;
struct V_35 V_36 = {
. V_37 = V_38 ,
. V_44 [ 0 ] = & V_34 ,
. V_39 = { sizeof( * V_34 ) , } ,
. V_40 = { V_41 , } ,
. V_5 = V_8 ,
} ;
int V_16 = 0 ;
F_14 ( & V_2 -> V_102 ) ;
if ( V_97 ) {
V_99 = V_103 ;
} else {
if ( F_15 ( V_101 , 3 , V_104 ) ||
F_15 ( V_101 , 3 , V_105 ) ||
F_15 ( V_101 , 3 , V_106 ) )
V_99 = V_107 ;
else
V_99 = V_94 ;
}
F_16 ( V_2 ,
L_1 ,
V_99 ,
F_15 ( V_101 , 3 , V_104 ) ? L_2 : L_3 ,
F_15 ( V_101 , 3 , V_105 ) ? L_2 : L_3 ,
F_15 ( V_101 , 3 , V_106 ) ? L_2 : L_3 ) ;
if ( V_99 == V_2 -> V_99 )
return 0 ;
V_2 -> V_99 = V_99 ;
V_34 = F_9 ( sizeof( * V_34 ) , V_42 ) ;
if ( ! V_34 )
return - V_43 ;
V_36 . V_44 [ 0 ] = V_34 ;
V_34 -> V_5 = F_10 ( V_54 ) ;
V_34 -> V_92 = F_10 ( V_93 [ V_99 ] ) ;
V_34 -> V_95 = F_10 ( V_96 [ V_99 ] ) ;
V_34 -> V_56 |= F_10 ( V_57 |
V_61 |
V_62 ) ;
F_16 ( V_2 , L_4 ,
V_93 [ V_99 ] ,
V_96 [ V_99 ] ) ;
V_16 = F_11 ( V_2 , & V_36 ) ;
F_12 ( V_34 ) ;
return V_16 ;
}
int F_17 ( struct V_1 * V_2 , T_3 V_108 , bool V_109 )
{
struct V_33 * V_34 ;
struct V_35 V_36 = {
. V_37 = V_38 ,
. V_39 = { sizeof( * V_34 ) , } ,
. V_40 = { V_41 , } ,
. V_5 = V_110 ,
} ;
struct V_111 * V_112 ;
int V_16 ;
V_112 = F_18 ( V_2 , V_108 ) ;
if ( ! V_112 )
return 0 ;
if ( V_112 -> V_113 ||
V_112 -> V_114 == V_109 )
return 0 ;
V_34 = F_9 ( sizeof( * V_34 ) , V_115 ) ;
if ( ! V_34 )
return - V_43 ;
V_36 . V_44 [ 0 ] = V_34 ;
V_34 -> V_5 = F_10 ( V_54 ) ;
V_34 -> V_56 =
F_10 ( V_57 | V_63 ) ;
V_34 -> V_116 = V_108 ;
if ( V_109 )
V_34 -> V_116 |= V_117 ;
F_16 ( V_2 , L_5 ,
V_109 ? L_6 : L_7 , V_108 ) ;
V_112 -> V_114 = V_109 ;
V_16 = F_11 ( V_2 , & V_36 ) ;
F_12 ( V_34 ) ;
return V_16 ;
}
static inline
void F_19 ( struct V_1 * V_2 ,
struct V_12 * V_13 ,
bool V_109 , int V_118 )
{
struct V_119 * V_120 = F_20 ( V_13 ) ;
V_120 -> V_121 . V_122 = V_118 ;
V_120 -> V_121 . V_123 =
V_109 ? V_124 : 0 ;
V_120 -> V_121 . V_125 =
V_109 ? V_126 : 0 ;
}
static void F_21 ( void * V_127 , T_3 * V_128 ,
struct V_12 * V_13 )
{
struct V_119 * V_120 = F_20 ( V_13 ) ;
struct V_129 * V_44 = V_127 ;
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_14 * V_15 ;
enum V_130 V_131 ;
T_2 V_132 ;
int V_133 ;
F_14 ( & V_2 -> V_102 ) ;
switch ( V_13 -> type ) {
case V_134 :
V_131 = V_135 ;
V_44 -> V_136 ++ ;
if ( ! V_13 -> V_137 . V_138 ) {
F_22 ( V_2 , V_13 , V_139 ,
V_131 ) ;
if ( F_17 ( V_2 ,
V_120 -> V_140 ,
false ) )
F_23 ( V_2 , L_8 ) ;
return;
}
break;
case V_141 :
V_131 = V_142 ;
if ( ! V_120 -> V_143 ) {
F_22 ( V_2 , V_13 , V_139 ,
V_131 ) ;
return;
}
V_44 -> V_97 = false ;
break;
default:
return;
}
V_15 = F_5 ( V_13 -> V_15 ) ;
if ( ( ! V_15 ||
V_15 -> V_18 . V_19 -> V_20 != V_21 ) ) {
F_22 ( V_2 , V_13 , V_139 ,
V_131 ) ;
if ( V_13 -> type == V_134 )
F_19 ( V_2 , V_13 , false , 0 ) ;
return;
}
V_132 = F_7 ( V_44 -> V_101 -> V_132 ) ;
if ( V_132 >= V_144 )
V_131 = V_145 ;
else if ( V_132 >= V_146 )
V_131 = V_13 -> type == V_141 ?
V_142 :
V_147 ;
F_16 ( V_44 -> V_2 ,
L_9 ,
V_120 -> V_37 , V_44 -> V_101 -> V_148 , V_132 ,
V_131 ) ;
F_22 ( V_2 , V_13 , V_139 , V_131 ) ;
if ( F_24 ( V_120 ) ) {
V_44 -> V_149 = true ;
V_44 -> V_150 = V_44 -> V_151 ;
V_44 -> V_151 = V_15 ;
}
if ( V_13 -> type == V_141 ) {
if ( ! V_120 -> V_143 )
return;
if ( V_15 == V_44 -> V_151 )
return;
if ( ! V_44 -> V_149 ) {
V_44 -> V_150 = V_44 -> V_151 ;
V_44 -> V_151 = V_15 ;
} else {
V_44 -> V_150 = V_15 ;
}
return;
}
if ( ! V_44 -> V_151 || V_44 -> V_151 == V_15 )
V_44 -> V_151 = V_15 ;
else if ( ! V_44 -> V_150 )
V_44 -> V_150 = V_15 ;
if ( F_3 ( V_2 , V_13 ) == V_22 ||
V_2 -> V_24 -> V_25 ) {
V_44 -> V_97 = false ;
F_19 ( V_2 , V_13 , false , 0 ) ;
return;
}
if ( ! V_44 -> V_101 -> V_148 ) {
if ( F_17 ( V_2 , V_120 -> V_140 , false ) )
F_23 ( V_2 , L_8 ) ;
V_44 -> V_97 = false ;
F_19 ( V_2 , V_13 , false , 0 ) ;
return;
}
V_133 = V_120 -> V_121 . V_152 ;
if ( ! V_133 )
V_133 = - 100 ;
if ( V_133 > V_124 ) {
if ( F_17 ( V_2 , V_120 -> V_140 , true ) )
F_23 ( V_2 , L_8 ) ;
} else if ( V_133 < V_126 ) {
if ( F_17 ( V_2 , V_120 -> V_140 , false ) )
F_23 ( V_2 , L_8 ) ;
V_44 -> V_97 = false ;
}
F_19 ( V_2 , V_13 , true , V_133 ) ;
}
static void F_25 ( struct V_1 * V_2 )
{
struct V_129 V_44 = {
. V_2 = V_2 ,
. V_101 = & V_2 -> V_29 ,
. V_97 = true ,
} ;
struct V_153 V_36 = {} ;
T_3 V_154 ;
F_4 () ;
F_26 (
V_2 -> V_155 , V_156 ,
F_21 , & V_44 ) ;
if ( V_44 . V_151 ) {
struct V_14 * V_19 = V_44 . V_151 ;
if ( F_27 ( ! V_19 -> V_18 . V_19 ) ) {
F_6 () ;
return;
}
if ( V_19 -> V_18 . V_157 < V_158 ) {
V_154 = 0 ;
V_36 . V_159 = 0 ;
} else {
V_36 . V_159 = 1 ;
if ( V_19 -> V_18 . V_160 >
V_19 -> V_18 . V_19 -> V_161 )
V_154 = 2 ;
else
V_154 = 1 ;
}
V_36 . V_162 =
V_163 [ V_19 -> V_18 . V_19 -> V_164 ] [ V_154 ] ;
V_36 . V_28 = * ( ( T_1 * ) V_44 . V_151 -> V_26 ) ;
}
if ( V_44 . V_150 ) {
struct V_14 * V_19 = V_44 . V_150 ;
if ( F_27 ( ! V_44 . V_150 -> V_18 . V_19 ) ) {
F_6 () ;
return;
}
if ( V_19 -> V_18 . V_157 < V_158 ) {
V_154 = 0 ;
V_36 . V_165 = 0 ;
} else {
V_36 . V_165 = 1 ;
if ( V_19 -> V_18 . V_160 >
V_19 -> V_18 . V_19 -> V_161 )
V_154 = 2 ;
else
V_154 = 1 ;
}
V_36 . V_166 =
V_163 [ V_19 -> V_18 . V_19 -> V_164 ] [ V_154 ] ;
V_36 . V_31 = * ( ( T_1 * ) V_44 . V_150 -> V_26 ) ;
}
F_6 () ;
if ( memcmp ( & V_36 , & V_2 -> V_27 , sizeof( V_36 ) ) ) {
if ( F_2 ( V_2 , V_167 , V_8 ,
sizeof( V_36 ) , & V_36 ) )
F_23 ( V_2 , L_10 ) ;
memcpy ( & V_2 -> V_27 , & V_36 , sizeof( V_36 ) ) ;
}
V_44 . V_97 = V_44 . V_97 && V_44 . V_136 ;
if ( F_13 ( V_2 , V_44 . V_97 ) )
F_23 ( V_2 , L_11 ) ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_168 * V_169 ,
struct V_170 * V_171 )
{
struct V_172 * V_173 = F_29 ( V_169 ) ;
struct V_100 * V_101 = ( void * ) V_173 -> V_44 ;
F_16 ( V_2 , L_12 ) ;
F_16 ( V_2 , L_13 ,
V_101 -> V_148 ? L_14 : L_15 ) ;
F_16 ( V_2 , L_16 , V_101 -> V_174 ) ;
F_16 ( V_2 , L_17 , V_101 -> V_175 ) ;
F_16 ( V_2 , L_18 ,
F_7 ( V_101 -> V_30 ) ) ;
F_16 ( V_2 , L_19 ,
F_7 ( V_101 -> V_32 ) ) ;
F_16 ( V_2 , L_20 ,
F_7 ( V_101 -> V_132 ) ) ;
F_16 ( V_2 , L_21 ,
V_101 -> V_176 ) ;
memcpy ( & V_2 -> V_29 , V_101 , sizeof( V_2 -> V_29 ) ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static void F_30 ( void * V_127 , T_3 * V_128 ,
struct V_12 * V_13 )
{
struct V_119 * V_120 = ( void * ) V_13 -> V_26 ;
struct V_129 * V_44 = V_127 ;
struct V_1 * V_2 = V_44 -> V_2 ;
struct V_177 * V_178 ;
struct V_111 * V_112 ;
struct V_14 * V_15 ;
F_4 () ;
V_15 = F_5 ( V_13 -> V_15 ) ;
if ( ! V_15 ||
V_15 -> V_18 . V_19 -> V_20 != V_21 ) {
F_6 () ;
return;
}
F_6 () ;
if ( V_13 -> type != V_134 ||
V_120 -> V_140 == V_179 )
return;
V_178 = F_31 ( V_2 -> V_180 [ V_120 -> V_140 ] ,
F_32 ( & V_2 -> V_102 ) ) ;
if ( F_33 ( V_178 ) )
return;
V_112 = F_34 ( V_178 ) ;
V_44 -> V_136 ++ ;
if ( ! V_112 -> V_114 )
V_44 -> V_97 = false ;
}
void F_35 ( struct V_1 * V_2 , struct V_12 * V_13 ,
enum V_181 V_182 )
{
struct V_119 * V_120 = ( void * ) V_13 -> V_26 ;
struct V_129 V_44 = {
. V_2 = V_2 ,
. V_97 = true ,
} ;
int V_16 ;
F_14 ( & V_2 -> V_102 ) ;
if ( V_120 -> V_140 == V_179 )
return;
if ( ! V_2 -> V_29 . V_148 )
return;
F_16 ( V_2 , L_22 , V_13 -> V_137 . V_183 ,
V_182 == V_184 ? L_23 : L_24 ) ;
if ( V_182 == V_185 || V_2 -> V_24 -> V_25 ||
F_3 ( V_2 , V_13 ) == V_22 )
V_16 = F_17 ( V_2 , V_120 -> V_140 ,
false ) ;
else
V_16 = F_17 ( V_2 , V_120 -> V_140 , true ) ;
if ( V_16 )
F_23 ( V_2 , L_25 ) ;
F_26 (
V_2 -> V_155 , V_156 ,
F_30 , & V_44 ) ;
V_44 . V_97 = V_44 . V_97 && V_44 . V_136 ;
if ( F_13 ( V_2 , V_44 . V_97 ) )
F_23 ( V_2 , L_11 ) ;
}
T_1 F_36 ( struct V_1 * V_2 ,
struct V_177 * V_178 )
{
struct V_111 * V_112 = F_34 ( V_178 ) ;
enum V_11 V_186 ;
if ( F_7 ( V_2 -> V_29 . V_132 ) <
V_144 )
return V_187 ;
V_186 = F_3 ( V_2 , V_112 -> V_13 ) ;
if ( V_186 == V_22 )
return V_187 ;
return V_188 ;
}
bool F_37 ( struct V_1 * V_2 ,
struct V_177 * V_178 )
{
struct V_111 * V_112 = F_34 ( V_178 ) ;
if ( F_7 ( V_2 -> V_29 . V_132 ) <
V_144 )
return true ;
return F_3 ( V_2 , V_112 -> V_13 ) == V_189 ;
}
T_3 F_38 ( struct V_1 * V_2 , struct V_190 * V_191 ,
struct V_192 * V_193 , T_3 V_194 )
{
T_4 V_195 = V_191 -> V_196 ;
if ( V_193 -> V_20 != V_21 )
return 0 ;
if ( F_39 ( V_2 -> V_197 ) )
return V_2 -> V_197 - 1 ;
if ( V_193 -> V_198 . V_5 & V_199 ||
F_40 ( V_191 -> V_200 ) ||
F_41 ( V_195 ) || F_42 ( V_195 ) ||
F_43 ( V_195 ) || F_44 ( V_195 ) )
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
void F_45 ( struct V_1 * V_2 )
{
if ( ! ( V_2 -> V_3 -> V_4 . V_5 & V_6 ) )
return;
F_25 ( V_2 ) ;
}
int F_46 ( struct V_1 * V_2 ,
struct V_168 * V_169 ,
struct V_170 * V_171 )
{
struct V_172 * V_173 = F_29 ( V_169 ) ;
T_2 V_204 = F_47 ( ( void * ) V_173 -> V_44 ) ;
T_3 T_5 V_205 , V_206 ;
int V_16 ;
T_3 V_207 ;
struct V_33 * V_34 ;
struct V_35 V_36 = {
. V_37 = V_38 ,
. V_39 = { sizeof( * V_34 ) , } ,
. V_40 = { V_41 , } ,
. V_5 = V_8 ,
} ;
if ( ! V_74 )
return 0 ;
F_14 ( & V_2 -> V_102 ) ;
if ( V_204 == V_2 -> V_208 )
return 0 ;
for ( V_207 = 0 ; V_207 < F_48 ( V_85 ) - 1 ; V_207 ++ )
if ( V_204 < V_85 [ V_207 + 1 ] . V_209 )
break;
V_205 = V_85 [ V_207 ] . V_209 ;
if ( V_207 < F_48 ( V_85 ) - 1 )
V_206 = V_85 [ V_207 + 1 ] . V_209 ;
else
V_206 = V_85 [ V_207 ] . V_209 ;
F_16 ( V_2 , L_26 ,
V_204 , V_205 , V_206 , V_207 ) ;
V_2 -> V_208 = V_204 ;
if ( V_2 -> V_210 == V_207 )
return 0 ;
V_2 -> V_210 = V_207 ;
V_34 = F_9 ( sizeof( * V_34 ) , V_42 ) ;
if ( ! V_34 )
return 0 ;
V_36 . V_44 [ 0 ] = V_34 ;
V_34 -> V_5 = F_10 ( V_54 ) ;
V_34 -> V_56 |= F_10 ( V_57 |
V_75 |
V_76 ) ;
memcpy ( V_34 -> V_84 , V_85 [ V_207 ] . V_86 ,
sizeof( V_34 -> V_84 ) ) ;
memcpy ( V_34 -> V_87 , V_85 [ V_207 ] . V_86 ,
sizeof( V_34 -> V_87 ) ) ;
V_16 = F_11 ( V_2 , & V_36 ) ;
F_12 ( V_34 ) ;
return V_16 ;
}
