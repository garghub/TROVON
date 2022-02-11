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
V_20 = - V_38 ;
goto V_39;
}
if ( args . V_25 . V_37 == 2 ) {
F_7 ( L_1 ) ;
V_20 = - V_40 ;
goto V_39;
}
if ( args . V_25 . V_37 == 3 ) {
F_7 ( L_2 ) ;
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
F_14 ( V_46 , L_3 , V_46 ) ;
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
F_7 ( L_4 ,
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
F_7 ( L_5 ,
V_77 [ ( V_72 & V_85 ) >> V_78 ] ,
V_79 [ ( V_73 & V_86 ) >> V_80 ] ) ;
for ( V_74 = 0 ; V_74 < 4 ; V_74 ++ )
V_71 [ V_74 ] = V_72 | V_73 ;
}
static unsigned F_18 ( int V_87 )
{
if ( V_87 == 0 )
return 24 ;
else
return V_87 * 3 ;
}
static int F_19 ( struct V_88 * V_89 ,
const T_1 V_90 [ V_91 ] ,
unsigned V_92 ,
unsigned * V_93 , unsigned * V_94 )
{
unsigned V_95 =
F_18 ( F_20 ( V_89 ) ) ;
static const unsigned V_96 [ 3 ] = { 162000 , 270000 , 540000 } ;
unsigned V_97 = F_21 ( V_90 ) ;
unsigned V_98 = F_22 ( V_90 ) ;
unsigned V_99 , V_100 , V_101 ;
if ( F_23 ( V_89 ) ==
V_102 ) {
for ( V_99 = 1 ; V_99 <= V_98 ; V_99 <<= 1 ) {
V_101 = ( V_99 * 270000 * 8 ) / V_95 ;
if ( V_101 >= V_92 ) {
* V_93 = V_99 ;
* V_94 = 270000 ;
return 0 ;
}
}
} else {
for ( V_100 = 0 ; V_100 < F_24 ( V_96 ) && V_96 [ V_100 ] <= V_97 ; V_100 ++ ) {
for ( V_99 = 1 ; V_99 <= V_98 ; V_99 <<= 1 ) {
V_101 = ( V_99 * V_96 [ V_100 ] * 8 ) / V_95 ;
if ( V_101 >= V_92 ) {
* V_93 = V_99 ;
* V_94 = V_96 [ V_100 ] ;
return 0 ;
}
}
}
}
return - V_61 ;
}
static T_1 F_25 ( struct V_11 * V_12 ,
int V_103 , int V_104 ,
T_1 V_105 , T_1 V_99 )
{
T_4 args ;
int V_15 = F_2 ( V_16 , V_106 ) ;
memset ( & args , 0 , sizeof( args ) ) ;
args . V_107 = V_104 / 10 ;
args . V_108 = V_105 ;
args . V_109 = V_103 ;
args . V_110 = V_99 ;
args . V_111 = 0 ;
F_6 ( V_12 -> V_22 . V_23 , V_15 , ( V_36 * ) & args ) ;
return args . V_111 ;
}
T_1 F_26 ( struct V_63 * V_63 )
{
struct V_9 * V_10 = V_63 -> V_18 . V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
return F_25 ( V_12 , V_112 , 0 ,
V_63 -> V_64 -> V_31 . V_32 , 0 ) ;
}
static void F_27 ( struct V_63 * V_63 )
{
struct V_113 * V_114 = V_63 -> V_115 ;
T_1 V_116 [ 3 ] ;
if ( ! ( V_114 -> V_90 [ V_117 ] & V_118 ) )
return;
if ( F_28 ( & V_63 -> V_64 -> V_43 , V_119 , V_116 , 3 ) == 3 )
F_7 ( L_6 ,
V_116 [ 0 ] , V_116 [ 1 ] , V_116 [ 2 ] ) ;
if ( F_28 ( & V_63 -> V_64 -> V_43 , V_120 , V_116 , 3 ) == 3 )
F_7 ( L_7 ,
V_116 [ 0 ] , V_116 [ 1 ] , V_116 [ 2 ] ) ;
}
int F_29 ( struct V_63 * V_63 )
{
struct V_113 * V_114 = V_63 -> V_115 ;
T_1 V_45 [ V_91 ] ;
int V_46 ;
V_46 = F_28 ( & V_63 -> V_64 -> V_43 , V_121 ,
V_45 , V_91 ) ;
if ( V_46 == V_91 ) {
memcpy ( V_114 -> V_90 , V_45 , V_91 ) ;
F_7 ( L_8 , ( int ) sizeof( V_114 -> V_90 ) ,
V_114 -> V_90 ) ;
F_27 ( V_63 ) ;
return 0 ;
}
V_114 -> V_90 [ 0 ] = 0 ;
return - V_61 ;
}
int F_30 ( struct V_122 * V_123 ,
struct V_88 * V_89 )
{
struct V_63 * V_63 = F_31 ( V_89 ) ;
struct V_113 * V_114 ;
int V_124 = V_125 ;
V_27 V_126 = F_23 ( V_89 ) ;
T_1 V_127 ;
if ( ! V_63 -> V_115 )
return V_124 ;
V_114 = V_63 -> V_115 ;
if ( V_126 != V_128 ) {
if ( F_32 ( & V_63 -> V_64 -> V_43 ,
V_129 , & V_127 ) == 1 ) {
if ( V_127 & 1 )
V_124 = V_130 ;
else if ( ( V_126 == V_102 ) ||
( V_126 == V_131 ) )
V_124 = V_132 ;
else
V_124 = V_125 ;
}
} else if ( V_89 -> V_133 == V_134 ) {
if ( F_32 ( & V_63 -> V_64 -> V_43 ,
V_129 , & V_127 ) == 1 ) {
if ( V_127 & 1 )
V_124 = V_130 ;
}
}
return V_124 ;
}
void F_33 ( struct V_88 * V_89 ,
const struct V_135 * V_136 )
{
struct V_63 * V_63 = F_31 ( V_89 ) ;
struct V_113 * V_114 ;
int V_46 ;
if ( ! V_63 -> V_115 )
return;
V_114 = V_63 -> V_115 ;
if ( ( V_114 -> V_137 == V_138 ) ||
( V_114 -> V_137 == V_139 ) ) {
V_46 = F_19 ( V_89 , V_114 -> V_90 ,
V_136 -> clock ,
& V_114 -> V_140 ,
& V_114 -> V_104 ) ;
if ( V_46 ) {
V_114 -> V_104 = 0 ;
V_114 -> V_140 = 0 ;
}
}
}
int F_34 ( struct V_88 * V_89 ,
struct V_135 * V_136 )
{
struct V_63 * V_63 = F_31 ( V_89 ) ;
struct V_113 * V_114 ;
unsigned V_93 , V_104 ;
int V_46 ;
if ( ! V_63 -> V_115 )
return V_141 ;
V_114 = V_63 -> V_115 ;
V_46 = F_19 ( V_89 , V_114 -> V_90 ,
V_136 -> clock , & V_93 , & V_104 ) ;
if ( V_46 )
return V_141 ;
if ( ( V_104 == 540000 ) &&
( ! F_35 ( V_89 ) ) )
return V_141 ;
return V_142 ;
}
bool F_36 ( struct V_63 * V_63 )
{
T_1 V_68 [ V_69 ] ;
struct V_113 * V_143 = V_63 -> V_115 ;
if ( F_37 ( & V_63 -> V_64 -> V_43 , V_68 )
<= 0 )
return false ;
if ( F_38 ( V_68 , V_143 -> V_140 ) )
return false ;
return true ;
}
void F_39 ( struct V_88 * V_89 ,
T_1 V_144 )
{
struct V_63 * V_63 = F_31 ( V_89 ) ;
struct V_113 * V_114 ;
if ( ! V_63 -> V_115 )
return;
V_114 = V_63 -> V_115 ;
if ( V_114 -> V_90 [ 0 ] >= 0x11 ) {
F_40 ( & V_63 -> V_64 -> V_43 ,
V_145 , V_144 ) ;
F_41 ( 1000 , 2000 ) ;
}
}
static void
F_42 ( struct V_146 * V_147 )
{
F_43 ( V_147 -> V_123 ,
V_148 ,
0 , V_147 -> V_71 [ 0 ] ) ;
F_44 ( V_147 -> V_43 , V_149 ,
V_147 -> V_71 , V_147 -> V_140 ) ;
}
static void
F_45 ( struct V_146 * V_147 , int V_150 )
{
int V_151 = 0 ;
switch ( V_150 ) {
case V_152 :
V_151 = V_153 ;
break;
case V_154 :
V_151 = V_155 ;
break;
case V_156 :
V_151 = V_157 ;
break;
}
F_46 ( V_147 -> V_123 , V_151 , 0 ) ;
F_40 ( V_147 -> V_43 , V_158 , V_150 ) ;
}
static int
F_47 ( struct V_146 * V_147 )
{
struct V_159 * V_159 = F_48 ( V_147 -> V_123 ) ;
struct V_160 * V_143 = V_159 -> V_161 ;
T_1 V_127 ;
F_39 ( V_147 -> V_89 , V_162 ) ;
if ( V_147 -> V_90 [ 3 ] & 0x1 )
F_40 ( V_147 -> V_43 ,
V_163 , V_164 ) ;
else
F_40 ( V_147 -> V_43 ,
V_163 , 0 ) ;
if ( V_143 -> V_124 == V_130 )
F_40 ( V_147 -> V_43 , V_165 , 1 ) ;
V_127 = V_147 -> V_140 ;
if ( F_49 ( V_147 -> V_90 ) )
V_127 |= V_166 ;
F_40 ( V_147 -> V_43 , V_167 , V_127 ) ;
V_127 = F_50 ( V_147 -> V_104 ) ;
F_40 ( V_147 -> V_43 , V_168 , V_127 ) ;
F_46 ( V_147 -> V_123 ,
V_169 , 0 ) ;
F_40 ( V_147 -> V_43 ,
V_158 ,
V_170 ) ;
return 0 ;
}
static int
F_51 ( struct V_146 * V_147 )
{
F_52 ( 400 ) ;
F_40 ( V_147 -> V_43 ,
V_158 ,
V_170 ) ;
F_46 ( V_147 -> V_123 ,
V_171 , 0 ) ;
return 0 ;
}
static int
F_53 ( struct V_146 * V_147 )
{
bool V_172 ;
T_1 V_173 ;
int V_100 ;
F_45 ( V_147 , V_152 ) ;
memset ( V_147 -> V_71 , 0 , 4 ) ;
F_42 ( V_147 ) ;
F_52 ( 400 ) ;
V_172 = false ;
V_147 -> V_174 = 0 ;
V_173 = 0xff ;
while ( 1 ) {
F_54 ( V_147 -> V_90 ) ;
if ( F_37 ( V_147 -> V_43 ,
V_147 -> V_68 ) <= 0 ) {
F_55 ( L_9 ) ;
break;
}
if ( F_56 ( V_147 -> V_68 , V_147 -> V_140 ) ) {
V_172 = true ;
break;
}
for ( V_100 = 0 ; V_100 < V_147 -> V_140 ; V_100 ++ ) {
if ( ( V_147 -> V_71 [ V_100 ] & V_82 ) == 0 )
break;
}
if ( V_100 == V_147 -> V_140 ) {
F_55 ( L_10 ) ;
break;
}
if ( ( V_147 -> V_71 [ 0 ] & V_85 ) == V_173 ) {
++ V_147 -> V_174 ;
if ( V_147 -> V_174 == 5 ) {
F_55 ( L_11 ) ;
break;
}
} else
V_147 -> V_174 = 0 ;
V_173 = V_147 -> V_71 [ 0 ] & V_85 ;
F_15 ( V_147 -> V_68 , V_147 -> V_140 ,
V_147 -> V_71 ) ;
F_42 ( V_147 ) ;
}
if ( ! V_172 ) {
F_55 ( L_12 ) ;
return - 1 ;
} else {
F_7 ( L_13 ,
V_147 -> V_71 [ 0 ] & V_85 ,
( V_147 -> V_71 [ 0 ] & V_86 ) >>
V_80 ) ;
return 0 ;
}
}
static int
F_57 ( struct V_146 * V_147 )
{
bool V_175 ;
if ( V_147 -> V_176 )
F_45 ( V_147 , V_156 ) ;
else
F_45 ( V_147 , V_154 ) ;
V_147 -> V_174 = 0 ;
V_175 = false ;
while ( 1 ) {
F_58 ( V_147 -> V_90 ) ;
if ( F_37 ( V_147 -> V_43 ,
V_147 -> V_68 ) <= 0 ) {
F_55 ( L_9 ) ;
break;
}
if ( F_38 ( V_147 -> V_68 , V_147 -> V_140 ) ) {
V_175 = true ;
break;
}
if ( V_147 -> V_174 > 5 ) {
F_55 ( L_14 ) ;
break;
}
F_15 ( V_147 -> V_68 , V_147 -> V_140 ,
V_147 -> V_71 ) ;
F_42 ( V_147 ) ;
V_147 -> V_174 ++ ;
}
if ( ! V_175 ) {
F_55 ( L_15 ) ;
return - 1 ;
} else {
F_7 ( L_16 ,
V_147 -> V_71 [ 0 ] & V_85 ,
( V_147 -> V_71 [ 0 ] & V_86 )
>> V_80 ) ;
return 0 ;
}
}
void F_59 ( struct V_122 * V_123 ,
struct V_88 * V_89 )
{
struct V_9 * V_10 = V_123 -> V_10 ;
struct V_11 * V_12 = V_10 -> V_13 ;
struct V_159 * V_159 = F_48 ( V_123 ) ;
struct V_160 * V_143 ;
struct V_63 * V_63 ;
struct V_113 * V_114 ;
struct V_146 V_147 ;
T_1 V_127 ;
if ( ! V_159 -> V_161 )
return;
V_143 = V_159 -> V_161 ;
V_63 = F_31 ( V_89 ) ;
if ( ! V_63 -> V_115 )
return;
V_114 = V_63 -> V_115 ;
if ( ( V_114 -> V_137 != V_138 ) &&
( V_114 -> V_137 != V_139 ) )
return;
if ( F_32 ( & V_63 -> V_64 -> V_43 , V_177 , & V_127 )
== 1 ) {
if ( V_127 & V_178 )
V_147 . V_176 = true ;
else
V_147 . V_176 = false ;
} else {
V_147 . V_176 = false ;
}
memcpy ( V_147 . V_90 , V_114 -> V_90 , V_179 ) ;
V_147 . V_12 = V_12 ;
V_147 . V_123 = V_123 ;
V_147 . V_89 = V_89 ;
V_147 . V_140 = V_114 -> V_140 ;
V_147 . V_104 = V_114 -> V_104 ;
V_147 . V_43 = & V_63 -> V_64 -> V_43 ;
if ( F_47 ( & V_147 ) )
goto V_39;
if ( F_53 ( & V_147 ) )
goto V_39;
if ( F_57 ( & V_147 ) )
goto V_39;
V_39:
if ( F_51 ( & V_147 ) )
return;
}
