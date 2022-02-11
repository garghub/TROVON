int F_1 ( const char * V_1 , long V_2 )
{
unsigned char V_3 [ V_4 ] ;
#ifndef F_2
struct V_5 V_6 ;
#endif
int V_7 , V_8 = 0 , V_9 ;
T_1 * V_10 = NULL ;
if ( V_1 == NULL )
return 0 ;
if ( V_2 == 0 )
return V_8 ;
V_10 = F_3 ( V_1 , L_1 ) ;
if ( V_10 == NULL )
goto V_11;
#ifndef F_2
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
if ( F_4 ( fileno ( V_10 ) , & V_6 ) < 0 )
goto V_11;
F_5 ( & V_6 , sizeof( V_6 ) , 0.0 ) ;
# if F_6 ( V_12 ) && F_6 ( V_13 )
if ( V_12 ( V_6 . V_14 ) || V_13 ( V_6 . V_14 ) ) {
V_2 = ( V_2 == - 1 ) ? 2048 : V_2 ;
setbuf ( V_10 , NULL ) ;
}
# endif
#endif
for (; ; ) {
if ( V_2 > 0 )
V_9 = ( V_2 < V_4 ) ? ( int ) V_2 : V_4 ;
else
V_9 = V_4 ;
V_7 = fread ( V_3 , 1 , V_9 , V_10 ) ;
if ( V_7 <= 0 )
break;
F_5 ( V_3 , V_7 , ( double ) V_7 ) ;
V_8 += V_7 ;
if ( V_2 > 0 ) {
V_2 -= V_9 ;
if ( V_2 <= 0 )
break;
}
}
F_7 ( V_3 , V_4 ) ;
V_11:
if ( V_10 != NULL )
fclose ( V_10 ) ;
return V_8 ;
}
int F_8 ( const char * V_1 )
{
unsigned char V_3 [ V_4 ] ;
int V_7 , V_8 = 0 , V_15 = 0 ;
T_1 * V_16 = NULL ;
int V_9 ;
#ifndef F_2
struct V_5 V_6 ;
# if F_6 ( V_12 ) && F_6 ( V_13 )
# ifdef F_9
# endif
V_7 = V_5 ( V_1 , & V_6 ) ;
if ( V_7 != - 1 ) {
if ( V_12 ( V_6 . V_14 ) || V_13 ( V_6 . V_14 ) ) {
return 1 ;
}
# endif
}
#endif
#if F_6 ( V_17 ) && ! F_6 ( F_2 ) && \
! F_6 ( V_18 ) && ! F_6 ( V_19 )
{
# ifndef F_10
# define F_10 0
# endif
int V_20 = F_11 ( V_1 , V_21 | V_17 | F_10 , 0600 ) ;
if ( V_20 != - 1 )
V_16 = fdopen ( V_20 , L_2 ) ;
}
#endif
#ifdef V_18
V_16 = F_3 ( V_1 , L_3 ) ;
#endif
if ( V_16 == NULL )
V_16 = F_3 ( V_1 , L_2 ) ;
if ( V_16 == NULL )
goto V_11;
#if ! F_6 ( V_22 ) && ! F_6 ( F_2 )
F_12 ( V_1 , 0600 ) ;
#endif
V_9 = V_23 ;
for (; ; ) {
V_7 = ( V_9 > V_4 ) ? V_4 : V_9 ;
V_9 -= V_4 ;
if ( F_13 ( V_3 , V_7 ) <= 0 )
V_15 = 1 ;
V_7 = fwrite ( V_3 , 1 , V_7 , V_16 ) ;
if ( V_7 <= 0 ) {
V_8 = 0 ;
break;
}
V_8 += V_7 ;
if ( V_9 <= 0 )
break;
}
fclose ( V_16 ) ;
F_7 ( V_3 , V_4 ) ;
V_11:
return ( V_15 ? - 1 : V_8 ) ;
}
const char * F_14 ( char * V_3 , T_2 V_24 )
{
char * V_25 = NULL ;
int V_26 = 1 ;
#ifdef F_15
struct V_5 V_6 ;
#endif
#if F_6 ( F_9 ) && F_6 ( V_27 )
T_3 V_28 ;
T_4 * V_29 , * V_30 ;
if ( ( V_29 = L_4 ,
V_28 = F_16 ( V_29 , NULL , 0 ) ) == 0
&& ( V_29 = L_5 , V_26 = 0 ,
V_28 = F_16 ( V_29 , NULL , 0 ) ) == 0
&& ( V_29 = L_6 ,
V_28 = F_16 ( V_29 , NULL , 0 ) ) == 0 ) {
V_29 = L_7 ,
V_28 = F_16 ( V_29 , NULL , 0 ) ;
}
if ( V_28 != 0 ) {
int V_31 ;
V_30 = F_17 ( V_28 * sizeof( T_4 ) ) ;
if ( F_16 ( V_29 , V_30 , V_28 ) < V_28
&& ( V_31 = F_18 ( V_27 , 0 , V_30 , - 1 , NULL , 0 ,
NULL , NULL ) ) != 0 ) {
V_25 = F_17 ( V_31 ) ;
if ( F_18 ( V_27 , 0 , V_30 , - 1 , V_25 , V_31 ,
NULL , NULL ) == 0 )
V_25 = NULL ;
}
}
#else
if ( F_19 () == 0 ) {
V_25 = getenv ( L_8 ) ;
} else {
V_26 = 0 ;
if ( F_19 () == 0 )
V_25 = getenv ( L_9 ) ;
}
#endif
#ifdef F_20
if ( ! V_26 && V_25 == NULL ) {
V_25 = F_20 ;
}
#endif
if ( V_25 != NULL && * V_25 ) {
T_2 V_28 = strlen ( V_25 ) ;
if ( V_26 && V_28 + 1 < V_24 ) {
if ( F_21 ( V_3 , V_25 , V_24 ) >= V_24 )
return NULL ;
} else if ( V_28 + strlen ( V_32 ) + 2 < V_24 ) {
F_21 ( V_3 , V_25 , V_24 ) ;
#ifndef V_18
F_22 ( V_3 , L_10 , V_24 ) ;
#endif
F_22 ( V_3 , V_32 , V_24 ) ;
}
} else {
V_3 [ 0 ] = '\0' ;
}
#ifdef F_15
if ( ! V_3 [ 0 ] )
if ( F_21 ( V_3 , L_11 , V_24 ) >= V_24 ) {
return NULL ;
}
if ( V_5 ( V_3 , & V_6 ) == - 1 )
if ( F_21 ( V_3 , L_11 , V_24 ) >= V_24 ) {
return NULL ;
}
#endif
return V_3 ;
}
