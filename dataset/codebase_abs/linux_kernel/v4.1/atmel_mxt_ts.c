static T_1 F_1 ( const struct V_1 * V_2 )
{
return V_2 -> V_3 + 1 ;
}
static T_1 F_2 ( const struct V_1 * V_2 )
{
return V_2 -> V_4 + 1 ;
}
static bool F_3 ( unsigned int type )
{
switch ( type ) {
case V_5 :
case V_6 :
case V_7 :
case V_8 :
case V_9 :
case V_10 :
case V_11 :
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
return true ;
default:
return false ;
}
}
static void F_4 ( struct V_29 * V_30 , T_2 * V_31 )
{
F_5 ( & V_30 -> V_32 -> V_33 , L_1 ,
V_30 -> V_34 , V_31 ) ;
}
static int F_6 ( struct V_29 * V_30 ,
struct V_35 * V_36 ,
unsigned int V_37 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
unsigned long V_39 = F_7 ( V_37 ) ;
long V_40 ;
V_40 = F_8 ( V_36 , V_39 ) ;
if ( V_40 < 0 ) {
return V_40 ;
} else if ( V_40 == 0 ) {
F_9 ( V_33 , L_2 ) ;
return - V_41 ;
}
return 0 ;
}
static int F_10 ( struct V_29 * V_30 ,
T_2 * V_42 , unsigned int V_43 )
{
int V_40 ;
struct V_44 V_45 ;
V_45 . V_46 = V_30 -> V_47 ;
V_45 . V_48 = V_30 -> V_32 -> V_48 & V_49 ;
V_45 . V_48 |= V_50 ;
V_45 . V_51 = V_43 ;
V_45 . V_52 = V_42 ;
V_40 = F_11 ( V_30 -> V_32 -> V_53 , & V_45 , 1 ) ;
if ( V_40 == 1 ) {
V_40 = 0 ;
} else {
V_40 = V_40 < 0 ? V_40 : - V_54 ;
F_9 ( & V_30 -> V_32 -> V_33 , L_3 ,
V_55 , V_40 ) ;
}
return V_40 ;
}
static int F_12 ( struct V_29 * V_30 ,
const T_2 * const V_42 , unsigned int V_43 )
{
int V_40 ;
struct V_44 V_45 ;
V_45 . V_46 = V_30 -> V_47 ;
V_45 . V_48 = V_30 -> V_32 -> V_48 & V_49 ;
V_45 . V_51 = V_43 ;
V_45 . V_52 = ( T_2 * ) V_42 ;
V_40 = F_11 ( V_30 -> V_32 -> V_53 , & V_45 , 1 ) ;
if ( V_40 == 1 ) {
V_40 = 0 ;
} else {
V_40 = V_40 < 0 ? V_40 : - V_54 ;
F_9 ( & V_30 -> V_32 -> V_33 , L_4 ,
V_55 , V_40 ) ;
}
return V_40 ;
}
static int F_13 ( struct V_29 * V_30 , bool V_56 )
{
T_2 V_57 = V_30 -> V_32 -> V_46 ;
T_2 V_58 ;
switch ( V_57 ) {
case 0x4a :
case 0x4b :
if ( V_56 || V_30 -> V_59 . V_60 >= 0xa2 ) {
V_58 = V_57 - 0x24 ;
break;
}
case 0x4c :
case 0x4d :
case 0x5a :
case 0x5b :
V_58 = V_57 - 0x26 ;
break;
default:
F_9 ( & V_30 -> V_32 -> V_33 ,
L_5 ,
V_57 ) ;
return - V_61 ;
}
V_30 -> V_47 = V_58 ;
return 0 ;
}
static int F_14 ( struct V_29 * V_30 , bool V_62 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int error ;
T_2 V_42 ;
bool V_63 ;
error = F_13 ( V_30 , V_62 ) ;
if ( error )
return error ;
error = F_10 ( V_30 , & V_42 , 1 ) ;
if ( error )
return error ;
V_63 = ( V_42 & ~ V_64 ) == V_65 ;
F_9 ( V_33 , L_6 ,
V_42 , V_63 ? L_7 : L_8 ) ;
return 0 ;
}
static T_2 F_15 ( struct V_29 * V_30 , T_2 V_42 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
T_2 V_52 [ 3 ] ;
if ( V_42 & V_66 ) {
if ( F_10 ( V_30 , & V_52 [ 0 ] , 3 ) != 0 ) {
F_9 ( V_33 , L_9 , V_55 ) ;
return V_42 ;
}
F_5 ( V_33 , L_10 , V_52 [ 1 ] , V_52 [ 2 ] ) ;
return V_52 [ 0 ] ;
} else {
F_5 ( V_33 , L_11 , V_42 & V_67 ) ;
return V_42 ;
}
}
static int F_16 ( struct V_29 * V_30 , unsigned int V_68 ,
bool V_69 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
T_2 V_42 ;
int V_40 ;
V_70:
if ( V_69 ) {
V_40 = F_6 ( V_30 , & V_30 -> V_71 ,
V_72 ) ;
if ( V_40 ) {
F_9 ( V_33 , L_12 , V_40 ) ;
return V_40 ;
}
}
V_40 = F_10 ( V_30 , & V_42 , 1 ) ;
if ( V_40 )
return V_40 ;
if ( V_68 == V_73 )
V_42 = F_15 ( V_30 , V_42 ) ;
switch ( V_68 ) {
case V_73 :
case V_74 :
case V_65 :
V_42 &= ~ V_64 ;
break;
case V_75 :
if ( V_42 == V_76 ) {
goto V_70;
} else if ( V_42 == V_77 ) {
F_9 ( V_33 , L_13 ) ;
return - V_61 ;
}
break;
default:
return - V_61 ;
}
if ( V_42 != V_68 ) {
F_9 ( V_33 , L_14 ,
V_42 , V_68 ) ;
return - V_61 ;
}
return 0 ;
}
static int F_17 ( struct V_29 * V_30 , bool V_78 )
{
int V_40 ;
T_2 V_52 [ 2 ] ;
if ( V_78 ) {
V_52 [ 0 ] = V_79 ;
V_52 [ 1 ] = V_80 ;
} else {
V_52 [ 0 ] = 0x01 ;
V_52 [ 1 ] = 0x01 ;
}
V_40 = F_12 ( V_30 , V_52 , 2 ) ;
if ( V_40 )
return V_40 ;
return 0 ;
}
static int F_18 ( struct V_81 * V_32 ,
T_3 V_82 , T_3 V_51 , void * V_42 )
{
struct V_44 V_83 [ 2 ] ;
T_2 V_52 [ 2 ] ;
int V_40 ;
V_52 [ 0 ] = V_82 & 0xff ;
V_52 [ 1 ] = ( V_82 >> 8 ) & 0xff ;
V_83 [ 0 ] . V_46 = V_32 -> V_46 ;
V_83 [ 0 ] . V_48 = 0 ;
V_83 [ 0 ] . V_51 = 2 ;
V_83 [ 0 ] . V_52 = V_52 ;
V_83 [ 1 ] . V_46 = V_32 -> V_46 ;
V_83 [ 1 ] . V_48 = V_50 ;
V_83 [ 1 ] . V_51 = V_51 ;
V_83 [ 1 ] . V_52 = V_42 ;
V_40 = F_11 ( V_32 -> V_53 , V_83 , 2 ) ;
if ( V_40 == 2 ) {
V_40 = 0 ;
} else {
if ( V_40 >= 0 )
V_40 = - V_54 ;
F_9 ( & V_32 -> V_33 , L_15 ,
V_55 , V_40 ) ;
}
return V_40 ;
}
static int F_19 ( struct V_81 * V_32 , T_3 V_82 , T_3 V_51 ,
const void * V_42 )
{
T_2 * V_52 ;
T_1 V_43 ;
int V_40 ;
V_43 = V_51 + 2 ;
V_52 = F_20 ( V_43 , V_84 ) ;
if ( ! V_52 )
return - V_85 ;
V_52 [ 0 ] = V_82 & 0xff ;
V_52 [ 1 ] = ( V_82 >> 8 ) & 0xff ;
memcpy ( & V_52 [ 2 ] , V_42 , V_51 ) ;
V_40 = F_21 ( V_32 , V_52 , V_43 ) ;
if ( V_40 == V_43 ) {
V_40 = 0 ;
} else {
if ( V_40 >= 0 )
V_40 = - V_54 ;
F_9 ( & V_32 -> V_33 , L_4 ,
V_55 , V_40 ) ;
}
F_22 ( V_52 ) ;
return V_40 ;
}
static int F_23 ( struct V_81 * V_32 , T_3 V_82 , T_2 V_42 )
{
return F_19 ( V_32 , V_82 , 1 , & V_42 ) ;
}
static struct V_1 *
F_24 ( struct V_29 * V_30 , T_2 type )
{
struct V_1 * V_86 ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_30 -> V_59 . V_88 ; V_87 ++ ) {
V_86 = V_30 -> V_89 + V_87 ;
if ( V_86 -> type == type )
return V_86 ;
}
F_25 ( & V_30 -> V_32 -> V_33 , L_16 , type ) ;
return NULL ;
}
static void F_26 ( struct V_29 * V_30 , T_2 * V_45 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
T_2 V_90 = V_45 [ 1 ] ;
T_4 V_91 = V_45 [ 2 ] | ( V_45 [ 3 ] << 8 ) | ( V_45 [ 4 ] << 16 ) ;
F_27 ( & V_30 -> V_92 ) ;
if ( V_91 != V_30 -> V_93 ) {
V_30 -> V_93 = V_91 ;
F_5 ( V_33 , L_17 , V_91 ) ;
}
if ( V_90 & V_94 )
F_27 ( & V_30 -> V_95 ) ;
if ( V_90 != V_30 -> V_96 )
F_5 ( V_33 , L_18 ,
V_90 ,
V_90 == 0 ? L_19 : L_8 ,
V_90 & V_94 ? L_20 : L_8 ,
V_90 & V_97 ? L_21 : L_8 ,
V_90 & V_98 ? L_22 : L_8 ,
V_90 & V_99 ? L_23 : L_8 ,
V_90 & V_100 ? L_24 : L_8 ,
V_90 & V_101 ? L_25 : L_8 ) ;
V_30 -> V_96 = V_90 ;
}
static int F_28 ( struct V_29 * V_30 ,
T_2 type , T_2 V_102 , T_2 V_42 )
{
struct V_1 * V_86 ;
T_3 V_82 ;
V_86 = F_24 ( V_30 , type ) ;
if ( ! V_86 || V_102 >= F_1 ( V_86 ) )
return - V_61 ;
V_82 = V_86 -> V_103 ;
return F_23 ( V_30 -> V_32 , V_82 + V_102 , V_42 ) ;
}
static void F_29 ( struct V_29 * V_30 , T_2 * V_31 )
{
struct V_104 * V_105 = V_30 -> V_104 ;
const struct V_106 * V_107 = V_30 -> V_107 ;
bool V_108 ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_107 -> V_109 ; V_87 ++ ) {
if ( V_107 -> V_110 [ V_87 ] == V_111 )
continue;
V_108 = ! ( V_31 [ 1 ] & ( 1 << V_87 ) ) ;
F_30 ( V_105 , V_107 -> V_110 [ V_87 ] , V_108 ) ;
}
}
static void F_31 ( struct V_29 * V_30 )
{
F_32 ( V_30 -> V_104 ,
V_30 -> V_107 -> V_109 ) ;
F_33 ( V_30 -> V_104 ) ;
}
static void F_34 ( struct V_29 * V_30 , T_2 * V_31 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_104 * V_104 = V_30 -> V_104 ;
int V_112 ;
T_2 V_90 ;
int V_113 ;
int V_114 ;
int V_115 ;
int V_116 ;
V_112 = V_31 [ 0 ] - V_30 -> V_117 ;
V_90 = V_31 [ 1 ] ;
V_113 = ( V_31 [ 2 ] << 4 ) | ( ( V_31 [ 4 ] >> 4 ) & 0xf ) ;
V_114 = ( V_31 [ 3 ] << 4 ) | ( ( V_31 [ 4 ] & 0xf ) ) ;
if ( V_30 -> V_118 < 1024 )
V_113 >>= 2 ;
if ( V_30 -> V_119 < 1024 )
V_114 >>= 2 ;
V_115 = V_31 [ 5 ] ;
V_116 = V_31 [ 6 ] ;
F_5 ( V_33 ,
L_26 ,
V_112 ,
( V_90 & V_120 ) ? 'D' : '.' ,
( V_90 & V_121 ) ? 'P' : '.' ,
( V_90 & V_122 ) ? 'R' : '.' ,
( V_90 & V_123 ) ? 'M' : '.' ,
( V_90 & V_124 ) ? 'V' : '.' ,
( V_90 & V_125 ) ? 'A' : '.' ,
( V_90 & V_126 ) ? 'S' : '.' ,
( V_90 & V_127 ) ? 'U' : '.' ,
V_113 , V_114 , V_115 , V_116 ) ;
F_35 ( V_104 , V_112 ) ;
if ( V_90 & V_120 ) {
if ( V_90 & V_122 ) {
F_36 ( V_104 ,
V_128 , 0 ) ;
F_31 ( V_30 ) ;
}
F_36 ( V_104 , V_128 , 1 ) ;
F_37 ( V_104 , V_129 , V_113 ) ;
F_37 ( V_104 , V_130 , V_114 ) ;
F_37 ( V_104 , V_131 , V_116 ) ;
F_37 ( V_104 , V_132 , V_115 ) ;
} else {
F_36 ( V_104 , V_128 , 0 ) ;
}
V_30 -> V_133 = true ;
}
static void F_38 ( struct V_29 * V_30 , T_2 * V_31 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_104 * V_104 = V_30 -> V_104 ;
int V_112 ;
T_2 V_90 ;
T_2 type = 0 ;
T_3 V_113 ;
T_3 V_114 ;
int V_134 = 0 ;
int V_135 = 0 ;
T_2 V_136 = 0 ;
T_2 V_137 = 0 ;
T_2 V_138 = 0 ;
V_112 = V_31 [ 0 ] - V_30 -> V_139 - 2 ;
if ( V_112 < 0 )
return;
V_90 = V_31 [ 1 ] ;
V_113 = F_39 ( & V_31 [ 2 ] ) ;
V_114 = F_39 ( & V_31 [ 4 ] ) ;
if ( V_90 & V_140 ) {
type = ( V_90 & V_141 ) >> 4 ;
switch ( type ) {
case V_142 :
V_135 = V_128 ;
V_134 = V_143 ;
if ( V_30 -> V_144 )
V_138 = V_31 [ V_30 -> V_144 ] ;
break;
case V_145 :
case V_146 :
V_135 = V_128 ;
V_134 = V_147 ;
if ( V_30 -> V_148 )
V_136 = V_31 [ V_30 -> V_148 ] ;
if ( V_30 -> V_149 )
V_137 = V_31 [ V_30 -> V_149 ] ;
if ( V_30 -> V_144 )
V_138 = V_31 [ V_30 -> V_144 ] ;
break;
case V_150 :
V_135 = V_151 ;
V_136 = V_152 ;
if ( V_30 -> V_149 )
V_137 = V_31 [ V_30 -> V_149 ] ;
break;
case V_153 :
break;
default:
F_5 ( V_33 , L_27 ) ;
return;
}
}
if ( ! V_137 && type != V_142 )
V_137 = V_154 ;
F_35 ( V_104 , V_112 ) ;
if ( V_90 & V_140 ) {
F_5 ( V_33 , L_28 ,
V_112 , type , V_113 , V_114 , V_136 , V_137 , V_138 ) ;
F_36 ( V_104 , V_135 , 1 ) ;
F_37 ( V_104 , V_129 , V_113 ) ;
F_37 ( V_104 , V_130 , V_114 ) ;
F_37 ( V_104 , V_132 , V_136 ) ;
F_37 ( V_104 , V_131 , V_137 ) ;
F_37 ( V_104 , V_155 , V_134 ) ;
F_37 ( V_104 , V_156 , V_138 ) ;
} else {
F_5 ( V_33 , L_29 , V_112 ) ;
F_36 ( V_104 , 0 , 0 ) ;
}
V_30 -> V_133 = true ;
}
static int F_40 ( struct V_29 * V_30 , T_2 * V_31 )
{
T_2 V_157 = V_31 [ 0 ] ;
if ( V_157 == V_158 )
return 0 ;
if ( V_157 == V_30 -> V_159 ) {
F_26 ( V_30 , V_31 ) ;
} else if ( ! V_30 -> V_104 ) {
F_4 ( V_30 , V_31 ) ;
} else if ( V_157 >= V_30 -> V_117 &&
V_157 <= V_30 -> V_160 ) {
F_34 ( V_30 , V_31 ) ;
} else if ( V_157 >= V_30 -> V_139 &&
V_157 <= V_30 -> V_161 ) {
F_38 ( V_30 , V_31 ) ;
} else if ( V_157 == V_30 -> V_162 ) {
F_29 ( V_30 , V_31 ) ;
V_30 -> V_133 = true ;
} else {
F_4 ( V_30 , V_31 ) ;
}
return 1 ;
}
static int F_41 ( struct V_29 * V_30 , T_2 V_43 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_40 ;
int V_87 ;
T_2 V_163 = 0 ;
if ( V_43 > V_30 -> V_164 )
return - V_61 ;
V_40 = F_18 ( V_30 -> V_32 , V_30 -> V_165 ,
V_30 -> V_34 * V_43 , V_30 -> V_166 ) ;
if ( V_40 ) {
F_9 ( V_33 , L_30 , V_43 , V_40 ) ;
return V_40 ;
}
for ( V_87 = 0 ; V_87 < V_43 ; V_87 ++ ) {
V_40 = F_40 ( V_30 ,
V_30 -> V_166 + V_30 -> V_34 * V_87 ) ;
if ( V_40 == 1 )
V_163 ++ ;
}
return V_163 ;
}
static T_5 F_42 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_40 ;
T_2 V_43 , V_167 ;
V_40 = F_18 ( V_30 -> V_32 , V_30 -> V_168 ,
V_30 -> V_34 + 1 , V_30 -> V_166 ) ;
if ( V_40 ) {
F_9 ( V_33 , L_31 , V_40 ) ;
return V_169 ;
}
V_43 = V_30 -> V_166 [ 0 ] ;
if ( V_43 == 0 ) {
F_5 ( V_33 , L_32 ) ;
return V_169 ;
} else if ( V_43 > V_30 -> V_164 ) {
F_9 ( V_33 , L_33 , V_43 ) ;
V_43 = V_30 -> V_164 ;
}
V_40 = F_40 ( V_30 , V_30 -> V_166 + 1 ) ;
if ( V_40 < 0 ) {
F_25 ( V_33 , L_34 ) ;
return V_169 ;
}
V_167 = V_43 - 1 ;
if ( V_167 ) {
V_40 = F_41 ( V_30 , V_167 ) ;
if ( V_40 < 0 )
goto V_170;
else if ( V_40 != V_167 )
F_25 ( V_33 , L_34 ) ;
}
V_170:
if ( V_30 -> V_133 ) {
F_31 ( V_30 ) ;
V_30 -> V_133 = false ;
}
return V_171 ;
}
static int F_43 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_43 , V_172 ;
T_2 V_173 = 2 ;
V_43 = V_30 -> V_164 ;
do {
V_172 = F_41 ( V_30 , V_43 ) ;
if ( V_172 < V_43 )
return 0 ;
} while ( -- V_173 );
if ( V_30 -> V_133 ) {
F_31 ( V_30 ) ;
V_30 -> V_133 = false ;
}
F_9 ( V_33 , L_35 ) ;
return - V_174 ;
}
static T_5 F_44 ( struct V_29 * V_30 )
{
int V_175 , V_176 ;
T_2 V_43 = V_30 -> V_177 ;
if ( V_43 < 1 || V_43 > V_30 -> V_164 )
V_43 = 1 ;
V_175 = F_41 ( V_30 , V_43 + 1 ) ;
if ( V_175 < 0 )
return V_169 ;
else if ( V_175 <= V_43 )
goto V_178;
do {
V_176 = F_41 ( V_30 , 2 ) ;
if ( V_176 < 0 )
return V_169 ;
V_175 += V_176 ;
if ( V_176 < 2 )
break;
} while ( V_175 < V_30 -> V_179 );
V_178:
V_30 -> V_177 = V_175 ;
if ( V_30 -> V_133 ) {
F_31 ( V_30 ) ;
V_30 -> V_133 = false ;
}
return V_171 ;
}
static T_5 F_45 ( int V_180 , void * V_181 )
{
struct V_29 * V_30 = V_181 ;
if ( V_30 -> V_182 ) {
F_27 ( & V_30 -> V_71 ) ;
return V_171 ;
}
if ( ! V_30 -> V_89 )
return V_171 ;
if ( V_30 -> V_168 ) {
return F_42 ( V_30 ) ;
} else {
return F_44 ( V_30 ) ;
}
}
static int F_46 ( struct V_29 * V_30 , T_3 V_183 ,
T_2 V_184 , bool V_69 )
{
T_3 V_82 ;
T_2 V_185 ;
int V_186 = 0 ;
int V_40 ;
V_82 = V_30 -> V_187 + V_183 ;
V_40 = F_23 ( V_30 -> V_32 , V_82 , V_184 ) ;
if ( V_40 )
return V_40 ;
if ( ! V_69 )
return 0 ;
do {
F_47 ( 20 ) ;
V_40 = F_18 ( V_30 -> V_32 , V_82 , 1 , & V_185 ) ;
if ( V_40 )
return V_40 ;
} while ( V_185 != 0 && V_186 ++ <= 100 );
if ( V_186 > 100 ) {
F_9 ( & V_30 -> V_32 -> V_33 , L_36 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_48 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_40 = 0 ;
F_49 ( V_33 , L_37 ) ;
F_50 ( & V_30 -> V_95 ) ;
V_40 = F_46 ( V_30 , V_188 , V_189 , false ) ;
if ( V_40 )
return V_40 ;
V_40 = F_6 ( V_30 , & V_30 -> V_95 ,
V_190 ) ;
if ( V_40 )
return V_40 ;
return 0 ;
}
static void F_51 ( struct V_29 * V_30 , T_2 V_191 , T_2 V_184 )
{
V_30 -> V_93 = 0 ;
F_50 ( & V_30 -> V_92 ) ;
F_46 ( V_30 , V_191 , V_184 , true ) ;
F_6 ( V_30 , & V_30 -> V_92 , V_192 ) ;
}
static void F_52 ( T_4 * V_91 , T_2 V_193 , T_2 V_194 )
{
static const unsigned int V_195 = 0x80001B ;
T_4 V_196 ;
T_4 V_197 ;
V_197 = ( V_194 << 8 ) | V_193 ;
V_196 = ( ( * V_91 << 1 ) ^ V_197 ) ;
if ( V_196 & 0x1000000 )
V_196 ^= V_195 ;
* V_91 = V_196 ;
}
static T_4 F_53 ( T_2 * V_198 , T_6 V_199 , T_6 V_200 )
{
T_4 V_91 = 0 ;
T_2 * V_201 = V_198 + V_199 ;
T_2 * V_202 = V_198 + V_200 - 1 ;
if ( V_200 < V_199 )
return - V_61 ;
while ( V_201 < V_202 ) {
F_52 ( & V_91 , * V_201 , * ( V_201 + 1 ) ) ;
V_201 += 2 ;
}
if ( V_201 == V_202 )
F_52 ( & V_91 , * V_201 , 0 ) ;
V_91 &= 0x00FFFFFF ;
return V_91 ;
}
static int F_54 ( struct V_29 * V_30 ,
const struct V_203 * V_204 ,
unsigned int V_205 ,
unsigned int V_206 ,
T_2 * V_207 ,
T_1 V_208 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_1 * V_86 ;
unsigned int type , V_209 , V_210 , V_211 ;
int V_102 ;
int V_40 ;
int V_87 ;
T_3 V_82 ;
T_2 V_42 ;
while ( V_205 < V_204 -> V_210 ) {
V_40 = sscanf ( V_204 -> V_30 + V_205 , L_38 ,
& type , & V_209 , & V_210 , & V_102 ) ;
if ( V_40 == 0 ) {
break;
} else if ( V_40 != 3 ) {
F_9 ( V_33 , L_39 ) ;
return - V_61 ;
}
V_205 += V_102 ;
V_86 = F_24 ( V_30 , type ) ;
if ( ! V_86 ) {
for ( V_87 = 0 ; V_87 < V_210 ; V_87 ++ ) {
V_40 = sscanf ( V_204 -> V_30 + V_205 , L_40 ,
& V_42 , & V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_41 ,
type , V_87 ) ;
return - V_61 ;
}
V_205 += V_102 ;
}
continue;
}
if ( V_210 > F_1 ( V_86 ) ) {
F_25 ( V_33 , L_42 ,
V_210 - F_1 ( V_86 ) , type ) ;
} else if ( F_1 ( V_86 ) > V_210 ) {
F_25 ( V_33 , L_43 ,
F_1 ( V_86 ) - V_210 , type ) ;
}
if ( V_209 >= F_2 ( V_86 ) ) {
F_9 ( V_33 , L_44 ) ;
return - V_61 ;
}
V_82 = V_86 -> V_103 + F_1 ( V_86 ) * V_209 ;
for ( V_87 = 0 ; V_87 < V_210 ; V_87 ++ ) {
V_40 = sscanf ( V_204 -> V_30 + V_205 , L_40 ,
& V_42 ,
& V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_41 ,
type , V_87 ) ;
return - V_61 ;
}
V_205 += V_102 ;
if ( V_87 > F_1 ( V_86 ) )
continue;
V_211 = V_82 + V_87 - V_206 ;
if ( V_211 >= 0 && V_211 < V_208 ) {
* ( V_207 + V_211 ) = V_42 ;
} else {
F_9 ( V_33 , L_45 ,
V_82 , V_86 -> type , V_211 ) ;
return - V_61 ;
}
}
}
return 0 ;
}
static int F_55 ( struct V_29 * V_30 , unsigned int V_212 ,
T_2 * V_207 , T_1 V_208 )
{
unsigned int V_211 = 0 ;
int error ;
while ( V_211 < V_208 ) {
unsigned int V_210 = V_208 - V_211 ;
if ( V_210 > V_213 )
V_210 = V_213 ;
error = F_19 ( V_30 -> V_32 ,
V_212 + V_211 ,
V_210 , V_207 + V_211 ) ;
if ( error ) {
F_9 ( & V_30 -> V_32 -> V_33 ,
L_46 , error ) ;
return error ;
}
V_211 += V_210 ;
}
return 0 ;
}
static int F_56 ( struct V_29 * V_30 , const struct V_203 * V_204 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_214 V_215 ;
int V_40 ;
int V_102 ;
int V_205 ;
int V_87 ;
int V_206 ;
T_4 V_216 , V_93 , V_217 ;
T_2 * V_207 ;
T_1 V_208 ;
F_51 ( V_30 , V_218 , 1 ) ;
if ( strncmp ( V_204 -> V_30 , V_219 , strlen ( V_219 ) ) ) {
F_9 ( V_33 , L_47 ) ;
return - V_61 ;
}
V_205 = strlen ( V_219 ) ;
for ( V_87 = 0 ; V_87 < sizeof( struct V_214 ) ; V_87 ++ ) {
V_40 = sscanf ( V_204 -> V_30 + V_205 , L_40 ,
( unsigned char * ) & V_215 + V_87 ,
& V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_48 ) ;
return - V_61 ;
}
V_205 += V_102 ;
}
if ( V_215 . V_60 != V_30 -> V_59 . V_60 ) {
F_9 ( V_33 , L_49 ) ;
return - V_61 ;
}
if ( V_215 . V_220 != V_30 -> V_59 . V_220 ) {
F_9 ( V_33 , L_50 ) ;
return - V_61 ;
}
V_40 = sscanf ( V_204 -> V_30 + V_205 , L_51 , & V_216 , & V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_52 ) ;
return - V_61 ;
}
V_205 += V_102 ;
V_40 = sscanf ( V_204 -> V_30 + V_205 , L_51 , & V_93 , & V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_53 ) ;
return - V_61 ;
}
V_205 += V_102 ;
if ( V_216 == V_30 -> V_216 ) {
if ( V_93 == 0 || V_30 -> V_93 == 0 ) {
F_49 ( V_33 , L_54 ) ;
} else if ( V_93 == V_30 -> V_93 ) {
F_5 ( V_33 , L_55 ,
V_30 -> V_93 ) ;
return 0 ;
} else {
F_49 ( V_33 , L_56 ,
V_30 -> V_93 , V_93 ) ;
}
} else {
F_25 ( V_33 ,
L_57 ,
V_30 -> V_216 , V_216 ) ;
}
V_206 = V_221 +
V_30 -> V_59 . V_88 * sizeof( struct V_1 ) +
V_222 ;
V_208 = V_30 -> V_223 - V_206 ;
V_207 = F_57 ( V_208 , V_84 ) ;
if ( ! V_207 ) {
F_9 ( V_33 , L_58 ) ;
return - V_85 ;
}
V_40 = F_54 ( V_30 , V_204 , V_205 , V_206 ,
V_207 , V_208 ) ;
if ( V_40 )
goto V_224;
if ( V_30 -> V_225 < V_206 ) {
F_9 ( V_33 , L_59 ,
V_30 -> V_225 , V_206 ) ;
V_40 = 0 ;
goto V_224;
}
V_217 = F_53 ( V_207 ,
V_30 -> V_225 - V_206 ,
V_208 ) ;
if ( V_93 > 0 && V_93 != V_217 )
F_25 ( V_33 , L_60 ,
V_217 , V_93 ) ;
V_40 = F_55 ( V_30 , V_206 ,
V_207 , V_208 ) ;
if ( V_40 )
goto V_224;
F_51 ( V_30 , V_226 , V_227 ) ;
V_40 = F_48 ( V_30 ) ;
if ( V_40 )
goto V_224;
F_49 ( V_33 , L_61 ) ;
V_224:
F_22 ( V_207 ) ;
return V_40 ;
}
static int F_58 ( struct V_29 * V_30 )
{
int error ;
F_59 ( V_30 -> V_180 ) ;
error = F_43 ( V_30 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_60 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
struct V_214 * V_59 = & V_30 -> V_59 ;
int error ;
error = F_18 ( V_32 , V_228 , sizeof( * V_59 ) , V_59 ) ;
if ( error )
return error ;
return 0 ;
}
static void F_61 ( struct V_29 * V_30 )
{
if ( V_30 -> V_104 ) {
F_62 ( V_30 -> V_104 ) ;
V_30 -> V_104 = NULL ;
}
}
static void F_63 ( struct V_29 * V_30 )
{
F_22 ( V_30 -> V_89 ) ;
V_30 -> V_89 = NULL ;
F_22 ( V_30 -> V_166 ) ;
V_30 -> V_166 = NULL ;
V_30 -> V_165 = 0 ;
V_30 -> V_34 = 0 ;
V_30 -> V_159 = 0 ;
V_30 -> V_225 = 0 ;
V_30 -> V_117 = 0 ;
V_30 -> V_160 = 0 ;
V_30 -> V_162 = 0 ;
V_30 -> V_168 = 0 ;
V_30 -> V_139 = 0 ;
V_30 -> V_161 = 0 ;
V_30 -> V_164 = 0 ;
}
static int F_64 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
T_1 V_229 ;
struct V_1 * V_89 ;
int error ;
int V_87 ;
T_2 V_230 ;
T_3 V_231 ;
V_229 = V_30 -> V_59 . V_88 * sizeof( struct V_1 ) ;
V_89 = F_57 ( V_229 , V_84 ) ;
if ( ! V_89 ) {
F_9 ( & V_30 -> V_32 -> V_33 , L_58 ) ;
return - V_85 ;
}
error = F_18 ( V_32 , V_221 , V_229 ,
V_89 ) ;
if ( error ) {
F_22 ( V_89 ) ;
return error ;
}
V_230 = 1 ;
V_30 -> V_223 = 0 ;
for ( V_87 = 0 ; V_87 < V_30 -> V_59 . V_88 ; V_87 ++ ) {
struct V_1 * V_86 = V_89 + V_87 ;
T_2 V_232 , V_233 ;
F_65 ( & V_86 -> V_103 ) ;
if ( V_86 -> V_234 ) {
V_232 = V_230 ;
V_230 += V_86 -> V_234 *
F_2 ( V_86 ) ;
V_233 = V_230 - 1 ;
} else {
V_232 = 0 ;
V_233 = 0 ;
}
F_5 ( & V_30 -> V_32 -> V_33 ,
L_62 ,
V_86 -> type , V_86 -> V_103 ,
F_1 ( V_86 ) , F_2 ( V_86 ) ,
V_232 , V_233 ) ;
switch ( V_86 -> type ) {
case V_235 :
if ( V_30 -> V_59 . V_60 == 0x80 &&
V_30 -> V_59 . V_236 < 0x20 ) {
V_30 -> V_34 = F_1 ( V_86 ) ;
} else {
V_30 -> V_34 = F_1 ( V_86 ) - 1 ;
}
V_30 -> V_165 = V_86 -> V_103 ;
break;
case V_5 :
V_30 -> V_159 = V_232 ;
V_30 -> V_187 = V_86 -> V_103 ;
break;
case V_6 :
V_30 -> V_225 = V_86 -> V_103 ;
break;
case V_9 :
V_30 -> V_237 = V_9 ;
V_30 -> V_117 = V_232 ;
V_30 -> V_160 = V_233 ;
V_30 -> V_179 = V_86 -> V_234
* F_2 ( V_86 ) ;
break;
case V_238 :
V_30 -> V_168 = V_86 -> V_103 ;
break;
case V_23 :
V_30 -> V_162 = V_232 ;
break;
case V_239 :
V_30 -> V_237 = V_239 ;
V_30 -> V_139 = V_232 ;
V_30 -> V_161 = V_233 ;
V_30 -> V_179 = V_86 -> V_234 - 2 ;
break;
}
V_231 = V_86 -> V_103
+ F_1 ( V_86 ) * F_2 ( V_86 ) - 1 ;
if ( V_231 >= V_30 -> V_223 )
V_30 -> V_223 = V_231 + 1 ;
}
V_30 -> V_164 = V_230 ;
if ( V_30 -> V_168 && ( V_30 -> V_165 != V_30 -> V_168 + 1 ) ) {
F_9 ( & V_32 -> V_33 , L_63 ) ;
error = - V_61 ;
goto V_240;
}
V_30 -> V_166 = F_66 ( V_30 -> V_164 ,
V_30 -> V_34 , V_84 ) ;
if ( ! V_30 -> V_166 ) {
F_9 ( & V_32 -> V_33 , L_64 ) ;
error = - V_85 ;
goto V_240;
}
V_30 -> V_89 = V_89 ;
return 0 ;
V_240:
F_63 ( V_30 ) ;
return error ;
}
static int F_67 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
int error ;
struct V_241 V_242 ;
unsigned char V_243 ;
struct V_1 * V_86 ;
V_86 = F_24 ( V_30 , V_9 ) ;
if ( ! V_86 )
return - V_61 ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_244 ,
sizeof( V_242 ) , & V_242 ) ;
if ( error )
return error ;
F_65 ( & V_242 . V_113 ) ;
F_65 ( & V_242 . V_114 ) ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_245 ,
1 , & V_243 ) ;
if ( error )
return error ;
if ( V_242 . V_113 == 0 )
V_242 . V_113 = 1023 ;
if ( V_242 . V_114 == 0 )
V_242 . V_114 = 1023 ;
if ( V_243 & V_246 ) {
V_30 -> V_118 = V_242 . V_114 ;
V_30 -> V_119 = V_242 . V_113 ;
} else {
V_30 -> V_118 = V_242 . V_113 ;
V_30 -> V_119 = V_242 . V_114 ;
}
F_5 ( & V_32 -> V_33 ,
L_65 , V_30 -> V_118 , V_30 -> V_119 ) ;
return 0 ;
}
static int F_68 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
int error ;
struct V_1 * V_86 ;
T_3 V_247 , V_248 ;
T_2 V_204 , V_249 ;
T_2 V_250 ;
V_86 = F_24 ( V_30 , V_239 ) ;
if ( ! V_86 )
return - V_61 ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_251 ,
sizeof( V_247 ) , & V_247 ) ;
if ( error )
return error ;
F_65 ( & V_247 ) ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_252 ,
sizeof( V_248 ) , & V_248 ) ;
if ( error )
return error ;
F_65 ( & V_248 ) ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_253 ,
1 , & V_204 ) ;
if ( error )
return error ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_254 ,
1 , & V_249 ) ;
if ( error )
return error ;
if ( V_247 == 0 )
V_247 = 1023 ;
if ( V_248 == 0 )
V_248 = 1023 ;
if ( V_204 & V_255 ) {
V_30 -> V_118 = V_248 ;
V_30 -> V_119 = V_247 ;
} else {
V_30 -> V_118 = V_247 ;
V_30 -> V_119 = V_248 ;
}
V_250 = 6 ;
if ( V_249 & V_256 )
V_30 -> V_144 = V_250 ++ ;
if ( V_249 & V_257 )
V_30 -> V_149 = V_250 ++ ;
if ( V_249 & V_258 )
V_30 -> V_148 = V_250 ++ ;
F_5 ( & V_32 -> V_33 ,
L_66 ,
V_30 -> V_144 , V_30 -> V_149 , V_30 -> V_148 ) ;
F_49 ( & V_32 -> V_33 ,
L_67 , V_30 -> V_118 , V_30 -> V_119 ) ;
return 0 ;
}
static void F_69 ( struct V_104 * V_104 ,
struct V_29 * V_30 )
{
const struct V_106 * V_107 = V_30 -> V_107 ;
int V_87 ;
V_104 -> V_259 = L_68 ;
F_70 ( V_260 , V_104 -> V_261 ) ;
F_71 ( V_104 , V_262 , V_263 ) ;
F_71 ( V_104 , V_264 , V_263 ) ;
F_71 ( V_104 , V_129 ,
V_263 ) ;
F_71 ( V_104 , V_130 ,
V_263 ) ;
for ( V_87 = 0 ; V_87 < V_107 -> V_109 ; V_87 ++ )
if ( V_107 -> V_110 [ V_87 ] != V_111 )
F_72 ( V_104 , V_265 ,
V_107 -> V_110 [ V_87 ] ) ;
}
static int F_73 ( struct V_29 * V_30 )
{
const struct V_106 * V_107 = V_30 -> V_107 ;
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_104 * V_104 ;
int error ;
unsigned int V_266 ;
unsigned int V_267 = 0 ;
switch ( V_30 -> V_237 ) {
case V_9 :
V_266 = V_30 -> V_160 - V_30 -> V_117 + 1 ;
error = F_67 ( V_30 ) ;
if ( error )
F_25 ( V_33 , L_69 ) ;
break;
case V_239 :
V_266 = V_30 -> V_179 ;
error = F_68 ( V_30 ) ;
if ( error )
F_25 ( V_33 , L_70 ) ;
break;
default:
F_9 ( V_33 , L_71 ) ;
return - V_61 ;
}
V_104 = F_74 () ;
if ( ! V_104 ) {
F_9 ( V_33 , L_58 ) ;
return - V_85 ;
}
V_104 -> V_259 = L_72 ;
V_104 -> V_268 = V_30 -> V_268 ;
V_104 -> V_112 . V_269 = V_270 ;
V_104 -> V_33 . V_271 = V_33 ;
V_104 -> V_272 = V_273 ;
V_104 -> V_274 = V_275 ;
F_72 ( V_104 , V_265 , V_276 ) ;
F_75 ( V_104 , V_262 , 0 , V_30 -> V_118 , 0 , 0 ) ;
F_75 ( V_104 , V_264 , 0 , V_30 -> V_119 , 0 , 0 ) ;
if ( V_30 -> V_237 == V_9 ||
( V_30 -> V_237 == V_239 &&
V_30 -> V_149 ) ) {
F_75 ( V_104 , V_277 , 0 , 255 , 0 , 0 ) ;
}
if ( V_107 -> V_109 ) {
F_69 ( V_104 , V_30 ) ;
V_267 |= V_278 ;
}
error = F_76 ( V_104 , V_266 , V_267 ) ;
if ( error ) {
F_9 ( V_33 , L_73 , error ) ;
goto V_279;
}
if ( V_30 -> V_237 == V_239 ) {
F_75 ( V_104 , V_280 ,
0 , V_281 , 0 , 0 ) ;
F_75 ( V_104 , V_155 ,
V_147 ,
V_143 ,
0 , 0 ) ;
}
F_75 ( V_104 , V_129 ,
0 , V_30 -> V_118 , 0 , 0 ) ;
F_75 ( V_104 , V_130 ,
0 , V_30 -> V_119 , 0 , 0 ) ;
if ( V_30 -> V_237 == V_9 ||
( V_30 -> V_237 == V_239 &&
V_30 -> V_148 ) ) {
F_75 ( V_104 , V_132 ,
0 , V_282 , 0 , 0 ) ;
}
if ( V_30 -> V_237 == V_9 ||
( V_30 -> V_237 == V_239 &&
V_30 -> V_149 ) ) {
F_75 ( V_104 , V_131 ,
0 , 255 , 0 , 0 ) ;
}
if ( V_30 -> V_237 == V_239 &&
V_30 -> V_144 ) {
F_75 ( V_104 , V_156 ,
0 , 255 , 0 , 0 ) ;
}
if ( V_30 -> V_237 == V_239 &&
V_30 -> V_149 ) {
F_75 ( V_104 , V_131 ,
0 , 255 , 0 , 0 ) ;
}
if ( V_30 -> V_237 == V_239 &&
V_30 -> V_144 ) {
F_75 ( V_104 , V_156 ,
0 , 255 , 0 , 0 ) ;
}
F_77 ( V_104 , V_30 ) ;
error = F_78 ( V_104 ) ;
if ( error ) {
F_9 ( V_33 , L_74 , error ) ;
goto V_279;
}
V_30 -> V_104 = V_104 ;
return 0 ;
V_279:
F_79 ( V_104 ) ;
return error ;
}
static void F_80 ( const struct V_203 * V_204 , void * V_283 )
{
F_81 ( V_283 , V_204 ) ;
F_82 ( V_204 ) ;
}
static int F_83 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
int V_284 = 0 ;
int error ;
while ( 1 ) {
error = F_60 ( V_30 ) ;
if ( ! error )
break;
error = F_14 ( V_30 , false ) ;
if ( error ) {
F_49 ( & V_32 -> V_33 , L_75 ) ;
error = F_14 ( V_30 , true ) ;
if ( error ) {
return error ;
}
}
if ( ++ V_284 > 1 ) {
F_9 ( & V_32 -> V_33 , L_76 ) ;
V_30 -> V_182 = true ;
return 0 ;
}
F_17 ( V_30 , false ) ;
F_47 ( V_285 ) ;
}
error = F_64 ( V_30 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_77 , error ) ;
return error ;
}
error = F_58 ( V_30 ) ;
if ( error )
goto V_286;
error = F_84 ( V_287 , true , V_288 ,
& V_32 -> V_33 , V_84 , V_30 ,
F_80 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_78 ,
error ) ;
goto V_286;
}
return 0 ;
V_286:
F_63 ( V_30 ) ;
return error ;
}
static int F_81 ( struct V_29 * V_30 ,
const struct V_203 * V_204 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_214 * V_59 = & V_30 -> V_59 ;
int error ;
if ( V_204 ) {
error = F_56 ( V_30 , V_204 ) ;
if ( error )
F_25 ( V_33 , L_79 , error ) ;
}
if ( V_30 -> V_237 ) {
error = F_73 ( V_30 ) ;
if ( error )
return error ;
} else {
F_25 ( V_33 , L_80 ) ;
}
F_49 ( V_33 ,
L_81 ,
V_59 -> V_60 , V_59 -> V_220 , V_59 -> V_236 >> 4 ,
V_59 -> V_236 & 0xf , V_59 -> V_289 , V_59 -> V_88 ) ;
return 0 ;
}
static T_7 F_85 ( struct V_38 * V_33 ,
struct V_290 * V_291 , char * V_52 )
{
struct V_29 * V_30 = F_86 ( V_33 ) ;
struct V_214 * V_59 = & V_30 -> V_59 ;
return F_87 ( V_52 , V_292 , L_82 ,
V_59 -> V_236 >> 4 , V_59 -> V_236 & 0xf , V_59 -> V_289 ) ;
}
static T_7 F_88 ( struct V_38 * V_33 ,
struct V_290 * V_291 , char * V_52 )
{
struct V_29 * V_30 = F_86 ( V_33 ) ;
struct V_214 * V_59 = & V_30 -> V_59 ;
return F_87 ( V_52 , V_292 , L_83 ,
V_59 -> V_60 , V_59 -> V_220 ) ;
}
static T_7 F_89 ( char * V_52 , int V_43 ,
struct V_1 * V_86 , int V_209 ,
const T_2 * V_42 )
{
int V_87 ;
if ( F_2 ( V_86 ) > 1 )
V_43 += F_87 ( V_52 + V_43 , V_292 - V_43 ,
L_84 , V_209 ) ;
for ( V_87 = 0 ; V_87 < F_1 ( V_86 ) ; V_87 ++ )
V_43 += F_87 ( V_52 + V_43 , V_292 - V_43 ,
L_85 , V_87 , V_42 [ V_87 ] , V_42 [ V_87 ] ) ;
V_43 += F_87 ( V_52 + V_43 , V_292 - V_43 , L_86 ) ;
return V_43 ;
}
static T_7 F_90 ( struct V_38 * V_33 ,
struct V_290 * V_291 , char * V_52 )
{
struct V_29 * V_30 = F_86 ( V_33 ) ;
struct V_1 * V_86 ;
int V_43 = 0 ;
int V_87 , V_293 ;
int error ;
T_2 * V_294 ;
V_294 = F_20 ( 256 , V_84 ) ;
if ( ! V_294 )
return - V_85 ;
error = 0 ;
for ( V_87 = 0 ; V_87 < V_30 -> V_59 . V_88 ; V_87 ++ ) {
V_86 = V_30 -> V_89 + V_87 ;
if ( ! F_3 ( V_86 -> type ) )
continue;
V_43 += F_87 ( V_52 + V_43 , V_292 - V_43 ,
L_87 , V_86 -> type ) ;
for ( V_293 = 0 ; V_293 < F_2 ( V_86 ) ; V_293 ++ ) {
T_3 V_210 = F_1 ( V_86 ) ;
T_3 V_46 = V_86 -> V_103 + V_293 * V_210 ;
error = F_18 ( V_30 -> V_32 , V_46 , V_210 , V_294 ) ;
if ( error )
goto V_295;
V_43 = F_89 ( V_52 , V_43 , V_86 , V_293 , V_294 ) ;
}
}
V_295:
F_22 ( V_294 ) ;
return error ? : V_43 ;
}
static int F_91 ( struct V_38 * V_33 ,
const struct V_203 * V_296 )
{
unsigned int V_297 = 0 ;
char V_298 ;
while ( V_297 < V_296 -> V_210 ) {
V_298 = * ( V_296 -> V_30 + V_297 ) ;
if ( V_298 < '0' || ( V_298 > '9' && V_298 < 'A' ) || V_298 > 'F' )
return 0 ;
V_297 ++ ;
}
F_9 ( V_33 , L_88 ) ;
return - V_61 ;
}
static int F_92 ( struct V_38 * V_33 , const char * V_299 )
{
struct V_29 * V_30 = F_86 ( V_33 ) ;
const struct V_203 * V_296 = NULL ;
unsigned int V_300 ;
unsigned int V_297 = 0 ;
unsigned int V_56 = 0 ;
unsigned int V_301 = 0 ;
int V_40 ;
V_40 = F_93 ( & V_296 , V_299 , V_33 ) ;
if ( V_40 ) {
F_9 ( V_33 , L_89 , V_299 ) ;
return V_40 ;
}
V_40 = F_91 ( V_33 , V_296 ) ;
if ( V_40 )
goto F_82;
if ( ! V_30 -> V_182 ) {
V_30 -> V_182 = true ;
V_40 = F_46 ( V_30 , V_188 ,
V_302 , false ) ;
if ( V_40 )
goto F_82;
F_47 ( V_303 ) ;
V_40 = F_13 ( V_30 , 0 ) ;
if ( V_40 )
goto F_82;
F_61 ( V_30 ) ;
F_63 ( V_30 ) ;
} else {
F_59 ( V_30 -> V_180 ) ;
}
F_50 ( & V_30 -> V_71 ) ;
V_40 = F_16 ( V_30 , V_73 , false ) ;
if ( V_40 ) {
V_40 = F_16 ( V_30 , V_74 , false ) ;
if ( V_40 )
goto V_304;
} else {
F_49 ( V_33 , L_90 ) ;
V_40 = F_17 ( V_30 , true ) ;
if ( V_40 )
goto V_304;
}
while ( V_297 < V_296 -> V_210 ) {
V_40 = F_16 ( V_30 , V_74 , true ) ;
if ( V_40 )
goto V_304;
V_300 = ( ( * ( V_296 -> V_30 + V_297 ) << 8 ) | * ( V_296 -> V_30 + V_297 + 1 ) ) ;
V_300 += 2 ;
V_40 = F_12 ( V_30 , V_296 -> V_30 + V_297 , V_300 ) ;
if ( V_40 )
goto V_304;
V_40 = F_16 ( V_30 , V_75 , true ) ;
if ( V_40 ) {
V_56 ++ ;
F_47 ( V_56 * 20 ) ;
if ( V_56 > 20 ) {
F_9 ( V_33 , L_91 ) ;
goto V_304;
}
} else {
V_56 = 0 ;
V_297 += V_300 ;
V_301 ++ ;
}
if ( V_301 % 50 == 0 )
F_5 ( V_33 , L_92 ,
V_301 , V_297 , V_296 -> V_210 ) ;
}
V_40 = F_6 ( V_30 , & V_30 -> V_71 ,
V_285 ) ;
if ( V_40 )
goto V_304;
F_5 ( V_33 , L_93 , V_301 , V_297 ) ;
F_6 ( V_30 , & V_30 -> V_71 , V_285 ) ;
V_30 -> V_182 = false ;
V_304:
V_304 ( V_30 -> V_180 ) ;
F_82:
F_82 ( V_296 ) ;
return V_40 ;
}
static T_7 F_94 ( struct V_38 * V_33 ,
struct V_290 * V_291 ,
const char * V_52 , T_1 V_43 )
{
struct V_29 * V_30 = F_86 ( V_33 ) ;
int error ;
error = F_92 ( V_33 , V_305 ) ;
if ( error ) {
F_9 ( V_33 , L_94 , error ) ;
V_43 = error ;
} else {
F_49 ( V_33 , L_95 ) ;
error = F_83 ( V_30 ) ;
if ( error )
return error ;
}
return V_43 ;
}
static void F_95 ( struct V_29 * V_30 )
{
F_28 ( V_30 , V_30 -> V_237 , V_306 , 0x83 ) ;
}
static void F_96 ( struct V_29 * V_30 )
{
F_28 ( V_30 , V_30 -> V_237 , V_306 , 0 ) ;
}
static int V_273 ( struct V_104 * V_33 )
{
struct V_29 * V_30 = F_97 ( V_33 ) ;
F_95 ( V_30 ) ;
return 0 ;
}
static void V_275 ( struct V_104 * V_33 )
{
struct V_29 * V_30 = F_97 ( V_33 ) ;
F_96 ( V_30 ) ;
}
static const struct V_106 * F_98 ( struct V_81 * V_32 )
{
struct V_106 * V_107 ;
T_4 * V_307 ;
T_4 V_308 ;
int V_309 , V_87 , V_40 ;
if ( ! V_32 -> V_33 . V_310 )
return F_99 ( - V_311 ) ;
V_107 = F_100 ( & V_32 -> V_33 , sizeof( * V_107 ) , V_84 ) ;
if ( ! V_107 )
return F_99 ( - V_85 ) ;
if ( F_101 ( V_32 -> V_33 . V_310 , L_96 ,
& V_309 ) ) {
V_107 -> V_109 = V_309 / sizeof( T_4 ) ;
V_307 = F_100 ( & V_32 -> V_33 ,
V_107 -> V_109 * sizeof( V_307 [ 0 ] ) ,
V_84 ) ;
if ( ! V_307 )
return F_99 ( - V_85 ) ;
for ( V_87 = 0 ; V_87 < V_107 -> V_109 ; V_87 ++ ) {
V_40 = F_102 ( V_32 -> V_33 . V_310 ,
L_96 , V_87 , & V_308 ) ;
if ( V_40 )
V_308 = V_111 ;
V_307 [ V_87 ] = V_308 ;
}
V_107 -> V_110 = V_307 ;
}
return V_107 ;
}
static const struct V_106 * F_98 ( struct V_81 * V_32 )
{
return F_99 ( - V_311 ) ;
}
static const struct V_106 * F_103 ( struct V_81 * V_32 )
{
struct V_312 * V_313 ;
const struct V_314 * V_315 ;
const struct V_316 * V_317 ;
if ( V_32 -> V_46 < 0x40 )
return F_99 ( - V_318 ) ;
V_313 = F_104 ( & V_32 -> V_33 ) ;
if ( ! V_313 )
return F_99 ( - V_311 ) ;
V_315 = F_105 ( V_319 ) ;
if ( ! V_315 )
return F_99 ( - V_311 ) ;
V_317 = V_315 -> V_320 ;
if ( ! V_317 )
return F_99 ( - V_311 ) ;
while ( V_317 -> V_321 ) {
if ( ! strcmp ( F_106 ( V_313 ) , V_317 -> V_321 ) )
return & V_317 -> V_107 ;
V_317 ++ ;
}
return F_99 ( - V_311 ) ;
}
static const struct V_106 * F_103 ( struct V_81 * V_32 )
{
return F_99 ( - V_311 ) ;
}
static const struct V_106 *
F_107 ( struct V_81 * V_32 )
{
const struct V_106 * V_107 ;
V_107 = F_108 ( & V_32 -> V_33 ) ;
if ( V_107 )
return V_107 ;
V_107 = F_98 ( V_32 ) ;
if ( ! F_109 ( V_107 ) || F_110 ( V_107 ) != - V_311 )
return V_107 ;
V_107 = F_103 ( V_32 ) ;
if ( ! F_109 ( V_107 ) || F_110 ( V_107 ) != - V_311 )
return V_107 ;
F_9 ( & V_32 -> V_33 , L_97 ) ;
return F_99 ( - V_61 ) ;
}
static int F_111 ( struct V_81 * V_32 , const struct V_322 * V_112 )
{
struct V_29 * V_30 ;
const struct V_106 * V_107 ;
int error ;
V_107 = F_107 ( V_32 ) ;
if ( F_109 ( V_107 ) )
return F_110 ( V_107 ) ;
V_30 = F_57 ( sizeof( struct V_29 ) , V_84 ) ;
if ( ! V_30 ) {
F_9 ( & V_32 -> V_33 , L_58 ) ;
return - V_85 ;
}
snprintf ( V_30 -> V_268 , sizeof( V_30 -> V_268 ) , L_98 ,
V_32 -> V_53 -> V_323 , V_32 -> V_46 ) ;
V_30 -> V_32 = V_32 ;
V_30 -> V_107 = V_107 ;
V_30 -> V_180 = V_32 -> V_180 ;
F_112 ( V_32 , V_30 ) ;
F_113 ( & V_30 -> V_71 ) ;
F_113 ( & V_30 -> V_95 ) ;
F_113 ( & V_30 -> V_92 ) ;
error = F_114 ( V_32 -> V_180 , NULL , F_45 ,
V_107 -> V_324 | V_325 ,
V_32 -> V_259 , V_30 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_99 ) ;
goto V_279;
}
V_304 ( V_32 -> V_180 ) ;
error = F_83 ( V_30 ) ;
if ( error )
goto V_326;
error = F_115 ( & V_32 -> V_33 . V_327 , & V_328 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_100 ,
error ) ;
goto V_329;
}
return 0 ;
V_329:
F_61 ( V_30 ) ;
F_63 ( V_30 ) ;
V_326:
F_116 ( V_32 -> V_180 , V_30 ) ;
V_279:
F_22 ( V_30 ) ;
return error ;
}
static int F_117 ( struct V_81 * V_32 )
{
struct V_29 * V_30 = F_118 ( V_32 ) ;
F_119 ( & V_32 -> V_33 . V_327 , & V_328 ) ;
F_116 ( V_30 -> V_180 , V_30 ) ;
F_61 ( V_30 ) ;
F_63 ( V_30 ) ;
F_22 ( V_30 ) ;
return 0 ;
}
static int T_8 F_120 ( struct V_38 * V_33 )
{
struct V_81 * V_32 = F_121 ( V_33 ) ;
struct V_29 * V_30 = F_118 ( V_32 ) ;
struct V_104 * V_104 = V_30 -> V_104 ;
F_122 ( & V_104 -> V_330 ) ;
if ( V_104 -> V_331 )
F_96 ( V_30 ) ;
F_123 ( & V_104 -> V_330 ) ;
return 0 ;
}
static int T_8 F_124 ( struct V_38 * V_33 )
{
struct V_81 * V_32 = F_121 ( V_33 ) ;
struct V_29 * V_30 = F_118 ( V_32 ) ;
struct V_104 * V_104 = V_30 -> V_104 ;
F_48 ( V_30 ) ;
F_122 ( & V_104 -> V_330 ) ;
if ( V_104 -> V_331 )
F_95 ( V_30 ) ;
F_123 ( & V_104 -> V_330 ) ;
return 0 ;
}
