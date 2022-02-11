T_1 F_1 ( unsigned long V_1 )
{
unsigned long V_2 = V_3 ;
if ( V_4 )
return 0 ;
if ( V_1 >= V_5 && V_1 < V_5 + V_6 )
return V_2 + V_1 - V_5 ;
return 0 ;
}
unsigned long F_2 ( T_1 V_7 )
{
unsigned long V_2 = V_3 ;
if ( V_4 )
return 0 ;
if ( V_7 >= V_2 && V_7 < V_2 + V_6 )
return V_5 + V_7 - V_2 ;
return 0 ;
}
void T_2 F_3 ( void )
{
#ifdef F_4
unsigned long V_8 = F_5 ( V_9 ) & 0xfe000000 ;
unsigned long V_10 = 0xf0 | V_11 | V_12 | V_13 ;
#ifdef F_6
int V_14 = 29 ;
#else
int V_14 = 28 ;
#endif
unsigned long V_15 = 0 ;
unsigned long V_16 = V_17 ;
for (; V_14 < 32 && V_16 >= V_18 ; V_14 ++ ) {
F_7 ( V_9 , V_8 | ( V_14 << 8 ) ) ;
F_7 ( V_19 , ( unsigned long ) F_8 ( V_15 ) | V_20 ) ;
F_7 ( V_21 , V_22 | V_23 ) ;
F_7 ( V_24 , V_15 | V_10 | V_25 ) ;
V_15 += V_18 ;
V_16 -= V_18 ;
}
#endif
}
static void F_9 ( void )
{
unsigned long V_2 = V_3 ;
unsigned long V_26 = V_5 ;
unsigned long V_27 = F_10 ( V_28 ) ;
int V_29 ;
for ( V_29 = 0 ; V_29 < V_6 ; V_29 += V_30 )
F_11 ( V_26 + V_29 , V_2 + V_29 , V_27 ) ;
}
void F_12 ( unsigned int * V_15 , unsigned long V_31 )
{
unsigned int V_32 = * V_15 ;
V_32 &= 0xffff0000 ;
V_32 |= ( unsigned long ) F_8 ( V_31 ) >> 16 ;
F_13 ( V_15 , V_32 ) ;
}
unsigned long T_2 F_14 ( unsigned long V_33 )
{
unsigned long V_31 ;
if ( V_4 ) {
V_31 = 0 ;
F_9 () ;
#ifndef F_6
F_13 ( & V_34 , V_35 ) ;
#endif
} else {
V_31 = V_33 & ~ ( V_18 - 1 ) ;
}
F_12 ( & V_36 , V_31 ) ;
F_12 ( & V_37 , V_31 ) ;
if ( V_31 )
F_15 ( V_31 ) ;
return V_31 ;
}
void F_16 ( T_1 V_38 ,
T_1 V_39 )
{
F_17 ( V_38 != 0 ) ;
F_15 ( F_18 ( V_40 , V_39 , 0x01800000 ) ) ;
}
void F_19 ( unsigned long V_41 , T_3 * V_42 )
{
T_4 V_29 = ( T_4 ) ( F_20 ( V_43 ) ) ;
#ifdef F_21
T_3 * * V_44 = * ( T_3 * * * ) ( V_45 + 0xf0 ) ;
* ( V_44 + 1 ) = V_42 ;
#endif
F_7 ( V_46 , F_20 ( V_42 ) - V_29 ) ;
F_7 ( V_47 , V_41 ) ;
F_22 () ;
}
void F_23 ( void )
{
F_24 () ;
F_7 ( V_48 , V_49 ) ;
F_24 () ;
}
