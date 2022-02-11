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
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_9 * V_10 = V_7 -> V_10 ;
if ( V_10 -> V_11 & V_17 ) {
switch ( V_3 ) {
case V_18 :
V_5 -> V_19 = V_16 ;
return;
case V_20 :
F_6 ( ( V_16 << 16 ) | V_5 -> V_19 ,
V_2 -> V_15 + V_18 ) ;
return;
}
}
F_7 ( V_16 , V_2 -> V_15 + V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_16 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_9 * V_10 = V_7 -> V_10 ;
if ( F_3 ( V_3 == V_21 ) )
V_16 &= ~ ( V_22 | V_23 ) ;
F_6 ( V_16 , V_2 -> V_15 + V_3 ) ;
if ( F_3 ( ( V_10 -> V_11 & V_24 ) &&
( V_3 == V_25 ) ) ) {
T_3 V_26 = F_9 ( V_2 -> V_15 + V_27 ) ;
if ( V_16 & V_28 )
V_26 |= 0x8 ;
else
V_26 &= ~ 0x8 ;
F_10 ( V_26 , V_2 -> V_15 + V_27 ) ;
}
}
static unsigned int F_11 ( struct V_1 * V_2 )
{
return F_12 ( V_2 -> V_29 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_3 V_30 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_9 * V_10 = V_7 -> V_10 ;
T_2 V_31 ;
F_14 ( V_2 , V_30 ) ;
if ( ! ( V_30 & V_32 ) )
return;
V_31 = F_15 ( V_2 , V_33 ) ;
if ( V_10 -> V_11 & V_34 )
V_31 |= V_35 ;
if ( V_10 -> V_11 & V_36 )
V_31 &= ~ V_37 ;
if ( V_10 -> V_11 & V_38 )
V_31 &= ~ V_39 ;
if ( V_10 -> V_11 & V_40 )
V_31 &= ~ V_41 ;
F_16 ( V_2 , V_31 , V_33 ) ;
}
static void F_17 ( struct V_1 * V_2 , int V_42 )
{
T_2 V_43 ;
V_43 = F_18 ( V_2 , V_44 ) ;
if ( ( V_2 -> V_29 -> V_45 & V_46 ) &&
( V_42 == V_47 ) ) {
V_43 &= ~ V_48 ;
V_43 |= V_49 ;
} else {
V_43 &= ~ V_49 ;
if ( V_42 == V_50 )
V_43 |= V_48 ;
else
V_43 &= ~ V_48 ;
}
F_19 ( V_2 , V_43 , V_44 ) ;
}
static int F_20 ( struct V_51 * V_52 )
{
struct V_53 * V_54 = V_52 -> V_55 ;
struct V_1 * V_2 = F_21 ( V_52 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
V_7 -> V_56 = F_22 ( V_54 , L_1 , 0 ) ;
return F_23 ( V_2 -> V_29 ) ;
}
static int F_24 ( struct V_57 * V_58 )
{
const struct V_59 * V_60 ;
const struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_61 * V_61 ;
int V_62 ;
V_60 = F_25 ( V_63 , & V_58 -> V_52 ) ;
if ( ! V_60 )
return - V_64 ;
V_10 = V_60 -> V_65 ;
V_2 = F_26 ( V_58 , V_10 -> V_66 , 0 ) ;
if ( F_27 ( V_2 ) )
return F_28 ( V_2 ) ;
V_5 = F_2 ( V_2 ) ;
V_7 = F_29 ( & V_58 -> V_52 , sizeof( * V_7 ) , V_67 ) ;
if ( ! V_7 ) {
F_30 ( F_31 ( V_2 -> V_29 ) , L_2 ) ;
V_62 = - V_68 ;
goto V_69;
}
V_7 -> V_10 = V_10 ;
V_5 -> V_8 = V_7 ;
V_62 = F_20 ( & V_58 -> V_52 ) ;
if ( V_62 )
goto V_70;
if ( F_32 ( V_7 -> V_56 ) ) {
V_62 = F_33 ( V_7 -> V_56 , L_3 ) ;
if ( V_62 ) {
F_30 ( F_31 ( V_2 -> V_29 ) ,
L_4 ) ;
goto V_71;
}
F_34 ( V_7 -> V_56 , 1 ) ;
}
V_61 = F_35 ( F_31 ( V_2 -> V_29 ) , NULL ) ;
if ( F_27 ( V_61 ) ) {
F_30 ( F_31 ( V_2 -> V_29 ) , L_5 ) ;
V_62 = F_28 ( V_61 ) ;
goto V_72;
}
F_36 ( V_61 ) ;
V_5 -> V_61 = V_61 ;
V_62 = F_37 ( V_2 ) ;
if ( V_62 )
goto V_73;
return 0 ;
V_73:
F_38 ( V_5 -> V_61 ) ;
F_39 ( V_5 -> V_61 ) ;
V_72:
if ( F_32 ( V_7 -> V_56 ) )
F_40 ( V_7 -> V_56 ) ;
V_71:
V_70:
V_69:
F_41 ( V_58 ) ;
return V_62 ;
}
static int F_42 ( struct V_57 * V_58 )
{
struct V_1 * V_2 = F_43 ( V_58 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
int V_74 = ( F_44 ( V_2 -> V_15 + V_75 ) == 0xffffffff ) ;
F_45 ( V_2 , V_74 ) ;
if ( F_32 ( V_7 -> V_56 ) )
F_40 ( V_7 -> V_56 ) ;
F_38 ( V_5 -> V_61 ) ;
F_39 ( V_5 -> V_61 ) ;
F_41 ( V_58 ) ;
return 0 ;
}
