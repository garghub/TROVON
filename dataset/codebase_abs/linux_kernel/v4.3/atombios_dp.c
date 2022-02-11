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
int V_20 = 0 ;
memset ( & args , 0 , sizeof( args ) ) ;
F_3 ( & V_2 -> V_21 ) ;
V_18 = ( unsigned char * ) ( V_12 -> V_22 . V_23 -> V_24 + 1 ) ;
F_4 ( V_18 , V_3 , V_4 , true ) ;
args . V_25 . V_26 = F_5 ( ( V_27 ) ( 0 + 4 ) ) ;
args . V_25 . V_28 = F_5 ( ( V_27 ) ( 16 + 4 ) ) ;
args . V_25 . V_29 = 0 ;
args . V_25 . V_30 = V_2 -> V_31 . V_32 ;
args . V_25 . V_33 = V_7 / 10 ;
args . V_25 . V_34 = V_2 -> V_31 . V_35 ;
F_6 ( V_12 -> V_22 . V_23 , V_15 , ( V_36 * ) & args ) ;
* V_8 = args . V_25 . V_37 ;
if ( args . V_25 . V_37 == 1 ) {
F_7 ( L_1 ) ;
V_20 = - V_38 ;
goto V_39;
}
if ( args . V_25 . V_37 == 2 ) {
F_7 ( L_2 ) ;
V_20 = - V_40 ;
goto V_39;
}
if ( args . V_25 . V_37 == 3 ) {
F_7 ( L_3 ) ;
V_20 = - V_40 ;
goto V_39;
}
V_19 = args . V_41 . V_29 ;
if ( V_19 > V_6 )
V_19 = V_6 ;
if ( V_5 && V_6 )
F_4 ( V_5 , V_18 + 16 , V_19 , false ) ;
V_20 = V_19 ;
V_39:
F_8 ( & V_2 -> V_21 ) ;
return V_20 ;
}
static T_2
F_9 ( struct V_42 * V_43 , struct V_44 * V_45 )
{
struct V_1 * V_2 =
F_10 ( V_43 , struct V_1 , V_43 ) ;
int V_46 ;
T_1 V_47 [ 20 ] ;
T_3 V_48 ;
T_1 V_8 , V_7 = 0 ;
if ( F_11 ( V_45 -> V_49 > 16 ) )
return - V_50 ;
V_47 [ 0 ] = V_45 -> V_51 & 0xff ;
V_47 [ 1 ] = V_45 -> V_51 >> 8 ;
V_47 [ 2 ] = ( V_45 -> V_52 << 4 ) |
( ( V_45 -> V_51 >> 16 ) & 0xf ) ;
V_47 [ 3 ] = V_45 -> V_49 ? ( V_45 -> V_49 - 1 ) : 0 ;
switch ( V_45 -> V_52 & ~ V_53 ) {
case V_54 :
case V_55 :
V_48 = V_56 + V_45 -> V_49 ;
if ( V_45 -> V_49 == 0 )
V_47 [ 3 ] |= V_57 << 4 ;
else
V_47 [ 3 ] |= V_48 << 4 ;
memcpy ( V_47 + V_56 , V_45 -> V_58 , V_45 -> V_49 ) ;
V_46 = F_1 ( V_2 ,
V_47 , V_48 , NULL , 0 , V_7 , & V_8 ) ;
if ( V_46 >= 0 )
V_46 = V_45 -> V_49 ;
break;
case V_59 :
case V_60 :
V_48 = V_56 ;
if ( V_45 -> V_49 == 0 )
V_47 [ 3 ] |= V_57 << 4 ;
else
V_47 [ 3 ] |= V_48 << 4 ;
V_46 = F_1 ( V_2 ,
V_47 , V_48 , V_45 -> V_58 , V_45 -> V_49 , V_7 , & V_8 ) ;
break;
default:
V_46 = - V_61 ;
break;
}
if ( V_46 >= 0 )
V_45 -> V_62 = V_8 >> 4 ;
return V_46 ;
}
void F_12 ( struct V_63 * V_63 )
{
int V_46 ;
V_63 -> V_64 -> V_31 . V_35 = V_63 -> V_35 . V_35 ;
V_63 -> V_64 -> V_43 . V_10 = V_63 -> V_18 . V_65 ;
V_63 -> V_64 -> V_43 . V_66 = F_9 ;
V_46 = F_13 ( & V_63 -> V_64 -> V_43 ) ;
if ( ! V_46 )
V_63 -> V_64 -> V_67 = true ;
F_14 ( V_46 , L_4 , V_46 ) ;
}
static void F_15 ( const T_1 V_68 [ V_69 ] ,
int V_70 ,
T_1 V_71 [ 4 ] )
{
T_1 V_72 = 0 ;
T_1 V_73 = 0 ;
int V_74 ;
for ( V_74 = 0 ; V_74 < V_70 ; V_74 ++ ) {
T_1 V_75 = F_16 ( V_68 , V_74 ) ;
T_1 V_76 = F_17 ( V_68 , V_74 ) ;
F_7 ( L_5 ,
V_74 ,
V_77 [ V_75 >> V_78 ] ,
V_79 [ V_76 >> V_80 ] ) ;
if ( V_75 > V_72 )
V_72 = V_75 ;
if ( V_76 > V_73 )
V_73 = V_76 ;
}
if ( V_72 >= V_81 )
V_72 |= V_82 ;
if ( V_73 >= V_83 )
V_73 |= V_84 ;
F_7 ( L_6 ,
V_77 [ ( V_72 & V_85 ) >> V_78 ] ,
V_79 [ ( V_73 & V_86 ) >> V_80 ] ) ;
for ( V_74 = 0 ; V_74 < 4 ; V_74 ++ )
V_71 [ V_74 ] = V_72 | V_73 ;
}
static int F_18 ( int V_87 )
{
if ( V_87 == 0 )
return 24 ;
else
return V_87 * 3 ;
}
static int F_19 ( int V_88 ,
int V_89 ,
int V_90 )
{
return ( V_88 * V_89 * 8 ) / V_90 ;
}
static int F_20 ( struct V_91 * V_92 ,
const T_1 V_93 [ V_94 ] ,
int V_95 )
{
int V_90 = F_18 ( F_21 ( V_92 ) ) ;
int V_96 = F_22 ( V_93 ) ;
int V_97 = F_23 ( V_93 ) ;
int V_89 ;
int V_98 ;
for ( V_89 = 1 ; V_89 < V_97 ; V_89 <<= 1 ) {
V_98 = F_19 ( V_96 , V_89 , V_90 ) ;
if ( V_95 <= V_98 )
break;
}
return V_89 ;
}
static int F_24 ( struct V_91 * V_92 ,
const T_1 V_93 [ V_94 ] ,
int V_95 )
{
int V_90 = F_18 ( F_21 ( V_92 ) ) ;
int V_89 , V_99 ;
if ( F_25 ( V_92 ) ==
V_100 )
return 270000 ;
V_89 = F_20 ( V_92 , V_93 , V_95 ) ;
V_99 = F_19 ( 162000 , V_89 , V_90 ) ;
if ( V_95 <= V_99 )
return 162000 ;
V_99 = F_19 ( 270000 , V_89 , V_90 ) ;
if ( V_95 <= V_99 )
return 270000 ;
if ( F_26 ( V_92 ) ) {
V_99 = F_19 ( 540000 , V_89 , V_90 ) ;
if ( V_95 <= V_99 )
return 540000 ;
}
return F_22 ( V_93 ) ;
}
static T_1 F_27 ( struct V_11 * V_12 ,
int V_101 , int V_102 ,
T_1 V_103 , T_1 V_89 )
{
T_4 args ;
int V_15 = F_2 ( V_16 , V_104 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_105 = V_102 / 10 ;
args . V_106 = V_103 ;
args . V_107 = V_101 ;
args . V_108 = V_89 ;
args . V_109 = 0 ;
F_6 ( V_12 -> V_22 . V_23 , V_15 , ( V_36 * ) & args ) ;
return args . V_109 ;
}
T_1 F_28 ( struct V_63 * V_63 )
{
struct V_9 * V_10 = V_63 -> V_18 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
return F_27 ( V_12 , V_110 , 0 ,
V_63 -> V_64 -> V_31 . V_32 , 0 ) ;
}
static void F_29 ( struct V_63 * V_63 )
{
struct V_111 * V_112 = V_63 -> V_113 ;
T_1 V_114 [ 3 ] ;
if ( ! ( V_112 -> V_93 [ V_115 ] & V_116 ) )
return;
if ( F_30 ( & V_63 -> V_64 -> V_43 , V_117 , V_114 , 3 ) == 3 )
F_7 ( L_7 ,
V_114 [ 0 ] , V_114 [ 1 ] , V_114 [ 2 ] ) ;
if ( F_30 ( & V_63 -> V_64 -> V_43 , V_118 , V_114 , 3 ) == 3 )
F_7 ( L_8 ,
V_114 [ 0 ] , V_114 [ 1 ] , V_114 [ 2 ] ) ;
}
int F_31 ( struct V_63 * V_63 )
{
struct V_111 * V_112 = V_63 -> V_113 ;
T_1 V_45 [ V_94 ] ;
int V_46 , V_119 ;
for ( V_119 = 0 ; V_119 < 7 ; V_119 ++ ) {
V_46 = F_30 ( & V_63 -> V_64 -> V_43 , V_120 , V_45 ,
V_94 ) ;
if ( V_46 == V_94 ) {
memcpy ( V_112 -> V_93 , V_45 , V_94 ) ;
F_7 ( L_9 , ( int ) sizeof( V_112 -> V_93 ) ,
V_112 -> V_93 ) ;
F_29 ( V_63 ) ;
return 0 ;
}
}
V_112 -> V_93 [ 0 ] = 0 ;
return - V_61 ;
}
int F_32 ( struct V_121 * V_122 ,
struct V_91 * V_92 )
{
struct V_63 * V_63 = F_33 ( V_92 ) ;
struct V_111 * V_112 ;
int V_123 = V_124 ;
V_27 V_125 = F_25 ( V_92 ) ;
T_1 V_126 ;
if ( ! V_63 -> V_113 )
return V_123 ;
V_112 = V_63 -> V_113 ;
if ( V_125 != V_127 ) {
if ( F_34 ( & V_63 -> V_64 -> V_43 ,
V_128 , & V_126 ) == 1 ) {
if ( V_126 & 1 )
V_123 = V_129 ;
else if ( ( V_125 == V_100 ) ||
( V_125 == V_130 ) )
V_123 = V_131 ;
else
V_123 = V_124 ;
}
} else if ( V_92 -> V_132 == V_133 ) {
if ( F_34 ( & V_63 -> V_64 -> V_43 ,
V_128 , & V_126 ) == 1 ) {
if ( V_126 & 1 )
V_123 = V_129 ;
}
}
return V_123 ;
}
void F_35 ( struct V_91 * V_92 ,
const struct V_134 * V_135 )
{
struct V_63 * V_63 = F_33 ( V_92 ) ;
struct V_111 * V_112 ;
if ( ! V_63 -> V_113 )
return;
V_112 = V_63 -> V_113 ;
if ( ( V_112 -> V_136 == V_137 ) ||
( V_112 -> V_136 == V_138 ) ) {
V_112 -> V_102 =
F_24 ( V_92 , V_112 -> V_93 , V_135 -> clock ) ;
V_112 -> V_139 =
F_20 ( V_92 , V_112 -> V_93 , V_135 -> clock ) ;
}
}
int F_36 ( struct V_91 * V_92 ,
struct V_134 * V_135 )
{
struct V_63 * V_63 = F_33 ( V_92 ) ;
struct V_111 * V_112 ;
int V_102 ;
if ( ! V_63 -> V_113 )
return V_140 ;
V_112 = V_63 -> V_113 ;
V_102 =
F_24 ( V_92 , V_112 -> V_93 , V_135 -> clock ) ;
if ( ( V_102 == 540000 ) &&
( ! F_26 ( V_92 ) ) )
return V_140 ;
return V_141 ;
}
bool F_37 ( struct V_63 * V_63 )
{
T_1 V_68 [ V_69 ] ;
struct V_111 * V_142 = V_63 -> V_113 ;
if ( F_38 ( & V_63 -> V_64 -> V_43 , V_68 )
<= 0 )
return false ;
if ( F_39 ( V_68 , V_142 -> V_139 ) )
return false ;
return true ;
}
void F_40 ( struct V_91 * V_92 ,
T_1 V_143 )
{
struct V_63 * V_63 = F_33 ( V_92 ) ;
struct V_111 * V_112 ;
if ( ! V_63 -> V_113 )
return;
V_112 = V_63 -> V_113 ;
if ( V_112 -> V_93 [ 0 ] >= 0x11 ) {
F_41 ( & V_63 -> V_64 -> V_43 ,
V_144 , V_143 ) ;
F_42 ( 1000 , 2000 ) ;
}
}
static void
F_43 ( struct V_145 * V_146 )
{
F_44 ( V_146 -> V_122 ,
V_147 ,
0 , V_146 -> V_71 [ 0 ] ) ;
F_45 ( V_146 -> V_43 , V_148 ,
V_146 -> V_71 , V_146 -> V_139 ) ;
}
static void
F_46 ( struct V_145 * V_146 , int V_149 )
{
int V_150 = 0 ;
switch ( V_149 ) {
case V_151 :
V_150 = V_152 ;
break;
case V_153 :
V_150 = V_154 ;
break;
case V_155 :
V_150 = V_156 ;
break;
}
F_47 ( V_146 -> V_122 , V_150 , 0 ) ;
F_41 ( V_146 -> V_43 , V_157 , V_149 ) ;
}
static int
F_48 ( struct V_145 * V_146 )
{
struct V_158 * V_158 = F_49 ( V_146 -> V_122 ) ;
struct V_159 * V_142 = V_158 -> V_160 ;
T_1 V_126 ;
F_40 ( V_146 -> V_92 , V_161 ) ;
if ( V_146 -> V_93 [ 3 ] & 0x1 )
F_41 ( V_146 -> V_43 ,
V_162 , V_163 ) ;
else
F_41 ( V_146 -> V_43 ,
V_162 , 0 ) ;
if ( V_142 -> V_123 == V_129 )
F_41 ( V_146 -> V_43 , V_164 , 1 ) ;
V_126 = V_146 -> V_139 ;
if ( F_50 ( V_146 -> V_93 ) )
V_126 |= V_165 ;
F_41 ( V_146 -> V_43 , V_166 , V_126 ) ;
V_126 = F_51 ( V_146 -> V_102 ) ;
F_41 ( V_146 -> V_43 , V_167 , V_126 ) ;
F_47 ( V_146 -> V_122 ,
V_168 , 0 ) ;
F_41 ( V_146 -> V_43 ,
V_157 ,
V_169 ) ;
return 0 ;
}
static int
F_52 ( struct V_145 * V_146 )
{
F_53 ( 400 ) ;
F_41 ( V_146 -> V_43 ,
V_157 ,
V_169 ) ;
F_47 ( V_146 -> V_122 ,
V_170 , 0 ) ;
return 0 ;
}
static int
F_54 ( struct V_145 * V_146 )
{
bool V_171 ;
T_1 V_172 ;
int V_119 ;
F_46 ( V_146 , V_151 ) ;
memset ( V_146 -> V_71 , 0 , 4 ) ;
F_43 ( V_146 ) ;
F_53 ( 400 ) ;
V_171 = false ;
V_146 -> V_173 = 0 ;
V_172 = 0xff ;
while ( 1 ) {
F_55 ( V_146 -> V_93 ) ;
if ( F_38 ( V_146 -> V_43 ,
V_146 -> V_68 ) <= 0 ) {
F_56 ( L_10 ) ;
break;
}
if ( F_57 ( V_146 -> V_68 , V_146 -> V_139 ) ) {
V_171 = true ;
break;
}
for ( V_119 = 0 ; V_119 < V_146 -> V_139 ; V_119 ++ ) {
if ( ( V_146 -> V_71 [ V_119 ] & V_82 ) == 0 )
break;
}
if ( V_119 == V_146 -> V_139 ) {
F_56 ( L_11 ) ;
break;
}
if ( ( V_146 -> V_71 [ 0 ] & V_85 ) == V_172 ) {
++ V_146 -> V_173 ;
if ( V_146 -> V_173 == 5 ) {
F_56 ( L_12 ) ;
break;
}
} else
V_146 -> V_173 = 0 ;
V_172 = V_146 -> V_71 [ 0 ] & V_85 ;
F_15 ( V_146 -> V_68 , V_146 -> V_139 ,
V_146 -> V_71 ) ;
F_43 ( V_146 ) ;
}
if ( ! V_171 ) {
F_56 ( L_13 ) ;
return - 1 ;
} else {
F_7 ( L_14 ,
V_146 -> V_71 [ 0 ] & V_85 ,
( V_146 -> V_71 [ 0 ] & V_86 ) >>
V_80 ) ;
return 0 ;
}
}
static int
F_58 ( struct V_145 * V_146 )
{
bool V_174 ;
if ( V_146 -> V_175 )
F_46 ( V_146 , V_155 ) ;
else
F_46 ( V_146 , V_153 ) ;
V_146 -> V_173 = 0 ;
V_174 = false ;
while ( 1 ) {
F_59 ( V_146 -> V_93 ) ;
if ( F_38 ( V_146 -> V_43 ,
V_146 -> V_68 ) <= 0 ) {
F_56 ( L_10 ) ;
break;
}
if ( F_39 ( V_146 -> V_68 , V_146 -> V_139 ) ) {
V_174 = true ;
break;
}
if ( V_146 -> V_173 > 5 ) {
F_56 ( L_15 ) ;
break;
}
F_15 ( V_146 -> V_68 , V_146 -> V_139 ,
V_146 -> V_71 ) ;
F_43 ( V_146 ) ;
V_146 -> V_173 ++ ;
}
if ( ! V_174 ) {
F_56 ( L_16 ) ;
return - 1 ;
} else {
F_7 ( L_17 ,
V_146 -> V_71 [ 0 ] & V_85 ,
( V_146 -> V_71 [ 0 ] & V_86 )
>> V_80 ) ;
return 0 ;
}
}
void F_60 ( struct V_121 * V_122 ,
struct V_91 * V_92 )
{
struct V_9 * V_10 = V_122 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_158 * V_158 = F_49 ( V_122 ) ;
struct V_159 * V_142 ;
struct V_63 * V_63 ;
struct V_111 * V_112 ;
struct V_145 V_146 ;
T_1 V_126 ;
if ( ! V_158 -> V_160 )
return;
V_142 = V_158 -> V_160 ;
V_63 = F_33 ( V_92 ) ;
if ( ! V_63 -> V_113 )
return;
V_112 = V_63 -> V_113 ;
if ( ( V_112 -> V_136 != V_137 ) &&
( V_112 -> V_136 != V_138 ) )
return;
if ( F_34 ( & V_63 -> V_64 -> V_43 , V_176 , & V_126 )
== 1 ) {
if ( V_126 & V_177 )
V_146 . V_175 = true ;
else
V_146 . V_175 = false ;
} else {
V_146 . V_175 = false ;
}
memcpy ( V_146 . V_93 , V_112 -> V_93 , V_178 ) ;
V_146 . V_12 = V_12 ;
V_146 . V_122 = V_122 ;
V_146 . V_92 = V_92 ;
V_146 . V_139 = V_112 -> V_139 ;
V_146 . V_102 = V_112 -> V_102 ;
V_146 . V_43 = & V_63 -> V_64 -> V_43 ;
if ( F_48 ( & V_146 ) )
goto V_39;
if ( F_54 ( & V_146 ) )
goto V_39;
if ( F_58 ( & V_146 ) )
goto V_39;
V_39:
if ( F_52 ( & V_146 ) )
return;
}
