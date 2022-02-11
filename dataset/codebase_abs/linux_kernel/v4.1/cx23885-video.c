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
struct V_147 V_148 ;
int V_149 ;
F_7 ( 2 , L_3 , V_22 ) ;
V_149 = F_53 ( V_134 , V_135 , V_136 ) ;
if ( 0 != V_149 )
return V_149 ;
if ( F_12 ( & V_6 -> V_24 ) || F_12 ( & V_6 -> V_25 ) ||
F_12 ( & V_6 -> V_26 ) )
return - V_27 ;
V_6 -> V_98 = F_1 ( V_136 -> V_98 . V_137 . V_138 ) ;
V_6 -> V_105 = V_136 -> V_98 . V_137 . V_105 ;
V_6 -> V_106 = V_136 -> V_98 . V_137 . V_106 ;
V_6 -> V_114 = V_136 -> V_98 . V_137 . V_114 ;
F_7 ( 2 , L_16 , V_22 ,
V_6 -> V_105 , V_6 -> V_106 , V_6 -> V_114 ) ;
F_58 ( & V_148 , & V_136 -> V_98 . V_137 , V_150 ) ;
F_13 ( V_6 , V_28 , V_151 , & V_148 ) ;
F_59 ( & V_136 -> V_98 . V_137 , & V_148 ) ;
V_136 -> V_98 . V_137 . V_114 = V_6 -> V_114 ;
return 0 ;
}
static int F_60 ( struct V_134 * V_134 , void * V_135 ,
struct V_152 * V_153 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
struct V_30 * V_154 = F_61 ( V_134 ) ;
strcpy ( V_153 -> V_155 , L_17 ) ;
F_62 ( V_153 -> V_156 , V_40 [ V_6 -> V_41 ] . V_39 ,
sizeof( V_153 -> V_156 ) ) ;
sprintf ( V_153 -> V_157 , L_18 , F_63 ( V_6 -> V_32 ) ) ;
V_153 -> V_158 = V_159 | V_160 | V_161 ;
if ( V_6 -> V_162 != V_163 )
V_153 -> V_158 |= V_164 ;
if ( V_154 -> V_165 == V_166 )
V_153 -> V_158 |= V_167 ;
else
V_153 -> V_158 |= V_168 ;
V_153 -> V_169 = V_153 -> V_158 | V_167 |
V_168 | V_170 ;
return 0 ;
}
static int F_64 ( struct V_134 * V_134 , void * V_135 ,
struct V_171 * V_136 )
{
if ( F_65 ( V_136 -> V_19 >= F_2 ( V_4 ) ) )
return - V_60 ;
F_62 ( V_136 -> V_172 , V_4 [ V_136 -> V_19 ] . V_39 ,
sizeof( V_136 -> V_172 ) ) ;
V_136 -> V_138 = V_4 [ V_136 -> V_19 ] . V_2 ;
return 0 ;
}
static int F_66 ( struct V_134 * V_134 , void * V_135 , T_2 * V_173 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
F_7 ( 1 , L_3 , V_22 ) ;
* V_173 = V_6 -> V_23 ;
return 0 ;
}
static int F_67 ( struct V_134 * V_134 , void * V_135 , T_2 V_174 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
F_7 ( 1 , L_3 , V_22 ) ;
return F_10 ( V_6 , V_174 ) ;
}
int F_68 ( struct V_5 * V_6 , struct V_175 * V_3 )
{
static const char * V_176 [] = {
[ V_177 ] = L_19 ,
[ V_178 ] = L_20 ,
[ V_179 ] = L_21 ,
[ V_180 ] = L_22 ,
[ V_181 ] = L_23 ,
[ V_182 ] = L_24 ,
[ V_71 ] = L_25 ,
[ V_183 ] = L_26 ,
[ V_184 ] = L_27 ,
[ V_185 ] = L_28 ,
} ;
unsigned int V_186 ;
F_7 ( 1 , L_3 , V_22 ) ;
V_186 = V_3 -> V_19 ;
if ( V_186 >= V_187 )
return - V_60 ;
if ( 0 == F_24 ( V_186 ) -> type )
return - V_60 ;
V_3 -> V_19 = V_186 ;
V_3 -> type = V_188 ;
strcpy ( V_3 -> V_39 , V_176 [ F_24 ( V_186 ) -> type ] ) ;
V_3 -> V_189 = V_190 ;
if ( ( V_71 == F_24 ( V_186 ) -> type ) ||
( V_183 == F_24 ( V_186 ) -> type ) ) {
V_3 -> type = V_191 ;
V_3 -> V_192 = 4 ;
} else {
V_3 -> V_192 = 3 ;
}
if ( V_6 -> V_56 == V_186 ) {
F_13 ( V_6 , V_28 , V_193 , & V_3 -> V_194 ) ;
}
return 0 ;
}
static int F_69 ( struct V_134 * V_134 , void * V_135 ,
struct V_175 * V_3 )
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
if ( V_3 >= V_187 ) {
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
F_13 ( V_6 , V_195 , V_196 ) ;
return 0 ;
}
static int F_75 ( struct V_134 * V_134 , void * V_135 ,
struct V_197 * V_3 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
static const char * V_176 [] = {
[ 0 ] = L_32 ,
[ 1 ] = L_33 ,
[ 2 ] = L_34 ,
} ;
unsigned int V_186 ;
F_7 ( 1 , L_3 , V_22 ) ;
V_186 = V_3 -> V_19 ;
if ( V_186 >= 3 )
return - V_60 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_19 = V_186 ;
strcpy ( V_3 -> V_39 , V_176 [ V_186 ] ) ;
V_3 -> V_198 = V_199 ;
return 0 ;
}
static int F_76 ( struct V_134 * V_134 , void * V_135 ,
struct V_197 * V_3 )
{
return F_75 ( V_134 , V_135 , V_3 ) ;
}
static int F_77 ( struct V_134 * V_134 , void * V_135 ,
struct V_197 * V_3 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
if ( ( V_71 == F_24 ( V_6 -> V_56 ) -> type ) ||
( V_183 == F_24 ( V_6 -> V_56 ) -> type ) )
V_3 -> V_19 = 2 ;
else
V_3 -> V_19 = V_6 -> V_200 ;
F_7 ( 1 , L_10 , V_22 , V_3 -> V_19 ) ;
return F_75 ( V_134 , V_135 , V_3 ) ;
}
static int F_78 ( struct V_134 * V_134 , void * V_135 ,
const struct V_197 * V_3 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
if ( ( V_71 == F_24 ( V_6 -> V_56 ) -> type ) ||
( V_183 == F_24 ( V_6 -> V_56 ) -> type ) ) {
return V_3 -> V_19 != 2 ? - V_60 : 0 ;
}
if ( V_3 -> V_19 > 1 )
return - V_60 ;
F_7 ( 1 , L_30 , V_22 , V_3 -> V_19 ) ;
V_6 -> V_200 = V_3 -> V_19 ;
F_22 ( V_6 , V_6 -> V_200 + 1 ) ;
return 0 ;
}
static int F_79 ( struct V_134 * V_134 , void * V_135 ,
struct V_201 * V_202 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
if ( V_6 -> V_162 == V_163 )
return - V_60 ;
if ( 0 != V_202 -> V_19 )
return - V_60 ;
strcpy ( V_202 -> V_39 , L_25 ) ;
F_13 ( V_6 , V_203 , V_204 , V_202 ) ;
return 0 ;
}
static int F_80 ( struct V_134 * V_134 , void * V_135 ,
const struct V_201 * V_202 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
if ( V_6 -> V_162 == V_163 )
return - V_60 ;
if ( 0 != V_202 -> V_19 )
return - V_60 ;
F_13 ( V_6 , V_203 , V_205 , V_202 ) ;
return 0 ;
}
static int F_81 ( struct V_134 * V_134 , void * V_135 ,
struct V_206 * V_136 )
{
struct V_5 * V_6 = F_52 ( V_134 ) ;
if ( V_6 -> V_162 == V_163 )
return - V_60 ;
V_136 -> type = V_207 ;
V_136 -> V_208 = V_6 -> V_209 ;
F_13 ( V_6 , V_203 , V_210 , V_136 ) ;
return 0 ;
}
static int F_82 ( struct V_5 * V_6 , const struct V_206 * V_136 )
{
struct V_211 * V_212 ;
int V_213 = 1 ;
if ( V_6 -> V_162 == V_163 )
return - V_60 ;
if ( F_65 ( V_136 -> V_203 != 0 ) )
return - V_60 ;
V_6 -> V_209 = V_136 -> V_208 ;
V_212 = F_83 ( & V_6 -> V_214 , V_215 ) ;
if ( V_212 ) {
V_213 = F_84 ( V_212 ) ;
if ( ! V_213 )
F_85 ( V_212 , 1 ) ;
}
F_13 ( V_6 , V_203 , V_216 , V_136 ) ;
F_86 ( 100 ) ;
if ( V_213 == 0 )
F_85 ( V_212 , V_213 ) ;
return 0 ;
}
static int F_87 ( struct V_5 * V_6 ,
const struct V_206 * V_136 )
{
struct V_211 * V_212 ;
int V_213 = 1 ;
struct V_217 * V_218 ;
struct V_219 * V_220 ;
struct V_221 V_222 = {
. V_223 = V_207 ,
. V_224 = V_225 ,
. V_189 = V_6 -> V_23 ,
. V_208 = V_136 -> V_208
} ;
V_6 -> V_209 = V_136 -> V_208 ;
V_212 = F_83 ( & V_6 -> V_214 , V_215 ) ;
if ( V_212 ) {
V_213 = F_84 ( V_212 ) ;
if ( ! V_213 )
F_85 ( V_212 , 1 ) ;
}
F_7 ( 1 , L_35 , V_22 ,
V_222 . V_208 , V_136 -> V_203 , V_222 . V_189 ) ;
V_218 = F_88 ( & V_6 -> V_226 . V_227 , 1 ) ;
if ( ! V_218 ) {
return - V_60 ;
}
V_220 = V_218 -> V_228 . V_229 ;
if ( ( V_6 -> V_41 == V_81 ) ||
( V_6 -> V_41 == V_79 ) ||
( V_6 -> V_41 == V_80 ) )
V_220 = & V_6 -> V_230 . V_231 ;
if ( V_220 && V_220 -> V_232 . V_233 . V_234 ) {
F_13 ( V_6 , V_28 , V_29 , V_6 -> V_23 ) ;
V_220 -> V_232 . V_233 . V_234 ( V_220 , & V_222 ) ;
}
else
F_20 ( V_55 L_36 , V_22 ) ;
F_86 ( 100 ) ;
if ( V_213 == 0 )
F_85 ( V_212 , V_213 ) ;
return 0 ;
}
int F_89 ( struct V_134 * V_134 , void * V_135 ,
const struct V_206 * V_136 )
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
const struct V_206 * V_136 )
{
return F_89 ( V_134 , V_135 , V_136 ) ;
}
int F_91 ( struct V_5 * V_6 , T_1 V_194 )
{
T_1 V_235 , V_9 ;
int V_236 = 0 ;
V_235 = F_92 ( V_94 ) ;
if ( 0 == ( V_194 & V_235 ) )
return V_236 ;
F_31 ( V_237 , V_194 ) ;
if ( ( V_194 & V_238 ) ||
( V_194 & V_239 ) ||
( V_194 & V_240 ) ) {
if ( V_194 & V_238 ) {
F_7 ( 7 , L_37 ,
V_238 ) ;
F_20 ( V_241 L_38 ,
V_6 -> V_39 ) ;
F_93 ( V_6 ,
& V_6 -> V_88 [ V_89 ] ) ;
}
if ( V_194 & V_239 )
F_7 ( 7 , L_39
L_40 ,
V_239 ) ;
if ( V_194 & V_240 )
F_7 ( 7 , L_41 ,
V_240 ) ;
}
if ( V_194 & V_242 ) {
F_94 ( & V_6 -> V_130 ) ;
V_9 = F_92 ( V_243 ) ;
F_3 ( V_6 , & V_6 -> V_125 , V_9 ) ;
F_95 ( & V_6 -> V_130 ) ;
V_236 ++ ;
}
V_236 += F_96 ( V_6 , V_194 ) ;
return V_236 ;
}
void F_97 ( struct V_5 * V_6 )
{
F_7 ( 1 , L_3 , V_22 ) ;
F_98 ( V_6 , 0x01 ) ;
if ( V_6 -> V_244 ) {
if ( F_99 ( V_6 -> V_244 ) )
F_100 ( V_6 -> V_244 ) ;
else
V_37 ( V_6 -> V_244 ) ;
V_6 -> V_244 = NULL ;
}
if ( V_6 -> V_245 ) {
if ( F_99 ( V_6 -> V_245 ) )
F_100 ( V_6 -> V_245 ) ;
else
V_37 ( V_6 -> V_245 ) ;
V_6 -> V_245 = NULL ;
}
if ( V_6 -> V_246 )
F_101 ( V_6 ) ;
}
int F_102 ( struct V_5 * V_6 )
{
struct V_96 * V_8 ;
int V_149 ;
F_7 ( 1 , L_3 , V_22 ) ;
V_247 = V_248 ;
strcpy ( V_247 . V_39 , L_42 ) ;
V_6 -> V_23 = V_249 ;
V_6 -> V_98 = F_1 ( V_250 ) ;
V_6 -> V_114 = V_119 ;
V_6 -> V_105 = 720 ;
V_6 -> V_106 = F_55 ( V_6 -> V_23 ) ;
F_103 ( & V_6 -> V_125 . V_12 ) ;
F_103 ( & V_6 -> V_251 . V_12 ) ;
F_32 ( V_6 , 0x01 ) ;
if ( ( V_163 != V_6 -> V_162 ) &&
( ( V_6 -> V_252 == 0 ) || ( V_6 -> V_252 == 1 ) ) ) {
struct V_253 * V_254 = NULL ;
if ( V_6 -> V_255 )
V_254 = F_104 ( & V_6 -> V_35 ,
& V_6 -> V_49 [ V_6 -> V_252 ] . V_50 ,
L_43 , V_6 -> V_255 , NULL ) ;
else
V_254 = F_104 ( & V_6 -> V_35 ,
& V_6 -> V_49 [ V_6 -> V_252 ] . V_50 ,
L_43 , 0 , F_105 ( V_256 ) ) ;
if ( V_254 ) {
struct V_257 V_258 ;
memset ( & V_258 , 0 , sizeof( V_258 ) ) ;
V_258 . V_259 = V_260 ;
V_258 . type = V_6 -> V_162 ;
V_258 . V_46 = F_106 ( V_254 ) ;
V_258 . V_261 = V_262 ;
F_26 ( V_254 , V_203 , V_263 , & V_258 ) ;
if ( ( V_6 -> V_41 == V_264 ) ||
( V_6 -> V_41 == V_265 ) ) {
struct V_266 V_267 = {
. V_268 = V_269 ,
. V_270 = 64
} ;
struct V_271 V_272 = {
. V_203 = V_6 -> V_162 ,
. V_135 = & V_267
} ;
F_26 ( V_254 , V_203 , V_273 , & V_272 ) ;
}
if ( V_6 -> V_41 == V_82 ) {
struct V_266 V_267 = {
. V_268 = L_44 ,
. V_270 = 64
} ;
struct V_271 V_272 = {
. V_203 = V_6 -> V_162 ,
. V_135 = & V_267
} ;
F_26 ( V_254 , V_203 , V_273 , & V_272 ) ;
}
}
}
F_107 ( & V_6 -> V_38 ) ;
F_10 ( V_6 , V_6 -> V_23 ) ;
F_23 ( V_6 , 0 ) ;
F_27 ( V_6 , 0 ) ;
F_108 ( & V_6 -> V_38 ) ;
V_8 = & V_6 -> V_24 ;
V_8 -> type = V_274 ;
V_8 -> V_275 = V_276 | V_277 | V_278 | V_279 ;
V_8 -> V_280 = V_281 ;
V_8 -> V_282 = 2 ;
V_8 -> V_103 = V_6 ;
V_8 -> V_283 = sizeof( struct V_10 ) ;
V_8 -> V_232 = & V_284 ;
V_8 -> V_285 = & V_286 ;
V_8 -> V_287 = V_288 ;
V_8 -> V_38 = & V_6 -> V_38 ;
V_149 = F_109 ( V_8 ) ;
if ( V_149 < 0 )
goto V_289;
V_8 = & V_6 -> V_25 ;
V_8 -> type = V_290 ;
V_8 -> V_275 = V_276 | V_277 | V_278 | V_279 ;
V_8 -> V_280 = V_281 ;
V_8 -> V_282 = 2 ;
V_8 -> V_103 = V_6 ;
V_8 -> V_283 = sizeof( struct V_10 ) ;
V_8 -> V_232 = & V_291 ;
V_8 -> V_285 = & V_286 ;
V_8 -> V_287 = V_288 ;
V_8 -> V_38 = & V_6 -> V_38 ;
V_149 = F_109 ( V_8 ) ;
if ( V_149 < 0 )
goto V_289;
V_6 -> V_245 = F_14 ( V_6 , V_6 -> V_32 ,
& V_248 , L_45 ) ;
V_6 -> V_245 -> V_14 = & V_6 -> V_24 ;
V_149 = F_110 ( V_6 -> V_245 , V_292 ,
V_293 [ V_6 -> V_294 ] ) ;
if ( V_149 < 0 ) {
F_20 ( V_295 L_46 ,
V_6 -> V_39 ) ;
goto V_289;
}
F_20 ( V_295 L_47 ,
V_6 -> V_39 , F_111 ( V_6 -> V_245 ) ) ;
V_6 -> V_244 = F_14 ( V_6 , V_6 -> V_32 ,
& V_247 , L_48 ) ;
V_6 -> V_244 -> V_14 = & V_6 -> V_25 ;
V_149 = F_110 ( V_6 -> V_244 , V_166 ,
V_296 [ V_6 -> V_294 ] ) ;
if ( V_149 < 0 ) {
F_20 ( V_295 L_49 ,
V_6 -> V_39 ) ;
goto V_289;
}
F_20 ( V_295 L_50 ,
V_6 -> V_39 , F_111 ( V_6 -> V_244 ) ) ;
V_6 -> V_246 = F_112 ( V_6 ) ;
return 0 ;
V_289:
F_97 ( V_6 ) ;
return V_149 ;
}
