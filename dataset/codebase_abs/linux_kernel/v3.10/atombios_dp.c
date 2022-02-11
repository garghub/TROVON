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
static void F_13 ( T_1 V_79 [ V_80 ] ,
int V_81 ,
T_1 V_82 [ 4 ] )
{
T_1 V_83 = 0 ;
T_1 V_84 = 0 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_81 ; V_85 ++ ) {
T_1 V_86 = F_14 ( V_79 , V_85 ) ;
T_1 V_87 = F_15 ( V_79 , V_85 ) ;
F_5 ( L_12 ,
V_85 ,
V_88 [ V_86 >> V_89 ] ,
V_90 [ V_87 >> V_91 ] ) ;
if ( V_86 > V_83 )
V_83 = V_86 ;
if ( V_87 > V_84 )
V_84 = V_87 ;
}
if ( V_83 >= V_92 )
V_83 |= V_93 ;
if ( V_84 >= V_94 )
V_84 |= V_95 ;
F_5 ( L_13 ,
V_88 [ ( V_83 & V_96 ) >> V_89 ] ,
V_90 [ ( V_84 & V_97 ) >> V_91 ] ) ;
for ( V_85 = 0 ; V_85 < 4 ; V_85 ++ )
V_82 [ V_85 ] = V_83 | V_84 ;
}
static int F_16 ( int V_98 )
{
if ( V_98 == 0 )
return 24 ;
else
return V_98 * 3 ;
}
static int F_17 ( int V_99 ,
int V_100 ,
int V_101 )
{
return ( V_99 * V_100 * 8 ) / V_101 ;
}
static int F_18 ( struct V_102 * V_103 ,
T_1 V_104 [ V_105 ] ,
int V_106 )
{
int V_101 = F_16 ( F_19 ( V_103 ) ) ;
int V_107 = F_20 ( V_104 ) ;
int V_108 = F_21 ( V_104 ) ;
int V_100 ;
int V_109 ;
for ( V_100 = 1 ; V_100 < V_108 ; V_100 <<= 1 ) {
V_109 = F_17 ( V_107 , V_100 , V_101 ) ;
if ( V_106 <= V_109 )
break;
}
return V_100 ;
}
static int F_22 ( struct V_102 * V_103 ,
T_1 V_104 [ V_105 ] ,
int V_106 )
{
int V_101 = F_16 ( F_19 ( V_103 ) ) ;
int V_100 , V_110 ;
if ( F_23 ( V_103 ) ==
V_111 )
return 270000 ;
V_100 = F_18 ( V_103 , V_104 , V_106 ) ;
V_110 = F_17 ( 162000 , V_100 , V_101 ) ;
if ( V_106 <= V_110 )
return 162000 ;
V_110 = F_17 ( 270000 , V_100 , V_101 ) ;
if ( V_106 <= V_110 )
return 270000 ;
if ( F_24 ( V_103 ) ) {
V_110 = F_17 ( 540000 , V_100 , V_101 ) ;
if ( V_106 <= V_110 )
return 540000 ;
}
return F_20 ( V_104 ) ;
}
static T_1 F_25 ( struct V_11 * V_12 ,
int V_112 , int V_113 ,
T_1 V_114 , T_1 V_100 )
{
T_3 args ;
int V_15 = F_2 ( V_16 , V_115 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_116 = V_113 / 10 ;
args . V_117 = V_114 ;
args . V_118 = V_112 ;
args . V_119 = V_100 ;
args . V_120 = 0 ;
F_4 ( V_12 -> V_20 . V_21 , V_15 , ( V_34 * ) & args ) ;
return args . V_120 ;
}
T_1 F_26 ( struct V_39 * V_39 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
struct V_9 * V_10 = V_39 -> V_18 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
return F_25 ( V_12 , V_121 , 0 ,
V_42 -> V_49 -> V_28 . V_29 , 0 ) ;
}
static void F_27 ( struct V_39 * V_39 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
T_1 V_122 [ 3 ] ;
if ( ! ( V_42 -> V_104 [ V_123 ] & V_124 ) )
return;
if ( F_8 ( V_39 , V_125 , V_122 , 3 , 0 ) )
F_5 ( L_14 ,
V_122 [ 0 ] , V_122 [ 1 ] , V_122 [ 2 ] ) ;
if ( F_8 ( V_39 , V_126 , V_122 , 3 , 0 ) )
F_5 ( L_15 ,
V_122 [ 0 ] , V_122 [ 1 ] , V_122 [ 2 ] ) ;
}
bool F_28 ( struct V_39 * V_39 )
{
struct V_41 * V_42 = V_39 -> V_43 ;
T_1 V_45 [ V_105 ] ;
int V_44 , V_127 ;
V_44 = F_8 ( V_39 , V_128 , V_45 ,
V_105 , 0 ) ;
if ( V_44 > 0 ) {
memcpy ( V_42 -> V_104 , V_45 , V_105 ) ;
F_5 ( L_16 ) ;
for ( V_127 = 0 ; V_127 < V_105 ; V_127 ++ )
F_5 ( L_17 , V_45 [ V_127 ] ) ;
F_5 ( L_18 ) ;
F_27 ( V_39 ) ;
return true ;
}
V_42 -> V_104 [ 0 ] = 0 ;
return false ;
}
int F_29 ( struct V_129 * V_130 ,
struct V_102 * V_103 )
{
struct V_9 * V_10 = V_130 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_39 * V_39 = F_30 ( V_103 ) ;
int V_131 = V_132 ;
T_2 V_133 = F_23 ( V_103 ) ;
T_1 V_134 ;
if ( ! F_3 ( V_12 ) )
return V_131 ;
if ( V_133 != V_135 ) {
V_134 = F_10 ( V_39 , V_136 ) ;
if ( V_134 & 1 )
V_131 = V_137 ;
else if ( ( V_133 == V_111 ) ||
( V_133 == V_138 ) )
V_131 = V_139 ;
else
V_131 = V_132 ;
} else if ( V_103 -> V_140 == V_141 ) {
V_134 = F_10 ( V_39 , V_136 ) ;
if ( V_134 & 1 )
V_131 = V_137 ;
}
return V_131 ;
}
void F_31 ( struct V_102 * V_103 ,
const struct V_142 * V_59 )
{
struct V_39 * V_39 = F_30 ( V_103 ) ;
struct V_41 * V_42 ;
if ( ! V_39 -> V_43 )
return;
V_42 = V_39 -> V_43 ;
if ( ( V_42 -> V_143 == V_144 ) ||
( V_42 -> V_143 == V_145 ) ) {
V_42 -> V_113 =
F_22 ( V_103 , V_42 -> V_104 , V_59 -> clock ) ;
V_42 -> V_146 =
F_18 ( V_103 , V_42 -> V_104 , V_59 -> clock ) ;
}
}
int F_32 ( struct V_102 * V_103 ,
struct V_142 * V_59 )
{
struct V_39 * V_39 = F_30 ( V_103 ) ;
struct V_41 * V_42 ;
int V_113 ;
if ( ! V_39 -> V_43 )
return V_147 ;
V_42 = V_39 -> V_43 ;
V_113 =
F_22 ( V_103 , V_42 -> V_104 , V_59 -> clock ) ;
if ( ( V_113 == 540000 ) &&
( ! F_24 ( V_103 ) ) )
return V_147 ;
return V_148 ;
}
static bool F_33 ( struct V_39 * V_39 ,
T_1 V_79 [ V_80 ] )
{
int V_44 ;
V_44 = F_8 ( V_39 , V_149 ,
V_79 , V_80 , 100 ) ;
if ( V_44 <= 0 ) {
return false ;
}
F_5 ( L_19 , 6 , V_79 ) ;
return true ;
}
bool F_34 ( struct V_39 * V_39 )
{
T_1 V_79 [ V_80 ] ;
struct V_41 * V_150 = V_39 -> V_43 ;
if ( ! F_33 ( V_39 , V_79 ) )
return false ;
if ( F_35 ( V_79 , V_150 -> V_146 ) )
return false ;
return true ;
}
static void F_36 ( struct V_151 * V_152 )
{
F_37 ( V_152 -> V_130 ,
V_153 ,
0 , V_152 -> V_82 [ 0 ] ) ;
F_6 ( V_152 -> V_39 , V_154 ,
V_152 -> V_82 , V_152 -> V_146 , 0 ) ;
}
static void F_38 ( struct V_151 * V_152 , int V_155 )
{
int V_156 = 0 ;
if ( F_3 ( V_152 -> V_12 ) || ! V_152 -> V_157 ) {
switch ( V_155 ) {
case V_158 :
V_156 = V_159 ;
break;
case V_160 :
V_156 = V_161 ;
break;
case V_162 :
V_156 = V_163 ;
break;
}
F_39 ( V_152 -> V_130 , V_156 , 0 ) ;
} else {
switch ( V_155 ) {
case V_158 :
V_156 = 0 ;
break;
case V_160 :
V_156 = 1 ;
break;
}
F_25 ( V_152 -> V_12 , V_164 ,
V_152 -> V_113 , V_152 -> V_165 , V_156 ) ;
}
F_9 ( V_152 -> V_39 , V_166 , V_155 ) ;
}
static int F_40 ( struct V_151 * V_152 )
{
struct V_167 * V_167 = F_41 ( V_152 -> V_130 ) ;
struct V_168 * V_150 = V_167 -> V_169 ;
T_1 V_134 ;
if ( V_152 -> V_104 [ 0 ] >= 0x11 )
F_9 ( V_152 -> V_39 ,
V_170 , V_171 ) ;
if ( V_152 -> V_104 [ 3 ] & 0x1 )
F_9 ( V_152 -> V_39 ,
V_172 , V_173 ) ;
else
F_9 ( V_152 -> V_39 ,
V_172 , 0 ) ;
if ( ( V_152 -> V_103 -> V_140 == V_141 ) &&
( V_150 -> V_131 == V_137 ) ) {
F_9 ( V_152 -> V_39 , V_174 , 1 ) ;
}
V_134 = V_152 -> V_146 ;
if ( V_152 -> V_104 [ V_128 ] >= 0x11 &&
V_152 -> V_104 [ V_175 ] & V_176 )
V_134 |= V_177 ;
F_9 ( V_152 -> V_39 , V_178 , V_134 ) ;
V_134 = F_42 ( V_152 -> V_113 ) ;
F_9 ( V_152 -> V_39 , V_179 , V_134 ) ;
if ( F_3 ( V_152 -> V_12 ) || ! V_152 -> V_157 )
F_39 ( V_152 -> V_130 ,
V_180 , 0 ) ;
else
F_25 ( V_152 -> V_12 , V_181 ,
V_152 -> V_113 , V_152 -> V_165 , 0 ) ;
F_9 ( V_152 -> V_39 ,
V_166 ,
V_182 ) ;
return 0 ;
}
static int F_43 ( struct V_151 * V_152 )
{
F_7 ( 400 ) ;
F_9 ( V_152 -> V_39 ,
V_166 ,
V_182 ) ;
if ( F_3 ( V_152 -> V_12 ) || ! V_152 -> V_157 )
F_39 ( V_152 -> V_130 ,
V_183 , 0 ) ;
else
F_25 ( V_152 -> V_12 , V_184 ,
V_152 -> V_113 , V_152 -> V_165 , 0 ) ;
return 0 ;
}
static int F_44 ( struct V_151 * V_152 )
{
bool V_185 ;
T_1 V_186 ;
int V_127 ;
F_38 ( V_152 , V_158 ) ;
memset ( V_152 -> V_82 , 0 , 4 ) ;
F_36 ( V_152 ) ;
F_7 ( 400 ) ;
V_185 = false ;
V_152 -> V_187 = 0 ;
V_186 = 0xff ;
while ( 1 ) {
F_45 ( V_152 -> V_104 ) ;
if ( ! F_33 ( V_152 -> V_39 , V_152 -> V_79 ) ) {
F_12 ( L_20 ) ;
break;
}
if ( F_46 ( V_152 -> V_79 , V_152 -> V_146 ) ) {
V_185 = true ;
break;
}
for ( V_127 = 0 ; V_127 < V_152 -> V_146 ; V_127 ++ ) {
if ( ( V_152 -> V_82 [ V_127 ] & V_93 ) == 0 )
break;
}
if ( V_127 == V_152 -> V_146 ) {
F_12 ( L_21 ) ;
break;
}
if ( ( V_152 -> V_82 [ 0 ] & V_96 ) == V_186 ) {
++ V_152 -> V_187 ;
if ( V_152 -> V_187 == 5 ) {
F_12 ( L_22 ) ;
break;
}
} else
V_152 -> V_187 = 0 ;
V_186 = V_152 -> V_82 [ 0 ] & V_96 ;
F_13 ( V_152 -> V_79 , V_152 -> V_146 , V_152 -> V_82 ) ;
F_36 ( V_152 ) ;
}
if ( ! V_185 ) {
F_12 ( L_23 ) ;
return - 1 ;
} else {
F_5 ( L_24 ,
V_152 -> V_82 [ 0 ] & V_96 ,
( V_152 -> V_82 [ 0 ] & V_97 ) >>
V_91 ) ;
return 0 ;
}
}
static int F_47 ( struct V_151 * V_152 )
{
bool V_188 ;
if ( V_152 -> V_189 )
F_38 ( V_152 , V_162 ) ;
else
F_38 ( V_152 , V_160 ) ;
V_152 -> V_187 = 0 ;
V_188 = false ;
while ( 1 ) {
F_48 ( V_152 -> V_104 ) ;
if ( ! F_33 ( V_152 -> V_39 , V_152 -> V_79 ) ) {
F_12 ( L_20 ) ;
break;
}
if ( F_35 ( V_152 -> V_79 , V_152 -> V_146 ) ) {
V_188 = true ;
break;
}
if ( V_152 -> V_187 > 5 ) {
F_12 ( L_25 ) ;
break;
}
F_13 ( V_152 -> V_79 , V_152 -> V_146 , V_152 -> V_82 ) ;
F_36 ( V_152 ) ;
V_152 -> V_187 ++ ;
}
if ( ! V_188 ) {
F_12 ( L_26 ) ;
return - 1 ;
} else {
F_5 ( L_27 ,
V_152 -> V_82 [ 0 ] & V_96 ,
( V_152 -> V_82 [ 0 ] & V_97 )
>> V_91 ) ;
return 0 ;
}
}
void F_49 ( struct V_129 * V_130 ,
struct V_102 * V_103 )
{
struct V_9 * V_10 = V_130 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_167 * V_167 = F_41 ( V_130 ) ;
struct V_168 * V_150 ;
struct V_39 * V_39 ;
struct V_41 * V_42 ;
struct V_151 V_152 ;
int V_15 ;
T_1 V_134 , V_190 , V_191 ;
if ( ! V_167 -> V_169 )
return;
V_150 = V_167 -> V_169 ;
V_39 = F_30 ( V_103 ) ;
if ( ! V_39 -> V_43 )
return;
V_42 = V_39 -> V_43 ;
if ( ( V_42 -> V_143 != V_144 ) &&
( V_42 -> V_143 != V_145 ) )
return;
V_152 . V_157 = true ;
V_15 = F_2 ( V_16 , V_115 ) ;
if ( F_50 ( V_12 -> V_20 . V_21 , V_15 , & V_190 , & V_191 ) ) {
if ( V_191 > 1 ) {
V_152 . V_157 = false ;
}
}
V_152 . V_165 = 0 ;
if ( V_150 -> V_192 )
V_152 . V_165 |= V_193 ;
else
V_152 . V_165 |= V_194 ;
if ( V_150 -> V_195 )
V_152 . V_165 |= V_196 ;
else
V_152 . V_165 |= V_197 ;
V_134 = F_10 ( V_39 , V_175 ) ;
if ( F_51 ( V_12 ) && ( V_134 & V_198 ) )
V_152 . V_189 = true ;
else
V_152 . V_189 = false ;
memcpy ( V_152 . V_104 , V_42 -> V_104 , V_199 ) ;
V_152 . V_12 = V_12 ;
V_152 . V_130 = V_130 ;
V_152 . V_103 = V_103 ;
V_152 . V_39 = V_39 ;
V_152 . V_146 = V_42 -> V_146 ;
V_152 . V_113 = V_42 -> V_113 ;
if ( F_40 ( & V_152 ) )
goto V_200;
if ( F_44 ( & V_152 ) )
goto V_200;
if ( F_47 ( & V_152 ) )
goto V_200;
V_200:
if ( F_43 ( & V_152 ) )
return;
}
