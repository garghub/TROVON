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
V_10 = F_1 ( V_1 , 0 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
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
V_10 = F_1 ( V_1 , 0 ) ;
if ( V_10 )
return V_10 ;
return 0 ;
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
F_11 ( V_25 -> V_26 , V_27 ,
V_28 , 1 << 18 ) ;
F_11 ( V_25 -> V_26 , V_27 ,
V_29 , 0 << 16 ) ;
return 0 ;
}
static int F_12 ( struct V_23 * V_24 )
{
struct V_25 * V_25 = F_10 ( V_24 ) ;
int V_10 ;
F_11 ( V_25 -> V_26 , V_27 ,
V_28 , 0 << 18 ) ;
F_11 ( V_25 -> V_26 , V_27 ,
V_29 , 1 << 16 ) ;
V_10 = F_13 ( V_25 -> V_30 ) ;
if ( V_10 ) {
F_14 ( V_24 -> V_31 , L_1 ) ;
goto V_32;
}
V_10 = F_13 ( V_25 -> V_33 ) ;
if ( V_10 ) {
F_14 ( V_24 -> V_31 , L_2 ) ;
goto V_34;
}
V_10 = F_13 ( V_25 -> V_35 ) ;
if ( V_10 ) {
F_14 ( V_24 -> V_31 , L_3 ) ;
goto V_36;
}
F_15 ( 200 , 500 ) ;
if ( F_16 ( V_25 -> V_37 ) ) {
F_17 ( V_25 -> V_37 , 0 ) ;
F_18 ( 100 ) ;
F_17 ( V_25 -> V_37 , 1 ) ;
}
return 0 ;
V_36:
F_19 ( V_25 -> V_33 ) ;
V_34:
F_19 ( V_25 -> V_30 ) ;
V_32:
return V_10 ;
}
static void F_20 ( struct V_23 * V_24 )
{
struct V_25 * V_25 = F_10 ( V_24 ) ;
F_11 ( V_25 -> V_26 , V_38 ,
V_39 , 0 << 10 ) ;
F_11 ( V_25 -> V_26 , V_38 ,
V_40 , V_41 << 12 ) ;
F_11 ( V_25 -> V_26 , V_38 ,
V_42 , 9 << 4 ) ;
F_11 ( V_25 -> V_26 , V_43 ,
V_44 , 0 << 0 ) ;
F_11 ( V_25 -> V_26 , V_43 ,
V_45 , 0 << 6 ) ;
F_11 ( V_25 -> V_26 , V_43 ,
V_46 , 20 << 12 ) ;
F_11 ( V_25 -> V_26 , V_43 ,
V_47 , 127 << 18 ) ;
F_11 ( V_25 -> V_26 , V_43 ,
V_48 , 127 << 25 ) ;
}
static int F_21 ( struct V_23 * V_24 )
{
int V_49 = 200 ;
while ( ! F_22 ( V_24 ) ) {
F_15 ( 100 , 1000 ) ;
if ( -- V_49 )
continue;
F_14 ( V_24 -> V_31 , L_4 ) ;
F_23 ( V_24 -> V_31 , L_5 ,
F_2 ( V_24 -> V_1 + V_50 ) ,
F_2 ( V_24 -> V_1 + V_51 ) ) ;
return - V_52 ;
}
return 0 ;
}
static T_3 F_24 ( int V_53 , void * V_54 )
{
struct V_23 * V_24 = V_54 ;
return F_25 ( V_24 ) ;
}
static int F_26 ( struct V_23 * V_24 )
{
struct V_25 * V_25 = F_10 ( V_24 ) ;
T_4 V_55 ;
int V_10 , V_49 ;
V_55 = F_2 ( V_24 -> V_1 + V_56 ) ;
V_55 &= ~ V_57 ;
V_55 |= V_58 ;
F_5 ( V_55 , V_24 -> V_1 + V_56 ) ;
F_11 ( V_25 -> V_26 , V_38 ,
V_39 , 1 << 10 ) ;
V_10 = F_21 ( V_24 ) ;
if ( V_10 )
return V_10 ;
V_55 = F_2 ( V_24 -> V_1 + V_56 ) ;
V_55 &= ~ V_57 ;
V_55 |= V_59 ;
F_5 ( V_55 , V_24 -> V_1 + V_56 ) ;
V_55 = F_2 ( V_24 -> V_1 + V_60 ) ;
V_55 |= V_61 ;
F_5 ( V_55 , V_24 -> V_1 + V_60 ) ;
V_49 = 200 ;
while ( V_49 -- ) {
V_55 = F_2 ( V_24 -> V_1 + V_60 ) ;
if ( ! ( V_55 & V_61 ) )
break;
F_15 ( 100 , 1000 ) ;
}
if ( V_49 )
V_10 = F_21 ( V_24 ) ;
else
V_10 = - V_52 ;
if ( V_10 ) {
F_14 ( V_24 -> V_31 , L_6 ) ;
} else {
V_55 = F_2 ( V_24 -> V_1 + 0x80 ) ;
F_23 ( V_24 -> V_31 , L_7 , ( V_55 >> 16 ) & 0xf ) ;
}
return V_10 ;
}
static void F_27 ( struct V_23 * V_24 )
{
F_9 ( V_24 ) ;
F_20 ( V_24 ) ;
F_12 ( V_24 ) ;
F_28 ( V_24 ) ;
F_26 ( V_24 ) ;
if ( F_29 ( V_62 ) )
F_30 ( V_24 ) ;
}
static void F_31 ( struct V_23 * V_24 )
{
T_4 V_63 ;
F_6 ( V_24 -> V_1 , V_64 , & V_63 ) ;
V_63 |= ( V_65 |
V_66 ) ;
F_7 ( V_24 -> V_1 , V_64 , V_63 ) ;
F_15 ( 2000 , 3000 ) ;
F_6 ( V_24 -> V_1 , V_64 , & V_63 ) ;
V_63 &= ~ ( V_65 |
V_66 ) ;
F_7 ( V_24 -> V_1 , V_64 , V_63 ) ;
}
static int F_32 ( struct V_23 * V_24 )
{
T_2 V_67 , V_68 , V_69 ;
int V_49 = 5 ;
while ( 1 ) {
V_67 = F_2 ( V_24 -> V_1 + V_51 ) ;
if ( ! ( V_67 & V_70 ) )
break;
if ( ! ( V_67 & V_71 ) )
return 1 ;
if ( ! V_49 -- )
break;
F_23 ( V_24 -> V_31 , L_8 ) ;
F_15 ( 1000 , 2000 ) ;
}
F_6 ( V_24 -> V_1 , V_72 , & V_69 ) ;
V_68 = F_2 ( V_24 -> V_1 + V_50 ) ;
if ( V_69 & 0x01 )
return 0 ;
if ( ( V_68 & 0x3f ) != 0x0d )
return 0 ;
F_14 ( V_24 -> V_31 , L_9 ) ;
F_23 ( V_24 -> V_31 , L_10 , V_68 , V_67 ) ;
F_31 ( V_24 ) ;
return 0 ;
}
static int T_5 F_33 ( struct V_23 * V_24 ,
struct V_73 * V_74 )
{
int V_10 ;
if ( F_29 ( V_62 ) ) {
V_24 -> V_75 = F_34 ( V_74 , L_11 ) ;
if ( V_24 -> V_75 <= 0 ) {
F_14 ( & V_74 -> V_31 , L_12 ) ;
return - V_76 ;
}
V_10 = F_35 ( & V_74 -> V_31 , V_24 -> V_75 ,
F_24 ,
V_77 , L_13 , V_24 ) ;
if ( V_10 ) {
F_14 ( & V_74 -> V_31 , L_14 ) ;
return - V_76 ;
}
}
V_24 -> V_78 = - 1 ;
V_24 -> V_79 = & V_80 ;
V_10 = F_36 ( V_24 ) ;
if ( V_10 ) {
F_14 ( & V_74 -> V_31 , L_15 ) ;
return V_10 ;
}
return 0 ;
}
static int T_5 F_37 ( struct V_73 * V_74 )
{
struct V_25 * V_25 ;
struct V_23 * V_24 ;
struct V_81 * V_82 = V_74 -> V_31 . V_83 ;
struct V_84 * V_1 ;
int V_10 ;
V_25 = F_38 ( & V_74 -> V_31 , sizeof( * V_25 ) , V_85 ) ;
if ( ! V_25 )
return - V_86 ;
V_24 = & V_25 -> V_24 ;
V_24 -> V_31 = & V_74 -> V_31 ;
F_39 ( 16 + 6 , F_8 , V_87 , 0 ,
L_16 ) ;
V_1 = F_40 ( V_74 , V_88 , 0 ) ;
V_24 -> V_1 = F_41 ( & V_74 -> V_31 , V_1 ) ;
if ( F_42 ( V_24 -> V_1 ) )
return F_43 ( V_24 -> V_1 ) ;
V_25 -> V_37 = F_44 ( V_82 , L_17 , 0 ) ;
if ( F_16 ( V_25 -> V_37 ) ) {
V_10 = F_45 ( & V_74 -> V_31 , V_25 -> V_37 ,
V_89 , L_18 ) ;
if ( V_10 ) {
F_14 ( & V_74 -> V_31 , L_19 ) ;
return V_10 ;
}
}
V_25 -> V_30 = F_46 ( & V_74 -> V_31 , L_20 ) ;
if ( F_42 ( V_25 -> V_30 ) ) {
F_14 ( & V_74 -> V_31 ,
L_21 ) ;
return F_43 ( V_25 -> V_30 ) ;
}
V_25 -> V_33 = F_46 ( & V_74 -> V_31 , L_22 ) ;
if ( F_42 ( V_25 -> V_33 ) ) {
F_14 ( & V_74 -> V_31 ,
L_23 ) ;
return F_43 ( V_25 -> V_33 ) ;
}
V_25 -> V_35 = F_46 ( & V_74 -> V_31 , L_24 ) ;
if ( F_42 ( V_25 -> V_35 ) ) {
F_14 ( & V_74 -> V_31 ,
L_25 ) ;
return F_43 ( V_25 -> V_35 ) ;
}
V_25 -> V_26 =
F_47 ( L_26 ) ;
if ( F_42 ( V_25 -> V_26 ) ) {
F_14 ( & V_74 -> V_31 , L_27 ) ;
return F_43 ( V_25 -> V_26 ) ;
}
V_10 = F_33 ( V_24 , V_74 ) ;
if ( V_10 < 0 )
return V_10 ;
F_48 ( V_74 , V_25 ) ;
return 0 ;
}
static int T_5 F_49 ( void )
{
return F_50 ( & V_90 , F_37 ) ;
}
