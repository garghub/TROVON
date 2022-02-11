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
F_32 ( L_3 , V_17 ) ;
return NULL ;
}
V_7 = F_18 ( V_12 , V_17 ) ;
if ( V_7 != NULL )
return V_7 ;
if ( V_29 )
F_26 ( V_12 ) ;
if ( V_12 -> V_18 > 0 ) {
V_7 = F_1 ( V_12 -> V_19 . V_40 ) ;
V_7 -> V_21 = 0 ;
F_14 ( V_7 , & V_12 -> V_19 ) ;
}
return V_7 ;
}
int F_33 ( struct V_41 * V_42 ,
const char * V_43 , ... )
{
T_2 args ;
int V_44 ;
va_start ( args , V_43 ) ;
V_44 = F_34 ( V_42 , V_43 , args , NULL ) ;
va_end ( args ) ;
return V_44 ;
}
int F_34 ( struct V_41 * V_42 ,
const char * V_45 , T_2 args ,
const char * V_46 , ... )
{
struct V_11 * V_12 = NULL ;
struct V_47 V_48 = { 0 } ;
struct V_1 * V_7 ;
char * V_49 = NULL ;
char * V_50 ;
int V_51 ;
int V_52 = 85 ;
int V_53 ;
T_2 V_54 ;
int V_55 ;
int V_14 ;
int V_56 ;
int V_57 = V_42 -> V_58 ;
const char * V_59 = F_35 ( V_42 -> V_60 ) ;
struct V_61 * V_62 = V_42 -> V_63 ;
V_12 = F_36 () ;
F_37 ( & V_48 , V_42 , F_38 () ) ;
if ( V_12 == NULL )
goto V_64;
if ( V_12 -> V_18 == 0 )
V_48 . V_65 |= V_66 ;
if ( V_12 -> V_67 ) {
F_39 ( V_12 ) ;
V_12 = NULL ;
goto V_64;
}
V_55 = F_40 () ;
V_51 = strlen ( V_59 ) + 1 + V_55 ;
if ( V_42 -> V_68 )
V_51 += strlen ( V_42 -> V_68 ) + 1 ;
if ( V_69 )
V_51 += sizeof( V_48 ) ;
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ ) {
V_7 = F_31 ( V_12 , V_52 + V_51 + 1 ) ;
if ( V_7 == NULL ) {
if ( V_52 + V_51 > V_22 )
V_57 |= V_70 ;
F_39 ( V_12 ) ;
V_12 = NULL ;
goto V_64;
}
V_49 = ( char * ) F_41 ( V_7 -> V_6 ) +
V_7 -> V_21 + V_51 ;
V_53 = V_22 - V_7 -> V_21 - V_51 ;
if ( V_53 <= 0 ) {
F_23 ( V_71 L_4 ,
V_53 ) ;
V_57 |= V_70 ;
F_39 ( V_12 ) ;
V_12 = NULL ;
goto V_64;
}
V_52 = 0 ;
if ( V_45 ) {
F_42 ( V_54 , args ) ;
V_52 = vsnprintf ( V_49 , V_53 , V_45 , V_54 ) ;
va_end ( V_54 ) ;
}
if ( V_46 ) {
V_56 = V_53 - V_52 ;
if ( V_56 < 0 )
V_56 = 0 ;
va_start ( V_54 , V_46 ) ;
V_52 += vsnprintf ( V_49 + V_52 , V_56 ,
V_46 , V_54 ) ;
va_end ( V_54 ) ;
}
if ( V_52 < V_53 )
break;
}
if ( * ( V_49 + V_52 - 1 ) != '\n' )
F_23 ( V_72 L_5 ,
V_59 , V_42 -> V_73 , V_42 -> V_68 ) ;
V_48 . V_74 = V_51 + V_52 ;
V_50 = ( char * ) F_41 ( V_7 -> V_6 ) + V_7 -> V_21 ;
if ( V_69 ) {
memcpy ( V_50 , & V_48 , sizeof( V_48 ) ) ;
V_7 -> V_21 += sizeof( V_48 ) ;
V_50 += sizeof( V_48 ) ;
}
while ( V_55 -- > 0 ) {
* ( V_50 ++ ) = '.' ;
++ V_7 -> V_21 ;
}
strcpy ( V_50 , V_59 ) ;
V_7 -> V_21 += strlen ( V_59 ) + 1 ;
V_50 += strlen ( V_59 ) + 1 ;
if ( V_42 -> V_68 ) {
strcpy ( V_50 , V_42 -> V_68 ) ;
V_7 -> V_21 += strlen ( V_42 -> V_68 ) + 1 ;
V_50 += strlen ( V_42 -> V_68 ) + 1 ;
}
F_11 ( V_50 == V_49 ) ;
V_7 -> V_21 += V_52 ;
F_11 ( V_7 -> V_21 <= V_22 ) ;
V_64:
if ( ( V_57 & V_75 ) == 0 ) {
if ( V_12 != NULL )
F_39 ( V_12 ) ;
return 1 ;
}
if ( V_62 != NULL ) {
if ( V_76 &&
V_62 -> V_77 != 0 &&
! F_43 ( F_44 () , V_62 -> V_77 ) ) {
V_62 -> V_78 ++ ;
if ( V_12 != NULL )
F_39 ( V_12 ) ;
return 1 ;
}
if ( F_43 ( F_44 () , V_62 -> V_77 +
V_79
+ F_45 ( 10 ) ) ) {
V_62 -> V_80 /= V_81 * 4 ;
} else {
V_62 -> V_80 *= V_81 ;
}
if ( V_62 -> V_80 < V_82 )
V_62 -> V_80 = V_82 ;
else if ( V_62 -> V_80 > V_79 )
V_62 -> V_80 = V_79 ;
V_62 -> V_77 = ( F_44 () + V_62 -> V_80 ) | 1 ;
}
if ( V_12 != NULL ) {
F_46 ( & V_48 , V_57 , V_49 , V_52 , V_59 ,
V_42 -> V_68 ) ;
F_39 ( V_12 ) ;
} else {
V_49 = F_47 () ;
V_52 = 0 ;
if ( V_45 != NULL ) {
F_42 ( V_54 , args ) ;
V_52 = vsnprintf ( V_49 ,
V_83 ,
V_45 , V_54 ) ;
va_end ( V_54 ) ;
}
if ( V_46 != NULL ) {
V_56 = V_83 - V_52 ;
if ( V_56 > 0 ) {
va_start ( V_54 , V_46 ) ;
V_52 += vsnprintf ( V_49 + V_52 , V_56 ,
V_46 , V_54 ) ;
va_end ( V_54 ) ;
}
}
F_46 ( & V_48 , V_57 ,
V_49 , V_52 , V_59 , V_42 -> V_68 ) ;
F_48 ( V_49 ) ;
}
if ( V_62 != NULL && V_62 -> V_78 != 0 ) {
V_49 = F_47 () ;
V_52 = snprintf ( V_49 , V_83 ,
L_6 ,
V_62 -> V_78 ,
( V_62 -> V_78 > 1 ) ? L_7 : L_8 ) ;
F_46 ( & V_48 , V_57 ,
V_49 , V_52 , V_59 , V_42 -> V_68 ) ;
F_48 ( V_49 ) ;
V_62 -> V_78 = 0 ;
}
return 0 ;
}
void
F_49 ( const char * V_84 ,
struct V_41 * V_42 )
{
struct V_47 V_85 ;
V_86 = 1 ;
V_87 = 1 ;
F_50 () ;
F_37 ( & V_85 , V_42 , F_38 () ) ;
F_46 ( & V_85 , V_88 , V_84 , strlen ( V_84 ) ,
V_42 -> V_60 , V_42 -> V_68 ) ;
F_51 ( L_9 ) ;
}
static void
F_52 ( struct V_35 * V_36 )
{
int V_14 ;
int V_89 ;
struct V_11 * V_12 ;
F_27 ( & V_36 -> V_38 ) ;
F_53 (tcd, i, j) {
F_54 ( & V_12 -> V_19 , & V_36 -> V_38 ) ;
V_12 -> V_18 = 0 ;
if ( V_36 -> V_90 ) {
F_54 ( & V_12 -> V_91 ,
& V_36 -> V_38 ) ;
V_12 -> V_92 = 0 ;
}
}
}
static void F_55 ( struct V_35 * V_36 )
{
struct V_11 * V_12 ;
int V_14 , V_27 ;
F_56 ( & V_36 -> V_39 ) ;
F_57 (cpu) {
F_58 (tcd, i, cpu) {
F_54 ( & V_12 -> V_19 , & V_36 -> V_38 ) ;
V_12 -> V_18 = 0 ;
if ( V_36 -> V_90 ) {
F_54 ( & V_12 -> V_91 ,
& V_36 -> V_38 ) ;
V_12 -> V_92 = 0 ;
}
}
}
F_59 ( & V_36 -> V_39 ) ;
}
static void F_60 ( struct V_35 * V_36 )
{
F_27 ( & V_36 -> V_38 ) ;
if ( V_86 )
F_52 ( V_36 ) ;
else
F_55 ( V_36 ) ;
}
static void F_61 ( struct V_35 * V_36 )
{
struct V_11 * V_12 ;
struct V_2 * V_93 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
int V_14 , V_27 ;
F_56 ( & V_36 -> V_39 ) ;
F_57 (cpu) {
F_58 (tcd, i, cpu) {
V_93 = V_12 -> V_19 . V_40 ;
F_29 (tage, tmp, &pc->pc_pages,
linkage) {
F_62 ( V_7 ) ;
if ( V_7 -> V_27 != V_27 || V_7 -> type != V_14 )
continue;
F_14 ( V_7 , V_93 ) ;
V_12 -> V_18 ++ ;
}
}
}
F_59 ( & V_36 -> V_39 ) ;
}
static void F_63 ( struct V_35 * V_36 )
{
if ( ! V_86 )
F_61 ( V_36 ) ;
}
static void F_30 ( struct V_35 * V_36 ,
struct V_11 * V_12 )
{
struct V_1 * V_7 ;
struct V_1 * V_37 ;
F_56 ( & V_36 -> V_39 ) ;
F_29 (tage, tmp, &pc->pc_pages, linkage) {
F_62 ( V_7 ) ;
if ( V_7 -> V_27 != V_12 -> V_94 || V_7 -> type != V_12 -> V_28 )
continue;
F_14 ( V_7 , & V_12 -> V_91 ) ;
V_12 -> V_92 ++ ;
if ( V_12 -> V_92 > V_12 -> V_23 ) {
struct V_1 * V_95 ;
F_11 ( ! F_19 ( & V_12 -> V_91 ) ) ;
V_95 = F_1 ( V_12 -> V_91 . V_40 ) ;
F_62 ( V_95 ) ;
F_64 ( & V_95 -> V_4 ) ;
F_10 ( V_95 ) ;
V_12 -> V_92 -- ;
}
}
F_59 ( & V_36 -> V_39 ) ;
}
static void F_65 ( struct V_35 * V_36 )
{
struct V_11 * V_12 ;
int V_14 , V_27 ;
F_57 (cpu) {
F_58 (tcd, i, cpu)
F_30 ( V_36 , V_12 ) ;
}
}
void F_66 ( void )
{
struct V_35 V_36 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
F_28 ( & V_36 . V_39 ) ;
V_36 . V_90 = 1 ;
F_60 ( & V_36 ) ;
F_29 (tage, tmp, &pc.pc_pages, linkage) {
char * V_96 , * V_59 , * V_97 ;
struct V_6 * V_6 ;
F_62 ( V_7 ) ;
V_6 = V_7 -> V_6 ;
V_96 = F_41 ( V_6 ) ;
while ( V_96 < ( ( char * ) F_41 ( V_6 ) + V_7 -> V_21 ) ) {
struct V_47 * V_85 ;
int V_17 ;
V_85 = ( void * ) V_96 ;
V_96 += sizeof( * V_85 ) ;
V_59 = V_96 ;
V_96 += strlen ( V_59 ) + 1 ;
V_97 = V_96 ;
V_96 += strlen ( V_97 ) + 1 ;
V_17 = V_85 -> V_74 - ( int ) ( V_96 - ( char * ) V_85 ) ;
F_46 ( V_85 , V_88 , V_96 , V_17 , V_59 , V_97 ) ;
V_96 += V_17 ;
}
F_64 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
}
int F_67 ( char * V_98 )
{
struct V_35 V_36 ;
struct V_59 * V_99 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
char * V_100 ;
int V_44 ;
V_101 ;
F_68 () ;
V_99 = F_69 ( V_98 , V_102 | V_103 | V_104 | V_105 , 0600 ) ;
if ( F_70 ( V_99 ) ) {
V_44 = F_71 ( V_99 ) ;
V_99 = NULL ;
F_32 ( L_10 ,
V_98 , V_44 ) ;
goto V_106;
}
F_28 ( & V_36 . V_39 ) ;
V_36 . V_90 = 1 ;
F_60 ( & V_36 ) ;
if ( F_19 ( & V_36 . V_38 ) ) {
V_44 = 0 ;
goto V_107;
}
V_108 ;
F_29 (tage, tmp, &pc.pc_pages, linkage) {
F_62 ( V_7 ) ;
V_100 = F_72 ( V_7 -> V_6 ) ;
V_44 = F_73 ( V_99 , ( V_109 const char V_110 * ) V_100 ,
V_7 -> V_21 , & V_99 -> V_111 ) ;
F_74 ( V_7 -> V_6 ) ;
if ( V_44 != ( int ) V_7 -> V_21 ) {
F_23 ( V_26 L_11 ,
V_7 -> V_21 , V_44 ) ;
F_63 ( & V_36 ) ;
F_11 ( F_19 ( & V_36 . V_38 ) ) ;
break;
}
F_64 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
V_112 ;
V_44 = F_75 ( V_99 , 1 ) ;
if ( V_44 )
F_32 ( L_12 , V_44 ) ;
V_107:
F_76 ( V_99 , NULL ) ;
V_106:
F_77 () ;
return V_44 ;
}
void F_78 ( void )
{
struct V_35 V_36 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
F_28 ( & V_36 . V_39 ) ;
V_36 . V_90 = 1 ;
F_60 ( & V_36 ) ;
F_29 (tage, tmp, &pc.pc_pages, linkage) {
F_62 ( V_7 ) ;
F_64 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
}
int F_79 ( char * V_113 , int V_114 ,
const char V_110 * V_115 , int V_116 )
{
int V_117 ;
if ( V_116 > V_114 )
return - V_118 ;
if ( F_80 ( ( void * ) V_113 ,
V_115 , V_116 ) )
return - V_119 ;
V_117 = F_81 ( V_113 , V_116 ) ;
while ( V_117 -- >= 0 )
if ( ! isspace ( V_113 [ V_117 ] ) )
break;
if ( V_117 < 0 )
return - V_120 ;
if ( V_117 == V_114 )
return - V_118 ;
V_113 [ V_117 + 1 ] = 0 ;
return 0 ;
}
int F_82 ( char V_110 * V_115 , int V_116 ,
const char * V_113 , char * V_121 )
{
int V_117 = strlen ( V_113 ) ;
if ( V_117 > V_116 )
V_117 = V_116 ;
if ( F_83 ( V_115 , V_113 , V_117 ) )
return - V_119 ;
if ( V_121 != NULL && V_117 < V_116 ) {
if ( F_83 ( V_115 + V_117 , V_121 , 1 ) )
return - V_119 ;
V_117 ++ ;
}
return V_117 ;
}
int F_84 ( char * * V_84 , int V_117 )
{
if ( V_117 > 2 * V_22 )
return - V_120 ;
* V_84 = F_7 ( V_117 , V_122 | V_123 ) ;
if ( * V_84 == NULL )
return - V_124 ;
return 0 ;
}
void F_85 ( char * V_84 , int V_117 )
{
F_12 ( V_84 ) ;
}
int F_86 ( void V_110 * V_125 , int V_126 )
{
char * V_84 ;
int V_44 ;
V_44 = F_84 ( & V_84 , V_126 + 1 ) ;
if ( V_44 != 0 )
return V_44 ;
V_44 = F_79 ( V_84 , V_126 + 1 ,
V_125 , V_126 ) ;
if ( V_44 != 0 )
goto V_106;
if ( V_84 [ 0 ] != '/' ) {
V_44 = - V_120 ;
goto V_106;
}
V_44 = F_67 ( V_84 ) ;
V_106:
F_85 ( V_84 , V_126 + 1 ) ;
return V_44 ;
}
int F_87 ( char * V_84 )
{
int V_44 = 0 ;
F_68 () ;
if ( strcmp ( V_84 , L_13 ) == 0 ) {
F_77 () ;
F_88 () ;
F_68 () ;
memset ( V_127 , 0 , sizeof( V_127 ) ) ;
} else if ( strncmp ( V_84 , L_14 , 5 ) == 0 ) {
V_128 = F_89 ( V_84 + 5 , NULL , 0 ) ;
if ( V_128 < 10 || V_128 > 20480 )
V_128 = V_129 ;
else
V_128 <<= 20 ;
} else if ( strlen ( V_84 ) >= sizeof( V_127 ) ) {
V_44 = - V_130 ;
} else if ( V_84 [ 0 ] != '/' ) {
V_44 = - V_120 ;
} else {
strcpy ( V_127 , V_84 ) ;
F_23 ( V_72
L_15 ,
V_127 ,
( long ) ( V_128 >> 10 ) ) ;
F_90 () ;
}
F_77 () ;
return V_44 ;
}
int F_91 ( void V_110 * V_125 , int V_126 )
{
char * V_84 ;
int V_44 ;
V_44 = F_84 ( & V_84 , V_126 + 1 ) ;
if ( V_44 != 0 )
return V_44 ;
V_44 = F_79 ( V_84 , V_126 + 1 ,
V_125 , V_126 ) ;
if ( V_44 == 0 )
V_44 = F_87 ( V_84 ) ;
F_85 ( V_84 , V_126 + 1 ) ;
return V_44 ;
}
int F_92 ( int F_50 )
{
int V_14 ;
int V_89 ;
int V_131 ;
int V_132 = F_93 () ;
struct V_11 * V_12 ;
if ( F_50 < F_94 () ) {
F_23 ( V_26
L_16 ,
F_50 , F_94 () ) ;
F_50 = F_94 () ;
}
if ( F_50 > V_132 ) {
F_23 ( V_26
L_17 ,
F_50 , V_132 ) ;
F_50 = V_132 ;
}
F_50 /= F_94 () ;
V_131 = F_50 << ( 20 - V_133 ) ;
F_68 () ;
F_53 (tcd, i, j)
V_12 -> V_23 = ( V_131 * V_12 -> V_134 ) / 100 ;
F_77 () ;
return 0 ;
}
int F_95 ( void )
{
int V_14 ;
int V_89 ;
struct V_11 * V_12 ;
int V_135 = 0 ;
F_96 () ;
F_53 (tcd, i, j)
V_135 += V_12 -> V_23 ;
F_97 () ;
return ( V_135 >> ( 20 - V_133 ) ) + 1 ;
}
static int F_98 ( void * V_136 )
{
struct V_35 V_36 ;
struct V_30 * V_31 = V_136 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
struct V_59 * V_99 ;
char * V_100 ;
int V_137 = 0 ;
int V_44 ;
V_101 ;
F_28 ( & V_36 . V_39 ) ;
F_99 ( & V_31 -> V_138 ) ;
while ( 1 ) {
T_3 V_139 ;
V_36 . V_90 = 0 ;
F_60 ( & V_36 ) ;
if ( F_19 ( & V_36 . V_38 ) )
goto V_140;
V_99 = NULL ;
F_96 () ;
if ( V_127 [ 0 ] != 0 ) {
V_99 = F_69 ( V_127 ,
V_102 | V_141 | V_105 ,
0600 ) ;
if ( F_70 ( V_99 ) ) {
V_44 = F_71 ( V_99 ) ;
V_99 = NULL ;
F_23 ( V_26 L_18 ,
V_127 , V_44 ) ;
}
}
F_97 () ;
if ( V_99 == NULL ) {
F_65 ( & V_36 ) ;
F_11 ( F_19 ( & V_36 . V_38 ) ) ;
goto V_140;
}
V_108 ;
F_29 (tage, tmp, &pc.pc_pages,
linkage) {
static T_4 V_111 ;
F_62 ( V_7 ) ;
if ( V_111 >= ( V_142 ) V_128 )
V_111 = 0 ;
else if ( V_111 > F_100 ( F_101 ( V_99 ) ) )
V_111 = F_100 ( F_101 ( V_99 ) ) ;
V_100 = F_72 ( V_7 -> V_6 ) ;
V_44 = F_73 ( V_99 , ( V_109 const char V_110 * ) V_100 ,
V_7 -> V_21 , & V_111 ) ;
F_74 ( V_7 -> V_6 ) ;
if ( V_44 != ( int ) V_7 -> V_21 ) {
F_23 ( V_26 L_11 ,
V_7 -> V_21 , V_44 ) ;
F_63 ( & V_36 ) ;
F_11 ( F_19 ( & V_36 . V_38 ) ) ;
break;
}
}
V_112 ;
F_76 ( V_99 , NULL ) ;
F_65 ( & V_36 ) ;
if ( ! F_19 ( & V_36 . V_38 ) ) {
int V_14 ;
F_23 ( V_143 L_19 ) ;
F_32 ( L_20 ,
F_94 () ) ;
for ( V_14 = 0 ; V_14 < F_94 () ; V_14 ++ )
if ( F_102 ( V_14 ) )
F_103 ( L_21 , V_14 ) ;
else
F_103 ( L_22 , V_14 ) ;
F_103 ( L_23 ) ;
V_14 = 0 ;
F_29 (tage, tmp, &pc.pc_pages,
linkage)
F_32 ( L_24 ,
++ V_14 , V_7 -> V_27 ) ;
F_32 ( L_25 , V_14 ) ;
}
F_11 ( F_19 ( & V_36 . V_38 ) ) ;
V_140:
if ( F_104 ( & V_31 -> V_144 ) ) {
if ( V_137 == 0 ) {
V_137 = 1 ;
continue;
} else {
break;
}
}
F_105 ( & V_139 , V_145 ) ;
F_106 ( & V_31 -> V_33 , & V_139 ) ;
F_107 ( V_146 ) ;
F_108 ( F_45 ( 1 ) ) ;
F_109 ( & V_31 -> V_33 , & V_139 ) ;
}
F_99 ( & V_31 -> V_147 ) ;
return 0 ;
}
int F_90 ( void )
{
struct V_30 * V_31 = & V_32 ;
int V_44 = 0 ;
F_110 ( & V_148 ) ;
if ( V_29 )
goto V_106;
F_111 ( & V_31 -> V_138 ) ;
F_111 ( & V_31 -> V_147 ) ;
F_112 ( & V_31 -> V_33 ) ;
F_113 ( & V_31 -> V_144 , 0 ) ;
if ( F_70 ( F_114 ( F_98 , V_31 , L_26 ) ) ) {
V_44 = - V_149 ;
goto V_106;
}
F_115 ( & V_31 -> V_138 ) ;
V_29 = 1 ;
V_106:
F_116 ( & V_148 ) ;
return V_44 ;
}
void F_88 ( void )
{
struct V_30 * V_31 = & V_32 ;
F_110 ( & V_148 ) ;
if ( V_29 ) {
F_23 ( V_72
L_27 ) ;
F_113 ( & V_31 -> V_144 , 1 ) ;
F_115 ( & V_31 -> V_147 ) ;
V_29 = 0 ;
}
F_116 ( & V_148 ) ;
}
int F_117 ( int V_150 )
{
struct V_11 * V_12 ;
int V_14 ;
int V_89 ;
int V_44 ;
int V_151 ;
V_44 = F_118 () ;
if ( V_44 != 0 )
return V_44 ;
F_53 (tcd, i, j) {
V_151 = V_12 -> V_134 ;
F_27 ( & V_12 -> V_19 ) ;
F_27 ( & V_12 -> V_24 ) ;
F_27 ( & V_12 -> V_91 ) ;
V_12 -> V_18 = 0 ;
V_12 -> V_15 = 0 ;
V_12 -> V_92 = 0 ;
V_12 -> V_23 = ( V_150 * V_151 ) / 100 ;
F_119 ( V_12 -> V_23 > 0 ) ;
V_12 -> V_67 = 0 ;
}
return 0 ;
}
static void F_120 ( void )
{
struct V_11 * V_12 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
int V_14 , V_27 ;
F_57 (cpu) {
F_58 (tcd, i, cpu) {
V_12 -> V_67 = 1 ;
F_29 (tage, tmp, &tcd->tcd_pages,
linkage) {
F_62 ( V_7 ) ;
F_64 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
V_12 -> V_18 = 0 ;
}
}
}
static void F_121 ( void )
{
struct V_35 V_36 ;
F_27 ( & V_36 . V_38 ) ;
F_28 ( & V_36 . V_39 ) ;
F_120 () ;
F_122 () ;
}
void F_123 ( void )
{
F_88 () ;
F_121 () ;
}
