static void F_1 ( void )
{
while ( F_2 ( V_1 ) )
F_3 () ;
while ( ! F_2 ( V_1 ) )
F_3 () ;
}
static void F_4 ( void )
{
void (* F_5)( void );
F_5 = F_6 ( V_2 ) ;
if ( F_5 ) {
F_5 () ;
F_7 ( V_2 ) ;
}
}
static void T_1 F_8 ( void )
{
F_9 ( 1 , & V_3 ) ;
F_10 ( F_11 ( V_4 ) ) ;
}
static inline void F_8 ( void ) {}
static void F_12 ( void )
{
if ( ! F_13 () )
F_14 ( V_5 , 0 ) ;
F_15 ( 'h' , NULL ) ;
}
static void F_16 ( char V_6 , const char * V_7 )
{
if ( ! F_13 () )
F_14 ( V_5 , 1 ) ;
F_15 ( 'h' , V_7 ) ;
}
static void T_1 F_17 ( void )
{
V_8 = F_12 ;
V_9 = F_16 ;
V_10 |= V_11 ;
F_18 ( F_11 ( V_12 ) ) ;
F_19 ( V_13 , 1 ) ;
F_19 ( V_14 , 1 ) ;
F_19 ( V_15 , 1 ) ;
F_19 ( V_16 , 1 ) ;
if ( ! F_13 () )
F_19 ( V_17 , 1 ) ;
F_20 ( NULL ) ;
F_21 ( NULL ) ;
F_22 ( NULL ) ;
F_8 () ;
F_23 ( & V_18 ) ;
F_24 ( & V_19 ) ;
F_25 ( & V_20 ) ;
F_26 ( NULL ) ;
F_27 ( 0 , F_11 ( V_21 ) ) ;
V_22 = & V_23 ;
if ( F_28 () )
V_24 [ 1 ] . V_25 = 53 * 1024 * 1024 ;
F_29 ( V_26 , F_30 ( V_26 ) ) ;
}
static void T_1 F_31 ( struct V_27 * V_28 ,
struct V_29 * V_30 , char * * V_31 , struct V_32 * V_33 )
{
F_32 () ;
V_33 -> V_34 = 1 ;
V_33 -> V_35 [ 0 ] . V_36 = 0xa0000000 ;
if ( F_13 () )
V_33 -> V_35 [ 0 ] . V_25 = ( 32 * 1024 * 1024 ) ;
else
V_33 -> V_35 [ 0 ] . V_25 = ( 64 * 1024 * 1024 ) ;
}
