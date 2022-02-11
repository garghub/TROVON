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
F_7 ( & V_22 -> V_32 . V_33 -> V_34 ) ;
V_28 = ( unsigned char * ) ( V_22 -> V_32 . V_33 -> V_35 + 1 ) ;
F_1 ( V_28 , V_13 , V_14 , true ) ;
args . V_36 . V_37 = F_8 ( ( V_38 ) ( 0 + 4 ) ) ;
args . V_36 . V_39 = F_8 ( ( V_38 ) ( 16 + 4 ) ) ;
args . V_36 . V_40 = 0 ;
args . V_36 . V_41 = V_12 -> V_42 . V_43 ;
args . V_36 . V_44 = V_17 / 10 ;
if ( F_9 ( V_22 ) )
args . V_45 . V_46 = V_12 -> V_42 . V_47 ;
F_10 ( V_22 -> V_32 . V_33 , V_25 , ( V_48 * ) & args ) ;
* V_18 = args . V_36 . V_49 ;
if ( args . V_36 . V_49 == 1 ) {
F_11 ( L_1 ) ;
V_30 = - V_50 ;
goto V_51;
}
if ( args . V_36 . V_49 == 2 ) {
F_11 ( L_2 ) ;
V_30 = - V_52 ;
goto V_51;
}
if ( args . V_36 . V_49 == 3 ) {
F_11 ( L_3 ) ;
V_30 = - V_52 ;
goto V_51;
}
V_29 = args . V_36 . V_40 ;
if ( V_29 > V_16 )
V_29 = V_16 ;
if ( V_15 && V_16 )
F_1 ( V_15 , V_28 + 16 , V_29 , false ) ;
V_30 = V_29 ;
V_51:
F_12 ( & V_22 -> V_32 . V_33 -> V_34 ) ;
F_12 ( & V_12 -> V_31 ) ;
return V_30 ;
}
static T_3
F_13 ( struct V_53 * V_54 , struct V_55 * V_56 )
{
struct V_11 * V_12 =
F_14 ( V_54 , struct V_11 , V_54 ) ;
int V_57 ;
T_1 V_58 [ 20 ] ;
T_4 V_59 ;
T_1 V_18 , V_17 = 0 ;
if ( F_15 ( V_56 -> V_60 > 16 ) )
return - V_61 ;
V_58 [ 0 ] = V_56 -> V_62 & 0xff ;
V_58 [ 1 ] = V_56 -> V_62 >> 8 ;
V_58 [ 2 ] = V_56 -> V_63 << 4 ;
V_58 [ 3 ] = V_56 -> V_60 ? ( V_56 -> V_60 - 1 ) : 0 ;
switch ( V_56 -> V_63 & ~ V_64 ) {
case V_65 :
case V_66 :
V_59 = V_67 + V_56 -> V_60 ;
if ( V_56 -> V_60 == 0 )
V_58 [ 3 ] |= V_68 << 4 ;
else
V_58 [ 3 ] |= V_59 << 4 ;
memcpy ( V_58 + V_67 , V_56 -> V_69 , V_56 -> V_60 ) ;
V_57 = F_5 ( V_12 ,
V_58 , V_59 , NULL , 0 , V_17 , & V_18 ) ;
if ( V_57 >= 0 )
V_57 = V_56 -> V_60 ;
break;
case V_70 :
case V_71 :
V_59 = V_67 ;
if ( V_56 -> V_60 == 0 )
V_58 [ 3 ] |= V_68 << 4 ;
else
V_58 [ 3 ] |= V_59 << 4 ;
V_57 = F_5 ( V_12 ,
V_58 , V_59 , V_56 -> V_69 , V_56 -> V_60 , V_17 , & V_18 ) ;
break;
default:
V_57 = - V_72 ;
break;
}
if ( V_57 >= 0 )
V_56 -> V_73 = V_18 >> 4 ;
return V_57 ;
}
void F_16 ( struct V_74 * V_74 )
{
int V_57 ;
V_74 -> V_75 -> V_42 . V_47 = V_74 -> V_47 . V_47 ;
V_74 -> V_75 -> V_54 . V_20 = V_74 -> V_28 . V_76 ;
V_74 -> V_75 -> V_54 . V_77 = F_13 ;
V_57 = F_17 ( & V_74 -> V_75 -> V_54 ) ;
if ( ! V_57 )
V_74 -> V_75 -> V_78 = true ;
F_18 ( V_57 , L_4 , V_57 ) ;
}
static void F_19 ( T_1 V_79 [ V_80 ] ,
int V_81 ,
T_1 V_82 [ 4 ] )
{
T_1 V_83 = 0 ;
T_1 V_84 = 0 ;
int V_85 ;
for ( V_85 = 0 ; V_85 < V_81 ; V_85 ++ ) {
T_1 V_86 = F_20 ( V_79 , V_85 ) ;
T_1 V_87 = F_21 ( V_79 , V_85 ) ;
F_11 ( L_5 ,
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
F_11 ( L_6 ,
V_88 [ ( V_83 & V_96 ) >> V_89 ] ,
V_90 [ ( V_84 & V_97 ) >> V_91 ] ) ;
for ( V_85 = 0 ; V_85 < 4 ; V_85 ++ )
V_82 [ V_85 ] = V_83 | V_84 ;
}
static int F_22 ( int V_98 )
{
if ( V_98 == 0 )
return 24 ;
else
return V_98 * 3 ;
}
static int F_23 ( int V_99 ,
int V_100 ,
int V_101 )
{
return ( V_99 * V_100 * 8 ) / V_101 ;
}
static int F_24 ( struct V_102 * V_103 ,
T_1 V_104 [ V_105 ] )
{
int V_106 ;
if ( F_25 ( V_103 ) )
V_106 = F_26 ( F_27 ( V_104 ) , 540000 ) ;
else
V_106 = F_26 ( F_27 ( V_104 ) , 270000 ) ;
return V_106 ;
}
static int F_28 ( struct V_102 * V_103 ,
T_1 V_104 [ V_105 ] ,
int V_107 )
{
int V_101 = F_22 ( F_29 ( V_103 ) ) ;
int V_106 = F_24 ( V_103 , V_104 ) ;
int V_108 = F_30 ( V_104 ) ;
int V_100 ;
int V_109 ;
for ( V_100 = 1 ; V_100 < V_108 ; V_100 <<= 1 ) {
V_109 = F_23 ( V_106 , V_100 , V_101 ) ;
if ( V_107 <= V_109 )
break;
}
return V_100 ;
}
static int F_31 ( struct V_102 * V_103 ,
T_1 V_104 [ V_105 ] ,
int V_107 )
{
int V_101 = F_22 ( F_29 ( V_103 ) ) ;
int V_100 , V_110 ;
if ( F_32 ( V_103 ) ==
V_111 )
return 270000 ;
V_100 = F_28 ( V_103 , V_104 , V_107 ) ;
V_110 = F_23 ( 162000 , V_100 , V_101 ) ;
if ( V_107 <= V_110 )
return 162000 ;
V_110 = F_23 ( 270000 , V_100 , V_101 ) ;
if ( V_107 <= V_110 )
return 270000 ;
if ( F_25 ( V_103 ) ) {
V_110 = F_23 ( 540000 , V_100 , V_101 ) ;
if ( V_107 <= V_110 )
return 540000 ;
}
return F_24 ( V_103 , V_104 ) ;
}
static T_1 F_33 ( struct V_21 * V_22 ,
int V_112 , int V_113 ,
T_1 V_114 , T_1 V_100 )
{
T_5 args ;
int V_25 = F_6 ( V_26 , V_115 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_116 = V_113 / 10 ;
args . V_117 = V_114 ;
args . V_118 = V_112 ;
args . V_119 = V_100 ;
args . V_120 = 0 ;
F_34 ( V_22 -> V_32 . V_33 , V_25 , ( V_48 * ) & args ) ;
return args . V_120 ;
}
T_1 F_35 ( struct V_74 * V_74 )
{
struct V_19 * V_20 = V_74 -> V_28 . V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
return F_33 ( V_22 , V_121 , 0 ,
V_74 -> V_75 -> V_42 . V_43 , 0 ) ;
}
static void F_36 ( struct V_74 * V_74 )
{
struct V_122 * V_123 = V_74 -> V_124 ;
T_1 V_125 [ 3 ] ;
if ( ! ( V_123 -> V_104 [ V_126 ] & V_127 ) )
return;
if ( F_37 ( & V_74 -> V_75 -> V_54 , V_128 , V_125 , 3 ) == 3 )
F_11 ( L_7 ,
V_125 [ 0 ] , V_125 [ 1 ] , V_125 [ 2 ] ) ;
if ( F_37 ( & V_74 -> V_75 -> V_54 , V_129 , V_125 , 3 ) == 3 )
F_11 ( L_8 ,
V_125 [ 0 ] , V_125 [ 1 ] , V_125 [ 2 ] ) ;
}
bool F_38 ( struct V_74 * V_74 )
{
struct V_122 * V_123 = V_74 -> V_124 ;
T_1 V_56 [ V_105 ] ;
int V_57 ;
V_57 = F_37 ( & V_74 -> V_75 -> V_54 , V_130 , V_56 ,
V_105 ) ;
if ( V_57 > 0 ) {
memcpy ( V_123 -> V_104 , V_56 , V_105 ) ;
F_11 ( L_9 , ( int ) sizeof( V_123 -> V_104 ) ,
V_123 -> V_104 ) ;
F_36 ( V_74 ) ;
return true ;
}
V_123 -> V_104 [ 0 ] = 0 ;
return false ;
}
int F_39 ( struct V_131 * V_132 ,
struct V_102 * V_103 )
{
struct V_19 * V_20 = V_132 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_74 * V_74 = F_40 ( V_103 ) ;
struct V_122 * V_123 ;
int V_133 = V_134 ;
V_38 V_135 = F_32 ( V_103 ) ;
T_1 V_136 ;
if ( ! F_9 ( V_22 ) )
return V_133 ;
if ( ! V_74 -> V_124 )
return V_133 ;
V_123 = V_74 -> V_124 ;
if ( V_135 != V_137 ) {
if ( F_41 ( & V_74 -> V_75 -> V_54 ,
V_138 , & V_136 ) == 1 ) {
if ( V_136 & 1 )
V_133 = V_139 ;
else if ( ( V_135 == V_111 ) ||
( V_135 == V_140 ) )
V_133 = V_141 ;
else
V_133 = V_134 ;
}
} else if ( V_103 -> V_142 == V_143 ) {
if ( F_41 ( & V_74 -> V_75 -> V_54 ,
V_138 , & V_136 ) == 1 ) {
if ( V_136 & 1 )
V_133 = V_139 ;
}
}
return V_133 ;
}
void F_42 ( struct V_102 * V_103 ,
const struct V_144 * V_145 )
{
struct V_74 * V_74 = F_40 ( V_103 ) ;
struct V_122 * V_123 ;
if ( ! V_74 -> V_124 )
return;
V_123 = V_74 -> V_124 ;
if ( ( V_123 -> V_146 == V_147 ) ||
( V_123 -> V_146 == V_148 ) ) {
V_123 -> V_113 =
F_31 ( V_103 , V_123 -> V_104 , V_145 -> clock ) ;
V_123 -> V_149 =
F_28 ( V_103 , V_123 -> V_104 , V_145 -> clock ) ;
}
}
int F_43 ( struct V_102 * V_103 ,
struct V_144 * V_145 )
{
struct V_74 * V_74 = F_40 ( V_103 ) ;
struct V_122 * V_123 ;
int V_113 ;
if ( ! V_74 -> V_124 )
return V_150 ;
V_123 = V_74 -> V_124 ;
V_113 =
F_31 ( V_103 , V_123 -> V_104 , V_145 -> clock ) ;
if ( ( V_113 == 540000 ) &&
( ! F_25 ( V_103 ) ) )
return V_150 ;
return V_151 ;
}
bool F_44 ( struct V_74 * V_74 )
{
T_1 V_79 [ V_80 ] ;
struct V_122 * V_152 = V_74 -> V_124 ;
if ( F_45 ( & V_74 -> V_75 -> V_54 , V_79 )
<= 0 )
return false ;
if ( F_46 ( V_79 , V_152 -> V_149 ) )
return false ;
return true ;
}
void F_47 ( struct V_102 * V_103 ,
T_1 V_153 )
{
struct V_74 * V_74 = F_40 ( V_103 ) ;
struct V_122 * V_123 ;
if ( ! V_74 -> V_124 )
return;
V_123 = V_74 -> V_124 ;
if ( V_123 -> V_104 [ 0 ] >= 0x11 ) {
F_48 ( & V_74 -> V_75 -> V_54 ,
V_154 , V_153 ) ;
F_49 ( 1000 , 2000 ) ;
}
}
static void F_50 ( struct V_155 * V_156 )
{
F_51 ( V_156 -> V_132 ,
V_157 ,
0 , V_156 -> V_82 [ 0 ] ) ;
F_52 ( V_156 -> V_54 , V_158 ,
V_156 -> V_82 , V_156 -> V_149 ) ;
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
V_156 -> V_113 , V_156 -> V_169 , V_160 ) ;
}
F_48 ( V_156 -> V_54 , V_170 , V_159 ) ;
}
static int F_55 ( struct V_155 * V_156 )
{
struct V_171 * V_171 = F_56 ( V_156 -> V_132 ) ;
struct V_172 * V_152 = V_171 -> V_173 ;
T_1 V_136 ;
F_47 ( V_156 -> V_103 , V_174 ) ;
if ( V_156 -> V_104 [ 3 ] & 0x1 )
F_48 ( V_156 -> V_54 ,
V_175 , V_176 ) ;
else
F_48 ( V_156 -> V_54 ,
V_175 , 0 ) ;
if ( ( V_156 -> V_103 -> V_142 == V_143 ) &&
( V_152 -> V_133 == V_139 ) ) {
F_48 ( V_156 -> V_54 , V_177 , 1 ) ;
}
V_136 = V_156 -> V_149 ;
if ( F_57 ( V_156 -> V_104 ) )
V_136 |= V_178 ;
F_48 ( V_156 -> V_54 , V_179 , V_136 ) ;
V_136 = F_58 ( V_156 -> V_113 ) ;
F_48 ( V_156 -> V_54 , V_180 , V_136 ) ;
if ( F_9 ( V_156 -> V_22 ) || ! V_156 -> V_161 )
F_54 ( V_156 -> V_132 ,
V_181 , 0 ) ;
else
F_33 ( V_156 -> V_22 , V_182 ,
V_156 -> V_113 , V_156 -> V_169 , 0 ) ;
F_48 ( V_156 -> V_54 ,
V_170 ,
V_183 ) ;
return 0 ;
}
static int F_59 ( struct V_155 * V_156 )
{
F_60 ( 400 ) ;
F_48 ( V_156 -> V_54 ,
V_170 ,
V_183 ) ;
if ( F_9 ( V_156 -> V_22 ) || ! V_156 -> V_161 )
F_54 ( V_156 -> V_132 ,
V_184 , 0 ) ;
else
F_33 ( V_156 -> V_22 , V_185 ,
V_156 -> V_113 , V_156 -> V_169 , 0 ) ;
return 0 ;
}
static int F_61 ( struct V_155 * V_156 )
{
bool V_186 ;
T_1 V_187 ;
int V_9 ;
F_53 ( V_156 , V_162 ) ;
memset ( V_156 -> V_82 , 0 , 4 ) ;
F_50 ( V_156 ) ;
F_60 ( 400 ) ;
V_186 = false ;
V_156 -> V_188 = 0 ;
V_187 = 0xff ;
while ( 1 ) {
F_62 ( V_156 -> V_104 ) ;
if ( F_45 ( V_156 -> V_54 ,
V_156 -> V_79 ) <= 0 ) {
F_63 ( L_10 ) ;
break;
}
if ( F_64 ( V_156 -> V_79 , V_156 -> V_149 ) ) {
V_186 = true ;
break;
}
for ( V_9 = 0 ; V_9 < V_156 -> V_149 ; V_9 ++ ) {
if ( ( V_156 -> V_82 [ V_9 ] & V_93 ) == 0 )
break;
}
if ( V_9 == V_156 -> V_149 ) {
F_63 ( L_11 ) ;
break;
}
if ( ( V_156 -> V_82 [ 0 ] & V_96 ) == V_187 ) {
++ V_156 -> V_188 ;
if ( V_156 -> V_188 == 5 ) {
F_63 ( L_12 ) ;
break;
}
} else
V_156 -> V_188 = 0 ;
V_187 = V_156 -> V_82 [ 0 ] & V_96 ;
F_19 ( V_156 -> V_79 , V_156 -> V_149 , V_156 -> V_82 ) ;
F_50 ( V_156 ) ;
}
if ( ! V_186 ) {
F_63 ( L_13 ) ;
return - 1 ;
} else {
F_11 ( L_14 ,
V_156 -> V_82 [ 0 ] & V_96 ,
( V_156 -> V_82 [ 0 ] & V_97 ) >>
V_91 ) ;
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
F_66 ( V_156 -> V_104 ) ;
if ( F_45 ( V_156 -> V_54 ,
V_156 -> V_79 ) <= 0 ) {
F_63 ( L_10 ) ;
break;
}
if ( F_46 ( V_156 -> V_79 , V_156 -> V_149 ) ) {
V_189 = true ;
break;
}
if ( V_156 -> V_188 > 5 ) {
F_63 ( L_15 ) ;
break;
}
F_19 ( V_156 -> V_79 , V_156 -> V_149 , V_156 -> V_82 ) ;
F_50 ( V_156 ) ;
V_156 -> V_188 ++ ;
}
if ( ! V_189 ) {
F_63 ( L_16 ) ;
return - 1 ;
} else {
F_11 ( L_17 ,
V_156 -> V_82 [ 0 ] & V_96 ,
( V_156 -> V_82 [ 0 ] & V_97 )
>> V_91 ) ;
return 0 ;
}
}
void F_67 ( struct V_131 * V_132 ,
struct V_102 * V_103 )
{
struct V_19 * V_20 = V_132 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_171 * V_171 = F_56 ( V_132 ) ;
struct V_172 * V_152 ;
struct V_74 * V_74 ;
struct V_122 * V_123 ;
struct V_155 V_156 ;
int V_25 ;
T_1 V_136 , V_191 , V_192 ;
if ( ! V_171 -> V_173 )
return;
V_152 = V_171 -> V_173 ;
V_74 = F_40 ( V_103 ) ;
if ( ! V_74 -> V_124 )
return;
V_123 = V_74 -> V_124 ;
if ( ( V_123 -> V_146 != V_147 ) &&
( V_123 -> V_146 != V_148 ) )
return;
V_156 . V_161 = true ;
V_25 = F_6 ( V_26 , V_115 ) ;
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
if ( F_41 ( & V_74 -> V_75 -> V_54 , V_199 , & V_136 )
== 1 ) {
if ( F_69 ( V_22 ) && ( V_136 & V_200 ) )
V_156 . V_190 = true ;
else
V_156 . V_190 = false ;
} else {
V_156 . V_190 = false ;
}
memcpy ( V_156 . V_104 , V_123 -> V_104 , V_201 ) ;
V_156 . V_22 = V_22 ;
V_156 . V_132 = V_132 ;
V_156 . V_103 = V_103 ;
V_156 . V_149 = V_123 -> V_149 ;
V_156 . V_113 = V_123 -> V_113 ;
V_156 . V_54 = & V_74 -> V_75 -> V_54 ;
if ( F_55 ( & V_156 ) )
goto V_51;
if ( F_61 ( & V_156 ) )
goto V_51;
if ( F_65 ( & V_156 ) )
goto V_51;
V_51:
if ( F_59 ( & V_156 ) )
return;
}
