static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_1 * F_3 ( T_1 V_5 )
{
struct V_6 * V_6 ;
struct V_1 * V_7 ;
if ( ! F_4 () && F_5 () )
return NULL ;
V_5 |= V_8 ;
V_6 = F_6 ( V_5 ) ;
if ( V_6 == NULL )
return NULL ;
V_7 = F_7 ( sizeof( * V_7 ) , V_5 ) ;
if ( V_7 == NULL ) {
F_8 ( V_6 ) ;
return NULL ;
}
V_7 -> V_6 = V_6 ;
F_9 ( & V_9 ) ;
return V_7 ;
}
static void F_10 ( struct V_1 * V_7 )
{
F_11 ( V_7 != NULL ) ;
F_11 ( V_7 -> V_6 != NULL ) ;
F_8 ( V_7 -> V_6 ) ;
F_12 ( V_7 ) ;
F_13 ( & V_9 ) ;
}
static void F_14 ( struct V_1 * V_7 ,
struct V_2 * V_10 )
{
F_11 ( V_7 != NULL ) ;
F_11 ( V_10 != NULL ) ;
F_15 ( & V_7 -> V_4 , V_10 ) ;
}
int F_16 ( struct V_11 * V_12 , T_1 V_5 ,
struct V_2 * V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 + V_12 -> V_15 < V_16 ; ++ V_14 ) {
struct V_1 * V_7 ;
V_7 = F_3 ( V_5 ) ;
if ( V_7 == NULL )
break;
F_17 ( & V_7 -> V_4 , V_13 ) ;
}
return V_14 ;
}
static struct V_1 *
F_18 ( struct V_11 * V_12 , unsigned long V_17 )
{
struct V_1 * V_7 ;
if ( V_12 -> V_18 > 0 ) {
F_11 ( ! F_19 ( & V_12 -> V_19 ) ) ;
V_7 = F_1 ( V_12 -> V_19 . V_20 ) ;
if ( V_7 -> V_21 + V_17 <= V_22 )
return V_7 ;
}
if ( V_12 -> V_18 < V_12 -> V_23 ) {
if ( V_12 -> V_15 > 0 ) {
V_7 = F_1 ( V_12 -> V_24 . V_20 ) ;
-- V_12 -> V_15 ;
F_20 ( & V_7 -> V_4 ) ;
} else {
V_7 = F_3 ( V_25 ) ;
if ( F_21 ( V_7 == NULL ) ) {
if ( ( ! F_5 () ||
F_4 () ) && F_22 () )
F_23 ( V_26
L_1 ,
V_12 -> V_18 ) ;
return NULL ;
}
}
V_7 -> V_21 = 0 ;
V_7 -> V_27 = F_24 () ;
V_7 -> type = V_12 -> V_28 ;
F_17 ( & V_7 -> V_4 , & V_12 -> V_19 ) ;
V_12 -> V_18 ++ ;
if ( V_12 -> V_18 > 8 && V_29 ) {
struct V_30 * V_31 = & V_32 ;
F_25 ( & V_31 -> V_33 ) ;
}
return V_7 ;
}
return NULL ;
}
static void F_26 ( struct V_11 * V_12 )
{
int V_34 = V_12 -> V_18 / 10 ;
struct V_35 V_36 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
if ( F_22 () )
F_23 ( V_26 L_2 ,
V_34 + 1 , V_12 -> V_18 ) ;
F_27 ( & V_36 . V_38 ) ;
F_28 (tage, tmp, &tcd->tcd_pages, linkage) {
if ( V_34 -- == 0 )
break;
F_15 ( & V_7 -> V_4 , & V_36 . V_38 ) ;
V_12 -> V_18 -- ;
}
F_29 ( & V_36 , V_12 ) ;
}
static struct V_1 * F_30 ( struct V_11 * V_12 ,
unsigned long V_17 )
{
struct V_1 * V_7 ;
if ( V_17 > V_22 ) {
F_31 ( L_3 , V_17 ) ;
return NULL ;
}
V_7 = F_18 ( V_12 , V_17 ) ;
if ( V_7 != NULL )
return V_7 ;
if ( V_29 )
F_26 ( V_12 ) ;
if ( V_12 -> V_18 > 0 ) {
V_7 = F_1 ( V_12 -> V_19 . V_39 ) ;
V_7 -> V_21 = 0 ;
F_14 ( V_7 , & V_12 -> V_19 ) ;
}
return V_7 ;
}
int F_32 ( struct V_40 * V_41 ,
const char * V_42 , ... )
{
T_2 args ;
int V_43 ;
va_start ( args , V_42 ) ;
V_43 = F_33 ( V_41 , V_42 , args , NULL ) ;
va_end ( args ) ;
return V_43 ;
}
int F_33 ( struct V_40 * V_41 ,
const char * V_44 , T_2 args ,
const char * V_45 , ... )
{
struct V_11 * V_12 = NULL ;
struct V_46 V_47 = { 0 } ;
struct V_1 * V_7 ;
char * V_48 = NULL ;
char * V_49 ;
int V_50 ;
int V_51 = 85 ;
int V_52 ;
T_2 V_53 ;
int V_54 ;
int V_14 ;
int V_55 ;
int V_56 = V_41 -> V_57 ;
const char * V_58 = F_34 ( V_41 -> V_59 ) ;
struct V_60 * V_61 = V_41 -> V_62 ;
V_12 = F_35 () ;
F_36 ( & V_47 , V_41 , F_37 () ) ;
if ( V_12 == NULL )
goto V_63;
if ( V_12 -> V_18 == 0 )
V_47 . V_64 |= V_65 ;
if ( V_12 -> V_66 ) {
F_38 ( V_12 ) ;
V_12 = NULL ;
goto V_63;
}
V_54 = F_39 () ;
V_50 = strlen ( V_58 ) + 1 + V_54 ;
if ( V_41 -> V_67 )
V_50 += strlen ( V_41 -> V_67 ) + 1 ;
if ( V_68 )
V_50 += sizeof( V_47 ) ;
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ ) {
V_7 = F_30 ( V_12 , V_51 + V_50 + 1 ) ;
if ( V_7 == NULL ) {
if ( V_51 + V_50 > V_22 )
V_56 |= V_69 ;
F_38 ( V_12 ) ;
V_12 = NULL ;
goto V_63;
}
V_48 = ( char * ) F_40 ( V_7 -> V_6 ) +
V_7 -> V_21 + V_50 ;
V_52 = V_22 - V_7 -> V_21 - V_50 ;
if ( V_52 <= 0 ) {
F_23 ( V_70 L_4 ,
V_52 ) ;
V_56 |= V_69 ;
F_38 ( V_12 ) ;
V_12 = NULL ;
goto V_63;
}
V_51 = 0 ;
if ( V_44 ) {
F_41 ( V_53 , args ) ;
V_51 = vsnprintf ( V_48 , V_52 , V_44 , V_53 ) ;
va_end ( V_53 ) ;
}
if ( V_45 ) {
V_55 = V_52 - V_51 ;
if ( V_55 < 0 )
V_55 = 0 ;
va_start ( V_53 , V_45 ) ;
V_51 += vsnprintf ( V_48 + V_51 , V_55 ,
V_45 , V_53 ) ;
va_end ( V_53 ) ;
}
if ( V_51 < V_52 )
break;
}
if ( * ( V_48 + V_51 - 1 ) != '\n' )
F_23 ( V_71 L_5 ,
V_58 , V_41 -> V_72 , V_41 -> V_67 ) ;
V_47 . V_73 = V_50 + V_51 ;
V_49 = ( char * ) F_40 ( V_7 -> V_6 ) + V_7 -> V_21 ;
if ( V_68 ) {
memcpy ( V_49 , & V_47 , sizeof( V_47 ) ) ;
V_7 -> V_21 += sizeof( V_47 ) ;
V_49 += sizeof( V_47 ) ;
}
while ( V_54 -- > 0 ) {
* ( V_49 ++ ) = '.' ;
++ V_7 -> V_21 ;
}
strcpy ( V_49 , V_58 ) ;
V_7 -> V_21 += strlen ( V_58 ) + 1 ;
V_49 += strlen ( V_58 ) + 1 ;
if ( V_41 -> V_67 ) {
strcpy ( V_49 , V_41 -> V_67 ) ;
V_7 -> V_21 += strlen ( V_41 -> V_67 ) + 1 ;
V_49 += strlen ( V_41 -> V_67 ) + 1 ;
}
F_11 ( V_49 == V_48 ) ;
V_7 -> V_21 += V_51 ;
F_11 ( V_7 -> V_21 <= V_22 ) ;
V_63:
if ( ( V_56 & V_74 ) == 0 ) {
if ( V_12 != NULL )
F_38 ( V_12 ) ;
return 1 ;
}
if ( V_61 != NULL ) {
if ( V_75 &&
V_61 -> V_76 != 0 &&
! F_42 ( F_43 () , V_61 -> V_76 ) ) {
V_61 -> V_77 ++ ;
if ( V_12 != NULL )
F_38 ( V_12 ) ;
return 1 ;
}
if ( F_42 ( F_43 () , V_61 -> V_76 +
V_78
+ F_44 ( 10 ) ) ) {
V_61 -> V_79 /= V_80 * 4 ;
} else {
V_61 -> V_79 *= V_80 ;
}
if ( V_61 -> V_79 < V_81 )
V_61 -> V_79 = V_81 ;
else if ( V_61 -> V_79 > V_78 )
V_61 -> V_79 = V_78 ;
V_61 -> V_76 = ( F_43 () + V_61 -> V_79 ) | 1 ;
}
if ( V_12 != NULL ) {
F_45 ( & V_47 , V_56 , V_48 , V_51 , V_58 ,
V_41 -> V_67 ) ;
F_38 ( V_12 ) ;
} else {
V_48 = F_46 () ;
V_51 = 0 ;
if ( V_44 != NULL ) {
F_41 ( V_53 , args ) ;
V_51 = vsnprintf ( V_48 ,
V_82 ,
V_44 , V_53 ) ;
va_end ( V_53 ) ;
}
if ( V_45 != NULL ) {
V_55 = V_82 - V_51 ;
if ( V_55 > 0 ) {
va_start ( V_53 , V_45 ) ;
V_51 += vsnprintf ( V_48 + V_51 , V_55 ,
V_45 , V_53 ) ;
va_end ( V_53 ) ;
}
}
F_45 ( & V_47 , V_56 ,
V_48 , V_51 , V_58 , V_41 -> V_67 ) ;
F_47 () ;
}
if ( V_61 != NULL && V_61 -> V_77 != 0 ) {
V_48 = F_46 () ;
V_51 = snprintf ( V_48 , V_82 ,
L_6 ,
V_61 -> V_77 ,
( V_61 -> V_77 > 1 ) ? L_7 : L_8 ) ;
F_45 ( & V_47 , V_56 ,
V_48 , V_51 , V_58 , V_41 -> V_67 ) ;
F_47 () ;
V_61 -> V_77 = 0 ;
}
return 0 ;
}
void
F_48 ( const char * V_83 ,
struct V_40 * V_41 )
{
struct V_46 V_84 ;
V_85 = 1 ;
V_86 = 1 ;
F_49 () ;
F_36 ( & V_84 , V_41 , F_37 () ) ;
F_45 ( & V_84 , V_87 , V_83 , strlen ( V_83 ) ,
V_41 -> V_59 , V_41 -> V_67 ) ;
F_50 ( L_9 ) ;
}
static void
F_51 ( struct V_35 * V_36 )
{
int V_14 ;
int V_88 ;
struct V_11 * V_12 ;
F_27 ( & V_36 -> V_38 ) ;
F_52 (tcd, i, j) {
F_53 ( & V_12 -> V_19 , & V_36 -> V_38 ) ;
V_12 -> V_18 = 0 ;
if ( V_36 -> V_89 ) {
F_53 ( & V_12 -> V_90 ,
& V_36 -> V_38 ) ;
V_12 -> V_91 = 0 ;
}
}
}
static void F_54 ( struct V_35 * V_36 )
{
struct V_11 * V_12 ;
int V_14 , V_27 ;
F_55 (cpu) {
F_56 (tcd, i, cpu) {
F_53 ( & V_12 -> V_19 , & V_36 -> V_38 ) ;
V_12 -> V_18 = 0 ;
if ( V_36 -> V_89 ) {
F_53 ( & V_12 -> V_90 ,
& V_36 -> V_38 ) ;
V_12 -> V_91 = 0 ;
}
}
}
}
static void F_57 ( struct V_35 * V_36 )
{
F_27 ( & V_36 -> V_38 ) ;
if ( V_85 )
F_51 ( V_36 ) ;
else
F_54 ( V_36 ) ;
}
static void F_58 ( struct V_35 * V_36 )
{
struct V_11 * V_12 ;
struct V_2 * V_92 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
int V_14 , V_27 ;
F_55 (cpu) {
F_56 (tcd, i, cpu) {
V_92 = V_12 -> V_19 . V_39 ;
F_28 (tage, tmp, &pc->pc_pages,
linkage) {
F_59 ( V_7 ) ;
if ( V_7 -> V_27 != V_27 || V_7 -> type != V_14 )
continue;
F_14 ( V_7 , V_92 ) ;
V_12 -> V_18 ++ ;
}
}
}
}
static void F_60 ( struct V_35 * V_36 )
{
if ( ! V_85 )
F_58 ( V_36 ) ;
}
static void F_29 ( struct V_35 * V_36 ,
struct V_11 * V_12 )
{
struct V_1 * V_7 ;
struct V_1 * V_37 ;
F_28 (tage, tmp, &pc->pc_pages, linkage) {
F_59 ( V_7 ) ;
if ( V_7 -> V_27 != V_12 -> V_93 || V_7 -> type != V_12 -> V_28 )
continue;
F_14 ( V_7 , & V_12 -> V_90 ) ;
V_12 -> V_91 ++ ;
if ( V_12 -> V_91 > V_12 -> V_23 ) {
struct V_1 * V_94 ;
F_11 ( ! F_19 ( & V_12 -> V_90 ) ) ;
V_94 = F_1 ( V_12 -> V_90 . V_39 ) ;
F_59 ( V_94 ) ;
F_61 ( & V_94 -> V_4 ) ;
F_10 ( V_94 ) ;
V_12 -> V_91 -- ;
}
}
}
static void F_62 ( struct V_35 * V_36 )
{
struct V_11 * V_12 ;
int V_14 , V_27 ;
F_55 (cpu) {
F_56 (tcd, i, cpu)
F_29 ( V_36 , V_12 ) ;
}
}
void F_63 ( void )
{
struct V_35 V_36 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
V_36 . V_89 = 1 ;
F_57 ( & V_36 ) ;
F_28 (tage, tmp, &pc.pc_pages, linkage) {
char * V_95 , * V_58 , * V_96 ;
struct V_6 * V_6 ;
F_59 ( V_7 ) ;
V_6 = V_7 -> V_6 ;
V_95 = F_40 ( V_6 ) ;
while ( V_95 < ( ( char * ) F_40 ( V_6 ) + V_7 -> V_21 ) ) {
struct V_46 * V_84 ;
int V_17 ;
V_84 = ( void * ) V_95 ;
V_95 += sizeof( * V_84 ) ;
V_58 = V_95 ;
V_95 += strlen ( V_58 ) + 1 ;
V_96 = V_95 ;
V_95 += strlen ( V_96 ) + 1 ;
V_17 = V_84 -> V_73 - ( int ) ( V_95 - ( char * ) V_84 ) ;
F_45 ( V_84 , V_87 , V_95 , V_17 , V_58 , V_96 ) ;
V_95 += V_17 ;
}
F_61 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
}
int F_64 ( char * V_97 )
{
struct V_35 V_36 ;
struct V_58 * V_98 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
char * V_99 ;
int V_43 ;
V_100 ;
F_65 () ;
V_98 = F_66 ( V_97 , V_101 | V_102 | V_103 | V_104 , 0600 ) ;
if ( F_67 ( V_98 ) ) {
V_43 = F_68 ( V_98 ) ;
V_98 = NULL ;
F_31 ( L_10 ,
V_97 , V_43 ) ;
goto V_105;
}
V_36 . V_89 = 1 ;
F_57 ( & V_36 ) ;
if ( F_19 ( & V_36 . V_38 ) ) {
V_43 = 0 ;
goto V_106;
}
V_107 ;
F_28 (tage, tmp, &pc.pc_pages, linkage) {
F_59 ( V_7 ) ;
V_99 = F_69 ( V_7 -> V_6 ) ;
V_43 = F_70 ( V_98 , ( V_108 const char V_109 * ) V_99 ,
V_7 -> V_21 , & V_98 -> V_110 ) ;
F_71 ( V_7 -> V_6 ) ;
if ( V_43 != ( int ) V_7 -> V_21 ) {
F_23 ( V_26 L_11 ,
V_7 -> V_21 , V_43 ) ;
F_60 ( & V_36 ) ;
F_11 ( F_19 ( & V_36 . V_38 ) ) ;
break;
}
F_61 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
V_111 ;
V_43 = F_72 ( V_98 , 1 ) ;
if ( V_43 )
F_31 ( L_12 , V_43 ) ;
V_106:
F_73 ( V_98 , NULL ) ;
V_105:
F_74 () ;
return V_43 ;
}
void F_75 ( void )
{
struct V_35 V_36 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
V_36 . V_89 = 1 ;
F_57 ( & V_36 ) ;
F_28 (tage, tmp, &pc.pc_pages, linkage) {
F_59 ( V_7 ) ;
F_61 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
}
int F_76 ( char * V_112 , int V_113 ,
const char V_109 * V_114 , int V_115 )
{
int V_116 ;
if ( V_115 > V_113 )
return - V_117 ;
if ( F_77 ( ( void * ) V_112 ,
V_114 , V_115 ) )
return - V_118 ;
V_116 = F_78 ( V_112 , V_115 ) ;
while ( V_116 -- >= 0 )
if ( ! isspace ( V_112 [ V_116 ] ) )
break;
if ( V_116 < 0 )
return - V_119 ;
if ( V_116 == V_113 )
return - V_117 ;
V_112 [ V_116 + 1 ] = 0 ;
return 0 ;
}
int F_79 ( char V_109 * V_114 , int V_115 ,
const char * V_112 , char * V_120 )
{
int V_116 = strlen ( V_112 ) ;
if ( V_116 > V_115 )
V_116 = V_115 ;
if ( F_80 ( V_114 , V_112 , V_116 ) )
return - V_118 ;
if ( V_120 != NULL && V_116 < V_115 ) {
if ( F_80 ( V_114 + V_116 , V_120 , 1 ) )
return - V_118 ;
V_116 ++ ;
}
return V_116 ;
}
int F_81 ( char * * V_83 , int V_116 )
{
if ( V_116 > 2 * V_22 )
return - V_119 ;
* V_83 = F_7 ( V_116 , V_121 | V_122 ) ;
if ( * V_83 == NULL )
return - V_123 ;
return 0 ;
}
int F_82 ( void V_109 * V_124 , int V_125 )
{
char * V_83 ;
int V_43 ;
V_43 = F_81 ( & V_83 , V_125 + 1 ) ;
if ( V_43 != 0 )
return V_43 ;
V_43 = F_76 ( V_83 , V_125 + 1 ,
V_124 , V_125 ) ;
if ( V_43 != 0 )
goto V_105;
if ( V_83 [ 0 ] != '/' ) {
V_43 = - V_119 ;
goto V_105;
}
V_43 = F_64 ( V_83 ) ;
V_105:
F_12 ( V_83 ) ;
return V_43 ;
}
int F_83 ( char * V_83 )
{
int V_43 = 0 ;
F_65 () ;
if ( strcmp ( V_83 , L_13 ) == 0 ) {
F_74 () ;
F_84 () ;
F_65 () ;
memset ( V_126 , 0 , sizeof( V_126 ) ) ;
} else if ( strncmp ( V_83 , L_14 , 5 ) == 0 ) {
V_127 = F_85 ( V_83 + 5 , NULL , 0 ) ;
if ( V_127 < 10 || V_127 > 20480 )
V_127 = V_128 ;
else
V_127 <<= 20 ;
} else if ( strlen ( V_83 ) >= sizeof( V_126 ) ) {
V_43 = - V_129 ;
} else if ( V_83 [ 0 ] != '/' ) {
V_43 = - V_119 ;
} else {
strcpy ( V_126 , V_83 ) ;
F_23 ( V_71
L_15 ,
V_126 ,
( long ) ( V_127 >> 10 ) ) ;
F_86 () ;
}
F_74 () ;
return V_43 ;
}
int F_87 ( void V_109 * V_124 , int V_125 )
{
char * V_83 ;
int V_43 ;
V_43 = F_81 ( & V_83 , V_125 + 1 ) ;
if ( V_43 != 0 )
return V_43 ;
V_43 = F_76 ( V_83 , V_125 + 1 ,
V_124 , V_125 ) ;
if ( V_43 == 0 )
V_43 = F_83 ( V_83 ) ;
F_12 ( V_83 ) ;
return V_43 ;
}
int F_88 ( int F_49 )
{
int V_14 ;
int V_88 ;
int V_130 ;
int V_131 = F_89 () ;
struct V_11 * V_12 ;
if ( F_49 < F_90 () ) {
F_23 ( V_26
L_16 ,
F_49 , F_90 () ) ;
F_49 = F_90 () ;
}
if ( F_49 > V_131 ) {
F_23 ( V_26
L_17 ,
F_49 , V_131 ) ;
F_49 = V_131 ;
}
F_49 /= F_90 () ;
V_130 = F_49 << ( 20 - V_132 ) ;
F_65 () ;
F_52 (tcd, i, j)
V_12 -> V_23 = ( V_130 * V_12 -> V_133 ) / 100 ;
F_74 () ;
return 0 ;
}
int F_91 ( void )
{
int V_14 ;
int V_88 ;
struct V_11 * V_12 ;
int V_134 = 0 ;
F_92 () ;
F_52 (tcd, i, j)
V_134 += V_12 -> V_23 ;
F_93 () ;
return ( V_134 >> ( 20 - V_132 ) ) + 1 ;
}
static int F_94 ( void * V_135 )
{
struct V_35 V_36 ;
struct V_30 * V_31 = V_135 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
struct V_58 * V_98 ;
char * V_99 ;
int V_136 = 0 ;
int V_43 ;
V_100 ;
F_95 ( & V_31 -> V_137 ) ;
while ( 1 ) {
T_3 V_138 ;
V_36 . V_89 = 0 ;
F_57 ( & V_36 ) ;
if ( F_19 ( & V_36 . V_38 ) )
goto V_139;
V_98 = NULL ;
F_92 () ;
if ( V_126 [ 0 ] != 0 ) {
V_98 = F_66 ( V_126 ,
V_101 | V_140 | V_104 ,
0600 ) ;
if ( F_67 ( V_98 ) ) {
V_43 = F_68 ( V_98 ) ;
V_98 = NULL ;
F_23 ( V_26 L_18 ,
V_126 , V_43 ) ;
}
}
F_93 () ;
if ( V_98 == NULL ) {
F_62 ( & V_36 ) ;
F_11 ( F_19 ( & V_36 . V_38 ) ) ;
goto V_139;
}
V_107 ;
F_28 (tage, tmp, &pc.pc_pages,
linkage) {
static T_4 V_110 ;
F_59 ( V_7 ) ;
if ( V_110 >= ( V_141 ) V_127 )
V_110 = 0 ;
else if ( V_110 > F_96 ( F_97 ( V_98 ) ) )
V_110 = F_96 ( F_97 ( V_98 ) ) ;
V_99 = F_69 ( V_7 -> V_6 ) ;
V_43 = F_70 ( V_98 , ( V_108 const char V_109 * ) V_99 ,
V_7 -> V_21 , & V_110 ) ;
F_71 ( V_7 -> V_6 ) ;
if ( V_43 != ( int ) V_7 -> V_21 ) {
F_23 ( V_26 L_11 ,
V_7 -> V_21 , V_43 ) ;
F_60 ( & V_36 ) ;
F_11 ( F_19 ( & V_36 . V_38 ) ) ;
break;
}
}
V_111 ;
F_73 ( V_98 , NULL ) ;
F_62 ( & V_36 ) ;
if ( ! F_19 ( & V_36 . V_38 ) ) {
int V_14 ;
F_23 ( V_142 L_19 ) ;
F_31 ( L_20 ,
F_90 () ) ;
for ( V_14 = 0 ; V_14 < F_90 () ; V_14 ++ )
if ( F_98 ( V_14 ) )
F_99 ( L_21 , V_14 ) ;
else
F_99 ( L_22 , V_14 ) ;
F_99 ( L_23 ) ;
V_14 = 0 ;
F_28 (tage, tmp, &pc.pc_pages,
linkage)
F_31 ( L_24 ,
++ V_14 , V_7 -> V_27 ) ;
F_31 ( L_25 , V_14 ) ;
}
F_11 ( F_19 ( & V_36 . V_38 ) ) ;
V_139:
if ( F_100 ( & V_31 -> V_143 ) ) {
if ( V_136 == 0 ) {
V_136 = 1 ;
continue;
} else {
break;
}
}
F_101 ( & V_138 , V_144 ) ;
F_102 ( & V_31 -> V_33 , & V_138 ) ;
F_103 ( V_145 ) ;
F_104 ( F_44 ( 1 ) ) ;
F_105 ( & V_31 -> V_33 , & V_138 ) ;
}
F_95 ( & V_31 -> V_146 ) ;
return 0 ;
}
int F_86 ( void )
{
struct V_30 * V_31 = & V_32 ;
int V_43 = 0 ;
F_106 ( & V_147 ) ;
if ( V_29 )
goto V_105;
F_107 ( & V_31 -> V_137 ) ;
F_107 ( & V_31 -> V_146 ) ;
F_108 ( & V_31 -> V_33 ) ;
F_109 ( & V_31 -> V_143 , 0 ) ;
if ( F_67 ( F_110 ( F_94 , V_31 , L_26 ) ) ) {
V_43 = - V_148 ;
goto V_105;
}
F_111 ( & V_31 -> V_137 ) ;
V_29 = 1 ;
V_105:
F_112 ( & V_147 ) ;
return V_43 ;
}
void F_84 ( void )
{
struct V_30 * V_31 = & V_32 ;
F_106 ( & V_147 ) ;
if ( V_29 ) {
F_23 ( V_71
L_27 ) ;
F_109 ( & V_31 -> V_143 , 1 ) ;
F_111 ( & V_31 -> V_146 ) ;
V_29 = 0 ;
}
F_112 ( & V_147 ) ;
}
int F_113 ( int V_149 )
{
struct V_11 * V_12 ;
int V_14 ;
int V_88 ;
int V_43 ;
int V_150 ;
V_43 = F_114 () ;
if ( V_43 != 0 )
return V_43 ;
F_52 (tcd, i, j) {
V_150 = V_12 -> V_133 ;
F_27 ( & V_12 -> V_19 ) ;
F_27 ( & V_12 -> V_24 ) ;
F_27 ( & V_12 -> V_90 ) ;
V_12 -> V_18 = 0 ;
V_12 -> V_15 = 0 ;
V_12 -> V_91 = 0 ;
V_12 -> V_23 = ( V_149 * V_150 ) / 100 ;
F_115 ( V_12 -> V_23 > 0 ) ;
V_12 -> V_66 = 0 ;
}
return 0 ;
}
static void F_116 ( void )
{
struct V_11 * V_12 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
int V_14 , V_27 ;
F_55 (cpu) {
F_56 (tcd, i, cpu) {
V_12 -> V_66 = 1 ;
F_28 (tage, tmp, &tcd->tcd_pages,
linkage) {
F_59 ( V_7 ) ;
F_61 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
V_12 -> V_18 = 0 ;
}
}
}
static void F_117 ( void )
{
struct V_35 V_36 ;
F_27 ( & V_36 . V_38 ) ;
F_116 () ;
F_118 () ;
}
void F_119 ( void )
{
F_84 () ;
F_117 () ;
}
