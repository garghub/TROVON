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
return F_12 ( V_2 -> V_27 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_3 V_28 )
{
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
const struct V_13 * V_14 = V_11 -> V_14 ;
if ( ! ( V_28 & V_29 ) )
return;
if ( V_14 -> V_15 & V_30 ) {
T_1 V_31 ;
V_31 = F_14 ( V_2 , V_32 ) ;
V_31 |= V_33 ;
F_15 ( V_2 , V_31 , V_32 ) ;
}
}
static int F_16 ( struct V_1 * V_2 , int V_34 )
{
T_1 V_35 ;
V_35 = F_14 ( V_2 , V_36 ) ;
if ( ( V_2 -> V_27 -> V_37 & V_38 ) &&
( V_34 == V_39 ) ) {
V_35 &= ~ V_40 ;
V_35 |= V_41 ;
} else {
V_35 &= ~ V_41 ;
if ( V_34 == V_42 )
V_35 |= V_40 ;
else
V_35 &= ~ V_40 ;
}
F_15 ( V_2 , V_35 , V_36 ) ;
return 0 ;
}
static int F_17 ( struct V_43 * V_44 )
{
struct V_45 * V_46 = V_44 -> V_47 ;
struct V_1 * V_2 = F_18 ( V_44 ) ;
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
V_11 -> V_48 = F_19 ( V_46 , L_1 , 0 ) ;
return F_20 ( V_2 -> V_27 ) ;
}
static int F_21 ( struct V_49 * V_50 )
{
const struct V_51 * V_52 ;
const struct V_13 * V_14 ;
struct V_1 * V_2 ;
struct V_8 * V_9 ;
struct V_10 * V_11 ;
struct V_53 * V_53 ;
int V_54 ;
V_52 = F_22 ( V_55 , & V_50 -> V_44 ) ;
if ( ! V_52 )
return - V_56 ;
V_14 = V_52 -> V_57 ;
V_2 = F_23 ( V_50 , V_14 -> V_58 , 0 ) ;
if ( F_24 ( V_2 ) )
return F_25 ( V_2 ) ;
V_9 = F_5 ( V_2 ) ;
V_11 = F_26 ( & V_50 -> V_44 , sizeof( * V_11 ) , V_59 ) ;
if ( ! V_11 ) {
F_27 ( F_28 ( V_2 -> V_27 ) , L_2 ) ;
V_54 = - V_60 ;
goto V_61;
}
V_11 -> V_14 = V_14 ;
V_9 -> V_12 = V_11 ;
V_54 = F_17 ( & V_50 -> V_44 ) ;
if ( V_54 )
goto V_62;
if ( F_29 ( V_11 -> V_48 ) ) {
V_54 = F_30 ( V_11 -> V_48 , L_3 ) ;
if ( V_54 ) {
F_27 ( F_28 ( V_2 -> V_27 ) ,
L_4 ) ;
goto V_63;
}
F_31 ( V_11 -> V_48 , 1 ) ;
}
V_53 = F_32 ( F_28 ( V_2 -> V_27 ) , NULL ) ;
if ( F_24 ( V_53 ) ) {
F_27 ( F_28 ( V_2 -> V_27 ) , L_5 ) ;
V_54 = F_25 ( V_53 ) ;
goto V_64;
}
F_33 ( V_53 ) ;
V_9 -> V_53 = V_53 ;
V_54 = F_34 ( V_2 ) ;
if ( V_54 )
goto V_65;
return 0 ;
V_65:
F_35 ( V_9 -> V_53 ) ;
F_36 ( V_9 -> V_53 ) ;
V_64:
if ( F_29 ( V_11 -> V_48 ) )
F_37 ( V_11 -> V_48 ) ;
V_63:
V_62:
V_61:
F_38 ( V_50 ) ;
return V_54 ;
}
static int F_39 ( struct V_49 * V_50 )
{
struct V_1 * V_2 = F_40 ( V_50 ) ;
struct V_8 * V_9 = F_5 ( V_2 ) ;
struct V_10 * V_11 = V_9 -> V_12 ;
int V_66 = ( F_3 ( V_2 -> V_6 + V_67 ) == 0xffffffff ) ;
F_41 ( V_2 , V_66 ) ;
if ( F_29 ( V_11 -> V_48 ) )
F_37 ( V_11 -> V_48 ) ;
F_35 ( V_9 -> V_53 ) ;
F_36 ( V_9 -> V_53 ) ;
F_38 ( V_50 ) ;
return 0 ;
}
