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
if ( ! F_12 ( V_11 -> V_27 ) )
return - 1 ;
return F_13 ( V_11 -> V_27 ) ;
}
static T_4 F_14 ( int V_28 , void * V_29 )
{
struct V_1 * V_30 = (struct V_1 * ) V_29 ;
F_15 ( & V_30 -> V_31 ) ;
return V_32 ;
}
static void F_16 ( struct V_1 * V_2 , T_3 V_33 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
const struct V_13 * V_14 = V_11 -> V_14 ;
if ( ! ( V_33 & V_34 ) )
return;
if ( V_14 -> V_15 & V_35 ) {
T_1 V_36 ;
V_36 = F_17 ( V_2 , V_37 ) ;
V_36 |= V_38 ;
F_18 ( V_2 , V_36 , V_37 ) ;
}
}
static int F_19 ( struct V_1 * V_2 , int V_39 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
T_1 V_40 ;
V_40 = F_17 ( V_2 , V_41 ) ;
if ( V_11 -> V_42 && V_39 == V_43 ) {
V_40 &= ~ V_44 ;
V_40 |= V_45 ;
} else {
V_40 &= ~ V_45 ;
if ( V_39 == V_46 )
V_40 |= V_44 ;
else
V_40 &= ~ V_44 ;
}
F_18 ( V_2 , V_40 , V_41 ) ;
return 0 ;
}
static void F_20 ( struct V_47 * V_48 ,
struct V_10 * V_11 )
{
struct V_49 * V_50 = V_48 -> V_51 ;
T_1 V_39 ;
V_11 -> V_52 = F_21 ( V_50 , L_1 , 0 ) ;
V_11 -> V_27 = F_21 ( V_50 , L_2 , 0 ) ;
V_11 -> V_53 = F_21 ( V_50 , L_3 , 0 ) ;
if ( F_22 ( V_50 , L_4 , & V_39 ) == 0 &&
V_39 == 8 )
V_11 -> V_42 = 1 ;
}
static int F_23 ( struct V_54 * V_55 )
{
const struct V_56 * V_57 ;
const struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_58 * V_58 ;
int V_59 ;
V_57 = F_24 ( V_60 , & V_55 -> V_48 ) ;
if ( ! V_57 )
return - V_61 ;
V_14 = V_57 -> V_29 ;
V_2 = F_25 ( V_55 , V_14 -> V_62 ) ;
if ( F_26 ( V_2 ) )
return F_27 ( V_2 ) ;
V_9 = F_5 ( V_2 ) ;
V_11 = F_28 ( & V_55 -> V_48 , sizeof( * V_11 ) , V_63 ) ;
if ( ! V_11 ) {
F_29 ( F_30 ( V_2 -> V_64 ) , L_5 ) ;
V_59 = - V_65 ;
goto V_66;
}
V_11 -> V_14 = V_14 ;
V_9 -> V_12 = V_11 ;
F_20 ( & V_55 -> V_48 , V_11 ) ;
if ( F_12 ( V_11 -> V_53 ) ) {
V_59 = F_31 ( V_11 -> V_53 , L_6 ) ;
if ( V_59 ) {
F_29 ( F_30 ( V_2 -> V_64 ) ,
L_7 ) ;
goto V_67;
}
F_32 ( V_11 -> V_53 , 1 ) ;
}
if ( F_12 ( V_11 -> V_52 ) ) {
V_59 = F_31 ( V_11 -> V_52 , L_8 ) ;
if ( V_59 ) {
F_29 ( F_30 ( V_2 -> V_64 ) ,
L_9 ) ;
goto V_68;
}
F_33 ( V_11 -> V_52 ) ;
V_59 = F_34 ( F_35 ( V_11 -> V_52 ) ,
F_14 ,
V_69 | V_70 ,
F_36 ( V_2 -> V_64 ) , V_2 ) ;
if ( V_59 ) {
F_29 ( F_30 ( V_2 -> V_64 ) , L_10 ) ;
goto V_71;
}
}
if ( F_12 ( V_11 -> V_27 ) ) {
V_59 = F_31 ( V_11 -> V_27 , L_11 ) ;
if ( V_59 ) {
F_29 ( F_30 ( V_2 -> V_64 ) ,
L_12 ) ;
goto V_72;
}
F_33 ( V_11 -> V_27 ) ;
}
V_58 = F_37 ( F_30 ( V_2 -> V_64 ) , NULL ) ;
if ( F_26 ( V_58 ) ) {
F_29 ( F_30 ( V_2 -> V_64 ) , L_13 ) ;
V_59 = F_27 ( V_58 ) ;
goto V_73;
}
F_38 ( V_58 ) ;
V_9 -> V_58 = V_58 ;
if ( V_11 -> V_42 )
V_2 -> V_64 -> V_74 |= V_75 ;
V_59 = F_39 ( V_2 ) ;
if ( V_59 )
goto V_76;
return 0 ;
V_76:
F_40 ( V_9 -> V_58 ) ;
F_41 ( V_9 -> V_58 ) ;
V_73:
if ( F_12 ( V_11 -> V_27 ) )
F_42 ( V_11 -> V_27 ) ;
V_72:
if ( F_12 ( V_11 -> V_52 ) )
F_43 ( F_35 ( V_11 -> V_52 ) , V_2 ) ;
V_71:
if ( F_12 ( V_11 -> V_52 ) )
F_42 ( V_11 -> V_52 ) ;
V_68:
if ( F_12 ( V_11 -> V_53 ) )
F_42 ( V_11 -> V_53 ) ;
V_67:
V_66:
F_44 ( V_55 ) ;
return V_59 ;
}
static int F_45 ( struct V_54 * V_55 )
{
struct V_1 * V_2 = F_46 ( V_55 ) ;
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_77 = ( F_3 ( V_2 -> V_6 + V_78 ) == 0xffffffff ) ;
F_47 ( V_2 , V_77 ) ;
if ( F_12 ( V_11 -> V_27 ) )
F_42 ( V_11 -> V_27 ) ;
if ( F_12 ( V_11 -> V_52 ) ) {
F_43 ( F_35 ( V_11 -> V_52 ) , V_2 ) ;
F_42 ( V_11 -> V_52 ) ;
}
if ( F_12 ( V_11 -> V_53 ) )
F_42 ( V_11 -> V_53 ) ;
F_40 ( V_9 -> V_58 ) ;
F_41 ( V_9 -> V_58 ) ;
F_44 ( V_55 ) ;
return 0 ;
}
