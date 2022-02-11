T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int T_2 F_2 ( T_3 * V_2 )
{
V_2 -> V_3 = 1 ;
V_2 -> V_4 = 0 ;
V_2 -> V_5 = NULL ;
#ifndef F_3
F_4 ( V_2 , L_1 , V_6 ) ;
#else
F_4 ( V_2 , L_1 , 0 ) ;
#endif
return ( 1 ) ;
}
static int T_2 F_5 ( T_3 * V_7 )
{
if ( V_7 == NULL ) return ( 0 ) ;
F_6 ( V_7 ) ;
return ( 1 ) ;
}
static int T_2 F_7 ( T_3 * V_8 , char * V_9 , int V_10 )
{
int V_11 = V_10 ;
char * V_12 = V_9 ;
char * V_13 ;
#if F_8 ( F_3 )
T_4 V_14 [ 2 ] ;
T_5 V_15 = V_16 ;
int V_17 = F_9 () ;
char V_18 [ 20 ] ;
#else
int V_19 ;
#endif
if( ( V_12 = ( char * ) Malloc ( V_10 + 1 ) ) == NULL ) {
return ( 0 ) ;
}
strncpy ( V_12 , V_9 , V_10 ) ;
V_12 [ V_10 ] = '\0' ;
#if F_8 ( F_3 )
if( strncmp ( V_12 , L_2 , 4 ) == 0 ) {
V_15 = V_16 ;
V_13 = V_12 + 4 ;
} else if( strncmp ( V_12 , L_3 , 4 ) == 0 ) {
V_15 = V_20 ;
V_13 = V_12 + 4 ;
} else if( strncmp ( V_12 , L_4 , 4 ) == 0 ) {
V_15 = V_21 ;
V_13 = V_12 + 4 ;
} else{
V_15 = V_16 ;
V_13 = V_12 ;
}
sprintf ( V_18 , L_5 , V_17 ) ;
V_14 [ 0 ] = V_18 ;
V_14 [ 1 ] = V_13 ;
if( V_8 -> V_5 )
F_10 ( V_8 -> V_5 , V_15 , 0 , 1024 , NULL , 2 , 0 ,
V_14 , NULL ) ;
#else
if( strncmp ( V_12 , L_2 , 4 ) == 0 ) {
V_19 = V_22 ;
V_13 = V_12 + 4 ;
} else if( strncmp ( V_12 , L_3 , 4 ) == 0 ) {
V_19 = V_23 ;
V_13 = V_12 + 4 ;
} else if( strncmp ( V_12 , L_4 , 4 ) == 0 ) {
V_19 = V_24 ;
V_13 = V_12 + 4 ;
} else{
V_19 = V_22 ;
V_13 = V_12 ;
}
F_11 ( V_19 , L_6 , V_13 ) ;
#endif
Free ( V_12 ) ;
return ( V_11 ) ;
}
static long T_2 F_12 ( T_3 * V_8 , int V_25 , long V_4 , char * V_5 )
{
switch ( V_25 )
{
case V_26 :
F_6 ( V_8 ) ;
F_4 ( V_8 , V_5 , V_4 ) ;
break;
default:
break;
}
return ( 0 ) ;
}
static int T_2 F_13 ( T_3 * V_27 , char * V_28 )
{
int V_29 , V_11 ;
V_29 = strlen ( V_28 ) ;
V_11 = F_7 ( V_27 , V_28 , V_29 ) ;
return ( V_11 ) ;
}
static int F_4 ( T_3 * V_27 , const char * V_30 , int V_31 )
{
#if F_8 ( F_3 )
if( ( V_27 -> V_5 = ( char * ) F_14 ( NULL , V_30 ) ) == NULL ) {
return ( 0 ) ;
}
#else
F_15 ( V_30 , V_32 | V_33 , V_31 ) ;
#endif
return ( 1 ) ;
}
static int F_6 ( T_3 * V_27 )
{
#if F_8 ( F_3 )
if( V_27 -> V_5 )
F_16 ( ( V_34 ) ( V_27 -> V_5 ) ) ;
V_27 -> V_5 = NULL ;
#else
F_17 () ;
#endif
return ( 1 ) ;
}
