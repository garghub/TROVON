static void F_1 ( T_1 const * V_1 , int V_2 , T_2 V_3 )
{
T_1 * V_4 ;
if ( V_5 ) {
F_2 () ;
return;
}
F_3 () ;
F_4 ( V_1 , V_4 ) ;
V_4 -> V_6 += V_2 ;
F_5 ( V_3 ) ;
F_6 () ;
}
static void F_7 ( int V_7 )
{
F_1 ( & V_8 , 0 , V_9 ) ;
}
static void F_8 ( int V_7 )
{
F_1 ( & V_10 , ( V_7 == V_11 ) ? 1 : 0 , V_9 ) ;
}
static void F_9 ( int V_7 )
{
F_1 ( & V_12 , F_10 ( V_7 ) ? - 1 : 0 , V_9 ) ;
}
static void F_11 ( int V_7 )
{
F_1 ( & V_13 , F_10 ( V_7 ) ? - 1 : 0 , V_9 ) ;
}
static void F_12 ( int V_7 )
{
F_1 ( & V_14 , F_10 ( V_7 ) ? - 1 : 0 , V_9 ) ;
}
static void F_13 ( int V_7 )
{
F_1 ( & V_15 , F_10 ( V_7 ) ? - 1 : 0 , V_9 ) ;
}
static void F_14 ( int V_7 )
{
F_1 ( & V_16 , 0 , V_17 ) ;
}
void F_15 ( void )
{
( V_18 [ V_19 ] ) ( V_20 & V_21 ) ;
}
