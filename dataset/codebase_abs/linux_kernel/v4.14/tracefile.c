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
if ( ! V_6 )
return NULL ;
V_7 = F_7 ( sizeof( * V_7 ) , V_5 ) ;
if ( ! V_7 ) {
F_8 ( V_6 ) ;
return NULL ;
}
V_7 -> V_6 = V_6 ;
F_9 ( & V_9 ) ;
return V_7 ;
}
static void F_10 ( struct V_1 * V_7 )
{
F_8 ( V_7 -> V_6 ) ;
F_11 ( V_7 ) ;
F_12 ( & V_9 ) ;
}
static void F_13 ( struct V_1 * V_7 ,
struct V_2 * V_10 )
{
F_14 ( & V_7 -> V_4 , V_10 ) ;
}
int F_15 ( struct V_11 * V_12 , T_1 V_5 ,
struct V_2 * V_13 )
{
int V_14 ;
for ( V_14 = 0 ; V_14 + V_12 -> V_15 < V_16 ; ++ V_14 ) {
struct V_1 * V_7 ;
V_7 = F_3 ( V_5 ) ;
if ( ! V_7 )
break;
F_16 ( & V_7 -> V_4 , V_13 ) ;
}
return V_14 ;
}
static struct V_1 *
F_17 ( struct V_11 * V_12 , unsigned long V_17 )
{
struct V_1 * V_7 ;
if ( V_12 -> V_18 > 0 ) {
F_18 ( ! F_19 ( & V_12 -> V_19 ) ) ;
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
if ( F_21 ( ! V_7 ) ) {
if ( ! F_5 () || F_4 () )
F_22 ( L_1 ,
V_12 -> V_18 ) ;
return NULL ;
}
}
V_7 -> V_21 = 0 ;
V_7 -> V_26 = F_23 () ;
V_7 -> type = V_12 -> V_27 ;
F_16 ( & V_7 -> V_4 , & V_12 -> V_19 ) ;
V_12 -> V_18 ++ ;
if ( V_12 -> V_18 > 8 && V_28 ) {
struct V_29 * V_30 = & V_31 ;
F_24 ( & V_30 -> V_32 ) ;
}
return V_7 ;
}
return NULL ;
}
static void F_25 ( struct V_11 * V_12 )
{
int V_33 = V_12 -> V_18 / 10 ;
struct V_34 V_35 ;
struct V_1 * V_7 ;
struct V_1 * V_36 ;
F_22 ( L_2 ,
V_33 + 1 , V_12 -> V_18 ) ;
F_26 ( & V_35 . V_37 ) ;
F_27 (tage, tmp, &tcd->tcd_pages, linkage) {
if ( ! V_33 -- )
break;
F_14 ( & V_7 -> V_4 , & V_35 . V_37 ) ;
V_12 -> V_18 -- ;
}
F_28 ( & V_35 , V_12 ) ;
}
static struct V_1 * F_29 ( struct V_11 * V_12 ,
unsigned long V_17 )
{
struct V_1 * V_7 ;
if ( V_17 > V_22 ) {
F_30 ( L_3 , V_17 ) ;
return NULL ;
}
V_7 = F_17 ( V_12 , V_17 ) ;
if ( V_7 )
return V_7 ;
if ( V_28 )
F_25 ( V_12 ) ;
if ( V_12 -> V_18 > 0 ) {
V_7 = F_1 ( V_12 -> V_19 . V_38 ) ;
V_7 -> V_21 = 0 ;
F_13 ( V_7 , & V_12 -> V_19 ) ;
}
return V_7 ;
}
int F_31 ( struct V_39 * V_40 ,
const char * V_41 , ... )
{
T_2 args ;
int V_42 ;
va_start ( args , V_41 ) ;
V_42 = F_32 ( V_40 , V_41 , args , NULL ) ;
va_end ( args ) ;
return V_42 ;
}
int F_32 ( struct V_39 * V_40 ,
const char * V_43 , T_2 args ,
const char * V_44 , ... )
{
struct V_11 * V_12 = NULL ;
struct V_45 V_46 = { 0 } ;
struct V_1 * V_7 ;
char * V_47 = NULL ;
char * V_48 ;
int V_49 ;
int V_50 = 85 ;
int V_51 ;
T_2 V_52 ;
int V_53 ;
int V_14 ;
int V_54 ;
int V_55 = V_40 -> V_56 ;
const char * V_57 = F_33 ( V_40 -> V_58 ) ;
struct V_59 * V_60 = V_40 -> V_61 ;
V_12 = F_34 () ;
F_35 ( & V_46 , V_40 , F_36 () ) ;
if ( ! V_12 )
goto V_62;
if ( ! V_12 -> V_18 )
V_46 . V_63 |= V_64 ;
if ( V_12 -> V_65 ) {
F_37 ( V_12 ) ;
V_12 = NULL ;
goto V_62;
}
V_53 = F_38 () ;
V_49 = strlen ( V_57 ) + 1 + V_53 ;
if ( V_40 -> V_66 )
V_49 += strlen ( V_40 -> V_66 ) + 1 ;
if ( V_67 )
V_49 += sizeof( V_46 ) ;
for ( V_14 = 0 ; V_14 < 2 ; V_14 ++ ) {
V_7 = F_29 ( V_12 , V_50 + V_49 + 1 ) ;
if ( ! V_7 ) {
if ( V_50 + V_49 > V_22 )
V_55 |= V_68 ;
F_37 ( V_12 ) ;
V_12 = NULL ;
goto V_62;
}
V_47 = ( char * ) F_39 ( V_7 -> V_6 ) +
V_7 -> V_21 + V_49 ;
V_51 = V_22 - V_7 -> V_21 - V_49 ;
if ( V_51 <= 0 ) {
F_40 ( L_4 , V_51 ) ;
V_55 |= V_68 ;
F_37 ( V_12 ) ;
V_12 = NULL ;
goto V_62;
}
V_50 = 0 ;
if ( V_43 ) {
F_41 ( V_52 , args ) ;
V_50 = vsnprintf ( V_47 , V_51 , V_43 , V_52 ) ;
va_end ( V_52 ) ;
}
if ( V_44 ) {
V_54 = V_51 - V_50 ;
if ( V_54 < 0 )
V_54 = 0 ;
va_start ( V_52 , V_44 ) ;
V_50 += vsnprintf ( V_47 + V_50 , V_54 ,
V_44 , V_52 ) ;
va_end ( V_52 ) ;
}
if ( V_50 < V_51 )
break;
}
if ( * ( V_47 + V_50 - 1 ) != '\n' )
F_42 ( L_5 , V_57 ,
V_40 -> V_69 , V_40 -> V_66 ) ;
V_46 . V_70 = V_49 + V_50 ;
V_48 = ( char * ) F_39 ( V_7 -> V_6 ) + V_7 -> V_21 ;
if ( V_67 ) {
memcpy ( V_48 , & V_46 , sizeof( V_46 ) ) ;
V_7 -> V_21 += sizeof( V_46 ) ;
V_48 += sizeof( V_46 ) ;
}
while ( V_53 -- > 0 ) {
* ( V_48 ++ ) = '.' ;
++ V_7 -> V_21 ;
}
strcpy ( V_48 , V_57 ) ;
V_7 -> V_21 += strlen ( V_57 ) + 1 ;
V_48 += strlen ( V_57 ) + 1 ;
if ( V_40 -> V_66 ) {
strcpy ( V_48 , V_40 -> V_66 ) ;
V_7 -> V_21 += strlen ( V_40 -> V_66 ) + 1 ;
V_48 += strlen ( V_40 -> V_66 ) + 1 ;
}
F_18 ( V_48 == V_47 ) ;
V_7 -> V_21 += V_50 ;
F_18 ( V_7 -> V_21 <= V_22 ) ;
V_62:
if ( ! ( V_55 & V_71 ) ) {
if ( V_12 )
F_37 ( V_12 ) ;
return 1 ;
}
if ( V_60 ) {
if ( V_72 &&
V_60 -> V_73 &&
! F_43 ( F_44 () , V_60 -> V_73 ) ) {
V_60 -> V_74 ++ ;
if ( V_12 )
F_37 ( V_12 ) ;
return 1 ;
}
if ( F_43 ( F_44 () ,
V_60 -> V_73 + V_75 +
F_45 ( 10 ) ) ) {
V_60 -> V_76 /= V_77 * 4 ;
} else {
V_60 -> V_76 *= V_77 ;
}
if ( V_60 -> V_76 < V_78 )
V_60 -> V_76 = V_78 ;
else if ( V_60 -> V_76 > V_75 )
V_60 -> V_76 = V_75 ;
V_60 -> V_73 = ( F_44 () + V_60 -> V_76 ) | 1 ;
}
if ( V_12 ) {
F_46 ( & V_46 , V_55 , V_47 , V_50 , V_57 ,
V_40 -> V_66 ) ;
F_37 ( V_12 ) ;
} else {
V_47 = F_47 () ;
V_50 = 0 ;
if ( V_43 ) {
F_41 ( V_52 , args ) ;
V_50 = vsnprintf ( V_47 ,
V_79 ,
V_43 , V_52 ) ;
va_end ( V_52 ) ;
}
if ( V_44 ) {
V_54 = V_79 - V_50 ;
if ( V_54 > 0 ) {
va_start ( V_52 , V_44 ) ;
V_50 += vsnprintf ( V_47 + V_50 , V_54 ,
V_44 , V_52 ) ;
va_end ( V_52 ) ;
}
}
F_46 ( & V_46 , V_55 ,
V_47 , V_50 , V_57 , V_40 -> V_66 ) ;
F_48 () ;
}
if ( V_60 && V_60 -> V_74 ) {
V_47 = F_47 () ;
V_50 = snprintf ( V_47 , V_79 ,
L_6 ,
V_60 -> V_74 ,
( V_60 -> V_74 > 1 ) ? L_7 : L_8 ) ;
F_46 ( & V_46 , V_55 ,
V_47 , V_50 , V_57 , V_40 -> V_66 ) ;
F_48 () ;
V_60 -> V_74 = 0 ;
}
return 0 ;
}
void
F_49 ( const char * V_80 ,
struct V_39 * V_40 )
{
struct V_45 V_81 ;
V_82 = 1 ;
V_83 = 1 ;
F_50 () ;
F_35 ( & V_81 , V_40 , F_36 () ) ;
F_46 ( & V_81 , V_84 , V_80 , strlen ( V_80 ) ,
V_40 -> V_58 , V_40 -> V_66 ) ;
F_51 ( L_9 ) ;
}
static void
F_52 ( struct V_34 * V_35 )
{
struct V_11 * V_12 ;
int V_14 ;
int V_85 ;
F_26 ( & V_35 -> V_37 ) ;
F_53 (tcd, i, j) {
F_54 ( & V_12 -> V_19 , & V_35 -> V_37 ) ;
V_12 -> V_18 = 0 ;
if ( V_35 -> V_86 ) {
F_54 ( & V_12 -> V_87 , & V_35 -> V_37 ) ;
V_12 -> V_88 = 0 ;
}
}
}
static void F_55 ( struct V_34 * V_35 )
{
struct V_11 * V_12 ;
int V_14 , V_26 ;
F_56 (cpu) {
F_57 (tcd, i, cpu) {
F_54 ( & V_12 -> V_19 , & V_35 -> V_37 ) ;
V_12 -> V_18 = 0 ;
if ( V_35 -> V_86 ) {
F_54 ( & V_12 -> V_87 ,
& V_35 -> V_37 ) ;
V_12 -> V_88 = 0 ;
}
}
}
}
static void F_58 ( struct V_34 * V_35 )
{
F_26 ( & V_35 -> V_37 ) ;
if ( V_82 )
F_52 ( V_35 ) ;
else
F_55 ( V_35 ) ;
}
static void F_59 ( struct V_34 * V_35 )
{
struct V_11 * V_12 ;
struct V_2 * V_89 ;
struct V_1 * V_7 ;
struct V_1 * V_36 ;
int V_14 , V_26 ;
F_56 (cpu) {
F_57 (tcd, i, cpu) {
V_89 = V_12 -> V_19 . V_38 ;
F_27 (tage, tmp, &pc->pc_pages,
linkage) {
F_60 ( V_7 ) ;
if ( V_7 -> V_26 != V_26 || V_7 -> type != V_14 )
continue;
F_13 ( V_7 , V_89 ) ;
V_12 -> V_18 ++ ;
}
}
}
}
static void F_61 ( struct V_34 * V_35 )
{
if ( ! V_82 )
F_59 ( V_35 ) ;
}
static void F_28 ( struct V_34 * V_35 ,
struct V_11 * V_12 )
{
struct V_1 * V_7 ;
struct V_1 * V_36 ;
F_27 (tage, tmp, &pc->pc_pages, linkage) {
F_60 ( V_7 ) ;
if ( V_7 -> V_26 != V_12 -> V_90 || V_7 -> type != V_12 -> V_27 )
continue;
F_13 ( V_7 , & V_12 -> V_87 ) ;
V_12 -> V_88 ++ ;
if ( V_12 -> V_88 > V_12 -> V_23 ) {
struct V_1 * V_91 ;
F_18 ( ! F_19 ( & V_12 -> V_87 ) ) ;
V_91 = F_1 ( V_12 -> V_87 . V_38 ) ;
F_60 ( V_91 ) ;
F_62 ( & V_91 -> V_4 ) ;
F_10 ( V_91 ) ;
V_12 -> V_88 -- ;
}
}
}
static void F_63 ( struct V_34 * V_35 )
{
struct V_11 * V_12 ;
int V_14 , V_26 ;
F_56 (cpu) {
F_57 (tcd, i, cpu)
F_28 ( V_35 , V_12 ) ;
}
}
void F_64 ( void )
{
struct V_34 V_35 ;
struct V_1 * V_7 ;
struct V_1 * V_36 ;
V_35 . V_86 = 1 ;
F_58 ( & V_35 ) ;
F_27 (tage, tmp, &pc.pc_pages, linkage) {
char * V_92 , * V_57 , * V_93 ;
struct V_6 * V_6 ;
F_60 ( V_7 ) ;
V_6 = V_7 -> V_6 ;
V_92 = F_39 ( V_6 ) ;
while ( V_92 < ( ( char * ) F_39 ( V_6 ) + V_7 -> V_21 ) ) {
struct V_45 * V_81 ;
int V_17 ;
V_81 = ( void * ) V_92 ;
V_92 += sizeof( * V_81 ) ;
V_57 = V_92 ;
V_92 += strlen ( V_57 ) + 1 ;
V_93 = V_92 ;
V_92 += strlen ( V_93 ) + 1 ;
V_17 = V_81 -> V_70 - ( int ) ( V_92 - ( char * ) V_81 ) ;
F_46 ( V_81 , V_84 , V_92 , V_17 , V_57 , V_93 ) ;
V_92 += V_17 ;
}
F_62 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
}
int F_65 ( char * V_94 )
{
struct V_34 V_35 ;
struct V_57 * V_95 ;
struct V_1 * V_7 ;
struct V_1 * V_36 ;
char * V_96 ;
T_3 V_97 ;
int V_42 ;
F_66 () ;
V_95 = F_67 ( V_94 , V_98 | V_99 | V_100 | V_101 ,
0600 ) ;
if ( F_68 ( V_95 ) ) {
V_42 = F_69 ( V_95 ) ;
V_95 = NULL ;
F_30 ( L_10 ,
V_94 , V_42 ) ;
goto V_102;
}
V_35 . V_86 = 1 ;
F_58 ( & V_35 ) ;
if ( F_19 ( & V_35 . V_37 ) ) {
V_42 = 0 ;
goto V_103;
}
V_97 = F_70 () ;
F_71 ( F_72 () ) ;
F_27 (tage, tmp, &pc.pc_pages, linkage) {
F_60 ( V_7 ) ;
V_96 = F_73 ( V_7 -> V_6 ) ;
V_42 = F_74 ( V_95 , V_96 , V_7 -> V_21 , & V_95 -> V_104 ) ;
F_75 ( V_7 -> V_6 ) ;
if ( V_42 != ( int ) V_7 -> V_21 ) {
F_76 ( L_11 , V_7 -> V_21 ,
V_42 ) ;
F_61 ( & V_35 ) ;
F_18 ( F_19 ( & V_35 . V_37 ) ) ;
break;
}
F_62 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
F_71 ( V_97 ) ;
V_42 = F_77 ( V_95 , 1 ) ;
if ( V_42 )
F_30 ( L_12 , V_42 ) ;
V_103:
F_78 ( V_95 , NULL ) ;
V_102:
F_79 () ;
return V_42 ;
}
void F_80 ( void )
{
struct V_34 V_35 ;
struct V_1 * V_7 ;
struct V_1 * V_36 ;
V_35 . V_86 = 1 ;
F_58 ( & V_35 ) ;
F_27 (tage, tmp, &pc.pc_pages, linkage) {
F_60 ( V_7 ) ;
F_62 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
}
int F_81 ( char * V_105 , int V_106 ,
const char T_4 * V_107 , int V_108 )
{
int V_109 ;
if ( V_108 > V_106 )
return - V_110 ;
if ( F_82 ( ( void * ) V_105 ,
V_107 , V_108 ) )
return - V_111 ;
V_109 = F_83 ( V_105 , V_108 ) ;
while ( V_109 -- >= 0 )
if ( ! isspace ( V_105 [ V_109 ] ) )
break;
if ( V_109 < 0 )
return - V_112 ;
if ( V_109 == V_106 )
return - V_110 ;
V_105 [ V_109 + 1 ] = 0 ;
return 0 ;
}
int F_84 ( char T_4 * V_107 , int V_108 ,
const char * V_105 , char * V_113 )
{
int V_109 = strlen ( V_105 ) ;
if ( V_109 > V_108 )
V_109 = V_108 ;
if ( F_85 ( V_107 , V_105 , V_109 ) )
return - V_111 ;
if ( V_113 && V_109 < V_108 ) {
if ( F_85 ( V_107 + V_109 , V_113 , 1 ) )
return - V_111 ;
V_109 ++ ;
}
return V_109 ;
}
int F_86 ( char * * V_80 , int V_109 )
{
if ( V_109 > 2 * V_22 )
return - V_112 ;
* V_80 = F_7 ( V_109 , V_114 | V_115 ) ;
if ( ! * V_80 )
return - V_116 ;
return 0 ;
}
int F_87 ( void T_4 * V_117 , int V_118 )
{
char * V_80 ;
int V_42 ;
V_42 = F_86 ( & V_80 , V_118 + 1 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_81 ( V_80 , V_118 + 1 ,
V_117 , V_118 ) ;
if ( V_42 )
goto V_102;
if ( V_80 [ 0 ] != '/' ) {
V_42 = - V_112 ;
goto V_102;
}
V_42 = F_65 ( V_80 ) ;
V_102:
F_11 ( V_80 ) ;
return V_42 ;
}
int F_88 ( char * V_80 )
{
int V_42 = 0 ;
F_66 () ;
if ( ! strcmp ( V_80 , L_13 ) ) {
F_79 () ;
F_89 () ;
F_66 () ;
memset ( V_119 , 0 , sizeof( V_119 ) ) ;
} else if ( ! strncmp ( V_80 , L_14 , 5 ) ) {
unsigned long V_36 ;
V_42 = F_90 ( V_80 + 5 , 10 , & V_36 ) ;
if ( ! V_42 ) {
if ( V_36 < 10 || V_36 > 20480 )
V_120 = V_121 ;
else
V_120 = V_36 << 20 ;
}
} else if ( strlen ( V_80 ) >= sizeof( V_119 ) ) {
V_42 = - V_122 ;
} else if ( V_80 [ 0 ] != '/' ) {
V_42 = - V_112 ;
} else {
strcpy ( V_119 , V_80 ) ;
F_42 ( L_15 ,
V_119 ,
( long ) ( V_120 >> 10 ) ) ;
F_91 () ;
}
F_79 () ;
return V_42 ;
}
int F_92 ( void T_4 * V_117 , int V_118 )
{
char * V_80 ;
int V_42 ;
V_42 = F_86 ( & V_80 , V_118 + 1 ) ;
if ( V_42 )
return V_42 ;
V_42 = F_81 ( V_80 , V_118 + 1 ,
V_117 , V_118 ) ;
if ( ! V_42 )
V_42 = F_88 ( V_80 ) ;
F_11 ( V_80 ) ;
return V_42 ;
}
int F_93 ( int F_50 )
{
int V_14 ;
int V_85 ;
int V_123 ;
int V_124 = F_94 () ;
struct V_11 * V_12 ;
if ( F_50 < F_95 () ) {
F_76 ( L_16 ,
F_50 , F_95 () ) ;
F_50 = F_95 () ;
}
if ( F_50 > V_124 ) {
F_76 ( L_17 ,
F_50 , V_124 ) ;
F_50 = V_124 ;
}
F_50 /= F_95 () ;
V_123 = F_50 << ( 20 - V_125 ) ;
F_66 () ;
F_53 (tcd, i, j)
V_12 -> V_23 = ( V_123 * V_12 -> V_126 ) / 100 ;
F_79 () ;
return 0 ;
}
int F_96 ( void )
{
int V_14 ;
int V_85 ;
struct V_11 * V_12 ;
int V_127 = 0 ;
F_97 () ;
F_53 (tcd, i, j)
V_127 += V_12 -> V_23 ;
F_98 () ;
return ( V_127 >> ( 20 - V_125 ) ) + 1 ;
}
static int F_99 ( void * V_128 )
{
struct V_34 V_35 ;
struct V_29 * V_30 = V_128 ;
struct V_1 * V_7 ;
struct V_1 * V_36 ;
struct V_57 * V_95 ;
char * V_96 ;
int V_129 = 0 ;
int V_42 ;
F_100 ( & V_30 -> V_130 ) ;
while ( 1 ) {
T_5 V_131 ;
V_35 . V_86 = 0 ;
F_58 ( & V_35 ) ;
if ( F_19 ( & V_35 . V_37 ) )
goto V_132;
V_95 = NULL ;
F_97 () ;
if ( V_119 [ 0 ] ) {
V_95 = F_67 ( V_119 ,
V_98 | V_133 | V_101 ,
0600 ) ;
if ( F_68 ( V_95 ) ) {
V_42 = F_69 ( V_95 ) ;
V_95 = NULL ;
F_76 ( L_18 , V_119 ,
V_42 ) ;
}
}
F_98 () ;
if ( ! V_95 ) {
F_63 ( & V_35 ) ;
F_18 ( F_19 ( & V_35 . V_37 ) ) ;
goto V_132;
}
F_27 (tage, tmp, &pc.pc_pages, linkage) {
static T_6 V_104 ;
F_60 ( V_7 ) ;
if ( V_104 >= ( V_134 ) V_120 )
V_104 = 0 ;
else if ( V_104 > F_101 ( F_102 ( V_95 ) ) )
V_104 = F_101 ( F_102 ( V_95 ) ) ;
V_96 = F_73 ( V_7 -> V_6 ) ;
V_42 = F_74 ( V_95 , V_96 , V_7 -> V_21 , & V_104 ) ;
F_75 ( V_7 -> V_6 ) ;
if ( V_42 != ( int ) V_7 -> V_21 ) {
F_76 ( L_11 ,
V_7 -> V_21 , V_42 ) ;
F_61 ( & V_35 ) ;
F_18 ( F_19 ( & V_35 . V_37 ) ) ;
break;
}
}
F_78 ( V_95 , NULL ) ;
F_63 ( & V_35 ) ;
if ( ! F_19 ( & V_35 . V_37 ) ) {
int V_14 ;
F_103 ( L_19 ) ;
F_30 ( L_20 , F_95 () ) ;
for ( V_14 = 0 ; V_14 < F_95 () ; V_14 ++ )
if ( F_104 ( V_14 ) )
F_105 ( L_21 , V_14 ) ;
else
F_105 ( L_22 , V_14 ) ;
F_105 ( L_23 ) ;
V_14 = 0 ;
F_27 (tage, tmp, &pc.pc_pages,
linkage)
F_30 ( L_24 ,
++ V_14 , V_7 -> V_26 ) ;
F_30 ( L_25 , V_14 ) ;
}
F_18 ( F_19 ( & V_35 . V_37 ) ) ;
V_132:
if ( F_106 ( & V_30 -> V_135 ) ) {
if ( ! V_129 ) {
V_129 = 1 ;
continue;
} else {
break;
}
}
F_107 ( & V_131 , V_136 ) ;
F_108 ( & V_30 -> V_32 , & V_131 ) ;
F_109 ( V_137 ) ;
F_110 ( F_45 ( 1 ) ) ;
F_111 ( & V_30 -> V_32 , & V_131 ) ;
}
F_100 ( & V_30 -> V_138 ) ;
return 0 ;
}
int F_91 ( void )
{
struct V_29 * V_30 = & V_31 ;
struct V_139 * V_140 ;
int V_42 = 0 ;
F_112 ( & V_141 ) ;
if ( V_28 )
goto V_102;
F_113 ( & V_30 -> V_130 ) ;
F_113 ( & V_30 -> V_138 ) ;
F_114 ( & V_30 -> V_32 ) ;
F_115 ( & V_30 -> V_135 , 0 ) ;
V_140 = F_116 ( F_99 , V_30 , L_26 ) ;
if ( F_68 ( V_140 ) ) {
V_42 = F_69 ( V_140 ) ;
goto V_102;
}
F_117 ( & V_30 -> V_130 ) ;
V_28 = 1 ;
V_102:
F_118 ( & V_141 ) ;
return V_42 ;
}
void F_89 ( void )
{
struct V_29 * V_30 = & V_31 ;
F_112 ( & V_141 ) ;
if ( V_28 ) {
F_42 ( L_27 ) ;
F_115 ( & V_30 -> V_135 , 1 ) ;
F_117 ( & V_30 -> V_138 ) ;
V_28 = 0 ;
}
F_118 ( & V_141 ) ;
}
int F_119 ( int V_142 )
{
struct V_11 * V_12 ;
int V_14 ;
int V_85 ;
int V_42 ;
int V_143 ;
V_42 = F_120 () ;
if ( V_42 )
return V_42 ;
F_53 (tcd, i, j) {
V_143 = V_12 -> V_126 ;
F_26 ( & V_12 -> V_19 ) ;
F_26 ( & V_12 -> V_24 ) ;
F_26 ( & V_12 -> V_87 ) ;
V_12 -> V_18 = 0 ;
V_12 -> V_15 = 0 ;
V_12 -> V_88 = 0 ;
V_12 -> V_23 = ( V_142 * V_143 ) / 100 ;
F_121 ( V_12 -> V_23 > 0 ) ;
V_12 -> V_65 = 0 ;
}
return 0 ;
}
static void F_122 ( void )
{
struct V_11 * V_12 ;
struct V_1 * V_7 ;
struct V_1 * V_36 ;
int V_14 , V_26 ;
F_56 (cpu) {
F_57 (tcd, i, cpu) {
V_12 -> V_65 = 1 ;
F_27 (tage, tmp, &tcd->tcd_pages,
linkage) {
F_60 ( V_7 ) ;
F_62 ( & V_7 -> V_4 ) ;
F_10 ( V_7 ) ;
}
V_12 -> V_18 = 0 ;
}
}
}
static void F_123 ( void )
{
struct V_34 V_35 ;
F_26 ( & V_35 . V_37 ) ;
F_122 () ;
F_124 () ;
}
void F_125 ( void )
{
F_89 () ;
F_123 () ;
}
