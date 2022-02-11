static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
T_1 V_4 =
V_5 |
F_2 ( V_3 ) ;
T_1 V_6 =
V_7 |
F_3 ( 1 ) |
F_2 ( V_3 ) ;
F_4 ( V_2 -> V_8 , V_9 , V_4 ) ;
F_4 ( V_2 -> V_10 , F_5 ( V_11 ) ,
V_4 ) ;
F_4 ( V_2 -> V_10 , F_5 ( V_12 ) ,
V_6 ) ;
F_4 ( V_2 -> V_10 , F_5 ( V_13 ) ,
V_14 |
V_15 |
V_16 |
V_17 |
V_18 |
V_19 |
F_3 ( V_2 -> V_20 ) |
F_2 ( V_3 ) ) ;
F_4 ( V_2 -> V_10 , F_5 ( V_21 ) ,
V_22 |
V_23 |
V_24 |
V_25 |
V_26 |
V_27 |
V_28 |
F_3 ( V_2 -> V_20 ) |
F_2 ( V_3 ) ) ;
F_4 ( V_2 -> V_8 , V_9 , V_6 |
V_29 ) ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned V_3 , int * V_30 )
{
F_1 ( V_2 , V_3 ) ;
F_4 ( V_2 -> V_10 , V_31 ,
F_7 ( 0 , V_11 ) |
F_7 ( 1 , V_12 ) |
F_7 ( 2 , V_13 ) |
F_7 ( 3 , V_21 ) |
F_7 ( 4 , V_11 ) |
F_7 ( 5 , V_12 ) ) ;
V_2 -> V_32 = V_2 -> V_20 * 2 + 2 ;
* V_30 = 6 ;
return 0 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_10 , V_33 , V_34 ,
V_34 ) ;
}
static void F_10 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_10 , V_33 , V_34 , 0 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_10 , V_35 , V_36 ,
V_36 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_10 , V_35 , V_36 , 0 ) ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_10 , V_33 ,
V_37 ,
V_37 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
F_9 ( V_2 -> V_10 , V_33 ,
V_37 , 0 ) ;
}
static void F_15 ( struct V_1 * V_2 )
{
T_1 V_38 ;
F_16 ( V_2 -> V_10 , V_33 , & V_38 ) ;
F_9 ( V_2 -> V_10 , V_33 , V_39 ,
V_39 ) ;
F_9 ( V_2 -> V_10 , V_33 , V_39 , 0 ) ;
F_4 ( V_2 -> V_10 , V_33 , V_38 ) ;
}
static void F_17 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_4 ( V_2 -> V_8 , V_9 , V_5 ) ;
F_15 ( V_2 ) ;
F_4 ( V_2 -> V_8 , V_9 ,
V_7 | V_29 ) ;
F_9 ( V_2 -> V_10 , V_40 , V_41 ,
V_41 ) ;
F_9 ( V_2 -> V_10 , V_35 , V_42 , 0 ) ;
F_10 ( V_2 ) ;
}
static void F_18 ( struct V_1 * V_2 ,
T_1 * V_43 ,
unsigned int V_44 )
{
unsigned int V_45 = 0 ;
unsigned int V_46 = 0 ;
unsigned int V_47 = 0 ;
unsigned int V_48 = 0 ;
unsigned int V_49 ;
for ( V_49 = 0 ; V_49 < V_44 ; V_49 ++ ) {
unsigned int V_50 = F_19 ( V_43 [ V_49 ] ) ;
unsigned int V_51 = F_20 ( V_43 [ V_49 ] ) ;
switch ( V_50 ) {
case 1 :
V_47 = V_51 ;
break;
case 2 :
V_45 = V_51 ;
break;
case 3 :
V_46 = V_51 ;
break;
case 5 :
V_48 = V_51 ;
break;
default:
F_21 ( V_2 -> V_52 , L_1 ,
V_50 ) ;
return;
}
}
if ( V_44 != 0 ) {
if ( V_47 < V_2 -> V_53 &&
V_48 < V_2 -> V_53 ) {
V_45 /= V_2 -> V_20 ;
V_46 /= V_2 -> V_20 ;
F_22 ( V_2 -> V_54 , V_55 , V_45 ) ;
F_22 ( V_2 -> V_54 , V_56 , V_46 ) ;
F_23 ( V_2 -> V_54 , V_57 , 1 ) ;
F_24 ( V_2 -> V_54 ) ;
F_12 ( V_2 ) ;
} else if ( V_47 >= V_2 -> V_53 &&
V_48 >= V_2 -> V_53 ) {
F_23 ( V_2 -> V_54 , V_57 , 0 ) ;
F_24 ( V_2 -> V_54 ) ;
F_17 ( V_2 ) ;
} else {
F_12 ( V_2 ) ;
}
}
}
static T_2 F_25 ( int V_58 , void * V_59 )
{
struct V_1 * V_2 = V_59 ;
T_1 V_43 [ V_60 ] ;
unsigned int V_44 ;
T_1 V_61 ;
unsigned int V_49 ;
F_16 ( V_2 -> V_10 , V_40 , & V_61 ) ;
V_44 = F_26 ( V_61 ) ;
V_44 -= V_44 % V_2 -> V_20 ;
if ( ! V_44 )
return V_62 ;
for ( V_49 = 0 ; V_49 != V_44 ; ++ V_49 )
F_16 ( V_2 -> V_10 , V_63 , & V_43 [ V_49 ] ) ;
F_18 ( V_2 , V_43 , V_44 ) ;
return V_62 ;
}
static T_2 F_27 ( int V_58 , void * V_59 )
{
struct V_1 * V_2 = V_59 ;
T_1 V_64 ;
int V_65 = V_62 ;
F_16 ( V_2 -> V_10 , V_40 , & V_64 ) ;
if ( V_64 & ( V_66 | V_67 | V_68 ) )
F_17 ( V_2 ) ;
if ( V_64 & V_41 ) {
F_8 ( V_2 ) ;
F_13 ( V_2 ) ;
F_12 ( V_2 ) ;
}
if ( V_64 & V_69 ) {
F_11 ( V_2 ) ;
V_65 = V_70 ;
}
F_9 ( V_2 -> V_10 , V_40 , V_66 |
V_67 | V_68 |
V_41 ,
V_66 | V_67 |
V_68 | V_41 ) ;
return V_65 ;
}
static int F_28 ( struct V_1 * V_2 )
{
T_1 V_71 ;
unsigned int V_72 ;
unsigned int V_73 ;
unsigned int V_74 ;
unsigned int V_3 ;
int V_75 ;
int error ;
F_16 ( V_2 -> V_8 , V_76 , & V_71 ) ;
V_72 = F_29 (unsigned int, 4 , MX25_TGCR_GET_ADCCLK(tgcr)) ;
V_73 = V_77 * V_72 * 2 + 2 ;
V_73 /= F_30 ( V_2 -> V_78 ) / 1000 + 1 ;
V_74 = F_31 ( V_2 -> V_79 , V_73 * 8 ) - 1 ;
V_3 = F_31 ( V_2 -> V_80 , V_73 * 8 ) - 1 ;
F_4 ( V_2 -> V_10 , V_33 ,
V_81 | V_39 ) ;
F_9 ( V_2 -> V_10 , V_33 ,
V_81 | V_39 , 0 ) ;
if ( V_74 > 127 )
V_74 = 127 ;
if ( V_3 > 255 )
V_3 = 255 ;
error = F_6 ( V_2 , V_3 , & V_75 ) ;
if ( error )
return error ;
F_9 ( V_2 -> V_10 , V_33 ,
V_82 | V_83 ,
F_32 ( V_75 - 1 ) |
F_33 ( V_2 -> V_32 - 1 ) ) ;
F_9 ( V_2 -> V_8 , V_76 ,
V_84 ,
F_34 ( V_74 ) ) ;
F_9 ( V_2 -> V_8 , V_76 , V_85 ,
V_85 ) ;
F_9 ( V_2 -> V_8 , V_76 , V_86 ,
V_86 ) ;
F_9 ( V_2 -> V_10 , V_33 , V_87 ,
V_88 ) ;
F_9 ( V_2 -> V_10 , V_33 ,
V_89 | V_90 ,
V_89 |
F_35 ( V_91 ) ) ;
return 0 ;
}
static int F_36 ( struct V_92 * V_93 ,
struct V_1 * V_2 )
{
struct V_94 * V_95 = V_93 -> V_52 . V_96 ;
T_1 V_97 ;
int error ;
V_2 -> V_53 = 500 ;
V_2 -> V_20 = 3 ;
V_2 -> V_79 = 1000000 ;
V_2 -> V_80 = 250000 ;
error = F_37 ( V_95 , L_2 , & V_97 ) ;
if ( error ) {
F_38 ( & V_93 -> V_52 , L_3 ) ;
return error ;
}
if ( V_97 == 4 ) {
V_2 -> V_98 = V_99 ;
} else {
F_38 ( & V_93 -> V_52 , L_4 , V_97 ) ;
return - V_100 ;
}
F_37 ( V_95 , L_5 , & V_2 -> V_53 ) ;
F_37 ( V_95 , L_6 , & V_2 -> V_80 ) ;
F_37 ( V_95 , L_7 , & V_2 -> V_79 ) ;
return 0 ;
}
static int F_39 ( struct V_101 * V_54 )
{
struct V_102 * V_52 = & V_54 -> V_52 ;
struct V_1 * V_2 = F_40 ( V_52 ) ;
int error ;
error = F_41 ( V_2 -> V_78 ) ;
if ( error ) {
F_38 ( V_52 , L_8 ) ;
return error ;
}
error = F_28 ( V_2 ) ;
if ( error ) {
F_38 ( V_52 , L_9 ) ;
F_42 ( V_2 -> V_78 ) ;
return error ;
}
F_17 ( V_2 ) ;
return 0 ;
}
static void F_43 ( struct V_101 * V_54 )
{
struct V_1 * V_2 = F_44 ( V_54 ) ;
F_14 ( V_2 ) ;
F_8 ( V_2 ) ;
F_11 ( V_2 ) ;
F_42 ( V_2 -> V_78 ) ;
}
static int F_45 ( struct V_92 * V_93 )
{
struct V_102 * V_52 = & V_93 -> V_52 ;
struct V_101 * V_54 ;
struct V_1 * V_2 ;
struct V_103 * V_104 = F_40 ( V_52 -> V_105 ) ;
struct V_106 * V_107 ;
void T_3 * V_108 ;
int error ;
V_2 = F_46 ( V_52 , sizeof( * V_2 ) , V_109 ) ;
if ( ! V_2 )
return - V_110 ;
V_2 -> V_52 = V_52 ;
V_107 = F_47 ( V_93 , V_111 , 0 ) ;
V_108 = F_48 ( V_52 , V_107 ) ;
if ( F_49 ( V_108 ) )
return F_50 ( V_108 ) ;
error = F_36 ( V_93 , V_2 ) ;
if ( error )
return error ;
V_2 -> V_10 = F_51 ( V_52 , V_108 , & V_112 ) ;
if ( F_49 ( V_2 -> V_10 ) ) {
F_38 ( V_52 , L_10 ) ;
return F_50 ( V_2 -> V_10 ) ;
}
V_2 -> V_58 = F_52 ( V_93 , 0 ) ;
if ( V_2 -> V_58 <= 0 ) {
F_38 ( V_52 , L_11 ) ;
return V_2 -> V_58 ;
}
V_54 = F_53 ( V_52 ) ;
if ( ! V_54 ) {
F_38 ( V_52 , L_12 ) ;
return - V_110 ;
}
V_54 -> V_113 = V_114 ;
F_54 ( V_54 , V_115 , V_57 ) ;
F_55 ( V_54 , V_55 , 0 , 0xfff , 0 , 0 ) ;
F_55 ( V_54 , V_56 , 0 , 0xfff , 0 , 0 ) ;
V_54 -> V_116 . V_117 = V_118 ;
V_54 -> V_119 = F_39 ;
V_54 -> V_120 = F_43 ;
V_2 -> V_54 = V_54 ;
F_56 ( V_54 , V_2 ) ;
V_2 -> V_8 = V_104 -> V_10 ;
if ( ! V_2 -> V_8 )
return - V_100 ;
V_2 -> V_78 = V_104 -> V_78 ;
if ( ! V_2 -> V_78 )
return - V_100 ;
F_57 ( V_93 , V_2 ) ;
error = F_58 ( V_52 , V_2 -> V_58 , F_27 ,
F_25 , 0 , V_93 -> V_113 ,
V_2 ) ;
if ( error ) {
F_38 ( V_52 , L_13 ) ;
return error ;
}
error = F_59 ( V_54 ) ;
if ( error ) {
F_38 ( V_52 , L_14 ) ;
return error ;
}
return 0 ;
}
