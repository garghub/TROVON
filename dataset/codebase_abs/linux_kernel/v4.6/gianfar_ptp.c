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
F_5 ( V_1 ) ;
F_4 ( & V_1 -> V_5 -> V_11 , V_1 -> V_11 ) ;
F_4 ( & V_1 -> V_5 -> V_12 , V_1 -> V_12 ) ;
}
static T_3 F_8 ( int V_13 , void * V_14 )
{
struct V_1 * V_1 = V_14 ;
struct V_15 V_16 ;
T_1 V_2 ;
T_2 V_17 = 0 , V_3 , V_4 , V_18 , V_19 ;
V_19 = F_2 ( & V_1 -> V_5 -> V_20 ) ;
if ( V_19 & V_21 ) {
V_17 |= V_21 ;
V_4 = F_2 ( & V_1 -> V_5 -> V_22 ) ;
V_3 = F_2 ( & V_1 -> V_5 -> V_23 ) ;
V_16 . type = V_24 ;
V_16 . V_25 = 0 ;
V_16 . V_26 = ( ( T_1 ) V_4 ) << 32 ;
V_16 . V_26 |= V_3 ;
V_15 ( V_1 -> clock , & V_16 ) ;
}
if ( V_19 & V_27 ) {
V_17 |= V_27 ;
V_4 = F_2 ( & V_1 -> V_5 -> V_28 ) ;
V_3 = F_2 ( & V_1 -> V_5 -> V_29 ) ;
V_16 . type = V_24 ;
V_16 . V_25 = 1 ;
V_16 . V_26 = ( ( T_1 ) V_4 ) << 32 ;
V_16 . V_26 |= V_3 ;
V_15 ( V_1 -> clock , & V_16 ) ;
}
if ( V_19 & V_30 ) {
V_17 |= V_30 ;
if ( V_1 -> V_31 ) {
V_16 . type = V_32 ;
V_16 . V_25 = 0 ;
V_16 . V_26 = V_1 -> V_31 ;
V_15 ( V_1 -> clock , & V_16 ) ;
}
if ( V_1 -> V_33 ) {
V_2 = V_1 -> V_31 + V_1 -> V_33 ;
V_4 = V_2 >> 32 ;
V_3 = V_2 & 0xffffffff ;
F_9 ( & V_1 -> V_34 ) ;
F_4 ( & V_1 -> V_5 -> V_35 , V_3 ) ;
F_4 ( & V_1 -> V_5 -> V_36 , V_4 ) ;
F_10 ( & V_1 -> V_34 ) ;
V_1 -> V_31 = V_2 ;
} else {
F_4 ( & V_1 -> V_5 -> V_20 , V_30 ) ;
F_9 ( & V_1 -> V_34 ) ;
V_18 = F_2 ( & V_1 -> V_5 -> V_37 ) ;
V_18 &= ~ V_38 ;
F_4 ( & V_1 -> V_5 -> V_37 , V_18 ) ;
F_10 ( & V_1 -> V_34 ) ;
V_1 -> V_31 = 0 ;
V_1 -> V_33 = 0 ;
}
}
if ( V_19 & V_39 ) {
V_17 |= V_39 ;
V_16 . type = V_40 ;
V_15 ( V_1 -> clock , & V_16 ) ;
}
if ( V_17 ) {
F_4 ( & V_1 -> V_5 -> V_20 , V_17 ) ;
return V_41 ;
} else
return V_42 ;
}
static int F_11 ( struct V_43 * V_44 , T_4 V_45 )
{
T_1 V_46 ;
T_2 V_47 , V_48 ;
int V_49 = 0 ;
struct V_1 * V_1 = F_12 ( V_44 , struct V_1 , V_50 ) ;
if ( V_45 < 0 ) {
V_49 = 1 ;
V_45 = - V_45 ;
}
V_48 = V_1 -> V_48 ;
V_46 = V_48 ;
V_46 *= V_45 ;
V_47 = F_6 ( V_46 , 1000000000ULL ) ;
V_48 = V_49 ? V_48 - V_47 : V_48 + V_47 ;
F_4 ( & V_1 -> V_5 -> V_48 , V_48 ) ;
return 0 ;
}
static int F_13 ( struct V_43 * V_44 , T_5 V_51 )
{
T_5 V_52 ;
unsigned long V_53 ;
struct V_1 * V_1 = F_12 ( V_44 , struct V_1 , V_50 ) ;
F_14 ( & V_1 -> V_34 , V_53 ) ;
V_52 = F_1 ( V_1 ) ;
V_52 += V_51 ;
F_3 ( V_1 , V_52 ) ;
F_15 ( & V_1 -> V_34 , V_53 ) ;
F_7 ( V_1 ) ;
return 0 ;
}
static int F_16 ( struct V_43 * V_44 ,
struct V_54 * V_55 )
{
T_1 V_2 ;
unsigned long V_53 ;
struct V_1 * V_1 = F_12 ( V_44 , struct V_1 , V_50 ) ;
F_14 ( & V_1 -> V_34 , V_53 ) ;
V_2 = F_1 ( V_1 ) ;
F_15 ( & V_1 -> V_34 , V_53 ) ;
* V_55 = F_17 ( V_2 ) ;
return 0 ;
}
static int F_18 ( struct V_43 * V_44 ,
const struct V_54 * V_55 )
{
T_1 V_2 ;
unsigned long V_53 ;
struct V_1 * V_1 = F_12 ( V_44 , struct V_1 , V_50 ) ;
V_2 = F_19 ( V_55 ) ;
F_14 ( & V_1 -> V_34 , V_53 ) ;
F_3 ( V_1 , V_2 ) ;
F_7 ( V_1 ) ;
F_15 ( & V_1 -> V_34 , V_53 ) ;
return 0 ;
}
static int F_20 ( struct V_43 * V_44 ,
struct V_56 * V_57 , int V_58 )
{
struct V_1 * V_1 = F_12 ( V_44 , struct V_1 , V_50 ) ;
unsigned long V_53 ;
T_2 V_59 , V_18 ;
switch ( V_57 -> type ) {
case V_60 :
switch ( V_57 -> V_61 . V_25 ) {
case 0 :
V_59 = V_62 ;
break;
case 1 :
V_59 = V_63 ;
break;
default:
return - V_64 ;
}
F_14 ( & V_1 -> V_34 , V_53 ) ;
V_18 = F_2 ( & V_1 -> V_5 -> V_37 ) ;
if ( V_58 )
V_18 |= V_59 ;
else
V_18 &= ~ V_59 ;
F_4 ( & V_1 -> V_5 -> V_37 , V_18 ) ;
F_15 ( & V_1 -> V_34 , V_53 ) ;
return 0 ;
case V_65 :
F_14 ( & V_1 -> V_34 , V_53 ) ;
V_18 = F_2 ( & V_1 -> V_5 -> V_37 ) ;
if ( V_58 )
V_18 |= V_66 ;
else
V_18 &= ~ V_66 ;
F_4 ( & V_1 -> V_5 -> V_37 , V_18 ) ;
F_15 ( & V_1 -> V_34 , V_53 ) ;
return 0 ;
default:
break;
}
return - V_67 ;
}
static int F_21 ( struct V_68 * V_69 )
{
struct V_70 * V_71 = V_69 -> V_69 . V_72 ;
struct V_1 * V_1 ;
struct V_54 V_52 ;
int V_73 = - V_74 ;
T_2 V_75 ;
unsigned long V_53 ;
V_1 = F_22 ( sizeof( * V_1 ) , V_76 ) ;
if ( ! V_1 )
goto V_77;
V_73 = - V_78 ;
V_1 -> V_50 = V_79 ;
if ( F_23 ( V_71 , L_1 , & V_1 -> V_80 ) )
V_1 -> V_80 = V_81 ;
if ( F_23 ( V_71 ,
L_2 , & V_1 -> V_8 ) ||
F_23 ( V_71 ,
L_3 , & V_1 -> V_82 ) ||
F_23 ( V_71 ,
L_4 , & V_1 -> V_48 ) ||
F_23 ( V_71 ,
L_5 , & V_1 -> V_11 ) ||
F_23 ( V_71 ,
L_6 , & V_1 -> V_12 ) ||
F_23 ( V_71 ,
L_7 , & V_1 -> V_50 . V_83 ) ) {
F_24 ( L_8 ) ;
goto V_84;
}
V_1 -> V_13 = F_25 ( V_69 , 0 ) ;
if ( V_1 -> V_13 < 0 ) {
F_24 ( L_9 ) ;
goto V_84;
}
if ( F_26 ( V_1 -> V_13 , F_8 , 0 , V_85 , V_1 ) ) {
F_24 ( L_10 ) ;
goto V_84;
}
V_1 -> V_86 = F_27 ( V_69 , V_87 , 0 ) ;
if ( ! V_1 -> V_86 ) {
F_24 ( L_11 ) ;
goto V_88;
}
if ( F_28 ( & V_89 , V_1 -> V_86 ) ) {
F_24 ( L_12 ) ;
goto V_88;
}
F_29 ( & V_1 -> V_34 ) ;
V_1 -> V_5 = F_30 ( V_1 -> V_86 -> V_90 ,
F_31 ( V_1 -> V_86 ) ) ;
if ( ! V_1 -> V_5 ) {
F_24 ( L_13 ) ;
goto V_91;
}
F_32 ( & V_52 ) ;
F_18 ( & V_1 -> V_50 , & V_52 ) ;
V_75 =
( V_1 -> V_8 & V_92 ) << V_93 |
( V_1 -> V_80 & V_94 ) << V_95 ;
F_14 ( & V_1 -> V_34 , V_53 ) ;
F_4 ( & V_1 -> V_5 -> V_75 , V_75 ) ;
F_4 ( & V_1 -> V_5 -> V_48 , V_1 -> V_48 ) ;
F_4 ( & V_1 -> V_5 -> V_82 , V_1 -> V_82 ) ;
F_4 ( & V_1 -> V_5 -> V_11 , V_1 -> V_11 ) ;
F_4 ( & V_1 -> V_5 -> V_12 , V_1 -> V_12 ) ;
F_5 ( V_1 ) ;
F_4 ( & V_1 -> V_5 -> V_75 , V_75 | V_96 | V_97 | V_98 | V_99 ) ;
F_15 ( & V_1 -> V_34 , V_53 ) ;
V_1 -> clock = F_33 ( & V_1 -> V_50 , & V_69 -> V_69 ) ;
if ( F_34 ( V_1 -> clock ) ) {
V_73 = F_35 ( V_1 -> clock ) ;
goto V_100;
}
V_101 = F_36 ( V_1 -> clock ) ;
F_37 ( V_69 , V_1 ) ;
return 0 ;
V_100:
F_38 ( V_1 -> V_5 ) ;
V_91:
F_39 ( V_1 -> V_86 ) ;
V_88:
F_40 ( V_1 -> V_13 , V_1 ) ;
V_84:
F_41 ( V_1 ) ;
V_77:
return V_73 ;
}
static int F_42 ( struct V_68 * V_69 )
{
struct V_1 * V_1 = F_43 ( V_69 ) ;
F_4 ( & V_1 -> V_5 -> V_37 , 0 ) ;
F_4 ( & V_1 -> V_5 -> V_75 , 0 ) ;
V_101 = - 1 ;
F_44 ( V_1 -> clock ) ;
F_38 ( V_1 -> V_5 ) ;
F_39 ( V_1 -> V_86 ) ;
F_40 ( V_1 -> V_13 , V_1 ) ;
F_41 ( V_1 ) ;
return 0 ;
}
