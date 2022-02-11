static int F_1 ( struct V_1 * V_2 , int V_3 , int V_4 )
{
int V_5 ;
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = F_2 ( V_7 ) ;
T_1 V_10 ;
F_3 ( V_8 , ( V_11 | ( V_3 << V_12 ) |
( V_4 << V_13 ) ) , V_14 ) ;
V_10 = F_4 ( V_8 , V_14 ) ;
V_10 |= V_15 ;
F_3 ( V_8 , V_10 , V_14 ) ;
F_5 ( V_8 -> V_16 ,
! ( F_4 ( V_8 , V_14 )
& V_15 ) ,
V_17 / 100 ) ;
V_5 = F_4 ( V_8 , V_14 ) ;
if ( V_5 & V_18 )
return - V_19 ;
return V_5 & 0xffff ;
}
static int F_6 ( struct V_1 * V_2 , int V_3 ,
int V_4 , T_2 V_20 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_8 = F_2 ( V_7 ) ;
T_1 V_10 ;
F_3 ( V_8 , ( V_21 | ( V_3 << V_12 ) |
( V_4 << V_13 ) | ( 0xffff & V_20 ) ) ,
V_14 ) ;
V_10 = F_4 ( V_8 , V_14 ) ;
V_10 |= V_15 ;
F_3 ( V_8 , V_10 , V_14 ) ;
F_5 ( V_8 -> V_16 ,
! ( F_4 ( V_8 , V_14 ) &
V_15 ) ,
V_17 / 100 ) ;
return 0 ;
}
static void F_7 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_22 * V_23 = V_8 -> V_23 ;
T_1 V_10 , V_24 = 0 ;
unsigned int V_25 = 0 ;
if ( V_8 -> V_26 != V_23 -> V_27 ) {
V_25 = 1 ;
V_8 -> V_26 = V_23 -> V_27 ;
}
if ( V_23 -> V_27 ) {
V_10 = F_8 ( V_8 , V_28 ) ;
V_10 &= ~ V_29 ;
V_10 |= V_30 ;
F_9 ( V_8 , V_10 , V_28 ) ;
if ( V_23 -> V_31 == V_32 )
V_24 = V_33 ;
else if ( V_23 -> V_31 == V_34 )
V_24 = V_35 ;
else
V_24 = V_36 ;
V_24 <<= V_37 ;
if ( V_8 -> V_38 != V_23 -> V_39 ) {
V_25 = 1 ;
V_8 -> V_38 = V_23 -> V_39 ;
}
if ( V_23 -> V_39 != V_40 )
V_24 |= V_41 ;
if ( V_8 -> V_42 != V_23 -> V_43 ) {
V_25 = 1 ;
V_8 -> V_42 = V_23 -> V_43 ;
}
if ( ! V_23 -> V_43 )
V_24 |= V_44 | V_45 ;
V_10 = F_4 ( V_8 , V_46 ) ;
V_10 &= ~ ( ( V_47 << V_37 ) |
V_41 |
V_44 | V_45 ) ;
V_10 |= V_24 ;
F_3 ( V_8 , V_10 , V_46 ) ;
}
if ( V_25 )
F_10 ( V_23 ) ;
}
void F_11 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
if ( V_8 -> V_23 ) {
F_12 ( V_8 -> V_23 ) ;
F_13 ( V_8 -> V_23 ) ;
}
}
static void F_14 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
T_1 V_10 = 0 ;
if ( ! F_15 ( V_8 ) )
return;
V_10 = F_8 ( V_8 , V_48 ) ;
V_10 &= ~ ( V_49 | V_50 ) ;
V_10 |= V_51 ;
F_9 ( V_8 , V_10 , V_48 ) ;
F_16 ( 2 ) ;
V_10 &= ~ V_51 ;
F_9 ( V_8 , V_10 , V_48 ) ;
F_17 ( 20 ) ;
}
static void F_18 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
T_1 V_10 ;
F_14 ( V_7 ) ;
V_10 = F_8 ( V_8 , V_52 ) ;
V_10 |= V_53 ;
F_9 ( V_8 , V_10 , V_52 ) ;
F_11 ( V_7 ) ;
}
static void F_19 ( struct V_9 * V_8 )
{
T_1 V_10 ;
V_10 = F_20 ( V_8 , V_54 ) ;
V_10 |= V_55 ;
F_21 ( V_8 , V_10 , V_54 ) ;
}
int F_22 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_22 * V_23 = V_8 -> V_23 ;
struct V_56 * V_57 = & V_8 -> V_58 -> V_7 ;
const char * V_59 = NULL ;
T_1 V_60 = 0 ;
T_1 V_61 ;
T_1 V_10 ;
V_8 -> V_62 = ! F_23 ( V_8 -> V_23 ) &&
( V_8 -> V_63 != V_64 ) ;
if ( F_23 ( V_8 -> V_23 ) )
V_8 -> V_63 = V_65 ;
switch ( V_8 -> V_63 ) {
case V_65 :
case V_64 :
if ( F_15 ( V_8 ) )
V_61 = V_66 ;
else
V_61 = V_67 ;
F_21 ( V_8 , V_61 , V_54 ) ;
if ( F_23 ( V_8 -> V_23 ) ) {
V_59 = L_1 ;
F_18 ( V_7 ) ;
} else if ( V_8 -> V_63 == V_64 ) {
V_59 = L_2 ;
F_19 ( V_8 ) ;
}
break;
case V_68 :
V_59 = L_3 ;
V_23 -> V_69 &= V_70 ;
F_21 ( V_8 ,
V_71 , V_54 ) ;
break;
case V_72 :
V_59 = L_4 ;
if ( ( V_8 -> V_23 -> V_69 & V_70 ) ==
V_70 )
V_61 = V_73 ;
else
V_61 = V_74 ;
F_21 ( V_8 , V_61 , V_54 ) ;
break;
case V_75 :
V_60 = F_24 ( 16 ) ;
case V_76 :
if ( V_60 )
V_59 = L_5 ;
else
V_59 = L_6 ;
V_10 = F_8 ( V_8 , V_28 ) ;
V_10 |= V_77 | V_60 ;
F_9 ( V_8 , V_10 , V_28 ) ;
F_21 ( V_8 ,
V_78 , V_54 ) ;
break;
default:
F_25 ( V_57 , L_7 , V_8 -> V_63 ) ;
return - V_79 ;
}
F_26 ( V_57 , L_8 , V_59 ) ;
return 0 ;
}
static int F_27 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
struct V_22 * V_23 ;
unsigned int V_80 ;
int V_5 ;
if ( V_8 -> V_23 ) {
F_28 ( L_9 ) ;
return 0 ;
}
if ( V_8 -> V_81 )
V_23 = F_29 ( V_7 , V_8 -> V_81 ,
F_7 , 0 ,
V_8 -> V_63 ) ;
else
V_23 = F_30 ( V_7 ,
F_7 ,
V_8 -> V_63 ) ;
if ( ! V_23 ) {
F_31 ( L_10 ) ;
return - V_82 ;
}
V_8 -> V_26 = - 1 ;
V_8 -> V_38 = - 1 ;
V_8 -> V_42 = - 1 ;
V_8 -> V_23 = V_23 ;
V_5 = F_22 ( V_7 ) ;
if ( V_5 ) {
F_32 ( V_8 -> V_23 ) ;
return V_5 ;
}
V_80 = V_83 ;
if ( ( V_23 -> V_69 & V_84 ) || F_33 ( V_8 ) )
V_80 = 0 ;
V_23 -> V_85 |= V_80 ;
V_23 -> V_86 = V_23 -> V_69 ;
if ( F_23 ( V_8 -> V_23 ) )
V_8 -> V_1 -> V_87 [ V_23 -> V_88 ] = V_89 ;
else
V_8 -> V_1 -> V_87 [ V_23 -> V_88 ] = V_90 ;
F_28 ( L_11 ,
V_23 -> V_88 , V_23 -> V_91 -> V_92 ) ;
return 0 ;
}
static int F_34 ( struct V_9 * V_8 )
{
struct V_1 * V_2 ;
if ( V_8 -> V_1 )
return 0 ;
V_8 -> V_1 = F_35 () ;
if ( ! V_8 -> V_1 ) {
F_31 ( L_12 ) ;
return - V_93 ;
}
V_2 = V_8 -> V_1 ;
V_2 -> V_8 = V_8 -> V_7 ;
V_2 -> V_92 = L_13 ;
V_2 -> V_94 = & V_8 -> V_58 -> V_7 ;
V_2 -> V_95 = F_1 ;
V_2 -> V_96 = F_6 ;
snprintf ( V_2 -> V_97 , V_98 , L_14 ,
V_8 -> V_58 -> V_92 , V_8 -> V_58 -> V_97 ) ;
V_2 -> V_87 = F_36 ( sizeof( int ) * V_99 , V_100 ) ;
if ( ! V_2 -> V_87 ) {
F_37 ( V_8 -> V_1 ) ;
return - V_93 ;
}
return 0 ;
}
static int F_38 ( struct V_9 * V_8 )
{
struct V_101 * V_102 = V_8 -> V_58 -> V_7 . V_103 ;
struct V_56 * V_57 = & V_8 -> V_58 -> V_7 ;
struct V_101 * V_104 ;
char * V_105 ;
int V_5 ;
V_105 = F_39 ( V_100 , L_15 , V_8 -> V_106 ) ;
if ( ! V_105 )
return - V_93 ;
V_104 = F_40 ( V_102 , NULL , V_105 ) ;
F_41 ( V_105 ) ;
if ( ! V_104 ) {
F_25 ( V_57 , L_16 ) ;
return - V_82 ;
}
V_5 = F_42 ( V_8 -> V_1 , V_104 ) ;
if ( V_5 ) {
F_25 ( V_57 , L_17 ) ;
return V_5 ;
}
V_8 -> V_81 = F_43 ( V_102 , L_18 , 0 ) ;
V_8 -> V_63 = F_44 ( V_102 ) ;
return 0 ;
}
int F_45 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
int V_5 ;
V_5 = F_34 ( V_8 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_38 ( V_8 ) ;
if ( V_5 )
goto V_107;
V_5 = F_27 ( V_7 ) ;
if ( V_5 )
goto V_108;
return 0 ;
V_108:
F_46 ( V_8 -> V_1 ) ;
V_107:
F_41 ( V_8 -> V_1 -> V_87 ) ;
F_37 ( V_8 -> V_1 ) ;
return V_5 ;
}
void F_47 ( struct V_6 * V_7 )
{
struct V_9 * V_8 = F_2 ( V_7 ) ;
F_46 ( V_8 -> V_1 ) ;
F_41 ( V_8 -> V_1 -> V_87 ) ;
F_37 ( V_8 -> V_1 ) ;
}
