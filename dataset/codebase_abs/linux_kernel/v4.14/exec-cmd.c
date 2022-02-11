void F_1 ( const char * V_1 , const char * V_2 ,
const char * V_3 , const char * V_4 )
{
V_5 . V_1 = V_1 ;
V_5 . V_2 = V_2 ;
V_5 . V_3 = V_3 ;
V_5 . V_4 = V_4 ;
}
static int F_2 ( const char * V_6 )
{
return V_6 [ 0 ] == '/' ;
}
static const char * F_3 ( void )
{
static char V_7 [ V_8 + 1 ] ;
char * V_9 ;
struct V_10 V_11 , V_12 ;
if ( F_4 ( V_7 , V_8 ) == NULL )
return NULL ;
V_9 = getenv ( L_1 ) ;
if ( V_9 && strcmp ( V_9 , V_7 ) ) {
V_10 ( V_7 , & V_11 ) ;
if ( ! V_10 ( V_9 , & V_12 ) &&
V_12 . V_13 == V_11 . V_13 &&
V_12 . V_14 == V_11 . V_14 ) {
F_5 ( V_7 , V_9 , V_8 ) ;
}
}
return V_7 ;
}
static const char * F_6 ( const char * V_6 )
{
static char V_15 [ V_8 + 1 ] ;
if ( F_2 ( V_6 ) ) {
if ( F_5 ( V_15 , V_6 , V_8 ) >= V_8 )
F_7 ( L_2 , 60 , V_6 ) ;
} else {
const char * V_7 = F_3 () ;
if ( ! V_7 )
F_7 ( L_3 ) ;
if ( snprintf ( V_15 , V_8 , L_4 , V_7 , V_6 ) >= V_8 )
F_7 ( L_2 , 60 , V_6 ) ;
}
return V_15 ;
}
char * F_8 ( const char * V_6 )
{
char * V_15 = NULL ;
if ( F_2 ( V_6 ) )
return F_9 ( V_6 ) ;
F_10 ( & V_15 , L_4 , V_5 . V_2 , V_6 ) ;
return V_15 ;
}
const char * F_11 ( const char * V_16 )
{
const char * V_17 ;
if ( ! V_16 || ! * V_16 )
return NULL ;
V_17 = V_16 + strlen ( V_16 ) ;
while ( V_16 <= V_17 && ! F_12 ( * V_17 ) )
V_17 -- ;
if ( V_17 >= V_16 ) {
V_18 = F_13 ( V_16 , V_17 - V_16 ) ;
return V_18 ? V_17 + 1 : NULL ;
}
return V_16 ;
}
void F_14 ( const char * V_3 )
{
V_19 = V_3 ;
F_15 ( V_5 . V_4 , V_3 , 1 ) ;
}
char * F_16 ( void )
{
char * V_20 ;
if ( V_19 )
return F_9 ( V_19 ) ;
V_20 = getenv ( V_5 . V_4 ) ;
if ( V_20 && * V_20 )
return F_9 ( V_20 ) ;
return F_8 ( V_5 . V_3 ) ;
}
static void F_17 ( char * * V_21 , const char * V_6 )
{
if ( V_6 && * V_6 ) {
if ( F_2 ( V_6 ) )
F_18 ( V_21 , V_6 ) ;
else
F_18 ( V_21 , F_6 ( V_6 ) ) ;
F_18 ( V_21 , L_5 ) ;
}
}
void F_19 ( void )
{
const char * V_22 = getenv ( L_6 ) ;
char * V_23 = NULL ;
char * V_24 = F_16 () ;
F_17 ( & V_23 , V_24 ) ;
F_17 ( & V_23 , V_18 ) ;
free ( V_24 ) ;
if ( V_22 )
F_18 ( & V_23 , V_22 ) ;
else
F_18 ( & V_23 , L_7 ) ;
F_15 ( L_6 , V_23 , 1 ) ;
free ( V_23 ) ;
}
static const char * * F_20 ( const char * * V_25 )
{
int V_26 ;
const char * * V_27 ;
for ( V_26 = 0 ; V_25 [ V_26 ] ; V_26 ++ )
;
V_27 = malloc ( sizeof( * V_27 ) * ( V_26 + 2 ) ) ;
V_27 [ 0 ] = V_5 . V_1 ;
for ( V_26 = 0 ; V_25 [ V_26 ] ; V_26 ++ )
V_27 [ V_26 + 1 ] = V_25 [ V_26 ] ;
V_27 [ V_26 + 1 ] = NULL ;
return V_27 ;
}
int F_21 ( const char * * V_25 ) {
const char * * V_27 = F_20 ( V_25 ) ;
F_22 ( V_5 . V_1 , ( char * * ) V_27 ) ;
free ( V_27 ) ;
return - 1 ;
}
int F_23 ( const char * V_28 , ... )
{
int V_26 ;
const char * V_25 [ V_29 + 1 ] ;
const char * V_30 ;
T_1 V_31 ;
va_start ( V_31 , V_28 ) ;
V_25 [ 0 ] = V_28 ;
V_26 = 1 ;
while ( V_26 < V_29 ) {
V_30 = V_25 [ V_26 ++ ] = va_arg ( V_31 , char * ) ;
if ( ! V_30 )
break;
}
va_end ( V_31 ) ;
if ( V_29 <= V_26 ) {
fprintf ( V_32 , L_8 , V_28 ) ;
return - 1 ;
}
V_25 [ V_26 ] = NULL ;
return F_21 ( V_25 ) ;
}
