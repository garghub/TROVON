static int F_1 ( char * V_1 )
{
V_2 = 1 ;
return 0 ;
}
static bool F_2 ( void )
{
if ( ( V_3 . V_4 . V_5 >= V_6 ) &&
( V_3 . V_7 & V_8 ) ) {
F_3 ( V_9 L_1 ) ;
return true ;
}
return false ;
}
static int F_4 ( char * V_10 , char * V_11 )
{
return F_5 () && ( V_2 || F_2 () ) ;
}
static void
F_6 ( const struct V_12 * V_13 , int V_14 , int V_15 )
{
unsigned long V_16 ;
unsigned long V_17 ;
unsigned long V_7 ;
F_7 () ;
F_8 ( V_7 ) ;
V_17 = F_9 () ;
F_10 (query_cpu, mask) {
if ( V_15 == V_18 && V_17 == V_16 )
continue;
F_11 ( F_12 ( V_19 , V_16 ) ,
V_14 , V_20 ) ;
}
F_13 ( V_7 ) ;
}
static void F_14 ( const struct V_12 * V_13 , int V_14 )
{
F_6 ( V_13 , V_14 , V_21 ) ;
}
static void
F_15 ( const struct V_12 * V_13 , int V_14 )
{
F_6 ( V_13 , V_14 , V_18 ) ;
}
static void F_16 ( int V_14 )
{
F_6 ( V_22 , V_14 , V_18 ) ;
}
static void F_17 ( int V_14 )
{
F_6 ( V_22 , V_14 , V_21 ) ;
}
static void F_18 ( void )
{
}
static int F_19 ( void )
{
if ( V_23 && ( V_2 || F_2 () ) )
return 1 ;
return V_24 == & V_25 ;
}
