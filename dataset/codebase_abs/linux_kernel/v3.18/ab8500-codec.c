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
static int F_3 ( void * V_8 , unsigned int V_9 ,
unsigned int * V_10 )
{
struct V_11 * V_12 = V_8 ;
int V_13 ;
T_1 V_14 ;
V_13 = F_4 ( V_12 , V_15 ,
V_9 , & V_14 ) ;
* V_10 = ( unsigned int ) V_14 ;
return V_13 ;
}
static int F_5 ( void * V_8 , unsigned int V_9 ,
unsigned int V_10 )
{
struct V_11 * V_12 = V_8 ;
return F_6 ( V_12 , V_15 ,
V_9 , V_10 ) ;
}
static void F_7 ( struct V_16 * V_17 ,
unsigned int V_18 , unsigned int V_19 , unsigned int V_20 )
{
if ( V_19 == 0 && V_18 == 0 )
F_8 ( V_17 , V_21 ,
F_9 ( V_22 ) ,
F_9 ( V_22 ) ) ;
F_10 ( V_17 , V_23 , V_20 >> 8 & 0xff ) ;
F_10 ( V_17 , V_24 , V_20 & 0xff ) ;
if ( V_19 == V_25 - 1 && V_18 == 1 )
F_8 ( V_17 , V_21 ,
F_9 ( V_22 ) , 0 ) ;
}
static void F_11 ( struct V_16 * V_17 , unsigned int V_18 ,
unsigned int V_19 , unsigned int V_20 )
{
if ( V_19 == 0 ) {
if ( V_18 == 0 ) {
F_8 ( V_17 , V_21 ,
F_9 ( V_26 ) ,
F_9 ( V_26 ) ) ;
F_12 ( V_27 , V_27 ) ;
F_8 ( V_17 , V_21 ,
F_9 ( V_26 ) , 0 ) ;
F_12 ( V_27 , V_27 ) ;
} else {
F_8 ( V_17 , V_21 ,
F_9 ( V_28 ) ,
F_9 ( V_28 ) ) ;
}
} else if ( V_19 > 3 ) {
F_10 ( V_17 , V_29 , 0 ) ;
F_10 ( V_17 , V_30 , V_20 >> 16 & 0xff ) ;
}
F_10 ( V_17 , V_29 , V_20 >> 8 & 0xff ) ;
F_10 ( V_17 , V_30 , V_20 & 0xff ) ;
if ( V_19 == V_31 - 1 && V_18 == 1 )
F_8 ( V_17 , V_21 ,
F_9 ( V_28 ) , 0 ) ;
}
static void F_13 ( struct V_16 * V_17 ,
bool V_32 , bool V_33 )
{
struct V_34 * V_35 = F_14 ( V_17 -> V_12 ) ;
unsigned int V_18 , V_19 , V_20 ;
F_15 ( V_17 -> V_12 , L_6 , V_36 ) ;
if ( V_32 )
F_8 ( V_17 , V_21 ,
F_9 ( V_37 ) , 0 ) ;
F_8 ( V_17 , V_21 ,
F_9 ( V_37 ) , F_9 ( V_37 ) ) ;
if ( V_32 )
for ( V_18 = 0 ; V_18 < V_38 ; V_18 ++ )
for ( V_19 = 0 ; V_19 < V_25 ; V_19 ++ ) {
V_20 = F_16 ( V_17 ,
V_35 -> V_39 [ V_19 ] ) ;
F_7 ( V_17 , V_18 , V_19 , V_20 ) ;
}
if ( V_33 )
for ( V_18 = 0 ; V_18 < V_38 ; V_18 ++ )
for ( V_19 = 0 ; V_19 < V_31 ; V_19 ++ ) {
V_20 = F_16 ( V_17 ,
V_35 -> V_40 [ V_19 ] ) ;
F_11 ( V_17 , V_18 , V_19 , V_20 ) ;
}
F_15 ( V_17 -> V_12 , L_7 , V_36 ) ;
}
static int F_17 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_16 * V_17 = F_18 ( V_42 ) ;
struct V_34 * V_35 = F_14 ( V_17 -> V_12 ) ;
F_19 ( & V_17 -> V_45 ) ;
V_44 -> V_10 . integer . V_10 [ 0 ] = V_35 -> V_46 ;
F_20 ( & V_17 -> V_45 ) ;
return 0 ;
}
static int F_21 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_16 * V_17 = F_18 ( V_42 ) ;
struct V_34 * V_35 = F_14 ( V_17 -> V_12 ) ;
unsigned int V_47 , V_48 , V_20 ;
int V_13 = 1 ;
F_15 ( V_17 -> V_12 , L_8 , V_36 ) ;
if ( V_44 -> V_10 . integer . V_10 [ 0 ] != V_49 ) {
F_22 ( V_17 -> V_12 ,
L_9 ,
V_36 , V_50 [ V_49 ] ) ;
return - V_51 ;
}
F_19 ( & V_17 -> V_45 ) ;
V_48 = F_16 ( V_17 , V_52 ) ;
if ( ( ( V_48 & F_9 ( V_53 ) ) != 0 ) ) {
if ( ( V_48 & F_9 ( V_54 ) ) == 0 ) {
F_22 ( V_17 -> V_12 , L_10 ,
V_36 ) ;
V_13 = - V_55 ;
} else {
V_13 = - V_56 ;
}
goto V_57;
}
F_10 ( V_17 , V_58 , 0 ) ;
for ( V_47 = 0 ; V_47 < V_59 ; V_47 ++ ) {
V_20 = F_16 ( V_17 , V_35 -> V_60 [ V_47 ] ) ;
F_10 ( V_17 , V_61 , V_20 >> 8 & 0xff ) ;
F_10 ( V_17 , V_62 , V_20 & 0xff ) ;
}
F_8 ( V_17 , V_58 ,
F_9 ( V_63 ) ,
F_9 ( V_63 ) ) ;
F_8 ( V_17 , V_58 ,
F_9 ( V_63 ) , 0 ) ;
V_35 -> V_46 = V_64 ;
V_57:
F_20 ( & V_17 -> V_45 ) ;
F_15 ( V_17 -> V_12 , L_11 , V_36 ) ;
return V_13 ;
}
static int F_23 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_16 * V_17 = F_18 ( V_42 ) ;
struct V_34 * V_35 = F_14 ( V_17 -> V_12 ) ;
F_19 ( & V_17 -> V_45 ) ;
V_44 -> V_10 . integer . V_10 [ 0 ] = V_35 -> V_65 ;
F_20 ( & V_17 -> V_45 ) ;
return 0 ;
}
static int F_24 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_16 * V_17 = F_18 ( V_42 ) ;
struct V_34 * V_35 = F_14 ( V_17 -> V_12 ) ;
struct V_11 * V_12 = V_17 -> V_12 ;
bool V_32 , V_33 ;
unsigned int V_66 ;
int V_13 ;
F_15 ( V_12 , L_6 , V_36 ) ;
F_19 ( & V_35 -> V_67 ) ;
V_66 = V_44 -> V_10 . integer . V_10 [ 0 ] ;
if ( V_66 >= F_25 ( V_68 ) ) {
V_13 = - V_69 ;
goto V_70;
}
if ( V_66 != V_71 && V_66 != V_72 &&
V_66 != V_73 ) {
F_22 ( V_12 , L_12 ,
V_36 , V_68 [ V_66 ] ) ;
V_13 = - V_69 ;
goto V_70;
}
V_32 = V_66 == V_72 || V_66 == V_71 ;
V_33 = V_66 == V_73 || V_66 == V_71 ;
V_13 = F_26 ( & V_17 -> V_74 ,
L_13 ) ;
if ( V_13 < 0 ) {
F_22 ( V_12 ,
L_14 ,
V_36 , V_13 ) ;
goto V_70;
}
F_27 ( & V_17 -> V_74 ) ;
F_19 ( & V_17 -> V_45 ) ;
F_13 ( V_17 , V_32 , V_33 ) ;
F_20 ( & V_17 -> V_45 ) ;
if ( V_32 ) {
if ( V_35 -> V_65 == V_75 )
V_35 -> V_65 = V_76 ;
else if ( V_35 -> V_65 != V_76 )
V_35 -> V_65 = V_77 ;
}
if ( V_33 ) {
if ( V_35 -> V_65 == V_77 )
V_35 -> V_65 = V_76 ;
else if ( V_35 -> V_65 != V_76 )
V_35 -> V_65 = V_75 ;
}
V_13 = F_28 ( & V_17 -> V_74 , L_13 ) ;
F_27 ( & V_17 -> V_74 ) ;
V_70:
F_20 ( & V_35 -> V_67 ) ;
if ( V_13 < 0 )
F_22 ( V_12 , L_15 ,
V_36 , V_13 ) ;
F_15 ( V_12 , L_7 , V_36 ) ;
return ( V_13 < 0 ) ? V_13 : 1 ;
}
static int F_29 ( struct V_41 * V_42 ,
struct V_78 * V_79 )
{
struct V_80 * V_81 =
(struct V_80 * ) V_42 -> V_82 ;
V_79 -> type = V_83 ;
V_79 -> V_84 = V_81 -> V_84 ;
V_79 -> V_10 . integer . V_85 = V_81 -> V_85 ;
V_79 -> V_10 . integer . V_86 = V_81 -> V_86 ;
return 0 ;
}
static int F_30 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_16 * V_17 = F_18 ( V_42 ) ;
struct V_80 * V_81 =
(struct V_80 * ) V_42 -> V_82 ;
unsigned int V_87 ;
F_19 ( & V_17 -> V_45 ) ;
for ( V_87 = 0 ; V_87 < V_81 -> V_84 ; V_87 ++ )
V_44 -> V_10 . integer . V_10 [ V_87 ] = V_81 -> V_10 [ V_87 ] ;
F_20 ( & V_17 -> V_45 ) ;
return 0 ;
}
static int F_31 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_16 * V_17 = F_18 ( V_42 ) ;
struct V_80 * V_81 =
(struct V_80 * ) V_42 -> V_82 ;
unsigned int V_87 ;
F_19 ( & V_17 -> V_45 ) ;
for ( V_87 = 0 ; V_87 < V_81 -> V_84 ; V_87 ++ )
V_81 -> V_10 [ V_87 ] = V_44 -> V_10 . integer . V_10 [ V_87 ] ;
F_20 ( & V_17 -> V_45 ) ;
return 0 ;
}
static int F_32 ( struct V_16 * V_17 )
{
int V_13 ;
F_15 ( V_17 -> V_12 , L_6 , V_36 ) ;
V_13 = F_33 ( V_88 ,
V_89 |
V_90 ,
V_90 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_34 ( struct V_16 * V_17 ,
struct V_91 * V_92 )
{
T_1 V_14 ;
unsigned int V_10 ;
int V_13 ;
const struct V_93 * V_94 ;
F_15 ( V_17 -> V_12 , L_6 , V_36 ) ;
V_13 = F_4 ( V_17 -> V_12 , V_95 ,
V_96 ,
& V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
V_10 = V_14 | V_97 | V_98 |
V_99 ;
V_13 = F_6 ( V_17 -> V_12 ,
V_95 ,
V_96 ,
V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
F_15 ( V_17 -> V_12 , L_16 , V_36 ,
F_1 ( V_92 -> V_100 ) ) ;
V_94 = & V_101 [ V_92 -> V_100 ] ;
V_13 = F_35 ( & V_17 -> V_74 , V_94 , 1 ) ;
F_15 ( V_17 -> V_12 , L_17 , V_36 ,
F_1 ( V_92 -> V_102 ) ) ;
V_94 = & V_103 [ V_92 -> V_102 ] ;
V_13 |= F_35 ( & V_17 -> V_74 , V_94 , 1 ) ;
F_15 ( V_17 -> V_12 , L_18 , V_36 ,
F_1 ( V_92 -> V_104 ) ) ;
V_94 = & V_105 [ V_92 -> V_104 ] ;
V_13 |= F_35 ( & V_17 -> V_74 , V_94 , 1 ) ;
if ( V_13 < 0 ) {
F_22 ( V_17 -> V_12 ,
L_19 ,
V_36 , V_13 ) ;
return V_13 ;
}
F_15 ( V_17 -> V_12 , L_20 , V_36 ,
F_2 ( V_92 -> V_106 ) ) ;
F_8 ( V_17 , V_107 , V_108 ,
V_92 -> V_106 == V_6 ?
0 : V_108 ) ;
F_15 ( V_17 -> V_12 , L_21 , V_36 ,
F_2 ( V_92 -> V_109 ) ) ;
F_8 ( V_17 , V_110 , V_108 ,
V_92 -> V_109 == V_6 ?
0 : V_108 ) ;
return 0 ;
}
static int F_36 ( struct V_16 * V_17 ,
enum V_111 V_112 )
{
char * V_113 ;
switch ( V_112 ) {
case V_114 :
V_113 = L_22 ;
break;
case V_115 :
V_113 = L_23 ;
break;
case V_116 :
V_113 = L_24 ;
break;
case V_117 :
V_113 = L_25 ;
break;
default:
F_22 ( V_17 -> V_12 ,
L_26 ,
V_36 , ( int ) V_112 ) ;
return - V_69 ;
}
F_15 ( V_17 -> V_12 , L_27 , V_36 ,
V_113 ) ;
F_8 ( V_17 , V_118 , V_119 ,
V_112 ) ;
return 0 ;
}
static int F_37 ( struct V_120 * V_121 ,
unsigned int V_122 )
{
unsigned int V_123 , V_20 ;
struct V_16 * V_17 = V_121 -> V_17 ;
V_123 = F_9 ( V_124 ) ;
V_20 = 0 ;
switch ( V_122 ) {
case 0 :
break;
case 1 :
V_20 |= F_9 ( V_124 ) ;
break;
default:
F_22 ( V_121 -> V_17 -> V_12 ,
L_28 ,
V_36 , V_122 ) ;
return - V_69 ;
}
F_15 ( V_121 -> V_17 -> V_12 , L_29 ,
V_36 , V_122 ) ;
F_8 ( V_17 , V_125 , V_123 , V_20 ) ;
return 0 ;
}
static int F_38 ( struct V_16 * V_17 ,
unsigned int V_126 )
{
unsigned int V_123 ;
unsigned int V_20 ;
V_123 = F_9 ( V_127 ) |
F_9 ( V_128 ) ;
V_20 = F_9 ( V_127 ) ;
switch ( V_126 & V_129 ) {
case V_130 :
F_15 ( V_17 -> V_12 , L_30 ,
V_36 ) ;
V_20 |= F_9 ( V_128 ) ;
break;
case V_131 :
F_15 ( V_17 -> V_12 , L_31 ,
V_36 ) ;
break;
default:
F_22 ( V_17 -> V_12 ,
L_32 ,
V_36 , V_126 & V_129 ) ;
return - V_69 ;
}
F_8 ( V_17 , V_132 , V_123 , V_20 ) ;
return 0 ;
}
static int F_39 ( struct V_120 * V_121 , unsigned int V_126 )
{
unsigned int V_123 ;
unsigned int V_20 ;
struct V_16 * V_17 = V_121 -> V_17 ;
int V_13 ;
F_15 ( V_17 -> V_12 , L_33 , V_36 , V_126 ) ;
V_123 = F_9 ( V_133 ) |
F_9 ( V_134 ) |
F_9 ( V_135 ) |
F_9 ( V_136 ) ;
V_20 = 0 ;
switch ( V_126 & V_137 ) {
case V_138 :
F_15 ( V_121 -> V_17 -> V_12 ,
L_34 , V_36 ) ;
V_20 |= F_9 ( V_136 ) ;
break;
case V_139 :
F_15 ( V_121 -> V_17 -> V_12 ,
L_35 , V_36 ) ;
break;
case V_140 :
case V_141 :
F_22 ( V_121 -> V_17 -> V_12 ,
L_36 ,
V_36 ) ;
default:
F_22 ( V_121 -> V_17 -> V_12 ,
L_37 ,
V_36 , V_126 & V_137 ) ;
return - V_69 ;
break;
}
F_8 ( V_17 , V_142 , V_123 , V_20 ) ;
V_13 = F_38 ( V_17 , V_126 ) ;
if ( V_13 ) {
F_22 ( V_121 -> V_17 -> V_12 ,
L_38 ,
V_36 , V_13 ) ;
return V_13 ;
}
V_123 = F_9 ( V_143 ) |
F_9 ( V_144 ) |
F_9 ( V_145 ) |
F_9 ( V_146 ) ;
V_20 = 0 ;
switch ( V_126 & V_147 ) {
case V_148 :
F_15 ( V_121 -> V_17 -> V_12 , L_39 , V_36 ) ;
V_20 |= F_9 ( V_144 ) ;
F_37 ( V_121 , 0 ) ;
break;
case V_149 :
F_15 ( V_121 -> V_17 -> V_12 ,
L_40 , V_36 ) ;
V_20 |= F_9 ( V_143 ) ;
F_37 ( V_121 , 1 ) ;
break;
case V_150 :
F_15 ( V_121 -> V_17 -> V_12 ,
L_41 , V_36 ) ;
V_20 |= F_9 ( V_143 ) ;
F_37 ( V_121 , 0 ) ;
break;
default:
F_22 ( V_121 -> V_17 -> V_12 ,
L_42 ,
V_36 , V_126 & V_147 ) ;
return - V_69 ;
}
switch ( V_126 & V_151 ) {
case V_152 :
F_15 ( V_121 -> V_17 -> V_12 ,
L_43 ,
V_36 ) ;
break;
case V_153 :
F_15 ( V_121 -> V_17 -> V_12 ,
L_44 ,
V_36 ) ;
V_20 |= F_9 ( V_145 ) ;
break;
case V_154 :
F_15 ( V_121 -> V_17 -> V_12 ,
L_45 ,
V_36 ) ;
V_20 |= F_9 ( V_146 ) ;
break;
case V_155 :
F_15 ( V_121 -> V_17 -> V_12 ,
L_46 ,
V_36 ) ;
V_20 |= F_9 ( V_145 ) ;
V_20 |= F_9 ( V_146 ) ;
break;
default:
F_22 ( V_121 -> V_17 -> V_12 ,
L_47 ,
V_36 , V_126 & V_151 ) ;
return - V_69 ;
}
F_8 ( V_17 , V_125 , V_123 , V_20 ) ;
return 0 ;
}
static int F_40 ( struct V_120 * V_121 ,
unsigned int V_156 , unsigned int V_157 ,
int V_158 , int V_159 )
{
struct V_16 * V_17 = V_121 -> V_17 ;
unsigned int V_20 , V_123 , V_160 , V_161 ;
V_123 = F_9 ( V_162 ) |
F_9 ( V_163 ) ;
V_20 = 0 ;
switch ( V_159 ) {
case 16 :
break;
case 20 :
V_20 |= F_9 ( V_162 ) ;
break;
case 24 :
V_20 |= F_9 ( V_163 ) ;
break;
case 32 :
V_20 |= F_9 ( V_163 ) |
F_9 ( V_162 ) ;
break;
default:
F_22 ( V_121 -> V_17 -> V_12 , L_48 ,
V_36 , V_159 ) ;
return - V_69 ;
}
F_15 ( V_121 -> V_17 -> V_12 , L_49 ,
V_36 , V_159 ) ;
F_8 ( V_17 , V_125 , V_123 , V_20 ) ;
F_15 ( V_121 -> V_17 -> V_12 , L_50 , V_36 , V_158 ) ;
V_123 = F_9 ( V_164 ) |
F_9 ( V_165 ) ;
switch ( V_158 ) {
case 2 :
V_20 = V_166 ;
break;
case 4 :
V_20 = F_9 ( V_164 ) ;
break;
case 8 :
V_20 = F_9 ( V_165 ) ;
break;
case 16 :
V_20 = F_9 ( V_164 ) |
F_9 ( V_165 ) ;
break;
default:
F_22 ( V_121 -> V_17 -> V_12 ,
L_51 ,
V_36 , V_158 ) ;
return - V_69 ;
}
F_8 ( V_17 , V_132 , V_123 , V_20 ) ;
if ( V_156 & ~ 0xff )
return - V_69 ;
V_123 = V_167 ;
V_156 = V_156 << V_168 ;
V_161 = F_41 ( V_156 ) ;
F_15 ( V_121 -> V_17 -> V_12 , L_52 , V_36 ,
V_161 ) ;
switch ( V_161 ) {
case 0 :
break;
case 1 :
V_160 = F_42 ( V_156 ) ;
F_8 ( V_17 , V_169 , V_123 , V_160 ) ;
F_8 ( V_17 , V_170 , V_123 , V_160 ) ;
F_8 ( V_17 , V_171 , V_123 , V_160 ) ;
F_8 ( V_17 , V_172 , V_123 , V_160 ) ;
break;
case 2 :
V_160 = F_42 ( V_156 ) ;
F_8 ( V_17 , V_169 , V_123 , V_160 ) ;
F_8 ( V_17 , V_170 , V_123 , V_160 ) ;
V_160 = F_43 ( V_156 ) ;
F_8 ( V_17 , V_171 , V_123 , V_160 ) ;
F_8 ( V_17 , V_172 , V_123 , V_160 ) ;
break;
case 8 :
F_15 ( V_121 -> V_17 -> V_12 ,
L_53 ,
V_36 ) ;
break;
default:
F_22 ( V_121 -> V_17 -> V_12 ,
L_54 ,
V_36 , V_161 ) ;
return - V_69 ;
}
if ( V_157 & ~ 0xff )
return - V_69 ;
V_157 = V_157 << V_173 ;
V_161 = F_41 ( V_157 ) ;
F_15 ( V_121 -> V_17 -> V_12 , L_55 , V_36 ,
V_161 ) ;
switch ( V_161 ) {
case 0 :
break;
case 1 :
V_160 = F_42 ( V_157 ) ;
F_8 ( V_17 , F_44 ( V_160 ) ,
F_45 ( V_160 ) ,
F_46 ( V_174 , V_160 ) ) ;
break;
case 2 :
V_160 = F_42 ( V_157 ) ;
F_8 ( V_17 ,
F_44 ( V_160 ) ,
F_45 ( V_160 ) ,
F_46 ( V_174 , V_160 ) ) ;
V_160 = F_43 ( V_157 ) ;
F_8 ( V_17 ,
F_44 ( V_160 ) ,
F_45 ( V_160 ) ,
F_46 ( V_175 , V_160 ) ) ;
break;
case 8 :
F_15 ( V_121 -> V_17 -> V_12 ,
L_56 ,
V_36 ) ;
break;
default:
F_22 ( V_121 -> V_17 -> V_12 ,
L_57 ,
V_36 , V_161 ) ;
return - V_69 ;
}
return 0 ;
}
static void F_47 ( struct V_11 * V_12 , struct V_176 * V_177 ,
struct V_178 * V_17 )
{
T_2 V_10 ;
if ( F_48 ( V_177 , L_58 , NULL ) )
V_17 -> V_92 . V_106 = V_7 ;
else
V_17 -> V_92 . V_106 = V_6 ;
if ( F_48 ( V_177 , L_59 , NULL ) )
V_17 -> V_92 . V_109 = V_7 ;
else
V_17 -> V_92 . V_109 = V_6 ;
if ( F_48 ( V_177 , L_60 , NULL ) )
V_17 -> V_92 . V_100 = V_4 ;
else
V_17 -> V_92 . V_100 = V_3 ;
if ( F_48 ( V_177 , L_61 , NULL ) )
V_17 -> V_92 . V_102 = V_4 ;
else
V_17 -> V_92 . V_102 = V_3 ;
if ( F_48 ( V_177 , L_62 , NULL ) )
V_17 -> V_92 . V_104 = V_3 ;
else
V_17 -> V_92 . V_104 = V_4 ;
if ( ! F_49 ( V_177 , L_63 , & V_10 ) ) {
switch ( V_10 ) {
case 950 :
V_17 -> V_112 = V_114 ;
break;
case 1100 :
V_17 -> V_112 = V_115 ;
break;
case 1270 :
V_17 -> V_112 = V_116 ;
break;
case 1580 :
V_17 -> V_112 = V_117 ;
break;
default :
V_17 -> V_112 = V_179 ;
F_22 ( V_12 , L_64 ) ;
}
} else {
F_50 ( V_12 , L_65 ) ;
V_17 -> V_112 = V_114 ;
}
}
static int F_51 ( struct V_16 * V_17 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_176 * V_177 = V_12 -> V_180 ;
struct V_34 * V_35 = F_14 ( V_12 ) ;
struct V_181 * V_182 ;
struct V_80 * V_81 ;
int V_13 ;
F_15 ( V_12 , L_6 , V_36 ) ;
V_182 = F_52 ( V_12 -> V_183 ) ;
if ( V_177 ) {
if ( ! V_182 )
V_182 = F_53 ( V_12 ,
sizeof( struct V_181 ) ,
V_184 ) ;
if ( V_182 && ! V_182 -> V_17 )
V_182 -> V_17
= F_53 ( V_12 ,
sizeof( struct V_178 ) ,
V_184 ) ;
if ( ! ( V_182 && V_182 -> V_17 ) )
return - V_185 ;
F_47 ( V_12 , V_177 , V_182 -> V_17 ) ;
} else {
if ( ! ( V_182 && V_182 -> V_17 ) ) {
F_22 ( V_12 , L_66 ) ;
return - V_69 ;
}
}
V_13 = F_34 ( V_17 , & V_182 -> V_17 -> V_92 ) ;
if ( V_13 < 0 ) {
F_54 ( L_67 , V_36 , V_13 ) ;
return V_13 ;
}
V_13 = F_36 ( V_17 , V_182 -> V_17 -> V_112 ) ;
if ( V_13 < 0 ) {
F_54 ( L_68 ,
V_36 , V_13 ) ;
return V_13 ;
}
V_13 = F_32 ( V_17 ) ;
if ( V_13 < 0 ) {
F_22 ( V_12 , L_69 ,
V_36 , V_13 ) ;
return V_13 ;
}
F_10 ( V_17 , V_186 ,
F_9 ( V_187 ) ) ;
F_10 ( V_17 , V_188 ,
F_9 ( V_189 ) ) ;
V_13 = F_55 ( V_17 , V_190 ,
F_25 ( V_190 ) ) ;
if ( V_13 < 0 ) {
F_22 ( V_12 ,
L_70 ,
V_36 , V_13 ) ;
return V_13 ;
}
V_81 = (struct V_80 * )
& V_190 [ V_191 ] . V_82 ;
V_35 -> V_39 = ( long * ) V_81 -> V_10 ;
V_81 = (struct V_80 * )
& V_190 [ V_192 ] . V_82 ;
V_35 -> V_40 = ( long * ) V_81 -> V_10 ;
V_81 = (struct V_80 * )
& V_190 [ V_193 ] . V_82 ;
V_35 -> V_60 = ( long * ) V_81 -> V_10 ;
( void ) F_28 ( & V_17 -> V_74 , L_13 ) ;
F_56 ( & V_35 -> V_67 ) ;
return V_13 ;
}
static int F_57 ( struct V_194 * V_195 )
{
int V_13 ;
struct V_34 * V_35 ;
F_15 ( & V_195 -> V_12 , L_6 , V_36 ) ;
V_35 = F_53 ( & V_195 -> V_12 , sizeof( struct V_34 ) ,
V_184 ) ;
if ( ! V_35 )
return - V_185 ;
V_35 -> V_46 = V_196 ;
V_35 -> V_65 = V_197 ;
F_58 ( & V_195 -> V_12 , V_35 ) ;
V_35 -> V_198 = F_59 ( & V_195 -> V_12 , NULL , & V_195 -> V_12 ,
& V_199 ) ;
if ( F_60 ( V_35 -> V_198 ) ) {
V_13 = F_61 ( V_35 -> V_198 ) ;
F_22 ( & V_195 -> V_12 , L_71 ,
V_36 , V_13 ) ;
return V_13 ;
}
F_15 ( & V_195 -> V_12 , L_72 , V_36 ) ;
V_13 = F_62 ( & V_195 -> V_12 , & V_200 ,
V_201 ,
F_25 ( V_201 ) ) ;
if ( V_13 < 0 )
F_22 ( & V_195 -> V_12 ,
L_73 ,
V_36 , V_13 ) ;
return V_13 ;
}
static int F_63 ( struct V_194 * V_195 )
{
F_15 ( & V_195 -> V_12 , L_74 , V_36 ) ;
F_64 ( & V_195 -> V_12 ) ;
return 0 ;
}
