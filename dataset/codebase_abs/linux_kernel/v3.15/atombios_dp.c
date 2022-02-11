void F_1 ( T_1 * V_1 , T_1 * V_2 , T_1 V_3 , bool V_4 )
{
#ifdef F_2
T_1 V_5 [ 20 ] , V_6 [ 20 ] ;
T_2 * V_7 , * V_8 ;
int V_9 ;
memcpy ( V_5 , V_2 , V_3 ) ;
V_8 = ( T_2 * ) V_5 ;
V_7 = ( T_2 * ) V_6 ;
if ( V_4 ) {
for ( V_9 = 0 ; V_9 < ( ( V_3 + 3 ) / 4 ) ; V_9 ++ )
V_7 [ V_9 ] = F_3 ( V_8 [ V_9 ] ) ;
memcpy ( V_1 , V_6 , V_3 ) ;
} else {
T_1 V_10 = V_3 & ~ 3 ;
for ( V_9 = 0 ; V_9 < ( ( V_3 + 3 ) / 4 ) ; V_9 ++ )
V_7 [ V_9 ] = F_4 ( V_8 [ V_9 ] ) ;
memcpy ( V_1 , V_6 , V_10 ) ;
if ( V_3 % 4 ) {
for ( V_9 = 0 ; V_9 < ( V_3 % 4 ) ; V_9 ++ )
V_1 [ V_10 + V_9 ] = V_6 [ V_10 + V_9 ] ;
}
}
#else
memcpy ( V_1 , V_2 , V_3 ) ;
#endif
}
static int F_5 ( struct V_11 * V_12 ,
T_1 * V_13 , int V_14 ,
T_1 * V_15 , int V_16 ,
T_1 V_17 , T_1 * V_18 )
{
struct V_19 * V_20 = V_12 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
union V_24 args ;
int V_25 = F_6 ( V_26 , V_27 ) ;
unsigned char * V_28 ;
int V_29 ;
memset ( & args , 0 , sizeof( args ) ) ;
V_28 = ( unsigned char * ) ( V_22 -> V_30 . V_31 -> V_32 + 1 ) ;
F_1 ( V_28 , V_13 , V_14 , true ) ;
args . V_33 . V_34 = F_7 ( ( V_35 ) ( 0 + 4 ) ) ;
args . V_33 . V_36 = F_7 ( ( V_35 ) ( 16 + 4 ) ) ;
args . V_33 . V_37 = 0 ;
args . V_33 . V_38 = V_12 -> V_39 . V_40 ;
args . V_33 . V_41 = V_17 / 10 ;
if ( F_8 ( V_22 ) )
args . V_42 . V_43 = V_12 -> V_39 . V_44 ;
F_9 ( V_22 -> V_30 . V_31 , V_25 , ( V_45 * ) & args ) ;
* V_18 = args . V_33 . V_46 ;
if ( args . V_33 . V_46 == 1 ) {
F_10 ( L_1 ) ;
return - V_47 ;
}
if ( args . V_33 . V_46 == 2 ) {
F_10 ( L_2 ) ;
return - V_48 ;
}
if ( args . V_33 . V_46 == 3 ) {
F_10 ( L_3 ) ;
return - V_49 ;
}
V_29 = args . V_33 . V_37 ;
if ( V_29 > V_16 )
V_29 = V_16 ;
if ( V_15 && V_16 )
F_1 ( V_15 , V_28 + 16 , V_29 , false ) ;
return V_29 ;
}
static T_3
F_11 ( struct V_50 * V_51 , struct V_52 * V_53 )
{
struct V_11 * V_12 =
F_12 ( V_51 , struct V_11 , V_51 ) ;
int V_54 ;
T_1 V_55 [ 20 ] ;
T_4 V_56 ;
T_1 V_18 , V_17 = 0 ;
if ( F_13 ( V_53 -> V_57 > 16 ) )
return - V_58 ;
V_55 [ 0 ] = V_53 -> V_59 & 0xff ;
V_55 [ 1 ] = V_53 -> V_59 >> 8 ;
V_55 [ 2 ] = V_53 -> V_60 << 4 ;
V_55 [ 3 ] = V_53 -> V_57 ? ( V_53 -> V_57 - 1 ) : 0 ;
switch ( V_53 -> V_60 & ~ V_61 ) {
case V_62 :
case V_63 :
V_56 = V_64 + V_53 -> V_57 ;
if ( V_53 -> V_57 == 0 )
V_55 [ 3 ] |= V_65 << 4 ;
else
V_55 [ 3 ] |= V_56 << 4 ;
memcpy ( V_55 + V_64 , V_53 -> V_66 , V_53 -> V_57 ) ;
V_54 = F_5 ( V_12 ,
V_55 , V_56 , NULL , 0 , V_17 , & V_18 ) ;
if ( V_54 >= 0 )
V_54 = V_53 -> V_57 ;
break;
case V_67 :
case V_68 :
V_56 = V_64 ;
if ( V_53 -> V_57 == 0 )
V_55 [ 3 ] |= V_65 << 4 ;
else
V_55 [ 3 ] |= V_56 << 4 ;
V_54 = F_5 ( V_12 ,
V_55 , V_56 , V_53 -> V_66 , V_53 -> V_57 , V_17 , & V_18 ) ;
break;
default:
V_54 = - V_69 ;
break;
}
if ( V_54 >= 0 )
V_53 -> V_70 = V_18 >> 4 ;
return V_54 ;
}
void F_14 ( struct V_71 * V_71 )
{
int V_54 ;
V_71 -> V_72 -> V_39 . V_44 = V_71 -> V_44 . V_44 ;
V_71 -> V_72 -> V_51 . V_20 = V_71 -> V_28 . V_73 ;
V_71 -> V_72 -> V_51 . V_74 = F_11 ;
V_54 = F_15 ( & V_71 -> V_72 -> V_51 ) ;
if ( ! V_54 )
V_71 -> V_72 -> V_75 = true ;
F_16 ( V_54 , L_4 , V_54 ) ;
}
static void F_17 ( T_1 V_76 [ V_77 ] ,
int V_78 ,
T_1 V_79 [ 4 ] )
{
T_1 V_80 = 0 ;
T_1 V_81 = 0 ;
int V_82 ;
for ( V_82 = 0 ; V_82 < V_78 ; V_82 ++ ) {
T_1 V_83 = F_18 ( V_76 , V_82 ) ;
T_1 V_84 = F_19 ( V_76 , V_82 ) ;
F_10 ( L_5 ,
V_82 ,
V_85 [ V_83 >> V_86 ] ,
V_87 [ V_84 >> V_88 ] ) ;
if ( V_83 > V_80 )
V_80 = V_83 ;
if ( V_84 > V_81 )
V_81 = V_84 ;
}
if ( V_80 >= V_89 )
V_80 |= V_90 ;
if ( V_81 >= V_91 )
V_81 |= V_92 ;
F_10 ( L_6 ,
V_85 [ ( V_80 & V_93 ) >> V_86 ] ,
V_87 [ ( V_81 & V_94 ) >> V_88 ] ) ;
for ( V_82 = 0 ; V_82 < 4 ; V_82 ++ )
V_79 [ V_82 ] = V_80 | V_81 ;
}
static int F_20 ( int V_95 )
{
if ( V_95 == 0 )
return 24 ;
else
return V_95 * 3 ;
}
static int F_21 ( int V_96 ,
int V_97 ,
int V_98 )
{
return ( V_96 * V_97 * 8 ) / V_98 ;
}
static int F_22 ( struct V_99 * V_100 ,
T_1 V_101 [ V_102 ] ,
int V_103 )
{
int V_98 = F_20 ( F_23 ( V_100 ) ) ;
int V_104 = F_24 ( V_101 ) ;
int V_105 = F_25 ( V_101 ) ;
int V_97 ;
int V_106 ;
for ( V_97 = 1 ; V_97 < V_105 ; V_97 <<= 1 ) {
V_106 = F_21 ( V_104 , V_97 , V_98 ) ;
if ( V_103 <= V_106 )
break;
}
return V_97 ;
}
static int F_26 ( struct V_99 * V_100 ,
T_1 V_101 [ V_102 ] ,
int V_103 )
{
int V_98 = F_20 ( F_23 ( V_100 ) ) ;
int V_97 , V_107 ;
if ( F_27 ( V_100 ) ==
V_108 )
return 270000 ;
V_97 = F_22 ( V_100 , V_101 , V_103 ) ;
V_107 = F_21 ( 162000 , V_97 , V_98 ) ;
if ( V_103 <= V_107 )
return 162000 ;
V_107 = F_21 ( 270000 , V_97 , V_98 ) ;
if ( V_103 <= V_107 )
return 270000 ;
if ( F_28 ( V_100 ) ) {
V_107 = F_21 ( 540000 , V_97 , V_98 ) ;
if ( V_103 <= V_107 )
return 540000 ;
}
return F_24 ( V_101 ) ;
}
static T_1 F_29 ( struct V_21 * V_22 ,
int V_109 , int V_110 ,
T_1 V_111 , T_1 V_97 )
{
T_5 args ;
int V_25 = F_6 ( V_26 , V_112 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_113 = V_110 / 10 ;
args . V_114 = V_111 ;
args . V_115 = V_109 ;
args . V_116 = V_97 ;
args . V_117 = 0 ;
F_9 ( V_22 -> V_30 . V_31 , V_25 , ( V_45 * ) & args ) ;
return args . V_117 ;
}
T_1 F_30 ( struct V_71 * V_71 )
{
struct V_19 * V_20 = V_71 -> V_28 . V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
return F_29 ( V_22 , V_118 , 0 ,
V_71 -> V_72 -> V_39 . V_40 , 0 ) ;
}
static void F_31 ( struct V_71 * V_71 )
{
struct V_119 * V_120 = V_71 -> V_121 ;
T_1 V_122 [ 3 ] ;
if ( ! ( V_120 -> V_101 [ V_123 ] & V_124 ) )
return;
if ( F_32 ( & V_71 -> V_72 -> V_51 , V_125 , V_122 , 3 ) == 3 )
F_10 ( L_7 ,
V_122 [ 0 ] , V_122 [ 1 ] , V_122 [ 2 ] ) ;
if ( F_32 ( & V_71 -> V_72 -> V_51 , V_126 , V_122 , 3 ) == 3 )
F_10 ( L_8 ,
V_122 [ 0 ] , V_122 [ 1 ] , V_122 [ 2 ] ) ;
}
bool F_33 ( struct V_71 * V_71 )
{
struct V_119 * V_120 = V_71 -> V_121 ;
T_1 V_53 [ V_102 ] ;
int V_54 , V_9 ;
V_54 = F_32 ( & V_71 -> V_72 -> V_51 , V_127 , V_53 ,
V_102 ) ;
if ( V_54 > 0 ) {
memcpy ( V_120 -> V_101 , V_53 , V_102 ) ;
F_10 ( L_9 ) ;
for ( V_9 = 0 ; V_9 < V_102 ; V_9 ++ )
F_10 ( L_10 , V_53 [ V_9 ] ) ;
F_10 ( L_11 ) ;
F_31 ( V_71 ) ;
return true ;
}
V_120 -> V_101 [ 0 ] = 0 ;
return false ;
}
int F_34 ( struct V_128 * V_129 ,
struct V_99 * V_100 )
{
struct V_19 * V_20 = V_129 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_71 * V_71 = F_35 ( V_100 ) ;
struct V_119 * V_120 ;
int V_130 = V_131 ;
V_35 V_132 = F_27 ( V_100 ) ;
T_1 V_133 ;
if ( ! F_8 ( V_22 ) )
return V_130 ;
if ( ! V_71 -> V_121 )
return V_130 ;
V_120 = V_71 -> V_121 ;
if ( V_132 != V_134 ) {
if ( F_36 ( & V_71 -> V_72 -> V_51 ,
V_135 , & V_133 ) == 1 ) {
if ( V_133 & 1 )
V_130 = V_136 ;
else if ( ( V_132 == V_108 ) ||
( V_132 == V_137 ) )
V_130 = V_138 ;
else
V_130 = V_131 ;
}
} else if ( V_100 -> V_139 == V_140 ) {
if ( F_36 ( & V_71 -> V_72 -> V_51 ,
V_135 , & V_133 ) == 1 ) {
if ( V_133 & 1 )
V_130 = V_136 ;
}
}
return V_130 ;
}
void F_37 ( struct V_99 * V_100 ,
const struct V_141 * V_142 )
{
struct V_71 * V_71 = F_35 ( V_100 ) ;
struct V_119 * V_120 ;
if ( ! V_71 -> V_121 )
return;
V_120 = V_71 -> V_121 ;
if ( ( V_120 -> V_143 == V_144 ) ||
( V_120 -> V_143 == V_145 ) ) {
V_120 -> V_110 =
F_26 ( V_100 , V_120 -> V_101 , V_142 -> clock ) ;
V_120 -> V_146 =
F_22 ( V_100 , V_120 -> V_101 , V_142 -> clock ) ;
}
}
int F_38 ( struct V_99 * V_100 ,
struct V_141 * V_142 )
{
struct V_71 * V_71 = F_35 ( V_100 ) ;
struct V_119 * V_120 ;
int V_110 ;
if ( ! V_71 -> V_121 )
return V_147 ;
V_120 = V_71 -> V_121 ;
V_110 =
F_26 ( V_100 , V_120 -> V_101 , V_142 -> clock ) ;
if ( ( V_110 == 540000 ) &&
( ! F_28 ( V_100 ) ) )
return V_147 ;
return V_148 ;
}
bool F_39 ( struct V_71 * V_71 )
{
T_1 V_76 [ V_77 ] ;
struct V_119 * V_149 = V_71 -> V_121 ;
if ( F_40 ( & V_71 -> V_72 -> V_51 , V_76 )
<= 0 )
return false ;
if ( F_41 ( V_76 , V_149 -> V_146 ) )
return false ;
return true ;
}
void F_42 ( struct V_99 * V_100 ,
T_1 V_150 )
{
struct V_71 * V_71 = F_35 ( V_100 ) ;
struct V_119 * V_120 ;
if ( ! V_71 -> V_121 )
return;
V_120 = V_71 -> V_121 ;
if ( V_120 -> V_101 [ 0 ] >= 0x11 ) {
F_43 ( & V_71 -> V_72 -> V_51 ,
V_151 , V_150 ) ;
F_44 ( 1000 , 2000 ) ;
}
}
static void F_45 ( struct V_152 * V_153 )
{
F_46 ( V_153 -> V_129 ,
V_154 ,
0 , V_153 -> V_79 [ 0 ] ) ;
F_47 ( V_153 -> V_51 , V_155 ,
V_153 -> V_79 , V_153 -> V_146 ) ;
}
static void F_48 ( struct V_152 * V_153 , int V_156 )
{
int V_157 = 0 ;
if ( F_8 ( V_153 -> V_22 ) || ! V_153 -> V_158 ) {
switch ( V_156 ) {
case V_159 :
V_157 = V_160 ;
break;
case V_161 :
V_157 = V_162 ;
break;
case V_163 :
V_157 = V_164 ;
break;
}
F_49 ( V_153 -> V_129 , V_157 , 0 ) ;
} else {
switch ( V_156 ) {
case V_159 :
V_157 = 0 ;
break;
case V_161 :
V_157 = 1 ;
break;
}
F_29 ( V_153 -> V_22 , V_165 ,
V_153 -> V_110 , V_153 -> V_166 , V_157 ) ;
}
F_43 ( V_153 -> V_51 , V_167 , V_156 ) ;
}
static int F_50 ( struct V_152 * V_153 )
{
struct V_168 * V_168 = F_51 ( V_153 -> V_129 ) ;
struct V_169 * V_149 = V_168 -> V_170 ;
T_1 V_133 ;
F_42 ( V_153 -> V_100 , V_171 ) ;
if ( V_153 -> V_101 [ 3 ] & 0x1 )
F_43 ( V_153 -> V_51 ,
V_172 , V_173 ) ;
else
F_43 ( V_153 -> V_51 ,
V_172 , 0 ) ;
if ( ( V_153 -> V_100 -> V_139 == V_140 ) &&
( V_149 -> V_130 == V_136 ) ) {
F_43 ( V_153 -> V_51 , V_174 , 1 ) ;
}
V_133 = V_153 -> V_146 ;
if ( F_52 ( V_153 -> V_101 ) )
V_133 |= V_175 ;
F_43 ( V_153 -> V_51 , V_176 , V_133 ) ;
V_133 = F_53 ( V_153 -> V_110 ) ;
F_43 ( V_153 -> V_51 , V_177 , V_133 ) ;
if ( F_8 ( V_153 -> V_22 ) || ! V_153 -> V_158 )
F_49 ( V_153 -> V_129 ,
V_178 , 0 ) ;
else
F_29 ( V_153 -> V_22 , V_179 ,
V_153 -> V_110 , V_153 -> V_166 , 0 ) ;
F_43 ( V_153 -> V_51 ,
V_167 ,
V_180 ) ;
return 0 ;
}
static int F_54 ( struct V_152 * V_153 )
{
F_55 ( 400 ) ;
F_43 ( V_153 -> V_51 ,
V_167 ,
V_180 ) ;
if ( F_8 ( V_153 -> V_22 ) || ! V_153 -> V_158 )
F_49 ( V_153 -> V_129 ,
V_181 , 0 ) ;
else
F_29 ( V_153 -> V_22 , V_182 ,
V_153 -> V_110 , V_153 -> V_166 , 0 ) ;
return 0 ;
}
static int F_56 ( struct V_152 * V_153 )
{
bool V_183 ;
T_1 V_184 ;
int V_9 ;
F_48 ( V_153 , V_159 ) ;
memset ( V_153 -> V_79 , 0 , 4 ) ;
F_45 ( V_153 ) ;
F_55 ( 400 ) ;
V_183 = false ;
V_153 -> V_185 = 0 ;
V_184 = 0xff ;
while ( 1 ) {
F_57 ( V_153 -> V_101 ) ;
if ( F_40 ( V_153 -> V_51 ,
V_153 -> V_76 ) <= 0 ) {
F_58 ( L_12 ) ;
break;
}
if ( F_59 ( V_153 -> V_76 , V_153 -> V_146 ) ) {
V_183 = true ;
break;
}
for ( V_9 = 0 ; V_9 < V_153 -> V_146 ; V_9 ++ ) {
if ( ( V_153 -> V_79 [ V_9 ] & V_90 ) == 0 )
break;
}
if ( V_9 == V_153 -> V_146 ) {
F_58 ( L_13 ) ;
break;
}
if ( ( V_153 -> V_79 [ 0 ] & V_93 ) == V_184 ) {
++ V_153 -> V_185 ;
if ( V_153 -> V_185 == 5 ) {
F_58 ( L_14 ) ;
break;
}
} else
V_153 -> V_185 = 0 ;
V_184 = V_153 -> V_79 [ 0 ] & V_93 ;
F_17 ( V_153 -> V_76 , V_153 -> V_146 , V_153 -> V_79 ) ;
F_45 ( V_153 ) ;
}
if ( ! V_183 ) {
F_58 ( L_15 ) ;
return - 1 ;
} else {
F_10 ( L_16 ,
V_153 -> V_79 [ 0 ] & V_93 ,
( V_153 -> V_79 [ 0 ] & V_94 ) >>
V_88 ) ;
return 0 ;
}
}
static int F_60 ( struct V_152 * V_153 )
{
bool V_186 ;
if ( V_153 -> V_187 )
F_48 ( V_153 , V_163 ) ;
else
F_48 ( V_153 , V_161 ) ;
V_153 -> V_185 = 0 ;
V_186 = false ;
while ( 1 ) {
F_61 ( V_153 -> V_101 ) ;
if ( F_40 ( V_153 -> V_51 ,
V_153 -> V_76 ) <= 0 ) {
F_58 ( L_12 ) ;
break;
}
if ( F_41 ( V_153 -> V_76 , V_153 -> V_146 ) ) {
V_186 = true ;
break;
}
if ( V_153 -> V_185 > 5 ) {
F_58 ( L_17 ) ;
break;
}
F_17 ( V_153 -> V_76 , V_153 -> V_146 , V_153 -> V_79 ) ;
F_45 ( V_153 ) ;
V_153 -> V_185 ++ ;
}
if ( ! V_186 ) {
F_58 ( L_18 ) ;
return - 1 ;
} else {
F_10 ( L_19 ,
V_153 -> V_79 [ 0 ] & V_93 ,
( V_153 -> V_79 [ 0 ] & V_94 )
>> V_88 ) ;
return 0 ;
}
}
void F_62 ( struct V_128 * V_129 ,
struct V_99 * V_100 )
{
struct V_19 * V_20 = V_129 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_168 * V_168 = F_51 ( V_129 ) ;
struct V_169 * V_149 ;
struct V_71 * V_71 ;
struct V_119 * V_120 ;
struct V_152 V_153 ;
int V_25 ;
T_1 V_133 , V_188 , V_189 ;
if ( ! V_168 -> V_170 )
return;
V_149 = V_168 -> V_170 ;
V_71 = F_35 ( V_100 ) ;
if ( ! V_71 -> V_121 )
return;
V_120 = V_71 -> V_121 ;
if ( ( V_120 -> V_143 != V_144 ) &&
( V_120 -> V_143 != V_145 ) )
return;
V_153 . V_158 = true ;
V_25 = F_6 ( V_26 , V_112 ) ;
if ( F_63 ( V_22 -> V_30 . V_31 , V_25 , & V_188 , & V_189 ) ) {
if ( V_189 > 1 ) {
V_153 . V_158 = false ;
}
}
V_153 . V_166 = 0 ;
if ( V_149 -> V_190 )
V_153 . V_166 |= V_191 ;
else
V_153 . V_166 |= V_192 ;
if ( V_149 -> V_193 )
V_153 . V_166 |= V_194 ;
else
V_153 . V_166 |= V_195 ;
if ( F_36 ( & V_71 -> V_72 -> V_51 , V_196 , & V_133 )
== 1 ) {
if ( F_64 ( V_22 ) && ( V_133 & V_197 ) )
V_153 . V_187 = true ;
else
V_153 . V_187 = false ;
} else {
V_153 . V_187 = false ;
}
memcpy ( V_153 . V_101 , V_120 -> V_101 , V_198 ) ;
V_153 . V_22 = V_22 ;
V_153 . V_129 = V_129 ;
V_153 . V_100 = V_100 ;
V_153 . V_146 = V_120 -> V_146 ;
V_153 . V_110 = V_120 -> V_110 ;
V_153 . V_51 = & V_71 -> V_72 -> V_51 ;
if ( F_50 ( & V_153 ) )
goto V_199;
if ( F_56 ( & V_153 ) )
goto V_199;
if ( F_60 ( & V_153 ) )
goto V_199;
V_199:
if ( F_54 ( & V_153 ) )
return;
}
