static int F_1 ( unsigned long V_1 , unsigned long V_2 ,
int V_3 , int V_4 , int V_5 )
{
struct V_6 * * V_7 = & V_8 . V_6 ;
struct V_6 * V_9 = NULL ;
struct V_10 * V_11 = NULL ;
while ( * V_7 ) {
V_9 = * V_7 ;
V_11 = F_2 ( * V_7 , struct V_10 , V_7 ) ;
if ( V_2 > V_11 -> V_2 )
V_7 = & ( * V_7 ) -> V_12 ;
else if ( V_2 < V_11 -> V_2 )
V_7 = & ( * V_7 ) -> V_13 ;
else
break;
}
if ( V_11 && V_11 -> V_2 == V_2 ) {
V_11 -> V_14 ++ ;
V_11 -> V_3 += V_3 ;
V_11 -> V_4 += V_4 ;
} else {
V_11 = malloc ( sizeof( * V_11 ) ) ;
if ( ! V_11 ) {
F_3 ( L_1 , V_15 ) ;
return - 1 ;
}
V_11 -> V_2 = V_2 ;
V_11 -> V_16 = 0 ;
V_11 -> V_14 = 1 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_4 = V_4 ;
F_4 ( & V_11 -> V_7 , V_9 , V_7 ) ;
F_5 ( & V_11 -> V_7 , & V_8 ) ;
}
V_11 -> V_1 = V_1 ;
V_11 -> V_17 = V_5 ;
return 0 ;
}
static int F_6 ( unsigned long V_1 ,
int V_3 , int V_4 )
{
struct V_6 * * V_7 = & V_18 . V_6 ;
struct V_6 * V_9 = NULL ;
struct V_10 * V_11 = NULL ;
while ( * V_7 ) {
V_9 = * V_7 ;
V_11 = F_2 ( * V_7 , struct V_10 , V_7 ) ;
if ( V_1 > V_11 -> V_1 )
V_7 = & ( * V_7 ) -> V_12 ;
else if ( V_1 < V_11 -> V_1 )
V_7 = & ( * V_7 ) -> V_13 ;
else
break;
}
if ( V_11 && V_11 -> V_1 == V_1 ) {
V_11 -> V_14 ++ ;
V_11 -> V_3 += V_3 ;
V_11 -> V_4 += V_4 ;
} else {
V_11 = malloc ( sizeof( * V_11 ) ) ;
if ( ! V_11 ) {
F_3 ( L_1 , V_15 ) ;
return - 1 ;
}
V_11 -> V_1 = V_1 ;
V_11 -> V_16 = 0 ;
V_11 -> V_14 = 1 ;
V_11 -> V_3 = V_3 ;
V_11 -> V_4 = V_4 ;
F_4 ( & V_11 -> V_7 , V_9 , V_7 ) ;
F_5 ( & V_11 -> V_7 , & V_18 ) ;
}
return 0 ;
}
static int F_7 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
unsigned long V_2 = F_8 ( V_20 , V_22 , L_2 ) ,
V_1 = F_8 ( V_20 , V_22 , L_3 ) ;
int V_3 = F_8 ( V_20 , V_22 , L_4 ) ,
V_4 = F_8 ( V_20 , V_22 , L_5 ) ;
if ( F_1 ( V_1 , V_2 , V_3 , V_4 , V_22 -> V_5 ) ||
F_6 ( V_1 , V_3 , V_4 ) )
return - 1 ;
V_23 += V_3 ;
V_24 += V_4 ;
V_25 ++ ;
return 0 ;
}
static int F_9 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
int V_26 = F_7 ( V_20 , V_22 ) ;
if ( ! V_26 ) {
int V_27 = F_10 ( V_22 -> V_5 ) ,
V_28 = F_8 ( V_20 , V_22 , L_6 ) ;
if ( V_27 != V_28 )
V_29 ++ ;
}
return V_26 ;
}
static struct V_10 * F_11 ( unsigned long V_2 ,
unsigned long V_1 ,
struct V_30 * V_31 ,
T_1 V_32 )
{
struct V_6 * V_7 = V_31 -> V_6 ;
struct V_10 V_33 = { . V_2 = V_2 , . V_1 = V_1 } ;
while ( V_7 ) {
struct V_10 * V_11 ;
int V_34 ;
V_11 = F_2 ( V_7 , struct V_10 , V_7 ) ;
V_34 = V_32 ( & V_33 , V_11 ) ;
if ( V_34 < 0 )
V_7 = V_7 -> V_13 ;
else if ( V_34 > 0 )
V_7 = V_7 -> V_12 ;
else
return V_11 ;
}
return NULL ;
}
static int F_12 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
unsigned long V_2 = F_8 ( V_20 , V_22 , L_2 ) ;
struct V_10 * V_35 , * V_36 ;
V_35 = F_11 ( V_2 , 0 , & V_8 , V_37 ) ;
if ( ! V_35 )
return 0 ;
if ( ( short ) V_22 -> V_5 != V_35 -> V_17 ) {
V_35 -> V_16 ++ ;
V_36 = F_11 ( 0 , V_35 -> V_1 ,
& V_18 , V_38 ) ;
if ( ! V_36 )
return - 1 ;
V_36 -> V_16 ++ ;
}
V_35 -> V_17 = - 1 ;
return 0 ;
}
static struct V_39 * F_13 ( unsigned long V_40 , bool V_41 )
{
struct V_6 * * V_7 = & V_42 . V_6 ;
struct V_6 * V_9 = NULL ;
struct V_39 * V_11 ;
while ( * V_7 ) {
T_2 V_34 ;
V_9 = * V_7 ;
V_11 = F_2 ( * V_7 , struct V_39 , V_7 ) ;
V_34 = V_11 -> V_40 - V_40 ;
if ( V_34 < 0 )
V_7 = & V_9 -> V_13 ;
else if ( V_34 > 0 )
V_7 = & V_9 -> V_12 ;
else
return V_11 ;
}
if ( ! V_41 )
return NULL ;
V_11 = F_14 ( sizeof( * V_11 ) ) ;
if ( V_11 != NULL ) {
V_11 -> V_40 = V_40 ;
F_4 ( & V_11 -> V_7 , V_9 , V_7 ) ;
F_5 ( & V_11 -> V_7 , & V_42 ) ;
}
return V_11 ;
}
static int F_15 ( struct V_39 * V_43 , struct V_39 * V_44 )
{
if ( V_43 -> V_40 > V_44 -> V_40 )
return - 1 ;
if ( V_43 -> V_40 < V_44 -> V_40 )
return 1 ;
if ( V_43 -> V_45 > V_44 -> V_45 )
return - 1 ;
if ( V_43 -> V_45 < V_44 -> V_45 )
return 1 ;
if ( V_43 -> V_46 > V_44 -> V_46 )
return - 1 ;
if ( V_43 -> V_46 < V_44 -> V_46 )
return 1 ;
if ( V_43 -> V_47 > V_44 -> V_47 )
return - 1 ;
if ( V_43 -> V_47 < V_44 -> V_47 )
return 1 ;
return 0 ;
}
static struct V_39 * F_16 ( struct V_39 * V_48 , bool V_41 )
{
struct V_6 * * V_7 = & V_49 . V_6 ;
struct V_6 * V_9 = NULL ;
struct V_39 * V_11 ;
while ( * V_7 ) {
T_2 V_34 ;
V_9 = * V_7 ;
V_11 = F_2 ( * V_7 , struct V_39 , V_7 ) ;
V_34 = F_15 ( V_11 , V_48 ) ;
if ( V_34 < 0 )
V_7 = & V_9 -> V_13 ;
else if ( V_34 > 0 )
V_7 = & V_9 -> V_12 ;
else
return V_11 ;
}
if ( ! V_41 )
return NULL ;
V_11 = F_14 ( sizeof( * V_11 ) ) ;
if ( V_11 != NULL ) {
V_11 -> V_40 = V_48 -> V_40 ;
V_11 -> V_45 = V_48 -> V_45 ;
V_11 -> V_47 = V_48 -> V_47 ;
V_11 -> V_46 = V_48 -> V_46 ;
F_4 ( & V_11 -> V_7 , V_9 , V_7 ) ;
F_5 ( & V_11 -> V_7 , & V_49 ) ;
}
return V_11 ;
}
static bool F_17 ( T_3 V_50 )
{
if ( V_51 && V_50 == - 1UL )
return false ;
if ( ! V_51 && V_50 == 0 )
return false ;
return true ;
}
static int F_18 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
T_3 V_40 ;
unsigned int V_45 = F_8 ( V_20 , V_22 , L_7 ) ;
unsigned int V_47 = F_8 ( V_20 , V_22 , L_8 ) ;
unsigned int V_46 = F_8 ( V_20 , V_22 ,
L_9 ) ;
T_3 V_52 = V_53 << V_45 ;
struct V_39 * V_48 ;
struct V_39 V_54 = {
. V_45 = V_45 ,
. V_47 = V_47 ,
. V_46 = V_46 ,
} ;
if ( V_51 )
V_40 = F_8 ( V_20 , V_22 , L_10 ) ;
else
V_40 = F_8 ( V_20 , V_22 , L_11 ) ;
V_55 ++ ;
V_56 += V_52 ;
if ( ! F_17 ( V_40 ) ) {
V_57 ++ ;
V_58 += V_52 ;
return 0 ;
}
V_48 = F_13 ( V_40 , true ) ;
if ( V_48 == NULL )
return - V_59 ;
V_48 -> V_45 = V_45 ;
V_48 -> V_47 = V_47 ;
V_48 -> V_46 = V_46 ;
V_54 . V_40 = V_40 ;
V_48 = F_16 ( & V_54 , true ) ;
if ( V_48 == NULL )
return - V_59 ;
V_48 -> V_60 ++ ;
V_48 -> V_61 += V_52 ;
V_62 [ V_45 ] [ V_46 ] ++ ;
return 0 ;
}
static int F_19 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
T_3 V_40 ;
unsigned int V_45 = F_8 ( V_20 , V_22 , L_7 ) ;
T_3 V_52 = V_53 << V_45 ;
struct V_39 * V_48 ;
struct V_39 V_54 = {
. V_45 = V_45 ,
} ;
if ( V_51 )
V_40 = F_8 ( V_20 , V_22 , L_10 ) ;
else
V_40 = F_8 ( V_20 , V_22 , L_11 ) ;
V_63 ++ ;
V_64 += V_52 ;
V_48 = F_13 ( V_40 , false ) ;
if ( V_48 == NULL ) {
F_20 ( L_12 V_65 L_13 ,
V_40 , V_45 ) ;
V_66 ++ ;
V_67 += V_52 ;
return 0 ;
}
V_54 . V_40 = V_40 ;
V_54 . V_47 = V_48 -> V_47 ;
V_54 . V_46 = V_48 -> V_46 ;
F_21 ( & V_48 -> V_7 , & V_42 ) ;
free ( V_48 ) ;
V_48 = F_16 ( & V_54 , false ) ;
if ( V_48 == NULL )
return - V_68 ;
V_48 -> V_69 ++ ;
V_48 -> V_70 += V_52 ;
return 0 ;
}
static int F_22 ( struct V_71 * T_4 V_72 ,
union V_73 * V_74 ,
struct V_21 * V_22 ,
struct V_19 * V_20 ,
struct V_75 * V_75 )
{
struct V_76 * V_76 = F_23 ( V_75 , V_22 -> V_77 ,
V_22 -> V_78 ) ;
if ( V_76 == NULL ) {
F_24 ( L_14 ,
V_74 -> V_79 . type ) ;
return - 1 ;
}
F_25 ( L_15 , F_26 ( V_76 ) , V_76 -> V_78 ) ;
if ( V_20 -> V_80 != NULL ) {
T_5 V_81 = V_20 -> V_80 ;
return V_81 ( V_20 , V_22 ) ;
}
return 0 ;
}
static double F_27 ( unsigned long V_82 , unsigned long V_83 )
{
if ( V_83 == 0 )
return 0.0 ;
else
return 100.0 - ( 100.0 * V_82 / V_83 ) ;
}
static void F_28 ( struct V_30 * V_31 ,
struct V_84 * V_85 ,
int V_86 , int V_87 )
{
struct V_6 * V_88 ;
struct V_75 * V_75 = & V_85 -> V_89 . V_90 ;
printf ( L_16 , V_91 ) ;
printf ( L_17 , V_87 ? L_18 : L_19 ) ;
printf ( L_20 ) ;
printf ( L_16 , V_91 ) ;
V_88 = F_29 ( V_31 ) ;
while ( V_88 && V_86 -- ) {
struct V_10 * V_11 = F_2 ( V_88 , struct V_10 ,
V_7 ) ;
struct V_92 * V_93 = NULL ;
struct V_94 * V_94 ;
char V_95 [ V_96 ] ;
T_3 V_97 ;
if ( V_87 ) {
V_97 = V_11 -> V_1 ;
if ( ! V_98 )
V_93 = F_30 ( V_75 , V_97 , & V_94 , NULL ) ;
} else
V_97 = V_11 -> V_2 ;
if ( V_93 != NULL )
snprintf ( V_95 , sizeof( V_95 ) , L_21 V_65 L_22 , V_93 -> V_99 ,
V_97 - V_94 -> V_100 ( V_94 , V_93 -> V_101 ) ) ;
else
snprintf ( V_95 , sizeof( V_95 ) , L_23 V_65 L_22 , V_97 ) ;
printf ( L_17 , V_95 ) ;
printf ( L_24 ,
( unsigned long long ) V_11 -> V_4 ,
( unsigned long ) V_11 -> V_4 / V_11 -> V_14 ,
( unsigned long long ) V_11 -> V_3 ,
( unsigned long ) V_11 -> V_3 / V_11 -> V_14 ,
( unsigned long ) V_11 -> V_14 ,
( unsigned long ) V_11 -> V_16 ,
F_27 ( V_11 -> V_3 , V_11 -> V_4 ) ) ;
V_88 = F_31 ( V_88 ) ;
}
if ( V_86 == - 1 )
printf ( L_25 ) ;
printf ( L_16 , V_91 ) ;
}
static void F_32 ( struct V_30 * V_31 ,
struct V_84 * V_85 V_72 ,
int V_86 )
{
struct V_6 * V_88 = F_29 ( V_31 ) ;
const char * V_102 ;
printf ( L_26 , V_91 ) ;
printf ( L_27 ,
V_51 ? L_28 : L_29 ) ;
printf ( L_30 , V_91 ) ;
if ( V_51 )
V_102 = L_31 ;
else
V_102 = L_32 ;
while ( V_88 && V_86 -- ) {
struct V_39 * V_11 ;
V_11 = F_2 ( V_88 , struct V_39 , V_7 ) ;
printf ( V_102 , ( unsigned long long ) V_11 -> V_40 ,
( unsigned long long ) V_11 -> V_61 / 1024 ,
V_11 -> V_60 , V_11 -> V_45 ,
V_103 [ V_11 -> V_46 ] ,
( unsigned long ) V_11 -> V_47 ) ;
V_88 = F_31 ( V_88 ) ;
}
if ( V_86 == - 1 )
printf ( L_33 ) ;
printf ( L_30 , V_91 ) ;
}
static void F_33 ( void )
{
printf ( L_34 ) ;
printf ( L_35 ) ;
printf ( L_36 , V_23 ) ;
printf ( L_37 , V_24 ) ;
printf ( L_38 ,
V_24 - V_23 ) ;
printf ( L_39 ,
F_27 ( V_23 , V_24 ) ) ;
printf ( L_40 , V_29 , V_25 ) ;
}
static void F_34 ( void )
{
int V_104 , V_105 ;
T_3 V_106 = V_63 - V_66 ;
T_3 V_107 = V_64 - V_67 ;
printf ( L_41 ) ;
printf ( L_35 ) ;
printf ( L_42 V_108 L_43 , L_44 ,
V_55 , V_56 / 1024 ) ;
printf ( L_42 V_108 L_43 , L_45 ,
V_63 , V_64 / 1024 ) ;
printf ( L_46 ) ;
printf ( L_47 V_108 L_48 V_108 L_43 , L_49 ,
V_106 , ( V_107 ) / 1024 ) ;
printf ( L_47 V_108 L_48 V_108 L_43 , L_50 ,
V_55 - V_106 ,
( V_56 - V_107 ) / 1024 ) ;
printf ( L_42 V_108 L_43 , L_51 ,
V_66 , V_67 / 1024 ) ;
printf ( L_46 ) ;
printf ( L_42 V_108 L_43 , L_52 ,
V_57 , V_58 / 1024 ) ;
printf ( L_46 ) ;
printf ( L_53 , L_54 , L_55 ,
L_56 , L_57 , L_58 , L_59 ) ;
printf ( L_60 , V_91 ,
V_91 , V_91 , V_91 ,
V_91 , V_91 ) ;
for ( V_104 = 0 ; V_104 < V_109 ; V_104 ++ ) {
printf ( L_61 , V_104 ) ;
for ( V_105 = 0 ; V_105 < V_110 - 1 ; V_105 ++ ) {
if ( V_62 [ V_104 ] [ V_105 ] )
printf ( L_62 , V_62 [ V_104 ] [ V_105 ] ) ;
else
printf ( L_63 , '.' ) ;
}
printf ( L_46 ) ;
}
}
static void F_35 ( struct V_84 * V_85 )
{
if ( V_111 )
F_28 ( & V_112 , V_85 , V_113 , 1 ) ;
if ( V_114 )
F_28 ( & V_115 , V_85 , V_116 , 0 ) ;
F_33 () ;
}
static void F_36 ( struct V_84 * V_85 )
{
if ( V_114 )
F_32 ( & V_117 , V_85 , V_116 ) ;
F_34 () ;
}
static void F_37 ( struct V_84 * V_85 )
{
if ( V_118 )
F_35 ( V_85 ) ;
if ( V_119 )
F_36 ( V_85 ) ;
}
static void F_38 ( struct V_30 * V_31 , struct V_10 * V_11 ,
struct V_120 * V_121 )
{
struct V_6 * * V_122 = & ( V_31 -> V_6 ) ;
struct V_6 * V_9 = NULL ;
struct V_123 * V_124 ;
while ( * V_122 ) {
struct V_10 * V_54 ;
int V_34 = 0 ;
V_54 = F_2 ( * V_122 , struct V_10 , V_7 ) ;
V_9 = * V_122 ;
F_39 (sort, sort_list, list) {
V_34 = V_124 -> V_34 ( V_11 , V_54 ) ;
if ( V_34 )
break;
}
if ( V_34 > 0 )
V_122 = & ( ( * V_122 ) -> V_13 ) ;
else
V_122 = & ( ( * V_122 ) -> V_12 ) ;
}
F_4 ( & V_11 -> V_7 , V_9 , V_122 ) ;
F_5 ( & V_11 -> V_7 , V_31 ) ;
}
static void F_40 ( struct V_30 * V_31 , struct V_30 * V_125 ,
struct V_120 * V_121 )
{
struct V_6 * V_7 ;
struct V_10 * V_11 ;
for (; ; ) {
V_7 = F_29 ( V_31 ) ;
if ( ! V_7 )
break;
F_21 ( V_7 , V_31 ) ;
V_11 = F_2 ( V_7 , struct V_10 , V_7 ) ;
F_38 ( V_125 , V_11 , V_121 ) ;
}
}
static void F_41 ( struct V_30 * V_31 , struct V_39 * V_11 )
{
struct V_6 * * V_122 = & V_31 -> V_6 ;
struct V_6 * V_9 = NULL ;
while ( * V_122 ) {
struct V_39 * V_54 ;
int V_34 = 0 ;
V_54 = F_2 ( * V_122 , struct V_39 , V_7 ) ;
V_9 = * V_122 ;
V_34 = V_11 -> V_61 - V_54 -> V_61 ;
if ( V_34 > 0 )
V_122 = & V_9 -> V_13 ;
else
V_122 = & V_9 -> V_12 ;
}
F_4 ( & V_11 -> V_7 , V_9 , V_122 ) ;
F_5 ( & V_11 -> V_7 , V_31 ) ;
}
static void F_42 ( struct V_30 * V_31 , struct V_30 * V_125 )
{
struct V_6 * V_7 ;
struct V_39 * V_11 ;
for (; ; ) {
V_7 = F_29 ( V_31 ) ;
if ( ! V_7 )
break;
F_21 ( V_7 , V_31 ) ;
V_11 = F_2 ( V_7 , struct V_39 , V_7 ) ;
F_41 ( V_125 , V_11 ) ;
}
}
static void F_43 ( void )
{
if ( V_118 ) {
F_40 ( & V_8 , & V_115 ,
& V_126 ) ;
F_40 ( & V_18 , & V_112 ,
& V_127 ) ;
}
if ( V_119 ) {
F_42 ( & V_49 , & V_117 ) ;
}
}
static int F_44 ( struct V_84 * V_85 )
{
int V_128 = - V_129 ;
struct V_19 * V_20 ;
const struct V_130 V_131 [] = {
{ L_64 , F_7 , } ,
{ L_65 , F_7 , } ,
{ L_66 , F_9 , } ,
{ L_67 , F_9 , } ,
{ L_68 , F_12 , } ,
{ L_69 , F_12 , } ,
{ L_70 , F_18 , } ,
{ L_71 , F_19 , } ,
} ;
if ( ! F_45 ( V_85 , L_72 ) )
goto V_132;
if ( F_46 ( V_85 , V_131 ) ) {
F_3 ( L_73 ) ;
goto V_132;
}
F_47 (session->evlist, evsel) {
if ( ! strcmp ( F_48 ( V_20 ) , L_70 ) &&
F_49 ( V_20 , L_10 ) ) {
V_51 = true ;
break;
}
}
F_50 () ;
V_128 = F_51 ( V_85 ) ;
if ( V_128 != 0 ) {
F_3 ( L_74 , V_128 ) ;
goto V_132;
}
F_43 () ;
F_37 ( V_85 ) ;
V_132:
return V_128 ;
}
static int V_37 ( struct V_10 * V_133 , struct V_10 * V_134 )
{
if ( V_133 -> V_2 < V_134 -> V_2 )
return - 1 ;
else if ( V_133 -> V_2 > V_134 -> V_2 )
return 1 ;
return 0 ;
}
static int V_38 ( struct V_10 * V_133 , struct V_10 * V_134 )
{
if ( V_133 -> V_1 < V_134 -> V_1 )
return - 1 ;
else if ( V_133 -> V_1 > V_134 -> V_1 )
return 1 ;
return 0 ;
}
static int F_52 ( struct V_10 * V_133 , struct V_10 * V_134 )
{
if ( V_133 -> V_14 < V_134 -> V_14 )
return - 1 ;
else if ( V_133 -> V_14 > V_134 -> V_14 )
return 1 ;
return 0 ;
}
static int F_53 ( struct V_10 * V_133 , struct V_10 * V_134 )
{
if ( V_133 -> V_4 < V_134 -> V_4 )
return - 1 ;
else if ( V_133 -> V_4 > V_134 -> V_4 )
return 1 ;
return 0 ;
}
static int F_54 ( struct V_10 * V_133 , struct V_10 * V_134 )
{
double V_135 , V_136 ;
V_135 = F_27 ( V_133 -> V_3 , V_133 -> V_4 ) ;
V_136 = F_27 ( V_134 -> V_3 , V_134 -> V_4 ) ;
if ( V_135 < V_136 )
return - 1 ;
else if ( V_135 > V_136 )
return 1 ;
return 0 ;
}
static int F_55 ( struct V_10 * V_133 , struct V_10 * V_134 )
{
if ( V_133 -> V_16 < V_134 -> V_16 )
return - 1 ;
else if ( V_133 -> V_16 > V_134 -> V_16 )
return 1 ;
return 0 ;
}
static int F_56 ( const char * V_137 , struct V_120 * V_138 )
{
struct V_123 * V_124 ;
int V_139 ;
for ( V_139 = 0 ; V_139 < V_140 ; V_139 ++ ) {
if ( ! strcmp ( V_141 [ V_139 ] -> V_99 , V_137 ) ) {
V_124 = F_57 ( V_141 [ V_139 ] , sizeof( * V_141 [ V_139 ] ) ) ;
if ( ! V_124 ) {
F_3 ( L_75 , V_15 ) ;
return - 1 ;
}
F_58 ( & V_124 -> V_138 , V_138 ) ;
return 0 ;
}
}
return - 1 ;
}
static int F_59 ( struct V_120 * V_121 , const char * V_142 )
{
char * V_137 ;
char * V_143 = F_60 ( V_142 ) ;
char * V_144 = V_143 ;
if ( ! V_143 ) {
F_3 ( L_76 , V_15 ) ;
return - 1 ;
}
while ( true ) {
V_137 = F_61 ( & V_144 , L_77 ) ;
if ( ! V_137 )
break;
if ( F_56 ( V_137 , V_121 ) < 0 ) {
error ( L_78 , V_137 ) ;
free ( V_143 ) ;
return - 1 ;
}
}
free ( V_143 ) ;
return 0 ;
}
static int F_62 ( const struct V_145 * T_6 V_72 ,
const char * V_142 , int T_7 V_72 )
{
if ( ! V_142 )
return - 1 ;
if ( V_111 > V_114 )
return F_59 ( & V_127 , V_142 ) ;
else
return F_59 ( & V_126 , V_142 ) ;
return 0 ;
}
static int F_63 ( const struct V_145 * T_6 V_72 ,
const char * V_142 V_72 ,
int T_7 V_72 )
{
V_111 = ( V_114 + 1 ) ;
return 0 ;
}
static int F_64 ( const struct V_145 * T_6 V_72 ,
const char * V_142 V_72 ,
int T_7 V_72 )
{
V_114 = ( V_111 + 1 ) ;
return 0 ;
}
static int F_65 ( const struct V_145 * T_6 V_72 ,
const char * V_142 V_72 ,
int T_7 V_72 )
{
V_118 = ( V_119 + 1 ) ;
return 0 ;
}
static int F_66 ( const struct V_145 * T_6 V_72 ,
const char * V_142 V_72 ,
int T_7 V_72 )
{
V_119 = ( V_118 + 1 ) ;
return 0 ;
}
static int F_67 ( const struct V_145 * T_6 V_72 ,
const char * V_142 , int T_7 V_72 )
{
int V_146 ;
if ( ! V_142 )
return - 1 ;
V_146 = strtoul ( V_142 , NULL , 10 ) ;
if ( V_111 > V_114 )
V_113 = V_146 ;
else
V_116 = V_146 ;
return 0 ;
}
static int F_68 ( int V_147 , const char * * V_148 )
{
const char * const V_149 [] = {
L_79 , L_80 , L_81 , L_82 , L_83 ,
} ;
const char * const V_150 [] = {
L_84 , L_64 ,
L_84 , L_66 ,
L_84 , L_68 ,
L_84 , L_65 ,
L_84 , L_67 ,
L_84 , L_69 ,
} ;
const char * const V_151 [] = {
L_84 , L_70 ,
L_84 , L_71 ,
} ;
unsigned int V_152 , V_139 , V_153 ;
const char * * V_154 ;
V_152 = F_69 ( V_149 ) + V_147 - 1 ;
if ( V_118 )
V_152 += F_69 ( V_150 ) ;
if ( V_119 )
V_152 += F_69 ( V_151 ) ;
V_154 = calloc ( V_152 + 1 , sizeof( char * ) ) ;
if ( V_154 == NULL )
return - V_59 ;
for ( V_139 = 0 ; V_139 < F_69 ( V_149 ) ; V_139 ++ )
V_154 [ V_139 ] = F_60 ( V_149 [ V_139 ] ) ;
if ( V_118 ) {
for ( V_153 = 0 ; V_153 < F_69 ( V_150 ) ; V_153 ++ , V_139 ++ )
V_154 [ V_139 ] = F_60 ( V_150 [ V_153 ] ) ;
}
if ( V_119 ) {
for ( V_153 = 0 ; V_153 < F_69 ( V_151 ) ; V_153 ++ , V_139 ++ )
V_154 [ V_139 ] = F_60 ( V_151 [ V_153 ] ) ;
}
for ( V_153 = 1 ; V_153 < ( unsigned int ) V_147 ; V_153 ++ , V_139 ++ )
V_154 [ V_139 ] = V_148 [ V_153 ] ;
return F_70 ( V_139 , V_154 , NULL ) ;
}
int F_71 ( int V_147 , const char * * V_148 , const char * T_8 V_72 )
{
const char * const V_155 = L_85 ;
struct V_156 V_157 = {
. V_158 = V_159 ,
} ;
const struct V_145 V_160 [] = {
F_72 ( 'i' , L_86 , & V_161 , L_87 , L_88 ) ,
F_73 ( 'v' , L_89 , & V_162 ,
L_90 ) ,
F_74 ( 0 , L_91 , NULL , NULL ,
L_92 , F_63 ) ,
F_74 ( 0 , L_93 , NULL , NULL ,
L_94 , F_64 ) ,
F_75 ( 's' , L_95 , NULL , L_96 ,
L_97 ,
F_62 ) ,
F_75 ( 'l' , L_98 , NULL , L_99 , L_100 , F_67 ) ,
F_76 ( 0 , L_101 , & V_98 , L_102 ) ,
F_76 ( 'f' , L_103 , & V_157 . V_163 , L_104 ) ,
F_74 ( 0 , L_105 , NULL , NULL , L_106 ,
F_65 ) ,
F_74 ( 0 , L_11 , NULL , NULL , L_107 ,
F_66 ) ,
F_77 ()
} ;
const char * const V_164 [] = { L_79 , L_108 , NULL } ;
const char * V_165 [] = {
NULL ,
NULL
} ;
struct V_84 * V_85 ;
int V_26 = - 1 ;
V_147 = F_78 ( V_147 , V_148 , V_160 ,
V_164 , V_165 , 0 ) ;
if ( ! V_147 )
F_79 ( V_165 , V_160 ) ;
if ( V_118 == 0 && V_119 == 0 )
V_118 = 1 ;
if ( ! strncmp ( V_148 [ 0 ] , L_109 , 3 ) ) {
F_80 ( NULL ) ;
return F_68 ( V_147 , V_148 ) ;
}
V_157 . V_166 = V_161 ;
V_85 = F_81 ( & V_157 , false , & V_167 ) ;
if ( V_85 == NULL )
return - 1 ;
if ( V_119 ) {
struct V_19 * V_20 = F_82 ( V_85 -> V_168 ) ;
if ( V_20 == NULL || V_20 -> V_169 == NULL ) {
F_3 ( L_110 ) ;
return - 1 ;
}
V_53 = F_83 ( V_20 -> V_169 -> V_170 ) ;
}
F_80 ( & V_85 -> V_79 . V_171 ) ;
if ( ! strcmp ( V_148 [ 0 ] , L_108 ) ) {
setlocale ( V_172 , L_22 ) ;
if ( F_84 () )
goto V_173;
if ( F_85 ( & V_127 ) )
F_59 ( & V_127 , V_155 ) ;
if ( F_85 ( & V_126 ) )
F_59 ( & V_126 , V_155 ) ;
V_26 = F_44 ( V_85 ) ;
} else
F_79 ( V_165 , V_160 ) ;
V_173:
F_86 ( V_85 ) ;
return V_26 ;
}
