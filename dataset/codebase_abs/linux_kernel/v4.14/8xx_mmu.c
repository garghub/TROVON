T_1 F_1 ( unsigned long V_1 )
{
unsigned long V_2 = V_3 ;
if ( V_4 )
return 0 ;
if ( V_1 >= V_5 && V_1 < V_5 + V_6 )
return V_2 + V_1 - V_5 ;
if ( V_1 >= V_7 && V_1 < V_7 + V_8 )
return F_2 ( V_1 ) ;
return 0 ;
}
unsigned long F_3 ( T_1 V_9 )
{
unsigned long V_2 = V_3 ;
if ( V_4 )
return 0 ;
if ( V_9 >= V_2 && V_9 < V_2 + V_6 )
return V_5 + V_9 - V_2 ;
if ( V_9 < V_8 )
return ( unsigned long ) F_4 ( V_9 ) ;
return 0 ;
}
void T_2 F_5 ( void )
{
#ifdef F_6
unsigned long V_10 = F_7 ( V_11 ) & 0xfe000000 ;
unsigned long V_12 = 0xf0 | V_13 | V_14 | V_15 ;
#ifdef F_8
int V_16 = 29 ;
#else
int V_16 = 28 ;
#endif
unsigned long V_17 = 0 ;
unsigned long V_18 = V_19 ;
for (; V_16 < 32 && V_18 >= V_20 ; V_16 ++ ) {
F_9 ( V_11 , V_10 | ( V_16 << 8 ) ) ;
F_9 ( V_21 , ( unsigned long ) F_4 ( V_17 ) | V_22 ) ;
F_9 ( V_23 , V_24 | V_25 ) ;
F_9 ( V_26 , V_17 | V_12 | V_27 ) ;
V_17 += V_20 ;
V_18 -= V_20 ;
}
#endif
}
static void T_2 F_10 ( void )
{
unsigned long V_2 = V_3 ;
unsigned long V_28 = V_5 ;
unsigned long V_29 = F_11 ( V_30 ) ;
int V_31 ;
for ( V_31 = 0 ; V_31 < V_6 ; V_31 += V_32 )
F_12 ( V_28 + V_31 , V_2 + V_31 , V_29 ) ;
}
static void T_2 F_13 ( unsigned int * V_17 , unsigned long V_33 )
{
unsigned int V_34 = * V_17 ;
V_34 &= 0xffff0000 ;
V_34 |= ( unsigned long ) F_4 ( V_33 ) >> 16 ;
F_14 ( V_17 , V_34 ) ;
}
unsigned long T_2 F_15 ( unsigned long V_35 )
{
unsigned long V_33 ;
if ( V_4 ) {
V_33 = 0 ;
F_10 () ;
#ifndef F_8
F_14 ( & V_36 , V_37 ) ;
#endif
#ifndef F_16
F_13 ( & V_38 , 0 ) ;
#endif
} else {
V_33 = V_35 & ~ ( V_20 - 1 ) ;
}
F_13 ( & V_39 , V_33 ) ;
F_13 ( & V_40 , V_33 ) ;
if ( V_33 )
F_17 ( V_33 ) ;
V_8 = V_33 ;
return V_33 ;
}
void T_2 F_18 ( T_1 V_41 ,
T_1 V_42 )
{
F_19 ( V_41 != 0 ) ;
F_17 ( F_20 ( V_43 , V_42 , 0x01800000 ) ) ;
}
void F_21 ( unsigned long V_44 , T_3 * V_45 )
{
T_4 V_31 = ( T_4 ) ( F_2 ( V_46 ) ) ;
#ifdef F_22
T_3 * * V_47 = * ( T_3 * * * ) ( V_48 + 0xf0 ) ;
* ( V_47 + 1 ) = V_45 ;
#endif
F_9 ( V_49 , F_2 ( V_45 ) - V_31 ) ;
F_9 ( V_50 , V_44 ) ;
F_23 () ;
}
void F_24 ( void )
{
F_25 () ;
F_9 ( V_51 , V_52 ) ;
F_25 () ;
}
