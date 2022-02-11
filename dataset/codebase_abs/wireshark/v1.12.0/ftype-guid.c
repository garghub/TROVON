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
if ( ! isxdigit ( ( V_10 ) V_4 [ V_5 ] ) )
return FALSE ;
} else {
if ( V_4 [ V_5 ] != V_9 [ V_5 ] )
return FALSE ;
}
}
V_7 = V_4 ;
strncpy ( V_8 , V_7 , 8 ) ;
V_8 [ 8 ] = '\0' ;
V_3 -> V_11 = ( V_12 ) strtoul ( V_8 , NULL , 16 ) ;
V_7 += 9 ;
strncpy ( V_8 , V_7 , 4 ) ;
V_8 [ 4 ] = '\0' ;
V_3 -> V_13 = ( V_14 ) strtoul ( V_8 , NULL , 16 ) ;
V_7 += 5 ;
strncpy ( V_8 , V_7 , 4 ) ;
V_8 [ 4 ] = '\0' ;
V_3 -> V_15 = ( V_14 ) strtoul ( V_8 , NULL , 16 ) ;
V_7 += 5 ;
for ( V_5 = 0 ; V_5 < sizeof( V_3 -> V_16 ) ; V_5 ++ ) {
if ( * V_7 == '-' ) V_7 ++ ;
V_8 [ 0 ] = * ( V_7 ++ ) ;
V_8 [ 1 ] = * ( V_7 ++ ) ;
V_8 [ 2 ] = '\0' ;
V_3 -> V_16 [ V_5 ] = ( V_17 ) strtoul ( V_8 , NULL , 16 ) ;
}
return TRUE ;
}
static T_4
F_4 ( T_1 * V_1 , const char * V_4 , T_4 T_6 V_18 , T_7 V_19 )
{
T_2 V_3 ;
if ( ! F_3 ( V_4 , & V_3 ) ) {
V_19 ( L_2 , V_4 ) ;
return FALSE ;
}
V_1 -> V_2 . V_3 = V_3 ;
return TRUE ;
}
static int
F_5 ( T_1 * V_1 V_18 , T_8 T_9 V_18 )
{
return V_20 ;
}
static void
F_6 ( T_1 * V_1 , T_8 T_9 V_18 , char * V_21 )
{
F_7 ( & V_1 -> V_2 . V_3 , V_21 , V_20 ) ;
}
static T_4
F_8 ( const T_1 * V_22 , const T_1 * V_23 )
{
return memcmp ( & V_22 -> V_2 . V_3 , & V_23 -> V_2 . V_3 , sizeof( T_2 ) ) == 0 ;
}
static T_4
F_9 ( const T_1 * V_22 , const T_1 * V_23 )
{
return memcmp ( & V_22 -> V_2 . V_3 , & V_23 -> V_2 . V_3 , sizeof( T_2 ) ) != 0 ;
}
void
F_10 ( void )
{
static T_10 V_24 = {
V_25 ,
L_3 ,
L_4 ,
V_26 ,
NULL ,
NULL ,
F_4 ,
NULL ,
F_6 ,
F_5 ,
NULL ,
NULL ,
F_1 ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
NULL ,
F_2 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_8 ,
F_9 ,
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
F_11 ( V_25 , & V_24 ) ;
}
