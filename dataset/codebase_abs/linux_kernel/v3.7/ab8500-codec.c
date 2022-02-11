static inline const char * F_1 ( enum V_1 V_2 )
{
switch ( V_2 ) {
case V_3 :
return L_1 ;
case V_4 :
return L_2 ;
default:
return L_3 ;
}
}
static inline const char * F_2 ( enum V_5 type )
{
switch ( type ) {
case V_6 :
return L_4 ;
case V_7 :
return L_5 ;
default:
return L_3 ;
}
}
static unsigned int F_3 ( struct V_8 * V_9 ,
unsigned int V_10 )
{
int V_11 ;
unsigned int V_12 = 0 ;
T_1 V_13 ;
V_11 = F_4 ( V_9 -> V_14 , V_15 ,
V_10 , & V_13 ) ;
if ( V_11 < 0 ) {
F_5 ( V_9 -> V_14 ,
L_6 ,
V_16 , ( T_1 ) V_15 , ( T_1 ) V_10 , V_11 ) ;
} else {
F_6 ( V_9 -> V_14 ,
L_7 ,
V_16 , V_13 , ( T_1 ) V_15 , ( T_1 ) V_10 ) ;
V_12 = ( unsigned int ) V_13 ;
}
return V_12 ;
}
static int F_7 ( struct V_8 * V_9 ,
unsigned int V_10 , unsigned int V_12 )
{
int V_11 ;
V_11 = F_8 ( V_9 -> V_14 , V_15 ,
V_10 , V_12 ) ;
if ( V_11 < 0 )
F_5 ( V_9 -> V_14 ,
L_8 ,
V_16 , ( T_1 ) V_15 , ( T_1 ) V_10 , V_11 ) ;
else
F_6 ( V_9 -> V_14 ,
L_9 ,
V_16 , ( T_1 ) V_12 , ( T_1 ) V_15 , ( T_1 ) V_10 ) ;
return V_11 ;
}
static void F_9 ( struct V_8 * V_9 ,
unsigned int V_17 , unsigned int V_18 , unsigned int V_19 )
{
if ( V_18 == 0 && V_17 == 0 )
F_10 ( V_9 , V_20 ,
F_11 ( V_21 ) ,
F_11 ( V_21 ) ) ;
F_12 ( V_9 , V_22 , V_19 >> 8 & 0xff ) ;
F_12 ( V_9 , V_23 , V_19 & 0xff ) ;
if ( V_18 == V_24 - 1 && V_17 == 1 )
F_10 ( V_9 , V_20 ,
F_11 ( V_21 ) , 0 ) ;
}
static void F_13 ( struct V_8 * V_9 , unsigned int V_17 ,
unsigned int V_18 , unsigned int V_19 )
{
if ( V_18 == 0 ) {
if ( V_17 == 0 ) {
F_10 ( V_9 , V_20 ,
F_11 ( V_25 ) ,
F_11 ( V_25 ) ) ;
F_14 ( V_26 , V_26 ) ;
F_10 ( V_9 , V_20 ,
F_11 ( V_25 ) , 0 ) ;
F_14 ( V_26 , V_26 ) ;
} else {
F_10 ( V_9 , V_20 ,
F_11 ( V_27 ) ,
F_11 ( V_27 ) ) ;
}
} else if ( V_18 > 3 ) {
F_12 ( V_9 , V_28 , 0 ) ;
F_12 ( V_9 , V_29 , V_19 >> 16 & 0xff ) ;
}
F_12 ( V_9 , V_28 , V_19 >> 8 & 0xff ) ;
F_12 ( V_9 , V_29 , V_19 & 0xff ) ;
if ( V_18 == V_30 - 1 && V_17 == 1 )
F_10 ( V_9 , V_20 ,
F_11 ( V_27 ) , 0 ) ;
}
static void F_15 ( struct V_8 * V_9 ,
bool V_31 , bool V_32 )
{
struct V_33 * V_34 = F_16 ( V_9 -> V_14 ) ;
unsigned int V_17 , V_18 , V_19 ;
F_6 ( V_9 -> V_14 , L_10 , V_16 ) ;
if ( V_31 )
F_10 ( V_9 , V_20 ,
F_11 ( V_35 ) , 0 ) ;
F_10 ( V_9 , V_20 ,
F_11 ( V_35 ) , F_11 ( V_35 ) ) ;
if ( V_31 )
for ( V_17 = 0 ; V_17 < V_36 ; V_17 ++ )
for ( V_18 = 0 ; V_18 < V_24 ; V_18 ++ ) {
V_19 = F_17 ( V_9 ,
V_34 -> V_37 [ V_18 ] ) ;
F_9 ( V_9 , V_17 , V_18 , V_19 ) ;
}
if ( V_32 )
for ( V_17 = 0 ; V_17 < V_36 ; V_17 ++ )
for ( V_18 = 0 ; V_18 < V_30 ; V_18 ++ ) {
V_19 = F_17 ( V_9 ,
V_34 -> V_38 [ V_18 ] ) ;
F_13 ( V_9 , V_17 , V_18 , V_19 ) ;
}
F_6 ( V_9 -> V_14 , L_11 , V_16 ) ;
}
static int F_18 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_8 * V_9 = F_19 ( V_40 ) ;
struct V_33 * V_34 = F_16 ( V_9 -> V_14 ) ;
F_20 ( & V_9 -> V_43 ) ;
V_42 -> V_12 . integer . V_12 [ 0 ] = V_34 -> V_44 ;
F_21 ( & V_9 -> V_43 ) ;
return 0 ;
}
static int F_22 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_8 * V_9 = F_19 ( V_40 ) ;
struct V_33 * V_34 = F_16 ( V_9 -> V_14 ) ;
unsigned int V_45 , V_46 , V_19 ;
int V_11 = 1 ;
F_6 ( V_9 -> V_14 , L_12 , V_16 ) ;
if ( V_42 -> V_12 . integer . V_12 [ 0 ] != V_47 ) {
F_5 ( V_9 -> V_14 ,
L_13 ,
V_16 , V_48 [ V_47 ] ) ;
return - V_49 ;
}
F_20 ( & V_9 -> V_43 ) ;
V_46 = F_17 ( V_9 , V_50 ) ;
if ( ( ( V_46 & F_11 ( V_51 ) ) != 0 ) ) {
if ( ( V_46 & F_11 ( V_52 ) ) == 0 ) {
F_5 ( V_9 -> V_14 , L_14 ,
V_16 ) ;
V_11 = - V_53 ;
} else {
V_11 = - V_54 ;
}
goto V_55;
}
F_12 ( V_9 , V_56 , 0 ) ;
for ( V_45 = 0 ; V_45 < V_57 ; V_45 ++ ) {
V_19 = F_17 ( V_9 , V_34 -> V_58 [ V_45 ] ) ;
F_12 ( V_9 , V_59 , V_19 >> 8 & 0xff ) ;
F_12 ( V_9 , V_60 , V_19 & 0xff ) ;
}
F_10 ( V_9 , V_56 ,
F_11 ( V_61 ) ,
F_11 ( V_61 ) ) ;
F_10 ( V_9 , V_56 ,
F_11 ( V_61 ) , 0 ) ;
V_34 -> V_44 = V_62 ;
V_55:
F_21 ( & V_9 -> V_43 ) ;
F_6 ( V_9 -> V_14 , L_15 , V_16 ) ;
return V_11 ;
}
static int F_23 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_8 * V_9 = F_19 ( V_40 ) ;
struct V_33 * V_34 = F_16 ( V_9 -> V_14 ) ;
F_20 ( & V_9 -> V_43 ) ;
V_42 -> V_12 . integer . V_12 [ 0 ] = V_34 -> V_63 ;
F_21 ( & V_9 -> V_43 ) ;
return 0 ;
}
static int F_24 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_8 * V_9 = F_19 ( V_40 ) ;
struct V_33 * V_34 = F_16 ( V_9 -> V_14 ) ;
struct V_64 * V_14 = V_9 -> V_14 ;
bool V_31 , V_32 ;
int V_65 , V_11 ;
F_6 ( V_14 , L_10 , V_16 ) ;
F_20 ( & V_34 -> V_66 ) ;
V_65 = V_42 -> V_12 . integer . V_12 [ 0 ] ;
if ( V_65 != V_67 && V_65 != V_68 &&
V_65 != V_69 ) {
F_5 ( V_14 , L_16 ,
V_16 , V_70 [ V_65 ] ) ;
V_11 = - V_71 ;
goto V_72;
}
V_31 = V_65 == V_68 || V_65 == V_67 ;
V_32 = V_65 == V_69 || V_65 == V_67 ;
V_11 = F_25 ( & V_9 -> V_73 ,
L_17 ) ;
if ( V_11 < 0 ) {
F_5 ( V_14 ,
L_18 ,
V_16 , V_11 ) ;
goto V_72;
}
F_26 ( & V_9 -> V_73 ) ;
F_20 ( & V_9 -> V_43 ) ;
F_15 ( V_9 , V_31 , V_32 ) ;
F_21 ( & V_9 -> V_43 ) ;
if ( V_31 ) {
if ( V_34 -> V_63 == V_74 )
V_34 -> V_63 = V_75 ;
else if ( V_34 -> V_63 != V_75 )
V_34 -> V_63 = V_76 ;
}
if ( V_32 ) {
if ( V_34 -> V_63 == V_76 )
V_34 -> V_63 = V_75 ;
else if ( V_34 -> V_63 != V_75 )
V_34 -> V_63 = V_74 ;
}
V_11 = F_27 ( & V_9 -> V_73 , L_17 ) ;
F_26 ( & V_9 -> V_73 ) ;
V_72:
F_21 ( & V_34 -> V_66 ) ;
if ( V_11 < 0 )
F_5 ( V_14 , L_19 ,
V_16 , V_11 ) ;
F_6 ( V_14 , L_11 , V_16 ) ;
return ( V_11 < 0 ) ? V_11 : 1 ;
}
static int F_28 ( struct V_39 * V_40 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 =
(struct V_79 * ) V_40 -> V_81 ;
V_78 -> type = V_82 ;
V_78 -> V_83 = V_80 -> V_83 ;
V_78 -> V_12 . integer . V_84 = V_80 -> V_84 ;
V_78 -> V_12 . integer . V_85 = V_80 -> V_85 ;
return 0 ;
}
static int F_29 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_8 * V_9 = F_19 ( V_40 ) ;
struct V_79 * V_80 =
(struct V_79 * ) V_40 -> V_81 ;
unsigned int V_86 ;
F_20 ( & V_9 -> V_43 ) ;
for ( V_86 = 0 ; V_86 < V_80 -> V_83 ; V_86 ++ )
V_42 -> V_12 . integer . V_12 [ V_86 ] = V_80 -> V_12 [ V_86 ] ;
F_21 ( & V_9 -> V_43 ) ;
return 0 ;
}
static int F_30 ( struct V_39 * V_40 ,
struct V_41 * V_42 )
{
struct V_8 * V_9 = F_19 ( V_40 ) ;
struct V_79 * V_80 =
(struct V_79 * ) V_40 -> V_81 ;
unsigned int V_86 ;
F_20 ( & V_9 -> V_43 ) ;
for ( V_86 = 0 ; V_86 < V_80 -> V_83 ; V_86 ++ )
V_80 -> V_12 [ V_86 ] = V_42 -> V_12 . integer . V_12 [ V_86 ] ;
F_21 ( & V_9 -> V_43 ) ;
return 0 ;
}
static int F_31 ( struct V_8 * V_9 )
{
int V_11 ;
F_6 ( V_9 -> V_14 , L_10 , V_16 ) ;
V_11 = F_32 ( V_87 ,
V_88 |
V_89 ,
V_89 ) ;
if ( V_11 < 0 )
return V_11 ;
return 0 ;
}
static int F_33 ( struct V_8 * V_9 ,
struct V_90 * V_91 )
{
T_1 V_13 ;
unsigned int V_12 ;
int V_11 ;
const struct V_92 * V_93 ;
F_6 ( V_9 -> V_14 , L_10 , V_16 ) ;
V_11 = F_4 ( V_9 -> V_14 , ( T_1 ) V_94 ,
( T_1 ) V_95 ,
& V_13 ) ;
if ( V_11 < 0 )
return V_11 ;
V_12 = V_13 | V_96 | V_97 |
V_98 ;
V_11 = F_8 ( V_9 -> V_14 ,
( T_1 ) V_94 ,
( T_1 ) V_95 ,
V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
F_6 ( V_9 -> V_14 , L_20 , V_16 ,
F_1 ( V_91 -> V_99 ) ) ;
V_93 = & V_100 [ V_91 -> V_99 ] ;
V_11 = F_34 ( & V_9 -> V_73 , V_93 , 1 ) ;
F_6 ( V_9 -> V_14 , L_21 , V_16 ,
F_1 ( V_91 -> V_101 ) ) ;
V_93 = & V_102 [ V_91 -> V_101 ] ;
V_11 |= F_34 ( & V_9 -> V_73 , V_93 , 1 ) ;
F_6 ( V_9 -> V_14 , L_22 , V_16 ,
F_1 ( V_91 -> V_103 ) ) ;
V_93 = & V_104 [ V_91 -> V_103 ] ;
V_11 |= F_34 ( & V_9 -> V_73 , V_93 , 1 ) ;
if ( V_11 < 0 ) {
F_5 ( V_9 -> V_14 ,
L_23 ,
V_16 , V_11 ) ;
return V_11 ;
}
F_6 ( V_9 -> V_14 , L_24 , V_16 ,
F_2 ( V_91 -> V_105 ) ) ;
F_10 ( V_9 , V_106 , V_107 ,
V_91 -> V_105 == V_6 ?
0 : V_107 ) ;
F_6 ( V_9 -> V_14 , L_25 , V_16 ,
F_2 ( V_91 -> V_108 ) ) ;
F_10 ( V_9 , V_109 , V_107 ,
V_91 -> V_108 == V_6 ?
0 : V_107 ) ;
return 0 ;
}
static int F_35 ( struct V_8 * V_9 ,
enum V_110 V_111 )
{
char * V_112 ;
switch ( V_111 ) {
case V_113 :
V_112 = L_26 ;
break;
case V_114 :
V_112 = L_27 ;
break;
case V_115 :
V_112 = L_28 ;
break;
case V_116 :
V_112 = L_29 ;
break;
default:
F_5 ( V_9 -> V_14 ,
L_30 ,
V_16 , ( int ) V_111 ) ;
return - V_71 ;
}
F_6 ( V_9 -> V_14 , L_31 , V_16 ,
V_112 ) ;
F_10 ( V_9 , V_117 , V_118 ,
V_111 ) ;
return 0 ;
}
static int F_36 ( struct V_119 * V_120 ,
unsigned int V_121 )
{
unsigned int V_122 , V_19 ;
struct V_8 * V_9 = V_120 -> V_9 ;
V_122 = F_11 ( V_123 ) ;
V_19 = 0 ;
switch ( V_121 ) {
case 0 :
break;
case 1 :
V_19 |= F_11 ( V_123 ) ;
break;
default:
F_5 ( V_120 -> V_9 -> V_14 ,
L_32 ,
V_16 , V_121 ) ;
return - V_71 ;
}
F_6 ( V_120 -> V_9 -> V_14 , L_33 ,
V_16 , V_121 ) ;
F_10 ( V_9 , V_124 , V_122 , V_19 ) ;
return 0 ;
}
static int F_37 ( struct V_8 * V_9 ,
unsigned int V_125 )
{
unsigned int V_122 ;
unsigned int V_19 ;
V_122 = F_11 ( V_126 ) |
F_11 ( V_127 ) ;
V_19 = F_11 ( V_126 ) ;
switch ( V_125 & V_128 ) {
case V_129 :
F_6 ( V_9 -> V_14 , L_34 ,
V_16 ) ;
V_19 |= F_11 ( V_127 ) ;
break;
case V_130 :
F_6 ( V_9 -> V_14 , L_35 ,
V_16 ) ;
break;
default:
F_5 ( V_9 -> V_14 ,
L_36 ,
V_16 , V_125 & V_128 ) ;
return - V_71 ;
}
F_10 ( V_9 , V_131 , V_122 , V_19 ) ;
return 0 ;
}
static int F_38 ( struct V_119 * V_120 , unsigned int V_125 )
{
unsigned int V_122 ;
unsigned int V_19 ;
struct V_8 * V_9 = V_120 -> V_9 ;
int V_11 ;
F_6 ( V_9 -> V_14 , L_37 , V_16 , V_125 ) ;
V_122 = F_11 ( V_132 ) |
F_11 ( V_133 ) |
F_11 ( V_134 ) |
F_11 ( V_135 ) ;
V_19 = 0 ;
switch ( V_125 & V_136 ) {
case V_137 :
F_6 ( V_120 -> V_9 -> V_14 ,
L_38 , V_16 ) ;
V_19 |= F_11 ( V_135 ) ;
break;
case V_138 :
F_6 ( V_120 -> V_9 -> V_14 ,
L_39 , V_16 ) ;
break;
case V_139 :
case V_140 :
F_5 ( V_120 -> V_9 -> V_14 ,
L_40 ,
V_16 ) ;
default:
F_5 ( V_120 -> V_9 -> V_14 ,
L_41 ,
V_16 , V_125 & V_136 ) ;
return - V_71 ;
break;
}
F_10 ( V_9 , V_141 , V_122 , V_19 ) ;
V_11 = F_37 ( V_9 , V_125 ) ;
if ( V_11 ) {
F_5 ( V_120 -> V_9 -> V_14 ,
L_42 ,
V_16 , V_11 ) ;
return V_11 ;
}
V_122 = F_11 ( V_142 ) |
F_11 ( V_143 ) |
F_11 ( V_144 ) |
F_11 ( V_145 ) ;
V_19 = 0 ;
switch ( V_125 & V_146 ) {
case V_147 :
F_6 ( V_120 -> V_9 -> V_14 , L_43 , V_16 ) ;
V_19 |= F_11 ( V_143 ) ;
F_36 ( V_120 , 0 ) ;
break;
case V_148 :
F_6 ( V_120 -> V_9 -> V_14 ,
L_44 , V_16 ) ;
V_19 |= F_11 ( V_142 ) ;
F_36 ( V_120 , 1 ) ;
break;
case V_149 :
F_6 ( V_120 -> V_9 -> V_14 ,
L_45 , V_16 ) ;
V_19 |= F_11 ( V_142 ) ;
F_36 ( V_120 , 0 ) ;
break;
default:
F_5 ( V_120 -> V_9 -> V_14 ,
L_46 ,
V_16 , V_125 & V_146 ) ;
return - V_71 ;
}
switch ( V_125 & V_150 ) {
case V_151 :
F_6 ( V_120 -> V_9 -> V_14 ,
L_47 ,
V_16 ) ;
break;
case V_152 :
F_6 ( V_120 -> V_9 -> V_14 ,
L_48 ,
V_16 ) ;
V_19 |= F_11 ( V_144 ) ;
break;
case V_153 :
F_6 ( V_120 -> V_9 -> V_14 ,
L_49 ,
V_16 ) ;
V_19 |= F_11 ( V_145 ) ;
break;
case V_154 :
F_6 ( V_120 -> V_9 -> V_14 ,
L_50 ,
V_16 ) ;
V_19 |= F_11 ( V_144 ) ;
V_19 |= F_11 ( V_145 ) ;
break;
default:
F_5 ( V_120 -> V_9 -> V_14 ,
L_51 ,
V_16 , V_125 & V_150 ) ;
return - V_71 ;
}
F_10 ( V_9 , V_124 , V_122 , V_19 ) ;
return 0 ;
}
static int F_39 ( struct V_119 * V_120 ,
unsigned int V_155 , unsigned int V_156 ,
int V_157 , int V_158 )
{
struct V_8 * V_9 = V_120 -> V_9 ;
unsigned int V_19 , V_122 , V_159 ;
V_122 = F_11 ( V_160 ) |
F_11 ( V_161 ) ;
V_19 = 0 ;
switch ( V_158 ) {
case 16 :
break;
case 20 :
V_19 |= F_11 ( V_160 ) ;
break;
case 24 :
V_19 |= F_11 ( V_161 ) ;
break;
case 32 :
V_19 |= F_11 ( V_161 ) |
F_11 ( V_160 ) ;
break;
default:
F_5 ( V_120 -> V_9 -> V_14 , L_52 ,
V_16 , V_158 ) ;
return - V_71 ;
}
F_6 ( V_120 -> V_9 -> V_14 , L_53 ,
V_16 , V_158 ) ;
F_10 ( V_9 , V_124 , V_122 , V_19 ) ;
F_6 ( V_120 -> V_9 -> V_14 , L_54 , V_16 , V_157 ) ;
V_122 = F_11 ( V_162 ) |
F_11 ( V_163 ) ;
switch ( V_157 ) {
case 2 :
V_19 = V_164 ;
break;
case 4 :
V_19 = F_11 ( V_162 ) ;
break;
case 8 :
V_19 = F_11 ( V_163 ) ;
break;
case 16 :
V_19 = F_11 ( V_162 ) |
F_11 ( V_163 ) ;
break;
default:
F_5 ( V_120 -> V_9 -> V_14 ,
L_55 ,
V_16 , V_157 ) ;
return - V_71 ;
}
F_10 ( V_9 , V_131 , V_122 , V_19 ) ;
V_122 = V_165 ;
V_159 = F_40 ( V_155 ) ;
F_6 ( V_120 -> V_9 -> V_14 , L_56 , V_16 ,
V_159 ) ;
switch ( V_159 ) {
case 0 :
break;
case 1 :
F_10 ( V_9 , V_166 , V_122 , 11 ) ;
F_10 ( V_9 , V_167 , V_122 , 11 ) ;
F_10 ( V_9 , V_168 , V_122 , 11 ) ;
F_10 ( V_9 , V_169 , V_122 , 11 ) ;
break;
case 2 :
F_10 ( V_9 , V_166 , V_122 , 9 ) ;
F_10 ( V_9 , V_167 , V_122 , 9 ) ;
F_10 ( V_9 , V_168 , V_122 , 11 ) ;
F_10 ( V_9 , V_169 , V_122 , 11 ) ;
break;
case 8 :
F_6 ( V_120 -> V_9 -> V_14 ,
L_57 ,
V_16 ) ;
break;
default:
F_5 ( V_120 -> V_9 -> V_14 ,
L_58 ,
V_16 , V_159 ) ;
return - V_71 ;
}
V_159 = F_40 ( V_156 ) ;
F_6 ( V_120 -> V_9 -> V_14 , L_59 , V_16 ,
V_159 ) ;
switch ( V_159 ) {
case 0 :
break;
case 1 :
F_10 ( V_9 , V_170 , V_171 ,
V_172 |
V_173 ) ;
break;
case 2 :
F_10 ( V_9 ,
V_170 ,
V_171 ,
V_172 |
V_174 ) ;
break;
case 8 :
F_6 ( V_120 -> V_9 -> V_14 ,
L_60 ,
V_16 ) ;
break;
default:
F_5 ( V_120 -> V_9 -> V_14 ,
L_61 ,
V_16 , V_159 ) ;
return - V_71 ;
}
return 0 ;
}
static void F_41 ( struct V_64 * V_14 , struct V_175 * V_176 ,
struct V_177 * V_9 )
{
T_2 V_12 ;
if ( F_42 ( V_176 , L_62 , NULL ) )
V_9 -> V_91 . V_105 = V_7 ;
else
V_9 -> V_91 . V_105 = V_6 ;
if ( F_42 ( V_176 , L_63 , NULL ) )
V_9 -> V_91 . V_108 = V_7 ;
else
V_9 -> V_91 . V_108 = V_6 ;
if ( F_42 ( V_176 , L_64 , NULL ) )
V_9 -> V_91 . V_99 = V_4 ;
else
V_9 -> V_91 . V_99 = V_3 ;
if ( F_42 ( V_176 , L_65 , NULL ) )
V_9 -> V_91 . V_101 = V_4 ;
else
V_9 -> V_91 . V_101 = V_3 ;
if ( F_42 ( V_176 , L_66 , NULL ) )
V_9 -> V_91 . V_103 = V_3 ;
else
V_9 -> V_91 . V_103 = V_4 ;
if ( ! F_43 ( V_176 , L_67 , & V_12 ) ) {
switch ( V_12 ) {
case 950 :
V_9 -> V_111 = V_113 ;
break;
case 1100 :
V_9 -> V_111 = V_114 ;
break;
case 1270 :
V_9 -> V_111 = V_115 ;
break;
case 1580 :
V_9 -> V_111 = V_116 ;
break;
default :
V_9 -> V_111 = V_178 ;
F_5 ( V_14 , L_68 ) ;
}
} else {
F_44 ( V_14 , L_69 ) ;
V_9 -> V_111 = V_113 ;
}
}
static int F_45 ( struct V_8 * V_9 )
{
struct V_64 * V_14 = V_9 -> V_14 ;
struct V_175 * V_176 = V_14 -> V_179 ;
struct V_33 * V_34 = F_16 ( V_14 ) ;
struct V_180 * V_181 ;
struct V_79 * V_80 ;
int V_11 ;
F_6 ( V_14 , L_10 , V_16 ) ;
V_181 = F_46 ( V_14 -> V_182 ) ;
if ( V_176 ) {
if ( ! V_181 )
V_181 = F_47 ( V_14 ,
sizeof( struct V_180 ) ,
V_183 ) ;
if ( V_181 && ! V_181 -> V_9 )
V_181 -> V_9
= F_47 ( V_14 ,
sizeof( struct V_177 ) ,
V_183 ) ;
if ( ! ( V_181 && V_181 -> V_9 ) )
return - V_184 ;
F_41 ( V_14 , V_176 , V_181 -> V_9 ) ;
} else {
if ( ! ( V_181 && V_181 -> V_9 ) ) {
F_5 ( V_14 , L_70 ) ;
return - V_71 ;
}
}
V_11 = F_33 ( V_9 , & V_181 -> V_9 -> V_91 ) ;
if ( V_11 < 0 ) {
F_48 ( L_71 , V_16 , V_11 ) ;
return V_11 ;
}
V_11 = F_35 ( V_9 , V_181 -> V_9 -> V_111 ) ;
if ( V_11 < 0 ) {
F_48 ( L_72 ,
V_16 , V_11 ) ;
return V_11 ;
}
V_11 = F_31 ( V_9 ) ;
if ( V_11 < 0 ) {
F_5 ( V_14 , L_73 ,
V_16 , V_11 ) ;
return V_11 ;
}
F_7 ( V_9 ,
V_185 ,
F_11 ( V_186 ) ) ;
F_7 ( V_9 ,
V_187 ,
F_11 ( V_188 ) ) ;
V_11 = F_49 ( V_9 , V_189 ,
F_50 ( V_189 ) ) ;
if ( V_11 < 0 ) {
F_5 ( V_14 ,
L_74 ,
V_16 , V_11 ) ;
return V_11 ;
}
V_80 = (struct V_79 * )
& V_189 [ V_190 ] . V_81 ;
V_34 -> V_37 = ( long * ) V_80 -> V_12 ;
V_80 = (struct V_79 * )
& V_189 [ V_191 ] . V_81 ;
V_34 -> V_38 = ( long * ) V_80 -> V_12 ;
V_80 = (struct V_79 * )
& V_189 [ V_192 ] . V_81 ;
V_34 -> V_58 = ( long * ) V_80 -> V_12 ;
( void ) F_27 ( & V_9 -> V_73 , L_17 ) ;
F_51 ( & V_34 -> V_66 ) ;
return V_11 ;
}
static int T_3 F_52 ( struct V_193 * V_194 )
{
int V_11 ;
struct V_33 * V_34 ;
F_6 ( & V_194 -> V_14 , L_10 , V_16 ) ;
V_34 = F_47 ( & V_194 -> V_14 , sizeof( struct V_33 ) ,
V_183 ) ;
V_34 -> V_44 = V_195 ;
V_34 -> V_63 = V_196 ;
F_53 ( & V_194 -> V_14 , V_34 ) ;
F_6 ( & V_194 -> V_14 , L_75 , V_16 ) ;
V_11 = F_54 ( & V_194 -> V_14 , & V_197 ,
V_198 ,
F_50 ( V_198 ) ) ;
if ( V_11 < 0 )
F_5 ( & V_194 -> V_14 ,
L_76 ,
V_16 , V_11 ) ;
return V_11 ;
}
static int T_4 F_55 ( struct V_193 * V_194 )
{
F_56 ( & V_194 -> V_14 , L_77 , V_16 ) ;
F_57 ( & V_194 -> V_14 ) ;
return 0 ;
}
