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
if ( F_10 ( V_10 ) )
F_9 ( V_11 , V_21 ,
V_22 << V_23 ) ;
}
static void F_11 ( struct V_10 * V_10 )
{
void T_2 * V_11 = V_10 -> V_12 ;
F_9 ( V_11 , V_24 ,
V_19 |
V_25 | V_26 ) ;
F_12 ( V_10 -> V_27 , V_28 , 0 ) ;
F_9 ( V_11 , V_29 , 0 ) ;
}
static void F_13 ( struct V_10 * V_10 , int V_30 )
{
F_14 ( V_30 && F_15 ( V_10 ) ) ;
}
static void F_16 ( unsigned long V_31 )
{
struct V_10 * V_10 = ( void * ) V_31 ;
void T_2 * V_27 = V_10 -> V_27 ;
T_3 V_32 ;
unsigned long V_33 ;
V_32 = F_17 ( V_27 , V_28 ) ;
F_18 ( V_10 -> V_34 , L_4 , V_32 ,
F_19 ( V_10 -> V_35 -> V_36 ) ) ;
F_20 ( & V_10 -> V_37 , V_33 ) ;
switch ( V_10 -> V_35 -> V_36 ) {
case V_38 :
V_32 &= ~ V_39 ;
F_12 ( V_10 -> V_27 , V_28 , V_32 ) ;
V_32 = F_17 ( V_10 -> V_27 , V_28 ) ;
if ( V_32 & V_40 ) {
V_10 -> V_35 -> V_36 = V_41 ;
F_21 ( V_10 ) ;
} else {
V_10 -> V_35 -> V_36 = V_42 ;
F_22 ( V_10 ) ;
}
break;
case V_43 :
if ( V_32 & V_44 ) {
F_23 ( & V_45 , V_46 + V_47 * V_48 ) ;
break;
}
V_10 -> V_35 -> V_36 = V_49 ;
F_9 ( V_10 -> V_12 , V_21 ,
V_50 << V_23 ) ;
break;
case V_41 :
if ( ! F_24 ( V_10 ) )
break;
F_12 ( V_27 , V_28 , V_32 | V_39 ) ;
V_32 = F_17 ( V_27 , V_28 ) ;
if ( V_32 & V_40 )
F_23 ( & V_45 , V_46 + V_47 * V_48 ) ;
else
V_10 -> V_35 -> V_36 = V_42 ;
break;
default:
break;
}
F_25 ( & V_10 -> V_37 , V_33 ) ;
}
static void F_26 ( struct V_10 * V_10 , unsigned long V_51 )
{
static unsigned long V_52 ;
if ( ! F_10 ( V_10 ) )
return;
if ( V_51 == 0 )
V_51 = V_46 + F_27 ( 3 ) ;
if ( V_10 -> V_53 || ( V_10 -> V_54 == 0 &&
V_10 -> V_35 -> V_36 == V_38 ) ) {
F_18 ( V_10 -> V_34 , L_5 ,
F_19 ( V_10 -> V_35 -> V_36 ) ) ;
F_28 ( & V_45 ) ;
V_52 = V_46 ;
return;
}
if ( F_29 ( V_52 , V_51 ) && F_30 ( & V_45 ) ) {
F_18 ( V_10 -> V_34 , L_6 ) ;
return;
}
V_52 = V_51 ;
F_18 ( V_10 -> V_34 , L_7 ,
F_19 ( V_10 -> V_35 -> V_36 ) ,
F_31 ( V_51 - V_46 ) ) ;
F_23 ( & V_45 , V_51 ) ;
}
static T_4 F_32 ( int V_55 , void * V_56 )
{
struct V_10 * V_10 = V_56 ;
void T_2 * V_11 = V_10 -> V_12 ;
struct V_57 * V_58 = V_10 -> V_35 -> V_58 ;
unsigned long V_33 ;
T_4 V_59 = V_60 ;
T_1 V_61 ;
F_20 ( & V_10 -> V_37 , V_33 ) ;
V_61 = F_33 ( V_11 , V_62 ) ;
if ( ! V_61 )
goto V_63;
F_9 ( V_11 , V_64 , V_61 ) ;
F_18 ( V_10 -> V_34 , L_8 , V_61 ) ;
V_10 -> V_65 = ( V_61 & V_26 ) >> V_18 ;
V_10 -> V_66 = ( V_61 & V_25 ) >> V_16 ;
V_10 -> V_67 = ( V_61 & V_19 ) >> V_23 ;
if ( V_61 & ( V_22 << V_23 ) ) {
int V_68 = F_33 ( V_11 , V_69 ) ;
void T_2 * V_27 = V_10 -> V_27 ;
T_3 V_32 = F_17 ( V_27 , V_28 ) ;
int V_70 ;
V_70 = F_34 ( V_10 ) && ( V_10 -> V_67 &
V_50 ) ;
if ( V_70 ) {
V_10 -> V_67 &= ~ V_50 ;
V_10 -> V_35 -> V_36 = V_43 ;
F_23 ( & V_45 , V_46 + V_47 * V_48 ) ;
F_35 ( L_9 ) ;
} else if ( F_34 ( V_10 ) && V_68 ) {
F_22 ( V_10 ) ;
V_58 -> V_71 = 1 ;
V_10 -> V_35 -> V_36 = V_49 ;
F_36 ( V_10 -> V_72 |= V_73 ) ;
F_28 ( & V_45 ) ;
} else {
V_10 -> V_53 = 0 ;
F_21 ( V_10 ) ;
V_58 -> V_71 = 0 ;
V_10 -> V_35 -> V_36 = V_41 ;
F_36 ( V_10 -> V_72 &= ~ V_73 ) ;
}
F_18 ( V_10 -> V_34 , L_10 ,
V_68 ? L_11 : L_12 ,
F_19 ( V_10 -> V_35 -> V_36 ) ,
V_70 ? L_13 : L_14 ,
V_32 ) ;
V_59 = V_74 ;
}
if ( V_10 -> V_66 || V_10 -> V_65 || V_10 -> V_67 )
V_59 |= F_37 ( V_10 ) ;
V_63:
if ( V_59 == V_74 || V_61 )
F_9 ( V_11 , V_29 , 0 ) ;
if ( F_10 ( V_10 ) && V_10 -> V_35 -> V_36 == V_41 )
F_23 ( & V_45 , V_46 + V_47 * V_48 ) ;
F_25 ( & V_10 -> V_37 , V_33 ) ;
return V_59 ;
}
static int F_38 ( struct V_10 * V_10 , T_3 V_75 )
{
T_1 V_1 = F_2 ( V_2 ) ;
V_1 &= ~ V_76 ;
switch ( V_75 ) {
case V_77 :
V_1 |= V_78 ;
break;
case V_79 :
V_1 |= V_80 ;
break;
case V_81 :
V_1 |= V_82 ;
break;
default:
F_18 ( V_10 -> V_34 , L_15 , V_75 ) ;
}
F_3 ( V_1 , V_2 ) ;
return 0 ;
}
static int F_39 ( struct V_10 * V_10 )
{
void T_2 * V_11 = V_10 -> V_12 ;
T_1 V_83 ;
V_10 -> V_27 += V_84 ;
V_83 = F_33 ( V_11 , V_85 ) ;
if ( ! V_83 )
goto V_86;
F_40 () ;
V_10 -> V_35 = F_41 () ;
if ( ! V_10 -> V_35 )
goto V_86;
if ( F_34 ( V_10 ) )
F_42 ( & V_45 , F_16 , ( unsigned long ) V_10 ) ;
F_9 ( V_11 , V_87 , V_88 ) ;
F_1 () ;
F_43 ( 5 ) ;
F_44 ( L_16 ,
V_83 , F_2 ( V_2 ) ,
F_17 ( V_11 , V_87 ) ) ;
V_10 -> V_89 = F_32 ;
return 0 ;
V_86:
return - V_90 ;
}
static int F_45 ( struct V_10 * V_10 )
{
if ( F_34 ( V_10 ) )
F_46 ( & V_45 ) ;
F_6 () ;
F_47 ( V_10 -> V_35 ) ;
F_48 () ;
return 0 ;
}
static int T_5 F_49 ( struct V_91 * V_92 )
{
struct V_93 * V_94 = V_92 -> V_95 . V_96 ;
struct V_91 * V_10 ;
struct V_97 * V_98 ;
struct V_99 * V_99 ;
int V_59 = - V_100 ;
V_98 = F_50 ( sizeof( * V_98 ) , V_101 ) ;
if ( ! V_98 ) {
F_51 ( & V_92 -> V_95 , L_17 ) ;
goto V_102;
}
V_10 = F_52 ( L_18 , - 1 ) ;
if ( ! V_10 ) {
F_51 ( & V_92 -> V_95 , L_19 ) ;
goto V_103;
}
V_99 = F_53 ( & V_92 -> V_95 , L_20 ) ;
if ( F_54 ( V_99 ) ) {
F_51 ( & V_92 -> V_95 , L_21 ) ;
V_59 = F_55 ( V_99 ) ;
goto V_104;
}
V_59 = F_56 ( V_99 ) ;
if ( V_59 ) {
F_51 ( & V_92 -> V_95 , L_22 ) ;
goto V_105;
}
V_10 -> V_95 . V_106 = & V_92 -> V_95 ;
V_10 -> V_95 . V_107 = & V_108 ;
V_10 -> V_95 . V_109 = V_108 ;
V_98 -> V_95 = & V_92 -> V_95 ;
V_98 -> V_10 = V_10 ;
V_98 -> V_99 = V_99 ;
V_94 -> V_110 = & V_111 ;
F_57 ( V_92 , V_98 ) ;
V_59 = F_58 ( V_10 , V_92 -> V_112 ,
V_92 -> V_113 ) ;
if ( V_59 ) {
F_51 ( & V_92 -> V_95 , L_23 ) ;
goto V_114;
}
V_59 = F_59 ( V_10 , V_94 , sizeof( * V_94 ) ) ;
if ( V_59 ) {
F_51 ( & V_92 -> V_95 , L_24 ) ;
goto V_114;
}
V_59 = F_60 ( V_10 ) ;
if ( V_59 ) {
F_51 ( & V_92 -> V_95 , L_25 ) ;
goto V_114;
}
return 0 ;
V_114:
F_61 ( V_99 ) ;
V_105:
F_62 ( V_99 ) ;
V_104:
F_63 ( V_10 ) ;
V_103:
F_64 ( V_98 ) ;
V_102:
return V_59 ;
}
static int T_6 F_65 ( struct V_91 * V_92 )
{
struct V_97 * V_98 = F_66 ( V_92 ) ;
F_67 ( V_98 -> V_10 ) ;
F_63 ( V_98 -> V_10 ) ;
F_61 ( V_98 -> V_99 ) ;
F_62 ( V_98 -> V_99 ) ;
F_64 ( V_98 ) ;
return 0 ;
}
static int T_7 F_68 ( void )
{
return F_69 ( & V_115 ) ;
}
static void T_8 F_70 ( void )
{
F_71 ( & V_115 ) ;
}
