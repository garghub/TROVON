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
V_11 -> V_18 = V_4 ;
return 0 ;
}
static int F_6 ( unsigned long V_1 ,
int V_3 , int V_4 )
{
struct V_6 * * V_7 = & V_19 . V_6 ;
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
F_5 ( & V_11 -> V_7 , & V_19 ) ;
}
return 0 ;
}
static int F_7 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
unsigned long V_2 = F_8 ( V_21 , V_23 , L_2 ) ,
V_1 = F_8 ( V_21 , V_23 , L_3 ) ;
int V_3 = F_8 ( V_21 , V_23 , L_4 ) ,
V_4 = F_8 ( V_21 , V_23 , L_5 ) ;
if ( F_1 ( V_1 , V_2 , V_3 , V_4 , V_23 -> V_5 ) ||
F_6 ( V_1 , V_3 , V_4 ) )
return - 1 ;
V_24 += V_3 ;
V_25 += V_4 ;
V_26 ++ ;
return 0 ;
}
static int F_9 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
int V_27 = F_7 ( V_21 , V_23 ) ;
if ( ! V_27 ) {
int V_28 = F_10 ( V_23 -> V_5 ) ,
V_29 = F_8 ( V_21 , V_23 , L_6 ) ;
if ( V_28 != V_29 )
V_30 ++ ;
}
return V_27 ;
}
static struct V_10 * F_11 ( unsigned long V_2 ,
unsigned long V_1 ,
struct V_31 * V_32 ,
T_1 V_33 )
{
struct V_6 * V_7 = V_32 -> V_6 ;
struct V_10 V_34 = { . V_2 = V_2 , . V_1 = V_1 } ;
while ( V_7 ) {
struct V_10 * V_11 ;
int V_35 ;
V_11 = F_2 ( V_7 , struct V_10 , V_7 ) ;
V_35 = V_33 ( & V_34 , V_11 ) ;
if ( V_35 < 0 )
V_7 = V_7 -> V_13 ;
else if ( V_35 > 0 )
V_7 = V_7 -> V_12 ;
else
return V_11 ;
}
return NULL ;
}
static int F_12 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
unsigned long V_2 = F_8 ( V_21 , V_23 , L_2 ) ;
struct V_10 * V_36 , * V_37 ;
V_36 = F_11 ( V_2 , 0 , & V_8 , V_38 ) ;
if ( ! V_36 )
return 0 ;
V_39 += V_36 -> V_18 ;
if ( ( short ) V_23 -> V_5 != V_36 -> V_17 ) {
V_36 -> V_16 ++ ;
V_37 = F_11 ( 0 , V_36 -> V_1 ,
& V_19 ,
V_40 ) ;
if ( ! V_37 )
return - 1 ;
V_37 -> V_16 ++ ;
}
V_36 -> V_17 = - 1 ;
return 0 ;
}
static int F_13 ( const void * V_41 , const void * V_42 )
{
const struct V_43 * V_44 = V_41 ;
const struct V_43 * V_45 = V_42 ;
if ( V_44 -> V_46 > V_45 -> V_46 )
return 1 ;
else
return - 1 ;
}
static int F_14 ( const void * V_41 , const void * V_42 )
{
const struct V_43 * V_44 = V_41 ;
const struct V_43 * V_45 = V_42 ;
if ( V_45 -> V_46 <= V_44 -> V_46 && V_44 -> V_47 < V_45 -> V_47 )
return 0 ;
if ( V_44 -> V_46 > V_45 -> V_46 )
return 1 ;
else
return - 1 ;
}
static int F_15 ( void )
{
int V_27 ;
struct V_48 * V_49 ;
struct V_50 * V_51 ;
struct V_6 * V_7 ;
struct V_43 * V_52 ;
struct V_53 * V_53 = & V_54 -> V_55 . V_56 ;
T_2 V_57 ;
const char V_58 [] = L_7 ;
V_27 = regcomp ( & V_57 , V_58 , V_59 ) ;
if ( V_27 ) {
char V_60 [ V_61 ] ;
regerror ( V_27 , & V_57 , V_60 , sizeof( V_60 ) ) ;
F_3 ( L_8 , V_58 , V_60 ) ;
return - V_62 ;
}
V_49 = F_16 ( V_53 ) ;
if ( F_17 ( V_49 ) < 0 ) {
F_3 ( L_9 ) ;
return - V_63 ;
}
F_18 (kernel_map, sym, node) {
if ( regexec ( & V_57 , V_51 -> V_64 , 0 , NULL , 0 ) )
continue;
V_52 = realloc ( V_65 ,
( V_66 + 1 ) * sizeof( * V_52 ) ) ;
if ( V_52 == NULL )
return - V_67 ;
F_19 ( L_10 , V_51 -> V_64 ) ;
V_52 [ V_66 ] . V_46 = V_51 -> V_46 ;
V_52 [ V_66 ] . V_47 = V_51 -> V_47 ;
V_52 [ V_66 ] . V_64 = V_51 -> V_64 ;
V_65 = V_52 ;
V_66 ++ ;
}
qsort ( V_65 , V_66 , sizeof( * V_52 ) , F_13 ) ;
regfree ( & V_57 ) ;
return 0 ;
}
static T_3 F_20 ( struct V_20 * V_21 , struct V_22 * V_23 )
{
struct V_68 V_69 ;
struct V_53 * V_53 = & V_54 -> V_55 . V_56 ;
struct V_70 * V_7 ;
if ( V_65 == NULL ) {
if ( F_15 () < 0 )
goto V_71;
}
V_69 . V_72 = F_21 ( V_53 , V_23 -> V_73 , V_23 -> V_74 ) ;
F_22 ( V_23 , & V_75 , NULL , V_21 , & V_69 , 16 ) ;
F_23 ( & V_75 ) ;
while ( true ) {
struct V_43 V_34 , * V_76 ;
T_3 V_77 ;
V_7 = F_24 ( & V_75 ) ;
if ( V_7 == NULL )
break;
V_34 . V_46 = V_34 . V_47 = V_7 -> V_78 ;
V_76 = bsearch ( & V_34 , V_65 , V_66 ,
sizeof( V_34 ) , F_14 ) ;
if ( ! V_76 ) {
if ( V_7 -> V_48 )
V_77 = F_25 ( V_7 -> V_48 , V_7 -> V_78 ) ;
else
V_77 = V_7 -> V_78 ;
return V_77 ;
} else
F_26 ( L_11 , V_76 -> V_64 ) ;
F_27 ( & V_75 ) ;
}
V_71:
F_28 ( L_12 V_79 L_13 , V_23 -> V_78 ) ;
return V_23 -> V_78 ;
}
static struct V_80 *
F_29 ( struct V_80 * V_81 , bool V_82 )
{
struct V_6 * * V_7 = & V_83 . V_6 ;
struct V_6 * V_9 = NULL ;
struct V_80 * V_11 ;
while ( * V_7 ) {
T_4 V_35 ;
V_9 = * V_7 ;
V_11 = F_2 ( * V_7 , struct V_80 , V_7 ) ;
V_35 = V_11 -> V_84 - V_81 -> V_84 ;
if ( V_35 < 0 )
V_7 = & V_9 -> V_13 ;
else if ( V_35 > 0 )
V_7 = & V_9 -> V_12 ;
else
return V_11 ;
}
if ( ! V_82 )
return NULL ;
V_11 = F_30 ( sizeof( * V_11 ) ) ;
if ( V_11 != NULL ) {
V_11 -> V_84 = V_81 -> V_84 ;
V_11 -> V_85 = V_81 -> V_85 ;
V_11 -> V_86 = V_81 -> V_86 ;
V_11 -> V_87 = V_81 -> V_87 ;
F_4 ( & V_11 -> V_7 , V_9 , V_7 ) ;
F_5 ( & V_11 -> V_7 , & V_83 ) ;
}
return V_11 ;
}
static struct V_80 * F_31 ( struct V_80 * V_81 )
{
return F_29 ( V_81 , false ) ;
}
static struct V_80 * F_32 ( struct V_80 * V_81 )
{
return F_29 ( V_81 , true ) ;
}
static struct V_80 *
F_33 ( struct V_80 * V_81 , bool V_82 )
{
struct V_6 * * V_7 = & V_88 . V_6 ;
struct V_6 * V_9 = NULL ;
struct V_80 * V_11 ;
struct V_89 * V_90 ;
while ( * V_7 ) {
int V_35 = 0 ;
V_9 = * V_7 ;
V_11 = F_2 ( * V_7 , struct V_80 , V_7 ) ;
F_34 (sort, &page_alloc_sort_input, list) {
V_35 = V_90 -> V_35 ( V_81 , V_11 ) ;
if ( V_35 )
break;
}
if ( V_35 < 0 )
V_7 = & V_9 -> V_13 ;
else if ( V_35 > 0 )
V_7 = & V_9 -> V_12 ;
else
return V_11 ;
}
if ( ! V_82 )
return NULL ;
V_11 = F_30 ( sizeof( * V_11 ) ) ;
if ( V_11 != NULL ) {
V_11 -> V_84 = V_81 -> V_84 ;
V_11 -> V_85 = V_81 -> V_85 ;
V_11 -> V_86 = V_81 -> V_86 ;
V_11 -> V_87 = V_81 -> V_87 ;
F_4 ( & V_11 -> V_7 , V_9 , V_7 ) ;
F_5 ( & V_11 -> V_7 , & V_88 ) ;
}
return V_11 ;
}
static struct V_80 * F_35 ( struct V_80 * V_81 )
{
return F_33 ( V_81 , false ) ;
}
static struct V_80 * F_36 ( struct V_80 * V_81 )
{
return F_33 ( V_81 , true ) ;
}
static struct V_80 *
F_37 ( struct V_80 * V_81 , bool V_82 )
{
struct V_6 * * V_7 = & V_91 . V_6 ;
struct V_6 * V_9 = NULL ;
struct V_80 * V_11 ;
struct V_89 * V_90 ;
while ( * V_7 ) {
int V_35 = 0 ;
V_9 = * V_7 ;
V_11 = F_2 ( * V_7 , struct V_80 , V_7 ) ;
F_34 (sort, &page_caller_sort_input, list) {
V_35 = V_90 -> V_35 ( V_81 , V_11 ) ;
if ( V_35 )
break;
}
if ( V_35 < 0 )
V_7 = & V_9 -> V_13 ;
else if ( V_35 > 0 )
V_7 = & V_9 -> V_12 ;
else
return V_11 ;
}
if ( ! V_82 )
return NULL ;
V_11 = F_30 ( sizeof( * V_11 ) ) ;
if ( V_11 != NULL ) {
V_11 -> V_92 = V_81 -> V_92 ;
V_11 -> V_85 = V_81 -> V_85 ;
V_11 -> V_86 = V_81 -> V_86 ;
V_11 -> V_87 = V_81 -> V_87 ;
F_4 ( & V_11 -> V_7 , V_9 , V_7 ) ;
F_5 ( & V_11 -> V_7 , & V_91 ) ;
}
return V_11 ;
}
static struct V_80 * F_38 ( struct V_80 * V_81 )
{
return F_37 ( V_81 , false ) ;
}
static struct V_80 * F_39 ( struct V_80 * V_81 )
{
return F_37 ( V_81 , true ) ;
}
static bool F_40 ( T_3 V_93 )
{
if ( V_94 && V_93 == - 1UL )
return false ;
if ( ! V_94 && V_93 == 0 )
return false ;
return true ;
}
static int F_41 ( const void * V_41 , const void * V_42 )
{
const struct V_95 * V_44 = V_41 ;
const struct V_95 * V_45 = V_42 ;
return V_44 -> V_96 - V_45 -> V_96 ;
}
static char * F_42 ( char * V_86 )
{
char * V_97 = F_43 ( V_86 ) ;
char * V_98 = NULL ;
char * V_99 , * V_100 = NULL ;
T_5 V_101 = 0 ;
if ( V_97 == NULL )
return NULL ;
V_99 = strtok_r ( V_97 , L_14 , & V_100 ) ;
while ( V_99 ) {
T_5 V_102 ;
char * V_103 ;
const char * V_104 ;
for ( V_102 = 0 ; V_102 < F_44 ( V_105 ) ; V_102 ++ ) {
if ( strcmp ( V_105 [ V_102 ] . V_106 , V_99 ) )
continue;
V_104 = V_105 [ V_102 ] . V_107 ;
V_103 = realloc ( V_98 , V_101 + strlen ( V_104 ) + 2 ) ;
if ( V_103 == NULL ) {
free ( V_98 ) ;
return NULL ;
}
V_98 = V_103 ;
if ( ! V_101 ) {
strcpy ( V_98 , V_104 ) ;
} else {
strcat ( V_98 , L_14 ) ;
strcat ( V_98 , V_104 ) ;
V_101 ++ ;
}
V_101 += strlen ( V_104 ) ;
}
V_99 = strtok_r ( NULL , L_14 , & V_100 ) ;
}
if ( V_108 < V_101 )
V_108 = V_101 ;
free ( V_97 ) ;
return V_98 ;
}
static char * F_45 ( unsigned long V_86 )
{
struct V_95 V_34 = {
. V_96 = V_86 ,
} ;
struct V_95 * V_109 ;
V_109 = bsearch ( & V_34 , V_110 , V_111 , sizeof( * V_110 ) , F_41 ) ;
if ( V_109 )
return V_109 -> V_112 ;
return NULL ;
}
static int F_46 ( struct V_20 * V_21 , struct V_22 * V_23 ,
unsigned int V_86 )
{
struct V_113 V_114 = {
. V_5 = V_23 -> V_5 ,
. V_11 = V_23 -> V_115 ,
. V_116 = V_23 -> V_117 ,
} ;
struct V_118 V_119 ;
char * V_99 , * V_100 = NULL ;
if ( V_111 ) {
struct V_95 V_34 = {
. V_96 = V_86 ,
} ;
if ( bsearch ( & V_34 , V_110 , V_111 , sizeof( * V_110 ) , F_41 ) )
return 0 ;
}
F_47 ( & V_119 ) ;
F_48 ( & V_119 , V_21 -> V_120 , & V_114 ) ;
V_99 = strtok_r ( V_119 . V_121 , L_15 , & V_100 ) ;
while ( V_99 ) {
if ( ! strncmp ( V_99 , L_16 , 10 ) ) {
struct V_95 * V_103 ;
V_103 = realloc ( V_110 , ( V_111 + 1 ) * sizeof( * V_110 ) ) ;
if ( V_103 == NULL )
return - V_67 ;
V_110 = V_103 ;
V_103 += V_111 ++ ;
V_103 -> V_96 = V_86 ;
V_103 -> V_122 = F_43 ( V_99 + 10 ) ;
V_103 -> V_112 = F_42 ( V_99 + 10 ) ;
if ( ! V_103 -> V_122 || ! V_103 -> V_112 )
return - V_67 ;
qsort ( V_110 , V_111 , sizeof( * V_110 ) , F_41 ) ;
}
V_99 = strtok_r ( NULL , L_15 , & V_100 ) ;
}
F_49 ( & V_119 ) ;
return 0 ;
}
static int F_50 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
T_3 V_84 ;
unsigned int V_85 = F_8 ( V_21 , V_23 , L_17 ) ;
unsigned int V_86 = F_8 ( V_21 , V_23 , L_18 ) ;
unsigned int V_87 = F_8 ( V_21 , V_23 ,
L_19 ) ;
T_3 V_123 = V_124 << V_85 ;
T_3 V_92 ;
struct V_80 * V_81 ;
struct V_80 V_125 = {
. V_85 = V_85 ,
. V_86 = V_86 ,
. V_87 = V_87 ,
} ;
if ( V_94 )
V_84 = F_8 ( V_21 , V_23 , L_20 ) ;
else
V_84 = F_8 ( V_21 , V_23 , L_21 ) ;
V_126 ++ ;
V_127 += V_123 ;
if ( ! F_40 ( V_84 ) ) {
V_128 ++ ;
V_129 += V_123 ;
return 0 ;
}
if ( F_46 ( V_21 , V_23 , V_86 ) < 0 )
return - 1 ;
V_92 = F_20 ( V_21 , V_23 ) ;
V_125 . V_84 = V_84 ;
V_81 = F_32 ( & V_125 ) ;
if ( V_81 == NULL )
return - V_67 ;
V_81 -> V_130 ++ ;
V_81 -> V_131 += V_123 ;
V_81 -> V_92 = V_92 ;
if ( ! V_132 ) {
V_81 = F_36 ( & V_125 ) ;
if ( V_81 == NULL )
return - V_67 ;
V_81 -> V_130 ++ ;
V_81 -> V_131 += V_123 ;
V_81 -> V_92 = V_92 ;
}
V_125 . V_92 = V_92 ;
V_81 = F_39 ( & V_125 ) ;
if ( V_81 == NULL )
return - V_67 ;
V_81 -> V_130 ++ ;
V_81 -> V_131 += V_123 ;
V_133 [ V_85 ] [ V_87 ] ++ ;
return 0 ;
}
static int F_51 ( struct V_20 * V_21 ,
struct V_22 * V_23 )
{
T_3 V_84 ;
unsigned int V_85 = F_8 ( V_21 , V_23 , L_17 ) ;
T_3 V_123 = V_124 << V_85 ;
struct V_80 * V_81 ;
struct V_80 V_125 = {
. V_85 = V_85 ,
} ;
if ( V_94 )
V_84 = F_8 ( V_21 , V_23 , L_20 ) ;
else
V_84 = F_8 ( V_21 , V_23 , L_21 ) ;
V_134 ++ ;
V_135 += V_123 ;
V_125 . V_84 = V_84 ;
V_81 = F_31 ( & V_125 ) ;
if ( V_81 == NULL ) {
F_28 ( L_22 V_79 L_23 ,
V_84 , V_85 ) ;
V_136 ++ ;
V_137 += V_123 ;
return 0 ;
}
V_125 . V_86 = V_81 -> V_86 ;
V_125 . V_87 = V_81 -> V_87 ;
V_125 . V_92 = V_81 -> V_92 ;
F_52 ( & V_81 -> V_7 , & V_83 ) ;
free ( V_81 ) ;
if ( V_132 ) {
V_133 [ V_125 . V_85 ] [ V_125 . V_87 ] -- ;
} else {
V_81 = F_35 ( & V_125 ) ;
if ( V_81 == NULL )
return - V_67 ;
V_81 -> V_138 ++ ;
V_81 -> V_139 += V_123 ;
}
V_81 = F_38 ( & V_125 ) ;
if ( V_81 == NULL )
return - V_63 ;
V_81 -> V_138 ++ ;
V_81 -> V_139 += V_123 ;
if ( V_132 ) {
V_81 -> V_130 -- ;
V_81 -> V_131 -= V_123 ;
if ( V_81 -> V_130 == 0 ) {
F_52 ( & V_81 -> V_7 , & V_91 ) ;
free ( V_81 ) ;
}
}
return 0 ;
}
static bool F_53 ( struct V_22 * V_23 )
{
if ( F_54 ( & V_140 , V_23 -> time ) )
return true ;
return false ;
}
static int F_55 ( struct V_141 * T_6 V_142 ,
union V_143 * V_144 ,
struct V_22 * V_23 ,
struct V_20 * V_21 ,
struct V_53 * V_53 )
{
int V_60 = 0 ;
struct V_72 * V_72 = F_21 ( V_53 , V_23 -> V_73 ,
V_23 -> V_74 ) ;
if ( V_72 == NULL ) {
F_19 ( L_24 ,
V_144 -> V_145 . type ) ;
return - 1 ;
}
if ( F_53 ( V_23 ) )
return 0 ;
F_56 ( L_25 , F_57 ( V_72 ) , V_72 -> V_74 ) ;
if ( V_21 -> V_146 != NULL ) {
T_7 V_147 = V_21 -> V_146 ;
V_60 = V_147 ( V_21 , V_23 ) ;
}
F_58 ( V_72 ) ;
return V_60 ;
}
static double F_59 ( unsigned long V_148 , unsigned long V_149 )
{
if ( V_149 == 0 )
return 0.0 ;
else
return 100.0 - ( 100.0 * V_148 / V_149 ) ;
}
static void F_60 ( struct V_31 * V_32 ,
struct V_150 * V_151 ,
int V_152 , int V_153 )
{
struct V_6 * V_154 ;
struct V_53 * V_53 = & V_151 -> V_55 . V_56 ;
printf ( L_26 , V_155 ) ;
printf ( L_27 , V_153 ? L_28 : L_29 ) ;
printf ( L_30 ) ;
printf ( L_26 , V_155 ) ;
V_154 = F_61 ( V_32 ) ;
while ( V_154 && V_152 -- ) {
struct V_10 * V_11 = F_2 ( V_154 , struct V_10 ,
V_7 ) ;
struct V_50 * V_51 = NULL ;
struct V_48 * V_48 ;
char V_156 [ V_61 ] ;
T_3 V_77 ;
if ( V_153 ) {
V_77 = V_11 -> V_1 ;
if ( ! V_157 )
V_51 = F_62 ( V_53 , V_77 , & V_48 ) ;
} else
V_77 = V_11 -> V_2 ;
if ( V_51 != NULL )
snprintf ( V_156 , sizeof( V_156 ) , L_31 V_79 L_32 , V_51 -> V_64 ,
V_77 - V_48 -> V_158 ( V_48 , V_51 -> V_46 ) ) ;
else
snprintf ( V_156 , sizeof( V_156 ) , L_33 V_79 L_32 , V_77 ) ;
printf ( L_27 , V_156 ) ;
printf ( L_34 ,
( unsigned long long ) V_11 -> V_4 ,
( unsigned long ) V_11 -> V_4 / V_11 -> V_14 ,
( unsigned long long ) V_11 -> V_3 ,
( unsigned long ) V_11 -> V_3 / V_11 -> V_14 ,
( unsigned long ) V_11 -> V_14 ,
( unsigned long ) V_11 -> V_16 ,
F_59 ( V_11 -> V_3 , V_11 -> V_4 ) ) ;
V_154 = F_63 ( V_154 ) ;
}
if ( V_152 == - 1 )
printf ( L_35 ) ;
printf ( L_26 , V_155 ) ;
}
static void F_64 ( struct V_150 * V_151 , int V_152 )
{
struct V_6 * V_154 = F_61 ( & V_159 ) ;
struct V_53 * V_53 = & V_151 -> V_55 . V_56 ;
const char * V_160 ;
int V_161 = F_65 ( strlen ( L_36 ) , V_108 ) ;
printf ( L_37 , V_155 ) ;
printf ( L_38 ,
V_94 ? L_39 : L_40 , V_132 ? L_41 : L_42 ,
V_161 , L_36 ) ;
printf ( L_26 , V_155 ) ;
if ( V_94 )
V_160 = L_43 ;
else
V_160 = L_44 ;
while ( V_154 && V_152 -- ) {
struct V_80 * V_11 ;
struct V_50 * V_51 ;
struct V_48 * V_48 ;
char V_156 [ 32 ] ;
char * V_76 = V_156 ;
V_11 = F_2 ( V_154 , struct V_80 , V_7 ) ;
V_51 = F_62 ( V_53 , V_11 -> V_92 , & V_48 ) ;
if ( V_51 )
V_76 = V_51 -> V_64 ;
else
F_66 ( V_156 , sizeof( V_156 ) , L_45 V_79 , V_11 -> V_92 ) ;
printf ( V_160 , ( unsigned long long ) V_11 -> V_84 ,
( unsigned long long ) V_11 -> V_131 / 1024 ,
V_11 -> V_130 , V_11 -> V_85 ,
V_162 [ V_11 -> V_87 ] ,
V_161 , F_45 ( V_11 -> V_86 ) , V_76 ) ;
V_154 = F_63 ( V_154 ) ;
}
if ( V_152 == - 1 ) {
printf ( L_46 ,
V_161 , L_47 ) ;
}
printf ( L_26 , V_155 ) ;
}
static void F_67 ( struct V_150 * V_151 , int V_152 )
{
struct V_6 * V_154 = F_61 ( & V_163 ) ;
struct V_53 * V_53 = & V_151 -> V_55 . V_56 ;
int V_161 = F_65 ( strlen ( L_36 ) , V_108 ) ;
printf ( L_37 , V_155 ) ;
printf ( L_48 ,
V_132 ? L_41 : L_42 , V_161 , L_36 ) ;
printf ( L_26 , V_155 ) ;
while ( V_154 && V_152 -- ) {
struct V_80 * V_11 ;
struct V_50 * V_51 ;
struct V_48 * V_48 ;
char V_156 [ 32 ] ;
char * V_76 = V_156 ;
V_11 = F_2 ( V_154 , struct V_80 , V_7 ) ;
V_51 = F_62 ( V_53 , V_11 -> V_92 , & V_48 ) ;
if ( V_51 )
V_76 = V_51 -> V_64 ;
else
F_66 ( V_156 , sizeof( V_156 ) , L_45 V_79 , V_11 -> V_92 ) ;
printf ( L_49 ,
( unsigned long long ) V_11 -> V_131 / 1024 ,
V_11 -> V_130 , V_11 -> V_85 ,
V_162 [ V_11 -> V_87 ] ,
V_161 , F_45 ( V_11 -> V_86 ) , V_76 ) ;
V_154 = F_63 ( V_154 ) ;
}
if ( V_152 == - 1 ) {
printf ( L_50 ,
V_161 , L_47 ) ;
}
printf ( L_26 , V_155 ) ;
}
static void F_68 ( void )
{
int V_102 ;
printf ( L_51 ) ;
printf ( L_52 ) ;
printf ( L_53 ) ;
for ( V_102 = 0 ; V_102 < V_111 ; V_102 ++ ) {
printf ( L_54 , V_110 [ V_102 ] . V_96 ,
( int ) V_108 , V_110 [ V_102 ] . V_112 ,
V_110 [ V_102 ] . V_122 ) ;
}
}
static void F_69 ( void )
{
printf ( L_55 ) ;
printf ( L_56 ) ;
printf ( L_57 , V_24 ) ;
printf ( L_58 , V_25 ) ;
printf ( L_59 , V_39 ) ;
if ( V_25 > V_39 ) {
printf ( L_60 ,
V_25 - V_39 ) ;
}
printf ( L_61 ,
V_25 - V_24 ) ;
printf ( L_62 ,
F_59 ( V_24 , V_25 ) ) ;
printf ( L_63 , V_30 , V_26 ) ;
}
static void F_70 ( void )
{
int V_164 , V_165 ;
T_3 V_166 = V_134 - V_136 ;
T_3 V_167 = V_135 - V_137 ;
printf ( L_64 ) ;
printf ( L_56 ) ;
printf ( L_65 V_168 L_66 , L_67 ,
V_126 , V_127 / 1024 ) ;
printf ( L_65 V_168 L_66 , L_68 ,
V_134 , V_135 / 1024 ) ;
printf ( L_13 ) ;
printf ( L_69 V_168 L_70 V_168 L_66 , L_71 ,
V_166 , ( V_167 ) / 1024 ) ;
printf ( L_69 V_168 L_70 V_168 L_66 , L_72 ,
V_126 - V_166 ,
( V_127 - V_167 ) / 1024 ) ;
printf ( L_65 V_168 L_66 , L_73 ,
V_136 , V_137 / 1024 ) ;
printf ( L_13 ) ;
printf ( L_65 V_168 L_66 , L_74 ,
V_128 , V_129 / 1024 ) ;
printf ( L_13 ) ;
printf ( L_75 , L_76 , L_77 ,
L_78 , L_79 , L_80 , L_81 ) ;
printf ( L_82 , V_155 ,
V_155 , V_155 , V_155 ,
V_155 , V_155 ) ;
for ( V_164 = 0 ; V_164 < V_169 ; V_164 ++ ) {
printf ( L_83 , V_164 ) ;
for ( V_165 = 0 ; V_165 < V_170 - 1 ; V_165 ++ ) {
if ( V_133 [ V_164 ] [ V_165 ] )
printf ( L_84 , V_133 [ V_164 ] [ V_165 ] ) ;
else
printf ( L_85 , '.' ) ;
}
printf ( L_13 ) ;
}
}
static void F_71 ( struct V_150 * V_151 )
{
if ( V_171 )
F_60 ( & V_172 , V_151 , V_173 , 1 ) ;
if ( V_174 )
F_60 ( & V_175 , V_151 , V_176 , 0 ) ;
F_69 () ;
}
static void F_72 ( struct V_150 * V_151 )
{
if ( V_171 || V_174 )
F_68 () ;
if ( V_171 )
F_67 ( V_151 , V_173 ) ;
if ( V_174 )
F_64 ( V_151 , V_176 ) ;
F_70 () ;
}
static void F_73 ( struct V_150 * V_151 )
{
if ( V_177 )
F_71 ( V_151 ) ;
if ( V_178 )
F_72 ( V_151 ) ;
}
static void F_74 ( struct V_31 * V_32 , struct V_10 * V_11 ,
struct V_179 * V_180 )
{
struct V_6 * * V_103 = & ( V_32 -> V_6 ) ;
struct V_6 * V_9 = NULL ;
struct V_89 * V_90 ;
while ( * V_103 ) {
struct V_10 * V_125 ;
int V_35 = 0 ;
V_125 = F_2 ( * V_103 , struct V_10 , V_7 ) ;
V_9 = * V_103 ;
F_34 (sort, sort_list, list) {
V_35 = V_90 -> V_35 ( V_11 , V_125 ) ;
if ( V_35 )
break;
}
if ( V_35 > 0 )
V_103 = & ( ( * V_103 ) -> V_13 ) ;
else
V_103 = & ( ( * V_103 ) -> V_12 ) ;
}
F_4 ( & V_11 -> V_7 , V_9 , V_103 ) ;
F_5 ( & V_11 -> V_7 , V_32 ) ;
}
static void F_75 ( struct V_31 * V_32 , struct V_31 * V_181 ,
struct V_179 * V_180 )
{
struct V_6 * V_7 ;
struct V_10 * V_11 ;
for (; ; ) {
V_7 = F_61 ( V_32 ) ;
if ( ! V_7 )
break;
F_52 ( V_7 , V_32 ) ;
V_11 = F_2 ( V_7 , struct V_10 , V_7 ) ;
F_74 ( V_181 , V_11 , V_180 ) ;
}
}
static void F_76 ( struct V_31 * V_32 , struct V_80 * V_11 ,
struct V_179 * V_180 )
{
struct V_6 * * V_103 = & V_32 -> V_6 ;
struct V_6 * V_9 = NULL ;
struct V_89 * V_90 ;
while ( * V_103 ) {
struct V_80 * V_125 ;
int V_35 = 0 ;
V_125 = F_2 ( * V_103 , struct V_80 , V_7 ) ;
V_9 = * V_103 ;
F_34 (sort, sort_list, list) {
V_35 = V_90 -> V_35 ( V_11 , V_125 ) ;
if ( V_35 )
break;
}
if ( V_35 > 0 )
V_103 = & V_9 -> V_13 ;
else
V_103 = & V_9 -> V_12 ;
}
F_4 ( & V_11 -> V_7 , V_9 , V_103 ) ;
F_5 ( & V_11 -> V_7 , V_32 ) ;
}
static void F_77 ( struct V_31 * V_32 , struct V_31 * V_181 ,
struct V_179 * V_180 )
{
struct V_6 * V_7 ;
struct V_80 * V_11 ;
for (; ; ) {
V_7 = F_61 ( V_32 ) ;
if ( ! V_7 )
break;
F_52 ( V_7 , V_32 ) ;
V_11 = F_2 ( V_7 , struct V_80 , V_7 ) ;
F_76 ( V_181 , V_11 , V_180 ) ;
}
}
static void F_78 ( void )
{
if ( V_177 ) {
F_75 ( & V_8 , & V_175 ,
& V_182 ) ;
F_75 ( & V_19 , & V_172 ,
& V_183 ) ;
}
if ( V_178 ) {
if ( V_132 )
F_77 ( & V_83 , & V_159 ,
& V_184 ) ;
else
F_77 ( & V_88 , & V_159 ,
& V_184 ) ;
F_77 ( & V_91 , & V_163 ,
& V_185 ) ;
}
}
static int F_79 ( struct V_150 * V_151 )
{
int V_60 = - V_62 ;
struct V_20 * V_21 ;
const struct V_186 V_187 [] = {
{ L_86 , F_7 , } ,
{ L_87 , F_7 , } ,
{ L_88 , F_9 , } ,
{ L_89 , F_9 , } ,
{ L_90 , F_12 , } ,
{ L_91 , F_12 , } ,
{ L_92 , F_50 , } ,
{ L_93 , F_51 , } ,
} ;
if ( ! F_80 ( V_151 , L_94 ) )
goto V_71;
if ( F_81 ( V_151 , V_187 ) ) {
F_3 ( L_95 ) ;
goto V_71;
}
F_82 (session->evlist, evsel) {
if ( ! strcmp ( F_83 ( V_21 ) , L_92 ) &&
F_84 ( V_21 , L_20 ) ) {
V_94 = true ;
break;
}
}
F_85 () ;
V_60 = F_86 ( V_151 ) ;
if ( V_60 != 0 ) {
F_3 ( L_96 , V_60 ) ;
goto V_71;
}
F_78 () ;
F_73 ( V_151 ) ;
V_71:
return V_60 ;
}
static int V_38 ( void * V_41 , void * V_42 )
{
struct V_10 * V_188 = V_41 ;
struct V_10 * V_189 = V_42 ;
if ( V_188 -> V_2 < V_189 -> V_2 )
return - 1 ;
else if ( V_188 -> V_2 > V_189 -> V_2 )
return 1 ;
return 0 ;
}
static int V_40 ( void * V_41 , void * V_42 )
{
struct V_10 * V_188 = V_41 ;
struct V_10 * V_189 = V_42 ;
if ( V_188 -> V_1 < V_189 -> V_1 )
return - 1 ;
else if ( V_188 -> V_1 > V_189 -> V_1 )
return 1 ;
return 0 ;
}
static int F_87 ( void * V_41 , void * V_42 )
{
struct V_10 * V_188 = V_41 ;
struct V_10 * V_189 = V_42 ;
if ( V_188 -> V_14 < V_189 -> V_14 )
return - 1 ;
else if ( V_188 -> V_14 > V_189 -> V_14 )
return 1 ;
return 0 ;
}
static int F_88 ( void * V_41 , void * V_42 )
{
struct V_10 * V_188 = V_41 ;
struct V_10 * V_189 = V_42 ;
if ( V_188 -> V_4 < V_189 -> V_4 )
return - 1 ;
else if ( V_188 -> V_4 > V_189 -> V_4 )
return 1 ;
return 0 ;
}
static int F_89 ( void * V_41 , void * V_42 )
{
double V_190 , V_191 ;
struct V_10 * V_188 = V_41 ;
struct V_10 * V_189 = V_42 ;
V_190 = F_59 ( V_188 -> V_3 , V_188 -> V_4 ) ;
V_191 = F_59 ( V_189 -> V_3 , V_189 -> V_4 ) ;
if ( V_190 < V_191 )
return - 1 ;
else if ( V_190 > V_191 )
return 1 ;
return 0 ;
}
static int F_90 ( void * V_41 , void * V_42 )
{
struct V_10 * V_188 = V_41 ;
struct V_10 * V_189 = V_42 ;
if ( V_188 -> V_16 < V_189 -> V_16 )
return - 1 ;
else if ( V_188 -> V_16 > V_189 -> V_16 )
return 1 ;
return 0 ;
}
static int F_91 ( void * V_41 , void * V_42 )
{
struct V_80 * V_188 = V_41 ;
struct V_80 * V_189 = V_42 ;
if ( V_188 -> V_84 < V_189 -> V_84 )
return - 1 ;
else if ( V_188 -> V_84 > V_189 -> V_84 )
return 1 ;
return 0 ;
}
static int F_92 ( void * V_41 , void * V_42 )
{
struct V_80 * V_188 = V_41 ;
struct V_80 * V_189 = V_42 ;
if ( V_188 -> V_92 < V_189 -> V_92 )
return - 1 ;
else if ( V_188 -> V_92 > V_189 -> V_92 )
return 1 ;
return 0 ;
}
static int F_93 ( void * V_41 , void * V_42 )
{
struct V_80 * V_188 = V_41 ;
struct V_80 * V_189 = V_42 ;
if ( V_188 -> V_130 < V_189 -> V_130 )
return - 1 ;
else if ( V_188 -> V_130 > V_189 -> V_130 )
return 1 ;
return 0 ;
}
static int F_94 ( void * V_41 , void * V_42 )
{
struct V_80 * V_188 = V_41 ;
struct V_80 * V_189 = V_42 ;
if ( V_188 -> V_131 < V_189 -> V_131 )
return - 1 ;
else if ( V_188 -> V_131 > V_189 -> V_131 )
return 1 ;
return 0 ;
}
static int F_95 ( void * V_41 , void * V_42 )
{
struct V_80 * V_188 = V_41 ;
struct V_80 * V_189 = V_42 ;
if ( V_188 -> V_85 < V_189 -> V_85 )
return - 1 ;
else if ( V_188 -> V_85 > V_189 -> V_85 )
return 1 ;
return 0 ;
}
static int F_96 ( void * V_41 , void * V_42 )
{
struct V_80 * V_188 = V_41 ;
struct V_80 * V_189 = V_42 ;
if ( V_188 -> V_87 == - 1U )
return 0 ;
if ( V_188 -> V_87 < V_189 -> V_87 )
return - 1 ;
else if ( V_188 -> V_87 > V_189 -> V_87 )
return 1 ;
return 0 ;
}
static int F_97 ( void * V_41 , void * V_42 )
{
struct V_80 * V_188 = V_41 ;
struct V_80 * V_189 = V_42 ;
if ( V_188 -> V_86 == - 1U )
return 0 ;
if ( V_188 -> V_86 < V_189 -> V_86 )
return - 1 ;
else if ( V_188 -> V_86 > V_189 -> V_86 )
return 1 ;
return 0 ;
}
static int F_98 ( const char * V_192 , struct V_179 * V_193 )
{
struct V_89 * V_90 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < ( int ) F_44 ( V_194 ) ; V_102 ++ ) {
if ( ! strcmp ( V_194 [ V_102 ] -> V_64 , V_192 ) ) {
V_90 = F_99 ( V_194 [ V_102 ] , sizeof( * V_194 [ V_102 ] ) ) ;
if ( ! V_90 ) {
F_3 ( L_97 , V_15 ) ;
return - 1 ;
}
F_100 ( & V_90 -> V_193 , V_193 ) ;
return 0 ;
}
}
return - 1 ;
}
static int F_101 ( const char * V_192 , struct V_179 * V_193 )
{
struct V_89 * V_90 ;
int V_102 ;
for ( V_102 = 0 ; V_102 < ( int ) F_44 ( V_195 ) ; V_102 ++ ) {
if ( ! strcmp ( V_195 [ V_102 ] -> V_64 , V_192 ) ) {
V_90 = F_99 ( V_195 [ V_102 ] , sizeof( * V_195 [ V_102 ] ) ) ;
if ( ! V_90 ) {
F_3 ( L_97 , V_15 ) ;
return - 1 ;
}
F_100 ( & V_90 -> V_193 , V_193 ) ;
return 0 ;
}
}
return - 1 ;
}
static int F_102 ( struct V_179 * V_180 , const char * V_196 )
{
char * V_192 ;
char * V_99 = F_43 ( V_196 ) ;
char * V_100 = V_99 ;
if ( ! V_99 ) {
F_3 ( L_98 , V_15 ) ;
return - 1 ;
}
while ( true ) {
V_192 = F_103 ( & V_100 , L_99 ) ;
if ( ! V_192 )
break;
if ( F_98 ( V_192 , V_180 ) < 0 ) {
error ( L_100 , V_192 ) ;
free ( V_99 ) ;
return - 1 ;
}
}
free ( V_99 ) ;
return 0 ;
}
static int F_104 ( struct V_179 * V_180 , const char * V_196 )
{
char * V_192 ;
char * V_99 = F_43 ( V_196 ) ;
char * V_100 = V_99 ;
if ( ! V_99 ) {
F_3 ( L_98 , V_15 ) ;
return - 1 ;
}
while ( true ) {
V_192 = F_103 ( & V_100 , L_99 ) ;
if ( ! V_192 )
break;
if ( F_101 ( V_192 , V_180 ) < 0 ) {
error ( L_101 , V_192 ) ;
free ( V_99 ) ;
return - 1 ;
}
}
free ( V_99 ) ;
return 0 ;
}
static int F_105 ( const struct V_197 * T_8 V_142 ,
const char * V_196 , int T_9 V_142 )
{
if ( ! V_196 )
return - 1 ;
if ( V_178 > V_177 ||
( V_178 == 0 && V_177 == 0 && V_198 == V_199 ) ) {
if ( V_171 > V_174 )
return F_104 ( & V_185 , V_196 ) ;
else
return F_104 ( & V_184 , V_196 ) ;
} else {
if ( V_171 > V_174 )
return F_102 ( & V_183 , V_196 ) ;
else
return F_102 ( & V_182 , V_196 ) ;
}
return 0 ;
}
static int F_106 ( const struct V_197 * T_8 V_142 ,
const char * V_196 V_142 ,
int T_9 V_142 )
{
V_171 = ( V_174 + 1 ) ;
return 0 ;
}
static int F_107 ( const struct V_197 * T_8 V_142 ,
const char * V_196 V_142 ,
int T_9 V_142 )
{
V_174 = ( V_171 + 1 ) ;
return 0 ;
}
static int F_108 ( const struct V_197 * T_8 V_142 ,
const char * V_196 V_142 ,
int T_9 V_142 )
{
V_177 = ( V_178 + 1 ) ;
return 0 ;
}
static int F_109 ( const struct V_197 * T_8 V_142 ,
const char * V_196 V_142 ,
int T_9 V_142 )
{
V_178 = ( V_177 + 1 ) ;
return 0 ;
}
static int F_110 ( const struct V_197 * T_8 V_142 ,
const char * V_196 , int T_9 V_142 )
{
int V_200 ;
if ( ! V_196 )
return - 1 ;
V_200 = strtoul ( V_196 , NULL , 10 ) ;
if ( V_171 > V_174 )
V_173 = V_200 ;
else
V_176 = V_200 ;
return 0 ;
}
static int F_111 ( int V_201 , const char * * V_202 )
{
const char * const V_203 [] = {
L_102 , L_103 , L_104 , L_105 , L_106 ,
} ;
const char * const V_204 [] = {
L_107 , L_86 ,
L_107 , L_88 ,
L_107 , L_90 ,
L_107 , L_87 ,
L_107 , L_89 ,
L_107 , L_91 ,
} ;
const char * const V_205 [] = {
L_107 , L_92 ,
L_107 , L_93 ,
} ;
unsigned int V_206 , V_102 , V_207 ;
const char * * V_208 ;
V_206 = F_44 ( V_203 ) + V_201 - 1 ;
if ( V_177 )
V_206 += F_44 ( V_204 ) ;
if ( V_178 )
V_206 += F_44 ( V_205 ) + 1 ;
V_208 = calloc ( V_206 + 1 , sizeof( char * ) ) ;
if ( V_208 == NULL )
return - V_67 ;
for ( V_102 = 0 ; V_102 < F_44 ( V_203 ) ; V_102 ++ )
V_208 [ V_102 ] = F_43 ( V_203 [ V_102 ] ) ;
if ( V_177 ) {
for ( V_207 = 0 ; V_207 < F_44 ( V_204 ) ; V_207 ++ , V_102 ++ )
V_208 [ V_102 ] = F_43 ( V_204 [ V_207 ] ) ;
}
if ( V_178 ) {
V_208 [ V_102 ++ ] = F_43 ( L_108 ) ;
for ( V_207 = 0 ; V_207 < F_44 ( V_205 ) ; V_207 ++ , V_102 ++ )
V_208 [ V_102 ] = F_43 ( V_205 [ V_207 ] ) ;
}
for ( V_207 = 1 ; V_207 < ( unsigned int ) V_201 ; V_207 ++ , V_102 ++ )
V_208 [ V_102 ] = V_202 [ V_207 ] ;
return F_112 ( V_102 , V_208 ) ;
}
static int F_113 ( const char * V_209 , const char * V_210 , void * T_10 V_142 )
{
if ( ! strcmp ( V_209 , L_109 ) ) {
if ( ! strcmp ( V_210 , L_110 ) )
V_198 = V_211 ;
else if ( ! strcmp ( V_210 , L_21 ) )
V_198 = V_199 ;
else
F_3 ( L_111 ,
V_210 ) ;
return 0 ;
}
return 0 ;
}
int F_114 ( int V_201 , const char * * V_202 )
{
const char * const V_212 = L_112 ;
const char * const V_213 = L_113 ;
struct V_214 V_215 = {
. V_216 = V_217 ,
} ;
const struct V_197 V_218 [] = {
F_115 ( 'i' , L_114 , & V_219 , L_115 , L_116 ) ,
F_116 ( 'v' , L_117 , & V_220 ,
L_118 ) ,
F_117 ( 0 , L_119 , NULL , NULL ,
L_120 , F_106 ) ,
F_117 ( 0 , L_121 , NULL , NULL ,
L_122 , F_107 ) ,
F_118 ( 's' , L_123 , NULL , L_124 ,
L_125
L_126 , F_105 ) ,
F_118 ( 'l' , L_127 , NULL , L_128 , L_129 , F_110 ) ,
F_119 ( 0 , L_130 , & V_157 , L_131 ) ,
F_119 ( 'f' , L_132 , & V_215 . V_221 , L_133 ) ,
F_117 ( 0 , L_110 , NULL , NULL , L_134 ,
F_108 ) ,
F_117 ( 0 , L_21 , NULL , NULL , L_135 ,
F_109 ) ,
F_119 ( 0 , L_136 , & V_132 , L_137 ) ,
F_115 ( 0 , L_138 , & V_222 , L_139 ,
L_140 ) ,
F_120 ()
} ;
const char * const V_223 [] = { L_102 , L_141 , NULL } ;
const char * V_224 [] = {
NULL ,
NULL
} ;
struct V_150 * V_151 ;
const char V_225 [] = L_142 ;
int V_27 = F_121 ( F_113 , NULL ) ;
if ( V_27 )
return V_27 ;
V_201 = F_122 ( V_201 , V_202 , V_218 ,
V_223 , V_224 , 0 ) ;
if ( ! V_201 )
F_123 ( V_224 , V_218 ) ;
if ( V_177 == 0 && V_178 == 0 ) {
if ( V_198 == V_211 )
V_177 = 1 ;
else
V_178 = 1 ;
}
if ( ! strncmp ( V_202 [ 0 ] , L_143 , 3 ) ) {
F_124 ( NULL ) ;
return F_111 ( V_201 , V_202 ) ;
}
V_215 . V_226 = V_219 ;
V_54 = V_151 = F_125 ( & V_215 , false , & V_227 ) ;
if ( V_151 == NULL )
return - 1 ;
V_27 = - 1 ;
if ( V_177 ) {
if ( ! F_126 ( V_151 -> V_228 ,
L_86 ) ) {
F_3 ( V_225 , L_110 , L_110 ) ;
goto V_229;
}
}
if ( V_178 ) {
struct V_20 * V_21 ;
V_21 = F_126 ( V_151 -> V_228 ,
L_92 ) ;
if ( V_21 == NULL ) {
F_3 ( V_225 , L_21 , L_21 ) ;
goto V_229;
}
V_124 = F_127 ( V_21 -> V_120 -> V_230 ) ;
V_231 . V_232 = true ;
}
F_124 ( & V_151 -> V_145 . V_233 ) ;
if ( F_128 ( & V_140 , V_222 ) != 0 ) {
F_3 ( L_144 ) ;
return - V_62 ;
}
if ( ! strcmp ( V_202 [ 0 ] , L_141 ) ) {
setlocale ( V_234 , L_32 ) ;
if ( F_129 () )
goto V_229;
if ( F_130 ( & V_183 ) )
F_102 ( & V_183 , V_212 ) ;
if ( F_130 ( & V_182 ) )
F_102 ( & V_182 , V_212 ) ;
if ( F_130 ( & V_185 ) )
F_104 ( & V_185 , V_213 ) ;
if ( F_130 ( & V_184 ) )
F_104 ( & V_184 , V_213 ) ;
if ( V_178 ) {
F_104 ( & V_235 ,
L_145 ) ;
F_104 ( & V_236 ,
L_146 ) ;
}
V_27 = F_79 ( V_151 ) ;
} else
F_123 ( V_224 , V_218 ) ;
V_229:
F_131 ( V_151 ) ;
return V_27 ;
}
