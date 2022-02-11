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
unsigned long V_25 ;
T_4 V_56 = V_57 ;
T_2 V_58 , V_59 ;
F_13 ( & V_1 -> V_29 , V_25 ) ;
V_58 = F_26 ( V_2 , V_60 ) ;
if ( V_58 ) {
F_2 ( V_2 , V_61 , V_58 ) ;
V_1 -> V_62 =
( V_58 & V_18 ) >> V_8 ;
V_1 -> V_63 =
( V_58 & V_17 ) >> V_6 ;
}
V_59 = F_26 ( V_2 , V_64 ) ;
if ( ! V_59 && ! V_58 )
goto V_65;
if ( V_59 ) {
F_2 ( V_2 , V_66 , V_59 ) ;
V_1 -> V_67 =
( V_59 & V_11 ) >> V_14 ;
}
if ( V_59 & ( V_13 << V_14 ) ) {
int V_68 = F_26 ( V_2 , V_69 ) ;
void T_1 * V_19 = V_1 -> V_19 ;
T_3 V_24 = F_10 ( V_19 , V_20 ) ;
int V_70 ;
V_70 = F_27 ( V_1 ) && ( V_1 -> V_67 &
V_37 ) ;
if ( V_70 ) {
V_1 -> V_67 &= ~ V_37 ;
V_1 -> V_27 -> V_28 = V_35 ;
F_17 ( & V_38 , V_39 + V_40 * V_41 ) ;
F_28 ( L_5 ) ;
} else if ( F_27 ( V_1 ) && V_68 ) {
F_15 ( V_1 ) ;
V_1 -> V_27 -> V_71 = 1 ;
V_1 -> V_27 -> V_28 = V_36 ;
F_29 ( V_1 -> V_72 |= V_73 ) ;
F_21 ( & V_38 ) ;
} else {
V_1 -> V_44 = 0 ;
F_14 ( V_1 ) ;
V_1 -> V_27 -> V_71 = 0 ;
V_1 -> V_27 -> V_28 = V_33 ;
F_29 ( V_1 -> V_72 &= ~ V_73 ) ;
}
F_11 ( V_1 -> V_26 , L_6 ,
V_68 ? L_7 : L_8 ,
F_12 ( V_1 -> V_27 -> V_28 ) ,
V_70 ? L_9 : L_10 ,
V_24 ) ;
V_56 = V_74 ;
}
if ( V_1 -> V_63 || V_1 -> V_62 || V_1 -> V_67 )
V_56 |= F_30 ( V_1 ) ;
V_65:
if ( V_56 == V_74 || V_58 || V_59 ) {
if ( V_54 -> V_75 )
V_54 -> V_75 () ;
F_2 ( V_2 , V_21 , 0 ) ;
}
if ( F_3 ( V_1 ) && V_1 -> V_27 -> V_28 == V_33 )
F_17 ( & V_38 , V_39 + V_40 * V_41 ) ;
F_18 ( & V_1 -> V_29 , V_25 ) ;
return V_56 ;
}
static int F_31 ( struct V_1 * V_1 , T_3 V_76 )
{
struct V_48 * V_49 = V_1 -> V_26 ;
struct V_50 * V_51 = V_49 -> V_52 ;
struct V_53 * V_54 = V_51 -> V_55 ;
int V_77 = 0 ;
if ( V_54 -> V_78 )
V_54 -> V_78 ( V_76 ) ;
else
V_77 = - V_79 ;
return V_77 ;
}
static int F_32 ( struct V_1 * V_1 )
{
struct V_48 * V_49 = V_1 -> V_26 ;
struct V_50 * V_51 = V_49 -> V_52 ;
struct V_53 * V_54 = V_51 -> V_55 ;
void T_1 * V_2 = V_1 -> V_3 ;
T_2 V_80 ;
V_1 -> V_19 += V_81 ;
V_80 = F_26 ( V_2 , V_82 ) ;
if ( ! V_80 )
return - V_83 ;
F_33 () ;
V_1 -> V_27 = F_34 () ;
if ( ! V_1 -> V_27 )
return - V_83 ;
if ( F_27 ( V_1 ) )
F_35 ( & V_38 , F_9 , ( unsigned long ) V_1 ) ;
if ( V_54 -> V_84 )
V_54 -> V_84 () ;
F_2 ( V_2 , V_85 , V_86 ) ;
if ( V_54 -> V_87 )
V_54 -> V_87 ( 1 ) ;
F_36 ( 5 ) ;
V_1 -> V_88 = F_25 ;
if ( V_54 -> V_75 )
V_54 -> V_75 () ;
return 0 ;
}
static int F_37 ( struct V_1 * V_1 )
{
struct V_48 * V_49 = V_1 -> V_26 ;
struct V_50 * V_51 = V_49 -> V_52 ;
struct V_53 * V_54 = V_51 -> V_55 ;
if ( F_27 ( V_1 ) )
F_38 ( & V_38 ) ;
if ( V_54 -> V_87 )
V_54 -> V_87 ( 0 ) ;
F_39 ( V_1 -> V_27 ) ;
F_40 () ;
return 0 ;
}
void F_41 ( struct V_89 * V_90 , T_5 V_91 , T_3 * V_92 )
{
void T_1 * V_93 = V_90 -> V_93 ;
T_2 V_94 ;
int V_95 ;
if ( F_42 ( ( 0x03 & ( unsigned long ) V_92 ) == 0 ) && V_91 >= 4 ) {
F_43 ( V_93 , V_92 , V_91 >> 2 ) ;
V_92 += V_91 & ~ 0x03 ;
V_91 &= 0x03 ;
}
if ( V_91 > 4 ) {
for ( V_95 = 0 ; V_95 < ( V_91 >> 2 ) ; V_95 ++ ) {
* ( T_2 * ) V_92 = F_26 ( V_93 , 0 ) ;
V_92 += 4 ;
}
V_91 &= 0x03 ;
}
if ( V_91 > 0 ) {
V_94 = F_26 ( V_93 , 0 ) ;
memcpy ( V_92 , & V_94 , V_91 ) ;
}
}
static int T_6 F_44 ( struct V_96 * V_97 )
{
struct V_50 * V_98 = V_97 -> V_49 . V_52 ;
struct V_96 * V_1 ;
struct V_99 * V_100 ;
struct V_101 * V_102 ;
struct V_101 * V_101 ;
int V_56 = - V_103 ;
V_100 = F_45 ( sizeof( * V_100 ) , V_104 ) ;
if ( ! V_100 ) {
F_46 ( & V_97 -> V_49 , L_11 ) ;
goto V_105;
}
V_1 = F_47 ( L_12 , - 1 ) ;
if ( ! V_1 ) {
F_46 ( & V_97 -> V_49 , L_13 ) ;
goto V_106;
}
V_102 = F_48 ( & V_97 -> V_49 , L_14 ) ;
if ( F_49 ( V_102 ) ) {
F_46 ( & V_97 -> V_49 , L_15 ) ;
V_56 = F_50 ( V_102 ) ;
goto V_107;
}
V_101 = F_48 ( & V_97 -> V_49 , L_16 ) ;
if ( F_49 ( V_101 ) ) {
F_46 ( & V_97 -> V_49 , L_17 ) ;
V_56 = F_50 ( V_101 ) ;
goto V_108;
}
V_56 = F_51 ( V_102 ) ;
if ( V_56 ) {
F_46 ( & V_97 -> V_49 , L_18 ) ;
goto V_109;
}
V_56 = F_51 ( V_101 ) ;
if ( V_56 ) {
F_46 ( & V_97 -> V_49 , L_19 ) ;
goto V_110;
}
V_1 -> V_49 . V_111 = & V_97 -> V_49 ;
V_1 -> V_49 . V_112 = & V_113 ;
V_1 -> V_49 . V_114 = V_113 ;
V_100 -> V_49 = & V_97 -> V_49 ;
V_100 -> V_1 = V_1 ;
V_100 -> V_102 = V_102 ;
V_100 -> V_101 = V_101 ;
V_98 -> V_115 = & V_116 ;
F_52 ( V_97 , V_100 ) ;
V_56 = F_53 ( V_1 , V_97 -> V_117 ,
V_97 -> V_118 ) ;
if ( V_56 ) {
F_46 ( & V_97 -> V_49 , L_20 ) ;
goto V_119;
}
V_56 = F_54 ( V_1 , V_98 , sizeof( * V_98 ) ) ;
if ( V_56 ) {
F_46 ( & V_97 -> V_49 , L_21 ) ;
goto V_119;
}
V_56 = F_55 ( V_1 ) ;
if ( V_56 ) {
F_46 ( & V_97 -> V_49 , L_22 ) ;
goto V_119;
}
return 0 ;
V_119:
F_56 ( V_101 ) ;
V_110:
F_56 ( V_102 ) ;
V_109:
F_57 ( V_101 ) ;
V_108:
F_57 ( V_102 ) ;
V_107:
F_58 ( V_1 ) ;
V_106:
F_59 ( V_100 ) ;
V_105:
return V_56 ;
}
static int T_7 F_60 ( struct V_96 * V_97 )
{
struct V_99 * V_100 = F_61 ( V_97 ) ;
F_62 ( V_100 -> V_1 ) ;
F_58 ( V_100 -> V_1 ) ;
F_56 ( V_100 -> V_101 ) ;
F_56 ( V_100 -> V_102 ) ;
F_57 ( V_100 -> V_101 ) ;
F_57 ( V_100 -> V_102 ) ;
F_59 ( V_100 ) ;
return 0 ;
}
static int F_63 ( struct V_48 * V_49 )
{
struct V_99 * V_100 = F_64 ( V_49 ) ;
struct V_50 * V_51 = V_49 -> V_52 ;
struct V_53 * V_54 = V_51 -> V_55 ;
if ( V_54 -> V_87 )
V_54 -> V_87 ( 0 ) ;
F_56 ( V_100 -> V_102 ) ;
F_56 ( V_100 -> V_101 ) ;
return 0 ;
}
static int F_65 ( struct V_48 * V_49 )
{
struct V_99 * V_100 = F_64 ( V_49 ) ;
struct V_50 * V_51 = V_49 -> V_52 ;
struct V_53 * V_54 = V_51 -> V_55 ;
int V_56 ;
if ( V_54 -> V_87 )
V_54 -> V_87 ( 1 ) ;
V_56 = F_51 ( V_100 -> V_102 ) ;
if ( V_56 ) {
F_46 ( V_49 , L_18 ) ;
return V_56 ;
}
V_56 = F_51 ( V_100 -> V_101 ) ;
if ( V_56 ) {
F_46 ( V_49 , L_19 ) ;
return V_56 ;
}
return 0 ;
}
static int T_6 F_66 ( void )
{
return F_67 ( & V_120 , F_44 ) ;
}
static void T_7 F_68 ( void )
{
F_69 ( & V_120 ) ;
}
