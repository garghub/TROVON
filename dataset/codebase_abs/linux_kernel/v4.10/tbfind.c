T_1
F_1 ( char * V_1 ,
char * V_2 , char * V_3 , T_2 * V_4 )
{
T_1 V_5 = V_6 ;
struct V_7 V_8 ;
T_2 V_9 ;
F_2 ( V_10 ) ;
if ( ! F_3 ( V_1 ) ) {
F_4 ( V_11 ) ;
}
if ( ( strlen ( V_2 ) > V_12 ) ||
( strlen ( V_3 ) > V_13 ) ) {
F_4 ( V_14 ) ;
}
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
F_5 ( V_8 . V_1 , V_1 ) ;
strncpy ( V_8 . V_2 , V_2 , V_12 ) ;
strncpy ( V_8 . V_3 , V_3 , V_13 ) ;
( void ) F_6 ( V_15 ) ;
for ( V_9 = 0 ; V_9 < V_16 . V_17 ; ++ V_9 ) {
if ( memcmp ( & ( V_16 . V_18 [ V_9 ] . V_1 ) ,
V_8 . V_1 , V_19 ) ) {
continue;
}
if ( ! V_16 . V_18 [ V_9 ] . V_20 ) {
V_5 =
F_7 ( & V_16 .
V_18 [ V_9 ] ) ;
if ( F_8 ( V_5 ) ) {
goto V_21;
}
if ( ! V_16 . V_18 [ V_9 ] . V_20 ) {
continue;
}
}
if ( ! memcmp
( V_16 . V_18 [ V_9 ] . V_20 -> V_1 ,
V_8 . V_1 , V_19 ) && ( ! V_2 [ 0 ]
||
! memcmp
( V_16 .
V_18 [ V_9 ] . V_20 ->
V_2 ,
V_8 . V_2 ,
V_12 ) )
&& ( ! V_3 [ 0 ]
|| ! memcmp ( V_16 . V_18 [ V_9 ] . V_20 ->
V_3 , V_8 . V_3 ,
V_13 ) ) ) {
* V_4 = V_9 ;
F_9 ( ( V_22 ,
L_1 ,
V_8 . V_1 ) ) ;
goto V_21;
}
}
V_5 = V_23 ;
V_21:
( void ) F_10 ( V_15 ) ;
F_4 ( V_5 ) ;
}
