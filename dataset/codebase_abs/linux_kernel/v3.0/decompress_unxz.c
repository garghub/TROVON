static bool F_1 ( const void * V_1 , const void * V_2 , T_1 V_3 )
{
const T_2 * V_4 = V_1 ;
const T_2 * V_5 = V_2 ;
T_1 V_6 ;
for ( V_6 = 0 ; V_6 < V_3 ; ++ V_6 )
if ( V_4 [ V_6 ] != V_5 [ V_6 ] )
return false ;
return true ;
}
static void F_2 ( void * V_7 , T_1 V_3 )
{
T_2 * V_2 = V_7 ;
T_2 * V_8 = V_2 + V_3 ;
while ( V_2 != V_8 )
* V_2 ++ = '\0' ;
}
void * memmove ( void * V_9 , const void * V_10 , T_1 V_3 )
{
T_2 * V_11 = V_9 ;
const T_2 * V_12 = V_10 ;
T_1 V_6 ;
if ( V_11 < V_12 ) {
for ( V_6 = 0 ; V_6 < V_3 ; ++ V_6 )
V_11 [ V_6 ] = V_12 [ V_6 ] ;
} else if ( V_11 > V_12 ) {
V_6 = V_3 ;
while ( V_6 -- > 0 )
V_11 [ V_6 ] = V_12 [ V_6 ] ;
}
return V_9 ;
}
STATIC int T_3 F_3 ( unsigned char * V_13 , int V_14 ,
int (* F_4)( void * V_9 , unsigned int V_3 ) ,
int (* F_5)( void * V_10 , unsigned int V_3 ) ,
unsigned char * V_15 , int * V_16 ,
void (* error)( char * V_4 ) )
{
struct V_17 V_2 ;
struct V_18 * V_12 ;
enum V_19 V_20 ;
bool V_21 = false ;
#if V_22
F_6 () ;
#endif
if ( V_16 != NULL )
* V_16 = 0 ;
if ( F_4 == NULL && F_5 == NULL )
V_12 = F_7 ( V_23 , 0 ) ;
else
V_12 = F_7 ( V_24 , ( V_25 ) - 1 ) ;
if ( V_12 == NULL )
goto V_26;
if ( F_5 == NULL ) {
V_2 . V_15 = V_15 ;
V_2 . V_27 = ( T_1 ) - 1 ;
} else {
V_2 . V_27 = V_28 ;
V_2 . V_15 = malloc ( V_28 ) ;
if ( V_2 . V_15 == NULL )
goto V_29;
}
if ( V_13 == NULL ) {
V_21 = true ;
V_13 = malloc ( V_28 ) ;
if ( V_13 == NULL )
goto V_30;
}
V_2 . V_13 = V_13 ;
V_2 . V_31 = 0 ;
V_2 . V_14 = V_14 ;
V_2 . V_32 = 0 ;
if ( F_4 == NULL && F_5 == NULL ) {
V_20 = F_8 ( V_12 , & V_2 ) ;
} else {
do {
if ( V_2 . V_31 == V_2 . V_14 && F_4 != NULL ) {
if ( V_16 != NULL )
* V_16 += V_2 . V_31 ;
V_2 . V_31 = 0 ;
V_14 = F_4 ( V_13 , V_28 ) ;
if ( V_14 < 0 ) {
V_20 = V_33 ;
break;
}
V_2 . V_14 = V_14 ;
}
V_20 = F_8 ( V_12 , & V_2 ) ;
if ( F_5 != NULL && ( V_2 . V_32 == V_2 . V_27
|| ( V_20 != V_34 && V_2 . V_32 > 0 ) ) ) {
if ( F_5 ( V_2 . V_15 , V_2 . V_32 ) != ( int ) V_2 . V_32 )
V_20 = V_33 ;
V_2 . V_32 = 0 ;
}
} while ( V_20 == V_34 );
if ( V_21 )
free ( V_13 ) ;
if ( F_5 != NULL )
free ( V_2 . V_15 ) ;
}
if ( V_16 != NULL )
* V_16 += V_2 . V_31 ;
F_9 ( V_12 ) ;
switch ( V_20 ) {
case V_35 :
return 0 ;
case V_36 :
error ( L_1 ) ;
break;
case V_37 :
error ( L_2 ) ;
break;
case V_38 :
error ( L_3
L_4 ) ;
break;
case V_39 :
case V_33 :
error ( L_5 ) ;
break;
default:
error ( L_6 ) ;
break;
}
return - 1 ;
V_30:
if ( F_5 != NULL )
free ( V_2 . V_15 ) ;
V_29:
F_9 ( V_12 ) ;
V_26:
error ( L_1 ) ;
return - 1 ;
}
