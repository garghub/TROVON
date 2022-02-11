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
F_18 ( V_10 -> V_33 [ V_10 -> V_35 ] ,
V_10 -> V_33 [ V_8 ] ) ) {
V_10 -> V_35 = V_8 ;
F_19 ( & V_10 -> V_36 ,
V_10 -> V_33 [ V_8 ] , V_32 ,
V_37 ) ;
}
F_20 ( & V_10 -> V_15 , V_26 ) ;
}
static void F_21 ( struct V_9 * V_10 , enum V_25 V_8 )
{
unsigned long V_26 , V_38 ;
enum V_25 V_39 , V_40 = V_29 ;
if ( ( V_8 >= V_29 ) ||
! ( V_10 -> V_34 & ( 1 << V_8 ) ) )
return;
F_14 ( & V_10 -> V_15 , V_26 ) ;
V_10 -> V_34 &= ~ ( 1 << V_8 ) ;
if ( V_10 -> V_35 == V_8 ) {
if ( V_10 -> V_34 == 0 ) {
F_22 ( & V_10 -> V_36 ) ;
V_10 -> V_35 = V_29 ;
} else {
V_38 = V_10 -> V_34 ;
F_23 (cur_timer, &enabled_timer_bits,
NUM_OTG_FSM_TIMERS) {
if ( ( V_40 == V_29 ) ||
F_24 ( V_10 -> V_33 [ V_40 ] ,
V_10 -> V_33 [ V_39 ] ) )
V_40 = V_39 ;
}
}
}
if ( V_40 != V_29 ) {
V_10 -> V_35 = V_40 ;
F_19 ( & V_10 -> V_36 ,
V_10 -> V_33 [ V_40 ] , V_32 ,
V_37 ) ;
}
F_20 ( & V_10 -> V_15 , V_26 ) ;
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
V_10 -> V_12 . F_29 = 1 ;
return 0 ;
}
static int F_30 ( struct V_9 * V_10 )
{
V_10 -> V_12 . F_30 = 1 ;
return 0 ;
}
static int F_31 ( struct V_9 * V_10 )
{
V_10 -> V_12 . V_41 = 1 ;
return 0 ;
}
static int F_32 ( struct V_9 * V_10 )
{
V_10 -> V_12 . V_42 = 1 ;
return 0 ;
}
static int F_33 ( struct V_9 * V_10 )
{
V_10 -> V_12 . V_43 = 1 ;
return 1 ;
}
static int F_34 ( struct V_9 * V_10 )
{
V_10 -> V_12 . V_43 = 1 ;
V_10 -> V_12 . V_22 = 0 ;
if ( V_10 -> V_12 . V_44 )
V_10 -> V_12 . V_44 = 0 ;
F_35 ( V_10 , V_45 , 0 ) ;
F_36 ( V_10 -> V_2 ) ;
return 0 ;
}
static int F_37 ( struct V_9 * V_10 )
{
V_10 -> V_12 . V_46 = 1 ;
if ( V_10 -> V_12 . V_17 -> V_18 == V_47 )
return 0 ;
else
return 1 ;
}
static enum V_48 F_38 ( struct V_49 * V_8 )
{
struct V_9 * V_10 = F_39 ( V_8 , struct V_9 , V_36 ) ;
T_3 V_50 , * V_51 ;
unsigned long V_38 ;
unsigned long V_26 ;
enum V_25 V_39 , V_40 = V_29 ;
int V_52 = - V_53 ;
F_14 ( & V_10 -> V_15 , V_26 ) ;
V_38 = V_10 -> V_34 ;
V_10 -> V_35 = V_29 ;
V_50 = F_16 () ;
F_23 (cur_timer, &enabled_timer_bits, NUM_OTG_FSM_TIMERS) {
if ( F_40 ( V_50 , V_10 -> V_33 [ V_39 ] ) >= 0 ) {
V_10 -> V_34 &= ~ ( 1 << V_39 ) ;
if ( V_54 [ V_39 ] )
V_52 = V_54 [ V_39 ] ( V_10 ) ;
} else {
if ( ( V_40 == V_29 ) ||
F_24 ( V_10 -> V_33 [ V_39 ] ,
V_10 -> V_33 [ V_40 ] ) )
V_40 = V_39 ;
}
}
if ( V_40 < V_29 ) {
V_51 = & V_10 -> V_33 [ V_40 ] ;
F_19 ( & V_10 -> V_36 , * V_51 ,
V_32 , V_37 ) ;
V_10 -> V_35 = V_40 ;
}
F_20 ( & V_10 -> V_15 , V_26 ) ;
if ( ! V_52 )
F_7 ( V_10 ) ;
return V_55 ;
}
static int F_41 ( struct V_9 * V_10 )
{
F_42 ( & V_10 -> V_36 , V_56 , V_37 ) ;
V_10 -> V_36 . V_57 = F_38 ;
return 0 ;
}
static void F_43 ( struct V_58 * V_12 , enum V_25 V_8 )
{
struct V_9 * V_10 = F_39 ( V_12 , struct V_9 , V_12 ) ;
if ( V_8 < V_29 )
F_13 ( V_10 , V_8 ) ;
return;
}
static void F_44 ( struct V_58 * V_12 , enum V_25 V_8 )
{
struct V_9 * V_10 = F_39 ( V_12 , struct V_9 , V_12 ) ;
if ( V_8 < V_29 )
F_21 ( V_10 , V_8 ) ;
return;
}
static void F_45 ( struct V_58 * V_12 , int V_59 )
{
int V_52 ;
struct V_9 * V_10 = F_39 ( V_12 , struct V_9 , V_12 ) ;
if ( V_59 ) {
F_46 ( V_10 , V_60 , V_61 | V_62 ,
V_62 ) ;
if ( V_10 -> V_63 -> V_64 ) {
V_52 = F_47 ( V_10 -> V_63 -> V_64 ) ;
if ( V_52 ) {
F_48 ( V_10 -> V_2 ,
L_2 ,
V_52 ) ;
return;
}
}
F_35 ( V_10 , V_65 , 0 ) ;
V_12 -> V_66 = 0 ;
V_12 -> V_44 = 0 ;
} else {
if ( V_10 -> V_63 -> V_64 )
F_49 ( V_10 -> V_63 -> V_64 ) ;
V_12 -> V_16 = 1 ;
V_12 -> V_13 = 0 ;
}
}
static void F_50 ( struct V_58 * V_12 , int V_59 )
{
struct V_9 * V_10 = F_39 ( V_12 , struct V_9 , V_12 ) ;
if ( V_59 )
F_46 ( V_10 , V_67 , V_68 , V_68 ) ;
else
F_46 ( V_10 , V_67 , V_68 , 0 ) ;
}
static void F_51 ( struct V_58 * V_12 , int V_59 )
{
struct V_69 * V_70 ;
if ( ! V_12 -> V_17 -> V_71 )
return;
V_70 = F_52 ( V_12 -> V_17 -> V_71 -> V_72 , 1 ) ;
if ( ! V_70 )
return;
if ( V_59 ) {
F_53 ( V_70 ) ;
} else {
F_54 ( & V_70 -> V_2 , 0 ) ;
F_55 ( V_70 ) ;
}
}
static void F_56 ( struct V_58 * V_12 )
{
struct V_9 * V_10 = F_39 ( V_12 , struct V_9 , V_12 ) ;
F_35 ( V_10 , V_73 , V_73 ) ;
F_57 ( V_10 -> V_2 ) ;
F_13 ( V_10 , V_74 ) ;
}
static int F_58 ( struct V_58 * V_12 , int V_59 )
{
struct V_9 * V_10 = F_39 ( V_12 , struct V_9 , V_12 ) ;
if ( V_59 ) {
F_59 ( V_10 ) ;
F_60 ( V_10 , V_75 ) ;
} else {
F_59 ( V_10 ) ;
F_60 ( V_10 , V_76 ) ;
}
return 0 ;
}
static int F_61 ( struct V_58 * V_12 , int V_59 )
{
struct V_9 * V_10 = F_39 ( V_12 , struct V_9 , V_12 ) ;
if ( V_59 )
F_62 ( & V_10 -> V_20 ) ;
else
F_63 ( & V_10 -> V_20 ) ;
return 0 ;
}
int F_64 ( struct V_9 * V_10 )
{
if ( V_10 -> V_12 . V_77 && ! ( V_10 -> V_78 ) &&
V_10 -> V_12 . V_17 -> V_18 < V_79 )
return 0 ;
F_65 ( V_10 -> V_2 ) ;
if ( F_66 ( & V_10 -> V_12 ) ) {
if ( V_10 -> V_12 . V_17 -> V_18 == V_79 ) {
if ( ( V_10 -> V_12 . V_77 ) || ( V_10 -> V_80 ) ||
( V_10 -> V_12 . V_44 ) ) {
F_7 ( V_10 ) ;
} else {
F_46 ( V_10 , V_60 , V_61 |
V_62 , 0 ) ;
F_35 ( V_10 , V_81 , V_81 ) ;
F_35 ( V_10 , V_65 , V_65 ) ;
}
if ( V_10 -> V_80 )
V_10 -> V_80 = false ;
} else if ( V_10 -> V_12 . V_17 -> V_18 == V_47 ) {
if ( V_10 -> V_12 . V_82 ) {
V_10 -> V_12 . V_44 = 0 ;
F_7 ( V_10 ) ;
}
} else if ( V_10 -> V_12 . V_17 -> V_18 == V_83 ) {
F_67 ( V_10 -> V_2 ) ;
F_68 ( V_10 -> V_2 ) ;
return 0 ;
}
}
F_69 ( V_10 -> V_2 ) ;
return 0 ;
}
static void F_70 ( struct V_9 * V_10 )
{
T_4 V_84 , V_85 , V_86 ;
struct V_58 * V_12 = & V_10 -> V_12 ;
V_84 = F_71 ( V_10 ) ;
V_85 = F_72 ( V_10 , V_87 ) ;
V_86 = F_73 ( V_10 , V_60 , V_88 ) ;
switch ( V_10 -> V_12 . V_17 -> V_18 ) {
case V_89 :
if ( V_86 ) {
V_12 -> V_90 = 1 ;
V_12 -> V_13 = 1 ;
F_7 ( V_10 ) ;
}
break;
case V_47 :
if ( V_85 && ( V_84 & V_91 ) && V_86 ) {
V_12 -> V_82 = 1 ;
F_7 ( V_10 ) ;
}
break;
case V_23 :
if ( ( V_84 & V_92 ) && V_86 && V_85 ) {
F_13 ( V_10 , V_93 ) ;
} else if ( V_84 & V_91 ) {
F_21 ( V_10 , V_93 ) ;
if ( V_12 -> V_41 == 1 )
V_12 -> V_41 = 0 ;
}
break;
case V_94 :
if ( ( V_84 & V_91 ) && ! V_86 ) {
V_12 -> V_95 = 0 ;
V_12 -> V_22 = 0 ;
F_7 ( V_10 ) ;
}
break;
case V_19 :
if ( V_84 & V_92 ) {
V_12 -> V_96 = 1 ;
F_13 ( V_10 , V_97 ) ;
}
if ( V_84 & V_98 )
F_21 ( V_10 , V_97 ) ;
if ( V_84 & V_91 ) {
if ( V_12 -> V_96 == 1 ) {
F_21 ( V_10 , V_97 ) ;
V_12 -> V_96 = 0 ;
}
}
break;
case V_99 :
if ( ( V_84 & V_91 ) && ! V_86 ) {
V_12 -> V_90 = 0 ;
if ( V_10 -> V_78 ) {
V_10 -> V_20 . V_100 = 1 ;
}
F_7 ( V_10 ) ;
}
break;
case V_83 :
if ( ( V_84 & V_91 ) && ! V_86 ) {
V_12 -> V_90 = 0 ;
F_7 ( V_10 ) ;
}
break;
case V_101 :
if ( ( V_84 & V_91 ) && V_86 ) {
V_12 -> V_95 = 1 ;
F_7 ( V_10 ) ;
}
break;
default:
break;
}
}
T_5 F_74 ( struct V_9 * V_10 )
{
T_5 V_102 = V_103 ;
T_4 V_104 , V_105 = 0 ;
struct V_58 * V_12 = & V_10 -> V_12 ;
V_104 = F_72 ( V_10 , ~ 0 ) ;
V_105 = V_104 & V_106 & ( V_104 >> 8 ) ;
V_12 -> V_77 = ( V_104 & V_107 ) ? 1 : 0 ;
if ( V_105 ) {
if ( V_105 & V_81 ) {
F_35 ( V_10 , V_81 , V_81 ) ;
V_12 -> V_66 = 1 ;
V_12 -> V_16 = 0 ;
} else if ( V_105 & V_108 ) {
F_35 ( V_10 , V_108 , V_108 ) ;
if ( V_12 -> V_77 == 0 ) {
V_12 -> V_16 = 0 ;
V_12 -> V_13 = 1 ;
V_10 -> V_80 = true ;
}
} else if ( V_105 & V_109 ) {
F_35 ( V_10 , V_109 , V_109 ) ;
if ( V_104 & V_87 ) {
V_12 -> V_82 = 1 ;
F_21 ( V_10 , V_110 ) ;
F_21 ( V_10 , V_111 ) ;
V_12 -> V_46 = 0 ;
} else {
V_12 -> V_82 = 0 ;
if ( V_12 -> V_77 )
F_13 ( V_10 , V_110 ) ;
}
} else if ( V_105 & V_112 ) {
F_35 ( V_10 , V_112 , V_112 ) ;
if ( V_104 & V_113 ) {
V_12 -> V_114 = 1 ;
} else {
V_12 -> V_114 = 0 ;
V_12 -> V_90 = 0 ;
}
}
F_7 ( V_10 ) ;
return V_115 ;
}
F_70 ( V_10 ) ;
return V_102 ;
}
void F_75 ( struct V_9 * V_10 )
{
F_7 ( V_10 ) ;
}
int F_76 ( struct V_9 * V_10 )
{
int V_102 = 0 ;
if ( V_10 -> V_116 )
V_10 -> V_17 . V_116 = V_10 -> V_116 ;
else
V_10 -> V_17 . V_117 = V_10 -> V_117 ;
V_10 -> V_17 . V_20 = & V_10 -> V_20 ;
V_10 -> V_12 . V_17 = & V_10 -> V_17 ;
V_10 -> V_12 . V_44 = 1 ;
V_10 -> V_12 . V_77 = F_72 ( V_10 , V_107 ) ? 1 : 0 ;
V_10 -> V_12 . V_17 -> V_18 = V_118 ;
V_10 -> V_12 . V_119 = & V_120 ;
V_10 -> V_20 . V_121 = 1 ;
V_10 -> V_12 . V_122 = F_77 ( V_10 -> V_2 , 1 , V_123 ) ;
if ( ! V_10 -> V_12 . V_122 )
return - V_124 ;
F_78 ( & V_10 -> V_12 . V_15 ) ;
V_102 = F_41 ( V_10 ) ;
if ( V_102 ) {
F_48 ( V_10 -> V_2 , L_3 ) ;
return V_102 ;
}
V_10 -> V_34 = 0 ;
V_10 -> V_35 = V_29 ;
V_102 = F_79 ( & V_10 -> V_2 -> V_125 , & V_126 ) ;
if ( V_102 < 0 ) {
F_80 ( V_10 -> V_2 ,
L_4 , V_102 ) ;
return V_102 ;
}
F_35 ( V_10 , V_127 , V_127 ) ;
if ( V_10 -> V_12 . V_77 ) {
V_10 -> V_12 . V_46 =
F_72 ( V_10 , V_87 ) ? 0 : 1 ;
V_10 -> V_12 . V_82 =
F_72 ( V_10 , V_87 ) ? 1 : 0 ;
F_35 ( V_10 , V_128 , V_128 ) ;
}
return 0 ;
}
void F_81 ( struct V_9 * V_10 )
{
F_82 ( & V_10 -> V_2 -> V_125 , & V_126 ) ;
}
