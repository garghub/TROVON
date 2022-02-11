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
if ( V_9 -> V_10 & V_33 )
V_29 |= V_34 ;
if ( V_9 -> V_10 & V_35 )
V_29 |= V_36 ;
else
V_29 &= ~ V_36 ;
if ( V_9 -> V_10 & V_37 )
V_29 |= V_38 ;
else
V_29 &= ~ V_38 ;
if ( V_9 -> V_10 & V_39 )
V_29 |= V_40 ;
else
V_29 &= ~ V_40 ;
F_17 ( V_2 , V_29 , V_32 ) ;
V_30 = F_16 ( V_2 , V_41 ) ;
V_30 &= ~ V_42 ;
if ( V_9 -> V_10 & V_36 )
V_30 |= V_43 ;
F_17 ( V_2 , V_30 , V_41 ) ;
if ( V_9 -> V_10 & V_44 )
V_7 -> V_45 = true ;
V_7 -> V_46 = false ;
}
static void F_18 ( struct V_1 * V_2 , int V_47 )
{
T_2 V_48 ;
V_48 = F_19 ( V_2 , V_49 ) ;
if ( ( V_2 -> V_27 -> V_50 & V_51 ) &&
( V_47 == V_52 ) ) {
V_48 &= ~ V_53 ;
V_48 |= V_54 ;
} else {
V_48 &= ~ V_54 ;
if ( V_47 == V_55 )
V_48 |= V_53 ;
else
V_48 &= ~ V_53 ;
}
F_20 ( V_2 , V_48 , V_49 ) ;
}
static void F_21 ( struct V_1 * V_2 )
{
T_2 V_15 ;
F_22 ( 1 ) ;
V_15 = F_16 ( V_2 , V_56 ) ;
V_15 |= V_57 | V_58 ;
F_17 ( V_2 , V_15 , V_56 ) ;
}
static void F_23 ( struct V_1 * V_2 , unsigned int clock )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
unsigned long V_59 ;
if ( ! clock )
return F_24 ( V_2 , clock ) ;
V_59 = V_7 -> V_46 ? clock * 2 : clock ;
F_25 ( V_5 -> V_60 , V_59 ) ;
V_2 -> V_61 = F_26 ( V_5 -> V_60 ) ;
F_24 ( V_2 , clock ) ;
if ( V_7 -> V_45 ) {
F_21 ( V_2 ) ;
V_7 -> V_45 = false ;
}
}
static void F_27 ( struct V_1 * V_2 ,
unsigned V_62 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
if ( V_62 == V_63 )
V_7 -> V_46 = true ;
return F_28 ( V_2 , V_62 ) ;
}
static unsigned int F_29 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_30 ( V_5 -> V_60 , V_64 ) / 2 ;
}
static void F_31 ( struct V_1 * V_2 , unsigned int V_65 )
{
T_2 V_3 ;
V_3 = F_16 ( V_2 , V_41 ) ;
V_3 &= ~ V_66 ;
V_3 |= V_65 << V_67 ;
F_17 ( V_2 , V_3 , V_41 ) ;
}
static int F_32 ( struct V_1 * V_2 , T_2 V_68 )
{
unsigned int V_69 , V_70 ;
V_69 = 10 ;
while ( V_69 < 255 ) {
F_31 ( V_2 , V_69 ) ;
if ( ! F_33 ( V_2 -> V_27 , V_68 , NULL ) )
break;
V_69 ++ ;
}
V_70 = V_69 + 1 ;
while ( V_70 < 255 ) {
F_31 ( V_2 , V_70 ) ;
if ( F_33 ( V_2 -> V_27 , V_68 , NULL ) ) {
V_70 -- ;
break;
}
V_70 ++ ;
}
F_31 ( V_2 , V_69 + ( ( V_70 - V_69 ) * 3 / 4 ) ) ;
return F_33 ( V_2 -> V_27 , V_68 , NULL ) ;
}
static void F_34 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
const struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_9 -> V_10 & V_44 )
V_7 -> V_45 = true ;
}
static int F_35 ( struct V_71 * V_72 )
{
const struct V_73 * V_74 ;
const struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_60 * V_60 ;
int V_75 ;
V_74 = F_36 ( V_76 , & V_72 -> V_77 ) ;
if ( ! V_74 )
return - V_78 ;
V_9 = V_74 -> V_79 ;
V_2 = F_37 ( V_72 , V_9 -> V_80 , sizeof( * V_7 ) ) ;
if ( F_38 ( V_2 ) )
return F_39 ( V_2 ) ;
V_5 = F_2 ( V_2 ) ;
V_7 = F_3 ( V_5 ) ;
V_7 -> V_46 = false ;
V_7 -> V_45 = false ;
V_7 -> V_9 = V_9 ;
V_75 = F_40 ( V_2 -> V_27 ) ;
if ( V_75 )
goto V_81;
if ( V_7 -> V_9 -> V_10 & V_37 )
V_2 -> V_27 -> V_50 |= V_82 ;
V_7 -> V_83 = F_41 ( & V_72 -> V_77 , L_1 ,
V_84 ) ;
if ( F_38 ( V_7 -> V_83 ) ) {
V_75 = F_39 ( V_7 -> V_83 ) ;
goto V_85;
}
V_60 = F_42 ( F_43 ( V_2 -> V_27 ) , NULL ) ;
if ( F_38 ( V_60 ) ) {
F_44 ( F_43 ( V_2 -> V_27 ) , L_2 ) ;
V_75 = F_39 ( V_60 ) ;
goto V_86;
}
F_45 ( V_60 ) ;
V_5 -> V_60 = V_60 ;
V_75 = F_46 ( V_2 ) ;
if ( V_75 )
goto V_87;
return 0 ;
V_87:
F_47 ( V_5 -> V_60 ) ;
V_86:
V_85:
V_81:
F_48 ( V_72 ) ;
return V_75 ;
}
