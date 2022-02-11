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
int V_87 ;
for ( V_87 = 0 ; V_87 < V_107 -> V_108 ; V_87 ++ ) {
if ( V_107 -> V_109 [ V_87 ] == V_110 )
continue;
F_30 ( V_105 , V_107 -> V_109 [ V_87 ] ,
! ( V_31 [ 1 ] & F_31 ( V_87 ) ) ) ;
}
}
static void F_32 ( struct V_29 * V_30 )
{
F_33 ( V_30 -> V_104 ,
V_30 -> V_107 -> V_108 ) ;
F_34 ( V_30 -> V_104 ) ;
}
static void F_35 ( struct V_29 * V_30 , T_2 * V_31 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_104 * V_104 = V_30 -> V_104 ;
int V_111 ;
T_2 V_90 ;
int V_112 ;
int V_113 ;
int V_114 ;
int V_115 ;
V_111 = V_31 [ 0 ] - V_30 -> V_116 ;
V_90 = V_31 [ 1 ] ;
V_112 = ( V_31 [ 2 ] << 4 ) | ( ( V_31 [ 4 ] >> 4 ) & 0xf ) ;
V_113 = ( V_31 [ 3 ] << 4 ) | ( ( V_31 [ 4 ] & 0xf ) ) ;
if ( V_30 -> V_117 < 1024 )
V_112 >>= 2 ;
if ( V_30 -> V_118 < 1024 )
V_113 >>= 2 ;
V_114 = V_31 [ 5 ] ;
V_115 = V_31 [ 6 ] ;
F_5 ( V_33 ,
L_26 ,
V_111 ,
( V_90 & V_119 ) ? 'D' : '.' ,
( V_90 & V_120 ) ? 'P' : '.' ,
( V_90 & V_121 ) ? 'R' : '.' ,
( V_90 & V_122 ) ? 'M' : '.' ,
( V_90 & V_123 ) ? 'V' : '.' ,
( V_90 & V_124 ) ? 'A' : '.' ,
( V_90 & V_125 ) ? 'S' : '.' ,
( V_90 & V_126 ) ? 'U' : '.' ,
V_112 , V_113 , V_114 , V_115 ) ;
F_36 ( V_104 , V_111 ) ;
if ( V_90 & V_119 ) {
if ( V_90 & V_121 ) {
F_37 ( V_104 ,
V_127 , 0 ) ;
F_32 ( V_30 ) ;
}
F_37 ( V_104 , V_127 , 1 ) ;
F_38 ( V_104 , V_128 , V_112 ) ;
F_38 ( V_104 , V_129 , V_113 ) ;
F_38 ( V_104 , V_130 , V_115 ) ;
F_38 ( V_104 , V_131 , V_114 ) ;
} else {
F_37 ( V_104 , V_127 , 0 ) ;
}
V_30 -> V_132 = true ;
}
static void F_39 ( struct V_29 * V_30 , T_2 * V_31 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_104 * V_104 = V_30 -> V_104 ;
int V_111 ;
T_2 V_90 ;
T_2 type = 0 ;
T_3 V_112 ;
T_3 V_113 ;
int V_133 = 0 ;
int V_134 = 0 ;
T_2 V_135 = 0 ;
T_2 V_136 = 0 ;
T_2 V_137 = 0 ;
V_111 = V_31 [ 0 ] - V_30 -> V_138 - 2 ;
if ( V_111 < 0 )
return;
V_90 = V_31 [ 1 ] ;
V_112 = F_40 ( & V_31 [ 2 ] ) ;
V_113 = F_40 ( & V_31 [ 4 ] ) ;
if ( V_90 & V_139 ) {
type = ( V_90 & V_140 ) >> 4 ;
switch ( type ) {
case V_141 :
V_134 = V_127 ;
V_133 = V_142 ;
if ( V_30 -> V_143 )
V_137 = V_31 [ V_30 -> V_143 ] ;
break;
case V_144 :
case V_145 :
V_134 = V_127 ;
V_133 = V_146 ;
if ( V_30 -> V_147 )
V_135 = V_31 [ V_30 -> V_147 ] ;
if ( V_30 -> V_148 )
V_136 = V_31 [ V_30 -> V_148 ] ;
if ( V_30 -> V_143 )
V_137 = V_31 [ V_30 -> V_143 ] ;
break;
case V_149 :
V_134 = V_150 ;
V_135 = V_151 ;
if ( V_30 -> V_148 )
V_136 = V_31 [ V_30 -> V_148 ] ;
break;
case V_152 :
break;
default:
F_5 ( V_33 , L_27 ) ;
return;
}
}
if ( ! V_136 && type != V_141 )
V_136 = V_153 ;
F_36 ( V_104 , V_111 ) ;
if ( V_90 & V_139 ) {
F_5 ( V_33 , L_28 ,
V_111 , type , V_112 , V_113 , V_135 , V_136 , V_137 ) ;
F_37 ( V_104 , V_134 , 1 ) ;
F_38 ( V_104 , V_128 , V_112 ) ;
F_38 ( V_104 , V_129 , V_113 ) ;
F_38 ( V_104 , V_131 , V_135 ) ;
F_38 ( V_104 , V_130 , V_136 ) ;
F_38 ( V_104 , V_154 , V_133 ) ;
F_38 ( V_104 , V_155 , V_137 ) ;
} else {
F_5 ( V_33 , L_29 , V_111 ) ;
F_37 ( V_104 , 0 , 0 ) ;
}
V_30 -> V_132 = true ;
}
static int F_41 ( struct V_29 * V_30 , T_2 * V_31 )
{
T_2 V_156 = V_31 [ 0 ] ;
if ( V_156 == V_157 )
return 0 ;
if ( V_156 == V_30 -> V_158 ) {
F_26 ( V_30 , V_31 ) ;
} else if ( ! V_30 -> V_104 ) {
F_4 ( V_30 , V_31 ) ;
} else if ( V_156 >= V_30 -> V_116 &&
V_156 <= V_30 -> V_159 ) {
F_35 ( V_30 , V_31 ) ;
} else if ( V_156 >= V_30 -> V_138 &&
V_156 <= V_30 -> V_160 ) {
F_39 ( V_30 , V_31 ) ;
} else if ( V_156 == V_30 -> V_161 ) {
F_29 ( V_30 , V_31 ) ;
V_30 -> V_132 = true ;
} else {
F_4 ( V_30 , V_31 ) ;
}
return 1 ;
}
static int F_42 ( struct V_29 * V_30 , T_2 V_43 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_40 ;
int V_87 ;
T_2 V_162 = 0 ;
if ( V_43 > V_30 -> V_163 )
return - V_61 ;
V_40 = F_18 ( V_30 -> V_32 , V_30 -> V_164 ,
V_30 -> V_34 * V_43 , V_30 -> V_165 ) ;
if ( V_40 ) {
F_9 ( V_33 , L_30 , V_43 , V_40 ) ;
return V_40 ;
}
for ( V_87 = 0 ; V_87 < V_43 ; V_87 ++ ) {
V_40 = F_41 ( V_30 ,
V_30 -> V_165 + V_30 -> V_34 * V_87 ) ;
if ( V_40 == 1 )
V_162 ++ ;
}
return V_162 ;
}
static T_5 F_43 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_40 ;
T_2 V_43 , V_166 ;
V_40 = F_18 ( V_30 -> V_32 , V_30 -> V_167 ,
V_30 -> V_34 + 1 , V_30 -> V_165 ) ;
if ( V_40 ) {
F_9 ( V_33 , L_31 , V_40 ) ;
return V_168 ;
}
V_43 = V_30 -> V_165 [ 0 ] ;
if ( V_43 == 0 )
return V_168 ;
if ( V_43 > V_30 -> V_163 ) {
F_25 ( V_33 , L_32 , V_43 ) ;
V_43 = V_30 -> V_163 ;
}
V_40 = F_41 ( V_30 , V_30 -> V_165 + 1 ) ;
if ( V_40 < 0 ) {
F_25 ( V_33 , L_33 ) ;
return V_168 ;
}
V_166 = V_43 - 1 ;
if ( V_166 ) {
V_40 = F_42 ( V_30 , V_166 ) ;
if ( V_40 < 0 )
goto V_169;
else if ( V_40 != V_166 )
F_25 ( V_33 , L_33 ) ;
}
V_169:
if ( V_30 -> V_132 ) {
F_32 ( V_30 ) ;
V_30 -> V_132 = false ;
}
return V_170 ;
}
static int F_44 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_43 , V_171 ;
T_2 V_172 = 2 ;
V_43 = V_30 -> V_163 ;
do {
V_171 = F_42 ( V_30 , V_43 ) ;
if ( V_171 < V_43 )
return 0 ;
} while ( -- V_172 );
if ( V_30 -> V_132 ) {
F_32 ( V_30 ) ;
V_30 -> V_132 = false ;
}
F_9 ( V_33 , L_34 ) ;
return - V_173 ;
}
static T_5 F_45 ( struct V_29 * V_30 )
{
int V_174 , V_175 ;
T_2 V_43 = V_30 -> V_176 ;
if ( V_43 < 1 || V_43 > V_30 -> V_163 )
V_43 = 1 ;
V_174 = F_42 ( V_30 , V_43 + 1 ) ;
if ( V_174 < 0 )
return V_168 ;
else if ( V_174 <= V_43 )
goto V_177;
do {
V_175 = F_42 ( V_30 , 2 ) ;
if ( V_175 < 0 )
return V_168 ;
V_174 += V_175 ;
if ( V_175 < 2 )
break;
} while ( V_174 < V_30 -> V_178 );
V_177:
V_30 -> V_176 = V_174 ;
if ( V_30 -> V_132 ) {
F_32 ( V_30 ) ;
V_30 -> V_132 = false ;
}
return V_170 ;
}
static T_5 F_46 ( int V_179 , void * V_180 )
{
struct V_29 * V_30 = V_180 ;
if ( V_30 -> V_181 ) {
F_27 ( & V_30 -> V_71 ) ;
return V_170 ;
}
if ( ! V_30 -> V_89 )
return V_170 ;
if ( V_30 -> V_167 ) {
return F_43 ( V_30 ) ;
} else {
return F_45 ( V_30 ) ;
}
}
static int F_47 ( struct V_29 * V_30 , T_3 V_182 ,
T_2 V_183 , bool V_69 )
{
T_3 V_82 ;
T_2 V_184 ;
int V_185 = 0 ;
int V_40 ;
V_82 = V_30 -> V_186 + V_182 ;
V_40 = F_23 ( V_30 -> V_32 , V_82 , V_183 ) ;
if ( V_40 )
return V_40 ;
if ( ! V_69 )
return 0 ;
do {
F_48 ( 20 ) ;
V_40 = F_18 ( V_30 -> V_32 , V_82 , 1 , & V_184 ) ;
if ( V_40 )
return V_40 ;
} while ( V_184 != 0 && V_185 ++ <= 100 );
if ( V_185 > 100 ) {
F_9 ( & V_30 -> V_32 -> V_33 , L_35 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_49 ( struct V_29 * V_30 )
{
int error ;
F_50 ( V_30 -> V_179 ) ;
error = F_44 ( V_30 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_51 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_40 = 0 ;
F_52 ( V_33 , L_36 ) ;
F_53 ( V_30 -> V_179 ) ;
F_54 ( & V_30 -> V_95 ) ;
V_40 = F_47 ( V_30 , V_187 , V_188 , false ) ;
if ( V_40 )
return V_40 ;
F_48 ( 100 ) ;
F_49 ( V_30 ) ;
V_40 = F_6 ( V_30 , & V_30 -> V_95 ,
V_189 ) ;
if ( V_40 )
return V_40 ;
return 0 ;
}
static void F_55 ( struct V_29 * V_30 , T_2 V_190 , T_2 V_183 )
{
V_30 -> V_93 = 0 ;
F_54 ( & V_30 -> V_92 ) ;
F_47 ( V_30 , V_190 , V_183 , true ) ;
F_6 ( V_30 , & V_30 -> V_92 , V_191 ) ;
}
static void F_56 ( T_4 * V_91 , T_2 V_192 , T_2 V_193 )
{
static const unsigned int V_194 = 0x80001B ;
T_4 V_195 ;
T_4 V_196 ;
V_196 = ( V_193 << 8 ) | V_192 ;
V_195 = ( ( * V_91 << 1 ) ^ V_196 ) ;
if ( V_195 & 0x1000000 )
V_195 ^= V_194 ;
* V_91 = V_195 ;
}
static T_4 F_57 ( T_2 * V_197 , T_6 V_198 , T_6 V_199 )
{
T_4 V_91 = 0 ;
T_2 * V_200 = V_197 + V_198 ;
T_2 * V_201 = V_197 + V_199 - 1 ;
if ( V_199 < V_198 )
return - V_61 ;
while ( V_200 < V_201 ) {
F_56 ( & V_91 , * V_200 , * ( V_200 + 1 ) ) ;
V_200 += 2 ;
}
if ( V_200 == V_201 )
F_56 ( & V_91 , * V_200 , 0 ) ;
V_91 &= 0x00FFFFFF ;
return V_91 ;
}
static int F_58 ( struct V_29 * V_30 ,
const struct V_202 * V_203 ,
unsigned int V_204 ,
unsigned int V_205 ,
T_2 * V_206 ,
T_1 V_207 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_1 * V_86 ;
unsigned int type , V_208 , V_209 , V_210 ;
int V_102 ;
int V_40 ;
int V_87 ;
T_3 V_82 ;
T_2 V_42 ;
while ( V_204 < V_203 -> V_209 ) {
V_40 = sscanf ( V_203 -> V_30 + V_204 , L_37 ,
& type , & V_208 , & V_209 , & V_102 ) ;
if ( V_40 == 0 ) {
break;
} else if ( V_40 != 3 ) {
F_9 ( V_33 , L_38 ) ;
return - V_61 ;
}
V_204 += V_102 ;
V_86 = F_24 ( V_30 , type ) ;
if ( ! V_86 ) {
for ( V_87 = 0 ; V_87 < V_209 ; V_87 ++ ) {
V_40 = sscanf ( V_203 -> V_30 + V_204 , L_39 ,
& V_42 , & V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_40 ,
type , V_87 ) ;
return - V_61 ;
}
V_204 += V_102 ;
}
continue;
}
if ( V_209 > F_1 ( V_86 ) ) {
F_25 ( V_33 , L_41 ,
V_209 - F_1 ( V_86 ) , type ) ;
} else if ( F_1 ( V_86 ) > V_209 ) {
F_25 ( V_33 , L_42 ,
F_1 ( V_86 ) - V_209 , type ) ;
}
if ( V_208 >= F_2 ( V_86 ) ) {
F_9 ( V_33 , L_43 ) ;
return - V_61 ;
}
V_82 = V_86 -> V_103 + F_1 ( V_86 ) * V_208 ;
for ( V_87 = 0 ; V_87 < V_209 ; V_87 ++ ) {
V_40 = sscanf ( V_203 -> V_30 + V_204 , L_39 ,
& V_42 ,
& V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_40 ,
type , V_87 ) ;
return - V_61 ;
}
V_204 += V_102 ;
if ( V_87 > F_1 ( V_86 ) )
continue;
V_210 = V_82 + V_87 - V_205 ;
if ( V_210 >= 0 && V_210 < V_207 ) {
* ( V_206 + V_210 ) = V_42 ;
} else {
F_9 ( V_33 , L_44 ,
V_82 , V_86 -> type , V_210 ) ;
return - V_61 ;
}
}
}
return 0 ;
}
static int F_59 ( struct V_29 * V_30 , unsigned int V_211 ,
T_2 * V_206 , T_1 V_207 )
{
unsigned int V_210 = 0 ;
int error ;
while ( V_210 < V_207 ) {
unsigned int V_209 = V_207 - V_210 ;
if ( V_209 > V_212 )
V_209 = V_212 ;
error = F_19 ( V_30 -> V_32 ,
V_211 + V_210 ,
V_209 , V_206 + V_210 ) ;
if ( error ) {
F_9 ( & V_30 -> V_32 -> V_33 ,
L_45 , error ) ;
return error ;
}
V_210 += V_209 ;
}
return 0 ;
}
static int F_60 ( struct V_29 * V_30 , const struct V_202 * V_203 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_213 V_214 ;
int V_40 ;
int V_102 ;
int V_204 ;
int V_87 ;
int V_205 ;
T_4 V_215 , V_93 , V_216 ;
T_2 * V_206 ;
T_1 V_207 ;
F_55 ( V_30 , V_217 , 1 ) ;
if ( strncmp ( V_203 -> V_30 , V_218 , strlen ( V_218 ) ) ) {
F_9 ( V_33 , L_46 ) ;
return - V_61 ;
}
V_204 = strlen ( V_218 ) ;
for ( V_87 = 0 ; V_87 < sizeof( struct V_213 ) ; V_87 ++ ) {
V_40 = sscanf ( V_203 -> V_30 + V_204 , L_39 ,
( unsigned char * ) & V_214 + V_87 ,
& V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_47 ) ;
return - V_61 ;
}
V_204 += V_102 ;
}
if ( V_214 . V_60 != V_30 -> V_59 . V_60 ) {
F_9 ( V_33 , L_48 ) ;
return - V_61 ;
}
if ( V_214 . V_219 != V_30 -> V_59 . V_219 ) {
F_9 ( V_33 , L_49 ) ;
return - V_61 ;
}
V_40 = sscanf ( V_203 -> V_30 + V_204 , L_50 , & V_215 , & V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_51 ) ;
return - V_61 ;
}
V_204 += V_102 ;
V_40 = sscanf ( V_203 -> V_30 + V_204 , L_50 , & V_93 , & V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_52 ) ;
return - V_61 ;
}
V_204 += V_102 ;
if ( V_215 == V_30 -> V_215 ) {
if ( V_93 == 0 || V_30 -> V_93 == 0 ) {
F_52 ( V_33 , L_53 ) ;
} else if ( V_93 == V_30 -> V_93 ) {
F_5 ( V_33 , L_54 ,
V_30 -> V_93 ) ;
return 0 ;
} else {
F_52 ( V_33 , L_55 ,
V_30 -> V_93 , V_93 ) ;
}
} else {
F_25 ( V_33 ,
L_56 ,
V_30 -> V_215 , V_215 ) ;
}
V_205 = V_220 +
V_30 -> V_59 . V_88 * sizeof( struct V_1 ) +
V_221 ;
V_207 = V_30 -> V_222 - V_205 ;
V_206 = F_61 ( V_207 , V_84 ) ;
if ( ! V_206 ) {
F_9 ( V_33 , L_57 ) ;
return - V_85 ;
}
V_40 = F_58 ( V_30 , V_203 , V_204 , V_205 ,
V_206 , V_207 ) ;
if ( V_40 )
goto V_223;
if ( V_30 -> V_224 < V_205 ) {
F_9 ( V_33 , L_58 ,
V_30 -> V_224 , V_205 ) ;
V_40 = 0 ;
goto V_223;
}
V_216 = F_57 ( V_206 ,
V_30 -> V_224 - V_205 ,
V_207 ) ;
if ( V_93 > 0 && V_93 != V_216 )
F_25 ( V_33 , L_59 ,
V_216 , V_93 ) ;
V_40 = F_59 ( V_30 , V_205 ,
V_206 , V_207 ) ;
if ( V_40 )
goto V_223;
F_55 ( V_30 , V_225 , V_226 ) ;
V_40 = F_51 ( V_30 ) ;
if ( V_40 )
goto V_223;
F_52 ( V_33 , L_60 ) ;
F_62 ( V_30 ) ;
V_223:
F_22 ( V_206 ) ;
return V_40 ;
}
static int F_63 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
struct V_213 * V_59 = & V_30 -> V_59 ;
int error ;
error = F_18 ( V_32 , 0 , sizeof( * V_59 ) , V_59 ) ;
if ( error )
return error ;
return 0 ;
}
static void F_64 ( struct V_29 * V_30 )
{
if ( V_30 -> V_104 ) {
F_65 ( V_30 -> V_104 ) ;
V_30 -> V_104 = NULL ;
}
}
static void F_66 ( struct V_29 * V_30 )
{
#ifdef F_67
F_68 ( & V_30 -> V_227 . V_228 ) ;
F_69 ( & V_30 -> V_227 . V_229 ) ;
#endif
F_22 ( V_30 -> V_89 ) ;
V_30 -> V_89 = NULL ;
F_22 ( V_30 -> V_165 ) ;
V_30 -> V_165 = NULL ;
V_30 -> V_164 = 0 ;
V_30 -> V_34 = 0 ;
V_30 -> V_158 = 0 ;
V_30 -> V_224 = 0 ;
V_30 -> V_116 = 0 ;
V_30 -> V_159 = 0 ;
V_30 -> V_161 = 0 ;
V_30 -> V_167 = 0 ;
V_30 -> V_138 = 0 ;
V_30 -> V_160 = 0 ;
V_30 -> V_163 = 0 ;
}
static int F_70 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
T_1 V_230 ;
struct V_1 * V_89 ;
int error ;
int V_87 ;
T_2 V_231 ;
T_3 V_232 ;
V_230 = V_30 -> V_59 . V_88 * sizeof( struct V_1 ) ;
V_89 = F_61 ( V_230 , V_84 ) ;
if ( ! V_89 ) {
F_9 ( & V_30 -> V_32 -> V_33 , L_57 ) ;
return - V_85 ;
}
error = F_18 ( V_32 , V_220 , V_230 ,
V_89 ) ;
if ( error ) {
F_22 ( V_89 ) ;
return error ;
}
V_231 = 1 ;
V_30 -> V_222 = 0 ;
for ( V_87 = 0 ; V_87 < V_30 -> V_59 . V_88 ; V_87 ++ ) {
struct V_1 * V_86 = V_89 + V_87 ;
T_2 V_233 , V_234 ;
F_71 ( & V_86 -> V_103 ) ;
if ( V_86 -> V_235 ) {
V_233 = V_231 ;
V_231 += V_86 -> V_235 *
F_2 ( V_86 ) ;
V_234 = V_231 - 1 ;
} else {
V_233 = 0 ;
V_234 = 0 ;
}
F_5 ( & V_30 -> V_32 -> V_33 ,
L_61 ,
V_86 -> type , V_86 -> V_103 ,
F_1 ( V_86 ) , F_2 ( V_86 ) ,
V_233 , V_234 ) ;
switch ( V_86 -> type ) {
case V_236 :
if ( V_30 -> V_59 . V_60 == 0x80 &&
V_30 -> V_59 . V_237 < 0x20 ) {
V_30 -> V_34 = F_1 ( V_86 ) ;
} else {
V_30 -> V_34 = F_1 ( V_86 ) - 1 ;
}
V_30 -> V_164 = V_86 -> V_103 ;
break;
case V_5 :
V_30 -> V_158 = V_233 ;
V_30 -> V_186 = V_86 -> V_103 ;
break;
case V_6 :
V_30 -> V_224 = V_86 -> V_103 ;
break;
case V_9 :
V_30 -> V_238 = V_9 ;
V_30 -> V_116 = V_233 ;
V_30 -> V_159 = V_234 ;
V_30 -> V_178 = V_86 -> V_235
* F_2 ( V_86 ) ;
break;
case V_239 :
V_30 -> V_167 = V_86 -> V_103 ;
break;
case V_23 :
V_30 -> V_161 = V_233 ;
break;
case V_240 :
V_30 -> V_238 = V_240 ;
V_30 -> V_138 = V_233 ;
V_30 -> V_160 = V_234 ;
V_30 -> V_178 = V_86 -> V_235 - 2 ;
break;
}
V_232 = V_86 -> V_103
+ F_1 ( V_86 ) * F_2 ( V_86 ) - 1 ;
if ( V_232 >= V_30 -> V_222 )
V_30 -> V_222 = V_232 + 1 ;
}
V_30 -> V_163 = V_231 ;
if ( V_30 -> V_167 && ( V_30 -> V_164 != V_30 -> V_167 + 1 ) ) {
F_9 ( & V_32 -> V_33 , L_62 ) ;
error = - V_61 ;
goto V_241;
}
V_30 -> V_165 = F_72 ( V_30 -> V_163 ,
V_30 -> V_34 , V_84 ) ;
if ( ! V_30 -> V_165 ) {
F_9 ( & V_32 -> V_33 , L_63 ) ;
error = - V_85 ;
goto V_241;
}
V_30 -> V_89 = V_89 ;
return 0 ;
V_241:
F_66 ( V_30 ) ;
return error ;
}
static int F_73 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
int error ;
struct V_242 V_243 ;
unsigned char V_244 ;
struct V_1 * V_86 ;
V_86 = F_24 ( V_30 , V_9 ) ;
if ( ! V_86 )
return - V_61 ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_245 ,
sizeof( V_30 -> V_246 ) , & V_30 -> V_246 ) ;
if ( error )
return error ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_247 ,
sizeof( V_30 -> V_248 ) , & V_30 -> V_248 ) ;
if ( error )
return error ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_249 ,
sizeof( V_243 ) , & V_243 ) ;
if ( error )
return error ;
V_30 -> V_117 = F_40 ( & V_243 . V_112 ) ;
V_30 -> V_118 = F_40 ( & V_243 . V_113 ) ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_250 ,
1 , & V_244 ) ;
if ( error )
return error ;
V_30 -> V_251 = V_244 & V_252 ;
V_30 -> V_253 = V_244 & V_254 ;
V_30 -> V_255 = V_244 & V_256 ;
return 0 ;
}
static int F_74 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
int error ;
struct V_1 * V_86 ;
T_3 V_257 , V_258 ;
T_2 V_203 , V_259 ;
T_2 V_260 ;
V_86 = F_24 ( V_30 , V_240 ) ;
if ( ! V_86 )
return - V_61 ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_261 ,
sizeof( V_257 ) , & V_257 ) ;
if ( error )
return error ;
V_30 -> V_117 = F_40 ( & V_257 ) ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_262 ,
sizeof( V_258 ) , & V_258 ) ;
if ( error )
return error ;
V_30 -> V_118 = F_40 ( & V_258 ) ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_263 ,
sizeof( V_30 -> V_246 ) , & V_30 -> V_246 ) ;
if ( error )
return error ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_264 ,
sizeof( V_30 -> V_248 ) , & V_30 -> V_248 ) ;
if ( error )
return error ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_265 ,
1 , & V_203 ) ;
if ( error )
return error ;
V_30 -> V_251 = V_203 & V_266 ;
V_30 -> V_253 = V_203 & V_267 ;
V_30 -> V_255 = V_203 & V_268 ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_269 ,
1 , & V_259 ) ;
if ( error )
return error ;
V_260 = 6 ;
if ( V_259 & V_270 )
V_30 -> V_143 = V_260 ++ ;
if ( V_259 & V_271 )
V_30 -> V_148 = V_260 ++ ;
if ( V_259 & V_272 )
V_30 -> V_147 = V_260 ++ ;
F_5 ( & V_32 -> V_33 ,
L_64 ,
V_30 -> V_143 , V_30 -> V_148 , V_30 -> V_147 ) ;
return 0 ;
}
static void F_75 ( struct V_104 * V_104 ,
struct V_29 * V_30 )
{
const struct V_106 * V_107 = V_30 -> V_107 ;
int V_87 ;
V_104 -> V_273 = L_65 ;
F_76 ( V_274 , V_104 -> V_275 ) ;
F_77 ( V_104 , V_276 , V_277 ) ;
F_77 ( V_104 , V_278 , V_277 ) ;
F_77 ( V_104 , V_128 ,
V_277 ) ;
F_77 ( V_104 , V_129 ,
V_277 ) ;
for ( V_87 = 0 ; V_87 < V_107 -> V_108 ; V_87 ++ )
if ( V_107 -> V_109 [ V_87 ] != V_110 )
F_78 ( V_104 , V_279 ,
V_107 -> V_109 [ V_87 ] ) ;
}
static int F_79 ( struct V_29 * V_30 )
{
const struct V_106 * V_107 = V_30 -> V_107 ;
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_104 * V_104 ;
int error ;
unsigned int V_280 ;
unsigned int V_281 = 0 ;
switch ( V_30 -> V_238 ) {
case V_9 :
V_280 = V_30 -> V_159 - V_30 -> V_116 + 1 ;
error = F_73 ( V_30 ) ;
if ( error )
F_25 ( V_33 , L_66 ) ;
break;
case V_240 :
V_280 = V_30 -> V_178 ;
error = F_74 ( V_30 ) ;
if ( error )
F_25 ( V_33 , L_67 ) ;
break;
default:
F_9 ( V_33 , L_68 ) ;
return - V_61 ;
}
if ( V_30 -> V_117 == 0 )
V_30 -> V_117 = 1023 ;
if ( V_30 -> V_118 == 0 )
V_30 -> V_118 = 1023 ;
if ( V_30 -> V_251 )
F_80 ( V_30 -> V_117 , V_30 -> V_118 ) ;
F_52 ( V_33 , L_69 , V_30 -> V_117 , V_30 -> V_118 ) ;
V_104 = F_81 () ;
if ( ! V_104 ) {
F_9 ( V_33 , L_57 ) ;
return - V_85 ;
}
V_104 -> V_273 = L_70 ;
V_104 -> V_282 = V_30 -> V_282 ;
V_104 -> V_111 . V_283 = V_284 ;
V_104 -> V_33 . V_285 = V_33 ;
V_104 -> V_286 = V_287 ;
V_104 -> V_288 = V_289 ;
F_78 ( V_104 , V_279 , V_290 ) ;
F_82 ( V_104 , V_276 , 0 , V_30 -> V_117 , 0 , 0 ) ;
F_82 ( V_104 , V_278 , 0 , V_30 -> V_118 , 0 , 0 ) ;
if ( V_30 -> V_238 == V_9 ||
( V_30 -> V_238 == V_240 &&
V_30 -> V_148 ) ) {
F_82 ( V_104 , V_291 , 0 , 255 , 0 , 0 ) ;
}
if ( V_107 -> V_108 ) {
F_75 ( V_104 , V_30 ) ;
V_281 |= V_292 ;
} else {
V_281 |= V_293 ;
}
error = F_83 ( V_104 , V_280 , V_281 ) ;
if ( error ) {
F_9 ( V_33 , L_71 , error ) ;
goto V_294;
}
if ( V_30 -> V_238 == V_240 ) {
F_82 ( V_104 , V_295 ,
0 , V_296 , 0 , 0 ) ;
F_82 ( V_104 , V_154 ,
V_146 ,
V_142 ,
0 , 0 ) ;
}
F_82 ( V_104 , V_128 ,
0 , V_30 -> V_117 , 0 , 0 ) ;
F_82 ( V_104 , V_129 ,
0 , V_30 -> V_118 , 0 , 0 ) ;
if ( V_30 -> V_238 == V_9 ||
( V_30 -> V_238 == V_240 &&
V_30 -> V_147 ) ) {
F_82 ( V_104 , V_131 ,
0 , V_297 , 0 , 0 ) ;
}
if ( V_30 -> V_238 == V_9 ||
( V_30 -> V_238 == V_240 &&
V_30 -> V_148 ) ) {
F_82 ( V_104 , V_130 ,
0 , 255 , 0 , 0 ) ;
}
if ( V_30 -> V_238 == V_240 &&
V_30 -> V_143 ) {
F_82 ( V_104 , V_155 ,
0 , 255 , 0 , 0 ) ;
}
if ( V_30 -> V_238 == V_240 &&
V_30 -> V_148 ) {
F_82 ( V_104 , V_130 ,
0 , 255 , 0 , 0 ) ;
}
if ( V_30 -> V_238 == V_240 &&
V_30 -> V_143 ) {
F_82 ( V_104 , V_155 ,
0 , 255 , 0 , 0 ) ;
}
F_84 ( V_104 , V_30 ) ;
error = F_85 ( V_104 ) ;
if ( error ) {
F_9 ( V_33 , L_72 , error ) ;
goto V_294;
}
V_30 -> V_104 = V_104 ;
return 0 ;
V_294:
F_86 ( V_104 ) ;
return error ;
}
static void F_87 ( const struct V_202 * V_203 , void * V_298 )
{
F_88 ( V_298 , V_203 ) ;
F_89 ( V_203 ) ;
}
static int F_90 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
int V_299 = 0 ;
int error ;
while ( 1 ) {
error = F_63 ( V_30 ) ;
if ( ! error )
break;
error = F_14 ( V_30 , false ) ;
if ( error ) {
F_52 ( & V_32 -> V_33 , L_73 ) ;
error = F_14 ( V_30 , true ) ;
if ( error ) {
return error ;
}
}
if ( ++ V_299 > 1 ) {
F_9 ( & V_32 -> V_33 , L_74 ) ;
V_30 -> V_181 = true ;
return 0 ;
}
F_17 ( V_30 , false ) ;
F_48 ( V_300 ) ;
}
error = F_70 ( V_30 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_75 , error ) ;
return error ;
}
error = F_49 ( V_30 ) ;
if ( error )
goto V_301;
error = F_91 ( V_302 , true , V_303 ,
& V_32 -> V_33 , V_84 , V_30 ,
F_87 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_76 ,
error ) ;
goto V_301;
}
return 0 ;
V_301:
F_66 ( V_30 ) ;
return error ;
}
static int F_92 ( struct V_29 * V_30 , T_2 V_304 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int error ;
struct V_305 * V_306 ;
struct V_305 V_307 = { . V_308 = 0 , . V_309 = 0 } ;
if ( V_304 == V_310 )
V_306 = & V_307 ;
else
V_306 = & V_30 -> V_311 ;
error = F_19 ( V_30 -> V_32 , V_30 -> V_224 ,
sizeof( V_30 -> V_311 ) , V_306 ) ;
if ( error )
return error ;
F_5 ( V_33 , L_77 ,
V_306 -> V_308 , V_306 -> V_309 ) ;
return 0 ;
}
static int F_62 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int error ;
bool V_56 = false ;
V_70:
error = F_18 ( V_30 -> V_32 , V_30 -> V_224 ,
sizeof( V_30 -> V_311 ) , & V_30 -> V_311 ) ;
if ( error )
return error ;
if ( V_30 -> V_311 . V_308 == 0 || V_30 -> V_311 . V_309 == 0 ) {
if ( ! V_56 ) {
F_5 ( V_33 , L_78 ) ;
F_51 ( V_30 ) ;
V_56 = true ;
goto V_70;
} else {
F_5 ( V_33 , L_79 ) ;
V_30 -> V_311 . V_308 = 20 ;
V_30 -> V_311 . V_309 = 100 ;
return F_92 ( V_30 , V_312 ) ;
}
}
F_5 ( V_33 , L_80 ,
V_30 -> V_311 . V_308 , V_30 -> V_311 . V_309 ) ;
return 0 ;
}
static T_3 F_93 ( struct V_29 * V_30 , unsigned int V_112 ,
unsigned int V_113 )
{
struct V_213 * V_59 = & V_30 -> V_59 ;
struct V_313 * V_227 = & V_30 -> V_227 ;
unsigned int V_314 , V_315 ;
unsigned int V_316 = 0 ;
unsigned int V_317 ;
if ( V_59 -> V_60 == V_318 ) {
V_317 = V_59 -> V_319 / V_320 ;
V_316 = V_113 / V_317 ;
V_113 = V_113 % V_317 ;
} else {
V_317 = V_59 -> V_319 ;
}
V_314 = ( V_113 + ( V_112 * V_317 ) ) * sizeof( T_3 ) ;
V_315 = V_314 / V_321 ;
V_314 %= V_321 ;
if ( V_59 -> V_60 == V_318 )
V_315 += V_316 * V_322 ;
return F_40 ( & V_227 -> V_323 [ V_315 ] . V_30 [ V_314 ] ) ;
}
static int F_94 ( struct V_29 * V_30 , T_3 * V_324 )
{
struct V_313 * V_227 = & V_30 -> V_227 ;
unsigned int V_112 = 0 ;
unsigned int V_113 = 0 ;
unsigned int V_87 , V_325 , V_326 ;
for ( V_87 = 0 ; V_87 < V_227 -> V_327 ; V_87 ++ ) {
V_325 = V_30 -> V_251 ? V_113 : V_112 ;
V_326 = V_30 -> V_251 ? V_112 : V_113 ;
V_325 = V_30 -> V_253 ? ( V_30 -> V_246 - 1 - V_325 ) : V_325 ;
V_326 = V_30 -> V_255 ? ( V_30 -> V_248 - 1 - V_326 ) : V_326 ;
V_324 [ V_87 ] = F_93 ( V_30 , V_325 , V_326 ) ;
if ( ++ V_112 >= ( V_30 -> V_251 ? V_30 -> V_248 : V_30 -> V_246 ) ) {
V_112 = 0 ;
V_113 ++ ;
}
}
return 0 ;
}
static int F_95 ( struct V_29 * V_30 , T_2 V_328 ,
T_3 * V_324 )
{
struct V_313 * V_227 = & V_30 -> V_227 ;
int V_329 = 0 ;
int V_315 ;
int V_40 ;
T_2 V_190 = V_328 ;
struct V_330 * V_331 ;
T_2 V_332 ;
for ( V_315 = 0 ; V_315 < V_227 -> V_333 ; V_315 ++ ) {
V_331 = V_227 -> V_323 + V_315 ;
V_40 = F_23 ( V_30 -> V_32 , V_227 -> V_334 ,
V_190 ) ;
if ( V_40 )
return V_40 ;
V_329 = 0 ;
F_48 ( 20 ) ;
V_335:
V_40 = F_18 ( V_30 -> V_32 , V_227 -> V_334 ,
sizeof( V_332 ) , & V_332 ) ;
if ( V_40 )
return V_40 ;
if ( V_332 ) {
if ( V_329 ++ > 100 )
return - V_61 ;
F_48 ( 20 ) ;
goto V_335;
}
V_40 = F_18 ( V_30 -> V_32 , V_227 -> V_336 ,
sizeof( struct V_330 ) , V_331 ) ;
if ( V_40 )
return V_40 ;
if ( V_331 -> V_328 != V_328 || V_331 -> V_315 != V_315 ) {
F_9 ( & V_30 -> V_32 -> V_33 , L_81 ) ;
return - V_61 ;
}
F_5 ( & V_30 -> V_32 -> V_33 , L_82 ,
V_55 , V_315 , V_329 ) ;
V_190 = V_337 ;
}
return F_94 ( V_30 , V_324 ) ;
}
static int F_96 ( struct V_338 * V_339 ,
unsigned int * V_340 , unsigned int * V_341 ,
unsigned int V_342 [] , struct V_38 * V_343 [] )
{
struct V_29 * V_30 = V_339 -> V_344 ;
T_1 V_209 = V_30 -> V_227 . V_327 * sizeof( T_3 ) ;
if ( * V_341 )
return V_342 [ 0 ] < V_209 ? - V_61 : 0 ;
* V_341 = 1 ;
V_342 [ 0 ] = V_209 ;
return 0 ;
}
static void F_97 ( struct V_345 * V_346 )
{
struct V_29 * V_30 = F_98 ( V_346 -> V_338 ) ;
T_3 * V_200 ;
int V_40 ;
T_2 V_328 ;
V_200 = F_99 ( V_346 , 0 ) ;
if ( ! V_200 ) {
F_9 ( & V_30 -> V_32 -> V_33 , L_83 ) ;
goto V_347;
}
switch ( V_30 -> V_227 . V_105 ) {
case V_348 :
default:
V_328 = V_349 ;
break;
case V_350 :
V_328 = V_351 ;
break;
}
V_40 = F_95 ( V_30 , V_328 , V_200 ) ;
if ( V_40 )
goto V_347;
F_100 ( V_346 , 0 , V_30 -> V_227 . V_327 * sizeof( T_3 ) ) ;
F_101 ( V_346 , V_352 ) ;
return;
V_347:
F_101 ( V_346 , V_353 ) ;
}
static int F_102 ( struct V_354 * V_354 , void * V_355 ,
struct V_356 * V_357 )
{
struct V_29 * V_30 = F_103 ( V_354 ) ;
F_104 ( V_357 -> V_358 , L_84 , sizeof( V_357 -> V_358 ) ) ;
F_104 ( V_357 -> V_359 , L_85 , sizeof( V_357 -> V_359 ) ) ;
snprintf ( V_357 -> V_360 , sizeof( V_357 -> V_360 ) ,
L_86 , F_105 ( & V_30 -> V_32 -> V_33 ) ) ;
return 0 ;
}
static int F_106 ( struct V_354 * V_354 , void * V_355 ,
struct V_361 * V_87 )
{
if ( V_87 -> V_362 >= V_363 )
return - V_61 ;
V_87 -> type = V_364 ;
switch ( V_87 -> V_362 ) {
case V_350 :
F_104 ( V_87 -> V_273 , L_87 ,
sizeof( V_87 -> V_273 ) ) ;
break;
case V_348 :
F_104 ( V_87 -> V_273 , L_88 , sizeof( V_87 -> V_273 ) ) ;
break;
}
return 0 ;
}
static int F_107 ( struct V_29 * V_30 , unsigned int V_87 )
{
struct V_365 * V_366 = & V_30 -> V_227 . V_367 ;
if ( V_87 >= V_363 )
return - V_61 ;
if ( V_87 == V_348 )
V_366 -> V_368 = V_369 ;
else
V_366 -> V_368 = V_370 ;
V_366 -> V_371 = V_30 -> V_251 ? V_30 -> V_248 : V_30 -> V_246 ;
V_366 -> V_372 = V_30 -> V_251 ? V_30 -> V_246 : V_30 -> V_248 ;
V_366 -> V_373 = V_374 ;
V_366 -> V_375 = V_376 ;
V_366 -> V_377 = V_366 -> V_371 * sizeof( T_3 ) ;
V_366 -> V_378 = V_366 -> V_371 * V_366 -> V_372 * sizeof( T_3 ) ;
V_30 -> V_227 . V_105 = V_87 ;
return 0 ;
}
static int F_108 ( struct V_354 * V_354 , void * V_355 , unsigned int V_87 )
{
return F_107 ( F_103 ( V_354 ) , V_87 ) ;
}
static int F_109 ( struct V_354 * V_354 , void * V_355 , unsigned int * V_87 )
{
struct V_29 * V_30 = F_103 ( V_354 ) ;
* V_87 = V_30 -> V_227 . V_105 ;
return 0 ;
}
static int F_110 ( struct V_354 * V_354 , void * V_355 , struct V_379 * V_366 )
{
struct V_29 * V_30 = F_103 ( V_354 ) ;
V_366 -> type = V_380 ;
V_366 -> V_381 . V_382 = V_30 -> V_227 . V_367 ;
return 0 ;
}
static int F_111 ( struct V_354 * V_354 , void * V_355 ,
struct V_383 * V_381 )
{
if ( V_381 -> type != V_380 )
return - V_61 ;
switch ( V_381 -> V_362 ) {
case 0 :
V_381 -> V_368 = V_370 ;
break;
case 1 :
V_381 -> V_368 = V_369 ;
break;
default:
return - V_61 ;
}
return 0 ;
}
static int F_112 ( struct V_354 * V_354 , void * V_384 ,
struct V_385 * V_386 )
{
if ( V_386 -> type != V_380 )
return - V_61 ;
V_386 -> V_387 . V_388 . V_389 = 1 ;
V_386 -> V_387 . V_388 . V_390 . V_391 = 1 ;
V_386 -> V_387 . V_388 . V_390 . V_392 = 10 ;
return 0 ;
}
static void F_113 ( struct V_29 * V_30 )
{
struct V_213 * V_59 = & V_30 -> V_59 ;
struct V_313 * V_227 = & V_30 -> V_227 ;
struct V_1 * V_86 ;
int error ;
V_86 = F_24 ( V_30 , V_5 ) ;
if ( ! V_86 )
goto error;
V_227 -> V_334 = V_86 -> V_103 + V_393 ;
V_86 = F_24 ( V_30 , V_394 ) ;
if ( ! V_86 )
goto error;
if ( F_1 ( V_86 ) != sizeof( struct V_330 ) ) {
F_25 ( & V_30 -> V_32 -> V_33 , L_89 ) ;
goto error;
}
V_227 -> V_336 = V_86 -> V_103 ;
V_227 -> V_327 = V_30 -> V_246 * V_30 -> V_248 ;
if ( V_59 -> V_60 == V_318 )
V_227 -> V_333 = V_320 * V_322 ;
else
V_227 -> V_333 = F_114 ( V_30 -> V_246 *
V_30 -> V_59 . V_319 *
sizeof( T_3 ) ,
sizeof( V_227 -> V_323 -> V_30 ) ) ;
V_227 -> V_323 = F_115 ( & V_30 -> V_32 -> V_33 , V_227 -> V_333 ,
sizeof( struct V_330 ) , V_84 ) ;
if ( ! V_227 -> V_323 )
goto error;
F_107 ( V_30 , 0 ) ;
snprintf ( V_227 -> V_229 . V_273 , sizeof( V_227 -> V_229 . V_273 ) , L_90 , L_84 ) ;
error = F_116 ( & V_30 -> V_32 -> V_33 , & V_227 -> V_229 ) ;
if ( error )
goto error;
F_117 ( & V_227 -> V_395 ) ;
V_227 -> V_396 = V_397 ;
V_227 -> V_396 . V_344 = V_30 ;
V_227 -> V_396 . V_395 = & V_227 -> V_395 ;
V_227 -> V_396 . V_33 = & V_30 -> V_32 -> V_33 ;
error = F_118 ( & V_227 -> V_396 ) ;
if ( error )
goto V_398;
V_227 -> V_228 = V_399 ;
V_227 -> V_228 . V_400 = & V_227 -> V_229 ;
V_227 -> V_228 . V_395 = & V_227 -> V_395 ;
V_227 -> V_228 . V_401 = V_402 ;
V_227 -> V_228 . V_396 = & V_227 -> V_396 ;
F_119 ( & V_227 -> V_228 , V_30 ) ;
error = F_120 ( & V_227 -> V_228 , V_403 , - 1 ) ;
if ( error )
goto V_398;
return;
V_398:
F_69 ( & V_227 -> V_229 ) ;
error:
F_25 ( & V_30 -> V_32 -> V_33 , L_91 ) ;
}
static void F_113 ( struct V_29 * V_30 )
{
}
static int F_88 ( struct V_29 * V_30 ,
const struct V_202 * V_203 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_213 * V_59 = & V_30 -> V_59 ;
int error ;
error = F_62 ( V_30 ) ;
if ( error ) {
F_9 ( V_33 , L_92 ) ;
return error ;
}
if ( V_203 ) {
error = F_60 ( V_30 , V_203 ) ;
if ( error )
F_25 ( V_33 , L_93 , error ) ;
}
if ( V_30 -> V_238 ) {
error = F_79 ( V_30 ) ;
if ( error )
return error ;
} else {
F_25 ( V_33 , L_94 ) ;
}
F_113 ( V_30 ) ;
F_52 ( V_33 ,
L_95 ,
V_59 -> V_60 , V_59 -> V_219 , V_59 -> V_237 >> 4 ,
V_59 -> V_237 & 0xf , V_59 -> V_404 , V_59 -> V_88 ) ;
return 0 ;
}
static T_7 F_121 ( struct V_38 * V_33 ,
struct V_405 * V_406 , char * V_52 )
{
struct V_29 * V_30 = F_122 ( V_33 ) ;
struct V_213 * V_59 = & V_30 -> V_59 ;
return F_123 ( V_52 , V_407 , L_96 ,
V_59 -> V_237 >> 4 , V_59 -> V_237 & 0xf , V_59 -> V_404 ) ;
}
static T_7 F_124 ( struct V_38 * V_33 ,
struct V_405 * V_406 , char * V_52 )
{
struct V_29 * V_30 = F_122 ( V_33 ) ;
struct V_213 * V_59 = & V_30 -> V_59 ;
return F_123 ( V_52 , V_407 , L_97 ,
V_59 -> V_60 , V_59 -> V_219 ) ;
}
static T_7 F_125 ( char * V_52 , int V_43 ,
struct V_1 * V_86 , int V_208 ,
const T_2 * V_42 )
{
int V_87 ;
if ( F_2 ( V_86 ) > 1 )
V_43 += F_123 ( V_52 + V_43 , V_407 - V_43 ,
L_98 , V_208 ) ;
for ( V_87 = 0 ; V_87 < F_1 ( V_86 ) ; V_87 ++ )
V_43 += F_123 ( V_52 + V_43 , V_407 - V_43 ,
L_99 , V_87 , V_42 [ V_87 ] , V_42 [ V_87 ] ) ;
V_43 += F_123 ( V_52 + V_43 , V_407 - V_43 , L_100 ) ;
return V_43 ;
}
static T_7 F_126 ( struct V_38 * V_33 ,
struct V_405 * V_406 , char * V_52 )
{
struct V_29 * V_30 = F_122 ( V_33 ) ;
struct V_1 * V_86 ;
int V_43 = 0 ;
int V_87 , V_408 ;
int error ;
T_2 * V_409 ;
V_409 = F_20 ( 256 , V_84 ) ;
if ( ! V_409 )
return - V_85 ;
error = 0 ;
for ( V_87 = 0 ; V_87 < V_30 -> V_59 . V_88 ; V_87 ++ ) {
V_86 = V_30 -> V_89 + V_87 ;
if ( ! F_3 ( V_86 -> type ) )
continue;
V_43 += F_123 ( V_52 + V_43 , V_407 - V_43 ,
L_101 , V_86 -> type ) ;
for ( V_408 = 0 ; V_408 < F_2 ( V_86 ) ; V_408 ++ ) {
T_3 V_209 = F_1 ( V_86 ) ;
T_3 V_46 = V_86 -> V_103 + V_408 * V_209 ;
error = F_18 ( V_30 -> V_32 , V_46 , V_209 , V_409 ) ;
if ( error )
goto V_410;
V_43 = F_125 ( V_52 , V_43 , V_86 , V_408 , V_409 ) ;
}
}
V_410:
F_22 ( V_409 ) ;
return error ? : V_43 ;
}
static int F_127 ( struct V_38 * V_33 ,
const struct V_202 * V_411 )
{
unsigned int V_412 = 0 ;
char V_413 ;
while ( V_412 < V_411 -> V_209 ) {
V_413 = * ( V_411 -> V_30 + V_412 ) ;
if ( V_413 < '0' || ( V_413 > '9' && V_413 < 'A' ) || V_413 > 'F' )
return 0 ;
V_412 ++ ;
}
F_9 ( V_33 , L_102 ) ;
return - V_61 ;
}
static int F_128 ( struct V_38 * V_33 , const char * V_414 )
{
struct V_29 * V_30 = F_122 ( V_33 ) ;
const struct V_202 * V_411 = NULL ;
unsigned int V_415 ;
unsigned int V_412 = 0 ;
unsigned int V_56 = 0 ;
unsigned int V_416 = 0 ;
int V_40 ;
V_40 = F_129 ( & V_411 , V_414 , V_33 ) ;
if ( V_40 ) {
F_9 ( V_33 , L_103 , V_414 ) ;
return V_40 ;
}
V_40 = F_127 ( V_33 , V_411 ) ;
if ( V_40 )
goto F_89;
if ( ! V_30 -> V_181 ) {
V_30 -> V_181 = true ;
V_40 = F_47 ( V_30 , V_187 ,
V_417 , false ) ;
if ( V_40 )
goto F_89;
F_48 ( V_418 ) ;
V_40 = F_13 ( V_30 , 0 ) ;
if ( V_40 )
goto F_89;
F_64 ( V_30 ) ;
F_66 ( V_30 ) ;
} else {
F_50 ( V_30 -> V_179 ) ;
}
F_54 ( & V_30 -> V_71 ) ;
V_40 = F_16 ( V_30 , V_73 , false ) ;
if ( V_40 ) {
V_40 = F_16 ( V_30 , V_74 , false ) ;
if ( V_40 )
goto F_53;
} else {
F_52 ( V_33 , L_104 ) ;
V_40 = F_17 ( V_30 , true ) ;
if ( V_40 )
goto F_53;
}
while ( V_412 < V_411 -> V_209 ) {
V_40 = F_16 ( V_30 , V_74 , true ) ;
if ( V_40 )
goto F_53;
V_415 = ( ( * ( V_411 -> V_30 + V_412 ) << 8 ) | * ( V_411 -> V_30 + V_412 + 1 ) ) ;
V_415 += 2 ;
V_40 = F_12 ( V_30 , V_411 -> V_30 + V_412 , V_415 ) ;
if ( V_40 )
goto F_53;
V_40 = F_16 ( V_30 , V_75 , true ) ;
if ( V_40 ) {
V_56 ++ ;
F_48 ( V_56 * 20 ) ;
if ( V_56 > 20 ) {
F_9 ( V_33 , L_105 ) ;
goto F_53;
}
} else {
V_56 = 0 ;
V_412 += V_415 ;
V_416 ++ ;
}
if ( V_416 % 50 == 0 )
F_5 ( V_33 , L_106 ,
V_416 , V_412 , V_411 -> V_209 ) ;
}
V_40 = F_6 ( V_30 , & V_30 -> V_71 ,
V_300 ) ;
if ( V_40 )
goto F_53;
F_5 ( V_33 , L_107 , V_416 , V_412 ) ;
F_6 ( V_30 , & V_30 -> V_71 , V_300 ) ;
V_30 -> V_181 = false ;
F_53:
F_53 ( V_30 -> V_179 ) ;
F_89:
F_89 ( V_411 ) ;
return V_40 ;
}
static T_7 F_130 ( struct V_38 * V_33 ,
struct V_405 * V_406 ,
const char * V_52 , T_1 V_43 )
{
struct V_29 * V_30 = F_122 ( V_33 ) ;
int error ;
error = F_128 ( V_33 , V_419 ) ;
if ( error ) {
F_9 ( V_33 , L_108 , error ) ;
V_43 = error ;
} else {
F_52 ( V_33 , L_109 ) ;
error = F_90 ( V_30 ) ;
if ( error )
return error ;
}
return V_43 ;
}
static void F_131 ( struct V_29 * V_30 )
{
switch ( V_30 -> V_107 -> V_420 ) {
case V_421 :
F_51 ( V_30 ) ;
F_28 ( V_30 ,
V_9 , V_422 , 0x83 ) ;
break;
case V_423 :
default:
F_92 ( V_30 , V_312 ) ;
F_47 ( V_30 , V_424 , 1 , false ) ;
break;
}
}
static void F_132 ( struct V_29 * V_30 )
{
switch ( V_30 -> V_107 -> V_420 ) {
case V_421 :
F_28 ( V_30 ,
V_9 , V_422 , 0 ) ;
break;
case V_423 :
default:
F_92 ( V_30 , V_310 ) ;
break;
}
}
static int V_287 ( struct V_104 * V_33 )
{
struct V_29 * V_30 = F_133 ( V_33 ) ;
F_131 ( V_30 ) ;
return 0 ;
}
static void V_289 ( struct V_104 * V_33 )
{
struct V_29 * V_30 = F_133 ( V_33 ) ;
F_132 ( V_30 ) ;
}
static const struct V_106 * F_134 ( struct V_81 * V_32 )
{
struct V_106 * V_107 ;
struct V_425 * V_426 = V_32 -> V_33 . V_427 ;
T_4 * V_428 ;
int V_429 , V_40 ;
if ( ! V_426 )
return F_135 ( - V_430 ) ;
V_107 = F_136 ( & V_32 -> V_33 , sizeof( * V_107 ) , V_84 ) ;
if ( ! V_107 )
return F_135 ( - V_85 ) ;
if ( F_137 ( V_426 , L_110 , & V_429 ) ) {
V_107 -> V_108 = V_429 / sizeof( T_4 ) ;
V_428 = F_136 ( & V_32 -> V_33 ,
V_107 -> V_108 * sizeof( V_428 [ 0 ] ) ,
V_84 ) ;
if ( ! V_428 )
return F_135 ( - V_85 ) ;
V_40 = F_138 ( V_426 , L_110 ,
V_428 , V_107 -> V_108 ) ;
if ( V_40 )
F_25 ( & V_32 -> V_33 ,
L_111 , V_40 ) ;
V_107 -> V_109 = V_428 ;
}
V_107 -> V_420 = V_423 ;
return V_107 ;
}
static const struct V_106 * F_134 ( struct V_81 * V_32 )
{
return F_135 ( - V_430 ) ;
}
static const struct V_106 * F_139 ( struct V_81 * V_32 )
{
struct V_431 * V_432 ;
const struct V_433 * V_434 ;
const struct V_435 * V_436 ;
if ( V_32 -> V_46 < 0x40 )
return F_135 ( - V_437 ) ;
V_432 = F_140 ( & V_32 -> V_33 ) ;
if ( ! V_432 )
return F_135 ( - V_430 ) ;
V_434 = F_141 ( V_438 ) ;
if ( ! V_434 )
return F_135 ( - V_430 ) ;
V_436 = V_434 -> V_439 ;
if ( ! V_436 )
return F_135 ( - V_430 ) ;
while ( V_436 -> V_440 ) {
if ( ! strcmp ( F_142 ( V_432 ) , V_436 -> V_440 ) )
return & V_436 -> V_107 ;
V_436 ++ ;
}
return F_135 ( - V_430 ) ;
}
static const struct V_106 * F_139 ( struct V_81 * V_32 )
{
return F_135 ( - V_430 ) ;
}
static const struct V_106 *
F_143 ( struct V_81 * V_32 )
{
const struct V_106 * V_107 ;
V_107 = F_144 ( & V_32 -> V_33 ) ;
if ( V_107 )
return V_107 ;
V_107 = F_134 ( V_32 ) ;
if ( ! F_145 ( V_107 ) || F_146 ( V_107 ) != - V_430 )
return V_107 ;
V_107 = F_139 ( V_32 ) ;
if ( ! F_145 ( V_107 ) || F_146 ( V_107 ) != - V_430 )
return V_107 ;
F_9 ( & V_32 -> V_33 , L_112 ) ;
return F_135 ( - V_61 ) ;
}
static int F_147 ( struct V_81 * V_32 , const struct V_441 * V_111 )
{
struct V_29 * V_30 ;
const struct V_106 * V_107 ;
int error ;
V_107 = F_143 ( V_32 ) ;
if ( F_145 ( V_107 ) )
return F_146 ( V_107 ) ;
V_30 = F_61 ( sizeof( struct V_29 ) , V_84 ) ;
if ( ! V_30 ) {
F_9 ( & V_32 -> V_33 , L_57 ) ;
return - V_85 ;
}
snprintf ( V_30 -> V_282 , sizeof( V_30 -> V_282 ) , L_113 ,
V_32 -> V_53 -> V_442 , V_32 -> V_46 ) ;
V_30 -> V_32 = V_32 ;
V_30 -> V_107 = V_107 ;
V_30 -> V_179 = V_32 -> V_179 ;
F_148 ( V_32 , V_30 ) ;
F_149 ( & V_30 -> V_71 ) ;
F_149 ( & V_30 -> V_95 ) ;
F_149 ( & V_30 -> V_92 ) ;
error = F_150 ( V_32 -> V_179 , NULL , F_46 ,
V_107 -> V_443 | V_444 ,
V_32 -> V_273 , V_30 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_114 ) ;
goto V_294;
}
F_53 ( V_32 -> V_179 ) ;
error = F_90 ( V_30 ) ;
if ( error )
goto V_445;
error = F_151 ( & V_32 -> V_33 . V_446 , & V_447 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_115 ,
error ) ;
goto V_448;
}
return 0 ;
V_448:
F_64 ( V_30 ) ;
F_66 ( V_30 ) ;
V_445:
F_152 ( V_32 -> V_179 , V_30 ) ;
V_294:
F_22 ( V_30 ) ;
return error ;
}
static int F_153 ( struct V_81 * V_32 )
{
struct V_29 * V_30 = F_154 ( V_32 ) ;
F_155 ( & V_32 -> V_33 . V_446 , & V_447 ) ;
F_152 ( V_30 -> V_179 , V_30 ) ;
F_64 ( V_30 ) ;
F_66 ( V_30 ) ;
F_22 ( V_30 ) ;
return 0 ;
}
static int T_8 F_156 ( struct V_38 * V_33 )
{
struct V_81 * V_32 = F_157 ( V_33 ) ;
struct V_29 * V_30 = F_154 ( V_32 ) ;
struct V_104 * V_104 = V_30 -> V_104 ;
if ( ! V_104 )
return 0 ;
F_158 ( & V_104 -> V_449 ) ;
if ( V_104 -> V_450 )
F_132 ( V_30 ) ;
F_159 ( & V_104 -> V_449 ) ;
return 0 ;
}
static int T_8 F_160 ( struct V_38 * V_33 )
{
struct V_81 * V_32 = F_157 ( V_33 ) ;
struct V_29 * V_30 = F_154 ( V_32 ) ;
struct V_104 * V_104 = V_30 -> V_104 ;
if ( ! V_104 )
return 0 ;
F_158 ( & V_104 -> V_449 ) ;
if ( V_104 -> V_450 )
F_131 ( V_30 ) ;
F_159 ( & V_104 -> V_449 ) ;
return 0 ;
}
