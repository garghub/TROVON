int F_1 ( T_1 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_3 , V_4 ) ;
F_3 ( V_1 -> V_5 , V_4 ) ;
F_4 () ;
F_5 ( V_1 -> V_3 , V_4 ) ;
F_5 ( V_1 -> V_5 , V_4 ) ;
F_6 () ;
}
T_1 * F_7 ( void )
{
T_1 * V_6 = NULL ;
T_2 V_7 ;
F_8 ( V_6 , T_1 ) ;
F_9 ( V_6 -> V_3 , V_8 ) ;
F_9 ( V_6 -> V_5 , V_8 ) ;
return ( V_6 ) ;
F_10 ( V_9 ) ;
}
T_1 * F_11 ( T_1 * * V_1 , unsigned char * * V_2 , long V_10 )
{
F_12 ( V_1 , T_1 * , F_7 ) ;
F_13 () ;
F_14 () ;
F_15 ( V_6 -> V_3 , V_11 ) ;
F_15 ( V_6 -> V_5 , V_11 ) ;
F_16 ( V_1 , V_12 , V_13 ) ;
}
void V_12 ( T_1 * V_1 )
{
if( V_1 == NULL ) return;
F_17 ( V_1 -> V_3 ) ;
F_17 ( V_1 -> V_5 ) ;
Free ( ( char * ) V_1 ) ;
}
int F_18 ( T_3 * V_1 , unsigned char * * V_2 )
{
F_2 ( V_1 ) ;
F_3 ( V_1 -> V_14 , V_15 ) ;
F_3 ( V_1 -> V_16 , V_17 ) ;
F_3 ( V_1 -> V_18 , V_17 ) ;
F_3 ( V_1 -> V_19 , V_4 ) ;
F_4 () ;
F_5 ( V_1 -> V_14 , V_15 ) ;
F_5 ( V_1 -> V_16 , V_17 ) ;
F_5 ( V_1 -> V_18 , V_17 ) ;
F_5 ( V_1 -> V_19 , V_4 ) ;
F_6 () ;
}
T_3 * F_19 ( void )
{
T_3 * V_6 = NULL ;
T_2 V_7 ;
F_8 ( V_6 , T_3 ) ;
F_9 ( V_6 -> V_14 , V_20 ) ;
F_9 ( V_6 -> V_16 , V_21 ) ;
V_6 -> V_18 = NULL ;
V_6 -> V_19 = NULL ;
return ( V_6 ) ;
F_10 ( V_22 ) ;
}
T_3 * F_20 ( T_3 * * V_1 , unsigned char * * V_2 ,
long V_10 )
{
F_12 ( V_1 , T_3 * , F_19 ) ;
F_13 () ;
F_14 () ;
F_15 ( V_6 -> V_14 , V_23 ) ;
F_15 ( V_6 -> V_16 , V_24 ) ;
F_21 ( V_6 -> V_18 , V_24 , V_25 ) ;
F_21 ( V_6 -> V_19 , V_11 , V_26 ) ;
F_16 ( V_1 , V_27 , V_28 ) ;
}
void V_27 ( T_3 * V_1 )
{
if( V_1 == NULL ) return;
F_22 ( V_1 -> V_14 ) ;
F_23 ( V_1 -> V_16 ) ;
F_23 ( V_1 -> V_18 ) ;
F_17 ( V_1 -> V_19 ) ;
Free ( ( char * ) V_1 ) ;
}
T_4 * F_24 ( const T_5 * V_29 , int V_16 ,
unsigned char * V_14 , int V_30 )
{
T_4 * V_31 = NULL , * V_32 = NULL , * V_6 = NULL ;
int V_33 ;
T_6 V_34 ;
unsigned char V_35 [ V_36 ] ;
T_3 * V_37 = NULL ;
T_1 * V_38 = NULL ;
T_7 * V_39 = NULL ;
if( ! ( V_38 = F_7 () ) ) goto V_40;
V_31 = V_38 -> V_5 ;
V_33 = F_25 ( V_29 ) ;
V_31 -> V_41 = F_26 ( V_33 ) ;
if( ! ( V_31 -> V_42 = V_20 () ) ) goto V_40;
F_27 ( V_35 , F_28 ( V_29 ) ) ;
F_29 ( & V_34 , V_29 , NULL , V_35 , 0 ) ;
if( F_30 ( & V_34 , V_31 -> V_42 ) < 0 ) {
F_31 ( V_43 ,
V_44 ) ;
goto V_45;
}
F_32 ( & V_34 ) ;
if( ! ( V_37 = F_19 () ) ) goto V_40;
if( ! ( V_39 = F_33 () ) ) goto V_40;
if ( ! V_30 ) V_30 = V_46 ;
if ( ! ( V_39 -> V_47 = Malloc ( V_30 ) ) ) goto V_40;
V_39 -> V_10 = V_30 ;
if ( V_14 ) memcpy ( V_39 -> V_47 , V_14 , V_30 ) ;
else F_27 ( V_39 -> V_47 , V_30 ) ;
if( V_16 <= 0 ) V_16 = V_48 ;
if( ! F_34 ( V_37 -> V_16 , V_16 ) ) goto V_40;
V_37 -> V_14 -> V_49 . V_50 = V_39 ;
V_37 -> V_14 -> type = V_51 ;
V_39 = NULL ;
if( V_33 == V_52 ) {
if( ! ( V_37 -> V_18 = V_21 () ) ) goto V_40;
if( ! F_34 ( V_37 -> V_18 ,
F_35 ( V_29 ) ) ) goto V_40;
}
V_38 -> V_3 -> V_41 = F_26 ( V_53 ) ;
if( ! ( V_38 -> V_3 -> V_42 = V_20 () ) ) goto V_40;
if( ! F_36 ( V_37 , F_18 ,
& V_38 -> V_3 -> V_42 -> V_49 . V_54 ) ) goto V_40;
V_38 -> V_3 -> V_42 -> type = V_26 ;
V_27 ( V_37 ) ;
V_37 = NULL ;
if( ! ( V_6 = V_8 () ) ) goto V_40;
if( ! ( V_6 -> V_42 = V_20 () ) ) goto V_40;
V_6 -> V_41 = F_26 ( V_55 ) ;
if( ! F_36 ( V_38 , F_1 ,
& V_6 -> V_42 -> V_49 . V_54 ) ) goto V_40;
V_6 -> V_42 -> type = V_26 ;
V_12 ( V_38 ) ;
V_38 = NULL ;
return V_6 ;
V_40:
F_31 ( V_43 , V_56 ) ;
V_45:
V_12 ( V_38 ) ;
F_37 ( V_39 ) ;
V_27 ( V_37 ) ;
F_17 ( V_32 ) ;
F_17 ( V_6 ) ;
return NULL ;
}
