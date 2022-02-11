static inline T_1 F_1 ( void T_2 * V_1 , T_1 V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void F_3 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
}
static T_1 F_5 ( struct V_4 * V_5 )
{
return F_1 ( V_5 -> V_1 , V_6 +
V_5 -> V_7 ) ;
}
static void F_6 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_6 +
V_5 -> V_7 , V_3 ) ;
}
static T_1 F_7 ( struct V_4 * V_5 )
{
return F_1 ( V_5 -> V_1 , V_8 -
V_5 -> V_9 ) ;
}
static void F_8 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_8 -
V_5 -> V_9 , V_3 ) ;
}
static T_1 F_9 ( struct V_4 * V_5 )
{
return F_1 ( V_5 -> V_1 , V_10 +
V_5 -> V_11 ) ;
}
static void F_10 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_10 +
V_5 -> V_11 , V_3 ) ;
}
static void F_11 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_12 +
V_5 -> V_11 , V_3 ) ;
}
static void F_12 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_13 -
V_5 -> V_9 , V_3 ) ;
}
int F_13 ( enum V_14 V_15 )
{
T_1 V_16 ;
struct V_4 * V_5 = V_17 ;
if ( ! V_5 )
return - V_18 ;
switch ( V_15 ) {
case V_19 :
F_14 ( V_5 -> V_20 , L_1 ) ;
V_16 = F_5 ( V_5 ) ;
V_16 &= ~ ( V_21
| V_22
| V_23 ) ;
V_16 |= V_24
| V_25 ;
F_6 ( V_5 , V_16 ) ;
break;
case V_26 :
F_14 ( V_5 -> V_20 , L_2 ) ;
V_16 = F_5 ( V_5 ) ;
V_16 &= ~ V_23 ;
V_16 |= V_21
| V_22
| V_24
| V_25 ;
F_6 ( V_5 , V_16 ) ;
break;
case V_27 :
case V_28 :
F_14 ( V_5 -> V_20 , L_3 ) ;
V_16 = F_5 ( V_5 ) ;
V_16 &= ~ ( V_24
| V_22
| V_25 ) ;
V_16 |= V_23
| V_21 ;
F_6 ( V_5 , V_16 ) ;
break;
default:
F_14 ( V_5 -> V_20 , L_4 ) ;
}
return 0 ;
}
static T_3 F_15 ( int V_29 , void * V_17 )
{
struct V_4 * V_5 = V_17 ;
T_1 V_30 ;
F_16 ( & V_5 -> V_31 ) ;
V_30 = F_9 ( V_5 ) ;
if ( V_30 & V_32 ) {
F_14 ( V_5 -> V_20 , L_5 ) ;
V_5 -> V_33 = false ;
}
if ( V_30 & V_34 )
F_14 ( V_5 -> V_20 , L_6 ) ;
if ( V_30 & V_35 )
F_14 ( V_5 -> V_20 , L_7 ) ;
if ( V_30 & V_36 )
F_14 ( V_5 -> V_20 , L_8 ) ;
if ( V_30 & V_37 )
F_14 ( V_5 -> V_20 , L_9 ) ;
if ( V_30 & V_38 )
F_14 ( V_5 -> V_20 , L_10 ) ;
if ( V_30 & V_39 )
F_14 ( V_5 -> V_20 , L_11 ) ;
if ( V_30 & V_40 )
F_14 ( V_5 -> V_20 , L_12 ) ;
if ( V_30 & V_41 )
F_14 ( V_5 -> V_20 , L_13 ) ;
if ( V_30 & V_42 )
F_14 ( V_5 -> V_20 , L_14 ) ;
F_10 ( V_5 , V_30 ) ;
V_30 = F_7 ( V_5 ) ;
F_8 ( V_5 , V_30 ) ;
F_17 ( & V_5 -> V_31 ) ;
return V_43 ;
}
static int F_18 ( struct V_44 * V_20 , void * V_45 )
{
struct V_46 * V_47 = F_19 ( V_20 ) ;
F_20 ( V_47 ) ;
return 0 ;
}
static void F_21 ( struct V_4 * V_5 )
{
T_1 V_30 ;
V_30 = V_48 ;
F_12 ( V_5 , V_30 ) ;
V_30 = ( V_34 |
V_35 |
V_36 |
V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
V_42 ) ;
F_11 ( V_5 , V_30 ) ;
}
static void F_22 ( struct V_4 * V_5 )
{
F_11 ( V_5 , 0x00 ) ;
F_12 ( V_5 , 0x00 ) ;
}
static int F_23 ( struct V_46 * V_47 )
{
struct V_49 * V_50 = V_47 -> V_20 . V_51 ;
struct V_4 * V_5 ;
struct V_52 * V_53 ;
struct V_44 * V_20 = & V_47 -> V_20 ;
int V_54 = - V_55 ;
int V_29 ;
int V_56 = 0 ;
int V_57 ;
T_1 V_30 ;
void T_2 * V_1 ;
if ( ! V_50 ) {
F_24 ( V_20 , L_15 ) ;
return - V_58 ;
}
V_5 = F_25 ( V_20 , sizeof( * V_5 ) , V_59 ) ;
if ( ! V_5 ) {
F_24 ( V_20 , L_16 ) ;
return - V_55 ;
}
F_26 ( V_47 , V_5 ) ;
V_29 = F_27 ( V_47 , 0 ) ;
if ( V_29 < 0 ) {
F_24 ( V_20 , L_17 ) ;
return - V_58 ;
}
V_53 = F_28 ( V_47 , V_60 , 0 ) ;
if ( ! V_53 ) {
F_24 ( V_20 , L_18 ) ;
return - V_58 ;
}
V_1 = F_29 ( V_20 , V_53 -> V_61 , F_30 ( V_53 ) ) ;
if ( ! V_1 ) {
F_24 ( V_20 , L_19 ) ;
return - V_55 ;
}
F_31 ( & V_5 -> V_31 ) ;
V_5 -> V_20 = V_20 ;
V_5 -> V_29 = V_29 ;
V_5 -> V_1 = V_1 ;
V_20 -> V_62 = & V_63 ;
V_17 = V_5 ;
F_32 ( V_20 ) ;
V_54 = F_33 ( V_20 ) ;
if ( V_54 < 0 ) {
F_24 ( V_20 , L_20 , V_54 ) ;
goto V_64;
}
V_30 = F_1 ( V_5 -> V_1 , V_65 ) ;
V_5 -> V_66 = V_30 ;
V_57 = F_34 ( V_30 ) ;
switch ( V_57 ) {
case V_67 :
case V_68 :
V_5 -> V_69 = 0 ;
V_5 -> V_9 = 0 ;
V_5 -> V_11 = 0 ;
V_5 -> V_7 = 0 ;
V_5 -> V_70 = 0 ;
break;
default:
V_5 -> V_69 = V_71 ;
V_5 -> V_9 = V_72 ;
V_5 -> V_11 = V_73 ;
V_5 -> V_7 = V_74 ;
V_5 -> V_70 = V_75 ;
break;
}
if ( F_35 ( V_50 , L_21 ) ) {
V_5 -> V_69 = V_71 ;
V_5 -> V_9 = V_72 ;
V_5 -> V_11 = V_73 ;
V_5 -> V_7 = V_74 ;
V_5 -> V_70 = V_75 ;
}
V_30 = F_5 ( V_5 ) ;
F_36 ( V_50 , L_22 , & V_56 ) ;
switch ( V_56 ) {
case V_76 :
V_30 |= V_77 ;
break;
case V_78 :
V_30 &= ~ V_77 ;
break;
default:
F_14 ( V_20 , L_23 , V_56 ) ;
}
F_6 ( V_5 , V_30 ) ;
V_30 = F_1 ( V_5 -> V_1 , V_79 ) ;
V_5 -> V_33 = ! ! ( V_30 & V_80 ) ;
V_54 = F_37 ( V_20 , V_5 -> V_29 , F_15 , 0 ,
L_24 , V_5 ) ;
if ( V_54 ) {
F_24 ( V_20 , L_25 ,
V_5 -> V_29 , V_54 ) ;
goto V_81;
}
F_21 ( V_5 ) ;
V_54 = F_38 ( V_50 , NULL , NULL , V_20 ) ;
if ( V_54 ) {
F_24 ( & V_47 -> V_20 , L_26 ) ;
goto V_82;
}
return 0 ;
V_82:
F_22 ( V_5 ) ;
V_81:
F_39 ( V_20 ) ;
V_64:
F_40 ( V_20 ) ;
return V_54 ;
}
static int F_41 ( struct V_46 * V_47 )
{
struct V_4 * V_5 = F_42 ( V_47 ) ;
F_22 ( V_5 ) ;
F_39 ( & V_47 -> V_20 ) ;
F_40 ( & V_47 -> V_20 ) ;
F_43 ( & V_47 -> V_20 , NULL , F_18 ) ;
return 0 ;
}
static int F_44 ( struct V_44 * V_20 )
{
struct V_4 * V_5 = F_45 ( V_20 ) ;
F_22 ( V_5 ) ;
return 0 ;
}
static void F_46 ( struct V_44 * V_20 )
{
struct V_4 * V_5 = F_45 ( V_20 ) ;
F_21 ( V_5 ) ;
}
static int F_47 ( struct V_44 * V_20 )
{
struct V_4 * V_5 = F_45 ( V_20 ) ;
V_5 -> V_83 = F_5 ( V_5 ) ;
return 0 ;
}
static int F_48 ( struct V_44 * V_20 )
{
struct V_4 * V_5 = F_45 ( V_20 ) ;
F_6 ( V_5 , V_5 -> V_83 ) ;
F_40 ( V_20 ) ;
F_49 ( V_20 ) ;
F_32 ( V_20 ) ;
return 0 ;
}
