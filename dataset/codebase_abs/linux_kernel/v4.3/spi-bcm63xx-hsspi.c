static void F_1 ( struct V_1 * V_2 , unsigned V_3 ,
bool V_4 )
{
T_1 V_5 ;
F_2 ( & V_2 -> V_6 ) ;
V_5 = F_3 ( V_2 -> V_7 + V_8 ) ;
V_5 &= ~ F_4 ( V_3 ) ;
if ( V_4 == ! ( V_2 -> V_9 & F_4 ( V_3 ) ) )
V_5 |= F_4 ( V_3 ) ;
F_5 ( V_5 , V_2 -> V_7 + V_8 ) ;
F_6 ( & V_2 -> V_6 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_10 * V_11 , int V_12 )
{
unsigned V_13 = V_11 -> V_14 ;
T_1 V_5 ;
V_5 = F_8 ( 2048 , F_8 ( V_2 -> V_15 , V_12 ) ) ;
F_5 ( V_16 | V_5 ,
V_2 -> V_7 + F_9 ( V_13 ) ) ;
V_5 = F_3 ( V_2 -> V_7 + F_10 ( V_13 ) ) ;
if ( V_12 > V_17 )
V_5 |= V_18 ;
else
V_5 &= ~ V_18 ;
F_5 ( V_5 , V_2 -> V_7 + F_10 ( V_13 ) ) ;
F_2 ( & V_2 -> V_6 ) ;
V_5 = F_3 ( V_2 -> V_7 + V_8 ) ;
V_5 &= ~ V_19 ;
if ( V_11 -> V_20 & V_21 )
V_5 |= V_19 ;
F_5 ( V_5 , V_2 -> V_7 + V_8 ) ;
F_6 ( & V_2 -> V_6 ) ;
}
static int F_11 ( struct V_10 * V_11 , struct V_22 * V_23 )
{
struct V_1 * V_2 = F_12 ( V_11 -> V_24 ) ;
unsigned V_14 = V_11 -> V_14 ;
T_2 V_25 = 0 ;
int V_26 = V_23 -> V_27 ;
int V_28 = V_29 ;
const T_3 * V_30 = V_23 -> V_31 ;
T_3 * V_32 = V_23 -> V_33 ;
F_7 ( V_2 , V_11 , V_23 -> V_15 ) ;
F_1 ( V_2 , V_11 -> V_14 , true ) ;
if ( V_30 && V_32 )
V_25 = V_34 ;
else if ( V_30 )
V_25 = V_35 ;
else if ( V_32 )
V_25 = V_36 ;
if ( V_25 != V_36 )
V_28 -= V_37 ;
if ( ( V_25 == V_36 && V_23 -> V_38 == V_39 ) ||
( V_25 == V_35 && V_23 -> V_40 == V_39 ) )
V_25 |= V_41 ;
F_5 ( 1 << V_42 |
1 << V_43 | 0xff ,
V_2 -> V_7 + F_13 ( V_14 ) ) ;
while ( V_26 > 0 ) {
int V_44 = F_14 ( int , V_28 , V_26 ) ;
F_15 ( & V_2 -> V_45 ) ;
if ( V_30 ) {
F_16 ( V_2 -> V_46 + V_37 , V_30 , V_44 ) ;
V_30 += V_44 ;
}
F_17 ( V_25 | V_44 , V_2 -> V_46 ) ;
F_5 ( F_18 ( 0 ) ,
V_2 -> V_7 + V_47 ) ;
F_5 ( ! V_14 << V_48 |
V_14 << V_49 |
V_50 ,
V_2 -> V_7 + F_19 ( 0 ) ) ;
if ( F_20 ( & V_2 -> V_45 , V_51 ) == 0 ) {
F_21 ( & V_2 -> V_52 -> V_53 , L_1 ) ;
return - V_54 ;
}
if ( V_32 ) {
F_22 ( V_32 , V_2 -> V_46 , V_44 ) ;
V_32 += V_44 ;
}
V_26 -= V_44 ;
}
return 0 ;
}
static int F_23 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_12 ( V_11 -> V_24 ) ;
T_1 V_5 ;
V_5 = F_3 ( V_2 -> V_7 +
F_10 ( V_11 -> V_14 ) ) ;
V_5 &= ~ ( V_55 | V_56 ) ;
if ( V_11 -> V_20 & V_57 )
V_5 |= V_55 ;
else
V_5 |= V_56 ;
F_5 ( V_5 , V_2 -> V_7 +
F_10 ( V_11 -> V_14 ) ) ;
F_2 ( & V_2 -> V_6 ) ;
V_5 = F_3 ( V_2 -> V_7 + V_8 ) ;
if ( ( V_5 & V_58 ) == V_2 -> V_9 ) {
if ( V_11 -> V_20 & V_59 )
V_5 |= F_4 ( V_11 -> V_14 ) ;
else
V_5 &= ~ F_4 ( V_11 -> V_14 ) ;
F_5 ( V_5 , V_2 -> V_7 + V_8 ) ;
}
if ( V_11 -> V_20 & V_59 )
V_2 -> V_9 |= F_4 ( V_11 -> V_14 ) ;
else
V_2 -> V_9 &= ~ F_4 ( V_11 -> V_14 ) ;
F_6 ( & V_2 -> V_6 ) ;
return 0 ;
}
static int F_24 ( struct V_60 * V_24 ,
struct V_61 * V_62 )
{
struct V_1 * V_2 = F_12 ( V_24 ) ;
struct V_22 * V_23 ;
struct V_10 * V_11 = V_62 -> V_11 ;
int V_63 = - V_64 ;
int V_65 ;
T_1 V_5 ;
V_65 = ! V_11 -> V_14 ;
F_1 ( V_2 , V_65 , true ) ;
F_25 (t, &msg->transfers, transfer_list) {
V_63 = F_11 ( V_11 , V_23 ) ;
if ( V_63 )
break;
V_62 -> V_66 += V_23 -> V_27 ;
if ( V_23 -> V_67 )
F_26 ( V_23 -> V_67 ) ;
if ( V_23 -> V_68 )
F_1 ( V_2 , V_11 -> V_14 , false ) ;
}
F_2 ( & V_2 -> V_6 ) ;
V_5 = F_3 ( V_2 -> V_7 + V_8 ) ;
V_5 &= ~ V_58 ;
V_5 |= V_2 -> V_9 ;
F_5 ( V_5 , V_2 -> V_7 + V_8 ) ;
F_6 ( & V_2 -> V_6 ) ;
V_62 -> V_63 = V_63 ;
F_27 ( V_24 ) ;
return 0 ;
}
static T_4 F_28 ( int V_69 , void * V_70 )
{
struct V_1 * V_2 = (struct V_1 * ) V_70 ;
if ( F_3 ( V_2 -> V_7 + V_71 ) == 0 )
return V_72 ;
F_5 ( V_73 , V_2 -> V_7 + V_74 ) ;
F_5 ( 0 , V_2 -> V_7 + V_47 ) ;
F_29 ( & V_2 -> V_45 ) ;
return V_75 ;
}
static int F_30 ( struct V_76 * V_52 )
{
struct V_60 * V_24 ;
struct V_1 * V_2 ;
struct V_77 * V_78 ;
void T_5 * V_7 ;
struct V_79 * V_53 = & V_52 -> V_53 ;
struct V_80 * V_80 ;
int V_69 , V_81 ;
T_1 V_5 , V_82 ;
V_69 = F_31 ( V_52 , 0 ) ;
if ( V_69 < 0 ) {
F_21 ( V_53 , L_2 ) ;
return - V_83 ;
}
V_78 = F_32 ( V_52 , V_84 , 0 ) ;
V_7 = F_33 ( V_53 , V_78 ) ;
if ( F_34 ( V_7 ) )
return F_35 ( V_7 ) ;
V_80 = F_36 ( V_53 , L_3 ) ;
if ( F_34 ( V_80 ) )
return F_35 ( V_80 ) ;
V_82 = F_37 ( V_80 ) ;
if ( ! V_82 )
return - V_64 ;
V_81 = F_38 ( V_80 ) ;
if ( V_81 )
return V_81 ;
V_24 = F_39 ( & V_52 -> V_53 , sizeof( * V_2 ) ) ;
if ( ! V_24 ) {
V_81 = - V_85 ;
goto V_86;
}
V_2 = F_12 ( V_24 ) ;
V_2 -> V_52 = V_52 ;
V_2 -> V_80 = V_80 ;
V_2 -> V_7 = V_7 ;
V_2 -> V_15 = V_82 ;
V_2 -> V_46 = ( T_3 T_5 * ) ( V_2 -> V_7 + F_40 ( 0 ) ) ;
F_41 ( & V_2 -> V_6 ) ;
F_42 ( & V_2 -> V_45 ) ;
V_24 -> V_87 = V_88 ;
V_24 -> V_89 = 8 ;
V_24 -> V_90 = F_23 ;
V_24 -> V_91 = F_24 ;
V_24 -> V_92 = V_21 | V_57 | V_59 |
V_93 | V_94 ;
V_24 -> V_95 = F_43 ( 8 ) ;
V_24 -> V_96 = true ;
F_44 ( V_52 , V_24 ) ;
F_5 ( 0 , V_2 -> V_7 + V_47 ) ;
F_5 ( V_73 , V_2 -> V_7 + V_74 ) ;
V_5 = F_3 ( V_2 -> V_7 + V_8 ) ;
V_2 -> V_9 = V_5 & V_58 ;
F_5 ( V_5 | V_97 ,
V_2 -> V_7 + V_8 ) ;
V_81 = F_45 ( V_53 , V_69 , F_28 , V_98 ,
V_52 -> V_99 , V_2 ) ;
if ( V_81 )
goto V_100;
V_81 = F_46 ( V_53 , V_24 ) ;
if ( V_81 )
goto V_100;
return 0 ;
V_100:
F_47 ( V_24 ) ;
V_86:
F_48 ( V_80 ) ;
return V_81 ;
}
static int F_49 ( struct V_76 * V_52 )
{
struct V_60 * V_24 = F_50 ( V_52 ) ;
struct V_1 * V_2 = F_12 ( V_24 ) ;
F_5 ( 0 , V_2 -> V_7 + V_47 ) ;
F_48 ( V_2 -> V_80 ) ;
return 0 ;
}
static int F_51 ( struct V_79 * V_53 )
{
struct V_60 * V_24 = F_52 ( V_53 ) ;
struct V_1 * V_2 = F_12 ( V_24 ) ;
F_53 ( V_24 ) ;
F_48 ( V_2 -> V_80 ) ;
return 0 ;
}
static int F_54 ( struct V_79 * V_53 )
{
struct V_60 * V_24 = F_52 ( V_53 ) ;
struct V_1 * V_2 = F_12 ( V_24 ) ;
int V_81 ;
V_81 = F_38 ( V_2 -> V_80 ) ;
if ( V_81 )
return V_81 ;
F_55 ( V_24 ) ;
return 0 ;
}
