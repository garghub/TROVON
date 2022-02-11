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
char * F_20 ( char * V_26 )
{
#ifdef F_16
V_26 += sprintf ( V_26 ,
L_13 ,
V_18 , V_17 ,
V_13 , V_12 ,
V_20 , V_21 ,
V_15 , V_16 ,
V_19 , V_14 , V_27 ) ;
#endif
return V_26 ;
}
bool F_21 ( void )
{
#ifdef F_16
return V_18 != V_17 ||
V_13 != V_12 ;
#else
return false ;
#endif
}
unsigned long
F_8 ( struct V_28 * V_29 )
{
if ( -- V_29 -> V_30 < 0 ) {
V_29 -> V_31 += ( unsigned long ) F_22 () ;
V_29 -> V_30 = V_32 ;
}
V_29 -> V_31 = V_29 -> V_31 * V_33 +
V_34 ;
return F_23 ( V_29 -> V_31 ) ;
}
void F_24 ( struct V_35 * V_36 )
{
struct V_37 * V_38 ;
if ( F_25 ( V_36 == NULL ) )
return;
V_38 = F_26 ( sizeof( * V_38 ) , V_39 ) ;
if ( F_25 ( V_38 == NULL ) )
return;
V_38 -> V_40 = V_36 ;
F_27 ( & V_41 ) ;
F_28 ( & V_38 -> V_42 , & V_43 ) ;
F_29 ( & V_41 ) ;
}
static void F_30 ( void )
{
struct V_37 * V_38 ;
struct V_37 * V_44 ;
F_27 ( & V_41 ) ;
F_31 (stp, p, &shuffle_task_list, st_l) {
F_32 ( & V_38 -> V_42 ) ;
F_33 ( V_38 ) ;
}
F_29 ( & V_41 ) ;
}
static void F_34 ( void )
{
struct V_37 * V_38 ;
F_35 ( V_45 ) ;
F_36 () ;
if ( F_37 () == 1 ) {
F_38 () ;
return;
}
V_46 = F_39 ( V_46 , V_45 ) ;
if ( V_46 >= V_47 )
V_46 = - 1 ;
if ( V_46 != - 1 ) {
F_40 ( V_46 , V_45 ) ;
if ( F_41 ( V_45 ) ) {
F_38 () ;
return;
}
}
F_27 ( & V_41 ) ;
F_42 (stp, &shuffle_task_list, st_l)
F_43 ( V_38 -> V_40 , V_45 ) ;
F_29 ( & V_41 ) ;
F_38 () ;
}
static int F_44 ( void * V_1 )
{
F_3 ( L_14 ) ;
do {
F_6 ( V_48 ) ;
F_34 () ;
F_45 ( L_15 ) ;
} while ( ! F_7 () );
F_14 ( L_15 ) ;
return 0 ;
}
int F_46 ( long V_49 )
{
V_48 = V_49 ;
V_46 = - 1 ;
if ( ! F_47 ( & V_45 , V_39 ) ) {
F_48 ( L_16 ) ;
return - V_50 ;
}
return F_17 ( F_44 , NULL , V_51 ) ;
}
static void F_49 ( void )
{
F_30 () ;
if ( V_51 ) {
F_3 ( L_17 ) ;
F_19 ( V_51 ) ;
F_50 ( V_45 ) ;
}
V_51 = NULL ;
}
void F_45 ( const char * V_52 )
{
while ( F_51 ( V_53 ) == V_54 ) {
F_52 ( L_18 ,
V_52 ) ;
F_53 ( V_55 ) ;
}
}
static int F_54 ( void * V_1 )
{
long V_3 ;
unsigned long V_56 ;
F_3 ( L_19 ) ;
V_56 = V_11 ;
while ( F_55 ( V_56 , V_57 ) &&
! F_7 () ) {
V_3 = V_57 - V_56 ;
if ( V_8 )
F_11 ( L_4 V_9
L_20 ,
V_10 , V_3 ) ;
F_6 ( V_3 ) ;
V_56 = V_11 ;
}
if ( F_7 () ) {
F_14 ( L_21 ) ;
return 0 ;
}
F_3 ( L_22 ) ;
V_58 = NULL ;
if ( V_59 )
V_59 () ;
else
F_3 ( L_23 ) ;
F_56 () ;
return 0 ;
}
int F_57 ( int V_60 , void (* F_58)( void ) )
{
int V_5 = 0 ;
V_61 = V_60 ;
V_59 = F_58 ;
if ( V_61 > 0 ) {
V_57 = V_11 + V_61 * V_27 ;
V_5 = F_17 ( F_54 , NULL ,
V_58 ) ;
}
return V_5 ;
}
static int F_59 ( struct V_62 * V_63 ,
unsigned long V_64 , void * V_65 )
{
F_27 ( & V_66 ) ;
if ( F_51 ( V_53 ) == V_67 ) {
F_3 ( L_24 ) ;
F_51 ( V_53 ) = V_54 ;
} else {
F_60 ( L_25 ) ;
}
F_29 ( & V_66 ) ;
return V_68 ;
}
static void F_61 ( void )
{
F_62 ( & V_69 ) ;
if ( V_58 != NULL ) {
F_3 ( L_26 ) ;
F_19 ( V_58 ) ;
}
V_58 = NULL ;
}
void F_63 ( const char * V_52 )
{
while ( F_51 ( V_70 ) ||
( V_71 && ! F_51 ( * V_71 ) ) ) {
if ( V_70 )
F_6 ( 1 ) ;
else
F_6 ( F_64 ( V_27 ) ) ;
F_45 ( V_52 ) ;
}
}
static int F_65 ( void * V_1 )
{
F_3 ( L_27 ) ;
do {
if ( ! F_7 () ) {
F_6 ( V_72 ) ;
F_51 ( V_70 ) = 1 ;
}
if ( ! F_7 () )
F_6 ( V_72 ) ;
F_51 ( V_70 ) = 0 ;
F_45 ( L_28 ) ;
} while ( ! F_7 () );
F_14 ( L_28 ) ;
return 0 ;
}
int F_66 ( int V_73 )
{
int V_5 ;
V_72 = V_73 ;
V_5 = F_17 ( F_65 , NULL , V_74 ) ;
return V_5 ;
}
static void F_67 ( void )
{
if ( ! V_74 )
return;
F_3 ( L_29 ) ;
F_19 ( V_74 ) ;
V_74 = NULL ;
}
void T_1 F_68 ( char * V_75 , bool V_76 , int * V_77 )
{
F_27 ( & V_66 ) ;
V_10 = V_75 ;
V_8 = V_76 ;
V_71 = V_77 ;
V_53 = V_67 ;
}
void T_1 F_69 ( void )
{
F_29 ( & V_66 ) ;
F_70 ( & V_69 ) ;
}
bool F_71 ( void )
{
F_27 ( & V_66 ) ;
if ( F_51 ( V_53 ) == V_54 ) {
F_60 ( L_25 ) ;
F_29 ( & V_66 ) ;
F_53 ( 10 ) ;
return true ;
}
F_51 ( V_53 ) = V_78 ;
F_29 ( & V_66 ) ;
F_61 () ;
F_49 () ;
F_67 () ;
F_18 () ;
return false ;
}
bool F_7 ( void )
{
return F_72 () || F_73 () ;
}
bool F_72 ( void )
{
return F_51 ( V_53 ) != V_67 ;
}
void F_14 ( char * V_52 )
{
if ( V_8 )
F_3 ( V_52 ) ;
while ( ! F_73 () ) {
F_45 ( V_52 ) ;
F_53 ( 1 ) ;
}
}
int F_74 ( int (* F_75)( void * V_1 ) , void * V_1 , char * V_73 , char * V_79 ,
char * V_80 , struct V_35 * * V_36 )
{
int V_5 = 0 ;
F_3 ( V_79 ) ;
* V_36 = F_76 ( F_75 , V_1 , V_73 ) ;
if ( F_77 ( * V_36 ) ) {
V_5 = F_78 ( * V_36 ) ;
F_48 ( V_80 ) ;
* V_36 = NULL ;
}
F_24 ( * V_36 ) ;
return V_5 ;
}
void F_79 ( char * V_79 , struct V_35 * * V_36 )
{
if ( * V_36 == NULL )
return;
F_3 ( V_79 ) ;
F_19 ( * V_36 ) ;
* V_36 = NULL ;
}
