static void F_1 ( struct V_1 * V_2 ,
T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_1 V_8 ;
int V_9 ;
for ( V_9 = 0 ; V_9 < 1024 ; V_9 ++ ) {
V_8 = F_4 ( V_2 , V_10 ) ;
if ( V_8 & V_3 )
return;
F_5 ( 50 ) ;
}
F_6 ( V_7 , L_1 ) ;
}
static int F_7 ( struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = F_2 ( & V_12 -> V_2 ) ;
struct V_15 * V_16 = F_8 ( V_14 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
int V_9 , V_17 , V_18 ;
int V_19 [] = {
1 , 6 ,
} ;
int V_20 [] = {
1 , 2 , 4 , 8 , 16 , 6 , 12 ,
} ;
unsigned int V_21 ;
unsigned int V_22 = F_9 ( V_5 , V_14 , V_16 ) ;
for ( V_9 = 0 ; V_9 < F_10 ( V_19 ) ; V_9 ++ ) {
for ( V_17 = 0 ; V_17 < F_10 ( V_20 ) ; V_17 ++ ) {
V_21 = V_22 / V_19 [ V_9 ]
* 32 * 2 * V_20 [ V_17 ] ;
V_18 = F_11 ( & V_12 -> V_2 , V_21 ) ;
if ( 0 == V_18 ) {
V_12 -> V_22 = V_22 ;
V_12 -> V_23 = V_24 | V_25 |
V_26 | V_27 | F_12 ( V_17 ) ;
F_13 ( V_7 , L_2 ,
F_14 ( & V_12 -> V_2 ) , V_22 ) ;
return 0 ;
}
}
}
F_15 ( V_7 , L_3 ) ;
return - V_28 ;
}
static void F_16 ( struct V_11 * V_12 )
{
V_12 -> V_22 = 0 ;
V_12 -> V_23 = 0 ;
F_17 ( & V_12 -> V_2 ) ;
}
static void F_18 ( struct V_11 * V_12 ,
struct V_29 * V_30 ,
struct V_13 * V_14 )
{
struct V_4 * V_5 = F_2 ( & V_12 -> V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_1 V_31 ;
if ( 0 == V_12 -> V_32 ) {
F_19 ( V_12 -> V_33 ) ;
if ( F_20 ( V_30 ) ) {
if ( F_21 ( V_12 ) )
F_18 ( V_12 -> V_34 , V_30 , V_14 ) ;
else
F_7 ( V_12 , V_14 ) ;
}
}
V_31 = V_12 -> V_35 |
V_12 -> V_23 |
V_12 -> V_36 |
V_37 ;
F_22 ( & V_12 -> V_2 , V_38 , V_31 ) ;
V_12 -> V_32 ++ ;
F_13 ( V_7 , L_4 , F_14 ( & V_12 -> V_2 ) ) ;
}
static void F_23 ( struct V_11 * V_12 ,
struct V_29 * V_30 )
{
struct V_4 * V_5 = F_2 ( & V_12 -> V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
T_1 V_31 ;
if ( 0 == V_12 -> V_32 )
return;
V_12 -> V_32 -- ;
if ( 0 == V_12 -> V_32 ) {
V_31 = V_12 -> V_35 |
V_12 -> V_23 ;
F_22 ( & V_12 -> V_2 , V_38 , V_31 | V_37 ) ;
F_1 ( & V_12 -> V_2 , V_39 ) ;
F_22 ( & V_12 -> V_2 , V_38 , V_31 ) ;
F_1 ( & V_12 -> V_2 , V_40 ) ;
if ( F_20 ( V_30 ) ) {
if ( F_21 ( V_12 ) )
F_23 ( V_12 -> V_34 , V_30 ) ;
else
F_16 ( V_12 ) ;
}
F_24 ( V_12 -> V_33 ) ;
}
F_13 ( V_7 , L_5 , F_14 ( & V_12 -> V_2 ) ) ;
}
static int F_25 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
struct V_13 * V_14 = F_27 ( V_2 ) ;
struct V_15 * V_16 = F_8 ( V_14 ) ;
T_1 V_31 ;
V_31 = V_24 ;
V_31 |= V_25 ;
switch ( V_16 -> V_41 ) {
case 16 :
V_31 |= V_42 ;
break;
case 32 :
V_31 |= V_43 ;
break;
default:
return - V_28 ;
}
if ( V_30 -> V_44 )
V_31 |= V_45 ;
if ( V_30 -> V_46 )
V_31 |= V_47 ;
if ( V_30 -> V_48 )
V_31 |= V_49 ;
if ( V_30 -> V_50 )
V_31 |= V_51 ;
if ( F_28 ( V_30 , V_14 ) )
V_31 |= V_52 ;
V_12 -> V_30 = V_30 ;
V_12 -> V_35 = V_31 ;
V_12 -> V_53 = - 1 ;
F_29 ( V_2 , V_30 ) ;
return 0 ;
}
static int F_30 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
if ( V_12 -> V_53 > 0 )
F_6 ( V_7 , L_6 , V_12 -> V_53 ) ;
V_12 -> V_30 = NULL ;
V_12 -> V_35 = 0 ;
V_12 -> V_53 = 0 ;
return 0 ;
}
static void F_31 ( struct V_11 * V_12 , T_1 V_8 )
{
if ( V_8 & ( V_54 | V_55 ) ) {
V_12 -> V_53 ++ ;
F_22 ( & V_12 -> V_2 , V_10 , 0 ) ;
}
}
static T_2 F_32 ( int V_56 , void * V_57 )
{
struct V_11 * V_12 = V_57 ;
struct V_1 * V_2 = & V_12 -> V_2 ;
struct V_13 * V_14 = F_27 ( V_2 ) ;
T_1 V_8 = F_4 ( V_2 , V_10 ) ;
T_2 V_18 = V_58 ;
if ( V_14 && ( V_8 & V_39 ) ) {
struct V_29 * V_30 = V_12 -> V_30 ;
struct V_15 * V_16 = F_8 ( V_14 ) ;
T_1 * V_59 = ( T_1 * ) ( V_16 -> V_60 +
F_33 ( V_14 , 0 ) ) ;
F_31 ( V_12 , V_8 ) ;
if ( F_28 ( V_30 , V_14 ) )
F_22 ( V_2 , V_61 , * V_59 ) ;
else
* V_59 = F_4 ( V_2 , V_62 ) ;
F_34 ( V_14 , sizeof( * V_59 ) ) ;
V_18 = V_63 ;
}
return V_18 ;
}
static int F_35 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_11 * V_12 = F_26 ( V_2 ) ;
int V_56 = V_12 -> V_64 -> V_65 ;
int V_18 ;
V_18 = F_36 ( V_7 , V_56 ,
F_32 ,
V_66 ,
F_37 ( V_7 ) , V_12 ) ;
if ( V_18 )
F_15 ( V_7 , L_7 ) ;
F_13 ( V_7 , L_8 , F_38 ( V_2 ) ) ;
return V_18 ;
}
static int F_39 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
struct V_13 * V_14 = F_27 ( V_2 ) ;
V_12 -> V_36 = V_67 | V_68 | V_69 ;
F_40 ( V_2 , V_30 ) ;
F_18 ( V_12 , V_30 , V_14 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
V_12 -> V_36 = 0 ;
F_23 ( V_12 , V_30 ) ;
return 0 ;
}
static int F_42 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_11 * V_12 = F_26 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
int V_70 = V_12 -> V_64 -> V_70 ;
int V_18 ;
V_18 = F_43 (
V_5 , F_44 ( V_2 ) ,
F_45 ( V_5 , V_12 ) ,
V_70 ) ;
if ( V_18 < 0 )
F_15 ( V_7 , L_9 ) ;
F_13 ( V_7 , L_10 , F_38 ( V_2 ) ) ;
return V_18 ;
}
static int F_46 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
F_47 ( F_2 ( V_2 ) , F_44 ( V_2 ) ) ;
return 0 ;
}
static int F_48 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
struct V_71 * V_72 = F_44 ( & V_12 -> V_2 ) ;
struct V_13 * V_14 = F_27 ( V_2 ) ;
V_12 -> V_36 = V_73 ;
F_49 ( V_72 ) ;
F_18 ( V_12 , V_12 -> V_30 , V_14 ) ;
if ( F_20 ( V_30 ) )
F_22 ( & V_12 -> V_2 , V_74 , V_75 ) ;
return 0 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_29 * V_30 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
struct V_71 * V_72 = F_44 ( & V_12 -> V_2 ) ;
V_12 -> V_36 = 0 ;
F_31 ( V_12 , F_4 ( V_2 , V_10 ) ) ;
F_23 ( V_12 , V_30 ) ;
F_51 ( V_72 ) ;
return 0 ;
}
struct V_1 * F_52 ( struct V_4 * V_5 , int V_76 )
{
if ( F_53 ( V_76 < 0 || V_76 >= F_54 ( V_5 ) ) )
V_76 = 0 ;
return & ( (struct V_11 * ) ( V_5 -> V_12 ) + V_76 ) -> V_2 ;
}
int F_55 ( struct V_1 * V_2 )
{
struct V_11 * V_12 = F_26 ( V_2 ) ;
return ! ! ( F_56 ( V_12 ) & V_77 ) ;
}
static void F_57 ( struct V_4 * V_5 , struct V_11 * V_12 )
{
if ( ! F_55 ( & V_12 -> V_2 ) )
return;
switch ( F_14 ( & V_12 -> V_2 ) ) {
case 1 :
case 2 :
V_12 -> V_34 = F_26 ( F_52 ( V_5 , 0 ) ) ;
break;
case 4 :
V_12 -> V_34 = F_26 ( F_52 ( V_5 , 3 ) ) ;
break;
case 8 :
V_12 -> V_34 = F_26 ( F_52 ( V_5 , 7 ) ) ;
break;
}
}
static void F_58 ( struct V_78 * V_79 ,
const struct V_80 * V_81 ,
struct V_4 * V_5 )
{
struct V_82 * V_83 ;
struct V_82 * V_84 ;
struct V_85 * V_86 ;
struct V_87 * V_64 = F_59 ( V_5 ) ;
struct V_6 * V_7 = & V_79 -> V_7 ;
int V_88 , V_9 ;
if ( ! V_81 )
return;
V_83 = F_60 ( V_7 -> V_89 , L_11 ) ;
if ( ! V_83 )
return;
V_88 = F_61 ( V_83 ) ;
if ( ! V_88 )
goto V_90;
V_86 = F_62 ( V_7 ,
sizeof( struct V_85 ) * V_88 ,
V_91 ) ;
if ( ! V_86 ) {
F_15 ( V_7 , L_12 ) ;
goto V_90;
}
V_64 -> V_86 = V_86 ;
V_64 -> V_92 = V_88 ;
V_9 = - 1 ;
F_63 (node, np) {
V_9 ++ ;
V_86 = V_64 -> V_86 + V_9 ;
if ( F_64 ( V_84 , L_13 , NULL ) )
V_86 -> V_93 |= V_77 ;
V_86 -> V_65 = F_65 ( V_84 , 0 ) ;
V_86 -> V_70 = F_64 ( V_84 , L_14 , NULL ) ?
0 : 1 ;
}
V_90:
F_66 ( V_83 ) ;
}
int F_67 ( struct V_78 * V_79 ,
const struct V_80 * V_81 ,
struct V_4 * V_5 )
{
struct V_87 * V_64 = F_59 ( V_5 ) ;
struct V_85 * V_94 ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
struct V_95 * V_96 ;
struct V_33 * V_33 ;
struct V_11 * V_12 ;
char V_97 [ V_98 ] ;
int V_9 , V_88 ;
F_58 ( V_79 , V_81 , V_5 ) ;
V_88 = V_64 -> V_92 ;
V_12 = F_62 ( V_7 , sizeof( * V_12 ) * V_88 , V_91 ) ;
if ( ! V_12 ) {
F_15 ( V_7 , L_15 ) ;
return - V_99 ;
}
V_5 -> V_12 = V_12 ;
V_5 -> V_100 = V_88 ;
F_68 (ssi, priv, i) {
V_94 = & V_64 -> V_86 [ V_9 ] ;
snprintf ( V_97 , V_98 , L_16 ,
V_101 , V_9 ) ;
V_33 = F_69 ( V_7 , V_97 ) ;
if ( F_70 ( V_33 ) )
return F_71 ( V_33 ) ;
V_12 -> V_64 = V_94 ;
V_12 -> V_33 = V_33 ;
V_96 = & V_102 ;
if ( V_94 -> V_70 > 0 )
V_96 = & V_103 ;
else if ( F_72 ( V_12 ) )
V_96 = & V_104 ;
F_73 ( V_5 , & V_12 -> V_2 , V_96 , V_105 , V_9 ) ;
F_57 ( V_5 , V_12 ) ;
}
return 0 ;
}
