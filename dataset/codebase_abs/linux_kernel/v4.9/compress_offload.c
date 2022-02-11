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
F_8 ( & V_7 -> V_29 . V_30 , V_31 ) ;
V_7 -> V_29 . V_32 = V_5 -> V_32 ;
V_7 -> V_29 . V_25 = V_11 ;
V_7 -> V_29 . V_33 = V_5 -> V_33 ;
V_7 -> V_29 . V_34 = V_5 ;
V_9 = F_7 ( sizeof( * V_9 ) , V_27 ) ;
if ( ! V_9 ) {
F_9 ( V_7 ) ;
F_6 ( V_5 -> V_26 ) ;
return - V_28 ;
}
V_9 -> V_35 = V_36 ;
F_10 ( & V_9 -> V_37 ) ;
V_7 -> V_29 . V_9 = V_9 ;
V_3 -> V_33 = ( void * ) V_7 ;
F_11 ( & V_5 -> V_38 ) ;
V_13 = V_5 -> V_32 -> V_39 ( & V_7 -> V_29 ) ;
F_12 ( & V_5 -> V_38 ) ;
if ( V_13 ) {
F_9 ( V_9 ) ;
F_9 ( V_7 ) ;
}
F_6 ( V_5 -> V_26 ) ;
return V_13 ;
}
static int F_13 ( struct V_1 * V_1 , struct V_2 * V_3 )
{
struct V_6 * V_7 = V_3 -> V_33 ;
struct V_8 * V_9 = V_7 -> V_29 . V_9 ;
F_14 ( & V_7 -> V_29 . V_30 ) ;
switch ( V_9 -> V_35 ) {
case V_40 :
case V_41 :
case V_42 :
V_7 -> V_29 . V_32 -> V_43 ( & V_7 -> V_29 , V_44 ) ;
break;
default:
break;
}
V_7 -> V_29 . V_32 -> free ( & V_7 -> V_29 ) ;
F_9 ( V_7 -> V_29 . V_9 -> V_45 ) ;
F_9 ( V_7 -> V_29 . V_9 ) ;
F_9 ( V_7 ) ;
return 0 ;
}
static int F_15 ( struct V_46 * V_29 ,
struct V_47 * V_48 )
{
if ( ! V_29 -> V_32 -> V_49 )
return - V_50 ;
V_29 -> V_32 -> V_49 ( V_29 , V_48 ) ;
F_16 ( L_3 ,
V_48 -> V_51 , V_48 -> V_52 ) ;
if ( V_29 -> V_25 == V_17 )
V_29 -> V_9 -> V_53 = V_48 -> V_52 ;
else
V_29 -> V_9 -> V_54 = V_48 -> V_52 ;
return 0 ;
}
static T_1 F_17 ( struct V_46 * V_29 ,
struct V_55 * V_56 )
{
memset ( V_56 , 0 , sizeof( * V_56 ) ) ;
F_15 ( V_29 , & V_56 -> V_48 ) ;
if ( V_29 -> V_9 -> V_54 == 0 &&
V_29 -> V_9 -> V_35 == V_57 &&
V_29 -> V_25 == V_17 ) {
F_16 ( L_4 ) ;
return V_29 -> V_9 -> V_58 ;
}
F_16 ( L_5 ,
V_29 -> V_9 -> V_54 ,
V_29 -> V_9 -> V_53 ) ;
if ( V_29 -> V_9 -> V_54 ==
V_29 -> V_9 -> V_53 ) {
if ( V_29 -> V_25 == V_17 ) {
F_16 ( L_6 ) ;
return V_29 -> V_9 -> V_58 ;
} else {
F_16 ( L_7 ) ;
return 0 ;
}
}
V_56 -> V_56 = V_29 -> V_9 -> V_54 -
V_29 -> V_9 -> V_53 ;
if ( V_29 -> V_25 == V_17 )
V_56 -> V_56 = V_29 -> V_9 -> V_58 - V_56 -> V_56 ;
F_16 ( L_8 , V_56 -> V_56 ) ;
return V_56 -> V_56 ;
}
static inline T_1 F_18 ( struct V_46 * V_29 )
{
struct V_55 V_56 ;
return F_17 ( V_29 , & V_56 ) ;
}
static int
F_19 ( struct V_46 * V_29 , unsigned long V_59 )
{
struct V_55 V_60 ;
T_1 V_56 ;
V_56 = F_17 ( V_29 , & V_60 ) ;
V_60 . V_56 = V_56 ;
switch ( V_29 -> V_9 -> V_35 ) {
case V_36 :
return - V_23 ;
case V_61 :
return - V_62 ;
default:
break;
}
if ( F_20 ( ( V_63 V_64 * ) V_59 ,
& V_60 , sizeof( V_60 ) ) )
return - V_65 ;
return 0 ;
}
static int F_21 ( struct V_46 * V_29 ,
const char V_64 * V_66 , T_1 V_67 )
{
void * V_68 ;
T_1 V_69 ;
struct V_8 * V_9 = V_29 -> V_9 ;
T_2 V_70 = F_22 ( V_9 -> V_54 ,
V_9 -> V_58 ) ;
V_70 = V_9 -> V_54 -
( V_70 * V_9 -> V_58 ) ;
V_68 = V_9 -> V_45 + V_70 ;
F_16 ( L_9 ,
( unsigned long ) V_67 , V_70 ) ;
if ( V_67 < V_9 -> V_58 - V_70 ) {
if ( F_23 ( V_68 , V_66 , V_67 ) )
return - V_65 ;
} else {
V_69 = V_9 -> V_58 - V_70 ;
if ( F_23 ( V_68 , V_66 , V_69 ) )
return - V_65 ;
if ( F_23 ( V_9 -> V_45 , V_66 + V_69 , V_67 - V_69 ) )
return - V_65 ;
}
if ( V_29 -> V_32 -> V_71 )
V_29 -> V_32 -> V_71 ( V_29 , V_67 ) ;
return V_67 ;
}
static T_3 F_24 ( struct V_2 * V_3 , const char V_64 * V_66 ,
T_1 V_67 , T_4 * V_72 )
{
struct V_6 * V_7 = V_3 -> V_33 ;
struct V_46 * V_29 ;
T_1 V_56 ;
int V_73 ;
if ( F_25 ( ! V_7 ) )
return - V_65 ;
V_29 = & V_7 -> V_29 ;
F_11 ( & V_29 -> V_34 -> V_38 ) ;
switch ( V_29 -> V_9 -> V_35 ) {
case V_57 :
case V_74 :
case V_40 :
break;
default:
F_12 ( & V_29 -> V_34 -> V_38 ) ;
return - V_23 ;
}
V_56 = F_18 ( V_29 ) ;
F_16 ( L_10 , ( unsigned long ) V_56 ) ;
if ( V_56 > V_67 )
V_56 = V_67 ;
if ( V_29 -> V_32 -> V_69 ) {
char V_64 * V_75 = ( char V_64 * ) V_66 ;
V_73 = V_29 -> V_32 -> V_69 ( V_29 , V_75 , V_56 ) ;
} else {
V_73 = F_21 ( V_29 , V_66 , V_56 ) ;
}
if ( V_73 > 0 )
V_29 -> V_9 -> V_54 += V_73 ;
if ( V_29 -> V_9 -> V_35 == V_57 ) {
V_29 -> V_9 -> V_35 = V_74 ;
F_16 ( L_11 ) ;
}
F_12 ( & V_29 -> V_34 -> V_38 ) ;
return V_73 ;
}
static T_3 F_26 ( struct V_2 * V_3 , char V_64 * V_66 ,
T_1 V_67 , T_4 * V_72 )
{
struct V_6 * V_7 = V_3 -> V_33 ;
struct V_46 * V_29 ;
T_1 V_56 ;
int V_73 ;
if ( F_25 ( ! V_7 ) )
return - V_65 ;
V_29 = & V_7 -> V_29 ;
F_11 ( & V_29 -> V_34 -> V_38 ) ;
switch ( V_29 -> V_9 -> V_35 ) {
case V_36 :
case V_74 :
case V_76 :
case V_77 :
V_73 = - V_23 ;
goto V_78;
case V_61 :
V_73 = - V_62 ;
goto V_78;
}
V_56 = F_18 ( V_29 ) ;
F_16 ( L_10 , ( unsigned long ) V_56 ) ;
if ( V_56 > V_67 )
V_56 = V_67 ;
if ( V_29 -> V_32 -> V_69 ) {
V_73 = V_29 -> V_32 -> V_69 ( V_29 , V_66 , V_56 ) ;
} else {
V_73 = - V_79 ;
goto V_78;
}
if ( V_73 > 0 )
V_29 -> V_9 -> V_53 += V_73 ;
V_78:
F_12 ( & V_29 -> V_34 -> V_38 ) ;
return V_73 ;
}
static int F_27 ( struct V_2 * V_3 , struct V_80 * V_81 )
{
return - V_79 ;
}
static inline int F_28 ( struct V_46 * V_29 )
{
if ( V_29 -> V_25 == V_17 )
return V_82 | V_83 ;
else
return V_84 | V_85 ;
}
static unsigned int F_29 ( struct V_2 * V_3 , T_5 * V_86 )
{
struct V_6 * V_7 = V_3 -> V_33 ;
struct V_46 * V_29 ;
T_1 V_56 ;
int V_73 = 0 ;
if ( F_25 ( ! V_7 ) )
return V_87 ;
V_29 = & V_7 -> V_29 ;
F_11 ( & V_29 -> V_34 -> V_38 ) ;
switch ( V_29 -> V_9 -> V_35 ) {
case V_36 :
case V_61 :
V_73 = F_28 ( V_29 ) | V_87 ;
goto V_78;
default:
break;
}
F_30 ( V_3 , & V_29 -> V_9 -> V_37 , V_86 ) ;
V_56 = F_18 ( V_29 ) ;
F_16 ( L_12 , ( unsigned long ) V_56 ) ;
switch ( V_29 -> V_9 -> V_35 ) {
case V_41 :
V_73 = F_28 ( V_29 ) ;
V_29 -> V_9 -> V_35 = V_57 ;
break;
case V_40 :
case V_74 :
case V_42 :
if ( V_56 >= V_29 -> V_9 -> V_88 )
V_73 = F_28 ( V_29 ) ;
break;
default:
V_73 = F_28 ( V_29 ) | V_87 ;
break;
}
V_78:
F_12 ( & V_29 -> V_34 -> V_38 ) ;
return V_73 ;
}
static int
F_31 ( struct V_46 * V_29 , unsigned long V_59 )
{
int V_73 ;
struct V_89 V_90 ;
if ( ! V_29 -> V_32 -> V_91 )
return - V_79 ;
memset ( & V_90 , 0 , sizeof( V_90 ) ) ;
V_73 = V_29 -> V_32 -> V_91 ( V_29 , & V_90 ) ;
if ( V_73 )
goto V_78;
if ( F_20 ( ( void V_64 * ) V_59 , & V_90 , sizeof( V_90 ) ) )
V_73 = - V_65 ;
V_78:
return V_73 ;
}
static int
F_32 ( struct V_46 * V_29 , unsigned long V_59 )
{
int V_73 ;
struct V_92 * V_90 ;
if ( ! V_29 -> V_32 -> V_93 )
return - V_79 ;
V_90 = F_7 ( sizeof( * V_90 ) , V_27 ) ;
if ( ! V_90 )
return - V_28 ;
V_73 = V_29 -> V_32 -> V_93 ( V_29 , V_90 ) ;
if ( V_73 )
goto V_78;
if ( F_20 ( ( void V_64 * ) V_59 , V_90 , sizeof( * V_90 ) ) )
V_73 = - V_65 ;
V_78:
F_9 ( V_90 ) ;
return V_73 ;
}
static int F_33 ( struct V_46 * V_29 ,
struct V_94 * V_95 )
{
unsigned int V_58 ;
void * V_45 ;
V_58 = V_95 -> V_45 . V_88 * V_95 -> V_45 . V_96 ;
if ( V_29 -> V_32 -> V_69 ) {
V_45 = NULL ;
} else {
V_45 = F_34 ( V_58 , V_27 ) ;
if ( ! V_45 )
return - V_28 ;
}
V_29 -> V_9 -> V_88 = V_95 -> V_45 . V_88 ;
V_29 -> V_9 -> V_96 = V_95 -> V_45 . V_96 ;
V_29 -> V_9 -> V_45 = V_45 ;
V_29 -> V_9 -> V_58 = V_58 ;
return 0 ;
}
static int F_35 ( struct V_94 * V_95 )
{
if ( V_95 -> V_45 . V_88 == 0 ||
V_95 -> V_45 . V_96 > V_97 / V_95 -> V_45 . V_88 )
return - V_20 ;
if ( V_95 -> V_98 . V_99 == 0 || V_95 -> V_98 . V_99 > V_100 )
return - V_20 ;
if ( V_95 -> V_98 . V_101 == 0 || V_95 -> V_98 . V_102 == 0 )
return - V_20 ;
return 0 ;
}
static int
F_36 ( struct V_46 * V_29 , unsigned long V_59 )
{
struct V_94 * V_95 ;
int V_73 ;
if ( V_29 -> V_9 -> V_35 == V_36 ) {
V_95 = F_37 ( ( void V_64 * ) V_59 , sizeof( * V_95 ) ) ;
if ( F_38 ( V_95 ) )
return F_39 ( V_95 ) ;
V_73 = F_35 ( V_95 ) ;
if ( V_73 )
goto V_78;
V_73 = F_33 ( V_29 , V_95 ) ;
if ( V_73 ) {
V_73 = - V_28 ;
goto V_78;
}
V_73 = V_29 -> V_32 -> V_103 ( V_29 , V_95 ) ;
if ( V_73 )
goto V_78;
V_29 -> V_104 = false ;
V_29 -> V_105 = false ;
if ( V_29 -> V_25 == V_17 )
V_29 -> V_9 -> V_35 = V_57 ;
else
V_29 -> V_9 -> V_35 = V_74 ;
} else {
return - V_106 ;
}
V_78:
F_9 ( V_95 ) ;
return V_73 ;
}
static int
F_40 ( struct V_46 * V_29 , unsigned long V_59 )
{
struct V_107 * V_95 ;
int V_73 ;
if ( ! V_29 -> V_32 -> V_108 )
return - V_23 ;
V_95 = F_7 ( sizeof( * V_95 ) , V_27 ) ;
if ( ! V_95 )
return - V_28 ;
V_73 = V_29 -> V_32 -> V_108 ( V_29 , V_95 ) ;
if ( V_73 )
goto V_78;
if ( F_20 ( ( char V_64 * ) V_59 , V_95 , sizeof( * V_95 ) ) )
V_73 = - V_65 ;
V_78:
F_9 ( V_95 ) ;
return V_73 ;
}
static int
F_41 ( struct V_46 * V_29 , unsigned long V_59 )
{
struct V_109 V_110 ;
int V_73 ;
if ( ! V_29 -> V_32 -> V_111 )
return - V_79 ;
if ( F_23 ( & V_110 , ( void V_64 * ) V_59 , sizeof( V_110 ) ) )
return - V_65 ;
V_73 = V_29 -> V_32 -> V_111 ( V_29 , & V_110 ) ;
if ( V_73 != 0 )
return V_73 ;
if ( F_20 ( ( void V_64 * ) V_59 , & V_110 , sizeof( V_110 ) ) )
return - V_65 ;
return 0 ;
}
static int
F_42 ( struct V_46 * V_29 , unsigned long V_59 )
{
struct V_109 V_110 ;
int V_73 ;
if ( ! V_29 -> V_32 -> V_112 )
return - V_79 ;
if ( F_23 ( & V_110 , ( void V_64 * ) V_59 , sizeof( V_110 ) ) )
return - V_65 ;
V_73 = V_29 -> V_32 -> V_112 ( V_29 , & V_110 ) ;
V_29 -> V_104 = true ;
return V_73 ;
}
static inline int
V_47 ( struct V_46 * V_29 , unsigned long V_59 )
{
struct V_47 V_48 = { 0 } ;
int V_13 ;
V_13 = F_15 ( V_29 , & V_48 ) ;
if ( V_13 == 0 )
V_13 = F_20 ( (struct V_47 V_64 * ) V_59 ,
& V_48 , sizeof( V_48 ) ) ? - V_65 : 0 ;
return V_13 ;
}
static int F_43 ( struct V_46 * V_29 )
{
int V_73 ;
if ( V_29 -> V_9 -> V_35 != V_40 )
return - V_106 ;
V_73 = V_29 -> V_32 -> V_43 ( V_29 , V_113 ) ;
if ( ! V_73 )
V_29 -> V_9 -> V_35 = V_42 ;
return V_73 ;
}
static int F_44 ( struct V_46 * V_29 )
{
int V_73 ;
if ( V_29 -> V_9 -> V_35 != V_42 )
return - V_106 ;
V_73 = V_29 -> V_32 -> V_43 ( V_29 , V_114 ) ;
if ( ! V_73 )
V_29 -> V_9 -> V_35 = V_40 ;
return V_73 ;
}
static int F_45 ( struct V_46 * V_29 )
{
int V_73 ;
if ( V_29 -> V_9 -> V_35 != V_74 )
return - V_106 ;
V_73 = V_29 -> V_32 -> V_43 ( V_29 , V_115 ) ;
if ( ! V_73 )
V_29 -> V_9 -> V_35 = V_40 ;
return V_73 ;
}
static int F_46 ( struct V_46 * V_29 )
{
int V_73 ;
if ( V_29 -> V_9 -> V_35 == V_74 ||
V_29 -> V_9 -> V_35 == V_57 )
return - V_106 ;
V_73 = V_29 -> V_32 -> V_43 ( V_29 , V_44 ) ;
if ( ! V_73 ) {
F_47 ( V_29 ) ;
V_29 -> V_9 -> V_54 = 0 ;
V_29 -> V_9 -> V_53 = 0 ;
}
return V_73 ;
}
static void V_31 ( struct V_116 * V_117 )
{
struct V_46 * V_29 ;
V_29 = F_48 ( V_117 , struct V_46 , V_30 . V_117 ) ;
F_11 ( & V_29 -> V_34 -> V_38 ) ;
V_29 -> V_32 -> V_43 ( V_29 , V_44 ) ;
F_49 ( & V_29 -> V_9 -> V_37 ) ;
F_12 ( & V_29 -> V_34 -> V_38 ) ;
}
int F_50 ( struct V_46 * V_29 ,
T_6 V_35 )
{
if ( V_29 -> V_9 -> V_35 == V_35 )
return 0 ;
V_29 -> V_9 -> V_35 = V_35 ;
F_16 ( L_13 , V_35 ) ;
F_51 ( V_118 , & V_29 -> V_30 , 0 ) ;
return 0 ;
}
static int F_52 ( struct V_46 * V_29 )
{
int V_13 ;
V_29 -> V_9 -> V_35 = V_41 ;
F_12 ( & V_29 -> V_34 -> V_38 ) ;
V_13 = F_53 ( V_29 -> V_9 -> V_37 ,
( V_29 -> V_9 -> V_35 != V_41 ) ) ;
if ( V_13 == - V_119 )
F_16 ( L_14 ) ;
else if ( V_13 )
F_16 ( L_15 , V_13 ) ;
F_49 ( & V_29 -> V_9 -> V_37 ) ;
F_11 ( & V_29 -> V_34 -> V_38 ) ;
return V_13 ;
}
static int F_54 ( struct V_46 * V_29 )
{
int V_73 ;
if ( V_29 -> V_9 -> V_35 == V_74 ||
V_29 -> V_9 -> V_35 == V_57 )
return - V_106 ;
V_73 = V_29 -> V_32 -> V_43 ( V_29 , V_120 ) ;
if ( V_73 ) {
F_16 ( L_16 , V_73 ) ;
F_49 ( & V_29 -> V_9 -> V_37 ) ;
return V_73 ;
}
return F_52 ( V_29 ) ;
}
static int F_55 ( struct V_46 * V_29 )
{
int V_73 ;
if ( V_29 -> V_9 -> V_35 != V_40 )
return - V_106 ;
if ( V_29 -> V_104 == false )
return - V_106 ;
V_73 = V_29 -> V_32 -> V_43 ( V_29 , V_121 ) ;
if ( V_73 != 0 )
return V_73 ;
V_29 -> V_104 = false ;
V_29 -> V_105 = true ;
return 0 ;
}
static int F_56 ( struct V_46 * V_29 )
{
int V_73 ;
if ( V_29 -> V_9 -> V_35 == V_74 ||
V_29 -> V_9 -> V_35 == V_57 )
return - V_106 ;
if ( V_29 -> V_105 == false )
return - V_106 ;
V_73 = V_29 -> V_32 -> V_43 ( V_29 , V_122 ) ;
if ( V_73 ) {
F_16 ( L_17 ) ;
F_49 ( & V_29 -> V_9 -> V_37 ) ;
return V_73 ;
}
V_29 -> V_105 = false ;
return F_52 ( V_29 ) ;
}
static long F_57 ( struct V_2 * V_3 , unsigned int V_123 , unsigned long V_59 )
{
struct V_6 * V_7 = V_3 -> V_33 ;
struct V_46 * V_29 ;
int V_73 = - V_124 ;
if ( F_25 ( ! V_7 ) )
return - V_65 ;
V_29 = & V_7 -> V_29 ;
F_11 ( & V_29 -> V_34 -> V_38 ) ;
switch ( F_58 ( V_123 ) ) {
case F_58 ( V_125 ) :
V_73 = F_59 ( V_126 ,
( int V_64 * ) V_59 ) ? - V_65 : 0 ;
break;
case F_58 ( V_127 ) :
V_73 = F_31 ( V_29 , V_59 ) ;
break;
#ifndef F_60
case F_58 ( V_128 ) :
V_73 = F_32 ( V_29 , V_59 ) ;
break;
#endif
case F_58 ( V_129 ) :
V_73 = F_36 ( V_29 , V_59 ) ;
break;
case F_58 ( V_130 ) :
V_73 = F_40 ( V_29 , V_59 ) ;
break;
case F_58 ( V_131 ) :
V_73 = F_42 ( V_29 , V_59 ) ;
break;
case F_58 ( V_132 ) :
V_73 = F_41 ( V_29 , V_59 ) ;
break;
case F_58 ( V_133 ) :
V_73 = V_47 ( V_29 , V_59 ) ;
break;
case F_58 ( V_134 ) :
V_73 = F_19 ( V_29 , V_59 ) ;
break;
case F_58 ( V_135 ) :
V_73 = F_43 ( V_29 ) ;
break;
case F_58 ( V_136 ) :
V_73 = F_44 ( V_29 ) ;
break;
case F_58 ( V_137 ) :
V_73 = F_45 ( V_29 ) ;
break;
case F_58 ( V_138 ) :
V_73 = F_46 ( V_29 ) ;
break;
case F_58 ( V_139 ) :
V_73 = F_54 ( V_29 ) ;
break;
case F_58 ( V_140 ) :
V_73 = F_56 ( V_29 ) ;
break;
case F_58 ( V_141 ) :
V_73 = F_55 ( V_29 ) ;
break;
}
F_12 ( & V_29 -> V_34 -> V_38 ) ;
return V_73 ;
}
static long F_61 ( struct V_2 * V_2 , unsigned int V_123 ,
unsigned long V_59 )
{
return F_57 ( V_2 , V_123 , ( unsigned long ) F_62 ( V_59 ) ) ;
}
static int F_63 ( struct V_142 * V_34 )
{
int V_13 = - V_20 ;
char V_143 [ 16 ] ;
struct V_4 * V_5 ;
if ( F_25 ( ! V_34 || ! V_34 -> V_144 ) )
return - V_23 ;
V_5 = V_34 -> V_144 ;
F_16 ( L_18 , V_143 , V_5 -> V_145 ,
V_5 -> V_25 ) ;
V_13 = F_64 ( V_22 ,
V_5 -> V_26 , V_5 -> V_34 ,
& V_146 , V_5 , & V_5 -> V_147 ) ;
if ( V_13 < 0 ) {
F_5 ( L_19 , V_13 ) ;
return V_13 ;
}
return V_13 ;
}
static int F_65 ( struct V_142 * V_34 )
{
struct V_4 * V_5 ;
V_5 = V_34 -> V_144 ;
F_66 ( & V_5 -> V_147 ) ;
return 0 ;
}
static void F_67 ( struct V_148 * V_149 ,
struct V_150 * V_45 )
{
struct V_4 * V_5 = (struct V_4 * ) V_149 -> V_33 ;
F_68 ( V_45 , L_20 , V_5 -> V_26 -> V_151 ) ;
F_68 ( V_45 , L_21 , V_5 -> V_34 ) ;
F_68 ( V_45 , L_22 ,
V_5 -> V_25 == V_17
? L_23 : L_24 ) ;
F_68 ( V_45 , L_25 , V_5 -> V_99 ) ;
}
static int F_69 ( struct V_4 * V_5 )
{
struct V_148 * V_149 ;
char V_145 [ 16 ] ;
sprintf ( V_145 , L_26 , V_5 -> V_34 ) ;
V_149 = F_70 ( V_5 -> V_26 , V_145 ,
V_5 -> V_26 -> V_152 ) ;
if ( ! V_149 )
return - V_28 ;
V_149 -> V_153 = V_154 | V_155 | V_156 ;
if ( F_71 ( V_149 ) < 0 ) {
F_72 ( V_149 ) ;
return - V_28 ;
}
V_5 -> V_152 = V_149 ;
V_149 = F_70 ( V_5 -> V_26 , L_27 ,
V_5 -> V_152 ) ;
if ( V_149 ) {
F_73 ( V_149 , V_5 ,
F_67 ) ;
if ( F_71 ( V_149 ) < 0 ) {
F_72 ( V_149 ) ;
V_149 = NULL ;
}
}
V_5 -> V_157 = V_149 ;
return 0 ;
}
static void F_74 ( struct V_4 * V_5 )
{
F_72 ( V_5 -> V_157 ) ;
V_5 -> V_157 = NULL ;
F_72 ( V_5 -> V_152 ) ;
V_5 -> V_152 = NULL ;
}
static inline void F_75 ( struct V_4 * V_5 , const char * V_99 )
{
F_76 ( V_5 -> V_99 , V_99 , sizeof( V_5 -> V_99 ) ) ;
}
static inline int F_69 ( struct V_4 * V_5 )
{
return 0 ;
}
static inline void F_74 ( struct V_4 * V_5 )
{
}
static inline void F_75 ( struct V_4 * V_5 , const char * V_99 )
{
}
static int F_77 ( struct V_142 * V_34 )
{
struct V_4 * V_5 ;
V_5 = V_34 -> V_144 ;
F_74 ( V_5 ) ;
F_78 ( & V_5 -> V_147 ) ;
return 0 ;
}
int F_79 ( struct V_158 * V_26 , int V_34 ,
int V_11 , const char * V_99 , struct V_4 * V_5 )
{
static struct V_159 V_32 = {
. V_160 = F_77 ,
. V_161 = F_63 ,
. V_162 = F_65 ,
} ;
int V_13 ;
V_5 -> V_26 = V_26 ;
V_5 -> V_34 = V_34 ;
V_5 -> V_25 = V_11 ;
F_75 ( V_5 , V_99 ) ;
F_80 ( & V_5 -> V_147 , V_26 ) ;
F_81 ( & V_5 -> V_147 , L_28 , V_26 -> V_151 , V_34 ) ;
V_13 = F_82 ( V_26 , V_163 , V_5 , & V_32 ) ;
if ( V_13 == 0 )
F_69 ( V_5 ) ;
return V_13 ;
}
static int F_83 ( struct V_4 * V_34 )
{
int V_13 ;
if ( ! V_34 -> V_26 )
return - V_20 ;
V_13 = F_84 ( V_34 -> V_26 ) ;
if ( V_13 )
goto V_78;
return 0 ;
V_78:
F_5 ( L_29 , V_13 ) ;
return V_13 ;
}
static int F_85 ( struct V_4 * V_34 )
{
return F_86 ( V_34 -> V_26 ) ;
}
int F_87 ( struct V_4 * V_34 )
{
int V_73 ;
if ( V_34 -> V_145 == NULL || V_34 -> V_32 == NULL )
return - V_20 ;
F_16 ( L_30 , V_34 -> V_145 ) ;
if ( F_25 ( ! V_34 -> V_32 -> V_39 ) )
return - V_20 ;
if ( F_25 ( ! V_34 -> V_32 -> free ) )
return - V_20 ;
if ( F_25 ( ! V_34 -> V_32 -> V_103 ) )
return - V_20 ;
if ( F_25 ( ! V_34 -> V_32 -> V_43 ) )
return - V_20 ;
F_88 ( & V_34 -> V_38 ) ;
F_11 ( & V_164 ) ;
V_73 = F_83 ( V_34 ) ;
F_12 ( & V_164 ) ;
return V_73 ;
}
int F_89 ( struct V_4 * V_34 )
{
F_16 ( L_31 , V_34 -> V_145 ) ;
F_11 ( & V_164 ) ;
F_85 ( V_34 ) ;
F_12 ( & V_164 ) ;
return 0 ;
}
static int T_7 F_90 ( void )
{
return 0 ;
}
static void T_8 F_91 ( void )
{
}
