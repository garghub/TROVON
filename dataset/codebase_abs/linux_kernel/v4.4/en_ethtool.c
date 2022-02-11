static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
F_3 ( V_4 -> V_9 , V_10 , sizeof( V_4 -> V_9 ) ) ;
F_3 ( V_4 -> V_11 , V_12 L_1 V_13 L_2 ,
sizeof( V_4 -> V_11 ) ) ;
snprintf ( V_4 -> V_14 , sizeof( V_4 -> V_14 ) ,
L_3 ,
F_4 ( V_8 ) , F_5 ( V_8 ) , F_6 ( V_8 ) ) ;
F_3 ( V_4 -> V_15 , F_7 ( V_8 -> V_16 ) ,
sizeof( V_4 -> V_15 ) ) ;
}
static int F_8 ( struct V_1 * V_2 , int V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_17 ) {
case V_18 :
return V_19 + V_20 +
V_6 -> V_21 . V_22 * V_23 +
V_6 -> V_21 . V_22 * V_6 -> V_21 . V_24 *
V_25 ;
default:
return - V_26 ;
}
}
static void F_9 ( struct V_1 * V_2 ,
T_1 V_27 , T_2 * V_28 )
{
int V_29 , V_30 , V_31 , V_32 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_27 ) {
case V_33 :
break;
case V_34 :
break;
case V_18 :
for ( V_29 = 0 ; V_29 < V_19 ; V_29 ++ )
strcpy ( V_28 + ( V_32 ++ ) * V_35 ,
V_36 [ V_29 ] ) ;
for ( V_29 = 0 ; V_29 < V_20 ; V_29 ++ )
strcpy ( V_28 + ( V_32 ++ ) * V_35 ,
V_37 [ V_29 ] ) ;
for ( V_29 = 0 ; V_29 < V_6 -> V_21 . V_22 ; V_29 ++ )
for ( V_30 = 0 ; V_30 < V_23 ; V_30 ++ )
sprintf ( V_28 + ( V_32 ++ ) * V_35 ,
L_4 , V_29 , V_38 [ V_30 ] ) ;
for ( V_29 = 0 ; V_29 < V_6 -> V_21 . V_22 ; V_29 ++ )
for ( V_31 = 0 ; V_31 < V_6 -> V_21 . V_24 ; V_31 ++ )
for ( V_30 = 0 ; V_30 < V_25 ; V_30 ++ )
sprintf ( V_28 +
( V_32 ++ ) * V_35 ,
L_5 , V_29 , V_31 ,
V_39 [ V_30 ] ) ;
break;
}
}
static void F_10 ( struct V_1 * V_2 ,
struct V_40 * V_41 , T_3 * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_29 , V_30 , V_31 , V_32 = 0 ;
if ( ! V_28 )
return;
F_11 ( & V_6 -> V_42 ) ;
if ( F_12 ( V_43 , & V_6 -> V_44 ) )
F_13 ( V_6 ) ;
F_14 ( & V_6 -> V_42 ) ;
for ( V_29 = 0 ; V_29 < V_19 ; V_29 ++ )
V_28 [ V_32 ++ ] = ( ( T_3 * ) & V_6 -> V_41 . V_45 ) [ V_29 ] ;
for ( V_29 = 0 ; V_29 < V_20 ; V_29 ++ )
V_28 [ V_32 ++ ] = F_15 ( ( ( V_46 * ) & V_6 -> V_41 . V_47 ) [ V_29 ] ) ;
for ( V_29 = 0 ; V_29 < V_6 -> V_21 . V_22 ; V_29 ++ )
for ( V_30 = 0 ; V_30 < V_23 ; V_30 ++ )
V_28 [ V_32 ++ ] = ! F_12 ( V_43 ,
& V_6 -> V_44 ) ? 0 :
( ( T_3 * ) & V_6 -> V_48 [ V_29 ] -> V_49 . V_41 ) [ V_30 ] ;
for ( V_29 = 0 ; V_29 < V_6 -> V_21 . V_22 ; V_29 ++ )
for ( V_31 = 0 ; V_31 < V_6 -> V_21 . V_24 ; V_31 ++ )
for ( V_30 = 0 ; V_30 < V_25 ; V_30 ++ )
V_28 [ V_32 ++ ] = ! F_12 ( V_43 ,
& V_6 -> V_44 ) ? 0 :
( ( T_3 * ) & V_6 -> V_48 [ V_29 ] -> V_50 [ V_31 ] . V_41 ) [ V_30 ] ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_52 -> V_53 = 1 << V_54 ;
V_52 -> V_55 = 1 << V_56 ;
V_52 -> V_57 = 1 << V_6 -> V_21 . V_58 ;
V_52 -> V_59 = 1 << V_6 -> V_21 . V_60 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_51 * V_52 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
bool V_61 ;
T_4 V_62 ;
T_5 V_58 ;
T_5 V_60 ;
int V_63 = 0 ;
if ( V_52 -> V_64 ) {
F_18 ( V_2 , L_6 ,
V_65 ) ;
return - V_66 ;
}
if ( V_52 -> V_67 ) {
F_18 ( V_2 , L_7 ,
V_65 ) ;
return - V_66 ;
}
if ( V_52 -> V_57 < ( 1 << V_68 ) ) {
F_18 ( V_2 , L_8 ,
V_65 , V_52 -> V_57 ,
1 << V_68 ) ;
return - V_66 ;
}
if ( V_52 -> V_57 > ( 1 << V_54 ) ) {
F_18 ( V_2 , L_9 ,
V_65 , V_52 -> V_57 ,
1 << V_54 ) ;
return - V_66 ;
}
if ( V_52 -> V_59 < ( 1 << V_69 ) ) {
F_18 ( V_2 , L_10 ,
V_65 , V_52 -> V_59 ,
1 << V_69 ) ;
return - V_66 ;
}
if ( V_52 -> V_59 > ( 1 << V_56 ) ) {
F_18 ( V_2 , L_11 ,
V_65 , V_52 -> V_59 ,
1 << V_56 ) ;
return - V_66 ;
}
V_58 = F_19 ( V_52 -> V_57 ) ;
V_60 = F_19 ( V_52 -> V_59 ) ;
V_62 = F_20 ( T_4 , V_52 -> V_57 - 1 ,
V_70 ) ;
if ( V_58 == V_6 -> V_21 . V_58 &&
V_60 == V_6 -> V_21 . V_60 &&
V_62 == V_6 -> V_21 . V_62 )
return 0 ;
F_11 ( & V_6 -> V_42 ) ;
V_61 = F_12 ( V_43 , & V_6 -> V_44 ) ;
if ( V_61 )
F_21 ( V_2 ) ;
V_6 -> V_21 . V_58 = V_58 ;
V_6 -> V_21 . V_60 = V_60 ;
V_6 -> V_21 . V_62 = V_62 ;
if ( V_61 )
V_63 = F_22 ( V_2 ) ;
F_14 ( & V_6 -> V_42 ) ;
return V_63 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_72 -> V_73 = F_24 ( V_6 -> V_8 ) ;
V_72 -> V_74 = V_6 -> V_21 . V_22 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_75 = F_24 ( V_6 -> V_8 ) ;
unsigned int V_76 = V_72 -> V_74 ;
bool V_61 ;
int V_63 = 0 ;
if ( ! V_76 ) {
F_18 ( V_2 , L_12 ,
V_65 ) ;
return - V_66 ;
}
if ( V_72 -> V_77 || V_72 -> V_78 ) {
F_18 ( V_2 , L_13 ,
V_65 ) ;
return - V_66 ;
}
if ( V_76 > V_75 ) {
F_18 ( V_2 , L_14 ,
V_65 , V_76 , V_75 ) ;
return - V_66 ;
}
if ( V_6 -> V_21 . V_22 == V_76 )
return 0 ;
F_11 ( & V_6 -> V_42 ) ;
V_61 = F_12 ( V_43 , & V_6 -> V_44 ) ;
if ( V_61 )
F_21 ( V_2 ) ;
V_6 -> V_21 . V_22 = V_76 ;
if ( V_61 )
V_63 = F_22 ( V_2 ) ;
F_14 ( & V_6 -> V_42 ) ;
return V_63 ;
}
static int F_26 ( struct V_1 * V_79 ,
struct V_80 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_79 ) ;
V_81 -> V_82 = V_6 -> V_21 . V_83 ;
V_81 -> V_84 = V_6 -> V_21 . V_85 ;
V_81 -> V_86 = V_6 -> V_21 . V_87 ;
V_81 -> V_88 = V_6 -> V_21 . V_89 ;
return 0 ;
}
static int F_27 ( struct V_1 * V_79 ,
struct V_80 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_79 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_90 * V_91 ;
int V_31 ;
int V_29 ;
V_6 -> V_21 . V_87 = V_81 -> V_86 ;
V_6 -> V_21 . V_89 = V_81 -> V_88 ;
V_6 -> V_21 . V_83 = V_81 -> V_82 ;
V_6 -> V_21 . V_85 = V_81 -> V_84 ;
for ( V_29 = 0 ; V_29 < V_6 -> V_21 . V_22 ; ++ V_29 ) {
V_91 = V_6 -> V_48 [ V_29 ] ;
for ( V_31 = 0 ; V_31 < V_91 -> V_24 ; V_31 ++ ) {
F_28 ( V_8 ,
& V_91 -> V_50 [ V_31 ] . V_92 . V_93 ,
V_81 -> V_86 ,
V_81 -> V_88 ) ;
}
F_28 ( V_8 , & V_91 -> V_49 . V_92 . V_93 ,
V_81 -> V_82 ,
V_81 -> V_84 ) ;
}
return 0 ;
}
static T_6 F_29 ( T_6 V_94 )
{
int V_29 ;
T_6 V_95 = 0 ;
for ( V_29 = 0 ; V_29 < V_96 ; ++ V_29 ) {
if ( V_94 & F_30 ( V_29 ) )
V_95 |= V_97 [ V_29 ] . V_98 ;
}
return V_95 ;
}
static T_6 F_31 ( T_6 V_94 )
{
int V_29 ;
T_6 V_99 = 0 ;
for ( V_29 = 0 ; V_29 < V_96 ; ++ V_29 ) {
if ( V_94 & F_30 ( V_29 ) )
V_99 |= V_97 [ V_29 ] . V_100 ;
}
return V_99 ;
}
static T_6 F_32 ( T_6 V_94 )
{
if ( V_94 & ( F_30 ( V_101 )
| F_30 ( V_102 )
| F_30 ( V_103 )
| F_30 ( V_104 )
| F_30 ( V_105 )
| F_30 ( V_106 ) ) ) {
return V_107 ;
}
if ( V_94 & ( F_30 ( V_108 )
| F_30 ( V_109 )
| F_30 ( V_110 )
| F_30 ( V_111 )
| F_30 ( V_112 ) ) ) {
return V_113 ;
}
return 0 ;
}
static void F_33 ( struct V_1 * V_79 ,
T_6 V_114 ,
struct V_115 * V_116 )
{
int V_29 ;
T_6 V_117 = V_118 ;
T_5 V_119 = V_120 ;
if ( ! F_34 ( V_79 ) )
goto V_121;
for ( V_29 = 0 ; V_29 < V_96 ; ++ V_29 ) {
if ( V_114 & F_30 ( V_29 ) ) {
V_117 = V_97 [ V_29 ] . V_117 ;
V_119 = V_122 ;
break;
}
}
V_121:
F_35 ( V_116 , V_117 ) ;
V_116 -> V_119 = V_119 ;
}
static void F_36 ( T_6 V_94 , T_6 * V_98 )
{
* V_98 |= F_32 ( V_94 ) ;
* V_98 |= F_29 ( V_94 ) ;
* V_98 |= V_123 | V_124 ;
}
static void F_37 ( T_6 V_94 , T_5 V_125 ,
T_5 V_126 , T_6 * V_127 )
{
* V_127 |= F_31 ( V_94 ) ;
* V_127 |= V_125 ? V_128 : 0 ;
* V_127 |= ( V_125 ^ V_126 ) ? V_129 : 0 ;
}
static T_5 F_38 ( T_6 V_130 )
{
if ( V_130 & ( F_30 ( V_102 )
| F_30 ( V_104 )
| F_30 ( V_105 )
| F_30 ( V_106 ) ) ) {
return V_131 ;
}
if ( V_130 & ( F_30 ( V_103 )
| F_30 ( V_101 )
| F_30 ( V_132 ) ) ) {
return V_133 ;
}
if ( V_130 & ( F_30 ( V_111 )
| F_30 ( V_110 )
| F_30 ( V_109 )
| F_30 ( V_108 ) ) ) {
return V_134 ;
}
return V_135 ;
}
static void F_39 ( T_6 V_136 , T_6 * V_137 )
{
* V_137 = F_31 ( V_136 ) ;
}
static int F_40 ( struct V_1 * V_79 ,
struct V_115 * V_116 )
{
struct V_5 * V_6 = F_2 ( V_79 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_6 V_121 [ F_41 ( V_138 ) ] ;
T_6 V_94 ;
T_6 V_139 ;
T_6 V_136 ;
T_6 V_114 ;
int V_63 ;
V_63 = F_42 ( V_8 , V_121 , sizeof( V_121 ) , V_140 , 1 ) ;
if ( V_63 ) {
F_43 ( V_79 , L_15 ,
V_65 , V_63 ) ;
goto V_141;
}
V_94 = F_44 ( V_138 , V_121 , V_142 ) ;
V_139 = F_44 ( V_138 , V_121 , V_139 ) ;
V_114 = F_44 ( V_138 , V_121 , V_114 ) ;
V_136 = F_44 ( V_138 , V_121 , V_143 ) ;
V_116 -> V_98 = 0 ;
V_116 -> V_127 = 0 ;
F_36 ( V_94 , & V_116 -> V_98 ) ;
F_37 ( V_139 , 0 , 0 , & V_116 -> V_127 ) ;
F_33 ( V_79 , V_114 , V_116 ) ;
V_114 = V_114 ? V_114 : V_94 ;
V_116 -> V_144 = F_38 ( V_114 ) ;
F_39 ( V_136 , & V_116 -> V_137 ) ;
V_116 -> V_145 = V_146 ;
V_141:
return V_63 ;
}
static T_6 F_45 ( T_6 V_147 )
{
T_6 V_29 , V_148 = 0 ;
for ( V_29 = 0 ; V_29 < V_96 ; ++ V_29 ) {
if ( V_97 [ V_29 ] . V_100 & V_147 )
V_148 |= F_30 ( V_29 ) ;
}
return V_148 ;
}
static T_6 F_46 ( T_6 V_117 )
{
T_6 V_29 , V_149 = 0 ;
for ( V_29 = 0 ; V_29 < V_96 ; ++ V_29 ) {
if ( V_97 [ V_29 ] . V_117 == V_117 )
V_149 |= F_30 ( V_29 ) ;
}
return V_149 ;
}
static int F_47 ( struct V_1 * V_79 ,
struct V_115 * V_116 )
{
struct V_5 * V_6 = F_2 ( V_79 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_6 V_147 ;
T_6 V_117 ;
T_6 V_94 , V_139 ;
enum V_150 V_151 ;
int V_63 ;
V_117 = F_48 ( V_116 ) ;
V_147 = V_116 -> V_152 == V_153 ?
F_45 ( V_116 -> V_127 ) :
F_46 ( V_117 ) ;
V_63 = F_49 ( V_8 , & V_94 , V_140 ) ;
if ( V_63 ) {
F_43 ( V_79 , L_16 ,
V_65 , V_63 ) ;
goto V_121;
}
V_147 = V_147 & V_94 ;
if ( ! V_147 ) {
F_43 ( V_79 , L_17 ,
V_65 ) ;
V_63 = - V_66 ;
goto V_121;
}
V_63 = F_50 ( V_8 , & V_139 , V_140 ) ;
if ( V_63 ) {
F_43 ( V_79 , L_18 ,
V_65 , V_63 ) ;
goto V_121;
}
if ( V_147 == V_139 )
goto V_121;
F_51 ( V_8 , & V_151 ) ;
if ( V_151 == V_154 )
F_52 ( V_8 , V_155 ) ;
F_53 ( V_8 , V_147 , V_140 ) ;
if ( V_151 == V_154 )
F_52 ( V_8 , V_154 ) ;
V_121:
return V_63 ;
}
static T_6 F_54 ( struct V_1 * V_79 )
{
struct V_5 * V_6 = F_2 ( V_79 ) ;
return sizeof( V_6 -> V_21 . V_156 ) ;
}
static T_6 F_55 ( struct V_1 * V_79 )
{
return V_157 ;
}
static int F_56 ( struct V_1 * V_79 , T_6 * V_158 , T_5 * V_159 ,
T_5 * V_160 )
{
struct V_5 * V_6 = F_2 ( V_79 ) ;
if ( V_158 )
memcpy ( V_158 , V_6 -> V_21 . V_161 ,
sizeof( V_6 -> V_21 . V_161 ) ) ;
if ( V_159 )
memcpy ( V_159 , V_6 -> V_21 . V_156 ,
sizeof( V_6 -> V_21 . V_156 ) ) ;
if ( V_160 )
* V_160 = V_6 -> V_21 . V_162 ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 , const T_6 * V_158 ,
const T_5 * V_159 , const T_5 V_160 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
bool V_163 ;
int V_63 = 0 ;
if ( ( V_160 != V_164 ) &&
( V_160 != V_165 ) &&
( V_160 != V_166 ) )
return - V_66 ;
F_11 ( & V_6 -> V_42 ) ;
if ( V_158 ) {
memcpy ( V_6 -> V_21 . V_161 , V_158 ,
sizeof( V_6 -> V_21 . V_161 ) ) ;
F_58 ( V_6 , V_167 ) ;
}
V_163 = ( V_159 || ( V_160 != V_164 ) ) &&
F_12 ( V_43 , & V_6 -> V_44 ) ;
if ( V_163 )
F_21 ( V_2 ) ;
if ( V_159 )
memcpy ( V_6 -> V_21 . V_156 , V_159 ,
sizeof( V_6 -> V_21 . V_156 ) ) ;
if ( V_160 != V_164 )
V_6 -> V_21 . V_162 = V_160 ;
if ( V_163 )
V_63 = F_22 ( V_6 -> V_79 ) ;
F_14 ( & V_6 -> V_42 ) ;
return V_63 ;
}
static int F_59 ( struct V_1 * V_79 ,
struct V_168 * V_169 , T_6 * V_170 )
{
struct V_5 * V_6 = F_2 ( V_79 ) ;
int V_63 = 0 ;
switch ( V_169 -> V_116 ) {
case V_171 :
V_169 -> V_28 = V_6 -> V_21 . V_22 ;
break;
default:
V_63 = - V_26 ;
break;
}
return V_63 ;
}
static int F_60 ( struct V_1 * V_2 ,
const struct V_172 * V_173 ,
void * V_28 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
switch ( V_173 -> V_174 ) {
case V_175 :
* ( T_6 * ) V_28 = V_6 -> V_21 . V_176 ;
break;
default:
V_63 = - V_66 ;
break;
}
return V_63 ;
}
static int F_61 ( struct V_1 * V_2 ,
const struct V_172 * V_173 ,
const void * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
bool V_61 ;
T_6 V_177 ;
int V_63 = 0 ;
switch ( V_173 -> V_174 ) {
case V_175 :
V_177 = * ( T_6 * ) V_28 ;
if ( V_177 > F_62 ( V_8 ) ) {
V_63 = - V_66 ;
break;
}
F_11 ( & V_6 -> V_42 ) ;
V_61 = F_12 ( V_43 , & V_6 -> V_44 ) ;
if ( V_61 )
F_21 ( V_2 ) ;
V_6 -> V_21 . V_176 = V_177 ;
if ( V_61 )
V_63 = F_22 ( V_2 ) ;
F_14 ( & V_6 -> V_42 ) ;
break;
default:
V_63 = - V_66 ;
break;
}
return V_63 ;
}
static void F_63 ( struct V_1 * V_79 ,
struct V_178 * V_179 )
{
struct V_5 * V_6 = F_2 ( V_79 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_63 ;
V_63 = F_64 ( V_8 , & V_179 -> V_126 ,
& V_179 -> V_125 ) ;
if ( V_63 ) {
F_43 ( V_79 , L_19 ,
V_65 , V_63 ) ;
}
}
static int F_65 ( struct V_1 * V_79 ,
struct V_178 * V_179 )
{
struct V_5 * V_6 = F_2 ( V_79 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_63 ;
if ( V_179 -> V_152 )
return - V_66 ;
V_63 = F_66 ( V_8 ,
V_179 -> V_126 ? 1 : 0 ,
V_179 -> V_125 ? 1 : 0 ) ;
if ( V_63 ) {
F_43 ( V_79 , L_20 ,
V_65 , V_63 ) ;
}
return V_63 ;
}
