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
V_44 -> V_10 . V_46 . V_47 [ 0 ] = V_35 -> V_48 ;
F_20 ( & V_35 -> V_45 ) ;
return 0 ;
}
static int F_21 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_16 * V_17 = F_18 ( V_42 ) ;
struct V_34 * V_35 = F_14 ( V_17 -> V_12 ) ;
unsigned int V_49 , V_50 , V_20 ;
int V_13 = 1 ;
F_15 ( V_17 -> V_12 , L_8 , V_36 ) ;
if ( V_44 -> V_10 . V_46 . V_47 [ 0 ] != V_51 ) {
F_22 ( V_17 -> V_12 ,
L_9 ,
V_36 , V_52 [ V_51 ] ) ;
return - V_53 ;
}
F_19 ( & V_35 -> V_45 ) ;
V_50 = F_16 ( V_17 , V_54 ) ;
if ( ( ( V_50 & F_9 ( V_55 ) ) != 0 ) ) {
if ( ( V_50 & F_9 ( V_56 ) ) == 0 ) {
F_22 ( V_17 -> V_12 , L_10 ,
V_36 ) ;
V_13 = - V_57 ;
} else {
V_13 = - V_58 ;
}
goto V_59;
}
F_10 ( V_17 , V_60 , 0 ) ;
for ( V_49 = 0 ; V_49 < V_61 ; V_49 ++ ) {
V_20 = F_16 ( V_17 , V_35 -> V_62 [ V_49 ] ) ;
F_10 ( V_17 , V_63 , V_20 >> 8 & 0xff ) ;
F_10 ( V_17 , V_64 , V_20 & 0xff ) ;
}
F_8 ( V_17 , V_60 ,
F_9 ( V_65 ) ,
F_9 ( V_65 ) ) ;
F_8 ( V_17 , V_60 ,
F_9 ( V_65 ) , 0 ) ;
V_35 -> V_48 = V_66 ;
V_59:
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
V_44 -> V_10 . V_46 . V_47 [ 0 ] = V_35 -> V_67 ;
F_20 ( & V_35 -> V_45 ) ;
return 0 ;
}
static int F_24 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_16 * V_17 = F_18 ( V_42 ) ;
struct V_68 * V_69 = F_25 ( V_17 ) ;
struct V_34 * V_35 = F_14 ( V_17 -> V_12 ) ;
struct V_11 * V_12 = V_17 -> V_12 ;
bool V_32 , V_33 ;
unsigned int V_70 ;
int V_13 ;
F_15 ( V_12 , L_6 , V_36 ) ;
F_19 ( & V_35 -> V_45 ) ;
V_70 = V_44 -> V_10 . V_46 . V_47 [ 0 ] ;
if ( V_70 >= F_26 ( V_71 ) ) {
V_13 = - V_72 ;
goto V_73;
}
if ( V_70 != V_74 && V_70 != V_75 &&
V_70 != V_76 ) {
F_22 ( V_12 , L_12 ,
V_36 , V_71 [ V_70 ] ) ;
V_13 = - V_72 ;
goto V_73;
}
V_32 = V_70 == V_75 || V_70 == V_74 ;
V_33 = V_70 == V_76 || V_70 == V_74 ;
V_13 = F_27 ( V_69 , L_13 ) ;
if ( V_13 < 0 ) {
F_22 ( V_12 ,
L_14 ,
V_36 , V_13 ) ;
goto V_73;
}
F_28 ( V_69 ) ;
F_13 ( V_17 , V_32 , V_33 ) ;
if ( V_32 ) {
if ( V_35 -> V_67 == V_77 )
V_35 -> V_67 = V_78 ;
else if ( V_35 -> V_67 != V_78 )
V_35 -> V_67 = V_79 ;
}
if ( V_33 ) {
if ( V_35 -> V_67 == V_79 )
V_35 -> V_67 = V_78 ;
else if ( V_35 -> V_67 != V_78 )
V_35 -> V_67 = V_77 ;
}
V_13 = F_29 ( V_69 , L_13 ) ;
F_28 ( V_69 ) ;
V_73:
F_20 ( & V_35 -> V_45 ) ;
if ( V_13 < 0 )
F_22 ( V_12 , L_15 ,
V_36 , V_13 ) ;
F_15 ( V_12 , L_7 , V_36 ) ;
return ( V_13 < 0 ) ? V_13 : 1 ;
}
static int F_30 ( struct V_41 * V_42 ,
struct V_80 * V_81 )
{
struct V_82 * V_83 =
(struct V_82 * ) V_42 -> V_84 ;
V_81 -> type = V_85 ;
V_81 -> V_86 = V_83 -> V_86 ;
V_81 -> V_10 . integer . V_87 = V_83 -> V_87 ;
V_81 -> V_10 . integer . V_88 = V_83 -> V_88 ;
return 0 ;
}
static int F_31 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_16 * V_17 = F_18 ( V_42 ) ;
struct V_34 * V_35 = F_32 ( V_17 ) ;
struct V_82 * V_83 =
(struct V_82 * ) V_42 -> V_84 ;
unsigned int V_89 ;
F_19 ( & V_35 -> V_45 ) ;
for ( V_89 = 0 ; V_89 < V_83 -> V_86 ; V_89 ++ )
V_44 -> V_10 . integer . V_10 [ V_89 ] = V_83 -> V_10 [ V_89 ] ;
F_20 ( & V_35 -> V_45 ) ;
return 0 ;
}
static int F_33 ( struct V_41 * V_42 ,
struct V_43 * V_44 )
{
struct V_16 * V_17 = F_18 ( V_42 ) ;
struct V_34 * V_35 = F_32 ( V_17 ) ;
struct V_82 * V_83 =
(struct V_82 * ) V_42 -> V_84 ;
unsigned int V_89 ;
F_19 ( & V_35 -> V_45 ) ;
for ( V_89 = 0 ; V_89 < V_83 -> V_86 ; V_89 ++ )
V_83 -> V_10 [ V_89 ] = V_44 -> V_10 . integer . V_10 [ V_89 ] ;
F_20 ( & V_35 -> V_45 ) ;
return 0 ;
}
static int F_34 ( struct V_16 * V_17 )
{
int V_13 ;
F_15 ( V_17 -> V_12 , L_6 , V_36 ) ;
V_13 = F_35 ( V_90 ,
V_91 |
V_92 ,
V_92 ) ;
if ( V_13 < 0 )
return V_13 ;
return 0 ;
}
static int F_36 ( struct V_16 * V_17 ,
struct V_93 * V_94 )
{
struct V_68 * V_69 = F_25 ( V_17 ) ;
T_1 V_14 ;
unsigned int V_10 ;
int V_13 ;
const struct V_95 * V_96 ;
F_15 ( V_17 -> V_12 , L_6 , V_36 ) ;
V_13 = F_4 ( V_17 -> V_12 , V_97 ,
V_98 ,
& V_14 ) ;
if ( V_13 < 0 )
return V_13 ;
V_10 = V_14 | V_99 | V_100 |
V_101 ;
V_13 = F_6 ( V_17 -> V_12 ,
V_97 ,
V_98 ,
V_10 ) ;
if ( V_13 < 0 )
return V_13 ;
F_15 ( V_17 -> V_12 , L_16 , V_36 ,
F_1 ( V_94 -> V_102 ) ) ;
V_96 = & V_103 [ V_94 -> V_102 ] ;
V_13 = F_37 ( V_69 , V_96 , 1 ) ;
F_15 ( V_17 -> V_12 , L_17 , V_36 ,
F_1 ( V_94 -> V_104 ) ) ;
V_96 = & V_105 [ V_94 -> V_104 ] ;
V_13 |= F_37 ( V_69 , V_96 , 1 ) ;
F_15 ( V_17 -> V_12 , L_18 , V_36 ,
F_1 ( V_94 -> V_106 ) ) ;
V_96 = & V_107 [ V_94 -> V_106 ] ;
V_13 |= F_37 ( V_69 , V_96 , 1 ) ;
if ( V_13 < 0 ) {
F_22 ( V_17 -> V_12 ,
L_19 ,
V_36 , V_13 ) ;
return V_13 ;
}
F_15 ( V_17 -> V_12 , L_20 , V_36 ,
F_2 ( V_94 -> V_108 ) ) ;
F_8 ( V_17 , V_109 , V_110 ,
V_94 -> V_108 == V_6 ?
0 : V_110 ) ;
F_15 ( V_17 -> V_12 , L_21 , V_36 ,
F_2 ( V_94 -> V_111 ) ) ;
F_8 ( V_17 , V_112 , V_110 ,
V_94 -> V_111 == V_6 ?
0 : V_110 ) ;
return 0 ;
}
static int F_38 ( struct V_16 * V_17 ,
enum V_113 V_114 )
{
char * V_115 ;
switch ( V_114 ) {
case V_116 :
V_115 = L_22 ;
break;
case V_117 :
V_115 = L_23 ;
break;
case V_118 :
V_115 = L_24 ;
break;
case V_119 :
V_115 = L_25 ;
break;
default:
F_22 ( V_17 -> V_12 ,
L_26 ,
V_36 , ( int ) V_114 ) ;
return - V_72 ;
}
F_15 ( V_17 -> V_12 , L_27 , V_36 ,
V_115 ) ;
F_8 ( V_17 , V_120 , V_121 ,
V_114 ) ;
return 0 ;
}
static int F_39 ( struct V_122 * V_123 ,
unsigned int V_124 )
{
unsigned int V_125 , V_20 ;
struct V_16 * V_17 = V_123 -> V_17 ;
V_125 = F_9 ( V_126 ) ;
V_20 = 0 ;
switch ( V_124 ) {
case 0 :
break;
case 1 :
V_20 |= F_9 ( V_126 ) ;
break;
default:
F_22 ( V_123 -> V_17 -> V_12 ,
L_28 ,
V_36 , V_124 ) ;
return - V_72 ;
}
F_15 ( V_123 -> V_17 -> V_12 , L_29 ,
V_36 , V_124 ) ;
F_8 ( V_17 , V_127 , V_125 , V_20 ) ;
return 0 ;
}
static int F_40 ( struct V_16 * V_17 ,
unsigned int V_128 )
{
unsigned int V_125 ;
unsigned int V_20 ;
V_125 = F_9 ( V_129 ) |
F_9 ( V_130 ) ;
V_20 = F_9 ( V_129 ) ;
switch ( V_128 & V_131 ) {
case V_132 :
F_15 ( V_17 -> V_12 , L_30 ,
V_36 ) ;
V_20 |= F_9 ( V_130 ) ;
break;
case V_133 :
F_15 ( V_17 -> V_12 , L_31 ,
V_36 ) ;
break;
default:
F_22 ( V_17 -> V_12 ,
L_32 ,
V_36 , V_128 & V_131 ) ;
return - V_72 ;
}
F_8 ( V_17 , V_134 , V_125 , V_20 ) ;
return 0 ;
}
static int F_41 ( struct V_122 * V_123 , unsigned int V_128 )
{
unsigned int V_125 ;
unsigned int V_20 ;
struct V_16 * V_17 = V_123 -> V_17 ;
int V_13 ;
F_15 ( V_17 -> V_12 , L_33 , V_36 , V_128 ) ;
V_125 = F_9 ( V_135 ) |
F_9 ( V_136 ) |
F_9 ( V_137 ) |
F_9 ( V_138 ) ;
V_20 = 0 ;
switch ( V_128 & V_139 ) {
case V_140 :
F_15 ( V_123 -> V_17 -> V_12 ,
L_34 , V_36 ) ;
V_20 |= F_9 ( V_138 ) ;
break;
case V_141 :
F_15 ( V_123 -> V_17 -> V_12 ,
L_35 , V_36 ) ;
break;
case V_142 :
case V_143 :
F_22 ( V_123 -> V_17 -> V_12 ,
L_36 ,
V_36 ) ;
default:
F_22 ( V_123 -> V_17 -> V_12 ,
L_37 ,
V_36 , V_128 & V_139 ) ;
return - V_72 ;
}
F_8 ( V_17 , V_144 , V_125 , V_20 ) ;
V_13 = F_40 ( V_17 , V_128 ) ;
if ( V_13 ) {
F_22 ( V_123 -> V_17 -> V_12 ,
L_38 ,
V_36 , V_13 ) ;
return V_13 ;
}
V_125 = F_9 ( V_145 ) |
F_9 ( V_146 ) |
F_9 ( V_147 ) |
F_9 ( V_148 ) ;
V_20 = 0 ;
switch ( V_128 & V_149 ) {
case V_150 :
F_15 ( V_123 -> V_17 -> V_12 , L_39 , V_36 ) ;
V_20 |= F_9 ( V_146 ) ;
F_39 ( V_123 , 0 ) ;
break;
case V_151 :
F_15 ( V_123 -> V_17 -> V_12 ,
L_40 , V_36 ) ;
V_20 |= F_9 ( V_145 ) ;
F_39 ( V_123 , 1 ) ;
break;
case V_152 :
F_15 ( V_123 -> V_17 -> V_12 ,
L_41 , V_36 ) ;
V_20 |= F_9 ( V_145 ) ;
F_39 ( V_123 , 0 ) ;
break;
default:
F_22 ( V_123 -> V_17 -> V_12 ,
L_42 ,
V_36 , V_128 & V_149 ) ;
return - V_72 ;
}
switch ( V_128 & V_153 ) {
case V_154 :
F_15 ( V_123 -> V_17 -> V_12 ,
L_43 ,
V_36 ) ;
break;
case V_155 :
F_15 ( V_123 -> V_17 -> V_12 ,
L_44 ,
V_36 ) ;
V_20 |= F_9 ( V_147 ) ;
break;
case V_156 :
F_15 ( V_123 -> V_17 -> V_12 ,
L_45 ,
V_36 ) ;
V_20 |= F_9 ( V_148 ) ;
break;
case V_157 :
F_15 ( V_123 -> V_17 -> V_12 ,
L_46 ,
V_36 ) ;
V_20 |= F_9 ( V_147 ) ;
V_20 |= F_9 ( V_148 ) ;
break;
default:
F_22 ( V_123 -> V_17 -> V_12 ,
L_47 ,
V_36 , V_128 & V_153 ) ;
return - V_72 ;
}
F_8 ( V_17 , V_127 , V_125 , V_20 ) ;
return 0 ;
}
static int F_42 ( struct V_122 * V_123 ,
unsigned int V_158 , unsigned int V_159 ,
int V_160 , int V_161 )
{
struct V_16 * V_17 = V_123 -> V_17 ;
unsigned int V_20 , V_125 , V_162 , V_163 ;
V_125 = F_9 ( V_164 ) |
F_9 ( V_165 ) ;
V_20 = 0 ;
switch ( V_161 ) {
case 16 :
break;
case 20 :
V_20 |= F_9 ( V_164 ) ;
break;
case 24 :
V_20 |= F_9 ( V_165 ) ;
break;
case 32 :
V_20 |= F_9 ( V_165 ) |
F_9 ( V_164 ) ;
break;
default:
F_22 ( V_123 -> V_17 -> V_12 , L_48 ,
V_36 , V_161 ) ;
return - V_72 ;
}
F_15 ( V_123 -> V_17 -> V_12 , L_49 ,
V_36 , V_161 ) ;
F_8 ( V_17 , V_127 , V_125 , V_20 ) ;
F_15 ( V_123 -> V_17 -> V_12 , L_50 , V_36 , V_160 ) ;
V_125 = F_9 ( V_166 ) |
F_9 ( V_167 ) ;
switch ( V_160 ) {
case 2 :
V_20 = V_168 ;
break;
case 4 :
V_20 = F_9 ( V_166 ) ;
break;
case 8 :
V_20 = F_9 ( V_167 ) ;
break;
case 16 :
V_20 = F_9 ( V_166 ) |
F_9 ( V_167 ) ;
break;
default:
F_22 ( V_123 -> V_17 -> V_12 ,
L_51 ,
V_36 , V_160 ) ;
return - V_72 ;
}
F_8 ( V_17 , V_134 , V_125 , V_20 ) ;
if ( V_158 & ~ 0xff )
return - V_72 ;
V_125 = V_169 ;
V_158 = V_158 << V_170 ;
V_163 = F_43 ( V_158 ) ;
F_15 ( V_123 -> V_17 -> V_12 , L_52 , V_36 ,
V_163 ) ;
switch ( V_163 ) {
case 0 :
break;
case 1 :
V_162 = F_44 ( V_158 ) ;
F_8 ( V_17 , V_171 , V_125 , V_162 ) ;
F_8 ( V_17 , V_172 , V_125 , V_162 ) ;
F_8 ( V_17 , V_173 , V_125 , V_162 ) ;
F_8 ( V_17 , V_174 , V_125 , V_162 ) ;
break;
case 2 :
V_162 = F_44 ( V_158 ) ;
F_8 ( V_17 , V_171 , V_125 , V_162 ) ;
F_8 ( V_17 , V_172 , V_125 , V_162 ) ;
V_162 = F_45 ( V_158 ) ;
F_8 ( V_17 , V_173 , V_125 , V_162 ) ;
F_8 ( V_17 , V_174 , V_125 , V_162 ) ;
break;
case 8 :
F_15 ( V_123 -> V_17 -> V_12 ,
L_53 ,
V_36 ) ;
break;
default:
F_22 ( V_123 -> V_17 -> V_12 ,
L_54 ,
V_36 , V_163 ) ;
return - V_72 ;
}
if ( V_159 & ~ 0xff )
return - V_72 ;
V_159 = V_159 << V_175 ;
V_163 = F_43 ( V_159 ) ;
F_15 ( V_123 -> V_17 -> V_12 , L_55 , V_36 ,
V_163 ) ;
switch ( V_163 ) {
case 0 :
break;
case 1 :
V_162 = F_44 ( V_159 ) ;
F_8 ( V_17 , F_46 ( V_162 ) ,
F_47 ( V_162 ) ,
F_48 ( V_176 , V_162 ) ) ;
break;
case 2 :
V_162 = F_44 ( V_159 ) ;
F_8 ( V_17 ,
F_46 ( V_162 ) ,
F_47 ( V_162 ) ,
F_48 ( V_176 , V_162 ) ) ;
V_162 = F_45 ( V_159 ) ;
F_8 ( V_17 ,
F_46 ( V_162 ) ,
F_47 ( V_162 ) ,
F_48 ( V_177 , V_162 ) ) ;
break;
case 8 :
F_15 ( V_123 -> V_17 -> V_12 ,
L_56 ,
V_36 ) ;
break;
default:
F_22 ( V_123 -> V_17 -> V_12 ,
L_57 ,
V_36 , V_163 ) ;
return - V_72 ;
}
return 0 ;
}
static void F_49 ( struct V_11 * V_12 , struct V_178 * V_179 ,
struct V_180 * V_17 )
{
T_2 V_10 ;
if ( F_50 ( V_179 , L_58 , NULL ) )
V_17 -> V_94 . V_108 = V_7 ;
else
V_17 -> V_94 . V_108 = V_6 ;
if ( F_50 ( V_179 , L_59 , NULL ) )
V_17 -> V_94 . V_111 = V_7 ;
else
V_17 -> V_94 . V_111 = V_6 ;
if ( F_50 ( V_179 , L_60 , NULL ) )
V_17 -> V_94 . V_102 = V_4 ;
else
V_17 -> V_94 . V_102 = V_3 ;
if ( F_50 ( V_179 , L_61 , NULL ) )
V_17 -> V_94 . V_104 = V_4 ;
else
V_17 -> V_94 . V_104 = V_3 ;
if ( F_50 ( V_179 , L_62 , NULL ) )
V_17 -> V_94 . V_106 = V_3 ;
else
V_17 -> V_94 . V_106 = V_4 ;
if ( ! F_51 ( V_179 , L_63 , & V_10 ) ) {
switch ( V_10 ) {
case 950 :
V_17 -> V_114 = V_116 ;
break;
case 1100 :
V_17 -> V_114 = V_117 ;
break;
case 1270 :
V_17 -> V_114 = V_118 ;
break;
case 1580 :
V_17 -> V_114 = V_119 ;
break;
default :
V_17 -> V_114 = V_181 ;
F_22 ( V_12 , L_64 ) ;
}
} else {
F_52 ( V_12 , L_65 ) ;
V_17 -> V_114 = V_116 ;
}
}
static int F_53 ( struct V_16 * V_17 )
{
struct V_68 * V_69 = F_25 ( V_17 ) ;
struct V_11 * V_12 = V_17 -> V_12 ;
struct V_178 * V_179 = V_12 -> V_182 ;
struct V_34 * V_35 = F_14 ( V_12 ) ;
struct V_180 V_183 ;
struct V_82 * V_83 ;
int V_13 ;
F_15 ( V_12 , L_6 , V_36 ) ;
F_49 ( V_12 , V_179 , & V_183 ) ;
V_13 = F_36 ( V_17 , & V_183 . V_94 ) ;
if ( V_13 < 0 ) {
F_54 ( L_66 , V_36 , V_13 ) ;
return V_13 ;
}
V_13 = F_38 ( V_17 , V_183 . V_114 ) ;
if ( V_13 < 0 ) {
F_54 ( L_67 ,
V_36 , V_13 ) ;
return V_13 ;
}
V_13 = F_34 ( V_17 ) ;
if ( V_13 < 0 ) {
F_22 ( V_12 , L_68 ,
V_36 , V_13 ) ;
return V_13 ;
}
F_10 ( V_17 , V_184 ,
F_9 ( V_185 ) ) ;
F_10 ( V_17 , V_186 ,
F_9 ( V_187 ) ) ;
V_13 = F_55 ( V_17 , V_188 ,
F_26 ( V_188 ) ) ;
if ( V_13 < 0 ) {
F_22 ( V_12 ,
L_69 ,
V_36 , V_13 ) ;
return V_13 ;
}
V_83 = (struct V_82 * )
& V_188 [ V_189 ] . V_84 ;
V_35 -> V_39 = ( long * ) V_83 -> V_10 ;
V_83 = (struct V_82 * )
& V_188 [ V_190 ] . V_84 ;
V_35 -> V_40 = ( long * ) V_83 -> V_10 ;
V_83 = (struct V_82 * )
& V_188 [ V_191 ] . V_84 ;
V_35 -> V_62 = ( long * ) V_83 -> V_10 ;
F_29 ( V_69 , L_13 ) ;
F_56 ( & V_35 -> V_45 ) ;
return V_13 ;
}
static int F_57 ( struct V_192 * V_193 )
{
int V_13 ;
struct V_34 * V_35 ;
F_15 ( & V_193 -> V_12 , L_6 , V_36 ) ;
V_35 = F_58 ( & V_193 -> V_12 , sizeof( struct V_34 ) ,
V_194 ) ;
if ( ! V_35 )
return - V_195 ;
V_35 -> V_48 = V_196 ;
V_35 -> V_67 = V_197 ;
F_59 ( & V_193 -> V_12 , V_35 ) ;
V_35 -> V_198 = F_60 ( & V_193 -> V_12 , NULL , & V_193 -> V_12 ,
& V_199 ) ;
if ( F_61 ( V_35 -> V_198 ) ) {
V_13 = F_62 ( V_35 -> V_198 ) ;
F_22 ( & V_193 -> V_12 , L_70 ,
V_36 , V_13 ) ;
return V_13 ;
}
F_15 ( & V_193 -> V_12 , L_71 , V_36 ) ;
V_13 = F_63 ( & V_193 -> V_12 , & V_200 ,
V_201 ,
F_26 ( V_201 ) ) ;
if ( V_13 < 0 )
F_22 ( & V_193 -> V_12 ,
L_72 ,
V_36 , V_13 ) ;
return V_13 ;
}
static int F_64 ( struct V_192 * V_193 )
{
F_15 ( & V_193 -> V_12 , L_73 , V_36 ) ;
F_65 ( & V_193 -> V_12 ) ;
return 0 ;
}
