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
for ( V_31 = 0 ; V_31 < V_6 -> V_21 . V_24 ; V_31 ++ )
for ( V_29 = 0 ; V_29 < V_6 -> V_21 . V_22 ; V_29 ++ )
for ( V_30 = 0 ; V_30 < V_25 ; V_30 ++ )
sprintf ( V_28 +
( V_32 ++ ) * V_35 ,
L_5 ,
V_6 -> V_39 [ V_29 ] [ V_31 ] ,
V_40 [ V_30 ] ) ;
break;
}
}
static void F_10 ( struct V_1 * V_2 ,
struct V_41 * V_42 , T_3 * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_29 , V_30 , V_31 , V_32 = 0 ;
if ( ! V_28 )
return;
F_11 ( & V_6 -> V_43 ) ;
if ( F_12 ( V_44 , & V_6 -> V_45 ) )
F_13 ( V_6 ) ;
F_14 ( & V_6 -> V_43 ) ;
for ( V_29 = 0 ; V_29 < V_19 ; V_29 ++ )
V_28 [ V_32 ++ ] = ( ( T_3 * ) & V_6 -> V_42 . V_46 ) [ V_29 ] ;
for ( V_29 = 0 ; V_29 < V_20 ; V_29 ++ )
V_28 [ V_32 ++ ] = F_15 ( ( ( V_47 * ) & V_6 -> V_42 . V_48 ) [ V_29 ] ) ;
for ( V_29 = 0 ; V_29 < V_6 -> V_21 . V_22 ; V_29 ++ )
for ( V_30 = 0 ; V_30 < V_23 ; V_30 ++ )
V_28 [ V_32 ++ ] = ! F_12 ( V_44 ,
& V_6 -> V_45 ) ? 0 :
( ( T_3 * ) & V_6 -> V_49 [ V_29 ] -> V_50 . V_42 ) [ V_30 ] ;
for ( V_31 = 0 ; V_31 < V_6 -> V_21 . V_24 ; V_31 ++ )
for ( V_29 = 0 ; V_29 < V_6 -> V_21 . V_22 ; V_29 ++ )
for ( V_30 = 0 ; V_30 < V_25 ; V_30 ++ )
V_28 [ V_32 ++ ] = ! F_12 ( V_44 ,
& V_6 -> V_45 ) ? 0 :
( ( T_3 * ) & V_6 -> V_49 [ V_29 ] -> V_51 [ V_31 ] . V_42 ) [ V_30 ] ;
}
static void F_16 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_53 -> V_54 = 1 << V_55 ;
V_53 -> V_56 = 1 << V_57 ;
V_53 -> V_58 = 1 << V_6 -> V_21 . V_59 ;
V_53 -> V_60 = 1 << V_6 -> V_21 . V_61 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_52 * V_53 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
bool V_62 ;
T_4 V_63 ;
T_5 V_59 ;
T_5 V_61 ;
int V_64 = 0 ;
if ( V_53 -> V_65 ) {
F_18 ( V_2 , L_6 ,
V_66 ) ;
return - V_67 ;
}
if ( V_53 -> V_68 ) {
F_18 ( V_2 , L_7 ,
V_66 ) ;
return - V_67 ;
}
if ( V_53 -> V_58 < ( 1 << V_69 ) ) {
F_18 ( V_2 , L_8 ,
V_66 , V_53 -> V_58 ,
1 << V_69 ) ;
return - V_67 ;
}
if ( V_53 -> V_58 > ( 1 << V_55 ) ) {
F_18 ( V_2 , L_9 ,
V_66 , V_53 -> V_58 ,
1 << V_55 ) ;
return - V_67 ;
}
if ( V_53 -> V_60 < ( 1 << V_70 ) ) {
F_18 ( V_2 , L_10 ,
V_66 , V_53 -> V_60 ,
1 << V_70 ) ;
return - V_67 ;
}
if ( V_53 -> V_60 > ( 1 << V_57 ) ) {
F_18 ( V_2 , L_11 ,
V_66 , V_53 -> V_60 ,
1 << V_57 ) ;
return - V_67 ;
}
V_59 = F_19 ( V_53 -> V_58 ) ;
V_61 = F_19 ( V_53 -> V_60 ) ;
V_63 = F_20 ( T_4 , V_53 -> V_58 - 1 ,
V_71 ) ;
if ( V_59 == V_6 -> V_21 . V_59 &&
V_61 == V_6 -> V_21 . V_61 &&
V_63 == V_6 -> V_21 . V_63 )
return 0 ;
F_11 ( & V_6 -> V_43 ) ;
V_62 = F_12 ( V_44 , & V_6 -> V_45 ) ;
if ( V_62 )
F_21 ( V_2 ) ;
V_6 -> V_21 . V_59 = V_59 ;
V_6 -> V_21 . V_61 = V_61 ;
V_6 -> V_21 . V_63 = V_63 ;
if ( V_62 )
V_64 = F_22 ( V_2 ) ;
F_14 ( & V_6 -> V_43 ) ;
return V_64 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_73 -> V_74 = F_24 ( V_6 -> V_8 ) ;
V_73 -> V_75 = V_6 -> V_21 . V_22 ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_72 * V_73 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_76 = F_24 ( V_6 -> V_8 ) ;
unsigned int V_77 = V_73 -> V_75 ;
bool V_62 ;
int V_64 = 0 ;
if ( ! V_77 ) {
F_18 ( V_2 , L_12 ,
V_66 ) ;
return - V_67 ;
}
if ( V_73 -> V_78 || V_73 -> V_79 ) {
F_18 ( V_2 , L_13 ,
V_66 ) ;
return - V_67 ;
}
if ( V_77 > V_76 ) {
F_18 ( V_2 , L_14 ,
V_66 , V_77 , V_76 ) ;
return - V_67 ;
}
if ( V_6 -> V_21 . V_22 == V_77 )
return 0 ;
F_11 ( & V_6 -> V_43 ) ;
V_62 = F_12 ( V_44 , & V_6 -> V_45 ) ;
if ( V_62 )
F_21 ( V_2 ) ;
V_6 -> V_21 . V_22 = V_77 ;
F_26 ( V_6 -> V_21 . V_80 ,
V_81 , V_77 ) ;
if ( V_62 )
V_64 = F_22 ( V_2 ) ;
F_14 ( & V_6 -> V_43 ) ;
return V_64 ;
}
static int F_27 ( struct V_1 * V_82 ,
struct V_83 * V_84 )
{
struct V_5 * V_6 = F_2 ( V_82 ) ;
if ( ! F_28 ( V_6 -> V_8 , V_85 ) )
return - V_86 ;
V_84 -> V_87 = V_6 -> V_21 . V_88 ;
V_84 -> V_89 = V_6 -> V_21 . V_90 ;
V_84 -> V_91 = V_6 -> V_21 . V_92 ;
V_84 -> V_93 = V_6 -> V_21 . V_94 ;
return 0 ;
}
static int F_29 ( struct V_1 * V_82 ,
struct V_83 * V_84 )
{
struct V_5 * V_6 = F_2 ( V_82 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_95 * V_96 ;
int V_31 ;
int V_29 ;
if ( ! F_28 ( V_8 , V_85 ) )
return - V_86 ;
F_11 ( & V_6 -> V_43 ) ;
V_6 -> V_21 . V_92 = V_84 -> V_91 ;
V_6 -> V_21 . V_94 = V_84 -> V_93 ;
V_6 -> V_21 . V_88 = V_84 -> V_87 ;
V_6 -> V_21 . V_90 = V_84 -> V_89 ;
if ( ! F_12 ( V_44 , & V_6 -> V_45 ) )
goto V_97;
for ( V_29 = 0 ; V_29 < V_6 -> V_21 . V_22 ; ++ V_29 ) {
V_96 = V_6 -> V_49 [ V_29 ] ;
for ( V_31 = 0 ; V_31 < V_96 -> V_24 ; V_31 ++ ) {
F_30 ( V_8 ,
& V_96 -> V_51 [ V_31 ] . V_98 . V_99 ,
V_84 -> V_91 ,
V_84 -> V_93 ) ;
}
F_30 ( V_8 , & V_96 -> V_50 . V_98 . V_99 ,
V_84 -> V_87 ,
V_84 -> V_89 ) ;
}
V_97:
F_14 ( & V_6 -> V_43 ) ;
return 0 ;
}
static T_6 F_31 ( T_6 V_100 )
{
int V_29 ;
T_6 V_101 = 0 ;
for ( V_29 = 0 ; V_29 < V_102 ; ++ V_29 ) {
if ( V_100 & F_32 ( V_29 ) )
V_101 |= V_103 [ V_29 ] . V_104 ;
}
return V_101 ;
}
static T_6 F_33 ( T_6 V_100 )
{
int V_29 ;
T_6 V_105 = 0 ;
for ( V_29 = 0 ; V_29 < V_102 ; ++ V_29 ) {
if ( V_100 & F_32 ( V_29 ) )
V_105 |= V_103 [ V_29 ] . V_106 ;
}
return V_105 ;
}
static T_6 F_34 ( T_6 V_100 )
{
if ( V_100 & ( F_32 ( V_107 )
| F_32 ( V_108 )
| F_32 ( V_109 )
| F_32 ( V_110 )
| F_32 ( V_111 )
| F_32 ( V_112 ) ) ) {
return V_113 ;
}
if ( V_100 & ( F_32 ( V_114 )
| F_32 ( V_115 )
| F_32 ( V_116 )
| F_32 ( V_117 )
| F_32 ( V_118 ) ) ) {
return V_119 ;
}
return 0 ;
}
static void F_35 ( struct V_1 * V_82 ,
T_6 V_120 ,
struct V_121 * V_122 )
{
int V_29 ;
T_6 V_123 = V_124 ;
T_5 V_125 = V_126 ;
if ( ! F_36 ( V_82 ) )
goto V_97;
for ( V_29 = 0 ; V_29 < V_102 ; ++ V_29 ) {
if ( V_120 & F_32 ( V_29 ) ) {
V_123 = V_103 [ V_29 ] . V_123 ;
V_125 = V_127 ;
break;
}
}
V_97:
F_37 ( V_122 , V_123 ) ;
V_122 -> V_125 = V_125 ;
}
static void F_38 ( T_6 V_100 , T_6 * V_104 )
{
* V_104 |= F_34 ( V_100 ) ;
* V_104 |= F_31 ( V_100 ) ;
* V_104 |= V_128 | V_129 ;
}
static void F_39 ( T_6 V_100 , T_5 V_130 ,
T_5 V_131 , T_6 * V_132 )
{
* V_132 |= F_33 ( V_100 ) ;
* V_132 |= V_130 ? V_133 : 0 ;
* V_132 |= ( V_130 ^ V_131 ) ? V_134 : 0 ;
}
static T_5 F_40 ( T_6 V_135 )
{
if ( V_135 & ( F_32 ( V_108 )
| F_32 ( V_110 )
| F_32 ( V_111 )
| F_32 ( V_112 ) ) ) {
return V_136 ;
}
if ( V_135 & ( F_32 ( V_109 )
| F_32 ( V_107 )
| F_32 ( V_137 ) ) ) {
return V_138 ;
}
if ( V_135 & ( F_32 ( V_117 )
| F_32 ( V_116 )
| F_32 ( V_115 )
| F_32 ( V_114 ) ) ) {
return V_139 ;
}
return V_140 ;
}
static void F_41 ( T_6 V_141 , T_6 * V_142 )
{
* V_142 = F_33 ( V_141 ) ;
}
static int F_42 ( struct V_1 * V_82 ,
struct V_121 * V_122 )
{
struct V_5 * V_6 = F_2 ( V_82 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_6 V_97 [ F_43 ( V_143 ) ] ;
T_6 V_100 ;
T_6 V_144 ;
T_6 V_141 ;
T_6 V_120 ;
int V_64 ;
V_64 = F_44 ( V_8 , V_97 , sizeof( V_97 ) , V_145 , 1 ) ;
if ( V_64 ) {
F_45 ( V_82 , L_15 ,
V_66 , V_64 ) ;
goto V_146;
}
V_100 = F_46 ( V_143 , V_97 , V_147 ) ;
V_144 = F_46 ( V_143 , V_97 , V_144 ) ;
V_120 = F_46 ( V_143 , V_97 , V_120 ) ;
V_141 = F_46 ( V_143 , V_97 , V_148 ) ;
V_122 -> V_104 = 0 ;
V_122 -> V_132 = 0 ;
F_38 ( V_100 , & V_122 -> V_104 ) ;
F_39 ( V_144 , 0 , 0 , & V_122 -> V_132 ) ;
F_35 ( V_82 , V_120 , V_122 ) ;
V_120 = V_120 ? V_120 : V_100 ;
V_122 -> V_149 = F_40 ( V_120 ) ;
F_41 ( V_141 , & V_122 -> V_142 ) ;
V_122 -> V_150 = V_151 ;
V_146:
return V_64 ;
}
static T_6 F_47 ( T_6 V_152 )
{
T_6 V_29 , V_153 = 0 ;
for ( V_29 = 0 ; V_29 < V_102 ; ++ V_29 ) {
if ( V_103 [ V_29 ] . V_106 & V_152 )
V_153 |= F_32 ( V_29 ) ;
}
return V_153 ;
}
static T_6 F_48 ( T_6 V_123 )
{
T_6 V_29 , V_154 = 0 ;
for ( V_29 = 0 ; V_29 < V_102 ; ++ V_29 ) {
if ( V_103 [ V_29 ] . V_123 == V_123 )
V_154 |= F_32 ( V_29 ) ;
}
return V_154 ;
}
static int F_49 ( struct V_1 * V_82 ,
struct V_121 * V_122 )
{
struct V_5 * V_6 = F_2 ( V_82 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_6 V_152 ;
T_6 V_123 ;
T_6 V_100 , V_144 ;
enum V_155 V_156 ;
int V_64 ;
V_123 = F_50 ( V_122 ) ;
V_152 = V_122 -> V_157 == V_158 ?
F_47 ( V_122 -> V_132 ) :
F_48 ( V_123 ) ;
V_64 = F_51 ( V_8 , & V_100 , V_145 ) ;
if ( V_64 ) {
F_45 ( V_82 , L_16 ,
V_66 , V_64 ) ;
goto V_97;
}
V_152 = V_152 & V_100 ;
if ( ! V_152 ) {
F_45 ( V_82 , L_17 ,
V_66 ) ;
V_64 = - V_67 ;
goto V_97;
}
V_64 = F_52 ( V_8 , & V_144 , V_145 ) ;
if ( V_64 ) {
F_45 ( V_82 , L_18 ,
V_66 , V_64 ) ;
goto V_97;
}
if ( V_152 == V_144 )
goto V_97;
F_53 ( V_8 , & V_156 ) ;
if ( V_156 == V_159 )
F_54 ( V_8 , V_160 ) ;
F_55 ( V_8 , V_152 , V_145 ) ;
if ( V_156 == V_159 )
F_54 ( V_8 , V_159 ) ;
V_97:
return V_64 ;
}
static T_6 F_56 ( struct V_1 * V_82 )
{
struct V_5 * V_6 = F_2 ( V_82 ) ;
return sizeof( V_6 -> V_21 . V_161 ) ;
}
static T_6 F_57 ( struct V_1 * V_82 )
{
return V_81 ;
}
static int F_58 ( struct V_1 * V_82 , T_6 * V_162 , T_5 * V_163 ,
T_5 * V_164 )
{
struct V_5 * V_6 = F_2 ( V_82 ) ;
if ( V_162 )
memcpy ( V_162 , V_6 -> V_21 . V_80 ,
sizeof( V_6 -> V_21 . V_80 ) ) ;
if ( V_163 )
memcpy ( V_163 , V_6 -> V_21 . V_161 ,
sizeof( V_6 -> V_21 . V_161 ) ) ;
if ( V_164 )
* V_164 = V_6 -> V_21 . V_165 ;
return 0 ;
}
static void F_59 ( struct V_5 * V_6 , void * V_166 , int V_167 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
void * V_168 = F_60 ( V_169 , V_166 , V_170 ) ;
int V_29 ;
F_61 ( V_169 , V_166 , V_171 . V_172 , 1 ) ;
F_62 ( V_168 , V_6 ) ;
for ( V_29 = 0 ; V_29 < V_173 ; V_29 ++ )
if ( F_63 ( V_29 ) )
F_64 ( V_8 , V_6 -> V_174 [ V_29 ] , V_166 , V_167 ) ;
}
static int F_65 ( struct V_1 * V_2 , const T_6 * V_162 ,
const T_5 * V_163 , const T_5 V_164 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_167 = F_66 ( V_169 ) ;
void * V_166 ;
if ( ( V_164 != V_175 ) &&
( V_164 != V_176 ) &&
( V_164 != V_177 ) )
return - V_67 ;
V_166 = F_67 ( V_167 ) ;
if ( ! V_166 )
return - V_178 ;
F_11 ( & V_6 -> V_43 ) ;
if ( V_162 ) {
memcpy ( V_6 -> V_21 . V_80 , V_162 ,
sizeof( V_6 -> V_21 . V_80 ) ) ;
F_68 ( V_6 , V_179 ) ;
}
if ( V_163 )
memcpy ( V_6 -> V_21 . V_161 , V_163 ,
sizeof( V_6 -> V_21 . V_161 ) ) ;
if ( V_164 != V_175 )
V_6 -> V_21 . V_165 = V_164 ;
F_59 ( V_6 , V_166 , V_167 ) ;
F_14 ( & V_6 -> V_43 ) ;
F_69 ( V_166 ) ;
return 0 ;
}
static int F_70 ( struct V_1 * V_82 ,
struct V_180 * V_181 , T_6 * V_182 )
{
struct V_5 * V_6 = F_2 ( V_82 ) ;
int V_64 = 0 ;
switch ( V_181 -> V_122 ) {
case V_183 :
V_181 -> V_28 = V_6 -> V_21 . V_22 ;
break;
default:
V_64 = - V_26 ;
break;
}
return V_64 ;
}
static int F_71 ( struct V_1 * V_2 ,
const struct V_184 * V_185 ,
void * V_28 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_64 = 0 ;
switch ( V_185 -> V_186 ) {
case V_187 :
* ( T_6 * ) V_28 = V_6 -> V_21 . V_188 ;
break;
default:
V_64 = - V_67 ;
break;
}
return V_64 ;
}
static int F_72 ( struct V_1 * V_2 ,
const struct V_184 * V_185 ,
const void * V_28 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
bool V_62 ;
T_6 V_189 ;
int V_64 = 0 ;
switch ( V_185 -> V_186 ) {
case V_187 :
V_189 = * ( T_6 * ) V_28 ;
if ( V_189 > F_73 ( V_8 ) ) {
V_64 = - V_67 ;
break;
}
F_11 ( & V_6 -> V_43 ) ;
V_62 = F_12 ( V_44 , & V_6 -> V_45 ) ;
if ( V_62 )
F_21 ( V_2 ) ;
V_6 -> V_21 . V_188 = V_189 ;
if ( V_62 )
V_64 = F_22 ( V_2 ) ;
F_14 ( & V_6 -> V_43 ) ;
break;
default:
V_64 = - V_67 ;
break;
}
return V_64 ;
}
static void F_74 ( struct V_1 * V_82 ,
struct V_190 * V_191 )
{
struct V_5 * V_6 = F_2 ( V_82 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_64 ;
V_64 = F_75 ( V_8 , & V_191 -> V_131 ,
& V_191 -> V_130 ) ;
if ( V_64 ) {
F_45 ( V_82 , L_19 ,
V_66 , V_64 ) ;
}
}
static int F_76 ( struct V_1 * V_82 ,
struct V_190 * V_191 )
{
struct V_5 * V_6 = F_2 ( V_82 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_64 ;
if ( V_191 -> V_157 )
return - V_67 ;
V_64 = F_77 ( V_8 ,
V_191 -> V_131 ? 1 : 0 ,
V_191 -> V_130 ? 1 : 0 ) ;
if ( V_64 ) {
F_45 ( V_82 , L_20 ,
V_66 , V_64 ) ;
}
return V_64 ;
}
static int F_78 ( struct V_1 * V_2 ,
struct V_192 * V_181 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_193 ;
V_193 = F_79 ( V_2 , V_181 ) ;
if ( V_193 )
return V_193 ;
V_181 -> V_194 = V_6 -> V_195 . V_196 ?
F_80 ( V_6 -> V_195 . V_196 ) : - 1 ;
if ( ! F_28 ( V_6 -> V_8 , V_197 ) )
return 0 ;
V_181 -> V_198 |= V_199 |
V_200 |
V_201 ;
V_181 -> V_202 = ( F_81 ( 1 ) << V_203 ) |
( F_81 ( 1 ) << V_204 ) ;
V_181 -> V_205 = ( F_81 ( 1 ) << V_206 ) |
( F_81 ( 1 ) << V_207 ) ;
return 0 ;
}
static T_7 F_82 ( struct V_7 * V_8 )
{
T_7 V_193 = 0 ;
if ( F_28 ( V_8 , V_208 ) )
V_193 |= V_209 ;
if ( F_28 ( V_8 , V_210 ) )
V_193 |= V_211 ;
if ( F_28 ( V_8 , V_212 ) )
V_193 |= V_213 ;
if ( F_28 ( V_8 , V_214 ) )
V_193 |= V_215 ;
if ( F_28 ( V_8 , V_216 ) )
V_193 |= V_217 ;
if ( F_28 ( V_8 , V_218 ) )
V_193 |= V_219 ;
if ( F_28 ( V_8 , V_220 ) )
V_193 |= V_221 ;
return V_193 ;
}
static T_7 F_83 ( T_5 V_222 )
{
T_7 V_193 = 0 ;
if ( V_222 & V_223 )
V_193 |= V_209 ;
if ( V_222 & V_224 )
V_193 |= V_211 ;
if ( V_222 & V_225 )
V_193 |= V_213 ;
if ( V_222 & V_226 )
V_193 |= V_215 ;
if ( V_222 & V_227 )
V_193 |= V_217 ;
if ( V_222 & V_228 )
V_193 |= V_219 ;
if ( V_222 & V_229 )
V_193 |= V_221 ;
return V_193 ;
}
static T_5 F_84 ( T_7 V_222 )
{
T_5 V_193 = 0 ;
if ( V_222 & V_209 )
V_193 |= V_223 ;
if ( V_222 & V_211 )
V_193 |= V_224 ;
if ( V_222 & V_213 )
V_193 |= V_225 ;
if ( V_222 & V_215 )
V_193 |= V_226 ;
if ( V_222 & V_217 )
V_193 |= V_227 ;
if ( V_222 & V_219 )
V_193 |= V_228 ;
if ( V_222 & V_221 )
V_193 |= V_229 ;
return V_193 ;
}
static void F_85 ( struct V_1 * V_82 ,
struct V_230 * V_231 )
{
struct V_5 * V_6 = F_2 ( V_82 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_5 V_232 ;
int V_64 ;
memset ( V_231 , 0 , sizeof( * V_231 ) ) ;
V_231 -> V_104 = F_82 ( V_8 ) ;
if ( ! V_231 -> V_104 )
return;
V_64 = F_86 ( V_8 , & V_232 ) ;
if ( V_64 )
return;
V_231 -> V_233 = F_83 ( V_232 ) ;
}
static int F_87 ( struct V_1 * V_82 , struct V_230 * V_231 )
{
struct V_5 * V_6 = F_2 ( V_82 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_7 V_234 = F_82 ( V_8 ) ;
T_6 V_232 ;
if ( ! V_234 )
return - V_86 ;
if ( V_231 -> V_233 & ~ V_234 )
return - V_67 ;
V_232 = F_84 ( V_231 -> V_233 ) ;
return F_88 ( V_8 , V_232 ) ;
}
