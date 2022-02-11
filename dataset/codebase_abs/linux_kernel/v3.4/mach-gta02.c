static long F_1 ( int V_1 )
{
long V_2 = 0 ;
char V_3 ;
V_3 = ( V_1 ) ? 1 : 0 ;
F_2 ( V_4 , V_3 ) ;
return V_2 ;
}
static void
F_3 ( struct V_5 * V_6 , void * V_7 , int V_8 )
{
int V_9 ;
if ( V_8 < ( ( V_10 + V_11 ) / 2 ) ) {
F_4 ( V_6 , V_12 , 0 ) ;
V_9 = 1000 ;
} else
V_9 = 100 ;
F_5 ( V_6 , V_9 ) ;
}
static void F_6 ( struct V_13 * V_14 )
{
if ( V_15 ) {
F_5 ( V_16 , V_15 ) ;
return;
}
#ifdef F_7
F_8 ( V_16 ,
V_17 ,
V_18 ,
F_3 ,
NULL ) ;
#else
F_5 ( V_6 , 100 ) ;
#endif
}
static void F_9 ( struct V_5 * V_6 , int V_19 )
{
if ( V_19 == V_20 ) {
F_10 ( & V_21 ,
V_22 ) ;
return;
}
if ( V_19 == V_23 ) {
F_11 ( & V_21 ) ;
V_15 = 0 ;
}
}
static void F_12 ( unsigned int V_9 )
{
if ( ! V_16 )
return;
V_15 = V_9 ;
F_10 ( & V_21 ,
V_22 ) ;
}
static void T_1 F_13 ( void )
{
F_14 ( V_24 , F_15 ( V_24 ) ) ;
F_16 ( 12000000 ) ;
F_17 ( V_25 , F_15 ( V_25 ) ) ;
}
static void F_18 ( struct V_5 * V_6 )
{
int V_26 ;
V_16 = V_6 ;
for ( V_26 = 0 ; V_26 < F_15 ( V_27 ) ; V_26 ++ )
V_27 [ V_26 ] -> V_28 . V_29 = V_6 -> V_28 ;
F_19 ( V_27 ,
F_15 ( V_27 ) ) ;
}
static void F_20 ( void )
{
F_21 ( V_16 , V_30 , 1 , 1 ) ;
}
static void T_1 F_22 ( void )
{
V_31 = F_1 ;
F_23 () ;
#ifdef F_24
F_25 ( & V_21 , F_6 ) ;
#endif
F_26 ( & V_32 ) ;
F_27 ( & V_33 ) ;
F_28 ( & V_34 ) ;
F_29 ( & V_35 ) ;
F_30 ( NULL ) ;
F_31 ( 0 , V_36 , F_15 ( V_36 ) ) ;
F_19 ( V_37 , F_15 ( V_37 ) ) ;
V_38 = F_20 ;
F_32 () ;
}
