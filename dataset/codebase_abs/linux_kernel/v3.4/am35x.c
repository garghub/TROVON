static void F_1 ( struct V_1 * V_1 )
{
void T_1 * V_2 = V_1 -> V_3 ;
T_2 V_4 ;
V_4 = ( ( V_1 -> V_4 & V_5 ) << V_6 ) |
( ( V_1 -> V_4 & V_7 ) << V_8 ) ;
F_2 ( V_2 , V_9 , V_4 ) ;
F_2 ( V_2 , V_10 , V_11 ) ;
if ( F_3 ( V_1 ) )
F_2 ( V_2 , V_12 ,
V_13 << V_14 ) ;
}
static void F_4 ( struct V_1 * V_1 )
{
void T_1 * V_2 = V_1 -> V_3 ;
F_2 ( V_2 , V_15 , V_11 ) ;
F_2 ( V_2 , V_16 ,
V_17 | V_18 ) ;
F_5 ( V_1 -> V_19 , V_20 , 0 ) ;
F_2 ( V_2 , V_21 , 0 ) ;
}
static void F_6 ( struct V_1 * V_1 , int V_22 )
{
F_7 ( V_22 && F_8 ( V_1 ) ) ;
}
static void F_9 ( unsigned long V_23 )
{
struct V_1 * V_1 = ( void * ) V_23 ;
void T_1 * V_19 = V_1 -> V_19 ;
T_3 V_24 ;
unsigned long V_25 ;
V_24 = F_10 ( V_19 , V_20 ) ;
F_11 ( V_1 -> V_26 , L_1 , V_24 ,
F_12 ( V_1 -> V_27 -> V_28 ) ) ;
F_13 ( & V_1 -> V_29 , V_25 ) ;
switch ( V_1 -> V_27 -> V_28 ) {
case V_30 :
V_24 &= ~ V_31 ;
F_5 ( V_1 -> V_19 , V_20 , V_24 ) ;
V_24 = F_10 ( V_1 -> V_19 , V_20 ) ;
if ( V_24 & V_32 ) {
V_1 -> V_27 -> V_28 = V_33 ;
F_14 ( V_1 ) ;
} else {
V_1 -> V_27 -> V_28 = V_34 ;
F_15 ( V_1 ) ;
}
break;
case V_35 :
V_1 -> V_27 -> V_28 = V_36 ;
F_2 ( V_1 -> V_3 , V_12 ,
V_37 << V_14 ) ;
break;
case V_33 :
if ( ! F_16 ( V_1 ) )
break;
V_24 = F_10 ( V_19 , V_20 ) ;
if ( V_24 & V_32 )
F_17 ( & V_38 , V_39 + V_40 * V_41 ) ;
else
V_1 -> V_27 -> V_28 = V_34 ;
break;
default:
break;
}
F_18 ( & V_1 -> V_29 , V_25 ) ;
}
static void F_19 ( struct V_1 * V_1 , unsigned long V_42 )
{
static unsigned long V_43 ;
if ( ! F_3 ( V_1 ) )
return;
if ( V_42 == 0 )
V_42 = V_39 + F_20 ( 3 ) ;
if ( V_1 -> V_44 || ( V_1 -> V_45 == 0 &&
V_1 -> V_27 -> V_28 == V_30 ) ) {
F_11 ( V_1 -> V_26 , L_2 ,
F_12 ( V_1 -> V_27 -> V_28 ) ) ;
F_21 ( & V_38 ) ;
V_43 = V_39 ;
return;
}
if ( F_22 ( V_43 , V_42 ) && F_23 ( & V_38 ) ) {
F_11 ( V_1 -> V_26 , L_3 ) ;
return;
}
V_43 = V_42 ;
F_11 ( V_1 -> V_26 , L_4 ,
F_12 ( V_1 -> V_27 -> V_28 ) ,
F_24 ( V_42 - V_39 ) ) ;
F_17 ( & V_38 , V_42 ) ;
}
static T_4 F_25 ( int V_46 , void * V_47 )
{
struct V_1 * V_1 = V_47 ;
void T_1 * V_2 = V_1 -> V_3 ;
struct V_48 * V_49 = V_1 -> V_26 ;
struct V_50 * V_51 = V_49 -> V_52 ;
struct V_53 * V_54 = V_51 -> V_55 ;
struct V_56 * V_57 = V_1 -> V_27 -> V_57 ;
unsigned long V_25 ;
T_4 V_58 = V_59 ;
T_2 V_60 , V_61 ;
F_13 ( & V_1 -> V_29 , V_25 ) ;
V_60 = F_26 ( V_2 , V_62 ) ;
if ( V_60 ) {
F_2 ( V_2 , V_63 , V_60 ) ;
V_1 -> V_64 =
( V_60 & V_18 ) >> V_8 ;
V_1 -> V_65 =
( V_60 & V_17 ) >> V_6 ;
}
V_61 = F_26 ( V_2 , V_66 ) ;
if ( ! V_61 && ! V_60 )
goto V_67;
if ( V_61 ) {
F_2 ( V_2 , V_68 , V_61 ) ;
V_1 -> V_69 =
( V_61 & V_11 ) >> V_14 ;
}
if ( V_61 & ( V_13 << V_14 ) ) {
int V_70 = F_26 ( V_2 , V_71 ) ;
void T_1 * V_19 = V_1 -> V_19 ;
T_3 V_24 = F_10 ( V_19 , V_20 ) ;
int V_72 ;
V_72 = F_27 ( V_1 ) && ( V_1 -> V_69 &
V_37 ) ;
if ( V_72 ) {
V_1 -> V_69 &= ~ V_37 ;
V_1 -> V_27 -> V_28 = V_35 ;
F_17 ( & V_38 , V_39 + V_40 * V_41 ) ;
F_28 ( L_5 ) ;
} else if ( F_27 ( V_1 ) && V_70 ) {
F_15 ( V_1 ) ;
V_57 -> V_73 = 1 ;
V_1 -> V_27 -> V_28 = V_36 ;
F_29 ( V_1 -> V_74 |= V_75 ) ;
F_21 ( & V_38 ) ;
} else {
V_1 -> V_44 = 0 ;
F_14 ( V_1 ) ;
V_57 -> V_73 = 0 ;
V_1 -> V_27 -> V_28 = V_33 ;
F_29 ( V_1 -> V_74 &= ~ V_75 ) ;
}
F_11 ( V_1 -> V_26 , L_6 ,
V_70 ? L_7 : L_8 ,
F_12 ( V_1 -> V_27 -> V_28 ) ,
V_72 ? L_9 : L_10 ,
V_24 ) ;
V_58 = V_76 ;
}
if ( V_1 -> V_65 || V_1 -> V_64 || V_1 -> V_69 )
V_58 |= F_30 ( V_1 ) ;
V_67:
if ( V_58 == V_76 || V_60 || V_61 ) {
if ( V_54 -> V_77 )
V_54 -> V_77 () ;
F_2 ( V_2 , V_21 , 0 ) ;
}
if ( F_3 ( V_1 ) && V_1 -> V_27 -> V_28 == V_33 )
F_17 ( & V_38 , V_39 + V_40 * V_41 ) ;
F_18 ( & V_1 -> V_29 , V_25 ) ;
return V_58 ;
}
static int F_31 ( struct V_1 * V_1 , T_3 V_78 )
{
struct V_48 * V_49 = V_1 -> V_26 ;
struct V_50 * V_51 = V_49 -> V_52 ;
struct V_53 * V_54 = V_51 -> V_55 ;
int V_79 = 0 ;
if ( V_54 -> V_80 )
V_54 -> V_80 ( V_78 ) ;
else
V_79 = - V_81 ;
return V_79 ;
}
static int F_32 ( struct V_1 * V_1 )
{
struct V_48 * V_49 = V_1 -> V_26 ;
struct V_50 * V_51 = V_49 -> V_52 ;
struct V_53 * V_54 = V_51 -> V_55 ;
void T_1 * V_2 = V_1 -> V_3 ;
T_2 V_82 ;
V_1 -> V_19 += V_83 ;
V_82 = F_26 ( V_2 , V_84 ) ;
if ( ! V_82 )
return - V_85 ;
F_33 () ;
V_1 -> V_27 = F_34 () ;
if ( ! V_1 -> V_27 )
return - V_85 ;
if ( F_27 ( V_1 ) )
F_35 ( & V_38 , F_9 , ( unsigned long ) V_1 ) ;
if ( V_54 -> V_86 )
V_54 -> V_86 () ;
F_2 ( V_2 , V_87 , V_88 ) ;
if ( V_54 -> V_89 )
V_54 -> V_89 ( 1 ) ;
F_36 ( 5 ) ;
V_1 -> V_90 = F_25 ;
if ( V_54 -> V_77 )
V_54 -> V_77 () ;
return 0 ;
}
static int F_37 ( struct V_1 * V_1 )
{
struct V_48 * V_49 = V_1 -> V_26 ;
struct V_50 * V_51 = V_49 -> V_52 ;
struct V_53 * V_54 = V_51 -> V_55 ;
if ( F_27 ( V_1 ) )
F_38 ( & V_38 ) ;
if ( V_54 -> V_89 )
V_54 -> V_89 ( 0 ) ;
F_39 ( V_1 -> V_27 ) ;
F_40 () ;
return 0 ;
}
void F_41 ( struct V_91 * V_92 , T_5 V_93 , T_3 * V_94 )
{
void T_1 * V_95 = V_92 -> V_95 ;
T_2 V_96 ;
int V_97 ;
if ( F_42 ( ( 0x03 & ( unsigned long ) V_94 ) == 0 ) && V_93 >= 4 ) {
F_43 ( V_95 , V_94 , V_93 >> 2 ) ;
V_94 += V_93 & ~ 0x03 ;
V_93 &= 0x03 ;
}
if ( V_93 > 4 ) {
for ( V_97 = 0 ; V_97 < ( V_93 >> 2 ) ; V_97 ++ ) {
* ( T_2 * ) V_94 = F_26 ( V_95 , 0 ) ;
V_94 += 4 ;
}
V_93 &= 0x03 ;
}
if ( V_93 > 0 ) {
V_96 = F_26 ( V_95 , 0 ) ;
memcpy ( V_94 , & V_96 , V_93 ) ;
}
}
static int T_6 F_44 ( struct V_98 * V_99 )
{
struct V_50 * V_100 = V_99 -> V_49 . V_52 ;
struct V_98 * V_1 ;
struct V_101 * V_102 ;
struct V_103 * V_104 ;
struct V_103 * V_103 ;
int V_58 = - V_105 ;
V_102 = F_45 ( sizeof( * V_102 ) , V_106 ) ;
if ( ! V_102 ) {
F_46 ( & V_99 -> V_49 , L_11 ) ;
goto V_107;
}
V_1 = F_47 ( L_12 , - 1 ) ;
if ( ! V_1 ) {
F_46 ( & V_99 -> V_49 , L_13 ) ;
goto V_108;
}
V_104 = F_48 ( & V_99 -> V_49 , L_14 ) ;
if ( F_49 ( V_104 ) ) {
F_46 ( & V_99 -> V_49 , L_15 ) ;
V_58 = F_50 ( V_104 ) ;
goto V_109;
}
V_103 = F_48 ( & V_99 -> V_49 , L_16 ) ;
if ( F_49 ( V_103 ) ) {
F_46 ( & V_99 -> V_49 , L_17 ) ;
V_58 = F_50 ( V_103 ) ;
goto V_110;
}
V_58 = F_51 ( V_104 ) ;
if ( V_58 ) {
F_46 ( & V_99 -> V_49 , L_18 ) ;
goto V_111;
}
V_58 = F_51 ( V_103 ) ;
if ( V_58 ) {
F_46 ( & V_99 -> V_49 , L_19 ) ;
goto V_112;
}
V_1 -> V_49 . V_113 = & V_99 -> V_49 ;
V_1 -> V_49 . V_114 = & V_115 ;
V_1 -> V_49 . V_116 = V_115 ;
V_102 -> V_49 = & V_99 -> V_49 ;
V_102 -> V_1 = V_1 ;
V_102 -> V_104 = V_104 ;
V_102 -> V_103 = V_103 ;
V_100 -> V_117 = & V_118 ;
F_52 ( V_99 , V_102 ) ;
V_58 = F_53 ( V_1 , V_99 -> V_119 ,
V_99 -> V_120 ) ;
if ( V_58 ) {
F_46 ( & V_99 -> V_49 , L_20 ) ;
goto V_121;
}
V_58 = F_54 ( V_1 , V_100 , sizeof( * V_100 ) ) ;
if ( V_58 ) {
F_46 ( & V_99 -> V_49 , L_21 ) ;
goto V_121;
}
V_58 = F_55 ( V_1 ) ;
if ( V_58 ) {
F_46 ( & V_99 -> V_49 , L_22 ) ;
goto V_121;
}
return 0 ;
V_121:
F_56 ( V_103 ) ;
V_112:
F_56 ( V_104 ) ;
V_111:
F_57 ( V_103 ) ;
V_110:
F_57 ( V_104 ) ;
V_109:
F_58 ( V_1 ) ;
V_108:
F_59 ( V_102 ) ;
V_107:
return V_58 ;
}
static int T_7 F_60 ( struct V_98 * V_99 )
{
struct V_101 * V_102 = F_61 ( V_99 ) ;
F_62 ( V_102 -> V_1 ) ;
F_58 ( V_102 -> V_1 ) ;
F_56 ( V_102 -> V_103 ) ;
F_56 ( V_102 -> V_104 ) ;
F_57 ( V_102 -> V_103 ) ;
F_57 ( V_102 -> V_104 ) ;
F_59 ( V_102 ) ;
return 0 ;
}
static int F_63 ( struct V_48 * V_49 )
{
struct V_101 * V_102 = F_64 ( V_49 ) ;
struct V_50 * V_51 = V_49 -> V_52 ;
struct V_53 * V_54 = V_51 -> V_55 ;
if ( V_54 -> V_89 )
V_54 -> V_89 ( 0 ) ;
F_56 ( V_102 -> V_104 ) ;
F_56 ( V_102 -> V_103 ) ;
return 0 ;
}
static int F_65 ( struct V_48 * V_49 )
{
struct V_101 * V_102 = F_64 ( V_49 ) ;
struct V_50 * V_51 = V_49 -> V_52 ;
struct V_53 * V_54 = V_51 -> V_55 ;
int V_58 ;
if ( V_54 -> V_89 )
V_54 -> V_89 ( 1 ) ;
V_58 = F_51 ( V_102 -> V_104 ) ;
if ( V_58 ) {
F_46 ( V_49 , L_18 ) ;
return V_58 ;
}
V_58 = F_51 ( V_102 -> V_103 ) ;
if ( V_58 ) {
F_46 ( V_49 , L_19 ) ;
return V_58 ;
}
return 0 ;
}
static int T_8 F_66 ( void )
{
return F_67 ( & V_122 ) ;
}
static void T_9 F_68 ( void )
{
F_69 ( & V_122 ) ;
}
