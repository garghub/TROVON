static T_1 F_1 ( unsigned int V_1 , T_1 V_2 , T_1 V_3 )
{
T_1 V_4 , V_5 , V_6 ;
T_1 V_7 , V_8 , V_9 ;
T_1 V_10 ;
V_4 = F_2 ( V_2 , 128 ) ;
V_5 = F_2 ( V_2 , 128 ) ;
V_7 = F_2 ( V_3 , 32 ) ;
V_8 = F_2 ( ( ( V_3 + 1 ) >> 1 ) , 16 ) ;
V_6 = V_4 * V_7 ;
V_9 = V_5 * V_8 + V_11 ;
V_10 = V_6 + V_9 + V_12 ;
return F_2 ( V_10 , V_11 ) ;
}
static T_1 F_3 ( unsigned int V_2 , unsigned int V_3 )
{
return ( ( V_2 * V_3 * 3 / 2 ) / 2 ) + 128 ;
}
static const struct V_13 *
F_4 ( struct V_14 * V_15 , T_1 V_16 , T_1 type )
{
const struct V_13 * V_17 = V_18 ;
unsigned int V_10 = F_5 ( V_18 ) ;
unsigned int V_19 ;
for ( V_19 = 0 ; V_19 < V_10 ; V_19 ++ ) {
if ( V_17 [ V_19 ] . V_16 == V_16 )
break;
}
if ( V_19 == V_10 || V_17 [ V_19 ] . type != type )
return NULL ;
if ( type == V_20 &&
! F_6 ( V_15 , V_17 [ V_19 ] . V_16 ) )
return NULL ;
return & V_17 [ V_19 ] ;
}
static const struct V_13 *
F_7 ( struct V_14 * V_15 , unsigned int V_21 , T_1 type )
{
const struct V_13 * V_17 = V_18 ;
unsigned int V_10 = F_5 ( V_18 ) ;
unsigned int V_19 , V_22 = 0 ;
if ( V_21 > V_10 )
return NULL ;
for ( V_19 = 0 ; V_19 < V_10 ; V_19 ++ ) {
if ( V_17 [ V_19 ] . type != type )
continue;
if ( V_22 == V_21 )
break;
V_22 ++ ;
}
if ( V_19 == V_10 )
return NULL ;
if ( type == V_20 &&
! F_6 ( V_15 , V_17 [ V_19 ] . V_16 ) )
return NULL ;
return & V_17 [ V_19 ] ;
}
static const struct V_13 *
F_8 ( struct V_14 * V_15 , struct V_23 * V_24 )
{
struct V_25 * V_26 = & V_24 -> V_17 . V_27 ;
struct V_28 * V_29 = V_26 -> V_30 ;
const struct V_13 * V_17 ;
unsigned int V_31 ;
memset ( V_29 [ 0 ] . V_32 , 0 , sizeof( V_29 [ 0 ] . V_32 ) ) ;
memset ( V_26 -> V_32 , 0 , sizeof( V_26 -> V_32 ) ) ;
V_17 = F_4 ( V_15 , V_26 -> V_33 , V_24 -> type ) ;
if ( ! V_17 ) {
if ( V_24 -> type == V_34 )
V_26 -> V_33 = V_35 ;
else if ( V_24 -> type == V_20 )
V_26 -> V_33 = V_36 ;
else
return NULL ;
V_17 = F_4 ( V_15 , V_26 -> V_33 , V_24 -> type ) ;
V_26 -> V_2 = 1280 ;
V_26 -> V_3 = 720 ;
}
V_26 -> V_2 = F_9 ( V_26 -> V_2 , V_15 -> V_37 . V_38 ,
V_15 -> V_37 . V_39 ) ;
V_26 -> V_3 = F_9 ( V_26 -> V_3 , V_15 -> V_40 . V_38 ,
V_15 -> V_40 . V_39 ) ;
if ( V_24 -> type == V_34 )
V_26 -> V_3 = F_2 ( V_26 -> V_3 , 32 ) ;
if ( V_26 -> V_41 == V_42 )
V_26 -> V_41 = V_43 ;
V_26 -> V_44 = V_17 -> V_44 ;
V_26 -> V_45 = 0 ;
if ( V_24 -> type == V_34 ) {
for ( V_31 = 0 ; V_31 < V_26 -> V_44 ; V_31 ++ ) {
V_29 [ V_31 ] . V_46 =
F_1 ( V_31 , V_26 -> V_2 ,
V_26 -> V_3 ) ;
V_29 [ V_31 ] . V_47 = F_2 ( V_26 -> V_2 , 128 ) ;
}
} else {
V_29 [ 0 ] . V_46 = F_3 ( V_26 -> V_2 ,
V_26 -> V_3 ) ;
V_29 [ 0 ] . V_47 = 0 ;
}
return V_17 ;
}
static int F_10 ( struct V_48 * V_48 , void * V_49 , struct V_23 * V_24 )
{
struct V_14 * V_15 = F_11 ( V_48 ) ;
F_8 ( V_15 , V_24 ) ;
return 0 ;
}
static int F_12 ( struct V_48 * V_48 , void * V_49 , struct V_23 * V_24 )
{
struct V_14 * V_15 = F_11 ( V_48 ) ;
const struct V_13 * V_17 = NULL ;
struct V_25 * V_26 = & V_24 -> V_17 . V_27 ;
if ( V_24 -> type == V_34 )
V_17 = V_15 -> V_50 ;
else if ( V_24 -> type == V_20 )
V_17 = V_15 -> V_51 ;
if ( V_15 -> V_52 ) {
struct V_23 V_53 = {} ;
V_15 -> V_54 = V_15 -> V_55 ;
V_15 -> V_56 = V_15 -> V_57 ;
V_15 -> V_52 = false ;
V_53 . type = V_34 ;
V_53 . V_17 . V_27 . V_33 = V_15 -> V_50 -> V_16 ;
V_53 . V_17 . V_27 . V_2 = V_15 -> V_54 ;
V_53 . V_17 . V_27 . V_3 = V_15 -> V_56 ;
F_8 ( V_15 , & V_53 ) ;
V_15 -> V_2 = V_53 . V_17 . V_27 . V_2 ;
V_15 -> V_3 = V_53 . V_17 . V_27 . V_3 ;
}
V_26 -> V_33 = V_17 -> V_16 ;
if ( V_24 -> type == V_34 ) {
V_26 -> V_2 = V_15 -> V_2 ;
V_26 -> V_3 = V_15 -> V_3 ;
V_26 -> V_58 = V_15 -> V_58 ;
V_26 -> V_59 = V_15 -> V_59 ;
V_26 -> V_60 = V_15 -> V_60 ;
V_26 -> V_61 = V_15 -> V_61 ;
} else if ( V_24 -> type == V_20 ) {
V_26 -> V_2 = V_15 -> V_54 ;
V_26 -> V_3 = V_15 -> V_56 ;
}
F_8 ( V_15 , V_24 ) ;
return 0 ;
}
static int F_13 ( struct V_48 * V_48 , void * V_49 , struct V_23 * V_24 )
{
struct V_14 * V_15 = F_11 ( V_48 ) ;
struct V_25 * V_26 = & V_24 -> V_17 . V_27 ;
struct V_25 V_62 ;
const struct V_13 * V_17 ;
struct V_23 V_53 ;
T_1 V_63 = 0 , V_64 = 0 ;
V_62 = * V_26 ;
V_17 = F_8 ( V_15 , V_24 ) ;
if ( V_24 -> type == V_20 ) {
V_63 = V_26 -> V_33 ;
V_64 = V_15 -> V_50 -> V_16 ;
} else if ( V_24 -> type == V_34 ) {
V_64 = V_26 -> V_33 ;
V_63 = V_15 -> V_51 -> V_16 ;
}
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . type = V_20 ;
V_53 . V_17 . V_27 . V_33 = V_63 ;
V_53 . V_17 . V_27 . V_2 = V_62 . V_2 ;
V_53 . V_17 . V_27 . V_3 = V_62 . V_3 ;
F_8 ( V_15 , & V_53 ) ;
if ( V_24 -> type == V_20 ) {
V_15 -> V_54 = V_53 . V_17 . V_27 . V_2 ;
V_15 -> V_56 = V_53 . V_17 . V_27 . V_3 ;
V_15 -> V_58 = V_26 -> V_58 ;
V_15 -> V_59 = V_26 -> V_59 ;
V_15 -> V_60 = V_26 -> V_60 ;
V_15 -> V_61 = V_26 -> V_61 ;
}
memset ( & V_53 , 0 , sizeof( V_53 ) ) ;
V_53 . type = V_34 ;
V_53 . V_17 . V_27 . V_33 = V_64 ;
V_53 . V_17 . V_27 . V_2 = V_62 . V_2 ;
V_53 . V_17 . V_27 . V_3 = V_62 . V_3 ;
F_8 ( V_15 , & V_53 ) ;
V_15 -> V_2 = V_53 . V_17 . V_27 . V_2 ;
V_15 -> V_3 = V_53 . V_17 . V_27 . V_3 ;
if ( V_24 -> type == V_20 )
V_15 -> V_51 = V_17 ;
else if ( V_24 -> type == V_34 )
V_15 -> V_50 = V_17 ;
return 0 ;
}
static int
F_14 ( struct V_48 * V_48 , void * V_49 , struct V_65 * V_66 )
{
struct V_14 * V_15 = F_11 ( V_48 ) ;
if ( V_66 -> type != V_67 &&
V_66 -> type != V_68 )
return - V_69 ;
switch ( V_66 -> V_70 ) {
case V_71 :
case V_72 :
case V_73 :
if ( V_66 -> type != V_68 )
return - V_69 ;
V_66 -> V_74 . V_2 = V_15 -> V_54 ;
V_66 -> V_74 . V_3 = V_15 -> V_56 ;
break;
case V_75 :
case V_76 :
if ( V_66 -> type != V_67 )
return - V_69 ;
V_66 -> V_74 . V_2 = V_15 -> V_2 ;
V_66 -> V_74 . V_3 = V_15 -> V_3 ;
break;
case V_77 :
case V_78 :
if ( V_66 -> type != V_67 )
return - V_69 ;
V_66 -> V_74 . V_2 = V_15 -> V_54 ;
V_66 -> V_74 . V_3 = V_15 -> V_56 ;
break;
default:
return - V_69 ;
}
V_66 -> V_74 . V_79 = 0 ;
V_66 -> V_74 . V_80 = 0 ;
return 0 ;
}
static int
F_15 ( struct V_48 * V_48 , void * V_49 , struct V_81 * V_82 )
{
F_16 ( V_82 -> V_83 , L_1 , sizeof( V_82 -> V_83 ) ) ;
F_16 ( V_82 -> V_84 , L_2 , sizeof( V_82 -> V_84 ) ) ;
F_16 ( V_82 -> V_85 , L_3 , sizeof( V_82 -> V_85 ) ) ;
return 0 ;
}
static int F_17 ( struct V_48 * V_48 , void * V_49 , struct V_86 * V_24 )
{
struct V_14 * V_15 = F_11 ( V_48 ) ;
const struct V_13 * V_17 ;
memset ( V_24 -> V_32 , 0 , sizeof( V_24 -> V_32 ) ) ;
V_17 = F_7 ( V_15 , V_24 -> V_21 , V_24 -> type ) ;
if ( ! V_17 )
return - V_69 ;
V_24 -> V_33 = V_17 -> V_16 ;
return 0 ;
}
static int F_18 ( struct V_48 * V_48 , void * V_49 , struct V_87 * V_88 )
{
struct V_14 * V_15 = F_11 ( V_48 ) ;
struct V_89 * V_82 = & V_88 -> V_90 . V_91 ;
struct V_92 * V_93 = & V_82 -> V_93 ;
T_2 V_94 , V_95 ;
if ( V_88 -> type != V_34 &&
V_88 -> type != V_20 )
return - V_69 ;
memset ( V_82 -> V_32 , 0 , sizeof( V_82 -> V_32 ) ) ;
if ( ! V_93 -> V_96 )
V_93 -> V_96 = V_15 -> V_93 . V_96 ;
if ( ! V_93 -> V_97 )
V_93 -> V_97 = V_15 -> V_93 . V_97 ;
V_82 -> V_98 = 0 ;
V_82 -> V_99 = 0 ;
V_82 -> V_100 = V_101 ;
V_94 = V_93 -> V_97 * ( T_2 ) V_102 ;
F_19 ( V_94 , V_93 -> V_96 ) ;
if ( ! V_94 )
return - V_69 ;
V_95 = ( T_2 ) V_102 ;
F_19 ( V_95 , V_94 ) ;
V_15 -> V_95 = V_95 ;
V_15 -> V_93 = * V_93 ;
return 0 ;
}
static int F_20 ( struct V_48 * V_48 , void * V_49 ,
struct V_103 * V_104 )
{
struct V_14 * V_15 = F_11 ( V_48 ) ;
const struct V_13 * V_17 ;
V_17 = F_4 ( V_15 , V_104 -> V_105 ,
V_34 ) ;
if ( ! V_17 ) {
V_17 = F_4 ( V_15 , V_104 -> V_105 ,
V_20 ) ;
if ( ! V_17 )
return - V_69 ;
}
if ( V_104 -> V_21 )
return - V_69 ;
V_104 -> type = V_106 ;
V_104 -> V_107 . V_108 = V_15 -> V_37 . V_38 ;
V_104 -> V_107 . V_109 = V_15 -> V_37 . V_39 ;
V_104 -> V_107 . V_110 = V_15 -> V_37 . V_111 ;
V_104 -> V_107 . V_112 = V_15 -> V_40 . V_38 ;
V_104 -> V_107 . V_113 = V_15 -> V_40 . V_39 ;
V_104 -> V_107 . V_114 = V_15 -> V_40 . V_111 ;
return 0 ;
}
static int F_21 ( struct V_115 * V_49 ,
const struct V_116 * V_117 )
{
switch ( V_117 -> type ) {
case V_118 :
return F_22 ( V_49 , V_117 , 2 , NULL ) ;
case V_119 :
return F_23 ( V_49 , V_117 ) ;
case V_120 :
return F_24 ( V_49 , V_117 ) ;
default:
return - V_69 ;
}
}
static int
F_25 ( struct V_48 * V_48 , void * V_49 , struct V_121 * V_122 )
{
if ( V_122 -> V_122 != V_123 )
return - V_69 ;
return 0 ;
}
static int
F_26 ( struct V_48 * V_48 , void * V_49 , struct V_121 * V_122 )
{
struct V_14 * V_15 = F_11 ( V_48 ) ;
int V_124 ;
V_124 = F_25 ( V_48 , V_49 , V_122 ) ;
if ( V_124 )
return V_124 ;
F_27 ( & V_15 -> V_125 ) ;
V_15 -> V_126 = true ;
F_28 ( & V_15 -> V_125 ) ;
F_29 ( V_15 ) ;
return 0 ;
}
static int F_30 ( struct V_14 * V_15 )
{
struct V_127 * V_128 = & V_15 -> V_129 . V_130 ;
struct V_131 * V_132 = V_15 -> V_132 ;
struct V_133 V_134 = { . V_135 = 1 } ;
T_1 V_136 ;
int V_124 ;
if ( V_132 -> V_137 -> V_138 == V_139 ) {
V_136 = V_140 ;
V_124 = F_31 ( V_15 , V_136 , & V_134 ) ;
if ( V_124 )
return V_124 ;
}
if ( V_132 -> V_137 -> V_138 == V_141 ||
V_15 -> V_142 ) {
struct V_143 V_144 ;
V_136 = V_145 ;
V_144 . type = V_146 ;
V_144 . V_144 = V_147 ;
V_124 = F_31 ( V_15 , V_136 , & V_144 ) ;
if ( V_124 )
return V_124 ;
}
if ( V_128 -> V_148 ) {
V_136 = V_149 ;
V_134 . V_135 = 1 ;
V_124 = F_31 ( V_15 , V_136 , & V_134 ) ;
if ( V_124 )
return V_124 ;
}
return 0 ;
}
static int F_32 ( struct V_14 * V_15 )
{
int V_124 ;
V_124 = F_33 ( V_15 , V_15 -> V_51 -> V_16 ) ;
if ( V_124 )
return V_124 ;
V_124 = F_34 ( V_15 , V_15 -> V_54 ,
V_15 -> V_56 ) ;
if ( V_124 )
goto V_150;
V_124 = F_35 ( V_15 , V_15 -> V_50 -> V_16 ) ;
if ( V_124 )
goto V_150;
return 0 ;
V_150:
F_36 ( V_15 ) ;
return V_124 ;
}
static int F_37 ( struct V_14 * V_15 , unsigned int * V_151 )
{
struct V_152 V_153 ;
int V_124 ;
V_124 = F_32 ( V_15 ) ;
if ( V_124 )
return V_124 ;
V_124 = F_38 ( V_15 , V_146 , & V_153 ) ;
* V_151 = V_153 . V_154 ;
F_36 ( V_15 ) ;
return V_124 ;
}
static int F_39 ( struct V_155 * V_156 ,
unsigned int * V_157 , unsigned int * V_44 ,
unsigned int V_158 [] , struct V_159 * V_160 [] )
{
struct V_14 * V_15 = F_40 ( V_156 ) ;
unsigned int V_31 , V_151 ;
int V_124 = 0 ;
if ( * V_44 ) {
if ( V_156 -> type == V_20 &&
* V_44 != V_15 -> V_51 -> V_44 )
return - V_69 ;
if ( V_156 -> type == V_34 &&
* V_44 != V_15 -> V_50 -> V_44 )
return - V_69 ;
if ( V_156 -> type == V_20 &&
V_158 [ 0 ] < V_15 -> V_161 )
return - V_69 ;
if ( V_156 -> type == V_34 &&
V_158 [ 0 ] < V_15 -> V_162 )
return - V_69 ;
return 0 ;
}
switch ( V_156 -> type ) {
case V_20 :
* V_44 = V_15 -> V_51 -> V_44 ;
V_158 [ 0 ] = F_3 ( V_15 -> V_54 ,
V_15 -> V_56 ) ;
V_15 -> V_161 = V_158 [ 0 ] ;
V_15 -> V_163 = * V_157 ;
V_124 = F_37 ( V_15 , & V_151 ) ;
if ( V_124 )
break;
V_15 -> V_164 = V_151 ;
break;
case V_34 :
* V_44 = V_15 -> V_50 -> V_44 ;
V_124 = F_37 ( V_15 , & V_151 ) ;
if ( V_124 )
break;
* V_157 = V_39 ( * V_157 , V_151 ) ;
for ( V_31 = 0 ; V_31 < * V_44 ; V_31 ++ )
V_158 [ V_31 ] = F_1 ( V_31 , V_15 -> V_2 ,
V_15 -> V_3 ) ;
V_15 -> V_164 = * V_157 ;
V_15 -> V_162 = V_158 [ 0 ] ;
break;
default:
V_124 = - V_69 ;
break;
}
return V_124 ;
}
static int F_41 ( struct V_14 * V_15 )
{
struct V_152 V_153 ;
int V_124 ;
if ( ! V_15 -> V_163 || ! V_15 -> V_164 )
return - V_69 ;
V_124 = F_38 ( V_15 , V_146 , & V_153 ) ;
if ( V_124 )
return V_124 ;
if ( V_15 -> V_164 < V_153 . V_154 ||
V_15 -> V_164 < V_153 . V_165 )
return - V_69 ;
V_124 = F_38 ( V_15 , V_166 , & V_153 ) ;
if ( V_124 )
return V_124 ;
if ( V_15 -> V_163 < V_153 . V_165 )
return - V_69 ;
return 0 ;
}
static int F_42 ( struct V_155 * V_156 , unsigned int V_167 )
{
struct V_14 * V_15 = F_40 ( V_156 ) ;
struct V_131 * V_132 = V_15 -> V_132 ;
T_1 V_136 ;
int V_124 ;
F_27 ( & V_15 -> V_125 ) ;
if ( V_156 -> type == V_20 )
V_15 -> V_168 = 1 ;
else
V_15 -> V_169 = 1 ;
if ( ! ( V_15 -> V_168 & V_15 -> V_169 ) ) {
F_28 ( & V_15 -> V_125 ) ;
return 0 ;
}
F_43 ( V_15 ) ;
V_15 -> V_52 = false ;
V_15 -> V_170 = 0 ;
V_15 -> V_171 = 0 ;
V_15 -> V_126 = false ;
V_124 = F_32 ( V_15 ) ;
if ( V_124 )
goto V_172;
V_124 = F_30 ( V_15 ) ;
if ( V_124 )
goto V_173;
if ( V_132 -> V_137 -> V_138 == V_141 ) {
struct V_174 V_175 ;
V_136 = V_176 ;
V_175 . type = V_146 ;
V_175 . V_10 = V_15 -> V_162 ;
V_124 = F_31 ( V_15 , V_136 , & V_175 ) ;
if ( V_124 )
goto V_173;
}
V_124 = F_41 ( V_15 ) ;
if ( V_124 )
goto V_173;
V_124 = F_44 ( V_15 , V_15 -> V_163 ,
V_177 ) ;
if ( V_124 )
goto V_173;
V_124 = F_45 ( V_15 ) ;
if ( V_124 )
goto V_173;
F_28 ( & V_15 -> V_125 ) ;
return 0 ;
V_173:
F_36 ( V_15 ) ;
V_172:
F_46 ( V_15 , V_178 ) ;
if ( V_156 -> type == V_20 )
V_15 -> V_168 = 0 ;
else
V_15 -> V_169 = 0 ;
F_28 ( & V_15 -> V_125 ) ;
return V_124 ;
}
static void F_47 ( struct V_14 * V_15 , unsigned int V_179 ,
T_1 V_180 , T_1 V_181 , T_1 V_182 , T_1 V_45 ,
T_1 V_183 , T_2 V_184 )
{
enum V_185 V_186 = V_187 ;
struct V_188 * V_189 ;
struct V_190 * V_191 ;
unsigned int type ;
if ( V_179 == V_166 )
type = V_20 ;
else
type = V_34 ;
V_189 = F_48 ( V_15 , type , V_180 ) ;
if ( ! V_189 )
return;
V_189 -> V_45 = V_45 ;
V_189 -> V_41 = V_43 ;
if ( type == V_34 ) {
V_191 = & V_189 -> V_192 ;
V_191 -> V_193 [ 0 ] . V_181 =
F_49 (unsigned int, inst->output_buf_size, bytesused) ;
V_191 -> V_193 [ 0 ] . V_182 = V_182 ;
V_191 -> V_194 = V_184 * V_195 ;
V_189 -> V_196 = V_15 -> V_170 ++ ;
if ( V_15 -> V_126 ) {
V_189 -> V_45 |= V_197 ;
V_15 -> V_126 = false ;
}
if ( V_189 -> V_45 & V_197 ) {
const struct V_198 V_199 = { . type = V_118 } ;
F_50 ( & V_15 -> V_49 , & V_199 ) ;
}
} else {
V_189 -> V_196 = V_15 -> V_171 ++ ;
}
if ( V_183 & V_200 )
F_51 ( V_189 ) ;
if ( V_183 & V_201 )
V_186 = V_202 ;
F_52 ( V_189 , V_186 ) ;
}
static void F_53 ( struct V_14 * V_15 , T_1 V_203 ,
struct V_204 * V_205 )
{
struct V_131 * V_132 = V_15 -> V_132 ;
struct V_159 * V_206 = V_132 -> V_207 ;
static const struct V_198 V_199 = {
. type = V_119 ,
. V_208 . V_209 . V_210 = V_211 } ;
switch ( V_203 ) {
case V_212 :
V_15 -> V_213 = true ;
F_54 ( V_206 , L_4 , V_15 -> error ) ;
break;
case V_214 :
switch ( V_205 -> V_215 ) {
case V_216 :
F_55 ( V_15 ) ;
F_56 ( V_206 , L_5 ) ;
break;
case V_217 :
V_15 -> V_57 = V_205 -> V_3 ;
V_15 -> V_55 = V_205 -> V_2 ;
V_15 -> V_52 = true ;
F_50 ( & V_15 -> V_49 , & V_199 ) ;
F_56 ( V_206 , L_6 ,
V_205 -> V_2 , V_205 -> V_3 ) ;
break;
case V_218 :
F_57 ( V_15 , V_205 -> V_180 ) ;
break;
default:
break;
}
break;
default:
break;
}
}
static void F_58 ( struct V_14 * V_15 )
{
V_15 -> V_51 = & V_18 [ 6 ] ;
V_15 -> V_50 = & V_18 [ 0 ] ;
V_15 -> V_2 = 1280 ;
V_15 -> V_3 = F_2 ( 720 , 32 ) ;
V_15 -> V_54 = 1280 ;
V_15 -> V_56 = 720 ;
V_15 -> V_95 = 30 ;
V_15 -> V_93 . V_97 = 1 ;
V_15 -> V_93 . V_96 = 30 ;
V_15 -> V_37 . V_38 = 64 ;
V_15 -> V_37 . V_39 = 1920 ;
if ( V_15 -> V_132 -> V_137 -> V_138 == V_141 )
V_15 -> V_37 . V_39 = 3840 ;
V_15 -> V_37 . V_111 = 1 ;
V_15 -> V_40 . V_38 = 64 ;
V_15 -> V_40 . V_39 = F_2 ( 1080 , 32 ) ;
if ( V_15 -> V_132 -> V_137 -> V_138 == V_141 )
V_15 -> V_40 . V_39 = F_2 ( 2160 , 32 ) ;
V_15 -> V_40 . V_111 = 1 ;
V_15 -> V_219 . V_38 = 1 ;
V_15 -> V_219 . V_39 = 30 ;
V_15 -> V_219 . V_111 = 1 ;
V_15 -> V_220 . V_38 = 16 ;
V_15 -> V_220 . V_39 = 8160 ;
}
static int F_59 ( void * V_221 , struct V_155 * V_222 ,
struct V_155 * V_223 )
{
struct V_14 * V_15 = V_221 ;
int V_124 ;
V_222 -> type = V_20 ;
V_222 -> V_224 = V_225 | V_226 ;
V_222 -> V_227 = V_228 ;
V_222 -> V_229 = & V_230 ;
V_222 -> V_231 = & V_232 ;
V_222 -> V_233 = V_15 ;
V_222 -> V_234 = sizeof( struct V_235 ) ;
V_222 -> V_236 = 1 ;
V_222 -> V_237 = 1 ;
V_222 -> V_206 = V_15 -> V_132 -> V_206 ;
V_124 = F_60 ( V_222 ) ;
if ( V_124 )
return V_124 ;
V_223 -> type = V_34 ;
V_223 -> V_224 = V_225 | V_226 ;
V_223 -> V_227 = V_228 ;
V_223 -> V_229 = & V_230 ;
V_223 -> V_231 = & V_232 ;
V_223 -> V_233 = V_15 ;
V_223 -> V_234 = sizeof( struct V_235 ) ;
V_223 -> V_236 = 1 ;
V_223 -> V_237 = 1 ;
V_223 -> V_206 = V_15 -> V_132 -> V_206 ;
V_124 = F_60 ( V_223 ) ;
if ( V_124 ) {
F_61 ( V_222 ) ;
return V_124 ;
}
return 0 ;
}
static int F_62 ( struct V_48 * V_48 )
{
struct V_131 * V_132 = F_63 ( V_48 ) ;
struct V_14 * V_15 ;
int V_124 ;
V_15 = F_64 ( sizeof( * V_15 ) , V_238 ) ;
if ( ! V_15 )
return - V_239 ;
F_65 ( & V_15 -> V_240 ) ;
F_65 ( & V_15 -> V_241 ) ;
F_65 ( & V_15 -> V_242 ) ;
F_66 ( & V_15 -> V_125 ) ;
V_15 -> V_132 = V_132 ;
V_15 -> V_243 = V_244 ;
V_15 -> V_164 = 1 ;
F_43 ( V_15 ) ;
V_124 = F_67 ( V_132 -> V_207 ) ;
if ( V_124 < 0 )
goto V_245;
V_124 = F_68 ( V_15 ) ;
if ( V_124 )
goto V_246;
V_124 = F_69 ( V_15 , & V_247 ) ;
if ( V_124 )
goto V_248;
F_58 ( V_15 ) ;
V_15 -> V_249 = F_70 ( & V_250 ) ;
if ( F_71 ( V_15 -> V_249 ) ) {
V_124 = F_72 ( V_15 -> V_249 ) ;
goto V_251;
}
V_15 -> V_252 = F_73 ( V_15 -> V_249 , V_15 , F_59 ) ;
if ( F_71 ( V_15 -> V_252 ) ) {
V_124 = F_72 ( V_15 -> V_252 ) ;
goto V_253;
}
F_74 ( & V_15 -> V_49 , V_132 -> V_254 ) ;
V_15 -> V_49 . V_255 = & V_15 -> V_255 ;
F_75 ( & V_15 -> V_49 ) ;
V_15 -> V_49 . V_252 = V_15 -> V_252 ;
V_48 -> V_256 = & V_15 -> V_49 ;
return 0 ;
V_253:
F_76 ( V_15 -> V_249 ) ;
V_251:
F_77 ( V_15 ) ;
V_248:
F_78 ( V_15 ) ;
V_246:
F_79 ( V_132 -> V_207 ) ;
V_245:
F_80 ( V_15 ) ;
return V_124 ;
}
static int F_81 ( struct V_48 * V_48 )
{
struct V_14 * V_15 = F_11 ( V_48 ) ;
F_82 ( V_15 -> V_252 ) ;
F_76 ( V_15 -> V_249 ) ;
F_78 ( V_15 ) ;
F_77 ( V_15 ) ;
F_83 ( & V_15 -> V_125 ) ;
F_84 ( & V_15 -> V_49 ) ;
F_85 ( & V_15 -> V_49 ) ;
F_79 ( V_15 -> V_132 -> V_207 ) ;
F_80 ( V_15 ) ;
return 0 ;
}
static int F_86 ( struct V_257 * V_258 )
{
struct V_159 * V_206 = & V_258 -> V_206 ;
struct V_259 * V_260 ;
struct V_131 * V_132 ;
int V_124 ;
if ( ! V_206 -> V_261 )
return - V_262 ;
V_132 = F_87 ( V_206 -> V_261 ) ;
if ( ! V_132 )
return - V_262 ;
if ( V_132 -> V_137 -> V_138 == V_141 ) {
V_132 -> V_263 = F_88 ( V_206 , L_7 ) ;
if ( F_71 ( V_132 -> V_263 ) )
return F_72 ( V_132 -> V_263 ) ;
}
F_89 ( V_258 , V_132 ) ;
V_260 = F_90 () ;
if ( ! V_260 )
return - V_239 ;
F_16 ( V_260 -> V_264 , L_8 , sizeof( V_260 -> V_264 ) ) ;
V_260 -> V_265 = V_266 ;
V_260 -> V_267 = & V_268 ;
V_260 -> V_269 = & V_270 ;
V_260 -> V_271 = V_272 ;
V_260 -> V_273 = & V_132 -> V_273 ;
V_260 -> V_274 = V_275 | V_276 ;
V_124 = F_91 ( V_260 , V_277 , - 1 ) ;
if ( V_124 )
goto V_278;
V_132 -> V_254 = V_260 ;
V_132 -> V_207 = V_206 ;
F_92 ( V_260 , V_132 ) ;
F_93 ( V_206 ) ;
return 0 ;
V_278:
V_266 ( V_260 ) ;
return V_124 ;
}
static int F_94 ( struct V_257 * V_258 )
{
struct V_131 * V_132 = F_87 ( V_258 -> V_206 . V_261 ) ;
F_95 ( V_132 -> V_254 ) ;
F_96 ( V_132 -> V_207 ) ;
return 0 ;
}
static T_3 int F_97 ( struct V_159 * V_206 )
{
struct V_131 * V_132 = F_87 ( V_206 ) ;
if ( V_132 -> V_137 -> V_138 == V_139 )
return 0 ;
F_98 ( 0 , V_132 -> V_279 + V_280 ) ;
F_99 ( V_132 -> V_263 ) ;
F_98 ( 1 , V_132 -> V_279 + V_280 ) ;
return 0 ;
}
static T_3 int F_100 ( struct V_159 * V_206 )
{
struct V_131 * V_132 = F_87 ( V_206 ) ;
int V_124 ;
if ( V_132 -> V_137 -> V_138 == V_139 )
return 0 ;
F_98 ( 0 , V_132 -> V_279 + V_280 ) ;
V_124 = F_101 ( V_132 -> V_263 ) ;
F_98 ( 1 , V_132 -> V_279 + V_280 ) ;
return V_124 ;
}
