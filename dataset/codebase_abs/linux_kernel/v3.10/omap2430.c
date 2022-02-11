static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_2 = ( void * ) V_1 ;
unsigned long V_3 ;
T_1 V_4 ;
T_1 V_5 ;
F_2 ( & V_2 -> V_6 , V_3 ) ;
switch ( V_2 -> V_7 -> V_8 ) {
case V_9 :
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
if ( V_5 & V_12 ) {
V_2 -> V_7 -> V_8 = V_13 ;
F_4 ( V_2 ) ;
} else {
V_2 -> V_7 -> V_8 = V_14 ;
F_5 ( V_2 ) ;
}
break;
case V_15 :
if ( V_2 -> V_16 & V_17 ) {
V_4 = F_3 ( V_2 -> V_10 , V_18 ) ;
V_4 &= ~ V_19 ;
F_6 ( V_2 -> V_20 , L_1 , V_4 ) ;
F_7 ( V_2 -> V_10 , V_18 , V_4 ) ;
V_2 -> V_21 = 1 ;
V_2 -> V_16 &= ~ ( V_22
| V_17 ) ;
V_2 -> V_16 |= V_23 << 16 ;
F_8 ( F_9 ( V_2 ) ) ;
V_2 -> V_7 -> V_8 = V_24 ;
}
break;
case V_24 :
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
if ( V_5 & V_12 )
V_2 -> V_7 -> V_8 = V_13 ;
else
V_2 -> V_7 -> V_8 = V_9 ;
default:
break;
}
F_10 ( & V_2 -> V_6 , V_3 ) ;
}
static void F_11 ( struct V_2 * V_2 , unsigned long V_25 )
{
unsigned long V_26 = V_27 + F_12 ( 3 ) ;
static unsigned long V_28 ;
if ( V_25 == 0 )
V_25 = V_26 ;
if ( V_2 -> V_21 || ( ( V_2 -> V_29 == 0 )
&& ( V_2 -> V_7 -> V_8 == V_9 ) ) ) {
F_6 ( V_2 -> V_20 , L_2 ,
F_13 ( V_2 -> V_7 -> V_8 ) ) ;
F_14 ( & V_30 ) ;
V_28 = V_27 ;
return;
}
if ( F_15 ( V_28 , V_25 ) ) {
if ( ! F_16 ( & V_30 ) )
V_28 = V_25 ;
else {
F_6 ( V_2 -> V_20 , L_3 ) ;
return;
}
}
V_28 = V_25 ;
F_6 ( V_2 -> V_20 , L_4 ,
F_13 ( V_2 -> V_7 -> V_8 ) ,
( unsigned long ) F_17 ( V_25 - V_27 ) ) ;
F_18 ( & V_30 , V_25 ) ;
}
static void F_19 ( struct V_2 * V_2 , int V_31 )
{
struct V_32 * V_33 = V_2 -> V_7 -> V_33 ;
T_1 V_5 ;
unsigned long V_25 = V_27 + F_12 ( 1000 ) ;
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
if ( V_31 ) {
if ( V_2 -> V_7 -> V_8 == V_14 ) {
int V_34 = 100 ;
V_5 |= V_35 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
while ( F_3 ( V_2 -> V_10 , V_11 ) & 0x80 ) {
F_20 ( 5 ) ;
F_21 () ;
if ( F_15 ( V_27 , V_25 )
|| V_34 -- <= 0 ) {
F_22 ( V_2 -> V_20 ,
L_5 ) ;
break;
}
}
F_23 ( V_33 , 1 ) ;
} else {
V_2 -> V_21 = 1 ;
V_33 -> V_36 = 1 ;
V_2 -> V_7 -> V_8 = V_37 ;
V_5 |= V_35 ;
F_5 ( V_2 ) ;
}
} else {
V_2 -> V_21 = 0 ;
V_33 -> V_36 = 0 ;
V_2 -> V_7 -> V_8 = V_13 ;
V_5 &= ~ V_35 ;
F_4 ( V_2 ) ;
}
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
F_6 ( V_2 -> V_20 , L_6
L_7 ,
F_13 ( V_2 -> V_7 -> V_8 ) ,
F_3 ( V_2 -> V_10 , V_11 ) ) ;
}
static int F_24 ( struct V_2 * V_2 , T_1 V_38 )
{
T_1 V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
V_5 |= V_35 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
return 0 ;
}
static inline void F_25 ( struct V_2 * V_2 )
{
T_2 V_39 ;
V_39 = F_26 ( V_2 -> V_10 , V_40 ) ;
V_39 |= V_41 ;
F_27 ( V_2 -> V_10 , V_40 , V_39 ) ;
}
static inline void F_28 ( struct V_2 * V_2 )
{
T_2 V_39 ;
V_39 = F_26 ( V_2 -> V_10 , V_40 ) ;
V_39 &= ~ V_41 ;
F_27 ( V_2 -> V_10 , V_40 , V_39 ) ;
}
void F_29 ( enum V_42 V_43 )
{
struct V_44 * V_45 = V_46 ;
if ( ! V_45 ) {
F_30 ( L_8 , V_47 ) ;
return;
}
V_45 -> V_43 = V_43 ;
if ( ! F_31 ( V_45 ) ) {
F_30 ( L_9 , V_47 ) ;
return;
}
F_32 ( & V_45 -> V_48 ) ;
}
static void F_33 ( struct V_44 * V_45 )
{
struct V_2 * V_2 = F_31 ( V_45 ) ;
struct V_49 * V_50 = V_2 -> V_20 ;
struct V_51 * V_52 = V_50 -> V_53 ;
struct V_54 * V_55 = V_52 -> V_56 ;
struct V_32 * V_33 = V_2 -> V_7 -> V_33 ;
switch ( V_45 -> V_43 ) {
case V_57 :
F_6 ( V_50 , L_10 ) ;
V_33 -> V_36 = true ;
V_2 -> V_7 -> V_8 = V_14 ;
V_2 -> V_7 -> V_58 = V_59 ;
if ( V_2 -> V_60 ) {
F_34 ( V_50 ) ;
F_35 ( V_45 -> V_61 ,
V_62 ) ;
F_19 ( V_2 , 1 ) ;
}
break;
case V_63 :
F_6 ( V_50 , L_11 ) ;
V_33 -> V_36 = false ;
V_2 -> V_7 -> V_8 = V_13 ;
V_2 -> V_7 -> V_58 = V_64 ;
if ( V_2 -> V_60 )
F_34 ( V_50 ) ;
F_35 ( V_45 -> V_61 , V_65 ) ;
break;
case V_66 :
case V_67 :
F_6 ( V_50 , L_12 ) ;
V_2 -> V_7 -> V_58 = V_68 ;
if ( V_2 -> V_60 ) {
F_19 ( V_2 , 0 ) ;
F_36 ( V_50 ) ;
F_37 ( V_50 ) ;
}
if ( V_55 -> V_69 == V_70 )
F_23 ( V_2 -> V_7 -> V_33 , 0 ) ;
F_35 ( V_45 -> V_61 ,
V_71 ) ;
break;
default:
F_6 ( V_50 , L_13 ) ;
}
}
static void V_48 ( struct V_72 * V_73 )
{
struct V_44 * V_45 = F_38 ( V_73 ,
struct V_44 , V_48 ) ;
F_33 ( V_45 ) ;
}
static T_3 F_39 ( int V_74 , void * V_75 )
{
unsigned long V_3 ;
T_3 V_76 = V_77 ;
struct V_2 * V_2 = V_75 ;
F_2 ( & V_2 -> V_6 , V_3 ) ;
V_2 -> V_78 = F_3 ( V_2 -> V_10 , V_79 ) ;
V_2 -> V_80 = F_40 ( V_2 -> V_10 , V_81 ) ;
V_2 -> V_82 = F_40 ( V_2 -> V_10 , V_83 ) ;
if ( V_2 -> V_78 || V_2 -> V_80 || V_2 -> V_82 )
V_76 = F_41 ( V_2 ) ;
F_10 ( & V_2 -> V_6 , V_3 ) ;
return V_76 ;
}
static int F_42 ( struct V_2 * V_2 )
{
T_2 V_39 ;
int V_43 = 0 ;
struct V_49 * V_50 = V_2 -> V_20 ;
struct V_44 * V_45 = F_43 ( V_50 -> V_84 ) ;
struct V_51 * V_85 = V_50 -> V_53 ;
struct V_54 * V_55 = V_85 -> V_56 ;
if ( V_50 -> V_84 -> V_86 )
V_2 -> V_7 = F_44 ( V_50 -> V_84 ,
L_14 , 0 ) ;
else
V_2 -> V_7 = F_45 ( V_50 , 0 ) ;
if ( F_46 ( V_2 -> V_7 ) ) {
V_43 = F_47 ( V_2 -> V_7 ) ;
if ( V_43 == - V_87 )
return V_43 ;
F_30 ( L_15 ) ;
return - V_88 ;
}
V_2 -> V_89 = F_39 ;
V_43 = F_34 ( V_50 ) ;
if ( V_43 < 0 ) {
F_22 ( V_50 , L_16 , V_43 ) ;
goto V_90;
}
V_39 = F_26 ( V_2 -> V_10 , V_91 ) ;
if ( V_55 -> V_69 == V_70 ) {
V_39 &= ~ V_92 ;
V_39 |= V_93 ;
} else {
V_39 |= V_92 ;
}
F_27 ( V_2 -> V_10 , V_91 , V_39 ) ;
F_48 ( L_17
L_18 ,
F_26 ( V_2 -> V_10 , V_94 ) ,
F_26 ( V_2 -> V_10 , V_95 ) ,
F_26 ( V_2 -> V_10 , V_96 ) ,
F_26 ( V_2 -> V_10 , V_91 ) ,
F_26 ( V_2 -> V_10 , V_97 ) ) ;
F_49 ( & V_30 , F_1 , ( unsigned long ) V_2 ) ;
if ( V_45 -> V_43 != V_98 )
F_33 ( V_45 ) ;
F_50 ( V_2 -> V_7 ) ;
F_51 ( V_2 -> V_20 ) ;
return 0 ;
V_90:
return V_43 ;
}
static void F_52 ( struct V_2 * V_2 )
{
T_1 V_5 ;
unsigned long V_25 = V_27 + F_12 ( 1000 ) ;
struct V_49 * V_50 = V_2 -> V_20 ;
struct V_44 * V_45 = F_43 ( V_50 -> V_84 ) ;
struct V_51 * V_52 = V_50 -> V_53 ;
struct V_54 * V_55 = V_52 -> V_56 ;
switch ( V_45 -> V_43 ) {
case V_57 :
F_35 ( V_45 -> V_61 , V_62 ) ;
if ( V_55 -> V_69 != V_70 )
break;
V_5 = F_3 ( V_2 -> V_10 , V_11 ) ;
V_5 |= V_35 ;
F_7 ( V_2 -> V_10 , V_11 , V_5 ) ;
while ( F_3 ( V_2 -> V_10 , V_11 ) &
V_12 ) {
F_21 () ;
if ( F_15 ( V_27 , V_25 ) ) {
F_22 ( V_50 , L_5 ) ;
break;
}
}
break;
case V_63 :
F_35 ( V_45 -> V_61 , V_65 ) ;
break;
default:
break;
}
}
static void F_53 ( struct V_2 * V_2 )
{
struct V_49 * V_50 = V_2 -> V_20 ;
struct V_44 * V_45 = F_43 ( V_50 -> V_84 ) ;
if ( V_45 -> V_43 != V_98 )
F_35 ( V_45 -> V_61 ,
V_71 ) ;
}
static int F_54 ( struct V_2 * V_2 )
{
F_55 ( & V_30 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static int F_56 ( struct V_99 * V_100 )
{
struct V_51 * V_52 = V_100 -> V_50 . V_53 ;
struct V_54 * V_55 ;
struct V_99 * V_2 ;
struct V_44 * V_45 ;
struct V_101 * V_102 = V_100 -> V_50 . V_86 ;
struct V_103 * V_104 ;
int V_105 = - V_106 ;
V_45 = F_57 ( & V_100 -> V_50 , sizeof( * V_45 ) , V_107 ) ;
if ( ! V_45 ) {
F_22 ( & V_100 -> V_50 , L_19 ) ;
goto V_108;
}
V_2 = F_58 ( L_20 , V_109 ) ;
if ( ! V_2 ) {
F_22 ( & V_100 -> V_50 , L_21 ) ;
goto V_108;
}
V_2 -> V_50 . V_84 = & V_100 -> V_50 ;
V_2 -> V_50 . V_110 = & V_111 ;
V_2 -> V_50 . V_112 = V_111 ;
V_45 -> V_50 = & V_100 -> V_50 ;
V_45 -> V_2 = V_2 ;
V_45 -> V_43 = V_98 ;
if ( V_102 ) {
V_52 = F_57 ( & V_100 -> V_50 , sizeof( * V_52 ) , V_107 ) ;
if ( ! V_52 ) {
F_22 ( & V_100 -> V_50 ,
L_22 ) ;
goto V_113;
}
V_55 = F_57 ( & V_100 -> V_50 , sizeof( * V_55 ) , V_107 ) ;
if ( ! V_55 ) {
F_22 ( & V_100 -> V_50 ,
L_23 ) ;
goto V_113;
}
V_104 = F_57 ( & V_100 -> V_50 , sizeof( * V_104 ) , V_107 ) ;
if ( ! V_104 ) {
F_22 ( & V_100 -> V_50 ,
L_24 ) ;
goto V_113;
}
F_59 ( V_102 , L_25 , ( T_2 * ) & V_52 -> V_114 ) ;
F_59 ( V_102 , L_26 ,
( T_2 * ) & V_55 -> V_69 ) ;
F_59 ( V_102 , L_27 , ( T_2 * ) & V_104 -> V_115 ) ;
F_59 ( V_102 , L_28 , ( T_2 * ) & V_104 -> V_116 ) ;
F_59 ( V_102 , L_29 , ( T_2 * ) & V_52 -> V_4 ) ;
V_104 -> V_117 = F_60 ( V_102 , L_30 ) ;
V_52 -> V_118 = F_60 ( V_102 ,
L_31 ) ;
V_52 -> V_56 = V_55 ;
V_52 -> V_104 = V_104 ;
}
if ( V_52 -> V_118 ) {
V_45 -> V_61 = F_61 () ;
if ( F_46 ( V_45 -> V_61 ) ) {
F_62 ( & V_100 -> V_50 , L_32 ) ;
V_105 = F_47 ( V_45 -> V_61 ) ;
goto V_113;
}
} else {
V_45 -> V_61 = F_63 ( - V_119 ) ;
}
V_52 -> V_120 = & V_121 ;
F_64 ( V_100 , V_45 ) ;
V_46 = V_45 ;
F_65 ( & V_45 -> V_48 , V_48 ) ;
V_105 = F_66 ( V_2 , V_100 -> V_122 ,
V_100 -> V_123 ) ;
if ( V_105 ) {
F_22 ( & V_100 -> V_50 , L_33 ) ;
goto V_113;
}
V_105 = F_67 ( V_2 , V_52 , sizeof( * V_52 ) ) ;
if ( V_105 ) {
F_22 ( & V_100 -> V_50 , L_34 ) ;
goto V_113;
}
F_68 ( & V_100 -> V_50 ) ;
V_105 = F_69 ( V_2 ) ;
if ( V_105 ) {
F_22 ( & V_100 -> V_50 , L_35 ) ;
goto V_113;
}
return 0 ;
V_113:
F_70 ( V_2 ) ;
V_108:
return V_105 ;
}
static int F_71 ( struct V_99 * V_100 )
{
struct V_44 * V_45 = F_72 ( V_100 ) ;
F_73 ( & V_45 -> V_48 ) ;
F_74 ( V_45 -> V_2 ) ;
return 0 ;
}
static int F_75 ( struct V_49 * V_50 )
{
struct V_44 * V_45 = F_43 ( V_50 ) ;
struct V_2 * V_2 = F_31 ( V_45 ) ;
if ( V_2 ) {
V_2 -> V_124 . V_125 = F_26 ( V_2 -> V_10 ,
V_91 ) ;
F_25 ( V_2 ) ;
F_76 ( V_2 -> V_7 , 1 ) ;
}
return 0 ;
}
static int F_77 ( struct V_49 * V_50 )
{
struct V_44 * V_45 = F_43 ( V_50 ) ;
struct V_2 * V_2 = F_31 ( V_45 ) ;
if ( V_2 ) {
F_28 ( V_2 ) ;
F_27 ( V_2 -> V_10 , V_91 ,
V_2 -> V_124 . V_125 ) ;
F_76 ( V_2 -> V_7 , 0 ) ;
}
return 0 ;
}
static int T_4 F_78 ( void )
{
return F_79 ( & V_126 ) ;
}
static void T_5 F_80 ( void )
{
F_81 ( & V_126 ) ;
}
