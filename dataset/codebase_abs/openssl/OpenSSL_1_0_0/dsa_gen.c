int F_1 ( T_1 * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 ,
int * V_5 , unsigned long * V_6 , T_2 * V_7 )
{
if( V_1 -> V_8 -> V_9 )
return V_1 -> V_8 -> V_9 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , V_6 , V_7 ) ;
else
{
const T_3 * V_10 ;
T_4 V_11 = V_2 >= 2048 ? 256 : 160 ;
if ( V_2 >= 2048 )
{
V_11 = 256 ;
V_10 = F_2 () ;
}
else
{
V_11 = 160 ;
V_10 = F_3 () ;
}
return F_4 ( V_1 , V_2 , V_11 , V_10 ,
V_3 , V_4 , V_5 , V_6 , V_7 ) ;
}
}
int F_4 ( T_1 * V_1 , T_4 V_2 , T_4 V_11 ,
const T_3 * V_10 , const unsigned char * V_3 , T_4 V_4 ,
int * V_5 , unsigned long * V_6 , T_2 * V_7 )
{
int V_12 = 0 ;
unsigned char V_13 [ V_14 ] ;
unsigned char V_15 [ V_14 ] ;
unsigned char V_16 [ V_14 ] , V_17 [ V_14 ] ;
T_5 * V_18 , * V_19 , * V_20 , * V_21 , * V_22 ;
T_5 * V_23 = NULL , * V_24 = NULL , * V_25 = NULL ;
T_6 * V_26 = NULL ;
int V_27 , V_28 , V_29 = 0 , V_30 , V_31 = 0 , V_32 = V_11 >> 3 ;
int V_33 = 0 ;
int V_34 = 0 ;
T_7 * V_35 = NULL ;
unsigned int V_36 = 2 ;
if ( V_32 != V_37 && V_32 != V_38 &&
V_32 != V_14 )
return 0 ;
if ( V_10 == NULL )
V_10 = F_3 () ;
if ( V_2 < 512 )
V_2 = 512 ;
V_2 = ( V_2 + 63 ) / 64 * 64 ;
if ( V_4 && ( V_4 < ( T_4 ) V_32 ) )
V_3 = NULL ;
if ( V_4 > ( T_4 ) V_32 )
V_4 = V_32 ;
if ( V_3 != NULL )
memcpy ( V_13 , V_3 , V_4 ) ;
if ( ( V_35 = F_5 () ) == NULL )
goto V_39;
if ( ( V_26 = F_6 () ) == NULL )
goto V_39;
F_7 ( V_35 ) ;
V_18 = F_8 ( V_35 ) ;
V_23 = F_8 ( V_35 ) ;
V_19 = F_8 ( V_35 ) ;
V_24 = F_8 ( V_35 ) ;
V_20 = F_8 ( V_35 ) ;
V_21 = F_8 ( V_35 ) ;
V_25 = F_8 ( V_35 ) ;
V_22 = F_8 ( V_35 ) ;
if ( ! F_9 ( V_22 , F_10 () , V_2 - 1 ) )
goto V_39;
for (; ; )
{
for (; ; )
{
int V_40 ;
if( ! F_11 ( V_7 , 0 , V_31 ++ ) )
goto V_39;
if ( ! V_4 )
{
F_12 ( V_13 , V_32 ) ;
V_40 = 1 ;
}
else
{
V_40 = 0 ;
V_4 = 0 ;
}
memcpy ( V_16 , V_13 , V_32 ) ;
memcpy ( V_17 , V_13 , V_32 ) ;
for ( V_27 = V_32 - 1 ; V_27 >= 0 ; V_27 -- )
{
V_16 [ V_27 ] ++ ;
if ( V_16 [ V_27 ] != 0 )
break;
}
F_13 ( V_13 , V_32 , V_15 , NULL , V_10 , NULL ) ;
F_13 ( V_16 , V_32 , V_17 , NULL , V_10 , NULL ) ;
for ( V_27 = 0 ; V_27 < V_32 ; V_27 ++ )
V_15 [ V_27 ] ^= V_17 [ V_27 ] ;
V_15 [ 0 ] |= 0x80 ;
V_15 [ V_32 - 1 ] |= 0x01 ;
if ( ! F_14 ( V_15 , V_32 , V_24 ) )
goto V_39;
V_34 = F_15 ( V_24 , V_41 , V_35 ,
V_40 , V_7 ) ;
if ( V_34 > 0 )
break;
if ( V_34 != 0 )
goto V_39;
}
if( ! F_11 ( V_7 , 2 , 0 ) ) goto V_39;
if( ! F_11 ( V_7 , 3 , 0 ) ) goto V_39;
V_33 = 0 ;
V_29 = ( V_2 - 1 ) / 160 ;
V_30 = ( V_2 - 1 ) - V_29 * 160 ;
for (; ; )
{
if ( ( V_33 != 0 ) && ! F_11 ( V_7 , 0 , V_33 ) )
goto V_39;
F_16 ( V_19 ) ;
for ( V_28 = 0 ; V_28 <= V_29 ; V_28 ++ )
{
for ( V_27 = V_32 - 1 ; V_27 >= 0 ; V_27 -- )
{
V_16 [ V_27 ] ++ ;
if ( V_16 [ V_27 ] != 0 )
break;
}
F_13 ( V_16 , V_32 , V_15 , NULL , V_10 , NULL ) ;
if ( ! F_14 ( V_15 , V_32 , V_18 ) )
goto V_39;
if ( ! F_9 ( V_18 , V_18 , ( V_32 << 3 ) * V_28 ) ) goto V_39;
if ( ! F_17 ( V_19 , V_19 , V_18 ) ) goto V_39;
}
if ( ! F_18 ( V_19 , V_2 - 1 ) ) goto V_39;
if ( ! F_19 ( V_20 , V_19 ) ) goto V_39;
if ( ! F_17 ( V_20 , V_20 , V_22 ) ) goto V_39;
if ( ! F_20 ( V_18 , V_24 ) ) goto V_39;
if ( ! F_21 ( V_21 , V_20 , V_18 , V_35 ) ) goto V_39;
if ( ! F_22 ( V_18 , V_21 , F_10 () ) ) goto V_39;
if ( ! F_22 ( V_25 , V_20 , V_18 ) ) goto V_39;
if ( F_23 ( V_25 , V_22 ) >= 0 )
{
V_34 = F_15 ( V_25 , V_41 ,
V_35 , 1 , V_7 ) ;
if ( V_34 > 0 )
goto V_42;
if ( V_34 != 0 )
goto V_39;
}
V_33 ++ ;
if ( V_33 >= 4096 ) break;
}
}
V_42:
if( ! F_11 ( V_7 , 2 , 1 ) )
goto V_39;
if ( ! F_22 ( V_22 , V_25 , F_10 () ) ) goto V_39;
if ( ! F_24 ( V_18 , NULL , V_22 , V_24 , V_35 ) ) goto V_39;
if ( ! F_25 ( V_22 , V_36 ) ) goto V_39;
if ( ! F_26 ( V_26 , V_25 , V_35 ) ) goto V_39;
for (; ; )
{
if ( ! F_27 ( V_23 , V_22 , V_18 , V_25 , V_35 , V_26 ) ) goto V_39;
if ( ! F_28 ( V_23 ) ) break;
if ( ! F_17 ( V_22 , V_22 , F_10 () ) ) goto V_39;
V_36 ++ ;
}
if( ! F_11 ( V_7 , 3 , 1 ) )
goto V_39;
V_12 = 1 ;
V_39:
if ( V_12 )
{
if( V_1 -> V_25 ) F_29 ( V_1 -> V_25 ) ;
if( V_1 -> V_24 ) F_29 ( V_1 -> V_24 ) ;
if( V_1 -> V_23 ) F_29 ( V_1 -> V_23 ) ;
V_1 -> V_25 = F_30 ( V_25 ) ;
V_1 -> V_24 = F_30 ( V_24 ) ;
V_1 -> V_23 = F_30 ( V_23 ) ;
if ( V_1 -> V_25 == NULL || V_1 -> V_24 == NULL || V_1 -> V_23 == NULL )
{
V_12 = 0 ;
goto V_39;
}
if ( V_5 != NULL ) * V_5 = V_33 ;
if ( V_6 != NULL ) * V_6 = V_36 ;
}
if( V_35 )
{
F_31 ( V_35 ) ;
F_32 ( V_35 ) ;
}
if ( V_26 != NULL ) F_33 ( V_26 ) ;
return V_12 ;
}
