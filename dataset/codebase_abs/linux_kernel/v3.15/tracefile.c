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
struct V_62 * V_63 = V_43 -> V_64 ;
V_12 = F_35 () ;
F_36 ( & V_49 , V_43 , F_37 () ) ;
if ( V_12 == NULL )
goto V_65;
if ( V_12 -> V_18 == 0 )
V_49 . V_66 |= V_67 ;
if ( V_12 -> V_68 ) {
F_38 ( V_12 ) ;
V_12 = NULL ;
goto V_65;
}
V_56 = F_39 () ;
V_52 = strlen ( V_60 ) + 1 + V_56 ;
if ( V_43 -> V_69 )
V_52 += strlen ( V_43 -> V_69 ) + 1 ;
if ( V_70 )
V_52 += sizeof( V_49 ) ;
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ ) {
V_7 = F_31 ( V_12 , V_53 + V_52 + 1 ) ;
if ( V_7 == NULL ) {
if ( V_53 + V_52 > V_22 )
V_58 |= V_71 ;
F_38 ( V_12 ) ;
V_12 = NULL ;
goto V_65;
}
V_50 = ( char * ) F_40 ( V_7 -> V_6 ) +
V_7 -> V_21 + V_52 ;
V_54 = V_22 - V_7 -> V_21 - V_52 ;
if ( V_54 <= 0 ) {
F_23 ( V_72 L_5 ,
V_54 ) ;
V_58 |= V_71 ;
F_38 ( V_12 ) ;
V_12 = NULL ;
goto V_65;
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
F_23 ( V_73 L_6
L_7 , V_60 , V_43 -> V_74 , V_43 -> V_69 ) ;
V_49 . V_75 = V_52 + V_53 ;
V_51 = ( char * ) F_40 ( V_7 -> V_6 ) + V_7 -> V_21 ;
if ( V_70 ) {
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
if ( V_43 -> V_69 ) {
strcpy ( V_51 , V_43 -> V_69 ) ;
V_7 -> V_21 += strlen ( V_43 -> V_69 ) + 1 ;
V_51 += strlen ( V_43 -> V_69 ) + 1 ;
}
F_11 ( V_51 == V_50 ) ;
V_7 -> V_21 += V_53 ;
F_11 ( V_7 -> V_21 <= V_22 ) ;
V_65:
if ( ( V_58 & V_76 ) == 0 ) {
if ( V_12 != NULL )
F_38 ( V_12 ) ;
return 1 ;
}
if ( V_63 != NULL ) {
if ( V_77 &&
V_63 -> V_78 != 0 &&
! F_42 ( F_43 () , V_63 -> V_78 ) ) {
V_63 -> V_79 ++ ;
if ( V_12 != NULL )
F_38 ( V_12 ) ;
return 1 ;
}
if ( F_42 ( F_43 () , V_63 -> V_78 +
V_80
+ F_44 ( 10 ) ) ) {
V_63 -> V_81 /= V_82 * 4 ;
} else {
V_63 -> V_81 *= V_82 ;
if ( V_63 -> V_81 < V_83 )
V_63 -> V_81 = V_83 ;
else if ( V_63 -> V_81 > V_80 )
V_63 -> V_81 = V_80 ;
}
V_63 -> V_78 = ( F_43 () + V_63 -> V_81 ) | 1 ;
}
if ( V_12 != NULL ) {
F_45 ( & V_49 , V_58 , V_50 , V_53 , V_60 ,
V_43 -> V_69 ) ;
F_38 ( V_12 ) ;
} else {
V_50 = F_46 () ;
V_53 = 0 ;
if ( V_46 != NULL ) {
F_41 ( V_55 , args ) ;
V_53 = vsnprintf ( V_50 ,
V_84 ,
V_46 , V_55 ) ;
va_end ( V_55 ) ;
}
if ( V_47 != NULL ) {
V_57 = V_84 - V_53 ;
if ( V_57 > 0 ) {
va_start ( V_55 , V_47 ) ;
V_53 += vsnprintf ( V_50 + V_53 , V_57 ,
V_47 , V_55 ) ;
va_end ( V_55 ) ;
}
}
F_45 ( & V_49 , V_58 ,
V_50 , V_53 , V_60 , V_43 -> V_69 ) ;
F_47 ( V_50 ) ;
}
if ( V_63 != NULL && V_63 -> V_79 != 0 ) {
V_50 = F_46 () ;
V_53 = snprintf ( V_50 , V_84 ,
L_8 ,
V_63 -> V_79 ,
( V_63 -> V_79 > 1 ) ? L_9 : L_10 ) ;
F_45 ( & V_49 , V_58 ,
V_50 , V_53 , V_60 , V_43 -> V_69 ) ;
F_47 ( V_50 ) ;
V_63 -> V_79 = 0 ;
}
return 0 ;
}
void
F_48 ( const char * V_85 ,
struct V_42 * V_43 )
{
struct V_48 V_86 ;
V_87 = 1 ;
V_88 = 1 ;
F_49 () ;
F_36 ( & V_86 , V_43 , F_37 () ) ;
F_45 ( & V_86 , V_89 , V_85 , strlen ( V_85 ) ,
V_43 -> V_61 , V_43 -> V_69 ) ;
F_50 ( L_11 ) ;
}
static void
F_51 ( struct V_35 * V_36 )
{
int V_14 ;
int V_90 ;
struct V_11 * V_12 ;
F_27 ( & V_36 -> V_38 ) ;
F_52 (tcd, i, j) {
F_53 ( & V_12 -> V_19 , & V_36 -> V_38 ) ;
V_12 -> V_18 = 0 ;
if ( V_36 -> V_91 ) {
F_53 ( & V_12 -> V_92 ,
& V_36 -> V_38 ) ;
V_12 -> V_93 = 0 ;
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
if ( V_36 -> V_91 ) {
F_53 ( & V_12 -> V_92 ,
& V_36 -> V_38 ) ;
V_12 -> V_93 = 0 ;
}
}
}
F_58 ( & V_36 -> V_39 ) ;
}
static void F_59 ( struct V_35 * V_36 )
{
F_27 ( & V_36 -> V_38 ) ;
if ( V_87 )
F_51 ( V_36 ) ;
else
F_54 ( V_36 ) ;
}
static void F_60 ( struct V_35 * V_36 )
{
struct V_11 * V_12 ;
struct V_2 * V_94 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
int V_14 , V_27 ;
F_55 ( & V_36 -> V_39 ) ;
F_56 (cpu) {
F_57 (tcd, i, cpu) {
V_94 = V_12 -> V_19 . V_41 ;
F_29 (tage, tmp, &pc->pc_pages,
linkage) {
F_61 ( V_7 ) ;
if ( V_7 -> V_27 != V_27 || V_7 -> type != V_14 )
continue;
F_14 ( V_7 , V_94 ) ;
V_12 -> V_18 ++ ;
}
}
}
F_58 ( & V_36 -> V_39 ) ;
}
static void F_62 ( struct V_35 * V_36 )
{
if ( ! V_87 )
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
if ( V_7 -> V_27 != V_12 -> V_95 || V_7 -> type != V_12 -> V_28 )
continue;
F_14 ( V_7 , & V_12 -> V_92 ) ;
V_12 -> V_93 ++ ;
if ( V_12 -> V_93 > V_12 -> V_23 ) {
struct V_1 * V_96 ;
F_11 ( ! F_19 ( & V_12 -> V_92 ) ) ;
V_96 = F_1 ( V_12 -> V_92 . V_41 ) ;
F_61 ( V_96 ) ;
F_63 ( & V_96 -> V_4 ) ;
F_10 ( V_96 ) ;
V_12 -> V_93 -- ;
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
V_36 . V_91 = 1 ;
F_59 ( & V_36 ) ;
F_29 (tage, tmp, &pc.pc_pages, linkage) {
char * V_97 , * V_60 , * V_98 ;
struct V_6 * V_6 ;
F_61 ( V_7 ) ;
V_6 = V_7 -> V_6 ;
V_97 = F_40 ( V_6 ) ;
while ( V_97 < ( ( char * ) F_40 ( V_6 ) + V_7 -> V_21 ) ) {
struct V_48 * V_86 ;
int V_17 ;
V_86 = ( void * ) V_97 ;
V_97 += sizeof( * V_86 ) ;
V_60 = V_97 ;
V_97 += strlen ( V_60 ) + 1 ;
V_98 = V_97 ;
V_97 += strlen ( V_98 ) + 1 ;
V_17 = V_86 -> V_75 - ( int ) ( V_97 - ( char * ) V_86 ) ;
F_45 ( V_86 , V_89 , V_97 , V_17 , V_60 , V_98 ) ;
V_97 += V_17 ;
}
F_63 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
}
int F_66 ( char * V_99 )
{
struct V_35 V_36 ;
struct V_60 * V_100 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
char * V_101 ;
int V_45 ;
V_102 ;
F_67 () ;
V_100 = F_68 ( V_99 , V_103 | V_104 | V_105 | V_106 , 0600 ) ;
if ( F_69 ( V_100 ) ) {
V_45 = F_70 ( V_100 ) ;
V_100 = NULL ;
F_23 ( V_40 L_12 ,
V_99 , V_45 ) ;
goto V_107;
}
F_28 ( & V_36 . V_39 ) ;
V_36 . V_91 = 1 ;
F_59 ( & V_36 ) ;
if ( F_19 ( & V_36 . V_38 ) ) {
V_45 = 0 ;
goto V_108;
}
V_109 ;
F_29 (tage, tmp, &pc.pc_pages, linkage) {
F_61 ( V_7 ) ;
V_101 = F_71 ( V_7 -> V_6 ) ;
V_45 = F_72 ( V_100 , ( V_110 const char V_111 * ) V_101 ,
V_7 -> V_21 , & V_100 -> V_112 ) ;
F_73 ( V_7 -> V_6 ) ;
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
V_113 ;
V_45 = F_74 ( V_100 , 1 ) ;
if ( V_45 )
F_23 ( V_40 L_15 , V_45 ) ;
V_108:
F_75 ( V_100 , NULL ) ;
V_107:
F_76 () ;
return V_45 ;
}
void F_77 ( void )
{
struct V_35 V_36 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
F_28 ( & V_36 . V_39 ) ;
V_36 . V_91 = 1 ;
F_59 ( & V_36 ) ;
F_29 (tage, tmp, &pc.pc_pages, linkage) {
F_61 ( V_7 ) ;
F_63 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
}
int F_78 ( char * V_114 , int V_115 ,
const char * V_116 , int V_117 )
{
int V_118 ;
if ( V_117 > V_115 )
return - V_119 ;
if ( F_79 ( ( void * ) V_114 ,
( void * ) V_116 , V_117 ) )
return - V_120 ;
V_118 = F_80 ( V_114 , V_117 ) ;
while ( V_118 -- >= 0 )
if ( ! isspace ( V_114 [ V_118 ] ) )
break;
if ( V_118 < 0 )
return - V_121 ;
if ( V_118 == V_115 )
return - V_119 ;
V_114 [ V_118 + 1 ] = 0 ;
return 0 ;
}
int F_81 ( char * V_116 , int V_117 ,
const char * V_114 , char * V_122 )
{
int V_118 = strlen ( V_114 ) ;
if ( V_118 > V_117 )
V_118 = V_117 ;
if ( F_82 ( V_116 , V_114 , V_118 ) )
return - V_120 ;
if ( V_122 != NULL && V_118 < V_117 ) {
if ( F_82 ( V_116 + V_118 , V_122 , 1 ) )
return - V_120 ;
V_118 ++ ;
}
return V_118 ;
}
int F_83 ( char * * V_85 , int V_118 )
{
if ( V_118 > 2 * V_22 )
return - V_121 ;
* V_85 = F_7 ( V_118 , V_123 | V_124 ) ;
if ( * V_85 == NULL )
return - V_125 ;
return 0 ;
}
void F_84 ( char * V_85 , int V_118 )
{
F_12 ( V_85 ) ;
}
int F_85 ( void * V_126 , int V_127 )
{
char * V_85 ;
int V_45 ;
V_45 = F_83 ( & V_85 , V_127 + 1 ) ;
if ( V_45 != 0 )
return V_45 ;
V_45 = F_78 ( V_85 , V_127 + 1 ,
V_126 , V_127 ) ;
if ( V_45 != 0 )
goto V_107;
if ( V_85 [ 0 ] != '/' ) {
V_45 = - V_121 ;
goto V_107;
}
V_45 = F_66 ( V_85 ) ;
V_107:
F_84 ( V_85 , V_127 + 1 ) ;
return V_45 ;
}
int F_86 ( char * V_85 )
{
int V_45 = 0 ;
F_67 () ;
if ( strcmp ( V_85 , L_16 ) == 0 ) {
F_76 () ;
F_87 () ;
F_67 () ;
memset ( V_128 , 0 , sizeof( V_128 ) ) ;
} else if ( strncmp ( V_85 , L_17 , 5 ) == 0 ) {
V_129 = F_88 ( V_85 + 5 , NULL , 0 ) ;
if ( V_129 < 10 || V_129 > 20480 )
V_129 = V_130 ;
else
V_129 <<= 20 ;
} else if ( strlen ( V_85 ) >= sizeof( V_128 ) ) {
V_45 = - V_131 ;
} else if ( V_85 [ 0 ] != '/' ) {
V_45 = - V_121 ;
} else {
strcpy ( V_128 , V_85 ) ;
F_23 ( V_73
L_18
L_19 , V_128 ,
( long ) ( V_129 >> 10 ) ) ;
F_89 () ;
}
F_76 () ;
return V_45 ;
}
int F_90 ( void * V_126 , int V_127 )
{
char * V_85 ;
int V_45 ;
V_45 = F_83 ( & V_85 , V_127 + 1 ) ;
if ( V_45 != 0 )
return V_45 ;
V_45 = F_78 ( V_85 , V_127 + 1 ,
V_126 , V_127 ) ;
if ( V_45 == 0 )
V_45 = F_86 ( V_85 ) ;
F_84 ( V_85 , V_127 + 1 ) ;
return V_45 ;
}
int F_91 ( int F_49 )
{
int V_14 ;
int V_90 ;
int V_132 ;
int V_133 = F_92 () ;
struct V_11 * V_12 ;
if ( F_49 < F_93 () ) {
F_23 ( V_26
L_20
L_21 , F_49 , F_93 () ) ;
F_49 = F_93 () ;
}
if ( F_49 > V_133 ) {
F_23 ( V_26
L_22
L_21 , F_49 , V_133 ) ;
F_49 = V_133 ;
}
F_49 /= F_93 () ;
V_132 = F_49 << ( 20 - V_134 ) ;
F_67 () ;
F_52 (tcd, i, j)
V_12 -> V_23 = ( V_132 * V_12 -> V_135 ) / 100 ;
F_76 () ;
return 0 ;
}
int F_94 ( void * V_126 , int V_127 )
{
char V_85 [ 32 ] ;
int V_45 ;
V_45 = F_78 ( V_85 , sizeof( V_85 ) , V_126 , V_127 ) ;
if ( V_45 < 0 )
return V_45 ;
return F_91 ( F_88 ( V_85 , NULL , 0 ) ) ;
}
int F_95 ( void )
{
int V_14 ;
int V_90 ;
struct V_11 * V_12 ;
int V_136 = 0 ;
F_96 () ;
F_52 (tcd, i, j)
V_136 += V_12 -> V_23 ;
F_97 () ;
return ( V_136 >> ( 20 - V_134 ) ) + 1 ;
}
static int F_98 ( void * V_137 )
{
struct V_35 V_36 ;
struct V_30 * V_31 = V_137 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
struct V_60 * V_100 ;
char * V_101 ;
int V_138 = 0 ;
int V_45 ;
V_102 ;
F_28 ( & V_36 . V_39 ) ;
F_99 ( & V_31 -> V_139 ) ;
while ( 1 ) {
T_2 V_140 ;
V_36 . V_91 = 0 ;
F_59 ( & V_36 ) ;
if ( F_19 ( & V_36 . V_38 ) )
goto V_141;
V_100 = NULL ;
F_96 () ;
if ( V_128 [ 0 ] != 0 ) {
V_100 = F_68 ( V_128 ,
V_103 | V_142 | V_106 ,
0600 ) ;
if ( F_69 ( V_100 ) ) {
V_45 = F_70 ( V_100 ) ;
V_100 = NULL ;
F_23 ( V_26 L_23
L_14 , V_128 , V_45 ) ;
}
}
F_97 () ;
if ( V_100 == NULL ) {
F_64 ( & V_36 ) ;
F_11 ( F_19 ( & V_36 . V_38 ) ) ;
goto V_141;
}
V_109 ;
F_29 (tage, tmp, &pc.pc_pages,
linkage) {
static T_3 V_112 ;
F_61 ( V_7 ) ;
if ( V_112 >= ( V_143 ) V_129 )
V_112 = 0 ;
else if ( V_112 > F_100 ( V_100 -> V_144 -> V_145 ) )
V_112 = F_100 ( V_100 -> V_144 -> V_145 ) ;
V_101 = F_71 ( V_7 -> V_6 ) ;
V_45 = F_72 ( V_100 , ( V_110 const char V_111 * ) V_101 ,
V_7 -> V_21 , & V_112 ) ;
F_73 ( V_7 -> V_6 ) ;
if ( V_45 != ( int ) V_7 -> V_21 ) {
F_23 ( V_26 L_24
L_25 , V_7 -> V_21 , V_45 ) ;
F_62 ( & V_36 ) ;
F_11 ( F_19 ( & V_36 . V_38 ) ) ;
}
}
V_113 ;
F_75 ( V_100 , NULL ) ;
F_64 ( & V_36 ) ;
if ( ! F_19 ( & V_36 . V_38 ) ) {
int V_14 ;
F_23 ( V_146 L_26
L_27 ) ;
F_23 ( V_40 L_28 ,
F_93 () ) ;
for ( V_14 = 0 ; V_14 < F_93 () ; V_14 ++ )
if ( F_101 ( V_14 ) )
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
V_141:
if ( F_102 ( & V_31 -> V_147 ) ) {
if ( V_138 == 0 ) {
V_138 = 1 ;
continue;
} else {
break;
}
}
F_103 ( & V_140 , V_148 ) ;
F_104 ( & V_31 -> V_33 , & V_140 ) ;
F_105 ( V_149 ) ;
F_106 ( F_44 ( 1 ) ) ;
F_107 ( & V_31 -> V_33 , & V_140 ) ;
}
F_99 ( & V_31 -> V_150 ) ;
return 0 ;
}
int F_89 ( void )
{
struct V_30 * V_31 = & V_32 ;
int V_45 = 0 ;
F_108 ( & V_151 ) ;
if ( V_29 )
goto V_107;
F_109 ( & V_31 -> V_139 ) ;
F_109 ( & V_31 -> V_150 ) ;
F_110 ( & V_31 -> V_33 ) ;
F_111 ( & V_31 -> V_147 , 0 ) ;
if ( F_69 ( F_112 ( F_98 , V_31 , L_34 ) ) ) {
V_45 = - V_152 ;
goto V_107;
}
F_113 ( & V_31 -> V_139 ) ;
V_29 = 1 ;
V_107:
F_114 ( & V_151 ) ;
return V_45 ;
}
void F_87 ( void )
{
struct V_30 * V_31 = & V_32 ;
F_108 ( & V_151 ) ;
if ( V_29 ) {
F_23 ( V_73
L_35 ) ;
F_111 ( & V_31 -> V_147 , 1 ) ;
F_113 ( & V_31 -> V_150 ) ;
V_29 = 0 ;
}
F_114 ( & V_151 ) ;
}
int F_115 ( int V_153 )
{
struct V_11 * V_12 ;
int V_14 ;
int V_90 ;
int V_45 ;
int V_154 ;
V_45 = F_116 () ;
if ( V_45 != 0 )
return V_45 ;
F_52 (tcd, i, j) {
V_154 = V_12 -> V_135 ;
F_27 ( & V_12 -> V_19 ) ;
F_27 ( & V_12 -> V_24 ) ;
F_27 ( & V_12 -> V_92 ) ;
V_12 -> V_18 = 0 ;
V_12 -> V_15 = 0 ;
V_12 -> V_93 = 0 ;
V_12 -> V_23 = ( V_153 * V_154 ) / 100 ;
F_117 ( V_12 -> V_23 > 0 ) ;
V_12 -> V_68 = 0 ;
}
return 0 ;
}
static void F_118 ( void )
{
struct V_11 * V_12 ;
struct V_1 * V_7 ;
struct V_1 * V_37 ;
int V_14 , V_27 ;
F_56 (cpu) {
F_57 (tcd, i, cpu) {
V_12 -> V_68 = 1 ;
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
static void F_119 ( void )
{
struct V_35 V_36 ;
F_27 ( & V_36 . V_38 ) ;
F_28 ( & V_36 . V_39 ) ;
F_118 () ;
F_120 () ;
}
void F_121 ( void )
{
F_87 () ;
F_119 () ;
}
