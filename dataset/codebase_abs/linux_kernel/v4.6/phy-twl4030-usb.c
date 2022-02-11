static inline bool F_1 ( enum V_1 V_2 )
{
return V_2 == V_3 ||
V_2 == V_4 ;
}
static int F_2 ( struct V_5 * V_6 ,
T_1 V_7 , T_1 V_8 , T_1 V_9 )
{
T_1 V_10 ;
if ( ( F_3 ( V_7 , V_8 , V_9 ) >= 0 ) &&
( F_4 ( V_7 , & V_10 , V_9 ) >= 0 ) &&
( V_10 == V_8 ) )
return 0 ;
F_5 ( V_6 -> V_11 , L_1 ,
1 , V_7 , V_9 , V_10 , V_8 ) ;
if ( ( F_3 ( V_7 , V_8 , V_9 ) >= 0 ) &&
( F_4 ( V_7 , & V_10 , V_9 ) >= 0 ) &&
( V_10 == V_8 ) )
return 0 ;
F_5 ( V_6 -> V_11 , L_1 ,
2 , V_7 , V_9 , V_10 , V_8 ) ;
return - V_12 ;
}
static inline int F_6 ( struct V_5 * V_6 ,
T_1 V_9 , T_1 V_8 )
{
int V_13 = 0 ;
V_13 = F_3 ( V_14 , V_8 , V_9 ) ;
if ( V_13 < 0 )
F_5 ( V_6 -> V_11 ,
L_2 , V_9 , V_13 ) ;
return V_13 ;
}
static inline int F_7 ( struct V_5 * V_6 , T_1 V_7 , T_1 V_9 )
{
T_1 V_8 ;
int V_13 = 0 ;
V_13 = F_4 ( V_7 , & V_8 , V_9 ) ;
if ( V_13 >= 0 )
V_13 = V_8 ;
else
F_5 ( V_6 -> V_11 ,
L_3 ,
V_7 , V_9 , V_13 ) ;
return V_13 ;
}
static inline int F_8 ( struct V_5 * V_6 , T_1 V_9 )
{
return F_7 ( V_6 , V_14 , V_9 ) ;
}
static inline int
F_9 ( struct V_5 * V_6 , T_1 V_15 , T_1 V_16 )
{
return F_6 ( V_6 , F_10 ( V_15 ) , V_16 ) ;
}
static inline int
F_11 ( struct V_5 * V_6 , T_1 V_15 , T_1 V_16 )
{
return F_6 ( V_6 , F_12 ( V_15 ) , V_16 ) ;
}
static bool F_13 ( struct V_5 * V_6 )
{
int V_13 ;
V_13 = F_8 ( V_6 , V_17 ) ;
if ( V_13 < 0 || ! ( V_13 & V_18 ) )
return false ;
V_13 = F_8 ( V_6 , V_19 ) ;
if ( V_13 < 0 )
return false ;
return ( V_13 & ( V_20 | V_21 ) ) ? true : false ;
}
static enum V_1
F_14 ( struct V_5 * V_6 )
{
int V_22 ;
enum V_1 V_23 = V_24 ;
V_6 -> V_25 = false ;
V_22 = F_7 ( V_6 , V_26 , V_27 ) ;
if ( V_22 < 0 )
F_15 ( V_6 -> V_11 , L_4 , V_22 ) ;
else if ( V_22 & ( F_16 ( 7 ) | F_16 ( 2 ) ) ) {
if ( V_22 & F_16 ( 7 ) ) {
if ( F_13 ( V_6 ) )
V_22 &= ~ F_16 ( 7 ) ;
else
V_6 -> V_25 = true ;
}
if ( V_22 & F_16 ( 2 ) )
V_23 = V_4 ;
else if ( V_22 & F_16 ( 7 ) )
V_23 = V_3 ;
else
V_23 = V_28 ;
} else {
if ( V_6 -> V_23 != V_24 )
V_23 = V_28 ;
}
F_5 ( V_6 -> V_11 , L_5 ,
V_22 , V_22 , V_23 ) ;
return V_23 ;
}
static void F_17 ( struct V_5 * V_6 , int V_29 )
{
V_6 -> V_30 = V_29 ;
switch ( V_29 ) {
case V_31 :
F_11 ( V_6 , V_32 ,
V_33 ) ;
F_9 ( V_6 , V_34 , V_35 ) ;
F_11 ( V_6 , V_36 ,
V_37 |
V_38 ) ;
break;
case - 1 :
break;
default:
F_15 ( V_6 -> V_11 , L_6 ,
V_29 ) ;
break;
}
}
static void F_18 ( struct V_5 * V_6 , int V_39 )
{
unsigned long V_40 ;
int V_41 = F_8 ( V_6 , V_42 ) ;
if ( V_41 >= 0 ) {
if ( V_39 ) {
V_41 |= V_43 ;
F_19 ( F_20 ( V_6 , V_42 ,
( T_1 ) V_41 ) < 0 ) ;
V_40 = V_44 + V_45 ;
while ( ! ( F_8 ( V_6 , V_17 ) &
V_18 )
&& F_21 ( V_44 , V_40 ) )
F_22 ( 10 ) ;
if ( ! ( F_8 ( V_6 , V_17 ) &
V_18 ) )
F_15 ( V_6 -> V_11 , L_7
L_8 ) ;
} else {
V_41 &= ~ V_43 ;
F_19 ( F_20 ( V_6 , V_42 ,
( T_1 ) V_41 ) < 0 ) ;
}
}
}
static void F_23 ( struct V_5 * V_6 , int V_39 )
{
T_1 V_46 = F_8 ( V_6 , V_47 ) ;
if ( V_39 )
V_46 &= ~ V_48 ;
else
V_46 |= V_48 ;
F_19 ( F_20 ( V_6 , V_47 , V_46 ) < 0 ) ;
}
static int T_2 F_24 ( struct V_49 * V_11 )
{
struct V_5 * V_6 = F_25 ( V_11 ) ;
F_5 ( V_6 -> V_11 , L_9 , V_50 ) ;
F_23 ( V_6 , 0 ) ;
F_26 ( V_6 -> V_51 ) ;
F_26 ( V_6 -> V_52 ) ;
F_26 ( V_6 -> V_53 ) ;
return 0 ;
}
static int T_2 F_27 ( struct V_49 * V_11 )
{
struct V_5 * V_6 = F_25 ( V_11 ) ;
int V_54 ;
F_5 ( V_6 -> V_11 , L_9 , V_50 ) ;
V_54 = F_28 ( V_6 -> V_53 ) ;
if ( V_54 )
F_15 ( V_6 -> V_11 , L_10 ) ;
V_54 = F_28 ( V_6 -> V_52 ) ;
if ( V_54 )
F_15 ( V_6 -> V_11 , L_11 ) ;
F_3 ( V_55 , 0 , V_56 ) ;
V_54 = F_28 ( V_6 -> V_51 ) ;
if ( V_54 )
F_15 ( V_6 -> V_11 , L_12 ) ;
F_23 ( V_6 , 1 ) ;
F_6 ( V_6 , V_42 ,
F_8 ( V_6 , V_42 ) |
( V_57 |
V_58 ) ) ;
return 0 ;
}
static int F_29 ( struct V_59 * V_59 )
{
struct V_5 * V_6 = F_30 ( V_59 ) ;
F_5 ( V_6 -> V_11 , L_9 , V_50 ) ;
F_31 ( V_6 -> V_11 ) ;
F_32 ( V_6 -> V_11 ) ;
return 0 ;
}
static int F_33 ( struct V_59 * V_59 )
{
struct V_5 * V_6 = F_30 ( V_59 ) ;
F_5 ( V_6 -> V_11 , L_9 , V_50 ) ;
F_34 ( V_6 -> V_11 ) ;
F_18 ( V_6 , 1 ) ;
F_17 ( V_6 , V_6 -> V_30 ) ;
if ( V_6 -> V_30 == V_31 )
F_18 ( V_6 , 0 ) ;
F_35 ( & V_6 -> V_60 , 0 ) ;
return 0 ;
}
static int F_36 ( struct V_5 * V_6 )
{
F_3 ( V_26 , V_61 ,
V_62 ) ;
F_3 ( V_26 , V_63 ,
V_62 ) ;
F_3 ( V_55 , 0x14 , V_64 ) ;
F_3 ( V_55 , 0 , V_65 ) ;
V_6 -> V_53 = F_37 ( V_6 -> V_11 , L_13 ) ;
if ( F_38 ( V_6 -> V_53 ) )
return - V_66 ;
F_3 ( V_55 , 0 , V_67 ) ;
F_3 ( V_55 , 0 , V_68 ) ;
V_6 -> V_51 = F_37 ( V_6 -> V_11 , L_14 ) ;
if ( F_38 ( V_6 -> V_51 ) )
return - V_66 ;
F_3 ( V_55 , 0 , V_69 ) ;
F_3 ( V_55 , 0 , V_70 ) ;
V_6 -> V_52 = F_37 ( V_6 -> V_11 , L_15 ) ;
if ( F_38 ( V_6 -> V_52 ) )
return - V_66 ;
F_3 ( V_55 , 0 , V_71 ) ;
F_3 ( V_26 , 0 ,
V_62 ) ;
return 0 ;
}
static T_3 F_39 ( struct V_49 * V_11 ,
struct V_72 * V_73 , char * V_74 )
{
struct V_5 * V_6 = F_25 ( V_11 ) ;
int V_13 = - V_75 ;
F_40 ( & V_6 -> V_76 ) ;
V_13 = sprintf ( V_74 , L_9 ,
V_6 -> V_25 ? L_16 : L_17 ) ;
F_41 ( & V_6 -> V_76 ) ;
return V_13 ;
}
static T_4 F_42 ( int V_77 , void * V_78 )
{
struct V_5 * V_6 = V_78 ;
enum V_1 V_22 ;
bool V_79 = false ;
V_22 = F_14 ( V_6 ) ;
F_40 ( & V_6 -> V_76 ) ;
if ( V_22 >= 0 && V_22 != V_6 -> V_23 ) {
V_79 =
F_1 ( V_6 -> V_23 ) !=
F_1 ( V_22 ) ;
V_6 -> V_23 = V_22 ;
}
F_41 ( & V_6 -> V_76 ) ;
if ( V_79 ) {
if ( F_1 ( V_22 ) ) {
F_34 ( V_6 -> V_11 ) ;
} else {
F_31 ( V_6 -> V_11 ) ;
F_32 ( V_6 -> V_11 ) ;
}
F_43 ( V_22 ) ;
}
if ( V_22 == V_4 && F_44 ( V_6 -> V_11 ) ) {
F_45 ( & V_6 -> V_60 ) ;
F_35 ( & V_6 -> V_60 , V_45 ) ;
}
if ( V_77 )
F_46 ( & V_6 -> V_11 -> V_80 , NULL , L_18 ) ;
return V_81 ;
}
static void F_47 ( struct V_82 * V_83 )
{
struct V_5 * V_6 = F_48 ( V_83 , struct V_5 ,
V_60 . V_83 ) ;
F_42 ( 0 , V_6 ) ;
}
static int F_49 ( struct V_59 * V_59 )
{
struct V_5 * V_6 = F_30 ( V_59 ) ;
F_34 ( V_6 -> V_11 ) ;
F_35 ( & V_6 -> V_60 , 0 ) ;
F_31 ( V_6 -> V_11 ) ;
F_32 ( V_6 -> V_11 ) ;
return 0 ;
}
static int F_50 ( struct V_84 * V_85 ,
struct V_86 * V_87 )
{
if ( ! V_85 )
return - V_66 ;
V_85 -> V_87 = V_87 ;
if ( ! V_87 )
V_85 -> V_88 = V_89 ;
return 0 ;
}
static int F_51 ( struct V_84 * V_85 , struct V_90 * V_91 )
{
if ( ! V_85 )
return - V_66 ;
V_85 -> V_91 = V_91 ;
if ( ! V_91 )
V_85 -> V_88 = V_89 ;
return 0 ;
}
static int F_52 ( struct V_92 * V_93 )
{
struct V_94 * V_95 = F_53 ( & V_93 -> V_11 ) ;
struct V_5 * V_6 ;
struct V_59 * V_59 ;
int V_22 , V_96 ;
struct V_84 * V_85 ;
struct V_97 * V_98 = V_93 -> V_11 . V_99 ;
struct V_100 * V_100 ;
V_6 = F_54 ( & V_93 -> V_11 , sizeof( * V_6 ) , V_101 ) ;
if ( ! V_6 )
return - V_102 ;
if ( V_98 )
F_55 ( V_98 , L_19 ,
(enum V_103 * ) & V_6 -> V_30 ) ;
else if ( V_95 ) {
V_6 -> V_30 = V_95 -> V_30 ;
} else {
F_15 ( & V_93 -> V_11 , L_20 ) ;
return - V_75 ;
}
V_85 = F_54 ( & V_93 -> V_11 , sizeof( * V_85 ) , V_101 ) ;
if ( ! V_85 )
return - V_102 ;
V_6 -> V_11 = & V_93 -> V_11 ;
V_6 -> V_77 = F_56 ( V_93 , 0 ) ;
V_6 -> V_25 = false ;
V_6 -> V_23 = V_24 ;
V_6 -> V_59 . V_11 = V_6 -> V_11 ;
V_6 -> V_59 . V_104 = L_21 ;
V_6 -> V_59 . V_85 = V_85 ;
V_6 -> V_59 . type = V_105 ;
V_85 -> V_106 = & V_6 -> V_59 ;
V_85 -> V_107 = F_51 ;
V_85 -> V_108 = F_50 ;
V_59 = F_57 ( V_6 -> V_11 , NULL , & V_109 ) ;
if ( F_38 ( V_59 ) ) {
F_5 ( & V_93 -> V_11 , L_22 ) ;
return F_58 ( V_59 ) ;
}
F_59 ( V_59 , V_6 ) ;
V_100 = F_60 ( V_6 -> V_11 ,
V_110 ) ;
if ( F_38 ( V_100 ) )
return F_58 ( V_100 ) ;
F_61 ( & V_6 -> V_76 ) ;
F_62 ( & V_6 -> V_60 , F_47 ) ;
V_96 = F_36 ( V_6 ) ;
if ( V_96 ) {
F_15 ( & V_93 -> V_11 , L_23 ) ;
return V_96 ;
}
F_63 ( & V_6 -> V_59 ) ;
F_64 ( V_93 , V_6 ) ;
if ( F_65 ( & V_93 -> V_11 , & V_111 ) )
F_66 ( & V_93 -> V_11 , L_24 ) ;
F_67 ( & V_6 -> V_59 . V_112 ) ;
F_68 ( & V_93 -> V_11 ) ;
F_69 ( & V_93 -> V_11 , 2000 ) ;
F_70 ( & V_93 -> V_11 ) ;
F_34 ( & V_93 -> V_11 ) ;
V_22 = F_71 ( V_6 -> V_11 , V_6 -> V_77 , NULL ,
F_42 , V_113 |
V_114 | V_115 , L_25 , V_6 ) ;
if ( V_22 < 0 ) {
F_5 ( & V_93 -> V_11 , L_26 ,
V_6 -> V_77 , V_22 ) ;
return V_22 ;
}
if ( V_95 )
V_96 = F_72 ( V_59 , L_27 , L_28 ) ;
if ( V_96 )
return V_96 ;
F_31 ( & V_93 -> V_11 ) ;
F_32 ( V_6 -> V_11 ) ;
F_73 ( & V_93 -> V_11 , L_29 ) ;
return 0 ;
}
static int F_74 ( struct V_92 * V_93 )
{
struct V_5 * V_6 = F_75 ( V_93 ) ;
int V_41 ;
F_76 ( & V_6 -> V_59 ) ;
F_34 ( V_6 -> V_11 ) ;
F_45 ( & V_6 -> V_60 ) ;
F_77 ( V_6 -> V_11 , & V_111 ) ;
F_17 ( V_6 , - 1 ) ;
if ( F_1 ( V_6 -> V_23 ) )
F_78 ( V_6 -> V_11 ) ;
F_31 ( V_6 -> V_11 ) ;
F_79 ( V_6 -> V_11 ) ;
F_80 ( V_6 -> V_11 ) ;
V_41 = F_8 ( V_6 , V_42 ) ;
if ( V_41 >= 0 ) {
V_41 |= V_57 ;
V_41 &= ~ ( V_58 | V_43 ) ;
F_6 ( V_6 , V_42 , ( T_1 ) V_41 ) ;
}
F_11 ( V_6 , V_34 , V_35 ) ;
return 0 ;
}
static int T_5 F_81 ( void )
{
return F_82 ( & V_116 ) ;
}
static void T_6 F_83 ( void )
{
F_84 ( & V_116 ) ;
}
