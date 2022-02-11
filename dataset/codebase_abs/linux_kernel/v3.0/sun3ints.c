void F_1 ( void )
{
F_2 ( 0 ) ;
}
void F_3 ( void )
{
F_4 ( 0 ) ;
}
void F_4 ( unsigned int V_1 )
{
* V_2 |= ( 1 << V_1 ) ;
}
void F_2 ( unsigned int V_1 )
{
* V_2 &= ~ ( 1 << V_1 ) ;
}
static T_1 F_5 ( int V_1 , void * V_3 )
{
* V_2 |= ( 1 << V_1 ) ;
if ( ! ( F_6 ( 0 ) . V_4 [ V_1 ] % 2000 ) )
F_7 ( V_5 [ ( F_6 ( 0 ) . V_4 [ V_1 ] % 16000 ) / 2000 ] ) ;
return V_6 ;
}
static T_1 F_8 ( int V_1 , void * V_3 )
{
#ifdef F_9
F_10 () ;
#endif
* V_2 |= ( 1 << V_1 ) ;
#ifdef F_9
F_10 () ;
#endif
F_11 ( 1 ) ;
F_12 ( F_13 ( F_14 () ) ) ;
if ( ! ( F_6 ( 0 ) . V_4 [ V_1 ] % 20 ) )
F_7 ( V_5 [ ( F_6 ( 0 ) . V_4 [ V_1 ] % 160 ) / 20 ] ) ;
return V_6 ;
}
static T_1 F_15 ( int V_1 , void * V_3 )
{
return V_6 ;
}
static void F_16 ( unsigned int V_1 , struct V_7 * V_8 )
{
* V_2 &= ~ ( 1 << V_1 ) ;
F_17 ( V_1 , V_8 ) ;
}
void T_2 F_18 ( void )
{
* V_2 = 1 ;
F_19 ( F_16 ) ;
F_20 ( & V_9 , V_10 , 7 ) ;
F_21 ( V_11 , 128 , NULL ) ;
if ( F_22 ( V_12 , F_8 , 0 , L_1 , NULL ) )
F_23 ( L_2 , L_1 ) ;
if ( F_22 ( V_13 , F_5 , 0 , L_3 , NULL ) )
F_23 ( L_2 , L_3 ) ;
if ( F_22 ( V_14 + 127 , F_15 , 0 , L_4 , NULL ) )
F_23 ( L_2 , L_4 ) ;
}
