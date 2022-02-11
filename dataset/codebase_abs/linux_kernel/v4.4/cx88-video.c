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
static int F_19 ( struct V_67 * V_36 , const void * V_68 ,
unsigned int * V_69 , unsigned int * V_70 ,
unsigned int V_71 [] , void * V_72 [] )
{
struct V_33 * V_34 = V_36 -> V_73 ;
struct V_5 * V_6 = V_34 -> V_6 ;
* V_70 = 1 ;
V_71 [ 0 ] = ( V_34 -> V_48 -> V_74 * V_6 -> V_44 * V_6 -> V_45 ) >> 3 ;
V_72 [ 0 ] = V_34 -> V_75 ;
return 0 ;
}
static int F_20 ( struct V_76 * V_64 )
{
struct V_77 * V_78 = F_21 ( V_64 ) ;
struct V_33 * V_34 = V_64 -> V_67 -> V_73 ;
struct V_5 * V_6 = V_34 -> V_6 ;
struct V_37 * V_38 = F_22 ( V_78 , struct V_37 , V_64 ) ;
struct V_79 * V_80 = F_23 ( V_64 , 0 ) ;
V_38 -> V_41 = V_6 -> V_44 * V_34 -> V_48 -> V_74 >> 3 ;
if ( F_24 ( V_64 , 0 ) < V_6 -> V_45 * V_38 -> V_41 )
return - V_81 ;
F_25 ( V_64 , 0 , V_6 -> V_45 * V_38 -> V_41 ) ;
switch ( V_6 -> V_46 ) {
case V_82 :
F_26 ( V_34 -> V_83 , & V_38 -> V_42 ,
V_80 -> V_84 , 0 , V_85 ,
V_38 -> V_41 , 0 , V_6 -> V_45 ) ;
break;
case V_86 :
F_26 ( V_34 -> V_83 , & V_38 -> V_42 ,
V_80 -> V_84 , V_85 , 0 ,
V_38 -> V_41 , 0 , V_6 -> V_45 ) ;
break;
case V_87 :
F_26 ( V_34 -> V_83 , & V_38 -> V_42 ,
V_80 -> V_84 ,
0 , V_38 -> V_41 * ( V_6 -> V_45 >> 1 ) ,
V_38 -> V_41 , 0 ,
V_6 -> V_45 >> 1 ) ;
break;
case V_88 :
F_26 ( V_34 -> V_83 , & V_38 -> V_42 ,
V_80 -> V_84 ,
V_38 -> V_41 * ( V_6 -> V_45 >> 1 ) , 0 ,
V_38 -> V_41 , 0 ,
V_6 -> V_45 >> 1 ) ;
break;
case V_89 :
default:
F_26 ( V_34 -> V_83 , & V_38 -> V_42 ,
V_80 -> V_84 , 0 , V_38 -> V_41 ,
V_38 -> V_41 , V_38 -> V_41 ,
V_6 -> V_45 >> 1 ) ;
break;
}
F_4 ( 2 , L_3 ,
V_38 , V_38 -> V_64 . V_65 . V_66 ,
V_6 -> V_44 , V_6 -> V_45 , V_34 -> V_48 -> V_74 , V_34 -> V_48 -> V_90 ,
( unsigned long ) V_38 -> V_42 . V_43 ) ;
return 0 ;
}
static void F_27 ( struct V_76 * V_64 )
{
struct V_77 * V_78 = F_21 ( V_64 ) ;
struct V_33 * V_34 = V_64 -> V_67 -> V_73 ;
struct V_37 * V_38 = F_22 ( V_78 , struct V_37 , V_64 ) ;
struct V_91 * V_42 = & V_38 -> V_42 ;
if ( V_42 -> V_92 )
F_28 ( V_34 -> V_83 , V_42 -> V_93 , V_42 -> V_92 , V_42 -> V_43 ) ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
}
static void F_29 ( struct V_76 * V_64 )
{
struct V_77 * V_78 = F_21 ( V_64 ) ;
struct V_33 * V_34 = V_64 -> V_67 -> V_73 ;
struct V_37 * V_38 = F_22 ( V_78 , struct V_37 , V_64 ) ;
struct V_37 * V_94 ;
struct V_5 * V_6 = V_34 -> V_6 ;
struct V_35 * V_36 = & V_34 -> V_95 ;
V_38 -> V_42 . V_92 [ 1 ] = F_30 ( V_38 -> V_42 . V_43 + 8 ) ;
V_38 -> V_42 . V_96 [ 0 ] = F_30 ( V_97 | V_98 ) ;
V_38 -> V_42 . V_96 [ 1 ] = F_30 ( V_38 -> V_42 . V_43 + 8 ) ;
if ( F_17 ( & V_36 -> V_61 ) ) {
F_31 ( & V_38 -> V_63 , & V_36 -> V_61 ) ;
F_4 ( 2 , L_4 ,
V_38 , V_38 -> V_64 . V_65 . V_66 ) ;
} else {
V_38 -> V_42 . V_92 [ 0 ] |= F_30 ( V_99 ) ;
V_94 = F_18 ( V_36 -> V_61 . V_94 , struct V_37 , V_63 ) ;
F_31 ( & V_38 -> V_63 , & V_36 -> V_61 ) ;
V_94 -> V_42 . V_96 [ 1 ] = F_30 ( V_38 -> V_42 . V_43 ) ;
F_4 ( 2 , L_5 ,
V_38 , V_38 -> V_64 . V_65 . V_66 ) ;
}
}
static int F_32 ( struct V_67 * V_36 , unsigned int V_53 )
{
struct V_33 * V_34 = V_36 -> V_73 ;
struct V_35 * V_100 = & V_34 -> V_95 ;
struct V_37 * V_38 = F_18 ( V_100 -> V_61 . V_62 ,
struct V_37 , V_63 ) ;
F_12 ( V_34 , V_100 , V_38 ) ;
return 0 ;
}
static void F_33 ( struct V_67 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_73 ;
struct V_5 * V_6 = V_34 -> V_6 ;
struct V_35 * V_100 = & V_34 -> V_95 ;
unsigned long V_101 ;
F_9 ( V_60 , 0x11 ) ;
F_9 ( V_58 , 0x06 ) ;
F_34 ( & V_34 -> V_102 , V_101 ) ;
while ( ! F_17 ( & V_100 -> V_61 ) ) {
struct V_37 * V_38 = F_18 ( V_100 -> V_61 . V_62 ,
struct V_37 , V_63 ) ;
F_35 ( & V_38 -> V_63 ) ;
F_36 ( & V_38 -> V_64 . V_65 , V_103 ) ;
}
F_37 ( & V_34 -> V_102 , V_101 ) ;
}
static int F_38 ( struct V_104 * V_104 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
int V_105 = F_40 ( V_104 ) ;
if ( V_105 )
return V_105 ;
F_7 ( V_14 , V_6 -> V_106 . V_107 . V_12 ) ;
F_7 ( V_15 , V_6 -> V_106 . V_107 . V_9 ) ;
F_7 ( V_16 , V_6 -> V_106 . V_107 . V_10 ) ;
F_7 ( V_17 , V_6 -> V_106 . V_107 . V_11 ) ;
if ( V_6 -> V_106 . V_107 . V_22 ) {
if ( V_6 -> V_23 ) {
F_10 ( V_6 , V_24 , V_25 ,
V_6 -> V_106 . V_107 . V_22 , 0 , 0 ) ;
}
V_6 -> V_28 = V_29 ;
F_11 ( V_6 ) ;
} else {
V_6 -> V_28 = V_108 ;
F_11 ( V_6 ) ;
F_41 ( V_6 , V_109 , 1 ) ;
}
F_10 ( V_6 , V_110 , V_111 ) ;
return 0 ;
}
static int F_42 ( struct V_112 * V_113 )
{
struct V_5 * V_6 =
F_22 ( V_113 -> V_114 , struct V_5 , V_115 ) ;
const struct V_116 * V_117 = V_113 -> V_118 ;
T_1 V_119 , V_120 ;
V_120 = V_117 -> V_120 ;
switch ( V_113 -> V_121 ) {
case V_122 :
V_119 = ( ( V_113 -> V_123 - V_117 -> V_124 ) << V_117 -> V_125 ) & V_117 -> V_120 ;
if ( V_6 -> V_126 & V_127 ) {
V_119 = V_119 << 8 | V_119 ;
} else {
V_119 = ( V_119 * 0x5a ) / 0x7f << 8 | V_119 ;
}
V_120 = 0xffff ;
break;
case V_128 :
V_119 = ( V_113 -> V_123 < 1 ? 0 : ( ( V_113 -> V_123 + 3 ) << 7 ) ) ;
F_6 ( V_20 , V_120 , V_119 ) ;
break;
case V_129 :
V_119 = ( ( V_113 -> V_123 - V_117 -> V_124 ) << V_117 -> V_125 ) & V_117 -> V_120 ;
break;
default:
V_119 = ( ( V_113 -> V_123 - V_117 -> V_124 ) << V_117 -> V_125 ) & V_117 -> V_120 ;
break;
}
F_4 ( 1 , L_6 ,
V_113 -> V_121 , V_113 -> V_90 , V_113 -> V_123 , V_117 -> V_130 , V_119 ,
V_120 , V_117 -> V_131 ? L_7 : L_8 ) ;
if ( V_117 -> V_131 )
F_43 ( V_117 -> V_131 , V_117 -> V_130 , V_120 , V_119 ) ;
else
F_6 ( V_117 -> V_130 , V_120 , V_119 ) ;
return 0 ;
}
static int F_44 ( struct V_112 * V_113 )
{
struct V_5 * V_6 =
F_22 ( V_113 -> V_114 , struct V_5 , V_132 ) ;
const struct V_116 * V_117 = V_113 -> V_118 ;
T_1 V_119 , V_120 ;
if ( V_6 -> V_23 ) {
switch ( V_113 -> V_121 ) {
case V_133 :
F_45 ( V_6 , V_113 -> V_121 , V_113 -> V_123 ) ;
break;
case V_134 :
F_45 ( V_6 , V_113 -> V_121 , ( V_113 -> V_123 ) ?
( 0x90 + V_113 -> V_123 ) << 8 : 0 ) ;
break;
case V_135 :
F_45 ( V_6 , V_113 -> V_121 , V_113 -> V_123 << 9 ) ;
break;
default:
break;
}
}
V_120 = V_117 -> V_120 ;
switch ( V_113 -> V_121 ) {
case V_135 :
V_119 = ( V_113 -> V_123 < 0x40 ) ? ( 0x7f - V_113 -> V_123 ) : ( V_113 -> V_123 - 0x40 ) ;
break;
case V_134 :
V_119 = 0x3f - ( V_113 -> V_123 & 0x3f ) ;
break;
default:
V_119 = ( ( V_113 -> V_123 - V_117 -> V_124 ) << V_117 -> V_125 ) & V_117 -> V_120 ;
break;
}
F_4 ( 1 , L_6 ,
V_113 -> V_121 , V_113 -> V_90 , V_113 -> V_123 , V_117 -> V_130 , V_119 ,
V_120 , V_117 -> V_131 ? L_7 : L_8 ) ;
if ( V_117 -> V_131 )
F_43 ( V_117 -> V_131 , V_117 -> V_130 , V_120 , V_119 ) ;
else
F_6 ( V_117 -> V_130 , V_120 , V_119 ) ;
return 0 ;
}
static int F_46 ( struct V_104 * V_104 , void * V_118 ,
struct V_136 * V_137 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
V_137 -> V_48 . V_138 . V_44 = V_6 -> V_44 ;
V_137 -> V_48 . V_138 . V_45 = V_6 -> V_45 ;
V_137 -> V_48 . V_138 . V_46 = V_6 -> V_46 ;
V_137 -> V_48 . V_138 . V_139 = V_34 -> V_48 -> V_2 ;
V_137 -> V_48 . V_138 . V_140 =
( V_137 -> V_48 . V_138 . V_44 * V_34 -> V_48 -> V_74 ) >> 3 ;
V_137 -> V_48 . V_138 . V_141 =
V_137 -> V_48 . V_138 . V_45 * V_137 -> V_48 . V_138 . V_140 ;
V_137 -> V_48 . V_138 . V_142 = V_143 ;
return 0 ;
}
static int F_47 ( struct V_104 * V_104 , void * V_118 ,
struct V_136 * V_137 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
const struct V_1 * V_48 ;
enum V_144 V_46 ;
unsigned int V_145 , V_146 ;
V_48 = F_1 ( V_137 -> V_48 . V_138 . V_139 ) ;
if ( NULL == V_48 )
return - V_81 ;
V_145 = F_48 ( V_6 -> V_126 ) ;
V_146 = F_49 ( V_6 -> V_126 ) ;
V_46 = V_137 -> V_48 . V_138 . V_46 ;
switch ( V_46 ) {
case V_82 :
case V_86 :
case V_89 :
case V_88 :
case V_87 :
break;
default:
V_46 = ( V_137 -> V_48 . V_138 . V_45 > V_146 / 2 )
? V_89
: V_86 ;
break;
}
if ( F_50 ( V_46 ) )
V_146 /= 2 ;
F_51 ( & V_137 -> V_48 . V_138 . V_44 , 48 , V_145 , 2 ,
& V_137 -> V_48 . V_138 . V_45 , 32 , V_146 , 0 , 0 ) ;
V_137 -> V_48 . V_138 . V_46 = V_46 ;
V_137 -> V_48 . V_138 . V_140 =
( V_137 -> V_48 . V_138 . V_44 * V_48 -> V_74 ) >> 3 ;
V_137 -> V_48 . V_138 . V_141 =
V_137 -> V_48 . V_138 . V_45 * V_137 -> V_48 . V_138 . V_140 ;
V_137 -> V_48 . V_138 . V_142 = V_143 ;
return 0 ;
}
static int F_52 ( struct V_104 * V_104 , void * V_118 ,
struct V_136 * V_137 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
int V_147 = F_47 ( V_104 , V_118 , V_137 ) ;
if ( 0 != V_147 )
return V_147 ;
if ( F_53 ( & V_34 -> V_148 ) || F_53 ( & V_34 -> V_149 ) )
return - V_150 ;
if ( V_6 -> V_151 && F_53 ( & V_6 -> V_151 -> V_152 ) )
return - V_150 ;
V_34 -> V_48 = F_1 ( V_137 -> V_48 . V_138 . V_139 ) ;
V_6 -> V_44 = V_137 -> V_48 . V_138 . V_44 ;
V_6 -> V_45 = V_137 -> V_48 . V_138 . V_45 ;
V_6 -> V_46 = V_137 -> V_48 . V_138 . V_46 ;
return 0 ;
}
void F_54 ( struct V_104 * V_104 , struct V_5 * V_6 ,
struct V_153 * V_154 )
{
struct V_155 * V_156 = F_55 ( V_104 ) ;
F_56 ( V_154 -> V_157 , V_6 -> V_106 . V_90 , sizeof( V_154 -> V_157 ) ) ;
V_154 -> V_158 = V_159 | V_160 ;
if ( V_85 != V_6 -> V_106 . V_161 )
V_154 -> V_158 |= V_162 ;
switch ( V_156 -> V_163 ) {
case V_164 :
V_154 -> V_158 = V_165 | V_162 ;
break;
case V_166 :
V_154 -> V_158 |= V_167 ;
break;
case V_168 :
V_154 -> V_158 |= V_169 ;
break;
}
V_154 -> V_170 = V_154 -> V_158 | V_167 |
V_169 | V_171 ;
if ( V_6 -> V_106 . V_107 . type == V_172 )
V_154 -> V_170 |= V_165 ;
}
static int F_57 ( struct V_104 * V_104 , void * V_118 ,
struct V_153 * V_154 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
strcpy ( V_154 -> V_173 , L_9 ) ;
sprintf ( V_154 -> V_174 , L_10 , F_58 ( V_34 -> V_83 ) ) ;
F_54 ( V_104 , V_6 , V_154 ) ;
return 0 ;
}
static int F_59 ( struct V_104 * V_104 , void * V_118 ,
struct V_175 * V_137 )
{
if ( F_60 ( V_137 -> V_66 >= F_2 ( V_4 ) ) )
return - V_81 ;
F_56 ( V_137 -> V_176 , V_4 [ V_137 -> V_66 ] . V_90 , sizeof( V_137 -> V_176 ) ) ;
V_137 -> V_139 = V_4 [ V_137 -> V_66 ] . V_2 ;
return 0 ;
}
static int F_61 ( struct V_104 * V_104 , void * V_118 , T_2 * V_126 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
* V_126 = V_6 -> V_126 ;
return 0 ;
}
static int F_62 ( struct V_104 * V_104 , void * V_118 , T_2 V_177 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
return F_63 ( V_6 , V_177 ) ;
}
int F_64 ( struct V_5 * V_6 , struct V_178 * V_3 )
{
static const char * const V_179 [] = {
[ V_180 ] = L_11 ,
[ V_181 ] = L_12 ,
[ V_182 ] = L_13 ,
[ V_183 ] = L_14 ,
[ V_18 ] = L_15 ,
[ V_26 ] = L_16 ,
[ V_27 ] = L_17 ,
[ V_184 ] = L_18 ,
[ V_185 ] = L_19 ,
} ;
unsigned int V_186 = V_3 -> V_66 ;
if ( V_186 >= 4 )
return - V_81 ;
if ( 0 == F_5 ( V_186 ) . type )
return - V_81 ;
V_3 -> type = V_187 ;
strcpy ( V_3 -> V_90 , V_179 [ F_5 ( V_186 ) . type ] ) ;
if ( ( V_26 == F_5 ( V_186 ) . type ) ||
( V_27 == F_5 ( V_186 ) . type ) ) {
V_3 -> type = V_188 ;
}
V_3 -> V_189 = V_190 ;
return 0 ;
}
static int F_65 ( struct V_104 * V_104 , void * V_118 ,
struct V_178 * V_3 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
return F_64 ( V_6 , V_3 ) ;
}
static int F_66 ( struct V_104 * V_104 , void * V_118 , unsigned int * V_3 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
* V_3 = V_6 -> V_7 ;
return 0 ;
}
static int F_67 ( struct V_104 * V_104 , void * V_118 , unsigned int V_3 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( V_3 >= 4 )
return - V_81 ;
if ( 0 == F_5 ( V_3 ) . type )
return - V_81 ;
F_68 ( V_6 ) ;
F_3 ( V_6 , V_3 ) ;
return 0 ;
}
static int F_69 ( struct V_104 * V_104 , void * V_118 ,
struct V_191 * V_192 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
T_1 V_130 ;
if ( F_60 ( V_85 == V_6 -> V_106 . V_161 ) )
return - V_81 ;
if ( 0 != V_192 -> V_66 )
return - V_81 ;
strcpy ( V_192 -> V_90 , L_16 ) ;
V_192 -> V_193 = V_194 ;
V_192 -> V_195 = 0xffffffffUL ;
F_10 ( V_6 , V_110 , V_196 , V_192 ) ;
F_70 ( V_6 , V_192 ) ;
V_130 = F_71 ( V_197 ) ;
V_192 -> signal = ( V_130 & ( 1 << 5 ) ) ? 0xffff : 0x0000 ;
return 0 ;
}
static int F_72 ( struct V_104 * V_104 , void * V_118 ,
const struct V_191 * V_192 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( V_85 == V_6 -> V_106 . V_161 )
return - V_81 ;
if ( 0 != V_192 -> V_66 )
return - V_81 ;
F_41 ( V_6 , V_192 -> V_198 , 1 ) ;
return 0 ;
}
static int F_73 ( struct V_104 * V_104 , void * V_118 ,
struct V_199 * V_137 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( F_60 ( V_85 == V_6 -> V_106 . V_161 ) )
return - V_81 ;
if ( V_137 -> V_110 )
return - V_81 ;
V_137 -> V_200 = V_6 -> V_201 ;
F_10 ( V_6 , V_110 , V_202 , V_137 ) ;
return 0 ;
}
int F_74 ( struct V_5 * V_6 ,
const struct V_199 * V_137 )
{
struct V_199 V_203 = * V_137 ;
if ( F_60 ( V_85 == V_6 -> V_106 . V_161 ) )
return - V_81 ;
if ( F_60 ( V_137 -> V_110 != 0 ) )
return - V_81 ;
F_68 ( V_6 ) ;
F_10 ( V_6 , V_110 , V_204 , V_137 ) ;
F_10 ( V_6 , V_110 , V_202 , & V_203 ) ;
V_6 -> V_201 = V_203 . V_200 ;
F_75 ( 10 ) ;
F_11 ( V_6 ) ;
return 0 ;
}
static int F_76 ( struct V_104 * V_104 , void * V_118 ,
const struct V_199 * V_137 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
return F_74 ( V_6 , V_137 ) ;
}
static int F_77 ( struct V_104 * V_104 , void * V_205 ,
struct V_206 * V_130 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
V_130 -> V_123 = F_71 ( V_130 -> V_130 & 0xfffffc ) ;
V_130 -> V_93 = 4 ;
return 0 ;
}
static int F_78 ( struct V_104 * V_104 , void * V_205 ,
const struct V_206 * V_130 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
F_7 ( V_130 -> V_130 & 0xfffffc , V_130 -> V_123 ) ;
return 0 ;
}
static int F_79 ( struct V_104 * V_104 , void * V_118 ,
struct V_191 * V_192 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( F_60 ( V_192 -> V_66 > 0 ) )
return - V_81 ;
strcpy ( V_192 -> V_90 , L_20 ) ;
F_10 ( V_6 , V_110 , V_196 , V_192 ) ;
return 0 ;
}
static int F_80 ( struct V_104 * V_104 , void * V_118 ,
const struct V_191 * V_192 )
{
struct V_33 * V_34 = F_39 ( V_104 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( 0 != V_192 -> V_66 )
return - V_81 ;
F_10 ( V_6 , V_110 , V_207 , V_192 ) ;
return 0 ;
}
static void F_81 ( struct V_33 * V_34 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
T_1 V_208 , V_120 , V_53 ;
V_208 = F_71 ( V_209 ) ;
V_120 = F_71 ( V_57 ) ;
if ( 0 == ( V_208 & V_120 ) )
return;
F_7 ( V_209 , V_208 ) ;
if ( V_210 || ( V_208 & V_120 & ~ 0xff ) )
F_82 ( V_6 -> V_90 , L_21 ,
V_211 , F_2 ( V_211 ) ,
V_208 , V_120 ) ;
if ( V_208 & ( 1 << 16 ) ) {
F_83 ( V_212 L_22 , V_6 -> V_90 ) ;
F_9 ( V_60 , 0x11 ) ;
F_9 ( V_58 , 0x06 ) ;
F_84 ( V_6 , & V_39 [ V_40 ] ) ;
}
if ( V_208 & 0x01 ) {
F_85 ( & V_34 -> V_102 ) ;
V_53 = F_71 ( V_213 ) ;
F_86 ( V_6 , & V_34 -> V_95 , V_53 ) ;
F_87 ( & V_34 -> V_102 ) ;
}
if ( V_208 & 0x08 ) {
F_85 ( & V_34 -> V_102 ) ;
V_53 = F_71 ( V_214 ) ;
F_86 ( V_6 , & V_34 -> V_215 , V_53 ) ;
F_87 ( & V_34 -> V_102 ) ;
}
}
static T_3 F_88 ( int V_216 , void * V_217 )
{
struct V_33 * V_34 = V_217 ;
struct V_5 * V_6 = V_34 -> V_6 ;
T_1 V_208 ;
int V_218 , V_219 = 0 ;
for ( V_218 = 0 ; V_218 < 10 ; V_218 ++ ) {
V_208 = F_71 ( V_220 ) &
( V_6 -> V_55 | V_56 ) ;
if ( 0 == V_208 )
goto V_221;
F_7 ( V_220 , V_208 ) ;
V_219 = 1 ;
if ( V_208 & V_6 -> V_55 )
F_89 ( V_6 , V_208 ) ;
if ( V_208 & V_56 )
F_81 ( V_34 ) ;
}
if ( 10 == V_218 ) {
F_83 ( V_212 L_23 ,
V_6 -> V_90 ) ;
F_7 ( V_54 , 0 ) ;
}
V_221:
return F_90 ( V_219 ) ;
}
static void F_91 ( struct V_33 * V_34 )
{
F_92 ( & V_34 -> V_222 ) ;
F_92 ( & V_34 -> V_223 ) ;
F_92 ( & V_34 -> V_224 ) ;
}
static int F_93 ( struct V_225 * V_225 ,
const struct V_226 * V_227 )
{
struct V_33 * V_34 ;
struct V_5 * V_6 ;
struct V_67 * V_36 ;
int V_147 ;
int V_3 ;
V_34 = F_94 ( sizeof( * V_34 ) , V_228 ) ;
if ( NULL == V_34 )
return - V_229 ;
V_34 -> V_83 = V_225 ;
if ( F_95 ( V_225 ) ) {
V_147 = - V_230 ;
goto V_231;
}
V_6 = F_96 ( V_34 -> V_83 ) ;
if ( NULL == V_6 ) {
V_147 = - V_81 ;
goto V_231;
}
V_34 -> V_6 = V_6 ;
V_34 -> V_232 = V_225 -> V_233 ;
F_97 ( V_225 , V_234 , & V_34 -> V_235 ) ;
F_83 ( V_236 L_24
L_25 , V_6 -> V_90 ,
F_58 ( V_225 ) , V_34 -> V_232 , V_225 -> V_216 ,
V_34 -> V_235 , ( unsigned long long ) F_98 ( V_225 , 0 ) ) ;
F_99 ( V_225 ) ;
V_147 = F_100 ( V_225 , F_101 ( 32 ) ) ;
if ( V_147 ) {
F_83 ( L_26 , V_6 -> V_90 ) ;
goto V_237;
}
V_34 -> V_75 = F_102 ( & V_225 -> V_34 ) ;
if ( F_103 ( V_34 -> V_75 ) ) {
V_147 = F_104 ( V_34 -> V_75 ) ;
goto V_237;
}
F_105 ( & V_34 -> V_102 ) ;
F_106 ( & V_34 -> V_95 . V_61 ) ;
F_106 ( & V_34 -> V_215 . V_61 ) ;
V_147 = F_107 ( V_225 -> V_216 , F_88 ,
V_238 , V_6 -> V_90 , V_34 ) ;
if ( V_147 < 0 ) {
F_83 ( V_239 L_27 ,
V_6 -> V_90 , V_225 -> V_216 ) ;
goto V_237;
}
F_8 ( V_54 , V_6 -> V_55 ) ;
for ( V_3 = 0 ; V_3 < V_240 ; V_3 ++ ) {
const struct V_116 * V_117 = & V_241 [ V_3 ] ;
struct V_112 * V_242 ;
V_242 = F_108 ( & V_6 -> V_132 , & V_243 ,
V_117 -> V_121 , V_117 -> V_244 , V_117 -> V_245 , V_117 -> V_246 , V_117 -> V_247 ) ;
if ( V_242 == NULL ) {
V_147 = V_6 -> V_132 . error ;
goto V_237;
}
V_242 -> V_118 = ( void * ) V_117 ;
}
for ( V_3 = 0 ; V_3 < V_248 ; V_3 ++ ) {
const struct V_116 * V_117 = & V_249 [ V_3 ] ;
struct V_112 * V_242 ;
V_242 = F_108 ( & V_6 -> V_115 , & V_250 ,
V_117 -> V_121 , V_117 -> V_244 , V_117 -> V_245 , V_117 -> V_246 , V_117 -> V_247 ) ;
if ( V_242 == NULL ) {
V_147 = V_6 -> V_115 . error ;
goto V_237;
}
V_242 -> V_118 = ( void * ) V_117 ;
if ( V_242 -> V_121 == V_129 )
V_6 -> V_251 = V_242 ;
}
F_109 ( & V_6 -> V_115 , & V_6 -> V_132 , NULL ) ;
if ( V_6 -> V_106 . V_252 == V_253 ) {
struct V_254 V_255 = {
. type = L_28 ,
. V_256 = 0x36 >> 1 ,
. V_257 = & V_6 -> V_258 ,
} ;
struct V_259 * V_260 ;
if ( V_6 -> V_261 == V_262 )
V_6 -> V_258 . V_263 = true ;
else
V_6 -> V_258 . V_263 = false ;
V_260 = F_110 ( & V_6 -> V_264 , & V_6 -> V_265 ,
& V_255 , NULL ) ;
if ( V_260 != NULL ) {
V_6 -> V_23 = V_260 ;
V_260 -> V_266 = V_267 ;
}
}
if ( V_6 -> V_106 . V_252 == V_268 ) {
F_111 ( & V_6 -> V_264 , & V_6 -> V_265 ,
L_29 , 0 , F_112 ( 0xb0 >> 1 ) ) ;
}
switch ( V_6 -> V_261 ) {
case V_269 :
case V_270 : {
static const struct V_254 V_271 = {
F_113 ( L_30 , 0x6f )
} ;
F_114 ( L_31 ) ;
V_6 -> V_272 = F_115 ( & V_6 -> V_265 , & V_271 ) ;
}
case V_273 :
F_114 ( L_32 ) ;
}
F_116 ( V_225 , V_34 ) ;
V_34 -> V_48 = F_1 ( V_274 ) ;
V_6 -> V_275 = V_34 ;
F_117 ( & V_6 -> V_276 ) ;
F_63 ( V_6 , V_6 -> V_126 ) ;
F_118 ( & V_6 -> V_115 ) ;
F_118 ( & V_6 -> V_132 ) ;
F_3 ( V_6 , 0 ) ;
V_36 = & V_34 -> V_148 ;
V_36 -> type = V_277 ;
V_36 -> V_278 = V_279 | V_280 | V_281 | V_282 ;
V_36 -> V_283 = V_284 ;
V_36 -> V_285 = 2 ;
V_36 -> V_73 = V_34 ;
V_36 -> V_286 = sizeof( struct V_37 ) ;
V_36 -> V_287 = & V_288 ;
V_36 -> V_289 = & V_290 ;
V_36 -> V_291 = V_292 ;
V_36 -> V_276 = & V_6 -> V_276 ;
V_147 = F_119 ( V_36 ) ;
if ( V_147 < 0 )
goto V_293;
V_36 = & V_34 -> V_149 ;
V_36 -> type = V_294 ;
V_36 -> V_278 = V_279 | V_280 | V_281 | V_282 ;
V_36 -> V_283 = V_284 ;
V_36 -> V_285 = 2 ;
V_36 -> V_73 = V_34 ;
V_36 -> V_286 = sizeof( struct V_37 ) ;
V_36 -> V_287 = & V_295 ;
V_36 -> V_289 = & V_290 ;
V_36 -> V_291 = V_292 ;
V_36 -> V_276 = & V_6 -> V_276 ;
V_147 = F_119 ( V_36 ) ;
if ( V_147 < 0 )
goto V_293;
F_120 ( V_6 , V_34 -> V_83 , & V_34 -> V_224 ,
& V_296 , L_33 ) ;
F_121 ( & V_34 -> V_224 , V_34 ) ;
V_34 -> V_224 . V_297 = & V_6 -> V_115 ;
V_34 -> V_224 . V_298 = & V_34 -> V_148 ;
V_147 = F_122 ( & V_34 -> V_224 , V_166 ,
V_299 [ V_6 -> V_300 ] ) ;
if ( V_147 < 0 ) {
F_83 ( V_239 L_34 ,
V_6 -> V_90 ) ;
goto V_293;
}
F_83 ( V_236 L_35 ,
V_6 -> V_90 , F_123 ( & V_34 -> V_224 ) ) ;
F_120 ( V_6 , V_34 -> V_83 , & V_34 -> V_223 ,
& V_301 , L_36 ) ;
F_121 ( & V_34 -> V_223 , V_34 ) ;
V_34 -> V_223 . V_298 = & V_34 -> V_149 ;
V_147 = F_122 ( & V_34 -> V_223 , V_168 ,
V_302 [ V_6 -> V_300 ] ) ;
if ( V_147 < 0 ) {
F_83 ( V_239 L_37 ,
V_6 -> V_90 ) ;
goto V_293;
}
F_83 ( V_236 L_38 ,
V_6 -> V_90 , F_123 ( & V_34 -> V_223 ) ) ;
if ( V_6 -> V_106 . V_107 . type == V_172 ) {
F_120 ( V_6 , V_34 -> V_83 , & V_34 -> V_222 ,
& V_303 , L_39 ) ;
F_121 ( & V_34 -> V_222 , V_34 ) ;
V_34 -> V_222 . V_297 = & V_6 -> V_132 ;
V_147 = F_122 ( & V_34 -> V_222 , V_164 ,
V_304 [ V_6 -> V_300 ] ) ;
if ( V_147 < 0 ) {
F_83 ( V_239 L_40 ,
V_6 -> V_90 ) ;
goto V_293;
}
F_83 ( V_236 L_38 ,
V_6 -> V_90 , F_123 ( & V_34 -> V_222 ) ) ;
}
if ( V_6 -> V_106 . V_161 != V_85 ) {
V_6 -> V_305 = F_124 ( V_306 , V_6 , L_41 ) ;
if ( F_103 ( V_6 -> V_305 ) ) {
V_147 = F_104 ( V_6 -> V_305 ) ;
F_83 ( V_239 L_42 ,
V_6 -> V_90 , V_147 ) ;
}
}
F_125 ( & V_6 -> V_276 ) ;
return 0 ;
V_293:
F_91 ( V_34 ) ;
F_126 ( V_225 -> V_216 , V_34 ) ;
F_125 ( & V_6 -> V_276 ) ;
V_237:
F_127 ( V_34 -> V_75 ) ;
V_6 -> V_275 = NULL ;
F_128 ( V_6 , V_34 -> V_83 ) ;
V_231:
F_129 ( V_34 ) ;
return V_147 ;
}
static void F_130 ( struct V_225 * V_225 )
{
struct V_33 * V_34 = F_131 ( V_225 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( V_6 -> V_305 ) {
F_132 ( V_6 -> V_305 ) ;
V_6 -> V_305 = NULL ;
}
if ( V_6 -> V_307 )
F_133 ( V_6 ) ;
F_134 ( V_6 ) ;
F_126 ( V_225 -> V_216 , V_34 ) ;
F_91 ( V_34 ) ;
F_135 ( V_225 ) ;
V_6 -> V_275 = NULL ;
F_128 ( V_6 , V_34 -> V_83 ) ;
F_127 ( V_34 -> V_75 ) ;
F_129 ( V_34 ) ;
}
static int F_136 ( struct V_225 * V_225 , T_4 V_308 )
{
struct V_33 * V_34 = F_131 ( V_225 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
unsigned long V_101 ;
F_34 ( & V_34 -> V_102 , V_101 ) ;
if ( ! F_17 ( & V_34 -> V_95 . V_61 ) ) {
F_83 ( L_43 , V_6 -> V_90 ) ;
F_15 ( V_34 ) ;
}
if ( ! F_17 ( & V_34 -> V_215 . V_61 ) ) {
F_83 ( L_44 , V_6 -> V_90 ) ;
F_137 ( V_34 ) ;
}
F_37 ( & V_34 -> V_102 , V_101 ) ;
if ( V_6 -> V_307 )
F_133 ( V_6 ) ;
F_134 ( V_6 ) ;
F_138 ( V_225 ) ;
if ( 0 != F_139 ( V_225 , F_140 ( V_225 , V_308 ) ) ) {
F_135 ( V_225 ) ;
V_34 -> V_308 . V_309 = 1 ;
}
return 0 ;
}
static int F_141 ( struct V_225 * V_225 )
{
struct V_33 * V_34 = F_131 ( V_225 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
unsigned long V_101 ;
int V_147 ;
if ( V_34 -> V_308 . V_309 ) {
V_147 = F_95 ( V_225 ) ;
if ( V_147 ) {
F_83 ( V_239 L_45 ,
V_6 -> V_90 ) ;
return V_147 ;
}
V_34 -> V_308 . V_309 = 0 ;
}
V_147 = F_139 ( V_225 , V_310 ) ;
if ( V_147 ) {
F_83 ( V_239 L_46 , V_6 -> V_90 ) ;
F_135 ( V_225 ) ;
V_34 -> V_308 . V_309 = 1 ;
return V_147 ;
}
F_142 ( V_225 ) ;
F_143 ( V_6 ) ;
if ( V_6 -> V_307 )
F_144 ( V_6 ) ;
F_8 ( V_54 , V_6 -> V_55 ) ;
F_34 ( & V_34 -> V_102 , V_101 ) ;
if ( ! F_17 ( & V_34 -> V_95 . V_61 ) ) {
F_83 ( L_47 , V_6 -> V_90 ) ;
F_16 ( V_34 , & V_34 -> V_95 ) ;
}
if ( ! F_17 ( & V_34 -> V_215 . V_61 ) ) {
F_83 ( L_48 , V_6 -> V_90 ) ;
F_145 ( V_34 , & V_34 -> V_215 ) ;
}
F_37 ( & V_34 -> V_102 , V_101 ) ;
return 0 ;
}
