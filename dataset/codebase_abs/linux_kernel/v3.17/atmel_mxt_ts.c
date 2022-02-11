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
static void F_28 ( struct V_29 * V_30 , T_2 * V_31 )
{
struct V_102 * V_103 = V_30 -> V_102 ;
const struct V_104 * V_105 = V_30 -> V_105 ;
bool V_106 ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_105 -> V_107 ; V_87 ++ ) {
if ( V_105 -> V_108 [ V_87 ] == V_109 )
continue;
V_106 = ! ( V_31 [ 1 ] & ( 1 << V_87 ) ) ;
F_29 ( V_103 , V_105 -> V_108 [ V_87 ] , V_106 ) ;
}
}
static void F_30 ( struct V_29 * V_30 )
{
F_31 ( V_30 -> V_102 ,
V_30 -> V_105 -> V_107 ) ;
F_32 ( V_30 -> V_102 ) ;
}
static void F_33 ( struct V_29 * V_30 , T_2 * V_31 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_102 * V_102 = V_30 -> V_102 ;
int V_110 ;
T_2 V_90 ;
int V_111 ;
int V_112 ;
int V_113 ;
int V_114 ;
V_110 = V_31 [ 0 ] - V_30 -> V_115 ;
V_90 = V_31 [ 1 ] ;
V_111 = ( V_31 [ 2 ] << 4 ) | ( ( V_31 [ 4 ] >> 4 ) & 0xf ) ;
V_112 = ( V_31 [ 3 ] << 4 ) | ( ( V_31 [ 4 ] & 0xf ) ) ;
if ( V_30 -> V_116 < 1024 )
V_111 >>= 2 ;
if ( V_30 -> V_117 < 1024 )
V_112 >>= 2 ;
V_113 = V_31 [ 5 ] ;
V_114 = V_31 [ 6 ] ;
F_5 ( V_33 ,
L_26 ,
V_110 ,
( V_90 & V_118 ) ? 'D' : '.' ,
( V_90 & V_119 ) ? 'P' : '.' ,
( V_90 & V_120 ) ? 'R' : '.' ,
( V_90 & V_121 ) ? 'M' : '.' ,
( V_90 & V_122 ) ? 'V' : '.' ,
( V_90 & V_123 ) ? 'A' : '.' ,
( V_90 & V_124 ) ? 'S' : '.' ,
( V_90 & V_125 ) ? 'U' : '.' ,
V_111 , V_112 , V_113 , V_114 ) ;
F_34 ( V_102 , V_110 ) ;
if ( V_90 & V_118 ) {
if ( V_90 & V_120 ) {
F_35 ( V_102 ,
V_126 , 0 ) ;
F_30 ( V_30 ) ;
}
F_35 ( V_102 , V_126 , 1 ) ;
F_36 ( V_102 , V_127 , V_111 ) ;
F_36 ( V_102 , V_128 , V_112 ) ;
F_36 ( V_102 , V_129 , V_114 ) ;
F_36 ( V_102 , V_130 , V_113 ) ;
} else {
F_35 ( V_102 , V_126 , 0 ) ;
}
V_30 -> V_131 = true ;
}
static int F_37 ( struct V_29 * V_30 , T_2 * V_31 )
{
T_2 V_132 = V_31 [ 0 ] ;
if ( V_132 == V_133 )
return 0 ;
if ( V_132 == V_30 -> V_134 ) {
F_26 ( V_30 , V_31 ) ;
} else if ( ! V_30 -> V_102 ) {
F_4 ( V_30 , V_31 ) ;
} else if ( V_132 >= V_30 -> V_115
&& V_132 <= V_30 -> V_135 ) {
F_33 ( V_30 , V_31 ) ;
} else if ( V_132 == V_30 -> V_136 ) {
F_28 ( V_30 , V_31 ) ;
V_30 -> V_131 = true ;
} else {
F_4 ( V_30 , V_31 ) ;
}
return 1 ;
}
static int F_38 ( struct V_29 * V_30 , T_2 V_43 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_40 ;
int V_87 ;
T_2 V_137 = 0 ;
if ( V_43 > V_30 -> V_138 )
return - V_61 ;
V_40 = F_18 ( V_30 -> V_32 , V_30 -> V_139 ,
V_30 -> V_34 * V_43 , V_30 -> V_140 ) ;
if ( V_40 ) {
F_9 ( V_33 , L_27 , V_43 , V_40 ) ;
return V_40 ;
}
for ( V_87 = 0 ; V_87 < V_43 ; V_87 ++ ) {
V_40 = F_37 ( V_30 ,
V_30 -> V_140 + V_30 -> V_34 * V_87 ) ;
if ( V_40 == 1 )
V_137 ++ ;
}
return V_137 ;
}
static T_5 F_39 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_40 ;
T_2 V_43 , V_141 ;
V_40 = F_18 ( V_30 -> V_32 , V_30 -> V_142 ,
V_30 -> V_34 + 1 , V_30 -> V_140 ) ;
if ( V_40 ) {
F_9 ( V_33 , L_28 , V_40 ) ;
return V_143 ;
}
V_43 = V_30 -> V_140 [ 0 ] ;
if ( V_43 == 0 ) {
F_5 ( V_33 , L_29 ) ;
return V_143 ;
} else if ( V_43 > V_30 -> V_138 ) {
F_9 ( V_33 , L_30 , V_43 ) ;
V_43 = V_30 -> V_138 ;
}
V_40 = F_37 ( V_30 , V_30 -> V_140 + 1 ) ;
if ( V_40 < 0 ) {
F_25 ( V_33 , L_31 ) ;
return V_143 ;
}
V_141 = V_43 - 1 ;
if ( V_141 ) {
V_40 = F_38 ( V_30 , V_141 ) ;
if ( V_40 < 0 )
goto V_144;
else if ( V_40 != V_141 )
F_25 ( V_33 , L_31 ) ;
}
V_144:
if ( V_30 -> V_131 ) {
F_30 ( V_30 ) ;
V_30 -> V_131 = false ;
}
return V_145 ;
}
static int F_40 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_43 , V_146 ;
T_2 V_147 = 2 ;
V_43 = V_30 -> V_138 ;
do {
V_146 = F_38 ( V_30 , V_43 ) ;
if ( V_146 < V_43 )
return 0 ;
} while ( -- V_147 );
if ( V_30 -> V_131 ) {
F_30 ( V_30 ) ;
V_30 -> V_131 = false ;
}
F_9 ( V_33 , L_32 ) ;
return - V_148 ;
}
static T_5 F_41 ( struct V_29 * V_30 )
{
int V_149 , V_150 ;
T_2 V_43 = V_30 -> V_151 ;
if ( V_43 < 1 || V_43 > V_30 -> V_138 )
V_43 = 1 ;
V_149 = F_38 ( V_30 , V_43 + 1 ) ;
if ( V_149 < 0 )
return V_143 ;
else if ( V_149 <= V_43 )
goto V_152;
do {
V_150 = F_38 ( V_30 , 2 ) ;
if ( V_150 < 0 )
return V_143 ;
V_149 += V_150 ;
if ( V_150 < 2 )
break;
} while ( V_149 < V_30 -> V_153 );
V_152:
V_30 -> V_151 = V_149 ;
if ( V_30 -> V_131 ) {
F_30 ( V_30 ) ;
V_30 -> V_131 = false ;
}
return V_145 ;
}
static T_5 F_42 ( int V_154 , void * V_155 )
{
struct V_29 * V_30 = V_155 ;
if ( V_30 -> V_156 ) {
F_27 ( & V_30 -> V_71 ) ;
return V_145 ;
}
if ( ! V_30 -> V_89 )
return V_145 ;
if ( V_30 -> V_142 ) {
return F_39 ( V_30 ) ;
} else {
return F_41 ( V_30 ) ;
}
}
static int F_43 ( struct V_29 * V_30 , T_3 V_157 ,
T_2 V_158 , bool V_69 )
{
T_3 V_82 ;
T_2 V_159 ;
int V_160 = 0 ;
int V_40 ;
V_82 = V_30 -> V_161 + V_157 ;
V_40 = F_23 ( V_30 -> V_32 , V_82 , V_158 ) ;
if ( V_40 )
return V_40 ;
if ( ! V_69 )
return 0 ;
do {
F_44 ( 20 ) ;
V_40 = F_18 ( V_30 -> V_32 , V_82 , 1 , & V_159 ) ;
if ( V_40 )
return V_40 ;
} while ( V_159 != 0 && V_160 ++ <= 100 );
if ( V_160 > 100 ) {
F_9 ( & V_30 -> V_32 -> V_33 , L_33 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_45 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_40 = 0 ;
F_46 ( V_33 , L_34 ) ;
F_47 ( & V_30 -> V_95 ) ;
V_40 = F_43 ( V_30 , V_162 , V_163 , false ) ;
if ( V_40 )
return V_40 ;
V_40 = F_6 ( V_30 , & V_30 -> V_95 ,
V_164 ) ;
if ( V_40 )
return V_40 ;
return 0 ;
}
static void F_48 ( struct V_29 * V_30 , T_2 V_165 , T_2 V_158 )
{
V_30 -> V_93 = 0 ;
F_47 ( & V_30 -> V_92 ) ;
F_43 ( V_30 , V_165 , V_158 , true ) ;
F_6 ( V_30 , & V_30 -> V_92 , V_166 ) ;
}
static void F_49 ( T_4 * V_91 , T_2 V_167 , T_2 V_168 )
{
static const unsigned int V_169 = 0x80001B ;
T_4 V_170 ;
T_4 V_171 ;
V_171 = ( V_168 << 8 ) | V_167 ;
V_170 = ( ( * V_91 << 1 ) ^ V_171 ) ;
if ( V_170 & 0x1000000 )
V_170 ^= V_169 ;
* V_91 = V_170 ;
}
static T_4 F_50 ( T_2 * V_172 , T_6 V_173 , T_6 V_174 )
{
T_4 V_91 = 0 ;
T_2 * V_175 = V_172 + V_173 ;
T_2 * V_176 = V_172 + V_174 - 1 ;
if ( V_174 < V_173 )
return - V_61 ;
while ( V_175 < V_176 ) {
F_49 ( & V_91 , * V_175 , * ( V_175 + 1 ) ) ;
V_175 += 2 ;
}
if ( V_175 == V_176 )
F_49 ( & V_91 , * V_175 , 0 ) ;
V_91 &= 0x00FFFFFF ;
return V_91 ;
}
static int F_51 ( struct V_29 * V_30 ,
const struct V_177 * V_178 ,
unsigned int V_179 ,
unsigned int V_180 ,
T_2 * V_181 ,
T_1 V_182 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_1 * V_86 ;
unsigned int type , V_183 , V_184 , V_185 ;
int V_186 ;
int V_40 ;
int V_87 ;
T_3 V_82 ;
T_2 V_42 ;
while ( V_179 < V_178 -> V_184 ) {
V_40 = sscanf ( V_178 -> V_30 + V_179 , L_35 ,
& type , & V_183 , & V_184 , & V_186 ) ;
if ( V_40 == 0 ) {
break;
} else if ( V_40 != 3 ) {
F_9 ( V_33 , L_36 ) ;
return - V_61 ;
}
V_179 += V_186 ;
V_86 = F_24 ( V_30 , type ) ;
if ( ! V_86 ) {
for ( V_87 = 0 ; V_87 < V_184 ; V_87 ++ ) {
V_40 = sscanf ( V_178 -> V_30 + V_179 , L_37 ,
& V_42 , & V_186 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_38 ,
type , V_87 ) ;
return - V_61 ;
}
V_179 += V_186 ;
}
continue;
}
if ( V_184 > F_1 ( V_86 ) ) {
F_25 ( V_33 , L_39 ,
V_184 - F_1 ( V_86 ) , type ) ;
} else if ( F_1 ( V_86 ) > V_184 ) {
F_25 ( V_33 , L_40 ,
F_1 ( V_86 ) - V_184 , type ) ;
}
if ( V_183 >= F_2 ( V_86 ) ) {
F_9 ( V_33 , L_41 ) ;
return - V_61 ;
}
V_82 = V_86 -> V_187 + F_1 ( V_86 ) * V_183 ;
for ( V_87 = 0 ; V_87 < V_184 ; V_87 ++ ) {
V_40 = sscanf ( V_178 -> V_30 + V_179 , L_37 ,
& V_42 ,
& V_186 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_38 ,
type , V_87 ) ;
return - V_61 ;
}
V_179 += V_186 ;
if ( V_87 > F_1 ( V_86 ) )
continue;
V_185 = V_82 + V_87 - V_180 ;
if ( V_185 >= 0 && V_185 < V_182 ) {
* ( V_181 + V_185 ) = V_42 ;
} else {
F_9 ( V_33 , L_42 ,
V_82 , V_86 -> type , V_185 ) ;
return - V_61 ;
}
}
}
return 0 ;
}
static int F_52 ( struct V_29 * V_30 , unsigned int V_188 ,
T_2 * V_181 , T_1 V_182 )
{
unsigned int V_185 = 0 ;
int error ;
while ( V_185 < V_182 ) {
unsigned int V_184 = V_182 - V_185 ;
if ( V_184 > V_189 )
V_184 = V_189 ;
error = F_19 ( V_30 -> V_32 ,
V_188 + V_185 ,
V_184 , V_181 + V_185 ) ;
if ( error ) {
F_9 ( & V_30 -> V_32 -> V_33 ,
L_43 , error ) ;
return error ;
}
V_185 += V_184 ;
}
return 0 ;
}
static int F_53 ( struct V_29 * V_30 , const struct V_177 * V_178 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_190 V_191 ;
int V_40 ;
int V_186 ;
int V_179 ;
int V_87 ;
int V_180 ;
T_4 V_192 , V_93 , V_193 ;
T_2 * V_181 ;
T_1 V_182 ;
F_48 ( V_30 , V_194 , 1 ) ;
if ( strncmp ( V_178 -> V_30 , V_195 , strlen ( V_195 ) ) ) {
F_9 ( V_33 , L_44 ) ;
return - V_61 ;
}
V_179 = strlen ( V_195 ) ;
for ( V_87 = 0 ; V_87 < sizeof( struct V_190 ) ; V_87 ++ ) {
V_40 = sscanf ( V_178 -> V_30 + V_179 , L_37 ,
( unsigned char * ) & V_191 + V_87 ,
& V_186 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_45 ) ;
return - V_61 ;
}
V_179 += V_186 ;
}
if ( V_191 . V_60 != V_30 -> V_59 . V_60 ) {
F_9 ( V_33 , L_46 ) ;
return - V_61 ;
}
if ( V_191 . V_196 != V_30 -> V_59 . V_196 ) {
F_9 ( V_33 , L_47 ) ;
return - V_61 ;
}
V_40 = sscanf ( V_178 -> V_30 + V_179 , L_48 , & V_192 , & V_186 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_49 ) ;
return - V_61 ;
}
V_179 += V_186 ;
V_40 = sscanf ( V_178 -> V_30 + V_179 , L_48 , & V_93 , & V_186 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_50 ) ;
return - V_61 ;
}
V_179 += V_186 ;
if ( V_192 == V_30 -> V_192 ) {
if ( V_93 == 0 || V_30 -> V_93 == 0 ) {
F_46 ( V_33 , L_51 ) ;
} else if ( V_93 == V_30 -> V_93 ) {
F_5 ( V_33 , L_52 ,
V_30 -> V_93 ) ;
return 0 ;
} else {
F_46 ( V_33 , L_53 ,
V_30 -> V_93 , V_93 ) ;
}
} else {
F_25 ( V_33 ,
L_54 ,
V_30 -> V_192 , V_192 ) ;
}
V_180 = V_197 +
V_30 -> V_59 . V_88 * sizeof( struct V_1 ) +
V_198 ;
V_182 = V_30 -> V_199 - V_180 ;
V_181 = F_54 ( V_182 , V_84 ) ;
if ( ! V_181 ) {
F_9 ( V_33 , L_55 ) ;
return - V_85 ;
}
V_40 = F_51 ( V_30 , V_178 , V_179 , V_180 ,
V_181 , V_182 ) ;
if ( V_40 )
goto V_200;
if ( V_30 -> V_201 < V_180 ) {
F_9 ( V_33 , L_56 ,
V_30 -> V_201 , V_180 ) ;
V_40 = 0 ;
goto V_200;
}
V_193 = F_50 ( V_181 ,
V_30 -> V_201 - V_180 ,
V_182 ) ;
if ( V_93 > 0 && V_93 != V_193 )
F_25 ( V_33 , L_57 ,
V_193 , V_93 ) ;
V_40 = F_52 ( V_30 , V_180 ,
V_181 , V_182 ) ;
if ( V_40 )
goto V_200;
F_48 ( V_30 , V_202 , V_203 ) ;
V_40 = F_45 ( V_30 ) ;
if ( V_40 )
goto V_200;
F_46 ( V_33 , L_58 ) ;
V_200:
F_22 ( V_181 ) ;
return V_40 ;
}
static int F_55 ( struct V_29 * V_30 )
{
int error ;
F_56 ( V_30 -> V_154 ) ;
error = F_40 ( V_30 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_57 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
struct V_190 * V_59 = & V_30 -> V_59 ;
int error ;
error = F_18 ( V_32 , V_204 , sizeof( * V_59 ) , V_59 ) ;
if ( error )
return error ;
return 0 ;
}
static void F_58 ( struct V_29 * V_30 )
{
if ( V_30 -> V_102 ) {
F_59 ( V_30 -> V_102 ) ;
V_30 -> V_102 = NULL ;
}
}
static void F_60 ( struct V_29 * V_30 )
{
F_22 ( V_30 -> V_89 ) ;
V_30 -> V_89 = NULL ;
F_22 ( V_30 -> V_140 ) ;
V_30 -> V_140 = NULL ;
V_30 -> V_139 = 0 ;
V_30 -> V_34 = 0 ;
V_30 -> V_134 = 0 ;
V_30 -> V_201 = 0 ;
V_30 -> V_115 = 0 ;
V_30 -> V_135 = 0 ;
V_30 -> V_136 = 0 ;
V_30 -> V_142 = 0 ;
V_30 -> V_138 = 0 ;
}
static int F_61 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
T_1 V_205 ;
struct V_1 * V_89 ;
int error ;
int V_87 ;
T_2 V_206 ;
T_3 V_207 ;
V_205 = V_30 -> V_59 . V_88 * sizeof( struct V_1 ) ;
V_89 = F_54 ( V_205 , V_84 ) ;
if ( ! V_89 ) {
F_9 ( & V_30 -> V_32 -> V_33 , L_55 ) ;
return - V_85 ;
}
error = F_18 ( V_32 , V_197 , V_205 ,
V_89 ) ;
if ( error ) {
F_22 ( V_89 ) ;
return error ;
}
V_206 = 1 ;
V_30 -> V_199 = 0 ;
for ( V_87 = 0 ; V_87 < V_30 -> V_59 . V_88 ; V_87 ++ ) {
struct V_1 * V_86 = V_89 + V_87 ;
T_2 V_208 , V_209 ;
F_62 ( & V_86 -> V_187 ) ;
if ( V_86 -> V_210 ) {
V_208 = V_206 ;
V_206 += V_86 -> V_210 *
F_2 ( V_86 ) ;
V_209 = V_206 - 1 ;
} else {
V_208 = 0 ;
V_209 = 0 ;
}
F_5 ( & V_30 -> V_32 -> V_33 ,
L_59 ,
V_86 -> type , V_86 -> V_187 ,
F_1 ( V_86 ) , F_2 ( V_86 ) ,
V_208 , V_209 ) ;
switch ( V_86 -> type ) {
case V_211 :
if ( V_30 -> V_59 . V_60 == 0x80 &&
V_30 -> V_59 . V_212 < 0x20 ) {
V_30 -> V_34 = F_1 ( V_86 ) ;
} else {
V_30 -> V_34 = F_1 ( V_86 ) - 1 ;
}
V_30 -> V_139 = V_86 -> V_187 ;
break;
case V_5 :
V_30 -> V_134 = V_208 ;
V_30 -> V_161 = V_86 -> V_187 ;
break;
case V_6 :
V_30 -> V_201 = V_86 -> V_187 ;
break;
case V_9 :
V_30 -> V_115 = V_208 ;
V_30 -> V_135 = V_209 ;
V_30 -> V_153 = V_86 -> V_210
* F_2 ( V_86 ) ;
break;
case V_213 :
V_30 -> V_142 = V_86 -> V_187 ;
break;
case V_23 :
V_30 -> V_136 = V_208 ;
break;
}
V_207 = V_86 -> V_187
+ F_1 ( V_86 ) * F_2 ( V_86 ) - 1 ;
if ( V_207 >= V_30 -> V_199 )
V_30 -> V_199 = V_207 + 1 ;
}
V_30 -> V_138 = V_206 ;
if ( V_30 -> V_142 && ( V_30 -> V_139 != V_30 -> V_142 + 1 ) ) {
F_9 ( & V_32 -> V_33 , L_60 ) ;
error = - V_61 ;
goto V_214;
}
V_30 -> V_140 = F_63 ( V_30 -> V_138 ,
V_30 -> V_34 , V_84 ) ;
if ( ! V_30 -> V_140 ) {
F_9 ( & V_32 -> V_33 , L_61 ) ;
error = - V_85 ;
goto V_214;
}
V_30 -> V_89 = V_89 ;
return 0 ;
V_214:
F_60 ( V_30 ) ;
return error ;
}
static int F_64 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
int error ;
struct V_215 V_216 ;
unsigned char V_217 ;
struct V_1 * V_86 ;
V_86 = F_24 ( V_30 , V_9 ) ;
if ( ! V_86 )
return - V_61 ;
error = F_18 ( V_32 ,
V_86 -> V_187 + V_218 ,
sizeof( V_216 ) , & V_216 ) ;
if ( error )
return error ;
F_62 ( & V_216 . V_111 ) ;
F_62 ( & V_216 . V_112 ) ;
error = F_18 ( V_32 ,
V_86 -> V_187 + V_219 ,
1 , & V_217 ) ;
if ( error )
return error ;
if ( V_216 . V_111 == 0 )
V_216 . V_111 = 1023 ;
if ( V_216 . V_112 == 0 )
V_216 . V_112 = 1023 ;
if ( V_217 & V_220 ) {
V_30 -> V_116 = V_216 . V_112 ;
V_30 -> V_117 = V_216 . V_111 ;
} else {
V_30 -> V_116 = V_216 . V_111 ;
V_30 -> V_117 = V_216 . V_112 ;
}
F_5 ( & V_32 -> V_33 ,
L_62 , V_30 -> V_116 , V_30 -> V_117 ) ;
return 0 ;
}
static int F_65 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
const struct V_104 * V_105 = V_30 -> V_105 ;
struct V_102 * V_102 ;
int error ;
unsigned int V_221 ;
unsigned int V_222 = 0 ;
int V_87 ;
error = F_64 ( V_30 ) ;
if ( error )
F_25 ( V_33 , L_63 ) ;
V_102 = F_66 () ;
if ( ! V_102 ) {
F_9 ( V_33 , L_55 ) ;
return - V_85 ;
}
V_102 -> V_223 = L_64 ;
V_102 -> V_224 = V_30 -> V_224 ;
V_102 -> V_110 . V_225 = V_226 ;
V_102 -> V_33 . V_227 = V_33 ;
V_102 -> V_228 = V_229 ;
V_102 -> V_230 = V_231 ;
F_67 ( V_232 , V_102 -> V_233 ) ;
F_67 ( V_234 , V_102 -> V_233 ) ;
F_67 ( V_235 , V_102 -> V_236 ) ;
if ( V_105 -> V_107 ) {
F_67 ( V_237 , V_102 -> V_238 ) ;
for ( V_87 = 0 ; V_87 < V_105 -> V_107 ; V_87 ++ )
if ( V_105 -> V_108 [ V_87 ] != V_109 )
F_68 ( V_102 , V_234 ,
V_105 -> V_108 [ V_87 ] ) ;
V_222 |= V_239 ;
F_69 ( V_102 , V_240 , V_241 ) ;
F_69 ( V_102 , V_242 , V_241 ) ;
F_69 ( V_102 , V_127 ,
V_241 ) ;
F_69 ( V_102 , V_128 ,
V_241 ) ;
V_102 -> V_223 = L_65 ;
}
F_70 ( V_102 , V_240 ,
0 , V_30 -> V_116 , 0 , 0 ) ;
F_70 ( V_102 , V_242 ,
0 , V_30 -> V_117 , 0 , 0 ) ;
F_70 ( V_102 , V_243 ,
0 , 255 , 0 , 0 ) ;
V_221 = V_30 -> V_135 - V_30 -> V_115 + 1 ;
error = F_71 ( V_102 , V_221 , V_222 ) ;
if ( error ) {
F_9 ( V_33 , L_66 , error ) ;
goto V_244;
}
F_70 ( V_102 , V_130 ,
0 , V_245 , 0 , 0 ) ;
F_70 ( V_102 , V_127 ,
0 , V_30 -> V_116 , 0 , 0 ) ;
F_70 ( V_102 , V_128 ,
0 , V_30 -> V_117 , 0 , 0 ) ;
F_70 ( V_102 , V_129 ,
0 , 255 , 0 , 0 ) ;
F_72 ( V_102 , V_30 ) ;
error = F_73 ( V_102 ) ;
if ( error ) {
F_9 ( V_33 , L_67 , error ) ;
goto V_244;
}
V_30 -> V_102 = V_102 ;
return 0 ;
V_244:
F_74 ( V_102 ) ;
return error ;
}
static void F_75 ( const struct V_177 * V_178 , void * V_246 )
{
F_76 ( V_246 , V_178 ) ;
F_77 ( V_178 ) ;
}
static int F_78 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
int V_247 = 0 ;
int error ;
while ( 1 ) {
error = F_57 ( V_30 ) ;
if ( ! error )
break;
error = F_14 ( V_30 , false ) ;
if ( error ) {
F_46 ( & V_32 -> V_33 , L_68 ) ;
error = F_14 ( V_30 , true ) ;
if ( error ) {
return error ;
}
}
if ( ++ V_247 > 1 ) {
F_9 ( & V_32 -> V_33 , L_69 ) ;
V_30 -> V_156 = true ;
return 0 ;
}
F_17 ( V_30 , false ) ;
F_44 ( V_248 ) ;
}
error = F_61 ( V_30 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_70 , error ) ;
return error ;
}
error = F_55 ( V_30 ) ;
if ( error )
goto V_249;
error = F_79 ( V_250 , true , V_251 ,
& V_32 -> V_33 , V_84 , V_30 ,
F_75 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_71 ,
error ) ;
goto V_249;
}
return 0 ;
V_249:
F_60 ( V_30 ) ;
return error ;
}
static int F_80 ( struct V_29 * V_30 , T_2 V_252 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int error ;
struct V_253 * V_254 ;
struct V_253 V_255 = { . V_256 = 0 , . V_257 = 0 } ;
if ( V_252 == V_258 )
V_254 = & V_255 ;
else
V_254 = & V_30 -> V_259 ;
error = F_19 ( V_30 -> V_32 , V_30 -> V_201 ,
sizeof( V_30 -> V_259 ) , V_254 ) ;
if ( error )
return error ;
F_5 ( V_33 , L_72 ,
V_254 -> V_256 , V_254 -> V_257 ) ;
return 0 ;
}
static int F_81 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int error ;
bool V_56 = false ;
V_70:
error = F_18 ( V_30 -> V_32 , V_30 -> V_201 ,
sizeof( V_30 -> V_259 ) , & V_30 -> V_259 ) ;
if ( error )
return error ;
if ( V_30 -> V_259 . V_256 == 0 || V_30 -> V_259 . V_257 == 0 ) {
if ( ! V_56 ) {
F_5 ( V_33 , L_73 ) ;
F_45 ( V_30 ) ;
V_56 = true ;
goto V_70;
} else {
F_5 ( V_33 , L_74 ) ;
V_30 -> V_259 . V_256 = 20 ;
V_30 -> V_259 . V_257 = 100 ;
return F_80 ( V_30 , V_260 ) ;
}
}
F_5 ( V_33 , L_75 ,
V_30 -> V_259 . V_256 , V_30 -> V_259 . V_257 ) ;
return 0 ;
}
static int F_76 ( struct V_29 * V_30 ,
const struct V_177 * V_178 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_190 * V_59 = & V_30 -> V_59 ;
int error ;
if ( V_178 ) {
error = F_53 ( V_30 , V_178 ) ;
if ( error )
F_25 ( V_33 , L_76 , error ) ;
}
error = F_81 ( V_30 ) ;
if ( error ) {
F_9 ( V_33 , L_77 ) ;
return error ;
}
error = F_65 ( V_30 ) ;
if ( error )
return error ;
F_46 ( V_33 ,
L_78 ,
V_59 -> V_60 , V_59 -> V_196 , V_59 -> V_212 >> 4 ,
V_59 -> V_212 & 0xf , V_59 -> V_261 , V_59 -> V_88 ) ;
return 0 ;
}
static T_7 F_82 ( struct V_38 * V_33 ,
struct V_262 * V_263 , char * V_52 )
{
struct V_29 * V_30 = F_83 ( V_33 ) ;
struct V_190 * V_59 = & V_30 -> V_59 ;
return F_84 ( V_52 , V_264 , L_79 ,
V_59 -> V_212 >> 4 , V_59 -> V_212 & 0xf , V_59 -> V_261 ) ;
}
static T_7 F_85 ( struct V_38 * V_33 ,
struct V_262 * V_263 , char * V_52 )
{
struct V_29 * V_30 = F_83 ( V_33 ) ;
struct V_190 * V_59 = & V_30 -> V_59 ;
return F_84 ( V_52 , V_264 , L_80 ,
V_59 -> V_60 , V_59 -> V_196 ) ;
}
static T_7 F_86 ( char * V_52 , int V_43 ,
struct V_1 * V_86 , int V_183 ,
const T_2 * V_42 )
{
int V_87 ;
if ( F_2 ( V_86 ) > 1 )
V_43 += F_84 ( V_52 + V_43 , V_264 - V_43 ,
L_81 , V_183 ) ;
for ( V_87 = 0 ; V_87 < F_1 ( V_86 ) ; V_87 ++ )
V_43 += F_84 ( V_52 + V_43 , V_264 - V_43 ,
L_82 , V_87 , V_42 [ V_87 ] , V_42 [ V_87 ] ) ;
V_43 += F_84 ( V_52 + V_43 , V_264 - V_43 , L_83 ) ;
return V_43 ;
}
static T_7 F_87 ( struct V_38 * V_33 ,
struct V_262 * V_263 , char * V_52 )
{
struct V_29 * V_30 = F_83 ( V_33 ) ;
struct V_1 * V_86 ;
int V_43 = 0 ;
int V_87 , V_265 ;
int error ;
T_2 * V_266 ;
V_266 = F_20 ( 256 , V_84 ) ;
if ( ! V_266 )
return - V_85 ;
error = 0 ;
for ( V_87 = 0 ; V_87 < V_30 -> V_59 . V_88 ; V_87 ++ ) {
V_86 = V_30 -> V_89 + V_87 ;
if ( ! F_3 ( V_86 -> type ) )
continue;
V_43 += F_84 ( V_52 + V_43 , V_264 - V_43 ,
L_84 , V_86 -> type ) ;
for ( V_265 = 0 ; V_265 < F_2 ( V_86 ) ; V_265 ++ ) {
T_3 V_184 = F_1 ( V_86 ) ;
T_3 V_46 = V_86 -> V_187 + V_265 * V_184 ;
error = F_18 ( V_30 -> V_32 , V_46 , V_184 , V_266 ) ;
if ( error )
goto V_267;
V_43 = F_86 ( V_52 , V_43 , V_86 , V_265 , V_266 ) ;
}
}
V_267:
F_22 ( V_266 ) ;
return error ? : V_43 ;
}
static int F_88 ( struct V_38 * V_33 ,
const struct V_177 * V_268 )
{
unsigned int V_269 = 0 ;
char V_270 ;
while ( V_269 < V_268 -> V_184 ) {
V_270 = * ( V_268 -> V_30 + V_269 ) ;
if ( V_270 < '0' || ( V_270 > '9' && V_270 < 'A' ) || V_270 > 'F' )
return 0 ;
V_269 ++ ;
}
F_9 ( V_33 , L_85 ) ;
return - V_61 ;
}
static int F_89 ( struct V_38 * V_33 , const char * V_271 )
{
struct V_29 * V_30 = F_83 ( V_33 ) ;
const struct V_177 * V_268 = NULL ;
unsigned int V_272 ;
unsigned int V_269 = 0 ;
unsigned int V_56 = 0 ;
unsigned int V_273 = 0 ;
int V_40 ;
V_40 = F_90 ( & V_268 , V_271 , V_33 ) ;
if ( V_40 ) {
F_9 ( V_33 , L_86 , V_271 ) ;
return V_40 ;
}
V_40 = F_88 ( V_33 , V_268 ) ;
if ( V_40 )
goto F_77;
if ( ! V_30 -> V_156 ) {
V_30 -> V_156 = true ;
V_40 = F_43 ( V_30 , V_162 ,
V_274 , false ) ;
if ( V_40 )
goto F_77;
F_44 ( V_275 ) ;
V_40 = F_13 ( V_30 , 0 ) ;
if ( V_40 )
goto F_77;
F_58 ( V_30 ) ;
F_60 ( V_30 ) ;
} else {
F_56 ( V_30 -> V_154 ) ;
}
F_47 ( & V_30 -> V_71 ) ;
V_40 = F_16 ( V_30 , V_73 , false ) ;
if ( V_40 ) {
V_40 = F_16 ( V_30 , V_74 , false ) ;
if ( V_40 )
goto V_276;
} else {
F_46 ( V_33 , L_87 ) ;
V_40 = F_17 ( V_30 , true ) ;
if ( V_40 )
goto V_276;
}
while ( V_269 < V_268 -> V_184 ) {
V_40 = F_16 ( V_30 , V_74 , true ) ;
if ( V_40 )
goto V_276;
V_272 = ( ( * ( V_268 -> V_30 + V_269 ) << 8 ) | * ( V_268 -> V_30 + V_269 + 1 ) ) ;
V_272 += 2 ;
V_40 = F_12 ( V_30 , V_268 -> V_30 + V_269 , V_272 ) ;
if ( V_40 )
goto V_276;
V_40 = F_16 ( V_30 , V_75 , true ) ;
if ( V_40 ) {
V_56 ++ ;
F_44 ( V_56 * 20 ) ;
if ( V_56 > 20 ) {
F_9 ( V_33 , L_88 ) ;
goto V_276;
}
} else {
V_56 = 0 ;
V_269 += V_272 ;
V_273 ++ ;
}
if ( V_273 % 50 == 0 )
F_5 ( V_33 , L_89 ,
V_273 , V_269 , V_268 -> V_184 ) ;
}
V_40 = F_6 ( V_30 , & V_30 -> V_71 ,
V_248 ) ;
if ( V_40 )
goto V_276;
F_5 ( V_33 , L_90 , V_273 , V_269 ) ;
F_6 ( V_30 , & V_30 -> V_71 , V_248 ) ;
V_30 -> V_156 = false ;
V_276:
V_276 ( V_30 -> V_154 ) ;
F_77:
F_77 ( V_268 ) ;
return V_40 ;
}
static T_7 F_91 ( struct V_38 * V_33 ,
struct V_262 * V_263 ,
const char * V_52 , T_1 V_43 )
{
struct V_29 * V_30 = F_83 ( V_33 ) ;
int error ;
error = F_89 ( V_33 , V_277 ) ;
if ( error ) {
F_9 ( V_33 , L_91 , error ) ;
V_43 = error ;
} else {
F_46 ( V_33 , L_92 ) ;
error = F_78 ( V_30 ) ;
if ( error )
return error ;
}
return V_43 ;
}
static void F_92 ( struct V_29 * V_30 )
{
F_80 ( V_30 , V_260 ) ;
F_43 ( V_30 , V_278 , 1 , false ) ;
}
static void F_93 ( struct V_29 * V_30 )
{
F_80 ( V_30 , V_258 ) ;
}
static int V_229 ( struct V_102 * V_33 )
{
struct V_29 * V_30 = F_94 ( V_33 ) ;
F_92 ( V_30 ) ;
return 0 ;
}
static void V_231 ( struct V_102 * V_33 )
{
struct V_29 * V_30 = F_94 ( V_33 ) ;
F_93 ( V_30 ) ;
}
static struct V_104 * F_95 ( struct V_81 * V_32 )
{
struct V_104 * V_105 ;
T_4 * V_279 ;
T_4 V_280 ;
int V_281 , V_87 , V_40 ;
if ( ! V_32 -> V_33 . V_282 )
return F_96 ( - V_283 ) ;
V_105 = F_97 ( & V_32 -> V_33 , sizeof( * V_105 ) , V_84 ) ;
if ( ! V_105 )
return F_96 ( - V_85 ) ;
if ( F_98 ( V_32 -> V_33 . V_282 , L_93 ,
& V_281 ) ) {
V_105 -> V_107 = V_281 / sizeof( T_4 ) ;
V_279 = F_97 ( & V_32 -> V_33 ,
V_105 -> V_107 * sizeof( V_279 [ 0 ] ) ,
V_84 ) ;
if ( ! V_279 )
return F_96 ( - V_85 ) ;
for ( V_87 = 0 ; V_87 < V_105 -> V_107 ; V_87 ++ ) {
V_40 = F_99 ( V_32 -> V_33 . V_282 ,
L_93 , V_87 , & V_280 ) ;
if ( V_40 )
V_280 = V_109 ;
V_279 [ V_87 ] = V_280 ;
}
V_105 -> V_108 = V_279 ;
}
return V_105 ;
}
static struct V_104 * F_95 ( struct V_81 * V_32 )
{
F_5 ( & V_32 -> V_33 , L_94 ) ;
return F_96 ( - V_61 ) ;
}
static int F_100 ( struct V_81 * V_32 , const struct V_284 * V_110 )
{
struct V_29 * V_30 ;
const struct V_104 * V_105 ;
int error ;
V_105 = F_101 ( & V_32 -> V_33 ) ;
if ( ! V_105 ) {
V_105 = F_95 ( V_32 ) ;
if ( F_102 ( V_105 ) )
return F_103 ( V_105 ) ;
}
V_30 = F_54 ( sizeof( struct V_29 ) , V_84 ) ;
if ( ! V_30 ) {
F_9 ( & V_32 -> V_33 , L_55 ) ;
return - V_85 ;
}
snprintf ( V_30 -> V_224 , sizeof( V_30 -> V_224 ) , L_95 ,
V_32 -> V_53 -> V_285 , V_32 -> V_46 ) ;
V_30 -> V_32 = V_32 ;
V_30 -> V_105 = V_105 ;
V_30 -> V_154 = V_32 -> V_154 ;
F_104 ( V_32 , V_30 ) ;
F_105 ( & V_30 -> V_71 ) ;
F_105 ( & V_30 -> V_95 ) ;
F_105 ( & V_30 -> V_92 ) ;
error = F_106 ( V_32 -> V_154 , NULL , F_42 ,
V_105 -> V_286 | V_287 ,
V_32 -> V_223 , V_30 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_96 ) ;
goto V_244;
}
V_276 ( V_32 -> V_154 ) ;
error = F_78 ( V_30 ) ;
if ( error )
goto V_288;
error = F_107 ( & V_32 -> V_33 . V_289 , & V_290 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_97 ,
error ) ;
goto V_291;
}
return 0 ;
V_291:
F_58 ( V_30 ) ;
F_60 ( V_30 ) ;
V_288:
F_108 ( V_32 -> V_154 , V_30 ) ;
V_244:
F_22 ( V_30 ) ;
return error ;
}
static int F_109 ( struct V_81 * V_32 )
{
struct V_29 * V_30 = F_110 ( V_32 ) ;
F_111 ( & V_32 -> V_33 . V_289 , & V_290 ) ;
F_108 ( V_30 -> V_154 , V_30 ) ;
F_58 ( V_30 ) ;
F_60 ( V_30 ) ;
F_22 ( V_30 ) ;
return 0 ;
}
static int F_112 ( struct V_38 * V_33 )
{
struct V_81 * V_32 = F_113 ( V_33 ) ;
struct V_29 * V_30 = F_110 ( V_32 ) ;
struct V_102 * V_102 = V_30 -> V_102 ;
F_114 ( & V_102 -> V_292 ) ;
if ( V_102 -> V_293 )
F_93 ( V_30 ) ;
F_115 ( & V_102 -> V_292 ) ;
return 0 ;
}
static int F_116 ( struct V_38 * V_33 )
{
struct V_81 * V_32 = F_113 ( V_33 ) ;
struct V_29 * V_30 = F_110 ( V_32 ) ;
struct V_102 * V_102 = V_30 -> V_102 ;
F_114 ( & V_102 -> V_292 ) ;
if ( V_102 -> V_293 )
F_92 ( V_30 ) ;
F_115 ( & V_102 -> V_292 ) ;
return 0 ;
}
