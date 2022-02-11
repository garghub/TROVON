T_1 * F_1 ( int V_1 ,
unsigned char * V_2 , int V_3 ,
int * V_4 , unsigned long * V_5 ,
void (* F_2)( int , int , void * ) ,
void * V_6 )
{
int V_7 = 0 ;
unsigned char V_8 [ V_9 ] ;
unsigned char V_10 [ V_9 ] ;
unsigned char V_11 [ V_9 ] , V_12 [ V_9 ] ;
T_2 * V_13 , * V_14 , * V_15 , * V_16 , * V_17 ;
T_2 * V_18 = NULL , * V_19 = NULL , * V_20 = NULL ;
T_3 * V_21 = NULL ;
int V_22 , V_23 = 0 , V_24 , V_25 , V_26 = 0 ;
int V_27 = 0 ;
int V_28 = 0 ;
T_4 * V_29 = NULL , * V_30 = NULL , * V_31 = NULL ;
unsigned int V_32 = 2 ;
T_1 * V_33 = NULL ;
if ( V_1 < 512 ) V_1 = 512 ;
V_1 = ( V_1 + 63 ) / 64 * 64 ;
if ( V_3 < 20 )
V_2 = NULL ;
if ( V_3 > 20 )
V_3 = 20 ;
if ( ( V_2 != NULL ) && ( V_3 == 20 ) )
memcpy ( V_8 , V_2 , V_3 ) ;
if ( ( V_29 = F_3 () ) == NULL ) goto V_34;
if ( ( V_30 = F_3 () ) == NULL ) goto V_34;
if ( ( V_31 = F_3 () ) == NULL ) goto V_34;
if ( ( V_33 = F_4 () ) == NULL ) goto V_34;
if ( ( V_21 = F_5 () ) == NULL ) goto V_34;
F_6 ( V_30 ) ;
V_13 = F_7 ( V_30 ) ;
V_18 = F_7 ( V_30 ) ;
V_14 = F_7 ( V_30 ) ;
V_19 = F_7 ( V_30 ) ;
V_15 = F_7 ( V_30 ) ;
V_16 = F_7 ( V_30 ) ;
V_20 = F_7 ( V_30 ) ;
V_17 = F_7 ( V_30 ) ;
F_8 ( V_17 , F_9 () , V_1 - 1 ) ;
for (; ; )
{
for (; ; )
{
int V_35 ;
if ( F_2 != NULL ) F_2 ( 0 , V_26 ++ , V_6 ) ;
if ( ! V_3 )
{
F_10 ( V_8 , V_9 ) ;
V_35 = 1 ;
}
else
{
V_35 = 0 ;
V_3 = 0 ;
}
memcpy ( V_11 , V_8 , V_9 ) ;
memcpy ( V_12 , V_8 , V_9 ) ;
for ( V_24 = V_9 - 1 ; V_24 >= 0 ; V_24 -- )
{
V_11 [ V_24 ] ++ ;
if ( V_11 [ V_24 ] != 0 ) break;
}
F_11 ( V_8 , V_9 , V_10 , NULL , V_36 , NULL ) ;
F_11 ( V_11 , V_9 , V_12 , NULL , V_36 , NULL ) ;
for ( V_24 = 0 ; V_24 < V_9 ; V_24 ++ )
V_10 [ V_24 ] ^= V_12 [ V_24 ] ;
V_10 [ 0 ] |= 0x80 ;
V_10 [ V_9 - 1 ] |= 0x01 ;
if ( ! F_12 ( V_10 , V_9 , V_19 ) ) goto V_34;
V_28 = F_13 ( V_19 , V_37 , F_2 , V_31 , V_6 , V_35 ) ;
if ( V_28 > 0 )
break;
if ( V_28 != 0 )
goto V_34;
}
if ( F_2 != NULL ) F_2 ( 2 , 0 , V_6 ) ;
if ( F_2 != NULL ) F_2 ( 3 , 0 , V_6 ) ;
V_27 = 0 ;
V_23 = ( V_1 - 1 ) / 160 ;
V_25 = ( V_1 - 1 ) - V_23 * 160 ;
for (; ; )
{
if ( F_2 != NULL && V_27 != 0 )
F_2 ( 0 , V_27 , V_6 ) ;
F_14 ( V_14 ) ;
for ( V_22 = 0 ; V_22 <= V_23 ; V_22 ++ )
{
for ( V_24 = V_9 - 1 ; V_24 >= 0 ; V_24 -- )
{
V_11 [ V_24 ] ++ ;
if ( V_11 [ V_24 ] != 0 ) break;
}
F_11 ( V_11 , V_9 , V_10 , NULL , V_36 , NULL ) ;
if ( ! F_12 ( V_10 , V_9 , V_13 ) )
goto V_34;
F_8 ( V_13 , V_13 , 160 * V_22 ) ;
F_15 ( V_14 , V_14 , V_13 ) ;
}
F_16 ( V_14 , V_1 - 1 ) ;
F_17 ( V_15 , V_14 ) ;
F_15 ( V_15 , V_15 , V_17 ) ;
F_18 ( V_13 , V_19 ) ;
F_19 ( V_16 , V_15 , V_13 , V_29 ) ;
F_20 ( V_13 , V_16 , F_9 () ) ;
F_20 ( V_20 , V_15 , V_13 ) ;
if ( F_21 ( V_20 , V_17 ) >= 0 )
{
V_28 = F_13 ( V_20 , V_37 , F_2 , V_31 , V_6 , 1 ) ;
if ( V_28 > 0 )
goto V_38;
if ( V_28 != 0 )
goto V_34;
}
V_27 ++ ;
if ( V_27 >= 4096 ) break;
}
}
V_38:
if ( F_2 != NULL ) F_2 ( 2 , 1 , V_6 ) ;
F_20 ( V_17 , V_20 , F_9 () ) ;
F_22 ( V_13 , NULL , V_17 , V_19 , V_29 ) ;
F_23 ( V_17 , V_32 ) ;
F_24 ( V_21 , V_20 , V_29 ) ;
for (; ; )
{
F_25 ( V_18 , V_17 , V_13 , V_20 , V_29 , V_21 ) ;
if ( ! F_26 ( V_18 ) ) break;
F_15 ( V_17 , V_17 , F_9 () ) ;
V_32 ++ ;
}
if ( F_2 != NULL ) F_2 ( 3 , 1 , V_6 ) ;
V_7 = 1 ;
V_34:
if ( ! V_7 )
{
if ( V_33 != NULL ) F_27 ( V_33 ) ;
}
else
{
V_33 -> V_20 = F_28 ( V_20 ) ;
V_33 -> V_19 = F_28 ( V_19 ) ;
V_33 -> V_18 = F_28 ( V_18 ) ;
if ( ( V_26 > 1 ) && ( V_2 != NULL ) ) memcpy ( V_2 , V_8 , 20 ) ;
if ( V_4 != NULL ) * V_4 = V_27 ;
if ( V_5 != NULL ) * V_5 = V_32 ;
}
if ( V_29 != NULL ) F_29 ( V_29 ) ;
if ( V_30 != NULL )
{
F_30 ( V_30 ) ;
F_29 ( V_30 ) ;
}
if ( V_31 != NULL ) F_29 ( V_31 ) ;
if ( V_21 != NULL ) F_31 ( V_21 ) ;
return ( V_7 ? V_33 : NULL ) ;
}
