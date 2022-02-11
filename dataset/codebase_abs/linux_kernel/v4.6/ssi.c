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
F_15 ( V_14 , L_1 ,
F_16 ( V_4 ) , F_17 ( V_4 ) ) ;
}
static T_1 F_18 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
enum V_17 V_18 [] = {
V_19 ,
V_20 ,
V_21 ,
} ;
int V_16 , V_22 ;
V_22 = 0 ;
for ( V_16 = 0 ; V_16 < F_19 ( V_18 ) ; V_16 ++ ) {
V_4 = F_20 ( V_2 , V_18 [ V_16 ] ) ;
if ( ! V_4 )
continue;
V_22 |= 1 << F_17 ( V_4 ) ;
}
return V_22 ;
}
static T_1 F_21 ( struct V_1 * V_2 )
{
struct V_3 * V_23 = F_2 ( V_2 ) ;
struct V_3 * V_24 = F_22 ( V_2 ) ;
return F_23 ( V_2 ) |
1 << F_17 ( V_23 ) |
1 << F_17 ( V_24 ) ;
}
T_1 F_23 ( struct V_1 * V_2 )
{
if ( F_24 ( V_2 ) )
return F_18 ( V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
struct V_13 * V_14 = F_13 ( V_12 ) ;
struct V_25 * V_26 = F_27 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_3 * V_24 = F_22 ( V_2 ) ;
int V_27 = F_28 ( V_2 ) ;
int V_28 , V_29 ;
int V_30 [] = {
1 , 2 , 4 , 8 , 16 , 6 , 12 ,
} ;
unsigned int V_31 ;
unsigned int V_32 = F_29 ( V_2 ) ?
F_30 ( V_12 , V_2 ) :
F_31 ( V_12 , V_2 ) ;
if ( ! F_32 ( V_26 ) )
return 0 ;
if ( V_24 && ! F_33 ( V_4 , V_2 ) )
return 0 ;
if ( F_34 ( V_4 , V_2 ) )
return 0 ;
if ( V_6 -> V_33 > 1 ) {
if ( V_6 -> V_32 != V_32 ) {
F_35 ( V_14 , L_2 ) ;
return - V_34 ;
}
return 0 ;
}
for ( V_28 = 0 ; V_28 < F_19 ( V_30 ) ; V_28 ++ ) {
V_31 = V_32 * 32 * V_27 * V_30 [ V_28 ] ;
V_29 = F_36 ( V_4 , V_31 ) ;
if ( 0 == V_29 ) {
V_6 -> V_35 = V_36 | V_37 |
V_38 | V_39 | F_37 ( V_28 ) ;
V_6 -> V_40 = V_41 ;
V_6 -> V_32 = V_32 ;
F_38 ( V_14 , L_3 ,
F_16 ( V_4 ) ,
F_17 ( V_4 ) , V_32 ) ;
return 0 ;
}
}
F_35 ( V_14 , L_4 ) ;
return - V_42 ;
}
static void F_39 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = F_27 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_3 * V_24 = F_22 ( V_2 ) ;
if ( ! F_32 ( V_26 ) )
return;
if ( V_24 && ! F_33 ( V_4 , V_2 ) )
return;
if ( V_6 -> V_33 > 1 )
return;
V_6 -> V_35 = 0 ;
V_6 -> V_32 = 0 ;
F_40 ( V_4 ) ;
}
static void F_41 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = F_27 ( V_2 ) ;
struct V_43 * V_44 = F_42 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_45 ;
T_1 V_46 ;
T_1 V_40 ;
int V_47 ;
V_47 = F_43 ( V_2 ) ;
V_45 = V_36 | V_37 | V_48 ;
if ( V_26 -> V_49 )
V_45 |= V_50 ;
if ( V_26 -> V_51 ^ V_47 )
V_45 |= V_52 ;
if ( V_26 -> V_53 )
V_45 |= V_54 ;
if ( V_26 -> V_55 )
V_45 |= V_56 ;
if ( F_29 ( V_2 ) )
V_45 |= V_57 ;
switch ( V_44 -> V_58 ) {
case 16 :
V_45 |= V_59 ;
break;
case 32 :
V_45 |= V_60 ;
break;
}
if ( F_4 ( V_4 ) ) {
V_46 = V_61 | V_62 |
V_63 ;
} else {
V_46 = V_64 ;
}
V_40 = V_6 -> V_40 ;
if ( V_47 ) {
V_40 |= V_65 ;
V_45 |= V_66 ;
}
V_6 -> V_45 = V_45 ;
V_6 -> V_46 = V_46 ;
V_6 -> V_40 = V_40 ;
}
static void F_44 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_8 ( V_4 , V_67 , V_6 -> V_40 ) ;
F_8 ( V_4 , V_68 , V_6 -> V_45 |
V_6 -> V_35 |
V_6 -> V_46 ) ;
}
static int F_45 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_29 ;
if ( ! F_46 ( V_4 , V_2 ) )
return 0 ;
V_6 -> V_33 ++ ;
F_47 ( V_4 ) ;
V_29 = F_25 ( V_4 , V_2 ) ;
if ( V_29 < 0 )
return V_29 ;
if ( ! F_33 ( V_4 , V_2 ) )
F_41 ( V_4 , V_2 ) ;
F_44 ( V_4 ) ;
F_7 ( V_4 ) ;
return 0 ;
}
static int F_48 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_13 * V_14 = F_13 ( V_12 ) ;
if ( ! F_46 ( V_4 , V_2 ) )
return 0 ;
if ( ! V_6 -> V_33 ) {
F_35 ( V_14 , L_5 ,
F_16 ( V_4 ) , F_17 ( V_4 ) ) ;
return - V_42 ;
}
if ( ! F_33 ( V_4 , V_2 ) )
V_6 -> V_45 = 0 ;
F_39 ( V_4 , V_2 ) ;
F_49 ( V_4 ) ;
V_6 -> V_33 -- ;
return 0 ;
}
static int F_50 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_69 * V_70 ,
struct V_71 * V_72 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_27 = F_51 ( V_72 ) ;
if ( V_6 -> V_33 > 1 ) {
if ( V_6 -> V_27 != V_27 )
return - V_42 ;
}
V_6 -> V_27 = V_27 ;
return 0 ;
}
static int F_52 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
if ( ! F_46 ( V_4 , V_2 ) )
return 0 ;
if ( F_23 ( V_2 ) )
return 0 ;
F_53 ( V_4 , V_68 , V_73 , V_73 ) ;
return 0 ;
}
static int F_54 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
T_1 V_74 ;
if ( ! F_46 ( V_4 , V_2 ) )
return 0 ;
if ( V_6 -> V_33 > 1 )
return 0 ;
V_74 = V_6 -> V_45 |
V_6 -> V_35 ;
F_8 ( V_4 , V_68 , V_74 | V_73 ) ;
F_11 ( V_4 , V_75 ) ;
F_8 ( V_4 , V_68 , V_74 ) ;
F_11 ( V_4 , V_76 ) ;
return 0 ;
}
static int F_55 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 ,
int V_77 )
{
T_1 V_78 = 0 ;
if ( F_56 ( V_12 ) )
return 0 ;
if ( F_33 ( V_4 , V_2 ) )
return 0 ;
if ( ! F_46 ( V_4 , V_2 ) )
return 0 ;
if ( V_77 )
V_78 = F_4 ( V_4 ) ? 0x0e000000 : 0x0f000000 ;
F_8 ( V_4 , V_79 , V_78 ) ;
return 0 ;
}
static void F_57 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_11 * V_12 = F_12 ( V_4 ) ;
int V_80 = F_4 ( V_4 ) ;
T_1 V_15 ;
bool V_81 = false ;
bool V_82 = false ;
F_58 ( & V_12 -> V_83 ) ;
if ( ! F_59 ( V_2 ) )
goto V_84;
V_15 = F_9 ( V_4 ) ;
if ( ! V_80 && ( V_15 & V_75 ) ) {
struct V_43 * V_44 = F_42 ( V_2 ) ;
T_1 * V_85 = ( T_1 * ) ( V_44 -> V_86 +
F_60 ( V_2 , 0 ) ) ;
if ( F_29 ( V_2 ) )
F_8 ( V_4 , V_87 , * V_85 ) ;
else
* V_85 = F_10 ( V_4 , V_88 ) ;
V_81 = F_61 ( V_2 , sizeof( * V_85 ) ) ;
}
if ( V_80 && ( V_15 & ( V_89 | V_90 ) ) )
V_82 = true ;
F_7 ( V_4 ) ;
V_84:
F_62 ( & V_12 -> V_83 ) ;
if ( V_81 )
F_63 ( V_2 ) ;
if ( V_82 )
F_64 ( V_2 -> V_70 ) ;
}
static T_2 F_65 ( int V_91 , void * V_92 )
{
struct V_3 * V_4 = V_92 ;
F_66 ( V_4 , F_57 ) ;
return V_93 ;
}
static void F_67 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = F_27 ( V_2 ) ;
struct V_11 * V_12 = F_12 ( V_4 ) ;
if ( ! F_68 ( V_4 ) )
return;
if ( ! F_32 ( V_26 ) )
return;
switch ( F_17 ( V_4 ) ) {
case 1 :
case 2 :
F_69 ( F_70 ( V_12 , 0 ) , V_2 , V_94 ) ;
break;
case 4 :
F_69 ( F_70 ( V_12 , 3 ) , V_2 , V_94 ) ;
break;
case 8 :
F_69 ( F_70 ( V_12 , 7 ) , V_2 , V_94 ) ;
break;
}
}
static int F_71 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_95 * V_96 )
{
F_67 ( V_4 , V_2 ) ;
return 0 ;
}
static int F_72 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = F_13 ( V_12 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_29 ;
if ( F_34 ( V_4 , V_2 ) )
return 0 ;
V_29 = F_73 ( V_2 , V_4 ) ;
if ( V_29 < 0 )
return V_29 ;
V_29 = F_74 ( V_14 , V_6 -> V_91 ,
F_65 ,
V_97 ,
F_75 ( V_14 ) , V_4 ) ;
return V_29 ;
}
static int F_76 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_98 = 0 ;
int V_29 ;
if ( F_34 ( V_4 , V_2 ) )
return 0 ;
V_29 = F_72 ( V_4 , V_2 , V_12 ) ;
if ( V_29 )
return V_29 ;
V_29 = F_77 ( V_2 , V_4 , & V_6 -> V_99 , V_98 ) ;
return V_29 ;
}
static int F_78 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_13 * V_14 = F_13 ( V_12 ) ;
int V_91 = V_6 -> V_91 ;
F_79 ( V_14 , V_91 , V_4 ) ;
return 0 ;
}
static int F_80 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 = F_13 ( V_12 ) ;
V_4 -> V_100 = & V_101 ;
F_81 ( V_14 , L_6 ,
F_16 ( V_4 ) , F_17 ( V_4 ) ) ;
return 0 ;
}
static struct V_102 * F_82 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_11 * V_12 = F_12 ( V_4 ) ;
int V_103 = F_29 ( V_2 ) ;
char * V_104 ;
if ( F_1 ( V_2 ) )
V_104 = V_103 ? L_7 : L_8 ;
else
V_104 = V_103 ? L_9 : L_10 ;
return F_83 ( F_84 ( V_12 ) ,
V_4 , V_104 ) ;
}
int F_4 ( struct V_3 * V_4 )
{
return V_4 -> V_100 == & V_105 ;
}
static void F_85 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_25 * V_26 = F_27 ( V_2 ) ;
enum V_17 V_18 [] = {
V_106 ,
V_19 ,
V_20 ,
V_21 ,
} ;
enum V_17 type ;
int V_16 ;
for ( V_16 = 0 ; V_16 < F_19 ( V_18 ) ; V_16 ++ ) {
type = V_18 [ V_16 ] ;
if ( ! F_20 ( V_2 , type ) ) {
F_69 ( V_4 , V_2 , type ) ;
F_86 ( V_26 , 2 * ( V_16 + 1 ) , ( V_16 + 1 ) ) ;
return;
}
}
}
void F_87 ( struct V_25 * V_26 ,
struct V_107 * V_108 ,
struct V_107 * V_109 )
{
struct V_11 * V_12 = F_88 ( V_26 ) ;
struct V_107 * V_110 ;
struct V_107 * V_111 ;
struct V_3 * V_4 ;
int V_16 ;
V_110 = F_84 ( V_12 ) ;
if ( ! V_110 )
return;
V_16 = 0 ;
F_89 (node, np) {
V_4 = F_70 ( V_12 , V_16 ) ;
if ( V_111 == V_108 )
F_85 ( V_4 , & V_26 -> V_108 ) ;
if ( V_111 == V_109 )
F_85 ( V_4 , & V_26 -> V_109 ) ;
V_16 ++ ;
}
F_90 ( V_110 ) ;
}
struct V_3 * F_70 ( struct V_11 * V_12 , int V_112 )
{
if ( F_91 ( V_112 < 0 || V_112 >= F_92 ( V_12 ) ) )
V_112 = 0 ;
return F_93 ( F_94 ( V_12 , V_112 ) ) ;
}
int F_68 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
return ! ! ( F_5 ( V_6 ) & V_113 ) ;
}
static T_1 * F_95 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
enum V_17 type )
{
if ( type == V_94 )
return & V_2 -> V_114 ;
return F_96 ( V_2 , V_4 , type ) ;
}
int F_97 ( struct V_11 * V_12 )
{
struct V_107 * V_110 ;
struct V_107 * V_111 ;
struct V_13 * V_14 = F_13 ( V_12 ) ;
struct V_115 * V_100 ;
struct V_116 * V_116 ;
struct V_5 * V_6 ;
char V_104 [ V_117 ] ;
int V_16 , V_118 , V_29 ;
V_110 = F_84 ( V_12 ) ;
if ( ! V_110 )
return - V_34 ;
V_118 = F_98 ( V_110 ) ;
if ( ! V_118 ) {
V_29 = - V_34 ;
goto V_119;
}
V_6 = F_99 ( V_14 , sizeof( * V_6 ) * V_118 , V_120 ) ;
if ( ! V_6 ) {
V_29 = - V_121 ;
goto V_119;
}
V_12 -> V_6 = V_6 ;
V_12 -> V_122 = V_118 ;
V_16 = 0 ;
F_89 (node, np) {
V_6 = F_94 ( V_12 , V_16 ) ;
snprintf ( V_104 , V_117 , L_11 ,
V_123 , V_16 ) ;
V_116 = F_100 ( V_14 , V_104 ) ;
if ( F_101 ( V_116 ) ) {
V_29 = F_102 ( V_116 ) ;
goto V_119;
}
if ( F_103 ( V_111 , L_12 , NULL ) )
V_6 -> V_124 |= V_113 ;
if ( F_103 ( V_111 , L_13 , NULL ) )
V_6 -> V_124 |= V_8 ;
V_6 -> V_91 = F_104 ( V_111 , 0 ) ;
if ( ! V_6 -> V_91 ) {
V_29 = - V_34 ;
goto V_119;
}
V_100 = & V_125 ;
if ( F_103 ( V_111 , L_14 , NULL ) )
V_100 = & V_101 ;
else
V_100 = & V_105 ;
V_29 = F_105 ( V_12 , F_93 ( V_6 ) , V_100 , V_116 ,
F_95 , V_106 , V_16 ) ;
if ( V_29 )
goto V_119;
V_16 ++ ;
}
V_29 = 0 ;
V_119:
F_90 ( V_110 ) ;
return V_29 ;
}
void F_106 ( struct V_11 * V_12 )
{
struct V_5 * V_6 ;
int V_16 ;
F_107 (ssi, priv, i) {
F_108 ( F_93 ( V_6 ) ) ;
}
}
