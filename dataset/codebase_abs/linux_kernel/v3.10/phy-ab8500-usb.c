static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static void F_3 ( struct V_1 * V_5 )
{
F_4 ( V_5 -> V_6 ,
V_7 ,
V_8 ,
V_9 ) ;
F_5 ( V_10 ) ;
F_4 ( V_5 -> V_6 ,
V_7 ,
V_8 ,
( V_9
| V_11 ) ) ;
F_5 ( V_12 ) ;
F_4 ( V_5 -> V_6 ,
V_7 ,
V_8 ,
0 ) ;
}
static void F_6 ( struct V_1 * V_5 )
{
int V_13 , V_14 ;
V_13 = F_7 ( V_5 -> V_15 ) ;
if ( V_13 )
F_8 ( V_5 -> V_6 , L_1 ) ;
if ( ! F_9 ( V_5 -> V_16 ) ) {
V_5 -> V_17 = F_10 ( V_5 -> V_18 ) ;
if ( V_5 -> V_17 < 0 )
F_8 ( V_5 -> V_6 , L_2 ) ;
V_13 = F_11 ( V_5 -> V_18 , 1300000 , 1350000 ) ;
if ( V_13 < 0 )
F_8 ( V_5 -> V_6 , L_3 ,
V_13 ) ;
V_13 = F_12 ( V_5 -> V_18 , 28000 ) ;
if ( V_13 < 0 )
F_8 ( V_5 -> V_6 , L_4 ,
V_13 ) ;
}
V_13 = F_7 ( V_5 -> V_18 ) ;
if ( V_13 )
F_8 ( V_5 -> V_6 , L_5 ) ;
if ( ! F_9 ( V_5 -> V_16 ) ) {
V_14 = F_10 ( V_5 -> V_18 ) ;
if ( ( V_14 != 1300000 ) && ( V_14 != 1350000 ) )
F_8 ( V_5 -> V_6 , L_6 ,
V_14 ) ;
}
V_13 = F_7 ( V_5 -> V_19 ) ;
if ( V_13 )
F_8 ( V_5 -> V_6 , L_7 ) ;
}
static void F_13 ( struct V_1 * V_5 )
{
int V_13 ;
F_14 ( V_5 -> V_19 ) ;
F_14 ( V_5 -> V_18 ) ;
if ( ! F_9 ( V_5 -> V_16 ) ) {
if ( V_5 -> V_17 > 0 ) {
V_13 = F_11 ( V_5 -> V_18 ,
V_5 -> V_17 , V_5 -> V_17 ) ;
if ( V_13 < 0 )
F_8 ( V_5 -> V_6 , L_8 ,
V_5 -> V_17 , V_13 ) ;
}
V_13 = F_12 ( V_5 -> V_18 , 0 ) ;
if ( V_13 < 0 )
F_8 ( V_5 -> V_6 , L_4 ,
V_13 ) ;
}
F_14 ( V_5 -> V_15 ) ;
}
static void F_15 ( struct V_1 * V_5 , T_1 V_20 )
{
if ( F_16 ( V_5 -> V_16 ) ) {
F_17 ( V_5 -> V_6 ,
V_21 , V_22 ,
V_20 , V_20 ) ;
F_5 ( V_23 ) ;
}
}
static void F_18 ( struct V_1 * V_5 , bool V_24 )
{
T_1 V_20 ;
V_20 = V_24 ? V_25 :
V_26 ;
V_5 -> V_27 = F_19 ( V_5 -> V_6 , V_28 ) ;
if ( F_20 ( V_5 -> V_27 ) )
F_8 ( V_5 -> V_6 , L_9 ) ;
F_6 ( V_5 ) ;
F_17 ( V_5 -> V_6 ,
V_21 , V_22 ,
V_20 , V_20 ) ;
}
static void F_21 ( struct V_1 * V_5 , bool V_24 )
{
T_1 V_20 ;
V_20 = V_24 ? V_25 :
V_26 ;
F_15 ( V_5 , V_20 ) ;
F_17 ( V_5 -> V_6 ,
V_21 , V_22 ,
V_20 , 0 ) ;
F_3 ( V_5 ) ;
F_13 ( V_5 ) ;
if ( ! F_20 ( V_5 -> V_27 ) ) {
V_5 -> V_29 = F_22 ( V_5 -> V_27 ,
V_30 ) ;
if ( F_20 ( V_5 -> V_29 ) )
F_23 ( V_5 -> V_6 , L_10 ) ;
else if ( F_24 ( V_5 -> V_27 , V_5 -> V_29 ) )
F_8 ( V_5 -> V_6 , L_11 ) ;
F_25 ( V_5 -> V_27 ) ;
}
}
static int F_26 ( struct V_1 * V_5 ,
enum V_31 V_32 )
{
enum V_33 V_34 = 0 ;
F_23 ( V_5 -> V_6 , L_12 , V_32 ) ;
if ( V_5 -> V_35 == V_36 &&
( V_32 == V_37 ) )
return 0 ;
V_5 -> V_35 = V_32 ;
switch ( V_32 ) {
case V_38 :
V_34 = V_39 ;
case V_40 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
V_5 -> V_45 = V_46 ;
V_5 -> V_4 . V_47 -> V_48 = false ;
V_5 -> V_49 = 0 ;
if ( V_34 != V_39 )
V_34 = V_50 ;
V_5 -> V_4 . V_51 = V_52 ;
break;
case V_53 :
V_34 = V_54 ;
case V_37 :
case V_55 :
case V_56 :
case V_57 :
if ( V_5 -> V_45 == V_46 ) {
V_5 -> V_45 = V_58 ;
F_27 ( V_5 ) ;
F_28 ( & V_5 -> V_4 . V_59 ,
V_60 , & V_5 -> V_49 ) ;
}
if ( V_34 != V_54 )
V_34 = V_61 ;
break;
case V_36 :
case V_62 :
V_34 = V_63 ;
case V_64 :
if ( V_5 -> V_45 == V_46 ) {
V_5 -> V_45 = V_65 ;
F_29 ( V_5 ) ;
F_28 ( & V_5 -> V_4 . V_59 ,
V_60 , & V_5 -> V_49 ) ;
}
V_5 -> V_4 . V_47 -> V_48 = true ;
if ( V_34 != V_63 )
V_34 = V_66 ;
F_28 ( & V_5 -> V_4 . V_59 ,
V_34 , & V_5 -> V_49 ) ;
break;
case V_67 :
V_5 -> V_45 = V_68 ;
V_34 = V_69 ;
F_28 ( & V_5 -> V_4 . V_59 ,
V_34 , & V_5 -> V_49 ) ;
break;
default:
break;
}
return 0 ;
}
static int F_30 ( struct V_1 * V_5 ,
enum V_70 V_32 )
{
enum V_33 V_34 = 0 ;
F_23 ( V_5 -> V_6 , L_13 , V_32 ) ;
if ( V_5 -> V_35 == V_71 &&
( V_32 == V_72 ||
V_32 == V_73 ) )
return 0 ;
if ( V_5 -> V_35 == V_74 &&
V_32 == V_73 )
return 0 ;
V_5 -> V_35 = V_32 ;
switch ( V_32 ) {
case V_75 :
V_34 = V_39 ;
case V_76 :
case V_77 :
V_5 -> V_45 = V_46 ;
V_5 -> V_4 . V_47 -> V_48 = false ;
V_5 -> V_49 = 0 ;
if ( V_34 != V_39 )
V_34 = V_50 ;
V_5 -> V_4 . V_51 = V_52 ;
break;
case V_78 :
case V_79 :
case V_80 :
V_34 = V_54 ;
case V_73 :
case V_72 :
case V_81 :
case V_82 :
case V_83 :
case V_84 :
if ( V_5 -> V_45 == V_46 ) {
V_5 -> V_45 = V_58 ;
F_27 ( V_5 ) ;
F_28 ( & V_5 -> V_4 . V_59 ,
V_60 , & V_5 -> V_49 ) ;
}
if ( V_34 != V_54 )
V_34 = V_61 ;
break;
case V_74 :
V_34 = V_63 ;
case V_71 :
if ( V_5 -> V_45 == V_46 ) {
V_5 -> V_45 = V_65 ;
F_29 ( V_5 ) ;
F_28 ( & V_5 -> V_4 . V_59 ,
V_60 , & V_5 -> V_49 ) ;
}
V_5 -> V_4 . V_47 -> V_48 = true ;
if ( V_34 != V_63 )
V_34 = V_66 ;
F_28 ( & V_5 -> V_4 . V_59 ,
V_34 , & V_5 -> V_49 ) ;
break;
case V_85 :
V_5 -> V_45 = V_68 ;
V_34 = V_69 ;
F_28 ( & V_5 -> V_4 . V_59 ,
V_34 , & V_5 -> V_49 ) ;
break;
case V_86 :
break;
}
return 0 ;
}
static int F_31 ( struct V_1 * V_5 )
{
T_1 V_87 ;
int V_13 = 0 ;
if ( F_32 ( V_5 -> V_16 ) ) {
enum V_70 V_32 ;
F_33 ( V_5 -> V_6 ,
V_21 , V_88 , & V_87 ) ;
V_32 = ( V_87 >> 3 ) & 0x0F ;
V_13 = F_30 ( V_5 , V_32 ) ;
} else if ( F_34 ( V_5 -> V_16 ) ) {
enum V_31 V_32 ;
F_33 ( V_5 -> V_6 ,
V_21 , V_89 , & V_87 ) ;
V_32 = ( V_87 >> 3 ) & 0x1F ;
V_13 = F_26 ( V_5 , V_32 ) ;
}
return V_13 ;
}
static T_2 F_35 ( int V_90 , void * V_91 )
{
struct V_1 * V_5 = (struct V_1 * ) V_91 ;
enum V_92 V_34 = V_50 ;
if ( V_5 -> V_45 == V_65 ) {
V_5 -> V_4 . V_47 -> V_48 = false ;
V_5 -> V_49 = 0 ;
F_28 ( & V_5 -> V_4 . V_59 ,
V_34 , & V_5 -> V_49 ) ;
F_36 ( V_5 ) ;
V_5 -> V_45 = V_46 ;
}
if ( V_5 -> V_45 == V_58 ) {
F_28 ( & V_5 -> V_4 . V_59 ,
V_34 , & V_5 -> V_49 ) ;
F_37 ( V_5 ) ;
F_28 ( & V_5 -> V_4 . V_59 ,
V_93 , & V_5 -> V_49 ) ;
V_5 -> V_45 = V_46 ;
V_5 -> V_4 . V_47 -> V_48 = false ;
V_5 -> V_49 = 0 ;
}
if ( F_16 ( V_5 -> V_16 ) ) {
if ( V_5 -> V_45 == V_68 ) {
F_15 ( V_5 ,
V_26 ) ;
F_17 ( V_5 -> V_6 ,
V_21 , V_22 ,
V_26 , 0 ) ;
}
}
return V_94 ;
}
static T_2 F_38 ( int V_90 , void * V_91 )
{
struct V_1 * V_5 = (struct V_1 * ) V_91 ;
F_31 ( V_5 ) ;
return V_94 ;
}
static void F_39 ( struct V_95 * V_96 )
{
struct V_1 * V_5 = F_2 ( V_96 , struct V_1 ,
V_97 ) ;
if ( ! V_5 -> V_4 . V_47 -> V_98 )
F_36 ( V_5 ) ;
if ( ! V_5 -> V_4 . V_47 -> V_99 )
F_37 ( V_5 ) ;
}
static unsigned F_40 ( struct V_1 * V_5 , unsigned V_100 )
{
if ( F_9 ( V_5 -> V_16 ) )
if ( V_100 > 100 )
V_100 = 100 ;
return V_100 ;
}
static int F_41 ( struct V_2 * V_4 , unsigned V_100 )
{
struct V_1 * V_5 ;
if ( ! V_4 )
return - V_101 ;
V_5 = F_1 ( V_4 ) ;
V_100 = F_40 ( V_5 , V_100 ) ;
V_5 -> V_49 = V_100 ;
F_28 ( & V_5 -> V_4 . V_59 ,
V_61 , & V_5 -> V_49 ) ;
return 0 ;
}
static int F_42 ( struct V_2 * V_3 , int V_102 )
{
return 0 ;
}
static int F_43 ( struct V_103 * V_47 ,
struct V_104 * V_99 )
{
struct V_1 * V_5 ;
if ( ! V_47 )
return - V_101 ;
V_5 = F_1 ( V_47 -> V_4 ) ;
V_5 -> V_4 . V_47 -> V_99 = V_99 ;
if ( ( V_5 -> V_45 != V_46 ) && ( ! V_99 ) ) {
V_5 -> V_45 = V_46 ;
F_44 ( & V_5 -> V_97 ) ;
}
return 0 ;
}
static int F_45 ( struct V_103 * V_47 , struct V_105 * V_98 )
{
struct V_1 * V_5 ;
if ( ! V_47 )
return - V_101 ;
V_5 = F_1 ( V_47 -> V_4 ) ;
V_5 -> V_4 . V_47 -> V_98 = V_98 ;
if ( ( V_5 -> V_45 != V_46 ) && ( ! V_98 ) ) {
V_5 -> V_45 = V_46 ;
F_44 ( & V_5 -> V_97 ) ;
}
return 0 ;
}
static int F_46 ( struct V_1 * V_5 )
{
int V_106 ;
V_5 -> V_15 = F_47 ( V_5 -> V_6 , L_14 ) ;
if ( F_20 ( V_5 -> V_15 ) ) {
F_8 ( V_5 -> V_6 , L_15 ) ;
V_106 = F_48 ( V_5 -> V_15 ) ;
return V_106 ;
}
V_5 -> V_18 = F_47 ( V_5 -> V_6 , L_16 ) ;
if ( F_20 ( V_5 -> V_18 ) ) {
F_8 ( V_5 -> V_6 , L_17 ) ;
V_106 = F_48 ( V_5 -> V_18 ) ;
return V_106 ;
}
V_5 -> V_19 = F_47 ( V_5 -> V_6 , L_18 ) ;
if ( F_20 ( V_5 -> V_19 ) ) {
F_8 ( V_5 -> V_6 , L_19 ) ;
V_106 = F_48 ( V_5 -> V_19 ) ;
return V_106 ;
}
return 0 ;
}
static int F_49 ( struct V_107 * V_108 ,
struct V_1 * V_5 )
{
int V_106 ;
int V_90 ;
V_90 = F_50 ( V_108 , L_20 ) ;
if ( V_90 < 0 ) {
F_8 ( & V_108 -> V_6 , L_21 ) ;
return V_90 ;
}
V_106 = F_51 ( & V_108 -> V_6 , V_90 , NULL ,
F_38 ,
V_109 | V_110 , L_22 , V_5 ) ;
if ( V_106 < 0 ) {
F_8 ( V_5 -> V_6 , L_23 ) ;
return V_106 ;
}
V_90 = F_50 ( V_108 , L_24 ) ;
if ( V_90 < 0 ) {
F_8 ( & V_108 -> V_6 , L_25 ) ;
return V_90 ;
}
V_106 = F_51 ( & V_108 -> V_6 , V_90 , NULL ,
F_35 ,
V_109 | V_110 , L_26 , V_5 ) ;
if ( V_106 < 0 ) {
F_8 ( V_5 -> V_6 , L_27 ) ;
return V_106 ;
}
V_90 = F_50 ( V_108 , L_28 ) ;
if ( V_90 < 0 ) {
F_8 ( & V_108 -> V_6 , L_29 ) ;
return V_90 ;
}
V_106 = F_51 ( & V_108 -> V_6 , V_90 , NULL ,
F_35 ,
V_109 | V_110 , L_30 , V_5 ) ;
if ( V_106 < 0 ) {
F_8 ( V_5 -> V_6 , L_31 ) ;
return V_106 ;
}
return 0 ;
}
static int F_52 ( struct V_107 * V_108 )
{
struct V_1 * V_5 ;
struct V_16 * V_16 ;
struct V_103 * V_47 ;
int V_106 ;
int V_111 ;
V_16 = F_53 ( V_108 -> V_6 . V_112 ) ;
V_111 = F_54 ( & V_108 -> V_6 ) ;
if ( F_55 ( V_16 ) ) {
F_8 ( & V_108 -> V_6 , L_32 , V_111 ) ;
return - V_101 ;
}
V_5 = F_56 ( & V_108 -> V_6 , sizeof( * V_5 ) , V_113 ) ;
if ( ! V_5 )
return - V_114 ;
V_47 = F_56 ( & V_108 -> V_6 , sizeof( * V_47 ) , V_113 ) ;
if ( ! V_47 )
return - V_114 ;
V_5 -> V_6 = & V_108 -> V_6 ;
V_5 -> V_16 = V_16 ;
V_5 -> V_4 . V_6 = V_5 -> V_6 ;
V_5 -> V_4 . V_47 = V_47 ;
V_5 -> V_4 . V_115 = L_33 ;
V_5 -> V_4 . V_116 = F_42 ;
V_5 -> V_4 . V_117 = F_41 ;
V_5 -> V_4 . V_51 = V_118 ;
V_47 -> V_4 = & V_5 -> V_4 ;
V_47 -> V_119 = F_45 ;
V_47 -> V_120 = F_43 ;
F_57 ( V_108 , V_5 ) ;
F_58 ( & V_5 -> V_4 . V_59 ) ;
F_59 ( & V_5 -> V_97 , F_39 ) ;
V_106 = F_46 ( V_5 ) ;
if ( V_106 )
return V_106 ;
V_106 = F_49 ( V_108 , V_5 ) ;
if ( V_106 < 0 )
return V_106 ;
V_106 = F_60 ( & V_5 -> V_4 , V_121 ) ;
if ( V_106 ) {
F_8 ( & V_108 -> V_6 , L_34 ) ;
return V_106 ;
}
if ( ! F_9 ( V_5 -> V_16 ) ) {
V_106 = F_4 ( V_5 -> V_6 ,
V_122 , V_123 , 0x01 ) ;
if ( V_106 < 0 )
F_8 ( V_5 -> V_6 , L_35 ,
V_106 ) ;
V_106 = F_4 ( V_5 -> V_6 ,
V_124 , V_125 , 0xC8 ) ;
if ( V_106 < 0 )
F_8 ( V_5 -> V_6 , L_36 ,
V_106 ) ;
V_106 = F_4 ( V_5 -> V_6 ,
V_124 , V_126 , 0x00 ) ;
if ( V_106 < 0 )
F_8 ( V_5 -> V_6 , L_37 ,
V_106 ) ;
V_106 = F_4 ( V_5 -> V_6 ,
V_124 , V_127 , 0x78 ) ;
if ( V_106 < 0 )
F_8 ( V_5 -> V_6 , L_38 ,
V_106 ) ;
V_106 = F_4 ( V_5 -> V_6 ,
V_122 , V_123 , 0x00 ) ;
if ( V_106 < 0 )
F_8 ( V_5 -> V_6 , L_39 ,
V_106 ) ;
}
if ( F_34 ( V_5 -> V_16 ) ) {
V_106 = F_17 ( V_5 -> V_6 ,
V_122 , V_123 ,
0x01 , 0x01 ) ;
if ( V_106 < 0 )
F_8 ( V_5 -> V_6 , L_35 ,
V_106 ) ;
V_106 = F_17 ( V_5 -> V_6 ,
V_124 , V_125 ,
0xC8 , 0xC8 ) ;
if ( V_106 < 0 )
F_8 ( V_5 -> V_6 , L_36 ,
V_106 ) ;
V_106 = F_17 ( V_5 -> V_6 ,
V_124 , V_126 ,
0x60 , 0x60 ) ;
if ( V_106 < 0 )
F_8 ( V_5 -> V_6 , L_37 ,
V_106 ) ;
V_106 = F_17 ( V_5 -> V_6 ,
V_124 , V_127 ,
0xFC , 0x80 ) ;
if ( V_106 < 0 )
F_8 ( V_5 -> V_6 , L_38 ,
V_106 ) ;
V_106 = F_17 ( V_5 -> V_6 ,
V_122 , V_123 ,
0x00 , 0x00 ) ;
if ( V_106 < 0 )
F_8 ( V_5 -> V_6 , L_39 ,
V_106 ) ;
}
F_3 ( V_5 ) ;
F_31 ( V_5 ) ;
F_61 ( & V_108 -> V_6 , L_40 , V_111 ) ;
return 0 ;
}
static int F_62 ( struct V_107 * V_108 )
{
struct V_1 * V_5 = F_63 ( V_108 ) ;
F_64 ( & V_5 -> V_97 ) ;
F_65 ( & V_5 -> V_4 ) ;
if ( V_5 -> V_45 == V_65 )
F_36 ( V_5 ) ;
else if ( V_5 -> V_45 == V_58 )
F_37 ( V_5 ) ;
return 0 ;
}
static int T_3 F_66 ( void )
{
return F_67 ( & V_128 ) ;
}
static void T_4 F_68 ( void )
{
F_69 ( & V_128 ) ;
}
