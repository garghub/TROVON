static void * F_1 ( T_1 V_1 )
{
struct V_2 * V_3 ;
V_3 = F_2 ( V_1 + sizeof( * V_3 ) ) ;
if ( ! V_3 )
return NULL ;
V_3 -> V_4 = F_3 ( V_5 . V_6 ) ;
if ( ! V_3 -> V_4 )
return NULL ;
V_3 -> V_7 = F_2 ( V_5 . V_8 * sizeof( * V_3 -> V_7 ) ) ;
if ( ! V_3 -> V_7 )
return NULL ;
F_4 ( & V_3 -> V_9 . V_10 ) ;
F_4 ( & V_3 -> V_9 . V_11 ) ;
F_4 ( & V_3 -> V_9 . V_12 ) ;
return & V_3 -> V_13 ;
}
static void F_5 ( void * V_13 )
{
struct V_2 * V_3 ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
if ( V_3 -> V_14 ) {
F_7 ( & V_3 -> V_14 -> V_14 ) ;
free ( V_3 -> V_14 ) ;
}
free ( V_3 -> V_4 ) ;
free ( V_3 -> V_7 ) ;
free ( V_3 ) ;
}
static struct V_15 *
F_8 ( struct V_16 * V_13 ,
const char * V_17 ,
int V_18 )
{
struct V_2 * V_3 ;
struct V_15 * V_14 ;
int V_19 ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
if ( V_3 -> V_14 )
return V_3 -> V_14 ;
V_14 = V_3 -> V_14 = F_2 ( sizeof( * V_14 ) ) ;
if ( ! V_14 )
return NULL ;
V_19 = F_9 ( V_14 , V_17 , V_18 ) ;
if ( V_19 ) {
free ( V_14 ) ;
return NULL ;
}
return V_14 ;
}
static void F_10 ( struct V_2 * V_3 ,
struct V_20 * V_21 )
{
if ( F_11 ( V_21 -> V_22 == ( unsigned int ) - 1 ,
L_1 ) )
return;
F_12 ( V_21 -> V_22 , V_3 -> V_4 ) ;
}
static void F_13 ( struct V_2 * V_3 ,
struct V_23 * V_24 ,
T_2 V_25 )
{
struct F_13 * V_9 = & V_3 -> V_9 ;
if ( V_24 -> V_11 )
F_14 ( & V_9 -> V_11 , V_25 ) ;
else if ( V_24 -> V_10 )
F_14 ( & V_9 -> V_10 , V_25 ) ;
else if ( V_24 -> V_12 )
F_14 ( & V_9 -> V_12 , V_25 ) ;
}
static int F_15 ( struct V_26 * T_3 V_27 ,
union V_28 * V_29 ,
struct V_20 * V_21 ,
struct V_30 * V_31 ,
struct V_32 * V_32 )
{
struct V_15 * V_15 = & V_5 . V_14 ;
struct V_2 * V_3 ;
struct V_23 V_24 = { . V_33 = 0 , } ;
struct V_16 * V_13 ;
struct V_34 V_35 ;
struct V_36 * V_37 , * V_38 ;
int V_19 ;
if ( F_16 ( V_32 , & V_35 , V_21 ) < 0 ) {
F_17 ( L_2 ,
V_29 -> V_39 . type ) ;
return - 1 ;
}
V_19 = F_18 ( V_21 , & V_40 , NULL ,
V_31 , & V_35 , V_41 ) ;
if ( V_19 )
goto V_42;
V_37 = F_19 ( V_21 , & V_35 ) ;
if ( V_37 == NULL )
return - V_43 ;
V_38 = F_20 ( V_37 , sizeof( * V_37 ) ) ;
if ( ! V_38 )
goto V_44;
F_21 ( & V_24 , V_37 ) ;
V_13 = F_22 ( & V_15 -> V_14 , & V_45 ,
& V_35 , NULL , NULL , V_37 ,
V_21 , true ) ;
if ( V_13 == NULL )
goto V_46;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
F_23 ( & V_3 -> V_24 , & V_24 ) ;
F_23 ( & V_15 -> V_24 , & V_24 ) ;
F_10 ( V_3 , V_21 ) ;
F_24 ( & V_15 -> V_14 , V_13 -> V_47 ) ;
V_19 = F_25 ( V_13 , V_21 ) ;
if ( ! V_19 ) {
int V_22 = V_21 -> V_22 == ( unsigned int ) - 1 ? 0 : V_21 -> V_22 ;
int V_48 = V_5 . V_49 [ V_22 ] ;
V_37 = V_38 ;
V_38 = F_20 ( V_37 , sizeof( * V_37 ) ) ;
if ( ! V_38 )
goto V_44;
V_15 = F_8 ( V_13 , V_5 . V_50 , 2 ) ;
if ( ! V_15 )
goto V_46;
V_13 = F_22 ( & V_15 -> V_14 , & V_45 ,
& V_35 , NULL , NULL , V_37 ,
V_21 , true ) ;
if ( V_13 == NULL )
goto V_46;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
F_23 ( & V_3 -> V_24 , & V_24 ) ;
F_23 ( & V_15 -> V_24 , & V_24 ) ;
F_23 ( & V_3 -> V_7 [ V_48 ] , & V_24 ) ;
F_13 ( V_3 , & V_24 , V_21 -> V_25 ) ;
F_10 ( V_3 , V_21 ) ;
F_24 ( & V_15 -> V_14 , V_13 -> V_47 ) ;
V_19 = F_25 ( V_13 , V_21 ) ;
}
V_42:
F_26 ( & V_35 ) ;
return V_19 ;
V_46:
free ( V_38 ) ;
V_44:
free ( V_37 ) ;
V_19 = - V_43 ;
goto V_42;
}
static int F_27 ( struct V_14 * V_14 , struct V_51 * V_52 )
{
int V_53 = F_28 ( V_14 , V_52 -> V_54 ) ;
if ( ! V_5 . V_55 )
V_53 = F_29 ( V_53 , V_56 ) ;
return V_53 ;
}
static int F_30 ( struct V_57 * V_58 ,
struct V_59 * T_4 V_27 ,
struct V_14 * V_14 )
{
struct V_60 * V_60 ;
struct V_61 * V_62 ;
V_60 = F_6 ( V_58 , struct V_60 , V_58 ) ;
V_62 = V_60 -> V_62 ;
if ( V_62 == & V_63 || V_62 == & V_64 )
return F_27 ( V_14 , V_62 -> V_52 ) ;
return V_62 -> V_52 ? F_28 ( V_14 , V_62 -> V_52 -> V_54 ) :
V_60 -> V_62 -> V_53 ;
}
static int F_31 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_14 * V_14 , int line , int * V_65 )
{
struct V_66 * V_67 = V_14 -> V_67 ;
struct V_60 * V_60 ;
struct V_61 * V_62 ;
const char * V_68 = NULL ;
int V_53 = F_30 ( V_58 , T_4 , V_14 ) ;
V_60 = F_6 ( V_58 , struct V_60 , V_58 ) ;
V_62 = V_60 -> V_62 ;
if ( V_62 -> V_52 ) {
V_68 = V_62 -> V_39 . line [ line ] . V_68 ;
if ( ! V_68 && ( line == V_67 -> V_18 - 1 ) )
V_68 = V_62 -> V_52 -> V_69 ;
} else {
V_68 = V_62 -> V_39 . line [ line ] . V_68 ;
if ( * V_65 ) {
( * V_65 ) -- ;
return 0 ;
} else {
* V_65 = V_62 -> V_39 . line [ line ] . V_65 ;
}
}
if ( V_68 == NULL )
V_68 = L_3 ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_4 , V_53 , V_68 ) ;
}
static T_5
F_33 ( struct V_57 * V_58 V_27 ,
struct V_16 * V_71 , struct V_16 * V_72 )
{
return F_34 ( V_71 , V_72 ) ;
}
static int F_35 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
T_6 V_73 = 0 ;
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
char V_70 [ 20 ] ;
if ( V_13 -> V_36 )
V_73 = F_36 ( V_13 -> V_36 -> V_74 . V_73 ) ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_4 , V_53 , F_37 ( V_70 , V_73 ) ) ;
}
static int F_38 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
T_6 V_73 = 0 ;
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
char V_70 [ 20 ] ;
if ( V_13 -> V_36 )
V_73 = F_39 ( V_13 -> V_36 -> V_74 . V_75 ) ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_4 , V_53 , F_37 ( V_70 , V_73 ) ) ;
}
static T_5
F_40 ( struct V_57 * V_58 V_27 ,
struct V_16 * V_71 , struct V_16 * V_72 )
{
T_6 V_76 = 0 , V_77 = 0 ;
if ( V_71 -> V_36 )
V_76 = F_39 ( V_71 -> V_36 -> V_74 . V_73 ) ;
if ( V_72 -> V_36 )
V_77 = F_39 ( V_72 -> V_36 -> V_74 . V_73 ) ;
return ( T_5 ) ( V_77 - V_76 ) ;
}
static int
F_41 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
T_6 V_73 = 0 ;
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
char V_70 [ 20 ] ;
if ( V_13 -> V_36 )
V_73 = V_13 -> V_36 -> V_78 . V_73 ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_4 , V_53 , F_37 ( V_70 , V_73 ) ) ;
}
static T_5
F_42 ( struct V_57 * V_58 V_27 ,
struct V_16 * V_71 , struct V_16 * V_72 )
{
return F_43 ( V_71 , V_72 ) ;
}
static int
F_44 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
struct V_2 * V_3 ;
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
unsigned int V_79 ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
V_79 = V_3 -> V_24 . V_10 + V_3 -> V_24 . V_11 ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_5 , V_53 , V_79 ) ;
}
static T_5
F_45 ( struct V_57 * V_58 V_27 ,
struct V_16 * V_71 , struct V_16 * V_72 )
{
struct V_2 * V_80 ;
struct V_2 * V_81 ;
unsigned int V_82 ;
unsigned int V_83 ;
V_80 = F_6 ( V_71 , struct V_2 , V_13 ) ;
V_81 = F_6 ( V_72 , struct V_2 , V_13 ) ;
V_82 = V_80 -> V_24 . V_10 + V_80 -> V_24 . V_11 ;
V_83 = V_81 -> V_24 . V_10 + V_81 -> V_24 . V_11 ;
return V_82 - V_83 ;
}
static T_6 F_46 ( struct V_23 * V_24 )
{
T_6 V_84 ;
V_84 = V_24 -> V_85 +
V_24 -> V_86 +
V_24 -> V_11 +
V_24 -> V_87 ;
return V_84 ;
}
static int
F_47 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
struct V_2 * V_3 ;
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_6 , V_53 ,
F_46 ( & V_3 -> V_24 ) ) ;
}
static T_5
F_48 ( struct V_57 * V_58 V_27 ,
struct V_16 * V_71 , struct V_16 * V_72 )
{
struct V_2 * V_80 ;
struct V_2 * V_81 ;
V_80 = F_6 ( V_71 , struct V_2 , V_13 ) ;
V_81 = F_6 ( V_72 , struct V_2 , V_13 ) ;
return F_46 ( & V_80 -> V_24 ) - F_46 ( & V_81 -> V_24 ) ;
}
static T_6 F_49 ( struct V_23 * V_24 )
{
T_6 V_88 , V_89 , V_90 ;
V_88 = V_24 -> V_85 +
V_24 -> V_86 +
V_24 -> V_11 +
V_24 -> V_87 ;
V_89 = V_88 +
V_24 -> V_91 +
V_24 -> V_92 +
V_24 -> V_93 +
V_24 -> V_94 +
V_24 -> V_10 ;
V_90 = V_89 +
V_24 -> V_95 +
V_24 -> V_96 ;
return V_90 ;
}
static int
F_50 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
struct V_2 * V_3 ;
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
T_6 V_97 ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
V_97 = F_49 ( & V_3 -> V_24 ) ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_7 V_98 , V_53 , V_97 ) ;
}
static T_5
F_51 ( struct V_57 * V_58 V_27 ,
struct V_16 * V_71 , struct V_16 * V_72 )
{
struct V_2 * V_80 ;
struct V_2 * V_81 ;
T_6 V_99 ;
T_6 V_100 ;
V_80 = F_6 ( V_71 , struct V_2 , V_13 ) ;
V_81 = F_6 ( V_72 , struct V_2 , V_13 ) ;
V_99 = F_49 ( & V_80 -> V_24 ) ;
V_100 = F_49 ( & V_81 -> V_24 ) ;
return V_99 - V_100 ;
}
static T_6 F_52 ( struct V_23 * V_24 )
{
T_6 V_88 , V_89 ;
V_88 = V_24 -> V_85 +
V_24 -> V_86 +
V_24 -> V_11 +
V_24 -> V_87 ;
V_89 = V_88 +
V_24 -> V_91 +
V_24 -> V_92 +
V_24 -> V_93 +
V_24 -> V_94 +
V_24 -> V_10 ;
return V_89 ;
}
static int
F_53 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
struct V_2 * V_3 ;
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
T_6 V_97 ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
V_97 = F_52 ( & V_3 -> V_24 ) ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_7 V_98 , V_53 , V_97 ) ;
}
static T_5
F_54 ( struct V_57 * V_58 V_27 ,
struct V_16 * V_71 , struct V_16 * V_72 )
{
struct V_2 * V_80 ;
struct V_2 * V_81 ;
T_6 V_99 ;
T_6 V_100 ;
V_80 = F_6 ( V_71 , struct V_2 , V_13 ) ;
V_81 = F_6 ( V_72 , struct V_2 , V_13 ) ;
V_99 = F_52 ( & V_80 -> V_24 ) ;
V_100 = F_52 ( & V_81 -> V_24 ) ;
return V_99 - V_100 ;
}
static int
F_55 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 , T_7 V_101 )
{
struct V_2 * V_3 ;
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
double V_102 ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
V_102 = V_101 ( V_3 ) ;
#ifdef F_56
if ( V_103 )
return F_57 ( T_4 , L_8 , V_53 - 1 , V_102 ) ;
#endif
return F_58 ( T_4 , L_8 , V_53 - 1 , V_102 ) ;
}
static double F_59 ( struct V_2 * V_3 )
{
struct V_15 * V_14 ;
struct V_23 * V_24 ;
struct V_23 * V_90 ;
int V_104 = 0 , V_105 = 0 ;
double V_106 ;
V_14 = F_6 ( V_3 -> V_13 . V_14 , struct V_15 , V_14 ) ;
V_24 = & V_3 -> V_24 ;
V_90 = & V_14 -> V_24 ;
switch ( V_5 . V_107 ) {
case V_108 :
V_105 = V_24 -> V_11 ;
V_104 = V_90 -> V_11 ;
break;
case V_109 :
V_105 = V_24 -> V_10 ;
V_104 = V_90 -> V_10 ;
break;
case V_110 :
V_105 = V_24 -> V_79 ;
V_104 = V_90 -> V_79 ;
default:
break;
}
V_106 = V_104 ? ( double ) V_105 / V_104 : 0 ;
return 100 * V_106 ;
}
static int
F_60 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
struct V_2 * V_3 ;
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
char V_70 [ 10 ] ;
double V_102 ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
V_102 = F_59 ( V_3 ) ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_4 , V_53 , F_61 ( V_70 , V_102 ) ) ;
}
static int
F_62 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
return F_55 ( V_58 , T_4 , V_13 , F_59 ) ;
}
static T_5
F_63 ( struct V_57 * V_58 V_27 ,
struct V_16 * V_71 , struct V_16 * V_72 )
{
struct V_2 * V_80 ;
struct V_2 * V_81 ;
double V_111 ;
double V_112 ;
V_80 = F_6 ( V_71 , struct V_2 , V_13 ) ;
V_81 = F_6 ( V_72 , struct V_2 , V_13 ) ;
V_111 = F_59 ( V_80 ) ;
V_112 = F_59 ( V_81 ) ;
return V_111 - V_112 ;
}
static struct V_23 * F_64 ( struct V_16 * V_13 )
{
struct V_2 * V_3 ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
return & V_3 -> V_24 ;
}
static struct V_23 * F_65 ( struct V_16 * V_13 )
{
struct V_15 * V_14 ;
V_14 = F_6 ( V_13 -> V_14 , struct V_15 , V_14 ) ;
return & V_14 -> V_24 ;
}
static double F_66 ( int V_105 , int V_104 )
{
return V_104 ? 100. * ( double ) V_105 / ( double ) V_104 : 0 ;
}
static int
F_67 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
double V_102 = F_68 ( V_13 , V_11 ) ;
char V_70 [ 10 ] ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_4 , V_53 , F_61 ( V_70 , V_102 ) ) ;
}
static int
F_69 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
return F_55 ( V_58 , T_4 , V_13 , V_113 ) ;
}
static T_5
F_70 ( struct V_57 * V_58 V_27 ,
struct V_16 * V_71 , struct V_16 * V_72 )
{
double V_111 ;
double V_112 ;
V_111 = F_68 ( V_71 , V_10 ) ;
V_112 = F_68 ( V_72 , V_10 ) ;
return V_111 - V_112 ;
}
static int
F_71 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
double V_102 = F_68 ( V_13 , V_10 ) ;
char V_70 [ 10 ] ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_4 , V_53 , F_61 ( V_70 , V_102 ) ) ;
}
static int
F_72 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
return F_55 ( V_58 , T_4 , V_13 , V_114 ) ;
}
static T_5
F_73 ( struct V_57 * V_58 V_27 ,
struct V_16 * V_71 , struct V_16 * V_72 )
{
double V_111 ;
double V_112 ;
V_111 = F_68 ( V_71 , V_10 ) ;
V_112 = F_68 ( V_72 , V_10 ) ;
return V_111 - V_112 ;
}
static int
F_74 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
double V_102 = F_68 ( V_13 , V_95 ) ;
char V_70 [ 10 ] ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_4 , V_53 , F_61 ( V_70 , V_102 ) ) ;
}
static int
F_75 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
return F_55 ( V_58 , T_4 , V_13 , V_115 ) ;
}
static T_5
F_76 ( struct V_57 * V_58 V_27 ,
struct V_16 * V_71 , struct V_16 * V_72 )
{
double V_111 ;
double V_112 ;
V_111 = F_68 ( V_71 , V_95 ) ;
V_112 = F_68 ( V_72 , V_95 ) ;
return V_111 - V_112 ;
}
static int
F_77 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
double V_102 = F_68 ( V_13 , V_96 ) ;
char V_70 [ 10 ] ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_4 , V_53 , F_61 ( V_70 , V_102 ) ) ;
}
static int
F_78 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
return F_55 ( V_58 , T_4 , V_13 , V_116 ) ;
}
static T_5
F_79 ( struct V_57 * V_58 V_27 ,
struct V_16 * V_71 , struct V_16 * V_72 )
{
double V_111 ;
double V_112 ;
V_111 = F_68 ( V_71 , V_96 ) ;
V_112 = F_68 ( V_72 , V_96 ) ;
return V_111 - V_112 ;
}
static int
F_80 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_9 , V_53 , V_13 -> V_117 -> V_118 ) ;
}
static T_5
F_81 ( struct V_57 * V_58 V_27 ,
struct V_16 * V_71 , struct V_16 * V_72 )
{
return V_71 -> V_117 -> V_118 - V_72 -> V_117 -> V_118 ;
}
static T_5
F_82 ( struct V_57 * V_58 V_27 ,
struct V_16 * V_71 V_27 ,
struct V_16 * V_72 V_27 )
{
return 0 ;
}
static int
F_83 ( struct V_57 * V_58 V_27 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
struct V_2 * V_3 ;
bool V_119 = true ;
int V_48 ;
int V_19 = 0 ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
for ( V_48 = 0 ; V_48 < V_5 . V_8 ; V_48 ++ ) {
F_84 ( V_120 , V_5 . V_6 ) ;
F_85 ( V_120 , V_5 . V_6 ) ;
F_86 ( V_120 , V_3 -> V_4 , V_5 . V_121 [ V_48 ] , V_5 . V_6 ) ;
if ( ! F_87 ( V_120 , V_5 . V_6 ) ) {
if ( V_5 . V_122 == 1 ) {
V_19 = F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_10 , L_11 ) ;
F_88 ( T_4 , V_19 ) ;
}
continue;
}
if ( ! V_119 ) {
V_19 = F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_11 ) ;
F_88 ( T_4 , V_19 ) ;
}
switch ( V_5 . V_122 ) {
case 0 :
V_19 = F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_12 , V_48 ) ;
F_88 ( T_4 , V_19 ) ;
break;
case 1 :
{
int V_123 = F_87 ( V_3 -> V_4 , V_5 . V_6 ) ;
struct V_23 * V_24 = & V_3 -> V_7 [ V_48 ] ;
V_19 = F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_13 , V_48 , V_123 ) ;
F_88 ( T_4 , V_19 ) ;
#define F_89 ( T_8 ) \
if (c2c_he->stats.__h> 0) { \
ret = scnprintf(hpp->buf, hpp->size, "%5.1f%% ", \
percent(stats->__h, c2c_he->stats.__h));\
} else { \
ret = scnprintf(hpp->buf, hpp->size, "%6s ", "n/a"); \
}
switch ( V_5 . V_107 ) {
case V_108 :
F_89 ( V_11 ) ;
break;
case V_109 :
F_89 ( V_10 ) ;
break;
case V_110 :
F_89 ( V_79 ) ;
default:
break;
}
#undef F_89
F_88 ( T_4 , V_19 ) ;
if ( V_3 -> V_24 . V_124 > 0 ) {
V_19 = F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_14 ,
F_66 ( V_24 -> V_124 , V_3 -> V_24 . V_124 ) ) ;
} else {
V_19 = F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_15 , L_16 ) ;
}
F_88 ( T_4 , V_19 ) ;
break;
}
case 2 :
V_19 = F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_17 , V_48 ) ;
F_88 ( T_4 , V_19 ) ;
V_19 = F_90 ( V_120 , V_5 . V_6 , T_4 -> V_70 , T_4 -> V_1 ) ;
F_88 ( T_4 , V_19 ) ;
V_19 = F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_18 ) ;
F_88 ( T_4 , V_19 ) ;
break;
default:
break;
}
V_119 = false ;
}
return 0 ;
}
static int
F_91 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 , double V_125 )
{
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
char V_70 [ 10 ] ;
F_32 ( V_70 , 10 , L_19 , V_125 ) ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_4 , V_53 , V_70 ) ;
}
static int
F_92 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
struct V_2 * V_3 ;
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
char V_70 [ 10 ] ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
F_32 ( V_70 , 10 , L_20 , F_87 ( V_3 -> V_4 , V_5 . V_6 ) ) ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_4 , V_53 , V_70 ) ;
}
static int
F_93 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
struct V_2 * V_3 ;
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
char V_70 [ 10 ] ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
F_32 ( V_70 , 10 , L_21 , V_3 -> V_126 ) ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_4 , V_53 , V_70 ) ;
}
static int
F_94 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
int V_53 = F_30 ( V_58 , T_4 , V_13 -> V_14 ) ;
return F_32 ( T_4 -> V_70 , T_4 -> V_1 , L_4 , V_53 , L_3 ) ;
}
static void F_95 ( struct V_57 * V_58 )
{
struct V_60 * V_60 ;
V_60 = F_6 ( V_58 , struct V_60 , V_58 ) ;
free ( V_60 ) ;
}
static bool F_96 ( struct V_57 * V_127 , struct V_57 * V_128 )
{
struct V_60 * V_129 = F_6 ( V_127 , struct V_60 , V_58 ) ;
struct V_60 * V_130 = F_6 ( V_128 , struct V_60 , V_58 ) ;
return V_129 -> V_62 == V_130 -> V_62 ;
}
static struct V_61 * F_97 ( const char * V_131 )
{
unsigned int V_132 ;
for ( V_132 = 0 ; V_133 [ V_132 ] ; V_132 ++ ) {
struct V_61 * V_62 = V_133 [ V_132 ] ;
if ( ! strcmp ( V_62 -> V_131 , V_131 ) )
return V_62 ;
} ;
return NULL ;
}
static int F_98 ( struct V_57 * V_58 , struct V_59 * T_4 ,
struct V_16 * V_13 )
{
struct V_60 * V_60 = F_6 ( V_58 , struct V_60 , V_58 ) ;
struct V_61 * V_62 = V_60 -> V_62 ;
T_1 V_134 = V_58 -> V_135 ;
if ( ! V_134 ) {
V_134 = F_28 ( V_13 -> V_14 , V_62 -> V_52 -> V_54 ) ;
if ( V_62 == & V_63 || V_62 == & V_64 )
V_134 = F_27 ( V_13 -> V_14 , V_62 -> V_52 ) ;
}
return V_62 -> V_52 -> V_136 ( V_13 , T_4 -> V_70 , T_4 -> V_1 , V_134 ) ;
}
static T_5 F_99 ( struct V_57 * V_58 ,
struct V_16 * V_127 , struct V_16 * V_128 )
{
struct V_60 * V_60 = F_6 ( V_58 , struct V_60 , V_58 ) ;
struct V_61 * V_62 = V_60 -> V_62 ;
return V_62 -> V_52 -> V_137 ( V_127 , V_128 ) ;
}
static T_5 F_100 ( struct V_57 * V_58 ,
struct V_16 * V_127 , struct V_16 * V_128 )
{
struct V_60 * V_60 = F_6 ( V_58 , struct V_60 , V_58 ) ;
struct V_61 * V_62 = V_60 -> V_62 ;
T_5 (* F_101)( struct V_16 * , struct V_16 * );
F_101 = V_62 -> V_52 -> V_138 ? : V_62 -> V_52 -> V_137 ;
return F_101 ( V_127 , V_128 ) ;
}
static struct V_60 * F_102 ( const char * V_131 )
{
struct V_61 * V_62 = F_97 ( V_131 ) ;
struct V_60 * V_60 ;
struct V_57 * V_58 ;
if ( ! V_62 )
return NULL ;
V_60 = F_2 ( sizeof( * V_60 ) ) ;
if ( ! V_60 )
return NULL ;
V_60 -> V_62 = V_62 ;
V_58 = & V_60 -> V_58 ;
F_103 ( & V_58 -> V_139 ) ;
F_103 ( & V_58 -> V_140 ) ;
V_58 -> V_141 = V_62 -> V_52 ? F_99 : V_62 -> V_141 ;
V_58 -> V_17 = V_62 -> V_52 ? F_99 : V_62 -> V_141 ;
V_58 -> V_142 = V_62 -> V_52 ? NULL : V_62 -> V_142 ;
V_58 -> V_143 = V_62 -> V_52 ? F_98 : V_62 -> V_143 ;
V_58 -> V_39 = F_31 ;
V_58 -> V_53 = F_30 ;
V_58 -> V_144 = V_62 -> V_52 ? F_100 : V_62 -> V_141 ;
V_58 -> V_145 = F_96 ;
V_58 -> free = F_95 ;
return V_60 ;
}
static int F_104 ( struct V_66 * V_67 , char * V_131 )
{
struct V_60 * V_60 = F_102 ( V_131 ) ;
if ( ! V_60 ) {
F_105 () ;
return F_106 ( V_67 , V_131 ) ;
}
F_107 ( V_67 , & V_60 -> V_58 ) ;
return 0 ;
}
static int F_108 ( struct V_66 * V_67 , char * V_131 )
{
struct V_60 * V_60 = F_102 ( V_131 ) ;
struct V_61 * V_62 ;
if ( ! V_60 ) {
F_105 () ;
return F_109 ( V_67 , V_131 , NULL , 0 ) ;
}
V_62 = V_60 -> V_62 ;
if ( V_62 == & V_146 )
V_67 -> V_147 = 1 ;
F_110 ( V_67 , & V_60 -> V_58 ) ;
return 0 ;
}
static int F_111 ( struct V_66 * V_67 ,
const char * V_148 ,
const char * V_149 )
{
char * V_150 = V_148 ? F_112 ( V_148 ) : NULL ;
char * V_17 = V_149 ? F_112 ( V_149 ) : NULL ;
int V_19 ;
F_113 ( V_150 , F_104 ) ;
F_113 ( V_17 , F_108 ) ;
F_114 ( V_67 ) ;
#if 0
perf_hpp__append_sort_keys(&hists->list);
#endif
free ( V_150 ) ;
free ( V_17 ) ;
return V_19 ;
}
static int F_9 ( struct V_15 * V_14 ,
const char * V_17 ,
int V_18 )
{
F_115 ( & V_14 -> V_14 , & V_14 -> V_139 ) ;
F_116 ( & V_14 -> V_139 ) ;
V_14 -> V_139 . V_18 = V_18 ;
return F_111 ( & V_14 -> V_139 , NULL , V_17 ) ;
}
static int F_117 ( struct V_15 * V_15 ,
const char * V_150 ,
const char * V_17 )
{
F_118 ( & V_15 -> V_139 ) ;
return F_111 ( & V_15 -> V_139 , V_150 , V_17 ) ;
}
static bool F_119 ( struct V_16 * V_13 , struct V_23 * V_24 )
{
struct V_2 * V_3 ;
double V_151 ;
if ( V_5 . V_152 )
return true ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
#define F_120 ( T_8 ) \
if (stats->__h) { \
ld_dist = ((double)c2c_he->stats.__h / stats->__h); \
if (ld_dist < DISPLAY_LINE_LIMIT) \
he->filtered = HIST_FILTER__C2C; \
} else { \
he->filtered = HIST_FILTER__C2C; \
}
switch ( V_5 . V_107 ) {
case V_109 :
F_120 ( V_10 ) ;
break;
case V_108 :
F_120 ( V_11 ) ;
break;
case V_110 :
F_120 ( V_79 ) ;
default:
break;
} ;
#undef F_120
return V_13 -> V_47 == 0 ;
}
static inline int F_121 ( struct V_16 * V_13 )
{
struct V_2 * V_3 ;
bool V_153 ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
V_153 = V_5 . V_107 == V_110 ? V_3 -> V_24 . V_79 :
V_5 . V_107 == V_109 ? V_3 -> V_24 . V_10 :
V_3 -> V_24 . V_11 ;
return V_153 || V_3 -> V_24 . V_124 ;
}
static void F_122 ( struct V_16 * V_13 )
{
struct V_15 * V_15 ;
V_15 = F_6 ( V_13 -> V_14 , struct V_15 , V_14 ) ;
F_123 ( & V_15 -> V_14 , V_13 ) ;
}
static int F_124 ( struct V_16 * V_13 )
{
if ( V_5 . V_154 && ! V_13 -> V_155 )
V_13 -> V_155 = F_125 ( V_13 ) ;
F_122 ( V_13 ) ;
if ( ! F_121 ( V_13 ) )
V_13 -> V_47 = V_156 ;
return 0 ;
}
static int F_126 ( struct V_16 * V_13 )
{
struct V_2 * V_3 ;
struct V_15 * V_15 ;
bool V_107 = F_119 ( V_13 , & V_5 . V_157 ) ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
V_15 = V_3 -> V_14 ;
F_122 ( V_13 ) ;
if ( V_107 && V_15 ) {
static unsigned int V_158 ;
V_3 -> V_126 = V_158 ++ ;
F_117 ( V_15 , V_5 . V_159 , V_5 . V_160 ) ;
F_127 ( & V_15 -> V_14 , NULL ) ;
F_128 ( & V_15 -> V_14 , NULL , F_124 ) ;
}
return 0 ;
}
static void F_129 ( void )
{
V_161 . V_39 = V_162 [ V_5 . V_122 ] ;
}
static int F_130 ( struct V_163 * V_164 )
{
struct V_165 * V_166 ;
unsigned long * * V_121 ;
int V_48 , V_22 ;
int * V_49 ;
if ( V_5 . V_122 > 2 )
V_5 . V_122 = 2 ;
V_5 . V_8 = V_164 -> V_39 . V_167 . V_168 ;
V_5 . V_6 = V_164 -> V_39 . V_167 . V_169 ;
V_166 = V_164 -> V_39 . V_167 . V_170 ;
if ( ! V_166 )
return - V_171 ;
V_121 = F_2 ( sizeof( unsigned long * ) * V_5 . V_8 ) ;
if ( ! V_121 )
return - V_43 ;
V_5 . V_121 = V_121 ;
V_49 = F_2 ( sizeof( int ) * V_5 . V_6 ) ;
if ( ! V_49 )
return - V_43 ;
for ( V_22 = 0 ; V_22 < V_5 . V_6 ; V_22 ++ )
V_49 [ V_22 ] = - 1 ;
V_5 . V_49 = V_49 ;
for ( V_48 = 0 ; V_48 < V_5 . V_8 ; V_48 ++ ) {
struct V_172 * V_173 = V_166 [ V_48 ] . V_173 ;
unsigned long * V_120 ;
V_120 = F_3 ( V_5 . V_6 ) ;
if ( ! V_120 )
return - V_43 ;
for ( V_22 = 0 ; V_22 < V_173 -> V_174 ; V_22 ++ ) {
F_12 ( V_173 -> V_173 [ V_22 ] , V_120 ) ;
if ( F_11 ( V_49 [ V_173 -> V_173 [ V_22 ] ] != - 1 , L_22 ) )
return - V_171 ;
V_49 [ V_173 -> V_173 [ V_22 ] ] = V_48 ;
}
V_121 [ V_48 ] = V_120 ;
}
F_129 () ;
return 0 ;
}
static int F_131 ( struct V_16 * V_13 )
{
struct V_2 * V_3 ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
if ( F_132 ( V_3 ) ) {
V_5 . V_175 ++ ;
F_23 ( & V_5 . V_157 , & V_3 -> V_24 ) ;
}
return 0 ;
}
static int F_133 ( struct V_14 * V_14 , T_9 V_176 )
{
struct V_177 * V_178 = F_134 ( & V_14 -> V_179 ) ;
int V_19 = 0 ;
while ( V_178 ) {
struct V_16 * V_13 ;
V_13 = F_135 ( V_178 , struct V_16 , V_177 ) ;
V_19 = V_176 ( V_13 ) ;
if ( V_19 )
break;
V_178 = F_136 ( & V_13 -> V_177 ) ;
}
return V_19 ;
}
static void F_137 ( T_10 * V_42 )
{
int V_180 ;
struct V_23 * V_24 = & V_5 . V_14 . V_24 ;
V_180 = V_24 -> V_85 +
V_24 -> V_86 +
V_24 -> V_87 +
V_24 -> V_11 ;
fprintf ( V_42 , L_23 ) ;
fprintf ( V_42 , L_24 ) ;
fprintf ( V_42 , L_23 ) ;
fprintf ( V_42 , L_25 , V_24 -> V_33 ) ;
fprintf ( V_42 , L_26 , V_24 -> V_181 ) ;
fprintf ( V_42 , L_27 , V_24 -> V_12 ) ;
fprintf ( V_42 , L_28 , V_24 -> V_182 ) ;
fprintf ( V_42 , L_29 , V_24 -> V_183 ) ;
fprintf ( V_42 , L_30 , V_24 -> V_184 ) ;
fprintf ( V_42 , L_31 , V_24 -> V_185 ) ;
fprintf ( V_42 , L_32 , V_24 -> V_91 ) ;
fprintf ( V_42 , L_33 , V_24 -> V_92 ) ;
fprintf ( V_42 , L_34 , V_24 -> V_93 ) ;
fprintf ( V_42 , L_35 , V_24 -> V_94 + V_24 -> V_10 ) ;
fprintf ( V_42 , L_36 , V_24 -> V_10 ) ;
fprintf ( V_42 , L_37 , V_24 -> V_11 ) ;
fprintf ( V_42 , L_38 , V_24 -> V_87 ) ;
fprintf ( V_42 , L_39 , V_24 -> V_85 ) ;
fprintf ( V_42 , L_40 , V_24 -> V_86 ) ;
fprintf ( V_42 , L_41 , V_24 -> V_186 ) ;
fprintf ( V_42 , L_42 , V_24 -> V_187 ) ;
fprintf ( V_42 , L_43 , V_180 ) ;
fprintf ( V_42 , L_44 , ( ( double ) V_24 -> V_85 / ( double ) V_180 ) * 100. ) ;
fprintf ( V_42 , L_45 , ( ( double ) V_24 -> V_86 / ( double ) V_180 ) * 100. ) ;
fprintf ( V_42 , L_46 , ( ( double ) V_24 -> V_87 / ( double ) V_180 ) * 100. ) ;
fprintf ( V_42 , L_47 , ( ( double ) V_24 -> V_11 / ( double ) V_180 ) * 100. ) ;
fprintf ( V_42 , L_48 , V_24 -> V_124 ) ;
fprintf ( V_42 , L_49 , V_24 -> V_188 ) ;
fprintf ( V_42 , L_50 , V_24 -> V_189 ) ;
fprintf ( V_42 , L_51 , V_24 -> V_95 ) ;
fprintf ( V_42 , L_52 , V_24 -> V_96 ) ;
fprintf ( V_42 , L_53 , V_24 -> V_190 ) ;
fprintf ( V_42 , L_54 , V_24 -> V_191 ) ;
}
static void F_138 ( T_10 * V_42 )
{
struct V_23 * V_24 = & V_5 . V_157 ;
int V_192 = V_24 -> V_10 + V_24 -> V_11 ;
fprintf ( V_42 , L_23 ) ;
fprintf ( V_42 , L_55 ) ;
fprintf ( V_42 , L_23 ) ;
fprintf ( V_42 , L_56 , V_5 . V_175 ) ;
fprintf ( V_42 , L_57 , V_24 -> V_12 ) ;
fprintf ( V_42 , L_58 , V_24 -> V_91 ) ;
fprintf ( V_42 , L_59 , V_24 -> V_92 ) ;
fprintf ( V_42 , L_60 , V_24 -> V_93 ) ;
fprintf ( V_42 , L_61 , V_24 -> V_94 + V_24 -> V_10 ) ;
fprintf ( V_42 , L_62 , V_24 -> V_181 ) ;
fprintf ( V_42 , L_63 , V_24 -> V_124 ) ;
fprintf ( V_42 , L_64 , V_24 -> V_95 ) ;
fprintf ( V_42 , L_65 , V_192 + V_24 -> V_124 ) ;
}
static void F_139 ( struct V_15 * V_15 ,
struct V_16 * V_193 ,
struct V_66 * V_67 ,
T_10 * V_42 )
{
char V_194 [ 1000 ] ;
struct V_59 T_4 = {
. V_70 = V_194 ,
. V_1 = 1000 ,
} ;
static bool V_195 ;
if ( ! V_195 ) {
F_140 ( & V_15 -> V_14 , V_42 ) ;
V_195 = true ;
} else {
fprintf ( V_42 , L_66 ) ;
}
fprintf ( V_42 , L_67 ) ;
F_141 ( V_193 , & T_4 , V_67 ) ;
fprintf ( V_42 , L_68 , V_194 ) ;
fprintf ( V_42 , L_67 ) ;
F_142 ( & V_15 -> V_14 , false , 0 , 0 , 0 , V_42 , true ) ;
}
static void F_143 ( T_10 * V_42 )
{
struct V_66 V_67 ;
struct V_177 * V_196 ;
int V_19 ;
F_116 ( & V_67 ) ;
V_19 = F_111 ( & V_67 ,
L_69
L_70
L_71
L_72
L_73
L_74 ,
NULL ) ;
if ( F_11 ( V_19 , L_75 ) )
return;
V_196 = F_134 ( & V_5 . V_14 . V_14 . V_179 ) ;
for (; V_196 ; V_196 = F_136 ( V_196 ) ) {
struct V_16 * V_13 = F_135 ( V_196 , struct V_16 , V_177 ) ;
struct V_2 * V_3 ;
if ( V_13 -> V_47 )
continue;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
F_139 ( V_3 -> V_14 , V_13 , & V_67 , V_42 ) ;
}
}
static void F_144 ( T_10 * V_42 , struct V_163 * V_164 )
{
struct V_197 * V_198 = V_164 -> V_198 ;
struct V_30 * V_31 ;
bool V_119 = true ;
fprintf ( V_42 , L_23 ) ;
fprintf ( V_42 , L_76 ) ;
fprintf ( V_42 , L_23 ) ;
F_145 (evlist, evsel) {
fprintf ( V_42 , L_77 , V_119 ? L_78 : L_3 ,
F_146 ( V_31 ) ) ;
V_119 = false ;
}
fprintf ( V_42 , L_79 ,
V_199 [ V_5 . V_107 ] ) ;
fprintf ( V_42 , L_80 , V_5 . V_50 ) ;
}
static void F_147 ( T_10 * V_42 , struct V_163 * V_164 )
{
F_148 () ;
F_137 ( V_42 ) ;
fprintf ( V_42 , L_66 ) ;
F_138 ( V_42 ) ;
fprintf ( V_42 , L_66 ) ;
F_144 ( V_42 , V_164 ) ;
if ( V_5 . V_200 )
return;
fprintf ( V_42 , L_66 ) ;
fprintf ( V_42 , L_23 ) ;
fprintf ( V_42 , L_81 ) ;
fprintf ( V_42 , L_23 ) ;
fprintf ( V_42 , L_82 ) ;
F_142 ( & V_5 . V_14 . V_14 , true , 0 , 0 , 0 , stdout , false ) ;
fprintf ( V_42 , L_66 ) ;
fprintf ( V_42 , L_23 ) ;
fprintf ( V_42 , L_83 ) ;
fprintf ( V_42 , L_23 ) ;
fprintf ( V_42 , L_82 ) ;
F_143 ( V_42 ) ;
}
static void F_149 ( struct V_201 * V_202 )
{
T_2 V_33 = 0 ;
struct V_177 * V_196 = F_134 ( & V_202 -> V_14 -> V_179 ) ;
while ( V_196 ) {
struct V_16 * V_13 = F_135 ( V_196 , struct V_16 , V_177 ) ;
if ( ! V_13 -> V_47 )
V_33 ++ ;
V_196 = F_136 ( V_196 ) ;
}
V_202 -> V_203 = V_33 ;
}
static int
F_150 ( struct V_201 * V_204 ,
char * V_194 , T_1 V_1 )
{
struct V_205 * V_206 ;
struct V_16 * V_13 ;
T_6 V_73 = 0 ;
V_206 = F_6 ( V_204 , struct V_205 , V_202 ) ;
V_13 = V_206 -> V_13 ;
if ( V_13 -> V_36 )
V_73 = F_36 ( V_13 -> V_36 -> V_74 . V_73 ) ;
F_32 ( V_194 , V_1 , L_84 , V_73 ) ;
return 0 ;
}
static struct V_205 *
F_151 ( struct V_14 * V_14 , struct V_16 * V_13 )
{
struct V_205 * V_204 ;
V_204 = F_2 ( sizeof( * V_204 ) ) ;
if ( V_204 ) {
F_152 ( & V_204 -> V_202 , V_14 ) ;
V_204 -> V_202 . V_207 = true ;
V_204 -> V_202 . V_208 = F_150 ;
V_204 -> V_13 = V_13 ;
}
return V_204 ;
}
static int F_153 ( struct V_16 * V_13 )
{
struct V_2 * V_3 ;
struct V_15 * V_15 ;
struct V_205 * V_206 ;
struct V_201 * V_204 ;
int V_209 = - 1 ;
const char V_210 [] =
L_85
L_86
L_87
L_88 ;
V_5 . V_55 = false ;
V_3 = F_6 ( V_13 , struct V_2 , V_13 ) ;
V_15 = V_3 -> V_14 ;
V_206 = F_151 ( & V_15 -> V_14 , V_13 ) ;
if ( V_206 == NULL )
return - 1 ;
V_204 = & V_206 -> V_202 ;
F_154 () ;
F_155 ( 0 , 0 , 0 ) ;
F_149 ( V_204 ) ;
while ( 1 ) {
V_209 = F_156 ( V_204 , L_89 ) ;
switch ( V_209 ) {
case 's' :
V_5 . V_55 = ! V_5 . V_55 ;
break;
case 'n' :
V_5 . V_122 = ( V_5 . V_122 + 1 ) % 3 ;
F_129 () ;
break;
case 'q' :
goto V_42;
case '?' :
F_157 ( & V_204 -> V_128 , V_210 ) ;
break;
default:
break;
}
}
V_42:
free ( V_206 ) ;
return 0 ;
}
static int F_158 ( struct V_201 * V_204 ,
char * V_194 , T_1 V_1 )
{
F_32 ( V_194 , V_1 ,
L_90
L_91 ,
V_204 -> V_203 ,
V_199 [ V_5 . V_107 ] ) ;
return 0 ;
}
static struct V_201 *
F_159 ( struct V_14 * V_14 )
{
struct V_201 * V_204 = F_160 ( V_14 ) ;
if ( V_204 ) {
V_204 -> V_208 = F_158 ;
V_204 -> V_207 = true ;
}
return V_204 ;
}
static int F_161 ( struct V_14 * V_14 )
{
struct V_201 * V_204 ;
int V_209 = - 1 ;
const char V_210 [] =
L_92
L_85
L_93 ;
V_204 = F_159 ( V_14 ) ;
if ( V_204 == NULL )
return - 1 ;
F_154 () ;
F_155 ( 0 , 0 , 0 ) ;
F_149 ( V_204 ) ;
while ( 1 ) {
V_209 = F_156 ( V_204 , L_89 ) ;
switch ( V_209 ) {
case 'q' :
goto V_42;
case 'd' :
F_153 ( V_204 -> V_211 ) ;
break;
case '?' :
F_157 ( & V_204 -> V_128 , V_210 ) ;
break;
default:
break;
}
}
V_42:
F_162 ( V_204 ) ;
return 0 ;
}
static void F_163 ( struct V_163 * V_164 )
{
if ( V_103 == 0 )
F_147 ( stdout , V_164 ) ;
else
F_161 ( & V_5 . V_14 . V_14 ) ;
}
static void F_163 ( struct V_163 * V_164 )
{
V_103 = 0 ;
F_147 ( stdout , V_164 ) ;
}
static void F_164 ( void )
{
if ( ! V_5 . V_212 ) {
V_213 . V_53 = 5 ;
V_213 . V_39 = V_214 ;
}
V_215 . V_39 = V_216 [ V_5 . V_107 ] ;
}
static int
F_165 ( const struct V_217 * V_218 , const char * V_219 , int V_220 )
{
struct V_221 * V_222 = V_218 -> V_223 ;
V_222 -> V_224 = ! V_220 ;
if ( V_220 ) {
V_225 . V_226 = false ;
V_222 -> V_227 = V_228 ;
return 0 ;
}
return F_166 ( V_219 ) ;
}
static int F_167 ( struct V_197 * V_198 )
{
T_2 V_229 = F_168 ( V_198 ) ;
enum V_230 V_227 = V_231 ;
if ( ( V_229 & V_232 ) &&
( V_229 & V_233 ) )
V_227 = V_234 ;
else if ( V_229 & V_235 )
V_227 = V_236 ;
else if ( V_229 & V_237 )
V_227 = V_238 ;
if ( ! V_221 . V_224 &&
V_221 . V_227 != V_228 &&
V_227 != V_231 ) {
V_225 . V_226 = true ;
if ( F_169 ( & V_221 ) < 0 ) {
F_170 ( L_94 ) ;
return - V_171 ;
}
}
V_221 . V_239 = V_227 ;
V_221 . V_240 = 0 ;
return 0 ;
}
static int F_171 ( const char * V_241 )
{
const char * V_107 = V_241 ? : L_95 ;
if ( ! strcmp ( V_107 , L_95 ) )
V_5 . V_107 = V_110 ;
else if ( ! strcmp ( V_107 , L_96 ) )
V_5 . V_107 = V_108 ;
else if ( ! strcmp ( V_107 , L_97 ) )
V_5 . V_107 = V_109 ;
else {
F_172 ( L_98 , V_241 ) ;
return - 1 ;
}
return 0 ;
}
static int F_173 ( char * V_50 , bool V_242 )
{
char * V_243 , * V_244 , * V_70 = F_112 ( V_50 ) ;
bool V_245 = false ;
bool V_246 = false ;
bool V_247 = false ;
bool V_248 = false ;
bool V_249 = false ;
bool V_250 = false ;
if ( ! V_70 )
return - V_43 ;
F_174 (tok, buf, L_99 , tmp) {
if ( ! strcmp ( V_243 , L_100 ) ) {
V_246 = true ;
} else if ( ! strcmp ( V_243 , L_101 ) ) {
V_245 = true ;
} else if ( ! strcmp ( V_243 , L_102 ) ) {
V_247 = true ;
V_248 = true ;
V_249 = true ;
V_250 = V_242 ? false : true ;
} else if ( ! strcmp ( V_243 , L_103 ) ) {
V_249 = true ;
} else if ( strcmp ( V_243 , L_104 ) ) {
F_172 ( L_105 , V_243 ) ;
return - V_171 ;
}
}
if ( F_175 ( & V_5 . V_159 ,
L_106 ,
V_5 . V_212 ? L_107 : L_3 ,
L_108
L_109
L_110
L_111
L_112 ,
V_245 ? L_113 : L_3 ,
V_246 ? L_114 : L_3 ,
V_247 ? L_115 : L_3 ,
L_116
L_117
L_118
L_119
L_120 ,
V_248 ? L_121 : L_3 ,
V_249 ? L_122 : L_3 ,
V_250 ? L_123 : L_3 ,
L_124 ) < 0 )
return - V_43 ;
V_5 . V_154 = V_250 ;
free ( V_70 ) ;
return 0 ;
}
static int F_176 ( const char * V_251 , bool V_242 )
{
const char * V_252 = V_251 ? : V_253 ;
if ( F_175 ( & V_5 . V_50 , L_125 , V_252 ) < 0 )
return - V_43 ;
if ( F_173 ( V_5 . V_50 , V_242 ) )
return - 1 ;
if ( F_175 ( & V_5 . V_160 , L_125 ,
V_5 . V_107 == V_110 ?
L_126 :
V_5 . V_107 == V_108 ?
L_127 :
L_128 ) < 0 )
return - V_43 ;
F_17 ( L_129 , V_5 . V_50 ) ;
F_17 ( L_130 , V_5 . V_160 ) ;
F_17 ( L_131 , V_5 . V_159 ) ;
return 0 ;
}
static int F_177 ( int V_254 , const char * * V_255 )
{
struct V_163 * V_164 ;
struct V_256 V_257 ;
struct V_258 V_259 = {
. V_227 = V_260 ,
} ;
char V_261 [] = V_262 ;
const char * V_107 = NULL ;
const char * V_251 = NULL ;
bool V_242 = false ;
const struct V_217 V_263 [] = {
F_178 ( 'k' , L_132 , & V_225 . V_264 ,
L_133 , L_134 ) ,
F_178 ( 'i' , L_135 , & V_265 , L_133 ,
L_136 ) ,
F_179 ( 'N' , L_137 , & V_5 . V_122 ,
L_138 ) ,
#ifdef F_56
F_180 ( 0 , L_139 , & V_5 . V_212 , L_140 ) ,
#endif
F_180 ( 0 , L_141 , & V_5 . V_200 ,
L_142 ) ,
F_180 ( 0 , L_143 , & V_5 . V_55 ,
L_144 ) ,
F_180 ( 0 , L_145 , & V_242 ,
L_146 ) ,
F_180 ( 0 , L_147 , & V_5 . V_152 ,
L_148 ) ,
F_181 ( 'g' , L_149 , & V_221 ,
L_150 ,
V_266 , & F_165 ,
V_261 ) ,
F_178 ( 'd' , L_151 , & V_107 , L_152 , L_153 ) ,
F_178 ( 'c' , L_154 , & V_251 , L_155 ,
L_156 ) ,
F_180 ( 'f' , L_157 , & V_225 . V_267 , L_158 ) ,
F_182 ( V_268 ) ,
F_183 ()
} ;
int V_269 = 0 ;
V_254 = F_184 ( V_254 , V_255 , V_263 , V_270 ,
V_271 ) ;
if ( V_254 )
F_185 ( V_270 , V_263 ) ;
if ( V_5 . V_200 )
V_5 . V_212 = true ;
if ( ! V_265 || ! strlen ( V_265 ) )
V_265 = L_159 ;
V_259 . V_272 = V_265 ;
V_259 . V_267 = V_225 . V_267 ;
V_269 = F_171 ( V_107 ) ;
if ( V_269 )
goto V_42;
V_269 = F_176 ( V_251 , V_242 ) ;
if ( V_269 ) {
F_17 ( L_160 ) ;
goto V_42;
}
V_269 = F_9 ( & V_5 . V_14 , L_74 , 2 ) ;
if ( V_269 ) {
F_17 ( L_160 ) ;
goto V_42;
}
V_164 = F_186 ( & V_259 , 0 , & V_5 . T_3 ) ;
if ( V_164 == NULL ) {
F_17 ( L_161 ) ;
goto V_42;
}
V_269 = F_130 ( V_164 ) ;
if ( V_269 ) {
F_172 ( L_162 ) ;
goto V_42;
}
V_269 = F_167 ( V_164 -> V_198 ) ;
if ( V_269 )
goto V_273;
if ( F_187 ( & V_164 -> V_39 . V_167 ) < 0 )
goto V_273;
if ( F_188 ( V_164 -> V_259 ) ) {
F_17 ( L_163 ) ;
goto V_273;
}
if ( V_5 . V_212 )
V_103 = 0 ;
else
V_103 = 1 ;
F_189 ( false ) ;
V_269 = F_190 ( V_164 ) ;
if ( V_269 ) {
F_172 ( L_164 ) ;
goto V_273;
}
F_117 ( & V_5 . V_14 ,
L_165
L_166
L_119
L_167
L_168
L_169
L_170
L_171
L_172
L_173
L_174 ,
V_5 . V_107 == V_110 ? L_126 :
V_5 . V_107 == V_109 ? L_175 : L_176
) ;
F_191 ( & V_257 , V_5 . V_14 . V_14 . V_33 , L_177 ) ;
F_127 ( & V_5 . V_14 . V_14 , NULL ) ;
F_128 ( & V_5 . V_14 . V_14 , & V_257 , F_131 ) ;
F_133 ( & V_5 . V_14 . V_14 , F_126 ) ;
F_192 () ;
F_164 () ;
F_163 ( V_164 ) ;
V_273:
F_193 ( V_164 ) ;
V_42:
return V_269 ;
}
static int F_194 ( const struct V_217 * V_218 ,
const char * V_241 , int V_220 V_27 )
{
bool * V_274 = ( bool * ) V_218 -> V_223 ;
* V_274 = true ;
return F_195 ( V_241 ) ;
}
static int F_196 ( int V_254 , const char * * V_255 )
{
int V_275 , V_132 = 0 , V_276 ;
const char * * V_277 ;
int V_19 ;
bool V_278 = false , V_279 = false ;
bool V_274 = false ;
struct V_217 V_263 [] = {
F_197 ( 'e' , L_178 , & V_274 , L_178 ,
L_179 ,
F_194 ) ,
F_180 ( 'u' , L_180 , & V_278 , L_181 ) ,
F_180 ( 'k' , L_182 , & V_279 , L_183 ) ,
F_198 ( 'l' , L_184 , & V_280 , L_185 ) ,
F_182 ( V_268 ) ,
F_183 ()
} ;
if ( F_199 () ) {
F_172 ( L_186 ) ;
return - 1 ;
}
V_254 = F_184 ( V_254 , V_255 , V_263 , V_281 ,
V_282 ) ;
V_275 = V_254 + 10 ;
V_277 = calloc ( V_275 + 1 , sizeof( char * ) ) ;
if ( ! V_277 )
return - 1 ;
V_277 [ V_132 ++ ] = L_187 ;
if ( ! V_274 ) {
V_283 [ V_284 ] . V_285 = true ;
V_283 [ V_286 ] . V_285 = true ;
}
if ( V_283 [ V_284 ] . V_285 )
V_277 [ V_132 ++ ] = L_188 ;
V_277 [ V_132 ++ ] = L_189 ;
V_277 [ V_132 ++ ] = L_190 ;
for ( V_276 = 0 ; V_276 < V_287 ; V_276 ++ ) {
if ( ! V_283 [ V_276 ] . V_285 )
continue;
if ( ! V_283 [ V_276 ] . V_288 ) {
F_172 ( L_191 ,
V_283 [ V_276 ] . V_131 ) ;
return - 1 ;
}
V_277 [ V_132 ++ ] = L_192 ;
V_277 [ V_132 ++ ] = F_200 ( V_276 ) ;
} ;
if ( V_278 )
V_277 [ V_132 ++ ] = L_193 ;
if ( V_279 )
V_277 [ V_132 ++ ] = L_194 ;
for ( V_276 = 0 ; V_276 < V_254 ; V_276 ++ , V_132 ++ )
V_277 [ V_132 ] = V_255 [ V_276 ] ;
if ( V_289 > 0 ) {
F_17 ( L_195 ) ;
V_276 = 0 ;
while ( V_277 [ V_276 ] ) {
F_17 ( L_196 , V_277 [ V_276 ] ) ;
V_276 ++ ;
}
F_17 ( L_66 ) ;
}
V_19 = F_201 ( V_132 , V_277 ) ;
free ( V_277 ) ;
return V_19 ;
}
int F_202 ( int V_254 , const char * * V_255 )
{
V_254 = F_184 ( V_254 , V_255 , V_268 , V_290 ,
V_271 ) ;
if ( ! V_254 )
F_185 ( V_290 , V_268 ) ;
if ( ! strncmp ( V_255 [ 0 ] , L_197 , 3 ) ) {
return F_196 ( V_254 , V_255 ) ;
} else if ( ! strncmp ( V_255 [ 0 ] , L_198 , 3 ) ) {
return F_177 ( V_254 , V_255 ) ;
} else {
F_185 ( V_290 , V_268 ) ;
}
return 0 ;
}
