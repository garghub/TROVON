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
switch ( V_3 ) {
case V_17 :
V_5 -> V_18 = V_16 ;
return;
case V_19 :
F_6 ( ( V_16 << 16 ) | V_5 -> V_18 ,
V_2 -> V_15 + V_17 ) ;
return;
}
F_7 ( V_16 , V_2 -> V_15 + V_3 ) ;
}
static void F_8 ( struct V_1 * V_2 , T_2 V_16 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_9 * V_10 = V_7 -> V_10 ;
if ( F_3 ( V_3 == V_20 ) )
V_16 &= ~ ( V_21 | V_22 ) ;
F_6 ( V_16 , V_2 -> V_15 + V_3 ) ;
if ( F_3 ( ( V_10 -> V_11 & V_23 ) &&
( V_3 == V_24 ) ) ) {
T_3 V_25 = F_9 ( V_2 -> V_15 + V_26 ) ;
if ( V_16 & V_27 )
V_25 |= 0x8 ;
else
V_25 &= ~ 0x8 ;
F_10 ( V_25 , V_2 -> V_15 + V_26 ) ;
}
}
static unsigned int F_11 ( struct V_1 * V_2 )
{
return F_12 ( V_2 -> V_28 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_3 V_29 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
const struct V_9 * V_10 = V_7 -> V_10 ;
T_2 V_30 , V_31 ;
F_14 ( V_2 , V_29 ) ;
if ( ! ( V_29 & V_32 ) )
return;
V_30 = F_15 ( V_2 , V_33 ) ;
if ( V_10 -> V_11 & V_34 )
V_30 |= V_35 ;
if ( V_10 -> V_11 & V_36 )
V_30 |= V_37 ;
if ( V_10 -> V_11 & V_38 )
V_30 |= V_39 ;
if ( V_10 -> V_11 & V_40 )
V_30 |= V_41 ;
F_16 ( V_2 , V_30 , V_33 ) ;
V_31 = F_15 ( V_2 , V_42 ) ;
V_31 &= ~ V_43 ;
if ( V_10 -> V_11 & V_37 )
V_31 |= V_44 ;
F_16 ( V_2 , V_31 , V_42 ) ;
V_7 -> V_45 = false ;
}
static void F_17 ( struct V_1 * V_2 , int V_46 )
{
T_2 V_47 ;
V_47 = F_18 ( V_2 , V_48 ) ;
if ( ( V_2 -> V_28 -> V_49 & V_50 ) &&
( V_46 == V_51 ) ) {
V_47 &= ~ V_52 ;
V_47 |= V_53 ;
} else {
V_47 &= ~ V_53 ;
if ( V_46 == V_54 )
V_47 |= V_52 ;
else
V_47 &= ~ V_52 ;
}
F_19 ( V_2 , V_47 , V_48 ) ;
}
static void F_20 ( struct V_1 * V_2 , unsigned int clock )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
unsigned long V_55 ;
if ( ! clock )
return;
V_55 = V_7 -> V_45 ? clock * 2 : clock ;
F_21 ( V_5 -> V_56 , V_55 ) ;
V_2 -> V_57 = F_22 ( V_5 -> V_56 ) ;
return F_23 ( V_2 , clock ) ;
}
static void F_24 ( struct V_1 * V_2 ,
unsigned V_58 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
if ( V_58 == V_59 )
V_7 -> V_45 = true ;
return F_25 ( V_2 , V_58 ) ;
}
static unsigned int F_26 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_27 ( V_5 -> V_56 , V_60 ) / 2 ;
}
static void F_28 ( struct V_1 * V_2 , unsigned int V_61 )
{
T_2 V_3 ;
V_3 = F_15 ( V_2 , V_42 ) ;
V_3 &= ~ V_62 ;
V_3 |= V_61 << V_63 ;
F_16 ( V_2 , V_3 , V_42 ) ;
}
static int F_29 ( struct V_1 * V_2 , T_2 V_64 )
{
unsigned int V_65 , V_66 ;
V_65 = 10 ;
while ( V_65 < 255 ) {
F_28 ( V_2 , V_65 ) ;
if ( ! F_30 ( V_2 -> V_28 , V_64 , NULL ) )
break;
V_65 ++ ;
}
V_66 = V_65 + 1 ;
while ( V_66 < 255 ) {
F_28 ( V_2 , V_66 ) ;
if ( F_30 ( V_2 -> V_28 , V_64 , NULL ) ) {
V_66 -- ;
break;
}
V_66 ++ ;
}
F_28 ( V_2 , V_65 + ( ( V_66 - V_65 ) * 3 / 4 ) ) ;
return F_30 ( V_2 -> V_28 , V_64 , NULL ) ;
}
static int F_31 ( struct V_67 * V_68 )
{
const struct V_69 * V_70 ;
const struct V_9 * V_10 ;
struct V_1 * V_2 ;
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_56 * V_56 ;
int V_71 ;
V_70 = F_32 ( V_72 , & V_68 -> V_73 ) ;
if ( ! V_70 )
return - V_74 ;
V_10 = V_70 -> V_75 ;
V_2 = F_33 ( V_68 , V_10 -> V_76 , 0 ) ;
if ( F_34 ( V_2 ) )
return F_35 ( V_2 ) ;
V_5 = F_2 ( V_2 ) ;
V_7 = F_36 ( & V_68 -> V_73 , sizeof( * V_7 ) , V_77 ) ;
if ( ! V_7 ) {
F_37 ( F_38 ( V_2 -> V_28 ) , L_1 ) ;
V_71 = - V_78 ;
goto V_79;
}
V_7 -> V_45 = false ;
V_7 -> V_10 = V_10 ;
V_5 -> V_8 = V_7 ;
V_71 = F_39 ( V_2 -> V_28 ) ;
if ( V_71 )
goto V_80;
if ( V_7 -> V_10 -> V_11 & V_38 )
V_2 -> V_28 -> V_49 |= V_81 ;
V_7 -> V_82 = F_40 ( & V_68 -> V_73 , L_2 ,
V_83 ) ;
if ( F_34 ( V_7 -> V_82 ) ) {
V_71 = F_35 ( V_7 -> V_82 ) ;
goto V_84;
}
V_56 = F_41 ( F_38 ( V_2 -> V_28 ) , NULL ) ;
if ( F_34 ( V_56 ) ) {
F_37 ( F_38 ( V_2 -> V_28 ) , L_3 ) ;
V_71 = F_35 ( V_56 ) ;
goto V_85;
}
F_42 ( V_56 ) ;
V_5 -> V_56 = V_56 ;
V_71 = F_43 ( V_2 ) ;
if ( V_71 )
goto V_86;
return 0 ;
V_86:
F_44 ( V_5 -> V_56 ) ;
V_85:
V_84:
V_80:
V_79:
F_45 ( V_68 ) ;
return V_71 ;
}
