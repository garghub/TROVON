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
F_21 ( V_67 L_5 , V_28 ) ;
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
static int F_23 ( struct V_5 * V_6 , int V_68 )
{
T_3 V_69 ;
F_7 ( 1 , L_8 , V_28 , V_68 ) ;
if ( V_68 == 1 )
V_69 = F_20 ( V_6 , V_70 ) & ~ V_71 ;
else if ( V_68 == 2 )
V_69 = F_20 ( V_6 , V_70 ) | V_71 ;
else
return - V_72 ;
V_69 |= 0x20 ;
F_18 ( V_6 , V_70 , V_69 ) ;
F_18 ( V_6 , V_73 , 0 ) ;
if ( V_74 )
F_22 ( V_6 ) ;
return 0 ;
}
static int F_24 ( struct V_5 * V_6 , unsigned int V_68 )
{
F_7 ( 1 , L_9 ,
V_28 ,
V_68 , F_25 ( V_68 ) -> V_75 ,
F_25 ( V_68 ) -> V_76 , F_25 ( V_68 ) -> V_77 ,
F_25 ( V_68 ) -> V_78 , F_25 ( V_68 ) -> V_79 ) ;
V_6 -> V_68 = V_68 ;
if ( V_6 -> V_53 == V_80 ||
V_6 -> V_53 == V_81 ||
V_6 -> V_53 == V_82 ) {
if ( F_25 ( V_68 ) -> type == V_83 )
F_26 ( V_6 , V_84 ) ;
}
F_27 ( V_6 -> V_85 , V_38 , V_86 ,
F_25 ( V_68 ) -> V_75 , 0 , 0 ) ;
if ( ( V_6 -> V_53 == V_87 ) ||
( V_6 -> V_53 == V_88 ) ||
( V_6 -> V_53 == V_89 ) ||
( V_6 -> V_53 == V_90 ) ||
( V_6 -> V_53 == V_91 ) ||
( V_6 -> V_53 == V_92 ) ||
( V_6 -> V_53 == V_93 ) ||
( V_6 -> V_53 == V_82 ) ||
( V_6 -> V_53 == V_94 ) ||
( V_6 -> V_53 == V_95 ) ||
( V_6 -> V_53 == V_96 ) ) {
F_27 ( V_6 -> V_85 , V_97 , V_86 ,
F_25 ( V_68 ) -> V_98 , 0 , 0 ) ;
if ( F_25 ( V_68 ) -> V_98 == V_99 )
F_23 ( V_6 , 1 ) ;
else if ( F_25 ( V_68 ) -> V_98 == V_100 )
F_23 ( V_6 , 2 ) ;
}
return 0 ;
}
static int F_28 ( struct V_5 * V_6 , unsigned int V_68 )
{
F_7 ( 1 , L_10 , V_28 , V_68 ) ;
if ( F_25 ( V_68 ) -> V_98 == V_99 )
F_23 ( V_6 , 1 ) ;
else if ( F_25 ( V_68 ) -> V_98 == V_100 )
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
F_30 ( V_101 , 0x11 ) ;
F_31 ( V_6 , & V_6 -> V_102 [ V_103 ] ,
V_11 -> V_104 , V_11 -> V_105 . V_106 ) ;
F_32 ( V_107 , 3 ) ;
V_8 -> V_9 = 0 ;
F_33 ( V_6 , 0x01 ) ;
F_34 ( V_108 , 0x000011 ) ;
F_34 ( V_109 , ( 1 << 5 ) ) ;
F_34 ( V_101 , 0x11 ) ;
return 0 ;
}
static int F_35 ( struct V_110 * V_8 ,
unsigned int * V_111 , unsigned int * V_112 ,
unsigned int V_113 [] , struct V_114 * V_115 [] )
{
struct V_5 * V_6 = V_8 -> V_116 ;
* V_112 = 1 ;
V_113 [ 0 ] = ( V_6 -> V_117 -> V_118 * V_6 -> V_34 * V_6 -> V_35 ) >> 3 ;
return 0 ;
}
static int F_36 ( struct V_119 * V_15 )
{
struct V_120 * V_121 = F_37 ( V_15 ) ;
struct V_5 * V_6 = V_15 -> V_110 -> V_116 ;
struct V_10 * V_11 =
F_38 ( V_121 , struct V_10 , V_15 ) ;
T_1 V_122 , V_123 ;
struct V_124 * V_125 = F_39 ( V_15 , 0 ) ;
int V_126 ;
V_11 -> V_104 = ( V_6 -> V_34 * V_6 -> V_117 -> V_118 ) >> 3 ;
if ( F_40 ( V_15 , 0 ) < V_6 -> V_35 * V_11 -> V_104 )
return - V_72 ;
F_41 ( V_15 , 0 , V_6 -> V_35 * V_11 -> V_104 ) ;
switch ( V_6 -> V_36 ) {
case V_127 :
F_42 ( V_6 -> V_44 , & V_11 -> V_105 ,
V_125 -> V_128 , 0 , V_129 ,
V_11 -> V_104 , 0 , V_6 -> V_35 ) ;
break;
case V_130 :
F_42 ( V_6 -> V_44 , & V_11 -> V_105 ,
V_125 -> V_128 , V_129 , 0 ,
V_11 -> V_104 , 0 , V_6 -> V_35 ) ;
break;
case V_37 :
if ( V_6 -> V_29 & V_131 )
V_126 = 1 ;
else
V_126 = 0 ;
if ( V_52 [ V_6 -> V_53 ] . V_132 )
V_126 = 0 ;
if ( V_126 ) {
F_7 ( 1 , L_11 ,
V_28 ) ;
V_122 = V_11 -> V_104 ;
V_123 = 0 ;
} else {
F_7 ( 1 , L_12 ,
V_28 ) ;
V_122 = 0 ;
V_123 = V_11 -> V_104 ;
}
F_42 ( V_6 -> V_44 , & V_11 -> V_105 ,
V_125 -> V_128 , V_122 ,
V_123 ,
V_11 -> V_104 , V_11 -> V_104 ,
V_6 -> V_35 >> 1 ) ;
break;
case V_133 :
F_42 ( V_6 -> V_44 , & V_11 -> V_105 ,
V_125 -> V_128 ,
0 , V_11 -> V_104 * ( V_6 -> V_35 >> 1 ) ,
V_11 -> V_104 , 0 ,
V_6 -> V_35 >> 1 ) ;
break;
case V_134 :
F_42 ( V_6 -> V_44 , & V_11 -> V_105 ,
V_125 -> V_128 ,
V_11 -> V_104 * ( V_6 -> V_35 >> 1 ) , 0 ,
V_11 -> V_104 , 0 ,
V_6 -> V_35 >> 1 ) ;
break;
default:
F_43 () ;
}
F_7 ( 2 , L_13 ,
V_11 , V_11 -> V_15 . V_17 . V_19 ,
V_6 -> V_34 , V_6 -> V_35 , V_6 -> V_117 -> V_118 , V_6 -> V_117 -> V_51 ,
( unsigned long ) V_11 -> V_105 . V_106 ) ;
return 0 ;
}
static void F_44 ( struct V_119 * V_15 )
{
struct V_120 * V_121 = F_37 ( V_15 ) ;
struct V_10 * V_11 = F_38 ( V_121 ,
struct V_10 , V_15 ) ;
F_45 ( V_15 -> V_110 -> V_116 , V_11 ) ;
}
static void F_46 ( struct V_119 * V_15 )
{
struct V_120 * V_121 = F_37 ( V_15 ) ;
struct V_5 * V_6 = V_15 -> V_110 -> V_116 ;
struct V_10 * V_11 = F_38 ( V_121 ,
struct V_10 , V_15 ) ;
struct V_10 * V_135 ;
struct V_7 * V_8 = & V_6 -> V_136 ;
unsigned long V_59 ;
V_11 -> V_105 . V_137 [ 1 ] = F_47 ( V_11 -> V_105 . V_106 + 12 ) ;
V_11 -> V_105 . V_138 [ 0 ] = F_47 ( V_139 | V_140 ) ;
V_11 -> V_105 . V_138 [ 1 ] = F_47 ( V_11 -> V_105 . V_106 + 12 ) ;
V_11 -> V_105 . V_138 [ 2 ] = F_47 ( 0 ) ;
F_48 ( & V_6 -> V_141 , V_59 ) ;
if ( F_4 ( & V_8 -> V_12 ) ) {
F_49 ( & V_11 -> V_14 , & V_8 -> V_12 ) ;
F_7 ( 2 , L_14 ,
V_11 , V_11 -> V_15 . V_17 . V_19 ) ;
} else {
V_11 -> V_105 . V_137 [ 0 ] |= F_47 ( V_142 ) ;
V_135 = F_5 ( V_8 -> V_12 . V_135 , struct V_10 ,
V_14 ) ;
F_49 ( & V_11 -> V_14 , & V_8 -> V_12 ) ;
V_135 -> V_105 . V_138 [ 1 ] = F_47 ( V_11 -> V_105 . V_106 ) ;
F_7 ( 2 , L_15 ,
V_11 , V_11 -> V_15 . V_17 . V_19 ) ;
}
F_50 ( & V_6 -> V_141 , V_59 ) ;
}
static int F_51 ( struct V_110 * V_8 , unsigned int V_9 )
{
struct V_5 * V_6 = V_8 -> V_116 ;
struct V_7 * V_143 = & V_6 -> V_136 ;
struct V_10 * V_11 = F_5 ( V_143 -> V_12 . V_13 ,
struct V_10 , V_14 ) ;
F_29 ( V_6 , V_143 , V_11 ) ;
return 0 ;
}
static void F_52 ( struct V_110 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_116 ;
struct V_7 * V_143 = & V_6 -> V_136 ;
unsigned long V_59 ;
F_30 ( V_101 , 0x11 ) ;
F_48 ( & V_6 -> V_141 , V_59 ) ;
while ( ! F_4 ( & V_143 -> V_12 ) ) {
struct V_10 * V_11 = F_5 ( V_143 -> V_12 . V_13 ,
struct V_10 , V_14 ) ;
F_8 ( & V_11 -> V_14 ) ;
F_9 ( & V_11 -> V_15 . V_17 , V_144 ) ;
}
F_50 ( & V_6 -> V_141 , V_59 ) ;
}
static int F_53 ( struct V_145 * V_145 , void * V_146 ,
struct V_147 * V_148 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
V_148 -> V_117 . V_149 . V_34 = V_6 -> V_34 ;
V_148 -> V_117 . V_149 . V_35 = V_6 -> V_35 ;
V_148 -> V_117 . V_149 . V_36 = V_6 -> V_36 ;
V_148 -> V_117 . V_149 . V_150 = V_6 -> V_117 -> V_2 ;
V_148 -> V_117 . V_149 . V_151 =
( V_148 -> V_117 . V_149 . V_34 * V_6 -> V_117 -> V_118 ) >> 3 ;
V_148 -> V_117 . V_149 . V_152 =
V_148 -> V_117 . V_149 . V_35 * V_148 -> V_117 . V_149 . V_151 ;
V_148 -> V_117 . V_149 . V_153 = V_154 ;
return 0 ;
}
static int F_55 ( struct V_145 * V_145 , void * V_146 ,
struct V_147 * V_148 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
struct V_1 * V_117 ;
enum V_155 V_36 ;
unsigned int V_156 , V_157 ;
V_117 = F_1 ( V_148 -> V_117 . V_149 . V_150 ) ;
if ( NULL == V_117 )
return - V_72 ;
V_36 = V_148 -> V_117 . V_149 . V_36 ;
V_156 = 720 ;
V_157 = F_13 ( V_6 -> V_29 ) ;
if ( V_158 == V_36 ) {
V_36 = ( V_148 -> V_117 . V_149 . V_35 > V_157 / 2 )
? V_37
: V_130 ;
}
switch ( V_36 ) {
case V_127 :
case V_130 :
V_157 = V_157 / 2 ;
break;
case V_37 :
case V_133 :
case V_134 :
break;
default:
V_36 = V_37 ;
break;
}
V_148 -> V_117 . V_149 . V_36 = V_36 ;
F_56 ( & V_148 -> V_117 . V_149 . V_34 , 48 , V_156 , 2 ,
& V_148 -> V_117 . V_149 . V_35 , 32 , V_157 , 0 , 0 ) ;
V_148 -> V_117 . V_149 . V_151 =
( V_148 -> V_117 . V_149 . V_34 * V_117 -> V_118 ) >> 3 ;
V_148 -> V_117 . V_149 . V_152 =
V_148 -> V_117 . V_149 . V_35 * V_148 -> V_117 . V_149 . V_151 ;
V_148 -> V_117 . V_149 . V_153 = V_154 ;
return 0 ;
}
static int F_57 ( struct V_145 * V_145 , void * V_146 ,
struct V_147 * V_148 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
struct V_22 V_23 = {
. V_24 = V_25 ,
} ;
int V_159 ;
F_7 ( 2 , L_3 , V_28 ) ;
V_159 = F_55 ( V_145 , V_146 , V_148 ) ;
if ( 0 != V_159 )
return V_159 ;
if ( F_12 ( & V_6 -> V_30 ) || F_12 ( & V_6 -> V_31 ) ||
F_12 ( & V_6 -> V_32 ) )
return - V_33 ;
V_6 -> V_117 = F_1 ( V_148 -> V_117 . V_149 . V_150 ) ;
V_6 -> V_34 = V_148 -> V_117 . V_149 . V_34 ;
V_6 -> V_35 = V_148 -> V_117 . V_149 . V_35 ;
V_6 -> V_36 = V_148 -> V_117 . V_149 . V_36 ;
F_7 ( 2 , L_16 , V_28 ,
V_6 -> V_34 , V_6 -> V_35 , V_6 -> V_36 ) ;
F_58 ( & V_23 . V_23 , & V_148 -> V_117 . V_149 , V_27 ) ;
F_14 ( V_6 , V_40 , V_41 , NULL , & V_23 ) ;
F_59 ( & V_148 -> V_117 . V_149 , & V_23 . V_23 ) ;
V_148 -> V_117 . V_149 . V_36 = V_6 -> V_36 ;
return 0 ;
}
static int F_60 ( struct V_145 * V_145 , void * V_146 ,
struct V_160 * V_161 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
struct V_42 * V_162 = F_61 ( V_145 ) ;
strcpy ( V_161 -> V_163 , L_17 ) ;
F_62 ( V_161 -> V_164 , V_52 [ V_6 -> V_53 ] . V_51 ,
sizeof( V_161 -> V_164 ) ) ;
sprintf ( V_161 -> V_165 , L_18 , F_63 ( V_6 -> V_44 ) ) ;
V_161 -> V_166 = V_167 | V_168 | V_169 ;
if ( V_6 -> V_170 != V_171 )
V_161 -> V_166 |= V_172 ;
if ( V_162 -> V_173 == V_174 )
V_161 -> V_166 |= V_175 ;
else
V_161 -> V_166 |= V_176 ;
V_161 -> V_177 = V_161 -> V_166 | V_175 |
V_176 | V_178 ;
return 0 ;
}
static int F_64 ( struct V_145 * V_145 , void * V_146 ,
struct V_179 * V_148 )
{
if ( F_65 ( V_148 -> V_19 >= F_2 ( V_4 ) ) )
return - V_72 ;
F_62 ( V_148 -> V_180 , V_4 [ V_148 -> V_19 ] . V_51 ,
sizeof( V_148 -> V_180 ) ) ;
V_148 -> V_150 = V_4 [ V_148 -> V_19 ] . V_2 ;
return 0 ;
}
static int F_66 ( struct V_145 * V_145 , void * V_146 ,
struct V_181 * V_182 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
bool V_183 = V_6 -> V_29 & V_184 ;
if ( V_182 -> type != V_185 )
return - V_72 ;
V_182 -> V_186 . V_187 = 0 ;
V_182 -> V_186 . V_188 = 0 ;
V_182 -> V_186 . V_34 = 720 ;
V_182 -> V_186 . V_35 = F_13 ( V_6 -> V_29 ) ;
V_182 -> V_189 = V_182 -> V_186 ;
V_182 -> V_190 . V_191 = V_183 ? 54 : 11 ;
V_182 -> V_190 . V_192 = V_183 ? 59 : 10 ;
return 0 ;
}
static int F_67 ( struct V_145 * V_145 , void * V_146 , T_2 * V_193 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
F_7 ( 1 , L_3 , V_28 ) ;
* V_193 = V_6 -> V_29 ;
return 0 ;
}
static int F_68 ( struct V_145 * V_145 , void * V_146 , T_2 V_194 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
F_7 ( 1 , L_3 , V_28 ) ;
return F_10 ( V_6 , V_194 ) ;
}
int F_69 ( struct V_5 * V_6 , struct V_195 * V_3 )
{
static const char * V_196 [] = {
[ V_197 ] = L_19 ,
[ V_198 ] = L_20 ,
[ V_199 ] = L_21 ,
[ V_200 ] = L_22 ,
[ V_201 ] = L_23 ,
[ V_202 ] = L_24 ,
[ V_83 ] = L_25 ,
[ V_203 ] = L_26 ,
[ V_204 ] = L_27 ,
[ V_205 ] = L_28 ,
} ;
unsigned int V_206 ;
F_7 ( 1 , L_3 , V_28 ) ;
V_206 = V_3 -> V_19 ;
if ( V_206 >= V_207 )
return - V_72 ;
if ( 0 == F_25 ( V_206 ) -> type )
return - V_72 ;
V_3 -> V_19 = V_206 ;
V_3 -> type = V_208 ;
strcpy ( V_3 -> V_51 , V_196 [ F_25 ( V_206 ) -> type ] ) ;
V_3 -> V_209 = V_210 ;
if ( ( V_83 == F_25 ( V_206 ) -> type ) ||
( V_203 == F_25 ( V_206 ) -> type ) ) {
V_3 -> type = V_211 ;
V_3 -> V_212 = 4 ;
} else {
V_3 -> V_212 = 3 ;
}
if ( V_6 -> V_68 == V_206 ) {
F_14 ( V_6 , V_38 , V_213 , & V_3 -> V_214 ) ;
}
return 0 ;
}
static int F_70 ( struct V_145 * V_145 , void * V_146 ,
struct V_195 * V_3 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
F_7 ( 1 , L_3 , V_28 ) ;
return F_69 ( V_6 , V_3 ) ;
}
int F_71 ( struct V_145 * V_145 , void * V_146 , unsigned int * V_3 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
* V_3 = V_6 -> V_68 ;
F_7 ( 1 , L_29 , V_28 , * V_3 ) ;
return 0 ;
}
static int F_72 ( struct V_145 * V_145 , void * V_146 , unsigned int * V_3 )
{
return F_71 ( V_145 , V_146 , V_3 ) ;
}
int F_73 ( struct V_145 * V_145 , void * V_146 , unsigned int V_3 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
F_7 ( 1 , L_30 , V_28 , V_3 ) ;
if ( V_3 >= V_207 ) {
F_7 ( 1 , L_31 , V_28 ) ;
return - V_72 ;
}
if ( F_25 ( V_3 ) -> type == 0 )
return - V_72 ;
F_24 ( V_6 , V_3 ) ;
F_28 ( V_6 , V_3 ) ;
return 0 ;
}
static int F_74 ( struct V_145 * V_145 , void * V_146 , unsigned int V_3 )
{
return F_73 ( V_145 , V_146 , V_3 ) ;
}
static int F_75 ( struct V_145 * V_145 , void * V_146 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
F_14 ( V_6 , V_215 , V_216 ) ;
return 0 ;
}
static int F_76 ( struct V_145 * V_145 , void * V_146 ,
struct V_217 * V_3 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
static const char * V_196 [] = {
[ 0 ] = L_32 ,
[ 1 ] = L_33 ,
[ 2 ] = L_34 ,
} ;
unsigned int V_206 ;
F_7 ( 1 , L_3 , V_28 ) ;
V_206 = V_3 -> V_19 ;
if ( V_206 >= 3 )
return - V_72 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_19 = V_206 ;
strcpy ( V_3 -> V_51 , V_196 [ V_206 ] ) ;
V_3 -> V_218 = V_219 ;
return 0 ;
}
static int F_77 ( struct V_145 * V_145 , void * V_146 ,
struct V_217 * V_3 )
{
return F_76 ( V_145 , V_146 , V_3 ) ;
}
static int F_78 ( struct V_145 * V_145 , void * V_146 ,
struct V_217 * V_3 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
if ( ( V_83 == F_25 ( V_6 -> V_68 ) -> type ) ||
( V_203 == F_25 ( V_6 -> V_68 ) -> type ) )
V_3 -> V_19 = 2 ;
else
V_3 -> V_19 = V_6 -> V_220 ;
F_7 ( 1 , L_10 , V_28 , V_3 -> V_19 ) ;
return F_76 ( V_145 , V_146 , V_3 ) ;
}
static int F_79 ( struct V_145 * V_145 , void * V_146 ,
const struct V_217 * V_3 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
if ( ( V_83 == F_25 ( V_6 -> V_68 ) -> type ) ||
( V_203 == F_25 ( V_6 -> V_68 ) -> type ) ) {
return V_3 -> V_19 != 2 ? - V_72 : 0 ;
}
if ( V_3 -> V_19 > 1 )
return - V_72 ;
F_7 ( 1 , L_30 , V_28 , V_3 -> V_19 ) ;
V_6 -> V_220 = V_3 -> V_19 ;
F_23 ( V_6 , V_6 -> V_220 + 1 ) ;
return 0 ;
}
static int F_80 ( struct V_145 * V_145 , void * V_146 ,
struct V_221 * V_222 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
if ( V_6 -> V_170 == V_171 )
return - V_72 ;
if ( 0 != V_222 -> V_19 )
return - V_72 ;
strcpy ( V_222 -> V_51 , L_25 ) ;
F_14 ( V_6 , V_223 , V_224 , V_222 ) ;
return 0 ;
}
static int F_81 ( struct V_145 * V_145 , void * V_146 ,
const struct V_221 * V_222 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
if ( V_6 -> V_170 == V_171 )
return - V_72 ;
if ( 0 != V_222 -> V_19 )
return - V_72 ;
F_14 ( V_6 , V_223 , V_225 , V_222 ) ;
return 0 ;
}
static int F_82 ( struct V_145 * V_145 , void * V_146 ,
struct V_226 * V_148 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
if ( V_6 -> V_170 == V_171 )
return - V_72 ;
V_148 -> type = V_227 ;
V_148 -> V_228 = V_6 -> V_229 ;
F_14 ( V_6 , V_223 , V_230 , V_148 ) ;
return 0 ;
}
static int F_83 ( struct V_5 * V_6 , const struct V_226 * V_148 )
{
struct V_231 * V_232 ;
int V_233 = 1 ;
if ( V_6 -> V_170 == V_171 )
return - V_72 ;
if ( F_65 ( V_148 -> V_223 != 0 ) )
return - V_72 ;
V_6 -> V_229 = V_148 -> V_228 ;
V_232 = F_84 ( & V_6 -> V_234 , V_235 ) ;
if ( V_232 ) {
V_233 = F_85 ( V_232 ) ;
if ( ! V_233 )
F_86 ( V_232 , 1 ) ;
}
F_14 ( V_6 , V_223 , V_236 , V_148 ) ;
F_87 ( 100 ) ;
if ( V_233 == 0 )
F_86 ( V_232 , V_233 ) ;
return 0 ;
}
static int F_88 ( struct V_5 * V_6 ,
const struct V_226 * V_148 )
{
struct V_231 * V_232 ;
int V_233 = 1 ;
struct V_237 * V_238 ;
struct V_239 * V_240 ;
struct V_241 V_242 = {
. V_243 = V_227 ,
. V_244 = V_245 ,
. V_209 = V_6 -> V_29 ,
. V_228 = V_148 -> V_228
} ;
V_6 -> V_229 = V_148 -> V_228 ;
V_232 = F_84 ( & V_6 -> V_234 , V_235 ) ;
if ( V_232 ) {
V_233 = F_85 ( V_232 ) ;
if ( ! V_233 )
F_86 ( V_232 , 1 ) ;
}
F_7 ( 1 , L_35 , V_28 ,
V_242 . V_228 , V_148 -> V_223 , V_242 . V_209 ) ;
V_238 = F_89 ( & V_6 -> V_246 . V_247 , 1 ) ;
if ( ! V_238 ) {
return - V_72 ;
}
V_240 = V_238 -> V_248 . V_249 ;
if ( ( V_6 -> V_53 == V_93 ) ||
( V_6 -> V_53 == V_91 ) ||
( V_6 -> V_53 == V_92 ) )
V_240 = & V_6 -> V_250 . V_251 ;
if ( V_240 && V_240 -> V_252 . V_253 . V_254 ) {
F_14 ( V_6 , V_38 , V_39 , V_6 -> V_29 ) ;
V_240 -> V_252 . V_253 . V_254 ( V_240 , & V_242 ) ;
}
else
F_21 ( V_67 L_36 , V_28 ) ;
F_87 ( 100 ) ;
if ( V_233 == 0 )
F_86 ( V_232 , V_233 ) ;
return 0 ;
}
int F_90 ( struct V_145 * V_145 , void * V_146 ,
const struct V_226 * V_148 )
{
struct V_5 * V_6 = F_54 ( V_145 ) ;
int V_63 ;
switch ( V_6 -> V_53 ) {
case V_91 :
case V_92 :
case V_93 :
V_63 = F_88 ( V_6 , V_148 ) ;
break;
default:
V_63 = F_83 ( V_6 , V_148 ) ;
}
return V_63 ;
}
static int F_91 ( struct V_145 * V_145 , void * V_146 ,
const struct V_226 * V_148 )
{
return F_90 ( V_145 , V_146 , V_148 ) ;
}
int F_92 ( struct V_5 * V_6 , T_1 V_214 )
{
T_1 V_255 , V_9 ;
int V_256 = 0 ;
V_255 = F_93 ( V_108 ) ;
if ( 0 == ( V_214 & V_255 ) )
return V_256 ;
F_32 ( V_257 , V_214 ) ;
if ( ( V_214 & V_258 ) ||
( V_214 & V_259 ) ||
( V_214 & V_260 ) ) {
if ( V_214 & V_258 ) {
F_7 ( 7 , L_37 ,
V_258 ) ;
F_21 ( V_261 L_38 ,
V_6 -> V_51 ) ;
F_94 ( V_6 ,
& V_6 -> V_102 [ V_103 ] ) ;
}
if ( V_214 & V_259 )
F_7 ( 7 , L_39
L_40 ,
V_259 ) ;
if ( V_214 & V_260 )
F_7 ( 7 , L_41 ,
V_260 ) ;
}
if ( V_214 & V_262 ) {
F_95 ( & V_6 -> V_141 ) ;
V_9 = F_93 ( V_263 ) ;
F_3 ( V_6 , & V_6 -> V_136 , V_9 ) ;
F_96 ( & V_6 -> V_141 ) ;
V_256 ++ ;
}
V_256 += F_97 ( V_6 , V_214 ) ;
return V_256 ;
}
void F_98 ( struct V_5 * V_6 )
{
F_7 ( 1 , L_3 , V_28 ) ;
F_99 ( V_6 , 0x01 ) ;
if ( V_6 -> V_264 ) {
if ( F_100 ( V_6 -> V_264 ) )
F_101 ( V_6 -> V_264 ) ;
else
V_49 ( V_6 -> V_264 ) ;
V_6 -> V_264 = NULL ;
}
if ( V_6 -> V_265 ) {
if ( F_100 ( V_6 -> V_265 ) )
F_101 ( V_6 -> V_265 ) ;
else
V_49 ( V_6 -> V_265 ) ;
V_6 -> V_265 = NULL ;
}
if ( V_6 -> V_266 )
F_102 ( V_6 ) ;
}
int F_103 ( struct V_5 * V_6 )
{
struct V_110 * V_8 ;
int V_159 ;
F_7 ( 1 , L_3 , V_28 ) ;
V_267 = V_268 ;
strcpy ( V_267 . V_51 , L_42 ) ;
V_6 -> V_29 = V_269 ;
V_6 -> V_117 = F_1 ( V_270 ) ;
V_6 -> V_36 = V_37 ;
V_6 -> V_34 = 720 ;
V_6 -> V_35 = F_13 ( V_6 -> V_29 ) ;
F_104 ( & V_6 -> V_136 . V_12 ) ;
F_104 ( & V_6 -> V_271 . V_12 ) ;
F_33 ( V_6 , 0x01 ) ;
if ( ( V_171 != V_6 -> V_170 ) &&
( ( V_6 -> V_272 == 0 ) || ( V_6 -> V_272 == 1 ) ) ) {
struct V_273 * V_274 = NULL ;
if ( V_6 -> V_275 )
V_274 = F_105 ( & V_6 -> V_47 ,
& V_6 -> V_61 [ V_6 -> V_272 ] . V_62 ,
L_43 , V_6 -> V_275 , NULL ) ;
else
V_274 = F_105 ( & V_6 -> V_47 ,
& V_6 -> V_61 [ V_6 -> V_272 ] . V_62 ,
L_43 , 0 , F_106 ( V_276 ) ) ;
if ( V_274 ) {
struct V_277 V_278 ;
memset ( & V_278 , 0 , sizeof( V_278 ) ) ;
V_278 . V_279 = V_280 ;
V_278 . type = V_6 -> V_170 ;
V_278 . V_58 = F_107 ( V_274 ) ;
V_278 . V_281 = V_282 ;
F_27 ( V_274 , V_223 , V_283 , & V_278 ) ;
if ( ( V_6 -> V_53 == V_284 ) ||
( V_6 -> V_53 == V_285 ) ) {
struct V_286 V_287 = {
. V_288 = V_289 ,
. V_290 = 64
} ;
struct V_291 V_292 = {
. V_223 = V_6 -> V_170 ,
. V_146 = & V_287
} ;
F_27 ( V_274 , V_223 , V_293 , & V_292 ) ;
}
if ( V_6 -> V_53 == V_94 ) {
struct V_286 V_287 = {
. V_288 = L_44 ,
. V_290 = 64
} ;
struct V_291 V_292 = {
. V_223 = V_6 -> V_170 ,
. V_146 = & V_287
} ;
F_27 ( V_274 , V_223 , V_293 , & V_292 ) ;
}
}
}
F_108 ( & V_6 -> V_50 ) ;
F_10 ( V_6 , V_6 -> V_29 ) ;
F_24 ( V_6 , 0 ) ;
F_28 ( V_6 , 0 ) ;
F_109 ( & V_6 -> V_50 ) ;
V_8 = & V_6 -> V_30 ;
V_8 -> type = V_185 ;
V_8 -> V_294 = V_295 | V_296 | V_297 | V_298 ;
V_8 -> V_299 = V_300 ;
V_8 -> V_301 = 2 ;
V_8 -> V_116 = V_6 ;
V_8 -> V_302 = sizeof( struct V_10 ) ;
V_8 -> V_252 = & V_303 ;
V_8 -> V_304 = & V_305 ;
V_8 -> V_306 = V_307 ;
V_8 -> V_50 = & V_6 -> V_50 ;
V_8 -> V_6 = & V_6 -> V_44 -> V_6 ;
V_159 = F_110 ( V_8 ) ;
if ( V_159 < 0 )
goto V_308;
V_8 = & V_6 -> V_31 ;
V_8 -> type = V_309 ;
V_8 -> V_294 = V_295 | V_296 | V_297 | V_298 ;
V_8 -> V_299 = V_300 ;
V_8 -> V_301 = 2 ;
V_8 -> V_116 = V_6 ;
V_8 -> V_302 = sizeof( struct V_10 ) ;
V_8 -> V_252 = & V_310 ;
V_8 -> V_304 = & V_305 ;
V_8 -> V_306 = V_307 ;
V_8 -> V_50 = & V_6 -> V_50 ;
V_8 -> V_6 = & V_6 -> V_44 -> V_6 ;
V_159 = F_110 ( V_8 ) ;
if ( V_159 < 0 )
goto V_308;
V_6 -> V_265 = F_15 ( V_6 , V_6 -> V_44 ,
& V_268 , L_45 ) ;
V_6 -> V_265 -> V_14 = & V_6 -> V_30 ;
V_159 = F_111 ( V_6 -> V_265 , V_311 ,
V_312 [ V_6 -> V_313 ] ) ;
if ( V_159 < 0 ) {
F_21 ( V_314 L_46 ,
V_6 -> V_51 ) ;
goto V_308;
}
F_21 ( V_314 L_47 ,
V_6 -> V_51 , F_112 ( V_6 -> V_265 ) ) ;
V_6 -> V_264 = F_15 ( V_6 , V_6 -> V_44 ,
& V_267 , L_48 ) ;
V_6 -> V_264 -> V_14 = & V_6 -> V_31 ;
V_159 = F_111 ( V_6 -> V_264 , V_174 ,
V_315 [ V_6 -> V_313 ] ) ;
if ( V_159 < 0 ) {
F_21 ( V_314 L_49 ,
V_6 -> V_51 ) ;
goto V_308;
}
F_21 ( V_314 L_50 ,
V_6 -> V_51 , F_112 ( V_6 -> V_264 ) ) ;
V_6 -> V_266 = F_113 ( V_6 ) ;
return 0 ;
V_308:
F_98 ( V_6 ) ;
return V_159 ;
}
