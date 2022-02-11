int F_1 ( void )
{
int V_1 = 1 ;
F_2 ( & V_2 ) ;
assert ( V_3 < V_4 ) ;
if ( V_3 ++ == 0 ) {
int V_5 = ( F_3 ( & V_6 , 0 ) == 0 ) ;
int V_7 = ( F_3 ( & V_8 , 0 ) == 0 ) ;
int V_9 = ( F_3 ( & V_10 , 0 ) == 0 ) ;
int V_11 = ( F_3 ( & V_12 , 0 ) == 0 ) ;
if ( ! V_5 || ! V_7 || ! V_9 || ! V_11 ) {
V_1 = 0 ;
V_3 = 0 ;
if ( V_5 )
F_4 ( V_6 ) ;
if ( V_7 )
F_4 ( V_8 ) ;
if ( V_9 )
F_4 ( V_10 ) ;
if ( V_11 )
F_4 ( V_12 ) ;
}
}
F_5 ( & V_2 ) ;
return V_1 ;
}
void F_6 ( void )
{
F_2 ( & V_2 ) ;
assert ( V_3 > 0 ) ;
if ( -- V_3 == 0 ) {
F_4 ( V_6 ) ;
F_4 ( V_8 ) ;
F_4 ( V_10 ) ;
F_4 ( V_12 ) ;
}
F_5 ( & V_2 ) ;
}
int F_1 ( void )
{
assert ( V_3 < V_4 ) ;
V_3 ++ ;
return 1 ;
}
void F_6 ( void )
{
assert ( V_3 > 0 ) ;
V_3 -- ;
}
static int F_7 ( const volatile T_1 * V_13 , const T_1 * V_14 )
{
int V_15 = ( V_14 -> V_16 == V_17 ||
V_14 -> V_16 == V_13 -> V_16 ) ;
int V_18 = ( V_14 -> V_19 == V_20 ||
V_14 -> V_19 == V_13 -> V_19 ) ;
return V_15 && V_18 ;
}
T_2 static void F_8 ( T_3 * V_21 )
{
struct V_22 * V_23 ;
assert ( V_21 -> V_24 . V_16 != 0 &&
V_21 -> V_24 . V_19 != 0 ) ;
for ( V_23 = F_9 () ; V_23 != 0 ; V_23 = V_23 -> V_25 ) {
if ( V_23 -> V_26 == V_27 ) {
V_23 -> V_28 . V_29 -> V_30 ( V_23 -> V_28 . V_29 -> V_31 ) ;
} else {
struct V_32 * V_33 = V_23 -> V_28 . V_34 ;
const T_1 * V_35 = V_33 -> V_24 ;
T_4 V_36 ;
assert ( V_23 -> V_26 == V_37 ) ;
F_10 ( V_33 -> V_38 . V_39 ) ;
for ( V_36 = 0 ; V_36 < V_33 -> V_40 ; V_35 ++ , V_36 ++ ) {
if ( F_7 ( & V_21 -> V_24 , V_35 ) ) {
V_33 -> V_38 = * V_21 ;
F_11 ( V_23 ) ;
longjmp ( V_33 -> V_41 , 1 ) ;
}
}
}
}
F_11 ( V_23 ) ;
F_12 () ( V_21 ) ;
abort () ;
}
static void F_13 ( T_3 * V_21 )
{
if ( V_21 -> V_42 == NULL ) {
fprintf ( V_43 , L_1 ,
V_21 -> V_24 . V_16 ,
V_21 -> V_24 . V_19 ) ;
} else {
fprintf ( V_43 , L_2 ,
V_21 -> V_42 , V_21 -> V_24 . V_16 ,
V_21 -> V_24 . V_19 ) ;
}
abort () ;
}
static void F_14 ( struct V_22 * V_44 )
{
V_44 -> V_25 = F_9 () ;
F_11 ( V_44 ) ;
}
void F_15 ( struct V_22 * V_45 ,
struct V_29 * V_46 , void (* F_16)( void * ) , void * V_47 )
{
V_45 -> V_26 = V_27 ;
V_46 -> V_30 = F_16 ;
V_46 -> V_31 = V_47 ;
V_45 -> V_28 . V_29 = V_46 ;
F_14 ( V_45 ) ;
}
void F_17 ( struct V_22 * V_45 ,
struct V_32 * V_48 , const T_1 V_49 [] , T_4 V_50 )
{
V_48 -> V_24 = V_49 ;
V_48 -> V_40 = V_50 ;
V_48 -> V_38 . V_39 = 0 ;
V_45 -> V_26 = V_37 ;
V_45 -> V_28 . V_34 = V_48 ;
F_14 ( V_45 ) ;
}
struct V_22 * F_18 ( void )
{
struct V_22 * V_23 = F_9 () ;
F_11 ( V_23 -> V_25 ) ;
return V_23 ;
}
T_2 void F_19 ( T_3 * V_21 )
{
struct V_22 * V_23 = F_9 () ;
assert ( V_23 != 0 ) ;
assert ( V_23 -> V_26 == V_37 ) ;
assert ( & V_23 -> V_28 . V_34 -> V_38 == V_21 ) ;
F_11 ( V_23 -> V_25 ) ;
F_8 ( V_21 ) ;
}
T_2 void F_20 ( long V_51 , long V_52 , const char * V_53 )
{
T_3 V_21 ;
V_21 . V_24 . V_16 = V_51 ;
V_21 . V_24 . V_19 = V_52 ;
V_21 . V_42 = V_53 ;
V_21 . V_39 = 0 ;
#ifdef F_21
if ( V_52 == V_54 && F_22 () ) {
F_23 () ;
}
#endif
F_8 ( & V_21 ) ;
}
T_2 void F_24 ( long V_51 , long V_52 , const char * V_53 , void * V_55 )
{
T_3 V_21 ;
V_21 . V_24 . V_16 = V_51 ;
V_21 . V_24 . V_19 = V_52 ;
V_21 . V_42 = V_53 ;
V_21 . V_39 = V_55 ;
F_8 ( & V_21 ) ;
}
T_2 void F_25 ( long V_51 , long V_52 , const char * V_56 , ... )
{
char * V_57 = ( char * ) F_26 ( V_58 ) ;
T_5 V_59 ;
va_start ( V_59 , V_56 ) ;
F_27 ( V_57 , V_58 , V_56 , V_59 ) ;
va_end ( V_59 ) ;
F_24 ( V_51 , V_52 , V_57 , V_57 ) ;
}
unsigned long V_19 ( T_3 * V_60 )
{
return V_60 -> V_24 . V_19 ;
}
unsigned long V_16 ( T_3 * V_60 )
{
return V_60 -> V_24 . V_16 ;
}
const char * V_42 ( T_3 * V_60 )
{
return V_60 -> V_42 ;
}
void * F_28 ( T_3 * V_60 )
{
return V_60 -> V_39 ;
}
void * F_29 ( T_3 * V_60 )
{
void * V_55 = V_60 -> V_39 ;
V_60 -> V_39 = 0 ;
return V_55 ;
}
void F_30 ( void * (* F_31)( T_4 ) , void (* F_32)( void * ) )
{
F_33 ( F_31 ) ;
F_34 ( F_32 ) ;
}
void * F_26 ( T_4 V_50 )
{
void * V_61 = F_35 () ( V_50 ) ;
if ( V_61 == 0 )
F_20 ( V_62 , 0 , L_3 ) ;
return V_61 ;
}
void F_10 ( void * V_61 )
{
F_36 () ( V_61 ) ;
}
static void F_37 ( void * V_63 )
{
printf ( L_4 , ( char * ) V_63 ) ;
}
static void F_38 ( void )
{
char V_57 [ 256 ] ;
printf ( L_5 ) ; fflush ( stdout ) ;
fgets ( V_57 , sizeof V_57 , V_64 ) ;
if ( V_57 [ 0 ] >= 0 && ( V_57 [ 0 ] == 'Y' || V_57 [ 0 ] == 'y' ) )
F_20 ( 1 , 1 , L_6 ) ;
}
static void F_39 ( void )
{
F_40 ( F_37 , L_7 ) ;
F_38 () ;
F_41 ( 0 ) ;
}
int main ( int V_65 , char * * V_66 )
{
static const T_1 V_67 [] = { { 1 , 1 } , { 1 , 2 } } ;
T_3 * V_60 ;
char * V_53 ;
F_42 ( V_67 , 2 , & V_60 ) ;
if ( ! V_60 ) {
F_42 ( V_67 , 2 , & V_60 ) ;
if ( ! V_60 ) {
F_39 () ;
} else {
V_53 = V_42 ( V_60 ) ;
if ( V_53 == NULL ) {
printf ( L_8 ,
V_16 ( V_60 ) , V_19 ( V_60 ) ) ;
} else {
printf ( L_9 ,
V_53 , V_16 ( V_60 ) , V_19 ( V_60 ) ) ;
}
F_19 ( V_60 ) ;
}
F_43 () ;
} else {
V_53 = V_42 ( V_60 ) ;
if ( V_53 == NULL ) {
printf ( L_10 ,
V_16 ( V_60 ) , V_19 ( V_60 ) ) ;
} else {
printf ( L_11 ,
V_42 ( V_60 ) , V_16 ( V_60 ) , V_19 ( V_60 ) ) ;
}
}
F_43 () ;
F_20 ( 99 , 99 , L_12 ) ;
return 0 ;
}
