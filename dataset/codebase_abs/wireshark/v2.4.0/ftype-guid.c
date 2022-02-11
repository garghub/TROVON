static void
F_1 ( T_1 * V_1 , const T_2 * V_2 )
{
V_1 -> V_2 . V_3 = * V_2 ;
}
static T_3
F_2 ( T_1 * V_1 )
{
return & ( V_1 -> V_2 . V_3 ) ;
}
static T_4
F_3 ( const char * V_4 , T_2 * V_3 )
{
T_5 V_5 , V_6 ;
const char * V_7 ;
char V_8 [ 9 ] ;
static const char V_9 [] = L_1 ;
V_6 = strlen ( V_4 ) ;
if ( V_6 != strlen ( V_9 ) )
return FALSE ;
for ( V_5 = 0 ; V_5 < V_6 ; V_5 ++ ) {
if ( V_9 [ V_5 ] == 'X' ) {
if ( ! F_4 ( V_4 [ V_5 ] ) )
return FALSE ;
} else {
if ( V_4 [ V_5 ] != V_9 [ V_5 ] )
return FALSE ;
}
}
V_7 = V_4 ;
F_5 ( V_8 , V_7 , 9 ) ;
V_3 -> V_10 = ( V_11 ) strtoul ( V_8 , NULL , 16 ) ;
V_7 += 9 ;
F_5 ( V_8 , V_7 , 5 ) ;
V_3 -> V_12 = ( V_13 ) strtoul ( V_8 , NULL , 16 ) ;
V_7 += 5 ;
F_5 ( V_8 , V_7 , 5 ) ;
V_3 -> V_14 = ( V_13 ) strtoul ( V_8 , NULL , 16 ) ;
V_7 += 5 ;
for ( V_5 = 0 ; V_5 < sizeof( V_3 -> V_15 ) ; V_5 ++ ) {
if ( * V_7 == '-' ) V_7 ++ ;
V_8 [ 0 ] = * ( V_7 ++ ) ;
V_8 [ 1 ] = * ( V_7 ++ ) ;
V_8 [ 2 ] = '\0' ;
V_3 -> V_15 [ V_5 ] = ( V_16 ) strtoul ( V_8 , NULL , 16 ) ;
}
return TRUE ;
}
static T_4
F_6 ( T_1 * V_1 , const char * V_4 , T_4 T_6 V_17 , T_7 * * V_18 )
{
T_2 V_3 ;
if ( ! F_3 ( V_4 , & V_3 ) ) {
if ( V_18 != NULL )
* V_18 = F_7 ( L_2 , V_4 ) ;
return FALSE ;
}
V_1 -> V_2 . V_3 = V_3 ;
return TRUE ;
}
static int
F_8 ( T_1 * V_1 V_17 , T_8 T_9 V_17 , int T_10 V_17 )
{
return V_19 ;
}
static void
F_9 ( T_1 * V_1 , T_8 T_9 V_17 , int T_10 V_17 , char * V_20 , unsigned int V_21 )
{
F_10 ( & V_1 -> V_2 . V_3 , V_20 , V_21 ) ;
}
static T_4
F_11 ( const T_1 * V_22 , const T_1 * V_23 )
{
return memcmp ( & V_22 -> V_2 . V_3 , & V_23 -> V_2 . V_3 , sizeof( T_2 ) ) == 0 ;
}
static T_4
F_12 ( const T_1 * V_22 , const T_1 * V_23 )
{
return memcmp ( & V_22 -> V_2 . V_3 , & V_23 -> V_2 . V_3 , sizeof( T_2 ) ) != 0 ;
}
void
F_13 ( void )
{
static T_11 V_24 = {
V_25 ,
L_3 ,
L_4 ,
V_26 ,
NULL ,
NULL ,
F_6 ,
NULL ,
F_9 ,
F_8 ,
{ . V_27 = F_1 } ,
{ . V_28 = F_2 } ,
F_11 ,
F_12 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
} ;
F_14 ( V_25 , & V_24 ) ;
}
