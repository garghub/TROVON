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
if ( F_16 ( V_56 -> V_60 > 12 ) )
return - V_61 ;
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
void F_17 ( struct V_74 * V_74 )
{
struct V_19 * V_20 = V_74 -> V_28 . V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
int V_57 ;
V_74 -> V_75 -> V_42 . V_47 = V_74 -> V_47 . V_47 ;
V_74 -> V_75 -> V_54 . V_20 = V_74 -> V_28 . V_76 ;
if ( F_18 ( V_22 ) ) {
if ( V_77 )
V_74 -> V_75 -> V_54 . V_78 = V_79 ;
else
V_74 -> V_75 -> V_54 . V_78 = F_13 ;
} else {
V_74 -> V_75 -> V_54 . V_78 = F_13 ;
}
V_57 = F_19 ( & V_74 -> V_75 -> V_54 ) ;
if ( ! V_57 )
V_74 -> V_75 -> V_80 = true ;
F_20 ( V_57 , L_4 , V_57 ) ;
}
static void F_21 ( T_1 V_81 [ V_82 ] ,
int V_83 ,
T_1 V_84 [ 4 ] )
{
T_1 V_85 = 0 ;
T_1 V_86 = 0 ;
int V_87 ;
for ( V_87 = 0 ; V_87 < V_83 ; V_87 ++ ) {
T_1 V_88 = F_22 ( V_81 , V_87 ) ;
T_1 V_89 = F_23 ( V_81 , V_87 ) ;
F_11 ( L_5 ,
V_87 ,
V_90 [ V_88 >> V_91 ] ,
V_92 [ V_89 >> V_93 ] ) ;
if ( V_88 > V_85 )
V_85 = V_88 ;
if ( V_89 > V_86 )
V_86 = V_89 ;
}
if ( V_85 >= V_94 )
V_85 |= V_95 ;
if ( V_86 >= V_96 )
V_86 |= V_97 ;
F_11 ( L_6 ,
V_90 [ ( V_85 & V_98 ) >> V_91 ] ,
V_92 [ ( V_86 & V_99 ) >> V_93 ] ) ;
for ( V_87 = 0 ; V_87 < 4 ; V_87 ++ )
V_84 [ V_87 ] = V_85 | V_86 ;
}
static int F_24 ( int V_100 )
{
if ( V_100 == 0 )
return 24 ;
else
return V_100 * 3 ;
}
static int F_25 ( int V_101 ,
int V_102 ,
int V_103 )
{
return ( V_101 * V_102 * 8 ) / V_103 ;
}
int F_26 ( struct V_104 * V_105 ,
T_1 V_106 [ V_107 ] )
{
int V_108 ;
if ( F_27 ( V_105 ) )
V_108 = F_28 ( F_29 ( V_106 ) , 540000 ) ;
else
V_108 = F_28 ( F_29 ( V_106 ) , 270000 ) ;
return V_108 ;
}
static int F_30 ( struct V_104 * V_105 ,
T_1 V_106 [ V_107 ] ,
int V_109 )
{
int V_103 = F_24 ( F_31 ( V_105 ) ) ;
int V_108 = F_26 ( V_105 , V_106 ) ;
int V_110 = F_32 ( V_106 ) ;
int V_102 ;
int V_111 ;
for ( V_102 = 1 ; V_102 < V_110 ; V_102 <<= 1 ) {
V_111 = F_25 ( V_108 , V_102 , V_103 ) ;
if ( V_109 <= V_111 )
break;
}
return V_102 ;
}
static int F_33 ( struct V_104 * V_105 ,
T_1 V_106 [ V_107 ] ,
int V_109 )
{
int V_103 = F_24 ( F_31 ( V_105 ) ) ;
int V_102 , V_112 ;
if ( F_34 ( V_105 ) ==
V_113 )
return 270000 ;
V_102 = F_30 ( V_105 , V_106 , V_109 ) ;
V_112 = F_25 ( 162000 , V_102 , V_103 ) ;
if ( V_109 <= V_112 )
return 162000 ;
V_112 = F_25 ( 270000 , V_102 , V_103 ) ;
if ( V_109 <= V_112 )
return 270000 ;
if ( F_27 ( V_105 ) ) {
V_112 = F_25 ( 540000 , V_102 , V_103 ) ;
if ( V_109 <= V_112 )
return 540000 ;
}
return F_26 ( V_105 , V_106 ) ;
}
static T_1 F_35 ( struct V_21 * V_22 ,
int V_114 , int V_115 ,
T_1 V_116 , T_1 V_102 )
{
T_5 args ;
int V_25 = F_6 ( V_26 , V_117 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_118 = V_115 / 10 ;
args . V_119 = V_116 ;
args . V_120 = V_114 ;
args . V_121 = V_102 ;
args . V_122 = 0 ;
F_36 ( V_22 -> V_32 . V_33 , V_25 , ( V_48 * ) & args ) ;
return args . V_122 ;
}
T_1 F_37 ( struct V_74 * V_74 )
{
struct V_19 * V_20 = V_74 -> V_28 . V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
return F_35 ( V_22 , V_123 , 0 ,
V_74 -> V_75 -> V_42 . V_43 , 0 ) ;
}
static void F_38 ( struct V_74 * V_74 )
{
struct V_124 * V_125 = V_74 -> V_126 ;
T_1 V_127 [ 3 ] ;
if ( ! ( V_125 -> V_106 [ V_128 ] & V_129 ) )
return;
if ( F_39 ( & V_74 -> V_75 -> V_54 , V_130 , V_127 , 3 ) == 3 )
F_11 ( L_7 ,
V_127 [ 0 ] , V_127 [ 1 ] , V_127 [ 2 ] ) ;
if ( F_39 ( & V_74 -> V_75 -> V_54 , V_131 , V_127 , 3 ) == 3 )
F_11 ( L_8 ,
V_127 [ 0 ] , V_127 [ 1 ] , V_127 [ 2 ] ) ;
}
bool F_40 ( struct V_74 * V_74 )
{
struct V_124 * V_125 = V_74 -> V_126 ;
T_1 V_56 [ V_107 ] ;
int V_57 , V_9 ;
for ( V_9 = 0 ; V_9 < 7 ; V_9 ++ ) {
V_57 = F_39 ( & V_74 -> V_75 -> V_54 , V_132 , V_56 ,
V_107 ) ;
if ( V_57 == V_107 ) {
memcpy ( V_125 -> V_106 , V_56 , V_107 ) ;
F_11 ( L_9 , ( int ) sizeof( V_125 -> V_106 ) ,
V_125 -> V_106 ) ;
F_38 ( V_74 ) ;
return true ;
}
}
V_125 -> V_106 [ 0 ] = 0 ;
return false ;
}
int F_41 ( struct V_133 * V_134 ,
struct V_104 * V_105 )
{
struct V_19 * V_20 = V_134 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_74 * V_74 = F_42 ( V_105 ) ;
struct V_124 * V_125 ;
int V_135 = V_136 ;
V_38 V_137 = F_34 ( V_105 ) ;
T_1 V_138 ;
if ( ! F_9 ( V_22 ) )
return V_135 ;
if ( ! V_74 -> V_126 )
return V_135 ;
V_125 = V_74 -> V_126 ;
if ( V_137 != V_139 ) {
if ( F_43 ( & V_74 -> V_75 -> V_54 ,
V_140 , & V_138 ) == 1 ) {
if ( V_138 & 1 )
V_135 = V_141 ;
else if ( ( V_137 == V_113 ) ||
( V_137 == V_142 ) )
V_135 = V_143 ;
else
V_135 = V_136 ;
}
} else if ( V_105 -> V_144 == V_145 ) {
if ( F_43 ( & V_74 -> V_75 -> V_54 ,
V_140 , & V_138 ) == 1 ) {
if ( V_138 & 1 )
V_135 = V_141 ;
}
}
return V_135 ;
}
void F_44 ( struct V_104 * V_105 ,
const struct V_146 * V_147 )
{
struct V_74 * V_74 = F_42 ( V_105 ) ;
struct V_124 * V_125 ;
if ( ! V_74 -> V_126 )
return;
V_125 = V_74 -> V_126 ;
if ( ( V_125 -> V_148 == V_149 ) ||
( V_125 -> V_148 == V_150 ) ) {
V_125 -> V_115 =
F_33 ( V_105 , V_125 -> V_106 , V_147 -> clock ) ;
V_125 -> V_151 =
F_30 ( V_105 , V_125 -> V_106 , V_147 -> clock ) ;
}
}
int F_45 ( struct V_104 * V_105 ,
struct V_146 * V_147 )
{
struct V_74 * V_74 = F_42 ( V_105 ) ;
struct V_124 * V_125 ;
int V_115 ;
if ( ( V_147 -> clock > 340000 ) &&
( ! F_27 ( V_105 ) ) )
return V_152 ;
if ( ! V_74 -> V_126 )
return V_152 ;
V_125 = V_74 -> V_126 ;
V_115 =
F_33 ( V_105 , V_125 -> V_106 , V_147 -> clock ) ;
if ( ( V_115 == 540000 ) &&
( ! F_27 ( V_105 ) ) )
return V_152 ;
return V_153 ;
}
bool F_46 ( struct V_74 * V_74 )
{
T_1 V_81 [ V_82 ] ;
struct V_124 * V_154 = V_74 -> V_126 ;
if ( F_47 ( & V_74 -> V_75 -> V_54 , V_81 )
<= 0 )
return false ;
if ( F_48 ( V_81 , V_154 -> V_151 ) )
return false ;
return true ;
}
void F_49 ( struct V_104 * V_105 ,
T_1 V_155 )
{
struct V_74 * V_74 = F_42 ( V_105 ) ;
struct V_124 * V_125 ;
if ( ! V_74 -> V_126 )
return;
V_125 = V_74 -> V_126 ;
if ( V_125 -> V_106 [ 0 ] >= 0x11 ) {
F_50 ( & V_74 -> V_75 -> V_54 ,
V_156 , V_155 ) ;
F_51 ( 1000 , 2000 ) ;
}
}
static void F_52 ( struct V_157 * V_158 )
{
F_53 ( V_158 -> V_134 ,
V_159 ,
0 , V_158 -> V_84 [ 0 ] ) ;
F_54 ( V_158 -> V_54 , V_160 ,
V_158 -> V_84 , V_158 -> V_151 ) ;
}
static void F_55 ( struct V_157 * V_158 , int V_161 )
{
int V_162 = 0 ;
if ( F_9 ( V_158 -> V_22 ) || ! V_158 -> V_163 ) {
switch ( V_161 ) {
case V_164 :
V_162 = V_165 ;
break;
case V_166 :
V_162 = V_167 ;
break;
case V_168 :
V_162 = V_169 ;
break;
}
F_56 ( V_158 -> V_134 , V_162 , 0 ) ;
} else {
switch ( V_161 ) {
case V_164 :
V_162 = 0 ;
break;
case V_166 :
V_162 = 1 ;
break;
}
F_35 ( V_158 -> V_22 , V_170 ,
V_158 -> V_115 , V_158 -> V_171 , V_162 ) ;
}
F_50 ( V_158 -> V_54 , V_172 , V_161 ) ;
}
static int F_57 ( struct V_157 * V_158 )
{
struct V_173 * V_173 = F_58 ( V_158 -> V_134 ) ;
struct V_174 * V_154 = V_173 -> V_175 ;
T_1 V_138 ;
F_49 ( V_158 -> V_105 , V_176 ) ;
if ( V_158 -> V_106 [ 3 ] & 0x1 )
F_50 ( V_158 -> V_54 ,
V_177 , V_178 ) ;
else
F_50 ( V_158 -> V_54 ,
V_177 , 0 ) ;
if ( V_154 -> V_135 == V_141 )
F_50 ( V_158 -> V_54 , V_179 , 1 ) ;
V_138 = V_158 -> V_151 ;
if ( F_59 ( V_158 -> V_106 ) )
V_138 |= V_180 ;
F_50 ( V_158 -> V_54 , V_181 , V_138 ) ;
V_138 = F_60 ( V_158 -> V_115 ) ;
F_50 ( V_158 -> V_54 , V_182 , V_138 ) ;
if ( F_9 ( V_158 -> V_22 ) || ! V_158 -> V_163 )
F_56 ( V_158 -> V_134 ,
V_183 , 0 ) ;
else
F_35 ( V_158 -> V_22 , V_184 ,
V_158 -> V_115 , V_158 -> V_171 , 0 ) ;
F_50 ( V_158 -> V_54 ,
V_172 ,
V_185 ) ;
return 0 ;
}
static int F_61 ( struct V_157 * V_158 )
{
F_62 ( 400 ) ;
F_50 ( V_158 -> V_54 ,
V_172 ,
V_185 ) ;
if ( F_9 ( V_158 -> V_22 ) || ! V_158 -> V_163 )
F_56 ( V_158 -> V_134 ,
V_186 , 0 ) ;
else
F_35 ( V_158 -> V_22 , V_187 ,
V_158 -> V_115 , V_158 -> V_171 , 0 ) ;
return 0 ;
}
static int F_63 ( struct V_157 * V_158 )
{
bool V_188 ;
T_1 V_189 ;
int V_9 ;
F_55 ( V_158 , V_164 ) ;
memset ( V_158 -> V_84 , 0 , 4 ) ;
F_52 ( V_158 ) ;
F_62 ( 400 ) ;
V_188 = false ;
V_158 -> V_190 = 0 ;
V_189 = 0xff ;
while ( 1 ) {
F_64 ( V_158 -> V_106 ) ;
if ( F_47 ( V_158 -> V_54 ,
V_158 -> V_81 ) <= 0 ) {
F_65 ( L_10 ) ;
break;
}
if ( F_66 ( V_158 -> V_81 , V_158 -> V_151 ) ) {
V_188 = true ;
break;
}
for ( V_9 = 0 ; V_9 < V_158 -> V_151 ; V_9 ++ ) {
if ( ( V_158 -> V_84 [ V_9 ] & V_95 ) == 0 )
break;
}
if ( V_9 == V_158 -> V_151 ) {
F_65 ( L_11 ) ;
break;
}
if ( ( V_158 -> V_84 [ 0 ] & V_98 ) == V_189 ) {
++ V_158 -> V_190 ;
if ( V_158 -> V_190 == 5 ) {
F_65 ( L_12 ) ;
break;
}
} else
V_158 -> V_190 = 0 ;
V_189 = V_158 -> V_84 [ 0 ] & V_98 ;
F_21 ( V_158 -> V_81 , V_158 -> V_151 , V_158 -> V_84 ) ;
F_52 ( V_158 ) ;
}
if ( ! V_188 ) {
F_65 ( L_13 ) ;
return - 1 ;
} else {
F_11 ( L_14 ,
V_158 -> V_84 [ 0 ] & V_98 ,
( V_158 -> V_84 [ 0 ] & V_99 ) >>
V_93 ) ;
return 0 ;
}
}
static int F_67 ( struct V_157 * V_158 )
{
bool V_191 ;
if ( V_158 -> V_192 )
F_55 ( V_158 , V_168 ) ;
else
F_55 ( V_158 , V_166 ) ;
V_158 -> V_190 = 0 ;
V_191 = false ;
while ( 1 ) {
F_68 ( V_158 -> V_106 ) ;
if ( F_47 ( V_158 -> V_54 ,
V_158 -> V_81 ) <= 0 ) {
F_65 ( L_10 ) ;
break;
}
if ( F_48 ( V_158 -> V_81 , V_158 -> V_151 ) ) {
V_191 = true ;
break;
}
if ( V_158 -> V_190 > 5 ) {
F_65 ( L_15 ) ;
break;
}
F_21 ( V_158 -> V_81 , V_158 -> V_151 , V_158 -> V_84 ) ;
F_52 ( V_158 ) ;
V_158 -> V_190 ++ ;
}
if ( ! V_191 ) {
F_65 ( L_16 ) ;
return - 1 ;
} else {
F_11 ( L_17 ,
V_158 -> V_84 [ 0 ] & V_98 ,
( V_158 -> V_84 [ 0 ] & V_99 )
>> V_93 ) ;
return 0 ;
}
}
void F_69 ( struct V_133 * V_134 ,
struct V_104 * V_105 )
{
struct V_19 * V_20 = V_134 -> V_20 ;
struct V_21 * V_22 = V_20 -> V_23 ;
struct V_173 * V_173 = F_58 ( V_134 ) ;
struct V_174 * V_154 ;
struct V_74 * V_74 ;
struct V_124 * V_125 ;
struct V_157 V_158 ;
int V_25 ;
T_1 V_138 , V_193 , V_194 ;
if ( ! V_173 -> V_175 )
return;
V_154 = V_173 -> V_175 ;
V_74 = F_42 ( V_105 ) ;
if ( ! V_74 -> V_126 )
return;
V_125 = V_74 -> V_126 ;
if ( ( V_125 -> V_148 != V_149 ) &&
( V_125 -> V_148 != V_150 ) )
return;
V_158 . V_163 = true ;
V_25 = F_6 ( V_26 , V_117 ) ;
if ( F_70 ( V_22 -> V_32 . V_33 , V_25 , & V_193 , & V_194 ) ) {
if ( V_194 > 1 ) {
V_158 . V_163 = false ;
}
}
V_158 . V_171 = 0 ;
if ( V_154 -> V_195 )
V_158 . V_171 |= V_196 ;
else
V_158 . V_171 |= V_197 ;
if ( V_154 -> V_198 )
V_158 . V_171 |= V_199 ;
else
V_158 . V_171 |= V_200 ;
if ( F_43 ( & V_74 -> V_75 -> V_54 , V_201 , & V_138 )
== 1 ) {
if ( F_18 ( V_22 ) && ( V_138 & V_202 ) )
V_158 . V_192 = true ;
else
V_158 . V_192 = false ;
} else {
V_158 . V_192 = false ;
}
memcpy ( V_158 . V_106 , V_125 -> V_106 , V_203 ) ;
V_158 . V_22 = V_22 ;
V_158 . V_134 = V_134 ;
V_158 . V_105 = V_105 ;
V_158 . V_151 = V_125 -> V_151 ;
V_158 . V_115 = V_125 -> V_115 ;
V_158 . V_54 = & V_74 -> V_75 -> V_54 ;
if ( F_57 ( & V_158 ) )
goto V_51;
if ( F_63 ( & V_158 ) )
goto V_51;
if ( F_67 ( & V_158 ) )
goto V_51;
V_51:
if ( F_61 ( & V_158 ) )
return;
}
