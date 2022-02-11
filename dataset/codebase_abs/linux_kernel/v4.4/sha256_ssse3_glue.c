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
return F_1 ( V_2 , V_3 , V_4 , V_13 ) ;
}
static int F_15 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_12 )
{
return F_10 ( V_2 , V_3 , V_4 , V_12 , V_13 ) ;
}
static int F_16 ( struct V_1 * V_2 , T_1 * V_12 )
{
return F_15 ( V_2 , NULL , 0 , V_12 ) ;
}
static int F_17 ( void )
{
if ( F_18 ( V_14 ) )
return F_19 ( V_15 ,
F_20 ( V_15 ) ) ;
return 0 ;
}
static void F_21 ( void )
{
if ( F_18 ( V_14 ) )
F_22 ( V_15 ,
F_20 ( V_15 ) ) ;
}
static int F_23 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_16 ) ;
}
static int F_24 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_12 )
{
return F_10 ( V_2 , V_3 , V_4 , V_12 , V_16 ) ;
}
static int F_25 ( struct V_1 * V_2 , T_1 * V_12 )
{
return F_24 ( V_2 , NULL , 0 , V_12 ) ;
}
static bool F_26 ( void )
{
if ( ! F_27 ( V_17 | V_18 , NULL ) ) {
if ( V_19 )
F_28 ( L_1 ) ;
return false ;
}
return true ;
}
static int F_29 ( void )
{
if ( F_26 () )
return F_19 ( V_20 ,
F_20 ( V_20 ) ) ;
return 0 ;
}
static void F_30 ( void )
{
if ( F_26 () )
F_22 ( V_20 ,
F_20 ( V_20 ) ) ;
}
static inline int F_29 ( void ) { return 0 ; }
static inline void F_30 ( void ) { }
static int F_31 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_21 ) ;
}
static int F_32 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_12 )
{
return F_10 ( V_2 , V_3 , V_4 , V_12 , V_21 ) ;
}
static int F_33 ( struct V_1 * V_2 , T_1 * V_12 )
{
return F_32 ( V_2 , NULL , 0 , V_12 ) ;
}
static bool F_34 ( void )
{
if ( F_26 () && F_18 ( V_22 ) &&
F_18 ( V_23 ) )
return true ;
return false ;
}
static int F_35 ( void )
{
if ( F_34 () )
return F_19 ( V_24 ,
F_20 ( V_24 ) ) ;
return 0 ;
}
static void F_36 ( void )
{
if ( F_34 () )
F_22 ( V_24 ,
F_20 ( V_24 ) ) ;
}
static inline int F_35 ( void ) { return 0 ; }
static inline void F_36 ( void ) { }
static int F_37 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_25 ) ;
}
static int F_38 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 , T_1 * V_12 )
{
return F_10 ( V_2 , V_3 , V_4 , V_12 , V_25 ) ;
}
static int F_39 ( struct V_1 * V_2 , T_1 * V_12 )
{
return F_38 ( V_2 , NULL , 0 , V_12 ) ;
}
static int F_40 ( void )
{
if ( F_18 ( V_26 ) )
return F_19 ( V_27 ,
F_20 ( V_27 ) ) ;
return 0 ;
}
static void F_41 ( void )
{
if ( F_18 ( V_26 ) )
F_22 ( V_27 ,
F_20 ( V_27 ) ) ;
}
static inline int F_40 ( void ) { return 0 ; }
static inline void F_41 ( void ) { }
static int T_3 F_42 ( void )
{
if ( F_17 () )
goto V_28;
if ( F_29 () ) {
F_21 () ;
goto V_28;
}
if ( F_35 () ) {
F_30 () ;
F_21 () ;
goto V_28;
}
if ( F_40 () ) {
F_36 () ;
F_30 () ;
F_21 () ;
goto V_28;
}
return 0 ;
V_28:
return - V_29 ;
}
static void T_4 F_43 ( void )
{
F_41 () ;
F_36 () ;
F_30 () ;
F_21 () ;
}
