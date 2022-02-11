static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
int V_7 = 0 ;
if ( ! F_4 ( V_2 ) )
return 0 ;
if ( ! ( F_5 ( V_4 ) & V_8 ) )
V_7 = 1 ;
if ( F_6 ( V_6 ) )
V_7 = 1 ;
return V_7 ;
}
static void F_7 ( struct V_1 * V_2 ,
T_1 V_9 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
T_1 V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < 1024 ; V_15 ++ ) {
V_14 = F_10 ( V_2 , V_16 ) ;
if ( V_14 & V_9 )
return;
F_11 ( 50 ) ;
}
F_12 ( V_13 , L_1 ) ;
}
static int F_13 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_10 * V_11 = F_8 ( & V_4 -> V_2 ) ;
struct V_17 * V_18 = F_14 ( V_6 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_15 , V_19 , V_20 ;
int V_21 [] = {
1 , 6 ,
} ;
int V_22 [] = {
1 , 2 , 4 , 8 , 16 , 6 , 12 ,
} ;
unsigned int V_23 ;
unsigned int V_24 = F_15 ( V_11 , V_6 , V_18 ) ;
for ( V_15 = 0 ; V_15 < F_16 ( V_21 ) ; V_15 ++ ) {
for ( V_19 = 0 ; V_19 < F_16 ( V_22 ) ; V_19 ++ ) {
V_23 = V_24 / V_21 [ V_15 ]
* 32 * 2 * V_22 [ V_19 ] ;
V_20 = F_17 ( & V_4 -> V_2 , V_23 ) ;
if ( 0 == V_20 ) {
V_4 -> V_24 = V_24 ;
V_4 -> V_25 = V_26 | V_27 |
V_28 | V_29 | F_18 ( V_19 ) ;
F_19 ( V_13 , L_2 ,
F_20 ( & V_4 -> V_2 ) ,
F_21 ( & V_4 -> V_2 ) , V_24 ) ;
return 0 ;
}
}
}
F_22 ( V_13 , L_3 ) ;
return - V_30 ;
}
static void F_23 ( struct V_3 * V_4 )
{
V_4 -> V_24 = 0 ;
V_4 -> V_25 = 0 ;
F_24 ( & V_4 -> V_2 ) ;
}
static void F_25 ( struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_5 * V_6 )
{
struct V_10 * V_11 = F_8 ( & V_4 -> V_2 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
T_1 V_33 ;
T_1 V_34 ;
if ( 0 == V_4 -> V_35 ) {
F_26 ( V_4 -> V_36 ) ;
if ( F_27 ( V_32 ) ) {
if ( F_28 ( V_4 ) )
F_25 ( V_4 -> V_37 , V_32 , V_6 ) ;
else
F_13 ( V_4 , V_6 ) ;
}
}
V_33 = F_4 ( & V_4 -> V_2 ) ?
V_38 :
V_39 ;
V_34 = V_4 -> V_40 |
V_4 -> V_25 |
V_33 |
V_41 | V_42 | V_43 ;
F_29 ( & V_4 -> V_2 , V_44 , V_34 ) ;
if ( F_27 ( V_32 ) )
F_29 ( & V_4 -> V_2 , V_45 , V_46 ) ;
F_29 ( & V_4 -> V_2 , V_16 , 0 ) ;
V_4 -> V_35 ++ ;
F_19 ( V_13 , L_4 ,
F_20 ( & V_4 -> V_2 ) , F_21 ( & V_4 -> V_2 ) ) ;
}
static void F_30 ( struct V_3 * V_4 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_8 ( & V_4 -> V_2 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
T_1 V_34 ;
if ( 0 == V_4 -> V_35 )
return;
V_4 -> V_35 -- ;
if ( 0 == V_4 -> V_35 ) {
V_34 = V_4 -> V_40 |
V_4 -> V_25 ;
F_29 ( & V_4 -> V_2 , V_44 , V_34 | V_43 ) ;
F_7 ( & V_4 -> V_2 , V_47 ) ;
F_29 ( & V_4 -> V_2 , V_44 , V_34 ) ;
F_7 ( & V_4 -> V_2 , V_48 ) ;
if ( F_27 ( V_32 ) ) {
if ( F_28 ( V_4 ) )
F_30 ( V_4 -> V_37 , V_32 ) ;
else
F_23 ( V_4 ) ;
}
F_31 ( V_4 -> V_36 ) ;
}
F_19 ( V_13 , L_5 ,
F_20 ( & V_4 -> V_2 ) , F_21 ( & V_4 -> V_2 ) ) ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_17 * V_18 = F_14 ( V_6 ) ;
T_1 V_34 ;
V_34 = V_26 ;
V_34 |= V_27 ;
switch ( V_18 -> V_49 ) {
case 16 :
V_34 |= V_50 ;
break;
case 32 :
V_34 |= V_51 ;
break;
default:
return - V_30 ;
}
if ( V_32 -> V_52 )
V_34 |= V_53 ;
if ( V_32 -> V_54 )
V_34 |= V_55 ;
if ( V_32 -> V_56 )
V_34 |= V_57 ;
if ( V_32 -> V_58 )
V_34 |= V_59 ;
if ( F_33 ( V_32 , V_6 ) )
V_34 |= V_60 ;
V_4 -> V_32 = V_32 ;
V_4 -> V_40 = V_34 ;
V_4 -> V_61 = - 1 ;
return 0 ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
if ( V_4 -> V_61 > 0 )
F_12 ( V_13 , L_6 , V_4 -> V_61 ) ;
V_4 -> V_32 = NULL ;
V_4 -> V_40 = 0 ;
V_4 -> V_61 = 0 ;
return 0 ;
}
static void F_35 ( struct V_3 * V_4 , T_1 V_14 )
{
if ( V_14 & ( V_62 | V_63 ) ) {
V_4 -> V_61 ++ ;
F_29 ( & V_4 -> V_2 , V_16 , 0 ) ;
}
}
static int F_36 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
F_37 ( V_2 , V_32 , F_1 ( V_2 ) ) ;
F_25 ( V_4 , V_32 , V_6 ) ;
F_38 ( V_2 , V_32 ) ;
return 0 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_40 ( V_2 , V_32 ) ;
F_35 ( V_4 , F_10 ( V_2 , V_16 ) ) ;
F_30 ( V_4 , V_32 ) ;
F_41 ( V_2 , V_32 ) ;
return 0 ;
}
static T_2 F_42 ( int V_64 , void * V_65 )
{
struct V_3 * V_4 = V_65 ;
struct V_31 * V_32 = V_4 -> V_32 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
T_1 V_14 = F_10 ( V_2 , V_16 ) ;
if ( ! V_6 )
return V_66 ;
if ( V_14 & V_47 ) {
struct V_17 * V_18 = F_14 ( V_6 ) ;
T_1 * V_67 = ( T_1 * ) ( V_18 -> V_68 +
F_43 ( V_6 , 0 ) ) ;
if ( F_33 ( V_32 , V_6 ) )
F_29 ( V_2 , V_69 , * V_67 ) ;
else
* V_67 = F_10 ( V_2 , V_70 ) ;
F_44 ( V_6 , sizeof( * V_67 ) ) ;
}
if ( V_14 & ( V_62 | V_63 ) ) {
struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
F_39 ( V_2 , V_32 ) ;
F_36 ( V_2 , V_32 ) ;
F_19 ( V_13 , L_7 ,
F_20 ( V_2 ) , F_21 ( V_2 ) ) ;
}
F_35 ( V_4 , V_14 ) ;
return V_71 ;
}
static int F_45 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_20 ;
V_20 = F_46 ( V_13 , V_4 -> V_72 -> V_64 ,
F_42 ,
V_73 ,
F_47 ( V_13 ) , V_4 ) ;
if ( V_20 )
F_22 ( V_13 , L_8 ,
F_20 ( V_2 ) , F_21 ( V_2 ) ) ;
else
F_19 ( V_13 , L_9 ,
F_20 ( V_2 ) , F_21 ( V_2 ) ) ;
return V_20 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_74 = V_4 -> V_72 -> V_74 ;
int V_20 ;
V_20 = F_46 ( V_13 , V_4 -> V_72 -> V_64 ,
F_42 ,
V_73 ,
F_47 ( V_13 ) , V_4 ) ;
if ( V_20 )
goto V_75;
V_20 = F_49 (
V_11 , F_50 ( V_2 ) ,
F_51 ( V_11 , V_4 ) ,
V_74 ) ;
if ( V_20 )
goto V_75;
F_19 ( V_13 , L_10 ,
F_20 ( V_2 ) , F_21 ( V_2 ) ) ;
return V_20 ;
V_75:
F_22 ( V_13 , L_11 ,
F_20 ( V_2 ) , F_21 ( V_2 ) ) ;
return V_20 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_64 = V_4 -> V_72 -> V_64 ;
F_53 ( F_8 ( V_2 ) , F_50 ( V_2 ) ) ;
F_54 ( V_13 , V_64 , V_4 ) ;
return 0 ;
}
static int F_55 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
V_2 -> V_76 = & V_77 ;
F_56 ( V_13 , L_12 ,
F_20 ( V_2 ) , F_21 ( V_2 ) ) ;
return 0 ;
}
static int F_57 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_78 * V_79 = F_50 ( V_2 ) ;
F_36 ( V_2 , V_32 ) ;
F_58 ( V_79 ) ;
return 0 ;
}
static int F_59 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_78 * V_79 = F_50 ( V_2 ) ;
F_60 ( V_79 ) ;
F_39 ( V_2 , V_32 ) ;
return 0 ;
}
static char * F_61 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ? L_13 : V_80 ;
}
int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_76 == & V_81 ;
}
struct V_1 * F_62 ( struct V_10 * V_11 , int V_82 )
{
if ( F_63 ( V_82 < 0 || V_82 >= F_64 ( V_11 ) ) )
V_82 = 0 ;
return & ( (struct V_3 * ) ( V_11 -> V_4 ) + V_82 ) -> V_2 ;
}
int F_65 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return ! ! ( F_5 ( V_4 ) & V_83 ) ;
}
static void F_66 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
if ( ! F_65 ( & V_4 -> V_2 ) )
return;
switch ( F_21 ( & V_4 -> V_2 ) ) {
case 1 :
case 2 :
V_4 -> V_37 = F_2 ( F_62 ( V_11 , 0 ) ) ;
break;
case 4 :
V_4 -> V_37 = F_2 ( F_62 ( V_11 , 3 ) ) ;
break;
case 8 :
V_4 -> V_37 = F_2 ( F_62 ( V_11 , 7 ) ) ;
break;
}
}
static void F_67 ( struct V_84 * V_85 ,
const struct V_86 * V_87 ,
struct V_10 * V_11 )
{
struct V_88 * V_89 ;
struct V_88 * V_90 ;
struct V_91 * V_92 ;
struct V_93 * V_72 = F_68 ( V_11 ) ;
struct V_12 * V_13 = & V_85 -> V_13 ;
int V_94 , V_15 ;
if ( ! V_87 )
return;
V_89 = F_69 ( V_13 -> V_95 , L_14 ) ;
if ( ! V_89 )
return;
V_94 = F_70 ( V_89 ) ;
if ( ! V_94 )
goto V_96;
V_92 = F_71 ( V_13 ,
sizeof( struct V_91 ) * V_94 ,
V_97 ) ;
if ( ! V_92 ) {
F_22 ( V_13 , L_15 ) ;
goto V_96;
}
V_72 -> V_92 = V_92 ;
V_72 -> V_98 = V_94 ;
V_15 = - 1 ;
F_72 (node, np) {
V_15 ++ ;
V_92 = V_72 -> V_92 + V_15 ;
if ( F_73 ( V_90 , L_16 , NULL ) )
V_92 -> V_99 |= V_83 ;
V_92 -> V_64 = F_74 ( V_90 , 0 ) ;
V_92 -> V_74 = F_73 ( V_90 , L_17 , NULL ) ?
0 : 1 ;
if ( F_73 ( V_90 , L_18 , NULL ) )
V_92 -> V_99 |= V_8 ;
}
V_96:
F_75 ( V_89 ) ;
}
int F_76 ( struct V_84 * V_85 ,
const struct V_86 * V_87 ,
struct V_10 * V_11 )
{
struct V_93 * V_72 = F_68 ( V_11 ) ;
struct V_91 * V_100 ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
struct V_101 * V_76 ;
struct V_36 * V_36 ;
struct V_3 * V_4 ;
char V_102 [ V_103 ] ;
int V_15 , V_94 ;
F_67 ( V_85 , V_87 , V_11 ) ;
V_94 = V_72 -> V_98 ;
V_4 = F_71 ( V_13 , sizeof( * V_4 ) * V_94 , V_97 ) ;
if ( ! V_4 ) {
F_22 ( V_13 , L_19 ) ;
return - V_104 ;
}
V_11 -> V_4 = V_4 ;
V_11 -> V_105 = V_94 ;
F_77 (ssi, priv, i) {
V_100 = & V_72 -> V_92 [ V_15 ] ;
snprintf ( V_102 , V_103 , L_20 ,
V_80 , V_15 ) ;
V_36 = F_78 ( V_13 , V_102 ) ;
if ( F_79 ( V_36 ) )
return F_80 ( V_36 ) ;
V_4 -> V_72 = V_100 ;
V_4 -> V_36 = V_36 ;
V_76 = & V_106 ;
if ( V_100 -> V_74 > 0 )
V_76 = & V_81 ;
else if ( F_81 ( V_4 ) )
V_76 = & V_77 ;
F_82 ( V_11 , & V_4 -> V_2 , V_76 , V_107 , V_15 ) ;
F_66 ( V_11 , V_4 ) ;
}
return 0 ;
}
