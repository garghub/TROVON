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
F_56 ( V_59 ) ;
F_57 () ;
return 0 ;
}
int F_58 ( int V_60 , void (* F_59)( void ) )
{
int V_5 = 0 ;
V_61 = V_60 ;
V_58 = F_59 ;
if ( V_61 > 0 ) {
V_56 = V_11 + V_61 * V_26 ;
V_5 = F_17 ( F_54 , NULL ,
V_57 ) ;
}
return V_5 ;
}
static int F_60 ( struct V_62 * V_63 ,
unsigned long V_64 , void * V_65 )
{
F_28 ( & V_66 ) ;
if ( F_51 ( V_52 ) == V_67 ) {
F_3 ( L_24 ) ;
F_61 ( V_52 , V_53 ) ;
} else {
F_62 ( L_25 ) ;
}
F_30 ( & V_66 ) ;
return V_68 ;
}
static void F_63 ( void )
{
F_64 ( & V_69 ) ;
if ( V_57 != NULL ) {
F_3 ( L_26 ) ;
F_19 ( V_57 ) ;
}
V_57 = NULL ;
}
void F_65 ( const char * V_51 )
{
F_66 () ;
while ( F_51 ( V_70 ) ||
( V_71 && ! F_51 ( * V_71 ) ) ) {
if ( V_70 )
if ( F_51 ( V_70 ) == 1 )
F_6 ( 1 ) ;
else
while ( F_51 ( V_70 ) )
F_67 () ;
else
F_6 ( F_68 ( V_26 ) ) ;
F_45 ( V_51 ) ;
}
}
static int F_69 ( void * V_1 )
{
F_3 ( L_27 ) ;
do {
if ( ! F_7 () ) {
if ( V_72 > 1 ) {
F_6 ( V_72 - 1 ) ;
F_61 ( V_70 , 2 ) ;
}
F_6 ( 1 ) ;
F_61 ( V_70 , 1 ) ;
}
if ( ! F_7 () )
F_6 ( V_72 ) ;
F_61 ( V_70 , 0 ) ;
F_45 ( L_28 ) ;
} while ( ! F_7 () );
F_14 ( L_28 ) ;
return 0 ;
}
int F_70 ( int V_73 )
{
int V_5 ;
V_72 = V_73 ;
V_5 = F_17 ( F_69 , NULL , V_74 ) ;
return V_5 ;
}
static void F_71 ( void )
{
if ( ! V_74 )
return;
F_3 ( L_29 ) ;
F_19 ( V_74 ) ;
V_74 = NULL ;
}
bool F_72 ( char * V_75 , bool V_76 , int * V_77 )
{
F_28 ( & V_66 ) ;
if ( V_10 != NULL ) {
F_11 ( L_30 ,
V_75 , V_10 ) ;
F_11 ( L_31 ) ;
F_30 ( & V_66 ) ;
return false ;
}
V_10 = V_75 ;
V_8 = V_76 ;
V_71 = V_77 ;
V_52 = V_67 ;
return true ;
}
void F_73 ( void )
{
F_30 ( & V_66 ) ;
F_74 ( & V_69 ) ;
}
bool F_75 ( void )
{
F_28 ( & V_66 ) ;
if ( F_51 ( V_52 ) == V_53 ) {
F_62 ( L_25 ) ;
F_30 ( & V_66 ) ;
F_53 ( 10 ) ;
return true ;
}
F_61 ( V_52 , V_78 ) ;
F_30 ( & V_66 ) ;
F_63 () ;
F_49 () ;
F_71 () ;
F_18 () ;
return false ;
}
void F_76 ( void )
{
F_28 ( & V_66 ) ;
V_10 = NULL ;
F_30 ( & V_66 ) ;
}
bool F_7 ( void )
{
return F_77 () || F_78 () ;
}
bool F_77 ( void )
{
return F_51 ( V_52 ) != V_67 ;
}
void F_14 ( char * V_51 )
{
char V_79 [ 128 ] ;
snprintf ( V_79 , sizeof( V_79 ) , L_32 , V_51 ) ;
F_3 ( V_79 ) ;
while ( ! F_78 () ) {
F_45 ( V_51 ) ;
F_53 ( 1 ) ;
}
}
int F_79 ( int (* F_80)( void * V_1 ) , void * V_1 , char * V_73 , char * V_80 ,
char * V_81 , struct V_34 * * V_35 )
{
int V_5 = 0 ;
F_3 ( V_80 ) ;
* V_35 = F_81 ( F_80 , V_1 , L_4 , V_73 ) ;
if ( F_82 ( * V_35 ) ) {
V_5 = F_83 ( * V_35 ) ;
F_48 ( V_81 ) ;
* V_35 = NULL ;
}
F_25 ( * V_35 ) ;
return V_5 ;
}
void F_84 ( char * V_80 , struct V_34 * * V_35 )
{
if ( * V_35 == NULL )
return;
F_3 ( V_80 ) ;
F_19 ( * V_35 ) ;
* V_35 = NULL ;
}
