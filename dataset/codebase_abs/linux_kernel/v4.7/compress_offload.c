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
return V_13 ;
}
static int F_12 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
struct V_8 * V_9 = V_7 -> V_29 . V_9 ;
switch ( V_9 -> V_33 ) {
case V_38 :
case V_39 :
case V_40 :
V_7 -> V_29 . V_30 -> V_41 ( & V_7 -> V_29 , V_42 ) ;
break;
default:
break;
}
V_7 -> V_29 . V_30 -> free ( & V_7 -> V_29 ) ;
F_8 ( V_7 -> V_29 . V_9 -> V_43 ) ;
F_8 ( V_7 -> V_29 . V_9 ) ;
F_8 ( V_7 ) ;
return 0 ;
}
static int F_13 ( struct V_44 * V_29 ,
struct V_45 * V_46 )
{
if ( ! V_29 -> V_30 -> V_47 )
return - V_48 ;
V_29 -> V_30 -> V_47 ( V_29 , V_46 ) ;
F_14 ( L_3 ,
V_46 -> V_49 , V_46 -> V_50 ) ;
if ( V_29 -> V_25 == V_17 )
V_29 -> V_9 -> V_51 = V_46 -> V_50 ;
else
V_29 -> V_9 -> V_52 = V_46 -> V_50 ;
return 0 ;
}
static T_1 F_15 ( struct V_44 * V_29 ,
struct V_53 * V_54 )
{
memset ( V_54 , 0 , sizeof( * V_54 ) ) ;
F_13 ( V_29 , & V_54 -> V_46 ) ;
if ( V_29 -> V_9 -> V_52 == 0 &&
V_29 -> V_9 -> V_33 == V_55 &&
V_29 -> V_25 == V_17 ) {
F_14 ( L_4 ) ;
return V_29 -> V_9 -> V_56 ;
}
F_14 ( L_5 ,
V_29 -> V_9 -> V_52 ,
V_29 -> V_9 -> V_51 ) ;
if ( V_29 -> V_9 -> V_52 ==
V_29 -> V_9 -> V_51 ) {
if ( V_29 -> V_25 == V_17 ) {
F_14 ( L_6 ) ;
return V_29 -> V_9 -> V_56 ;
} else {
F_14 ( L_7 ) ;
return 0 ;
}
}
V_54 -> V_54 = V_29 -> V_9 -> V_52 -
V_29 -> V_9 -> V_51 ;
if ( V_29 -> V_25 == V_17 )
V_54 -> V_54 = V_29 -> V_9 -> V_56 - V_54 -> V_54 ;
F_14 ( L_8 , V_54 -> V_54 ) ;
return V_54 -> V_54 ;
}
static inline T_1 F_16 ( struct V_44 * V_29 )
{
struct V_53 V_54 ;
return F_15 ( V_29 , & V_54 ) ;
}
static int
F_17 ( struct V_44 * V_29 , unsigned long V_57 )
{
struct V_53 V_58 ;
T_1 V_54 ;
V_54 = F_15 ( V_29 , & V_58 ) ;
V_58 . V_54 = V_54 ;
if ( F_18 ( ( V_59 V_60 * ) V_57 ,
& V_58 , sizeof( V_58 ) ) )
return - V_61 ;
return 0 ;
}
static int F_19 ( struct V_44 * V_29 ,
const char V_60 * V_62 , T_1 V_63 )
{
void * V_64 ;
T_1 V_65 ;
struct V_8 * V_9 = V_29 -> V_9 ;
T_2 V_66 = F_20 ( V_9 -> V_52 ,
V_9 -> V_56 ) ;
V_66 = V_9 -> V_52 -
( V_66 * V_9 -> V_56 ) ;
V_64 = V_9 -> V_43 + V_66 ;
F_14 ( L_9 ,
( unsigned long ) V_63 , V_66 ) ;
if ( V_63 < V_9 -> V_56 - V_66 ) {
if ( F_21 ( V_64 , V_62 , V_63 ) )
return - V_61 ;
} else {
V_65 = V_9 -> V_56 - V_66 ;
if ( F_21 ( V_64 , V_62 , V_65 ) )
return - V_61 ;
if ( F_21 ( V_9 -> V_43 , V_62 + V_65 , V_63 - V_65 ) )
return - V_61 ;
}
if ( V_29 -> V_30 -> V_67 )
V_29 -> V_30 -> V_67 ( V_29 , V_63 ) ;
return V_63 ;
}
static T_3 F_22 ( struct V_2 * V_3 , const char V_60 * V_62 ,
T_1 V_63 , T_4 * V_68 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
struct V_44 * V_29 ;
T_1 V_54 ;
int V_69 ;
if ( F_23 ( ! V_7 ) )
return - V_61 ;
V_29 = & V_7 -> V_29 ;
F_10 ( & V_29 -> V_32 -> V_36 ) ;
switch ( V_29 -> V_9 -> V_33 ) {
case V_55 :
case V_70 :
case V_38 :
break;
default:
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return - V_23 ;
}
V_54 = F_16 ( V_29 ) ;
F_14 ( L_10 , ( unsigned long ) V_54 ) ;
if ( V_54 > V_63 )
V_54 = V_63 ;
if ( V_29 -> V_30 -> V_65 ) {
char V_60 * V_71 = ( char V_60 * ) V_62 ;
V_69 = V_29 -> V_30 -> V_65 ( V_29 , V_71 , V_54 ) ;
} else {
V_69 = F_19 ( V_29 , V_62 , V_54 ) ;
}
if ( V_69 > 0 )
V_29 -> V_9 -> V_52 += V_69 ;
if ( V_29 -> V_9 -> V_33 == V_55 ) {
V_29 -> V_9 -> V_33 = V_70 ;
F_14 ( L_11 ) ;
}
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return V_69 ;
}
static T_3 F_24 ( struct V_2 * V_3 , char V_60 * V_62 ,
T_1 V_63 , T_4 * V_68 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
struct V_44 * V_29 ;
T_1 V_54 ;
int V_69 ;
if ( F_23 ( ! V_7 ) )
return - V_61 ;
V_29 = & V_7 -> V_29 ;
F_10 ( & V_29 -> V_32 -> V_36 ) ;
switch ( V_29 -> V_9 -> V_33 ) {
case V_34 :
case V_70 :
case V_72 :
case V_73 :
case V_74 :
V_69 = - V_23 ;
goto V_75;
}
V_54 = F_16 ( V_29 ) ;
F_14 ( L_10 , ( unsigned long ) V_54 ) ;
if ( V_54 > V_63 )
V_54 = V_63 ;
if ( V_29 -> V_30 -> V_65 ) {
V_69 = V_29 -> V_30 -> V_65 ( V_29 , V_62 , V_54 ) ;
} else {
V_69 = - V_76 ;
goto V_75;
}
if ( V_69 > 0 )
V_29 -> V_9 -> V_51 += V_69 ;
V_75:
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return V_69 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_77 * V_78 )
{
return - V_76 ;
}
static inline int F_26 ( struct V_44 * V_29 )
{
if ( V_29 -> V_25 == V_17 )
return V_79 | V_80 ;
else
return V_81 | V_82 ;
}
static unsigned int F_27 ( struct V_2 * V_3 , T_5 * V_83 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
struct V_44 * V_29 ;
T_1 V_54 ;
int V_69 = 0 ;
if ( F_23 ( ! V_7 ) )
return V_84 ;
V_29 = & V_7 -> V_29 ;
F_10 ( & V_29 -> V_32 -> V_36 ) ;
if ( V_29 -> V_9 -> V_33 == V_34 ) {
V_69 = F_26 ( V_29 ) | V_84 ;
goto V_75;
}
F_28 ( V_3 , & V_29 -> V_9 -> V_35 , V_83 ) ;
V_54 = F_16 ( V_29 ) ;
F_14 ( L_12 , ( unsigned long ) V_54 ) ;
switch ( V_29 -> V_9 -> V_33 ) {
case V_39 :
V_69 = F_26 ( V_29 ) ;
V_29 -> V_9 -> V_33 = V_55 ;
break;
case V_38 :
case V_70 :
case V_40 :
if ( V_54 >= V_29 -> V_9 -> V_85 )
V_69 = F_26 ( V_29 ) ;
break;
default:
V_69 = F_26 ( V_29 ) | V_84 ;
break;
}
V_75:
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return V_69 ;
}
static int
F_29 ( struct V_44 * V_29 , unsigned long V_57 )
{
int V_69 ;
struct V_86 V_87 ;
if ( ! V_29 -> V_30 -> V_88 )
return - V_76 ;
memset ( & V_87 , 0 , sizeof( V_87 ) ) ;
V_69 = V_29 -> V_30 -> V_88 ( V_29 , & V_87 ) ;
if ( V_69 )
goto V_75;
if ( F_18 ( ( void V_60 * ) V_57 , & V_87 , sizeof( V_87 ) ) )
V_69 = - V_61 ;
V_75:
return V_69 ;
}
static int
F_30 ( struct V_44 * V_29 , unsigned long V_57 )
{
int V_69 ;
struct V_89 * V_87 ;
if ( ! V_29 -> V_30 -> V_90 )
return - V_76 ;
V_87 = F_7 ( sizeof( * V_87 ) , V_27 ) ;
if ( ! V_87 )
return - V_28 ;
V_69 = V_29 -> V_30 -> V_90 ( V_29 , V_87 ) ;
if ( V_69 )
goto V_75;
if ( F_18 ( ( void V_60 * ) V_57 , V_87 , sizeof( * V_87 ) ) )
V_69 = - V_61 ;
V_75:
F_8 ( V_87 ) ;
return V_69 ;
}
static int F_31 ( struct V_44 * V_29 ,
struct V_91 * V_92 )
{
unsigned int V_56 ;
void * V_43 ;
V_56 = V_92 -> V_43 . V_85 * V_92 -> V_43 . V_93 ;
if ( V_29 -> V_30 -> V_65 ) {
V_43 = NULL ;
} else {
V_43 = F_32 ( V_56 , V_27 ) ;
if ( ! V_43 )
return - V_28 ;
}
V_29 -> V_9 -> V_85 = V_92 -> V_43 . V_85 ;
V_29 -> V_9 -> V_93 = V_92 -> V_43 . V_93 ;
V_29 -> V_9 -> V_43 = V_43 ;
V_29 -> V_9 -> V_56 = V_56 ;
return 0 ;
}
static int F_33 ( struct V_91 * V_92 )
{
if ( V_92 -> V_43 . V_85 == 0 ||
V_92 -> V_43 . V_93 > V_94 / V_92 -> V_43 . V_85 )
return - V_20 ;
if ( V_92 -> V_95 . V_96 == 0 || V_92 -> V_95 . V_96 > V_97 )
return - V_20 ;
if ( V_92 -> V_95 . V_98 == 0 || V_92 -> V_95 . V_99 == 0 )
return - V_20 ;
return 0 ;
}
static int
F_34 ( struct V_44 * V_29 , unsigned long V_57 )
{
struct V_91 * V_92 ;
int V_69 ;
if ( V_29 -> V_9 -> V_33 == V_34 ) {
V_92 = F_32 ( sizeof( * V_92 ) , V_27 ) ;
if ( ! V_92 )
return - V_28 ;
if ( F_21 ( V_92 , ( void V_60 * ) V_57 , sizeof( * V_92 ) ) ) {
V_69 = - V_61 ;
goto V_75;
}
V_69 = F_33 ( V_92 ) ;
if ( V_69 )
goto V_75;
V_69 = F_31 ( V_29 , V_92 ) ;
if ( V_69 ) {
V_69 = - V_28 ;
goto V_75;
}
V_69 = V_29 -> V_30 -> V_100 ( V_29 , V_92 ) ;
if ( V_69 )
goto V_75;
V_29 -> V_101 = false ;
V_29 -> V_102 = false ;
if ( V_29 -> V_25 == V_17 )
V_29 -> V_9 -> V_33 = V_55 ;
else
V_29 -> V_9 -> V_33 = V_70 ;
} else {
return - V_103 ;
}
V_75:
F_8 ( V_92 ) ;
return V_69 ;
}
static int
F_35 ( struct V_44 * V_29 , unsigned long V_57 )
{
struct V_104 * V_92 ;
int V_69 ;
if ( ! V_29 -> V_30 -> V_105 )
return - V_23 ;
V_92 = F_7 ( sizeof( * V_92 ) , V_27 ) ;
if ( ! V_92 )
return - V_28 ;
V_69 = V_29 -> V_30 -> V_105 ( V_29 , V_92 ) ;
if ( V_69 )
goto V_75;
if ( F_18 ( ( char V_60 * ) V_57 , V_92 , sizeof( * V_92 ) ) )
V_69 = - V_61 ;
V_75:
F_8 ( V_92 ) ;
return V_69 ;
}
static int
F_36 ( struct V_44 * V_29 , unsigned long V_57 )
{
struct V_106 V_107 ;
int V_69 ;
if ( ! V_29 -> V_30 -> V_108 )
return - V_76 ;
if ( F_21 ( & V_107 , ( void V_60 * ) V_57 , sizeof( V_107 ) ) )
return - V_61 ;
V_69 = V_29 -> V_30 -> V_108 ( V_29 , & V_107 ) ;
if ( V_69 != 0 )
return V_69 ;
if ( F_18 ( ( void V_60 * ) V_57 , & V_107 , sizeof( V_107 ) ) )
return - V_61 ;
return 0 ;
}
static int
F_37 ( struct V_44 * V_29 , unsigned long V_57 )
{
struct V_106 V_107 ;
int V_69 ;
if ( ! V_29 -> V_30 -> V_109 )
return - V_76 ;
if ( F_21 ( & V_107 , ( void V_60 * ) V_57 , sizeof( V_107 ) ) )
return - V_61 ;
V_69 = V_29 -> V_30 -> V_109 ( V_29 , & V_107 ) ;
V_29 -> V_101 = true ;
return V_69 ;
}
static inline int
V_45 ( struct V_44 * V_29 , unsigned long V_57 )
{
struct V_45 V_46 = { 0 } ;
int V_13 ;
V_13 = F_13 ( V_29 , & V_46 ) ;
if ( V_13 == 0 )
V_13 = F_18 ( (struct V_45 V_60 * ) V_57 ,
& V_46 , sizeof( V_46 ) ) ? - V_61 : 0 ;
return V_13 ;
}
static int F_38 ( struct V_44 * V_29 )
{
int V_69 ;
if ( V_29 -> V_9 -> V_33 != V_38 )
return - V_103 ;
V_69 = V_29 -> V_30 -> V_41 ( V_29 , V_110 ) ;
if ( ! V_69 )
V_29 -> V_9 -> V_33 = V_40 ;
return V_69 ;
}
static int F_39 ( struct V_44 * V_29 )
{
int V_69 ;
if ( V_29 -> V_9 -> V_33 != V_40 )
return - V_103 ;
V_69 = V_29 -> V_30 -> V_41 ( V_29 , V_111 ) ;
if ( ! V_69 )
V_29 -> V_9 -> V_33 = V_38 ;
return V_69 ;
}
static int F_40 ( struct V_44 * V_29 )
{
int V_69 ;
if ( V_29 -> V_9 -> V_33 != V_70 )
return - V_103 ;
V_69 = V_29 -> V_30 -> V_41 ( V_29 , V_112 ) ;
if ( ! V_69 )
V_29 -> V_9 -> V_33 = V_38 ;
return V_69 ;
}
static int F_41 ( struct V_44 * V_29 )
{
int V_69 ;
if ( V_29 -> V_9 -> V_33 == V_70 ||
V_29 -> V_9 -> V_33 == V_55 )
return - V_103 ;
V_69 = V_29 -> V_30 -> V_41 ( V_29 , V_42 ) ;
if ( ! V_69 ) {
F_42 ( V_29 ) ;
V_29 -> V_9 -> V_52 = 0 ;
V_29 -> V_9 -> V_51 = 0 ;
}
return V_69 ;
}
static int F_43 ( struct V_44 * V_29 )
{
int V_13 ;
V_29 -> V_9 -> V_33 = V_39 ;
F_11 ( & V_29 -> V_32 -> V_36 ) ;
V_13 = F_44 ( V_29 -> V_9 -> V_35 ,
( V_29 -> V_9 -> V_33 != V_39 ) ) ;
if ( V_13 == - V_113 )
F_14 ( L_13 ) ;
else if ( V_13 )
F_14 ( L_14 , V_13 ) ;
F_45 ( & V_29 -> V_9 -> V_35 ) ;
F_10 ( & V_29 -> V_32 -> V_36 ) ;
return V_13 ;
}
static int F_46 ( struct V_44 * V_29 )
{
int V_69 ;
if ( V_29 -> V_9 -> V_33 == V_70 ||
V_29 -> V_9 -> V_33 == V_55 )
return - V_103 ;
V_69 = V_29 -> V_30 -> V_41 ( V_29 , V_114 ) ;
if ( V_69 ) {
F_14 ( L_15 , V_69 ) ;
F_45 ( & V_29 -> V_9 -> V_35 ) ;
return V_69 ;
}
return F_43 ( V_29 ) ;
}
static int F_47 ( struct V_44 * V_29 )
{
int V_69 ;
if ( V_29 -> V_9 -> V_33 != V_38 )
return - V_103 ;
if ( V_29 -> V_101 == false )
return - V_103 ;
V_69 = V_29 -> V_30 -> V_41 ( V_29 , V_115 ) ;
if ( V_69 != 0 )
return V_69 ;
V_29 -> V_101 = false ;
V_29 -> V_102 = true ;
return 0 ;
}
static int F_48 ( struct V_44 * V_29 )
{
int V_69 ;
if ( V_29 -> V_9 -> V_33 == V_70 ||
V_29 -> V_9 -> V_33 == V_55 )
return - V_103 ;
if ( V_29 -> V_102 == false )
return - V_103 ;
V_69 = V_29 -> V_30 -> V_41 ( V_29 , V_116 ) ;
if ( V_69 ) {
F_14 ( L_16 ) ;
F_45 ( & V_29 -> V_9 -> V_35 ) ;
return V_69 ;
}
V_29 -> V_102 = false ;
return F_43 ( V_29 ) ;
}
static long F_49 ( struct V_2 * V_3 , unsigned int V_117 , unsigned long V_57 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
struct V_44 * V_29 ;
int V_69 = - V_118 ;
if ( F_23 ( ! V_7 ) )
return - V_61 ;
V_29 = & V_7 -> V_29 ;
F_10 ( & V_29 -> V_32 -> V_36 ) ;
switch ( F_50 ( V_117 ) ) {
case F_50 ( V_119 ) :
V_69 = F_51 ( V_120 ,
( int V_60 * ) V_57 ) ? - V_61 : 0 ;
break;
case F_50 ( V_121 ) :
V_69 = F_29 ( V_29 , V_57 ) ;
break;
#ifndef F_52
case F_50 ( V_122 ) :
V_69 = F_30 ( V_29 , V_57 ) ;
break;
#endif
case F_50 ( V_123 ) :
V_69 = F_34 ( V_29 , V_57 ) ;
break;
case F_50 ( V_124 ) :
V_69 = F_35 ( V_29 , V_57 ) ;
break;
case F_50 ( V_125 ) :
V_69 = F_37 ( V_29 , V_57 ) ;
break;
case F_50 ( V_126 ) :
V_69 = F_36 ( V_29 , V_57 ) ;
break;
case F_50 ( V_127 ) :
V_69 = V_45 ( V_29 , V_57 ) ;
break;
case F_50 ( V_128 ) :
V_69 = F_17 ( V_29 , V_57 ) ;
break;
case F_50 ( V_129 ) :
V_69 = F_38 ( V_29 ) ;
break;
case F_50 ( V_130 ) :
V_69 = F_39 ( V_29 ) ;
break;
case F_50 ( V_131 ) :
V_69 = F_40 ( V_29 ) ;
break;
case F_50 ( V_132 ) :
V_69 = F_41 ( V_29 ) ;
break;
case F_50 ( V_133 ) :
V_69 = F_46 ( V_29 ) ;
break;
case F_50 ( V_134 ) :
V_69 = F_48 ( V_29 ) ;
break;
case F_50 ( V_135 ) :
V_69 = F_47 ( V_29 ) ;
break;
}
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return V_69 ;
}
static long F_53 ( struct V_2 * V_2 , unsigned int V_117 ,
unsigned long V_57 )
{
return F_49 ( V_2 , V_117 , ( unsigned long ) F_54 ( V_57 ) ) ;
}
static int F_55 ( struct V_136 * V_32 )
{
int V_13 = - V_20 ;
char V_137 [ 16 ] ;
struct V_4 * V_5 ;
if ( F_23 ( ! V_32 || ! V_32 -> V_138 ) )
return - V_23 ;
V_5 = V_32 -> V_138 ;
F_14 ( L_17 , V_137 , V_5 -> V_139 ,
V_5 -> V_25 ) ;
V_13 = F_56 ( V_22 ,
V_5 -> V_26 , V_5 -> V_32 ,
& V_140 , V_5 , & V_5 -> V_141 ) ;
if ( V_13 < 0 ) {
F_5 ( L_18 , V_13 ) ;
return V_13 ;
}
return V_13 ;
}
static int F_57 ( struct V_136 * V_32 )
{
struct V_4 * V_5 ;
V_5 = V_32 -> V_138 ;
F_58 ( & V_5 -> V_141 ) ;
return 0 ;
}
static void F_59 ( struct V_142 * V_143 ,
struct V_144 * V_43 )
{
struct V_4 * V_5 = (struct V_4 * ) V_143 -> V_31 ;
F_60 ( V_43 , L_19 , V_5 -> V_26 -> V_145 ) ;
F_60 ( V_43 , L_20 , V_5 -> V_32 ) ;
F_60 ( V_43 , L_21 ,
V_5 -> V_25 == V_17
? L_22 : L_23 ) ;
F_60 ( V_43 , L_24 , V_5 -> V_96 ) ;
}
static int F_61 ( struct V_4 * V_5 )
{
struct V_142 * V_143 ;
char V_139 [ 16 ] ;
sprintf ( V_139 , L_25 , V_5 -> V_32 ) ;
V_143 = F_62 ( V_5 -> V_26 , V_139 ,
V_5 -> V_26 -> V_146 ) ;
if ( ! V_143 )
return - V_28 ;
V_143 -> V_147 = V_148 | V_149 | V_150 ;
if ( F_63 ( V_143 ) < 0 ) {
F_64 ( V_143 ) ;
return - V_28 ;
}
V_5 -> V_146 = V_143 ;
V_143 = F_62 ( V_5 -> V_26 , L_26 ,
V_5 -> V_146 ) ;
if ( V_143 ) {
F_65 ( V_143 , V_5 ,
F_59 ) ;
if ( F_63 ( V_143 ) < 0 ) {
F_64 ( V_143 ) ;
V_143 = NULL ;
}
}
V_5 -> V_151 = V_143 ;
return 0 ;
}
static void F_66 ( struct V_4 * V_5 )
{
F_64 ( V_5 -> V_151 ) ;
V_5 -> V_151 = NULL ;
F_64 ( V_5 -> V_146 ) ;
V_5 -> V_146 = NULL ;
}
static inline void F_67 ( struct V_4 * V_5 , const char * V_96 )
{
F_68 ( V_5 -> V_96 , V_96 , sizeof( V_5 -> V_96 ) ) ;
}
static inline int F_61 ( struct V_4 * V_5 )
{
return 0 ;
}
static inline void F_66 ( struct V_4 * V_5 )
{
}
static inline void F_67 ( struct V_4 * V_5 , const char * V_96 )
{
}
static int F_69 ( struct V_136 * V_32 )
{
struct V_4 * V_5 ;
V_5 = V_32 -> V_138 ;
F_66 ( V_5 ) ;
F_70 ( & V_5 -> V_141 ) ;
return 0 ;
}
int F_71 ( struct V_152 * V_26 , int V_32 ,
int V_11 , const char * V_96 , struct V_4 * V_5 )
{
static struct V_153 V_30 = {
. V_154 = F_69 ,
. V_155 = F_55 ,
. V_156 = F_57 ,
} ;
int V_13 ;
V_5 -> V_26 = V_26 ;
V_5 -> V_32 = V_32 ;
V_5 -> V_25 = V_11 ;
F_67 ( V_5 , V_96 ) ;
F_72 ( & V_5 -> V_141 , V_26 ) ;
F_73 ( & V_5 -> V_141 , L_27 , V_26 -> V_145 , V_32 ) ;
V_13 = F_74 ( V_26 , V_157 , V_5 , & V_30 ) ;
if ( V_13 == 0 )
F_61 ( V_5 ) ;
return V_13 ;
}
static int F_75 ( struct V_4 * V_32 )
{
int V_13 ;
if ( ! V_32 -> V_26 )
return - V_20 ;
V_13 = F_76 ( V_32 -> V_26 ) ;
if ( V_13 )
goto V_75;
return 0 ;
V_75:
F_5 ( L_28 , V_13 ) ;
return V_13 ;
}
static int F_77 ( struct V_4 * V_32 )
{
return F_78 ( V_32 -> V_26 ) ;
}
int F_79 ( struct V_4 * V_32 )
{
int V_69 ;
if ( V_32 -> V_139 == NULL || V_32 -> V_30 == NULL )
return - V_20 ;
F_14 ( L_29 , V_32 -> V_139 ) ;
if ( F_23 ( ! V_32 -> V_30 -> V_37 ) )
return - V_20 ;
if ( F_23 ( ! V_32 -> V_30 -> free ) )
return - V_20 ;
if ( F_23 ( ! V_32 -> V_30 -> V_100 ) )
return - V_20 ;
if ( F_23 ( ! V_32 -> V_30 -> V_41 ) )
return - V_20 ;
F_80 ( & V_32 -> V_36 ) ;
F_10 ( & V_158 ) ;
V_69 = F_75 ( V_32 ) ;
F_11 ( & V_158 ) ;
return V_69 ;
}
int F_81 ( struct V_4 * V_32 )
{
F_14 ( L_30 , V_32 -> V_139 ) ;
F_10 ( & V_158 ) ;
F_77 ( V_32 ) ;
F_11 ( & V_158 ) ;
return 0 ;
}
static int T_6 F_82 ( void )
{
return 0 ;
}
static void T_7 F_83 ( void )
{
}
