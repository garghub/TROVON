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
static void F_18 ( struct V_1 * V_1 , bool V_24 , bool V_25 )
{
struct V_26 * V_27 = V_1 -> V_16 ;
struct V_28 * V_29 = F_19 ( V_27 -> V_30 ) ;
bool V_31 ;
int V_32 ;
if ( V_29 -> V_24 != V_24 )
V_29 -> V_24 = V_24 ;
if ( V_29 -> V_33 != V_25 )
V_29 -> V_33 = V_25 ;
V_31 = V_29 -> V_24 && V_29 -> V_33 ;
if ( V_31 == V_29 -> V_34 ) {
F_20 ( V_1 -> V_16 , L_4 ,
V_31 ) ;
return;
}
V_29 -> V_34 = V_31 ;
if ( V_31 ) {
V_32 = F_21 ( V_1 -> V_16 ) ;
if ( V_32 < 0 ) {
F_8 ( V_1 -> V_16 , L_5 , V_32 ) ;
V_29 -> V_34 = false ;
}
} else {
F_22 ( V_1 -> V_16 ) ;
F_23 ( V_1 -> V_16 ) ;
}
}
static int F_24 ( enum V_35 V_36 )
{
struct V_28 * V_29 = V_37 ;
if ( ! V_29 ) {
F_25 ( L_6 , V_38 ) ;
return - V_39 ;
}
V_29 -> V_36 = V_36 ;
if ( ! F_26 ( V_29 ) ) {
F_25 ( L_7 , V_38 ) ;
return - V_39 ;
}
F_27 ( & V_29 -> V_40 ) ;
return 0 ;
}
static void F_28 ( struct V_28 * V_29 )
{
struct V_1 * V_1 = F_26 ( V_29 ) ;
struct V_26 * V_27 = V_1 -> V_16 ;
struct V_41 * V_42 = F_29 ( V_27 ) ;
struct V_43 * V_44 = V_42 -> V_45 ;
struct V_3 * V_4 = V_1 -> V_5 -> V_4 ;
bool V_33 ;
V_33 = ( ( V_29 -> V_36 == V_46 ) ||
( V_29 -> V_36 == V_47 ) ) ;
if ( V_33 )
F_18 ( V_1 , V_29 -> V_24 , V_33 ) ;
switch ( V_29 -> V_36 ) {
case V_46 :
F_12 ( V_27 , L_8 ) ;
V_4 -> V_18 = true ;
V_1 -> V_5 -> V_4 -> V_11 = V_12 ;
V_1 -> V_5 -> V_48 = V_49 ;
if ( V_1 -> V_50 ) {
F_30 ( V_29 -> V_51 ,
V_52 ) ;
F_1 ( V_1 , 1 ) ;
}
break;
case V_47 :
F_12 ( V_27 , L_9 ) ;
V_4 -> V_18 = false ;
V_1 -> V_5 -> V_4 -> V_11 = V_20 ;
V_1 -> V_5 -> V_48 = V_53 ;
F_30 ( V_29 -> V_51 , V_54 ) ;
break;
case V_55 :
case V_56 :
F_12 ( V_27 , L_10 ) ;
V_1 -> V_5 -> V_48 = V_57 ;
if ( V_1 -> V_50 )
F_1 ( V_1 , 0 ) ;
if ( V_44 -> V_58 == V_59 )
F_9 ( V_1 -> V_5 -> V_4 , 0 ) ;
F_30 ( V_29 -> V_51 ,
V_60 ) ;
break;
default:
F_12 ( V_27 , L_11 ) ;
}
if ( ! V_33 )
F_18 ( V_1 , V_29 -> V_24 , V_33 ) ;
F_31 ( & V_1 -> V_5 -> V_61 ,
V_1 -> V_5 -> V_48 , NULL ) ;
}
static void V_40 ( struct V_62 * V_63 )
{
struct V_28 * V_29 = F_32 ( V_63 ,
struct V_28 , V_40 ) ;
F_28 ( V_29 ) ;
}
static T_3 F_33 ( int V_64 , void * V_65 )
{
unsigned long V_66 ;
T_3 V_67 = V_68 ;
struct V_1 * V_1 = V_65 ;
F_34 ( & V_1 -> V_69 , V_66 ) ;
V_1 -> V_70 = F_3 ( V_1 -> V_9 , V_71 ) ;
V_1 -> V_72 = F_35 ( V_1 -> V_9 , V_73 ) ;
V_1 -> V_74 = F_35 ( V_1 -> V_9 , V_75 ) ;
if ( V_1 -> V_70 || V_1 -> V_72 || V_1 -> V_74 )
V_67 = F_36 ( V_1 ) ;
F_37 ( & V_1 -> V_69 , V_66 ) ;
return V_67 ;
}
static int F_38 ( struct V_1 * V_1 )
{
T_2 V_21 ;
int V_36 = 0 ;
struct V_26 * V_27 = V_1 -> V_16 ;
struct V_28 * V_29 = F_19 ( V_27 -> V_30 ) ;
struct V_41 * V_76 = F_29 ( V_27 ) ;
struct V_43 * V_44 = V_76 -> V_45 ;
if ( V_27 -> V_30 -> V_77 ) {
V_1 -> V_78 = F_39 ( V_27 -> V_30 , L_12 ) ;
V_1 -> V_5 = F_40 ( V_27 -> V_30 ,
L_13 , 0 ) ;
} else {
V_1 -> V_5 = F_41 ( V_27 , 0 ) ;
V_1 -> V_78 = F_39 ( V_27 , L_14 ) ;
}
if ( F_42 ( V_1 -> V_5 ) ) {
V_36 = F_43 ( V_1 -> V_5 ) ;
if ( V_36 == - V_79 )
return V_36 ;
F_25 ( L_15 ) ;
return - V_39 ;
}
if ( F_42 ( V_1 -> V_78 ) ) {
F_25 ( L_16 ) ;
return F_43 ( V_1 -> V_78 ) ;
}
V_1 -> V_80 = F_33 ;
F_44 ( V_1 -> V_78 ) ;
V_21 = F_15 ( V_1 -> V_9 , V_81 ) ;
if ( V_44 -> V_58 == V_59 ) {
V_21 &= ~ V_82 ;
V_21 |= V_83 ;
} else {
V_21 |= V_82 ;
}
F_16 ( V_1 -> V_9 , V_81 , V_21 ) ;
F_45 ( L_17
L_18 ,
F_15 ( V_1 -> V_9 , V_84 ) ,
F_15 ( V_1 -> V_9 , V_85 ) ,
F_15 ( V_1 -> V_9 , V_86 ) ,
F_15 ( V_1 -> V_9 , V_81 ) ,
F_15 ( V_1 -> V_9 , V_87 ) ) ;
if ( V_29 -> V_36 != V_88 )
F_28 ( V_29 ) ;
return 0 ;
}
static void F_46 ( struct V_1 * V_1 )
{
T_1 V_6 ;
unsigned long V_7 = V_8 + F_2 ( 1000 ) ;
struct V_26 * V_27 = V_1 -> V_16 ;
struct V_28 * V_29 = F_19 ( V_27 -> V_30 ) ;
struct V_41 * V_42 = F_29 ( V_27 ) ;
struct V_43 * V_44 = V_42 -> V_45 ;
if ( ! F_47 ( ! V_1 -> V_78 ) )
F_48 ( V_1 -> V_78 ) ;
F_18 ( V_1 , true , V_29 -> V_33 ) ;
switch ( V_29 -> V_36 ) {
case V_46 :
F_30 ( V_29 -> V_51 , V_52 ) ;
if ( V_44 -> V_58 != V_59 )
break;
V_6 = F_3 ( V_1 -> V_9 , V_10 ) ;
V_6 |= V_14 ;
F_4 ( V_1 -> V_9 , V_10 , V_6 ) ;
while ( F_3 ( V_1 -> V_9 , V_10 ) &
V_15 ) {
F_6 () ;
if ( F_7 ( V_8 , V_7 ) ) {
F_8 ( V_27 , L_1 ) ;
break;
}
}
break;
case V_47 :
F_30 ( V_29 -> V_51 , V_54 ) ;
break;
default:
break;
}
}
static void F_49 ( struct V_1 * V_1 )
{
struct V_26 * V_27 = V_1 -> V_16 ;
struct V_28 * V_29 = F_19 ( V_27 -> V_30 ) ;
if ( ! F_47 ( ! V_1 -> V_78 ) )
F_50 ( V_1 -> V_78 ) ;
if ( V_29 -> V_36 != V_88 )
F_30 ( V_29 -> V_51 ,
V_60 ) ;
F_18 ( V_1 , false , V_29 -> V_33 ) ;
}
static int F_51 ( struct V_1 * V_1 )
{
struct V_26 * V_27 = V_1 -> V_16 ;
struct V_28 * V_29 = F_19 ( V_27 -> V_30 ) ;
F_14 ( V_1 ) ;
F_52 ( V_1 -> V_78 ) ;
V_1 -> V_78 = NULL ;
F_53 ( & V_29 -> V_40 ) ;
return 0 ;
}
static int F_54 ( struct V_89 * V_90 )
{
struct V_91 V_92 [ 3 ] ;
struct V_41 * V_42 = F_29 ( & V_90 -> V_27 ) ;
struct V_43 * V_44 ;
struct V_89 * V_1 ;
struct V_28 * V_29 ;
struct V_93 * V_94 = V_90 -> V_27 . V_77 ;
struct V_95 * V_96 ;
int V_97 = - V_98 , V_99 ;
V_29 = F_55 ( & V_90 -> V_27 , sizeof( * V_29 ) , V_100 ) ;
if ( ! V_29 )
goto V_101;
V_1 = F_56 ( L_19 , V_102 ) ;
if ( ! V_1 ) {
F_8 ( & V_90 -> V_27 , L_20 ) ;
goto V_101;
}
V_1 -> V_27 . V_30 = & V_90 -> V_27 ;
V_1 -> V_27 . V_103 = & V_104 ;
V_1 -> V_27 . V_105 = V_104 ;
V_29 -> V_27 = & V_90 -> V_27 ;
V_29 -> V_1 = V_1 ;
V_29 -> V_36 = V_88 ;
V_29 -> V_51 = F_57 ( - V_106 ) ;
if ( V_94 ) {
struct V_93 * V_107 ;
struct V_89 * V_108 ;
V_42 = F_55 ( & V_90 -> V_27 , sizeof( * V_42 ) , V_100 ) ;
if ( ! V_42 )
goto V_109;
V_44 = F_55 ( & V_90 -> V_27 , sizeof( * V_44 ) , V_100 ) ;
if ( ! V_44 )
goto V_109;
V_96 = F_55 ( & V_90 -> V_27 , sizeof( * V_96 ) , V_100 ) ;
if ( ! V_96 )
goto V_109;
F_58 ( V_94 , L_21 , ( T_2 * ) & V_42 -> V_110 ) ;
F_58 ( V_94 , L_22 ,
( T_2 * ) & V_44 -> V_58 ) ;
F_58 ( V_94 , L_23 , ( T_2 * ) & V_96 -> V_111 ) ;
F_58 ( V_94 , L_24 , ( T_2 * ) & V_96 -> V_112 ) ;
F_58 ( V_94 , L_25 , ( T_2 * ) & V_42 -> V_113 ) ;
V_97 = F_58 ( V_94 , L_26 , & V_99 ) ;
if ( ! V_97 && V_99 )
V_96 -> V_114 = true ;
V_42 -> V_45 = V_44 ;
V_42 -> V_96 = V_96 ;
V_107 = F_59 ( V_94 , L_27 , 0 ) ;
if ( V_107 ) {
V_108 = F_60 ( V_107 ) ;
if ( ! V_108 ) {
F_8 ( & V_90 -> V_27 , L_28 ) ;
V_97 = - V_115 ;
goto V_109;
}
V_29 -> V_51 = & V_108 -> V_27 ;
}
}
V_42 -> V_116 = & V_117 ;
F_61 ( V_90 , V_29 ) ;
V_37 = V_29 ;
F_62 ( & V_29 -> V_40 , V_40 ) ;
memset ( V_92 , 0x00 , sizeof( * V_92 ) *
F_63 ( V_92 ) ) ;
V_92 [ 0 ] . V_118 = V_90 -> V_91 [ 0 ] . V_118 ;
V_92 [ 0 ] . V_119 = V_90 -> V_91 [ 0 ] . V_119 ;
V_92 [ 0 ] . V_120 = V_90 -> V_91 [ 0 ] . V_120 ;
V_92 [ 0 ] . V_66 = V_90 -> V_91 [ 0 ] . V_66 ;
V_92 [ 1 ] . V_118 = V_90 -> V_91 [ 1 ] . V_118 ;
V_92 [ 1 ] . V_119 = V_90 -> V_91 [ 1 ] . V_119 ;
V_92 [ 1 ] . V_120 = V_90 -> V_91 [ 1 ] . V_120 ;
V_92 [ 1 ] . V_66 = V_90 -> V_91 [ 1 ] . V_66 ;
V_92 [ 2 ] . V_118 = V_90 -> V_91 [ 2 ] . V_118 ;
V_92 [ 2 ] . V_119 = V_90 -> V_91 [ 2 ] . V_119 ;
V_92 [ 2 ] . V_120 = V_90 -> V_91 [ 2 ] . V_120 ;
V_92 [ 2 ] . V_66 = V_90 -> V_91 [ 2 ] . V_66 ;
V_97 = F_64 ( V_1 , V_92 ,
F_63 ( V_92 ) ) ;
if ( V_97 ) {
F_8 ( & V_90 -> V_27 , L_29 ) ;
goto V_109;
}
V_97 = F_65 ( V_1 , V_42 , sizeof( * V_42 ) ) ;
if ( V_97 ) {
F_8 ( & V_90 -> V_27 , L_30 ) ;
goto V_109;
}
F_66 ( V_29 -> V_27 ) ;
F_67 ( V_29 -> V_27 ) ;
F_68 ( V_29 -> V_27 , 500 ) ;
V_97 = F_69 ( V_1 ) ;
if ( V_97 ) {
F_8 ( & V_90 -> V_27 , L_31 ) ;
goto V_109;
}
return 0 ;
V_109:
F_70 ( V_1 ) ;
V_101:
return V_97 ;
}
static int F_71 ( struct V_89 * V_90 )
{
struct V_28 * V_29 = F_72 ( V_90 ) ;
struct V_1 * V_1 = F_26 ( V_29 ) ;
F_21 ( V_29 -> V_27 ) ;
F_73 ( V_29 -> V_1 ) ;
F_18 ( V_1 , false , false ) ;
F_74 ( V_29 -> V_27 ) ;
F_75 ( V_29 -> V_27 ) ;
F_76 ( V_29 -> V_27 ) ;
return 0 ;
}
static int F_77 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_19 ( V_27 ) ;
struct V_1 * V_1 = F_26 ( V_29 ) ;
if ( ! V_1 )
return 0 ;
V_1 -> V_121 . V_122 = F_15 ( V_1 -> V_9 ,
V_81 ) ;
F_14 ( V_1 ) ;
return 0 ;
}
static int F_78 ( struct V_26 * V_27 )
{
struct V_28 * V_29 = F_19 ( V_27 ) ;
struct V_1 * V_1 = F_26 ( V_29 ) ;
if ( ! V_1 )
return 0 ;
F_17 ( V_1 ) ;
F_16 ( V_1 -> V_9 , V_81 ,
V_1 -> V_121 . V_122 ) ;
return 0 ;
}
