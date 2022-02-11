static struct V_1 * F_1
( struct V_2 * V_3 , void (* F_2)( void * , unsigned long ) ,
unsigned long V_4 , unsigned long V_5 )
{
struct V_1 * V_6 ;
V_6 = F_3 ( V_3 -> V_7 , sizeof( struct V_1 ) ,
V_8 ) ;
if ( ! V_6 )
return NULL ;
V_6 -> F_2 = F_2 ;
V_6 -> V_4 = V_4 ;
V_6 -> V_5 = V_5 ;
return V_6 ;
}
static T_1
F_4 ( struct V_9 * V_7 , struct V_10 * V_11 , char * V_12 )
{
char * V_13 ;
unsigned V_14 , V_15 ;
struct V_2 * V_3 = F_5 ( V_7 ) ;
V_13 = V_12 ;
V_14 = V_16 ;
V_15 = F_6 ( V_13 , V_14 , L_1 , V_3 -> V_17 . V_18 ) ;
V_14 -= V_15 ;
V_13 += V_15 ;
return V_16 - V_14 ;
}
static T_1
F_7 ( struct V_9 * V_7 , struct V_10 * V_11 ,
const char * V_12 , T_2 V_19 )
{
struct V_2 * V_3 = F_5 ( V_7 ) ;
if ( V_19 > 2 )
return - 1 ;
F_8 ( & V_3 -> V_17 . V_20 ) ;
if ( V_12 [ 0 ] == '0' ) {
V_3 -> V_17 . V_18 = 0 ;
} else if ( V_12 [ 0 ] == '1' ) {
if ( V_3 -> V_17 . V_21 ) {
F_9 ( & V_3 -> V_17 . V_20 ) ;
return V_19 ;
}
V_3 -> V_17 . V_18 = 1 ;
}
F_10 ( V_3 ) ;
F_9 ( & V_3 -> V_17 . V_20 ) ;
return V_19 ;
}
static T_1
F_11 ( struct V_9 * V_7 , struct V_10 * V_11 , char * V_12 )
{
char * V_13 ;
unsigned V_14 , V_15 ;
struct V_2 * V_3 = F_5 ( V_7 ) ;
V_13 = V_12 ;
V_14 = V_16 ;
V_15 = F_6 ( V_13 , V_14 , L_1 , V_3 -> V_17 . V_21 ) ;
V_14 -= V_15 ;
V_13 += V_15 ;
return V_16 - V_14 ;
}
static T_1
F_12 ( struct V_9 * V_7 , struct V_10 * V_11 ,
const char * V_12 , T_2 V_19 )
{
struct V_2 * V_3 = F_5 ( V_7 ) ;
if ( V_19 > 2 )
return - 1 ;
F_8 ( & V_3 -> V_17 . V_20 ) ;
if ( V_12 [ 0 ] == '0' ) {
V_3 -> V_17 . V_21 = 0 ;
} else if ( V_12 [ 0 ] == '1' ) {
V_3 -> V_17 . V_21 = 1 ;
V_3 -> V_17 . V_18 = 0 ;
}
F_10 ( V_3 ) ;
F_9 ( & V_3 -> V_17 . V_20 ) ;
return V_19 ;
}
static T_1
F_13 ( struct V_9 * V_7 , struct V_10 * V_11 , char * V_12 )
{
char * V_13 ;
unsigned V_14 , V_15 ;
struct V_2 * V_3 = F_5 ( V_7 ) ;
V_13 = V_12 ;
V_14 = V_16 ;
V_15 = F_6 ( V_13 , V_14 , L_1 , V_3 -> V_17 . V_22 ) ;
V_14 -= V_15 ;
V_13 += V_15 ;
return V_16 - V_14 ;
}
static T_1
F_14 ( struct V_9 * V_7 , struct V_10 * V_11 ,
const char * V_12 , T_2 V_19 )
{
struct V_2 * V_3 = F_5 ( V_7 ) ;
if ( V_19 > 2 )
return - 1 ;
F_8 ( & V_3 -> V_17 . V_20 ) ;
if ( V_12 [ 0 ] == '0' )
V_3 -> V_17 . V_22 = 0 ;
else if ( V_12 [ 0 ] == '1' )
V_3 -> V_17 . V_22 = 1 ;
F_10 ( V_3 ) ;
F_9 ( & V_3 -> V_17 . V_20 ) ;
return V_19 ;
}
static T_1
F_15 ( struct V_9 * V_7 , struct V_10 * V_11 ,
const char * V_12 , T_2 V_19 )
{
struct V_2 * V_3 = F_5 ( V_7 ) ;
if ( V_19 > 2 )
return - 1 ;
F_8 ( & V_3 -> V_17 . V_20 ) ;
if ( V_12 [ 0 ] == '1' )
V_3 -> V_17 . V_23 = 1 ;
F_10 ( V_3 ) ;
F_9 ( & V_3 -> V_17 . V_20 ) ;
return V_19 ;
}
static void F_16 ( struct V_2 * V_3 , enum V_24 V_15 )
{
struct V_1 * V_25 ;
struct V_1 * V_6 = V_3 -> V_26 -> V_27 [ V_15 ] ;
struct V_28 * V_29 = & V_3 -> V_26 -> V_29 ;
if ( V_15 >= V_30 )
return;
F_17 (tmp_timer, active_timers, list)
if ( V_25 == V_6 ) {
V_6 -> V_19 = V_6 -> V_4 ;
return;
}
V_6 -> V_19 = V_6 -> V_4 ;
F_18 ( & V_6 -> V_31 , V_29 ) ;
if ( ! ( F_19 ( V_3 , V_32 ) ) )
F_20 ( V_3 , V_32 , V_32 ) ;
}
static void F_21 ( struct V_2 * V_3 , enum V_24 V_15 )
{
struct V_1 * V_25 , * V_33 ;
struct V_1 * V_6 = V_3 -> V_26 -> V_27 [ V_15 ] ;
struct V_28 * V_29 = & V_3 -> V_26 -> V_29 ;
if ( V_15 >= V_30 )
return;
F_22 (tmp_timer, del_tmp, active_timers, list)
if ( V_25 == V_6 )
F_23 ( & V_6 -> V_31 ) ;
if ( F_24 ( V_29 ) )
F_20 ( V_3 , V_32 , 0 ) ;
}
static inline int F_25 ( struct V_2 * V_3 )
{
struct V_1 * V_25 , * V_33 ;
struct V_28 * V_29 = & V_3 -> V_26 -> V_29 ;
int V_34 = 0 ;
F_22 (tmp_timer, del_tmp, active_timers, list) {
V_25 -> V_19 -- ;
if ( ! V_25 -> V_19 ) {
F_23 ( & V_25 -> V_31 ) ;
V_25 -> F_2 ( V_3 , V_25 -> V_5 ) ;
V_34 = 1 ;
}
}
if ( ( V_34 == 1 ) && F_24 ( V_29 ) )
F_20 ( V_3 , V_32 , 0 ) ;
return V_34 ;
}
static void F_26 ( void * V_35 , unsigned long V_36 )
{
* ( int * ) V_36 = 1 ;
}
static void F_27 ( void * V_35 , unsigned long V_36 )
{
struct V_2 * V_3 = (struct V_2 * ) V_35 ;
F_26 ( V_3 , V_36 ) ;
F_10 ( V_3 ) ;
}
static void F_28 ( void * V_35 , unsigned long V_36 )
{
struct V_2 * V_3 = (struct V_2 * ) V_35 ;
F_26 ( V_3 , V_36 ) ;
F_29 ( V_3 , V_37 , V_38 | V_39 , 0 ) ;
F_20 ( V_3 , V_40 , V_40 ) ;
F_20 ( V_3 , V_41 , V_41 ) ;
F_10 ( V_3 ) ;
}
static void F_30 ( void * V_35 , unsigned long V_36 )
{
struct V_2 * V_3 = (struct V_2 * ) V_35 ;
F_26 ( V_3 , V_36 ) ;
if ( ! F_19 ( V_3 , V_42 ) )
V_3 -> V_17 . V_43 = 0 ;
F_10 ( V_3 ) ;
}
static void F_31 ( void * V_35 , unsigned long V_36 )
{
struct V_2 * V_3 = (struct V_2 * ) V_35 ;
F_26 ( V_3 , V_36 ) ;
if ( V_3 -> V_17 . V_44 -> V_45 == V_46 )
F_10 ( V_3 ) ;
}
static void F_32 ( void * V_35 , unsigned long V_36 )
{
struct V_2 * V_3 = (struct V_2 * ) V_35 ;
if ( ! ( F_19 ( V_3 , V_42 ) ) ) {
V_3 -> V_17 . V_43 = 0 ;
F_16 ( V_3 , V_47 ) ;
F_10 ( V_3 ) ;
}
}
static void F_33 ( void * V_35 , unsigned long V_36 )
{
struct V_2 * V_3 = (struct V_2 * ) V_35 ;
V_3 -> V_17 . V_48 = 1 ;
V_3 -> V_17 . V_22 = 0 ;
if ( V_3 -> V_17 . V_49 )
V_3 -> V_17 . V_49 = 0 ;
F_20 ( V_3 , V_50 , 0 ) ;
F_10 ( V_3 ) ;
}
static int F_34 ( struct V_2 * V_3 )
{
struct V_51 * V_17 = & V_3 -> V_17 ;
V_3 -> V_26 -> V_27 [ V_52 ] =
F_1 ( V_3 , & F_27 , V_53 ,
( unsigned long ) & V_17 -> V_54 ) ;
if ( V_3 -> V_26 -> V_27 [ V_52 ] == NULL )
return - V_55 ;
V_3 -> V_26 -> V_27 [ V_56 ] =
F_1 ( V_3 , & F_28 ,
V_57 , ( unsigned long ) & V_17 -> V_58 ) ;
if ( V_3 -> V_26 -> V_27 [ V_56 ] == NULL )
return - V_55 ;
V_3 -> V_26 -> V_27 [ V_59 ] =
F_1 ( V_3 , & F_27 , V_60 ,
( unsigned long ) & V_17 -> V_61 ) ;
if ( V_3 -> V_26 -> V_27 [ V_59 ] == NULL )
return - V_55 ;
V_3 -> V_26 -> V_27 [ V_62 ] =
F_1 ( V_3 , & F_27 , V_63 ,
( unsigned long ) & V_17 -> V_64 ) ;
if ( V_3 -> V_26 -> V_27 [ V_62 ] == NULL )
return - V_55 ;
V_3 -> V_26 -> V_27 [ V_65 ] =
F_1 ( V_3 , & F_27 , V_66 ,
( unsigned long ) & V_17 -> V_67 ) ;
if ( V_3 -> V_26 -> V_27 [ V_65 ] == NULL )
return - V_55 ;
V_3 -> V_26 -> V_27 [ V_68 ] =
F_1 ( V_3 , & F_30 , V_69 ,
( unsigned long ) & V_17 -> V_70 ) ;
if ( V_3 -> V_26 -> V_27 [ V_68 ] == NULL )
return - V_55 ;
V_3 -> V_26 -> V_27 [ V_71 ] =
F_1 ( V_3 , & F_27 , V_72 ,
( unsigned long ) & V_17 -> V_73 ) ;
if ( V_3 -> V_26 -> V_27 [ V_71 ] == NULL )
return - V_55 ;
V_3 -> V_26 -> V_27 [ V_47 ] =
F_1 ( V_3 , & F_31 , V_74 ,
( unsigned long ) & V_17 -> V_75 ) ;
if ( V_3 -> V_26 -> V_27 [ V_47 ] == NULL )
return - V_55 ;
V_3 -> V_26 -> V_27 [ V_76 ] =
F_1 ( V_3 , & F_26 , V_77 ,
( unsigned long ) & V_17 -> V_48 ) ;
if ( V_3 -> V_26 -> V_27 [ V_76 ] == NULL )
return - V_55 ;
V_3 -> V_26 -> V_27 [ V_78 ] =
F_1 ( V_3 , & F_33 , V_79 , 0 ) ;
if ( V_3 -> V_26 -> V_27 [ V_78 ] == NULL )
return - V_55 ;
V_3 -> V_26 -> V_27 [ V_80 ] = F_1 ( V_3 ,
& F_32 , V_81 , 0 ) ;
if ( V_3 -> V_26 -> V_27 [ V_80 ] == NULL )
return - V_55 ;
return 0 ;
}
static void F_35 ( struct V_51 * V_17 , enum V_82 V_15 )
{
struct V_2 * V_3 = F_36 ( V_17 , struct V_2 , V_17 ) ;
if ( V_15 < V_83 )
F_16 ( V_3 , V_15 ) ;
return;
}
static void F_37 ( struct V_51 * V_17 , enum V_82 V_15 )
{
struct V_2 * V_3 = F_36 ( V_17 , struct V_2 , V_17 ) ;
if ( V_15 < V_83 )
F_21 ( V_3 , V_15 ) ;
return;
}
static void F_38 ( struct V_51 * V_17 , int V_84 )
{
int V_85 ;
struct V_2 * V_3 = F_36 ( V_17 , struct V_2 , V_17 ) ;
if ( V_84 ) {
F_29 ( V_3 , V_37 , V_38 | V_39 ,
V_39 ) ;
if ( V_3 -> V_86 -> V_87 ) {
V_85 = F_39 ( V_3 -> V_86 -> V_87 ) ;
if ( V_85 ) {
F_40 ( V_3 -> V_7 ,
L_2 ,
V_85 ) ;
return;
}
}
F_20 ( V_3 , V_41 , 0 ) ;
V_17 -> V_88 = 0 ;
V_17 -> V_49 = 0 ;
} else {
if ( V_3 -> V_86 -> V_87 )
F_41 ( V_3 -> V_86 -> V_87 ) ;
V_17 -> V_21 = 1 ;
V_17 -> V_18 = 0 ;
}
}
static void F_42 ( struct V_51 * V_17 , int V_84 )
{
struct V_2 * V_3 = F_36 ( V_17 , struct V_2 , V_17 ) ;
if ( V_84 )
F_29 ( V_3 , V_89 , V_90 , V_90 ) ;
else
F_29 ( V_3 , V_89 , V_90 , 0 ) ;
}
static void F_43 ( struct V_51 * V_17 , int V_84 )
{
struct V_2 * V_3 = F_36 ( V_17 , struct V_2 , V_17 ) ;
if ( V_84 )
F_29 ( V_3 , V_37 , V_38 | V_91 ,
V_91 ) ;
else
F_29 ( V_3 , V_37 , V_38 | V_92 ,
V_92 ) ;
}
static void F_44 ( struct V_51 * V_17 )
{
struct V_2 * V_3 = F_36 ( V_17 , struct V_2 , V_17 ) ;
F_20 ( V_3 , V_93 , V_93 ) ;
F_16 ( V_3 , V_78 ) ;
}
static int F_45 ( struct V_51 * V_17 , int V_84 )
{
struct V_2 * V_3 = F_36 ( V_17 , struct V_2 , V_17 ) ;
F_9 ( & V_17 -> V_20 ) ;
if ( V_84 ) {
F_46 ( V_3 ) ;
F_47 ( V_3 , V_94 ) ;
} else {
F_46 ( V_3 ) ;
F_48 ( V_3 ) ;
F_47 ( V_3 , V_95 ) ;
}
F_8 ( & V_17 -> V_20 ) ;
return 0 ;
}
static int F_49 ( struct V_51 * V_17 , int V_84 )
{
struct V_2 * V_3 = F_36 ( V_17 , struct V_2 , V_17 ) ;
F_9 ( & V_17 -> V_20 ) ;
if ( V_84 )
F_50 ( & V_3 -> V_96 ) ;
else
F_51 ( & V_3 -> V_96 ) ;
F_8 ( & V_17 -> V_20 ) ;
return 0 ;
}
int F_52 ( struct V_2 * V_3 )
{
if ( V_3 -> V_17 . V_97 && ! ( V_3 -> V_98 ) &&
V_3 -> V_17 . V_44 -> V_45 < V_99 )
return 0 ;
if ( F_53 ( & V_3 -> V_17 ) ) {
if ( V_3 -> V_17 . V_44 -> V_45 == V_99 ) {
if ( ( V_3 -> V_17 . V_97 ) || ( V_3 -> V_100 ) ||
( V_3 -> V_17 . V_49 ) )
F_10 ( V_3 ) ;
if ( V_3 -> V_100 )
V_3 -> V_100 = false ;
} else if ( V_3 -> V_17 . V_44 -> V_45 == V_46 ) {
if ( V_3 -> V_17 . V_43 ) {
V_3 -> V_17 . V_49 = 0 ;
F_10 ( V_3 ) ;
}
}
}
return 0 ;
}
static void F_54 ( struct V_2 * V_3 )
{
T_3 V_101 , V_102 , V_103 ;
struct V_51 * V_17 = & V_3 -> V_17 ;
V_101 = F_55 ( V_3 ) ;
V_102 = F_19 ( V_3 , V_42 ) ;
V_103 = F_56 ( V_3 , V_37 , V_104 ) ;
switch ( V_3 -> V_17 . V_44 -> V_45 ) {
case V_105 :
if ( V_103 ) {
V_17 -> V_106 = 1 ;
V_17 -> V_18 = 1 ;
F_10 ( V_3 ) ;
}
break;
case V_46 :
if ( V_102 && ( V_101 & V_107 ) && V_103 ) {
V_17 -> V_43 = 1 ;
F_10 ( V_3 ) ;
}
break;
case V_108 :
if ( ( V_101 & V_109 ) && V_103 && V_102 ) {
V_17 -> V_110 = 1 ;
F_10 ( V_3 ) ;
} else if ( V_101 & V_107 ) {
if ( V_17 -> V_110 == 1 )
V_17 -> V_110 = 0 ;
}
break;
case V_111 :
if ( ( V_101 & V_107 ) && ! V_103 ) {
V_17 -> V_112 = 0 ;
V_17 -> V_22 = 0 ;
F_10 ( V_3 ) ;
F_16 ( V_3 , V_80 ) ;
}
break;
case V_113 :
if ( V_101 & V_109 ) {
V_17 -> V_114 = 1 ;
F_16 ( V_3 , V_65 ) ;
}
if ( V_101 & V_115 )
F_21 ( V_3 , V_65 ) ;
if ( V_101 & V_107 ) {
if ( V_17 -> V_114 == 1 ) {
F_21 ( V_3 , V_65 ) ;
V_17 -> V_114 = 0 ;
}
}
break;
case V_116 :
if ( ( V_101 & V_107 ) && ! V_103 ) {
V_17 -> V_106 = 0 ;
if ( V_3 -> V_98 ) {
V_3 -> V_96 . V_117 = 1 ;
}
F_10 ( V_3 ) ;
}
break;
case V_118 :
if ( ( V_101 & V_107 ) && ! V_103 ) {
V_17 -> V_106 = 0 ;
F_10 ( V_3 ) ;
}
break;
case V_119 :
if ( ( V_101 & V_107 ) && V_103 ) {
V_17 -> V_112 = 1 ;
F_10 ( V_3 ) ;
}
break;
default:
break;
}
}
T_4 F_57 ( struct V_2 * V_3 )
{
T_4 V_120 = V_121 ;
T_3 V_122 , V_123 = 0 ;
struct V_51 * V_17 = & V_3 -> V_17 ;
V_122 = F_19 ( V_3 , ~ 0 ) ;
V_123 = V_122 & V_124 & ( V_122 >> 8 ) ;
V_17 -> V_97 = ( V_122 & V_125 ) ? 1 : 0 ;
if ( V_123 ) {
if ( V_123 & V_126 ) {
F_20 ( V_3 , V_126 , V_126 ) ;
V_120 = F_25 ( V_3 ) ;
return V_127 ;
} else if ( V_123 & V_40 ) {
F_20 ( V_3 , V_40 , V_40 ) ;
V_17 -> V_88 = 1 ;
V_17 -> V_21 = 0 ;
} else if ( V_123 & V_128 ) {
F_20 ( V_3 , V_128 , V_128 ) ;
if ( V_17 -> V_97 == 0 ) {
V_17 -> V_21 = 0 ;
V_17 -> V_18 = 1 ;
V_3 -> V_100 = true ;
}
} else if ( V_123 & V_129 ) {
F_20 ( V_3 , V_129 , V_129 ) ;
if ( V_122 & V_42 ) {
V_17 -> V_43 = 1 ;
F_21 ( V_3 , V_47 ) ;
F_21 ( V_3 , V_76 ) ;
V_17 -> V_75 = 0 ;
} else {
V_17 -> V_43 = 0 ;
if ( V_17 -> V_97 )
F_16 ( V_3 , V_47 ) ;
}
} else if ( V_123 & V_130 ) {
F_20 ( V_3 , V_130 , V_130 ) ;
if ( V_122 & V_131 ) {
V_17 -> V_132 = 1 ;
} else {
V_17 -> V_132 = 0 ;
V_17 -> V_106 = 0 ;
}
}
F_10 ( V_3 ) ;
return V_127 ;
}
F_54 ( V_3 ) ;
return V_120 ;
}
void F_58 ( struct V_2 * V_3 )
{
F_10 ( V_3 ) ;
}
int F_59 ( struct V_2 * V_3 )
{
int V_120 = 0 ;
if ( V_3 -> V_133 )
V_3 -> V_44 . V_133 = V_3 -> V_133 ;
else
V_3 -> V_44 . V_134 = V_3 -> V_134 ;
V_3 -> V_44 . V_96 = & V_3 -> V_96 ;
V_3 -> V_17 . V_44 = & V_3 -> V_44 ;
V_3 -> V_17 . V_49 = 1 ;
V_3 -> V_17 . V_97 = F_19 ( V_3 , V_125 ) ? 1 : 0 ;
V_3 -> V_17 . V_44 -> V_45 = V_135 ;
V_3 -> V_17 . V_136 = & V_137 ;
F_60 ( & V_3 -> V_17 . V_20 ) ;
V_3 -> V_26 = F_3 ( V_3 -> V_7 ,
sizeof( struct V_138 ) , V_8 ) ;
if ( ! V_3 -> V_26 )
return - V_55 ;
F_61 ( & V_3 -> V_26 -> V_29 ) ;
V_120 = F_34 ( V_3 ) ;
if ( V_120 ) {
F_40 ( V_3 -> V_7 , L_3 ) ;
return V_120 ;
}
V_120 = F_62 ( & V_3 -> V_7 -> V_139 , & V_140 ) ;
if ( V_120 < 0 ) {
F_63 ( V_3 -> V_7 ,
L_4 , V_120 ) ;
return V_120 ;
}
F_20 ( V_3 , V_141 , V_141 ) ;
if ( V_3 -> V_17 . V_97 ) {
V_3 -> V_17 . V_75 =
F_19 ( V_3 , V_42 ) ? 0 : 1 ;
V_3 -> V_17 . V_43 =
F_19 ( V_3 , V_42 ) ? 1 : 0 ;
F_20 ( V_3 , V_142 , V_142 ) ;
}
return 0 ;
}
void F_64 ( struct V_2 * V_3 )
{
F_65 ( & V_3 -> V_7 -> V_139 , & V_140 ) ;
}
