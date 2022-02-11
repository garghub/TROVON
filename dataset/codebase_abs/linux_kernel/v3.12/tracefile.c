static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static struct V_1 * F_3 ( int V_5 )
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
int F_16 ( struct V_11 * V_12 , int V_5 ,
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
F_23 ( V_26 L_2
L_3 ,
V_34 + 1 , V_12 -> V_18 ) ;
F_27 ( & V_36 . V_38 ) ;
F_28 ( & V_36 . V_39 ) ;
F_29 (tage, tmp, &tcd->tcd_pages, linkage) {
if ( V_34 -- == 0 )
break;
F_15 ( & V_7 -> V_4 , & V_36 . V_38 ) ;
V_12 -> V_18 -- ;
}
F_30 ( & V_36 , V_12 ) ;
}
static struct V_1 * F_31 ( struct V_11 * V_12 ,
unsigned long V_17 )
{
struct V_1 * V_7 ;
if ( V_17 > V_22 ) {
F_23 ( V_40
L_4 , V_17 ) ;
return NULL ;
}
V_7 = F_18 ( V_12 , V_17 ) ;
if ( V_7 != NULL )
return V_7 ;
if ( V_29 )
F_26 ( V_12 ) ;
if ( V_12 -> V_18 > 0 ) {
V_7 = F_1 ( V_12 -> V_19 . V_41 ) ;
V_7 -> V_21 = 0 ;
F_14 ( V_7 , & V_12 -> V_19 ) ;
}
return V_7 ;
}
int F_32 ( struct V_42 * V_43 ,
const char * V_44 , ... )
{
T_1 args ;
int V_45 ;
va_start ( args , V_44 ) ;
V_45 = F_33 ( V_43 , V_44 , args , NULL ) ;
va_end ( args ) ;
return V_45 ;
}
int F_33 ( struct V_42 * V_43 ,
const char * V_46 , T_1 args ,
const char * V_47 , ... )
{
struct V_11 * V_12 = NULL ;
struct V_48 V_49 = { 0 } ;
struct V_1 * V_7 ;
char * V_50 = NULL ;
char * V_51 ;
int V_52 ;
int V_53 = 85 ;
int V_54 ;
T_1 V_55 ;
int V_56 ;
int V_14 ;
int V_57 ;
int V_58 = V_43 -> V_59 ;
const char * V_60 = F_34 ( V_43 -> V_61 ) ;
T_2 * V_62 = V_43 -> V_63 ;
V_12 = F_35 () ;
F_36 ( & V_49 , V_43 , F_37 () ) ;
if ( V_12 == NULL )
goto V_64;
if ( V_12 -> V_18 == 0 )
V_49 . V_65 |= V_66 ;
if ( V_12 -> V_67 ) {
F_38 ( V_12 ) ;
V_12 = NULL ;
goto V_64;
}
V_56 = F_39 () ;
V_52 = strlen ( V_60 ) + 1 + V_56 ;
if ( V_43 -> V_68 )
V_52 += strlen ( V_43 -> V_68 ) + 1 ;
if ( V_69 )
V_52 += sizeof( V_49 ) ;
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ ) {
V_7 = F_31 ( V_12 , V_53 + V_52 + 1 ) ;
if ( V_7 == NULL ) {
if ( V_53 + V_52 > V_22 )
V_58 |= V_70 ;
F_38 ( V_12 ) ;
V_12 = NULL ;
goto V_64;
}
V_50 = ( char * ) F_40 ( V_7 -> V_6 ) +
V_7 -> V_21 + V_52 ;
V_54 = V_22 - V_7 -> V_21 - V_52 ;
if ( V_54 <= 0 ) {
F_23 ( V_71 L_5 ,
V_54 ) ;
V_58 |= V_70 ;
F_38 ( V_12 ) ;
V_12 = NULL ;
goto V_64;
}
V_53 = 0 ;
if ( V_46 ) {
F_41 ( V_55 , args ) ;
V_53 = vsnprintf ( V_50 , V_54 , V_46 , V_55 ) ;
va_end ( V_55 ) ;
}
if ( V_47 ) {
V_57 = V_54 - V_53 ;
if ( V_57 < 0 )
V_57 = 0 ;
va_start ( V_55 , V_47 ) ;
V_53 += vsnprintf ( V_50 + V_53 , V_57 ,
V_47 , V_55 ) ;
va_end ( V_55 ) ;
}
if ( V_53 < V_54 )
break;
}
if ( * ( V_50 + V_53 - 1 ) != '\n' )
F_23 ( V_72 L_6
L_7 , V_60 , V_43 -> V_73 , V_43 -> V_68 ) ;
V_49 . V_74 = V_52 + V_53 ;
V_51 = ( char * ) F_40 ( V_7 -> V_6 ) + V_7 -> V_21 ;
if ( V_69 ) {
memcpy ( V_51 , & V_49 , sizeof( V_49 ) ) ;
V_7 -> V_21 += sizeof( V_49 ) ;
V_51 += sizeof( V_49 ) ;
}
while ( V_56 -- > 0 ) {
* ( V_51 ++ ) = '.' ;
++ V_7 -> V_21 ;
}
strcpy ( V_51 , V_60 ) ;
V_7 -> V_21 += strlen ( V_60 ) + 1 ;
V_51 += strlen ( V_60 ) + 1 ;
if ( V_43 -> V_68 ) {
strcpy ( V_51 , V_43 -> V_68 ) ;
V_7 -> V_21 += strlen ( V_43 -> V_68 ) + 1 ;
V_51 += strlen ( V_43 -> V_68 ) + 1 ;
}
F_11 ( V_51 == V_50 ) ;
V_7 -> V_21 += V_53 ;
F_11 ( V_7 -> V_21 <= V_22 ) ;
V_64:
if ( ( V_58 & V_75 ) == 0 ) {
if ( V_12 != NULL )
F_38 ( V_12 ) ;
return 1 ;
}
if ( V_62 != NULL ) {
if ( V_76 &&
V_62 -> V_77 != 0 &&
! F_42 ( F_43 () , V_62 -> V_77 ) ) {
V_62 -> V_78 ++ ;
if ( V_12 != NULL )
F_38 ( V_12 ) ;
return 1 ;
}
if ( F_42 ( F_43 () , V_62 -> V_77 +
V_79
+ F_44 ( 10 ) ) ) {
V_62 -> V_80 /= V_81 * 4 ;
} else {
V_62 -> V_80 *= V_81 ;
if ( V_62 -> V_80 < V_82 )
V_62 -> V_80 = V_82 ;
else if ( V_62 -> V_80 > V_79 )
V_62 -> V_80 = V_79 ;
}
V_62 -> V_77 = ( F_43 () + V_62 -> V_80 ) | 1 ;
}
if ( V_12 != NULL ) {
F_45 ( & V_49 , V_58 , V_50 , V_53 , V_60 ,
V_43 -> V_68 ) ;
F_38 ( V_12 ) ;
} else {
V_50 = F_46 () ;
V_53 = 0 ;
if ( V_46 != NULL ) {
F_41 ( V_55 , args ) ;
V_53 = vsnprintf ( V_50 ,
V_83 ,
V_46 , V_55 ) ;
va_end ( V_55 ) ;
}
if ( V_47 != NULL ) {
V_57 = V_83 - V_53 ;
if ( V_57 > 0 ) {
va_start ( V_55 , V_47 ) ;
V_53 += vsnprintf ( V_50 + V_53 , V_57 ,
V_47 , V_55 ) ;
va_end ( V_55 ) ;
}
}
F_45 ( & V_49 , V_58 ,
V_50 , V_53 , V_60 , V_43 -> V_68 ) ;
F_47 ( V_50 ) ;
}
if ( V_62 != NULL && V_62 -> V_78 != 0 ) {
V_50 = F_46 () ;
V_53 = snprintf ( V_50 , V_83 ,
L_8 ,
V_62 -> V_78 ,
( V_62 -> V_78 > 1 ) ? L_9 : L_10 ) ;
F_45 ( & V_49 , V_58 ,
V_50 , V_53 , V_60 , V_43 -> V_68 ) ;
F_47 ( V_50 ) ;
V_62 -> V_78 = 0 ;
}
return 0 ;
}
void
F_48 ( const char * V_84 ,
struct V_42 * V_43 )
{
struct V_48 V_85 ;
V_86 = 1 ;
V_87 = 1 ;
F_49 () ;
F_36 ( & V_85 , V_43 , F_37 () ) ;
F_45 ( & V_85 , V_88 , V_84 , strlen ( V_84 ) ,
V_43 -> V_61 , V_43 -> V_68 ) ;
F_50 ( L_11 ) ;
}
static void
F_51 ( struct V_35 * V_36 )
{
int V_14 ;
int V_89 ;
struct V_11 * V_12 ;
F_27 ( & V_36 -> V_38 ) ;
F_52 (tcd, i, j) {
F_53 ( & V_12 -> V_19 , & V_36 -> V_38 ) ;
V_12 -> V_18 = 0 ;
if ( V_36 -> V_90 ) {
F_53 ( & V_12 -> V_91 ,
& V_36 -> V_38 ) ;
V_12 -> V_92 = 0 ;
}
}
}
static void F_54 ( struct V_35 * V_36 )
{
struct V_11 * V_12 ;
int V_14 , V_27 ;
F_55 ( & V_36 -> V_39 ) ;
F_56 (cpu) {
F_57 (tcd, i, cpu) {
F_53 ( & V_12 -> V_19 , & V_36 -> V_38 ) ;
V_12 -> V_18 = 0 ;
if ( V_36 -> V_90 ) {
F_53 ( & V_12 -> V_91 ,
& V_36 -> V_38 ) ;
V_12 -> V_92 = 0 ;
}
}
}
F_58 ( & V_36 -> V_39 ) ;
}
static void F_59 ( struct V_35 * V_36 )
{
F_27 ( & V_36 -> V_38 ) ;
if ( V_86 )
F_51 ( V_36 ) ;
else
F_54 ( V_36 ) ;
}
static void F_60 ( struct V_35 * V_36 )
{
struct V_11 * V_12 ;
struct V_2 * V_93 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
int V_14 , V_27 ;
F_55 ( & V_36 -> V_39 ) ;
F_56 (cpu) {
F_57 (tcd, i, cpu) {
V_93 = V_12 -> V_19 . V_41 ;
F_29 (tage, tmp, &pc->pc_pages,
linkage) {
F_61 ( V_7 ) ;
if ( V_7 -> V_27 != V_27 || V_7 -> type != V_14 )
continue;
F_14 ( V_7 , V_93 ) ;
V_12 -> V_18 ++ ;
}
}
}
F_58 ( & V_36 -> V_39 ) ;
}
static void F_62 ( struct V_35 * V_36 )
{
if ( ! V_86 )
F_60 ( V_36 ) ;
}
static void F_30 ( struct V_35 * V_36 ,
struct V_11 * V_12 )
{
struct V_1 * V_7 ;
struct V_1 * V_37 ;
F_55 ( & V_36 -> V_39 ) ;
F_29 (tage, tmp, &pc->pc_pages, linkage) {
F_61 ( V_7 ) ;
if ( V_7 -> V_27 != V_12 -> V_94 || V_7 -> type != V_12 -> V_28 )
continue;
F_14 ( V_7 , & V_12 -> V_91 ) ;
V_12 -> V_92 ++ ;
if ( V_12 -> V_92 > V_12 -> V_23 ) {
struct V_1 * V_95 ;
F_11 ( ! F_19 ( & V_12 -> V_91 ) ) ;
V_95 = F_1 ( V_12 -> V_91 . V_41 ) ;
F_61 ( V_95 ) ;
F_63 ( & V_95 -> V_4 ) ;
F_10 ( V_95 ) ;
V_12 -> V_92 -- ;
}
}
F_58 ( & V_36 -> V_39 ) ;
}
static void F_64 ( struct V_35 * V_36 )
{
struct V_11 * V_12 ;
int V_14 , V_27 ;
F_56 (cpu) {
F_57 (tcd, i, cpu)
F_30 ( V_36 , V_12 ) ;
}
}
void F_65 ( void )
{
struct V_35 V_36 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
F_28 ( & V_36 . V_39 ) ;
V_36 . V_90 = 1 ;
F_59 ( & V_36 ) ;
F_29 (tage, tmp, &pc.pc_pages, linkage) {
char * V_96 , * V_60 , * V_97 ;
struct V_6 * V_6 ;
F_61 ( V_7 ) ;
V_6 = V_7 -> V_6 ;
V_96 = F_40 ( V_6 ) ;
while ( V_96 < ( ( char * ) F_40 ( V_6 ) + V_7 -> V_21 ) ) {
struct V_48 * V_85 ;
int V_17 ;
V_85 = ( void * ) V_96 ;
V_96 += sizeof( * V_85 ) ;
V_60 = V_96 ;
V_96 += strlen ( V_60 ) + 1 ;
V_97 = V_96 ;
V_96 += strlen ( V_97 ) + 1 ;
V_17 = V_85 -> V_74 - ( int ) ( V_96 - ( char * ) V_85 ) ;
F_45 ( V_85 , V_88 , V_96 , V_17 , V_60 , V_97 ) ;
V_96 += V_17 ;
}
F_63 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
}
int F_66 ( char * V_98 )
{
struct V_35 V_36 ;
struct V_60 * V_99 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
int V_45 ;
V_100 ;
F_67 () ;
V_99 = F_68 ( V_98 , V_101 | V_102 | V_103 | V_104 , 0600 ) ;
if ( F_69 ( V_99 ) ) {
V_45 = F_70 ( V_99 ) ;
V_99 = NULL ;
F_23 ( V_40 L_12 ,
V_98 , V_45 ) ;
goto V_105;
}
F_28 ( & V_36 . V_39 ) ;
V_36 . V_90 = 1 ;
F_59 ( & V_36 ) ;
if ( F_19 ( & V_36 . V_38 ) ) {
V_45 = 0 ;
goto V_106;
}
V_107 ;
F_29 (tage, tmp, &pc.pc_pages, linkage) {
F_61 ( V_7 ) ;
V_45 = F_71 ( V_99 , F_40 ( V_7 -> V_6 ) ,
V_7 -> V_21 , F_72 ( V_99 ) ) ;
if ( V_45 != ( int ) V_7 -> V_21 ) {
F_23 ( V_26 L_13
L_14 , V_7 -> V_21 , V_45 ) ;
F_62 ( & V_36 ) ;
F_11 ( F_19 ( & V_36 . V_38 ) ) ;
break;
}
F_63 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
V_108 ;
V_45 = F_73 ( V_99 ) ;
if ( V_45 )
F_23 ( V_40 L_15 , V_45 ) ;
V_106:
F_74 ( V_99 , NULL ) ;
V_105:
F_75 () ;
return V_45 ;
}
void F_76 ( void )
{
struct V_35 V_36 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
F_28 ( & V_36 . V_39 ) ;
V_36 . V_90 = 1 ;
F_59 ( & V_36 ) ;
F_29 (tage, tmp, &pc.pc_pages, linkage) {
F_61 ( V_7 ) ;
F_63 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
}
int F_77 ( char * V_109 , int V_110 ,
const char * V_111 , int V_112 )
{
int V_113 ;
if ( V_112 > V_110 )
return - V_114 ;
if ( F_78 ( ( void * ) V_109 ,
( void * ) V_111 , V_112 ) )
return - V_115 ;
V_113 = F_79 ( V_109 , V_112 ) ;
while ( V_113 -- >= 0 )
if ( ! isspace ( V_109 [ V_113 ] ) )
break;
if ( V_113 < 0 )
return - V_116 ;
if ( V_113 == V_110 )
return - V_114 ;
V_109 [ V_113 + 1 ] = 0 ;
return 0 ;
}
int F_80 ( char * V_111 , int V_112 ,
const char * V_109 , char * V_117 )
{
int V_113 = strlen ( V_109 ) ;
if ( V_113 > V_112 )
V_113 = V_112 ;
if ( F_81 ( V_111 , V_109 , V_113 ) )
return - V_115 ;
if ( V_117 != NULL && V_113 < V_112 ) {
if ( F_81 ( V_111 + V_113 , V_117 , 1 ) )
return - V_115 ;
V_113 ++ ;
}
return V_113 ;
}
int F_82 ( char * * V_84 , int V_113 )
{
if ( V_113 > 2 * V_22 )
return - V_116 ;
* V_84 = F_7 ( V_113 , V_118 | V_119 ) ;
if ( * V_84 == NULL )
return - V_120 ;
return 0 ;
}
void F_83 ( char * V_84 , int V_113 )
{
F_12 ( V_84 ) ;
}
int F_84 ( void * V_121 , int V_122 )
{
char * V_84 ;
int V_45 ;
V_45 = F_82 ( & V_84 , V_122 + 1 ) ;
if ( V_45 != 0 )
return V_45 ;
V_45 = F_77 ( V_84 , V_122 + 1 ,
V_121 , V_122 ) ;
if ( V_45 != 0 )
goto V_105;
if ( V_84 [ 0 ] != '/' ) {
V_45 = - V_116 ;
goto V_105;
}
V_45 = F_66 ( V_84 ) ;
V_105:
F_83 ( V_84 , V_122 + 1 ) ;
return V_45 ;
}
int F_85 ( char * V_84 )
{
int V_45 = 0 ;
F_67 () ;
if ( strcmp ( V_84 , L_16 ) == 0 ) {
F_75 () ;
F_86 () ;
F_67 () ;
memset ( V_123 , 0 , sizeof( V_123 ) ) ;
} else if ( strncmp ( V_84 , L_17 , 5 ) == 0 ) {
V_124 = F_87 ( V_84 + 5 , NULL , 0 ) ;
if ( V_124 < 10 || V_124 > 20480 )
V_124 = V_125 ;
else
V_124 <<= 20 ;
} else if ( strlen ( V_84 ) >= sizeof( V_123 ) ) {
V_45 = - V_126 ;
} else if ( V_84 [ 0 ] != '/' ) {
V_45 = - V_116 ;
} else {
strcpy ( V_123 , V_84 ) ;
F_23 ( V_72
L_18
L_19 , V_123 ,
( long ) ( V_124 >> 10 ) ) ;
F_88 () ;
}
F_75 () ;
return V_45 ;
}
int F_89 ( void * V_121 , int V_122 )
{
char * V_84 ;
int V_45 ;
V_45 = F_82 ( & V_84 , V_122 + 1 ) ;
if ( V_45 != 0 )
return V_45 ;
V_45 = F_77 ( V_84 , V_122 + 1 ,
V_121 , V_122 ) ;
if ( V_45 == 0 )
V_45 = F_85 ( V_84 ) ;
F_83 ( V_84 , V_122 + 1 ) ;
return V_45 ;
}
int F_90 ( int F_49 )
{
int V_14 ;
int V_89 ;
int V_127 ;
int V_128 = F_91 () ;
struct V_11 * V_12 ;
if ( F_49 < F_92 () ) {
F_23 ( V_26
L_20
L_21 , F_49 , F_92 () ) ;
F_49 = F_92 () ;
}
if ( F_49 > V_128 ) {
F_23 ( V_26
L_22
L_21 , F_49 , V_128 ) ;
F_49 = V_128 ;
}
F_49 /= F_92 () ;
V_127 = F_49 << ( 20 - V_129 ) ;
F_67 () ;
F_52 (tcd, i, j)
V_12 -> V_23 = ( V_127 * V_12 -> V_130 ) / 100 ;
F_75 () ;
return 0 ;
}
int F_93 ( void * V_121 , int V_122 )
{
char V_84 [ 32 ] ;
int V_45 ;
V_45 = F_77 ( V_84 , sizeof( V_84 ) , V_121 , V_122 ) ;
if ( V_45 < 0 )
return V_45 ;
return F_90 ( F_87 ( V_84 , NULL , 0 ) ) ;
}
int F_94 ( void )
{
int V_14 ;
int V_89 ;
struct V_11 * V_12 ;
int V_131 = 0 ;
F_95 () ;
F_52 (tcd, i, j)
V_131 += V_12 -> V_23 ;
F_96 () ;
return ( V_131 >> ( 20 - V_129 ) ) + 1 ;
}
static int F_97 ( void * V_132 )
{
struct V_35 V_36 ;
struct V_30 * V_31 = V_132 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
struct V_60 * V_99 ;
int V_133 = 0 ;
int V_45 ;
V_100 ;
F_28 ( & V_36 . V_39 ) ;
F_98 ( & V_31 -> V_134 ) ;
while ( 1 ) {
T_3 V_135 ;
V_36 . V_90 = 0 ;
F_59 ( & V_36 ) ;
if ( F_19 ( & V_36 . V_38 ) )
goto V_136;
V_99 = NULL ;
F_95 () ;
if ( V_123 [ 0 ] != 0 ) {
V_99 = F_68 ( V_123 ,
V_101 | V_137 | V_104 ,
0600 ) ;
if ( F_69 ( V_99 ) ) {
V_45 = F_70 ( V_99 ) ;
V_99 = NULL ;
F_23 ( V_26 L_23
L_14 , V_123 , V_45 ) ;
}
}
F_96 () ;
if ( V_99 == NULL ) {
F_64 ( & V_36 ) ;
F_11 ( F_19 ( & V_36 . V_38 ) ) ;
goto V_136;
}
V_107 ;
F_29 (tage, tmp, &pc.pc_pages,
linkage) {
static T_4 V_138 ;
F_61 ( V_7 ) ;
if ( V_138 >= ( V_139 ) V_124 )
V_138 = 0 ;
else if ( V_138 > ( V_139 ) F_99 ( V_99 ) )
V_138 = F_99 ( V_99 ) ;
V_45 = F_71 ( V_99 , F_40 ( V_7 -> V_6 ) ,
V_7 -> V_21 , & V_138 ) ;
if ( V_45 != ( int ) V_7 -> V_21 ) {
F_23 ( V_26 L_24
L_25 , V_7 -> V_21 , V_45 ) ;
F_62 ( & V_36 ) ;
F_11 ( F_19 ( & V_36 . V_38 ) ) ;
}
}
V_108 ;
F_74 ( V_99 , NULL ) ;
F_64 ( & V_36 ) ;
if ( ! F_19 ( & V_36 . V_38 ) ) {
int V_14 ;
F_23 ( V_140 L_26
L_27 ) ;
F_23 ( V_40 L_28 ,
F_92 () ) ;
for ( V_14 = 0 ; V_14 < F_92 () ; V_14 ++ )
if ( F_100 ( V_14 ) )
F_23 ( V_40 L_29 , V_14 ) ;
else
F_23 ( V_40 L_30 , V_14 ) ;
F_23 ( V_40 L_31 ) ;
V_14 = 0 ;
F_29 (tage, tmp, &pc.pc_pages,
linkage)
F_23 ( V_40 L_32
L_14 , ++ V_14 , V_7 -> V_27 ) ;
F_23 ( V_40 L_33 ,
V_14 ) ;
}
F_11 ( F_19 ( & V_36 . V_38 ) ) ;
V_136:
if ( F_101 ( & V_31 -> V_141 ) ) {
if ( V_133 == 0 ) {
V_133 = 1 ;
continue;
} else {
break;
}
}
F_102 ( & V_135 ) ;
F_103 ( & V_31 -> V_33 , & V_135 ) ;
F_104 ( V_142 ) ;
F_105 ( & V_135 , V_142 ,
F_44 ( 1 ) ) ;
F_106 ( & V_31 -> V_33 , & V_135 ) ;
}
F_98 ( & V_31 -> V_143 ) ;
return 0 ;
}
int F_88 ( void )
{
struct V_30 * V_31 = & V_32 ;
int V_45 = 0 ;
F_107 ( & V_144 ) ;
if ( V_29 )
goto V_105;
F_108 ( & V_31 -> V_134 ) ;
F_108 ( & V_31 -> V_143 ) ;
F_109 ( & V_31 -> V_33 ) ;
F_110 ( & V_31 -> V_141 , 0 ) ;
if ( F_69 ( F_111 ( F_97 , V_31 , L_34 ) ) ) {
V_45 = - V_145 ;
goto V_105;
}
F_112 ( & V_31 -> V_134 ) ;
V_29 = 1 ;
V_105:
F_113 ( & V_144 ) ;
return V_45 ;
}
void F_86 ( void )
{
struct V_30 * V_31 = & V_32 ;
F_107 ( & V_144 ) ;
if ( V_29 ) {
F_23 ( V_72
L_35 ) ;
F_110 ( & V_31 -> V_141 , 1 ) ;
F_112 ( & V_31 -> V_143 ) ;
V_29 = 0 ;
}
F_113 ( & V_144 ) ;
}
int F_114 ( int V_146 )
{
struct V_11 * V_12 ;
int V_14 ;
int V_89 ;
int V_45 ;
int V_147 ;
V_45 = F_115 () ;
if ( V_45 != 0 )
return V_45 ;
F_52 (tcd, i, j) {
V_147 = V_12 -> V_130 ;
F_27 ( & V_12 -> V_19 ) ;
F_27 ( & V_12 -> V_24 ) ;
F_27 ( & V_12 -> V_91 ) ;
V_12 -> V_18 = 0 ;
V_12 -> V_15 = 0 ;
V_12 -> V_92 = 0 ;
V_12 -> V_23 = ( V_146 * V_147 ) / 100 ;
F_116 ( V_12 -> V_23 > 0 ) ;
V_12 -> V_67 = 0 ;
}
return 0 ;
}
static void F_117 ( void )
{
struct V_11 * V_12 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
int V_14 , V_27 ;
F_56 (cpu) {
F_57 (tcd, i, cpu) {
V_12 -> V_67 = 1 ;
F_29 (tage, tmp, &tcd->tcd_pages,
linkage) {
F_61 ( V_7 ) ;
F_63 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
V_12 -> V_18 = 0 ;
}
}
}
static void F_118 ( void )
{
struct V_35 V_36 ;
F_27 ( & V_36 . V_38 ) ;
F_28 ( & V_36 . V_39 ) ;
F_117 () ;
F_119 () ;
}
void F_120 ( void )
{
F_86 () ;
F_118 () ;
}
