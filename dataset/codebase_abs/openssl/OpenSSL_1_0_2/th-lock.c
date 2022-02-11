void F_1 ( void )
{
int V_1 ;
V_2 = F_2 ( F_3 () * sizeof( V_3 ) ) ;
for ( V_1 = 0 ; V_1 < F_3 () ; V_1 ++ ) {
V_2 [ V_1 ] = F_4 ( NULL , FALSE , NULL ) ;
}
F_5 ( ( void ( * ) ( int , int , char * , int ) )
V_4 ) ;
return ( 1 ) ;
}
static void F_6 ( void )
{
int V_1 ;
F_5 ( NULL ) ;
for ( V_1 = 0 ; V_1 < F_3 () ; V_1 ++ )
F_7 ( V_2 [ V_1 ] ) ;
F_8 ( V_2 ) ;
}
void V_4 ( int V_5 , int type , char * V_6 , int line )
{
if ( V_5 & V_7 ) {
F_9 ( V_2 [ type ] , V_8 ) ;
} else {
F_10 ( V_2 [ type ] ) ;
}
}
void F_1 ( void )
{
int V_1 ;
# ifdef F_11
V_2 = F_2 ( F_3 () * sizeof( V_9 ) ) ;
# else
V_2 = F_2 ( F_3 () * sizeof( V_10 ) ) ;
# endif
V_11 = F_2 ( F_3 () * sizeof( long ) ) ;
for ( V_1 = 0 ; V_1 < F_3 () ; V_1 ++ ) {
V_11 [ V_1 ] = 0 ;
# ifdef F_11
F_12 ( & ( V_2 [ V_1 ] ) , V_12 , NULL ) ;
# else
F_13 ( & ( V_2 [ V_1 ] ) , V_12 , NULL ) ;
# endif
}
F_14 ( ( unsigned long ( * ) () ) V_13 ) ;
F_5 ( ( void ( * ) () ) V_14 ) ;
}
void F_6 ( void )
{
int V_1 ;
F_5 ( NULL ) ;
for ( V_1 = 0 ; V_1 < F_3 () ; V_1 ++ ) {
# ifdef F_11
F_15 ( & ( V_2 [ V_1 ] ) ) ;
# else
F_16 ( & ( V_2 [ V_1 ] ) ) ;
# endif
}
F_8 ( V_2 ) ;
F_8 ( V_11 ) ;
}
void V_14 ( int V_5 , int type , char * V_6 , int line )
{
# if 0
fprintf(stderr, "thread=%4d mode=%s lock=%s %s:%d\n",
CRYPTO_thread_id(),
(mode & CRYPTO_LOCK) ? "l" : "u",
(type & CRYPTO_READ) ? "r" : "w", file, line);
# endif
# if 0
if (CRYPTO_LOCK_SSL_CERT == type)
fprintf(stderr, "(t,m,f,l) %ld %d %s %d\n",
CRYPTO_thread_id(), mode, file, line);
# endif
if ( V_5 & V_7 ) {
# ifdef F_11
F_17 ( & ( V_2 [ type ] ) ) ;
# else
if ( V_5 & V_15 )
F_18 ( & ( V_2 [ type ] ) ) ;
else
F_19 ( & ( V_2 [ type ] ) ) ;
# endif
V_11 [ type ] ++ ;
} else {
# ifdef F_11
F_20 ( & ( V_2 [ type ] ) ) ;
# else
F_21 ( & ( V_2 [ type ] ) ) ;
# endif
}
}
unsigned long V_13 ( void )
{
unsigned long V_16 ;
V_16 = ( unsigned long ) F_22 () ;
return ( V_16 ) ;
}
void F_1 ( void )
{
int V_1 ;
char V_17 [ 20 ] ;
strcpy ( V_17 , L_1 ) ;
F_23 ( V_17 ) ;
F_24 ( V_18 ) ;
F_24 ( V_19 ) ;
F_24 ( V_20 , 100 ) ;
F_24 ( V_21 , V_22 ) ;
V_23 = F_25 ( V_17 ) ;
F_26 ( V_17 ) ;
V_2 = F_2 ( F_3 () * sizeof( V_24 * ) ) ;
for ( V_1 = 0 ; V_1 < F_3 () ; V_1 ++ ) {
V_2 [ V_1 ] = F_27 ( V_23 , 1 ) ;
}
F_14 ( ( unsigned long ( * ) () ) V_25 ) ;
F_5 ( ( void ( * ) () ) V_26 ) ;
}
void F_6 ( void )
{
int V_1 ;
F_5 ( NULL ) ;
for ( V_1 = 0 ; V_1 < F_3 () ; V_1 ++ ) {
char V_27 [ 10 ] ;
sprintf ( V_27 , L_2 , V_1 ) ;
F_28 ( V_2 [ V_1 ] , stdout , V_27 ) ;
F_29 ( V_2 [ V_1 ] , V_23 ) ;
}
F_8 ( V_2 ) ;
}
void V_26 ( int V_5 , int type , char * V_6 , int line )
{
if ( V_5 & V_7 ) {
F_30 ( V_2 [ type ] ) ;
} else {
F_31 ( V_2 [ type ] ) ;
}
}
unsigned long V_25 ( void )
{
unsigned long V_16 ;
V_16 = ( unsigned long ) F_32 () ;
return ( V_16 ) ;
}
void F_1 ( void )
{
int V_1 ;
V_2 = F_2 ( F_3 () * sizeof( V_28 ) ) ;
V_11 = F_2 ( F_3 () * sizeof( long ) ) ;
for ( V_1 = 0 ; V_1 < F_3 () ; V_1 ++ ) {
V_11 [ V_1 ] = 0 ;
F_33 ( & ( V_2 [ V_1 ] ) , NULL ) ;
}
F_14 ( ( unsigned long ( * ) () ) V_29 ) ;
F_5 ( ( void ( * ) () ) V_30 ) ;
}
void F_34 ( void )
{
int V_1 ;
F_5 ( NULL ) ;
for ( V_1 = 0 ; V_1 < F_3 () ; V_1 ++ ) {
F_35 ( & ( V_2 [ V_1 ] ) ) ;
}
F_8 ( V_2 ) ;
F_8 ( V_11 ) ;
}
void V_30 ( int V_5 , int type , char * V_6 , int line )
{
# if 0
fprintf(stderr, "thread=%4d mode=%s lock=%s %s:%d\n",
CRYPTO_thread_id(),
(mode & CRYPTO_LOCK) ? "l" : "u",
(type & CRYPTO_READ) ? "r" : "w", file, line);
# endif
# if 0
if (CRYPTO_LOCK_SSL_CERT == type)
fprintf(stderr, "(t,m,f,l) %ld %d %s %d\n",
CRYPTO_thread_id(), mode, file, line);
# endif
if ( V_5 & V_7 ) {
F_36 ( & ( V_2 [ type ] ) ) ;
V_11 [ type ] ++ ;
} else {
F_37 ( & ( V_2 [ type ] ) ) ;
}
}
unsigned long V_29 ( void )
{
unsigned long V_16 ;
V_16 = ( unsigned long ) F_38 () ;
return ( V_16 ) ;
}
