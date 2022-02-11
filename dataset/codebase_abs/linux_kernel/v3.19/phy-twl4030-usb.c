static int F_1 ( struct V_1 * V_2 ,
T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
T_1 V_6 ;
if ( ( F_2 ( V_3 , V_4 , V_5 ) >= 0 ) &&
( F_3 ( V_3 , & V_6 , V_5 ) >= 0 ) &&
( V_6 == V_4 ) )
return 0 ;
F_4 ( V_2 -> V_7 , L_1 ,
1 , V_3 , V_5 , V_6 , V_4 ) ;
if ( ( F_2 ( V_3 , V_4 , V_5 ) >= 0 ) &&
( F_3 ( V_3 , & V_6 , V_5 ) >= 0 ) &&
( V_6 == V_4 ) )
return 0 ;
F_4 ( V_2 -> V_7 , L_1 ,
2 , V_3 , V_5 , V_6 , V_4 ) ;
return - V_8 ;
}
static inline int F_5 ( struct V_1 * V_2 ,
T_1 V_5 , T_1 V_4 )
{
int V_9 = 0 ;
V_9 = F_2 ( V_10 , V_4 , V_5 ) ;
if ( V_9 < 0 )
F_4 ( V_2 -> V_7 ,
L_2 , V_5 , V_9 ) ;
return V_9 ;
}
static inline int F_6 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_5 )
{
T_1 V_4 ;
int V_9 = 0 ;
V_9 = F_3 ( V_3 , & V_4 , V_5 ) ;
if ( V_9 >= 0 )
V_9 = V_4 ;
else
F_4 ( V_2 -> V_7 ,
L_3 ,
V_3 , V_5 , V_9 ) ;
return V_9 ;
}
static inline int F_7 ( struct V_1 * V_2 , T_1 V_5 )
{
return F_6 ( V_2 , V_10 , V_5 ) ;
}
static inline int
F_8 ( struct V_1 * V_2 , T_1 V_11 , T_1 V_12 )
{
return F_5 ( V_2 , F_9 ( V_11 ) , V_12 ) ;
}
static inline int
F_10 ( struct V_1 * V_2 , T_1 V_11 , T_1 V_12 )
{
return F_5 ( V_2 , F_11 ( V_11 ) , V_12 ) ;
}
static bool F_12 ( struct V_1 * V_2 )
{
int V_9 ;
V_9 = F_7 ( V_2 , V_13 ) ;
if ( V_9 < 0 || ! ( V_9 & V_14 ) )
return false ;
V_9 = F_7 ( V_2 , V_15 ) ;
if ( V_9 < 0 )
return false ;
return ( V_9 & ( V_16 | V_17 ) ) ? true : false ;
}
static enum V_18
F_13 ( struct V_1 * V_2 )
{
int V_19 ;
enum V_18 V_20 = V_21 ;
V_2 -> V_22 = false ;
V_19 = F_6 ( V_2 , V_23 , V_24 ) ;
if ( V_19 < 0 )
F_14 ( V_2 -> V_7 , L_4 , V_19 ) ;
else if ( V_19 & ( F_15 ( 7 ) | F_15 ( 2 ) ) ) {
if ( V_19 & F_15 ( 7 ) ) {
if ( F_12 ( V_2 ) )
V_19 &= ~ F_15 ( 7 ) ;
else
V_2 -> V_22 = true ;
}
if ( V_19 & F_15 ( 2 ) )
V_20 = V_25 ;
else if ( V_19 & F_15 ( 7 ) )
V_20 = V_26 ;
else
V_20 = V_27 ;
} else {
if ( V_2 -> V_20 != V_21 )
V_20 = V_27 ;
}
F_4 ( V_2 -> V_7 , L_5 ,
V_19 , V_19 , V_20 ) ;
return V_20 ;
}
static void F_16 ( struct V_1 * V_2 , int V_28 )
{
V_2 -> V_29 = V_28 ;
switch ( V_28 ) {
case V_30 :
F_10 ( V_2 , V_31 ,
V_32 ) ;
F_8 ( V_2 , V_33 , V_34 ) ;
F_10 ( V_2 , V_35 ,
V_36 |
V_37 ) ;
break;
case - 1 :
break;
default:
F_14 ( V_2 -> V_7 , L_6 ,
V_28 ) ;
break;
}
}
static void F_17 ( struct V_1 * V_2 , int V_38 )
{
unsigned long V_39 ;
int V_40 = F_7 ( V_2 , V_41 ) ;
if ( V_40 >= 0 ) {
if ( V_38 ) {
V_40 |= V_42 ;
F_18 ( F_19 ( V_2 , V_41 ,
( T_1 ) V_40 ) < 0 ) ;
V_39 = V_43 + V_44 ;
while ( ! ( F_7 ( V_2 , V_13 ) &
V_14 )
&& F_20 ( V_43 , V_39 ) )
F_21 ( 10 ) ;
if ( ! ( F_7 ( V_2 , V_13 ) &
V_14 ) )
F_14 ( V_2 -> V_7 , L_7
L_8 ) ;
} else {
V_40 &= ~ V_42 ;
F_18 ( F_19 ( V_2 , V_41 ,
( T_1 ) V_40 ) < 0 ) ;
}
}
}
static void F_22 ( struct V_1 * V_2 , int V_38 )
{
T_1 V_45 = F_7 ( V_2 , V_46 ) ;
if ( V_38 )
V_45 &= ~ V_47 ;
else
V_45 |= V_47 ;
F_18 ( F_19 ( V_2 , V_46 , V_45 ) < 0 ) ;
}
static int F_23 ( struct V_48 * V_7 )
{
struct V_1 * V_2 = F_24 ( V_7 ) ;
F_4 ( V_2 -> V_7 , L_9 , V_49 ) ;
if ( F_25 ( V_7 ) )
return 0 ;
F_22 ( V_2 , 0 ) ;
F_26 ( V_2 -> V_50 ) ;
F_26 ( V_2 -> V_51 ) ;
F_26 ( V_2 -> V_52 ) ;
return 0 ;
}
static int F_27 ( struct V_48 * V_7 )
{
struct V_1 * V_2 = F_24 ( V_7 ) ;
int V_53 ;
F_4 ( V_2 -> V_7 , L_9 , V_49 ) ;
if ( F_28 ( V_7 ) )
return 0 ;
V_53 = F_29 ( V_2 -> V_52 ) ;
if ( V_53 )
F_14 ( V_2 -> V_7 , L_10 ) ;
V_53 = F_29 ( V_2 -> V_51 ) ;
if ( V_53 )
F_14 ( V_2 -> V_7 , L_11 ) ;
F_2 ( V_54 , 0 , V_55 ) ;
V_53 = F_29 ( V_2 -> V_50 ) ;
if ( V_53 )
F_14 ( V_2 -> V_7 , L_12 ) ;
F_22 ( V_2 , 1 ) ;
F_5 ( V_2 , V_41 ,
F_7 ( V_2 , V_41 ) |
( V_56 |
V_57 ) ) ;
return 0 ;
}
static int F_30 ( struct V_58 * V_58 )
{
struct V_1 * V_2 = F_31 ( V_58 ) ;
F_4 ( V_2 -> V_7 , L_9 , V_49 ) ;
F_32 ( V_2 -> V_7 ) ;
F_33 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_34 ( struct V_58 * V_58 )
{
struct V_1 * V_2 = F_31 ( V_58 ) ;
F_4 ( V_2 -> V_7 , L_9 , V_49 ) ;
F_35 ( V_2 -> V_7 ) ;
F_17 ( V_2 , 1 ) ;
F_16 ( V_2 , V_2 -> V_29 ) ;
if ( V_2 -> V_29 == V_30 )
F_17 ( V_2 , 0 ) ;
F_36 ( & V_2 -> V_59 , 0 ) ;
return 0 ;
}
static int F_37 ( struct V_1 * V_2 )
{
F_2 ( V_23 , V_60 ,
V_61 ) ;
F_2 ( V_23 , V_62 ,
V_61 ) ;
F_2 ( V_54 , 0x14 , V_63 ) ;
F_2 ( V_54 , 0 , V_64 ) ;
V_2 -> V_52 = F_38 ( V_2 -> V_7 , L_13 ) ;
if ( F_39 ( V_2 -> V_52 ) )
return - V_65 ;
F_2 ( V_54 , 0 , V_66 ) ;
F_2 ( V_54 , 0 , V_67 ) ;
V_2 -> V_50 = F_38 ( V_2 -> V_7 , L_14 ) ;
if ( F_39 ( V_2 -> V_50 ) )
return - V_65 ;
F_2 ( V_54 , 0 , V_68 ) ;
F_2 ( V_54 , 0 , V_69 ) ;
V_2 -> V_51 = F_38 ( V_2 -> V_7 , L_15 ) ;
if ( F_39 ( V_2 -> V_51 ) )
return - V_65 ;
F_2 ( V_54 , 0 , V_70 ) ;
F_2 ( V_23 , 0 ,
V_61 ) ;
return 0 ;
}
static T_2 F_40 ( struct V_48 * V_7 ,
struct V_71 * V_72 , char * V_73 )
{
struct V_1 * V_2 = F_24 ( V_7 ) ;
int V_9 = - V_74 ;
F_41 ( & V_2 -> V_75 ) ;
V_9 = sprintf ( V_73 , L_9 ,
V_2 -> V_22 ? L_16 : L_17 ) ;
F_42 ( & V_2 -> V_75 ) ;
return V_9 ;
}
static T_3 F_43 ( int V_76 , void * V_77 )
{
struct V_1 * V_2 = V_77 ;
enum V_18 V_19 ;
bool V_78 = false ;
V_19 = F_13 ( V_2 ) ;
F_41 ( & V_2 -> V_75 ) ;
if ( V_19 >= 0 && V_19 != V_2 -> V_20 ) {
V_2 -> V_20 = V_19 ;
V_78 = true ;
}
F_42 ( & V_2 -> V_75 ) ;
if ( V_78 ) {
if ( ( V_19 == V_26 ) ||
( V_19 == V_25 ) ) {
if ( F_25 ( V_2 -> V_7 ) )
F_35 ( V_2 -> V_7 ) ;
} else {
if ( F_28 ( V_2 -> V_7 ) ) {
F_32 ( V_2 -> V_7 ) ;
F_33 ( V_2 -> V_7 ) ;
}
}
F_44 ( V_19 ) ;
}
if ( V_19 == V_25 && F_28 ( V_2 -> V_7 ) ) {
F_45 ( & V_2 -> V_59 ) ;
F_36 ( & V_2 -> V_59 , V_44 ) ;
}
if ( V_76 )
F_46 ( & V_2 -> V_7 -> V_79 , NULL , L_18 ) ;
return V_80 ;
}
static void F_47 ( struct V_81 * V_82 )
{
struct V_1 * V_2 = F_48 ( V_82 , struct V_1 ,
V_59 . V_82 ) ;
F_43 ( 0 , V_2 ) ;
}
static int F_49 ( struct V_58 * V_58 )
{
struct V_1 * V_2 = F_31 ( V_58 ) ;
F_35 ( V_2 -> V_7 ) ;
F_36 ( & V_2 -> V_59 , 0 ) ;
F_32 ( V_2 -> V_7 ) ;
F_33 ( V_2 -> V_7 ) ;
return 0 ;
}
static int F_50 ( struct V_83 * V_84 ,
struct V_85 * V_86 )
{
if ( ! V_84 )
return - V_65 ;
V_84 -> V_86 = V_86 ;
if ( ! V_86 )
V_84 -> V_87 = V_88 ;
return 0 ;
}
static int F_51 ( struct V_83 * V_84 , struct V_89 * V_90 )
{
if ( ! V_84 )
return - V_65 ;
V_84 -> V_90 = V_90 ;
if ( ! V_90 )
V_84 -> V_87 = V_88 ;
return 0 ;
}
static int F_52 ( struct V_91 * V_92 )
{
struct V_93 * V_94 = F_53 ( & V_92 -> V_7 ) ;
struct V_1 * V_2 ;
struct V_58 * V_58 ;
int V_19 , V_95 ;
struct V_83 * V_84 ;
struct V_96 * V_97 = V_92 -> V_7 . V_98 ;
struct V_99 * V_99 ;
V_2 = F_54 ( & V_92 -> V_7 , sizeof( * V_2 ) , V_100 ) ;
if ( ! V_2 )
return - V_101 ;
if ( V_97 )
F_55 ( V_97 , L_19 ,
(enum V_102 * ) & V_2 -> V_29 ) ;
else if ( V_94 ) {
V_2 -> V_29 = V_94 -> V_29 ;
} else {
F_14 ( & V_92 -> V_7 , L_20 ) ;
return - V_74 ;
}
V_84 = F_54 ( & V_92 -> V_7 , sizeof( * V_84 ) , V_100 ) ;
if ( ! V_84 )
return - V_101 ;
V_2 -> V_7 = & V_92 -> V_7 ;
V_2 -> V_76 = F_56 ( V_92 , 0 ) ;
V_2 -> V_22 = false ;
V_2 -> V_20 = - V_74 ;
V_2 -> V_20 = V_21 ;
V_2 -> V_58 . V_7 = V_2 -> V_7 ;
V_2 -> V_58 . V_103 = L_21 ;
V_2 -> V_58 . V_84 = V_84 ;
V_2 -> V_58 . type = V_104 ;
V_84 -> V_105 = & V_2 -> V_58 ;
V_84 -> V_106 = F_51 ;
V_84 -> V_107 = F_50 ;
V_58 = F_57 ( V_2 -> V_7 , NULL , & V_108 ) ;
if ( F_39 ( V_58 ) ) {
F_4 ( & V_92 -> V_7 , L_22 ) ;
return F_58 ( V_58 ) ;
}
F_59 ( V_58 , V_2 ) ;
V_99 = F_60 ( V_2 -> V_7 ,
V_109 ) ;
if ( F_39 ( V_99 ) )
return F_58 ( V_99 ) ;
F_61 ( & V_2 -> V_75 ) ;
F_62 ( & V_2 -> V_59 , F_47 ) ;
V_95 = F_37 ( V_2 ) ;
if ( V_95 ) {
F_14 ( & V_92 -> V_7 , L_23 ) ;
return V_95 ;
}
F_63 ( & V_2 -> V_58 ) ;
F_64 ( V_92 , V_2 ) ;
if ( F_65 ( & V_92 -> V_7 , & V_110 ) )
F_66 ( & V_92 -> V_7 , L_24 ) ;
F_67 ( & V_2 -> V_58 . V_111 ) ;
F_68 ( & V_92 -> V_7 ) ;
F_69 ( & V_92 -> V_7 , 2000 ) ;
F_70 ( & V_92 -> V_7 ) ;
F_35 ( & V_92 -> V_7 ) ;
V_19 = F_71 ( V_2 -> V_7 , V_2 -> V_76 , NULL ,
F_43 , V_112 |
V_113 | V_114 , L_25 , V_2 ) ;
if ( V_19 < 0 ) {
F_4 ( & V_92 -> V_7 , L_26 ,
V_2 -> V_76 , V_19 ) ;
return V_19 ;
}
if ( V_94 )
V_95 = F_72 ( V_58 , L_27 , L_28 ) ;
if ( V_95 )
return V_95 ;
F_32 ( & V_92 -> V_7 ) ;
F_33 ( V_2 -> V_7 ) ;
F_73 ( & V_92 -> V_7 , L_29 ) ;
return 0 ;
}
static int F_74 ( struct V_91 * V_92 )
{
struct V_1 * V_2 = F_75 ( V_92 ) ;
int V_40 ;
F_35 ( V_2 -> V_7 ) ;
F_45 ( & V_2 -> V_59 ) ;
F_76 ( V_2 -> V_7 , & V_110 ) ;
F_16 ( V_2 , - 1 ) ;
V_40 = F_7 ( V_2 , V_41 ) ;
if ( V_40 >= 0 ) {
V_40 |= V_56 ;
V_40 &= ~ ( V_57 | V_42 ) ;
F_5 ( V_2 , V_41 , ( T_1 ) V_40 ) ;
}
F_10 ( V_2 , V_33 , V_34 ) ;
F_32 ( V_2 -> V_7 ) ;
F_77 ( V_2 -> V_7 ) ;
return 0 ;
}
static int T_4 F_78 ( void )
{
return F_79 ( & V_115 ) ;
}
static void T_5 F_80 ( void )
{
F_81 ( & V_115 ) ;
}
