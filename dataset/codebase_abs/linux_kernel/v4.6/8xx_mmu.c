void T_1 F_1 ( void )
{
}
unsigned long T_1 F_2 ( unsigned long V_1 )
{
unsigned long V_2 , V_3 , V_4 ;
T_2 V_5 ;
V_2 = V_6 ;
V_5 = 0 ;
V_3 = V_1 ;
if ( V_7 )
return 0 ;
#ifdef F_3
while ( V_3 >= V_8 ) {
T_3 * V_9 ;
unsigned long V_10 = V_5 | V_11 ;
V_9 = F_4 ( F_5 ( F_6 ( V_2 ) , V_2 ) , V_2 ) ;
* V_9 ++ = F_7 ( V_10 ) ;
* V_9 ++ = F_7 ( V_10 + V_12 ) ;
V_2 += V_8 ;
V_5 += V_8 ;
V_3 -= V_8 ;
}
#else
while ( V_3 >= V_13 ) {
T_3 * V_9 ;
unsigned long V_10 = V_5 | V_11 ;
V_9 = F_4 ( F_5 ( F_6 ( V_2 ) , V_2 ) , V_2 ) ;
* V_9 ++ = F_7 ( V_10 ) ;
V_2 += V_13 ;
V_5 += V_13 ;
V_3 -= V_13 ;
}
#endif
V_4 = V_1 - V_3 ;
F_8 ( V_4 ) ;
return V_4 ;
}
void F_9 ( T_2 V_14 ,
T_2 V_15 )
{
F_10 ( V_14 != 0 ) ;
#ifdef F_11
F_8 ( F_12 ( V_16 , V_15 , 0x01800000 ) ) ;
#else
F_8 ( F_12 ( V_16 , V_15 , 0x00800000 ) ) ;
#endif
}
void F_13 ( unsigned long V_17 , T_4 * V_18 )
{
T_5 V_19 = ( T_5 ) ( F_14 ( V_20 ) ) ;
#ifdef F_15
T_4 * * V_21 = * ( T_4 * * * ) ( V_6 + 0xf0 ) ;
* ( V_21 + 1 ) = V_18 ;
#endif
F_16 ( V_22 , F_14 ( V_18 ) - V_19 ) ;
F_16 ( V_23 , V_17 ) ;
F_17 () ;
}
void F_18 ( void )
{
F_19 () ;
F_16 ( V_24 , V_25 ) ;
F_19 () ;
}
