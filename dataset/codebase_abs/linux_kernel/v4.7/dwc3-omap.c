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
static void F_13 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_14 +
V_5 -> V_11 , V_3 ) ;
}
static void F_14 ( struct V_4 * V_5 , T_1 V_3 )
{
F_3 ( V_5 -> V_1 , V_15 -
V_5 -> V_9 , V_3 ) ;
}
static void F_15 ( struct V_4 * V_5 ,
enum V_16 V_17 )
{
int V_18 ;
T_1 V_19 ;
switch ( V_17 ) {
case V_20 :
if ( V_5 -> V_21 ) {
V_18 = F_16 ( V_5 -> V_21 ) ;
if ( V_18 ) {
F_17 ( V_5 -> V_22 , L_1 ) ;
return;
}
}
V_19 = F_5 ( V_5 ) ;
V_19 &= ~ ( V_23
| V_24
| V_25 ) ;
V_19 |= V_26
| V_27 ;
F_6 ( V_5 , V_19 ) ;
break;
case V_28 :
V_19 = F_5 ( V_5 ) ;
V_19 &= ~ V_25 ;
V_19 |= V_23
| V_24
| V_26
| V_27 ;
F_6 ( V_5 , V_19 ) ;
break;
case V_29 :
if ( V_5 -> V_21 )
F_18 ( V_5 -> V_21 ) ;
case V_30 :
V_19 = F_5 ( V_5 ) ;
V_19 &= ~ ( V_26
| V_24
| V_27 ) ;
V_19 |= V_25
| V_23 ;
F_6 ( V_5 , V_19 ) ;
break;
default:
F_19 ( V_5 -> V_22 , L_2 ) ;
}
}
static T_3 F_20 ( int V_31 , void * V_32 )
{
struct V_4 * V_5 = V_32 ;
T_1 V_33 ;
V_33 = F_9 ( V_5 ) ;
F_10 ( V_5 , V_33 ) ;
V_33 = F_7 ( V_5 ) ;
F_8 ( V_5 , V_33 ) ;
return V_34 ;
}
static void F_21 ( struct V_4 * V_5 )
{
T_1 V_33 ;
V_33 = V_35 ;
F_12 ( V_5 , V_33 ) ;
V_33 = ( V_36 |
V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
V_42 |
V_43 |
V_44 ) ;
F_11 ( V_5 , V_33 ) ;
}
static void F_22 ( struct V_4 * V_5 )
{
T_1 V_33 ;
V_33 = V_35 ;
F_14 ( V_5 , V_33 ) ;
V_33 = ( V_36 |
V_37 |
V_38 |
V_39 |
V_40 |
V_41 |
V_42 |
V_43 |
V_44 ) ;
F_13 ( V_5 , V_33 ) ;
}
static int F_23 ( struct V_45 * V_46 ,
unsigned long V_47 , void * V_48 )
{
struct V_4 * V_5 = F_24 ( V_46 , struct V_4 , V_49 ) ;
if ( V_47 )
F_15 ( V_5 , V_20 ) ;
else
F_15 ( V_5 , V_29 ) ;
return V_50 ;
}
static int F_25 ( struct V_45 * V_46 ,
unsigned long V_47 , void * V_48 )
{
struct V_4 * V_5 = F_24 ( V_46 , struct V_4 , V_51 ) ;
if ( V_47 )
F_15 ( V_5 , V_28 ) ;
else
F_15 ( V_5 , V_30 ) ;
return V_50 ;
}
static void F_26 ( struct V_4 * V_5 )
{
struct V_52 * V_53 = V_5 -> V_22 -> V_54 ;
if ( F_27 ( V_53 , L_3 ) ) {
V_5 -> V_55 = V_56 ;
V_5 -> V_9 = V_57 ;
V_5 -> V_11 = V_58 ;
V_5 -> V_7 = V_59 ;
V_5 -> V_60 = V_61 ;
}
}
static void F_28 ( struct V_4 * V_5 )
{
T_1 V_33 ;
struct V_52 * V_53 = V_5 -> V_22 -> V_54 ;
int V_62 = 0 ;
V_33 = F_5 ( V_5 ) ;
F_29 ( V_53 , L_4 , & V_62 ) ;
switch ( V_62 ) {
case V_63 :
V_33 |= V_64 ;
break;
case V_65 :
V_33 &= ~ V_64 ;
break;
default:
F_19 ( V_5 -> V_22 , L_5 , V_62 ) ;
}
F_6 ( V_5 , V_33 ) ;
}
static int F_30 ( struct V_4 * V_5 )
{
int V_18 ;
struct V_52 * V_53 = V_5 -> V_22 -> V_54 ;
struct V_66 * V_67 ;
if ( F_31 ( V_53 , L_6 ) ) {
V_67 = F_32 ( V_5 -> V_22 , 0 ) ;
if ( F_33 ( V_67 ) ) {
F_34 ( V_5 -> V_22 , L_7 ) ;
return - V_68 ;
}
V_5 -> V_51 . V_69 = F_25 ;
V_18 = F_35 ( V_67 , V_70 ,
& V_5 -> V_51 ) ;
if ( V_18 < 0 )
F_34 ( V_5 -> V_22 , L_8 ) ;
V_5 -> V_49 . V_69 = F_23 ;
V_18 = F_35 ( V_67 , V_71 ,
& V_5 -> V_49 ) ;
if ( V_18 < 0 )
F_34 ( V_5 -> V_22 , L_9 ) ;
if ( F_36 ( V_67 , V_70 ) == true )
F_15 ( V_5 , V_28 ) ;
if ( F_36 ( V_67 , V_71 ) == true )
F_15 ( V_5 , V_20 ) ;
V_5 -> V_67 = V_67 ;
}
return 0 ;
}
static int F_37 ( struct V_72 * V_73 )
{
struct V_52 * V_53 = V_73 -> V_22 . V_54 ;
struct V_4 * V_5 ;
struct V_74 * V_75 ;
struct V_76 * V_22 = & V_73 -> V_22 ;
struct V_77 * V_21 = NULL ;
int V_18 ;
int V_31 ;
T_1 V_33 ;
void T_2 * V_1 ;
if ( ! V_53 ) {
F_17 ( V_22 , L_10 ) ;
return - V_78 ;
}
V_5 = F_38 ( V_22 , sizeof( * V_5 ) , V_79 ) ;
if ( ! V_5 )
return - V_80 ;
F_39 ( V_73 , V_5 ) ;
V_31 = F_40 ( V_73 , 0 ) ;
if ( V_31 < 0 ) {
F_17 ( V_22 , L_11 ) ;
return - V_78 ;
}
V_75 = F_41 ( V_73 , V_81 , 0 ) ;
V_1 = F_42 ( V_22 , V_75 ) ;
if ( F_33 ( V_1 ) )
return F_43 ( V_1 ) ;
if ( F_31 ( V_53 , L_12 ) ) {
V_21 = F_44 ( V_22 , L_13 ) ;
if ( F_33 ( V_21 ) ) {
F_17 ( V_22 , L_14 ) ;
return F_43 ( V_21 ) ;
}
}
V_5 -> V_22 = V_22 ;
V_5 -> V_31 = V_31 ;
V_5 -> V_1 = V_1 ;
V_5 -> V_21 = V_21 ;
F_45 ( V_22 ) ;
V_18 = F_46 ( V_22 ) ;
if ( V_18 < 0 ) {
F_17 ( V_22 , L_15 , V_18 ) ;
goto V_82;
}
F_26 ( V_5 ) ;
F_28 ( V_5 ) ;
V_33 = F_1 ( V_5 -> V_1 , V_83 ) ;
V_18 = F_47 ( V_22 , V_5 -> V_31 , F_20 , 0 ,
L_16 , V_5 ) ;
if ( V_18 ) {
F_17 ( V_22 , L_17 ,
V_5 -> V_31 , V_18 ) ;
goto V_82;
}
V_18 = F_30 ( V_5 ) ;
if ( V_18 < 0 )
goto V_82;
V_18 = F_48 ( V_53 , NULL , NULL , V_22 ) ;
if ( V_18 ) {
F_17 ( & V_73 -> V_22 , L_18 ) ;
goto V_84;
}
F_21 ( V_5 ) ;
return 0 ;
V_84:
F_49 ( V_5 -> V_67 , V_70 , & V_5 -> V_51 ) ;
F_49 ( V_5 -> V_67 , V_71 , & V_5 -> V_49 ) ;
V_82:
F_50 ( V_22 ) ;
F_51 ( V_22 ) ;
return V_18 ;
}
static int F_52 ( struct V_72 * V_73 )
{
struct V_4 * V_5 = F_53 ( V_73 ) ;
F_49 ( V_5 -> V_67 , V_70 , & V_5 -> V_51 ) ;
F_49 ( V_5 -> V_67 , V_71 , & V_5 -> V_49 ) ;
F_22 ( V_5 ) ;
F_54 ( V_5 -> V_22 ) ;
F_50 ( & V_73 -> V_22 ) ;
F_51 ( & V_73 -> V_22 ) ;
return 0 ;
}
static int F_55 ( struct V_76 * V_22 )
{
struct V_4 * V_5 = F_56 ( V_22 ) ;
V_5 -> V_85 = F_5 ( V_5 ) ;
F_22 ( V_5 ) ;
return 0 ;
}
static int F_57 ( struct V_76 * V_22 )
{
struct V_4 * V_5 = F_56 ( V_22 ) ;
F_6 ( V_5 , V_5 -> V_85 ) ;
F_21 ( V_5 ) ;
F_51 ( V_22 ) ;
F_58 ( V_22 ) ;
F_45 ( V_22 ) ;
return 0 ;
}
