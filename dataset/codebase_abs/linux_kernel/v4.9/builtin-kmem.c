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
& V_18 ,
V_38 ) ;
if ( ! V_36 )
return - 1 ;
V_36 -> V_16 ++ ;
}
V_35 -> V_17 = - 1 ;
return 0 ;
}
static int F_13 ( const void * V_39 , const void * V_40 )
{
const struct V_41 * V_42 = V_39 ;
const struct V_41 * V_43 = V_40 ;
if ( V_42 -> V_44 > V_43 -> V_44 )
return 1 ;
else
return - 1 ;
}
static int F_14 ( const void * V_39 , const void * V_40 )
{
const struct V_41 * V_42 = V_39 ;
const struct V_41 * V_43 = V_40 ;
if ( V_43 -> V_44 <= V_42 -> V_44 && V_42 -> V_45 < V_43 -> V_45 )
return 0 ;
if ( V_42 -> V_44 > V_43 -> V_44 )
return 1 ;
else
return - 1 ;
}
static int F_15 ( void )
{
int V_26 ;
struct V_46 * V_47 ;
struct V_48 * V_49 ;
struct V_6 * V_7 ;
struct V_41 * V_50 ;
struct V_51 * V_51 = & V_52 -> V_53 . V_54 ;
T_2 V_55 ;
const char V_56 [] = L_7 ;
V_26 = regcomp ( & V_55 , V_56 , V_57 ) ;
if ( V_26 ) {
char V_58 [ V_59 ] ;
regerror ( V_26 , & V_55 , V_58 , sizeof( V_58 ) ) ;
F_3 ( L_8 , V_56 , V_58 ) ;
return - V_60 ;
}
V_47 = F_16 ( V_51 ) ;
if ( F_17 ( V_47 ) < 0 ) {
F_3 ( L_9 ) ;
return - V_61 ;
}
F_18 (kernel_map, sym, node) {
if ( regexec ( & V_55 , V_49 -> V_62 , 0 , NULL , 0 ) )
continue;
V_50 = realloc ( V_63 ,
( V_64 + 1 ) * sizeof( * V_50 ) ) ;
if ( V_50 == NULL )
return - V_65 ;
F_19 ( L_10 , V_49 -> V_62 ) ;
V_50 [ V_64 ] . V_44 = V_49 -> V_44 ;
V_50 [ V_64 ] . V_45 = V_49 -> V_45 ;
V_50 [ V_64 ] . V_62 = V_49 -> V_62 ;
V_63 = V_50 ;
V_64 ++ ;
}
qsort ( V_63 , V_64 , sizeof( * V_50 ) , F_13 ) ;
regfree ( & V_55 ) ;
return 0 ;
}
static T_3 F_20 ( struct V_19 * V_20 , struct V_21 * V_22 )
{
struct V_66 V_67 ;
struct V_51 * V_51 = & V_52 -> V_53 . V_54 ;
struct V_68 * V_7 ;
if ( V_63 == NULL ) {
if ( F_15 () < 0 )
goto V_69;
}
V_67 . V_70 = F_21 ( V_51 , V_22 -> V_71 , V_22 -> V_72 ) ;
F_22 ( V_22 , & V_73 , NULL , V_20 , & V_67 , 16 ) ;
F_23 ( & V_73 ) ;
while ( true ) {
struct V_41 V_33 , * V_74 ;
T_3 V_75 ;
V_7 = F_24 ( & V_73 ) ;
if ( V_7 == NULL )
break;
V_33 . V_44 = V_33 . V_45 = V_7 -> V_76 ;
V_74 = bsearch ( & V_33 , V_63 , V_64 ,
sizeof( V_33 ) , F_14 ) ;
if ( ! V_74 ) {
if ( V_7 -> V_46 )
V_75 = F_25 ( V_7 -> V_46 , V_7 -> V_76 ) ;
else
V_75 = V_7 -> V_76 ;
return V_75 ;
} else
F_26 ( L_11 , V_74 -> V_62 ) ;
F_27 ( & V_73 ) ;
}
V_69:
F_28 ( L_12 V_77 L_13 , V_22 -> V_76 ) ;
return V_22 -> V_76 ;
}
static struct V_78 *
F_29 ( struct V_78 * V_79 , bool V_80 )
{
struct V_6 * * V_7 = & V_81 . V_6 ;
struct V_6 * V_9 = NULL ;
struct V_78 * V_11 ;
while ( * V_7 ) {
T_4 V_34 ;
V_9 = * V_7 ;
V_11 = F_2 ( * V_7 , struct V_78 , V_7 ) ;
V_34 = V_11 -> V_82 - V_79 -> V_82 ;
if ( V_34 < 0 )
V_7 = & V_9 -> V_13 ;
else if ( V_34 > 0 )
V_7 = & V_9 -> V_12 ;
else
return V_11 ;
}
if ( ! V_80 )
return NULL ;
V_11 = F_30 ( sizeof( * V_11 ) ) ;
if ( V_11 != NULL ) {
V_11 -> V_82 = V_79 -> V_82 ;
V_11 -> V_83 = V_79 -> V_83 ;
V_11 -> V_84 = V_79 -> V_84 ;
V_11 -> V_85 = V_79 -> V_85 ;
F_4 ( & V_11 -> V_7 , V_9 , V_7 ) ;
F_5 ( & V_11 -> V_7 , & V_81 ) ;
}
return V_11 ;
}
static struct V_78 * F_31 ( struct V_78 * V_79 )
{
return F_29 ( V_79 , false ) ;
}
static struct V_78 * F_32 ( struct V_78 * V_79 )
{
return F_29 ( V_79 , true ) ;
}
static struct V_78 *
F_33 ( struct V_78 * V_79 , bool V_80 )
{
struct V_6 * * V_7 = & V_86 . V_6 ;
struct V_6 * V_9 = NULL ;
struct V_78 * V_11 ;
struct V_87 * V_88 ;
while ( * V_7 ) {
int V_34 = 0 ;
V_9 = * V_7 ;
V_11 = F_2 ( * V_7 , struct V_78 , V_7 ) ;
F_34 (sort, &page_alloc_sort_input, list) {
V_34 = V_88 -> V_34 ( V_79 , V_11 ) ;
if ( V_34 )
break;
}
if ( V_34 < 0 )
V_7 = & V_9 -> V_13 ;
else if ( V_34 > 0 )
V_7 = & V_9 -> V_12 ;
else
return V_11 ;
}
if ( ! V_80 )
return NULL ;
V_11 = F_30 ( sizeof( * V_11 ) ) ;
if ( V_11 != NULL ) {
V_11 -> V_82 = V_79 -> V_82 ;
V_11 -> V_83 = V_79 -> V_83 ;
V_11 -> V_84 = V_79 -> V_84 ;
V_11 -> V_85 = V_79 -> V_85 ;
F_4 ( & V_11 -> V_7 , V_9 , V_7 ) ;
F_5 ( & V_11 -> V_7 , & V_86 ) ;
}
return V_11 ;
}
static struct V_78 * F_35 ( struct V_78 * V_79 )
{
return F_33 ( V_79 , false ) ;
}
static struct V_78 * F_36 ( struct V_78 * V_79 )
{
return F_33 ( V_79 , true ) ;
}
static struct V_78 *
F_37 ( struct V_78 * V_79 , bool V_80 )
{
struct V_6 * * V_7 = & V_89 . V_6 ;
struct V_6 * V_9 = NULL ;
struct V_78 * V_11 ;
struct V_87 * V_88 ;
while ( * V_7 ) {
int V_34 = 0 ;
V_9 = * V_7 ;
V_11 = F_2 ( * V_7 , struct V_78 , V_7 ) ;
F_34 (sort, &page_caller_sort_input, list) {
V_34 = V_88 -> V_34 ( V_79 , V_11 ) ;
if ( V_34 )
break;
}
if ( V_34 < 0 )
V_7 = & V_9 -> V_13 ;
else if ( V_34 > 0 )
V_7 = & V_9 -> V_12 ;
else
return V_11 ;
}
if ( ! V_80 )
return NULL ;
V_11 = F_30 ( sizeof( * V_11 ) ) ;
if ( V_11 != NULL ) {
V_11 -> V_90 = V_79 -> V_90 ;
V_11 -> V_83 = V_79 -> V_83 ;
V_11 -> V_84 = V_79 -> V_84 ;
V_11 -> V_85 = V_79 -> V_85 ;
F_4 ( & V_11 -> V_7 , V_9 , V_7 ) ;
F_5 ( & V_11 -> V_7 , & V_89 ) ;
}
return V_11 ;
}
static struct V_78 * F_38 ( struct V_78 * V_79 )
{
return F_37 ( V_79 , false ) ;
}
static struct V_78 * F_39 ( struct V_78 * V_79 )
{
return F_37 ( V_79 , true ) ;
}
static bool F_40 ( T_3 V_91 )
{
if ( V_92 && V_91 == - 1UL )
return false ;
if ( ! V_92 && V_91 == 0 )
return false ;
return true ;
}
static int F_41 ( const void * V_39 , const void * V_40 )
{
const struct V_93 * V_42 = V_39 ;
const struct V_93 * V_43 = V_40 ;
return V_42 -> V_94 - V_43 -> V_94 ;
}
static char * F_42 ( char * V_84 )
{
char * V_95 = F_43 ( V_84 ) ;
char * V_96 = NULL ;
char * V_97 , * V_98 = NULL ;
T_5 V_99 = 0 ;
if ( V_95 == NULL )
return NULL ;
V_97 = strtok_r ( V_95 , L_14 , & V_98 ) ;
while ( V_97 ) {
T_5 V_100 ;
char * V_101 ;
const char * V_102 ;
for ( V_100 = 0 ; V_100 < F_44 ( V_103 ) ; V_100 ++ ) {
if ( strcmp ( V_103 [ V_100 ] . V_104 , V_97 ) )
continue;
V_102 = V_103 [ V_100 ] . V_105 ;
V_101 = realloc ( V_96 , V_99 + strlen ( V_102 ) + 2 ) ;
if ( V_101 == NULL ) {
free ( V_96 ) ;
return NULL ;
}
V_96 = V_101 ;
if ( ! V_99 ) {
strcpy ( V_96 , V_102 ) ;
} else {
strcat ( V_96 , L_14 ) ;
strcat ( V_96 , V_102 ) ;
V_99 ++ ;
}
V_99 += strlen ( V_102 ) ;
}
V_97 = strtok_r ( NULL , L_14 , & V_98 ) ;
}
if ( V_106 < V_99 )
V_106 = V_99 ;
free ( V_95 ) ;
return V_96 ;
}
static char * F_45 ( unsigned long V_84 )
{
struct V_93 V_33 = {
. V_94 = V_84 ,
} ;
struct V_93 * V_107 ;
V_107 = bsearch ( & V_33 , V_108 , V_109 , sizeof( * V_108 ) , F_41 ) ;
if ( V_107 )
return V_107 -> V_110 ;
return NULL ;
}
static int F_46 ( struct V_19 * V_20 , struct V_21 * V_22 ,
unsigned int V_84 )
{
struct V_111 V_112 = {
. V_5 = V_22 -> V_5 ,
. V_11 = V_22 -> V_113 ,
. V_114 = V_22 -> V_115 ,
} ;
struct V_116 V_117 ;
char * V_97 , * V_98 = NULL ;
if ( V_109 ) {
struct V_93 V_33 = {
. V_94 = V_84 ,
} ;
if ( bsearch ( & V_33 , V_108 , V_109 , sizeof( * V_108 ) , F_41 ) )
return 0 ;
}
F_47 ( & V_117 ) ;
F_48 ( & V_117 , V_20 -> V_118 , & V_112 ) ;
V_97 = strtok_r ( V_117 . V_119 , L_15 , & V_98 ) ;
while ( V_97 ) {
if ( ! strncmp ( V_97 , L_16 , 10 ) ) {
struct V_93 * V_101 ;
V_101 = realloc ( V_108 , ( V_109 + 1 ) * sizeof( * V_108 ) ) ;
if ( V_101 == NULL )
return - V_65 ;
V_108 = V_101 ;
V_101 += V_109 ++ ;
V_101 -> V_94 = V_84 ;
V_101 -> V_120 = F_43 ( V_97 + 10 ) ;
V_101 -> V_110 = F_42 ( V_97 + 10 ) ;
if ( ! V_101 -> V_120 || ! V_101 -> V_110 )
return - V_65 ;
qsort ( V_108 , V_109 , sizeof( * V_108 ) , F_41 ) ;
}
V_97 = strtok_r ( NULL , L_15 , & V_98 ) ;
}
F_49 ( & V_117 ) ;
return 0 ;
}
static int F_50 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
T_3 V_82 ;
unsigned int V_83 = F_8 ( V_20 , V_22 , L_17 ) ;
unsigned int V_84 = F_8 ( V_20 , V_22 , L_18 ) ;
unsigned int V_85 = F_8 ( V_20 , V_22 ,
L_19 ) ;
T_3 V_121 = V_122 << V_83 ;
T_3 V_90 ;
struct V_78 * V_79 ;
struct V_78 V_123 = {
. V_83 = V_83 ,
. V_84 = V_84 ,
. V_85 = V_85 ,
} ;
if ( V_92 )
V_82 = F_8 ( V_20 , V_22 , L_20 ) ;
else
V_82 = F_8 ( V_20 , V_22 , L_21 ) ;
V_124 ++ ;
V_125 += V_121 ;
if ( ! F_40 ( V_82 ) ) {
V_126 ++ ;
V_127 += V_121 ;
return 0 ;
}
if ( F_46 ( V_20 , V_22 , V_84 ) < 0 )
return - 1 ;
V_90 = F_20 ( V_20 , V_22 ) ;
V_123 . V_82 = V_82 ;
V_79 = F_32 ( & V_123 ) ;
if ( V_79 == NULL )
return - V_65 ;
V_79 -> V_128 ++ ;
V_79 -> V_129 += V_121 ;
V_79 -> V_90 = V_90 ;
if ( ! V_130 ) {
V_79 = F_36 ( & V_123 ) ;
if ( V_79 == NULL )
return - V_65 ;
V_79 -> V_128 ++ ;
V_79 -> V_129 += V_121 ;
V_79 -> V_90 = V_90 ;
}
V_123 . V_90 = V_90 ;
V_79 = F_39 ( & V_123 ) ;
if ( V_79 == NULL )
return - V_65 ;
V_79 -> V_128 ++ ;
V_79 -> V_129 += V_121 ;
V_131 [ V_83 ] [ V_85 ] ++ ;
return 0 ;
}
static int F_51 ( struct V_19 * V_20 ,
struct V_21 * V_22 )
{
T_3 V_82 ;
unsigned int V_83 = F_8 ( V_20 , V_22 , L_17 ) ;
T_3 V_121 = V_122 << V_83 ;
struct V_78 * V_79 ;
struct V_78 V_123 = {
. V_83 = V_83 ,
} ;
if ( V_92 )
V_82 = F_8 ( V_20 , V_22 , L_20 ) ;
else
V_82 = F_8 ( V_20 , V_22 , L_21 ) ;
V_132 ++ ;
V_133 += V_121 ;
V_123 . V_82 = V_82 ;
V_79 = F_31 ( & V_123 ) ;
if ( V_79 == NULL ) {
F_28 ( L_22 V_77 L_23 ,
V_82 , V_83 ) ;
V_134 ++ ;
V_135 += V_121 ;
return 0 ;
}
V_123 . V_84 = V_79 -> V_84 ;
V_123 . V_85 = V_79 -> V_85 ;
V_123 . V_90 = V_79 -> V_90 ;
F_52 ( & V_79 -> V_7 , & V_81 ) ;
free ( V_79 ) ;
if ( V_130 ) {
V_131 [ V_123 . V_83 ] [ V_123 . V_85 ] -- ;
} else {
V_79 = F_35 ( & V_123 ) ;
if ( V_79 == NULL )
return - V_65 ;
V_79 -> V_136 ++ ;
V_79 -> V_137 += V_121 ;
}
V_79 = F_38 ( & V_123 ) ;
if ( V_79 == NULL )
return - V_61 ;
V_79 -> V_136 ++ ;
V_79 -> V_137 += V_121 ;
if ( V_130 ) {
V_79 -> V_128 -- ;
V_79 -> V_129 -= V_121 ;
if ( V_79 -> V_128 == 0 ) {
F_52 ( & V_79 -> V_7 , & V_89 ) ;
free ( V_79 ) ;
}
}
return 0 ;
}
static int F_53 ( struct V_138 * T_6 V_139 ,
union V_140 * V_141 ,
struct V_21 * V_22 ,
struct V_19 * V_20 ,
struct V_51 * V_51 )
{
int V_58 = 0 ;
struct V_70 * V_70 = F_21 ( V_51 , V_22 -> V_71 ,
V_22 -> V_72 ) ;
if ( V_70 == NULL ) {
F_19 ( L_24 ,
V_141 -> V_142 . type ) ;
return - 1 ;
}
F_54 ( L_25 , F_55 ( V_70 ) , V_70 -> V_72 ) ;
if ( V_20 -> V_143 != NULL ) {
T_7 V_144 = V_20 -> V_143 ;
V_58 = V_144 ( V_20 , V_22 ) ;
}
F_56 ( V_70 ) ;
return V_58 ;
}
static double F_57 ( unsigned long V_145 , unsigned long V_146 )
{
if ( V_146 == 0 )
return 0.0 ;
else
return 100.0 - ( 100.0 * V_145 / V_146 ) ;
}
static void F_58 ( struct V_30 * V_31 ,
struct V_147 * V_148 ,
int V_149 , int V_150 )
{
struct V_6 * V_151 ;
struct V_51 * V_51 = & V_148 -> V_53 . V_54 ;
printf ( L_26 , V_152 ) ;
printf ( L_27 , V_150 ? L_28 : L_29 ) ;
printf ( L_30 ) ;
printf ( L_26 , V_152 ) ;
V_151 = F_59 ( V_31 ) ;
while ( V_151 && V_149 -- ) {
struct V_10 * V_11 = F_2 ( V_151 , struct V_10 ,
V_7 ) ;
struct V_48 * V_49 = NULL ;
struct V_46 * V_46 ;
char V_153 [ V_59 ] ;
T_3 V_75 ;
if ( V_150 ) {
V_75 = V_11 -> V_1 ;
if ( ! V_154 )
V_49 = F_60 ( V_51 , V_75 , & V_46 ) ;
} else
V_75 = V_11 -> V_2 ;
if ( V_49 != NULL )
snprintf ( V_153 , sizeof( V_153 ) , L_31 V_77 L_32 , V_49 -> V_62 ,
V_75 - V_46 -> V_155 ( V_46 , V_49 -> V_44 ) ) ;
else
snprintf ( V_153 , sizeof( V_153 ) , L_33 V_77 L_32 , V_75 ) ;
printf ( L_27 , V_153 ) ;
printf ( L_34 ,
( unsigned long long ) V_11 -> V_4 ,
( unsigned long ) V_11 -> V_4 / V_11 -> V_14 ,
( unsigned long long ) V_11 -> V_3 ,
( unsigned long ) V_11 -> V_3 / V_11 -> V_14 ,
( unsigned long ) V_11 -> V_14 ,
( unsigned long ) V_11 -> V_16 ,
F_57 ( V_11 -> V_3 , V_11 -> V_4 ) ) ;
V_151 = F_61 ( V_151 ) ;
}
if ( V_149 == - 1 )
printf ( L_35 ) ;
printf ( L_26 , V_152 ) ;
}
static void F_62 ( struct V_147 * V_148 , int V_149 )
{
struct V_6 * V_151 = F_59 ( & V_156 ) ;
struct V_51 * V_51 = & V_148 -> V_53 . V_54 ;
const char * V_157 ;
int V_158 = F_63 ( strlen ( L_36 ) , V_106 ) ;
printf ( L_37 , V_152 ) ;
printf ( L_38 ,
V_92 ? L_39 : L_40 , V_130 ? L_41 : L_42 ,
V_158 , L_36 ) ;
printf ( L_26 , V_152 ) ;
if ( V_92 )
V_157 = L_43 ;
else
V_157 = L_44 ;
while ( V_151 && V_149 -- ) {
struct V_78 * V_11 ;
struct V_48 * V_49 ;
struct V_46 * V_46 ;
char V_153 [ 32 ] ;
char * V_74 = V_153 ;
V_11 = F_2 ( V_151 , struct V_78 , V_7 ) ;
V_49 = F_60 ( V_51 , V_11 -> V_90 , & V_46 ) ;
if ( V_49 && V_49 -> V_62 )
V_74 = V_49 -> V_62 ;
else
F_64 ( V_153 , sizeof( V_153 ) , L_45 V_77 , V_11 -> V_90 ) ;
printf ( V_157 , ( unsigned long long ) V_11 -> V_82 ,
( unsigned long long ) V_11 -> V_129 / 1024 ,
V_11 -> V_128 , V_11 -> V_83 ,
V_159 [ V_11 -> V_85 ] ,
V_158 , F_45 ( V_11 -> V_84 ) , V_74 ) ;
V_151 = F_61 ( V_151 ) ;
}
if ( V_149 == - 1 ) {
printf ( L_46 ,
V_158 , L_47 ) ;
}
printf ( L_26 , V_152 ) ;
}
static void F_65 ( struct V_147 * V_148 , int V_149 )
{
struct V_6 * V_151 = F_59 ( & V_160 ) ;
struct V_51 * V_51 = & V_148 -> V_53 . V_54 ;
int V_158 = F_63 ( strlen ( L_36 ) , V_106 ) ;
printf ( L_37 , V_152 ) ;
printf ( L_48 ,
V_130 ? L_41 : L_42 , V_158 , L_36 ) ;
printf ( L_26 , V_152 ) ;
while ( V_151 && V_149 -- ) {
struct V_78 * V_11 ;
struct V_48 * V_49 ;
struct V_46 * V_46 ;
char V_153 [ 32 ] ;
char * V_74 = V_153 ;
V_11 = F_2 ( V_151 , struct V_78 , V_7 ) ;
V_49 = F_60 ( V_51 , V_11 -> V_90 , & V_46 ) ;
if ( V_49 && V_49 -> V_62 )
V_74 = V_49 -> V_62 ;
else
F_64 ( V_153 , sizeof( V_153 ) , L_45 V_77 , V_11 -> V_90 ) ;
printf ( L_49 ,
( unsigned long long ) V_11 -> V_129 / 1024 ,
V_11 -> V_128 , V_11 -> V_83 ,
V_159 [ V_11 -> V_85 ] ,
V_158 , F_45 ( V_11 -> V_84 ) , V_74 ) ;
V_151 = F_61 ( V_151 ) ;
}
if ( V_149 == - 1 ) {
printf ( L_50 ,
V_158 , L_47 ) ;
}
printf ( L_26 , V_152 ) ;
}
static void F_66 ( void )
{
int V_100 ;
printf ( L_51 ) ;
printf ( L_52 ) ;
printf ( L_53 ) ;
for ( V_100 = 0 ; V_100 < V_109 ; V_100 ++ ) {
printf ( L_54 , V_108 [ V_100 ] . V_94 ,
( int ) V_106 , V_108 [ V_100 ] . V_110 ,
V_108 [ V_100 ] . V_120 ) ;
}
}
static void F_67 ( void )
{
printf ( L_55 ) ;
printf ( L_56 ) ;
printf ( L_57 , V_23 ) ;
printf ( L_58 , V_24 ) ;
printf ( L_59 ,
V_24 - V_23 ) ;
printf ( L_60 ,
F_57 ( V_23 , V_24 ) ) ;
printf ( L_61 , V_29 , V_25 ) ;
}
static void F_68 ( void )
{
int V_161 , V_162 ;
T_3 V_163 = V_132 - V_134 ;
T_3 V_164 = V_133 - V_135 ;
printf ( L_62 ) ;
printf ( L_56 ) ;
printf ( L_63 V_165 L_64 , L_65 ,
V_124 , V_125 / 1024 ) ;
printf ( L_63 V_165 L_64 , L_66 ,
V_132 , V_133 / 1024 ) ;
printf ( L_13 ) ;
printf ( L_67 V_165 L_68 V_165 L_64 , L_69 ,
V_163 , ( V_164 ) / 1024 ) ;
printf ( L_67 V_165 L_68 V_165 L_64 , L_70 ,
V_124 - V_163 ,
( V_125 - V_164 ) / 1024 ) ;
printf ( L_63 V_165 L_64 , L_71 ,
V_134 , V_135 / 1024 ) ;
printf ( L_13 ) ;
printf ( L_63 V_165 L_64 , L_72 ,
V_126 , V_127 / 1024 ) ;
printf ( L_13 ) ;
printf ( L_73 , L_74 , L_75 ,
L_76 , L_77 , L_78 , L_79 ) ;
printf ( L_80 , V_152 ,
V_152 , V_152 , V_152 ,
V_152 , V_152 ) ;
for ( V_161 = 0 ; V_161 < V_166 ; V_161 ++ ) {
printf ( L_81 , V_161 ) ;
for ( V_162 = 0 ; V_162 < V_167 - 1 ; V_162 ++ ) {
if ( V_131 [ V_161 ] [ V_162 ] )
printf ( L_82 , V_131 [ V_161 ] [ V_162 ] ) ;
else
printf ( L_83 , '.' ) ;
}
printf ( L_13 ) ;
}
}
static void F_69 ( struct V_147 * V_148 )
{
if ( V_168 )
F_58 ( & V_169 , V_148 , V_170 , 1 ) ;
if ( V_171 )
F_58 ( & V_172 , V_148 , V_173 , 0 ) ;
F_67 () ;
}
static void F_70 ( struct V_147 * V_148 )
{
if ( V_168 || V_171 )
F_66 () ;
if ( V_168 )
F_65 ( V_148 , V_170 ) ;
if ( V_171 )
F_62 ( V_148 , V_173 ) ;
F_68 () ;
}
static void F_71 ( struct V_147 * V_148 )
{
if ( V_174 )
F_69 ( V_148 ) ;
if ( V_175 )
F_70 ( V_148 ) ;
}
static void F_72 ( struct V_30 * V_31 , struct V_10 * V_11 ,
struct V_176 * V_177 )
{
struct V_6 * * V_101 = & ( V_31 -> V_6 ) ;
struct V_6 * V_9 = NULL ;
struct V_87 * V_88 ;
while ( * V_101 ) {
struct V_10 * V_123 ;
int V_34 = 0 ;
V_123 = F_2 ( * V_101 , struct V_10 , V_7 ) ;
V_9 = * V_101 ;
F_34 (sort, sort_list, list) {
V_34 = V_88 -> V_34 ( V_11 , V_123 ) ;
if ( V_34 )
break;
}
if ( V_34 > 0 )
V_101 = & ( ( * V_101 ) -> V_13 ) ;
else
V_101 = & ( ( * V_101 ) -> V_12 ) ;
}
F_4 ( & V_11 -> V_7 , V_9 , V_101 ) ;
F_5 ( & V_11 -> V_7 , V_31 ) ;
}
static void F_73 ( struct V_30 * V_31 , struct V_30 * V_178 ,
struct V_176 * V_177 )
{
struct V_6 * V_7 ;
struct V_10 * V_11 ;
for (; ; ) {
V_7 = F_59 ( V_31 ) ;
if ( ! V_7 )
break;
F_52 ( V_7 , V_31 ) ;
V_11 = F_2 ( V_7 , struct V_10 , V_7 ) ;
F_72 ( V_178 , V_11 , V_177 ) ;
}
}
static void F_74 ( struct V_30 * V_31 , struct V_78 * V_11 ,
struct V_176 * V_177 )
{
struct V_6 * * V_101 = & V_31 -> V_6 ;
struct V_6 * V_9 = NULL ;
struct V_87 * V_88 ;
while ( * V_101 ) {
struct V_78 * V_123 ;
int V_34 = 0 ;
V_123 = F_2 ( * V_101 , struct V_78 , V_7 ) ;
V_9 = * V_101 ;
F_34 (sort, sort_list, list) {
V_34 = V_88 -> V_34 ( V_11 , V_123 ) ;
if ( V_34 )
break;
}
if ( V_34 > 0 )
V_101 = & V_9 -> V_13 ;
else
V_101 = & V_9 -> V_12 ;
}
F_4 ( & V_11 -> V_7 , V_9 , V_101 ) ;
F_5 ( & V_11 -> V_7 , V_31 ) ;
}
static void F_75 ( struct V_30 * V_31 , struct V_30 * V_178 ,
struct V_176 * V_177 )
{
struct V_6 * V_7 ;
struct V_78 * V_11 ;
for (; ; ) {
V_7 = F_59 ( V_31 ) ;
if ( ! V_7 )
break;
F_52 ( V_7 , V_31 ) ;
V_11 = F_2 ( V_7 , struct V_78 , V_7 ) ;
F_74 ( V_178 , V_11 , V_177 ) ;
}
}
static void F_76 ( void )
{
if ( V_174 ) {
F_73 ( & V_8 , & V_172 ,
& V_179 ) ;
F_73 ( & V_18 , & V_169 ,
& V_180 ) ;
}
if ( V_175 ) {
if ( V_130 )
F_75 ( & V_81 , & V_156 ,
& V_181 ) ;
else
F_75 ( & V_86 , & V_156 ,
& V_181 ) ;
F_75 ( & V_89 , & V_160 ,
& V_182 ) ;
}
}
static int F_77 ( struct V_147 * V_148 )
{
int V_58 = - V_60 ;
struct V_19 * V_20 ;
const struct V_183 V_184 [] = {
{ L_84 , F_7 , } ,
{ L_85 , F_7 , } ,
{ L_86 , F_9 , } ,
{ L_87 , F_9 , } ,
{ L_88 , F_12 , } ,
{ L_89 , F_12 , } ,
{ L_90 , F_50 , } ,
{ L_91 , F_51 , } ,
} ;
if ( ! F_78 ( V_148 , L_92 ) )
goto V_69;
if ( F_79 ( V_148 , V_184 ) ) {
F_3 ( L_93 ) ;
goto V_69;
}
F_80 (session->evlist, evsel) {
if ( ! strcmp ( F_81 ( V_20 ) , L_90 ) &&
F_82 ( V_20 , L_20 ) ) {
V_92 = true ;
break;
}
}
F_83 () ;
V_58 = F_84 ( V_148 ) ;
if ( V_58 != 0 ) {
F_3 ( L_94 , V_58 ) ;
goto V_69;
}
F_76 () ;
F_71 ( V_148 ) ;
V_69:
return V_58 ;
}
static int V_37 ( void * V_39 , void * V_40 )
{
struct V_10 * V_185 = V_39 ;
struct V_10 * V_186 = V_40 ;
if ( V_185 -> V_2 < V_186 -> V_2 )
return - 1 ;
else if ( V_185 -> V_2 > V_186 -> V_2 )
return 1 ;
return 0 ;
}
static int V_38 ( void * V_39 , void * V_40 )
{
struct V_10 * V_185 = V_39 ;
struct V_10 * V_186 = V_40 ;
if ( V_185 -> V_1 < V_186 -> V_1 )
return - 1 ;
else if ( V_185 -> V_1 > V_186 -> V_1 )
return 1 ;
return 0 ;
}
static int F_85 ( void * V_39 , void * V_40 )
{
struct V_10 * V_185 = V_39 ;
struct V_10 * V_186 = V_40 ;
if ( V_185 -> V_14 < V_186 -> V_14 )
return - 1 ;
else if ( V_185 -> V_14 > V_186 -> V_14 )
return 1 ;
return 0 ;
}
static int F_86 ( void * V_39 , void * V_40 )
{
struct V_10 * V_185 = V_39 ;
struct V_10 * V_186 = V_40 ;
if ( V_185 -> V_4 < V_186 -> V_4 )
return - 1 ;
else if ( V_185 -> V_4 > V_186 -> V_4 )
return 1 ;
return 0 ;
}
static int F_87 ( void * V_39 , void * V_40 )
{
double V_187 , V_188 ;
struct V_10 * V_185 = V_39 ;
struct V_10 * V_186 = V_40 ;
V_187 = F_57 ( V_185 -> V_3 , V_185 -> V_4 ) ;
V_188 = F_57 ( V_186 -> V_3 , V_186 -> V_4 ) ;
if ( V_187 < V_188 )
return - 1 ;
else if ( V_187 > V_188 )
return 1 ;
return 0 ;
}
static int F_88 ( void * V_39 , void * V_40 )
{
struct V_10 * V_185 = V_39 ;
struct V_10 * V_186 = V_40 ;
if ( V_185 -> V_16 < V_186 -> V_16 )
return - 1 ;
else if ( V_185 -> V_16 > V_186 -> V_16 )
return 1 ;
return 0 ;
}
static int F_89 ( void * V_39 , void * V_40 )
{
struct V_78 * V_185 = V_39 ;
struct V_78 * V_186 = V_40 ;
if ( V_185 -> V_82 < V_186 -> V_82 )
return - 1 ;
else if ( V_185 -> V_82 > V_186 -> V_82 )
return 1 ;
return 0 ;
}
static int F_90 ( void * V_39 , void * V_40 )
{
struct V_78 * V_185 = V_39 ;
struct V_78 * V_186 = V_40 ;
if ( V_185 -> V_90 < V_186 -> V_90 )
return - 1 ;
else if ( V_185 -> V_90 > V_186 -> V_90 )
return 1 ;
return 0 ;
}
static int F_91 ( void * V_39 , void * V_40 )
{
struct V_78 * V_185 = V_39 ;
struct V_78 * V_186 = V_40 ;
if ( V_185 -> V_128 < V_186 -> V_128 )
return - 1 ;
else if ( V_185 -> V_128 > V_186 -> V_128 )
return 1 ;
return 0 ;
}
static int F_92 ( void * V_39 , void * V_40 )
{
struct V_78 * V_185 = V_39 ;
struct V_78 * V_186 = V_40 ;
if ( V_185 -> V_129 < V_186 -> V_129 )
return - 1 ;
else if ( V_185 -> V_129 > V_186 -> V_129 )
return 1 ;
return 0 ;
}
static int F_93 ( void * V_39 , void * V_40 )
{
struct V_78 * V_185 = V_39 ;
struct V_78 * V_186 = V_40 ;
if ( V_185 -> V_83 < V_186 -> V_83 )
return - 1 ;
else if ( V_185 -> V_83 > V_186 -> V_83 )
return 1 ;
return 0 ;
}
static int F_94 ( void * V_39 , void * V_40 )
{
struct V_78 * V_185 = V_39 ;
struct V_78 * V_186 = V_40 ;
if ( V_185 -> V_85 == - 1U )
return 0 ;
if ( V_185 -> V_85 < V_186 -> V_85 )
return - 1 ;
else if ( V_185 -> V_85 > V_186 -> V_85 )
return 1 ;
return 0 ;
}
static int F_95 ( void * V_39 , void * V_40 )
{
struct V_78 * V_185 = V_39 ;
struct V_78 * V_186 = V_40 ;
if ( V_185 -> V_84 == - 1U )
return 0 ;
if ( V_185 -> V_84 < V_186 -> V_84 )
return - 1 ;
else if ( V_185 -> V_84 > V_186 -> V_84 )
return 1 ;
return 0 ;
}
static int F_96 ( const char * V_189 , struct V_176 * V_190 )
{
struct V_87 * V_88 ;
int V_100 ;
for ( V_100 = 0 ; V_100 < ( int ) F_44 ( V_191 ) ; V_100 ++ ) {
if ( ! strcmp ( V_191 [ V_100 ] -> V_62 , V_189 ) ) {
V_88 = F_97 ( V_191 [ V_100 ] , sizeof( * V_191 [ V_100 ] ) ) ;
if ( ! V_88 ) {
F_3 ( L_95 , V_15 ) ;
return - 1 ;
}
F_98 ( & V_88 -> V_190 , V_190 ) ;
return 0 ;
}
}
return - 1 ;
}
static int F_99 ( const char * V_189 , struct V_176 * V_190 )
{
struct V_87 * V_88 ;
int V_100 ;
for ( V_100 = 0 ; V_100 < ( int ) F_44 ( V_192 ) ; V_100 ++ ) {
if ( ! strcmp ( V_192 [ V_100 ] -> V_62 , V_189 ) ) {
V_88 = F_97 ( V_192 [ V_100 ] , sizeof( * V_192 [ V_100 ] ) ) ;
if ( ! V_88 ) {
F_3 ( L_95 , V_15 ) ;
return - 1 ;
}
F_98 ( & V_88 -> V_190 , V_190 ) ;
return 0 ;
}
}
return - 1 ;
}
static int F_100 ( struct V_176 * V_177 , const char * V_193 )
{
char * V_189 ;
char * V_97 = F_43 ( V_193 ) ;
char * V_98 = V_97 ;
if ( ! V_97 ) {
F_3 ( L_96 , V_15 ) ;
return - 1 ;
}
while ( true ) {
V_189 = F_101 ( & V_98 , L_97 ) ;
if ( ! V_189 )
break;
if ( F_96 ( V_189 , V_177 ) < 0 ) {
error ( L_98 , V_189 ) ;
free ( V_97 ) ;
return - 1 ;
}
}
free ( V_97 ) ;
return 0 ;
}
static int F_102 ( struct V_176 * V_177 , const char * V_193 )
{
char * V_189 ;
char * V_97 = F_43 ( V_193 ) ;
char * V_98 = V_97 ;
if ( ! V_97 ) {
F_3 ( L_96 , V_15 ) ;
return - 1 ;
}
while ( true ) {
V_189 = F_101 ( & V_98 , L_97 ) ;
if ( ! V_189 )
break;
if ( F_99 ( V_189 , V_177 ) < 0 ) {
error ( L_99 , V_189 ) ;
free ( V_97 ) ;
return - 1 ;
}
}
free ( V_97 ) ;
return 0 ;
}
static int F_103 ( const struct V_194 * T_8 V_139 ,
const char * V_193 , int T_9 V_139 )
{
if ( ! V_193 )
return - 1 ;
if ( V_175 > V_174 ||
( V_175 == 0 && V_174 == 0 && V_195 == V_196 ) ) {
if ( V_168 > V_171 )
return F_102 ( & V_182 , V_193 ) ;
else
return F_102 ( & V_181 , V_193 ) ;
} else {
if ( V_168 > V_171 )
return F_100 ( & V_180 , V_193 ) ;
else
return F_100 ( & V_179 , V_193 ) ;
}
return 0 ;
}
static int F_104 ( const struct V_194 * T_8 V_139 ,
const char * V_193 V_139 ,
int T_9 V_139 )
{
V_168 = ( V_171 + 1 ) ;
return 0 ;
}
static int F_105 ( const struct V_194 * T_8 V_139 ,
const char * V_193 V_139 ,
int T_9 V_139 )
{
V_171 = ( V_168 + 1 ) ;
return 0 ;
}
static int F_106 ( const struct V_194 * T_8 V_139 ,
const char * V_193 V_139 ,
int T_9 V_139 )
{
V_174 = ( V_175 + 1 ) ;
return 0 ;
}
static int F_107 ( const struct V_194 * T_8 V_139 ,
const char * V_193 V_139 ,
int T_9 V_139 )
{
V_175 = ( V_174 + 1 ) ;
return 0 ;
}
static int F_108 ( const struct V_194 * T_8 V_139 ,
const char * V_193 , int T_9 V_139 )
{
int V_197 ;
if ( ! V_193 )
return - 1 ;
V_197 = strtoul ( V_193 , NULL , 10 ) ;
if ( V_168 > V_171 )
V_170 = V_197 ;
else
V_173 = V_197 ;
return 0 ;
}
static int F_109 ( int V_198 , const char * * V_199 )
{
const char * const V_200 [] = {
L_100 , L_101 , L_102 , L_103 , L_104 ,
} ;
const char * const V_201 [] = {
L_105 , L_84 ,
L_105 , L_86 ,
L_105 , L_88 ,
L_105 , L_85 ,
L_105 , L_87 ,
L_105 , L_89 ,
} ;
const char * const V_202 [] = {
L_105 , L_90 ,
L_105 , L_91 ,
} ;
unsigned int V_203 , V_100 , V_204 ;
const char * * V_205 ;
V_203 = F_44 ( V_200 ) + V_198 - 1 ;
if ( V_174 )
V_203 += F_44 ( V_201 ) ;
if ( V_175 )
V_203 += F_44 ( V_202 ) + 1 ;
V_205 = calloc ( V_203 + 1 , sizeof( char * ) ) ;
if ( V_205 == NULL )
return - V_65 ;
for ( V_100 = 0 ; V_100 < F_44 ( V_200 ) ; V_100 ++ )
V_205 [ V_100 ] = F_43 ( V_200 [ V_100 ] ) ;
if ( V_174 ) {
for ( V_204 = 0 ; V_204 < F_44 ( V_201 ) ; V_204 ++ , V_100 ++ )
V_205 [ V_100 ] = F_43 ( V_201 [ V_204 ] ) ;
}
if ( V_175 ) {
V_205 [ V_100 ++ ] = F_43 ( L_106 ) ;
for ( V_204 = 0 ; V_204 < F_44 ( V_202 ) ; V_204 ++ , V_100 ++ )
V_205 [ V_100 ] = F_43 ( V_202 [ V_204 ] ) ;
}
for ( V_204 = 1 ; V_204 < ( unsigned int ) V_198 ; V_204 ++ , V_100 ++ )
V_205 [ V_100 ] = V_199 [ V_204 ] ;
return F_110 ( V_100 , V_205 , NULL ) ;
}
static int F_111 ( const char * V_206 , const char * V_207 , void * T_10 V_139 )
{
if ( ! strcmp ( V_206 , L_107 ) ) {
if ( ! strcmp ( V_207 , L_108 ) )
V_195 = V_208 ;
else if ( ! strcmp ( V_207 , L_21 ) )
V_195 = V_196 ;
else
F_3 ( L_109 ,
V_207 ) ;
return 0 ;
}
return 0 ;
}
int F_112 ( int V_198 , const char * * V_199 , const char * T_11 V_139 )
{
const char * const V_209 = L_110 ;
const char * const V_210 = L_111 ;
struct V_211 V_212 = {
. V_213 = V_214 ,
} ;
const struct V_194 V_215 [] = {
F_113 ( 'i' , L_112 , & V_216 , L_113 , L_114 ) ,
F_114 ( 'v' , L_115 , & V_217 ,
L_116 ) ,
F_115 ( 0 , L_117 , NULL , NULL ,
L_118 , F_104 ) ,
F_115 ( 0 , L_119 , NULL , NULL ,
L_120 , F_105 ) ,
F_116 ( 's' , L_121 , NULL , L_122 ,
L_123
L_124 , F_103 ) ,
F_116 ( 'l' , L_125 , NULL , L_126 , L_127 , F_108 ) ,
F_117 ( 0 , L_128 , & V_154 , L_129 ) ,
F_117 ( 'f' , L_130 , & V_212 . V_218 , L_131 ) ,
F_115 ( 0 , L_108 , NULL , NULL , L_132 ,
F_106 ) ,
F_115 ( 0 , L_21 , NULL , NULL , L_133 ,
F_107 ) ,
F_117 ( 0 , L_134 , & V_130 , L_135 ) ,
F_118 ()
} ;
const char * const V_219 [] = { L_100 , L_136 , NULL } ;
const char * V_220 [] = {
NULL ,
NULL
} ;
struct V_147 * V_148 ;
int V_26 = - 1 ;
const char V_221 [] = L_137 ;
F_119 ( F_111 , NULL ) ;
V_198 = F_120 ( V_198 , V_199 , V_215 ,
V_219 , V_220 , 0 ) ;
if ( ! V_198 )
F_121 ( V_220 , V_215 ) ;
if ( V_174 == 0 && V_175 == 0 ) {
if ( V_195 == V_208 )
V_174 = 1 ;
else
V_175 = 1 ;
}
if ( ! strncmp ( V_199 [ 0 ] , L_138 , 3 ) ) {
F_122 ( NULL ) ;
return F_109 ( V_198 , V_199 ) ;
}
V_212 . V_222 = V_216 ;
V_52 = V_148 = F_123 ( & V_212 , false , & V_223 ) ;
if ( V_148 == NULL )
return - 1 ;
if ( V_174 ) {
if ( ! F_124 ( V_148 -> V_224 ,
L_84 ) ) {
F_3 ( V_221 , L_108 , L_108 ) ;
goto V_225;
}
}
if ( V_175 ) {
struct V_19 * V_20 ;
V_20 = F_124 ( V_148 -> V_224 ,
L_90 ) ;
if ( V_20 == NULL ) {
F_3 ( V_221 , L_21 , L_21 ) ;
goto V_225;
}
V_122 = F_125 ( V_20 -> V_118 -> V_226 ) ;
V_227 . V_228 = true ;
}
F_122 ( & V_148 -> V_142 . V_229 ) ;
if ( ! strcmp ( V_199 [ 0 ] , L_136 ) ) {
setlocale ( V_230 , L_32 ) ;
if ( F_126 () )
goto V_225;
if ( F_127 ( & V_180 ) )
F_100 ( & V_180 , V_209 ) ;
if ( F_127 ( & V_179 ) )
F_100 ( & V_179 , V_209 ) ;
if ( F_127 ( & V_182 ) )
F_102 ( & V_182 , V_210 ) ;
if ( F_127 ( & V_181 ) )
F_102 ( & V_181 , V_210 ) ;
if ( V_175 ) {
F_102 ( & V_231 ,
L_139 ) ;
F_102 ( & V_232 ,
L_140 ) ;
}
V_26 = F_77 ( V_148 ) ;
} else
F_121 ( V_220 , V_215 ) ;
V_225:
F_128 ( V_148 ) ;
return V_26 ;
}
