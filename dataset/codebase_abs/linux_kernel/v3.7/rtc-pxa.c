static T_1 F_1 ( struct V_1 * V_2 )
{
return ( ( V_2 -> V_3 + 1900 ) << V_4 )
| ( ( V_2 -> V_5 + 1 ) << V_6 )
| V_2 -> V_7 ;
}
static T_1 F_2 ( struct V_1 * V_2 )
{
return ( V_2 -> V_8 << V_9 ) | ( V_2 -> V_10 << V_11 )
| V_2 -> V_12 ;
}
static void F_3 ( T_1 V_13 , T_1 V_14 , struct V_1 * V_2 )
{
V_2 -> V_3 = ( ( V_13 & V_15 ) >> V_4 ) - 1900 ;
V_2 -> V_5 = ( ( ( V_13 & V_16 ) >> V_6 ) ) - 1 ;
V_2 -> V_7 = ( V_13 & V_17 ) ;
V_2 -> V_8 = ( V_14 & V_18 ) >> V_9 ;
V_2 -> V_10 = ( V_14 & V_19 ) >> V_11 ;
V_2 -> V_12 = V_14 & V_20 ;
}
static void F_4 ( struct V_21 * V_21 , T_1 V_22 )
{
T_1 V_23 ;
V_23 = F_5 ( V_21 , V_24 ) ;
V_23 &= ~ V_25 ;
V_23 &= ~ V_22 ;
F_6 ( V_21 , V_24 , V_23 ) ;
}
static void F_7 ( struct V_21 * V_21 , T_1 V_22 )
{
T_1 V_23 ;
V_23 = F_5 ( V_21 , V_24 ) ;
V_23 &= ~ V_25 ;
V_23 |= V_22 ;
F_6 ( V_21 , V_24 , V_23 ) ;
}
static T_2 F_8 ( int V_26 , void * V_27 )
{
struct V_28 * V_29 = F_9 ( V_27 ) ;
struct V_21 * V_21 = F_10 ( V_29 ) ;
T_1 V_23 ;
unsigned long V_30 = 0 ;
F_11 ( & V_21 -> V_31 ) ;
V_23 = F_5 ( V_21 , V_24 ) ;
F_6 ( V_21 , V_24 , V_23 ) ;
F_4 ( V_21 , V_32 | V_33 | V_34 ) ;
if ( V_23 & V_35 )
V_23 &= ~ V_32 ;
if ( V_23 & V_35 )
V_30 |= V_36 | V_37 ;
if ( V_23 & V_38 )
V_30 |= V_39 | V_37 ;
if ( V_23 & V_40 )
V_30 |= V_41 | V_37 ;
F_12 ( V_21 -> V_42 , 1 , V_30 ) ;
F_6 ( V_21 , V_24 , V_23 & ~ V_25 ) ;
F_13 ( & V_21 -> V_31 ) ;
return V_43 ;
}
static int F_14 ( struct V_44 * V_45 )
{
struct V_21 * V_21 = F_15 ( V_45 ) ;
int V_46 ;
V_46 = F_16 ( V_21 -> V_47 , F_8 , 0 ,
L_1 , V_45 ) ;
if ( V_46 < 0 ) {
F_17 ( V_45 , L_2 , V_21 -> V_47 ,
V_46 ) ;
goto V_48;
}
V_46 = F_16 ( V_21 -> V_49 , F_8 , 0 ,
L_3 , V_45 ) ;
if ( V_46 < 0 ) {
F_17 ( V_45 , L_2 , V_21 -> V_49 ,
V_46 ) ;
goto V_50;
}
return 0 ;
V_50:
F_18 ( V_21 -> V_47 , V_45 ) ;
V_48:
return V_46 ;
}
static void F_19 ( struct V_44 * V_45 )
{
struct V_21 * V_21 = F_15 ( V_45 ) ;
F_20 ( & V_21 -> V_31 ) ;
F_4 ( V_21 , V_33 | V_32 | V_34 ) ;
F_21 ( & V_21 -> V_31 ) ;
F_18 ( V_21 -> V_49 , V_45 ) ;
F_18 ( V_21 -> V_47 , V_45 ) ;
}
static int F_22 ( struct V_44 * V_45 , unsigned int V_51 )
{
struct V_21 * V_21 = F_15 ( V_45 ) ;
F_20 ( & V_21 -> V_31 ) ;
if ( V_51 )
F_7 ( V_21 , V_32 ) ;
else
F_4 ( V_21 , V_32 ) ;
F_21 ( & V_21 -> V_31 ) ;
return 0 ;
}
static int F_23 ( struct V_44 * V_45 , struct V_1 * V_2 )
{
struct V_21 * V_21 = F_15 ( V_45 ) ;
T_1 V_13 , V_14 ;
V_13 = F_5 ( V_21 , V_52 ) ;
V_14 = F_5 ( V_21 , V_53 ) ;
F_3 ( V_13 , V_14 , V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_44 * V_45 , struct V_1 * V_2 )
{
struct V_21 * V_21 = F_15 ( V_45 ) ;
F_6 ( V_21 , V_52 , F_1 ( V_2 ) ) ;
F_6 ( V_21 , V_53 , F_2 ( V_2 ) ) ;
return 0 ;
}
static int F_25 ( struct V_44 * V_45 , struct V_54 * V_55 )
{
struct V_21 * V_21 = F_15 ( V_45 ) ;
T_1 V_23 , V_56 , V_57 ;
V_56 = F_5 ( V_21 , V_58 ) ;
V_57 = F_5 ( V_21 , V_59 ) ;
F_3 ( V_56 , V_57 , & V_55 -> time ) ;
V_23 = F_5 ( V_21 , V_24 ) ;
V_55 -> V_51 = ( V_23 & V_32 ) ? 1 : 0 ;
V_55 -> V_60 = ( V_23 & V_35 ) ? 1 : 0 ;
return 0 ;
}
static int F_26 ( struct V_44 * V_45 , struct V_54 * V_55 )
{
struct V_21 * V_21 = F_15 ( V_45 ) ;
T_1 V_23 ;
F_20 ( & V_21 -> V_31 ) ;
F_6 ( V_21 , V_58 , F_1 ( & V_55 -> time ) ) ;
F_6 ( V_21 , V_59 , F_2 ( & V_55 -> time ) ) ;
V_23 = F_5 ( V_21 , V_24 ) ;
if ( V_55 -> V_51 )
V_23 |= V_32 ;
else
V_23 &= ~ V_32 ;
F_6 ( V_21 , V_24 , V_23 ) ;
F_21 ( & V_21 -> V_31 ) ;
return 0 ;
}
static int F_27 ( struct V_44 * V_45 , struct V_61 * V_62 )
{
struct V_21 * V_21 = F_15 ( V_45 ) ;
F_28 ( V_62 , L_4 , F_5 ( V_21 , V_63 ) ) ;
F_28 ( V_62 , L_5 ,
( F_5 ( V_21 , V_24 ) & V_34 ) ? L_6 : L_7 ) ;
F_28 ( V_62 , L_8 ,
( F_5 ( V_21 , V_24 ) & V_33 ) ? L_6 : L_7 ) ;
F_28 ( V_62 , L_9 , F_5 ( V_21 , V_64 ) ) ;
return 0 ;
}
static int T_3 F_29 ( struct V_28 * V_29 )
{
struct V_44 * V_45 = & V_29 -> V_45 ;
struct V_21 * V_21 ;
int V_46 ;
T_1 V_65 ;
V_21 = F_30 ( sizeof( struct V_21 ) , V_66 ) ;
if ( ! V_21 )
return - V_67 ;
F_31 ( & V_21 -> V_31 ) ;
F_32 ( V_29 , V_21 ) ;
V_46 = - V_68 ;
V_21 -> V_69 = F_33 ( V_29 , V_70 , 0 ) ;
if ( ! V_21 -> V_69 ) {
F_17 ( V_45 , L_10 ) ;
goto V_71;
}
V_21 -> V_47 = F_34 ( V_29 , 0 ) ;
if ( V_21 -> V_47 < 0 ) {
F_17 ( V_45 , L_11 ) ;
goto V_71;
}
V_21 -> V_49 = F_34 ( V_29 , 1 ) ;
if ( V_21 -> V_49 < 0 ) {
F_17 ( V_45 , L_12 ) ;
goto V_71;
}
V_46 = - V_67 ;
V_21 -> V_72 = F_35 ( V_21 -> V_69 -> V_73 ,
F_36 ( V_21 -> V_69 ) ) ;
if ( ! V_21 -> V_72 ) {
F_17 ( & V_29 -> V_45 , L_13 ) ;
goto V_74;
}
if ( F_5 ( V_21 , V_63 ) == 0 ) {
V_65 = V_75 + ( V_76 << 16 ) ;
F_6 ( V_21 , V_63 , V_65 ) ;
F_37 ( V_45 , L_14
L_15 ) ;
}
F_4 ( V_21 , V_33 | V_32 | V_34 ) ;
V_21 -> V_42 = F_38 ( L_16 , & V_29 -> V_45 , & V_77 ,
V_78 ) ;
V_46 = F_39 ( V_21 -> V_42 ) ;
if ( F_40 ( V_21 -> V_42 ) ) {
F_17 ( V_45 , L_17 , V_46 ) ;
goto V_79;
}
F_41 ( V_45 , 1 ) ;
return 0 ;
V_79:
F_42 ( V_21 -> V_72 ) ;
V_71:
V_74:
F_43 ( V_21 ) ;
return V_46 ;
}
static int T_4 F_44 ( struct V_28 * V_29 )
{
struct V_21 * V_21 = F_10 ( V_29 ) ;
F_45 ( V_21 -> V_42 ) ;
F_20 ( & V_21 -> V_31 ) ;
F_42 ( V_21 -> V_72 ) ;
F_21 ( & V_21 -> V_31 ) ;
F_43 ( V_21 ) ;
return 0 ;
}
static int F_46 ( struct V_44 * V_45 )
{
struct V_21 * V_21 = F_15 ( V_45 ) ;
if ( F_47 ( V_45 ) )
F_48 ( V_21 -> V_49 ) ;
return 0 ;
}
static int F_49 ( struct V_44 * V_45 )
{
struct V_21 * V_21 = F_15 ( V_45 ) ;
if ( F_47 ( V_45 ) )
F_50 ( V_21 -> V_49 ) ;
return 0 ;
}
static int T_3 F_51 ( void )
{
if ( F_52 () || F_53 () )
return F_54 ( & V_80 , F_29 ) ;
return - V_81 ;
}
static void T_4 F_55 ( void )
{
F_56 ( & V_80 ) ;
}
