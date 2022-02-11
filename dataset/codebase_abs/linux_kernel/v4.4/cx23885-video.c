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
F_6 ( & V_11 -> V_15 . V_17 ) ;
F_7 ( 2 , L_1 , V_11 ,
V_11 -> V_15 . V_18 . V_19 , V_9 , V_8 -> V_9 ) ;
F_8 ( & V_11 -> V_14 ) ;
F_9 ( & V_11 -> V_15 . V_18 , V_20 ) ;
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
static int F_34 ( struct V_96 * V_8 , const void * V_97 ,
unsigned int * V_98 , unsigned int * V_99 ,
unsigned int V_100 [] , void * V_101 [] )
{
struct V_5 * V_6 = V_8 -> V_102 ;
* V_99 = 1 ;
V_100 [ 0 ] = ( V_6 -> V_103 -> V_104 * V_6 -> V_105 * V_6 -> V_106 ) >> 3 ;
V_101 [ 0 ] = V_6 -> V_107 ;
return 0 ;
}
static int F_35 ( struct V_108 * V_15 )
{
struct V_109 * V_110 = F_36 ( V_15 ) ;
struct V_5 * V_6 = V_15 -> V_96 -> V_102 ;
struct V_10 * V_11 =
F_37 ( V_110 , struct V_10 , V_15 ) ;
T_1 V_111 , V_112 ;
struct V_113 * V_114 = F_38 ( V_15 , 0 ) ;
int V_115 ;
V_11 -> V_90 = ( V_6 -> V_105 * V_6 -> V_103 -> V_104 ) >> 3 ;
if ( F_39 ( V_15 , 0 ) < V_6 -> V_106 * V_11 -> V_90 )
return - V_60 ;
F_40 ( V_15 , 0 , V_6 -> V_106 * V_11 -> V_90 ) ;
switch ( V_6 -> V_116 ) {
case V_117 :
F_41 ( V_6 -> V_32 , & V_11 -> V_91 ,
V_114 -> V_118 , 0 , V_119 ,
V_11 -> V_90 , 0 , V_6 -> V_106 ) ;
break;
case V_120 :
F_41 ( V_6 -> V_32 , & V_11 -> V_91 ,
V_114 -> V_118 , V_119 , 0 ,
V_11 -> V_90 , 0 , V_6 -> V_106 ) ;
break;
case V_121 :
if ( V_6 -> V_23 & V_122 )
V_115 = 1 ;
else
V_115 = 0 ;
if ( V_40 [ V_6 -> V_41 ] . V_123 )
V_115 = 0 ;
if ( V_115 ) {
F_7 ( 1 , L_11 ,
V_22 ) ;
V_111 = V_11 -> V_90 ;
V_112 = 0 ;
} else {
F_7 ( 1 , L_12 ,
V_22 ) ;
V_111 = 0 ;
V_112 = V_11 -> V_90 ;
}
F_41 ( V_6 -> V_32 , & V_11 -> V_91 ,
V_114 -> V_118 , V_111 ,
V_112 ,
V_11 -> V_90 , V_11 -> V_90 ,
V_6 -> V_106 >> 1 ) ;
break;
case V_124 :
F_41 ( V_6 -> V_32 , & V_11 -> V_91 ,
V_114 -> V_118 ,
0 , V_11 -> V_90 * ( V_6 -> V_106 >> 1 ) ,
V_11 -> V_90 , 0 ,
V_6 -> V_106 >> 1 ) ;
break;
case V_125 :
F_41 ( V_6 -> V_32 , & V_11 -> V_91 ,
V_114 -> V_118 ,
V_11 -> V_90 * ( V_6 -> V_106 >> 1 ) , 0 ,
V_11 -> V_90 , 0 ,
V_6 -> V_106 >> 1 ) ;
break;
default:
F_42 () ;
}
F_7 ( 2 , L_13 ,
V_11 , V_11 -> V_15 . V_18 . V_19 ,
V_6 -> V_105 , V_6 -> V_106 , V_6 -> V_103 -> V_104 , V_6 -> V_103 -> V_39 ,
( unsigned long ) V_11 -> V_91 . V_92 ) ;
return 0 ;
}
static void F_43 ( struct V_108 * V_15 )
{
struct V_109 * V_110 = F_36 ( V_15 ) ;
struct V_10 * V_11 = F_37 ( V_110 ,
struct V_10 , V_15 ) ;
F_44 ( V_15 -> V_96 -> V_102 , V_11 ) ;
}
static void F_45 ( struct V_108 * V_15 )
{
struct V_109 * V_110 = F_36 ( V_15 ) ;
struct V_5 * V_6 = V_15 -> V_96 -> V_102 ;
struct V_10 * V_11 = F_37 ( V_110 ,
struct V_10 , V_15 ) ;
struct V_10 * V_126 ;
struct V_7 * V_8 = & V_6 -> V_127 ;
unsigned long V_47 ;
V_11 -> V_91 . V_128 [ 1 ] = F_46 ( V_11 -> V_91 . V_92 + 12 ) ;
V_11 -> V_91 . V_129 [ 0 ] = F_46 ( V_130 | V_131 ) ;
V_11 -> V_91 . V_129 [ 1 ] = F_46 ( V_11 -> V_91 . V_92 + 12 ) ;
V_11 -> V_91 . V_129 [ 2 ] = F_46 ( 0 ) ;
F_47 ( & V_6 -> V_132 , V_47 ) ;
if ( F_4 ( & V_8 -> V_12 ) ) {
F_48 ( & V_11 -> V_14 , & V_8 -> V_12 ) ;
F_7 ( 2 , L_14 ,
V_11 , V_11 -> V_15 . V_18 . V_19 ) ;
} else {
V_11 -> V_91 . V_128 [ 0 ] |= F_46 ( V_133 ) ;
V_126 = F_5 ( V_8 -> V_12 . V_126 , struct V_10 ,
V_14 ) ;
F_48 ( & V_11 -> V_14 , & V_8 -> V_12 ) ;
V_126 -> V_91 . V_129 [ 1 ] = F_46 ( V_11 -> V_91 . V_92 ) ;
F_7 ( 2 , L_15 ,
V_11 , V_11 -> V_15 . V_18 . V_19 ) ;
}
F_49 ( & V_6 -> V_132 , V_47 ) ;
}
static int F_50 ( struct V_96 * V_8 , unsigned int V_9 )
{
struct V_5 * V_6 = V_8 -> V_102 ;
struct V_7 * V_134 = & V_6 -> V_127 ;
struct V_10 * V_11 = F_5 ( V_134 -> V_12 . V_13 ,
struct V_10 , V_14 ) ;
F_28 ( V_6 , V_134 , V_11 ) ;
return 0 ;
}
static void F_51 ( struct V_96 * V_8 )
{
struct V_5 * V_6 = V_8 -> V_102 ;
struct V_7 * V_134 = & V_6 -> V_127 ;
unsigned long V_47 ;
F_29 ( V_87 , 0x11 ) ;
F_47 ( & V_6 -> V_132 , V_47 ) ;
while ( ! F_4 ( & V_134 -> V_12 ) ) {
struct V_10 * V_11 = F_5 ( V_134 -> V_12 . V_13 ,
struct V_10 , V_14 ) ;
F_8 ( & V_11 -> V_14 ) ;
F_9 ( & V_11 -> V_15 . V_18 , V_135 ) ;
}
F_49 ( & V_6 -> V_132 , V_47 ) ;
}
static int F_52 ( struct V_136 * V_136 , void * V_137 ,
struct V_138 * V_139 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
V_139 -> V_103 . V_140 . V_105 = V_6 -> V_105 ;
V_139 -> V_103 . V_140 . V_106 = V_6 -> V_106 ;
V_139 -> V_103 . V_140 . V_116 = V_6 -> V_116 ;
V_139 -> V_103 . V_140 . V_141 = V_6 -> V_103 -> V_2 ;
V_139 -> V_103 . V_140 . V_142 =
( V_139 -> V_103 . V_140 . V_105 * V_6 -> V_103 -> V_104 ) >> 3 ;
V_139 -> V_103 . V_140 . V_143 =
V_139 -> V_103 . V_140 . V_106 * V_139 -> V_103 . V_140 . V_142 ;
V_139 -> V_103 . V_140 . V_144 = V_145 ;
return 0 ;
}
static int F_54 ( struct V_136 * V_136 , void * V_137 ,
struct V_138 * V_139 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
struct V_1 * V_103 ;
enum V_146 V_116 ;
unsigned int V_147 , V_148 ;
V_103 = F_1 ( V_139 -> V_103 . V_140 . V_141 ) ;
if ( NULL == V_103 )
return - V_60 ;
V_116 = V_139 -> V_103 . V_140 . V_116 ;
V_147 = F_55 ( V_6 -> V_23 ) ;
V_148 = F_56 ( V_6 -> V_23 ) ;
if ( V_149 == V_116 ) {
V_116 = ( V_139 -> V_103 . V_140 . V_106 > V_148 / 2 )
? V_121
: V_120 ;
}
switch ( V_116 ) {
case V_117 :
case V_120 :
V_148 = V_148 / 2 ;
break;
case V_121 :
case V_124 :
case V_125 :
break;
default:
V_116 = V_121 ;
break;
}
V_139 -> V_103 . V_140 . V_116 = V_116 ;
F_57 ( & V_139 -> V_103 . V_140 . V_105 , 48 , V_147 , 2 ,
& V_139 -> V_103 . V_140 . V_106 , 32 , V_148 , 0 , 0 ) ;
V_139 -> V_103 . V_140 . V_142 =
( V_139 -> V_103 . V_140 . V_105 * V_103 -> V_104 ) >> 3 ;
V_139 -> V_103 . V_140 . V_143 =
V_139 -> V_103 . V_140 . V_106 * V_139 -> V_103 . V_140 . V_142 ;
V_139 -> V_103 . V_140 . V_144 = V_145 ;
return 0 ;
}
static int F_58 ( struct V_136 * V_136 , void * V_137 ,
struct V_138 * V_139 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
struct V_150 V_151 = {
. V_152 = V_153 ,
} ;
int V_154 ;
F_7 ( 2 , L_3 , V_22 ) ;
V_154 = F_54 ( V_136 , V_137 , V_139 ) ;
if ( 0 != V_154 )
return V_154 ;
if ( F_12 ( & V_6 -> V_24 ) || F_12 ( & V_6 -> V_25 ) ||
F_12 ( & V_6 -> V_26 ) )
return - V_27 ;
V_6 -> V_103 = F_1 ( V_139 -> V_103 . V_140 . V_141 ) ;
V_6 -> V_105 = V_139 -> V_103 . V_140 . V_105 ;
V_6 -> V_106 = V_139 -> V_103 . V_140 . V_106 ;
V_6 -> V_116 = V_139 -> V_103 . V_140 . V_116 ;
F_7 ( 2 , L_16 , V_22 ,
V_6 -> V_105 , V_6 -> V_106 , V_6 -> V_116 ) ;
F_59 ( & V_151 . V_151 , & V_139 -> V_103 . V_140 , V_155 ) ;
F_13 ( V_6 , V_156 , V_157 , NULL , & V_151 ) ;
F_60 ( & V_139 -> V_103 . V_140 , & V_151 . V_151 ) ;
V_139 -> V_103 . V_140 . V_116 = V_6 -> V_116 ;
return 0 ;
}
static int F_61 ( struct V_136 * V_136 , void * V_137 ,
struct V_158 * V_159 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
struct V_30 * V_160 = F_62 ( V_136 ) ;
strcpy ( V_159 -> V_161 , L_17 ) ;
F_63 ( V_159 -> V_162 , V_40 [ V_6 -> V_41 ] . V_39 ,
sizeof( V_159 -> V_162 ) ) ;
sprintf ( V_159 -> V_163 , L_18 , F_64 ( V_6 -> V_32 ) ) ;
V_159 -> V_164 = V_165 | V_166 | V_167 ;
if ( V_6 -> V_168 != V_169 )
V_159 -> V_164 |= V_170 ;
if ( V_160 -> V_171 == V_172 )
V_159 -> V_164 |= V_173 ;
else
V_159 -> V_164 |= V_174 ;
V_159 -> V_175 = V_159 -> V_164 | V_173 |
V_174 | V_176 ;
return 0 ;
}
static int F_65 ( struct V_136 * V_136 , void * V_137 ,
struct V_177 * V_139 )
{
if ( F_66 ( V_139 -> V_19 >= F_2 ( V_4 ) ) )
return - V_60 ;
F_63 ( V_139 -> V_178 , V_4 [ V_139 -> V_19 ] . V_39 ,
sizeof( V_139 -> V_178 ) ) ;
V_139 -> V_141 = V_4 [ V_139 -> V_19 ] . V_2 ;
return 0 ;
}
static int F_67 ( struct V_136 * V_136 , void * V_137 , T_2 * V_179 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
F_7 ( 1 , L_3 , V_22 ) ;
* V_179 = V_6 -> V_23 ;
return 0 ;
}
static int F_68 ( struct V_136 * V_136 , void * V_137 , T_2 V_180 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
F_7 ( 1 , L_3 , V_22 ) ;
return F_10 ( V_6 , V_180 ) ;
}
int F_69 ( struct V_5 * V_6 , struct V_181 * V_3 )
{
static const char * V_182 [] = {
[ V_183 ] = L_19 ,
[ V_184 ] = L_20 ,
[ V_185 ] = L_21 ,
[ V_186 ] = L_22 ,
[ V_187 ] = L_23 ,
[ V_188 ] = L_24 ,
[ V_71 ] = L_25 ,
[ V_189 ] = L_26 ,
[ V_190 ] = L_27 ,
[ V_191 ] = L_28 ,
} ;
unsigned int V_192 ;
F_7 ( 1 , L_3 , V_22 ) ;
V_192 = V_3 -> V_19 ;
if ( V_192 >= V_193 )
return - V_60 ;
if ( 0 == F_24 ( V_192 ) -> type )
return - V_60 ;
V_3 -> V_19 = V_192 ;
V_3 -> type = V_194 ;
strcpy ( V_3 -> V_39 , V_182 [ F_24 ( V_192 ) -> type ] ) ;
V_3 -> V_195 = V_196 ;
if ( ( V_71 == F_24 ( V_192 ) -> type ) ||
( V_189 == F_24 ( V_192 ) -> type ) ) {
V_3 -> type = V_197 ;
V_3 -> V_198 = 4 ;
} else {
V_3 -> V_198 = 3 ;
}
if ( V_6 -> V_56 == V_192 ) {
F_13 ( V_6 , V_28 , V_199 , & V_3 -> V_200 ) ;
}
return 0 ;
}
static int F_70 ( struct V_136 * V_136 , void * V_137 ,
struct V_181 * V_3 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
F_7 ( 1 , L_3 , V_22 ) ;
return F_69 ( V_6 , V_3 ) ;
}
int F_71 ( struct V_136 * V_136 , void * V_137 , unsigned int * V_3 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
* V_3 = V_6 -> V_56 ;
F_7 ( 1 , L_29 , V_22 , * V_3 ) ;
return 0 ;
}
static int F_72 ( struct V_136 * V_136 , void * V_137 , unsigned int * V_3 )
{
return F_71 ( V_136 , V_137 , V_3 ) ;
}
int F_73 ( struct V_136 * V_136 , void * V_137 , unsigned int V_3 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
F_7 ( 1 , L_30 , V_22 , V_3 ) ;
if ( V_3 >= V_193 ) {
F_7 ( 1 , L_31 , V_22 ) ;
return - V_60 ;
}
if ( F_24 ( V_3 ) -> type == 0 )
return - V_60 ;
F_23 ( V_6 , V_3 ) ;
F_27 ( V_6 , V_3 ) ;
return 0 ;
}
static int F_74 ( struct V_136 * V_136 , void * V_137 , unsigned int V_3 )
{
return F_73 ( V_136 , V_137 , V_3 ) ;
}
static int F_75 ( struct V_136 * V_136 , void * V_137 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
F_13 ( V_6 , V_201 , V_202 ) ;
return 0 ;
}
static int F_76 ( struct V_136 * V_136 , void * V_137 ,
struct V_203 * V_3 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
static const char * V_182 [] = {
[ 0 ] = L_32 ,
[ 1 ] = L_33 ,
[ 2 ] = L_34 ,
} ;
unsigned int V_192 ;
F_7 ( 1 , L_3 , V_22 ) ;
V_192 = V_3 -> V_19 ;
if ( V_192 >= 3 )
return - V_60 ;
memset ( V_3 , 0 , sizeof( * V_3 ) ) ;
V_3 -> V_19 = V_192 ;
strcpy ( V_3 -> V_39 , V_182 [ V_192 ] ) ;
V_3 -> V_204 = V_205 ;
return 0 ;
}
static int F_77 ( struct V_136 * V_136 , void * V_137 ,
struct V_203 * V_3 )
{
return F_76 ( V_136 , V_137 , V_3 ) ;
}
static int F_78 ( struct V_136 * V_136 , void * V_137 ,
struct V_203 * V_3 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
if ( ( V_71 == F_24 ( V_6 -> V_56 ) -> type ) ||
( V_189 == F_24 ( V_6 -> V_56 ) -> type ) )
V_3 -> V_19 = 2 ;
else
V_3 -> V_19 = V_6 -> V_206 ;
F_7 ( 1 , L_10 , V_22 , V_3 -> V_19 ) ;
return F_76 ( V_136 , V_137 , V_3 ) ;
}
static int F_79 ( struct V_136 * V_136 , void * V_137 ,
const struct V_203 * V_3 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
if ( ( V_71 == F_24 ( V_6 -> V_56 ) -> type ) ||
( V_189 == F_24 ( V_6 -> V_56 ) -> type ) ) {
return V_3 -> V_19 != 2 ? - V_60 : 0 ;
}
if ( V_3 -> V_19 > 1 )
return - V_60 ;
F_7 ( 1 , L_30 , V_22 , V_3 -> V_19 ) ;
V_6 -> V_206 = V_3 -> V_19 ;
F_22 ( V_6 , V_6 -> V_206 + 1 ) ;
return 0 ;
}
static int F_80 ( struct V_136 * V_136 , void * V_137 ,
struct V_207 * V_208 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
if ( V_6 -> V_168 == V_169 )
return - V_60 ;
if ( 0 != V_208 -> V_19 )
return - V_60 ;
strcpy ( V_208 -> V_39 , L_25 ) ;
F_13 ( V_6 , V_209 , V_210 , V_208 ) ;
return 0 ;
}
static int F_81 ( struct V_136 * V_136 , void * V_137 ,
const struct V_207 * V_208 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
if ( V_6 -> V_168 == V_169 )
return - V_60 ;
if ( 0 != V_208 -> V_19 )
return - V_60 ;
F_13 ( V_6 , V_209 , V_211 , V_208 ) ;
return 0 ;
}
static int F_82 ( struct V_136 * V_136 , void * V_137 ,
struct V_212 * V_139 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
if ( V_6 -> V_168 == V_169 )
return - V_60 ;
V_139 -> type = V_213 ;
V_139 -> V_214 = V_6 -> V_215 ;
F_13 ( V_6 , V_209 , V_216 , V_139 ) ;
return 0 ;
}
static int F_83 ( struct V_5 * V_6 , const struct V_212 * V_139 )
{
struct V_217 * V_218 ;
int V_219 = 1 ;
if ( V_6 -> V_168 == V_169 )
return - V_60 ;
if ( F_66 ( V_139 -> V_209 != 0 ) )
return - V_60 ;
V_6 -> V_215 = V_139 -> V_214 ;
V_218 = F_84 ( & V_6 -> V_220 , V_221 ) ;
if ( V_218 ) {
V_219 = F_85 ( V_218 ) ;
if ( ! V_219 )
F_86 ( V_218 , 1 ) ;
}
F_13 ( V_6 , V_209 , V_222 , V_139 ) ;
F_87 ( 100 ) ;
if ( V_219 == 0 )
F_86 ( V_218 , V_219 ) ;
return 0 ;
}
static int F_88 ( struct V_5 * V_6 ,
const struct V_212 * V_139 )
{
struct V_217 * V_218 ;
int V_219 = 1 ;
struct V_223 * V_224 ;
struct V_225 * V_226 ;
struct V_227 V_228 = {
. V_229 = V_213 ,
. V_230 = V_231 ,
. V_195 = V_6 -> V_23 ,
. V_214 = V_139 -> V_214
} ;
V_6 -> V_215 = V_139 -> V_214 ;
V_218 = F_84 ( & V_6 -> V_220 , V_221 ) ;
if ( V_218 ) {
V_219 = F_85 ( V_218 ) ;
if ( ! V_219 )
F_86 ( V_218 , 1 ) ;
}
F_7 ( 1 , L_35 , V_22 ,
V_228 . V_214 , V_139 -> V_209 , V_228 . V_195 ) ;
V_224 = F_89 ( & V_6 -> V_232 . V_233 , 1 ) ;
if ( ! V_224 ) {
return - V_60 ;
}
V_226 = V_224 -> V_234 . V_235 ;
if ( ( V_6 -> V_41 == V_81 ) ||
( V_6 -> V_41 == V_79 ) ||
( V_6 -> V_41 == V_80 ) )
V_226 = & V_6 -> V_236 . V_237 ;
if ( V_226 && V_226 -> V_238 . V_239 . V_240 ) {
F_13 ( V_6 , V_28 , V_29 , V_6 -> V_23 ) ;
V_226 -> V_238 . V_239 . V_240 ( V_226 , & V_228 ) ;
}
else
F_20 ( V_55 L_36 , V_22 ) ;
F_87 ( 100 ) ;
if ( V_219 == 0 )
F_86 ( V_218 , V_219 ) ;
return 0 ;
}
int F_90 ( struct V_136 * V_136 , void * V_137 ,
const struct V_212 * V_139 )
{
struct V_5 * V_6 = F_53 ( V_136 ) ;
int V_51 ;
switch ( V_6 -> V_41 ) {
case V_79 :
case V_80 :
case V_81 :
V_51 = F_88 ( V_6 , V_139 ) ;
break;
default:
V_51 = F_83 ( V_6 , V_139 ) ;
}
return V_51 ;
}
static int F_91 ( struct V_136 * V_136 , void * V_137 ,
const struct V_212 * V_139 )
{
return F_90 ( V_136 , V_137 , V_139 ) ;
}
int F_92 ( struct V_5 * V_6 , T_1 V_200 )
{
T_1 V_241 , V_9 ;
int V_242 = 0 ;
V_241 = F_93 ( V_94 ) ;
if ( 0 == ( V_200 & V_241 ) )
return V_242 ;
F_31 ( V_243 , V_200 ) ;
if ( ( V_200 & V_244 ) ||
( V_200 & V_245 ) ||
( V_200 & V_246 ) ) {
if ( V_200 & V_244 ) {
F_7 ( 7 , L_37 ,
V_244 ) ;
F_20 ( V_247 L_38 ,
V_6 -> V_39 ) ;
F_94 ( V_6 ,
& V_6 -> V_88 [ V_89 ] ) ;
}
if ( V_200 & V_245 )
F_7 ( 7 , L_39
L_40 ,
V_245 ) ;
if ( V_200 & V_246 )
F_7 ( 7 , L_41 ,
V_246 ) ;
}
if ( V_200 & V_248 ) {
F_95 ( & V_6 -> V_132 ) ;
V_9 = F_93 ( V_249 ) ;
F_3 ( V_6 , & V_6 -> V_127 , V_9 ) ;
F_96 ( & V_6 -> V_132 ) ;
V_242 ++ ;
}
V_242 += F_97 ( V_6 , V_200 ) ;
return V_242 ;
}
void F_98 ( struct V_5 * V_6 )
{
F_7 ( 1 , L_3 , V_22 ) ;
F_99 ( V_6 , 0x01 ) ;
if ( V_6 -> V_250 ) {
if ( F_100 ( V_6 -> V_250 ) )
F_101 ( V_6 -> V_250 ) ;
else
V_37 ( V_6 -> V_250 ) ;
V_6 -> V_250 = NULL ;
}
if ( V_6 -> V_251 ) {
if ( F_100 ( V_6 -> V_251 ) )
F_101 ( V_6 -> V_251 ) ;
else
V_37 ( V_6 -> V_251 ) ;
V_6 -> V_251 = NULL ;
}
if ( V_6 -> V_252 )
F_102 ( V_6 ) ;
}
int F_103 ( struct V_5 * V_6 )
{
struct V_96 * V_8 ;
int V_154 ;
F_7 ( 1 , L_3 , V_22 ) ;
V_253 = V_254 ;
strcpy ( V_253 . V_39 , L_42 ) ;
V_6 -> V_23 = V_255 ;
V_6 -> V_103 = F_1 ( V_256 ) ;
V_6 -> V_116 = V_121 ;
V_6 -> V_105 = 720 ;
V_6 -> V_106 = F_56 ( V_6 -> V_23 ) ;
F_104 ( & V_6 -> V_127 . V_12 ) ;
F_104 ( & V_6 -> V_257 . V_12 ) ;
F_32 ( V_6 , 0x01 ) ;
if ( ( V_169 != V_6 -> V_168 ) &&
( ( V_6 -> V_258 == 0 ) || ( V_6 -> V_258 == 1 ) ) ) {
struct V_259 * V_260 = NULL ;
if ( V_6 -> V_261 )
V_260 = F_105 ( & V_6 -> V_35 ,
& V_6 -> V_49 [ V_6 -> V_258 ] . V_50 ,
L_43 , V_6 -> V_261 , NULL ) ;
else
V_260 = F_105 ( & V_6 -> V_35 ,
& V_6 -> V_49 [ V_6 -> V_258 ] . V_50 ,
L_43 , 0 , F_106 ( V_262 ) ) ;
if ( V_260 ) {
struct V_263 V_264 ;
memset ( & V_264 , 0 , sizeof( V_264 ) ) ;
V_264 . V_265 = V_266 ;
V_264 . type = V_6 -> V_168 ;
V_264 . V_46 = F_107 ( V_260 ) ;
V_264 . V_267 = V_268 ;
F_26 ( V_260 , V_209 , V_269 , & V_264 ) ;
if ( ( V_6 -> V_41 == V_270 ) ||
( V_6 -> V_41 == V_271 ) ) {
struct V_272 V_273 = {
. V_274 = V_275 ,
. V_276 = 64
} ;
struct V_277 V_278 = {
. V_209 = V_6 -> V_168 ,
. V_137 = & V_273
} ;
F_26 ( V_260 , V_209 , V_279 , & V_278 ) ;
}
if ( V_6 -> V_41 == V_82 ) {
struct V_272 V_273 = {
. V_274 = L_44 ,
. V_276 = 64
} ;
struct V_277 V_278 = {
. V_209 = V_6 -> V_168 ,
. V_137 = & V_273
} ;
F_26 ( V_260 , V_209 , V_279 , & V_278 ) ;
}
}
}
F_108 ( & V_6 -> V_38 ) ;
F_10 ( V_6 , V_6 -> V_23 ) ;
F_23 ( V_6 , 0 ) ;
F_27 ( V_6 , 0 ) ;
F_109 ( & V_6 -> V_38 ) ;
V_8 = & V_6 -> V_24 ;
V_8 -> type = V_280 ;
V_8 -> V_281 = V_282 | V_283 | V_284 | V_285 ;
V_8 -> V_286 = V_287 ;
V_8 -> V_288 = 2 ;
V_8 -> V_102 = V_6 ;
V_8 -> V_289 = sizeof( struct V_10 ) ;
V_8 -> V_238 = & V_290 ;
V_8 -> V_291 = & V_292 ;
V_8 -> V_293 = V_294 ;
V_8 -> V_38 = & V_6 -> V_38 ;
V_154 = F_110 ( V_8 ) ;
if ( V_154 < 0 )
goto V_295;
V_8 = & V_6 -> V_25 ;
V_8 -> type = V_296 ;
V_8 -> V_281 = V_282 | V_283 | V_284 | V_285 ;
V_8 -> V_286 = V_287 ;
V_8 -> V_288 = 2 ;
V_8 -> V_102 = V_6 ;
V_8 -> V_289 = sizeof( struct V_10 ) ;
V_8 -> V_238 = & V_297 ;
V_8 -> V_291 = & V_292 ;
V_8 -> V_293 = V_294 ;
V_8 -> V_38 = & V_6 -> V_38 ;
V_154 = F_110 ( V_8 ) ;
if ( V_154 < 0 )
goto V_295;
V_6 -> V_251 = F_14 ( V_6 , V_6 -> V_32 ,
& V_254 , L_45 ) ;
V_6 -> V_251 -> V_14 = & V_6 -> V_24 ;
V_154 = F_111 ( V_6 -> V_251 , V_298 ,
V_299 [ V_6 -> V_300 ] ) ;
if ( V_154 < 0 ) {
F_20 ( V_301 L_46 ,
V_6 -> V_39 ) ;
goto V_295;
}
F_20 ( V_301 L_47 ,
V_6 -> V_39 , F_112 ( V_6 -> V_251 ) ) ;
V_6 -> V_250 = F_14 ( V_6 , V_6 -> V_32 ,
& V_253 , L_48 ) ;
V_6 -> V_250 -> V_14 = & V_6 -> V_25 ;
V_154 = F_111 ( V_6 -> V_250 , V_172 ,
V_302 [ V_6 -> V_300 ] ) ;
if ( V_154 < 0 ) {
F_20 ( V_301 L_49 ,
V_6 -> V_39 ) ;
goto V_295;
}
F_20 ( V_301 L_50 ,
V_6 -> V_39 , F_112 ( V_6 -> V_250 ) ) ;
V_6 -> V_252 = F_113 ( V_6 ) ;
return 0 ;
V_295:
F_98 ( V_6 ) ;
return V_154 ;
}
