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
int V_30 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
F_7 ( & V_12 -> V_31 ) ;
V_28 = ( unsigned char * ) ( V_22 -> V_32 . V_33 -> V_34 + 1 ) ;
F_1 ( V_28 , V_13 , V_14 , true ) ;
args . V_35 . V_36 = F_8 ( ( V_37 ) ( 0 + 4 ) ) ;
args . V_35 . V_38 = F_8 ( ( V_37 ) ( 16 + 4 ) ) ;
args . V_35 . V_39 = 0 ;
args . V_35 . V_40 = V_12 -> V_41 . V_42 ;
args . V_35 . V_43 = V_17 / 10 ;
if ( F_9 ( V_22 ) )
args . V_44 . V_45 = V_12 -> V_41 . V_46 ;
F_10 ( V_22 -> V_32 . V_33 , V_25 , ( V_47 * ) & args ) ;
* V_18 = args . V_35 . V_48 ;
if ( args . V_35 . V_48 == 1 ) {
F_11 ( L_1 ) ;
V_30 = - V_49 ;
goto V_50;
}
if ( args . V_35 . V_48 == 2 ) {
F_11 ( L_2 ) ;
V_30 = - V_51 ;
goto V_50;
}
if ( args . V_35 . V_48 == 3 ) {
F_11 ( L_3 ) ;
V_30 = - V_51 ;
goto V_50;
}
V_29 = args . V_35 . V_39 ;
if ( V_29 > V_16 )
V_29 = V_16 ;
if ( V_15 && V_16 )
F_1 ( V_15 , V_28 + 16 , V_29 , false ) ;
V_30 = V_29 ;
V_50:
F_12 ( & V_12 -> V_31 ) ;
return V_30 ;
}
static T_3
F_13 ( struct V_52 * V_53 , struct V_54 * V_55 )
{
struct V_11 * V_12 =
F_14 ( V_53 , struct V_11 , V_53 ) ;
int V_56 ;
T_1 V_57 [ 20 ] ;
T_4 V_58 ;
T_1 V_18 , V_17 = 0 ;
if ( F_15 ( V_55 -> V_59 > 16 ) )
return - V_60 ;
V_57 [ 0 ] = V_55 -> V_61 & 0xff ;
V_57 [ 1 ] = V_55 -> V_61 >> 8 ;
V_57 [ 2 ] = V_55 -> V_62 << 4 ;
V_57 [ 3 ] = V_55 -> V_59 ? ( V_55 -> V_59 - 1 ) : 0 ;
switch ( V_55 -> V_62 & ~ V_63 ) {
case V_64 :
case V_65 :
V_58 = V_66 + V_55 -> V_59 ;
if ( V_55 -> V_59 == 0 )
V_57 [ 3 ] |= V_67 << 4 ;
else
V_57 [ 3 ] |= V_58 << 4 ;
memcpy ( V_57 + V_66 , V_55 -> V_68 , V_55 -> V_59 ) ;
V_56 = F_5 ( V_12 ,
V_57 , V_58 , NULL , 0 , V_17 , & V_18 ) ;
if ( V_56 >= 0 )
V_56 = V_55 -> V_59 ;
break;
case V_69 :
case V_70 :
V_58 = V_66 ;
if ( V_55 -> V_59 == 0 )
V_57 [ 3 ] |= V_67 << 4 ;
else
V_57 [ 3 ] |= V_58 << 4 ;
V_56 = F_5 ( V_12 ,
V_57 , V_58 , V_55 -> V_68 , V_55 -> V_59 , V_17 , & V_18 ) ;
break;
default:
V_56 = - V_71 ;
break;
}
if ( V_56 >= 0 )
V_55 -> V_72 = V_18 >> 4 ;
return V_56 ;
}
void F_16 ( struct V_73 * V_73 )
{
int V_56 ;
V_73 -> V_74 -> V_41 . V_46 = V_73 -> V_46 . V_46 ;
V_73 -> V_74 -> V_53 . V_20 = V_73 -> V_28 . V_75 ;
V_73 -> V_74 -> V_53 . V_76 = F_13 ;
V_56 = F_17 ( & V_73 -> V_74 -> V_53 ) ;
if ( ! V_56 )
V_73 -> V_74 -> V_77 = true ;
F_18 ( V_56 , L_4 , V_56 ) ;
}
static void F_19 ( T_1 V_78 [ V_79 ] ,
int V_80 ,
T_1 V_81 [ 4 ] )
{
T_1 V_82 = 0 ;
T_1 V_83 = 0 ;
int V_84 ;
for ( V_84 = 0 ; V_84 < V_80 ; V_84 ++ ) {
T_1 V_85 = F_20 ( V_78 , V_84 ) ;
T_1 V_86 = F_21 ( V_78 , V_84 ) ;
F_11 ( L_5 ,
V_84 ,
V_87 [ V_85 >> V_88 ] ,
V_89 [ V_86 >> V_90 ] ) ;
if ( V_85 > V_82 )
V_82 = V_85 ;
if ( V_86 > V_83 )
V_83 = V_86 ;
}
if ( V_82 >= V_91 )
V_82 |= V_92 ;
if ( V_83 >= V_93 )
V_83 |= V_94 ;
F_11 ( L_6 ,
V_87 [ ( V_82 & V_95 ) >> V_88 ] ,
V_89 [ ( V_83 & V_96 ) >> V_90 ] ) ;
for ( V_84 = 0 ; V_84 < 4 ; V_84 ++ )
V_81 [ V_84 ] = V_82 | V_83 ;
}
static int F_22 ( int V_97 )
{
if ( V_97 == 0 )
return 24 ;
else
return V_97 * 3 ;
}
static int F_23 ( int V_98 ,
int V_99 ,
int V_100 )
{
return ( V_98 * V_99 * 8 ) / V_100 ;
}
static int F_24 ( struct V_101 * V_102 ,
T_1 V_103 [ V_104 ] )
{
int V_105 ;
if ( F_25 ( V_102 ) )
V_105 = F_26 ( F_27 ( V_103 ) , 540000 ) ;
else
V_105 = F_26 ( F_27 ( V_103 ) , 270000 ) ;
return V_105 ;
}
static int F_28 ( struct V_101 * V_102 ,
T_1 V_103 [ V_104 ] ,
int V_106 )
{
int V_100 = F_22 ( F_29 ( V_102 ) ) ;
int V_105 = F_24 ( V_102 , V_103 ) ;
int V_107 = F_30 ( V_103 ) ;
int V_99 ;
int V_108 ;
for ( V_99 = 1 ; V_99 < V_107 ; V_99 <<= 1 ) {
V_108 = F_23 ( V_105 , V_99 , V_100 ) ;
if ( V_106 <= V_108 )
break;
}
return V_99 ;
}
static int F_31 ( struct V_101 * V_102 ,
T_1 V_103 [ V_104 ] ,
int V_106 )
{
int V_100 = F_22 ( F_29 ( V_102 ) ) ;
int V_99 , V_109 ;
if ( F_32 ( V_102 ) ==
V_110 )
return 270000 ;
V_99 = F_28 ( V_102 , V_103 , V_106 ) ;
V_109 = F_23 ( 162000 , V_99 , V_100 ) ;
if ( V_106 <= V_109 )
return 162000 ;
V_109 = F_23 ( 270000 , V_99 , V_100 ) ;
if ( V_106 <= V_109 )
return 270000 ;
if ( F_25 ( V_102 ) ) {
V_109 = F_23 ( 540000 , V_99 , V_100 ) ;
if ( V_106 <= V_109 )
return 540000 ;
}
return F_24 ( V_102 , V_103 ) ;
}
static T_1 F_33 ( struct V_21 * V_22 ,
int V_111 , int V_112 ,
T_1 V_113 , T_1 V_99 )
{
T_5 args ;
int V_25 = F_6 ( V_26 , V_114 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_115 = V_112 / 10 ;
args . V_116 = V_113 ;
args . V_117 = V_111 ;
args . V_118 = V_99 ;
args . V_119 = 0 ;
F_10 ( V_22 -> V_32 . V_33 , V_25 , ( V_47 * ) & args ) ;
return args . V_119 ;
}
T_1 F_34 ( struct V_73 * V_73 )
{
struct V_19 * V_20 = V_73 -> V_28 . V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
return F_33 ( V_22 , V_120 , 0 ,
V_73 -> V_74 -> V_41 . V_42 , 0 ) ;
}
static void F_35 ( struct V_73 * V_73 )
{
struct V_121 * V_122 = V_73 -> V_123 ;
T_1 V_124 [ 3 ] ;
if ( ! ( V_122 -> V_103 [ V_125 ] & V_126 ) )
return;
if ( F_36 ( & V_73 -> V_74 -> V_53 , V_127 , V_124 , 3 ) == 3 )
F_11 ( L_7 ,
V_124 [ 0 ] , V_124 [ 1 ] , V_124 [ 2 ] ) ;
if ( F_36 ( & V_73 -> V_74 -> V_53 , V_128 , V_124 , 3 ) == 3 )
F_11 ( L_8 ,
V_124 [ 0 ] , V_124 [ 1 ] , V_124 [ 2 ] ) ;
}
bool F_37 ( struct V_73 * V_73 )
{
struct V_121 * V_122 = V_73 -> V_123 ;
T_1 V_55 [ V_104 ] ;
int V_56 ;
char V_129 [ V_104 * 3 ] ;
V_56 = F_36 ( & V_73 -> V_74 -> V_53 , V_130 , V_55 ,
V_104 ) ;
if ( V_56 > 0 ) {
memcpy ( V_122 -> V_103 , V_55 , V_104 ) ;
F_38 ( V_122 -> V_103 , sizeof( V_122 -> V_103 ) ,
32 , 1 , V_129 , sizeof( V_129 ) , false ) ;
F_11 ( L_9 , V_129 ) ;
F_35 ( V_73 ) ;
return true ;
}
V_122 -> V_103 [ 0 ] = 0 ;
return false ;
}
int F_39 ( struct V_131 * V_132 ,
struct V_101 * V_102 )
{
struct V_19 * V_20 = V_132 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_73 * V_73 = F_40 ( V_102 ) ;
struct V_121 * V_122 ;
int V_133 = V_134 ;
V_37 V_135 = F_32 ( V_102 ) ;
T_1 V_136 ;
if ( ! F_9 ( V_22 ) )
return V_133 ;
if ( ! V_73 -> V_123 )
return V_133 ;
V_122 = V_73 -> V_123 ;
if ( V_135 != V_137 ) {
if ( F_41 ( & V_73 -> V_74 -> V_53 ,
V_138 , & V_136 ) == 1 ) {
if ( V_136 & 1 )
V_133 = V_139 ;
else if ( ( V_135 == V_110 ) ||
( V_135 == V_140 ) )
V_133 = V_141 ;
else
V_133 = V_134 ;
}
} else if ( V_102 -> V_142 == V_143 ) {
if ( F_41 ( & V_73 -> V_74 -> V_53 ,
V_138 , & V_136 ) == 1 ) {
if ( V_136 & 1 )
V_133 = V_139 ;
}
}
return V_133 ;
}
void F_42 ( struct V_101 * V_102 ,
const struct V_144 * V_145 )
{
struct V_73 * V_73 = F_40 ( V_102 ) ;
struct V_121 * V_122 ;
if ( ! V_73 -> V_123 )
return;
V_122 = V_73 -> V_123 ;
if ( ( V_122 -> V_146 == V_147 ) ||
( V_122 -> V_146 == V_148 ) ) {
V_122 -> V_112 =
F_31 ( V_102 , V_122 -> V_103 , V_145 -> clock ) ;
V_122 -> V_149 =
F_28 ( V_102 , V_122 -> V_103 , V_145 -> clock ) ;
}
}
int F_43 ( struct V_101 * V_102 ,
struct V_144 * V_145 )
{
struct V_73 * V_73 = F_40 ( V_102 ) ;
struct V_121 * V_122 ;
int V_112 ;
if ( ! V_73 -> V_123 )
return V_150 ;
V_122 = V_73 -> V_123 ;
V_112 =
F_31 ( V_102 , V_122 -> V_103 , V_145 -> clock ) ;
if ( ( V_112 == 540000 ) &&
( ! F_25 ( V_102 ) ) )
return V_150 ;
return V_151 ;
}
bool F_44 ( struct V_73 * V_73 )
{
T_1 V_78 [ V_79 ] ;
struct V_121 * V_152 = V_73 -> V_123 ;
if ( F_45 ( & V_73 -> V_74 -> V_53 , V_78 )
<= 0 )
return false ;
if ( F_46 ( V_78 , V_152 -> V_149 ) )
return false ;
return true ;
}
void F_47 ( struct V_101 * V_102 ,
T_1 V_153 )
{
struct V_73 * V_73 = F_40 ( V_102 ) ;
struct V_121 * V_122 ;
if ( ! V_73 -> V_123 )
return;
V_122 = V_73 -> V_123 ;
if ( V_122 -> V_103 [ 0 ] >= 0x11 ) {
F_48 ( & V_73 -> V_74 -> V_53 ,
V_154 , V_153 ) ;
F_49 ( 1000 , 2000 ) ;
}
}
static void F_50 ( struct V_155 * V_156 )
{
F_51 ( V_156 -> V_132 ,
V_157 ,
0 , V_156 -> V_81 [ 0 ] ) ;
F_52 ( V_156 -> V_53 , V_158 ,
V_156 -> V_81 , V_156 -> V_149 ) ;
}
static void F_53 ( struct V_155 * V_156 , int V_159 )
{
int V_160 = 0 ;
if ( F_9 ( V_156 -> V_22 ) || ! V_156 -> V_161 ) {
switch ( V_159 ) {
case V_162 :
V_160 = V_163 ;
break;
case V_164 :
V_160 = V_165 ;
break;
case V_166 :
V_160 = V_167 ;
break;
}
F_54 ( V_156 -> V_132 , V_160 , 0 ) ;
} else {
switch ( V_159 ) {
case V_162 :
V_160 = 0 ;
break;
case V_164 :
V_160 = 1 ;
break;
}
F_33 ( V_156 -> V_22 , V_168 ,
V_156 -> V_112 , V_156 -> V_169 , V_160 ) ;
}
F_48 ( V_156 -> V_53 , V_170 , V_159 ) ;
}
static int F_55 ( struct V_155 * V_156 )
{
struct V_171 * V_171 = F_56 ( V_156 -> V_132 ) ;
struct V_172 * V_152 = V_171 -> V_173 ;
T_1 V_136 ;
F_47 ( V_156 -> V_102 , V_174 ) ;
if ( V_156 -> V_103 [ 3 ] & 0x1 )
F_48 ( V_156 -> V_53 ,
V_175 , V_176 ) ;
else
F_48 ( V_156 -> V_53 ,
V_175 , 0 ) ;
if ( ( V_156 -> V_102 -> V_142 == V_143 ) &&
( V_152 -> V_133 == V_139 ) ) {
F_48 ( V_156 -> V_53 , V_177 , 1 ) ;
}
V_136 = V_156 -> V_149 ;
if ( F_57 ( V_156 -> V_103 ) )
V_136 |= V_178 ;
F_48 ( V_156 -> V_53 , V_179 , V_136 ) ;
V_136 = F_58 ( V_156 -> V_112 ) ;
F_48 ( V_156 -> V_53 , V_180 , V_136 ) ;
if ( F_9 ( V_156 -> V_22 ) || ! V_156 -> V_161 )
F_54 ( V_156 -> V_132 ,
V_181 , 0 ) ;
else
F_33 ( V_156 -> V_22 , V_182 ,
V_156 -> V_112 , V_156 -> V_169 , 0 ) ;
F_48 ( V_156 -> V_53 ,
V_170 ,
V_183 ) ;
return 0 ;
}
static int F_59 ( struct V_155 * V_156 )
{
F_60 ( 400 ) ;
F_48 ( V_156 -> V_53 ,
V_170 ,
V_183 ) ;
if ( F_9 ( V_156 -> V_22 ) || ! V_156 -> V_161 )
F_54 ( V_156 -> V_132 ,
V_184 , 0 ) ;
else
F_33 ( V_156 -> V_22 , V_185 ,
V_156 -> V_112 , V_156 -> V_169 , 0 ) ;
return 0 ;
}
static int F_61 ( struct V_155 * V_156 )
{
bool V_186 ;
T_1 V_187 ;
int V_9 ;
F_53 ( V_156 , V_162 ) ;
memset ( V_156 -> V_81 , 0 , 4 ) ;
F_50 ( V_156 ) ;
F_60 ( 400 ) ;
V_186 = false ;
V_156 -> V_188 = 0 ;
V_187 = 0xff ;
while ( 1 ) {
F_62 ( V_156 -> V_103 ) ;
if ( F_45 ( V_156 -> V_53 ,
V_156 -> V_78 ) <= 0 ) {
F_63 ( L_10 ) ;
break;
}
if ( F_64 ( V_156 -> V_78 , V_156 -> V_149 ) ) {
V_186 = true ;
break;
}
for ( V_9 = 0 ; V_9 < V_156 -> V_149 ; V_9 ++ ) {
if ( ( V_156 -> V_81 [ V_9 ] & V_92 ) == 0 )
break;
}
if ( V_9 == V_156 -> V_149 ) {
F_63 ( L_11 ) ;
break;
}
if ( ( V_156 -> V_81 [ 0 ] & V_95 ) == V_187 ) {
++ V_156 -> V_188 ;
if ( V_156 -> V_188 == 5 ) {
F_63 ( L_12 ) ;
break;
}
} else
V_156 -> V_188 = 0 ;
V_187 = V_156 -> V_81 [ 0 ] & V_95 ;
F_19 ( V_156 -> V_78 , V_156 -> V_149 , V_156 -> V_81 ) ;
F_50 ( V_156 ) ;
}
if ( ! V_186 ) {
F_63 ( L_13 ) ;
return - 1 ;
} else {
F_11 ( L_14 ,
V_156 -> V_81 [ 0 ] & V_95 ,
( V_156 -> V_81 [ 0 ] & V_96 ) >>
V_90 ) ;
return 0 ;
}
}
static int F_65 ( struct V_155 * V_156 )
{
bool V_189 ;
if ( V_156 -> V_190 )
F_53 ( V_156 , V_166 ) ;
else
F_53 ( V_156 , V_164 ) ;
V_156 -> V_188 = 0 ;
V_189 = false ;
while ( 1 ) {
F_66 ( V_156 -> V_103 ) ;
if ( F_45 ( V_156 -> V_53 ,
V_156 -> V_78 ) <= 0 ) {
F_63 ( L_10 ) ;
break;
}
if ( F_46 ( V_156 -> V_78 , V_156 -> V_149 ) ) {
V_189 = true ;
break;
}
if ( V_156 -> V_188 > 5 ) {
F_63 ( L_15 ) ;
break;
}
F_19 ( V_156 -> V_78 , V_156 -> V_149 , V_156 -> V_81 ) ;
F_50 ( V_156 ) ;
V_156 -> V_188 ++ ;
}
if ( ! V_189 ) {
F_63 ( L_16 ) ;
return - 1 ;
} else {
F_11 ( L_17 ,
V_156 -> V_81 [ 0 ] & V_95 ,
( V_156 -> V_81 [ 0 ] & V_96 )
>> V_90 ) ;
return 0 ;
}
}
void F_67 ( struct V_131 * V_132 ,
struct V_101 * V_102 )
{
struct V_19 * V_20 = V_132 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_171 * V_171 = F_56 ( V_132 ) ;
struct V_172 * V_152 ;
struct V_73 * V_73 ;
struct V_121 * V_122 ;
struct V_155 V_156 ;
int V_25 ;
T_1 V_136 , V_191 , V_192 ;
if ( ! V_171 -> V_173 )
return;
V_152 = V_171 -> V_173 ;
V_73 = F_40 ( V_102 ) ;
if ( ! V_73 -> V_123 )
return;
V_122 = V_73 -> V_123 ;
if ( ( V_122 -> V_146 != V_147 ) &&
( V_122 -> V_146 != V_148 ) )
return;
V_156 . V_161 = true ;
V_25 = F_6 ( V_26 , V_114 ) ;
if ( F_68 ( V_22 -> V_32 . V_33 , V_25 , & V_191 , & V_192 ) ) {
if ( V_192 > 1 ) {
V_156 . V_161 = false ;
}
}
V_156 . V_169 = 0 ;
if ( V_152 -> V_193 )
V_156 . V_169 |= V_194 ;
else
V_156 . V_169 |= V_195 ;
if ( V_152 -> V_196 )
V_156 . V_169 |= V_197 ;
else
V_156 . V_169 |= V_198 ;
if ( F_41 ( & V_73 -> V_74 -> V_53 , V_199 , & V_136 )
== 1 ) {
if ( F_69 ( V_22 ) && ( V_136 & V_200 ) )
V_156 . V_190 = true ;
else
V_156 . V_190 = false ;
} else {
V_156 . V_190 = false ;
}
memcpy ( V_156 . V_103 , V_122 -> V_103 , V_201 ) ;
V_156 . V_22 = V_22 ;
V_156 . V_132 = V_132 ;
V_156 . V_102 = V_102 ;
V_156 . V_149 = V_122 -> V_149 ;
V_156 . V_112 = V_122 -> V_112 ;
V_156 . V_53 = & V_73 -> V_74 -> V_53 ;
if ( F_55 ( & V_156 ) )
goto V_50;
if ( F_61 ( & V_156 ) )
goto V_50;
if ( F_65 ( & V_156 ) )
goto V_50;
V_50:
if ( F_59 ( & V_156 ) )
return;
}
