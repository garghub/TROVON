static T_1 F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
const struct V_8 * V_9 = V_7 -> V_9 ;
if ( F_4 ( ( V_9 -> V_10 & V_11 ) &&
( V_3 == V_12 ) ) ) {
return V_13 ;
}
return F_5 ( V_2 -> V_14 + V_3 ) ;
}
static void F_6 ( struct V_1 * V_2 , T_1 V_15 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
switch ( V_3 ) {
case V_16 :
V_5 -> V_17 = V_15 ;
return;
case V_18 :
F_7 ( ( V_15 << 16 ) | V_5 -> V_17 ,
V_2 -> V_14 + V_16 ) ;
return;
}
F_8 ( V_15 , V_2 -> V_14 + V_3 ) ;
}
static void F_9 ( struct V_1 * V_2 , T_2 V_15 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
const struct V_8 * V_9 = V_7 -> V_9 ;
if ( F_4 ( V_3 == V_19 ) )
V_15 &= ~ ( V_20 | V_21 ) ;
F_7 ( V_15 , V_2 -> V_14 + V_3 ) ;
if ( F_4 ( ( V_9 -> V_10 & V_22 ) &&
( V_3 == V_23 ) ) ) {
T_3 V_24 = F_10 ( V_2 -> V_14 + V_25 ) ;
if ( V_15 & V_26 )
V_24 |= 0x8 ;
else
V_24 &= ~ 0x8 ;
F_11 ( V_24 , V_2 -> V_14 + V_25 ) ;
}
}
static unsigned int F_12 ( struct V_1 * V_2 )
{
return F_13 ( V_2 -> V_27 ) ;
}
static void F_14 ( struct V_1 * V_2 , T_3 V_28 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
const struct V_8 * V_9 = V_7 -> V_9 ;
T_2 V_29 , V_30 ;
F_15 ( V_2 , V_28 ) ;
if ( ! ( V_28 & V_31 ) )
return;
V_29 = F_16 ( V_2 , V_32 ) ;
V_30 = F_16 ( V_2 , V_33 ) ;
V_29 &= ~ ( V_34 |
V_35 |
V_36 |
V_37 ) ;
V_30 &= ~ V_38 ;
if ( ! F_17 ( V_2 -> V_27 -> V_39 . V_40 ) ) {
if ( V_9 -> V_10 & V_41 )
V_29 |= V_34 ;
if ( V_9 -> V_10 & V_42 )
V_29 |= V_35 ;
if ( V_9 -> V_10 & V_43 )
V_29 |= V_36 ;
if ( V_9 -> V_10 & V_44 )
V_29 |= V_37 ;
if ( V_9 -> V_10 & V_35 )
V_30 |= V_45 ;
}
F_18 ( V_2 , V_29 , V_32 ) ;
F_18 ( V_2 , V_30 , V_33 ) ;
if ( V_9 -> V_10 & V_46 )
V_7 -> V_47 = true ;
V_7 -> V_48 = false ;
}
static void F_19 ( struct V_1 * V_2 )
{
T_2 V_15 ;
F_20 ( 1 ) ;
V_15 = F_16 ( V_2 , V_49 ) ;
V_15 |= V_50 | V_51 ;
F_18 ( V_2 , V_15 , V_49 ) ;
}
static void F_21 ( struct V_1 * V_2 , unsigned int clock )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
unsigned long V_52 ;
if ( ! clock )
return F_22 ( V_2 , clock ) ;
V_52 = V_7 -> V_48 ? clock * 2 : clock ;
F_23 ( V_5 -> V_53 , V_52 ) ;
V_2 -> V_54 = F_24 ( V_5 -> V_53 ) ;
F_22 ( V_2 , clock ) ;
if ( V_7 -> V_47 ) {
F_19 ( V_2 ) ;
V_7 -> V_47 = false ;
}
}
static void F_25 ( struct V_1 * V_2 ,
unsigned V_55 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
if ( V_55 == V_56 )
V_7 -> V_48 = true ;
return F_26 ( V_2 , V_55 ) ;
}
static unsigned int F_27 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_28 ( V_5 -> V_53 , V_57 ) / 2 ;
}
static void F_29 ( struct V_1 * V_2 , unsigned int V_58 )
{
T_2 V_3 ;
V_3 = F_16 ( V_2 , V_33 ) ;
V_3 &= ~ V_59 ;
V_3 |= V_58 << V_60 ;
F_18 ( V_2 , V_3 , V_33 ) ;
}
static int F_30 ( struct V_1 * V_2 , T_2 V_61 )
{
unsigned int V_62 , V_63 ;
V_62 = 10 ;
while ( V_62 < 255 ) {
F_29 ( V_2 , V_62 ) ;
if ( ! F_31 ( V_2 -> V_27 , V_61 , NULL ) )
break;
V_62 ++ ;
}
V_63 = V_62 + 1 ;
while ( V_63 < 255 ) {
F_29 ( V_2 , V_63 ) ;
if ( F_31 ( V_2 -> V_27 , V_61 , NULL ) ) {
V_63 -- ;
break;
}
V_63 ++ ;
}
F_29 ( V_2 , V_62 + ( ( V_63 - V_62 ) * 3 / 4 ) ) ;
return F_31 ( V_2 -> V_27 , V_61 , NULL ) ;
}
static void F_32 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
const struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_9 -> V_10 & V_46 )
V_7 -> V_47 = true ;
}
static int F_33 ( struct V_64 * V_65 )
{
const struct V_66 * V_67 ;
const struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_53 * V_53 ;
int V_68 ;
V_67 = F_34 ( V_69 , & V_65 -> V_70 ) ;
if ( ! V_67 )
return - V_71 ;
V_9 = V_67 -> V_72 ;
V_2 = F_35 ( V_65 , V_9 -> V_73 , sizeof( * V_7 ) ) ;
if ( F_17 ( V_2 ) )
return F_36 ( V_2 ) ;
V_5 = F_2 ( V_2 ) ;
V_7 = F_3 ( V_5 ) ;
V_7 -> V_48 = false ;
V_7 -> V_47 = false ;
V_7 -> V_9 = V_9 ;
V_68 = F_37 ( V_2 -> V_27 ) ;
if ( V_68 )
goto V_74;
if ( V_7 -> V_9 -> V_10 & V_43 )
V_2 -> V_27 -> V_75 |= V_76 ;
V_7 -> V_77 = F_38 ( & V_65 -> V_70 , L_1 ,
V_78 ) ;
if ( F_17 ( V_7 -> V_77 ) ) {
V_68 = F_36 ( V_7 -> V_77 ) ;
goto V_79;
}
V_53 = F_39 ( F_40 ( V_2 -> V_27 ) , NULL ) ;
if ( F_17 ( V_53 ) ) {
F_41 ( F_40 ( V_2 -> V_27 ) , L_2 ) ;
V_68 = F_36 ( V_53 ) ;
goto V_80;
}
F_42 ( V_53 ) ;
V_5 -> V_53 = V_53 ;
V_7 -> V_81 = F_43 ( & V_65 -> V_70 ,
L_3 ) ;
if ( F_17 ( V_7 -> V_81 ) ) {
V_68 = F_36 ( V_7 -> V_81 ) ;
F_41 ( & V_65 -> V_70 , L_4 , V_68 ) ;
goto V_82;
}
V_68 = F_44 ( V_7 -> V_81 ) ;
if ( V_68 )
goto V_82;
F_45 ( 2000 , 4000 ) ;
V_68 = F_46 ( V_7 -> V_81 ) ;
if ( V_68 )
goto V_82;
F_45 ( 2000 , 4000 ) ;
V_68 = F_47 ( V_2 ) ;
if ( V_68 )
goto V_83;
return 0 ;
V_83:
F_44 ( V_7 -> V_81 ) ;
V_82:
F_48 ( V_5 -> V_53 ) ;
V_80:
V_79:
V_74:
F_49 ( V_65 ) ;
return V_68 ;
}
static int F_50 ( struct V_64 * V_65 )
{
struct V_1 * V_2 = F_51 ( V_65 ) ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
F_52 ( V_2 , 0 ) ;
F_44 ( V_7 -> V_81 ) ;
F_45 ( 2000 , 4000 ) ;
F_48 ( V_5 -> V_53 ) ;
F_49 ( V_65 ) ;
return 0 ;
}
