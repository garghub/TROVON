void T_1 F_1 ( void )
{
F_2 ( V_1 , 0x10000000 ) ;
F_3 () ;
F_2 ( V_2 , 0x00000000 ) ;
F_2 ( V_3 , 0xFFFF0000 ) ;
F_2 ( V_4 , 0xFFFF0000 ) ;
}
unsigned long T_1 F_4 ( unsigned long V_5 )
{
unsigned long V_6 , V_7 , V_8 ;
T_2 V_9 ;
V_6 = V_10 ;
V_9 = 0 ;
V_7 = V_11 ;
if ( V_12 )
return 0 ;
while ( V_7 >= V_13 ) {
T_3 * V_14 ;
unsigned long V_15 = V_9 | V_16 | V_17 | V_18 ;
V_14 = F_5 ( F_6 ( F_7 ( V_6 ) , V_6 ) , V_6 ) ;
F_8 ( * V_14 ++ ) = V_15 ;
F_8 ( * V_14 ++ ) = V_15 ;
F_8 ( * V_14 ++ ) = V_15 ;
F_8 ( * V_14 ++ ) = V_15 ;
V_6 += V_13 ;
V_9 += V_13 ;
V_7 -= V_13 ;
}
while ( V_7 >= V_19 ) {
T_3 * V_14 ;
unsigned long V_15 = V_9 | V_20 | V_17 | V_18 ;
V_14 = F_5 ( F_6 ( F_7 ( V_6 ) , V_6 ) , V_6 ) ;
F_8 ( * V_14 ) = V_15 ;
V_6 += V_19 ;
V_9 += V_19 ;
V_7 -= V_19 ;
}
V_8 = V_11 - V_7 ;
F_9 ( V_8 ) ;
return V_8 ;
}
void F_10 ( T_2 V_21 ,
T_2 V_22 )
{
F_11 ( V_21 != 0 ) ;
F_9 ( F_12 ( V_23 , V_22 , 0x00800000 ) ) ;
}
