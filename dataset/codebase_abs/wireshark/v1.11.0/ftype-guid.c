static void
F_1 ( T_1 * V_1 , T_2 V_2 , T_3 V_3 )
{
F_2 ( ! V_3 ) ;
V_1 -> V_2 . V_4 = * ( V_5 * ) V_2 ;
}
static T_2
F_3 ( T_1 * V_1 )
{
return & ( V_1 -> V_2 . V_4 ) ;
}
static T_3
F_4 ( char * V_6 , V_5 * V_4 )
{
T_4 V_7 , V_8 ;
char * V_9 , V_10 [ 9 ] ;
static const char V_11 [] = L_1 ;
V_8 = strlen ( V_6 ) ;
if ( V_8 != strlen ( V_11 ) )
return FALSE ;
for ( V_7 = 0 ; V_7 < V_8 ; V_7 ++ ) {
if ( V_11 [ V_7 ] == 'X' ) {
if ( ! isxdigit ( ( V_12 ) V_6 [ V_7 ] ) )
return FALSE ;
} else {
if ( V_6 [ V_7 ] != V_11 [ V_7 ] )
return FALSE ;
}
}
V_9 = V_6 ;
strncpy ( V_10 , V_9 , 8 ) ;
V_10 [ 8 ] = '\0' ;
V_4 -> V_13 = ( V_14 ) strtoul ( V_10 , NULL , 16 ) ;
V_9 += 9 ;
strncpy ( V_10 , V_9 , 4 ) ;
V_10 [ 4 ] = '\0' ;
V_4 -> V_15 = ( V_16 ) strtoul ( V_10 , NULL , 16 ) ;
V_9 += 5 ;
strncpy ( V_10 , V_9 , 4 ) ;
V_10 [ 4 ] = '\0' ;
V_4 -> V_17 = ( V_16 ) strtoul ( V_10 , NULL , 16 ) ;
V_9 += 5 ;
for ( V_7 = 0 ; V_7 < sizeof( V_4 -> V_18 ) ; V_7 ++ ) {
if ( * V_9 == '-' ) V_9 ++ ;
V_10 [ 0 ] = * ( V_9 ++ ) ;
V_10 [ 1 ] = * ( V_9 ++ ) ;
V_10 [ 2 ] = '\0' ;
V_4 -> V_18 [ V_7 ] = ( V_19 ) strtoul ( V_10 , NULL , 16 ) ;
}
return TRUE ;
}
static T_3
F_5 ( T_1 * V_1 , char * V_6 , T_3 T_5 V_20 , T_6 V_21 )
{
V_5 V_4 ;
if ( ! F_4 ( V_6 , & V_4 ) ) {
V_21 ( L_2 , V_6 ) ;
return FALSE ;
}
V_1 -> V_2 . V_4 = V_4 ;
return TRUE ;
}
static int
F_6 ( T_1 * V_1 V_20 , T_7 T_8 V_20 )
{
return V_22 ;
}
static void
F_7 ( T_1 * V_1 , T_7 T_8 V_20 , char * V_23 )
{
F_8 ( & V_1 -> V_2 . V_4 , V_23 , V_22 ) ;
}
static T_3
F_9 ( const T_1 * V_24 , const T_1 * V_25 )
{
return memcmp ( & V_24 -> V_2 . V_4 , & V_25 -> V_2 . V_4 , sizeof( V_5 ) ) == 0 ;
}
static T_3
F_10 ( const T_1 * V_24 , const T_1 * V_25 )
{
return memcmp ( & V_24 -> V_2 . V_4 , & V_25 -> V_2 . V_4 , sizeof( V_5 ) ) != 0 ;
}
void
F_11 ( void )
{
static T_9 V_26 = {
V_27 ,
L_3 ,
L_4 ,
V_28 ,
NULL ,
NULL ,
F_5 ,
NULL ,
F_7 ,
F_6 ,
F_1 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_3 ,
NULL ,
NULL ,
NULL ,
NULL ,
F_9 ,
F_10 ,
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
F_12 ( V_27 , & V_26 ) ;
}
