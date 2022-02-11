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
static int F_2 ( T_1 * V_9 , T_2 V_10 , T_2 V_11 )
{
struct V_12 V_13 ;
T_3 * V_14 =
( T_3 * ) & V_13 . V_15 . V_11 ;
V_13 . V_16 = V_17 ;
V_14 -> V_10 = V_10 ;
V_14 -> V_11 = V_11 ;
return F_3 ( V_9 , ( V_18 * ) & V_13 ) ;
}
static int F_4 ( T_1 * V_9 ,
T_2 V_10 , V_18 V_19 , V_18 * V_11 )
{
struct V_12 V_13 ;
T_4 * V_14 =
( T_4 * ) & V_13 . V_15 . V_11 ;
V_13 . V_16 = V_17 ;
V_14 -> V_10 = V_10 ;
V_14 -> V_11 . V_19 = V_19 ;
memcpy ( V_14 -> V_11 . V_11 , V_11 , V_19 ) ;
return F_3 ( V_9 , ( V_18 * ) & V_13 ) ;
}
static int F_5 ( struct V_20 * V_20 ,
struct V_21 * V_22 ,
enum V_23 type , T_2 * V_24 ,
struct V_25 * V_26 )
{
T_1 * V_9 = V_22 -> V_27 ;
T_2 V_11 ;
int V_28 ;
int V_2 = 0 ;
switch ( type ) {
case V_29 :
if ( V_9 -> V_30 == V_31 )
goto exit;
V_9 -> V_30 = V_31 ;
V_11 = 0 ;
break;
case V_32 :
if ( V_9 -> V_30 == V_33 )
goto exit;
V_9 -> V_30 = V_33 ;
V_11 = 1 ;
break;
default:
F_6 ( V_22 , L_1 , type ) ;
return - V_8 ;
}
V_28 = F_2 ( V_9 ,
V_34 ,
V_11 ) ;
if ( V_28 )
V_2 = - V_35 ;
V_22 -> V_36 -> V_37 = type ;
exit:
return V_2 ;
}
static int F_7 ( struct V_20 * V_20 , struct V_21 * V_22 ,
V_18 V_38 , bool V_39 , const V_18 * V_40 ,
struct V_41 * V_26 )
{
T_1 * V_9 = V_22 -> V_27 ;
T_2 V_10 ;
int V_2 = 0 ;
int V_28 = 0 ;
switch ( V_26 -> V_42 ) {
case V_43 :
case V_44 :
V_28 = F_2 ( V_9 ,
V_45 ,
V_38 ) ;
if ( V_28 )
goto exit;
switch ( V_38 ) {
case 0 :
V_10 = V_46 ;
break;
case 1 :
V_10 = V_47 ;
break;
case 2 :
V_10 = V_48 ;
break;
case 3 :
V_10 = V_49 ;
break;
default:
V_2 = - V_4 ;
goto exit;
}
V_28 = F_4 ( V_9 , V_10 ,
V_26 -> V_50 , V_26 -> V_51 ) ;
if ( V_28 )
goto exit;
break;
default:
F_8 ( L_2 ) ;
V_28 = 1 ;
}
exit:
if ( V_28 )
V_2 = - V_35 ;
return V_2 ;
}
static int F_9 ( struct V_20 * V_20 , struct V_21 * V_22 ,
V_18 V_38 , bool V_39 ,
const V_18 * V_40 , void * V_52 ,
void (* F_10)( void * V_52 , struct V_41 * ) )
{
T_1 * V_9 = V_22 -> V_27 ;
struct V_41 V_26 ;
int V_19 ;
if ( V_38 >= V_53 )
return - V_4 ;
V_19 = V_9 -> V_54 [ V_38 ] ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( V_19 == 13 )
V_26 . V_42 = V_44 ;
else if ( V_19 == 5 )
V_26 . V_42 = V_44 ;
else
return - V_55 ;
V_26 . V_50 = V_19 ;
V_26 . V_51 = V_9 -> V_56 [ V_38 ] ;
V_26 . V_57 = 0 ;
F_10 ( V_52 , & V_26 ) ;
return 0 ;
}
static int F_11 ( struct V_20 * V_20 , struct V_21 * V_22 ,
V_18 V_38 , bool V_39 , const V_18 * V_40 )
{
T_1 * V_9 = V_22 -> V_27 ;
T_2 V_10 ;
int V_2 = 0 ;
int V_28 = 0 ;
switch ( V_38 ) {
case 0 :
V_10 =
V_46 ;
break;
case 1 :
V_10 =
V_47 ;
break;
case 2 :
V_10 =
V_48 ;
break;
case 3 :
V_10 =
V_49 ;
break;
default:
V_2 = - V_4 ;
goto exit;
}
V_28 = F_4 ( V_9 , V_10 , 13 , L_3 ) ;
exit:
if ( V_28 )
V_2 = - V_35 ;
return V_2 ;
}
static int F_12 ( struct V_20 * V_20 , struct V_21 * V_22 ,
V_18 V_38 , bool V_58 , bool V_59 )
{
T_1 * V_9 = V_22 -> V_27 ;
int V_2 = 0 ;
int V_28 = 0 ;
V_28 = F_2 ( V_9 ,
V_45 ,
V_38 ) ;
if ( V_28 )
V_2 = - V_35 ;
return V_2 ;
}
static int F_13 ( struct V_20 * V_20 , struct V_21 * V_22 ,
V_18 * V_60 , struct V_61 * V_62 )
{
T_1 * V_9 = V_22 -> V_27 ;
struct V_63 V_64 ;
int V_28 ;
memset ( V_62 , 0 , sizeof( * V_62 ) ) ;
if ( ( V_9 == NULL ) || ( V_9 -> V_65 != V_66 ) )
return - V_8 ;
V_64 . V_16 = V_67 ;
V_64 . V_68 . V_11 = V_69 ;
V_64 . V_68 . V_70 = V_71 ;
if ( V_9 -> V_72 == NULL )
return - V_8 ;
V_28 = V_9 -> V_72 ( V_9 , (struct V_73 * ) & V_64 ) ;
if ( V_28 == 0 ) {
V_62 -> V_74 . V_75 = V_64 . V_74 . V_11 ;
V_62 -> V_76 |= V_77 ;
V_62 -> signal = V_64 . V_78 . V_11 ;
V_62 -> V_76 |= V_79 ;
}
return V_28 ;
}
static int F_14 ( struct V_20 * V_20 ,
struct V_80 * V_81 )
{
struct V_21 * V_22 ;
struct V_82 * V_83 = F_15 ( V_20 ) ;
T_1 * V_9 ;
struct V_84 V_85 ;
struct V_86 V_87 ;
struct V_88 * V_89 ;
int V_28 ;
int V_2 = 0 ;
int V_90 = 0 ;
int V_91 = 0 ;
V_18 V_92 [ 46 ] ;
int V_93 ;
if ( ! V_81 )
return - V_4 ;
V_22 = V_81 -> V_94 -> V_95 ;
V_9 = V_22 -> V_27 ;
if ( V_83 -> V_96 && V_83 -> V_96 != V_81 )
return - V_97 ;
if ( V_9 -> V_30 == V_98 ) {
F_16 ( V_22 , L_4 ) ;
return - V_8 ;
}
V_83 -> V_96 = V_81 ;
memset ( & V_85 , 0x00 , sizeof( struct V_84 ) ) ;
V_85 . V_16 = V_99 ;
V_85 . V_100 . V_11 = V_101 ;
memset ( & V_85 . V_102 . V_11 . V_11 , 0xFF , sizeof( V_85 . V_102 . V_11 . V_11 ) ) ;
V_85 . V_102 . V_11 . V_19 = 6 ;
if ( V_81 -> V_103 > 0 ) {
V_85 . V_104 . V_11 = V_105 ;
V_85 . V_106 . V_11 . V_19 = V_81 -> V_107 -> V_108 ;
memcpy ( V_85 . V_106 . V_11 . V_11 ,
V_81 -> V_107 -> V_106 , V_81 -> V_107 -> V_108 ) ;
} else {
V_85 . V_104 . V_11 = 0 ;
}
V_85 . V_109 . V_11 = 0 ;
for ( V_91 = 0 ;
( V_91 < V_81 -> V_110 ) && V_91 < F_17 ( V_111 ) ;
V_91 ++ )
V_85 . V_112 . V_11 . V_11 [ V_91 ] =
F_18 (
V_81 -> V_113 [ V_91 ] -> V_114 ) ;
V_85 . V_112 . V_11 . V_19 = V_81 -> V_110 ;
V_85 . V_115 . V_11 = 250 ;
V_85 . V_116 . V_11 = 200 ;
V_28 = F_3 ( V_9 , ( V_18 * ) & V_85 ) ;
if ( V_28 ) {
V_2 = F_1 ( V_85 . V_117 . V_11 ) ;
goto exit;
}
V_90 = V_85 . V_90 . V_11 ;
for ( V_91 = 0 ; V_91 < V_90 ; V_91 ++ ) {
int V_118 ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_87 . V_16 = V_119 ;
V_87 . V_120 . V_11 = V_91 ;
V_28 = F_3 ( V_9 , ( V_18 * ) & V_87 ) ;
if ( ( V_28 != 0 ) ||
( V_87 . V_117 . V_11 != V_121 ) ) {
break;
}
V_92 [ 0 ] = V_122 ;
V_92 [ 1 ] = V_87 . V_106 . V_11 . V_19 ;
V_93 = V_92 [ 1 ] + 2 ;
memcpy ( & V_92 [ 2 ] , & ( V_87 . V_106 . V_11 . V_11 ) , V_87 . V_106 . V_11 . V_19 ) ;
V_118 = F_19 ( V_87 . V_123 . V_11 ,
V_124 ) ;
V_89 = F_20 ( V_20 ,
F_21 ( V_20 , V_118 ) ,
( const V_18 * ) & ( V_87 . V_102 . V_11 . V_11 ) ,
V_87 . V_125 . V_11 , V_87 . V_126 . V_11 ,
V_87 . V_127 . V_11 ,
V_92 ,
V_93 ,
( V_87 . signal . V_11 - 65536 ) * 100 ,
V_128
) ;
if ( ! V_89 ) {
V_2 = - V_129 ;
goto exit;
}
F_22 ( V_20 , V_89 ) ;
}
if ( V_28 )
V_2 = F_1 ( V_87 . V_117 . V_11 ) ;
exit:
F_23 ( V_81 , V_2 ? 1 : 0 ) ;
V_83 -> V_96 = NULL ;
return V_2 ;
}
static int F_24 ( struct V_20 * V_20 , T_2 V_130 )
{
struct V_82 * V_83 = F_15 ( V_20 ) ;
T_1 * V_9 = V_83 -> V_9 ;
T_2 V_11 ;
int V_28 ;
int V_2 = 0 ;
if ( V_130 & V_131 ) {
if ( V_20 -> V_132 == - 1 )
V_11 = 2347 ;
else
V_11 = V_20 -> V_132 ;
V_28 = F_2 ( V_9 ,
V_133 ,
V_11 ) ;
if ( V_28 ) {
V_2 = - V_35 ;
goto exit;
}
}
if ( V_130 & V_134 ) {
if ( V_20 -> V_135 == - 1 )
V_11 = 2346 ;
else
V_11 = V_20 -> V_135 ;
V_28 = F_2 ( V_9 ,
V_136 ,
V_11 ) ;
if ( V_28 ) {
V_2 = - V_35 ;
goto exit;
}
}
exit:
return V_2 ;
}
static int F_25 ( struct V_20 * V_20 , struct V_21 * V_22 ,
struct V_137 * V_138 )
{
T_1 * V_9 = V_22 -> V_27 ;
struct V_139 * V_140 = V_138 -> V_140 ;
struct V_141 V_142 ;
T_2 V_10 ;
int V_143 = V_138 -> V_108 ;
int V_144 = - 1 ;
int V_145 = ( V_138 -> V_146 . V_147 == V_43 ) ||
( V_138 -> V_146 . V_147 == V_44 ) ;
int V_28 ;
int V_2 = 0 ;
if ( V_140 ) {
V_144 = F_18 ( V_140 -> V_114 ) ;
V_28 = F_2 ( V_9 ,
V_148 ,
V_144 ) ;
if ( V_28 )
goto exit;
}
if ( ( V_138 -> V_149 == V_150 ) ||
( ( V_138 -> V_149 == V_151 ) && ! V_145 ) )
V_142 . V_152 . V_11 = V_153 ;
else if ( ( V_138 -> V_149 == V_154 ) ||
( ( V_138 -> V_149 == V_151 ) && V_145 ) )
V_142 . V_152 . V_11 = V_155 ;
else
F_6 ( V_22 ,
L_5 ,
V_138 -> V_149 ) ;
if ( V_145 ) {
if ( V_138 -> V_51 ) {
V_28 = F_2 ( V_9 ,
V_45 ,
V_138 -> V_156 ) ;
if ( V_28 )
goto exit;
switch ( V_138 -> V_156 ) {
case 0 :
V_10 = V_46 ;
break;
case 1 :
V_10 = V_47 ;
break;
case 2 :
V_10 = V_48 ;
break;
case 3 :
V_10 = V_49 ;
break;
default:
V_2 = - V_4 ;
goto exit;
}
V_28 = F_4 ( V_9 ,
V_10 , V_138 -> V_50 ,
( V_18 * ) V_138 -> V_51 ) ;
if ( V_28 )
goto exit;
}
V_28 = F_2 ( V_9 ,
V_157 ,
V_69 ) ;
if ( V_28 )
goto exit;
V_28 = F_2 ( V_9 ,
V_158 ,
V_69 ) ;
if ( V_28 )
goto exit;
} else {
V_28 = F_2 ( V_9 ,
V_157 ,
V_159 ) ;
if ( V_28 )
goto exit;
V_28 = F_2 ( V_9 ,
V_158 ,
V_159 ) ;
if ( V_28 )
goto exit;
}
V_142 . V_16 = V_160 ;
memcpy ( V_142 . V_106 . V_11 . V_11 , V_138 -> V_106 , V_143 ) ;
V_142 . V_106 . V_11 . V_19 = V_143 ;
V_28 = F_3 ( V_9 , ( V_18 * ) & V_142 ) ;
exit:
if ( V_28 )
V_2 = - V_35 ;
return V_2 ;
}
static int F_26 ( struct V_20 * V_20 , struct V_21 * V_22 ,
T_5 V_161 )
{
T_1 * V_9 = V_22 -> V_27 ;
struct V_141 V_142 ;
int V_28 ;
int V_2 = 0 ;
V_142 . V_16 = V_160 ;
memcpy ( V_142 . V_106 . V_11 . V_11 , L_6 , 3 ) ;
V_142 . V_106 . V_11 . V_19 = 3 ;
V_28 = F_3 ( V_9 , ( V_18 * ) & V_142 ) ;
if ( V_28 )
V_2 = - V_35 ;
return V_2 ;
}
static int F_27 ( struct V_20 * V_20 , struct V_21 * V_22 ,
struct V_162 * V_26 )
{
return - V_8 ;
}
static int F_28 ( struct V_20 * V_20 , struct V_21 * V_22 )
{
return - V_8 ;
}
static int F_29 ( struct V_20 * V_20 , struct V_163 * V_94 ,
enum V_164 type , int V_165 )
{
struct V_82 * V_83 = F_15 ( V_20 ) ;
T_1 * V_9 = V_83 -> V_9 ;
T_2 V_11 ;
int V_28 ;
int V_2 = 0 ;
if ( type == V_166 )
V_11 = 30 ;
else
V_11 = F_30 ( V_165 ) ;
V_28 = F_2 ( V_9 ,
V_167 ,
V_11 ) ;
if ( V_28 ) {
V_2 = - V_35 ;
goto exit;
}
exit:
return V_2 ;
}
static int F_31 ( struct V_20 * V_20 , struct V_163 * V_94 ,
int * V_68 )
{
struct V_82 * V_83 = F_15 ( V_20 ) ;
T_1 * V_9 = V_83 -> V_9 ;
struct V_168 V_13 ;
T_3 * V_14 ;
int V_28 ;
int V_2 = 0 ;
V_14 = ( T_3 * ) & V_13 . V_15 . V_11 ;
V_13 . V_16 = V_169 ;
V_14 -> V_10 =
V_167 ;
V_28 = F_3 ( V_9 , ( V_18 * ) & V_13 ) ;
if ( V_28 ) {
V_2 = - V_35 ;
goto exit;
}
* V_68 = V_14 -> V_11 ;
exit:
return V_2 ;
}
void F_32 ( T_1 * V_9 , V_18 V_170 )
{
T_5 V_70 = V_170 ?
V_171 : V_172 ;
F_33 ( V_9 -> V_95 , V_9 -> V_102 ,
NULL , 0 , NULL , 0 , V_70 , V_128 ) ;
}
void F_34 ( T_1 * V_9 )
{
F_35 ( V_9 -> V_95 , 0 , NULL ,
0 , V_128 ) ;
}
void F_36 ( T_1 * V_9 )
{
F_37 ( V_9 -> V_95 , NULL , V_9 -> V_102 ,
NULL , 0 , NULL , 0 , V_128 ) ;
}
static struct V_20 * F_38 ( struct V_173 * V_22 , T_1 * V_9 )
{
struct V_20 * V_20 ;
struct V_82 * V_83 ;
V_20 = F_39 ( & V_174 , sizeof( * V_83 ) ) ;
if ( ! V_20 )
return NULL ;
V_83 = F_15 ( V_20 ) ;
V_83 -> V_9 = V_9 ;
memcpy ( V_83 -> V_113 , V_111 , sizeof( V_111 ) ) ;
memcpy ( V_83 -> V_175 , V_176 , sizeof( V_176 ) ) ;
V_83 -> V_177 . V_113 = V_83 -> V_113 ;
V_83 -> V_177 . V_110 = F_17 ( V_111 ) ;
V_83 -> V_177 . V_178 = V_83 -> V_175 ;
V_83 -> V_177 . V_179 = F_17 ( V_176 ) ;
V_83 -> V_177 . V_177 = V_124 ;
V_83 -> V_177 . V_180 . V_181 = false ;
V_20 -> V_182 [ V_124 ] = & V_83 -> V_177 ;
F_40 ( V_20 , V_22 ) ;
V_20 -> V_183 = V_184 ;
V_20 -> V_185 = 1 ;
V_20 -> V_186 = F_41 ( V_32 )
| F_41 ( V_29 ) ;
V_20 -> V_187 = V_188 ;
V_20 -> V_189 = V_190 ;
V_20 -> V_191 = V_192 ;
if ( F_42 ( V_20 ) < 0 )
return NULL ;
return V_20 ;
}
static void F_43 ( struct V_20 * V_20 )
{
F_44 ( V_20 ) ;
F_45 ( V_20 ) ;
}
