static int F_1 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_4 * V_5 ;
struct V_6 * V_7 ;
struct V_8 * V_9 ;
enum V_10 V_11 ;
int V_12 = F_2 ( V_1 ) ;
int V_13 ;
if ( V_3 -> V_14 & V_15 )
V_11 = V_16 ;
else if ( V_3 -> V_14 & V_17 )
V_11 = V_18 ;
else {
F_3 ( L_1 ) ;
return - V_19 ;
}
if ( V_12 == V_20 )
V_5 = F_4 ( F_5 ( V_1 ) ,
V_21 ) ;
else
return - V_22 ;
if ( V_5 == NULL ) {
F_3 ( L_2 ) ;
return - V_23 ;
}
if ( V_11 != V_5 -> V_24 ) {
F_3 ( L_3 ) ;
return - V_19 ;
}
V_7 = F_6 ( sizeof( * V_7 ) , V_25 ) ;
if ( ! V_7 )
return - V_26 ;
V_7 -> V_27 . V_28 = V_5 -> V_28 ;
V_7 -> V_27 . V_24 = V_11 ;
V_7 -> V_27 . V_29 = V_5 -> V_29 ;
V_7 -> V_27 . V_30 = V_5 ;
V_9 = F_6 ( sizeof( * V_9 ) , V_25 ) ;
if ( ! V_9 ) {
F_7 ( V_7 ) ;
return - V_26 ;
}
V_9 -> V_31 = V_32 ;
F_8 ( & V_9 -> V_33 ) ;
V_7 -> V_27 . V_9 = V_9 ;
V_3 -> V_29 = ( void * ) V_7 ;
F_9 ( & V_5 -> V_34 ) ;
V_13 = V_5 -> V_28 -> V_35 ( & V_7 -> V_27 ) ;
F_10 ( & V_5 -> V_34 ) ;
if ( V_13 ) {
F_7 ( V_9 ) ;
F_7 ( V_7 ) ;
}
return V_13 ;
}
static int F_11 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_29 ;
V_7 -> V_27 . V_28 -> free ( & V_7 -> V_27 ) ;
F_7 ( V_7 -> V_27 . V_9 -> V_36 ) ;
F_7 ( V_7 -> V_27 . V_9 ) ;
F_7 ( V_7 ) ;
return 0 ;
}
static void F_12 ( struct V_37 * V_27 ,
struct V_38 * V_39 )
{
if ( ! V_27 -> V_28 -> V_40 )
return;
V_27 -> V_28 -> V_40 ( V_27 , V_39 ) ;
F_13 ( L_4 ,
V_39 -> V_41 , V_39 -> V_42 ) ;
V_27 -> V_9 -> V_43 = V_39 -> V_41 ;
V_27 -> V_9 -> V_44 = V_39 -> V_42 ;
}
static T_1 F_14 ( struct V_37 * V_27 ,
struct V_45 * V_46 )
{
long V_47 ;
F_12 ( V_27 , & V_46 -> V_39 ) ;
if ( V_27 -> V_9 -> V_48 == 0 &&
V_27 -> V_9 -> V_31 == V_49 ) {
F_13 ( L_5 ) ;
return V_27 -> V_9 -> V_50 ;
}
F_13 ( L_6 ,
V_27 -> V_9 -> V_48 ,
V_27 -> V_9 -> V_44 ) ;
if ( V_27 -> V_9 -> V_48 ==
V_27 -> V_9 -> V_44 ) {
F_13 ( L_7 ) ;
return V_27 -> V_9 -> V_50 ;
}
V_47 = V_27 -> V_9 -> V_50 -
( V_27 -> V_9 -> V_51 - V_27 -> V_9 -> V_43 ) ;
F_13 ( L_8 , V_47 ,
V_27 -> V_9 -> V_51 ,
V_27 -> V_9 -> V_43 ) ;
if ( V_47 >= V_27 -> V_9 -> V_50 )
V_47 -= V_27 -> V_9 -> V_50 ;
F_13 ( L_9 , V_47 ) ;
V_46 -> V_46 = V_47 ;
return V_47 ;
}
static inline T_1 F_15 ( struct V_37 * V_27 )
{
struct V_45 V_46 ;
return F_14 ( V_27 , & V_46 ) ;
}
static int
F_16 ( struct V_37 * V_27 , unsigned long V_52 )
{
struct V_45 V_53 ;
T_1 V_46 ;
V_46 = F_14 ( V_27 , & V_53 ) ;
V_53 . V_46 = V_46 ;
if ( F_17 ( ( V_54 V_55 * ) V_52 ,
& V_53 , sizeof( V_53 ) ) )
return - V_56 ;
return 0 ;
}
static int F_18 ( struct V_37 * V_27 ,
const char V_55 * V_57 , T_1 V_58 )
{
void * V_59 ;
T_1 V_60 ;
struct V_8 * V_9 = V_27 -> V_9 ;
V_59 = V_9 -> V_36 + V_9 -> V_51 ;
F_13 ( L_10 ,
( unsigned long ) V_58 , V_9 -> V_51 ) ;
if ( V_58 < V_9 -> V_50 - V_9 -> V_51 ) {
if ( F_19 ( V_59 , V_57 , V_58 ) )
return - V_56 ;
V_9 -> V_51 += V_58 ;
} else {
V_60 = V_9 -> V_50 - V_9 -> V_51 ;
if ( F_19 ( V_59 , V_57 , V_60 ) )
return - V_56 ;
if ( F_19 ( V_9 -> V_36 , V_57 + V_60 , V_58 - V_60 ) )
return - V_56 ;
V_9 -> V_51 = V_58 - V_60 ;
}
if ( V_27 -> V_28 -> V_61 )
V_27 -> V_28 -> V_61 ( V_27 , V_58 ) ;
return V_58 ;
}
static T_2 F_20 ( struct V_2 * V_3 , const char V_55 * V_57 ,
T_1 V_58 , T_3 * V_62 )
{
struct V_6 * V_7 = V_3 -> V_29 ;
struct V_37 * V_27 ;
T_1 V_46 ;
int V_63 ;
if ( F_21 ( ! V_7 ) )
return - V_56 ;
V_27 = & V_7 -> V_27 ;
F_9 ( & V_27 -> V_30 -> V_34 ) ;
if ( V_27 -> V_9 -> V_31 != V_49 &&
V_27 -> V_9 -> V_31 != V_64 ) {
F_10 ( & V_27 -> V_30 -> V_34 ) ;
return - V_22 ;
}
V_46 = F_15 ( V_27 ) ;
F_13 ( L_11 , ( unsigned long ) V_46 ) ;
if ( V_46 > V_58 )
V_46 = V_58 ;
if ( V_27 -> V_28 -> V_60 )
V_63 = V_27 -> V_28 -> V_60 ( V_27 , V_57 , V_46 ) ;
else
V_63 = F_18 ( V_27 , V_57 , V_46 ) ;
if ( V_63 > 0 )
V_27 -> V_9 -> V_48 += V_63 ;
if ( V_27 -> V_9 -> V_31 == V_49 ) {
V_27 -> V_9 -> V_31 = V_65 ;
F_13 ( L_12 ) ;
}
F_10 ( & V_27 -> V_30 -> V_34 ) ;
return V_63 ;
}
static T_2 F_22 ( struct V_2 * V_3 , char V_55 * V_57 ,
T_1 V_58 , T_3 * V_62 )
{
return - V_66 ;
}
static int F_23 ( struct V_2 * V_3 , struct V_67 * V_68 )
{
return - V_66 ;
}
static inline int F_24 ( struct V_37 * V_27 )
{
if ( V_27 -> V_24 == V_16 )
return V_69 | V_70 ;
else
return V_71 | V_72 ;
}
static unsigned int F_25 ( struct V_2 * V_3 , T_4 * V_73 )
{
struct V_6 * V_7 = V_3 -> V_29 ;
struct V_37 * V_27 ;
T_1 V_46 ;
int V_63 = 0 ;
if ( F_21 ( ! V_7 ) )
return - V_56 ;
V_27 = & V_7 -> V_27 ;
if ( F_21 ( ! V_27 ) )
return - V_56 ;
F_9 ( & V_27 -> V_30 -> V_34 ) ;
if ( V_27 -> V_9 -> V_31 == V_74 ||
V_27 -> V_9 -> V_31 == V_32 ) {
V_63 = - V_22 ;
goto V_75;
}
F_26 ( V_3 , & V_27 -> V_9 -> V_33 , V_73 ) ;
V_46 = F_15 ( V_27 ) ;
F_13 ( L_13 , ( unsigned long ) V_46 ) ;
switch ( V_27 -> V_9 -> V_31 ) {
case V_76 :
V_63 = F_24 ( V_27 ) ;
V_27 -> V_9 -> V_31 = V_49 ;
break;
case V_64 :
case V_65 :
case V_74 :
if ( V_46 >= V_27 -> V_9 -> V_77 )
V_63 = F_24 ( V_27 ) ;
break;
default:
if ( V_27 -> V_24 == V_16 )
V_63 = V_69 | V_70 | V_78 ;
else
V_63 = V_71 | V_72 | V_78 ;
break;
}
V_75:
F_10 ( & V_27 -> V_30 -> V_34 ) ;
return V_63 ;
}
static int
F_27 ( struct V_37 * V_27 , unsigned long V_52 )
{
int V_63 ;
struct V_79 V_80 ;
if ( ! V_27 -> V_28 -> V_81 )
return - V_66 ;
V_63 = V_27 -> V_28 -> V_81 ( V_27 , & V_80 ) ;
if ( V_63 )
goto V_75;
if ( F_17 ( ( void V_55 * ) V_52 , & V_80 , sizeof( V_80 ) ) )
V_63 = - V_56 ;
V_75:
return V_63 ;
}
static int
F_28 ( struct V_37 * V_27 , unsigned long V_52 )
{
int V_63 ;
struct V_82 * V_80 ;
if ( ! V_27 -> V_28 -> V_83 )
return - V_66 ;
V_80 = F_29 ( sizeof( * V_80 ) , V_25 ) ;
if ( ! V_80 )
return - V_26 ;
V_63 = V_27 -> V_28 -> V_83 ( V_27 , V_80 ) ;
if ( V_63 )
goto V_75;
if ( F_17 ( ( void V_55 * ) V_52 , V_80 , sizeof( * V_80 ) ) )
V_63 = - V_56 ;
V_75:
F_7 ( V_80 ) ;
return V_63 ;
}
static int F_30 ( struct V_37 * V_27 ,
struct V_84 * V_85 )
{
unsigned int V_50 ;
void * V_36 ;
V_50 = V_85 -> V_36 . V_77 * V_85 -> V_36 . V_86 ;
if ( V_27 -> V_28 -> V_60 ) {
V_36 = NULL ;
} else {
V_36 = F_29 ( V_50 , V_25 ) ;
if ( ! V_36 )
return - V_26 ;
}
V_27 -> V_9 -> V_77 = V_85 -> V_36 . V_77 ;
V_27 -> V_9 -> V_86 = V_85 -> V_36 . V_86 ;
V_27 -> V_9 -> V_36 = V_36 ;
V_27 -> V_9 -> V_50 = V_50 ;
return 0 ;
}
static int
F_31 ( struct V_37 * V_27 , unsigned long V_52 )
{
struct V_84 * V_85 ;
int V_63 ;
if ( V_27 -> V_9 -> V_31 == V_32 ) {
V_85 = F_29 ( sizeof( * V_85 ) , V_25 ) ;
if ( ! V_85 )
return - V_26 ;
if ( F_19 ( V_85 , ( void V_55 * ) V_52 , sizeof( * V_85 ) ) ) {
V_63 = - V_56 ;
goto V_75;
}
V_63 = F_30 ( V_27 , V_85 ) ;
if ( V_63 ) {
V_63 = - V_26 ;
goto V_75;
}
V_63 = V_27 -> V_28 -> V_87 ( V_27 , V_85 ) ;
if ( V_63 )
goto V_75;
V_27 -> V_9 -> V_31 = V_49 ;
} else {
return - V_88 ;
}
V_75:
F_7 ( V_85 ) ;
return V_63 ;
}
static int
F_32 ( struct V_37 * V_27 , unsigned long V_52 )
{
struct V_89 * V_85 ;
int V_63 ;
if ( ! V_27 -> V_28 -> V_90 )
return - V_22 ;
V_85 = F_29 ( sizeof( * V_85 ) , V_25 ) ;
if ( ! V_85 )
return - V_26 ;
V_63 = V_27 -> V_28 -> V_90 ( V_27 , V_85 ) ;
if ( V_63 )
goto V_75;
if ( F_17 ( ( char V_55 * ) V_52 , V_85 , sizeof( * V_85 ) ) )
V_63 = - V_56 ;
V_75:
F_7 ( V_85 ) ;
return V_63 ;
}
static inline int
V_38 ( struct V_37 * V_27 , unsigned long V_52 )
{
struct V_38 V_39 ;
F_12 ( V_27 , & V_39 ) ;
return F_17 ( (struct V_38 V_55 * ) V_52 ,
& V_39 , sizeof( V_39 ) ) ? - V_56 : 0 ;
}
static int F_33 ( struct V_37 * V_27 )
{
int V_63 ;
if ( V_27 -> V_9 -> V_31 != V_64 )
return - V_88 ;
V_63 = V_27 -> V_28 -> V_91 ( V_27 , V_92 ) ;
if ( ! V_63 ) {
V_27 -> V_9 -> V_31 = V_74 ;
F_34 ( & V_27 -> V_9 -> V_33 ) ;
}
return V_63 ;
}
static int F_35 ( struct V_37 * V_27 )
{
int V_63 ;
if ( V_27 -> V_9 -> V_31 != V_74 )
return - V_88 ;
V_63 = V_27 -> V_28 -> V_91 ( V_27 , V_93 ) ;
if ( ! V_63 )
V_27 -> V_9 -> V_31 = V_64 ;
return V_63 ;
}
static int F_36 ( struct V_37 * V_27 )
{
int V_63 ;
if ( V_27 -> V_9 -> V_31 != V_65 )
return - V_88 ;
V_63 = V_27 -> V_28 -> V_91 ( V_27 , V_94 ) ;
if ( ! V_63 )
V_27 -> V_9 -> V_31 = V_64 ;
return V_63 ;
}
static int F_37 ( struct V_37 * V_27 )
{
int V_63 ;
if ( V_27 -> V_9 -> V_31 == V_65 ||
V_27 -> V_9 -> V_31 == V_49 )
return - V_88 ;
V_63 = V_27 -> V_28 -> V_91 ( V_27 , V_95 ) ;
if ( ! V_63 ) {
V_27 -> V_9 -> V_31 = V_49 ;
F_34 ( & V_27 -> V_9 -> V_33 ) ;
}
return V_63 ;
}
static int F_38 ( struct V_37 * V_27 )
{
int V_63 ;
if ( V_27 -> V_9 -> V_31 == V_65 ||
V_27 -> V_9 -> V_31 == V_49 )
return - V_88 ;
V_63 = V_27 -> V_28 -> V_91 ( V_27 , V_96 ) ;
if ( ! V_63 ) {
V_27 -> V_9 -> V_31 = V_76 ;
F_34 ( & V_27 -> V_9 -> V_33 ) ;
}
return V_63 ;
}
static long F_39 ( struct V_2 * V_3 , unsigned int V_97 , unsigned long V_52 )
{
struct V_6 * V_7 = V_3 -> V_29 ;
struct V_37 * V_27 ;
int V_63 = - V_98 ;
if ( F_21 ( ! V_7 ) )
return - V_56 ;
V_27 = & V_7 -> V_27 ;
if ( F_21 ( ! V_27 ) )
return - V_56 ;
F_9 ( & V_27 -> V_30 -> V_34 ) ;
switch ( F_40 ( V_97 ) ) {
case F_40 ( V_99 ) :
F_41 ( V_100 ,
( int V_55 * ) V_52 ) ? - V_56 : 0 ;
break;
case F_40 ( V_101 ) :
V_63 = F_27 ( V_27 , V_52 ) ;
break;
case F_40 ( V_102 ) :
V_63 = F_28 ( V_27 , V_52 ) ;
break;
case F_40 ( V_103 ) :
V_63 = F_31 ( V_27 , V_52 ) ;
break;
case F_40 ( V_104 ) :
V_63 = F_32 ( V_27 , V_52 ) ;
break;
case F_40 ( V_105 ) :
V_63 = V_38 ( V_27 , V_52 ) ;
break;
case F_40 ( V_106 ) :
V_63 = F_16 ( V_27 , V_52 ) ;
break;
case F_40 ( V_107 ) :
V_63 = F_33 ( V_27 ) ;
break;
case F_40 ( V_108 ) :
V_63 = F_35 ( V_27 ) ;
break;
case F_40 ( V_109 ) :
V_63 = F_36 ( V_27 ) ;
break;
case F_40 ( V_110 ) :
V_63 = F_37 ( V_27 ) ;
break;
case F_40 ( V_111 ) :
V_63 = F_38 ( V_27 ) ;
break;
}
F_10 ( & V_27 -> V_30 -> V_34 ) ;
return V_63 ;
}
static int F_42 ( struct V_112 * V_30 )
{
int V_13 = - V_19 ;
char V_113 [ 16 ] ;
struct V_4 * V_5 ;
if ( F_21 ( ! V_30 || ! V_30 -> V_114 ) )
return - V_22 ;
V_5 = V_30 -> V_114 ;
sprintf ( V_113 , L_14 , V_5 -> V_115 -> V_116 , V_5 -> V_30 ) ;
F_13 ( L_15 , V_113 , V_5 -> V_117 ,
V_5 -> V_24 ) ;
V_13 = F_43 ( V_21 , V_5 -> V_115 ,
V_5 -> V_30 , & V_118 , V_5 , V_113 ) ;
if ( V_13 < 0 ) {
F_3 ( L_16 , V_13 ) ;
return V_13 ;
}
return V_13 ;
}
static int F_44 ( struct V_112 * V_30 )
{
struct V_4 * V_5 ;
V_5 = V_30 -> V_114 ;
F_45 ( V_5 -> V_24 , V_5 -> V_115 , V_5 -> V_30 ) ;
return 0 ;
}
int F_46 ( struct V_119 * V_115 , int V_30 ,
int V_11 , struct V_4 * V_5 )
{
static struct V_120 V_28 = {
. V_121 = NULL ,
. V_122 = F_42 ,
. V_123 = F_44 ,
} ;
V_5 -> V_115 = V_115 ;
V_5 -> V_30 = V_30 ;
V_5 -> V_24 = V_11 ;
return F_47 ( V_115 , V_124 , V_5 , & V_28 ) ;
}
static int F_48 ( struct V_4 * V_30 )
{
int V_13 ;
if ( ! V_30 -> V_115 )
return - V_19 ;
V_13 = F_49 ( V_30 -> V_115 ) ;
if ( V_13 )
goto V_75;
return 0 ;
V_75:
F_3 ( L_17 , V_13 ) ;
return V_13 ;
}
static int F_50 ( struct V_4 * V_30 )
{
return F_51 ( V_30 -> V_115 ) ;
}
int F_52 ( struct V_4 * V_30 )
{
int V_63 ;
if ( V_30 -> V_117 == NULL || V_30 -> V_125 == NULL || V_30 -> V_28 == NULL )
return - V_19 ;
F_13 ( L_18 , V_30 -> V_117 ) ;
if ( F_21 ( ! V_30 -> V_28 -> V_35 ) )
return - V_19 ;
if ( F_21 ( ! V_30 -> V_28 -> free ) )
return - V_19 ;
if ( F_21 ( ! V_30 -> V_28 -> V_87 ) )
return - V_19 ;
if ( F_21 ( ! V_30 -> V_28 -> V_91 ) )
return - V_19 ;
F_53 ( & V_30 -> V_34 ) ;
F_9 ( & V_126 ) ;
V_63 = F_48 ( V_30 ) ;
F_10 ( & V_126 ) ;
return V_63 ;
}
int F_54 ( struct V_4 * V_30 )
{
F_13 ( L_19 , V_30 -> V_117 ) ;
F_9 ( & V_126 ) ;
F_50 ( V_30 ) ;
F_10 ( & V_126 ) ;
return 0 ;
}
static int T_5 F_55 ( void )
{
return 0 ;
}
static void T_6 F_56 ( void )
{
}
