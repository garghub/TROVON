static void T_1 F_1 ( void )
{
T_2 * V_1 = F_2 ( 0UL ) ;
F_3 ( V_1 ) ;
F_4 () ;
}
static void T_1 F_5 ( void )
{
memset ( V_2 , 0 ,
( unsigned long ) V_3 - ( unsigned long ) V_2 ) ;
}
static void T_1 F_6 ( char * V_4 )
{
char * V_5 ;
memcpy ( & V_6 , V_4 , sizeof V_6 ) ;
if ( V_6 . V_7 . V_8 ) {
V_5 = F_7 ( V_6 . V_7 . V_8 ) ;
memcpy ( V_9 , V_5 , V_10 ) ;
}
}
void T_1 F_8 ( char * V_4 )
{
int V_11 ;
F_9 ( V_12 < V_13 ) ;
F_9 ( V_12 - V_13 < V_14 ) ;
F_9 ( V_15 + V_14 > 2 * V_16 ) ;
F_9 ( ( V_13 & ~ V_17 ) != 0 ) ;
F_9 ( ( V_12 & ~ V_17 ) != 0 ) ;
F_9 ( ! ( V_12 > V_18 ) ) ;
F_9 ( ! ( ( ( V_19 - 1 ) & V_20 ) ==
( V_18 & V_20 ) ) ) ;
F_9 ( F_10 ( V_21 ) <= V_19 ) ;
F_5 () ;
F_1 () ;
V_22 = V_14 >> V_23 ;
for ( V_11 = 0 ; V_11 < V_24 ; V_11 ++ ) {
#ifdef F_11
F_12 ( V_11 , & V_25 [ V_11 ] ) ;
#else
F_12 ( V_11 , V_26 ) ;
#endif
}
F_13 ( ( const struct V_27 * ) & V_28 ) ;
if ( V_29 == 10 )
F_14 ( L_1 ) ;
F_15 ( V_4 ) ;
}
void T_1 F_15 ( char * V_4 )
{
F_6 ( F_7 ( V_4 ) ) ;
F_16 ( F_17 ( & V_30 ) ,
F_17 ( & V_3 ) - F_17 ( & V_30 ) ) ;
#ifdef F_18
if ( V_6 . V_7 . V_31 && V_6 . V_7 . V_32 ) {
unsigned long V_32 = V_6 . V_7 . V_32 ;
unsigned long V_33 = V_6 . V_7 . V_33 ;
unsigned long V_34 = F_19 ( V_32 + V_33 ) ;
F_16 ( V_32 , V_34 - V_32 ) ;
}
#endif
F_20 () ;
F_21 () ;
}
