int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 = 0 ;
if ( ! F_4 ( V_4 ) )
return 0 ;
if ( ! ( F_5 ( V_6 ) & V_8 ) )
V_7 = 1 ;
if ( F_6 ( V_2 ) )
V_7 = 1 ;
return V_7 ;
}
static void F_7 ( struct V_3 * V_4 )
{
F_8 ( V_4 , V_9 , 0 ) ;
}
static T_1 F_9 ( struct V_3 * V_4 )
{
return F_10 ( V_4 , V_9 ) ;
}
static void F_11 ( struct V_3 * V_4 ,
T_1 V_10 )
{
struct V_11 * V_12 = F_12 ( V_4 ) ;
struct V_13 * V_14 = F_13 ( V_12 ) ;
T_1 V_15 ;
int V_16 ;
for ( V_16 = 0 ; V_16 < 1024 ; V_16 ++ ) {
V_15 = F_9 ( V_4 ) ;
if ( V_15 & V_10 )
return;
F_14 ( 50 ) ;
}
F_15 ( V_14 , L_1 ) ;
}
static int F_16 ( struct V_3 * V_17 )
{
struct V_11 * V_12 = F_12 ( V_17 ) ;
if ( F_17 ( V_12 ) )
return 0 ;
F_8 ( V_17 , V_18 ,
F_4 ( V_17 ) ?
0x0e000000 : 0x0f000000 ) ;
return 0 ;
}
static int F_18 ( struct V_3 * V_17 )
{
struct V_11 * V_12 = F_12 ( V_17 ) ;
if ( F_17 ( V_12 ) )
return 0 ;
F_8 ( V_17 , V_18 , 0x00000000 ) ;
return 0 ;
}
T_1 F_19 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_19 * V_20 = F_20 ( V_2 ) ;
struct V_11 * V_12 = F_21 ( V_2 ) ;
struct V_13 * V_14 = F_13 ( V_12 ) ;
enum V_21 V_22 [] = {
V_23 ,
V_24 ,
V_25 ,
} ;
int V_16 , V_26 ;
switch ( V_20 -> V_27 ) {
case 2 :
return 0 ;
case 6 :
break;
default:
F_22 ( V_14 , L_2 ) ;
return 0 ;
}
V_26 = 0 ;
for ( V_16 = 0 ; V_16 < F_23 ( V_22 ) ; V_16 ++ ) {
V_4 = F_24 ( V_2 , V_22 [ V_16 ] ) ;
if ( ! V_4 )
continue;
V_26 |= 1 << F_25 ( V_4 ) ;
}
return V_26 ;
}
static int F_26 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_11 * V_12 = F_21 ( V_2 ) ;
struct V_19 * V_20 = F_20 ( V_2 ) ;
struct V_13 * V_14 = F_13 ( V_12 ) ;
struct V_28 * V_29 = F_27 ( V_2 ) ;
struct V_3 * V_4 = F_28 ( V_6 ) ;
struct V_3 * V_30 = F_29 ( V_2 ) ;
int V_31 = F_30 ( V_2 ) ;
int V_32 , V_33 ;
int V_34 [] = {
1 , 2 , 4 , 8 , 16 , 6 , 12 ,
} ;
unsigned int V_35 ;
unsigned int V_36 = F_31 ( V_12 , V_2 , V_20 ) ;
if ( ! F_32 ( V_29 ) )
return 0 ;
if ( V_30 && ! F_33 ( V_4 , V_2 ) )
return 0 ;
if ( F_34 ( V_4 , V_2 ) )
return 0 ;
if ( V_6 -> V_37 > 1 ) {
if ( V_6 -> V_36 != V_36 ) {
F_22 ( V_14 , L_3 ) ;
return - V_38 ;
}
return 0 ;
}
for ( V_32 = 0 ; V_32 < F_23 ( V_34 ) ; V_32 ++ ) {
V_35 = V_36 * 32 * V_31 * V_34 [ V_32 ] ;
V_33 = F_35 ( V_4 , V_35 ) ;
if ( 0 == V_33 ) {
V_6 -> V_39 = V_40 | V_41 |
V_42 | V_43 | F_36 ( V_32 ) ;
V_6 -> V_44 = V_45 ;
V_6 -> V_36 = V_36 ;
F_37 ( V_14 , L_4 ,
F_38 ( V_4 ) ,
F_25 ( V_4 ) , V_36 ) ;
return 0 ;
}
}
F_22 ( V_14 , L_5 ) ;
return - V_46 ;
}
static void F_39 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_28 * V_29 = F_27 ( V_2 ) ;
struct V_3 * V_4 = F_28 ( V_6 ) ;
struct V_3 * V_30 = F_29 ( V_2 ) ;
if ( ! F_32 ( V_29 ) )
return;
if ( V_30 && ! F_33 ( V_4 , V_2 ) )
return;
if ( V_6 -> V_37 > 1 )
return;
V_6 -> V_39 = 0 ;
V_6 -> V_36 = 0 ;
F_40 ( V_4 ) ;
}
static int F_41 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_28 * V_29 = F_27 ( V_2 ) ;
struct V_19 * V_20 = F_20 ( V_2 ) ;
T_1 V_47 ;
T_1 V_48 ;
T_1 V_44 ;
int V_49 ;
V_49 = ( F_30 ( V_2 ) >= 6 ) ? 1 : 0 ;
V_47 = V_40 | V_41 | V_50 ;
if ( V_29 -> V_51 )
V_47 |= V_52 ;
if ( V_29 -> V_53 ^ V_49 )
V_47 |= V_54 ;
if ( V_29 -> V_55 )
V_47 |= V_56 ;
if ( V_29 -> V_57 )
V_47 |= V_58 ;
if ( F_42 ( V_2 ) )
V_47 |= V_59 ;
switch ( V_20 -> V_60 ) {
case 16 :
V_47 |= V_61 ;
break;
case 32 :
V_47 |= V_62 ;
break;
default:
return - V_38 ;
}
if ( F_4 ( F_28 ( V_6 ) ) ) {
V_48 = V_63 | V_64 |
V_65 ;
} else {
V_48 = V_66 ;
}
V_44 = V_6 -> V_44 ;
if ( V_49 ) {
V_44 |= V_67 ;
V_47 |= V_68 ;
}
V_6 -> V_47 = V_47 ;
V_6 -> V_48 = V_48 ;
V_6 -> V_44 = V_44 ;
return 0 ;
}
static int F_43 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_33 ;
V_6 -> V_37 ++ ;
F_44 ( V_4 ) ;
V_33 = F_26 ( V_6 , V_2 ) ;
if ( V_33 < 0 )
return V_33 ;
if ( F_33 ( V_4 , V_2 ) )
return 0 ;
V_33 = F_41 ( V_6 , V_2 ) ;
if ( V_33 < 0 )
return V_33 ;
V_6 -> V_69 = - 1 ;
F_7 ( V_4 ) ;
F_16 ( V_4 ) ;
return 0 ;
}
static int F_45 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_13 * V_14 = F_13 ( V_12 ) ;
if ( ! V_6 -> V_37 ) {
F_22 ( V_14 , L_6 ,
F_38 ( V_4 ) , F_25 ( V_4 ) ) ;
return - V_46 ;
}
if ( ! F_33 ( V_4 , V_2 ) ) {
if ( V_6 -> V_69 > 0 )
F_15 ( V_14 , L_7 ,
F_38 ( V_4 ) , F_25 ( V_4 ) ,
V_6 -> V_69 ) ;
V_6 -> V_47 = 0 ;
V_6 -> V_69 = 0 ;
F_18 ( V_4 ) ;
}
F_39 ( V_6 , V_2 ) ;
F_46 ( V_4 ) ;
V_6 -> V_37 -- ;
return 0 ;
}
static int F_47 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_70 * V_71 ,
struct V_72 * V_73 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_74 = F_48 ( V_73 ) ;
if ( V_6 -> V_37 > 1 ) {
if ( V_6 -> V_74 != V_74 )
return - V_46 ;
}
V_6 -> V_74 = V_74 ;
return 0 ;
}
static T_1 F_49 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_28 ( V_6 ) ;
T_1 V_15 = F_9 ( V_4 ) ;
if ( V_15 & ( V_75 | V_76 ) )
V_6 -> V_69 ++ ;
return V_15 ;
}
static int F_50 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_77 ;
V_77 = V_6 -> V_47 |
V_6 -> V_39 |
V_6 -> V_48 ;
if ( ! F_19 ( V_2 ) )
V_77 |= V_78 ;
F_8 ( V_4 , V_79 , V_77 ) ;
F_8 ( V_4 , V_80 , V_6 -> V_44 ) ;
return 0 ;
}
static int F_51 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
return F_50 ( V_4 , V_2 , V_12 ) ;
}
static int F_52 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_77 ;
V_77 = V_6 -> V_47 |
V_6 -> V_39 ;
F_8 ( V_4 , V_79 , V_77 | V_78 ) ;
F_11 ( V_4 , V_81 ) ;
F_8 ( V_4 , V_79 , V_77 ) ;
F_11 ( V_4 , V_82 ) ;
return 0 ;
}
static int F_53 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
if ( V_6 -> V_37 > 1 )
return 0 ;
return F_52 ( V_4 , V_2 , V_12 ) ;
}
static void F_54 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_11 * V_12 = F_12 ( V_4 ) ;
struct V_13 * V_14 = F_13 ( V_12 ) ;
int V_83 = F_4 ( V_4 ) ;
T_1 V_15 ;
bool V_84 = false ;
F_55 ( & V_12 -> V_85 ) ;
if ( ! F_56 ( V_2 ) )
goto V_86;
V_15 = F_49 ( V_6 ) ;
if ( ! V_83 && ( V_15 & V_81 ) ) {
struct V_19 * V_20 = F_20 ( V_2 ) ;
T_1 * V_87 = ( T_1 * ) ( V_20 -> V_88 +
F_57 ( V_2 , 0 ) ) ;
if ( F_42 ( V_2 ) )
F_8 ( V_4 , V_89 , * V_87 ) ;
else
* V_87 = F_10 ( V_4 , V_90 ) ;
V_84 = F_58 ( V_2 , sizeof( * V_87 ) ) ;
}
if ( V_83 && ( V_15 & ( V_75 | V_76 ) ) ) {
F_37 ( V_14 , L_8 ,
F_38 ( V_4 ) , F_25 ( V_4 ) ) ;
F_52 ( V_4 , V_2 , V_12 ) ;
F_50 ( V_4 , V_2 , V_12 ) ;
}
if ( V_6 -> V_69 > 1024 ) {
F_18 ( V_4 ) ;
F_15 ( V_14 , L_9 ,
F_38 ( V_4 ) , F_25 ( V_4 ) ) ;
}
F_7 ( V_4 ) ;
V_86:
F_59 ( & V_12 -> V_85 ) ;
if ( V_84 )
F_60 ( V_2 ) ;
}
static T_2 F_61 ( int V_91 , void * V_92 )
{
struct V_3 * V_4 = V_92 ;
F_62 ( V_4 , F_54 ) ;
return V_93 ;
}
static void F_63 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
if ( ! F_64 ( V_4 ) )
return;
switch ( F_25 ( V_4 ) ) {
case 1 :
case 2 :
F_65 ( F_66 ( V_12 , 0 ) , V_2 , V_94 ) ;
break;
case 4 :
F_65 ( F_66 ( V_12 , 3 ) , V_2 , V_94 ) ;
break;
case 8 :
F_65 ( F_66 ( V_12 , 7 ) , V_2 , V_94 ) ;
break;
}
}
static int F_67 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = F_13 ( V_12 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_33 ;
if ( F_34 ( V_4 , V_2 ) )
return 0 ;
F_63 ( V_4 , V_2 , V_12 ) ;
V_33 = F_68 ( V_2 , V_4 ) ;
if ( V_33 < 0 )
return V_33 ;
V_33 = F_69 ( V_14 , V_6 -> V_91 ,
F_61 ,
V_95 ,
F_70 ( V_14 ) , V_4 ) ;
return V_33 ;
}
static int F_71 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_96 = 0 ;
int V_33 ;
if ( F_34 ( V_4 , V_2 ) )
return 0 ;
V_33 = F_67 ( V_4 , V_2 , V_12 ) ;
if ( V_33 )
return V_33 ;
V_6 -> V_97 = F_72 ( V_2 , V_4 , V_96 ) ;
if ( F_73 ( V_6 -> V_97 ) )
return F_74 ( V_6 -> V_97 ) ;
return V_33 ;
}
static int F_75 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_13 * V_14 = F_13 ( V_12 ) ;
int V_91 = V_6 -> V_91 ;
F_76 ( V_14 , V_91 , V_4 ) ;
return 0 ;
}
static int F_77 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = F_13 ( V_12 ) ;
V_4 -> V_98 = & V_99 ;
F_78 ( V_14 , L_10 ,
F_38 ( V_4 ) , F_25 ( V_4 ) ) ;
return 0 ;
}
static struct V_100 * F_79 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_12 = F_12 ( V_4 ) ;
int V_101 = F_42 ( V_2 ) ;
char * V_102 ;
if ( F_1 ( V_2 ) )
V_102 = V_101 ? L_11 : L_12 ;
else
V_102 = V_101 ? L_13 : L_14 ;
return F_80 ( F_81 ( V_12 ) ,
V_4 , V_102 ) ;
}
int F_4 ( struct V_3 * V_4 )
{
return V_4 -> V_98 == & V_103 ;
}
static void F_82 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_28 * V_29 = F_27 ( V_2 ) ;
enum V_21 V_22 [] = {
V_104 ,
V_23 ,
V_24 ,
V_25 ,
} ;
enum V_21 type ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_23 ( V_22 ) ; V_16 ++ ) {
type = V_22 [ V_16 ] ;
if ( ! F_24 ( V_2 , type ) ) {
F_65 ( V_4 , V_2 , type ) ;
F_83 ( V_29 , 2 * ( V_16 + 1 ) , ( V_16 + 1 ) ) ;
return;
}
}
}
void F_84 ( struct V_28 * V_29 ,
struct V_105 * V_106 ,
struct V_105 * V_107 )
{
struct V_11 * V_12 = F_85 ( V_29 ) ;
struct V_105 * V_108 ;
struct V_105 * V_109 ;
struct V_3 * V_4 ;
int V_16 ;
V_108 = F_81 ( V_12 ) ;
if ( ! V_108 )
return;
V_16 = 0 ;
F_86 (node, np) {
V_4 = F_66 ( V_12 , V_16 ) ;
if ( V_109 == V_106 )
F_82 ( V_4 , & V_29 -> V_106 ) ;
if ( V_109 == V_107 )
F_82 ( V_4 , & V_29 -> V_107 ) ;
V_16 ++ ;
}
F_87 ( V_108 ) ;
}
struct V_3 * F_66 ( struct V_11 * V_12 , int V_110 )
{
if ( F_88 ( V_110 < 0 || V_110 >= F_89 ( V_12 ) ) )
V_110 = 0 ;
return F_28 ( F_90 ( V_12 , V_110 ) ) ;
}
int F_64 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
return ! ! ( F_5 ( V_6 ) & V_111 ) ;
}
int F_91 ( struct V_11 * V_12 )
{
struct V_105 * V_108 ;
struct V_105 * V_109 ;
struct V_13 * V_14 = F_13 ( V_12 ) ;
struct V_112 * V_98 ;
struct V_113 * V_113 ;
struct V_5 * V_6 ;
char V_102 [ V_114 ] ;
int V_16 , V_115 , V_33 ;
V_108 = F_81 ( V_12 ) ;
if ( ! V_108 )
return - V_38 ;
V_115 = F_92 ( V_108 ) ;
if ( ! V_115 ) {
V_33 = - V_38 ;
goto V_116;
}
V_6 = F_93 ( V_14 , sizeof( * V_6 ) * V_115 , V_117 ) ;
if ( ! V_6 ) {
V_33 = - V_118 ;
goto V_116;
}
V_12 -> V_6 = V_6 ;
V_12 -> V_119 = V_115 ;
V_16 = 0 ;
F_86 (node, np) {
V_6 = F_90 ( V_12 , V_16 ) ;
snprintf ( V_102 , V_114 , L_15 ,
V_120 , V_16 ) ;
V_113 = F_94 ( V_14 , V_102 ) ;
if ( F_73 ( V_113 ) ) {
V_33 = F_74 ( V_113 ) ;
goto V_116;
}
if ( F_95 ( V_109 , L_16 , NULL ) )
V_6 -> V_121 |= V_111 ;
if ( F_95 ( V_109 , L_17 , NULL ) )
V_6 -> V_121 |= V_8 ;
V_6 -> V_91 = F_96 ( V_109 , 0 ) ;
if ( ! V_6 -> V_91 ) {
V_33 = - V_38 ;
goto V_116;
}
V_98 = & V_122 ;
if ( F_95 ( V_109 , L_18 , NULL ) )
V_98 = & V_99 ;
else
V_98 = & V_103 ;
V_33 = F_97 ( V_12 , F_28 ( V_6 ) , V_98 , V_113 ,
V_104 , V_16 ) ;
if ( V_33 )
goto V_116;
V_16 ++ ;
}
V_33 = 0 ;
V_116:
F_87 ( V_108 ) ;
return V_33 ;
}
void F_98 ( struct V_11 * V_12 )
{
struct V_5 * V_6 ;
int V_16 ;
F_99 (ssi, priv, i) {
F_100 ( F_28 ( V_6 ) ) ;
}
}
