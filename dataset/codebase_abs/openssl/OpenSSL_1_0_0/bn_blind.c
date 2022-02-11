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
if ( ( V_4 -> V_3 = F_5 ( V_3 ) ) == NULL ) goto V_7;
if ( F_6 ( V_3 , V_8 ) != 0 )
F_7 ( V_4 -> V_3 , V_8 ) ;
V_4 -> V_9 = V_10 ;
F_8 ( & V_4 -> V_11 ) ;
return ( V_4 ) ;
V_7:
if ( V_4 != NULL ) F_9 ( V_4 ) ;
return ( NULL ) ;
}
void F_9 ( T_1 * V_12 )
{
if( V_12 == NULL )
return;
if ( V_12 -> V_1 != NULL ) F_10 ( V_12 -> V_1 ) ;
if ( V_12 -> V_2 != NULL ) F_10 ( V_12 -> V_2 ) ;
if ( V_12 -> V_13 != NULL ) F_10 ( V_12 -> V_13 ) ;
if ( V_12 -> V_3 != NULL ) F_10 ( V_12 -> V_3 ) ;
F_11 ( V_12 ) ;
}
int F_12 ( T_1 * V_14 , T_3 * V_15 )
{
int V_4 = 0 ;
if ( ( V_14 -> V_1 == NULL ) || ( V_14 -> V_2 == NULL ) )
{
F_4 ( V_16 , V_17 ) ;
goto V_7;
}
if ( -- ( V_14 -> V_9 ) == 0 && V_14 -> V_13 != NULL &&
! ( V_14 -> V_18 & V_19 ) )
{
if ( ! F_13 ( V_14 , NULL , NULL , V_15 , NULL , NULL ) )
goto V_7;
}
else if ( ! ( V_14 -> V_18 & V_20 ) )
{
if ( ! F_14 ( V_14 -> V_1 , V_14 -> V_1 , V_14 -> V_1 , V_14 -> V_3 , V_15 ) ) goto V_7;
if ( ! F_14 ( V_14 -> V_2 , V_14 -> V_2 , V_14 -> V_2 , V_14 -> V_3 , V_15 ) ) goto V_7;
}
V_4 = 1 ;
V_7:
if ( V_14 -> V_9 == 0 )
V_14 -> V_9 = V_10 ;
return ( V_4 ) ;
}
int F_15 ( T_2 * V_21 , T_1 * V_14 , T_3 * V_15 )
{
return F_16 ( V_21 , NULL , V_14 , V_15 ) ;
}
int F_16 ( T_2 * V_21 , T_2 * V_12 , T_1 * V_14 , T_3 * V_15 )
{
int V_4 = 1 ;
F_2 ( V_21 ) ;
if ( ( V_14 -> V_1 == NULL ) || ( V_14 -> V_2 == NULL ) )
{
F_4 ( V_22 , V_17 ) ;
return ( 0 ) ;
}
if ( V_12 != NULL )
{
if ( ! F_17 ( V_12 , V_14 -> V_2 ) ) V_4 = 0 ;
}
if ( ! F_14 ( V_21 , V_21 , V_14 -> V_1 , V_14 -> V_3 , V_15 ) ) V_4 = 0 ;
return V_4 ;
}
int F_18 ( T_2 * V_21 , T_1 * V_14 , T_3 * V_15 )
{
return F_19 ( V_21 , NULL , V_14 , V_15 ) ;
}
int F_19 ( T_2 * V_21 , const T_2 * V_12 , T_1 * V_14 , T_3 * V_15 )
{
int V_4 ;
F_2 ( V_21 ) ;
if ( ( V_14 -> V_1 == NULL ) || ( V_14 -> V_2 == NULL ) )
{
F_4 ( V_23 , V_17 ) ;
return ( 0 ) ;
}
if ( V_12 != NULL )
V_4 = F_14 ( V_21 , V_21 , V_12 , V_14 -> V_3 , V_15 ) ;
else
V_4 = F_14 ( V_21 , V_21 , V_14 -> V_2 , V_14 -> V_3 , V_15 ) ;
if ( V_4 >= 0 )
{
if ( ! F_12 ( V_14 , V_15 ) )
return ( 0 ) ;
}
F_2 ( V_21 ) ;
return ( V_4 ) ;
}
unsigned long F_20 ( const T_1 * V_14 )
{
return V_14 -> V_24 ;
}
void F_21 ( T_1 * V_14 , unsigned long V_21 )
{
V_14 -> V_24 = V_21 ;
}
T_4 * F_22 ( T_1 * V_14 )
{
return & V_14 -> V_11 ;
}
unsigned long F_23 ( const T_1 * V_14 )
{
return V_14 -> V_18 ;
}
void F_24 ( T_1 * V_14 , unsigned long V_18 )
{
V_14 -> V_18 = V_18 ;
}
T_1 * F_13 ( T_1 * V_14 ,
const T_2 * V_13 , T_2 * V_25 , T_3 * V_15 ,
int (* F_25)( T_2 * V_12 , const T_2 * V_26 , const T_2 * V_27 ,
const T_2 * V_25 , T_3 * V_15 , T_5 * V_28 ) ,
T_5 * V_28 )
{
int V_29 = 32 ;
T_1 * V_4 = NULL ;
if ( V_14 == NULL )
V_4 = F_1 ( NULL , NULL , V_25 ) ;
else
V_4 = V_14 ;
if ( V_4 == NULL )
goto V_7;
if ( V_4 -> V_1 == NULL && ( V_4 -> V_1 = F_26 () ) == NULL )
goto V_7;
if ( V_4 -> V_2 == NULL && ( V_4 -> V_2 = F_26 () ) == NULL )
goto V_7;
if ( V_13 != NULL )
{
if ( V_4 -> V_13 != NULL )
F_10 ( V_4 -> V_13 ) ;
V_4 -> V_13 = F_5 ( V_13 ) ;
}
if ( V_4 -> V_13 == NULL )
goto V_7;
if ( F_25 != NULL )
V_4 -> F_25 = F_25 ;
if ( V_28 != NULL )
V_4 -> V_28 = V_28 ;
do {
if ( ! F_27 ( V_4 -> V_1 , V_4 -> V_3 ) ) goto V_7;
if ( F_28 ( V_4 -> V_2 , V_4 -> V_1 , V_4 -> V_3 , V_15 ) == NULL )
{
unsigned long error = F_29 () ;
if ( F_30 ( error ) == V_30 )
{
if ( V_29 -- == 0 )
{
F_4 ( V_31 ,
V_32 ) ;
goto V_7;
}
F_31 () ;
}
else
goto V_7;
}
else
break;
} while ( 1 );
if ( V_4 -> F_25 != NULL && V_4 -> V_28 != NULL )
{
if ( ! V_4 -> F_25 ( V_4 -> V_1 , V_4 -> V_1 , V_4 -> V_13 , V_4 -> V_3 , V_15 , V_4 -> V_28 ) )
goto V_7;
}
else
{
if ( ! F_32 ( V_4 -> V_1 , V_4 -> V_1 , V_4 -> V_13 , V_4 -> V_3 , V_15 ) )
goto V_7;
}
return V_4 ;
V_7:
if ( V_14 == NULL && V_4 != NULL )
{
F_9 ( V_4 ) ;
V_4 = NULL ;
}
return V_4 ;
}
