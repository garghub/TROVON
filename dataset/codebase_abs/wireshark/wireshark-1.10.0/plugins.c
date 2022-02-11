static int
F_1 ( void * V_1 , T_1 * V_2 , T_1 * V_3 ,
void (* F_2)( void ) ,
void (* F_3)( void ) ,
void (* F_4)( void ) ,
void (* F_5)( void ) ,
void (* F_6)( void ) )
{
T_2 * V_4 , * V_5 ;
V_5 = V_6 ;
if ( ! V_5 )
{
V_4 = ( T_2 * ) F_7 ( sizeof( T_2 ) ) ;
if ( V_4 == NULL )
return V_7 ;
V_6 = V_4 ;
}
else
{
while ( 1 )
{
if ( ! strcmp ( V_5 -> V_2 , V_2 ) &&
! strcmp ( V_5 -> V_3 , V_3 ) )
{
return V_8 ;
}
if ( V_5 -> V_9 == NULL )
break;
V_5 = V_5 -> V_9 ;
}
V_4 = ( T_2 * ) F_7 ( sizeof( T_2 ) ) ;
if ( V_4 == NULL )
return V_7 ;
V_5 -> V_9 = V_4 ;
}
V_4 -> V_1 = ( V_10 * ) V_1 ;
V_4 -> V_2 = V_2 ;
V_4 -> V_3 = V_3 ;
V_4 -> F_2 = F_2 ;
V_4 -> F_3 = F_3 ;
V_4 -> F_4 = F_4 ;
V_4 -> F_5 = F_5 ;
V_4 -> F_6 = F_6 ;
V_4 -> V_9 = NULL ;
return 0 ;
}
static void
F_8 ( const char * V_11 )
{
#define F_9 1024
T_3 * V_12 ;
T_4 * V_13 ;
const char * V_2 ;
T_1 V_14 [ F_9 ] ;
V_10 * V_1 ;
T_1 * V_3 ;
T_5 V_15 ;
void (* F_2)( void );
void (* F_3)( void );
void (* F_4)( void );
void (* F_5)( void );
void (* F_6)( void );
T_1 * V_16 ;
int V_17 ;
if ( ( V_12 = F_10 ( V_11 , 0 , NULL ) ) != NULL )
{
while ( ( V_13 = F_11 ( V_12 ) ) != NULL )
{
V_2 = F_12 ( V_13 ) ;
V_16 = strrchr ( V_2 , '.' ) ;
if ( V_16 == NULL || strcmp ( V_16 + 1 , V_18 ) != 0 )
continue;
F_13 ( V_14 , F_9 , L_1 V_19 L_1 ,
V_11 , V_2 ) ;
if ( ( V_1 = F_14 ( V_14 , ( V_20 ) 0 ) ) == NULL )
{
F_15 ( L_2 , V_14 ,
F_16 () ) ;
continue;
}
if ( ! F_17 ( V_1 , L_3 , & V_15 ) )
{
F_15 ( L_4 , V_2 ) ;
F_18 ( V_1 ) ;
continue;
}
V_3 = ( char * ) V_15 ;
if ( F_17 ( V_1 , L_5 , & V_15 ) )
{
F_2 = ( void ( * ) ( void ) ) V_15 ;
}
else
{
F_2 = NULL ;
}
if ( F_17 ( V_1 , L_6 , & V_15 ) )
{
F_3 = ( void ( * ) ( void ) ) V_15 ;
}
else
{
F_3 = NULL ;
}
if ( F_17 ( V_1 , L_7 , & V_15 ) )
{
F_4 = ( void ( * ) ( void ) ) V_15 ;
}
else
{
F_4 = NULL ;
}
if ( F_17 ( V_1 , L_8 , & V_15 ) )
{
if ( F_2 != NULL || F_4 != NULL )
{
F_15 ( L_9 ,
V_2 ) ;
F_18 ( V_1 ) ;
continue;
}
F_15 ( L_10 ,
V_2 ) ;
F_18 ( V_1 ) ;
continue;
}
if ( F_17 ( V_1 , L_11 , & V_15 ) )
{
F_5 = ( void ( * ) ( void ) ) V_15 ;
}
else
{
F_5 = NULL ;
}
if ( F_17 ( V_1 , L_12 , & V_15 ) )
{
F_6 = ( void ( * ) ( void ) ) V_15 ;
}
else
{
F_6 = NULL ;
}
if ( F_2 == NULL &&
F_4 == NULL &&
F_5 == NULL &&
F_6 == NULL )
{
F_15 ( L_13
L_14 ,
V_2 ) ;
F_18 ( V_1 ) ;
continue;
}
if ( ( V_17 = F_1 ( V_1 , F_19 ( V_2 ) , V_3 ,
F_2 , F_3 ,
F_4 , F_5 , F_6 ) ) )
{
if ( V_17 == V_8 )
fprintf ( V_21 , L_15
L_16 , V_2 , V_3 ) ;
else
fprintf ( V_21 , L_17
L_18 ,
V_2 , V_3 ) ;
F_18 ( V_1 ) ;
continue;
}
}
F_20 ( V_12 ) ;
}
}
void
F_21 ( void )
{
const char * V_22 ;
const char * V_2 ;
char * V_23 ;
char * V_24 ;
T_3 * V_12 ;
T_4 * V_13 ;
if ( V_6 == NULL )
{
V_22 = F_22 () ;
if ( F_23 () )
{
if ( ( V_12 = F_10 ( V_22 , 0 , NULL ) ) != NULL )
{
while ( ( V_13 = F_11 ( V_12 ) ) != NULL )
{
V_2 = F_12 ( V_13 ) ;
if ( strcmp ( V_2 , L_19 ) == 0 || strcmp ( V_2 , L_20 ) == 0 )
continue;
V_23 = F_24 (
L_1 V_19 L_1 V_19 L_21 ,
V_22 , V_2 ) ;
if ( F_25 ( V_23 ) != V_25 ) {
F_26 ( V_23 ) ;
V_23 = F_24 ( L_1 V_19 L_1 ,
V_22 , V_2 ) ;
}
F_8 ( V_23 ) ;
F_26 ( V_23 ) ;
}
F_20 ( V_12 ) ;
}
}
else
F_8 ( V_22 ) ;
if ( ! F_27 () )
{
V_24 = F_28 () ;
F_8 ( V_24 ) ;
F_26 ( V_24 ) ;
}
}
F_29 () ;
F_30 () ;
}
void
F_31 ( void )
{
T_2 * V_5 ;
for ( V_5 = V_6 ; V_5 != NULL ; V_5 = V_5 -> V_9 )
{
if ( V_5 -> F_2 )
( V_5 -> F_2 ) ( ) ;
}
}
void
F_32 ( void )
{
T_2 * V_5 ;
for ( V_5 = V_6 ; V_5 != NULL ; V_5 = V_5 -> V_9 )
{
if ( V_5 -> F_3 )
( V_5 -> F_3 ) ( ) ;
}
}
void
F_33 ( void )
{
T_2 * V_5 ;
for ( V_5 = V_6 ; V_5 != NULL ; V_5 = V_5 -> V_9 )
{
if ( V_5 -> F_4 )
( V_5 -> F_4 ) ( ) ;
}
}
static void
F_29 ( void )
{
T_2 * V_5 ;
for ( V_5 = V_6 ; V_5 != NULL ; V_5 = V_5 -> V_9 )
{
if ( V_5 -> F_5 )
( V_5 -> F_5 ) ( ) ;
}
}
static void
F_30 ( void )
{
T_2 * V_5 ;
for ( V_5 = V_6 ; V_5 != NULL ; V_5 = V_5 -> V_9 )
{
if ( V_5 -> F_6 )
( V_5 -> F_6 ) ( ) ;
}
}
void
F_34 ( void )
{
#ifdef F_35
T_2 * V_5 ;
const char * V_26 ;
#endif
#ifdef F_36
T_6 * V_27 ;
#endif
#ifdef F_35
for ( V_5 = V_6 ; V_5 != NULL ; V_5 = V_5 -> V_9 )
{
V_26 = L_22 ;
printf ( L_23 , V_5 -> V_2 , V_5 -> V_3 ) ;
if ( V_5 -> F_2 )
{
printf ( L_24 ) ;
V_26 = L_25 ;
}
if ( V_5 -> F_4 )
{
printf ( L_26 , V_26 ) ;
V_26 = L_25 ;
}
if ( V_5 -> F_5 )
{
printf ( L_27 , V_26 ) ;
V_26 = L_25 ;
}
if ( V_5 -> F_6 )
{
printf ( L_28 , V_26 ) ;
}
printf ( L_29 , F_37 ( V_5 -> V_1 ) ) ;
}
#endif
#ifdef F_36
for ( V_27 = V_28 ; V_27 != NULL ; V_27 = V_27 -> V_9 )
{
printf ( L_30 , V_27 -> V_2 , V_27 -> V_3 , V_27 -> V_14 ) ;
}
#endif
}
