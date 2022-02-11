T_1 * F_1 ( const T_2 * V_1 , const T_2 * V_2 , T_2 * V_3 )
{
T_1 * V_4 = NULL ;
F_2 ( V_3 ) ;
if ( ( V_4 = ( T_1 * ) F_3 ( sizeof( T_1 ) ) ) == NULL )
{
F_4 ( V_5 , V_6 ) ;
return ( NULL ) ;
}
memset ( V_4 , 0 , sizeof( T_1 ) ) ;
if ( V_1 != NULL )
{
if ( ( V_4 -> V_1 = F_5 ( V_1 ) ) == NULL ) goto V_7;
}
if ( V_2 != NULL )
{
if ( ( V_4 -> V_2 = F_5 ( V_2 ) ) == NULL ) goto V_7;
}
V_4 -> V_3 = V_3 ;
V_4 -> V_8 = V_9 ;
return ( V_4 ) ;
V_7:
if ( V_4 != NULL ) F_6 ( V_4 ) ;
return ( NULL ) ;
}
void F_6 ( T_1 * V_10 )
{
if( V_10 == NULL )
return;
if ( V_10 -> V_1 != NULL ) F_7 ( V_10 -> V_1 ) ;
if ( V_10 -> V_2 != NULL ) F_7 ( V_10 -> V_2 ) ;
if ( V_10 -> V_11 != NULL ) F_7 ( V_10 -> V_11 ) ;
F_8 ( V_10 ) ;
}
int F_9 ( T_1 * V_12 , T_3 * V_13 )
{
int V_4 = 0 ;
if ( ( V_12 -> V_1 == NULL ) || ( V_12 -> V_2 == NULL ) )
{
F_4 ( V_14 , V_15 ) ;
goto V_7;
}
if ( -- ( V_12 -> V_8 ) == 0 && V_12 -> V_11 != NULL &&
! ( V_12 -> V_16 & V_17 ) )
{
if ( ! F_10 ( V_12 , NULL , NULL , V_13 , NULL , NULL ) )
goto V_7;
}
else if ( ! ( V_12 -> V_16 & V_18 ) )
{
if ( ! F_11 ( V_12 -> V_1 , V_12 -> V_1 , V_12 -> V_1 , V_12 -> V_3 , V_13 ) ) goto V_7;
if ( ! F_11 ( V_12 -> V_2 , V_12 -> V_2 , V_12 -> V_2 , V_12 -> V_3 , V_13 ) ) goto V_7;
}
V_4 = 1 ;
V_7:
if ( V_12 -> V_8 == 0 )
V_12 -> V_8 = V_9 ;
return ( V_4 ) ;
}
int F_12 ( T_2 * V_19 , T_1 * V_12 , T_3 * V_13 )
{
return F_13 ( V_19 , NULL , V_12 , V_13 ) ;
}
int F_13 ( T_2 * V_19 , T_2 * V_10 , T_1 * V_12 , T_3 * V_13 )
{
int V_4 = 1 ;
F_2 ( V_19 ) ;
if ( ( V_12 -> V_1 == NULL ) || ( V_12 -> V_2 == NULL ) )
{
F_4 ( V_20 , V_15 ) ;
return ( 0 ) ;
}
if ( V_10 != NULL )
{
if ( ! F_14 ( V_10 , V_12 -> V_2 ) ) V_4 = 0 ;
}
if ( ! F_11 ( V_19 , V_19 , V_12 -> V_1 , V_12 -> V_3 , V_13 ) ) V_4 = 0 ;
return V_4 ;
}
int F_15 ( T_2 * V_19 , T_1 * V_12 , T_3 * V_13 )
{
return F_16 ( V_19 , NULL , V_12 , V_13 ) ;
}
int F_16 ( T_2 * V_19 , const T_2 * V_10 , T_1 * V_12 , T_3 * V_13 )
{
int V_4 ;
F_2 ( V_19 ) ;
if ( ( V_12 -> V_1 == NULL ) || ( V_12 -> V_2 == NULL ) )
{
F_4 ( V_21 , V_15 ) ;
return ( 0 ) ;
}
if ( V_10 != NULL )
V_4 = F_11 ( V_19 , V_19 , V_10 , V_12 -> V_3 , V_13 ) ;
else
V_4 = F_11 ( V_19 , V_19 , V_12 -> V_2 , V_12 -> V_3 , V_13 ) ;
if ( V_4 >= 0 )
{
if ( ! F_9 ( V_12 , V_13 ) )
return ( 0 ) ;
}
F_2 ( V_19 ) ;
return ( V_4 ) ;
}
unsigned long F_17 ( const T_1 * V_12 )
{
return V_12 -> V_22 ;
}
void F_18 ( T_1 * V_12 , unsigned long V_19 )
{
V_12 -> V_22 = V_19 ;
}
unsigned long F_19 ( const T_1 * V_12 )
{
return V_12 -> V_16 ;
}
void F_20 ( T_1 * V_12 , unsigned long V_16 )
{
V_12 -> V_16 = V_16 ;
}
T_1 * F_10 ( T_1 * V_12 ,
const T_2 * V_11 , T_2 * V_23 , T_3 * V_13 ,
int (* F_21)( T_2 * V_10 , const T_2 * V_24 , const T_2 * V_25 ,
const T_2 * V_23 , T_3 * V_13 , T_4 * V_26 ) ,
T_4 * V_26 )
{
int V_27 = 32 ;
T_1 * V_4 = NULL ;
if ( V_12 == NULL )
V_4 = F_1 ( NULL , NULL , V_23 ) ;
else
V_4 = V_12 ;
if ( V_4 == NULL )
goto V_7;
if ( V_4 -> V_1 == NULL && ( V_4 -> V_1 = F_22 () ) == NULL )
goto V_7;
if ( V_4 -> V_2 == NULL && ( V_4 -> V_2 = F_22 () ) == NULL )
goto V_7;
if ( V_11 != NULL )
{
if ( V_4 -> V_11 != NULL )
F_7 ( V_4 -> V_11 ) ;
V_4 -> V_11 = F_5 ( V_11 ) ;
}
if ( V_4 -> V_11 == NULL )
goto V_7;
if ( F_21 != NULL )
V_4 -> F_21 = F_21 ;
if ( V_26 != NULL )
V_4 -> V_26 = V_26 ;
do {
if ( ! F_23 ( V_4 -> V_1 , V_4 -> V_3 ) ) goto V_7;
if ( F_24 ( V_4 -> V_2 , V_4 -> V_1 , V_4 -> V_3 , V_13 ) == NULL )
{
unsigned long error = F_25 () ;
if ( F_26 ( error ) == V_28 )
{
if ( V_27 -- == 0 )
{
F_4 ( V_29 ,
V_30 ) ;
goto V_7;
}
F_27 () ;
}
else
goto V_7;
}
else
break;
} while ( 1 );
if ( V_4 -> F_21 != NULL && V_4 -> V_26 != NULL )
{
if ( ! V_4 -> F_21 ( V_4 -> V_1 , V_4 -> V_1 , V_4 -> V_11 , V_4 -> V_3 , V_13 , V_4 -> V_26 ) )
goto V_7;
}
else
{
if ( ! F_28 ( V_4 -> V_1 , V_4 -> V_1 , V_4 -> V_11 , V_4 -> V_3 , V_13 ) )
goto V_7;
}
return V_4 ;
V_7:
if ( V_12 == NULL && V_4 != NULL )
{
F_6 ( V_4 ) ;
V_4 = NULL ;
}
return V_4 ;
}
