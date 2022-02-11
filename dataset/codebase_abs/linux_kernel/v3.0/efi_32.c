void F_1 ( void )
{
unsigned long V_1 ;
unsigned long V_2 ;
struct V_3 V_4 ;
F_2 ( V_5 ) ;
V_1 = F_3 () ;
if ( V_1 & V_6 ) {
V_7 [ 0 ] . V_8 =
V_9 [ F_4 ( 0 ) ] . V_8 ;
V_9 [ 0 ] . V_8 =
V_9 [ F_4 ( V_10 ) ] . V_8 ;
} else {
V_7 [ 0 ] . V_8 =
V_9 [ F_4 ( 0 ) ] . V_8 ;
V_7 [ 1 ] . V_8 =
V_9 [ F_4 ( 0x400000 ) ] . V_8 ;
V_9 [ F_4 ( 0 ) ] . V_8 =
V_9 [ F_4 ( V_10 ) ] . V_8 ;
V_2 = V_10 + 0x400000 ;
V_9 [ F_4 ( 0x400000 ) ] . V_8 =
V_9 [ F_4 ( V_2 ) ] . V_8 ;
}
F_5 () ;
V_4 . V_11 = F_6 ( F_7 ( 0 ) ) ;
V_4 . V_12 = V_13 - 1 ;
F_8 ( & V_4 ) ;
}
void F_9 ( void )
{
unsigned long V_1 ;
struct V_3 V_4 ;
V_4 . V_11 = ( unsigned long ) F_7 ( 0 ) ;
V_4 . V_12 = V_13 - 1 ;
F_8 ( & V_4 ) ;
V_1 = F_3 () ;
if ( V_1 & V_6 ) {
V_9 [ F_4 ( 0 ) ] . V_8 =
V_7 [ 0 ] . V_8 ;
} else {
V_9 [ F_4 ( 0 ) ] . V_8 =
V_7 [ 0 ] . V_8 ;
V_9 [ F_4 ( 0x400000 ) ] . V_8 =
V_7 [ 1 ] . V_8 ;
}
F_5 () ;
F_10 ( V_5 ) ;
}
