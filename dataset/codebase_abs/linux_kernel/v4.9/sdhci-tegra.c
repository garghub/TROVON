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
static void F_19 ( struct V_1 * V_2 , int V_49 )
{
T_2 V_50 ;
V_50 = F_20 ( V_2 , V_51 ) ;
if ( ( V_2 -> V_27 -> V_52 & V_53 ) &&
( V_49 == V_54 ) ) {
V_50 &= ~ V_55 ;
V_50 |= V_56 ;
} else {
V_50 &= ~ V_56 ;
if ( V_49 == V_57 )
V_50 |= V_55 ;
else
V_50 &= ~ V_55 ;
}
F_21 ( V_2 , V_50 , V_51 ) ;
}
static void F_22 ( struct V_1 * V_2 )
{
T_2 V_15 ;
F_23 ( 1 ) ;
V_15 = F_16 ( V_2 , V_58 ) ;
V_15 |= V_59 | V_60 ;
F_18 ( V_2 , V_15 , V_58 ) ;
}
static void F_24 ( struct V_1 * V_2 , unsigned int clock )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
unsigned long V_61 ;
if ( ! clock )
return F_25 ( V_2 , clock ) ;
V_61 = V_7 -> V_48 ? clock * 2 : clock ;
F_26 ( V_5 -> V_62 , V_61 ) ;
V_2 -> V_63 = F_27 ( V_5 -> V_62 ) ;
F_25 ( V_2 , clock ) ;
if ( V_7 -> V_47 ) {
F_22 ( V_2 ) ;
V_7 -> V_47 = false ;
}
}
static void F_28 ( struct V_1 * V_2 ,
unsigned V_64 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
if ( V_64 == V_65 )
V_7 -> V_48 = true ;
return F_29 ( V_2 , V_64 ) ;
}
static unsigned int F_30 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_31 ( V_5 -> V_62 , V_66 ) / 2 ;
}
static void F_32 ( struct V_1 * V_2 , unsigned int V_67 )
{
T_2 V_3 ;
V_3 = F_16 ( V_2 , V_33 ) ;
V_3 &= ~ V_68 ;
V_3 |= V_67 << V_69 ;
F_18 ( V_2 , V_3 , V_33 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_2 V_70 )
{
unsigned int V_71 , V_72 ;
V_71 = 10 ;
while ( V_71 < 255 ) {
F_32 ( V_2 , V_71 ) ;
if ( ! F_34 ( V_2 -> V_27 , V_70 , NULL ) )
break;
V_71 ++ ;
}
V_72 = V_71 + 1 ;
while ( V_72 < 255 ) {
F_32 ( V_2 , V_72 ) ;
if ( F_34 ( V_2 -> V_27 , V_70 , NULL ) ) {
V_72 -- ;
break;
}
V_72 ++ ;
}
F_32 ( V_2 , V_71 + ( ( V_72 - V_71 ) * 3 / 4 ) ) ;
return F_34 ( V_2 -> V_27 , V_70 , NULL ) ;
}
static void F_35 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_5 ) ;
const struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_9 -> V_10 & V_46 )
V_7 -> V_47 = true ;
}
static int F_36 ( struct V_73 * V_74 )
{
const struct V_75 * V_76 ;
const struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_62 * V_62 ;
int V_77 ;
V_76 = F_37 ( V_78 , & V_74 -> V_79 ) ;
if ( ! V_76 )
return - V_80 ;
V_9 = V_76 -> V_81 ;
V_2 = F_38 ( V_74 , V_9 -> V_82 , sizeof( * V_7 ) ) ;
if ( F_17 ( V_2 ) )
return F_39 ( V_2 ) ;
V_5 = F_2 ( V_2 ) ;
V_7 = F_3 ( V_5 ) ;
V_7 -> V_48 = false ;
V_7 -> V_47 = false ;
V_7 -> V_9 = V_9 ;
V_77 = F_40 ( V_2 -> V_27 ) ;
if ( V_77 )
goto V_83;
if ( V_7 -> V_9 -> V_10 & V_43 )
V_2 -> V_27 -> V_52 |= V_84 ;
V_7 -> V_85 = F_41 ( & V_74 -> V_79 , L_1 ,
V_86 ) ;
if ( F_17 ( V_7 -> V_85 ) ) {
V_77 = F_39 ( V_7 -> V_85 ) ;
goto V_87;
}
V_62 = F_42 ( F_43 ( V_2 -> V_27 ) , NULL ) ;
if ( F_17 ( V_62 ) ) {
F_44 ( F_43 ( V_2 -> V_27 ) , L_2 ) ;
V_77 = F_39 ( V_62 ) ;
goto V_88;
}
F_45 ( V_62 ) ;
V_5 -> V_62 = V_62 ;
V_77 = F_46 ( V_2 ) ;
if ( V_77 )
goto V_89;
return 0 ;
V_89:
F_47 ( V_5 -> V_62 ) ;
V_88:
V_87:
V_83:
F_48 ( V_74 ) ;
return V_77 ;
}
