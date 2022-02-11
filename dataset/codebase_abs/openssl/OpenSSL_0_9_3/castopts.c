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
V_5 = ( ( double ) ( V_8 . time - V_7 . time ) ) + ( ( double ) V_13 ) / 1000.0 ;
return ( ( V_5 == 0.0 ) ? 1e-6 : V_5 ) ;
}
#endif
}
int main ( int V_15 , char * * V_16 )
{
long V_17 ;
static unsigned char V_18 [ V_19 ] ;
static char V_20 [ 16 ] = { 0x12 , 0x34 , 0x56 , 0x78 , 0x9a , 0xbc , 0xde , 0xf0 ,
0x12 , 0x34 , 0x56 , 0x78 , 0x9a , 0xbc , 0xde , 0xf0 } ;
T_2 V_21 ;
double V_22 , V_23 [ 16 ] , V_24 = 0 ;
int V_25 [ 16 ] ;
char * V_26 [ 16 ] ;
int V_27 = 0 , V_13 , V_28 = 0 , V_29 ;
#ifndef F_7
long V_30 , V_31 , V_32 , V_33 , V_34 ;
#endif
for ( V_13 = 0 ; V_13 < 12 ; V_13 ++ )
{
V_23 [ V_13 ] = 0.0 ;
V_25 [ V_13 ] = 0 ;
}
#ifndef F_4
fprintf ( V_35 , L_1 ) ;
fprintf ( V_35 , L_2 ) ;
#endif
F_8 ( & V_21 , 16 , V_20 ) ;
#ifndef V_2
fprintf ( V_35 , L_3 ) ;
V_17 = 10 ;
do {
long V_13 ;
unsigned long V_36 [ 2 ] ;
V_17 *= 2 ;
F_3 ( V_9 ) ;
for ( V_13 = V_17 ; V_13 ; V_13 -- )
F_9 ( V_36 , & V_21 ) ;
V_22 = F_3 ( V_37 ) ;
} while ( V_22 < 3.0 );
V_30 = V_17 ;
V_31 = V_17 * 3 ;
V_32 = V_17 * 3 * 8 / V_19 + 1 ;
V_33 = V_17 * 8 / V_19 + 1 ;
V_34 = V_17 / 20 + 1 ;
#define F_10 ( V_22 ) (count != (d))
#define F_11 ( V_22 ) (d)
#else
#define F_10 ( T_3 ) (run)
#define F_11 ( V_22 ) (count)
signal ( V_2 , F_1 ) ;
F_12 ( 10 ) ;
#endif
F_13 ( V_38 , L_4 , 0 ) ;
F_13 ( V_39 , L_5 , 1 ) ;
F_13 ( V_40 , L_6 , 2 ) ;
V_28 += 3 ;
V_26 [ 0 ] = L_7 ;
F_14 ( L_4 , 0 ) ;
V_24 = V_23 [ 0 ] ;
V_27 = 0 ;
V_26 [ 1 ] = L_8 ;
F_14 ( L_9 , 1 ) ;
if ( V_24 < V_23 [ 1 ] ) { V_24 = V_23 [ 1 ] ; V_27 = 1 ; }
V_26 [ 2 ] = L_10 ;
F_14 ( L_11 , 2 ) ;
if ( V_24 < V_23 [ 2 ] ) { V_24 = V_23 [ 2 ] ; V_27 = 2 ; }
printf ( L_12 ) ;
printf ( L_13 , V_26 [ V_27 ] , V_23 [ V_27 ] ) ;
V_22 = V_23 [ V_27 ] ;
V_23 [ V_27 ] = - 2.0 ;
V_24 = - 1.0 ;
for (; ; )
{
for ( V_13 = 0 ; V_13 < 3 ; V_13 ++ )
{
if ( V_24 < V_23 [ V_13 ] ) { V_24 = V_23 [ V_13 ] ; V_29 = V_13 ; }
}
if ( V_24 < 0.0 ) break;
printf ( L_14 , V_26 [ V_29 ] , V_23 [ V_29 ] , V_23 [ V_29 ] / V_22 * 100.0 ) ;
V_23 [ V_29 ] = - 2.0 ;
V_24 = - 1.0 ;
}
switch ( V_27 )
{
case 0 :
printf ( L_15 ) ;
break;
case 1 :
printf ( L_16 ) ;
break;
case 2 :
printf ( L_17 ) ;
break;
}
exit ( 0 ) ;
#if F_15 ( F_2 ) || F_15 ( V_41 )
return ( 0 ) ;
#endif
}
