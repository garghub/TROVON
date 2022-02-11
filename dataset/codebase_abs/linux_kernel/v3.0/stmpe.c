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
V_6 = F_4 ( V_1 -> V_7 , V_5 ) ;
if ( V_6 < 0 )
F_5 ( V_1 -> V_8 , L_1 ,
V_5 , V_6 ) ;
F_6 ( V_1 -> V_8 , L_2 , V_5 , V_6 ) ;
return V_6 ;
}
static int F_7 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_9 )
{
int V_6 ;
F_6 ( V_1 -> V_8 , L_3 , V_5 , V_9 ) ;
V_6 = F_8 ( V_1 -> V_7 , V_5 , V_9 ) ;
if ( V_6 < 0 )
F_5 ( V_1 -> V_8 , L_4 ,
V_5 , V_6 ) ;
return V_6 ;
}
static int F_9 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_10 , T_1 V_9 )
{
int V_6 ;
V_6 = F_3 ( V_1 , V_5 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 &= ~ V_10 ;
V_6 |= V_9 ;
return F_7 ( V_1 , V_5 , V_6 ) ;
}
static int F_10 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_11 ,
T_1 * V_12 )
{
int V_6 ;
V_6 = F_11 ( V_1 -> V_7 , V_5 , V_11 , V_12 ) ;
if ( V_6 < 0 )
F_5 ( V_1 -> V_8 , L_5 ,
V_5 , V_6 ) ;
F_6 ( V_1 -> V_8 , L_6 , V_5 , V_11 , V_6 ) ;
F_12 ( L_7 , V_12 , V_11 ) ;
return V_6 ;
}
static int F_13 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_11 ,
const T_1 * V_12 )
{
int V_6 ;
F_6 ( V_1 -> V_8 , L_8 , V_5 , V_11 ) ;
F_12 ( L_9 , V_12 , V_11 ) ;
V_6 = F_14 ( V_1 -> V_7 , V_5 , V_11 ,
V_12 ) ;
if ( V_6 < 0 )
F_5 ( V_1 -> V_8 , L_10 ,
V_5 , V_6 ) ;
return V_6 ;
}
int F_15 ( struct V_1 * V_1 , unsigned int V_2 )
{
int V_6 ;
F_16 ( & V_1 -> V_13 ) ;
V_6 = F_1 ( V_1 , V_2 ) ;
F_17 ( & V_1 -> V_13 ) ;
return V_6 ;
}
int F_18 ( struct V_1 * V_1 , unsigned int V_2 )
{
int V_6 ;
F_16 ( & V_1 -> V_13 ) ;
V_6 = F_2 ( V_1 , V_2 ) ;
F_17 ( & V_1 -> V_13 ) ;
return V_6 ;
}
int F_19 ( struct V_1 * V_1 , T_1 V_5 )
{
int V_6 ;
F_16 ( & V_1 -> V_13 ) ;
V_6 = F_3 ( V_1 , V_5 ) ;
F_17 ( & V_1 -> V_13 ) ;
return V_6 ;
}
int F_20 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_9 )
{
int V_6 ;
F_16 ( & V_1 -> V_13 ) ;
V_6 = F_7 ( V_1 , V_5 , V_9 ) ;
F_17 ( & V_1 -> V_13 ) ;
return V_6 ;
}
int F_21 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_10 , T_1 V_9 )
{
int V_6 ;
F_16 ( & V_1 -> V_13 ) ;
V_6 = F_9 ( V_1 , V_5 , V_10 , V_9 ) ;
F_17 ( & V_1 -> V_13 ) ;
return V_6 ;
}
int F_22 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_11 , T_1 * V_12 )
{
int V_6 ;
F_16 ( & V_1 -> V_13 ) ;
V_6 = F_10 ( V_1 , V_5 , V_11 , V_12 ) ;
F_17 ( & V_1 -> V_13 ) ;
return V_6 ;
}
int F_23 ( struct V_1 * V_1 , T_1 V_5 , T_1 V_11 ,
const T_1 * V_12 )
{
int V_6 ;
F_16 ( & V_1 -> V_13 ) ;
V_6 = F_13 ( V_1 , V_5 , V_11 , V_12 ) ;
F_17 ( & V_1 -> V_13 ) ;
return V_6 ;
}
int F_24 ( struct V_1 * V_1 , T_2 V_14 , enum V_15 V_16 )
{
struct V_17 * V_3 = V_1 -> V_3 ;
T_1 V_18 = V_1 -> V_19 [ V_20 ] ;
int V_21 = V_3 -> V_21 ;
int V_22 = F_25 ( V_1 -> V_23 * V_21 , 8 ) ;
int V_24 = 8 / V_21 ;
int V_10 = ( 1 << V_21 ) - 1 ;
T_1 V_19 [ V_22 ] ;
int V_25 ;
int V_6 ;
F_16 ( & V_1 -> V_13 ) ;
V_6 = F_1 ( V_1 , V_26 ) ;
if ( V_6 < 0 )
goto V_27;
V_6 = F_10 ( V_1 , V_18 , V_22 , V_19 ) ;
if ( V_6 < 0 )
goto V_27;
V_25 = V_3 -> V_28 ( V_1 , V_16 ) ;
while ( V_14 ) {
int V_29 = F_26 ( V_14 ) ;
int V_30 = V_22 - ( V_29 / V_24 ) - 1 ;
int V_31 = ( V_29 % V_24 ) * ( 8 / V_24 ) ;
V_19 [ V_30 ] &= ~ ( V_10 << V_31 ) ;
V_19 [ V_30 ] |= V_25 << V_31 ;
V_14 &= ~ ( 1 << V_29 ) ;
}
V_6 = F_13 ( V_1 , V_18 , V_22 , V_19 ) ;
V_27:
F_17 ( & V_1 -> V_13 ) ;
return V_6 ;
}
static int F_27 ( struct V_1 * V_1 , unsigned int V_2 ,
bool V_4 )
{
unsigned int V_10 = 0 ;
if ( V_2 & V_26 )
V_10 |= V_32 ;
if ( V_2 & V_33 )
V_10 |= V_34 ;
if ( V_2 & V_35 )
V_10 |= V_36 ;
return F_9 ( V_1 , V_37 , V_10 ,
V_4 ? 0 : V_10 ) ;
}
static int F_28 ( struct V_1 * V_1 , enum V_15 V_16 )
{
return V_16 != V_35 ;
}
static int F_29 ( int V_38 )
{
int V_39 ;
for ( V_39 = 0 ; V_39 < F_30 ( V_40 ) ; V_39 ++ ) {
if ( V_40 [ V_39 ] >= V_38 )
return V_39 ;
}
return - V_41 ;
}
static int F_31 ( struct V_1 * V_1 , int V_42 )
{
int V_6 ;
if ( ! V_1 -> V_3 -> V_43 )
return - V_44 ;
F_16 ( & V_1 -> V_13 ) ;
V_6 = V_1 -> V_3 -> V_43 ( V_1 , V_42 ) ;
F_17 ( & V_1 -> V_13 ) ;
return V_6 ;
}
static int F_32 ( struct V_1 * V_1 ,
int V_42 )
{
int V_6 , V_38 ;
V_38 = F_29 ( V_42 ) ;
if ( V_38 < 0 ) {
F_5 ( V_1 -> V_8 , L_11 ) ;
return V_38 ;
}
V_6 = F_9 ( V_1 , V_45 ,
V_46 ,
V_38 ) ;
if ( V_6 < 0 )
return V_6 ;
return F_9 ( V_1 , V_45 ,
V_47 ,
V_47 ) ;
}
static int F_33 ( struct V_1 * V_1 , unsigned int V_2 ,
bool V_4 )
{
unsigned int V_10 = 0 ;
if ( V_2 & V_26 )
V_10 |= V_48 ;
if ( V_2 & V_49 )
V_10 |= V_50 ;
return F_9 ( V_1 , V_51 , V_10 ,
V_4 ? V_10 : 0 ) ;
}
static int F_34 ( struct V_1 * V_1 , enum V_15 V_16 )
{
switch ( V_16 ) {
case V_52 :
return 2 ;
case V_49 :
return 1 ;
case V_26 :
default:
return 0 ;
}
}
static int F_35 ( struct V_1 * V_1 , unsigned int V_2 ,
bool V_4 )
{
unsigned int V_10 = 0 ;
if ( V_2 & V_26 )
V_10 |= V_53 ;
if ( V_2 & V_49 )
V_10 |= V_54 ;
return F_9 ( V_1 , V_55 , V_10 ,
V_4 ? V_10 : 0 ) ;
}
static int F_36 ( struct V_1 * V_1 , enum V_15 V_16 )
{
switch ( V_16 ) {
case V_56 :
return 2 ;
case V_49 :
return 1 ;
case V_26 :
default:
return 0 ;
}
}
static T_3 F_37 ( int V_57 , void * V_58 )
{
struct V_1 * V_1 = V_58 ;
struct V_17 * V_3 = V_1 -> V_3 ;
int V_59 = F_25 ( V_3 -> V_60 , 8 ) ;
T_1 V_61 = V_1 -> V_19 [ V_62 ] ;
T_1 V_63 [ V_59 ] ;
int V_6 ;
int V_39 ;
V_6 = F_22 ( V_1 , V_61 , V_59 , V_63 ) ;
if ( V_6 < 0 )
return V_64 ;
for ( V_39 = 0 ; V_39 < V_59 ; V_39 ++ ) {
int V_65 = V_59 - V_39 - 1 ;
T_1 V_66 = V_63 [ V_39 ] ;
T_1 V_67 ;
V_66 &= V_1 -> V_68 [ V_65 ] ;
if ( ! V_66 )
continue;
V_67 = V_66 ;
while ( V_66 ) {
int V_69 = F_26 ( V_66 ) ;
int line = V_65 * 8 + V_69 ;
F_38 ( V_1 -> V_70 + line ) ;
V_66 &= ~ ( 1 << V_69 ) ;
}
F_20 ( V_1 , V_61 + V_39 , V_67 ) ;
}
return V_71 ;
}
static void F_39 ( struct V_72 * V_58 )
{
struct V_1 * V_1 = F_40 ( V_58 ) ;
F_16 ( & V_1 -> V_73 ) ;
}
static void F_41 ( struct V_72 * V_58 )
{
struct V_1 * V_1 = F_40 ( V_58 ) ;
struct V_17 * V_3 = V_1 -> V_3 ;
int V_59 = F_25 ( V_3 -> V_60 , 8 ) ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_59 ; V_39 ++ ) {
T_1 V_74 = V_1 -> V_68 [ V_39 ] ;
T_1 V_75 = V_1 -> V_76 [ V_39 ] ;
if ( V_74 == V_75 )
continue;
V_1 -> V_76 [ V_39 ] = V_74 ;
F_20 ( V_1 , V_1 -> V_19 [ V_77 ] - V_39 , V_74 ) ;
}
F_17 ( & V_1 -> V_73 ) ;
}
static void F_42 ( struct V_72 * V_58 )
{
struct V_1 * V_1 = F_40 ( V_58 ) ;
int V_78 = V_58 -> V_57 - V_1 -> V_70 ;
int V_30 = V_78 / 8 ;
int V_10 = 1 << ( V_78 % 8 ) ;
V_1 -> V_68 [ V_30 ] &= ~ V_10 ;
}
static void F_43 ( struct V_72 * V_58 )
{
struct V_1 * V_1 = F_40 ( V_58 ) ;
int V_78 = V_58 -> V_57 - V_1 -> V_70 ;
int V_30 = V_78 / 8 ;
int V_10 = 1 << ( V_78 % 8 ) ;
V_1 -> V_68 [ V_30 ] |= V_10 ;
}
static int T_4 F_44 ( struct V_1 * V_1 )
{
int V_60 = V_1 -> V_3 -> V_60 ;
int V_79 = V_1 -> V_70 ;
int V_57 ;
for ( V_57 = V_79 ; V_57 < V_79 + V_60 ; V_57 ++ ) {
F_45 ( V_57 , V_1 ) ;
F_46 ( V_57 , & V_80 ,
V_81 ) ;
F_47 ( V_57 , 1 ) ;
#ifdef F_48
F_49 ( V_57 , V_82 ) ;
#else
F_50 ( V_57 ) ;
#endif
}
return 0 ;
}
static void F_51 ( struct V_1 * V_1 )
{
int V_60 = V_1 -> V_3 -> V_60 ;
int V_79 = V_1 -> V_70 ;
int V_57 ;
for ( V_57 = V_79 ; V_57 < V_79 + V_60 ; V_57 ++ ) {
#ifdef F_48
F_49 ( V_57 , 0 ) ;
#endif
F_46 ( V_57 , NULL , NULL ) ;
F_45 ( V_57 , NULL ) ;
}
}
static int T_4 F_52 ( struct V_1 * V_1 )
{
unsigned int V_83 = V_1 -> V_84 -> V_83 ;
int V_42 = V_1 -> V_84 -> V_42 ;
struct V_17 * V_3 = V_1 -> V_3 ;
T_1 V_85 = V_86 ;
unsigned int V_87 ;
T_1 V_58 [ 2 ] ;
int V_6 ;
V_6 = F_22 ( V_1 , V_1 -> V_19 [ V_88 ] ,
F_30 ( V_58 ) , V_58 ) ;
if ( V_6 < 0 )
return V_6 ;
V_87 = ( V_58 [ 0 ] << 8 ) | V_58 [ 1 ] ;
if ( ( V_87 & V_3 -> V_89 ) != V_3 -> V_90 ) {
F_5 ( V_1 -> V_8 , L_12 , V_87 ) ;
return - V_41 ;
}
F_53 ( V_1 -> V_8 , L_13 , V_3 -> V_91 , V_87 ) ;
V_6 = F_18 ( V_1 , ~ 0 ) ;
if ( V_6 )
return V_6 ;
if ( V_83 == V_92 ||
V_83 == V_93 )
V_85 |= V_94 ;
if ( V_83 == V_93 ||
V_83 == V_95 )
V_85 |= V_96 ;
if ( V_1 -> V_84 -> V_97 )
V_85 ^= V_96 ;
if ( V_1 -> V_84 -> V_98 ) {
V_6 = F_31 ( V_1 , V_42 ) ;
if ( V_6 )
return V_6 ;
}
return F_20 ( V_1 , V_1 -> V_19 [ V_99 ] , V_85 ) ;
}
static int T_4 F_54 ( struct V_1 * V_1 ,
struct V_100 * V_101 , int V_57 )
{
return F_55 ( V_1 -> V_8 , V_1 -> V_84 -> V_87 , V_101 , 1 ,
NULL , V_1 -> V_70 + V_57 ) ;
}
static int T_4 F_56 ( struct V_1 * V_1 )
{
struct V_17 * V_3 = V_1 -> V_3 ;
unsigned int V_102 = V_1 -> V_84 -> V_2 ;
int V_6 = - V_41 ;
int V_39 ;
for ( V_39 = 0 ; V_39 < V_3 -> V_103 ; V_39 ++ ) {
struct V_104 * V_16 = & V_3 -> V_2 [ V_39 ] ;
if ( ! ( V_102 & V_16 -> V_16 ) )
continue;
V_102 &= ~ V_16 -> V_16 ;
V_6 = F_54 ( V_1 , V_16 -> V_101 , V_16 -> V_57 ) ;
if ( V_6 )
return V_6 ;
}
if ( V_102 )
F_57 ( V_1 -> V_8 ,
L_14 ,
V_102 ) ;
return V_6 ;
}
static int F_58 ( struct V_105 * V_8 )
{
struct V_106 * V_7 = F_59 ( V_8 ) ;
if ( F_60 ( & V_7 -> V_8 ) )
F_61 ( V_7 -> V_57 ) ;
return 0 ;
}
static int F_62 ( struct V_105 * V_8 )
{
struct V_106 * V_7 = F_59 ( V_8 ) ;
if ( F_60 ( & V_7 -> V_8 ) )
F_63 ( V_7 -> V_57 ) ;
return 0 ;
}
static int T_4 F_64 ( struct V_106 * V_7 ,
const struct V_107 * V_87 )
{
struct V_108 * V_84 = V_7 -> V_8 . V_109 ;
struct V_1 * V_1 ;
int V_6 ;
if ( ! V_84 )
return - V_41 ;
V_1 = F_65 ( sizeof( struct V_1 ) , V_110 ) ;
if ( ! V_1 )
return - V_111 ;
F_66 ( & V_1 -> V_73 ) ;
F_66 ( & V_1 -> V_13 ) ;
V_1 -> V_8 = & V_7 -> V_8 ;
V_1 -> V_7 = V_7 ;
V_1 -> V_84 = V_84 ;
V_1 -> V_70 = V_84 -> V_70 ;
V_1 -> V_112 = V_87 -> V_113 ;
V_1 -> V_3 = V_17 [ V_1 -> V_112 ] ;
V_1 -> V_19 = V_1 -> V_3 -> V_19 ;
V_1 -> V_23 = V_1 -> V_3 -> V_23 ;
F_67 ( V_7 , V_1 ) ;
V_6 = F_52 ( V_1 ) ;
if ( V_6 )
goto V_114;
V_6 = F_44 ( V_1 ) ;
if ( V_6 )
goto V_114;
V_6 = F_68 ( V_1 -> V_7 -> V_57 , NULL , F_37 ,
V_84 -> V_83 | V_115 ,
L_15 , V_1 ) ;
if ( V_6 ) {
F_5 ( V_1 -> V_8 , L_16 , V_6 ) ;
goto V_116;
}
V_6 = F_56 ( V_1 ) ;
if ( V_6 ) {
F_5 ( V_1 -> V_8 , L_17 ) ;
goto V_117;
}
return 0 ;
V_117:
F_69 ( V_1 -> V_8 ) ;
F_70 ( V_1 -> V_7 -> V_57 , V_1 ) ;
V_116:
F_51 ( V_1 ) ;
V_114:
F_71 ( V_1 ) ;
return V_6 ;
}
static int T_5 F_72 ( struct V_106 * V_118 )
{
struct V_1 * V_1 = F_73 ( V_118 ) ;
F_69 ( V_1 -> V_8 ) ;
F_70 ( V_1 -> V_7 -> V_57 , V_1 ) ;
F_51 ( V_1 ) ;
F_71 ( V_1 ) ;
return 0 ;
}
static int T_6 F_74 ( void )
{
return F_75 ( & V_119 ) ;
}
static void T_7 F_76 ( void )
{
F_77 ( & V_119 ) ;
}
