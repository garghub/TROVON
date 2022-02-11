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
unsigned int V_12 ;
F_8 ( 0 , V_13 , V_14 ,
( void * ) V_15 ) ;
F_9 ( 0xFFFFD7FF , V_14 + V_16 + 4 ) ;
if ( F_10 () )
F_9 ( 0x0000FFFF , V_14 + V_17 ) ;
for ( V_12 = V_13 ; V_12 < V_18 ; V_12 ++ ) {
if ( V_12 != V_19 && V_12 != V_20 )
F_11 ( V_12 , V_21 ) ;
}
}
static void T_1 F_12 ( void )
{
F_13 ( V_22 , F_14 ( V_22 ) ) ;
}
static void T_1 F_15 ( void )
{
F_13 ( V_23 , F_14 ( V_23 ) ) ;
}
