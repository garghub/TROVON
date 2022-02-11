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
T_1 V_18 ;
F_8 () ;
F_1 () ;
V_18 = F_2 ( V_19 ) ;
if ( V_17 )
V_18 |= V_20 ;
else
V_18 &= ~ V_20 ;
F_1 () ;
F_5 ( V_18 , V_19 ) ;
F_9 () ;
return 0 ;
}
static int F_10 ( struct V_21 * V_22 )
{
if ( F_11 ( V_22 ) != 0 )
return - V_23 ;
V_22 -> V_24 = F_12 ( V_22 -> V_24 ) ;
V_22 -> V_25 = F_12 ( V_22 -> V_25 ) ;
V_22 -> V_26 = F_12 ( V_22 -> V_26 ) ;
V_22 -> V_27 = F_12 ( V_22 -> V_27 ) ;
V_22 -> V_28 = F_12 ( V_22 -> V_28 + 1 ) ;
if ( V_22 -> V_29 < 100 || V_22 -> V_29 > 199 )
return - V_23 ;
V_22 -> V_29 = F_12 ( V_22 -> V_29 - 100 ) ;
return 0 ;
}
static void F_13 ( struct V_21 * V_22 )
{
V_22 -> V_24 = F_14 ( V_22 -> V_24 ) ;
V_22 -> V_25 = F_14 ( V_22 -> V_25 ) ;
V_22 -> V_26 = F_14 ( V_22 -> V_26 ) ;
V_22 -> V_27 = F_14 ( V_22 -> V_27 ) ;
V_22 -> V_28 = F_14 ( V_22 -> V_28 ) - 1 ;
V_22 -> V_29 = F_14 ( V_22 -> V_29 ) + 100 ;
}
static int F_15 ( struct V_15 * V_16 , struct V_21 * V_22 )
{
F_8 () ;
F_1 () ;
V_22 -> V_24 = F_2 ( V_30 ) ;
V_22 -> V_25 = F_2 ( V_31 ) ;
V_22 -> V_26 = F_2 ( V_32 ) ;
V_22 -> V_27 = F_2 ( V_33 ) ;
V_22 -> V_28 = F_2 ( V_34 ) ;
V_22 -> V_29 = F_2 ( V_35 ) ;
F_9 () ;
F_13 ( V_22 ) ;
return 0 ;
}
static int F_16 ( struct V_15 * V_16 , struct V_21 * V_22 )
{
if ( F_10 ( V_22 ) < 0 )
return - V_23 ;
F_8 () ;
F_1 () ;
F_5 ( V_22 -> V_29 , V_35 ) ;
F_5 ( V_22 -> V_28 , V_34 ) ;
F_5 ( V_22 -> V_27 , V_33 ) ;
F_5 ( V_22 -> V_26 , V_32 ) ;
F_5 ( V_22 -> V_25 , V_31 ) ;
F_5 ( V_22 -> V_24 , V_30 ) ;
F_9 () ;
return 0 ;
}
static int F_17 ( struct V_15 * V_16 , struct V_36 * V_37 )
{
F_8 () ;
F_1 () ;
V_37 -> time . V_24 = F_2 ( V_38 ) ;
V_37 -> time . V_25 = F_2 ( V_39 ) ;
V_37 -> time . V_26 = F_2 ( V_40 ) ;
V_37 -> time . V_27 = F_2 ( V_41 ) ;
V_37 -> time . V_28 = F_2 ( V_42 ) ;
V_37 -> time . V_29 = F_2 ( V_43 ) ;
F_9 () ;
F_13 ( & V_37 -> time ) ;
V_37 -> V_17 = ! ! ( F_2 ( V_19 )
& V_20 ) ;
return 0 ;
}
static int F_18 ( struct V_15 * V_16 , struct V_36 * V_37 )
{
T_1 V_18 ;
if ( F_10 ( & V_37 -> time ) < 0 )
return - V_23 ;
F_8 () ;
F_1 () ;
F_5 ( V_37 -> time . V_29 , V_43 ) ;
F_5 ( V_37 -> time . V_28 , V_42 ) ;
F_5 ( V_37 -> time . V_27 , V_41 ) ;
F_5 ( V_37 -> time . V_26 , V_40 ) ;
F_5 ( V_37 -> time . V_25 , V_39 ) ;
F_5 ( V_37 -> time . V_24 , V_38 ) ;
V_18 = F_2 ( V_19 ) ;
if ( V_37 -> V_17 )
V_18 |= V_20 ;
else
V_18 &= ~ V_20 ;
F_5 ( V_18 , V_19 ) ;
F_9 () ;
return 0 ;
}
static int T_3 F_19 ( struct V_44 * V_45 )
{
struct V_46 * V_47 ;
struct V_48 * V_6 ;
T_1 V_18 , V_49 ;
const struct V_50 * V_51 ;
const struct V_52 * V_53 ;
V_53 = F_20 ( V_54 , & V_45 -> V_16 ) ;
if ( V_53 )
V_45 -> V_51 = V_53 -> V_55 ;
V_56 = F_21 ( V_45 , 0 ) ;
if ( V_56 <= 0 ) {
F_22 ( L_1 , V_45 -> V_57 ) ;
return - V_58 ;
}
V_59 = F_21 ( V_45 , 1 ) ;
if ( V_59 <= 0 ) {
F_22 ( L_2 , V_45 -> V_57 ) ;
return - V_58 ;
}
V_47 = F_23 ( V_45 , V_60 , 0 ) ;
V_61 = F_24 ( & V_45 -> V_16 , V_47 ) ;
if ( F_25 ( V_61 ) )
return F_26 ( V_61 ) ;
F_27 ( & V_45 -> V_16 ) ;
F_28 ( & V_45 -> V_16 ) ;
V_51 = F_29 ( V_45 ) ;
if ( V_51 && ( V_51 -> V_62 & V_63 ) ) {
F_30 ( V_64 , V_65 ) ;
F_30 ( V_66 , V_67 ) ;
}
V_6 = F_31 ( & V_45 -> V_16 , V_45 -> V_57 ,
& V_68 , V_69 ) ;
if ( F_25 ( V_6 ) ) {
F_22 ( L_3 ,
V_45 -> V_57 , F_26 ( V_6 ) ) ;
goto V_70;
}
F_32 ( V_45 , V_6 ) ;
F_5 ( 0 , V_19 ) ;
V_18 = F_2 ( V_3 ) ;
if ( V_18 & ( T_1 ) V_71 ) {
F_33 ( L_4 ,
V_45 -> V_57 ) ;
F_5 ( V_71 , V_3 ) ;
}
if ( V_18 & ( T_1 ) V_9 )
F_5 ( V_9 , V_3 ) ;
if ( F_34 ( & V_45 -> V_16 , V_56 , F_4 , 0 ,
F_35 ( & V_6 -> V_16 ) , V_6 ) ) {
F_22 ( L_5 ,
V_45 -> V_57 , V_56 ) ;
goto V_70;
}
if ( ( V_56 != V_59 ) &&
( F_34 ( & V_45 -> V_16 , V_59 , F_4 , 0 ,
F_35 ( & V_6 -> V_16 ) , V_6 ) ) ) {
F_22 ( L_6 ,
V_45 -> V_57 , V_59 ) ;
goto V_70;
}
V_18 = F_2 ( V_72 ) ;
if ( V_18 & ( T_1 ) V_73 )
F_33 ( L_7 , V_45 -> V_57 ) ;
V_49 = V_18 & ( V_74 | V_75 ) ;
V_49 |= V_73 ;
F_36 ( & V_45 -> V_16 , true ) ;
if ( V_49 & ( T_1 ) V_74 )
F_33 ( L_8 , V_45 -> V_57 ) ;
if ( V_18 != V_49 )
F_5 ( V_49 , V_72 ) ;
return 0 ;
V_70:
if ( V_51 && ( V_51 -> V_62 & V_63 ) )
F_30 ( 0 , V_65 ) ;
F_37 ( & V_45 -> V_16 ) ;
F_38 ( & V_45 -> V_16 ) ;
return - V_76 ;
}
static int T_4 F_39 ( struct V_44 * V_45 )
{
const struct V_50 * V_51 =
F_29 ( V_45 ) ;
F_36 ( & V_45 -> V_16 , 0 ) ;
F_5 ( 0 , V_19 ) ;
if ( V_51 && ( V_51 -> V_62 & V_63 ) )
F_30 ( 0 , V_65 ) ;
F_37 ( & V_45 -> V_16 ) ;
F_38 ( & V_45 -> V_16 ) ;
return 0 ;
}
static int F_40 ( struct V_15 * V_16 )
{
T_1 V_77 ;
struct V_44 * V_45 = F_41 ( V_16 ) ;
const struct V_50 * V_51 =
F_29 ( V_45 ) ;
V_78 = F_2 ( V_19 ) ;
if ( F_42 ( V_16 ) ) {
F_43 ( V_59 ) ;
if ( V_51 -> V_62 & V_79 ) {
V_77 = F_2 ( V_80 ) ;
V_77 |= V_81 ;
F_5 ( V_77 , V_80 ) ;
}
} else {
F_5 ( 0 , V_19 ) ;
}
F_37 ( V_16 ) ;
return 0 ;
}
static int F_44 ( struct V_15 * V_16 )
{
T_1 V_77 ;
struct V_44 * V_45 = F_41 ( V_16 ) ;
const struct V_50 * V_51 =
F_29 ( V_45 ) ;
F_28 ( V_16 ) ;
if ( F_42 ( V_16 ) ) {
F_45 ( V_59 ) ;
if ( V_51 -> V_62 & V_79 ) {
V_77 = F_2 ( V_80 ) ;
V_77 &= ~ V_81 ;
F_5 ( V_77 , V_80 ) ;
}
} else {
F_5 ( V_78 , V_19 ) ;
}
return 0 ;
}
static void F_46 ( struct V_44 * V_45 )
{
F_5 ( 0 , V_19 ) ;
}
