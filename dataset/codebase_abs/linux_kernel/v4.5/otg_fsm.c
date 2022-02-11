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
V_8 = F_3 ( V_6 , V_7 , L_1 , V_10 -> V_12 . V_17 ) ;
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
V_10 -> V_12 . V_17 = 0 ;
else if ( V_5 [ 0 ] == '1' )
V_10 -> V_12 . V_17 = 1 ;
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
V_10 -> V_12 . V_18 = 1 ;
F_7 ( V_10 ) ;
F_6 ( & V_10 -> V_12 . V_15 ) ;
return V_14 ;
}
static void F_13 ( struct V_9 * V_10 , enum V_19 V_8 )
{
unsigned long V_20 , V_21 , V_22 ;
if ( V_8 >= V_23 )
return;
F_14 ( & V_10 -> V_15 , V_20 ) ;
V_21 = V_24 [ V_8 ] / V_25 ;
V_22 = ( V_24 [ V_8 ] % V_25 ) * V_26 ;
V_10 -> V_27 [ V_8 ] = F_15 ( F_16 () ,
F_17 ( V_21 , V_22 ) ) ;
V_10 -> V_28 |= ( 1 << V_8 ) ;
if ( ( V_10 -> V_29 == V_23 ) ||
( V_10 -> V_27 [ V_10 -> V_29 ] . V_30 >
V_10 -> V_27 [ V_8 ] . V_30 ) ) {
V_10 -> V_29 = V_8 ;
F_18 ( & V_10 -> V_31 ,
V_10 -> V_27 [ V_8 ] , V_26 ,
V_32 ) ;
}
F_19 ( & V_10 -> V_15 , V_20 ) ;
}
static void F_20 ( struct V_9 * V_10 , enum V_19 V_8 )
{
unsigned long V_20 , V_33 ;
enum V_19 V_34 , V_35 = V_23 ;
if ( ( V_8 >= V_23 ) ||
! ( V_10 -> V_28 & ( 1 << V_8 ) ) )
return;
F_14 ( & V_10 -> V_15 , V_20 ) ;
V_10 -> V_28 &= ~ ( 1 << V_8 ) ;
if ( V_10 -> V_29 == V_8 ) {
if ( V_10 -> V_28 == 0 ) {
F_21 ( & V_10 -> V_31 ) ;
V_10 -> V_29 = V_23 ;
} else {
V_33 = V_10 -> V_28 ;
F_22 (cur_timer, &enabled_timer_bits,
NUM_OTG_FSM_TIMERS) {
if ( ( V_35 == V_23 ) ||
( V_10 -> V_27 [ V_35 ] . V_30 <
V_10 -> V_27 [ V_34 ] . V_30 ) )
V_35 = V_34 ;
}
}
}
if ( V_35 != V_23 ) {
V_10 -> V_29 = V_35 ;
F_18 ( & V_10 -> V_31 ,
V_10 -> V_27 [ V_35 ] , V_26 ,
V_32 ) ;
}
F_19 ( & V_10 -> V_15 , V_20 ) ;
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
V_10 -> V_12 . V_36 = 1 ;
return 0 ;
}
static int F_30 ( struct V_9 * V_10 )
{
V_10 -> V_12 . V_37 = 1 ;
return 1 ;
}
static int F_31 ( struct V_9 * V_10 )
{
V_10 -> V_12 . V_37 = 1 ;
V_10 -> V_12 . V_17 = 0 ;
if ( V_10 -> V_12 . V_38 )
V_10 -> V_12 . V_38 = 0 ;
F_32 ( V_10 , V_39 , 0 ) ;
F_33 ( V_10 -> V_2 ) ;
return 0 ;
}
static int F_34 ( struct V_9 * V_10 )
{
V_10 -> V_12 . V_40 = 1 ;
if ( V_10 -> V_12 . V_41 -> V_42 == V_43 )
return 0 ;
else
return 1 ;
}
static enum V_44 F_35 ( struct V_45 * V_8 )
{
struct V_9 * V_10 = F_36 ( V_8 , struct V_9 , V_31 ) ;
T_3 V_46 , * V_47 ;
unsigned long V_33 ;
unsigned long V_20 ;
enum V_19 V_34 , V_35 = V_23 ;
int V_48 = - V_49 ;
F_14 ( & V_10 -> V_15 , V_20 ) ;
V_33 = V_10 -> V_28 ;
V_10 -> V_29 = V_23 ;
V_46 = F_16 () ;
F_22 (cur_timer, &enabled_timer_bits, NUM_OTG_FSM_TIMERS) {
if ( V_46 . V_30 >= V_10 -> V_27 [ V_34 ] . V_30 ) {
V_10 -> V_28 &= ~ ( 1 << V_34 ) ;
if ( V_50 [ V_34 ] )
V_48 = V_50 [ V_34 ] ( V_10 ) ;
} else {
if ( ( V_35 == V_23 ) ||
( V_10 -> V_27 [ V_34 ] . V_30 <
V_10 -> V_27 [ V_35 ] . V_30 ) )
V_35 = V_34 ;
}
}
if ( V_35 < V_23 ) {
V_47 = & V_10 -> V_27 [ V_35 ] ;
F_18 ( & V_10 -> V_31 , * V_47 ,
V_26 , V_32 ) ;
V_10 -> V_29 = V_35 ;
}
F_19 ( & V_10 -> V_15 , V_20 ) ;
if ( ! V_48 )
F_7 ( V_10 ) ;
return V_51 ;
}
static int F_37 ( struct V_9 * V_10 )
{
F_38 ( & V_10 -> V_31 , V_52 , V_32 ) ;
V_10 -> V_31 . V_53 = F_35 ;
return 0 ;
}
static void F_39 ( struct V_54 * V_12 , enum V_19 V_8 )
{
struct V_9 * V_10 = F_36 ( V_12 , struct V_9 , V_12 ) ;
if ( V_8 < V_23 )
F_13 ( V_10 , V_8 ) ;
return;
}
static void F_40 ( struct V_54 * V_12 , enum V_19 V_8 )
{
struct V_9 * V_10 = F_36 ( V_12 , struct V_9 , V_12 ) ;
if ( V_8 < V_23 )
F_20 ( V_10 , V_8 ) ;
return;
}
static void F_41 ( struct V_54 * V_12 , int V_55 )
{
int V_48 ;
struct V_9 * V_10 = F_36 ( V_12 , struct V_9 , V_12 ) ;
if ( V_55 ) {
F_42 ( V_10 , V_56 , V_57 | V_58 ,
V_58 ) ;
if ( V_10 -> V_59 -> V_60 ) {
V_48 = F_43 ( V_10 -> V_59 -> V_60 ) ;
if ( V_48 ) {
F_44 ( V_10 -> V_2 ,
L_2 ,
V_48 ) ;
return;
}
}
F_32 ( V_10 , V_61 , 0 ) ;
V_12 -> V_62 = 0 ;
V_12 -> V_38 = 0 ;
} else {
if ( V_10 -> V_59 -> V_60 )
F_45 ( V_10 -> V_59 -> V_60 ) ;
V_12 -> V_16 = 1 ;
V_12 -> V_13 = 0 ;
}
}
static void F_46 ( struct V_54 * V_12 , int V_55 )
{
struct V_9 * V_10 = F_36 ( V_12 , struct V_9 , V_12 ) ;
if ( V_55 )
F_42 ( V_10 , V_63 , V_64 , V_64 ) ;
else
F_42 ( V_10 , V_63 , V_64 , 0 ) ;
}
static void F_47 ( struct V_54 * V_12 , int V_55 )
{
struct V_65 * V_66 ;
if ( ! V_12 -> V_41 -> V_67 )
return;
V_66 = F_48 ( V_12 -> V_41 -> V_67 -> V_68 , 1 ) ;
if ( ! V_66 )
return;
if ( V_55 ) {
F_49 ( V_66 ) ;
} else {
F_50 ( & V_66 -> V_2 , 0 ) ;
F_51 ( V_66 ) ;
}
}
static void F_52 ( struct V_54 * V_12 )
{
struct V_9 * V_10 = F_36 ( V_12 , struct V_9 , V_12 ) ;
F_32 ( V_10 , V_69 , V_69 ) ;
F_53 ( V_10 -> V_2 ) ;
F_13 ( V_10 , V_70 ) ;
}
static int F_54 ( struct V_54 * V_12 , int V_55 )
{
struct V_9 * V_10 = F_36 ( V_12 , struct V_9 , V_12 ) ;
if ( V_55 ) {
F_55 ( V_10 ) ;
F_56 ( V_10 , V_71 ) ;
} else {
F_55 ( V_10 ) ;
F_56 ( V_10 , V_72 ) ;
}
return 0 ;
}
static int F_57 ( struct V_54 * V_12 , int V_55 )
{
struct V_9 * V_10 = F_36 ( V_12 , struct V_9 , V_12 ) ;
if ( V_55 )
F_58 ( & V_10 -> V_73 ) ;
else
F_59 ( & V_10 -> V_73 ) ;
return 0 ;
}
int F_60 ( struct V_9 * V_10 )
{
if ( V_10 -> V_12 . V_74 && ! ( V_10 -> V_75 ) &&
V_10 -> V_12 . V_41 -> V_42 < V_76 )
return 0 ;
F_61 ( V_10 -> V_2 ) ;
if ( F_62 ( & V_10 -> V_12 ) ) {
if ( V_10 -> V_12 . V_41 -> V_42 == V_76 ) {
if ( ( V_10 -> V_12 . V_74 ) || ( V_10 -> V_77 ) ||
( V_10 -> V_12 . V_38 ) ) {
F_7 ( V_10 ) ;
} else {
F_42 ( V_10 , V_56 , V_57 |
V_58 , 0 ) ;
F_32 ( V_10 , V_78 , V_78 ) ;
F_32 ( V_10 , V_61 , V_61 ) ;
}
if ( V_10 -> V_77 )
V_10 -> V_77 = false ;
} else if ( V_10 -> V_12 . V_41 -> V_42 == V_43 ) {
if ( V_10 -> V_12 . V_79 ) {
V_10 -> V_12 . V_38 = 0 ;
F_7 ( V_10 ) ;
}
} else if ( V_10 -> V_12 . V_41 -> V_42 == V_80 ) {
F_63 ( V_10 -> V_2 ) ;
F_64 ( V_10 -> V_2 ) ;
return 0 ;
}
}
F_65 ( V_10 -> V_2 ) ;
return 0 ;
}
static void F_66 ( struct V_9 * V_10 )
{
T_4 V_81 , V_82 , V_83 ;
struct V_54 * V_12 = & V_10 -> V_12 ;
V_81 = F_67 ( V_10 ) ;
V_82 = F_68 ( V_10 , V_84 ) ;
V_83 = F_69 ( V_10 , V_56 , V_85 ) ;
switch ( V_10 -> V_12 . V_41 -> V_42 ) {
case V_86 :
if ( V_83 ) {
V_12 -> V_87 = 1 ;
V_12 -> V_13 = 1 ;
F_7 ( V_10 ) ;
}
break;
case V_43 :
if ( V_82 && ( V_81 & V_88 ) && V_83 ) {
V_12 -> V_79 = 1 ;
F_7 ( V_10 ) ;
}
break;
case V_89 :
if ( ( V_81 & V_90 ) && V_83 && V_82 ) {
V_12 -> V_91 = 1 ;
F_7 ( V_10 ) ;
} else if ( V_81 & V_88 ) {
if ( V_12 -> V_91 == 1 )
V_12 -> V_91 = 0 ;
}
break;
case V_92 :
if ( ( V_81 & V_88 ) && ! V_83 ) {
V_12 -> V_93 = 0 ;
V_12 -> V_17 = 0 ;
F_7 ( V_10 ) ;
}
break;
case V_94 :
if ( V_81 & V_90 ) {
V_12 -> V_95 = 1 ;
F_13 ( V_10 , V_96 ) ;
}
if ( V_81 & V_97 )
F_20 ( V_10 , V_96 ) ;
if ( V_81 & V_88 ) {
if ( V_12 -> V_95 == 1 ) {
F_20 ( V_10 , V_96 ) ;
V_12 -> V_95 = 0 ;
}
}
break;
case V_98 :
if ( ( V_81 & V_88 ) && ! V_83 ) {
V_12 -> V_87 = 0 ;
if ( V_10 -> V_75 ) {
V_10 -> V_73 . V_99 = 1 ;
}
F_7 ( V_10 ) ;
}
break;
case V_80 :
if ( ( V_81 & V_88 ) && ! V_83 ) {
V_12 -> V_87 = 0 ;
F_7 ( V_10 ) ;
}
break;
case V_100 :
if ( ( V_81 & V_88 ) && V_83 ) {
V_12 -> V_93 = 1 ;
F_7 ( V_10 ) ;
}
break;
default:
break;
}
}
T_5 F_70 ( struct V_9 * V_10 )
{
T_5 V_101 = V_102 ;
T_4 V_103 , V_104 = 0 ;
struct V_54 * V_12 = & V_10 -> V_12 ;
V_103 = F_68 ( V_10 , ~ 0 ) ;
V_104 = V_103 & V_105 & ( V_103 >> 8 ) ;
V_12 -> V_74 = ( V_103 & V_106 ) ? 1 : 0 ;
if ( V_104 ) {
if ( V_104 & V_78 ) {
F_32 ( V_10 , V_78 , V_78 ) ;
V_12 -> V_62 = 1 ;
V_12 -> V_16 = 0 ;
} else if ( V_104 & V_107 ) {
F_32 ( V_10 , V_107 , V_107 ) ;
if ( V_12 -> V_74 == 0 ) {
V_12 -> V_16 = 0 ;
V_12 -> V_13 = 1 ;
V_10 -> V_77 = true ;
}
} else if ( V_104 & V_108 ) {
F_32 ( V_10 , V_108 , V_108 ) ;
if ( V_103 & V_84 ) {
V_12 -> V_79 = 1 ;
F_20 ( V_10 , V_109 ) ;
F_20 ( V_10 , V_110 ) ;
V_12 -> V_40 = 0 ;
} else {
V_12 -> V_79 = 0 ;
if ( V_12 -> V_74 )
F_13 ( V_10 , V_109 ) ;
}
} else if ( V_104 & V_111 ) {
F_32 ( V_10 , V_111 , V_111 ) ;
if ( V_103 & V_112 ) {
V_12 -> V_113 = 1 ;
} else {
V_12 -> V_113 = 0 ;
V_12 -> V_87 = 0 ;
}
}
F_7 ( V_10 ) ;
return V_114 ;
}
F_66 ( V_10 ) ;
return V_101 ;
}
void F_71 ( struct V_9 * V_10 )
{
F_7 ( V_10 ) ;
}
int F_72 ( struct V_9 * V_10 )
{
int V_101 = 0 ;
if ( V_10 -> V_115 )
V_10 -> V_41 . V_115 = V_10 -> V_115 ;
else
V_10 -> V_41 . V_116 = V_10 -> V_116 ;
V_10 -> V_41 . V_73 = & V_10 -> V_73 ;
V_10 -> V_12 . V_41 = & V_10 -> V_41 ;
V_10 -> V_12 . V_38 = 1 ;
V_10 -> V_12 . V_74 = F_68 ( V_10 , V_106 ) ? 1 : 0 ;
V_10 -> V_12 . V_41 -> V_42 = V_117 ;
V_10 -> V_12 . V_118 = & V_119 ;
F_73 ( & V_10 -> V_12 . V_15 ) ;
V_101 = F_37 ( V_10 ) ;
if ( V_101 ) {
F_44 ( V_10 -> V_2 , L_3 ) ;
return V_101 ;
}
V_10 -> V_28 = 0 ;
V_10 -> V_29 = V_23 ;
V_101 = F_74 ( & V_10 -> V_2 -> V_120 , & V_121 ) ;
if ( V_101 < 0 ) {
F_75 ( V_10 -> V_2 ,
L_4 , V_101 ) ;
return V_101 ;
}
F_32 ( V_10 , V_122 , V_122 ) ;
if ( V_10 -> V_12 . V_74 ) {
V_10 -> V_12 . V_40 =
F_68 ( V_10 , V_84 ) ? 0 : 1 ;
V_10 -> V_12 . V_79 =
F_68 ( V_10 , V_84 ) ? 1 : 0 ;
F_32 ( V_10 , V_123 , V_123 ) ;
}
return 0 ;
}
void F_76 ( struct V_9 * V_10 )
{
F_77 ( & V_10 -> V_2 -> V_120 , & V_121 ) ;
}
