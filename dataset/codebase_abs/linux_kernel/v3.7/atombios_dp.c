static int F_1 ( struct V_1 * V_2 ,
T_1 * V_3 , int V_4 ,
T_1 * V_5 , int V_6 ,
T_1 V_7 , T_1 * V_8 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
union V_14 args ;
int V_15 = F_2 ( V_16 , V_17 ) ;
unsigned char * V_18 ;
int V_19 ;
memset ( & args , 0 , sizeof( args ) ) ;
V_18 = ( unsigned char * ) ( V_12 -> V_20 . V_21 -> V_22 + 1 ) ;
memcpy ( V_18 , V_3 , V_4 ) ;
args . V_23 . V_24 = 0 + 4 ;
args . V_23 . V_25 = 16 + 4 ;
args . V_23 . V_26 = 0 ;
args . V_23 . V_27 = V_2 -> V_28 . V_29 ;
args . V_23 . V_30 = V_7 / 10 ;
if ( F_3 ( V_12 ) )
args . V_31 . V_32 = V_2 -> V_28 . V_33 ;
F_4 ( V_12 -> V_20 . V_21 , V_15 , ( V_34 * ) & args ) ;
* V_8 = args . V_23 . V_35 ;
if ( args . V_23 . V_35 == 1 ) {
F_5 ( L_1 ) ;
return - V_36 ;
}
if ( args . V_23 . V_35 == 2 ) {
F_5 ( L_2 ) ;
return - V_37 ;
}
if ( args . V_23 . V_35 == 3 ) {
F_5 ( L_3 ) ;
return - V_38 ;
}
V_19 = args . V_23 . V_26 ;
if ( V_19 > V_6 )
V_19 = V_6 ;
if ( V_5 && V_6 )
memcpy ( V_5 , V_18 + 16 , V_19 ) ;
return V_19 ;
}
static int F_6 ( struct V_39 * V_39 ,
T_2 V_40 , T_1 * V_3 , T_1 V_4 , T_1 V_7 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
int V_44 ;
T_1 V_45 [ 20 ] ;
int V_46 = V_4 + 4 ;
T_1 V_8 ;
unsigned V_47 ;
if ( V_4 > 16 )
return - 1 ;
V_45 [ 0 ] = V_40 ;
V_45 [ 1 ] = V_40 >> 8 ;
V_45 [ 2 ] = V_48 << 4 ;
V_45 [ 3 ] = ( V_46 << 4 ) | ( V_4 - 1 ) ;
memcpy ( & V_45 [ 4 ] , V_3 , V_4 ) ;
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ ) {
V_44 = F_1 ( V_42 -> V_49 ,
V_45 , V_46 , NULL , 0 , V_7 , & V_8 ) ;
if ( V_44 == - V_37 )
continue;
else if ( V_44 < 0 )
return V_44 ;
if ( ( V_8 & V_50 ) == V_51 )
return V_4 ;
else if ( ( V_8 & V_50 ) == V_52 )
F_7 ( 400 ) ;
else
return - V_38 ;
}
return - V_38 ;
}
static int F_8 ( struct V_39 * V_39 ,
T_2 V_40 , T_1 * V_5 , int V_19 , T_1 V_7 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
T_1 V_45 [ 4 ] ;
int V_46 = 4 ;
T_1 V_8 ;
int V_44 ;
unsigned V_47 ;
V_45 [ 0 ] = V_40 ;
V_45 [ 1 ] = V_40 >> 8 ;
V_45 [ 2 ] = V_53 << 4 ;
V_45 [ 3 ] = ( V_46 << 4 ) | ( V_19 - 1 ) ;
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ ) {
V_44 = F_1 ( V_42 -> V_49 ,
V_45 , V_46 , V_5 , V_19 , V_7 , & V_8 ) ;
if ( V_44 == - V_37 )
continue;
else if ( V_44 < 0 )
return V_44 ;
if ( ( V_8 & V_50 ) == V_51 )
return V_44 ;
else if ( ( V_8 & V_50 ) == V_52 )
F_7 ( 400 ) ;
else if ( V_44 == 0 )
return - V_54 ;
else
return - V_38 ;
}
return - V_38 ;
}
static void F_9 ( struct V_39 * V_39 ,
T_2 V_55 , T_1 V_56 )
{
F_6 ( V_39 , V_55 , & V_56 , 1 , 0 ) ;
}
static T_1 F_10 ( struct V_39 * V_39 ,
T_2 V_55 )
{
T_1 V_56 = 0 ;
F_8 ( V_39 , V_55 , & V_56 , 1 , 0 ) ;
return V_56 ;
}
int F_11 ( struct V_57 * V_58 , int V_59 ,
T_1 V_60 , T_1 * V_61 )
{
struct V_62 * V_63 = V_58 -> V_63 ;
struct V_1 * V_64 = (struct V_1 * ) V_58 ;
T_2 V_40 = V_63 -> V_40 ;
T_1 V_45 [ 5 ] ;
T_1 V_65 [ 2 ] ;
unsigned V_47 ;
int V_46 ;
int V_66 = 1 ;
int V_44 ;
T_1 V_8 ;
if ( V_59 & V_67 )
V_45 [ 2 ] = V_68 << 4 ;
else
V_45 [ 2 ] = V_69 << 4 ;
if ( ! ( V_59 & V_70 ) )
V_45 [ 2 ] |= V_71 << 4 ;
V_45 [ 0 ] = V_40 ;
V_45 [ 1 ] = V_40 >> 8 ;
switch ( V_59 ) {
case V_72 :
V_46 = 5 ;
V_45 [ 3 ] = V_46 << 4 ;
V_45 [ 4 ] = V_60 ;
break;
case V_67 :
V_46 = 4 ;
V_45 [ 3 ] = V_46 << 4 ;
break;
default:
V_46 = 4 ;
V_45 [ 3 ] = 3 << 4 ;
break;
}
for ( V_47 = 0 ; V_47 < 4 ; V_47 ++ ) {
V_44 = F_1 ( V_64 ,
V_45 , V_46 , V_65 , V_66 , 0 , & V_8 ) ;
if ( V_44 == - V_37 )
continue;
else if ( V_44 < 0 ) {
F_5 ( L_4 , V_44 ) ;
return V_44 ;
}
switch ( V_8 & V_50 ) {
case V_51 :
break;
case V_73 :
F_5 ( L_5 ) ;
return - V_74 ;
case V_52 :
F_5 ( L_6 ) ;
F_7 ( 400 ) ;
continue;
default:
F_12 ( L_7 , V_8 ) ;
return - V_74 ;
}
switch ( V_8 & V_75 ) {
case V_76 :
if ( V_59 == V_67 )
* V_61 = V_65 [ 0 ] ;
return V_44 ;
case V_77 :
F_5 ( L_8 ) ;
return - V_74 ;
case V_78 :
F_5 ( L_9 ) ;
F_7 ( 400 ) ;
break;
default:
F_12 ( L_10 , V_8 ) ;
return - V_74 ;
}
}
F_5 ( L_11 ) ;
return - V_74 ;
}
static T_1 F_13 ( T_1 V_79 [ V_80 ] , int V_81 )
{
return V_79 [ V_81 - V_82 ] ;
}
static T_1 F_14 ( T_1 V_79 [ V_80 ] ,
int V_83 )
{
int V_84 = V_82 + ( V_83 >> 1 ) ;
int V_85 = ( V_83 & 1 ) * 4 ;
T_1 V_86 = F_13 ( V_79 , V_84 ) ;
return ( V_86 >> V_85 ) & 0xf ;
}
static bool F_15 ( T_1 V_79 [ V_80 ] ,
int V_87 )
{
int V_83 ;
T_1 V_88 ;
for ( V_83 = 0 ; V_83 < V_87 ; V_83 ++ ) {
V_88 = F_14 ( V_79 , V_83 ) ;
if ( ( V_88 & V_89 ) == 0 )
return false ;
}
return true ;
}
static bool F_16 ( T_1 V_79 [ V_80 ] ,
int V_87 )
{
T_1 V_90 ;
T_1 V_88 ;
int V_83 ;
V_90 = F_13 ( V_79 ,
V_91 ) ;
if ( ( V_90 & V_92 ) == 0 )
return false ;
for ( V_83 = 0 ; V_83 < V_87 ; V_83 ++ ) {
V_88 = F_14 ( V_79 , V_83 ) ;
if ( ( V_88 & V_93 ) != V_93 )
return false ;
}
return true ;
}
static T_1 F_17 ( T_1 V_79 [ V_80 ] ,
int V_83 )
{
int V_84 = V_94 + ( V_83 >> 1 ) ;
int V_85 = ( ( V_83 & 1 ) ?
V_95 :
V_96 ) ;
T_1 V_86 = F_13 ( V_79 , V_84 ) ;
return ( ( V_86 >> V_85 ) & 0x3 ) << V_97 ;
}
static T_1 F_18 ( T_1 V_79 [ V_80 ] ,
int V_83 )
{
int V_84 = V_94 + ( V_83 >> 1 ) ;
int V_85 = ( ( V_83 & 1 ) ?
V_98 :
V_99 ) ;
T_1 V_86 = F_13 ( V_79 , V_84 ) ;
return ( ( V_86 >> V_85 ) & 0x3 ) << V_100 ;
}
static void F_19 ( T_1 V_79 [ V_80 ] ,
int V_87 ,
T_1 V_101 [ 4 ] )
{
T_1 V_102 = 0 ;
T_1 V_103 = 0 ;
int V_83 ;
for ( V_83 = 0 ; V_83 < V_87 ; V_83 ++ ) {
T_1 V_104 = F_17 ( V_79 , V_83 ) ;
T_1 V_105 = F_18 ( V_79 , V_83 ) ;
F_5 ( L_12 ,
V_83 ,
V_106 [ V_104 >> V_97 ] ,
V_107 [ V_105 >> V_100 ] ) ;
if ( V_104 > V_102 )
V_102 = V_104 ;
if ( V_105 > V_103 )
V_103 = V_105 ;
}
if ( V_102 >= V_108 )
V_102 |= V_109 ;
if ( V_103 >= V_110 )
V_103 |= V_111 ;
F_5 ( L_13 ,
V_106 [ ( V_102 & V_112 ) >> V_97 ] ,
V_107 [ ( V_103 & V_113 ) >> V_100 ] ) ;
for ( V_83 = 0 ; V_83 < 4 ; V_83 ++ )
V_101 [ V_83 ] = V_102 | V_103 ;
}
static int F_20 ( int V_114 )
{
if ( V_114 == 0 )
return 24 ;
else
return V_114 * 3 ;
}
static int F_21 ( int V_115 ,
int V_116 ,
int V_117 )
{
return ( V_115 * V_116 * 8 ) / V_117 ;
}
static int F_22 ( T_1 V_118 [ V_119 ] )
{
switch ( V_118 [ V_120 ] ) {
case V_121 :
default:
return 162000 ;
case V_122 :
return 270000 ;
case V_123 :
return 540000 ;
}
}
static T_1 F_23 ( T_1 V_118 [ V_119 ] )
{
return V_118 [ V_124 ] & V_125 ;
}
static T_1 F_24 ( int V_115 )
{
switch ( V_115 ) {
case 162000 :
default:
return V_121 ;
case 270000 :
return V_122 ;
case 540000 :
return V_123 ;
}
}
static int F_25 ( struct V_126 * V_127 ,
T_1 V_118 [ V_119 ] ,
int V_128 )
{
int V_117 = F_20 ( F_26 ( V_127 ) ) ;
int V_129 = F_22 ( V_118 ) ;
int V_130 = F_23 ( V_118 ) ;
int V_116 ;
int V_131 ;
for ( V_116 = 1 ; V_116 < V_130 ; V_116 <<= 1 ) {
V_131 = F_21 ( V_129 , V_116 , V_117 ) ;
if ( V_128 <= V_131 )
break;
}
return V_116 ;
}
static int F_27 ( struct V_126 * V_127 ,
T_1 V_118 [ V_119 ] ,
int V_128 )
{
int V_117 = F_20 ( F_26 ( V_127 ) ) ;
int V_116 , V_132 ;
if ( F_28 ( V_127 ) ==
V_133 )
return 270000 ;
V_116 = F_25 ( V_127 , V_118 , V_128 ) ;
V_132 = F_21 ( 162000 , V_116 , V_117 ) ;
if ( V_128 <= V_132 )
return 162000 ;
V_132 = F_21 ( 270000 , V_116 , V_117 ) ;
if ( V_128 <= V_132 )
return 270000 ;
if ( F_29 ( V_127 ) ) {
V_132 = F_21 ( 540000 , V_116 , V_117 ) ;
if ( V_128 <= V_132 )
return 540000 ;
}
return F_22 ( V_118 ) ;
}
static T_1 F_30 ( struct V_11 * V_12 ,
int V_134 , int V_135 ,
T_1 V_136 , T_1 V_116 )
{
T_3 args ;
int V_15 = F_2 ( V_16 , V_137 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_138 = V_135 / 10 ;
args . V_139 = V_136 ;
args . V_140 = V_134 ;
args . V_141 = V_116 ;
args . V_142 = 0 ;
F_4 ( V_12 -> V_20 . V_21 , V_15 , ( V_34 * ) & args ) ;
return args . V_142 ;
}
T_1 F_31 ( struct V_39 * V_39 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
struct V_9 * V_10 = V_39 -> V_18 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
return F_30 ( V_12 , V_143 , 0 ,
V_42 -> V_49 -> V_28 . V_29 , 0 ) ;
}
static void F_32 ( struct V_39 * V_39 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
T_1 V_144 [ 3 ] ;
if ( ! ( V_42 -> V_118 [ V_145 ] & V_146 ) )
return;
if ( F_8 ( V_39 , V_147 , V_144 , 3 , 0 ) )
F_5 ( L_14 ,
V_144 [ 0 ] , V_144 [ 1 ] , V_144 [ 2 ] ) ;
if ( F_8 ( V_39 , V_148 , V_144 , 3 , 0 ) )
F_5 ( L_15 ,
V_144 [ 0 ] , V_144 [ 1 ] , V_144 [ 2 ] ) ;
}
bool F_33 ( struct V_39 * V_39 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
T_1 V_45 [ 25 ] ;
int V_44 , V_84 ;
V_44 = F_8 ( V_39 , V_149 , V_45 , 8 , 0 ) ;
if ( V_44 > 0 ) {
memcpy ( V_42 -> V_118 , V_45 , 8 ) ;
F_5 ( L_16 ) ;
for ( V_84 = 0 ; V_84 < 8 ; V_84 ++ )
F_5 ( L_17 , V_45 [ V_84 ] ) ;
F_5 ( L_18 ) ;
F_32 ( V_39 ) ;
return true ;
}
V_42 -> V_118 [ 0 ] = 0 ;
return false ;
}
int F_34 ( struct V_150 * V_151 ,
struct V_126 * V_127 )
{
struct V_9 * V_10 = V_151 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_39 * V_39 = F_35 ( V_127 ) ;
int V_152 = V_153 ;
T_2 V_154 = F_28 ( V_127 ) ;
T_1 V_155 ;
if ( ! F_3 ( V_12 ) )
return V_152 ;
if ( V_154 != V_156 ) {
V_155 = F_10 ( V_39 , V_157 ) ;
if ( V_155 & 1 )
V_152 = V_158 ;
else if ( ( V_154 == V_133 ) ||
( V_154 == V_159 ) )
V_152 = V_160 ;
else
V_152 = V_153 ;
} else if ( V_127 -> V_161 == V_162 ) {
V_155 = F_10 ( V_39 , V_157 ) ;
if ( V_155 & 1 )
V_152 = V_158 ;
}
return V_152 ;
}
void F_36 ( struct V_126 * V_127 ,
const struct V_163 * V_59 )
{
struct V_39 * V_39 = F_35 ( V_127 ) ;
struct V_41 * V_42 ;
if ( ! V_39 -> V_43 )
return;
V_42 = V_39 -> V_43 ;
if ( ( V_42 -> V_164 == V_165 ) ||
( V_42 -> V_164 == V_166 ) ) {
V_42 -> V_135 =
F_27 ( V_127 , V_42 -> V_118 , V_59 -> clock ) ;
V_42 -> V_167 =
F_25 ( V_127 , V_42 -> V_118 , V_59 -> clock ) ;
}
}
int F_37 ( struct V_126 * V_127 ,
struct V_163 * V_59 )
{
struct V_39 * V_39 = F_35 ( V_127 ) ;
struct V_41 * V_42 ;
int V_135 ;
if ( ! V_39 -> V_43 )
return V_168 ;
V_42 = V_39 -> V_43 ;
V_135 =
F_27 ( V_127 , V_42 -> V_118 , V_59 -> clock ) ;
if ( ( V_135 == 540000 ) &&
( ! F_29 ( V_127 ) ) )
return V_168 ;
return V_169 ;
}
static bool F_38 ( struct V_39 * V_39 ,
T_1 V_79 [ V_80 ] )
{
int V_44 ;
V_44 = F_8 ( V_39 , V_82 ,
V_79 , V_80 , 100 ) ;
if ( V_44 <= 0 ) {
return false ;
}
F_5 ( L_19 , 6 , V_79 ) ;
return true ;
}
bool F_39 ( struct V_39 * V_39 )
{
T_1 V_79 [ V_80 ] ;
struct V_41 * V_170 = V_39 -> V_43 ;
if ( ! F_38 ( V_39 , V_79 ) )
return false ;
if ( F_16 ( V_79 , V_170 -> V_167 ) )
return false ;
return true ;
}
static void F_40 ( struct V_171 * V_172 )
{
F_41 ( V_172 -> V_151 ,
V_173 ,
0 , V_172 -> V_101 [ 0 ] ) ;
F_6 ( V_172 -> V_39 , V_174 ,
V_172 -> V_101 , V_172 -> V_167 , 0 ) ;
}
static void F_42 ( struct V_171 * V_172 , int V_175 )
{
int V_176 = 0 ;
if ( F_3 ( V_172 -> V_12 ) || ! V_172 -> V_177 ) {
switch ( V_175 ) {
case V_178 :
V_176 = V_179 ;
break;
case V_180 :
V_176 = V_181 ;
break;
case V_182 :
V_176 = V_183 ;
break;
}
F_43 ( V_172 -> V_151 , V_176 , 0 ) ;
} else {
switch ( V_175 ) {
case V_178 :
V_176 = 0 ;
break;
case V_180 :
V_176 = 1 ;
break;
}
F_30 ( V_172 -> V_12 , V_184 ,
V_172 -> V_135 , V_172 -> V_185 , V_176 ) ;
}
F_9 ( V_172 -> V_39 , V_186 , V_175 ) ;
}
static int F_44 ( struct V_171 * V_172 )
{
struct V_187 * V_187 = F_45 ( V_172 -> V_151 ) ;
struct V_188 * V_170 = V_187 -> V_189 ;
T_1 V_155 ;
if ( V_172 -> V_118 [ 0 ] >= 0x11 )
F_9 ( V_172 -> V_39 ,
V_190 , V_191 ) ;
if ( V_172 -> V_118 [ 3 ] & 0x1 )
F_9 ( V_172 -> V_39 ,
V_192 , V_193 ) ;
else
F_9 ( V_172 -> V_39 ,
V_192 , 0 ) ;
if ( ( V_172 -> V_127 -> V_161 == V_162 ) &&
( V_170 -> V_152 == V_158 ) ) {
F_9 ( V_172 -> V_39 , V_194 , 1 ) ;
}
V_155 = V_172 -> V_167 ;
if ( V_172 -> V_118 [ V_149 ] >= 0x11 &&
V_172 -> V_118 [ V_124 ] & V_195 )
V_155 |= V_196 ;
F_9 ( V_172 -> V_39 , V_197 , V_155 ) ;
V_155 = F_24 ( V_172 -> V_135 ) ;
F_9 ( V_172 -> V_39 , V_198 , V_155 ) ;
if ( F_3 ( V_172 -> V_12 ) || ! V_172 -> V_177 )
F_43 ( V_172 -> V_151 ,
V_199 , 0 ) ;
else
F_30 ( V_172 -> V_12 , V_200 ,
V_172 -> V_135 , V_172 -> V_185 , 0 ) ;
F_9 ( V_172 -> V_39 ,
V_186 ,
V_201 ) ;
return 0 ;
}
static int F_46 ( struct V_171 * V_172 )
{
F_7 ( 400 ) ;
F_9 ( V_172 -> V_39 ,
V_186 ,
V_201 ) ;
if ( F_3 ( V_172 -> V_12 ) || ! V_172 -> V_177 )
F_43 ( V_172 -> V_151 ,
V_202 , 0 ) ;
else
F_30 ( V_172 -> V_12 , V_203 ,
V_172 -> V_135 , V_172 -> V_185 , 0 ) ;
return 0 ;
}
static int F_47 ( struct V_171 * V_172 )
{
bool V_204 ;
T_1 V_205 ;
int V_84 ;
F_42 ( V_172 , V_178 ) ;
memset ( V_172 -> V_101 , 0 , 4 ) ;
F_40 ( V_172 ) ;
F_7 ( 400 ) ;
V_204 = false ;
V_172 -> V_206 = 0 ;
V_205 = 0xff ;
while ( 1 ) {
if ( V_172 -> V_207 == 0 )
F_7 ( 100 ) ;
else
F_48 ( V_172 -> V_207 * 4 ) ;
if ( ! F_38 ( V_172 -> V_39 , V_172 -> V_79 ) ) {
F_12 ( L_20 ) ;
break;
}
if ( F_15 ( V_172 -> V_79 , V_172 -> V_167 ) ) {
V_204 = true ;
break;
}
for ( V_84 = 0 ; V_84 < V_172 -> V_167 ; V_84 ++ ) {
if ( ( V_172 -> V_101 [ V_84 ] & V_109 ) == 0 )
break;
}
if ( V_84 == V_172 -> V_167 ) {
F_12 ( L_21 ) ;
break;
}
if ( ( V_172 -> V_101 [ 0 ] & V_112 ) == V_205 ) {
++ V_172 -> V_206 ;
if ( V_172 -> V_206 == 5 ) {
F_12 ( L_22 ) ;
break;
}
} else
V_172 -> V_206 = 0 ;
V_205 = V_172 -> V_101 [ 0 ] & V_112 ;
F_19 ( V_172 -> V_79 , V_172 -> V_167 , V_172 -> V_101 ) ;
F_40 ( V_172 ) ;
}
if ( ! V_204 ) {
F_12 ( L_23 ) ;
return - 1 ;
} else {
F_5 ( L_24 ,
V_172 -> V_101 [ 0 ] & V_112 ,
( V_172 -> V_101 [ 0 ] & V_113 ) >>
V_100 ) ;
return 0 ;
}
}
static int F_49 ( struct V_171 * V_172 )
{
bool V_208 ;
if ( V_172 -> V_209 )
F_42 ( V_172 , V_182 ) ;
else
F_42 ( V_172 , V_180 ) ;
V_172 -> V_206 = 0 ;
V_208 = false ;
while ( 1 ) {
if ( V_172 -> V_207 == 0 )
F_7 ( 400 ) ;
else
F_48 ( V_172 -> V_207 * 4 ) ;
if ( ! F_38 ( V_172 -> V_39 , V_172 -> V_79 ) ) {
F_12 ( L_20 ) ;
break;
}
if ( F_16 ( V_172 -> V_79 , V_172 -> V_167 ) ) {
V_208 = true ;
break;
}
if ( V_172 -> V_206 > 5 ) {
F_12 ( L_25 ) ;
break;
}
F_19 ( V_172 -> V_79 , V_172 -> V_167 , V_172 -> V_101 ) ;
F_40 ( V_172 ) ;
V_172 -> V_206 ++ ;
}
if ( ! V_208 ) {
F_12 ( L_26 ) ;
return - 1 ;
} else {
F_5 ( L_27 ,
V_172 -> V_101 [ 0 ] & V_112 ,
( V_172 -> V_101 [ 0 ] & V_113 )
>> V_100 ) ;
return 0 ;
}
}
void F_50 ( struct V_150 * V_151 ,
struct V_126 * V_127 )
{
struct V_9 * V_10 = V_151 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_187 * V_187 = F_45 ( V_151 ) ;
struct V_188 * V_170 ;
struct V_39 * V_39 ;
struct V_41 * V_42 ;
struct V_171 V_172 ;
int V_15 ;
T_1 V_155 , V_210 , V_211 ;
if ( ! V_187 -> V_189 )
return;
V_170 = V_187 -> V_189 ;
V_39 = F_35 ( V_127 ) ;
if ( ! V_39 -> V_43 )
return;
V_42 = V_39 -> V_43 ;
if ( ( V_42 -> V_164 != V_165 ) &&
( V_42 -> V_164 != V_166 ) )
return;
V_172 . V_177 = true ;
V_15 = F_2 ( V_16 , V_137 ) ;
if ( F_51 ( V_12 -> V_20 . V_21 , V_15 , & V_210 , & V_211 ) ) {
if ( V_211 > 1 ) {
V_172 . V_177 = false ;
}
}
V_172 . V_185 = 0 ;
if ( V_170 -> V_212 )
V_172 . V_185 |= V_213 ;
else
V_172 . V_185 |= V_214 ;
if ( V_170 -> V_215 )
V_172 . V_185 |= V_216 ;
else
V_172 . V_185 |= V_217 ;
V_172 . V_207 = F_10 ( V_39 , V_218 ) ;
V_155 = F_10 ( V_39 , V_124 ) ;
if ( F_52 ( V_12 ) && ( V_155 & V_219 ) )
V_172 . V_209 = true ;
else
V_172 . V_209 = false ;
memcpy ( V_172 . V_118 , V_42 -> V_118 , 8 ) ;
V_172 . V_12 = V_12 ;
V_172 . V_151 = V_151 ;
V_172 . V_127 = V_127 ;
V_172 . V_39 = V_39 ;
V_172 . V_167 = V_42 -> V_167 ;
V_172 . V_135 = V_42 -> V_135 ;
if ( F_44 ( & V_172 ) )
goto V_220;
if ( F_47 ( & V_172 ) )
goto V_220;
if ( F_49 ( & V_172 ) )
goto V_220;
V_220:
if ( F_46 ( & V_172 ) )
return;
}
