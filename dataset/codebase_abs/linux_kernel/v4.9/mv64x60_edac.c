static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_4 -> V_7 + V_8 ) ;
if ( ! V_6 )
return;
F_3 ( V_9 L_1 , V_4 -> V_10 ) ;
F_3 ( V_9 L_2 , V_6 ) ;
F_3 ( V_9 L_3 ,
F_2 ( V_4 -> V_7 + V_11 ) ) ;
F_3 ( V_9 L_4 ,
F_2 ( V_4 -> V_7 + V_12 ) ) ;
F_3 ( V_9 L_5 ,
F_2 ( V_4 -> V_7 + V_13 ) ) ;
F_3 ( V_9 L_6 ,
F_2 ( V_4 -> V_7 + V_14 ) ) ;
F_4 ( V_4 -> V_7 + V_8 , ~ V_6 ) ;
if ( V_6 & V_15 )
F_5 ( V_2 , V_2 -> V_16 ) ;
if ( ! ( V_6 & V_15 ) )
F_6 ( V_2 , V_2 -> V_16 ) ;
}
static T_2 F_7 ( int V_17 , void * V_18 )
{
struct V_1 * V_2 = V_18 ;
struct V_3 * V_4 = V_2 -> V_5 ;
T_1 V_19 ;
V_19 = F_2 ( V_4 -> V_7 + V_8 ) ;
if ( ! V_19 )
return V_20 ;
F_1 ( V_2 ) ;
return V_21 ;
}
static int T_3 F_8 ( struct V_22 * V_23 )
{
struct V_24 * V_25 ;
void T_4 * V_26 ;
V_25 = F_9 ( V_23 , V_27 , 1 ) ;
if ( ! V_25 ) {
F_3 ( V_9 L_7
L_8 , V_28 ) ;
return - V_29 ;
}
V_26 = F_10 ( V_25 -> V_30 , F_11 ( V_25 ) ) ;
if ( ! V_26 )
return - V_31 ;
F_4 ( V_26 , F_2 ( V_26 ) & ~ 0x1 ) ;
F_12 ( V_26 ) ;
return 0 ;
}
static int F_13 ( struct V_22 * V_23 )
{
struct V_1 * V_2 ;
struct V_3 * V_4 ;
struct V_24 * V_25 ;
int V_32 = 0 ;
if ( ! F_14 ( & V_23 -> V_33 , F_13 , V_34 ) )
return - V_31 ;
V_2 = F_15 ( sizeof( * V_4 ) , L_9 ) ;
if ( ! V_2 )
return - V_31 ;
V_4 = V_2 -> V_5 ;
V_4 -> V_10 = V_23 -> V_35 ;
V_4 -> V_36 = L_10 ;
F_16 ( V_23 , V_2 ) ;
V_2 -> V_33 = & V_23 -> V_33 ;
V_2 -> V_37 = V_37 ( & V_23 -> V_33 ) ;
V_2 -> V_38 = V_39 ;
V_2 -> V_16 = V_4 -> V_36 ;
if ( V_40 == V_41 )
V_2 -> V_42 = F_1 ;
V_4 -> V_43 = V_44 ++ ;
V_25 = F_9 ( V_23 , V_27 , 0 ) ;
if ( ! V_25 ) {
F_3 ( V_9 L_7
L_8 , V_28 ) ;
V_32 = - V_29 ;
goto V_45;
}
if ( ! F_17 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ,
V_4 -> V_36 ) ) {
F_3 ( V_9 L_11 ,
V_28 ) ;
V_32 = - V_46 ;
goto V_45;
}
V_4 -> V_7 = F_18 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ) ;
if ( ! V_4 -> V_7 ) {
F_3 ( V_9 L_12 , V_28 ) ;
V_32 = - V_31 ;
goto V_45;
}
V_32 = F_8 ( V_23 ) ;
if ( V_32 < 0 ) {
F_3 ( V_9 L_13 , V_28 ) ;
goto V_45;
}
F_4 ( V_4 -> V_7 + V_8 , 0 ) ;
F_4 ( V_4 -> V_7 + V_47 , 0 ) ;
F_4 ( V_4 -> V_7 + V_47 ,
V_48 ) ;
if ( F_19 ( V_2 , V_4 -> V_43 ) > 0 ) {
F_20 ( 3 , L_14 ) ;
goto V_45;
}
if ( V_40 == V_49 ) {
V_4 -> V_17 = F_21 ( V_23 , 0 ) ;
V_32 = F_22 ( & V_23 -> V_33 ,
V_4 -> V_17 ,
F_7 ,
0 ,
L_15 ,
V_2 ) ;
if ( V_32 < 0 ) {
F_3 ( V_9 L_16
L_17 , V_28 , V_4 -> V_17 ) ;
V_32 = - V_50 ;
goto V_51;
}
F_3 (KERN_INFO EDAC_MOD_STR L_18 ,
pdata->irq) ;
}
F_23 ( & V_23 -> V_33 , F_13 ) ;
F_20 ( 3 , L_19 ) ;
return 0 ;
V_51:
F_24 ( & V_23 -> V_33 ) ;
V_45:
F_25 ( V_2 ) ;
F_26 ( & V_23 -> V_33 , F_13 ) ;
return V_32 ;
}
static int F_27 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_28 ( V_23 ) ;
F_20 ( 0 , L_20 ) ;
F_24 ( & V_23 -> V_33 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static void F_29 ( struct V_52 * V_53 )
{
struct V_54 * V_4 = V_53 -> V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_4 -> V_55 + V_56 ) ;
if ( ! V_6 )
return;
F_3 ( V_9 L_21 ) ;
F_3 ( V_9 L_2 , V_6 ) ;
F_3 ( V_9 L_3 ,
F_2 ( V_4 -> V_55 + V_57 ) ) ;
F_3 ( V_9 L_4 ,
F_2 ( V_4 -> V_55 + V_58 ) ) ;
F_3 ( V_9 L_22 ,
F_2 ( V_4 -> V_55 + V_59 ) ) ;
F_3 ( V_9 L_23 ,
F_2 ( V_4 -> V_55 + V_60 ) ) ;
F_3 ( V_9 L_24 ,
F_2 ( V_4 -> V_55 + V_61 ) ) ;
F_4 ( V_4 -> V_55 + V_56 , 0 ) ;
F_30 ( V_53 , 0 , 0 , V_53 -> V_16 ) ;
}
static T_2 F_31 ( int V_17 , void * V_18 )
{
struct V_52 * V_53 = V_18 ;
struct V_54 * V_4 = V_53 -> V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_4 -> V_55 + V_56 ) ;
if ( ! V_6 )
return V_20 ;
F_29 ( V_53 ) ;
return V_21 ;
}
static int F_32 ( struct V_22 * V_23 )
{
struct V_52 * V_53 ;
struct V_54 * V_4 ;
struct V_24 * V_25 ;
int V_32 = 0 ;
if ( ! F_14 ( & V_23 -> V_33 , F_32 , V_34 ) )
return - V_31 ;
V_53 = F_33 ( sizeof( * V_4 ) ,
L_25 , 1 , NULL , 0 , 0 , NULL , 0 ,
V_62 ) ;
if ( ! V_53 ) {
F_26 ( & V_23 -> V_33 , F_32 ) ;
return - V_31 ;
}
V_4 = V_53 -> V_5 ;
V_4 -> V_36 = L_26 ;
V_53 -> V_33 = & V_23 -> V_33 ;
F_16 ( V_23 , V_53 ) ;
V_53 -> V_37 = V_37 ( & V_23 -> V_33 ) ;
V_25 = F_9 ( V_23 , V_27 , 0 ) ;
if ( ! V_25 ) {
F_3 ( V_9 L_7
L_27 , V_28 ) ;
V_32 = - V_29 ;
goto V_45;
}
if ( ! F_17 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ,
V_4 -> V_36 ) ) {
F_3 ( V_9 L_28 ,
V_28 ) ;
V_32 = - V_46 ;
goto V_45;
}
V_4 -> V_55 = F_18 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ) ;
if ( ! V_4 -> V_55 ) {
F_3 ( V_9 L_29 ,
V_28 ) ;
V_32 = - V_31 ;
goto V_45;
}
F_4 ( V_4 -> V_55 + V_56 , 0 ) ;
V_53 -> V_38 = V_39 ;
V_53 -> V_16 = V_4 -> V_36 ;
if ( V_40 == V_41 )
V_53 -> V_42 = F_29 ;
V_4 -> V_43 = V_62 ++ ;
if ( F_34 ( V_53 ) > 0 ) {
F_20 ( 3 , L_30 ) ;
goto V_45;
}
if ( V_40 == V_49 ) {
V_4 -> V_17 = F_21 ( V_23 , 0 ) ;
V_32 = F_22 ( & V_23 -> V_33 ,
V_4 -> V_17 ,
F_31 ,
0 ,
L_31 ,
V_53 ) ;
if ( V_32 < 0 ) {
F_3 ( V_9
L_16
L_32 , V_28 , V_4 -> V_17 ) ;
V_32 = - V_50 ;
goto V_51;
}
F_3 (KERN_INFO EDAC_MOD_STR L_33 ,
pdata->irq) ;
}
F_23 ( & V_23 -> V_33 , F_32 ) ;
F_20 ( 3 , L_19 ) ;
return 0 ;
V_51:
F_35 ( & V_23 -> V_33 ) ;
V_45:
F_26 ( & V_23 -> V_33 , F_32 ) ;
F_36 ( V_53 ) ;
return V_32 ;
}
static int F_37 ( struct V_22 * V_23 )
{
struct V_52 * V_53 = F_28 ( V_23 ) ;
F_20 ( 0 , L_20 ) ;
F_35 ( & V_23 -> V_33 ) ;
F_36 ( V_53 ) ;
return 0 ;
}
static void F_38 ( struct V_52 * V_53 )
{
struct V_63 * V_4 = V_53 -> V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_4 -> V_64 [ 1 ] + V_65 ) &
V_66 ;
if ( ! V_6 )
return;
F_3 ( V_9 L_34 ) ;
F_3 ( V_9 L_2 , V_6 ) ;
F_3 ( V_9 L_3 ,
F_2 ( V_4 -> V_64 [ 0 ] + V_67 ) ) ;
F_3 ( V_9 L_4 ,
F_2 ( V_4 -> V_64 [ 0 ] + V_68 ) ) ;
F_3 ( V_9 L_22 ,
F_2 ( V_4 -> V_64 [ 1 ] + V_69 ) ) ;
F_3 ( V_9 L_23 ,
F_2 ( V_4 -> V_64 [ 1 ] + V_70 ) ) ;
F_3 ( V_9 L_24 ,
F_2 ( V_4 -> V_64 [ 1 ] + V_71 ) ) ;
F_4 ( V_4 -> V_64 [ 1 ] + V_65 , 0 ) ;
F_30 ( V_53 , 0 , 0 , V_53 -> V_16 ) ;
}
static T_2 F_39 ( int V_17 , void * V_18 )
{
struct V_52 * V_53 = V_18 ;
struct V_63 * V_4 = V_53 -> V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_4 -> V_64 [ 1 ] + V_65 ) &
V_66 ;
if ( ! V_6 )
return V_20 ;
F_38 ( V_53 ) ;
return V_21 ;
}
static int F_40 ( struct V_22 * V_23 )
{
struct V_52 * V_53 ;
struct V_24 * V_25 ;
struct V_63 * V_4 ;
int V_32 = 0 ;
if ( ! F_14 ( & V_23 -> V_33 , F_40 , V_34 ) )
return - V_31 ;
V_53 = F_33 ( sizeof( * V_4 ) ,
L_35 , 1 , NULL , 0 , 0 , NULL , 0 ,
V_62 ) ;
if ( ! V_53 ) {
F_26 ( & V_23 -> V_33 , F_40 ) ;
return - V_31 ;
}
V_4 = V_53 -> V_5 ;
V_4 -> V_36 = L_36 ;
V_53 -> V_33 = & V_23 -> V_33 ;
F_16 ( V_23 , V_53 ) ;
V_53 -> V_37 = V_37 ( & V_23 -> V_33 ) ;
V_25 = F_9 ( V_23 , V_27 , 0 ) ;
if ( ! V_25 ) {
F_3 ( V_9 L_7
L_37 , V_28 ) ;
V_32 = - V_29 ;
goto V_45;
}
if ( ! F_17 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ,
V_4 -> V_36 ) ) {
F_3 ( V_9 L_11 ,
V_28 ) ;
V_32 = - V_46 ;
goto V_45;
}
V_4 -> V_64 [ 0 ] = F_18 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ) ;
if ( ! V_4 -> V_64 [ 0 ] ) {
F_3 ( V_9 L_38 , V_28 ) ;
V_32 = - V_31 ;
goto V_45;
}
V_25 = F_9 ( V_23 , V_27 , 1 ) ;
if ( ! V_25 ) {
F_3 ( V_9 L_7
L_37 , V_28 ) ;
V_32 = - V_29 ;
goto V_45;
}
if ( ! F_17 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ,
V_4 -> V_36 ) ) {
F_3 ( V_9 L_11 ,
V_28 ) ;
V_32 = - V_46 ;
goto V_45;
}
V_4 -> V_64 [ 1 ] = F_18 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ) ;
if ( ! V_4 -> V_64 [ 1 ] ) {
F_3 ( V_9 L_38 , V_28 ) ;
V_32 = - V_31 ;
goto V_45;
}
F_4 ( V_4 -> V_64 [ 1 ] + V_65 , 0 ) ;
F_4 ( V_4 -> V_64 [ 1 ] + V_72 , 0 ) ;
F_4 ( V_4 -> V_64 [ 1 ] + V_72 , 0x000000ff ) ;
V_53 -> V_38 = V_39 ;
V_53 -> V_16 = V_4 -> V_36 ;
if ( V_40 == V_41 )
V_53 -> V_42 = F_38 ;
V_4 -> V_43 = V_62 ++ ;
if ( F_34 ( V_53 ) > 0 ) {
F_20 ( 3 , L_30 ) ;
goto V_45;
}
if ( V_40 == V_49 ) {
V_4 -> V_17 = F_21 ( V_23 , 0 ) ;
V_32 = F_22 ( & V_23 -> V_33 ,
V_4 -> V_17 ,
F_39 ,
0 ,
L_39 ,
V_53 ) ;
if ( V_32 < 0 ) {
F_3 ( V_9
L_40
L_41 , V_28 , V_4 -> V_17 ) ;
V_32 = - V_50 ;
goto V_51;
}
F_3 (KERN_INFO EDAC_MOD_STR
L_42 , pdata->irq) ;
}
F_23 ( & V_23 -> V_33 , F_40 ) ;
F_20 ( 3 , L_19 ) ;
return 0 ;
V_51:
F_35 ( & V_23 -> V_33 ) ;
V_45:
F_26 ( & V_23 -> V_33 , F_40 ) ;
F_36 ( V_53 ) ;
return V_32 ;
}
static int F_41 ( struct V_22 * V_23 )
{
struct V_52 * V_53 = F_28 ( V_23 ) ;
F_20 ( 0 , L_20 ) ;
F_35 ( & V_23 -> V_33 ) ;
F_36 ( V_53 ) ;
return 0 ;
}
static void F_42 ( struct V_73 * V_74 )
{
struct V_75 * V_4 = V_74 -> V_5 ;
T_1 V_76 ;
T_1 V_77 ;
T_1 V_78 ;
T_1 V_79 ;
T_1 V_80 ;
V_76 = F_2 ( V_4 -> V_81 + V_82 ) ;
if ( ! V_76 )
return;
V_77 = V_76 & ~ 0x3 ;
V_78 = F_2 ( V_4 -> V_81 + V_83 ) ;
V_79 = F_2 ( V_4 -> V_81 + V_84 ) ;
V_80 = V_78 ^ V_79 ;
if ( ! ( V_76 & 0x1 ) )
F_43 ( V_85 , V_74 , 1 ,
V_77 >> V_86 ,
V_77 & V_87 , V_80 ,
0 , 0 , - 1 ,
V_74 -> V_16 , L_43 ) ;
else
F_43 ( V_88 , V_74 , 1 ,
V_77 >> V_86 ,
V_77 & V_87 , 0 ,
0 , 0 , - 1 ,
V_74 -> V_16 , L_43 ) ;
F_4 ( V_4 -> V_81 + V_82 , 0 ) ;
}
static T_2 F_44 ( int V_17 , void * V_18 )
{
struct V_73 * V_74 = V_18 ;
struct V_75 * V_4 = V_74 -> V_5 ;
T_1 V_76 ;
V_76 = F_2 ( V_4 -> V_81 + V_82 ) ;
if ( ! V_76 )
return V_20 ;
F_42 ( V_74 ) ;
return V_21 ;
}
static void F_45 ( struct V_75 * V_4 )
{
struct V_89 * V_90 = NULL ;
const unsigned int * V_76 ;
V_90 = F_46 ( NULL , L_44 ) ;
if ( ! V_90 )
return;
V_76 = F_47 ( V_90 , L_45 , NULL ) ;
V_4 -> V_91 = V_76 [ 1 ] ;
}
static void F_48 ( struct V_73 * V_74 ,
struct V_75 * V_4 )
{
struct V_92 * V_93 ;
struct V_94 * V_95 ;
T_1 V_96 ;
T_1 V_97 ;
F_45 ( V_4 ) ;
V_97 = F_2 ( V_4 -> V_81 + V_98 ) ;
V_93 = V_74 -> V_99 [ 0 ] ;
V_95 = V_93 -> V_100 [ 0 ] -> V_95 ;
V_95 -> V_101 = V_4 -> V_91 >> V_86 ;
V_95 -> V_102 = 8 ;
V_95 -> V_103 = ( V_97 & V_104 ) ? V_105 : V_106 ;
V_96 = ( V_97 >> 20 ) & 0x3 ;
switch ( V_96 ) {
case 0x0 :
V_95 -> V_107 = V_108 ;
break;
case 0x2 :
V_95 -> V_107 = V_109 ;
break;
case 0x3 :
V_95 -> V_107 = V_110 ;
break;
default:
V_95 -> V_107 = V_111 ;
break;
}
V_95 -> V_112 = V_113 ;
}
static int F_49 ( struct V_22 * V_23 )
{
struct V_73 * V_74 ;
struct V_114 V_115 [ 2 ] ;
struct V_75 * V_4 ;
struct V_24 * V_25 ;
T_1 V_97 ;
int V_32 = 0 ;
if ( ! F_14 ( & V_23 -> V_33 , F_49 , V_34 ) )
return - V_31 ;
V_115 [ 0 ] . type = V_116 ;
V_115 [ 0 ] . V_117 = 1 ;
V_115 [ 0 ] . V_118 = true ;
V_115 [ 1 ] . type = V_119 ;
V_115 [ 1 ] . V_117 = 1 ;
V_115 [ 1 ] . V_118 = false ;
V_74 = F_50 ( V_120 , F_51 ( V_115 ) , V_115 ,
sizeof( struct V_75 ) ) ;
if ( ! V_74 ) {
F_3 ( V_9 L_46 , V_28 ) ;
F_26 ( & V_23 -> V_33 , F_49 ) ;
return - V_31 ;
}
V_4 = V_74 -> V_5 ;
V_74 -> V_23 = & V_23 -> V_33 ;
F_16 ( V_23 , V_74 ) ;
V_4 -> V_36 = L_47 ;
V_74 -> V_37 = V_37 ( & V_23 -> V_33 ) ;
V_4 -> V_43 = V_120 ++ ;
V_25 = F_9 ( V_23 , V_27 , 0 ) ;
if ( ! V_25 ) {
F_3 ( V_9 L_7
L_48 , V_28 ) ;
V_32 = - V_29 ;
goto V_45;
}
if ( ! F_17 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ,
V_4 -> V_36 ) ) {
F_3 ( V_9 L_11 ,
V_28 ) ;
V_32 = - V_46 ;
goto V_45;
}
V_4 -> V_81 = F_18 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ) ;
if ( ! V_4 -> V_81 ) {
F_3 ( V_9 L_49 , V_28 ) ;
V_32 = - V_31 ;
goto V_45;
}
V_97 = F_2 ( V_4 -> V_81 + V_98 ) ;
if ( ! ( V_97 & V_121 ) ) {
F_3 ( V_122 L_50 , V_28 ) ;
V_32 = - V_50 ;
goto V_51;
}
F_20 ( 3 , L_51 ) ;
V_74 -> V_123 = V_124 | V_125 ;
V_74 -> V_126 = V_127 | V_128 ;
V_74 -> V_129 = V_128 ;
V_74 -> V_38 = V_39 ;
V_74 -> V_130 = V_131 ;
V_74 -> V_16 = V_132 ;
if ( V_40 == V_41 )
V_74 -> V_42 = F_42 ;
V_74 -> V_133 = NULL ;
V_74 -> V_134 = V_135 ;
F_48 ( V_74 , V_4 ) ;
F_4 ( V_4 -> V_81 + V_82 , 0 ) ;
V_97 = F_2 ( V_4 -> V_81 + V_136 ) ;
V_97 = ( V_97 & 0xff00ffff ) | 0x10000 ;
F_4 ( V_4 -> V_81 + V_136 , V_97 ) ;
V_32 = F_52 ( V_74 ) ;
if ( V_32 ) {
F_20 ( 3 , L_52 ) ;
goto V_45;
}
if ( V_40 == V_49 ) {
V_4 -> V_17 = F_21 ( V_23 , 0 ) ;
V_32 = F_22 ( & V_23 -> V_33 ,
V_4 -> V_17 ,
F_44 ,
0 ,
L_53 ,
V_74 ) ;
if ( V_32 < 0 ) {
F_3 ( V_9 L_16
L_54 , V_28 , V_4 -> V_17 ) ;
V_32 = - V_50 ;
goto V_51;
}
F_3 (KERN_INFO EDAC_MOD_STR L_55 ,
pdata->irq) ;
}
F_20 ( 3 , L_19 ) ;
return 0 ;
V_51:
F_53 ( & V_23 -> V_33 ) ;
V_45:
F_26 ( & V_23 -> V_33 , F_49 ) ;
F_54 ( V_74 ) ;
return V_32 ;
}
static int F_55 ( struct V_22 * V_23 )
{
struct V_73 * V_74 = F_28 ( V_23 ) ;
F_20 ( 0 , L_20 ) ;
F_53 ( & V_23 -> V_33 ) ;
F_54 ( V_74 ) ;
return 0 ;
}
static int T_3 F_56 ( void )
{
int V_137 = 0 ;
F_3 ( V_138 L_56 V_131 L_20 ) ;
F_3 ( V_138 L_57 ) ;
switch ( V_40 ) {
case V_41 :
case V_49 :
break;
default:
V_40 = V_49 ;
break;
}
return F_57 ( V_139 , F_51 ( V_139 ) ) ;
}
static void T_5 F_58 ( void )
{
F_59 ( V_139 , F_51 ( V_139 ) ) ;
}
