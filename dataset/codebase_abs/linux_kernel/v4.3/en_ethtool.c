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
int V_73 = V_6 -> V_8 -> V_6 . V_74 . V_75 ;
V_72 -> V_76 = V_73 ;
V_72 -> V_77 = V_6 -> V_21 . V_22 ;
}
static int F_24 ( struct V_1 * V_2 ,
struct V_71 * V_72 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_73 = V_6 -> V_8 -> V_6 . V_74 . V_75 ;
unsigned int V_78 = V_72 -> V_77 ;
bool V_61 ;
int V_63 = 0 ;
if ( ! V_78 ) {
F_18 ( V_2 , L_12 ,
V_65 ) ;
return - V_66 ;
}
if ( V_72 -> V_79 || V_72 -> V_80 ) {
F_18 ( V_2 , L_13 ,
V_65 ) ;
return - V_66 ;
}
if ( V_78 > V_73 ) {
F_18 ( V_2 , L_14 ,
V_65 , V_78 , V_73 ) ;
return - V_66 ;
}
if ( V_6 -> V_21 . V_22 == V_78 )
return 0 ;
F_11 ( & V_6 -> V_42 ) ;
V_61 = F_12 ( V_43 , & V_6 -> V_44 ) ;
if ( V_61 )
F_21 ( V_2 ) ;
V_6 -> V_21 . V_22 = V_78 ;
if ( V_61 )
V_63 = F_22 ( V_2 ) ;
F_14 ( & V_6 -> V_42 ) ;
return V_63 ;
}
static int F_25 ( struct V_1 * V_81 ,
struct V_82 * V_83 )
{
struct V_5 * V_6 = F_2 ( V_81 ) ;
V_83 -> V_84 = V_6 -> V_21 . V_85 ;
V_83 -> V_86 = V_6 -> V_21 . V_87 ;
V_83 -> V_88 = V_6 -> V_21 . V_89 ;
V_83 -> V_90 = V_6 -> V_21 . V_91 ;
return 0 ;
}
static int F_26 ( struct V_1 * V_81 ,
struct V_82 * V_83 )
{
struct V_5 * V_6 = F_2 ( V_81 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_92 * V_93 ;
int V_31 ;
int V_29 ;
V_6 -> V_21 . V_89 = V_83 -> V_88 ;
V_6 -> V_21 . V_91 = V_83 -> V_90 ;
V_6 -> V_21 . V_85 = V_83 -> V_84 ;
V_6 -> V_21 . V_87 = V_83 -> V_86 ;
for ( V_29 = 0 ; V_29 < V_6 -> V_21 . V_22 ; ++ V_29 ) {
V_93 = V_6 -> V_48 [ V_29 ] ;
for ( V_31 = 0 ; V_31 < V_93 -> V_24 ; V_31 ++ ) {
F_27 ( V_8 ,
& V_93 -> V_50 [ V_31 ] . V_94 . V_95 ,
V_83 -> V_88 ,
V_83 -> V_90 ) ;
}
F_27 ( V_8 , & V_93 -> V_49 . V_94 . V_95 ,
V_83 -> V_84 ,
V_83 -> V_86 ) ;
}
return 0 ;
}
static T_6 F_28 ( T_6 V_96 )
{
int V_29 ;
T_6 V_97 = 0 ;
for ( V_29 = 0 ; V_29 < V_98 ; ++ V_29 ) {
if ( V_96 & F_29 ( V_29 ) )
V_97 |= V_99 [ V_29 ] . V_100 ;
}
return V_97 ;
}
static T_6 F_30 ( T_6 V_96 )
{
int V_29 ;
T_6 V_101 = 0 ;
for ( V_29 = 0 ; V_29 < V_98 ; ++ V_29 ) {
if ( V_96 & F_29 ( V_29 ) )
V_101 |= V_99 [ V_29 ] . V_102 ;
}
return V_101 ;
}
static T_6 F_31 ( T_6 V_96 )
{
if ( V_96 & ( F_29 ( V_103 )
| F_29 ( V_104 )
| F_29 ( V_105 )
| F_29 ( V_106 )
| F_29 ( V_107 )
| F_29 ( V_108 ) ) ) {
return V_109 ;
}
if ( V_96 & ( F_29 ( V_110 )
| F_29 ( V_111 )
| F_29 ( V_112 )
| F_29 ( V_113 )
| F_29 ( V_114 ) ) ) {
return V_115 ;
}
return 0 ;
}
static void F_32 ( struct V_1 * V_81 ,
T_6 V_116 ,
struct V_117 * V_118 )
{
int V_29 ;
T_6 V_119 = V_120 ;
T_5 V_121 = V_122 ;
if ( ! F_33 ( V_81 ) )
goto V_123;
for ( V_29 = 0 ; V_29 < V_98 ; ++ V_29 ) {
if ( V_116 & F_29 ( V_29 ) ) {
V_119 = V_99 [ V_29 ] . V_119 ;
V_121 = V_124 ;
break;
}
}
V_123:
F_34 ( V_118 , V_119 ) ;
V_118 -> V_121 = V_121 ;
}
static void F_35 ( T_6 V_96 , T_6 * V_100 )
{
* V_100 |= F_31 ( V_96 ) ;
* V_100 |= F_28 ( V_96 ) ;
* V_100 |= V_125 | V_126 ;
}
static void F_36 ( T_6 V_96 , T_5 V_127 ,
T_5 V_128 , T_6 * V_129 )
{
* V_129 |= F_30 ( V_96 ) ;
* V_129 |= V_127 ? V_130 : 0 ;
* V_129 |= ( V_127 ^ V_128 ) ? V_131 : 0 ;
}
static T_5 F_37 ( T_6 V_132 )
{
if ( V_132 & ( F_29 ( V_104 )
| F_29 ( V_106 )
| F_29 ( V_107 )
| F_29 ( V_108 ) ) ) {
return V_133 ;
}
if ( V_132 & ( F_29 ( V_105 )
| F_29 ( V_103 )
| F_29 ( V_134 ) ) ) {
return V_135 ;
}
if ( V_132 & ( F_29 ( V_113 )
| F_29 ( V_112 )
| F_29 ( V_111 )
| F_29 ( V_110 ) ) ) {
return V_136 ;
}
return V_137 ;
}
static void F_38 ( T_6 V_138 , T_6 * V_139 )
{
* V_139 = F_30 ( V_138 ) ;
}
static int F_39 ( struct V_1 * V_81 ,
struct V_117 * V_118 )
{
struct V_5 * V_6 = F_2 ( V_81 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_6 V_123 [ F_40 ( V_140 ) ] ;
T_6 V_96 ;
T_6 V_141 ;
T_6 V_138 ;
T_6 V_116 ;
int V_63 ;
V_63 = F_41 ( V_8 , V_123 , sizeof( V_123 ) , V_142 , 1 ) ;
if ( V_63 ) {
F_42 ( V_81 , L_15 ,
V_65 , V_63 ) ;
goto V_143;
}
V_96 = F_43 ( V_140 , V_123 , V_144 ) ;
V_141 = F_43 ( V_140 , V_123 , V_141 ) ;
V_116 = F_43 ( V_140 , V_123 , V_116 ) ;
V_138 = F_43 ( V_140 , V_123 , V_145 ) ;
V_118 -> V_100 = 0 ;
V_118 -> V_129 = 0 ;
F_35 ( V_96 , & V_118 -> V_100 ) ;
F_36 ( V_141 , 0 , 0 , & V_118 -> V_129 ) ;
F_32 ( V_81 , V_116 , V_118 ) ;
V_116 = V_116 ? V_116 : V_96 ;
V_118 -> V_146 = F_37 ( V_116 ) ;
F_38 ( V_138 , & V_118 -> V_139 ) ;
V_118 -> V_147 = V_148 ;
V_143:
return V_63 ;
}
static T_6 F_44 ( T_6 V_149 )
{
T_6 V_29 , V_150 = 0 ;
for ( V_29 = 0 ; V_29 < V_98 ; ++ V_29 ) {
if ( V_99 [ V_29 ] . V_102 & V_149 )
V_150 |= F_29 ( V_29 ) ;
}
return V_150 ;
}
static T_6 F_45 ( T_6 V_119 )
{
T_6 V_29 , V_151 = 0 ;
for ( V_29 = 0 ; V_29 < V_98 ; ++ V_29 ) {
if ( V_99 [ V_29 ] . V_119 == V_119 )
V_151 |= F_29 ( V_29 ) ;
}
return V_151 ;
}
static int F_46 ( struct V_1 * V_81 ,
struct V_117 * V_118 )
{
struct V_5 * V_6 = F_2 ( V_81 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_6 V_149 ;
T_6 V_119 ;
T_6 V_96 , V_141 ;
enum V_152 V_153 ;
int V_63 ;
V_119 = F_47 ( V_118 ) ;
V_149 = V_118 -> V_154 == V_155 ?
F_44 ( V_118 -> V_129 ) :
F_45 ( V_119 ) ;
V_63 = F_48 ( V_8 , & V_96 , V_142 ) ;
if ( V_63 ) {
F_42 ( V_81 , L_16 ,
V_65 , V_63 ) ;
goto V_123;
}
V_149 = V_149 & V_96 ;
if ( ! V_149 ) {
F_42 ( V_81 , L_17 ,
V_65 ) ;
V_63 = - V_66 ;
goto V_123;
}
V_63 = F_49 ( V_8 , & V_141 , V_142 ) ;
if ( V_63 ) {
F_42 ( V_81 , L_18 ,
V_65 , V_63 ) ;
goto V_123;
}
if ( V_149 == V_141 )
goto V_123;
F_50 ( V_8 , & V_153 ) ;
if ( V_153 == V_156 )
F_51 ( V_8 , V_157 ) ;
F_52 ( V_8 , V_149 , V_142 ) ;
if ( V_153 == V_156 )
F_51 ( V_8 , V_156 ) ;
V_123:
return V_63 ;
}
static T_6 F_53 ( struct V_1 * V_81 )
{
struct V_5 * V_6 = F_2 ( V_81 ) ;
return sizeof( V_6 -> V_21 . V_158 ) ;
}
static T_6 F_54 ( struct V_1 * V_81 )
{
return V_159 ;
}
static int F_55 ( struct V_1 * V_81 , T_6 * V_160 , T_5 * V_161 ,
T_5 * V_162 )
{
struct V_5 * V_6 = F_2 ( V_81 ) ;
if ( V_160 )
memcpy ( V_160 , V_6 -> V_21 . V_163 ,
sizeof( V_6 -> V_21 . V_163 ) ) ;
if ( V_161 )
memcpy ( V_161 , V_6 -> V_21 . V_158 ,
sizeof( V_6 -> V_21 . V_158 ) ) ;
if ( V_162 )
* V_162 = V_6 -> V_21 . V_164 ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 , const T_6 * V_160 ,
const T_5 * V_161 , const T_5 V_162 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
bool V_165 ;
int V_63 = 0 ;
if ( ( V_162 != V_166 ) &&
( V_162 != V_167 ) &&
( V_162 != V_168 ) )
return - V_66 ;
F_11 ( & V_6 -> V_42 ) ;
if ( V_160 ) {
memcpy ( V_6 -> V_21 . V_163 , V_160 ,
sizeof( V_6 -> V_21 . V_163 ) ) ;
F_57 ( V_6 , V_169 ) ;
}
V_165 = ( V_161 || ( V_162 != V_166 ) ) &&
F_12 ( V_43 , & V_6 -> V_44 ) ;
if ( V_165 )
F_21 ( V_2 ) ;
if ( V_161 )
memcpy ( V_6 -> V_21 . V_158 , V_161 ,
sizeof( V_6 -> V_21 . V_158 ) ) ;
if ( V_162 != V_166 )
V_6 -> V_21 . V_164 = V_162 ;
if ( V_165 )
V_63 = F_22 ( V_6 -> V_81 ) ;
F_14 ( & V_6 -> V_42 ) ;
return V_63 ;
}
static int F_58 ( struct V_1 * V_81 ,
struct V_170 * V_171 , T_6 * V_172 )
{
struct V_5 * V_6 = F_2 ( V_81 ) ;
int V_63 = 0 ;
switch ( V_171 -> V_118 ) {
case V_173 :
V_171 -> V_28 = V_6 -> V_21 . V_22 ;
break;
default:
V_63 = - V_26 ;
break;
}
return V_63 ;
}
static int F_59 ( struct V_1 * V_2 ,
const struct V_174 * V_175 ,
void * V_28 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_63 = 0 ;
switch ( V_175 -> V_176 ) {
case V_177 :
* ( T_6 * ) V_28 = V_6 -> V_21 . V_178 ;
break;
default:
V_63 = - V_66 ;
break;
}
return V_63 ;
}
static int F_60 ( struct V_1 * V_2 ,
const struct V_174 * V_175 ,
const void * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
bool V_61 ;
T_6 V_179 ;
int V_63 = 0 ;
switch ( V_175 -> V_176 ) {
case V_177 :
V_179 = * ( T_6 * ) V_28 ;
if ( V_179 > F_61 ( V_8 ) ) {
V_63 = - V_66 ;
break;
}
F_11 ( & V_6 -> V_42 ) ;
V_61 = F_12 ( V_43 , & V_6 -> V_44 ) ;
if ( V_61 )
F_21 ( V_2 ) ;
V_6 -> V_21 . V_178 = V_179 ;
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
static void F_62 ( struct V_1 * V_81 ,
struct V_180 * V_181 )
{
struct V_5 * V_6 = F_2 ( V_81 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_63 ;
V_63 = F_63 ( V_8 , & V_181 -> V_128 ,
& V_181 -> V_127 ) ;
if ( V_63 ) {
F_42 ( V_81 , L_19 ,
V_65 , V_63 ) ;
}
}
static int F_64 ( struct V_1 * V_81 ,
struct V_180 * V_181 )
{
struct V_5 * V_6 = F_2 ( V_81 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_63 ;
if ( V_181 -> V_154 )
return - V_66 ;
V_63 = F_65 ( V_8 ,
V_181 -> V_128 ? 1 : 0 ,
V_181 -> V_127 ? 1 : 0 ) ;
if ( V_63 ) {
F_42 ( V_81 , L_20 ,
V_65 , V_63 ) ;
}
return V_63 ;
}
