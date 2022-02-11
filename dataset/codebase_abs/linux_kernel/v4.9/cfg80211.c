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
enum V_26 type , T_1 * V_27 ,
struct V_28 * V_29 )
{
struct V_9 * V_10 = V_25 -> V_30 ;
T_1 V_12 ;
int V_31 ;
int V_2 = 0 ;
switch ( type ) {
case V_32 :
if ( V_10 -> V_33 == V_34 )
goto exit;
V_10 -> V_33 = V_34 ;
V_12 = 0 ;
break;
case V_35 :
if ( V_10 -> V_33 == V_36 )
goto exit;
V_10 -> V_33 = V_36 ;
V_12 = 1 ;
break;
default:
F_6 ( V_25 , L_1 , type ) ;
return - V_8 ;
}
V_31 = F_2 ( V_10 ,
V_37 ,
V_12 ) ;
if ( V_31 )
V_2 = - V_38 ;
V_25 -> V_39 -> V_40 = type ;
exit:
return V_2 ;
}
static int F_7 ( struct V_23 * V_23 , struct V_24 * V_25 ,
V_20 V_41 , bool V_42 , const V_20 * V_43 ,
struct V_44 * V_29 )
{
struct V_9 * V_10 = V_25 -> V_30 ;
T_1 V_11 ;
int V_2 = 0 ;
int V_31 = 0 ;
if ( V_41 >= V_45 )
return - V_4 ;
switch ( V_29 -> V_46 ) {
case V_47 :
case V_48 :
V_31 = F_2 ( V_10 ,
V_49 ,
V_41 ) ;
if ( V_31 )
goto exit;
V_11 = F_8 ( V_41 + 1 ) ;
V_31 = F_4 ( V_10 , V_11 ,
V_29 -> V_50 , V_29 -> V_51 ) ;
if ( V_31 )
goto exit;
break;
default:
F_9 ( L_2 ) ;
V_31 = 1 ;
}
exit:
if ( V_31 )
V_2 = - V_38 ;
return V_2 ;
}
static int F_10 ( struct V_23 * V_23 , struct V_24 * V_25 ,
V_20 V_41 , bool V_42 ,
const V_20 * V_43 , void * V_52 ,
void (* F_11)( void * V_52 , struct V_44 * ) )
{
struct V_9 * V_10 = V_25 -> V_30 ;
struct V_44 V_29 ;
int V_21 ;
if ( V_41 >= V_45 )
return - V_4 ;
V_21 = V_10 -> V_53 [ V_41 ] ;
memset ( & V_29 , 0 , sizeof( V_29 ) ) ;
if ( V_21 == 13 )
V_29 . V_46 = V_48 ;
else if ( V_21 == 5 )
V_29 . V_46 = V_48 ;
else
return - V_54 ;
V_29 . V_50 = V_21 ;
V_29 . V_51 = V_10 -> V_55 [ V_41 ] ;
V_29 . V_56 = 0 ;
F_11 ( V_52 , & V_29 ) ;
return 0 ;
}
static int F_12 ( struct V_23 * V_23 , struct V_24 * V_25 ,
V_20 V_41 , bool V_42 , const V_20 * V_43 )
{
struct V_9 * V_10 = V_25 -> V_30 ;
T_1 V_11 ;
int V_2 = 0 ;
int V_31 = 0 ;
if ( V_41 >= V_45 )
return - V_4 ;
V_11 = F_8 ( V_41 + 1 ) ;
V_31 = F_4 ( V_10 , V_11 , 13 , L_3 ) ;
if ( V_31 )
V_2 = - V_38 ;
return V_2 ;
}
static int F_13 ( struct V_23 * V_23 , struct V_24 * V_25 ,
V_20 V_41 , bool V_57 , bool V_58 )
{
struct V_9 * V_10 = V_25 -> V_30 ;
int V_2 = 0 ;
int V_31 = 0 ;
V_31 = F_2 ( V_10 ,
V_49 ,
V_41 ) ;
if ( V_31 )
V_2 = - V_38 ;
return V_2 ;
}
static int F_14 ( struct V_23 * V_23 , struct V_24 * V_25 ,
const V_20 * V_59 , struct V_60 * V_61 )
{
struct V_9 * V_10 = V_25 -> V_30 ;
struct V_62 V_63 ;
int V_31 ;
memset ( V_61 , 0 , sizeof( * V_61 ) ) ;
if ( ! V_10 || ( V_10 -> V_64 != V_65 ) )
return - V_8 ;
V_63 . V_18 = V_66 ;
V_63 . V_67 . V_12 = V_68 ;
V_63 . V_67 . V_69 = V_70 ;
if ( ! V_10 -> V_71 )
return - V_8 ;
V_31 = V_10 -> V_71 ( V_10 , (struct V_72 * ) & V_63 ) ;
if ( V_31 == 0 ) {
V_61 -> V_73 . V_74 = V_63 . V_73 . V_12 ;
V_61 -> V_75 |= F_15 ( V_76 ) ;
V_61 -> signal = V_63 . V_77 . V_12 ;
V_61 -> V_75 |= F_15 ( V_78 ) ;
}
return V_31 ;
}
static int F_16 ( struct V_23 * V_23 ,
struct V_79 * V_80 )
{
struct V_24 * V_25 ;
struct V_81 * V_82 = F_17 ( V_23 ) ;
struct V_9 * V_10 ;
struct V_83 V_84 ;
struct V_85 V_86 ;
struct V_87 * V_88 ;
struct V_89 V_90 = {} ;
int V_31 ;
int V_2 = 0 ;
int V_91 = 0 ;
int V_92 = 0 ;
V_20 V_93 [ 46 ] ;
int V_94 ;
if ( ! V_80 )
return - V_4 ;
V_25 = V_80 -> V_95 -> V_96 ;
V_10 = V_25 -> V_30 ;
if ( V_82 -> V_97 && V_82 -> V_97 != V_80 )
return - V_98 ;
if ( V_10 -> V_33 == V_99 ) {
F_18 ( V_25 , L_4 ) ;
return - V_8 ;
}
V_82 -> V_97 = V_80 ;
memset ( & V_84 , 0x00 , sizeof( struct V_83 ) ) ;
V_84 . V_18 = V_100 ;
V_84 . V_101 . V_12 = V_102 ;
memset ( & V_84 . V_103 . V_12 . V_12 , 0xFF , sizeof( V_84 . V_103 . V_12 . V_12 ) ) ;
V_84 . V_103 . V_12 . V_21 = 6 ;
if ( V_80 -> V_104 > 0 ) {
V_84 . V_105 . V_12 = V_106 ;
V_84 . V_107 . V_12 . V_21 = V_80 -> V_108 -> V_109 ;
memcpy ( V_84 . V_107 . V_12 . V_12 ,
V_80 -> V_108 -> V_107 , V_80 -> V_108 -> V_109 ) ;
} else {
V_84 . V_105 . V_12 = 0 ;
}
V_84 . V_110 . V_12 = 0 ;
for ( V_92 = 0 ;
( V_92 < V_80 -> V_111 ) && V_92 < F_19 ( V_112 ) ;
V_92 ++ )
V_84 . V_113 . V_12 . V_12 [ V_92 ] =
F_20 (
V_80 -> V_114 [ V_92 ] -> V_115 ) ;
V_84 . V_113 . V_12 . V_21 = V_80 -> V_111 ;
V_84 . V_116 . V_12 = 250 ;
V_84 . V_117 . V_12 = 200 ;
V_31 = F_3 ( V_10 , ( V_20 * ) & V_84 ) ;
if ( V_31 ) {
V_2 = F_1 ( V_84 . V_118 . V_12 ) ;
goto exit;
}
V_91 = V_84 . V_91 . V_12 ;
for ( V_92 = 0 ; V_92 < V_91 ; V_92 ++ ) {
int V_119 ;
memset ( & V_86 , 0 , sizeof( V_86 ) ) ;
V_86 . V_18 = V_120 ;
V_86 . V_121 . V_12 = V_92 ;
V_31 = F_3 ( V_10 , ( V_20 * ) & V_86 ) ;
if ( ( V_31 != 0 ) ||
( V_86 . V_118 . V_12 != V_122 ) ) {
break;
}
V_93 [ 0 ] = V_123 ;
V_93 [ 1 ] = V_86 . V_107 . V_12 . V_21 ;
V_94 = V_93 [ 1 ] + 2 ;
memcpy ( & V_93 [ 2 ] , & ( V_86 . V_107 . V_12 . V_12 ) , V_86 . V_107 . V_12 . V_21 ) ;
V_119 = F_21 ( V_86 . V_124 . V_12 ,
V_125 ) ;
V_88 = F_22 ( V_23 ,
F_23 ( V_23 , V_119 ) ,
V_126 ,
( const V_20 * ) & ( V_86 . V_103 . V_12 . V_12 ) ,
V_86 . V_127 . V_12 , V_86 . V_128 . V_12 ,
V_86 . V_129 . V_12 ,
V_93 ,
V_94 ,
( V_86 . signal . V_12 - 65536 ) * 100 ,
V_130
) ;
if ( ! V_88 ) {
V_2 = - V_131 ;
goto exit;
}
F_24 ( V_23 , V_88 ) ;
}
if ( V_31 )
V_2 = F_1 ( V_86 . V_118 . V_12 ) ;
exit:
V_90 . V_132 = ! ! ( V_2 ) ;
F_25 ( V_80 , & V_90 ) ;
V_82 -> V_97 = NULL ;
return V_2 ;
}
static int F_26 ( struct V_23 * V_23 , T_1 V_133 )
{
struct V_81 * V_82 = F_17 ( V_23 ) ;
struct V_9 * V_10 = V_82 -> V_10 ;
T_1 V_12 ;
int V_31 ;
int V_2 = 0 ;
if ( V_133 & V_134 ) {
if ( V_23 -> V_135 == - 1 )
V_12 = 2347 ;
else
V_12 = V_23 -> V_135 ;
V_31 = F_2 ( V_10 ,
V_136 ,
V_12 ) ;
if ( V_31 ) {
V_2 = - V_38 ;
goto exit;
}
}
if ( V_133 & V_137 ) {
if ( V_23 -> V_138 == - 1 )
V_12 = 2346 ;
else
V_12 = V_23 -> V_138 ;
V_31 = F_2 ( V_10 ,
V_139 ,
V_12 ) ;
if ( V_31 ) {
V_2 = - V_38 ;
goto exit;
}
}
exit:
return V_2 ;
}
static int F_27 ( struct V_23 * V_23 , struct V_24 * V_25 ,
struct V_140 * V_141 )
{
struct V_9 * V_10 = V_25 -> V_30 ;
struct V_142 * V_143 = V_141 -> V_143 ;
struct V_144 V_145 ;
T_1 V_11 ;
int V_146 = V_141 -> V_109 ;
int V_147 = - 1 ;
int V_148 = ( V_141 -> V_149 . V_150 == V_47 ) ||
( V_141 -> V_149 . V_150 == V_48 ) ;
int V_31 ;
int V_2 = 0 ;
if ( V_143 ) {
V_147 = F_20 ( V_143 -> V_115 ) ;
V_31 = F_2 ( V_10 ,
V_151 ,
V_147 ) ;
if ( V_31 )
goto exit;
}
if ( ( V_141 -> V_152 == V_153 ) ||
( ( V_141 -> V_152 == V_154 ) && ! V_148 ) )
V_145 . V_155 . V_12 = V_156 ;
else if ( ( V_141 -> V_152 == V_157 ) ||
( ( V_141 -> V_152 == V_154 ) && V_148 ) )
V_145 . V_155 . V_12 = V_158 ;
else
F_6 ( V_25 ,
L_5 ,
V_141 -> V_152 ) ;
if ( V_148 ) {
if ( V_141 -> V_51 ) {
if ( V_141 -> V_159 >= V_45 ) {
V_2 = - V_4 ;
goto exit;
}
V_31 = F_2 ( V_10 ,
V_49 ,
V_141 -> V_159 ) ;
if ( V_31 )
goto exit;
V_11 = F_8 (
V_141 -> V_159 + 1 ) ;
V_31 = F_4 ( V_10 ,
V_11 , V_141 -> V_50 ,
( V_20 * ) V_141 -> V_51 ) ;
if ( V_31 )
goto exit;
}
V_31 = F_2 ( V_10 ,
V_160 ,
V_68 ) ;
if ( V_31 )
goto exit;
V_31 = F_2 ( V_10 ,
V_161 ,
V_68 ) ;
if ( V_31 )
goto exit;
} else {
V_31 = F_2 ( V_10 ,
V_160 ,
V_162 ) ;
if ( V_31 )
goto exit;
V_31 = F_2 ( V_10 ,
V_161 ,
V_162 ) ;
if ( V_31 )
goto exit;
}
V_145 . V_18 = V_163 ;
memcpy ( V_145 . V_107 . V_12 . V_12 , V_141 -> V_107 , V_146 ) ;
V_145 . V_107 . V_12 . V_21 = V_146 ;
V_31 = F_3 ( V_10 , ( V_20 * ) & V_145 ) ;
exit:
if ( V_31 )
V_2 = - V_38 ;
return V_2 ;
}
static int F_28 ( struct V_23 * V_23 , struct V_24 * V_25 ,
T_2 V_164 )
{
struct V_9 * V_10 = V_25 -> V_30 ;
struct V_144 V_145 ;
int V_31 ;
int V_2 = 0 ;
V_145 . V_18 = V_163 ;
memcpy ( V_145 . V_107 . V_12 . V_12 , L_6 , 3 ) ;
V_145 . V_107 . V_12 . V_21 = 3 ;
V_31 = F_3 ( V_10 , ( V_20 * ) & V_145 ) ;
if ( V_31 )
V_2 = - V_38 ;
return V_2 ;
}
static int F_29 ( struct V_23 * V_23 , struct V_24 * V_25 ,
struct V_165 * V_29 )
{
return - V_8 ;
}
static int F_30 ( struct V_23 * V_23 , struct V_24 * V_25 )
{
return - V_8 ;
}
static int F_31 ( struct V_23 * V_23 , struct V_166 * V_95 ,
enum V_167 type , int V_168 )
{
struct V_81 * V_82 = F_17 ( V_23 ) ;
struct V_9 * V_10 = V_82 -> V_10 ;
T_1 V_12 ;
int V_31 ;
int V_2 = 0 ;
if ( type == V_169 )
V_12 = 30 ;
else
V_12 = F_32 ( V_168 ) ;
V_31 = F_2 ( V_10 ,
V_170 ,
V_12 ) ;
if ( V_31 ) {
V_2 = - V_38 ;
goto exit;
}
exit:
return V_2 ;
}
static int F_33 ( struct V_23 * V_23 , struct V_166 * V_95 ,
int * V_67 )
{
struct V_81 * V_82 = F_17 ( V_23 ) ;
struct V_9 * V_10 = V_82 -> V_10 ;
struct V_171 V_14 ;
struct V_15 * V_16 ;
int V_31 ;
int V_2 = 0 ;
V_16 = (struct V_15 * ) & V_14 . V_17 . V_12 ;
V_14 . V_18 = V_172 ;
V_16 -> V_11 =
V_170 ;
V_31 = F_3 ( V_10 , ( V_20 * ) & V_14 ) ;
if ( V_31 ) {
V_2 = - V_38 ;
goto exit;
}
* V_67 = V_16 -> V_12 ;
exit:
return V_2 ;
}
void F_34 ( struct V_9 * V_10 , V_20 V_173 )
{
T_2 V_69 = V_173 ?
V_174 : V_175 ;
F_35 ( V_10 -> V_96 , V_10 -> V_103 ,
NULL , 0 , NULL , 0 , V_69 , V_130 ) ;
}
void F_36 ( struct V_9 * V_10 )
{
F_37 ( V_10 -> V_96 , 0 , NULL ,
0 , false , V_130 ) ;
}
void F_38 ( struct V_9 * V_10 )
{
F_39 ( V_10 -> V_96 , NULL , V_10 -> V_103 ,
NULL , 0 , NULL , 0 , V_130 ) ;
}
static struct V_23 * F_40 ( struct V_176 * V_25 , struct V_9 * V_10 )
{
struct V_23 * V_23 ;
struct V_81 * V_82 ;
V_23 = F_41 ( & V_177 , sizeof( * V_82 ) ) ;
if ( ! V_23 )
return NULL ;
V_82 = F_17 ( V_23 ) ;
V_82 -> V_10 = V_10 ;
memcpy ( V_82 -> V_114 , V_112 , sizeof( V_112 ) ) ;
memcpy ( V_82 -> V_178 , V_179 , sizeof( V_179 ) ) ;
V_82 -> V_180 . V_114 = V_82 -> V_114 ;
V_82 -> V_180 . V_111 = F_19 ( V_112 ) ;
V_82 -> V_180 . V_181 = V_82 -> V_178 ;
V_82 -> V_180 . V_182 = F_19 ( V_179 ) ;
V_82 -> V_180 . V_180 = V_125 ;
V_82 -> V_180 . V_183 . V_184 = false ;
V_23 -> V_185 [ V_125 ] = & V_82 -> V_180 ;
F_42 ( V_23 , V_25 ) ;
V_23 -> V_186 = V_187 ;
V_23 -> V_188 = 1 ;
V_23 -> V_189 = F_15 ( V_35 )
| F_15 ( V_32 ) ;
V_23 -> V_190 = V_191 ;
V_23 -> V_192 = V_193 ;
V_23 -> V_194 = V_195 ;
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
