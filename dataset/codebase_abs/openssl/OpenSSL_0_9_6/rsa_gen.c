T_1 * F_1 ( int V_1 , unsigned long V_2 ,
void (* F_2)( int , int , void * ) , void * V_3 )
{
T_1 * V_4 = NULL ;
T_2 * V_5 = NULL , * V_6 = NULL , * V_7 = NULL , * V_8 = NULL , * V_9 ;
int V_10 , V_11 , V_12 = - 1 , V_13 = 0 , V_14 ;
T_3 * V_15 = NULL , * V_16 = NULL ;
V_15 = F_3 () ;
if ( V_15 == NULL ) goto V_17;
V_16 = F_3 () ;
if ( V_16 == NULL ) goto V_17;
F_4 ( V_15 ) ;
V_5 = F_5 ( V_15 ) ;
V_6 = F_5 ( V_15 ) ;
V_7 = F_5 ( V_15 ) ;
V_8 = F_5 ( V_15 ) ;
if ( V_8 == NULL ) goto V_17;
V_10 = ( V_1 + 1 ) / 2 ;
V_11 = V_1 - V_10 ;
V_4 = F_6 () ;
if ( V_4 == NULL ) goto V_17;
V_4 -> V_18 = F_7 () ;
if ( V_4 -> V_18 == NULL ) goto V_17;
#if 1
for ( V_14 = 0 ; V_14 <sizeof( unsigned long ) * 8 ; V_14 ++ )
{
if ( V_2 & ( 1UL << V_14 ) )
F_8 ( V_4 -> V_18 , V_14 ) ;
}
#else
if ( ! F_9 ( V_4 -> V_18 , V_2 ) ) goto V_17;
#endif
for (; ; )
{
V_4 -> V_19 = F_10 ( NULL , V_10 , 0 , NULL , NULL , F_2 , V_3 ) ;
if ( V_4 -> V_19 == NULL ) goto V_17;
if ( ! F_11 ( V_7 , V_4 -> V_19 , F_12 () ) ) goto V_17;
if ( ! F_13 ( V_6 , V_7 , V_4 -> V_18 , V_15 ) ) goto V_17;
if ( F_14 ( V_6 ) ) break;
if ( F_2 != NULL ) F_2 ( 2 , V_13 ++ , V_3 ) ;
F_15 ( V_4 -> V_19 ) ;
}
if ( F_2 != NULL ) F_2 ( 3 , 0 , V_3 ) ;
for (; ; )
{
V_4 -> V_20 = F_10 ( NULL , V_11 , 0 , NULL , NULL , F_2 , V_3 ) ;
if ( V_4 -> V_20 == NULL ) goto V_17;
if ( ! F_11 ( V_7 , V_4 -> V_20 , F_12 () ) ) goto V_17;
if ( ! F_13 ( V_6 , V_7 , V_4 -> V_18 , V_15 ) ) goto V_17;
if ( F_14 ( V_6 ) && ( F_16 ( V_4 -> V_19 , V_4 -> V_20 ) != 0 ) )
break;
if ( F_2 != NULL ) F_2 ( 2 , V_13 ++ , V_3 ) ;
F_15 ( V_4 -> V_20 ) ;
}
if ( F_2 != NULL ) F_2 ( 3 , 1 , V_3 ) ;
if ( F_16 ( V_4 -> V_19 , V_4 -> V_20 ) < 0 )
{
V_9 = V_4 -> V_19 ;
V_4 -> V_19 = V_4 -> V_20 ;
V_4 -> V_20 = V_9 ;
}
V_4 -> V_13 = F_7 () ;
if ( V_4 -> V_13 == NULL ) goto V_17;
if ( ! F_17 ( V_4 -> V_13 , V_4 -> V_19 , V_4 -> V_20 , V_15 ) ) goto V_17;
if ( ! F_11 ( V_6 , V_4 -> V_19 , F_12 () ) ) goto V_17;
if ( ! F_11 ( V_7 , V_4 -> V_20 , F_12 () ) ) goto V_17;
if ( ! F_17 ( V_5 , V_6 , V_7 , V_15 ) ) goto V_17;
V_4 -> V_21 = F_18 ( NULL , V_4 -> V_18 , V_5 , V_16 ) ;
if ( V_4 -> V_21 == NULL ) goto V_17;
V_4 -> V_22 = F_7 () ;
if ( V_4 -> V_22 == NULL ) goto V_17;
if ( ! F_19 ( V_4 -> V_22 , V_4 -> V_21 , V_6 , V_15 ) ) goto V_17;
V_4 -> V_23 = F_7 () ;
if ( V_4 -> V_23 == NULL ) goto V_17;
if ( ! F_19 ( V_4 -> V_23 , V_4 -> V_21 , V_7 , V_15 ) ) goto V_17;
V_4 -> V_24 = F_18 ( NULL , V_4 -> V_20 , V_4 -> V_19 , V_16 ) ;
if ( V_4 -> V_24 == NULL ) goto V_17;
V_12 = 1 ;
V_17:
if ( V_12 == - 1 )
{
F_20 ( V_25 , V_26 ) ;
V_12 = 0 ;
}
F_21 ( V_15 ) ;
F_22 ( V_15 ) ;
F_22 ( V_16 ) ;
if ( ! V_12 )
{
if ( V_4 != NULL ) F_23 ( V_4 ) ;
return ( NULL ) ;
}
else
return ( V_4 ) ;
}
