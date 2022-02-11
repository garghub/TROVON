static enum V_1
F_1 ( struct V_2 * V_3 , const struct V_4 * V_5 )
{
struct V_6 * V_7 ;
enum V_1 V_8 ;
T_1 V_9 ;
T_2 V_10 , V_11 ;
F_2 () ;
V_7 = F_3 ( V_5 -> V_7 ) ;
if ( ! V_7 ||
V_7 -> V_12 . V_13 -> V_14 != V_15 ) {
F_4 () ;
return V_16 ;
}
V_8 = V_17 ;
if ( V_3 -> V_18 -> V_19 ) {
F_4 () ;
return V_8 ;
}
V_9 = * ( ( T_1 * ) V_7 -> V_20 ) ;
V_10 = F_5 ( V_3 -> V_21 . V_10 ) ;
V_11 =
F_5 ( V_3 -> V_21 . V_11 ) ;
if ( V_10 == V_9 )
V_8 = F_5 ( V_3 -> V_22 . V_23 ) ;
else if ( V_11 == V_9 )
V_8 = F_5 ( V_3 -> V_22 . V_24 ) ;
F_4 () ;
return V_8 ;
}
int F_6 ( struct V_2 * V_3 )
{
struct V_25 * V_26 ;
struct V_27 V_28 = {
. V_29 = V_30 ,
. V_31 = { sizeof( * V_26 ) , } ,
. V_32 = { V_33 , } ,
} ;
int V_8 ;
T_2 V_34 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_7 ( V_3 ) ;
V_26 = F_8 ( sizeof( * V_26 ) , V_39 ) ;
if ( ! V_26 )
return - V_40 ;
V_28 . V_41 [ 0 ] = V_26 ;
F_9 ( & V_3 -> V_42 ) ;
if ( F_10 ( V_3 -> V_43 != V_44 ) ) {
switch ( V_3 -> V_43 ) {
case V_45 :
V_34 = V_46 ;
break;
case V_47 :
V_34 = V_48 ;
break;
default:
F_11 ( 1 ) ;
V_34 = 0 ;
}
V_26 -> V_34 = F_12 ( V_34 ) ;
goto V_49;
}
V_26 -> V_50 = F_12 ( 5 ) ;
V_26 -> V_51 =
F_12 ( V_52 ) ;
V_26 -> V_53 = F_12 ( 15 ) ;
V_26 -> V_54 = F_12 ( 15 ) ;
V_26 -> V_55 = F_12 ( V_16 ) ;
V_26 -> V_56 = F_12 ( V_16 ) ;
V_34 = V_57 . V_58 ? V_59 : V_60 ;
V_26 -> V_34 = F_12 ( V_34 ) ;
if ( V_61 )
V_26 -> V_62 |=
F_12 ( V_63 ) ;
if ( V_64 )
V_26 -> V_62 |= F_12 ( V_65 ) ;
if ( V_66 ) {
V_26 -> V_62 |= F_12 ( V_67 ) ;
V_26 -> V_62 |=
F_12 ( V_68 ) ;
}
V_26 -> V_62 |= F_12 ( V_69 ) ;
if ( V_3 -> V_18 -> V_19 )
memcpy ( & V_26 -> V_70 , V_71 ,
sizeof( V_71 ) ) ;
else
memcpy ( & V_26 -> V_70 , V_72 ,
sizeof( V_72 ) ) ;
memcpy ( & V_26 -> V_73 , V_74 ,
sizeof( V_74 ) ) ;
V_26 -> V_75 [ 0 ] = F_12 ( V_76 ) ;
V_26 -> V_75 [ 1 ] = F_12 ( V_77 ) ;
V_49:
memset ( & V_3 -> V_22 , 0 , sizeof( V_3 -> V_22 ) ) ;
memset ( & V_3 -> V_21 , 0 , sizeof( V_3 -> V_21 ) ) ;
V_8 = F_13 ( V_3 , & V_28 ) ;
F_14 ( V_26 ) ;
return V_8 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_78 * V_79 = & V_3 -> V_22 ;
T_2 V_80 = F_5 ( V_79 -> V_23 ) ;
T_2 V_81 = F_5 ( V_79 -> V_24 ) ;
T_2 V_82 = F_5 ( V_79 -> V_83 ) ;
struct V_84 V_28 = {} ;
T_3 V_85 [ V_86 ] = {} ;
T_3 V_87 [ V_86 ] = {} ;
int V_88 ;
F_9 ( & V_3 -> V_42 ) ;
V_85 [ 0 ] = V_89 [ V_82 ] [ V_80 ] ;
V_87 [ 0 ] = V_90 [ V_82 ] [ V_80 ] ;
V_85 [ 1 ] = V_89 [ V_82 ] [ V_81 ] ;
V_87 [ 1 ] = V_90 [ V_82 ] [ V_81 ] ;
if ( ! memcmp ( V_85 , V_3 -> V_91 , sizeof( V_85 ) ) ||
! memcmp ( V_87 , V_3 -> V_92 , sizeof( V_87 ) ) )
return 0 ;
memcpy ( V_3 -> V_91 , V_85 ,
sizeof( V_3 -> V_91 ) ) ;
memcpy ( V_3 -> V_92 , V_87 ,
sizeof( V_3 -> V_92 ) ) ;
F_16 ( F_17 ( V_85 ) < F_17 ( V_28 . V_93 ) ) ;
for ( V_88 = 0 ; V_88 < F_17 ( V_28 . V_93 ) ; V_88 ++ ) {
V_28 . V_93 [ V_88 ] . V_94 =
F_12 ( V_95 [ V_85 [ V_88 ] ] ) ;
V_28 . V_93 [ V_88 ] . V_96 =
F_12 ( V_95 [ V_87 [ V_88 ] ] ) ;
}
return F_18 ( V_3 , V_97 , 0 ,
sizeof( V_28 ) , & V_28 ) ;
}
static int F_19 ( struct V_2 * V_3 , T_3 V_98 ,
bool V_99 )
{
struct V_100 V_28 = {} ;
struct V_101 * V_102 ;
T_2 V_103 ;
int V_8 ;
V_102 = F_20 ( V_3 , V_98 ) ;
if ( ! V_102 )
return 0 ;
if ( V_102 -> V_104 == V_99 )
return 0 ;
V_103 = V_102 -> V_98 ;
if ( V_99 )
V_103 |= V_105 ;
F_21 ( V_3 , L_1 ,
V_99 ? L_2 : L_3 , V_98 ) ;
V_28 . V_106 = F_12 ( V_103 ) ;
V_102 -> V_104 = V_99 ;
V_8 = F_18 ( V_3 , V_107 , V_108 ,
sizeof( V_28 ) , & V_28 ) ;
return V_8 ;
}
static inline
void F_22 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
bool V_99 , int V_109 )
{
struct V_110 * V_111 = F_23 ( V_5 ) ;
V_111 -> V_112 . V_113 = V_109 ;
V_111 -> V_112 . V_114 =
V_99 ? - V_115 : 0 ;
V_111 -> V_112 . V_116 =
V_99 ? - V_117 : 0 ;
}
static void F_24 ( void * V_118 , T_3 * V_119 ,
struct V_4 * V_5 )
{
struct V_110 * V_111 = F_23 ( V_5 ) ;
struct V_120 * V_41 = V_118 ;
struct V_2 * V_3 = V_41 -> V_3 ;
struct V_6 * V_7 ;
enum V_121 V_122 = V_123 ;
T_2 V_83 ;
int V_124 ;
F_9 ( & V_3 -> V_42 ) ;
switch ( V_5 -> type ) {
case V_125 :
break;
case V_126 :
if ( ! V_111 -> V_127 )
return;
break;
default:
return;
}
V_7 = F_3 ( V_5 -> V_7 ) ;
if ( ( ! V_7 ||
V_7 -> V_12 . V_13 -> V_14 != V_15 ) ) {
if ( V_5 -> type == V_125 ) {
F_25 ( V_3 , V_5 , V_128 ,
V_122 ) ;
F_19 ( V_3 , V_111 -> V_129 ,
false ) ;
F_22 ( V_3 , V_5 , false , 0 ) ;
}
return;
}
V_83 = F_5 ( V_41 -> V_79 -> V_83 ) ;
if ( V_83 >= V_130 )
V_122 = V_131 ;
else if ( V_83 >= V_132 )
V_122 = V_133 ;
if ( ! V_5 -> V_134 . V_135 )
V_122 = V_123 ;
if ( F_26 ( V_3 -> V_22 . V_136 ,
V_111 -> V_137 -> V_29 ) )
V_122 = V_123 ;
F_21 ( V_41 -> V_3 ,
L_4 ,
V_111 -> V_29 , V_83 , V_122 ) ;
if ( V_5 -> type == V_125 )
F_25 ( V_3 , V_5 , V_128 ,
V_122 ) ;
if ( F_27 ( V_111 ) ) {
V_41 -> V_138 = true ;
V_41 -> V_139 = V_41 -> V_140 ;
V_41 -> V_140 = V_7 ;
}
if ( V_5 -> type == V_126 ) {
if ( ! V_111 -> V_127 )
return;
if ( V_7 == V_41 -> V_140 )
return;
if ( ! V_41 -> V_138 ) {
V_41 -> V_139 = V_41 -> V_140 ;
V_41 -> V_140 = V_7 ;
} else {
V_41 -> V_139 = V_7 ;
}
return;
}
if ( ! V_41 -> V_140 || V_41 -> V_140 == V_7 )
V_41 -> V_140 = V_7 ;
else if ( ! V_41 -> V_139 )
V_41 -> V_139 = V_7 ;
if ( F_1 ( V_3 , V_5 ) == V_141 ||
V_3 -> V_18 -> V_19 || ! V_5 -> V_134 . V_135 ||
F_5 ( V_3 -> V_22 . V_83 ) == V_142 ) {
F_19 ( V_3 , V_111 -> V_129 , false ) ;
F_22 ( V_3 , V_5 , false , 0 ) ;
return;
}
V_124 = V_111 -> V_112 . V_143 ;
if ( ! V_124 )
V_124 = - 100 ;
if ( V_124 > - V_115 ) {
if ( F_19 ( V_3 , V_111 -> V_129 , true ) )
F_28 ( V_3 , L_5 ) ;
} else if ( V_124 < - V_117 ) {
if ( F_19 ( V_3 , V_111 -> V_129 , false ) )
F_28 ( V_3 , L_5 ) ;
}
F_22 ( V_3 , V_5 , true , V_124 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_120 V_41 = {
. V_3 = V_3 ,
. V_79 = & V_3 -> V_22 ,
} ;
struct V_144 V_28 = {} ;
T_3 V_145 ;
if ( F_10 ( V_3 -> V_43 != V_44 ) )
return;
F_2 () ;
F_30 (
V_3 -> V_146 , V_147 ,
F_24 , & V_41 ) ;
if ( V_41 . V_140 ) {
struct V_6 * V_13 = V_41 . V_140 ;
if ( F_11 ( ! V_13 -> V_12 . V_13 ) ) {
F_4 () ;
return;
}
if ( V_13 -> V_12 . V_148 < V_149 ) {
V_145 = 0 ;
} else {
if ( V_13 -> V_12 . V_150 >
V_13 -> V_12 . V_13 -> V_151 )
V_145 = 2 ;
else
V_145 = 1 ;
}
V_28 . V_152 =
V_153 [ V_13 -> V_12 . V_13 -> V_154 ] [ V_145 ] ;
V_28 . V_10 =
F_12 ( * ( ( T_1 * ) V_41 . V_140 -> V_20 ) ) ;
}
if ( V_41 . V_139 ) {
struct V_6 * V_13 = V_41 . V_139 ;
if ( F_11 ( ! V_41 . V_139 -> V_12 . V_13 ) ) {
F_4 () ;
return;
}
if ( V_13 -> V_12 . V_148 < V_149 ) {
V_145 = 0 ;
} else {
if ( V_13 -> V_12 . V_150 >
V_13 -> V_12 . V_13 -> V_151 )
V_145 = 2 ;
else
V_145 = 1 ;
}
V_28 . V_155 =
V_153 [ V_13 -> V_12 . V_13 -> V_154 ] [ V_145 ] ;
V_28 . V_11 =
F_12 ( * ( ( T_1 * ) V_41 . V_139 -> V_20 ) ) ;
}
F_4 () ;
if ( memcmp ( & V_28 , & V_3 -> V_21 , sizeof( V_28 ) ) ) {
if ( F_18 ( V_3 , V_156 , 0 ,
sizeof( V_28 ) , & V_28 ) )
F_28 ( V_3 , L_6 ) ;
memcpy ( & V_3 -> V_21 , & V_28 , sizeof( V_28 ) ) ;
}
if ( F_15 ( V_3 ) )
F_28 ( V_3 , L_7 ) ;
}
int F_31 ( struct V_2 * V_3 ,
struct V_157 * V_158 ,
struct V_159 * V_160 )
{
struct V_161 * V_162 = F_32 ( V_158 ) ;
struct V_78 * V_79 = ( void * ) V_162 -> V_41 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_33 ( V_3 , V_158 , V_160 ) ;
F_21 ( V_3 , L_8 ) ;
F_21 ( V_3 , L_9 , V_79 -> V_163 ) ;
F_21 ( V_3 , L_10 ,
F_5 ( V_79 -> V_23 ) ) ;
F_21 ( V_3 , L_11 ,
F_5 ( V_79 -> V_24 ) ) ;
F_21 ( V_3 , L_12 ,
F_5 ( V_79 -> V_83 ) ) ;
memcpy ( & V_3 -> V_22 , V_79 , sizeof( V_3 -> V_22 ) ) ;
F_29 ( V_3 ) ;
return 0 ;
}
static void F_34 ( void * V_118 , T_3 * V_119 ,
struct V_4 * V_5 )
{
struct V_110 * V_111 = ( void * ) V_5 -> V_20 ;
struct V_120 * V_41 = V_118 ;
struct V_2 * V_3 = V_41 -> V_3 ;
struct V_164 * V_165 ;
struct V_101 * V_102 ;
struct V_6 * V_7 ;
F_2 () ;
V_7 = F_3 ( V_5 -> V_7 ) ;
if ( ! V_7 ||
V_7 -> V_12 . V_13 -> V_14 != V_15 ) {
F_4 () ;
return;
}
F_4 () ;
if ( V_5 -> type != V_125 ||
V_111 -> V_129 == V_166 )
return;
V_165 = F_35 ( V_3 -> V_167 [ V_111 -> V_129 ] ,
F_36 ( & V_3 -> V_42 ) ) ;
if ( F_37 ( V_165 ) )
return;
V_102 = F_38 ( V_165 ) ;
}
void F_39 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_168 V_169 )
{
struct V_110 * V_111 = ( void * ) V_5 -> V_20 ;
struct V_120 V_41 = {
. V_3 = V_3 ,
} ;
int V_8 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) ) {
F_40 ( V_3 , V_5 , V_169 ) ;
return;
}
F_9 ( & V_3 -> V_42 ) ;
if ( F_10 ( V_3 -> V_43 != V_44 ) )
return;
if ( V_111 -> V_129 == V_166 )
return;
if ( F_5 ( V_3 -> V_22 . V_83 ) == V_142 )
return;
F_21 ( V_3 , L_13 , V_5 -> V_134 . V_170 ,
V_169 == V_171 ? L_14 : L_15 ) ;
if ( V_169 == V_172 || V_3 -> V_18 -> V_19 ||
F_1 ( V_3 , V_5 ) == V_141 )
V_8 = F_19 ( V_3 , V_111 -> V_129 ,
false ) ;
else
V_8 = F_19 ( V_3 , V_111 -> V_129 , true ) ;
if ( V_8 )
F_28 ( V_3 , L_16 ) ;
F_30 (
V_3 -> V_146 , V_147 ,
F_34 , & V_41 ) ;
if ( F_15 ( V_3 ) )
F_28 ( V_3 , L_7 ) ;
}
T_1 F_41 ( struct V_2 * V_3 ,
struct V_164 * V_165 )
{
struct V_101 * V_102 = F_38 ( V_165 ) ;
struct V_110 * V_111 = F_23 ( V_102 -> V_5 ) ;
struct V_173 * V_137 = V_111 -> V_137 ;
enum V_1 V_174 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_42 ( V_3 , V_165 ) ;
if ( F_43 ( V_3 -> V_22 . V_136 , V_137 -> V_29 ) )
return V_175 ;
if ( F_5 ( V_3 -> V_22 . V_83 ) <
V_130 )
return V_175 ;
V_174 = F_1 ( V_3 , V_102 -> V_5 ) ;
if ( V_174 == V_141 || V_174 == V_16 )
return V_175 ;
return V_176 ;
}
bool F_44 ( struct V_2 * V_3 ,
struct V_164 * V_165 )
{
struct V_101 * V_102 = F_38 ( V_165 ) ;
struct V_110 * V_111 = F_23 ( V_102 -> V_5 ) ;
struct V_173 * V_137 = V_111 -> V_137 ;
enum V_1 V_174 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_45 ( V_3 , V_165 ) ;
if ( F_43 ( V_3 -> V_22 . V_136 , V_137 -> V_29 ) )
return true ;
if ( F_5 ( V_3 -> V_22 . V_83 ) <
V_130 )
return true ;
V_174 = F_1 ( V_3 , V_102 -> V_5 ) ;
return V_174 != V_141 ;
}
bool F_46 ( struct V_2 * V_3 , T_3 V_177 )
{
if ( V_3 -> V_18 -> V_19 )
return true ;
if ( V_177 & V_3 -> V_18 -> V_178 )
return true ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_47 ( V_3 ) ;
return F_5 ( V_3 -> V_22 . V_83 ) <
V_130 ;
}
bool F_48 ( struct V_2 * V_3 )
{
if ( V_3 -> V_18 -> V_19 )
return true ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_47 ( V_3 ) ;
return F_5 ( V_3 -> V_22 . V_83 ) == V_142 ;
}
bool F_49 ( struct V_2 * V_3 ,
enum V_179 V_14 )
{
T_2 V_180 = F_5 ( V_3 -> V_22 . V_83 ) ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_50 ( V_3 , V_14 ) ;
if ( V_14 != V_15 )
return false ;
return V_180 >= V_132 ;
}
T_3 F_51 ( struct V_2 * V_3 , struct V_181 * V_182 ,
struct V_183 * V_184 , T_3 V_185 )
{
T_4 V_186 = V_182 -> V_187 ;
if ( V_184 -> V_14 != V_15 )
return 0 ;
if ( F_10 ( V_3 -> V_188 ) )
return V_3 -> V_188 - 1 ;
if ( V_184 -> V_189 . V_190 & V_191 ||
F_52 ( V_182 -> V_192 ) ||
F_53 ( V_186 ) || F_54 ( V_186 ) ||
F_55 ( V_186 ) || F_56 ( V_186 ) )
return 3 ;
switch ( V_185 ) {
case V_193 :
return 1 ;
case V_194 :
return 3 ;
case V_195 :
return 2 ;
default:
break;
}
return 0 ;
}
void F_57 ( struct V_2 * V_3 )
{
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) ) {
F_58 ( V_3 ) ;
return;
}
F_29 ( V_3 ) ;
}
int F_59 ( struct V_2 * V_3 ,
struct V_157 * V_158 ,
struct V_159 * V_160 )
{
struct V_161 * V_162 = F_32 ( V_158 ) ;
T_2 V_196 = F_60 ( ( void * ) V_162 -> V_41 ) ;
struct V_197 V_28 = {} ;
T_3 T_5 V_198 , V_199 ;
T_3 V_200 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_61 ( V_3 , V_158 , V_160 ) ;
if ( ! V_64 )
return 0 ;
F_9 ( & V_3 -> V_42 ) ;
if ( F_10 ( V_3 -> V_43 != V_44 ) )
return 0 ;
if ( V_196 == V_3 -> V_201 )
return 0 ;
for ( V_200 = 0 ; V_200 < F_17 ( V_202 ) - 1 ; V_200 ++ )
if ( V_196 < V_202 [ V_200 + 1 ] . V_203 )
break;
V_198 = V_202 [ V_200 ] . V_203 ;
if ( V_200 < F_17 ( V_202 ) - 1 )
V_199 = V_202 [ V_200 + 1 ] . V_203 ;
else
V_199 = V_202 [ V_200 ] . V_203 ;
F_21 ( V_3 , L_17 ,
V_196 , V_198 , V_199 , V_200 ) ;
V_3 -> V_201 = V_196 ;
if ( V_3 -> V_204 == V_200 )
return 0 ;
V_3 -> V_204 = V_200 ;
memcpy ( & V_28 . V_205 , V_202 [ V_200 ] . V_206 ,
sizeof( V_28 . V_205 ) ) ;
memcpy ( & V_28 . V_207 , V_202 [ V_200 ] . V_206 ,
sizeof( V_28 . V_207 ) ) ;
return F_18 ( V_3 , V_208 , 0 ,
sizeof( V_28 ) , & V_28 ) ;
}
