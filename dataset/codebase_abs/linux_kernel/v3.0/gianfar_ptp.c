static T_1 F_1 ( struct V_1 * V_1 )
{
T_1 V_2 ;
T_2 V_3 , V_4 ;
V_3 = F_2 ( & V_1 -> V_5 -> V_6 ) ;
V_4 = F_2 ( & V_1 -> V_5 -> V_7 ) ;
V_2 = ( ( T_1 ) V_4 ) << 32 ;
V_2 |= V_3 ;
return V_2 ;
}
static void F_3 ( struct V_1 * V_1 , T_1 V_2 )
{
T_2 V_4 = V_2 >> 32 ;
T_2 V_3 = V_2 & 0xffffffff ;
F_4 ( & V_1 -> V_5 -> V_6 , V_3 ) ;
F_4 ( & V_1 -> V_5 -> V_7 , V_4 ) ;
}
static void F_5 ( struct V_1 * V_1 )
{
T_1 V_2 ;
T_2 V_3 , V_4 ;
V_2 = F_1 ( V_1 ) + 1500000000ULL ;
V_2 = F_6 ( V_2 , 1000000000UL ) * 1000000000ULL ;
V_2 -= V_1 -> V_8 ;
V_4 = V_2 >> 32 ;
V_3 = V_2 & 0xffffffff ;
F_4 ( & V_1 -> V_5 -> V_9 , V_3 ) ;
F_4 ( & V_1 -> V_5 -> V_10 , V_4 ) ;
}
static void F_7 ( struct V_1 * V_1 )
{
T_2 V_11 = F_2 ( & V_1 -> V_5 -> V_11 ) ;
F_4 ( & V_1 -> V_5 -> V_11 , V_11 & ( ~ V_12 ) ) ;
F_4 ( & V_1 -> V_5 -> V_13 , V_1 -> V_13 ) ;
F_4 ( & V_1 -> V_5 -> V_14 , V_1 -> V_14 ) ;
F_4 ( & V_1 -> V_5 -> V_15 , V_1 -> V_15 ) ;
F_5 ( V_1 ) ;
F_4 ( & V_1 -> V_5 -> V_11 , V_11 | V_12 ) ;
}
static T_3 F_8 ( int V_16 , void * V_17 )
{
struct V_1 * V_1 = V_17 ;
struct V_18 V_19 ;
T_1 V_2 ;
T_2 V_20 = 0 , V_3 , V_4 , V_21 , V_22 ;
V_22 = F_2 ( & V_1 -> V_5 -> V_23 ) ;
if ( V_22 & V_24 ) {
V_20 |= V_24 ;
V_4 = F_2 ( & V_1 -> V_5 -> V_25 ) ;
V_3 = F_2 ( & V_1 -> V_5 -> V_26 ) ;
V_19 . type = V_27 ;
V_19 . V_28 = 0 ;
V_19 . V_29 = ( ( T_1 ) V_4 ) << 32 ;
V_19 . V_29 |= V_3 ;
V_18 ( V_1 -> clock , & V_19 ) ;
}
if ( V_22 & V_30 ) {
V_20 |= V_30 ;
V_4 = F_2 ( & V_1 -> V_5 -> V_31 ) ;
V_3 = F_2 ( & V_1 -> V_5 -> V_32 ) ;
V_19 . type = V_27 ;
V_19 . V_28 = 1 ;
V_19 . V_29 = ( ( T_1 ) V_4 ) << 32 ;
V_19 . V_29 |= V_3 ;
V_18 ( V_1 -> clock , & V_19 ) ;
}
if ( V_22 & V_33 ) {
V_20 |= V_33 ;
if ( V_1 -> V_34 ) {
V_19 . type = V_35 ;
V_19 . V_28 = 0 ;
V_19 . V_29 = V_1 -> V_34 ;
V_18 ( V_1 -> clock , & V_19 ) ;
}
if ( V_1 -> V_36 ) {
V_2 = V_1 -> V_34 + V_1 -> V_36 ;
V_4 = V_2 >> 32 ;
V_3 = V_2 & 0xffffffff ;
F_9 ( & V_1 -> V_37 ) ;
F_4 ( & V_1 -> V_5 -> V_38 , V_3 ) ;
F_4 ( & V_1 -> V_5 -> V_39 , V_4 ) ;
F_10 ( & V_1 -> V_37 ) ;
V_1 -> V_34 = V_2 ;
} else {
F_4 ( & V_1 -> V_5 -> V_23 , V_33 ) ;
F_9 ( & V_1 -> V_37 ) ;
V_21 = F_2 ( & V_1 -> V_5 -> V_40 ) ;
V_21 &= ~ V_41 ;
F_4 ( & V_1 -> V_5 -> V_40 , V_21 ) ;
F_10 ( & V_1 -> V_37 ) ;
V_1 -> V_34 = 0 ;
V_1 -> V_36 = 0 ;
}
}
if ( V_22 & V_42 ) {
V_20 |= V_42 ;
V_19 . type = V_43 ;
V_18 ( V_1 -> clock , & V_19 ) ;
}
if ( V_20 ) {
F_4 ( & V_1 -> V_5 -> V_23 , V_20 ) ;
return V_44 ;
} else
return V_45 ;
}
static int F_11 ( struct V_46 * V_47 , T_4 V_48 )
{
T_1 V_49 ;
T_2 V_50 , V_51 ;
int V_52 = 0 ;
struct V_1 * V_1 = F_12 ( V_47 , struct V_1 , V_53 ) ;
if ( V_48 < 0 ) {
V_52 = 1 ;
V_48 = - V_48 ;
}
V_51 = V_1 -> V_51 ;
V_49 = V_51 ;
V_49 *= V_48 ;
V_50 = F_6 ( V_49 , 1000000000ULL ) ;
V_51 = V_52 ? V_51 - V_50 : V_51 + V_50 ;
F_4 ( & V_1 -> V_5 -> V_51 , V_51 ) ;
return 0 ;
}
static int F_13 ( struct V_46 * V_47 , T_5 V_54 )
{
T_5 V_55 ;
unsigned long V_56 ;
struct V_1 * V_1 = F_12 ( V_47 , struct V_1 , V_53 ) ;
F_14 ( & V_1 -> V_37 , V_56 ) ;
V_55 = F_1 ( V_1 ) ;
V_55 += V_54 ;
F_3 ( V_1 , V_55 ) ;
F_15 ( & V_1 -> V_37 , V_56 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
static int F_16 ( struct V_46 * V_47 , struct V_57 * V_58 )
{
T_1 V_2 ;
T_2 V_59 ;
unsigned long V_56 ;
struct V_1 * V_1 = F_12 ( V_47 , struct V_1 , V_53 ) ;
F_14 ( & V_1 -> V_37 , V_56 ) ;
V_2 = F_1 ( V_1 ) ;
F_15 ( & V_1 -> V_37 , V_56 ) ;
V_58 -> V_60 = F_17 ( V_2 , 1000000000 , & V_59 ) ;
V_58 -> V_61 = V_59 ;
return 0 ;
}
static int F_18 ( struct V_46 * V_47 ,
const struct V_57 * V_58 )
{
T_1 V_2 ;
unsigned long V_56 ;
struct V_1 * V_1 = F_12 ( V_47 , struct V_1 , V_53 ) ;
V_2 = V_58 -> V_60 * 1000000000ULL ;
V_2 += V_58 -> V_61 ;
F_14 ( & V_1 -> V_37 , V_56 ) ;
F_3 ( V_1 , V_2 ) ;
F_7 ( V_1 ) ;
F_15 ( & V_1 -> V_37 , V_56 ) ;
return 0 ;
}
static int F_19 ( struct V_46 * V_47 ,
struct V_62 * V_63 , int V_64 )
{
struct V_1 * V_1 = F_12 ( V_47 , struct V_1 , V_53 ) ;
unsigned long V_56 ;
T_2 V_65 , V_21 ;
switch ( V_63 -> type ) {
case V_66 :
switch ( V_63 -> V_67 . V_28 ) {
case 0 :
V_65 = V_68 ;
break;
case 1 :
V_65 = V_69 ;
break;
default:
return - V_70 ;
}
F_14 ( & V_1 -> V_37 , V_56 ) ;
V_21 = F_2 ( & V_1 -> V_5 -> V_40 ) ;
if ( V_64 )
V_21 |= V_65 ;
else
V_21 &= ~ V_65 ;
F_4 ( & V_1 -> V_5 -> V_40 , V_21 ) ;
F_15 ( & V_1 -> V_37 , V_56 ) ;
return 0 ;
case V_71 :
F_14 ( & V_1 -> V_37 , V_56 ) ;
V_21 = F_2 ( & V_1 -> V_5 -> V_40 ) ;
if ( V_64 )
V_21 |= V_72 ;
else
V_21 &= ~ V_72 ;
F_4 ( & V_1 -> V_5 -> V_40 , V_21 ) ;
F_15 ( & V_1 -> V_37 , V_56 ) ;
return 0 ;
default:
break;
}
return - V_73 ;
}
static int F_20 ( struct V_74 * V_75 , char * V_76 , T_2 * V_22 )
{
int V_77 ;
const T_2 * V_78 = F_21 ( V_75 , V_76 , & V_77 ) ;
if ( ! V_78 || V_77 != sizeof( * V_78 ) )
return - 1 ;
* V_22 = * V_78 ;
return 0 ;
}
static int F_22 ( struct V_79 * V_80 )
{
struct V_74 * V_75 = V_80 -> V_80 . V_81 ;
struct V_1 * V_1 ;
struct V_57 V_55 ;
int V_82 = - V_83 ;
T_2 V_11 ;
unsigned long V_56 ;
V_1 = F_23 ( sizeof( * V_1 ) , V_84 ) ;
if ( ! V_1 )
goto V_85;
V_82 = - V_86 ;
V_1 -> V_53 = V_87 ;
V_1 -> V_88 = V_89 ;
if ( F_20 ( V_75 , L_1 , & V_1 -> V_8 ) ||
F_20 ( V_75 , L_2 , & V_1 -> V_13 ) ||
F_20 ( V_75 , L_3 , & V_1 -> V_51 ) ||
F_20 ( V_75 , L_4 , & V_1 -> V_14 ) ||
F_20 ( V_75 , L_5 , & V_1 -> V_15 ) ||
F_20 ( V_75 , L_6 , & V_1 -> V_53 . V_90 ) ) {
F_24 ( L_7 ) ;
goto V_91;
}
V_1 -> V_16 = F_25 ( V_80 , 0 ) ;
if ( V_1 -> V_16 == V_92 ) {
F_24 ( L_8 ) ;
goto V_91;
}
if ( F_26 ( V_1 -> V_16 , F_8 , 0 , V_93 , V_1 ) ) {
F_24 ( L_9 ) ;
goto V_91;
}
V_1 -> V_94 = F_27 ( V_80 , V_95 , 0 ) ;
if ( ! V_1 -> V_94 ) {
F_24 ( L_10 ) ;
goto V_96;
}
if ( F_28 ( & V_97 , V_1 -> V_94 ) ) {
F_24 ( L_11 ) ;
goto V_96;
}
F_29 ( & V_1 -> V_37 ) ;
V_1 -> V_5 = F_30 ( V_1 -> V_94 -> V_98 ,
1 + V_1 -> V_94 -> V_99 - V_1 -> V_94 -> V_98 ) ;
if ( ! V_1 -> V_5 ) {
F_24 ( L_12 ) ;
goto V_100;
}
F_31 ( & V_55 ) ;
F_18 ( & V_1 -> V_53 , & V_55 ) ;
V_11 =
( V_1 -> V_8 & V_101 ) << V_102 |
( V_1 -> V_88 & V_103 ) << V_104 ;
F_14 ( & V_1 -> V_37 , V_56 ) ;
F_4 ( & V_1 -> V_5 -> V_11 , V_11 ) ;
F_4 ( & V_1 -> V_5 -> V_51 , V_1 -> V_51 ) ;
F_4 ( & V_1 -> V_5 -> V_13 , V_1 -> V_13 ) ;
F_4 ( & V_1 -> V_5 -> V_14 , V_1 -> V_14 ) ;
F_4 ( & V_1 -> V_5 -> V_15 , V_1 -> V_15 ) ;
F_5 ( V_1 ) ;
F_4 ( & V_1 -> V_5 -> V_11 , V_11 | V_105 | V_106 | V_12 ) ;
F_15 ( & V_1 -> V_37 , V_56 ) ;
V_1 -> clock = F_32 ( & V_1 -> V_53 ) ;
if ( F_33 ( V_1 -> clock ) ) {
V_82 = F_34 ( V_1 -> clock ) ;
goto V_107;
}
F_35 ( & V_80 -> V_80 , V_1 ) ;
return 0 ;
V_107:
V_100:
F_36 ( V_1 -> V_94 ) ;
V_96:
F_37 ( V_1 -> V_16 , V_1 ) ;
V_91:
F_38 ( V_1 ) ;
V_85:
return V_82 ;
}
static int F_39 ( struct V_79 * V_80 )
{
struct V_1 * V_1 = F_40 ( & V_80 -> V_80 ) ;
F_4 ( & V_1 -> V_5 -> V_40 , 0 ) ;
F_4 ( & V_1 -> V_5 -> V_11 , 0 ) ;
F_41 ( V_1 -> clock ) ;
F_42 ( V_1 -> V_5 ) ;
F_36 ( V_1 -> V_94 ) ;
F_37 ( V_1 -> V_16 , V_1 ) ;
F_38 ( V_1 ) ;
return 0 ;
}
static int T_6 F_43 ( void )
{
return F_44 ( & V_108 ) ;
}
static void T_7 F_45 ( void )
{
F_46 ( & V_108 ) ;
}
