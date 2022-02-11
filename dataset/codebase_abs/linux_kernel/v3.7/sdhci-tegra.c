static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
T_1 V_4 ;
if ( F_2 ( V_3 == V_5 ) ) {
V_4 = F_3 ( V_2 -> V_6 + V_3 ) ;
return V_4 | V_7 ;
}
return F_3 ( V_2 -> V_6 + V_3 ) ;
}
static T_2 F_4 ( struct V_1 * V_2 , int V_3 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
const struct V_13 * V_14 = V_11 -> V_14 ;
if ( F_2 ( ( V_14 -> V_15 & V_16 ) &&
( V_3 == V_17 ) ) ) {
return V_18 ;
}
return F_6 ( V_2 -> V_6 + V_3 ) ;
}
static void F_7 ( struct V_1 * V_2 , T_1 V_4 , int V_3 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
const struct V_13 * V_14 = V_11 -> V_14 ;
if ( F_2 ( V_3 == V_19 ) )
V_4 &= ~ ( V_20 | V_21 ) ;
F_8 ( V_4 , V_2 -> V_6 + V_3 ) ;
if ( F_2 ( ( V_14 -> V_15 & V_22 ) &&
( V_3 == V_23 ) ) ) {
T_3 V_24 = F_9 ( V_2 -> V_6 + V_25 ) ;
if ( V_4 & V_26 )
V_24 |= 0x8 ;
else
V_24 &= ~ 0x8 ;
F_10 ( V_24 , V_2 -> V_6 + V_25 ) ;
}
}
static unsigned int F_11 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
const struct V_27 * V_28 = V_11 -> V_28 ;
if ( ! F_12 ( V_28 -> V_29 ) )
return - 1 ;
return F_13 ( V_28 -> V_29 ) ;
}
static T_4 F_14 ( int V_30 , void * V_31 )
{
struct V_1 * V_32 = (struct V_1 * ) V_31 ;
F_15 ( & V_32 -> V_33 ) ;
return V_34 ;
}
static void F_16 ( struct V_1 * V_2 , T_3 V_35 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
const struct V_13 * V_14 = V_11 -> V_14 ;
if ( ! ( V_35 & V_36 ) )
return;
if ( V_14 -> V_15 & V_37 ) {
T_1 V_38 ;
V_38 = F_17 ( V_2 , V_39 ) ;
V_38 |= V_40 ;
F_18 ( V_2 , V_38 , V_39 ) ;
}
}
static int F_19 ( struct V_1 * V_2 , int V_41 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
const struct V_27 * V_28 = V_11 -> V_28 ;
T_1 V_42 ;
V_42 = F_17 ( V_2 , V_43 ) ;
if ( V_28 -> V_44 && V_41 == V_45 ) {
V_42 &= ~ V_46 ;
V_42 |= V_47 ;
} else {
V_42 &= ~ V_47 ;
if ( V_41 == V_48 )
V_42 |= V_46 ;
else
V_42 &= ~ V_46 ;
}
F_18 ( V_2 , V_42 , V_43 ) ;
return 0 ;
}
static struct V_27 * T_5 F_20 (
struct V_49 * V_50 )
{
struct V_27 * V_28 ;
struct V_51 * V_52 = V_50 -> V_53 . V_54 ;
T_1 V_41 ;
if ( ! V_52 )
return NULL ;
V_28 = F_21 ( & V_50 -> V_53 , sizeof( * V_28 ) , V_55 ) ;
if ( ! V_28 ) {
F_22 ( & V_50 -> V_53 , L_1 ) ;
return NULL ;
}
V_28 -> V_56 = F_23 ( V_52 , L_2 , 0 ) ;
V_28 -> V_29 = F_23 ( V_52 , L_3 , 0 ) ;
V_28 -> V_57 = F_23 ( V_52 , L_4 , 0 ) ;
if ( F_24 ( V_52 , L_5 , & V_41 ) == 0 &&
V_41 == 8 )
V_28 -> V_44 = 1 ;
return V_28 ;
}
static int T_5 F_25 ( struct V_49 * V_50 )
{
const struct V_58 * V_59 ;
const struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_27 * V_28 ;
struct V_10 * V_11 ;
struct V_60 * V_60 ;
int V_61 ;
V_59 = F_26 ( V_62 , & V_50 -> V_53 ) ;
if ( ! V_59 )
return - V_63 ;
V_14 = V_59 -> V_31 ;
V_2 = F_27 ( V_50 , V_14 -> V_64 ) ;
if ( F_28 ( V_2 ) )
return F_29 ( V_2 ) ;
V_9 = F_5 ( V_2 ) ;
V_28 = V_50 -> V_53 . V_65 ;
if ( V_28 == NULL )
V_28 = F_20 ( V_50 ) ;
if ( V_28 == NULL ) {
F_22 ( F_30 ( V_2 -> V_66 ) , L_6 ) ;
V_61 = - V_67 ;
goto V_68;
}
V_11 = F_21 ( & V_50 -> V_53 , sizeof( * V_11 ) , V_55 ) ;
if ( ! V_11 ) {
F_22 ( F_30 ( V_2 -> V_66 ) , L_7 ) ;
V_61 = - V_69 ;
goto V_68;
}
V_11 -> V_28 = V_28 ;
V_11 -> V_14 = V_14 ;
V_9 -> V_12 = V_11 ;
if ( F_12 ( V_28 -> V_57 ) ) {
V_61 = F_31 ( V_28 -> V_57 , L_8 ) ;
if ( V_61 ) {
F_22 ( F_30 ( V_2 -> V_66 ) ,
L_9 ) ;
goto V_70;
}
F_32 ( V_28 -> V_57 , 1 ) ;
}
if ( F_12 ( V_28 -> V_56 ) ) {
V_61 = F_31 ( V_28 -> V_56 , L_10 ) ;
if ( V_61 ) {
F_22 ( F_30 ( V_2 -> V_66 ) ,
L_11 ) ;
goto V_71;
}
F_33 ( V_28 -> V_56 ) ;
V_61 = F_34 ( F_35 ( V_28 -> V_56 ) , F_14 ,
V_72 | V_73 ,
F_36 ( V_2 -> V_66 ) , V_2 ) ;
if ( V_61 ) {
F_22 ( F_30 ( V_2 -> V_66 ) , L_12 ) ;
goto V_74;
}
}
if ( F_12 ( V_28 -> V_29 ) ) {
V_61 = F_31 ( V_28 -> V_29 , L_13 ) ;
if ( V_61 ) {
F_22 ( F_30 ( V_2 -> V_66 ) ,
L_14 ) ;
goto V_75;
}
F_33 ( V_28 -> V_29 ) ;
}
V_60 = F_37 ( F_30 ( V_2 -> V_66 ) , NULL ) ;
if ( F_28 ( V_60 ) ) {
F_22 ( F_30 ( V_2 -> V_66 ) , L_15 ) ;
V_61 = F_29 ( V_60 ) ;
goto V_76;
}
F_38 ( V_60 ) ;
V_9 -> V_60 = V_60 ;
V_2 -> V_66 -> V_77 = V_28 -> V_78 ;
if ( V_28 -> V_44 )
V_2 -> V_66 -> V_79 |= V_80 ;
V_61 = F_39 ( V_2 ) ;
if ( V_61 )
goto V_81;
return 0 ;
V_81:
F_40 ( V_9 -> V_60 ) ;
F_41 ( V_9 -> V_60 ) ;
V_76:
if ( F_12 ( V_28 -> V_29 ) )
F_42 ( V_28 -> V_29 ) ;
V_75:
if ( F_12 ( V_28 -> V_56 ) )
F_43 ( F_35 ( V_28 -> V_56 ) , V_2 ) ;
V_74:
if ( F_12 ( V_28 -> V_56 ) )
F_42 ( V_28 -> V_56 ) ;
V_71:
if ( F_12 ( V_28 -> V_57 ) )
F_42 ( V_28 -> V_57 ) ;
V_70:
V_68:
F_44 ( V_50 ) ;
return V_61 ;
}
static int T_6 F_45 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_46 ( V_50 ) ;
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
const struct V_27 * V_28 = V_11 -> V_28 ;
int V_82 = ( F_3 ( V_2 -> V_6 + V_83 ) == 0xffffffff ) ;
F_47 ( V_2 , V_82 ) ;
if ( F_12 ( V_28 -> V_29 ) )
F_42 ( V_28 -> V_29 ) ;
if ( F_12 ( V_28 -> V_56 ) ) {
F_43 ( F_35 ( V_28 -> V_56 ) , V_2 ) ;
F_42 ( V_28 -> V_56 ) ;
}
if ( F_12 ( V_28 -> V_57 ) )
F_42 ( V_28 -> V_57 ) ;
F_40 ( V_9 -> V_60 ) ;
F_41 ( V_9 -> V_60 ) ;
F_44 ( V_50 ) ;
return 0 ;
}
