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
case V_29 :
return true ;
default:
return false ;
}
}
static void F_4 ( struct V_30 * V_31 , T_2 * V_32 )
{
F_5 ( & V_31 -> V_33 -> V_34 , L_1 ,
V_31 -> V_35 , V_32 ) ;
}
static int F_6 ( struct V_30 * V_31 ,
struct V_36 * V_37 ,
unsigned int V_38 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
unsigned long V_40 = F_7 ( V_38 ) ;
long V_41 ;
V_41 = F_8 ( V_37 , V_40 ) ;
if ( V_41 < 0 ) {
return V_41 ;
} else if ( V_41 == 0 ) {
F_9 ( V_34 , L_2 ) ;
return - V_42 ;
}
return 0 ;
}
static int F_10 ( struct V_30 * V_31 ,
T_2 * V_43 , unsigned int V_44 )
{
int V_41 ;
struct V_45 V_46 ;
V_46 . V_47 = V_31 -> V_48 ;
V_46 . V_49 = V_31 -> V_33 -> V_49 & V_50 ;
V_46 . V_49 |= V_51 ;
V_46 . V_52 = V_44 ;
V_46 . V_53 = V_43 ;
V_41 = F_11 ( V_31 -> V_33 -> V_54 , & V_46 , 1 ) ;
if ( V_41 == 1 ) {
V_41 = 0 ;
} else {
V_41 = V_41 < 0 ? V_41 : - V_55 ;
F_9 ( & V_31 -> V_33 -> V_34 , L_3 ,
V_56 , V_41 ) ;
}
return V_41 ;
}
static int F_12 ( struct V_30 * V_31 ,
const T_2 * const V_43 , unsigned int V_44 )
{
int V_41 ;
struct V_45 V_46 ;
V_46 . V_47 = V_31 -> V_48 ;
V_46 . V_49 = V_31 -> V_33 -> V_49 & V_50 ;
V_46 . V_52 = V_44 ;
V_46 . V_53 = ( T_2 * ) V_43 ;
V_41 = F_11 ( V_31 -> V_33 -> V_54 , & V_46 , 1 ) ;
if ( V_41 == 1 ) {
V_41 = 0 ;
} else {
V_41 = V_41 < 0 ? V_41 : - V_55 ;
F_9 ( & V_31 -> V_33 -> V_34 , L_4 ,
V_56 , V_41 ) ;
}
return V_41 ;
}
static int F_13 ( struct V_30 * V_31 , bool V_57 )
{
T_2 V_58 = V_31 -> V_33 -> V_47 ;
T_2 V_59 ;
switch ( V_58 ) {
case 0x4a :
case 0x4b :
if ( V_57 || V_31 -> V_60 . V_61 >= 0xa2 ) {
V_59 = V_58 - 0x24 ;
break;
}
case 0x4c :
case 0x4d :
case 0x5a :
case 0x5b :
V_59 = V_58 - 0x26 ;
break;
default:
F_9 ( & V_31 -> V_33 -> V_34 ,
L_5 ,
V_58 ) ;
return - V_62 ;
}
V_31 -> V_48 = V_59 ;
return 0 ;
}
static int F_14 ( struct V_30 * V_31 , bool V_63 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
int error ;
T_2 V_43 ;
bool V_64 ;
error = F_13 ( V_31 , V_63 ) ;
if ( error )
return error ;
error = F_10 ( V_31 , & V_43 , 1 ) ;
if ( error )
return error ;
V_64 = ( V_43 & ~ V_65 ) == V_66 ;
F_9 ( V_34 , L_6 ,
V_43 , V_64 ? L_7 : L_8 ) ;
return 0 ;
}
static T_2 F_15 ( struct V_30 * V_31 , T_2 V_43 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
T_2 V_53 [ 3 ] ;
if ( V_43 & V_67 ) {
if ( F_10 ( V_31 , & V_53 [ 0 ] , 3 ) != 0 ) {
F_9 ( V_34 , L_9 , V_56 ) ;
return V_43 ;
}
F_5 ( V_34 , L_10 , V_53 [ 1 ] , V_53 [ 2 ] ) ;
return V_53 [ 0 ] ;
} else {
F_5 ( V_34 , L_11 , V_43 & V_68 ) ;
return V_43 ;
}
}
static int F_16 ( struct V_30 * V_31 , unsigned int V_69 ,
bool V_70 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
T_2 V_43 ;
int V_41 ;
V_71:
if ( V_70 ) {
V_41 = F_6 ( V_31 , & V_31 -> V_72 ,
V_73 ) ;
if ( V_41 ) {
F_9 ( V_34 , L_12 , V_41 ) ;
return V_41 ;
}
}
V_41 = F_10 ( V_31 , & V_43 , 1 ) ;
if ( V_41 )
return V_41 ;
if ( V_69 == V_74 )
V_43 = F_15 ( V_31 , V_43 ) ;
switch ( V_69 ) {
case V_74 :
case V_75 :
case V_66 :
V_43 &= ~ V_65 ;
break;
case V_76 :
if ( V_43 == V_77 ) {
goto V_71;
} else if ( V_43 == V_78 ) {
F_9 ( V_34 , L_13 ) ;
return - V_62 ;
}
break;
default:
return - V_62 ;
}
if ( V_43 != V_69 ) {
F_9 ( V_34 , L_14 ,
V_43 , V_69 ) ;
return - V_62 ;
}
return 0 ;
}
static int F_17 ( struct V_30 * V_31 , bool V_79 )
{
int V_41 ;
T_2 V_53 [ 2 ] ;
if ( V_79 ) {
V_53 [ 0 ] = V_80 ;
V_53 [ 1 ] = V_81 ;
} else {
V_53 [ 0 ] = 0x01 ;
V_53 [ 1 ] = 0x01 ;
}
V_41 = F_12 ( V_31 , V_53 , 2 ) ;
if ( V_41 )
return V_41 ;
return 0 ;
}
static int F_18 ( struct V_82 * V_33 ,
T_3 V_83 , T_3 V_52 , void * V_43 )
{
struct V_45 V_84 [ 2 ] ;
T_2 V_53 [ 2 ] ;
int V_41 ;
V_53 [ 0 ] = V_83 & 0xff ;
V_53 [ 1 ] = ( V_83 >> 8 ) & 0xff ;
V_84 [ 0 ] . V_47 = V_33 -> V_47 ;
V_84 [ 0 ] . V_49 = 0 ;
V_84 [ 0 ] . V_52 = 2 ;
V_84 [ 0 ] . V_53 = V_53 ;
V_84 [ 1 ] . V_47 = V_33 -> V_47 ;
V_84 [ 1 ] . V_49 = V_51 ;
V_84 [ 1 ] . V_52 = V_52 ;
V_84 [ 1 ] . V_53 = V_43 ;
V_41 = F_11 ( V_33 -> V_54 , V_84 , 2 ) ;
if ( V_41 == 2 ) {
V_41 = 0 ;
} else {
if ( V_41 >= 0 )
V_41 = - V_55 ;
F_9 ( & V_33 -> V_34 , L_15 ,
V_56 , V_41 ) ;
}
return V_41 ;
}
static int F_19 ( struct V_82 * V_33 , T_3 V_83 , T_3 V_52 ,
const void * V_43 )
{
T_2 * V_53 ;
T_1 V_44 ;
int V_41 ;
V_44 = V_52 + 2 ;
V_53 = F_20 ( V_44 , V_85 ) ;
if ( ! V_53 )
return - V_86 ;
V_53 [ 0 ] = V_83 & 0xff ;
V_53 [ 1 ] = ( V_83 >> 8 ) & 0xff ;
memcpy ( & V_53 [ 2 ] , V_43 , V_52 ) ;
V_41 = F_21 ( V_33 , V_53 , V_44 ) ;
if ( V_41 == V_44 ) {
V_41 = 0 ;
} else {
if ( V_41 >= 0 )
V_41 = - V_55 ;
F_9 ( & V_33 -> V_34 , L_4 ,
V_56 , V_41 ) ;
}
F_22 ( V_53 ) ;
return V_41 ;
}
static int F_23 ( struct V_82 * V_33 , T_3 V_83 , T_2 V_43 )
{
return F_19 ( V_33 , V_83 , 1 , & V_43 ) ;
}
static struct V_1 *
F_24 ( struct V_30 * V_31 , T_2 type )
{
struct V_1 * V_87 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_31 -> V_60 . V_89 ; V_88 ++ ) {
V_87 = V_31 -> V_90 + V_88 ;
if ( V_87 -> type == type )
return V_87 ;
}
F_25 ( & V_31 -> V_33 -> V_34 , L_16 , type ) ;
return NULL ;
}
static void F_26 ( struct V_30 * V_31 , T_2 * V_46 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
T_2 V_91 = V_46 [ 1 ] ;
T_4 V_92 = V_46 [ 2 ] | ( V_46 [ 3 ] << 8 ) | ( V_46 [ 4 ] << 16 ) ;
F_27 ( & V_31 -> V_93 ) ;
if ( V_92 != V_31 -> V_94 ) {
V_31 -> V_94 = V_92 ;
F_5 ( V_34 , L_17 , V_92 ) ;
}
if ( V_91 & V_95 )
F_27 ( & V_31 -> V_96 ) ;
if ( V_91 != V_31 -> V_97 )
F_5 ( V_34 , L_18 ,
V_91 ,
V_91 == 0 ? L_19 : L_8 ,
V_91 & V_95 ? L_20 : L_8 ,
V_91 & V_98 ? L_21 : L_8 ,
V_91 & V_99 ? L_22 : L_8 ,
V_91 & V_100 ? L_23 : L_8 ,
V_91 & V_101 ? L_24 : L_8 ,
V_91 & V_102 ? L_25 : L_8 ) ;
V_31 -> V_97 = V_91 ;
}
static int F_28 ( struct V_30 * V_31 ,
T_2 type , T_2 V_103 , T_2 V_43 )
{
struct V_1 * V_87 ;
T_3 V_83 ;
V_87 = F_24 ( V_31 , type ) ;
if ( ! V_87 || V_103 >= F_1 ( V_87 ) )
return - V_62 ;
V_83 = V_87 -> V_104 ;
return F_23 ( V_31 -> V_33 , V_83 + V_103 , V_43 ) ;
}
static void F_29 ( struct V_30 * V_31 , T_2 * V_32 )
{
struct V_105 * V_106 = V_31 -> V_105 ;
const struct V_107 * V_108 = V_31 -> V_108 ;
int V_88 ;
for ( V_88 = 0 ; V_88 < V_108 -> V_109 ; V_88 ++ ) {
if ( V_108 -> V_110 [ V_88 ] == V_111 )
continue;
F_30 ( V_106 , V_108 -> V_110 [ V_88 ] ,
! ( V_32 [ 1 ] & F_31 ( V_88 ) ) ) ;
}
}
static void F_32 ( struct V_30 * V_31 )
{
F_33 ( V_31 -> V_105 ,
V_31 -> V_108 -> V_109 ) ;
F_34 ( V_31 -> V_105 ) ;
}
static void F_35 ( struct V_30 * V_31 , T_2 * V_32 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
struct V_105 * V_105 = V_31 -> V_105 ;
int V_112 ;
T_2 V_91 ;
int V_113 ;
int V_114 ;
int V_115 ;
int V_116 ;
V_112 = V_32 [ 0 ] - V_31 -> V_117 ;
V_91 = V_32 [ 1 ] ;
V_113 = ( V_32 [ 2 ] << 4 ) | ( ( V_32 [ 4 ] >> 4 ) & 0xf ) ;
V_114 = ( V_32 [ 3 ] << 4 ) | ( ( V_32 [ 4 ] & 0xf ) ) ;
if ( V_31 -> V_118 < 1024 )
V_113 >>= 2 ;
if ( V_31 -> V_119 < 1024 )
V_114 >>= 2 ;
V_115 = V_32 [ 5 ] ;
V_116 = V_32 [ 6 ] ;
F_5 ( V_34 ,
L_26 ,
V_112 ,
( V_91 & V_120 ) ? 'D' : '.' ,
( V_91 & V_121 ) ? 'P' : '.' ,
( V_91 & V_122 ) ? 'R' : '.' ,
( V_91 & V_123 ) ? 'M' : '.' ,
( V_91 & V_124 ) ? 'V' : '.' ,
( V_91 & V_125 ) ? 'A' : '.' ,
( V_91 & V_126 ) ? 'S' : '.' ,
( V_91 & V_127 ) ? 'U' : '.' ,
V_113 , V_114 , V_115 , V_116 ) ;
F_36 ( V_105 , V_112 ) ;
if ( V_91 & V_120 ) {
if ( V_91 & V_122 ) {
F_37 ( V_105 ,
V_128 , 0 ) ;
F_32 ( V_31 ) ;
}
F_37 ( V_105 , V_128 , 1 ) ;
F_38 ( V_105 , V_129 , V_113 ) ;
F_38 ( V_105 , V_130 , V_114 ) ;
F_38 ( V_105 , V_131 , V_116 ) ;
F_38 ( V_105 , V_132 , V_115 ) ;
} else {
F_37 ( V_105 , V_128 , 0 ) ;
}
V_31 -> V_133 = true ;
}
static void F_39 ( struct V_30 * V_31 , T_2 * V_32 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
struct V_105 * V_105 = V_31 -> V_105 ;
int V_112 ;
T_2 V_91 ;
T_2 type = 0 ;
T_3 V_113 ;
T_3 V_114 ;
int V_134 = 0 ;
int V_135 = 0 ;
T_2 V_136 = 0 ;
T_2 V_137 = 0 ;
T_2 V_138 = 0 ;
V_112 = V_32 [ 0 ] - V_31 -> V_139 - 2 ;
if ( V_112 < 0 )
return;
V_91 = V_32 [ 1 ] ;
V_113 = F_40 ( & V_32 [ 2 ] ) ;
V_114 = F_40 ( & V_32 [ 4 ] ) ;
if ( V_91 & V_140 ) {
type = ( V_91 & V_141 ) >> 4 ;
switch ( type ) {
case V_142 :
V_135 = V_128 ;
V_134 = V_143 ;
if ( V_31 -> V_144 )
V_138 = V_32 [ V_31 -> V_144 ] ;
break;
case V_145 :
case V_146 :
V_135 = V_128 ;
V_134 = V_147 ;
if ( V_31 -> V_148 )
V_136 = V_32 [ V_31 -> V_148 ] ;
if ( V_31 -> V_149 )
V_137 = V_32 [ V_31 -> V_149 ] ;
if ( V_31 -> V_144 )
V_138 = V_32 [ V_31 -> V_144 ] ;
break;
case V_150 :
V_135 = V_151 ;
V_136 = V_152 ;
if ( V_31 -> V_149 )
V_137 = V_32 [ V_31 -> V_149 ] ;
break;
case V_153 :
break;
default:
F_5 ( V_34 , L_27 ) ;
return;
}
}
if ( ! V_137 && type != V_142 )
V_137 = V_154 ;
F_36 ( V_105 , V_112 ) ;
if ( V_91 & V_140 ) {
F_5 ( V_34 , L_28 ,
V_112 , type , V_113 , V_114 , V_136 , V_137 , V_138 ) ;
F_37 ( V_105 , V_135 , 1 ) ;
F_38 ( V_105 , V_129 , V_113 ) ;
F_38 ( V_105 , V_130 , V_114 ) ;
F_38 ( V_105 , V_132 , V_136 ) ;
F_38 ( V_105 , V_131 , V_137 ) ;
F_38 ( V_105 , V_155 , V_134 ) ;
F_38 ( V_105 , V_156 , V_138 ) ;
} else {
F_5 ( V_34 , L_29 , V_112 ) ;
F_37 ( V_105 , 0 , 0 ) ;
}
V_31 -> V_133 = true ;
}
static int F_41 ( struct V_30 * V_31 , T_2 * V_32 )
{
T_2 V_157 = V_32 [ 0 ] ;
if ( V_157 == V_158 )
return 0 ;
if ( V_157 == V_31 -> V_159 ) {
F_26 ( V_31 , V_32 ) ;
} else if ( ! V_31 -> V_105 ) {
F_4 ( V_31 , V_32 ) ;
} else if ( V_157 >= V_31 -> V_117 &&
V_157 <= V_31 -> V_160 ) {
F_35 ( V_31 , V_32 ) ;
} else if ( V_157 >= V_31 -> V_139 &&
V_157 <= V_31 -> V_161 ) {
F_39 ( V_31 , V_32 ) ;
} else if ( V_157 == V_31 -> V_162 ) {
F_29 ( V_31 , V_32 ) ;
V_31 -> V_133 = true ;
} else {
F_4 ( V_31 , V_32 ) ;
}
return 1 ;
}
static int F_42 ( struct V_30 * V_31 , T_2 V_44 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
int V_41 ;
int V_88 ;
T_2 V_163 = 0 ;
if ( V_44 > V_31 -> V_164 )
return - V_62 ;
V_41 = F_18 ( V_31 -> V_33 , V_31 -> V_165 ,
V_31 -> V_35 * V_44 , V_31 -> V_166 ) ;
if ( V_41 ) {
F_9 ( V_34 , L_30 , V_44 , V_41 ) ;
return V_41 ;
}
for ( V_88 = 0 ; V_88 < V_44 ; V_88 ++ ) {
V_41 = F_41 ( V_31 ,
V_31 -> V_166 + V_31 -> V_35 * V_88 ) ;
if ( V_41 == 1 )
V_163 ++ ;
}
return V_163 ;
}
static T_5 F_43 ( struct V_30 * V_31 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
int V_41 ;
T_2 V_44 , V_167 ;
V_41 = F_18 ( V_31 -> V_33 , V_31 -> V_168 ,
V_31 -> V_35 + 1 , V_31 -> V_166 ) ;
if ( V_41 ) {
F_9 ( V_34 , L_31 , V_41 ) ;
return V_169 ;
}
V_44 = V_31 -> V_166 [ 0 ] ;
if ( V_44 == 0 )
return V_169 ;
if ( V_44 > V_31 -> V_164 ) {
F_25 ( V_34 , L_32 , V_44 ) ;
V_44 = V_31 -> V_164 ;
}
V_41 = F_41 ( V_31 , V_31 -> V_166 + 1 ) ;
if ( V_41 < 0 ) {
F_25 ( V_34 , L_33 ) ;
return V_169 ;
}
V_167 = V_44 - 1 ;
if ( V_167 ) {
V_41 = F_42 ( V_31 , V_167 ) ;
if ( V_41 < 0 )
goto V_170;
else if ( V_41 != V_167 )
F_25 ( V_34 , L_33 ) ;
}
V_170:
if ( V_31 -> V_133 ) {
F_32 ( V_31 ) ;
V_31 -> V_133 = false ;
}
return V_171 ;
}
static int F_44 ( struct V_30 * V_31 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
int V_44 , V_172 ;
T_2 V_173 = 2 ;
V_44 = V_31 -> V_164 ;
do {
V_172 = F_42 ( V_31 , V_44 ) ;
if ( V_172 < V_44 )
return 0 ;
} while ( -- V_173 );
if ( V_31 -> V_133 ) {
F_32 ( V_31 ) ;
V_31 -> V_133 = false ;
}
F_9 ( V_34 , L_34 ) ;
return - V_174 ;
}
static T_5 F_45 ( struct V_30 * V_31 )
{
int V_175 , V_176 ;
T_2 V_44 = V_31 -> V_177 ;
if ( V_44 < 1 || V_44 > V_31 -> V_164 )
V_44 = 1 ;
V_175 = F_42 ( V_31 , V_44 + 1 ) ;
if ( V_175 < 0 )
return V_169 ;
else if ( V_175 <= V_44 )
goto V_178;
do {
V_176 = F_42 ( V_31 , 2 ) ;
if ( V_176 < 0 )
return V_169 ;
V_175 += V_176 ;
if ( V_176 < 2 )
break;
} while ( V_175 < V_31 -> V_179 );
V_178:
V_31 -> V_177 = V_175 ;
if ( V_31 -> V_133 ) {
F_32 ( V_31 ) ;
V_31 -> V_133 = false ;
}
return V_171 ;
}
static T_5 F_46 ( int V_180 , void * V_181 )
{
struct V_30 * V_31 = V_181 ;
if ( V_31 -> V_182 ) {
F_27 ( & V_31 -> V_72 ) ;
return V_171 ;
}
if ( ! V_31 -> V_90 )
return V_171 ;
if ( V_31 -> V_168 ) {
return F_43 ( V_31 ) ;
} else {
return F_45 ( V_31 ) ;
}
}
static int F_47 ( struct V_30 * V_31 , T_3 V_183 ,
T_2 V_184 , bool V_70 )
{
T_3 V_83 ;
T_2 V_185 ;
int V_186 = 0 ;
int V_41 ;
V_83 = V_31 -> V_187 + V_183 ;
V_41 = F_23 ( V_31 -> V_33 , V_83 , V_184 ) ;
if ( V_41 )
return V_41 ;
if ( ! V_70 )
return 0 ;
do {
F_48 ( 20 ) ;
V_41 = F_18 ( V_31 -> V_33 , V_83 , 1 , & V_185 ) ;
if ( V_41 )
return V_41 ;
} while ( V_185 != 0 && V_186 ++ <= 100 );
if ( V_186 > 100 ) {
F_9 ( & V_31 -> V_33 -> V_34 , L_35 ) ;
return - V_55 ;
}
return 0 ;
}
static int F_49 ( struct V_30 * V_31 )
{
int error ;
F_50 ( V_31 -> V_180 ) ;
error = F_44 ( V_31 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_51 ( struct V_30 * V_31 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
int V_41 = 0 ;
F_52 ( V_34 , L_36 ) ;
F_53 ( V_31 -> V_180 ) ;
F_54 ( & V_31 -> V_96 ) ;
V_41 = F_47 ( V_31 , V_188 , V_189 , false ) ;
if ( V_41 )
return V_41 ;
F_48 ( 100 ) ;
F_49 ( V_31 ) ;
V_41 = F_6 ( V_31 , & V_31 -> V_96 ,
V_190 ) ;
if ( V_41 )
return V_41 ;
return 0 ;
}
static void F_55 ( struct V_30 * V_31 , T_2 V_191 , T_2 V_184 )
{
V_31 -> V_94 = 0 ;
F_54 ( & V_31 -> V_93 ) ;
F_47 ( V_31 , V_191 , V_184 , true ) ;
F_6 ( V_31 , & V_31 -> V_93 , V_192 ) ;
}
static void F_56 ( T_4 * V_92 , T_2 V_193 , T_2 V_194 )
{
static const unsigned int V_195 = 0x80001B ;
T_4 V_196 ;
T_4 V_197 ;
V_197 = ( V_194 << 8 ) | V_193 ;
V_196 = ( ( * V_92 << 1 ) ^ V_197 ) ;
if ( V_196 & 0x1000000 )
V_196 ^= V_195 ;
* V_92 = V_196 ;
}
static T_4 F_57 ( T_2 * V_198 , T_6 V_199 , T_6 V_200 )
{
T_4 V_92 = 0 ;
T_2 * V_201 = V_198 + V_199 ;
T_2 * V_202 = V_198 + V_200 - 1 ;
if ( V_200 < V_199 )
return - V_62 ;
while ( V_201 < V_202 ) {
F_56 ( & V_92 , * V_201 , * ( V_201 + 1 ) ) ;
V_201 += 2 ;
}
if ( V_201 == V_202 )
F_56 ( & V_92 , * V_201 , 0 ) ;
V_92 &= 0x00FFFFFF ;
return V_92 ;
}
static int F_58 ( struct V_30 * V_31 ,
const struct V_203 * V_204 ,
unsigned int V_205 ,
unsigned int V_206 ,
T_2 * V_207 ,
T_1 V_208 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
struct V_1 * V_87 ;
unsigned int type , V_209 , V_210 , V_211 ;
int V_103 ;
int V_41 ;
int V_88 ;
T_3 V_83 ;
T_2 V_43 ;
while ( V_205 < V_204 -> V_210 ) {
V_41 = sscanf ( V_204 -> V_31 + V_205 , L_37 ,
& type , & V_209 , & V_210 , & V_103 ) ;
if ( V_41 == 0 ) {
break;
} else if ( V_41 != 3 ) {
F_9 ( V_34 , L_38 ) ;
return - V_62 ;
}
V_205 += V_103 ;
V_87 = F_24 ( V_31 , type ) ;
if ( ! V_87 ) {
for ( V_88 = 0 ; V_88 < V_210 ; V_88 ++ ) {
V_41 = sscanf ( V_204 -> V_31 + V_205 , L_39 ,
& V_43 , & V_103 ) ;
if ( V_41 != 1 ) {
F_9 ( V_34 , L_40 ,
type , V_88 ) ;
return - V_62 ;
}
V_205 += V_103 ;
}
continue;
}
if ( V_210 > F_1 ( V_87 ) ) {
F_25 ( V_34 , L_41 ,
V_210 - F_1 ( V_87 ) , type ) ;
} else if ( F_1 ( V_87 ) > V_210 ) {
F_25 ( V_34 , L_42 ,
F_1 ( V_87 ) - V_210 , type ) ;
}
if ( V_209 >= F_2 ( V_87 ) ) {
F_9 ( V_34 , L_43 ) ;
return - V_62 ;
}
V_83 = V_87 -> V_104 + F_1 ( V_87 ) * V_209 ;
for ( V_88 = 0 ; V_88 < V_210 ; V_88 ++ ) {
V_41 = sscanf ( V_204 -> V_31 + V_205 , L_39 ,
& V_43 ,
& V_103 ) ;
if ( V_41 != 1 ) {
F_9 ( V_34 , L_40 ,
type , V_88 ) ;
return - V_62 ;
}
V_205 += V_103 ;
if ( V_88 > F_1 ( V_87 ) )
continue;
V_211 = V_83 + V_88 - V_206 ;
if ( V_211 >= 0 && V_211 < V_208 ) {
* ( V_207 + V_211 ) = V_43 ;
} else {
F_9 ( V_34 , L_44 ,
V_83 , V_87 -> type , V_211 ) ;
return - V_62 ;
}
}
}
return 0 ;
}
static int F_59 ( struct V_30 * V_31 , unsigned int V_212 ,
T_2 * V_207 , T_1 V_208 )
{
unsigned int V_211 = 0 ;
int error ;
while ( V_211 < V_208 ) {
unsigned int V_210 = V_208 - V_211 ;
if ( V_210 > V_213 )
V_210 = V_213 ;
error = F_19 ( V_31 -> V_33 ,
V_212 + V_211 ,
V_210 , V_207 + V_211 ) ;
if ( error ) {
F_9 ( & V_31 -> V_33 -> V_34 ,
L_45 , error ) ;
return error ;
}
V_211 += V_210 ;
}
return 0 ;
}
static int F_60 ( struct V_30 * V_31 , const struct V_203 * V_204 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
struct V_214 V_215 ;
int V_41 ;
int V_103 ;
int V_205 ;
int V_88 ;
int V_206 ;
T_4 V_216 , V_94 , V_217 ;
T_2 * V_207 ;
T_1 V_208 ;
F_55 ( V_31 , V_218 , 1 ) ;
if ( strncmp ( V_204 -> V_31 , V_219 , strlen ( V_219 ) ) ) {
F_9 ( V_34 , L_46 ) ;
return - V_62 ;
}
V_205 = strlen ( V_219 ) ;
for ( V_88 = 0 ; V_88 < sizeof( struct V_214 ) ; V_88 ++ ) {
V_41 = sscanf ( V_204 -> V_31 + V_205 , L_39 ,
( unsigned char * ) & V_215 + V_88 ,
& V_103 ) ;
if ( V_41 != 1 ) {
F_9 ( V_34 , L_47 ) ;
return - V_62 ;
}
V_205 += V_103 ;
}
if ( V_215 . V_61 != V_31 -> V_60 . V_61 ) {
F_9 ( V_34 , L_48 ) ;
return - V_62 ;
}
if ( V_215 . V_220 != V_31 -> V_60 . V_220 ) {
F_9 ( V_34 , L_49 ) ;
return - V_62 ;
}
V_41 = sscanf ( V_204 -> V_31 + V_205 , L_50 , & V_216 , & V_103 ) ;
if ( V_41 != 1 ) {
F_9 ( V_34 , L_51 ) ;
return - V_62 ;
}
V_205 += V_103 ;
V_41 = sscanf ( V_204 -> V_31 + V_205 , L_50 , & V_94 , & V_103 ) ;
if ( V_41 != 1 ) {
F_9 ( V_34 , L_52 ) ;
return - V_62 ;
}
V_205 += V_103 ;
if ( V_216 == V_31 -> V_216 ) {
if ( V_94 == 0 || V_31 -> V_94 == 0 ) {
F_52 ( V_34 , L_53 ) ;
} else if ( V_94 == V_31 -> V_94 ) {
F_5 ( V_34 , L_54 ,
V_31 -> V_94 ) ;
return 0 ;
} else {
F_52 ( V_34 , L_55 ,
V_31 -> V_94 , V_94 ) ;
}
} else {
F_25 ( V_34 ,
L_56 ,
V_31 -> V_216 , V_216 ) ;
}
V_206 = V_221 +
V_31 -> V_60 . V_89 * sizeof( struct V_1 ) +
V_222 ;
V_208 = V_31 -> V_223 - V_206 ;
V_207 = F_61 ( V_208 , V_85 ) ;
if ( ! V_207 ) {
F_9 ( V_34 , L_57 ) ;
return - V_86 ;
}
V_41 = F_58 ( V_31 , V_204 , V_205 , V_206 ,
V_207 , V_208 ) ;
if ( V_41 )
goto V_224;
if ( V_31 -> V_225 < V_206 ) {
F_9 ( V_34 , L_58 ,
V_31 -> V_225 , V_206 ) ;
V_41 = 0 ;
goto V_224;
}
V_217 = F_57 ( V_207 ,
V_31 -> V_225 - V_206 ,
V_208 ) ;
if ( V_94 > 0 && V_94 != V_217 )
F_25 ( V_34 , L_59 ,
V_217 , V_94 ) ;
V_41 = F_59 ( V_31 , V_206 ,
V_207 , V_208 ) ;
if ( V_41 )
goto V_224;
F_55 ( V_31 , V_226 , V_227 ) ;
V_41 = F_51 ( V_31 ) ;
if ( V_41 )
goto V_224;
F_52 ( V_34 , L_60 ) ;
F_62 ( V_31 ) ;
V_224:
F_22 ( V_207 ) ;
return V_41 ;
}
static int F_63 ( struct V_30 * V_31 )
{
struct V_82 * V_33 = V_31 -> V_33 ;
struct V_214 * V_60 = & V_31 -> V_60 ;
int error ;
error = F_18 ( V_33 , 0 , sizeof( * V_60 ) , V_60 ) ;
if ( error )
return error ;
return 0 ;
}
static void F_64 ( struct V_30 * V_31 )
{
if ( V_31 -> V_105 ) {
F_65 ( V_31 -> V_105 ) ;
V_31 -> V_105 = NULL ;
}
}
static void F_66 ( struct V_30 * V_31 )
{
#ifdef F_67
F_68 ( & V_31 -> V_228 . V_229 ) ;
F_69 ( & V_31 -> V_228 . V_230 ) ;
#endif
F_22 ( V_31 -> V_90 ) ;
V_31 -> V_90 = NULL ;
F_22 ( V_31 -> V_166 ) ;
V_31 -> V_166 = NULL ;
V_31 -> V_165 = 0 ;
V_31 -> V_35 = 0 ;
V_31 -> V_159 = 0 ;
V_31 -> V_225 = 0 ;
V_31 -> V_117 = 0 ;
V_31 -> V_160 = 0 ;
V_31 -> V_162 = 0 ;
V_31 -> V_168 = 0 ;
V_31 -> V_139 = 0 ;
V_31 -> V_161 = 0 ;
V_31 -> V_164 = 0 ;
}
static int F_70 ( struct V_30 * V_31 )
{
struct V_82 * V_33 = V_31 -> V_33 ;
T_1 V_231 ;
struct V_1 * V_90 ;
int error ;
int V_88 ;
T_2 V_232 ;
T_3 V_233 ;
V_231 = V_31 -> V_60 . V_89 * sizeof( struct V_1 ) ;
V_90 = F_61 ( V_231 , V_85 ) ;
if ( ! V_90 ) {
F_9 ( & V_31 -> V_33 -> V_34 , L_57 ) ;
return - V_86 ;
}
error = F_18 ( V_33 , V_221 , V_231 ,
V_90 ) ;
if ( error ) {
F_22 ( V_90 ) ;
return error ;
}
V_232 = 1 ;
V_31 -> V_223 = 0 ;
for ( V_88 = 0 ; V_88 < V_31 -> V_60 . V_89 ; V_88 ++ ) {
struct V_1 * V_87 = V_90 + V_88 ;
T_2 V_234 , V_235 ;
F_71 ( & V_87 -> V_104 ) ;
if ( V_87 -> V_236 ) {
V_234 = V_232 ;
V_232 += V_87 -> V_236 *
F_2 ( V_87 ) ;
V_235 = V_232 - 1 ;
} else {
V_234 = 0 ;
V_235 = 0 ;
}
F_5 ( & V_31 -> V_33 -> V_34 ,
L_61 ,
V_87 -> type , V_87 -> V_104 ,
F_1 ( V_87 ) , F_2 ( V_87 ) ,
V_234 , V_235 ) ;
switch ( V_87 -> type ) {
case V_237 :
if ( V_31 -> V_60 . V_61 == 0x80 &&
V_31 -> V_60 . V_238 < 0x20 ) {
V_31 -> V_35 = F_1 ( V_87 ) ;
} else {
V_31 -> V_35 = F_1 ( V_87 ) - 1 ;
}
V_31 -> V_165 = V_87 -> V_104 ;
break;
case V_5 :
V_31 -> V_159 = V_234 ;
V_31 -> V_187 = V_87 -> V_104 ;
break;
case V_6 :
V_31 -> V_225 = V_87 -> V_104 ;
break;
case V_9 :
V_31 -> V_239 = V_9 ;
V_31 -> V_117 = V_234 ;
V_31 -> V_160 = V_235 ;
V_31 -> V_179 = V_87 -> V_236
* F_2 ( V_87 ) ;
break;
case V_240 :
V_31 -> V_168 = V_87 -> V_104 ;
break;
case V_24 :
V_31 -> V_162 = V_234 ;
break;
case V_13 :
V_31 -> V_239 = V_13 ;
V_31 -> V_139 = V_234 ;
V_31 -> V_161 = V_235 ;
V_31 -> V_179 = V_87 -> V_236 - 2 ;
break;
}
V_233 = V_87 -> V_104
+ F_1 ( V_87 ) * F_2 ( V_87 ) - 1 ;
if ( V_233 >= V_31 -> V_223 )
V_31 -> V_223 = V_233 + 1 ;
}
V_31 -> V_164 = V_232 ;
if ( V_31 -> V_168 && ( V_31 -> V_165 != V_31 -> V_168 + 1 ) ) {
F_9 ( & V_33 -> V_34 , L_62 ) ;
error = - V_62 ;
goto V_241;
}
V_31 -> V_166 = F_72 ( V_31 -> V_164 ,
V_31 -> V_35 , V_85 ) ;
if ( ! V_31 -> V_166 ) {
F_9 ( & V_33 -> V_34 , L_63 ) ;
error = - V_86 ;
goto V_241;
}
V_31 -> V_90 = V_90 ;
return 0 ;
V_241:
F_66 ( V_31 ) ;
return error ;
}
static int F_73 ( struct V_30 * V_31 )
{
struct V_82 * V_33 = V_31 -> V_33 ;
int error ;
struct V_242 V_243 ;
unsigned char V_244 ;
struct V_1 * V_87 ;
V_87 = F_24 ( V_31 , V_9 ) ;
if ( ! V_87 )
return - V_62 ;
error = F_18 ( V_33 ,
V_87 -> V_104 + V_245 ,
sizeof( V_31 -> V_246 ) , & V_31 -> V_246 ) ;
if ( error )
return error ;
error = F_18 ( V_33 ,
V_87 -> V_104 + V_247 ,
sizeof( V_31 -> V_248 ) , & V_31 -> V_248 ) ;
if ( error )
return error ;
error = F_18 ( V_33 ,
V_87 -> V_104 + V_249 ,
sizeof( V_243 ) , & V_243 ) ;
if ( error )
return error ;
V_31 -> V_118 = F_40 ( & V_243 . V_113 ) ;
V_31 -> V_119 = F_40 ( & V_243 . V_114 ) ;
error = F_18 ( V_33 ,
V_87 -> V_104 + V_250 ,
1 , & V_244 ) ;
if ( error )
return error ;
V_31 -> V_251 = V_244 & V_252 ;
V_31 -> V_253 = V_244 & V_254 ;
V_31 -> V_255 = V_244 & V_256 ;
return 0 ;
}
static int F_74 ( struct V_30 * V_31 )
{
struct V_82 * V_33 = V_31 -> V_33 ;
int error ;
struct V_1 * V_87 ;
T_3 V_257 , V_258 ;
T_2 V_204 , V_259 ;
T_2 V_260 ;
V_87 = F_24 ( V_31 , V_13 ) ;
if ( ! V_87 )
return - V_62 ;
error = F_18 ( V_33 ,
V_87 -> V_104 + V_261 ,
sizeof( V_257 ) , & V_257 ) ;
if ( error )
return error ;
V_31 -> V_118 = F_40 ( & V_257 ) ;
error = F_18 ( V_33 ,
V_87 -> V_104 + V_262 ,
sizeof( V_258 ) , & V_258 ) ;
if ( error )
return error ;
V_31 -> V_119 = F_40 ( & V_258 ) ;
error = F_18 ( V_33 ,
V_87 -> V_104 + V_263 ,
sizeof( V_31 -> V_246 ) , & V_31 -> V_246 ) ;
if ( error )
return error ;
error = F_18 ( V_33 ,
V_87 -> V_104 + V_264 ,
sizeof( V_31 -> V_248 ) , & V_31 -> V_248 ) ;
if ( error )
return error ;
error = F_18 ( V_33 ,
V_87 -> V_104 + V_265 ,
1 , & V_204 ) ;
if ( error )
return error ;
V_31 -> V_251 = V_204 & V_266 ;
V_31 -> V_253 = V_204 & V_267 ;
V_31 -> V_255 = V_204 & V_268 ;
error = F_18 ( V_33 ,
V_87 -> V_104 + V_269 ,
1 , & V_259 ) ;
if ( error )
return error ;
V_260 = 6 ;
if ( V_259 & V_270 )
V_31 -> V_144 = V_260 ++ ;
if ( V_259 & V_271 )
V_31 -> V_149 = V_260 ++ ;
if ( V_259 & V_272 )
V_31 -> V_148 = V_260 ++ ;
F_5 ( & V_33 -> V_34 ,
L_64 ,
V_31 -> V_144 , V_31 -> V_149 , V_31 -> V_148 ) ;
return 0 ;
}
static void F_75 ( struct V_105 * V_105 ,
struct V_30 * V_31 )
{
const struct V_107 * V_108 = V_31 -> V_108 ;
int V_88 ;
V_105 -> V_273 = L_65 ;
F_76 ( V_274 , V_105 -> V_275 ) ;
F_77 ( V_105 , V_276 , V_277 ) ;
F_77 ( V_105 , V_278 , V_277 ) ;
F_77 ( V_105 , V_129 ,
V_277 ) ;
F_77 ( V_105 , V_130 ,
V_277 ) ;
for ( V_88 = 0 ; V_88 < V_108 -> V_109 ; V_88 ++ )
if ( V_108 -> V_110 [ V_88 ] != V_111 )
F_78 ( V_105 , V_279 ,
V_108 -> V_110 [ V_88 ] ) ;
}
static int F_79 ( struct V_30 * V_31 )
{
const struct V_107 * V_108 = V_31 -> V_108 ;
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
struct V_105 * V_105 ;
int error ;
unsigned int V_280 ;
unsigned int V_281 = 0 ;
switch ( V_31 -> V_239 ) {
case V_9 :
V_280 = V_31 -> V_160 - V_31 -> V_117 + 1 ;
error = F_73 ( V_31 ) ;
if ( error )
F_25 ( V_34 , L_66 ) ;
break;
case V_13 :
V_280 = V_31 -> V_179 ;
error = F_74 ( V_31 ) ;
if ( error )
F_25 ( V_34 , L_67 ) ;
break;
default:
F_9 ( V_34 , L_68 ) ;
return - V_62 ;
}
if ( V_31 -> V_118 == 0 )
V_31 -> V_118 = 1023 ;
if ( V_31 -> V_119 == 0 )
V_31 -> V_119 = 1023 ;
if ( V_31 -> V_251 )
F_80 ( V_31 -> V_118 , V_31 -> V_119 ) ;
F_52 ( V_34 , L_69 , V_31 -> V_118 , V_31 -> V_119 ) ;
V_105 = F_81 () ;
if ( ! V_105 ) {
F_9 ( V_34 , L_57 ) ;
return - V_86 ;
}
V_105 -> V_273 = L_70 ;
V_105 -> V_282 = V_31 -> V_282 ;
V_105 -> V_112 . V_283 = V_284 ;
V_105 -> V_34 . V_285 = V_34 ;
V_105 -> V_286 = V_287 ;
V_105 -> V_288 = V_289 ;
F_78 ( V_105 , V_279 , V_290 ) ;
F_82 ( V_105 , V_276 , 0 , V_31 -> V_118 , 0 , 0 ) ;
F_82 ( V_105 , V_278 , 0 , V_31 -> V_119 , 0 , 0 ) ;
if ( V_31 -> V_239 == V_9 ||
( V_31 -> V_239 == V_13 &&
V_31 -> V_149 ) ) {
F_82 ( V_105 , V_291 , 0 , 255 , 0 , 0 ) ;
}
if ( V_108 -> V_109 ) {
F_75 ( V_105 , V_31 ) ;
V_281 |= V_292 ;
} else {
V_281 |= V_293 ;
}
error = F_83 ( V_105 , V_280 , V_281 ) ;
if ( error ) {
F_9 ( V_34 , L_71 , error ) ;
goto V_294;
}
if ( V_31 -> V_239 == V_13 ) {
F_82 ( V_105 , V_295 ,
0 , V_296 , 0 , 0 ) ;
F_82 ( V_105 , V_155 ,
V_147 ,
V_143 ,
0 , 0 ) ;
}
F_82 ( V_105 , V_129 ,
0 , V_31 -> V_118 , 0 , 0 ) ;
F_82 ( V_105 , V_130 ,
0 , V_31 -> V_119 , 0 , 0 ) ;
if ( V_31 -> V_239 == V_9 ||
( V_31 -> V_239 == V_13 &&
V_31 -> V_148 ) ) {
F_82 ( V_105 , V_132 ,
0 , V_297 , 0 , 0 ) ;
}
if ( V_31 -> V_239 == V_9 ||
( V_31 -> V_239 == V_13 &&
V_31 -> V_149 ) ) {
F_82 ( V_105 , V_131 ,
0 , 255 , 0 , 0 ) ;
}
if ( V_31 -> V_239 == V_13 &&
V_31 -> V_144 ) {
F_82 ( V_105 , V_156 ,
0 , 255 , 0 , 0 ) ;
}
if ( V_31 -> V_239 == V_13 &&
V_31 -> V_149 ) {
F_82 ( V_105 , V_131 ,
0 , 255 , 0 , 0 ) ;
}
if ( V_31 -> V_239 == V_13 &&
V_31 -> V_144 ) {
F_82 ( V_105 , V_156 ,
0 , 255 , 0 , 0 ) ;
}
F_84 ( V_105 , V_31 ) ;
error = F_85 ( V_105 ) ;
if ( error ) {
F_9 ( V_34 , L_72 , error ) ;
goto V_294;
}
V_31 -> V_105 = V_105 ;
return 0 ;
V_294:
F_86 ( V_105 ) ;
return error ;
}
static void F_87 ( const struct V_203 * V_204 , void * V_298 )
{
F_88 ( V_298 , V_204 ) ;
F_89 ( V_204 ) ;
}
static int F_90 ( struct V_30 * V_31 )
{
struct V_82 * V_33 = V_31 -> V_33 ;
int V_299 = 0 ;
int error ;
while ( 1 ) {
error = F_63 ( V_31 ) ;
if ( ! error )
break;
error = F_14 ( V_31 , false ) ;
if ( error ) {
F_52 ( & V_33 -> V_34 , L_73 ) ;
error = F_14 ( V_31 , true ) ;
if ( error ) {
return error ;
}
}
if ( ++ V_299 > 1 ) {
F_9 ( & V_33 -> V_34 , L_74 ) ;
V_31 -> V_182 = true ;
return 0 ;
}
F_17 ( V_31 , false ) ;
F_48 ( V_300 ) ;
}
error = F_70 ( V_31 ) ;
if ( error ) {
F_9 ( & V_33 -> V_34 , L_75 , error ) ;
return error ;
}
error = F_49 ( V_31 ) ;
if ( error )
goto V_301;
error = F_91 ( V_302 , true , V_303 ,
& V_33 -> V_34 , V_85 , V_31 ,
F_87 ) ;
if ( error ) {
F_9 ( & V_33 -> V_34 , L_76 ,
error ) ;
goto V_301;
}
return 0 ;
V_301:
F_66 ( V_31 ) ;
return error ;
}
static int F_92 ( struct V_30 * V_31 , T_2 V_304 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
int error ;
struct V_305 * V_306 ;
struct V_305 V_307 = { . V_308 = 0 , . V_309 = 0 } ;
if ( V_304 == V_310 )
V_306 = & V_307 ;
else
V_306 = & V_31 -> V_311 ;
error = F_19 ( V_31 -> V_33 , V_31 -> V_225 ,
sizeof( V_31 -> V_311 ) , V_306 ) ;
if ( error )
return error ;
F_5 ( V_34 , L_77 ,
V_306 -> V_308 , V_306 -> V_309 ) ;
return 0 ;
}
static int F_62 ( struct V_30 * V_31 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
int error ;
bool V_57 = false ;
V_71:
error = F_18 ( V_31 -> V_33 , V_31 -> V_225 ,
sizeof( V_31 -> V_311 ) , & V_31 -> V_311 ) ;
if ( error )
return error ;
if ( V_31 -> V_311 . V_308 == 0 || V_31 -> V_311 . V_309 == 0 ) {
if ( ! V_57 ) {
F_5 ( V_34 , L_78 ) ;
F_51 ( V_31 ) ;
V_57 = true ;
goto V_71;
} else {
F_5 ( V_34 , L_79 ) ;
V_31 -> V_311 . V_308 = 20 ;
V_31 -> V_311 . V_309 = 100 ;
return F_92 ( V_31 , V_312 ) ;
}
}
F_5 ( V_34 , L_80 ,
V_31 -> V_311 . V_308 , V_31 -> V_311 . V_309 ) ;
return 0 ;
}
static T_3 F_93 ( struct V_30 * V_31 , unsigned int V_113 ,
unsigned int V_114 )
{
struct V_214 * V_60 = & V_31 -> V_60 ;
struct V_313 * V_228 = & V_31 -> V_228 ;
unsigned int V_314 , V_315 ;
unsigned int V_316 = 0 ;
unsigned int V_317 ;
if ( V_60 -> V_61 == V_318 ) {
V_317 = V_60 -> V_319 / V_320 ;
V_316 = V_114 / V_317 ;
V_114 = V_114 % V_317 ;
} else {
V_317 = V_60 -> V_319 ;
}
V_314 = ( V_114 + ( V_113 * V_317 ) ) * sizeof( T_3 ) ;
V_315 = V_314 / V_321 ;
V_314 %= V_321 ;
if ( V_60 -> V_61 == V_318 )
V_315 += V_316 * V_322 ;
return F_40 ( & V_228 -> V_323 [ V_315 ] . V_31 [ V_314 ] ) ;
}
static int F_94 ( struct V_30 * V_31 , T_3 * V_324 )
{
struct V_313 * V_228 = & V_31 -> V_228 ;
unsigned int V_113 = 0 ;
unsigned int V_114 = 0 ;
unsigned int V_88 , V_325 , V_326 ;
for ( V_88 = 0 ; V_88 < V_228 -> V_327 ; V_88 ++ ) {
V_325 = V_31 -> V_251 ? V_114 : V_113 ;
V_326 = V_31 -> V_251 ? V_113 : V_114 ;
V_325 = V_31 -> V_253 ? ( V_31 -> V_246 - 1 - V_325 ) : V_325 ;
V_326 = V_31 -> V_255 ? ( V_31 -> V_248 - 1 - V_326 ) : V_326 ;
V_324 [ V_88 ] = F_93 ( V_31 , V_325 , V_326 ) ;
if ( ++ V_113 >= ( V_31 -> V_251 ? V_31 -> V_248 : V_31 -> V_246 ) ) {
V_113 = 0 ;
V_114 ++ ;
}
}
return 0 ;
}
static int F_95 ( struct V_30 * V_31 , T_2 V_328 ,
T_3 * V_324 )
{
struct V_313 * V_228 = & V_31 -> V_228 ;
int V_329 = 0 ;
int V_315 ;
int V_41 ;
T_2 V_191 = V_328 ;
struct V_330 * V_331 ;
T_2 V_332 ;
for ( V_315 = 0 ; V_315 < V_228 -> V_333 ; V_315 ++ ) {
V_331 = V_228 -> V_323 + V_315 ;
V_41 = F_23 ( V_31 -> V_33 , V_228 -> V_334 ,
V_191 ) ;
if ( V_41 )
return V_41 ;
V_329 = 0 ;
F_48 ( 20 ) ;
V_335:
V_41 = F_18 ( V_31 -> V_33 , V_228 -> V_334 ,
sizeof( V_332 ) , & V_332 ) ;
if ( V_41 )
return V_41 ;
if ( V_332 ) {
if ( V_329 ++ > 100 )
return - V_62 ;
F_48 ( 20 ) ;
goto V_335;
}
V_41 = F_18 ( V_31 -> V_33 , V_228 -> V_336 ,
sizeof( struct V_330 ) , V_331 ) ;
if ( V_41 )
return V_41 ;
if ( V_331 -> V_328 != V_328 || V_331 -> V_315 != V_315 ) {
F_9 ( & V_31 -> V_33 -> V_34 , L_81 ) ;
return - V_62 ;
}
F_5 ( & V_31 -> V_33 -> V_34 , L_82 ,
V_56 , V_315 , V_329 ) ;
V_191 = V_337 ;
}
return F_94 ( V_31 , V_324 ) ;
}
static int F_96 ( struct V_338 * V_339 ,
unsigned int * V_340 , unsigned int * V_341 ,
unsigned int V_342 [] , struct V_39 * V_343 [] )
{
struct V_30 * V_31 = V_339 -> V_344 ;
T_1 V_210 = V_31 -> V_228 . V_327 * sizeof( T_3 ) ;
if ( * V_341 )
return V_342 [ 0 ] < V_210 ? - V_62 : 0 ;
* V_341 = 1 ;
V_342 [ 0 ] = V_210 ;
return 0 ;
}
static void F_97 ( struct V_345 * V_346 )
{
struct V_30 * V_31 = F_98 ( V_346 -> V_338 ) ;
T_3 * V_201 ;
int V_41 ;
T_2 V_328 ;
V_201 = F_99 ( V_346 , 0 ) ;
if ( ! V_201 ) {
F_9 ( & V_31 -> V_33 -> V_34 , L_83 ) ;
goto V_347;
}
switch ( V_31 -> V_228 . V_106 ) {
case V_348 :
default:
V_328 = V_349 ;
break;
case V_350 :
V_328 = V_351 ;
break;
}
V_41 = F_95 ( V_31 , V_328 , V_201 ) ;
if ( V_41 )
goto V_347;
F_100 ( V_346 , 0 , V_31 -> V_228 . V_327 * sizeof( T_3 ) ) ;
F_101 ( V_346 , V_352 ) ;
return;
V_347:
F_101 ( V_346 , V_353 ) ;
}
static int F_102 ( struct V_354 * V_354 , void * V_355 ,
struct V_356 * V_357 )
{
struct V_30 * V_31 = F_103 ( V_354 ) ;
F_104 ( V_357 -> V_358 , L_84 , sizeof( V_357 -> V_358 ) ) ;
F_104 ( V_357 -> V_359 , L_85 , sizeof( V_357 -> V_359 ) ) ;
snprintf ( V_357 -> V_360 , sizeof( V_357 -> V_360 ) ,
L_86 , F_105 ( & V_31 -> V_33 -> V_34 ) ) ;
return 0 ;
}
static int F_106 ( struct V_354 * V_354 , void * V_355 ,
struct V_361 * V_88 )
{
if ( V_88 -> V_362 >= V_363 )
return - V_62 ;
V_88 -> type = V_364 ;
switch ( V_88 -> V_362 ) {
case V_350 :
F_104 ( V_88 -> V_273 , L_87 ,
sizeof( V_88 -> V_273 ) ) ;
break;
case V_348 :
F_104 ( V_88 -> V_273 , L_88 , sizeof( V_88 -> V_273 ) ) ;
break;
}
return 0 ;
}
static int F_107 ( struct V_30 * V_31 , unsigned int V_88 )
{
struct V_365 * V_366 = & V_31 -> V_228 . V_367 ;
if ( V_88 >= V_363 )
return - V_62 ;
if ( V_88 == V_348 )
V_366 -> V_368 = V_369 ;
else
V_366 -> V_368 = V_370 ;
V_366 -> V_371 = V_31 -> V_251 ? V_31 -> V_248 : V_31 -> V_246 ;
V_366 -> V_372 = V_31 -> V_251 ? V_31 -> V_246 : V_31 -> V_248 ;
V_366 -> V_373 = V_374 ;
V_366 -> V_375 = V_376 ;
V_366 -> V_377 = V_366 -> V_371 * sizeof( T_3 ) ;
V_366 -> V_378 = V_366 -> V_371 * V_366 -> V_372 * sizeof( T_3 ) ;
V_31 -> V_228 . V_106 = V_88 ;
return 0 ;
}
static int F_108 ( struct V_354 * V_354 , void * V_355 , unsigned int V_88 )
{
return F_107 ( F_103 ( V_354 ) , V_88 ) ;
}
static int F_109 ( struct V_354 * V_354 , void * V_355 , unsigned int * V_88 )
{
struct V_30 * V_31 = F_103 ( V_354 ) ;
* V_88 = V_31 -> V_228 . V_106 ;
return 0 ;
}
static int F_110 ( struct V_354 * V_354 , void * V_355 , struct V_379 * V_366 )
{
struct V_30 * V_31 = F_103 ( V_354 ) ;
V_366 -> type = V_380 ;
V_366 -> V_381 . V_382 = V_31 -> V_228 . V_367 ;
return 0 ;
}
static int F_111 ( struct V_354 * V_354 , void * V_355 ,
struct V_383 * V_381 )
{
if ( V_381 -> type != V_380 )
return - V_62 ;
switch ( V_381 -> V_362 ) {
case 0 :
V_381 -> V_368 = V_370 ;
break;
case 1 :
V_381 -> V_368 = V_369 ;
break;
default:
return - V_62 ;
}
return 0 ;
}
static int F_112 ( struct V_354 * V_354 , void * V_384 ,
struct V_385 * V_386 )
{
if ( V_386 -> type != V_380 )
return - V_62 ;
V_386 -> V_387 . V_388 . V_389 = 1 ;
V_386 -> V_387 . V_388 . V_390 . V_391 = 1 ;
V_386 -> V_387 . V_388 . V_390 . V_392 = 10 ;
return 0 ;
}
static void F_113 ( struct V_30 * V_31 )
{
struct V_214 * V_60 = & V_31 -> V_60 ;
struct V_313 * V_228 = & V_31 -> V_228 ;
struct V_1 * V_87 ;
int error ;
V_87 = F_24 ( V_31 , V_5 ) ;
if ( ! V_87 )
goto error;
V_228 -> V_334 = V_87 -> V_104 + V_393 ;
V_87 = F_24 ( V_31 , V_394 ) ;
if ( ! V_87 )
goto error;
if ( F_1 ( V_87 ) != sizeof( struct V_330 ) ) {
F_25 ( & V_31 -> V_33 -> V_34 , L_89 ) ;
goto error;
}
V_228 -> V_336 = V_87 -> V_104 ;
V_228 -> V_327 = V_31 -> V_246 * V_31 -> V_248 ;
if ( V_60 -> V_61 == V_318 )
V_228 -> V_333 = V_320 * V_322 ;
else
V_228 -> V_333 = F_114 ( V_31 -> V_246 *
V_60 -> V_319 *
sizeof( T_3 ) ,
sizeof( V_228 -> V_323 -> V_31 ) ) ;
V_228 -> V_323 = F_115 ( & V_31 -> V_33 -> V_34 , V_228 -> V_333 ,
sizeof( struct V_330 ) , V_85 ) ;
if ( ! V_228 -> V_323 )
goto error;
F_107 ( V_31 , 0 ) ;
snprintf ( V_228 -> V_230 . V_273 , sizeof( V_228 -> V_230 . V_273 ) , L_90 , L_84 ) ;
error = F_116 ( & V_31 -> V_33 -> V_34 , & V_228 -> V_230 ) ;
if ( error )
goto error;
F_117 ( & V_228 -> V_395 ) ;
V_228 -> V_396 = V_397 ;
V_228 -> V_396 . V_344 = V_31 ;
V_228 -> V_396 . V_395 = & V_228 -> V_395 ;
V_228 -> V_396 . V_34 = & V_31 -> V_33 -> V_34 ;
error = F_118 ( & V_228 -> V_396 ) ;
if ( error )
goto V_398;
V_228 -> V_229 = V_399 ;
V_228 -> V_229 . V_400 = & V_228 -> V_230 ;
V_228 -> V_229 . V_395 = & V_228 -> V_395 ;
V_228 -> V_229 . V_401 = V_402 ;
V_228 -> V_229 . V_396 = & V_228 -> V_396 ;
F_119 ( & V_228 -> V_229 , V_31 ) ;
error = F_120 ( & V_228 -> V_229 , V_403 , - 1 ) ;
if ( error )
goto V_398;
return;
V_398:
F_69 ( & V_228 -> V_230 ) ;
error:
F_25 ( & V_31 -> V_33 -> V_34 , L_91 ) ;
}
static void F_113 ( struct V_30 * V_31 )
{
}
static int F_88 ( struct V_30 * V_31 ,
const struct V_203 * V_204 )
{
struct V_39 * V_34 = & V_31 -> V_33 -> V_34 ;
struct V_214 * V_60 = & V_31 -> V_60 ;
int error ;
error = F_62 ( V_31 ) ;
if ( error ) {
F_9 ( V_34 , L_92 ) ;
return error ;
}
if ( V_204 ) {
error = F_60 ( V_31 , V_204 ) ;
if ( error )
F_25 ( V_34 , L_93 , error ) ;
}
if ( V_31 -> V_239 ) {
error = F_79 ( V_31 ) ;
if ( error )
return error ;
} else {
F_25 ( V_34 , L_94 ) ;
}
F_113 ( V_31 ) ;
F_52 ( V_34 ,
L_95 ,
V_60 -> V_61 , V_60 -> V_220 , V_60 -> V_238 >> 4 ,
V_60 -> V_238 & 0xf , V_60 -> V_404 , V_60 -> V_89 ) ;
return 0 ;
}
static T_7 F_121 ( struct V_39 * V_34 ,
struct V_405 * V_406 , char * V_53 )
{
struct V_30 * V_31 = F_122 ( V_34 ) ;
struct V_214 * V_60 = & V_31 -> V_60 ;
return F_123 ( V_53 , V_407 , L_96 ,
V_60 -> V_238 >> 4 , V_60 -> V_238 & 0xf , V_60 -> V_404 ) ;
}
static T_7 F_124 ( struct V_39 * V_34 ,
struct V_405 * V_406 , char * V_53 )
{
struct V_30 * V_31 = F_122 ( V_34 ) ;
struct V_214 * V_60 = & V_31 -> V_60 ;
return F_123 ( V_53 , V_407 , L_97 ,
V_60 -> V_61 , V_60 -> V_220 ) ;
}
static T_7 F_125 ( char * V_53 , int V_44 ,
struct V_1 * V_87 , int V_209 ,
const T_2 * V_43 )
{
int V_88 ;
if ( F_2 ( V_87 ) > 1 )
V_44 += F_123 ( V_53 + V_44 , V_407 - V_44 ,
L_98 , V_209 ) ;
for ( V_88 = 0 ; V_88 < F_1 ( V_87 ) ; V_88 ++ )
V_44 += F_123 ( V_53 + V_44 , V_407 - V_44 ,
L_99 , V_88 , V_43 [ V_88 ] , V_43 [ V_88 ] ) ;
V_44 += F_123 ( V_53 + V_44 , V_407 - V_44 , L_100 ) ;
return V_44 ;
}
static T_7 F_126 ( struct V_39 * V_34 ,
struct V_405 * V_406 , char * V_53 )
{
struct V_30 * V_31 = F_122 ( V_34 ) ;
struct V_1 * V_87 ;
int V_44 = 0 ;
int V_88 , V_408 ;
int error ;
T_2 * V_409 ;
V_409 = F_20 ( 256 , V_85 ) ;
if ( ! V_409 )
return - V_86 ;
error = 0 ;
for ( V_88 = 0 ; V_88 < V_31 -> V_60 . V_89 ; V_88 ++ ) {
V_87 = V_31 -> V_90 + V_88 ;
if ( ! F_3 ( V_87 -> type ) )
continue;
V_44 += F_123 ( V_53 + V_44 , V_407 - V_44 ,
L_101 , V_87 -> type ) ;
for ( V_408 = 0 ; V_408 < F_2 ( V_87 ) ; V_408 ++ ) {
T_3 V_210 = F_1 ( V_87 ) ;
T_3 V_47 = V_87 -> V_104 + V_408 * V_210 ;
error = F_18 ( V_31 -> V_33 , V_47 , V_210 , V_409 ) ;
if ( error )
goto V_410;
V_44 = F_125 ( V_53 , V_44 , V_87 , V_408 , V_409 ) ;
}
}
V_410:
F_22 ( V_409 ) ;
return error ? : V_44 ;
}
static int F_127 ( struct V_39 * V_34 ,
const struct V_203 * V_411 )
{
unsigned int V_412 = 0 ;
char V_413 ;
while ( V_412 < V_411 -> V_210 ) {
V_413 = * ( V_411 -> V_31 + V_412 ) ;
if ( V_413 < '0' || ( V_413 > '9' && V_413 < 'A' ) || V_413 > 'F' )
return 0 ;
V_412 ++ ;
}
F_9 ( V_34 , L_102 ) ;
return - V_62 ;
}
static int F_128 ( struct V_39 * V_34 , const char * V_414 )
{
struct V_30 * V_31 = F_122 ( V_34 ) ;
const struct V_203 * V_411 = NULL ;
unsigned int V_415 ;
unsigned int V_412 = 0 ;
unsigned int V_57 = 0 ;
unsigned int V_416 = 0 ;
int V_41 ;
V_41 = F_129 ( & V_411 , V_414 , V_34 ) ;
if ( V_41 ) {
F_9 ( V_34 , L_103 , V_414 ) ;
return V_41 ;
}
V_41 = F_127 ( V_34 , V_411 ) ;
if ( V_41 )
goto F_89;
if ( ! V_31 -> V_182 ) {
V_31 -> V_182 = true ;
V_41 = F_47 ( V_31 , V_188 ,
V_417 , false ) ;
if ( V_41 )
goto F_89;
F_48 ( V_418 ) ;
V_41 = F_13 ( V_31 , 0 ) ;
if ( V_41 )
goto F_89;
F_64 ( V_31 ) ;
F_66 ( V_31 ) ;
} else {
F_50 ( V_31 -> V_180 ) ;
}
F_54 ( & V_31 -> V_72 ) ;
V_41 = F_16 ( V_31 , V_74 , false ) ;
if ( V_41 ) {
V_41 = F_16 ( V_31 , V_75 , false ) ;
if ( V_41 )
goto F_53;
} else {
F_52 ( V_34 , L_104 ) ;
V_41 = F_17 ( V_31 , true ) ;
if ( V_41 )
goto F_53;
}
while ( V_412 < V_411 -> V_210 ) {
V_41 = F_16 ( V_31 , V_75 , true ) ;
if ( V_41 )
goto F_53;
V_415 = ( ( * ( V_411 -> V_31 + V_412 ) << 8 ) | * ( V_411 -> V_31 + V_412 + 1 ) ) ;
V_415 += 2 ;
V_41 = F_12 ( V_31 , V_411 -> V_31 + V_412 , V_415 ) ;
if ( V_41 )
goto F_53;
V_41 = F_16 ( V_31 , V_76 , true ) ;
if ( V_41 ) {
V_57 ++ ;
F_48 ( V_57 * 20 ) ;
if ( V_57 > 20 ) {
F_9 ( V_34 , L_105 ) ;
goto F_53;
}
} else {
V_57 = 0 ;
V_412 += V_415 ;
V_416 ++ ;
}
if ( V_416 % 50 == 0 )
F_5 ( V_34 , L_106 ,
V_416 , V_412 , V_411 -> V_210 ) ;
}
V_41 = F_6 ( V_31 , & V_31 -> V_72 ,
V_300 ) ;
if ( V_41 )
goto F_53;
F_5 ( V_34 , L_107 , V_416 , V_412 ) ;
F_6 ( V_31 , & V_31 -> V_72 , V_300 ) ;
V_31 -> V_182 = false ;
F_53:
F_53 ( V_31 -> V_180 ) ;
F_89:
F_89 ( V_411 ) ;
return V_41 ;
}
static T_7 F_130 ( struct V_39 * V_34 ,
struct V_405 * V_406 ,
const char * V_53 , T_1 V_44 )
{
struct V_30 * V_31 = F_122 ( V_34 ) ;
int error ;
error = F_128 ( V_34 , V_419 ) ;
if ( error ) {
F_9 ( V_34 , L_108 , error ) ;
V_44 = error ;
} else {
F_52 ( V_34 , L_109 ) ;
error = F_90 ( V_31 ) ;
if ( error )
return error ;
}
return V_44 ;
}
static void F_131 ( struct V_30 * V_31 )
{
switch ( V_31 -> V_108 -> V_420 ) {
case V_421 :
F_51 ( V_31 ) ;
F_28 ( V_31 ,
V_9 , V_422 , 0x83 ) ;
break;
case V_423 :
default:
F_92 ( V_31 , V_312 ) ;
F_47 ( V_31 , V_424 , 1 , false ) ;
break;
}
}
static void F_132 ( struct V_30 * V_31 )
{
switch ( V_31 -> V_108 -> V_420 ) {
case V_421 :
F_28 ( V_31 ,
V_9 , V_422 , 0 ) ;
break;
case V_423 :
default:
F_92 ( V_31 , V_310 ) ;
break;
}
}
static int V_287 ( struct V_105 * V_34 )
{
struct V_30 * V_31 = F_133 ( V_34 ) ;
F_131 ( V_31 ) ;
return 0 ;
}
static void V_289 ( struct V_105 * V_34 )
{
struct V_30 * V_31 = F_133 ( V_34 ) ;
F_132 ( V_31 ) ;
}
static const struct V_107 * F_134 ( struct V_82 * V_33 )
{
struct V_107 * V_108 ;
struct V_425 * V_426 = V_33 -> V_34 . V_427 ;
T_4 * V_428 ;
int V_429 , V_41 ;
if ( ! V_426 )
return F_135 ( - V_430 ) ;
V_108 = F_136 ( & V_33 -> V_34 , sizeof( * V_108 ) , V_85 ) ;
if ( ! V_108 )
return F_135 ( - V_86 ) ;
if ( F_137 ( V_426 , L_110 , & V_429 ) ) {
V_108 -> V_109 = V_429 / sizeof( T_4 ) ;
V_428 = F_136 ( & V_33 -> V_34 ,
V_108 -> V_109 * sizeof( V_428 [ 0 ] ) ,
V_85 ) ;
if ( ! V_428 )
return F_135 ( - V_86 ) ;
V_41 = F_138 ( V_426 , L_110 ,
V_428 , V_108 -> V_109 ) ;
if ( V_41 )
F_25 ( & V_33 -> V_34 ,
L_111 , V_41 ) ;
V_108 -> V_110 = V_428 ;
}
V_108 -> V_420 = V_423 ;
return V_108 ;
}
static const struct V_107 * F_134 ( struct V_82 * V_33 )
{
return F_135 ( - V_430 ) ;
}
static const struct V_107 * F_139 ( struct V_82 * V_33 )
{
struct V_431 * V_432 ;
const struct V_433 * V_434 ;
const struct V_435 * V_436 ;
if ( V_33 -> V_47 < 0x40 )
return F_135 ( - V_437 ) ;
V_432 = F_140 ( & V_33 -> V_34 ) ;
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
return & V_436 -> V_108 ;
V_436 ++ ;
}
return F_135 ( - V_430 ) ;
}
static const struct V_107 * F_139 ( struct V_82 * V_33 )
{
return F_135 ( - V_430 ) ;
}
static const struct V_107 *
F_143 ( struct V_82 * V_33 )
{
const struct V_107 * V_108 ;
V_108 = F_144 ( & V_33 -> V_34 ) ;
if ( V_108 )
return V_108 ;
V_108 = F_134 ( V_33 ) ;
if ( ! F_145 ( V_108 ) || F_146 ( V_108 ) != - V_430 )
return V_108 ;
V_108 = F_139 ( V_33 ) ;
if ( ! F_145 ( V_108 ) || F_146 ( V_108 ) != - V_430 )
return V_108 ;
F_9 ( & V_33 -> V_34 , L_112 ) ;
return F_135 ( - V_62 ) ;
}
static int F_147 ( struct V_82 * V_33 , const struct V_441 * V_112 )
{
struct V_30 * V_31 ;
const struct V_107 * V_108 ;
int error ;
V_108 = F_143 ( V_33 ) ;
if ( F_145 ( V_108 ) )
return F_146 ( V_108 ) ;
V_31 = F_136 ( & V_33 -> V_34 , sizeof( struct V_30 ) , V_85 ) ;
if ( ! V_31 )
return - V_86 ;
snprintf ( V_31 -> V_282 , sizeof( V_31 -> V_282 ) , L_113 ,
V_33 -> V_54 -> V_442 , V_33 -> V_47 ) ;
V_31 -> V_33 = V_33 ;
V_31 -> V_108 = V_108 ;
V_31 -> V_180 = V_33 -> V_180 ;
F_148 ( V_33 , V_31 ) ;
F_149 ( & V_31 -> V_72 ) ;
F_149 ( & V_31 -> V_96 ) ;
F_149 ( & V_31 -> V_93 ) ;
V_31 -> V_443 = F_150 ( & V_33 -> V_34 ,
L_114 , V_444 ) ;
if ( F_145 ( V_31 -> V_443 ) ) {
error = F_146 ( V_31 -> V_443 ) ;
F_9 ( & V_33 -> V_34 , L_115 , error ) ;
return error ;
}
error = F_151 ( & V_33 -> V_34 , V_33 -> V_180 ,
NULL , F_46 ,
V_108 -> V_445 | V_446 ,
V_33 -> V_273 , V_31 ) ;
if ( error ) {
F_9 ( & V_33 -> V_34 , L_116 ) ;
return error ;
}
if ( V_31 -> V_443 ) {
V_31 -> V_182 = true ;
F_48 ( V_418 ) ;
F_54 ( & V_31 -> V_72 ) ;
F_152 ( V_31 -> V_443 , 1 ) ;
error = F_6 ( V_31 , & V_31 -> V_72 ,
V_190 ) ;
if ( error )
return error ;
V_31 -> V_182 = false ;
}
F_53 ( V_33 -> V_180 ) ;
error = F_90 ( V_31 ) ;
if ( error )
return error ;
error = F_153 ( & V_33 -> V_34 . V_447 , & V_448 ) ;
if ( error ) {
F_9 ( & V_33 -> V_34 , L_117 ,
error ) ;
goto V_449;
}
return 0 ;
V_449:
F_64 ( V_31 ) ;
F_66 ( V_31 ) ;
return error ;
}
static int F_154 ( struct V_82 * V_33 )
{
struct V_30 * V_31 = F_155 ( V_33 ) ;
F_53 ( V_31 -> V_180 ) ;
F_156 ( & V_33 -> V_34 . V_447 , & V_448 ) ;
F_64 ( V_31 ) ;
F_66 ( V_31 ) ;
return 0 ;
}
static int T_8 F_157 ( struct V_39 * V_34 )
{
struct V_82 * V_33 = F_158 ( V_34 ) ;
struct V_30 * V_31 = F_155 ( V_33 ) ;
struct V_105 * V_105 = V_31 -> V_105 ;
if ( ! V_105 )
return 0 ;
F_159 ( & V_105 -> V_450 ) ;
if ( V_105 -> V_451 )
F_132 ( V_31 ) ;
F_160 ( & V_105 -> V_450 ) ;
return 0 ;
}
static int T_8 F_161 ( struct V_39 * V_34 )
{
struct V_82 * V_33 = F_158 ( V_34 ) ;
struct V_30 * V_31 = F_155 ( V_33 ) ;
struct V_105 * V_105 = V_31 -> V_105 ;
if ( ! V_105 )
return 0 ;
F_159 ( & V_105 -> V_450 ) ;
if ( V_105 -> V_451 )
F_131 ( V_31 ) ;
F_160 ( & V_105 -> V_450 ) ;
return 0 ;
}
