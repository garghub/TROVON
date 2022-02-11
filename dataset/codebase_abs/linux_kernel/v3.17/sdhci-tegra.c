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
static void F_5 ( struct V_1 * V_2 , T_2 V_16 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_9 * V_10 = V_7 -> V_10 ;
if ( F_3 ( V_3 == V_17 ) )
V_16 &= ~ ( V_18 | V_19 ) ;
F_6 ( V_16 , V_2 -> V_15 + V_3 ) ;
if ( F_3 ( ( V_10 -> V_11 & V_20 ) &&
( V_3 == V_21 ) ) ) {
T_3 V_22 = F_7 ( V_2 -> V_15 + V_23 ) ;
if ( V_16 & V_24 )
V_22 |= 0x8 ;
else
V_22 &= ~ 0x8 ;
F_8 ( V_22 , V_2 -> V_15 + V_23 ) ;
}
}
static unsigned int F_9 ( struct V_1 * V_2 )
{
return F_10 ( V_2 -> V_25 ) ;
}
static void F_11 ( struct V_1 * V_2 , T_3 V_26 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_9 * V_10 = V_7 -> V_10 ;
T_2 V_27 ;
F_12 ( V_2 , V_26 ) ;
if ( ! ( V_26 & V_28 ) )
return;
V_27 = F_13 ( V_2 , V_29 ) ;
if ( V_10 -> V_11 & V_30 )
V_27 |= V_31 ;
if ( V_10 -> V_11 & V_32 )
V_27 &= ~ V_33 ;
if ( V_10 -> V_11 & V_34 )
V_27 &= ~ V_35 ;
if ( V_10 -> V_11 & V_36 )
V_27 &= ~ V_37 ;
F_14 ( V_2 , V_27 , V_29 ) ;
}
static void F_15 ( struct V_1 * V_2 , int V_38 )
{
T_2 V_39 ;
V_39 = F_16 ( V_2 , V_40 ) ;
if ( ( V_2 -> V_25 -> V_41 & V_42 ) &&
( V_38 == V_43 ) ) {
V_39 &= ~ V_44 ;
V_39 |= V_45 ;
} else {
V_39 &= ~ V_45 ;
if ( V_38 == V_46 )
V_39 |= V_44 ;
else
V_39 &= ~ V_44 ;
}
F_17 ( V_2 , V_39 , V_40 ) ;
}
static int F_18 ( struct V_47 * V_48 )
{
struct V_49 * V_50 = V_48 -> V_51 ;
struct V_1 * V_2 = F_19 ( V_48 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
V_7 -> V_52 = F_20 ( V_50 , L_1 , 0 ) ;
return F_21 ( V_2 -> V_25 ) ;
}
static int F_22 ( struct V_53 * V_54 )
{
const struct V_55 * V_56 ;
const struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_57 * V_57 ;
int V_58 ;
V_56 = F_23 ( V_59 , & V_54 -> V_48 ) ;
if ( ! V_56 )
return - V_60 ;
V_10 = V_56 -> V_61 ;
V_2 = F_24 ( V_54 , V_10 -> V_62 , 0 ) ;
if ( F_25 ( V_2 ) )
return F_26 ( V_2 ) ;
V_5 = F_2 ( V_2 ) ;
V_7 = F_27 ( & V_54 -> V_48 , sizeof( * V_7 ) , V_63 ) ;
if ( ! V_7 ) {
F_28 ( F_29 ( V_2 -> V_25 ) , L_2 ) ;
V_58 = - V_64 ;
goto V_65;
}
V_7 -> V_10 = V_10 ;
V_5 -> V_8 = V_7 ;
V_58 = F_18 ( & V_54 -> V_48 ) ;
if ( V_58 )
goto V_66;
if ( F_30 ( V_7 -> V_52 ) ) {
V_58 = F_31 ( V_7 -> V_52 , L_3 ) ;
if ( V_58 ) {
F_28 ( F_29 ( V_2 -> V_25 ) ,
L_4 ) ;
goto V_67;
}
F_32 ( V_7 -> V_52 , 1 ) ;
}
V_57 = F_33 ( F_29 ( V_2 -> V_25 ) , NULL ) ;
if ( F_25 ( V_57 ) ) {
F_28 ( F_29 ( V_2 -> V_25 ) , L_5 ) ;
V_58 = F_26 ( V_57 ) ;
goto V_68;
}
F_34 ( V_57 ) ;
V_5 -> V_57 = V_57 ;
V_58 = F_35 ( V_2 ) ;
if ( V_58 )
goto V_69;
return 0 ;
V_69:
F_36 ( V_5 -> V_57 ) ;
F_37 ( V_5 -> V_57 ) ;
V_68:
if ( F_30 ( V_7 -> V_52 ) )
F_38 ( V_7 -> V_52 ) ;
V_67:
V_66:
V_65:
F_39 ( V_54 ) ;
return V_58 ;
}
static int F_40 ( struct V_53 * V_54 )
{
struct V_1 * V_2 = F_41 ( V_54 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_70 = ( F_42 ( V_2 -> V_15 + V_71 ) == 0xffffffff ) ;
F_43 ( V_2 , V_70 ) ;
if ( F_30 ( V_7 -> V_52 ) )
F_38 ( V_7 -> V_52 ) ;
F_36 ( V_5 -> V_57 ) ;
F_37 ( V_5 -> V_57 ) ;
F_39 ( V_54 ) ;
return 0 ;
}
