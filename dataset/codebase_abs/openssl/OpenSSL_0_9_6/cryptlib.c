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
{
F_4 ( V_8 , V_9 ) ;
return ( 0 ) ;
}
V_3 = F_6 ( V_7 , V_2 ) ;
if ( ! V_3 )
F_7 ( V_2 ) ;
else
V_3 += V_10 ;
return ( V_3 ) ;
}
int F_8 ( void )
{
return V_10 ;
}
int F_9 ( void )
{
int V_3 = 0 ;
T_1 * V_11 = NULL ;
if ( V_12 == NULL )
{
F_4 ( V_13 , V_14 ) ;
return ( 0 ) ;
}
F_10 ( V_15 ) ;
if ( ( V_16 == NULL )
&& ( ( V_16 = F_11 () ) == NULL ) )
{
F_12 ( V_15 ) ;
F_4 ( V_13 , V_9 ) ;
return ( 0 ) ;
}
F_12 ( V_15 ) ;
V_11 = ( T_1 * ) F_13 ( sizeof( T_1 ) ) ;
if ( V_11 == NULL )
{
F_4 ( V_13 , V_9 ) ;
return ( 0 ) ;
}
V_11 -> V_17 = 1 ;
V_11 -> V_18 = V_12 ( __FILE__ , __LINE__ ) ;
if ( V_11 -> V_18 == NULL )
{
F_7 ( V_11 ) ;
F_4 ( V_13 , V_9 ) ;
return ( 0 ) ;
}
F_10 ( V_15 ) ;
V_3 = F_14 ( V_16 , NULL ) ;
if ( V_3 == - 1 )
V_3 = F_15 ( V_16 , V_11 ) ;
F_12 ( V_15 ) ;
if ( ! V_3 )
{
F_16 ( V_11 -> V_18 , __FILE__ , __LINE__ ) ;
F_7 ( V_11 ) ;
}
else
V_3 += 1 ;
return - V_3 ;
}
void F_17 ( int V_3 )
{
T_1 * V_11 = NULL ;
if ( V_3 )
V_3 = - V_3 - 1 ;
if ( F_16 == NULL )
return;
F_10 ( V_15 ) ;
if ( V_16 == NULL || V_3 >= F_18 ( V_16 ) )
return;
V_11 = F_19 ( V_16 , V_3 ) ;
if ( V_11 != NULL )
{
-- V_11 -> V_17 ;
#ifdef F_20
if ( V_11 -> V_17 < 0 )
{
fprintf ( V_19 , L_1 ) ;
abort () ;
}
else
#endif
if ( -- ( V_11 -> V_17 ) <= 0 )
{
F_21 ( V_16 , V_3 , NULL ) ;
}
else
V_11 = NULL ;
}
F_12 ( V_15 ) ;
if ( V_11 )
{
F_16 ( V_11 -> V_18 , __FILE__ , __LINE__ ) ;
F_7 ( V_11 ) ;
}
}
struct V_20 * F_22 ( int V_3 )
{
T_1 * V_11 = NULL ;
if ( V_3 )
V_3 = - V_3 - 1 ;
F_10 ( V_15 ) ;
if ( V_16 != NULL && V_3 < F_18 ( V_16 ) )
V_11 = F_19 ( V_16 , V_3 ) ;
if ( V_11 )
V_11 -> V_17 ++ ;
F_12 ( V_15 ) ;
if ( V_11 )
return V_11 -> V_18 ;
return NULL ;
}
void F_23 ( void (* F_24)( int V_21 ,
struct V_20 * V_22 , const char * V_23 , int line ) )
{
V_24 = F_24 ;
}
void F_25 ( void (* F_24)
( struct V_20 * V_22 , const char * V_23 , int line ) )
{
F_16 = F_24 ;
}
void F_26 ( void (* F_24)( int V_21 , int type ,
const char * V_23 , int line ) )
{
V_25 = F_24 ;
}
void F_27 ( int (* F_24)( int * V_26 , int V_27 , int type ,
const char * V_23 , int line ) )
{
V_28 = F_24 ;
}
unsigned long F_28 ( void )
{
unsigned long V_29 = 0 ;
if ( V_30 == NULL )
{
#ifdef V_5
V_29 = ( unsigned long ) F_29 () ;
#elif F_2 ( V_4 )
V_29 = ( unsigned long ) F_30 () ;
#elif F_2 ( V_31 )
V_29 = 1L ;
#else
V_29 = ( unsigned long ) F_31 () ;
#endif
}
else
V_29 = V_30 () ;
return ( V_29 ) ;
}
void F_32 ( int V_21 , int type , const char * V_23 , int line )
{
#ifdef F_33
{
char * V_32 , * V_33 ;
if ( V_21 & V_34 )
V_33 = L_2 ;
else if ( V_21 & V_35 )
V_33 = L_3 ;
else
V_33 = L_4 ;
if ( V_21 & V_36 )
V_32 = L_5 ;
else if ( V_21 & V_37 )
V_32 = L_6 ;
else
V_32 = L_7 ;
fprintf ( V_19 , L_8 ,
F_28 () , V_32 , V_33 ,
F_34 ( type ) , V_23 , line ) ;
}
#endif
if ( type < 0 )
{
int V_3 = - type - 1 ;
struct V_20 * V_11
= F_22 ( V_3 ) ;
if ( V_11 )
{
V_24 ( V_21 , V_11 , V_23 , line ) ;
}
F_17 ( V_3 ) ;
}
else
if ( V_25 != NULL )
V_25 ( V_21 , type , V_23 , line ) ;
}
int F_35 ( int * V_11 , int V_38 , int type , const char * V_23 ,
int line )
{
int V_29 = 0 ;
if ( V_28 != NULL )
{
#ifdef F_33
int V_39 = * V_11 ;
#endif
V_29 = V_28 ( V_11 , V_38 , type , V_23 , line ) ;
#ifdef F_33
fprintf ( V_19 , L_9 ,
F_28 () ,
V_39 , V_38 , V_29 ,
F_34 ( type ) ,
V_23 , line ) ;
#endif
* V_11 = V_29 ;
}
else
{
F_32 ( V_34 | V_37 , type , V_23 , line ) ;
V_29 = * V_11 + V_38 ;
#ifdef F_33
fprintf ( V_19 , L_9 ,
F_28 () ,
* V_11 , V_38 , V_29 ,
F_34 ( type ) ,
V_23 , line ) ;
#endif
* V_11 = V_29 ;
F_32 ( V_35 | V_37 , type , V_23 , line ) ;
}
return ( V_29 ) ;
}
const char * F_34 ( int type )
{
if ( type < 0 )
return ( L_10 ) ;
else if ( type < V_10 )
return ( V_40 [ type ] ) ;
else if ( type - V_10 >= F_36 ( V_7 ) )
return ( L_7 ) ;
else
return ( F_37 ( V_7 , type - V_10 ) ) ;
}
BOOL T_2 F_38 ( T_3 V_41 , T_4 V_42 ,
T_5 V_43 )
{
switch( V_42 )
{
case V_44 :
break;
case V_45 :
break;
case V_46 :
F_39 ( 0 ) ;
break;
case V_47 :
break;
}
return ( TRUE ) ;
}
