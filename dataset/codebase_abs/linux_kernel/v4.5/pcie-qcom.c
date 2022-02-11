static void F_1 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , 1 ) ;
F_3 ( V_4 , V_4 + 500 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( V_2 -> V_3 , 0 ) ;
F_3 ( V_4 , V_4 + 500 ) ;
}
static T_1 F_5 ( int V_5 , void * V_6 )
{
struct V_7 * V_8 = V_6 ;
return F_6 ( V_8 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = V_2 -> V_10 ;
unsigned int V_11 = 0 ;
T_2 V_12 ;
if ( F_8 ( & V_2 -> V_8 ) )
return 0 ;
V_12 = F_9 ( V_2 -> V_13 + V_14 ) ;
V_12 |= V_15 ;
F_10 ( V_12 , V_2 -> V_13 + V_14 ) ;
do {
if ( F_8 ( & V_2 -> V_8 ) )
return 0 ;
F_3 ( 250 , 1000 ) ;
} while ( V_11 < 200 );
F_11 ( V_10 , L_1 ) ;
return - V_16 ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_18 . V_19 ;
struct V_9 * V_10 = V_2 -> V_10 ;
V_18 -> V_20 = F_13 ( V_10 , L_2 ) ;
if ( F_14 ( V_18 -> V_20 ) )
return F_15 ( V_18 -> V_20 ) ;
V_18 -> V_21 = F_13 ( V_10 , L_3 ) ;
if ( F_14 ( V_18 -> V_21 ) )
return F_15 ( V_18 -> V_21 ) ;
V_18 -> V_22 = F_13 ( V_10 , L_4 ) ;
if ( F_14 ( V_18 -> V_22 ) )
return F_15 ( V_18 -> V_22 ) ;
V_18 -> V_23 = F_16 ( V_10 , L_5 ) ;
if ( F_14 ( V_18 -> V_23 ) )
return F_15 ( V_18 -> V_23 ) ;
V_18 -> V_24 = F_16 ( V_10 , L_6 ) ;
if ( F_14 ( V_18 -> V_24 ) )
return F_15 ( V_18 -> V_24 ) ;
V_18 -> V_25 = F_16 ( V_10 , L_7 ) ;
if ( F_14 ( V_18 -> V_25 ) )
return F_15 ( V_18 -> V_25 ) ;
V_18 -> V_26 = F_17 ( V_10 , L_8 ) ;
if ( F_14 ( V_18 -> V_26 ) )
return F_15 ( V_18 -> V_26 ) ;
V_18 -> V_27 = F_17 ( V_10 , L_9 ) ;
if ( F_14 ( V_18 -> V_27 ) )
return F_15 ( V_18 -> V_27 ) ;
V_18 -> V_28 = F_17 ( V_10 , L_10 ) ;
if ( F_14 ( V_18 -> V_28 ) )
return F_15 ( V_18 -> V_28 ) ;
V_18 -> V_29 = F_17 ( V_10 , L_11 ) ;
if ( F_14 ( V_18 -> V_29 ) )
return F_15 ( V_18 -> V_29 ) ;
V_18 -> V_30 = F_17 ( V_10 , L_7 ) ;
if ( F_14 ( V_18 -> V_30 ) )
return F_15 ( V_18 -> V_30 ) ;
return 0 ;
}
static int F_18 ( struct V_1 * V_2 )
{
struct V_31 * V_18 = & V_2 -> V_18 . V_32 ;
struct V_9 * V_10 = V_2 -> V_10 ;
V_18 -> V_20 = F_13 ( V_10 , L_2 ) ;
if ( F_14 ( V_18 -> V_20 ) )
return F_15 ( V_18 -> V_20 ) ;
V_18 -> V_33 = F_16 ( V_10 , L_5 ) ;
if ( F_14 ( V_18 -> V_33 ) )
return F_15 ( V_18 -> V_33 ) ;
V_18 -> V_34 = F_16 ( V_10 , L_12 ) ;
if ( F_14 ( V_18 -> V_34 ) )
return F_15 ( V_18 -> V_34 ) ;
V_18 -> V_35 = F_16 ( V_10 , L_13 ) ;
if ( F_14 ( V_18 -> V_35 ) )
return F_15 ( V_18 -> V_35 ) ;
V_18 -> V_36 = F_16 ( V_10 , L_14 ) ;
if ( F_14 ( V_18 -> V_36 ) )
return F_15 ( V_18 -> V_36 ) ;
V_18 -> V_37 = F_17 ( V_10 , L_6 ) ;
if ( F_14 ( V_18 -> V_37 ) )
return F_15 ( V_18 -> V_37 ) ;
return 0 ;
}
static void F_19 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_18 . V_19 ;
F_20 ( V_18 -> V_26 ) ;
F_20 ( V_18 -> V_27 ) ;
F_20 ( V_18 -> V_28 ) ;
F_20 ( V_18 -> V_29 ) ;
F_20 ( V_18 -> V_26 ) ;
F_21 ( V_18 -> V_23 ) ;
F_21 ( V_18 -> V_24 ) ;
F_21 ( V_18 -> V_25 ) ;
F_22 ( V_18 -> V_20 ) ;
F_22 ( V_18 -> V_21 ) ;
F_22 ( V_18 -> V_22 ) ;
}
static int F_23 ( struct V_1 * V_2 )
{
struct V_17 * V_18 = & V_2 -> V_18 . V_19 ;
struct V_9 * V_10 = V_2 -> V_10 ;
T_2 V_12 ;
int V_38 ;
V_38 = F_24 ( V_18 -> V_20 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_15 ) ;
return V_38 ;
}
V_38 = F_24 ( V_18 -> V_22 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_16 ) ;
goto V_39;
}
V_38 = F_24 ( V_18 -> V_21 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_17 ) ;
goto V_40;
}
V_38 = F_20 ( V_18 -> V_28 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_18 ) ;
goto V_41;
}
V_38 = F_26 ( V_18 -> V_23 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_19 ) ;
goto V_41;
}
V_38 = F_26 ( V_18 -> V_25 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_20 ) ;
goto V_42;
}
V_38 = F_26 ( V_18 -> V_24 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_21 ) ;
goto V_43;
}
V_38 = F_27 ( V_18 -> V_28 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_22 ) ;
goto V_44;
}
V_12 = F_9 ( V_2 -> V_45 + V_46 ) ;
V_12 &= ~ F_28 ( 0 ) ;
F_10 ( V_12 , V_2 -> V_45 + V_46 ) ;
V_12 = F_9 ( V_2 -> V_45 + V_47 ) ;
V_12 |= F_28 ( 16 ) ;
F_10 ( V_12 , V_2 -> V_45 + V_47 ) ;
V_38 = F_27 ( V_18 -> V_30 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_23 ) ;
return V_38 ;
}
V_38 = F_27 ( V_18 -> V_26 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_24 ) ;
return V_38 ;
}
V_38 = F_27 ( V_18 -> V_29 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_25 ) ;
return V_38 ;
}
V_38 = F_27 ( V_18 -> V_27 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_26 ) ;
return V_38 ;
}
F_3 ( 1000 , 1500 ) ;
return 0 ;
V_44:
F_21 ( V_18 -> V_24 ) ;
V_43:
F_21 ( V_18 -> V_25 ) ;
V_42:
F_21 ( V_18 -> V_23 ) ;
V_41:
F_22 ( V_18 -> V_21 ) ;
V_40:
F_22 ( V_18 -> V_22 ) ;
V_39:
F_22 ( V_18 -> V_20 ) ;
return V_38 ;
}
static void F_29 ( struct V_1 * V_2 )
{
struct V_31 * V_18 = & V_2 -> V_18 . V_32 ;
F_20 ( V_18 -> V_37 ) ;
F_21 ( V_18 -> V_36 ) ;
F_21 ( V_18 -> V_35 ) ;
F_21 ( V_18 -> V_33 ) ;
F_21 ( V_18 -> V_34 ) ;
F_22 ( V_18 -> V_20 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
struct V_31 * V_18 = & V_2 -> V_18 . V_32 ;
struct V_9 * V_10 = V_2 -> V_10 ;
int V_38 ;
V_38 = F_27 ( V_18 -> V_37 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_27 ) ;
return V_38 ;
}
V_38 = F_26 ( V_18 -> V_34 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_28 ) ;
goto V_48;
}
V_38 = F_26 ( V_18 -> V_33 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_19 ) ;
goto V_49;
}
V_38 = F_26 ( V_18 -> V_35 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_29 ) ;
goto V_50;
}
V_38 = F_26 ( V_18 -> V_36 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_30 ) ;
goto V_51;
}
V_38 = F_24 ( V_18 -> V_20 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_15 ) ;
goto V_52;
}
F_10 ( 0 , V_2 -> V_45 + V_53 ) ;
if ( F_31 ( V_54 ) ) {
T_2 V_12 = F_9 ( V_2 -> V_45 + V_55 ) ;
V_12 |= F_28 ( 31 ) ;
F_10 ( V_12 , V_2 -> V_45 + V_55 ) ;
}
return 0 ;
V_52:
F_21 ( V_18 -> V_36 ) ;
V_51:
F_21 ( V_18 -> V_35 ) ;
V_50:
F_21 ( V_18 -> V_33 ) ;
V_49:
F_21 ( V_18 -> V_34 ) ;
V_48:
F_20 ( V_18 -> V_37 ) ;
return V_38 ;
}
static int F_32 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_33 ( V_8 ) ;
T_3 V_12 = F_34 ( V_2 -> V_56 + V_57 + V_58 ) ;
return ! ! ( V_12 & V_59 ) ;
}
static void F_35 ( struct V_7 * V_8 )
{
struct V_1 * V_2 = F_33 ( V_8 ) ;
int V_38 ;
F_1 ( V_2 ) ;
V_38 = V_2 -> V_60 -> V_61 ( V_2 ) ;
if ( V_38 )
goto V_62;
V_38 = F_36 ( V_2 -> V_63 ) ;
if ( V_38 )
goto V_62;
F_37 ( V_8 ) ;
if ( F_31 ( V_54 ) )
F_38 ( V_8 ) ;
F_4 ( V_2 ) ;
V_38 = F_7 ( V_2 ) ;
if ( V_38 )
goto V_64;
return;
V_64:
F_1 ( V_2 ) ;
F_39 ( V_2 -> V_63 ) ;
V_62:
V_2 -> V_60 -> V_65 ( V_2 ) ;
}
static int F_40 ( struct V_7 * V_8 , int V_66 , int V_67 ,
T_2 * V_12 )
{
if ( V_66 == V_68 && V_67 == 4 ) {
* V_12 = F_9 ( V_8 -> V_69 + V_68 ) ;
* V_12 &= 0xff ;
* V_12 |= V_70 << 16 ;
return V_71 ;
}
return F_41 ( V_8 -> V_69 + V_66 , V_67 , V_12 ) ;
}
static int F_42 ( struct V_72 * V_73 )
{
struct V_9 * V_10 = & V_73 -> V_10 ;
struct V_74 * V_18 ;
struct V_1 * V_2 ;
struct V_7 * V_8 ;
int V_38 ;
V_2 = F_43 ( V_10 , sizeof( * V_2 ) , V_75 ) ;
if ( ! V_2 )
return - V_76 ;
V_2 -> V_60 = (struct V_77 * ) F_44 ( V_10 ) ;
V_2 -> V_10 = V_10 ;
V_2 -> V_3 = F_45 ( V_10 , L_31 , V_78 ) ;
if ( F_14 ( V_2 -> V_3 ) )
return F_15 ( V_2 -> V_3 ) ;
V_18 = F_46 ( V_73 , V_79 , L_32 ) ;
V_2 -> V_45 = F_47 ( V_10 , V_18 ) ;
if ( F_14 ( V_2 -> V_45 ) )
return F_15 ( V_2 -> V_45 ) ;
V_18 = F_46 ( V_73 , V_79 , L_33 ) ;
V_2 -> V_56 = F_47 ( V_10 , V_18 ) ;
if ( F_14 ( V_2 -> V_56 ) )
return F_15 ( V_2 -> V_56 ) ;
V_18 = F_46 ( V_73 , V_79 , L_34 ) ;
V_2 -> V_13 = F_47 ( V_10 , V_18 ) ;
if ( F_14 ( V_2 -> V_13 ) )
return F_15 ( V_2 -> V_13 ) ;
V_2 -> V_63 = F_48 ( V_10 , L_35 ) ;
if ( F_14 ( V_2 -> V_63 ) )
return F_15 ( V_2 -> V_63 ) ;
V_38 = V_2 -> V_60 -> V_80 ( V_2 ) ;
if ( V_38 )
return V_38 ;
V_8 = & V_2 -> V_8 ;
V_8 -> V_10 = V_10 ;
V_8 -> V_69 = V_2 -> V_56 ;
V_8 -> V_81 = - 1 ;
V_8 -> V_60 = & V_82 ;
if ( F_31 ( V_54 ) ) {
V_8 -> V_83 = F_49 ( V_73 , L_36 ) ;
if ( V_8 -> V_83 < 0 )
return V_8 -> V_83 ;
V_38 = F_50 ( V_10 , V_8 -> V_83 ,
F_5 ,
V_84 , L_37 , V_8 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_38 ) ;
return V_38 ;
}
}
V_38 = F_51 ( V_2 -> V_63 ) ;
if ( V_38 )
return V_38 ;
V_38 = F_52 ( V_8 ) ;
if ( V_38 ) {
F_25 ( V_10 , L_39 ) ;
return V_38 ;
}
F_53 ( V_73 , V_2 ) ;
return 0 ;
}
static int F_54 ( struct V_72 * V_73 )
{
struct V_1 * V_2 = F_55 ( V_73 ) ;
F_1 ( V_2 ) ;
F_39 ( V_2 -> V_63 ) ;
F_56 ( V_2 -> V_63 ) ;
V_2 -> V_60 -> V_65 ( V_2 ) ;
return 0 ;
}
