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
return - V_20 ;
}
V_7 = F_6 ( sizeof( * V_7 ) , V_26 ) ;
if ( ! V_7 )
return - V_27 ;
V_7 -> V_28 . V_29 = V_5 -> V_29 ;
V_7 -> V_28 . V_25 = V_11 ;
V_7 -> V_28 . V_30 = V_5 -> V_30 ;
V_7 -> V_28 . V_31 = V_5 ;
V_9 = F_6 ( sizeof( * V_9 ) , V_26 ) ;
if ( ! V_9 ) {
F_7 ( V_7 ) ;
return - V_27 ;
}
V_9 -> V_32 = V_33 ;
F_8 ( & V_9 -> V_34 ) ;
V_7 -> V_28 . V_9 = V_9 ;
V_3 -> V_30 = ( void * ) V_7 ;
F_9 ( & V_5 -> V_35 ) ;
V_13 = V_5 -> V_29 -> V_36 ( & V_7 -> V_28 ) ;
F_10 ( & V_5 -> V_35 ) ;
if ( V_13 ) {
F_7 ( V_9 ) ;
F_7 ( V_7 ) ;
}
return V_13 ;
}
static int F_11 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_30 ;
V_7 -> V_28 . V_29 -> free ( & V_7 -> V_28 ) ;
F_7 ( V_7 -> V_28 . V_9 -> V_37 ) ;
F_7 ( V_7 -> V_28 . V_9 ) ;
F_7 ( V_7 ) ;
return 0 ;
}
static void F_12 ( struct V_38 * V_28 ,
struct V_39 * V_40 )
{
if ( ! V_28 -> V_29 -> V_41 )
return;
V_28 -> V_29 -> V_41 ( V_28 , V_40 ) ;
F_13 ( L_3 ,
V_40 -> V_42 , V_40 -> V_43 ) ;
V_28 -> V_9 -> V_44 = V_40 -> V_42 ;
V_28 -> V_9 -> V_45 = V_40 -> V_43 ;
}
static T_1 F_14 ( struct V_38 * V_28 ,
struct V_46 * V_47 )
{
long V_48 ;
F_12 ( V_28 , & V_47 -> V_40 ) ;
if ( V_28 -> V_9 -> V_49 == 0 &&
V_28 -> V_9 -> V_32 == V_50 ) {
F_13 ( L_4 ) ;
return V_28 -> V_9 -> V_51 ;
}
F_13 ( L_5 ,
V_28 -> V_9 -> V_49 ,
V_28 -> V_9 -> V_45 ) ;
if ( V_28 -> V_9 -> V_49 ==
V_28 -> V_9 -> V_45 ) {
F_13 ( L_6 ) ;
return V_28 -> V_9 -> V_51 ;
}
V_48 = V_28 -> V_9 -> V_51 -
( V_28 -> V_9 -> V_52 - V_28 -> V_9 -> V_44 ) ;
F_13 ( L_7 , V_48 ,
V_28 -> V_9 -> V_52 ,
V_28 -> V_9 -> V_44 ) ;
if ( V_48 >= V_28 -> V_9 -> V_51 )
V_48 -= V_28 -> V_9 -> V_51 ;
F_13 ( L_8 , V_48 ) ;
V_47 -> V_47 = V_48 ;
return V_48 ;
}
static inline T_1 F_15 ( struct V_38 * V_28 )
{
struct V_46 V_47 ;
return F_14 ( V_28 , & V_47 ) ;
}
static int
F_16 ( struct V_38 * V_28 , unsigned long V_53 )
{
struct V_46 V_54 ;
T_1 V_47 ;
V_47 = F_14 ( V_28 , & V_54 ) ;
V_54 . V_47 = V_47 ;
if ( F_17 ( ( V_55 V_56 * ) V_53 ,
& V_54 , sizeof( V_54 ) ) )
return - V_57 ;
return 0 ;
}
static int F_18 ( struct V_38 * V_28 ,
const char V_56 * V_58 , T_1 V_59 )
{
void * V_60 ;
T_1 V_61 ;
struct V_8 * V_9 = V_28 -> V_9 ;
V_60 = V_9 -> V_37 + V_9 -> V_52 ;
F_13 ( L_9 ,
( unsigned long ) V_59 , V_9 -> V_52 ) ;
if ( V_59 < V_9 -> V_51 - V_9 -> V_52 ) {
if ( F_19 ( V_60 , V_58 , V_59 ) )
return - V_57 ;
V_9 -> V_52 += V_59 ;
} else {
V_61 = V_9 -> V_51 - V_9 -> V_52 ;
if ( F_19 ( V_60 , V_58 , V_61 ) )
return - V_57 ;
if ( F_19 ( V_9 -> V_37 , V_58 + V_61 , V_59 - V_61 ) )
return - V_57 ;
V_9 -> V_52 = V_59 - V_61 ;
}
if ( V_28 -> V_29 -> V_62 )
V_28 -> V_29 -> V_62 ( V_28 , V_59 ) ;
return V_59 ;
}
static T_2 F_20 ( struct V_2 * V_3 , const char V_56 * V_58 ,
T_1 V_59 , T_3 * V_63 )
{
struct V_6 * V_7 = V_3 -> V_30 ;
struct V_38 * V_28 ;
T_1 V_47 ;
int V_64 ;
if ( F_21 ( ! V_7 ) )
return - V_57 ;
V_28 = & V_7 -> V_28 ;
F_9 ( & V_28 -> V_31 -> V_35 ) ;
if ( V_28 -> V_9 -> V_32 != V_50 &&
V_28 -> V_9 -> V_32 != V_65 ) {
F_10 ( & V_28 -> V_31 -> V_35 ) ;
return - V_23 ;
}
V_47 = F_15 ( V_28 ) ;
F_13 ( L_10 , ( unsigned long ) V_47 ) ;
if ( V_47 > V_59 )
V_47 = V_59 ;
if ( V_28 -> V_29 -> V_61 )
V_64 = V_28 -> V_29 -> V_61 ( V_28 , V_58 , V_47 ) ;
else
V_64 = F_18 ( V_28 , V_58 , V_47 ) ;
if ( V_64 > 0 )
V_28 -> V_9 -> V_49 += V_64 ;
if ( V_28 -> V_9 -> V_32 == V_50 ) {
V_28 -> V_9 -> V_32 = V_66 ;
F_13 ( L_11 ) ;
}
F_10 ( & V_28 -> V_31 -> V_35 ) ;
return V_64 ;
}
static T_2 F_22 ( struct V_2 * V_3 , char V_56 * V_58 ,
T_1 V_59 , T_3 * V_63 )
{
return - V_67 ;
}
static int F_23 ( struct V_2 * V_3 , struct V_68 * V_69 )
{
return - V_67 ;
}
static inline int F_24 ( struct V_38 * V_28 )
{
if ( V_28 -> V_25 == V_17 )
return V_70 | V_71 ;
else
return V_72 | V_73 ;
}
static unsigned int F_25 ( struct V_2 * V_3 , T_4 * V_74 )
{
struct V_6 * V_7 = V_3 -> V_30 ;
struct V_38 * V_28 ;
T_1 V_47 ;
int V_64 = 0 ;
if ( F_21 ( ! V_7 ) )
return - V_57 ;
V_28 = & V_7 -> V_28 ;
if ( F_21 ( ! V_28 ) )
return - V_57 ;
F_9 ( & V_28 -> V_31 -> V_35 ) ;
if ( V_28 -> V_9 -> V_32 == V_75 ||
V_28 -> V_9 -> V_32 == V_33 ) {
V_64 = - V_23 ;
goto V_76;
}
F_26 ( V_3 , & V_28 -> V_9 -> V_34 , V_74 ) ;
V_47 = F_15 ( V_28 ) ;
F_13 ( L_12 , ( unsigned long ) V_47 ) ;
switch ( V_28 -> V_9 -> V_32 ) {
case V_77 :
V_64 = F_24 ( V_28 ) ;
V_28 -> V_9 -> V_32 = V_50 ;
break;
case V_65 :
case V_66 :
case V_75 :
if ( V_47 >= V_28 -> V_9 -> V_78 )
V_64 = F_24 ( V_28 ) ;
break;
default:
if ( V_28 -> V_25 == V_17 )
V_64 = V_70 | V_71 | V_79 ;
else
V_64 = V_72 | V_73 | V_79 ;
break;
}
V_76:
F_10 ( & V_28 -> V_31 -> V_35 ) ;
return V_64 ;
}
static int
F_27 ( struct V_38 * V_28 , unsigned long V_53 )
{
int V_64 ;
struct V_80 V_81 ;
if ( ! V_28 -> V_29 -> V_82 )
return - V_67 ;
V_64 = V_28 -> V_29 -> V_82 ( V_28 , & V_81 ) ;
if ( V_64 )
goto V_76;
if ( F_17 ( ( void V_56 * ) V_53 , & V_81 , sizeof( V_81 ) ) )
V_64 = - V_57 ;
V_76:
return V_64 ;
}
static int
F_28 ( struct V_38 * V_28 , unsigned long V_53 )
{
int V_64 ;
struct V_83 * V_81 ;
if ( ! V_28 -> V_29 -> V_84 )
return - V_67 ;
V_81 = F_29 ( sizeof( * V_81 ) , V_26 ) ;
if ( ! V_81 )
return - V_27 ;
V_64 = V_28 -> V_29 -> V_84 ( V_28 , V_81 ) ;
if ( V_64 )
goto V_76;
if ( F_17 ( ( void V_56 * ) V_53 , V_81 , sizeof( * V_81 ) ) )
V_64 = - V_57 ;
V_76:
F_7 ( V_81 ) ;
return V_64 ;
}
static int F_30 ( struct V_38 * V_28 ,
struct V_85 * V_86 )
{
unsigned int V_51 ;
void * V_37 ;
V_51 = V_86 -> V_37 . V_78 * V_86 -> V_37 . V_87 ;
if ( V_28 -> V_29 -> V_61 ) {
V_37 = NULL ;
} else {
V_37 = F_29 ( V_51 , V_26 ) ;
if ( ! V_37 )
return - V_27 ;
}
V_28 -> V_9 -> V_78 = V_86 -> V_37 . V_78 ;
V_28 -> V_9 -> V_87 = V_86 -> V_37 . V_87 ;
V_28 -> V_9 -> V_37 = V_37 ;
V_28 -> V_9 -> V_51 = V_51 ;
return 0 ;
}
static int
F_31 ( struct V_38 * V_28 , unsigned long V_53 )
{
struct V_85 * V_86 ;
int V_64 ;
if ( V_28 -> V_9 -> V_32 == V_33 ) {
V_86 = F_29 ( sizeof( * V_86 ) , V_26 ) ;
if ( ! V_86 )
return - V_27 ;
if ( F_19 ( V_86 , ( void V_56 * ) V_53 , sizeof( * V_86 ) ) ) {
V_64 = - V_57 ;
goto V_76;
}
V_64 = F_30 ( V_28 , V_86 ) ;
if ( V_64 ) {
V_64 = - V_27 ;
goto V_76;
}
V_64 = V_28 -> V_29 -> V_88 ( V_28 , V_86 ) ;
if ( V_64 )
goto V_76;
V_28 -> V_9 -> V_32 = V_50 ;
} else {
return - V_89 ;
}
V_76:
F_7 ( V_86 ) ;
return V_64 ;
}
static int
F_32 ( struct V_38 * V_28 , unsigned long V_53 )
{
struct V_90 * V_86 ;
int V_64 ;
if ( ! V_28 -> V_29 -> V_91 )
return - V_23 ;
V_86 = F_29 ( sizeof( * V_86 ) , V_26 ) ;
if ( ! V_86 )
return - V_27 ;
V_64 = V_28 -> V_29 -> V_91 ( V_28 , V_86 ) ;
if ( V_64 )
goto V_76;
if ( F_17 ( ( char V_56 * ) V_53 , V_86 , sizeof( * V_86 ) ) )
V_64 = - V_57 ;
V_76:
F_7 ( V_86 ) ;
return V_64 ;
}
static inline int
V_39 ( struct V_38 * V_28 , unsigned long V_53 )
{
struct V_39 V_40 ;
F_12 ( V_28 , & V_40 ) ;
return F_17 ( (struct V_39 V_56 * ) V_53 ,
& V_40 , sizeof( V_40 ) ) ? - V_57 : 0 ;
}
static int F_33 ( struct V_38 * V_28 )
{
int V_64 ;
if ( V_28 -> V_9 -> V_32 != V_65 )
return - V_89 ;
V_64 = V_28 -> V_29 -> V_92 ( V_28 , V_93 ) ;
if ( ! V_64 )
V_28 -> V_9 -> V_32 = V_75 ;
return V_64 ;
}
static int F_34 ( struct V_38 * V_28 )
{
int V_64 ;
if ( V_28 -> V_9 -> V_32 != V_75 )
return - V_89 ;
V_64 = V_28 -> V_29 -> V_92 ( V_28 , V_94 ) ;
if ( ! V_64 )
V_28 -> V_9 -> V_32 = V_65 ;
return V_64 ;
}
static int F_35 ( struct V_38 * V_28 )
{
int V_64 ;
if ( V_28 -> V_9 -> V_32 != V_66 )
return - V_89 ;
V_64 = V_28 -> V_29 -> V_92 ( V_28 , V_95 ) ;
if ( ! V_64 )
V_28 -> V_9 -> V_32 = V_65 ;
return V_64 ;
}
static int F_36 ( struct V_38 * V_28 )
{
int V_64 ;
if ( V_28 -> V_9 -> V_32 == V_66 ||
V_28 -> V_9 -> V_32 == V_50 )
return - V_89 ;
V_64 = V_28 -> V_29 -> V_92 ( V_28 , V_96 ) ;
if ( ! V_64 ) {
V_28 -> V_9 -> V_32 = V_50 ;
F_37 ( & V_28 -> V_9 -> V_34 ) ;
V_28 -> V_9 -> V_44 = 0 ;
V_28 -> V_9 -> V_52 = 0 ;
V_28 -> V_9 -> V_49 = 0 ;
V_28 -> V_9 -> V_45 = 0 ;
}
return V_64 ;
}
static int F_38 ( struct V_38 * V_28 )
{
int V_64 ;
if ( V_28 -> V_9 -> V_32 == V_66 ||
V_28 -> V_9 -> V_32 == V_50 )
return - V_89 ;
V_64 = V_28 -> V_29 -> V_92 ( V_28 , V_97 ) ;
if ( ! V_64 ) {
V_28 -> V_9 -> V_32 = V_77 ;
F_37 ( & V_28 -> V_9 -> V_34 ) ;
}
return V_64 ;
}
static long F_39 ( struct V_2 * V_3 , unsigned int V_98 , unsigned long V_53 )
{
struct V_6 * V_7 = V_3 -> V_30 ;
struct V_38 * V_28 ;
int V_64 = - V_99 ;
if ( F_21 ( ! V_7 ) )
return - V_57 ;
V_28 = & V_7 -> V_28 ;
if ( F_21 ( ! V_28 ) )
return - V_57 ;
F_9 ( & V_28 -> V_31 -> V_35 ) ;
switch ( F_40 ( V_98 ) ) {
case F_40 ( V_100 ) :
F_41 ( V_101 ,
( int V_56 * ) V_53 ) ? - V_57 : 0 ;
break;
case F_40 ( V_102 ) :
V_64 = F_27 ( V_28 , V_53 ) ;
break;
case F_40 ( V_103 ) :
V_64 = F_28 ( V_28 , V_53 ) ;
break;
case F_40 ( V_104 ) :
V_64 = F_31 ( V_28 , V_53 ) ;
break;
case F_40 ( V_105 ) :
V_64 = F_32 ( V_28 , V_53 ) ;
break;
case F_40 ( V_106 ) :
V_64 = V_39 ( V_28 , V_53 ) ;
break;
case F_40 ( V_107 ) :
V_64 = F_16 ( V_28 , V_53 ) ;
break;
case F_40 ( V_108 ) :
V_64 = F_33 ( V_28 ) ;
break;
case F_40 ( V_109 ) :
V_64 = F_34 ( V_28 ) ;
break;
case F_40 ( V_110 ) :
V_64 = F_35 ( V_28 ) ;
break;
case F_40 ( V_111 ) :
V_64 = F_36 ( V_28 ) ;
break;
case F_40 ( V_112 ) :
V_64 = F_38 ( V_28 ) ;
break;
}
F_10 ( & V_28 -> V_31 -> V_35 ) ;
return V_64 ;
}
static int F_42 ( struct V_113 * V_31 )
{
int V_13 = - V_20 ;
char V_114 [ 16 ] ;
struct V_4 * V_5 ;
if ( F_21 ( ! V_31 || ! V_31 -> V_115 ) )
return - V_23 ;
V_5 = V_31 -> V_115 ;
sprintf ( V_114 , L_13 , V_5 -> V_116 -> V_117 , V_5 -> V_31 ) ;
F_13 ( L_14 , V_114 , V_5 -> V_118 ,
V_5 -> V_25 ) ;
V_13 = F_43 ( V_22 , V_5 -> V_116 ,
V_5 -> V_31 , & V_119 , V_5 , V_114 ) ;
if ( V_13 < 0 ) {
F_5 ( L_15 , V_13 ) ;
return V_13 ;
}
return V_13 ;
}
static int F_44 ( struct V_113 * V_31 )
{
struct V_4 * V_5 ;
V_5 = V_31 -> V_115 ;
F_45 ( V_5 -> V_25 , V_5 -> V_116 , V_5 -> V_31 ) ;
return 0 ;
}
int F_46 ( struct V_120 * V_116 , int V_31 ,
int V_11 , struct V_4 * V_5 )
{
static struct V_121 V_29 = {
. V_122 = NULL ,
. V_123 = F_42 ,
. V_124 = F_44 ,
} ;
V_5 -> V_116 = V_116 ;
V_5 -> V_31 = V_31 ;
V_5 -> V_25 = V_11 ;
return F_47 ( V_116 , V_125 , V_5 , & V_29 ) ;
}
static int F_48 ( struct V_4 * V_31 )
{
int V_13 ;
if ( ! V_31 -> V_116 )
return - V_20 ;
V_13 = F_49 ( V_31 -> V_116 ) ;
if ( V_13 )
goto V_76;
return 0 ;
V_76:
F_5 ( L_16 , V_13 ) ;
return V_13 ;
}
static int F_50 ( struct V_4 * V_31 )
{
return F_51 ( V_31 -> V_116 ) ;
}
int F_52 ( struct V_4 * V_31 )
{
int V_64 ;
if ( V_31 -> V_118 == NULL || V_31 -> V_126 == NULL || V_31 -> V_29 == NULL )
return - V_20 ;
F_13 ( L_17 , V_31 -> V_118 ) ;
if ( F_21 ( ! V_31 -> V_29 -> V_36 ) )
return - V_20 ;
if ( F_21 ( ! V_31 -> V_29 -> free ) )
return - V_20 ;
if ( F_21 ( ! V_31 -> V_29 -> V_88 ) )
return - V_20 ;
if ( F_21 ( ! V_31 -> V_29 -> V_92 ) )
return - V_20 ;
F_53 ( & V_31 -> V_35 ) ;
F_9 ( & V_127 ) ;
V_64 = F_48 ( V_31 ) ;
F_10 ( & V_127 ) ;
return V_64 ;
}
int F_54 ( struct V_4 * V_31 )
{
F_13 ( L_18 , V_31 -> V_118 ) ;
F_9 ( & V_127 ) ;
F_50 ( V_31 ) ;
F_10 ( & V_127 ) ;
return 0 ;
}
static int T_5 F_55 ( void )
{
return 0 ;
}
static void T_6 F_56 ( void )
{
}
