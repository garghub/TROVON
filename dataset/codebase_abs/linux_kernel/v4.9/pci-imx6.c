static int F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = & V_1 -> V_4 ;
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
struct V_3 * V_4 = & V_1 -> V_4 ;
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
struct V_3 * V_4 = & V_1 -> V_4 ;
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
struct V_3 * V_4 = & V_1 -> V_4 ;
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
struct V_3 * V_4 = & V_1 -> V_4 ;
T_1 V_5 , V_29 , V_30 ;
switch ( V_1 -> V_31 ) {
case V_32 :
F_12 ( V_1 -> V_33 , V_34 ,
V_35 ,
V_35 ) ;
F_12 ( V_1 -> V_33 , V_36 ,
V_37 ,
V_37 ) ;
break;
case V_38 :
F_12 ( V_1 -> V_33 , V_39 ,
V_40 ,
V_40 ) ;
break;
case V_41 :
F_13 ( V_1 -> V_33 , V_39 , & V_29 ) ;
F_13 ( V_1 -> V_33 , V_34 , & V_30 ) ;
if ( ( V_29 & V_42 ) &&
( V_30 & V_43 ) ) {
V_5 = F_2 ( V_4 , V_44 ) ;
V_5 &= ~ V_45 ;
V_5 |= V_46 ;
F_5 ( V_4 , V_44 , V_5 ) ;
F_12 ( V_1 -> V_33 , V_34 ,
V_43 , 0 << 10 ) ;
}
F_12 ( V_1 -> V_33 , V_39 ,
V_47 , 1 << 18 ) ;
F_12 ( V_1 -> V_33 , V_39 ,
V_42 , 0 << 16 ) ;
break;
}
}
static int F_14 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = & V_1 -> V_4 ;
struct V_48 * V_49 = V_4 -> V_49 ;
int V_12 = 0 ;
switch ( V_1 -> V_31 ) {
case V_32 :
V_12 = F_15 ( V_1 -> V_50 ) ;
if ( V_12 ) {
F_16 ( V_49 , L_1 ) ;
break;
}
F_12 ( V_1 -> V_33 , V_34 ,
V_35 , 0 ) ;
break;
case V_38 :
case V_41 :
F_12 ( V_1 -> V_33 , V_39 ,
V_47 , 0 << 18 ) ;
F_3 ( 10 ) ;
F_12 ( V_1 -> V_33 , V_39 ,
V_42 , 1 << 16 ) ;
break;
}
return V_12 ;
}
static void F_17 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = & V_1 -> V_4 ;
struct V_48 * V_49 = V_4 -> V_49 ;
int V_12 ;
V_12 = F_15 ( V_1 -> V_51 ) ;
if ( V_12 ) {
F_16 ( V_49 , L_2 ) ;
return;
}
V_12 = F_15 ( V_1 -> V_52 ) ;
if ( V_12 ) {
F_16 ( V_49 , L_3 ) ;
goto V_53;
}
V_12 = F_15 ( V_1 -> V_54 ) ;
if ( V_12 ) {
F_16 ( V_49 , L_4 ) ;
goto V_55;
}
V_12 = F_14 ( V_1 ) ;
if ( V_12 ) {
F_16 ( V_49 , L_5 ) ;
goto V_56;
}
F_9 ( 200 , 500 ) ;
if ( F_18 ( V_1 -> V_57 ) ) {
F_19 ( V_1 -> V_57 ,
V_1 -> V_58 ) ;
F_20 ( 100 ) ;
F_19 ( V_1 -> V_57 ,
! V_1 -> V_58 ) ;
}
switch ( V_1 -> V_31 ) {
case V_32 :
F_12 ( V_1 -> V_33 , V_36 ,
V_37 , 0 ) ;
break;
case V_38 :
F_12 ( V_1 -> V_33 , V_39 ,
V_40 , 0 ) ;
F_9 ( 200 , 500 ) ;
break;
case V_41 :
break;
}
return;
V_56:
F_21 ( V_1 -> V_54 ) ;
V_55:
F_21 ( V_1 -> V_52 ) ;
V_53:
F_21 ( V_1 -> V_51 ) ;
}
static void F_22 ( struct V_1 * V_1 )
{
if ( V_1 -> V_31 == V_32 )
F_12 ( V_1 -> V_33 , V_34 ,
V_59 ,
V_60 ) ;
F_12 ( V_1 -> V_33 , V_34 ,
V_43 , 0 << 10 ) ;
F_12 ( V_1 -> V_33 , V_34 ,
V_61 , V_62 << 12 ) ;
F_12 ( V_1 -> V_33 , V_34 ,
V_63 , 9 << 4 ) ;
F_12 ( V_1 -> V_33 , V_64 ,
V_65 ,
V_1 -> V_66 << 0 ) ;
F_12 ( V_1 -> V_33 , V_64 ,
V_67 ,
V_1 -> V_68 << 6 ) ;
F_12 ( V_1 -> V_33 , V_64 ,
V_69 ,
V_1 -> V_70 << 12 ) ;
F_12 ( V_1 -> V_33 , V_64 ,
V_71 ,
V_1 -> V_72 << 18 ) ;
F_12 ( V_1 -> V_33 , V_64 ,
V_73 ,
V_1 -> V_74 << 25 ) ;
}
static int F_23 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = & V_1 -> V_4 ;
struct V_48 * V_49 = V_4 -> V_49 ;
if ( ! F_24 ( V_4 ) )
return 0 ;
F_25 ( V_49 , L_6 ,
F_2 ( V_4 , V_75 ) ,
F_2 ( V_4 , V_76 ) ) ;
return - V_10 ;
}
static int F_26 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = & V_1 -> V_4 ;
struct V_48 * V_49 = V_4 -> V_49 ;
T_1 V_22 ;
unsigned int V_77 ;
for ( V_77 = 0 ; V_77 < 200 ; V_77 ++ ) {
V_22 = F_2 ( V_4 , V_78 ) ;
if ( ! ( V_22 & V_79 ) )
return 0 ;
F_9 ( 100 , 1000 ) ;
}
F_16 ( V_49 , L_7 ) ;
return - V_80 ;
}
static T_2 F_27 ( int V_81 , void * V_82 )
{
struct V_1 * V_1 = V_82 ;
struct V_3 * V_4 = & V_1 -> V_4 ;
return F_28 ( V_4 ) ;
}
static int F_29 ( struct V_1 * V_1 )
{
struct V_3 * V_4 = & V_1 -> V_4 ;
struct V_48 * V_49 = V_4 -> V_49 ;
T_1 V_22 ;
int V_12 ;
V_22 = F_2 ( V_4 , V_83 ) ;
V_22 &= ~ V_84 ;
V_22 |= V_85 ;
F_5 ( V_4 , V_83 , V_22 ) ;
F_12 ( V_1 -> V_33 , V_34 ,
V_43 , 1 << 10 ) ;
V_12 = F_23 ( V_1 ) ;
if ( V_12 ) {
F_30 ( V_49 , L_8 ) ;
goto V_86;
}
if ( V_1 -> V_87 == 2 ) {
V_22 = F_2 ( V_4 , V_83 ) ;
V_22 &= ~ V_84 ;
V_22 |= V_88 ;
F_5 ( V_4 , V_83 , V_22 ) ;
} else {
F_30 ( V_49 , L_9 ) ;
}
V_22 = F_2 ( V_4 , V_78 ) ;
V_22 |= V_79 ;
F_5 ( V_4 , V_78 , V_22 ) ;
V_12 = F_26 ( V_1 ) ;
if ( V_12 ) {
F_16 ( V_49 , L_10 ) ;
goto V_86;
}
V_12 = F_23 ( V_1 ) ;
if ( V_12 ) {
F_16 ( V_49 , L_10 ) ;
goto V_86;
}
V_22 = F_2 ( V_4 , V_89 ) ;
F_30 ( V_49 , L_11 , ( V_22 >> 16 ) & 0xf ) ;
return 0 ;
V_86:
F_25 ( V_49 , L_12 ,
F_2 ( V_4 , V_75 ) ,
F_2 ( V_4 , V_76 ) ) ;
F_8 ( V_1 ) ;
return V_12 ;
}
static void F_31 ( struct V_3 * V_4 )
{
struct V_1 * V_1 = F_32 ( V_4 ) ;
F_11 ( V_1 ) ;
F_22 ( V_1 ) ;
F_17 ( V_1 ) ;
F_33 ( V_4 ) ;
F_29 ( V_1 ) ;
if ( F_34 ( V_90 ) )
F_35 ( V_4 ) ;
}
static int F_36 ( struct V_3 * V_4 )
{
return F_2 ( V_4 , V_76 ) &
V_91 ;
}
static int T_3 F_37 ( struct V_1 * V_1 ,
struct V_92 * V_93 )
{
struct V_3 * V_4 = & V_1 -> V_4 ;
struct V_48 * V_49 = V_4 -> V_49 ;
int V_12 ;
if ( F_34 ( V_90 ) ) {
V_4 -> V_94 = F_38 ( V_93 , L_13 ) ;
if ( V_4 -> V_94 <= 0 ) {
F_16 ( V_49 , L_14 ) ;
return - V_95 ;
}
V_12 = F_39 ( V_49 , V_4 -> V_94 ,
F_27 ,
V_96 | V_97 ,
L_15 , V_1 ) ;
if ( V_12 ) {
F_16 ( V_49 , L_16 ) ;
return V_12 ;
}
}
V_4 -> V_98 = - 1 ;
V_4 -> V_99 = & V_100 ;
V_12 = F_40 ( V_4 ) ;
if ( V_12 ) {
F_16 ( V_49 , L_17 ) ;
return V_12 ;
}
return 0 ;
}
static int T_3 F_41 ( struct V_92 * V_93 )
{
struct V_48 * V_49 = & V_93 -> V_49 ;
struct V_1 * V_1 ;
struct V_3 * V_4 ;
struct V_101 * V_102 ;
struct V_103 * V_104 = V_49 -> V_105 ;
int V_12 ;
V_1 = F_42 ( V_49 , sizeof( * V_1 ) , V_106 ) ;
if ( ! V_1 )
return - V_107 ;
V_4 = & V_1 -> V_4 ;
V_4 -> V_49 = V_49 ;
V_1 -> V_31 =
(enum V_108 ) F_43 ( V_49 ) ;
F_44 ( 16 + 6 , F_10 , V_109 , 0 ,
L_18 ) ;
V_102 = F_45 ( V_93 , V_110 , 0 ) ;
V_4 -> V_102 = F_46 ( V_49 , V_102 ) ;
if ( F_47 ( V_4 -> V_102 ) )
return F_48 ( V_4 -> V_102 ) ;
V_1 -> V_57 = F_49 ( V_104 , L_19 , 0 ) ;
V_1 -> V_58 = F_50 ( V_104 ,
L_20 ) ;
if ( F_18 ( V_1 -> V_57 ) ) {
V_12 = F_51 ( V_49 , V_1 -> V_57 ,
V_1 -> V_58 ?
V_111 :
V_112 ,
L_21 ) ;
if ( V_12 ) {
F_16 ( V_49 , L_22 ) ;
return V_12 ;
}
}
V_1 -> V_51 = F_52 ( V_49 , L_23 ) ;
if ( F_47 ( V_1 -> V_51 ) ) {
F_16 ( V_49 , L_24 ) ;
return F_48 ( V_1 -> V_51 ) ;
}
V_1 -> V_52 = F_52 ( V_49 , L_25 ) ;
if ( F_47 ( V_1 -> V_52 ) ) {
F_16 ( V_49 , L_26 ) ;
return F_48 ( V_1 -> V_52 ) ;
}
V_1 -> V_54 = F_52 ( V_49 , L_27 ) ;
if ( F_47 ( V_1 -> V_54 ) ) {
F_16 ( V_49 , L_28 ) ;
return F_48 ( V_1 -> V_54 ) ;
}
if ( V_1 -> V_31 == V_32 ) {
V_1 -> V_50 = F_52 ( V_49 ,
L_29 ) ;
if ( F_47 ( V_1 -> V_50 ) ) {
F_16 ( V_49 ,
L_30 ) ;
return F_48 ( V_1 -> V_50 ) ;
}
}
V_1 -> V_33 =
F_53 ( L_31 ) ;
if ( F_47 ( V_1 -> V_33 ) ) {
F_16 ( V_49 , L_32 ) ;
return F_48 ( V_1 -> V_33 ) ;
}
if ( F_54 ( V_104 , L_33 ,
& V_1 -> V_66 ) )
V_1 -> V_66 = 0 ;
if ( F_54 ( V_104 , L_34 ,
& V_1 -> V_68 ) )
V_1 -> V_68 = 0 ;
if ( F_54 ( V_104 , L_35 ,
& V_1 -> V_70 ) )
V_1 -> V_70 = 20 ;
if ( F_54 ( V_104 , L_36 ,
& V_1 -> V_72 ) )
V_1 -> V_72 = 127 ;
if ( F_54 ( V_104 , L_37 ,
& V_1 -> V_74 ) )
V_1 -> V_74 = 127 ;
V_12 = F_54 ( V_104 , L_38 ,
& V_1 -> V_87 ) ;
if ( V_12 )
V_1 -> V_87 = 1 ;
V_12 = F_37 ( V_1 , V_93 ) ;
if ( V_12 < 0 )
return V_12 ;
F_55 ( V_93 , V_1 ) ;
return 0 ;
}
static void F_56 ( struct V_92 * V_93 )
{
struct V_1 * V_1 = F_57 ( V_93 ) ;
F_11 ( V_1 ) ;
}
static int T_3 F_58 ( void )
{
return F_59 ( & V_113 , F_41 ) ;
}
