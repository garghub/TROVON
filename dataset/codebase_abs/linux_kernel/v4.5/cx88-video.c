static const struct V_1 * F_1 ( unsigned int V_2 )
{
unsigned int V_3 ;
for ( V_3 = 0 ; V_3 < F_2 ( V_4 ) ; V_3 ++ )
if ( V_4 [ V_3 ] . V_2 == V_2 )
return V_4 + V_3 ;
return NULL ;
}
int F_3 ( struct V_5 * V_6 , unsigned int V_7 )
{
F_4 ( 1 , L_1 ,
V_7 , F_5 ( V_7 ) . V_8 ,
F_5 ( V_7 ) . V_9 , F_5 ( V_7 ) . V_10 ,
F_5 ( V_7 ) . V_11 , F_5 ( V_7 ) . V_12 ) ;
V_6 -> V_7 = V_7 ;
F_6 ( V_13 , 0x03 << 14 , F_5 ( V_7 ) . V_8 << 14 ) ;
F_7 ( V_14 , F_5 ( V_7 ) . V_12 ) ;
F_7 ( V_15 , F_5 ( V_7 ) . V_9 ) ;
F_7 ( V_16 , F_5 ( V_7 ) . V_10 ) ;
F_7 ( V_17 , F_5 ( V_7 ) . V_11 ) ;
switch ( F_5 ( V_7 ) . type ) {
case V_18 :
F_8 ( V_19 , 0x00000001 ) ;
F_8 ( V_13 , 0x00010010 ) ;
F_8 ( V_20 , 0x00002020 ) ;
F_8 ( V_21 , 0x00002020 ) ;
break;
default:
F_9 ( V_19 , 0x00000001 ) ;
F_9 ( V_13 , 0x00010010 ) ;
F_9 ( V_20 , 0x00002020 ) ;
F_9 ( V_21 , 0x00002020 ) ;
break;
}
if ( F_5 ( V_7 ) . V_22 ) {
if ( V_6 -> V_23 ) {
F_10 ( V_6 , V_24 , V_25 ,
F_5 ( V_7 ) . V_22 , 0 , 0 ) ;
}
if ( F_5 ( V_7 ) . type != V_26 &&
F_5 ( V_7 ) . type != V_27 ) {
V_6 -> V_28 = V_29 ;
F_11 ( V_6 ) ;
} else {
F_7 ( V_30 , 0x0 ) ;
F_9 ( V_31 , V_32 ) ;
}
}
return 0 ;
}
static int F_12 ( struct V_33 * V_34 ,
struct V_35 * V_36 ,
struct V_37 * V_38 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
F_13 ( V_6 , & V_39 [ V_40 ] ,
V_38 -> V_41 , V_38 -> V_42 . V_43 ) ;
F_14 ( V_6 , V_6 -> V_44 , V_6 -> V_45 , V_6 -> V_46 ) ;
F_7 ( V_47 , V_34 -> V_48 -> V_49 | V_50 ) ;
F_7 ( V_51 , V_52 ) ;
V_36 -> V_53 = 0 ;
F_8 ( V_54 , V_6 -> V_55 | V_56 ) ;
F_8 ( V_57 , 0x0f0011 ) ;
F_8 ( V_58 , 0x06 ) ;
F_8 ( V_59 , ( 1 << 5 ) ) ;
F_8 ( V_60 , 0x11 ) ;
return 0 ;
}
static int F_15 ( struct V_33 * V_34 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
F_9 ( V_60 , 0x11 ) ;
F_9 ( V_58 , 0x06 ) ;
F_9 ( V_54 , V_56 ) ;
F_9 ( V_57 , 0x0f0011 ) ;
return 0 ;
}
static int F_16 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
struct V_37 * V_38 ;
if ( ! F_17 ( & V_36 -> V_61 ) ) {
V_38 = F_18 ( V_36 -> V_61 . V_62 , struct V_37 , V_63 ) ;
F_4 ( 2 , L_2 ,
V_38 , V_38 -> V_64 . V_65 . V_66 ) ;
F_12 ( V_34 , V_36 , V_38 ) ;
}
return 0 ;
}
static int F_19 ( struct V_67 * V_36 ,
unsigned int * V_68 , unsigned int * V_69 ,
unsigned int V_70 [] , void * V_71 [] )
{
struct V_33 * V_34 = V_36 -> V_72 ;
struct V_5 * V_6 = V_34 -> V_6 ;
* V_69 = 1 ;
V_70 [ 0 ] = ( V_34 -> V_48 -> V_73 * V_6 -> V_44 * V_6 -> V_45 ) >> 3 ;
V_71 [ 0 ] = V_34 -> V_74 ;
return 0 ;
}
static int F_20 ( struct V_75 * V_64 )
{
struct V_76 * V_77 = F_21 ( V_64 ) ;
struct V_33 * V_34 = V_64 -> V_67 -> V_72 ;
struct V_5 * V_6 = V_34 -> V_6 ;
struct V_37 * V_38 = F_22 ( V_77 , struct V_37 , V_64 ) ;
struct V_78 * V_79 = F_23 ( V_64 , 0 ) ;
V_38 -> V_41 = V_6 -> V_44 * V_34 -> V_48 -> V_73 >> 3 ;
if ( F_24 ( V_64 , 0 ) < V_6 -> V_45 * V_38 -> V_41 )
return - V_80 ;
F_25 ( V_64 , 0 , V_6 -> V_45 * V_38 -> V_41 ) ;
switch ( V_6 -> V_46 ) {
case V_81 :
F_26 ( V_34 -> V_82 , & V_38 -> V_42 ,
V_79 -> V_83 , 0 , V_84 ,
V_38 -> V_41 , 0 , V_6 -> V_45 ) ;
break;
case V_85 :
F_26 ( V_34 -> V_82 , & V_38 -> V_42 ,
V_79 -> V_83 , V_84 , 0 ,
V_38 -> V_41 , 0 , V_6 -> V_45 ) ;
break;
case V_86 :
F_26 ( V_34 -> V_82 , & V_38 -> V_42 ,
V_79 -> V_83 ,
0 , V_38 -> V_41 * ( V_6 -> V_45 >> 1 ) ,
V_38 -> V_41 , 0 ,
V_6 -> V_45 >> 1 ) ;
break;
case V_87 :
F_26 ( V_34 -> V_82 , & V_38 -> V_42 ,
V_79 -> V_83 ,
V_38 -> V_41 * ( V_6 -> V_45 >> 1 ) , 0 ,
V_38 -> V_41 , 0 ,
V_6 -> V_45 >> 1 ) ;
break;
case V_88 :
default:
F_26 ( V_34 -> V_82 , & V_38 -> V_42 ,
V_79 -> V_83 , 0 , V_38 -> V_41 ,
V_38 -> V_41 , V_38 -> V_41 ,
V_6 -> V_45 >> 1 ) ;
break;
}
F_4 ( 2 , L_3 ,
V_38 , V_38 -> V_64 . V_65 . V_66 ,
V_6 -> V_44 , V_6 -> V_45 , V_34 -> V_48 -> V_73 , V_34 -> V_48 -> V_89 ,
( unsigned long ) V_38 -> V_42 . V_43 ) ;
return 0 ;
}
static void F_27 ( struct V_75 * V_64 )
{
struct V_76 * V_77 = F_21 ( V_64 ) ;
struct V_33 * V_34 = V_64 -> V_67 -> V_72 ;
struct V_37 * V_38 = F_22 ( V_77 , struct V_37 , V_64 ) ;
struct V_90 * V_42 = & V_38 -> V_42 ;
if ( V_42 -> V_91 )
F_28 ( V_34 -> V_82 , V_42 -> V_92 , V_42 -> V_91 , V_42 -> V_43 ) ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
}
static void F_29 ( struct V_75 * V_64 )
{
struct V_76 * V_77 = F_21 ( V_64 ) ;
struct V_33 * V_34 = V_64 -> V_67 -> V_72 ;
struct V_37 * V_38 = F_22 ( V_77 , struct V_37 , V_64 ) ;
struct V_37 * V_93 ;
struct V_5 * V_6 = V_34 -> V_6 ;
struct V_35 * V_36 = & V_34 -> V_94 ;
V_38 -> V_42 . V_91 [ 1 ] = F_30 ( V_38 -> V_42 . V_43 + 8 ) ;
V_38 -> V_42 . V_95 [ 0 ] = F_30 ( V_96 | V_97 ) ;
V_38 -> V_42 . V_95 [ 1 ] = F_30 ( V_38 -> V_42 . V_43 + 8 ) ;
if ( F_17 ( & V_36 -> V_61 ) ) {
F_31 ( & V_38 -> V_63 , & V_36 -> V_61 ) ;
F_4 ( 2 , L_4 ,
V_38 , V_38 -> V_64 . V_65 . V_66 ) ;
} else {
V_38 -> V_42 . V_91 [ 0 ] |= F_30 ( V_98 ) ;
V_93 = F_18 ( V_36 -> V_61 . V_93 , struct V_37 , V_63 ) ;
F_31 ( & V_38 -> V_63 , & V_36 -> V_61 ) ;
V_93 -> V_42 . V_95 [ 1 ] = F_30 ( V_38 -> V_42 . V_43 ) ;
F_4 ( 2 , L_5 ,
V_38 , V_38 -> V_64 . V_65 . V_66 ) ;
}
}
static int F_32 ( struct V_67 * V_36 , unsigned int V_53 )
{
struct V_33 * V_34 = V_36 -> V_72 ;
struct V_35 * V_99 = & V_34 -> V_94 ;
struct V_37 * V_38 = F_18 ( V_99 -> V_61 . V_62 ,
struct V_37 , V_63 ) ;
F_12 ( V_34 , V_99 , V_38 ) ;
return 0 ;
}
static void F_33 ( struct V_67 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_72 ;
struct V_5 * V_6 = V_34 -> V_6 ;
struct V_35 * V_99 = & V_34 -> V_94 ;
unsigned long V_100 ;
F_9 ( V_60 , 0x11 ) ;
F_9 ( V_58 , 0x06 ) ;
F_34 ( & V_34 -> V_101 , V_100 ) ;
while ( ! F_17 ( & V_99 -> V_61 ) ) {
struct V_37 * V_38 = F_18 ( V_99 -> V_61 . V_62 ,
struct V_37 , V_63 ) ;
F_35 ( & V_38 -> V_63 ) ;
F_36 ( & V_38 -> V_64 . V_65 , V_102 ) ;
}
F_37 ( & V_34 -> V_101 , V_100 ) ;
}
static int F_38 ( struct V_103 * V_103 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
int V_104 = F_40 ( V_103 ) ;
if ( V_104 )
return V_104 ;
F_7 ( V_14 , V_6 -> V_105 . V_106 . V_12 ) ;
F_7 ( V_15 , V_6 -> V_105 . V_106 . V_9 ) ;
F_7 ( V_16 , V_6 -> V_105 . V_106 . V_10 ) ;
F_7 ( V_17 , V_6 -> V_105 . V_106 . V_11 ) ;
if ( V_6 -> V_105 . V_106 . V_22 ) {
if ( V_6 -> V_23 ) {
F_10 ( V_6 , V_24 , V_25 ,
V_6 -> V_105 . V_106 . V_22 , 0 , 0 ) ;
}
V_6 -> V_28 = V_29 ;
F_11 ( V_6 ) ;
} else {
V_6 -> V_28 = V_107 ;
F_11 ( V_6 ) ;
F_41 ( V_6 , V_108 , 1 ) ;
}
F_10 ( V_6 , V_109 , V_110 ) ;
return 0 ;
}
static int F_42 ( struct V_111 * V_112 )
{
struct V_5 * V_6 =
F_22 ( V_112 -> V_113 , struct V_5 , V_114 ) ;
const struct V_115 * V_116 = V_112 -> V_117 ;
T_1 V_118 , V_119 ;
V_119 = V_116 -> V_119 ;
switch ( V_112 -> V_120 ) {
case V_121 :
V_118 = ( ( V_112 -> V_122 - V_116 -> V_123 ) << V_116 -> V_124 ) & V_116 -> V_119 ;
if ( V_6 -> V_125 & V_126 ) {
V_118 = V_118 << 8 | V_118 ;
} else {
V_118 = ( V_118 * 0x5a ) / 0x7f << 8 | V_118 ;
}
V_119 = 0xffff ;
break;
case V_127 :
V_118 = ( V_112 -> V_122 < 1 ? 0 : ( ( V_112 -> V_122 + 3 ) << 7 ) ) ;
F_6 ( V_20 , V_119 , V_118 ) ;
break;
case V_128 :
V_118 = ( ( V_112 -> V_122 - V_116 -> V_123 ) << V_116 -> V_124 ) & V_116 -> V_119 ;
break;
default:
V_118 = ( ( V_112 -> V_122 - V_116 -> V_123 ) << V_116 -> V_124 ) & V_116 -> V_119 ;
break;
}
F_4 ( 1 , L_6 ,
V_112 -> V_120 , V_112 -> V_89 , V_112 -> V_122 , V_116 -> V_129 , V_118 ,
V_119 , V_116 -> V_130 ? L_7 : L_8 ) ;
if ( V_116 -> V_130 )
F_43 ( V_116 -> V_130 , V_116 -> V_129 , V_119 , V_118 ) ;
else
F_6 ( V_116 -> V_129 , V_119 , V_118 ) ;
return 0 ;
}
static int F_44 ( struct V_111 * V_112 )
{
struct V_5 * V_6 =
F_22 ( V_112 -> V_113 , struct V_5 , V_131 ) ;
const struct V_115 * V_116 = V_112 -> V_117 ;
T_1 V_118 , V_119 ;
if ( V_6 -> V_23 ) {
switch ( V_112 -> V_120 ) {
case V_132 :
F_45 ( V_6 , V_112 -> V_120 , V_112 -> V_122 ) ;
break;
case V_133 :
F_45 ( V_6 , V_112 -> V_120 , ( V_112 -> V_122 ) ?
( 0x90 + V_112 -> V_122 ) << 8 : 0 ) ;
break;
case V_134 :
F_45 ( V_6 , V_112 -> V_120 , V_112 -> V_122 << 9 ) ;
break;
default:
break;
}
}
V_119 = V_116 -> V_119 ;
switch ( V_112 -> V_120 ) {
case V_134 :
V_118 = ( V_112 -> V_122 < 0x40 ) ? ( 0x7f - V_112 -> V_122 ) : ( V_112 -> V_122 - 0x40 ) ;
break;
case V_133 :
V_118 = 0x3f - ( V_112 -> V_122 & 0x3f ) ;
break;
default:
V_118 = ( ( V_112 -> V_122 - V_116 -> V_123 ) << V_116 -> V_124 ) & V_116 -> V_119 ;
break;
}
F_4 ( 1 , L_6 ,
V_112 -> V_120 , V_112 -> V_89 , V_112 -> V_122 , V_116 -> V_129 , V_118 ,
V_119 , V_116 -> V_130 ? L_7 : L_8 ) ;
if ( V_116 -> V_130 )
F_43 ( V_116 -> V_130 , V_116 -> V_129 , V_119 , V_118 ) ;
else
F_6 ( V_116 -> V_129 , V_119 , V_118 ) ;
return 0 ;
}
static int F_46 ( struct V_103 * V_103 , void * V_117 ,
struct V_135 * V_136 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
V_136 -> V_48 . V_137 . V_44 = V_6 -> V_44 ;
V_136 -> V_48 . V_137 . V_45 = V_6 -> V_45 ;
V_136 -> V_48 . V_137 . V_46 = V_6 -> V_46 ;
V_136 -> V_48 . V_137 . V_138 = V_34 -> V_48 -> V_2 ;
V_136 -> V_48 . V_137 . V_139 =
( V_136 -> V_48 . V_137 . V_44 * V_34 -> V_48 -> V_73 ) >> 3 ;
V_136 -> V_48 . V_137 . V_140 =
V_136 -> V_48 . V_137 . V_45 * V_136 -> V_48 . V_137 . V_139 ;
V_136 -> V_48 . V_137 . V_141 = V_142 ;
return 0 ;
}
static int F_47 ( struct V_103 * V_103 , void * V_117 ,
struct V_135 * V_136 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
const struct V_1 * V_48 ;
enum V_143 V_46 ;
unsigned int V_144 , V_145 ;
V_48 = F_1 ( V_136 -> V_48 . V_137 . V_138 ) ;
if ( NULL == V_48 )
return - V_80 ;
V_144 = F_48 ( V_6 -> V_125 ) ;
V_145 = F_49 ( V_6 -> V_125 ) ;
V_46 = V_136 -> V_48 . V_137 . V_46 ;
switch ( V_46 ) {
case V_81 :
case V_85 :
case V_88 :
case V_87 :
case V_86 :
break;
default:
V_46 = ( V_136 -> V_48 . V_137 . V_45 > V_145 / 2 )
? V_88
: V_85 ;
break;
}
if ( F_50 ( V_46 ) )
V_145 /= 2 ;
F_51 ( & V_136 -> V_48 . V_137 . V_44 , 48 , V_144 , 2 ,
& V_136 -> V_48 . V_137 . V_45 , 32 , V_145 , 0 , 0 ) ;
V_136 -> V_48 . V_137 . V_46 = V_46 ;
V_136 -> V_48 . V_137 . V_139 =
( V_136 -> V_48 . V_137 . V_44 * V_48 -> V_73 ) >> 3 ;
V_136 -> V_48 . V_137 . V_140 =
V_136 -> V_48 . V_137 . V_45 * V_136 -> V_48 . V_137 . V_139 ;
V_136 -> V_48 . V_137 . V_141 = V_142 ;
return 0 ;
}
static int F_52 ( struct V_103 * V_103 , void * V_117 ,
struct V_135 * V_136 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
int V_146 = F_47 ( V_103 , V_117 , V_136 ) ;
if ( 0 != V_146 )
return V_146 ;
if ( F_53 ( & V_34 -> V_147 ) || F_53 ( & V_34 -> V_148 ) )
return - V_149 ;
if ( V_6 -> V_150 && F_53 ( & V_6 -> V_150 -> V_151 ) )
return - V_149 ;
V_34 -> V_48 = F_1 ( V_136 -> V_48 . V_137 . V_138 ) ;
V_6 -> V_44 = V_136 -> V_48 . V_137 . V_44 ;
V_6 -> V_45 = V_136 -> V_48 . V_137 . V_45 ;
V_6 -> V_46 = V_136 -> V_48 . V_137 . V_46 ;
return 0 ;
}
void F_54 ( struct V_103 * V_103 , struct V_5 * V_6 ,
struct V_152 * V_153 )
{
struct V_154 * V_155 = F_55 ( V_103 ) ;
F_56 ( V_153 -> V_156 , V_6 -> V_105 . V_89 , sizeof( V_153 -> V_156 ) ) ;
V_153 -> V_157 = V_158 | V_159 ;
if ( V_84 != V_6 -> V_105 . V_160 )
V_153 -> V_157 |= V_161 ;
switch ( V_155 -> V_162 ) {
case V_163 :
V_153 -> V_157 = V_164 | V_161 ;
break;
case V_165 :
V_153 -> V_157 |= V_166 ;
break;
case V_167 :
V_153 -> V_157 |= V_168 ;
break;
}
V_153 -> V_169 = V_153 -> V_157 | V_166 |
V_168 | V_170 ;
if ( V_6 -> V_105 . V_106 . type == V_171 )
V_153 -> V_169 |= V_164 ;
}
static int F_57 ( struct V_103 * V_103 , void * V_117 ,
struct V_152 * V_153 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
strcpy ( V_153 -> V_172 , L_9 ) ;
sprintf ( V_153 -> V_173 , L_10 , F_58 ( V_34 -> V_82 ) ) ;
F_54 ( V_103 , V_6 , V_153 ) ;
return 0 ;
}
static int F_59 ( struct V_103 * V_103 , void * V_117 ,
struct V_174 * V_136 )
{
if ( F_60 ( V_136 -> V_66 >= F_2 ( V_4 ) ) )
return - V_80 ;
F_56 ( V_136 -> V_175 , V_4 [ V_136 -> V_66 ] . V_89 , sizeof( V_136 -> V_175 ) ) ;
V_136 -> V_138 = V_4 [ V_136 -> V_66 ] . V_2 ;
return 0 ;
}
static int F_61 ( struct V_103 * V_103 , void * V_117 , T_2 * V_125 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
* V_125 = V_6 -> V_125 ;
return 0 ;
}
static int F_62 ( struct V_103 * V_103 , void * V_117 , T_2 V_176 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
return F_63 ( V_6 , V_176 ) ;
}
int F_64 ( struct V_5 * V_6 , struct V_177 * V_3 )
{
static const char * const V_178 [] = {
[ V_179 ] = L_11 ,
[ V_180 ] = L_12 ,
[ V_181 ] = L_13 ,
[ V_182 ] = L_14 ,
[ V_18 ] = L_15 ,
[ V_26 ] = L_16 ,
[ V_27 ] = L_17 ,
[ V_183 ] = L_18 ,
[ V_184 ] = L_19 ,
} ;
unsigned int V_185 = V_3 -> V_66 ;
if ( V_185 >= 4 )
return - V_80 ;
if ( 0 == F_5 ( V_185 ) . type )
return - V_80 ;
V_3 -> type = V_186 ;
strcpy ( V_3 -> V_89 , V_178 [ F_5 ( V_185 ) . type ] ) ;
if ( ( V_26 == F_5 ( V_185 ) . type ) ||
( V_27 == F_5 ( V_185 ) . type ) ) {
V_3 -> type = V_187 ;
}
V_3 -> V_188 = V_189 ;
return 0 ;
}
static int F_65 ( struct V_103 * V_103 , void * V_117 ,
struct V_177 * V_3 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
return F_64 ( V_6 , V_3 ) ;
}
static int F_66 ( struct V_103 * V_103 , void * V_117 , unsigned int * V_3 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
* V_3 = V_6 -> V_7 ;
return 0 ;
}
static int F_67 ( struct V_103 * V_103 , void * V_117 , unsigned int V_3 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( V_3 >= 4 )
return - V_80 ;
if ( 0 == F_5 ( V_3 ) . type )
return - V_80 ;
F_68 ( V_6 ) ;
F_3 ( V_6 , V_3 ) ;
return 0 ;
}
static int F_69 ( struct V_103 * V_103 , void * V_117 ,
struct V_190 * V_191 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
T_1 V_129 ;
if ( F_60 ( V_84 == V_6 -> V_105 . V_160 ) )
return - V_80 ;
if ( 0 != V_191 -> V_66 )
return - V_80 ;
strcpy ( V_191 -> V_89 , L_16 ) ;
V_191 -> V_192 = V_193 ;
V_191 -> V_194 = 0xffffffffUL ;
F_10 ( V_6 , V_109 , V_195 , V_191 ) ;
F_70 ( V_6 , V_191 ) ;
V_129 = F_71 ( V_196 ) ;
V_191 -> signal = ( V_129 & ( 1 << 5 ) ) ? 0xffff : 0x0000 ;
return 0 ;
}
static int F_72 ( struct V_103 * V_103 , void * V_117 ,
const struct V_190 * V_191 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( V_84 == V_6 -> V_105 . V_160 )
return - V_80 ;
if ( 0 != V_191 -> V_66 )
return - V_80 ;
F_41 ( V_6 , V_191 -> V_197 , 1 ) ;
return 0 ;
}
static int F_73 ( struct V_103 * V_103 , void * V_117 ,
struct V_198 * V_136 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( F_60 ( V_84 == V_6 -> V_105 . V_160 ) )
return - V_80 ;
if ( V_136 -> V_109 )
return - V_80 ;
V_136 -> V_199 = V_6 -> V_200 ;
F_10 ( V_6 , V_109 , V_201 , V_136 ) ;
return 0 ;
}
int F_74 ( struct V_5 * V_6 ,
const struct V_198 * V_136 )
{
struct V_198 V_202 = * V_136 ;
if ( F_60 ( V_84 == V_6 -> V_105 . V_160 ) )
return - V_80 ;
if ( F_60 ( V_136 -> V_109 != 0 ) )
return - V_80 ;
F_68 ( V_6 ) ;
F_10 ( V_6 , V_109 , V_203 , V_136 ) ;
F_10 ( V_6 , V_109 , V_201 , & V_202 ) ;
V_6 -> V_200 = V_202 . V_199 ;
F_75 ( 10 ) ;
F_11 ( V_6 ) ;
return 0 ;
}
static int F_76 ( struct V_103 * V_103 , void * V_117 ,
const struct V_198 * V_136 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
return F_74 ( V_6 , V_136 ) ;
}
static int F_77 ( struct V_103 * V_103 , void * V_204 ,
struct V_205 * V_129 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
V_129 -> V_122 = F_71 ( V_129 -> V_129 & 0xfffffc ) ;
V_129 -> V_92 = 4 ;
return 0 ;
}
static int F_78 ( struct V_103 * V_103 , void * V_204 ,
const struct V_205 * V_129 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
F_7 ( V_129 -> V_129 & 0xfffffc , V_129 -> V_122 ) ;
return 0 ;
}
static int F_79 ( struct V_103 * V_103 , void * V_117 ,
struct V_190 * V_191 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( F_60 ( V_191 -> V_66 > 0 ) )
return - V_80 ;
strcpy ( V_191 -> V_89 , L_20 ) ;
F_10 ( V_6 , V_109 , V_195 , V_191 ) ;
return 0 ;
}
static int F_80 ( struct V_103 * V_103 , void * V_117 ,
const struct V_190 * V_191 )
{
struct V_33 * V_34 = F_39 ( V_103 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( 0 != V_191 -> V_66 )
return - V_80 ;
F_10 ( V_6 , V_109 , V_206 , V_191 ) ;
return 0 ;
}
static void F_81 ( struct V_33 * V_34 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
T_1 V_207 , V_119 , V_53 ;
V_207 = F_71 ( V_208 ) ;
V_119 = F_71 ( V_57 ) ;
if ( 0 == ( V_207 & V_119 ) )
return;
F_7 ( V_208 , V_207 ) ;
if ( V_209 || ( V_207 & V_119 & ~ 0xff ) )
F_82 ( V_6 -> V_89 , L_21 ,
V_210 , F_2 ( V_210 ) ,
V_207 , V_119 ) ;
if ( V_207 & ( 1 << 16 ) ) {
F_83 ( V_211 L_22 , V_6 -> V_89 ) ;
F_9 ( V_60 , 0x11 ) ;
F_9 ( V_58 , 0x06 ) ;
F_84 ( V_6 , & V_39 [ V_40 ] ) ;
}
if ( V_207 & 0x01 ) {
F_85 ( & V_34 -> V_101 ) ;
V_53 = F_71 ( V_212 ) ;
F_86 ( V_6 , & V_34 -> V_94 , V_53 ) ;
F_87 ( & V_34 -> V_101 ) ;
}
if ( V_207 & 0x08 ) {
F_85 ( & V_34 -> V_101 ) ;
V_53 = F_71 ( V_213 ) ;
F_86 ( V_6 , & V_34 -> V_214 , V_53 ) ;
F_87 ( & V_34 -> V_101 ) ;
}
}
static T_3 F_88 ( int V_215 , void * V_216 )
{
struct V_33 * V_34 = V_216 ;
struct V_5 * V_6 = V_34 -> V_6 ;
T_1 V_207 ;
int V_217 , V_218 = 0 ;
for ( V_217 = 0 ; V_217 < 10 ; V_217 ++ ) {
V_207 = F_71 ( V_219 ) &
( V_6 -> V_55 | V_56 ) ;
if ( 0 == V_207 )
goto V_220;
F_7 ( V_219 , V_207 ) ;
V_218 = 1 ;
if ( V_207 & V_6 -> V_55 )
F_89 ( V_6 , V_207 ) ;
if ( V_207 & V_56 )
F_81 ( V_34 ) ;
}
if ( 10 == V_217 ) {
F_83 ( V_211 L_23 ,
V_6 -> V_89 ) ;
F_7 ( V_54 , 0 ) ;
}
V_220:
return F_90 ( V_218 ) ;
}
static void F_91 ( struct V_33 * V_34 )
{
F_92 ( & V_34 -> V_221 ) ;
F_92 ( & V_34 -> V_222 ) ;
F_92 ( & V_34 -> V_223 ) ;
}
static int F_93 ( struct V_224 * V_224 ,
const struct V_225 * V_226 )
{
struct V_33 * V_34 ;
struct V_5 * V_6 ;
struct V_67 * V_36 ;
int V_146 ;
int V_3 ;
V_34 = F_94 ( sizeof( * V_34 ) , V_227 ) ;
if ( NULL == V_34 )
return - V_228 ;
V_34 -> V_82 = V_224 ;
if ( F_95 ( V_224 ) ) {
V_146 = - V_229 ;
goto V_230;
}
V_6 = F_96 ( V_34 -> V_82 ) ;
if ( NULL == V_6 ) {
V_146 = - V_80 ;
goto V_230;
}
V_34 -> V_6 = V_6 ;
V_34 -> V_231 = V_224 -> V_232 ;
F_97 ( V_224 , V_233 , & V_34 -> V_234 ) ;
F_83 ( V_235 L_24
L_25 , V_6 -> V_89 ,
F_58 ( V_224 ) , V_34 -> V_231 , V_224 -> V_215 ,
V_34 -> V_234 , ( unsigned long long ) F_98 ( V_224 , 0 ) ) ;
F_99 ( V_224 ) ;
V_146 = F_100 ( V_224 , F_101 ( 32 ) ) ;
if ( V_146 ) {
F_83 ( L_26 , V_6 -> V_89 ) ;
goto V_236;
}
V_34 -> V_74 = F_102 ( & V_224 -> V_34 ) ;
if ( F_103 ( V_34 -> V_74 ) ) {
V_146 = F_104 ( V_34 -> V_74 ) ;
goto V_236;
}
F_105 ( & V_34 -> V_101 ) ;
F_106 ( & V_34 -> V_94 . V_61 ) ;
F_106 ( & V_34 -> V_214 . V_61 ) ;
V_146 = F_107 ( V_224 -> V_215 , F_88 ,
V_237 , V_6 -> V_89 , V_34 ) ;
if ( V_146 < 0 ) {
F_83 ( V_238 L_27 ,
V_6 -> V_89 , V_224 -> V_215 ) ;
goto V_236;
}
F_8 ( V_54 , V_6 -> V_55 ) ;
for ( V_3 = 0 ; V_3 < V_239 ; V_3 ++ ) {
const struct V_115 * V_116 = & V_240 [ V_3 ] ;
struct V_111 * V_241 ;
V_241 = F_108 ( & V_6 -> V_131 , & V_242 ,
V_116 -> V_120 , V_116 -> V_243 , V_116 -> V_244 , V_116 -> V_245 , V_116 -> V_246 ) ;
if ( V_241 == NULL ) {
V_146 = V_6 -> V_131 . error ;
goto V_236;
}
V_241 -> V_117 = ( void * ) V_116 ;
}
for ( V_3 = 0 ; V_3 < V_247 ; V_3 ++ ) {
const struct V_115 * V_116 = & V_248 [ V_3 ] ;
struct V_111 * V_241 ;
V_241 = F_108 ( & V_6 -> V_114 , & V_249 ,
V_116 -> V_120 , V_116 -> V_243 , V_116 -> V_244 , V_116 -> V_245 , V_116 -> V_246 ) ;
if ( V_241 == NULL ) {
V_146 = V_6 -> V_114 . error ;
goto V_236;
}
V_241 -> V_117 = ( void * ) V_116 ;
if ( V_241 -> V_120 == V_128 )
V_6 -> V_250 = V_241 ;
}
F_109 ( & V_6 -> V_114 , & V_6 -> V_131 , NULL ) ;
if ( V_6 -> V_105 . V_251 == V_252 ) {
struct V_253 V_254 = {
. type = L_28 ,
. V_255 = 0x36 >> 1 ,
. V_256 = & V_6 -> V_257 ,
} ;
struct V_258 * V_259 ;
if ( V_6 -> V_260 == V_261 )
V_6 -> V_257 . V_262 = true ;
else
V_6 -> V_257 . V_262 = false ;
V_259 = F_110 ( & V_6 -> V_263 , & V_6 -> V_264 ,
& V_254 , NULL ) ;
if ( V_259 != NULL ) {
V_6 -> V_23 = V_259 ;
V_259 -> V_265 = V_266 ;
}
}
if ( V_6 -> V_105 . V_251 == V_267 ) {
F_111 ( & V_6 -> V_263 , & V_6 -> V_264 ,
L_29 , 0 , F_112 ( 0xb0 >> 1 ) ) ;
}
switch ( V_6 -> V_260 ) {
case V_268 :
case V_269 : {
static const struct V_253 V_270 = {
F_113 ( L_30 , 0x6f )
} ;
F_114 ( L_31 ) ;
V_6 -> V_271 = F_115 ( & V_6 -> V_264 , & V_270 ) ;
}
case V_272 :
F_114 ( L_32 ) ;
}
F_116 ( V_224 , V_34 ) ;
V_34 -> V_48 = F_1 ( V_273 ) ;
V_6 -> V_274 = V_34 ;
F_117 ( & V_6 -> V_275 ) ;
F_63 ( V_6 , V_6 -> V_125 ) ;
F_118 ( & V_6 -> V_114 ) ;
F_118 ( & V_6 -> V_131 ) ;
F_3 ( V_6 , 0 ) ;
V_36 = & V_34 -> V_147 ;
V_36 -> type = V_276 ;
V_36 -> V_277 = V_278 | V_279 | V_280 | V_281 ;
V_36 -> V_282 = V_283 ;
V_36 -> V_284 = 2 ;
V_36 -> V_72 = V_34 ;
V_36 -> V_285 = sizeof( struct V_37 ) ;
V_36 -> V_286 = & V_287 ;
V_36 -> V_288 = & V_289 ;
V_36 -> V_290 = V_291 ;
V_36 -> V_275 = & V_6 -> V_275 ;
V_146 = F_119 ( V_36 ) ;
if ( V_146 < 0 )
goto V_292;
V_36 = & V_34 -> V_148 ;
V_36 -> type = V_293 ;
V_36 -> V_277 = V_278 | V_279 | V_280 | V_281 ;
V_36 -> V_282 = V_283 ;
V_36 -> V_284 = 2 ;
V_36 -> V_72 = V_34 ;
V_36 -> V_285 = sizeof( struct V_37 ) ;
V_36 -> V_286 = & V_294 ;
V_36 -> V_288 = & V_289 ;
V_36 -> V_290 = V_291 ;
V_36 -> V_275 = & V_6 -> V_275 ;
V_146 = F_119 ( V_36 ) ;
if ( V_146 < 0 )
goto V_292;
F_120 ( V_6 , V_34 -> V_82 , & V_34 -> V_223 ,
& V_295 , L_33 ) ;
F_121 ( & V_34 -> V_223 , V_34 ) ;
V_34 -> V_223 . V_296 = & V_6 -> V_114 ;
V_34 -> V_223 . V_297 = & V_34 -> V_147 ;
V_146 = F_122 ( & V_34 -> V_223 , V_165 ,
V_298 [ V_6 -> V_299 ] ) ;
if ( V_146 < 0 ) {
F_83 ( V_238 L_34 ,
V_6 -> V_89 ) ;
goto V_292;
}
F_83 ( V_235 L_35 ,
V_6 -> V_89 , F_123 ( & V_34 -> V_223 ) ) ;
F_120 ( V_6 , V_34 -> V_82 , & V_34 -> V_222 ,
& V_300 , L_36 ) ;
F_121 ( & V_34 -> V_222 , V_34 ) ;
V_34 -> V_222 . V_297 = & V_34 -> V_148 ;
V_146 = F_122 ( & V_34 -> V_222 , V_167 ,
V_301 [ V_6 -> V_299 ] ) ;
if ( V_146 < 0 ) {
F_83 ( V_238 L_37 ,
V_6 -> V_89 ) ;
goto V_292;
}
F_83 ( V_235 L_38 ,
V_6 -> V_89 , F_123 ( & V_34 -> V_222 ) ) ;
if ( V_6 -> V_105 . V_106 . type == V_171 ) {
F_120 ( V_6 , V_34 -> V_82 , & V_34 -> V_221 ,
& V_302 , L_39 ) ;
F_121 ( & V_34 -> V_221 , V_34 ) ;
V_34 -> V_221 . V_296 = & V_6 -> V_131 ;
V_146 = F_122 ( & V_34 -> V_221 , V_163 ,
V_303 [ V_6 -> V_299 ] ) ;
if ( V_146 < 0 ) {
F_83 ( V_238 L_40 ,
V_6 -> V_89 ) ;
goto V_292;
}
F_83 ( V_235 L_38 ,
V_6 -> V_89 , F_123 ( & V_34 -> V_221 ) ) ;
}
if ( V_6 -> V_105 . V_160 != V_84 ) {
V_6 -> V_304 = F_124 ( V_305 , V_6 , L_41 ) ;
if ( F_103 ( V_6 -> V_304 ) ) {
V_146 = F_104 ( V_6 -> V_304 ) ;
F_83 ( V_238 L_42 ,
V_6 -> V_89 , V_146 ) ;
}
}
F_125 ( & V_6 -> V_275 ) ;
return 0 ;
V_292:
F_91 ( V_34 ) ;
F_126 ( V_224 -> V_215 , V_34 ) ;
F_125 ( & V_6 -> V_275 ) ;
V_236:
F_127 ( V_34 -> V_74 ) ;
V_6 -> V_274 = NULL ;
F_128 ( V_6 , V_34 -> V_82 ) ;
V_230:
F_129 ( V_34 ) ;
return V_146 ;
}
static void F_130 ( struct V_224 * V_224 )
{
struct V_33 * V_34 = F_131 ( V_224 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( V_6 -> V_304 ) {
F_132 ( V_6 -> V_304 ) ;
V_6 -> V_304 = NULL ;
}
if ( V_6 -> V_306 )
F_133 ( V_6 ) ;
F_134 ( V_6 ) ;
F_126 ( V_224 -> V_215 , V_34 ) ;
F_91 ( V_34 ) ;
F_135 ( V_224 ) ;
V_6 -> V_274 = NULL ;
F_128 ( V_6 , V_34 -> V_82 ) ;
F_127 ( V_34 -> V_74 ) ;
F_129 ( V_34 ) ;
}
static int F_136 ( struct V_224 * V_224 , T_4 V_307 )
{
struct V_33 * V_34 = F_131 ( V_224 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
unsigned long V_100 ;
F_34 ( & V_34 -> V_101 , V_100 ) ;
if ( ! F_17 ( & V_34 -> V_94 . V_61 ) ) {
F_83 ( L_43 , V_6 -> V_89 ) ;
F_15 ( V_34 ) ;
}
if ( ! F_17 ( & V_34 -> V_214 . V_61 ) ) {
F_83 ( L_44 , V_6 -> V_89 ) ;
F_137 ( V_34 ) ;
}
F_37 ( & V_34 -> V_101 , V_100 ) ;
if ( V_6 -> V_306 )
F_133 ( V_6 ) ;
F_134 ( V_6 ) ;
F_138 ( V_224 ) ;
if ( 0 != F_139 ( V_224 , F_140 ( V_224 , V_307 ) ) ) {
F_135 ( V_224 ) ;
V_34 -> V_307 . V_308 = 1 ;
}
return 0 ;
}
static int F_141 ( struct V_224 * V_224 )
{
struct V_33 * V_34 = F_131 ( V_224 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
unsigned long V_100 ;
int V_146 ;
if ( V_34 -> V_307 . V_308 ) {
V_146 = F_95 ( V_224 ) ;
if ( V_146 ) {
F_83 ( V_238 L_45 ,
V_6 -> V_89 ) ;
return V_146 ;
}
V_34 -> V_307 . V_308 = 0 ;
}
V_146 = F_139 ( V_224 , V_309 ) ;
if ( V_146 ) {
F_83 ( V_238 L_46 , V_6 -> V_89 ) ;
F_135 ( V_224 ) ;
V_34 -> V_307 . V_308 = 1 ;
return V_146 ;
}
F_142 ( V_224 ) ;
F_143 ( V_6 ) ;
if ( V_6 -> V_306 )
F_144 ( V_6 ) ;
F_8 ( V_54 , V_6 -> V_55 ) ;
F_34 ( & V_34 -> V_101 , V_100 ) ;
if ( ! F_17 ( & V_34 -> V_94 . V_61 ) ) {
F_83 ( L_47 , V_6 -> V_89 ) ;
F_16 ( V_34 , & V_34 -> V_94 ) ;
}
if ( ! F_17 ( & V_34 -> V_214 . V_61 ) ) {
F_83 ( L_48 , V_6 -> V_89 ) ;
F_145 ( V_34 , & V_34 -> V_214 ) ;
}
F_37 ( & V_34 -> V_101 , V_100 ) ;
return 0 ;
}
