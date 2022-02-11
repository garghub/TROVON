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
static int T_5 F_13 ( struct V_22 * V_23 )
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
V_4 -> V_17 = V_37 ;
F_16 ( V_23 , V_2 ) ;
V_2 -> V_33 = & V_23 -> V_33 ;
V_2 -> V_38 = V_38 ( & V_23 -> V_33 ) ;
V_2 -> V_39 = V_40 ;
V_2 -> V_16 = V_4 -> V_36 ;
if ( V_41 == V_42 )
V_2 -> V_43 = F_1 ;
V_4 -> V_44 = V_45 ++ ;
V_25 = F_9 ( V_23 , V_27 , 0 ) ;
if ( ! V_25 ) {
F_3 ( V_9 L_7
L_8 , V_28 ) ;
V_32 = - V_29 ;
goto V_46;
}
if ( ! F_17 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ,
V_4 -> V_36 ) ) {
F_3 ( V_9 L_11 ,
V_28 ) ;
V_32 = - V_47 ;
goto V_46;
}
V_4 -> V_7 = F_18 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ) ;
if ( ! V_4 -> V_7 ) {
F_3 ( V_9 L_12 , V_28 ) ;
V_32 = - V_31 ;
goto V_46;
}
V_32 = F_8 ( V_23 ) ;
if ( V_32 < 0 ) {
F_3 ( V_9 L_13 , V_28 ) ;
goto V_46;
}
F_4 ( V_4 -> V_7 + V_8 , 0 ) ;
F_4 ( V_4 -> V_7 + V_48 , 0 ) ;
F_4 ( V_4 -> V_7 + V_48 ,
V_49 ) ;
if ( F_19 ( V_2 , V_4 -> V_44 ) > 0 ) {
F_20 ( L_14 , V_28 ) ;
goto V_46;
}
if ( V_41 == V_50 ) {
V_4 -> V_17 = F_21 ( V_23 , 0 ) ;
V_32 = F_22 ( & V_23 -> V_33 ,
V_4 -> V_17 ,
F_7 ,
V_51 ,
L_15 ,
V_2 ) ;
if ( V_32 < 0 ) {
F_3 ( V_9 L_16
L_17 , V_28 , V_4 -> V_17 ) ;
V_32 = - V_52 ;
goto V_53;
}
F_3 (KERN_INFO EDAC_MOD_STR L_18 ,
pdata->irq) ;
}
F_23 ( & V_23 -> V_33 , F_13 ) ;
F_20 ( L_19 , V_28 ) ;
return 0 ;
V_53:
F_24 ( & V_23 -> V_33 ) ;
V_46:
F_25 ( V_2 ) ;
F_26 ( & V_23 -> V_33 , F_13 ) ;
return V_32 ;
}
static int F_27 ( struct V_22 * V_23 )
{
struct V_1 * V_2 = F_28 ( V_23 ) ;
F_29 ( L_20 , V_28 ) ;
F_24 ( & V_23 -> V_33 ) ;
F_25 ( V_2 ) ;
return 0 ;
}
static void F_30 ( struct V_54 * V_55 )
{
struct V_56 * V_4 = V_55 -> V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_4 -> V_57 + V_58 ) ;
if ( ! V_6 )
return;
F_3 ( V_9 L_21 ) ;
F_3 ( V_9 L_2 , V_6 ) ;
F_3 ( V_9 L_3 ,
F_2 ( V_4 -> V_57 + V_59 ) ) ;
F_3 ( V_9 L_4 ,
F_2 ( V_4 -> V_57 + V_60 ) ) ;
F_3 ( V_9 L_22 ,
F_2 ( V_4 -> V_57 + V_61 ) ) ;
F_3 ( V_9 L_23 ,
F_2 ( V_4 -> V_57 + V_62 ) ) ;
F_3 ( V_9 L_24 ,
F_2 ( V_4 -> V_57 + V_63 ) ) ;
F_4 ( V_4 -> V_57 + V_58 , 0 ) ;
F_31 ( V_55 , 0 , 0 , V_55 -> V_16 ) ;
}
static T_2 F_32 ( int V_17 , void * V_18 )
{
struct V_54 * V_55 = V_18 ;
struct V_56 * V_4 = V_55 -> V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_4 -> V_57 + V_58 ) ;
if ( ! V_6 )
return V_20 ;
F_30 ( V_55 ) ;
return V_21 ;
}
static int T_5 F_33 ( struct V_22 * V_23 )
{
struct V_54 * V_55 ;
struct V_56 * V_4 ;
struct V_24 * V_25 ;
int V_32 = 0 ;
if ( ! F_14 ( & V_23 -> V_33 , F_33 , V_34 ) )
return - V_31 ;
V_55 = F_34 ( sizeof( * V_4 ) ,
L_25 , 1 , NULL , 0 , 0 , NULL , 0 ,
V_64 ) ;
if ( ! V_55 ) {
F_26 ( & V_23 -> V_33 , F_33 ) ;
return - V_31 ;
}
V_4 = V_55 -> V_5 ;
V_4 -> V_36 = L_26 ;
V_4 -> V_17 = V_37 ;
V_55 -> V_33 = & V_23 -> V_33 ;
F_16 ( V_23 , V_55 ) ;
V_55 -> V_38 = V_38 ( & V_23 -> V_33 ) ;
V_25 = F_9 ( V_23 , V_27 , 0 ) ;
if ( ! V_25 ) {
F_3 ( V_9 L_7
L_27 , V_28 ) ;
V_32 = - V_29 ;
goto V_46;
}
if ( ! F_17 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ,
V_4 -> V_36 ) ) {
F_3 ( V_9 L_28 ,
V_28 ) ;
V_32 = - V_47 ;
goto V_46;
}
V_4 -> V_57 = F_18 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ) ;
if ( ! V_4 -> V_57 ) {
F_3 ( V_9 L_29 ,
V_28 ) ;
V_32 = - V_31 ;
goto V_46;
}
F_4 ( V_4 -> V_57 + V_58 , 0 ) ;
V_55 -> V_39 = V_40 ;
V_55 -> V_16 = V_4 -> V_36 ;
if ( V_41 == V_42 )
V_55 -> V_43 = F_30 ;
V_4 -> V_44 = V_64 ++ ;
if ( F_35 ( V_55 ) > 0 ) {
F_20 ( L_30 , V_28 ) ;
goto V_46;
}
if ( V_41 == V_50 ) {
V_4 -> V_17 = F_21 ( V_23 , 0 ) ;
V_32 = F_22 ( & V_23 -> V_33 ,
V_4 -> V_17 ,
F_32 ,
V_51 ,
L_31 ,
V_55 ) ;
if ( V_32 < 0 ) {
F_3 ( V_9
L_16
L_32 , V_28 , V_4 -> V_17 ) ;
V_32 = - V_52 ;
goto V_53;
}
F_3 (KERN_INFO EDAC_MOD_STR L_33 ,
pdata->irq) ;
}
F_23 ( & V_23 -> V_33 , F_33 ) ;
F_20 ( L_19 , V_28 ) ;
return 0 ;
V_53:
F_36 ( & V_23 -> V_33 ) ;
V_46:
F_26 ( & V_23 -> V_33 , F_33 ) ;
F_37 ( V_55 ) ;
return V_32 ;
}
static int F_38 ( struct V_22 * V_23 )
{
struct V_54 * V_55 = F_28 ( V_23 ) ;
F_29 ( L_20 , V_28 ) ;
F_36 ( & V_23 -> V_33 ) ;
F_37 ( V_55 ) ;
return 0 ;
}
static void F_39 ( struct V_54 * V_55 )
{
struct V_65 * V_4 = V_55 -> V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_4 -> V_66 [ 1 ] + V_67 ) &
V_68 ;
if ( ! V_6 )
return;
F_3 ( V_9 L_34 ) ;
F_3 ( V_9 L_2 , V_6 ) ;
F_3 ( V_9 L_3 ,
F_2 ( V_4 -> V_66 [ 0 ] + V_69 ) ) ;
F_3 ( V_9 L_4 ,
F_2 ( V_4 -> V_66 [ 0 ] + V_70 ) ) ;
F_3 ( V_9 L_22 ,
F_2 ( V_4 -> V_66 [ 1 ] + V_71 ) ) ;
F_3 ( V_9 L_23 ,
F_2 ( V_4 -> V_66 [ 1 ] + V_72 ) ) ;
F_3 ( V_9 L_24 ,
F_2 ( V_4 -> V_66 [ 1 ] + V_73 ) ) ;
F_4 ( V_4 -> V_66 [ 1 ] + V_67 , 0 ) ;
F_31 ( V_55 , 0 , 0 , V_55 -> V_16 ) ;
}
static T_2 F_40 ( int V_17 , void * V_18 )
{
struct V_54 * V_55 = V_18 ;
struct V_65 * V_4 = V_55 -> V_5 ;
T_1 V_6 ;
V_6 = F_2 ( V_4 -> V_66 [ 1 ] + V_67 ) &
V_68 ;
if ( ! V_6 )
return V_20 ;
F_39 ( V_55 ) ;
return V_21 ;
}
static int T_5 F_41 ( struct V_22 * V_23 )
{
struct V_54 * V_55 ;
struct V_24 * V_25 ;
struct V_65 * V_4 ;
int V_32 = 0 ;
if ( ! F_14 ( & V_23 -> V_33 , F_41 , V_34 ) )
return - V_31 ;
V_55 = F_34 ( sizeof( * V_4 ) ,
L_35 , 1 , NULL , 0 , 0 , NULL , 0 ,
V_64 ) ;
if ( ! V_55 ) {
F_26 ( & V_23 -> V_33 , F_41 ) ;
return - V_31 ;
}
V_4 = V_55 -> V_5 ;
V_4 -> V_36 = L_36 ;
V_4 -> V_17 = V_37 ;
V_55 -> V_33 = & V_23 -> V_33 ;
F_16 ( V_23 , V_55 ) ;
V_55 -> V_38 = V_38 ( & V_23 -> V_33 ) ;
V_25 = F_9 ( V_23 , V_27 , 0 ) ;
if ( ! V_25 ) {
F_3 ( V_9 L_7
L_37 , V_28 ) ;
V_32 = - V_29 ;
goto V_46;
}
if ( ! F_17 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ,
V_4 -> V_36 ) ) {
F_3 ( V_9 L_11 ,
V_28 ) ;
V_32 = - V_47 ;
goto V_46;
}
V_4 -> V_66 [ 0 ] = F_18 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ) ;
if ( ! V_4 -> V_66 [ 0 ] ) {
F_3 ( V_9 L_38 , V_28 ) ;
V_32 = - V_31 ;
goto V_46;
}
V_25 = F_9 ( V_23 , V_27 , 1 ) ;
if ( ! V_25 ) {
F_3 ( V_9 L_7
L_37 , V_28 ) ;
V_32 = - V_29 ;
goto V_46;
}
if ( ! F_17 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ,
V_4 -> V_36 ) ) {
F_3 ( V_9 L_11 ,
V_28 ) ;
V_32 = - V_47 ;
goto V_46;
}
V_4 -> V_66 [ 1 ] = F_18 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ) ;
if ( ! V_4 -> V_66 [ 1 ] ) {
F_3 ( V_9 L_38 , V_28 ) ;
V_32 = - V_31 ;
goto V_46;
}
F_4 ( V_4 -> V_66 [ 1 ] + V_67 , 0 ) ;
F_4 ( V_4 -> V_66 [ 1 ] + V_74 , 0 ) ;
F_4 ( V_4 -> V_66 [ 1 ] + V_74 , 0x000000ff ) ;
V_55 -> V_39 = V_40 ;
V_55 -> V_16 = V_4 -> V_36 ;
if ( V_41 == V_42 )
V_55 -> V_43 = F_39 ;
V_4 -> V_44 = V_64 ++ ;
if ( F_35 ( V_55 ) > 0 ) {
F_20 ( L_30 , V_28 ) ;
goto V_46;
}
if ( V_41 == V_50 ) {
V_4 -> V_17 = F_21 ( V_23 , 0 ) ;
V_32 = F_22 ( & V_23 -> V_33 ,
V_4 -> V_17 ,
F_40 ,
V_51 ,
L_39 ,
V_55 ) ;
if ( V_32 < 0 ) {
F_3 ( V_9
L_40
L_41 , V_28 , V_4 -> V_17 ) ;
V_32 = - V_52 ;
goto V_53;
}
F_3 (KERN_INFO EDAC_MOD_STR
L_42 , pdata->irq) ;
}
F_23 ( & V_23 -> V_33 , F_41 ) ;
F_20 ( L_19 , V_28 ) ;
return 0 ;
V_53:
F_36 ( & V_23 -> V_33 ) ;
V_46:
F_26 ( & V_23 -> V_33 , F_41 ) ;
F_37 ( V_55 ) ;
return V_32 ;
}
static int F_42 ( struct V_22 * V_23 )
{
struct V_54 * V_55 = F_28 ( V_23 ) ;
F_29 ( L_20 , V_28 ) ;
F_36 ( & V_23 -> V_33 ) ;
F_37 ( V_55 ) ;
return 0 ;
}
static void F_43 ( struct V_75 * V_76 )
{
struct V_77 * V_4 = V_76 -> V_5 ;
T_1 V_78 ;
T_1 V_79 ;
T_1 V_80 ;
T_1 V_81 ;
T_1 V_82 ;
V_78 = F_2 ( V_4 -> V_83 + V_84 ) ;
if ( ! V_78 )
return;
V_79 = V_78 & ~ 0x3 ;
V_80 = F_2 ( V_4 -> V_83 + V_85 ) ;
V_81 = F_2 ( V_4 -> V_83 + V_86 ) ;
V_82 = V_80 ^ V_81 ;
if ( ! ( V_78 & 0x1 ) )
F_44 ( V_76 , V_79 >> V_87 ,
V_79 & V_88 , V_82 , 0 , 0 ,
V_76 -> V_16 ) ;
else
F_45 ( V_76 , V_79 >> V_87 ,
V_79 & V_88 , 0 , V_76 -> V_16 ) ;
F_4 ( V_4 -> V_83 + V_84 , 0 ) ;
}
static T_2 F_46 ( int V_17 , void * V_18 )
{
struct V_75 * V_76 = V_18 ;
struct V_77 * V_4 = V_76 -> V_5 ;
T_1 V_78 ;
V_78 = F_2 ( V_4 -> V_83 + V_84 ) ;
if ( ! V_78 )
return V_20 ;
F_43 ( V_76 ) ;
return V_21 ;
}
static void F_47 ( struct V_77 * V_4 )
{
struct V_89 * V_90 = NULL ;
const unsigned int * V_78 ;
V_90 = F_48 ( NULL , L_43 ) ;
if ( ! V_90 )
return;
V_78 = F_49 ( V_90 , L_44 , NULL ) ;
V_4 -> V_91 = V_78 [ 1 ] ;
}
static void F_50 ( struct V_75 * V_76 ,
struct V_77 * V_4 )
{
struct V_92 * V_93 ;
T_1 V_94 ;
T_1 V_95 ;
F_47 ( V_4 ) ;
V_95 = F_2 ( V_4 -> V_83 + V_96 ) ;
V_93 = & V_76 -> V_97 [ 0 ] ;
V_93 -> V_98 = 0 ;
V_93 -> V_99 = V_4 -> V_91 >> V_87 ;
V_93 -> V_100 = V_93 -> V_98 + V_93 -> V_99 - 1 ;
V_93 -> V_101 = 8 ;
V_93 -> V_102 = ( V_95 & V_103 ) ? V_104 : V_105 ;
V_94 = ( V_95 >> 20 ) & 0x3 ;
switch ( V_94 ) {
case 0x0 :
V_93 -> V_106 = V_107 ;
break;
case 0x2 :
V_93 -> V_106 = V_108 ;
break;
case 0x3 :
V_93 -> V_106 = V_109 ;
break;
default:
V_93 -> V_106 = V_110 ;
break;
}
V_93 -> V_111 = V_112 ;
}
static int T_5 F_51 ( struct V_22 * V_23 )
{
struct V_75 * V_76 ;
struct V_77 * V_4 ;
struct V_24 * V_25 ;
T_1 V_95 ;
int V_32 = 0 ;
if ( ! F_14 ( & V_23 -> V_33 , F_51 , V_34 ) )
return - V_31 ;
V_76 = F_52 ( sizeof( struct V_77 ) , 1 , 1 , V_113 ) ;
if ( ! V_76 ) {
F_3 ( V_9 L_45 , V_28 ) ;
F_26 ( & V_23 -> V_33 , F_51 ) ;
return - V_31 ;
}
V_4 = V_76 -> V_5 ;
V_76 -> V_33 = & V_23 -> V_33 ;
F_16 ( V_23 , V_76 ) ;
V_4 -> V_36 = L_46 ;
V_4 -> V_17 = V_37 ;
V_76 -> V_38 = V_38 ( & V_23 -> V_33 ) ;
V_4 -> V_44 = V_113 ++ ;
V_25 = F_9 ( V_23 , V_27 , 0 ) ;
if ( ! V_25 ) {
F_3 ( V_9 L_7
L_47 , V_28 ) ;
V_32 = - V_29 ;
goto V_46;
}
if ( ! F_17 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ,
V_4 -> V_36 ) ) {
F_3 ( V_9 L_11 ,
V_28 ) ;
V_32 = - V_47 ;
goto V_46;
}
V_4 -> V_83 = F_18 ( & V_23 -> V_33 ,
V_25 -> V_30 ,
F_11 ( V_25 ) ) ;
if ( ! V_4 -> V_83 ) {
F_3 ( V_9 L_48 , V_28 ) ;
V_32 = - V_31 ;
goto V_46;
}
V_95 = F_2 ( V_4 -> V_83 + V_96 ) ;
if ( ! ( V_95 & V_114 ) ) {
F_3 ( V_115 L_49 , V_28 ) ;
V_32 = - V_52 ;
goto V_53;
}
F_20 ( L_50 , V_28 ) ;
V_76 -> V_116 = V_117 | V_118 ;
V_76 -> V_119 = V_120 | V_121 ;
V_76 -> V_122 = V_121 ;
V_76 -> V_39 = V_40 ;
V_76 -> V_123 = V_124 ;
V_76 -> V_16 = V_125 ;
if ( V_41 == V_42 )
V_76 -> V_43 = F_43 ;
V_76 -> V_126 = NULL ;
V_76 -> V_127 = V_128 ;
F_50 ( V_76 , V_4 ) ;
F_4 ( V_4 -> V_83 + V_84 , 0 ) ;
V_95 = F_2 ( V_4 -> V_83 + V_129 ) ;
V_95 = ( V_95 & 0xff00ffff ) | 0x10000 ;
F_4 ( V_4 -> V_83 + V_129 , V_95 ) ;
if ( F_53 ( V_76 ) ) {
F_20 ( L_51 , V_28 ) ;
goto V_46;
}
if ( V_41 == V_50 ) {
V_4 -> V_17 = F_21 ( V_23 , 0 ) ;
V_32 = F_22 ( & V_23 -> V_33 ,
V_4 -> V_17 ,
F_46 ,
V_51 ,
L_52 ,
V_76 ) ;
if ( V_32 < 0 ) {
F_3 ( V_9 L_16
L_53 , V_28 , V_4 -> V_17 ) ;
V_32 = - V_52 ;
goto V_53;
}
F_3 (KERN_INFO EDAC_MOD_STR L_54 ,
pdata->irq) ;
}
F_20 ( L_19 , V_28 ) ;
return 0 ;
V_53:
F_54 ( & V_23 -> V_33 ) ;
V_46:
F_26 ( & V_23 -> V_33 , F_51 ) ;
F_55 ( V_76 ) ;
return V_32 ;
}
static int F_56 ( struct V_22 * V_23 )
{
struct V_75 * V_76 = F_28 ( V_23 ) ;
F_29 ( L_20 , V_28 ) ;
F_54 ( & V_23 -> V_33 ) ;
F_55 ( V_76 ) ;
return 0 ;
}
static int T_3 F_57 ( void )
{
int V_130 = 0 ;
F_3 ( V_131 L_55 V_124 L_56 ) ;
F_3 ( V_131 L_57 ) ;
switch ( V_41 ) {
case V_42 :
case V_50 :
break;
default:
V_41 = V_50 ;
break;
}
V_130 = F_58 ( & V_132 ) ;
if ( V_130 )
F_3 (KERN_WARNING EDAC_MOD_STR L_58 ) ;
V_130 = F_58 ( & V_133 ) ;
if ( V_130 )
F_3 (KERN_WARNING EDAC_MOD_STR
L_59 ) ;
V_130 = F_58 ( & V_134 ) ;
if ( V_130 )
F_3 (KERN_WARNING EDAC_MOD_STR
L_60 ) ;
#ifdef F_59
V_130 = F_58 ( & V_135 ) ;
if ( V_130 )
F_3 (KERN_WARNING EDAC_MOD_STR
L_61 ) ;
#endif
return V_130 ;
}
static void T_6 F_60 ( void )
{
#ifdef F_59
F_61 ( & V_135 ) ;
#endif
F_61 ( & V_134 ) ;
F_61 ( & V_133 ) ;
F_61 ( & V_132 ) ;
}
