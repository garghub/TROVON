int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_7 = 0 ;
if ( ! F_3 ( V_4 ) )
return 0 ;
if ( ! ( F_4 ( V_6 ) & V_8 ) )
V_7 = 1 ;
if ( F_5 ( V_2 ) )
V_7 = 1 ;
return V_7 ;
}
static void F_6 ( struct V_3 * V_4 ,
T_1 V_9 )
{
struct V_10 * V_11 = F_7 ( V_4 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
T_1 V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < 1024 ; V_15 ++ ) {
V_14 = F_9 ( V_4 , V_16 ) ;
if ( V_14 & V_9 )
return;
F_10 ( 50 ) ;
}
F_11 ( V_13 , L_1 ) ;
}
static int F_12 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_10 * V_11 = F_13 ( V_2 ) ;
struct V_17 * V_18 = F_14 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
int V_15 , V_19 , V_20 ;
int V_21 [] = {
1 , 6 ,
} ;
int V_22 [] = {
1 , 2 , 4 , 8 , 16 , 6 , 12 ,
} ;
unsigned int V_23 ;
unsigned int V_24 = F_15 ( V_11 , V_2 , V_18 ) ;
for ( V_15 = 0 ; V_15 < F_16 ( V_21 ) ; V_15 ++ ) {
for ( V_19 = 0 ; V_19 < F_16 ( V_22 ) ; V_19 ++ ) {
V_23 = V_24 / V_21 [ V_15 ]
* 32 * 2 * V_22 [ V_19 ] ;
V_20 = F_17 ( & V_6 -> V_4 , V_23 ) ;
if ( 0 == V_20 ) {
V_6 -> V_25 = V_26 | V_27 |
V_28 | V_29 | F_18 ( V_19 ) ;
F_19 ( V_13 , L_2 ,
F_20 ( & V_6 -> V_4 ) ,
F_21 ( & V_6 -> V_4 ) , V_24 ) ;
return 0 ;
}
}
}
F_22 ( V_13 , L_3 ) ;
return - V_30 ;
}
static void F_23 ( struct V_5 * V_6 )
{
V_6 -> V_25 = 0 ;
F_24 ( & V_6 -> V_4 ) ;
}
static void F_25 ( struct V_5 * V_6 ,
struct V_1 * V_2 )
{
struct V_10 * V_11 = F_13 ( V_2 ) ;
struct V_31 * V_32 = F_26 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
T_1 V_33 ;
T_1 V_34 ;
if ( 0 == V_6 -> V_35 ) {
F_27 ( & V_6 -> V_4 ) ;
if ( F_28 ( V_32 ) ) {
struct V_5 * V_36 = F_29 ( V_6 ) ;
if ( V_36 )
F_25 ( V_36 , V_2 ) ;
else
F_12 ( V_6 , V_2 ) ;
}
}
if ( F_3 ( & V_6 -> V_4 ) ) {
V_33 = V_37 | V_38 |
V_39 ;
} else {
V_33 = V_40 ;
}
V_34 = V_6 -> V_41 |
V_6 -> V_25 |
V_33 |
V_42 ;
F_30 ( & V_6 -> V_4 , V_43 , V_34 ) ;
if ( F_28 ( V_32 ) )
F_30 ( & V_6 -> V_4 , V_44 , V_45 ) ;
F_30 ( & V_6 -> V_4 , V_16 , 0 ) ;
V_6 -> V_35 ++ ;
F_19 ( V_13 , L_4 ,
F_20 ( & V_6 -> V_4 ) , F_21 ( & V_6 -> V_4 ) ) ;
}
static void F_31 ( struct V_1 * V_2 , struct V_5 * V_6 )
{
struct V_10 * V_11 = F_7 ( & V_6 -> V_4 ) ;
struct V_31 * V_32 = F_26 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
T_1 V_34 ;
if ( 0 == V_6 -> V_35 ) {
F_22 ( V_13 , L_5 , V_46 ) ;
return;
}
V_6 -> V_35 -- ;
if ( 0 == V_6 -> V_35 ) {
V_34 = V_6 -> V_41 |
V_6 -> V_25 ;
F_30 ( & V_6 -> V_4 , V_43 , V_34 | V_42 ) ;
F_6 ( & V_6 -> V_4 , V_47 ) ;
F_30 ( & V_6 -> V_4 , V_43 , V_34 ) ;
F_6 ( & V_6 -> V_4 , V_48 ) ;
if ( F_28 ( V_32 ) ) {
struct V_5 * V_36 = F_29 ( V_6 ) ;
if ( V_36 )
F_31 ( V_2 , V_36 ) ;
else
F_23 ( V_6 ) ;
}
F_32 ( & V_6 -> V_4 ) ;
V_6 -> V_49 = 0 ;
}
F_19 ( V_13 , L_6 ,
F_20 ( & V_6 -> V_4 ) , F_21 ( & V_6 -> V_4 ) ) ;
}
static int F_33 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_31 * V_32 = F_26 ( V_2 ) ;
struct V_17 * V_18 = F_14 ( V_2 ) ;
T_1 V_34 ;
V_34 = V_26 ;
V_34 |= V_27 ;
switch ( V_18 -> V_50 ) {
case 16 :
V_34 |= V_51 ;
break;
case 32 :
V_34 |= V_52 ;
break;
default:
return - V_30 ;
}
if ( V_32 -> V_53 )
V_34 |= V_54 ;
if ( V_32 -> V_55 )
V_34 |= V_56 ;
if ( V_32 -> V_57 )
V_34 |= V_58 ;
if ( V_32 -> V_59 )
V_34 |= V_60 ;
if ( F_34 ( V_2 ) )
V_34 |= V_61 ;
V_6 -> V_41 = V_34 ;
V_6 -> V_62 = - 1 ;
return 0 ;
}
static int F_35 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
if ( V_6 -> V_62 > 0 )
F_11 ( V_13 , L_7 ,
F_20 ( V_4 ) , F_21 ( V_4 ) , V_6 -> V_62 ) ;
V_6 -> V_41 = 0 ;
V_6 -> V_62 = 0 ;
return 0 ;
}
static int F_36 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_63 * V_64 ,
struct V_65 * V_66 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_5 * V_36 = F_29 ( V_6 ) ;
int V_49 = F_37 ( V_66 ) ;
if ( V_6 -> V_35 ) {
if ( V_6 -> V_49 != V_49 )
return - V_30 ;
}
V_6 -> V_49 = V_49 ;
if ( V_36 )
return F_36 ( & V_36 -> V_4 , V_2 ,
V_64 , V_66 ) ;
return 0 ;
}
static void F_38 ( struct V_5 * V_6 , T_1 V_14 )
{
if ( V_14 & ( V_67 | V_68 ) ) {
V_6 -> V_62 ++ ;
F_30 ( & V_6 -> V_4 , V_16 , 0 ) ;
}
}
static int F_39 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_40 ( V_4 , V_2 , F_1 ( V_2 , V_4 ) ) ;
F_25 ( V_6 , V_2 ) ;
F_41 ( V_4 ) ;
return 0 ;
}
static int F_42 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
F_43 ( V_4 ) ;
F_38 ( V_6 , F_9 ( V_4 , V_16 ) ) ;
F_31 ( V_2 , V_6 ) ;
F_44 ( V_4 , V_2 ) ;
return 0 ;
}
static void F_45 ( struct V_3 * V_4 ,
struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_10 * V_11 = F_7 ( V_4 ) ;
int V_69 = F_3 ( V_4 ) ;
T_1 V_14 ;
bool V_70 = false ;
F_46 ( & V_11 -> V_71 ) ;
if ( ! F_47 ( V_2 ) )
goto V_72;
V_14 = F_9 ( V_4 , V_16 ) ;
if ( ! V_69 && ( V_14 & V_47 ) ) {
struct V_17 * V_18 = F_14 ( V_2 ) ;
T_1 * V_73 = ( T_1 * ) ( V_18 -> V_74 +
F_48 ( V_2 , 0 ) ) ;
if ( F_34 ( V_2 ) )
F_30 ( V_4 , V_75 , * V_73 ) ;
else
* V_73 = F_9 ( V_4 , V_76 ) ;
V_70 = F_49 ( V_2 , sizeof( * V_73 ) ) ;
}
if ( V_69 && ( V_14 & ( V_67 | V_68 ) ) ) {
struct V_12 * V_13 = F_8 ( V_11 ) ;
F_19 ( V_13 , L_8 ,
F_20 ( V_4 ) , F_21 ( V_4 ) ) ;
F_42 ( V_4 , V_2 , V_11 ) ;
if ( V_6 -> V_62 < 1024 )
F_39 ( V_4 , V_2 , V_11 ) ;
else
F_11 ( V_13 , L_9 ) ;
}
F_38 ( V_6 , V_14 ) ;
V_72:
F_50 ( & V_11 -> V_71 ) ;
if ( V_70 )
F_51 ( V_2 ) ;
}
static T_2 F_52 ( int V_77 , void * V_78 )
{
struct V_3 * V_4 = V_78 ;
F_53 ( V_4 , F_45 ) ;
return V_79 ;
}
static int F_54 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_8 ( V_11 ) ;
struct V_5 * V_6 = F_2 ( V_4 ) ;
int V_20 ;
V_20 = F_55 ( V_13 , V_6 -> V_80 -> V_77 ,
F_52 ,
V_81 ,
F_56 ( V_13 ) , V_4 ) ;
return V_20 ;
}
static int F_57 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
int V_82 = V_6 -> V_80 -> V_82 ;
int V_20 ;
V_20 = F_55 ( V_13 , V_6 -> V_80 -> V_77 ,
F_52 ,
V_81 ,
F_56 ( V_13 ) , V_4 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_58 (
V_2 , F_59 ( V_4 ) ,
V_82 ) ;
return V_20 ;
}
static int F_60 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
int V_77 = V_6 -> V_80 -> V_77 ;
F_61 ( V_2 , F_59 ( V_4 ) ) ;
F_62 ( V_13 , V_77 , V_6 ) ;
return 0 ;
}
static int F_63 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_8 ( V_11 ) ;
V_4 -> V_83 = & V_84 ;
F_64 ( V_13 , L_10 ,
F_20 ( V_4 ) , F_21 ( V_4 ) ) ;
return 0 ;
}
static int F_65 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_85 * V_86 = F_59 ( V_4 ) ;
F_66 ( V_2 , V_86 ) ;
F_39 ( V_4 , V_2 , V_11 ) ;
return 0 ;
}
static int F_67 ( struct V_3 * V_4 ,
struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_85 * V_86 = F_59 ( V_4 ) ;
F_42 ( V_4 , V_2 , V_11 ) ;
F_68 ( V_2 , V_86 ) ;
return 0 ;
}
static struct V_87 * F_69 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_10 * V_11 = F_7 ( V_4 ) ;
int V_88 = F_34 ( V_2 ) ;
char * V_89 ;
if ( F_1 ( V_2 , V_4 ) )
V_89 = V_88 ? L_11 : L_12 ;
else
V_89 = V_88 ? L_13 : L_14 ;
return F_70 ( F_71 ( V_11 ) ,
V_4 , V_89 ) ;
}
int F_3 ( struct V_3 * V_4 )
{
return V_4 -> V_83 == & V_90 ;
}
struct V_3 * F_72 ( struct V_10 * V_11 , int V_91 )
{
if ( F_73 ( V_91 < 0 || V_91 >= F_74 ( V_11 ) ) )
V_91 = 0 ;
return & ( (struct V_5 * ) ( V_11 -> V_6 ) + V_91 ) -> V_4 ;
}
int F_75 ( struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_4 ) ;
return ! ! ( F_4 ( V_6 ) & V_92 ) ;
}
static void F_76 ( struct V_10 * V_11 , struct V_5 * V_6 )
{
if ( ! F_75 ( & V_6 -> V_4 ) )
return;
switch ( F_21 ( & V_6 -> V_4 ) ) {
case 1 :
case 2 :
V_6 -> V_93 = F_2 ( F_72 ( V_11 , 0 ) ) ;
break;
case 4 :
V_6 -> V_93 = F_2 ( F_72 ( V_11 , 3 ) ) ;
break;
case 8 :
V_6 -> V_93 = F_2 ( F_72 ( V_11 , 7 ) ) ;
break;
}
}
static void F_77 ( struct V_94 * V_95 ,
const struct V_96 * V_97 ,
struct V_10 * V_11 )
{
struct V_98 * V_99 ;
struct V_98 * V_100 ;
struct V_101 * V_102 ;
struct V_103 * V_80 = F_78 ( V_11 ) ;
struct V_12 * V_13 = & V_95 -> V_13 ;
int V_104 , V_15 ;
if ( ! V_97 )
return;
V_99 = F_71 ( V_11 ) ;
if ( ! V_99 )
return;
V_104 = F_79 ( V_99 ) ;
if ( ! V_104 )
goto V_105;
V_102 = F_80 ( V_13 ,
sizeof( struct V_101 ) * V_104 ,
V_106 ) ;
if ( ! V_102 ) {
F_22 ( V_13 , L_15 ) ;
goto V_105;
}
V_80 -> V_102 = V_102 ;
V_80 -> V_107 = V_104 ;
V_15 = - 1 ;
F_81 (node, np) {
V_15 ++ ;
V_102 = V_80 -> V_102 + V_15 ;
if ( F_82 ( V_100 , L_16 , NULL ) )
V_102 -> V_108 |= V_92 ;
V_102 -> V_77 = F_83 ( V_100 , 0 ) ;
V_102 -> V_82 = F_82 ( V_100 , L_17 , NULL ) ?
0 : 1 ;
if ( F_82 ( V_100 , L_18 , NULL ) )
V_102 -> V_108 |= V_8 ;
}
V_105:
F_84 ( V_99 ) ;
}
int F_85 ( struct V_94 * V_95 ,
const struct V_96 * V_97 ,
struct V_10 * V_11 )
{
struct V_103 * V_80 = F_78 ( V_11 ) ;
struct V_101 * V_109 ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
struct V_110 * V_83 ;
struct V_111 * V_111 ;
struct V_5 * V_6 ;
char V_89 [ V_112 ] ;
int V_15 , V_104 , V_20 ;
F_77 ( V_95 , V_97 , V_11 ) ;
V_104 = V_80 -> V_107 ;
V_6 = F_80 ( V_13 , sizeof( * V_6 ) * V_104 , V_106 ) ;
if ( ! V_6 ) {
F_22 ( V_13 , L_19 ) ;
return - V_113 ;
}
V_11 -> V_6 = V_6 ;
V_11 -> V_114 = V_104 ;
F_86 (ssi, priv, i) {
V_109 = & V_80 -> V_102 [ V_15 ] ;
snprintf ( V_89 , V_112 , L_20 ,
V_115 , V_15 ) ;
V_111 = F_87 ( V_13 , V_89 ) ;
if ( F_88 ( V_111 ) )
return F_89 ( V_111 ) ;
V_6 -> V_80 = V_109 ;
V_83 = & V_116 ;
if ( V_109 -> V_82 > 0 )
V_83 = & V_90 ;
else if ( F_90 ( V_6 ) )
V_83 = & V_84 ;
V_20 = F_91 ( V_11 , & V_6 -> V_4 , V_83 , V_111 , V_117 , V_15 ) ;
if ( V_20 )
return V_20 ;
F_76 ( V_11 , V_6 ) ;
}
return 0 ;
}
void F_92 ( struct V_94 * V_95 ,
struct V_10 * V_11 )
{
struct V_5 * V_6 ;
int V_15 ;
F_86 (ssi, priv, i) {
F_93 ( & V_6 -> V_4 ) ;
}
}
