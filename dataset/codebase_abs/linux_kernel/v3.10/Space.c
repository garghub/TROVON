static int T_1 F_1 ( int V_1 , struct V_2 * V_3 , int V_4 )
{
struct V_5 * V_6 ;
for (; V_3 -> V_7 ; V_3 ++ ) {
if ( V_4 && V_3 -> V_8 )
continue;
V_6 = V_3 -> V_7 ( V_1 ) ;
if ( ! F_2 ( V_6 ) )
return 0 ;
if ( V_4 )
V_3 -> V_8 = F_3 ( V_6 ) ;
}
return - V_9 ;
}
static void T_1 F_4 ( int V_1 )
{
unsigned long V_10 = F_5 ( L_1 , V_1 ) ;
if ( V_10 == 1 )
return;
( void ) ( F_1 ( V_1 , V_11 , V_10 == 0 ) &&
F_1 ( V_1 , V_12 , V_10 == 0 ) ) ;
}
static int T_1 F_6 ( void )
{
int V_13 ;
#ifdef F_7
for ( V_13 = 0 ; V_13 < 8 ; ++ V_13 )
F_8 ( V_13 ) ;
#endif
for ( V_13 = 0 ; V_13 < 8 ; ++ V_13 )
F_4 ( V_13 ) ;
#ifdef F_9
F_10 ( 0 ) ;
F_10 ( 1 ) ;
F_10 ( 2 ) ;
#endif
#ifdef F_11
F_12 () ;
#endif
return 0 ;
}
