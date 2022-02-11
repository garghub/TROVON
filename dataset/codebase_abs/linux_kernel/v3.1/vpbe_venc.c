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
F_5 ( V_3 , V_13 , 0x210 ) ;
break;
case 2 :
F_5 ( V_3 , V_13 , 0x543 ) ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static void F_11 ( struct V_2 * V_3 , int V_15 )
{
F_10 ( V_12 , 2 , V_3 , L_3 ) ;
if ( V_15 ) {
F_5 ( V_3 , V_16 , 0 ) ;
F_5 ( V_3 , V_17 , 0 ) ;
F_5 ( V_3 , V_18 , 0 ) ;
F_5 ( V_3 , V_19 , 0 ) ;
F_5 ( V_3 , V_20 , 0 ) ;
F_5 ( V_3 , V_21 , 0 ) ;
F_5 ( V_3 , V_22 , 0 ) ;
F_5 ( V_3 , V_23 , 0 ) ;
F_5 ( V_3 , V_24 , 0 ) ;
F_5 ( V_3 , V_25 , 0 ) ;
F_5 ( V_3 , V_26 , 0 ) ;
F_5 ( V_3 , V_27 , 0 ) ;
F_5 ( V_3 , V_13 , 0 ) ;
} else {
F_5 ( V_3 , V_16 , 0 ) ;
F_5 ( V_3 , V_28 , 0x141 ) ;
F_5 ( V_3 , V_29 , 0 ) ;
F_5 ( V_3 , V_30 , 0 ) ;
F_5 ( V_3 , V_31 , 0x0000057C ) ;
F_5 ( V_3 , V_18 , 0 ) ;
F_5 ( V_3 , V_32 , 0x100 ) ;
F_5 ( V_3 , V_19 , 0 ) ;
F_5 ( V_3 , V_22 , 0 ) ;
F_5 ( V_3 , V_20 , 0 ) ;
F_5 ( V_3 , V_21 , 0 ) ;
F_5 ( V_3 , V_23 , 0 ) ;
F_5 ( V_3 , V_26 , 0 ) ;
F_5 ( V_3 , V_24 , 0 ) ;
F_5 ( V_3 , V_25 , 0 ) ;
F_5 ( V_3 , V_33 , 0 ) ;
F_5 ( V_3 , V_34 , 0 ) ;
F_5 ( V_3 , V_27 , 0 ) ;
F_5 ( V_3 , V_35 , 0 ) ;
F_5 ( V_3 , V_36 , 1 ) ;
F_5 ( V_3 , V_37 , 2 ) ;
}
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_38 * V_39 = V_5 -> V_39 ;
F_10 ( V_12 , 2 , V_3 , L_4 ) ;
F_13 ( V_40 , 1 ) ;
if ( V_39 -> V_41 ( V_42 , V_43 ) < 0 )
return - V_14 ;
F_11 ( V_3 , 0 ) ;
F_7 ( V_3 , V_28 , 0 , 1 << 1 ) ;
F_5 ( V_3 , V_27 , 0x1 ) ;
F_7 ( V_3 , V_44 , 0 , V_45 ) ;
F_7 ( V_3 , V_44 , 0 , V_46 ) ;
F_5 ( V_3 , V_16 , 0 ) ;
F_7 ( V_3 , V_16 , ( 1 << V_47 ) ,
V_48 ) ;
F_7 ( V_3 , V_16 , ( 0 << V_49 ) , V_49 ) ;
F_7 ( V_3 , V_16 , ( 0 << V_50 ) ,
V_51 ) ;
F_5 ( V_3 , V_52 , 0x0 ) ;
F_7 ( V_3 , V_16 , V_53 , V_53 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_10 ( V_12 , 2 , V_3 , L_5 ) ;
F_13 ( V_40 , 1 ) ;
if ( V_5 -> V_39 -> V_41 ( V_42 , V_54 ) < 0 )
return - V_14 ;
F_11 ( V_3 , 0 ) ;
F_7 ( V_3 , V_28 , 0 , 1 << 1 ) ;
F_5 ( V_3 , V_27 , 0x1 ) ;
F_7 ( V_3 , V_29 , 1 << V_55 ,
V_56 ) ;
F_5 ( V_3 , V_16 , 0 ) ;
F_7 ( V_3 , V_16 ,
( 1 << V_47 ) ,
V_48 ) ;
F_7 ( V_3 , V_16 ,
( 0 << V_49 ) , V_49 ) ;
F_7 ( V_3 , V_16 ,
( 1 << V_50 ) ,
V_51 ) ;
F_5 ( V_3 , V_52 , 0x0 ) ;
F_7 ( V_3 , V_16 , V_53 , V_53 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_38 * V_39 = V_5 -> V_39 ;
F_10 ( V_12 , 2 , V_3 , L_6 ) ;
if ( V_39 -> V_41 ( V_57 , V_58 ) < 0 )
return - V_14 ;
F_11 ( V_3 , 0 ) ;
F_5 ( V_3 , V_36 , 0 ) ;
F_5 ( V_3 , V_37 , 1 ) ;
F_7 ( V_3 , V_44 , V_45 ,
V_45 ) ;
F_7 ( V_3 , V_44 , V_46 ,
V_46 ) ;
F_5 ( V_3 , V_16 , 0 ) ;
F_7 ( V_3 , V_16 , ( 1 << V_47 ) ,
V_48 ) ;
F_7 ( V_3 , V_16 , V_59 , V_59 ) ;
F_7 ( V_3 , V_16 , ( V_60 << V_50 ) ,
V_51 ) ;
F_7 ( V_3 , V_16 , V_61 <<
V_62 , V_63 ) ;
F_7 ( V_3 , V_16 , V_53 , V_53 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_38 * V_39 = V_5 -> V_39 ;
F_10 ( V_12 , 2 , V_3 , L_7 ) ;
if ( V_39 -> V_41 ( V_57 , V_64 ) < 0 )
return - V_14 ;
F_11 ( V_3 , 0 ) ;
F_5 ( V_3 , V_36 , 0 ) ;
F_5 ( V_3 , V_37 , 1 ) ;
F_7 ( V_3 , V_44 , V_45 ,
V_45 ) ;
F_7 ( V_3 , V_44 , V_46 ,
V_46 ) ;
F_5 ( V_3 , V_16 , 0 ) ;
F_7 ( V_3 , V_16 , ( 1 << V_47 ) ,
V_48 ) ;
F_7 ( V_3 , V_16 , V_59 , V_59 ) ;
F_7 ( V_3 , V_16 , ( V_65 << V_50 ) ,
V_51 ) ;
F_7 ( V_3 , V_16 , V_61 <<
V_62 , V_63 ) ;
F_7 ( V_3 , V_16 , V_53 , V_53 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 , T_2 V_66 )
{
F_10 ( V_12 , 1 , V_3 , L_8 ) ;
if ( V_66 & V_43 )
return F_12 ( V_3 ) ;
else if ( V_66 & V_54 )
return F_14 ( V_3 ) ;
return - V_14 ;
}
static int F_18 ( struct V_2 * V_3 ,
struct V_67 * V_68 )
{
F_10 ( V_12 , 1 , V_3 , L_9 ) ;
if ( V_68 -> V_69 == V_64 )
return F_16 ( V_3 ) ;
else if ( V_68 -> V_69 == V_58 )
return F_15 ( V_3 ) ;
return - V_14 ;
}
static int F_19 ( struct V_2 * V_3 , T_1 V_70 , T_1 V_71 ,
T_1 V_72 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_73 ;
F_10 ( V_12 , 1 , V_3 , L_10 ) ;
V_73 = F_9 ( V_3 , V_71 ) ;
if ( ! V_73 )
V_5 -> V_71 = V_71 ;
return V_73 ;
}
static long F_20 ( struct V_2 * V_3 ,
unsigned int V_74 ,
void * V_75 )
{
T_1 V_7 ;
switch ( V_74 ) {
case V_76 :
V_7 = F_3 ( V_3 , V_77 ) ;
* ( ( int * ) V_75 ) = ( ( V_7 & V_78 ) ==
V_78 ) ;
break;
default:
F_21 ( V_3 , L_11 ) ;
break;
}
return 0 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_73 ;
V_5 -> V_71 = 0 ;
V_5 -> V_79 = V_43 ;
V_73 = F_19 ( V_3 , 0 , V_5 -> V_71 , 0 ) ;
if ( V_73 < 0 ) {
F_21 ( V_3 , L_12 ) ;
return - V_14 ;
}
V_73 = F_17 ( V_3 , V_5 -> V_79 ) ;
if ( V_73 < 0 ) {
F_21 ( V_3 , L_13 ) ;
return - V_14 ;
}
return V_73 ;
}
static int F_23 ( struct V_80 * V_81 , void * V_82 )
{
struct V_83 * V_84 = F_24 ( V_81 ) ;
struct V_1 * * V_5 = V_82 ;
if ( strcmp ( V_85 , V_84 -> V_86 ) == 0 )
* V_5 = F_25 ( V_84 ) ;
return 0 ;
}
struct V_2 * F_26 ( struct V_87 * V_88 ,
const char * V_89 )
{
struct V_1 * V_5 ;
int V_90 ;
V_90 = F_27 ( & V_91 , NULL , & V_5 ,
F_23 ) ;
if ( V_5 == NULL )
return NULL ;
F_28 ( & V_5 -> V_3 , & V_92 ) ;
strcpy ( V_5 -> V_3 . V_86 , V_89 ) ;
if ( F_29 ( V_88 , & V_5 -> V_3 ) < 0 ) {
F_21 ( V_88 ,
L_14 ) ;
return NULL ;
}
if ( F_22 ( & V_5 -> V_3 ) ) {
F_21 ( V_88 ,
L_15 ) ;
return NULL ;
}
return & V_5 -> V_3 ;
}
static int F_30 ( struct V_83 * V_84 )
{
struct V_1 * V_5 ;
struct V_93 * V_94 ;
int V_73 ;
V_5 = F_31 ( sizeof( struct V_1 ) , V_95 ) ;
if ( V_5 == NULL )
return - V_96 ;
V_5 -> V_84 = & V_84 -> V_81 ;
V_5 -> V_39 = V_84 -> V_81 . V_97 ;
if ( NULL == V_5 -> V_39 ) {
F_32 ( V_5 -> V_84 , L_16
L_17 ) ;
V_73 = - V_98 ;
goto V_99;
}
V_94 = F_33 ( V_84 , V_100 , 0 ) ;
if ( ! V_94 ) {
F_32 ( V_5 -> V_84 ,
L_18 ) ;
V_73 = - V_101 ;
goto V_99;
}
if ( ! F_34 ( V_94 -> V_102 , F_35 ( V_94 ) , L_19 ) ) {
F_32 ( V_5 -> V_84 , L_20 ) ;
V_73 = - V_101 ;
goto V_99;
}
V_5 -> V_6 = F_36 ( V_94 -> V_102 , F_35 ( V_94 ) ) ;
if ( ! V_5 -> V_6 ) {
F_32 ( V_5 -> V_84 , L_21 ) ;
V_73 = - V_101 ;
goto V_103;
}
F_37 ( & V_5 -> V_104 ) ;
F_38 ( V_84 , V_5 ) ;
F_39 ( V_5 -> V_84 , L_22 ) ;
return 0 ;
V_103:
V_94 = F_33 ( V_84 , V_100 , 0 ) ;
F_40 ( V_94 -> V_102 , F_35 ( V_94 ) ) ;
V_99:
F_41 ( V_5 ) ;
return V_73 ;
}
static int F_42 ( struct V_83 * V_84 )
{
struct V_1 * V_5 = F_25 ( V_84 ) ;
struct V_93 * V_94 ;
V_94 = F_33 ( V_84 , V_100 , 0 ) ;
F_43 ( ( void * ) V_5 -> V_6 ) ;
F_40 ( V_94 -> V_102 , F_35 ( V_94 ) ) ;
F_41 ( V_5 ) ;
return 0 ;
}
static int F_44 ( void )
{
if ( F_45 ( & V_105 ) ) {
F_46 ( V_106 L_23 ) ;
return - V_101 ;
}
return 0 ;
}
static void F_47 ( void )
{
F_48 ( & V_105 ) ;
return;
}
