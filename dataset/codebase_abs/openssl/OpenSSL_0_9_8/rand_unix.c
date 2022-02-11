int F_1 ( void )
{
T_1 V_1 = 0 , V_2 ;
unsigned char V_3 [ V_4 ] ;
for ( V_2 = 0 ; V_2 < sizeof( V_3 ) ; V_2 ++ ) {
if ( V_2 % 4 == 0 )
V_1 = F_2 () ;
V_3 [ V_2 ] = V_1 ;
V_1 >>= 8 ;
}
F_3 ( V_3 , sizeof( V_3 ) , V_4 ) ;
memset ( V_3 , 0 , sizeof( V_3 ) ) ;
return 1 ;
}
int F_1 ( void )
{
unsigned long V_5 ;
T_2 V_6 = F_4 () ;
#if F_5 ( V_7 ) || F_5 ( V_8 )
unsigned char V_9 [ V_4 ] ;
int V_10 = 0 ;
#endif
#ifdef V_7
static const char * V_11 [] = { V_7 } ;
struct V_12 V_13 [ sizeof( V_11 ) / sizeof( V_11 [ 0 ] ) ] ;
int V_14 , V_2 ;
#endif
#ifdef V_8
static const char * V_15 [] = { V_8 , NULL } ;
const char * * V_16 = NULL ;
#endif
#ifdef V_7
memset ( V_13 , 0 , sizeof( V_13 ) ) ;
for ( V_2 = 0 ; V_2 < sizeof( V_11 ) / sizeof( V_11 [ 0 ] ) && V_10 < V_4 ; V_2 ++ )
{
if ( ( V_14 = F_6 ( V_11 [ V_2 ] , V_17
#ifdef F_7
| F_7
#endif
#ifdef F_8
| F_8
#endif
#ifdef F_9
| F_9
#endif
) ) >= 0 )
{
struct V_18 V_19 = { 0 , 10 * 1000 } ;
int V_20 , V_21 ;
T_3 V_22 ;
struct V_12 * V_23 = & V_13 [ V_2 ] ;
if ( F_10 ( V_14 , V_23 ) != 0 ) { F_11 ( V_14 ) ; continue; }
for ( V_21 = 0 ; V_21 < V_2 ; V_21 ++ )
{
if ( V_13 [ V_21 ] . V_24 == V_23 -> V_24 &&
V_13 [ V_21 ] . V_25 == V_23 -> V_25 )
break;
}
if ( V_21 < V_2 ) { F_11 ( V_14 ) ; continue; }
do
{
F_12 ( & V_22 ) ;
F_13 ( V_14 , & V_22 ) ;
V_20 = - 1 ;
if ( F_14 ( V_14 + 1 , & V_22 , NULL , NULL , & V_19 ) < 0 )
V_19 . V_26 = 0 ;
else if ( F_15 ( V_14 , & V_22 ) )
{
V_20 = F_16 ( V_14 , ( unsigned char * ) V_9 + V_10 ,
V_4 - V_10 ) ;
if ( V_20 > 0 )
V_10 += V_20 ;
}
if ( V_19 . V_26 == 10 * 1000 )
V_19 . V_26 = 0 ;
}
while ( ( V_20 > 0 || ( V_27 == V_28 || V_27 == V_29 ) )
&& V_19 . V_26 != 0 && V_10 < V_4 );
F_11 ( V_14 ) ;
}
}
#endif
#ifdef V_8
for ( V_16 = V_15 ; * V_16 && V_10 < V_4 ; V_16 ++ )
{
int V_20 ;
V_20 = F_17 ( * V_16 , ( unsigned char * ) V_9 + V_10 ,
V_4 - V_10 ) ;
if ( V_20 > 0 )
V_10 += V_20 ;
}
#endif
#if F_5 ( V_7 ) || F_5 ( V_8 )
if ( V_10 > 0 )
{
F_3 ( V_9 , sizeof V_9 , ( double ) V_10 ) ;
F_18 ( V_9 , V_10 ) ;
}
#endif
V_5 = V_6 ;
F_3 ( & V_5 , sizeof( V_5 ) , 0.0 ) ;
V_5 = F_19 () ;
F_3 ( & V_5 , sizeof( V_5 ) , 0.0 ) ;
V_5 = time ( NULL ) ;
F_3 ( & V_5 , sizeof( V_5 ) , 0.0 ) ;
#if F_5 ( V_7 ) || F_5 ( V_8 )
return 1 ;
#else
return 0 ;
#endif
}
int F_1 ( void )
{
return 0 ;
}
