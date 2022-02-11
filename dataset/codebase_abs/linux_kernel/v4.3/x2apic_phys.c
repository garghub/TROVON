static int F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static bool F_2 ( void )
{
#ifdef F_3
if ( ( V_3 . V_4 . V_5 >= V_6 ) &&
( V_3 . V_7 & V_8 ) ) {
F_4 ( V_9 L_1 ) ;
return true ;
}
#endif
return false ;
}
static int F_5 ( char * V_10 , char * V_11 )
{
return F_6 () && ( V_2 || F_2 () ) ;
}
static void
F_7 ( const struct V_12 * V_13 , int V_14 , int V_15 )
{
unsigned long V_16 ;
unsigned long V_17 ;
unsigned long V_7 ;
F_8 () ;
F_9 ( V_7 ) ;
V_17 = F_10 () ;
F_11 (query_cpu, mask) {
if ( V_15 == V_18 && V_17 == V_16 )
continue;
F_12 ( F_13 ( V_19 , V_16 ) ,
V_14 , V_20 ) ;
}
F_14 ( V_7 ) ;
}
static void F_15 ( const struct V_12 * V_13 , int V_14 )
{
F_7 ( V_13 , V_14 , V_21 ) ;
}
static void
F_16 ( const struct V_12 * V_13 , int V_14 )
{
F_7 ( V_13 , V_14 , V_18 ) ;
}
static void F_17 ( int V_14 )
{
F_7 ( V_22 , V_14 , V_18 ) ;
}
static void F_18 ( int V_14 )
{
F_7 ( V_22 , V_14 , V_21 ) ;
}
static void F_19 ( void )
{
}
static int F_20 ( void )
{
if ( V_23 && ( V_2 || F_2 () ) )
return 1 ;
return V_24 == & V_25 ;
}
