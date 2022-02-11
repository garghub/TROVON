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
static void F_7 ( int V_12 , int V_13 )
{
T_1 V_14 = F_8 ( V_15 , V_12 ) ;
F_9 () ;
F_10 ( V_14 , V_13 , V_16 ) ;
}
static void
F_11 ( const struct V_17 * V_18 , int V_13 , int V_19 )
{
unsigned long V_20 ;
unsigned long V_21 ;
unsigned long V_7 ;
F_9 () ;
F_12 ( V_7 ) ;
V_21 = F_13 () ;
F_14 (query_cpu, mask) {
if ( V_19 == V_22 && V_21 == V_20 )
continue;
F_10 ( F_8 ( V_15 , V_20 ) ,
V_13 , V_16 ) ;
}
F_15 ( V_7 ) ;
}
static void F_16 ( const struct V_17 * V_18 , int V_13 )
{
F_11 ( V_18 , V_13 , V_23 ) ;
}
static void
F_17 ( const struct V_17 * V_18 , int V_13 )
{
F_11 ( V_18 , V_13 , V_22 ) ;
}
static void F_18 ( int V_13 )
{
F_11 ( V_24 , V_13 , V_22 ) ;
}
static void F_19 ( int V_13 )
{
F_11 ( V_24 , V_13 , V_23 ) ;
}
static void F_20 ( void )
{
}
static int F_21 ( void )
{
if ( V_25 && ( V_2 || F_2 () ) )
return 1 ;
return V_26 == & V_27 ;
}
