static inline bool F_1 ( enum V_1 V_2 )
{
return V_2 == V_3 ||
V_2 == V_4 ;
}
static int F_2 ( struct V_5 * V_6 ,
T_1 V_7 , T_1 V_8 , T_1 V_9 )
{
T_1 V_10 = 0xFF ;
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
F_17 ( & V_6 -> V_11 -> V_29 , V_23 == V_3
? V_30 : V_31 ) ;
F_5 ( V_6 -> V_11 , L_5 ,
V_22 , V_22 , V_23 ) ;
return V_23 ;
}
static void F_18 ( struct V_5 * V_6 , int V_32 )
{
V_6 -> V_33 = V_32 ;
switch ( V_32 ) {
case V_34 :
F_11 ( V_6 , V_35 ,
V_36 ) ;
F_9 ( V_6 , V_37 , V_38 ) ;
F_11 ( V_6 , V_39 ,
V_40 |
V_41 ) ;
break;
case - 1 :
break;
default:
F_15 ( V_6 -> V_11 , L_6 ,
V_32 ) ;
break;
}
}
static void F_19 ( struct V_5 * V_6 , int V_42 )
{
unsigned long V_43 ;
int V_44 = F_8 ( V_6 , V_45 ) ;
if ( V_44 >= 0 ) {
if ( V_42 ) {
V_44 |= V_46 ;
F_20 ( F_21 ( V_6 , V_45 ,
( T_1 ) V_44 ) < 0 ) ;
V_43 = V_47 + V_48 ;
while ( ! ( F_8 ( V_6 , V_17 ) &
V_18 )
&& F_22 ( V_47 , V_43 ) )
F_23 ( 10 ) ;
if ( ! ( F_8 ( V_6 , V_17 ) &
V_18 ) )
F_15 ( V_6 -> V_11 , L_7
L_8 ) ;
} else {
V_44 &= ~ V_46 ;
F_20 ( F_21 ( V_6 , V_45 ,
( T_1 ) V_44 ) < 0 ) ;
}
}
}
static void F_24 ( struct V_5 * V_6 , int V_42 )
{
T_1 V_49 = F_8 ( V_6 , V_50 ) ;
if ( V_42 )
V_49 &= ~ V_51 ;
else
V_49 |= V_51 ;
F_20 ( F_21 ( V_6 , V_50 , V_49 ) < 0 ) ;
}
static int T_2 F_25 ( struct V_52 * V_11 )
{
struct V_5 * V_6 = F_26 ( V_11 ) ;
F_5 ( V_6 -> V_11 , L_9 , V_53 ) ;
F_24 ( V_6 , 0 ) ;
F_27 ( V_6 -> V_54 ) ;
F_27 ( V_6 -> V_55 ) ;
F_27 ( V_6 -> V_56 ) ;
return 0 ;
}
static int T_2 F_28 ( struct V_52 * V_11 )
{
struct V_5 * V_6 = F_26 ( V_11 ) ;
int V_57 ;
F_5 ( V_6 -> V_11 , L_9 , V_53 ) ;
V_57 = F_29 ( V_6 -> V_56 ) ;
if ( V_57 )
F_15 ( V_6 -> V_11 , L_10 ) ;
V_57 = F_29 ( V_6 -> V_55 ) ;
if ( V_57 )
F_15 ( V_6 -> V_11 , L_11 ) ;
F_3 ( V_58 , 0 , V_59 ) ;
V_57 = F_29 ( V_6 -> V_54 ) ;
if ( V_57 )
F_15 ( V_6 -> V_11 , L_12 ) ;
F_24 ( V_6 , 1 ) ;
F_6 ( V_6 , V_45 ,
F_8 ( V_6 , V_45 ) |
( V_60 |
V_61 ) ) ;
F_19 ( V_6 , 1 ) ;
F_18 ( V_6 , V_6 -> V_33 ) ;
if ( V_6 -> V_33 == V_34 )
F_19 ( V_6 , 0 ) ;
F_30 ( 50 ) ;
return 0 ;
}
static int F_31 ( struct V_62 * V_62 )
{
struct V_5 * V_6 = F_32 ( V_62 ) ;
F_5 ( V_6 -> V_11 , L_9 , V_53 ) ;
return 0 ;
}
static int F_33 ( struct V_62 * V_62 )
{
struct V_5 * V_6 = F_32 ( V_62 ) ;
F_5 ( V_6 -> V_11 , L_9 , V_53 ) ;
F_34 ( V_6 -> V_11 ) ;
F_35 ( & V_6 -> V_63 , V_48 ) ;
F_36 ( V_6 -> V_11 ) ;
F_37 ( V_6 -> V_11 ) ;
return 0 ;
}
static int F_38 ( struct V_5 * V_6 )
{
F_3 ( V_26 , V_64 ,
V_65 ) ;
F_3 ( V_26 , V_66 ,
V_65 ) ;
F_3 ( V_58 , 0x14 , V_67 ) ;
F_3 ( V_58 , 0 , V_68 ) ;
V_6 -> V_56 = F_39 ( V_6 -> V_11 , L_13 ) ;
if ( F_40 ( V_6 -> V_56 ) )
return - V_69 ;
F_3 ( V_58 , 0 , V_70 ) ;
F_3 ( V_58 , 0 , V_71 ) ;
V_6 -> V_54 = F_39 ( V_6 -> V_11 , L_14 ) ;
if ( F_40 ( V_6 -> V_54 ) )
return - V_69 ;
F_3 ( V_58 , 0 , V_72 ) ;
F_3 ( V_58 , 0 , V_73 ) ;
V_6 -> V_55 = F_39 ( V_6 -> V_11 , L_15 ) ;
if ( F_40 ( V_6 -> V_55 ) )
return - V_69 ;
F_3 ( V_58 , 0 , V_74 ) ;
F_3 ( V_26 , 0 ,
V_65 ) ;
return 0 ;
}
static T_3 F_41 ( struct V_52 * V_11 ,
struct V_75 * V_76 , char * V_77 )
{
struct V_5 * V_6 = F_26 ( V_11 ) ;
int V_13 = - V_78 ;
F_42 ( & V_6 -> V_79 ) ;
V_13 = sprintf ( V_77 , L_9 ,
V_6 -> V_25 ? L_16 : L_17 ) ;
F_43 ( & V_6 -> V_79 ) ;
return V_13 ;
}
static T_4 F_44 ( int V_80 , void * V_81 )
{
struct V_5 * V_6 = V_81 ;
enum V_1 V_22 ;
bool V_82 = false ;
int V_83 ;
V_22 = F_14 ( V_6 ) ;
F_42 ( & V_6 -> V_79 ) ;
if ( V_22 >= 0 && V_22 != V_6 -> V_23 ) {
V_82 =
F_1 ( V_6 -> V_23 ) !=
F_1 ( V_22 ) ;
V_6 -> V_23 = V_22 ;
}
F_43 ( & V_6 -> V_79 ) ;
if ( V_82 ) {
if ( F_1 ( V_22 ) ) {
F_34 ( V_6 -> V_11 ) ;
} else {
F_36 ( V_6 -> V_11 ) ;
F_37 ( V_6 -> V_11 ) ;
}
V_6 -> V_84 = true ;
}
if ( V_6 -> V_84 ) {
V_83 = F_45 ( V_22 ) ;
if ( ! V_83 )
V_6 -> V_84 = false ;
}
if ( V_22 == V_4 && F_46 ( V_6 -> V_11 ) ) {
F_47 ( & V_6 -> V_63 ) ;
F_35 ( & V_6 -> V_63 , V_48 ) ;
}
if ( V_80 )
F_48 ( & V_6 -> V_11 -> V_29 , NULL , L_18 ) ;
return V_85 ;
}
static void F_49 ( struct V_86 * V_87 )
{
struct V_5 * V_6 = F_50 ( V_87 , struct V_5 ,
V_63 . V_87 ) ;
F_44 ( 0 , V_6 ) ;
}
static int F_51 ( struct V_62 * V_62 )
{
struct V_5 * V_6 = F_32 ( V_62 ) ;
F_34 ( V_6 -> V_11 ) ;
V_6 -> V_23 = V_24 ;
F_35 ( & V_6 -> V_63 , V_48 ) ;
F_36 ( V_6 -> V_11 ) ;
F_37 ( V_6 -> V_11 ) ;
return 0 ;
}
static int F_52 ( struct V_88 * V_89 ,
struct V_90 * V_91 )
{
if ( ! V_89 )
return - V_69 ;
V_89 -> V_91 = V_91 ;
if ( ! V_91 )
V_89 -> V_92 = V_93 ;
return 0 ;
}
static int F_53 ( struct V_88 * V_89 , struct V_94 * V_95 )
{
if ( ! V_89 )
return - V_69 ;
V_89 -> V_95 = V_95 ;
if ( ! V_95 )
V_89 -> V_92 = V_93 ;
return 0 ;
}
static int F_54 ( struct V_96 * V_97 )
{
struct V_98 * V_99 = F_55 ( & V_97 -> V_11 ) ;
struct V_5 * V_6 ;
struct V_62 * V_62 ;
int V_22 , V_83 ;
struct V_88 * V_89 ;
struct V_100 * V_101 = V_97 -> V_11 . V_102 ;
struct V_103 * V_103 ;
V_6 = F_56 ( & V_97 -> V_11 , sizeof( * V_6 ) , V_104 ) ;
if ( ! V_6 )
return - V_105 ;
if ( V_101 )
F_57 ( V_101 , L_19 ,
(enum V_106 * ) & V_6 -> V_33 ) ;
else if ( V_99 ) {
V_6 -> V_33 = V_99 -> V_33 ;
} else {
F_15 ( & V_97 -> V_11 , L_20 ) ;
return - V_78 ;
}
V_89 = F_56 ( & V_97 -> V_11 , sizeof( * V_89 ) , V_104 ) ;
if ( ! V_89 )
return - V_105 ;
V_6 -> V_11 = & V_97 -> V_11 ;
V_6 -> V_80 = F_58 ( V_97 , 0 ) ;
V_6 -> V_25 = false ;
V_6 -> V_23 = V_24 ;
V_6 -> V_84 = false ;
V_6 -> V_62 . V_11 = V_6 -> V_11 ;
V_6 -> V_62 . V_107 = L_21 ;
V_6 -> V_62 . V_89 = V_89 ;
V_6 -> V_62 . type = V_108 ;
V_89 -> V_109 = & V_6 -> V_62 ;
V_89 -> V_110 = F_53 ;
V_89 -> V_111 = F_52 ;
V_62 = F_59 ( V_6 -> V_11 , NULL , & V_112 ) ;
if ( F_40 ( V_62 ) ) {
F_5 ( & V_97 -> V_11 , L_22 ) ;
return F_60 ( V_62 ) ;
}
F_61 ( V_62 , V_6 ) ;
V_103 = F_62 ( V_6 -> V_11 ,
V_113 ) ;
if ( F_40 ( V_103 ) )
return F_60 ( V_103 ) ;
F_63 ( & V_6 -> V_79 ) ;
F_64 ( & V_6 -> V_63 , F_49 ) ;
V_83 = F_38 ( V_6 ) ;
if ( V_83 ) {
F_15 ( & V_97 -> V_11 , L_23 ) ;
return V_83 ;
}
F_65 ( & V_6 -> V_62 ) ;
F_66 ( V_97 , V_6 ) ;
if ( F_67 ( & V_97 -> V_11 , & V_114 ) )
F_68 ( & V_97 -> V_11 , L_24 ) ;
F_69 ( & V_6 -> V_62 . V_115 ) ;
F_70 ( & V_97 -> V_11 ) ;
F_71 ( & V_97 -> V_11 , 2000 ) ;
F_72 ( & V_97 -> V_11 ) ;
F_34 ( & V_97 -> V_11 ) ;
V_22 = F_73 ( V_6 -> V_11 , V_6 -> V_80 , NULL ,
F_44 , V_116 |
V_117 | V_118 , L_25 , V_6 ) ;
if ( V_22 < 0 ) {
F_5 ( & V_97 -> V_11 , L_26 ,
V_6 -> V_80 , V_22 ) ;
return V_22 ;
}
if ( V_99 )
V_83 = F_74 ( V_62 , L_27 , L_28 ) ;
if ( V_83 )
return V_83 ;
F_36 ( & V_97 -> V_11 ) ;
F_37 ( V_6 -> V_11 ) ;
F_75 ( & V_97 -> V_11 , L_29 ) ;
return 0 ;
}
static int F_76 ( struct V_96 * V_97 )
{
struct V_5 * V_6 = F_77 ( V_97 ) ;
int V_44 ;
F_78 ( & V_6 -> V_62 ) ;
F_34 ( V_6 -> V_11 ) ;
F_47 ( & V_6 -> V_63 ) ;
F_79 ( V_6 -> V_11 , & V_114 ) ;
F_18 ( V_6 , - 1 ) ;
if ( F_1 ( V_6 -> V_23 ) )
F_80 ( V_6 -> V_11 ) ;
F_36 ( V_6 -> V_11 ) ;
F_81 ( & V_97 -> V_11 ) ;
F_82 ( V_6 -> V_11 ) ;
F_83 ( V_6 -> V_11 ) ;
V_44 = F_8 ( V_6 , V_45 ) ;
if ( V_44 >= 0 ) {
V_44 |= V_60 ;
V_44 &= ~ ( V_61 | V_46 ) ;
F_6 ( V_6 , V_45 , ( T_1 ) V_44 ) ;
}
F_11 ( V_6 , V_37 , V_38 ) ;
return 0 ;
}
static int T_5 F_84 ( void )
{
return F_85 ( & V_119 ) ;
}
static void T_6 F_86 ( void )
{
F_87 ( & V_119 ) ;
}
