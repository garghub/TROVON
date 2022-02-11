static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline T_1 F_3 ( struct V_2 * V_3 , T_1 V_4 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
return F_4 ( V_5 -> V_6 + V_4 ) ;
}
static inline T_1 F_5 ( struct V_2 * V_3 , T_1 V_4 , T_1 V_7 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_6 ( V_7 , ( V_5 -> V_6 + V_4 ) ) ;
return V_7 ;
}
static inline T_1 F_7 ( struct V_2 * V_3 , T_1 V_4 ,
T_1 V_7 , T_1 V_8 )
{
T_1 V_9 = ( F_3 ( V_3 , V_4 ) & ~ V_8 ) | ( V_7 & V_8 ) ;
F_5 ( V_3 , V_4 , V_9 ) ;
return V_9 ;
}
static inline T_1 F_8 ( struct V_2 * V_3 , T_1 V_7 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_6 ( V_7 , V_5 -> V_10 ) ;
V_7 = F_4 ( V_5 -> V_10 ) ;
return V_7 ;
}
static int F_9 ( struct V_2 * V_3 , T_1 V_11 )
{
switch ( V_11 ) {
case 0 :
F_10 ( V_12 , 1 , V_3 , L_1 ) ;
F_5 ( V_3 , V_13 , 0 ) ;
break;
case 1 :
F_10 ( V_12 , 1 , V_3 , L_2 ) ;
F_5 ( V_3 , V_13 , V_14 ) ;
break;
case 2 :
F_10 ( V_12 , 1 , V_3 , L_3 ) ;
F_5 ( V_3 , V_13 , V_15 ) ;
break;
default:
return - V_16 ;
}
return 0 ;
}
static void F_11 ( struct V_2 * V_3 , int V_17 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_18 * V_19 = V_5 -> V_19 ;
F_10 ( V_12 , 2 , V_3 , L_4 ) ;
if ( V_17 ) {
F_5 ( V_3 , V_20 , 0 ) ;
F_5 ( V_3 , V_21 , 0 ) ;
F_5 ( V_3 , V_22 , 0 ) ;
F_5 ( V_3 , V_23 , 0 ) ;
F_5 ( V_3 , V_24 , 0 ) ;
F_5 ( V_3 , V_25 , 0 ) ;
F_5 ( V_3 , V_26 , 0 ) ;
F_5 ( V_3 , V_27 , 0 ) ;
F_5 ( V_3 , V_28 , 0 ) ;
F_5 ( V_3 , V_29 , 0 ) ;
F_5 ( V_3 , V_30 , 0 ) ;
F_5 ( V_3 , V_31 , 0 ) ;
F_5 ( V_3 , V_13 , 0 ) ;
} else {
F_5 ( V_3 , V_20 , 0 ) ;
F_5 ( V_3 , V_32 , 0x141 ) ;
F_5 ( V_3 , V_33 , 0 ) ;
F_5 ( V_3 , V_34 , 0 ) ;
F_5 ( V_3 , V_35 , 0x0000057C ) ;
F_5 ( V_3 , V_22 , 0 ) ;
if ( V_19 -> V_36 != V_37 )
F_5 ( V_3 , V_38 , 0x100 ) ;
F_5 ( V_3 , V_23 , 0 ) ;
F_5 ( V_3 , V_26 , 0 ) ;
F_5 ( V_3 , V_24 , 0 ) ;
F_5 ( V_3 , V_25 , 0 ) ;
F_5 ( V_3 , V_27 , 0 ) ;
F_5 ( V_3 , V_30 , 0 ) ;
F_5 ( V_3 , V_28 , 0 ) ;
F_5 ( V_3 , V_29 , 0 ) ;
F_5 ( V_3 , V_39 , 0 ) ;
F_5 ( V_3 , V_40 , 0 ) ;
F_5 ( V_3 , V_31 , 0 ) ;
F_5 ( V_3 , V_41 , 0 ) ;
F_5 ( V_3 , V_42 , 1 ) ;
F_5 ( V_3 , V_43 , 2 ) ;
}
}
static int F_12 ( struct V_2 * V_3 )
{
T_1 V_7 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_18 * V_19 = V_5 -> V_19 ;
F_10 ( V_12 , 2 , V_3 , L_5 ) ;
F_13 ( V_44 , 1 ) ;
if ( V_19 -> V_45 ( V_46 , V_47 ) < 0 )
return - V_16 ;
F_11 ( V_3 , 0 ) ;
if ( V_19 -> V_36 == V_37 ) {
F_5 ( V_3 , V_48 , 0x01 ) ;
F_5 ( V_3 , V_32 , 0 ) ;
V_7 = F_8 ( V_3 , V_49 ) ;
} else if ( V_19 -> V_36 == V_50 ) {
F_5 ( V_3 , V_48 , 0x01 ) ;
F_5 ( V_3 , V_32 , 0 ) ;
F_8 ( V_3 , V_51 ) ;
} else {
F_7 ( V_3 , V_32 , 0 , 1 << 1 ) ;
F_5 ( V_3 , V_31 , 0x1 ) ;
F_7 ( V_3 , V_52 , 0 , V_53 ) ;
F_7 ( V_3 , V_52 , 0 , V_54 ) ;
}
F_5 ( V_3 , V_20 , 0 ) ;
F_7 ( V_3 , V_20 , ( 1 << V_55 ) ,
V_56 ) ;
F_7 ( V_3 , V_20 , ( 0 << V_57 ) , V_57 ) ;
F_7 ( V_3 , V_20 , ( 0 << V_58 ) ,
V_59 ) ;
F_5 ( V_3 , V_60 , 0x0 ) ;
F_7 ( V_3 , V_20 , V_61 , V_61 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_18 * V_19 = V_5 -> V_19 ;
F_10 ( V_12 , 2 , V_3 , L_6 ) ;
F_13 ( V_44 , 1 ) ;
if ( V_5 -> V_19 -> V_45 ( V_46 , V_62 ) < 0 )
return - V_16 ;
F_11 ( V_3 , 0 ) ;
if ( V_19 -> V_36 == V_37 ) {
F_5 ( V_3 , V_48 , 0x1 ) ;
F_5 ( V_3 , V_32 , 0 ) ;
F_8 ( V_3 , V_49 ) ;
} else if ( V_19 -> V_36 == V_50 ) {
F_5 ( V_3 , V_48 , 0x1 ) ;
F_5 ( V_3 , V_32 , 0 ) ;
F_8 ( V_3 , V_51 ) ;
} else {
F_7 ( V_3 , V_32 , 0 , 1 << 1 ) ;
F_5 ( V_3 , V_31 , 0x1 ) ;
}
F_7 ( V_3 , V_33 , 1 << V_63 ,
V_64 ) ;
F_5 ( V_3 , V_20 , 0 ) ;
F_7 ( V_3 , V_20 ,
( 1 << V_55 ) ,
V_56 ) ;
F_7 ( V_3 , V_20 ,
( 0 << V_57 ) , V_57 ) ;
F_7 ( V_3 , V_20 ,
( 1 << V_58 ) ,
V_59 ) ;
F_5 ( V_3 , V_60 , 0x0 ) ;
F_7 ( V_3 , V_20 , V_61 , V_61 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_18 * V_19 = V_5 -> V_19 ;
F_10 ( V_12 , 2 , V_3 , L_7 ) ;
if ( ( V_19 -> V_36 != V_65 ) &&
( V_19 -> V_36 != V_50 ) )
return - V_16 ;
if ( V_19 -> V_45 ( V_66 , 27000000 ) < 0 )
return - V_16 ;
F_11 ( V_3 , 0 ) ;
if ( V_19 -> V_36 == V_50 )
F_8 ( V_3 , V_67 ) ;
F_5 ( V_3 , V_42 , 0 ) ;
F_5 ( V_3 , V_43 , 1 ) ;
if ( V_19 -> V_36 == V_65 ) {
F_7 ( V_3 , V_52 , V_53 ,
V_53 ) ;
F_7 ( V_3 , V_52 , V_54 ,
V_54 ) ;
}
F_5 ( V_3 , V_20 , 0 ) ;
F_7 ( V_3 , V_20 , ( 1 << V_55 ) ,
V_56 ) ;
F_7 ( V_3 , V_20 , V_68 , V_68 ) ;
F_7 ( V_3 , V_20 , ( V_69 << V_58 ) ,
V_59 ) ;
F_7 ( V_3 , V_20 , V_70 <<
V_71 , V_72 ) ;
F_7 ( V_3 , V_20 , V_61 , V_61 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_18 * V_19 = V_5 -> V_19 ;
F_10 ( V_12 , 2 , V_3 , L_8 ) ;
if ( ( V_19 -> V_36 != V_65 ) &&
( V_19 -> V_36 != V_50 ) )
return - V_16 ;
if ( V_19 -> V_45 ( V_66 , 27000000 ) < 0 )
return - V_16 ;
F_11 ( V_3 , 0 ) ;
if ( V_19 -> V_36 == V_50 )
F_8 ( V_3 , V_67 ) ;
F_5 ( V_3 , V_42 , 0 ) ;
F_5 ( V_3 , V_43 , 1 ) ;
if ( V_19 -> V_36 == V_65 ) {
F_7 ( V_3 , V_52 , V_53 ,
V_53 ) ;
F_7 ( V_3 , V_52 , V_54 ,
V_54 ) ;
}
F_5 ( V_3 , V_20 , 0 ) ;
F_7 ( V_3 , V_20 , ( 1 << V_55 ) ,
V_56 ) ;
F_7 ( V_3 , V_20 , V_68 , V_68 ) ;
F_7 ( V_3 , V_20 , ( V_73 << V_58 ) ,
V_59 ) ;
F_7 ( V_3 , V_20 , V_70 <<
V_71 , V_72 ) ;
F_7 ( V_3 , V_20 , V_61 , V_61 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_18 * V_19 = V_5 -> V_19 ;
if ( V_19 -> V_45 ( V_66 , 74250000 ) < 0 )
return - V_16 ;
F_11 ( V_3 , 0 ) ;
F_5 ( V_3 , V_42 , 0 ) ;
F_5 ( V_3 , V_43 , 1 ) ;
F_5 ( V_3 , V_20 , 0 ) ;
F_7 ( V_3 , V_20 , ( 1 << V_55 ) ,
V_56 ) ;
F_7 ( V_3 , V_20 , V_68 , V_68 ) ;
F_7 ( V_3 , V_20 , ( V_74 << V_58 ) ,
V_59 ) ;
F_7 ( V_3 , V_20 , V_61 , V_61 ) ;
F_5 ( V_3 , V_75 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_18 * V_19 = V_5 -> V_19 ;
if ( V_19 -> V_45 ( V_66 , 74250000 ) < 0 )
return - V_16 ;
F_11 ( V_3 , 0 ) ;
F_5 ( V_3 , V_42 , 0 ) ;
F_5 ( V_3 , V_43 , 1 ) ;
F_5 ( V_3 , V_20 , 0 ) ;
F_7 ( V_3 , V_20 , ( 1 << V_55 ) ,
V_56 ) ;
F_7 ( V_3 , V_20 , V_68 , V_68 ) ;
F_7 ( V_3 , V_20 , ( V_76 << V_58 ) ,
V_59 ) ;
F_7 ( V_3 , V_20 , V_61 , V_61 ) ;
F_5 ( V_3 , V_75 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , T_2 V_77 )
{
F_10 ( V_12 , 1 , V_3 , L_9 ) ;
if ( V_77 & V_47 )
return F_12 ( V_3 ) ;
else if ( V_77 & V_62 )
return F_14 ( V_3 ) ;
return - V_16 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_78 * V_79 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_80 = V_79 -> V_81 . V_80 ;
int V_82 ;
F_10 ( V_12 , 1 , V_3 , L_10 ) ;
if ( V_80 == 576 )
return F_16 ( V_3 ) ;
else if ( V_80 == 480 )
return F_15 ( V_3 ) ;
else if ( ( V_80 == 720 ) &&
( V_5 -> V_19 -> V_36 == V_50 ) ) {
V_82 = F_17 ( V_3 ) ;
F_8 ( V_3 , V_67 ) ;
return V_82 ;
} else if ( ( V_80 == 1080 ) &&
( V_5 -> V_19 -> V_36 == V_50 ) ) {
V_82 = F_18 ( V_3 ) ;
F_8 ( V_3 , V_67 ) ;
return V_82 ;
}
return - V_16 ;
}
static int F_21 ( struct V_2 * V_3 , T_1 V_83 , T_1 V_84 ,
T_1 V_85 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_82 ;
F_10 ( V_12 , 1 , V_3 , L_11 ) ;
V_82 = F_9 ( V_3 , V_84 ) ;
if ( ! V_82 )
V_5 -> V_84 = V_84 ;
return V_82 ;
}
static long F_22 ( struct V_2 * V_3 ,
unsigned int V_86 ,
void * V_87 )
{
T_1 V_7 ;
switch ( V_86 ) {
case V_88 :
V_7 = F_3 ( V_3 , V_89 ) ;
* ( ( int * ) V_87 ) = ( ( V_7 & V_90 ) ==
V_90 ) ;
break;
default:
F_23 ( V_3 , L_12 ) ;
break;
}
return 0 ;
}
static int F_24 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_82 ;
V_5 -> V_84 = 0 ;
V_5 -> V_91 = V_47 ;
V_82 = F_21 ( V_3 , 0 , V_5 -> V_84 , 0 ) ;
if ( V_82 < 0 ) {
F_23 ( V_3 , L_13 ) ;
return - V_16 ;
}
V_82 = F_19 ( V_3 , V_5 -> V_91 ) ;
if ( V_82 < 0 ) {
F_23 ( V_3 , L_14 ) ;
return - V_16 ;
}
return V_82 ;
}
static int F_25 ( struct V_92 * V_93 , void * V_94 )
{
struct V_95 * V_96 = F_26 ( V_93 ) ;
struct V_1 * * V_5 = V_94 ;
if ( strcmp ( V_97 , V_96 -> V_98 ) == 0 )
* V_5 = F_27 ( V_96 ) ;
return 0 ;
}
struct V_2 * F_28 ( struct V_99 * V_100 ,
const char * V_101 )
{
struct V_1 * V_5 ;
int V_102 ;
V_102 = F_29 ( & V_103 , NULL , & V_5 ,
F_25 ) ;
if ( V_5 == NULL )
return NULL ;
F_30 ( & V_5 -> V_3 , & V_104 ) ;
strcpy ( V_5 -> V_3 . V_98 , V_101 ) ;
if ( F_31 ( V_100 , & V_5 -> V_3 ) < 0 ) {
F_23 ( V_100 ,
L_15 ) ;
return NULL ;
}
if ( F_24 ( & V_5 -> V_3 ) ) {
F_23 ( V_100 ,
L_16 ) ;
return NULL ;
}
return & V_5 -> V_3 ;
}
static int F_32 ( struct V_95 * V_96 )
{
struct V_1 * V_5 ;
struct V_105 * V_106 ;
int V_82 ;
V_5 = F_33 ( sizeof( struct V_1 ) , V_107 ) ;
if ( V_5 == NULL )
return - V_108 ;
V_5 -> V_96 = & V_96 -> V_93 ;
V_5 -> V_19 = V_96 -> V_93 . V_109 ;
if ( NULL == V_5 -> V_19 ) {
F_34 ( V_5 -> V_96 , L_17
L_18 ) ;
V_82 = - V_110 ;
goto V_111;
}
V_106 = F_35 ( V_96 , V_112 , 0 ) ;
if ( ! V_106 ) {
F_34 ( V_5 -> V_96 ,
L_19 ) ;
V_82 = - V_113 ;
goto V_111;
}
if ( ! F_36 ( V_106 -> V_114 , F_37 ( V_106 ) , L_20 ) ) {
F_34 ( V_5 -> V_96 , L_21 ) ;
V_82 = - V_113 ;
goto V_111;
}
V_5 -> V_6 = F_38 ( V_106 -> V_114 , F_37 ( V_106 ) ) ;
if ( ! V_5 -> V_6 ) {
F_34 ( V_5 -> V_96 , L_22 ) ;
V_82 = - V_113 ;
goto V_115;
}
if ( V_5 -> V_19 -> V_36 != V_65 ) {
V_106 = F_35 ( V_96 , V_112 , 1 ) ;
if ( ! V_106 ) {
F_34 ( V_5 -> V_96 ,
L_23 ) ;
V_82 = - V_113 ;
goto V_116;
}
if ( ! F_36 ( V_106 -> V_114 ,
F_37 ( V_106 ) , L_20 ) ) {
F_34 ( V_5 -> V_96 ,
L_24 ) ;
V_82 = - V_113 ;
goto V_116;
}
V_5 -> V_10 = F_38 ( V_106 -> V_114 ,
F_37 ( V_106 ) ) ;
if ( ! V_5 -> V_10 ) {
F_34 ( V_5 -> V_96 ,
L_25 ) ;
V_82 = - V_113 ;
goto V_117;
}
}
F_39 ( & V_5 -> V_118 ) ;
F_40 ( V_96 , V_5 ) ;
F_41 ( V_5 -> V_96 , L_26 ) ;
return 0 ;
V_117:
F_42 ( V_106 -> V_114 , F_37 ( V_106 ) ) ;
V_116:
F_43 ( V_5 -> V_6 ) ;
V_115:
V_106 = F_35 ( V_96 , V_112 , 0 ) ;
F_42 ( V_106 -> V_114 , F_37 ( V_106 ) ) ;
V_111:
F_44 ( V_5 ) ;
return V_82 ;
}
static int F_45 ( struct V_95 * V_96 )
{
struct V_1 * V_5 = F_27 ( V_96 ) ;
struct V_105 * V_106 ;
V_106 = F_35 ( V_96 , V_112 , 0 ) ;
F_43 ( ( void * ) V_5 -> V_6 ) ;
F_42 ( V_106 -> V_114 , F_37 ( V_106 ) ) ;
if ( V_5 -> V_19 -> V_36 != V_65 ) {
V_106 = F_35 ( V_96 , V_112 , 1 ) ;
F_43 ( ( void * ) V_5 -> V_10 ) ;
F_42 ( V_106 -> V_114 , F_37 ( V_106 ) ) ;
}
F_44 ( V_5 ) ;
return 0 ;
}
