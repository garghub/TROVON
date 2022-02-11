static void F_1 ( struct V_1 * V_1 )
{
void T_1 * V_2 = V_1 -> V_3 ;
T_2 V_4 ;
V_4 = ( ( V_1 -> V_5 & V_6 ) << V_7 ) |
( ( V_1 -> V_5 & V_8 ) << V_9 ) |
V_10 ;
F_2 ( V_2 , V_11 , V_4 ) ;
F_2 ( V_2 , V_12 ,
V_13 << V_14 ) ;
}
static void F_3 ( struct V_1 * V_1 )
{
void T_1 * V_2 = V_1 -> V_3 ;
F_2 ( V_2 , V_15 ,
V_10 |
V_16 | V_17 ) ;
F_2 ( V_2 , V_18 , 0 ) ;
}
static void F_4 ( struct V_1 * V_1 , int V_19 )
{
F_5 ( V_19 && F_6 ( V_1 ) ) ;
}
static void F_7 ( unsigned long V_20 )
{
struct V_1 * V_1 = ( void * ) V_20 ;
void T_1 * V_21 = V_1 -> V_21 ;
T_3 V_22 ;
unsigned long V_23 ;
V_22 = F_8 ( V_21 , V_24 ) ;
F_9 ( V_1 -> V_25 , L_1 , V_22 ,
F_10 ( V_1 -> V_26 -> V_27 -> V_28 ) ) ;
F_11 ( & V_1 -> V_29 , V_23 ) ;
switch ( V_1 -> V_26 -> V_27 -> V_28 ) {
case V_30 :
V_22 &= ~ V_31 ;
F_12 ( V_1 -> V_21 , V_24 , V_22 ) ;
V_22 = F_8 ( V_1 -> V_21 , V_24 ) ;
if ( V_22 & V_32 ) {
V_1 -> V_26 -> V_27 -> V_28 = V_33 ;
F_13 ( V_1 ) ;
} else {
V_1 -> V_26 -> V_27 -> V_28 = V_34 ;
F_14 ( V_1 ) ;
}
break;
case V_35 :
if ( V_22 & V_36 ) {
F_15 ( & V_37 , V_38 + V_39 * V_40 ) ;
break;
}
V_1 -> V_26 -> V_27 -> V_28 = V_41 ;
F_2 ( V_1 -> V_3 , V_12 ,
V_42 << V_14 ) ;
break;
case V_33 :
F_12 ( V_21 , V_24 , V_22 | V_31 ) ;
V_22 = F_8 ( V_21 , V_24 ) ;
if ( V_22 & V_32 )
F_15 ( & V_37 , V_38 + V_39 * V_40 ) ;
else
V_1 -> V_26 -> V_27 -> V_28 = V_34 ;
break;
default:
break;
}
F_16 ( & V_1 -> V_29 , V_23 ) ;
}
static void F_17 ( struct V_1 * V_1 , unsigned long V_43 )
{
static unsigned long V_44 ;
if ( V_43 == 0 )
V_43 = V_38 + F_18 ( 3 ) ;
if ( V_1 -> V_45 || ( V_1 -> V_46 == 0 &&
V_1 -> V_26 -> V_27 -> V_28 == V_30 ) ) {
F_9 ( V_1 -> V_25 , L_2 ,
F_10 ( V_1 -> V_26 -> V_27 -> V_28 ) ) ;
F_19 ( & V_37 ) ;
V_44 = V_38 ;
return;
}
if ( F_20 ( V_44 , V_43 ) && F_21 ( & V_37 ) ) {
F_9 ( V_1 -> V_25 , L_3 ) ;
return;
}
V_44 = V_43 ;
F_9 ( V_1 -> V_25 , L_4 ,
F_10 ( V_1 -> V_26 -> V_27 -> V_28 ) ,
F_22 ( V_43 - V_38 ) ) ;
F_15 ( & V_37 , V_43 ) ;
}
static T_4 F_23 ( int V_47 , void * V_48 )
{
struct V_1 * V_1 = V_48 ;
void T_1 * V_2 = V_1 -> V_3 ;
struct V_49 * V_27 = V_1 -> V_26 -> V_27 ;
unsigned long V_23 ;
T_4 V_50 = V_51 ;
T_2 V_52 ;
F_11 ( & V_1 -> V_29 , V_23 ) ;
V_52 = F_24 ( V_2 , V_53 ) ;
if ( ! V_52 )
goto V_54;
F_2 ( V_2 , V_55 , V_52 ) ;
F_9 ( V_1 -> V_25 , L_5 , V_52 ) ;
V_1 -> V_56 = ( V_52 & V_17 ) >> V_9 ;
V_1 -> V_57 = ( V_52 & V_16 ) >> V_7 ;
V_1 -> V_58 = ( V_52 & V_10 ) >> V_14 ;
if ( V_52 & ( V_13 << V_14 ) ) {
int V_59 = F_24 ( V_2 , V_60 ) ;
void T_1 * V_21 = V_1 -> V_21 ;
T_3 V_22 = F_8 ( V_21 , V_24 ) ;
int V_61 ;
V_61 = V_1 -> V_58 & V_42 ;
if ( V_61 ) {
V_1 -> V_58 &= ~ V_42 ;
V_1 -> V_26 -> V_27 -> V_28 = V_35 ;
F_15 ( & V_37 , V_38 + V_39 * V_40 ) ;
F_25 ( L_6 ) ;
} else if ( V_59 ) {
F_14 ( V_1 ) ;
V_27 -> V_62 = 1 ;
V_1 -> V_26 -> V_27 -> V_28 = V_41 ;
F_26 ( V_1 -> V_63 |= V_64 ) ;
F_19 ( & V_37 ) ;
} else {
V_1 -> V_45 = 0 ;
F_13 ( V_1 ) ;
V_27 -> V_62 = 0 ;
V_1 -> V_26 -> V_27 -> V_28 = V_33 ;
F_26 ( V_1 -> V_63 &= ~ V_64 ) ;
}
F_9 ( V_1 -> V_25 , L_7 ,
V_59 ? L_8 : L_9 ,
F_10 ( V_1 -> V_26 -> V_27 -> V_28 ) ,
V_61 ? L_10 : L_11 ,
V_22 ) ;
V_50 = V_65 ;
}
if ( V_1 -> V_57 || V_1 -> V_56 || V_1 -> V_58 )
V_50 |= F_27 ( V_1 ) ;
V_54:
if ( V_50 == V_65 || V_52 )
F_2 ( V_2 , V_18 , 0 ) ;
if ( V_1 -> V_26 -> V_27 -> V_28 == V_33 )
F_15 ( & V_37 , V_38 + V_39 * V_40 ) ;
F_16 ( & V_1 -> V_29 , V_23 ) ;
return V_50 ;
}
static int F_28 ( struct V_1 * V_1 , T_3 V_66 )
{
struct V_67 * V_68 = F_29 ( V_1 -> V_25 -> V_69 ) ;
enum V_70 V_70 ;
if ( ! V_1 -> V_71 )
return F_30 ( V_68 -> V_72 , V_73 ) ;
switch ( V_66 ) {
case V_74 :
V_70 = V_75 ;
break;
case V_76 :
V_70 = V_77 ;
break;
case V_78 :
V_70 = V_73 ;
break;
default:
return - V_79 ;
}
return F_30 ( V_68 -> V_72 , V_70 ) ;
}
static int F_31 ( struct V_1 * V_1 )
{
struct V_67 * V_68 = F_29 ( V_1 -> V_25 -> V_69 ) ;
void T_1 * V_2 = V_1 -> V_3 ;
T_2 V_80 ;
int V_50 = - V_81 ;
V_1 -> V_21 += V_82 ;
V_50 = F_32 ( V_68 -> V_83 ) ;
if ( V_50 ) {
F_33 ( V_68 -> V_84 , L_12 ) ;
return V_50 ;
}
V_80 = F_24 ( V_2 , V_85 ) ;
if ( ! V_80 )
goto V_86;
V_1 -> V_26 = F_34 ( V_87 ) ;
if ( F_35 ( V_1 -> V_26 ) ) {
V_50 = - V_88 ;
goto V_86;
}
F_36 ( & V_37 , F_7 , ( unsigned long ) V_1 ) ;
F_2 ( V_2 , V_89 , V_90 ) ;
V_50 = F_37 ( V_68 -> V_72 ) ;
if ( V_50 ) {
F_33 ( V_68 -> V_84 , L_13 ) ;
goto V_86;
}
V_50 = F_38 ( V_68 -> V_72 ) ;
if ( V_50 ) {
F_33 ( V_68 -> V_84 , L_14 ) ;
goto V_91;
}
F_39 ( 5 ) ;
F_40 ( L_15 , V_80 ,
F_8 ( V_2 , V_89 ) ) ;
V_1 -> V_92 = F_23 ;
return 0 ;
V_91:
F_41 ( V_68 -> V_72 ) ;
V_86:
F_42 ( V_68 -> V_83 ) ;
return V_50 ;
}
static int F_43 ( struct V_1 * V_1 )
{
struct V_67 * V_68 = F_29 ( V_1 -> V_25 -> V_69 ) ;
F_44 ( & V_37 ) ;
F_45 ( V_68 -> V_72 ) ;
F_41 ( V_68 -> V_72 ) ;
F_42 ( V_68 -> V_83 ) ;
F_46 ( V_1 -> V_26 ) ;
return 0 ;
}
static inline T_3 F_47 ( struct V_93 * V_84 )
{
struct V_94 * V_95 ;
int V_96 ;
V_95 = F_48 ( V_84 , L_16 ) ;
if ( F_49 ( V_95 ) )
return 255 ;
V_96 = F_50 ( V_95 ) ;
F_51 ( V_95 ) ;
if ( V_96 <= 0 || V_96 > 510000 )
return 255 ;
return V_96 / 1000 / 2 ;
}
static void F_52 ( struct V_97 * V_98 )
{
struct V_1 * V_1 = V_98 -> V_1 ;
void T_1 * V_2 = V_1 -> V_3 ;
F_2 ( V_2 , V_18 , 0 ) ;
}
static struct V_97 *
F_53 ( struct V_1 * V_1 , void T_1 * V_99 )
{
struct V_97 * V_25 ;
V_25 = F_54 ( V_1 , V_99 ) ;
if ( F_35 ( V_25 ) )
return V_25 ;
V_25 -> V_100 = F_52 ;
return V_25 ;
}
static int F_55 ( struct V_101 * V_102 )
{
struct V_103 V_104 [ 2 ] ;
struct V_105 * V_106 = F_56 ( & V_102 -> V_84 ) ;
struct V_67 * V_68 ;
struct V_107 V_108 ;
struct V_83 * V_83 ;
struct V_109 * V_110 = V_102 -> V_84 . V_111 ;
int V_50 ;
V_68 = F_57 ( & V_102 -> V_84 , sizeof( * V_68 ) , V_112 ) ;
if ( ! V_68 )
return - V_113 ;
V_83 = F_58 ( & V_102 -> V_84 , L_17 ) ;
if ( F_49 ( V_83 ) ) {
F_33 ( & V_102 -> V_84 , L_18 ) ;
return F_59 ( V_83 ) ;
}
V_68 -> V_72 = F_60 ( & V_102 -> V_84 , L_19 ) ;
if ( F_49 ( V_68 -> V_72 ) ) {
if ( F_59 ( V_68 -> V_72 ) != - V_88 )
F_33 ( & V_102 -> V_84 , L_20 ) ;
return F_59 ( V_68 -> V_72 ) ;
}
V_68 -> V_84 = & V_102 -> V_84 ;
V_68 -> V_83 = V_83 ;
if ( F_61 ( V_114 ) && V_110 ) {
V_106 = F_57 ( & V_102 -> V_84 , sizeof( * V_106 ) , V_112 ) ;
if ( ! V_106 )
return - V_113 ;
V_106 -> V_115 = & V_116 ;
V_106 -> V_117 = F_62 ( & V_102 -> V_84 ) ;
V_106 -> V_118 = F_47 ( & V_102 -> V_84 ) ;
}
V_106 -> V_119 = & V_120 ;
V_68 -> V_121 = F_63 () ;
V_50 = F_64 ( V_68 -> V_121 ) ;
if ( V_50 ) {
F_33 ( & V_102 -> V_84 , L_21 ) ;
return V_50 ;
}
F_65 ( V_102 , V_68 ) ;
V_50 = F_66 ( V_102 -> V_84 . V_111 , NULL ,
V_122 , & V_102 -> V_84 ) ;
if ( V_50 )
return V_50 ;
memset ( V_104 , 0x00 , sizeof( * V_104 ) *
F_67 ( V_104 ) ) ;
V_104 [ 0 ] . V_123 = V_102 -> V_103 [ 0 ] . V_123 ;
V_104 [ 0 ] . V_124 = V_102 -> V_103 [ 0 ] . V_124 ;
V_104 [ 0 ] . V_125 = V_102 -> V_103 [ 0 ] . V_125 ;
V_104 [ 0 ] . V_23 = V_102 -> V_103 [ 0 ] . V_23 ;
V_104 [ 1 ] . V_123 = V_102 -> V_103 [ 1 ] . V_123 ;
V_104 [ 1 ] . V_124 = V_102 -> V_103 [ 1 ] . V_124 ;
V_104 [ 1 ] . V_125 = V_102 -> V_103 [ 1 ] . V_125 ;
V_104 [ 1 ] . V_23 = V_102 -> V_103 [ 1 ] . V_23 ;
V_108 = V_126 ;
V_108 . V_69 = & V_102 -> V_84 ;
V_108 . V_127 = V_104 ;
V_108 . V_128 = F_67 ( V_104 ) ;
V_108 . V_129 = V_106 ;
V_108 . V_130 = sizeof( * V_106 ) ;
V_68 -> V_1 = F_68 ( & V_108 ) ;
V_50 = F_64 ( V_68 -> V_1 ) ;
if ( V_50 ) {
F_33 ( & V_102 -> V_84 , L_22 , V_50 ) ;
F_69 ( V_68 -> V_121 ) ;
}
return V_50 ;
}
static int F_70 ( struct V_101 * V_102 )
{
struct V_67 * V_68 = F_71 ( V_102 ) ;
F_72 ( V_68 -> V_1 ) ;
F_69 ( V_68 -> V_121 ) ;
return 0 ;
}
static int F_73 ( struct V_93 * V_84 )
{
int V_50 ;
struct V_67 * V_68 = F_29 ( V_84 ) ;
V_50 = F_45 ( V_68 -> V_72 ) ;
if ( V_50 )
return V_50 ;
F_42 ( V_68 -> V_83 ) ;
return 0 ;
}
static int F_74 ( struct V_93 * V_84 )
{
int V_50 ;
struct V_67 * V_68 = F_29 ( V_84 ) ;
V_50 = F_32 ( V_68 -> V_83 ) ;
if ( V_50 )
return V_50 ;
return F_38 ( V_68 -> V_72 ) ;
}
