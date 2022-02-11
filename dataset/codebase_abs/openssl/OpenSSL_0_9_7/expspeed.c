static double F_1 ( int V_1 )
{
double V_2 ;
#ifdef F_2
static struct V_3 V_4 , V_5 ;
if ( V_1 == V_6 )
{
F_3 ( & V_4 ) ;
return ( 0 ) ;
}
else
{
F_3 ( & V_5 ) ;
V_2 = ( ( double ) ( V_5 . V_7 - V_4 . V_7 ) ) / V_8 ;
return ( ( V_2 < 1e-3 ) ? 1e-3 : V_2 ) ;
}
#else
static struct V_9 V_4 , V_5 ;
long V_10 ;
if ( V_1 == V_6 )
{
F_4 ( & V_4 ) ;
return ( 0 ) ;
}
else
{
F_4 ( & V_5 ) ;
V_10 = ( long ) V_5 . V_11 - ( long ) V_4 . V_11 ;
V_2 = ( ( double ) ( V_5 . time - V_4 . time ) ) + ( ( double ) V_10 ) / 1000.0 ;
return ( ( V_2 < 0.001 ) ? 0.001 : V_2 ) ;
}
#endif
}
int main ( int V_12 , char * * V_13 )
{
T_1 * V_14 ;
T_2 * V_15 , * V_16 , * V_17 , * V_18 ;
#if 1
if ( ! F_5 ( 0 , 0 , 0 , 0 , 0 ) )
abort () ;
#endif
V_14 = F_6 () ;
V_15 = F_7 () ;
V_16 = F_7 () ;
V_17 = F_7 () ;
V_18 = F_7 () ;
while ( ! F_8 () )
F_9 ( L_1 ) ;
F_10 ( V_18 , V_15 , V_16 , V_17 , V_14 ) ;
return 0 ;
}
void F_10 ( T_2 * V_18 , T_2 * V_15 , T_2 * V_16 , T_2 * V_17 , T_1 * V_14 )
{
int V_10 , V_19 ;
double V_20 ;
long V_21 ;
V_21 = V_22 ;
for ( V_10 = V_23 ; V_10 < V_24 ; V_10 ++ )
{
#ifdef F_11
# ifdef F_12
if ( ! F_13 ( V_15 , 64 ) ) goto V_25;
if ( ! F_13 ( V_16 , V_26 ) ) goto V_25;
# define F_14 a
# define F_15 b
# else
# define F_14 NULL
# define F_15 NULL
# endif
if ( ! F_16 ( V_17 , V_27 [ V_10 ] , 0 , F_14 , F_15 , V_28 , NULL ) ) goto V_25;
putc ( '\n' , V_29 ) ;
fflush ( V_29 ) ;
#endif
for ( V_19 = 0 ; V_19 < V_21 ; V_19 ++ )
{
if ( V_19 % 50 == 0 )
{
if ( ! F_17 ( V_15 , V_27 [ V_10 ] , 1 , 0 ) ) goto V_25;
if ( ! F_17 ( V_16 , V_27 [ V_10 ] , 1 , 0 ) ) goto V_25;
#ifndef F_11
if ( ! F_17 ( V_17 , V_27 [ V_10 ] , 1 , 1 ) ) goto V_25;
#endif
#ifdef F_12
if ( ! F_18 ( V_15 , V_15 , V_17 , V_14 ) ) goto V_25;
if ( ! F_18 ( V_16 , V_16 , V_17 , V_14 ) ) goto V_25;
#else
if ( ! F_19 ( V_15 , V_15 , V_17 , V_14 ) ) goto V_25;
if ( ! F_19 ( V_16 , V_16 , V_17 , V_14 ) ) goto V_25;
#endif
if ( V_19 == 0 )
F_1 ( V_6 ) ;
}
#if F_20 ( V_30 )
if ( ! F_21 ( V_18 , V_15 , V_16 , V_17 , V_14 ) ) goto V_25;
#elif F_20 ( V_31 )
{
int V_10 = 0 ;
for ( V_10 = 0 ; V_10 < 50 ; V_10 ++ )
if ( ! F_22 ( V_18 , V_15 , V_16 , V_17 , V_14 ) ) goto V_25;
}
#elif F_20 ( V_32 )
{
int V_10 = 0 ;
for ( V_10 = 0 ; V_10 < 50 ; V_10 ++ )
{
if ( ! F_18 ( V_18 , V_15 , V_17 , V_14 ) ) goto V_25;
if ( ! F_18 ( V_18 , V_16 , V_17 , V_14 ) ) goto V_25;
}
}
#elif F_20 ( V_33 )
if ( ! F_23 ( V_18 , V_15 , V_16 , V_14 ) ) goto V_25;
if ( ! F_23 ( V_18 , V_16 , V_17 , V_14 ) ) goto V_25;
if ( ! F_23 ( V_18 , V_17 , V_15 , V_14 ) ) goto V_25;
#elif F_20 ( V_34 )
if ( - 2 == F_24 ( V_15 , V_16 , V_14 ) ) goto V_25;
if ( - 2 == F_24 ( V_16 , V_17 , V_14 ) ) goto V_25;
if ( - 2 == F_24 ( V_17 , V_15 , V_14 ) ) goto V_25;
#elif F_20 ( V_35 )
if ( ! F_25 ( V_18 , V_15 , V_17 , V_14 ) ) goto V_25;
if ( ! F_25 ( V_18 , V_16 , V_17 , V_14 ) ) goto V_25;
#else
if ( ! F_26 ( V_18 , V_15 , V_17 , V_14 ) ) goto V_25;
if ( ! F_26 ( V_18 , V_16 , V_17 , V_14 ) ) goto V_25;
#endif
}
V_20 = F_1 ( V_36 ) ;
printf (
#if F_20 ( V_30 )
L_2
#elif F_20 ( V_31 )
L_3
#elif F_20 ( V_32 )
L_4
#elif F_20 ( V_33 )
L_5
#elif F_20 ( V_34 )
L_6
#elif F_20 ( V_35 )
L_7
#else
L_8
#endif
L_9 ,
#ifdef F_12
V_26 ,
#endif
V_27 [ V_10 ] , V_27 [ V_10 ] , V_27 [ V_10 ] , V_20 * 1000.0 / V_21 , V_20 * V_37 [ V_10 ] / V_21 , V_21 ) ;
V_21 /= 7 ;
if ( V_21 <= 0 ) V_21 = 1 ;
}
return;
V_25:
F_27 ( V_29 ) ;
}
static void V_28 ( int V_38 , int V_39 , void * V_40 )
{
char V_17 = '*' ;
if ( V_38 == 0 ) V_17 = '.' ;
if ( V_38 == 1 ) V_17 = '+' ;
if ( V_38 == 2 ) V_17 = '*' ;
if ( V_38 == 3 ) V_17 = '\n' ;
putc ( V_17 , V_29 ) ;
fflush ( V_29 ) ;
( void ) V_39 ;
( void ) V_40 ;
}
