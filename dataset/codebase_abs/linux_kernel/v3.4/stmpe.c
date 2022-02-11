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
F_35 ( V_1 -> V_70 ) ;
return V_71 ;
}
V_6 = F_18 ( V_1 , V_65 , V_63 , V_67 ) ;
if ( V_6 < 0 )
return V_72 ;
for ( V_44 = 0 ; V_44 < V_63 ; V_44 ++ ) {
int V_73 = V_63 - V_44 - 1 ;
T_1 V_74 = V_67 [ V_44 ] ;
T_1 V_75 ;
V_74 &= V_1 -> V_76 [ V_73 ] ;
if ( ! V_74 )
continue;
V_75 = V_74 ;
while ( V_74 ) {
int V_77 = F_22 ( V_74 ) ;
int line = V_73 * 8 + V_77 ;
F_35 ( V_1 -> V_70 + line ) ;
V_74 &= ~ ( 1 << V_77 ) ;
}
F_16 ( V_1 , V_65 + V_44 , V_75 ) ;
}
return V_71 ;
}
static void F_36 ( struct V_78 * V_62 )
{
struct V_1 * V_1 = F_37 ( V_62 ) ;
F_12 ( & V_1 -> V_79 ) ;
}
static void F_38 ( struct V_78 * V_62 )
{
struct V_1 * V_1 = F_37 ( V_62 ) ;
struct V_21 * V_3 = V_1 -> V_3 ;
int V_63 = F_21 ( V_3 -> V_64 , 8 ) ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_63 ; V_44 ++ ) {
T_1 V_80 = V_1 -> V_76 [ V_44 ] ;
T_1 V_81 = V_1 -> V_82 [ V_44 ] ;
if ( V_80 == V_81 )
continue;
V_1 -> V_82 [ V_44 ] = V_80 ;
F_16 ( V_1 , V_1 -> V_23 [ V_83 ] - V_44 , V_80 ) ;
}
F_13 ( & V_1 -> V_79 ) ;
}
static void F_39 ( struct V_78 * V_62 )
{
struct V_1 * V_1 = F_37 ( V_62 ) ;
int V_84 = V_62 -> V_61 - V_1 -> V_70 ;
int V_34 = V_84 / 8 ;
int V_12 = 1 << ( V_84 % 8 ) ;
V_1 -> V_76 [ V_34 ] &= ~ V_12 ;
}
static void F_40 ( struct V_78 * V_62 )
{
struct V_1 * V_1 = F_37 ( V_62 ) ;
int V_84 = V_62 -> V_61 - V_1 -> V_70 ;
int V_34 = V_84 / 8 ;
int V_12 = 1 << ( V_84 % 8 ) ;
V_1 -> V_76 [ V_34 ] |= V_12 ;
}
static int T_4 F_41 ( struct V_1 * V_1 )
{
struct V_85 * V_86 = NULL ;
int V_64 = V_1 -> V_3 -> V_64 ;
int V_87 = V_1 -> V_70 ;
int V_61 ;
if ( V_1 -> V_3 -> V_68 != V_69 )
V_86 = & V_88 ;
for ( V_61 = V_87 ; V_61 < V_87 + V_64 ; V_61 ++ ) {
F_42 ( V_61 , V_1 ) ;
F_43 ( V_61 , V_86 , V_89 ) ;
F_44 ( V_61 , 1 ) ;
#ifdef F_45
F_46 ( V_61 , V_90 ) ;
#else
F_47 ( V_61 ) ;
#endif
}
return 0 ;
}
static void F_48 ( struct V_1 * V_1 )
{
int V_64 = V_1 -> V_3 -> V_64 ;
int V_87 = V_1 -> V_70 ;
int V_61 ;
for ( V_61 = V_87 ; V_61 < V_87 + V_64 ; V_61 ++ ) {
#ifdef F_45
F_46 ( V_61 , 0 ) ;
#endif
F_43 ( V_61 , NULL , NULL ) ;
F_42 ( V_61 , NULL ) ;
}
}
static int T_4 F_49 ( struct V_1 * V_1 )
{
unsigned int V_91 = V_1 -> V_92 -> V_91 ;
int V_46 = V_1 -> V_92 -> V_46 ;
struct V_21 * V_3 = V_1 -> V_3 ;
T_1 V_93 = 0 ;
unsigned int V_94 ;
T_1 V_62 [ 2 ] ;
int V_6 ;
V_6 = F_18 ( V_1 , V_1 -> V_23 [ V_95 ] ,
F_27 ( V_62 ) , V_62 ) ;
if ( V_6 < 0 )
return V_6 ;
V_94 = ( V_62 [ 0 ] << 8 ) | V_62 [ 1 ] ;
if ( ( V_94 & V_3 -> V_96 ) != V_3 -> V_68 ) {
F_4 ( V_1 -> V_9 , L_12 , V_94 ) ;
return - V_36 ;
}
F_50 ( V_1 -> V_9 , L_13 , V_3 -> V_97 , V_94 ) ;
V_6 = F_14 ( V_1 , ~ 0 ) ;
if ( V_6 )
return V_6 ;
if ( V_1 -> V_61 >= 0 ) {
if ( V_94 == V_69 )
V_93 = V_98 ;
else
V_93 = V_99 ;
if ( V_94 != V_69 ) {
if ( V_91 == V_100 ||
V_91 == V_101 )
V_93 |= V_102 ;
}
if ( V_91 == V_101 ||
V_91 == V_103 ) {
if ( V_94 == V_69 )
V_93 |= V_104 ;
else
V_93 |= V_105 ;
}
if ( V_1 -> V_92 -> V_106 ) {
if ( V_94 == V_69 )
V_93 ^= V_104 ;
else
V_93 ^= V_105 ;
}
}
if ( V_1 -> V_92 -> V_107 ) {
V_6 = F_28 ( V_1 , V_46 ) ;
if ( V_6 )
return V_6 ;
}
return F_16 ( V_1 , V_1 -> V_23 [ V_108 ] , V_93 ) ;
}
static int T_4 F_51 ( struct V_1 * V_1 ,
struct V_109 * V_110 , int V_61 )
{
return F_52 ( V_1 -> V_9 , V_1 -> V_92 -> V_94 , V_110 , 1 ,
NULL , V_1 -> V_70 + V_61 ) ;
}
static int T_4 F_53 ( struct V_1 * V_1 )
{
struct V_21 * V_3 = V_1 -> V_3 ;
unsigned int V_111 = V_1 -> V_92 -> V_2 ;
int V_6 = - V_36 ;
int V_44 ;
for ( V_44 = 0 ; V_44 < V_3 -> V_112 ; V_44 ++ ) {
struct V_113 * V_20 = & V_3 -> V_2 [ V_44 ] ;
if ( ! ( V_111 & V_20 -> V_20 ) )
continue;
V_111 &= ~ V_20 -> V_20 ;
V_6 = F_51 ( V_1 , V_20 -> V_110 , V_20 -> V_61 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_111 )
F_54 ( V_1 -> V_9 ,
L_14 ,
V_111 ) ;
return V_6 ;
}
int T_4 F_55 ( struct V_114 * V_7 , int V_115 )
{
struct V_116 * V_92 = F_56 ( V_7 -> V_9 ) ;
struct V_1 * V_1 ;
int V_6 ;
if ( ! V_92 )
return - V_36 ;
V_1 = F_57 ( sizeof( struct V_1 ) , V_117 ) ;
if ( ! V_1 )
return - V_118 ;
F_58 ( & V_1 -> V_79 ) ;
F_58 ( & V_1 -> V_17 ) ;
V_1 -> V_9 = V_7 -> V_9 ;
V_1 -> V_119 = V_7 -> V_119 ;
V_1 -> V_92 = V_92 ;
V_1 -> V_70 = V_92 -> V_70 ;
V_1 -> V_7 = V_7 ;
V_1 -> V_115 = V_115 ;
V_1 -> V_3 = V_21 [ V_115 ] ;
V_1 -> V_23 = V_1 -> V_3 -> V_23 ;
V_1 -> V_27 = V_1 -> V_3 -> V_27 ;
F_59 ( V_1 -> V_9 , V_1 ) ;
if ( V_7 -> V_120 )
V_7 -> V_120 ( V_1 ) ;
if ( V_92 -> V_121 ) {
V_6 = F_60 ( V_92 -> V_122 , V_123 , L_15 ) ;
if ( V_6 ) {
F_4 ( V_1 -> V_9 , L_16 ,
V_6 ) ;
goto V_124;
}
V_1 -> V_61 = F_61 ( V_92 -> V_122 ) ;
} else {
V_1 -> V_61 = V_7 -> V_61 ;
}
if ( V_1 -> V_61 < 0 ) {
F_50 ( V_1 -> V_9 ,
L_17 ,
V_1 -> V_3 -> V_97 ) ;
if ( ! V_125 [ V_1 -> V_115 ] ) {
F_4 ( V_1 -> V_9 ,
L_18 ,
V_1 -> V_3 -> V_97 ) ;
V_6 = - V_126 ;
goto V_127;
}
V_1 -> V_3 = V_125 [ V_1 -> V_115 ] ;
}
V_6 = F_49 ( V_1 ) ;
if ( V_6 )
goto V_127;
if ( V_1 -> V_61 >= 0 ) {
V_6 = F_41 ( V_1 ) ;
if ( V_6 )
goto V_127;
V_6 = F_62 ( V_1 -> V_61 , NULL , F_34 ,
V_92 -> V_91 | V_128 ,
L_15 , V_1 ) ;
if ( V_6 ) {
F_4 ( V_1 -> V_9 , L_19 ,
V_6 ) ;
goto V_129;
}
}
V_6 = F_53 ( V_1 ) ;
if ( V_6 ) {
F_4 ( V_1 -> V_9 , L_20 ) ;
goto V_130;
}
return 0 ;
V_130:
F_63 ( V_1 -> V_9 ) ;
if ( V_1 -> V_61 >= 0 )
F_64 ( V_1 -> V_61 , V_1 ) ;
V_129:
if ( V_1 -> V_61 >= 0 )
F_48 ( V_1 ) ;
V_127:
if ( V_92 -> V_121 )
F_65 ( V_92 -> V_122 ) ;
V_124:
F_66 ( V_1 ) ;
return V_6 ;
}
int F_67 ( struct V_1 * V_1 )
{
F_63 ( V_1 -> V_9 ) ;
if ( V_1 -> V_61 >= 0 ) {
F_64 ( V_1 -> V_61 , V_1 ) ;
F_48 ( V_1 ) ;
}
if ( V_1 -> V_92 -> V_121 )
F_65 ( V_1 -> V_92 -> V_122 ) ;
F_66 ( V_1 ) ;
return 0 ;
}
static int F_68 ( struct V_131 * V_9 )
{
struct V_1 * V_1 = F_69 ( V_9 ) ;
if ( V_1 -> V_61 >= 0 && F_70 ( V_9 ) )
F_71 ( V_1 -> V_61 ) ;
return 0 ;
}
static int F_72 ( struct V_131 * V_9 )
{
struct V_1 * V_1 = F_69 ( V_9 ) ;
if ( V_1 -> V_61 >= 0 && F_70 ( V_9 ) )
F_73 ( V_1 -> V_61 ) ;
return 0 ;
}
