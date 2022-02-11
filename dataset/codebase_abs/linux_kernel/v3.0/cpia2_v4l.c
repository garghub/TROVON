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
V_52 -> V_61 = F_32 ( V_69 , V_70 ,
V_71 ) ;
V_52 -> V_72 = V_73 |
V_74 |
V_75 ;
return 0 ;
}
static int F_33 ( struct V_1 * V_1 , void * V_5 , struct V_76 * V_77 )
{
if ( V_77 -> V_78 )
return - V_27 ;
strcpy ( V_77 -> V_79 , L_14 ) ;
V_77 -> type = V_80 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , void * V_5 , unsigned int * V_77 )
{
* V_77 = 0 ;
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , void * V_5 , unsigned int V_77 )
{
return V_77 ? - V_27 : 0 ;
}
static int F_36 ( struct V_1 * V_1 , void * V_5 ,
struct V_81 * V_82 )
{
int V_78 = V_82 -> V_78 ;
if ( V_78 < 0 || V_78 > 1 )
return - V_27 ;
memset ( V_82 , 0 , sizeof( * V_82 ) ) ;
V_82 -> V_78 = V_78 ;
V_82 -> type = V_83 ;
V_82 -> V_84 = V_85 ;
switch( V_78 ) {
case 0 :
strcpy ( V_82 -> V_86 , L_15 ) ;
V_82 -> V_87 = V_88 ;
break;
case 1 :
strcpy ( V_82 -> V_86 , L_16 ) ;
V_82 -> V_87 = V_89 ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , void * V_5 ,
struct V_90 * V_82 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( V_82 -> V_91 . V_92 . V_87 != V_88 &&
V_82 -> V_91 . V_92 . V_87 != V_89 )
return - V_27 ;
V_82 -> V_91 . V_92 . V_93 = V_94 ;
V_82 -> V_91 . V_92 . V_95 = 0 ;
V_82 -> V_91 . V_92 . V_96 = V_3 -> V_97 ;
V_82 -> V_91 . V_92 . V_98 = V_99 ;
V_82 -> V_91 . V_92 . V_100 = 0 ;
switch ( F_38 ( V_82 -> V_91 . V_92 . V_101 , V_82 -> V_91 . V_92 . V_102 ) ) {
case V_103 :
V_82 -> V_91 . V_92 . V_101 = 640 ;
V_82 -> V_91 . V_92 . V_102 = 480 ;
break;
case V_104 :
V_82 -> V_91 . V_92 . V_101 = 352 ;
V_82 -> V_91 . V_92 . V_102 = 288 ;
break;
case V_105 :
V_82 -> V_91 . V_92 . V_101 = 320 ;
V_82 -> V_91 . V_92 . V_102 = 240 ;
break;
case V_106 :
V_82 -> V_91 . V_92 . V_101 = 288 ;
V_82 -> V_91 . V_92 . V_102 = 216 ;
break;
case V_107 :
V_82 -> V_91 . V_92 . V_101 = 256 ;
V_82 -> V_91 . V_92 . V_102 = 192 ;
break;
case V_108 :
V_82 -> V_91 . V_92 . V_101 = 224 ;
V_82 -> V_91 . V_92 . V_102 = 168 ;
break;
case V_109 :
V_82 -> V_91 . V_92 . V_101 = 192 ;
V_82 -> V_91 . V_92 . V_102 = 144 ;
break;
case V_110 :
default:
V_82 -> V_91 . V_92 . V_101 = 176 ;
V_82 -> V_91 . V_92 . V_102 = 144 ;
break;
}
return 0 ;
}
static int F_39 ( struct V_1 * V_1 , void * V_111 ,
struct V_90 * V_82 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_111 ;
int V_112 , V_35 ;
V_112 = F_40 ( & V_3 -> V_15 , V_5 -> V_15 ) ;
if ( V_112 )
return V_112 ;
V_112 = F_37 ( V_1 , V_111 , V_82 ) ;
if( V_112 != 0 )
return V_112 ;
V_112 = F_41 ( & V_3 -> V_15 , & V_5 -> V_15 , V_20 ) ;
if( V_112 != 0 ) {
return V_112 ;
}
V_3 -> V_87 = V_82 -> V_91 . V_92 . V_87 ;
V_3 -> V_54 . V_113 . V_114 = 0 ;
F_42 ( L_17 ,
V_82 -> V_91 . V_92 . V_101 , V_82 -> V_91 . V_92 . V_102 ) ;
if ( V_82 -> V_91 . V_92 . V_101 != V_3 -> V_101 ||
V_82 -> V_91 . V_92 . V_102 != V_3 -> V_102 ) {
V_3 -> V_101 = V_82 -> V_91 . V_92 . V_101 ;
V_3 -> V_102 = V_82 -> V_91 . V_92 . V_102 ;
V_3 -> V_54 . V_115 . V_101 = V_82 -> V_91 . V_92 . V_101 ;
V_3 -> V_54 . V_115 . V_102 = V_82 -> V_91 . V_92 . V_102 ;
F_43 ( V_3 ) ;
}
for ( V_35 = 0 ; V_35 < V_3 -> V_116 ; ++ V_35 ) {
if ( V_3 -> V_36 [ V_35 ] . V_37 == V_117 )
if ( ( V_112 = F_23 ( V_3 , V_35 ) ) < 0 )
return V_112 ;
V_3 -> V_36 [ V_35 ] . V_37 = V_118 ;
}
return 0 ;
}
static int F_44 ( struct V_1 * V_1 , void * V_5 ,
struct V_90 * V_82 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
V_82 -> V_91 . V_92 . V_101 = V_3 -> V_101 ;
V_82 -> V_91 . V_92 . V_102 = V_3 -> V_102 ;
V_82 -> V_91 . V_92 . V_87 = V_3 -> V_87 ;
V_82 -> V_91 . V_92 . V_93 = V_94 ;
V_82 -> V_91 . V_92 . V_95 = 0 ;
V_82 -> V_91 . V_92 . V_96 = V_3 -> V_97 ;
V_82 -> V_91 . V_92 . V_98 = V_99 ;
V_82 -> V_91 . V_92 . V_100 = 0 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_1 , void * V_5 , struct V_119 * V_120 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( V_120 -> type != V_83 )
return - V_27 ;
V_120 -> V_121 . V_122 = 0 ;
V_120 -> V_121 . V_123 = 0 ;
V_120 -> V_121 . V_101 = V_3 -> V_101 ;
V_120 -> V_121 . V_102 = V_3 -> V_102 ;
V_120 -> V_124 . V_122 = 0 ;
V_120 -> V_124 . V_123 = 0 ;
V_120 -> V_124 . V_101 = V_3 -> V_101 ;
V_120 -> V_124 . V_102 = V_3 -> V_102 ;
V_120 -> V_125 . V_126 = 1 ;
V_120 -> V_125 . V_127 = 1 ;
return 0 ;
}
static int F_46 ( struct V_1 * V_1 , void * V_5 , struct V_128 * V_120 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_77 ;
for( V_77 = 0 ; V_77 < V_129 ; ++ V_77 ) {
if( V_120 -> V_130 == V_131 [ V_77 ] . V_130 ) {
memcpy ( V_120 , V_131 + V_77 , sizeof( * V_120 ) ) ;
break;
}
}
if( V_77 == V_129 )
return - V_27 ;
switch( V_120 -> V_130 ) {
case V_132 :
if ( V_3 -> V_54 . V_55 . V_58 == V_59 )
V_120 -> V_133 = 1 ;
break;
case V_134 :
if( V_3 -> V_54 . V_55 . V_58 == V_59 )
V_120 -> V_84 |= V_135 ;
break;
case V_136 :
if( V_3 -> V_54 . V_55 . V_58 == V_59 &&
V_3 -> V_54 . V_61 . V_62 == V_67 ) {
for( V_77 = 0 ; V_77 < V_120 -> V_137 ; ++ V_77 ) {
if( V_138 [ V_77 ] . V_139 ==
V_140 ) {
V_120 -> V_137 = V_77 ;
V_120 -> V_141 = V_77 ;
}
}
}
break;
case V_142 :
if( V_3 -> V_54 . V_55 . V_58 != V_59 )
V_120 -> V_84 |= V_135 ;
break;
case V_143 :
if( V_3 -> V_54 . V_55 . V_56 != 0x151 )
V_120 -> V_84 |= V_135 ;
break;
default:
break;
}
return 0 ;
}
static int F_47 ( struct V_1 * V_1 , void * V_5 , struct V_144 * V_145 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
switch( V_145 -> V_130 ) {
case V_142 :
if ( V_145 -> V_78 >= V_146 )
return - V_27 ;
strcpy ( V_145 -> V_79 , V_147 [ V_145 -> V_78 ] . V_79 ) ;
break;
case V_136 :
{
int V_137 = V_148 - 1 ;
if( V_3 -> V_54 . V_55 . V_58 == V_59 &&
V_3 -> V_54 . V_61 . V_62 == V_67 ) {
int V_77 ;
for( V_77 = 0 ; V_77 < V_137 ; ++ V_77 ) {
if( V_138 [ V_77 ] . V_139 ==
V_140 )
V_137 = V_77 ;
}
}
if ( V_145 -> V_78 > V_137 )
return - V_27 ;
strcpy ( V_145 -> V_79 , V_138 [ V_145 -> V_78 ] . V_79 ) ;
break;
}
case V_143 :
if ( V_145 -> V_78 >= V_149 )
return - V_27 ;
strcpy ( V_145 -> V_79 , V_150 [ V_145 -> V_78 ] . V_79 ) ;
break;
default:
return - V_27 ;
}
return 0 ;
}
static int F_48 ( struct V_1 * V_1 , void * V_5 , struct V_151 * V_120 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
switch( V_120 -> V_130 ) {
case V_132 :
F_49 ( V_3 , V_152 ,
V_153 , 0 ) ;
V_120 -> V_139 = V_3 -> V_54 . V_154 . V_155 ;
break;
case V_156 :
F_49 ( V_3 , V_157 ,
V_153 , 0 ) ;
V_120 -> V_139 = V_3 -> V_54 . V_154 . V_158 ;
break;
case V_159 :
F_49 ( V_3 , V_160 ,
V_153 , 0 ) ;
V_120 -> V_139 = V_3 -> V_54 . V_154 . V_161 ;
break;
case V_162 :
F_49 ( V_3 , V_163 ,
V_153 , 0 ) ;
V_120 -> V_139 = ( V_3 -> V_54 . V_164 . V_165 &
V_166 ) != 0 ;
break;
case V_134 :
F_49 ( V_3 , V_163 ,
V_153 , 0 ) ;
V_120 -> V_139 = ( V_3 -> V_54 . V_164 . V_165 &
V_167 ) != 0 ;
break;
case V_168 :
V_120 -> V_139 = V_3 -> V_54 . V_169 . V_170 ;
break;
case V_50 :
F_49 ( V_3 , V_171 ,
V_153 , 0 ) ;
V_120 -> V_139 = V_3 -> V_54 . V_164 . V_172 ;
break;
case V_142 :
{
int V_77 , V_173 ;
F_49 ( V_3 , V_174 ,
V_153 , 0 ) ;
if( V_3 -> V_54 . V_175 . V_176 &
V_177 ) {
V_173 = V_178 ;
} else {
if( V_3 -> V_54 . V_175 . V_176 &
V_179 ) {
V_173 = V_180 ;
} else {
V_173 = V_181 ;
}
}
for( V_77 = 0 ; V_77 < V_146 ; V_77 ++ ) {
if( V_147 [ V_77 ] . V_139 == V_173 ) {
V_120 -> V_139 = V_77 ;
break;
}
}
if( V_77 == V_146 )
return - V_27 ;
break;
}
case V_136 :
{
int V_137 = V_148 - 1 ;
int V_77 ;
for( V_77 = 0 ; V_77 <= V_137 ; V_77 ++ ) {
if( V_3 -> V_54 . V_164 . V_182 ==
V_138 [ V_77 ] . V_139 )
break;
}
if( V_77 > V_137 )
return - V_27 ;
V_120 -> V_139 = V_77 ;
break;
}
case V_183 :
V_120 -> V_139 = V_3 -> V_54 . V_184 . V_185 ;
break;
case V_143 :
{
int V_77 ;
F_49 ( V_3 , V_171 ,
V_153 , 0 ) ;
for( V_77 = 0 ; V_77 < V_149 ; V_77 ++ ) {
if( ( V_3 -> V_54 . V_164 . V_172 & V_186 ) ==
V_150 [ V_77 ] . V_139 ) {
break;
}
}
if( V_77 == V_149 )
return - V_27 ;
V_120 -> V_139 = V_77 ;
break;
}
case V_187 :
return - V_27 ;
default:
return - V_27 ;
}
F_42 ( L_18 , V_120 -> V_130 , V_120 -> V_139 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_1 , void * V_5 , struct V_151 * V_120 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_77 ;
int V_188 = 0 ;
F_42 ( L_19 , V_120 -> V_130 , V_120 -> V_139 ) ;
for( V_77 = 0 ; V_77 < V_129 ; V_77 ++ ) {
if( V_120 -> V_130 == V_131 [ V_77 ] . V_130 ) {
if( V_120 -> V_139 < V_131 [ V_77 ] . V_133 ||
V_120 -> V_139 > V_131 [ V_77 ] . V_137 ) {
return - V_27 ;
}
break;
}
}
if( V_77 == V_129 )
return - V_27 ;
switch( V_120 -> V_130 ) {
case V_132 :
F_51 ( V_3 , V_120 -> V_139 ) ;
break;
case V_156 :
F_52 ( V_3 , V_120 -> V_139 ) ;
break;
case V_159 :
F_53 ( V_3 , V_120 -> V_139 ) ;
break;
case V_162 :
F_54 ( V_3 , V_120 -> V_139 ) ;
break;
case V_134 :
F_55 ( V_3 , V_120 -> V_139 ) ;
break;
case V_168 :
V_188 = F_56 ( V_3 , V_120 -> V_139 ) ;
break;
case V_50 :
V_188 = F_29 ( V_3 , V_120 -> V_139 ) ;
break;
case V_142 :
V_188 = F_57 ( V_3 ,
V_147 [ V_120 -> V_139 ] . V_139 ) ;
break;
case V_136 :
V_188 = F_58 ( V_3 , V_138 [ V_120 -> V_139 ] . V_139 ) ;
break;
case V_183 :
V_188 = F_59 ( V_3 , V_120 -> V_139 ) ;
break;
case V_143 :
V_188 = F_29 ( V_3 , V_150 [ V_120 -> V_139 ] . V_139 ) ;
break;
case V_187 :
F_60 ( V_3 ) ;
F_5 ( V_3 ) ;
F_61 ( V_3 ) ;
break;
default:
V_188 = - V_27 ;
}
return V_188 ;
}
static int F_62 ( struct V_1 * V_1 , void * V_5 , struct V_189 * V_190 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
memset ( V_190 , 0 , sizeof( * V_190 ) ) ;
V_190 -> V_191 = 80 ;
V_190 -> V_192 = V_193 | V_194 ;
if( ! V_3 -> V_54 . V_113 . V_114 ) {
V_190 -> V_192 |= V_195 ;
}
V_190 -> V_196 = V_3 -> V_196 ;
V_190 -> V_11 = V_3 -> V_11 ;
if( V_3 -> V_11 > 0 ) {
memcpy ( V_190 -> V_197 , V_3 -> V_197 , V_3 -> V_11 ) ;
V_190 -> V_192 |= V_198 ;
}
V_190 -> V_12 = V_3 -> V_12 ;
if( V_3 -> V_12 > 0 ) {
memcpy ( V_190 -> V_199 , V_3 -> V_199 , V_3 -> V_12 ) ;
V_190 -> V_192 |= V_200 ;
}
F_42 ( L_20 ,
V_190 -> V_11 , V_190 -> V_12 ) ;
return 0 ;
}
static int F_63 ( struct V_1 * V_1 , void * V_5 , struct V_189 * V_190 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_42 ( L_21 ,
V_190 -> V_11 , V_190 -> V_12 ) ;
V_3 -> V_54 . V_113 . V_114 =
! ( V_190 -> V_192 & V_195 ) ;
if( V_190 -> V_11 != 0 ) {
if( V_190 -> V_11 > 0 &&
V_190 -> V_11 <= sizeof( V_3 -> V_197 ) &&
V_190 -> V_196 >= 0 && V_190 -> V_196 <= 15 ) {
V_3 -> V_196 = V_190 -> V_196 ;
V_3 -> V_11 = V_190 -> V_11 ;
memcpy ( V_3 -> V_197 , V_190 -> V_197 , V_190 -> V_11 ) ;
} else {
LOG ( L_22 ,
V_190 -> V_196 , V_190 -> V_11 ) ;
return - V_27 ;
}
} else {
V_3 -> V_11 = 0 ;
}
if( V_190 -> V_12 != 0 ) {
if( V_190 -> V_12 > 0 &&
V_190 -> V_12 <= sizeof( V_3 -> V_199 ) ) {
V_3 -> V_12 = V_190 -> V_12 ;
memcpy ( V_3 -> V_199 , V_190 -> V_199 , V_190 -> V_12 ) ;
} else {
LOG ( L_23 , V_190 -> V_12 ) ;
return - V_27 ;
}
}
return 0 ;
}
static int F_64 ( struct V_1 * V_1 , void * V_5 , struct V_201 * V_202 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if( V_202 -> type != V_83 ||
V_202 -> V_203 != V_204 )
return - V_27 ;
F_42 ( L_24 , V_202 -> V_22 , V_3 -> V_116 ) ;
V_202 -> V_22 = V_3 -> V_116 ;
memset ( & V_202 -> V_205 , 0 , sizeof( V_202 -> V_205 ) ) ;
return 0 ;
}
static int F_65 ( struct V_1 * V_1 , void * V_5 , struct V_206 * V_21 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if( V_21 -> type != V_83 ||
V_21 -> V_78 > V_3 -> V_116 )
return - V_27 ;
V_21 -> V_145 . V_207 = V_3 -> V_36 [ V_21 -> V_78 ] . V_208 - V_3 -> V_209 ;
V_21 -> V_40 = V_3 -> V_97 ;
V_21 -> V_203 = V_204 ;
if( V_3 -> V_17 )
V_21 -> V_84 = V_210 ;
else
V_21 -> V_84 = 0 ;
switch ( V_3 -> V_36 [ V_21 -> V_78 ] . V_37 ) {
case V_118 :
case V_211 :
case V_117 :
V_21 -> V_212 = 0 ;
V_21 -> V_84 = V_213 ;
break;
case V_38 :
V_21 -> V_212 = V_3 -> V_36 [ V_21 -> V_78 ] . V_40 ;
V_21 -> V_214 = V_3 -> V_36 [ V_21 -> V_78 ] . V_214 ;
V_21 -> V_215 = V_3 -> V_36 [ V_21 -> V_78 ] . V_216 ;
V_21 -> V_84 = V_217 ;
break;
}
F_42 ( L_25 ,
V_21 -> V_78 , V_21 -> V_145 . V_207 , V_21 -> V_84 , V_21 -> V_215 ,
V_21 -> V_212 ) ;
return 0 ;
}
static int F_66 ( struct V_1 * V_1 , void * V_5 , struct V_206 * V_21 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if( V_21 -> type != V_83 ||
V_21 -> V_203 != V_204 ||
V_21 -> V_78 > V_3 -> V_116 )
return - V_27 ;
F_42 ( L_26 , V_21 -> V_78 ) ;
if( V_3 -> V_36 [ V_21 -> V_78 ] . V_37 == V_38 )
V_3 -> V_36 [ V_21 -> V_78 ] . V_37 = V_118 ;
return 0 ;
}
static int F_67 ( struct V_2 * V_3 )
{
int V_77 ;
int V_218 = - 1 ;
for ( V_77 = 0 ; V_77 < V_3 -> V_116 ; V_77 ++ ) {
if( V_3 -> V_36 [ V_77 ] . V_37 == V_38 ) {
if( V_218 < 0 ) {
V_218 = V_77 ;
} else {
struct V_219 * V_220 , * V_221 ;
V_220 = & V_3 -> V_36 [ V_77 ] . V_214 ;
V_221 = & V_3 -> V_36 [ V_218 ] . V_214 ;
if( V_220 -> V_222 < V_221 -> V_222 ||
( V_220 -> V_222 == V_221 -> V_222 &&
V_220 -> V_223 < V_221 -> V_223 ) )
V_218 = V_77 ;
}
}
}
return V_218 ;
}
static int F_68 ( struct V_1 * V_1 , void * V_5 , struct V_206 * V_21 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_35 ;
if( V_21 -> type != V_83 ||
V_21 -> V_203 != V_204 )
return - V_27 ;
V_35 = F_67 ( V_3 ) ;
if( V_35 < 0 && V_1 -> V_25 & V_26 )
return - V_224 ;
if( V_35 < 0 ) {
struct V_34 * V_225 = V_3 -> V_226 ;
F_24 ( & V_3 -> V_41 ) ;
F_25 ( V_3 -> V_42 ,
! V_3 -> V_7 ||
( V_225 = V_3 -> V_226 ) -> V_37 == V_38 ) ;
F_26 ( & V_3 -> V_41 ) ;
if ( F_27 ( V_43 ) )
return - V_44 ;
if( ! V_3 -> V_7 )
return - V_45 ;
V_35 = V_225 -> V_227 ;
}
V_21 -> V_78 = V_35 ;
V_21 -> V_212 = V_3 -> V_36 [ V_21 -> V_78 ] . V_40 ;
V_21 -> V_84 = V_210 | V_217 ;
V_21 -> V_93 = V_94 ;
V_21 -> V_214 = V_3 -> V_36 [ V_21 -> V_78 ] . V_214 ;
V_21 -> V_215 = V_3 -> V_36 [ V_21 -> V_78 ] . V_216 ;
V_21 -> V_145 . V_207 = V_3 -> V_36 [ V_21 -> V_78 ] . V_208 - V_3 -> V_209 ;
V_21 -> V_40 = V_3 -> V_97 ;
V_21 -> V_228 = 0 ;
V_21 -> V_205 = 0 ;
memset ( & V_21 -> V_229 , 0 , sizeof( V_21 -> V_229 ) ) ;
F_42 ( L_27 , V_21 -> V_78 ,
V_3 -> V_36 [ V_21 -> V_78 ] . V_37 , V_21 -> V_215 , V_21 -> V_212 ) ;
return 0 ;
}
static int F_69 ( struct V_1 * V_1 , void * V_111 , enum V_230 * V_231 )
{
struct V_4 * V_5 = V_111 ;
* V_231 = V_5 -> V_15 ;
return 0 ;
}
static int F_70 ( struct V_1 * V_1 , void * V_111 , enum V_230 V_15 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_4 * V_5 = V_111 ;
if ( V_3 -> V_39 && V_15 != V_5 -> V_15 &&
V_5 -> V_15 == V_20 )
return - V_28 ;
if ( V_15 == V_20 && V_15 != V_5 -> V_15 &&
F_71 ( & V_3 -> V_15 ) == V_20 )
return - V_28 ;
return F_41 ( & V_3 -> V_15 , & V_5 -> V_15 , V_15 ) ;
}
static int F_72 ( struct V_1 * V_1 , void * V_5 , enum V_232 type )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_42 ( L_28 , V_3 -> V_39 ) ;
if ( ! V_3 -> V_17 || type != V_83 )
return - V_27 ;
if ( ! V_3 -> V_39 )
return F_73 ( V_3 ,
V_3 -> V_54 . V_184 . V_185 ) ;
return - V_27 ;
}
static int F_74 ( struct V_1 * V_1 , void * V_5 , enum V_232 type )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_42 ( L_29 , V_3 -> V_39 ) ;
if ( ! V_3 -> V_17 || type != V_83 )
return - V_27 ;
if ( V_3 -> V_39 )
return F_12 ( V_3 ) ;
return - V_27 ;
}
static int F_75 ( struct V_1 * V_1 , struct V_233 * V_234 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_188 ;
struct V_4 * V_5 = V_1 -> V_14 ;
if( V_5 -> V_15 != V_20 ) {
return - V_28 ;
}
V_188 = F_76 ( V_3 , V_234 ) ;
if( ! V_188 )
V_5 -> V_17 = 1 ;
return V_188 ;
}
static void F_77 ( struct V_2 * V_3 )
{
V_3 -> V_101 = V_3 -> V_54 . V_115 . V_101 ;
V_3 -> V_102 = V_3 -> V_54 . V_115 . V_102 ;
V_3 -> V_97 = V_235 ;
V_3 -> V_116 = V_236 ;
V_3 -> V_54 . V_175 . V_237 = V_238 ;
V_3 -> V_54 . V_175 . V_239 = V_240 ;
V_3 -> V_54 . V_184 . V_185 = V_241 ;
V_3 -> V_87 = V_89 ;
F_78 ( & V_3 -> V_15 ) ;
}
int F_79 ( struct V_2 * V_3 )
{
V_3 -> V_242 = F_80 () ;
if( ! V_3 -> V_242 )
return - V_9 ;
memcpy ( V_3 -> V_242 , & V_243 , sizeof( V_243 ) ) ;
F_81 ( V_3 -> V_242 , V_3 ) ;
V_3 -> V_242 -> V_244 = & V_3 -> V_41 ;
F_77 ( V_3 ) ;
if ( F_82 ( V_3 -> V_242 , V_245 , V_246 ) < 0 ) {
F_3 ( L_30 ) ;
F_83 ( V_3 -> V_242 ) ;
return - V_6 ;
}
return 0 ;
}
void F_84 ( struct V_2 * V_3 )
{
if ( ! V_3 -> V_8 ) {
F_18 ( V_3 -> V_242 ) ;
} else {
LOG ( L_31
L_32 ,
F_85 ( V_3 -> V_242 ) ) ;
}
}
static void T_6 F_86 ( void )
{
if( V_235 < V_247 ) {
V_235 = V_247 ;
LOG ( L_33 , V_235 ) ;
} else if( V_235 > 1024 * 1024 ) {
V_235 = 1024 * 1024 ;
LOG ( L_34 ,
V_235 ) ;
} else {
V_235 += V_247 - 1 ;
V_235 &= ~ ( V_247 - 1 ) ;
}
if( V_236 < 1 ) {
V_236 = 1 ;
LOG ( L_35 , V_236 ) ;
} else if( V_236 > V_248 ) {
V_236 = V_248 ;
LOG ( L_36 , V_236 ) ;
}
if( V_241 < V_249 || V_241 > V_250 ) {
V_241 = V_251 ;
LOG ( L_37 , V_241 ) ;
}
if ( V_238 != V_178 && V_238 != V_252 ) {
V_238 = V_178 ;
LOG ( L_38 ,
V_238 ) ;
}
if ( V_240 != V_180 && V_240 != V_181 ) {
V_240 = V_181 ;
LOG ( L_38 ,
V_240 ) ;
}
if( V_246 < - 1 || V_246 > 64 ) {
V_246 = - 1 ;
LOG ( L_39 ) ;
}
F_42 ( L_40 ,
V_236 , V_235 , V_241 ) ;
}
static int T_6 F_87 ( void )
{
LOG ( L_41 ,
V_253 , V_69 , V_70 , V_71 ) ;
F_86 () ;
F_88 () ;
return 0 ;
}
static void T_7 F_89 ( void )
{
F_90 () ;
F_91 ( 2 * V_254 ) ;
}
