void T_1 F_1 ( void )
{
unsigned long V_1 = V_2 & V_3 ;
unsigned long V_4 [ V_5 ] = { 0 , } ;
V_6 = F_2 ( V_7 ) ;
memset ( V_6 , 0 , V_7 ) ;
F_3 ( V_8 ) ;
V_4 [ V_9 ] = ( V_1 - V_10 ) >> V_11 ;
F_4 ( V_4 ) ;
}
void T_1 F_5 ( void )
{
int V_12 = 0 , V_13 = 0 , V_14 = 0 ;
unsigned long V_15 ;
unsigned long V_16 = V_17 - V_18 ;
unsigned long V_19 = V_20 ;
unsigned long V_1 = V_2 ;
F_6 ( L_1 , V_19 , V_1 ) ;
V_1 &= V_3 ;
V_21 = ( void * ) V_1 ;
V_19 = F_7 ( V_19 ) ;
V_22 = V_23 = ( ( ( unsigned long ) V_21 ) - V_10 ) >> V_11 ;
V_24 = F_8 () ;
V_12 = ( V_25 - V_26 ) >> 10 ;
V_13 = ( V_27 - V_28 ) >> 10 ;
V_14 = ( V_29 - V_30 ) >> 10 ;
V_15 = F_9 () << V_11 ;
F_10 ( V_31 L_2 ,
V_15 >> 10 ,
V_16 >> 10 ,
V_12 ,
V_13
) ;
}
void F_11 ( unsigned long V_32 , unsigned long V_33 )
{
int V_34 = 0 ;
for (; V_32 < V_33 ; V_32 += V_7 ) {
F_12 ( F_13 ( V_32 ) ) ;
F_14 ( F_13 ( V_32 ) ) ;
F_15 ( V_32 ) ;
V_24 ++ ;
V_34 ++ ;
}
F_16 ( L_3 ,
V_34 * ( V_7 / 1024 ) ) ;
}
void F_17 ( void )
{
#ifdef F_18
unsigned long V_35 ;
V_35 = F_7 ( ( unsigned long ) V_29 ) ;
for (; V_35 + V_7 < ( ( unsigned long ) V_30 ) ; V_35 += V_7 ) {
F_12 ( F_13 ( V_35 ) ) ;
F_14 ( F_13 ( V_35 ) ) ;
F_15 ( V_35 ) ;
V_24 ++ ;
}
F_16 ( L_4 ,
( V_35 - F_7 ( ( unsigned long ) V_29 ) ) >> 10 ,
( int ) ( F_7 ( ( unsigned long ) V_29 ) ) ,
( int ) ( V_35 - V_7 ) ) ;
#endif
}
