static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
enum V_10 V_11 ;
int V_12 = F_2 ( V_1 ) ;
int V_13 ;
if ( ( V_3 -> V_14 & V_15 ) == V_16 )
V_11 = V_17 ;
else if ( ( V_3 -> V_14 & V_15 ) == V_18 )
V_11 = V_19 ;
else
return - V_20 ;
if ( V_12 == V_21 )
V_5 = F_3 ( F_4 ( V_1 ) ,
V_22 ) ;
else
return - V_23 ;
if ( V_5 == NULL ) {
F_5 ( L_1 ) ;
return - V_24 ;
}
if ( V_11 != V_5 -> V_25 ) {
F_5 ( L_2 ) ;
F_6 ( V_5 -> V_26 ) ;
return - V_20 ;
}
V_7 = F_7 ( sizeof( * V_7 ) , V_27 ) ;
if ( ! V_7 ) {
F_6 ( V_5 -> V_26 ) ;
return - V_28 ;
}
V_7 -> V_29 . V_30 = V_5 -> V_30 ;
V_7 -> V_29 . V_25 = V_11 ;
V_7 -> V_29 . V_31 = V_5 -> V_31 ;
V_7 -> V_29 . V_32 = V_5 ;
V_9 = F_7 ( sizeof( * V_9 ) , V_27 ) ;
if ( ! V_9 ) {
F_8 ( V_7 ) ;
F_6 ( V_5 -> V_26 ) ;
return - V_28 ;
}
V_9 -> V_33 = V_34 ;
F_9 ( & V_9 -> V_35 ) ;
V_7 -> V_29 . V_9 = V_9 ;
V_3 -> V_31 = ( void * ) V_7 ;
F_10 ( & V_5 -> V_36 ) ;
V_13 = V_5 -> V_30 -> V_37 ( & V_7 -> V_29 ) ;
F_11 ( & V_5 -> V_36 ) ;
if ( V_13 ) {
F_8 ( V_9 ) ;
F_8 ( V_7 ) ;
}
F_6 ( V_5 -> V_26 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
V_7 -> V_29 . V_30 -> free ( & V_7 -> V_29 ) ;
F_8 ( V_7 -> V_29 . V_9 -> V_38 ) ;
F_8 ( V_7 -> V_29 . V_9 ) ;
F_8 ( V_7 ) ;
return 0 ;
}
static void F_13 ( struct V_39 * V_29 ,
struct V_40 * V_41 )
{
if ( ! V_29 -> V_30 -> V_42 )
return;
V_29 -> V_30 -> V_42 ( V_29 , V_41 ) ;
F_14 ( L_3 ,
V_41 -> V_43 , V_41 -> V_44 ) ;
V_29 -> V_9 -> V_45 = V_41 -> V_43 ;
V_29 -> V_9 -> V_46 = V_41 -> V_44 ;
}
static T_1 F_15 ( struct V_39 * V_29 ,
struct V_47 * V_48 )
{
long V_49 ;
F_13 ( V_29 , & V_48 -> V_41 ) ;
if ( V_29 -> V_9 -> V_50 == 0 &&
V_29 -> V_9 -> V_33 == V_51 ) {
F_14 ( L_4 ) ;
return V_29 -> V_9 -> V_52 ;
}
F_14 ( L_5 ,
V_29 -> V_9 -> V_50 ,
V_29 -> V_9 -> V_46 ) ;
if ( V_29 -> V_9 -> V_50 ==
V_29 -> V_9 -> V_46 ) {
F_14 ( L_6 ) ;
return V_29 -> V_9 -> V_52 ;
}
V_49 = V_29 -> V_9 -> V_52 -
( V_29 -> V_9 -> V_53 - V_29 -> V_9 -> V_45 ) ;
F_14 ( L_7 , V_49 ,
V_29 -> V_9 -> V_53 ,
V_29 -> V_9 -> V_45 ) ;
if ( V_49 >= V_29 -> V_9 -> V_52 )
V_49 -= V_29 -> V_9 -> V_52 ;
F_14 ( L_8 , V_49 ) ;
V_48 -> V_48 = V_49 ;
return V_49 ;
}
static inline T_1 F_16 ( struct V_39 * V_29 )
{
struct V_47 V_48 ;
return F_15 ( V_29 , & V_48 ) ;
}
static int
F_17 ( struct V_39 * V_29 , unsigned long V_54 )
{
struct V_47 V_55 ;
T_1 V_48 ;
V_48 = F_15 ( V_29 , & V_55 ) ;
V_55 . V_48 = V_48 ;
if ( F_18 ( ( V_56 V_57 * ) V_54 ,
& V_55 , sizeof( V_55 ) ) )
return - V_58 ;
return 0 ;
}
static int F_19 ( struct V_39 * V_29 ,
const char V_57 * V_59 , T_1 V_60 )
{
void * V_61 ;
T_1 V_62 ;
struct V_8 * V_9 = V_29 -> V_9 ;
V_61 = V_9 -> V_38 + V_9 -> V_53 ;
F_14 ( L_9 ,
( unsigned long ) V_60 , V_9 -> V_53 ) ;
if ( V_60 < V_9 -> V_52 - V_9 -> V_53 ) {
if ( F_20 ( V_61 , V_59 , V_60 ) )
return - V_58 ;
V_9 -> V_53 += V_60 ;
} else {
V_62 = V_9 -> V_52 - V_9 -> V_53 ;
if ( F_20 ( V_61 , V_59 , V_62 ) )
return - V_58 ;
if ( F_20 ( V_9 -> V_38 , V_59 + V_62 , V_60 - V_62 ) )
return - V_58 ;
V_9 -> V_53 = V_60 - V_62 ;
}
if ( V_29 -> V_30 -> V_63 )
V_29 -> V_30 -> V_63 ( V_29 , V_60 ) ;
return V_60 ;
}
static T_2 F_21 ( struct V_2 * V_3 , const char V_57 * V_59 ,
T_1 V_60 , T_3 * V_64 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
struct V_39 * V_29 ;
T_1 V_48 ;
int V_65 ;
if ( F_22 ( ! V_7 ) )
return - V_58 ;
V_29 = & V_7 -> V_29 ;
F_10 ( & V_29 -> V_32 -> V_36 ) ;
if ( V_29 -> V_9 -> V_33 != V_51 &&
V_29 -> V_9 -> V_33 != V_66 ) {
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return - V_23 ;
}
V_48 = F_16 ( V_29 ) ;
F_14 ( L_10 , ( unsigned long ) V_48 ) ;
if ( V_48 > V_60 )
V_48 = V_60 ;
if ( V_29 -> V_30 -> V_62 )
V_65 = V_29 -> V_30 -> V_62 ( V_29 , V_59 , V_48 ) ;
else
V_65 = F_19 ( V_29 , V_59 , V_48 ) ;
if ( V_65 > 0 )
V_29 -> V_9 -> V_50 += V_65 ;
if ( V_29 -> V_9 -> V_33 == V_51 ) {
V_29 -> V_9 -> V_33 = V_67 ;
F_14 ( L_11 ) ;
}
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return V_65 ;
}
static T_2 F_23 ( struct V_2 * V_3 , char V_57 * V_59 ,
T_1 V_60 , T_3 * V_64 )
{
return - V_68 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_69 * V_70 )
{
return - V_68 ;
}
static inline int F_25 ( struct V_39 * V_29 )
{
if ( V_29 -> V_25 == V_17 )
return V_71 | V_72 ;
else
return V_73 | V_74 ;
}
static unsigned int F_26 ( struct V_2 * V_3 , T_4 * V_75 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
struct V_39 * V_29 ;
T_1 V_48 ;
int V_65 = 0 ;
if ( F_22 ( ! V_7 ) )
return - V_58 ;
V_29 = & V_7 -> V_29 ;
if ( F_22 ( ! V_29 ) )
return - V_58 ;
F_10 ( & V_29 -> V_32 -> V_36 ) ;
if ( V_29 -> V_9 -> V_33 == V_76 ||
V_29 -> V_9 -> V_33 == V_34 ) {
V_65 = - V_23 ;
goto V_77;
}
F_27 ( V_3 , & V_29 -> V_9 -> V_35 , V_75 ) ;
V_48 = F_16 ( V_29 ) ;
F_14 ( L_12 , ( unsigned long ) V_48 ) ;
switch ( V_29 -> V_9 -> V_33 ) {
case V_78 :
V_65 = F_25 ( V_29 ) ;
V_29 -> V_9 -> V_33 = V_51 ;
break;
case V_66 :
case V_67 :
case V_76 :
if ( V_48 >= V_29 -> V_9 -> V_79 )
V_65 = F_25 ( V_29 ) ;
break;
default:
if ( V_29 -> V_25 == V_17 )
V_65 = V_71 | V_72 | V_80 ;
else
V_65 = V_73 | V_74 | V_80 ;
break;
}
V_77:
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return V_65 ;
}
static int
F_28 ( struct V_39 * V_29 , unsigned long V_54 )
{
int V_65 ;
struct V_81 V_82 ;
if ( ! V_29 -> V_30 -> V_83 )
return - V_68 ;
V_65 = V_29 -> V_30 -> V_83 ( V_29 , & V_82 ) ;
if ( V_65 )
goto V_77;
if ( F_18 ( ( void V_57 * ) V_54 , & V_82 , sizeof( V_82 ) ) )
V_65 = - V_58 ;
V_77:
return V_65 ;
}
static int
F_29 ( struct V_39 * V_29 , unsigned long V_54 )
{
int V_65 ;
struct V_84 * V_82 ;
if ( ! V_29 -> V_30 -> V_85 )
return - V_68 ;
V_82 = F_30 ( sizeof( * V_82 ) , V_27 ) ;
if ( ! V_82 )
return - V_28 ;
V_65 = V_29 -> V_30 -> V_85 ( V_29 , V_82 ) ;
if ( V_65 )
goto V_77;
if ( F_18 ( ( void V_57 * ) V_54 , V_82 , sizeof( * V_82 ) ) )
V_65 = - V_58 ;
V_77:
F_8 ( V_82 ) ;
return V_65 ;
}
static int F_31 ( struct V_39 * V_29 ,
struct V_86 * V_87 )
{
unsigned int V_52 ;
void * V_38 ;
V_52 = V_87 -> V_38 . V_79 * V_87 -> V_38 . V_88 ;
if ( V_29 -> V_30 -> V_62 ) {
V_38 = NULL ;
} else {
V_38 = F_30 ( V_52 , V_27 ) ;
if ( ! V_38 )
return - V_28 ;
}
V_29 -> V_9 -> V_79 = V_87 -> V_38 . V_79 ;
V_29 -> V_9 -> V_88 = V_87 -> V_38 . V_88 ;
V_29 -> V_9 -> V_38 = V_38 ;
V_29 -> V_9 -> V_52 = V_52 ;
return 0 ;
}
static int F_32 ( struct V_86 * V_87 )
{
if ( V_87 -> V_38 . V_79 == 0 ||
V_87 -> V_38 . V_88 > V_89 / V_87 -> V_38 . V_79 )
return - V_20 ;
if ( V_87 -> V_90 . V_91 == 0 || V_87 -> V_90 . V_91 > V_92 )
return - V_20 ;
if ( V_87 -> V_90 . V_93 == 0 || V_87 -> V_90 . V_94 == 0 )
return - V_20 ;
if ( ! ( V_87 -> V_90 . V_95 & V_96 ) )
return - V_20 ;
return 0 ;
}
static int
F_33 ( struct V_39 * V_29 , unsigned long V_54 )
{
struct V_86 * V_87 ;
int V_65 ;
if ( V_29 -> V_9 -> V_33 == V_34 ) {
V_87 = F_30 ( sizeof( * V_87 ) , V_27 ) ;
if ( ! V_87 )
return - V_28 ;
if ( F_20 ( V_87 , ( void V_57 * ) V_54 , sizeof( * V_87 ) ) ) {
V_65 = - V_58 ;
goto V_77;
}
V_65 = F_32 ( V_87 ) ;
if ( V_65 )
goto V_77;
V_65 = F_31 ( V_29 , V_87 ) ;
if ( V_65 ) {
V_65 = - V_28 ;
goto V_77;
}
V_65 = V_29 -> V_30 -> V_97 ( V_29 , V_87 ) ;
if ( V_65 )
goto V_77;
V_29 -> V_9 -> V_33 = V_51 ;
} else {
return - V_98 ;
}
V_77:
F_8 ( V_87 ) ;
return V_65 ;
}
static int
F_34 ( struct V_39 * V_29 , unsigned long V_54 )
{
struct V_99 * V_87 ;
int V_65 ;
if ( ! V_29 -> V_30 -> V_100 )
return - V_23 ;
V_87 = F_30 ( sizeof( * V_87 ) , V_27 ) ;
if ( ! V_87 )
return - V_28 ;
V_65 = V_29 -> V_30 -> V_100 ( V_29 , V_87 ) ;
if ( V_65 )
goto V_77;
if ( F_18 ( ( char V_57 * ) V_54 , V_87 , sizeof( * V_87 ) ) )
V_65 = - V_58 ;
V_77:
F_8 ( V_87 ) ;
return V_65 ;
}
static inline int
V_40 ( struct V_39 * V_29 , unsigned long V_54 )
{
struct V_40 V_41 ;
F_13 ( V_29 , & V_41 ) ;
return F_18 ( (struct V_40 V_57 * ) V_54 ,
& V_41 , sizeof( V_41 ) ) ? - V_58 : 0 ;
}
static int F_35 ( struct V_39 * V_29 )
{
int V_65 ;
if ( V_29 -> V_9 -> V_33 != V_66 )
return - V_98 ;
V_65 = V_29 -> V_30 -> V_101 ( V_29 , V_102 ) ;
if ( ! V_65 )
V_29 -> V_9 -> V_33 = V_76 ;
return V_65 ;
}
static int F_36 ( struct V_39 * V_29 )
{
int V_65 ;
if ( V_29 -> V_9 -> V_33 != V_76 )
return - V_98 ;
V_65 = V_29 -> V_30 -> V_101 ( V_29 , V_103 ) ;
if ( ! V_65 )
V_29 -> V_9 -> V_33 = V_66 ;
return V_65 ;
}
static int F_37 ( struct V_39 * V_29 )
{
int V_65 ;
if ( V_29 -> V_9 -> V_33 != V_67 )
return - V_98 ;
V_65 = V_29 -> V_30 -> V_101 ( V_29 , V_104 ) ;
if ( ! V_65 )
V_29 -> V_9 -> V_33 = V_66 ;
return V_65 ;
}
static int F_38 ( struct V_39 * V_29 )
{
int V_65 ;
if ( V_29 -> V_9 -> V_33 == V_67 ||
V_29 -> V_9 -> V_33 == V_51 )
return - V_98 ;
V_65 = V_29 -> V_30 -> V_101 ( V_29 , V_105 ) ;
if ( ! V_65 ) {
V_29 -> V_9 -> V_33 = V_51 ;
F_39 ( & V_29 -> V_9 -> V_35 ) ;
V_29 -> V_9 -> V_45 = 0 ;
V_29 -> V_9 -> V_53 = 0 ;
V_29 -> V_9 -> V_50 = 0 ;
V_29 -> V_9 -> V_46 = 0 ;
}
return V_65 ;
}
static int F_40 ( struct V_39 * V_29 )
{
int V_65 ;
if ( V_29 -> V_9 -> V_33 == V_67 ||
V_29 -> V_9 -> V_33 == V_51 )
return - V_98 ;
V_65 = V_29 -> V_30 -> V_101 ( V_29 , V_106 ) ;
if ( ! V_65 ) {
V_29 -> V_9 -> V_33 = V_78 ;
F_39 ( & V_29 -> V_9 -> V_35 ) ;
}
return V_65 ;
}
static long F_41 ( struct V_2 * V_3 , unsigned int V_107 , unsigned long V_54 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
struct V_39 * V_29 ;
int V_65 = - V_108 ;
if ( F_22 ( ! V_7 ) )
return - V_58 ;
V_29 = & V_7 -> V_29 ;
if ( F_22 ( ! V_29 ) )
return - V_58 ;
F_10 ( & V_29 -> V_32 -> V_36 ) ;
switch ( F_42 ( V_107 ) ) {
case F_42 ( V_109 ) :
F_43 ( V_110 ,
( int V_57 * ) V_54 ) ? - V_58 : 0 ;
break;
case F_42 ( V_111 ) :
V_65 = F_28 ( V_29 , V_54 ) ;
break;
case F_42 ( V_112 ) :
V_65 = F_29 ( V_29 , V_54 ) ;
break;
case F_42 ( V_113 ) :
V_65 = F_33 ( V_29 , V_54 ) ;
break;
case F_42 ( V_114 ) :
V_65 = F_34 ( V_29 , V_54 ) ;
break;
case F_42 ( V_115 ) :
V_65 = V_40 ( V_29 , V_54 ) ;
break;
case F_42 ( V_116 ) :
V_65 = F_17 ( V_29 , V_54 ) ;
break;
case F_42 ( V_117 ) :
V_65 = F_35 ( V_29 ) ;
break;
case F_42 ( V_118 ) :
V_65 = F_36 ( V_29 ) ;
break;
case F_42 ( V_119 ) :
V_65 = F_37 ( V_29 ) ;
break;
case F_42 ( V_120 ) :
V_65 = F_38 ( V_29 ) ;
break;
case F_42 ( V_121 ) :
V_65 = F_40 ( V_29 ) ;
break;
}
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return V_65 ;
}
static int F_44 ( struct V_122 * V_32 )
{
int V_13 = - V_20 ;
char V_123 [ 16 ] ;
struct V_4 * V_5 ;
if ( F_22 ( ! V_32 || ! V_32 -> V_124 ) )
return - V_23 ;
V_5 = V_32 -> V_124 ;
sprintf ( V_123 , L_13 , V_5 -> V_26 -> V_125 , V_5 -> V_32 ) ;
F_14 ( L_14 , V_123 , V_5 -> V_126 ,
V_5 -> V_25 ) ;
V_13 = F_45 ( V_22 , V_5 -> V_26 ,
V_5 -> V_32 , & V_127 , V_5 , V_123 ) ;
if ( V_13 < 0 ) {
F_5 ( L_15 , V_13 ) ;
return V_13 ;
}
return V_13 ;
}
static int F_46 ( struct V_122 * V_32 )
{
struct V_4 * V_5 ;
V_5 = V_32 -> V_124 ;
F_47 ( V_5 -> V_25 , V_5 -> V_26 , V_5 -> V_32 ) ;
return 0 ;
}
int F_48 ( struct V_128 * V_26 , int V_32 ,
int V_11 , struct V_4 * V_5 )
{
static struct V_129 V_30 = {
. V_130 = NULL ,
. V_131 = F_44 ,
. V_132 = F_46 ,
} ;
V_5 -> V_26 = V_26 ;
V_5 -> V_32 = V_32 ;
V_5 -> V_25 = V_11 ;
return F_49 ( V_26 , V_133 , V_5 , & V_30 ) ;
}
static int F_50 ( struct V_4 * V_32 )
{
int V_13 ;
if ( ! V_32 -> V_26 )
return - V_20 ;
V_13 = F_51 ( V_32 -> V_26 ) ;
if ( V_13 )
goto V_77;
return 0 ;
V_77:
F_5 ( L_16 , V_13 ) ;
return V_13 ;
}
static int F_52 ( struct V_4 * V_32 )
{
return F_53 ( V_32 -> V_26 ) ;
}
int F_54 ( struct V_4 * V_32 )
{
int V_65 ;
if ( V_32 -> V_126 == NULL || V_32 -> V_134 == NULL || V_32 -> V_30 == NULL )
return - V_20 ;
F_14 ( L_17 , V_32 -> V_126 ) ;
if ( F_22 ( ! V_32 -> V_30 -> V_37 ) )
return - V_20 ;
if ( F_22 ( ! V_32 -> V_30 -> free ) )
return - V_20 ;
if ( F_22 ( ! V_32 -> V_30 -> V_97 ) )
return - V_20 ;
if ( F_22 ( ! V_32 -> V_30 -> V_101 ) )
return - V_20 ;
F_55 ( & V_32 -> V_36 ) ;
F_10 ( & V_135 ) ;
V_65 = F_50 ( V_32 ) ;
F_11 ( & V_135 ) ;
return V_65 ;
}
int F_56 ( struct V_4 * V_32 )
{
F_14 ( L_18 , V_32 -> V_126 ) ;
F_10 ( & V_135 ) ;
F_52 ( V_32 ) ;
F_11 ( & V_135 ) ;
return 0 ;
}
static int T_5 F_57 ( void )
{
return 0 ;
}
static void T_6 F_58 ( void )
{
}
