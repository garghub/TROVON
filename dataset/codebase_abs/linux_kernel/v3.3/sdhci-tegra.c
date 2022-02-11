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
struct V_18 * V_19 = F_11 ( V_17 ) ;
struct V_20 * V_21 = V_19 -> V_22 ;
if ( ! F_12 ( V_21 -> V_23 ) )
return - 1 ;
return F_13 ( V_21 -> V_23 ) ;
}
static T_4 F_14 ( int V_24 , void * V_25 )
{
struct V_1 * V_26 = (struct V_1 * ) V_25 ;
F_15 ( & V_26 -> V_27 ) ;
return V_28 ;
}
static int F_16 ( struct V_1 * V_2 , int V_29 )
{
struct V_18 * V_19 = F_11 ( V_2 ) ;
struct V_20 * V_21 = V_19 -> V_22 ;
T_1 V_30 ;
V_30 = F_17 ( V_2 , V_31 ) ;
if ( V_21 -> V_32 && V_29 == V_33 ) {
V_30 &= ~ V_34 ;
V_30 |= V_35 ;
} else {
V_30 &= ~ V_35 ;
if ( V_29 == V_36 )
V_30 |= V_34 ;
else
V_30 &= ~ V_34 ;
}
F_18 ( V_2 , V_30 , V_31 ) ;
return 0 ;
}
static struct V_20 * T_5 F_19 (
struct V_37 * V_38 )
{
struct V_20 * V_21 ;
struct V_39 * V_40 = V_38 -> V_41 . V_42 ;
if ( ! V_40 )
return NULL ;
V_21 = F_20 ( & V_38 -> V_41 , sizeof( * V_21 ) , V_43 ) ;
if ( ! V_21 ) {
F_21 ( & V_38 -> V_41 , L_1 ) ;
return NULL ;
}
V_21 -> V_44 = F_22 ( V_40 , L_2 , 0 ) ;
V_21 -> V_23 = F_22 ( V_40 , L_3 , 0 ) ;
V_21 -> V_45 = F_22 ( V_40 , L_4 , 0 ) ;
if ( F_23 ( V_40 , L_5 , NULL ) )
V_21 -> V_32 = 1 ;
return V_21 ;
}
static int T_5 F_24 ( struct V_37 * V_38 )
{
struct V_18 * V_19 ;
struct V_20 * V_21 ;
struct V_1 * V_2 ;
struct V_46 * V_46 ;
int V_47 ;
V_2 = F_25 ( V_38 , & V_48 ) ;
if ( F_26 ( V_2 ) )
return F_27 ( V_2 ) ;
V_19 = F_11 ( V_2 ) ;
V_21 = V_38 -> V_41 . V_49 ;
if ( V_21 == NULL )
V_21 = F_19 ( V_38 ) ;
if ( V_21 == NULL ) {
F_21 ( F_28 ( V_2 -> V_50 ) , L_6 ) ;
V_47 = - V_51 ;
goto V_52;
}
V_19 -> V_22 = V_21 ;
if ( F_12 ( V_21 -> V_45 ) ) {
V_47 = F_29 ( V_21 -> V_45 , L_7 ) ;
if ( V_47 ) {
F_21 ( F_28 ( V_2 -> V_50 ) ,
L_8 ) ;
goto V_53;
}
F_30 ( V_21 -> V_45 ) ;
F_31 ( V_21 -> V_45 , 1 ) ;
}
if ( F_12 ( V_21 -> V_44 ) ) {
V_47 = F_29 ( V_21 -> V_44 , L_9 ) ;
if ( V_47 ) {
F_21 ( F_28 ( V_2 -> V_50 ) ,
L_10 ) ;
goto V_54;
}
F_30 ( V_21 -> V_44 ) ;
F_32 ( V_21 -> V_44 ) ;
V_47 = F_33 ( F_34 ( V_21 -> V_44 ) , F_14 ,
V_55 | V_56 ,
F_35 ( V_2 -> V_50 ) , V_2 ) ;
if ( V_47 ) {
F_21 ( F_28 ( V_2 -> V_50 ) , L_11 ) ;
goto V_57;
}
}
if ( F_12 ( V_21 -> V_23 ) ) {
V_47 = F_29 ( V_21 -> V_23 , L_12 ) ;
if ( V_47 ) {
F_21 ( F_28 ( V_2 -> V_50 ) ,
L_13 ) ;
goto V_58;
}
F_30 ( V_21 -> V_23 ) ;
F_32 ( V_21 -> V_23 ) ;
}
V_46 = F_36 ( F_28 ( V_2 -> V_50 ) , NULL ) ;
if ( F_26 ( V_46 ) ) {
F_21 ( F_28 ( V_2 -> V_50 ) , L_14 ) ;
V_47 = F_27 ( V_46 ) ;
goto V_59;
}
F_37 ( V_46 ) ;
V_19 -> V_46 = V_46 ;
V_2 -> V_50 -> V_60 = V_21 -> V_61 ;
if ( V_21 -> V_32 )
V_2 -> V_50 -> V_62 |= V_63 ;
V_47 = F_38 ( V_2 ) ;
if ( V_47 )
goto V_64;
return 0 ;
V_64:
F_39 ( V_19 -> V_46 ) ;
F_40 ( V_19 -> V_46 ) ;
V_59:
if ( F_12 ( V_21 -> V_23 ) ) {
F_41 ( V_21 -> V_23 ) ;
F_42 ( V_21 -> V_23 ) ;
}
V_58:
if ( F_12 ( V_21 -> V_44 ) )
F_43 ( F_34 ( V_21 -> V_44 ) , V_2 ) ;
V_57:
if ( F_12 ( V_21 -> V_44 ) ) {
F_41 ( V_21 -> V_44 ) ;
F_42 ( V_21 -> V_44 ) ;
}
V_54:
if ( F_12 ( V_21 -> V_45 ) ) {
F_41 ( V_21 -> V_45 ) ;
F_42 ( V_21 -> V_45 ) ;
}
V_53:
V_52:
F_44 ( V_38 ) ;
return V_47 ;
}
static int T_6 F_45 ( struct V_37 * V_38 )
{
struct V_1 * V_2 = F_46 ( V_38 ) ;
struct V_18 * V_19 = F_11 ( V_2 ) ;
struct V_20 * V_21 = V_19 -> V_22 ;
int V_65 = ( F_3 ( V_2 -> V_6 + V_66 ) == 0xffffffff ) ;
F_47 ( V_2 , V_65 ) ;
if ( F_12 ( V_21 -> V_23 ) ) {
F_41 ( V_21 -> V_23 ) ;
F_42 ( V_21 -> V_23 ) ;
}
if ( F_12 ( V_21 -> V_44 ) ) {
F_43 ( F_34 ( V_21 -> V_44 ) , V_2 ) ;
F_41 ( V_21 -> V_44 ) ;
F_42 ( V_21 -> V_44 ) ;
}
if ( F_12 ( V_21 -> V_45 ) ) {
F_41 ( V_21 -> V_45 ) ;
F_42 ( V_21 -> V_45 ) ;
}
F_39 ( V_19 -> V_46 ) ;
F_40 ( V_19 -> V_46 ) ;
F_44 ( V_38 ) ;
return 0 ;
}
