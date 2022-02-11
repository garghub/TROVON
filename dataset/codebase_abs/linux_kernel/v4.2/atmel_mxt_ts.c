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
if ( V_43 == 0 ) {
F_5 ( V_33 , L_32 ) ;
return V_168 ;
} else if ( V_43 > V_30 -> V_163 ) {
F_9 ( V_33 , L_33 , V_43 ) ;
V_43 = V_30 -> V_163 ;
}
V_40 = F_41 ( V_30 , V_30 -> V_165 + 1 ) ;
if ( V_40 < 0 ) {
F_25 ( V_33 , L_34 ) ;
return V_168 ;
}
V_166 = V_43 - 1 ;
if ( V_166 ) {
V_40 = F_42 ( V_30 , V_166 ) ;
if ( V_40 < 0 )
goto V_169;
else if ( V_40 != V_166 )
F_25 ( V_33 , L_34 ) ;
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
F_9 ( V_33 , L_35 ) ;
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
F_9 ( & V_30 -> V_32 -> V_33 , L_36 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_49 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_40 = 0 ;
F_50 ( V_33 , L_37 ) ;
F_51 ( & V_30 -> V_95 ) ;
V_40 = F_47 ( V_30 , V_187 , V_188 , false ) ;
if ( V_40 )
return V_40 ;
V_40 = F_6 ( V_30 , & V_30 -> V_95 ,
V_189 ) ;
if ( V_40 )
return V_40 ;
return 0 ;
}
static void F_52 ( struct V_29 * V_30 , T_2 V_190 , T_2 V_183 )
{
V_30 -> V_93 = 0 ;
F_51 ( & V_30 -> V_92 ) ;
F_47 ( V_30 , V_190 , V_183 , true ) ;
F_6 ( V_30 , & V_30 -> V_92 , V_191 ) ;
}
static void F_53 ( T_4 * V_91 , T_2 V_192 , T_2 V_193 )
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
static T_4 F_54 ( T_2 * V_197 , T_6 V_198 , T_6 V_199 )
{
T_4 V_91 = 0 ;
T_2 * V_200 = V_197 + V_198 ;
T_2 * V_201 = V_197 + V_199 - 1 ;
if ( V_199 < V_198 )
return - V_61 ;
while ( V_200 < V_201 ) {
F_53 ( & V_91 , * V_200 , * ( V_200 + 1 ) ) ;
V_200 += 2 ;
}
if ( V_200 == V_201 )
F_53 ( & V_91 , * V_200 , 0 ) ;
V_91 &= 0x00FFFFFF ;
return V_91 ;
}
static int F_55 ( struct V_29 * V_30 ,
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
V_40 = sscanf ( V_203 -> V_30 + V_204 , L_38 ,
& type , & V_208 , & V_209 , & V_102 ) ;
if ( V_40 == 0 ) {
break;
} else if ( V_40 != 3 ) {
F_9 ( V_33 , L_39 ) ;
return - V_61 ;
}
V_204 += V_102 ;
V_86 = F_24 ( V_30 , type ) ;
if ( ! V_86 ) {
for ( V_87 = 0 ; V_87 < V_209 ; V_87 ++ ) {
V_40 = sscanf ( V_203 -> V_30 + V_204 , L_40 ,
& V_42 , & V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_41 ,
type , V_87 ) ;
return - V_61 ;
}
V_204 += V_102 ;
}
continue;
}
if ( V_209 > F_1 ( V_86 ) ) {
F_25 ( V_33 , L_42 ,
V_209 - F_1 ( V_86 ) , type ) ;
} else if ( F_1 ( V_86 ) > V_209 ) {
F_25 ( V_33 , L_43 ,
F_1 ( V_86 ) - V_209 , type ) ;
}
if ( V_208 >= F_2 ( V_86 ) ) {
F_9 ( V_33 , L_44 ) ;
return - V_61 ;
}
V_82 = V_86 -> V_103 + F_1 ( V_86 ) * V_208 ;
for ( V_87 = 0 ; V_87 < V_209 ; V_87 ++ ) {
V_40 = sscanf ( V_203 -> V_30 + V_204 , L_40 ,
& V_42 ,
& V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_41 ,
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
F_9 ( V_33 , L_45 ,
V_82 , V_86 -> type , V_210 ) ;
return - V_61 ;
}
}
}
return 0 ;
}
static int F_56 ( struct V_29 * V_30 , unsigned int V_211 ,
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
L_46 , error ) ;
return error ;
}
V_210 += V_209 ;
}
return 0 ;
}
static int F_57 ( struct V_29 * V_30 , const struct V_202 * V_203 )
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
F_52 ( V_30 , V_217 , 1 ) ;
if ( strncmp ( V_203 -> V_30 , V_218 , strlen ( V_218 ) ) ) {
F_9 ( V_33 , L_47 ) ;
return - V_61 ;
}
V_204 = strlen ( V_218 ) ;
for ( V_87 = 0 ; V_87 < sizeof( struct V_213 ) ; V_87 ++ ) {
V_40 = sscanf ( V_203 -> V_30 + V_204 , L_40 ,
( unsigned char * ) & V_214 + V_87 ,
& V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_48 ) ;
return - V_61 ;
}
V_204 += V_102 ;
}
if ( V_214 . V_60 != V_30 -> V_59 . V_60 ) {
F_9 ( V_33 , L_49 ) ;
return - V_61 ;
}
if ( V_214 . V_219 != V_30 -> V_59 . V_219 ) {
F_9 ( V_33 , L_50 ) ;
return - V_61 ;
}
V_40 = sscanf ( V_203 -> V_30 + V_204 , L_51 , & V_215 , & V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_52 ) ;
return - V_61 ;
}
V_204 += V_102 ;
V_40 = sscanf ( V_203 -> V_30 + V_204 , L_51 , & V_93 , & V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_53 ) ;
return - V_61 ;
}
V_204 += V_102 ;
if ( V_215 == V_30 -> V_215 ) {
if ( V_93 == 0 || V_30 -> V_93 == 0 ) {
F_50 ( V_33 , L_54 ) ;
} else if ( V_93 == V_30 -> V_93 ) {
F_5 ( V_33 , L_55 ,
V_30 -> V_93 ) ;
return 0 ;
} else {
F_50 ( V_33 , L_56 ,
V_30 -> V_93 , V_93 ) ;
}
} else {
F_25 ( V_33 ,
L_57 ,
V_30 -> V_215 , V_215 ) ;
}
V_205 = V_220 +
V_30 -> V_59 . V_88 * sizeof( struct V_1 ) +
V_221 ;
V_207 = V_30 -> V_222 - V_205 ;
V_206 = F_58 ( V_207 , V_84 ) ;
if ( ! V_206 ) {
F_9 ( V_33 , L_58 ) ;
return - V_85 ;
}
V_40 = F_55 ( V_30 , V_203 , V_204 , V_205 ,
V_206 , V_207 ) ;
if ( V_40 )
goto V_223;
if ( V_30 -> V_224 < V_205 ) {
F_9 ( V_33 , L_59 ,
V_30 -> V_224 , V_205 ) ;
V_40 = 0 ;
goto V_223;
}
V_216 = F_54 ( V_206 ,
V_30 -> V_224 - V_205 ,
V_207 ) ;
if ( V_93 > 0 && V_93 != V_216 )
F_25 ( V_33 , L_60 ,
V_216 , V_93 ) ;
V_40 = F_56 ( V_30 , V_205 ,
V_206 , V_207 ) ;
if ( V_40 )
goto V_223;
F_52 ( V_30 , V_225 , V_226 ) ;
V_40 = F_49 ( V_30 ) ;
if ( V_40 )
goto V_223;
F_50 ( V_33 , L_61 ) ;
V_223:
F_22 ( V_206 ) ;
return V_40 ;
}
static int F_59 ( struct V_29 * V_30 )
{
int error ;
F_60 ( V_30 -> V_179 ) ;
error = F_44 ( V_30 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_61 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
struct V_213 * V_59 = & V_30 -> V_59 ;
int error ;
error = F_18 ( V_32 , V_227 , sizeof( * V_59 ) , V_59 ) ;
if ( error )
return error ;
return 0 ;
}
static void F_62 ( struct V_29 * V_30 )
{
if ( V_30 -> V_104 ) {
F_63 ( V_30 -> V_104 ) ;
V_30 -> V_104 = NULL ;
}
}
static void F_64 ( struct V_29 * V_30 )
{
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
static int F_65 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
T_1 V_228 ;
struct V_1 * V_89 ;
int error ;
int V_87 ;
T_2 V_229 ;
T_3 V_230 ;
V_228 = V_30 -> V_59 . V_88 * sizeof( struct V_1 ) ;
V_89 = F_58 ( V_228 , V_84 ) ;
if ( ! V_89 ) {
F_9 ( & V_30 -> V_32 -> V_33 , L_58 ) ;
return - V_85 ;
}
error = F_18 ( V_32 , V_220 , V_228 ,
V_89 ) ;
if ( error ) {
F_22 ( V_89 ) ;
return error ;
}
V_229 = 1 ;
V_30 -> V_222 = 0 ;
for ( V_87 = 0 ; V_87 < V_30 -> V_59 . V_88 ; V_87 ++ ) {
struct V_1 * V_86 = V_89 + V_87 ;
T_2 V_231 , V_232 ;
F_66 ( & V_86 -> V_103 ) ;
if ( V_86 -> V_233 ) {
V_231 = V_229 ;
V_229 += V_86 -> V_233 *
F_2 ( V_86 ) ;
V_232 = V_229 - 1 ;
} else {
V_231 = 0 ;
V_232 = 0 ;
}
F_5 ( & V_30 -> V_32 -> V_33 ,
L_62 ,
V_86 -> type , V_86 -> V_103 ,
F_1 ( V_86 ) , F_2 ( V_86 ) ,
V_231 , V_232 ) ;
switch ( V_86 -> type ) {
case V_234 :
if ( V_30 -> V_59 . V_60 == 0x80 &&
V_30 -> V_59 . V_235 < 0x20 ) {
V_30 -> V_34 = F_1 ( V_86 ) ;
} else {
V_30 -> V_34 = F_1 ( V_86 ) - 1 ;
}
V_30 -> V_164 = V_86 -> V_103 ;
break;
case V_5 :
V_30 -> V_158 = V_231 ;
V_30 -> V_186 = V_86 -> V_103 ;
break;
case V_6 :
V_30 -> V_224 = V_86 -> V_103 ;
break;
case V_9 :
V_30 -> V_236 = V_9 ;
V_30 -> V_116 = V_231 ;
V_30 -> V_159 = V_232 ;
V_30 -> V_178 = V_86 -> V_233
* F_2 ( V_86 ) ;
break;
case V_237 :
V_30 -> V_167 = V_86 -> V_103 ;
break;
case V_23 :
V_30 -> V_161 = V_231 ;
break;
case V_238 :
V_30 -> V_236 = V_238 ;
V_30 -> V_138 = V_231 ;
V_30 -> V_160 = V_232 ;
V_30 -> V_178 = V_86 -> V_233 - 2 ;
break;
}
V_230 = V_86 -> V_103
+ F_1 ( V_86 ) * F_2 ( V_86 ) - 1 ;
if ( V_230 >= V_30 -> V_222 )
V_30 -> V_222 = V_230 + 1 ;
}
V_30 -> V_163 = V_229 ;
if ( V_30 -> V_167 && ( V_30 -> V_164 != V_30 -> V_167 + 1 ) ) {
F_9 ( & V_32 -> V_33 , L_63 ) ;
error = - V_61 ;
goto V_239;
}
V_30 -> V_165 = F_67 ( V_30 -> V_163 ,
V_30 -> V_34 , V_84 ) ;
if ( ! V_30 -> V_165 ) {
F_9 ( & V_32 -> V_33 , L_64 ) ;
error = - V_85 ;
goto V_239;
}
V_30 -> V_89 = V_89 ;
return 0 ;
V_239:
F_64 ( V_30 ) ;
return error ;
}
static int F_68 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
int error ;
struct V_240 V_241 ;
unsigned char V_242 ;
struct V_1 * V_86 ;
V_86 = F_24 ( V_30 , V_9 ) ;
if ( ! V_86 )
return - V_61 ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_243 ,
sizeof( V_241 ) , & V_241 ) ;
if ( error )
return error ;
F_66 ( & V_241 . V_112 ) ;
F_66 ( & V_241 . V_113 ) ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_244 ,
1 , & V_242 ) ;
if ( error )
return error ;
if ( V_241 . V_112 == 0 )
V_241 . V_112 = 1023 ;
if ( V_241 . V_113 == 0 )
V_241 . V_113 = 1023 ;
if ( V_242 & V_245 ) {
V_30 -> V_117 = V_241 . V_113 ;
V_30 -> V_118 = V_241 . V_112 ;
} else {
V_30 -> V_117 = V_241 . V_112 ;
V_30 -> V_118 = V_241 . V_113 ;
}
F_5 ( & V_32 -> V_33 ,
L_65 , V_30 -> V_117 , V_30 -> V_118 ) ;
return 0 ;
}
static int F_69 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
int error ;
struct V_1 * V_86 ;
T_3 V_246 , V_247 ;
T_2 V_203 , V_248 ;
T_2 V_249 ;
V_86 = F_24 ( V_30 , V_238 ) ;
if ( ! V_86 )
return - V_61 ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_250 ,
sizeof( V_246 ) , & V_246 ) ;
if ( error )
return error ;
F_66 ( & V_246 ) ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_251 ,
sizeof( V_247 ) , & V_247 ) ;
if ( error )
return error ;
F_66 ( & V_247 ) ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_252 ,
1 , & V_203 ) ;
if ( error )
return error ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_253 ,
1 , & V_248 ) ;
if ( error )
return error ;
if ( V_246 == 0 )
V_246 = 1023 ;
if ( V_247 == 0 )
V_247 = 1023 ;
if ( V_203 & V_254 ) {
V_30 -> V_117 = V_247 ;
V_30 -> V_118 = V_246 ;
} else {
V_30 -> V_117 = V_246 ;
V_30 -> V_118 = V_247 ;
}
V_249 = 6 ;
if ( V_248 & V_255 )
V_30 -> V_143 = V_249 ++ ;
if ( V_248 & V_256 )
V_30 -> V_148 = V_249 ++ ;
if ( V_248 & V_257 )
V_30 -> V_147 = V_249 ++ ;
F_5 ( & V_32 -> V_33 ,
L_66 ,
V_30 -> V_143 , V_30 -> V_148 , V_30 -> V_147 ) ;
F_50 ( & V_32 -> V_33 ,
L_67 , V_30 -> V_117 , V_30 -> V_118 ) ;
return 0 ;
}
static void F_70 ( struct V_104 * V_104 ,
struct V_29 * V_30 )
{
const struct V_106 * V_107 = V_30 -> V_107 ;
int V_87 ;
V_104 -> V_258 = L_68 ;
F_71 ( V_259 , V_104 -> V_260 ) ;
F_72 ( V_104 , V_261 , V_262 ) ;
F_72 ( V_104 , V_263 , V_262 ) ;
F_72 ( V_104 , V_128 ,
V_262 ) ;
F_72 ( V_104 , V_129 ,
V_262 ) ;
for ( V_87 = 0 ; V_87 < V_107 -> V_108 ; V_87 ++ )
if ( V_107 -> V_109 [ V_87 ] != V_110 )
F_73 ( V_104 , V_264 ,
V_107 -> V_109 [ V_87 ] ) ;
}
static int F_74 ( struct V_29 * V_30 )
{
const struct V_106 * V_107 = V_30 -> V_107 ;
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_104 * V_104 ;
int error ;
unsigned int V_265 ;
unsigned int V_266 = 0 ;
switch ( V_30 -> V_236 ) {
case V_9 :
V_265 = V_30 -> V_159 - V_30 -> V_116 + 1 ;
error = F_68 ( V_30 ) ;
if ( error )
F_25 ( V_33 , L_69 ) ;
break;
case V_238 :
V_265 = V_30 -> V_178 ;
error = F_69 ( V_30 ) ;
if ( error )
F_25 ( V_33 , L_70 ) ;
break;
default:
F_9 ( V_33 , L_71 ) ;
return - V_61 ;
}
V_104 = F_75 () ;
if ( ! V_104 ) {
F_9 ( V_33 , L_58 ) ;
return - V_85 ;
}
V_104 -> V_258 = L_72 ;
V_104 -> V_267 = V_30 -> V_267 ;
V_104 -> V_111 . V_268 = V_269 ;
V_104 -> V_33 . V_270 = V_33 ;
V_104 -> V_271 = V_272 ;
V_104 -> V_273 = V_274 ;
F_73 ( V_104 , V_264 , V_275 ) ;
F_76 ( V_104 , V_261 , 0 , V_30 -> V_117 , 0 , 0 ) ;
F_76 ( V_104 , V_263 , 0 , V_30 -> V_118 , 0 , 0 ) ;
if ( V_30 -> V_236 == V_9 ||
( V_30 -> V_236 == V_238 &&
V_30 -> V_148 ) ) {
F_76 ( V_104 , V_276 , 0 , 255 , 0 , 0 ) ;
}
if ( V_107 -> V_108 ) {
F_70 ( V_104 , V_30 ) ;
V_266 |= V_277 ;
}
error = F_77 ( V_104 , V_265 , V_266 ) ;
if ( error ) {
F_9 ( V_33 , L_73 , error ) ;
goto V_278;
}
if ( V_30 -> V_236 == V_238 ) {
F_76 ( V_104 , V_279 ,
0 , V_280 , 0 , 0 ) ;
F_76 ( V_104 , V_154 ,
V_146 ,
V_142 ,
0 , 0 ) ;
}
F_76 ( V_104 , V_128 ,
0 , V_30 -> V_117 , 0 , 0 ) ;
F_76 ( V_104 , V_129 ,
0 , V_30 -> V_118 , 0 , 0 ) ;
if ( V_30 -> V_236 == V_9 ||
( V_30 -> V_236 == V_238 &&
V_30 -> V_147 ) ) {
F_76 ( V_104 , V_131 ,
0 , V_281 , 0 , 0 ) ;
}
if ( V_30 -> V_236 == V_9 ||
( V_30 -> V_236 == V_238 &&
V_30 -> V_148 ) ) {
F_76 ( V_104 , V_130 ,
0 , 255 , 0 , 0 ) ;
}
if ( V_30 -> V_236 == V_238 &&
V_30 -> V_143 ) {
F_76 ( V_104 , V_155 ,
0 , 255 , 0 , 0 ) ;
}
if ( V_30 -> V_236 == V_238 &&
V_30 -> V_148 ) {
F_76 ( V_104 , V_130 ,
0 , 255 , 0 , 0 ) ;
}
if ( V_30 -> V_236 == V_238 &&
V_30 -> V_143 ) {
F_76 ( V_104 , V_155 ,
0 , 255 , 0 , 0 ) ;
}
F_78 ( V_104 , V_30 ) ;
error = F_79 ( V_104 ) ;
if ( error ) {
F_9 ( V_33 , L_74 , error ) ;
goto V_278;
}
V_30 -> V_104 = V_104 ;
return 0 ;
V_278:
F_80 ( V_104 ) ;
return error ;
}
static void F_81 ( const struct V_202 * V_203 , void * V_282 )
{
F_82 ( V_282 , V_203 ) ;
F_83 ( V_203 ) ;
}
static int F_84 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
int V_283 = 0 ;
int error ;
while ( 1 ) {
error = F_61 ( V_30 ) ;
if ( ! error )
break;
error = F_14 ( V_30 , false ) ;
if ( error ) {
F_50 ( & V_32 -> V_33 , L_75 ) ;
error = F_14 ( V_30 , true ) ;
if ( error ) {
return error ;
}
}
if ( ++ V_283 > 1 ) {
F_9 ( & V_32 -> V_33 , L_76 ) ;
V_30 -> V_181 = true ;
return 0 ;
}
F_17 ( V_30 , false ) ;
F_48 ( V_284 ) ;
}
error = F_65 ( V_30 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_77 , error ) ;
return error ;
}
error = F_59 ( V_30 ) ;
if ( error )
goto V_285;
error = F_85 ( V_286 , true , V_287 ,
& V_32 -> V_33 , V_84 , V_30 ,
F_81 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_78 ,
error ) ;
goto V_285;
}
return 0 ;
V_285:
F_64 ( V_30 ) ;
return error ;
}
static int F_82 ( struct V_29 * V_30 ,
const struct V_202 * V_203 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_213 * V_59 = & V_30 -> V_59 ;
int error ;
if ( V_203 ) {
error = F_57 ( V_30 , V_203 ) ;
if ( error )
F_25 ( V_33 , L_79 , error ) ;
}
if ( V_30 -> V_236 ) {
error = F_74 ( V_30 ) ;
if ( error )
return error ;
} else {
F_25 ( V_33 , L_80 ) ;
}
F_50 ( V_33 ,
L_81 ,
V_59 -> V_60 , V_59 -> V_219 , V_59 -> V_235 >> 4 ,
V_59 -> V_235 & 0xf , V_59 -> V_288 , V_59 -> V_88 ) ;
return 0 ;
}
static T_7 F_86 ( struct V_38 * V_33 ,
struct V_289 * V_290 , char * V_52 )
{
struct V_29 * V_30 = F_87 ( V_33 ) ;
struct V_213 * V_59 = & V_30 -> V_59 ;
return F_88 ( V_52 , V_291 , L_82 ,
V_59 -> V_235 >> 4 , V_59 -> V_235 & 0xf , V_59 -> V_288 ) ;
}
static T_7 F_89 ( struct V_38 * V_33 ,
struct V_289 * V_290 , char * V_52 )
{
struct V_29 * V_30 = F_87 ( V_33 ) ;
struct V_213 * V_59 = & V_30 -> V_59 ;
return F_88 ( V_52 , V_291 , L_83 ,
V_59 -> V_60 , V_59 -> V_219 ) ;
}
static T_7 F_90 ( char * V_52 , int V_43 ,
struct V_1 * V_86 , int V_208 ,
const T_2 * V_42 )
{
int V_87 ;
if ( F_2 ( V_86 ) > 1 )
V_43 += F_88 ( V_52 + V_43 , V_291 - V_43 ,
L_84 , V_208 ) ;
for ( V_87 = 0 ; V_87 < F_1 ( V_86 ) ; V_87 ++ )
V_43 += F_88 ( V_52 + V_43 , V_291 - V_43 ,
L_85 , V_87 , V_42 [ V_87 ] , V_42 [ V_87 ] ) ;
V_43 += F_88 ( V_52 + V_43 , V_291 - V_43 , L_86 ) ;
return V_43 ;
}
static T_7 F_91 ( struct V_38 * V_33 ,
struct V_289 * V_290 , char * V_52 )
{
struct V_29 * V_30 = F_87 ( V_33 ) ;
struct V_1 * V_86 ;
int V_43 = 0 ;
int V_87 , V_292 ;
int error ;
T_2 * V_293 ;
V_293 = F_20 ( 256 , V_84 ) ;
if ( ! V_293 )
return - V_85 ;
error = 0 ;
for ( V_87 = 0 ; V_87 < V_30 -> V_59 . V_88 ; V_87 ++ ) {
V_86 = V_30 -> V_89 + V_87 ;
if ( ! F_3 ( V_86 -> type ) )
continue;
V_43 += F_88 ( V_52 + V_43 , V_291 - V_43 ,
L_87 , V_86 -> type ) ;
for ( V_292 = 0 ; V_292 < F_2 ( V_86 ) ; V_292 ++ ) {
T_3 V_209 = F_1 ( V_86 ) ;
T_3 V_46 = V_86 -> V_103 + V_292 * V_209 ;
error = F_18 ( V_30 -> V_32 , V_46 , V_209 , V_293 ) ;
if ( error )
goto V_294;
V_43 = F_90 ( V_52 , V_43 , V_86 , V_292 , V_293 ) ;
}
}
V_294:
F_22 ( V_293 ) ;
return error ? : V_43 ;
}
static int F_92 ( struct V_38 * V_33 ,
const struct V_202 * V_295 )
{
unsigned int V_296 = 0 ;
char V_297 ;
while ( V_296 < V_295 -> V_209 ) {
V_297 = * ( V_295 -> V_30 + V_296 ) ;
if ( V_297 < '0' || ( V_297 > '9' && V_297 < 'A' ) || V_297 > 'F' )
return 0 ;
V_296 ++ ;
}
F_9 ( V_33 , L_88 ) ;
return - V_61 ;
}
static int F_93 ( struct V_38 * V_33 , const char * V_298 )
{
struct V_29 * V_30 = F_87 ( V_33 ) ;
const struct V_202 * V_295 = NULL ;
unsigned int V_299 ;
unsigned int V_296 = 0 ;
unsigned int V_56 = 0 ;
unsigned int V_300 = 0 ;
int V_40 ;
V_40 = F_94 ( & V_295 , V_298 , V_33 ) ;
if ( V_40 ) {
F_9 ( V_33 , L_89 , V_298 ) ;
return V_40 ;
}
V_40 = F_92 ( V_33 , V_295 ) ;
if ( V_40 )
goto F_83;
if ( ! V_30 -> V_181 ) {
V_30 -> V_181 = true ;
V_40 = F_47 ( V_30 , V_187 ,
V_301 , false ) ;
if ( V_40 )
goto F_83;
F_48 ( V_302 ) ;
V_40 = F_13 ( V_30 , 0 ) ;
if ( V_40 )
goto F_83;
F_62 ( V_30 ) ;
F_64 ( V_30 ) ;
} else {
F_60 ( V_30 -> V_179 ) ;
}
F_51 ( & V_30 -> V_71 ) ;
V_40 = F_16 ( V_30 , V_73 , false ) ;
if ( V_40 ) {
V_40 = F_16 ( V_30 , V_74 , false ) ;
if ( V_40 )
goto V_303;
} else {
F_50 ( V_33 , L_90 ) ;
V_40 = F_17 ( V_30 , true ) ;
if ( V_40 )
goto V_303;
}
while ( V_296 < V_295 -> V_209 ) {
V_40 = F_16 ( V_30 , V_74 , true ) ;
if ( V_40 )
goto V_303;
V_299 = ( ( * ( V_295 -> V_30 + V_296 ) << 8 ) | * ( V_295 -> V_30 + V_296 + 1 ) ) ;
V_299 += 2 ;
V_40 = F_12 ( V_30 , V_295 -> V_30 + V_296 , V_299 ) ;
if ( V_40 )
goto V_303;
V_40 = F_16 ( V_30 , V_75 , true ) ;
if ( V_40 ) {
V_56 ++ ;
F_48 ( V_56 * 20 ) ;
if ( V_56 > 20 ) {
F_9 ( V_33 , L_91 ) ;
goto V_303;
}
} else {
V_56 = 0 ;
V_296 += V_299 ;
V_300 ++ ;
}
if ( V_300 % 50 == 0 )
F_5 ( V_33 , L_92 ,
V_300 , V_296 , V_295 -> V_209 ) ;
}
V_40 = F_6 ( V_30 , & V_30 -> V_71 ,
V_284 ) ;
if ( V_40 )
goto V_303;
F_5 ( V_33 , L_93 , V_300 , V_296 ) ;
F_6 ( V_30 , & V_30 -> V_71 , V_284 ) ;
V_30 -> V_181 = false ;
V_303:
V_303 ( V_30 -> V_179 ) ;
F_83:
F_83 ( V_295 ) ;
return V_40 ;
}
static T_7 F_95 ( struct V_38 * V_33 ,
struct V_289 * V_290 ,
const char * V_52 , T_1 V_43 )
{
struct V_29 * V_30 = F_87 ( V_33 ) ;
int error ;
error = F_93 ( V_33 , V_304 ) ;
if ( error ) {
F_9 ( V_33 , L_94 , error ) ;
V_43 = error ;
} else {
F_50 ( V_33 , L_95 ) ;
error = F_84 ( V_30 ) ;
if ( error )
return error ;
}
return V_43 ;
}
static void F_96 ( struct V_29 * V_30 )
{
F_28 ( V_30 , V_30 -> V_236 , V_305 , 0x83 ) ;
}
static void F_97 ( struct V_29 * V_30 )
{
F_28 ( V_30 , V_30 -> V_236 , V_305 , 0 ) ;
}
static int V_272 ( struct V_104 * V_33 )
{
struct V_29 * V_30 = F_98 ( V_33 ) ;
F_96 ( V_30 ) ;
return 0 ;
}
static void V_274 ( struct V_104 * V_33 )
{
struct V_29 * V_30 = F_98 ( V_33 ) ;
F_97 ( V_30 ) ;
}
static const struct V_106 * F_99 ( struct V_81 * V_32 )
{
struct V_106 * V_107 ;
T_4 * V_306 ;
T_4 V_307 ;
int V_308 , V_87 , V_40 ;
if ( ! V_32 -> V_33 . V_309 )
return F_100 ( - V_310 ) ;
V_107 = F_101 ( & V_32 -> V_33 , sizeof( * V_107 ) , V_84 ) ;
if ( ! V_107 )
return F_100 ( - V_85 ) ;
if ( F_102 ( V_32 -> V_33 . V_309 , L_96 ,
& V_308 ) ) {
V_107 -> V_108 = V_308 / sizeof( T_4 ) ;
V_306 = F_101 ( & V_32 -> V_33 ,
V_107 -> V_108 * sizeof( V_306 [ 0 ] ) ,
V_84 ) ;
if ( ! V_306 )
return F_100 ( - V_85 ) ;
for ( V_87 = 0 ; V_87 < V_107 -> V_108 ; V_87 ++ ) {
V_40 = F_103 ( V_32 -> V_33 . V_309 ,
L_96 , V_87 , & V_307 ) ;
if ( V_40 )
V_307 = V_110 ;
V_306 [ V_87 ] = V_307 ;
}
V_107 -> V_109 = V_306 ;
}
return V_107 ;
}
static const struct V_106 * F_99 ( struct V_81 * V_32 )
{
return F_100 ( - V_310 ) ;
}
static const struct V_106 * F_104 ( struct V_81 * V_32 )
{
struct V_311 * V_312 ;
const struct V_313 * V_314 ;
const struct V_315 * V_316 ;
if ( V_32 -> V_46 < 0x40 )
return F_100 ( - V_317 ) ;
V_312 = F_105 ( & V_32 -> V_33 ) ;
if ( ! V_312 )
return F_100 ( - V_310 ) ;
V_314 = F_106 ( V_318 ) ;
if ( ! V_314 )
return F_100 ( - V_310 ) ;
V_316 = V_314 -> V_319 ;
if ( ! V_316 )
return F_100 ( - V_310 ) ;
while ( V_316 -> V_320 ) {
if ( ! strcmp ( F_107 ( V_312 ) , V_316 -> V_320 ) )
return & V_316 -> V_107 ;
V_316 ++ ;
}
return F_100 ( - V_310 ) ;
}
static const struct V_106 * F_104 ( struct V_81 * V_32 )
{
return F_100 ( - V_310 ) ;
}
static const struct V_106 *
F_108 ( struct V_81 * V_32 )
{
const struct V_106 * V_107 ;
V_107 = F_109 ( & V_32 -> V_33 ) ;
if ( V_107 )
return V_107 ;
V_107 = F_99 ( V_32 ) ;
if ( ! F_110 ( V_107 ) || F_111 ( V_107 ) != - V_310 )
return V_107 ;
V_107 = F_104 ( V_32 ) ;
if ( ! F_110 ( V_107 ) || F_111 ( V_107 ) != - V_310 )
return V_107 ;
F_9 ( & V_32 -> V_33 , L_97 ) ;
return F_100 ( - V_61 ) ;
}
static int F_112 ( struct V_81 * V_32 , const struct V_321 * V_111 )
{
struct V_29 * V_30 ;
const struct V_106 * V_107 ;
int error ;
V_107 = F_108 ( V_32 ) ;
if ( F_110 ( V_107 ) )
return F_111 ( V_107 ) ;
V_30 = F_58 ( sizeof( struct V_29 ) , V_84 ) ;
if ( ! V_30 ) {
F_9 ( & V_32 -> V_33 , L_58 ) ;
return - V_85 ;
}
snprintf ( V_30 -> V_267 , sizeof( V_30 -> V_267 ) , L_98 ,
V_32 -> V_53 -> V_322 , V_32 -> V_46 ) ;
V_30 -> V_32 = V_32 ;
V_30 -> V_107 = V_107 ;
V_30 -> V_179 = V_32 -> V_179 ;
F_113 ( V_32 , V_30 ) ;
F_114 ( & V_30 -> V_71 ) ;
F_114 ( & V_30 -> V_95 ) ;
F_114 ( & V_30 -> V_92 ) ;
error = F_115 ( V_32 -> V_179 , NULL , F_46 ,
V_107 -> V_323 | V_324 ,
V_32 -> V_258 , V_30 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_99 ) ;
goto V_278;
}
V_303 ( V_32 -> V_179 ) ;
error = F_84 ( V_30 ) ;
if ( error )
goto V_325;
error = F_116 ( & V_32 -> V_33 . V_326 , & V_327 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_100 ,
error ) ;
goto V_328;
}
return 0 ;
V_328:
F_62 ( V_30 ) ;
F_64 ( V_30 ) ;
V_325:
F_117 ( V_32 -> V_179 , V_30 ) ;
V_278:
F_22 ( V_30 ) ;
return error ;
}
static int F_118 ( struct V_81 * V_32 )
{
struct V_29 * V_30 = F_119 ( V_32 ) ;
F_120 ( & V_32 -> V_33 . V_326 , & V_327 ) ;
F_117 ( V_30 -> V_179 , V_30 ) ;
F_62 ( V_30 ) ;
F_64 ( V_30 ) ;
F_22 ( V_30 ) ;
return 0 ;
}
static int T_8 F_121 ( struct V_38 * V_33 )
{
struct V_81 * V_32 = F_122 ( V_33 ) ;
struct V_29 * V_30 = F_119 ( V_32 ) ;
struct V_104 * V_104 = V_30 -> V_104 ;
F_123 ( & V_104 -> V_329 ) ;
if ( V_104 -> V_330 )
F_97 ( V_30 ) ;
F_124 ( & V_104 -> V_329 ) ;
return 0 ;
}
static int T_8 F_125 ( struct V_38 * V_33 )
{
struct V_81 * V_32 = F_122 ( V_33 ) ;
struct V_29 * V_30 = F_119 ( V_32 ) ;
struct V_104 * V_104 = V_30 -> V_104 ;
F_49 ( V_30 ) ;
F_123 ( & V_104 -> V_329 ) ;
if ( V_104 -> V_330 )
F_96 ( V_30 ) ;
F_124 ( & V_104 -> V_329 ) ;
return 0 ;
}
