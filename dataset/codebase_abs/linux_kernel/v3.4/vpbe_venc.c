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
if ( V_19 -> V_45 ( V_66 , V_67 ) < 0 )
return - V_16 ;
F_11 ( V_3 , 0 ) ;
if ( V_19 -> V_36 == V_50 )
F_8 ( V_3 , V_68 ) ;
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
F_7 ( V_3 , V_20 , V_69 , V_69 ) ;
F_7 ( V_3 , V_20 , ( V_70 << V_58 ) ,
V_59 ) ;
F_7 ( V_3 , V_20 , V_71 <<
V_72 , V_73 ) ;
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
if ( V_19 -> V_45 ( V_66 , V_74 ) < 0 )
return - V_16 ;
F_11 ( V_3 , 0 ) ;
if ( V_19 -> V_36 == V_50 )
F_8 ( V_3 , V_68 ) ;
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
F_7 ( V_3 , V_20 , V_69 , V_69 ) ;
F_7 ( V_3 , V_20 , ( V_75 << V_58 ) ,
V_59 ) ;
F_7 ( V_3 , V_20 , V_71 <<
V_72 , V_73 ) ;
F_7 ( V_3 , V_20 , V_61 , V_61 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_18 * V_19 = V_5 -> V_19 ;
if ( V_19 -> V_45 ( V_66 , V_76 ) < 0 )
return - V_16 ;
F_11 ( V_3 , 0 ) ;
F_5 ( V_3 , V_42 , 0 ) ;
F_5 ( V_3 , V_43 , 1 ) ;
F_5 ( V_3 , V_20 , 0 ) ;
F_7 ( V_3 , V_20 , ( 1 << V_55 ) ,
V_56 ) ;
F_7 ( V_3 , V_20 , V_69 , V_69 ) ;
F_7 ( V_3 , V_20 , ( V_77 << V_58 ) ,
V_59 ) ;
F_7 ( V_3 , V_20 , V_61 , V_61 ) ;
F_5 ( V_3 , V_78 , 0 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_18 * V_19 = V_5 -> V_19 ;
if ( V_19 -> V_45 ( V_66 , V_79 ) < 0 )
return - V_16 ;
F_11 ( V_3 , 0 ) ;
F_5 ( V_3 , V_42 , 0 ) ;
F_5 ( V_3 , V_43 , 1 ) ;
F_5 ( V_3 , V_20 , 0 ) ;
F_7 ( V_3 , V_20 , ( 1 << V_55 ) ,
V_56 ) ;
F_7 ( V_3 , V_20 , V_69 , V_69 ) ;
F_7 ( V_3 , V_20 , ( V_80 << V_58 ) ,
V_59 ) ;
F_7 ( V_3 , V_20 , V_61 , V_61 ) ;
F_5 ( V_3 , V_78 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 , T_2 V_81 )
{
F_10 ( V_12 , 1 , V_3 , L_9 ) ;
if ( V_81 & V_47 )
return F_12 ( V_3 ) ;
else if ( V_81 & V_62 )
return F_14 ( V_3 ) ;
return - V_16 ;
}
static int F_20 ( struct V_2 * V_3 ,
struct V_82 * V_83 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_84 ;
F_10 ( V_12 , 1 , V_3 , L_10 ) ;
if ( V_83 -> V_85 == V_74 )
return F_16 ( V_3 ) ;
else if ( V_83 -> V_85 == V_67 )
return F_15 ( V_3 ) ;
else if ( ( V_83 -> V_85 == V_76 ) &&
( V_5 -> V_19 -> V_36 == V_50 ) ) {
V_84 = F_17 ( V_3 ) ;
F_8 ( V_3 , V_68 ) ;
return V_84 ;
} else if ( ( V_83 -> V_85 == V_86 ) &&
( V_5 -> V_19 -> V_36 == V_50 ) ) {
V_84 = F_18 ( V_3 ) ;
F_8 ( V_3 , V_68 ) ;
return V_84 ;
}
return - V_16 ;
}
static int F_21 ( struct V_2 * V_3 , T_1 V_87 , T_1 V_88 ,
T_1 V_89 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_84 ;
F_10 ( V_12 , 1 , V_3 , L_11 ) ;
V_84 = F_9 ( V_3 , V_88 ) ;
if ( ! V_84 )
V_5 -> V_88 = V_88 ;
return V_84 ;
}
static long F_22 ( struct V_2 * V_3 ,
unsigned int V_90 ,
void * V_91 )
{
T_1 V_7 ;
switch ( V_90 ) {
case V_92 :
V_7 = F_3 ( V_3 , V_93 ) ;
* ( ( int * ) V_91 ) = ( ( V_7 & V_94 ) ==
V_94 ) ;
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
int V_84 ;
V_5 -> V_88 = 0 ;
V_5 -> V_95 = V_47 ;
V_84 = F_21 ( V_3 , 0 , V_5 -> V_88 , 0 ) ;
if ( V_84 < 0 ) {
F_23 ( V_3 , L_13 ) ;
return - V_16 ;
}
V_84 = F_19 ( V_3 , V_5 -> V_95 ) ;
if ( V_84 < 0 ) {
F_23 ( V_3 , L_14 ) ;
return - V_16 ;
}
return V_84 ;
}
static int F_25 ( struct V_96 * V_97 , void * V_98 )
{
struct V_99 * V_100 = F_26 ( V_97 ) ;
struct V_1 * * V_5 = V_98 ;
if ( strcmp ( V_101 , V_100 -> V_102 ) == 0 )
* V_5 = F_27 ( V_100 ) ;
return 0 ;
}
struct V_2 * F_28 ( struct V_103 * V_104 ,
const char * V_105 )
{
struct V_1 * V_5 ;
int V_106 ;
V_106 = F_29 ( & V_107 , NULL , & V_5 ,
F_25 ) ;
if ( V_5 == NULL )
return NULL ;
F_30 ( & V_5 -> V_3 , & V_108 ) ;
strcpy ( V_5 -> V_3 . V_102 , V_105 ) ;
if ( F_31 ( V_104 , & V_5 -> V_3 ) < 0 ) {
F_23 ( V_104 ,
L_15 ) ;
return NULL ;
}
if ( F_24 ( & V_5 -> V_3 ) ) {
F_23 ( V_104 ,
L_16 ) ;
return NULL ;
}
return & V_5 -> V_3 ;
}
static int F_32 ( struct V_99 * V_100 )
{
struct V_1 * V_5 ;
struct V_109 * V_110 ;
int V_84 ;
V_5 = F_33 ( sizeof( struct V_1 ) , V_111 ) ;
if ( V_5 == NULL )
return - V_112 ;
V_5 -> V_100 = & V_100 -> V_97 ;
V_5 -> V_19 = V_100 -> V_97 . V_113 ;
if ( NULL == V_5 -> V_19 ) {
F_34 ( V_5 -> V_100 , L_17
L_18 ) ;
V_84 = - V_114 ;
goto V_115;
}
V_110 = F_35 ( V_100 , V_116 , 0 ) ;
if ( ! V_110 ) {
F_34 ( V_5 -> V_100 ,
L_19 ) ;
V_84 = - V_117 ;
goto V_115;
}
if ( ! F_36 ( V_110 -> V_118 , F_37 ( V_110 ) , L_20 ) ) {
F_34 ( V_5 -> V_100 , L_21 ) ;
V_84 = - V_117 ;
goto V_115;
}
V_5 -> V_6 = F_38 ( V_110 -> V_118 , F_37 ( V_110 ) ) ;
if ( ! V_5 -> V_6 ) {
F_34 ( V_5 -> V_100 , L_22 ) ;
V_84 = - V_117 ;
goto V_119;
}
if ( V_5 -> V_19 -> V_36 != V_65 ) {
V_110 = F_35 ( V_100 , V_116 , 1 ) ;
if ( ! V_110 ) {
F_34 ( V_5 -> V_100 ,
L_23 ) ;
V_84 = - V_117 ;
goto V_120;
}
if ( ! F_36 ( V_110 -> V_118 ,
F_37 ( V_110 ) , L_20 ) ) {
F_34 ( V_5 -> V_100 ,
L_24 ) ;
V_84 = - V_117 ;
goto V_120;
}
V_5 -> V_10 = F_38 ( V_110 -> V_118 ,
F_37 ( V_110 ) ) ;
if ( ! V_5 -> V_10 ) {
F_34 ( V_5 -> V_100 ,
L_25 ) ;
V_84 = - V_117 ;
goto V_121;
}
}
F_39 ( & V_5 -> V_122 ) ;
F_40 ( V_100 , V_5 ) ;
F_41 ( V_5 -> V_100 , L_26 ) ;
return 0 ;
V_121:
F_42 ( V_110 -> V_118 , F_37 ( V_110 ) ) ;
V_120:
F_43 ( V_5 -> V_6 ) ;
V_119:
V_110 = F_35 ( V_100 , V_116 , 0 ) ;
F_42 ( V_110 -> V_118 , F_37 ( V_110 ) ) ;
V_115:
F_44 ( V_5 ) ;
return V_84 ;
}
static int F_45 ( struct V_99 * V_100 )
{
struct V_1 * V_5 = F_27 ( V_100 ) ;
struct V_109 * V_110 ;
V_110 = F_35 ( V_100 , V_116 , 0 ) ;
F_43 ( ( void * ) V_5 -> V_6 ) ;
F_42 ( V_110 -> V_118 , F_37 ( V_110 ) ) ;
if ( V_5 -> V_19 -> V_36 != V_65 ) {
V_110 = F_35 ( V_100 , V_116 , 1 ) ;
F_43 ( ( void * ) V_5 -> V_10 ) ;
F_42 ( V_110 -> V_118 , F_37 ( V_110 ) ) ;
}
F_44 ( V_5 ) ;
return 0 ;
}
