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
memcpy ( & V_26 -> V_75 , V_76 ,
sizeof( V_76 ) ) ;
V_49:
memset ( & V_3 -> V_22 , 0 , sizeof( V_3 -> V_22 ) ) ;
memset ( & V_3 -> V_21 , 0 , sizeof( V_3 -> V_21 ) ) ;
V_8 = F_13 ( V_3 , & V_28 ) ;
F_14 ( V_26 ) ;
return V_8 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_77 * V_78 = & V_3 -> V_22 ;
T_2 V_79 = F_5 ( V_78 -> V_23 ) ;
T_2 V_80 = F_5 ( V_78 -> V_24 ) ;
T_2 V_81 = F_5 ( V_78 -> V_82 ) ;
struct V_83 V_28 = {} ;
T_3 V_84 [ V_85 ] = {} ;
T_3 V_86 [ V_85 ] = {} ;
int V_87 ;
F_9 ( & V_3 -> V_42 ) ;
V_84 [ 0 ] = V_88 [ V_81 ] [ V_79 ] ;
V_86 [ 0 ] = V_89 [ V_81 ] [ V_79 ] ;
V_84 [ 1 ] = V_88 [ V_81 ] [ V_80 ] ;
V_86 [ 1 ] = V_89 [ V_81 ] [ V_80 ] ;
if ( ! memcmp ( V_84 , V_3 -> V_90 , sizeof( V_84 ) ) ||
! memcmp ( V_86 , V_3 -> V_91 , sizeof( V_86 ) ) )
return 0 ;
memcpy ( V_3 -> V_90 , V_84 ,
sizeof( V_3 -> V_90 ) ) ;
memcpy ( V_3 -> V_91 , V_86 ,
sizeof( V_3 -> V_91 ) ) ;
F_16 ( F_17 ( V_84 ) < F_17 ( V_28 . V_92 ) ) ;
for ( V_87 = 0 ; V_87 < F_17 ( V_28 . V_92 ) ; V_87 ++ ) {
V_28 . V_92 [ V_87 ] . V_93 =
F_12 ( V_94 [ V_84 [ V_87 ] ] ) ;
V_28 . V_92 [ V_87 ] . V_95 =
F_12 ( V_94 [ V_86 [ V_87 ] ] ) ;
}
return F_18 ( V_3 , V_96 , 0 ,
sizeof( V_28 ) , & V_28 ) ;
}
static int F_19 ( struct V_2 * V_3 , T_3 V_97 ,
bool V_98 )
{
struct V_99 V_28 = {} ;
struct V_100 * V_101 ;
T_2 V_102 ;
int V_8 ;
V_101 = F_20 ( V_3 , V_97 ) ;
if ( ! V_101 )
return 0 ;
if ( V_101 -> V_103 == V_98 )
return 0 ;
V_102 = V_101 -> V_97 ;
if ( V_98 )
V_102 |= V_104 ;
F_21 ( V_3 , L_1 ,
V_98 ? L_2 : L_3 , V_97 ) ;
V_28 . V_105 = F_12 ( V_102 ) ;
V_101 -> V_103 = V_98 ;
V_8 = F_18 ( V_3 , V_106 , V_107 ,
sizeof( V_28 ) , & V_28 ) ;
return V_8 ;
}
static inline
void F_22 ( struct V_2 * V_3 ,
struct V_4 * V_5 ,
bool V_98 , int V_108 )
{
struct V_109 * V_110 = F_23 ( V_5 ) ;
V_110 -> V_111 . V_112 = V_108 ;
V_110 -> V_111 . V_113 =
V_98 ? - V_114 : 0 ;
V_110 -> V_111 . V_115 =
V_98 ? - V_116 : 0 ;
}
static void F_24 ( void * V_117 , T_3 * V_118 ,
struct V_4 * V_5 )
{
struct V_109 * V_110 = F_23 ( V_5 ) ;
struct V_119 * V_41 = V_117 ;
struct V_2 * V_3 = V_41 -> V_3 ;
struct V_6 * V_7 ;
enum V_120 V_121 = V_122 ;
T_2 V_82 ;
int V_123 ;
F_9 ( & V_3 -> V_42 ) ;
switch ( V_5 -> type ) {
case V_124 :
break;
case V_125 :
if ( ! V_110 -> V_126 )
return;
break;
default:
return;
}
V_7 = F_3 ( V_5 -> V_7 ) ;
if ( ( ! V_7 ||
V_7 -> V_12 . V_13 -> V_14 != V_15 ) ) {
if ( V_5 -> type == V_124 ) {
F_25 ( V_3 , V_5 , V_127 ,
V_121 ) ;
F_19 ( V_3 , V_110 -> V_128 ,
false ) ;
F_22 ( V_3 , V_5 , false , 0 ) ;
}
return;
}
V_82 = F_5 ( V_41 -> V_78 -> V_82 ) ;
if ( V_82 >= V_129 )
V_121 = V_130 ;
else if ( V_82 >= V_131 )
V_121 = V_132 ;
if ( ! V_5 -> V_133 . V_134 )
V_121 = V_122 ;
if ( F_26 ( V_3 -> V_22 . V_135 ,
V_110 -> V_136 -> V_29 ) )
V_121 = V_122 ;
F_21 ( V_41 -> V_3 ,
L_4 ,
V_110 -> V_29 , V_82 , V_121 ) ;
if ( V_5 -> type == V_124 )
F_25 ( V_3 , V_5 , V_127 ,
V_121 ) ;
if ( F_27 ( V_110 ) ) {
V_41 -> V_137 = true ;
V_41 -> V_138 = V_41 -> V_139 ;
V_41 -> V_139 = V_7 ;
}
if ( V_5 -> type == V_125 ) {
if ( ! V_110 -> V_126 )
return;
if ( V_7 == V_41 -> V_139 )
return;
if ( ! V_41 -> V_137 ) {
V_41 -> V_138 = V_41 -> V_139 ;
V_41 -> V_139 = V_7 ;
} else {
V_41 -> V_138 = V_7 ;
}
return;
}
if ( ! V_41 -> V_139 || V_41 -> V_139 == V_7 )
V_41 -> V_139 = V_7 ;
else if ( ! V_41 -> V_138 )
V_41 -> V_138 = V_7 ;
if ( F_1 ( V_3 , V_5 ) == V_140 ||
V_3 -> V_18 -> V_19 || ! V_5 -> V_133 . V_134 ||
F_5 ( V_3 -> V_22 . V_82 ) == V_141 ) {
F_19 ( V_3 , V_110 -> V_128 , false ) ;
F_22 ( V_3 , V_5 , false , 0 ) ;
return;
}
V_123 = V_110 -> V_111 . V_142 ;
if ( ! V_123 )
V_123 = - 100 ;
if ( V_123 > - V_114 ) {
if ( F_19 ( V_3 , V_110 -> V_128 , true ) )
F_28 ( V_3 , L_5 ) ;
} else if ( V_123 < - V_116 ) {
if ( F_19 ( V_3 , V_110 -> V_128 , false ) )
F_28 ( V_3 , L_5 ) ;
}
F_22 ( V_3 , V_5 , true , V_123 ) ;
}
static void F_29 ( struct V_2 * V_3 )
{
struct V_119 V_41 = {
. V_3 = V_3 ,
. V_78 = & V_3 -> V_22 ,
} ;
struct V_143 V_28 = {} ;
T_3 V_144 ;
if ( F_10 ( V_3 -> V_43 != V_44 ) )
return;
F_2 () ;
F_30 (
V_3 -> V_145 , V_146 ,
F_24 , & V_41 ) ;
if ( V_41 . V_139 ) {
struct V_6 * V_13 = V_41 . V_139 ;
if ( F_11 ( ! V_13 -> V_12 . V_13 ) ) {
F_4 () ;
return;
}
if ( V_13 -> V_12 . V_147 < V_148 ) {
V_144 = 0 ;
} else {
if ( V_13 -> V_12 . V_149 >
V_13 -> V_12 . V_13 -> V_150 )
V_144 = 2 ;
else
V_144 = 1 ;
}
V_28 . V_151 =
V_152 [ V_13 -> V_12 . V_13 -> V_153 ] [ V_144 ] ;
V_28 . V_10 =
F_12 ( * ( ( T_1 * ) V_41 . V_139 -> V_20 ) ) ;
}
if ( V_41 . V_138 ) {
struct V_6 * V_13 = V_41 . V_138 ;
if ( F_11 ( ! V_41 . V_138 -> V_12 . V_13 ) ) {
F_4 () ;
return;
}
if ( V_13 -> V_12 . V_147 < V_148 ) {
V_144 = 0 ;
} else {
if ( V_13 -> V_12 . V_149 >
V_13 -> V_12 . V_13 -> V_150 )
V_144 = 2 ;
else
V_144 = 1 ;
}
V_28 . V_154 =
V_152 [ V_13 -> V_12 . V_13 -> V_153 ] [ V_144 ] ;
V_28 . V_11 =
F_12 ( * ( ( T_1 * ) V_41 . V_138 -> V_20 ) ) ;
}
F_4 () ;
if ( memcmp ( & V_28 , & V_3 -> V_21 , sizeof( V_28 ) ) ) {
if ( F_18 ( V_3 , V_155 , 0 ,
sizeof( V_28 ) , & V_28 ) )
F_28 ( V_3 , L_6 ) ;
memcpy ( & V_3 -> V_21 , & V_28 , sizeof( V_28 ) ) ;
}
if ( F_15 ( V_3 ) )
F_28 ( V_3 , L_7 ) ;
}
int F_31 ( struct V_2 * V_3 ,
struct V_156 * V_157 ,
struct V_158 * V_159 )
{
struct V_160 * V_161 = F_32 ( V_157 ) ;
struct V_77 * V_78 = ( void * ) V_161 -> V_41 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_33 ( V_3 , V_157 , V_159 ) ;
F_21 ( V_3 , L_8 ) ;
F_21 ( V_3 , L_9 , V_78 -> V_162 ) ;
F_21 ( V_3 , L_10 ,
F_5 ( V_78 -> V_23 ) ) ;
F_21 ( V_3 , L_11 ,
F_5 ( V_78 -> V_24 ) ) ;
F_21 ( V_3 , L_12 ,
F_5 ( V_78 -> V_82 ) ) ;
memcpy ( & V_3 -> V_22 , V_78 , sizeof( V_3 -> V_22 ) ) ;
F_29 ( V_3 ) ;
return 0 ;
}
static void F_34 ( void * V_117 , T_3 * V_118 ,
struct V_4 * V_5 )
{
struct V_109 * V_110 = ( void * ) V_5 -> V_20 ;
struct V_119 * V_41 = V_117 ;
struct V_2 * V_3 = V_41 -> V_3 ;
struct V_163 * V_164 ;
struct V_100 * V_101 ;
struct V_6 * V_7 ;
F_2 () ;
V_7 = F_3 ( V_5 -> V_7 ) ;
if ( ! V_7 ||
V_7 -> V_12 . V_13 -> V_14 != V_15 ) {
F_4 () ;
return;
}
F_4 () ;
if ( V_5 -> type != V_124 ||
V_110 -> V_128 == V_165 )
return;
V_164 = F_35 ( V_3 -> V_166 [ V_110 -> V_128 ] ,
F_36 ( & V_3 -> V_42 ) ) ;
if ( F_37 ( V_164 ) )
return;
V_101 = F_38 ( V_164 ) ;
}
void F_39 ( struct V_2 * V_3 , struct V_4 * V_5 ,
enum V_167 V_168 )
{
struct V_109 * V_110 = ( void * ) V_5 -> V_20 ;
struct V_119 V_41 = {
. V_3 = V_3 ,
} ;
int V_8 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) ) {
F_40 ( V_3 , V_5 , V_168 ) ;
return;
}
F_9 ( & V_3 -> V_42 ) ;
if ( F_10 ( V_3 -> V_43 != V_44 ) )
return;
if ( V_110 -> V_128 == V_165 )
return;
if ( F_5 ( V_3 -> V_22 . V_82 ) == V_141 )
return;
F_21 ( V_3 , L_13 , V_5 -> V_133 . V_169 ,
V_168 == V_170 ? L_14 : L_15 ) ;
if ( V_168 == V_171 || V_3 -> V_18 -> V_19 ||
F_1 ( V_3 , V_5 ) == V_140 )
V_8 = F_19 ( V_3 , V_110 -> V_128 ,
false ) ;
else
V_8 = F_19 ( V_3 , V_110 -> V_128 , true ) ;
if ( V_8 )
F_28 ( V_3 , L_16 ) ;
F_30 (
V_3 -> V_145 , V_146 ,
F_34 , & V_41 ) ;
if ( F_15 ( V_3 ) )
F_28 ( V_3 , L_7 ) ;
}
T_1 F_41 ( struct V_2 * V_3 ,
struct V_163 * V_164 )
{
struct V_100 * V_101 = F_38 ( V_164 ) ;
struct V_109 * V_110 = F_23 ( V_101 -> V_5 ) ;
struct V_172 * V_136 = V_110 -> V_136 ;
enum V_1 V_173 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_42 ( V_3 , V_164 ) ;
if ( F_43 ( V_3 -> V_22 . V_135 , V_136 -> V_29 ) )
return V_174 ;
if ( F_5 ( V_3 -> V_22 . V_82 ) <
V_129 )
return V_174 ;
V_173 = F_1 ( V_3 , V_101 -> V_5 ) ;
if ( V_173 == V_140 || V_173 == V_16 )
return V_174 ;
return V_175 ;
}
bool F_44 ( struct V_2 * V_3 ,
struct V_163 * V_164 )
{
struct V_100 * V_101 = F_38 ( V_164 ) ;
struct V_109 * V_110 = F_23 ( V_101 -> V_5 ) ;
struct V_172 * V_136 = V_110 -> V_136 ;
enum V_1 V_173 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_45 ( V_3 , V_164 ) ;
if ( F_43 ( V_3 -> V_22 . V_135 , V_136 -> V_29 ) )
return true ;
if ( F_5 ( V_3 -> V_22 . V_82 ) <
V_129 )
return true ;
V_173 = F_1 ( V_3 , V_101 -> V_5 ) ;
return V_173 != V_140 ;
}
bool F_46 ( struct V_2 * V_3 )
{
if ( V_3 -> V_18 -> V_19 )
return true ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_47 ( V_3 ) ;
return F_5 ( V_3 -> V_22 . V_82 ) == V_141 ;
}
bool F_48 ( struct V_2 * V_3 ,
enum V_176 V_14 )
{
T_2 V_177 = F_5 ( V_3 -> V_22 . V_82 ) ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_49 ( V_3 , V_14 ) ;
if ( V_14 != V_15 )
return false ;
return V_177 >= V_131 ;
}
T_3 F_50 ( struct V_2 * V_3 , struct V_178 * V_179 ,
struct V_180 * V_181 , T_3 V_182 )
{
T_4 V_183 = V_179 -> V_184 ;
if ( V_181 -> V_14 != V_15 )
return 0 ;
if ( F_10 ( V_3 -> V_185 ) )
return V_3 -> V_185 - 1 ;
if ( V_181 -> V_186 . V_187 & V_188 ||
F_51 ( V_179 -> V_189 ) ||
F_52 ( V_183 ) || F_53 ( V_183 ) ||
F_54 ( V_183 ) || F_55 ( V_183 ) )
return 3 ;
switch ( V_182 ) {
case V_190 :
return 1 ;
case V_191 :
return 3 ;
case V_192 :
return 2 ;
default:
break;
}
return 0 ;
}
void F_56 ( struct V_2 * V_3 )
{
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) ) {
F_57 ( V_3 ) ;
return;
}
F_29 ( V_3 ) ;
}
int F_58 ( struct V_2 * V_3 ,
struct V_156 * V_157 ,
struct V_158 * V_159 )
{
struct V_160 * V_161 = F_32 ( V_157 ) ;
T_2 V_193 = F_59 ( ( void * ) V_161 -> V_41 ) ;
struct V_194 V_28 = {} ;
T_3 T_5 V_195 , V_196 ;
T_3 V_197 ;
if ( ! ( V_3 -> V_35 -> V_36 . V_37 [ 0 ] & V_38 ) )
return F_60 ( V_3 , V_157 , V_159 ) ;
if ( ! V_64 )
return 0 ;
F_9 ( & V_3 -> V_42 ) ;
if ( F_10 ( V_3 -> V_43 != V_44 ) )
return 0 ;
if ( V_193 == V_3 -> V_198 )
return 0 ;
for ( V_197 = 0 ; V_197 < F_17 ( V_199 ) - 1 ; V_197 ++ )
if ( V_193 < V_199 [ V_197 + 1 ] . V_200 )
break;
V_195 = V_199 [ V_197 ] . V_200 ;
if ( V_197 < F_17 ( V_199 ) - 1 )
V_196 = V_199 [ V_197 + 1 ] . V_200 ;
else
V_196 = V_199 [ V_197 ] . V_200 ;
F_21 ( V_3 , L_17 ,
V_193 , V_195 , V_196 , V_197 ) ;
V_3 -> V_198 = V_193 ;
if ( V_3 -> V_201 == V_197 )
return 0 ;
V_3 -> V_201 = V_197 ;
memcpy ( & V_28 . V_202 , V_199 [ V_197 ] . V_203 ,
sizeof( V_28 . V_202 ) ) ;
memcpy ( & V_28 . V_204 , V_199 [ V_197 ] . V_203 ,
sizeof( V_28 . V_204 ) ) ;
return F_18 ( V_3 , V_205 , 0 ,
sizeof( V_28 ) , & V_28 ) ;
}
