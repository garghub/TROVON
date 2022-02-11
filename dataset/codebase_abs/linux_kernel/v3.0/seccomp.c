void F_1 ( int V_1 )
{
int V_2 = V_3 -> V_4 . V_2 ;
int * V_5 ;
switch ( V_2 ) {
case 1 :
V_5 = V_6 ;
#ifdef F_2
if ( F_3 () )
V_5 = V_7 ;
#endif
do {
if ( * V_5 == V_1 )
return;
} while ( * ++ V_5 );
break;
default:
F_4 () ;
}
#ifdef F_5
F_6 () ;
#endif
F_7 ( V_8 ) ;
}
long F_8 ( void )
{
return V_3 -> V_4 . V_2 ;
}
long F_9 ( unsigned long V_9 )
{
long V_10 ;
V_10 = - V_11 ;
if ( F_10 ( V_3 -> V_4 . V_2 ) )
goto V_12;
V_10 = - V_13 ;
if ( V_9 && V_9 <= V_14 ) {
V_3 -> V_4 . V_2 = V_9 ;
F_11 ( V_15 ) ;
#ifdef F_12
F_13 () ;
#endif
V_10 = 0 ;
}
V_12:
return V_10 ;
}
