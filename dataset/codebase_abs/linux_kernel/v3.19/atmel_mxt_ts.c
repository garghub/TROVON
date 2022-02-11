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
static int F_38 ( struct V_29 * V_30 , T_2 * V_31 )
{
T_2 V_134 = V_31 [ 0 ] ;
if ( V_134 == V_135 )
return 0 ;
if ( V_134 == V_30 -> V_136 ) {
F_26 ( V_30 , V_31 ) ;
} else if ( ! V_30 -> V_104 ) {
F_4 ( V_30 , V_31 ) ;
} else if ( V_134 >= V_30 -> V_117
&& V_134 <= V_30 -> V_137 ) {
F_34 ( V_30 , V_31 ) ;
} else if ( V_134 == V_30 -> V_138 ) {
F_29 ( V_30 , V_31 ) ;
V_30 -> V_133 = true ;
} else {
F_4 ( V_30 , V_31 ) ;
}
return 1 ;
}
static int F_39 ( struct V_29 * V_30 , T_2 V_43 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_40 ;
int V_87 ;
T_2 V_139 = 0 ;
if ( V_43 > V_30 -> V_140 )
return - V_61 ;
V_40 = F_18 ( V_30 -> V_32 , V_30 -> V_141 ,
V_30 -> V_34 * V_43 , V_30 -> V_142 ) ;
if ( V_40 ) {
F_9 ( V_33 , L_27 , V_43 , V_40 ) ;
return V_40 ;
}
for ( V_87 = 0 ; V_87 < V_43 ; V_87 ++ ) {
V_40 = F_38 ( V_30 ,
V_30 -> V_142 + V_30 -> V_34 * V_87 ) ;
if ( V_40 == 1 )
V_139 ++ ;
}
return V_139 ;
}
static T_5 F_40 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_40 ;
T_2 V_43 , V_143 ;
V_40 = F_18 ( V_30 -> V_32 , V_30 -> V_144 ,
V_30 -> V_34 + 1 , V_30 -> V_142 ) ;
if ( V_40 ) {
F_9 ( V_33 , L_28 , V_40 ) ;
return V_145 ;
}
V_43 = V_30 -> V_142 [ 0 ] ;
if ( V_43 == 0 ) {
F_5 ( V_33 , L_29 ) ;
return V_145 ;
} else if ( V_43 > V_30 -> V_140 ) {
F_9 ( V_33 , L_30 , V_43 ) ;
V_43 = V_30 -> V_140 ;
}
V_40 = F_38 ( V_30 , V_30 -> V_142 + 1 ) ;
if ( V_40 < 0 ) {
F_25 ( V_33 , L_31 ) ;
return V_145 ;
}
V_143 = V_43 - 1 ;
if ( V_143 ) {
V_40 = F_39 ( V_30 , V_143 ) ;
if ( V_40 < 0 )
goto V_146;
else if ( V_40 != V_143 )
F_25 ( V_33 , L_31 ) ;
}
V_146:
if ( V_30 -> V_133 ) {
F_31 ( V_30 ) ;
V_30 -> V_133 = false ;
}
return V_147 ;
}
static int F_41 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_43 , V_148 ;
T_2 V_149 = 2 ;
V_43 = V_30 -> V_140 ;
do {
V_148 = F_39 ( V_30 , V_43 ) ;
if ( V_148 < V_43 )
return 0 ;
} while ( -- V_149 );
if ( V_30 -> V_133 ) {
F_31 ( V_30 ) ;
V_30 -> V_133 = false ;
}
F_9 ( V_33 , L_32 ) ;
return - V_150 ;
}
static T_5 F_42 ( struct V_29 * V_30 )
{
int V_151 , V_152 ;
T_2 V_43 = V_30 -> V_153 ;
if ( V_43 < 1 || V_43 > V_30 -> V_140 )
V_43 = 1 ;
V_151 = F_39 ( V_30 , V_43 + 1 ) ;
if ( V_151 < 0 )
return V_145 ;
else if ( V_151 <= V_43 )
goto V_154;
do {
V_152 = F_39 ( V_30 , 2 ) ;
if ( V_152 < 0 )
return V_145 ;
V_151 += V_152 ;
if ( V_152 < 2 )
break;
} while ( V_151 < V_30 -> V_155 );
V_154:
V_30 -> V_153 = V_151 ;
if ( V_30 -> V_133 ) {
F_31 ( V_30 ) ;
V_30 -> V_133 = false ;
}
return V_147 ;
}
static T_5 F_43 ( int V_156 , void * V_157 )
{
struct V_29 * V_30 = V_157 ;
if ( V_30 -> V_158 ) {
F_27 ( & V_30 -> V_71 ) ;
return V_147 ;
}
if ( ! V_30 -> V_89 )
return V_147 ;
if ( V_30 -> V_144 ) {
return F_40 ( V_30 ) ;
} else {
return F_42 ( V_30 ) ;
}
}
static int F_44 ( struct V_29 * V_30 , T_3 V_159 ,
T_2 V_160 , bool V_69 )
{
T_3 V_82 ;
T_2 V_161 ;
int V_162 = 0 ;
int V_40 ;
V_82 = V_30 -> V_163 + V_159 ;
V_40 = F_23 ( V_30 -> V_32 , V_82 , V_160 ) ;
if ( V_40 )
return V_40 ;
if ( ! V_69 )
return 0 ;
do {
F_45 ( 20 ) ;
V_40 = F_18 ( V_30 -> V_32 , V_82 , 1 , & V_161 ) ;
if ( V_40 )
return V_40 ;
} while ( V_161 != 0 && V_162 ++ <= 100 );
if ( V_162 > 100 ) {
F_9 ( & V_30 -> V_32 -> V_33 , L_33 ) ;
return - V_54 ;
}
return 0 ;
}
static int F_46 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
int V_40 = 0 ;
F_47 ( V_33 , L_34 ) ;
F_48 ( & V_30 -> V_95 ) ;
V_40 = F_44 ( V_30 , V_164 , V_165 , false ) ;
if ( V_40 )
return V_40 ;
V_40 = F_6 ( V_30 , & V_30 -> V_95 ,
V_166 ) ;
if ( V_40 )
return V_40 ;
return 0 ;
}
static void F_49 ( struct V_29 * V_30 , T_2 V_167 , T_2 V_160 )
{
V_30 -> V_93 = 0 ;
F_48 ( & V_30 -> V_92 ) ;
F_44 ( V_30 , V_167 , V_160 , true ) ;
F_6 ( V_30 , & V_30 -> V_92 , V_168 ) ;
}
static void F_50 ( T_4 * V_91 , T_2 V_169 , T_2 V_170 )
{
static const unsigned int V_171 = 0x80001B ;
T_4 V_172 ;
T_4 V_173 ;
V_173 = ( V_170 << 8 ) | V_169 ;
V_172 = ( ( * V_91 << 1 ) ^ V_173 ) ;
if ( V_172 & 0x1000000 )
V_172 ^= V_171 ;
* V_91 = V_172 ;
}
static T_4 F_51 ( T_2 * V_174 , T_6 V_175 , T_6 V_176 )
{
T_4 V_91 = 0 ;
T_2 * V_177 = V_174 + V_175 ;
T_2 * V_178 = V_174 + V_176 - 1 ;
if ( V_176 < V_175 )
return - V_61 ;
while ( V_177 < V_178 ) {
F_50 ( & V_91 , * V_177 , * ( V_177 + 1 ) ) ;
V_177 += 2 ;
}
if ( V_177 == V_178 )
F_50 ( & V_91 , * V_177 , 0 ) ;
V_91 &= 0x00FFFFFF ;
return V_91 ;
}
static int F_52 ( struct V_29 * V_30 ,
const struct V_179 * V_180 ,
unsigned int V_181 ,
unsigned int V_182 ,
T_2 * V_183 ,
T_1 V_184 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_1 * V_86 ;
unsigned int type , V_185 , V_186 , V_187 ;
int V_102 ;
int V_40 ;
int V_87 ;
T_3 V_82 ;
T_2 V_42 ;
while ( V_181 < V_180 -> V_186 ) {
V_40 = sscanf ( V_180 -> V_30 + V_181 , L_35 ,
& type , & V_185 , & V_186 , & V_102 ) ;
if ( V_40 == 0 ) {
break;
} else if ( V_40 != 3 ) {
F_9 ( V_33 , L_36 ) ;
return - V_61 ;
}
V_181 += V_102 ;
V_86 = F_24 ( V_30 , type ) ;
if ( ! V_86 ) {
for ( V_87 = 0 ; V_87 < V_186 ; V_87 ++ ) {
V_40 = sscanf ( V_180 -> V_30 + V_181 , L_37 ,
& V_42 , & V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_38 ,
type , V_87 ) ;
return - V_61 ;
}
V_181 += V_102 ;
}
continue;
}
if ( V_186 > F_1 ( V_86 ) ) {
F_25 ( V_33 , L_39 ,
V_186 - F_1 ( V_86 ) , type ) ;
} else if ( F_1 ( V_86 ) > V_186 ) {
F_25 ( V_33 , L_40 ,
F_1 ( V_86 ) - V_186 , type ) ;
}
if ( V_185 >= F_2 ( V_86 ) ) {
F_9 ( V_33 , L_41 ) ;
return - V_61 ;
}
V_82 = V_86 -> V_103 + F_1 ( V_86 ) * V_185 ;
for ( V_87 = 0 ; V_87 < V_186 ; V_87 ++ ) {
V_40 = sscanf ( V_180 -> V_30 + V_181 , L_37 ,
& V_42 ,
& V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_38 ,
type , V_87 ) ;
return - V_61 ;
}
V_181 += V_102 ;
if ( V_87 > F_1 ( V_86 ) )
continue;
V_187 = V_82 + V_87 - V_182 ;
if ( V_187 >= 0 && V_187 < V_184 ) {
* ( V_183 + V_187 ) = V_42 ;
} else {
F_9 ( V_33 , L_42 ,
V_82 , V_86 -> type , V_187 ) ;
return - V_61 ;
}
}
}
return 0 ;
}
static int F_53 ( struct V_29 * V_30 , unsigned int V_188 ,
T_2 * V_183 , T_1 V_184 )
{
unsigned int V_187 = 0 ;
int error ;
while ( V_187 < V_184 ) {
unsigned int V_186 = V_184 - V_187 ;
if ( V_186 > V_189 )
V_186 = V_189 ;
error = F_19 ( V_30 -> V_32 ,
V_188 + V_187 ,
V_186 , V_183 + V_187 ) ;
if ( error ) {
F_9 ( & V_30 -> V_32 -> V_33 ,
L_43 , error ) ;
return error ;
}
V_187 += V_186 ;
}
return 0 ;
}
static int F_54 ( struct V_29 * V_30 , const struct V_179 * V_180 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_190 V_191 ;
int V_40 ;
int V_102 ;
int V_181 ;
int V_87 ;
int V_182 ;
T_4 V_192 , V_93 , V_193 ;
T_2 * V_183 ;
T_1 V_184 ;
F_49 ( V_30 , V_194 , 1 ) ;
if ( strncmp ( V_180 -> V_30 , V_195 , strlen ( V_195 ) ) ) {
F_9 ( V_33 , L_44 ) ;
return - V_61 ;
}
V_181 = strlen ( V_195 ) ;
for ( V_87 = 0 ; V_87 < sizeof( struct V_190 ) ; V_87 ++ ) {
V_40 = sscanf ( V_180 -> V_30 + V_181 , L_37 ,
( unsigned char * ) & V_191 + V_87 ,
& V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_45 ) ;
return - V_61 ;
}
V_181 += V_102 ;
}
if ( V_191 . V_60 != V_30 -> V_59 . V_60 ) {
F_9 ( V_33 , L_46 ) ;
return - V_61 ;
}
if ( V_191 . V_196 != V_30 -> V_59 . V_196 ) {
F_9 ( V_33 , L_47 ) ;
return - V_61 ;
}
V_40 = sscanf ( V_180 -> V_30 + V_181 , L_48 , & V_192 , & V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_49 ) ;
return - V_61 ;
}
V_181 += V_102 ;
V_40 = sscanf ( V_180 -> V_30 + V_181 , L_48 , & V_93 , & V_102 ) ;
if ( V_40 != 1 ) {
F_9 ( V_33 , L_50 ) ;
return - V_61 ;
}
V_181 += V_102 ;
if ( V_192 == V_30 -> V_192 ) {
if ( V_93 == 0 || V_30 -> V_93 == 0 ) {
F_47 ( V_33 , L_51 ) ;
} else if ( V_93 == V_30 -> V_93 ) {
F_5 ( V_33 , L_52 ,
V_30 -> V_93 ) ;
return 0 ;
} else {
F_47 ( V_33 , L_53 ,
V_30 -> V_93 , V_93 ) ;
}
} else {
F_25 ( V_33 ,
L_54 ,
V_30 -> V_192 , V_192 ) ;
}
V_182 = V_197 +
V_30 -> V_59 . V_88 * sizeof( struct V_1 ) +
V_198 ;
V_184 = V_30 -> V_199 - V_182 ;
V_183 = F_55 ( V_184 , V_84 ) ;
if ( ! V_183 ) {
F_9 ( V_33 , L_55 ) ;
return - V_85 ;
}
V_40 = F_52 ( V_30 , V_180 , V_181 , V_182 ,
V_183 , V_184 ) ;
if ( V_40 )
goto V_200;
if ( V_30 -> V_201 < V_182 ) {
F_9 ( V_33 , L_56 ,
V_30 -> V_201 , V_182 ) ;
V_40 = 0 ;
goto V_200;
}
V_193 = F_51 ( V_183 ,
V_30 -> V_201 - V_182 ,
V_184 ) ;
if ( V_93 > 0 && V_93 != V_193 )
F_25 ( V_33 , L_57 ,
V_193 , V_93 ) ;
V_40 = F_53 ( V_30 , V_182 ,
V_183 , V_184 ) ;
if ( V_40 )
goto V_200;
F_49 ( V_30 , V_202 , V_203 ) ;
V_40 = F_46 ( V_30 ) ;
if ( V_40 )
goto V_200;
F_47 ( V_33 , L_58 ) ;
V_200:
F_22 ( V_183 ) ;
return V_40 ;
}
static int F_56 ( struct V_29 * V_30 )
{
int error ;
F_57 ( V_30 -> V_156 ) ;
error = F_41 ( V_30 ) ;
if ( error )
return error ;
return 0 ;
}
static int F_58 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
struct V_190 * V_59 = & V_30 -> V_59 ;
int error ;
error = F_18 ( V_32 , V_204 , sizeof( * V_59 ) , V_59 ) ;
if ( error )
return error ;
return 0 ;
}
static void F_59 ( struct V_29 * V_30 )
{
if ( V_30 -> V_104 ) {
F_60 ( V_30 -> V_104 ) ;
V_30 -> V_104 = NULL ;
}
}
static void F_61 ( struct V_29 * V_30 )
{
F_22 ( V_30 -> V_89 ) ;
V_30 -> V_89 = NULL ;
F_22 ( V_30 -> V_142 ) ;
V_30 -> V_142 = NULL ;
V_30 -> V_141 = 0 ;
V_30 -> V_34 = 0 ;
V_30 -> V_136 = 0 ;
V_30 -> V_201 = 0 ;
V_30 -> V_117 = 0 ;
V_30 -> V_137 = 0 ;
V_30 -> V_138 = 0 ;
V_30 -> V_144 = 0 ;
V_30 -> V_140 = 0 ;
}
static int F_62 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
T_1 V_205 ;
struct V_1 * V_89 ;
int error ;
int V_87 ;
T_2 V_206 ;
T_3 V_207 ;
V_205 = V_30 -> V_59 . V_88 * sizeof( struct V_1 ) ;
V_89 = F_55 ( V_205 , V_84 ) ;
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
F_63 ( & V_86 -> V_103 ) ;
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
V_86 -> type , V_86 -> V_103 ,
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
V_30 -> V_141 = V_86 -> V_103 ;
break;
case V_5 :
V_30 -> V_136 = V_208 ;
V_30 -> V_163 = V_86 -> V_103 ;
break;
case V_6 :
V_30 -> V_201 = V_86 -> V_103 ;
break;
case V_9 :
V_30 -> V_117 = V_208 ;
V_30 -> V_137 = V_209 ;
V_30 -> V_155 = V_86 -> V_210
* F_2 ( V_86 ) ;
break;
case V_213 :
V_30 -> V_144 = V_86 -> V_103 ;
break;
case V_23 :
V_30 -> V_138 = V_208 ;
break;
}
V_207 = V_86 -> V_103
+ F_1 ( V_86 ) * F_2 ( V_86 ) - 1 ;
if ( V_207 >= V_30 -> V_199 )
V_30 -> V_199 = V_207 + 1 ;
}
V_30 -> V_140 = V_206 ;
if ( V_30 -> V_144 && ( V_30 -> V_141 != V_30 -> V_144 + 1 ) ) {
F_9 ( & V_32 -> V_33 , L_60 ) ;
error = - V_61 ;
goto V_214;
}
V_30 -> V_142 = F_64 ( V_30 -> V_140 ,
V_30 -> V_34 , V_84 ) ;
if ( ! V_30 -> V_142 ) {
F_9 ( & V_32 -> V_33 , L_61 ) ;
error = - V_85 ;
goto V_214;
}
V_30 -> V_89 = V_89 ;
return 0 ;
V_214:
F_61 ( V_30 ) ;
return error ;
}
static int F_65 ( struct V_29 * V_30 )
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
V_86 -> V_103 + V_218 ,
sizeof( V_216 ) , & V_216 ) ;
if ( error )
return error ;
F_63 ( & V_216 . V_113 ) ;
F_63 ( & V_216 . V_114 ) ;
error = F_18 ( V_32 ,
V_86 -> V_103 + V_219 ,
1 , & V_217 ) ;
if ( error )
return error ;
if ( V_216 . V_113 == 0 )
V_216 . V_113 = 1023 ;
if ( V_216 . V_114 == 0 )
V_216 . V_114 = 1023 ;
if ( V_217 & V_220 ) {
V_30 -> V_118 = V_216 . V_114 ;
V_30 -> V_119 = V_216 . V_113 ;
} else {
V_30 -> V_118 = V_216 . V_113 ;
V_30 -> V_119 = V_216 . V_114 ;
}
F_5 ( & V_32 -> V_33 ,
L_62 , V_30 -> V_118 , V_30 -> V_119 ) ;
return 0 ;
}
static int F_66 ( struct V_29 * V_30 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
const struct V_106 * V_107 = V_30 -> V_107 ;
struct V_104 * V_104 ;
int error ;
unsigned int V_221 ;
unsigned int V_222 = 0 ;
int V_87 ;
error = F_65 ( V_30 ) ;
if ( error )
F_25 ( V_33 , L_63 ) ;
V_104 = F_67 () ;
if ( ! V_104 ) {
F_9 ( V_33 , L_55 ) ;
return - V_85 ;
}
V_104 -> V_223 = L_64 ;
V_104 -> V_224 = V_30 -> V_224 ;
V_104 -> V_112 . V_225 = V_226 ;
V_104 -> V_33 . V_227 = V_33 ;
V_104 -> V_228 = V_229 ;
V_104 -> V_230 = V_231 ;
F_68 ( V_232 , V_104 -> V_233 ) ;
F_68 ( V_234 , V_104 -> V_233 ) ;
F_68 ( V_235 , V_104 -> V_236 ) ;
if ( V_107 -> V_109 ) {
F_68 ( V_237 , V_104 -> V_238 ) ;
for ( V_87 = 0 ; V_87 < V_107 -> V_109 ; V_87 ++ )
if ( V_107 -> V_110 [ V_87 ] != V_111 )
F_69 ( V_104 , V_234 ,
V_107 -> V_110 [ V_87 ] ) ;
V_222 |= V_239 ;
F_70 ( V_104 , V_240 , V_241 ) ;
F_70 ( V_104 , V_242 , V_241 ) ;
F_70 ( V_104 , V_129 ,
V_241 ) ;
F_70 ( V_104 , V_130 ,
V_241 ) ;
V_104 -> V_223 = L_65 ;
}
F_71 ( V_104 , V_240 ,
0 , V_30 -> V_118 , 0 , 0 ) ;
F_71 ( V_104 , V_242 ,
0 , V_30 -> V_119 , 0 , 0 ) ;
F_71 ( V_104 , V_243 ,
0 , 255 , 0 , 0 ) ;
V_221 = V_30 -> V_137 - V_30 -> V_117 + 1 ;
error = F_72 ( V_104 , V_221 , V_222 ) ;
if ( error ) {
F_9 ( V_33 , L_66 , error ) ;
goto V_244;
}
F_71 ( V_104 , V_132 ,
0 , V_245 , 0 , 0 ) ;
F_71 ( V_104 , V_129 ,
0 , V_30 -> V_118 , 0 , 0 ) ;
F_71 ( V_104 , V_130 ,
0 , V_30 -> V_119 , 0 , 0 ) ;
F_71 ( V_104 , V_131 ,
0 , 255 , 0 , 0 ) ;
F_73 ( V_104 , V_30 ) ;
error = F_74 ( V_104 ) ;
if ( error ) {
F_9 ( V_33 , L_67 , error ) ;
goto V_244;
}
V_30 -> V_104 = V_104 ;
return 0 ;
V_244:
F_75 ( V_104 ) ;
return error ;
}
static void F_76 ( const struct V_179 * V_180 , void * V_246 )
{
F_77 ( V_246 , V_180 ) ;
F_78 ( V_180 ) ;
}
static int F_79 ( struct V_29 * V_30 )
{
struct V_81 * V_32 = V_30 -> V_32 ;
int V_247 = 0 ;
int error ;
while ( 1 ) {
error = F_58 ( V_30 ) ;
if ( ! error )
break;
error = F_14 ( V_30 , false ) ;
if ( error ) {
F_47 ( & V_32 -> V_33 , L_68 ) ;
error = F_14 ( V_30 , true ) ;
if ( error ) {
return error ;
}
}
if ( ++ V_247 > 1 ) {
F_9 ( & V_32 -> V_33 , L_69 ) ;
V_30 -> V_158 = true ;
return 0 ;
}
F_17 ( V_30 , false ) ;
F_45 ( V_248 ) ;
}
error = F_62 ( V_30 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_70 , error ) ;
return error ;
}
error = F_56 ( V_30 ) ;
if ( error )
goto V_249;
error = F_80 ( V_250 , true , V_251 ,
& V_32 -> V_33 , V_84 , V_30 ,
F_76 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_71 ,
error ) ;
goto V_249;
}
return 0 ;
V_249:
F_61 ( V_30 ) ;
return error ;
}
static int F_77 ( struct V_29 * V_30 ,
const struct V_179 * V_180 )
{
struct V_38 * V_33 = & V_30 -> V_32 -> V_33 ;
struct V_190 * V_59 = & V_30 -> V_59 ;
int error ;
if ( V_180 ) {
error = F_54 ( V_30 , V_180 ) ;
if ( error )
F_25 ( V_33 , L_72 , error ) ;
}
error = F_66 ( V_30 ) ;
if ( error )
return error ;
F_47 ( V_33 ,
L_73 ,
V_59 -> V_60 , V_59 -> V_196 , V_59 -> V_212 >> 4 ,
V_59 -> V_212 & 0xf , V_59 -> V_252 , V_59 -> V_88 ) ;
return 0 ;
}
static T_7 F_81 ( struct V_38 * V_33 ,
struct V_253 * V_254 , char * V_52 )
{
struct V_29 * V_30 = F_82 ( V_33 ) ;
struct V_190 * V_59 = & V_30 -> V_59 ;
return F_83 ( V_52 , V_255 , L_74 ,
V_59 -> V_212 >> 4 , V_59 -> V_212 & 0xf , V_59 -> V_252 ) ;
}
static T_7 F_84 ( struct V_38 * V_33 ,
struct V_253 * V_254 , char * V_52 )
{
struct V_29 * V_30 = F_82 ( V_33 ) ;
struct V_190 * V_59 = & V_30 -> V_59 ;
return F_83 ( V_52 , V_255 , L_75 ,
V_59 -> V_60 , V_59 -> V_196 ) ;
}
static T_7 F_85 ( char * V_52 , int V_43 ,
struct V_1 * V_86 , int V_185 ,
const T_2 * V_42 )
{
int V_87 ;
if ( F_2 ( V_86 ) > 1 )
V_43 += F_83 ( V_52 + V_43 , V_255 - V_43 ,
L_76 , V_185 ) ;
for ( V_87 = 0 ; V_87 < F_1 ( V_86 ) ; V_87 ++ )
V_43 += F_83 ( V_52 + V_43 , V_255 - V_43 ,
L_77 , V_87 , V_42 [ V_87 ] , V_42 [ V_87 ] ) ;
V_43 += F_83 ( V_52 + V_43 , V_255 - V_43 , L_78 ) ;
return V_43 ;
}
static T_7 F_86 ( struct V_38 * V_33 ,
struct V_253 * V_254 , char * V_52 )
{
struct V_29 * V_30 = F_82 ( V_33 ) ;
struct V_1 * V_86 ;
int V_43 = 0 ;
int V_87 , V_256 ;
int error ;
T_2 * V_257 ;
V_257 = F_20 ( 256 , V_84 ) ;
if ( ! V_257 )
return - V_85 ;
error = 0 ;
for ( V_87 = 0 ; V_87 < V_30 -> V_59 . V_88 ; V_87 ++ ) {
V_86 = V_30 -> V_89 + V_87 ;
if ( ! F_3 ( V_86 -> type ) )
continue;
V_43 += F_83 ( V_52 + V_43 , V_255 - V_43 ,
L_79 , V_86 -> type ) ;
for ( V_256 = 0 ; V_256 < F_2 ( V_86 ) ; V_256 ++ ) {
T_3 V_186 = F_1 ( V_86 ) ;
T_3 V_46 = V_86 -> V_103 + V_256 * V_186 ;
error = F_18 ( V_30 -> V_32 , V_46 , V_186 , V_257 ) ;
if ( error )
goto V_258;
V_43 = F_85 ( V_52 , V_43 , V_86 , V_256 , V_257 ) ;
}
}
V_258:
F_22 ( V_257 ) ;
return error ? : V_43 ;
}
static int F_87 ( struct V_38 * V_33 ,
const struct V_179 * V_259 )
{
unsigned int V_260 = 0 ;
char V_261 ;
while ( V_260 < V_259 -> V_186 ) {
V_261 = * ( V_259 -> V_30 + V_260 ) ;
if ( V_261 < '0' || ( V_261 > '9' && V_261 < 'A' ) || V_261 > 'F' )
return 0 ;
V_260 ++ ;
}
F_9 ( V_33 , L_80 ) ;
return - V_61 ;
}
static int F_88 ( struct V_38 * V_33 , const char * V_262 )
{
struct V_29 * V_30 = F_82 ( V_33 ) ;
const struct V_179 * V_259 = NULL ;
unsigned int V_263 ;
unsigned int V_260 = 0 ;
unsigned int V_56 = 0 ;
unsigned int V_264 = 0 ;
int V_40 ;
V_40 = F_89 ( & V_259 , V_262 , V_33 ) ;
if ( V_40 ) {
F_9 ( V_33 , L_81 , V_262 ) ;
return V_40 ;
}
V_40 = F_87 ( V_33 , V_259 ) ;
if ( V_40 )
goto F_78;
if ( ! V_30 -> V_158 ) {
V_30 -> V_158 = true ;
V_40 = F_44 ( V_30 , V_164 ,
V_265 , false ) ;
if ( V_40 )
goto F_78;
F_45 ( V_266 ) ;
V_40 = F_13 ( V_30 , 0 ) ;
if ( V_40 )
goto F_78;
F_59 ( V_30 ) ;
F_61 ( V_30 ) ;
} else {
F_57 ( V_30 -> V_156 ) ;
}
F_48 ( & V_30 -> V_71 ) ;
V_40 = F_16 ( V_30 , V_73 , false ) ;
if ( V_40 ) {
V_40 = F_16 ( V_30 , V_74 , false ) ;
if ( V_40 )
goto V_267;
} else {
F_47 ( V_33 , L_82 ) ;
V_40 = F_17 ( V_30 , true ) ;
if ( V_40 )
goto V_267;
}
while ( V_260 < V_259 -> V_186 ) {
V_40 = F_16 ( V_30 , V_74 , true ) ;
if ( V_40 )
goto V_267;
V_263 = ( ( * ( V_259 -> V_30 + V_260 ) << 8 ) | * ( V_259 -> V_30 + V_260 + 1 ) ) ;
V_263 += 2 ;
V_40 = F_12 ( V_30 , V_259 -> V_30 + V_260 , V_263 ) ;
if ( V_40 )
goto V_267;
V_40 = F_16 ( V_30 , V_75 , true ) ;
if ( V_40 ) {
V_56 ++ ;
F_45 ( V_56 * 20 ) ;
if ( V_56 > 20 ) {
F_9 ( V_33 , L_83 ) ;
goto V_267;
}
} else {
V_56 = 0 ;
V_260 += V_263 ;
V_264 ++ ;
}
if ( V_264 % 50 == 0 )
F_5 ( V_33 , L_84 ,
V_264 , V_260 , V_259 -> V_186 ) ;
}
V_40 = F_6 ( V_30 , & V_30 -> V_71 ,
V_248 ) ;
if ( V_40 )
goto V_267;
F_5 ( V_33 , L_85 , V_264 , V_260 ) ;
F_6 ( V_30 , & V_30 -> V_71 , V_248 ) ;
V_30 -> V_158 = false ;
V_267:
V_267 ( V_30 -> V_156 ) ;
F_78:
F_78 ( V_259 ) ;
return V_40 ;
}
static T_7 F_90 ( struct V_38 * V_33 ,
struct V_253 * V_254 ,
const char * V_52 , T_1 V_43 )
{
struct V_29 * V_30 = F_82 ( V_33 ) ;
int error ;
error = F_88 ( V_33 , V_268 ) ;
if ( error ) {
F_9 ( V_33 , L_86 , error ) ;
V_43 = error ;
} else {
F_47 ( V_33 , L_87 ) ;
error = F_79 ( V_30 ) ;
if ( error )
return error ;
}
return V_43 ;
}
static void F_91 ( struct V_29 * V_30 )
{
F_28 ( V_30 ,
V_9 , V_269 , 0x83 ) ;
}
static void F_92 ( struct V_29 * V_30 )
{
F_28 ( V_30 ,
V_9 , V_269 , 0 ) ;
}
static int V_229 ( struct V_104 * V_33 )
{
struct V_29 * V_30 = F_93 ( V_33 ) ;
F_91 ( V_30 ) ;
return 0 ;
}
static void V_231 ( struct V_104 * V_33 )
{
struct V_29 * V_30 = F_93 ( V_33 ) ;
F_92 ( V_30 ) ;
}
static struct V_106 * F_94 ( struct V_81 * V_32 )
{
struct V_106 * V_107 ;
T_4 * V_270 ;
T_4 V_271 ;
int V_272 , V_87 , V_40 ;
if ( ! V_32 -> V_33 . V_273 )
return F_95 ( - V_274 ) ;
V_107 = F_96 ( & V_32 -> V_33 , sizeof( * V_107 ) , V_84 ) ;
if ( ! V_107 )
return F_95 ( - V_85 ) ;
if ( F_97 ( V_32 -> V_33 . V_273 , L_88 ,
& V_272 ) ) {
V_107 -> V_109 = V_272 / sizeof( T_4 ) ;
V_270 = F_96 ( & V_32 -> V_33 ,
V_107 -> V_109 * sizeof( V_270 [ 0 ] ) ,
V_84 ) ;
if ( ! V_270 )
return F_95 ( - V_85 ) ;
for ( V_87 = 0 ; V_87 < V_107 -> V_109 ; V_87 ++ ) {
V_40 = F_98 ( V_32 -> V_33 . V_273 ,
L_88 , V_87 , & V_271 ) ;
if ( V_40 )
V_271 = V_111 ;
V_270 [ V_87 ] = V_271 ;
}
V_107 -> V_110 = V_270 ;
}
return V_107 ;
}
static struct V_106 * F_94 ( struct V_81 * V_32 )
{
F_5 ( & V_32 -> V_33 , L_89 ) ;
return F_95 ( - V_61 ) ;
}
static int F_99 ( struct V_81 * V_32 , const struct V_275 * V_112 )
{
struct V_29 * V_30 ;
const struct V_106 * V_107 ;
int error ;
V_107 = F_100 ( & V_32 -> V_33 ) ;
if ( ! V_107 ) {
V_107 = F_94 ( V_32 ) ;
if ( F_101 ( V_107 ) )
return F_102 ( V_107 ) ;
}
V_30 = F_55 ( sizeof( struct V_29 ) , V_84 ) ;
if ( ! V_30 ) {
F_9 ( & V_32 -> V_33 , L_55 ) ;
return - V_85 ;
}
snprintf ( V_30 -> V_224 , sizeof( V_30 -> V_224 ) , L_90 ,
V_32 -> V_53 -> V_276 , V_32 -> V_46 ) ;
V_30 -> V_32 = V_32 ;
V_30 -> V_107 = V_107 ;
V_30 -> V_156 = V_32 -> V_156 ;
F_103 ( V_32 , V_30 ) ;
F_104 ( & V_30 -> V_71 ) ;
F_104 ( & V_30 -> V_95 ) ;
F_104 ( & V_30 -> V_92 ) ;
error = F_105 ( V_32 -> V_156 , NULL , F_43 ,
V_107 -> V_277 | V_278 ,
V_32 -> V_223 , V_30 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_91 ) ;
goto V_244;
}
V_267 ( V_32 -> V_156 ) ;
error = F_79 ( V_30 ) ;
if ( error )
goto V_279;
error = F_106 ( & V_32 -> V_33 . V_280 , & V_281 ) ;
if ( error ) {
F_9 ( & V_32 -> V_33 , L_92 ,
error ) ;
goto V_282;
}
return 0 ;
V_282:
F_59 ( V_30 ) ;
F_61 ( V_30 ) ;
V_279:
F_107 ( V_32 -> V_156 , V_30 ) ;
V_244:
F_22 ( V_30 ) ;
return error ;
}
static int F_108 ( struct V_81 * V_32 )
{
struct V_29 * V_30 = F_109 ( V_32 ) ;
F_110 ( & V_32 -> V_33 . V_280 , & V_281 ) ;
F_107 ( V_30 -> V_156 , V_30 ) ;
F_59 ( V_30 ) ;
F_61 ( V_30 ) ;
F_22 ( V_30 ) ;
return 0 ;
}
static int T_8 F_111 ( struct V_38 * V_33 )
{
struct V_81 * V_32 = F_112 ( V_33 ) ;
struct V_29 * V_30 = F_109 ( V_32 ) ;
struct V_104 * V_104 = V_30 -> V_104 ;
F_113 ( & V_104 -> V_283 ) ;
if ( V_104 -> V_284 )
F_92 ( V_30 ) ;
F_114 ( & V_104 -> V_283 ) ;
return 0 ;
}
static int T_8 F_115 ( struct V_38 * V_33 )
{
struct V_81 * V_32 = F_112 ( V_33 ) ;
struct V_29 * V_30 = F_109 ( V_32 ) ;
struct V_104 * V_104 = V_30 -> V_104 ;
F_46 ( V_30 ) ;
F_113 ( & V_104 -> V_283 ) ;
if ( V_104 -> V_284 )
F_91 ( V_30 ) ;
F_114 ( & V_104 -> V_283 ) ;
return 0 ;
}
