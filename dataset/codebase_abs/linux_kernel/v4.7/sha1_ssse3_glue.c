static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_2 * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
if ( ! F_3 () ||
( V_7 -> V_8 % V_9 ) + V_4 < V_9 )
return F_4 ( V_2 , V_3 , V_4 ) ;
F_5 ( F_6 ( struct V_6 , V_10 ) != 0 ) ;
F_7 () ;
F_8 ( V_2 , V_3 , V_4 ,
( V_11 * ) V_5 ) ;
F_9 () ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_12 , T_2 * V_5 )
{
if ( ! F_3 () )
return F_11 ( V_2 , V_3 , V_4 , V_12 ) ;
F_7 () ;
if ( V_4 )
F_8 ( V_2 , V_3 , V_4 ,
( V_11 * ) V_5 ) ;
F_12 ( V_2 , ( V_11 * ) V_5 ) ;
F_9 () ;
return F_13 ( V_2 , V_12 ) ;
}
static int F_14 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
return F_1 ( V_2 , V_3 , V_4 ,
( T_2 * ) V_13 ) ;
}
static int F_15 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_12 )
{
return F_10 ( V_2 , V_3 , V_4 , V_12 ,
( T_2 * ) V_13 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 * V_12 )
{
return F_15 ( V_2 , NULL , 0 , V_12 ) ;
}
static int F_17 ( void )
{
if ( F_18 ( V_14 ) )
return F_19 ( & V_15 ) ;
return 0 ;
}
static void F_20 ( void )
{
if ( F_18 ( V_14 ) )
F_21 ( & V_15 ) ;
}
static int F_22 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
return F_1 ( V_2 , V_3 , V_4 ,
( T_2 * ) V_16 ) ;
}
static int F_23 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_12 )
{
return F_10 ( V_2 , V_3 , V_4 , V_12 ,
( T_2 * ) V_16 ) ;
}
static int F_24 ( struct V_1 * V_2 , T_1 * V_12 )
{
return F_23 ( V_2 , NULL , 0 , V_12 ) ;
}
static bool F_25 ( void )
{
if ( ! F_26 ( V_17 | V_18 , NULL ) ) {
if ( F_18 ( V_19 ) )
F_27 ( L_1 ) ;
return false ;
}
return true ;
}
static int F_28 ( void )
{
if ( F_25 () )
return F_19 ( & V_20 ) ;
return 0 ;
}
static void F_29 ( void )
{
if ( F_25 () )
F_21 ( & V_20 ) ;
}
static inline int F_28 ( void ) { return 0 ; }
static inline void F_29 ( void ) { }
static bool F_30 ( void )
{
if ( F_25 () && F_18 ( V_21 )
&& F_18 ( V_22 )
&& F_18 ( V_23 ) )
return true ;
return false ;
}
static void F_31 ( T_3 * V_24 , const char * V_3 ,
unsigned int V_25 )
{
if ( V_25 >= V_26 )
F_32 ( V_24 , V_3 , V_25 ) ;
else
V_16 ( V_24 , V_3 , V_25 ) ;
}
static int F_33 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
return F_1 ( V_2 , V_3 , V_4 ,
( T_2 * ) F_31 ) ;
}
static int F_34 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_12 )
{
return F_10 ( V_2 , V_3 , V_4 , V_12 ,
( T_2 * ) F_31 ) ;
}
static int F_35 ( struct V_1 * V_2 , T_1 * V_12 )
{
return F_34 ( V_2 , NULL , 0 , V_12 ) ;
}
static int F_36 ( void )
{
if ( F_30 () )
return F_19 ( & V_27 ) ;
return 0 ;
}
static void F_37 ( void )
{
if ( F_30 () )
F_21 ( & V_27 ) ;
}
static inline int F_36 ( void ) { return 0 ; }
static inline void F_37 ( void ) { }
static int F_38 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
return F_1 ( V_2 , V_3 , V_4 ,
( T_2 * ) V_28 ) ;
}
static int F_39 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_12 )
{
return F_10 ( V_2 , V_3 , V_4 , V_12 ,
( T_2 * ) V_28 ) ;
}
static int F_40 ( struct V_1 * V_2 , T_1 * V_12 )
{
return F_39 ( V_2 , NULL , 0 , V_12 ) ;
}
static int F_41 ( void )
{
if ( F_18 ( V_29 ) )
return F_19 ( & V_30 ) ;
return 0 ;
}
static void F_42 ( void )
{
if ( F_18 ( V_29 ) )
F_21 ( & V_30 ) ;
}
static inline int F_41 ( void ) { return 0 ; }
static inline void F_42 ( void ) { }
static int T_4 F_43 ( void )
{
if ( F_17 () )
goto V_31;
if ( F_28 () ) {
F_20 () ;
goto V_31;
}
if ( F_36 () ) {
F_29 () ;
F_20 () ;
goto V_31;
}
if ( F_41 () ) {
F_37 () ;
F_29 () ;
F_20 () ;
goto V_31;
}
return 0 ;
V_31:
return - V_32 ;
}
static void T_5 F_44 ( void )
{
F_42 () ;
F_37 () ;
F_29 () ;
F_20 () ;
}
