int F_1 ( T_1 * V_1 , int V_2 ,
const unsigned char * V_3 , int V_4 ,
int * V_5 , unsigned long * V_6 ,
T_2 * V_7 )
{
# ifdef F_2
if ( F_3 () && ! ( V_1 -> V_8 -> V_9 & V_10 )
&& ! ( V_1 -> V_9 & V_11 ) ) {
F_4 ( V_12 , V_13 ) ;
return 0 ;
}
# endif
if ( V_1 -> V_8 -> V_14 )
return V_1 -> V_8 -> V_14 ( V_1 , V_2 , V_3 , V_4 ,
V_5 , V_6 , V_7 ) ;
# ifdef F_2
else if ( F_3 () ) {
return F_5 ( V_1 , V_2 ,
V_3 , V_4 ,
V_5 , V_6 , V_7 ) ;
}
# endif
else {
const T_3 * V_15 ;
T_4 V_16 = V_2 >= 2048 ? 256 : 160 ;
if ( V_2 >= 2048 ) {
V_16 = 256 ;
V_15 = F_6 () ;
} else {
V_16 = 160 ;
V_15 = F_7 () ;
}
return F_8 ( V_1 , V_2 , V_16 , V_15 ,
V_3 , V_4 , NULL , V_5 ,
V_6 , V_7 ) ;
}
}
int F_8 ( T_1 * V_1 , T_4 V_2 , T_4 V_16 ,
const T_3 * V_15 , const unsigned char * V_3 ,
T_4 V_4 , unsigned char * V_17 ,
int * V_5 , unsigned long * V_6 , T_2 * V_7 )
{
int V_18 = 0 ;
unsigned char V_19 [ V_20 ] ;
unsigned char V_21 [ V_20 ] ;
unsigned char V_22 [ V_20 ] , V_23 [ V_20 ] ;
T_5 * V_24 , * V_25 , * V_26 , * V_27 , * V_28 ;
T_5 * V_29 = NULL , * V_30 = NULL , * V_31 = NULL ;
T_6 * V_32 = NULL ;
int V_33 , V_34 , V_35 = 0 , V_36 = 0 , V_37 = V_16 >> 3 ;
int V_38 = 0 ;
int V_39 = 0 ;
T_7 * V_40 = NULL ;
unsigned int V_41 = 2 ;
if ( V_37 != V_42 && V_37 != V_43 &&
V_37 != V_20 )
return 0 ;
if ( V_15 == NULL )
V_15 = F_7 () ;
if ( V_2 < 512 )
V_2 = 512 ;
V_2 = ( V_2 + 63 ) / 64 * 64 ;
if ( V_4 && ( V_4 < ( T_4 ) V_37 ) )
V_3 = NULL ;
if ( V_4 > ( T_4 ) V_37 )
V_4 = V_37 ;
if ( V_3 != NULL )
memcpy ( V_19 , V_3 , V_4 ) ;
if ( ( V_40 = F_9 () ) == NULL )
goto V_44;
if ( ( V_32 = F_10 () ) == NULL )
goto V_44;
F_11 ( V_40 ) ;
V_24 = F_12 ( V_40 ) ;
V_29 = F_12 ( V_40 ) ;
V_25 = F_12 ( V_40 ) ;
V_30 = F_12 ( V_40 ) ;
V_26 = F_12 ( V_40 ) ;
V_27 = F_12 ( V_40 ) ;
V_31 = F_12 ( V_40 ) ;
V_28 = F_12 ( V_40 ) ;
if ( ! F_13 ( V_28 , F_14 () , V_2 - 1 ) )
goto V_44;
for (; ; ) {
for (; ; ) {
int V_45 ;
if ( ! F_15 ( V_7 , 0 , V_36 ++ ) )
goto V_44;
if ( ! V_4 ) {
F_16 ( V_19 , V_37 ) ;
V_45 = 1 ;
} else {
V_45 = 0 ;
V_4 = 0 ;
}
memcpy ( V_22 , V_19 , V_37 ) ;
memcpy ( V_23 , V_19 , V_37 ) ;
for ( V_33 = V_37 - 1 ; V_33 >= 0 ; V_33 -- ) {
V_22 [ V_33 ] ++ ;
if ( V_22 [ V_33 ] != 0 )
break;
}
if ( ! F_17 ( V_19 , V_37 , V_21 , NULL , V_15 , NULL ) )
goto V_44;
if ( ! F_17 ( V_22 , V_37 , V_23 , NULL , V_15 , NULL ) )
goto V_44;
for ( V_33 = 0 ; V_33 < V_37 ; V_33 ++ )
V_21 [ V_33 ] ^= V_23 [ V_33 ] ;
V_21 [ 0 ] |= 0x80 ;
V_21 [ V_37 - 1 ] |= 0x01 ;
if ( ! F_18 ( V_21 , V_37 , V_30 ) )
goto V_44;
V_39 = F_19 ( V_30 , V_46 , V_40 ,
V_45 , V_7 ) ;
if ( V_39 > 0 )
break;
if ( V_39 != 0 )
goto V_44;
}
if ( ! F_15 ( V_7 , 2 , 0 ) )
goto V_44;
if ( ! F_15 ( V_7 , 3 , 0 ) )
goto V_44;
V_38 = 0 ;
V_35 = ( V_2 - 1 ) / 160 ;
for (; ; ) {
if ( ( V_38 != 0 ) && ! F_15 ( V_7 , 0 , V_38 ) )
goto V_44;
F_20 ( V_25 ) ;
for ( V_34 = 0 ; V_34 <= V_35 ; V_34 ++ ) {
for ( V_33 = V_37 - 1 ; V_33 >= 0 ; V_33 -- ) {
V_22 [ V_33 ] ++ ;
if ( V_22 [ V_33 ] != 0 )
break;
}
if ( ! F_17 ( V_22 , V_37 , V_21 , NULL , V_15 , NULL ) )
goto V_44;
if ( ! F_18 ( V_21 , V_37 , V_24 ) )
goto V_44;
if ( ! F_13 ( V_24 , V_24 , ( V_37 << 3 ) * V_34 ) )
goto V_44;
if ( ! F_21 ( V_25 , V_25 , V_24 ) )
goto V_44;
}
if ( ! F_22 ( V_25 , V_2 - 1 ) )
goto V_44;
if ( ! F_23 ( V_26 , V_25 ) )
goto V_44;
if ( ! F_21 ( V_26 , V_26 , V_28 ) )
goto V_44;
if ( ! F_24 ( V_24 , V_30 ) )
goto V_44;
if ( ! F_25 ( V_27 , V_26 , V_24 , V_40 ) )
goto V_44;
if ( ! F_26 ( V_24 , V_27 , F_14 () ) )
goto V_44;
if ( ! F_26 ( V_31 , V_26 , V_24 ) )
goto V_44;
if ( F_27 ( V_31 , V_28 ) >= 0 ) {
V_39 = F_19 ( V_31 , V_46 , V_40 , 1 , V_7 ) ;
if ( V_39 > 0 )
goto V_47;
if ( V_39 != 0 )
goto V_44;
}
V_38 ++ ;
if ( V_38 >= 4096 )
break;
}
}
V_47:
if ( ! F_15 ( V_7 , 2 , 1 ) )
goto V_44;
if ( ! F_26 ( V_28 , V_31 , F_14 () ) )
goto V_44;
if ( ! F_28 ( V_24 , NULL , V_28 , V_30 , V_40 ) )
goto V_44;
if ( ! F_29 ( V_28 , V_41 ) )
goto V_44;
if ( ! F_30 ( V_32 , V_31 , V_40 ) )
goto V_44;
for (; ; ) {
if ( ! F_31 ( V_29 , V_28 , V_24 , V_31 , V_40 , V_32 ) )
goto V_44;
if ( ! F_32 ( V_29 ) )
break;
if ( ! F_21 ( V_28 , V_28 , F_14 () ) )
goto V_44;
V_41 ++ ;
}
if ( ! F_15 ( V_7 , 3 , 1 ) )
goto V_44;
V_18 = 1 ;
V_44:
if ( V_18 ) {
if ( V_1 -> V_31 )
F_33 ( V_1 -> V_31 ) ;
if ( V_1 -> V_30 )
F_33 ( V_1 -> V_30 ) ;
if ( V_1 -> V_29 )
F_33 ( V_1 -> V_29 ) ;
V_1 -> V_31 = F_34 ( V_31 ) ;
V_1 -> V_30 = F_34 ( V_30 ) ;
V_1 -> V_29 = F_34 ( V_29 ) ;
if ( V_1 -> V_31 == NULL || V_1 -> V_30 == NULL || V_1 -> V_29 == NULL ) {
V_18 = 0 ;
goto V_44;
}
if ( V_5 != NULL )
* V_5 = V_38 ;
if ( V_6 != NULL )
* V_6 = V_41 ;
if ( V_17 )
memcpy ( V_17 , V_19 , V_37 ) ;
}
if ( V_40 ) {
F_35 ( V_40 ) ;
F_36 ( V_40 ) ;
}
if ( V_32 != NULL )
F_37 ( V_32 ) ;
return V_18 ;
}
int F_38 ( T_1 * V_1 , T_4 V_48 , T_4 V_49 ,
const T_3 * V_15 , const unsigned char * V_3 ,
T_4 V_4 , int V_50 , unsigned char * V_17 ,
int * V_5 , unsigned long * V_6 ,
T_2 * V_7 )
{
int V_18 = - 1 ;
unsigned char * V_19 = NULL , * V_51 = NULL ;
unsigned char V_21 [ V_52 ] ;
int V_53 ;
T_5 * V_24 , * V_25 , * V_26 , * V_27 , * V_28 ;
T_5 * V_29 = NULL , * V_30 = NULL , * V_31 = NULL ;
T_6 * V_32 = NULL ;
int V_33 , V_34 , V_35 = 0 , V_36 = 0 , V_37 = V_49 >> 3 ;
int V_38 = 0 ;
int V_39 = 0 ;
T_7 * V_40 = NULL ;
T_8 V_54 ;
unsigned int V_41 = 2 ;
# ifdef F_2
if ( F_3 () )
return F_39 ( V_1 , V_48 , V_49 , V_15 ,
V_3 , V_4 , V_50 ,
V_17 , V_5 , V_6 , V_7 ) ;
# endif
F_40 ( & V_54 ) ;
if ( V_15 == NULL ) {
if ( V_49 == 160 )
V_15 = F_7 () ;
else if ( V_49 == 224 )
V_15 = F_41 () ;
else
V_15 = F_6 () ;
}
V_53 = F_42 ( V_15 ) ;
if ( ! V_1 -> V_31 || ! V_1 -> V_30 || V_50 >= 0 ) {
if ( V_4 == 0 )
V_4 = V_53 ;
V_19 = F_43 ( V_4 ) ;
if ( V_17 )
V_51 = V_17 ;
else
V_51 = F_43 ( V_4 ) ;
if ( ! V_19 || ! V_51 )
goto V_44;
if ( V_3 )
memcpy ( V_19 , V_3 , V_4 ) ;
}
if ( ( V_40 = F_9 () ) == NULL )
goto V_44;
if ( ( V_32 = F_10 () ) == NULL )
goto V_44;
F_11 ( V_40 ) ;
V_24 = F_12 ( V_40 ) ;
V_29 = F_12 ( V_40 ) ;
V_25 = F_12 ( V_40 ) ;
V_26 = F_12 ( V_40 ) ;
V_27 = F_12 ( V_40 ) ;
V_28 = F_12 ( V_40 ) ;
if ( V_1 -> V_31 && V_1 -> V_30 ) {
V_31 = V_1 -> V_31 ;
V_30 = V_1 -> V_30 ;
if ( V_50 >= 0 )
memcpy ( V_51 , V_19 , V_4 ) ;
goto V_55;
} else {
V_31 = F_12 ( V_40 ) ;
V_30 = F_12 ( V_40 ) ;
}
if ( ! F_13 ( V_28 , F_14 () , V_48 - 1 ) )
goto V_44;
for (; ; ) {
for (; ; ) {
unsigned char * V_56 ;
if ( ! F_15 ( V_7 , 0 , V_36 ++ ) )
goto V_44;
if ( ! V_3 ) {
if ( F_16 ( V_19 , V_4 ) < 0 )
goto V_44;
}
if ( ! F_17 ( V_19 , V_4 , V_21 , NULL , V_15 , NULL ) )
goto V_44;
if ( V_53 > V_37 )
V_56 = V_21 + V_53 - V_37 ;
else
V_56 = V_21 ;
if ( V_53 < V_37 )
memset ( V_21 + V_53 , 0 , V_37 - V_53 ) ;
V_56 [ 0 ] |= 0x80 ;
V_56 [ V_37 - 1 ] |= 0x01 ;
if ( ! F_18 ( V_56 , V_37 , V_30 ) )
goto V_44;
V_39 = F_19 ( V_30 , V_46 , V_40 ,
V_3 ? 1 : 0 , V_7 ) ;
if ( V_39 > 0 )
break;
if ( V_39 != 0 )
goto V_44;
if ( V_3 ) {
V_18 = 0 ;
F_4 ( V_57 , V_58 ) ;
goto V_44;
}
}
if ( V_17 )
memcpy ( V_17 , V_19 , V_4 ) ;
if ( ! F_15 ( V_7 , 2 , 0 ) )
goto V_44;
if ( ! F_15 ( V_7 , 3 , 0 ) )
goto V_44;
V_38 = 0 ;
V_35 = ( V_48 - 1 ) / ( V_53 << 3 ) ;
for (; ; ) {
if ( ( V_38 != 0 ) && ! F_15 ( V_7 , 0 , V_38 ) )
goto V_44;
F_20 ( V_25 ) ;
for ( V_34 = 0 ; V_34 <= V_35 ; V_34 ++ ) {
for ( V_33 = V_4 - 1 ; V_33 >= 0 ; V_33 -- ) {
V_19 [ V_33 ] ++ ;
if ( V_19 [ V_33 ] != 0 )
break;
}
if ( ! F_17 ( V_19 , V_4 , V_21 , NULL , V_15 , NULL ) )
goto V_44;
if ( ! F_18 ( V_21 , V_53 , V_24 ) )
goto V_44;
if ( ! F_13 ( V_24 , V_24 , ( V_53 << 3 ) * V_34 ) )
goto V_44;
if ( ! F_21 ( V_25 , V_25 , V_24 ) )
goto V_44;
}
if ( ! F_22 ( V_25 , V_48 - 1 ) )
goto V_44;
if ( ! F_23 ( V_26 , V_25 ) )
goto V_44;
if ( ! F_21 ( V_26 , V_26 , V_28 ) )
goto V_44;
if ( ! F_24 ( V_24 , V_30 ) )
goto V_44;
if ( ! F_25 ( V_27 , V_26 , V_24 , V_40 ) )
goto V_44;
if ( ! F_26 ( V_24 , V_27 , F_14 () ) )
goto V_44;
if ( ! F_26 ( V_31 , V_26 , V_24 ) )
goto V_44;
if ( F_27 ( V_31 , V_28 ) >= 0 ) {
V_39 = F_19 ( V_31 , V_46 , V_40 , 1 , V_7 ) ;
if ( V_39 > 0 )
goto V_47;
if ( V_39 != 0 )
goto V_44;
}
V_38 ++ ;
if ( V_38 >= ( int ) ( 4 * V_48 ) )
break;
}
if ( V_3 ) {
V_18 = 0 ;
F_4 ( V_57 , V_59 ) ;
goto V_44;
}
}
V_47:
if ( ! F_15 ( V_7 , 2 , 1 ) )
goto V_44;
V_55:
if ( ! F_26 ( V_28 , V_31 , F_14 () ) )
goto V_44;
if ( ! F_28 ( V_24 , NULL , V_28 , V_30 , V_40 ) )
goto V_44;
if ( V_50 < 0 ) {
if ( ! F_29 ( V_28 , V_41 ) )
goto V_44;
} else
V_41 = 1 ;
if ( ! F_30 ( V_32 , V_31 , V_40 ) )
goto V_44;
for (; ; ) {
static const unsigned char V_60 [ 4 ] = { 0x67 , 0x67 , 0x65 , 0x6e } ;
if ( V_50 >= 0 ) {
V_21 [ 0 ] = V_50 & 0xff ;
V_21 [ 1 ] = ( V_41 >> 8 ) & 0xff ;
V_21 [ 2 ] = V_41 & 0xff ;
if ( ! F_44 ( & V_54 , V_15 , NULL ) )
goto V_44;
if ( ! F_45 ( & V_54 , V_51 , V_4 ) )
goto V_44;
if ( ! F_45 ( & V_54 , V_60 , sizeof( V_60 ) ) )
goto V_44;
if ( ! F_45 ( & V_54 , V_21 , 3 ) )
goto V_44;
if ( ! F_46 ( & V_54 , V_21 , NULL ) )
goto V_44;
if ( ! F_18 ( V_21 , V_53 , V_28 ) )
goto V_44;
}
if ( ! F_31 ( V_29 , V_28 , V_24 , V_31 , V_40 , V_32 ) )
goto V_44;
if ( ! F_32 ( V_29 ) )
break;
if ( V_50 < 0 && ! F_21 ( V_28 , V_28 , F_14 () ) )
goto V_44;
V_41 ++ ;
if ( V_50 >= 0 && V_41 > 0xffff )
goto V_44;
}
if ( ! F_15 ( V_7 , 3 , 1 ) )
goto V_44;
V_18 = 1 ;
V_44:
if ( V_18 == 1 ) {
if ( V_31 != V_1 -> V_31 ) {
if ( V_1 -> V_31 )
F_33 ( V_1 -> V_31 ) ;
V_1 -> V_31 = F_34 ( V_31 ) ;
}
if ( V_30 != V_1 -> V_30 ) {
if ( V_1 -> V_30 )
F_33 ( V_1 -> V_30 ) ;
V_1 -> V_30 = F_34 ( V_30 ) ;
}
if ( V_1 -> V_29 )
F_33 ( V_1 -> V_29 ) ;
V_1 -> V_29 = F_34 ( V_29 ) ;
if ( V_1 -> V_31 == NULL || V_1 -> V_30 == NULL || V_1 -> V_29 == NULL ) {
V_18 = - 1 ;
goto V_44;
}
if ( V_5 != NULL )
* V_5 = V_38 ;
if ( V_6 != NULL )
* V_6 = V_41 ;
}
if ( V_19 )
F_47 ( V_19 ) ;
if ( V_17 != V_51 )
F_47 ( V_51 ) ;
if ( V_40 ) {
F_35 ( V_40 ) ;
F_36 ( V_40 ) ;
}
if ( V_32 != NULL )
F_37 ( V_32 ) ;
F_48 ( & V_54 ) ;
return V_18 ;
}
int F_49 ( T_1 * V_61 )
{
T_7 * V_40 ;
T_5 * V_62 ;
T_6 * V_32 = NULL ;
int V_63 = - 1 ;
V_40 = F_9 () ;
if ( ! V_40 )
return - 1 ;
F_11 ( V_40 ) ;
if ( F_27 ( V_61 -> V_29 , F_14 () ) <= 0 )
return 0 ;
if ( F_27 ( V_61 -> V_29 , V_61 -> V_31 ) >= 0 )
return 0 ;
V_62 = F_12 ( V_40 ) ;
if ( ! V_62 )
goto V_44;
if ( ( V_32 = F_10 () ) == NULL )
goto V_44;
if ( ! F_30 ( V_32 , V_61 -> V_31 , V_40 ) )
goto V_44;
if ( ! F_31 ( V_62 , V_61 -> V_29 , V_61 -> V_30 , V_61 -> V_31 , V_40 , V_32 ) )
goto V_44;
if ( ! F_27 ( V_62 , F_14 () ) )
V_63 = 1 ;
else
V_63 = 0 ;
V_44:
F_35 ( V_40 ) ;
if ( V_32 )
F_37 ( V_32 ) ;
F_36 ( V_40 ) ;
return V_63 ;
}
