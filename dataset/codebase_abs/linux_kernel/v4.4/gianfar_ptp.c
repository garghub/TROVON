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
static int F_21 ( struct V_68 * V_69 , char * V_70 , T_2 * V_19 )
{
int V_71 ;
const T_2 * V_72 = F_22 ( V_69 , V_70 , & V_71 ) ;
if ( ! V_72 || V_71 != sizeof( * V_72 ) )
return - 1 ;
* V_19 = * V_72 ;
return 0 ;
}
static int F_23 ( struct V_73 * V_74 )
{
struct V_68 * V_69 = V_74 -> V_74 . V_75 ;
struct V_1 * V_1 ;
struct V_54 V_52 ;
int V_76 = - V_77 ;
T_2 V_78 ;
unsigned long V_53 ;
V_1 = F_24 ( sizeof( * V_1 ) , V_79 ) ;
if ( ! V_1 )
goto V_80;
V_76 = - V_81 ;
V_1 -> V_50 = V_82 ;
if ( F_21 ( V_69 , L_1 , & V_1 -> V_83 ) )
V_1 -> V_83 = V_84 ;
if ( F_21 ( V_69 , L_2 , & V_1 -> V_8 ) ||
F_21 ( V_69 , L_3 , & V_1 -> V_85 ) ||
F_21 ( V_69 , L_4 , & V_1 -> V_48 ) ||
F_21 ( V_69 , L_5 , & V_1 -> V_11 ) ||
F_21 ( V_69 , L_6 , & V_1 -> V_12 ) ||
F_21 ( V_69 , L_7 , & V_1 -> V_50 . V_86 ) ) {
F_25 ( L_8 ) ;
goto V_87;
}
V_1 -> V_13 = F_26 ( V_74 , 0 ) ;
if ( V_1 -> V_13 < 0 ) {
F_25 ( L_9 ) ;
goto V_87;
}
if ( F_27 ( V_1 -> V_13 , F_8 , 0 , V_88 , V_1 ) ) {
F_25 ( L_10 ) ;
goto V_87;
}
V_1 -> V_89 = F_28 ( V_74 , V_90 , 0 ) ;
if ( ! V_1 -> V_89 ) {
F_25 ( L_11 ) ;
goto V_91;
}
if ( F_29 ( & V_92 , V_1 -> V_89 ) ) {
F_25 ( L_12 ) ;
goto V_91;
}
F_30 ( & V_1 -> V_34 ) ;
V_1 -> V_5 = F_31 ( V_1 -> V_89 -> V_93 ,
F_32 ( V_1 -> V_89 ) ) ;
if ( ! V_1 -> V_5 ) {
F_25 ( L_13 ) ;
goto V_94;
}
F_33 ( & V_52 ) ;
F_18 ( & V_1 -> V_50 , & V_52 ) ;
V_78 =
( V_1 -> V_8 & V_95 ) << V_96 |
( V_1 -> V_83 & V_97 ) << V_98 ;
F_14 ( & V_1 -> V_34 , V_53 ) ;
F_4 ( & V_1 -> V_5 -> V_78 , V_78 ) ;
F_4 ( & V_1 -> V_5 -> V_48 , V_1 -> V_48 ) ;
F_4 ( & V_1 -> V_5 -> V_85 , V_1 -> V_85 ) ;
F_4 ( & V_1 -> V_5 -> V_11 , V_1 -> V_11 ) ;
F_4 ( & V_1 -> V_5 -> V_12 , V_1 -> V_12 ) ;
F_5 ( V_1 ) ;
F_4 ( & V_1 -> V_5 -> V_78 , V_78 | V_99 | V_100 | V_101 | V_102 ) ;
F_15 ( & V_1 -> V_34 , V_53 ) ;
V_1 -> clock = F_34 ( & V_1 -> V_50 , & V_74 -> V_74 ) ;
if ( F_35 ( V_1 -> clock ) ) {
V_76 = F_36 ( V_1 -> clock ) ;
goto V_103;
}
V_104 = F_37 ( V_1 -> clock ) ;
F_38 ( V_74 , V_1 ) ;
return 0 ;
V_103:
F_39 ( V_1 -> V_5 ) ;
V_94:
F_40 ( V_1 -> V_89 ) ;
V_91:
F_41 ( V_1 -> V_13 , V_1 ) ;
V_87:
F_42 ( V_1 ) ;
V_80:
return V_76 ;
}
static int F_43 ( struct V_73 * V_74 )
{
struct V_1 * V_1 = F_44 ( V_74 ) ;
F_4 ( & V_1 -> V_5 -> V_37 , 0 ) ;
F_4 ( & V_1 -> V_5 -> V_78 , 0 ) ;
V_104 = - 1 ;
F_45 ( V_1 -> clock ) ;
F_39 ( V_1 -> V_5 ) ;
F_40 ( V_1 -> V_89 ) ;
F_41 ( V_1 -> V_13 , V_1 ) ;
F_42 ( V_1 ) ;
return 0 ;
}
