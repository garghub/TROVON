static inline void F_1 ( void )
{
T_1 V_1 = F_2 ( V_2 ) ;
V_1 &= ~ ( V_3 | V_4 | V_5 ) ;
V_1 |= V_6 ;
F_3 ( V_1 , V_2 ) ;
F_4 ( L_1 ) ;
while ( ! ( F_2 ( V_2 ) & V_7 ) )
F_5 () ;
}
static inline void F_6 ( void )
{
T_1 V_1 = F_2 ( V_2 ) ;
if ( ! ( V_1 & V_8 ) &&
( V_1 & V_9 ) ) {
F_7 ( L_2
L_3 ) ;
return;
}
V_1 |= V_4 | V_5 ;
F_3 ( V_1 , V_2 ) ;
}
static void F_8 ( struct V_10 * V_10 )
{
void T_2 * V_11 = V_10 -> V_12 ;
T_1 V_13 ;
V_13 = ( ( V_10 -> V_14 & V_15 ) << V_16 ) |
( ( V_10 -> V_14 & V_17 ) << V_18 ) |
V_19 ;
F_9 ( V_11 , V_20 , V_13 ) ;
F_9 ( V_11 , V_21 ,
V_22 << V_23 ) ;
}
static void F_10 ( struct V_10 * V_10 )
{
void T_2 * V_11 = V_10 -> V_12 ;
F_9 ( V_11 , V_24 ,
V_19 |
V_25 | V_26 ) ;
F_11 ( V_10 -> V_27 , V_28 , 0 ) ;
F_9 ( V_11 , V_29 , 0 ) ;
}
static void F_12 ( struct V_10 * V_10 , int V_30 )
{
F_13 ( V_30 && F_14 ( V_10 ) ) ;
}
static void F_15 ( unsigned long V_31 )
{
struct V_10 * V_10 = ( void * ) V_31 ;
void T_2 * V_27 = V_10 -> V_27 ;
T_3 V_32 ;
unsigned long V_33 ;
V_32 = F_16 ( V_27 , V_28 ) ;
F_17 ( V_10 -> V_34 , L_4 , V_32 ,
F_18 ( V_10 -> V_35 -> V_36 ) ) ;
F_19 ( & V_10 -> V_37 , V_33 ) ;
switch ( V_10 -> V_35 -> V_36 ) {
case V_38 :
V_32 &= ~ V_39 ;
F_11 ( V_10 -> V_27 , V_28 , V_32 ) ;
V_32 = F_16 ( V_10 -> V_27 , V_28 ) ;
if ( V_32 & V_40 ) {
V_10 -> V_35 -> V_36 = V_41 ;
F_20 ( V_10 ) ;
} else {
V_10 -> V_35 -> V_36 = V_42 ;
F_21 ( V_10 ) ;
}
break;
case V_43 :
if ( V_32 & V_44 ) {
F_22 ( & V_45 , V_46 + V_47 * V_48 ) ;
break;
}
V_10 -> V_35 -> V_36 = V_49 ;
F_9 ( V_10 -> V_12 , V_21 ,
V_50 << V_23 ) ;
break;
case V_41 :
F_11 ( V_27 , V_28 , V_32 | V_39 ) ;
V_32 = F_16 ( V_27 , V_28 ) ;
if ( V_32 & V_40 )
F_22 ( & V_45 , V_46 + V_47 * V_48 ) ;
else
V_10 -> V_35 -> V_36 = V_42 ;
break;
default:
break;
}
F_23 ( & V_10 -> V_37 , V_33 ) ;
}
static void F_24 ( struct V_10 * V_10 , unsigned long V_51 )
{
static unsigned long V_52 ;
if ( V_51 == 0 )
V_51 = V_46 + F_25 ( 3 ) ;
if ( V_10 -> V_53 || ( V_10 -> V_54 == 0 &&
V_10 -> V_35 -> V_36 == V_38 ) ) {
F_17 ( V_10 -> V_34 , L_5 ,
F_18 ( V_10 -> V_35 -> V_36 ) ) ;
F_26 ( & V_45 ) ;
V_52 = V_46 ;
return;
}
if ( F_27 ( V_52 , V_51 ) && F_28 ( & V_45 ) ) {
F_17 ( V_10 -> V_34 , L_6 ) ;
return;
}
V_52 = V_51 ;
F_17 ( V_10 -> V_34 , L_7 ,
F_18 ( V_10 -> V_35 -> V_36 ) ,
F_29 ( V_51 - V_46 ) ) ;
F_22 ( & V_45 , V_51 ) ;
}
static T_4 F_30 ( int V_55 , void * V_56 )
{
struct V_10 * V_10 = V_56 ;
void T_2 * V_11 = V_10 -> V_12 ;
struct V_57 * V_58 = V_10 -> V_35 -> V_58 ;
unsigned long V_33 ;
T_4 V_59 = V_60 ;
T_1 V_61 ;
F_19 ( & V_10 -> V_37 , V_33 ) ;
V_61 = F_31 ( V_11 , V_62 ) ;
if ( ! V_61 )
goto V_63;
F_9 ( V_11 , V_64 , V_61 ) ;
F_17 ( V_10 -> V_34 , L_8 , V_61 ) ;
V_10 -> V_65 = ( V_61 & V_26 ) >> V_18 ;
V_10 -> V_66 = ( V_61 & V_25 ) >> V_16 ;
V_10 -> V_67 = ( V_61 & V_19 ) >> V_23 ;
if ( V_61 & ( V_22 << V_23 ) ) {
int V_68 = F_31 ( V_11 , V_69 ) ;
void T_2 * V_27 = V_10 -> V_27 ;
T_3 V_32 = F_16 ( V_27 , V_28 ) ;
int V_70 ;
V_70 = V_10 -> V_67 & V_71 ;
if ( V_70 ) {
V_10 -> V_67 &= ~ V_50 ;
V_10 -> V_35 -> V_36 = V_43 ;
F_22 ( & V_45 , V_46 + V_47 * V_48 ) ;
F_32 ( L_9 ) ;
} else if ( V_68 ) {
F_21 ( V_10 ) ;
V_58 -> V_72 = 1 ;
V_10 -> V_35 -> V_36 = V_49 ;
F_33 ( V_10 -> V_73 |= V_74 ) ;
F_26 ( & V_45 ) ;
} else {
V_10 -> V_53 = 0 ;
F_20 ( V_10 ) ;
V_58 -> V_72 = 0 ;
V_10 -> V_35 -> V_36 = V_41 ;
F_33 ( V_10 -> V_73 &= ~ V_74 ) ;
}
F_17 ( V_10 -> V_34 , L_10 ,
V_68 ? L_11 : L_12 ,
F_18 ( V_10 -> V_35 -> V_36 ) ,
V_70 ? L_13 : L_14 ,
V_32 ) ;
V_59 = V_75 ;
}
if ( V_10 -> V_66 || V_10 -> V_65 || V_10 -> V_67 )
V_59 |= F_34 ( V_10 ) ;
V_63:
if ( V_59 == V_75 || V_61 )
F_9 ( V_11 , V_29 , 0 ) ;
if ( V_10 -> V_35 -> V_36 == V_41 )
F_22 ( & V_45 , V_46 + V_47 * V_48 ) ;
F_23 ( & V_10 -> V_37 , V_33 ) ;
return V_59 ;
}
static int F_35 ( struct V_10 * V_10 , T_3 V_76 )
{
T_1 V_1 = F_2 ( V_2 ) ;
V_1 &= ~ V_77 ;
switch ( V_76 ) {
case V_78 :
V_1 |= V_79 ;
break;
case V_80 :
V_1 |= V_81 ;
break;
case V_82 :
V_1 |= V_83 ;
break;
default:
F_17 ( V_10 -> V_34 , L_15 , V_76 ) ;
}
F_3 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_36 ( struct V_10 * V_10 )
{
void T_2 * V_11 = V_10 -> V_12 ;
T_1 V_84 ;
V_10 -> V_27 += V_85 ;
V_84 = F_31 ( V_11 , V_86 ) ;
if ( ! V_84 )
goto V_87;
F_37 () ;
V_10 -> V_35 = F_38 ( V_88 ) ;
if ( F_39 ( V_10 -> V_35 ) )
goto V_87;
F_40 ( & V_45 , F_15 , ( unsigned long ) V_10 ) ;
F_9 ( V_11 , V_89 , V_90 ) ;
F_1 () ;
F_41 ( 5 ) ;
F_42 ( L_16 ,
V_84 , F_2 ( V_2 ) ,
F_16 ( V_11 , V_89 ) ) ;
V_10 -> V_91 = F_30 ;
return 0 ;
V_87:
return - V_92 ;
}
static int F_43 ( struct V_10 * V_10 )
{
F_44 ( & V_45 ) ;
F_6 () ;
F_45 ( V_10 -> V_35 ) ;
F_46 () ;
return 0 ;
}
static int T_5 F_47 ( struct V_93 * V_94 )
{
struct V_95 * V_96 = V_94 -> V_97 . V_98 ;
struct V_93 * V_10 ;
struct V_99 * V_100 ;
struct V_101 * V_101 ;
int V_59 = - V_102 ;
int V_103 ;
V_100 = F_48 ( sizeof( * V_100 ) , V_104 ) ;
if ( ! V_100 ) {
F_49 ( & V_94 -> V_97 , L_17 ) ;
goto V_105;
}
V_103 = F_50 ( & V_94 -> V_97 , V_104 ) ;
if ( V_103 < 0 ) {
F_49 ( & V_94 -> V_97 , L_18 ) ;
V_59 = - V_102 ;
goto V_106;
}
V_10 = F_51 ( L_19 , V_103 ) ;
if ( ! V_10 ) {
F_49 ( & V_94 -> V_97 , L_20 ) ;
goto V_107;
}
V_101 = F_52 ( & V_94 -> V_97 , L_21 ) ;
if ( F_53 ( V_101 ) ) {
F_49 ( & V_94 -> V_97 , L_22 ) ;
V_59 = F_54 ( V_101 ) ;
goto V_108;
}
V_59 = F_55 ( V_101 ) ;
if ( V_59 ) {
F_49 ( & V_94 -> V_97 , L_23 ) ;
goto V_109;
}
V_10 -> V_110 = V_103 ;
V_10 -> V_97 . V_111 = & V_94 -> V_97 ;
V_10 -> V_97 . V_112 = & V_113 ;
V_10 -> V_97 . V_114 = V_113 ;
V_100 -> V_97 = & V_94 -> V_97 ;
V_100 -> V_10 = V_10 ;
V_100 -> V_101 = V_101 ;
V_96 -> V_115 = & V_116 ;
F_56 ( V_94 , V_100 ) ;
V_59 = F_57 ( V_10 , V_94 -> V_117 ,
V_94 -> V_118 ) ;
if ( V_59 ) {
F_49 ( & V_94 -> V_97 , L_24 ) ;
goto V_119;
}
V_59 = F_58 ( V_10 , V_96 , sizeof( * V_96 ) ) ;
if ( V_59 ) {
F_49 ( & V_94 -> V_97 , L_25 ) ;
goto V_119;
}
V_59 = F_59 ( V_10 ) ;
if ( V_59 ) {
F_49 ( & V_94 -> V_97 , L_26 ) ;
goto V_119;
}
return 0 ;
V_119:
F_60 ( V_101 ) ;
V_109:
F_61 ( V_101 ) ;
V_108:
F_62 ( V_10 ) ;
V_107:
F_63 ( & V_94 -> V_97 , V_103 ) ;
V_106:
F_64 ( V_100 ) ;
V_105:
return V_59 ;
}
static int T_6 F_65 ( struct V_93 * V_94 )
{
struct V_99 * V_100 = F_66 ( V_94 ) ;
F_63 ( & V_94 -> V_97 , V_100 -> V_10 -> V_110 ) ;
F_67 ( V_100 -> V_10 ) ;
F_62 ( V_100 -> V_10 ) ;
F_60 ( V_100 -> V_101 ) ;
F_61 ( V_100 -> V_101 ) ;
F_64 ( V_100 ) ;
return 0 ;
}
static int T_7 F_68 ( void )
{
return F_69 ( & V_120 ) ;
}
static void T_8 F_70 ( void )
{
F_71 ( & V_120 ) ;
}
