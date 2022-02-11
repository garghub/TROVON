int F_1 ( T_1 * V_1 , int V_2 ,
unsigned char * V_3 , int V_4 ,
int * V_5 , unsigned long * V_6 , T_2 * V_7 )
{
if( V_1 -> V_8 -> V_9 )
return V_1 -> V_8 -> V_9 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , V_6 , V_7 ) ;
return F_2 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , V_6 , V_7 ) ;
}
static int F_2 ( T_1 * V_1 , int V_2 ,
unsigned char * V_3 , int V_4 ,
int * V_5 , unsigned long * V_6 , T_2 * V_7 )
{
int V_10 = 0 ;
unsigned char V_11 [ V_12 ] ;
unsigned char V_13 [ V_12 ] ;
unsigned char V_14 [ V_12 ] , V_15 [ V_12 ] ;
T_3 * V_16 , * V_17 , * V_18 , * V_19 , * V_20 ;
T_3 * V_21 = NULL , * V_22 = NULL , * V_23 = NULL ;
T_4 * V_24 = NULL ;
int V_25 , V_26 = 0 , V_27 , V_28 , V_29 = 0 ;
int V_30 = 0 ;
int V_31 = 0 ;
T_5 * V_32 = NULL ;
unsigned int V_33 = 2 ;
if ( V_2 < 512 ) V_2 = 512 ;
V_2 = ( V_2 + 63 ) / 64 * 64 ;
if ( V_4 < 20 )
V_3 = NULL ;
if ( V_4 > 20 )
V_4 = 20 ;
if ( ( V_3 != NULL ) && ( V_4 == 20 ) )
memcpy ( V_11 , V_3 , V_4 ) ;
if ( ( V_32 = F_3 () ) == NULL ) goto V_34;
if ( ( V_24 = F_4 () ) == NULL ) goto V_34;
F_5 ( V_32 ) ;
V_16 = F_6 ( V_32 ) ;
V_21 = F_6 ( V_32 ) ;
V_17 = F_6 ( V_32 ) ;
V_22 = F_6 ( V_32 ) ;
V_18 = F_6 ( V_32 ) ;
V_19 = F_6 ( V_32 ) ;
V_23 = F_6 ( V_32 ) ;
V_20 = F_6 ( V_32 ) ;
if ( ! F_7 ( V_20 , F_8 () , V_2 - 1 ) )
goto V_34;
for (; ; )
{
for (; ; )
{
int V_35 ;
if( ! F_9 ( V_7 , 0 , V_29 ++ ) )
goto V_34;
if ( ! V_4 )
{
F_10 ( V_11 , V_12 ) ;
V_35 = 1 ;
}
else
{
V_35 = 0 ;
V_4 = 0 ;
}
memcpy ( V_14 , V_11 , V_12 ) ;
memcpy ( V_15 , V_11 , V_12 ) ;
for ( V_27 = V_12 - 1 ; V_27 >= 0 ; V_27 -- )
{
V_14 [ V_27 ] ++ ;
if ( V_14 [ V_27 ] != 0 ) break;
}
F_11 ( V_11 , V_12 , V_13 , NULL , V_36 , NULL ) ;
F_11 ( V_14 , V_12 , V_15 , NULL , V_36 , NULL ) ;
for ( V_27 = 0 ; V_27 < V_12 ; V_27 ++ )
V_13 [ V_27 ] ^= V_15 [ V_27 ] ;
V_13 [ 0 ] |= 0x80 ;
V_13 [ V_12 - 1 ] |= 0x01 ;
if ( ! F_12 ( V_13 , V_12 , V_22 ) ) goto V_34;
V_31 = F_13 ( V_22 , V_37 , V_32 ,
V_35 , V_7 ) ;
if ( V_31 > 0 )
break;
if ( V_31 != 0 )
goto V_34;
}
if( ! F_9 ( V_7 , 2 , 0 ) ) goto V_34;
if( ! F_9 ( V_7 , 3 , 0 ) ) goto V_34;
V_30 = 0 ;
V_26 = ( V_2 - 1 ) / 160 ;
V_28 = ( V_2 - 1 ) - V_26 * 160 ;
for (; ; )
{
if ( ( V_30 != 0 ) && ! F_9 ( V_7 , 0 , V_30 ) )
goto V_34;
F_14 ( V_17 ) ;
for ( V_25 = 0 ; V_25 <= V_26 ; V_25 ++ )
{
for ( V_27 = V_12 - 1 ; V_27 >= 0 ; V_27 -- )
{
V_14 [ V_27 ] ++ ;
if ( V_14 [ V_27 ] != 0 ) break;
}
F_11 ( V_14 , V_12 , V_13 , NULL , V_36 , NULL ) ;
if ( ! F_12 ( V_13 , V_12 , V_16 ) )
goto V_34;
if ( ! F_7 ( V_16 , V_16 , 160 * V_25 ) ) goto V_34;
if ( ! F_15 ( V_17 , V_17 , V_16 ) ) goto V_34;
}
if ( ! F_16 ( V_17 , V_2 - 1 ) ) goto V_34;
if ( ! F_17 ( V_18 , V_17 ) ) goto V_34;
if ( ! F_15 ( V_18 , V_18 , V_20 ) ) goto V_34;
if ( ! F_18 ( V_16 , V_22 ) ) goto V_34;
if ( ! F_19 ( V_19 , V_18 , V_16 , V_32 ) ) goto V_34;
if ( ! F_20 ( V_16 , V_19 , F_8 () ) ) goto V_34;
if ( ! F_20 ( V_23 , V_18 , V_16 ) ) goto V_34;
if ( F_21 ( V_23 , V_20 ) >= 0 )
{
V_31 = F_13 ( V_23 , V_37 ,
V_32 , 1 , V_7 ) ;
if ( V_31 > 0 )
goto V_38;
if ( V_31 != 0 )
goto V_34;
}
V_30 ++ ;
if ( V_30 >= 4096 ) break;
}
}
V_38:
if( ! F_9 ( V_7 , 2 , 1 ) )
goto V_34;
if ( ! F_20 ( V_20 , V_23 , F_8 () ) ) goto V_34;
if ( ! F_22 ( V_16 , NULL , V_20 , V_22 , V_32 ) ) goto V_34;
if ( ! F_23 ( V_20 , V_33 ) ) goto V_34;
if ( ! F_24 ( V_24 , V_23 , V_32 ) ) goto V_34;
for (; ; )
{
if ( ! F_25 ( V_21 , V_20 , V_16 , V_23 , V_32 , V_24 ) ) goto V_34;
if ( ! F_26 ( V_21 ) ) break;
if ( ! F_15 ( V_20 , V_20 , F_8 () ) ) goto V_34;
V_33 ++ ;
}
if( ! F_9 ( V_7 , 3 , 1 ) )
goto V_34;
V_10 = 1 ;
V_34:
if ( V_10 )
{
if( V_1 -> V_23 ) F_27 ( V_1 -> V_23 ) ;
if( V_1 -> V_22 ) F_27 ( V_1 -> V_22 ) ;
if( V_1 -> V_21 ) F_27 ( V_1 -> V_21 ) ;
V_1 -> V_23 = F_28 ( V_23 ) ;
V_1 -> V_22 = F_28 ( V_22 ) ;
V_1 -> V_21 = F_28 ( V_21 ) ;
if ( V_1 -> V_23 == NULL || V_1 -> V_22 == NULL || V_1 -> V_21 == NULL )
{
V_10 = 0 ;
goto V_34;
}
if ( ( V_29 > 1 ) && ( V_3 != NULL ) ) memcpy ( V_3 , V_11 , 20 ) ;
if ( V_5 != NULL ) * V_5 = V_30 ;
if ( V_6 != NULL ) * V_6 = V_33 ;
}
if( V_32 )
{
F_29 ( V_32 ) ;
F_30 ( V_32 ) ;
}
if ( V_24 != NULL ) F_31 ( V_24 ) ;
return V_10 ;
}
