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
static void F_7 ( struct V_3 * V_4 ,
T_1 V_9 )
{
struct V_10 * V_11 = F_8 ( V_4 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
T_1 V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < 1024 ; V_15 ++ ) {
V_14 = F_10 ( V_4 , V_16 ) ;
if ( V_14 & V_9 )
return;
F_11 ( 50 ) ;
}
F_12 ( V_13 , L_1 ) ;
}
static int F_13 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_10 * V_11 = F_14 ( V_2 ) ;
struct V_17 * V_18 = F_15 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
struct V_3 * V_4 = F_16 ( V_6 ) ;
int V_19 , V_20 ;
int V_21 [] = {
1 , 2 , 4 , 8 , 16 , 6 , 12 ,
} ;
unsigned int V_22 ;
unsigned int V_23 = F_17 ( V_11 , V_2 , V_18 ) ;
for ( V_19 = 0 ; V_19 < F_18 ( V_21 ) ; V_19 ++ ) {
V_22 = V_23 * 32 * 2 * V_21 [ V_19 ] ;
V_20 = F_19 ( V_4 , V_22 ) ;
if ( 0 == V_20 ) {
V_6 -> V_24 = V_25 | V_26 |
V_27 | V_28 | F_20 ( V_19 ) ;
F_21 ( V_13 , L_2 ,
F_22 ( V_4 ) ,
F_23 ( V_4 ) , V_23 ) ;
return 0 ;
}
}
F_24 ( V_13 , L_3 ) ;
return - V_29 ;
}
static void F_25 ( struct V_5 * V_6 )
{
struct V_3 * V_4 = F_16 ( V_6 ) ;
V_6 -> V_24 = 0 ;
F_26 ( V_4 ) ;
}
static void F_27 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_10 * V_11 = F_14 ( V_2 ) ;
struct V_30 * V_31 = F_28 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
struct V_3 * V_4 = F_16 ( V_6 ) ;
T_1 V_32 ;
T_1 V_33 ;
if ( 0 == V_6 -> V_34 ) {
F_29 ( V_4 ) ;
if ( F_30 ( V_31 ) ) {
struct V_5 * V_35 = F_31 ( V_6 ) ;
if ( V_35 )
F_27 ( V_35 , V_2 ) ;
else
F_13 ( V_6 , V_2 ) ;
}
}
if ( F_4 ( V_4 ) ) {
V_32 = V_36 | V_37 |
V_38 ;
} else {
V_32 = V_39 ;
}
V_33 = V_6 -> V_40 |
V_6 -> V_24 |
V_32 |
V_41 ;
F_32 ( V_4 , V_42 , V_33 ) ;
if ( F_30 ( V_31 ) )
F_32 ( V_4 , V_43 , V_44 ) ;
F_32 ( V_4 , V_16 , 0 ) ;
V_6 -> V_34 ++ ;
F_21 ( V_13 , L_4 ,
F_22 ( V_4 ) , F_23 ( V_4 ) ) ;
}
static void F_33 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_3 * V_4 = F_16 ( V_6 ) ;
struct V_10 * V_11 = F_8 ( V_4 ) ;
struct V_30 * V_31 = F_28 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
T_1 V_33 ;
if ( 0 == V_6 -> V_34 ) {
F_24 ( V_13 , L_5 , V_45 ) ;
return;
}
V_6 -> V_34 -- ;
if ( 0 == V_6 -> V_34 ) {
V_33 = V_6 -> V_40 |
V_6 -> V_24 ;
F_32 ( V_4 , V_42 , V_33 | V_41 ) ;
F_7 ( V_4 , V_46 ) ;
F_32 ( V_4 , V_42 , V_33 ) ;
F_7 ( V_4 , V_47 ) ;
if ( F_30 ( V_31 ) ) {
struct V_5 * V_35 = F_31 ( V_6 ) ;
if ( V_35 )
F_33 ( V_2 , V_35 ) ;
else
F_25 ( V_6 ) ;
}
F_34 ( V_4 ) ;
V_6 -> V_48 = 0 ;
}
F_21 ( V_13 , L_6 ,
F_22 ( V_4 ) , F_23 ( V_4 ) ) ;
}
static int F_35 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_30 * V_31 = F_28 ( V_2 ) ;
struct V_17 * V_18 = F_15 ( V_2 ) ;
T_1 V_33 ;
V_33 = V_25 ;
V_33 |= V_26 ;
switch ( V_18 -> V_49 ) {
case 16 :
V_33 |= V_50 ;
break;
case 32 :
V_33 |= V_51 ;
break;
default:
return - V_29 ;
}
if ( V_31 -> V_52 )
V_33 |= V_53 ;
if ( V_31 -> V_54 )
V_33 |= V_55 ;
if ( V_31 -> V_56 )
V_33 |= V_57 ;
if ( V_31 -> V_58 )
V_33 |= V_59 ;
if ( F_36 ( V_2 ) )
V_33 |= V_60 ;
V_6 -> V_40 = V_33 ;
V_6 -> V_61 = - 1 ;
return 0 ;
}
static int F_37 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
if ( V_6 -> V_61 > 0 )
F_12 ( V_13 , L_7 ,
F_22 ( V_4 ) , F_23 ( V_4 ) , V_6 -> V_61 ) ;
V_6 -> V_40 = 0 ;
V_6 -> V_61 = 0 ;
return 0 ;
}
static int F_38 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_62 * V_63 ,
struct V_64 * V_65 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_5 * V_35 = F_31 ( V_6 ) ;
int V_48 = F_39 ( V_65 ) ;
if ( V_6 -> V_34 ) {
if ( V_6 -> V_48 != V_48 )
return - V_29 ;
}
V_6 -> V_48 = V_48 ;
if ( V_35 )
return F_38 ( F_16 ( V_35 ) , V_2 ,
V_63 , V_65 ) ;
return 0 ;
}
static void F_40 ( struct V_5 * V_6 , T_1 V_14 )
{
struct V_3 * V_4 = F_16 ( V_6 ) ;
if ( V_14 & ( V_66 | V_67 ) ) {
V_6 -> V_61 ++ ;
F_32 ( V_4 , V_16 , 0 ) ;
}
}
static int F_41 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_42 ( V_4 , V_2 , F_1 ( V_2 ) ) ;
F_27 ( V_6 , V_2 ) ;
F_43 ( V_4 ) ;
return 0 ;
}
static int F_44 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
F_45 ( V_4 ) ;
F_40 ( V_6 , F_10 ( V_4 , V_16 ) ) ;
F_33 ( V_2 , V_6 ) ;
F_46 ( V_4 , V_2 ) ;
return 0 ;
}
static void F_47 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_10 * V_11 = F_8 ( V_4 ) ;
int V_68 = F_4 ( V_4 ) ;
T_1 V_14 ;
bool V_69 = false ;
F_48 ( & V_11 -> V_70 ) ;
if ( ! F_49 ( V_2 ) )
goto V_71;
V_14 = F_10 ( V_4 , V_16 ) ;
if ( ! V_68 && ( V_14 & V_46 ) ) {
struct V_17 * V_18 = F_15 ( V_2 ) ;
T_1 * V_72 = ( T_1 * ) ( V_18 -> V_73 +
F_50 ( V_2 , 0 ) ) ;
if ( F_36 ( V_2 ) )
F_32 ( V_4 , V_74 , * V_72 ) ;
else
* V_72 = F_10 ( V_4 , V_75 ) ;
V_69 = F_51 ( V_2 , sizeof( * V_72 ) ) ;
}
if ( V_68 && ( V_14 & ( V_66 | V_67 ) ) ) {
struct V_12 * V_13 = F_9 ( V_11 ) ;
F_21 ( V_13 , L_8 ,
F_22 ( V_4 ) , F_23 ( V_4 ) ) ;
F_44 ( V_4 , V_2 , V_11 ) ;
if ( V_6 -> V_61 < 1024 )
F_41 ( V_4 , V_2 , V_11 ) ;
else
F_12 ( V_13 , L_9 ) ;
}
F_40 ( V_6 , V_14 ) ;
V_71:
F_52 ( & V_11 -> V_70 ) ;
if ( V_69 )
F_53 ( V_2 ) ;
}
static T_2 F_54 ( int V_76 , void * V_77 )
{
struct V_3 * V_4 = V_77 ;
F_55 ( V_4 , F_47 ) ;
return V_78 ;
}
static int F_56 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_20 ;
V_20 = F_57 ( V_13 , V_6 -> V_79 -> V_76 ,
F_54 ,
V_80 ,
F_58 ( V_13 ) , V_4 ) ;
return V_20 ;
}
static int F_59 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_81 = V_6 -> V_79 -> V_81 ;
int V_20 ;
V_20 = F_57 ( V_13 , V_6 -> V_79 -> V_76 ,
F_54 ,
V_80 ,
F_58 ( V_13 ) , V_4 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_60 (
V_2 , F_61 ( V_4 ) ,
V_81 ) ;
return V_20 ;
}
static int F_62 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_76 = V_6 -> V_79 -> V_76 ;
F_63 ( V_2 , F_61 ( V_4 ) ) ;
F_64 ( V_13 , V_76 , V_4 ) ;
return 0 ;
}
static int F_65 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
V_4 -> V_82 = & V_83 ;
F_66 ( V_13 , L_10 ,
F_22 ( V_4 ) , F_23 ( V_4 ) ) ;
return 0 ;
}
static int F_67 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_84 * V_85 = F_61 ( V_4 ) ;
F_68 ( V_2 , V_85 ) ;
F_41 ( V_4 , V_2 , V_11 ) ;
return 0 ;
}
static int F_69 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_84 * V_85 = F_61 ( V_4 ) ;
F_44 ( V_4 , V_2 , V_11 ) ;
F_70 ( V_2 , V_85 ) ;
return 0 ;
}
static struct V_86 * F_71 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 = F_8 ( V_4 ) ;
int V_87 = F_36 ( V_2 ) ;
char * V_88 ;
if ( F_1 ( V_2 ) )
V_88 = V_87 ? L_11 : L_12 ;
else
V_88 = V_87 ? L_13 : L_14 ;
return F_72 ( F_73 ( V_11 ) ,
V_4 , V_88 ) ;
}
int F_4 ( struct V_3 * V_4 )
{
return V_4 -> V_82 == & V_89 ;
}
struct V_3 * F_74 ( struct V_10 * V_11 , int V_90 )
{
if ( F_75 ( V_90 < 0 || V_90 >= F_76 ( V_11 ) ) )
V_90 = 0 ;
return F_16 ( (struct V_5 * ) ( V_11 -> V_6 ) + V_90 ) ;
}
int F_77 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_3 ( V_4 ) ;
return ! ! ( F_5 ( V_6 ) & V_91 ) ;
}
static void F_78 ( struct V_10 * V_11 , struct V_5 * V_6 )
{
struct V_3 * V_4 = F_16 ( V_6 ) ;
if ( ! F_77 ( V_4 ) )
return;
switch ( F_23 ( V_4 ) ) {
case 1 :
case 2 :
V_6 -> V_92 = F_3 ( F_74 ( V_11 , 0 ) ) ;
break;
case 4 :
V_6 -> V_92 = F_3 ( F_74 ( V_11 , 3 ) ) ;
break;
case 8 :
V_6 -> V_92 = F_3 ( F_74 ( V_11 , 7 ) ) ;
break;
}
}
static void F_79 ( struct V_93 * V_94 ,
const struct V_95 * V_96 ,
struct V_10 * V_11 )
{
struct V_97 * V_98 ;
struct V_97 * V_99 ;
struct V_100 * V_101 ;
struct V_102 * V_79 = F_80 ( V_11 ) ;
struct V_12 * V_13 = & V_94 -> V_13 ;
int V_103 , V_15 ;
V_98 = F_73 ( V_11 ) ;
if ( ! V_98 )
return;
V_103 = F_81 ( V_98 ) ;
if ( ! V_103 )
goto V_104;
V_101 = F_82 ( V_13 ,
sizeof( struct V_100 ) * V_103 ,
V_105 ) ;
if ( ! V_101 ) {
F_24 ( V_13 , L_15 ) ;
goto V_104;
}
V_79 -> V_101 = V_101 ;
V_79 -> V_106 = V_103 ;
V_15 = - 1 ;
F_83 (node, np) {
V_15 ++ ;
V_101 = V_79 -> V_101 + V_15 ;
if ( F_84 ( V_99 , L_16 , NULL ) )
V_101 -> V_107 |= V_91 ;
V_101 -> V_76 = F_85 ( V_99 , 0 ) ;
V_101 -> V_81 = F_84 ( V_99 , L_17 , NULL ) ?
0 : 1 ;
if ( F_84 ( V_99 , L_18 , NULL ) )
V_101 -> V_107 |= V_8 ;
}
V_104:
F_86 ( V_98 ) ;
}
int F_87 ( struct V_93 * V_94 ,
const struct V_95 * V_96 ,
struct V_10 * V_11 )
{
struct V_102 * V_79 = F_80 ( V_11 ) ;
struct V_100 * V_108 ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
struct V_109 * V_82 ;
struct V_110 * V_110 ;
struct V_5 * V_6 ;
char V_88 [ V_111 ] ;
int V_15 , V_103 , V_20 ;
F_79 ( V_94 , V_96 , V_11 ) ;
V_103 = V_79 -> V_106 ;
V_6 = F_82 ( V_13 , sizeof( * V_6 ) * V_103 , V_105 ) ;
if ( ! V_6 )
return - V_112 ;
V_11 -> V_6 = V_6 ;
V_11 -> V_113 = V_103 ;
F_88 (ssi, priv, i) {
V_108 = & V_79 -> V_101 [ V_15 ] ;
snprintf ( V_88 , V_111 , L_19 ,
V_114 , V_15 ) ;
V_110 = F_89 ( V_13 , V_88 ) ;
if ( F_90 ( V_110 ) )
return F_91 ( V_110 ) ;
V_6 -> V_79 = V_108 ;
V_82 = & V_115 ;
if ( V_108 -> V_81 > 0 )
V_82 = & V_89 ;
else if ( F_92 ( V_6 ) )
V_82 = & V_83 ;
V_20 = F_93 ( V_11 , F_16 ( V_6 ) , V_82 , V_110 ,
V_116 , V_15 ) ;
if ( V_20 )
return V_20 ;
F_78 ( V_11 , V_6 ) ;
}
return 0 ;
}
void F_94 ( struct V_93 * V_94 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 ;
int V_15 ;
F_88 (ssi, priv, i) {
F_95 ( F_16 ( V_6 ) ) ;
}
}
