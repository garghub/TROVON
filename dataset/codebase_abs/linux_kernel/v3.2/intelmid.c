static int F_1 ( struct V_1 * V_2 ,
int V_3 )
{
int V_4 = 0 , V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
F_2 ( ! V_2 ) ;
V_7 = F_3 ( V_2 ) ;
V_9 = V_2 -> V_12 -> V_13 ;
F_2 ( ! V_7 -> V_14 ) ;
F_2 ( ! V_7 -> V_14 -> V_15 ) ;
V_11 = V_7 -> V_14 -> V_16 ;
V_5 = V_9 -> V_17 . V_5 ;
switch ( V_3 ) {
case V_18 :
F_4 ( L_1 ) ;
V_4 = V_11 -> V_19 ( V_20 , & V_5 ) ;
if ( V_4 )
return V_4 ;
V_9 -> V_21 = V_22 ;
V_9 -> V_2 = V_2 ;
break;
case V_23 :
F_4 ( L_2 ) ;
V_4 = V_11 -> V_19 ( V_24 , & V_5 ) ;
if ( V_4 )
return V_4 ;
V_9 -> V_21 = V_25 ;
break;
case V_26 :
F_4 ( L_3 ) ;
V_4 = V_11 -> V_19 ( V_27 , & V_5 ) ;
if ( V_4 )
return V_4 ;
V_9 -> V_21 = V_28 ;
break;
case V_29 :
F_4 ( L_4 ) ;
V_4 = V_11 -> V_19 ( V_30 , & V_5 ) ;
if ( V_4 )
return V_4 ;
V_9 -> V_21 = V_22 ;
break;
default:
return - V_31 ;
}
return V_4 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
int V_4 = 0 ;
struct V_6 * V_7 ;
F_4 ( L_5 ) ;
F_2 ( ! V_2 ) ;
V_9 = V_2 -> V_12 -> V_13 ;
V_7 = F_3 ( V_2 ) ;
F_4 ( L_6 ,\
V_7 -> V_32 ,
V_7 -> V_33 ) ;
if ( V_9 -> V_17 . V_5 ) {
F_4 ( L_7 ) ;
V_4 = V_7 -> V_14 -> V_16 -> V_19 (
V_24 , & V_9 -> V_17 . V_5 ) ;
return V_4 ;
}
V_4 = F_6 ( V_2 ) ;
if ( V_4 < 0 )
return V_4 ;
V_9 -> V_34 = 0 ;
if ( V_2 -> V_9 == V_35 )
V_7 -> V_32 ++ ;
else
V_7 -> V_33 ++ ;
snprintf ( V_2 -> V_36 -> V_37 , sizeof( V_2 -> V_36 -> V_37 ) ,
L_8 , V_9 -> V_17 . V_5 ) ;
F_4 ( L_9 ,
V_2 -> V_36 -> V_37 ) ;
V_4 = F_7 ( V_2 ) ;
if ( V_4 )
return V_4 ;
V_2 -> V_12 -> V_38 . V_39 = V_40 ;
return V_4 ;
}
static int F_8 ( struct V_1 * V_2 ,
struct V_41 * V_42 )
{
int V_4 ;
F_4 ( L_10 ) ;
V_4 = F_9 ( V_2 ,
F_10 ( V_42 ) ) ;
memset ( V_2 -> V_12 -> V_43 , 0 ,
F_10 ( V_42 ) ) ;
return V_4 ;
}
static int F_11 ( struct V_1 * V_2 )
{
F_4 ( L_11 ) ;
return F_12 ( V_2 ) ;
}
static T_1 F_13
( struct V_1 * V_2 )
{
struct V_8 * V_9 ;
struct V_6 * V_7 ;
int V_4 ;
F_2 ( ! V_2 ) ;
V_7 = F_3 ( V_2 ) ;
V_9 = V_2 -> V_12 -> V_13 ;
if ( V_9 -> V_21 == V_44 )
return 0 ;
V_4 = V_7 -> V_14 -> V_16 -> V_19 (
V_45 , & V_9 -> V_17 ) ;
if ( V_4 ) {
F_14 ( L_12 , V_4 ) ;
return V_4 ;
}
F_4 ( L_13 ,
V_9 -> V_17 . V_46 ) ;
F_4 ( L_14 ,
( int ) V_2 -> V_12 -> V_47 ,
( int ) V_2 -> V_12 -> V_48 ) ;
return V_9 -> V_17 . V_46 ;
}
static int F_15 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
struct V_8 * V_9 ;
int V_4 = 0 , V_5 ;
F_2 ( ! V_2 ) ;
V_9 = V_2 -> V_12 -> V_13 ;
V_5 = V_9 -> V_17 . V_5 ;
F_4 ( L_15 , V_5 ) ;
V_7 = F_3 ( V_2 ) ;
F_4 ( L_16 , V_9 -> V_17 . V_5 ) ;
if ( V_9 -> V_17 . V_5 ) {
V_4 = V_7 -> V_14 -> V_16 -> V_49 ( V_5 ) ;
if ( V_2 -> V_9 == V_35 )
V_7 -> V_32 -- ;
else
V_7 -> V_33 -- ;
}
F_4 ( L_17 ,
V_7 -> V_32 , V_7 -> V_33 ) ;
F_16 ( V_2 -> V_12 -> V_13 ) ;
return V_4 ;
}
static int F_17 ( struct V_1 * V_2 ,
enum V_50 type )
{
struct V_6 * V_7 ;
struct V_51 * V_12 ;
struct V_8 * V_9 ;
F_2 ( ! V_2 ) ;
F_4 ( L_18 ) ;
V_7 = F_3 ( V_2 ) ;
V_12 = V_2 -> V_12 ;
V_12 -> V_38 = V_52 ;
if ( V_7 -> V_53 == V_54 ) {
if ( V_2 -> V_9 == V_55 ) {
V_12 -> V_38 . V_56 = ( V_57 |
V_58 ) ;
V_12 -> V_38 . V_59 = 1 ;
}
}
if ( V_7 -> V_53 == V_60 ) {
V_12 -> V_38 = V_52 ;
V_12 -> V_38 . V_61 = V_62 ;
V_12 -> V_38 . V_63 = V_64 ;
V_12 -> V_38 . V_56 = ( V_65 |
V_66 ) ;
if ( V_7 -> V_14 -> V_15 -> V_67 == V_68 )
V_12 -> V_38 . V_59 = V_69 ;
else
V_12 -> V_38 . V_59 = V_70 ;
}
V_9 = F_18 ( sizeof( * V_9 ) , V_71 ) ;
if ( ! V_9 )
return - V_72 ;
V_9 -> V_17 . V_5 = 0 ;
V_9 -> V_73 = type ;
V_9 -> V_21 = V_44 ;
V_12 -> V_13 = V_9 ;
return F_19 ( V_12 ,
V_74 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_75 ) ;
}
static int F_21 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_76 ) ;
}
static int F_22 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_77 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
return F_17 ( V_2 , V_78 ) ;
}
int F_24 ( void )
{
struct V_79 * V_80 ;
if ( ! V_81 || ! V_81 -> V_14 )
return - V_82 ;
V_80 = V_81 -> V_14 -> V_15 ;
if ( V_80 && V_80 -> V_83 )
return V_80 -> V_83 ( V_81 ) ;
else
return - V_82 ;
}
int F_25 ( int V_84 )
{
struct V_79 * V_80 ;
if ( ! V_81 || ! V_81 -> V_14 )
return - V_82 ;
V_80 = V_81 -> V_14 -> V_15 ;
if ( V_80 && V_80 -> V_85 )
return V_80 -> V_85 ( V_84 ) ;
else
return - V_82 ;
}
void F_26 ( struct V_86 * V_87 )
{
T_2 V_88 ;
struct V_89 * V_90 =
F_27 ( V_87 , struct V_89 , V_91 ) ;
struct V_6 * V_7 =
V_90 -> V_7 ;
if ( ! V_7 )
return;
V_88 = V_90 -> V_92 ;
if ( V_7 -> V_14 && V_7 -> V_14 -> V_15
&& V_7 -> V_14 -> V_15 -> V_93 ) {
V_7 -> V_14 -> V_15 -> V_93 (
( void * ) V_7 , V_88 ) ;
V_7 -> V_14 -> V_15 -> V_94 () ;
}
F_16 ( V_90 ) ;
}
static T_3 F_28 ( int V_95 , void * V_96 )
{
struct V_6 * V_7 =
(struct V_6 * ) V_96 ;
T_2 V_88 ;
struct V_89 * V_97 ;
F_29 ( & V_88 ,
( ( void * ) ( V_7 -> V_98 ) ) ,
sizeof( T_2 ) ) ;
V_97 = F_18 ( sizeof( * V_97 ) , V_99 ) ;
V_97 -> V_92 = V_88 ;
V_97 -> V_7 = V_7 ;
F_30 ( & V_97 -> V_91 , F_26 ) ;
F_31 ( V_7 -> V_100 , & V_97 -> V_91 ) ;
return V_101 ;
}
void F_32 ( struct V_102 * V_103 ,
int V_104 , int V_105 )
{
if ( ! V_103 ) {
F_4 ( L_19 ) ;
} else {
F_33 ( V_103 , V_105 ) ;
if ( V_104 )
F_33 ( V_103 , 0 ) ;
F_4 ( L_20 ) ;
}
}
static int T_4 F_34 (
struct V_6 * V_7 , unsigned int V_106 ,
unsigned int V_107 )
{
int V_4 ;
char * V_108 ;
F_4 ( L_21 ,
V_106 , V_107 ) ;
V_7 -> V_98 = F_35 ( V_106 , V_107 ) ;
if ( ! V_7 -> V_98 )
F_14 ( L_22 ) ;
F_4 ( L_23 , V_7 -> V_95 ) ;
if ( V_7 -> V_53 == V_60 )
V_108 = V_109 ;
else
V_108 = V_110 ;
V_4 = F_36 ( V_7 -> V_95 ,
F_28 ,
V_111 , V_108 ,
V_7 ) ;
if ( V_4 )
F_14 ( L_24 ) ;
return V_4 ;
}
static int T_4 F_37 (
struct V_6 * V_7 )
{
int V_4 = 0 ;
struct V_79 * V_112 [ V_113 ] = {
& V_114 ,
& V_115 ,
& V_116 ,
& V_117
} ;
struct V_118 V_119 = { 0x00 , 0x00 , 0x00 } ;
if ( V_7 -> V_53 == V_54 ) {
V_4 = F_38 ( & V_119 , V_120 , 1 ) ;
if ( V_4 )
return V_4 ;
V_121 = ( V_119 . V_122 & ( V_123 | V_124 | V_125 ) ) ;
F_4 ( L_25 ,
V_119 . V_122 , V_121 ) ;
if ( V_121 < 0 || V_121 > 2 ) {
F_14 ( L_26 ) ;
return - V_126 ;
}
} else
V_121 = 0x3 ;
V_7 -> V_14 -> V_127 = V_128 ;
V_7 -> V_14 -> V_129 = V_121 ;
F_39 ( ! V_112 [ V_121 ] ) ;
V_7 -> V_14 -> V_15 =
V_112 [ V_121 ] ;
if ( V_7 -> V_53 == V_60 ) {
V_7 -> V_14 -> V_15 -> V_130 = 0 ;
V_7 -> V_14 -> V_15 -> V_131 = 0 ;
V_7 -> V_14 -> V_15 -> V_67 = V_132 ;
V_7 -> V_14 -> V_15 -> V_133 =
V_134 ;
V_7 -> V_14 -> V_15 -> V_135 = V_136 ;
}
V_4 = F_40 ( V_7 -> V_14 ) ;
if ( V_4 ) {
F_14 ( L_27 ) ;
return V_4 ;
}
V_121 = V_7 -> V_14 -> V_129 ;
V_7 -> V_137 = V_138 ;
return V_4 ;
}
static void F_41 ( struct V_139 * V_36 )
{
F_42 ( V_36 ) ;
}
static int T_4 F_43 ( struct V_140 * V_141 ,
struct V_6 * V_7 ,
unsigned int V_142 , unsigned int V_143 , unsigned int V_144 )
{
int V_4 = 0 ;
struct V_139 * V_36 ;
char V_145 [ 32 ] = V_146 ;
struct V_147 * V_148 = NULL , * V_149 = NULL ;
F_4 ( L_28 , V_142 , V_143 , V_144 ) ;
V_4 = F_44 ( V_141 , V_145 , V_144 , V_142 , V_143 , & V_36 ) ;
if ( V_4 )
return V_4 ;
switch ( V_144 ) {
case 0 :
V_148 = & V_150 ;
V_149 = & V_151 ;
break;
case 1 :
V_148 = & V_152 ;
V_149 = & V_151 ;
break;
case 2 :
V_148 = & V_153 ;
V_149 = & V_151 ;
break;
case 3 :
V_148 = & V_154 ;
V_149 = & V_151 ;
break;
}
if ( V_142 )
F_45 ( V_36 , V_35 , V_148 ) ;
if ( V_143 )
F_45 ( V_36 , V_55 , V_149 ) ;
V_36 -> V_13 = V_7 ;
V_36 -> V_155 = F_41 ;
V_36 -> V_156 = 0 ;
strncpy ( V_36 -> V_145 , V_141 -> V_157 , strlen ( V_141 -> V_157 ) ) ;
F_46 ( V_36 ,
V_158 ,
F_47 ( V_71 ) ,
V_159 , V_160 ) ;
return V_4 ;
}
static int T_4 F_48 ( struct V_140 * V_141 ,
struct V_6 * V_7 )
{
int V_4 = 0 ;
F_2 ( ! V_141 ) ;
F_2 ( ! V_7 ) ;
F_4 ( L_29 ) ;
V_4 = F_43 ( V_141 , V_7 , 1 , 1 , 0 ) ;
if ( V_7 -> V_53 == V_54 )
return V_4 ;
V_4 = F_43 ( V_141 , V_7 , 1 , 0 , 1 ) ;
if ( V_4 )
return V_4 ;
V_4 = F_43 ( V_141 , V_7 , 1 , 0 , 2 ) ;
if ( V_4 )
return V_4 ;
return F_43 ( V_141 , V_7 , 1 , 0 , 3 ) ;
}
static int F_49 ( struct V_6 * V_7 )
{
struct V_102 * V_103 ;
int V_161 ;
F_4 ( L_30 ) ;
V_103 = & V_7 -> V_103 [ 0 ] . V_103 ;
F_50 ( V_103 , V_162 , V_163 ) ;
V_161 = F_51 ( V_7 -> V_141 , L_31 ,
V_164 | V_165 |
V_166 | V_162
| V_167 , & V_103 ) ;
F_4 ( L_30 ) ;
if ( V_161 < 0 )
return V_161 ;
F_33 ( V_103 , 0 ) ;
V_103 -> V_13 = V_103 ;
V_7 -> V_103 [ 0 ] . V_103 = * V_103 ;
return V_161 ;
}
static int T_4 F_52 ( struct V_6 * V_7 )
{
struct V_140 * V_141 ;
unsigned int V_168 ;
int V_4 = 0 , V_169 = 0 ;
char * V_170 = L_32 ;
struct V_171 * V_172 ;
F_2 ( ! V_7 ) ;
V_141 = V_7 -> V_141 ;
strncpy ( V_141 -> V_170 , V_170 , sizeof( V_141 -> V_170 ) - 1 ) ;
if ( V_7 -> V_53 == V_60 ) {
V_169 = V_173 ;
V_172 = V_174 ;
} else {
V_169 = V_175 ;
V_172 = V_176 ;
}
for ( V_168 = 0 ; V_168 < V_169 ; V_168 ++ ) {
V_4 = F_53 ( V_141 ,
F_54 ( & V_172 [ V_168 ] ,
V_7 ) ) ;
F_4 ( L_33 , V_168 ) ;
if ( V_4 ) {
F_14 ( L_34 , V_168 ) ;
break;
}
}
return V_4 ;
}
static int F_55 ( struct V_177 * V_73 )
{
struct V_6 * V_7 ;
F_2 ( ! V_73 ) ;
V_7 = V_73 -> V_178 ;
F_4 ( L_35 ) ;
F_56 ( V_7 -> V_14 ) ;
F_57 ( V_7 -> V_100 ) ;
V_73 -> V_178 = NULL ;
F_16 ( V_7 -> V_14 ) ;
F_16 ( V_7 ) ;
return 0 ;
}
static int T_4 F_58 (
struct V_6 * V_7 ,
struct V_140 * V_141 )
{
int V_4 ;
static struct V_179 V_180 = {
. V_181 = F_55 ,
} ;
F_2 ( ! V_7 ) ;
F_2 ( ! V_141 ) ;
V_4 = F_59 ( V_141 , V_182 , V_7 , & V_180 ) ;
return V_4 ;
}
int T_4 F_60 ( struct V_183 * V_184 )
{
struct V_140 * V_141 ;
int V_4 ;
struct V_6 * V_7 ;
const struct V_185 * V_37 = F_61 ( V_184 ) ;
struct V_186 * V_39 = ( void * ) V_37 -> V_187 ;
F_4 ( L_36 , V_184 -> V_145 , V_39 -> V_53 ) ;
F_4 ( L_37 , V_39 -> V_188 , V_39 -> V_189 ) ;
if ( ! strcmp ( V_184 -> V_145 , V_110 ) )
F_4 ( L_38 ) ;
else if ( ! strcmp ( V_184 -> V_145 , V_109 ) )
F_4 ( L_39 ) ;
else {
F_14 ( L_40 ) ;
return - V_126 ;
}
if ( ( V_39 -> V_53 < V_54 ) ||
( V_39 -> V_53 > V_60 ) ) {
F_14 ( L_41 ) ;
return - V_126 ;
}
V_7 = F_18 ( sizeof( * V_7 ) , V_71 ) ;
if ( ! V_7 ) {
F_4 ( L_42 ) ;
return - V_72 ;
}
V_81 = V_7 ;
V_7 -> V_14 = F_18 ( sizeof( struct V_190 ) ,
V_71 ) ;
if ( ! V_7 -> V_14 ) {
F_14 ( L_43 ) ;
F_16 ( V_7 ) ;
return - V_72 ;
}
V_7 -> V_53 = V_39 -> V_53 ;
V_4 = F_62 ( V_191 , V_192 , V_193 , 0 , & V_141 ) ;
if ( V_4 ) {
F_14 ( L_44 ) ;
goto V_194;
}
V_7 -> V_184 = V_184 ;
V_7 -> V_95 = F_63 ( V_184 , 0 ) ;
F_64 ( V_184 , V_7 ) ;
V_7 -> V_141 = V_141 ;
V_7 -> V_192 = V_192 ;
V_7 -> V_191 = V_191 ;
V_7 -> V_195 = V_196 ;
V_7 -> V_32 = V_7 -> V_33 = 0 ;
strncpy ( V_141 -> V_197 , V_146 , strlen ( V_146 ) ) ;
strncpy ( V_141 -> V_157 , V_146 , strlen ( V_146 ) ) ;
V_7 -> V_14 -> V_127 = V_128 ;
V_4 = F_37 ( V_7 ) ;
if ( V_4 ) {
F_14 ( L_45 ) ;
goto V_198;
}
V_7 -> V_137 = V_199 ;
V_4 = F_48 ( V_141 , V_7 ) ;
if ( V_4 ) {
F_14 ( L_46 ) ;
goto V_200;
}
V_4 = F_52 ( V_7 ) ;
if ( V_4 ) {
F_14 ( L_47 ) ;
goto V_201;
}
V_4 = F_49 ( V_7 ) ;
if ( V_4 ) {
F_14 ( L_48 ) ;
goto V_201;
}
V_7 -> V_202 = F_65 () ;
F_30 ( & V_7 -> V_97 . V_91 ,
F_26 ) ;
V_7 -> V_100 = F_66 ( L_49 ) ;
if ( ! V_7 -> V_100 )
goto V_201;
V_4 = F_34 ( V_7 ,
V_39 -> V_188 , V_39 -> V_189 ) ;
if ( V_4 ) {
F_14 ( L_50 ) ;
goto V_203;
}
V_4 = F_58 ( V_7 , V_141 ) ;
if ( V_4 ) {
F_14 ( L_51 ) ;
goto V_204;
}
V_141 -> V_13 = & V_7 ;
F_67 ( V_141 , & V_184 -> V_96 ) ;
V_4 = F_68 ( V_141 ) ;
if ( V_4 ) {
F_14 ( L_52 ) ;
goto V_204;
}
if ( V_184 -> V_96 . V_205 ) {
int V_206 = * ( int * ) V_184 -> V_96 . V_205 ;
if ( F_69 ( V_206 , V_207 , L_53 ) )
V_206 = 0 ;
V_7 -> V_14 -> V_15 -> V_206 = V_206 ;
}
F_4 ( L_54 ) ;
return V_4 ;
V_204:
V_141 -> V_13 = NULL ;
V_203:
F_57 ( V_7 -> V_100 ) ;
V_201:
F_70 ( V_7 -> V_141 ) ;
V_200:
F_56 ( V_7 -> V_14 ) ;
V_198:
F_64 ( V_184 , NULL ) ;
V_194:
F_14 ( L_55 ) ;
F_70 ( V_141 ) ;
F_16 ( V_7 -> V_14 ) ;
F_16 ( V_7 ) ;
return V_4 ;
}
static int F_71 ( struct V_183 * V_184 )
{
struct V_6 * V_7 = F_72 ( V_184 ) ;
if ( V_7 ) {
if ( V_7 -> V_14 -> V_15 -> V_206 )
F_73 ( V_7 -> V_14 -> V_15 -> V_206 ) ;
F_74 ( V_7 -> V_95 , V_7 ) ;
F_70 ( V_7 -> V_141 ) ;
}
V_81 = NULL ;
F_64 ( V_184 , NULL ) ;
return 0 ;
}
static int T_5 F_75 ( void )
{
F_4 ( L_56 ) ;
return F_76 ( & V_208 ) ;
}
static void T_6 F_77 ( void )
{
F_4 ( L_57 ) ;
return F_78 ( & V_208 ) ;
}
