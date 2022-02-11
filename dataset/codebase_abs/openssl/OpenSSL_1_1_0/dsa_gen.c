int F_1 ( T_1 * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 ,
int * V_5 , unsigned long * V_6 ,
T_2 * V_7 )
{
if ( V_1 -> V_8 -> V_9 )
return V_1 -> V_8 -> V_9 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , V_6 , V_7 ) ;
else {
const T_3 * V_10 = V_2 >= 2048 ? F_2 () : F_3 () ;
T_4 V_11 = F_4 ( V_10 ) * 8 ;
return F_5 ( V_1 , V_2 , V_11 , V_10 ,
V_3 , V_4 , NULL , V_5 ,
V_6 , V_7 ) ;
}
}
int F_5 ( T_1 * V_1 , T_4 V_2 , T_4 V_11 ,
const T_3 * V_10 , const unsigned char * V_3 ,
T_4 V_4 , unsigned char * V_12 ,
int * V_5 , unsigned long * V_6 , T_2 * V_7 )
{
int V_13 = 0 ;
unsigned char V_14 [ V_15 ] ;
unsigned char V_16 [ V_15 ] ;
unsigned char V_17 [ V_15 ] , V_18 [ V_15 ] ;
T_5 * V_19 , * V_20 , * V_21 , * V_22 , * V_23 ;
T_5 * V_24 = NULL , * V_25 = NULL , * V_26 = NULL ;
T_6 * V_27 = NULL ;
int V_28 , V_29 , V_30 = 0 , V_31 = 0 , V_32 = V_11 >> 3 ;
int V_33 = 0 ;
int V_34 = 0 ;
T_7 * V_35 = NULL ;
unsigned int V_36 = 2 ;
if ( V_32 != V_37 && V_32 != V_38 &&
V_32 != V_15 )
return 0 ;
if ( V_10 == NULL )
V_10 = F_3 () ;
if ( V_2 < 512 )
V_2 = 512 ;
V_2 = ( V_2 + 63 ) / 64 * 64 ;
if ( V_3 != NULL ) {
if ( V_4 < ( T_4 ) V_32 )
return 0 ;
if ( V_4 > ( T_4 ) V_32 ) {
V_4 = V_32 ;
}
memcpy ( V_14 , V_3 , V_4 ) ;
}
if ( ( V_27 = F_6 () ) == NULL )
goto V_39;
if ( ( V_35 = F_7 () ) == NULL )
goto V_39;
F_8 ( V_35 ) ;
V_19 = F_9 ( V_35 ) ;
V_24 = F_9 ( V_35 ) ;
V_20 = F_9 ( V_35 ) ;
V_25 = F_9 ( V_35 ) ;
V_21 = F_9 ( V_35 ) ;
V_22 = F_9 ( V_35 ) ;
V_26 = F_9 ( V_35 ) ;
V_23 = F_9 ( V_35 ) ;
if ( ! F_10 ( V_23 , F_11 () , V_2 - 1 ) )
goto V_39;
for (; ; ) {
for (; ; ) {
int V_40 = ( V_3 == NULL ) ;
if ( ! F_12 ( V_7 , 0 , V_31 ++ ) )
goto V_39;
if ( V_40 ) {
if ( F_13 ( V_14 , V_32 ) <= 0 )
goto V_39;
} else {
V_3 = NULL ;
}
memcpy ( V_17 , V_14 , V_32 ) ;
memcpy ( V_18 , V_14 , V_32 ) ;
for ( V_28 = V_32 - 1 ; V_28 >= 0 ; V_28 -- ) {
V_17 [ V_28 ] ++ ;
if ( V_17 [ V_28 ] != 0 )
break;
}
if ( ! F_14 ( V_14 , V_32 , V_16 , NULL , V_10 , NULL ) )
goto V_39;
if ( ! F_14 ( V_17 , V_32 , V_18 , NULL , V_10 , NULL ) )
goto V_39;
for ( V_28 = 0 ; V_28 < V_32 ; V_28 ++ )
V_16 [ V_28 ] ^= V_18 [ V_28 ] ;
V_16 [ 0 ] |= 0x80 ;
V_16 [ V_32 - 1 ] |= 0x01 ;
if ( ! F_15 ( V_16 , V_32 , V_25 ) )
goto V_39;
V_34 = F_16 ( V_25 , V_41 , V_35 ,
V_40 , V_7 ) ;
if ( V_34 > 0 )
break;
if ( V_34 != 0 )
goto V_39;
}
if ( ! F_12 ( V_7 , 2 , 0 ) )
goto V_39;
if ( ! F_12 ( V_7 , 3 , 0 ) )
goto V_39;
V_33 = 0 ;
V_30 = ( V_2 - 1 ) / 160 ;
for (; ; ) {
if ( ( V_33 != 0 ) && ! F_12 ( V_7 , 0 , V_33 ) )
goto V_39;
F_17 ( V_20 ) ;
for ( V_29 = 0 ; V_29 <= V_30 ; V_29 ++ ) {
for ( V_28 = V_32 - 1 ; V_28 >= 0 ; V_28 -- ) {
V_17 [ V_28 ] ++ ;
if ( V_17 [ V_28 ] != 0 )
break;
}
if ( ! F_14 ( V_17 , V_32 , V_16 , NULL , V_10 , NULL ) )
goto V_39;
if ( ! F_15 ( V_16 , V_32 , V_19 ) )
goto V_39;
if ( ! F_10 ( V_19 , V_19 , ( V_32 << 3 ) * V_29 ) )
goto V_39;
if ( ! F_18 ( V_20 , V_20 , V_19 ) )
goto V_39;
}
if ( ! F_19 ( V_20 , V_2 - 1 ) )
goto V_39;
if ( ! F_20 ( V_21 , V_20 ) )
goto V_39;
if ( ! F_18 ( V_21 , V_21 , V_23 ) )
goto V_39;
if ( ! F_21 ( V_19 , V_25 ) )
goto V_39;
if ( ! F_22 ( V_22 , V_21 , V_19 , V_35 ) )
goto V_39;
if ( ! F_23 ( V_19 , V_22 , F_11 () ) )
goto V_39;
if ( ! F_23 ( V_26 , V_21 , V_19 ) )
goto V_39;
if ( F_24 ( V_26 , V_23 ) >= 0 ) {
V_34 = F_16 ( V_26 , V_41 , V_35 , 1 , V_7 ) ;
if ( V_34 > 0 )
goto V_42;
if ( V_34 != 0 )
goto V_39;
}
V_33 ++ ;
if ( V_33 >= 4096 )
break;
}
}
V_42:
if ( ! F_12 ( V_7 , 2 , 1 ) )
goto V_39;
if ( ! F_23 ( V_23 , V_26 , F_11 () ) )
goto V_39;
if ( ! F_25 ( V_19 , NULL , V_23 , V_25 , V_35 ) )
goto V_39;
if ( ! F_26 ( V_23 , V_36 ) )
goto V_39;
if ( ! F_27 ( V_27 , V_26 , V_35 ) )
goto V_39;
for (; ; ) {
if ( ! F_28 ( V_24 , V_23 , V_19 , V_26 , V_35 , V_27 ) )
goto V_39;
if ( ! F_29 ( V_24 ) )
break;
if ( ! F_18 ( V_23 , V_23 , F_11 () ) )
goto V_39;
V_36 ++ ;
}
if ( ! F_12 ( V_7 , 3 , 1 ) )
goto V_39;
V_13 = 1 ;
V_39:
if ( V_13 ) {
F_30 ( V_1 -> V_26 ) ;
F_30 ( V_1 -> V_25 ) ;
F_30 ( V_1 -> V_24 ) ;
V_1 -> V_26 = F_31 ( V_26 ) ;
V_1 -> V_25 = F_31 ( V_25 ) ;
V_1 -> V_24 = F_31 ( V_24 ) ;
if ( V_1 -> V_26 == NULL || V_1 -> V_25 == NULL || V_1 -> V_24 == NULL ) {
V_13 = 0 ;
goto V_39;
}
if ( V_5 != NULL )
* V_5 = V_33 ;
if ( V_6 != NULL )
* V_6 = V_36 ;
if ( V_12 )
memcpy ( V_12 , V_14 , V_32 ) ;
}
if ( V_35 )
F_32 ( V_35 ) ;
F_33 ( V_35 ) ;
F_34 ( V_27 ) ;
return V_13 ;
}
int F_35 ( T_1 * V_1 , T_4 V_43 , T_4 V_44 ,
const T_3 * V_10 , const unsigned char * V_3 ,
T_4 V_4 , int V_45 , unsigned char * V_12 ,
int * V_5 , unsigned long * V_6 ,
T_2 * V_7 )
{
int V_13 = - 1 ;
unsigned char * V_14 = NULL , * V_46 = NULL ;
unsigned char V_16 [ V_47 ] ;
int V_48 ;
T_5 * V_19 , * V_20 , * V_21 , * V_22 , * V_23 ;
T_5 * V_24 = NULL , * V_25 = NULL , * V_26 = NULL ;
T_6 * V_27 = NULL ;
int V_28 , V_29 , V_30 = 0 , V_31 = 0 , V_32 = V_44 >> 3 ;
int V_33 = 0 ;
int V_34 = 0 ;
T_7 * V_35 = NULL ;
T_8 * V_49 = F_36 () ;
unsigned int V_36 = 2 ;
if ( V_49 == NULL )
goto V_39;
if ( V_10 == NULL ) {
if ( V_44 == 160 )
V_10 = F_3 () ;
else if ( V_44 == 224 )
V_10 = F_37 () ;
else
V_10 = F_2 () ;
}
V_48 = F_4 ( V_10 ) ;
if ( ! V_1 -> V_26 || ! V_1 -> V_25 || V_45 >= 0 ) {
if ( V_4 == 0 )
V_4 = V_48 ;
V_14 = F_38 ( V_4 ) ;
if ( V_12 )
V_46 = V_12 ;
else
V_46 = F_38 ( V_4 ) ;
if ( V_14 == NULL || V_46 == NULL )
goto V_39;
if ( V_3 )
memcpy ( V_14 , V_3 , V_4 ) ;
}
if ( ( V_35 = F_7 () ) == NULL )
goto V_39;
if ( ( V_27 = F_6 () ) == NULL )
goto V_39;
F_8 ( V_35 ) ;
V_19 = F_9 ( V_35 ) ;
V_24 = F_9 ( V_35 ) ;
V_20 = F_9 ( V_35 ) ;
V_21 = F_9 ( V_35 ) ;
V_22 = F_9 ( V_35 ) ;
V_23 = F_9 ( V_35 ) ;
if ( V_23 == NULL )
goto V_39;
if ( V_1 -> V_26 && V_1 -> V_25 ) {
V_26 = V_1 -> V_26 ;
V_25 = V_1 -> V_25 ;
if ( V_45 >= 0 )
memcpy ( V_46 , V_14 , V_4 ) ;
goto V_50;
} else {
V_26 = F_9 ( V_35 ) ;
V_25 = F_9 ( V_35 ) ;
}
if ( ! F_10 ( V_23 , F_11 () , V_43 - 1 ) )
goto V_39;
for (; ; ) {
for (; ; ) {
unsigned char * V_51 ;
if ( ! F_12 ( V_7 , 0 , V_31 ++ ) )
goto V_39;
if ( ! V_3 ) {
if ( F_13 ( V_14 , V_4 ) <= 0 )
goto V_39;
}
if ( ! F_14 ( V_14 , V_4 , V_16 , NULL , V_10 , NULL ) )
goto V_39;
if ( V_48 > V_32 )
V_51 = V_16 + V_48 - V_32 ;
else
V_51 = V_16 ;
if ( V_48 < V_32 )
memset ( V_16 + V_48 , 0 , V_32 - V_48 ) ;
V_51 [ 0 ] |= 0x80 ;
V_51 [ V_32 - 1 ] |= 0x01 ;
if ( ! F_15 ( V_51 , V_32 , V_25 ) )
goto V_39;
V_34 = F_16 ( V_25 , V_41 , V_35 ,
V_3 ? 1 : 0 , V_7 ) ;
if ( V_34 > 0 )
break;
if ( V_34 != 0 )
goto V_39;
if ( V_3 ) {
V_13 = 0 ;
F_39 ( V_52 , V_53 ) ;
goto V_39;
}
}
if ( V_12 )
memcpy ( V_12 , V_14 , V_4 ) ;
if ( ! F_12 ( V_7 , 2 , 0 ) )
goto V_39;
if ( ! F_12 ( V_7 , 3 , 0 ) )
goto V_39;
V_33 = 0 ;
V_30 = ( V_43 - 1 ) / ( V_48 << 3 ) ;
for (; ; ) {
if ( ( V_33 != 0 ) && ! F_12 ( V_7 , 0 , V_33 ) )
goto V_39;
F_17 ( V_20 ) ;
for ( V_29 = 0 ; V_29 <= V_30 ; V_29 ++ ) {
for ( V_28 = V_4 - 1 ; V_28 >= 0 ; V_28 -- ) {
V_14 [ V_28 ] ++ ;
if ( V_14 [ V_28 ] != 0 )
break;
}
if ( ! F_14 ( V_14 , V_4 , V_16 , NULL , V_10 , NULL ) )
goto V_39;
if ( ! F_15 ( V_16 , V_48 , V_19 ) )
goto V_39;
if ( ! F_10 ( V_19 , V_19 , ( V_48 << 3 ) * V_29 ) )
goto V_39;
if ( ! F_18 ( V_20 , V_20 , V_19 ) )
goto V_39;
}
if ( ! F_19 ( V_20 , V_43 - 1 ) )
goto V_39;
if ( ! F_20 ( V_21 , V_20 ) )
goto V_39;
if ( ! F_18 ( V_21 , V_21 , V_23 ) )
goto V_39;
if ( ! F_21 ( V_19 , V_25 ) )
goto V_39;
if ( ! F_22 ( V_22 , V_21 , V_19 , V_35 ) )
goto V_39;
if ( ! F_23 ( V_19 , V_22 , F_11 () ) )
goto V_39;
if ( ! F_23 ( V_26 , V_21 , V_19 ) )
goto V_39;
if ( F_24 ( V_26 , V_23 ) >= 0 ) {
V_34 = F_16 ( V_26 , V_41 , V_35 , 1 , V_7 ) ;
if ( V_34 > 0 )
goto V_42;
if ( V_34 != 0 )
goto V_39;
}
V_33 ++ ;
if ( V_33 >= ( int ) ( 4 * V_43 ) )
break;
}
if ( V_3 ) {
V_13 = 0 ;
F_39 ( V_52 , V_54 ) ;
goto V_39;
}
}
V_42:
if ( ! F_12 ( V_7 , 2 , 1 ) )
goto V_39;
V_50:
if ( ! F_23 ( V_23 , V_26 , F_11 () ) )
goto V_39;
if ( ! F_25 ( V_19 , NULL , V_23 , V_25 , V_35 ) )
goto V_39;
if ( V_45 < 0 ) {
if ( ! F_26 ( V_23 , V_36 ) )
goto V_39;
} else
V_36 = 1 ;
if ( ! F_27 ( V_27 , V_26 , V_35 ) )
goto V_39;
for (; ; ) {
static const unsigned char V_55 [ 4 ] = { 0x67 , 0x67 , 0x65 , 0x6e } ;
if ( V_45 >= 0 ) {
V_16 [ 0 ] = V_45 & 0xff ;
V_16 [ 1 ] = ( V_36 >> 8 ) & 0xff ;
V_16 [ 2 ] = V_36 & 0xff ;
if ( ! F_40 ( V_49 , V_10 , NULL ) )
goto V_39;
if ( ! F_41 ( V_49 , V_46 , V_4 ) )
goto V_39;
if ( ! F_41 ( V_49 , V_55 , sizeof( V_55 ) ) )
goto V_39;
if ( ! F_41 ( V_49 , V_16 , 3 ) )
goto V_39;
if ( ! F_42 ( V_49 , V_16 , NULL ) )
goto V_39;
if ( ! F_15 ( V_16 , V_48 , V_23 ) )
goto V_39;
}
if ( ! F_28 ( V_24 , V_23 , V_19 , V_26 , V_35 , V_27 ) )
goto V_39;
if ( ! F_29 ( V_24 ) )
break;
if ( V_45 < 0 && ! F_18 ( V_23 , V_23 , F_11 () ) )
goto V_39;
V_36 ++ ;
if ( V_45 >= 0 && V_36 > 0xffff )
goto V_39;
}
if ( ! F_12 ( V_7 , 3 , 1 ) )
goto V_39;
V_13 = 1 ;
V_39:
if ( V_13 == 1 ) {
if ( V_26 != V_1 -> V_26 ) {
F_30 ( V_1 -> V_26 ) ;
V_1 -> V_26 = F_31 ( V_26 ) ;
}
if ( V_25 != V_1 -> V_25 ) {
F_30 ( V_1 -> V_25 ) ;
V_1 -> V_25 = F_31 ( V_25 ) ;
}
F_30 ( V_1 -> V_24 ) ;
V_1 -> V_24 = F_31 ( V_24 ) ;
if ( V_1 -> V_26 == NULL || V_1 -> V_25 == NULL || V_1 -> V_24 == NULL ) {
V_13 = - 1 ;
goto V_39;
}
if ( V_5 != NULL )
* V_5 = V_33 ;
if ( V_6 != NULL )
* V_6 = V_36 ;
}
F_43 ( V_14 ) ;
if ( V_12 != V_46 )
F_43 ( V_46 ) ;
if ( V_35 )
F_32 ( V_35 ) ;
F_33 ( V_35 ) ;
F_34 ( V_27 ) ;
F_44 ( V_49 ) ;
return V_13 ;
}
