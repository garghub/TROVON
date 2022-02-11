T_1
F_1 ( char * V_1 ,
char * V_2 , char * V_3 , T_2 * V_4 )
{
T_2 V_5 ;
T_1 V_6 ;
struct V_7 V_8 ;
F_2 ( V_9 ) ;
memset ( & V_8 , 0 , sizeof( struct V_7 ) ) ;
F_3 ( V_8 . V_1 , V_1 ) ;
strncpy ( V_8 . V_2 , V_2 , V_10 ) ;
strncpy ( V_8 . V_3 , V_3 , V_11 ) ;
for ( V_5 = 0 ; V_5 < V_12 . V_13 ; ++ V_5 ) {
if ( memcmp ( & ( V_12 . V_14 [ V_5 ] . V_1 ) ,
V_8 . V_1 , V_15 ) ) {
continue;
}
if ( ! V_12 . V_14 [ V_5 ] . V_16 ) {
V_6 =
F_4 ( & V_12 .
V_14 [ V_5 ] ) ;
if ( F_5 ( V_6 ) ) {
F_6 ( V_6 ) ;
}
if ( ! V_12 . V_14 [ V_5 ] . V_16 ) {
continue;
}
}
if ( ! memcmp
( V_12 . V_14 [ V_5 ] . V_16 -> V_1 ,
V_8 . V_1 , V_15 ) && ( ! V_2 [ 0 ]
||
! memcmp
( V_12 .
V_14 [ V_5 ] . V_16 ->
V_2 ,
V_8 . V_2 ,
V_10 ) )
&& ( ! V_3 [ 0 ]
|| ! memcmp ( V_12 . V_14 [ V_5 ] . V_16 ->
V_3 , V_8 . V_3 ,
V_11 ) ) ) {
* V_4 = V_5 ;
F_7 ( ( V_17 ,
L_1 ,
V_8 . V_1 ) ) ;
F_6 ( V_18 ) ;
}
}
F_6 ( V_19 ) ;
}
