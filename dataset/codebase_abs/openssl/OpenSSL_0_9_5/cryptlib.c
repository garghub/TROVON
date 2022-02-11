int F_1 ( char * V_1 )
{
char * V_2 ;
int V_3 ;
#if F_2 ( V_4 ) || F_2 ( V_5 )
V_6 = ( double ) V_1 [ 0 ] * ( double ) V_1 [ 1 ] ;
#endif
if ( ( V_7 == NULL ) && ( ( V_7 = F_3 () ) == NULL ) )
{
F_4 ( V_8 , V_9 ) ;
return ( 0 ) ;
}
if ( ( V_2 = F_5 ( V_1 ) ) == NULL )
return ( 0 ) ;
V_3 = F_6 ( V_7 , V_2 ) ;
if ( ! V_3 )
Free ( V_2 ) ;
else
V_3 += V_10 ;
return ( V_3 ) ;
}
int F_7 ( void )
{
return V_10 ;
}
void F_8 ( void (* F_9)( int V_11 , int type ,
const char * V_12 , int line ) )
{
V_13 = F_9 ;
}
void F_10 ( int (* F_9)( int * V_14 , int V_15 , int type ,
const char * V_12 , int line ) )
{
V_16 = F_9 ;
}
unsigned long F_11 ( void )
{
unsigned long V_17 = 0 ;
if ( V_18 == NULL )
{
#ifdef V_5
V_17 = ( unsigned long ) F_12 () ;
#elif F_2 ( V_4 )
V_17 = ( unsigned long ) F_13 () ;
#elif F_2 ( V_19 )
V_17 = 1L ;
#else
V_17 = ( unsigned long ) F_14 () ;
#endif
}
else
V_17 = V_18 () ;
return ( V_17 ) ;
}
void F_15 ( int V_11 , int type , const char * V_12 , int line )
{
#ifdef F_16
{
char * V_20 , * V_21 ;
if ( V_11 & V_22 )
V_21 = L_1 ;
else if ( V_11 & V_23 )
V_21 = L_2 ;
else
V_21 = L_3 ;
if ( V_11 & V_24 )
V_20 = L_4 ;
else if ( V_11 & V_25 )
V_20 = L_5 ;
else
V_20 = L_6 ;
fprintf ( V_26 , L_7 ,
F_11 () , V_20 , V_21 ,
F_17 ( type ) , V_12 , line ) ;
}
#endif
if ( V_13 != NULL )
V_13 ( V_11 , type , V_12 , line ) ;
}
int F_18 ( int * V_27 , int V_28 , int type , const char * V_12 ,
int line )
{
int V_17 ;
if ( V_16 != NULL )
{
#ifdef F_16
int V_29 = * V_27 ;
#endif
V_17 = V_16 ( V_27 , V_28 , type , V_12 , line ) ;
#ifdef F_16
fprintf ( V_26 , L_8 ,
F_11 () ,
V_29 , V_28 , V_17 ,
F_17 ( type ) ,
V_12 , line ) ;
#endif
* V_27 = V_17 ;
}
else
{
F_15 ( V_22 | V_25 , type , V_12 , line ) ;
V_17 = * V_27 + V_28 ;
#ifdef F_16
fprintf ( V_26 , L_8 ,
F_11 () ,
* V_27 , V_28 , V_17 ,
F_17 ( type ) ,
V_12 , line ) ;
#endif
* V_27 = V_17 ;
F_15 ( V_23 | V_25 , type , V_12 , line ) ;
}
return ( V_17 ) ;
}
const char * F_17 ( int type )
{
if ( type < 0 )
return ( L_6 ) ;
else if ( type < V_10 )
return ( V_30 [ type ] ) ;
else if ( type - V_10 >= F_19 ( V_7 ) )
return ( L_6 ) ;
else
return ( F_20 ( V_7 , type - V_10 ) ) ;
}
BOOL T_1 F_21 ( T_2 V_31 , T_3 V_32 ,
T_4 V_33 )
{
switch( V_32 )
{
case V_34 :
break;
case V_35 :
break;
case V_36 :
F_22 ( 0 ) ;
break;
case V_37 :
break;
}
return ( TRUE ) ;
}
