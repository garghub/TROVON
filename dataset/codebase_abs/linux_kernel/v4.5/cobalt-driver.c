static void F_1 ( struct V_1 * V_1 , bool V_2 )
{
if ( V_2 ) {
unsigned V_3 = V_4 |
V_5 |
V_6 |
V_7 |
V_8 |
V_9 |
V_10 |
V_11 |
V_12 |
V_13 |
V_14 |
V_15 |
V_16 ;
if ( V_1 -> V_17 )
V_3 |= V_18 |
V_19 |
V_20 ;
if ( V_1 -> V_21 )
V_3 |= V_22 |
V_23 |
V_24 ;
F_2 ( V_1 , V_25 , 0xffffffff ) ;
F_2 ( V_1 , V_26 , V_3 ) ;
} else {
F_2 ( V_1 , V_26 , 0 ) ;
}
}
static unsigned F_3 ( struct V_27 * V_28 )
{
struct V_1 * V_1 = F_4 ( V_28 -> V_29 ) ;
unsigned V_30 ;
for ( V_30 = 0 ; V_30 < V_31 ; V_30 ++ )
if ( V_28 == V_1 -> V_32 [ V_30 ] . V_28 )
return V_30 ;
F_5 ( L_1 ) ;
return 0 ;
}
static void F_6 ( struct V_27 * V_28 ,
unsigned int V_33 , void * V_34 )
{
struct V_1 * V_1 = F_4 ( V_28 -> V_29 ) ;
unsigned V_35 = F_3 ( V_28 ) ;
struct V_36 * V_37 = & V_1 -> V_32 [ V_35 ] ;
bool V_38 = V_34 ? * ( ( int * ) V_34 ) : false ;
if ( V_37 -> V_39 )
return;
switch ( V_33 ) {
case V_40 :
F_7 ( V_1 ,
F_8 ( V_35 ) , V_38 ) ;
F_9 ( 1 , L_2 , V_35 , V_38 ) ;
break;
case V_41 :
F_9 ( 1 , L_3 , V_35 ) ;
F_10 ( & V_37 -> V_42 , V_34 ) ;
break;
default:
break;
}
}
static int F_11 ( T_1 V_43 )
{
switch ( V_43 ) {
case 0 : return 128 ;
case 1 : return 256 ;
case 2 : return 512 ;
case 3 : return 1024 ;
case 4 : return 2048 ;
case 5 : return 4096 ;
default: return 0 ;
}
return 0 ;
}
static const char * F_12 ( T_1 V_44 )
{
switch ( V_44 & V_45 ) {
case 1 : return L_4 ;
case 2 : return L_5 ;
case 3 : return L_6 ;
}
return L_7 ;
}
void F_13 ( struct V_1 * V_1 )
{
struct V_46 * V_46 = V_1 -> V_46 ;
struct V_46 * V_47 = V_1 -> V_46 -> V_48 -> V_49 ;
int V_50 ;
int V_51 ;
T_2 V_52 ;
T_1 V_44 , V_53 ;
V_50 = F_14 ( V_46 , V_54 ) ;
V_51 = F_14 ( V_47 , V_54 ) ;
F_15 ( V_46 , V_50 + V_55 , & V_52 ) ;
F_16 ( V_46 , V_50 + V_56 , & V_53 ) ;
F_16 ( V_46 , V_50 + V_57 , & V_44 ) ;
F_17 ( L_8 ,
V_52 , F_11 ( V_52 & V_58 ) ) ;
F_17 ( L_9 ,
V_53 ,
F_11 ( ( V_53 & V_59 ) >> 5 ) ,
F_11 ( ( V_53 & V_60 ) >> 12 ) ) ;
F_17 ( L_10 , V_44 ) ;
F_15 ( V_46 , V_50 + V_61 , & V_52 ) ;
F_16 ( V_46 , V_50 + V_62 , & V_53 ) ;
F_16 ( V_46 , V_50 + V_63 , & V_44 ) ;
F_17 ( L_11 ,
V_52 , F_12 ( V_52 ) ,
( V_52 & V_64 ) >> 4 ) ;
F_17 ( L_12 , V_53 ) ;
F_17 ( L_13 ,
V_44 , F_12 ( V_44 ) ,
( V_44 & V_65 ) >> 4 ) ;
F_15 ( V_47 , V_51 + V_61 , & V_52 ) ;
F_17 ( L_14 ,
V_52 , F_12 ( V_52 ) ,
( V_52 & V_64 ) >> 4 ) ;
F_15 ( V_46 , V_50 + V_66 , & V_52 ) ;
F_16 ( V_46 , V_50 + V_67 , & V_53 ) ;
F_16 ( V_46 , V_50 + V_68 , & V_44 ) ;
F_17 ( L_15 , V_52 ) ;
F_17 ( L_16 , V_53 ) ;
F_17 ( L_17 , V_44 ) ;
}
static unsigned F_18 ( struct V_1 * V_1 )
{
struct V_46 * V_46 = V_1 -> V_46 ;
unsigned V_50 ;
T_1 V_69 ;
V_50 = F_14 ( V_46 , V_54 ) ;
if ( ! V_50 )
return 0 ;
F_16 ( V_46 , V_50 + V_63 , & V_69 ) ;
return ( V_69 & V_65 ) >> 4 ;
}
static unsigned F_19 ( struct V_1 * V_1 )
{
struct V_46 * V_46 = V_1 -> V_46 -> V_48 -> V_49 ;
unsigned V_50 ;
T_2 V_69 ;
V_50 = F_14 ( V_46 , V_54 ) ;
if ( ! V_50 )
return 0 ;
F_15 ( V_46 , V_50 + V_61 , & V_69 ) ;
return ( V_69 & V_64 ) >> 4 ;
}
static void F_20 ( struct V_1 * V_1 , struct V_46 * V_46 )
{
T_1 V_53 , V_70 ;
T_2 V_71 , V_72 ;
F_16 ( V_46 , 0x52 , & V_53 ) ;
F_17 ( L_18 , V_53 & 1 ? L_19 : L_20 ) ;
F_17 ( L_21 ,
( 1 << ( ( V_53 >> 1 ) & 7 ) ) , ( 1 << ( ( V_53 >> 4 ) & 7 ) ) ) ;
if ( V_53 & 0x80 )
F_17 ( L_22 ) ;
F_15 ( V_46 , 0x54 , & V_71 ) ;
F_15 ( V_46 , 0x58 , & V_72 ) ;
F_16 ( V_46 , 0x5c , & V_70 ) ;
if ( V_53 & 0x80 )
F_17 ( L_23 ,
V_72 , V_71 , V_70 ) ;
else
F_17 ( L_24 ,
V_71 , V_70 ) ;
}
static void F_21 ( struct V_1 * V_1 , struct V_46 * V_46 )
{
if ( V_1 -> V_73 ) {
F_22 ( V_46 , V_1 -> V_73 ) ;
V_1 -> V_73 = NULL ;
}
if ( V_1 -> V_74 ) {
F_22 ( V_46 , V_1 -> V_74 ) ;
V_1 -> V_74 = NULL ;
}
}
static void F_23 ( struct V_1 * V_1 , struct V_46 * V_46 )
{
F_24 ( V_46 -> V_75 , ( void * ) V_1 ) ;
if ( V_1 -> V_76 )
F_25 ( V_46 ) ;
}
static int F_26 ( struct V_1 * V_1 , struct V_46 * V_46 ,
const struct V_77 * V_78 )
{
T_2 V_53 ;
int V_79 ;
F_9 ( 1 , L_25 ) ;
V_79 = F_27 ( V_46 ) ;
if ( V_79 ) {
F_5 ( L_26 ) ;
return V_79 ;
}
F_28 ( V_46 ) ;
F_29 ( V_46 , V_80 , & V_1 -> V_81 ) ;
F_16 ( V_46 , V_82 , & V_1 -> V_83 ) ;
switch ( V_1 -> V_83 ) {
case V_84 :
F_17 ( L_27 ) ;
break;
default:
F_17 ( L_28 ) ;
break;
}
if ( F_18 ( V_1 ) != 8 ) {
F_30 ( L_29 ,
F_18 ( V_1 ) ) ;
if ( F_19 ( V_1 ) < 8 )
F_30 ( L_30 ,
F_19 ( V_1 ) ) ;
if ( F_18 ( V_1 ) != F_19 ( V_1 ) ) {
F_5 ( L_31 ) ;
V_79 = - V_85 ;
goto V_86;
}
}
if ( F_31 ( V_46 , F_32 ( 64 ) ) ) {
V_79 = F_31 ( V_46 , F_32 ( 32 ) ) ;
if ( V_79 ) {
F_5 ( L_32 ) ;
goto V_86;
}
}
V_79 = F_33 ( V_46 , L_33 ) ;
if ( V_79 ) {
F_5 ( L_34 ) ;
goto V_86;
}
F_13 ( V_1 ) ;
V_1 -> V_73 = F_34 ( V_46 , 0 , 0 ) ;
V_1 -> V_74 = F_34 ( V_46 , 1 , 0 ) ;
if ( V_1 -> V_74 == NULL ) {
V_1 -> V_74 = F_34 ( V_46 , 2 , 0 ) ;
F_17 ( L_35 ) ;
}
if ( ! V_1 -> V_73 || ! V_1 -> V_74 ) {
V_79 = - V_85 ;
goto V_87;
}
V_53 = F_35 ( V_1 , V_88 ) ;
F_2 ( V_1 , V_88 , V_53 & ~ 0xf00 ) ;
F_1 ( V_1 , false ) ;
if ( F_36 ( V_46 , 1 , 1 ) < 1 ) {
F_5 ( L_36 ) ;
V_1 -> V_76 = false ;
V_79 = - V_85 ;
goto V_87;
}
F_20 ( V_1 , V_46 ) ;
V_1 -> V_76 = true ;
if ( F_37 ( V_46 -> V_75 , V_89 , V_90 ,
V_1 -> V_29 . V_91 , ( void * ) V_1 ) ) {
F_5 ( L_37 , V_46 -> V_75 ) ;
V_79 = - V_85 ;
goto V_92;
}
F_38 ( V_1 ) ;
return 0 ;
V_92:
F_25 ( V_46 ) ;
V_87:
F_21 ( V_1 , V_46 ) ;
F_39 ( V_46 ) ;
V_86:
F_40 ( V_1 -> V_46 ) ;
return V_79 ;
}
static int F_41 ( struct V_1 * V_1 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_93 ; V_30 ++ )
V_1 -> V_94 [ V_30 ] =
F_42 ( V_1 -> V_74 + V_95 + V_30 ) ;
V_1 -> V_94 [ V_93 - 1 ] = '\0' ;
if ( strstr ( V_1 -> V_94 , V_96 ) )
return 0 ;
return 1 ;
}
static void F_43 ( struct V_1 * V_1 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_97 ; V_30 ++ ) {
struct V_36 * V_37 = & V_1 -> V_32 [ V_30 ] ;
V_37 -> V_1 = V_1 ;
V_37 -> V_98 = 0 ;
V_37 -> V_99 = false ;
V_37 -> V_39 = false ;
V_37 -> V_100 = true ;
if ( V_30 <= V_101 ) {
V_37 -> V_102 = V_30 + V_1 -> V_103 ;
V_37 -> V_104 = V_30 ;
V_37 -> V_105 =
V_12 << ( 4 * V_30 ) ;
V_37 -> V_106 =
V_4 << ( 4 * V_30 ) ;
} else if ( V_30 >= V_107 &&
V_30 <= V_107 + 4 ) {
unsigned V_108 = V_30 - V_107 ;
V_37 -> V_102 = 6 + V_108 ;
V_37 -> V_99 = true ;
V_37 -> V_104 = V_108 ;
V_37 -> V_105 = V_16 ;
} else if ( V_30 == V_109 ) {
V_37 -> V_102 = 11 ;
V_37 -> V_39 = true ;
V_37 -> V_104 = 5 ;
V_37 -> V_105 = V_23 ;
V_37 -> V_106 = V_22 ;
} else if ( V_30 == V_110 ) {
V_37 -> V_102 = 12 ;
V_37 -> V_99 = true ;
V_37 -> V_39 = true ;
V_37 -> V_104 = 5 ;
V_37 -> V_105 = V_24 ;
} else {
V_37 -> V_102 = V_30 - V_31 ;
}
F_17 ( L_38 ,
V_30 , V_37 -> V_102 , V_37 -> V_104 ) ;
}
}
static int F_44 ( struct V_1 * V_1 )
{
static struct V_111 V_112 = {
. V_113 = 1 ,
. V_114 = V_115 ,
. V_116 = V_117 ,
. V_118 = 1 ,
. V_119 = 1 ,
. V_120 = V_121 ,
. V_122 = V_123 ,
. V_124 = V_125 ,
. V_126 = V_125 ,
. V_127 = V_125 ,
. V_128 = 1 ,
. V_129 = 1 ,
. V_130 = 1 ,
} ;
static struct V_131 V_132 = {
. type = L_39 ,
. V_133 = 0x20 ,
. V_134 = & V_112 ,
} ;
struct V_36 * V_37 = V_1 -> V_32 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_135 ; V_30 ++ ) {
struct V_136 V_137 = {
. V_138 = V_139 ,
. V_140 = V_141 ,
. V_142 . V_43 = V_143 ,
} ;
struct V_144 V_145 = {
. V_138 = V_146 ,
. V_147 = 0 ,
. V_148 = 2 ,
. V_149 = V_149 ,
} ;
int V_150 ;
V_37 [ V_30 ] . V_151 = V_139 ;
V_37 [ V_30 ] . V_152 = & V_1 -> V_152 [ V_30 ] ;
if ( V_37 [ V_30 ] . V_152 -> V_153 . V_154 == NULL )
continue;
F_7 ( V_1 ,
F_45 ( V_30 ) , 1 ) ;
V_37 [ V_30 ] . V_28 = F_46 ( & V_1 -> V_29 ,
V_37 [ V_30 ] . V_152 , & V_132 , NULL ) ;
if ( ! V_37 [ V_30 ] . V_28 ) {
if ( V_155 )
continue;
return - V_156 ;
}
V_150 = F_47 ( V_37 [ V_30 ] . V_28 , V_157 , V_158 ,
V_146 , 0 , 0 ) ;
if ( V_150 )
return V_150 ;
V_150 = F_47 ( V_37 [ V_30 ] . V_28 , V_138 , V_159 ,
& V_145 ) ;
if ( V_150 )
return V_150 ;
V_150 = F_47 ( V_37 [ V_30 ] . V_28 , V_138 , V_160 , NULL ,
& V_137 ) ;
if ( V_150 )
return V_150 ;
F_7 ( V_1 ,
F_48 ( V_30 ) , 0 ) ;
F_49 ( 2 ) ;
F_7 ( V_1 ,
F_48 ( V_30 ) , 1 ) ;
F_49 ( 1 ) ;
V_37 [ V_30 ] . V_100 = false ;
V_1 -> V_32 [ V_30 + V_107 ] . V_100 = false ;
}
return 0 ;
}
static int F_50 ( struct V_1 * V_1 )
{
static struct V_161 V_162 = {
. V_113 = 1 ,
. V_114 = V_163 ,
. V_116 = V_164 ,
. V_120 = V_165 ,
. V_118 = 1 ,
. V_119 = 1 ,
. V_124 = 3 ,
. V_126 = 3 ,
. V_127 = 3 ,
. V_166 = V_167 ,
. V_168 = 1 ,
. V_169 = V_170 ,
. V_171 = 0x4a ,
. V_172 = 0x48 ,
. V_173 = 0x22 ,
. V_174 = 0x24 ,
. V_175 = 0x26 ,
. V_176 = 0x34 ,
. V_177 = 0x32 ,
. V_178 = 0x36 ,
. V_179 = 0x3e ,
. V_180 = 0x40 ,
. V_181 = 0x42 ,
} ;
static struct V_131 V_182 = {
. type = L_40 ,
. V_133 = 0x20 ,
. V_134 = & V_162 ,
} ;
static struct V_136 V_137 = {
. V_138 = V_183 ,
. V_140 = V_141 ,
. V_142 . V_43 = V_143 ,
} ;
static struct V_184 V_185 = {
. V_178 = 0x7e >> 1 ,
. V_180 = 0x7c >> 1 ,
. V_186 = 0x70 >> 1 ,
. V_187 = 12000000 ,
} ;
static struct V_131 V_188 = {
. type = L_41 ,
. V_133 = 0x39 ,
. V_134 = & V_185 ,
} ;
struct V_144 V_145 = {
. V_138 = V_189 ,
. V_147 = 0 ,
. V_148 = 2 ,
. V_149 = V_149 ,
} ;
struct V_36 * V_37 = & V_1 -> V_32 [ V_101 ] ;
V_37 -> V_152 = & V_1 -> V_152 [ V_190 - 1 ] ;
if ( V_37 -> V_152 -> V_153 . V_154 == NULL )
return 0 ;
F_7 ( V_1 , F_45 ( 4 ) , 1 ) ;
V_37 -> V_28 = F_46 ( & V_1 -> V_29 ,
V_37 -> V_152 , & V_182 , NULL ) ;
if ( V_37 -> V_28 ) {
int V_150 = F_47 ( V_37 -> V_28 , V_138 , V_159 , & V_145 ) ;
if ( V_150 )
return V_150 ;
V_150 = F_47 ( V_37 -> V_28 , V_138 , V_160 , NULL ,
& V_137 ) ;
if ( V_150 )
return V_150 ;
V_1 -> V_17 = true ;
V_37 -> V_151 = V_183 ;
V_37 -> V_100 = false ;
V_1 -> V_32 [ 4 + V_107 ] . V_100 = false ;
F_7 ( V_1 ,
F_48 ( 4 ) , 0 ) ;
F_49 ( 2 ) ;
F_7 ( V_1 ,
F_48 ( 4 ) , 1 ) ;
F_49 ( 1 ) ;
return V_150 ;
}
F_7 ( V_1 , F_45 ( 4 ) , 0 ) ;
F_7 ( V_1 , V_191 , 0 ) ;
V_37 ++ ;
V_37 -> V_152 = & V_1 -> V_152 [ V_190 - 1 ] ;
V_37 -> V_28 = F_46 ( & V_1 -> V_29 ,
V_37 -> V_152 , & V_188 , NULL ) ;
if ( V_37 -> V_28 ) {
F_7 ( V_1 ,
V_192 , 1 ) ;
F_7 ( V_1 ,
F_48 ( 4 ) , 0 ) ;
F_7 ( V_1 ,
V_193 , 1 ) ;
V_1 -> V_21 = true ;
F_47 ( V_37 -> V_28 , V_194 , V_195 , 1 ) ;
F_47 ( V_37 -> V_28 , V_157 , V_196 , 1 ) ;
F_47 ( V_37 -> V_28 , V_197 , V_196 , 1 ) ;
F_51 ( F_52 ( V_37 -> V_28 -> V_198 ,
V_199 ) , V_200 ) ;
V_37 -> V_100 = false ;
V_1 -> V_32 [ V_110 ] . V_100 = false ;
return 0 ;
}
return - V_156 ;
}
static int F_53 ( struct V_46 * V_46 ,
const struct V_77 * V_78 )
{
struct V_1 * V_1 ;
int V_201 = 0 ;
int V_30 ;
V_30 = F_54 ( & V_202 ) - 1 ;
V_1 = F_55 ( sizeof( struct V_1 ) , V_203 ) ;
if ( V_1 == NULL )
return - V_204 ;
V_1 -> V_46 = V_46 ;
V_1 -> V_205 = V_30 ;
V_1 -> V_206 = F_56 ( & V_46 -> V_153 ) ;
if ( F_57 ( V_1 -> V_206 ) ) {
F_58 ( V_1 ) ;
return - V_204 ;
}
V_201 = F_59 ( & V_46 -> V_153 , & V_1 -> V_29 ) ;
if ( V_201 ) {
F_60 ( L_42 ,
V_1 -> V_205 ) ;
F_61 ( V_1 -> V_206 ) ;
F_58 ( V_1 ) ;
return V_201 ;
}
snprintf ( V_1 -> V_29 . V_91 , sizeof( V_1 -> V_29 . V_91 ) ,
L_43 , V_1 -> V_205 ) ;
V_1 -> V_29 . V_207 = F_6 ;
F_17 ( L_44 , V_1 -> V_205 ) ;
V_1 -> V_208 =
F_62 ( V_1 -> V_29 . V_91 ) ;
if ( V_1 -> V_208 == NULL ) {
F_5 ( L_45 ) ;
V_201 = - V_204 ;
goto V_150;
}
F_63 ( & V_1 -> V_209 , V_210 ) ;
V_201 = F_26 ( V_1 , V_46 , V_78 ) ;
if ( V_201 != 0 )
goto V_211;
if ( F_41 ( V_1 ) )
F_17 ( L_46 ) ;
else
F_17 ( L_47 , V_1 -> V_94 ) ;
V_201 = F_64 ( V_1 ) ;
if ( V_201 )
goto V_212;
F_43 ( V_1 ) ;
V_201 = F_44 ( V_1 ) ;
if ( V_201 )
goto V_213;
if ( ! ( F_35 ( V_1 , V_214 ) &
V_215 ) ) {
V_201 = F_50 ( V_1 ) ;
if ( V_201 )
goto V_213;
}
V_201 = F_65 ( & V_1 -> V_29 ) ;
if ( V_201 )
goto V_213;
V_201 = F_66 ( V_1 ) ;
if ( V_201 ) {
F_5 ( L_48 , V_201 ) ;
goto V_213;
}
F_1 ( V_1 , true ) ;
F_67 ( & V_1 -> V_29 , 0 , V_194 ,
V_216 , 0 , NULL ) ;
F_17 ( L_49 ) ;
F_68 ( V_1 ) ;
return 0 ;
V_213:
F_69 ( V_1 ) ;
F_7 ( V_1 , V_192 , 0 ) ;
V_212:
F_23 ( V_1 , V_46 ) ;
F_21 ( V_1 , V_46 ) ;
F_39 ( V_1 -> V_46 ) ;
F_40 ( V_1 -> V_46 ) ;
V_211:
F_70 ( V_1 -> V_208 ) ;
V_150:
if ( V_201 == 0 )
V_201 = - V_156 ;
F_5 ( L_50 , V_201 ) ;
F_71 ( & V_1 -> V_29 ) ;
F_61 ( V_1 -> V_206 ) ;
F_58 ( V_1 ) ;
return V_201 ;
}
static void F_72 ( struct V_46 * V_46 )
{
struct V_217 * V_29 = F_73 ( V_46 ) ;
struct V_1 * V_1 = F_4 ( V_29 ) ;
int V_30 ;
F_74 ( V_1 ) ;
F_1 ( V_1 , false ) ;
F_75 ( V_1 -> V_208 ) ;
F_76 ( V_1 ) ;
for ( V_30 = 0 ; V_30 < V_190 ; V_30 ++ ) {
struct V_27 * V_28 = V_1 -> V_32 [ V_30 ] . V_28 ;
struct V_218 * V_219 ;
if ( V_28 == NULL )
continue;
V_219 = F_77 ( V_28 ) ;
F_78 ( V_28 ) ;
F_79 ( V_219 ) ;
}
F_69 ( V_1 ) ;
F_23 ( V_1 , V_46 ) ;
F_7 ( V_1 , V_192 , 0 ) ;
F_21 ( V_1 , V_46 ) ;
F_39 ( V_1 -> V_46 ) ;
F_40 ( V_1 -> V_46 ) ;
F_70 ( V_1 -> V_208 ) ;
F_17 ( L_51 ) ;
F_71 ( V_29 ) ;
F_61 ( V_1 -> V_206 ) ;
F_58 ( V_1 ) ;
}
