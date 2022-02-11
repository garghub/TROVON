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
F_8 ( 0 , V_12 , V_13 ,
( void * ) V_14 ) ;
F_9 ( 0xFFFFD7FF , V_13 + V_15 + 4 ) ;
if ( ! F_10 () )
F_9 ( 0x0000FFFF , V_13 + V_16 ) ;
}
static void T_1 F_11 ( void )
{
}
static void T_1 F_12 ( void )
{
struct V_17 * V_18 ;
V_18 = F_13 ( NULL , V_19 ,
V_20 ) ;
if ( V_18 )
F_14 ( V_18 , V_21 ) ;
if ( F_15 ( L_1 ) ) {
F_16 ( V_22 L_2 ) ;
F_17 () ;
}
F_18 ( NULL , V_23 ,
V_24 , NULL ) ;
}
