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
T_1 V_23 [ V_26 ] ;
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
if ( V_2 & V_53 )
V_12 |= V_54 ;
return F_7 ( V_1 , V_55 , V_12 ,
V_4 ? V_12 : 0 ) ;
}
static int F_31 ( struct V_1 * V_1 , enum V_19 V_20 )
{
switch ( V_20 ) {
case V_56 :
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
V_12 |= V_57 ;
if ( V_2 & V_53 )
V_12 |= V_58 ;
return F_7 ( V_1 , V_59 , V_12 ,
V_4 ? V_12 : 0 ) ;
}
static int F_33 ( struct V_1 * V_1 , enum V_19 V_20 )
{
switch ( V_20 ) {
case V_60 :
return 2 ;
case V_53 :
return 1 ;
case V_31 :
default:
return 0 ;
}
}
static T_3 F_34 ( int V_61 , void * V_62 )
{
struct V_1 * V_1 = V_62 ;
struct V_21 * V_3 = V_1 -> V_3 ;
int V_63 = F_21 ( V_3 -> V_64 , 8 ) ;
T_1 V_65 = V_1 -> V_23 [ V_66 ] ;
T_1 V_67 [ V_63 ] ;
int V_6 ;
int V_44 ;
if ( V_3 -> V_68 == V_69 ) {
int V_70 = F_35 ( V_1 -> V_71 , 0 ) ;
F_36 ( V_70 ) ;
return V_72 ;
}
V_6 = F_18 ( V_1 , V_65 , V_63 , V_67 ) ;
if ( V_6 < 0 )
return V_73 ;
for ( V_44 = 0 ; V_44 < V_63 ; V_44 ++ ) {
int V_74 = V_63 - V_44 - 1 ;
T_1 V_75 = V_67 [ V_44 ] ;
T_1 V_76 ;
V_75 &= V_1 -> V_77 [ V_74 ] ;
if ( ! V_75 )
continue;
V_76 = V_75 ;
while ( V_75 ) {
int V_78 = F_22 ( V_75 ) ;
int line = V_74 * 8 + V_78 ;
int V_79 = F_35 ( V_1 -> V_71 , line ) ;
F_36 ( V_79 ) ;
V_75 &= ~ ( 1 << V_78 ) ;
}
F_16 ( V_1 , V_65 + V_44 , V_76 ) ;
}
return V_72 ;
}
static void F_37 ( struct V_80 * V_62 )
{
struct V_1 * V_1 = F_38 ( V_62 ) ;
F_12 ( & V_1 -> V_81 ) ;
}
static void F_39 ( struct V_80 * V_62 )
{
struct V_1 * V_1 = F_38 ( V_62 ) ;
struct V_21 * V_3 = V_1 -> V_3 ;
int V_63 = F_21 ( V_3 -> V_64 , 8 ) ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_63 ; V_44 ++ ) {
T_1 V_82 = V_1 -> V_77 [ V_44 ] ;
T_1 V_83 = V_1 -> V_84 [ V_44 ] ;
if ( V_82 == V_83 )
continue;
V_1 -> V_84 [ V_44 ] = V_82 ;
F_16 ( V_1 , V_1 -> V_23 [ V_85 ] - V_44 , V_82 ) ;
}
F_13 ( & V_1 -> V_81 ) ;
}
static void F_40 ( struct V_80 * V_62 )
{
struct V_1 * V_1 = F_38 ( V_62 ) ;
int V_86 = V_62 -> V_87 ;
int V_34 = V_86 / 8 ;
int V_12 = 1 << ( V_86 % 8 ) ;
V_1 -> V_77 [ V_34 ] &= ~ V_12 ;
}
static void F_41 ( struct V_80 * V_62 )
{
struct V_1 * V_1 = F_38 ( V_62 ) ;
int V_86 = V_62 -> V_87 ;
int V_34 = V_86 / 8 ;
int V_12 = 1 << ( V_86 % 8 ) ;
V_1 -> V_77 [ V_34 ] |= V_12 ;
}
static int F_42 ( struct V_88 * V_89 , unsigned int V_90 ,
T_4 V_87 )
{
struct V_1 * V_1 = V_89 -> V_91 ;
struct V_92 * V_93 = NULL ;
if ( V_1 -> V_3 -> V_68 != V_69 )
V_93 = & V_94 ;
F_43 ( V_90 , V_1 ) ;
F_44 ( V_90 , V_93 , V_95 ) ;
F_45 ( V_90 , 1 ) ;
#ifdef F_46
F_47 ( V_90 , V_96 ) ;
#else
F_48 ( V_90 ) ;
#endif
return 0 ;
}
static void F_49 ( struct V_88 * V_89 , unsigned int V_90 )
{
#ifdef F_46
F_47 ( V_90 , 0 ) ;
#endif
F_44 ( V_90 , NULL , NULL ) ;
F_43 ( V_90 , NULL ) ;
}
static int F_50 ( struct V_1 * V_1 , struct V_97 * V_98 )
{
int V_70 = 0 ;
int V_64 = V_1 -> V_3 -> V_64 ;
if ( ! V_98 )
V_70 = V_1 -> V_99 ;
V_1 -> V_71 = F_51 ( V_98 , V_64 , V_70 ,
& V_100 , V_1 ) ;
if ( ! V_1 -> V_71 ) {
F_4 ( V_1 -> V_9 , L_12 ) ;
return - V_48 ;
}
return 0 ;
}
static int F_52 ( struct V_1 * V_1 )
{
unsigned int V_101 = V_1 -> V_102 -> V_101 ;
int V_46 = V_1 -> V_102 -> V_46 ;
struct V_21 * V_3 = V_1 -> V_3 ;
T_1 V_103 = 0 ;
unsigned int V_104 ;
T_1 V_62 [ 2 ] ;
int V_6 ;
V_6 = F_18 ( V_1 , V_1 -> V_23 [ V_105 ] ,
F_27 ( V_62 ) , V_62 ) ;
if ( V_6 < 0 )
return V_6 ;
V_104 = ( V_62 [ 0 ] << 8 ) | V_62 [ 1 ] ;
if ( ( V_104 & V_3 -> V_106 ) != V_3 -> V_68 ) {
F_4 ( V_1 -> V_9 , L_13 , V_104 ) ;
return - V_36 ;
}
F_53 ( V_1 -> V_9 , L_14 , V_3 -> V_107 , V_104 ) ;
V_6 = F_14 ( V_1 , ~ 0 ) ;
if ( V_6 )
return V_6 ;
if ( V_1 -> V_61 >= 0 ) {
if ( V_104 == V_69 )
V_103 = V_108 ;
else
V_103 = V_109 ;
if ( V_104 != V_69 ) {
if ( V_101 == V_110 ||
V_101 == V_111 )
V_103 |= V_112 ;
}
if ( V_101 == V_111 ||
V_101 == V_113 ) {
if ( V_104 == V_69 )
V_103 |= V_114 ;
else
V_103 |= V_115 ;
}
}
if ( V_1 -> V_102 -> V_116 ) {
V_6 = F_28 ( V_1 , V_46 ) ;
if ( V_6 )
return V_6 ;
}
return F_16 ( V_1 , V_1 -> V_23 [ V_117 ] , V_103 ) ;
}
static int F_54 ( struct V_1 * V_1 , struct V_118 * V_119 )
{
return F_55 ( V_1 -> V_9 , V_1 -> V_102 -> V_104 , V_119 , 1 ,
NULL , V_1 -> V_99 , V_1 -> V_71 ) ;
}
static int F_56 ( struct V_1 * V_1 )
{
struct V_21 * V_3 = V_1 -> V_3 ;
unsigned int V_120 = V_1 -> V_102 -> V_2 ;
int V_6 = - V_36 ;
int V_44 , V_121 ;
for ( V_44 = 0 ; V_44 < V_3 -> V_122 ; V_44 ++ ) {
struct V_123 * V_20 = & V_3 -> V_2 [ V_44 ] ;
if ( ! ( V_120 & V_20 -> V_20 ) )
continue;
for ( V_121 = 0 ; V_121 < V_20 -> V_119 -> V_124 ; V_121 ++ ) {
struct V_125 * V_126 =
(struct V_125 * ) & V_20 -> V_119 -> V_127 [ V_121 ] ;
if ( V_126 -> V_128 & V_129 )
V_126 -> V_130 = V_126 -> V_131 = V_20 -> V_61 + V_121 ;
}
V_120 &= ~ V_20 -> V_20 ;
V_6 = F_54 ( V_1 , V_20 -> V_119 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_120 )
F_57 ( V_1 -> V_9 ,
L_15 ,
V_120 ) ;
return V_6 ;
}
void F_58 ( struct V_132 * V_102 , struct V_97 * V_98 )
{
struct V_97 * V_133 ;
V_102 -> V_104 = - 1 ;
V_102 -> V_101 = V_134 ;
F_59 ( V_98 , L_16 ,
& V_102 -> V_46 ) ;
V_102 -> V_116 = ( V_102 -> V_46 ) ? true : false ;
F_60 (np, child) {
if ( ! strcmp ( V_133 -> V_107 , L_17 ) ) {
V_102 -> V_2 |= V_31 ;
} else if ( ! strcmp ( V_133 -> V_107 , L_18 ) ) {
V_102 -> V_2 |= V_53 ;
} else if ( ! strcmp ( V_133 -> V_107 , L_19 ) ) {
V_102 -> V_2 |= V_40 ;
} else if ( ! strcmp ( V_133 -> V_107 , L_20 ) ) {
V_102 -> V_2 |= V_38 ;
} else if ( ! strcmp ( V_133 -> V_107 , L_21 ) ) {
V_102 -> V_2 |= V_56 ;
} else if ( ! strcmp ( V_133 -> V_107 , L_22 ) ) {
V_102 -> V_2 |= V_60 ;
}
}
}
int F_61 ( struct V_135 * V_7 , int V_136 )
{
struct V_132 * V_102 = F_62 ( V_7 -> V_9 ) ;
struct V_97 * V_98 = V_7 -> V_9 -> V_137 ;
struct V_1 * V_1 ;
int V_6 ;
if ( ! V_102 ) {
if ( ! V_98 )
return - V_36 ;
V_102 = F_63 ( V_7 -> V_9 , sizeof( * V_102 ) , V_138 ) ;
if ( ! V_102 )
return - V_139 ;
F_58 ( V_102 , V_98 ) ;
}
V_1 = F_63 ( V_7 -> V_9 , sizeof( struct V_1 ) , V_138 ) ;
if ( ! V_1 )
return - V_139 ;
F_64 ( & V_1 -> V_81 ) ;
F_64 ( & V_1 -> V_17 ) ;
V_1 -> V_9 = V_7 -> V_9 ;
V_1 -> V_140 = V_7 -> V_140 ;
V_1 -> V_102 = V_102 ;
V_1 -> V_99 = V_102 -> V_99 ;
V_1 -> V_7 = V_7 ;
V_1 -> V_136 = V_136 ;
V_1 -> V_3 = V_21 [ V_136 ] ;
V_1 -> V_23 = V_1 -> V_3 -> V_23 ;
V_1 -> V_27 = V_1 -> V_3 -> V_27 ;
F_65 ( V_1 -> V_9 , V_1 ) ;
if ( V_7 -> V_141 )
V_7 -> V_141 ( V_1 ) ;
if ( V_102 -> V_142 ) {
V_6 = F_66 ( V_7 -> V_9 , V_102 -> V_143 ,
V_144 , L_23 ) ;
if ( V_6 ) {
F_4 ( V_1 -> V_9 , L_24 ,
V_6 ) ;
return V_6 ;
}
V_1 -> V_61 = F_67 ( V_102 -> V_143 ) ;
} else {
V_1 -> V_61 = V_7 -> V_61 ;
}
if ( V_1 -> V_61 < 0 ) {
F_53 ( V_1 -> V_9 ,
L_25 ,
V_1 -> V_3 -> V_107 ) ;
if ( ! V_145 [ V_1 -> V_136 ] ) {
F_4 ( V_1 -> V_9 ,
L_26 ,
V_1 -> V_3 -> V_107 ) ;
return - V_146 ;
}
V_1 -> V_3 = V_145 [ V_1 -> V_136 ] ;
} else if ( V_102 -> V_101 == V_134 ) {
V_102 -> V_101 =
F_68 ( F_69 ( V_1 -> V_61 ) ) ;
}
V_6 = F_52 ( V_1 ) ;
if ( V_6 )
return V_6 ;
if ( V_1 -> V_61 >= 0 ) {
V_6 = F_50 ( V_1 , V_98 ) ;
if ( V_6 )
return V_6 ;
V_6 = F_70 ( V_7 -> V_9 , V_1 -> V_61 , NULL ,
F_34 , V_102 -> V_101 | V_147 ,
L_23 , V_1 ) ;
if ( V_6 ) {
F_4 ( V_1 -> V_9 , L_27 ,
V_6 ) ;
return V_6 ;
}
}
V_6 = F_56 ( V_1 ) ;
if ( ! V_6 )
return 0 ;
F_4 ( V_1 -> V_9 , L_28 ) ;
F_71 ( V_1 -> V_9 ) ;
return V_6 ;
}
int F_72 ( struct V_1 * V_1 )
{
F_71 ( V_1 -> V_9 ) ;
return 0 ;
}
static int F_73 ( struct V_148 * V_9 )
{
struct V_1 * V_1 = F_74 ( V_9 ) ;
if ( V_1 -> V_61 >= 0 && F_75 ( V_9 ) )
F_76 ( V_1 -> V_61 ) ;
return 0 ;
}
static int F_77 ( struct V_148 * V_9 )
{
struct V_1 * V_1 = F_74 ( V_9 ) ;
if ( V_1 -> V_61 >= 0 && F_75 ( V_9 ) )
F_78 ( V_1 -> V_61 ) ;
return 0 ;
}
