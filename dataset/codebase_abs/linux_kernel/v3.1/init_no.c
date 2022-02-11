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
extern char V_16 , V_17 , V_18 , V_19 , V_20 , V_21 ;
extern unsigned int V_22 , V_23 ;
unsigned long V_24 = V_22 - V_23 ;
unsigned long V_25 = V_26 ;
unsigned long V_1 = V_2 ;
F_6 ( L_1 , V_25 , V_1 ) ;
V_1 &= V_3 ;
V_27 = ( void * ) V_1 ;
V_25 = F_7 ( V_25 ) ;
V_28 = V_29 = ( ( ( unsigned long ) V_27 ) - V_10 ) >> V_11 ;
V_30 = F_8 () ;
V_12 = ( & V_16 - & V_17 ) >> 10 ;
V_13 = ( & V_19 - & V_18 ) >> 10 ;
V_14 = ( & V_20 - & V_21 ) >> 10 ;
V_15 = F_9 () << V_11 ;
F_10 ( V_31 L_2 ,
V_15 >> 10 ,
V_24 >> 10 ,
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
V_30 ++ ;
V_34 ++ ;
}
F_16 ( L_3 ,
V_34 * ( V_7 / 1024 ) ) ;
}
void F_17 ( void )
{
#ifdef F_18
unsigned long V_35 ;
extern char V_20 , V_21 ;
V_35 = F_7 ( ( unsigned long ) ( & V_20 ) ) ;
for (; V_35 + V_7 < ( unsigned long ) ( & V_21 ) ; V_35 += V_7 ) {
F_12 ( F_13 ( V_35 ) ) ;
F_14 ( F_13 ( V_35 ) ) ;
F_15 ( V_35 ) ;
V_30 ++ ;
}
F_16 ( L_4 ,
( V_35 - F_7 ( ( long ) & V_20 ) ) >> 10 ,
( int ) ( F_7 ( ( unsigned long ) ( & V_20 ) ) ) ,
( int ) ( V_35 - V_7 ) ) ;
#endif
}
