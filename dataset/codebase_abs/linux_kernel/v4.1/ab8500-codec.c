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
F_19 ( & V_35 -> V_45 ) ;
V_44 -> V_10 . integer . V_10 [ 0 ] = V_35 -> V_46 ;
F_20 ( & V_35 -> V_45 ) ;
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
F_19 ( & V_35 -> V_45 ) ;
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
F_20 ( & V_35 -> V_45 ) ;
F_15 ( V_17 -> V_12 , L_11 , V_36 ) ;
return V_13 ;
}
static int F_23 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_16 * V_17 = F_18 ( V_42 ) ;
struct V_34 * V_35 = F_14 ( V_17 -> V_12 ) ;
F_19 ( & V_35 -> V_45 ) ;
V_44 -> V_10 . integer . V_10 [ 0 ] = V_35 -> V_65 ;
F_20 ( & V_35 -> V_45 ) ;
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
F_19 ( & V_35 -> V_45 ) ;
V_66 = V_44 -> V_10 . integer . V_10 [ 0 ] ;
if ( V_66 >= F_25 ( V_67 ) ) {
V_13 = - V_68 ;
goto V_69;
}
if ( V_66 != V_70 && V_66 != V_71 &&
V_66 != V_72 ) {
F_22 ( V_12 , L_12 ,
V_36 , V_67 [ V_66 ] ) ;
V_13 = - V_68 ;
goto V_69;
}
V_32 = V_66 == V_71 || V_66 == V_70 ;
V_33 = V_66 == V_72 || V_66 == V_70 ;
V_13 = F_26 ( & V_17 -> V_73 ,
L_13 ) ;
if ( V_13 < 0 ) {
F_22 ( V_12 ,
L_14 ,
V_36 , V_13 ) ;
goto V_69;
}
F_27 ( & V_17 -> V_73 ) ;
F_13 ( V_17 , V_32 , V_33 ) ;
if ( V_32 ) {
if ( V_35 -> V_65 == V_74 )
V_35 -> V_65 = V_75 ;
else if ( V_35 -> V_65 != V_75 )
V_35 -> V_65 = V_76 ;
}
if ( V_33 ) {
if ( V_35 -> V_65 == V_76 )
V_35 -> V_65 = V_75 ;
else if ( V_35 -> V_65 != V_75 )
V_35 -> V_65 = V_74 ;
}
V_13 = F_28 ( & V_17 -> V_73 , L_13 ) ;
F_27 ( & V_17 -> V_73 ) ;
V_69:
F_20 ( & V_35 -> V_45 ) ;
if ( V_13 < 0 )
F_22 ( V_12 , L_15 ,
V_36 , V_13 ) ;
F_15 ( V_12 , L_7 , V_36 ) ;
return ( V_13 < 0 ) ? V_13 : 1 ;
}
static int F_29 ( struct V_41 * V_42 ,
struct V_77 * V_78 )
{
struct V_79 * V_80 =
(struct V_79 * ) V_42 -> V_81 ;
V_78 -> type = V_82 ;
V_78 -> V_83 = V_80 -> V_83 ;
V_78 -> V_10 . integer . V_84 = V_80 -> V_84 ;
V_78 -> V_10 . integer . V_85 = V_80 -> V_85 ;
return 0 ;
}
static int F_30 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_16 * V_17 = F_18 ( V_42 ) ;
struct V_34 * V_35 = F_31 ( V_17 ) ;
struct V_79 * V_80 =
(struct V_79 * ) V_42 -> V_81 ;
unsigned int V_86 ;
F_19 ( & V_35 -> V_45 ) ;
for ( V_86 = 0 ; V_86 < V_80 -> V_83 ; V_86 ++ )
V_44 -> V_10 . integer . V_10 [ V_86 ] = V_80 -> V_10 [ V_86 ] ;
F_20 ( & V_35 -> V_45 ) ;
return 0 ;
}
static int F_32 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_16 * V_17 = F_18 ( V_42 ) ;
struct V_34 * V_35 = F_31 ( V_17 ) ;
struct V_79 * V_80 =
(struct V_79 * ) V_42 -> V_81 ;
unsigned int V_86 ;
F_19 ( & V_35 -> V_45 ) ;
for ( V_86 = 0 ; V_86 < V_80 -> V_83 ; V_86 ++ )
V_80 -> V_10 [ V_86 ] = V_44 -> V_10 . integer . V_10 [ V_86 ] ;
F_20 ( & V_35 -> V_45 ) ;
return 0 ;
}
static int F_33 ( struct V_16 * V_17 )
{
int V_13 ;
F_15 ( V_17 -> V_12 , L_6 , V_36 ) ;
V_13 = F_34 ( V_87 ,
V_88 |
V_89 ,
V_89 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_35 ( struct V_16 * V_17 ,
struct V_90 * V_91 )
{
T_1 V_14 ;
unsigned int V_10 ;
int V_13 ;
const struct V_92 * V_93 ;
F_15 ( V_17 -> V_12 , L_6 , V_36 ) ;
V_13 = F_4 ( V_17 -> V_12 , V_94 ,
V_95 ,
& V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
V_10 = V_14 | V_96 | V_97 |
V_98 ;
V_13 = F_6 ( V_17 -> V_12 ,
V_94 ,
V_95 ,
V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
F_15 ( V_17 -> V_12 , L_16 , V_36 ,
F_1 ( V_91 -> V_99 ) ) ;
V_93 = & V_100 [ V_91 -> V_99 ] ;
V_13 = F_36 ( & V_17 -> V_73 , V_93 , 1 ) ;
F_15 ( V_17 -> V_12 , L_17 , V_36 ,
F_1 ( V_91 -> V_101 ) ) ;
V_93 = & V_102 [ V_91 -> V_101 ] ;
V_13 |= F_36 ( & V_17 -> V_73 , V_93 , 1 ) ;
F_15 ( V_17 -> V_12 , L_18 , V_36 ,
F_1 ( V_91 -> V_103 ) ) ;
V_93 = & V_104 [ V_91 -> V_103 ] ;
V_13 |= F_36 ( & V_17 -> V_73 , V_93 , 1 ) ;
if ( V_13 < 0 ) {
F_22 ( V_17 -> V_12 ,
L_19 ,
V_36 , V_13 ) ;
return V_13 ;
}
F_15 ( V_17 -> V_12 , L_20 , V_36 ,
F_2 ( V_91 -> V_105 ) ) ;
F_8 ( V_17 , V_106 , V_107 ,
V_91 -> V_105 == V_6 ?
0 : V_107 ) ;
F_15 ( V_17 -> V_12 , L_21 , V_36 ,
F_2 ( V_91 -> V_108 ) ) ;
F_8 ( V_17 , V_109 , V_107 ,
V_91 -> V_108 == V_6 ?
0 : V_107 ) ;
return 0 ;
}
static int F_37 ( struct V_16 * V_17 ,
enum V_110 V_111 )
{
char * V_112 ;
switch ( V_111 ) {
case V_113 :
V_112 = L_22 ;
break;
case V_114 :
V_112 = L_23 ;
break;
case V_115 :
V_112 = L_24 ;
break;
case V_116 :
V_112 = L_25 ;
break;
default:
F_22 ( V_17 -> V_12 ,
L_26 ,
V_36 , ( int ) V_111 ) ;
return - V_68 ;
}
F_15 ( V_17 -> V_12 , L_27 , V_36 ,
V_112 ) ;
F_8 ( V_17 , V_117 , V_118 ,
V_111 ) ;
return 0 ;
}
static int F_38 ( struct V_119 * V_120 ,
unsigned int V_121 )
{
unsigned int V_122 , V_20 ;
struct V_16 * V_17 = V_120 -> V_17 ;
V_122 = F_9 ( V_123 ) ;
V_20 = 0 ;
switch ( V_121 ) {
case 0 :
break;
case 1 :
V_20 |= F_9 ( V_123 ) ;
break;
default:
F_22 ( V_120 -> V_17 -> V_12 ,
L_28 ,
V_36 , V_121 ) ;
return - V_68 ;
}
F_15 ( V_120 -> V_17 -> V_12 , L_29 ,
V_36 , V_121 ) ;
F_8 ( V_17 , V_124 , V_122 , V_20 ) ;
return 0 ;
}
static int F_39 ( struct V_16 * V_17 ,
unsigned int V_125 )
{
unsigned int V_122 ;
unsigned int V_20 ;
V_122 = F_9 ( V_126 ) |
F_9 ( V_127 ) ;
V_20 = F_9 ( V_126 ) ;
switch ( V_125 & V_128 ) {
case V_129 :
F_15 ( V_17 -> V_12 , L_30 ,
V_36 ) ;
V_20 |= F_9 ( V_127 ) ;
break;
case V_130 :
F_15 ( V_17 -> V_12 , L_31 ,
V_36 ) ;
break;
default:
F_22 ( V_17 -> V_12 ,
L_32 ,
V_36 , V_125 & V_128 ) ;
return - V_68 ;
}
F_8 ( V_17 , V_131 , V_122 , V_20 ) ;
return 0 ;
}
static int F_40 ( struct V_119 * V_120 , unsigned int V_125 )
{
unsigned int V_122 ;
unsigned int V_20 ;
struct V_16 * V_17 = V_120 -> V_17 ;
int V_13 ;
F_15 ( V_17 -> V_12 , L_33 , V_36 , V_125 ) ;
V_122 = F_9 ( V_132 ) |
F_9 ( V_133 ) |
F_9 ( V_134 ) |
F_9 ( V_135 ) ;
V_20 = 0 ;
switch ( V_125 & V_136 ) {
case V_137 :
F_15 ( V_120 -> V_17 -> V_12 ,
L_34 , V_36 ) ;
V_20 |= F_9 ( V_135 ) ;
break;
case V_138 :
F_15 ( V_120 -> V_17 -> V_12 ,
L_35 , V_36 ) ;
break;
case V_139 :
case V_140 :
F_22 ( V_120 -> V_17 -> V_12 ,
L_36 ,
V_36 ) ;
default:
F_22 ( V_120 -> V_17 -> V_12 ,
L_37 ,
V_36 , V_125 & V_136 ) ;
return - V_68 ;
break;
}
F_8 ( V_17 , V_141 , V_122 , V_20 ) ;
V_13 = F_39 ( V_17 , V_125 ) ;
if ( V_13 ) {
F_22 ( V_120 -> V_17 -> V_12 ,
L_38 ,
V_36 , V_13 ) ;
return V_13 ;
}
V_122 = F_9 ( V_142 ) |
F_9 ( V_143 ) |
F_9 ( V_144 ) |
F_9 ( V_145 ) ;
V_20 = 0 ;
switch ( V_125 & V_146 ) {
case V_147 :
F_15 ( V_120 -> V_17 -> V_12 , L_39 , V_36 ) ;
V_20 |= F_9 ( V_143 ) ;
F_38 ( V_120 , 0 ) ;
break;
case V_148 :
F_15 ( V_120 -> V_17 -> V_12 ,
L_40 , V_36 ) ;
V_20 |= F_9 ( V_142 ) ;
F_38 ( V_120 , 1 ) ;
break;
case V_149 :
F_15 ( V_120 -> V_17 -> V_12 ,
L_41 , V_36 ) ;
V_20 |= F_9 ( V_142 ) ;
F_38 ( V_120 , 0 ) ;
break;
default:
F_22 ( V_120 -> V_17 -> V_12 ,
L_42 ,
V_36 , V_125 & V_146 ) ;
return - V_68 ;
}
switch ( V_125 & V_150 ) {
case V_151 :
F_15 ( V_120 -> V_17 -> V_12 ,
L_43 ,
V_36 ) ;
break;
case V_152 :
F_15 ( V_120 -> V_17 -> V_12 ,
L_44 ,
V_36 ) ;
V_20 |= F_9 ( V_144 ) ;
break;
case V_153 :
F_15 ( V_120 -> V_17 -> V_12 ,
L_45 ,
V_36 ) ;
V_20 |= F_9 ( V_145 ) ;
break;
case V_154 :
F_15 ( V_120 -> V_17 -> V_12 ,
L_46 ,
V_36 ) ;
V_20 |= F_9 ( V_144 ) ;
V_20 |= F_9 ( V_145 ) ;
break;
default:
F_22 ( V_120 -> V_17 -> V_12 ,
L_47 ,
V_36 , V_125 & V_150 ) ;
return - V_68 ;
}
F_8 ( V_17 , V_124 , V_122 , V_20 ) ;
return 0 ;
}
static int F_41 ( struct V_119 * V_120 ,
unsigned int V_155 , unsigned int V_156 ,
int V_157 , int V_158 )
{
struct V_16 * V_17 = V_120 -> V_17 ;
unsigned int V_20 , V_122 , V_159 , V_160 ;
V_122 = F_9 ( V_161 ) |
F_9 ( V_162 ) ;
V_20 = 0 ;
switch ( V_158 ) {
case 16 :
break;
case 20 :
V_20 |= F_9 ( V_161 ) ;
break;
case 24 :
V_20 |= F_9 ( V_162 ) ;
break;
case 32 :
V_20 |= F_9 ( V_162 ) |
F_9 ( V_161 ) ;
break;
default:
F_22 ( V_120 -> V_17 -> V_12 , L_48 ,
V_36 , V_158 ) ;
return - V_68 ;
}
F_15 ( V_120 -> V_17 -> V_12 , L_49 ,
V_36 , V_158 ) ;
F_8 ( V_17 , V_124 , V_122 , V_20 ) ;
F_15 ( V_120 -> V_17 -> V_12 , L_50 , V_36 , V_157 ) ;
V_122 = F_9 ( V_163 ) |
F_9 ( V_164 ) ;
switch ( V_157 ) {
case 2 :
V_20 = V_165 ;
break;
case 4 :
V_20 = F_9 ( V_163 ) ;
break;
case 8 :
V_20 = F_9 ( V_164 ) ;
break;
case 16 :
V_20 = F_9 ( V_163 ) |
F_9 ( V_164 ) ;
break;
default:
F_22 ( V_120 -> V_17 -> V_12 ,
L_51 ,
V_36 , V_157 ) ;
return - V_68 ;
}
F_8 ( V_17 , V_131 , V_122 , V_20 ) ;
if ( V_155 & ~ 0xff )
return - V_68 ;
V_122 = V_166 ;
V_155 = V_155 << V_167 ;
V_160 = F_42 ( V_155 ) ;
F_15 ( V_120 -> V_17 -> V_12 , L_52 , V_36 ,
V_160 ) ;
switch ( V_160 ) {
case 0 :
break;
case 1 :
V_159 = F_43 ( V_155 ) ;
F_8 ( V_17 , V_168 , V_122 , V_159 ) ;
F_8 ( V_17 , V_169 , V_122 , V_159 ) ;
F_8 ( V_17 , V_170 , V_122 , V_159 ) ;
F_8 ( V_17 , V_171 , V_122 , V_159 ) ;
break;
case 2 :
V_159 = F_43 ( V_155 ) ;
F_8 ( V_17 , V_168 , V_122 , V_159 ) ;
F_8 ( V_17 , V_169 , V_122 , V_159 ) ;
V_159 = F_44 ( V_155 ) ;
F_8 ( V_17 , V_170 , V_122 , V_159 ) ;
F_8 ( V_17 , V_171 , V_122 , V_159 ) ;
break;
case 8 :
F_15 ( V_120 -> V_17 -> V_12 ,
L_53 ,
V_36 ) ;
break;
default:
F_22 ( V_120 -> V_17 -> V_12 ,
L_54 ,
V_36 , V_160 ) ;
return - V_68 ;
}
if ( V_156 & ~ 0xff )
return - V_68 ;
V_156 = V_156 << V_172 ;
V_160 = F_42 ( V_156 ) ;
F_15 ( V_120 -> V_17 -> V_12 , L_55 , V_36 ,
V_160 ) ;
switch ( V_160 ) {
case 0 :
break;
case 1 :
V_159 = F_43 ( V_156 ) ;
F_8 ( V_17 , F_45 ( V_159 ) ,
F_46 ( V_159 ) ,
F_47 ( V_173 , V_159 ) ) ;
break;
case 2 :
V_159 = F_43 ( V_156 ) ;
F_8 ( V_17 ,
F_45 ( V_159 ) ,
F_46 ( V_159 ) ,
F_47 ( V_173 , V_159 ) ) ;
V_159 = F_44 ( V_156 ) ;
F_8 ( V_17 ,
F_45 ( V_159 ) ,
F_46 ( V_159 ) ,
F_47 ( V_174 , V_159 ) ) ;
break;
case 8 :
F_15 ( V_120 -> V_17 -> V_12 ,
L_56 ,
V_36 ) ;
break;
default:
F_22 ( V_120 -> V_17 -> V_12 ,
L_57 ,
V_36 , V_160 ) ;
return - V_68 ;
}
return 0 ;
}
static void F_48 ( struct V_11 * V_12 , struct V_175 * V_176 ,
struct V_177 * V_17 )
{
T_2 V_10 ;
if ( F_49 ( V_176 , L_58 , NULL ) )
V_17 -> V_91 . V_105 = V_7 ;
else
V_17 -> V_91 . V_105 = V_6 ;
if ( F_49 ( V_176 , L_59 , NULL ) )
V_17 -> V_91 . V_108 = V_7 ;
else
V_17 -> V_91 . V_108 = V_6 ;
if ( F_49 ( V_176 , L_60 , NULL ) )
V_17 -> V_91 . V_99 = V_4 ;
else
V_17 -> V_91 . V_99 = V_3 ;
if ( F_49 ( V_176 , L_61 , NULL ) )
V_17 -> V_91 . V_101 = V_4 ;
else
V_17 -> V_91 . V_101 = V_3 ;
if ( F_49 ( V_176 , L_62 , NULL ) )
V_17 -> V_91 . V_103 = V_3 ;
else
V_17 -> V_91 . V_103 = V_4 ;
if ( ! F_50 ( V_176 , L_63 , & V_10 ) ) {
switch ( V_10 ) {
case 950 :
V_17 -> V_111 = V_113 ;
break;
case 1100 :
V_17 -> V_111 = V_114 ;
break;
case 1270 :
V_17 -> V_111 = V_115 ;
break;
case 1580 :
V_17 -> V_111 = V_116 ;
break;
default :
V_17 -> V_111 = V_178 ;
F_22 ( V_12 , L_64 ) ;
}
} else {
F_51 ( V_12 , L_65 ) ;
V_17 -> V_111 = V_113 ;
}
}
static int F_52 ( struct V_16 * V_17 )
{
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_175 * V_176 = V_12 -> V_179 ;
struct V_34 * V_35 = F_14 ( V_12 ) ;
struct V_180 * V_181 ;
struct V_79 * V_80 ;
int V_13 ;
F_15 ( V_12 , L_6 , V_36 ) ;
V_181 = F_53 ( V_12 -> V_182 ) ;
if ( V_176 ) {
if ( ! V_181 )
V_181 = F_54 ( V_12 ,
sizeof( struct V_180 ) ,
V_183 ) ;
if ( V_181 && ! V_181 -> V_17 )
V_181 -> V_17
= F_54 ( V_12 ,
sizeof( struct V_177 ) ,
V_183 ) ;
if ( ! ( V_181 && V_181 -> V_17 ) )
return - V_184 ;
F_48 ( V_12 , V_176 , V_181 -> V_17 ) ;
} else {
if ( ! ( V_181 && V_181 -> V_17 ) ) {
F_22 ( V_12 , L_66 ) ;
return - V_68 ;
}
}
V_13 = F_35 ( V_17 , & V_181 -> V_17 -> V_91 ) ;
if ( V_13 < 0 ) {
F_55 ( L_67 , V_36 , V_13 ) ;
return V_13 ;
}
V_13 = F_37 ( V_17 , V_181 -> V_17 -> V_111 ) ;
if ( V_13 < 0 ) {
F_55 ( L_68 ,
V_36 , V_13 ) ;
return V_13 ;
}
V_13 = F_33 ( V_17 ) ;
if ( V_13 < 0 ) {
F_22 ( V_12 , L_69 ,
V_36 , V_13 ) ;
return V_13 ;
}
F_10 ( V_17 , V_185 ,
F_9 ( V_186 ) ) ;
F_10 ( V_17 , V_187 ,
F_9 ( V_188 ) ) ;
V_13 = F_56 ( V_17 , V_189 ,
F_25 ( V_189 ) ) ;
if ( V_13 < 0 ) {
F_22 ( V_12 ,
L_70 ,
V_36 , V_13 ) ;
return V_13 ;
}
V_80 = (struct V_79 * )
& V_189 [ V_190 ] . V_81 ;
V_35 -> V_39 = ( long * ) V_80 -> V_10 ;
V_80 = (struct V_79 * )
& V_189 [ V_191 ] . V_81 ;
V_35 -> V_40 = ( long * ) V_80 -> V_10 ;
V_80 = (struct V_79 * )
& V_189 [ V_192 ] . V_81 ;
V_35 -> V_60 = ( long * ) V_80 -> V_10 ;
( void ) F_28 ( & V_17 -> V_73 , L_13 ) ;
F_57 ( & V_35 -> V_45 ) ;
return V_13 ;
}
static int F_58 ( struct V_193 * V_194 )
{
int V_13 ;
struct V_34 * V_35 ;
F_15 ( & V_194 -> V_12 , L_6 , V_36 ) ;
V_35 = F_54 ( & V_194 -> V_12 , sizeof( struct V_34 ) ,
V_183 ) ;
if ( ! V_35 )
return - V_184 ;
V_35 -> V_46 = V_195 ;
V_35 -> V_65 = V_196 ;
F_59 ( & V_194 -> V_12 , V_35 ) ;
V_35 -> V_197 = F_60 ( & V_194 -> V_12 , NULL , & V_194 -> V_12 ,
& V_198 ) ;
if ( F_61 ( V_35 -> V_197 ) ) {
V_13 = F_62 ( V_35 -> V_197 ) ;
F_22 ( & V_194 -> V_12 , L_71 ,
V_36 , V_13 ) ;
return V_13 ;
}
F_15 ( & V_194 -> V_12 , L_72 , V_36 ) ;
V_13 = F_63 ( & V_194 -> V_12 , & V_199 ,
V_200 ,
F_25 ( V_200 ) ) ;
if ( V_13 < 0 )
F_22 ( & V_194 -> V_12 ,
L_73 ,
V_36 , V_13 ) ;
return V_13 ;
}
static int F_64 ( struct V_193 * V_194 )
{
F_15 ( & V_194 -> V_12 , L_74 , V_36 ) ;
F_65 ( & V_194 -> V_12 ) ;
return 0 ;
}
