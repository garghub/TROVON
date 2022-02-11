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
static T_2 V_20 = { 0x12 , 0x34 , 0x56 , 0x78 , 0x9a , 0xbc , 0xde , 0xf0 } ;
static T_2 V_21 = { 0x34 , 0x56 , 0x78 , 0x9a , 0xbc , 0xde , 0xf0 , 0x12 } ;
static T_2 V_22 = { 0x56 , 0x78 , 0x9a , 0xbc , 0xde , 0xf0 , 0x12 , 0x34 } ;
T_3 V_23 , V_24 , V_25 ;
double V_26 , V_27 [ 16 ] , V_28 = 0 ;
int V_29 [ 16 ] ;
char * V_30 [ 16 ] ;
int V_31 = 0 , V_13 , V_32 = 0 , V_33 ;
#ifndef F_7
long V_34 , V_35 , V_36 , V_37 , V_38 ;
#endif
for ( V_13 = 0 ; V_13 < 12 ; V_13 ++ )
{
V_27 [ V_13 ] = 0.0 ;
V_29 [ V_13 ] = 0 ;
}
#ifndef F_4
fprintf ( V_39 , L_1 ) ;
fprintf ( V_39 , L_2 ) ;
#endif
F_8 ( & V_20 , V_23 ) ;
F_8 ( & V_21 , V_24 ) ;
F_8 ( & V_22 , V_25 ) ;
#ifndef V_2
fprintf ( V_39 , L_3 ) ;
F_8 ( & V_20 , V_23 ) ;
V_17 = 10 ;
do {
long V_13 ;
unsigned long V_40 [ 2 ] ;
V_17 *= 2 ;
F_3 ( V_9 ) ;
for ( V_13 = V_17 ; V_13 ; V_13 -- )
F_9 ( V_40 , & ( V_23 [ 0 ] ) , V_41 ) ;
V_26 = F_3 ( V_42 ) ;
} while ( V_26 < 3.0 );
V_34 = V_17 ;
V_35 = V_17 * 3 ;
V_36 = V_17 * 3 * 8 / V_19 + 1 ;
V_37 = V_17 * 8 / V_19 + 1 ;
V_38 = V_17 / 20 + 1 ;
#define F_10 ( V_26 ) (count != (d))
#define F_11 ( V_26 ) (d)
#else
#define F_10 ( T_4 ) (run)
#define F_11 ( V_26 ) (count)
signal ( V_2 , F_1 ) ;
F_12 ( 10 ) ;
#endif
#ifdef F_13
F_14 ( V_43 , L_4 , 0 ) ;
F_14 ( V_44 , L_5 , 1 ) ;
F_14 ( V_45 , L_6 , 2 ) ;
V_32 += 3 ;
#endif
#ifdef F_15
F_14 ( V_46 , L_7 , 3 ) ;
F_14 ( V_47 , L_8 , 4 ) ;
F_14 ( V_48 , L_9 , 5 ) ;
V_32 += 3 ;
#endif
#ifdef F_16
F_14 ( V_49 , L_10 , 6 ) ;
F_14 ( V_50 , L_11 , 7 ) ;
F_14 ( V_51 , L_12 , 8 ) ;
V_32 += 3 ;
#endif
#ifdef F_17
F_14 ( V_52 , L_13 , 9 ) ;
F_14 ( V_53 , L_14 , 10 ) ;
F_14 ( V_54 , L_15 , 11 ) ;
V_32 += 3 ;
#endif
#ifdef F_13
V_30 [ 0 ] = L_16 ;
F_18 ( L_4 , 0 ) ;
V_28 = V_27 [ 0 ] ;
V_31 = 0 ;
V_30 [ 1 ] = L_17 ;
F_18 ( L_5 , 1 ) ;
if ( V_28 < V_27 [ 1 ] ) { V_28 = V_27 [ 1 ] ; V_31 = 1 ; }
V_30 [ 2 ] = L_18 ;
F_18 ( L_6 , 2 ) ;
if ( V_28 < V_27 [ 2 ] ) { V_28 = V_27 [ 2 ] ; V_31 = 2 ; }
#endif
#ifdef F_15
V_30 [ 3 ] = L_19 ;
F_18 ( L_7 , 3 ) ;
if ( V_28 < V_27 [ 3 ] ) { V_28 = V_27 [ 3 ] ; V_31 = 3 ; }
V_30 [ 4 ] = L_20 ;
F_18 ( L_8 , 4 ) ;
if ( V_28 < V_27 [ 4 ] ) { V_28 = V_27 [ 4 ] ; V_31 = 4 ; }
V_30 [ 5 ] = L_21 ;
F_18 ( L_9 , 5 ) ;
if ( V_28 < V_27 [ 5 ] ) { V_28 = V_27 [ 5 ] ; V_31 = 5 ; }
#endif
#ifdef F_16
V_30 [ 6 ] = L_22 ;
F_18 ( L_10 , 6 ) ;
if ( V_28 < V_27 [ 6 ] ) { V_28 = V_27 [ 6 ] ; V_31 = 6 ; }
V_30 [ 7 ] = L_23 ;
F_18 ( L_11 , 7 ) ;
if ( V_28 < V_27 [ 7 ] ) { V_28 = V_27 [ 7 ] ; V_31 = 7 ; }
V_30 [ 8 ] = L_24 ;
F_18 ( L_12 , 8 ) ;
if ( V_28 < V_27 [ 8 ] ) { V_28 = V_27 [ 8 ] ; V_31 = 8 ; }
#endif
#ifdef F_17
V_30 [ 9 ] = L_25 ;
F_18 ( L_13 , 9 ) ;
if ( V_28 < V_27 [ 9 ] ) { V_28 = V_27 [ 9 ] ; V_31 = 9 ; }
V_30 [ 10 ] = L_26 ;
F_18 ( L_14 , 10 ) ;
if ( V_28 < V_27 [ 10 ] ) { V_28 = V_27 [ 10 ] ; V_31 = 10 ; }
V_30 [ 11 ] = L_27 ;
F_18 ( L_15 , 11 ) ;
if ( V_28 < V_27 [ 11 ] ) { V_28 = V_27 [ 11 ] ; V_31 = 11 ; }
#endif
printf ( L_28 ) ;
printf ( L_29 , V_30 [ V_31 ] , V_27 [ V_31 ] ) ;
V_26 = V_27 [ V_31 ] ;
V_27 [ V_31 ] = - 2.0 ;
V_28 = - 1.0 ;
for (; ; )
{
for ( V_13 = 0 ; V_13 < 12 ; V_13 ++ )
{
if ( V_28 < V_27 [ V_13 ] ) { V_28 = V_27 [ V_13 ] ; V_33 = V_13 ; }
}
if ( V_28 < 0.0 ) break;
printf ( L_30 , V_30 [ V_33 ] , V_27 [ V_33 ] , V_27 [ V_33 ] / V_26 * 100.0 ) ;
V_27 [ V_33 ] = - 2.0 ;
V_28 = - 1.0 ;
}
switch ( V_31 )
{
case 0 :
printf ( L_31 ) ;
break;
case 1 :
printf ( L_32 ) ;
break;
case 2 :
printf ( L_33 ) ;
break;
case 3 :
printf ( L_34 ) ;
break;
case 4 :
printf ( L_35 ) ;
break;
case 5 :
printf ( L_36 ) ;
break;
case 6 :
printf ( L_37 ) ;
break;
case 7 :
printf ( L_38 ) ;
break;
case 8 :
printf ( L_39 ) ;
break;
case 9 :
printf ( L_40 ) ;
break;
case 10 :
printf ( L_41 ) ;
break;
case 11 :
printf ( L_42 ) ;
break;
}
exit ( 0 ) ;
#if F_19 ( F_2 ) || F_19 ( V_55 )
return ( 0 ) ;
#endif
}
