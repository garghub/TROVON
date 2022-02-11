static void F_1 ( struct V_1 * V_1 , int V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 -> V_4 ;
T_1 V_6 ;
unsigned long V_7 = V_8 + F_2 ( 1000 ) ;
V_6 = F_3 ( V_1 -> V_9 , V_10 ) ;
if ( V_2 ) {
if ( V_1 -> V_5 -> V_4 -> V_11 == V_12 ) {
int V_13 = 100 ;
V_6 |= V_14 ;
F_4 ( V_1 -> V_9 , V_10 , V_6 ) ;
while ( F_3 ( V_1 -> V_9 , V_10 ) &
V_15 ) {
F_5 ( 5 ) ;
F_6 () ;
if ( F_7 ( V_8 , V_7 )
|| V_13 -- <= 0 ) {
F_8 ( V_1 -> V_16 ,
L_1 ) ;
break;
}
}
F_9 ( V_4 , 1 ) ;
} else {
V_1 -> V_17 = 1 ;
V_4 -> V_18 = 1 ;
V_1 -> V_5 -> V_4 -> V_11 = V_19 ;
V_6 |= V_14 ;
F_10 ( V_1 ) ;
}
} else {
V_1 -> V_17 = 0 ;
V_4 -> V_18 = 0 ;
V_1 -> V_5 -> V_4 -> V_11 = V_20 ;
V_6 &= ~ V_14 ;
F_11 ( V_1 ) ;
}
F_4 ( V_1 -> V_9 , V_10 , V_6 ) ;
F_12 ( V_1 -> V_16 , L_2
L_3 ,
F_13 ( V_1 -> V_5 -> V_4 -> V_11 ) ,
F_3 ( V_1 -> V_9 , V_10 ) ) ;
}
static inline void F_14 ( struct V_1 * V_1 )
{
T_2 V_21 ;
V_21 = F_15 ( V_1 -> V_9 , V_22 ) ;
V_21 |= V_23 ;
F_16 ( V_1 -> V_9 , V_22 , V_21 ) ;
}
static inline void F_17 ( struct V_1 * V_1 )
{
T_2 V_21 ;
V_21 = F_15 ( V_1 -> V_9 , V_22 ) ;
V_21 &= ~ V_23 ;
F_16 ( V_1 -> V_9 , V_22 , V_21 ) ;
}
static int F_18 ( enum V_24 V_25 )
{
struct V_26 * V_27 = V_28 ;
if ( ! V_27 ) {
F_19 ( L_4 , V_29 ) ;
return - V_30 ;
}
V_27 -> V_25 = V_25 ;
if ( ! F_20 ( V_27 ) ) {
F_19 ( L_5 , V_29 ) ;
return - V_30 ;
}
F_21 ( & V_27 -> V_31 ) ;
return 0 ;
}
static void F_22 ( struct V_26 * V_27 )
{
struct V_1 * V_1 = F_20 ( V_27 ) ;
struct V_32 * V_33 =
F_23 ( V_1 -> V_16 ) ;
struct V_34 * V_35 = V_33 -> V_36 ;
struct V_3 * V_4 = V_1 -> V_5 -> V_4 ;
F_24 ( V_1 -> V_16 ) ;
switch ( V_27 -> V_25 ) {
case V_37 :
F_12 ( V_1 -> V_16 , L_6 ) ;
V_4 -> V_18 = true ;
V_1 -> V_5 -> V_4 -> V_11 = V_12 ;
V_1 -> V_5 -> V_38 = V_39 ;
if ( V_1 -> V_40 ) {
F_25 ( V_27 -> V_41 ,
V_42 ) ;
F_1 ( V_1 , 1 ) ;
}
break;
case V_43 :
F_12 ( V_1 -> V_16 , L_7 ) ;
V_4 -> V_18 = false ;
V_1 -> V_5 -> V_4 -> V_11 = V_20 ;
V_1 -> V_5 -> V_38 = V_44 ;
F_25 ( V_27 -> V_41 , V_45 ) ;
break;
case V_46 :
case V_47 :
F_12 ( V_1 -> V_16 , L_8 ) ;
V_1 -> V_5 -> V_38 = V_48 ;
if ( V_1 -> V_40 )
F_1 ( V_1 , 0 ) ;
if ( V_35 -> V_49 == V_50 )
F_9 ( V_1 -> V_5 -> V_4 , 0 ) ;
F_25 ( V_27 -> V_41 ,
V_51 ) ;
break;
default:
F_12 ( V_1 -> V_16 , L_9 ) ;
}
F_26 ( V_1 -> V_16 ) ;
F_27 ( V_1 -> V_16 ) ;
F_28 ( & V_1 -> V_5 -> V_52 ,
V_1 -> V_5 -> V_38 , NULL ) ;
}
static void V_31 ( struct V_53 * V_54 )
{
struct V_26 * V_27 = F_29 ( V_54 ,
struct V_26 , V_31 ) ;
F_22 ( V_27 ) ;
}
static T_3 F_30 ( int V_55 , void * V_56 )
{
unsigned long V_57 ;
T_3 V_58 = V_59 ;
struct V_1 * V_1 = V_56 ;
F_31 ( & V_1 -> V_60 , V_57 ) ;
V_1 -> V_61 = F_3 ( V_1 -> V_9 , V_62 ) ;
V_1 -> V_63 = F_32 ( V_1 -> V_9 , V_64 ) ;
V_1 -> V_65 = F_32 ( V_1 -> V_9 , V_66 ) ;
if ( V_1 -> V_61 || V_1 -> V_63 || V_1 -> V_65 )
V_58 = F_33 ( V_1 ) ;
F_34 ( & V_1 -> V_60 , V_57 ) ;
return V_58 ;
}
static int F_35 ( struct V_1 * V_1 )
{
T_2 V_21 ;
int V_25 = 0 ;
struct V_67 * V_68 = V_1 -> V_16 ;
struct V_26 * V_27 = F_36 ( V_68 -> V_69 ) ;
struct V_32 * V_70 = F_23 ( V_68 ) ;
struct V_34 * V_35 = V_70 -> V_36 ;
if ( V_68 -> V_69 -> V_71 ) {
V_1 -> V_72 = F_37 ( V_68 -> V_69 , L_10 ) ;
V_1 -> V_5 = F_38 ( V_68 -> V_69 ,
L_11 , 0 ) ;
} else {
V_1 -> V_5 = F_39 ( V_68 , 0 ) ;
V_1 -> V_72 = F_37 ( V_68 , L_12 ) ;
}
if ( F_40 ( V_1 -> V_5 ) ) {
V_25 = F_41 ( V_1 -> V_5 ) ;
if ( V_25 == - V_73 )
return V_25 ;
F_19 ( L_13 ) ;
return - V_30 ;
}
if ( F_40 ( V_1 -> V_72 ) ) {
F_19 ( L_14 ) ;
return F_41 ( V_1 -> V_72 ) ;
}
V_1 -> V_74 = F_30 ;
F_42 ( V_1 -> V_72 ) ;
F_43 ( V_1 -> V_72 ) ;
V_21 = F_15 ( V_1 -> V_9 , V_75 ) ;
if ( V_35 -> V_49 == V_50 ) {
V_21 &= ~ V_76 ;
V_21 |= V_77 ;
} else {
V_21 |= V_76 ;
}
F_16 ( V_1 -> V_9 , V_75 , V_21 ) ;
F_44 ( L_15
L_16 ,
F_15 ( V_1 -> V_9 , V_78 ) ,
F_15 ( V_1 -> V_9 , V_79 ) ,
F_15 ( V_1 -> V_9 , V_80 ) ,
F_15 ( V_1 -> V_9 , V_75 ) ,
F_15 ( V_1 -> V_9 , V_81 ) ) ;
if ( V_27 -> V_25 != V_82 )
F_22 ( V_27 ) ;
return 0 ;
}
static void F_45 ( struct V_1 * V_1 )
{
T_1 V_6 ;
unsigned long V_7 = V_8 + F_2 ( 1000 ) ;
struct V_67 * V_68 = V_1 -> V_16 ;
struct V_26 * V_27 = F_36 ( V_68 -> V_69 ) ;
struct V_32 * V_33 = F_23 ( V_68 ) ;
struct V_34 * V_35 = V_33 -> V_36 ;
switch ( V_27 -> V_25 ) {
case V_37 :
F_25 ( V_27 -> V_41 , V_42 ) ;
if ( V_35 -> V_49 != V_50 )
break;
V_6 = F_3 ( V_1 -> V_9 , V_10 ) ;
V_6 |= V_14 ;
F_4 ( V_1 -> V_9 , V_10 , V_6 ) ;
while ( F_3 ( V_1 -> V_9 , V_10 ) &
V_15 ) {
F_6 () ;
if ( F_7 ( V_8 , V_7 ) ) {
F_8 ( V_68 , L_1 ) ;
break;
}
}
break;
case V_43 :
F_25 ( V_27 -> V_41 , V_45 ) ;
break;
default:
break;
}
}
static void F_46 ( struct V_1 * V_1 )
{
struct V_67 * V_68 = V_1 -> V_16 ;
struct V_26 * V_27 = F_36 ( V_68 -> V_69 ) ;
if ( V_27 -> V_25 != V_82 )
F_25 ( V_27 -> V_41 ,
V_51 ) ;
}
static int F_47 ( struct V_1 * V_1 )
{
struct V_67 * V_68 = V_1 -> V_16 ;
struct V_26 * V_27 = F_36 ( V_68 -> V_69 ) ;
F_14 ( V_1 ) ;
F_48 ( V_1 -> V_72 ) ;
F_49 ( V_1 -> V_72 ) ;
V_1 -> V_72 = NULL ;
F_50 ( & V_27 -> V_31 ) ;
return 0 ;
}
static int F_51 ( struct V_83 * V_84 )
{
struct V_85 V_86 [ 3 ] ;
struct V_32 * V_33 = F_23 ( & V_84 -> V_68 ) ;
struct V_34 * V_35 ;
struct V_83 * V_1 ;
struct V_26 * V_27 ;
struct V_87 * V_88 = V_84 -> V_68 . V_71 ;
struct V_89 * V_90 ;
int V_91 = - V_92 , V_93 ;
V_27 = F_52 ( & V_84 -> V_68 , sizeof( * V_27 ) , V_94 ) ;
if ( ! V_27 )
goto V_95;
V_1 = F_53 ( L_17 , V_96 ) ;
if ( ! V_1 ) {
F_8 ( & V_84 -> V_68 , L_18 ) ;
goto V_95;
}
V_1 -> V_68 . V_69 = & V_84 -> V_68 ;
V_1 -> V_68 . V_97 = & V_98 ;
V_1 -> V_68 . V_99 = V_98 ;
V_27 -> V_68 = & V_84 -> V_68 ;
V_27 -> V_1 = V_1 ;
V_27 -> V_25 = V_82 ;
V_27 -> V_41 = F_54 ( - V_100 ) ;
if ( V_88 ) {
struct V_87 * V_101 ;
struct V_83 * V_102 ;
V_33 = F_52 ( & V_84 -> V_68 , sizeof( * V_33 ) , V_94 ) ;
if ( ! V_33 )
goto V_103;
V_35 = F_52 ( & V_84 -> V_68 , sizeof( * V_35 ) , V_94 ) ;
if ( ! V_35 )
goto V_103;
V_90 = F_52 ( & V_84 -> V_68 , sizeof( * V_90 ) , V_94 ) ;
if ( ! V_90 )
goto V_103;
F_55 ( V_88 , L_19 , ( T_2 * ) & V_33 -> V_104 ) ;
F_55 ( V_88 , L_20 ,
( T_2 * ) & V_35 -> V_49 ) ;
F_55 ( V_88 , L_21 , ( T_2 * ) & V_90 -> V_105 ) ;
F_55 ( V_88 , L_22 , ( T_2 * ) & V_90 -> V_106 ) ;
F_55 ( V_88 , L_23 , ( T_2 * ) & V_33 -> V_107 ) ;
V_91 = F_55 ( V_88 , L_24 , & V_93 ) ;
if ( ! V_91 && V_93 )
V_90 -> V_108 = true ;
V_33 -> V_36 = V_35 ;
V_33 -> V_90 = V_90 ;
V_101 = F_56 ( V_88 , L_25 , 0 ) ;
if ( V_101 ) {
V_102 = F_57 ( V_101 ) ;
if ( ! V_102 ) {
F_8 ( & V_84 -> V_68 , L_26 ) ;
V_91 = - V_109 ;
goto V_103;
}
V_27 -> V_41 = & V_102 -> V_68 ;
}
}
V_33 -> V_110 = & V_111 ;
F_58 ( V_84 , V_27 ) ;
V_28 = V_27 ;
F_59 ( & V_27 -> V_31 , V_31 ) ;
memset ( V_86 , 0x00 , sizeof( * V_86 ) *
F_60 ( V_86 ) ) ;
V_86 [ 0 ] . V_112 = V_84 -> V_85 [ 0 ] . V_112 ;
V_86 [ 0 ] . V_113 = V_84 -> V_85 [ 0 ] . V_113 ;
V_86 [ 0 ] . V_114 = V_84 -> V_85 [ 0 ] . V_114 ;
V_86 [ 0 ] . V_57 = V_84 -> V_85 [ 0 ] . V_57 ;
V_86 [ 1 ] . V_112 = V_84 -> V_85 [ 1 ] . V_112 ;
V_86 [ 1 ] . V_113 = V_84 -> V_85 [ 1 ] . V_113 ;
V_86 [ 1 ] . V_114 = V_84 -> V_85 [ 1 ] . V_114 ;
V_86 [ 1 ] . V_57 = V_84 -> V_85 [ 1 ] . V_57 ;
V_86 [ 2 ] . V_112 = V_84 -> V_85 [ 2 ] . V_112 ;
V_86 [ 2 ] . V_113 = V_84 -> V_85 [ 2 ] . V_113 ;
V_86 [ 2 ] . V_114 = V_84 -> V_85 [ 2 ] . V_114 ;
V_86 [ 2 ] . V_57 = V_84 -> V_85 [ 2 ] . V_57 ;
V_91 = F_61 ( V_1 , V_86 ,
F_60 ( V_86 ) ) ;
if ( V_91 ) {
F_8 ( & V_84 -> V_68 , L_27 ) ;
goto V_103;
}
V_91 = F_62 ( V_1 , V_33 , sizeof( * V_33 ) ) ;
if ( V_91 ) {
F_8 ( & V_84 -> V_68 , L_28 ) ;
goto V_103;
}
F_63 ( V_27 -> V_68 ) ;
V_91 = F_64 ( V_1 ) ;
if ( V_91 ) {
F_8 ( & V_84 -> V_68 , L_29 ) ;
goto V_115;
}
return 0 ;
V_115:
F_65 ( V_27 -> V_68 ) ;
V_103:
F_66 ( V_1 ) ;
V_95:
return V_91 ;
}
static int F_67 ( struct V_83 * V_84 )
{
struct V_26 * V_27 = F_68 ( V_84 ) ;
F_69 ( V_27 -> V_1 ) ;
F_65 ( V_27 -> V_68 ) ;
return 0 ;
}
static int F_70 ( struct V_67 * V_68 )
{
struct V_26 * V_27 = F_36 ( V_68 ) ;
struct V_1 * V_1 = F_20 ( V_27 ) ;
if ( ! V_1 )
return 0 ;
V_1 -> V_116 . V_117 = F_15 ( V_1 -> V_9 ,
V_75 ) ;
F_14 ( V_1 ) ;
return 0 ;
}
static int F_71 ( struct V_67 * V_68 )
{
struct V_26 * V_27 = F_36 ( V_68 ) ;
struct V_1 * V_1 = F_20 ( V_27 ) ;
if ( ! V_1 )
return 0 ;
F_17 ( V_1 ) ;
F_16 ( V_1 -> V_9 , V_75 ,
V_1 -> V_116 . V_117 ) ;
return 0 ;
}
