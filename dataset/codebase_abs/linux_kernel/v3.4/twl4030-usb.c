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
static enum V_13 F_12 ( struct V_1 * V_2 )
{
int V_14 ;
int V_15 = V_16 ;
struct V_17 * V_18 = V_2 -> V_19 . V_18 ;
V_2 -> V_20 = false ;
V_14 = F_6 ( V_2 , V_21 ,
V_22 ) ;
if ( V_14 < 0 )
F_13 ( V_2 -> V_7 , L_4 , V_14 ) ;
else if ( V_14 & ( F_14 ( 7 ) | F_14 ( 2 ) ) ) {
if ( V_14 & ( F_14 ( 7 ) ) )
V_2 -> V_20 = true ;
if ( V_14 & F_14 ( 2 ) )
V_15 = V_23 ;
else
V_15 = V_24 ;
} else
V_15 = V_16 ;
F_4 ( V_2 -> V_7 , L_5 ,
V_14 , V_14 , V_15 ) ;
V_2 -> V_19 . V_25 = V_15 ;
F_15 ( & V_2 -> V_26 ) ;
V_2 -> V_15 = V_15 ;
if ( V_15 == V_23 ) {
V_18 -> V_27 = true ;
V_2 -> V_19 . V_28 = V_29 ;
} else {
V_18 -> V_27 = false ;
V_2 -> V_19 . V_28 = V_30 ;
}
F_16 ( & V_2 -> V_26 ) ;
return V_15 ;
}
static void F_17 ( struct V_1 * V_2 , int V_31 )
{
V_2 -> V_32 = V_31 ;
switch ( V_31 ) {
case V_33 :
F_10 ( V_2 , V_34 ,
V_35 ) ;
F_8 ( V_2 , V_36 , V_37 ) ;
F_10 ( V_2 , V_38 ,
V_39 |
V_40 ) ;
break;
case - 1 :
break;
default:
F_13 ( V_2 -> V_7 , L_6 ,
V_31 ) ;
break;
} ;
}
static void F_18 ( struct V_1 * V_2 , int V_41 )
{
unsigned long V_42 ;
int V_43 = F_7 ( V_2 , V_44 ) ;
if ( V_43 >= 0 ) {
if ( V_41 ) {
V_43 |= V_45 ;
F_19 ( F_20 ( V_2 , V_44 ,
( T_1 ) V_43 ) < 0 ) ;
V_42 = V_46 + V_47 ;
while ( ! ( F_7 ( V_2 , V_48 ) &
V_49 )
&& F_21 ( V_46 , V_42 ) )
F_22 ( 10 ) ;
if ( ! ( F_7 ( V_2 , V_48 ) &
V_49 ) )
F_13 ( V_2 -> V_7 , L_7
L_8 ) ;
} else {
V_43 &= ~ V_45 ;
F_19 ( F_20 ( V_2 , V_44 ,
( T_1 ) V_43 ) < 0 ) ;
}
}
}
static void F_23 ( struct V_1 * V_2 , int V_41 )
{
T_1 V_50 = F_7 ( V_2 , V_51 ) ;
if ( V_41 )
V_50 &= ~ V_52 ;
else
V_50 |= V_52 ;
F_19 ( F_20 ( V_2 , V_51 , V_50 ) < 0 ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_41 )
{
if ( V_41 ) {
F_25 ( V_2 -> V_53 ) ;
F_25 ( V_2 -> V_54 ) ;
F_2 ( V_55 , 0 ,
V_56 ) ;
F_25 ( V_2 -> V_57 ) ;
F_23 ( V_2 , 1 ) ;
F_5 ( V_2 , V_44 ,
F_7 ( V_2 , V_44 ) |
( V_58 |
V_59 ) ) ;
} else {
F_23 ( V_2 , 0 ) ;
F_26 ( V_2 -> V_57 ) ;
F_26 ( V_2 -> V_54 ) ;
F_26 ( V_2 -> V_53 ) ;
}
}
static void F_27 ( struct V_1 * V_2 , int V_60 )
{
if ( V_2 -> V_61 )
return;
F_24 ( V_2 , 0 ) ;
V_2 -> V_61 = 1 ;
F_4 ( V_2 -> V_7 , L_9 , V_62 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_24 ( V_2 , 1 ) ;
F_18 ( V_2 , 1 ) ;
F_17 ( V_2 , V_2 -> V_32 ) ;
if ( V_2 -> V_32 == V_33 )
F_18 ( V_2 , 0 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_61 )
return;
F_28 ( V_2 ) ;
V_2 -> V_61 = 0 ;
F_4 ( V_2 -> V_7 , L_9 , V_62 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
F_2 ( V_21 ,
V_63 ,
V_64 ) ;
F_2 ( V_21 ,
V_65 ,
V_64 ) ;
F_2 ( V_55 , 0x14 , V_66 ) ;
F_2 ( V_55 , 0 , V_67 ) ;
V_2 -> V_53 = F_31 ( V_2 -> V_7 , L_10 ) ;
if ( F_32 ( V_2 -> V_53 ) )
return - V_68 ;
F_2 ( V_55 , 0 , V_69 ) ;
F_2 ( V_55 , 0 , V_70 ) ;
V_2 -> V_57 = F_31 ( V_2 -> V_7 , L_11 ) ;
if ( F_32 ( V_2 -> V_57 ) )
goto V_71;
F_2 ( V_55 , 0 , V_72 ) ;
F_2 ( V_55 , 0 , V_73 ) ;
V_2 -> V_54 = F_31 ( V_2 -> V_7 , L_12 ) ;
if ( F_32 ( V_2 -> V_54 ) )
goto V_74;
F_2 ( V_55 , 0 , V_75 ) ;
F_2 ( V_21 , 0 ,
V_64 ) ;
return 0 ;
V_74:
F_33 ( V_2 -> V_57 ) ;
V_2 -> V_57 = NULL ;
V_71:
F_33 ( V_2 -> V_53 ) ;
V_2 -> V_53 = NULL ;
return - V_68 ;
}
static T_2 F_34 ( struct V_76 * V_7 ,
struct V_77 * V_78 , char * V_79 )
{
struct V_1 * V_2 = F_35 ( V_7 ) ;
unsigned long V_80 ;
int V_9 = - V_81 ;
F_36 ( & V_2 -> V_26 , V_80 ) ;
V_9 = sprintf ( V_79 , L_9 ,
V_2 -> V_20 ? L_13 : L_14 ) ;
F_37 ( & V_2 -> V_26 , V_80 ) ;
return V_9 ;
}
static T_3 F_38 ( int V_82 , void * V_83 )
{
struct V_1 * V_2 = V_83 ;
int V_14 ;
V_14 = F_12 ( V_2 ) ;
if ( V_14 >= 0 ) {
if ( V_14 == V_16 )
F_27 ( V_2 , 0 ) ;
else
F_29 ( V_2 ) ;
F_39 ( & V_2 -> V_19 . V_84 , V_14 ,
V_2 -> V_19 . V_18 -> V_85 ) ;
}
F_40 ( & V_2 -> V_7 -> V_86 , NULL , L_15 ) ;
return V_87 ;
}
static void F_41 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_12 ( V_2 ) ;
if ( V_14 >= 0 ) {
if ( V_14 == V_16 ) {
F_23 ( V_2 , 0 ) ;
V_2 -> V_61 = 1 ;
} else {
F_28 ( V_2 ) ;
V_2 -> V_61 = 0 ;
}
F_39 ( & V_2 -> V_19 . V_84 , V_14 ,
V_2 -> V_19 . V_18 -> V_85 ) ;
}
F_40 ( & V_2 -> V_7 -> V_86 , NULL , L_15 ) ;
}
static int F_42 ( struct V_88 * V_89 , int V_90 )
{
struct V_1 * V_2 = F_43 ( V_89 ) ;
if ( V_90 )
F_27 ( V_2 , 1 ) ;
else
F_29 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_17 * V_18 ,
struct V_91 * V_85 )
{
if ( ! V_18 )
return - V_68 ;
V_18 -> V_85 = V_85 ;
if ( ! V_85 )
V_18 -> V_19 -> V_28 = V_92 ;
return 0 ;
}
static int F_45 ( struct V_17 * V_18 , struct V_93 * V_94 )
{
if ( ! V_18 )
return - V_68 ;
V_18 -> V_94 = V_94 ;
if ( ! V_94 )
V_18 -> V_19 -> V_28 = V_92 ;
return 0 ;
}
static int T_4 F_46 ( struct V_95 * V_96 )
{
struct V_97 * V_98 = V_96 -> V_7 . V_99 ;
struct V_1 * V_2 ;
int V_14 , V_100 ;
struct V_17 * V_18 ;
if ( ! V_98 ) {
F_4 ( & V_96 -> V_7 , L_16 ) ;
return - V_81 ;
}
V_2 = F_47 ( sizeof *V_2 , V_101 ) ;
if ( ! V_2 )
return - V_102 ;
V_18 = F_47 ( sizeof *V_18 , V_101 ) ;
if ( ! V_18 ) {
F_48 ( V_2 ) ;
return - V_102 ;
}
V_2 -> V_7 = & V_96 -> V_7 ;
V_2 -> V_82 = F_49 ( V_96 , 0 ) ;
V_2 -> V_32 = V_98 -> V_32 ;
V_2 -> V_20 = false ;
V_2 -> V_61 = 1 ;
V_2 -> V_19 . V_7 = V_2 -> V_7 ;
V_2 -> V_19 . V_103 = L_17 ;
V_2 -> V_19 . V_18 = V_18 ;
V_2 -> V_19 . V_104 = F_42 ;
V_18 -> V_19 = & V_2 -> V_19 ;
V_18 -> V_105 = F_45 ;
V_18 -> V_106 = F_44 ;
F_50 ( & V_2 -> V_26 ) ;
V_100 = F_30 ( V_2 ) ;
if ( V_100 ) {
F_13 ( & V_96 -> V_7 , L_18 ) ;
F_48 ( V_18 ) ;
F_48 ( V_2 ) ;
return V_100 ;
}
F_51 ( & V_2 -> V_19 ) ;
F_52 ( V_96 , V_2 ) ;
if ( F_53 ( & V_96 -> V_7 , & V_107 ) )
F_54 ( & V_96 -> V_7 , L_19 ) ;
F_55 ( & V_2 -> V_19 . V_84 ) ;
V_2 -> V_108 = true ;
V_14 = F_56 ( V_2 -> V_82 , NULL , F_38 ,
V_109 | V_110 ,
L_20 , V_2 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_96 -> V_7 , L_21 ,
V_2 -> V_82 , V_14 ) ;
F_48 ( V_18 ) ;
F_48 ( V_2 ) ;
return V_14 ;
}
F_41 ( V_2 ) ;
F_57 ( & V_96 -> V_7 , L_22 ) ;
return 0 ;
}
static int T_5 F_58 ( struct V_95 * V_96 )
{
struct V_1 * V_2 = F_59 ( V_96 ) ;
int V_43 ;
F_60 ( V_2 -> V_82 , V_2 ) ;
F_61 ( V_2 -> V_7 , & V_107 ) ;
F_17 ( V_2 , - 1 ) ;
V_43 = F_7 ( V_2 , V_44 ) ;
if ( V_43 >= 0 ) {
V_43 |= V_58 ;
V_43 &= ~ ( V_59 | V_45 ) ;
F_5 ( V_2 , V_44 , ( T_1 ) V_43 ) ;
}
F_10 ( V_2 , V_36 , V_37 ) ;
if ( ! V_2 -> V_61 )
F_24 ( V_2 , 0 ) ;
F_33 ( V_2 -> V_57 ) ;
F_33 ( V_2 -> V_54 ) ;
F_33 ( V_2 -> V_53 ) ;
F_48 ( V_2 -> V_19 . V_18 ) ;
F_48 ( V_2 ) ;
return 0 ;
}
static int T_6 F_62 ( void )
{
return F_63 ( & V_111 ) ;
}
static void T_5 F_64 ( void )
{
F_65 ( & V_111 ) ;
}
