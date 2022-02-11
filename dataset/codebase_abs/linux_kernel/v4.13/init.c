void T_1 F_1 ( void )
{
unsigned long V_1 = V_2 & V_3 ;
unsigned long V_4 [ V_5 ] = {
[ 0 ] = 0 ,
[ V_6 ] = ( V_1 - V_7 ) >> V_8 ,
[ V_9 ] = 0 ,
#ifdef F_2
[ V_10 ] = 0 ,
#endif
} ;
F_3 ( V_11 ) ;
F_4 ( L_1 ,
F_5 ( V_12 ) , V_1 ) ;
F_6 ( 0 , V_4 ,
V_7 >> V_8 , NULL ) ;
}
T_2 void T_1 F_7 ( void )
{
unsigned int V_13 = F_8 () ;
F_9 () ;
memset ( & V_14 [ V_13 ] , 0 , sizeof( V_14 [ V_13 ] ) ) ;
#ifdef F_10
V_14 [ V_13 ] . V_15 = ( unsigned long * ) ( V_16 + \
V_17 ) ;
#else
V_14 [ V_13 ] . V_15 = V_18 [ V_13 + 1 ] ;
#endif
#ifdef F_11
V_14 [ V_13 ] . V_19 = 0x1f ;
#endif
}
void T_1 F_12 ( void )
{
char V_20 [ 64 ] ;
V_21 = ( void * ) ( V_2 & V_3 ) ;
V_22 = F_13 ( V_21 ) ;
F_14 ( V_23 L_2 , V_22 ) ;
F_15 () ;
snprintf ( V_20 , sizeof( V_20 ) - 1 , L_3 , V_24 >> 10 ) ;
F_16 ( V_20 ) ;
}
void T_1 F_17 ( unsigned long V_25 , unsigned long V_26 )
{
#ifndef F_18
F_19 ( ( void * ) V_25 , ( void * ) V_26 , - 1 , L_4 ) ;
#endif
}
void T_3 F_20 ( void )
{
#if V_27 V_28 && ! V_27 F_18
F_21 ( - 1 ) ;
if ( V_12 == ( unsigned long ) ( & V_29 ) )
V_12 = ( unsigned long ) ( & V_30 ) ;
#endif
}
