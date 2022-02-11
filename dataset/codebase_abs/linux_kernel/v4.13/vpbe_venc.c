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
F_10 ( V_12 , 2 , V_3 , L_4 ) ;
if ( V_17 ) {
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
F_5 ( V_3 , V_28 , 0 ) ;
F_5 ( V_3 , V_29 , 0 ) ;
F_5 ( V_3 , V_13 , 0 ) ;
} else {
F_5 ( V_3 , V_18 , 0 ) ;
F_5 ( V_3 , V_30 , 0x141 ) ;
F_5 ( V_3 , V_31 , 0 ) ;
F_5 ( V_3 , V_32 , 0 ) ;
F_5 ( V_3 , V_33 , 0x0000057C ) ;
F_5 ( V_3 , V_20 , 0 ) ;
if ( V_5 -> V_34 != V_35 )
F_5 ( V_3 , V_36 , 0x100 ) ;
F_5 ( V_3 , V_21 , 0 ) ;
F_5 ( V_3 , V_24 , 0 ) ;
F_5 ( V_3 , V_22 , 0 ) ;
F_5 ( V_3 , V_23 , 0 ) ;
F_5 ( V_3 , V_25 , 0 ) ;
F_5 ( V_3 , V_28 , 0 ) ;
F_5 ( V_3 , V_26 , 0 ) ;
F_5 ( V_3 , V_27 , 0 ) ;
F_5 ( V_3 , V_37 , 0 ) ;
F_5 ( V_3 , V_38 , 0 ) ;
F_5 ( V_3 , V_29 , 0 ) ;
F_5 ( V_3 , V_39 , 0 ) ;
F_5 ( V_3 , V_40 , 1 ) ;
F_5 ( V_3 , V_41 , 2 ) ;
}
}
static void
F_12 ( int V_34 ,
enum V_42 type ,
unsigned int V_43 )
{
if ( V_34 == V_44 )
return;
if ( V_34 == V_45 && ( type == V_46 || ( type ==
V_47 && V_43 <= 27000000 ) ) ) {
F_13 ( V_48 , 1 ) ;
F_13 ( V_49 , 1 ) ;
return;
}
if ( V_34 == V_35 && type == V_46 )
F_13 ( V_48 , 0 ) ;
}
static int F_14 ( struct V_2 * V_3 )
{
T_1 V_7 ;
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_50 * V_51 = V_5 -> V_51 ;
F_10 ( V_12 , 2 , V_3 , L_5 ) ;
F_13 ( V_48 , 1 ) ;
if ( V_51 -> V_52 ( V_46 , V_53 ) < 0 )
return - V_16 ;
F_12 ( V_5 -> V_34 , V_46 , V_53 ) ;
F_11 ( V_3 , 0 ) ;
if ( V_5 -> V_34 == V_35 ) {
F_5 ( V_3 , V_54 , 0x01 ) ;
F_5 ( V_3 , V_30 , 0 ) ;
V_7 = F_8 ( V_3 , V_55 ) ;
} else if ( V_5 -> V_34 == V_45 ) {
F_5 ( V_3 , V_54 , 0x01 ) ;
F_5 ( V_3 , V_30 , 0 ) ;
F_8 ( V_3 , V_56 ) ;
} else {
F_7 ( V_3 , V_30 , 0 , 1 << 1 ) ;
F_5 ( V_3 , V_29 , 0x1 ) ;
F_7 ( V_3 , V_57 , 0 , V_58 ) ;
F_7 ( V_3 , V_57 , 0 , V_59 ) ;
}
F_5 ( V_3 , V_18 , 0 ) ;
F_7 ( V_3 , V_18 , ( 1 << V_60 ) ,
V_61 ) ;
F_7 ( V_3 , V_18 , ( 0 << V_62 ) , V_62 ) ;
F_7 ( V_3 , V_18 , ( 0 << V_63 ) ,
V_64 ) ;
F_5 ( V_3 , V_65 , 0x0 ) ;
F_7 ( V_3 , V_18 , V_66 , V_66 ) ;
return 0 ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
F_10 ( V_12 , 2 , V_3 , L_6 ) ;
F_13 ( V_48 , 1 ) ;
if ( V_5 -> V_51 -> V_52 ( V_46 , V_67 ) < 0 )
return - V_16 ;
F_12 ( V_5 -> V_34 , V_46 , V_67 ) ;
F_11 ( V_3 , 0 ) ;
if ( V_5 -> V_34 == V_35 ) {
F_5 ( V_3 , V_54 , 0x1 ) ;
F_5 ( V_3 , V_30 , 0 ) ;
F_8 ( V_3 , V_55 ) ;
} else if ( V_5 -> V_34 == V_45 ) {
F_5 ( V_3 , V_54 , 0x1 ) ;
F_5 ( V_3 , V_30 , 0 ) ;
F_8 ( V_3 , V_56 ) ;
} else {
F_7 ( V_3 , V_30 , 0 , 1 << 1 ) ;
F_5 ( V_3 , V_29 , 0x1 ) ;
}
F_7 ( V_3 , V_31 , 1 << V_68 ,
V_69 ) ;
F_5 ( V_3 , V_18 , 0 ) ;
F_7 ( V_3 , V_18 ,
( 1 << V_60 ) ,
V_61 ) ;
F_7 ( V_3 , V_18 ,
( 0 << V_62 ) , V_62 ) ;
F_7 ( V_3 , V_18 ,
( 1 << V_63 ) ,
V_64 ) ;
F_5 ( V_3 , V_65 , 0x0 ) ;
F_7 ( V_3 , V_18 , V_66 , V_66 ) ;
return 0 ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_50 * V_51 = V_5 -> V_51 ;
F_10 ( V_12 , 2 , V_3 , L_7 ) ;
if ( V_5 -> V_34 != V_44 &&
V_5 -> V_34 != V_45 )
return - V_16 ;
if ( V_51 -> V_52 ( V_47 , 27000000 ) < 0 )
return - V_16 ;
F_12 ( V_5 -> V_34 , V_47 , 27000000 ) ;
F_11 ( V_3 , 0 ) ;
if ( V_5 -> V_34 == V_45 )
F_8 ( V_3 , V_70 ) ;
F_5 ( V_3 , V_40 , 0 ) ;
F_5 ( V_3 , V_41 , 1 ) ;
if ( V_5 -> V_34 == V_44 ) {
F_7 ( V_3 , V_57 , V_58 ,
V_58 ) ;
F_7 ( V_3 , V_57 , V_59 ,
V_59 ) ;
}
F_5 ( V_3 , V_18 , 0 ) ;
F_7 ( V_3 , V_18 , ( 1 << V_60 ) ,
V_61 ) ;
F_7 ( V_3 , V_18 , V_71 , V_71 ) ;
F_7 ( V_3 , V_18 , ( V_72 << V_63 ) ,
V_64 ) ;
F_7 ( V_3 , V_18 , V_73 <<
V_74 , V_75 ) ;
F_7 ( V_3 , V_18 , V_66 , V_66 ) ;
return 0 ;
}
static int F_17 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_50 * V_51 = V_5 -> V_51 ;
F_10 ( V_12 , 2 , V_3 , L_8 ) ;
if ( V_5 -> V_34 != V_44 &&
V_5 -> V_34 != V_45 )
return - V_16 ;
if ( V_51 -> V_52 ( V_47 , 27000000 ) < 0 )
return - V_16 ;
F_12 ( V_5 -> V_34 , V_47 , 27000000 ) ;
F_11 ( V_3 , 0 ) ;
if ( V_5 -> V_34 == V_45 )
F_8 ( V_3 , V_70 ) ;
F_5 ( V_3 , V_40 , 0 ) ;
F_5 ( V_3 , V_41 , 1 ) ;
if ( V_5 -> V_34 == V_44 ) {
F_7 ( V_3 , V_57 , V_58 ,
V_58 ) ;
F_7 ( V_3 , V_57 , V_59 ,
V_59 ) ;
}
F_5 ( V_3 , V_18 , 0 ) ;
F_7 ( V_3 , V_18 , ( 1 << V_60 ) ,
V_61 ) ;
F_7 ( V_3 , V_18 , V_71 , V_71 ) ;
F_7 ( V_3 , V_18 , ( V_76 << V_63 ) ,
V_64 ) ;
F_7 ( V_3 , V_18 , V_73 <<
V_74 , V_75 ) ;
F_7 ( V_3 , V_18 , V_66 , V_66 ) ;
return 0 ;
}
static int F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_50 * V_51 = V_5 -> V_51 ;
if ( V_51 -> V_52 ( V_47 , 74250000 ) < 0 )
return - V_16 ;
F_12 ( V_5 -> V_34 , V_47 , 74250000 ) ;
F_11 ( V_3 , 0 ) ;
F_5 ( V_3 , V_40 , 0 ) ;
F_5 ( V_3 , V_41 , 1 ) ;
F_5 ( V_3 , V_18 , 0 ) ;
F_7 ( V_3 , V_18 , ( 1 << V_60 ) ,
V_61 ) ;
F_7 ( V_3 , V_18 , V_71 , V_71 ) ;
F_7 ( V_3 , V_18 , ( V_77 << V_63 ) ,
V_64 ) ;
F_7 ( V_3 , V_18 , V_66 , V_66 ) ;
F_5 ( V_3 , V_78 , 0 ) ;
return 0 ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
struct V_50 * V_51 = V_5 -> V_51 ;
if ( V_51 -> V_52 ( V_47 , 74250000 ) < 0 )
return - V_16 ;
F_12 ( V_5 -> V_34 , V_47 , 74250000 ) ;
F_11 ( V_3 , 0 ) ;
F_5 ( V_3 , V_40 , 0 ) ;
F_5 ( V_3 , V_41 , 1 ) ;
F_5 ( V_3 , V_18 , 0 ) ;
F_7 ( V_3 , V_18 , ( 1 << V_60 ) ,
V_61 ) ;
F_7 ( V_3 , V_18 , V_71 , V_71 ) ;
F_7 ( V_3 , V_18 , ( V_79 << V_63 ) ,
V_64 ) ;
F_7 ( V_3 , V_18 , V_66 , V_66 ) ;
F_5 ( V_3 , V_78 , 0 ) ;
return 0 ;
}
static int F_20 ( struct V_2 * V_3 , T_2 V_80 )
{
F_10 ( V_12 , 1 , V_3 , L_9 ) ;
if ( V_80 & V_53 )
return F_14 ( V_3 ) ;
else if ( V_80 & V_67 )
return F_15 ( V_3 ) ;
return - V_16 ;
}
static int F_21 ( struct V_2 * V_3 ,
struct V_81 * V_82 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
T_1 V_83 = V_82 -> V_84 . V_83 ;
int V_85 ;
F_10 ( V_12 , 1 , V_3 , L_10 ) ;
if ( V_83 == 576 )
return F_17 ( V_3 ) ;
else if ( V_83 == 480 )
return F_16 ( V_3 ) ;
else if ( ( V_83 == 720 ) &&
( V_5 -> V_34 == V_45 ) ) {
V_85 = F_18 ( V_3 ) ;
F_8 ( V_3 , V_70 ) ;
return V_85 ;
} else if ( ( V_83 == 1080 ) &&
( V_5 -> V_34 == V_45 ) ) {
V_85 = F_19 ( V_3 ) ;
F_8 ( V_3 , V_70 ) ;
return V_85 ;
}
return - V_16 ;
}
static int F_22 ( struct V_2 * V_3 , T_1 V_86 , T_1 V_87 ,
T_1 V_88 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_85 ;
F_10 ( V_12 , 1 , V_3 , L_11 ) ;
V_85 = F_9 ( V_3 , V_87 ) ;
if ( ! V_85 )
V_5 -> V_87 = V_87 ;
return V_85 ;
}
static long F_23 ( struct V_2 * V_3 ,
unsigned int V_89 ,
void * V_90 )
{
T_1 V_7 ;
switch ( V_89 ) {
case V_91 :
V_7 = F_3 ( V_3 , V_92 ) ;
* ( ( int * ) V_90 ) = ( ( V_7 & V_93 ) ==
V_93 ) ;
break;
default:
F_24 ( V_3 , L_12 ) ;
break;
}
return 0 ;
}
static int F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_5 = F_1 ( V_3 ) ;
int V_85 ;
V_5 -> V_87 = 0 ;
V_5 -> V_94 = V_53 ;
V_85 = F_22 ( V_3 , 0 , V_5 -> V_87 , 0 ) ;
if ( V_85 < 0 ) {
F_24 ( V_3 , L_13 ) ;
return - V_16 ;
}
V_85 = F_20 ( V_3 , V_5 -> V_94 ) ;
if ( V_85 < 0 ) {
F_24 ( V_3 , L_14 ) ;
return - V_16 ;
}
return V_85 ;
}
static int F_26 ( struct V_95 * V_96 , void * V_97 )
{
struct V_98 * V_99 = F_27 ( V_96 ) ;
struct V_1 * * V_5 = V_97 ;
if ( strstr ( V_99 -> V_100 , L_15 ) != NULL )
* V_5 = F_28 ( V_99 ) ;
return 0 ;
}
struct V_2 * F_29 ( struct V_101 * V_102 ,
const char * V_103 )
{
struct V_1 * V_5 ;
int V_104 ;
V_104 = F_30 ( & V_105 , NULL , & V_5 ,
F_26 ) ;
if ( V_5 == NULL )
return NULL ;
F_31 ( & V_5 -> V_3 , & V_106 ) ;
strcpy ( V_5 -> V_3 . V_100 , V_103 ) ;
if ( F_32 ( V_102 , & V_5 -> V_3 ) < 0 ) {
F_24 ( V_102 ,
L_16 ) ;
return NULL ;
}
if ( F_25 ( & V_5 -> V_3 ) ) {
F_24 ( V_102 ,
L_17 ) ;
return NULL ;
}
return & V_5 -> V_3 ;
}
static int F_33 ( struct V_98 * V_99 )
{
const struct V_107 * V_108 ;
struct V_1 * V_5 ;
struct V_109 * V_110 ;
if ( ! V_99 -> V_96 . V_111 ) {
F_34 ( & V_99 -> V_96 , L_18 ) ;
return - V_16 ;
}
V_108 = F_35 ( V_99 ) ;
if ( ! V_108 )
return - V_16 ;
V_5 = F_36 ( & V_99 -> V_96 , sizeof( struct V_1 ) , V_112 ) ;
if ( V_5 == NULL )
return - V_113 ;
V_5 -> V_34 = V_108 -> V_114 ;
V_5 -> V_99 = & V_99 -> V_96 ;
V_5 -> V_51 = V_99 -> V_96 . V_111 ;
V_110 = F_37 ( V_99 , V_115 , 0 ) ;
V_5 -> V_6 = F_38 ( & V_99 -> V_96 , V_110 ) ;
if ( F_39 ( V_5 -> V_6 ) )
return F_40 ( V_5 -> V_6 ) ;
if ( V_5 -> V_34 != V_44 ) {
V_110 = F_37 ( V_99 , V_115 , 1 ) ;
V_5 -> V_10 = F_38 ( & V_99 -> V_96 , V_110 ) ;
if ( F_39 ( V_5 -> V_10 ) )
return F_40 ( V_5 -> V_10 ) ;
}
F_41 ( & V_5 -> V_116 ) ;
F_42 ( V_99 , V_5 ) ;
F_43 ( V_5 -> V_99 , L_19 ) ;
return 0 ;
}
static int F_44 ( struct V_98 * V_99 )
{
return 0 ;
}
