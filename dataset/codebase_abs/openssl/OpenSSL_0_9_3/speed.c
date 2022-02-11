T_1 F_1 ( int V_1 )
{
signal ( V_2 , F_1 ) ;
V_3 = 0 ;
#ifdef F_2
V_1 = V_1 ;
#endif
}
double F_3 ( int V_4 )
{
double V_5 ;
#ifdef F_4
static struct V_6 V_7 , V_8 ;
if ( V_4 == V_9 )
{
F_5 ( & V_7 ) ;
return ( 0 ) ;
}
else
{
F_5 ( & V_8 ) ;
V_5 = ( ( double ) ( V_8 . V_10 - V_7 . V_10 ) ) / V_11 ;
return ( ( V_5 == 0.0 ) ? 1e-6 : V_5 ) ;
}
#else
static struct V_12 V_7 , V_8 ;
long V_13 ;
if ( V_4 == V_9 )
{
F_6 ( & V_7 ) ;
return ( 0 ) ;
}
else
{
F_6 ( & V_8 ) ;
V_13 = ( long ) V_8 . V_14 - ( long ) V_7 . V_14 ;
V_5 = ( ( double ) ( V_8 . time - V_7 . time ) ) + ( ( double ) V_13 ) / 1e3 ;
return ( ( V_5 == 0.0 ) ? 1e-6 : V_5 ) ;
}
#endif
}
int main ( int V_15 , char * * V_16 )
{
long V_17 ;
static unsigned char V_18 [ V_19 ] ;
static T_2 V_20 = { 0x12 , 0x34 , 0x56 , 0x78 , 0x9a , 0xbc , 0xde , 0xf0 } ;
static T_2 V_21 = { 0x34 , 0x56 , 0x78 , 0x9a , 0xbc , 0xde , 0xf0 , 0x12 } ;
static T_2 V_22 = { 0x56 , 0x78 , 0x9a , 0xbc , 0xde , 0xf0 , 0x12 , 0x34 } ;
T_3 V_23 , V_24 , V_25 ;
double V_26 , V_27 , V_28 , V_29 , V_30 ;
#ifndef V_2
long V_31 , V_32 , V_33 , V_34 , V_35 ;
#endif
#ifndef F_4
printf ( L_1 ) ;
printf ( L_2 ) ;
#endif
F_7 ( ( V_36 * ) V_21 , V_24 ) ;
F_7 ( ( V_36 * ) V_22 , V_25 ) ;
#ifndef V_2
printf ( L_3 ) ;
F_7 ( ( V_36 * ) V_20 , V_23 ) ;
V_17 = 10 ;
do {
long V_13 ;
T_4 V_37 [ 2 ] ;
V_17 *= 2 ;
F_3 ( V_9 ) ;
for ( V_13 = V_17 ; V_13 ; V_13 -- )
F_8 ( V_37 , & ( V_23 [ 0 ] ) , V_38 ) ;
V_29 = F_3 ( V_39 ) ;
} while ( V_29 < 3.0 );
V_31 = V_17 ;
V_32 = V_17 * 3 ;
V_33 = V_17 * 3 * 8 / V_19 + 1 ;
V_34 = V_17 * 8 / V_19 + 1 ;
V_35 = V_17 / 20 + 1 ;
printf ( L_4 , V_31 ) ;
#define F_9 ( V_29 ) (count != (d))
#define F_10 ( V_29 ) (d)
#else
#define F_9 ( V_28 ) (run)
#define F_10 ( V_29 ) (count)
signal ( V_2 , F_1 ) ;
printf ( L_5 ) ;
F_11 ( 10 ) ;
#endif
F_3 ( V_9 ) ;
for ( V_17 = 0 , V_3 = 1 ; F_9 ( V_31 ) ; V_17 ++ )
F_7 ( ( V_36 * ) V_20 , V_23 ) ;
V_29 = F_3 ( V_39 ) ;
printf ( L_6 , V_17 , V_29 ) ;
V_26 = ( ( double ) F_10 ( V_31 ) ) / V_29 ;
#ifdef V_2
printf ( L_7 ) ;
F_11 ( 10 ) ;
#else
printf ( L_8 , V_32 ) ;
#endif
F_3 ( V_9 ) ;
for ( V_17 = 0 , V_3 = 1 ; F_9 ( V_32 ) ; V_17 ++ )
{
T_4 V_37 [ 2 ] ;
F_8 ( V_37 , & ( V_23 [ 0 ] ) , V_38 ) ;
}
V_29 = F_3 ( V_39 ) ;
printf ( L_9 , V_17 , V_29 ) ;
V_27 = ( ( double ) F_10 ( V_32 ) * 8 ) / V_29 ;
#ifdef V_2
printf ( L_10 ,
V_19 ) ;
F_11 ( 10 ) ;
#else
printf ( L_11 , V_33 ,
V_19 ) ;
#endif
F_3 ( V_9 ) ;
for ( V_17 = 0 , V_3 = 1 ; F_9 ( V_33 ) ; V_17 ++ )
F_12 ( ( V_36 * ) V_18 , ( V_36 * ) V_18 , V_19 , & ( V_23 [ 0 ] ) ,
( V_36 * ) & ( V_20 [ 0 ] ) , V_38 ) ;
V_29 = F_3 ( V_39 ) ;
printf ( L_12 ,
V_17 , V_19 , V_29 ) ;
V_28 = ( ( double ) F_10 ( V_33 ) * V_19 ) / V_29 ;
#ifdef V_2
printf ( L_13 ,
V_19 ) ;
F_11 ( 10 ) ;
#else
printf ( L_14 , V_34 ,
V_19 ) ;
#endif
F_3 ( V_9 ) ;
for ( V_17 = 0 , V_3 = 1 ; F_9 ( V_34 ) ; V_17 ++ )
F_13 ( ( V_36 * ) V_18 , ( V_36 * ) V_18 , V_19 ,
& ( V_23 [ 0 ] ) ,
& ( V_24 [ 0 ] ) ,
& ( V_25 [ 0 ] ) ,
( V_36 * ) & ( V_20 [ 0 ] ) ,
V_38 ) ;
V_29 = F_3 ( V_39 ) ;
printf ( L_15 ,
V_17 , V_19 , V_29 ) ;
V_29 = ( ( double ) F_10 ( V_34 ) * V_19 ) / V_29 ;
#ifdef V_2
printf ( L_16 ) ;
F_11 ( 10 ) ;
#else
printf ( L_17 , V_35 ) ;
#endif
F_3 ( V_9 ) ;
for ( V_17 = 0 , V_3 = 1 ; F_9 ( V_35 ) ; V_17 ++ )
F_14 ( L_18 , L_19 ) ;
V_30 = F_3 ( V_39 ) ;
printf ( L_20 , V_17 , V_30 ) ;
V_30 = ( ( double ) F_10 ( V_35 ) ) / V_30 ;
printf ( L_21 , V_26 , 1.0e6 / V_26 ) ;
printf ( L_22 , V_27 , 8.0e6 / V_27 ) ;
printf ( L_23 , V_28 , 8.0e6 / V_28 ) ;
printf ( L_24 , V_29 , 8.0e6 / V_29 ) ;
printf ( L_25 , V_30 , 1.0e6 / V_30 ) ;
exit ( 0 ) ;
#if F_15 ( F_2 ) || F_15 ( V_40 )
return ( 0 ) ;
#endif
}
