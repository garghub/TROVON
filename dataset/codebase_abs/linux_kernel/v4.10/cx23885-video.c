static struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_2 )
return V_4 + V_3 ;
return NULL ;
}
void F_3 ( struct V_5 * V_6 ,
struct V_7 * V_8 , T_1 V_9 )
{
struct V_10 * V_11 ;
if ( F_4 ( & V_8 -> V_12 ) )
return;
V_11 = F_5 ( V_8 -> V_12 . V_13 ,
struct V_10 , V_14 ) ;
V_11 -> V_15 . V_16 = V_8 -> V_9 ++ ;
V_11 -> V_15 . V_17 . V_18 = F_6 () ;
F_7 ( 2 , L_1 , V_11 ,
V_11 -> V_15 . V_17 . V_19 , V_9 , V_8 -> V_9 ) ;
F_8 ( & V_11 -> V_14 ) ;
F_9 ( & V_11 -> V_15 . V_17 , V_20 ) ;
}
int F_10 ( struct V_5 * V_6 , T_2 V_21 )
{
struct V_22 V_23 = {
. V_24 = V_25 ,
. V_23 . V_26 = V_27 ,
} ;
F_7 ( 1 , L_2 ,
V_28 ,
( unsigned int ) V_21 ,
F_11 ( V_21 ) ) ;
if ( V_6 -> V_29 == V_21 )
return 0 ;
if ( V_6 -> V_29 != V_21 ) {
if ( F_12 ( & V_6 -> V_30 ) || F_12 ( & V_6 -> V_31 ) ||
F_12 ( & V_6 -> V_32 ) )
return - V_33 ;
}
V_6 -> V_29 = V_21 ;
V_6 -> V_34 = 720 ;
V_6 -> V_35 = F_13 ( V_21 ) ;
V_6 -> V_36 = V_37 ;
F_14 ( V_6 , V_38 , V_39 , V_21 ) ;
V_23 . V_23 . V_34 = V_6 -> V_34 ;
V_23 . V_23 . V_35 = V_6 -> V_35 ;
V_23 . V_23 . V_36 = V_6 -> V_36 ;
F_14 ( V_6 , V_40 , V_41 , NULL , & V_23 ) ;
return 0 ;
}
static struct V_42 * F_15 ( struct V_5 * V_6 ,
struct V_43 * V_44 ,
struct V_42 * V_45 ,
char * type )
{
struct V_42 * V_46 ;
F_7 ( 1 , L_3 , V_28 ) ;
V_46 = F_16 () ;
if ( NULL == V_46 )
return NULL ;
* V_46 = * V_45 ;
V_46 -> V_47 = & V_6 -> V_47 ;
V_46 -> V_48 = V_49 ;
V_46 -> V_50 = & V_6 -> V_50 ;
snprintf ( V_46 -> V_51 , sizeof( V_46 -> V_51 ) , L_4 ,
V_52 [ V_6 -> V_53 ] . V_51 , type ) ;
F_17 ( V_46 , V_6 ) ;
return V_46 ;
}
int F_18 ( struct V_5 * V_6 , T_3 V_54 , T_3 V_55 )
{
T_3 V_11 [] = { V_54 , V_55 } ;
struct V_56 V_57 = { . V_58 = 0x98 >> 1 ,
. V_59 = 0 , . V_11 = V_11 , . V_60 = 2 } ;
return F_19 ( & V_6 -> V_61 [ 2 ] . V_62 , & V_57 , 1 ) ;
}
T_3 F_20 ( struct V_5 * V_6 , T_3 V_54 )
{
int V_63 ;
T_3 V_64 [] = { V_54 } ;
T_3 V_65 [] = { 0 } ;
struct V_56 V_57 [] = {
{ . V_58 = 0x98 >> 1 , . V_59 = 0 , . V_11 = V_64 , . V_60 = 1 } ,
{ . V_58 = 0x98 >> 1 , . V_59 = V_66 , . V_11 = V_65 , . V_60 = 1 }
} ;
V_63 = F_19 ( & V_6 -> V_61 [ 2 ] . V_62 , & V_57 [ 0 ] , 2 ) ;
if ( V_63 != 2 )
F_21 ( L_5 , V_28 ) ;
return V_65 [ 0 ] ;
}
static void F_22 ( struct V_5 * V_6 )
{
int V_3 ;
F_7 ( 1 , L_6 ) ;
for ( V_3 = 0 ; V_3 < 0x24 ; V_3 ++ ) {
F_7 ( 1 , L_7 , V_3 ,
F_20 ( V_6 , V_3 ) ) ;
}
}
static int F_23 ( struct V_5 * V_6 , int V_67 )
{
T_3 V_68 ;
F_7 ( 1 , L_8 , V_28 , V_67 ) ;
if ( V_67 == 1 )
V_68 = F_20 ( V_6 , V_69 ) & ~ V_70 ;
else if ( V_67 == 2 )
V_68 = F_20 ( V_6 , V_69 ) | V_70 ;
else
return - V_71 ;
V_68 |= 0x20 ;
F_18 ( V_6 , V_69 , V_68 ) ;
F_18 ( V_6 , V_72 , 0 ) ;
if ( V_73 )
F_22 ( V_6 ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 , unsigned int V_67 )
{
F_7 ( 1 , L_9 ,
V_28 ,
V_67 , F_25 ( V_67 ) -> V_74 ,
F_25 ( V_67 ) -> V_75 , F_25 ( V_67 ) -> V_76 ,
F_25 ( V_67 ) -> V_77 , F_25 ( V_67 ) -> V_78 ) ;
V_6 -> V_67 = V_67 ;
if ( V_6 -> V_53 == V_79 ||
V_6 -> V_53 == V_80 ||
V_6 -> V_53 == V_81 ) {
if ( F_25 ( V_67 ) -> type == V_82 )
F_26 ( V_6 , V_83 ) ;
}
F_27 ( V_6 -> V_84 , V_38 , V_85 ,
F_25 ( V_67 ) -> V_74 , 0 , 0 ) ;
if ( ( V_6 -> V_53 == V_86 ) ||
( V_6 -> V_53 == V_87 ) ||
( V_6 -> V_53 == V_88 ) ||
( V_6 -> V_53 == V_89 ) ||
( V_6 -> V_53 == V_90 ) ||
( V_6 -> V_53 == V_91 ) ||
( V_6 -> V_53 == V_92 ) ||
( V_6 -> V_53 == V_81 ) ||
( V_6 -> V_53 == V_93 ) ||
( V_6 -> V_53 == V_94 ) ||
( V_6 -> V_53 == V_95 ) ) {
F_27 ( V_6 -> V_84 , V_96 , V_85 ,
F_25 ( V_67 ) -> V_97 , 0 , 0 ) ;
if ( F_25 ( V_67 ) -> V_97 == V_98 )
F_23 ( V_6 , 1 ) ;
else if ( F_25 ( V_67 ) -> V_97 == V_99 )
F_23 ( V_6 , 2 ) ;
}
return 0 ;
}
static int F_28 ( struct V_5 * V_6 , unsigned int V_67 )
{
F_7 ( 1 , L_10 , V_28 , V_67 ) ;
if ( F_25 ( V_67 ) -> V_97 == V_98 )
F_23 ( V_6 , 1 ) ;
else if ( F_25 ( V_67 ) -> V_97 == V_99 )
F_23 ( V_6 , 2 ) ;
else {
F_23 ( V_6 , 1 ) ;
}
return 0 ;
}
static int F_29 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_10 * V_11 )
{
F_7 ( 1 , L_3 , V_28 ) ;
F_30 ( V_100 , 0x11 ) ;
F_31 ( V_6 , & V_6 -> V_101 [ V_102 ] ,
V_11 -> V_103 , V_11 -> V_104 . V_105 ) ;
F_32 ( V_106 , 3 ) ;
V_8 -> V_9 = 0 ;
F_33 ( V_6 , 0x01 ) ;
F_34 ( V_107 , 0x000011 ) ;
F_34 ( V_108 , ( 1 << 5 ) ) ;
F_34 ( V_100 , 0x11 ) ;
return 0 ;
}
static int F_35 ( struct V_109 * V_8 ,
unsigned int * V_110 , unsigned int * V_111 ,
unsigned int V_112 [] , struct V_113 * V_114 [] )
{
struct V_5 * V_6 = V_8 -> V_115 ;
* V_111 = 1 ;
V_112 [ 0 ] = ( V_6 -> V_116 -> V_117 * V_6 -> V_34 * V_6 -> V_35 ) >> 3 ;
return 0 ;
}
static int F_36 ( struct V_118 * V_15 )
{
struct V_119 * V_120 = F_37 ( V_15 ) ;
struct V_5 * V_6 = V_15 -> V_109 -> V_115 ;
struct V_10 * V_11 =
F_38 ( V_120 , struct V_10 , V_15 ) ;
T_1 V_121 , V_122 ;
struct V_123 * V_124 = F_39 ( V_15 , 0 ) ;
int V_125 ;
V_11 -> V_103 = ( V_6 -> V_34 * V_6 -> V_116 -> V_117 ) >> 3 ;
if ( F_40 ( V_15 , 0 ) < V_6 -> V_35 * V_11 -> V_103 )
return - V_71 ;
F_41 ( V_15 , 0 , V_6 -> V_35 * V_11 -> V_103 ) ;
switch ( V_6 -> V_36 ) {
case V_126 :
F_42 ( V_6 -> V_44 , & V_11 -> V_104 ,
V_124 -> V_127 , 0 , V_128 ,
V_11 -> V_103 , 0 , V_6 -> V_35 ) ;
break;
case V_129 :
F_42 ( V_6 -> V_44 , & V_11 -> V_104 ,
V_124 -> V_127 , V_128 , 0 ,
V_11 -> V_103 , 0 , V_6 -> V_35 ) ;
break;
case V_37 :
if ( V_6 -> V_29 & V_130 )
V_125 = 1 ;
else
V_125 = 0 ;
if ( V_52 [ V_6 -> V_53 ] . V_131 )
V_125 = 0 ;
if ( V_125 ) {
F_7 ( 1 , L_11 ,
V_28 ) ;
V_121 = V_11 -> V_103 ;
V_122 = 0 ;
} else {
F_7 ( 1 , L_12 ,
V_28 ) ;
V_121 = 0 ;
V_122 = V_11 -> V_103 ;
}
F_42 ( V_6 -> V_44 , & V_11 -> V_104 ,
V_124 -> V_127 , V_121 ,
V_122 ,
V_11 -> V_103 , V_11 -> V_103 ,
V_6 -> V_35 >> 1 ) ;
break;
case V_132 :
F_42 ( V_6 -> V_44 , & V_11 -> V_104 ,
V_124 -> V_127 ,
0 , V_11 -> V_103 * ( V_6 -> V_35 >> 1 ) ,
V_11 -> V_103 , 0 ,
V_6 -> V_35 >> 1 ) ;
break;
case V_133 :
F_42 ( V_6 -> V_44 , & V_11 -> V_104 ,
V_124 -> V_127 ,
V_11 -> V_103 * ( V_6 -> V_35 >> 1 ) , 0 ,
V_11 -> V_103 , 0 ,
V_6 -> V_35 >> 1 ) ;
break;
default:
F_43 () ;
}
F_7 ( 2 , L_13 ,
V_11 , V_11 -> V_15 . V_17 . V_19 ,
V_6 -> V_34 , V_6 -> V_35 , V_6 -> V_116 -> V_117 , V_6 -> V_116 -> V_51 ,
( unsigned long ) V_11 -> V_104 . V_105 ) ;
return 0 ;
}
static void F_44 ( struct V_118 * V_15 )
{
struct V_119 * V_120 = F_37 ( V_15 ) ;
struct V_10 * V_11 = F_38 ( V_120 ,
struct V_10 , V_15 ) ;
F_45 ( V_15 -> V_109 -> V_115 , V_11 ) ;
}
static void F_46 ( struct V_118 * V_15 )
{
struct V_119 * V_120 = F_37 ( V_15 ) ;
struct V_5 * V_6 = V_15 -> V_109 -> V_115 ;
struct V_10 * V_11 = F_38 ( V_120 ,
struct V_10 , V_15 ) ;
struct V_10 * V_134 ;
struct V_7 * V_8 = & V_6 -> V_135 ;
unsigned long V_59 ;
V_11 -> V_104 . V_136 [ 1 ] = F_47 ( V_11 -> V_104 . V_105 + 12 ) ;
V_11 -> V_104 . V_137 [ 0 ] = F_47 ( V_138 | V_139 ) ;
V_11 -> V_104 . V_137 [ 1 ] = F_47 ( V_11 -> V_104 . V_105 + 12 ) ;
V_11 -> V_104 . V_137 [ 2 ] = F_47 ( 0 ) ;
F_48 ( & V_6 -> V_140 , V_59 ) ;
if ( F_4 ( & V_8 -> V_12 ) ) {
F_49 ( & V_11 -> V_14 , & V_8 -> V_12 ) ;
F_7 ( 2 , L_14 ,
V_11 , V_11 -> V_15 . V_17 . V_19 ) ;
} else {
V_11 -> V_104 . V_136 [ 0 ] |= F_47 ( V_141 ) ;
V_134 = F_5 ( V_8 -> V_12 . V_134 , struct V_10 ,
V_14 ) ;
F_49 ( & V_11 -> V_14 , & V_8 -> V_12 ) ;
V_134 -> V_104 . V_137 [ 1 ] = F_47 ( V_11 -> V_104 . V_105 ) ;
F_7 ( 2 , L_15 ,
V_11 , V_11 -> V_15 . V_17 . V_19 ) ;
}
F_50 ( & V_6 -> V_140 , V_59 ) ;
}
static int F_51 ( struct V_109 * V_8 , unsigned int V_9 )
{
struct V_5 * V_6 = V_8 -> V_115 ;
struct V_7 * V_142 = & V_6 -> V_135 ;
struct V_10 * V_11 = F_5 ( V_142 -> V_12 . V_13 ,
struct V_10 , V_14 ) ;
F_29 ( V_6 , V_142 , V_11 ) ;
return 0 ;
}
static void F_52 ( struct V_109 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_115 ;
struct V_7 * V_142 = & V_6 -> V_135 ;
unsigned long V_59 ;
F_30 ( V_100 , 0x11 ) ;
F_48 ( & V_6 -> V_140 , V_59 ) ;
while ( ! F_4 ( & V_142 -> V_12 ) ) {
struct V_10 * V_11 = F_5 ( V_142 -> V_12 . V_13 ,
struct V_10 , V_14 ) ;
F_8 ( & V_11 -> V_14 ) ;
F_9 ( & V_11 -> V_15 . V_17 , V_143 ) ;
}
F_50 ( & V_6 -> V_140 , V_59 ) ;
}
static int F_53 ( struct V_144 * V_144 , void * V_145 ,
struct V_146 * V_147 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
V_147 -> V_116 . V_148 . V_34 = V_6 -> V_34 ;
V_147 -> V_116 . V_148 . V_35 = V_6 -> V_35 ;
V_147 -> V_116 . V_148 . V_36 = V_6 -> V_36 ;
V_147 -> V_116 . V_148 . V_149 = V_6 -> V_116 -> V_2 ;
V_147 -> V_116 . V_148 . V_150 =
( V_147 -> V_116 . V_148 . V_34 * V_6 -> V_116 -> V_117 ) >> 3 ;
V_147 -> V_116 . V_148 . V_151 =
V_147 -> V_116 . V_148 . V_35 * V_147 -> V_116 . V_148 . V_150 ;
V_147 -> V_116 . V_148 . V_152 = V_153 ;
return 0 ;
}
static int F_55 ( struct V_144 * V_144 , void * V_145 ,
struct V_146 * V_147 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
struct V_1 * V_116 ;
enum V_154 V_36 ;
unsigned int V_155 , V_156 ;
V_116 = F_1 ( V_147 -> V_116 . V_148 . V_149 ) ;
if ( NULL == V_116 )
return - V_71 ;
V_36 = V_147 -> V_116 . V_148 . V_36 ;
V_155 = 720 ;
V_156 = F_13 ( V_6 -> V_29 ) ;
if ( V_157 == V_36 ) {
V_36 = ( V_147 -> V_116 . V_148 . V_35 > V_156 / 2 )
? V_37
: V_129 ;
}
switch ( V_36 ) {
case V_126 :
case V_129 :
V_156 = V_156 / 2 ;
break;
case V_37 :
case V_132 :
case V_133 :
break;
default:
V_36 = V_37 ;
break;
}
V_147 -> V_116 . V_148 . V_36 = V_36 ;
F_56 ( & V_147 -> V_116 . V_148 . V_34 , 48 , V_155 , 2 ,
& V_147 -> V_116 . V_148 . V_35 , 32 , V_156 , 0 , 0 ) ;
V_147 -> V_116 . V_148 . V_150 =
( V_147 -> V_116 . V_148 . V_34 * V_116 -> V_117 ) >> 3 ;
V_147 -> V_116 . V_148 . V_151 =
V_147 -> V_116 . V_148 . V_35 * V_147 -> V_116 . V_148 . V_150 ;
V_147 -> V_116 . V_148 . V_152 = V_153 ;
return 0 ;
}
static int F_57 ( struct V_144 * V_144 , void * V_145 ,
struct V_146 * V_147 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
struct V_22 V_23 = {
. V_24 = V_25 ,
} ;
int V_158 ;
F_7 ( 2 , L_3 , V_28 ) ;
V_158 = F_55 ( V_144 , V_145 , V_147 ) ;
if ( 0 != V_158 )
return V_158 ;
if ( F_12 ( & V_6 -> V_30 ) || F_12 ( & V_6 -> V_31 ) ||
F_12 ( & V_6 -> V_32 ) )
return - V_33 ;
V_6 -> V_116 = F_1 ( V_147 -> V_116 . V_148 . V_149 ) ;
V_6 -> V_34 = V_147 -> V_116 . V_148 . V_34 ;
V_6 -> V_35 = V_147 -> V_116 . V_148 . V_35 ;
V_6 -> V_36 = V_147 -> V_116 . V_148 . V_36 ;
F_7 ( 2 , L_16 , V_28 ,
V_6 -> V_34 , V_6 -> V_35 , V_6 -> V_36 ) ;
F_58 ( & V_23 . V_23 , & V_147 -> V_116 . V_148 , V_27 ) ;
F_14 ( V_6 , V_40 , V_41 , NULL , & V_23 ) ;
F_59 ( & V_147 -> V_116 . V_148 , & V_23 . V_23 ) ;
V_147 -> V_116 . V_148 . V_36 = V_6 -> V_36 ;
return 0 ;
}
static int F_60 ( struct V_144 * V_144 , void * V_145 ,
struct V_159 * V_160 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
struct V_42 * V_161 = F_61 ( V_144 ) ;
strcpy ( V_160 -> V_162 , L_17 ) ;
F_62 ( V_160 -> V_163 , V_52 [ V_6 -> V_53 ] . V_51 ,
sizeof( V_160 -> V_163 ) ) ;
sprintf ( V_160 -> V_164 , L_18 , F_63 ( V_6 -> V_44 ) ) ;
V_160 -> V_165 = V_166 | V_167 | V_168 ;
if ( V_6 -> V_169 != V_170 )
V_160 -> V_165 |= V_171 ;
if ( V_161 -> V_172 == V_173 )
V_160 -> V_165 |= V_174 ;
else
V_160 -> V_165 |= V_175 ;
V_160 -> V_176 = V_160 -> V_165 | V_174 |
V_175 | V_177 ;
return 0 ;
}
static int F_64 ( struct V_144 * V_144 , void * V_145 ,
struct V_178 * V_147 )
{
if ( F_65 ( V_147 -> V_19 >= F_2 ( V_4 ) ) )
return - V_71 ;
F_62 ( V_147 -> V_179 , V_4 [ V_147 -> V_19 ] . V_51 ,
sizeof( V_147 -> V_179 ) ) ;
V_147 -> V_149 = V_4 [ V_147 -> V_19 ] . V_2 ;
return 0 ;
}
static int F_66 ( struct V_144 * V_144 , void * V_145 ,
struct V_180 * V_181 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
bool V_182 = V_6 -> V_29 & V_183 ;
if ( V_181 -> type != V_184 )
return - V_71 ;
V_181 -> V_185 . V_186 = 0 ;
V_181 -> V_185 . V_187 = 0 ;
V_181 -> V_185 . V_34 = 720 ;
V_181 -> V_185 . V_35 = F_13 ( V_6 -> V_29 ) ;
V_181 -> V_188 = V_181 -> V_185 ;
V_181 -> V_189 . V_190 = V_182 ? 54 : 11 ;
V_181 -> V_189 . V_191 = V_182 ? 59 : 10 ;
return 0 ;
}
static int F_67 ( struct V_144 * V_144 , void * V_145 , T_2 * V_192 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
F_7 ( 1 , L_3 , V_28 ) ;
* V_192 = V_6 -> V_29 ;
return 0 ;
}
static int F_68 ( struct V_144 * V_144 , void * V_145 , T_2 V_193 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
F_7 ( 1 , L_3 , V_28 ) ;
return F_10 ( V_6 , V_193 ) ;
}
int F_69 ( struct V_5 * V_6 , struct V_194 * V_3 )
{
static const char * V_195 [] = {
[ V_196 ] = L_19 ,
[ V_197 ] = L_20 ,
[ V_198 ] = L_21 ,
[ V_199 ] = L_22 ,
[ V_200 ] = L_23 ,
[ V_201 ] = L_24 ,
[ V_82 ] = L_25 ,
[ V_202 ] = L_26 ,
[ V_203 ] = L_27 ,
[ V_204 ] = L_28 ,
} ;
unsigned int V_205 ;
F_7 ( 1 , L_3 , V_28 ) ;
V_205 = V_3 -> V_19 ;
if ( V_205 >= V_206 )
return - V_71 ;
if ( 0 == F_25 ( V_205 ) -> type )
return - V_71 ;
V_3 -> V_19 = V_205 ;
V_3 -> type = V_207 ;
strcpy ( V_3 -> V_51 , V_195 [ F_25 ( V_205 ) -> type ] ) ;
V_3 -> V_208 = V_209 ;
if ( ( V_82 == F_25 ( V_205 ) -> type ) ||
( V_202 == F_25 ( V_205 ) -> type ) ) {
V_3 -> type = V_210 ;
V_3 -> V_211 = 4 ;
} else {
V_3 -> V_211 = 3 ;
}
if ( V_6 -> V_67 == V_205 ) {
F_14 ( V_6 , V_38 , V_212 , & V_3 -> V_213 ) ;
}
return 0 ;
}
static int F_70 ( struct V_144 * V_144 , void * V_145 ,
struct V_194 * V_3 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
F_7 ( 1 , L_3 , V_28 ) ;
return F_69 ( V_6 , V_3 ) ;
}
int F_71 ( struct V_144 * V_144 , void * V_145 , unsigned int * V_3 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
* V_3 = V_6 -> V_67 ;
F_7 ( 1 , L_29 , V_28 , * V_3 ) ;
return 0 ;
}
static int F_72 ( struct V_144 * V_144 , void * V_145 , unsigned int * V_3 )
{
return F_71 ( V_144 , V_145 , V_3 ) ;
}
int F_73 ( struct V_144 * V_144 , void * V_145 , unsigned int V_3 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
F_7 ( 1 , L_30 , V_28 , V_3 ) ;
if ( V_3 >= V_206 ) {
F_7 ( 1 , L_31 , V_28 ) ;
return - V_71 ;
}
if ( F_25 ( V_3 ) -> type == 0 )
return - V_71 ;
F_24 ( V_6 , V_3 ) ;
F_28 ( V_6 , V_3 ) ;
return 0 ;
}
static int F_74 ( struct V_144 * V_144 , void * V_145 , unsigned int V_3 )
{
return F_73 ( V_144 , V_145 , V_3 ) ;
}
static int F_75 ( struct V_144 * V_144 , void * V_145 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
F_14 ( V_6 , V_214 , V_215 ) ;
return 0 ;
}
static int F_76 ( struct V_144 * V_144 , void * V_145 ,
struct V_216 * V_3 )
{
static const char * V_195 [] = {
[ 0 ] = L_32 ,
[ 1 ] = L_33 ,
[ 2 ] = L_34 ,
} ;
unsigned int V_205 ;
F_7 ( 1 , L_3 , V_28 ) ;
V_205 = V_3 -> V_19 ;
if ( V_205 >= 3 )
return - V_71 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_19 = V_205 ;
strcpy ( V_3 -> V_51 , V_195 [ V_205 ] ) ;
V_3 -> V_217 = V_218 ;
return 0 ;
}
static int F_77 ( struct V_144 * V_144 , void * V_145 ,
struct V_216 * V_3 )
{
return F_76 ( V_144 , V_145 , V_3 ) ;
}
static int F_78 ( struct V_144 * V_144 , void * V_145 ,
struct V_216 * V_3 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
if ( ( V_82 == F_25 ( V_6 -> V_67 ) -> type ) ||
( V_202 == F_25 ( V_6 -> V_67 ) -> type ) )
V_3 -> V_19 = 2 ;
else
V_3 -> V_19 = V_6 -> V_219 ;
F_7 ( 1 , L_10 , V_28 , V_3 -> V_19 ) ;
return F_76 ( V_144 , V_145 , V_3 ) ;
}
static int F_79 ( struct V_144 * V_144 , void * V_145 ,
const struct V_216 * V_3 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
if ( ( V_82 == F_25 ( V_6 -> V_67 ) -> type ) ||
( V_202 == F_25 ( V_6 -> V_67 ) -> type ) ) {
return V_3 -> V_19 != 2 ? - V_71 : 0 ;
}
if ( V_3 -> V_19 > 1 )
return - V_71 ;
F_7 ( 1 , L_30 , V_28 , V_3 -> V_19 ) ;
V_6 -> V_219 = V_3 -> V_19 ;
F_23 ( V_6 , V_6 -> V_219 + 1 ) ;
return 0 ;
}
static int F_80 ( struct V_144 * V_144 , void * V_145 ,
struct V_220 * V_221 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
if ( V_6 -> V_169 == V_170 )
return - V_71 ;
if ( 0 != V_221 -> V_19 )
return - V_71 ;
strcpy ( V_221 -> V_51 , L_25 ) ;
F_14 ( V_6 , V_222 , V_223 , V_221 ) ;
return 0 ;
}
static int F_81 ( struct V_144 * V_144 , void * V_145 ,
const struct V_220 * V_221 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
if ( V_6 -> V_169 == V_170 )
return - V_71 ;
if ( 0 != V_221 -> V_19 )
return - V_71 ;
F_14 ( V_6 , V_222 , V_224 , V_221 ) ;
return 0 ;
}
static int F_82 ( struct V_144 * V_144 , void * V_145 ,
struct V_225 * V_147 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
if ( V_6 -> V_169 == V_170 )
return - V_71 ;
V_147 -> type = V_226 ;
V_147 -> V_227 = V_6 -> V_228 ;
F_14 ( V_6 , V_222 , V_229 , V_147 ) ;
return 0 ;
}
static int F_83 ( struct V_5 * V_6 , const struct V_225 * V_147 )
{
struct V_230 * V_231 ;
int V_232 = 1 ;
if ( V_6 -> V_169 == V_170 )
return - V_71 ;
if ( F_65 ( V_147 -> V_222 != 0 ) )
return - V_71 ;
V_6 -> V_228 = V_147 -> V_227 ;
V_231 = F_84 ( & V_6 -> V_233 , V_234 ) ;
if ( V_231 ) {
V_232 = F_85 ( V_231 ) ;
if ( ! V_232 )
F_86 ( V_231 , 1 ) ;
}
F_14 ( V_6 , V_222 , V_235 , V_147 ) ;
F_87 ( 100 ) ;
if ( V_232 == 0 )
F_86 ( V_231 , V_232 ) ;
return 0 ;
}
static int F_88 ( struct V_5 * V_6 ,
const struct V_225 * V_147 )
{
struct V_230 * V_231 ;
int V_232 = 1 ;
struct V_236 * V_237 ;
struct V_238 * V_239 ;
struct V_240 V_241 = {
. V_242 = V_226 ,
. V_243 = V_244 ,
. V_208 = V_6 -> V_29 ,
. V_227 = V_147 -> V_227
} ;
V_6 -> V_228 = V_147 -> V_227 ;
V_231 = F_84 ( & V_6 -> V_233 , V_234 ) ;
if ( V_231 ) {
V_232 = F_85 ( V_231 ) ;
if ( ! V_232 )
F_86 ( V_231 , 1 ) ;
}
F_7 ( 1 , L_35 , V_28 ,
V_241 . V_227 , V_147 -> V_222 , V_241 . V_208 ) ;
V_237 = F_89 ( & V_6 -> V_245 . V_246 , 1 ) ;
if ( ! V_237 ) {
return - V_71 ;
}
V_239 = V_237 -> V_247 . V_248 ;
if ( ( V_6 -> V_53 == V_92 ) ||
( V_6 -> V_53 == V_90 ) ||
( V_6 -> V_53 == V_91 ) )
V_239 = & V_6 -> V_249 . V_250 ;
if ( V_239 && V_239 -> V_251 . V_252 . V_253 ) {
F_14 ( V_6 , V_38 , V_39 , V_6 -> V_29 ) ;
V_239 -> V_251 . V_252 . V_253 ( V_239 , & V_241 ) ;
}
else
F_21 ( L_36 , V_28 ) ;
F_87 ( 100 ) ;
if ( V_232 == 0 )
F_86 ( V_231 , V_232 ) ;
return 0 ;
}
int F_90 ( struct V_144 * V_144 , void * V_145 ,
const struct V_225 * V_147 )
{
struct V_5 * V_6 = F_54 ( V_144 ) ;
int V_63 ;
switch ( V_6 -> V_53 ) {
case V_90 :
case V_91 :
case V_92 :
V_63 = F_88 ( V_6 , V_147 ) ;
break;
default:
V_63 = F_83 ( V_6 , V_147 ) ;
}
return V_63 ;
}
static int F_91 ( struct V_144 * V_144 , void * V_145 ,
const struct V_225 * V_147 )
{
return F_90 ( V_144 , V_145 , V_147 ) ;
}
int F_92 ( struct V_5 * V_6 , T_1 V_213 )
{
T_1 V_254 , V_9 ;
int V_255 = 0 ;
V_254 = F_93 ( V_107 ) ;
if ( 0 == ( V_213 & V_254 ) )
return V_255 ;
F_32 ( V_256 , V_213 ) ;
if ( ( V_213 & V_257 ) ||
( V_213 & V_258 ) ||
( V_213 & V_259 ) ) {
if ( V_213 & V_257 ) {
F_7 ( 7 , L_37 ,
V_257 ) ;
F_94 ( L_38 ,
V_6 -> V_51 ) ;
F_95 ( V_6 ,
& V_6 -> V_101 [ V_102 ] ) ;
}
if ( V_213 & V_258 )
F_7 ( 7 , L_39 ,
V_258 ) ;
if ( V_213 & V_259 )
F_7 ( 7 , L_40 ,
V_259 ) ;
}
if ( V_213 & V_260 ) {
F_96 ( & V_6 -> V_140 ) ;
V_9 = F_93 ( V_261 ) ;
F_3 ( V_6 , & V_6 -> V_135 , V_9 ) ;
F_97 ( & V_6 -> V_140 ) ;
V_255 ++ ;
}
V_255 += F_98 ( V_6 , V_213 ) ;
return V_255 ;
}
void F_99 ( struct V_5 * V_6 )
{
F_7 ( 1 , L_3 , V_28 ) ;
F_100 ( V_6 , 0x01 ) ;
if ( V_6 -> V_262 ) {
if ( F_101 ( V_6 -> V_262 ) )
F_102 ( V_6 -> V_262 ) ;
else
V_49 ( V_6 -> V_262 ) ;
V_6 -> V_262 = NULL ;
}
if ( V_6 -> V_263 ) {
if ( F_101 ( V_6 -> V_263 ) )
F_102 ( V_6 -> V_263 ) ;
else
V_49 ( V_6 -> V_263 ) ;
V_6 -> V_263 = NULL ;
}
if ( V_6 -> V_264 )
F_103 ( V_6 ) ;
}
int F_104 ( struct V_5 * V_6 )
{
struct V_109 * V_8 ;
int V_158 ;
F_7 ( 1 , L_3 , V_28 ) ;
V_265 = V_266 ;
strcpy ( V_265 . V_51 , L_41 ) ;
V_6 -> V_29 = V_267 ;
V_6 -> V_116 = F_1 ( V_268 ) ;
V_6 -> V_36 = V_37 ;
V_6 -> V_34 = 720 ;
V_6 -> V_35 = F_13 ( V_6 -> V_29 ) ;
F_105 ( & V_6 -> V_135 . V_12 ) ;
F_105 ( & V_6 -> V_269 . V_12 ) ;
F_33 ( V_6 , 0x01 ) ;
if ( ( V_170 != V_6 -> V_169 ) &&
( ( V_6 -> V_270 == 0 ) || ( V_6 -> V_270 == 1 ) ) ) {
struct V_271 * V_272 = NULL ;
if ( V_6 -> V_273 )
V_272 = F_106 ( & V_6 -> V_47 ,
& V_6 -> V_61 [ V_6 -> V_270 ] . V_62 ,
L_42 , V_6 -> V_273 , NULL ) ;
else
V_272 = F_106 ( & V_6 -> V_47 ,
& V_6 -> V_61 [ V_6 -> V_270 ] . V_62 ,
L_42 , 0 , F_107 ( V_274 ) ) ;
if ( V_272 ) {
struct V_275 V_276 ;
memset ( & V_276 , 0 , sizeof( V_276 ) ) ;
V_276 . V_277 = V_278 ;
V_276 . type = V_6 -> V_169 ;
V_276 . V_58 = F_108 ( V_272 ) ;
V_276 . V_279 = V_280 ;
F_27 ( V_272 , V_222 , V_281 , & V_276 ) ;
if ( ( V_6 -> V_53 == V_282 ) ||
( V_6 -> V_53 == V_283 ) ) {
struct V_284 V_285 = {
. V_286 = V_287 ,
. V_288 = 64
} ;
struct V_289 V_290 = {
. V_222 = V_6 -> V_169 ,
. V_145 = & V_285
} ;
F_27 ( V_272 , V_222 , V_291 , & V_290 ) ;
}
if ( V_6 -> V_53 == V_93 ) {
struct V_284 V_285 = {
. V_286 = L_43 ,
. V_288 = 64
} ;
struct V_289 V_290 = {
. V_222 = V_6 -> V_169 ,
. V_145 = & V_285
} ;
F_27 ( V_272 , V_222 , V_291 , & V_290 ) ;
}
}
}
F_109 ( & V_6 -> V_50 ) ;
F_10 ( V_6 , V_6 -> V_29 ) ;
F_24 ( V_6 , 0 ) ;
F_28 ( V_6 , 0 ) ;
F_110 ( & V_6 -> V_50 ) ;
V_8 = & V_6 -> V_30 ;
V_8 -> type = V_184 ;
V_8 -> V_292 = V_293 | V_294 | V_295 | V_296 ;
V_8 -> V_297 = V_298 ;
V_8 -> V_299 = 2 ;
V_8 -> V_115 = V_6 ;
V_8 -> V_300 = sizeof( struct V_10 ) ;
V_8 -> V_251 = & V_301 ;
V_8 -> V_302 = & V_303 ;
V_8 -> V_304 = V_305 ;
V_8 -> V_50 = & V_6 -> V_50 ;
V_8 -> V_6 = & V_6 -> V_44 -> V_6 ;
V_158 = F_111 ( V_8 ) ;
if ( V_158 < 0 )
goto V_306;
V_8 = & V_6 -> V_31 ;
V_8 -> type = V_307 ;
V_8 -> V_292 = V_293 | V_294 | V_295 | V_296 ;
V_8 -> V_297 = V_298 ;
V_8 -> V_299 = 2 ;
V_8 -> V_115 = V_6 ;
V_8 -> V_300 = sizeof( struct V_10 ) ;
V_8 -> V_251 = & V_308 ;
V_8 -> V_302 = & V_303 ;
V_8 -> V_304 = V_305 ;
V_8 -> V_50 = & V_6 -> V_50 ;
V_8 -> V_6 = & V_6 -> V_44 -> V_6 ;
V_158 = F_111 ( V_8 ) ;
if ( V_158 < 0 )
goto V_306;
V_6 -> V_263 = F_15 ( V_6 , V_6 -> V_44 ,
& V_266 , L_44 ) ;
V_6 -> V_263 -> V_14 = & V_6 -> V_30 ;
V_158 = F_112 ( V_6 -> V_263 , V_309 ,
V_310 [ V_6 -> V_311 ] ) ;
if ( V_158 < 0 ) {
F_113 ( L_45 ,
V_6 -> V_51 ) ;
goto V_306;
}
F_113 ( L_46 ,
V_6 -> V_51 , F_114 ( V_6 -> V_263 ) ) ;
V_6 -> V_262 = F_15 ( V_6 , V_6 -> V_44 ,
& V_265 , L_47 ) ;
V_6 -> V_262 -> V_14 = & V_6 -> V_31 ;
V_158 = F_112 ( V_6 -> V_262 , V_173 ,
V_312 [ V_6 -> V_311 ] ) ;
if ( V_158 < 0 ) {
F_113 ( L_48 ,
V_6 -> V_51 ) ;
goto V_306;
}
F_113 ( L_49 ,
V_6 -> V_51 , F_114 ( V_6 -> V_262 ) ) ;
V_6 -> V_264 = F_115 ( V_6 ) ;
return 0 ;
V_306:
F_99 ( V_6 ) ;
return V_158 ;
}
