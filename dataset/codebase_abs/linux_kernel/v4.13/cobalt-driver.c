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
if ( ! V_50 || ! V_51 )
return;
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
F_25 ( V_46 ) ;
}
static int F_26 ( struct V_1 * V_1 , struct V_46 * V_46 ,
const struct V_76 * V_77 )
{
T_2 V_53 ;
int V_78 ;
F_9 ( 1 , L_25 ) ;
V_78 = F_27 ( V_46 ) ;
if ( V_78 ) {
F_5 ( L_26 ) ;
return V_78 ;
}
F_28 ( V_46 ) ;
F_29 ( V_46 , V_79 , & V_1 -> V_80 ) ;
F_16 ( V_46 , V_81 , & V_1 -> V_82 ) ;
switch ( V_1 -> V_82 ) {
case V_83 :
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
V_78 = - V_84 ;
goto V_85;
}
}
if ( F_31 ( V_46 , F_32 ( 64 ) ) ) {
V_78 = F_31 ( V_46 , F_32 ( 32 ) ) ;
if ( V_78 ) {
F_5 ( L_32 ) ;
goto V_85;
}
}
V_78 = F_33 ( V_46 , L_33 ) ;
if ( V_78 ) {
F_5 ( L_34 ) ;
goto V_85;
}
F_13 ( V_1 ) ;
V_1 -> V_73 = F_34 ( V_46 , 0 , 0 ) ;
V_1 -> V_74 = F_34 ( V_46 , 1 , 0 ) ;
if ( V_1 -> V_74 == NULL ) {
V_1 -> V_74 = F_34 ( V_46 , 2 , 0 ) ;
F_17 ( L_35 ) ;
}
if ( ! V_1 -> V_73 || ! V_1 -> V_74 ) {
V_78 = - V_84 ;
goto V_86;
}
V_53 = F_35 ( V_1 , V_87 ) ;
F_2 ( V_1 , V_87 , V_53 & ~ 0xf00 ) ;
F_1 ( V_1 , false ) ;
if ( F_36 ( V_46 , 1 , 1 , V_88 ) < 1 ) {
F_5 ( L_36 ) ;
V_78 = - V_84 ;
goto V_86;
}
F_20 ( V_1 , V_46 ) ;
if ( F_37 ( V_46 -> V_75 , V_89 , V_90 ,
V_1 -> V_29 . V_91 , ( void * ) V_1 ) ) {
F_5 ( L_37 , V_46 -> V_75 ) ;
V_78 = - V_84 ;
goto V_92;
}
F_38 ( V_1 ) ;
return 0 ;
V_92:
F_39 ( V_46 ) ;
V_86:
F_21 ( V_1 , V_46 ) ;
F_40 ( V_46 ) ;
V_85:
F_41 ( V_1 -> V_46 ) ;
return V_78 ;
}
static int F_42 ( struct V_1 * V_1 )
{
int V_30 ;
for ( V_30 = 0 ; V_30 < V_93 ; V_30 ++ )
V_1 -> V_94 [ V_30 ] =
F_43 ( V_1 -> V_74 + V_95 + V_30 ) ;
V_1 -> V_94 [ V_93 - 1 ] = '\0' ;
if ( strstr ( V_1 -> V_94 , V_96 ) )
return 0 ;
return 1 ;
}
static void F_44 ( struct V_1 * V_1 )
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
static int F_45 ( struct V_1 * V_1 )
{
static struct V_111 V_112 = {
. V_113 = 1 ,
. V_114 = V_115 ,
. V_116 = V_117 ,
. V_118 = 1 ,
. V_119 = V_120 ,
. V_121 = V_122 ,
. V_123 = V_124 ,
. V_125 = V_124 ,
. V_126 = V_124 ,
. V_127 = 1 ,
. V_128 = 1 ,
. V_129 = 1 ,
} ;
static struct V_130 V_131 = {
. type = L_39 ,
. V_132 = 0x20 ,
. V_133 = & V_112 ,
} ;
struct V_36 * V_37 = V_1 -> V_32 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < V_134 ; V_30 ++ ) {
struct V_135 V_136 = {
. V_137 = V_138 ,
. V_139 = V_140 ,
. V_141 . V_43 = V_142 ,
} ;
struct V_143 V_144 = {
. V_137 = V_145 ,
. V_146 = 0 ,
. V_147 = 2 ,
. V_148 = V_148 ,
} ;
int V_149 ;
V_37 [ V_30 ] . V_150 = V_138 ;
V_37 [ V_30 ] . V_151 = & V_1 -> V_151 [ V_30 ] ;
if ( V_37 [ V_30 ] . V_151 -> V_152 . V_153 == NULL )
continue;
F_7 ( V_1 ,
F_46 ( V_30 ) , 1 ) ;
V_37 [ V_30 ] . V_28 = F_47 ( & V_1 -> V_29 ,
V_37 [ V_30 ] . V_151 , & V_131 , NULL ) ;
if ( ! V_37 [ V_30 ] . V_28 ) {
if ( V_154 )
continue;
return - V_155 ;
}
V_149 = F_48 ( V_37 [ V_30 ] . V_28 , V_156 , V_157 ,
V_145 , 0 , 0 ) ;
if ( V_149 )
return V_149 ;
V_149 = F_48 ( V_37 [ V_30 ] . V_28 , V_137 , V_158 ,
& V_144 ) ;
if ( V_149 )
return V_149 ;
V_149 = F_48 ( V_37 [ V_30 ] . V_28 , V_137 , V_159 , NULL ,
& V_136 ) ;
if ( V_149 )
return V_149 ;
F_7 ( V_1 ,
F_49 ( V_30 ) , 0 ) ;
F_50 ( 2 ) ;
F_7 ( V_1 ,
F_49 ( V_30 ) , 1 ) ;
F_50 ( 1 ) ;
V_37 [ V_30 ] . V_100 = false ;
V_1 -> V_32 [ V_30 + V_107 ] . V_100 = false ;
}
return 0 ;
}
static int F_51 ( struct V_1 * V_1 )
{
static struct V_160 V_161 = {
. V_113 = 1 ,
. V_114 = V_162 ,
. V_116 = V_163 ,
. V_119 = V_164 ,
. V_118 = 1 ,
. V_123 = 3 ,
. V_125 = 3 ,
. V_126 = 3 ,
. V_165 = V_166 ,
. V_167 = 1 ,
. V_168 = V_169 ,
. V_170 = 0x4a ,
. V_171 = 0x48 ,
. V_172 = 0x22 ,
. V_173 = 0x24 ,
. V_174 = 0x26 ,
. V_175 = 0x34 ,
. V_176 = 0x32 ,
. V_177 = 0x36 ,
. V_178 = 0x3e ,
. V_179 = 0x40 ,
. V_180 = 0x42 ,
} ;
static struct V_130 V_181 = {
. type = L_40 ,
. V_132 = 0x20 ,
. V_133 = & V_161 ,
} ;
static struct V_135 V_136 = {
. V_137 = V_182 ,
. V_139 = V_140 ,
. V_141 . V_43 = V_142 ,
} ;
static struct V_183 V_184 = {
. V_177 = 0x7e >> 1 ,
. V_179 = 0x7c >> 1 ,
. V_185 = 0x70 >> 1 ,
. V_186 = 12000000 ,
} ;
static struct V_130 V_187 = {
. type = L_41 ,
. V_132 = 0x39 ,
. V_133 = & V_184 ,
} ;
struct V_143 V_144 = {
. V_137 = V_188 ,
. V_146 = 0 ,
. V_147 = 2 ,
. V_148 = V_148 ,
} ;
struct V_36 * V_37 = & V_1 -> V_32 [ V_101 ] ;
V_37 -> V_151 = & V_1 -> V_151 [ V_189 - 1 ] ;
if ( V_37 -> V_151 -> V_152 . V_153 == NULL )
return 0 ;
F_7 ( V_1 , F_46 ( 4 ) , 1 ) ;
V_37 -> V_28 = F_47 ( & V_1 -> V_29 ,
V_37 -> V_151 , & V_181 , NULL ) ;
if ( V_37 -> V_28 ) {
int V_149 = F_48 ( V_37 -> V_28 , V_137 , V_158 , & V_144 ) ;
if ( V_149 )
return V_149 ;
V_149 = F_48 ( V_37 -> V_28 , V_137 , V_159 , NULL ,
& V_136 ) ;
if ( V_149 )
return V_149 ;
V_1 -> V_17 = true ;
V_37 -> V_150 = V_182 ;
V_37 -> V_100 = false ;
V_1 -> V_32 [ 4 + V_107 ] . V_100 = false ;
F_7 ( V_1 ,
F_49 ( 4 ) , 0 ) ;
F_50 ( 2 ) ;
F_7 ( V_1 ,
F_49 ( 4 ) , 1 ) ;
F_50 ( 1 ) ;
return V_149 ;
}
F_7 ( V_1 , F_46 ( 4 ) , 0 ) ;
F_7 ( V_1 , V_190 , 0 ) ;
V_37 ++ ;
V_37 -> V_151 = & V_1 -> V_151 [ V_189 - 1 ] ;
V_37 -> V_28 = F_47 ( & V_1 -> V_29 ,
V_37 -> V_151 , & V_187 , NULL ) ;
if ( V_37 -> V_28 ) {
F_7 ( V_1 ,
V_191 , 1 ) ;
F_7 ( V_1 ,
F_49 ( 4 ) , 0 ) ;
F_7 ( V_1 ,
V_192 , 1 ) ;
V_1 -> V_21 = true ;
F_48 ( V_37 -> V_28 , V_193 , V_194 , 1 ) ;
F_48 ( V_37 -> V_28 , V_156 , V_195 , 1 ) ;
F_48 ( V_37 -> V_28 , V_196 , V_195 , 1 ) ;
F_52 ( F_53 ( V_37 -> V_28 -> V_197 ,
V_198 ) , V_199 ) ;
V_37 -> V_100 = false ;
V_1 -> V_32 [ V_110 ] . V_100 = false ;
return 0 ;
}
return - V_155 ;
}
static int F_54 ( struct V_46 * V_46 ,
const struct V_76 * V_77 )
{
struct V_1 * V_1 ;
int V_200 = 0 ;
int V_30 ;
V_30 = F_55 ( & V_201 ) - 1 ;
V_1 = F_56 ( sizeof( struct V_1 ) , V_202 ) ;
if ( V_1 == NULL )
return - V_203 ;
V_1 -> V_46 = V_46 ;
V_1 -> V_204 = V_30 ;
V_200 = F_57 ( & V_46 -> V_152 , & V_1 -> V_29 ) ;
if ( V_200 ) {
F_58 ( L_42 ,
V_1 -> V_204 ) ;
F_59 ( V_1 ) ;
return V_200 ;
}
snprintf ( V_1 -> V_29 . V_91 , sizeof( V_1 -> V_29 . V_91 ) ,
L_43 , V_1 -> V_204 ) ;
V_1 -> V_29 . V_205 = F_6 ;
F_17 ( L_44 , V_1 -> V_204 ) ;
V_1 -> V_206 =
F_60 ( V_1 -> V_29 . V_91 ) ;
if ( V_1 -> V_206 == NULL ) {
F_5 ( L_45 ) ;
V_200 = - V_203 ;
goto V_149;
}
F_61 ( & V_1 -> V_207 , V_208 ) ;
V_200 = F_26 ( V_1 , V_46 , V_77 ) ;
if ( V_200 != 0 )
goto V_209;
if ( F_42 ( V_1 ) )
F_17 ( L_46 ) ;
else
F_17 ( L_47 , V_1 -> V_94 ) ;
V_200 = F_62 ( V_1 ) ;
if ( V_200 )
goto V_210;
F_44 ( V_1 ) ;
V_200 = F_45 ( V_1 ) ;
if ( V_200 )
goto V_211;
if ( ! ( F_35 ( V_1 , V_212 ) &
V_213 ) ) {
V_200 = F_51 ( V_1 ) ;
if ( V_200 )
goto V_211;
}
V_200 = F_63 ( & V_1 -> V_29 ) ;
if ( V_200 )
goto V_211;
V_200 = F_64 ( V_1 ) ;
if ( V_200 ) {
F_5 ( L_48 , V_200 ) ;
goto V_211;
}
F_1 ( V_1 , true ) ;
F_65 ( & V_1 -> V_29 , 0 , V_193 ,
V_214 , 0 , NULL ) ;
F_17 ( L_49 ) ;
F_66 ( V_1 ) ;
return 0 ;
V_211:
F_67 ( V_1 ) ;
F_7 ( V_1 , V_191 , 0 ) ;
V_210:
F_23 ( V_1 , V_46 ) ;
F_21 ( V_1 , V_46 ) ;
F_40 ( V_1 -> V_46 ) ;
F_41 ( V_1 -> V_46 ) ;
V_209:
F_68 ( V_1 -> V_206 ) ;
V_149:
if ( V_200 == 0 )
V_200 = - V_155 ;
F_5 ( L_50 , V_200 ) ;
F_69 ( & V_1 -> V_29 ) ;
F_59 ( V_1 ) ;
return V_200 ;
}
static void F_70 ( struct V_46 * V_46 )
{
struct V_215 * V_29 = F_71 ( V_46 ) ;
struct V_1 * V_1 = F_4 ( V_29 ) ;
int V_30 ;
F_72 ( V_1 ) ;
F_1 ( V_1 , false ) ;
F_73 ( V_1 -> V_206 ) ;
F_74 ( V_1 ) ;
for ( V_30 = 0 ; V_30 < V_189 ; V_30 ++ ) {
struct V_27 * V_28 = V_1 -> V_32 [ V_30 ] . V_28 ;
struct V_216 * V_217 ;
if ( V_28 == NULL )
continue;
V_217 = F_75 ( V_28 ) ;
F_76 ( V_28 ) ;
F_77 ( V_217 ) ;
}
F_67 ( V_1 ) ;
F_23 ( V_1 , V_46 ) ;
F_7 ( V_1 , V_191 , 0 ) ;
F_21 ( V_1 , V_46 ) ;
F_40 ( V_1 -> V_46 ) ;
F_41 ( V_1 -> V_46 ) ;
F_68 ( V_1 -> V_206 ) ;
F_17 ( L_51 ) ;
F_69 ( V_29 ) ;
F_59 ( V_1 ) ;
}
