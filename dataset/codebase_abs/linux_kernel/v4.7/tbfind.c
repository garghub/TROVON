T_1
F_1 ( char * V_1 ,
char * V_2 , char * V_3 , T_2 * V_4 )
{
T_1 V_5 ;
struct V_6 V_7 ;
T_2 V_8 ;
F_2 ( V_9 ) ;
if ( ! F_3 ( V_1 ) ) {
F_4 ( V_10 ) ;
}
if ( ( strlen ( V_2 ) > V_11 ) ||
( strlen ( V_3 ) > V_12 ) ) {
F_4 ( V_13 ) ;
}
memset ( & V_7 , 0 , sizeof( struct V_6 ) ) ;
F_5 ( V_7 . V_1 , V_1 ) ;
strncpy ( V_7 . V_2 , V_2 , V_11 ) ;
strncpy ( V_7 . V_3 , V_3 , V_12 ) ;
for ( V_8 = 0 ; V_8 < V_14 . V_15 ; ++ V_8 ) {
if ( memcmp ( & ( V_14 . V_16 [ V_8 ] . V_1 ) ,
V_7 . V_1 , V_17 ) ) {
continue;
}
if ( ! V_14 . V_16 [ V_8 ] . V_18 ) {
V_5 =
F_6 ( & V_14 .
V_16 [ V_8 ] ) ;
if ( F_7 ( V_5 ) ) {
F_4 ( V_5 ) ;
}
if ( ! V_14 . V_16 [ V_8 ] . V_18 ) {
continue;
}
}
if ( ! memcmp
( V_14 . V_16 [ V_8 ] . V_18 -> V_1 ,
V_7 . V_1 , V_17 ) && ( ! V_2 [ 0 ]
||
! memcmp
( V_14 .
V_16 [ V_8 ] . V_18 ->
V_2 ,
V_7 . V_2 ,
V_11 ) )
&& ( ! V_3 [ 0 ]
|| ! memcmp ( V_14 . V_16 [ V_8 ] . V_18 ->
V_3 , V_7 . V_3 ,
V_12 ) ) ) {
* V_4 = V_8 ;
F_8 ( ( V_19 ,
L_1 ,
V_7 . V_1 ) ) ;
F_4 ( V_20 ) ;
}
}
F_4 ( V_21 ) ;
}
