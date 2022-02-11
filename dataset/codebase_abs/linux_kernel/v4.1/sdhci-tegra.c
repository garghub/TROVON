static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_9 * V_10 = V_7 -> V_10 ;
if ( F_3 ( ( V_10 -> V_11 & V_12 ) &&
( V_3 == V_13 ) ) ) {
return V_14 ;
}
return F_4 ( V_2 -> V_15 + V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , T_1 V_16 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_3 ) {
case V_17 :
V_5 -> V_18 = V_16 ;
return;
case V_19 :
F_6 ( ( V_16 << 16 ) | V_5 -> V_18 ,
V_2 -> V_15 + V_17 ) ;
return;
}
F_7 ( V_16 , V_2 -> V_15 + V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_16 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_9 * V_10 = V_7 -> V_10 ;
if ( F_3 ( V_3 == V_20 ) )
V_16 &= ~ ( V_21 | V_22 ) ;
F_6 ( V_16 , V_2 -> V_15 + V_3 ) ;
if ( F_3 ( ( V_10 -> V_11 & V_23 ) &&
( V_3 == V_24 ) ) ) {
T_3 V_25 = F_9 ( V_2 -> V_15 + V_26 ) ;
if ( V_16 & V_27 )
V_25 |= 0x8 ;
else
V_25 &= ~ 0x8 ;
F_10 ( V_25 , V_2 -> V_15 + V_26 ) ;
}
}
static unsigned int F_11 ( struct V_1 * V_2 )
{
return F_12 ( V_2 -> V_28 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_3 V_29 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_9 * V_10 = V_7 -> V_10 ;
T_2 V_30 ;
F_14 ( V_2 , V_29 ) ;
if ( ! ( V_29 & V_31 ) )
return;
V_30 = F_15 ( V_2 , V_32 ) ;
if ( V_10 -> V_11 & V_33 )
V_30 |= V_34 ;
if ( V_10 -> V_11 & V_35 )
V_30 &= ~ V_36 ;
if ( V_10 -> V_11 & V_37 )
V_30 &= ~ V_38 ;
if ( V_10 -> V_11 & V_39 )
V_30 &= ~ V_40 ;
F_16 ( V_2 , V_30 , V_32 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_41 )
{
T_2 V_42 ;
V_42 = F_18 ( V_2 , V_43 ) ;
if ( ( V_2 -> V_28 -> V_44 & V_45 ) &&
( V_41 == V_46 ) ) {
V_42 &= ~ V_47 ;
V_42 |= V_48 ;
} else {
V_42 &= ~ V_48 ;
if ( V_41 == V_49 )
V_42 |= V_47 ;
else
V_42 &= ~ V_47 ;
}
F_19 ( V_2 , V_42 , V_43 ) ;
}
static int F_20 ( struct V_50 * V_51 )
{
const struct V_52 * V_53 ;
const struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_54 * V_54 ;
int V_55 ;
V_53 = F_21 ( V_56 , & V_51 -> V_57 ) ;
if ( ! V_53 )
return - V_58 ;
V_10 = V_53 -> V_59 ;
V_2 = F_22 ( V_51 , V_10 -> V_60 , 0 ) ;
if ( F_23 ( V_2 ) )
return F_24 ( V_2 ) ;
V_5 = F_2 ( V_2 ) ;
V_7 = F_25 ( & V_51 -> V_57 , sizeof( * V_7 ) , V_61 ) ;
if ( ! V_7 ) {
F_26 ( F_27 ( V_2 -> V_28 ) , L_1 ) ;
V_55 = - V_62 ;
goto V_63;
}
V_7 -> V_10 = V_10 ;
V_5 -> V_8 = V_7 ;
V_55 = F_28 ( V_2 -> V_28 ) ;
if ( V_55 )
goto V_64;
V_7 -> V_65 = F_29 ( & V_51 -> V_57 , L_2 ,
V_66 ) ;
if ( F_23 ( V_7 -> V_65 ) ) {
V_55 = F_24 ( V_7 -> V_65 ) ;
goto V_67;
}
V_54 = F_30 ( F_27 ( V_2 -> V_28 ) , NULL ) ;
if ( F_23 ( V_54 ) ) {
F_26 ( F_27 ( V_2 -> V_28 ) , L_3 ) ;
V_55 = F_24 ( V_54 ) ;
goto V_68;
}
F_31 ( V_54 ) ;
V_5 -> V_54 = V_54 ;
V_55 = F_32 ( V_2 ) ;
if ( V_55 )
goto V_69;
return 0 ;
V_69:
F_33 ( V_5 -> V_54 ) ;
V_68:
V_67:
V_64:
V_63:
F_34 ( V_51 ) ;
return V_55 ;
}
