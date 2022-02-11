static int
F_1 ( void * V_1 )
{
int V_2 ;
unsigned long V_3 ;
int V_4 = - 1 ;
F_2 ( rand ) ;
int V_5 ;
unsigned long V_6 ;
F_3 ( L_1 ) ;
F_4 (cpu)
V_4 = V_2 ;
F_5 ( V_4 < 0 ) ;
if ( V_7 > 0 ) {
F_3 ( L_2 ) ;
F_6 ( V_7 ) ;
F_3 ( L_3 ) ;
}
while ( ! F_7 () ) {
V_2 = ( F_8 ( & rand ) >> 4 ) % ( V_4 + 1 ) ;
if ( F_9 ( V_2 ) && F_10 ( V_2 ) ) {
if ( V_8 )
F_11 ( L_4 V_9
L_5 ,
V_10 , V_2 ) ;
V_6 = V_11 ;
V_12 ++ ;
V_5 = F_12 ( V_2 ) ;
if ( V_5 ) {
if ( V_8 )
F_11 ( L_4 V_9
L_6 ,
V_10 , V_2 , V_5 ) ;
} else {
if ( V_8 )
F_11 ( L_4 V_9
L_7 ,
V_10 , V_2 ) ;
V_13 ++ ;
V_3 = V_11 - V_6 ;
V_14 += V_3 ;
if ( V_15 < 0 ) {
V_15 = V_3 ;
V_16 = V_3 ;
}
if ( V_15 > V_3 )
V_15 = V_3 ;
if ( V_16 < V_3 )
V_16 = V_3 ;
}
} else if ( F_10 ( V_2 ) ) {
if ( V_8 )
F_11 ( L_4 V_9
L_8 ,
V_10 , V_2 ) ;
V_6 = V_11 ;
V_17 ++ ;
V_5 = F_13 ( V_2 ) ;
if ( V_5 ) {
if ( V_8 )
F_11 ( L_4 V_9
L_9 ,
V_10 , V_2 , V_5 ) ;
} else {
if ( V_8 )
F_11 ( L_4 V_9
L_10 ,
V_10 , V_2 ) ;
V_18 ++ ;
V_3 = V_11 - V_6 ;
V_19 += V_3 ;
if ( V_20 < 0 ) {
V_20 = V_3 ;
V_21 = V_3 ;
}
if ( V_20 > V_3 )
V_20 = V_3 ;
if ( V_21 < V_3 )
V_21 = V_3 ;
}
}
F_6 ( V_22 ) ;
}
F_14 ( L_11 ) ;
return 0 ;
}
int F_15 ( long V_23 , long V_24 )
{
int V_5 = 0 ;
#ifdef F_16
V_7 = V_23 ;
V_22 = V_24 ;
if ( V_22 <= 0 )
return 0 ;
V_5 = F_17 ( F_1 , NULL , V_25 ) ;
#endif
return V_5 ;
}
static void F_18 ( void )
{
#ifdef F_16
if ( V_25 == NULL )
return;
F_3 ( L_12 ) ;
F_19 ( V_25 ) ;
V_25 = NULL ;
#endif
}
void F_20 ( void )
{
#ifdef F_16
F_21 ( L_13 ,
V_18 , V_17 ,
V_13 , V_12 ,
V_20 , V_21 ,
V_15 , V_16 ,
V_19 , V_14 , V_26 ) ;
#endif
}
bool F_22 ( void )
{
#ifdef F_16
return V_18 != V_17 ||
V_13 != V_12 ;
#else
return false ;
#endif
}
unsigned long
F_8 ( struct V_27 * V_28 )
{
if ( -- V_28 -> V_29 < 0 ) {
V_28 -> V_30 += ( unsigned long ) F_23 () ;
V_28 -> V_29 = V_31 ;
}
V_28 -> V_30 = V_28 -> V_30 * V_32 +
V_33 ;
return F_24 ( V_28 -> V_30 ) ;
}
void F_25 ( struct V_34 * V_35 )
{
struct V_36 * V_37 ;
if ( F_26 ( V_35 == NULL ) )
return;
V_37 = F_27 ( sizeof( * V_37 ) , V_38 ) ;
if ( F_26 ( V_37 == NULL ) )
return;
V_37 -> V_39 = V_35 ;
F_28 ( & V_40 ) ;
F_29 ( & V_37 -> V_41 , & V_42 ) ;
F_30 ( & V_40 ) ;
}
static void F_31 ( void )
{
struct V_36 * V_37 ;
struct V_36 * V_43 ;
F_28 ( & V_40 ) ;
F_32 (stp, p, &shuffle_task_list, st_l) {
F_33 ( & V_37 -> V_41 ) ;
F_34 ( V_37 ) ;
}
F_30 ( & V_40 ) ;
}
static void F_35 ( void )
{
struct V_36 * V_37 ;
F_36 ( V_44 ) ;
F_37 () ;
if ( F_38 () == 1 ) {
F_39 () ;
return;
}
V_45 = F_40 ( V_45 , V_44 ) ;
if ( V_45 >= V_46 )
V_45 = - 1 ;
else
F_41 ( V_45 , V_44 ) ;
F_28 ( & V_40 ) ;
F_42 (stp, &shuffle_task_list, st_l)
F_43 ( V_37 -> V_39 , V_44 ) ;
F_30 ( & V_40 ) ;
F_39 () ;
}
static int F_44 ( void * V_1 )
{
F_3 ( L_14 ) ;
do {
F_6 ( V_47 ) ;
F_35 () ;
F_45 ( L_15 ) ;
} while ( ! F_7 () );
F_14 ( L_15 ) ;
return 0 ;
}
int F_46 ( long V_48 )
{
V_47 = V_48 ;
V_45 = - 1 ;
if ( ! F_47 ( & V_44 , V_38 ) ) {
F_48 ( L_16 ) ;
return - V_49 ;
}
return F_17 ( F_44 , NULL , V_50 ) ;
}
static void F_49 ( void )
{
F_31 () ;
if ( V_50 ) {
F_3 ( L_17 ) ;
F_19 ( V_50 ) ;
F_50 ( V_44 ) ;
}
V_50 = NULL ;
}
void F_45 ( const char * V_51 )
{
while ( F_51 ( V_52 ) == V_53 ) {
F_52 ( L_18 ,
V_51 ) ;
F_53 ( V_54 ) ;
}
}
static int F_54 ( void * V_1 )
{
long V_3 ;
unsigned long V_55 ;
F_3 ( L_19 ) ;
V_55 = V_11 ;
while ( F_55 ( V_55 , V_56 ) &&
! F_7 () ) {
V_3 = V_56 - V_55 ;
if ( V_8 )
F_11 ( L_4 V_9
L_20 ,
V_10 , V_3 ) ;
F_6 ( V_3 ) ;
V_55 = V_11 ;
}
if ( F_7 () ) {
F_14 ( L_21 ) ;
return 0 ;
}
F_3 ( L_22 ) ;
V_57 = NULL ;
if ( V_58 )
V_58 () ;
else
F_3 ( L_23 ) ;
F_56 () ;
return 0 ;
}
int F_57 ( int V_59 , void (* F_58)( void ) )
{
int V_5 = 0 ;
V_60 = V_59 ;
V_58 = F_58 ;
if ( V_60 > 0 ) {
V_56 = V_11 + V_60 * V_26 ;
V_5 = F_17 ( F_54 , NULL ,
V_57 ) ;
}
return V_5 ;
}
static int F_59 ( struct V_61 * V_62 ,
unsigned long V_63 , void * V_64 )
{
F_28 ( & V_65 ) ;
if ( F_51 ( V_52 ) == V_66 ) {
F_3 ( L_24 ) ;
F_60 ( V_52 , V_53 ) ;
} else {
F_61 ( L_25 ) ;
}
F_30 ( & V_65 ) ;
return V_67 ;
}
static void F_62 ( void )
{
F_63 ( & V_68 ) ;
if ( V_57 != NULL ) {
F_3 ( L_26 ) ;
F_19 ( V_57 ) ;
}
V_57 = NULL ;
}
void F_64 ( const char * V_51 )
{
while ( F_51 ( V_69 ) ||
( V_70 && ! F_51 ( * V_70 ) ) ) {
if ( V_69 )
if ( F_51 ( V_69 ) == 1 )
F_6 ( 1 ) ;
else
while ( F_51 ( V_69 ) )
F_65 () ;
else
F_6 ( F_66 ( V_26 ) ) ;
F_45 ( V_51 ) ;
}
}
static int F_67 ( void * V_1 )
{
F_3 ( L_27 ) ;
do {
if ( ! F_7 () ) {
if ( V_71 > 1 ) {
F_6 ( V_71 - 1 ) ;
F_60 ( V_69 , 2 ) ;
}
F_6 ( 1 ) ;
F_60 ( V_69 , 1 ) ;
}
if ( ! F_7 () )
F_6 ( V_71 ) ;
F_60 ( V_69 , 0 ) ;
F_45 ( L_28 ) ;
} while ( ! F_7 () );
F_14 ( L_28 ) ;
return 0 ;
}
int F_68 ( int V_72 )
{
int V_5 ;
V_71 = V_72 ;
V_5 = F_17 ( F_67 , NULL , V_73 ) ;
return V_5 ;
}
static void F_69 ( void )
{
if ( ! V_73 )
return;
F_3 ( L_29 ) ;
F_19 ( V_73 ) ;
V_73 = NULL ;
}
bool F_70 ( char * V_74 , bool V_75 , int * V_76 )
{
F_28 ( & V_65 ) ;
if ( V_10 != NULL ) {
F_11 ( L_30 ,
V_74 , V_10 ) ;
F_30 ( & V_65 ) ;
return false ;
}
V_10 = V_74 ;
V_8 = V_75 ;
V_70 = V_76 ;
V_52 = V_66 ;
return true ;
}
void F_71 ( void )
{
F_30 ( & V_65 ) ;
F_72 ( & V_68 ) ;
}
bool F_73 ( void )
{
F_28 ( & V_65 ) ;
if ( F_51 ( V_52 ) == V_53 ) {
F_61 ( L_25 ) ;
F_30 ( & V_65 ) ;
F_53 ( 10 ) ;
return true ;
}
F_60 ( V_52 , V_77 ) ;
F_30 ( & V_65 ) ;
F_62 () ;
F_49 () ;
F_69 () ;
F_18 () ;
return false ;
}
void F_74 ( void )
{
F_28 ( & V_65 ) ;
V_10 = NULL ;
F_30 ( & V_65 ) ;
}
bool F_7 ( void )
{
return F_75 () || F_76 () ;
}
bool F_75 ( void )
{
return F_51 ( V_52 ) != V_66 ;
}
void F_14 ( char * V_51 )
{
char V_78 [ 128 ] ;
snprintf ( V_78 , sizeof( V_78 ) , L_31 , V_51 ) ;
F_3 ( V_78 ) ;
while ( ! F_76 () ) {
F_45 ( V_51 ) ;
F_53 ( 1 ) ;
}
}
int F_77 ( int (* F_78)( void * V_1 ) , void * V_1 , char * V_72 , char * V_79 ,
char * V_80 , struct V_34 * * V_35 )
{
int V_5 = 0 ;
F_3 ( V_79 ) ;
* V_35 = F_79 ( F_78 , V_1 , L_4 , V_72 ) ;
if ( F_80 ( * V_35 ) ) {
V_5 = F_81 ( * V_35 ) ;
F_48 ( V_80 ) ;
* V_35 = NULL ;
}
F_25 ( * V_35 ) ;
return V_5 ;
}
void F_82 ( char * V_79 , struct V_34 * * V_35 )
{
if ( * V_35 == NULL )
return;
F_3 ( V_79 ) ;
F_19 ( * V_35 ) ;
* V_35 = NULL ;
}
