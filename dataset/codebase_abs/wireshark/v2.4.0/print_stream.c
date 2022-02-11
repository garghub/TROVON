static T_1 *
F_1 ( T_2 V_1 , const char * V_2 )
{
T_1 * V_3 ;
if ( V_1 )
V_3 = F_2 ( V_2 , L_1 ) ;
else
V_3 = F_3 ( V_2 , L_1 ) ;
return V_3 ;
}
static T_2
F_4 ( T_2 V_1 , T_1 * V_3 )
{
if ( V_1 )
return ( fclose ( V_3 ) == 0 ) ;
else
return ( F_5 ( V_3 ) == 0 ) ;
}
T_2
F_6 ( T_3 * V_4 , T_4 * V_5 , const char * V_6 )
{
return V_4 -> V_7 -> F_6 ? ( V_4 -> V_7 -> F_6 ) ( V_4 , V_5 , V_6 ) : TRUE ;
}
T_2
F_7 ( T_3 * V_4 , int V_8 , const char * line )
{
return ( V_4 -> V_7 -> F_7 ) ( V_4 , V_8 , line ) ;
}
T_2
F_8 ( T_3 * V_4 , const T_4 * V_9 , const T_4 * V_10 )
{
return V_4 -> V_7 -> F_8 ? ( V_4 -> V_7 -> F_8 ) ( V_4 , V_9 , V_10 ) : TRUE ;
}
T_2
F_9 ( T_3 * V_4 )
{
return V_4 -> V_7 -> F_9 ? ( V_4 -> V_7 -> F_9 ) ( V_4 ) : TRUE ;
}
T_2
F_10 ( T_3 * V_4 )
{
return V_4 -> V_7 -> F_10 ? ( V_4 -> V_7 -> F_10 ) ( V_4 ) : TRUE ;
}
T_2
F_11 ( T_3 * V_4 )
{
return ( V_4 && V_4 -> V_7 && V_4 -> V_7 -> V_11 ) ? ( V_4 -> V_7 -> V_11 ) ( V_4 ) : TRUE ;
}
static T_2
F_12 ( T_3 * V_4 , int V_8 , const char * line )
{
static char V_12 [ V_13 ] ;
T_5 V_14 ;
T_6 * V_15 = ( T_6 * ) V_4 -> V_16 ;
unsigned int V_17 ;
if ( ! V_12 [ 0 ] ) {
int V_18 ;
for ( V_18 = 0 ; V_18 < V_13 ; V_18 ++ )
V_12 [ V_18 ] = ' ' ;
}
V_17 = V_8 * 4 ;
if ( V_17 > V_13 )
V_17 = V_13 ;
V_14 = fwrite ( V_12 , 1 , V_17 , V_15 -> V_3 ) ;
if ( V_14 == V_17 ) {
T_4 * V_19 = NULL ;
if ( V_4 -> V_20 && V_4 -> V_21 ) {
V_19 = F_13 ( line , - 1 , V_4 -> V_21 , L_2 , L_3 , NULL , NULL , NULL ) ;
}
if ( V_19 ) {
#ifdef F_14
T_7 V_22 = ( T_7 ) wcslen ( ( V_23 * ) V_19 ) ;
F_15 ( ( V_24 ) F_16 ( F_17 ( V_15 -> V_3 ) ) , V_19 , V_22 , & V_22 , NULL ) ;
#else
fputs ( V_19 , V_15 -> V_3 ) ;
#endif
F_18 ( V_19 ) ;
} else {
fputs ( line , V_15 -> V_3 ) ;
}
putc ( '\n' , V_15 -> V_3 ) ;
}
return ! ferror ( V_15 -> V_3 ) ;
}
static T_2
F_19 ( T_3 * V_4 )
{
T_6 * V_15 = ( T_6 * ) V_4 -> V_16 ;
fputs ( L_4 , V_15 -> V_3 ) ;
return ! ferror ( V_15 -> V_3 ) ;
}
static T_2
F_20 ( T_3 * V_4 )
{
T_6 * V_15 = ( T_6 * ) V_4 -> V_16 ;
T_2 V_14 ;
V_14 = F_4 ( V_15 -> V_1 , V_15 -> V_3 ) ;
F_18 ( V_15 ) ;
F_18 ( V_4 ) ;
return V_14 ;
}
static T_3 *
F_21 ( T_2 V_1 , T_1 * V_3 )
{
T_3 * V_25 ;
T_6 * V_15 ;
#ifndef F_14
const T_4 * V_26 ;
T_2 V_27 ;
#endif
V_15 = ( T_6 * ) F_22 ( sizeof *V_15 ) ;
V_15 -> V_1 = V_1 ;
V_15 -> V_3 = V_3 ;
V_25 = ( T_3 * ) F_23 ( sizeof ( T_3 ) ) ;
V_25 -> V_7 = & V_28 ;
V_25 -> V_20 = F_24 ( F_25 ( V_3 ) ) ;
V_25 -> V_16 = V_15 ;
#ifndef F_14
V_27 = F_26 ( & V_26 ) ;
if ( ! V_27 ) {
V_25 -> V_21 = V_26 ;
}
#else
V_25 -> V_21 = L_5 ;
#endif
return V_25 ;
}
T_3 *
F_27 ( T_2 V_1 , const char * V_2 )
{
T_1 * V_3 ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 == NULL )
return NULL ;
return F_21 ( V_1 , V_3 ) ;
}
T_3 *
F_28 ( T_1 * V_3 )
{
return F_21 ( TRUE , V_3 ) ;
}
static
void F_29 ( char * V_29 , const char * V_30 , int V_31 )
{
int V_32 , V_33 ;
char V_34 ;
if ( V_30 == NULL ) {
V_29 [ 0 ] = '\0' ;
return;
}
for ( V_32 = 0 , V_33 = 0 ; V_33 < V_31 ; V_32 ++ , V_33 ++ ) {
V_34 = V_30 [ V_32 ] ;
switch ( V_34 ) {
case '(' :
case ')' :
case '\\' :
V_29 [ V_33 ] = '\\' ;
V_29 [ ++ V_33 ] = V_34 ;
break;
default:
V_29 [ V_33 ] = V_34 ;
break;
}
if ( V_34 == 0 ) {
break;
}
}
}
static T_2
F_30 ( T_3 * V_4 , T_4 * V_5 , const char * V_6 )
{
T_8 * V_15 = ( T_8 * ) V_4 -> V_16 ;
char V_35 [ V_36 ] ;
F_31 ( V_15 -> V_3 ) ;
fputs ( L_6 , V_15 -> V_3 ) ;
F_29 ( V_35 , V_5 , V_36 ) ;
fprintf ( V_15 -> V_3 , L_7 , V_35 , V_6 ) ;
fputs ( L_8 , V_15 -> V_3 ) ;
return ! ferror ( V_15 -> V_3 ) ;
}
static T_2
F_32 ( T_3 * V_4 , int V_8 , const char * line )
{
T_8 * V_15 = ( T_8 * ) V_4 -> V_16 ;
char V_35 [ V_36 ] ;
F_29 ( V_35 , line , V_36 ) ;
fprintf ( V_15 -> V_3 , L_9 , V_8 , V_35 ) ;
return ! ferror ( V_15 -> V_3 ) ;
}
static T_2
F_33 ( T_3 * V_4 , const T_4 * V_9 , const T_4 * V_10 )
{
T_8 * V_15 = ( T_8 * ) V_4 -> V_16 ;
char V_35 [ V_36 ] ;
F_29 ( V_35 , V_10 , V_36 ) ;
fprintf ( V_15 -> V_3 , L_10 , V_9 ,
V_35 ) ;
fputs ( L_11 ,
V_15 -> V_3 ) ;
fputs ( L_12 ,
V_15 -> V_3 ) ;
fprintf ( V_15 -> V_3 , L_13 , V_9 ) ;
return ! ferror ( V_15 -> V_3 ) ;
}
static T_2
F_34 ( T_3 * V_4 )
{
T_8 * V_15 = ( T_8 * ) V_4 -> V_16 ;
fputs ( L_14 , V_15 -> V_3 ) ;
return ! ferror ( V_15 -> V_3 ) ;
}
static T_2
F_35 ( T_3 * V_4 )
{
T_8 * V_15 = ( T_8 * ) V_4 -> V_16 ;
F_36 ( V_15 -> V_3 ) ;
return ! ferror ( V_15 -> V_3 ) ;
}
static T_2
F_37 ( T_3 * V_4 )
{
T_8 * V_15 = ( T_8 * ) V_4 -> V_16 ;
T_2 V_14 ;
V_14 = F_4 ( V_15 -> V_1 , V_15 -> V_3 ) ;
F_18 ( V_15 ) ;
F_18 ( V_4 ) ;
return V_14 ;
}
static T_3 *
F_38 ( T_2 V_1 , T_1 * V_3 )
{
T_3 * V_25 ;
T_8 * V_15 ;
V_15 = ( T_8 * ) F_22 ( sizeof *V_15 ) ;
V_15 -> V_1 = V_1 ;
V_15 -> V_3 = V_3 ;
V_25 = ( T_3 * ) F_22 ( sizeof ( T_3 ) ) ;
V_25 -> V_7 = & V_37 ;
V_25 -> V_16 = V_15 ;
return V_25 ;
}
T_3 *
F_39 ( T_2 V_1 , const char * V_2 )
{
T_1 * V_3 ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 == NULL )
return NULL ;
return F_38 ( V_1 , V_3 ) ;
}
T_3 *
F_40 ( T_1 * V_3 )
{
return F_38 ( TRUE , V_3 ) ;
}
