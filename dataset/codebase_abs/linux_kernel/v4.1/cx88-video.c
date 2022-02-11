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
V_36 -> V_53 = 1 ;
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
F_19 (buf, &q->active, list)
V_38 -> V_53 = V_36 -> V_53 ++ ;
}
return 0 ;
}
static int F_20 ( struct V_67 * V_36 , const struct V_68 * V_48 ,
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
static int F_21 ( struct V_76 * V_64 )
{
struct V_33 * V_34 = V_64 -> V_67 -> V_73 ;
struct V_5 * V_6 = V_34 -> V_6 ;
struct V_37 * V_38 = F_22 ( V_64 , struct V_37 , V_64 ) ;
struct V_77 * V_78 = F_23 ( V_64 , 0 ) ;
V_38 -> V_41 = V_6 -> V_44 * V_34 -> V_48 -> V_74 >> 3 ;
if ( F_24 ( V_64 , 0 ) < V_6 -> V_45 * V_38 -> V_41 )
return - V_79 ;
F_25 ( V_64 , 0 , V_6 -> V_45 * V_38 -> V_41 ) ;
switch ( V_6 -> V_46 ) {
case V_80 :
F_26 ( V_34 -> V_81 , & V_38 -> V_42 ,
V_78 -> V_82 , 0 , V_83 ,
V_38 -> V_41 , 0 , V_6 -> V_45 ) ;
break;
case V_84 :
F_26 ( V_34 -> V_81 , & V_38 -> V_42 ,
V_78 -> V_82 , V_83 , 0 ,
V_38 -> V_41 , 0 , V_6 -> V_45 ) ;
break;
case V_85 :
F_26 ( V_34 -> V_81 , & V_38 -> V_42 ,
V_78 -> V_82 ,
0 , V_38 -> V_41 * ( V_6 -> V_45 >> 1 ) ,
V_38 -> V_41 , 0 ,
V_6 -> V_45 >> 1 ) ;
break;
case V_86 :
F_26 ( V_34 -> V_81 , & V_38 -> V_42 ,
V_78 -> V_82 ,
V_38 -> V_41 * ( V_6 -> V_45 >> 1 ) , 0 ,
V_38 -> V_41 , 0 ,
V_6 -> V_45 >> 1 ) ;
break;
case V_87 :
default:
F_26 ( V_34 -> V_81 , & V_38 -> V_42 ,
V_78 -> V_82 , 0 , V_38 -> V_41 ,
V_38 -> V_41 , V_38 -> V_41 ,
V_6 -> V_45 >> 1 ) ;
break;
}
F_4 ( 2 , L_3 ,
V_38 , V_38 -> V_64 . V_65 . V_66 ,
V_6 -> V_44 , V_6 -> V_45 , V_34 -> V_48 -> V_74 , V_34 -> V_48 -> V_88 ,
( unsigned long ) V_38 -> V_42 . V_43 ) ;
return 0 ;
}
static void F_27 ( struct V_76 * V_64 )
{
struct V_33 * V_34 = V_64 -> V_67 -> V_73 ;
struct V_37 * V_38 = F_22 ( V_64 , struct V_37 , V_64 ) ;
struct V_89 * V_42 = & V_38 -> V_42 ;
if ( V_42 -> V_90 )
F_28 ( V_34 -> V_81 , V_42 -> V_91 , V_42 -> V_90 , V_42 -> V_43 ) ;
memset ( V_42 , 0 , sizeof( * V_42 ) ) ;
}
static void F_29 ( struct V_76 * V_64 )
{
struct V_33 * V_34 = V_64 -> V_67 -> V_73 ;
struct V_37 * V_38 = F_22 ( V_64 , struct V_37 , V_64 ) ;
struct V_37 * V_92 ;
struct V_5 * V_6 = V_34 -> V_6 ;
struct V_35 * V_36 = & V_34 -> V_93 ;
V_38 -> V_42 . V_90 [ 1 ] = F_30 ( V_38 -> V_42 . V_43 + 8 ) ;
V_38 -> V_42 . V_94 [ 0 ] = F_30 ( V_95 | V_96 ) ;
V_38 -> V_42 . V_94 [ 1 ] = F_30 ( V_38 -> V_42 . V_43 + 8 ) ;
if ( F_17 ( & V_36 -> V_61 ) ) {
F_31 ( & V_38 -> V_63 , & V_36 -> V_61 ) ;
V_38 -> V_53 = V_36 -> V_53 ++ ;
F_4 ( 2 , L_4 ,
V_38 , V_38 -> V_64 . V_65 . V_66 ) ;
} else {
V_38 -> V_42 . V_90 [ 0 ] |= F_30 ( V_97 ) ;
V_92 = F_18 ( V_36 -> V_61 . V_92 , struct V_37 , V_63 ) ;
F_31 ( & V_38 -> V_63 , & V_36 -> V_61 ) ;
V_38 -> V_53 = V_36 -> V_53 ++ ;
V_92 -> V_42 . V_94 [ 1 ] = F_30 ( V_38 -> V_42 . V_43 ) ;
F_4 ( 2 , L_5 ,
V_38 , V_38 -> V_64 . V_65 . V_66 ) ;
}
}
static int F_32 ( struct V_67 * V_36 , unsigned int V_53 )
{
struct V_33 * V_34 = V_36 -> V_73 ;
struct V_35 * V_98 = & V_34 -> V_93 ;
struct V_37 * V_38 = F_18 ( V_98 -> V_61 . V_62 ,
struct V_37 , V_63 ) ;
F_12 ( V_34 , V_98 , V_38 ) ;
return 0 ;
}
static void F_33 ( struct V_67 * V_36 )
{
struct V_33 * V_34 = V_36 -> V_73 ;
struct V_5 * V_6 = V_34 -> V_6 ;
struct V_35 * V_98 = & V_34 -> V_93 ;
unsigned long V_99 ;
F_9 ( V_60 , 0x11 ) ;
F_9 ( V_58 , 0x06 ) ;
F_34 ( & V_34 -> V_100 , V_99 ) ;
while ( ! F_17 ( & V_98 -> V_61 ) ) {
struct V_37 * V_38 = F_18 ( V_98 -> V_61 . V_62 ,
struct V_37 , V_63 ) ;
F_35 ( & V_38 -> V_63 ) ;
F_36 ( & V_38 -> V_64 , V_101 ) ;
}
F_37 ( & V_34 -> V_100 , V_99 ) ;
}
static int F_38 ( struct V_102 * V_102 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
int V_103 = F_40 ( V_102 ) ;
if ( V_103 )
return V_103 ;
F_7 ( V_14 , V_6 -> V_104 . V_105 . V_12 ) ;
F_7 ( V_15 , V_6 -> V_104 . V_105 . V_9 ) ;
F_7 ( V_16 , V_6 -> V_104 . V_105 . V_10 ) ;
F_7 ( V_17 , V_6 -> V_104 . V_105 . V_11 ) ;
if ( V_6 -> V_104 . V_105 . V_22 ) {
if ( V_6 -> V_23 ) {
F_10 ( V_6 , V_24 , V_25 ,
V_6 -> V_104 . V_105 . V_22 , 0 , 0 ) ;
}
V_6 -> V_28 = V_29 ;
F_11 ( V_6 ) ;
} else {
V_6 -> V_28 = V_106 ;
F_11 ( V_6 ) ;
F_41 ( V_6 , V_107 , 1 ) ;
}
F_10 ( V_6 , V_108 , V_109 ) ;
return 0 ;
}
static int F_42 ( struct V_110 * V_111 )
{
struct V_5 * V_6 =
F_22 ( V_111 -> V_112 , struct V_5 , V_113 ) ;
const struct V_114 * V_115 = V_111 -> V_116 ;
T_1 V_117 , V_118 ;
V_118 = V_115 -> V_118 ;
switch ( V_111 -> V_119 ) {
case V_120 :
V_117 = ( ( V_111 -> V_121 - V_115 -> V_122 ) << V_115 -> V_123 ) & V_115 -> V_118 ;
if ( V_6 -> V_124 & V_125 ) {
V_117 = V_117 << 8 | V_117 ;
} else {
V_117 = ( V_117 * 0x5a ) / 0x7f << 8 | V_117 ;
}
V_118 = 0xffff ;
break;
case V_126 :
V_117 = ( V_111 -> V_121 < 1 ? 0 : ( ( V_111 -> V_121 + 3 ) << 7 ) ) ;
F_6 ( V_20 , V_118 , V_117 ) ;
break;
case V_127 :
V_117 = ( ( V_111 -> V_121 - V_115 -> V_122 ) << V_115 -> V_123 ) & V_115 -> V_118 ;
break;
default:
V_117 = ( ( V_111 -> V_121 - V_115 -> V_122 ) << V_115 -> V_123 ) & V_115 -> V_118 ;
break;
}
F_4 ( 1 , L_6 ,
V_111 -> V_119 , V_111 -> V_88 , V_111 -> V_121 , V_115 -> V_128 , V_117 ,
V_118 , V_115 -> V_129 ? L_7 : L_8 ) ;
if ( V_115 -> V_129 )
F_43 ( V_115 -> V_129 , V_115 -> V_128 , V_118 , V_117 ) ;
else
F_6 ( V_115 -> V_128 , V_118 , V_117 ) ;
return 0 ;
}
static int F_44 ( struct V_110 * V_111 )
{
struct V_5 * V_6 =
F_22 ( V_111 -> V_112 , struct V_5 , V_130 ) ;
const struct V_114 * V_115 = V_111 -> V_116 ;
T_1 V_117 , V_118 ;
if ( V_6 -> V_23 ) {
switch ( V_111 -> V_119 ) {
case V_131 :
F_45 ( V_6 , V_111 -> V_119 , V_111 -> V_121 ) ;
break;
case V_132 :
F_45 ( V_6 , V_111 -> V_119 , ( V_111 -> V_121 ) ?
( 0x90 + V_111 -> V_121 ) << 8 : 0 ) ;
break;
case V_133 :
F_45 ( V_6 , V_111 -> V_119 , V_111 -> V_121 << 9 ) ;
break;
default:
break;
}
}
V_118 = V_115 -> V_118 ;
switch ( V_111 -> V_119 ) {
case V_133 :
V_117 = ( V_111 -> V_121 < 0x40 ) ? ( 0x7f - V_111 -> V_121 ) : ( V_111 -> V_121 - 0x40 ) ;
break;
case V_132 :
V_117 = 0x3f - ( V_111 -> V_121 & 0x3f ) ;
break;
default:
V_117 = ( ( V_111 -> V_121 - V_115 -> V_122 ) << V_115 -> V_123 ) & V_115 -> V_118 ;
break;
}
F_4 ( 1 , L_6 ,
V_111 -> V_119 , V_111 -> V_88 , V_111 -> V_121 , V_115 -> V_128 , V_117 ,
V_118 , V_115 -> V_129 ? L_7 : L_8 ) ;
if ( V_115 -> V_129 )
F_43 ( V_115 -> V_129 , V_115 -> V_128 , V_118 , V_117 ) ;
else
F_6 ( V_115 -> V_128 , V_118 , V_117 ) ;
return 0 ;
}
static int F_46 ( struct V_102 * V_102 , void * V_116 ,
struct V_68 * V_134 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
V_134 -> V_48 . V_135 . V_44 = V_6 -> V_44 ;
V_134 -> V_48 . V_135 . V_45 = V_6 -> V_45 ;
V_134 -> V_48 . V_135 . V_46 = V_6 -> V_46 ;
V_134 -> V_48 . V_135 . V_136 = V_34 -> V_48 -> V_2 ;
V_134 -> V_48 . V_135 . V_137 =
( V_134 -> V_48 . V_135 . V_44 * V_34 -> V_48 -> V_74 ) >> 3 ;
V_134 -> V_48 . V_135 . V_138 =
V_134 -> V_48 . V_135 . V_45 * V_134 -> V_48 . V_135 . V_137 ;
V_134 -> V_48 . V_135 . V_139 = V_140 ;
return 0 ;
}
static int F_47 ( struct V_102 * V_102 , void * V_116 ,
struct V_68 * V_134 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
const struct V_1 * V_48 ;
enum V_141 V_46 ;
unsigned int V_142 , V_143 ;
V_48 = F_1 ( V_134 -> V_48 . V_135 . V_136 ) ;
if ( NULL == V_48 )
return - V_79 ;
V_142 = F_48 ( V_6 -> V_124 ) ;
V_143 = F_49 ( V_6 -> V_124 ) ;
V_46 = V_134 -> V_48 . V_135 . V_46 ;
switch ( V_46 ) {
case V_80 :
case V_84 :
case V_87 :
case V_86 :
case V_85 :
break;
default:
V_46 = ( V_134 -> V_48 . V_135 . V_45 > V_143 / 2 )
? V_87
: V_84 ;
break;
}
if ( F_50 ( V_46 ) )
V_143 /= 2 ;
F_51 ( & V_134 -> V_48 . V_135 . V_44 , 48 , V_142 , 2 ,
& V_134 -> V_48 . V_135 . V_45 , 32 , V_143 , 0 , 0 ) ;
V_134 -> V_48 . V_135 . V_46 = V_46 ;
V_134 -> V_48 . V_135 . V_137 =
( V_134 -> V_48 . V_135 . V_44 * V_48 -> V_74 ) >> 3 ;
V_134 -> V_48 . V_135 . V_138 =
V_134 -> V_48 . V_135 . V_45 * V_134 -> V_48 . V_135 . V_137 ;
return 0 ;
}
static int F_52 ( struct V_102 * V_102 , void * V_116 ,
struct V_68 * V_134 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
int V_144 = F_47 ( V_102 , V_116 , V_134 ) ;
if ( 0 != V_144 )
return V_144 ;
if ( F_53 ( & V_34 -> V_145 ) || F_53 ( & V_34 -> V_146 ) )
return - V_147 ;
if ( V_6 -> V_148 && F_53 ( & V_6 -> V_148 -> V_149 ) )
return - V_147 ;
V_34 -> V_48 = F_1 ( V_134 -> V_48 . V_135 . V_136 ) ;
V_6 -> V_44 = V_134 -> V_48 . V_135 . V_44 ;
V_6 -> V_45 = V_134 -> V_48 . V_135 . V_45 ;
V_6 -> V_46 = V_134 -> V_48 . V_135 . V_46 ;
return 0 ;
}
void F_54 ( struct V_102 * V_102 , struct V_5 * V_6 ,
struct V_150 * V_151 )
{
struct V_152 * V_153 = F_55 ( V_102 ) ;
F_56 ( V_151 -> V_154 , V_6 -> V_104 . V_88 , sizeof( V_151 -> V_154 ) ) ;
V_151 -> V_155 = V_156 | V_157 ;
if ( V_83 != V_6 -> V_104 . V_158 )
V_151 -> V_155 |= V_159 ;
switch ( V_153 -> V_160 ) {
case V_161 :
V_151 -> V_155 = V_162 | V_159 ;
break;
case V_163 :
V_151 -> V_155 |= V_164 ;
break;
case V_165 :
V_151 -> V_155 |= V_166 ;
break;
}
V_151 -> V_167 = V_151 -> V_155 | V_164 |
V_166 | V_168 ;
if ( V_6 -> V_104 . V_105 . type == V_169 )
V_151 -> V_167 |= V_162 ;
}
static int F_57 ( struct V_102 * V_102 , void * V_116 ,
struct V_150 * V_151 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
strcpy ( V_151 -> V_170 , L_9 ) ;
sprintf ( V_151 -> V_171 , L_10 , F_58 ( V_34 -> V_81 ) ) ;
F_54 ( V_102 , V_6 , V_151 ) ;
return 0 ;
}
static int F_59 ( struct V_102 * V_102 , void * V_116 ,
struct V_172 * V_134 )
{
if ( F_60 ( V_134 -> V_66 >= F_2 ( V_4 ) ) )
return - V_79 ;
F_56 ( V_134 -> V_173 , V_4 [ V_134 -> V_66 ] . V_88 , sizeof( V_134 -> V_173 ) ) ;
V_134 -> V_136 = V_4 [ V_134 -> V_66 ] . V_2 ;
return 0 ;
}
static int F_61 ( struct V_102 * V_102 , void * V_116 , T_2 * V_124 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
* V_124 = V_6 -> V_124 ;
return 0 ;
}
static int F_62 ( struct V_102 * V_102 , void * V_116 , T_2 V_174 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
return F_63 ( V_6 , V_174 ) ;
}
int F_64 ( struct V_5 * V_6 , struct V_175 * V_3 )
{
static const char * const V_176 [] = {
[ V_177 ] = L_11 ,
[ V_178 ] = L_12 ,
[ V_179 ] = L_13 ,
[ V_180 ] = L_14 ,
[ V_18 ] = L_15 ,
[ V_26 ] = L_16 ,
[ V_27 ] = L_17 ,
[ V_181 ] = L_18 ,
[ V_182 ] = L_19 ,
} ;
unsigned int V_183 = V_3 -> V_66 ;
if ( V_183 >= 4 )
return - V_79 ;
if ( 0 == F_5 ( V_183 ) . type )
return - V_79 ;
V_3 -> type = V_184 ;
strcpy ( V_3 -> V_88 , V_176 [ F_5 ( V_183 ) . type ] ) ;
if ( ( V_26 == F_5 ( V_183 ) . type ) ||
( V_27 == F_5 ( V_183 ) . type ) ) {
V_3 -> type = V_185 ;
}
V_3 -> V_186 = V_187 ;
return 0 ;
}
static int F_65 ( struct V_102 * V_102 , void * V_116 ,
struct V_175 * V_3 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
return F_64 ( V_6 , V_3 ) ;
}
static int F_66 ( struct V_102 * V_102 , void * V_116 , unsigned int * V_3 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
* V_3 = V_6 -> V_7 ;
return 0 ;
}
static int F_67 ( struct V_102 * V_102 , void * V_116 , unsigned int V_3 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( V_3 >= 4 )
return - V_79 ;
if ( 0 == F_5 ( V_3 ) . type )
return - V_79 ;
F_68 ( V_6 ) ;
F_3 ( V_6 , V_3 ) ;
return 0 ;
}
static int F_69 ( struct V_102 * V_102 , void * V_116 ,
struct V_188 * V_189 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
T_1 V_128 ;
if ( F_60 ( V_83 == V_6 -> V_104 . V_158 ) )
return - V_79 ;
if ( 0 != V_189 -> V_66 )
return - V_79 ;
strcpy ( V_189 -> V_88 , L_16 ) ;
V_189 -> V_190 = V_191 ;
V_189 -> V_192 = 0xffffffffUL ;
F_10 ( V_6 , V_108 , V_193 , V_189 ) ;
F_70 ( V_6 , V_189 ) ;
V_128 = F_71 ( V_194 ) ;
V_189 -> signal = ( V_128 & ( 1 << 5 ) ) ? 0xffff : 0x0000 ;
return 0 ;
}
static int F_72 ( struct V_102 * V_102 , void * V_116 ,
const struct V_188 * V_189 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( V_83 == V_6 -> V_104 . V_158 )
return - V_79 ;
if ( 0 != V_189 -> V_66 )
return - V_79 ;
F_41 ( V_6 , V_189 -> V_195 , 1 ) ;
return 0 ;
}
static int F_73 ( struct V_102 * V_102 , void * V_116 ,
struct V_196 * V_134 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( F_60 ( V_83 == V_6 -> V_104 . V_158 ) )
return - V_79 ;
if ( V_134 -> V_108 )
return - V_79 ;
V_134 -> V_197 = V_6 -> V_198 ;
F_10 ( V_6 , V_108 , V_199 , V_134 ) ;
return 0 ;
}
int F_74 ( struct V_5 * V_6 ,
const struct V_196 * V_134 )
{
struct V_196 V_200 = * V_134 ;
if ( F_60 ( V_83 == V_6 -> V_104 . V_158 ) )
return - V_79 ;
if ( F_60 ( V_134 -> V_108 != 0 ) )
return - V_79 ;
F_68 ( V_6 ) ;
F_10 ( V_6 , V_108 , V_201 , V_134 ) ;
F_10 ( V_6 , V_108 , V_199 , & V_200 ) ;
V_6 -> V_198 = V_200 . V_197 ;
F_75 ( 10 ) ;
F_11 ( V_6 ) ;
return 0 ;
}
static int F_76 ( struct V_102 * V_102 , void * V_116 ,
const struct V_196 * V_134 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
return F_74 ( V_6 , V_134 ) ;
}
static int F_77 ( struct V_102 * V_102 , void * V_202 ,
struct V_203 * V_128 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
V_128 -> V_121 = F_71 ( V_128 -> V_128 & 0xfffffc ) ;
V_128 -> V_91 = 4 ;
return 0 ;
}
static int F_78 ( struct V_102 * V_102 , void * V_202 ,
const struct V_203 * V_128 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
F_7 ( V_128 -> V_128 & 0xfffffc , V_128 -> V_121 ) ;
return 0 ;
}
static int F_79 ( struct V_102 * V_102 , void * V_116 ,
struct V_188 * V_189 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( F_60 ( V_189 -> V_66 > 0 ) )
return - V_79 ;
strcpy ( V_189 -> V_88 , L_20 ) ;
F_10 ( V_6 , V_108 , V_193 , V_189 ) ;
return 0 ;
}
static int F_80 ( struct V_102 * V_102 , void * V_116 ,
const struct V_188 * V_189 )
{
struct V_33 * V_34 = F_39 ( V_102 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( 0 != V_189 -> V_66 )
return - V_79 ;
F_10 ( V_6 , V_108 , V_204 , V_189 ) ;
return 0 ;
}
static void F_81 ( struct V_33 * V_34 )
{
struct V_5 * V_6 = V_34 -> V_6 ;
T_1 V_205 , V_118 , V_53 ;
V_205 = F_71 ( V_206 ) ;
V_118 = F_71 ( V_57 ) ;
if ( 0 == ( V_205 & V_118 ) )
return;
F_7 ( V_206 , V_205 ) ;
if ( V_207 || ( V_205 & V_118 & ~ 0xff ) )
F_82 ( V_6 -> V_88 , L_21 ,
V_208 , F_2 ( V_208 ) ,
V_205 , V_118 ) ;
if ( V_205 & ( 1 << 16 ) ) {
F_83 ( V_209 L_22 , V_6 -> V_88 ) ;
F_9 ( V_60 , 0x11 ) ;
F_9 ( V_58 , 0x06 ) ;
F_84 ( V_6 , & V_39 [ V_40 ] ) ;
}
if ( V_205 & 0x01 ) {
F_85 ( & V_34 -> V_100 ) ;
V_53 = F_71 ( V_210 ) ;
F_86 ( V_6 , & V_34 -> V_93 , V_53 ) ;
F_87 ( & V_34 -> V_100 ) ;
}
if ( V_205 & 0x08 ) {
F_85 ( & V_34 -> V_100 ) ;
V_53 = F_71 ( V_211 ) ;
F_86 ( V_6 , & V_34 -> V_212 , V_53 ) ;
F_87 ( & V_34 -> V_100 ) ;
}
}
static T_3 F_88 ( int V_213 , void * V_214 )
{
struct V_33 * V_34 = V_214 ;
struct V_5 * V_6 = V_34 -> V_6 ;
T_1 V_205 ;
int V_215 , V_216 = 0 ;
for ( V_215 = 0 ; V_215 < 10 ; V_215 ++ ) {
V_205 = F_71 ( V_217 ) &
( V_6 -> V_55 | V_56 ) ;
if ( 0 == V_205 )
goto V_218;
F_7 ( V_217 , V_205 ) ;
V_216 = 1 ;
if ( V_205 & V_6 -> V_55 )
F_89 ( V_6 , V_205 ) ;
if ( V_205 & V_56 )
F_81 ( V_34 ) ;
}
if ( 10 == V_215 ) {
F_83 ( V_209 L_23 ,
V_6 -> V_88 ) ;
F_7 ( V_54 , 0 ) ;
}
V_218:
return F_90 ( V_216 ) ;
}
static void F_91 ( struct V_33 * V_34 )
{
F_92 ( & V_34 -> V_219 ) ;
F_92 ( & V_34 -> V_220 ) ;
F_92 ( & V_34 -> V_221 ) ;
}
static int F_93 ( struct V_222 * V_222 ,
const struct V_223 * V_224 )
{
struct V_33 * V_34 ;
struct V_5 * V_6 ;
struct V_67 * V_36 ;
int V_144 ;
int V_3 ;
V_34 = F_94 ( sizeof( * V_34 ) , V_225 ) ;
if ( NULL == V_34 )
return - V_226 ;
V_34 -> V_81 = V_222 ;
if ( F_95 ( V_222 ) ) {
V_144 = - V_227 ;
goto V_228;
}
V_6 = F_96 ( V_34 -> V_81 ) ;
if ( NULL == V_6 ) {
V_144 = - V_79 ;
goto V_228;
}
V_34 -> V_6 = V_6 ;
V_34 -> V_229 = V_222 -> V_230 ;
F_97 ( V_222 , V_231 , & V_34 -> V_232 ) ;
F_83 ( V_233 L_24
L_25 , V_6 -> V_88 ,
F_58 ( V_222 ) , V_34 -> V_229 , V_222 -> V_213 ,
V_34 -> V_232 , ( unsigned long long ) F_98 ( V_222 , 0 ) ) ;
F_99 ( V_222 ) ;
if ( ! F_100 ( V_222 , F_101 ( 32 ) ) ) {
F_83 ( L_26 , V_6 -> V_88 ) ;
V_144 = - V_227 ;
goto V_234;
}
V_34 -> V_75 = F_102 ( & V_222 -> V_34 ) ;
if ( F_103 ( V_34 -> V_75 ) ) {
V_144 = F_104 ( V_34 -> V_75 ) ;
goto V_234;
}
F_105 ( & V_34 -> V_100 ) ;
F_106 ( & V_34 -> V_93 . V_61 ) ;
F_106 ( & V_34 -> V_212 . V_61 ) ;
V_144 = F_107 ( V_222 -> V_213 , F_88 ,
V_235 , V_6 -> V_88 , V_34 ) ;
if ( V_144 < 0 ) {
F_83 ( V_236 L_27 ,
V_6 -> V_88 , V_222 -> V_213 ) ;
goto V_234;
}
F_8 ( V_54 , V_6 -> V_55 ) ;
for ( V_3 = 0 ; V_3 < V_237 ; V_3 ++ ) {
const struct V_114 * V_115 = & V_238 [ V_3 ] ;
struct V_110 * V_239 ;
V_239 = F_108 ( & V_6 -> V_130 , & V_240 ,
V_115 -> V_119 , V_115 -> V_241 , V_115 -> V_242 , V_115 -> V_243 , V_115 -> V_244 ) ;
if ( V_239 == NULL ) {
V_144 = V_6 -> V_130 . error ;
goto V_234;
}
V_239 -> V_116 = ( void * ) V_115 ;
}
for ( V_3 = 0 ; V_3 < V_245 ; V_3 ++ ) {
const struct V_114 * V_115 = & V_246 [ V_3 ] ;
struct V_110 * V_239 ;
V_239 = F_108 ( & V_6 -> V_113 , & V_247 ,
V_115 -> V_119 , V_115 -> V_241 , V_115 -> V_242 , V_115 -> V_243 , V_115 -> V_244 ) ;
if ( V_239 == NULL ) {
V_144 = V_6 -> V_113 . error ;
goto V_234;
}
V_239 -> V_116 = ( void * ) V_115 ;
if ( V_239 -> V_119 == V_127 )
V_6 -> V_248 = V_239 ;
}
F_109 ( & V_6 -> V_113 , & V_6 -> V_130 , NULL ) ;
if ( V_6 -> V_104 . V_249 == V_250 ) {
struct V_251 V_252 = {
. type = L_28 ,
. V_253 = 0x36 >> 1 ,
. V_254 = & V_6 -> V_255 ,
} ;
struct V_256 * V_257 ;
if ( V_6 -> V_258 == V_259 )
V_6 -> V_255 . V_260 = true ;
else
V_6 -> V_255 . V_260 = false ;
V_257 = F_110 ( & V_6 -> V_261 , & V_6 -> V_262 ,
& V_252 , NULL ) ;
if ( V_257 != NULL ) {
V_6 -> V_23 = V_257 ;
V_257 -> V_263 = V_264 ;
}
}
if ( V_6 -> V_104 . V_249 == V_265 ) {
F_111 ( & V_6 -> V_261 , & V_6 -> V_262 ,
L_29 , 0 , F_112 ( 0xb0 >> 1 ) ) ;
}
switch ( V_6 -> V_258 ) {
case V_266 :
case V_267 : {
static const struct V_251 V_268 = {
F_113 ( L_30 , 0x6f )
} ;
F_114 ( L_31 ) ;
V_6 -> V_269 = F_115 ( & V_6 -> V_262 , & V_268 ) ;
}
case V_270 :
F_114 ( L_32 ) ;
}
F_116 ( V_222 , V_34 ) ;
V_34 -> V_48 = F_1 ( V_271 ) ;
V_6 -> V_272 = V_34 ;
F_117 ( & V_6 -> V_273 ) ;
F_63 ( V_6 , V_6 -> V_124 ) ;
F_118 ( & V_6 -> V_113 ) ;
F_118 ( & V_6 -> V_130 ) ;
F_3 ( V_6 , 0 ) ;
V_36 = & V_34 -> V_145 ;
V_36 -> type = V_274 ;
V_36 -> V_275 = V_276 | V_277 | V_278 | V_279 ;
V_36 -> V_280 = V_281 ;
V_36 -> V_282 = 2 ;
V_36 -> V_73 = V_34 ;
V_36 -> V_283 = sizeof( struct V_37 ) ;
V_36 -> V_284 = & V_285 ;
V_36 -> V_286 = & V_287 ;
V_36 -> V_288 = V_289 ;
V_36 -> V_273 = & V_6 -> V_273 ;
V_144 = F_119 ( V_36 ) ;
if ( V_144 < 0 )
goto V_290;
V_36 = & V_34 -> V_146 ;
V_36 -> type = V_291 ;
V_36 -> V_275 = V_276 | V_277 | V_278 | V_279 ;
V_36 -> V_280 = V_281 ;
V_36 -> V_282 = 2 ;
V_36 -> V_73 = V_34 ;
V_36 -> V_283 = sizeof( struct V_37 ) ;
V_36 -> V_284 = & V_292 ;
V_36 -> V_286 = & V_287 ;
V_36 -> V_288 = V_289 ;
V_36 -> V_273 = & V_6 -> V_273 ;
V_144 = F_119 ( V_36 ) ;
if ( V_144 < 0 )
goto V_290;
F_120 ( V_6 , V_34 -> V_81 , & V_34 -> V_221 ,
& V_293 , L_33 ) ;
F_121 ( & V_34 -> V_221 , V_34 ) ;
V_34 -> V_221 . V_294 = & V_6 -> V_113 ;
V_34 -> V_221 . V_295 = & V_34 -> V_145 ;
V_144 = F_122 ( & V_34 -> V_221 , V_163 ,
V_296 [ V_6 -> V_297 ] ) ;
if ( V_144 < 0 ) {
F_83 ( V_236 L_34 ,
V_6 -> V_88 ) ;
goto V_290;
}
F_83 ( V_233 L_35 ,
V_6 -> V_88 , F_123 ( & V_34 -> V_221 ) ) ;
F_120 ( V_6 , V_34 -> V_81 , & V_34 -> V_220 ,
& V_298 , L_36 ) ;
F_121 ( & V_34 -> V_220 , V_34 ) ;
V_34 -> V_220 . V_295 = & V_34 -> V_146 ;
V_144 = F_122 ( & V_34 -> V_220 , V_165 ,
V_299 [ V_6 -> V_297 ] ) ;
if ( V_144 < 0 ) {
F_83 ( V_236 L_37 ,
V_6 -> V_88 ) ;
goto V_290;
}
F_83 ( V_233 L_38 ,
V_6 -> V_88 , F_123 ( & V_34 -> V_220 ) ) ;
if ( V_6 -> V_104 . V_105 . type == V_169 ) {
F_120 ( V_6 , V_34 -> V_81 , & V_34 -> V_219 ,
& V_300 , L_39 ) ;
F_121 ( & V_34 -> V_219 , V_34 ) ;
V_34 -> V_219 . V_294 = & V_6 -> V_130 ;
V_144 = F_122 ( & V_34 -> V_219 , V_161 ,
V_301 [ V_6 -> V_297 ] ) ;
if ( V_144 < 0 ) {
F_83 ( V_236 L_40 ,
V_6 -> V_88 ) ;
goto V_290;
}
F_83 ( V_233 L_38 ,
V_6 -> V_88 , F_123 ( & V_34 -> V_219 ) ) ;
}
if ( V_6 -> V_104 . V_158 != V_83 ) {
V_6 -> V_302 = F_124 ( V_303 , V_6 , L_41 ) ;
if ( F_103 ( V_6 -> V_302 ) ) {
V_144 = F_104 ( V_6 -> V_302 ) ;
F_83 ( V_236 L_42 ,
V_6 -> V_88 , V_144 ) ;
}
}
F_125 ( & V_6 -> V_273 ) ;
return 0 ;
V_290:
F_91 ( V_34 ) ;
F_126 ( V_222 -> V_213 , V_34 ) ;
F_125 ( & V_6 -> V_273 ) ;
V_234:
F_127 ( V_34 -> V_75 ) ;
V_6 -> V_272 = NULL ;
F_128 ( V_6 , V_34 -> V_81 ) ;
V_228:
F_129 ( V_34 ) ;
return V_144 ;
}
static void F_130 ( struct V_222 * V_222 )
{
struct V_33 * V_34 = F_131 ( V_222 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
if ( V_6 -> V_302 ) {
F_132 ( V_6 -> V_302 ) ;
V_6 -> V_302 = NULL ;
}
if ( V_6 -> V_304 )
F_133 ( V_6 ) ;
F_134 ( V_6 ) ;
F_126 ( V_222 -> V_213 , V_34 ) ;
F_91 ( V_34 ) ;
F_135 ( V_222 ) ;
V_6 -> V_272 = NULL ;
F_128 ( V_6 , V_34 -> V_81 ) ;
F_127 ( V_34 -> V_75 ) ;
F_129 ( V_34 ) ;
}
static int F_136 ( struct V_222 * V_222 , T_4 V_305 )
{
struct V_33 * V_34 = F_131 ( V_222 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
unsigned long V_99 ;
F_34 ( & V_34 -> V_100 , V_99 ) ;
if ( ! F_17 ( & V_34 -> V_93 . V_61 ) ) {
F_83 ( L_43 , V_6 -> V_88 ) ;
F_15 ( V_34 ) ;
}
if ( ! F_17 ( & V_34 -> V_212 . V_61 ) ) {
F_83 ( L_44 , V_6 -> V_88 ) ;
F_137 ( V_34 ) ;
}
F_37 ( & V_34 -> V_100 , V_99 ) ;
if ( V_6 -> V_304 )
F_133 ( V_6 ) ;
F_134 ( V_6 ) ;
F_138 ( V_222 ) ;
if ( 0 != F_139 ( V_222 , F_140 ( V_222 , V_305 ) ) ) {
F_135 ( V_222 ) ;
V_34 -> V_305 . V_306 = 1 ;
}
return 0 ;
}
static int F_141 ( struct V_222 * V_222 )
{
struct V_33 * V_34 = F_131 ( V_222 ) ;
struct V_5 * V_6 = V_34 -> V_6 ;
unsigned long V_99 ;
int V_144 ;
if ( V_34 -> V_305 . V_306 ) {
V_144 = F_95 ( V_222 ) ;
if ( V_144 ) {
F_83 ( V_236 L_45 ,
V_6 -> V_88 ) ;
return V_144 ;
}
V_34 -> V_305 . V_306 = 0 ;
}
V_144 = F_139 ( V_222 , V_307 ) ;
if ( V_144 ) {
F_83 ( V_236 L_46 , V_6 -> V_88 ) ;
F_135 ( V_222 ) ;
V_34 -> V_305 . V_306 = 1 ;
return V_144 ;
}
F_142 ( V_222 ) ;
F_143 ( V_6 ) ;
if ( V_6 -> V_304 )
F_144 ( V_6 ) ;
F_8 ( V_54 , V_6 -> V_55 ) ;
F_34 ( & V_34 -> V_100 , V_99 ) ;
if ( ! F_17 ( & V_34 -> V_93 . V_61 ) ) {
F_83 ( L_47 , V_6 -> V_88 ) ;
F_16 ( V_34 , & V_34 -> V_93 ) ;
}
if ( ! F_17 ( & V_34 -> V_212 . V_61 ) ) {
F_83 ( L_48 , V_6 -> V_88 ) ;
F_145 ( V_34 , & V_34 -> V_212 ) ;
}
F_37 ( & V_34 -> V_100 , V_99 ) ;
return 0 ;
}
