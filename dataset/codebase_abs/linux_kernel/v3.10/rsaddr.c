T_1
F_1 ( struct V_1 * V_2 ,
union V_3 * V_4 )
{
F_2 () ;
if ( ( V_4 -> V_5 . V_6 > 2 )
&& ( V_4 -> V_5 . V_6 < 0xC0 ) ) {
return ( FALSE ) ;
}
( void ) F_3 ( V_2 , V_4 ,
V_7 ) ;
if ( V_2 -> V_8 . V_5 . V_6 == V_9 ) {
( void ) F_3 ( V_2 , V_4 ,
V_10 ) ;
} else if ( V_2 -> V_8 . V_5 . V_6 == V_11 ) {
( void ) F_3 ( V_2 , V_4 ,
V_12 ) ;
} else {
V_2 -> V_8 . V_5 . V_13 . V_14 =
V_4 -> V_5 . V_15 ;
}
return ( TRUE ) ;
}
void
F_4 ( union V_3 * V_4 ,
struct V_1 * V_2 )
{
F_2 () ;
( void ) F_5 ( V_2 , V_4 ,
V_7 ) ;
if ( V_2 -> V_8 . V_5 . V_6 == V_9 ) {
( void ) F_5 ( V_2 , V_4 ,
V_10 ) ;
} else if ( V_2 -> V_8 . V_5 . V_6 == V_11 ) {
( void ) F_5 ( V_2 , V_4 ,
V_12 ) ;
} else {
V_4 -> V_5 . V_15 =
V_2 -> V_8 . V_5 . V_13 . V_14 ;
}
}
