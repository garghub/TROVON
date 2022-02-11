static void F_1 ( struct V_1 * V_1 )
{
void T_1 * V_2 = V_1 -> V_3 ;
T_2 V_4 ;
V_4 = ( ( V_1 -> V_4 & V_5 ) << V_6 ) |
( ( V_1 -> V_4 & V_7 ) << V_8 ) ;
F_2 ( V_2 , V_9 , V_4 ) ;
F_2 ( V_2 , V_10 , V_11 ) ;
F_2 ( V_2 , V_12 ,
V_13 << V_14 ) ;
}
static void F_3 ( struct V_1 * V_1 )
{
void T_1 * V_2 = V_1 -> V_3 ;
F_2 ( V_2 , V_15 , V_11 ) ;
F_2 ( V_2 , V_16 ,
V_17 | V_18 ) ;
F_4 ( V_1 -> V_19 , V_20 , 0 ) ;
F_2 ( V_2 , V_21 , 0 ) ;
}
static void F_5 ( struct V_1 * V_1 , int V_22 )
{
F_6 ( V_22 && F_7 ( V_1 ) ) ;
}
static void F_8 ( unsigned long V_23 )
{
struct V_1 * V_1 = ( void * ) V_23 ;
void T_1 * V_19 = V_1 -> V_19 ;
T_3 V_24 ;
unsigned long V_25 ;
V_24 = F_9 ( V_19 , V_20 ) ;
F_10 ( V_1 -> V_26 , L_1 , V_24 ,
F_11 ( V_1 -> V_27 -> V_28 ) ) ;
F_12 ( & V_1 -> V_29 , V_25 ) ;
switch ( V_1 -> V_27 -> V_28 ) {
case V_30 :
V_24 &= ~ V_31 ;
F_4 ( V_1 -> V_19 , V_20 , V_24 ) ;
V_24 = F_9 ( V_1 -> V_19 , V_20 ) ;
if ( V_24 & V_32 ) {
V_1 -> V_27 -> V_28 = V_33 ;
F_13 ( V_1 ) ;
} else {
V_1 -> V_27 -> V_28 = V_34 ;
F_14 ( V_1 ) ;
}
break;
case V_35 :
V_1 -> V_27 -> V_28 = V_36 ;
F_2 ( V_1 -> V_3 , V_12 ,
V_37 << V_14 ) ;
break;
case V_33 :
V_24 = F_9 ( V_19 , V_20 ) ;
if ( V_24 & V_32 )
F_15 ( & V_38 , V_39 + V_40 * V_41 ) ;
else
V_1 -> V_27 -> V_28 = V_34 ;
break;
default:
break;
}
F_16 ( & V_1 -> V_29 , V_25 ) ;
}
static void F_17 ( struct V_1 * V_1 , unsigned long V_42 )
{
static unsigned long V_43 ;
if ( V_42 == 0 )
V_42 = V_39 + F_18 ( 3 ) ;
if ( V_1 -> V_44 || ( V_1 -> V_45 == 0 &&
V_1 -> V_27 -> V_28 == V_30 ) ) {
F_10 ( V_1 -> V_26 , L_2 ,
F_11 ( V_1 -> V_27 -> V_28 ) ) ;
F_19 ( & V_38 ) ;
V_43 = V_39 ;
return;
}
if ( F_20 ( V_43 , V_42 ) && F_21 ( & V_38 ) ) {
F_10 ( V_1 -> V_26 , L_3 ) ;
return;
}
V_43 = V_42 ;
F_10 ( V_1 -> V_26 , L_4 ,
F_11 ( V_1 -> V_27 -> V_28 ) ,
F_22 ( V_42 - V_39 ) ) ;
F_15 ( & V_38 , V_42 ) ;
}
static T_4 F_23 ( int V_46 , void * V_47 )
{
struct V_1 * V_1 = V_47 ;
void T_1 * V_2 = V_1 -> V_3 ;
struct V_48 * V_49 = V_1 -> V_26 ;
struct V_50 * V_51 = F_24 ( V_49 ) ;
struct V_52 * V_53 = V_51 -> V_54 ;
struct V_55 * V_56 = V_1 -> V_27 -> V_56 ;
unsigned long V_25 ;
T_4 V_57 = V_58 ;
T_2 V_59 , V_60 ;
F_12 ( & V_1 -> V_29 , V_25 ) ;
V_59 = F_25 ( V_2 , V_61 ) ;
if ( V_59 ) {
F_2 ( V_2 , V_62 , V_59 ) ;
V_1 -> V_63 =
( V_59 & V_18 ) >> V_8 ;
V_1 -> V_64 =
( V_59 & V_17 ) >> V_6 ;
}
V_60 = F_25 ( V_2 , V_65 ) ;
if ( ! V_60 && ! V_59 )
goto V_66;
if ( V_60 ) {
F_2 ( V_2 , V_67 , V_60 ) ;
V_1 -> V_68 =
( V_60 & V_11 ) >> V_14 ;
}
if ( V_60 & ( V_13 << V_14 ) ) {
int V_69 = F_25 ( V_2 , V_70 ) ;
void T_1 * V_19 = V_1 -> V_19 ;
T_3 V_24 = F_9 ( V_19 , V_20 ) ;
int V_71 ;
V_71 = V_1 -> V_68 & V_37 ;
if ( V_71 ) {
V_1 -> V_68 &= ~ V_37 ;
V_1 -> V_27 -> V_28 = V_35 ;
F_15 ( & V_38 , V_39 + V_40 * V_41 ) ;
F_26 ( L_5 ) ;
} else if ( V_69 ) {
F_14 ( V_1 ) ;
V_56 -> V_72 = 1 ;
V_1 -> V_27 -> V_28 = V_36 ;
F_27 ( V_1 -> V_73 |= V_74 ) ;
F_19 ( & V_38 ) ;
} else {
V_1 -> V_44 = 0 ;
F_13 ( V_1 ) ;
V_56 -> V_72 = 0 ;
V_1 -> V_27 -> V_28 = V_33 ;
F_27 ( V_1 -> V_73 &= ~ V_74 ) ;
}
F_10 ( V_1 -> V_26 , L_6 ,
V_69 ? L_7 : L_8 ,
F_11 ( V_1 -> V_27 -> V_28 ) ,
V_71 ? L_9 : L_10 ,
V_24 ) ;
V_57 = V_75 ;
}
if ( V_1 -> V_68 & V_76 ) {
V_1 -> V_64 = 0 ;
V_1 -> V_63 = 0 ;
}
if ( V_1 -> V_64 || V_1 -> V_63 || V_1 -> V_68 )
V_57 |= F_28 ( V_1 ) ;
V_66:
if ( V_57 == V_75 || V_59 || V_60 ) {
if ( V_53 -> V_77 )
V_53 -> V_77 () ;
F_2 ( V_2 , V_21 , 0 ) ;
}
if ( V_1 -> V_27 -> V_28 == V_33 )
F_15 ( & V_38 , V_39 + V_40 * V_41 ) ;
F_16 ( & V_1 -> V_29 , V_25 ) ;
return V_57 ;
}
static int F_29 ( struct V_1 * V_1 , T_3 V_78 )
{
struct V_48 * V_49 = V_1 -> V_26 ;
struct V_50 * V_51 = F_24 ( V_49 ) ;
struct V_52 * V_53 = V_51 -> V_54 ;
int V_79 = 0 ;
if ( V_53 -> V_80 )
V_53 -> V_80 ( V_78 ) ;
else
V_79 = - V_81 ;
return V_79 ;
}
static int F_30 ( struct V_1 * V_1 )
{
struct V_48 * V_49 = V_1 -> V_26 ;
struct V_50 * V_51 = F_24 ( V_49 ) ;
struct V_52 * V_53 = V_51 -> V_54 ;
void T_1 * V_2 = V_1 -> V_3 ;
T_2 V_82 ;
V_1 -> V_19 += V_83 ;
V_82 = F_25 ( V_2 , V_84 ) ;
if ( ! V_82 )
return - V_85 ;
F_31 () ;
V_1 -> V_27 = F_32 ( V_86 ) ;
if ( F_33 ( V_1 -> V_27 ) )
return - V_87 ;
F_34 ( & V_38 , F_8 , ( unsigned long ) V_1 ) ;
if ( V_53 -> V_88 )
V_53 -> V_88 () ;
F_2 ( V_2 , V_89 , V_90 ) ;
if ( V_53 -> V_91 )
V_53 -> V_91 ( 1 ) ;
F_35 ( 5 ) ;
V_1 -> V_92 = F_23 ;
if ( V_53 -> V_77 )
V_53 -> V_77 () ;
return 0 ;
}
static int F_36 ( struct V_1 * V_1 )
{
struct V_48 * V_49 = V_1 -> V_26 ;
struct V_50 * V_51 = F_24 ( V_49 ) ;
struct V_52 * V_53 = V_51 -> V_54 ;
F_37 ( & V_38 ) ;
if ( V_53 -> V_91 )
V_53 -> V_91 ( 0 ) ;
F_38 ( V_1 -> V_27 ) ;
F_39 () ;
return 0 ;
}
void F_40 ( struct V_93 * V_94 , T_5 V_95 , T_3 * V_96 )
{
void T_1 * V_97 = V_94 -> V_97 ;
T_2 V_98 ;
int V_99 ;
if ( F_41 ( ( 0x03 & ( unsigned long ) V_96 ) == 0 ) && V_95 >= 4 ) {
F_42 ( V_97 , V_96 , V_95 >> 2 ) ;
V_96 += V_95 & ~ 0x03 ;
V_95 &= 0x03 ;
}
if ( V_95 > 4 ) {
for ( V_99 = 0 ; V_99 < ( V_95 >> 2 ) ; V_99 ++ ) {
* ( T_2 * ) V_96 = F_25 ( V_97 , 0 ) ;
V_96 += 4 ;
}
V_95 &= 0x03 ;
}
if ( V_95 > 0 ) {
V_98 = F_25 ( V_97 , 0 ) ;
memcpy ( V_96 , & V_98 , V_95 ) ;
}
}
static int F_43 ( struct V_100 * V_101 )
{
struct V_50 * V_102 = F_24 ( & V_101 -> V_49 ) ;
struct V_100 * V_1 ;
struct V_103 * V_104 ;
struct V_105 V_106 ;
struct V_107 * V_108 ;
struct V_107 * V_107 ;
int V_57 = - V_109 ;
V_104 = F_44 ( sizeof( * V_104 ) , V_110 ) ;
if ( ! V_104 ) {
F_45 ( & V_101 -> V_49 , L_11 ) ;
goto V_111;
}
V_108 = F_46 ( & V_101 -> V_49 , L_12 ) ;
if ( F_47 ( V_108 ) ) {
F_45 ( & V_101 -> V_49 , L_13 ) ;
V_57 = F_48 ( V_108 ) ;
goto V_112;
}
V_107 = F_46 ( & V_101 -> V_49 , L_14 ) ;
if ( F_47 ( V_107 ) ) {
F_45 ( & V_101 -> V_49 , L_15 ) ;
V_57 = F_48 ( V_107 ) ;
goto V_113;
}
V_57 = F_49 ( V_108 ) ;
if ( V_57 ) {
F_45 ( & V_101 -> V_49 , L_16 ) ;
goto V_114;
}
V_57 = F_49 ( V_107 ) ;
if ( V_57 ) {
F_45 ( & V_101 -> V_49 , L_17 ) ;
goto V_115;
}
V_104 -> V_49 = & V_101 -> V_49 ;
V_104 -> V_108 = V_108 ;
V_104 -> V_107 = V_107 ;
V_102 -> V_116 = & V_117 ;
F_50 ( V_101 , V_104 ) ;
V_106 = V_118 ;
V_106 . V_119 = & V_101 -> V_49 ;
V_106 . V_120 = V_101 -> V_121 ;
V_106 . V_122 = V_101 -> V_123 ;
V_106 . V_53 = V_102 ;
V_106 . V_124 = sizeof( * V_102 ) ;
V_104 -> V_1 = V_1 = F_51 ( & V_106 ) ;
if ( F_47 ( V_1 ) ) {
V_57 = F_48 ( V_1 ) ;
F_45 ( & V_101 -> V_49 , L_18 , V_57 ) ;
goto V_125;
}
return 0 ;
V_125:
F_52 ( V_107 ) ;
V_115:
F_52 ( V_108 ) ;
V_114:
F_53 ( V_107 ) ;
V_113:
F_53 ( V_108 ) ;
V_112:
F_54 ( V_104 ) ;
V_111:
return V_57 ;
}
static int F_55 ( struct V_100 * V_101 )
{
struct V_103 * V_104 = F_56 ( V_101 ) ;
F_57 ( V_104 -> V_1 ) ;
F_52 ( V_104 -> V_107 ) ;
F_52 ( V_104 -> V_108 ) ;
F_53 ( V_104 -> V_107 ) ;
F_53 ( V_104 -> V_108 ) ;
F_54 ( V_104 ) ;
return 0 ;
}
static int F_58 ( struct V_48 * V_49 )
{
struct V_103 * V_104 = F_59 ( V_49 ) ;
struct V_50 * V_51 = F_24 ( V_49 ) ;
struct V_52 * V_53 = V_51 -> V_54 ;
if ( V_53 -> V_91 )
V_53 -> V_91 ( 0 ) ;
F_52 ( V_104 -> V_108 ) ;
F_52 ( V_104 -> V_107 ) ;
return 0 ;
}
static int F_60 ( struct V_48 * V_49 )
{
struct V_103 * V_104 = F_59 ( V_49 ) ;
struct V_50 * V_51 = F_24 ( V_49 ) ;
struct V_52 * V_53 = V_51 -> V_54 ;
int V_57 ;
if ( V_53 -> V_91 )
V_53 -> V_91 ( 1 ) ;
V_57 = F_49 ( V_104 -> V_108 ) ;
if ( V_57 ) {
F_45 ( V_49 , L_16 ) ;
return V_57 ;
}
V_57 = F_49 ( V_104 -> V_107 ) ;
if ( V_57 ) {
F_45 ( V_49 , L_17 ) ;
return V_57 ;
}
return 0 ;
}
