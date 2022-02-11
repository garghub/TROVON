static void F_1 ( void )
{
if ( V_1 )
return;
V_1 = 1 ;
if ( V_2 ) {
#ifndef F_2
# ifdef F_3
fprintf ( V_3 , L_1
L_2 ) ;
# endif
F_4 () ;
#endif
}
if ( V_4 ) {
#ifdef F_3
fprintf ( V_3 , L_1
L_3 ) ;
#endif
F_5 () ;
}
}
int F_6 ( T_1 V_5 , const T_2 * V_6 )
{
static int V_7 = 0 ;
if ( V_1 ) {
if ( ! V_7 ) {
V_7 = 1 ;
F_7 ( V_8 , V_9 ) ;
}
return 0 ;
}
if ( ! F_8 ( V_5 | V_10
| V_11 , V_6 ) )
return 0 ;
if ( ! F_9 ( & V_12 , V_13 ) )
return 0 ;
if ( ( V_5 & V_14 )
&& ! F_9 ( & V_15 , V_16 ) )
return 0 ;
if ( ( V_5 & V_17 )
&& ! F_9 ( & V_15 , V_18 ) )
return 0 ;
return 1 ;
}
