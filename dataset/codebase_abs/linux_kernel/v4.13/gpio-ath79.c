static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 , struct V_1 , V_5 ) ;
}
static T_1 F_4 ( struct V_1 * V_6 , unsigned V_7 )
{
return F_5 ( V_6 -> V_8 + V_7 ) ;
}
static void F_6 ( struct V_1 * V_6 ,
unsigned V_7 , T_1 V_9 )
{
return F_7 ( V_9 , V_6 -> V_8 + V_7 ) ;
}
static bool F_8 (
struct V_1 * V_6 , unsigned V_7 , T_1 V_10 , T_1 V_11 )
{
T_1 V_12 , V_13 ;
V_12 = F_4 ( V_6 , V_7 ) ;
V_13 = ( V_12 & ~ V_10 ) | ( V_11 & V_10 ) ;
if ( V_13 != V_12 )
F_6 ( V_6 , V_7 , V_13 ) ;
return V_13 != V_12 ;
}
static void F_9 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_10 = F_10 ( F_11 ( V_3 ) ) ;
unsigned long V_14 ;
F_12 ( & V_6 -> V_15 , V_14 ) ;
F_8 ( V_6 , V_16 , V_10 , V_10 ) ;
F_13 ( & V_6 -> V_15 , V_14 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_10 = F_10 ( F_11 ( V_3 ) ) ;
unsigned long V_14 ;
F_12 ( & V_6 -> V_15 , V_14 ) ;
F_8 ( V_6 , V_16 , V_10 , 0 ) ;
F_13 ( & V_6 -> V_15 , V_14 ) ;
}
static void F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_10 = F_10 ( F_11 ( V_3 ) ) ;
unsigned long V_14 ;
F_12 ( & V_6 -> V_15 , V_14 ) ;
F_8 ( V_6 , V_17 , V_10 , V_10 ) ;
F_8 ( V_6 , V_16 , V_10 , V_10 ) ;
F_13 ( & V_6 -> V_15 , V_14 ) ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_10 = F_10 ( F_11 ( V_3 ) ) ;
unsigned long V_14 ;
F_12 ( & V_6 -> V_15 , V_14 ) ;
F_8 ( V_6 , V_16 , V_10 , 0 ) ;
F_8 ( V_6 , V_17 , V_10 , 0 ) ;
F_13 ( & V_6 -> V_15 , V_14 ) ;
}
static int F_17 ( struct V_2 * V_3 ,
unsigned int V_18 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
T_1 V_10 = F_10 ( F_11 ( V_3 ) ) ;
T_1 type = 0 , V_19 = 0 ;
unsigned long V_14 ;
bool V_20 ;
switch ( V_18 ) {
case V_21 :
V_19 |= V_10 ;
case V_22 :
case V_23 :
break;
case V_24 :
V_19 |= V_10 ;
case V_25 :
type |= V_10 ;
break;
default:
return - V_26 ;
}
F_12 ( & V_6 -> V_15 , V_14 ) ;
if ( V_18 == V_23 ) {
V_6 -> V_27 |= V_10 ;
V_19 = ~ F_4 ( V_6 , V_28 ) ;
} else {
V_6 -> V_27 &= ~ V_10 ;
}
V_20 = F_8 (
V_6 , V_17 , V_10 , 0 ) ;
F_8 (
V_6 , V_29 , V_10 , type ) ;
F_8 (
V_6 , V_30 , V_10 , V_19 ) ;
if ( V_20 )
F_8 (
V_6 , V_17 , V_10 , V_10 ) ;
F_13 ( & V_6 -> V_15 , V_14 ) ;
return 0 ;
}
static void F_18 ( struct V_31 * V_32 )
{
struct V_4 * V_5 = F_19 ( V_32 ) ;
struct V_33 * V_34 = F_20 ( V_32 ) ;
struct V_1 * V_6 =
F_3 ( V_5 , struct V_1 , V_5 ) ;
unsigned long V_14 , V_35 ;
T_1 V_27 , V_36 ;
int V_37 ;
F_21 ( V_34 , V_32 ) ;
F_12 ( & V_6 -> V_15 , V_14 ) ;
V_35 = F_4 ( V_6 , V_38 ) ;
V_27 = V_6 -> V_27 & V_35 ;
if ( V_27 ) {
V_36 = F_4 ( V_6 , V_28 ) ;
F_8 ( V_6 , V_30 ,
V_27 , ~ V_36 ) ;
}
F_13 ( & V_6 -> V_15 , V_14 ) ;
if ( V_35 ) {
F_22 (irq, &pending, gc->ngpio)
F_23 (
F_24 ( V_5 -> V_39 , V_37 ) ) ;
}
F_25 ( V_34 , V_32 ) ;
}
static int F_26 ( struct V_40 * V_41 )
{
struct V_42 * V_43 = F_27 ( & V_41 -> V_44 ) ;
struct V_45 * V_46 = V_41 -> V_44 . V_47 ;
struct V_1 * V_6 ;
struct V_48 * V_49 ;
T_1 V_50 ;
bool V_51 ;
int V_52 ;
V_6 = F_28 ( & V_41 -> V_44 , sizeof( * V_6 ) , V_53 ) ;
if ( ! V_6 )
return - V_54 ;
F_29 ( V_41 , V_6 ) ;
if ( V_46 ) {
V_52 = F_30 ( V_46 , L_1 , & V_50 ) ;
if ( V_52 ) {
F_31 ( & V_41 -> V_44 , L_2 ) ;
return V_52 ;
}
V_51 = F_32 ( V_46 , L_3 ) ;
} else if ( V_43 ) {
V_50 = V_43 -> V_55 ;
V_51 = V_43 -> V_51 ;
} else {
F_31 ( & V_41 -> V_44 , L_4 ) ;
return - V_26 ;
}
if ( V_50 >= 32 ) {
F_31 ( & V_41 -> V_44 , L_5 ) ;
return - V_26 ;
}
V_49 = F_33 ( V_41 , V_56 , 0 ) ;
V_6 -> V_8 = F_34 (
& V_41 -> V_44 , V_49 -> V_57 , F_35 ( V_49 ) ) ;
if ( ! V_6 -> V_8 )
return - V_54 ;
F_36 ( & V_6 -> V_15 ) ;
V_52 = F_37 ( & V_6 -> V_5 , & V_41 -> V_44 , 4 ,
V_6 -> V_8 + V_28 ,
V_6 -> V_8 + V_58 ,
V_6 -> V_8 + V_59 ,
V_51 ? NULL : V_6 -> V_8 + V_60 ,
V_51 ? V_6 -> V_8 + V_60 : NULL ,
0 ) ;
if ( V_52 ) {
F_31 ( & V_41 -> V_44 , L_6 ) ;
return V_52 ;
}
V_6 -> V_5 . V_8 = 0 ;
V_52 = F_38 ( & V_6 -> V_5 , V_6 ) ;
if ( V_52 ) {
F_31 ( & V_41 -> V_44 ,
L_7 , V_52 ) ;
return V_52 ;
}
if ( V_46 && ! F_39 ( V_46 , L_8 ) )
return 0 ;
V_52 = F_40 ( & V_6 -> V_5 , & V_61 , 0 ,
V_62 , V_63 ) ;
if ( V_52 ) {
F_31 ( & V_41 -> V_44 , L_9 ) ;
goto V_64;
}
F_41 ( & V_6 -> V_5 , & V_61 ,
F_42 ( V_41 , 0 ) ,
F_18 ) ;
return 0 ;
V_64:
V_64 ( & V_6 -> V_5 ) ;
return V_52 ;
}
static int F_43 ( struct V_40 * V_41 )
{
struct V_1 * V_6 = F_44 ( V_41 ) ;
V_64 ( & V_6 -> V_5 ) ;
return 0 ;
}
