void F_1 ( int V_1 )
{
int V_2 ;
int V_3 ;
const void * V_4 ;
int V_5 = V_6 ;
int V_7 = V_8 ;
const T_1 * V_9 ;
const T_1 * V_10 ;
int V_11 ;
int V_12 ;
V_11 = F_2 ( V_13 , L_1 ) ;
if ( V_11 < 0 )
return;
V_9 = F_3 ( V_13 , V_11 ,
L_2 , NULL ) ;
if ( V_9 )
V_5 = F_4 ( * V_9 ) ;
V_10 = F_3 ( V_13 , V_11 ,
L_3 , NULL ) ;
if ( V_10 )
V_7 = F_4 ( * V_10 ) ;
V_12 = sizeof( V_14 ) * ( V_5 + V_7 ) ;
V_2 = F_2 ( V_13 , L_4 ) ;
if ( V_2 > 0 ) {
V_4 = F_3 ( V_13 , V_2 , L_5 , & V_3 ) ;
if ( V_3 > V_1 * V_12 ) {
V_3 = V_1 * V_12 ;
F_5 ( L_6 , V_1 ) ;
F_6 ( V_13 , V_2 , L_5 , V_4 ,
V_3 ) ;
}
}
}
static int F_7 ( const void * V_15 ,
unsigned long V_16 , const char * V_17 )
{
const char * V_18 ;
int V_19 ;
unsigned long V_20 , V_21 = 0 ;
V_18 = F_3 ( V_15 , V_16 , L_7 , & V_19 ) ;
if ( V_18 == NULL )
return 0 ;
while ( V_19 > 0 ) {
V_21 ++ ;
if ( F_8 ( V_18 , V_17 , strlen ( V_17 ) ) == 0 )
return V_21 ;
V_20 = strlen ( V_18 ) + 1 ;
V_18 += V_20 ;
V_19 -= V_20 ;
}
return 0 ;
}
bool F_9 ( const void * V_15 , unsigned long V_16 )
{
if ( F_3 ( V_15 , V_16 , L_8 , NULL ) )
return true ;
if ( F_10 ( V_22 ) &&
F_3 ( V_15 , V_16 , L_9 , NULL ) )
return true ;
return false ;
}
int F_11 ( const void * V_15 , unsigned long V_16 ,
const char * const * V_17 )
{
unsigned int V_23 , V_21 = 0 ;
if ( ! V_17 )
return 0 ;
while ( * V_17 ) {
V_23 = F_7 ( V_15 , V_16 , * V_17 ) ;
if ( V_23 && ( V_21 == 0 || ( V_23 < V_21 ) ) )
V_21 = V_23 ;
V_17 ++ ;
}
return V_21 ;
}
static void * F_12 ( void * * V_24 , unsigned long V_25 ,
unsigned long V_26 )
{
void * V_27 ;
* V_24 = F_13 ( * V_24 , V_26 ) ;
V_27 = * V_24 ;
* V_24 += V_25 ;
return V_27 ;
}
static void F_14 ( const void * V_15 ,
int V_28 ,
void * * V_24 ,
struct V_29 * V_30 ,
const char * V_31 ,
bool V_32 )
{
struct V_33 * V_34 , * * V_35 = NULL ;
int V_36 ;
bool V_37 = false ;
V_35 = & V_30 -> V_38 ;
for ( V_36 = F_15 ( V_15 , V_28 ) ;
V_36 >= 0 ;
V_36 = F_16 ( V_15 , V_36 ) ) {
const T_1 * V_4 ;
const char * V_39 ;
T_2 V_40 ;
V_4 = F_17 ( V_15 , V_36 , & V_39 , & V_40 ) ;
if ( ! V_4 ) {
F_18 ( L_10 , V_36 ) ;
continue;
}
if ( ! V_39 ) {
F_18 ( L_11 , V_36 ) ;
continue;
}
if ( ! strcmp ( V_39 , L_12 ) )
V_37 = true ;
V_34 = F_12 ( V_24 , sizeof( struct V_33 ) ,
F_19 ( struct V_33 ) ) ;
if ( V_32 )
continue;
if ( ! strcmp ( V_39 , L_13 ) ||
! strcmp ( V_39 , L_14 ) ) {
if ( ! V_30 -> V_41 )
V_30 -> V_41 = F_20 ( V_4 ) ;
}
if ( ! strcmp ( V_39 , L_15 ) )
V_30 -> V_41 = F_20 ( V_4 ) ;
V_34 -> V_42 = ( char * ) V_39 ;
V_34 -> V_43 = V_40 ;
V_34 -> V_44 = ( T_1 * ) V_4 ;
* V_35 = V_34 ;
V_35 = & V_34 -> V_45 ;
}
if ( ! V_37 ) {
const char * V_46 = V_31 , * V_47 = V_46 , * V_48 = NULL ;
int V_3 ;
while ( * V_46 ) {
if ( ( * V_46 ) == '@' )
V_48 = V_46 ;
else if ( ( * V_46 ) == '/' )
V_47 = V_46 + 1 ;
V_46 ++ ;
}
if ( V_48 < V_47 )
V_48 = V_46 ;
V_3 = ( V_48 - V_47 ) + 1 ;
V_34 = F_12 ( V_24 , sizeof( struct V_33 ) + V_3 ,
F_19 ( struct V_33 ) ) ;
if ( ! V_32 ) {
V_34 -> V_42 = L_12 ;
V_34 -> V_43 = V_3 ;
V_34 -> V_44 = V_34 + 1 ;
* V_35 = V_34 ;
V_35 = & V_34 -> V_45 ;
memcpy ( V_34 -> V_44 , V_47 , V_3 - 1 ) ;
( ( char * ) V_34 -> V_44 ) [ V_3 - 1 ] = 0 ;
F_5 ( L_16 ,
V_31 , ( char * ) V_34 -> V_44 ) ;
}
}
if ( ! V_32 )
* V_35 = NULL ;
}
static unsigned int F_21 ( const void * V_15 ,
int V_28 ,
void * * V_24 ,
struct V_29 * V_49 ,
unsigned int V_50 ,
struct V_29 * * V_51 ,
bool V_32 )
{
struct V_29 * V_30 ;
const char * V_52 ;
unsigned int V_20 , V_53 ;
int V_54 = 0 ;
V_52 = F_22 ( V_15 , V_28 , & V_20 ) ;
if ( ! V_52 ) {
* V_51 = NULL ;
return 0 ;
}
V_53 = ++ V_20 ;
if ( ( * V_52 ) != '/' ) {
V_54 = 1 ;
if ( V_50 == 0 ) {
V_50 = 1 ;
V_53 = 2 ;
V_20 = 1 ;
V_52 = L_17 ;
} else {
V_50 += V_20 ;
V_53 = V_50 ;
}
}
V_30 = F_12 ( V_24 , sizeof( struct V_29 ) + V_53 ,
F_19 ( struct V_29 ) ) ;
if ( ! V_32 ) {
char * V_55 ;
F_23 ( V_30 ) ;
V_30 -> V_56 = V_55 = ( ( char * ) V_30 ) + sizeof( * V_30 ) ;
if ( V_54 ) {
if ( V_49 && V_49 -> V_57 ) {
strcpy ( V_55 , V_49 -> V_56 ) ;
#ifdef F_24
if ( ( strlen ( V_55 ) + V_20 + 1 ) != V_53 ) {
F_5 ( L_18 ,
V_52 , ( int ) strlen ( V_55 ) ,
V_20 , V_53 ) ;
}
#endif
V_55 += strlen ( V_55 ) ;
}
* ( V_55 ++ ) = '/' ;
}
memcpy ( V_55 , V_52 , V_20 ) ;
if ( V_49 != NULL ) {
V_30 -> V_57 = V_49 ;
V_30 -> V_58 = V_49 -> V_59 ;
V_49 -> V_59 = V_30 ;
}
}
F_14 ( V_15 , V_28 , V_24 , V_30 , V_52 , V_32 ) ;
if ( ! V_32 ) {
V_30 -> V_42 = F_25 ( V_30 , L_12 , NULL ) ;
V_30 -> type = F_25 ( V_30 , L_19 , NULL ) ;
if ( ! V_30 -> V_42 )
V_30 -> V_42 = L_20 ;
if ( ! V_30 -> type )
V_30 -> type = L_20 ;
}
* V_51 = V_30 ;
return V_50 ;
}
static void F_26 ( struct V_29 * V_57 )
{
struct V_29 * V_59 , * V_45 ;
V_59 = V_57 -> V_59 ;
while ( V_59 ) {
F_26 ( V_59 ) ;
V_59 = V_59 -> V_58 ;
}
V_59 = V_57 -> V_59 ;
V_57 -> V_59 = NULL ;
while ( V_59 ) {
V_45 = V_59 -> V_58 ;
V_59 -> V_58 = V_57 -> V_59 ;
V_57 -> V_59 = V_59 ;
V_59 = V_45 ;
}
}
static int F_27 ( const void * V_15 ,
void * V_24 ,
struct V_29 * V_49 ,
struct V_29 * * V_60 )
{
struct V_29 * V_61 ;
int V_28 = 0 , V_62 = 0 , V_63 = 0 ;
#define F_28 64
unsigned int V_64 [ F_28 ] ;
struct V_29 * V_65 [ F_28 ] ;
void * V_66 = V_24 ;
bool V_32 = ! V_66 ;
if ( V_60 )
* V_60 = NULL ;
if ( V_49 )
V_62 = V_63 = 1 ;
V_61 = V_49 ;
V_64 [ V_62 ] = V_49 ? strlen ( F_29 ( V_49 ) ) : 0 ;
V_65 [ V_62 ] = V_49 ;
for ( V_28 = 0 ;
V_28 >= 0 && V_62 >= V_63 ;
V_28 = F_30 ( V_15 , V_28 , & V_62 ) ) {
if ( F_31 ( V_62 >= F_28 ) )
continue;
V_64 [ V_62 + 1 ] = F_21 ( V_15 , V_28 , & V_24 ,
V_65 [ V_62 ] ,
V_64 [ V_62 ] ,
& V_65 [ V_62 + 1 ] , V_32 ) ;
if ( ! V_64 [ V_62 + 1 ] )
return V_24 - V_66 ;
if ( ! V_32 && V_60 && ! * V_60 )
* V_60 = V_65 [ V_62 + 1 ] ;
if ( ! V_32 && ! V_61 )
V_61 = V_65 [ V_62 + 1 ] ;
}
if ( V_28 < 0 && V_28 != - V_67 ) {
F_32 ( L_21 , V_28 ) ;
return - V_68 ;
}
if ( ! V_32 )
F_26 ( V_61 ) ;
return V_24 - V_66 ;
}
void * F_33 ( const void * V_15 ,
struct V_29 * V_49 ,
struct V_29 * * V_69 ,
void * (* F_34)( T_3 V_25 , T_3 V_26 ) ,
bool V_70 )
{
int V_25 ;
void * V_24 ;
F_5 ( L_22 ) ;
if ( ! V_15 ) {
F_5 ( L_23 ) ;
return NULL ;
}
F_5 ( L_24 ) ;
F_5 ( L_25 , F_35 ( V_15 ) ) ;
F_5 ( L_26 , F_36 ( V_15 ) ) ;
F_5 ( L_27 , F_37 ( V_15 ) ) ;
if ( F_38 ( V_15 ) ) {
F_32 ( L_28 ) ;
return NULL ;
}
V_25 = F_27 ( V_15 , NULL , V_49 , NULL ) ;
if ( V_25 < 0 )
return NULL ;
V_25 = F_39 ( V_25 , 4 ) ;
F_5 ( L_29 , V_25 ) ;
V_24 = F_34 ( V_25 + 4 , F_19 ( struct V_29 ) ) ;
if ( ! V_24 )
return NULL ;
memset ( V_24 , 0 , V_25 ) ;
* ( T_1 * ) ( V_24 + V_25 ) = F_40 ( 0xdeadbeef ) ;
F_5 ( L_30 , V_24 ) ;
F_27 ( V_15 , V_24 , V_49 , V_69 ) ;
if ( F_20 ( V_24 + V_25 ) != 0xdeadbeef )
F_41 ( L_31 ,
F_20 ( V_24 + V_25 ) ) ;
if ( V_70 && V_69 ) {
F_42 ( * V_69 , V_71 ) ;
F_5 ( L_32 ) ;
}
F_5 ( L_33 ) ;
return V_24 ;
}
static void * F_43 ( T_3 V_25 , T_3 V_26 )
{
return F_44 ( V_25 , V_72 ) ;
}
void * F_45 ( const unsigned long * V_15 ,
struct V_29 * V_49 ,
struct V_29 * * V_69 )
{
void * V_24 ;
F_46 ( & V_73 ) ;
V_24 = F_33 ( V_15 , V_49 , V_69 , & F_43 ,
true ) ;
F_47 ( & V_73 ) ;
return V_24 ;
}
static int T_4 F_48 ( unsigned long V_16 ,
const char * V_74 )
{
int V_75 = ( V_76 + V_77 ) * sizeof( T_1 ) ;
T_5 V_66 , V_25 ;
int V_3 ;
const T_1 * V_78 ;
int V_79 , V_80 = 1 ;
V_78 = F_49 ( V_16 , L_5 , & V_3 ) ;
if ( ! V_78 )
return - V_81 ;
if ( V_3 && V_3 % V_75 != 0 ) {
F_32 ( L_34 ,
V_74 ) ;
return - V_68 ;
}
V_79 = F_49 ( V_16 , L_35 , NULL ) != NULL ;
while ( V_3 >= V_75 ) {
V_66 = F_50 ( V_76 , & V_78 ) ;
V_25 = F_50 ( V_77 , & V_78 ) ;
if ( V_25 &&
F_51 ( V_66 , V_25 , V_79 ) == 0 )
F_5 ( L_36 ,
V_74 , & V_66 , ( unsigned long ) V_25 / V_82 ) ;
else
F_52 ( L_37 ,
V_74 , & V_66 , ( unsigned long ) V_25 / V_82 ) ;
V_3 -= V_75 ;
if ( V_80 ) {
F_53 ( V_16 , V_74 , V_66 , V_25 ) ;
V_80 = 0 ;
}
}
return 0 ;
}
static int T_4 F_54 ( unsigned long V_16 )
{
const T_1 * V_78 ;
V_78 = F_49 ( V_16 , L_3 , NULL ) ;
if ( ! V_78 || F_20 ( V_78 ) != V_77 )
return - V_68 ;
V_78 = F_49 ( V_16 , L_2 , NULL ) ;
if ( ! V_78 || F_20 ( V_78 ) != V_76 )
return - V_68 ;
V_78 = F_49 ( V_16 , L_38 , NULL ) ;
if ( ! V_78 )
return - V_68 ;
return 0 ;
}
static int T_4 F_55 ( unsigned long V_16 , const char * V_74 ,
int V_62 , void * V_83 )
{
static int V_84 ;
const char * V_85 ;
int V_86 ;
if ( ! V_84 && V_62 == 1 && strcmp ( V_74 , L_39 ) == 0 ) {
if ( F_54 ( V_16 ) != 0 ) {
F_32 ( L_40 ) ;
return 1 ;
}
V_84 = 1 ;
return 0 ;
} else if ( ! V_84 ) {
return 0 ;
} else if ( V_84 && V_62 < 2 ) {
return 1 ;
}
V_85 = F_49 ( V_16 , L_41 , NULL ) ;
if ( V_85 && strcmp ( V_85 , L_42 ) != 0 && strcmp ( V_85 , L_43 ) != 0 )
return 0 ;
V_86 = F_48 ( V_16 , V_74 ) ;
if ( V_86 == - V_81 && F_49 ( V_16 , L_44 , NULL ) )
F_53 ( V_16 , V_74 , 0 , 0 ) ;
return 0 ;
}
void T_4 F_56 ( void )
{
int V_87 ;
T_3 V_66 , V_25 ;
if ( ! V_13 )
return;
for ( V_87 = 0 ; ; V_87 ++ ) {
F_57 ( V_13 , V_87 , & V_66 , & V_25 ) ;
if ( ! V_25 )
break;
F_51 ( V_66 , V_25 , 0 ) ;
}
F_58 ( F_55 , NULL ) ;
F_59 () ;
}
void T_4 F_60 ( void )
{
if ( ! V_13 )
return;
F_51 ( F_61 ( V_13 ) ,
F_36 ( V_13 ) ,
0 ) ;
}
int T_4 F_58 ( int (* F_62)( unsigned long V_16 ,
const char * V_74 , int V_62 ,
void * V_83 ) ,
void * V_83 )
{
const void * V_15 = V_13 ;
const char * V_52 ;
int V_28 , V_88 = 0 , V_62 = - 1 ;
if ( ! V_15 )
return 0 ;
for ( V_28 = F_30 ( V_15 , - 1 , & V_62 ) ;
V_28 >= 0 && V_62 >= 0 && ! V_88 ;
V_28 = F_30 ( V_15 , V_28 , & V_62 ) ) {
V_52 = F_22 ( V_15 , V_28 , NULL ) ;
if ( * V_52 == '/' )
V_52 = F_63 ( V_52 ) ;
V_88 = F_62 ( V_28 , V_52 , V_62 , V_83 ) ;
}
return V_88 ;
}
int T_4 F_64 ( unsigned long V_57 ,
int (* F_62)( unsigned long V_16 ,
const char * V_74 ,
void * V_83 ) ,
void * V_83 )
{
const void * V_15 = V_13 ;
int V_16 ;
F_65 (node, blob, parent) {
const char * V_52 ;
int V_88 ;
V_52 = F_22 ( V_15 , V_16 , NULL ) ;
if ( * V_52 == '/' )
V_52 = F_63 ( V_52 ) ;
V_88 = F_62 ( V_16 , V_52 , V_83 ) ;
if ( V_88 )
return V_88 ;
}
return 0 ;
}
int F_66 ( unsigned long V_16 , const char * V_74 )
{
return F_67 ( V_13 , V_16 , V_74 ) ;
}
unsigned long T_4 F_68 ( void )
{
return 0 ;
}
int T_4 F_69 ( void )
{
return F_36 ( V_13 ) ;
}
const void * T_4 F_49 ( unsigned long V_16 , const char * V_42 ,
int * V_25 )
{
return F_3 ( V_13 , V_16 , V_42 , V_25 ) ;
}
int T_4 F_70 ( unsigned long V_16 , const char * V_17 )
{
return F_7 ( V_13 , V_16 , V_17 ) ;
}
int T_4 F_71 ( unsigned long V_16 , const char * const * V_17 )
{
return F_11 ( V_13 , V_16 , V_17 ) ;
}
V_14 T_4 F_72 ( unsigned long V_16 )
{
return F_73 ( V_13 , V_16 ) ;
}
const char * T_4 F_74 ( void )
{
const char * V_42 ;
unsigned long V_89 = F_68 () ;
V_42 = F_49 ( V_89 , L_45 , NULL ) ;
if ( ! V_42 )
V_42 = F_49 ( V_89 , L_7 , NULL ) ;
return V_42 ;
}
const void * T_4 F_75 ( const void * V_90 ,
const void * (* F_76)( const char * const * * ) )
{
const void * V_83 = NULL ;
const void * V_91 = V_90 ;
const char * const * V_17 ;
unsigned long V_89 ;
unsigned int V_92 = ~ 1 , V_21 = 0 ;
V_89 = F_68 () ;
while ( ( V_83 = F_76 ( & V_17 ) ) ) {
V_21 = F_71 ( V_89 , V_17 ) ;
if ( V_21 > 0 && V_21 < V_92 ) {
V_91 = V_83 ;
V_92 = V_21 ;
}
}
if ( ! V_91 ) {
const char * V_78 ;
int V_25 ;
F_32 ( L_46 ) ;
V_78 = F_49 ( V_89 , L_7 , & V_25 ) ;
if ( V_78 ) {
while ( V_25 > 0 ) {
F_77 ( L_47 , V_78 ) ;
V_25 -= strlen ( V_78 ) + 1 ;
V_78 += strlen ( V_78 ) + 1 ;
}
}
F_77 ( L_48 ) ;
return NULL ;
}
F_52 ( L_49 , F_74 () ) ;
return V_91 ;
}
static void F_78 ( unsigned long V_93 ,
unsigned long V_94 )
{
V_95 = ( unsigned long ) F_79 ( V_93 ) ;
V_96 = ( unsigned long ) F_79 ( V_94 ) ;
V_97 = 1 ;
}
static void T_4 F_80 ( unsigned long V_16 )
{
T_3 V_93 , V_94 ;
int V_3 ;
const T_1 * V_78 ;
F_5 ( L_50 ) ;
V_78 = F_49 ( V_16 , L_51 , & V_3 ) ;
if ( ! V_78 )
return;
V_93 = F_81 ( V_78 , V_3 / 4 ) ;
V_78 = F_49 ( V_16 , L_52 , & V_3 ) ;
if ( ! V_78 )
return;
V_94 = F_81 ( V_78 , V_3 / 4 ) ;
F_78 ( V_93 , V_94 ) ;
F_5 ( L_53 ,
( unsigned long long ) V_93 , ( unsigned long long ) V_94 ) ;
}
static inline void F_80 ( unsigned long V_16 )
{
}
int T_4 F_82 ( void )
{
int V_28 ;
const char * V_46 , * V_98 , * V_99 = NULL ;
int V_20 ;
const struct V_100 * V_101 ;
const void * V_102 = V_13 ;
V_28 = F_2 ( V_102 , L_54 ) ;
if ( V_28 < 0 )
V_28 = F_2 ( V_102 , L_55 ) ;
if ( V_28 < 0 )
return - V_81 ;
V_46 = F_3 ( V_102 , V_28 , L_56 , & V_20 ) ;
if ( ! V_46 )
V_46 = F_3 ( V_102 , V_28 , L_57 , & V_20 ) ;
if ( ! V_46 || ! V_20 )
return - V_81 ;
V_98 = F_83 ( V_46 , ':' ) ;
if ( * V_98 != '\0' )
V_99 = V_98 + 1 ;
V_20 = V_98 - V_46 ;
V_28 = F_84 ( V_102 , V_46 , V_20 ) ;
if ( V_28 < 0 ) {
F_18 ( L_58 , V_20 , V_46 ) ;
return 0 ;
}
for ( V_101 = V_103 ; V_101 < V_104 ; V_101 ++ ) {
if ( ! V_101 -> V_105 [ 0 ] )
continue;
if ( F_85 ( V_102 , V_28 , V_101 -> V_105 ) )
continue;
F_86 ( V_101 , V_28 , V_99 ) ;
return 0 ;
}
return - V_106 ;
}
int T_4 F_87 ( unsigned long V_16 , const char * V_74 ,
int V_62 , void * V_83 )
{
const T_1 * V_78 ;
if ( V_62 != 0 )
return 0 ;
V_77 = V_8 ;
V_76 = V_6 ;
V_78 = F_49 ( V_16 , L_3 , NULL ) ;
if ( V_78 )
V_77 = F_20 ( V_78 ) ;
F_5 ( L_59 , V_77 ) ;
V_78 = F_49 ( V_16 , L_2 , NULL ) ;
if ( V_78 )
V_76 = F_20 ( V_78 ) ;
F_5 ( L_60 , V_76 ) ;
return 1 ;
}
T_3 T_4 F_50 ( int V_107 , const T_1 * * V_108 )
{
const T_1 * V_46 = * V_108 ;
* V_108 = V_46 + V_107 ;
return F_81 ( V_46 , V_107 ) ;
}
int T_4 F_88 ( unsigned long V_16 , const char * V_74 ,
int V_62 , void * V_83 )
{
const char * type = F_49 ( V_16 , L_19 , NULL ) ;
const T_1 * V_109 , * V_110 ;
int V_20 ;
bool V_111 ;
if ( type == NULL ) {
if ( ! F_10 ( V_112 ) || V_62 != 1 || strcmp ( V_74 , L_61 ) != 0 )
return 0 ;
} else if ( strcmp ( type , L_62 ) != 0 )
return 0 ;
V_109 = F_49 ( V_16 , L_63 , & V_20 ) ;
if ( V_109 == NULL )
V_109 = F_49 ( V_16 , L_5 , & V_20 ) ;
if ( V_109 == NULL )
return 0 ;
V_110 = V_109 + ( V_20 / sizeof( T_1 ) ) ;
V_111 = F_49 ( V_16 , L_64 , NULL ) ;
F_5 ( L_65 , V_74 , V_20 ) ;
while ( ( V_110 - V_109 ) >= ( V_76 + V_77 ) ) {
T_3 V_66 , V_25 ;
V_66 = F_50 ( V_76 , & V_109 ) ;
V_25 = F_50 ( V_77 , & V_109 ) ;
if ( V_25 == 0 )
continue;
F_5 ( L_66 , ( unsigned long long ) V_66 ,
( unsigned long long ) V_25 ) ;
F_89 ( V_66 , V_25 ) ;
if ( ! V_111 )
continue;
if ( F_90 ( V_66 , V_25 ) )
F_18 ( L_67 ,
V_66 , V_66 + V_25 ) ;
}
return 0 ;
}
int T_4 F_91 ( unsigned long V_16 , const char * V_74 ,
int V_62 , void * V_83 )
{
int V_20 ;
const char * V_46 ;
F_5 ( L_68 , V_62 , V_74 ) ;
if ( V_62 != 1 || ! V_83 ||
( strcmp ( V_74 , L_69 ) != 0 && strcmp ( V_74 , L_70 ) != 0 ) )
return 0 ;
F_80 ( V_16 ) ;
V_46 = F_49 ( V_16 , L_71 , & V_20 ) ;
if ( V_46 != NULL && V_20 > 0 )
F_92 ( V_83 , V_46 , F_93 ( ( int ) V_20 , V_113 ) ) ;
#ifdef F_94
#if F_95 ( V_114 )
F_96 ( V_83 , L_72 , V_113 ) ;
F_96 ( V_83 , F_94 , V_113 ) ;
#elif F_95 ( V_115 )
F_92 ( V_83 , F_94 , V_113 ) ;
#else
if ( ! ( ( char * ) V_83 ) [ 0 ] )
F_92 ( V_83 , F_94 , V_113 ) ;
#endif
#endif
F_5 ( L_73 , ( char * ) V_83 ) ;
return 1 ;
}
void T_4 __weak F_89 ( T_3 V_66 , T_3 V_25 )
{
const T_3 V_116 = V_117 ;
if ( ! F_97 ( V_66 ) ) {
if ( V_25 < V_118 - ( V_66 & ~ V_119 ) ) {
F_18 ( L_74 ,
V_66 , V_66 + V_25 ) ;
return;
}
V_25 -= V_118 - ( V_66 & ~ V_119 ) ;
V_66 = F_98 ( V_66 ) ;
}
V_25 &= V_119 ;
if ( V_66 > V_120 ) {
F_41 ( L_74 ,
V_66 , V_66 + V_25 ) ;
return;
}
if ( V_66 + V_25 - 1 > V_120 ) {
F_41 ( L_75 ,
( ( T_3 ) V_120 ) + 1 , V_66 + V_25 ) ;
V_25 = V_120 - V_66 + 1 ;
}
if ( V_66 + V_25 < V_116 ) {
F_41 ( L_74 ,
V_66 , V_66 + V_25 ) ;
return;
}
if ( V_66 < V_116 ) {
F_41 ( L_75 ,
V_66 , V_116 ) ;
V_25 -= V_116 - V_66 ;
V_66 = V_116 ;
}
F_99 ( V_66 , V_25 ) ;
}
int T_4 __weak F_90 ( T_3 V_66 , T_3 V_25 )
{
return F_100 ( V_66 , V_25 ) ;
}
int T_4 __weak F_51 ( T_5 V_66 ,
T_5 V_25 , bool V_79 )
{
if ( V_79 )
return F_101 ( V_66 , V_25 ) ;
return F_102 ( V_66 , V_25 ) ;
}
void * T_4 __weak F_103 ( T_3 V_25 , T_3 V_26 )
{
return F_79 ( F_104 ( V_25 , V_26 ) ) ;
}
void T_4 __weak F_89 ( T_3 V_66 , T_3 V_25 )
{
F_105 ( 1 ) ;
}
int T_4 __weak F_90 ( T_3 V_66 , T_3 V_25 )
{
return - V_121 ;
}
int T_4 __weak F_51 ( T_5 V_66 ,
T_5 V_25 , bool V_79 )
{
F_32 ( L_76 ,
& V_66 , & V_25 , V_79 ? L_77 : L_17 ) ;
return - V_121 ;
}
void * T_4 __weak F_103 ( T_3 V_25 , T_3 V_26 )
{
F_105 ( 1 ) ;
return NULL ;
}
bool T_4 F_106 ( void * V_122 )
{
if ( ! V_122 )
return false ;
if ( F_38 ( V_122 ) )
return false ;
V_13 = V_122 ;
V_123 = F_107 ( ~ 0 , V_13 ,
F_36 ( V_13 ) ) ;
return true ;
}
void T_4 F_108 ( void )
{
F_58 ( F_91 , V_124 ) ;
F_58 ( F_87 , NULL ) ;
F_58 ( F_88 , NULL ) ;
}
bool T_4 F_109 ( void * V_122 )
{
bool V_85 ;
V_85 = F_106 ( V_122 ) ;
if ( ! V_85 )
return false ;
F_108 () ;
return true ;
}
void T_4 F_110 ( void )
{
F_33 ( V_13 , NULL , & V_125 ,
F_103 , false ) ;
F_111 ( F_103 ) ;
F_112 () ;
}
void T_4 F_113 ( void )
{
int V_25 ;
void * V_126 ;
if ( ! V_13 ) {
F_18 ( L_78 ) ;
return;
}
V_25 = F_36 ( V_13 ) ;
V_126 = F_103 ( V_25 ,
F_114 ( V_127 ) ) ;
if ( V_126 ) {
memcpy ( V_126 , V_13 , V_25 ) ;
V_13 = V_126 ;
}
F_110 () ;
}
static T_6 F_115 ( struct V_128 * V_129 , struct V_130 * V_131 ,
struct V_132 * V_133 ,
char * V_134 , T_7 V_135 , T_8 V_136 )
{
memcpy ( V_134 , V_13 + V_135 , V_136 ) ;
return V_136 ;
}
static int T_4 F_116 ( void )
{
static struct V_132 V_137 =
F_117 ( V_102 , V_138 , F_115 , NULL , 0 ) ;
if ( ! V_13 )
return 0 ;
if ( V_123 != F_107 ( ~ 0 , V_13 ,
F_36 ( V_13 ) ) ) {
F_18 ( L_79 ) ;
return 0 ;
}
V_137 . V_25 = F_36 ( V_13 ) ;
return F_118 ( V_139 , & V_137 ) ;
}
