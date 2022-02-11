static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
if ( ! F_3 () ||
( V_6 -> V_7 % V_8 ) + V_4 < V_8 )
return F_4 ( V_2 , V_3 , V_4 ) ;
F_5 ( F_6 ( struct V_5 , V_9 ) != 0 ) ;
F_7 () ;
F_8 ( V_2 , V_3 , V_4 ,
( V_10 * ) V_11 ) ;
F_9 () ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_12 )
{
if ( ! F_3 () )
return F_11 ( V_2 , V_3 , V_4 , V_12 ) ;
F_7 () ;
if ( V_4 )
F_8 ( V_2 , V_3 , V_4 ,
( V_10 * ) V_11 ) ;
F_12 ( V_2 , ( V_10 * ) V_11 ) ;
F_9 () ;
return F_13 ( V_2 , V_12 ) ;
}
static int F_14 ( struct V_1 * V_2 , T_1 * V_12 )
{
return F_10 ( V_2 , NULL , 0 , V_12 ) ;
}
static void F_15 ( T_2 * V_13 , const char * V_3 ,
unsigned int V_14 )
{
if ( V_14 >= V_15 )
F_16 ( V_13 , V_3 , V_14 ) ;
else
F_17 ( V_13 , V_3 , V_14 ) ;
}
static bool T_3 F_18 ( void )
{
if ( ! F_19 ( V_16 | V_17 , NULL ) ) {
if ( V_18 )
F_20 ( L_1 ) ;
return false ;
}
return true ;
}
static bool T_3 F_21 ( void )
{
if ( F_18 () && V_19 && F_22 ( V_20 ) &&
F_22 ( V_21 ) )
return true ;
return false ;
}
static int T_3 F_23 ( void )
{
char * V_22 ;
if ( V_23 ) {
V_11 = V_24 ;
V_22 = L_2 ;
}
#ifdef F_24
if ( F_18 () ) {
V_11 = F_17 ;
V_22 = L_3 ;
#ifdef F_25
if ( F_21 () ) {
V_11 = F_15 ;
V_22 = L_4 ;
}
#endif
}
#endif
if ( V_11 ) {
F_20 ( L_5 , V_22 ) ;
return F_26 ( & V_25 ) ;
}
F_20 ( L_6 ) ;
return - V_26 ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_25 ) ;
}
