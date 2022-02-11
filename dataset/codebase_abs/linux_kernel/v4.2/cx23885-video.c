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
V_102 [ 0 ] = V_6 -> V_107 ;
return 0 ;
}
static int F_35 ( struct V_108 * V_15 )
{
struct V_5 * V_6 = V_15 -> V_96 -> V_103 ;
struct V_10 * V_11 =
F_36 ( V_15 , struct V_10 , V_15 ) ;
T_1 V_109 , V_110 ;
struct V_111 * V_112 = F_37 ( V_15 , 0 ) ;
int V_113 ;
V_11 -> V_90 = ( V_6 -> V_105 * V_6 -> V_98 -> V_104 ) >> 3 ;
if ( F_38 ( V_15 , 0 ) < V_6 -> V_106 * V_11 -> V_90 )
return - V_60 ;
F_39 ( V_15 , 0 , V_6 -> V_106 * V_11 -> V_90 ) ;
switch ( V_6 -> V_114 ) {
case V_115 :
F_40 ( V_6 -> V_32 , & V_11 -> V_91 ,
V_112 -> V_116 , 0 , V_117 ,
V_11 -> V_90 , 0 , V_6 -> V_106 ) ;
break;
case V_118 :
F_40 ( V_6 -> V_32 , & V_11 -> V_91 ,
V_112 -> V_116 , V_117 , 0 ,
V_11 -> V_90 , 0 , V_6 -> V_106 ) ;
break;
case V_119 :
if ( V_6 -> V_23 & V_120 )
V_113 = 1 ;
else
V_113 = 0 ;
if ( V_40 [ V_6 -> V_41 ] . V_121 )
V_113 = 0 ;
if ( V_113 ) {
F_7 ( 1 , L_11 ,
V_22 ) ;
V_109 = V_11 -> V_90 ;
V_110 = 0 ;
} else {
F_7 ( 1 , L_12 ,
V_22 ) ;
V_109 = 0 ;
V_110 = V_11 -> V_90 ;
}
F_40 ( V_6 -> V_32 , & V_11 -> V_91 ,
V_112 -> V_116 , V_109 ,
V_110 ,
V_11 -> V_90 , V_11 -> V_90 ,
V_6 -> V_106 >> 1 ) ;
break;
case V_122 :
F_40 ( V_6 -> V_32 , & V_11 -> V_91 ,
V_112 -> V_116 ,
0 , V_11 -> V_90 * ( V_6 -> V_106 >> 1 ) ,
V_11 -> V_90 , 0 ,
V_6 -> V_106 >> 1 ) ;
break;
case V_123 :
F_40 ( V_6 -> V_32 , & V_11 -> V_91 ,
V_112 -> V_116 ,
V_11 -> V_90 * ( V_6 -> V_106 >> 1 ) , 0 ,
V_11 -> V_90 , 0 ,
V_6 -> V_106 >> 1 ) ;
break;
default:
F_41 () ;
}
F_7 ( 2 , L_13 ,
V_11 , V_11 -> V_15 . V_16 . V_19 ,
V_6 -> V_105 , V_6 -> V_106 , V_6 -> V_98 -> V_104 , V_6 -> V_98 -> V_39 ,
( unsigned long ) V_11 -> V_91 . V_92 ) ;
return 0 ;
}
static void F_42 ( struct V_108 * V_15 )
{
struct V_10 * V_11 = F_36 ( V_15 ,
struct V_10 , V_15 ) ;
F_43 ( V_15 -> V_96 -> V_103 , V_11 ) ;
}
static void F_44 ( struct V_108 * V_15 )
{
struct V_5 * V_6 = V_15 -> V_96 -> V_103 ;
struct V_10 * V_11 = F_36 ( V_15 ,
struct V_10 , V_15 ) ;
struct V_10 * V_124 ;
struct V_7 * V_8 = & V_6 -> V_125 ;
unsigned long V_47 ;
V_11 -> V_91 . V_126 [ 1 ] = F_45 ( V_11 -> V_91 . V_92 + 12 ) ;
V_11 -> V_91 . V_127 [ 0 ] = F_45 ( V_128 | V_129 ) ;
V_11 -> V_91 . V_127 [ 1 ] = F_45 ( V_11 -> V_91 . V_92 + 12 ) ;
V_11 -> V_91 . V_127 [ 2 ] = F_45 ( 0 ) ;
F_46 ( & V_6 -> V_130 , V_47 ) ;
if ( F_4 ( & V_8 -> V_12 ) ) {
F_47 ( & V_11 -> V_14 , & V_8 -> V_12 ) ;
F_7 ( 2 , L_14 ,
V_11 , V_11 -> V_15 . V_16 . V_19 ) ;
} else {
V_11 -> V_91 . V_126 [ 0 ] |= F_45 ( V_131 ) ;
V_124 = F_5 ( V_8 -> V_12 . V_124 , struct V_10 ,
V_14 ) ;
F_47 ( & V_11 -> V_14 , & V_8 -> V_12 ) ;
V_124 -> V_91 . V_127 [ 1 ] = F_45 ( V_11 -> V_91 . V_92 ) ;
F_7 ( 2 , L_15 ,
V_11 , V_11 -> V_15 . V_16 . V_19 ) ;
}
F_48 ( & V_6 -> V_130 , V_47 ) ;
}
static int F_49 ( struct V_96 * V_8 , unsigned int V_9 )
{
struct V_5 * V_6 = V_8 -> V_103 ;
struct V_7 * V_132 = & V_6 -> V_125 ;
struct V_10 * V_11 = F_5 ( V_132 -> V_12 . V_13 ,
struct V_10 , V_14 ) ;
F_28 ( V_6 , V_132 , V_11 ) ;
return 0 ;
}
static void F_50 ( struct V_96 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_103 ;
struct V_7 * V_132 = & V_6 -> V_125 ;
unsigned long V_47 ;
F_29 ( V_87 , 0x11 ) ;
F_46 ( & V_6 -> V_130 , V_47 ) ;
while ( ! F_4 ( & V_132 -> V_12 ) ) {
struct V_10 * V_11 = F_5 ( V_132 -> V_12 . V_13 ,
struct V_10 , V_14 ) ;
F_8 ( & V_11 -> V_14 ) ;
F_9 ( & V_11 -> V_15 , V_133 ) ;
}
F_48 ( & V_6 -> V_130 , V_47 ) ;
}
static int F_51 ( struct V_134 * V_134 , void * V_135 ,
struct V_97 * V_136 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
V_136 -> V_98 . V_137 . V_105 = V_6 -> V_105 ;
V_136 -> V_98 . V_137 . V_106 = V_6 -> V_106 ;
V_136 -> V_98 . V_137 . V_114 = V_6 -> V_114 ;
V_136 -> V_98 . V_137 . V_138 = V_6 -> V_98 -> V_2 ;
V_136 -> V_98 . V_137 . V_139 =
( V_136 -> V_98 . V_137 . V_105 * V_6 -> V_98 -> V_104 ) >> 3 ;
V_136 -> V_98 . V_137 . V_140 =
V_136 -> V_98 . V_137 . V_106 * V_136 -> V_98 . V_137 . V_139 ;
V_136 -> V_98 . V_137 . V_141 = V_142 ;
return 0 ;
}
static int F_53 ( struct V_134 * V_134 , void * V_135 ,
struct V_97 * V_136 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
struct V_1 * V_98 ;
enum V_143 V_114 ;
unsigned int V_144 , V_145 ;
V_98 = F_1 ( V_136 -> V_98 . V_137 . V_138 ) ;
if ( NULL == V_98 )
return - V_60 ;
V_114 = V_136 -> V_98 . V_137 . V_114 ;
V_144 = F_54 ( V_6 -> V_23 ) ;
V_145 = F_55 ( V_6 -> V_23 ) ;
if ( V_146 == V_114 ) {
V_114 = ( V_136 -> V_98 . V_137 . V_106 > V_145 / 2 )
? V_119
: V_118 ;
}
switch ( V_114 ) {
case V_115 :
case V_118 :
V_145 = V_145 / 2 ;
break;
case V_119 :
case V_122 :
case V_123 :
break;
default:
V_114 = V_119 ;
break;
}
V_136 -> V_98 . V_137 . V_114 = V_114 ;
F_56 ( & V_136 -> V_98 . V_137 . V_105 , 48 , V_144 , 2 ,
& V_136 -> V_98 . V_137 . V_106 , 32 , V_145 , 0 , 0 ) ;
V_136 -> V_98 . V_137 . V_139 =
( V_136 -> V_98 . V_137 . V_105 * V_98 -> V_104 ) >> 3 ;
V_136 -> V_98 . V_137 . V_140 =
V_136 -> V_98 . V_137 . V_106 * V_136 -> V_98 . V_137 . V_139 ;
V_136 -> V_98 . V_137 . V_141 = V_142 ;
return 0 ;
}
static int F_57 ( struct V_134 * V_134 , void * V_135 ,
struct V_97 * V_136 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
struct V_147 V_148 = {
. V_149 = V_150 ,
} ;
int V_151 ;
F_7 ( 2 , L_3 , V_22 ) ;
V_151 = F_53 ( V_134 , V_135 , V_136 ) ;
if ( 0 != V_151 )
return V_151 ;
if ( F_12 ( & V_6 -> V_24 ) || F_12 ( & V_6 -> V_25 ) ||
F_12 ( & V_6 -> V_26 ) )
return - V_27 ;
V_6 -> V_98 = F_1 ( V_136 -> V_98 . V_137 . V_138 ) ;
V_6 -> V_105 = V_136 -> V_98 . V_137 . V_105 ;
V_6 -> V_106 = V_136 -> V_98 . V_137 . V_106 ;
V_6 -> V_114 = V_136 -> V_98 . V_137 . V_114 ;
F_7 ( 2 , L_16 , V_22 ,
V_6 -> V_105 , V_6 -> V_106 , V_6 -> V_114 ) ;
F_58 ( & V_148 . V_148 , & V_136 -> V_98 . V_137 , V_152 ) ;
F_13 ( V_6 , V_153 , V_154 , NULL , & V_148 ) ;
F_59 ( & V_136 -> V_98 . V_137 , & V_148 . V_148 ) ;
V_136 -> V_98 . V_137 . V_114 = V_6 -> V_114 ;
return 0 ;
}
static int F_60 ( struct V_134 * V_134 , void * V_135 ,
struct V_155 * V_156 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
struct V_30 * V_157 = F_61 ( V_134 ) ;
strcpy ( V_156 -> V_158 , L_17 ) ;
F_62 ( V_156 -> V_159 , V_40 [ V_6 -> V_41 ] . V_39 ,
sizeof( V_156 -> V_159 ) ) ;
sprintf ( V_156 -> V_160 , L_18 , F_63 ( V_6 -> V_32 ) ) ;
V_156 -> V_161 = V_162 | V_163 | V_164 ;
if ( V_6 -> V_165 != V_166 )
V_156 -> V_161 |= V_167 ;
if ( V_157 -> V_168 == V_169 )
V_156 -> V_161 |= V_170 ;
else
V_156 -> V_161 |= V_171 ;
V_156 -> V_172 = V_156 -> V_161 | V_170 |
V_171 | V_173 ;
return 0 ;
}
static int F_64 ( struct V_134 * V_134 , void * V_135 ,
struct V_174 * V_136 )
{
if ( F_65 ( V_136 -> V_19 >= F_2 ( V_4 ) ) )
return - V_60 ;
F_62 ( V_136 -> V_175 , V_4 [ V_136 -> V_19 ] . V_39 ,
sizeof( V_136 -> V_175 ) ) ;
V_136 -> V_138 = V_4 [ V_136 -> V_19 ] . V_2 ;
return 0 ;
}
static int F_66 ( struct V_134 * V_134 , void * V_135 , T_2 * V_176 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
F_7 ( 1 , L_3 , V_22 ) ;
* V_176 = V_6 -> V_23 ;
return 0 ;
}
static int F_67 ( struct V_134 * V_134 , void * V_135 , T_2 V_177 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
F_7 ( 1 , L_3 , V_22 ) ;
return F_10 ( V_6 , V_177 ) ;
}
int F_68 ( struct V_5 * V_6 , struct V_178 * V_3 )
{
static const char * V_179 [] = {
[ V_180 ] = L_19 ,
[ V_181 ] = L_20 ,
[ V_182 ] = L_21 ,
[ V_183 ] = L_22 ,
[ V_184 ] = L_23 ,
[ V_185 ] = L_24 ,
[ V_71 ] = L_25 ,
[ V_186 ] = L_26 ,
[ V_187 ] = L_27 ,
[ V_188 ] = L_28 ,
} ;
unsigned int V_189 ;
F_7 ( 1 , L_3 , V_22 ) ;
V_189 = V_3 -> V_19 ;
if ( V_189 >= V_190 )
return - V_60 ;
if ( 0 == F_24 ( V_189 ) -> type )
return - V_60 ;
V_3 -> V_19 = V_189 ;
V_3 -> type = V_191 ;
strcpy ( V_3 -> V_39 , V_179 [ F_24 ( V_189 ) -> type ] ) ;
V_3 -> V_192 = V_193 ;
if ( ( V_71 == F_24 ( V_189 ) -> type ) ||
( V_186 == F_24 ( V_189 ) -> type ) ) {
V_3 -> type = V_194 ;
V_3 -> V_195 = 4 ;
} else {
V_3 -> V_195 = 3 ;
}
if ( V_6 -> V_56 == V_189 ) {
F_13 ( V_6 , V_28 , V_196 , & V_3 -> V_197 ) ;
}
return 0 ;
}
static int F_69 ( struct V_134 * V_134 , void * V_135 ,
struct V_178 * V_3 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
F_7 ( 1 , L_3 , V_22 ) ;
return F_68 ( V_6 , V_3 ) ;
}
int F_70 ( struct V_134 * V_134 , void * V_135 , unsigned int * V_3 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
* V_3 = V_6 -> V_56 ;
F_7 ( 1 , L_29 , V_22 , * V_3 ) ;
return 0 ;
}
static int F_71 ( struct V_134 * V_134 , void * V_135 , unsigned int * V_3 )
{
return F_70 ( V_134 , V_135 , V_3 ) ;
}
int F_72 ( struct V_134 * V_134 , void * V_135 , unsigned int V_3 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
F_7 ( 1 , L_30 , V_22 , V_3 ) ;
if ( V_3 >= V_190 ) {
F_7 ( 1 , L_31 , V_22 ) ;
return - V_60 ;
}
if ( F_24 ( V_3 ) -> type == 0 )
return - V_60 ;
F_23 ( V_6 , V_3 ) ;
F_27 ( V_6 , V_3 ) ;
return 0 ;
}
static int F_73 ( struct V_134 * V_134 , void * V_135 , unsigned int V_3 )
{
return F_72 ( V_134 , V_135 , V_3 ) ;
}
static int F_74 ( struct V_134 * V_134 , void * V_135 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
F_13 ( V_6 , V_198 , V_199 ) ;
return 0 ;
}
static int F_75 ( struct V_134 * V_134 , void * V_135 ,
struct V_200 * V_3 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
static const char * V_179 [] = {
[ 0 ] = L_32 ,
[ 1 ] = L_33 ,
[ 2 ] = L_34 ,
} ;
unsigned int V_189 ;
F_7 ( 1 , L_3 , V_22 ) ;
V_189 = V_3 -> V_19 ;
if ( V_189 >= 3 )
return - V_60 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_19 = V_189 ;
strcpy ( V_3 -> V_39 , V_179 [ V_189 ] ) ;
V_3 -> V_201 = V_202 ;
return 0 ;
}
static int F_76 ( struct V_134 * V_134 , void * V_135 ,
struct V_200 * V_3 )
{
return F_75 ( V_134 , V_135 , V_3 ) ;
}
static int F_77 ( struct V_134 * V_134 , void * V_135 ,
struct V_200 * V_3 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
if ( ( V_71 == F_24 ( V_6 -> V_56 ) -> type ) ||
( V_186 == F_24 ( V_6 -> V_56 ) -> type ) )
V_3 -> V_19 = 2 ;
else
V_3 -> V_19 = V_6 -> V_203 ;
F_7 ( 1 , L_10 , V_22 , V_3 -> V_19 ) ;
return F_75 ( V_134 , V_135 , V_3 ) ;
}
static int F_78 ( struct V_134 * V_134 , void * V_135 ,
const struct V_200 * V_3 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
if ( ( V_71 == F_24 ( V_6 -> V_56 ) -> type ) ||
( V_186 == F_24 ( V_6 -> V_56 ) -> type ) ) {
return V_3 -> V_19 != 2 ? - V_60 : 0 ;
}
if ( V_3 -> V_19 > 1 )
return - V_60 ;
F_7 ( 1 , L_30 , V_22 , V_3 -> V_19 ) ;
V_6 -> V_203 = V_3 -> V_19 ;
F_22 ( V_6 , V_6 -> V_203 + 1 ) ;
return 0 ;
}
static int F_79 ( struct V_134 * V_134 , void * V_135 ,
struct V_204 * V_205 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
if ( V_6 -> V_165 == V_166 )
return - V_60 ;
if ( 0 != V_205 -> V_19 )
return - V_60 ;
strcpy ( V_205 -> V_39 , L_25 ) ;
F_13 ( V_6 , V_206 , V_207 , V_205 ) ;
return 0 ;
}
static int F_80 ( struct V_134 * V_134 , void * V_135 ,
const struct V_204 * V_205 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
if ( V_6 -> V_165 == V_166 )
return - V_60 ;
if ( 0 != V_205 -> V_19 )
return - V_60 ;
F_13 ( V_6 , V_206 , V_208 , V_205 ) ;
return 0 ;
}
static int F_81 ( struct V_134 * V_134 , void * V_135 ,
struct V_209 * V_136 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
if ( V_6 -> V_165 == V_166 )
return - V_60 ;
V_136 -> type = V_210 ;
V_136 -> V_211 = V_6 -> V_212 ;
F_13 ( V_6 , V_206 , V_213 , V_136 ) ;
return 0 ;
}
static int F_82 ( struct V_5 * V_6 , const struct V_209 * V_136 )
{
struct V_214 * V_215 ;
int V_216 = 1 ;
if ( V_6 -> V_165 == V_166 )
return - V_60 ;
if ( F_65 ( V_136 -> V_206 != 0 ) )
return - V_60 ;
V_6 -> V_212 = V_136 -> V_211 ;
V_215 = F_83 ( & V_6 -> V_217 , V_218 ) ;
if ( V_215 ) {
V_216 = F_84 ( V_215 ) ;
if ( ! V_216 )
F_85 ( V_215 , 1 ) ;
}
F_13 ( V_6 , V_206 , V_219 , V_136 ) ;
F_86 ( 100 ) ;
if ( V_216 == 0 )
F_85 ( V_215 , V_216 ) ;
return 0 ;
}
static int F_87 ( struct V_5 * V_6 ,
const struct V_209 * V_136 )
{
struct V_214 * V_215 ;
int V_216 = 1 ;
struct V_220 * V_221 ;
struct V_222 * V_223 ;
struct V_224 V_225 = {
. V_226 = V_210 ,
. V_227 = V_228 ,
. V_192 = V_6 -> V_23 ,
. V_211 = V_136 -> V_211
} ;
V_6 -> V_212 = V_136 -> V_211 ;
V_215 = F_83 ( & V_6 -> V_217 , V_218 ) ;
if ( V_215 ) {
V_216 = F_84 ( V_215 ) ;
if ( ! V_216 )
F_85 ( V_215 , 1 ) ;
}
F_7 ( 1 , L_35 , V_22 ,
V_225 . V_211 , V_136 -> V_206 , V_225 . V_192 ) ;
V_221 = F_88 ( & V_6 -> V_229 . V_230 , 1 ) ;
if ( ! V_221 ) {
return - V_60 ;
}
V_223 = V_221 -> V_231 . V_232 ;
if ( ( V_6 -> V_41 == V_81 ) ||
( V_6 -> V_41 == V_79 ) ||
( V_6 -> V_41 == V_80 ) )
V_223 = & V_6 -> V_233 . V_234 ;
if ( V_223 && V_223 -> V_235 . V_236 . V_237 ) {
F_13 ( V_6 , V_28 , V_29 , V_6 -> V_23 ) ;
V_223 -> V_235 . V_236 . V_237 ( V_223 , & V_225 ) ;
}
else
F_20 ( V_55 L_36 , V_22 ) ;
F_86 ( 100 ) ;
if ( V_216 == 0 )
F_85 ( V_215 , V_216 ) ;
return 0 ;
}
int F_89 ( struct V_134 * V_134 , void * V_135 ,
const struct V_209 * V_136 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
int V_51 ;
switch ( V_6 -> V_41 ) {
case V_79 :
case V_80 :
case V_81 :
V_51 = F_87 ( V_6 , V_136 ) ;
break;
default:
V_51 = F_82 ( V_6 , V_136 ) ;
}
return V_51 ;
}
static int F_90 ( struct V_134 * V_134 , void * V_135 ,
const struct V_209 * V_136 )
{
return F_89 ( V_134 , V_135 , V_136 ) ;
}
int F_91 ( struct V_5 * V_6 , T_1 V_197 )
{
T_1 V_238 , V_9 ;
int V_239 = 0 ;
V_238 = F_92 ( V_94 ) ;
if ( 0 == ( V_197 & V_238 ) )
return V_239 ;
F_31 ( V_240 , V_197 ) ;
if ( ( V_197 & V_241 ) ||
( V_197 & V_242 ) ||
( V_197 & V_243 ) ) {
if ( V_197 & V_241 ) {
F_7 ( 7 , L_37 ,
V_241 ) ;
F_20 ( V_244 L_38 ,
V_6 -> V_39 ) ;
F_93 ( V_6 ,
& V_6 -> V_88 [ V_89 ] ) ;
}
if ( V_197 & V_242 )
F_7 ( 7 , L_39
L_40 ,
V_242 ) ;
if ( V_197 & V_243 )
F_7 ( 7 , L_41 ,
V_243 ) ;
}
if ( V_197 & V_245 ) {
F_94 ( & V_6 -> V_130 ) ;
V_9 = F_92 ( V_246 ) ;
F_3 ( V_6 , & V_6 -> V_125 , V_9 ) ;
F_95 ( & V_6 -> V_130 ) ;
V_239 ++ ;
}
V_239 += F_96 ( V_6 , V_197 ) ;
return V_239 ;
}
void F_97 ( struct V_5 * V_6 )
{
F_7 ( 1 , L_3 , V_22 ) ;
F_98 ( V_6 , 0x01 ) ;
if ( V_6 -> V_247 ) {
if ( F_99 ( V_6 -> V_247 ) )
F_100 ( V_6 -> V_247 ) ;
else
V_37 ( V_6 -> V_247 ) ;
V_6 -> V_247 = NULL ;
}
if ( V_6 -> V_248 ) {
if ( F_99 ( V_6 -> V_248 ) )
F_100 ( V_6 -> V_248 ) ;
else
V_37 ( V_6 -> V_248 ) ;
V_6 -> V_248 = NULL ;
}
if ( V_6 -> V_249 )
F_101 ( V_6 ) ;
}
int F_102 ( struct V_5 * V_6 )
{
struct V_96 * V_8 ;
int V_151 ;
F_7 ( 1 , L_3 , V_22 ) ;
V_250 = V_251 ;
strcpy ( V_250 . V_39 , L_42 ) ;
V_6 -> V_23 = V_252 ;
V_6 -> V_98 = F_1 ( V_253 ) ;
V_6 -> V_114 = V_119 ;
V_6 -> V_105 = 720 ;
V_6 -> V_106 = F_55 ( V_6 -> V_23 ) ;
F_103 ( & V_6 -> V_125 . V_12 ) ;
F_103 ( & V_6 -> V_254 . V_12 ) ;
F_32 ( V_6 , 0x01 ) ;
if ( ( V_166 != V_6 -> V_165 ) &&
( ( V_6 -> V_255 == 0 ) || ( V_6 -> V_255 == 1 ) ) ) {
struct V_256 * V_257 = NULL ;
if ( V_6 -> V_258 )
V_257 = F_104 ( & V_6 -> V_35 ,
& V_6 -> V_49 [ V_6 -> V_255 ] . V_50 ,
L_43 , V_6 -> V_258 , NULL ) ;
else
V_257 = F_104 ( & V_6 -> V_35 ,
& V_6 -> V_49 [ V_6 -> V_255 ] . V_50 ,
L_43 , 0 , F_105 ( V_259 ) ) ;
if ( V_257 ) {
struct V_260 V_261 ;
memset ( & V_261 , 0 , sizeof( V_261 ) ) ;
V_261 . V_262 = V_263 ;
V_261 . type = V_6 -> V_165 ;
V_261 . V_46 = F_106 ( V_257 ) ;
V_261 . V_264 = V_265 ;
F_26 ( V_257 , V_206 , V_266 , & V_261 ) ;
if ( ( V_6 -> V_41 == V_267 ) ||
( V_6 -> V_41 == V_268 ) ) {
struct V_269 V_270 = {
. V_271 = V_272 ,
. V_273 = 64
} ;
struct V_274 V_275 = {
. V_206 = V_6 -> V_165 ,
. V_135 = & V_270
} ;
F_26 ( V_257 , V_206 , V_276 , & V_275 ) ;
}
if ( V_6 -> V_41 == V_82 ) {
struct V_269 V_270 = {
. V_271 = L_44 ,
. V_273 = 64
} ;
struct V_274 V_275 = {
. V_206 = V_6 -> V_165 ,
. V_135 = & V_270
} ;
F_26 ( V_257 , V_206 , V_276 , & V_275 ) ;
}
}
}
F_107 ( & V_6 -> V_38 ) ;
F_10 ( V_6 , V_6 -> V_23 ) ;
F_23 ( V_6 , 0 ) ;
F_27 ( V_6 , 0 ) ;
F_108 ( & V_6 -> V_38 ) ;
V_8 = & V_6 -> V_24 ;
V_8 -> type = V_277 ;
V_8 -> V_278 = V_279 | V_280 | V_281 | V_282 ;
V_8 -> V_283 = V_284 ;
V_8 -> V_285 = 2 ;
V_8 -> V_103 = V_6 ;
V_8 -> V_286 = sizeof( struct V_10 ) ;
V_8 -> V_235 = & V_287 ;
V_8 -> V_288 = & V_289 ;
V_8 -> V_290 = V_291 ;
V_8 -> V_38 = & V_6 -> V_38 ;
V_151 = F_109 ( V_8 ) ;
if ( V_151 < 0 )
goto V_292;
V_8 = & V_6 -> V_25 ;
V_8 -> type = V_293 ;
V_8 -> V_278 = V_279 | V_280 | V_281 | V_282 ;
V_8 -> V_283 = V_284 ;
V_8 -> V_285 = 2 ;
V_8 -> V_103 = V_6 ;
V_8 -> V_286 = sizeof( struct V_10 ) ;
V_8 -> V_235 = & V_294 ;
V_8 -> V_288 = & V_289 ;
V_8 -> V_290 = V_291 ;
V_8 -> V_38 = & V_6 -> V_38 ;
V_151 = F_109 ( V_8 ) ;
if ( V_151 < 0 )
goto V_292;
V_6 -> V_248 = F_14 ( V_6 , V_6 -> V_32 ,
& V_251 , L_45 ) ;
V_6 -> V_248 -> V_14 = & V_6 -> V_24 ;
V_151 = F_110 ( V_6 -> V_248 , V_295 ,
V_296 [ V_6 -> V_297 ] ) ;
if ( V_151 < 0 ) {
F_20 ( V_298 L_46 ,
V_6 -> V_39 ) ;
goto V_292;
}
F_20 ( V_298 L_47 ,
V_6 -> V_39 , F_111 ( V_6 -> V_248 ) ) ;
V_6 -> V_247 = F_14 ( V_6 , V_6 -> V_32 ,
& V_250 , L_48 ) ;
V_6 -> V_247 -> V_14 = & V_6 -> V_25 ;
V_151 = F_110 ( V_6 -> V_247 , V_169 ,
V_299 [ V_6 -> V_297 ] ) ;
if ( V_151 < 0 ) {
F_20 ( V_298 L_49 ,
V_6 -> V_39 ) ;
goto V_292;
}
F_20 ( V_298 L_50 ,
V_6 -> V_39 , F_111 ( V_6 -> V_247 ) ) ;
V_6 -> V_249 = F_112 ( V_6 ) ;
return 0 ;
V_292:
F_97 ( V_6 ) ;
return V_151 ;
}
