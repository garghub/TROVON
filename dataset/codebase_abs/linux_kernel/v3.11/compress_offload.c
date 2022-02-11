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
static int F_13 ( struct V_39 * V_29 ,
struct V_40 * V_41 )
{
if ( ! V_29 -> V_30 -> V_42 )
return - V_43 ;
V_29 -> V_30 -> V_42 ( V_29 , V_41 ) ;
F_14 ( L_3 ,
V_41 -> V_44 , V_41 -> V_45 ) ;
if ( V_29 -> V_25 == V_17 )
V_29 -> V_9 -> V_46 = V_41 -> V_45 ;
else
V_29 -> V_9 -> V_47 = V_41 -> V_45 ;
return 0 ;
}
static T_1 F_15 ( struct V_39 * V_29 ,
struct V_48 * V_49 )
{
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
F_13 ( V_29 , & V_49 -> V_41 ) ;
if ( V_29 -> V_9 -> V_47 == 0 &&
V_29 -> V_9 -> V_33 == V_50 &&
V_29 -> V_25 == V_17 ) {
F_14 ( L_4 ) ;
return V_29 -> V_9 -> V_51 ;
}
F_14 ( L_5 ,
V_29 -> V_9 -> V_47 ,
V_29 -> V_9 -> V_46 ) ;
if ( V_29 -> V_9 -> V_47 ==
V_29 -> V_9 -> V_46 ) {
if ( V_29 -> V_25 == V_17 ) {
F_14 ( L_6 ) ;
return V_29 -> V_9 -> V_51 ;
} else {
F_14 ( L_7 ) ;
return 0 ;
}
}
V_49 -> V_49 = V_29 -> V_9 -> V_47 -
V_29 -> V_9 -> V_46 ;
if ( V_29 -> V_25 == V_17 )
V_49 -> V_49 = V_29 -> V_9 -> V_51 - V_49 -> V_49 ;
F_14 ( L_8 , V_49 -> V_49 ) ;
return V_49 -> V_49 ;
}
static inline T_1 F_16 ( struct V_39 * V_29 )
{
struct V_48 V_49 ;
return F_15 ( V_29 , & V_49 ) ;
}
static int
F_17 ( struct V_39 * V_29 , unsigned long V_52 )
{
struct V_48 V_53 ;
T_1 V_49 ;
V_49 = F_15 ( V_29 , & V_53 ) ;
V_53 . V_49 = V_49 ;
if ( F_18 ( ( V_54 V_55 * ) V_52 ,
& V_53 , sizeof( V_53 ) ) )
return - V_56 ;
return 0 ;
}
static int F_19 ( struct V_39 * V_29 ,
const char V_55 * V_57 , T_1 V_58 )
{
void * V_59 ;
T_1 V_60 ;
struct V_8 * V_9 = V_29 -> V_9 ;
T_2 V_61 = F_20 ( V_9 -> V_47 ,
V_9 -> V_51 ) ;
V_61 = V_9 -> V_47 -
( V_61 * V_9 -> V_51 ) ;
V_59 = V_9 -> V_38 + V_61 ;
F_14 ( L_9 ,
( unsigned long ) V_58 , V_61 ) ;
if ( V_58 < V_9 -> V_51 - V_61 ) {
if ( F_21 ( V_59 , V_57 , V_58 ) )
return - V_56 ;
} else {
V_60 = V_9 -> V_51 - V_61 ;
if ( F_21 ( V_59 , V_57 , V_60 ) )
return - V_56 ;
if ( F_21 ( V_9 -> V_38 , V_57 + V_60 , V_58 - V_60 ) )
return - V_56 ;
}
if ( V_29 -> V_30 -> V_62 )
V_29 -> V_30 -> V_62 ( V_29 , V_58 ) ;
return V_58 ;
}
static T_3 F_22 ( struct V_2 * V_3 , const char V_55 * V_57 ,
T_1 V_58 , T_4 * V_63 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
struct V_39 * V_29 ;
T_1 V_49 ;
int V_64 ;
if ( F_23 ( ! V_7 ) )
return - V_56 ;
V_29 = & V_7 -> V_29 ;
F_10 ( & V_29 -> V_32 -> V_36 ) ;
if ( V_29 -> V_9 -> V_33 != V_50 &&
V_29 -> V_9 -> V_33 != V_65 ) {
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return - V_23 ;
}
V_49 = F_16 ( V_29 ) ;
F_14 ( L_10 , ( unsigned long ) V_49 ) ;
if ( V_49 > V_58 )
V_49 = V_58 ;
if ( V_29 -> V_30 -> V_60 ) {
char V_55 * V_66 = ( char V_55 * ) V_57 ;
V_64 = V_29 -> V_30 -> V_60 ( V_29 , V_66 , V_49 ) ;
} else {
V_64 = F_19 ( V_29 , V_57 , V_49 ) ;
}
if ( V_64 > 0 )
V_29 -> V_9 -> V_47 += V_64 ;
if ( V_29 -> V_9 -> V_33 == V_50 ) {
V_29 -> V_9 -> V_33 = V_67 ;
F_14 ( L_11 ) ;
}
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return V_64 ;
}
static T_3 F_24 ( struct V_2 * V_3 , char V_55 * V_57 ,
T_1 V_58 , T_4 * V_63 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
struct V_39 * V_29 ;
T_1 V_49 ;
int V_64 ;
if ( F_23 ( ! V_7 ) )
return - V_56 ;
V_29 = & V_7 -> V_29 ;
F_10 ( & V_29 -> V_32 -> V_36 ) ;
switch ( V_29 -> V_9 -> V_33 ) {
case V_34 :
case V_67 :
case V_68 :
case V_69 :
case V_70 :
V_64 = - V_23 ;
goto V_71;
}
V_49 = F_16 ( V_29 ) ;
F_14 ( L_10 , ( unsigned long ) V_49 ) ;
if ( V_49 > V_58 )
V_49 = V_58 ;
if ( V_29 -> V_30 -> V_60 ) {
V_64 = V_29 -> V_30 -> V_60 ( V_29 , V_57 , V_49 ) ;
} else {
V_64 = - V_72 ;
goto V_71;
}
if ( V_64 > 0 )
V_29 -> V_9 -> V_46 += V_64 ;
V_71:
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return V_64 ;
}
static int F_25 ( struct V_2 * V_3 , struct V_73 * V_74 )
{
return - V_72 ;
}
static inline int F_26 ( struct V_39 * V_29 )
{
if ( V_29 -> V_25 == V_17 )
return V_75 | V_76 ;
else
return V_77 | V_78 ;
}
static unsigned int F_27 ( struct V_2 * V_3 , T_5 * V_79 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
struct V_39 * V_29 ;
T_1 V_49 ;
int V_64 = 0 ;
if ( F_23 ( ! V_7 ) )
return - V_56 ;
V_29 = & V_7 -> V_29 ;
if ( F_23 ( ! V_29 ) )
return - V_56 ;
F_10 ( & V_29 -> V_32 -> V_36 ) ;
if ( V_29 -> V_9 -> V_33 == V_80 ||
V_29 -> V_9 -> V_33 == V_34 ) {
V_64 = - V_23 ;
goto V_71;
}
F_28 ( V_3 , & V_29 -> V_9 -> V_35 , V_79 ) ;
V_49 = F_16 ( V_29 ) ;
F_14 ( L_12 , ( unsigned long ) V_49 ) ;
switch ( V_29 -> V_9 -> V_33 ) {
case V_81 :
V_64 = F_26 ( V_29 ) ;
V_29 -> V_9 -> V_33 = V_50 ;
break;
case V_65 :
case V_67 :
case V_80 :
if ( V_49 >= V_29 -> V_9 -> V_82 )
V_64 = F_26 ( V_29 ) ;
break;
default:
if ( V_29 -> V_25 == V_17 )
V_64 = V_75 | V_76 | V_83 ;
else
V_64 = V_77 | V_78 | V_83 ;
break;
}
V_71:
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return V_64 ;
}
static int
F_29 ( struct V_39 * V_29 , unsigned long V_52 )
{
int V_64 ;
struct V_84 V_85 ;
if ( ! V_29 -> V_30 -> V_86 )
return - V_72 ;
memset ( & V_85 , 0 , sizeof( V_85 ) ) ;
V_64 = V_29 -> V_30 -> V_86 ( V_29 , & V_85 ) ;
if ( V_64 )
goto V_71;
if ( F_18 ( ( void V_55 * ) V_52 , & V_85 , sizeof( V_85 ) ) )
V_64 = - V_56 ;
V_71:
return V_64 ;
}
static int
F_30 ( struct V_39 * V_29 , unsigned long V_52 )
{
int V_64 ;
struct V_87 * V_85 ;
if ( ! V_29 -> V_30 -> V_88 )
return - V_72 ;
V_85 = F_7 ( sizeof( * V_85 ) , V_27 ) ;
if ( ! V_85 )
return - V_28 ;
V_64 = V_29 -> V_30 -> V_88 ( V_29 , V_85 ) ;
if ( V_64 )
goto V_71;
if ( F_18 ( ( void V_55 * ) V_52 , V_85 , sizeof( * V_85 ) ) )
V_64 = - V_56 ;
V_71:
F_8 ( V_85 ) ;
return V_64 ;
}
static int F_31 ( struct V_39 * V_29 ,
struct V_89 * V_90 )
{
unsigned int V_51 ;
void * V_38 ;
V_51 = V_90 -> V_38 . V_82 * V_90 -> V_38 . V_91 ;
if ( V_29 -> V_30 -> V_60 ) {
V_38 = NULL ;
} else {
V_38 = F_32 ( V_51 , V_27 ) ;
if ( ! V_38 )
return - V_28 ;
}
V_29 -> V_9 -> V_82 = V_90 -> V_38 . V_82 ;
V_29 -> V_9 -> V_91 = V_90 -> V_38 . V_91 ;
V_29 -> V_9 -> V_38 = V_38 ;
V_29 -> V_9 -> V_51 = V_51 ;
return 0 ;
}
static int F_33 ( struct V_89 * V_90 )
{
if ( V_90 -> V_38 . V_82 == 0 ||
V_90 -> V_38 . V_91 > V_92 / V_90 -> V_38 . V_82 )
return - V_20 ;
if ( V_90 -> V_93 . V_94 == 0 || V_90 -> V_93 . V_94 > V_95 )
return - V_20 ;
if ( V_90 -> V_93 . V_96 == 0 || V_90 -> V_93 . V_97 == 0 )
return - V_20 ;
if ( ! ( V_90 -> V_93 . V_98 & V_99 ) )
return - V_20 ;
return 0 ;
}
static int
F_34 ( struct V_39 * V_29 , unsigned long V_52 )
{
struct V_89 * V_90 ;
int V_64 ;
if ( V_29 -> V_9 -> V_33 == V_34 ) {
V_90 = F_32 ( sizeof( * V_90 ) , V_27 ) ;
if ( ! V_90 )
return - V_28 ;
if ( F_21 ( V_90 , ( void V_55 * ) V_52 , sizeof( * V_90 ) ) ) {
V_64 = - V_56 ;
goto V_71;
}
V_64 = F_33 ( V_90 ) ;
if ( V_64 )
goto V_71;
V_64 = F_31 ( V_29 , V_90 ) ;
if ( V_64 ) {
V_64 = - V_28 ;
goto V_71;
}
V_64 = V_29 -> V_30 -> V_100 ( V_29 , V_90 ) ;
if ( V_64 )
goto V_71;
V_29 -> V_101 = false ;
V_29 -> V_102 = false ;
if ( V_29 -> V_25 == V_17 )
V_29 -> V_9 -> V_33 = V_50 ;
else
V_29 -> V_9 -> V_33 = V_67 ;
} else {
return - V_103 ;
}
V_71:
F_8 ( V_90 ) ;
return V_64 ;
}
static int
F_35 ( struct V_39 * V_29 , unsigned long V_52 )
{
struct V_104 * V_90 ;
int V_64 ;
if ( ! V_29 -> V_30 -> V_105 )
return - V_23 ;
V_90 = F_7 ( sizeof( * V_90 ) , V_27 ) ;
if ( ! V_90 )
return - V_28 ;
V_64 = V_29 -> V_30 -> V_105 ( V_29 , V_90 ) ;
if ( V_64 )
goto V_71;
if ( F_18 ( ( char V_55 * ) V_52 , V_90 , sizeof( * V_90 ) ) )
V_64 = - V_56 ;
V_71:
F_8 ( V_90 ) ;
return V_64 ;
}
static int
F_36 ( struct V_39 * V_29 , unsigned long V_52 )
{
struct V_106 V_107 ;
int V_64 ;
if ( ! V_29 -> V_30 -> V_108 )
return - V_72 ;
if ( F_21 ( & V_107 , ( void V_55 * ) V_52 , sizeof( V_107 ) ) )
return - V_56 ;
V_64 = V_29 -> V_30 -> V_108 ( V_29 , & V_107 ) ;
if ( V_64 != 0 )
return V_64 ;
if ( F_18 ( ( void V_55 * ) V_52 , & V_107 , sizeof( V_107 ) ) )
return - V_56 ;
return 0 ;
}
static int
F_37 ( struct V_39 * V_29 , unsigned long V_52 )
{
struct V_106 V_107 ;
int V_64 ;
if ( ! V_29 -> V_30 -> V_109 )
return - V_72 ;
if ( F_21 ( & V_107 , ( void V_55 * ) V_52 , sizeof( V_107 ) ) )
return - V_56 ;
V_64 = V_29 -> V_30 -> V_109 ( V_29 , & V_107 ) ;
V_29 -> V_101 = true ;
return V_64 ;
}
static inline int
V_40 ( struct V_39 * V_29 , unsigned long V_52 )
{
struct V_40 V_41 = { 0 } ;
int V_13 ;
V_13 = F_13 ( V_29 , & V_41 ) ;
if ( V_13 == 0 )
V_13 = F_18 ( (struct V_40 V_55 * ) V_52 ,
& V_41 , sizeof( V_41 ) ) ? - V_56 : 0 ;
return V_13 ;
}
static int F_38 ( struct V_39 * V_29 )
{
int V_64 ;
if ( V_29 -> V_9 -> V_33 != V_65 )
return - V_103 ;
V_64 = V_29 -> V_30 -> V_110 ( V_29 , V_111 ) ;
if ( ! V_64 )
V_29 -> V_9 -> V_33 = V_80 ;
return V_64 ;
}
static int F_39 ( struct V_39 * V_29 )
{
int V_64 ;
if ( V_29 -> V_9 -> V_33 != V_80 )
return - V_103 ;
V_64 = V_29 -> V_30 -> V_110 ( V_29 , V_112 ) ;
if ( ! V_64 )
V_29 -> V_9 -> V_33 = V_65 ;
return V_64 ;
}
static int F_40 ( struct V_39 * V_29 )
{
int V_64 ;
if ( V_29 -> V_9 -> V_33 != V_67 )
return - V_103 ;
V_64 = V_29 -> V_30 -> V_110 ( V_29 , V_113 ) ;
if ( ! V_64 )
V_29 -> V_9 -> V_33 = V_65 ;
return V_64 ;
}
static int F_41 ( struct V_39 * V_29 )
{
int V_64 ;
if ( V_29 -> V_9 -> V_33 == V_67 ||
V_29 -> V_9 -> V_33 == V_50 )
return - V_103 ;
V_64 = V_29 -> V_30 -> V_110 ( V_29 , V_114 ) ;
if ( ! V_64 ) {
V_29 -> V_9 -> V_33 = V_50 ;
F_42 ( & V_29 -> V_9 -> V_35 ) ;
V_29 -> V_9 -> V_47 = 0 ;
V_29 -> V_9 -> V_46 = 0 ;
}
return V_64 ;
}
static int F_43 ( struct V_39 * V_29 )
{
int V_64 ;
if ( V_29 -> V_9 -> V_33 == V_67 ||
V_29 -> V_9 -> V_33 == V_50 )
return - V_103 ;
V_64 = V_29 -> V_30 -> V_110 ( V_29 , V_115 ) ;
if ( ! V_64 ) {
V_29 -> V_9 -> V_33 = V_81 ;
F_42 ( & V_29 -> V_9 -> V_35 ) ;
}
return V_64 ;
}
static int F_44 ( struct V_39 * V_29 )
{
int V_64 ;
if ( V_29 -> V_9 -> V_33 != V_65 )
return - V_103 ;
if ( V_29 -> V_101 == false )
return - V_103 ;
V_64 = V_29 -> V_30 -> V_110 ( V_29 , V_116 ) ;
if ( V_64 != 0 )
return V_64 ;
V_29 -> V_101 = false ;
V_29 -> V_102 = true ;
return 0 ;
}
static int F_45 ( struct V_39 * V_29 )
{
int V_64 ;
if ( V_29 -> V_9 -> V_33 == V_67 ||
V_29 -> V_9 -> V_33 == V_50 )
return - V_103 ;
if ( V_29 -> V_102 == false )
return - V_103 ;
V_64 = V_29 -> V_30 -> V_110 ( V_29 , V_117 ) ;
V_29 -> V_102 = false ;
return V_64 ;
}
static long F_46 ( struct V_2 * V_3 , unsigned int V_118 , unsigned long V_52 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
struct V_39 * V_29 ;
int V_64 = - V_119 ;
if ( F_23 ( ! V_7 ) )
return - V_56 ;
V_29 = & V_7 -> V_29 ;
if ( F_23 ( ! V_29 ) )
return - V_56 ;
F_10 ( & V_29 -> V_32 -> V_36 ) ;
switch ( F_47 ( V_118 ) ) {
case F_47 ( V_120 ) :
V_64 = F_48 ( V_121 ,
( int V_55 * ) V_52 ) ? - V_56 : 0 ;
break;
case F_47 ( V_122 ) :
V_64 = F_29 ( V_29 , V_52 ) ;
break;
case F_47 ( V_123 ) :
V_64 = F_30 ( V_29 , V_52 ) ;
break;
case F_47 ( V_124 ) :
V_64 = F_34 ( V_29 , V_52 ) ;
break;
case F_47 ( V_125 ) :
V_64 = F_35 ( V_29 , V_52 ) ;
break;
case F_47 ( V_126 ) :
V_64 = F_37 ( V_29 , V_52 ) ;
break;
case F_47 ( V_127 ) :
V_64 = F_36 ( V_29 , V_52 ) ;
break;
case F_47 ( V_128 ) :
V_64 = V_40 ( V_29 , V_52 ) ;
break;
case F_47 ( V_129 ) :
V_64 = F_17 ( V_29 , V_52 ) ;
break;
case F_47 ( V_130 ) :
V_64 = F_38 ( V_29 ) ;
break;
case F_47 ( V_131 ) :
V_64 = F_39 ( V_29 ) ;
break;
case F_47 ( V_132 ) :
V_64 = F_40 ( V_29 ) ;
break;
case F_47 ( V_133 ) :
V_64 = F_41 ( V_29 ) ;
break;
case F_47 ( V_134 ) :
V_64 = F_43 ( V_29 ) ;
break;
case F_47 ( V_135 ) :
V_64 = F_45 ( V_29 ) ;
break;
case F_47 ( V_136 ) :
V_64 = F_44 ( V_29 ) ;
break;
}
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return V_64 ;
}
static int F_49 ( struct V_137 * V_32 )
{
int V_13 = - V_20 ;
char V_138 [ 16 ] ;
struct V_4 * V_5 ;
if ( F_23 ( ! V_32 || ! V_32 -> V_139 ) )
return - V_23 ;
V_5 = V_32 -> V_139 ;
sprintf ( V_138 , L_13 , V_5 -> V_26 -> V_140 , V_5 -> V_32 ) ;
F_14 ( L_14 , V_138 , V_5 -> V_141 ,
V_5 -> V_25 ) ;
V_13 = F_50 ( V_22 , V_5 -> V_26 ,
V_5 -> V_32 , & V_142 , V_5 , V_138 ) ;
if ( V_13 < 0 ) {
F_5 ( L_15 , V_13 ) ;
return V_13 ;
}
return V_13 ;
}
static int F_51 ( struct V_137 * V_32 )
{
struct V_4 * V_5 ;
V_5 = V_32 -> V_139 ;
F_52 ( V_5 -> V_25 , V_5 -> V_26 , V_5 -> V_32 ) ;
return 0 ;
}
int F_53 ( struct V_143 * V_26 , int V_32 ,
int V_11 , struct V_4 * V_5 )
{
static struct V_144 V_30 = {
. V_145 = NULL ,
. V_146 = F_49 ,
. V_147 = F_51 ,
} ;
V_5 -> V_26 = V_26 ;
V_5 -> V_32 = V_32 ;
V_5 -> V_25 = V_11 ;
return F_54 ( V_26 , V_148 , V_5 , & V_30 ) ;
}
static int F_55 ( struct V_4 * V_32 )
{
int V_13 ;
if ( ! V_32 -> V_26 )
return - V_20 ;
V_13 = F_56 ( V_32 -> V_26 ) ;
if ( V_13 )
goto V_71;
return 0 ;
V_71:
F_5 ( L_16 , V_13 ) ;
return V_13 ;
}
static int F_57 ( struct V_4 * V_32 )
{
return F_58 ( V_32 -> V_26 ) ;
}
int F_59 ( struct V_4 * V_32 )
{
int V_64 ;
if ( V_32 -> V_141 == NULL || V_32 -> V_149 == NULL || V_32 -> V_30 == NULL )
return - V_20 ;
F_14 ( L_17 , V_32 -> V_141 ) ;
if ( F_23 ( ! V_32 -> V_30 -> V_37 ) )
return - V_20 ;
if ( F_23 ( ! V_32 -> V_30 -> free ) )
return - V_20 ;
if ( F_23 ( ! V_32 -> V_30 -> V_100 ) )
return - V_20 ;
if ( F_23 ( ! V_32 -> V_30 -> V_110 ) )
return - V_20 ;
F_60 ( & V_32 -> V_36 ) ;
F_10 ( & V_150 ) ;
V_64 = F_55 ( V_32 ) ;
F_11 ( & V_150 ) ;
return V_64 ;
}
int F_61 ( struct V_4 * V_32 )
{
F_14 ( L_18 , V_32 -> V_141 ) ;
F_10 ( & V_150 ) ;
F_57 ( V_32 ) ;
F_11 ( & V_150 ) ;
return 0 ;
}
static int T_6 F_62 ( void )
{
return 0 ;
}
static void T_7 F_63 ( void )
{
}
