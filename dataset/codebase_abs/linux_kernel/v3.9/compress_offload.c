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
V_29 -> V_9 -> V_46 = V_41 -> V_44 ;
V_29 -> V_9 -> V_47 = V_41 -> V_45 ;
return 0 ;
}
static T_1 F_15 ( struct V_39 * V_29 ,
struct V_48 * V_49 )
{
long V_50 ;
memset ( V_49 , 0 , sizeof( * V_49 ) ) ;
F_13 ( V_29 , & V_49 -> V_41 ) ;
if ( V_29 -> V_9 -> V_51 == 0 &&
V_29 -> V_9 -> V_33 == V_52 ) {
F_14 ( L_4 ) ;
return V_29 -> V_9 -> V_53 ;
}
F_14 ( L_5 ,
V_29 -> V_9 -> V_51 ,
V_29 -> V_9 -> V_47 ) ;
if ( V_29 -> V_9 -> V_51 ==
V_29 -> V_9 -> V_47 ) {
F_14 ( L_6 ) ;
return V_29 -> V_9 -> V_53 ;
}
V_50 = V_29 -> V_9 -> V_53 -
( V_29 -> V_9 -> V_54 - V_29 -> V_9 -> V_46 ) ;
F_14 ( L_7 , V_50 ,
V_29 -> V_9 -> V_54 ,
V_29 -> V_9 -> V_46 ) ;
if ( V_50 >= V_29 -> V_9 -> V_53 )
V_50 -= V_29 -> V_9 -> V_53 ;
F_14 ( L_8 , V_50 ) ;
V_49 -> V_49 = V_50 ;
return V_50 ;
}
static inline T_1 F_16 ( struct V_39 * V_29 )
{
struct V_48 V_49 ;
return F_15 ( V_29 , & V_49 ) ;
}
static int
F_17 ( struct V_39 * V_29 , unsigned long V_55 )
{
struct V_48 V_56 ;
T_1 V_49 ;
V_49 = F_15 ( V_29 , & V_56 ) ;
V_56 . V_49 = V_49 ;
if ( F_18 ( ( V_57 V_58 * ) V_55 ,
& V_56 , sizeof( V_56 ) ) )
return - V_59 ;
return 0 ;
}
static int F_19 ( struct V_39 * V_29 ,
const char V_58 * V_60 , T_1 V_61 )
{
void * V_62 ;
T_1 V_63 ;
struct V_8 * V_9 = V_29 -> V_9 ;
V_62 = V_9 -> V_38 + V_9 -> V_54 ;
F_14 ( L_9 ,
( unsigned long ) V_61 , V_9 -> V_54 ) ;
if ( V_61 < V_9 -> V_53 - V_9 -> V_54 ) {
if ( F_20 ( V_62 , V_60 , V_61 ) )
return - V_59 ;
V_9 -> V_54 += V_61 ;
} else {
V_63 = V_9 -> V_53 - V_9 -> V_54 ;
if ( F_20 ( V_62 , V_60 , V_63 ) )
return - V_59 ;
if ( F_20 ( V_9 -> V_38 , V_60 + V_63 , V_61 - V_63 ) )
return - V_59 ;
V_9 -> V_54 = V_61 - V_63 ;
}
if ( V_29 -> V_30 -> V_64 )
V_29 -> V_30 -> V_64 ( V_29 , V_61 ) ;
return V_61 ;
}
static T_2 F_21 ( struct V_2 * V_3 , const char V_58 * V_60 ,
T_1 V_61 , T_3 * V_65 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
struct V_39 * V_29 ;
T_1 V_49 ;
int V_66 ;
if ( F_22 ( ! V_7 ) )
return - V_59 ;
V_29 = & V_7 -> V_29 ;
F_10 ( & V_29 -> V_32 -> V_36 ) ;
if ( V_29 -> V_9 -> V_33 != V_52 &&
V_29 -> V_9 -> V_33 != V_67 ) {
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return - V_23 ;
}
V_49 = F_16 ( V_29 ) ;
F_14 ( L_10 , ( unsigned long ) V_49 ) ;
if ( V_49 > V_61 )
V_49 = V_61 ;
if ( V_29 -> V_30 -> V_63 )
V_66 = V_29 -> V_30 -> V_63 ( V_29 , V_60 , V_49 ) ;
else
V_66 = F_19 ( V_29 , V_60 , V_49 ) ;
if ( V_66 > 0 )
V_29 -> V_9 -> V_51 += V_66 ;
if ( V_29 -> V_9 -> V_33 == V_52 ) {
V_29 -> V_9 -> V_33 = V_68 ;
F_14 ( L_11 ) ;
}
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return V_66 ;
}
static T_2 F_23 ( struct V_2 * V_3 , char V_58 * V_60 ,
T_1 V_61 , T_3 * V_65 )
{
return - V_69 ;
}
static int F_24 ( struct V_2 * V_3 , struct V_70 * V_71 )
{
return - V_69 ;
}
static inline int F_25 ( struct V_39 * V_29 )
{
if ( V_29 -> V_25 == V_17 )
return V_72 | V_73 ;
else
return V_74 | V_75 ;
}
static unsigned int F_26 ( struct V_2 * V_3 , T_4 * V_76 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
struct V_39 * V_29 ;
T_1 V_49 ;
int V_66 = 0 ;
if ( F_22 ( ! V_7 ) )
return - V_59 ;
V_29 = & V_7 -> V_29 ;
if ( F_22 ( ! V_29 ) )
return - V_59 ;
F_10 ( & V_29 -> V_32 -> V_36 ) ;
if ( V_29 -> V_9 -> V_33 == V_77 ||
V_29 -> V_9 -> V_33 == V_34 ) {
V_66 = - V_23 ;
goto V_78;
}
F_27 ( V_3 , & V_29 -> V_9 -> V_35 , V_76 ) ;
V_49 = F_16 ( V_29 ) ;
F_14 ( L_12 , ( unsigned long ) V_49 ) ;
switch ( V_29 -> V_9 -> V_33 ) {
case V_79 :
V_66 = F_25 ( V_29 ) ;
V_29 -> V_9 -> V_33 = V_52 ;
break;
case V_67 :
case V_68 :
case V_77 :
if ( V_49 >= V_29 -> V_9 -> V_80 )
V_66 = F_25 ( V_29 ) ;
break;
default:
if ( V_29 -> V_25 == V_17 )
V_66 = V_72 | V_73 | V_81 ;
else
V_66 = V_74 | V_75 | V_81 ;
break;
}
V_78:
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return V_66 ;
}
static int
F_28 ( struct V_39 * V_29 , unsigned long V_55 )
{
int V_66 ;
struct V_82 V_83 ;
if ( ! V_29 -> V_30 -> V_84 )
return - V_69 ;
V_66 = V_29 -> V_30 -> V_84 ( V_29 , & V_83 ) ;
if ( V_66 )
goto V_78;
if ( F_18 ( ( void V_58 * ) V_55 , & V_83 , sizeof( V_83 ) ) )
V_66 = - V_59 ;
V_78:
return V_66 ;
}
static int
F_29 ( struct V_39 * V_29 , unsigned long V_55 )
{
int V_66 ;
struct V_85 * V_83 ;
if ( ! V_29 -> V_30 -> V_86 )
return - V_69 ;
V_83 = F_30 ( sizeof( * V_83 ) , V_27 ) ;
if ( ! V_83 )
return - V_28 ;
V_66 = V_29 -> V_30 -> V_86 ( V_29 , V_83 ) ;
if ( V_66 )
goto V_78;
if ( F_18 ( ( void V_58 * ) V_55 , V_83 , sizeof( * V_83 ) ) )
V_66 = - V_59 ;
V_78:
F_8 ( V_83 ) ;
return V_66 ;
}
static int F_31 ( struct V_39 * V_29 ,
struct V_87 * V_88 )
{
unsigned int V_53 ;
void * V_38 ;
V_53 = V_88 -> V_38 . V_80 * V_88 -> V_38 . V_89 ;
if ( V_29 -> V_30 -> V_63 ) {
V_38 = NULL ;
} else {
V_38 = F_30 ( V_53 , V_27 ) ;
if ( ! V_38 )
return - V_28 ;
}
V_29 -> V_9 -> V_80 = V_88 -> V_38 . V_80 ;
V_29 -> V_9 -> V_89 = V_88 -> V_38 . V_89 ;
V_29 -> V_9 -> V_38 = V_38 ;
V_29 -> V_9 -> V_53 = V_53 ;
return 0 ;
}
static int F_32 ( struct V_87 * V_88 )
{
if ( V_88 -> V_38 . V_80 == 0 ||
V_88 -> V_38 . V_89 > V_90 / V_88 -> V_38 . V_80 )
return - V_20 ;
if ( V_88 -> V_91 . V_92 == 0 || V_88 -> V_91 . V_92 > V_93 )
return - V_20 ;
if ( V_88 -> V_91 . V_94 == 0 || V_88 -> V_91 . V_95 == 0 )
return - V_20 ;
if ( ! ( V_88 -> V_91 . V_96 & V_97 ) )
return - V_20 ;
return 0 ;
}
static int
F_33 ( struct V_39 * V_29 , unsigned long V_55 )
{
struct V_87 * V_88 ;
int V_66 ;
if ( V_29 -> V_9 -> V_33 == V_34 ) {
V_88 = F_30 ( sizeof( * V_88 ) , V_27 ) ;
if ( ! V_88 )
return - V_28 ;
if ( F_20 ( V_88 , ( void V_58 * ) V_55 , sizeof( * V_88 ) ) ) {
V_66 = - V_59 ;
goto V_78;
}
V_66 = F_32 ( V_88 ) ;
if ( V_66 )
goto V_78;
V_66 = F_31 ( V_29 , V_88 ) ;
if ( V_66 ) {
V_66 = - V_28 ;
goto V_78;
}
V_66 = V_29 -> V_30 -> V_98 ( V_29 , V_88 ) ;
if ( V_66 )
goto V_78;
V_29 -> V_9 -> V_33 = V_52 ;
V_29 -> V_99 = false ;
V_29 -> V_100 = false ;
} else {
return - V_101 ;
}
V_78:
F_8 ( V_88 ) ;
return V_66 ;
}
static int
F_34 ( struct V_39 * V_29 , unsigned long V_55 )
{
struct V_102 * V_88 ;
int V_66 ;
if ( ! V_29 -> V_30 -> V_103 )
return - V_23 ;
V_88 = F_30 ( sizeof( * V_88 ) , V_27 ) ;
if ( ! V_88 )
return - V_28 ;
V_66 = V_29 -> V_30 -> V_103 ( V_29 , V_88 ) ;
if ( V_66 )
goto V_78;
if ( F_18 ( ( char V_58 * ) V_55 , V_88 , sizeof( * V_88 ) ) )
V_66 = - V_59 ;
V_78:
F_8 ( V_88 ) ;
return V_66 ;
}
static int
F_35 ( struct V_39 * V_29 , unsigned long V_55 )
{
struct V_104 V_105 ;
int V_66 ;
if ( ! V_29 -> V_30 -> V_106 )
return - V_69 ;
if ( F_20 ( & V_105 , ( void V_58 * ) V_55 , sizeof( V_105 ) ) )
return - V_59 ;
V_66 = V_29 -> V_30 -> V_106 ( V_29 , & V_105 ) ;
if ( V_66 != 0 )
return V_66 ;
if ( F_18 ( ( void V_58 * ) V_55 , & V_105 , sizeof( V_105 ) ) )
return - V_59 ;
return 0 ;
}
static int
F_36 ( struct V_39 * V_29 , unsigned long V_55 )
{
struct V_104 V_105 ;
int V_66 ;
if ( ! V_29 -> V_30 -> V_107 )
return - V_69 ;
if ( F_20 ( & V_105 , ( void V_58 * ) V_55 , sizeof( V_105 ) ) )
return - V_59 ;
V_66 = V_29 -> V_30 -> V_107 ( V_29 , & V_105 ) ;
V_29 -> V_99 = true ;
return V_66 ;
}
static inline int
V_40 ( struct V_39 * V_29 , unsigned long V_55 )
{
struct V_40 V_41 = { 0 } ;
int V_13 ;
V_13 = F_13 ( V_29 , & V_41 ) ;
if ( V_13 == 0 )
V_13 = F_18 ( (struct V_40 V_58 * ) V_55 ,
& V_41 , sizeof( V_41 ) ) ? - V_59 : 0 ;
return V_13 ;
}
static int F_37 ( struct V_39 * V_29 )
{
int V_66 ;
if ( V_29 -> V_9 -> V_33 != V_67 )
return - V_101 ;
V_66 = V_29 -> V_30 -> V_108 ( V_29 , V_109 ) ;
if ( ! V_66 )
V_29 -> V_9 -> V_33 = V_77 ;
return V_66 ;
}
static int F_38 ( struct V_39 * V_29 )
{
int V_66 ;
if ( V_29 -> V_9 -> V_33 != V_77 )
return - V_101 ;
V_66 = V_29 -> V_30 -> V_108 ( V_29 , V_110 ) ;
if ( ! V_66 )
V_29 -> V_9 -> V_33 = V_67 ;
return V_66 ;
}
static int F_39 ( struct V_39 * V_29 )
{
int V_66 ;
if ( V_29 -> V_9 -> V_33 != V_68 )
return - V_101 ;
V_66 = V_29 -> V_30 -> V_108 ( V_29 , V_111 ) ;
if ( ! V_66 )
V_29 -> V_9 -> V_33 = V_67 ;
return V_66 ;
}
static int F_40 ( struct V_39 * V_29 )
{
int V_66 ;
if ( V_29 -> V_9 -> V_33 == V_68 ||
V_29 -> V_9 -> V_33 == V_52 )
return - V_101 ;
V_66 = V_29 -> V_30 -> V_108 ( V_29 , V_112 ) ;
if ( ! V_66 ) {
V_29 -> V_9 -> V_33 = V_52 ;
F_41 ( & V_29 -> V_9 -> V_35 ) ;
V_29 -> V_9 -> V_46 = 0 ;
V_29 -> V_9 -> V_54 = 0 ;
V_29 -> V_9 -> V_51 = 0 ;
V_29 -> V_9 -> V_47 = 0 ;
}
return V_66 ;
}
static int F_42 ( struct V_39 * V_29 )
{
int V_66 ;
if ( V_29 -> V_9 -> V_33 == V_68 ||
V_29 -> V_9 -> V_33 == V_52 )
return - V_101 ;
V_66 = V_29 -> V_30 -> V_108 ( V_29 , V_113 ) ;
if ( ! V_66 ) {
V_29 -> V_9 -> V_33 = V_79 ;
F_41 ( & V_29 -> V_9 -> V_35 ) ;
}
return V_66 ;
}
static int F_43 ( struct V_39 * V_29 )
{
int V_66 ;
if ( V_29 -> V_9 -> V_33 != V_67 )
return - V_101 ;
if ( V_29 -> V_99 == false )
return - V_101 ;
V_66 = V_29 -> V_30 -> V_108 ( V_29 , V_114 ) ;
if ( V_66 != 0 )
return V_66 ;
V_29 -> V_99 = false ;
V_29 -> V_100 = true ;
return 0 ;
}
static int F_44 ( struct V_39 * V_29 )
{
int V_66 ;
if ( V_29 -> V_9 -> V_33 == V_68 ||
V_29 -> V_9 -> V_33 == V_52 )
return - V_101 ;
if ( V_29 -> V_100 == false )
return - V_101 ;
V_66 = V_29 -> V_30 -> V_108 ( V_29 , V_115 ) ;
V_29 -> V_100 = false ;
return V_66 ;
}
static long F_45 ( struct V_2 * V_3 , unsigned int V_116 , unsigned long V_55 )
{
struct V_6 * V_7 = V_3 -> V_31 ;
struct V_39 * V_29 ;
int V_66 = - V_117 ;
if ( F_22 ( ! V_7 ) )
return - V_59 ;
V_29 = & V_7 -> V_29 ;
if ( F_22 ( ! V_29 ) )
return - V_59 ;
F_10 ( & V_29 -> V_32 -> V_36 ) ;
switch ( F_46 ( V_116 ) ) {
case F_46 ( V_118 ) :
F_47 ( V_119 ,
( int V_58 * ) V_55 ) ? - V_59 : 0 ;
break;
case F_46 ( V_120 ) :
V_66 = F_28 ( V_29 , V_55 ) ;
break;
case F_46 ( V_121 ) :
V_66 = F_29 ( V_29 , V_55 ) ;
break;
case F_46 ( V_122 ) :
V_66 = F_33 ( V_29 , V_55 ) ;
break;
case F_46 ( V_123 ) :
V_66 = F_34 ( V_29 , V_55 ) ;
break;
case F_46 ( V_124 ) :
V_66 = F_36 ( V_29 , V_55 ) ;
break;
case F_46 ( V_125 ) :
V_66 = F_35 ( V_29 , V_55 ) ;
break;
case F_46 ( V_126 ) :
V_66 = V_40 ( V_29 , V_55 ) ;
break;
case F_46 ( V_127 ) :
V_66 = F_17 ( V_29 , V_55 ) ;
break;
case F_46 ( V_128 ) :
V_66 = F_37 ( V_29 ) ;
break;
case F_46 ( V_129 ) :
V_66 = F_38 ( V_29 ) ;
break;
case F_46 ( V_130 ) :
V_66 = F_39 ( V_29 ) ;
break;
case F_46 ( V_131 ) :
V_66 = F_40 ( V_29 ) ;
break;
case F_46 ( V_132 ) :
V_66 = F_42 ( V_29 ) ;
break;
case F_46 ( V_133 ) :
V_66 = F_44 ( V_29 ) ;
break;
case F_46 ( V_134 ) :
V_66 = F_43 ( V_29 ) ;
break;
}
F_11 ( & V_29 -> V_32 -> V_36 ) ;
return V_66 ;
}
static int F_48 ( struct V_135 * V_32 )
{
int V_13 = - V_20 ;
char V_136 [ 16 ] ;
struct V_4 * V_5 ;
if ( F_22 ( ! V_32 || ! V_32 -> V_137 ) )
return - V_23 ;
V_5 = V_32 -> V_137 ;
sprintf ( V_136 , L_13 , V_5 -> V_26 -> V_138 , V_5 -> V_32 ) ;
F_14 ( L_14 , V_136 , V_5 -> V_139 ,
V_5 -> V_25 ) ;
V_13 = F_49 ( V_22 , V_5 -> V_26 ,
V_5 -> V_32 , & V_140 , V_5 , V_136 ) ;
if ( V_13 < 0 ) {
F_5 ( L_15 , V_13 ) ;
return V_13 ;
}
return V_13 ;
}
static int F_50 ( struct V_135 * V_32 )
{
struct V_4 * V_5 ;
V_5 = V_32 -> V_137 ;
F_51 ( V_5 -> V_25 , V_5 -> V_26 , V_5 -> V_32 ) ;
return 0 ;
}
int F_52 ( struct V_141 * V_26 , int V_32 ,
int V_11 , struct V_4 * V_5 )
{
static struct V_142 V_30 = {
. V_143 = NULL ,
. V_144 = F_48 ,
. V_145 = F_50 ,
} ;
V_5 -> V_26 = V_26 ;
V_5 -> V_32 = V_32 ;
V_5 -> V_25 = V_11 ;
return F_53 ( V_26 , V_146 , V_5 , & V_30 ) ;
}
static int F_54 ( struct V_4 * V_32 )
{
int V_13 ;
if ( ! V_32 -> V_26 )
return - V_20 ;
V_13 = F_55 ( V_32 -> V_26 ) ;
if ( V_13 )
goto V_78;
return 0 ;
V_78:
F_5 ( L_16 , V_13 ) ;
return V_13 ;
}
static int F_56 ( struct V_4 * V_32 )
{
return F_57 ( V_32 -> V_26 ) ;
}
int F_58 ( struct V_4 * V_32 )
{
int V_66 ;
if ( V_32 -> V_139 == NULL || V_32 -> V_147 == NULL || V_32 -> V_30 == NULL )
return - V_20 ;
F_14 ( L_17 , V_32 -> V_139 ) ;
if ( F_22 ( ! V_32 -> V_30 -> V_37 ) )
return - V_20 ;
if ( F_22 ( ! V_32 -> V_30 -> free ) )
return - V_20 ;
if ( F_22 ( ! V_32 -> V_30 -> V_98 ) )
return - V_20 ;
if ( F_22 ( ! V_32 -> V_30 -> V_108 ) )
return - V_20 ;
F_59 ( & V_32 -> V_36 ) ;
F_10 ( & V_148 ) ;
V_66 = F_54 ( V_32 ) ;
F_11 ( & V_148 ) ;
return V_66 ;
}
int F_60 ( struct V_4 * V_32 )
{
F_14 ( L_18 , V_32 -> V_139 ) ;
F_10 ( & V_148 ) ;
F_56 ( V_32 ) ;
F_11 ( & V_148 ) ;
return 0 ;
}
static int T_5 F_61 ( void )
{
return 0 ;
}
static void T_6 F_62 ( void )
{
}
