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
T_3 * V_14 = ( T_3 * ) & V_13 . V_15 . V_11 ;
V_13 . V_16 = V_17 ;
V_14 -> V_10 = V_10 ;
V_14 -> V_11 = V_11 ;
return F_3 ( V_9 , ( V_18 * ) & V_13 ) ;
}
static int F_4 ( T_1 * V_9 ,
T_2 V_10 , V_18 V_19 , V_18 * V_11 )
{
struct V_12 V_13 ;
T_4 * V_14 = ( T_4 * ) & V_13 . V_15 . V_11 ;
V_13 . V_16 = V_17 ;
V_14 -> V_10 = V_10 ;
V_14 -> V_11 . V_19 = V_19 ;
memcpy ( V_14 -> V_11 . V_11 , V_11 , V_19 ) ;
return F_3 ( V_9 , ( V_18 * ) & V_13 ) ;
}
int F_5 ( struct V_20 * V_20 ,
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
F_6 ( V_34 L_1 , type ) ;
return - V_8 ;
}
V_28 = F_2 ( V_9 ,
V_35 ,
V_11 ) ;
if ( V_28 )
V_2 = - V_36 ;
V_22 -> V_37 -> V_38 = type ;
exit:
return V_2 ;
}
int F_7 ( struct V_20 * V_20 , struct V_21 * V_22 ,
V_18 V_39 , bool V_40 , const V_18 * V_41 ,
struct V_42 * V_26 )
{
T_1 * V_9 = V_22 -> V_27 ;
T_2 V_10 ;
int V_2 = 0 ;
int V_28 = 0 ;
switch ( V_26 -> V_43 ) {
case V_44 :
case V_45 :
V_28 = F_2 ( V_9 ,
V_46 ,
V_39 ) ;
if ( V_28 )
goto exit;
switch ( V_39 ) {
case 0 :
V_10 = V_47 ;
break;
case 1 :
V_10 = V_48 ;
break;
case 2 :
V_10 = V_49 ;
break;
case 3 :
V_10 = V_50 ;
break;
default:
V_2 = - V_4 ;
goto exit;
}
V_28 = F_4 ( V_9 , V_10 , V_26 -> V_51 , V_26 -> V_52 ) ;
if ( V_28 )
goto exit;
break;
default:
F_8 ( L_2 ) ;
V_28 = 1 ;
}
exit:
if ( V_28 )
V_2 = - V_36 ;
return V_2 ;
}
int F_9 ( struct V_20 * V_20 , struct V_21 * V_22 ,
V_18 V_39 , bool V_40 , const V_18 * V_41 , void * V_53 ,
void (* F_10)( void * V_53 , struct V_42 * ) )
{
T_1 * V_9 = V_22 -> V_27 ;
struct V_42 V_26 ;
int V_19 ;
if ( V_39 >= V_54 )
return - V_4 ;
V_19 = V_9 -> V_55 [ V_39 ] ;
memset ( & V_26 , 0 , sizeof( V_26 ) ) ;
if ( V_19 == 13 )
V_26 . V_43 = V_45 ;
else if ( V_19 == 5 )
V_26 . V_43 = V_45 ;
else
return - V_56 ;
V_26 . V_51 = V_19 ;
V_26 . V_52 = V_9 -> V_57 [ V_39 ] ;
V_26 . V_58 = 0 ;
F_10 ( V_53 , & V_26 ) ;
return 0 ;
}
int F_11 ( struct V_20 * V_20 , struct V_21 * V_22 ,
V_18 V_39 , bool V_40 , const V_18 * V_41 )
{
T_1 * V_9 = V_22 -> V_27 ;
T_2 V_10 ;
int V_2 = 0 ;
int V_28 = 0 ;
switch ( V_39 ) {
case 0 :
V_10 =
V_47 ;
break;
case 1 :
V_10 =
V_48 ;
break;
case 2 :
V_10 =
V_49 ;
break;
case 3 :
V_10 =
V_50 ;
break;
default:
V_2 = - V_4 ;
goto exit;
}
V_28 = F_4 ( V_9 , V_10 , 13 , L_3 ) ;
exit:
if ( V_28 )
V_2 = - V_36 ;
return V_2 ;
}
int F_12 ( struct V_20 * V_20 , struct V_21 * V_22 ,
V_18 V_39 , bool V_59 , bool V_60 )
{
T_1 * V_9 = V_22 -> V_27 ;
int V_2 = 0 ;
int V_28 = 0 ;
V_28 = F_2 ( V_9 ,
V_46 ,
V_39 ) ;
if ( V_28 )
V_2 = - V_36 ;
return V_2 ;
}
int F_13 ( struct V_20 * V_20 , struct V_21 * V_22 ,
V_18 * V_61 , struct V_62 * V_63 )
{
T_1 * V_9 = V_22 -> V_27 ;
struct V_64 V_65 ;
int V_28 ;
memset ( V_63 , 0 , sizeof( * V_63 ) ) ;
if ( ( V_9 == NULL ) || ( V_9 -> V_66 != V_67 ) )
return - V_8 ;
V_65 . V_16 = V_68 ;
V_65 . V_69 . V_11 = V_70 ;
V_65 . V_69 . V_71 = V_72 ;
if ( V_9 -> V_73 == NULL )
return - V_8 ;
V_28 = V_9 -> V_73 ( V_9 , (struct V_74 * ) & V_65 ) ;
if ( V_28 == 0 ) {
V_63 -> V_75 . V_76 = V_65 . V_75 . V_11 ;
V_63 -> V_77 |= V_78 ;
V_63 -> signal = V_65 . V_79 . V_11 ;
V_63 -> V_77 |= V_80 ;
}
return V_28 ;
}
int F_14 ( struct V_20 * V_20 , struct V_81 * V_82 )
{
struct V_21 * V_22 ;
struct V_83 * V_84 = F_15 ( V_20 ) ;
T_1 * V_9 ;
struct V_85 V_86 ;
struct V_87 V_88 ;
struct V_89 * V_90 ;
int V_28 ;
int V_2 = 0 ;
int V_91 = 0 ;
int V_92 = 0 ;
V_18 V_93 [ 46 ] ;
int V_94 ;
if ( ! V_82 )
return - V_4 ;
V_22 = V_82 -> V_95 -> V_96 ;
V_9 = V_22 -> V_27 ;
if ( V_84 -> V_97 && V_84 -> V_97 != V_82 )
return - V_98 ;
if ( V_9 -> V_30 == V_99 ) {
F_6 ( V_100 L_4 ) ;
return - V_8 ;
}
V_84 -> V_97 = V_82 ;
memset ( & V_86 , 0x00 , sizeof( struct V_85 ) ) ;
V_86 . V_16 = V_101 ;
V_86 . V_102 . V_11 = V_103 ;
memset ( & V_86 . V_104 . V_11 . V_11 , 0xFF , sizeof( V_86 . V_104 . V_11 . V_11 ) ) ;
V_86 . V_104 . V_11 . V_19 = 6 ;
if ( V_82 -> V_105 > 0 ) {
V_86 . V_106 . V_11 = V_107 ;
V_86 . V_108 . V_11 . V_19 = V_82 -> V_109 -> V_110 ;
memcpy ( V_86 . V_108 . V_11 . V_11 ,
V_82 -> V_109 -> V_108 , V_82 -> V_109 -> V_110 ) ;
} else {
V_86 . V_106 . V_11 = 0 ;
}
V_86 . V_111 . V_11 = 0 ;
for ( V_92 = 0 ;
( V_92 < V_82 -> V_112 ) && V_92 < F_16 ( V_113 ) ;
V_92 ++ )
V_86 . V_114 . V_11 . V_11 [ V_92 ] =
F_17 ( V_82 -> V_115 [ V_92 ] -> V_116 ) ;
V_86 . V_114 . V_11 . V_19 = V_82 -> V_112 ;
V_86 . V_117 . V_11 = 250 ;
V_86 . V_118 . V_11 = 200 ;
V_28 = F_3 ( V_9 , ( V_18 * ) & V_86 ) ;
if ( V_28 ) {
V_2 = F_1 ( V_86 . V_119 . V_11 ) ;
goto exit;
}
V_91 = V_86 . V_91 . V_11 ;
for ( V_92 = 0 ; V_92 < V_91 ; V_92 ++ ) {
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_16 = V_120 ;
V_88 . V_121 . V_11 = V_92 ;
V_28 = F_3 ( V_9 , ( V_18 * ) & V_88 ) ;
if ( ( V_28 != 0 ) ||
( V_88 . V_119 . V_11 != V_122 ) ) {
break;
}
V_93 [ 0 ] = V_123 ;
V_93 [ 1 ] = V_88 . V_108 . V_11 . V_19 ;
V_94 = V_93 [ 1 ] + 2 ;
memcpy ( & V_93 [ 2 ] , & ( V_88 . V_108 . V_11 . V_11 ) , V_88 . V_108 . V_11 . V_19 ) ;
V_90 = F_18 ( V_20 ,
F_19 ( V_20 , F_20 ( V_88 . V_124 . V_11 ) ) ,
( const V_18 * ) & ( V_88 . V_104 . V_11 . V_11 ) ,
V_88 . V_125 . V_11 , V_88 . V_126 . V_11 ,
V_88 . V_127 . V_11 ,
V_93 ,
V_94 ,
( V_88 . signal . V_11 - 65536 ) * 100 ,
V_128
) ;
if ( ! V_90 ) {
V_2 = - V_129 ;
goto exit;
}
F_21 ( V_90 ) ;
}
if ( V_28 )
V_2 = F_1 ( V_88 . V_119 . V_11 ) ;
exit:
F_22 ( V_82 , V_2 ? 1 : 0 ) ;
V_84 -> V_97 = NULL ;
return V_2 ;
}
int F_23 ( struct V_20 * V_20 , T_2 V_130 )
{
struct V_83 * V_84 = F_15 ( V_20 ) ;
T_1 * V_9 = V_84 -> V_9 ;
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
V_2 = - V_36 ;
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
V_2 = - V_36 ;
goto exit;
}
}
exit:
return V_2 ;
}
int F_24 ( struct V_20 * V_20 , struct V_21 * V_22 ,
struct V_137 * V_138 )
{
T_1 * V_9 = V_22 -> V_27 ;
struct V_139 * V_140 = V_138 -> V_140 ;
struct V_141 V_142 ;
T_2 V_10 ;
int V_143 = V_138 -> V_110 ;
int V_144 = - 1 ;
int V_145 = ( V_138 -> V_146 . V_147 == V_44 ) ||
( V_138 -> V_146 . V_147 == V_45 ) ;
int V_28 ;
int V_2 = 0 ;
if ( V_140 ) {
V_144 = F_17 ( V_140 -> V_116 ) ;
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
F_6 ( V_34
L_5 ,
V_138 -> V_149 ) ;
if ( V_145 ) {
if ( V_138 -> V_52 ) {
V_28 = F_2 ( V_9 ,
V_46 ,
V_138 -> V_156 ) ;
if ( V_28 )
goto exit;
switch ( V_138 -> V_156 ) {
case 0 :
V_10 = V_47 ;
break;
case 1 :
V_10 = V_48 ;
break;
case 2 :
V_10 = V_49 ;
break;
case 3 :
V_10 = V_50 ;
break;
default:
V_2 = - V_4 ;
goto exit;
}
V_28 = F_4 ( V_9 ,
V_10 , V_138 -> V_51 ,
( V_18 * ) V_138 -> V_52 ) ;
if ( V_28 )
goto exit;
}
V_28 = F_2 ( V_9 ,
V_157 ,
V_70 ) ;
if ( V_28 )
goto exit;
V_28 = F_2 ( V_9 ,
V_158 ,
V_70 ) ;
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
memcpy ( V_142 . V_108 . V_11 . V_11 , V_138 -> V_108 , V_143 ) ;
V_142 . V_108 . V_11 . V_19 = V_143 ;
V_28 = F_3 ( V_9 , ( V_18 * ) & V_142 ) ;
exit:
if ( V_28 )
V_2 = - V_36 ;
return V_2 ;
}
int F_25 ( struct V_20 * V_20 , struct V_21 * V_22 ,
T_5 V_161 )
{
T_1 * V_9 = V_22 -> V_27 ;
struct V_141 V_142 ;
int V_28 ;
int V_2 = 0 ;
V_142 . V_16 = V_160 ;
memcpy ( V_142 . V_108 . V_11 . V_11 , L_6 , 3 ) ;
V_142 . V_108 . V_11 . V_19 = 3 ;
V_28 = F_3 ( V_9 , ( V_18 * ) & V_142 ) ;
if ( V_28 )
V_2 = - V_36 ;
return V_2 ;
}
int F_26 ( struct V_20 * V_20 , struct V_21 * V_22 ,
struct V_162 * V_26 )
{
return - V_8 ;
}
int F_27 ( struct V_20 * V_20 , struct V_21 * V_22 )
{
return - V_8 ;
}
int F_28 ( struct V_20 * V_20 , enum V_163 type ,
int V_164 )
{
struct V_83 * V_84 = F_15 ( V_20 ) ;
T_1 * V_9 = V_84 -> V_9 ;
T_2 V_11 ;
int V_28 ;
int V_2 = 0 ;
if ( type == V_165 )
V_11 = 30 ;
else
V_11 = F_29 ( V_164 ) ;
V_28 = F_2 ( V_9 ,
V_166 ,
V_11 ) ;
if ( V_28 ) {
V_2 = - V_36 ;
goto exit;
}
exit:
return V_2 ;
}
int F_30 ( struct V_20 * V_20 , int * V_69 )
{
struct V_83 * V_84 = F_15 ( V_20 ) ;
T_1 * V_9 = V_84 -> V_9 ;
struct V_167 V_13 ;
T_3 * V_14 ;
int V_28 ;
int V_2 = 0 ;
V_14 = ( T_3 * ) & V_13 . V_15 . V_11 ;
V_13 . V_16 = V_168 ;
V_14 -> V_10 =
V_166 ;
V_28 = F_3 ( V_9 , ( V_18 * ) & V_13 ) ;
if ( V_28 ) {
V_2 = - V_36 ;
goto exit;
}
* V_69 = V_14 -> V_11 ;
exit:
return V_2 ;
}
void F_31 ( T_1 * V_9 , V_18 V_169 )
{
T_5 V_71 = V_169 ?
V_170 : V_171 ;
F_32 ( V_9 -> V_96 , V_9 -> V_104 ,
NULL , 0 , NULL , 0 , V_71 , V_128 ) ;
}
void F_33 ( T_1 * V_9 )
{
F_34 ( V_9 -> V_96 , 0 , NULL ,
0 , V_128 ) ;
}
void F_35 ( T_1 * V_9 )
{
F_36 ( V_9 -> V_96 , NULL , V_9 -> V_104 ,
NULL , 0 , NULL , 0 , V_128 ) ;
}
struct V_20 * F_37 ( struct V_172 * V_22 , T_1 * V_9 )
{
struct V_20 * V_20 ;
struct V_83 * V_84 ;
V_20 = F_38 ( & V_173 , sizeof( * V_84 ) ) ;
if ( ! V_20 )
return NULL ;
V_84 = F_15 ( V_20 ) ;
V_84 -> V_9 = V_9 ;
memcpy ( V_84 -> V_115 , V_113 , sizeof( V_113 ) ) ;
memcpy ( V_84 -> V_174 , V_175 , sizeof( V_175 ) ) ;
V_84 -> V_176 . V_115 = V_84 -> V_115 ;
V_84 -> V_176 . V_112 = F_16 ( V_113 ) ;
V_84 -> V_176 . V_177 = V_84 -> V_174 ;
V_84 -> V_176 . V_178 = F_16 ( V_175 ) ;
V_84 -> V_176 . V_176 = V_179 ;
V_84 -> V_176 . V_180 . V_181 = false ;
V_20 -> V_182 [ V_179 ] = & V_84 -> V_176 ;
F_39 ( V_20 , V_22 ) ;
V_20 -> V_183 = V_184 ;
V_20 -> V_185 = 1 ;
V_20 -> V_186 = F_40 ( V_32 )
| F_40 ( V_29 ) ;
V_20 -> V_187 = V_188 ;
V_20 -> V_189 = V_190 ;
V_20 -> V_191 = V_192 ;
if ( F_41 ( V_20 ) < 0 )
return NULL ;
return V_20 ;
}
void F_42 ( struct V_20 * V_20 )
{
F_43 ( V_20 ) ;
F_44 ( V_20 ) ;
}
