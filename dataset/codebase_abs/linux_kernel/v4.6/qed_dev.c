static T_1 F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
T_1 V_5 = ( V_4 == V_6 ?
V_7 : V_8 ) ;
T_1 V_9 = F_2 ( V_2 , V_2 -> V_10 , V_5 ) ;
if ( V_9 )
return 1 << ( V_9 + 15 ) ;
if ( V_2 -> V_11 -> V_12 > 1 ) {
F_3 ( V_2 ,
L_1 ) ;
return V_6 ? 256 * 1024 : 512 * 1024 ;
} else {
F_3 ( V_2 ,
L_2 ) ;
return 512 * 1024 ;
}
}
void F_4 ( struct V_13 * V_11 ,
T_1 V_14 , T_2 V_15 )
{
T_1 V_16 ;
V_11 -> V_15 = V_15 ;
V_11 -> V_14 = V_14 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_16 ] ;
V_2 -> V_15 = V_15 ;
V_2 -> V_14 = V_14 ;
}
}
void F_5 ( struct V_13 * V_11 )
{
T_2 V_16 ;
for ( V_16 = 0 ; V_16 < V_17 ; V_16 ++ ) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_16 ] ;
V_2 -> V_11 = V_11 ;
V_2 -> V_19 = V_16 ;
V_2 -> V_20 = false ;
F_6 ( & V_2 -> V_21 . V_22 ) ;
}
V_11 -> V_18 [ 0 ] . V_20 = true ;
V_11 -> V_23 = 7 ;
}
static void F_7 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = & V_2 -> V_25 ;
F_8 ( V_25 -> V_26 ) ;
V_25 -> V_26 = NULL ;
F_8 ( V_25 -> V_27 ) ;
V_25 -> V_27 = NULL ;
F_8 ( V_25 -> V_28 ) ;
V_25 -> V_28 = NULL ;
}
void F_9 ( struct V_13 * V_11 )
{
int V_16 ;
F_8 ( V_11 -> V_29 ) ;
V_11 -> V_29 = NULL ;
F_8 ( V_11 -> V_30 ) ;
F_10 (cdev, i) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_16 ] ;
F_8 ( V_2 -> V_31 ) ;
V_2 -> V_31 = NULL ;
F_8 ( V_2 -> V_32 ) ;
V_2 -> V_32 = NULL ;
}
F_10 (cdev, i) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_16 ] ;
F_11 ( V_2 ) ;
F_7 ( V_2 ) ;
F_12 ( V_2 ) ;
F_13 ( V_2 , V_2 -> V_33 ) ;
F_14 ( V_2 , V_2 -> V_34 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 ) ;
}
}
static int F_17 ( struct V_1 * V_2 )
{
struct V_24 * V_25 = & V_2 -> V_25 ;
struct V_35 * V_36 ;
T_2 V_37 , V_16 , V_38 , V_39 ;
T_3 V_40 , V_41 = 1 ;
memset ( V_25 , 0 , sizeof( * V_25 ) ) ;
V_40 = V_41 + 1 ;
V_37 = ( T_2 ) F_18 ( V_2 , V_42 ) ;
if ( V_40 > F_18 ( V_2 , V_43 ) ) {
F_19 ( V_2 ,
L_3 ,
V_40 , F_18 ( V_2 , V_43 ) ) ;
return - V_44 ;
}
V_25 -> V_26 = F_20 ( sizeof( * V_25 -> V_26 ) *
V_40 , V_45 ) ;
if ( ! V_25 -> V_26 )
goto V_46;
V_25 -> V_27 = F_20 ( sizeof( * V_25 -> V_27 ) *
V_37 , V_45 ) ;
if ( ! V_25 -> V_27 )
goto V_46;
V_25 -> V_28 = F_20 ( sizeof( * V_25 -> V_28 ) *
V_47 , V_45 ) ;
if ( ! V_25 -> V_28 )
goto V_46;
V_38 = ( T_2 ) F_21 ( V_2 , V_42 ) ;
for ( V_16 = 0 ; V_16 < V_41 ; V_16 ++ ) {
struct V_48 * V_49 = & V_25 -> V_26 [ V_16 ] ;
V_49 -> V_38 = V_38 ;
V_49 -> V_50 = V_2 -> V_51 . V_52 ;
V_49 -> V_53 = 1 ;
}
V_25 -> V_54 = V_16 ;
V_25 -> V_26 [ V_16 ] . V_38 = ( T_2 ) F_21 ( V_2 , V_42 ) ;
V_25 -> V_26 [ V_16 ] . V_50 = V_55 ;
V_25 -> V_26 [ V_16 ] . V_53 = 1 ;
V_16 ++ ;
V_25 -> V_56 = 0 ;
V_25 -> V_40 = V_40 ;
V_25 -> V_37 = V_37 ;
V_39 = V_2 -> V_11 -> V_57 ;
for ( V_16 = 0 ; V_16 < V_39 ; V_16 ++ ) {
V_36 = & V_25 -> V_28 [ V_16 ] ;
V_36 -> V_58 = 1 ;
V_36 -> V_59 = 4 ;
V_36 -> V_60 = V_61 / V_39 ;
V_36 -> V_62 = V_63 / V_39 ;
}
V_25 -> V_64 = V_65 ;
V_25 -> V_66 = ( T_3 ) F_21 ( V_2 , V_43 ) ;
V_25 -> V_67 = ( T_2 ) F_21 ( V_2 , V_42 ) ;
V_25 -> V_68 = 0 ;
V_25 -> V_69 = 0 ;
V_25 -> V_70 = 1 ;
return 0 ;
V_46:
F_22 ( V_2 , L_4 ) ;
F_8 ( V_25 -> V_26 ) ;
F_8 ( V_25 -> V_27 ) ;
F_8 ( V_25 -> V_28 ) ;
return - V_71 ;
}
int F_23 ( struct V_13 * V_11 )
{
struct V_72 * V_34 ;
struct V_73 * V_33 ;
int V_16 , V_74 = 0 ;
V_11 -> V_29 = F_20 ( sizeof( * V_11 -> V_29 ) , V_45 ) ;
if ( ! V_11 -> V_29 )
return - V_71 ;
F_10 (cdev, i) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_16 ] ;
int V_75 = sizeof( struct V_76 ) *
F_18 ( V_2 , V_77 ) ;
int V_78 = sizeof( struct V_76 ) *
F_18 ( V_2 , V_77 ) ;
V_2 -> V_31 = F_20 ( V_75 , V_45 ) ;
if ( ! V_2 -> V_31 ) {
F_22 ( V_2 ,
L_5 ) ;
V_74 = - V_71 ;
goto V_46;
}
V_2 -> V_32 = F_20 ( V_78 , V_45 ) ;
if ( ! V_2 -> V_32 ) {
F_22 ( V_2 ,
L_6 ) ;
V_74 = - V_71 ;
goto V_46;
}
}
F_10 (cdev, i) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_16 ] ;
V_74 = F_24 ( V_2 ) ;
if ( V_74 )
goto V_46;
V_74 = F_25 ( V_2 ) ;
if ( V_74 )
goto V_46;
V_74 = F_17 ( V_2 ) ;
if ( V_74 )
goto V_46;
V_74 = F_26 ( V_2 ) ;
if ( V_74 )
goto V_46;
V_74 = F_27 ( V_2 ) ;
if ( V_74 )
goto V_46;
V_74 = F_28 ( V_2 ) ;
if ( V_74 )
goto V_46;
V_2 -> V_79 = F_29 ( V_2 ,
V_80 ) ;
V_74 = F_30 ( V_2 , V_2 -> V_10 ) ;
if ( V_74 )
goto V_46;
V_33 = F_31 ( V_2 , 256 ) ;
if ( ! V_33 ) {
V_74 = - V_71 ;
goto V_46;
}
V_2 -> V_33 = V_33 ;
V_34 = F_32 ( V_2 ) ;
if ( ! V_34 ) {
V_74 = - V_71 ;
goto V_46;
}
V_2 -> V_34 = V_34 ;
V_74 = F_33 ( V_2 ) ;
if ( V_74 ) {
F_22 ( V_2 ,
L_7 ) ;
goto V_46;
}
}
V_11 -> V_30 = F_20 ( sizeof( * V_11 -> V_30 ) , V_45 ) ;
if ( ! V_11 -> V_30 ) {
F_22 ( V_11 , L_8 ) ;
V_74 = - V_71 ;
goto V_46;
}
return 0 ;
V_46:
F_9 ( V_11 ) ;
return V_74 ;
}
void F_34 ( struct V_13 * V_11 )
{
int V_16 ;
F_10 (cdev, i) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_16 ] ;
F_35 ( V_2 ) ;
F_36 ( V_2 ) ;
F_37 ( V_2 , V_2 -> V_33 ) ;
F_38 ( V_2 , V_2 -> V_34 ) ;
F_39 ( V_2 , V_2 -> V_10 ) ;
memcpy ( V_2 -> V_81 -> V_82 ,
V_2 -> V_81 -> V_83 ,
V_2 -> V_81 -> V_84 ) ;
F_40 ( V_2 , V_2 -> V_10 ) ;
}
}
int F_41 ( struct V_1 * V_2 ,
struct V_85 * V_86 ,
T_3 V_87 )
{
T_1 V_88 = 0 , V_89 , V_90 = V_91 ;
int V_74 = - V_92 ;
V_89 = V_93 +
F_42 ( V_2 -> V_94 ) ;
V_88 |= V_95 <<
V_96 ;
V_88 |= 1 << V_97 ;
V_88 |= V_87 << V_98 ;
V_88 |= V_99 << V_100 ;
if ( F_43 ( V_2 , V_89 ) ) {
F_22 (
V_2 ,
L_9 ) ;
F_44 ( V_2 , V_89 , 0 ) ;
}
F_45 ( V_2 , V_101 ,
L_10 ,
V_87 , V_88 ) ;
F_46 ( V_2 , V_86 , V_102 , V_88 ) ;
while ( ! F_43 ( V_2 , V_89 ) && V_90 -- )
F_47 ( V_103 ) ;
if ( F_43 ( V_2 , V_89 ) )
V_74 = 0 ;
else
F_22 ( V_2 ,
L_11 ) ;
F_44 ( V_2 , V_89 , 0 ) ;
return V_74 ;
}
static void F_48 ( struct V_1 * V_2 )
{
int V_104 = 0 ;
V_104 = ( 1 << V_105 ) ;
switch ( V_2 -> V_11 -> V_57 ) {
case 1 :
V_104 |= 1 << V_106 ;
break;
case 2 :
V_104 |= 1 << V_107 ;
break;
case 4 :
V_104 |= 1 << V_108 ;
break;
default:
F_22 ( V_2 , L_12 ,
V_2 -> V_11 -> V_57 ) ;
return;
}
switch ( V_2 -> V_11 -> V_109 ) {
case V_110 :
case V_111 :
V_104 |= 1 << V_112 ;
break;
case V_113 :
V_104 |= 1 << V_114 ;
break;
default:
F_22 ( V_2 , L_13 ) ;
V_104 |= 1 << V_112 ;
}
V_104 |= 1 << V_115 ;
V_2 -> V_51 . V_104 = V_104 ;
}
static void F_49 ( struct V_13 * V_11 )
{
T_1 V_116 = V_117 ;
int V_16 , V_118 ;
F_10 (cdev, i) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_16 ] ;
struct V_119 * V_120 ;
struct V_121 * V_122 ;
struct V_123 V_124 ;
V_120 = V_2 -> V_51 . V_120 ;
for ( V_118 = 0 ; V_118 < F_50 ( V_11 ) ;
V_118 ++ ) {
V_122 = & V_120 -> V_125 . V_126 [ V_118 ] ;
if ( ! V_122 -> V_127 )
continue;
F_51 ( V_2 , & V_124 ,
V_122 -> V_128 ,
0 , 0 ) ;
F_52 ( V_2 , V_116 + V_118 * 2 ,
V_124 ) ;
}
}
}
static int F_53 ( struct V_1 * V_2 ,
struct V_85 * V_86 ,
int V_104 )
{
struct V_24 * V_25 = & V_2 -> V_25 ;
struct V_129 V_49 ;
struct V_13 * V_11 = V_2 -> V_11 ;
int V_74 = 0 ;
F_49 ( V_11 ) ;
F_54 ( V_2 ) ;
if ( V_2 -> V_81 ) {
if ( V_2 -> V_81 -> V_130 . V_131 )
V_25 -> V_132 = 1 ;
if ( V_2 -> V_81 -> V_130 . V_133 )
V_25 -> V_134 = 1 ;
}
memset ( & V_49 , 0 , sizeof( V_49 ) ) ;
V_49 . V_135 = V_2 -> V_11 -> V_57 ;
V_49 . V_64 = V_25 -> V_64 ;
V_49 . V_132 = V_25 -> V_132 ;
V_49 . V_134 = V_25 -> V_134 ;
V_49 . V_70 = V_25 -> V_70 ;
V_49 . V_136 = V_25 -> V_136 ;
V_49 . V_137 = V_25 -> V_28 ;
F_55 ( V_2 , & V_49 ) ;
F_56 ( V_2 ) ;
F_46 ( V_2 , V_86 , V_138 , 0 ) ;
F_46 ( V_2 , V_86 , V_139 , 0 ) ;
F_57 ( V_2 , V_86 , V_2 -> V_140 ^ 1 ) ;
F_46 ( V_2 , V_86 , V_138 , 0 ) ;
F_46 ( V_2 , V_86 , V_139 , 0 ) ;
F_58 ( V_2 , V_86 ) ;
V_74 = F_59 ( V_2 , V_86 , V_141 , V_142 , V_104 ) ;
if ( V_74 != 0 )
return V_74 ;
F_46 ( V_2 , V_86 , V_143 , 0 ) ;
F_46 ( V_2 , V_86 , V_144 , 1 ) ;
F_46 ( V_2 , V_86 , 0x20b4 ,
F_2 ( V_2 , V_86 , 0x20b4 ) & ~ 0x10 ) ;
return V_74 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_85 * V_86 ,
int V_104 )
{
int V_74 = 0 ;
V_74 = F_59 ( V_2 , V_86 , V_145 , V_2 -> V_140 ,
V_104 ) ;
return V_74 ;
}
static int F_61 ( struct V_1 * V_2 ,
struct V_85 * V_86 ,
int V_104 ,
bool V_146 ,
enum V_147 V_148 ,
bool V_149 )
{
T_2 V_94 = V_2 -> V_94 ;
int V_74 = 0 ;
if ( V_2 -> V_81 ) {
struct V_150 * V_151 ;
V_151 = & V_2 -> V_81 -> V_130 ;
if ( V_151 -> V_133 )
V_2 -> V_25 . V_68 = V_151 -> V_133 ;
V_2 -> V_25 . V_69 = 100 ;
}
F_62 ( V_2 ) ;
F_63 ( V_2 ) ;
if ( V_104 & ( 1 << V_114 ) ) {
F_45 ( V_2 , V_152 , L_14 ) ;
F_64 ( V_2 , V_153 , 1 ) ;
F_64 ( V_2 , V_154 ,
V_2 -> V_51 . V_155 ) ;
}
if ( V_104 & ( 1 << V_112 ) ) {
F_45 ( V_2 , V_152 ,
L_15 ) ;
F_64 ( V_2 ,
V_156 , 1 ) ;
}
F_64 ( V_2 , V_157 , 0 ) ;
F_64 ( V_2 , V_158 , 0 ) ;
F_64 ( V_2 , V_159 , 0 ) ;
V_74 = F_41 ( V_2 , V_86 , V_94 ) ;
if ( V_74 != 0 )
return V_74 ;
V_74 = F_59 ( V_2 , V_86 , V_160 , V_94 , V_104 ) ;
if ( V_74 )
return V_74 ;
V_74 = F_59 ( V_2 , V_86 , V_161 , V_94 , V_104 ) ;
if ( V_74 )
return V_74 ;
F_65 ( V_2 , V_86 , true , true ) ;
if ( V_146 ) {
F_66 ( V_2 , V_86 , V_148 ) ;
V_74 = F_67 ( V_2 , V_2 -> V_11 -> V_109 ) ;
if ( V_74 )
F_22 ( V_2 , L_16 ) ;
}
return V_74 ;
}
static int F_68 ( struct V_1 * V_2 ,
struct V_85 * V_86 ,
T_2 V_162 )
{
T_1 V_163 = 0 , V_9 , V_164 = V_162 ? 1 : 0 ;
F_46 ( V_2 , V_86 ,
V_165 , V_164 ) ;
for ( V_163 = 0 ; V_163 < 20000 ; V_163 ++ ) {
V_9 = F_2 ( V_2 , V_86 ,
V_165 ) ;
if ( V_9 == V_164 )
break;
F_69 ( 50 , 60 ) ;
}
if ( V_9 != V_164 ) {
F_22 ( V_2 ,
L_17 ) ;
return - V_166 ;
}
return 0 ;
}
static void F_70 ( struct V_1 * V_2 ,
struct V_85 * V_10 )
{
F_39 ( V_2 , V_10 ) ;
memcpy ( V_2 -> V_81 -> V_82 ,
V_2 -> V_81 -> V_83 ,
V_2 -> V_81 -> V_84 ) ;
}
int F_71 ( struct V_13 * V_11 ,
bool V_146 ,
enum V_147 V_148 ,
bool V_149 ,
const T_2 * V_167 )
{
T_1 V_168 , V_169 ;
int V_74 , V_170 , V_16 ;
V_74 = F_72 ( V_11 , V_167 ) ;
if ( V_74 != 0 )
return V_74 ;
F_10 (cdev, i) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_16 ] ;
V_74 = F_68 ( V_2 , V_2 -> V_10 , true ) ;
F_48 ( V_2 ) ;
V_74 = F_73 ( V_2 , V_2 -> V_10 ,
& V_168 ) ;
if ( V_74 ) {
F_22 ( V_2 , L_18 ) ;
return V_74 ;
}
F_70 ( V_2 , V_2 -> V_10 ) ;
F_45 ( V_2 , V_171 ,
L_19 ,
V_74 , V_168 ) ;
V_2 -> V_172 = ( V_168 ==
V_173 ) ;
switch ( V_168 ) {
case V_173 :
V_74 = F_53 ( V_2 , V_2 -> V_10 ,
V_2 -> V_51 . V_104 ) ;
if ( V_74 )
break;
case V_174 :
V_74 = F_60 ( V_2 , V_2 -> V_10 ,
V_2 -> V_51 . V_104 ) ;
if ( V_74 )
break;
case V_175 :
V_74 = F_61 ( V_2 , V_2 -> V_10 ,
V_2 -> V_51 . V_104 ,
V_146 , V_148 ,
V_149 ) ;
break;
default:
V_74 = - V_44 ;
break;
}
if ( V_74 )
F_22 ( V_2 ,
L_20 ,
V_168 , V_74 ) ;
V_170 = F_74 ( V_2 , V_2 -> V_10 ,
V_176 ,
0 , & V_168 , & V_169 ) ;
if ( V_74 )
return V_74 ;
if ( V_170 ) {
F_22 ( V_2 , L_21 ) ;
return V_170 ;
}
V_2 -> V_177 = true ;
}
return 0 ;
}
static inline void F_75 ( struct V_13 * V_11 ,
struct V_1 * V_2 ,
struct V_85 * V_86 )
{
int V_16 ;
F_46 ( V_2 , V_86 , V_178 , 0x0 ) ;
F_46 ( V_2 , V_86 , V_179 , 0x0 ) ;
for ( V_16 = 0 ; V_16 < V_180 ; V_16 ++ ) {
if ( ( ! F_2 ( V_2 , V_86 ,
V_181 ) ) &&
( ! F_2 ( V_2 , V_86 ,
V_182 ) ) )
break;
F_69 ( 1000 , 2000 ) ;
}
if ( V_16 < V_180 )
return;
F_22 ( V_2 ,
L_22 ,
( T_2 ) F_2 ( V_2 , V_86 , V_181 ) ,
( T_2 ) F_2 ( V_2 , V_86 , V_182 ) ) ;
}
void F_76 ( struct V_13 * V_11 )
{
int V_183 ;
F_10 (cdev, j) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_183 ] ;
struct V_85 * V_86 = V_2 -> V_10 ;
F_75 ( V_11 , V_2 , V_86 ) ;
}
}
int F_77 ( struct V_13 * V_11 )
{
int V_74 = 0 , V_184 ;
int V_183 ;
F_10 (cdev, j) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_183 ] ;
struct V_85 * V_86 = V_2 -> V_10 ;
F_45 ( V_2 , V_185 , L_23 ) ;
V_2 -> V_177 = false ;
V_74 = F_78 ( V_2 ) ;
if ( V_74 )
F_22 ( V_2 ,
L_24 ) ;
F_46 ( V_2 , V_86 ,
V_186 , 0x1 ) ;
F_46 ( V_2 , V_86 , V_187 , 0x0 ) ;
F_46 ( V_2 , V_86 , V_188 , 0x0 ) ;
F_46 ( V_2 , V_86 , V_189 , 0x0 ) ;
F_46 ( V_2 , V_86 , V_190 , 0x0 ) ;
F_46 ( V_2 , V_86 , V_191 , 0x0 ) ;
F_75 ( V_11 , V_2 , V_86 ) ;
F_79 ( V_2 , V_86 ) ;
F_46 ( V_2 , V_86 , V_192 , 0 ) ;
F_46 ( V_2 , V_86 , V_193 , 0 ) ;
F_65 ( V_2 , V_86 , false , true ) ;
F_69 ( 1000 , 2000 ) ;
}
V_184 = F_68 ( & V_11 -> V_18 [ 0 ] ,
V_11 -> V_18 [ 0 ] . V_10 ,
false ) ;
if ( V_184 != 0 )
V_74 = V_184 ;
return V_74 ;
}
void F_80 ( struct V_13 * V_11 )
{
int V_183 ;
F_10 (cdev, j) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_183 ] ;
struct V_85 * V_86 = V_2 -> V_10 ;
F_45 ( V_2 ,
V_185 ,
L_25 ) ;
F_46 ( V_2 , V_86 ,
V_186 , 0x1 ) ;
F_46 ( V_2 , V_86 , V_187 , 0x0 ) ;
F_46 ( V_2 , V_86 , V_188 , 0x0 ) ;
F_46 ( V_2 , V_86 , V_189 , 0x0 ) ;
F_46 ( V_2 , V_86 , V_190 , 0x0 ) ;
F_46 ( V_2 , V_86 , V_191 , 0x0 ) ;
F_65 ( V_2 , V_86 , false , false ) ;
F_69 ( 1000 , 2000 ) ;
}
}
void F_81 ( struct V_1 * V_2 )
{
F_46 ( V_2 , V_2 -> V_10 ,
V_186 , 0x0 ) ;
}
static int F_82 ( struct V_1 * V_194 ,
struct V_85 * V_195 , T_1 V_196 ,
bool V_197 )
{
T_1 V_198 = F_2 ( V_194 , V_195 , V_196 ) ;
if ( V_198 != V_197 ) {
F_22 ( V_194 , L_26 ,
V_196 , V_197 ) ;
return - V_44 ;
}
return 0 ;
}
int F_83 ( struct V_13 * V_11 )
{
int V_74 = 0 ;
T_1 V_199 , V_200 ;
int V_16 ;
F_10 (cdev, i) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_16 ] ;
F_45 ( V_2 , V_185 , L_27 ) ;
F_82 ( V_2 , V_2 -> V_10 ,
V_201 , 0 ) ;
F_82 ( V_2 , V_2 -> V_10 ,
V_202 , 0 ) ;
F_46 ( V_2 , V_2 -> V_10 , V_203 , 0 ) ;
F_46 ( V_2 , V_2 -> V_10 , V_204 , 0 ) ;
F_46 ( V_2 , V_2 -> V_10 ,
V_205 , 0 ) ;
F_46 ( V_2 , V_2 -> V_10 ,
V_206 , 0 ) ;
V_74 = F_74 ( V_2 , V_2 -> V_10 ,
V_207 ,
V_208 ,
& V_199 , & V_200 ) ;
if ( V_74 ) {
F_22 ( V_2 , L_28 ) ;
V_199 = V_209 ;
}
V_74 = F_74 ( V_2 , V_2 -> V_10 ,
V_210 ,
0 , & V_199 , & V_200 ) ;
if ( V_74 ) {
F_22 ( V_2 , L_29 ) ;
return V_74 ;
}
}
return V_74 ;
}
static void F_84 ( struct V_1 * V_2 )
{
F_85 ( V_2 ) ;
F_8 ( V_2 -> V_51 . V_120 ) ;
}
static void F_86 ( struct V_1 * V_2 )
{
F_46 ( V_2 , V_2 -> V_10 , V_211 , 0 ) ;
F_46 ( V_2 , V_2 -> V_10 , V_212 , 0 ) ;
F_46 ( V_2 , V_2 -> V_10 , V_213 , 0 ) ;
F_46 ( V_2 , V_2 -> V_10 , V_214 , 0 ) ;
F_46 ( V_2 , V_2 -> V_10 ,
V_215 ,
1 << V_2 -> V_216 ) ;
F_46 ( V_2 , V_2 -> V_10 ,
V_217 , 1 ) ;
}
static void F_87 ( struct V_1 * V_2 )
{
V_2 -> V_51 . V_218 = ( T_3 ) F_43 ( V_2 , V_219 ) ;
V_2 -> V_51 . V_220 = F_43 ( V_2 , V_221 ) ;
V_2 -> V_216 = ( V_2 -> V_51 . V_220 >> 16 ) & 0xf ;
V_2 -> V_94 = F_88 ( V_2 -> V_51 . V_220 ,
V_222 ) ;
V_2 -> V_140 = F_88 ( V_2 -> V_51 . V_220 ,
V_223 ) ;
}
static void F_89 ( struct V_1 * V_2 )
{
T_1 * V_224 = V_2 -> V_51 . V_224 ;
int V_225 = 1 ;
V_224 [ V_226 ] = F_90 ( T_1 , F_18 ( V_2 , V_227 ) /
V_225 ,
F_18 ( V_2 , V_77 ) ) ;
F_45 ( V_2 , V_228 ,
L_30 ,
V_224 [ V_226 ] , F_18 ( V_2 , V_227 ) ,
V_225 ) ;
}
static void F_91 ( struct V_1 * V_2 )
{
T_1 * V_229 = V_2 -> V_51 . V_229 ;
T_1 * V_230 = V_2 -> V_51 . V_230 ;
struct V_231 V_232 ;
int V_233 , V_16 ;
V_233 = V_234 ;
memset ( & V_232 , 0 , sizeof( V_232 ) ) ;
F_92 ( V_2 , & V_232 ) ;
V_230 [ V_227 ] = F_90 ( T_1 ,
( V_235 / V_233 ) ,
V_232 . V_236 ) ;
V_230 [ V_77 ] = V_237 / V_233 ;
V_230 [ V_42 ] = V_238 / V_233 ;
V_230 [ V_239 ] = V_240 / V_233 ;
V_230 [ V_43 ] = V_241 / V_233 ;
V_230 [ V_242 ] = 8 ;
V_230 [ V_243 ] = V_244 / V_233 ;
V_230 [ V_245 ] = ( V_246 - 1 ) /
V_233 ;
V_230 [ V_247 ] = 950 ;
for ( V_16 = 0 ; V_16 < V_248 ; V_16 ++ )
V_229 [ V_16 ] = V_230 [ V_16 ] * V_2 -> V_94 ;
F_89 ( V_2 ) ;
F_45 ( V_2 , V_228 ,
L_31
L_32
L_33
L_34
L_35
L_36
L_37
L_38
L_39 ,
V_2 -> V_51 . V_230 [ V_227 ] ,
V_2 -> V_51 . V_229 [ V_227 ] ,
V_2 -> V_51 . V_230 [ V_77 ] ,
V_2 -> V_51 . V_229 [ V_77 ] ,
V_2 -> V_51 . V_230 [ V_42 ] ,
V_2 -> V_51 . V_229 [ V_42 ] ,
V_2 -> V_51 . V_230 [ V_43 ] ,
V_2 -> V_51 . V_229 [ V_43 ] ,
V_2 -> V_51 . V_230 [ V_242 ] ,
V_2 -> V_51 . V_229 [ V_242 ] ,
V_2 -> V_51 . V_230 [ V_243 ] ,
V_2 -> V_51 . V_229 [ V_243 ] ,
V_2 -> V_51 . V_230 [ V_245 ] ,
V_2 -> V_51 . V_229 [ V_245 ] ,
V_2 -> V_51 . V_230 [ V_247 ] ,
V_2 -> V_51 . V_229 [ V_247 ] ) ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_85 * V_86 )
{
T_1 V_249 , V_109 , V_89 , V_250 , V_251 ;
T_1 V_252 , V_253 , V_254 , V_255 ;
struct V_256 * V_257 ;
V_254 = F_2 ( V_2 , V_86 , V_258 ) ;
if ( ! V_254 ) {
F_22 ( V_2 , L_40 ) ;
return - V_44 ;
}
V_249 = F_2 ( V_2 , V_86 , V_254 + 4 ) ;
V_89 = V_259 + V_249 +
F_94 ( struct V_260 , V_261 ) +
F_94 ( struct V_262 , V_251 ) ;
V_251 = F_2 ( V_2 , V_86 , V_89 ) ;
switch ( ( V_251 & V_263 ) >>
V_264 ) {
case V_265 :
V_2 -> V_51 . V_266 = V_267 ;
break;
case V_268 :
V_2 -> V_51 . V_266 = V_269 ;
break;
case V_270 :
V_2 -> V_51 . V_266 = V_271 ;
break;
case V_272 :
V_2 -> V_51 . V_266 = V_273 ;
break;
case V_274 :
V_2 -> V_51 . V_266 = V_275 ;
break;
case V_276 :
V_2 -> V_51 . V_266 = V_277 ;
break;
case V_278 :
V_2 -> V_51 . V_266 = V_279 ;
break;
case V_280 :
V_2 -> V_51 . V_266 = V_281 ;
break;
case V_282 :
V_2 -> V_51 . V_266 = V_283 ;
break;
default:
F_22 ( V_2 , L_41 ,
V_251 ) ;
break;
}
V_257 = & V_2 -> V_81 -> V_284 ;
V_252 = V_259 + V_249 +
F_94 ( struct V_260 , V_285 [ F_95 ( V_2 ) ] ) ;
V_253 = F_2 ( V_2 , V_86 ,
V_252 +
F_94 ( struct V_286 , V_287 ) ) ;
V_257 -> V_288 . V_289 =
V_253 & V_290 ;
V_2 -> V_81 -> V_291 . V_292 =
V_257 -> V_288 . V_289 ;
V_253 = F_2 ( V_2 , V_86 ,
V_252 +
F_94 ( struct V_286 , V_293 ) ) ;
switch ( ( V_253 & V_294 ) >>
V_295 ) {
case V_296 :
V_257 -> V_288 . V_297 = true ;
break;
case V_298 :
V_257 -> V_288 . V_299 = 1000 ;
break;
case V_300 :
V_257 -> V_288 . V_299 = 10000 ;
break;
case V_301 :
V_257 -> V_288 . V_299 = 25000 ;
break;
case V_302 :
V_257 -> V_288 . V_299 = 40000 ;
break;
case V_303 :
V_257 -> V_288 . V_299 = 50000 ;
break;
case V_304 :
V_257 -> V_288 . V_299 = 100000 ;
break;
default:
F_22 ( V_2 , L_42 ,
V_253 ) ;
}
V_253 &= V_305 ;
V_253 >>= V_306 ;
V_257 -> V_307 . V_297 = ! ! ( V_253 &
V_308 ) ;
V_257 -> V_307 . V_309 = ! ! ( V_253 &
V_310 ) ;
V_257 -> V_307 . V_311 = ! ! ( V_253 &
V_312 ) ;
V_257 -> V_313 = 0 ;
F_45 ( V_2 , V_314 ,
L_43 ,
V_257 -> V_288 . V_299 , V_257 -> V_288 . V_289 ,
V_257 -> V_288 . V_297 , V_257 -> V_307 . V_297 ) ;
V_89 = V_259 + V_249 +
F_94 ( struct V_260 , V_261 ) +
F_94 ( struct V_262 , V_250 ) ;
V_250 = F_2 ( V_2 , V_86 , V_89 ) ;
V_109 = ( V_250 & V_315 ) >>
V_316 ;
switch ( V_109 ) {
case V_317 :
V_2 -> V_11 -> V_109 = V_113 ;
break;
case V_318 :
V_2 -> V_11 -> V_109 = V_111 ;
break;
case V_319 :
V_2 -> V_11 -> V_109 = V_110 ;
break;
}
F_3 ( V_2 , L_44 ,
V_2 -> V_11 -> V_109 ) ;
V_89 = V_259 + V_249 +
F_94 ( struct V_260 , V_261 ) +
F_94 ( struct V_262 , V_255 ) ;
V_255 = F_2 ( V_2 , V_86 , V_89 ) ;
if ( V_255 & V_320 )
F_96 ( V_321 ,
& V_2 -> V_51 . V_255 ) ;
return F_97 ( V_2 , V_86 ) ;
}
static int
F_98 ( struct V_1 * V_2 ,
struct V_85 * V_86 ,
enum V_322 V_323 )
{
T_1 V_266 ;
int V_74 ;
V_266 = F_2 ( V_2 , V_86 ,
V_324 ) ;
if ( V_266 < 3 ) {
V_2 -> V_11 -> V_57 = 1 ;
} else if ( V_266 <= 5 ) {
V_2 -> V_11 -> V_57 = 2 ;
} else {
F_22 ( V_2 , L_45 ,
V_2 -> V_11 -> V_57 ) ;
V_2 -> V_11 -> V_57 = 1 ;
}
F_93 ( V_2 , V_86 ) ;
V_74 = F_99 ( V_2 , V_86 ) ;
if ( V_74 )
return V_74 ;
if ( F_100 ( V_2 ) )
F_101 ( V_2 -> V_51 . V_325 ,
V_2 -> V_81 -> V_130 . V_326 ) ;
else
F_102 ( V_2 -> V_51 . V_325 ) ;
if ( F_100 ( V_2 ) ) {
if ( V_2 -> V_81 -> V_130 . V_155 != V_327 )
V_2 -> V_51 . V_155 =
V_2 -> V_81 -> V_130 . V_155 ;
F_103 ( V_2 , V_86 ) ;
}
if ( F_100 ( V_2 ) ) {
enum V_322 V_328 ;
V_328 = V_2 -> V_81 -> V_130 . V_328 ;
V_2 -> V_51 . V_323 = V_328 ;
}
F_91 ( V_2 ) ;
return V_74 ;
}
static int F_104 ( struct V_13 * V_11 )
{
struct V_1 * V_2 = F_105 ( V_11 ) ;
T_1 V_329 ;
F_106 ( V_11 -> V_330 , V_331 ,
& V_11 -> V_332 ) ;
F_106 ( V_11 -> V_330 , V_333 ,
& V_11 -> V_334 ) ;
V_11 -> V_335 = ( T_3 ) F_2 ( V_2 , V_2 -> V_10 ,
V_336 ) ;
V_11 -> V_337 = ( T_3 ) F_2 ( V_2 , V_2 -> V_10 ,
V_338 ) ;
F_107 ( V_339 , V_11 -> V_337 ) ;
V_11 -> type = V_340 ;
V_329 = F_2 ( V_2 , V_2 -> V_10 ,
V_341 ) ;
if ( V_329 & ( 1 << V_2 -> V_94 ) ) {
F_22 ( V_11 -> V_18 , L_46 ) ;
V_11 -> V_12 = 2 ;
} else {
V_11 -> V_12 = 1 ;
}
V_11 -> V_342 = F_2 ( V_2 , V_2 -> V_10 ,
V_343 ) >> 4 ;
F_107 ( V_344 , V_11 -> V_342 ) ;
V_11 -> V_345 = ( T_3 ) F_2 ( V_2 , V_2 -> V_10 ,
V_346 ) ;
F_107 ( V_347 , V_11 -> V_345 ) ;
F_3 ( V_11 -> V_18 ,
L_47 ,
V_11 -> V_335 , V_11 -> V_337 ,
V_11 -> V_342 , V_11 -> V_345 ) ;
if ( F_108 ( V_11 ) && F_109 ( V_11 ) ) {
F_22 ( V_11 -> V_18 ,
L_48 ) ;
return - V_44 ;
}
return 0 ;
}
static int F_110 ( struct V_1 * V_2 ,
void T_4 * V_348 ,
void T_4 * V_349 ,
enum V_322 V_323 )
{
int V_74 = 0 ;
V_2 -> V_350 = V_348 ;
V_2 -> V_351 = V_349 ;
if ( F_43 ( V_2 , V_219 ) == 0xffffffff ) {
F_19 ( V_2 ,
L_49 ) ;
return - V_44 ;
}
F_87 ( V_2 ) ;
V_74 = F_111 ( V_2 ) ;
if ( V_74 ) {
F_22 ( V_2 , L_50 ) ;
goto V_352;
}
V_2 -> V_10 = F_29 ( V_2 , V_353 ) ;
if ( ! V_2 -> V_19 ) {
V_74 = F_104 ( V_2 -> V_11 ) ;
if ( V_74 != 0 )
goto V_354;
}
F_86 ( V_2 ) ;
V_74 = F_112 ( V_2 , V_2 -> V_10 ) ;
if ( V_74 ) {
F_22 ( V_2 , L_51 ) ;
goto V_354;
}
V_74 = F_98 ( V_2 , V_2 -> V_10 , V_323 ) ;
if ( V_74 ) {
F_22 ( V_2 , L_52 ) ;
goto V_355;
}
V_74 = F_113 ( V_2 ) ;
if ( V_74 ) {
F_22 ( V_2 , L_53 ) ;
goto V_355;
}
return V_74 ;
V_355:
F_114 ( V_2 ) ;
V_354:
F_84 ( V_2 ) ;
V_352:
return V_74 ;
}
int F_115 ( struct V_13 * V_11 ,
int V_323 )
{
struct V_1 * V_2 = F_105 ( V_11 ) ;
int V_74 ;
F_116 ( V_11 ) ;
V_74 = F_110 ( V_2 ,
V_11 -> V_350 ,
V_11 -> V_351 , V_323 ) ;
if ( V_74 )
return V_74 ;
V_323 = V_2 -> V_51 . V_323 ;
if ( V_11 -> V_12 > 1 ) {
void T_4 * V_348 , * V_356 ;
T_2 T_4 * V_89 ;
V_89 = V_11 -> V_350 + F_1 ( V_2 , V_6 ) / 2 ;
V_348 = V_89 ;
V_89 = V_11 -> V_351 + F_1 ( V_2 , V_357 ) / 2 ;
V_356 = V_89 ;
V_74 = F_110 ( & V_11 -> V_18 [ 1 ] , V_348 ,
V_356 , V_323 ) ;
if ( V_74 ) {
F_117 ( V_2 ) ;
F_114 ( V_2 ) ;
F_84 ( V_2 ) ;
}
}
return V_74 ;
}
void F_118 ( struct V_13 * V_11 )
{
int V_16 ;
F_10 (cdev, i) {
struct V_1 * V_2 = & V_11 -> V_18 [ V_16 ] ;
F_117 ( V_2 ) ;
F_84 ( V_2 ) ;
F_114 ( V_2 ) ;
}
}
int F_119 ( struct V_13 * V_11 ,
enum V_358 V_359 ,
enum V_360 V_361 ,
T_3 V_362 ,
T_5 V_363 ,
struct V_364 * V_365 )
{
T_6 V_366 = 0 ;
void * V_367 = NULL ;
T_6 V_368 = 0 ;
void * V_369 = NULL ;
T_3 V_370 = 0 ;
T_5 V_371 ;
if ( V_361 == V_372 )
V_370 = 1 ;
else
V_370 = F_120 ( V_362 , V_363 , V_361 ) ;
V_371 = V_370 * V_373 ;
V_369 = F_121 ( & V_11 -> V_330 -> V_374 ,
V_371 , & V_368 , V_45 ) ;
if ( ! V_369 ) {
F_22 ( V_11 , L_54 ) ;
goto V_375;
}
if ( V_361 == V_376 ) {
V_371 = V_370 * V_377 ;
V_367 = F_121 ( & V_11 -> V_330 -> V_374 ,
V_371 , & V_366 ,
V_45 ) ;
if ( ! V_367 ) {
F_22 ( V_11 , L_55 ) ;
goto V_375;
}
F_122 ( V_365 , V_369 , V_368 , V_370 ,
( T_2 ) V_363 , V_359 ,
V_366 , V_367 ) ;
} else {
F_123 ( V_365 , V_369 , V_368 , V_370 ,
( T_2 ) V_363 , V_359 , V_361 ) ;
}
return 0 ;
V_375:
F_124 ( & V_11 -> V_330 -> V_374 ,
V_370 * V_373 ,
V_369 , V_368 ) ;
F_124 ( & V_11 -> V_330 -> V_374 ,
V_370 * V_377 ,
V_367 , V_366 ) ;
return - V_71 ;
}
void F_125 ( struct V_13 * V_11 ,
struct V_364 * V_365 )
{
T_5 V_371 ;
if ( ! V_365 -> V_378 )
return;
if ( V_365 -> V_361 == V_376 ) {
V_371 = V_365 -> V_370 * V_377 ;
F_124 ( & V_11 -> V_330 -> V_374 , V_371 ,
V_365 -> V_379 . V_380 ,
V_365 -> V_379 . V_381 ) ;
}
V_371 = V_365 -> V_370 * V_373 ;
F_124 ( & V_11 -> V_330 -> V_374 , V_371 ,
V_365 -> V_378 ,
V_365 -> V_382 ) ;
}
int F_126 ( struct V_1 * V_2 ,
T_3 V_383 , T_3 * V_384 )
{
if ( V_383 >= F_18 ( V_2 , V_77 ) ) {
T_3 V_385 , V_386 ;
V_385 = ( T_3 ) F_21 ( V_2 , V_77 ) ;
V_386 = V_385 + F_18 ( V_2 , V_77 ) ;
F_22 ( V_2 ,
L_56 ,
V_383 , V_385 , V_386 ) ;
return - V_44 ;
}
* V_384 = F_21 ( V_2 , V_77 ) + V_383 ;
return 0 ;
}
int F_127 ( struct V_1 * V_2 ,
T_2 V_383 , T_2 * V_384 )
{
if ( V_383 >= F_18 ( V_2 , V_42 ) ) {
T_2 V_385 , V_386 ;
V_385 = ( T_2 ) F_21 ( V_2 , V_42 ) ;
V_386 = V_385 + F_18 ( V_2 , V_42 ) ;
F_22 ( V_2 ,
L_57 ,
V_383 , V_385 , V_386 ) ;
return - V_44 ;
}
* V_384 = F_21 ( V_2 , V_42 ) + V_383 ;
return 0 ;
}
int F_128 ( struct V_1 * V_2 ,
T_2 V_383 , T_2 * V_384 )
{
if ( V_383 >= F_18 ( V_2 , V_239 ) ) {
T_2 V_385 , V_386 ;
V_385 = ( T_2 ) F_21 ( V_2 , V_239 ) ;
V_386 = V_385 + F_18 ( V_2 , V_239 ) ;
F_22 ( V_2 ,
L_58 ,
V_383 , V_385 , V_386 ) ;
return - V_44 ;
}
* V_384 = F_21 ( V_2 , V_239 ) + V_383 ;
return 0 ;
}
