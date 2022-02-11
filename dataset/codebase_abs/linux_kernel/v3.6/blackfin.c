void F_1 ( struct V_1 * V_2 , T_1 V_3 , const T_2 * V_4 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
void T_3 * V_6 = V_2 -> V_6 ;
void T_3 * V_7 = V_2 -> V_8 ;
T_2 V_9 = V_2 -> V_9 ;
F_2 ( ( T_2 * ) V_4 ) ;
F_3 ( V_7 , V_10 , V_3 ) ;
F_4 ( V_5 -> V_11 , L_1 ,
V_2 -> V_9 , V_6 , V_3 , V_4 , V_7 ) ;
F_5 ( V_4 , V_3 ) ;
if ( ! V_12 && V_9 != 0 ) {
T_1 V_13 ;
F_6 ( ( unsigned long ) V_4 ,
( unsigned long ) ( V_4 + V_3 ) ) ;
V_13 = ( V_14 ) V_4 ;
F_7 ( F_8 ( V_9 , V_15 ) , V_13 ) ;
F_9 () ;
V_13 = ( V_14 ) V_4 >> 16 ;
F_7 ( F_8 ( V_9 , V_16 ) , V_13 ) ;
F_9 () ;
F_7 ( F_8 ( V_9 , V_17 ) , V_3 ) ;
F_7 ( F_8 ( V_9 , V_18 ) , 0 ) ;
F_9 () ;
V_13 = ( V_9 << 4 ) | V_19 | V_20 | V_21 ;
F_7 ( F_8 ( V_9 , V_22 ) , V_13 ) ;
F_9 () ;
while ( ! ( F_10 () & ( 1 << V_9 ) ) )
F_11 () ;
F_12 ( 1 << V_9 ) ;
F_9 () ;
F_7 ( F_8 ( V_9 , V_22 ) , 0 ) ;
F_9 () ;
} else {
F_9 () ;
if ( F_13 ( ( unsigned long ) V_4 & 0x01 ) )
F_14 ( ( unsigned long ) V_6 , V_4 , ( V_3 + 1 ) >> 1 ) ;
else
F_15 ( ( unsigned long ) V_6 , V_4 , ( V_3 + 1 ) >> 1 ) ;
}
}
void F_16 ( struct V_1 * V_2 , T_1 V_3 , T_2 * V_23 )
{
struct V_5 * V_5 = V_2 -> V_5 ;
void T_3 * V_6 = V_2 -> V_6 ;
T_2 V_9 = V_2 -> V_9 ;
if ( V_24 && V_9 != 0 ) {
T_1 V_13 ;
F_17 ( ( unsigned long ) V_23 ,
( unsigned long ) ( V_23 + V_3 ) ) ;
V_13 = ( V_14 ) V_23 ;
F_7 ( F_8 ( V_9 , V_15 ) , V_13 ) ;
F_9 () ;
V_13 = ( V_14 ) V_23 >> 16 ;
F_7 ( F_8 ( V_9 , V_16 ) , V_13 ) ;
F_9 () ;
F_7 ( F_8 ( V_9 , V_17 ) , V_3 ) ;
F_7 ( F_8 ( V_9 , V_18 ) , 0 ) ;
F_9 () ;
V_13 = ( V_9 << 4 ) | V_19 | V_20 ;
F_7 ( F_8 ( V_9 , V_22 ) , V_13 ) ;
F_9 () ;
while ( ! ( F_10 () & ( 1 << V_9 ) ) )
F_11 () ;
F_12 ( 1 << V_9 ) ;
F_9 () ;
F_7 ( F_8 ( V_9 , V_22 ) , 0 ) ;
F_9 () ;
} else {
F_9 () ;
if ( V_3 == 1 )
* V_23 = ( T_2 ) F_18 ( ( unsigned long ) V_6 + 4 ) ;
else {
if ( F_13 ( ( unsigned long ) V_23 & 0x01 ) )
F_19 ( ( unsigned long ) V_6 , V_23 , V_3 >> 1 ) ;
else
F_20 ( ( unsigned long ) V_6 , V_23 , V_3 >> 1 ) ;
if ( V_3 & 0x01 )
* ( V_23 + V_3 - 1 ) = ( T_2 ) F_18 ( ( unsigned long ) V_6 + 4 ) ;
}
}
F_4 ( V_5 -> V_11 , L_2 ,
'R' , V_2 -> V_9 , V_6 , V_3 , V_23 ) ;
F_5 ( V_23 , V_3 ) ;
}
static T_4 F_21 ( int V_25 , void * V_26 )
{
unsigned long V_27 ;
T_4 V_28 = V_29 ;
struct V_5 * V_5 = V_26 ;
F_22 ( & V_5 -> V_30 , V_27 ) ;
V_5 -> V_31 = F_23 ( V_5 -> V_32 , V_33 ) ;
V_5 -> V_34 = F_24 ( V_5 -> V_32 , V_35 ) ;
V_5 -> V_36 = F_24 ( V_5 -> V_32 , V_37 ) ;
if ( V_5 -> V_31 || V_5 -> V_34 || V_5 -> V_36 ) {
F_25 ( V_5 -> V_32 , V_33 , V_5 -> V_31 ) ;
F_3 ( V_5 -> V_32 , V_35 , V_5 -> V_34 ) ;
F_3 ( V_5 -> V_32 , V_37 , V_5 -> V_36 ) ;
V_28 = F_26 ( V_5 ) ;
}
if ( ( F_27 ( V_5 ) && ( V_5 -> V_38 -> V_39 == V_40
|| V_5 -> V_38 -> V_39 == V_41 ) ) ||
( V_5 -> V_31 & V_42 && F_28 ( V_5 ) ) ) {
F_29 ( & V_43 , V_44 + V_45 ) ;
V_5 -> V_46 = V_45 ;
}
F_30 ( & V_5 -> V_30 , V_27 ) ;
return V_28 ;
}
static void F_31 ( unsigned long V_47 )
{
struct V_5 * V_5 = ( void * ) V_47 ;
unsigned long V_27 ;
T_1 V_48 ;
static T_2 V_49 ;
F_22 ( & V_5 -> V_30 , V_27 ) ;
switch ( V_5 -> V_38 -> V_39 ) {
case V_50 :
case V_41 :
V_48 = F_24 ( V_5 -> V_32 , V_51 ) ;
V_48 &= ~ V_52 ;
F_3 ( V_5 -> V_32 , V_51 , V_48 ) ;
V_48 |= V_52 ;
F_3 ( V_5 -> V_32 , V_51 , V_48 ) ;
V_48 = F_24 ( V_5 -> V_32 , V_51 ) ;
if ( ! ( V_48 & V_53 ) ) {
F_32 ( V_5 -> V_54 -> V_55 , 1 ) ;
V_5 -> V_38 -> V_39 = V_41 ;
} else {
F_32 ( V_5 -> V_54 -> V_55 , 0 ) ;
V_48 = F_23 ( V_5 -> V_32 , V_56 ) ;
V_48 &= ~ V_57 ;
F_25 ( V_5 -> V_32 , V_56 , V_48 ) ;
V_48 = V_58 | V_57 ;
F_25 ( V_5 -> V_32 , V_33 , V_48 ) ;
if ( F_27 ( V_5 ) )
V_5 -> V_38 -> V_39 = V_40 ;
else
F_25 ( V_5 -> V_32 , V_59 , V_60 ) ;
}
F_29 ( & V_43 , V_44 + V_45 ) ;
break;
case V_40 :
if ( ! F_33 ( V_5 ) )
break;
V_48 = F_24 ( V_5 -> V_32 , V_51 ) ;
V_48 |= V_52 ;
F_3 ( V_5 -> V_32 , V_51 , V_48 ) ;
V_48 = F_24 ( V_5 -> V_32 , V_51 ) ;
if ( ! ( V_48 & V_53 ) ) {
F_32 ( V_5 -> V_54 -> V_55 , 1 ) ;
V_5 -> V_38 -> V_39 = V_41 ;
} else {
F_32 ( V_5 -> V_54 -> V_55 , 0 ) ;
V_48 = F_23 ( V_5 -> V_32 , V_56 ) ;
V_48 &= ~ V_57 ;
F_25 ( V_5 -> V_32 , V_56 , V_48 ) ;
V_48 = V_58 | V_57 ;
F_25 ( V_5 -> V_32 , V_33 , V_48 ) ;
if ( V_49 ) {
V_48 = F_23 ( V_5 -> V_32 , V_59 ) ;
V_48 &= ~ V_61 ;
F_25 ( V_5 -> V_32 , V_59 , V_48 ) ;
V_49 = 0 ;
} else {
V_48 = F_23 ( V_5 -> V_32 , V_59 ) ;
V_48 |= V_61 ;
F_25 ( V_5 -> V_32 , V_59 , V_48 ) ;
V_49 = 1 ;
}
F_29 ( & V_43 , V_44 + V_45 / 4 ) ;
}
break;
default:
F_4 ( V_5 -> V_11 , L_3 ,
F_34 ( V_5 -> V_38 -> V_39 ) ) ;
break;
}
F_30 ( & V_5 -> V_30 , V_27 ) ;
F_4 ( V_5 -> V_11 , L_4 ,
F_34 ( V_5 -> V_38 -> V_39 ) ) ;
}
static void F_35 ( struct V_5 * V_5 )
{
if ( ! F_27 ( V_5 ) && F_36 ( V_5 ) ) {
F_29 ( & V_43 , V_44 + V_45 ) ;
V_5 -> V_46 = V_45 ;
}
}
static void F_37 ( struct V_5 * V_5 )
{
}
static void F_38 ( struct V_5 * V_5 , int V_62 )
{
int V_63 = V_5 -> V_54 -> V_64 ;
if ( ! V_62 )
V_63 = ! V_63 ;
F_32 ( V_5 -> V_54 -> V_55 , V_63 ) ;
F_4 ( V_5 -> V_11 , L_5
L_6 ,
F_34 ( V_5 -> V_38 -> V_39 ) ,
F_23 ( V_5 -> V_32 , V_51 ) ) ;
}
static int F_39 ( struct V_65 * V_66 , unsigned V_67 )
{
return 0 ;
}
static void F_40 ( struct V_5 * V_5 , unsigned long V_68 )
{
if ( ! F_27 ( V_5 ) && F_36 ( V_5 ) )
F_29 ( & V_43 , V_44 + V_45 ) ;
}
static int F_41 ( struct V_5 * V_5 )
{
return 0 ;
}
static int F_42 ( struct V_5 * V_5 , T_2 V_69 )
{
return - V_70 ;
}
static int F_43 ( struct V_71 * V_72 ,
T_1 V_73 , T_2 * V_74 ,
T_5 * V_75 , V_14 * V_3 )
{
struct V_76 * V_77 = V_72 -> V_78 ;
if ( V_79 ) {
if ( V_77 -> V_80 && * V_74 == 1 )
* V_3 = * V_3 - ( * V_3 % V_73 ) ;
}
return 0 ;
}
static void F_44 ( struct V_5 * V_5 )
{
if ( V_81 ) {
F_45 ( V_82 ) ;
F_9 () ;
}
if ( V_83 ) {
F_46 ( 0x0 ) ;
F_9 () ;
}
F_47 ( 0x3080 |
( ( 480 / V_5 -> V_54 -> V_84 ) << 1 ) ) ;
F_9 () ;
F_48 ( ( F_49 () / 1000 ) / 32 - 1 ) ;
F_9 () ;
F_50 ( 64 ) ;
F_9 () ;
F_51 ( 64 ) ;
F_9 () ;
F_52 ( 0x7 ) ;
F_9 () ;
F_53 ( V_85 | V_86 | V_87 |
V_88 | V_89 | V_90 |
V_91 | V_92 | V_93 |
V_94 | V_95 | V_96 |
V_97 | V_98 | V_99 ) ;
F_9 () ;
}
static int F_54 ( struct V_5 * V_5 )
{
if ( F_55 ( V_5 -> V_54 -> V_55 , L_7 ) ) {
F_56 ( V_100 L_8 ,
V_5 -> V_54 -> V_55 ) ;
return - V_101 ;
}
F_57 ( V_5 -> V_54 -> V_55 , 0 ) ;
F_58 () ;
V_5 -> V_38 = F_59 ( V_102 ) ;
if ( F_60 ( V_5 -> V_38 ) ) {
F_61 ( V_5 -> V_54 -> V_55 ) ;
return - V_101 ;
}
F_44 ( V_5 ) ;
if ( F_36 ( V_5 ) ) {
F_62 ( & V_43 ,
F_31 , ( unsigned long ) V_5 ) ;
}
if ( F_33 ( V_5 ) )
V_5 -> V_38 -> V_103 = F_39 ;
V_5 -> V_104 = F_21 ;
V_5 -> V_105 = true ;
return 0 ;
}
static int F_63 ( struct V_5 * V_5 )
{
F_61 ( V_5 -> V_54 -> V_55 ) ;
F_64 ( V_5 -> V_38 ) ;
F_65 () ;
return 0 ;
}
static int T_6 F_66 ( struct V_106 * V_107 )
{
struct V_108 * V_109 = V_107 -> V_110 . V_111 ;
struct V_106 * V_5 ;
struct V_112 * V_113 ;
int V_114 = - V_115 ;
V_113 = F_67 ( sizeof( * V_113 ) , V_116 ) ;
if ( ! V_113 ) {
F_68 ( & V_107 -> V_110 , L_9 ) ;
goto V_117;
}
V_5 = F_69 ( L_10 , - 1 ) ;
if ( ! V_5 ) {
F_68 ( & V_107 -> V_110 , L_11 ) ;
goto V_118;
}
V_5 -> V_110 . V_119 = & V_107 -> V_110 ;
V_5 -> V_110 . V_120 = & V_121 ;
V_5 -> V_110 . V_122 = V_121 ;
V_113 -> V_110 = & V_107 -> V_110 ;
V_113 -> V_5 = V_5 ;
V_109 -> V_123 = & V_124 ;
F_70 ( V_107 , V_113 ) ;
V_114 = F_71 ( V_5 , V_107 -> V_125 ,
V_107 -> V_126 ) ;
if ( V_114 ) {
F_68 ( & V_107 -> V_110 , L_12 ) ;
goto V_127;
}
V_114 = F_72 ( V_5 , V_109 , sizeof( * V_109 ) ) ;
if ( V_114 ) {
F_68 ( & V_107 -> V_110 , L_13 ) ;
goto V_127;
}
V_114 = F_73 ( V_5 ) ;
if ( V_114 ) {
F_68 ( & V_107 -> V_110 , L_14 ) ;
goto V_127;
}
return 0 ;
V_127:
F_74 ( V_5 ) ;
V_118:
F_75 ( V_113 ) ;
V_117:
return V_114 ;
}
static int T_7 F_76 ( struct V_106 * V_107 )
{
struct V_112 * V_113 = F_77 ( V_107 ) ;
F_78 ( V_113 -> V_5 ) ;
F_74 ( V_113 -> V_5 ) ;
F_75 ( V_113 ) ;
return 0 ;
}
static int F_79 ( struct V_128 * V_110 )
{
struct V_112 * V_113 = F_80 ( V_110 ) ;
struct V_5 * V_5 = F_81 ( V_113 ) ;
if ( F_28 ( V_5 ) )
F_32 ( V_5 -> V_54 -> V_55 , 0 ) ;
return 0 ;
}
static int F_82 ( struct V_128 * V_110 )
{
struct V_112 * V_113 = F_80 ( V_110 ) ;
struct V_5 * V_5 = F_81 ( V_113 ) ;
F_44 ( V_5 ) ;
return 0 ;
}
static int T_8 F_83 ( void )
{
return F_84 ( & V_129 ) ;
}
static void T_9 F_85 ( void )
{
F_86 ( & V_129 ) ;
}
