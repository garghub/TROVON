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
static unsigned long F_8 ( struct V_5 * V_6 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_17 ;
T_1 V_18 ;
int V_19 ;
V_19 = F_9 ( V_8 , & V_17 , & V_18 ) ;
return V_19 ? 0 : V_17 | V_18 ;
}
static int F_10 ( struct V_1 * V_2 , int V_20 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_20 ) {
case V_21 :
return V_22 +
F_11 ( V_6 ) +
V_23 + V_24 +
F_12 ( V_6 ) +
F_13 ( V_6 ) +
F_14 ( V_6 ) ;
default:
return - V_25 ;
}
}
static void F_15 ( struct V_5 * V_6 , T_2 * V_26 )
{
int V_27 , V_28 , V_29 , V_30 , V_31 = 0 ;
unsigned long V_32 ;
for ( V_27 = 0 ; V_27 < V_22 ; V_27 ++ )
strcpy ( V_26 + ( V_31 ++ ) * V_33 , V_34 [ V_27 ] . V_35 ) ;
for ( V_27 = 0 ; V_27 < F_11 ( V_6 ) ; V_27 ++ )
strcpy ( V_26 + ( V_31 ++ ) * V_33 , V_36 [ V_27 ] . V_35 ) ;
for ( V_27 = 0 ; V_27 < V_23 ; V_27 ++ )
strcpy ( V_26 + ( V_31 ++ ) * V_33 ,
V_37 [ V_27 ] . V_35 ) ;
for ( V_27 = 0 ; V_27 < V_38 ; V_27 ++ )
strcpy ( V_26 + ( V_31 ++ ) * V_33 ,
V_39 [ V_27 ] . V_35 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ )
strcpy ( V_26 + ( V_31 ++ ) * V_33 ,
V_41 [ V_27 ] . V_35 ) ;
for ( V_27 = 0 ; V_27 < V_42 ; V_27 ++ )
strcpy ( V_26 + ( V_31 ++ ) * V_33 ,
V_43 [ V_27 ] . V_35 ) ;
for ( V_30 = 0 ; V_30 < V_44 ; V_30 ++ ) {
for ( V_27 = 0 ; V_27 < V_45 ; V_27 ++ )
sprintf ( V_26 + ( V_31 ++ ) * V_33 ,
V_46 [ V_27 ] . V_35 , V_30 ) ;
}
V_32 = F_8 ( V_6 ) ;
F_16 (prio, &pfc_combined, NUM_PPORT_PRIO) {
for ( V_27 = 0 ; V_27 < V_47 ; V_27 ++ ) {
sprintf ( V_26 + ( V_31 ++ ) * V_33 ,
V_48 [ V_27 ] . V_35 , V_30 ) ;
}
}
if ( ! F_17 ( V_49 , & V_6 -> V_50 ) )
return;
for ( V_27 = 0 ; V_27 < V_6 -> V_51 . V_52 ; V_27 ++ )
for ( V_28 = 0 ; V_28 < V_53 ; V_28 ++ )
sprintf ( V_26 + ( V_31 ++ ) * V_33 ,
V_54 [ V_28 ] . V_35 , V_27 ) ;
for ( V_29 = 0 ; V_29 < V_6 -> V_51 . V_55 ; V_29 ++ )
for ( V_27 = 0 ; V_27 < V_6 -> V_51 . V_52 ; V_27 ++ )
for ( V_28 = 0 ; V_28 < V_56 ; V_28 ++ )
sprintf ( V_26 + ( V_31 ++ ) * V_33 ,
V_57 [ V_28 ] . V_35 ,
V_6 -> V_58 [ V_27 ] [ V_29 ] ) ;
}
static void F_18 ( struct V_1 * V_2 ,
T_3 V_59 , T_2 * V_26 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_59 ) {
case V_60 :
break;
case V_61 :
break;
case V_21 :
F_15 ( V_6 , V_26 ) ;
break;
}
}
static void F_19 ( struct V_1 * V_2 ,
struct V_62 * V_63 , T_4 * V_26 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_27 , V_28 , V_29 , V_30 , V_31 = 0 ;
unsigned long V_32 ;
if ( ! V_26 )
return;
F_20 ( & V_6 -> V_64 ) ;
if ( F_17 ( V_49 , & V_6 -> V_50 ) )
F_21 ( V_6 ) ;
F_22 ( & V_6 -> V_64 ) ;
for ( V_27 = 0 ; V_27 < V_22 ; V_27 ++ )
V_26 [ V_31 ++ ] = F_23 ( & V_6 -> V_63 . V_65 ,
V_34 , V_27 ) ;
for ( V_27 = 0 ; V_27 < F_11 ( V_6 ) ; V_27 ++ )
V_26 [ V_31 ++ ] = F_24 ( & V_6 -> V_63 . V_66 ,
V_36 , V_27 ) ;
for ( V_27 = 0 ; V_27 < V_23 ; V_27 ++ )
V_26 [ V_31 ++ ] = F_25 ( V_6 -> V_63 . V_67 . V_68 ,
V_37 , V_27 ) ;
for ( V_27 = 0 ; V_27 < V_38 ; V_27 ++ )
V_26 [ V_31 ++ ] = F_25 ( & V_6 -> V_63 . V_69 . V_70 ,
V_39 , V_27 ) ;
for ( V_27 = 0 ; V_27 < V_40 ; V_27 ++ )
V_26 [ V_31 ++ ] = F_25 ( & V_6 -> V_63 . V_69 . V_71 ,
V_41 , V_27 ) ;
for ( V_27 = 0 ; V_27 < V_42 ; V_27 ++ )
V_26 [ V_31 ++ ] = F_25 ( & V_6 -> V_63 . V_69 . V_72 ,
V_43 , V_27 ) ;
for ( V_30 = 0 ; V_30 < V_44 ; V_30 ++ ) {
for ( V_27 = 0 ; V_27 < V_45 ; V_27 ++ )
V_26 [ V_31 ++ ] = F_25 ( & V_6 -> V_63 . V_69 . V_73 [ V_30 ] ,
V_46 , V_27 ) ;
}
V_32 = F_8 ( V_6 ) ;
F_16 (prio, &pfc_combined, NUM_PPORT_PRIO) {
for ( V_27 = 0 ; V_27 < V_47 ; V_27 ++ ) {
V_26 [ V_31 ++ ] = F_25 ( & V_6 -> V_63 . V_69 . V_73 [ V_30 ] ,
V_48 , V_27 ) ;
}
}
if ( ! F_17 ( V_49 , & V_6 -> V_50 ) )
return;
for ( V_27 = 0 ; V_27 < V_6 -> V_51 . V_52 ; V_27 ++ )
for ( V_28 = 0 ; V_28 < V_53 ; V_28 ++ )
V_26 [ V_31 ++ ] =
F_23 ( & V_6 -> V_74 [ V_27 ] -> V_75 . V_63 ,
V_54 , V_28 ) ;
for ( V_29 = 0 ; V_29 < V_6 -> V_51 . V_55 ; V_29 ++ )
for ( V_27 = 0 ; V_27 < V_6 -> V_51 . V_52 ; V_27 ++ )
for ( V_28 = 0 ; V_28 < V_56 ; V_28 ++ )
V_26 [ V_31 ++ ] = F_23 ( & V_6 -> V_74 [ V_27 ] -> V_76 [ V_29 ] . V_63 ,
V_57 , V_28 ) ;
}
static void F_26 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_79 = V_6 -> V_51 . V_79 ;
V_78 -> V_80 = 1 << F_27 ( V_79 ) ;
V_78 -> V_81 = 1 << V_82 ;
V_78 -> V_83 = 1 << V_6 -> V_51 . V_84 ;
V_78 -> V_85 = 1 << V_6 -> V_51 . V_86 ;
}
static int F_28 ( struct V_1 * V_2 ,
struct V_77 * V_78 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
bool V_87 ;
int V_79 = V_6 -> V_51 . V_79 ;
T_5 V_88 ;
T_1 V_84 ;
T_1 V_86 ;
int V_19 = 0 ;
if ( V_78 -> V_89 ) {
F_29 ( V_2 , L_4 ,
V_90 ) ;
return - V_91 ;
}
if ( V_78 -> V_92 ) {
F_29 ( V_2 , L_5 ,
V_90 ) ;
return - V_91 ;
}
if ( V_78 -> V_83 < ( 1 << F_30 ( V_79 ) ) ) {
F_29 ( V_2 , L_6 ,
V_90 , V_78 -> V_83 ,
1 << F_30 ( V_79 ) ) ;
return - V_91 ;
}
if ( V_78 -> V_83 > ( 1 << F_27 ( V_79 ) ) ) {
F_29 ( V_2 , L_7 ,
V_90 , V_78 -> V_83 ,
1 << F_27 ( V_79 ) ) ;
return - V_91 ;
}
if ( V_78 -> V_85 < ( 1 << V_93 ) ) {
F_29 ( V_2 , L_8 ,
V_90 , V_78 -> V_85 ,
1 << V_93 ) ;
return - V_91 ;
}
if ( V_78 -> V_85 > ( 1 << V_82 ) ) {
F_29 ( V_2 , L_9 ,
V_90 , V_78 -> V_85 ,
1 << V_82 ) ;
return - V_91 ;
}
V_84 = F_31 ( V_78 -> V_83 ) ;
V_86 = F_31 ( V_78 -> V_85 ) ;
V_88 = F_32 ( V_79 , V_78 -> V_83 ) ;
if ( V_84 == V_6 -> V_51 . V_84 &&
V_86 == V_6 -> V_51 . V_86 &&
V_88 == V_6 -> V_51 . V_88 )
return 0 ;
F_20 ( & V_6 -> V_64 ) ;
V_87 = F_17 ( V_49 , & V_6 -> V_50 ) ;
if ( V_87 )
F_33 ( V_2 ) ;
V_6 -> V_51 . V_84 = V_84 ;
V_6 -> V_51 . V_86 = V_86 ;
V_6 -> V_51 . V_88 = V_88 ;
if ( V_87 )
V_19 = F_34 ( V_2 ) ;
F_22 ( & V_6 -> V_64 ) ;
return V_19 ;
}
static void F_35 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_95 -> V_96 = F_36 ( V_6 -> V_8 ) ;
V_95 -> V_97 = V_6 -> V_51 . V_52 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_94 * V_95 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_98 = F_36 ( V_6 -> V_8 ) ;
unsigned int V_99 = V_95 -> V_97 ;
bool V_100 ;
bool V_87 ;
int V_19 = 0 ;
if ( ! V_99 ) {
F_29 ( V_2 , L_10 ,
V_90 ) ;
return - V_91 ;
}
if ( V_95 -> V_101 || V_95 -> V_102 ) {
F_29 ( V_2 , L_11 ,
V_90 ) ;
return - V_91 ;
}
if ( V_99 > V_98 ) {
F_29 ( V_2 , L_12 ,
V_90 , V_99 , V_98 ) ;
return - V_91 ;
}
if ( V_6 -> V_51 . V_52 == V_99 )
return 0 ;
F_20 ( & V_6 -> V_64 ) ;
V_87 = F_17 ( V_49 , & V_6 -> V_50 ) ;
if ( V_87 )
F_33 ( V_2 ) ;
V_100 = V_2 -> V_103 & V_104 ;
if ( V_100 )
F_38 ( V_6 ) ;
V_6 -> V_51 . V_52 = V_99 ;
F_39 ( V_6 -> V_8 , V_6 -> V_51 . V_105 ,
V_106 , V_99 ) ;
if ( V_87 )
V_19 = F_34 ( V_2 ) ;
if ( V_19 )
goto V_107;
if ( V_100 ) {
V_19 = F_40 ( V_6 ) ;
if ( V_19 )
F_41 ( V_2 , L_13 ,
V_90 , V_19 ) ;
}
V_107:
F_22 ( & V_6 -> V_64 ) ;
return V_19 ;
}
static int F_42 ( struct V_1 * V_108 ,
struct V_109 * V_110 )
{
struct V_5 * V_6 = F_2 ( V_108 ) ;
if ( ! F_43 ( V_6 -> V_8 , V_111 ) )
return - V_112 ;
V_110 -> V_113 = V_6 -> V_51 . V_114 ;
V_110 -> V_115 = V_6 -> V_51 . V_116 ;
V_110 -> V_117 = V_6 -> V_51 . V_118 ;
V_110 -> V_119 = V_6 -> V_51 . V_120 ;
return 0 ;
}
static int F_44 ( struct V_1 * V_108 ,
struct V_109 * V_110 )
{
struct V_5 * V_6 = F_2 ( V_108 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_121 * V_122 ;
int V_29 ;
int V_27 ;
if ( ! F_43 ( V_8 , V_111 ) )
return - V_112 ;
F_20 ( & V_6 -> V_64 ) ;
V_6 -> V_51 . V_118 = V_110 -> V_117 ;
V_6 -> V_51 . V_120 = V_110 -> V_119 ;
V_6 -> V_51 . V_114 = V_110 -> V_113 ;
V_6 -> V_51 . V_116 = V_110 -> V_115 ;
if ( ! F_17 ( V_49 , & V_6 -> V_50 ) )
goto V_107;
for ( V_27 = 0 ; V_27 < V_6 -> V_51 . V_52 ; ++ V_27 ) {
V_122 = V_6 -> V_74 [ V_27 ] ;
for ( V_29 = 0 ; V_29 < V_122 -> V_55 ; V_29 ++ ) {
F_45 ( V_8 ,
& V_122 -> V_76 [ V_29 ] . V_123 . V_124 ,
V_110 -> V_117 ,
V_110 -> V_119 ) ;
}
F_45 ( V_8 , & V_122 -> V_75 . V_123 . V_124 ,
V_110 -> V_113 ,
V_110 -> V_115 ) ;
}
V_107:
F_22 ( & V_6 -> V_64 ) ;
return 0 ;
}
static T_6 F_46 ( T_6 V_125 )
{
int V_27 ;
T_6 V_126 = 0 ;
for ( V_27 = 0 ; V_27 < V_127 ; ++ V_27 ) {
if ( V_125 & F_47 ( V_27 ) )
V_126 |= V_128 [ V_27 ] . V_129 ;
}
return V_126 ;
}
static T_6 F_48 ( T_6 V_125 )
{
int V_27 ;
T_6 V_130 = 0 ;
for ( V_27 = 0 ; V_27 < V_127 ; ++ V_27 ) {
if ( V_125 & F_47 ( V_27 ) )
V_130 |= V_128 [ V_27 ] . V_131 ;
}
return V_130 ;
}
static T_6 F_49 ( T_6 V_125 )
{
if ( V_125 & ( F_47 ( V_132 )
| F_47 ( V_133 )
| F_47 ( V_134 )
| F_47 ( V_135 )
| F_47 ( V_136 )
| F_47 ( V_137 ) ) ) {
return V_138 ;
}
if ( V_125 & ( F_47 ( V_139 )
| F_47 ( V_140 )
| F_47 ( V_141 )
| F_47 ( V_142 )
| F_47 ( V_143 ) ) ) {
return V_144 ;
}
return 0 ;
}
int F_50 ( struct V_7 * V_8 , T_6 * V_145 )
{
T_6 V_146 = 0 ;
T_6 V_147 ;
int V_19 ;
int V_27 ;
V_19 = F_51 ( V_8 , & V_147 , V_148 ) ;
if ( V_19 )
return V_19 ;
for ( V_27 = 0 ; V_27 < V_127 ; ++ V_27 )
if ( V_147 & F_47 ( V_27 ) )
V_146 = F_52 ( V_146 , V_128 [ V_27 ] . V_145 ) ;
* V_145 = V_146 ;
return 0 ;
}
static void F_53 ( struct V_1 * V_108 ,
T_6 V_149 ,
struct V_150 * V_151 )
{
int V_27 ;
T_6 V_145 = V_152 ;
T_1 V_153 = V_154 ;
if ( ! F_54 ( V_108 ) )
goto V_107;
for ( V_27 = 0 ; V_27 < V_127 ; ++ V_27 ) {
if ( V_149 & F_47 ( V_27 ) ) {
V_145 = V_128 [ V_27 ] . V_145 ;
V_153 = V_155 ;
break;
}
}
V_107:
F_55 ( V_151 , V_145 ) ;
V_151 -> V_153 = V_153 ;
}
static void F_56 ( T_6 V_125 , T_6 * V_129 )
{
* V_129 |= F_49 ( V_125 ) ;
* V_129 |= F_46 ( V_125 ) ;
* V_129 |= V_156 | V_157 ;
}
static void F_57 ( T_6 V_125 , T_1 V_158 ,
T_1 V_159 , T_6 * V_160 )
{
* V_160 |= F_48 ( V_125 ) ;
* V_160 |= V_158 ? V_161 : 0 ;
* V_160 |= ( V_158 ^ V_159 ) ? V_162 : 0 ;
}
static T_1 F_58 ( T_6 V_163 )
{
if ( V_163 & ( F_47 ( V_133 )
| F_47 ( V_135 )
| F_47 ( V_136 )
| F_47 ( V_137 ) ) ) {
return V_164 ;
}
if ( V_163 & ( F_47 ( V_134 )
| F_47 ( V_132 )
| F_47 ( V_165 ) ) ) {
return V_166 ;
}
if ( V_163 & ( F_47 ( V_142 )
| F_47 ( V_141 )
| F_47 ( V_140 )
| F_47 ( V_139 ) ) ) {
return V_167 ;
}
return V_168 ;
}
static void F_59 ( T_6 V_169 , T_6 * V_170 )
{
* V_170 = F_48 ( V_169 ) ;
}
static int F_60 ( struct V_1 * V_108 ,
struct V_150 * V_151 )
{
struct V_5 * V_6 = F_2 ( V_108 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_6 V_107 [ F_61 ( V_171 ) ] ;
T_6 V_125 ;
T_6 V_172 ;
T_6 V_169 ;
T_6 V_149 ;
int V_19 ;
V_19 = F_62 ( V_8 , V_107 , sizeof( V_107 ) , V_148 , 1 ) ;
if ( V_19 ) {
F_41 ( V_108 , L_14 ,
V_90 , V_19 ) ;
goto V_173;
}
V_125 = F_63 ( V_171 , V_107 , V_174 ) ;
V_172 = F_63 ( V_171 , V_107 , V_172 ) ;
V_149 = F_63 ( V_171 , V_107 , V_149 ) ;
V_169 = F_63 ( V_171 , V_107 , V_175 ) ;
V_151 -> V_129 = 0 ;
V_151 -> V_160 = 0 ;
F_56 ( V_125 , & V_151 -> V_129 ) ;
F_57 ( V_172 , 0 , 0 , & V_151 -> V_160 ) ;
F_53 ( V_108 , V_149 , V_151 ) ;
V_149 = V_149 ? V_149 : V_125 ;
V_151 -> V_176 = F_58 ( V_149 ) ;
F_59 ( V_169 , & V_151 -> V_170 ) ;
V_151 -> V_177 = V_178 ;
V_173:
return V_19 ;
}
static T_6 F_64 ( T_6 V_179 )
{
T_6 V_27 , V_180 = 0 ;
for ( V_27 = 0 ; V_27 < V_127 ; ++ V_27 ) {
if ( V_128 [ V_27 ] . V_131 & V_179 )
V_180 |= F_47 ( V_27 ) ;
}
return V_180 ;
}
static T_6 F_65 ( T_6 V_145 )
{
T_6 V_27 , V_181 = 0 ;
for ( V_27 = 0 ; V_27 < V_127 ; ++ V_27 ) {
if ( V_128 [ V_27 ] . V_145 == V_145 )
V_181 |= F_47 ( V_27 ) ;
}
return V_181 ;
}
static int F_66 ( struct V_1 * V_108 ,
struct V_150 * V_151 )
{
struct V_5 * V_6 = F_2 ( V_108 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_6 V_179 ;
T_6 V_145 ;
T_6 V_125 , V_172 ;
enum V_182 V_183 ;
int V_19 ;
V_145 = F_67 ( V_151 ) ;
V_179 = V_151 -> V_184 == V_185 ?
F_64 ( V_151 -> V_160 ) :
F_65 ( V_145 ) ;
V_19 = F_51 ( V_8 , & V_125 , V_148 ) ;
if ( V_19 ) {
F_41 ( V_108 , L_15 ,
V_90 , V_19 ) ;
goto V_107;
}
V_179 = V_179 & V_125 ;
if ( ! V_179 ) {
F_41 ( V_108 , L_16 ,
V_90 ) ;
V_19 = - V_91 ;
goto V_107;
}
V_19 = F_68 ( V_8 , & V_172 , V_148 ) ;
if ( V_19 ) {
F_41 ( V_108 , L_17 ,
V_90 , V_19 ) ;
goto V_107;
}
if ( V_179 == V_172 )
goto V_107;
F_69 ( V_8 , & V_183 ) ;
if ( V_183 == V_186 )
F_70 ( V_8 , V_187 ) ;
F_71 ( V_8 , V_179 , V_148 ) ;
if ( V_183 == V_186 )
F_70 ( V_8 , V_186 ) ;
V_107:
return V_19 ;
}
static T_6 F_72 ( struct V_1 * V_108 )
{
struct V_5 * V_6 = F_2 ( V_108 ) ;
return sizeof( V_6 -> V_51 . V_188 ) ;
}
static T_6 F_73 ( struct V_1 * V_108 )
{
return V_106 ;
}
static int F_74 ( struct V_1 * V_108 , T_6 * V_189 , T_1 * V_190 ,
T_1 * V_191 )
{
struct V_5 * V_6 = F_2 ( V_108 ) ;
if ( V_189 )
memcpy ( V_189 , V_6 -> V_51 . V_105 ,
sizeof( V_6 -> V_51 . V_105 ) ) ;
if ( V_190 )
memcpy ( V_190 , V_6 -> V_51 . V_188 ,
sizeof( V_6 -> V_51 . V_188 ) ) ;
if ( V_191 )
* V_191 = V_6 -> V_51 . V_192 ;
return 0 ;
}
static void F_75 ( struct V_5 * V_6 , void * V_193 , int V_194 )
{
struct V_7 * V_8 = V_6 -> V_8 ;
void * V_195 = F_76 ( V_196 , V_193 , V_197 ) ;
int V_27 ;
F_77 ( V_196 , V_193 , V_198 . V_199 , 1 ) ;
F_78 ( V_195 , V_6 ) ;
for ( V_27 = 0 ; V_27 < V_200 ; V_27 ++ )
F_79 ( V_8 , V_6 -> V_201 [ V_27 ] , V_193 , V_194 ) ;
}
static int F_80 ( struct V_1 * V_2 , const T_6 * V_189 ,
const T_1 * V_190 , const T_1 V_191 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_194 = F_81 ( V_196 ) ;
void * V_193 ;
if ( ( V_191 != V_202 ) &&
( V_191 != V_203 ) &&
( V_191 != V_204 ) )
return - V_91 ;
V_193 = F_82 ( V_194 ) ;
if ( ! V_193 )
return - V_205 ;
F_20 ( & V_6 -> V_64 ) ;
if ( V_189 ) {
T_6 V_206 = V_6 -> V_207 ;
memcpy ( V_6 -> V_51 . V_105 , V_189 ,
sizeof( V_6 -> V_51 . V_105 ) ) ;
F_83 ( V_6 , V_206 , V_106 , 0 ) ;
}
if ( V_190 )
memcpy ( V_6 -> V_51 . V_188 , V_190 ,
sizeof( V_6 -> V_51 . V_188 ) ) ;
if ( V_191 != V_202 )
V_6 -> V_51 . V_192 = V_191 ;
F_75 ( V_6 , V_193 , V_194 ) ;
F_22 ( & V_6 -> V_64 ) ;
F_84 ( V_193 ) ;
return 0 ;
}
static int F_85 ( struct V_1 * V_108 ,
struct V_208 * V_209 , T_6 * V_210 )
{
struct V_5 * V_6 = F_2 ( V_108 ) ;
int V_19 = 0 ;
switch ( V_209 -> V_151 ) {
case V_211 :
V_209 -> V_26 = V_6 -> V_51 . V_52 ;
break;
default:
V_19 = - V_25 ;
break;
}
return V_19 ;
}
static int F_86 ( struct V_1 * V_2 ,
const struct V_212 * V_213 ,
void * V_26 )
{
const struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_19 = 0 ;
switch ( V_213 -> V_214 ) {
case V_215 :
* ( T_6 * ) V_26 = V_6 -> V_51 . V_216 ;
break;
default:
V_19 = - V_91 ;
break;
}
return V_19 ;
}
static int F_87 ( struct V_1 * V_2 ,
const struct V_212 * V_213 ,
const void * V_26 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
bool V_87 ;
T_6 V_217 ;
int V_19 = 0 ;
switch ( V_213 -> V_214 ) {
case V_215 :
V_217 = * ( T_6 * ) V_26 ;
if ( V_217 > F_88 ( V_8 ) ) {
V_19 = - V_91 ;
break;
}
F_20 ( & V_6 -> V_64 ) ;
V_87 = F_17 ( V_49 , & V_6 -> V_50 ) ;
if ( V_87 )
F_33 ( V_2 ) ;
V_6 -> V_51 . V_216 = V_217 ;
if ( V_87 )
V_19 = F_34 ( V_2 ) ;
F_22 ( & V_6 -> V_64 ) ;
break;
default:
V_19 = - V_91 ;
break;
}
return V_19 ;
}
static void F_89 ( struct V_1 * V_108 ,
struct V_218 * V_219 )
{
struct V_5 * V_6 = F_2 ( V_108 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_19 ;
V_19 = F_90 ( V_8 , & V_219 -> V_159 ,
& V_219 -> V_158 ) ;
if ( V_19 ) {
F_41 ( V_108 , L_18 ,
V_90 , V_19 ) ;
}
}
static int F_91 ( struct V_1 * V_108 ,
struct V_218 * V_219 )
{
struct V_5 * V_6 = F_2 ( V_108 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_19 ;
if ( V_219 -> V_184 )
return - V_91 ;
V_19 = F_92 ( V_8 ,
V_219 -> V_159 ? 1 : 0 ,
V_219 -> V_158 ? 1 : 0 ) ;
if ( V_19 ) {
F_41 ( V_108 , L_19 ,
V_90 , V_19 ) ;
}
return V_19 ;
}
static int F_93 ( struct V_1 * V_2 ,
struct V_220 * V_209 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_221 ;
V_221 = F_94 ( V_2 , V_209 ) ;
if ( V_221 )
return V_221 ;
V_209 -> V_222 = V_6 -> V_223 . V_224 ?
F_95 ( V_6 -> V_223 . V_224 ) : - 1 ;
if ( ! F_43 ( V_6 -> V_8 , V_225 ) )
return 0 ;
V_209 -> V_226 |= V_227 |
V_228 |
V_229 ;
V_209 -> V_230 = ( F_96 ( 1 ) << V_231 ) |
( F_96 ( 1 ) << V_232 ) ;
V_209 -> V_233 = ( F_96 ( 1 ) << V_234 ) |
( F_96 ( 1 ) << V_235 ) ;
return 0 ;
}
static T_7 F_97 ( struct V_7 * V_8 )
{
T_7 V_221 = 0 ;
if ( F_43 ( V_8 , V_236 ) )
V_221 |= V_237 ;
if ( F_43 ( V_8 , V_238 ) )
V_221 |= V_239 ;
if ( F_43 ( V_8 , V_240 ) )
V_221 |= V_241 ;
if ( F_43 ( V_8 , V_242 ) )
V_221 |= V_243 ;
if ( F_43 ( V_8 , V_244 ) )
V_221 |= V_245 ;
if ( F_43 ( V_8 , V_246 ) )
V_221 |= V_247 ;
if ( F_43 ( V_8 , V_248 ) )
V_221 |= V_249 ;
return V_221 ;
}
static T_7 F_98 ( T_1 V_250 )
{
T_7 V_221 = 0 ;
if ( V_250 & V_251 )
V_221 |= V_237 ;
if ( V_250 & V_252 )
V_221 |= V_239 ;
if ( V_250 & V_253 )
V_221 |= V_241 ;
if ( V_250 & V_254 )
V_221 |= V_243 ;
if ( V_250 & V_255 )
V_221 |= V_245 ;
if ( V_250 & V_256 )
V_221 |= V_247 ;
if ( V_250 & V_257 )
V_221 |= V_249 ;
return V_221 ;
}
static T_1 F_99 ( T_7 V_250 )
{
T_1 V_221 = 0 ;
if ( V_250 & V_237 )
V_221 |= V_251 ;
if ( V_250 & V_239 )
V_221 |= V_252 ;
if ( V_250 & V_241 )
V_221 |= V_253 ;
if ( V_250 & V_243 )
V_221 |= V_254 ;
if ( V_250 & V_245 )
V_221 |= V_255 ;
if ( V_250 & V_247 )
V_221 |= V_256 ;
if ( V_250 & V_249 )
V_221 |= V_257 ;
return V_221 ;
}
static void F_100 ( struct V_1 * V_108 ,
struct V_258 * V_259 )
{
struct V_5 * V_6 = F_2 ( V_108 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_1 V_260 ;
int V_19 ;
memset ( V_259 , 0 , sizeof( * V_259 ) ) ;
V_259 -> V_129 = F_97 ( V_8 ) ;
if ( ! V_259 -> V_129 )
return;
V_19 = F_101 ( V_8 , & V_260 ) ;
if ( V_19 )
return;
V_259 -> V_261 = F_98 ( V_260 ) ;
}
static int F_102 ( struct V_1 * V_108 , struct V_258 * V_259 )
{
struct V_5 * V_6 = F_2 ( V_108 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_7 V_262 = F_97 ( V_8 ) ;
T_6 V_260 ;
if ( ! V_262 )
return - V_112 ;
if ( V_259 -> V_261 & ~ V_262 )
return - V_91 ;
V_260 = F_99 ( V_259 -> V_261 ) ;
return F_103 ( V_8 , V_260 ) ;
}
static int F_104 ( struct V_1 * V_2 ,
enum V_263 V_50 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_5 V_264 ;
if ( ! F_43 ( V_8 , V_265 ) )
return - V_25 ;
switch ( V_50 ) {
case V_266 :
V_264 = V_267 ;
break;
case V_268 :
V_264 = V_269 ;
break;
default:
return - V_25 ;
}
return F_105 ( V_8 , V_264 ) ;
}
static int F_106 ( struct V_1 * V_108 ,
struct V_270 * V_271 )
{
struct V_5 * V_6 = F_2 ( V_108 ) ;
struct V_7 * V_2 = V_6 -> V_8 ;
int V_272 = 0 ;
T_1 V_26 [ 4 ] ;
V_272 = F_107 ( V_2 , 0 , 2 , V_26 ) ;
if ( V_272 < 2 )
return - V_273 ;
switch ( V_26 [ 0 ] ) {
case V_274 :
V_271 -> type = V_275 ;
V_271 -> V_276 = V_277 ;
break;
case V_278 :
case V_279 :
if ( V_26 [ 0 ] == V_279 || V_26 [ 1 ] >= 0x3 ) {
V_271 -> type = V_280 ;
V_271 -> V_276 = V_281 ;
} else {
V_271 -> type = V_275 ;
V_271 -> V_276 = V_277 ;
}
break;
case V_282 :
V_271 -> type = V_283 ;
V_271 -> V_276 = V_284 ;
break;
default:
F_41 ( V_6 -> V_108 , L_20 ,
V_90 , V_26 [ 0 ] ) ;
return - V_91 ;
}
return 0 ;
}
static int F_108 ( struct V_1 * V_108 ,
struct V_285 * V_286 ,
T_1 * V_26 )
{
struct V_5 * V_6 = F_2 ( V_108 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
int V_287 = V_286 -> V_287 ;
int V_272 ;
int V_27 = 0 ;
if ( ! V_286 -> V_288 )
return - V_91 ;
memset ( V_26 , 0 , V_286 -> V_288 ) ;
while ( V_27 < V_286 -> V_288 ) {
V_272 = F_107 ( V_8 , V_287 , V_286 -> V_288 - V_27 ,
V_26 + V_27 ) ;
if ( ! V_272 )
return 0 ;
if ( V_272 < 0 ) {
F_41 ( V_6 -> V_108 , L_21 ,
V_90 , V_272 ) ;
return 0 ;
}
V_27 += V_272 ;
V_287 += V_272 ;
}
return 0 ;
}
