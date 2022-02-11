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
struct V_46 * V_47 , * V_48 ;
struct V_49 * V_6 ;
T_1 V_18 , V_50 ;
V_51 = F_20 ( V_45 , 0 ) ;
if ( V_51 <= 0 ) {
F_21 ( L_1 , V_45 -> V_52 ) ;
return - V_53 ;
}
V_54 = F_20 ( V_45 , 1 ) ;
if ( V_54 <= 0 ) {
F_21 ( L_2 , V_45 -> V_52 ) ;
return - V_53 ;
}
V_47 = F_22 ( V_45 , V_55 , 0 ) ;
if ( ! V_47 ) {
F_21 ( L_3 , V_45 -> V_52 ) ;
return - V_53 ;
}
V_48 = F_23 ( V_47 -> V_56 , F_24 ( V_47 ) , V_45 -> V_52 ) ;
if ( ! V_48 ) {
F_21 ( L_4 ,
V_45 -> V_52 , V_47 -> V_56 ) ;
return - V_57 ;
}
V_58 = F_25 ( V_47 -> V_56 , F_24 ( V_47 ) ) ;
if ( ! V_58 ) {
F_21 ( L_5 , V_45 -> V_52 ) ;
goto V_59;
}
V_6 = F_26 ( V_45 -> V_52 , & V_45 -> V_16 ,
& V_60 , V_61 ) ;
if ( F_27 ( V_6 ) ) {
F_21 ( L_6 ,
V_45 -> V_52 , F_28 ( V_6 ) ) ;
goto V_62;
}
F_29 ( V_45 , V_6 ) ;
F_30 ( & V_6 -> V_16 , V_48 ) ;
F_5 ( 0 , V_19 ) ;
V_18 = F_2 ( V_3 ) ;
if ( V_18 & ( T_1 ) V_63 ) {
F_31 ( L_7 ,
V_45 -> V_52 ) ;
F_5 ( V_63 , V_3 ) ;
}
if ( V_18 & ( T_1 ) V_9 )
F_5 ( V_9 , V_3 ) ;
if ( F_32 ( V_51 , F_4 , 0 ,
F_33 ( & V_6 -> V_16 ) , V_6 ) ) {
F_21 ( L_8 ,
V_45 -> V_52 , V_51 ) ;
goto V_64;
}
if ( ( V_51 != V_54 ) &&
( F_32 ( V_54 , F_4 , 0 ,
F_33 ( & V_6 -> V_16 ) , V_6 ) ) ) {
F_21 ( L_9 ,
V_45 -> V_52 , V_54 ) ;
goto V_65;
}
V_18 = F_2 ( V_66 ) ;
if ( V_18 & ( T_1 ) V_67 )
F_31 ( L_10 , V_45 -> V_52 ) ;
V_50 = V_18 & ( V_68 | V_69 ) ;
V_50 |= V_67 ;
if ( V_50 & ( T_1 ) V_68 )
F_31 ( L_11 , V_45 -> V_52 ) ;
if ( V_18 != V_50 )
F_5 ( V_50 , V_66 ) ;
return 0 ;
V_65:
F_34 ( V_51 , V_6 ) ;
V_64:
F_35 ( V_6 ) ;
V_62:
F_36 ( V_58 ) ;
V_59:
F_37 ( V_48 -> V_56 , F_24 ( V_48 ) ) ;
return - V_70 ;
}
static int T_4 F_38 ( struct V_44 * V_45 )
{
struct V_49 * V_6 = F_39 ( V_45 ) ;
struct V_46 * V_48 = F_40 ( & V_6 -> V_16 ) ;
F_41 ( & V_45 -> V_16 , 0 ) ;
F_5 ( 0 , V_19 ) ;
F_34 ( V_51 , V_6 ) ;
if ( V_51 != V_54 )
F_34 ( V_54 , V_6 ) ;
F_35 ( V_6 ) ;
F_36 ( V_58 ) ;
F_37 ( V_48 -> V_56 , F_24 ( V_48 ) ) ;
return 0 ;
}
static int F_42 ( struct V_44 * V_45 , T_5 V_71 )
{
V_72 = F_2 ( V_19 ) ;
if ( F_43 ( & V_45 -> V_16 ) )
F_44 ( V_54 ) ;
else
F_5 ( 0 , V_19 ) ;
return 0 ;
}
static int F_45 ( struct V_44 * V_45 )
{
if ( F_43 ( & V_45 -> V_16 ) )
F_46 ( V_54 ) ;
else
F_5 ( V_72 , V_19 ) ;
return 0 ;
}
static void F_47 ( struct V_44 * V_45 )
{
F_5 ( 0 , V_19 ) ;
}
static int T_3 F_48 ( void )
{
return F_49 ( & V_73 , F_19 ) ;
}
static void T_4 F_50 ( void )
{
F_51 ( & V_73 ) ;
}
