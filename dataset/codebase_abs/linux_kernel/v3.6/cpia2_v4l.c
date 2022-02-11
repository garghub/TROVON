static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_4 = F_3 ( V_1 ) ;
if ( V_4 )
return V_4 ;
if ( F_4 ( V_1 ) ) {
if ( F_5 ( V_3 ) ) {
F_6 ( V_1 ) ;
return - V_5 ;
}
if ( F_7 ( V_3 ) < 0 ) {
F_6 ( V_1 ) ;
return - V_6 ;
}
V_3 -> V_7 = 0 ;
V_3 -> V_8 = 0 ;
}
F_8 ( V_3 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_1 )
{
struct V_9 * V_10 = F_10 ( V_1 ) ;
struct V_2 * V_3 = F_11 ( V_10 ) ;
if ( F_12 ( & V_3 -> V_11 ) && F_4 ( V_1 ) ) {
F_13 ( V_3 ) ;
F_14 ( V_3 ) ;
F_15 ( V_3 ) ;
F_16 ( V_3 ) ;
}
if ( V_3 -> V_12 == V_1 -> V_13 ) {
V_3 -> V_12 = NULL ;
V_3 -> V_14 = 0 ;
}
return F_6 ( V_1 ) ;
}
static T_1 F_17 ( struct V_1 * V_1 , char T_2 * V_15 , T_3 V_16 ,
T_4 * V_17 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_18 = V_1 -> V_19 & V_20 ;
if( ! V_3 )
return - V_21 ;
return F_18 ( V_3 , V_15 , V_16 , V_18 ) ;
}
static unsigned int F_19 ( struct V_1 * V_22 , struct V_23 * V_24 )
{
struct V_2 * V_3 = F_2 ( V_22 ) ;
return F_20 ( V_3 , V_22 , V_24 ) ;
}
static int F_21 ( struct V_2 * V_3 , int V_25 )
{
struct V_26 * V_27 = & V_3 -> V_28 [ V_25 ] ;
while ( 1 ) {
if ( V_27 -> V_29 == V_30 )
return 0 ;
if ( ! V_3 -> V_31 ) {
V_27 -> V_29 = V_30 ;
V_27 -> V_32 = 0 ;
return 0 ;
}
F_22 ( & V_3 -> V_33 ) ;
F_23 ( V_3 -> V_34 ,
! V_3 -> V_31 ||
V_27 -> V_29 == V_30 ) ;
F_24 ( & V_3 -> V_33 ) ;
if ( F_25 ( V_35 ) )
return - V_36 ;
if ( ! F_12 ( & V_3 -> V_11 ) )
return - V_37 ;
}
}
static int F_26 ( struct V_1 * V_1 , void * V_38 , struct V_39 * V_40 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
strcpy ( V_40 -> V_41 , L_1 ) ;
if ( V_3 -> V_42 . V_43 . V_44 == 0x151 )
strcpy ( V_40 -> V_45 , L_2 ) ;
else
strcpy ( V_40 -> V_45 , L_3 ) ;
switch ( V_3 -> V_42 . V_43 . V_46 ) {
case V_47 :
strcat ( V_40 -> V_45 , L_4 ) ;
break;
case V_48 :
strcat ( V_40 -> V_45 , L_5 ) ;
break;
default:
strcat ( V_40 -> V_45 , L_6 ) ;
break;
}
switch ( V_3 -> V_42 . V_49 . V_50 ) {
case V_51 :
strcat ( V_40 -> V_45 , L_7 ) ;
break;
case V_52 :
strcat ( V_40 -> V_45 , L_8 ) ;
break;
case V_53 :
strcat ( V_40 -> V_45 , L_9 ) ;
break;
case V_54 :
strcat ( V_40 -> V_45 , L_10 ) ;
break;
case V_55 :
strcat ( V_40 -> V_45 , L_11 ) ;
break;
default:
strcat ( V_40 -> V_45 , L_12 ) ;
break;
}
if ( F_27 ( V_3 -> V_10 , V_40 -> V_56 , sizeof( V_40 -> V_56 ) ) < 0 )
memset ( V_40 -> V_56 , 0 , sizeof( V_40 -> V_56 ) ) ;
V_40 -> V_57 = V_58 |
V_59 |
V_60 ;
V_40 -> V_61 = V_40 -> V_57 |
V_62 ;
return 0 ;
}
static int F_28 ( struct V_1 * V_1 , void * V_38 , struct V_63 * V_64 )
{
if ( V_64 -> V_65 )
return - V_21 ;
strcpy ( V_64 -> V_66 , L_13 ) ;
V_64 -> type = V_67 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 , void * V_38 , unsigned int * V_64 )
{
* V_64 = 0 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 , void * V_38 , unsigned int V_64 )
{
return V_64 ? - V_21 : 0 ;
}
static int F_31 ( struct V_1 * V_1 , void * V_38 ,
struct V_68 * V_69 )
{
int V_65 = V_69 -> V_65 ;
if ( V_65 < 0 || V_65 > 1 )
return - V_21 ;
memset ( V_69 , 0 , sizeof( * V_69 ) ) ;
V_69 -> V_65 = V_65 ;
V_69 -> type = V_70 ;
V_69 -> V_71 = V_72 ;
switch( V_65 ) {
case 0 :
strcpy ( V_69 -> V_73 , L_14 ) ;
V_69 -> V_74 = V_75 ;
break;
case 1 :
strcpy ( V_69 -> V_73 , L_15 ) ;
V_69 -> V_74 = V_76 ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_32 ( struct V_1 * V_1 , void * V_38 ,
struct V_77 * V_69 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( V_69 -> V_78 . V_79 . V_74 != V_75 &&
V_69 -> V_78 . V_79 . V_74 != V_76 )
return - V_21 ;
V_69 -> V_78 . V_79 . V_80 = V_81 ;
V_69 -> V_78 . V_79 . V_82 = 0 ;
V_69 -> V_78 . V_79 . V_83 = V_3 -> V_84 ;
V_69 -> V_78 . V_79 . V_85 = V_86 ;
V_69 -> V_78 . V_79 . V_87 = 0 ;
switch ( F_33 ( V_69 -> V_78 . V_79 . V_88 , V_69 -> V_78 . V_79 . V_89 ) ) {
case V_90 :
V_69 -> V_78 . V_79 . V_88 = 640 ;
V_69 -> V_78 . V_79 . V_89 = 480 ;
break;
case V_91 :
V_69 -> V_78 . V_79 . V_88 = 352 ;
V_69 -> V_78 . V_79 . V_89 = 288 ;
break;
case V_92 :
V_69 -> V_78 . V_79 . V_88 = 320 ;
V_69 -> V_78 . V_79 . V_89 = 240 ;
break;
case V_93 :
V_69 -> V_78 . V_79 . V_88 = 288 ;
V_69 -> V_78 . V_79 . V_89 = 216 ;
break;
case V_94 :
V_69 -> V_78 . V_79 . V_88 = 256 ;
V_69 -> V_78 . V_79 . V_89 = 192 ;
break;
case V_95 :
V_69 -> V_78 . V_79 . V_88 = 224 ;
V_69 -> V_78 . V_79 . V_89 = 168 ;
break;
case V_96 :
V_69 -> V_78 . V_79 . V_88 = 192 ;
V_69 -> V_78 . V_79 . V_89 = 144 ;
break;
case V_97 :
default:
V_69 -> V_78 . V_79 . V_88 = 176 ;
V_69 -> V_78 . V_79 . V_89 = 144 ;
break;
}
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , void * V_98 ,
struct V_77 * V_69 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_99 , V_27 ;
V_99 = F_32 ( V_1 , V_98 , V_69 ) ;
if( V_99 != 0 )
return V_99 ;
V_3 -> V_74 = V_69 -> V_78 . V_79 . V_74 ;
V_3 -> V_42 . V_100 . V_101 = 0 ;
F_35 ( L_16 ,
V_69 -> V_78 . V_79 . V_88 , V_69 -> V_78 . V_79 . V_89 ) ;
if ( V_69 -> V_78 . V_79 . V_88 != V_3 -> V_88 ||
V_69 -> V_78 . V_79 . V_89 != V_3 -> V_89 ) {
V_3 -> V_88 = V_69 -> V_78 . V_79 . V_88 ;
V_3 -> V_89 = V_69 -> V_78 . V_79 . V_89 ;
V_3 -> V_42 . V_102 . V_88 = V_69 -> V_78 . V_79 . V_88 ;
V_3 -> V_42 . V_102 . V_89 = V_69 -> V_78 . V_79 . V_89 ;
F_36 ( V_3 ) ;
}
for ( V_27 = 0 ; V_27 < V_3 -> V_103 ; ++ V_27 ) {
if ( V_3 -> V_28 [ V_27 ] . V_29 == V_104 )
if ( ( V_99 = F_21 ( V_3 , V_27 ) ) < 0 )
return V_99 ;
V_3 -> V_28 [ V_27 ] . V_29 = V_105 ;
}
return 0 ;
}
static int F_37 ( struct V_1 * V_1 , void * V_38 ,
struct V_77 * V_69 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
V_69 -> V_78 . V_79 . V_88 = V_3 -> V_88 ;
V_69 -> V_78 . V_79 . V_89 = V_3 -> V_89 ;
V_69 -> V_78 . V_79 . V_74 = V_3 -> V_74 ;
V_69 -> V_78 . V_79 . V_80 = V_81 ;
V_69 -> V_78 . V_79 . V_82 = 0 ;
V_69 -> V_78 . V_79 . V_83 = V_3 -> V_84 ;
V_69 -> V_78 . V_79 . V_85 = V_86 ;
V_69 -> V_78 . V_79 . V_87 = 0 ;
return 0 ;
}
static int F_38 ( struct V_1 * V_1 , void * V_38 , struct V_106 * V_107 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( V_107 -> type != V_70 )
return - V_21 ;
V_107 -> V_108 . V_109 = 0 ;
V_107 -> V_108 . V_110 = 0 ;
V_107 -> V_108 . V_88 = V_3 -> V_88 ;
V_107 -> V_108 . V_89 = V_3 -> V_89 ;
V_107 -> V_111 . V_109 = 0 ;
V_107 -> V_111 . V_110 = 0 ;
V_107 -> V_111 . V_88 = V_3 -> V_88 ;
V_107 -> V_111 . V_89 = V_3 -> V_89 ;
V_107 -> V_112 . V_113 = 1 ;
V_107 -> V_112 . V_114 = 1 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_1 , void * V_38 , struct V_115 * V_116 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_117 * V_118 = & V_116 -> V_119 . V_120 ;
int V_64 ;
if ( V_116 -> type != V_70 )
return - V_21 ;
V_118 -> V_121 = V_122 ;
V_118 -> V_123 = V_3 -> V_103 ;
for ( V_64 = 0 ; V_64 < F_40 ( V_124 ) ; V_64 ++ )
if ( V_3 -> V_42 . V_125 . V_126 == V_124 [ V_64 ] . V_127 ) {
V_118 -> V_128 = V_124 [ V_64 ] . V_129 ;
break;
}
return 0 ;
}
static int F_41 ( struct V_1 * V_1 , void * V_38 , struct V_115 * V_116 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_117 * V_118 = & V_116 -> V_119 . V_120 ;
struct V_130 V_131 = V_118 -> V_128 ;
int V_132 = F_40 ( V_124 ) - 1 ;
int V_133 ;
int V_64 ;
V_133 = F_39 ( V_1 , V_38 , V_116 ) ;
if ( V_133 || ! V_131 . V_114 || ! V_131 . V_113 )
return V_133 ;
if ( V_3 -> V_42 . V_43 . V_46 == V_47 &&
V_3 -> V_42 . V_49 . V_50 == V_55 )
V_132 -= 2 ;
for ( V_64 = 0 ; V_64 <= V_132 ; V_64 ++ ) {
struct V_130 V_134 = V_131 ;
struct V_130 V_135 = V_124 [ V_64 ] . V_129 ;
V_134 . V_113 *= V_135 . V_114 ;
V_135 . V_113 *= V_134 . V_114 ;
if ( V_134 . V_113 >= V_135 . V_113 )
break;
}
if ( V_64 > V_132 )
V_64 = V_132 ;
V_118 -> V_128 = V_124 [ V_64 ] . V_129 ;
return F_42 ( V_3 , V_124 [ V_64 ] . V_127 ) ;
}
static int F_43 ( struct V_1 * V_1 , void * V_38 ,
struct V_136 * V_137 )
{
if ( V_137 -> V_138 != V_75 &&
V_137 -> V_138 != V_76 )
return - V_21 ;
if ( V_137 -> V_65 >= F_40 ( V_139 ) )
return - V_21 ;
V_137 -> type = V_140 ;
V_137 -> V_141 . V_88 = V_139 [ V_137 -> V_65 ] . V_88 ;
V_137 -> V_141 . V_89 = V_139 [ V_137 -> V_65 ] . V_89 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_1 , void * V_38 ,
struct V_142 * V_143 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_132 = F_40 ( V_124 ) - 1 ;
int V_64 ;
if ( V_143 -> V_138 != V_75 &&
V_143 -> V_138 != V_76 )
return - V_21 ;
if ( V_3 -> V_42 . V_43 . V_46 == V_47 &&
V_3 -> V_42 . V_49 . V_50 == V_55 )
V_132 -= 2 ;
if ( V_143 -> V_65 > V_132 )
return - V_21 ;
for ( V_64 = 0 ; V_64 < F_40 ( V_139 ) ; V_64 ++ )
if ( V_143 -> V_88 == V_139 [ V_64 ] . V_88 &&
V_143 -> V_89 == V_139 [ V_64 ] . V_89 )
break;
if ( V_64 == F_40 ( V_139 ) )
return - V_21 ;
V_143 -> type = V_144 ;
V_143 -> V_141 = V_124 [ V_143 -> V_65 ] . V_129 ;
return 0 ;
}
static int F_45 ( struct V_145 * V_146 )
{
struct V_2 * V_3 =
F_46 ( V_146 -> V_147 , struct V_2 , V_148 ) ;
static const int V_149 [] = {
V_150 ,
V_151 ,
V_152 ,
} ;
F_35 ( L_17 , V_146 -> V_153 , V_146 -> V_154 ) ;
switch ( V_146 -> V_153 ) {
case V_155 :
F_47 ( V_3 , V_146 -> V_154 ) ;
break;
case V_156 :
F_48 ( V_3 , V_146 -> V_154 ) ;
break;
case V_157 :
F_49 ( V_3 , V_146 -> V_154 ) ;
break;
case V_158 :
F_50 ( V_3 , V_146 -> V_154 ) ;
break;
case V_159 :
F_51 ( V_3 , V_146 -> V_154 ) ;
break;
case V_160 :
return F_52 ( V_3 , V_149 [ V_146 -> V_154 ] ) ;
case V_161 :
return F_53 ( V_3 , ( V_3 -> V_162 -> V_154 << 6 ) |
( V_3 -> V_163 -> V_154 << 7 ) ) ;
case V_164 :
V_3 -> V_42 . V_100 . V_101 =
! ( V_146 -> V_154 & V_165 ) ;
break;
case V_166 :
V_3 -> V_42 . V_167 . V_168 = V_146 -> V_154 ;
break;
case V_169 :
V_3 -> V_42 . V_170 . V_171 = V_146 -> V_154 ;
break;
default:
return - V_21 ;
}
return 0 ;
}
static int F_54 ( struct V_1 * V_1 , void * V_38 , struct V_172 * V_173 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
memset ( V_173 , 0 , sizeof( * V_173 ) ) ;
V_173 -> V_168 = 80 ;
V_173 -> V_174 = V_175 | V_176 ;
if( ! V_3 -> V_42 . V_100 . V_101 ) {
V_173 -> V_174 |= V_177 ;
}
V_173 -> V_178 = V_3 -> V_178 ;
V_173 -> V_7 = V_3 -> V_7 ;
if( V_3 -> V_7 > 0 ) {
memcpy ( V_173 -> V_179 , V_3 -> V_179 , V_3 -> V_7 ) ;
V_173 -> V_174 |= V_180 ;
}
V_173 -> V_8 = V_3 -> V_8 ;
if( V_3 -> V_8 > 0 ) {
memcpy ( V_173 -> V_181 , V_3 -> V_181 , V_3 -> V_8 ) ;
V_173 -> V_174 |= V_182 ;
}
F_35 ( L_18 ,
V_173 -> V_7 , V_173 -> V_8 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_1 , void * V_38 , struct V_172 * V_173 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_35 ( L_19 ,
V_173 -> V_7 , V_173 -> V_8 ) ;
V_3 -> V_42 . V_100 . V_101 =
! ( V_173 -> V_174 & V_177 ) ;
V_173 -> V_174 &= V_175 | V_176 |
V_177 ;
if( V_173 -> V_7 != 0 ) {
if( V_173 -> V_7 > 0 &&
V_173 -> V_7 <= sizeof( V_3 -> V_179 ) &&
V_173 -> V_178 >= 0 && V_173 -> V_178 <= 15 ) {
V_3 -> V_178 = V_173 -> V_178 ;
V_3 -> V_7 = V_173 -> V_7 ;
memcpy ( V_3 -> V_179 , V_173 -> V_179 , V_173 -> V_7 ) ;
} else {
LOG ( L_20 ,
V_173 -> V_178 , V_173 -> V_7 ) ;
return - V_21 ;
}
} else {
V_3 -> V_7 = 0 ;
}
if( V_173 -> V_8 != 0 ) {
if( V_173 -> V_8 > 0 &&
V_173 -> V_8 <= sizeof( V_3 -> V_181 ) ) {
V_3 -> V_8 = V_173 -> V_8 ;
memcpy ( V_3 -> V_181 , V_173 -> V_181 , V_173 -> V_8 ) ;
} else {
LOG ( L_21 , V_173 -> V_8 ) ;
return - V_21 ;
}
}
return 0 ;
}
static int F_56 ( struct V_1 * V_1 , void * V_38 , struct V_183 * V_184 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if( V_184 -> type != V_70 ||
V_184 -> V_185 != V_186 )
return - V_21 ;
F_35 ( L_22 , V_184 -> V_16 , V_3 -> V_103 ) ;
V_184 -> V_16 = V_3 -> V_103 ;
memset ( & V_184 -> V_187 , 0 , sizeof( V_184 -> V_187 ) ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_1 , void * V_38 , struct V_188 * V_15 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if( V_15 -> type != V_70 ||
V_15 -> V_65 > V_3 -> V_103 )
return - V_21 ;
V_15 -> V_189 . V_190 = V_3 -> V_28 [ V_15 -> V_65 ] . V_191 - V_3 -> V_192 ;
V_15 -> V_32 = V_3 -> V_84 ;
V_15 -> V_185 = V_186 ;
if( V_3 -> V_14 )
V_15 -> V_71 = V_193 ;
else
V_15 -> V_71 = 0 ;
switch ( V_3 -> V_28 [ V_15 -> V_65 ] . V_29 ) {
case V_105 :
case V_194 :
case V_104 :
V_15 -> V_195 = 0 ;
V_15 -> V_71 = V_196 ;
break;
case V_30 :
V_15 -> V_195 = V_3 -> V_28 [ V_15 -> V_65 ] . V_32 ;
V_15 -> V_197 = V_3 -> V_28 [ V_15 -> V_65 ] . V_197 ;
V_15 -> V_198 = V_3 -> V_28 [ V_15 -> V_65 ] . V_199 ;
V_15 -> V_71 = V_200 ;
break;
}
F_35 ( L_23 ,
V_15 -> V_65 , V_15 -> V_189 . V_190 , V_15 -> V_71 , V_15 -> V_198 ,
V_15 -> V_195 ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_1 , void * V_38 , struct V_188 * V_15 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if( V_15 -> type != V_70 ||
V_15 -> V_185 != V_186 ||
V_15 -> V_65 > V_3 -> V_103 )
return - V_21 ;
F_35 ( L_24 , V_15 -> V_65 ) ;
if( V_3 -> V_28 [ V_15 -> V_65 ] . V_29 == V_30 )
V_3 -> V_28 [ V_15 -> V_65 ] . V_29 = V_105 ;
return 0 ;
}
static int F_59 ( struct V_2 * V_3 )
{
int V_64 ;
int V_201 = - 1 ;
for ( V_64 = 0 ; V_64 < V_3 -> V_103 ; V_64 ++ ) {
if( V_3 -> V_28 [ V_64 ] . V_29 == V_30 ) {
if( V_201 < 0 ) {
V_201 = V_64 ;
} else {
struct V_202 * V_203 , * V_204 ;
V_203 = & V_3 -> V_28 [ V_64 ] . V_197 ;
V_204 = & V_3 -> V_28 [ V_201 ] . V_197 ;
if( V_203 -> V_205 < V_204 -> V_205 ||
( V_203 -> V_205 == V_204 -> V_205 &&
V_203 -> V_206 < V_204 -> V_206 ) )
V_201 = V_64 ;
}
}
}
return V_201 ;
}
static int F_60 ( struct V_1 * V_1 , void * V_38 , struct V_188 * V_15 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_27 ;
if( V_15 -> type != V_70 ||
V_15 -> V_185 != V_186 )
return - V_21 ;
V_27 = F_59 ( V_3 ) ;
if( V_27 < 0 && V_1 -> V_19 & V_20 )
return - V_207 ;
if( V_27 < 0 ) {
struct V_26 * V_208 = V_3 -> V_209 ;
F_22 ( & V_3 -> V_33 ) ;
F_23 ( V_3 -> V_34 ,
! F_12 ( & V_3 -> V_11 ) ||
( V_208 = V_3 -> V_209 ) -> V_29 == V_30 ) ;
F_24 ( & V_3 -> V_33 ) ;
if ( F_25 ( V_35 ) )
return - V_36 ;
if ( ! F_12 ( & V_3 -> V_11 ) )
return - V_37 ;
V_27 = V_208 -> V_210 ;
}
V_15 -> V_65 = V_27 ;
V_15 -> V_195 = V_3 -> V_28 [ V_15 -> V_65 ] . V_32 ;
V_15 -> V_71 = V_193 | V_200 ;
V_15 -> V_80 = V_81 ;
V_15 -> V_197 = V_3 -> V_28 [ V_15 -> V_65 ] . V_197 ;
V_15 -> V_198 = V_3 -> V_28 [ V_15 -> V_65 ] . V_199 ;
V_15 -> V_189 . V_190 = V_3 -> V_28 [ V_15 -> V_65 ] . V_191 - V_3 -> V_192 ;
V_15 -> V_32 = V_3 -> V_84 ;
V_15 -> V_211 = 0 ;
V_15 -> V_187 = 0 ;
memset ( & V_15 -> V_212 , 0 , sizeof( V_15 -> V_212 ) ) ;
F_35 ( L_25 , V_15 -> V_65 ,
V_3 -> V_28 [ V_15 -> V_65 ] . V_29 , V_15 -> V_198 , V_15 -> V_195 ) ;
return 0 ;
}
static int F_61 ( struct V_1 * V_1 , void * V_38 , enum V_213 type )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_133 = - V_21 ;
F_35 ( L_26 , V_3 -> V_31 ) ;
if ( ! V_3 -> V_14 || type != V_70 )
return - V_21 ;
if ( ! V_3 -> V_31 ) {
V_133 = F_62 ( V_3 ,
V_3 -> V_42 . V_170 . V_171 ) ;
if ( ! V_133 )
F_63 ( V_3 -> V_214 , true ) ;
}
return V_133 ;
}
static int F_64 ( struct V_1 * V_1 , void * V_38 , enum V_213 type )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_133 = - V_21 ;
F_35 ( L_27 , V_3 -> V_31 ) ;
if ( ! V_3 -> V_14 || type != V_70 )
return - V_21 ;
if ( V_3 -> V_31 ) {
V_133 = F_13 ( V_3 ) ;
if ( ! V_133 )
F_63 ( V_3 -> V_214 , false ) ;
}
return V_133 ;
}
static int F_65 ( struct V_1 * V_1 , struct V_215 * V_216 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_4 ;
V_4 = F_66 ( V_3 , V_216 ) ;
if( ! V_4 )
V_3 -> V_12 = V_1 -> V_13 ;
return V_4 ;
}
static void F_67 ( struct V_2 * V_3 )
{
V_3 -> V_88 = V_3 -> V_42 . V_102 . V_88 ;
V_3 -> V_89 = V_3 -> V_42 . V_102 . V_89 ;
V_3 -> V_84 = V_217 ;
V_3 -> V_103 = V_218 ;
V_3 -> V_42 . V_219 . V_220 = V_221 ;
V_3 -> V_42 . V_170 . V_171 = V_222 ;
V_3 -> V_74 = V_76 ;
}
void F_68 ( struct V_223 * V_224 )
{
struct V_2 * V_3 =
F_46 ( V_224 , struct V_2 , V_224 ) ;
F_69 ( & V_3 -> V_148 ) ;
F_70 ( & V_3 -> V_224 ) ;
F_71 ( V_3 ) ;
}
int F_72 ( struct V_2 * V_3 )
{
struct V_225 * V_148 = & V_3 -> V_148 ;
struct V_226 V_227 = {
. V_228 = & V_229 ,
. V_153 = V_169 ,
. V_66 = L_28 ,
. type = V_230 ,
. V_231 = V_232 ,
. V_132 = V_233 ,
. V_234 = 1 ,
} ;
int V_133 ;
F_73 ( V_148 , 12 ) ;
F_74 ( V_148 , & V_229 ,
V_155 ,
V_3 -> V_42 . V_43 . V_46 == V_47 ? 1 : 0 ,
255 , 1 , V_235 ) ;
F_74 ( V_148 , & V_229 ,
V_156 , 0 , 255 , 1 , V_236 ) ;
F_74 ( V_148 , & V_229 ,
V_157 , 0 , 255 , 1 , V_237 ) ;
F_74 ( V_148 , & V_229 ,
V_158 , 0 , 1 , 1 , 0 ) ;
F_74 ( V_148 , & V_229 ,
V_164 , 0 ,
V_165 , 0 ,
V_165 ) ;
F_74 ( V_148 , & V_229 ,
V_166 , 1 ,
100 , 1 , 100 ) ;
V_227 . V_238 = V_222 ;
V_3 -> V_214 = F_75 ( V_148 , & V_227 , NULL ) ;
if ( V_3 -> V_42 . V_43 . V_46 != V_47 )
F_74 ( V_148 , & V_229 ,
V_159 , 0 , 1 , 1 , 0 ) ;
if ( V_3 -> V_42 . V_43 . V_46 == V_47 )
F_76 ( V_148 , & V_229 ,
V_160 ,
V_239 , 0 , 0 ) ;
if ( V_3 -> V_42 . V_43 . V_44 == 0x151 ) {
V_3 -> V_162 = F_74 ( V_148 , & V_229 ,
V_161 , 0 , 1 , 1 , 0 ) ;
V_3 -> V_163 = F_74 ( V_148 , & V_229 ,
V_240 , 0 , 1 , 1 , 0 ) ;
F_77 ( 2 , & V_3 -> V_162 ) ;
}
if ( V_148 -> error ) {
V_133 = V_148 -> error ;
F_69 ( V_148 ) ;
return V_133 ;
}
V_3 -> V_11 = V_241 ;
F_78 ( & V_3 -> V_11 , V_3 ) ;
V_3 -> V_11 . V_242 = & V_3 -> V_33 ;
V_3 -> V_11 . V_243 = V_148 ;
V_3 -> V_11 . V_224 = & V_3 -> V_224 ;
F_79 ( V_244 , & V_3 -> V_11 . V_71 ) ;
F_79 ( V_245 , & V_3 -> V_11 . V_71 ) ;
F_67 ( V_3 ) ;
if ( F_80 ( & V_3 -> V_11 , V_246 , V_247 ) < 0 ) {
F_81 ( L_29 ) ;
return - V_248 ;
}
return 0 ;
}
void F_82 ( struct V_2 * V_3 )
{
F_83 ( & V_3 -> V_11 ) ;
}
static void T_5 F_84 ( void )
{
if( V_217 < V_249 ) {
V_217 = V_249 ;
LOG ( L_30 , V_217 ) ;
} else if( V_217 > 1024 * 1024 ) {
V_217 = 1024 * 1024 ;
LOG ( L_31 ,
V_217 ) ;
} else {
V_217 += V_249 - 1 ;
V_217 &= ~ ( V_249 - 1 ) ;
}
if( V_218 < 1 ) {
V_218 = 1 ;
LOG ( L_32 , V_218 ) ;
} else if( V_218 > V_250 ) {
V_218 = V_250 ;
LOG ( L_33 , V_218 ) ;
}
if( V_222 < V_232 || V_222 > V_233 ) {
V_222 = V_251 ;
LOG ( L_34 , V_222 ) ;
}
if ( V_221 != 0 && V_221 != V_151 && V_221 != V_152 ) {
V_221 = 0 ;
LOG ( L_35 ,
V_221 ) ;
}
F_35 ( L_36 ,
V_218 , V_217 , V_222 ) ;
}
static int T_5 F_85 ( void )
{
LOG ( L_37 ,
V_252 , V_253 ) ;
F_84 () ;
F_86 () ;
return 0 ;
}
static void T_6 F_87 ( void )
{
F_88 () ;
F_89 ( 2 * V_254 ) ;
}
