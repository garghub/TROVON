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
static int F_16 ( struct V_1 * V_2 , int V_35 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
const struct V_27 * V_28 = V_11 -> V_28 ;
T_1 V_36 ;
V_36 = F_17 ( V_2 , V_37 ) ;
if ( V_28 -> V_38 && V_35 == V_39 ) {
V_36 &= ~ V_40 ;
V_36 |= V_41 ;
} else {
V_36 &= ~ V_41 ;
if ( V_35 == V_42 )
V_36 |= V_40 ;
else
V_36 &= ~ V_40 ;
}
F_18 ( V_2 , V_36 , V_37 ) ;
return 0 ;
}
static struct V_27 * T_5 F_19 (
struct V_43 * V_44 )
{
struct V_27 * V_28 ;
struct V_45 * V_46 = V_44 -> V_47 . V_48 ;
if ( ! V_46 )
return NULL ;
V_28 = F_20 ( & V_44 -> V_47 , sizeof( * V_28 ) , V_49 ) ;
if ( ! V_28 ) {
F_21 ( & V_44 -> V_47 , L_1 ) ;
return NULL ;
}
V_28 -> V_50 = F_22 ( V_46 , L_2 , 0 ) ;
V_28 -> V_29 = F_22 ( V_46 , L_3 , 0 ) ;
V_28 -> V_51 = F_22 ( V_46 , L_4 , 0 ) ;
if ( F_23 ( V_46 , L_5 , NULL ) )
V_28 -> V_38 = 1 ;
return V_28 ;
}
static int T_5 F_24 ( struct V_43 * V_44 )
{
const struct V_52 * V_53 ;
const struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_27 * V_28 ;
struct V_10 * V_11 ;
struct V_54 * V_54 ;
int V_55 ;
V_53 = F_25 ( V_56 , & V_44 -> V_47 ) ;
if ( V_53 )
V_14 = V_53 -> V_31 ;
else
V_14 = & V_57 ;
V_2 = F_26 ( V_44 , V_14 -> V_58 ) ;
if ( F_27 ( V_2 ) )
return F_28 ( V_2 ) ;
V_9 = F_5 ( V_2 ) ;
V_28 = V_44 -> V_47 . V_59 ;
if ( V_28 == NULL )
V_28 = F_19 ( V_44 ) ;
if ( V_28 == NULL ) {
F_21 ( F_29 ( V_2 -> V_60 ) , L_6 ) ;
V_55 = - V_61 ;
goto V_62;
}
V_11 = F_20 ( & V_44 -> V_47 , sizeof( * V_11 ) , V_49 ) ;
if ( ! V_11 ) {
F_21 ( F_29 ( V_2 -> V_60 ) , L_7 ) ;
V_55 = - V_63 ;
goto V_62;
}
V_11 -> V_28 = V_28 ;
V_11 -> V_14 = V_14 ;
V_9 -> V_12 = V_11 ;
if ( F_12 ( V_28 -> V_51 ) ) {
V_55 = F_30 ( V_28 -> V_51 , L_8 ) ;
if ( V_55 ) {
F_21 ( F_29 ( V_2 -> V_60 ) ,
L_9 ) ;
goto V_64;
}
F_31 ( V_28 -> V_51 ) ;
F_32 ( V_28 -> V_51 , 1 ) ;
}
if ( F_12 ( V_28 -> V_50 ) ) {
V_55 = F_30 ( V_28 -> V_50 , L_10 ) ;
if ( V_55 ) {
F_21 ( F_29 ( V_2 -> V_60 ) ,
L_11 ) ;
goto V_65;
}
F_31 ( V_28 -> V_50 ) ;
F_33 ( V_28 -> V_50 ) ;
V_55 = F_34 ( F_35 ( V_28 -> V_50 ) , F_14 ,
V_66 | V_67 ,
F_36 ( V_2 -> V_60 ) , V_2 ) ;
if ( V_55 ) {
F_21 ( F_29 ( V_2 -> V_60 ) , L_12 ) ;
goto V_68;
}
}
if ( F_12 ( V_28 -> V_29 ) ) {
V_55 = F_30 ( V_28 -> V_29 , L_13 ) ;
if ( V_55 ) {
F_21 ( F_29 ( V_2 -> V_60 ) ,
L_14 ) ;
goto V_69;
}
F_31 ( V_28 -> V_29 ) ;
F_33 ( V_28 -> V_29 ) ;
}
V_54 = F_37 ( F_29 ( V_2 -> V_60 ) , NULL ) ;
if ( F_27 ( V_54 ) ) {
F_21 ( F_29 ( V_2 -> V_60 ) , L_15 ) ;
V_55 = F_28 ( V_54 ) ;
goto V_70;
}
F_38 ( V_54 ) ;
V_9 -> V_54 = V_54 ;
V_2 -> V_60 -> V_71 = V_28 -> V_72 ;
if ( V_28 -> V_38 )
V_2 -> V_60 -> V_73 |= V_74 ;
V_55 = F_39 ( V_2 ) ;
if ( V_55 )
goto V_75;
return 0 ;
V_75:
F_40 ( V_9 -> V_54 ) ;
F_41 ( V_9 -> V_54 ) ;
V_70:
if ( F_12 ( V_28 -> V_29 ) ) {
F_42 ( V_28 -> V_29 ) ;
F_43 ( V_28 -> V_29 ) ;
}
V_69:
if ( F_12 ( V_28 -> V_50 ) )
F_44 ( F_35 ( V_28 -> V_50 ) , V_2 ) ;
V_68:
if ( F_12 ( V_28 -> V_50 ) ) {
F_42 ( V_28 -> V_50 ) ;
F_43 ( V_28 -> V_50 ) ;
}
V_65:
if ( F_12 ( V_28 -> V_51 ) ) {
F_42 ( V_28 -> V_51 ) ;
F_43 ( V_28 -> V_51 ) ;
}
V_64:
V_62:
F_45 ( V_44 ) ;
return V_55 ;
}
static int T_6 F_46 ( struct V_43 * V_44 )
{
struct V_1 * V_2 = F_47 ( V_44 ) ;
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
const struct V_27 * V_28 = V_11 -> V_28 ;
int V_76 = ( F_3 ( V_2 -> V_6 + V_77 ) == 0xffffffff ) ;
F_48 ( V_2 , V_76 ) ;
if ( F_12 ( V_28 -> V_29 ) ) {
F_42 ( V_28 -> V_29 ) ;
F_43 ( V_28 -> V_29 ) ;
}
if ( F_12 ( V_28 -> V_50 ) ) {
F_44 ( F_35 ( V_28 -> V_50 ) , V_2 ) ;
F_42 ( V_28 -> V_50 ) ;
F_43 ( V_28 -> V_50 ) ;
}
if ( F_12 ( V_28 -> V_51 ) ) {
F_42 ( V_28 -> V_51 ) ;
F_43 ( V_28 -> V_51 ) ;
}
F_40 ( V_9 -> V_54 ) ;
F_41 ( V_9 -> V_54 ) ;
F_45 ( V_44 ) ;
return 0 ;
}
