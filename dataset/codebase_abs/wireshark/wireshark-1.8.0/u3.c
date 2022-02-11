T_1 F_1 ( void )
{
return (
#ifdef F_2
V_1
#else
getenv
#endif
( L_1 ) != NULL ) ;
}
void F_3 ( T_2 * V_2 )
{
char * V_3 = NULL ;
char * V_4 = NULL ;
if( ( V_4 =
#ifdef F_2
V_1
#else
getenv
#endif
( L_2 ) ) != NULL ) {
F_4 ( V_2 , L_3 ) ;
F_4 ( V_2 , V_4 ) ;
} else {
F_4 ( V_2 , L_4 ) ;
}
F_4 ( V_2 , L_5 ) ;
if( ( V_3 =
#ifdef F_2
V_1
#else
getenv
#endif
( L_6 ) ) != NULL ) {
F_4 ( V_2 , L_7 ) ;
F_4 ( V_2 , V_3 ) ;
}
}
void F_5 ( void )
{
int V_5 ;
int V_6 ;
char * V_7 ;
int V_8 ;
if( ( V_7 =
#ifdef F_2
V_1
#else
getenv
#endif
( L_1 ) ) != NULL ) {
V_5 = F_6 () ;
V_8 = ( int ) strlen ( V_7 ) + 32 ;
V_9 = F_7 ( V_8 ) ;
F_8 ( V_9 , V_8 , L_8 , V_7 , V_5 ) ;
V_6 = F_9 ( V_9 , V_10 | V_11 | V_12 | V_13 , 0644 ) ;
if( V_6 != - 1 )
F_10 ( V_6 ) ;
else {
F_11 ( V_9 ) ;
V_9 = NULL ;
}
}
}
void F_12 ( void )
{
if( V_9 ) {
F_13 ( V_9 ) ;
F_11 ( V_9 ) ;
V_9 = NULL ;
}
}
char * F_14 ( char * V_14 )
{
return F_15 ( V_14 , V_15 , NULL ) ;
}
char * F_16 ( char * V_14 )
{
return F_15 ( V_14 , NULL , V_15 ) ;
}
static char * F_15 ( char * V_14 , const char * V_16 , const char * V_17 )
{
if( V_18 == ( char * ) - 1 ) {
V_18 =
#ifdef F_2
V_1
#else
getenv
#endif
( L_6 ) ;
}
if( V_17 == NULL )
V_17 = V_18 ;
if( V_16 == NULL )
V_16 = V_18 ;
if( V_19 != NULL ) {
F_11 ( V_19 ) ;
V_19 = NULL ;
}
if( ( V_14 != NULL ) && ( V_18 != NULL ) && ( strncmp ( V_14 , V_16 , strlen ( V_16 ) ) == 0 ) ) {
V_19 = F_17 ( V_17 , V_14 + strlen ( V_16 ) , NULL ) ;
return V_19 ;
}
return V_14 ;
}
