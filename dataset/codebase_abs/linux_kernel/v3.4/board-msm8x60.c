static void T_1 F_1 ( struct V_1 * V_1 , char * * V_2 ,
struct V_3 * V_4 )
{
for (; V_1 -> V_5 . V_6 ; V_1 = F_2 ( V_1 ) )
if ( V_1 -> V_5 . V_1 == V_7 &&
V_1 -> V_8 . V_9 . V_10 == 0x40200000 ) {
V_1 -> V_8 . V_9 . V_10 = 0x40000000 ;
V_1 -> V_8 . V_9 . V_6 += V_11 ;
}
}
static void T_1 F_3 ( void )
{
F_4 ( 0x40000000 , V_11 ) ;
}
static void T_1 F_5 ( void )
{
F_6 () ;
}
static void T_1 F_7 ( void )
{
if ( ! F_8 () )
F_9 ( 0 , V_12 , V_13 ,
( void * ) V_14 ) ;
#ifdef F_10
else
F_11 ( V_15 ) ;
#endif
F_12 ( 0xFFFFD7FF , V_13 + V_16 + 4 ) ;
if ( ! F_13 () )
F_12 ( 0x0000FFFF , V_13 + V_17 ) ;
}
static void T_1 F_14 ( void )
{
}
static void T_1 F_15 ( void )
{
if ( F_16 ( L_1 ) ) {
F_17 ( V_18 L_2 ) ;
F_18 () ;
}
F_19 ( NULL , V_19 ,
V_20 , NULL ) ;
}
