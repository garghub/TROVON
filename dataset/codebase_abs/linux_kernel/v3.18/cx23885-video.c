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
V_11 -> V_15 . V_16 . V_17 = V_8 -> V_9 ++ ;
F_6 ( & V_11 -> V_15 . V_16 . V_18 ) ;
F_7 ( 2 , L_1 , V_11 , V_11 -> V_15 . V_16 . V_19 ,
V_9 , V_8 -> V_9 ) ;
F_8 ( & V_11 -> V_14 ) ;
F_9 ( & V_11 -> V_15 , V_20 ) ;
}
int F_10 ( struct V_5 * V_6 , T_2 V_21 )
{
F_7 ( 1 , L_2 ,
V_22 ,
( unsigned int ) V_21 ,
F_11 ( V_21 ) ) ;
if ( V_6 -> V_23 != V_21 ) {
if ( F_12 ( & V_6 -> V_24 ) || F_12 ( & V_6 -> V_25 ) ||
F_12 ( & V_6 -> V_26 ) )
return - V_27 ;
}
V_6 -> V_23 = V_21 ;
F_13 ( V_6 , V_28 , V_29 , V_21 ) ;
return 0 ;
}
static struct V_30 * F_14 ( struct V_5 * V_6 ,
struct V_31 * V_32 ,
struct V_30 * V_33 ,
char * type )
{
struct V_30 * V_34 ;
F_7 ( 1 , L_3 , V_22 ) ;
V_34 = F_15 () ;
if ( NULL == V_34 )
return NULL ;
* V_34 = * V_33 ;
V_34 -> V_35 = & V_6 -> V_35 ;
V_34 -> V_36 = V_37 ;
V_34 -> V_38 = & V_6 -> V_38 ;
snprintf ( V_34 -> V_39 , sizeof( V_34 -> V_39 ) , L_4 ,
V_40 [ V_6 -> V_41 ] . V_39 , type ) ;
F_16 ( V_34 , V_6 ) ;
return V_34 ;
}
int F_17 ( struct V_5 * V_6 , T_3 V_42 , T_3 V_43 )
{
T_3 V_11 [] = { V_42 , V_43 } ;
struct V_44 V_45 = { . V_46 = 0x98 >> 1 ,
. V_47 = 0 , . V_11 = V_11 , . V_48 = 2 } ;
return F_18 ( & V_6 -> V_49 [ 2 ] . V_50 , & V_45 , 1 ) ;
}
T_3 F_19 ( struct V_5 * V_6 , T_3 V_42 )
{
int V_51 ;
T_3 V_52 [] = { V_42 } ;
T_3 V_53 [] = { 0 } ;
struct V_44 V_45 [] = {
{ . V_46 = 0x98 >> 1 , . V_47 = 0 , . V_11 = V_52 , . V_48 = 1 } ,
{ . V_46 = 0x98 >> 1 , . V_47 = V_54 , . V_11 = V_53 , . V_48 = 1 }
} ;
V_51 = F_18 ( & V_6 -> V_49 [ 2 ] . V_50 , & V_45 [ 0 ] , 2 ) ;
if ( V_51 != 2 )
F_20 ( V_55 L_5 , V_22 ) ;
return V_53 [ 0 ] ;
}
static void F_21 ( struct V_5 * V_6 )
{
int V_3 ;
F_7 ( 1 , L_6 ) ;
for ( V_3 = 0 ; V_3 < 0x24 ; V_3 ++ ) {
F_7 ( 1 , L_7 , V_3 ,
F_19 ( V_6 , V_3 ) ) ;
}
}
static int F_22 ( struct V_5 * V_6 , int V_56 )
{
T_3 V_57 ;
F_7 ( 1 , L_8 , V_22 , V_56 ) ;
if ( V_56 == 1 )
V_57 = F_19 ( V_6 , V_58 ) & ~ V_59 ;
else if ( V_56 == 2 )
V_57 = F_19 ( V_6 , V_58 ) | V_59 ;
else
return - V_60 ;
V_57 |= 0x20 ;
F_17 ( V_6 , V_58 , V_57 ) ;
F_17 ( V_6 , V_61 , 0 ) ;
if ( V_62 )
F_21 ( V_6 ) ;
return 0 ;
}
static int F_23 ( struct V_5 * V_6 , unsigned int V_56 )
{
F_7 ( 1 , L_9 ,
V_22 ,
V_56 , F_24 ( V_56 ) -> V_63 ,
F_24 ( V_56 ) -> V_64 , F_24 ( V_56 ) -> V_65 ,
F_24 ( V_56 ) -> V_66 , F_24 ( V_56 ) -> V_67 ) ;
V_6 -> V_56 = V_56 ;
if ( V_6 -> V_41 == V_68 ||
V_6 -> V_41 == V_69 ||
V_6 -> V_41 == V_70 ) {
if ( F_24 ( V_56 ) -> type == V_71 )
F_25 ( V_6 , V_72 ) ;
}
F_26 ( V_6 -> V_73 , V_28 , V_74 ,
F_24 ( V_56 ) -> V_63 , 0 , 0 ) ;
if ( ( V_6 -> V_41 == V_75 ) ||
( V_6 -> V_41 == V_76 ) ||
( V_6 -> V_41 == V_77 ) ||
( V_6 -> V_41 == V_78 ) ||
( V_6 -> V_41 == V_79 ) ||
( V_6 -> V_41 == V_80 ) ||
( V_6 -> V_41 == V_81 ) ||
( V_6 -> V_41 == V_70 ) ||
( V_6 -> V_41 == V_82 ) ) {
F_26 ( V_6 -> V_73 , V_83 , V_74 ,
F_24 ( V_56 ) -> V_84 , 0 , 0 ) ;
if ( F_24 ( V_56 ) -> V_84 == V_85 )
F_22 ( V_6 , 1 ) ;
else if ( F_24 ( V_56 ) -> V_84 == V_86 )
F_22 ( V_6 , 2 ) ;
}
return 0 ;
}
static int F_27 ( struct V_5 * V_6 , unsigned int V_56 )
{
F_7 ( 1 , L_10 , V_22 , V_56 ) ;
if ( F_24 ( V_56 ) -> V_84 == V_85 )
F_22 ( V_6 , 1 ) ;
else if ( F_24 ( V_56 ) -> V_84 == V_86 )
F_22 ( V_6 , 2 ) ;
else {
F_22 ( V_6 , 1 ) ;
}
return 0 ;
}
static int F_28 ( struct V_5 * V_6 ,
struct V_7 * V_8 ,
struct V_10 * V_11 )
{
F_7 ( 1 , L_3 , V_22 ) ;
F_29 ( V_87 , 0x11 ) ;
F_30 ( V_6 , & V_6 -> V_88 [ V_89 ] ,
V_11 -> V_90 , V_11 -> V_91 . V_92 ) ;
F_31 ( V_93 , 3 ) ;
V_8 -> V_9 = 0 ;
F_32 ( V_6 , 0x01 ) ;
F_33 ( V_94 , 0x000011 ) ;
F_33 ( V_95 , ( 1 << 5 ) ) ;
F_33 ( V_87 , 0x11 ) ;
return 0 ;
}
static int F_34 ( struct V_96 * V_8 , const struct V_97 * V_98 ,
unsigned int * V_99 , unsigned int * V_100 ,
unsigned int V_101 [] , void * V_102 [] )
{
struct V_5 * V_6 = V_8 -> V_103 ;
* V_100 = 1 ;
V_101 [ 0 ] = ( V_6 -> V_98 -> V_104 * V_6 -> V_105 * V_6 -> V_106 ) >> 3 ;
return 0 ;
}
static int F_35 ( struct V_107 * V_15 )
{
struct V_5 * V_6 = V_15 -> V_96 -> V_103 ;
struct V_10 * V_11 =
F_36 ( V_15 , struct V_10 , V_15 ) ;
T_1 V_108 , V_109 ;
struct V_110 * V_111 = F_37 ( V_15 , 0 ) ;
int V_112 ;
int V_51 ;
V_11 -> V_90 = ( V_6 -> V_105 * V_6 -> V_98 -> V_104 ) >> 3 ;
if ( F_38 ( V_15 , 0 ) < V_6 -> V_106 * V_11 -> V_90 )
return - V_60 ;
F_39 ( V_15 , 0 , V_6 -> V_106 * V_11 -> V_90 ) ;
V_51 = F_40 ( & V_6 -> V_32 -> V_6 , V_111 -> V_113 , V_111 -> V_114 , V_115 ) ;
if ( ! V_51 )
return - V_116 ;
switch ( V_6 -> V_117 ) {
case V_118 :
F_41 ( V_6 -> V_32 , & V_11 -> V_91 ,
V_111 -> V_113 , 0 , V_119 ,
V_11 -> V_90 , 0 , V_6 -> V_106 ) ;
break;
case V_120 :
F_41 ( V_6 -> V_32 , & V_11 -> V_91 ,
V_111 -> V_113 , V_119 , 0 ,
V_11 -> V_90 , 0 , V_6 -> V_106 ) ;
break;
case V_121 :
if ( V_6 -> V_23 & V_122 )
V_112 = 1 ;
else
V_112 = 0 ;
if ( V_40 [ V_6 -> V_41 ] . V_123 )
V_112 = 0 ;
if ( V_112 ) {
F_7 ( 1 , L_11 ,
V_22 ) ;
V_108 = V_11 -> V_90 ;
V_109 = 0 ;
} else {
F_7 ( 1 , L_12 ,
V_22 ) ;
V_108 = 0 ;
V_109 = V_11 -> V_90 ;
}
F_41 ( V_6 -> V_32 , & V_11 -> V_91 ,
V_111 -> V_113 , V_108 ,
V_109 ,
V_11 -> V_90 , V_11 -> V_90 ,
V_6 -> V_106 >> 1 ) ;
break;
case V_124 :
F_41 ( V_6 -> V_32 , & V_11 -> V_91 ,
V_111 -> V_113 ,
0 , V_11 -> V_90 * ( V_6 -> V_106 >> 1 ) ,
V_11 -> V_90 , 0 ,
V_6 -> V_106 >> 1 ) ;
break;
case V_125 :
F_41 ( V_6 -> V_32 , & V_11 -> V_91 ,
V_111 -> V_113 ,
V_11 -> V_90 * ( V_6 -> V_106 >> 1 ) , 0 ,
V_11 -> V_90 , 0 ,
V_6 -> V_106 >> 1 ) ;
break;
default:
F_42 () ;
}
F_7 ( 2 , L_13 ,
V_11 , V_11 -> V_15 . V_16 . V_19 ,
V_6 -> V_105 , V_6 -> V_106 , V_6 -> V_98 -> V_104 , V_6 -> V_98 -> V_39 ,
( unsigned long ) V_11 -> V_91 . V_92 ) ;
return 0 ;
}
static void F_43 ( struct V_107 * V_15 )
{
struct V_5 * V_6 = V_15 -> V_96 -> V_103 ;
struct V_10 * V_11 = F_36 ( V_15 ,
struct V_10 , V_15 ) ;
struct V_110 * V_111 = F_37 ( V_15 , 0 ) ;
F_44 ( V_15 -> V_96 -> V_103 , V_11 ) ;
F_45 ( & V_6 -> V_32 -> V_6 , V_111 -> V_113 , V_111 -> V_114 , V_115 ) ;
}
static void F_46 ( struct V_107 * V_15 )
{
struct V_5 * V_6 = V_15 -> V_96 -> V_103 ;
struct V_10 * V_11 = F_36 ( V_15 ,
struct V_10 , V_15 ) ;
struct V_10 * V_126 ;
struct V_7 * V_8 = & V_6 -> V_127 ;
unsigned long V_47 ;
V_11 -> V_91 . V_128 [ 1 ] = F_47 ( V_11 -> V_91 . V_92 + 12 ) ;
V_11 -> V_91 . V_129 [ 0 ] = F_47 ( V_130 | V_131 ) ;
V_11 -> V_91 . V_129 [ 1 ] = F_47 ( V_11 -> V_91 . V_92 + 12 ) ;
V_11 -> V_91 . V_129 [ 2 ] = F_47 ( 0 ) ;
F_48 ( & V_6 -> V_132 , V_47 ) ;
if ( F_4 ( & V_8 -> V_12 ) ) {
F_49 ( & V_11 -> V_14 , & V_8 -> V_12 ) ;
F_7 ( 2 , L_14 ,
V_11 , V_11 -> V_15 . V_16 . V_19 ) ;
} else {
V_11 -> V_91 . V_128 [ 0 ] |= F_47 ( V_133 ) ;
V_126 = F_5 ( V_8 -> V_12 . V_126 , struct V_10 ,
V_14 ) ;
F_49 ( & V_11 -> V_14 , & V_8 -> V_12 ) ;
V_126 -> V_91 . V_129 [ 1 ] = F_47 ( V_11 -> V_91 . V_92 ) ;
F_7 ( 2 , L_15 ,
V_11 , V_11 -> V_15 . V_16 . V_19 ) ;
}
F_50 ( & V_6 -> V_132 , V_47 ) ;
}
static int F_51 ( struct V_96 * V_8 , unsigned int V_9 )
{
struct V_5 * V_6 = V_8 -> V_103 ;
struct V_7 * V_134 = & V_6 -> V_127 ;
struct V_10 * V_11 = F_5 ( V_134 -> V_12 . V_13 ,
struct V_10 , V_14 ) ;
F_28 ( V_6 , V_134 , V_11 ) ;
return 0 ;
}
static void F_52 ( struct V_96 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_103 ;
struct V_7 * V_134 = & V_6 -> V_127 ;
unsigned long V_47 ;
F_29 ( V_87 , 0x11 ) ;
F_48 ( & V_6 -> V_132 , V_47 ) ;
while ( ! F_4 ( & V_134 -> V_12 ) ) {
struct V_10 * V_11 = F_5 ( V_134 -> V_12 . V_13 ,
struct V_10 , V_14 ) ;
F_8 ( & V_11 -> V_14 ) ;
F_9 ( & V_11 -> V_15 , V_135 ) ;
}
F_50 ( & V_6 -> V_132 , V_47 ) ;
}
static int F_53 ( struct V_136 * V_136 , void * V_137 ,
struct V_97 * V_138 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
V_138 -> V_98 . V_139 . V_105 = V_6 -> V_105 ;
V_138 -> V_98 . V_139 . V_106 = V_6 -> V_106 ;
V_138 -> V_98 . V_139 . V_117 = V_6 -> V_117 ;
V_138 -> V_98 . V_139 . V_140 = V_6 -> V_98 -> V_2 ;
V_138 -> V_98 . V_139 . V_141 =
( V_138 -> V_98 . V_139 . V_105 * V_6 -> V_98 -> V_104 ) >> 3 ;
V_138 -> V_98 . V_139 . V_142 =
V_138 -> V_98 . V_139 . V_106 * V_138 -> V_98 . V_139 . V_141 ;
V_138 -> V_98 . V_139 . V_143 = V_144 ;
return 0 ;
}
static int F_55 ( struct V_136 * V_136 , void * V_137 ,
struct V_97 * V_138 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
struct V_1 * V_98 ;
enum V_145 V_117 ;
unsigned int V_146 , V_147 ;
V_98 = F_1 ( V_138 -> V_98 . V_139 . V_140 ) ;
if ( NULL == V_98 )
return - V_60 ;
V_117 = V_138 -> V_98 . V_139 . V_117 ;
V_146 = F_56 ( V_6 -> V_23 ) ;
V_147 = F_57 ( V_6 -> V_23 ) ;
if ( V_148 == V_117 ) {
V_117 = ( V_138 -> V_98 . V_139 . V_106 > V_147 / 2 )
? V_121
: V_120 ;
}
switch ( V_117 ) {
case V_118 :
case V_120 :
V_147 = V_147 / 2 ;
break;
case V_121 :
case V_124 :
case V_125 :
break;
default:
V_117 = V_121 ;
break;
}
V_138 -> V_98 . V_139 . V_117 = V_117 ;
F_58 ( & V_138 -> V_98 . V_139 . V_105 , 48 , V_146 , 2 ,
& V_138 -> V_98 . V_139 . V_106 , 32 , V_147 , 0 , 0 ) ;
V_138 -> V_98 . V_139 . V_141 =
( V_138 -> V_98 . V_139 . V_105 * V_98 -> V_104 ) >> 3 ;
V_138 -> V_98 . V_139 . V_142 =
V_138 -> V_98 . V_139 . V_106 * V_138 -> V_98 . V_139 . V_141 ;
V_138 -> V_98 . V_139 . V_143 = V_144 ;
return 0 ;
}
static int F_59 ( struct V_136 * V_136 , void * V_137 ,
struct V_97 * V_138 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
struct V_149 V_150 ;
int V_151 ;
F_7 ( 2 , L_3 , V_22 ) ;
V_151 = F_55 ( V_136 , V_137 , V_138 ) ;
if ( 0 != V_151 )
return V_151 ;
if ( F_12 ( & V_6 -> V_24 ) || F_12 ( & V_6 -> V_25 ) ||
F_12 ( & V_6 -> V_26 ) )
return - V_27 ;
V_6 -> V_98 = F_1 ( V_138 -> V_98 . V_139 . V_140 ) ;
V_6 -> V_105 = V_138 -> V_98 . V_139 . V_105 ;
V_6 -> V_106 = V_138 -> V_98 . V_139 . V_106 ;
V_6 -> V_117 = V_138 -> V_98 . V_139 . V_117 ;
F_7 ( 2 , L_16 , V_22 ,
V_6 -> V_105 , V_6 -> V_106 , V_6 -> V_117 ) ;
F_60 ( & V_150 , & V_138 -> V_98 . V_139 , V_152 ) ;
F_13 ( V_6 , V_28 , V_153 , & V_150 ) ;
F_61 ( & V_138 -> V_98 . V_139 , & V_150 ) ;
V_138 -> V_98 . V_139 . V_117 = V_6 -> V_117 ;
return 0 ;
}
static int F_62 ( struct V_136 * V_136 , void * V_137 ,
struct V_154 * V_155 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
struct V_30 * V_156 = F_63 ( V_136 ) ;
strcpy ( V_155 -> V_157 , L_17 ) ;
F_64 ( V_155 -> V_158 , V_40 [ V_6 -> V_41 ] . V_39 ,
sizeof( V_155 -> V_158 ) ) ;
sprintf ( V_155 -> V_159 , L_18 , F_65 ( V_6 -> V_32 ) ) ;
V_155 -> V_160 = V_161 | V_162 | V_163 ;
if ( V_6 -> V_164 != V_165 )
V_155 -> V_160 |= V_166 ;
if ( V_156 -> V_167 == V_168 )
V_155 -> V_160 |= V_169 ;
else
V_155 -> V_160 |= V_170 ;
V_155 -> V_171 = V_155 -> V_160 | V_169 |
V_170 | V_172 ;
return 0 ;
}
static int F_66 ( struct V_136 * V_136 , void * V_137 ,
struct V_173 * V_138 )
{
if ( F_67 ( V_138 -> V_19 >= F_2 ( V_4 ) ) )
return - V_60 ;
F_64 ( V_138 -> V_174 , V_4 [ V_138 -> V_19 ] . V_39 ,
sizeof( V_138 -> V_174 ) ) ;
V_138 -> V_140 = V_4 [ V_138 -> V_19 ] . V_2 ;
return 0 ;
}
static int F_68 ( struct V_136 * V_136 , void * V_137 , T_2 * V_175 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
F_7 ( 1 , L_3 , V_22 ) ;
* V_175 = V_6 -> V_23 ;
return 0 ;
}
static int F_69 ( struct V_136 * V_136 , void * V_137 , T_2 V_176 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
F_7 ( 1 , L_3 , V_22 ) ;
return F_10 ( V_6 , V_176 ) ;
}
int F_70 ( struct V_5 * V_6 , struct V_177 * V_3 )
{
static const char * V_178 [] = {
[ V_179 ] = L_19 ,
[ V_180 ] = L_20 ,
[ V_181 ] = L_21 ,
[ V_182 ] = L_22 ,
[ V_183 ] = L_23 ,
[ V_184 ] = L_24 ,
[ V_71 ] = L_25 ,
[ V_185 ] = L_26 ,
[ V_186 ] = L_27 ,
[ V_187 ] = L_28 ,
} ;
unsigned int V_188 ;
F_7 ( 1 , L_3 , V_22 ) ;
V_188 = V_3 -> V_19 ;
if ( V_188 >= V_189 )
return - V_60 ;
if ( 0 == F_24 ( V_188 ) -> type )
return - V_60 ;
V_3 -> V_19 = V_188 ;
V_3 -> type = V_190 ;
strcpy ( V_3 -> V_39 , V_178 [ F_24 ( V_188 ) -> type ] ) ;
V_3 -> V_191 = V_192 ;
if ( ( V_71 == F_24 ( V_188 ) -> type ) ||
( V_185 == F_24 ( V_188 ) -> type ) ) {
V_3 -> type = V_193 ;
V_3 -> V_194 = 4 ;
} else {
V_3 -> V_194 = 3 ;
}
if ( V_6 -> V_56 == V_188 ) {
F_13 ( V_6 , V_28 , V_195 , & V_3 -> V_196 ) ;
}
return 0 ;
}
static int F_71 ( struct V_136 * V_136 , void * V_137 ,
struct V_177 * V_3 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
F_7 ( 1 , L_3 , V_22 ) ;
return F_70 ( V_6 , V_3 ) ;
}
int F_72 ( struct V_136 * V_136 , void * V_137 , unsigned int * V_3 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
* V_3 = V_6 -> V_56 ;
F_7 ( 1 , L_29 , V_22 , * V_3 ) ;
return 0 ;
}
static int F_73 ( struct V_136 * V_136 , void * V_137 , unsigned int * V_3 )
{
return F_72 ( V_136 , V_137 , V_3 ) ;
}
int F_74 ( struct V_136 * V_136 , void * V_137 , unsigned int V_3 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
F_7 ( 1 , L_30 , V_22 , V_3 ) ;
if ( V_3 >= V_189 ) {
F_7 ( 1 , L_31 , V_22 ) ;
return - V_60 ;
}
if ( F_24 ( V_3 ) -> type == 0 )
return - V_60 ;
F_23 ( V_6 , V_3 ) ;
F_27 ( V_6 , V_3 ) ;
return 0 ;
}
static int F_75 ( struct V_136 * V_136 , void * V_137 , unsigned int V_3 )
{
return F_74 ( V_136 , V_137 , V_3 ) ;
}
static int F_76 ( struct V_136 * V_136 , void * V_137 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
F_13 ( V_6 , V_197 , V_198 ) ;
return 0 ;
}
static int F_77 ( struct V_136 * V_136 , void * V_137 ,
struct V_199 * V_3 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
static const char * V_178 [] = {
[ 0 ] = L_32 ,
[ 1 ] = L_33 ,
[ 2 ] = L_34 ,
} ;
unsigned int V_188 ;
F_7 ( 1 , L_3 , V_22 ) ;
V_188 = V_3 -> V_19 ;
if ( V_188 >= 3 )
return - V_60 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_19 = V_188 ;
strcpy ( V_3 -> V_39 , V_178 [ V_188 ] ) ;
V_3 -> V_200 = V_201 ;
return 0 ;
}
static int F_78 ( struct V_136 * V_136 , void * V_137 ,
struct V_199 * V_3 )
{
return F_77 ( V_136 , V_137 , V_3 ) ;
}
static int F_79 ( struct V_136 * V_136 , void * V_137 ,
struct V_199 * V_3 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
if ( ( V_71 == F_24 ( V_6 -> V_56 ) -> type ) ||
( V_185 == F_24 ( V_6 -> V_56 ) -> type ) )
V_3 -> V_19 = 2 ;
else
V_3 -> V_19 = V_6 -> V_202 ;
F_7 ( 1 , L_10 , V_22 , V_3 -> V_19 ) ;
return F_77 ( V_136 , V_137 , V_3 ) ;
}
static int F_80 ( struct V_136 * V_136 , void * V_137 ,
const struct V_199 * V_3 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
if ( ( V_71 == F_24 ( V_6 -> V_56 ) -> type ) ||
( V_185 == F_24 ( V_6 -> V_56 ) -> type ) ) {
return V_3 -> V_19 != 2 ? - V_60 : 0 ;
}
if ( V_3 -> V_19 > 1 )
return - V_60 ;
F_7 ( 1 , L_30 , V_22 , V_3 -> V_19 ) ;
V_6 -> V_202 = V_3 -> V_19 ;
F_22 ( V_6 , V_6 -> V_202 + 1 ) ;
return 0 ;
}
static int F_81 ( struct V_136 * V_136 , void * V_137 ,
struct V_203 * V_204 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
if ( V_6 -> V_164 == V_165 )
return - V_60 ;
if ( 0 != V_204 -> V_19 )
return - V_60 ;
strcpy ( V_204 -> V_39 , L_25 ) ;
F_13 ( V_6 , V_205 , V_206 , V_204 ) ;
return 0 ;
}
static int F_82 ( struct V_136 * V_136 , void * V_137 ,
const struct V_203 * V_204 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
if ( V_6 -> V_164 == V_165 )
return - V_60 ;
if ( 0 != V_204 -> V_19 )
return - V_60 ;
F_13 ( V_6 , V_205 , V_207 , V_204 ) ;
return 0 ;
}
static int F_83 ( struct V_136 * V_136 , void * V_137 ,
struct V_208 * V_138 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
if ( V_6 -> V_164 == V_165 )
return - V_60 ;
V_138 -> type = V_209 ;
V_138 -> V_210 = V_6 -> V_211 ;
F_13 ( V_6 , V_205 , V_212 , V_138 ) ;
return 0 ;
}
static int F_84 ( struct V_5 * V_6 , const struct V_208 * V_138 )
{
struct V_213 * V_214 ;
int V_215 = 1 ;
if ( V_6 -> V_164 == V_165 )
return - V_60 ;
if ( F_67 ( V_138 -> V_205 != 0 ) )
return - V_60 ;
V_6 -> V_211 = V_138 -> V_210 ;
V_214 = F_85 ( & V_6 -> V_216 , V_217 ) ;
if ( V_214 ) {
V_215 = F_86 ( V_214 ) ;
if ( ! V_215 )
F_87 ( V_214 , 1 ) ;
}
F_13 ( V_6 , V_205 , V_218 , V_138 ) ;
F_88 ( 100 ) ;
if ( V_215 == 0 )
F_87 ( V_214 , V_215 ) ;
return 0 ;
}
static int F_89 ( struct V_5 * V_6 ,
const struct V_208 * V_138 )
{
struct V_213 * V_214 ;
int V_215 = 1 ;
struct V_219 * V_220 ;
struct V_221 * V_222 ;
struct V_223 V_224 = {
. V_225 = V_209 ,
. V_226 = V_227 ,
. V_191 = V_6 -> V_23 ,
. V_210 = V_138 -> V_210
} ;
V_6 -> V_211 = V_138 -> V_210 ;
V_214 = F_85 ( & V_6 -> V_216 , V_217 ) ;
if ( V_214 ) {
V_215 = F_86 ( V_214 ) ;
if ( ! V_215 )
F_87 ( V_214 , 1 ) ;
}
F_7 ( 1 , L_35 , V_22 ,
V_224 . V_210 , V_138 -> V_205 , V_224 . V_191 ) ;
V_220 = F_90 ( & V_6 -> V_228 . V_229 , 1 ) ;
if ( ! V_220 ) {
return - V_60 ;
}
V_222 = V_220 -> V_230 . V_231 ;
if ( ( V_6 -> V_41 == V_81 ) ||
( V_6 -> V_41 == V_79 ) ||
( V_6 -> V_41 == V_80 ) )
V_222 = & V_6 -> V_232 . V_233 ;
if ( V_222 && V_222 -> V_234 . V_235 . V_236 ) {
F_13 ( V_6 , V_28 , V_29 , V_6 -> V_23 ) ;
V_222 -> V_234 . V_235 . V_236 ( V_222 , & V_224 ) ;
}
else
F_20 ( V_55 L_36 , V_22 ) ;
F_88 ( 100 ) ;
if ( V_215 == 0 )
F_87 ( V_214 , V_215 ) ;
return 0 ;
}
int F_91 ( struct V_136 * V_136 , void * V_137 ,
const struct V_208 * V_138 )
{
struct V_5 * V_6 = F_54 ( V_136 ) ;
int V_51 ;
switch ( V_6 -> V_41 ) {
case V_79 :
case V_80 :
case V_81 :
V_51 = F_89 ( V_6 , V_138 ) ;
break;
default:
V_51 = F_84 ( V_6 , V_138 ) ;
}
return V_51 ;
}
static int F_92 ( struct V_136 * V_136 , void * V_137 ,
const struct V_208 * V_138 )
{
return F_91 ( V_136 , V_137 , V_138 ) ;
}
int F_93 ( struct V_5 * V_6 , T_1 V_196 )
{
T_1 V_237 , V_9 ;
int V_238 = 0 ;
V_237 = F_94 ( V_94 ) ;
if ( 0 == ( V_196 & V_237 ) )
return V_238 ;
F_31 ( V_239 , V_196 ) ;
if ( ( V_196 & V_240 ) ||
( V_196 & V_241 ) ||
( V_196 & V_242 ) ) {
if ( V_196 & V_240 ) {
F_7 ( 7 , L_37 ,
V_240 ) ;
F_20 ( V_243 L_38 ,
V_6 -> V_39 ) ;
F_95 ( V_6 ,
& V_6 -> V_88 [ V_89 ] ) ;
}
if ( V_196 & V_241 )
F_7 ( 7 , L_39
L_40 ,
V_241 ) ;
if ( V_196 & V_242 )
F_7 ( 7 , L_41 ,
V_242 ) ;
}
if ( V_196 & V_244 ) {
F_96 ( & V_6 -> V_132 ) ;
V_9 = F_94 ( V_245 ) ;
F_3 ( V_6 , & V_6 -> V_127 , V_9 ) ;
F_97 ( & V_6 -> V_132 ) ;
V_238 ++ ;
}
V_238 += F_98 ( V_6 , V_196 ) ;
return V_238 ;
}
void F_99 ( struct V_5 * V_6 )
{
F_7 ( 1 , L_3 , V_22 ) ;
F_100 ( V_6 , 0x01 ) ;
if ( V_6 -> V_246 ) {
if ( F_101 ( V_6 -> V_246 ) )
F_102 ( V_6 -> V_246 ) ;
else
V_37 ( V_6 -> V_246 ) ;
V_6 -> V_246 = NULL ;
}
if ( V_6 -> V_247 ) {
if ( F_101 ( V_6 -> V_247 ) )
F_102 ( V_6 -> V_247 ) ;
else
V_37 ( V_6 -> V_247 ) ;
V_6 -> V_247 = NULL ;
}
if ( V_6 -> V_248 )
F_103 ( V_6 ) ;
}
int F_104 ( struct V_5 * V_6 )
{
struct V_96 * V_8 ;
int V_151 ;
F_7 ( 1 , L_3 , V_22 ) ;
F_105 ( & V_6 -> V_132 ) ;
V_249 = V_250 ;
strcpy ( V_249 . V_39 , L_42 ) ;
V_6 -> V_23 = V_251 ;
V_6 -> V_98 = F_1 ( V_252 ) ;
V_6 -> V_117 = V_121 ;
V_6 -> V_105 = 720 ;
V_6 -> V_106 = F_57 ( V_6 -> V_23 ) ;
F_106 ( & V_6 -> V_127 . V_12 ) ;
F_106 ( & V_6 -> V_253 . V_12 ) ;
F_32 ( V_6 , 0x01 ) ;
if ( ( V_165 != V_6 -> V_164 ) &&
( ( V_6 -> V_254 == 0 ) || ( V_6 -> V_254 == 1 ) ) ) {
struct V_255 * V_256 = NULL ;
if ( V_6 -> V_257 )
V_256 = F_107 ( & V_6 -> V_35 ,
& V_6 -> V_49 [ V_6 -> V_254 ] . V_50 ,
L_43 , V_6 -> V_257 , NULL ) ;
else
V_256 = F_107 ( & V_6 -> V_35 ,
& V_6 -> V_49 [ V_6 -> V_254 ] . V_50 ,
L_43 , 0 , F_108 ( V_258 ) ) ;
if ( V_256 ) {
struct V_259 V_260 ;
memset ( & V_260 , 0 , sizeof( V_260 ) ) ;
V_260 . V_261 = V_262 ;
V_260 . type = V_6 -> V_164 ;
V_260 . V_46 = F_109 ( V_256 ) ;
V_260 . V_263 = V_264 ;
F_26 ( V_256 , V_205 , V_265 , & V_260 ) ;
if ( ( V_6 -> V_41 == V_266 ) ||
( V_6 -> V_41 == V_267 ) ) {
struct V_268 V_269 = {
. V_270 = V_271 ,
. V_272 = 64
} ;
struct V_273 V_274 = {
. V_205 = V_6 -> V_164 ,
. V_137 = & V_269
} ;
F_26 ( V_256 , V_205 , V_275 , & V_274 ) ;
}
if ( V_6 -> V_41 == V_82 ) {
struct V_268 V_269 = {
. V_270 = L_44 ,
. V_272 = 64
} ;
struct V_273 V_274 = {
. V_205 = V_6 -> V_164 ,
. V_137 = & V_269
} ;
F_26 ( V_256 , V_205 , V_275 , & V_274 ) ;
}
}
}
F_110 ( & V_6 -> V_38 ) ;
F_10 ( V_6 , V_6 -> V_23 ) ;
F_23 ( V_6 , 0 ) ;
F_27 ( V_6 , 0 ) ;
F_111 ( & V_6 -> V_38 ) ;
V_8 = & V_6 -> V_24 ;
V_8 -> type = V_276 ;
V_8 -> V_277 = V_278 | V_279 | V_280 | V_281 ;
V_8 -> V_282 = V_283 ;
V_8 -> V_284 = 2 ;
V_8 -> V_103 = V_6 ;
V_8 -> V_285 = sizeof( struct V_10 ) ;
V_8 -> V_234 = & V_286 ;
V_8 -> V_287 = & V_288 ;
V_8 -> V_289 = V_290 ;
V_8 -> V_38 = & V_6 -> V_38 ;
V_151 = F_112 ( V_8 ) ;
if ( V_151 < 0 )
goto V_291;
V_8 = & V_6 -> V_25 ;
V_8 -> type = V_292 ;
V_8 -> V_277 = V_278 | V_279 | V_280 | V_281 ;
V_8 -> V_282 = V_283 ;
V_8 -> V_284 = 2 ;
V_8 -> V_103 = V_6 ;
V_8 -> V_285 = sizeof( struct V_10 ) ;
V_8 -> V_234 = & V_293 ;
V_8 -> V_287 = & V_288 ;
V_8 -> V_289 = V_290 ;
V_8 -> V_38 = & V_6 -> V_38 ;
V_151 = F_112 ( V_8 ) ;
if ( V_151 < 0 )
goto V_291;
V_6 -> V_247 = F_14 ( V_6 , V_6 -> V_32 ,
& V_250 , L_45 ) ;
V_6 -> V_247 -> V_14 = & V_6 -> V_24 ;
V_151 = F_113 ( V_6 -> V_247 , V_294 ,
V_295 [ V_6 -> V_296 ] ) ;
if ( V_151 < 0 ) {
F_20 ( V_297 L_46 ,
V_6 -> V_39 ) ;
goto V_291;
}
F_20 ( V_297 L_47 ,
V_6 -> V_39 , F_114 ( V_6 -> V_247 ) ) ;
V_6 -> V_246 = F_14 ( V_6 , V_6 -> V_32 ,
& V_249 , L_48 ) ;
V_6 -> V_246 -> V_14 = & V_6 -> V_25 ;
V_151 = F_113 ( V_6 -> V_246 , V_168 ,
V_298 [ V_6 -> V_296 ] ) ;
if ( V_151 < 0 ) {
F_20 ( V_297 L_49 ,
V_6 -> V_39 ) ;
goto V_291;
}
F_20 ( V_297 L_50 ,
V_6 -> V_39 , F_114 ( V_6 -> V_246 ) ) ;
V_6 -> V_248 = F_115 ( V_6 ) ;
return 0 ;
V_291:
F_99 ( V_6 ) ;
return V_151 ;
}
