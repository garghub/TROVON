static int T_1 F_1 ( void )
{
if ( F_2 () ) {
F_3 ( & V_1 ) ;
} else {
F_3 ( & V_2 ) ;
F_3 ( & V_1 ) ;
}
return F_4 ( V_3 ,
F_5 ( V_3 ) ) ;
}
void T_1 F_6 ( void )
{
struct V_4 * V_5 [ 1 ] ;
if ( F_2 () ) {
V_6 . V_7 |= V_8 ;
V_5 [ 0 ] = & V_1 ;
F_7 ( V_5 , 1 ) ;
} else {
V_5 [ 0 ] = & V_2 ;
F_7 ( V_5 , 1 ) ;
V_5 [ 0 ] = & V_1 ;
F_7 ( V_5 , 1 ) ;
}
F_7 ( V_9 ,
F_5 ( V_9 ) ) ;
}
void T_1 F_8 ( void )
{
F_9 ( & V_10 ) ;
F_9 ( & V_11 ) ;
}
void T_1 F_8 ( void )
{
F_9 ( & V_10 ) ;
F_9 ( & V_12 ) ;
F_9 ( & V_13 ) ;
}
void T_1 F_8 ( void )
{
F_9 ( & V_10 ) ;
F_9 ( & V_11 ) ;
F_9 ( & V_13 ) ;
F_9 ( & V_14 ) ;
}
void T_1 F_8 ( void )
{
F_9 ( & V_10 ) ;
F_9 ( & V_12 ) ;
F_9 ( & V_13 ) ;
F_9 ( & V_14 ) ;
}
void T_1 F_10 ( int V_15 )
{
#if F_11 ( V_16 ) || F_11 ( V_17 )
F_12 () ;
return;
#endif
switch ( V_15 ) {
case V_18 :
F_13 ( F_14 ( V_19 ) | V_20 , V_19 ) ;
F_9 ( & V_21 ) ;
break;
default:
F_12 () ;
}
}
