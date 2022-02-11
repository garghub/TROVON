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
return V_4 -> V_7 -> V_11 ? ( V_4 -> V_7 -> V_11 ) ( V_4 ) : TRUE ;
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
fputs ( line , V_15 -> V_3 ) ;
putc ( '\n' , V_15 -> V_3 ) ;
}
return ! ferror ( V_15 -> V_3 ) ;
}
static T_2
F_13 ( T_3 * V_4 )
{
T_6 * V_15 = ( T_6 * ) V_4 -> V_16 ;
fputs ( L_2 , V_15 -> V_3 ) ;
return ! ferror ( V_15 -> V_3 ) ;
}
static T_2
F_14 ( T_3 * V_4 )
{
T_6 * V_15 = ( T_6 * ) V_4 -> V_16 ;
T_2 V_14 ;
V_14 = F_4 ( V_15 -> V_1 , V_15 -> V_3 ) ;
F_15 ( V_15 ) ;
F_15 ( V_4 ) ;
return V_14 ;
}
static T_3 *
F_16 ( T_2 V_1 , T_1 * V_3 )
{
T_3 * V_19 ;
T_6 * V_15 ;
V_15 = ( T_6 * ) F_17 ( sizeof *V_15 ) ;
V_15 -> V_1 = V_1 ;
V_15 -> V_3 = V_3 ;
V_19 = ( T_3 * ) F_17 ( sizeof ( T_3 ) ) ;
V_19 -> V_7 = & V_20 ;
V_19 -> V_16 = V_15 ;
return V_19 ;
}
T_3 *
F_18 ( T_2 V_1 , const char * V_2 )
{
T_1 * V_3 ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 == NULL )
return NULL ;
return F_16 ( V_1 , V_3 ) ;
}
T_3 *
F_19 ( T_1 * V_3 )
{
return F_16 ( TRUE , V_3 ) ;
}
static
void F_20 ( char * V_21 , const char * V_22 , int V_23 )
{
int V_24 , V_25 ;
char V_26 ;
if ( V_22 == NULL ) {
V_21 [ 0 ] = '\0' ;
return;
}
for ( V_24 = 0 , V_25 = 0 ; V_25 < V_23 ; V_24 ++ , V_25 ++ ) {
V_26 = V_22 [ V_24 ] ;
switch ( V_26 ) {
case '(' :
case ')' :
case '\\' :
V_21 [ V_25 ] = '\\' ;
V_21 [ ++ V_25 ] = V_26 ;
break;
default:
V_21 [ V_25 ] = V_26 ;
break;
}
if ( V_26 == 0 ) {
break;
}
}
}
static T_2
F_21 ( T_3 * V_4 , T_4 * V_5 , const char * V_6 )
{
T_7 * V_15 = ( T_7 * ) V_4 -> V_16 ;
char V_27 [ V_28 ] ;
F_22 ( V_15 -> V_3 ) ;
fputs ( L_3 , V_15 -> V_3 ) ;
F_20 ( V_27 , V_5 , V_28 ) ;
fprintf ( V_15 -> V_3 , L_4 , V_27 , V_6 ) ;
fputs ( L_5 , V_15 -> V_3 ) ;
return ! ferror ( V_15 -> V_3 ) ;
}
static T_2
F_23 ( T_3 * V_4 , int V_8 , const char * line )
{
T_7 * V_15 = ( T_7 * ) V_4 -> V_16 ;
char V_27 [ V_28 ] ;
F_20 ( V_27 , line , V_28 ) ;
fprintf ( V_15 -> V_3 , L_6 , V_8 , V_27 ) ;
return ! ferror ( V_15 -> V_3 ) ;
}
static T_2
F_24 ( T_3 * V_4 , const T_4 * V_9 , const T_4 * V_10 )
{
T_7 * V_15 = ( T_7 * ) V_4 -> V_16 ;
char V_27 [ V_28 ] ;
F_20 ( V_27 , V_10 , V_28 ) ;
fprintf ( V_15 -> V_3 , L_7 , V_9 ,
V_27 ) ;
fputs ( L_8 ,
V_15 -> V_3 ) ;
fputs ( L_9 ,
V_15 -> V_3 ) ;
fprintf ( V_15 -> V_3 , L_10 , V_9 ) ;
return ! ferror ( V_15 -> V_3 ) ;
}
static T_2
F_25 ( T_3 * V_4 )
{
T_7 * V_15 = ( T_7 * ) V_4 -> V_16 ;
fputs ( L_11 , V_15 -> V_3 ) ;
return ! ferror ( V_15 -> V_3 ) ;
}
static T_2
F_26 ( T_3 * V_4 )
{
T_7 * V_15 = ( T_7 * ) V_4 -> V_16 ;
F_27 ( V_15 -> V_3 ) ;
return ! ferror ( V_15 -> V_3 ) ;
}
static T_2
F_28 ( T_3 * V_4 )
{
T_7 * V_15 = ( T_7 * ) V_4 -> V_16 ;
T_2 V_14 ;
V_14 = F_4 ( V_15 -> V_1 , V_15 -> V_3 ) ;
F_15 ( V_15 ) ;
F_15 ( V_4 ) ;
return V_14 ;
}
static T_3 *
F_29 ( T_2 V_1 , T_1 * V_3 )
{
T_3 * V_19 ;
T_7 * V_15 ;
V_15 = ( T_7 * ) F_17 ( sizeof *V_15 ) ;
V_15 -> V_1 = V_1 ;
V_15 -> V_3 = V_3 ;
V_19 = ( T_3 * ) F_17 ( sizeof ( T_3 ) ) ;
V_19 -> V_7 = & V_29 ;
V_19 -> V_16 = V_15 ;
return V_19 ;
}
T_3 *
F_30 ( T_2 V_1 , const char * V_2 )
{
T_1 * V_3 ;
V_3 = F_1 ( V_1 , V_2 ) ;
if ( V_3 == NULL )
return NULL ;
return F_29 ( V_1 , V_3 ) ;
}
T_3 *
F_31 ( T_1 * V_3 )
{
return F_29 ( TRUE , V_3 ) ;
}
