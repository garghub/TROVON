static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
char * V_6 ;
unsigned V_7 , V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
V_6 = V_5 ;
V_7 = V_11 ;
V_8 = F_3 ( V_6 , V_7 , L_1 , V_10 -> V_12 . V_13 ) ;
V_7 -= V_8 ;
V_6 += V_8 ;
return V_11 - V_7 ;
}
static T_1
F_4 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_14 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_14 > 2 )
return - 1 ;
F_5 ( & V_10 -> V_12 . V_15 ) ;
if ( V_5 [ 0 ] == '0' ) {
V_10 -> V_12 . V_13 = 0 ;
} else if ( V_5 [ 0 ] == '1' ) {
if ( V_10 -> V_12 . V_16 ) {
F_6 ( & V_10 -> V_12 . V_15 ) ;
return V_14 ;
}
V_10 -> V_12 . V_13 = 1 ;
if ( V_10 -> V_12 . V_17 -> V_18 == V_19 ) {
V_10 -> V_20 . V_21 = 1 ;
F_6 ( & V_10 -> V_12 . V_15 ) ;
return V_14 ;
}
}
F_7 ( V_10 ) ;
F_6 ( & V_10 -> V_12 . V_15 ) ;
return V_14 ;
}
static T_1
F_8 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
char * V_6 ;
unsigned V_7 , V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
V_6 = V_5 ;
V_7 = V_11 ;
V_8 = F_3 ( V_6 , V_7 , L_1 , V_10 -> V_12 . V_16 ) ;
V_7 -= V_8 ;
V_6 += V_8 ;
return V_11 - V_7 ;
}
static T_1
F_9 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_14 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_14 > 2 )
return - 1 ;
F_5 ( & V_10 -> V_12 . V_15 ) ;
if ( V_5 [ 0 ] == '0' ) {
V_10 -> V_12 . V_16 = 0 ;
} else if ( V_5 [ 0 ] == '1' ) {
V_10 -> V_12 . V_16 = 1 ;
V_10 -> V_12 . V_13 = 0 ;
}
F_7 ( V_10 ) ;
F_6 ( & V_10 -> V_12 . V_15 ) ;
return V_14 ;
}
static T_1
F_10 ( struct V_1 * V_2 , struct V_3 * V_4 , char * V_5 )
{
char * V_6 ;
unsigned V_7 , V_8 ;
struct V_9 * V_10 = F_2 ( V_2 ) ;
V_6 = V_5 ;
V_7 = V_11 ;
V_8 = F_3 ( V_6 , V_7 , L_1 , V_10 -> V_12 . V_22 ) ;
V_7 -= V_8 ;
V_6 += V_8 ;
return V_11 - V_7 ;
}
static T_1
F_11 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_14 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_14 > 2 )
return - 1 ;
F_5 ( & V_10 -> V_12 . V_15 ) ;
if ( V_5 [ 0 ] == '0' )
V_10 -> V_12 . V_22 = 0 ;
else if ( V_5 [ 0 ] == '1' ) {
V_10 -> V_12 . V_22 = 1 ;
if ( V_10 -> V_12 . V_17 -> V_18 == V_23 ) {
V_10 -> V_20 . V_21 = 1 ;
F_6 ( & V_10 -> V_12 . V_15 ) ;
return V_14 ;
}
}
F_7 ( V_10 ) ;
F_6 ( & V_10 -> V_12 . V_15 ) ;
return V_14 ;
}
static T_1
F_12 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const char * V_5 , T_2 V_14 )
{
struct V_9 * V_10 = F_2 ( V_2 ) ;
if ( V_14 > 2 )
return - 1 ;
F_5 ( & V_10 -> V_12 . V_15 ) ;
if ( V_5 [ 0 ] == '1' )
V_10 -> V_12 . V_24 = 1 ;
F_7 ( V_10 ) ;
F_6 ( & V_10 -> V_12 . V_15 ) ;
return V_14 ;
}
static void F_13 ( struct V_9 * V_10 , enum V_25 V_8 )
{
unsigned long V_26 , V_27 , V_28 ;
if ( V_8 >= V_29 )
return;
F_14 ( & V_10 -> V_15 , V_26 ) ;
V_27 = V_30 [ V_8 ] / V_31 ;
V_28 = ( V_30 [ V_8 ] % V_31 ) * V_32 ;
V_10 -> V_33 [ V_8 ] = F_15 ( F_16 () ,
F_17 ( V_27 , V_28 ) ) ;
V_10 -> V_34 |= ( 1 << V_8 ) ;
if ( ( V_10 -> V_35 == V_29 ) ||
( V_10 -> V_33 [ V_10 -> V_35 ] . V_36 >
V_10 -> V_33 [ V_8 ] . V_36 ) ) {
V_10 -> V_35 = V_8 ;
F_18 ( & V_10 -> V_37 ,
V_10 -> V_33 [ V_8 ] , V_32 ,
V_38 ) ;
}
F_19 ( & V_10 -> V_15 , V_26 ) ;
}
static void F_20 ( struct V_9 * V_10 , enum V_25 V_8 )
{
unsigned long V_26 , V_39 ;
enum V_25 V_40 , V_41 = V_29 ;
if ( ( V_8 >= V_29 ) ||
! ( V_10 -> V_34 & ( 1 << V_8 ) ) )
return;
F_14 ( & V_10 -> V_15 , V_26 ) ;
V_10 -> V_34 &= ~ ( 1 << V_8 ) ;
if ( V_10 -> V_35 == V_8 ) {
if ( V_10 -> V_34 == 0 ) {
F_21 ( & V_10 -> V_37 ) ;
V_10 -> V_35 = V_29 ;
} else {
V_39 = V_10 -> V_34 ;
F_22 (cur_timer, &enabled_timer_bits,
NUM_OTG_FSM_TIMERS) {
if ( ( V_41 == V_29 ) ||
( V_10 -> V_33 [ V_41 ] . V_36 <
V_10 -> V_33 [ V_40 ] . V_36 ) )
V_41 = V_40 ;
}
}
}
if ( V_41 != V_29 ) {
V_10 -> V_35 = V_41 ;
F_18 ( & V_10 -> V_37 ,
V_10 -> V_33 [ V_41 ] , V_32 ,
V_38 ) ;
}
F_19 ( & V_10 -> V_15 , V_26 ) ;
}
static int F_23 ( struct V_9 * V_10 )
{
V_10 -> V_12 . F_23 = 1 ;
return 0 ;
}
static int F_24 ( struct V_9 * V_10 )
{
V_10 -> V_12 . F_24 = 1 ;
return 0 ;
}
static int F_25 ( struct V_9 * V_10 )
{
V_10 -> V_12 . F_25 = 1 ;
return 0 ;
}
static int F_26 ( struct V_9 * V_10 )
{
V_10 -> V_12 . F_26 = 1 ;
return 0 ;
}
static int F_27 ( struct V_9 * V_10 )
{
V_10 -> V_12 . F_27 = 1 ;
return 0 ;
}
static int F_28 ( struct V_9 * V_10 )
{
V_10 -> V_12 . F_28 = 1 ;
return 0 ;
}
static int F_29 ( struct V_9 * V_10 )
{
V_10 -> V_12 . V_42 = 1 ;
return 0 ;
}
static int F_30 ( struct V_9 * V_10 )
{
V_10 -> V_12 . V_43 = 1 ;
return 0 ;
}
static int F_31 ( struct V_9 * V_10 )
{
V_10 -> V_12 . V_44 = 1 ;
return 1 ;
}
static int F_32 ( struct V_9 * V_10 )
{
V_10 -> V_12 . V_44 = 1 ;
V_10 -> V_12 . V_22 = 0 ;
if ( V_10 -> V_12 . V_45 )
V_10 -> V_12 . V_45 = 0 ;
F_33 ( V_10 , V_46 , 0 ) ;
F_34 ( V_10 -> V_2 ) ;
return 0 ;
}
static int F_35 ( struct V_9 * V_10 )
{
V_10 -> V_12 . V_47 = 1 ;
if ( V_10 -> V_12 . V_17 -> V_18 == V_48 )
return 0 ;
else
return 1 ;
}
static enum V_49 F_36 ( struct V_50 * V_8 )
{
struct V_9 * V_10 = F_37 ( V_8 , struct V_9 , V_37 ) ;
T_3 V_51 , * V_52 ;
unsigned long V_39 ;
unsigned long V_26 ;
enum V_25 V_40 , V_41 = V_29 ;
int V_53 = - V_54 ;
F_14 ( & V_10 -> V_15 , V_26 ) ;
V_39 = V_10 -> V_34 ;
V_10 -> V_35 = V_29 ;
V_51 = F_16 () ;
F_22 (cur_timer, &enabled_timer_bits, NUM_OTG_FSM_TIMERS) {
if ( V_51 . V_36 >= V_10 -> V_33 [ V_40 ] . V_36 ) {
V_10 -> V_34 &= ~ ( 1 << V_40 ) ;
if ( V_55 [ V_40 ] )
V_53 = V_55 [ V_40 ] ( V_10 ) ;
} else {
if ( ( V_41 == V_29 ) ||
( V_10 -> V_33 [ V_40 ] . V_36 <
V_10 -> V_33 [ V_41 ] . V_36 ) )
V_41 = V_40 ;
}
}
if ( V_41 < V_29 ) {
V_52 = & V_10 -> V_33 [ V_41 ] ;
F_18 ( & V_10 -> V_37 , * V_52 ,
V_32 , V_38 ) ;
V_10 -> V_35 = V_41 ;
}
F_19 ( & V_10 -> V_15 , V_26 ) ;
if ( ! V_53 )
F_7 ( V_10 ) ;
return V_56 ;
}
static int F_38 ( struct V_9 * V_10 )
{
F_39 ( & V_10 -> V_37 , V_57 , V_38 ) ;
V_10 -> V_37 . V_58 = F_36 ;
return 0 ;
}
static void F_40 ( struct V_59 * V_12 , enum V_25 V_8 )
{
struct V_9 * V_10 = F_37 ( V_12 , struct V_9 , V_12 ) ;
if ( V_8 < V_29 )
F_13 ( V_10 , V_8 ) ;
return;
}
static void F_41 ( struct V_59 * V_12 , enum V_25 V_8 )
{
struct V_9 * V_10 = F_37 ( V_12 , struct V_9 , V_12 ) ;
if ( V_8 < V_29 )
F_20 ( V_10 , V_8 ) ;
return;
}
static void F_42 ( struct V_59 * V_12 , int V_60 )
{
int V_53 ;
struct V_9 * V_10 = F_37 ( V_12 , struct V_9 , V_12 ) ;
if ( V_60 ) {
F_43 ( V_10 , V_61 , V_62 | V_63 ,
V_63 ) ;
if ( V_10 -> V_64 -> V_65 ) {
V_53 = F_44 ( V_10 -> V_64 -> V_65 ) ;
if ( V_53 ) {
F_45 ( V_10 -> V_2 ,
L_2 ,
V_53 ) ;
return;
}
}
F_33 ( V_10 , V_66 , 0 ) ;
V_12 -> V_67 = 0 ;
V_12 -> V_45 = 0 ;
} else {
if ( V_10 -> V_64 -> V_65 )
F_46 ( V_10 -> V_64 -> V_65 ) ;
V_12 -> V_16 = 1 ;
V_12 -> V_13 = 0 ;
}
}
static void F_47 ( struct V_59 * V_12 , int V_60 )
{
struct V_9 * V_10 = F_37 ( V_12 , struct V_9 , V_12 ) ;
if ( V_60 )
F_43 ( V_10 , V_68 , V_69 , V_69 ) ;
else
F_43 ( V_10 , V_68 , V_69 , 0 ) ;
}
static void F_48 ( struct V_59 * V_12 , int V_60 )
{
struct V_70 * V_71 ;
if ( ! V_12 -> V_17 -> V_72 )
return;
V_71 = F_49 ( V_12 -> V_17 -> V_72 -> V_73 , 1 ) ;
if ( ! V_71 )
return;
if ( V_60 ) {
F_50 ( V_71 ) ;
} else {
F_51 ( & V_71 -> V_2 , 0 ) ;
F_52 ( V_71 ) ;
}
}
static void F_53 ( struct V_59 * V_12 )
{
struct V_9 * V_10 = F_37 ( V_12 , struct V_9 , V_12 ) ;
F_33 ( V_10 , V_74 , V_74 ) ;
F_54 ( V_10 -> V_2 ) ;
F_13 ( V_10 , V_75 ) ;
}
static int F_55 ( struct V_59 * V_12 , int V_60 )
{
struct V_9 * V_10 = F_37 ( V_12 , struct V_9 , V_12 ) ;
if ( V_60 ) {
F_56 ( V_10 ) ;
F_57 ( V_10 , V_76 ) ;
} else {
F_56 ( V_10 ) ;
F_57 ( V_10 , V_77 ) ;
}
return 0 ;
}
static int F_58 ( struct V_59 * V_12 , int V_60 )
{
struct V_9 * V_10 = F_37 ( V_12 , struct V_9 , V_12 ) ;
if ( V_60 )
F_59 ( & V_10 -> V_20 ) ;
else
F_60 ( & V_10 -> V_20 ) ;
return 0 ;
}
int F_61 ( struct V_9 * V_10 )
{
if ( V_10 -> V_12 . V_78 && ! ( V_10 -> V_79 ) &&
V_10 -> V_12 . V_17 -> V_18 < V_80 )
return 0 ;
F_62 ( V_10 -> V_2 ) ;
if ( F_63 ( & V_10 -> V_12 ) ) {
if ( V_10 -> V_12 . V_17 -> V_18 == V_80 ) {
if ( ( V_10 -> V_12 . V_78 ) || ( V_10 -> V_81 ) ||
( V_10 -> V_12 . V_45 ) ) {
F_7 ( V_10 ) ;
} else {
F_43 ( V_10 , V_61 , V_62 |
V_63 , 0 ) ;
F_33 ( V_10 , V_82 , V_82 ) ;
F_33 ( V_10 , V_66 , V_66 ) ;
}
if ( V_10 -> V_81 )
V_10 -> V_81 = false ;
} else if ( V_10 -> V_12 . V_17 -> V_18 == V_48 ) {
if ( V_10 -> V_12 . V_83 ) {
V_10 -> V_12 . V_45 = 0 ;
F_7 ( V_10 ) ;
}
} else if ( V_10 -> V_12 . V_17 -> V_18 == V_84 ) {
F_64 ( V_10 -> V_2 ) ;
F_65 ( V_10 -> V_2 ) ;
return 0 ;
}
}
F_66 ( V_10 -> V_2 ) ;
return 0 ;
}
static void F_67 ( struct V_9 * V_10 )
{
T_4 V_85 , V_86 , V_87 ;
struct V_59 * V_12 = & V_10 -> V_12 ;
V_85 = F_68 ( V_10 ) ;
V_86 = F_69 ( V_10 , V_88 ) ;
V_87 = F_70 ( V_10 , V_61 , V_89 ) ;
switch ( V_10 -> V_12 . V_17 -> V_18 ) {
case V_90 :
if ( V_87 ) {
V_12 -> V_91 = 1 ;
V_12 -> V_13 = 1 ;
F_7 ( V_10 ) ;
}
break;
case V_48 :
if ( V_86 && ( V_85 & V_92 ) && V_87 ) {
V_12 -> V_83 = 1 ;
F_7 ( V_10 ) ;
}
break;
case V_23 :
if ( ( V_85 & V_93 ) && V_87 && V_86 ) {
F_13 ( V_10 , V_94 ) ;
} else if ( V_85 & V_92 ) {
F_20 ( V_10 , V_94 ) ;
if ( V_12 -> V_42 == 1 )
V_12 -> V_42 = 0 ;
}
break;
case V_95 :
if ( ( V_85 & V_92 ) && ! V_87 ) {
V_12 -> V_96 = 0 ;
V_12 -> V_22 = 0 ;
F_7 ( V_10 ) ;
}
break;
case V_19 :
if ( V_85 & V_93 ) {
V_12 -> V_97 = 1 ;
F_13 ( V_10 , V_98 ) ;
}
if ( V_85 & V_99 )
F_20 ( V_10 , V_98 ) ;
if ( V_85 & V_92 ) {
if ( V_12 -> V_97 == 1 ) {
F_20 ( V_10 , V_98 ) ;
V_12 -> V_97 = 0 ;
}
}
break;
case V_100 :
if ( ( V_85 & V_92 ) && ! V_87 ) {
V_12 -> V_91 = 0 ;
if ( V_10 -> V_79 ) {
V_10 -> V_20 . V_101 = 1 ;
}
F_7 ( V_10 ) ;
}
break;
case V_84 :
if ( ( V_85 & V_92 ) && ! V_87 ) {
V_12 -> V_91 = 0 ;
F_7 ( V_10 ) ;
}
break;
case V_102 :
if ( ( V_85 & V_92 ) && V_87 ) {
V_12 -> V_96 = 1 ;
F_7 ( V_10 ) ;
}
break;
default:
break;
}
}
T_5 F_71 ( struct V_9 * V_10 )
{
T_5 V_103 = V_104 ;
T_4 V_105 , V_106 = 0 ;
struct V_59 * V_12 = & V_10 -> V_12 ;
V_105 = F_69 ( V_10 , ~ 0 ) ;
V_106 = V_105 & V_107 & ( V_105 >> 8 ) ;
V_12 -> V_78 = ( V_105 & V_108 ) ? 1 : 0 ;
if ( V_106 ) {
if ( V_106 & V_82 ) {
F_33 ( V_10 , V_82 , V_82 ) ;
V_12 -> V_67 = 1 ;
V_12 -> V_16 = 0 ;
} else if ( V_106 & V_109 ) {
F_33 ( V_10 , V_109 , V_109 ) ;
if ( V_12 -> V_78 == 0 ) {
V_12 -> V_16 = 0 ;
V_12 -> V_13 = 1 ;
V_10 -> V_81 = true ;
}
} else if ( V_106 & V_110 ) {
F_33 ( V_10 , V_110 , V_110 ) ;
if ( V_105 & V_88 ) {
V_12 -> V_83 = 1 ;
F_20 ( V_10 , V_111 ) ;
F_20 ( V_10 , V_112 ) ;
V_12 -> V_47 = 0 ;
} else {
V_12 -> V_83 = 0 ;
if ( V_12 -> V_78 )
F_13 ( V_10 , V_111 ) ;
}
} else if ( V_106 & V_113 ) {
F_33 ( V_10 , V_113 , V_113 ) ;
if ( V_105 & V_114 ) {
V_12 -> V_115 = 1 ;
} else {
V_12 -> V_115 = 0 ;
V_12 -> V_91 = 0 ;
}
}
F_7 ( V_10 ) ;
return V_116 ;
}
F_67 ( V_10 ) ;
return V_103 ;
}
void F_72 ( struct V_9 * V_10 )
{
F_7 ( V_10 ) ;
}
int F_73 ( struct V_9 * V_10 )
{
int V_103 = 0 ;
if ( V_10 -> V_117 )
V_10 -> V_17 . V_117 = V_10 -> V_117 ;
else
V_10 -> V_17 . V_118 = V_10 -> V_118 ;
V_10 -> V_17 . V_20 = & V_10 -> V_20 ;
V_10 -> V_12 . V_17 = & V_10 -> V_17 ;
V_10 -> V_12 . V_45 = 1 ;
V_10 -> V_12 . V_78 = F_69 ( V_10 , V_108 ) ? 1 : 0 ;
V_10 -> V_12 . V_17 -> V_18 = V_119 ;
V_10 -> V_12 . V_120 = & V_121 ;
V_10 -> V_20 . V_122 = 1 ;
V_10 -> V_12 . V_123 = F_74 ( V_10 -> V_2 , 1 , V_124 ) ;
if ( ! V_10 -> V_12 . V_123 )
return - V_125 ;
F_75 ( & V_10 -> V_12 . V_15 ) ;
V_103 = F_38 ( V_10 ) ;
if ( V_103 ) {
F_45 ( V_10 -> V_2 , L_3 ) ;
return V_103 ;
}
V_10 -> V_34 = 0 ;
V_10 -> V_35 = V_29 ;
V_103 = F_76 ( & V_10 -> V_2 -> V_126 , & V_127 ) ;
if ( V_103 < 0 ) {
F_77 ( V_10 -> V_2 ,
L_4 , V_103 ) ;
return V_103 ;
}
F_33 ( V_10 , V_128 , V_128 ) ;
if ( V_10 -> V_12 . V_78 ) {
V_10 -> V_12 . V_47 =
F_69 ( V_10 , V_88 ) ? 0 : 1 ;
V_10 -> V_12 . V_83 =
F_69 ( V_10 , V_88 ) ? 1 : 0 ;
F_33 ( V_10 , V_129 , V_129 ) ;
}
return 0 ;
}
void F_78 ( struct V_9 * V_10 )
{
F_79 ( & V_10 -> V_2 -> V_126 , & V_127 ) ;
}
