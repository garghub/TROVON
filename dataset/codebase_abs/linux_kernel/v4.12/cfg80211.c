static int F_1 ( int V_1 )
{
int V_2 = 0 ;
switch ( V_1 ) {
case V_3 :
V_2 = - V_4 ;
break;
case V_5 :
V_2 = - V_6 ;
break;
case V_7 :
V_2 = - V_8 ;
break;
default:
V_2 = 0 ;
break;
}
return V_2 ;
}
static int F_2 ( struct V_9 * V_10 , T_1 V_11 , T_1 V_12 )
{
struct V_13 V_14 ;
struct V_15 * V_16 =
(struct V_15 * ) & V_14 . V_17 . V_12 ;
V_14 . V_18 = V_19 ;
V_16 -> V_11 = V_11 ;
V_16 -> V_12 = V_12 ;
return F_3 ( V_10 , ( V_20 * ) & V_14 ) ;
}
static int F_4 ( struct V_9 * V_10 ,
T_1 V_11 , V_20 V_21 , const V_20 * V_12 )
{
struct V_13 V_14 ;
struct V_22 * V_16 =
(struct V_22 * ) & V_14 . V_17 . V_12 ;
V_14 . V_18 = V_19 ;
V_16 -> V_11 = V_11 ;
V_16 -> V_12 . V_21 = V_21 ;
memcpy ( V_16 -> V_12 . V_12 , V_12 , V_21 ) ;
return F_3 ( V_10 , ( V_20 * ) & V_14 ) ;
}
static int F_5 ( struct V_23 * V_23 ,
struct V_24 * V_25 ,
enum V_26 type ,
struct V_27 * V_28 )
{
struct V_9 * V_10 = V_25 -> V_29 ;
T_1 V_12 ;
int V_30 ;
int V_2 = 0 ;
switch ( type ) {
case V_31 :
if ( V_10 -> V_32 == V_33 )
goto exit;
V_10 -> V_32 = V_33 ;
V_12 = 0 ;
break;
case V_34 :
if ( V_10 -> V_32 == V_35 )
goto exit;
V_10 -> V_32 = V_35 ;
V_12 = 1 ;
break;
default:
F_6 ( V_25 , L_1 , type ) ;
return - V_8 ;
}
V_30 = F_2 ( V_10 ,
V_36 ,
V_12 ) ;
if ( V_30 )
V_2 = - V_37 ;
V_25 -> V_38 -> V_39 = type ;
exit:
return V_2 ;
}
static int F_7 ( struct V_23 * V_23 , struct V_24 * V_25 ,
V_20 V_40 , bool V_41 , const V_20 * V_42 ,
struct V_43 * V_28 )
{
struct V_9 * V_10 = V_25 -> V_29 ;
T_1 V_11 ;
int V_2 = 0 ;
int V_30 = 0 ;
if ( V_40 >= V_44 )
return - V_4 ;
switch ( V_28 -> V_45 ) {
case V_46 :
case V_47 :
V_30 = F_2 ( V_10 ,
V_48 ,
V_40 ) ;
if ( V_30 )
goto exit;
V_11 = F_8 ( V_40 + 1 ) ;
V_30 = F_4 ( V_10 , V_11 ,
V_28 -> V_49 , V_28 -> V_50 ) ;
if ( V_30 )
goto exit;
break;
default:
F_9 ( L_2 ) ;
V_30 = 1 ;
}
exit:
if ( V_30 )
V_2 = - V_37 ;
return V_2 ;
}
static int F_10 ( struct V_23 * V_23 , struct V_24 * V_25 ,
V_20 V_40 , bool V_41 ,
const V_20 * V_42 , void * V_51 ,
void (* F_11)( void * V_51 , struct V_43 * ) )
{
struct V_9 * V_10 = V_25 -> V_29 ;
struct V_43 V_28 ;
int V_21 ;
if ( V_40 >= V_44 )
return - V_4 ;
V_21 = V_10 -> V_52 [ V_40 ] ;
memset ( & V_28 , 0 , sizeof( V_28 ) ) ;
if ( V_21 == 13 )
V_28 . V_45 = V_47 ;
else if ( V_21 == 5 )
V_28 . V_45 = V_47 ;
else
return - V_53 ;
V_28 . V_49 = V_21 ;
V_28 . V_50 = V_10 -> V_54 [ V_40 ] ;
V_28 . V_55 = 0 ;
F_11 ( V_51 , & V_28 ) ;
return 0 ;
}
static int F_12 ( struct V_23 * V_23 , struct V_24 * V_25 ,
V_20 V_40 , bool V_41 , const V_20 * V_42 )
{
struct V_9 * V_10 = V_25 -> V_29 ;
T_1 V_11 ;
int V_2 = 0 ;
int V_30 = 0 ;
if ( V_40 >= V_44 )
return - V_4 ;
V_11 = F_8 ( V_40 + 1 ) ;
V_30 = F_4 ( V_10 , V_11 , 13 , L_3 ) ;
if ( V_30 )
V_2 = - V_37 ;
return V_2 ;
}
static int F_13 ( struct V_23 * V_23 , struct V_24 * V_25 ,
V_20 V_40 , bool V_56 , bool V_57 )
{
struct V_9 * V_10 = V_25 -> V_29 ;
int V_2 = 0 ;
int V_30 = 0 ;
V_30 = F_2 ( V_10 ,
V_48 ,
V_40 ) ;
if ( V_30 )
V_2 = - V_37 ;
return V_2 ;
}
static int F_14 ( struct V_23 * V_23 , struct V_24 * V_25 ,
const V_20 * V_58 , struct V_59 * V_60 )
{
struct V_9 * V_10 = V_25 -> V_29 ;
struct V_61 V_62 ;
int V_30 ;
memset ( V_60 , 0 , sizeof( * V_60 ) ) ;
if ( ! V_10 || ( V_10 -> V_63 != V_64 ) )
return - V_8 ;
V_62 . V_18 = V_65 ;
V_62 . V_66 . V_12 = V_67 ;
V_62 . V_66 . V_68 = V_69 ;
if ( ! V_10 -> V_70 )
return - V_8 ;
V_30 = V_10 -> V_70 ( V_10 , (struct V_71 * ) & V_62 ) ;
if ( V_30 == 0 ) {
V_60 -> V_72 . V_73 = V_62 . V_72 . V_12 ;
V_60 -> V_74 |= F_15 ( V_75 ) ;
V_60 -> signal = V_62 . V_76 . V_12 ;
V_60 -> V_74 |= F_15 ( V_77 ) ;
}
return V_30 ;
}
static int F_16 ( struct V_23 * V_23 ,
struct V_78 * V_79 )
{
struct V_24 * V_25 ;
struct V_80 * V_81 = F_17 ( V_23 ) ;
struct V_9 * V_10 ;
struct V_82 V_83 ;
struct V_84 V_85 ;
struct V_86 * V_87 ;
struct V_88 V_89 = {} ;
int V_30 ;
int V_2 = 0 ;
int V_90 = 0 ;
int V_91 = 0 ;
V_20 V_92 [ 46 ] ;
int V_93 ;
if ( ! V_79 )
return - V_4 ;
V_25 = V_79 -> V_94 -> V_95 ;
V_10 = V_25 -> V_29 ;
if ( V_81 -> V_96 && V_81 -> V_96 != V_79 )
return - V_97 ;
if ( V_10 -> V_32 == V_98 ) {
F_18 ( V_25 , L_4 ) ;
return - V_8 ;
}
V_81 -> V_96 = V_79 ;
memset ( & V_83 , 0x00 , sizeof( V_83 ) ) ;
V_83 . V_18 = V_99 ;
V_83 . V_100 . V_12 = V_101 ;
memset ( & V_83 . V_102 . V_12 . V_12 , 0xFF , sizeof( V_83 . V_102 . V_12 . V_12 ) ) ;
V_83 . V_102 . V_12 . V_21 = 6 ;
if ( V_79 -> V_103 > 0 ) {
V_83 . V_104 . V_12 = V_105 ;
V_83 . V_106 . V_12 . V_21 = V_79 -> V_107 -> V_108 ;
memcpy ( V_83 . V_106 . V_12 . V_12 ,
V_79 -> V_107 -> V_106 , V_79 -> V_107 -> V_108 ) ;
} else {
V_83 . V_104 . V_12 = 0 ;
}
V_83 . V_109 . V_12 = 0 ;
for ( V_91 = 0 ;
( V_91 < V_79 -> V_110 ) && V_91 < F_19 ( V_111 ) ;
V_91 ++ )
V_83 . V_112 . V_12 . V_12 [ V_91 ] =
F_20 (
V_79 -> V_113 [ V_91 ] -> V_114 ) ;
V_83 . V_112 . V_12 . V_21 = V_79 -> V_110 ;
V_83 . V_115 . V_12 = 250 ;
V_83 . V_116 . V_12 = 200 ;
V_30 = F_3 ( V_10 , ( V_20 * ) & V_83 ) ;
if ( V_30 ) {
V_2 = F_1 ( V_83 . V_117 . V_12 ) ;
goto exit;
}
V_90 = V_83 . V_90 . V_12 ;
for ( V_91 = 0 ; V_91 < V_90 ; V_91 ++ ) {
int V_118 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_85 . V_18 = V_119 ;
V_85 . V_120 . V_12 = V_91 ;
V_30 = F_3 ( V_10 , ( V_20 * ) & V_85 ) ;
if ( ( V_30 != 0 ) ||
( V_85 . V_117 . V_12 != V_121 ) ) {
break;
}
V_92 [ 0 ] = V_122 ;
V_92 [ 1 ] = V_85 . V_106 . V_12 . V_21 ;
V_93 = V_92 [ 1 ] + 2 ;
memcpy ( & V_92 [ 2 ] , & V_85 . V_106 . V_12 . V_12 , V_85 . V_106 . V_12 . V_21 ) ;
V_118 = F_21 ( V_85 . V_123 . V_12 ,
V_124 ) ;
V_87 = F_22 ( V_23 ,
F_23 ( V_23 , V_118 ) ,
V_125 ,
( const V_20 * ) & V_85 . V_102 . V_12 . V_12 ,
V_85 . V_126 . V_12 , V_85 . V_127 . V_12 ,
V_85 . V_128 . V_12 ,
V_92 ,
V_93 ,
( V_85 . signal . V_12 - 65536 ) * 100 ,
V_129
) ;
if ( ! V_87 ) {
V_2 = - V_130 ;
goto exit;
}
F_24 ( V_23 , V_87 ) ;
}
if ( V_30 )
V_2 = F_1 ( V_85 . V_117 . V_12 ) ;
exit:
V_89 . V_131 = ! ! ( V_2 ) ;
F_25 ( V_79 , & V_89 ) ;
V_81 -> V_96 = NULL ;
return V_2 ;
}
static int F_26 ( struct V_23 * V_23 , T_1 V_132 )
{
struct V_80 * V_81 = F_17 ( V_23 ) ;
struct V_9 * V_10 = V_81 -> V_10 ;
T_1 V_12 ;
int V_30 ;
int V_2 = 0 ;
if ( V_132 & V_133 ) {
if ( V_23 -> V_134 == - 1 )
V_12 = 2347 ;
else
V_12 = V_23 -> V_134 ;
V_30 = F_2 ( V_10 ,
V_135 ,
V_12 ) ;
if ( V_30 ) {
V_2 = - V_37 ;
goto exit;
}
}
if ( V_132 & V_136 ) {
if ( V_23 -> V_137 == - 1 )
V_12 = 2346 ;
else
V_12 = V_23 -> V_137 ;
V_30 = F_2 ( V_10 ,
V_138 ,
V_12 ) ;
if ( V_30 ) {
V_2 = - V_37 ;
goto exit;
}
}
exit:
return V_2 ;
}
static int F_27 ( struct V_23 * V_23 , struct V_24 * V_25 ,
struct V_139 * V_140 )
{
struct V_9 * V_10 = V_25 -> V_29 ;
struct V_141 * V_142 = V_140 -> V_142 ;
struct V_143 V_144 ;
T_1 V_11 ;
int V_145 = V_140 -> V_108 ;
int V_146 = - 1 ;
int V_147 = ( V_140 -> V_148 . V_149 == V_46 ) ||
( V_140 -> V_148 . V_149 == V_47 ) ;
int V_30 ;
int V_2 = 0 ;
if ( V_142 ) {
V_146 = F_20 ( V_142 -> V_114 ) ;
V_30 = F_2 ( V_10 ,
V_150 ,
V_146 ) ;
if ( V_30 )
goto exit;
}
if ( ( V_140 -> V_151 == V_152 ) ||
( ( V_140 -> V_151 == V_153 ) && ! V_147 ) )
V_144 . V_154 . V_12 = V_155 ;
else if ( ( V_140 -> V_151 == V_156 ) ||
( ( V_140 -> V_151 == V_153 ) && V_147 ) )
V_144 . V_154 . V_12 = V_157 ;
else
F_6 ( V_25 ,
L_5 ,
V_140 -> V_151 ) ;
if ( V_147 ) {
if ( V_140 -> V_50 ) {
if ( V_140 -> V_158 >= V_44 ) {
V_2 = - V_4 ;
goto exit;
}
V_30 = F_2 ( V_10 ,
V_48 ,
V_140 -> V_158 ) ;
if ( V_30 )
goto exit;
V_11 = F_8 (
V_140 -> V_158 + 1 ) ;
V_30 = F_4 ( V_10 ,
V_11 , V_140 -> V_49 ,
( V_20 * ) V_140 -> V_50 ) ;
if ( V_30 )
goto exit;
}
V_30 = F_2 ( V_10 ,
V_159 ,
V_67 ) ;
if ( V_30 )
goto exit;
V_30 = F_2 ( V_10 ,
V_160 ,
V_67 ) ;
if ( V_30 )
goto exit;
} else {
V_30 = F_2 ( V_10 ,
V_159 ,
V_161 ) ;
if ( V_30 )
goto exit;
V_30 = F_2 ( V_10 ,
V_160 ,
V_161 ) ;
if ( V_30 )
goto exit;
}
V_144 . V_18 = V_162 ;
memcpy ( V_144 . V_106 . V_12 . V_12 , V_140 -> V_106 , V_145 ) ;
V_144 . V_106 . V_12 . V_21 = V_145 ;
V_30 = F_3 ( V_10 , ( V_20 * ) & V_144 ) ;
exit:
if ( V_30 )
V_2 = - V_37 ;
return V_2 ;
}
static int F_28 ( struct V_23 * V_23 , struct V_24 * V_25 ,
T_2 V_163 )
{
struct V_9 * V_10 = V_25 -> V_29 ;
struct V_143 V_144 ;
int V_30 ;
int V_2 = 0 ;
V_144 . V_18 = V_162 ;
memcpy ( V_144 . V_106 . V_12 . V_12 , L_6 , 3 ) ;
V_144 . V_106 . V_12 . V_21 = 3 ;
V_30 = F_3 ( V_10 , ( V_20 * ) & V_144 ) ;
if ( V_30 )
V_2 = - V_37 ;
return V_2 ;
}
static int F_29 ( struct V_23 * V_23 , struct V_24 * V_25 ,
struct V_164 * V_28 )
{
return - V_8 ;
}
static int F_30 ( struct V_23 * V_23 , struct V_24 * V_25 )
{
return - V_8 ;
}
static int F_31 ( struct V_23 * V_23 , struct V_165 * V_94 ,
enum V_166 type , int V_167 )
{
struct V_80 * V_81 = F_17 ( V_23 ) ;
struct V_9 * V_10 = V_81 -> V_10 ;
T_1 V_12 ;
int V_30 ;
int V_2 = 0 ;
if ( type == V_168 )
V_12 = 30 ;
else
V_12 = F_32 ( V_167 ) ;
V_30 = F_2 ( V_10 ,
V_169 ,
V_12 ) ;
if ( V_30 ) {
V_2 = - V_37 ;
goto exit;
}
exit:
return V_2 ;
}
static int F_33 ( struct V_23 * V_23 , struct V_165 * V_94 ,
int * V_66 )
{
struct V_80 * V_81 = F_17 ( V_23 ) ;
struct V_9 * V_10 = V_81 -> V_10 ;
struct V_170 V_14 ;
struct V_15 * V_16 ;
int V_30 ;
int V_2 = 0 ;
V_16 = (struct V_15 * ) & V_14 . V_17 . V_12 ;
V_14 . V_18 = V_171 ;
V_16 -> V_11 =
V_169 ;
V_30 = F_3 ( V_10 , ( V_20 * ) & V_14 ) ;
if ( V_30 ) {
V_2 = - V_37 ;
goto exit;
}
* V_66 = V_16 -> V_12 ;
exit:
return V_2 ;
}
void F_34 ( struct V_9 * V_10 , V_20 V_172 )
{
T_2 V_68 = V_172 ?
V_173 : V_174 ;
F_35 ( V_10 -> V_95 , V_10 -> V_102 ,
NULL , 0 , NULL , 0 , V_68 , V_129 ) ;
}
void F_36 ( struct V_9 * V_10 )
{
F_37 ( V_10 -> V_95 , 0 , NULL ,
0 , false , V_129 ) ;
}
void F_38 ( struct V_9 * V_10 )
{
struct V_175 V_176 = {
. V_102 = V_10 -> V_102 ,
} ;
F_39 ( V_10 -> V_95 , & V_176 , V_129 ) ;
}
static struct V_23 * F_40 ( struct V_177 * V_25 , struct V_9 * V_10 )
{
struct V_23 * V_23 ;
struct V_80 * V_81 ;
V_23 = F_41 ( & V_178 , sizeof( * V_81 ) ) ;
if ( ! V_23 )
return NULL ;
V_81 = F_17 ( V_23 ) ;
V_81 -> V_10 = V_10 ;
memcpy ( V_81 -> V_113 , V_111 , sizeof( V_111 ) ) ;
memcpy ( V_81 -> V_179 , V_180 , sizeof( V_180 ) ) ;
V_81 -> V_181 . V_113 = V_81 -> V_113 ;
V_81 -> V_181 . V_110 = F_19 ( V_111 ) ;
V_81 -> V_181 . V_182 = V_81 -> V_179 ;
V_81 -> V_181 . V_183 = F_19 ( V_180 ) ;
V_81 -> V_181 . V_181 = V_124 ;
V_81 -> V_181 . V_184 . V_185 = false ;
V_23 -> V_186 [ V_124 ] = & V_81 -> V_181 ;
F_42 ( V_23 , V_25 ) ;
V_23 -> V_187 = V_188 ;
V_23 -> V_189 = 1 ;
V_23 -> V_190 = F_15 ( V_34 )
| F_15 ( V_31 ) ;
V_23 -> V_191 = V_192 ;
V_23 -> V_193 = V_194 ;
V_23 -> V_195 = V_196 ;
if ( F_43 ( V_23 ) < 0 ) {
F_44 ( V_23 ) ;
return NULL ;
}
return V_23 ;
}
static void F_45 ( struct V_23 * V_23 )
{
F_46 ( V_23 ) ;
F_44 ( V_23 ) ;
}
