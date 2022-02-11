static int F_1 ( void T_1 * V_1 , int V_2 )
{
T_2 V_3 ;
T_2 V_4 = 10 ;
T_2 V_5 = 0 ;
do {
V_3 = F_2 ( V_1 + V_6 ) ;
V_3 = ( V_3 >> V_7 ) & 0x1 ;
V_5 ++ ;
if ( V_3 == V_2 )
return 0 ;
F_3 ( 1 ) ;
} while ( V_5 < V_4 );
return - V_8 ;
}
static int F_4 ( void T_1 * V_1 , int V_9 )
{
T_2 V_3 ;
int V_10 ;
V_3 = V_9 << V_11 ;
F_5 ( V_3 , V_1 + V_12 ) ;
V_3 |= ( 0x1 << V_13 ) ;
F_5 ( V_3 , V_1 + V_12 ) ;
V_10 = F_1 ( V_1 , 1 ) ;
if ( V_10 )
return V_10 ;
V_3 = V_9 << V_11 ;
F_5 ( V_3 , V_1 + V_12 ) ;
return F_1 ( V_1 , 0 ) ;
}
static int F_6 ( void T_1 * V_1 , int V_9 , int * V_14 )
{
T_2 V_3 , V_15 ;
int V_10 ;
V_10 = F_4 ( V_1 , V_9 ) ;
if ( V_10 )
return V_10 ;
V_15 = 0x1 << V_16 ;
F_5 ( V_15 , V_1 + V_12 ) ;
V_10 = F_1 ( V_1 , 1 ) ;
if ( V_10 )
return V_10 ;
V_3 = F_2 ( V_1 + V_6 ) ;
* V_14 = V_3 & 0xffff ;
F_5 ( 0x00 , V_1 + V_12 ) ;
return F_1 ( V_1 , 0 ) ;
}
static int F_7 ( void T_1 * V_1 , int V_9 , int V_14 )
{
T_2 V_17 ;
int V_10 ;
V_10 = F_4 ( V_1 , V_9 ) ;
if ( V_10 )
return V_10 ;
V_17 = V_14 << V_11 ;
F_5 ( V_17 , V_1 + V_12 ) ;
V_17 |= ( 0x1 << V_18 ) ;
F_5 ( V_17 , V_1 + V_12 ) ;
V_10 = F_1 ( V_1 , 1 ) ;
if ( V_10 )
return V_10 ;
V_17 = V_14 << V_11 ;
F_5 ( V_17 , V_1 + V_12 ) ;
V_10 = F_1 ( V_1 , 0 ) ;
if ( V_10 )
return V_10 ;
V_17 = 0x1 << V_19 ;
F_5 ( V_17 , V_1 + V_12 ) ;
V_10 = F_1 ( V_1 , 1 ) ;
if ( V_10 )
return V_10 ;
V_17 = V_14 << V_11 ;
F_5 ( V_17 , V_1 + V_12 ) ;
V_10 = F_1 ( V_1 , 0 ) ;
if ( V_10 )
return V_10 ;
F_5 ( 0x0 , V_1 + V_12 ) ;
return 0 ;
}
static int F_8 ( unsigned long V_9 ,
unsigned int V_20 , struct V_21 * V_22 )
{
return 0 ;
}
static int F_9 ( struct V_23 * V_24 )
{
struct V_25 * V_25 = F_10 ( V_24 ) ;
T_2 V_3 , V_26 , V_27 ;
F_11 ( V_25 -> V_28 , V_29 , & V_26 ) ;
F_11 ( V_25 -> V_28 , V_30 , & V_27 ) ;
if ( ( V_26 & V_31 ) &&
( V_27 & V_32 ) ) {
V_3 = F_2 ( V_24 -> V_1 + V_33 ) ;
V_3 &= ~ V_34 ;
V_3 |= V_35 ;
F_5 ( V_3 , V_24 -> V_1 + V_33 ) ;
F_12 ( V_25 -> V_28 , V_30 ,
V_32 , 0 << 10 ) ;
}
F_12 ( V_25 -> V_28 , V_29 ,
V_36 , 1 << 18 ) ;
F_12 ( V_25 -> V_28 , V_29 ,
V_31 , 0 << 16 ) ;
return 0 ;
}
static int F_13 ( struct V_23 * V_24 )
{
struct V_25 * V_25 = F_10 ( V_24 ) ;
int V_10 ;
V_10 = F_14 ( V_25 -> V_37 ) ;
if ( V_10 ) {
F_15 ( V_24 -> V_38 , L_1 ) ;
goto V_39;
}
V_10 = F_14 ( V_25 -> V_40 ) ;
if ( V_10 ) {
F_15 ( V_24 -> V_38 , L_2 ) ;
goto V_41;
}
V_10 = F_14 ( V_25 -> V_42 ) ;
if ( V_10 ) {
F_15 ( V_24 -> V_38 , L_3 ) ;
goto V_43;
}
F_12 ( V_25 -> V_28 , V_29 ,
V_36 , 0 << 18 ) ;
F_3 ( 10 ) ;
F_12 ( V_25 -> V_28 , V_29 ,
V_31 , 1 << 16 ) ;
F_16 ( 200 , 500 ) ;
if ( F_17 ( V_25 -> V_44 ) ) {
F_18 ( V_25 -> V_44 , 0 ) ;
F_19 ( 100 ) ;
F_18 ( V_25 -> V_44 , 1 ) ;
}
return 0 ;
V_43:
F_20 ( V_25 -> V_40 ) ;
V_41:
F_20 ( V_25 -> V_37 ) ;
V_39:
return V_10 ;
}
static void F_21 ( struct V_23 * V_24 )
{
struct V_25 * V_25 = F_10 ( V_24 ) ;
F_12 ( V_25 -> V_28 , V_30 ,
V_32 , 0 << 10 ) ;
F_12 ( V_25 -> V_28 , V_30 ,
V_45 , V_46 << 12 ) ;
F_12 ( V_25 -> V_28 , V_30 ,
V_47 , 9 << 4 ) ;
F_12 ( V_25 -> V_28 , V_48 ,
V_49 , 0 << 0 ) ;
F_12 ( V_25 -> V_28 , V_48 ,
V_50 , 0 << 6 ) ;
F_12 ( V_25 -> V_28 , V_48 ,
V_51 , 20 << 12 ) ;
F_12 ( V_25 -> V_28 , V_48 ,
V_52 , 127 << 18 ) ;
F_12 ( V_25 -> V_28 , V_48 ,
V_53 , 127 << 25 ) ;
}
static int F_22 ( struct V_23 * V_24 )
{
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < 200 ; V_54 ++ ) {
if ( F_23 ( V_24 ) )
return 0 ;
F_16 ( 100 , 1000 ) ;
}
F_15 ( V_24 -> V_38 , L_4 ) ;
F_24 ( V_24 -> V_38 , L_5 ,
F_2 ( V_24 -> V_1 + V_55 ) ,
F_2 ( V_24 -> V_1 + V_56 ) ) ;
return - V_57 ;
}
static int F_25 ( struct V_23 * V_24 )
{
T_2 V_58 ;
unsigned int V_54 ;
for ( V_54 = 0 ; V_54 < 200 ; V_54 ++ ) {
V_58 = F_2 ( V_24 -> V_1 + V_59 ) ;
if ( ! ( V_58 & V_60 ) )
return 0 ;
F_16 ( 100 , 1000 ) ;
}
F_15 ( V_24 -> V_38 , L_6 ) ;
return - V_57 ;
}
static T_3 F_26 ( int V_61 , void * V_62 )
{
struct V_23 * V_24 = V_62 ;
return F_27 ( V_24 ) ;
}
static int F_28 ( struct V_23 * V_24 )
{
struct V_25 * V_25 = F_10 ( V_24 ) ;
T_2 V_58 ;
int V_10 ;
V_58 = F_2 ( V_24 -> V_1 + V_63 ) ;
V_58 &= ~ V_64 ;
V_58 |= V_65 ;
F_5 ( V_58 , V_24 -> V_1 + V_63 ) ;
F_12 ( V_25 -> V_28 , V_30 ,
V_32 , 1 << 10 ) ;
V_10 = F_22 ( V_24 ) ;
if ( V_10 )
return V_10 ;
V_58 = F_2 ( V_24 -> V_1 + V_63 ) ;
V_58 &= ~ V_64 ;
V_58 |= V_66 ;
F_5 ( V_58 , V_24 -> V_1 + V_63 ) ;
V_58 = F_2 ( V_24 -> V_1 + V_59 ) ;
V_58 |= V_60 ;
F_5 ( V_58 , V_24 -> V_1 + V_59 ) ;
V_10 = F_25 ( V_24 ) ;
if ( V_10 ) {
F_15 ( V_24 -> V_38 , L_7 ) ;
return V_10 ;
}
V_10 = F_22 ( V_24 ) ;
if ( V_10 ) {
F_15 ( V_24 -> V_38 , L_7 ) ;
return V_10 ;
}
V_58 = F_2 ( V_24 -> V_1 + V_67 ) ;
F_24 ( V_24 -> V_38 , L_8 , ( V_58 >> 16 ) & 0xf ) ;
return 0 ;
}
static void F_29 ( struct V_23 * V_24 )
{
F_9 ( V_24 ) ;
F_21 ( V_24 ) ;
F_13 ( V_24 ) ;
F_30 ( V_24 ) ;
F_28 ( V_24 ) ;
if ( F_31 ( V_68 ) )
F_32 ( V_24 ) ;
}
static void F_33 ( struct V_23 * V_24 )
{
T_2 V_58 ;
F_6 ( V_24 -> V_1 , V_69 , & V_58 ) ;
V_58 |= ( V_70 |
V_71 ) ;
F_7 ( V_24 -> V_1 , V_69 , V_58 ) ;
F_16 ( 2000 , 3000 ) ;
F_6 ( V_24 -> V_1 , V_69 , & V_58 ) ;
V_58 &= ~ ( V_70 |
V_71 ) ;
F_7 ( V_24 -> V_1 , V_69 , V_58 ) ;
}
static int F_34 ( struct V_23 * V_24 )
{
T_2 V_72 , V_73 , V_74 ;
int V_75 = 5 ;
while ( 1 ) {
V_72 = F_2 ( V_24 -> V_1 + V_56 ) ;
if ( ! ( V_72 & V_76 ) )
break;
if ( ! ( V_72 & V_77 ) )
return 1 ;
if ( ! V_75 -- )
break;
F_24 ( V_24 -> V_38 , L_9 ) ;
F_16 ( 1000 , 2000 ) ;
}
F_6 ( V_24 -> V_1 , V_78 , & V_74 ) ;
V_73 = F_2 ( V_24 -> V_1 + V_55 ) ;
if ( V_74 & 0x01 )
return 0 ;
if ( ( V_73 & 0x3f ) != 0x0d )
return 0 ;
F_15 ( V_24 -> V_38 , L_10 ) ;
F_24 ( V_24 -> V_38 , L_11 , V_73 , V_72 ) ;
F_33 ( V_24 ) ;
return 0 ;
}
static int T_4 F_35 ( struct V_23 * V_24 ,
struct V_79 * V_80 )
{
int V_10 ;
if ( F_31 ( V_68 ) ) {
V_24 -> V_81 = F_36 ( V_80 , L_12 ) ;
if ( V_24 -> V_81 <= 0 ) {
F_15 ( & V_80 -> V_38 , L_13 ) ;
return - V_82 ;
}
V_10 = F_37 ( & V_80 -> V_38 , V_24 -> V_81 ,
F_26 ,
V_83 , L_14 , V_24 ) ;
if ( V_10 ) {
F_15 ( & V_80 -> V_38 , L_15 ) ;
return - V_82 ;
}
}
V_24 -> V_84 = - 1 ;
V_24 -> V_85 = & V_86 ;
V_10 = F_38 ( V_24 ) ;
if ( V_10 ) {
F_15 ( & V_80 -> V_38 , L_16 ) ;
return V_10 ;
}
return 0 ;
}
static int T_4 F_39 ( struct V_79 * V_80 )
{
struct V_25 * V_25 ;
struct V_23 * V_24 ;
struct V_87 * V_88 = V_80 -> V_38 . V_89 ;
struct V_90 * V_1 ;
int V_10 ;
V_25 = F_40 ( & V_80 -> V_38 , sizeof( * V_25 ) , V_91 ) ;
if ( ! V_25 )
return - V_92 ;
V_24 = & V_25 -> V_24 ;
V_24 -> V_38 = & V_80 -> V_38 ;
F_41 ( 16 + 6 , F_8 , V_93 , 0 ,
L_17 ) ;
V_1 = F_42 ( V_80 , V_94 , 0 ) ;
V_24 -> V_1 = F_43 ( & V_80 -> V_38 , V_1 ) ;
if ( F_44 ( V_24 -> V_1 ) )
return F_45 ( V_24 -> V_1 ) ;
V_25 -> V_44 = F_46 ( V_88 , L_18 , 0 ) ;
if ( F_17 ( V_25 -> V_44 ) ) {
V_10 = F_47 ( & V_80 -> V_38 , V_25 -> V_44 ,
V_95 , L_19 ) ;
if ( V_10 ) {
F_15 ( & V_80 -> V_38 , L_20 ) ;
return V_10 ;
}
}
V_25 -> V_37 = F_48 ( & V_80 -> V_38 , L_21 ) ;
if ( F_44 ( V_25 -> V_37 ) ) {
F_15 ( & V_80 -> V_38 ,
L_22 ) ;
return F_45 ( V_25 -> V_37 ) ;
}
V_25 -> V_40 = F_48 ( & V_80 -> V_38 , L_23 ) ;
if ( F_44 ( V_25 -> V_40 ) ) {
F_15 ( & V_80 -> V_38 ,
L_24 ) ;
return F_45 ( V_25 -> V_40 ) ;
}
V_25 -> V_42 = F_48 ( & V_80 -> V_38 , L_25 ) ;
if ( F_44 ( V_25 -> V_42 ) ) {
F_15 ( & V_80 -> V_38 ,
L_26 ) ;
return F_45 ( V_25 -> V_42 ) ;
}
V_25 -> V_28 =
F_49 ( L_27 ) ;
if ( F_44 ( V_25 -> V_28 ) ) {
F_15 ( & V_80 -> V_38 , L_28 ) ;
return F_45 ( V_25 -> V_28 ) ;
}
V_10 = F_35 ( V_24 , V_80 ) ;
if ( V_10 < 0 )
return V_10 ;
F_50 ( V_80 , V_25 ) ;
return 0 ;
}
static void F_51 ( struct V_79 * V_80 )
{
struct V_25 * V_25 = F_52 ( V_80 ) ;
F_9 ( & V_25 -> V_24 ) ;
}
static int T_4 F_53 ( void )
{
return F_54 ( & V_96 , F_39 ) ;
}
