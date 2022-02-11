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
} else
V_15 = V_16 ;
F_4 ( V_2 -> V_7 , L_5 ,
V_14 , V_14 , V_15 ) ;
V_2 -> V_22 . V_23 = V_15 ;
F_15 ( & V_2 -> V_24 ) ;
V_2 -> V_15 = V_15 ;
if ( V_15 == V_20 ) {
V_2 -> V_22 . V_25 = true ;
V_2 -> V_22 . V_26 = V_27 ;
} else {
V_2 -> V_22 . V_25 = false ;
V_2 -> V_22 . V_26 = V_28 ;
}
F_16 ( & V_2 -> V_24 ) ;
return V_15 ;
}
static void F_17 ( struct V_1 * V_2 , int V_29 )
{
V_2 -> V_30 = V_29 ;
switch ( V_29 ) {
case V_31 :
F_10 ( V_2 , V_32 ,
V_33 ) ;
F_8 ( V_2 , V_34 , V_35 ) ;
F_10 ( V_2 , V_36 ,
V_37 |
V_38 ) ;
break;
case - 1 :
break;
default:
F_13 ( V_2 -> V_7 , L_6 ,
V_29 ) ;
break;
} ;
}
static void F_18 ( struct V_1 * V_2 , int V_39 )
{
unsigned long V_40 ;
int V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 >= 0 ) {
if ( V_39 ) {
V_41 |= V_43 ;
F_19 ( F_20 ( V_2 , V_42 ,
( T_1 ) V_41 ) < 0 ) ;
V_40 = V_44 + V_45 ;
while ( ! ( F_7 ( V_2 , V_46 ) &
V_47 )
&& F_21 ( V_44 , V_40 ) )
F_22 ( 10 ) ;
if ( ! ( F_7 ( V_2 , V_46 ) &
V_47 ) )
F_13 ( V_2 -> V_7 , L_7
L_8 ) ;
} else {
V_41 &= ~ V_43 ;
F_19 ( F_20 ( V_2 , V_42 ,
( T_1 ) V_41 ) < 0 ) ;
}
}
}
static void F_23 ( struct V_1 * V_2 , int V_39 )
{
T_1 V_48 = F_7 ( V_2 , V_49 ) ;
if ( V_39 )
V_48 &= ~ V_50 ;
else
V_48 |= V_50 ;
F_19 ( F_20 ( V_2 , V_49 , V_48 ) < 0 ) ;
}
static void F_24 ( struct V_1 * V_2 , int V_39 )
{
if ( V_39 ) {
F_25 ( V_2 -> V_51 ) ;
F_25 ( V_2 -> V_52 ) ;
F_2 ( V_53 , 0 ,
V_54 ) ;
F_25 ( V_2 -> V_55 ) ;
F_23 ( V_2 , 1 ) ;
F_5 ( V_2 , V_42 ,
F_7 ( V_2 , V_42 ) |
( V_56 |
V_57 ) ) ;
} else {
F_23 ( V_2 , 0 ) ;
F_26 ( V_2 -> V_55 ) ;
F_26 ( V_2 -> V_52 ) ;
F_26 ( V_2 -> V_51 ) ;
}
}
static void F_27 ( struct V_1 * V_2 , int V_58 )
{
if ( V_2 -> V_59 )
return;
F_24 ( V_2 , 0 ) ;
V_2 -> V_59 = 1 ;
F_4 ( V_2 -> V_7 , L_9 , V_60 ) ;
}
static void F_28 ( struct V_1 * V_2 )
{
F_24 ( V_2 , 1 ) ;
F_18 ( V_2 , 1 ) ;
F_17 ( V_2 , V_2 -> V_30 ) ;
if ( V_2 -> V_30 == V_31 )
F_18 ( V_2 , 0 ) ;
}
static void F_29 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_59 )
return;
F_28 ( V_2 ) ;
V_2 -> V_59 = 0 ;
F_4 ( V_2 -> V_7 , L_9 , V_60 ) ;
}
static int F_30 ( struct V_1 * V_2 )
{
F_2 ( V_18 ,
V_61 ,
V_62 ) ;
F_2 ( V_18 ,
V_63 ,
V_62 ) ;
F_2 ( V_53 , 0x14 , V_64 ) ;
F_2 ( V_53 , 0 , V_65 ) ;
V_2 -> V_51 = F_31 ( V_2 -> V_7 , L_10 ) ;
if ( F_32 ( V_2 -> V_51 ) )
return - V_66 ;
F_2 ( V_53 , 0 , V_67 ) ;
F_2 ( V_53 , 0 , V_68 ) ;
V_2 -> V_55 = F_31 ( V_2 -> V_7 , L_11 ) ;
if ( F_32 ( V_2 -> V_55 ) )
goto V_69;
F_2 ( V_53 , 0 , V_70 ) ;
F_2 ( V_53 , 0 , V_71 ) ;
V_2 -> V_52 = F_31 ( V_2 -> V_7 , L_12 ) ;
if ( F_32 ( V_2 -> V_52 ) )
goto V_72;
F_2 ( V_53 , 0 , V_73 ) ;
F_2 ( V_18 , 0 ,
V_62 ) ;
return 0 ;
V_72:
F_33 ( V_2 -> V_55 ) ;
V_2 -> V_55 = NULL ;
V_69:
F_33 ( V_2 -> V_51 ) ;
V_2 -> V_51 = NULL ;
return - V_66 ;
}
static T_2 F_34 ( struct V_74 * V_7 ,
struct V_75 * V_76 , char * V_77 )
{
struct V_1 * V_2 = F_35 ( V_7 ) ;
unsigned long V_78 ;
int V_9 = - V_79 ;
F_36 ( & V_2 -> V_24 , V_78 ) ;
V_9 = sprintf ( V_77 , L_9 ,
V_2 -> V_17 ? L_13 : L_14 ) ;
F_37 ( & V_2 -> V_24 , V_78 ) ;
return V_9 ;
}
static T_3 F_38 ( int V_80 , void * V_81 )
{
struct V_1 * V_2 = V_81 ;
int V_14 ;
V_14 = F_12 ( V_2 ) ;
if ( V_14 >= 0 ) {
if ( V_14 == V_16 )
F_27 ( V_2 , 0 ) ;
else
F_29 ( V_2 ) ;
F_39 ( & V_2 -> V_22 . V_82 , V_14 ,
V_2 -> V_22 . V_83 ) ;
}
F_40 ( & V_2 -> V_7 -> V_84 , NULL , L_15 ) ;
return V_85 ;
}
static void F_41 ( struct V_1 * V_2 )
{
int V_14 ;
V_14 = F_12 ( V_2 ) ;
if ( V_14 >= 0 ) {
if ( V_14 == V_16 ) {
F_23 ( V_2 , 0 ) ;
V_2 -> V_59 = 1 ;
} else {
F_28 ( V_2 ) ;
V_2 -> V_59 = 0 ;
}
F_39 ( & V_2 -> V_22 . V_82 , V_14 ,
V_2 -> V_22 . V_83 ) ;
}
F_40 ( & V_2 -> V_7 -> V_84 , NULL , L_15 ) ;
}
static int F_42 ( struct V_86 * V_87 , int V_88 )
{
struct V_1 * V_2 = F_43 ( V_87 ) ;
if ( V_88 )
F_27 ( V_2 , 1 ) ;
else
F_29 ( V_2 ) ;
return 0 ;
}
static int F_44 ( struct V_86 * V_87 ,
struct V_89 * V_83 )
{
struct V_1 * V_2 ;
if ( ! V_87 )
return - V_66 ;
V_2 = F_43 ( V_87 ) ;
V_2 -> V_22 . V_83 = V_83 ;
if ( ! V_83 )
V_2 -> V_22 . V_26 = V_90 ;
return 0 ;
}
static int F_45 ( struct V_86 * V_87 , struct V_91 * V_92 )
{
struct V_1 * V_2 ;
if ( ! V_87 )
return - V_66 ;
V_2 = F_43 ( V_87 ) ;
V_2 -> V_22 . V_92 = V_92 ;
if ( ! V_92 )
V_2 -> V_22 . V_26 = V_90 ;
return 0 ;
}
static int T_4 F_46 ( struct V_93 * V_94 )
{
struct V_95 * V_96 = V_94 -> V_7 . V_97 ;
struct V_1 * V_2 ;
int V_14 , V_98 ;
if ( ! V_96 ) {
F_4 ( & V_94 -> V_7 , L_16 ) ;
return - V_79 ;
}
V_2 = F_47 ( sizeof *V_2 , V_99 ) ;
if ( ! V_2 )
return - V_100 ;
V_2 -> V_7 = & V_94 -> V_7 ;
V_2 -> V_80 = F_48 ( V_94 , 0 ) ;
V_2 -> V_22 . V_7 = V_2 -> V_7 ;
V_2 -> V_22 . V_101 = L_17 ;
V_2 -> V_22 . V_102 = F_45 ;
V_2 -> V_22 . V_103 = F_44 ;
V_2 -> V_22 . V_104 = F_42 ;
V_2 -> V_30 = V_96 -> V_30 ;
V_2 -> V_17 = false ;
V_2 -> V_59 = 1 ;
F_49 ( & V_2 -> V_24 ) ;
V_98 = F_30 ( V_2 ) ;
if ( V_98 ) {
F_13 ( & V_94 -> V_7 , L_18 ) ;
F_50 ( V_2 ) ;
return V_98 ;
}
F_51 ( & V_2 -> V_22 ) ;
F_52 ( V_94 , V_2 ) ;
if ( F_53 ( & V_94 -> V_7 , & V_105 ) )
F_54 ( & V_94 -> V_7 , L_19 ) ;
F_55 ( & V_2 -> V_22 . V_82 ) ;
V_2 -> V_106 = true ;
V_14 = F_56 ( V_2 -> V_80 , NULL , F_38 ,
V_107 | V_108 ,
L_20 , V_2 ) ;
if ( V_14 < 0 ) {
F_4 ( & V_94 -> V_7 , L_21 ,
V_2 -> V_80 , V_14 ) ;
F_50 ( V_2 ) ;
return V_14 ;
}
F_41 ( V_2 ) ;
F_57 ( & V_94 -> V_7 , L_22 ) ;
return 0 ;
}
static int T_5 F_58 ( struct V_93 * V_94 )
{
struct V_1 * V_2 = F_59 ( V_94 ) ;
int V_41 ;
F_60 ( V_2 -> V_80 , V_2 ) ;
F_61 ( V_2 -> V_7 , & V_105 ) ;
F_17 ( V_2 , - 1 ) ;
V_41 = F_7 ( V_2 , V_42 ) ;
if ( V_41 >= 0 ) {
V_41 |= V_56 ;
V_41 &= ~ ( V_57 | V_43 ) ;
F_5 ( V_2 , V_42 , ( T_1 ) V_41 ) ;
}
F_10 ( V_2 , V_34 , V_35 ) ;
if ( ! V_2 -> V_59 )
F_24 ( V_2 , 0 ) ;
F_33 ( V_2 -> V_55 ) ;
F_33 ( V_2 -> V_52 ) ;
F_33 ( V_2 -> V_51 ) ;
F_50 ( V_2 ) ;
return 0 ;
}
static int T_6 F_62 ( void )
{
return F_63 ( & V_109 ) ;
}
static void T_5 F_64 ( void )
{
F_65 ( & V_109 ) ;
}
