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
F_1 ( V_1 , V_12 , V_10 == 0 ) &&
F_1 ( V_1 , V_13 , V_10 == 0 ) &&
F_1 ( V_1 , V_14 , V_10 == 0 ) &&
F_1 ( V_1 , V_15 , V_10 == 0 ) ) ;
}
static T_1 int F_6 ( int V_1 )
{
int V_16 = - V_9 ;
#ifdef F_7
struct V_5 * V_6 = F_8 ( 0 ) ;
if ( ! V_6 )
return - V_17 ;
sprintf ( V_6 -> V_18 , L_2 , V_1 ) ;
F_9 ( V_6 ) ;
V_16 = F_10 ( V_6 ) ;
if ( V_16 )
F_11 ( V_6 ) ;
#endif
return V_16 ;
}
static void T_1 F_12 ( int V_1 )
{
unsigned long V_10 = F_5 ( L_3 , V_1 ) ;
if ( V_10 == 1 )
return;
F_1 ( V_1 , V_19 , V_10 == 0 ) ;
}
static int T_1 F_13 ( void )
{
int V_20 ;
#ifdef F_14
for ( V_20 = 0 ; V_20 < 8 ; ++ V_20 )
F_15 ( V_20 ) ;
#endif
#ifdef F_16
for ( V_20 = 0 ; V_20 < 8 ; ++ V_20 )
if ( ! F_6 ( V_20 ) )
F_12 ( V_20 ) ;
#endif
for ( V_20 = 0 ; V_20 < 8 ; ++ V_20 )
F_4 ( V_20 ) ;
#ifdef F_17
F_18 ( 0 ) ;
F_18 ( 1 ) ;
F_18 ( 2 ) ;
#endif
#ifdef F_19
F_20 () ;
#endif
return 0 ;
}
