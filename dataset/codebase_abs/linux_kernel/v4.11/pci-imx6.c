static int F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
T_1 V_5 ;
T_1 V_6 = 10 ;
T_1 V_7 = 0 ;
do {
V_5 = F_2 ( V_4 , V_8 ) ;
V_5 = ( V_5 >> V_9 ) & 0x1 ;
V_7 ++ ;
if ( V_5 == V_2 )
return 0 ;
F_3 ( 1 ) ;
} while ( V_7 < V_6 );
return - V_10 ;
}
static int F_4 ( struct V_1 * V_1 , int V_11 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
T_1 V_5 ;
int V_12 ;
V_5 = V_11 << V_13 ;
F_5 ( V_4 , V_14 , V_5 ) ;
V_5 |= ( 0x1 << V_15 ) ;
F_5 ( V_4 , V_14 , V_5 ) ;
V_12 = F_1 ( V_1 , 1 ) ;
if ( V_12 )
return V_12 ;
V_5 = V_11 << V_13 ;
F_5 ( V_4 , V_14 , V_5 ) ;
return F_1 ( V_1 , 0 ) ;
}
static int F_6 ( struct V_1 * V_1 , int V_11 , int * V_16 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
T_1 V_5 , V_17 ;
int V_12 ;
V_12 = F_4 ( V_1 , V_11 ) ;
if ( V_12 )
return V_12 ;
V_17 = 0x1 << V_18 ;
F_5 ( V_4 , V_14 , V_17 ) ;
V_12 = F_1 ( V_1 , 1 ) ;
if ( V_12 )
return V_12 ;
V_5 = F_2 ( V_4 , V_8 ) ;
* V_16 = V_5 & 0xffff ;
F_5 ( V_4 , V_14 , 0x00 ) ;
return F_1 ( V_1 , 0 ) ;
}
static int F_7 ( struct V_1 * V_1 , int V_11 , int V_16 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
T_1 V_19 ;
int V_12 ;
V_12 = F_4 ( V_1 , V_11 ) ;
if ( V_12 )
return V_12 ;
V_19 = V_16 << V_13 ;
F_5 ( V_4 , V_14 , V_19 ) ;
V_19 |= ( 0x1 << V_20 ) ;
F_5 ( V_4 , V_14 , V_19 ) ;
V_12 = F_1 ( V_1 , 1 ) ;
if ( V_12 )
return V_12 ;
V_19 = V_16 << V_13 ;
F_5 ( V_4 , V_14 , V_19 ) ;
V_12 = F_1 ( V_1 , 0 ) ;
if ( V_12 )
return V_12 ;
V_19 = 0x1 << V_21 ;
F_5 ( V_4 , V_14 , V_19 ) ;
V_12 = F_1 ( V_1 , 1 ) ;
if ( V_12 )
return V_12 ;
V_19 = V_16 << V_13 ;
F_5 ( V_4 , V_14 , V_19 ) ;
V_12 = F_1 ( V_1 , 0 ) ;
if ( V_12 )
return V_12 ;
F_5 ( V_4 , V_14 , 0x0 ) ;
return 0 ;
}
static void F_8 ( struct V_1 * V_1 )
{
T_1 V_22 ;
F_6 ( V_1 , V_23 , & V_22 ) ;
V_22 |= ( V_24 |
V_25 ) ;
F_7 ( V_1 , V_23 , V_22 ) ;
F_9 ( 2000 , 3000 ) ;
F_6 ( V_1 , V_23 , & V_22 ) ;
V_22 &= ~ ( V_24 |
V_25 ) ;
F_7 ( V_1 , V_23 , V_22 ) ;
}
static int F_10 ( unsigned long V_11 ,
unsigned int V_26 , struct V_27 * V_28 )
{
return 0 ;
}
static void F_11 ( struct V_1 * V_1 )
{
switch ( V_1 -> V_29 ) {
case V_30 :
F_12 ( V_1 -> V_31 , V_32 ,
V_33 ,
V_33 ) ;
F_12 ( V_1 -> V_31 , V_34 ,
V_35 ,
V_35 ) ;
break;
case V_36 :
F_12 ( V_1 -> V_31 , V_37 ,
V_38 ,
V_38 ) ;
break;
case V_39 :
F_12 ( V_1 -> V_31 , V_37 ,
V_40 , 1 << 18 ) ;
F_12 ( V_1 -> V_31 , V_37 ,
V_41 , 0 << 16 ) ;
break;
}
}
static int F_13 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_42 * V_43 = V_4 -> V_43 ;
int V_12 = 0 ;
switch ( V_1 -> V_29 ) {
case V_30 :
V_12 = F_14 ( V_1 -> V_44 ) ;
if ( V_12 ) {
F_15 ( V_43 , L_1 ) ;
break;
}
F_12 ( V_1 -> V_31 , V_32 ,
V_33 , 0 ) ;
break;
case V_36 :
case V_39 :
F_12 ( V_1 -> V_31 , V_37 ,
V_40 , 0 << 18 ) ;
F_3 ( 10 ) ;
F_12 ( V_1 -> V_31 , V_37 ,
V_41 , 1 << 16 ) ;
break;
}
return V_12 ;
}
static void F_16 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_42 * V_43 = V_4 -> V_43 ;
int V_12 ;
V_12 = F_14 ( V_1 -> V_45 ) ;
if ( V_12 ) {
F_15 ( V_43 , L_2 ) ;
return;
}
V_12 = F_14 ( V_1 -> V_46 ) ;
if ( V_12 ) {
F_15 ( V_43 , L_3 ) ;
goto V_47;
}
V_12 = F_14 ( V_1 -> V_48 ) ;
if ( V_12 ) {
F_15 ( V_43 , L_4 ) ;
goto V_49;
}
V_12 = F_13 ( V_1 ) ;
if ( V_12 ) {
F_15 ( V_43 , L_5 ) ;
goto V_50;
}
F_9 ( 200 , 500 ) ;
if ( F_17 ( V_1 -> V_51 ) ) {
F_18 ( V_1 -> V_51 ,
V_1 -> V_52 ) ;
F_19 ( 100 ) ;
F_18 ( V_1 -> V_51 ,
! V_1 -> V_52 ) ;
}
switch ( V_1 -> V_29 ) {
case V_30 :
F_12 ( V_1 -> V_31 , V_34 ,
V_35 , 0 ) ;
break;
case V_36 :
F_12 ( V_1 -> V_31 , V_37 ,
V_38 , 0 ) ;
F_9 ( 200 , 500 ) ;
break;
case V_39 :
break;
}
return;
V_50:
F_20 ( V_1 -> V_48 ) ;
V_49:
F_20 ( V_1 -> V_46 ) ;
V_47:
F_20 ( V_1 -> V_45 ) ;
}
static void F_21 ( struct V_1 * V_1 )
{
if ( V_1 -> V_29 == V_30 )
F_12 ( V_1 -> V_31 , V_32 ,
V_53 ,
V_54 ) ;
F_12 ( V_1 -> V_31 , V_32 ,
V_55 , 0 << 10 ) ;
F_12 ( V_1 -> V_31 , V_32 ,
V_56 , V_57 << 12 ) ;
F_12 ( V_1 -> V_31 , V_32 ,
V_58 , 9 << 4 ) ;
F_12 ( V_1 -> V_31 , V_59 ,
V_60 ,
V_1 -> V_61 << 0 ) ;
F_12 ( V_1 -> V_31 , V_59 ,
V_62 ,
V_1 -> V_63 << 6 ) ;
F_12 ( V_1 -> V_31 , V_59 ,
V_64 ,
V_1 -> V_65 << 12 ) ;
F_12 ( V_1 -> V_31 , V_59 ,
V_66 ,
V_1 -> V_67 << 18 ) ;
F_12 ( V_1 -> V_31 , V_59 ,
V_68 ,
V_1 -> V_69 << 25 ) ;
}
static int F_22 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_42 * V_43 = V_4 -> V_43 ;
if ( ! F_23 ( V_4 ) )
return 0 ;
F_24 ( V_43 , L_6 ,
F_2 ( V_4 , V_70 ) ,
F_2 ( V_4 , V_71 ) ) ;
return - V_10 ;
}
static int F_25 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_42 * V_43 = V_4 -> V_43 ;
T_1 V_22 ;
unsigned int V_72 ;
for ( V_72 = 0 ; V_72 < 200 ; V_72 ++ ) {
V_22 = F_2 ( V_4 , V_73 ) ;
if ( ! ( V_22 & V_74 ) )
return 0 ;
F_9 ( 100 , 1000 ) ;
}
F_15 ( V_43 , L_7 ) ;
return - V_75 ;
}
static T_2 F_26 ( int V_76 , void * V_77 )
{
struct V_1 * V_1 = V_77 ;
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_78 * V_79 = & V_4 -> V_79 ;
return F_27 ( V_79 ) ;
}
static int F_28 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_42 * V_43 = V_4 -> V_43 ;
T_1 V_22 ;
int V_12 ;
V_22 = F_2 ( V_4 , V_80 ) ;
V_22 &= ~ V_81 ;
V_22 |= V_82 ;
F_5 ( V_4 , V_80 , V_22 ) ;
F_12 ( V_1 -> V_31 , V_32 ,
V_55 , 1 << 10 ) ;
V_12 = F_22 ( V_1 ) ;
if ( V_12 )
goto V_83;
if ( V_1 -> V_84 == 2 ) {
V_22 = F_2 ( V_4 , V_80 ) ;
V_22 &= ~ V_81 ;
V_22 |= V_85 ;
F_5 ( V_4 , V_80 , V_22 ) ;
} else {
F_29 ( V_43 , L_8 ) ;
}
V_22 = F_2 ( V_4 , V_73 ) ;
V_22 |= V_74 ;
F_5 ( V_4 , V_73 , V_22 ) ;
V_12 = F_25 ( V_1 ) ;
if ( V_12 ) {
F_15 ( V_43 , L_9 ) ;
goto V_83;
}
V_12 = F_22 ( V_1 ) ;
if ( V_12 ) {
F_15 ( V_43 , L_9 ) ;
goto V_83;
}
V_22 = F_2 ( V_4 , V_86 ) ;
F_29 ( V_43 , L_10 , ( V_22 >> 16 ) & 0xf ) ;
return 0 ;
V_83:
F_24 ( V_43 , L_11 ,
F_2 ( V_4 , V_70 ) ,
F_2 ( V_4 , V_71 ) ) ;
F_8 ( V_1 ) ;
return V_12 ;
}
static void F_30 ( struct V_78 * V_79 )
{
struct V_3 * V_4 = F_31 ( V_79 ) ;
struct V_1 * V_1 = F_32 ( V_4 ) ;
F_11 ( V_1 ) ;
F_21 ( V_1 ) ;
F_16 ( V_1 ) ;
F_33 ( V_79 ) ;
F_28 ( V_1 ) ;
if ( F_34 ( V_87 ) )
F_35 ( V_79 ) ;
}
static int F_36 ( struct V_3 * V_4 )
{
return F_2 ( V_4 , V_71 ) &
V_88 ;
}
static int T_3 F_37 ( struct V_1 * V_1 ,
struct V_89 * V_90 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
struct V_78 * V_79 = & V_4 -> V_79 ;
struct V_42 * V_43 = & V_90 -> V_43 ;
int V_12 ;
if ( F_34 ( V_87 ) ) {
V_79 -> V_91 = F_38 ( V_90 , L_12 ) ;
if ( V_79 -> V_91 <= 0 ) {
F_15 ( V_43 , L_13 ) ;
return - V_92 ;
}
V_12 = F_39 ( V_43 , V_79 -> V_91 ,
F_26 ,
V_93 | V_94 ,
L_14 , V_1 ) ;
if ( V_12 ) {
F_15 ( V_43 , L_15 ) ;
return V_12 ;
}
}
V_79 -> V_95 = - 1 ;
V_79 -> V_96 = & V_97 ;
V_12 = F_40 ( V_79 ) ;
if ( V_12 ) {
F_15 ( V_43 , L_16 ) ;
return V_12 ;
}
return 0 ;
}
static int T_3 F_41 ( struct V_89 * V_90 )
{
struct V_42 * V_43 = & V_90 -> V_43 ;
struct V_3 * V_4 ;
struct V_1 * V_1 ;
struct V_98 * V_99 ;
struct V_100 * V_101 = V_43 -> V_102 ;
int V_12 ;
V_1 = F_42 ( V_43 , sizeof( * V_1 ) , V_103 ) ;
if ( ! V_1 )
return - V_104 ;
V_4 = F_42 ( V_43 , sizeof( * V_4 ) , V_103 ) ;
if ( ! V_4 )
return - V_104 ;
V_4 -> V_43 = V_43 ;
V_4 -> V_96 = & V_105 ;
V_1 -> V_4 = V_4 ;
V_1 -> V_29 =
(enum V_106 ) F_43 ( V_43 ) ;
F_44 ( 16 + 6 , F_10 , V_107 , 0 ,
L_17 ) ;
V_99 = F_45 ( V_90 , V_108 , 0 ) ;
V_4 -> V_99 = F_46 ( V_43 , V_99 ) ;
if ( F_47 ( V_4 -> V_99 ) )
return F_48 ( V_4 -> V_99 ) ;
V_1 -> V_51 = F_49 ( V_101 , L_18 , 0 ) ;
V_1 -> V_52 = F_50 ( V_101 ,
L_19 ) ;
if ( F_17 ( V_1 -> V_51 ) ) {
V_12 = F_51 ( V_43 , V_1 -> V_51 ,
V_1 -> V_52 ?
V_109 :
V_110 ,
L_20 ) ;
if ( V_12 ) {
F_15 ( V_43 , L_21 ) ;
return V_12 ;
}
}
V_1 -> V_45 = F_52 ( V_43 , L_22 ) ;
if ( F_47 ( V_1 -> V_45 ) ) {
F_15 ( V_43 , L_23 ) ;
return F_48 ( V_1 -> V_45 ) ;
}
V_1 -> V_46 = F_52 ( V_43 , L_24 ) ;
if ( F_47 ( V_1 -> V_46 ) ) {
F_15 ( V_43 , L_25 ) ;
return F_48 ( V_1 -> V_46 ) ;
}
V_1 -> V_48 = F_52 ( V_43 , L_26 ) ;
if ( F_47 ( V_1 -> V_48 ) ) {
F_15 ( V_43 , L_27 ) ;
return F_48 ( V_1 -> V_48 ) ;
}
if ( V_1 -> V_29 == V_30 ) {
V_1 -> V_44 = F_52 ( V_43 ,
L_28 ) ;
if ( F_47 ( V_1 -> V_44 ) ) {
F_15 ( V_43 , L_29 ) ;
return F_48 ( V_1 -> V_44 ) ;
}
}
V_1 -> V_31 =
F_53 ( L_30 ) ;
if ( F_47 ( V_1 -> V_31 ) ) {
F_15 ( V_43 , L_31 ) ;
return F_48 ( V_1 -> V_31 ) ;
}
if ( F_54 ( V_101 , L_32 ,
& V_1 -> V_61 ) )
V_1 -> V_61 = 0 ;
if ( F_54 ( V_101 , L_33 ,
& V_1 -> V_63 ) )
V_1 -> V_63 = 0 ;
if ( F_54 ( V_101 , L_34 ,
& V_1 -> V_65 ) )
V_1 -> V_65 = 20 ;
if ( F_54 ( V_101 , L_35 ,
& V_1 -> V_67 ) )
V_1 -> V_67 = 127 ;
if ( F_54 ( V_101 , L_36 ,
& V_1 -> V_69 ) )
V_1 -> V_69 = 127 ;
V_12 = F_54 ( V_101 , L_37 ,
& V_1 -> V_84 ) ;
if ( V_12 )
V_1 -> V_84 = 1 ;
F_55 ( V_90 , V_1 ) ;
V_12 = F_37 ( V_1 , V_90 ) ;
if ( V_12 < 0 )
return V_12 ;
return 0 ;
}
static void F_56 ( struct V_89 * V_90 )
{
struct V_1 * V_1 = F_57 ( V_90 ) ;
F_11 ( V_1 ) ;
}
static int T_3 F_58 ( void )
{
return F_59 ( & V_111 , F_41 ) ;
}
