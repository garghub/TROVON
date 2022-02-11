static inline T_1 F_1 ( void T_2 * V_1 , T_1 V_2 )
{
return F_2 ( V_1 + V_2 ) ;
}
static inline void F_3 ( void T_2 * V_1 , T_1 V_2 , T_1 V_3 )
{
F_4 ( V_3 , V_1 + V_2 ) ;
}
int F_5 ( enum V_4 V_5 )
{
T_1 V_6 ;
struct V_7 * V_8 = V_9 ;
if ( ! V_8 )
return - V_10 ;
switch ( V_5 ) {
case V_11 :
F_6 ( V_8 -> V_12 , L_1 ) ;
V_6 = F_1 ( V_8 -> V_1 , V_13 ) ;
V_6 &= ~ ( V_14
| V_15
| V_16 ) ;
V_6 |= V_17
| V_18 ;
F_3 ( V_8 -> V_1 , V_13 , V_6 ) ;
break;
case V_19 :
F_6 ( V_8 -> V_12 , L_2 ) ;
V_6 = F_1 ( V_8 -> V_1 , V_13 ) ;
V_6 &= ~ V_16 ;
V_6 |= V_14
| V_15
| V_17
| V_18 ;
F_3 ( V_8 -> V_1 , V_13 , V_6 ) ;
break;
case V_20 :
case V_21 :
F_6 ( V_8 -> V_12 , L_3 ) ;
V_6 = F_1 ( V_8 -> V_1 , V_13 ) ;
V_6 &= ~ ( V_17
| V_15
| V_18 ) ;
V_6 |= V_16
| V_14 ;
F_3 ( V_8 -> V_1 , V_13 , V_6 ) ;
break;
default:
F_6 ( V_8 -> V_12 , L_4 ) ;
}
return 0 ;
}
static T_3 F_7 ( int V_22 , void * V_9 )
{
struct V_7 * V_8 = V_9 ;
T_1 V_23 ;
F_8 ( & V_8 -> V_24 ) ;
V_23 = F_1 ( V_8 -> V_1 , V_25 ) ;
if ( V_23 & V_26 ) {
F_6 ( V_8 -> V_12 , L_5 ) ;
V_8 -> V_27 = false ;
}
if ( V_23 & V_28 )
F_6 ( V_8 -> V_12 , L_6 ) ;
if ( V_23 & V_29 )
F_6 ( V_8 -> V_12 , L_7 ) ;
if ( V_23 & V_30 )
F_6 ( V_8 -> V_12 , L_8 ) ;
if ( V_23 & V_31 )
F_6 ( V_8 -> V_12 , L_9 ) ;
if ( V_23 & V_32 )
F_6 ( V_8 -> V_12 , L_10 ) ;
if ( V_23 & V_33 )
F_6 ( V_8 -> V_12 , L_11 ) ;
if ( V_23 & V_34 )
F_6 ( V_8 -> V_12 , L_12 ) ;
if ( V_23 & V_35 )
F_6 ( V_8 -> V_12 , L_13 ) ;
if ( V_23 & V_36 )
F_6 ( V_8 -> V_12 , L_14 ) ;
F_3 ( V_8 -> V_1 , V_25 , V_23 ) ;
V_23 = F_1 ( V_8 -> V_1 , V_37 ) ;
F_3 ( V_8 -> V_1 , V_37 , V_23 ) ;
F_9 ( & V_8 -> V_24 ) ;
return V_38 ;
}
static int F_10 ( struct V_39 * V_12 , void * V_40 )
{
struct V_41 * V_42 = F_11 ( V_12 ) ;
F_12 ( V_42 ) ;
return 0 ;
}
static void F_13 ( struct V_7 * V_8 )
{
T_1 V_23 ;
V_23 = V_43 ;
F_3 ( V_8 -> V_1 , V_44 , V_23 ) ;
V_23 = ( V_28 |
V_29 |
V_30 |
V_31 |
V_32 |
V_33 |
V_34 |
V_35 |
V_36 ) ;
F_3 ( V_8 -> V_1 , V_45 , V_23 ) ;
}
static void F_14 ( struct V_7 * V_8 )
{
F_3 ( V_8 -> V_1 , V_45 , 0x00 ) ;
F_3 ( V_8 -> V_1 , V_44 , 0x00 ) ;
}
static int F_15 ( struct V_41 * V_42 )
{
struct V_46 * V_47 = V_42 -> V_12 . V_48 ;
struct V_7 * V_8 ;
struct V_49 * V_50 ;
struct V_39 * V_12 = & V_42 -> V_12 ;
int V_51 = - V_52 ;
int V_22 ;
int V_53 = 0 ;
T_1 V_23 ;
void T_2 * V_1 ;
if ( ! V_47 ) {
F_16 ( V_12 , L_15 ) ;
return - V_54 ;
}
V_8 = F_17 ( V_12 , sizeof( * V_8 ) , V_55 ) ;
if ( ! V_8 ) {
F_16 ( V_12 , L_16 ) ;
return - V_52 ;
}
F_18 ( V_42 , V_8 ) ;
V_22 = F_19 ( V_42 , 0 ) ;
if ( V_22 < 0 ) {
F_16 ( V_12 , L_17 ) ;
return - V_54 ;
}
V_50 = F_20 ( V_42 , V_56 , 0 ) ;
if ( ! V_50 ) {
F_16 ( V_12 , L_18 ) ;
return - V_54 ;
}
V_1 = F_21 ( V_12 , V_50 -> V_57 , F_22 ( V_50 ) ) ;
if ( ! V_1 ) {
F_16 ( V_12 , L_19 ) ;
return - V_52 ;
}
F_23 ( & V_8 -> V_24 ) ;
V_8 -> V_12 = V_12 ;
V_8 -> V_22 = V_22 ;
V_8 -> V_1 = V_1 ;
V_12 -> V_58 = & V_59 ;
V_9 = V_8 ;
F_24 ( V_12 ) ;
V_51 = F_25 ( V_12 ) ;
if ( V_51 < 0 ) {
F_16 ( V_12 , L_20 , V_51 ) ;
return V_51 ;
}
V_23 = F_1 ( V_8 -> V_1 , V_13 ) ;
F_26 ( V_47 , L_21 , & V_53 ) ;
switch ( V_53 ) {
case V_60 :
V_23 |= V_61 ;
break;
case V_62 :
V_23 &= ~ V_61 ;
break;
default:
F_6 ( V_12 , L_22 , V_53 ) ;
}
F_3 ( V_8 -> V_1 , V_13 , V_23 ) ;
V_23 = F_1 ( V_8 -> V_1 , V_63 ) ;
V_8 -> V_27 = ! ! ( V_23 & V_64 ) ;
V_51 = F_27 ( V_12 , V_8 -> V_22 , F_7 , 0 ,
L_23 , V_8 ) ;
if ( V_51 ) {
F_16 ( V_12 , L_24 ,
V_8 -> V_22 , V_51 ) ;
return V_51 ;
}
F_13 ( V_8 ) ;
V_51 = F_28 ( V_47 , NULL , NULL , V_12 ) ;
if ( V_51 ) {
F_16 ( & V_42 -> V_12 , L_25 ) ;
return V_51 ;
}
return 0 ;
}
static int F_29 ( struct V_41 * V_42 )
{
struct V_7 * V_8 = F_30 ( V_42 ) ;
F_14 ( V_8 ) ;
F_31 ( & V_42 -> V_12 ) ;
F_32 ( & V_42 -> V_12 ) ;
F_33 ( & V_42 -> V_12 , NULL , F_10 ) ;
return 0 ;
}
static int F_34 ( struct V_39 * V_12 )
{
struct V_7 * V_8 = F_35 ( V_12 ) ;
F_14 ( V_8 ) ;
return 0 ;
}
static void F_36 ( struct V_39 * V_12 )
{
struct V_7 * V_8 = F_35 ( V_12 ) ;
F_13 ( V_8 ) ;
}
static int F_37 ( struct V_39 * V_12 )
{
struct V_7 * V_8 = F_35 ( V_12 ) ;
V_8 -> V_65 = F_1 ( V_8 -> V_1 ,
V_13 ) ;
return 0 ;
}
static int F_38 ( struct V_39 * V_12 )
{
struct V_7 * V_8 = F_35 ( V_12 ) ;
F_3 ( V_8 -> V_1 , V_13 ,
V_8 -> V_65 ) ;
F_32 ( V_12 ) ;
F_39 ( V_12 ) ;
F_24 ( V_12 ) ;
return 0 ;
}
