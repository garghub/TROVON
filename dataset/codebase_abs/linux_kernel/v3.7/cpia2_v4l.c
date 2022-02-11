static int F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_4 ;
if ( F_3 ( & V_3 -> V_5 ) )
return - V_6 ;
V_4 = F_4 ( V_1 ) ;
if ( V_4 )
goto V_7;
if ( F_5 ( V_1 ) ) {
if ( F_6 ( V_3 ) ) {
F_7 ( V_1 ) ;
V_4 = - V_8 ;
goto V_7;
}
if ( F_8 ( V_3 ) < 0 ) {
F_7 ( V_1 ) ;
V_4 = - V_9 ;
goto V_7;
}
V_3 -> V_10 = 0 ;
V_3 -> V_11 = 0 ;
}
F_9 ( V_3 ) ;
V_7:
F_10 ( & V_3 -> V_5 ) ;
return V_4 ;
}
static int F_11 ( struct V_1 * V_1 )
{
struct V_12 * V_13 = F_12 ( V_1 ) ;
struct V_2 * V_3 = F_13 ( V_13 ) ;
F_14 ( & V_3 -> V_5 ) ;
if ( F_15 ( & V_3 -> V_14 ) && F_5 ( V_1 ) ) {
F_16 ( V_3 ) ;
F_17 ( V_3 ) ;
F_18 ( V_3 ) ;
F_19 ( V_3 ) ;
}
if ( V_3 -> V_15 == V_1 -> V_16 ) {
V_3 -> V_15 = NULL ;
V_3 -> V_17 = 0 ;
}
F_10 ( & V_3 -> V_5 ) ;
return F_7 ( V_1 ) ;
}
static T_1 F_20 ( struct V_1 * V_1 , char T_2 * V_18 , T_3 V_19 ,
T_4 * V_20 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_21 = V_1 -> V_22 & V_23 ;
T_1 V_24 ;
if( ! V_3 )
return - V_25 ;
if ( F_3 ( & V_3 -> V_5 ) )
return - V_6 ;
V_24 = F_21 ( V_3 , V_18 , V_19 , V_21 ) ;
F_10 ( & V_3 -> V_5 ) ;
return V_24 ;
}
static unsigned int F_22 ( struct V_1 * V_26 , struct V_27 * V_28 )
{
struct V_2 * V_3 = F_2 ( V_26 ) ;
unsigned int V_29 ;
F_14 ( & V_3 -> V_5 ) ;
V_29 = F_23 ( V_3 , V_26 , V_28 ) ;
F_10 ( & V_3 -> V_5 ) ;
return V_29 ;
}
static int F_24 ( struct V_2 * V_3 , int V_30 )
{
struct V_31 * V_32 = & V_3 -> V_33 [ V_30 ] ;
while ( 1 ) {
if ( V_32 -> V_34 == V_35 )
return 0 ;
if ( ! V_3 -> V_36 ) {
V_32 -> V_34 = V_35 ;
V_32 -> V_37 = 0 ;
return 0 ;
}
F_10 ( & V_3 -> V_5 ) ;
F_25 ( V_3 -> V_38 ,
! V_3 -> V_36 ||
V_32 -> V_34 == V_35 ) ;
F_14 ( & V_3 -> V_5 ) ;
if ( F_26 ( V_39 ) )
return - V_6 ;
if ( ! F_15 ( & V_3 -> V_14 ) )
return - V_40 ;
}
}
static int F_27 ( struct V_1 * V_1 , void * V_41 , struct V_42 * V_43 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
strcpy ( V_43 -> V_44 , L_1 ) ;
if ( V_3 -> V_45 . V_46 . V_47 == 0x151 )
strcpy ( V_43 -> V_48 , L_2 ) ;
else
strcpy ( V_43 -> V_48 , L_3 ) ;
switch ( V_3 -> V_45 . V_46 . V_49 ) {
case V_50 :
strcat ( V_43 -> V_48 , L_4 ) ;
break;
case V_51 :
strcat ( V_43 -> V_48 , L_5 ) ;
break;
default:
strcat ( V_43 -> V_48 , L_6 ) ;
break;
}
switch ( V_3 -> V_45 . V_52 . V_53 ) {
case V_54 :
strcat ( V_43 -> V_48 , L_7 ) ;
break;
case V_55 :
strcat ( V_43 -> V_48 , L_8 ) ;
break;
case V_56 :
strcat ( V_43 -> V_48 , L_9 ) ;
break;
case V_57 :
strcat ( V_43 -> V_48 , L_10 ) ;
break;
case V_58 :
strcat ( V_43 -> V_48 , L_11 ) ;
break;
default:
strcat ( V_43 -> V_48 , L_12 ) ;
break;
}
if ( F_28 ( V_3 -> V_13 , V_43 -> V_59 , sizeof( V_43 -> V_59 ) ) < 0 )
memset ( V_43 -> V_59 , 0 , sizeof( V_43 -> V_59 ) ) ;
V_43 -> V_60 = V_61 |
V_62 |
V_63 ;
V_43 -> V_64 = V_43 -> V_60 |
V_65 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 , void * V_41 , struct V_66 * V_67 )
{
if ( V_67 -> V_68 )
return - V_25 ;
strcpy ( V_67 -> V_69 , L_13 ) ;
V_67 -> type = V_70 ;
return 0 ;
}
static int F_30 ( struct V_1 * V_1 , void * V_41 , unsigned int * V_67 )
{
* V_67 = 0 ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , void * V_41 , unsigned int V_67 )
{
return V_67 ? - V_25 : 0 ;
}
static int F_32 ( struct V_1 * V_1 , void * V_41 ,
struct V_71 * V_72 )
{
int V_68 = V_72 -> V_68 ;
if ( V_68 < 0 || V_68 > 1 )
return - V_25 ;
memset ( V_72 , 0 , sizeof( * V_72 ) ) ;
V_72 -> V_68 = V_68 ;
V_72 -> type = V_73 ;
V_72 -> V_74 = V_75 ;
switch( V_68 ) {
case 0 :
strcpy ( V_72 -> V_76 , L_14 ) ;
V_72 -> V_77 = V_78 ;
break;
case 1 :
strcpy ( V_72 -> V_76 , L_15 ) ;
V_72 -> V_77 = V_79 ;
break;
default:
return - V_25 ;
}
return 0 ;
}
static int F_33 ( struct V_1 * V_1 , void * V_41 ,
struct V_80 * V_72 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( V_72 -> V_81 . V_82 . V_77 != V_78 &&
V_72 -> V_81 . V_82 . V_77 != V_79 )
return - V_25 ;
V_72 -> V_81 . V_82 . V_83 = V_84 ;
V_72 -> V_81 . V_82 . V_85 = 0 ;
V_72 -> V_81 . V_82 . V_86 = V_3 -> V_87 ;
V_72 -> V_81 . V_82 . V_88 = V_89 ;
V_72 -> V_81 . V_82 . V_90 = 0 ;
switch ( F_34 ( V_72 -> V_81 . V_82 . V_91 , V_72 -> V_81 . V_82 . V_92 ) ) {
case V_93 :
V_72 -> V_81 . V_82 . V_91 = 640 ;
V_72 -> V_81 . V_82 . V_92 = 480 ;
break;
case V_94 :
V_72 -> V_81 . V_82 . V_91 = 352 ;
V_72 -> V_81 . V_82 . V_92 = 288 ;
break;
case V_95 :
V_72 -> V_81 . V_82 . V_91 = 320 ;
V_72 -> V_81 . V_82 . V_92 = 240 ;
break;
case V_96 :
V_72 -> V_81 . V_82 . V_91 = 288 ;
V_72 -> V_81 . V_82 . V_92 = 216 ;
break;
case V_97 :
V_72 -> V_81 . V_82 . V_91 = 256 ;
V_72 -> V_81 . V_82 . V_92 = 192 ;
break;
case V_98 :
V_72 -> V_81 . V_82 . V_91 = 224 ;
V_72 -> V_81 . V_82 . V_92 = 168 ;
break;
case V_99 :
V_72 -> V_81 . V_82 . V_91 = 192 ;
V_72 -> V_81 . V_82 . V_92 = 144 ;
break;
case V_100 :
default:
V_72 -> V_81 . V_82 . V_91 = 176 ;
V_72 -> V_81 . V_82 . V_92 = 144 ;
break;
}
return 0 ;
}
static int F_35 ( struct V_1 * V_1 , void * V_101 ,
struct V_80 * V_72 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_102 , V_32 ;
V_102 = F_33 ( V_1 , V_101 , V_72 ) ;
if( V_102 != 0 )
return V_102 ;
V_3 -> V_77 = V_72 -> V_81 . V_82 . V_77 ;
V_3 -> V_45 . V_103 . V_104 = 0 ;
F_36 ( L_16 ,
V_72 -> V_81 . V_82 . V_91 , V_72 -> V_81 . V_82 . V_92 ) ;
if ( V_72 -> V_81 . V_82 . V_91 != V_3 -> V_91 ||
V_72 -> V_81 . V_82 . V_92 != V_3 -> V_92 ) {
V_3 -> V_91 = V_72 -> V_81 . V_82 . V_91 ;
V_3 -> V_92 = V_72 -> V_81 . V_82 . V_92 ;
V_3 -> V_45 . V_105 . V_91 = V_72 -> V_81 . V_82 . V_91 ;
V_3 -> V_45 . V_105 . V_92 = V_72 -> V_81 . V_82 . V_92 ;
F_37 ( V_3 ) ;
}
for ( V_32 = 0 ; V_32 < V_3 -> V_106 ; ++ V_32 ) {
if ( V_3 -> V_33 [ V_32 ] . V_34 == V_107 )
if ( ( V_102 = F_24 ( V_3 , V_32 ) ) < 0 )
return V_102 ;
V_3 -> V_33 [ V_32 ] . V_34 = V_108 ;
}
return 0 ;
}
static int F_38 ( struct V_1 * V_1 , void * V_41 ,
struct V_80 * V_72 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
V_72 -> V_81 . V_82 . V_91 = V_3 -> V_91 ;
V_72 -> V_81 . V_82 . V_92 = V_3 -> V_92 ;
V_72 -> V_81 . V_82 . V_77 = V_3 -> V_77 ;
V_72 -> V_81 . V_82 . V_83 = V_84 ;
V_72 -> V_81 . V_82 . V_85 = 0 ;
V_72 -> V_81 . V_82 . V_86 = V_3 -> V_87 ;
V_72 -> V_81 . V_82 . V_88 = V_89 ;
V_72 -> V_81 . V_82 . V_90 = 0 ;
return 0 ;
}
static int F_39 ( struct V_1 * V_1 , void * V_41 , struct V_109 * V_110 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if ( V_110 -> type != V_73 )
return - V_25 ;
V_110 -> V_111 . V_112 = 0 ;
V_110 -> V_111 . V_113 = 0 ;
V_110 -> V_111 . V_91 = V_3 -> V_91 ;
V_110 -> V_111 . V_92 = V_3 -> V_92 ;
V_110 -> V_114 . V_112 = 0 ;
V_110 -> V_114 . V_113 = 0 ;
V_110 -> V_114 . V_91 = V_3 -> V_91 ;
V_110 -> V_114 . V_92 = V_3 -> V_92 ;
V_110 -> V_115 . V_116 = 1 ;
V_110 -> V_115 . V_117 = 1 ;
return 0 ;
}
static int F_40 ( struct V_1 * V_1 , void * V_41 , struct V_118 * V_119 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_120 * V_121 = & V_119 -> V_122 . V_123 ;
int V_67 ;
if ( V_119 -> type != V_73 )
return - V_25 ;
V_121 -> V_124 = V_125 ;
V_121 -> V_126 = V_3 -> V_106 ;
for ( V_67 = 0 ; V_67 < F_41 ( V_127 ) ; V_67 ++ )
if ( V_3 -> V_45 . V_128 . V_129 == V_127 [ V_67 ] . V_130 ) {
V_121 -> V_131 = V_127 [ V_67 ] . V_132 ;
break;
}
return 0 ;
}
static int F_42 ( struct V_1 * V_1 , void * V_41 , struct V_118 * V_119 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
struct V_120 * V_121 = & V_119 -> V_122 . V_123 ;
struct V_133 V_134 = V_121 -> V_131 ;
int V_135 = F_41 ( V_127 ) - 1 ;
int V_24 ;
int V_67 ;
V_24 = F_40 ( V_1 , V_41 , V_119 ) ;
if ( V_24 || ! V_134 . V_117 || ! V_134 . V_116 )
return V_24 ;
if ( V_3 -> V_45 . V_46 . V_49 == V_50 &&
V_3 -> V_45 . V_52 . V_53 == V_58 )
V_135 -= 2 ;
for ( V_67 = 0 ; V_67 <= V_135 ; V_67 ++ ) {
struct V_133 V_136 = V_134 ;
struct V_133 V_137 = V_127 [ V_67 ] . V_132 ;
V_136 . V_116 *= V_137 . V_117 ;
V_137 . V_116 *= V_136 . V_117 ;
if ( V_136 . V_116 >= V_137 . V_116 )
break;
}
if ( V_67 > V_135 )
V_67 = V_135 ;
V_121 -> V_131 = V_127 [ V_67 ] . V_132 ;
return F_43 ( V_3 , V_127 [ V_67 ] . V_130 ) ;
}
static int F_44 ( struct V_1 * V_1 , void * V_41 ,
struct V_138 * V_139 )
{
if ( V_139 -> V_140 != V_78 &&
V_139 -> V_140 != V_79 )
return - V_25 ;
if ( V_139 -> V_68 >= F_41 ( V_141 ) )
return - V_25 ;
V_139 -> type = V_142 ;
V_139 -> V_143 . V_91 = V_141 [ V_139 -> V_68 ] . V_91 ;
V_139 -> V_143 . V_92 = V_141 [ V_139 -> V_68 ] . V_92 ;
return 0 ;
}
static int F_45 ( struct V_1 * V_1 , void * V_41 ,
struct V_144 * V_145 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_135 = F_41 ( V_127 ) - 1 ;
int V_67 ;
if ( V_145 -> V_140 != V_78 &&
V_145 -> V_140 != V_79 )
return - V_25 ;
if ( V_3 -> V_45 . V_46 . V_49 == V_50 &&
V_3 -> V_45 . V_52 . V_53 == V_58 )
V_135 -= 2 ;
if ( V_145 -> V_68 > V_135 )
return - V_25 ;
for ( V_67 = 0 ; V_67 < F_41 ( V_141 ) ; V_67 ++ )
if ( V_145 -> V_91 == V_141 [ V_67 ] . V_91 &&
V_145 -> V_92 == V_141 [ V_67 ] . V_92 )
break;
if ( V_67 == F_41 ( V_141 ) )
return - V_25 ;
V_145 -> type = V_146 ;
V_145 -> V_143 = V_127 [ V_145 -> V_68 ] . V_132 ;
return 0 ;
}
static int F_46 ( struct V_147 * V_148 )
{
struct V_2 * V_3 =
F_47 ( V_148 -> V_149 , struct V_2 , V_150 ) ;
static const int V_151 [] = {
V_152 ,
V_153 ,
V_154 ,
} ;
F_36 ( L_17 , V_148 -> V_155 , V_148 -> V_156 ) ;
switch ( V_148 -> V_155 ) {
case V_157 :
F_48 ( V_3 , V_148 -> V_156 ) ;
break;
case V_158 :
F_49 ( V_3 , V_148 -> V_156 ) ;
break;
case V_159 :
F_50 ( V_3 , V_148 -> V_156 ) ;
break;
case V_160 :
F_51 ( V_3 , V_148 -> V_156 ) ;
break;
case V_161 :
F_52 ( V_3 , V_148 -> V_156 ) ;
break;
case V_162 :
return F_53 ( V_3 , V_151 [ V_148 -> V_156 ] ) ;
case V_163 :
return F_54 ( V_3 , ( V_3 -> V_164 -> V_156 << 6 ) |
( V_3 -> V_165 -> V_156 << 7 ) ) ;
case V_166 :
V_3 -> V_45 . V_103 . V_104 =
! ( V_148 -> V_156 & V_167 ) ;
break;
case V_168 :
V_3 -> V_45 . V_169 . V_170 = V_148 -> V_156 ;
break;
case V_171 :
V_3 -> V_45 . V_172 . V_173 = V_148 -> V_156 ;
break;
default:
return - V_25 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_1 , void * V_41 , struct V_174 * V_175 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
memset ( V_175 , 0 , sizeof( * V_175 ) ) ;
V_175 -> V_170 = 80 ;
V_175 -> V_176 = V_177 | V_178 ;
if( ! V_3 -> V_45 . V_103 . V_104 ) {
V_175 -> V_176 |= V_179 ;
}
V_175 -> V_180 = V_3 -> V_180 ;
V_175 -> V_10 = V_3 -> V_10 ;
if( V_3 -> V_10 > 0 ) {
memcpy ( V_175 -> V_181 , V_3 -> V_181 , V_3 -> V_10 ) ;
V_175 -> V_176 |= V_182 ;
}
V_175 -> V_11 = V_3 -> V_11 ;
if( V_3 -> V_11 > 0 ) {
memcpy ( V_175 -> V_183 , V_3 -> V_183 , V_3 -> V_11 ) ;
V_175 -> V_176 |= V_184 ;
}
F_36 ( L_18 ,
V_175 -> V_10 , V_175 -> V_11 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_1 , void * V_41 ,
const struct V_174 * V_175 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
F_36 ( L_19 ,
V_175 -> V_10 , V_175 -> V_11 ) ;
V_3 -> V_45 . V_103 . V_104 =
! ( V_175 -> V_176 & V_179 ) ;
if( V_175 -> V_10 != 0 ) {
if( V_175 -> V_10 > 0 &&
V_175 -> V_10 <= sizeof( V_3 -> V_181 ) &&
V_175 -> V_180 >= 0 && V_175 -> V_180 <= 15 ) {
V_3 -> V_180 = V_175 -> V_180 ;
V_3 -> V_10 = V_175 -> V_10 ;
memcpy ( V_3 -> V_181 , V_175 -> V_181 , V_175 -> V_10 ) ;
} else {
LOG ( L_20 ,
V_175 -> V_180 , V_175 -> V_10 ) ;
return - V_25 ;
}
} else {
V_3 -> V_10 = 0 ;
}
if( V_175 -> V_11 != 0 ) {
if( V_175 -> V_11 > 0 &&
V_175 -> V_11 <= sizeof( V_3 -> V_183 ) ) {
V_3 -> V_11 = V_175 -> V_11 ;
memcpy ( V_3 -> V_183 , V_175 -> V_183 , V_175 -> V_11 ) ;
} else {
LOG ( L_21 , V_175 -> V_11 ) ;
return - V_25 ;
}
}
return 0 ;
}
static int F_57 ( struct V_1 * V_1 , void * V_41 , struct V_185 * V_186 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if( V_186 -> type != V_73 ||
V_186 -> V_187 != V_188 )
return - V_25 ;
F_36 ( L_22 , V_186 -> V_19 , V_3 -> V_106 ) ;
V_186 -> V_19 = V_3 -> V_106 ;
memset ( & V_186 -> V_189 , 0 , sizeof( V_186 -> V_189 ) ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_1 , void * V_41 , struct V_190 * V_18 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if( V_18 -> type != V_73 ||
V_18 -> V_68 > V_3 -> V_106 )
return - V_25 ;
V_18 -> V_191 . V_192 = V_3 -> V_33 [ V_18 -> V_68 ] . V_193 - V_3 -> V_194 ;
V_18 -> V_37 = V_3 -> V_87 ;
V_18 -> V_187 = V_188 ;
if( V_3 -> V_17 )
V_18 -> V_74 = V_195 ;
else
V_18 -> V_74 = 0 ;
switch ( V_3 -> V_33 [ V_18 -> V_68 ] . V_34 ) {
case V_108 :
case V_196 :
case V_107 :
V_18 -> V_197 = 0 ;
V_18 -> V_74 = V_198 ;
break;
case V_35 :
V_18 -> V_197 = V_3 -> V_33 [ V_18 -> V_68 ] . V_37 ;
V_18 -> V_199 = V_3 -> V_33 [ V_18 -> V_68 ] . V_199 ;
V_18 -> V_200 = V_3 -> V_33 [ V_18 -> V_68 ] . V_201 ;
V_18 -> V_74 = V_202 ;
break;
}
F_36 ( L_23 ,
V_18 -> V_68 , V_18 -> V_191 . V_192 , V_18 -> V_74 , V_18 -> V_200 ,
V_18 -> V_197 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_1 , void * V_41 , struct V_190 * V_18 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
if( V_18 -> type != V_73 ||
V_18 -> V_187 != V_188 ||
V_18 -> V_68 > V_3 -> V_106 )
return - V_25 ;
F_36 ( L_24 , V_18 -> V_68 ) ;
if( V_3 -> V_33 [ V_18 -> V_68 ] . V_34 == V_35 )
V_3 -> V_33 [ V_18 -> V_68 ] . V_34 = V_108 ;
return 0 ;
}
static int F_60 ( struct V_2 * V_3 )
{
int V_67 ;
int V_203 = - 1 ;
for ( V_67 = 0 ; V_67 < V_3 -> V_106 ; V_67 ++ ) {
if( V_3 -> V_33 [ V_67 ] . V_34 == V_35 ) {
if( V_203 < 0 ) {
V_203 = V_67 ;
} else {
struct V_204 * V_205 , * V_206 ;
V_205 = & V_3 -> V_33 [ V_67 ] . V_199 ;
V_206 = & V_3 -> V_33 [ V_203 ] . V_199 ;
if( V_205 -> V_207 < V_206 -> V_207 ||
( V_205 -> V_207 == V_206 -> V_207 &&
V_205 -> V_208 < V_206 -> V_208 ) )
V_203 = V_67 ;
}
}
}
return V_203 ;
}
static int F_61 ( struct V_1 * V_1 , void * V_41 , struct V_190 * V_18 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_32 ;
if( V_18 -> type != V_73 ||
V_18 -> V_187 != V_188 )
return - V_25 ;
V_32 = F_60 ( V_3 ) ;
if( V_32 < 0 && V_1 -> V_22 & V_23 )
return - V_209 ;
if( V_32 < 0 ) {
struct V_31 * V_210 = V_3 -> V_211 ;
F_10 ( & V_3 -> V_5 ) ;
F_25 ( V_3 -> V_38 ,
! F_15 ( & V_3 -> V_14 ) ||
( V_210 = V_3 -> V_211 ) -> V_34 == V_35 ) ;
F_14 ( & V_3 -> V_5 ) ;
if ( F_26 ( V_39 ) )
return - V_6 ;
if ( ! F_15 ( & V_3 -> V_14 ) )
return - V_40 ;
V_32 = V_210 -> V_212 ;
}
V_18 -> V_68 = V_32 ;
V_18 -> V_197 = V_3 -> V_33 [ V_18 -> V_68 ] . V_37 ;
V_18 -> V_74 = V_195 | V_202 ;
V_18 -> V_83 = V_84 ;
V_18 -> V_199 = V_3 -> V_33 [ V_18 -> V_68 ] . V_199 ;
V_18 -> V_200 = V_3 -> V_33 [ V_18 -> V_68 ] . V_201 ;
V_18 -> V_191 . V_192 = V_3 -> V_33 [ V_18 -> V_68 ] . V_193 - V_3 -> V_194 ;
V_18 -> V_37 = V_3 -> V_87 ;
V_18 -> V_213 = 0 ;
V_18 -> V_189 = 0 ;
memset ( & V_18 -> V_214 , 0 , sizeof( V_18 -> V_214 ) ) ;
F_36 ( L_25 , V_18 -> V_68 ,
V_3 -> V_33 [ V_18 -> V_68 ] . V_34 , V_18 -> V_200 , V_18 -> V_197 ) ;
return 0 ;
}
static int F_62 ( struct V_1 * V_1 , void * V_41 , enum V_215 type )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_24 = - V_25 ;
F_36 ( L_26 , V_3 -> V_36 ) ;
if ( ! V_3 -> V_17 || type != V_73 )
return - V_25 ;
if ( ! V_3 -> V_36 ) {
V_24 = F_63 ( V_3 ,
V_3 -> V_45 . V_172 . V_173 ) ;
if ( ! V_24 )
F_64 ( V_3 -> V_216 , true ) ;
}
return V_24 ;
}
static int F_65 ( struct V_1 * V_1 , void * V_41 , enum V_215 type )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_24 = - V_25 ;
F_36 ( L_27 , V_3 -> V_36 ) ;
if ( ! V_3 -> V_17 || type != V_73 )
return - V_25 ;
if ( V_3 -> V_36 ) {
V_24 = F_16 ( V_3 ) ;
if ( ! V_24 )
F_64 ( V_3 -> V_216 , false ) ;
}
return V_24 ;
}
static int F_66 ( struct V_1 * V_1 , struct V_217 * V_218 )
{
struct V_2 * V_3 = F_2 ( V_1 ) ;
int V_4 ;
if ( F_3 ( & V_3 -> V_5 ) )
return - V_6 ;
V_4 = F_67 ( V_3 , V_218 ) ;
if( ! V_4 )
V_3 -> V_15 = V_1 -> V_16 ;
F_10 ( & V_3 -> V_5 ) ;
return V_4 ;
}
static void F_68 ( struct V_2 * V_3 )
{
V_3 -> V_91 = V_3 -> V_45 . V_105 . V_91 ;
V_3 -> V_92 = V_3 -> V_45 . V_105 . V_92 ;
V_3 -> V_87 = V_219 ;
V_3 -> V_106 = V_220 ;
V_3 -> V_45 . V_221 . V_222 = V_223 ;
V_3 -> V_45 . V_172 . V_173 = V_224 ;
V_3 -> V_77 = V_79 ;
}
void F_69 ( struct V_225 * V_226 )
{
struct V_2 * V_3 =
F_47 ( V_226 , struct V_2 , V_226 ) ;
F_70 ( & V_3 -> V_150 ) ;
F_71 ( & V_3 -> V_226 ) ;
F_72 ( V_3 ) ;
}
int F_73 ( struct V_2 * V_3 )
{
struct V_227 * V_150 = & V_3 -> V_150 ;
struct V_228 V_229 = {
. V_230 = & V_231 ,
. V_155 = V_171 ,
. V_69 = L_28 ,
. type = V_232 ,
. V_233 = V_234 ,
. V_135 = V_235 ,
. V_236 = 1 ,
} ;
int V_24 ;
F_74 ( V_150 , 12 ) ;
F_75 ( V_150 , & V_231 ,
V_157 ,
V_3 -> V_45 . V_46 . V_49 == V_50 ? 1 : 0 ,
255 , 1 , V_237 ) ;
F_75 ( V_150 , & V_231 ,
V_158 , 0 , 255 , 1 , V_238 ) ;
F_75 ( V_150 , & V_231 ,
V_159 , 0 , 255 , 1 , V_239 ) ;
F_75 ( V_150 , & V_231 ,
V_160 , 0 , 1 , 1 , 0 ) ;
F_75 ( V_150 , & V_231 ,
V_166 , 0 ,
V_167 , 0 ,
V_167 ) ;
F_75 ( V_150 , & V_231 ,
V_168 , 1 ,
100 , 1 , 100 ) ;
V_229 . V_240 = V_224 ;
V_3 -> V_216 = F_76 ( V_150 , & V_229 , NULL ) ;
if ( V_3 -> V_45 . V_46 . V_49 != V_50 )
F_75 ( V_150 , & V_231 ,
V_161 , 0 , 1 , 1 , 0 ) ;
if ( V_3 -> V_45 . V_46 . V_49 == V_50 )
F_77 ( V_150 , & V_231 ,
V_162 ,
V_241 , 0 , 0 ) ;
if ( V_3 -> V_45 . V_46 . V_47 == 0x151 ) {
V_3 -> V_164 = F_75 ( V_150 , & V_231 ,
V_163 , 0 , 1 , 1 , 0 ) ;
V_3 -> V_165 = F_75 ( V_150 , & V_231 ,
V_242 , 0 , 1 , 1 , 0 ) ;
F_78 ( 2 , & V_3 -> V_164 ) ;
}
if ( V_150 -> error ) {
V_24 = V_150 -> error ;
F_70 ( V_150 ) ;
return V_24 ;
}
V_3 -> V_14 = V_243 ;
F_79 ( & V_3 -> V_14 , V_3 ) ;
V_3 -> V_14 . V_244 = & V_3 -> V_5 ;
V_3 -> V_14 . V_245 = V_150 ;
V_3 -> V_14 . V_226 = & V_3 -> V_226 ;
F_80 ( V_246 , & V_3 -> V_14 . V_74 ) ;
F_68 ( V_3 ) ;
if ( F_81 ( & V_3 -> V_14 , V_247 , V_248 ) < 0 ) {
F_82 ( L_29 ) ;
return - V_249 ;
}
return 0 ;
}
void F_83 ( struct V_2 * V_3 )
{
F_84 ( & V_3 -> V_14 ) ;
}
static void T_5 F_85 ( void )
{
if( V_219 < V_250 ) {
V_219 = V_250 ;
LOG ( L_30 , V_219 ) ;
} else if( V_219 > 1024 * 1024 ) {
V_219 = 1024 * 1024 ;
LOG ( L_31 ,
V_219 ) ;
} else {
V_219 += V_250 - 1 ;
V_219 &= ~ ( V_250 - 1 ) ;
}
if( V_220 < 1 ) {
V_220 = 1 ;
LOG ( L_32 , V_220 ) ;
} else if( V_220 > V_251 ) {
V_220 = V_251 ;
LOG ( L_33 , V_220 ) ;
}
if( V_224 < V_234 || V_224 > V_235 ) {
V_224 = V_252 ;
LOG ( L_34 , V_224 ) ;
}
if ( V_223 != 0 && V_223 != V_153 && V_223 != V_154 ) {
V_223 = 0 ;
LOG ( L_35 ,
V_223 ) ;
}
F_36 ( L_36 ,
V_220 , V_219 , V_224 ) ;
}
static int T_5 F_86 ( void )
{
LOG ( L_37 ,
V_253 , V_254 ) ;
F_85 () ;
F_87 () ;
return 0 ;
}
static void T_6 F_88 ( void )
{
F_89 () ;
F_90 ( 2 * V_255 ) ;
}
