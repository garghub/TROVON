int F_1 ( void )
{
unsigned char V_1 [ V_2 ] ;
T_1 V_3 ;
T_2 V_4 ;
static int V_5 = 1 ;
int V_6 ;
long V_7 = 0 ;
struct V_8 V_9 ;
unsigned V_10 ;
if ( V_5 ) {
V_5 = 0 ;
V_7 = F_2 () ;
if ( V_7 == 1804289383 ) {
F_3 ( V_11 , & V_9 ) ;
V_3 = F_4 () ;
V_4 = F_5 () ;
V_10 = V_9 . V_12 ^ V_9 . V_13 ^ V_3 ^ V_4 ;
F_6 ( V_10 ) ;
}
}
for ( V_6 = 0 ; V_6 < sizeof( V_1 ) ; V_6 ++ ) {
if ( V_6 % 4 == 0 )
V_7 = F_2 () ;
V_1 [ V_6 ] = V_7 ;
V_7 >>= 8 ;
}
F_7 ( V_1 , sizeof( V_1 ) , V_2 ) ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
return 1 ;
}
int F_1 ( void )
{
T_3 V_7 = 0 , V_6 ;
unsigned char V_1 [ V_2 ] ;
for ( V_6 = 0 ; V_6 < sizeof( V_1 ) ; V_6 ++ ) {
if ( V_6 % 4 == 0 )
V_7 = F_8 () ;
V_1 [ V_6 ] = V_7 ;
V_7 >>= 8 ;
}
F_7 ( V_1 , sizeof( V_1 ) , V_2 ) ;
memset ( V_1 , 0 , sizeof( V_1 ) ) ;
return 1 ;
}
int F_1 ( void )
{
unsigned long V_14 ;
T_1 V_3 = F_4 () ;
#if F_9 ( V_15 ) || F_9 ( V_16 )
unsigned char V_17 [ V_2 ] ;
int V_18 = 0 ;
#endif
#ifdef V_15
static const char * V_19 [] = { V_15 } ;
struct V_20 V_21 [ sizeof( V_19 ) / sizeof( V_19 [ 0 ] ) ] ;
int V_22 ;
unsigned int V_6 ;
#endif
#ifdef V_16
static const char * V_23 [] = { V_16 , NULL } ;
const char * * V_24 = NULL ;
#endif
#ifdef V_15
memset ( V_21 , 0 , sizeof( V_21 ) ) ;
for ( V_6 = 0 ; ( V_6 < sizeof( V_19 ) / sizeof( V_19 [ 0 ] ) ) &&
( V_18 < V_2 ) ; V_6 ++ )
{
if ( ( V_22 = F_10 ( V_19 [ V_6 ] , V_25
#ifdef F_11
| F_11
#endif
#ifdef F_12
| F_12
#endif
#ifdef F_13
| F_13
#endif
) ) >= 0 )
{
int V_26 = 10 * 1000 ;
int V_27 ;
unsigned int V_28 ;
struct V_20 * V_29 = & V_21 [ V_6 ] ;
if ( F_14 ( V_22 , V_29 ) != 0 ) { F_15 ( V_22 ) ; continue; }
for ( V_28 = 0 ; V_28 < V_6 ; V_28 ++ )
{
if ( V_21 [ V_28 ] . V_30 == V_29 -> V_30 &&
V_21 [ V_28 ] . V_31 == V_29 -> V_31 )
break;
}
if ( V_28 < V_6 ) { F_15 ( V_22 ) ; continue; }
do
{
int V_32 = 0 ;
#if F_9 ( V_33 )
V_32 = 1 ;
#elif F_9 ( V_34 )
struct V_35 V_36 ;
V_36 . V_22 = V_22 ;
V_36 . V_37 = V_38 ;
V_36 . V_39 = 0 ;
if ( F_16 ( & V_36 , 1 , V_26 / 1000 ) < 0 )
V_26 = 0 ;
else
V_32 = ( V_36 . V_39 & V_38 ) != 0 ;
#else
T_4 V_40 ;
struct V_41 V_42 ;
V_42 . V_12 = 0 ;
V_42 . V_43 = V_26 ;
if ( V_44 > 0 && ( unsigned ) V_22 >= V_44 )
{
V_32 = 1 ;
}
else
{
F_17 ( & V_40 ) ;
F_18 ( V_22 , & V_40 ) ;
if ( F_19 ( V_22 + 1 , & V_40 , NULL , NULL , & V_42 ) >= 0 )
{
V_26 = V_42 . V_43 ;
if ( F_20 ( V_22 , & V_40 ) )
V_32 = 1 ;
}
else
V_26 = 0 ;
}
#endif
if ( V_32 )
{
V_27 = F_21 ( V_22 , ( unsigned char * ) V_17 + V_18 , V_2 - V_18 ) ;
if ( V_27 > 0 )
V_18 += V_27 ;
#if F_9 ( V_33 )
if ( V_27 == 0 )
F_22 ( V_42 . V_43 ) ;
#endif
}
else
V_27 = - 1 ;
if ( V_26 == 10 * 1000 )
V_26 = 0 ;
}
while ( ( V_27 > 0 ||
( V_45 == V_46 || V_45 == V_47 ) ) && V_26 != 0 && V_18 < V_2 );
F_15 ( V_22 ) ;
}
}
#endif
#ifdef V_16
for ( V_24 = V_23 ; * V_24 && V_18 < V_2 ; V_24 ++ )
{
int V_27 ;
V_27 = F_23 ( * V_24 , ( unsigned char * ) V_17 + V_18 ,
V_2 - V_18 ) ;
if ( V_27 > 0 )
V_18 += V_27 ;
}
#endif
#if F_9 ( V_15 ) || F_9 ( V_16 )
if ( V_18 > 0 )
{
F_7 ( V_17 , sizeof V_17 , ( double ) V_18 ) ;
F_24 ( V_17 , V_18 ) ;
}
#endif
V_14 = V_3 ;
F_7 ( & V_14 , sizeof( V_14 ) , 0.0 ) ;
V_14 = F_5 () ;
F_7 ( & V_14 , sizeof( V_14 ) , 0.0 ) ;
V_14 = time ( NULL ) ;
F_7 ( & V_14 , sizeof( V_14 ) , 0.0 ) ;
#if F_9 ( V_48 )
{
T_5 V_49 ;
F_25 ( & V_49 ) ;
F_7 ( & V_49 , sizeof( V_49 ) , 0 ) ;
}
#endif
#if F_9 ( V_15 ) || F_9 ( V_16 )
return 1 ;
#else
return 0 ;
#endif
}
int F_1 ( void )
{
return 0 ;
}
