static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
int V_7 = 0 ;
if ( ! ( F_4 ( V_4 ) & V_8 ) )
V_7 = 1 ;
if ( F_5 ( V_6 ) )
V_7 = 1 ;
return V_7 ;
}
static void F_6 ( struct V_1 * V_2 ,
T_1 V_9 )
{
struct V_10 * V_11 = F_7 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
T_1 V_14 ;
int V_15 ;
for ( V_15 = 0 ; V_15 < 1024 ; V_15 ++ ) {
V_14 = F_9 ( V_2 , V_16 ) ;
if ( V_14 & V_9 )
return;
F_10 ( 50 ) ;
}
F_11 ( V_13 , L_1 ) ;
}
static int F_12 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_10 * V_11 = F_7 ( & V_4 -> V_2 ) ;
struct V_17 * V_18 = F_13 ( V_6 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
int V_15 , V_19 , V_20 ;
int V_21 [] = {
1 , 6 ,
} ;
int V_22 [] = {
1 , 2 , 4 , 8 , 16 , 6 , 12 ,
} ;
unsigned int V_23 ;
unsigned int V_24 = F_14 ( V_11 , V_6 , V_18 ) ;
for ( V_15 = 0 ; V_15 < F_15 ( V_21 ) ; V_15 ++ ) {
for ( V_19 = 0 ; V_19 < F_15 ( V_22 ) ; V_19 ++ ) {
V_23 = V_24 / V_21 [ V_15 ]
* 32 * 2 * V_22 [ V_19 ] ;
V_20 = F_16 ( & V_4 -> V_2 , V_23 ) ;
if ( 0 == V_20 ) {
V_4 -> V_24 = V_24 ;
V_4 -> V_25 = V_26 | V_27 |
V_28 | V_29 | F_17 ( V_19 ) ;
F_18 ( V_13 , L_2 ,
F_19 ( & V_4 -> V_2 ) , V_24 ) ;
return 0 ;
}
}
}
F_20 ( V_13 , L_3 ) ;
return - V_30 ;
}
static void F_21 ( struct V_3 * V_4 )
{
V_4 -> V_24 = 0 ;
V_4 -> V_25 = 0 ;
F_22 ( & V_4 -> V_2 ) ;
}
static void F_23 ( struct V_3 * V_4 ,
struct V_31 * V_32 ,
struct V_5 * V_6 )
{
struct V_10 * V_11 = F_7 ( & V_4 -> V_2 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
T_1 V_33 ;
if ( 0 == V_4 -> V_34 ) {
F_24 ( V_4 -> V_35 ) ;
if ( F_25 ( V_32 ) ) {
if ( F_26 ( V_4 ) )
F_23 ( V_4 -> V_36 , V_32 , V_6 ) ;
else
F_12 ( V_4 , V_6 ) ;
}
}
V_33 = V_4 -> V_37 |
V_4 -> V_25 |
V_4 -> V_38 |
V_39 ;
F_27 ( & V_4 -> V_2 , V_40 , V_33 ) ;
V_4 -> V_34 ++ ;
F_18 ( V_13 , L_4 , F_19 ( & V_4 -> V_2 ) ) ;
}
static void F_28 ( struct V_3 * V_4 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_7 ( & V_4 -> V_2 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
T_1 V_33 ;
if ( 0 == V_4 -> V_34 )
return;
V_4 -> V_34 -- ;
if ( 0 == V_4 -> V_34 ) {
V_33 = V_4 -> V_37 |
V_4 -> V_25 ;
F_27 ( & V_4 -> V_2 , V_40 , V_33 | V_39 ) ;
F_6 ( & V_4 -> V_2 , V_41 ) ;
F_27 ( & V_4 -> V_2 , V_40 , V_33 ) ;
F_6 ( & V_4 -> V_2 , V_42 ) ;
if ( F_25 ( V_32 ) ) {
if ( F_26 ( V_4 ) )
F_28 ( V_4 -> V_36 , V_32 ) ;
else
F_21 ( V_4 ) ;
}
F_29 ( V_4 -> V_35 ) ;
}
F_18 ( V_13 , L_5 , F_19 ( & V_4 -> V_2 ) ) ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_17 * V_18 = F_13 ( V_6 ) ;
T_1 V_33 ;
V_33 = V_26 ;
V_33 |= V_27 ;
switch ( V_18 -> V_43 ) {
case 16 :
V_33 |= V_44 ;
break;
case 32 :
V_33 |= V_45 ;
break;
default:
return - V_30 ;
}
if ( V_32 -> V_46 )
V_33 |= V_47 ;
if ( V_32 -> V_48 )
V_33 |= V_49 ;
if ( V_32 -> V_50 )
V_33 |= V_51 ;
if ( V_32 -> V_52 )
V_33 |= V_53 ;
if ( F_31 ( V_32 , V_6 ) )
V_33 |= V_54 ;
V_4 -> V_32 = V_32 ;
V_4 -> V_37 = V_33 ;
V_4 -> V_55 = - 1 ;
return 0 ;
}
static int F_32 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_10 * V_11 = F_7 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
if ( V_4 -> V_55 > 0 )
F_11 ( V_13 , L_6 , V_4 -> V_55 ) ;
V_4 -> V_32 = NULL ;
V_4 -> V_37 = 0 ;
V_4 -> V_55 = 0 ;
return 0 ;
}
static void F_33 ( struct V_3 * V_4 , T_1 V_14 )
{
if ( V_14 & ( V_56 | V_57 ) ) {
V_4 -> V_55 ++ ;
F_27 ( & V_4 -> V_2 , V_16 , 0 ) ;
}
}
static T_2 F_34 ( int V_58 , void * V_59 )
{
struct V_3 * V_4 = V_59 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
T_1 V_14 = F_9 ( V_2 , V_16 ) ;
T_2 V_20 = V_60 ;
if ( V_6 && ( V_14 & V_41 ) ) {
struct V_31 * V_32 = V_4 -> V_32 ;
struct V_17 * V_18 = F_13 ( V_6 ) ;
T_1 * V_61 = ( T_1 * ) ( V_18 -> V_62 +
F_35 ( V_6 , 0 ) ) ;
F_33 ( V_4 , V_14 ) ;
if ( F_31 ( V_32 , V_6 ) )
F_27 ( V_2 , V_63 , * V_61 ) ;
else
* V_61 = F_9 ( V_2 , V_64 ) ;
F_36 ( V_6 , sizeof( * V_61 ) ) ;
V_20 = V_65 ;
}
return V_20 ;
}
static int F_37 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_7 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_58 = V_4 -> V_66 -> V_67 ;
int V_20 ;
V_20 = F_38 ( V_13 , V_58 ,
F_34 ,
V_68 ,
F_39 ( V_13 ) , V_4 ) ;
if ( V_20 )
F_20 ( V_13 , L_7 ) ;
F_18 ( V_13 , L_8 , F_40 ( V_2 ) ) ;
return V_20 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
V_4 -> V_38 = V_69 | V_70 | V_71 ;
F_42 ( V_2 , V_32 , 0 ) ;
F_43 ( V_2 , V_32 ) ;
F_23 ( V_4 , V_32 , V_6 ) ;
return 0 ;
}
static int F_44 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_38 = 0 ;
F_28 ( V_4 , V_32 ) ;
F_45 ( V_2 , V_32 , 0 ) ;
return 0 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_10 * V_11 = F_7 ( V_2 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
int V_72 = V_4 -> V_66 -> V_72 ;
int V_20 ;
V_20 = F_47 (
V_11 , F_48 ( V_2 ) ,
F_49 ( V_11 , V_4 ) ,
V_72 ) ;
if ( V_20 < 0 )
F_20 ( V_13 , L_9 ) ;
F_18 ( V_13 , L_10 , F_40 ( V_2 ) ) ;
return V_20 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
F_51 ( F_7 ( V_2 ) , F_48 ( V_2 ) ) ;
return 0 ;
}
static int F_52 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_73 * V_74 = F_48 ( & V_4 -> V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
V_4 -> V_38 = V_75 ;
F_42 ( V_2 , V_32 , F_1 ( V_2 ) ) ;
F_53 ( V_74 ) ;
F_23 ( V_4 , V_4 -> V_32 , V_6 ) ;
if ( F_25 ( V_32 ) )
F_27 ( & V_4 -> V_2 , V_76 , V_77 ) ;
return 0 ;
}
static int F_54 ( struct V_1 * V_2 ,
struct V_31 * V_32 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_73 * V_74 = F_48 ( & V_4 -> V_2 ) ;
V_4 -> V_38 = 0 ;
F_33 ( V_4 , F_9 ( V_2 , V_16 ) ) ;
F_28 ( V_4 , V_32 ) ;
F_55 ( V_74 ) ;
F_45 ( V_2 , V_32 , 1 ) ;
return 0 ;
}
static char * F_56 ( struct V_1 * V_2 )
{
return F_1 ( V_2 ) ? L_11 : V_78 ;
}
struct V_1 * F_57 ( struct V_10 * V_11 , int V_79 )
{
if ( F_58 ( V_79 < 0 || V_79 >= F_59 ( V_11 ) ) )
V_79 = 0 ;
return & ( (struct V_3 * ) ( V_11 -> V_4 ) + V_79 ) -> V_2 ;
}
int F_60 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return ! ! ( F_4 ( V_4 ) & V_80 ) ;
}
static void F_61 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
if ( ! F_60 ( & V_4 -> V_2 ) )
return;
switch ( F_19 ( & V_4 -> V_2 ) ) {
case 1 :
case 2 :
V_4 -> V_36 = F_2 ( F_57 ( V_11 , 0 ) ) ;
break;
case 4 :
V_4 -> V_36 = F_2 ( F_57 ( V_11 , 3 ) ) ;
break;
case 8 :
V_4 -> V_36 = F_2 ( F_57 ( V_11 , 7 ) ) ;
break;
}
}
static void F_62 ( struct V_81 * V_82 ,
const struct V_83 * V_84 ,
struct V_10 * V_11 )
{
struct V_85 * V_86 ;
struct V_85 * V_87 ;
struct V_88 * V_89 ;
struct V_90 * V_66 = F_63 ( V_11 ) ;
struct V_12 * V_13 = & V_82 -> V_13 ;
int V_91 , V_15 ;
if ( ! V_84 )
return;
V_86 = F_64 ( V_13 -> V_92 , L_12 ) ;
if ( ! V_86 )
return;
V_91 = F_65 ( V_86 ) ;
if ( ! V_91 )
goto V_93;
V_89 = F_66 ( V_13 ,
sizeof( struct V_88 ) * V_91 ,
V_94 ) ;
if ( ! V_89 ) {
F_20 ( V_13 , L_13 ) ;
goto V_93;
}
V_66 -> V_89 = V_89 ;
V_66 -> V_95 = V_91 ;
V_15 = - 1 ;
F_67 (node, np) {
V_15 ++ ;
V_89 = V_66 -> V_89 + V_15 ;
if ( F_68 ( V_87 , L_14 , NULL ) )
V_89 -> V_96 |= V_80 ;
V_89 -> V_67 = F_69 ( V_87 , 0 ) ;
V_89 -> V_72 = F_68 ( V_87 , L_15 , NULL ) ?
0 : 1 ;
if ( F_68 ( V_87 , L_16 , NULL ) )
V_89 -> V_96 |= V_8 ;
}
V_93:
F_70 ( V_86 ) ;
}
int F_71 ( struct V_81 * V_82 ,
const struct V_83 * V_84 ,
struct V_10 * V_11 )
{
struct V_90 * V_66 = F_63 ( V_11 ) ;
struct V_88 * V_97 ;
struct V_12 * V_13 = F_8 ( V_11 ) ;
struct V_98 * V_99 ;
struct V_35 * V_35 ;
struct V_3 * V_4 ;
char V_100 [ V_101 ] ;
int V_15 , V_91 ;
F_62 ( V_82 , V_84 , V_11 ) ;
V_91 = V_66 -> V_95 ;
V_4 = F_66 ( V_13 , sizeof( * V_4 ) * V_91 , V_94 ) ;
if ( ! V_4 ) {
F_20 ( V_13 , L_17 ) ;
return - V_102 ;
}
V_11 -> V_4 = V_4 ;
V_11 -> V_103 = V_91 ;
F_72 (ssi, priv, i) {
V_97 = & V_66 -> V_89 [ V_15 ] ;
snprintf ( V_100 , V_101 , L_18 ,
V_78 , V_15 ) ;
V_35 = F_73 ( V_13 , V_100 ) ;
if ( F_74 ( V_35 ) )
return F_75 ( V_35 ) ;
V_4 -> V_66 = V_97 ;
V_4 -> V_35 = V_35 ;
V_99 = & V_104 ;
if ( V_97 -> V_72 > 0 )
V_99 = & V_105 ;
else if ( F_76 ( V_4 ) )
V_99 = & V_106 ;
F_77 ( V_11 , & V_4 -> V_2 , V_99 , V_107 , V_15 ) ;
F_61 ( V_11 , V_4 ) ;
}
return 0 ;
}
