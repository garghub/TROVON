bool F_1 ( int V_1 , long * V_2 , long * V_3 ,
unsigned long * V_4 , int * V_5 , int * V_6 )
{
unsigned long V_7 ;
int V_8 ;
unsigned long V_9 ;
if ( ! F_2 ( V_1 ) || ! F_3 ( V_1 ) )
return false ;
if ( V_10 )
F_4 ( L_1 V_11
L_2 ,
V_12 , V_1 ) ;
V_9 = V_13 ;
( * V_2 ) ++ ;
V_8 = F_5 ( V_1 ) ;
if ( V_8 ) {
if ( V_10 )
F_4 ( L_1 V_11
L_3 ,
V_12 , V_1 , V_8 ) ;
} else {
if ( V_10 )
F_4 ( L_1 V_11
L_4 ,
V_12 , V_1 ) ;
( * V_3 ) ++ ;
V_7 = V_13 - V_9 ;
V_4 += V_7 ;
if ( * V_5 < 0 ) {
* V_5 = V_7 ;
* V_6 = V_7 ;
}
if ( * V_5 > V_7 )
* V_5 = V_7 ;
if ( * V_6 < V_7 )
* V_6 = V_7 ;
}
return true ;
}
bool F_6 ( int V_1 , long * V_14 , long * V_15 ,
unsigned long * V_16 , int * V_17 , int * V_18 )
{
unsigned long V_7 ;
int V_8 ;
unsigned long V_9 ;
if ( F_2 ( V_1 ) || ! F_3 ( V_1 ) )
return false ;
if ( V_10 )
F_4 ( L_1 V_11
L_5 ,
V_12 , V_1 ) ;
V_9 = V_13 ;
( * V_14 ) ++ ;
V_8 = F_7 ( V_1 ) ;
if ( V_8 ) {
if ( V_10 )
F_4 ( L_1 V_11
L_6 ,
V_12 , V_1 , V_8 ) ;
} else {
if ( V_10 )
F_4 ( L_1 V_11
L_7 ,
V_12 , V_1 ) ;
( * V_15 ) ++ ;
V_7 = V_13 - V_9 ;
* V_16 += V_7 ;
if ( * V_17 < 0 ) {
* V_17 = V_7 ;
* V_18 = V_7 ;
}
if ( * V_17 > V_7 )
* V_17 = V_7 ;
if ( * V_18 < V_7 )
* V_18 = V_7 ;
}
return true ;
}
static int
F_8 ( void * V_19 )
{
int V_1 ;
int V_20 = - 1 ;
F_9 ( rand ) ;
F_10 ( L_8 ) ;
F_11 (cpu)
V_20 = V_1 ;
F_12 ( V_20 < 0 ) ;
if ( V_20 == 0 ) {
F_10 ( L_9 ) ;
goto V_21;
}
if ( V_22 > 0 ) {
F_10 ( L_10 ) ;
F_13 ( V_22 ) ;
F_10 ( L_11 ) ;
}
while ( ! F_14 () ) {
V_1 = ( F_15 ( & rand ) >> 4 ) % ( V_20 + 1 ) ;
if ( ! F_1 ( V_1 ,
& V_23 , & V_24 ,
& V_25 , & V_26 , & V_27 ) )
F_6 ( V_1 ,
& V_28 , & V_29 ,
& V_30 , & V_31 , & V_32 ) ;
F_13 ( V_33 ) ;
}
V_21:
F_16 ( L_12 ) ;
return 0 ;
}
int F_17 ( long V_34 , long V_35 )
{
int V_8 = 0 ;
#ifdef F_18
V_22 = V_34 ;
V_33 = V_35 ;
if ( V_33 <= 0 )
return 0 ;
V_8 = F_19 ( F_8 , NULL , V_36 ) ;
#endif
return V_8 ;
}
static void F_20 ( void )
{
#ifdef F_18
if ( V_36 == NULL )
return;
F_10 ( L_13 ) ;
F_21 ( V_36 ) ;
V_36 = NULL ;
#endif
}
void F_22 ( void )
{
#ifdef F_18
F_23 ( L_14 ,
V_29 , V_28 ,
V_24 , V_23 ,
V_31 , V_32 ,
V_26 , V_27 ,
V_30 , V_25 , V_37 ) ;
#endif
}
bool F_24 ( void )
{
#ifdef F_18
return V_29 != V_28 ||
V_24 != V_23 ;
#else
return false ;
#endif
}
unsigned long
F_15 ( struct V_38 * V_39 )
{
if ( -- V_39 -> V_40 < 0 ) {
V_39 -> V_41 += ( unsigned long ) F_25 () ;
V_39 -> V_40 = V_42 ;
}
V_39 -> V_41 = V_39 -> V_41 * V_43 +
V_44 ;
return F_26 ( V_39 -> V_41 ) ;
}
void F_27 ( struct V_45 * V_46 )
{
struct V_47 * V_48 ;
if ( F_28 ( V_46 == NULL ) )
return;
V_48 = F_29 ( sizeof( * V_48 ) , V_49 ) ;
if ( F_28 ( V_48 == NULL ) )
return;
V_48 -> V_50 = V_46 ;
F_30 ( & V_51 ) ;
F_31 ( & V_48 -> V_52 , & V_53 ) ;
F_32 ( & V_51 ) ;
}
static void F_33 ( void )
{
struct V_47 * V_48 ;
struct V_47 * V_54 ;
F_30 ( & V_51 ) ;
F_34 (stp, p, &shuffle_task_list, st_l) {
F_35 ( & V_48 -> V_52 ) ;
F_36 ( V_48 ) ;
}
F_32 ( & V_51 ) ;
}
static void F_37 ( void )
{
struct V_47 * V_48 ;
F_38 ( V_55 ) ;
F_39 () ;
if ( F_40 () == 1 ) {
F_41 () ;
return;
}
V_56 = F_42 ( V_56 , V_55 ) ;
if ( V_56 >= V_57 )
V_56 = - 1 ;
else
F_43 ( V_56 , V_55 ) ;
F_30 ( & V_51 ) ;
F_44 (stp, &shuffle_task_list, st_l)
F_45 ( V_48 -> V_50 , V_55 ) ;
F_32 ( & V_51 ) ;
F_41 () ;
}
static int F_46 ( void * V_19 )
{
F_10 ( L_15 ) ;
do {
F_13 ( V_58 ) ;
F_37 () ;
F_47 ( L_16 ) ;
} while ( ! F_14 () );
F_16 ( L_16 ) ;
return 0 ;
}
int F_48 ( long V_59 )
{
V_58 = V_59 ;
V_56 = - 1 ;
if ( ! F_49 ( & V_55 , V_49 ) ) {
F_50 ( L_17 ) ;
return - V_60 ;
}
return F_19 ( F_46 , NULL , V_61 ) ;
}
static void F_51 ( void )
{
F_33 () ;
if ( V_61 ) {
F_10 ( L_18 ) ;
F_21 ( V_61 ) ;
F_52 ( V_55 ) ;
}
V_61 = NULL ;
}
void F_47 ( const char * V_62 )
{
while ( F_53 ( V_63 ) == V_64 ) {
F_54 ( L_19 ,
V_62 ) ;
F_55 ( V_65 ) ;
}
}
static int F_56 ( void * V_19 )
{
long V_7 ;
unsigned long V_66 ;
F_10 ( L_20 ) ;
V_66 = V_13 ;
while ( F_57 ( V_66 , V_67 ) &&
! F_14 () ) {
V_7 = V_67 - V_66 ;
if ( V_10 )
F_4 ( L_1 V_11
L_21 ,
V_12 , V_7 ) ;
F_13 ( V_7 ) ;
V_66 = V_13 ;
}
if ( F_14 () ) {
F_16 ( L_22 ) ;
return 0 ;
}
F_10 ( L_23 ) ;
V_68 = NULL ;
if ( V_69 )
V_69 () ;
else
F_10 ( L_24 ) ;
F_58 ( V_70 ) ;
F_59 () ;
return 0 ;
}
int F_60 ( int V_71 , void (* F_61)( void ) )
{
int V_8 = 0 ;
V_72 = V_71 ;
V_69 = F_61 ;
if ( V_72 > 0 ) {
V_67 = V_13 + V_72 * V_37 ;
V_8 = F_19 ( F_56 , NULL ,
V_68 ) ;
}
return V_8 ;
}
static int F_62 ( struct V_73 * V_74 ,
unsigned long V_75 , void * V_76 )
{
F_30 ( & V_77 ) ;
if ( F_53 ( V_63 ) == V_78 ) {
F_10 ( L_25 ) ;
F_63 ( V_63 , V_64 ) ;
} else {
F_64 ( L_26 ) ;
}
F_32 ( & V_77 ) ;
return V_79 ;
}
static void F_65 ( void )
{
F_66 ( & V_80 ) ;
if ( V_68 != NULL ) {
F_10 ( L_27 ) ;
F_21 ( V_68 ) ;
}
V_68 = NULL ;
}
void F_67 ( const char * V_62 )
{
F_68 () ;
while ( F_53 ( V_81 ) ||
( V_82 && ! F_53 ( * V_82 ) ) ) {
if ( V_81 )
if ( F_53 ( V_81 ) == 1 )
F_13 ( 1 ) ;
else
while ( F_53 ( V_81 ) )
F_69 () ;
else
F_13 ( F_70 ( V_37 ) ) ;
F_47 ( V_62 ) ;
}
}
static int F_71 ( void * V_19 )
{
F_10 ( L_28 ) ;
do {
if ( ! F_14 () ) {
if ( V_83 > 1 ) {
F_13 ( V_83 - 1 ) ;
F_63 ( V_81 , 2 ) ;
}
F_13 ( 1 ) ;
F_63 ( V_81 , 1 ) ;
}
if ( ! F_14 () )
F_13 ( V_83 ) ;
F_63 ( V_81 , 0 ) ;
F_47 ( L_29 ) ;
} while ( ! F_14 () );
F_16 ( L_29 ) ;
return 0 ;
}
int F_72 ( int V_84 )
{
int V_8 ;
V_83 = V_84 ;
V_8 = F_19 ( F_71 , NULL , V_85 ) ;
return V_8 ;
}
static void F_73 ( void )
{
if ( ! V_85 )
return;
F_10 ( L_30 ) ;
F_21 ( V_85 ) ;
V_85 = NULL ;
}
bool F_74 ( char * V_86 , bool V_87 , int * V_88 )
{
F_30 ( & V_77 ) ;
if ( V_12 != NULL ) {
F_4 ( L_31 ,
V_86 , V_12 ) ;
F_4 ( L_32 ) ;
F_32 ( & V_77 ) ;
return false ;
}
V_12 = V_86 ;
V_10 = V_87 ;
V_82 = V_88 ;
V_63 = V_78 ;
return true ;
}
void F_75 ( void )
{
F_32 ( & V_77 ) ;
F_76 ( & V_80 ) ;
}
bool F_77 ( void )
{
F_30 ( & V_77 ) ;
if ( F_53 ( V_63 ) == V_64 ) {
F_64 ( L_26 ) ;
F_32 ( & V_77 ) ;
F_55 ( 10 ) ;
return true ;
}
F_63 ( V_63 , V_89 ) ;
F_32 ( & V_77 ) ;
F_65 () ;
F_51 () ;
F_73 () ;
F_20 () ;
return false ;
}
void F_78 ( void )
{
F_30 ( & V_77 ) ;
V_12 = NULL ;
F_32 ( & V_77 ) ;
}
bool F_14 ( void )
{
return F_79 () || F_80 () ;
}
bool F_79 ( void )
{
return F_53 ( V_63 ) != V_78 ;
}
void F_16 ( char * V_62 )
{
char V_90 [ 128 ] ;
snprintf ( V_90 , sizeof( V_90 ) , L_33 , V_62 ) ;
F_10 ( V_90 ) ;
while ( ! F_80 () ) {
F_47 ( V_62 ) ;
F_55 ( 1 ) ;
}
}
int F_81 ( int (* F_82)( void * V_19 ) , void * V_19 , char * V_84 , char * V_91 ,
char * V_92 , struct V_45 * * V_46 )
{
int V_8 = 0 ;
F_10 ( V_91 ) ;
* V_46 = F_83 ( F_82 , V_19 , L_1 , V_84 ) ;
if ( F_84 ( * V_46 ) ) {
V_8 = F_85 ( * V_46 ) ;
F_50 ( V_92 ) ;
* V_46 = NULL ;
}
F_27 ( * V_46 ) ;
return V_8 ;
}
void F_86 ( char * V_91 , struct V_45 * * V_46 )
{
if ( * V_46 == NULL )
return;
F_10 ( V_91 ) ;
F_21 ( * V_46 ) ;
* V_46 = NULL ;
}
