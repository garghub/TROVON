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
V_28 = F_2 ( V_9 , V_35 , V_11 ) ;
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
int F_14 ( struct V_20 * V_20 , struct V_21 * V_22 ,
struct V_81 * V_82 )
{
struct V_83 * V_84 = F_15 ( V_20 ) ;
T_1 * V_9 = V_22 -> V_27 ;
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
if ( V_84 -> V_95 && V_84 -> V_95 != V_82 )
return - V_96 ;
if ( V_9 -> V_30 == V_97 ) {
F_6 ( V_98 L_4 ) ;
return - V_8 ;
}
V_84 -> V_95 = V_82 ;
memset ( & V_86 , 0x00 , sizeof( struct V_85 ) ) ;
V_86 . V_16 = V_99 ;
V_86 . V_100 . V_11 = V_101 ;
memset ( & V_86 . V_102 . V_11 . V_11 , 0xFF , sizeof( V_86 . V_102 . V_11 . V_11 ) ) ;
V_86 . V_102 . V_11 . V_19 = 6 ;
if ( V_82 -> V_103 > 0 ) {
V_86 . V_104 . V_11 = V_105 ;
V_86 . V_106 . V_11 . V_19 = V_82 -> V_107 -> V_108 ;
memcpy ( V_86 . V_106 . V_11 . V_11 , V_82 -> V_107 -> V_106 , V_82 -> V_107 -> V_108 ) ;
} else {
V_86 . V_104 . V_11 = 0 ;
}
V_86 . V_109 . V_11 = 0 ;
for ( V_92 = 0 ;
( V_92 < V_82 -> V_110 ) && V_92 < F_16 ( V_111 ) ;
V_92 ++ )
V_86 . V_112 . V_11 . V_11 [ V_92 ] =
F_17 ( V_82 -> V_113 [ V_92 ] -> V_114 ) ;
V_86 . V_112 . V_11 . V_19 = V_82 -> V_110 ;
V_86 . V_115 . V_11 = 250 ;
V_86 . V_116 . V_11 = 200 ;
V_28 = F_3 ( V_9 , ( V_18 * ) & V_86 ) ;
if ( V_28 ) {
V_2 = F_1 ( V_86 . V_117 . V_11 ) ;
goto exit;
}
V_91 = V_86 . V_91 . V_11 ;
for ( V_92 = 0 ; V_92 < V_91 ; V_92 ++ ) {
memset ( & V_88 , 0 , sizeof( V_88 ) ) ;
V_88 . V_16 = V_118 ;
V_88 . V_119 . V_11 = V_92 ;
V_28 = F_3 ( V_9 , ( V_18 * ) & V_88 ) ;
if ( ( V_28 != 0 ) ||
( V_88 . V_117 . V_11 != V_120 ) ) {
break;
}
V_93 [ 0 ] = V_121 ;
V_93 [ 1 ] = V_88 . V_106 . V_11 . V_19 ;
V_94 = V_93 [ 1 ] + 2 ;
memcpy ( & V_93 [ 2 ] , & ( V_88 . V_106 . V_11 . V_11 ) , V_88 . V_106 . V_11 . V_19 ) ;
V_90 = F_18 ( V_20 ,
F_19 ( V_20 , F_20 ( V_88 . V_122 . V_11 ) ) ,
( const V_18 * ) & ( V_88 . V_102 . V_11 . V_11 ) ,
V_88 . V_123 . V_11 , V_88 . V_124 . V_11 ,
V_88 . V_125 . V_11 ,
V_93 ,
V_94 ,
( V_88 . signal . V_11 - 65536 ) * 100 ,
V_126
) ;
if ( ! V_90 ) {
V_2 = - V_127 ;
goto exit;
}
F_21 ( V_90 ) ;
}
if ( V_28 )
V_2 = F_1 ( V_88 . V_117 . V_11 ) ;
exit:
F_22 ( V_82 , V_2 ? 1 : 0 ) ;
V_84 -> V_95 = NULL ;
return V_2 ;
}
int F_23 ( struct V_20 * V_20 , T_2 V_128 )
{
struct V_83 * V_84 = F_15 ( V_20 ) ;
T_1 * V_9 = V_84 -> V_9 ;
T_2 V_11 ;
int V_28 ;
int V_2 = 0 ;
if ( V_128 & V_129 ) {
if ( V_20 -> V_130 == - 1 )
V_11 = 2347 ;
else
V_11 = V_20 -> V_130 ;
V_28 = F_2 ( V_9 ,
V_131 ,
V_11 ) ;
if ( V_28 ) {
V_2 = - V_36 ;
goto exit;
}
}
if ( V_128 & V_132 ) {
if ( V_20 -> V_133 == - 1 )
V_11 = 2346 ;
else
V_11 = V_20 -> V_133 ;
V_28 = F_2 ( V_9 ,
V_134 ,
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
struct V_135 * V_136 )
{
T_1 * V_9 = V_22 -> V_27 ;
struct V_137 * V_138 = V_136 -> V_138 ;
struct V_139 V_140 ;
T_2 V_10 ;
int V_141 = V_136 -> V_108 ;
int V_142 = - 1 ;
int V_143 = ( V_136 -> V_144 . V_145 == V_44 ) ||
( V_136 -> V_144 . V_145 == V_45 ) ;
int V_28 ;
int V_2 = 0 ;
if ( V_138 ) {
V_142 = F_17 ( V_138 -> V_114 ) ;
V_28 = F_2 ( V_9 ,
V_146 ,
V_142 ) ;
if ( V_28 )
goto exit;
}
if ( ( V_136 -> V_147 == V_148 ) ||
( ( V_136 -> V_147 == V_149 ) && ! V_143 ) )
V_140 . V_150 . V_11 = V_151 ;
else if ( ( V_136 -> V_147 == V_152 ) ||
( ( V_136 -> V_147 == V_149 ) && V_143 ) )
V_140 . V_150 . V_11 = V_153 ;
else
F_6 ( V_34
L_5 ,
V_136 -> V_147 ) ;
if ( V_143 ) {
if ( V_136 -> V_52 ) {
V_28 = F_2 ( V_9 ,
V_46 ,
V_136 -> V_154 ) ;
if ( V_28 )
goto exit;
switch ( V_136 -> V_154 ) {
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
V_28 = F_4 ( V_9 , V_10 , V_136 -> V_51 , ( V_18 * ) V_136 -> V_52 ) ;
if ( V_28 )
goto exit;
}
V_28 = F_2 ( V_9 ,
V_155 ,
V_70 ) ;
if ( V_28 )
goto exit;
V_28 = F_2 ( V_9 ,
V_156 ,
V_70 ) ;
if ( V_28 )
goto exit;
} else {
V_28 = F_2 ( V_9 ,
V_155 ,
V_157 ) ;
if ( V_28 )
goto exit;
V_28 = F_2 ( V_9 ,
V_156 ,
V_157 ) ;
if ( V_28 )
goto exit;
}
V_140 . V_16 = V_158 ;
memcpy ( V_140 . V_106 . V_11 . V_11 , V_136 -> V_106 , V_141 ) ;
V_140 . V_106 . V_11 . V_19 = V_141 ;
V_28 = F_3 ( V_9 , ( V_18 * ) & V_140 ) ;
exit:
if ( V_28 )
V_2 = - V_36 ;
return V_2 ;
}
int F_25 ( struct V_20 * V_20 , struct V_21 * V_22 ,
T_5 V_159 )
{
T_1 * V_9 = V_22 -> V_27 ;
struct V_139 V_140 ;
int V_28 ;
int V_2 = 0 ;
V_140 . V_16 = V_158 ;
memcpy ( V_140 . V_106 . V_11 . V_11 , L_6 , 3 ) ;
V_140 . V_106 . V_11 . V_19 = 3 ;
V_28 = F_3 ( V_9 , ( V_18 * ) & V_140 ) ;
if ( V_28 )
V_2 = - V_36 ;
return V_2 ;
}
int F_26 ( struct V_20 * V_20 , struct V_21 * V_22 ,
struct V_160 * V_26 )
{
return - V_8 ;
}
int F_27 ( struct V_20 * V_20 , struct V_21 * V_22 )
{
return - V_8 ;
}
int F_28 ( struct V_20 * V_20 , enum V_161 type ,
int V_162 )
{
struct V_83 * V_84 = F_15 ( V_20 ) ;
T_1 * V_9 = V_84 -> V_9 ;
T_2 V_11 ;
int V_28 ;
int V_2 = 0 ;
if ( type == V_163 )
V_11 = 30 ;
else
V_11 = F_29 ( V_162 ) ;
V_28 = F_2 ( V_9 ,
V_164 ,
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
struct V_165 V_13 ;
T_3 * V_14 = ( T_3 * ) & V_13 . V_15 . V_11 ;
int V_28 ;
int V_2 = 0 ;
V_13 . V_16 = V_166 ;
V_14 -> V_10 =
V_164 ;
V_28 = F_3 ( V_9 , ( V_18 * ) & V_13 ) ;
if ( V_28 ) {
V_2 = - V_36 ;
goto exit;
}
* V_69 = V_14 -> V_11 ;
exit:
return V_2 ;
}
void F_31 ( T_1 * V_9 , V_18 V_167 )
{
T_5 V_71 = V_167 ? V_168 : V_169 ;
F_32 ( V_9 -> V_170 , V_9 -> V_102 ,
NULL , 0 , NULL , 0 , V_71 , V_126 ) ;
}
void F_33 ( T_1 * V_9 )
{
F_34 ( V_9 -> V_170 , 0 , NULL ,
0 , V_126 ) ;
}
void F_35 ( T_1 * V_9 )
{
F_36 ( V_9 -> V_170 , NULL , V_9 -> V_102 ,
NULL , 0 , NULL , 0 , V_126 ) ;
}
struct V_20 * F_37 ( struct V_171 * V_22 , T_1 * V_9 )
{
struct V_20 * V_20 ;
struct V_83 * V_84 ;
V_20 = F_38 ( & V_172 , sizeof( struct V_83 ) ) ;
if ( ! V_20 )
return NULL ;
V_84 = F_15 ( V_20 ) ;
V_84 -> V_9 = V_9 ;
memcpy ( V_84 -> V_113 , V_111 , sizeof( V_111 ) ) ;
memcpy ( V_84 -> V_173 , V_174 , sizeof( V_174 ) ) ;
V_84 -> V_175 . V_113 = V_84 -> V_113 ;
V_84 -> V_175 . V_110 = F_16 ( V_111 ) ;
V_84 -> V_175 . V_176 = V_84 -> V_173 ;
V_84 -> V_175 . V_177 = F_16 ( V_174 ) ;
V_84 -> V_175 . V_175 = V_178 ;
V_84 -> V_175 . V_179 . V_180 = false ;
V_20 -> V_181 [ V_178 ] = & V_84 -> V_175 ;
F_39 ( V_20 , V_22 ) ;
V_20 -> V_182 = V_183 ;
V_20 -> V_184 = 1 ;
V_20 -> V_185 = F_40 ( V_32 )
| F_40 ( V_29 ) ;
V_20 -> V_186 = V_187 ;
V_20 -> V_188 = V_189 ;
V_20 -> V_190 = V_191 ;
if ( F_41 ( V_20 ) < 0 )
return NULL ;
return V_20 ;
}
void F_42 ( struct V_20 * V_20 )
{
F_43 ( V_20 ) ;
F_44 ( V_20 ) ;
}
