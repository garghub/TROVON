static void F_1 ( void )
{
int V_1 = 0 ;
T_1 V_2 ;
for ( V_1 = 0 ; V_1 < 50 ; V_1 ++ ) {
V_2 = F_2 ( V_3 ) ;
if ( ( V_2 & ( T_1 ) V_4 ) == 0 )
break;
F_3 ( 1 ) ;
}
}
static T_2 F_4 ( int V_5 , void * V_6 )
{
unsigned long V_7 = 0 ;
T_1 V_8 ;
V_8 = F_2 ( V_3 ) ;
if ( V_8 & V_9 ) {
F_5 ( V_9 , V_3 ) ;
V_7 |= V_10 | V_11 ;
}
if ( V_8 & V_12 )
V_7 |= V_10 | V_13 ;
F_6 ( V_6 , 1 , V_7 ) ;
return V_14 ;
}
static int F_7 ( struct V_15 * V_16 , unsigned int V_17 )
{
T_1 V_18 , V_19 = 0 ;
struct V_20 * V_21 = F_8 ( V_16 ) ;
const struct V_22 * V_23 =
F_9 ( V_21 ) ;
F_10 () ;
F_1 () ;
V_18 = F_2 ( V_24 ) ;
if ( V_23 -> V_25 & V_26 )
V_19 = F_2 ( V_27 ) ;
if ( V_17 ) {
V_18 |= V_28 ;
V_19 |= V_29 ;
} else {
V_18 &= ~ V_28 ;
V_19 &= ~ V_29 ;
}
F_1 () ;
F_5 ( V_18 , V_24 ) ;
if ( V_23 -> V_25 & V_26 )
F_5 ( V_19 , V_27 ) ;
F_11 () ;
return 0 ;
}
static int F_12 ( struct V_30 * V_31 )
{
if ( F_13 ( V_31 ) != 0 )
return - V_32 ;
V_31 -> V_33 = F_14 ( V_31 -> V_33 ) ;
V_31 -> V_34 = F_14 ( V_31 -> V_34 ) ;
V_31 -> V_35 = F_14 ( V_31 -> V_35 ) ;
V_31 -> V_36 = F_14 ( V_31 -> V_36 ) ;
V_31 -> V_37 = F_14 ( V_31 -> V_37 + 1 ) ;
if ( V_31 -> V_38 < 100 || V_31 -> V_38 > 199 )
return - V_32 ;
V_31 -> V_38 = F_14 ( V_31 -> V_38 - 100 ) ;
return 0 ;
}
static void F_15 ( struct V_30 * V_31 )
{
V_31 -> V_33 = F_16 ( V_31 -> V_33 ) ;
V_31 -> V_34 = F_16 ( V_31 -> V_34 ) ;
V_31 -> V_35 = F_16 ( V_31 -> V_35 ) ;
V_31 -> V_36 = F_16 ( V_31 -> V_36 ) ;
V_31 -> V_37 = F_16 ( V_31 -> V_37 ) - 1 ;
V_31 -> V_38 = F_16 ( V_31 -> V_38 ) + 100 ;
}
static int F_17 ( struct V_15 * V_16 , struct V_30 * V_31 )
{
F_10 () ;
F_1 () ;
V_31 -> V_33 = F_2 ( V_39 ) ;
V_31 -> V_34 = F_2 ( V_40 ) ;
V_31 -> V_35 = F_2 ( V_41 ) ;
V_31 -> V_36 = F_2 ( V_42 ) ;
V_31 -> V_37 = F_2 ( V_43 ) ;
V_31 -> V_38 = F_2 ( V_44 ) ;
F_11 () ;
F_15 ( V_31 ) ;
return 0 ;
}
static int F_18 ( struct V_15 * V_16 , struct V_30 * V_31 )
{
if ( F_12 ( V_31 ) < 0 )
return - V_32 ;
F_10 () ;
F_1 () ;
F_5 ( V_31 -> V_38 , V_44 ) ;
F_5 ( V_31 -> V_37 , V_43 ) ;
F_5 ( V_31 -> V_36 , V_42 ) ;
F_5 ( V_31 -> V_35 , V_41 ) ;
F_5 ( V_31 -> V_34 , V_40 ) ;
F_5 ( V_31 -> V_33 , V_39 ) ;
F_11 () ;
return 0 ;
}
static int F_19 ( struct V_15 * V_16 , struct V_45 * V_46 )
{
F_10 () ;
F_1 () ;
V_46 -> time . V_33 = F_2 ( V_47 ) ;
V_46 -> time . V_34 = F_2 ( V_48 ) ;
V_46 -> time . V_35 = F_2 ( V_49 ) ;
V_46 -> time . V_36 = F_2 ( V_50 ) ;
V_46 -> time . V_37 = F_2 ( V_51 ) ;
V_46 -> time . V_38 = F_2 ( V_52 ) ;
F_11 () ;
F_15 ( & V_46 -> time ) ;
V_46 -> V_17 = ! ! ( F_2 ( V_24 )
& V_28 ) ;
return 0 ;
}
static int F_20 ( struct V_15 * V_16 , struct V_45 * V_46 )
{
T_1 V_18 , V_19 = 0 ;
struct V_20 * V_21 = F_8 ( V_16 ) ;
const struct V_22 * V_23 =
F_9 ( V_21 ) ;
if ( F_12 ( & V_46 -> time ) < 0 )
return - V_32 ;
F_10 () ;
F_1 () ;
F_5 ( V_46 -> time . V_38 , V_52 ) ;
F_5 ( V_46 -> time . V_37 , V_51 ) ;
F_5 ( V_46 -> time . V_36 , V_50 ) ;
F_5 ( V_46 -> time . V_35 , V_49 ) ;
F_5 ( V_46 -> time . V_34 , V_48 ) ;
F_5 ( V_46 -> time . V_33 , V_47 ) ;
V_18 = F_2 ( V_24 ) ;
if ( V_23 -> V_25 & V_26 )
V_19 = F_2 ( V_27 ) ;
if ( V_46 -> V_17 ) {
V_18 |= V_28 ;
V_19 |= V_29 ;
} else {
V_18 &= ~ V_28 ;
V_19 &= ~ V_29 ;
}
F_5 ( V_18 , V_24 ) ;
if ( V_23 -> V_25 & V_26 )
F_5 ( V_19 , V_27 ) ;
F_11 () ;
return 0 ;
}
static int T_3 F_21 ( struct V_20 * V_21 )
{
struct V_53 * V_54 ;
struct V_55 * V_6 ;
T_1 V_18 , V_56 ;
const struct V_22 * V_23 ;
const struct V_57 * V_58 ;
V_58 = F_22 ( V_59 , & V_21 -> V_16 ) ;
if ( V_58 )
V_21 -> V_23 = V_58 -> V_60 ;
V_23 = F_9 ( V_21 ) ;
if ( ! V_23 ) {
F_23 ( & V_21 -> V_16 , L_1 ) ;
return - V_61 ;
}
V_62 = F_24 ( V_21 , 0 ) ;
if ( V_62 <= 0 ) {
F_25 ( L_2 , V_21 -> V_63 ) ;
return - V_64 ;
}
V_65 = F_24 ( V_21 , 1 ) ;
if ( V_65 <= 0 ) {
F_25 ( L_3 , V_21 -> V_63 ) ;
return - V_64 ;
}
V_54 = F_26 ( V_21 , V_66 , 0 ) ;
V_67 = F_27 ( & V_21 -> V_16 , V_54 ) ;
if ( F_28 ( V_67 ) )
return F_29 ( V_67 ) ;
F_30 ( & V_21 -> V_16 ) ;
F_31 ( & V_21 -> V_16 ) ;
if ( V_23 -> V_25 & V_68 ) {
F_32 ( V_69 , V_70 ) ;
F_32 ( V_71 , V_72 ) ;
}
V_6 = F_33 ( & V_21 -> V_16 , V_21 -> V_63 ,
& V_73 , V_74 ) ;
if ( F_28 ( V_6 ) ) {
F_25 ( L_4 ,
V_21 -> V_63 , F_29 ( V_6 ) ) ;
goto V_75;
}
F_34 ( V_21 , V_6 ) ;
F_5 ( 0 , V_24 ) ;
if ( V_23 -> V_25 & V_76 )
F_32 ( V_77 , V_78 ) ;
V_18 = F_2 ( V_3 ) ;
if ( V_18 & ( T_1 ) V_79 ) {
F_35 ( L_5 ,
V_21 -> V_63 ) ;
F_5 ( V_79 , V_3 ) ;
}
if ( V_18 & ( T_1 ) V_9 )
F_5 ( V_9 , V_3 ) ;
if ( F_36 ( & V_21 -> V_16 , V_62 , F_4 , 0 ,
F_37 ( & V_6 -> V_16 ) , V_6 ) ) {
F_25 ( L_6 ,
V_21 -> V_63 , V_62 ) ;
goto V_75;
}
if ( ( V_62 != V_65 ) &&
( F_36 ( & V_21 -> V_16 , V_65 , F_4 , 0 ,
F_37 ( & V_6 -> V_16 ) , V_6 ) ) ) {
F_25 ( L_7 ,
V_21 -> V_63 , V_65 ) ;
goto V_75;
}
V_18 = F_2 ( V_80 ) ;
if ( V_18 & ( T_1 ) V_81 )
F_35 ( L_8 , V_21 -> V_63 ) ;
V_56 = V_18 & ( V_82 | V_83 ) ;
V_56 |= V_81 ;
F_38 ( & V_21 -> V_16 , true ) ;
if ( V_56 & ( T_1 ) V_82 )
F_35 ( L_9 , V_21 -> V_63 ) ;
if ( V_18 != V_56 )
F_5 ( V_56 , V_80 ) ;
return 0 ;
V_75:
if ( V_23 -> V_25 & V_68 )
F_32 ( 0 , V_70 ) ;
F_39 ( & V_21 -> V_16 ) ;
F_40 ( & V_21 -> V_16 ) ;
return - V_84 ;
}
static int T_4 F_41 ( struct V_20 * V_21 )
{
const struct V_22 * V_23 =
F_9 ( V_21 ) ;
F_38 ( & V_21 -> V_16 , 0 ) ;
F_5 ( 0 , V_24 ) ;
if ( V_23 -> V_25 & V_68 )
F_32 ( 0 , V_70 ) ;
F_39 ( & V_21 -> V_16 ) ;
F_40 ( & V_21 -> V_16 ) ;
return 0 ;
}
static int F_42 ( struct V_15 * V_16 )
{
V_85 = F_2 ( V_24 ) ;
if ( F_43 ( V_16 ) )
F_44 ( V_65 ) ;
else
F_5 ( 0 , V_24 ) ;
F_39 ( V_16 ) ;
return 0 ;
}
static int F_45 ( struct V_15 * V_16 )
{
F_31 ( V_16 ) ;
if ( F_43 ( V_16 ) )
F_46 ( V_65 ) ;
else
F_5 ( V_85 , V_24 ) ;
return 0 ;
}
static void F_47 ( struct V_20 * V_21 )
{
F_5 ( 0 , V_24 ) ;
}
