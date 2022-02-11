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
V_31 -> V_54 = V_55 ;
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
V_79 ) ;
if ( V_80 )
V_31 -> V_39 |= F_13 ( V_81 ) ;
if ( V_82 ) {
V_31 -> V_50 |= F_13 ( V_83 |
V_84 ) ;
V_31 -> V_39 |= F_13 ( V_85 ) ;
}
if ( V_86 ) {
V_31 -> V_39 |= F_13 ( V_87 ) ;
V_31 -> V_50 |= F_13 ( V_88 ) ;
}
if ( V_2 -> V_21 -> V_22 )
memcpy ( & V_31 -> V_89 , V_90 ,
sizeof( V_90 ) ) ;
else
memcpy ( & V_31 -> V_89 , V_91 ,
sizeof( V_91 ) ) ;
memcpy ( V_31 -> V_92 , V_93 [ 0 ] . V_94 ,
sizeof( V_31 -> V_92 ) ) ;
memcpy ( V_31 -> V_95 , V_93 [ 0 ] . V_94 ,
sizeof( V_31 -> V_95 ) ) ;
memcpy ( & V_31 -> V_96 , V_97 ,
sizeof( V_97 ) ) ;
memcpy ( & V_31 -> V_98 , V_99 ,
sizeof( V_99 ) ) ;
V_52:
memset ( & V_2 -> V_26 , 0 , sizeof( V_2 -> V_26 ) ) ;
memset ( & V_2 -> V_24 , 0 , sizeof( V_2 -> V_24 ) ) ;
V_13 = F_14 ( V_2 , & V_33 ) ;
F_15 ( V_31 ) ;
return V_13 ;
}
static int F_16 ( struct V_1 * V_2 )
{
struct V_100 * V_101 = & V_2 -> V_26 ;
T_2 V_102 = F_8 ( V_101 -> V_27 ) ;
T_2 V_103 = F_8 ( V_101 -> V_104 ) ;
struct V_30 * V_31 ;
T_3 V_105 , V_106 ;
struct V_32 V_33 = {
. V_34 = V_35 ,
. V_42 [ 0 ] = & V_31 ,
. V_36 = { sizeof( * V_31 ) , } ,
. V_37 = { V_38 , } ,
} ;
int V_13 = 0 ;
F_11 ( & V_2 -> V_43 ) ;
V_105 = V_107 [ V_103 ] [ V_102 ] ;
V_106 = V_108 [ V_103 ] [ V_102 ] ;
if ( V_2 -> V_109 [ 0 ] == V_105 &&
V_2 -> V_110 [ 0 ] == V_106 )
return 0 ;
V_2 -> V_109 [ 0 ] = V_105 ;
V_2 -> V_110 [ 0 ] = V_106 ;
V_31 = F_10 ( sizeof( * V_31 ) , V_40 ) ;
if ( ! V_31 )
return - V_41 ;
V_33 . V_42 [ 0 ] = V_31 ;
V_31 -> V_39 = F_13 ( V_64 ) ;
V_31 -> V_111 = F_13 ( V_112 [ V_105 ] ) ;
V_31 -> V_113 = F_13 ( V_112 [ V_106 ] ) ;
V_31 -> V_50 |= F_13 ( V_51 |
V_69 |
V_70 ) ;
V_13 = F_14 ( V_2 , & V_33 ) ;
F_15 ( V_31 ) ;
return V_13 ;
}
static int F_17 ( struct V_1 * V_2 , T_3 V_114 ,
bool V_115 )
{
struct V_30 * V_31 ;
struct V_32 V_33 = {
. V_34 = V_35 ,
. V_36 = { sizeof( * V_31 ) , } ,
. V_37 = { V_38 , } ,
. V_39 = V_116 ,
} ;
struct V_117 * V_118 ;
int V_13 ;
V_118 = F_18 ( V_2 , V_114 ) ;
if ( ! V_118 )
return 0 ;
if ( V_118 -> V_119 == V_115 )
return 0 ;
V_31 = F_10 ( sizeof( * V_31 ) , V_120 ) ;
if ( ! V_31 )
return - V_41 ;
V_33 . V_42 [ 0 ] = V_31 ;
V_31 -> V_39 = F_13 ( V_64 ) ;
V_31 -> V_50 =
F_13 ( V_51 | V_71 ) ;
V_31 -> V_121 = V_114 ;
if ( V_115 )
V_31 -> V_121 |= V_122 ;
F_19 ( V_2 , L_1 ,
V_115 ? L_2 : L_3 , V_114 ) ;
V_118 -> V_119 = V_115 ;
V_13 = F_14 ( V_2 , & V_33 ) ;
F_15 ( V_31 ) ;
return V_13 ;
}
static inline
void F_20 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
bool V_115 , int V_123 )
{
struct V_124 * V_125 = F_21 ( V_10 ) ;
V_125 -> V_126 . V_127 = V_123 ;
V_125 -> V_126 . V_128 =
V_115 ? - V_129 : 0 ;
V_125 -> V_126 . V_130 =
V_115 ? - V_131 : 0 ;
}
static void F_22 ( void * V_132 , T_3 * V_133 ,
struct V_9 * V_10 )
{
struct V_124 * V_125 = F_21 ( V_10 ) ;
struct V_134 * V_42 = V_132 ;
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_11 * V_12 ;
enum V_135 V_136 ;
T_2 V_104 ;
int V_137 ;
F_11 ( & V_2 -> V_43 ) ;
switch ( V_10 -> type ) {
case V_138 :
V_136 = V_139 ;
break;
case V_140 :
if ( ! V_125 -> V_141 )
return;
break;
default:
return;
}
V_12 = F_6 ( V_10 -> V_12 ) ;
if ( ( ! V_12 ||
V_12 -> V_15 . V_16 -> V_17 != V_18 ) ) {
if ( V_10 -> type == V_138 ) {
F_23 ( V_2 , V_10 , V_142 ,
V_136 ) ;
F_17 ( V_2 , V_125 -> V_143 ,
false ) ;
F_20 ( V_2 , V_10 , false , 0 ) ;
}
return;
}
V_104 = F_8 ( V_42 -> V_101 -> V_104 ) ;
if ( V_104 >= V_144 )
V_136 = V_145 ;
else if ( V_104 >= V_146 )
V_136 = V_10 -> type == V_140 ?
V_147 :
V_148 ;
if ( ! V_10 -> V_149 . V_150 )
V_136 = V_139 ;
F_19 ( V_42 -> V_2 ,
L_4 ,
V_125 -> V_34 , V_42 -> V_101 -> V_151 , V_104 ,
V_136 ) ;
if ( V_10 -> type == V_138 )
F_23 ( V_2 , V_10 , V_142 ,
V_136 ) ;
if ( F_24 ( V_125 ) ) {
V_42 -> V_152 = true ;
V_42 -> V_153 = V_42 -> V_154 ;
V_42 -> V_154 = V_12 ;
}
if ( V_10 -> type == V_140 ) {
if ( ! V_125 -> V_141 )
return;
if ( V_12 == V_42 -> V_154 )
return;
if ( ! V_42 -> V_152 ) {
V_42 -> V_153 = V_42 -> V_154 ;
V_42 -> V_154 = V_12 ;
} else {
V_42 -> V_153 = V_12 ;
}
return;
}
if ( ! V_42 -> V_154 || V_42 -> V_154 == V_12 )
V_42 -> V_154 = V_12 ;
else if ( ! V_42 -> V_153 )
V_42 -> V_153 = V_12 ;
if ( F_4 ( V_2 , V_10 ) == V_155 ||
V_2 -> V_21 -> V_22 || ! V_10 -> V_149 . V_150 ||
! V_42 -> V_101 -> V_151 ) {
F_17 ( V_2 , V_125 -> V_143 , false ) ;
F_20 ( V_2 , V_10 , false , 0 ) ;
return;
}
V_137 = V_125 -> V_126 . V_156 ;
if ( ! V_137 )
V_137 = - 100 ;
if ( V_137 > - V_129 ) {
if ( F_17 ( V_2 , V_125 -> V_143 , true ) )
F_25 ( V_2 , L_5 ) ;
} else if ( V_137 < - V_131 ) {
if ( F_17 ( V_2 , V_125 -> V_143 , false ) )
F_25 ( V_2 , L_5 ) ;
}
F_20 ( V_2 , V_10 , true , V_137 ) ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_134 V_42 = {
. V_2 = V_2 ,
. V_101 = & V_2 -> V_26 ,
} ;
struct V_157 V_33 = {} ;
T_3 V_158 ;
if ( F_2 ( V_2 -> V_3 != V_4 ) )
return;
F_5 () ;
F_27 (
V_2 -> V_159 , V_160 ,
F_22 , & V_42 ) ;
if ( V_42 . V_154 ) {
struct V_11 * V_16 = V_42 . V_154 ;
if ( F_12 ( ! V_16 -> V_15 . V_16 ) ) {
F_7 () ;
return;
}
if ( V_16 -> V_15 . V_161 < V_162 ) {
V_158 = 0 ;
V_33 . V_163 = 0 ;
} else {
V_33 . V_163 = 1 ;
if ( V_16 -> V_15 . V_164 >
V_16 -> V_15 . V_16 -> V_165 )
V_158 = 2 ;
else
V_158 = 1 ;
}
V_33 . V_166 =
V_167 [ V_16 -> V_15 . V_16 -> V_168 ] [ V_158 ] ;
V_33 . V_25 = * ( ( T_1 * ) V_42 . V_154 -> V_23 ) ;
}
if ( V_42 . V_153 ) {
struct V_11 * V_16 = V_42 . V_153 ;
if ( F_12 ( ! V_42 . V_153 -> V_15 . V_16 ) ) {
F_7 () ;
return;
}
if ( V_16 -> V_15 . V_161 < V_162 ) {
V_158 = 0 ;
V_33 . V_169 = 0 ;
} else {
V_33 . V_169 = 1 ;
if ( V_16 -> V_15 . V_164 >
V_16 -> V_15 . V_16 -> V_165 )
V_158 = 2 ;
else
V_158 = 1 ;
}
V_33 . V_170 =
V_167 [ V_16 -> V_15 . V_16 -> V_168 ] [ V_158 ] ;
V_33 . V_28 = * ( ( T_1 * ) V_42 . V_153 -> V_23 ) ;
}
F_7 () ;
if ( memcmp ( & V_33 , & V_2 -> V_24 , sizeof( V_33 ) ) ) {
if ( F_3 ( V_2 , V_171 , 0 ,
sizeof( V_33 ) , & V_33 ) )
F_25 ( V_2 , L_6 ) ;
memcpy ( & V_2 -> V_24 , & V_33 , sizeof( V_33 ) ) ;
}
if ( F_16 ( V_2 ) )
F_25 ( V_2 , L_7 ) ;
}
int F_28 ( struct V_1 * V_2 ,
struct V_172 * V_173 ,
struct V_174 * V_175 )
{
struct V_176 * V_177 = F_29 ( V_173 ) ;
struct V_100 * V_101 = ( void * ) V_177 -> V_42 ;
F_19 ( V_2 , L_8 ) ;
F_19 ( V_2 , L_9 ,
V_101 -> V_151 ? L_10 : L_11 ) ;
F_19 ( V_2 , L_12 , V_101 -> V_178 ) ;
F_19 ( V_2 , L_13 , V_101 -> V_179 ) ;
F_19 ( V_2 , L_14 ,
F_8 ( V_101 -> V_27 ) ) ;
F_19 ( V_2 , L_15 ,
F_8 ( V_101 -> V_29 ) ) ;
F_19 ( V_2 , L_16 ,
F_8 ( V_101 -> V_104 ) ) ;
F_19 ( V_2 , L_17 ,
V_101 -> V_180 ) ;
memcpy ( & V_2 -> V_26 , V_101 , sizeof( V_2 -> V_26 ) ) ;
F_26 ( V_2 ) ;
return 0 ;
}
static void F_30 ( void * V_132 , T_3 * V_133 ,
struct V_9 * V_10 )
{
struct V_124 * V_125 = ( void * ) V_10 -> V_23 ;
struct V_134 * V_42 = V_132 ;
struct V_1 * V_2 = V_42 -> V_2 ;
struct V_181 * V_182 ;
struct V_117 * V_118 ;
struct V_11 * V_12 ;
F_5 () ;
V_12 = F_6 ( V_10 -> V_12 ) ;
if ( ! V_12 ||
V_12 -> V_15 . V_16 -> V_17 != V_18 ) {
F_7 () ;
return;
}
F_7 () ;
if ( V_10 -> type != V_138 ||
V_125 -> V_143 == V_183 )
return;
V_182 = F_31 ( V_2 -> V_184 [ V_125 -> V_143 ] ,
F_32 ( & V_2 -> V_43 ) ) ;
if ( F_33 ( V_182 ) )
return;
V_118 = F_34 ( V_182 ) ;
}
void F_35 ( struct V_1 * V_2 , struct V_9 * V_10 ,
enum V_185 V_186 )
{
struct V_124 * V_125 = ( void * ) V_10 -> V_23 ;
struct V_134 V_42 = {
. V_2 = V_2 ,
} ;
int V_13 ;
F_11 ( & V_2 -> V_43 ) ;
if ( F_2 ( V_2 -> V_3 != V_4 ) )
return;
if ( V_125 -> V_143 == V_183 )
return;
if ( ! V_2 -> V_26 . V_151 )
return;
F_19 ( V_2 , L_18 , V_10 -> V_149 . V_187 ,
V_186 == V_188 ? L_19 : L_20 ) ;
if ( V_186 == V_189 || V_2 -> V_21 -> V_22 ||
F_4 ( V_2 , V_10 ) == V_155 )
V_13 = F_17 ( V_2 , V_125 -> V_143 ,
false ) ;
else
V_13 = F_17 ( V_2 , V_125 -> V_143 , true ) ;
if ( V_13 )
F_25 ( V_2 , L_21 ) ;
F_27 (
V_2 -> V_159 , V_160 ,
F_30 , & V_42 ) ;
if ( F_16 ( V_2 ) )
F_25 ( V_2 , L_7 ) ;
}
T_1 F_36 ( struct V_1 * V_2 ,
struct V_181 * V_182 )
{
struct V_117 * V_118 = F_34 ( V_182 ) ;
enum V_8 V_190 ;
if ( F_8 ( V_2 -> V_26 . V_104 ) <
V_144 )
return V_191 ;
if ( V_2 -> V_26 . V_192 )
return V_191 ;
V_190 = F_4 ( V_2 , V_118 -> V_10 ) ;
if ( V_190 == V_155 || V_190 == V_19 )
return V_191 ;
return V_193 ;
}
bool F_37 ( struct V_1 * V_2 ,
struct V_181 * V_182 )
{
struct V_117 * V_118 = F_34 ( V_182 ) ;
enum V_8 V_190 ;
if ( V_2 -> V_26 . V_192 )
return true ;
if ( F_8 ( V_2 -> V_26 . V_104 ) <
V_144 )
return true ;
V_190 = F_4 ( V_2 , V_118 -> V_10 ) ;
return V_190 != V_155 ;
}
bool F_38 ( struct V_1 * V_2 )
{
T_2 V_103 = F_8 ( V_2 -> V_26 . V_104 ) ;
return V_103 == V_194 ;
}
bool F_39 ( struct V_1 * V_2 ,
enum V_195 V_17 )
{
T_2 V_196 =
F_8 ( V_2 -> V_26 . V_104 ) ;
if ( V_17 != V_18 )
return false ;
return V_196 >= V_146 ;
}
void F_40 ( struct V_1 * V_2 )
{
F_26 ( V_2 ) ;
}
int F_41 ( struct V_1 * V_2 ,
struct V_172 * V_173 ,
struct V_174 * V_175 )
{
struct V_176 * V_177 = F_29 ( V_173 ) ;
T_2 V_197 = F_42 ( ( void * ) V_177 -> V_42 ) ;
T_3 T_4 V_198 , V_199 ;
int V_13 ;
T_3 V_200 ;
struct V_30 * V_31 ;
struct V_32 V_33 = {
. V_34 = V_35 ,
. V_36 = { sizeof( * V_31 ) , } ,
. V_37 = { V_38 , } ,
} ;
if ( ! V_82 )
return 0 ;
F_11 ( & V_2 -> V_43 ) ;
if ( F_2 ( V_2 -> V_3 != V_4 ) )
return 0 ;
if ( V_197 == V_2 -> V_201 )
return 0 ;
for ( V_200 = 0 ; V_200 < F_43 ( V_93 ) - 1 ; V_200 ++ )
if ( V_197 < V_93 [ V_200 + 1 ] . V_202 )
break;
V_198 = V_93 [ V_200 ] . V_202 ;
if ( V_200 < F_43 ( V_93 ) - 1 )
V_199 = V_93 [ V_200 + 1 ] . V_202 ;
else
V_199 = V_93 [ V_200 ] . V_202 ;
F_19 ( V_2 , L_22 ,
V_197 , V_198 , V_199 , V_200 ) ;
V_2 -> V_201 = V_197 ;
if ( V_2 -> V_203 == V_200 )
return 0 ;
V_2 -> V_203 = V_200 ;
V_31 = F_10 ( sizeof( * V_31 ) , V_40 ) ;
if ( ! V_31 )
return 0 ;
V_33 . V_42 [ 0 ] = V_31 ;
V_31 -> V_39 = F_13 ( V_64 ) ;
V_31 -> V_50 |= F_13 ( V_51 |
V_83 |
V_84 ) ;
memcpy ( V_31 -> V_92 , V_93 [ V_200 ] . V_94 ,
sizeof( V_31 -> V_92 ) ) ;
memcpy ( V_31 -> V_95 , V_93 [ V_200 ] . V_94 ,
sizeof( V_31 -> V_95 ) ) ;
V_13 = F_14 ( V_2 , & V_33 ) ;
F_15 ( V_31 ) ;
return V_13 ;
}
