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
unsigned int V_4 ;
V_4 = F_6 ( V_1 , 0 ) ;
if ( ! ( V_4 % 2000 ) )
F_7 ( V_5 [ V_4 % 16000 / 2000 ] ) ;
return V_6 ;
}
static T_1 F_8 ( int V_1 , void * V_3 )
{
unsigned int V_4 ;
#ifdef F_9
F_10 () ;
#endif
F_2 ( 5 ) ;
F_4 ( 5 ) ;
#ifdef F_9
F_10 () ;
#endif
F_11 ( 1 ) ;
F_12 ( F_13 ( F_14 () ) ) ;
V_4 = F_6 ( V_1 , 0 ) ;
if ( ! ( V_4 % 20 ) )
F_7 ( V_5 [ V_4 % 160 / 20 ] ) ;
return V_6 ;
}
static T_1 F_15 ( int V_1 , void * V_3 )
{
return V_6 ;
}
void T_2 F_16 ( void )
{
* V_2 = 1 ;
F_17 ( V_7 , 128 ) ;
if ( F_18 ( V_8 , F_8 , 0 , L_1 , NULL ) )
F_19 ( L_2 , L_3 ) ;
if ( F_18 ( V_9 , F_5 , 0 , L_4 , NULL ) )
F_19 ( L_2 , L_5 ) ;
if ( F_18 ( V_10 + 127 , F_15 , 0 , L_6 , NULL ) )
F_19 ( L_2 , L_6 ) ;
}
