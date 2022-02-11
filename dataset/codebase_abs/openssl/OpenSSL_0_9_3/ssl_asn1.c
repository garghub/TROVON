int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
#define F_2 (sizeof(long)*2)
int V_3 = 0 , V_4 = 0 , V_5 = 0 , V_6 = 0 ;
unsigned char V_7 [ 4 ] , V_8 [ F_2 ] , V_9 [ F_2 ] ;
unsigned char V_10 [ F_2 ] , V_11 [ F_2 ] ;
long V_12 ;
T_2 V_13 ;
F_3 ( V_1 ) ;
if ( ( V_1 == NULL ) || ( ( V_1 -> V_14 == NULL ) && ( V_1 -> V_15 == 0 ) ) )
return ( 0 ) ;
V_13 . V_16 . V_17 = F_2 ;
V_13 . V_16 . type = V_18 ;
V_13 . V_16 . V_19 = V_8 ;
F_4 ( & ( V_13 . V_16 ) , V_20 ) ;
V_13 . V_21 . V_17 = F_2 ;
V_13 . V_21 . type = V_18 ;
V_13 . V_21 . V_19 = V_9 ;
F_4 ( & ( V_13 . V_21 ) , V_1 -> V_21 ) ;
V_13 . V_14 . type = V_22 ;
V_13 . V_14 . V_19 = V_7 ;
if ( V_1 -> V_14 == NULL )
V_12 = V_1 -> V_15 ;
else
V_12 = V_1 -> V_14 -> V_23 ;
if ( V_1 -> V_21 == V_24 )
{
V_13 . V_14 . V_17 = 3 ;
V_7 [ 0 ] = ( ( unsigned char ) ( V_12 >> 16L ) ) & 0xff ;
V_7 [ 1 ] = ( ( unsigned char ) ( V_12 >> 8L ) ) & 0xff ;
V_7 [ 2 ] = ( ( unsigned char ) ( V_12 ) ) & 0xff ;
}
else
{
V_13 . V_14 . V_17 = 2 ;
V_7 [ 0 ] = ( ( unsigned char ) ( V_12 >> 8L ) ) & 0xff ;
V_7 [ 1 ] = ( ( unsigned char ) ( V_12 ) ) & 0xff ;
}
V_13 . V_25 . V_17 = V_1 -> V_26 ;
V_13 . V_25 . type = V_22 ;
V_13 . V_25 . V_19 = V_1 -> V_25 ;
V_13 . V_27 . V_17 = V_1 -> V_28 ;
V_13 . V_27 . type = V_22 ;
V_13 . V_27 . V_19 = V_1 -> V_27 ;
V_13 . V_29 . V_17 = V_1 -> V_30 ;
V_13 . V_29 . type = V_22 ;
V_13 . V_29 . V_19 = V_1 -> V_31 ;
V_13 . V_32 . V_17 = V_1 -> V_33 ;
V_13 . V_32 . type = V_22 ;
V_13 . V_32 . V_19 = V_1 -> V_32 ;
if ( V_1 -> time != 0L )
{
V_13 . time . V_17 = F_2 ;
V_13 . time . type = V_18 ;
V_13 . time . V_19 = V_10 ;
F_4 ( & ( V_13 . time ) , V_1 -> time ) ;
}
if ( V_1 -> V_34 != 0L )
{
V_13 . V_34 . V_17 = F_2 ;
V_13 . V_34 . type = V_18 ;
V_13 . V_34 . V_19 = V_11 ;
F_4 ( & ( V_13 . V_34 ) , V_1 -> V_34 ) ;
}
F_5 ( & ( V_13 . V_16 ) , V_35 ) ;
F_5 ( & ( V_13 . V_21 ) , V_35 ) ;
F_5 ( & ( V_13 . V_14 ) , V_36 ) ;
F_5 ( & ( V_13 . V_27 ) , V_36 ) ;
F_5 ( & ( V_13 . V_25 ) , V_36 ) ;
if ( V_1 -> V_33 > 0 )
F_6 ( & ( V_13 . V_32 ) , V_36 ) ;
if ( V_1 -> time != 0L )
F_7 ( & ( V_13 . time ) , V_35 , 1 , V_3 ) ;
if ( V_1 -> V_34 != 0L )
F_7 ( & ( V_13 . V_34 ) , V_35 , 2 , V_4 ) ;
if ( V_1 -> V_37 != NULL )
F_7 ( V_1 -> V_37 , V_38 , 3 , V_5 ) ;
F_7 ( & V_13 . V_29 , V_36 , 4 , V_6 ) ;
F_8 () ;
F_9 ( & ( V_13 . V_16 ) , V_35 ) ;
F_9 ( & ( V_13 . V_21 ) , V_35 ) ;
F_9 ( & ( V_13 . V_14 ) , V_36 ) ;
F_9 ( & ( V_13 . V_27 ) , V_36 ) ;
F_9 ( & ( V_13 . V_25 ) , V_36 ) ;
if ( V_1 -> V_33 > 0 )
F_10 ( & ( V_13 . V_32 ) , V_36 , 0 ) ;
if ( V_1 -> time != 0L )
F_11 ( & ( V_13 . time ) , V_35 , 1 , V_3 ) ;
if ( V_1 -> V_34 != 0L )
F_11 ( & ( V_13 . V_34 ) , V_35 , 2 , V_4 ) ;
if ( V_1 -> V_37 != NULL )
F_11 ( V_1 -> V_37 , V_38 , 3 , V_5 ) ;
F_11 ( & V_13 . V_29 , V_36 , 4 ,
V_6 ) ;
F_12 () ;
}
T_1 * F_13 ( T_1 * * V_13 , unsigned char * * V_2 ,
long V_17 )
{
int V_16 , V_21 = 0 , V_39 ;
long V_23 ;
T_3 V_40 , * V_41 ;
T_4 V_42 , * V_43 ;
F_14 ( V_13 , T_1 * , V_44 ) ;
V_41 = & V_40 ;
V_43 = & V_42 ;
F_15 () ;
F_16 () ;
V_40 . V_19 = NULL ; V_40 . V_17 = 0 ;
F_17 ( V_41 , V_45 ) ;
V_16 = ( int ) F_18 ( V_41 ) ;
if ( V_40 . V_19 != NULL ) { Free ( V_40 . V_19 ) ; V_40 . V_19 = NULL ; V_40 . V_17 = 0 ; }
F_17 ( V_41 , V_45 ) ;
V_21 = ( int ) F_18 ( V_41 ) ;
V_46 -> V_21 = V_21 ;
if ( V_40 . V_19 != NULL ) { Free ( V_40 . V_19 ) ; V_40 . V_19 = NULL ; V_40 . V_17 = 0 ; }
V_42 . V_19 = NULL ; V_42 . V_17 = 0 ;
F_17 ( V_43 , V_47 ) ;
if ( V_21 == V_24 )
{
if ( V_42 . V_17 != 3 )
{
V_48 . error = V_49 ;
goto V_50;
}
V_23 = 0x02000000L |
( ( unsigned long ) V_42 . V_19 [ 0 ] << 16L ) |
( ( unsigned long ) V_42 . V_19 [ 1 ] << 8L ) |
( unsigned long ) V_42 . V_19 [ 2 ] ;
}
else if ( ( V_21 >> 8 ) == 3 )
{
if ( V_42 . V_17 != 2 )
{
V_48 . error = V_49 ;
goto V_50;
}
V_23 = 0x03000000L |
( ( unsigned long ) V_42 . V_19 [ 0 ] << 8L ) |
( unsigned long ) V_42 . V_19 [ 1 ] ;
}
else
{
F_19 ( V_51 , V_52 ) ;
return ( NULL ) ;
}
V_46 -> V_14 = NULL ;
V_46 -> V_15 = V_23 ;
F_17 ( V_43 , V_47 ) ;
if ( ( V_21 >> 8 ) == V_53 )
V_39 = V_54 ;
else
V_39 = V_55 ;
if ( V_42 . V_17 > V_39 )
V_42 . V_17 = V_39 ;
V_46 -> V_28 = V_42 . V_17 ;
memcpy ( V_46 -> V_27 , V_42 . V_19 , V_42 . V_17 ) ;
F_17 ( V_43 , V_47 ) ;
if ( V_46 -> V_26 > V_56 )
V_46 -> V_26 = V_56 ;
else
V_46 -> V_26 = V_42 . V_17 ;
memcpy ( V_46 -> V_25 , V_42 . V_19 , V_46 -> V_26 ) ;
V_42 . V_17 = 0 ;
F_20 ( V_43 , V_47 , 0 , V_22 ) ;
if ( V_42 . V_17 > V_57 )
V_46 -> V_33 = V_57 ;
else
V_46 -> V_33 = V_42 . V_17 ;
memcpy ( V_46 -> V_32 , V_42 . V_19 , V_46 -> V_33 ) ;
if ( V_42 . V_19 != NULL ) Free ( V_42 . V_19 ) ;
V_40 . V_17 = 0 ;
F_21 ( V_41 , V_45 , 1 ) ;
if ( V_40 . V_19 != NULL )
{
V_46 -> time = F_18 ( V_41 ) ;
Free ( V_40 . V_19 ) ; V_40 . V_19 = NULL ; V_40 . V_17 = 0 ;
}
else
V_46 -> time = time ( NULL ) ;
V_40 . V_17 = 0 ;
F_21 ( V_41 , V_45 , 2 ) ;
if ( V_40 . V_19 != NULL )
{
V_46 -> V_34 = F_18 ( V_41 ) ;
Free ( V_40 . V_19 ) ; V_40 . V_19 = NULL ; V_40 . V_17 = 0 ;
}
else
V_46 -> V_34 = 3 ;
if ( V_46 -> V_37 != NULL )
{
F_22 ( V_46 -> V_37 ) ;
V_46 -> V_37 = NULL ;
}
F_21 ( V_46 -> V_37 , V_58 , 3 ) ;
V_42 . V_17 = 0 ;
V_42 . V_19 = NULL ;
F_21 ( V_43 , V_47 , 4 ) ;
if( V_42 . V_19 != NULL )
{
if ( V_42 . V_17 > V_59 )
F_19 ( V_51 , V_60 ) ;
V_46 -> V_30 = V_42 . V_17 ;
memcpy ( V_46 -> V_31 , V_42 . V_19 , V_42 . V_17 ) ;
Free ( V_42 . V_19 ) ; V_42 . V_19 = NULL ; V_42 . V_17 = 0 ;
}
else
V_46 -> V_30 = 0 ;
F_23 ( V_13 , V_61 , V_51 ) ;
}
