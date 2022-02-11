int F_1 ( const char * V_1 , long V_2 )
{
T_1 unsigned char V_3 [ V_4 ] ;
#ifndef F_2
struct V_5 V_6 ;
#endif
int V_7 , V_8 = 0 , V_9 ;
T_2 * V_10 ;
if ( V_1 == NULL ) return ( 0 ) ;
#ifndef F_2
#ifdef F_3
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
#endif
if ( V_5 ( V_1 , & V_6 ) < 0 ) return ( 0 ) ;
F_4 ( & V_6 , sizeof( V_6 ) , 0.0 ) ;
#endif
if ( V_2 == 0 ) return ( V_8 ) ;
#ifdef F_5
V_10 = F_6 ( V_1 , L_1 , V_11 ) ;
#else
V_10 = fopen ( V_1 , L_1 ) ;
#endif
if ( V_10 == NULL ) goto V_12;
#if F_7 ( V_13 ) && F_7 ( V_14 ) && ! F_7 ( V_15 )
if ( V_6 . V_16 & ( V_13 | V_14 ) ) {
V_2 = ( V_2 == - 1 ) ? 2048 : V_2 ;
setvbuf ( V_10 , NULL , V_17 , 0 ) ;
}
#endif
for (; ; )
{
if ( V_2 > 0 )
V_9 = ( V_2 < V_4 ) ? ( int ) V_2 : V_4 ;
else
V_9 = V_4 ;
V_7 = fread ( V_3 , 1 , V_9 , V_10 ) ;
if ( V_7 <= 0 ) break;
#ifdef F_3
F_4 ( V_3 , V_7 , ( double ) V_7 ) ;
#else
F_4 ( V_3 , V_9 , ( double ) V_7 ) ;
#endif
V_8 += V_7 ;
if ( V_2 > 0 )
{
V_2 -= V_9 ;
if ( V_2 <= 0 ) break;
}
}
fclose ( V_10 ) ;
F_8 ( V_3 , V_4 ) ;
V_12:
return ( V_8 ) ;
}
int F_9 ( const char * V_1 )
{
unsigned char V_3 [ V_4 ] ;
int V_7 , V_8 = 0 , V_18 = 0 ;
T_2 * V_19 = NULL ;
int V_9 ;
#ifndef F_2
struct V_5 V_6 ;
V_7 = V_5 ( V_1 , & V_6 ) ;
if ( V_7 != - 1 ) {
#if F_7 ( V_20 ) && F_7 ( V_21 )
if ( V_20 ( V_6 . V_16 ) || V_21 ( V_6 . V_16 ) ) {
return ( 1 ) ;
}
#endif
}
#endif
#if F_7 ( V_22 ) && ! F_7 ( F_2 ) && ! F_7 ( F_5 )
{
#ifndef F_10
#define F_10 0
#endif
int V_23 = F_11 ( V_1 , V_24 | V_22 | F_10 , 0600 ) ;
if ( V_23 != - 1 )
V_19 = fdopen ( V_23 , L_2 ) ;
}
#endif
#ifdef F_5
V_19 = F_6 ( V_1 , L_3 , V_11 ) ;
if ( V_19 == NULL )
V_19 = F_6 ( V_1 , L_2 , V_11 ) ;
#else
if ( V_19 == NULL )
V_19 = fopen ( V_1 , L_2 ) ;
#endif
if ( V_19 == NULL ) goto V_12;
#ifndef F_12
F_13 ( V_1 , 0600 ) ;
#endif
V_9 = V_25 ;
for (; ; )
{
V_7 = ( V_9 > V_4 ) ? V_4 : V_9 ;
V_9 -= V_4 ;
if ( F_14 ( V_3 , V_7 ) <= 0 )
V_18 = 1 ;
V_7 = fwrite ( V_3 , 1 , V_7 , V_19 ) ;
if ( V_7 <= 0 )
{
V_8 = 0 ;
break;
}
V_8 += V_7 ;
if ( V_9 <= 0 ) break;
}
fclose ( V_19 ) ;
F_8 ( V_3 , V_4 ) ;
V_12:
return ( V_18 ? - 1 : V_8 ) ;
}
const char * F_15 ( char * V_3 , T_3 V_26 )
{
char * V_27 = NULL ;
int V_28 = 0 ;
#ifdef F_16
struct V_5 V_6 ;
#endif
if ( F_17 () == 0 )
V_27 = getenv ( L_4 ) ;
if ( V_27 != NULL && * V_27 && strlen ( V_27 ) + 1 < V_26 )
{
if ( F_18 ( V_3 , V_27 , V_26 ) >= V_26 )
return NULL ;
}
else
{
if ( F_17 () == 0 )
V_27 = getenv ( L_5 ) ;
#ifdef F_19
if ( V_27 == NULL )
{
V_27 = F_19 ;
}
#endif
if ( V_27 && * V_27 && strlen ( V_27 ) + strlen ( V_29 ) + 2 < V_26 )
{
F_18 ( V_3 , V_27 , V_26 ) ;
#ifndef F_5
F_20 ( V_3 , L_6 , V_26 ) ;
#endif
F_20 ( V_3 , V_29 , V_26 ) ;
V_28 = 1 ;
}
else
V_3 [ 0 ] = '\0' ;
}
#ifdef F_16
if ( ! V_28 )
if ( F_18 ( V_3 , L_7 , V_26 ) >= V_26 ) {
return ( NULL ) ;
}
if ( V_5 ( V_3 , & V_6 ) == - 1 )
if ( F_18 ( V_3 , L_7 , V_26 ) >= V_26 ) {
return ( NULL ) ;
}
#endif
return ( V_3 ) ;
}
