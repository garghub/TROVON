static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 , T_1 V_5 )
{
T_2 V_6 ;
F_2 ( & V_2 -> V_7 ) ;
V_6 = F_3 ( V_2 -> V_8 , V_3 , V_5 , V_4 ) ;
F_4 ( & V_2 -> V_7 ) ;
return ( V_6 != V_5 ) ? - V_9 : 0 ;
}
static inline int F_5 ( struct V_1 * V_2 , T_1 V_3 , T_1 * V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , 1 ) ;
}
static int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
int V_6 ;
F_2 ( & V_2 -> V_7 ) ;
V_6 = F_7 ( V_2 -> V_8 , V_3 , V_4 ) ;
F_4 ( & V_2 -> V_7 ) ;
return V_6 ;
}
static bool F_8 ( const char * V_10 , int V_11 )
{
if ( ! strcmp ( V_10 , L_1 ) )
return V_11 == V_12 || V_11 == V_13 ;
else if ( ! strcmp ( V_10 , L_2 ) )
return V_11 == V_14 ;
return V_11 >= V_12 && V_11 <= V_14 ;
}
static int F_9 ( struct V_1 * V_2 )
{
T_1 V_15 ;
int V_6 ;
T_1 V_16 [ V_17 ] ;
V_6 = F_1 ( V_2 , V_18 , V_16 , V_17 ) ;
if ( V_6 )
return V_6 ;
V_15 = V_19 | V_20 | V_21 ;
V_6 = F_6 ( V_2 , V_22 , V_15 ) ;
if ( V_6 )
return V_6 ;
V_15 = V_23 | V_24 ;
return F_6 ( V_2 , V_25 , V_15 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_5 ( V_2 , V_26 , & V_15 ) ;
return V_15 & V_27 ;
}
static int F_11 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_5 ( V_2 , V_26 , & V_15 ) ;
return V_15 & V_28 ;
}
static inline void F_12 ( struct V_1 * V_2 , T_1 V_29 )
{
F_6 ( V_2 , V_30 , V_29 ) ;
}
static void F_13 ( struct V_1 * V_2 , T_1 V_11 , int V_31 )
{
struct V_32 * V_33 = V_2 -> V_33 ;
T_1 V_34 = V_35 ;
T_1 V_36 = V_37 | V_38 ;
switch ( V_11 ) {
case 0x5 :
V_34 = V_12 ;
V_2 -> V_39 = V_33 ? V_33 -> V_40 : NULL ;
break;
case 0xB :
if ( F_10 ( V_2 ) ) {
V_2 -> V_39 = V_33 ? V_33 -> V_40 : NULL ;
V_34 = V_13 ;
} else if ( F_11 ( V_2 ) ) {
V_2 -> V_39 = V_33 ? V_33 -> V_41 : NULL ;
V_34 = V_14 ;
V_36 = V_42 | V_43 ;
} else if ( V_31 ) {
V_34 = V_44 ;
V_36 = V_42 | V_43 ;
}
break;
default:
V_34 = V_35 ;
V_2 -> V_39 = NULL ;
break;
}
V_2 -> V_34 = V_34 ;
F_12 ( V_2 , V_36 ) ;
}
static void F_14 ( struct V_1 * V_2 )
{
T_1 V_15 ;
F_5 ( V_2 , V_25 , & V_15 ) ;
V_15 |= V_24 ;
F_6 ( V_2 , V_25 , V_15 ) ;
}
static void F_15 ( struct V_45 * V_46 )
{
struct V_1 * V_2 = F_16 ( V_46 , struct V_1 ,
V_47 . V_47 ) ;
T_1 V_16 [ V_17 ] ;
T_1 V_48 ;
T_1 V_49 ;
if ( F_1 ( V_2 , V_18 , V_16 , V_17 ) ) {
F_17 ( V_2 -> V_50 , L_3 ) ;
return;
}
V_48 = V_16 [ 0 ] & V_51 ;
V_49 = V_16 [ 0 ] & V_52 ;
F_13 ( V_2 , V_48 , V_49 ) ;
F_14 ( V_2 ) ;
F_18 ( V_2 -> V_53 -> V_40 ) ;
F_18 ( V_2 -> V_53 -> V_41 ) ;
F_18 ( V_2 -> V_53 -> V_54 ) ;
}
static T_3 F_19 ( int V_55 , void * V_56 )
{
struct V_1 * V_2 = V_56 ;
F_20 ( & V_2 -> V_47 , V_2 -> V_57 ) ;
return V_58 ;
}
static int F_21 ( struct V_1 * V_2 )
{
int V_6 ;
int V_55 = V_2 -> V_8 -> V_55 ;
unsigned V_59 = V_2 -> V_33 ? V_2 -> V_33 -> V_60 :
V_61 ;
F_22 ( & V_2 -> V_47 , F_15 ) ;
if ( V_55 <= 0 ) {
F_23 ( V_2 -> V_50 , L_4 , V_55 ) ;
return 0 ;
}
V_6 = F_24 ( V_55 , NULL , F_19 ,
V_62 | V_63 ,
L_5 , V_2 ) ;
if ( V_6 )
return V_6 ;
V_2 -> V_55 = V_55 ;
V_2 -> V_57 = F_25 ( V_59 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
F_27 ( & V_2 -> V_47 ) ;
if ( V_2 -> V_55 )
F_28 ( V_2 -> V_55 , V_2 ) ;
}
static int F_29 ( struct V_64 * V_53 ,
enum V_65 V_66 ,
union V_67 * V_15 )
{
struct V_1 * V_2 = F_30 ( V_53 -> V_50 . V_68 ) ;
if ( V_66 != V_69 )
return - V_70 ;
V_15 -> V_71 = F_8 ( V_53 -> V_72 -> V_10 , V_2 -> V_34 ) ;
return 0 ;
}
static bool F_31 ( enum V_73 V_74 )
{
switch ( V_74 ) {
case V_75 :
case V_76 :
case V_77 :
return true ;
default:
return false ;
}
}
static int F_32 ( struct V_64 * V_53 ,
enum V_65 V_66 ,
union V_67 * V_15 )
{
struct V_1 * V_2 = F_30 ( V_53 -> V_50 . V_68 ) ;
struct V_32 * V_33 = V_2 -> V_33 ;
enum V_73 V_74 ;
T_1 V_78 ;
switch ( V_66 ) {
case V_79 :
if ( ! F_8 ( V_53 -> V_72 -> V_10 , V_2 -> V_34 ) ) {
V_15 -> V_71 = V_80 ;
return 0 ;
}
F_5 ( V_2 , V_26 , & V_78 ) ;
V_15 -> V_71 = ( V_78 & V_81 ) == V_82 ?
V_83 :
V_84 ;
break;
case V_85 :
F_5 ( V_2 , V_86 , & V_78 ) ;
V_74 = ( V_78 & V_87 ) >> V_88 ;
V_15 -> V_71 = F_31 ( V_74 ) ?
V_89 :
V_90 ;
break;
case V_91 :
if ( ! V_33 )
return - V_70 ;
if ( V_33 -> V_92 )
V_15 -> V_71 = V_33 -> V_92 () ;
break;
case V_93 :
if ( ! V_33 )
return - V_70 ;
if ( V_33 -> V_94 )
V_15 -> V_71 = V_33 -> V_94 () ;
break;
case V_95 :
if ( ! V_33 )
return - V_70 ;
if ( V_33 -> V_96 )
V_15 -> V_71 = V_33 -> V_96 () ;
break;
case V_97 :
if ( ! V_33 )
return - V_70 ;
if ( V_33 -> V_98 )
V_15 -> V_71 = V_33 -> V_98 () ;
break;
default:
break;
}
return 0 ;
}
static void F_33 ( struct V_64 * V_53 )
{
struct V_1 * V_2 = F_30 ( V_53 -> V_50 . V_68 ) ;
T_1 V_99 ;
T_1 V_100 ;
T_1 V_15 ;
if ( ! F_8 ( V_53 -> V_72 -> V_10 , V_2 -> V_34 ) )
return;
if ( V_2 -> V_39 ) {
V_99 = V_2 -> V_39 -> V_99 ;
V_100 = V_2 -> V_39 -> V_100 ;
V_15 = ( V_100 << V_101 ) | V_99 ;
F_6 ( V_2 , V_102 , V_15 ) ;
}
}
static int F_34 ( struct V_1 * V_2 )
{
struct V_103 V_104 = {} ;
struct V_105 * V_53 ;
V_53 = F_35 ( V_2 -> V_50 , sizeof( * V_53 ) , V_106 ) ;
if ( ! V_53 )
return - V_107 ;
V_2 -> V_53 = V_53 ;
V_104 . V_108 = V_109 ;
V_104 . V_110 = F_36 ( V_109 ) ;
V_53 -> V_40 = F_37 ( V_2 -> V_50 , & V_111 , & V_104 ) ;
if ( F_38 ( V_53 -> V_40 ) )
goto V_112;
V_53 -> V_41 = F_37 ( V_2 -> V_50 , & V_113 ,
& V_104 ) ;
if ( F_38 ( V_53 -> V_41 ) )
goto V_114;
V_53 -> V_54 = F_37 ( V_2 -> V_50 , & V_115 , NULL ) ;
if ( F_38 ( V_53 -> V_54 ) )
goto V_116;
return 0 ;
V_116:
F_39 ( V_53 -> V_41 ) ;
V_114:
F_39 ( V_53 -> V_40 ) ;
V_112:
return - V_117 ;
}
static void F_40 ( struct V_1 * V_2 )
{
struct V_105 * V_53 = V_2 -> V_53 ;
if ( ! V_53 )
return;
F_39 ( V_53 -> V_40 ) ;
F_39 ( V_53 -> V_41 ) ;
F_39 ( V_53 -> V_54 ) ;
}
static struct V_118
* F_41 ( struct V_119 * V_50 , struct V_120 * V_121 )
{
struct V_118 * V_122 ;
V_122 = F_35 ( V_50 , sizeof( * V_122 ) , V_106 ) ;
if ( ! V_122 )
goto V_123;
F_42 ( V_121 , L_6 , ( T_1 * ) & V_122 -> V_99 ) ;
F_42 ( V_121 , L_7 , ( T_1 * ) & V_122 -> V_100 ) ;
V_123:
return V_122 ;
}
static struct V_32 * F_43 ( struct V_119 * V_50 )
{
struct V_120 * V_121 = V_50 -> V_124 ;
struct V_120 * V_125 ;
struct V_32 * V_33 ;
const char * type ;
V_33 = F_35 ( V_50 , sizeof( * V_33 ) , V_106 ) ;
if ( ! V_33 )
return F_44 ( - V_107 ) ;
F_45 ( V_121 , L_8 , & V_33 -> V_60 ) ;
if ( F_46 ( V_121 ) == 0 )
return V_33 ;
F_47 (np, child) {
F_48 ( V_125 , L_9 , & type ) ;
if ( ! strcmp ( type , L_1 ) )
V_33 -> V_40 = F_41 ( V_50 , V_125 ) ;
if ( ! strcmp ( type , L_2 ) )
V_33 -> V_41 = F_41 ( V_50 , V_125 ) ;
}
return V_33 ;
}
static struct V_32 * F_43 ( struct V_119 * V_50 )
{
return NULL ;
}
static int F_49 ( struct V_126 * V_127 , const struct V_128 * V_11 )
{
struct V_1 * V_2 ;
struct V_32 * V_33 ;
int V_6 ;
if ( ! F_50 ( V_127 -> V_129 , V_130 ) )
return - V_9 ;
if ( V_127 -> V_50 . V_124 ) {
V_33 = F_43 ( & V_127 -> V_50 ) ;
if ( F_38 ( V_33 ) )
return F_51 ( V_33 ) ;
} else {
V_33 = F_52 ( & V_127 -> V_50 ) ;
}
V_2 = F_35 ( & V_127 -> V_50 , sizeof( * V_2 ) , V_106 ) ;
if ( ! V_2 )
return - V_107 ;
V_2 -> V_8 = V_127 ;
V_2 -> V_50 = & V_127 -> V_50 ;
V_2 -> V_33 = V_33 ;
F_53 ( V_127 , V_2 ) ;
F_54 ( & V_2 -> V_7 ) ;
V_6 = F_9 ( V_2 ) ;
if ( V_6 ) {
F_17 ( V_2 -> V_50 , L_10 , V_6 ) ;
return V_6 ;
}
V_6 = F_34 ( V_2 ) ;
if ( V_6 ) {
F_17 ( V_2 -> V_50 , L_11 , V_6 ) ;
return V_6 ;
}
V_6 = F_21 ( V_2 ) ;
if ( V_6 ) {
F_17 ( V_2 -> V_50 , L_12 , V_6 ) ;
F_40 ( V_2 ) ;
return V_6 ;
}
return 0 ;
}
static int F_55 ( struct V_126 * V_127 )
{
struct V_1 * V_2 = F_56 ( V_127 ) ;
F_26 ( V_2 ) ;
F_40 ( V_2 ) ;
return 0 ;
}
