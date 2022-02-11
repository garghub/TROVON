T_1 F_1 ( int V_1 )
{
signal ( V_2 , F_1 ) ;
V_3 = 0 ;
# ifdef F_2
V_1 = V_1 ;
# endif
}
double F_3 ( int V_4 )
{
double V_5 ;
#ifdef F_4
static struct V_6 V_7 , V_8 ;
if ( V_4 == V_9 ) {
F_5 ( & V_7 ) ;
return ( 0 ) ;
} else {
F_5 ( & V_8 ) ;
V_5 = ( ( double ) ( V_8 . V_10 - V_7 . V_10 ) ) / V_11 ;
return ( ( V_5 == 0.0 ) ? 1e-6 : V_5 ) ;
}
#else
static struct V_12 V_7 , V_8 ;
long V_13 ;
if ( V_4 == V_9 ) {
F_6 ( & V_7 ) ;
return ( 0 ) ;
} else {
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
static unsigned char V_20 [] = {
0x12 , 0x34 , 0x56 , 0x78 , 0x9a , 0xbc , 0xde , 0xf0 ,
0xfe , 0xdc , 0xba , 0x98 , 0x76 , 0x54 , 0x32 , 0x10 ,
} ;
T_2 V_21 ;
double V_22 , V_23 , V_24 , V_25 , V_26 ;
#ifndef V_2
long V_27 , V_28 , V_29 , V_30 ;
#endif
#ifndef F_4
printf ( L_1 ) ;
printf ( L_2 ) ;
#endif
#ifndef V_2
printf ( L_3 ) ;
F_7 ( V_20 , & V_21 ) ;
V_17 = 10 ;
do {
long V_13 ;
T_3 V_31 [ 2 ] ;
V_17 *= 2 ;
F_3 ( V_9 ) ;
for ( V_13 = V_17 ; V_13 ; V_13 -- )
F_8 ( V_31 , & V_21 ) ;
V_26 = F_3 ( V_32 ) ;
} while ( V_26 < 3.0 );
V_27 = V_17 / 4 ;
V_28 = V_17 / 200 ;
V_29 = V_17 ;
V_30 = V_17 * 8 / V_19 + 1 ;
printf ( L_4 , V_27 ) ;
# define F_9 ( V_26 ) (count <= (d))
# define F_10 ( V_26 ) (d)
#else
# define F_9 ( V_25 ) (run)
# define F_10 ( V_26 ) (count)
signal ( V_2 , F_1 ) ;
printf ( L_5 ) ;
F_11 ( 10 ) ;
#endif
F_3 ( V_9 ) ;
for ( V_17 = 0 , V_3 = 1 ; F_9 ( V_27 ) ; V_17 += 4 ) {
F_7 ( V_20 , & V_21 ) ;
F_7 ( V_20 , & V_21 ) ;
F_7 ( V_20 , & V_21 ) ;
F_7 ( V_20 , & V_21 ) ;
}
V_26 = F_3 ( V_32 ) ;
printf ( L_6 , V_17 , V_26 ) ;
V_22 = ( ( double ) F_10 ( V_27 ) ) / V_26 ;
#ifdef V_2
printf ( L_7 ) ;
F_11 ( 10 ) ;
#else
printf ( L_8 , V_28 ) ;
#endif
F_3 ( V_9 ) ;
for ( V_17 = 0 , V_3 = 1 ; F_9 ( V_28 ) ; V_17 += 4 ) {
F_12 ( & V_21 , & V_21 ) ;
F_12 ( & V_21 , & V_21 ) ;
F_12 ( & V_21 , & V_21 ) ;
F_12 ( & V_21 , & V_21 ) ;
}
V_26 = F_3 ( V_32 ) ;
printf ( L_9 , V_17 , V_26 ) ;
V_23 = ( ( double ) F_10 ( V_28 ) ) / V_26 ;
#ifdef V_2
printf ( L_10 ) ;
F_11 ( 10 ) ;
#else
printf ( L_11 , V_29 ) ;
#endif
F_3 ( V_9 ) ;
for ( V_17 = 0 , V_3 = 1 ; F_9 ( V_29 ) ; V_17 += 4 ) {
unsigned long V_31 [ 2 ] ;
F_8 ( V_31 , & V_21 ) ;
F_8 ( V_31 , & V_21 ) ;
F_8 ( V_31 , & V_21 ) ;
F_8 ( V_31 , & V_21 ) ;
}
V_26 = F_3 ( V_32 ) ;
printf ( L_12 , V_17 , V_26 ) ;
V_24 = ( ( double ) F_10 ( V_29 ) * 8 ) / V_26 ;
#ifdef V_2
printf ( L_13 ,
V_19 ) ;
F_11 ( 10 ) ;
#else
printf ( L_14 , V_30 ,
V_19 ) ;
#endif
F_3 ( V_9 ) ;
for ( V_17 = 0 , V_3 = 1 ; F_9 ( V_30 ) ; V_17 ++ )
F_13 ( V_18 , V_18 , V_19 , & V_21 , & ( V_20 [ 0 ] ) , V_33 ) ;
V_26 = F_3 ( V_32 ) ;
printf ( L_15 ,
V_17 , V_19 , V_26 ) ;
V_25 = ( ( double ) F_10 ( V_30 ) * V_19 ) / V_26 ;
printf ( L_16 , V_22 , 1.0e6 / V_22 ) ;
printf ( L_17 , V_23 ,
1.0e6 / V_23 ) ;
printf ( L_18 , V_24 , 8.0e6 / V_24 ) ;
printf ( L_19 , V_25 , 8.0e6 / V_25 ) ;
exit ( 0 ) ;
#if F_14 ( F_2 ) || F_14 ( V_34 )
return ( 0 ) ;
#endif
}
