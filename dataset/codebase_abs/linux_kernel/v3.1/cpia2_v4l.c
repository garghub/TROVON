static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_4 * V_5 ;
if ( ! V_3 ) {
F_3 ( L_1 ) ;
return - V_6 ;
}
if ( ! V_3 -> V_7 )
return - V_6 ;
if ( V_3 -> V_8 == 0 ) {
if ( F_4 ( V_3 ) )
return - V_9 ;
if ( F_5 ( V_3 ) < 0 )
return - V_10 ;
V_3 -> V_11 = 0 ;
V_3 -> V_12 = 0 ;
}
V_5 = F_6 ( sizeof( * V_5 ) , V_13 ) ;
if ( ! V_5 )
return - V_9 ;
V_1 -> V_14 = V_5 ;
V_5 -> V_15 = V_16 ;
F_7 ( & V_3 -> V_15 , & V_5 -> V_15 ) ;
V_5 -> V_17 = 0 ;
++ V_3 -> V_8 ;
F_8 ( V_3 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_18 * V_19 = F_10 ( V_1 ) ;
struct V_2 * V_3 = F_11 ( V_19 ) ;
struct V_4 * V_5 = V_1 -> V_14 ;
if ( V_3 -> V_7 &&
( V_3 -> V_8 == 1 || V_5 -> V_15 == V_20 ) ) {
F_12 ( V_3 ) ;
if ( V_3 -> V_8 == 1 ) {
F_13 ( V_3 ) ;
F_14 ( V_3 ) ;
F_15 ( V_3 ) ;
}
}
if ( V_5 -> V_17 )
V_3 -> V_17 = 0 ;
F_16 ( & V_3 -> V_15 , V_5 -> V_15 ) ;
V_1 -> V_14 = NULL ;
F_17 ( V_5 ) ;
if ( -- V_3 -> V_8 == 0 ) {
F_15 ( V_3 ) ;
if ( ! V_3 -> V_7 ) {
F_18 ( V_19 ) ;
F_17 ( V_3 ) ;
return 0 ;
}
}
return 0 ;
}
static T_1 F_19 ( struct V_1 * V_1 , char T_2 * V_21 , T_3 V_22 ,
T_4 * V_23 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_24 = V_1 -> V_25 & V_26 ;
struct V_4 * V_5 = V_1 -> V_14 ;
if( ! V_3 )
return - V_27 ;
if( V_5 -> V_15 != V_20 ) {
return - V_28 ;
}
return F_20 ( V_3 , V_21 , V_22 , V_24 ) ;
}
static unsigned int F_21 ( struct V_1 * V_29 , struct V_30 * V_31 )
{
struct V_2 * V_3 = F_2 ( V_29 ) ;
struct V_4 * V_5 = V_29 -> V_14 ;
if( ! V_3 )
return V_32 ;
if( V_5 -> V_15 != V_20 ) {
return V_32 ;
}
return F_22 ( V_3 , V_29 , V_31 ) ;
}
static int F_23 ( struct V_2 * V_3 , int V_33 )
{
struct V_34 * V_35 = & V_3 -> V_36 [ V_33 ] ;
while ( 1 ) {
if ( V_35 -> V_37 == V_38 )
return 0 ;
if ( ! V_3 -> V_39 ) {
V_35 -> V_37 = V_38 ;
V_35 -> V_40 = 0 ;
return 0 ;
}
F_24 ( & V_3 -> V_41 ) ;
F_25 ( V_3 -> V_42 ,
! V_3 -> V_39 ||
V_35 -> V_37 == V_38 ) ;
F_26 ( & V_3 -> V_41 ) ;
if ( F_27 ( V_43 ) )
return - V_44 ;
if( ! V_3 -> V_7 )
return - V_45 ;
}
}
static long F_28 ( struct V_1 * V_1 , void * V_5 , bool V_46 ,
int V_47 , void * V_48 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
T_5 V_49 ;
if ( V_47 != V_50 )
return - V_27 ;
V_49 = * ( T_5 * ) V_48 ;
if ( V_49 & ~ 0xFFU )
return - V_27 ;
return F_29 ( V_3 , ( unsigned char ) V_49 ) ;
}
static int F_30 ( struct V_1 * V_1 , void * V_5 , struct V_51 * V_52 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
strcpy ( V_52 -> V_53 , L_2 ) ;
if ( V_3 -> V_54 . V_55 . V_56 == 0x151 )
strcpy ( V_52 -> V_57 , L_3 ) ;
else
strcpy ( V_52 -> V_57 , L_4 ) ;
switch ( V_3 -> V_54 . V_55 . V_58 ) {
case V_59 :
strcat ( V_52 -> V_57 , L_5 ) ;
break;
case V_60 :
strcat ( V_52 -> V_57 , L_6 ) ;
break;
default:
strcat ( V_52 -> V_57 , L_7 ) ;
break;
}
switch ( V_3 -> V_54 . V_61 . V_62 ) {
case V_63 :
strcat ( V_52 -> V_57 , L_8 ) ;
break;
case V_64 :
strcat ( V_52 -> V_57 , L_9 ) ;
break;
case V_65 :
strcat ( V_52 -> V_57 , L_10 ) ;
break;
case V_66 :
strcat ( V_52 -> V_57 , L_11 ) ;
break;
case V_67 :
strcat ( V_52 -> V_57 , L_12 ) ;
break;
default:
strcat ( V_52 -> V_57 , L_13 ) ;
break;
}
if ( F_31 ( V_3 -> V_19 , V_52 -> V_68 , sizeof( V_52 -> V_68 ) ) < 0 )
memset ( V_52 -> V_68 , 0 , sizeof( V_52 -> V_68 ) ) ;
V_52 -> V_69 = V_70 |
V_71 |
V_72 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , void * V_5 , struct V_73 * V_74 )
{
if ( V_74 -> V_75 )
return - V_27 ;
strcpy ( V_74 -> V_76 , L_14 ) ;
V_74 -> type = V_77 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_1 , void * V_5 , unsigned int * V_74 )
{
* V_74 = 0 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , void * V_5 , unsigned int V_74 )
{
return V_74 ? - V_27 : 0 ;
}
static int F_35 ( struct V_1 * V_1 , void * V_5 ,
struct V_78 * V_79 )
{
int V_75 = V_79 -> V_75 ;
if ( V_75 < 0 || V_75 > 1 )
return - V_27 ;
memset ( V_79 , 0 , sizeof( * V_79 ) ) ;
V_79 -> V_75 = V_75 ;
V_79 -> type = V_80 ;
V_79 -> V_81 = V_82 ;
switch( V_75 ) {
case 0 :
strcpy ( V_79 -> V_83 , L_15 ) ;
V_79 -> V_84 = V_85 ;
break;
case 1 :
strcpy ( V_79 -> V_83 , L_16 ) ;
V_79 -> V_84 = V_86 ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static int F_36 ( struct V_1 * V_1 , void * V_5 ,
struct V_87 * V_79 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( V_79 -> V_88 . V_89 . V_84 != V_85 &&
V_79 -> V_88 . V_89 . V_84 != V_86 )
return - V_27 ;
V_79 -> V_88 . V_89 . V_90 = V_91 ;
V_79 -> V_88 . V_89 . V_92 = 0 ;
V_79 -> V_88 . V_89 . V_93 = V_3 -> V_94 ;
V_79 -> V_88 . V_89 . V_95 = V_96 ;
V_79 -> V_88 . V_89 . V_97 = 0 ;
switch ( F_37 ( V_79 -> V_88 . V_89 . V_98 , V_79 -> V_88 . V_89 . V_99 ) ) {
case V_100 :
V_79 -> V_88 . V_89 . V_98 = 640 ;
V_79 -> V_88 . V_89 . V_99 = 480 ;
break;
case V_101 :
V_79 -> V_88 . V_89 . V_98 = 352 ;
V_79 -> V_88 . V_89 . V_99 = 288 ;
break;
case V_102 :
V_79 -> V_88 . V_89 . V_98 = 320 ;
V_79 -> V_88 . V_89 . V_99 = 240 ;
break;
case V_103 :
V_79 -> V_88 . V_89 . V_98 = 288 ;
V_79 -> V_88 . V_89 . V_99 = 216 ;
break;
case V_104 :
V_79 -> V_88 . V_89 . V_98 = 256 ;
V_79 -> V_88 . V_89 . V_99 = 192 ;
break;
case V_105 :
V_79 -> V_88 . V_89 . V_98 = 224 ;
V_79 -> V_88 . V_89 . V_99 = 168 ;
break;
case V_106 :
V_79 -> V_88 . V_89 . V_98 = 192 ;
V_79 -> V_88 . V_89 . V_99 = 144 ;
break;
case V_107 :
default:
V_79 -> V_88 . V_89 . V_98 = 176 ;
V_79 -> V_88 . V_89 . V_99 = 144 ;
break;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_1 , void * V_108 ,
struct V_87 * V_79 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_108 ;
int V_109 , V_35 ;
V_109 = F_39 ( & V_3 -> V_15 , V_5 -> V_15 ) ;
if ( V_109 )
return V_109 ;
V_109 = F_36 ( V_1 , V_108 , V_79 ) ;
if( V_109 != 0 )
return V_109 ;
V_109 = F_40 ( & V_3 -> V_15 , & V_5 -> V_15 , V_20 ) ;
if( V_109 != 0 ) {
return V_109 ;
}
V_3 -> V_84 = V_79 -> V_88 . V_89 . V_84 ;
V_3 -> V_54 . V_110 . V_111 = 0 ;
F_41 ( L_17 ,
V_79 -> V_88 . V_89 . V_98 , V_79 -> V_88 . V_89 . V_99 ) ;
if ( V_79 -> V_88 . V_89 . V_98 != V_3 -> V_98 ||
V_79 -> V_88 . V_89 . V_99 != V_3 -> V_99 ) {
V_3 -> V_98 = V_79 -> V_88 . V_89 . V_98 ;
V_3 -> V_99 = V_79 -> V_88 . V_89 . V_99 ;
V_3 -> V_54 . V_112 . V_98 = V_79 -> V_88 . V_89 . V_98 ;
V_3 -> V_54 . V_112 . V_99 = V_79 -> V_88 . V_89 . V_99 ;
F_42 ( V_3 ) ;
}
for ( V_35 = 0 ; V_35 < V_3 -> V_113 ; ++ V_35 ) {
if ( V_3 -> V_36 [ V_35 ] . V_37 == V_114 )
if ( ( V_109 = F_23 ( V_3 , V_35 ) ) < 0 )
return V_109 ;
V_3 -> V_36 [ V_35 ] . V_37 = V_115 ;
}
return 0 ;
}
static int F_43 ( struct V_1 * V_1 , void * V_5 ,
struct V_87 * V_79 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
V_79 -> V_88 . V_89 . V_98 = V_3 -> V_98 ;
V_79 -> V_88 . V_89 . V_99 = V_3 -> V_99 ;
V_79 -> V_88 . V_89 . V_84 = V_3 -> V_84 ;
V_79 -> V_88 . V_89 . V_90 = V_91 ;
V_79 -> V_88 . V_89 . V_92 = 0 ;
V_79 -> V_88 . V_89 . V_93 = V_3 -> V_94 ;
V_79 -> V_88 . V_89 . V_95 = V_96 ;
V_79 -> V_88 . V_89 . V_97 = 0 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_1 , void * V_5 , struct V_116 * V_117 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( V_117 -> type != V_80 )
return - V_27 ;
V_117 -> V_118 . V_119 = 0 ;
V_117 -> V_118 . V_120 = 0 ;
V_117 -> V_118 . V_98 = V_3 -> V_98 ;
V_117 -> V_118 . V_99 = V_3 -> V_99 ;
V_117 -> V_121 . V_119 = 0 ;
V_117 -> V_121 . V_120 = 0 ;
V_117 -> V_121 . V_98 = V_3 -> V_98 ;
V_117 -> V_121 . V_99 = V_3 -> V_99 ;
V_117 -> V_122 . V_123 = 1 ;
V_117 -> V_122 . V_124 = 1 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_1 , void * V_5 , struct V_125 * V_117 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_74 ;
for( V_74 = 0 ; V_74 < V_126 ; ++ V_74 ) {
if( V_117 -> V_127 == V_128 [ V_74 ] . V_127 ) {
memcpy ( V_117 , V_128 + V_74 , sizeof( * V_117 ) ) ;
break;
}
}
if( V_74 == V_126 )
return - V_27 ;
switch( V_117 -> V_127 ) {
case V_129 :
if ( V_3 -> V_54 . V_55 . V_58 == V_59 )
V_117 -> V_130 = 1 ;
break;
case V_131 :
if( V_3 -> V_54 . V_55 . V_58 == V_59 )
V_117 -> V_81 |= V_132 ;
break;
case V_133 :
if( V_3 -> V_54 . V_55 . V_58 == V_59 &&
V_3 -> V_54 . V_61 . V_62 == V_67 ) {
for( V_74 = 0 ; V_74 < V_117 -> V_134 ; ++ V_74 ) {
if( V_135 [ V_74 ] . V_136 ==
V_137 ) {
V_117 -> V_134 = V_74 ;
V_117 -> V_138 = V_74 ;
}
}
}
break;
case V_139 :
if( V_3 -> V_54 . V_55 . V_58 != V_59 )
V_117 -> V_81 |= V_132 ;
break;
case V_140 :
if( V_3 -> V_54 . V_55 . V_56 != 0x151 )
V_117 -> V_81 |= V_132 ;
break;
default:
break;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_1 , void * V_5 , struct V_141 * V_142 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
switch( V_142 -> V_127 ) {
case V_139 :
if ( V_142 -> V_75 >= V_143 )
return - V_27 ;
strcpy ( V_142 -> V_76 , V_144 [ V_142 -> V_75 ] . V_76 ) ;
break;
case V_133 :
{
int V_134 = V_145 - 1 ;
if( V_3 -> V_54 . V_55 . V_58 == V_59 &&
V_3 -> V_54 . V_61 . V_62 == V_67 ) {
int V_74 ;
for( V_74 = 0 ; V_74 < V_134 ; ++ V_74 ) {
if( V_135 [ V_74 ] . V_136 ==
V_137 )
V_134 = V_74 ;
}
}
if ( V_142 -> V_75 > V_134 )
return - V_27 ;
strcpy ( V_142 -> V_76 , V_135 [ V_142 -> V_75 ] . V_76 ) ;
break;
}
case V_140 :
if ( V_142 -> V_75 >= V_146 )
return - V_27 ;
strcpy ( V_142 -> V_76 , V_147 [ V_142 -> V_75 ] . V_76 ) ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_1 , void * V_5 , struct V_148 * V_117 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
switch( V_117 -> V_127 ) {
case V_129 :
F_48 ( V_3 , V_149 ,
V_150 , 0 ) ;
V_117 -> V_136 = V_3 -> V_54 . V_151 . V_152 ;
break;
case V_153 :
F_48 ( V_3 , V_154 ,
V_150 , 0 ) ;
V_117 -> V_136 = V_3 -> V_54 . V_151 . V_155 ;
break;
case V_156 :
F_48 ( V_3 , V_157 ,
V_150 , 0 ) ;
V_117 -> V_136 = V_3 -> V_54 . V_151 . V_158 ;
break;
case V_159 :
F_48 ( V_3 , V_160 ,
V_150 , 0 ) ;
V_117 -> V_136 = ( V_3 -> V_54 . V_161 . V_162 &
V_163 ) != 0 ;
break;
case V_131 :
F_48 ( V_3 , V_160 ,
V_150 , 0 ) ;
V_117 -> V_136 = ( V_3 -> V_54 . V_161 . V_162 &
V_164 ) != 0 ;
break;
case V_165 :
V_117 -> V_136 = V_3 -> V_54 . V_166 . V_167 ;
break;
case V_50 :
F_48 ( V_3 , V_168 ,
V_150 , 0 ) ;
V_117 -> V_136 = V_3 -> V_54 . V_161 . V_169 ;
break;
case V_139 :
{
int V_74 , V_170 ;
F_48 ( V_3 , V_171 ,
V_150 , 0 ) ;
if( V_3 -> V_54 . V_172 . V_173 &
V_174 ) {
V_170 = V_175 ;
} else {
if( V_3 -> V_54 . V_172 . V_173 &
V_176 ) {
V_170 = V_177 ;
} else {
V_170 = V_178 ;
}
}
for( V_74 = 0 ; V_74 < V_143 ; V_74 ++ ) {
if( V_144 [ V_74 ] . V_136 == V_170 ) {
V_117 -> V_136 = V_74 ;
break;
}
}
if( V_74 == V_143 )
return - V_27 ;
break;
}
case V_133 :
{
int V_134 = V_145 - 1 ;
int V_74 ;
for( V_74 = 0 ; V_74 <= V_134 ; V_74 ++ ) {
if( V_3 -> V_54 . V_161 . V_179 ==
V_135 [ V_74 ] . V_136 )
break;
}
if( V_74 > V_134 )
return - V_27 ;
V_117 -> V_136 = V_74 ;
break;
}
case V_180 :
V_117 -> V_136 = V_3 -> V_54 . V_181 . V_182 ;
break;
case V_140 :
{
int V_74 ;
F_48 ( V_3 , V_168 ,
V_150 , 0 ) ;
for( V_74 = 0 ; V_74 < V_146 ; V_74 ++ ) {
if( ( V_3 -> V_54 . V_161 . V_169 & V_183 ) ==
V_147 [ V_74 ] . V_136 ) {
break;
}
}
if( V_74 == V_146 )
return - V_27 ;
V_117 -> V_136 = V_74 ;
break;
}
case V_184 :
return - V_27 ;
default:
return - V_27 ;
}
F_41 ( L_18 , V_117 -> V_127 , V_117 -> V_136 ) ;
return 0 ;
}
static int F_49 ( struct V_1 * V_1 , void * V_5 , struct V_148 * V_117 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_74 ;
int V_185 = 0 ;
F_41 ( L_19 , V_117 -> V_127 , V_117 -> V_136 ) ;
for( V_74 = 0 ; V_74 < V_126 ; V_74 ++ ) {
if( V_117 -> V_127 == V_128 [ V_74 ] . V_127 ) {
if( V_117 -> V_136 < V_128 [ V_74 ] . V_130 ||
V_117 -> V_136 > V_128 [ V_74 ] . V_134 ) {
return - V_27 ;
}
break;
}
}
if( V_74 == V_126 )
return - V_27 ;
switch( V_117 -> V_127 ) {
case V_129 :
F_50 ( V_3 , V_117 -> V_136 ) ;
break;
case V_153 :
F_51 ( V_3 , V_117 -> V_136 ) ;
break;
case V_156 :
F_52 ( V_3 , V_117 -> V_136 ) ;
break;
case V_159 :
F_53 ( V_3 , V_117 -> V_136 ) ;
break;
case V_131 :
F_54 ( V_3 , V_117 -> V_136 ) ;
break;
case V_165 :
V_185 = F_55 ( V_3 , V_117 -> V_136 ) ;
break;
case V_50 :
V_185 = F_29 ( V_3 , V_117 -> V_136 ) ;
break;
case V_139 :
V_185 = F_56 ( V_3 ,
V_144 [ V_117 -> V_136 ] . V_136 ) ;
break;
case V_133 :
V_185 = F_57 ( V_3 , V_135 [ V_117 -> V_136 ] . V_136 ) ;
break;
case V_180 :
V_185 = F_58 ( V_3 , V_117 -> V_136 ) ;
break;
case V_140 :
V_185 = F_29 ( V_3 , V_147 [ V_117 -> V_136 ] . V_136 ) ;
break;
case V_184 :
F_59 ( V_3 ) ;
F_5 ( V_3 ) ;
F_60 ( V_3 ) ;
break;
default:
V_185 = - V_27 ;
}
return V_185 ;
}
static int F_61 ( struct V_1 * V_1 , void * V_5 , struct V_186 * V_187 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
memset ( V_187 , 0 , sizeof( * V_187 ) ) ;
V_187 -> V_188 = 80 ;
V_187 -> V_189 = V_190 | V_191 ;
if( ! V_3 -> V_54 . V_110 . V_111 ) {
V_187 -> V_189 |= V_192 ;
}
V_187 -> V_193 = V_3 -> V_193 ;
V_187 -> V_11 = V_3 -> V_11 ;
if( V_3 -> V_11 > 0 ) {
memcpy ( V_187 -> V_194 , V_3 -> V_194 , V_3 -> V_11 ) ;
V_187 -> V_189 |= V_195 ;
}
V_187 -> V_12 = V_3 -> V_12 ;
if( V_3 -> V_12 > 0 ) {
memcpy ( V_187 -> V_196 , V_3 -> V_196 , V_3 -> V_12 ) ;
V_187 -> V_189 |= V_197 ;
}
F_41 ( L_20 ,
V_187 -> V_11 , V_187 -> V_12 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_1 , void * V_5 , struct V_186 * V_187 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_41 ( L_21 ,
V_187 -> V_11 , V_187 -> V_12 ) ;
V_3 -> V_54 . V_110 . V_111 =
! ( V_187 -> V_189 & V_192 ) ;
if( V_187 -> V_11 != 0 ) {
if( V_187 -> V_11 > 0 &&
V_187 -> V_11 <= sizeof( V_3 -> V_194 ) &&
V_187 -> V_193 >= 0 && V_187 -> V_193 <= 15 ) {
V_3 -> V_193 = V_187 -> V_193 ;
V_3 -> V_11 = V_187 -> V_11 ;
memcpy ( V_3 -> V_194 , V_187 -> V_194 , V_187 -> V_11 ) ;
} else {
LOG ( L_22 ,
V_187 -> V_193 , V_187 -> V_11 ) ;
return - V_27 ;
}
} else {
V_3 -> V_11 = 0 ;
}
if( V_187 -> V_12 != 0 ) {
if( V_187 -> V_12 > 0 &&
V_187 -> V_12 <= sizeof( V_3 -> V_196 ) ) {
V_3 -> V_12 = V_187 -> V_12 ;
memcpy ( V_3 -> V_196 , V_187 -> V_196 , V_187 -> V_12 ) ;
} else {
LOG ( L_23 , V_187 -> V_12 ) ;
return - V_27 ;
}
}
return 0 ;
}
static int F_63 ( struct V_1 * V_1 , void * V_5 , struct V_198 * V_199 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if( V_199 -> type != V_80 ||
V_199 -> V_200 != V_201 )
return - V_27 ;
F_41 ( L_24 , V_199 -> V_22 , V_3 -> V_113 ) ;
V_199 -> V_22 = V_3 -> V_113 ;
memset ( & V_199 -> V_202 , 0 , sizeof( V_199 -> V_202 ) ) ;
return 0 ;
}
static int F_64 ( struct V_1 * V_1 , void * V_5 , struct V_203 * V_21 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if( V_21 -> type != V_80 ||
V_21 -> V_75 > V_3 -> V_113 )
return - V_27 ;
V_21 -> V_142 . V_204 = V_3 -> V_36 [ V_21 -> V_75 ] . V_205 - V_3 -> V_206 ;
V_21 -> V_40 = V_3 -> V_94 ;
V_21 -> V_200 = V_201 ;
if( V_3 -> V_17 )
V_21 -> V_81 = V_207 ;
else
V_21 -> V_81 = 0 ;
switch ( V_3 -> V_36 [ V_21 -> V_75 ] . V_37 ) {
case V_115 :
case V_208 :
case V_114 :
V_21 -> V_209 = 0 ;
V_21 -> V_81 = V_210 ;
break;
case V_38 :
V_21 -> V_209 = V_3 -> V_36 [ V_21 -> V_75 ] . V_40 ;
V_21 -> V_211 = V_3 -> V_36 [ V_21 -> V_75 ] . V_211 ;
V_21 -> V_212 = V_3 -> V_36 [ V_21 -> V_75 ] . V_213 ;
V_21 -> V_81 = V_214 ;
break;
}
F_41 ( L_25 ,
V_21 -> V_75 , V_21 -> V_142 . V_204 , V_21 -> V_81 , V_21 -> V_212 ,
V_21 -> V_209 ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_1 , void * V_5 , struct V_203 * V_21 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if( V_21 -> type != V_80 ||
V_21 -> V_200 != V_201 ||
V_21 -> V_75 > V_3 -> V_113 )
return - V_27 ;
F_41 ( L_26 , V_21 -> V_75 ) ;
if( V_3 -> V_36 [ V_21 -> V_75 ] . V_37 == V_38 )
V_3 -> V_36 [ V_21 -> V_75 ] . V_37 = V_115 ;
return 0 ;
}
static int F_66 ( struct V_2 * V_3 )
{
int V_74 ;
int V_215 = - 1 ;
for ( V_74 = 0 ; V_74 < V_3 -> V_113 ; V_74 ++ ) {
if( V_3 -> V_36 [ V_74 ] . V_37 == V_38 ) {
if( V_215 < 0 ) {
V_215 = V_74 ;
} else {
struct V_216 * V_217 , * V_218 ;
V_217 = & V_3 -> V_36 [ V_74 ] . V_211 ;
V_218 = & V_3 -> V_36 [ V_215 ] . V_211 ;
if( V_217 -> V_219 < V_218 -> V_219 ||
( V_217 -> V_219 == V_218 -> V_219 &&
V_217 -> V_220 < V_218 -> V_220 ) )
V_215 = V_74 ;
}
}
}
return V_215 ;
}
static int F_67 ( struct V_1 * V_1 , void * V_5 , struct V_203 * V_21 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_35 ;
if( V_21 -> type != V_80 ||
V_21 -> V_200 != V_201 )
return - V_27 ;
V_35 = F_66 ( V_3 ) ;
if( V_35 < 0 && V_1 -> V_25 & V_26 )
return - V_221 ;
if( V_35 < 0 ) {
struct V_34 * V_222 = V_3 -> V_223 ;
F_24 ( & V_3 -> V_41 ) ;
F_25 ( V_3 -> V_42 ,
! V_3 -> V_7 ||
( V_222 = V_3 -> V_223 ) -> V_37 == V_38 ) ;
F_26 ( & V_3 -> V_41 ) ;
if ( F_27 ( V_43 ) )
return - V_44 ;
if( ! V_3 -> V_7 )
return - V_45 ;
V_35 = V_222 -> V_224 ;
}
V_21 -> V_75 = V_35 ;
V_21 -> V_209 = V_3 -> V_36 [ V_21 -> V_75 ] . V_40 ;
V_21 -> V_81 = V_207 | V_214 ;
V_21 -> V_90 = V_91 ;
V_21 -> V_211 = V_3 -> V_36 [ V_21 -> V_75 ] . V_211 ;
V_21 -> V_212 = V_3 -> V_36 [ V_21 -> V_75 ] . V_213 ;
V_21 -> V_142 . V_204 = V_3 -> V_36 [ V_21 -> V_75 ] . V_205 - V_3 -> V_206 ;
V_21 -> V_40 = V_3 -> V_94 ;
V_21 -> V_225 = 0 ;
V_21 -> V_202 = 0 ;
memset ( & V_21 -> V_226 , 0 , sizeof( V_21 -> V_226 ) ) ;
F_41 ( L_27 , V_21 -> V_75 ,
V_3 -> V_36 [ V_21 -> V_75 ] . V_37 , V_21 -> V_212 , V_21 -> V_209 ) ;
return 0 ;
}
static int F_68 ( struct V_1 * V_1 , void * V_108 , enum V_227 * V_228 )
{
struct V_4 * V_5 = V_108 ;
* V_228 = V_5 -> V_15 ;
return 0 ;
}
static int F_69 ( struct V_1 * V_1 , void * V_108 , enum V_227 V_15 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_108 ;
if ( V_3 -> V_39 && V_15 != V_5 -> V_15 &&
V_5 -> V_15 == V_20 )
return - V_28 ;
if ( V_15 == V_20 && V_15 != V_5 -> V_15 &&
F_70 ( & V_3 -> V_15 ) == V_20 )
return - V_28 ;
return F_40 ( & V_3 -> V_15 , & V_5 -> V_15 , V_15 ) ;
}
static int F_71 ( struct V_1 * V_1 , void * V_5 , enum V_229 type )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_41 ( L_28 , V_3 -> V_39 ) ;
if ( ! V_3 -> V_17 || type != V_80 )
return - V_27 ;
if ( ! V_3 -> V_39 )
return F_72 ( V_3 ,
V_3 -> V_54 . V_181 . V_182 ) ;
return - V_27 ;
}
static int F_73 ( struct V_1 * V_1 , void * V_5 , enum V_229 type )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_41 ( L_29 , V_3 -> V_39 ) ;
if ( ! V_3 -> V_17 || type != V_80 )
return - V_27 ;
if ( V_3 -> V_39 )
return F_12 ( V_3 ) ;
return - V_27 ;
}
static int F_74 ( struct V_1 * V_1 , struct V_230 * V_231 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_185 ;
struct V_4 * V_5 = V_1 -> V_14 ;
if( V_5 -> V_15 != V_20 ) {
return - V_28 ;
}
V_185 = F_75 ( V_3 , V_231 ) ;
if( ! V_185 )
V_5 -> V_17 = 1 ;
return V_185 ;
}
static void F_76 ( struct V_2 * V_3 )
{
V_3 -> V_98 = V_3 -> V_54 . V_112 . V_98 ;
V_3 -> V_99 = V_3 -> V_54 . V_112 . V_99 ;
V_3 -> V_94 = V_232 ;
V_3 -> V_113 = V_233 ;
V_3 -> V_54 . V_172 . V_234 = V_235 ;
V_3 -> V_54 . V_172 . V_236 = V_237 ;
V_3 -> V_54 . V_181 . V_182 = V_238 ;
V_3 -> V_84 = V_86 ;
F_77 ( & V_3 -> V_15 ) ;
}
int F_78 ( struct V_2 * V_3 )
{
V_3 -> V_239 = F_79 () ;
if( ! V_3 -> V_239 )
return - V_9 ;
memcpy ( V_3 -> V_239 , & V_240 , sizeof( V_240 ) ) ;
F_80 ( V_3 -> V_239 , V_3 ) ;
V_3 -> V_239 -> V_241 = & V_3 -> V_41 ;
F_76 ( V_3 ) ;
if ( F_81 ( V_3 -> V_239 , V_242 , V_243 ) < 0 ) {
F_3 ( L_30 ) ;
F_82 ( V_3 -> V_239 ) ;
return - V_6 ;
}
return 0 ;
}
void F_83 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_8 ) {
F_18 ( V_3 -> V_239 ) ;
} else {
LOG ( L_31
L_32 ,
F_84 ( V_3 -> V_239 ) ) ;
}
}
static void T_6 F_85 ( void )
{
if( V_232 < V_244 ) {
V_232 = V_244 ;
LOG ( L_33 , V_232 ) ;
} else if( V_232 > 1024 * 1024 ) {
V_232 = 1024 * 1024 ;
LOG ( L_34 ,
V_232 ) ;
} else {
V_232 += V_244 - 1 ;
V_232 &= ~ ( V_244 - 1 ) ;
}
if( V_233 < 1 ) {
V_233 = 1 ;
LOG ( L_35 , V_233 ) ;
} else if( V_233 > V_245 ) {
V_233 = V_245 ;
LOG ( L_36 , V_233 ) ;
}
if( V_238 < V_246 || V_238 > V_247 ) {
V_238 = V_248 ;
LOG ( L_37 , V_238 ) ;
}
if ( V_235 != V_175 && V_235 != V_249 ) {
V_235 = V_175 ;
LOG ( L_38 ,
V_235 ) ;
}
if ( V_237 != V_177 && V_237 != V_178 ) {
V_237 = V_178 ;
LOG ( L_38 ,
V_237 ) ;
}
if( V_243 < - 1 || V_243 > 64 ) {
V_243 = - 1 ;
LOG ( L_39 ) ;
}
F_41 ( L_40 ,
V_233 , V_232 , V_238 ) ;
}
static int T_6 F_86 ( void )
{
LOG ( L_41 ,
V_250 , V_251 ) ;
F_85 () ;
F_87 () ;
return 0 ;
}
static void T_7 F_88 ( void )
{
F_89 () ;
F_90 ( 2 * V_252 ) ;
}
