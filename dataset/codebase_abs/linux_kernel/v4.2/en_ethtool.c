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
return V_19 +
V_6 -> V_20 . V_21 * V_22 +
V_6 -> V_20 . V_21 * V_6 -> V_23 *
V_24 ;
default:
return - V_25 ;
}
}
static void F_9 ( struct V_1 * V_2 ,
T_1 V_26 , T_2 * V_27 )
{
int V_28 , V_29 , V_30 , V_31 = 0 ;
struct V_5 * V_6 = F_2 ( V_2 ) ;
switch ( V_26 ) {
case V_32 :
break;
case V_33 :
break;
case V_18 :
for ( V_28 = 0 ; V_28 < V_19 ; V_28 ++ )
strcpy ( V_27 + ( V_31 ++ ) * V_34 ,
V_35 [ V_28 ] ) ;
for ( V_28 = 0 ; V_28 < V_6 -> V_20 . V_21 ; V_28 ++ )
for ( V_29 = 0 ; V_29 < V_22 ; V_29 ++ )
sprintf ( V_27 + ( V_31 ++ ) * V_34 ,
L_4 , V_28 , V_36 [ V_29 ] ) ;
for ( V_28 = 0 ; V_28 < V_6 -> V_20 . V_21 ; V_28 ++ )
for ( V_30 = 0 ; V_30 < V_6 -> V_23 ; V_30 ++ )
for ( V_29 = 0 ; V_29 < V_24 ; V_29 ++ )
sprintf ( V_27 +
( V_31 ++ ) * V_34 ,
L_5 , V_28 , V_30 ,
V_37 [ V_29 ] ) ;
break;
}
}
static void F_10 ( struct V_1 * V_2 ,
struct V_38 * V_39 , T_3 * V_27 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_28 , V_29 , V_30 , V_31 = 0 ;
if ( ! V_27 )
return;
F_11 ( & V_6 -> V_40 ) ;
if ( F_12 ( V_41 , & V_6 -> V_42 ) )
F_13 ( V_6 ) ;
F_14 ( & V_6 -> V_40 ) ;
for ( V_28 = 0 ; V_28 < V_19 ; V_28 ++ )
V_27 [ V_31 ++ ] = ( ( T_3 * ) & V_6 -> V_39 . V_43 ) [ V_28 ] ;
for ( V_28 = 0 ; V_28 < V_6 -> V_20 . V_21 ; V_28 ++ )
for ( V_29 = 0 ; V_29 < V_22 ; V_29 ++ )
V_27 [ V_31 ++ ] = ! F_12 ( V_41 ,
& V_6 -> V_42 ) ? 0 :
( ( T_3 * ) & V_6 -> V_44 [ V_28 ] -> V_45 . V_39 ) [ V_29 ] ;
for ( V_28 = 0 ; V_28 < V_6 -> V_20 . V_21 ; V_28 ++ )
for ( V_30 = 0 ; V_30 < V_6 -> V_23 ; V_30 ++ )
for ( V_29 = 0 ; V_29 < V_24 ; V_29 ++ )
V_27 [ V_31 ++ ] = ! F_12 ( V_41 ,
& V_6 -> V_42 ) ? 0 :
( ( T_3 * ) & V_6 -> V_44 [ V_28 ] -> V_46 [ V_30 ] . V_39 ) [ V_29 ] ;
}
static void F_15 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
V_48 -> V_49 = 1 << V_50 ;
V_48 -> V_51 = 1 << V_52 ;
V_48 -> V_53 = 1 << V_6 -> V_20 . V_54 ;
V_48 -> V_55 = 1 << V_6 -> V_20 . V_56 ;
}
static int F_16 ( struct V_1 * V_2 ,
struct V_47 * V_48 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_57 V_58 ;
T_4 V_59 ;
T_5 V_54 ;
T_5 V_56 ;
int V_60 = 0 ;
if ( V_48 -> V_61 ) {
F_17 ( V_2 , L_6 ,
V_62 ) ;
return - V_63 ;
}
if ( V_48 -> V_64 ) {
F_17 ( V_2 , L_7 ,
V_62 ) ;
return - V_63 ;
}
if ( V_48 -> V_53 < ( 1 << V_65 ) ) {
F_17 ( V_2 , L_8 ,
V_62 , V_48 -> V_53 ,
1 << V_65 ) ;
return - V_63 ;
}
if ( V_48 -> V_53 > ( 1 << V_50 ) ) {
F_17 ( V_2 , L_9 ,
V_62 , V_48 -> V_53 ,
1 << V_50 ) ;
return - V_63 ;
}
if ( V_48 -> V_55 < ( 1 << V_66 ) ) {
F_17 ( V_2 , L_10 ,
V_62 , V_48 -> V_55 ,
1 << V_66 ) ;
return - V_63 ;
}
if ( V_48 -> V_55 > ( 1 << V_52 ) ) {
F_17 ( V_2 , L_11 ,
V_62 , V_48 -> V_55 ,
1 << V_52 ) ;
return - V_63 ;
}
V_54 = F_18 ( V_48 -> V_53 ) ;
V_56 = F_18 ( V_48 -> V_55 ) ;
V_59 = F_19 ( T_4 , V_48 -> V_53 - 1 ,
V_67 ) ;
if ( V_54 == V_6 -> V_20 . V_54 &&
V_56 == V_6 -> V_20 . V_56 &&
V_59 == V_6 -> V_20 . V_59 )
return 0 ;
F_11 ( & V_6 -> V_40 ) ;
V_58 = V_6 -> V_20 ;
V_58 . V_54 = V_54 ;
V_58 . V_56 = V_56 ;
V_58 . V_59 = V_59 ;
V_60 = F_20 ( V_6 , & V_58 ) ;
F_14 ( & V_6 -> V_40 ) ;
return V_60 ;
}
static void F_21 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_70 = V_6 -> V_8 -> V_6 . V_71 . V_72 ;
V_69 -> V_73 = V_70 ;
V_69 -> V_74 = V_6 -> V_20 . V_21 ;
}
static int F_22 ( struct V_1 * V_2 ,
struct V_68 * V_69 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_70 = V_6 -> V_8 -> V_6 . V_71 . V_72 ;
unsigned int V_75 = V_69 -> V_74 ;
struct V_57 V_58 ;
int V_60 = 0 ;
if ( ! V_75 ) {
F_17 ( V_2 , L_12 ,
V_62 ) ;
return - V_63 ;
}
if ( V_69 -> V_76 || V_69 -> V_77 ) {
F_17 ( V_2 , L_13 ,
V_62 ) ;
return - V_63 ;
}
if ( V_75 > V_70 ) {
F_17 ( V_2 , L_14 ,
V_62 , V_75 , V_70 ) ;
return - V_63 ;
}
if ( V_6 -> V_20 . V_21 == V_75 )
return 0 ;
F_11 ( & V_6 -> V_40 ) ;
V_58 = V_6 -> V_20 ;
V_58 . V_21 = V_75 ;
V_60 = F_20 ( V_6 , & V_58 ) ;
F_14 ( & V_6 -> V_40 ) ;
return V_60 ;
}
static int F_23 ( struct V_1 * V_78 ,
struct V_79 * V_80 )
{
struct V_5 * V_6 = F_2 ( V_78 ) ;
V_80 -> V_81 = V_6 -> V_20 . V_82 ;
V_80 -> V_83 = V_6 -> V_20 . V_84 ;
V_80 -> V_85 = V_6 -> V_20 . V_86 ;
V_80 -> V_87 = V_6 -> V_20 . V_88 ;
return 0 ;
}
static int F_24 ( struct V_1 * V_78 ,
struct V_79 * V_80 )
{
struct V_5 * V_6 = F_2 ( V_78 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
struct V_89 * V_90 ;
int V_30 ;
int V_28 ;
V_6 -> V_20 . V_86 = V_80 -> V_85 ;
V_6 -> V_20 . V_88 = V_80 -> V_87 ;
V_6 -> V_20 . V_82 = V_80 -> V_81 ;
V_6 -> V_20 . V_84 = V_80 -> V_83 ;
for ( V_28 = 0 ; V_28 < V_6 -> V_20 . V_21 ; ++ V_28 ) {
V_90 = V_6 -> V_44 [ V_28 ] ;
for ( V_30 = 0 ; V_30 < V_90 -> V_23 ; V_30 ++ ) {
F_25 ( V_8 ,
& V_90 -> V_46 [ V_30 ] . V_91 . V_92 ,
V_80 -> V_85 ,
V_80 -> V_87 ) ;
}
F_25 ( V_8 , & V_90 -> V_45 . V_91 . V_92 ,
V_80 -> V_81 ,
V_80 -> V_83 ) ;
}
return 0 ;
}
static T_6 F_26 ( T_6 V_93 )
{
int V_28 ;
T_6 V_94 = 0 ;
for ( V_28 = 0 ; V_28 < V_95 ; ++ V_28 ) {
if ( V_93 & F_27 ( V_28 ) )
V_94 |= V_96 [ V_28 ] . V_97 ;
}
return V_94 ;
}
static T_6 F_28 ( T_6 V_93 )
{
int V_28 ;
T_6 V_98 = 0 ;
for ( V_28 = 0 ; V_28 < V_95 ; ++ V_28 ) {
if ( V_93 & F_27 ( V_28 ) )
V_98 |= V_96 [ V_28 ] . V_99 ;
}
return V_98 ;
}
static T_6 F_29 ( T_6 V_93 )
{
if ( V_93 & ( F_27 ( V_100 )
| F_27 ( V_101 )
| F_27 ( V_102 )
| F_27 ( V_103 )
| F_27 ( V_104 )
| F_27 ( V_105 ) ) ) {
return V_106 ;
}
if ( V_93 & ( F_27 ( V_107 )
| F_27 ( V_108 )
| F_27 ( V_109 )
| F_27 ( V_110 )
| F_27 ( V_111 ) ) ) {
return V_112 ;
}
return 0 ;
}
static void F_30 ( struct V_1 * V_78 ,
T_6 V_113 ,
struct V_114 * V_115 )
{
int V_28 ;
T_6 V_116 = V_117 ;
T_5 V_118 = V_119 ;
if ( ! F_31 ( V_78 ) )
goto V_120;
for ( V_28 = 0 ; V_28 < V_95 ; ++ V_28 ) {
if ( V_113 & F_27 ( V_28 ) ) {
V_116 = V_96 [ V_28 ] . V_116 ;
V_118 = V_121 ;
break;
}
}
V_120:
F_32 ( V_115 , V_116 ) ;
V_115 -> V_118 = V_118 ;
}
static void F_33 ( T_6 V_93 , T_6 * V_97 )
{
* V_97 |= F_29 ( V_93 ) ;
* V_97 |= F_26 ( V_93 ) ;
* V_97 |= V_122 | V_123 ;
}
static void F_34 ( T_6 V_93 , T_5 V_124 ,
T_5 V_125 , T_6 * V_126 )
{
* V_126 |= F_28 ( V_93 ) ;
* V_126 |= V_124 ? V_127 : 0 ;
* V_126 |= ( V_124 ^ V_125 ) ? V_128 : 0 ;
}
static T_5 F_35 ( T_6 V_129 )
{
if ( V_129 & ( F_27 ( V_101 )
| F_27 ( V_103 )
| F_27 ( V_104 )
| F_27 ( V_105 ) ) ) {
return V_130 ;
}
if ( V_129 & ( F_27 ( V_102 )
| F_27 ( V_100 )
| F_27 ( V_131 ) ) ) {
return V_132 ;
}
if ( V_129 & ( F_27 ( V_110 )
| F_27 ( V_109 )
| F_27 ( V_108 )
| F_27 ( V_107 ) ) ) {
return V_133 ;
}
return V_134 ;
}
static void F_36 ( T_6 V_135 , T_6 * V_136 )
{
* V_136 = F_28 ( V_135 ) ;
}
static int F_37 ( struct V_1 * V_78 ,
struct V_114 * V_115 )
{
struct V_5 * V_6 = F_2 ( V_78 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_6 V_120 [ F_38 ( V_137 ) ] ;
T_6 V_93 ;
T_6 V_138 ;
T_6 V_135 ;
T_6 V_113 ;
int V_60 ;
V_60 = F_39 ( V_8 , V_120 , sizeof( V_120 ) , V_139 , 1 ) ;
if ( V_60 ) {
F_40 ( V_78 , L_15 ,
V_62 , V_60 ) ;
goto V_140;
}
V_93 = F_41 ( V_137 , V_120 , V_141 ) ;
V_138 = F_41 ( V_137 , V_120 , V_138 ) ;
V_113 = F_41 ( V_137 , V_120 , V_113 ) ;
V_135 = F_41 ( V_137 , V_120 , V_142 ) ;
V_115 -> V_97 = 0 ;
V_115 -> V_126 = 0 ;
F_33 ( V_93 , & V_115 -> V_97 ) ;
F_34 ( V_138 , 0 , 0 , & V_115 -> V_126 ) ;
F_30 ( V_78 , V_113 , V_115 ) ;
V_113 = V_113 ? V_113 : V_93 ;
V_115 -> V_143 = F_35 ( V_113 ) ;
F_36 ( V_135 , & V_115 -> V_136 ) ;
V_115 -> V_144 = V_145 ;
V_140:
return V_60 ;
}
static T_6 F_42 ( T_6 V_146 )
{
T_6 V_28 , V_147 = 0 ;
for ( V_28 = 0 ; V_28 < V_95 ; ++ V_28 ) {
if ( V_96 [ V_28 ] . V_99 & V_146 )
V_147 |= F_27 ( V_28 ) ;
}
return V_147 ;
}
static T_6 F_43 ( T_6 V_116 )
{
T_6 V_28 , V_148 = 0 ;
for ( V_28 = 0 ; V_28 < V_95 ; ++ V_28 ) {
if ( V_96 [ V_28 ] . V_116 == V_116 )
V_148 |= F_27 ( V_28 ) ;
}
return V_148 ;
}
static int F_44 ( struct V_1 * V_78 ,
struct V_114 * V_115 )
{
struct V_5 * V_6 = F_2 ( V_78 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
T_6 V_146 ;
T_6 V_116 ;
T_6 V_93 , V_138 ;
T_5 V_149 ;
int V_60 ;
V_116 = F_45 ( V_115 ) ;
V_146 = V_115 -> V_150 == V_151 ?
F_42 ( V_115 -> V_126 ) :
F_43 ( V_116 ) ;
V_60 = F_46 ( V_8 , & V_93 , V_139 ) ;
if ( V_60 ) {
F_40 ( V_78 , L_16 ,
V_62 , V_60 ) ;
goto V_120;
}
V_146 = V_146 & V_93 ;
if ( ! V_146 ) {
F_40 ( V_78 , L_17 ,
V_62 ) ;
V_60 = - V_63 ;
goto V_120;
}
V_60 = F_47 ( V_8 , & V_138 , V_139 ) ;
if ( V_60 ) {
F_40 ( V_78 , L_18 ,
V_62 , V_60 ) ;
goto V_120;
}
if ( V_146 == V_138 )
goto V_120;
V_60 = F_48 ( V_8 , V_146 , V_139 ) ;
if ( V_60 ) {
F_40 ( V_78 , L_19 ,
V_62 , V_60 ) ;
goto V_120;
}
V_60 = F_49 ( V_8 , & V_149 ) ;
if ( V_60 )
goto V_120;
if ( V_149 == V_152 )
return 0 ;
V_60 = F_50 ( V_8 , V_152 ) ;
if ( V_60 )
goto V_120;
V_60 = F_50 ( V_8 , V_153 ) ;
V_120:
return V_60 ;
}
