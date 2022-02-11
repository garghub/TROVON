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
if ( F_2 ( V_3 == V_8 ) ) {
return V_9 ;
}
return F_5 ( V_2 -> V_6 + V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_4 , int V_3 )
{
if ( F_2 ( V_3 == V_10 ) )
V_4 &= ~ ( V_11 | V_12 ) ;
F_7 ( V_4 , V_2 -> V_6 + V_3 ) ;
if ( F_2 ( V_3 == V_13 ) ) {
T_3 V_14 = F_8 ( V_2 -> V_6 + V_15 ) ;
if ( V_4 & V_16 )
V_14 |= 0x8 ;
else
V_14 &= ~ 0x8 ;
F_9 ( V_14 , V_2 -> V_6 + V_15 ) ;
}
}
static unsigned int F_10 ( struct V_1 * V_17 )
{
struct V_18 * V_19 = F_11 ( F_12 ( V_17 -> V_20 ) ) ;
struct V_21 * V_22 ;
V_22 = V_19 -> V_23 . V_24 ;
if ( ! F_13 ( V_22 -> V_25 ) )
return - 1 ;
return F_14 ( V_22 -> V_25 ) ;
}
static T_4 F_15 ( int V_26 , void * V_27 )
{
struct V_1 * V_28 = (struct V_1 * ) V_27 ;
F_16 ( & V_28 -> V_29 ) ;
return V_30 ;
}
static int F_17 ( struct V_1 * V_2 , int V_31 )
{
struct V_18 * V_19 = F_11 ( F_12 ( V_2 -> V_20 ) ) ;
struct V_21 * V_22 ;
T_1 V_32 ;
V_22 = V_19 -> V_23 . V_24 ;
V_32 = F_18 ( V_2 , V_33 ) ;
if ( V_22 -> V_34 && V_31 == V_35 ) {
V_32 &= ~ V_36 ;
V_32 |= V_37 ;
} else {
V_32 &= ~ V_37 ;
if ( V_31 == V_38 )
V_32 |= V_36 ;
else
V_32 &= ~ V_36 ;
}
F_19 ( V_2 , V_32 , V_33 ) ;
return 0 ;
}
static int F_20 ( struct V_1 * V_2 ,
struct V_39 * V_40 )
{
struct V_41 * V_42 = F_21 ( V_2 ) ;
struct V_18 * V_19 = F_11 ( F_12 ( V_2 -> V_20 ) ) ;
struct V_21 * V_22 ;
struct V_43 * V_43 ;
int V_44 ;
V_22 = V_19 -> V_23 . V_24 ;
if ( V_22 == NULL ) {
F_22 ( F_12 ( V_2 -> V_20 ) , L_1 ) ;
return - V_45 ;
}
if ( F_13 ( V_22 -> V_46 ) ) {
V_44 = F_23 ( V_22 -> V_46 , L_2 ) ;
if ( V_44 ) {
F_22 ( F_12 ( V_2 -> V_20 ) ,
L_3 ) ;
goto V_47;
}
F_24 ( V_22 -> V_46 ) ;
F_25 ( V_22 -> V_46 , 1 ) ;
}
if ( F_13 ( V_22 -> V_48 ) ) {
V_44 = F_23 ( V_22 -> V_48 , L_4 ) ;
if ( V_44 ) {
F_22 ( F_12 ( V_2 -> V_20 ) ,
L_5 ) ;
goto V_49;
}
F_24 ( V_22 -> V_48 ) ;
F_26 ( V_22 -> V_48 ) ;
V_44 = F_27 ( F_28 ( V_22 -> V_48 ) , F_15 ,
V_50 | V_51 ,
F_29 ( V_2 -> V_20 ) , V_2 ) ;
if ( V_44 ) {
F_22 ( F_12 ( V_2 -> V_20 ) , L_6 ) ;
goto V_52;
}
}
if ( F_13 ( V_22 -> V_25 ) ) {
V_44 = F_23 ( V_22 -> V_25 , L_7 ) ;
if ( V_44 ) {
F_22 ( F_12 ( V_2 -> V_20 ) ,
L_8 ) ;
goto V_53;
}
F_24 ( V_22 -> V_25 ) ;
F_26 ( V_22 -> V_25 ) ;
}
V_43 = F_30 ( F_12 ( V_2 -> V_20 ) , NULL ) ;
if ( F_31 ( V_43 ) ) {
F_22 ( F_12 ( V_2 -> V_20 ) , L_9 ) ;
V_44 = F_32 ( V_43 ) ;
goto V_54;
}
F_33 ( V_43 ) ;
V_42 -> V_43 = V_43 ;
V_2 -> V_20 -> V_55 = V_22 -> V_56 ;
if ( V_22 -> V_34 )
V_2 -> V_20 -> V_57 |= V_58 ;
return 0 ;
V_54:
if ( F_13 ( V_22 -> V_25 ) ) {
F_34 ( V_22 -> V_25 ) ;
F_35 ( V_22 -> V_25 ) ;
}
V_53:
if ( F_13 ( V_22 -> V_48 ) )
F_36 ( F_28 ( V_22 -> V_48 ) , V_2 ) ;
V_52:
if ( F_13 ( V_22 -> V_48 ) ) {
F_34 ( V_22 -> V_48 ) ;
F_35 ( V_22 -> V_48 ) ;
}
V_49:
if ( F_13 ( V_22 -> V_46 ) ) {
F_34 ( V_22 -> V_46 ) ;
F_35 ( V_22 -> V_46 ) ;
}
V_47:
return V_44 ;
}
static void F_37 ( struct V_1 * V_2 )
{
struct V_41 * V_42 = F_21 ( V_2 ) ;
struct V_18 * V_19 = F_11 ( F_12 ( V_2 -> V_20 ) ) ;
struct V_21 * V_22 ;
V_22 = V_19 -> V_23 . V_24 ;
if ( F_13 ( V_22 -> V_25 ) ) {
F_34 ( V_22 -> V_25 ) ;
F_35 ( V_22 -> V_25 ) ;
}
if ( F_13 ( V_22 -> V_48 ) ) {
F_36 ( F_28 ( V_22 -> V_48 ) , V_2 ) ;
F_34 ( V_22 -> V_48 ) ;
F_35 ( V_22 -> V_48 ) ;
}
if ( F_13 ( V_22 -> V_46 ) ) {
F_34 ( V_22 -> V_46 ) ;
F_35 ( V_22 -> V_46 ) ;
}
F_38 ( V_42 -> V_43 ) ;
F_39 ( V_42 -> V_43 ) ;
}
