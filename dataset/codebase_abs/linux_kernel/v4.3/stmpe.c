static int F_1 ( struct V_1 * V_1 , unsigned int V_2 )
{
return V_1 -> V_3 -> V_4 ( V_1 , V_2 , true ) ;
}
static int F_2 ( struct V_1 * V_1 , unsigned int V_2 )
{
return V_1 -> V_3 -> V_4 ( V_1 , V_2 , false ) ;
}
static int F_3 ( struct V_1 * V_1 , T_1 V_5 )
{
int V_6 ;
V_6 = V_1 -> V_7 -> V_8 ( V_1 , V_5 ) ;
if ( V_6 < 0 )
F_4 ( V_1 -> V_9 , L_1 , V_5 , V_6 ) ;
F_5 ( V_1 -> V_9 , L_2 , V_5 , V_6 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_10 )
{
int V_6 ;
F_5 ( V_1 -> V_9 , L_3 , V_5 , V_10 ) ;
V_6 = V_1 -> V_7 -> V_11 ( V_1 , V_5 , V_10 ) ;
if ( V_6 < 0 )
F_4 ( V_1 -> V_9 , L_4 , V_5 , V_6 ) ;
return V_6 ;
}
static int F_7 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_12 , T_1 V_10 )
{
int V_6 ;
V_6 = F_3 ( V_1 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 &= ~ V_12 ;
V_6 |= V_10 ;
return F_6 ( V_1 , V_5 , V_6 ) ;
}
static int F_8 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_13 ,
T_1 * V_14 )
{
int V_6 ;
V_6 = V_1 -> V_7 -> V_15 ( V_1 , V_5 , V_13 , V_14 ) ;
if ( V_6 < 0 )
F_4 ( V_1 -> V_9 , L_5 , V_5 , V_6 ) ;
F_5 ( V_1 -> V_9 , L_6 , V_5 , V_13 , V_6 ) ;
F_9 ( L_7 , V_14 , V_13 ) ;
return V_6 ;
}
static int F_10 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_13 ,
const T_1 * V_14 )
{
int V_6 ;
F_5 ( V_1 -> V_9 , L_8 , V_5 , V_13 ) ;
F_9 ( L_9 , V_14 , V_13 ) ;
V_6 = V_1 -> V_7 -> V_16 ( V_1 , V_5 , V_13 , V_14 ) ;
if ( V_6 < 0 )
F_4 ( V_1 -> V_9 , L_10 , V_5 , V_6 ) ;
return V_6 ;
}
int F_11 ( struct V_1 * V_1 , unsigned int V_2 )
{
int V_6 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_1 ( V_1 , V_2 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
int F_14 ( struct V_1 * V_1 , unsigned int V_2 )
{
int V_6 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_2 ( V_1 , V_2 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
int F_15 ( struct V_1 * V_1 , T_1 V_5 )
{
int V_6 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_3 ( V_1 , V_5 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
int F_16 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_10 )
{
int V_6 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_6 ( V_1 , V_5 , V_10 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
int F_17 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_12 , T_1 V_10 )
{
int V_6 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_7 ( V_1 , V_5 , V_12 , V_10 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
int F_18 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_13 , T_1 * V_14 )
{
int V_6 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_8 ( V_1 , V_5 , V_13 , V_14 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
int F_19 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_13 ,
const T_1 * V_14 )
{
int V_6 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_10 ( V_1 , V_5 , V_13 , V_14 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
int F_20 ( struct V_1 * V_1 , T_2 V_18 , enum V_19 V_20 )
{
struct V_21 * V_3 = V_1 -> V_3 ;
T_1 V_22 = V_1 -> V_23 [ V_24 ] ;
int V_25 = V_3 -> V_25 ;
int V_26 = F_21 ( V_1 -> V_27 * V_25 , 8 ) ;
int V_12 = ( 1 << V_25 ) - 1 ;
T_1 V_23 [ 8 ] ;
int V_28 , V_29 , V_6 ;
if ( ! V_3 -> V_30 )
return 0 ;
V_29 = 8 / V_25 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = F_1 ( V_1 , V_31 ) ;
if ( V_6 < 0 )
goto V_32;
V_6 = F_8 ( V_1 , V_22 , V_26 , V_23 ) ;
if ( V_6 < 0 )
goto V_32;
V_28 = V_3 -> V_30 ( V_1 , V_20 ) ;
while ( V_18 ) {
int V_33 = F_22 ( V_18 ) ;
int V_34 = V_26 - ( V_33 / V_29 ) - 1 ;
int V_35 = ( V_33 % V_29 ) * ( 8 / V_29 ) ;
V_23 [ V_34 ] &= ~ ( V_12 << V_35 ) ;
V_23 [ V_34 ] |= V_28 << V_35 ;
V_18 &= ~ ( 1 << V_33 ) ;
}
V_6 = F_10 ( V_1 , V_22 , V_26 , V_23 ) ;
V_32:
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
static int F_23 ( struct V_1 * V_1 , unsigned int V_2 ,
bool V_4 )
{
if ( V_2 & V_31 )
return 0 ;
else
return - V_36 ;
}
static int F_24 ( struct V_1 * V_1 , unsigned int V_2 ,
bool V_4 )
{
unsigned int V_12 = 0 ;
if ( V_2 & V_31 )
V_12 |= V_37 ;
if ( V_2 & V_38 )
V_12 |= V_39 ;
if ( V_2 & V_40 )
V_12 |= V_41 ;
return F_7 ( V_1 , V_42 , V_12 ,
V_4 ? 0 : V_12 ) ;
}
static int F_25 ( struct V_1 * V_1 , enum V_19 V_20 )
{
return V_20 != V_40 ;
}
static int F_26 ( int V_43 )
{
int V_44 ;
for ( V_44 = 0 ; V_44 < F_27 ( V_45 ) ; V_44 ++ ) {
if ( V_45 [ V_44 ] >= V_43 )
return V_44 ;
}
return - V_36 ;
}
static int F_28 ( struct V_1 * V_1 , int V_46 )
{
int V_6 ;
if ( ! V_1 -> V_3 -> V_47 )
return - V_48 ;
F_12 ( & V_1 -> V_17 ) ;
V_6 = V_1 -> V_3 -> V_47 ( V_1 , V_46 ) ;
F_13 ( & V_1 -> V_17 ) ;
return V_6 ;
}
static int F_29 ( struct V_1 * V_1 ,
int V_46 )
{
int V_6 , V_43 ;
V_43 = F_26 ( V_46 ) ;
if ( V_43 < 0 ) {
F_4 ( V_1 -> V_9 , L_11 ) ;
return V_43 ;
}
V_6 = F_7 ( V_1 , V_49 ,
V_50 ,
V_43 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_7 ( V_1 , V_49 ,
V_51 ,
V_51 ) ;
}
static int F_30 ( struct V_1 * V_1 , unsigned int V_2 ,
bool V_4 )
{
unsigned int V_12 = 0 ;
if ( V_2 & V_31 )
V_12 |= V_52 ;
else
V_12 &= ~ V_52 ;
if ( V_2 & V_53 )
V_12 |= V_54 ;
else
V_12 &= ~ V_54 ;
if ( V_2 & V_55 )
V_12 |= V_56 ;
else
V_12 &= ~ V_56 ;
return F_7 ( V_1 , V_57 , V_12 ,
V_4 ? V_12 : 0 ) ;
}
static int F_31 ( struct V_1 * V_1 , enum V_19 V_20 )
{
switch ( V_20 ) {
case V_55 :
return 2 ;
case V_53 :
return 1 ;
case V_31 :
default:
return 0 ;
}
}
static int F_32 ( struct V_1 * V_1 , unsigned int V_2 ,
bool V_4 )
{
unsigned int V_12 = 0 ;
if ( V_2 & V_31 )
V_12 |= V_58 ;
if ( V_2 & V_53 )
V_12 |= V_59 ;
return F_7 ( V_1 , V_60 , V_12 ,
V_4 ? V_12 : 0 ) ;
}
static int F_33 ( struct V_1 * V_1 )
{
unsigned long V_43 ;
int V_6 = 0 ;
V_6 = F_7 ( V_1 , V_61 ,
V_62 , V_62 ) ;
if ( V_6 < 0 )
return V_6 ;
V_43 = V_63 + F_34 ( 100 ) ;
while ( F_35 ( V_63 , V_43 ) ) {
V_6 = F_3 ( V_1 , V_61 ) ;
if ( V_6 < 0 )
return V_6 ;
if ( ! ( V_6 & V_62 ) )
return 0 ;
F_36 ( 100 , 200 ) ;
}
return - V_64 ;
}
static int F_37 ( struct V_1 * V_1 , unsigned int V_2 ,
bool V_4 )
{
unsigned int V_12 = 0 ;
if ( V_2 & V_31 )
V_12 |= V_65 ;
if ( V_2 & V_53 )
V_12 |= V_66 ;
return F_7 ( V_1 , V_67 , V_12 ,
V_4 ? V_12 : 0 ) ;
}
static int F_38 ( struct V_1 * V_1 , enum V_19 V_20 )
{
switch ( V_20 ) {
case V_68 :
return 2 ;
case V_53 :
return 1 ;
case V_31 :
default:
return 0 ;
}
}
static T_3 F_39 ( int V_69 , void * V_70 )
{
struct V_1 * V_1 = V_70 ;
struct V_21 * V_3 = V_1 -> V_3 ;
int V_71 = F_21 ( V_3 -> V_72 , 8 ) ;
T_1 V_73 ;
T_1 V_74 [ 3 ] ;
int V_6 ;
int V_44 ;
if ( V_3 -> V_75 == V_76 ) {
int V_77 = F_40 ( V_1 -> V_78 , 0 ) ;
F_41 ( V_77 ) ;
return V_79 ;
}
if ( V_3 -> V_75 == V_80 )
V_73 = V_1 -> V_23 [ V_81 ] ;
else
V_73 = V_1 -> V_23 [ V_82 ] ;
V_6 = F_18 ( V_1 , V_73 , V_71 , V_74 ) ;
if ( V_6 < 0 )
return V_83 ;
for ( V_44 = 0 ; V_44 < V_71 ; V_44 ++ ) {
int V_84 = V_71 - V_44 - 1 ;
T_1 V_85 = V_74 [ V_44 ] ;
T_1 V_86 ;
V_85 &= V_1 -> V_87 [ V_84 ] ;
if ( ! V_85 )
continue;
V_86 = V_85 ;
while ( V_85 ) {
int V_88 = F_22 ( V_85 ) ;
int line = V_84 * 8 + V_88 ;
int V_89 = F_40 ( V_1 -> V_78 , line ) ;
F_41 ( V_89 ) ;
V_85 &= ~ ( 1 << V_88 ) ;
}
F_16 ( V_1 , V_73 + V_44 , V_86 ) ;
}
return V_79 ;
}
static void F_42 ( struct V_90 * V_70 )
{
struct V_1 * V_1 = F_43 ( V_70 ) ;
F_12 ( & V_1 -> V_91 ) ;
}
static void F_44 ( struct V_90 * V_70 )
{
struct V_1 * V_1 = F_43 ( V_70 ) ;
struct V_21 * V_3 = V_1 -> V_3 ;
int V_71 = F_21 ( V_3 -> V_72 , 8 ) ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_71 ; V_44 ++ ) {
T_1 V_92 = V_1 -> V_87 [ V_44 ] ;
T_1 V_93 = V_1 -> V_94 [ V_44 ] ;
if ( V_92 == V_93 )
continue;
V_1 -> V_94 [ V_44 ] = V_92 ;
F_16 ( V_1 , V_1 -> V_23 [ V_95 ] - V_44 , V_92 ) ;
}
F_13 ( & V_1 -> V_91 ) ;
}
static void F_45 ( struct V_90 * V_70 )
{
struct V_1 * V_1 = F_43 ( V_70 ) ;
int V_96 = V_70 -> V_97 ;
int V_34 = V_96 / 8 ;
int V_12 = 1 << ( V_96 % 8 ) ;
V_1 -> V_87 [ V_34 ] &= ~ V_12 ;
}
static void F_46 ( struct V_90 * V_70 )
{
struct V_1 * V_1 = F_43 ( V_70 ) ;
int V_96 = V_70 -> V_97 ;
int V_34 = V_96 / 8 ;
int V_12 = 1 << ( V_96 % 8 ) ;
V_1 -> V_87 [ V_34 ] |= V_12 ;
}
static int F_47 ( struct V_98 * V_99 , unsigned int V_100 ,
T_4 V_97 )
{
struct V_1 * V_1 = V_99 -> V_101 ;
struct V_102 * V_103 = NULL ;
if ( V_1 -> V_3 -> V_75 != V_76 )
V_103 = & V_104 ;
F_48 ( V_100 , V_1 ) ;
F_49 ( V_100 , V_103 , V_105 ) ;
F_50 ( V_100 , 1 ) ;
F_51 ( V_100 ) ;
return 0 ;
}
static void F_52 ( struct V_98 * V_99 , unsigned int V_100 )
{
F_49 ( V_100 , NULL , NULL ) ;
F_48 ( V_100 , NULL ) ;
}
static int F_53 ( struct V_1 * V_1 , struct V_106 * V_107 )
{
int V_77 = 0 ;
int V_72 = V_1 -> V_3 -> V_72 ;
V_1 -> V_78 = F_54 ( V_107 , V_72 , V_77 ,
& V_108 , V_1 ) ;
if ( ! V_1 -> V_78 ) {
F_4 ( V_1 -> V_9 , L_12 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_55 ( struct V_1 * V_1 )
{
unsigned int V_109 = V_1 -> V_110 -> V_109 ;
int V_46 = V_1 -> V_110 -> V_46 ;
struct V_21 * V_3 = V_1 -> V_3 ;
T_1 V_111 = 0 ;
unsigned int V_112 ;
T_1 V_70 [ 2 ] ;
int V_6 ;
V_6 = F_18 ( V_1 , V_1 -> V_23 [ V_113 ] ,
F_27 ( V_70 ) , V_70 ) ;
if ( V_6 < 0 )
return V_6 ;
V_112 = ( V_70 [ 0 ] << 8 ) | V_70 [ 1 ] ;
if ( ( V_112 & V_3 -> V_114 ) != V_3 -> V_75 ) {
F_4 ( V_1 -> V_9 , L_13 , V_112 ) ;
return - V_36 ;
}
F_56 ( V_1 -> V_9 , L_14 , V_3 -> V_115 , V_112 ) ;
V_6 = F_14 ( V_1 , ~ 0 ) ;
if ( V_6 )
return V_6 ;
if ( V_112 == V_80 ) {
V_6 = F_33 ( V_1 ) ;
if ( V_6 < 0 )
return V_6 ;
}
if ( V_1 -> V_69 >= 0 ) {
if ( V_112 == V_76 )
V_111 = V_116 ;
else
V_111 = V_117 ;
if ( V_112 != V_76 ) {
if ( V_109 == V_118 ||
V_109 == V_119 )
V_111 |= V_120 ;
}
if ( V_109 == V_119 ||
V_109 == V_121 ) {
if ( V_112 == V_76 )
V_111 |= V_122 ;
else
V_111 |= V_123 ;
}
}
if ( V_1 -> V_110 -> V_124 ) {
V_6 = F_28 ( V_1 , V_46 ) ;
if ( V_6 )
return V_6 ;
}
return F_16 ( V_1 , V_1 -> V_23 [ V_125 ] , V_111 ) ;
}
static int F_57 ( struct V_1 * V_1 , const struct V_126 * V_127 )
{
return F_58 ( V_1 -> V_9 , V_1 -> V_110 -> V_112 , V_127 , 1 ,
NULL , 0 , V_1 -> V_78 ) ;
}
static int F_59 ( struct V_1 * V_1 )
{
struct V_21 * V_3 = V_1 -> V_3 ;
unsigned int V_128 = V_1 -> V_110 -> V_2 ;
int V_6 = - V_36 ;
int V_44 , V_129 ;
for ( V_44 = 0 ; V_44 < V_3 -> V_130 ; V_44 ++ ) {
struct V_131 * V_20 = & V_3 -> V_2 [ V_44 ] ;
if ( ! ( V_128 & V_20 -> V_20 ) )
continue;
for ( V_129 = 0 ; V_129 < V_20 -> V_127 -> V_132 ; V_129 ++ ) {
struct V_133 * V_134 =
(struct V_133 * ) & V_20 -> V_127 -> V_135 [ V_129 ] ;
if ( V_134 -> V_136 & V_137 )
V_134 -> V_138 = V_134 -> V_139 = V_20 -> V_69 + V_129 ;
}
V_128 &= ~ V_20 -> V_20 ;
V_6 = F_57 ( V_1 , V_20 -> V_127 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_128 )
F_60 ( V_1 -> V_9 ,
L_15 ,
V_128 ) ;
return V_6 ;
}
static void F_61 ( struct V_140 * V_110 ,
struct V_106 * V_107 )
{
struct V_106 * V_141 ;
V_110 -> V_112 = F_62 ( V_107 , L_16 ) ;
if ( V_110 -> V_112 < 0 )
V_110 -> V_112 = - 1 ;
V_110 -> V_142 = F_63 ( V_107 , L_17 , 0 ,
& V_110 -> V_109 ) ;
if ( F_64 ( V_110 -> V_142 ) )
V_110 -> V_143 = 1 ;
else
V_110 -> V_109 = V_144 ;
F_65 ( V_107 , L_18 ,
& V_110 -> V_46 ) ;
V_110 -> V_124 = ( V_110 -> V_46 ) ? true : false ;
F_66 (np, child) {
if ( ! strcmp ( V_141 -> V_115 , L_19 ) ) {
V_110 -> V_2 |= V_31 ;
} else if ( ! strcmp ( V_141 -> V_115 , L_20 ) ) {
V_110 -> V_2 |= V_53 ;
} else if ( ! strcmp ( V_141 -> V_115 , L_21 ) ) {
V_110 -> V_2 |= V_40 ;
} else if ( ! strcmp ( V_141 -> V_115 , L_22 ) ) {
V_110 -> V_2 |= V_38 ;
} else if ( ! strcmp ( V_141 -> V_115 , L_23 ) ) {
V_110 -> V_2 |= V_55 ;
} else if ( ! strcmp ( V_141 -> V_115 , L_24 ) ) {
V_110 -> V_2 |= V_68 ;
}
}
}
int F_67 ( struct V_145 * V_7 , enum V_146 V_147 )
{
struct V_140 * V_110 = F_68 ( V_7 -> V_9 ) ;
struct V_106 * V_107 = V_7 -> V_9 -> V_148 ;
struct V_1 * V_1 ;
int V_6 ;
if ( ! V_110 ) {
if ( ! V_107 )
return - V_36 ;
V_110 = F_69 ( V_7 -> V_9 , sizeof( * V_110 ) , V_149 ) ;
if ( ! V_110 )
return - V_150 ;
F_61 ( V_110 , V_107 ) ;
if ( F_70 ( V_107 , L_25 , NULL ) == NULL )
V_7 -> V_69 = - 1 ;
}
V_1 = F_69 ( V_7 -> V_9 , sizeof( struct V_1 ) , V_149 ) ;
if ( ! V_1 )
return - V_150 ;
F_71 ( & V_1 -> V_91 ) ;
F_71 ( & V_1 -> V_17 ) ;
V_1 -> V_9 = V_7 -> V_9 ;
V_1 -> V_151 = V_7 -> V_151 ;
V_1 -> V_110 = V_110 ;
V_1 -> V_7 = V_7 ;
V_1 -> V_147 = V_147 ;
V_1 -> V_3 = V_21 [ V_147 ] ;
V_1 -> V_23 = V_1 -> V_3 -> V_23 ;
V_1 -> V_27 = V_1 -> V_3 -> V_27 ;
V_1 -> V_152 = F_72 ( V_7 -> V_9 , L_26 ) ;
if ( ! F_73 ( V_1 -> V_152 ) ) {
V_6 = F_74 ( V_1 -> V_152 ) ;
if ( V_6 )
F_60 ( V_7 -> V_9 , L_27 ) ;
}
V_1 -> V_153 = F_72 ( V_7 -> V_9 , L_28 ) ;
if ( ! F_73 ( V_1 -> V_153 ) ) {
V_6 = F_74 ( V_1 -> V_153 ) ;
if ( V_6 )
F_60 ( V_7 -> V_9 , L_29 ) ;
}
F_75 ( V_1 -> V_9 , V_1 ) ;
if ( V_7 -> V_154 )
V_7 -> V_154 ( V_1 ) ;
if ( V_110 -> V_143 ) {
V_6 = F_76 ( V_7 -> V_9 , V_110 -> V_142 ,
V_155 , L_30 ) ;
if ( V_6 ) {
F_4 ( V_1 -> V_9 , L_31 ,
V_6 ) ;
return V_6 ;
}
V_1 -> V_69 = F_77 ( V_110 -> V_142 ) ;
} else {
V_1 -> V_69 = V_7 -> V_69 ;
}
if ( V_1 -> V_69 < 0 ) {
F_56 ( V_1 -> V_9 ,
L_32 ,
V_1 -> V_3 -> V_115 ) ;
if ( ! V_156 [ V_1 -> V_147 ] ) {
F_4 ( V_1 -> V_9 ,
L_33 ,
V_1 -> V_3 -> V_115 ) ;
return - V_157 ;
}
V_1 -> V_3 = V_156 [ V_1 -> V_147 ] ;
} else if ( V_110 -> V_109 == V_144 ) {
V_110 -> V_109 = F_78 ( V_1 -> V_69 ) ;
}
V_6 = F_55 ( V_1 ) ;
if ( V_6 )
return V_6 ;
if ( V_1 -> V_69 >= 0 ) {
V_6 = F_53 ( V_1 , V_107 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_79 ( V_7 -> V_9 , V_1 -> V_69 , NULL ,
F_39 , V_110 -> V_109 | V_158 ,
L_30 , V_1 ) ;
if ( V_6 ) {
F_4 ( V_1 -> V_9 , L_34 ,
V_6 ) ;
return V_6 ;
}
}
V_6 = F_59 ( V_1 ) ;
if ( ! V_6 )
return 0 ;
F_4 ( V_1 -> V_9 , L_35 ) ;
F_80 ( V_1 -> V_9 ) ;
return V_6 ;
}
int F_81 ( struct V_1 * V_1 )
{
if ( ! F_73 ( V_1 -> V_153 ) )
F_82 ( V_1 -> V_153 ) ;
if ( ! F_73 ( V_1 -> V_152 ) )
F_82 ( V_1 -> V_152 ) ;
F_80 ( V_1 -> V_9 ) ;
return 0 ;
}
static int F_83 ( struct V_159 * V_9 )
{
struct V_1 * V_1 = F_84 ( V_9 ) ;
if ( V_1 -> V_69 >= 0 && F_85 ( V_9 ) )
F_86 ( V_1 -> V_69 ) ;
return 0 ;
}
static int F_87 ( struct V_159 * V_9 )
{
struct V_1 * V_1 = F_84 ( V_9 ) ;
if ( V_1 -> V_69 >= 0 && F_85 ( V_9 ) )
F_88 ( V_1 -> V_69 ) ;
return 0 ;
}
