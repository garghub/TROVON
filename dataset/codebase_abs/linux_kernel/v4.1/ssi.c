int F_1 ( struct V_1 * V_2 )
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
struct V_10 * V_11 = F_14 ( V_6 ) ;
struct V_17 * V_18 = F_15 ( V_6 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_15 , V_19 , V_20 ;
int V_21 [] = {
1 , 6 ,
} ;
int V_22 [] = {
1 , 2 , 4 , 8 , 16 , 6 , 12 ,
} ;
unsigned int V_23 ;
unsigned int V_24 = F_16 ( V_11 , V_6 , V_18 ) ;
for ( V_15 = 0 ; V_15 < F_17 ( V_21 ) ; V_15 ++ ) {
for ( V_19 = 0 ; V_19 < F_17 ( V_22 ) ; V_19 ++ ) {
V_23 = V_24 / V_21 [ V_15 ]
* 32 * 2 * V_22 [ V_19 ] ;
V_20 = F_18 ( & V_4 -> V_2 , V_23 ) ;
if ( 0 == V_20 ) {
V_4 -> V_25 = V_26 | V_27 |
V_28 | V_29 | F_19 ( V_19 ) ;
F_20 ( V_13 , L_2 ,
F_21 ( & V_4 -> V_2 ) ,
F_22 ( & V_4 -> V_2 ) , V_24 ) ;
return 0 ;
}
}
}
F_23 ( V_13 , L_3 ) ;
return - V_30 ;
}
static void F_24 ( struct V_3 * V_4 )
{
V_4 -> V_25 = 0 ;
F_25 ( & V_4 -> V_2 ) ;
}
static void F_26 ( struct V_3 * V_4 ,
struct V_5 * V_6 )
{
struct V_10 * V_11 = F_14 ( V_6 ) ;
struct V_31 * V_32 = F_27 ( V_6 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
T_1 V_33 ;
T_1 V_34 ;
if ( 0 == V_4 -> V_35 ) {
F_28 ( & V_4 -> V_2 ) ;
if ( F_29 ( V_32 ) ) {
if ( F_30 ( V_4 ) )
F_26 ( V_4 -> V_36 , V_6 ) ;
else
F_13 ( V_4 , V_6 ) ;
}
}
V_33 = F_4 ( & V_4 -> V_2 ) ?
V_37 :
V_38 ;
V_34 = V_4 -> V_39 |
V_4 -> V_25 |
V_33 |
V_40 | V_41 | V_42 ;
F_31 ( & V_4 -> V_2 , V_43 , V_34 ) ;
if ( F_29 ( V_32 ) )
F_31 ( & V_4 -> V_2 , V_44 , V_45 ) ;
F_31 ( & V_4 -> V_2 , V_16 , 0 ) ;
V_4 -> V_35 ++ ;
F_20 ( V_13 , L_4 ,
F_21 ( & V_4 -> V_2 ) , F_22 ( & V_4 -> V_2 ) ) ;
}
static void F_32 ( struct V_3 * V_4 )
{
struct V_10 * V_11 = F_8 ( & V_4 -> V_2 ) ;
struct V_5 * V_6 = F_3 ( & V_4 -> V_2 ) ;
struct V_31 * V_32 = F_27 ( V_6 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
T_1 V_34 ;
if ( 0 == V_4 -> V_35 )
return;
V_4 -> V_35 -- ;
if ( 0 == V_4 -> V_35 ) {
V_34 = V_4 -> V_39 |
V_4 -> V_25 ;
F_31 ( & V_4 -> V_2 , V_43 , V_34 | V_42 ) ;
F_7 ( & V_4 -> V_2 , V_46 ) ;
F_31 ( & V_4 -> V_2 , V_43 , V_34 ) ;
F_7 ( & V_4 -> V_2 , V_47 ) ;
if ( F_29 ( V_32 ) ) {
if ( F_30 ( V_4 ) )
F_32 ( V_4 -> V_36 ) ;
else
F_24 ( V_4 ) ;
}
F_33 ( & V_4 -> V_2 ) ;
}
F_20 ( V_13 , L_5 ,
F_21 ( & V_4 -> V_2 ) , F_22 ( & V_4 -> V_2 ) ) ;
}
static int F_34 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
struct V_31 * V_32 = F_27 ( V_6 ) ;
struct V_17 * V_18 = F_15 ( V_6 ) ;
T_1 V_34 ;
V_34 = V_26 ;
V_34 |= V_27 ;
switch ( V_18 -> V_48 ) {
case 16 :
V_34 |= V_49 ;
break;
case 32 :
V_34 |= V_50 ;
break;
default:
return - V_30 ;
}
if ( V_32 -> V_51 )
V_34 |= V_52 ;
if ( V_32 -> V_53 )
V_34 |= V_54 ;
if ( V_32 -> V_55 )
V_34 |= V_56 ;
if ( V_32 -> V_57 )
V_34 |= V_58 ;
if ( F_35 ( V_6 ) )
V_34 |= V_59 ;
V_4 -> V_39 = V_34 ;
V_4 -> V_60 = - 1 ;
return 0 ;
}
static int F_36 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
if ( V_4 -> V_60 > 0 )
F_12 ( V_13 , L_6 ,
F_21 ( V_2 ) , F_22 ( V_2 ) , V_4 -> V_60 ) ;
V_4 -> V_39 = 0 ;
V_4 -> V_60 = 0 ;
return 0 ;
}
static void F_37 ( struct V_3 * V_4 , T_1 V_14 )
{
if ( V_14 & ( V_61 | V_62 ) ) {
V_4 -> V_60 ++ ;
F_31 ( & V_4 -> V_2 , V_16 , 0 ) ;
}
}
static int F_38 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
F_39 ( V_2 , F_1 ( V_2 ) ) ;
F_26 ( V_4 , V_6 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
static int F_41 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_42 ( V_2 ) ;
F_37 ( V_4 , F_10 ( V_2 , V_16 ) ) ;
F_32 ( V_4 ) ;
F_43 ( V_2 ) ;
return 0 ;
}
static T_2 F_44 ( int V_63 , void * V_64 )
{
struct V_3 * V_4 = V_64 ;
struct V_1 * V_2 = & V_4 -> V_2 ;
struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
int V_65 = F_4 ( V_2 ) ;
T_1 V_14 = F_10 ( V_2 , V_16 ) ;
if ( ! V_6 )
return V_66 ;
if ( ! V_65 && ( V_14 & V_46 ) ) {
struct V_17 * V_18 = F_15 ( V_6 ) ;
T_1 * V_67 = ( T_1 * ) ( V_18 -> V_68 +
F_45 ( V_6 , 0 ) ) ;
if ( F_35 ( V_6 ) )
F_31 ( V_2 , V_69 , * V_67 ) ;
else
* V_67 = F_10 ( V_2 , V_70 ) ;
F_46 ( V_6 , sizeof( * V_67 ) ) ;
}
if ( V_14 & ( V_61 | V_62 ) ) {
struct V_12 * V_13 = F_9 ( V_11 ) ;
F_20 ( V_13 , L_7 ,
F_21 ( V_2 ) , F_22 ( V_2 ) ) ;
F_41 ( V_2 , V_11 ) ;
if ( V_4 -> V_60 < 1024 )
F_38 ( V_2 , V_11 ) ;
else
F_12 ( V_13 , L_8 ) ;
}
F_37 ( V_4 , V_14 ) ;
return V_71 ;
}
static int F_47 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_20 ;
V_20 = F_48 ( V_13 , V_4 -> V_72 -> V_63 ,
F_44 ,
V_73 ,
F_49 ( V_13 ) , V_4 ) ;
return V_20 ;
}
static int F_50 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_74 = V_4 -> V_72 -> V_74 ;
int V_20 ;
V_20 = F_48 ( V_13 , V_4 -> V_72 -> V_63 ,
F_44 ,
V_73 ,
F_49 ( V_13 ) , V_4 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_51 (
V_11 , F_52 ( V_2 ) ,
V_74 ) ;
return V_20 ;
}
static int F_53 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
int V_63 = V_4 -> V_72 -> V_63 ;
F_54 ( F_52 ( V_2 ) ) ;
F_55 ( V_13 , V_63 , V_4 ) ;
return 0 ;
}
static int F_56 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_12 * V_13 = F_9 ( V_11 ) ;
V_2 -> V_75 = & V_76 ;
F_57 ( V_13 , L_9 ,
F_21 ( V_2 ) , F_22 ( V_2 ) ) ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_77 * V_78 = F_52 ( V_2 ) ;
F_59 ( V_78 ) ;
F_38 ( V_2 , V_11 ) ;
return 0 ;
}
static int F_60 ( struct V_1 * V_2 ,
struct V_10 * V_11 )
{
struct V_77 * V_78 = F_52 ( V_2 ) ;
F_41 ( V_2 , V_11 ) ;
F_61 ( V_78 ) ;
return 0 ;
}
static struct V_79 * F_62 ( struct V_1 * V_2 )
{
struct V_10 * V_11 = F_8 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 ) ;
int V_80 = F_35 ( V_6 ) ;
char * V_81 ;
if ( F_1 ( V_2 ) )
V_81 = V_80 ? L_10 : L_11 ;
else
V_81 = V_80 ? L_12 : L_13 ;
return F_63 ( F_64 ( V_11 ) ,
V_2 , V_81 ) ;
}
int F_4 ( struct V_1 * V_2 )
{
return V_2 -> V_75 == & V_82 ;
}
struct V_1 * F_65 ( struct V_10 * V_11 , int V_83 )
{
if ( F_66 ( V_83 < 0 || V_83 >= F_67 ( V_11 ) ) )
V_83 = 0 ;
return & ( (struct V_3 * ) ( V_11 -> V_4 ) + V_83 ) -> V_2 ;
}
int F_68 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
return ! ! ( F_5 ( V_4 ) & V_84 ) ;
}
static void F_69 ( struct V_10 * V_11 , struct V_3 * V_4 )
{
if ( ! F_68 ( & V_4 -> V_2 ) )
return;
switch ( F_22 ( & V_4 -> V_2 ) ) {
case 1 :
case 2 :
V_4 -> V_36 = F_2 ( F_65 ( V_11 , 0 ) ) ;
break;
case 4 :
V_4 -> V_36 = F_2 ( F_65 ( V_11 , 3 ) ) ;
break;
case 8 :
V_4 -> V_36 = F_2 ( F_65 ( V_11 , 7 ) ) ;
break;
}
}
static void F_70 ( struct V_85 * V_86 ,
const struct V_87 * V_88 ,
struct V_10 * V_11 )
{
struct V_89 * V_90 ;
struct V_89 * V_91 ;
struct V_92 * V_93 ;
struct V_94 * V_72 = F_71 ( V_11 ) ;
struct V_12 * V_13 = & V_86 -> V_13 ;
int V_95 , V_15 ;
if ( ! V_88 )
return;
V_90 = F_64 ( V_11 ) ;
if ( ! V_90 )
return;
V_95 = F_72 ( V_90 ) ;
if ( ! V_95 )
goto V_96;
V_93 = F_73 ( V_13 ,
sizeof( struct V_92 ) * V_95 ,
V_97 ) ;
if ( ! V_93 ) {
F_23 ( V_13 , L_14 ) ;
goto V_96;
}
V_72 -> V_93 = V_93 ;
V_72 -> V_98 = V_95 ;
V_15 = - 1 ;
F_74 (node, np) {
V_15 ++ ;
V_93 = V_72 -> V_93 + V_15 ;
if ( F_75 ( V_91 , L_15 , NULL ) )
V_93 -> V_99 |= V_84 ;
V_93 -> V_63 = F_76 ( V_91 , 0 ) ;
V_93 -> V_74 = F_75 ( V_91 , L_16 , NULL ) ?
0 : 1 ;
if ( F_75 ( V_91 , L_17 , NULL ) )
V_93 -> V_99 |= V_8 ;
}
V_96:
F_77 ( V_90 ) ;
}
int F_78 ( struct V_85 * V_86 ,
const struct V_87 * V_88 ,
struct V_10 * V_11 )
{
struct V_94 * V_72 = F_71 ( V_11 ) ;
struct V_92 * V_100 ;
struct V_12 * V_13 = F_9 ( V_11 ) ;
struct V_101 * V_75 ;
struct V_102 * V_102 ;
struct V_3 * V_4 ;
char V_81 [ V_103 ] ;
int V_15 , V_95 , V_20 ;
F_70 ( V_86 , V_88 , V_11 ) ;
V_95 = V_72 -> V_98 ;
V_4 = F_73 ( V_13 , sizeof( * V_4 ) * V_95 , V_97 ) ;
if ( ! V_4 ) {
F_23 ( V_13 , L_18 ) ;
return - V_104 ;
}
V_11 -> V_4 = V_4 ;
V_11 -> V_105 = V_95 ;
F_79 (ssi, priv, i) {
V_100 = & V_72 -> V_93 [ V_15 ] ;
snprintf ( V_81 , V_103 , L_19 ,
V_106 , V_15 ) ;
V_102 = F_80 ( V_13 , V_81 ) ;
if ( F_81 ( V_102 ) )
return F_82 ( V_102 ) ;
V_4 -> V_72 = V_100 ;
V_75 = & V_107 ;
if ( V_100 -> V_74 > 0 )
V_75 = & V_82 ;
else if ( F_83 ( V_4 ) )
V_75 = & V_76 ;
V_20 = F_84 ( & V_4 -> V_2 , V_75 , V_102 , V_108 , V_15 ) ;
if ( V_20 )
return V_20 ;
F_69 ( V_11 , V_4 ) ;
}
return 0 ;
}
void F_85 ( struct V_85 * V_86 ,
struct V_10 * V_11 )
{
struct V_3 * V_4 ;
int V_15 ;
F_79 (ssi, priv, i) {
F_86 ( & V_4 -> V_2 ) ;
}
}
