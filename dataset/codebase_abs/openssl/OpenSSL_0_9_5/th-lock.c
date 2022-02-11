void F_1 ( void )
{
int V_1 ;
V_2 = Malloc ( F_2 () * sizeof( V_3 ) ) ;
for ( V_1 = 0 ; V_1 < F_2 () ; V_1 ++ )
{
V_2 [ V_1 ] = F_3 ( NULL , FALSE , NULL ) ;
}
F_4 ( ( void ( * ) ( int , int , char * , int ) ) V_4 ) ;
return ( 1 ) ;
}
static void F_5 ( void )
{
int V_1 ;
F_4 ( NULL ) ;
for ( V_1 = 0 ; V_1 < F_2 () ; V_1 ++ )
F_6 ( V_2 [ V_1 ] ) ;
Free ( V_2 ) ;
}
void V_4 ( int V_5 , int type , char * V_6 , int line )
{
if ( V_5 & V_7 )
{
F_7 ( V_2 [ type ] , V_8 ) ;
}
else
{
F_8 ( V_2 [ type ] ) ;
}
}
void F_1 ( void )
{
int V_1 ;
#ifdef F_9
V_2 = Malloc ( F_2 () * sizeof( V_9 ) ) ;
#else
V_2 = Malloc ( F_2 () * sizeof( V_10 ) ) ;
#endif
V_11 = Malloc ( F_2 () * sizeof( long ) ) ;
for ( V_1 = 0 ; V_1 < F_2 () ; V_1 ++ )
{
V_11 [ V_1 ] = 0 ;
#ifdef F_9
F_10 ( & ( V_2 [ V_1 ] ) , V_12 , NULL ) ;
#else
F_11 ( & ( V_2 [ V_1 ] ) , V_12 , NULL ) ;
#endif
}
F_12 ( ( unsigned long ( * ) () ) V_13 ) ;
F_4 ( ( void ( * ) () ) V_14 ) ;
}
void F_5 ( void )
{
int V_1 ;
F_4 ( NULL ) ;
for ( V_1 = 0 ; V_1 < F_2 () ; V_1 ++ )
{
#ifdef F_9
F_13 ( & ( V_2 [ V_1 ] ) ) ;
#else
F_14 ( & ( V_2 [ V_1 ] ) ) ;
#endif
}
Free ( V_2 ) ;
Free ( V_11 ) ;
}
void V_14 ( int V_5 , int type , char * V_6 , int line )
{
#if 0
fprintf(stderr,"thread=%4d mode=%s lock=%s %s:%d\n",
CRYPTO_thread_id(),
(mode&CRYPTO_LOCK)?"l":"u",
(type&CRYPTO_READ)?"r":"w",file,line);
#endif
#if 0
if (CRYPTO_LOCK_SSL_CERT == type)
fprintf(stderr,"(t,m,f,l) %ld %d %s %d\n",
CRYPTO_thread_id(),
mode,file,line);
#endif
if ( V_5 & V_7 )
{
#ifdef F_9
F_15 ( & ( V_2 [ type ] ) ) ;
#else
if ( V_5 & V_15 )
F_16 ( & ( V_2 [ type ] ) ) ;
else
F_17 ( & ( V_2 [ type ] ) ) ;
#endif
V_11 [ type ] ++ ;
}
else
{
#ifdef F_9
F_18 ( & ( V_2 [ type ] ) ) ;
#else
F_19 ( & ( V_2 [ type ] ) ) ;
#endif
}
}
unsigned long V_13 ( void )
{
unsigned long V_16 ;
V_16 = ( unsigned long ) F_20 () ;
return ( V_16 ) ;
}
void F_1 ( void )
{
int V_1 ;
char V_17 [ 20 ] ;
strcpy ( V_17 , L_1 ) ;
F_21 ( V_17 ) ;
F_22 ( V_18 ) ;
F_22 ( V_19 ) ;
F_22 ( V_20 , 100 ) ;
F_22 ( V_21 , V_22 ) ;
V_23 = F_23 ( V_17 ) ;
F_24 ( V_17 ) ;
V_2 = Malloc ( F_2 () * sizeof( V_24 * ) ) ;
for ( V_1 = 0 ; V_1 < F_2 () ; V_1 ++ )
{
V_2 [ V_1 ] = F_25 ( V_23 , 1 ) ;
}
F_12 ( ( unsigned long ( * ) () ) V_25 ) ;
F_4 ( ( void ( * ) () ) V_26 ) ;
}
void F_5 ( void )
{
int V_1 ;
F_4 ( NULL ) ;
for ( V_1 = 0 ; V_1 < F_2 () ; V_1 ++ )
{
char V_27 [ 10 ] ;
sprintf ( V_27 , L_2 , V_1 ) ;
F_26 ( V_2 [ V_1 ] , stdout , V_27 ) ;
F_27 ( V_2 [ V_1 ] , V_23 ) ;
}
Free ( V_2 ) ;
}
void V_26 ( int V_5 , int type , char * V_6 , int line )
{
if ( V_5 & V_7 )
{
F_28 ( V_2 [ type ] ) ;
}
else
{
F_29 ( V_2 [ type ] ) ;
}
}
unsigned long V_25 ( void )
{
unsigned long V_16 ;
V_16 = ( unsigned long ) F_30 () ;
return ( V_16 ) ;
}
void F_1 ( void )
{
int V_1 ;
V_2 = Malloc ( F_2 () * sizeof( V_28 ) ) ;
V_11 = Malloc ( F_2 () * sizeof( long ) ) ;
for ( V_1 = 0 ; V_1 < F_2 () ; V_1 ++ )
{
V_11 [ V_1 ] = 0 ;
F_31 ( & ( V_2 [ V_1 ] ) , NULL ) ;
}
F_12 ( ( unsigned long ( * ) () ) V_29 ) ;
F_4 ( ( void ( * ) () ) V_30 ) ;
}
void F_32 ( void )
{
int V_1 ;
F_4 ( NULL ) ;
for ( V_1 = 0 ; V_1 < F_2 () ; V_1 ++ )
{
F_33 ( & ( V_2 [ V_1 ] ) ) ;
}
Free ( V_2 ) ;
Free ( V_11 ) ;
}
void V_30 ( int V_5 , int type , char * V_6 ,
int line )
{
#if 0
fprintf(stderr,"thread=%4d mode=%s lock=%s %s:%d\n",
CRYPTO_thread_id(),
(mode&CRYPTO_LOCK)?"l":"u",
(type&CRYPTO_READ)?"r":"w",file,line);
#endif
#if 0
if (CRYPTO_LOCK_SSL_CERT == type)
fprintf(stderr,"(t,m,f,l) %ld %d %s %d\n",
CRYPTO_thread_id(),
mode,file,line);
#endif
if ( V_5 & V_7 )
{
F_34 ( & ( V_2 [ type ] ) ) ;
V_11 [ type ] ++ ;
}
else
{
F_35 ( & ( V_2 [ type ] ) ) ;
}
}
unsigned long V_29 ( void )
{
unsigned long V_16 ;
V_16 = ( unsigned long ) F_36 () ;
return ( V_16 ) ;
}
