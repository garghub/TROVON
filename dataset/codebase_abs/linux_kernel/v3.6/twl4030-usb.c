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
static enum V_13
F_12 ( struct V_1 * V_2 )
{
int V_14 ;
enum V_13 V_15 = V_16 ;
V_2 -> V_17 = false ;
V_14 = F_6 ( V_2 , V_18 ,
V_19 ) ;
if ( V_14 < 0 )
F_13 ( V_2 -> V_7 , L_4 , V_14 ) ;
else if ( V_14 & ( F_14 ( 7 ) | F_14 ( 2 ) ) ) {
if ( V_14 & ( F_14 ( 7 ) ) )
V_2 -> V_17 = true ;
if ( V_14 & F_14 ( 2 ) )
V_15 = V_20 ;
else
V_15 = V_21 ;
} else {
if ( V_2 -> V_15 != V_16 )
V_15 = V_22 ;
}
F_4 ( V_2 -> V_7 , L_5 ,
V_14 , V_14 , V_15 ) ;
F_15 ( & V_2 -> V_23 ) ;
V_2 -> V_15 = V_15 ;
F_16 ( & V_2 -> V_23 ) ;
return V_15 ;
}
static void F_17 ( struct V_1 * V_2 , int V_24 )
{
V_2 -> V_25 = V_24 ;
switch ( V_24 ) {
case V_26 :
F_10 ( V_2 , V_27 ,
V_28 ) ;
F_8 ( V_2 , V_29 , V_30 ) ;
F_10 ( V_2 , V_31 ,
V_32 |
V_33 ) ;
break;
case - 1 :
break;
default:
F_13 ( V_2 -> V_7 , L_6 ,
V_24 ) ;
break;
} ;
}
static void F_18 ( struct V_1 * V_2 , int V_34 )
{
unsigned long V_35 ;
int V_36 = F_7 ( V_2 , V_37 ) ;
if ( V_36 >= 0 ) {
if ( V_34 ) {
V_36 |= V_38 ;
F_19 ( F_20 ( V_2 , V_37 ,
( T_1 ) V_36 ) < 0 ) ;
V_35 = V_39 + V_40 ;
while ( ! ( F_7 ( V_2 , V_41 ) &
V_42 )
&& F_21 ( V_39 , V_35 ) )
F_22 ( 10 ) ;
if ( ! ( F_7 ( V_2 , V_41 ) &
V_42 ) )
F_13 ( V_2 -> V_7 , L_7
L_8 ) ;
} else {
V_36 &= ~ V_38 ;
F_19 ( F_20 ( V_2 , V_37 ,
( T_1 ) V_36 ) < 0 ) ;
}
}
}
static void F_23 ( struct V_1 * V_2 , int V_34 )
{
T_1 V_43 = F_7 ( V_2 , V_44 ) ;
if ( V_34 )
V_43 &= ~ V_45 ;
else
V_43 |= V_45 ;
F_19 ( F_20 ( V_2 , V_44 , V_43 ) < 0 ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_34 )
{
if ( V_34 ) {
F_25 ( V_2 -> V_46 ) ;
F_25 ( V_2 -> V_47 ) ;
F_2 ( V_48 , 0 ,
V_49 ) ;
F_25 ( V_2 -> V_50 ) ;
F_23 ( V_2 , 1 ) ;
F_5 ( V_2 , V_37 ,
F_7 ( V_2 , V_37 ) |
( V_51 |
V_52 ) ) ;
} else {
F_23 ( V_2 , 0 ) ;
F_26 ( V_2 -> V_50 ) ;
F_26 ( V_2 -> V_47 ) ;
F_26 ( V_2 -> V_46 ) ;
}
}
static void F_27 ( struct V_1 * V_2 , int V_53 )
{
if ( V_2 -> V_54 )
return;
F_24 ( V_2 , 0 ) ;
V_2 -> V_54 = 1 ;
F_4 ( V_2 -> V_7 , L_9 , V_55 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_24 ( V_2 , 1 ) ;
F_18 ( V_2 , 1 ) ;
F_17 ( V_2 , V_2 -> V_25 ) ;
if ( V_2 -> V_25 == V_26 )
F_18 ( V_2 , 0 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_54 )
return;
F_28 ( V_2 ) ;
V_2 -> V_54 = 0 ;
F_4 ( V_2 -> V_7 , L_9 , V_55 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
F_2 ( V_18 ,
V_56 ,
V_57 ) ;
F_2 ( V_18 ,
V_58 ,
V_57 ) ;
F_2 ( V_48 , 0x14 , V_59 ) ;
F_2 ( V_48 , 0 , V_60 ) ;
V_2 -> V_46 = F_31 ( V_2 -> V_7 , L_10 ) ;
if ( F_32 ( V_2 -> V_46 ) )
return - V_61 ;
F_2 ( V_48 , 0 , V_62 ) ;
F_2 ( V_48 , 0 , V_63 ) ;
V_2 -> V_50 = F_31 ( V_2 -> V_7 , L_11 ) ;
if ( F_32 ( V_2 -> V_50 ) )
goto V_64;
F_2 ( V_48 , 0 , V_65 ) ;
F_2 ( V_48 , 0 , V_66 ) ;
V_2 -> V_47 = F_31 ( V_2 -> V_7 , L_12 ) ;
if ( F_32 ( V_2 -> V_47 ) )
goto V_67;
F_2 ( V_48 , 0 , V_68 ) ;
F_2 ( V_18 , 0 ,
V_57 ) ;
return 0 ;
V_67:
F_33 ( V_2 -> V_50 ) ;
V_2 -> V_50 = NULL ;
V_64:
F_33 ( V_2 -> V_46 ) ;
V_2 -> V_46 = NULL ;
return - V_61 ;
}
static T_2 F_34 ( struct V_69 * V_7 ,
struct V_70 * V_71 , char * V_72 )
{
struct V_1 * V_2 = F_35 ( V_7 ) ;
unsigned long V_73 ;
int V_9 = - V_74 ;
F_36 ( & V_2 -> V_23 , V_73 ) ;
V_9 = sprintf ( V_72 , L_9 ,
V_2 -> V_17 ? L_13 : L_14 ) ;
F_37 ( & V_2 -> V_23 , V_73 ) ;
return V_9 ;
}
static T_3 F_38 ( int V_75 , void * V_76 )
{
struct V_1 * V_2 = V_76 ;
enum V_13 V_14 ;
V_14 = F_12 ( V_2 ) ;
if ( V_14 > 0 ) {
if ( V_14 == V_22 ||
V_14 == V_77 )
F_27 ( V_2 , 0 ) ;
else
F_29 ( V_2 ) ;
F_39 ( V_2 -> V_15 ) ;
}
F_40 ( & V_2 -> V_7 -> V_78 , NULL , L_15 ) ;
return V_79 ;
}
static void F_41 ( struct V_1 * V_2 )
{
enum V_13 V_14 ;
V_14 = F_12 ( V_2 ) ;
if ( V_14 > 0 ) {
if ( V_14 == V_22 ||
V_14 == V_77 ) {
F_23 ( V_2 , 0 ) ;
V_2 -> V_54 = 1 ;
} else {
F_28 ( V_2 ) ;
V_2 -> V_54 = 0 ;
}
F_39 ( V_2 -> V_15 ) ;
}
F_40 ( & V_2 -> V_7 -> V_78 , NULL , L_15 ) ;
}
static int F_42 ( struct V_80 * V_81 , int V_82 )
{
struct V_1 * V_2 = F_43 ( V_81 ) ;
if ( V_82 )
F_27 ( V_2 , 1 ) ;
else
F_29 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_83 * V_84 ,
struct V_85 * V_86 )
{
if ( ! V_84 )
return - V_61 ;
V_84 -> V_86 = V_86 ;
if ( ! V_86 )
V_84 -> V_87 -> V_88 = V_89 ;
return 0 ;
}
static int F_45 ( struct V_83 * V_84 , struct V_90 * V_91 )
{
if ( ! V_84 )
return - V_61 ;
V_84 -> V_91 = V_91 ;
if ( ! V_91 )
V_84 -> V_87 -> V_88 = V_89 ;
return 0 ;
}
static int T_4 F_46 ( struct V_92 * V_93 )
{
struct V_94 * V_95 = V_93 -> V_7 . V_96 ;
struct V_1 * V_2 ;
int V_14 , V_97 ;
struct V_83 * V_84 ;
if ( ! V_95 ) {
F_4 ( & V_93 -> V_7 , L_16 ) ;
return - V_74 ;
}
V_2 = F_47 ( & V_93 -> V_7 , sizeof *V_2 , V_98 ) ;
if ( ! V_2 )
return - V_99 ;
V_84 = F_47 ( & V_93 -> V_7 , sizeof *V_84 , V_98 ) ;
if ( ! V_84 )
return - V_99 ;
V_2 -> V_7 = & V_93 -> V_7 ;
V_2 -> V_75 = F_48 ( V_93 , 0 ) ;
V_2 -> V_25 = V_95 -> V_25 ;
V_2 -> V_17 = false ;
V_2 -> V_54 = 1 ;
V_2 -> V_15 = V_16 ;
V_2 -> V_87 . V_7 = V_2 -> V_7 ;
V_2 -> V_87 . V_100 = L_17 ;
V_2 -> V_87 . V_84 = V_84 ;
V_2 -> V_87 . V_101 = F_42 ;
V_84 -> V_87 = & V_2 -> V_87 ;
V_84 -> V_102 = F_45 ;
V_84 -> V_103 = F_44 ;
F_49 ( & V_2 -> V_23 ) ;
V_97 = F_30 ( V_2 ) ;
if ( V_97 ) {
F_13 ( & V_93 -> V_7 , L_18 ) ;
return V_97 ;
}
F_50 ( & V_2 -> V_87 , V_104 ) ;
F_51 ( V_93 , V_2 ) ;
if ( F_52 ( & V_93 -> V_7 , & V_105 ) )
F_53 ( & V_93 -> V_7 , L_19 ) ;
V_2 -> V_106 = true ;
V_14 = F_54 ( V_2 -> V_75 , NULL , F_38 ,
V_107 | V_108 |
V_109 , L_20 , V_2 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_93 -> V_7 , L_21 ,
V_2 -> V_75 , V_14 ) ;
return V_14 ;
}
F_41 ( V_2 ) ;
F_55 ( & V_93 -> V_7 , L_22 ) ;
return 0 ;
}
static int T_5 F_56 ( struct V_92 * V_93 )
{
struct V_1 * V_2 = F_57 ( V_93 ) ;
int V_36 ;
F_58 ( V_2 -> V_75 , V_2 ) ;
F_59 ( V_2 -> V_7 , & V_105 ) ;
F_17 ( V_2 , - 1 ) ;
V_36 = F_7 ( V_2 , V_37 ) ;
if ( V_36 >= 0 ) {
V_36 |= V_51 ;
V_36 &= ~ ( V_52 | V_38 ) ;
F_5 ( V_2 , V_37 , ( T_1 ) V_36 ) ;
}
F_10 ( V_2 , V_29 , V_30 ) ;
if ( ! V_2 -> V_54 )
F_24 ( V_2 , 0 ) ;
F_33 ( V_2 -> V_50 ) ;
F_33 ( V_2 -> V_47 ) ;
F_33 ( V_2 -> V_46 ) ;
return 0 ;
}
static int T_6 F_60 ( void )
{
return F_61 ( & V_110 ) ;
}
static void T_5 F_62 ( void )
{
F_63 ( & V_110 ) ;
}
