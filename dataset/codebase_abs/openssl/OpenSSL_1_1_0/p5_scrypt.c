T_1 * F_1 ( const T_2 * V_1 ,
const unsigned char * V_2 , int V_3 ,
unsigned char * V_4 , T_3 V_5 , T_3 V_6 ,
T_3 V_7 )
{
T_1 * V_8 = NULL , * V_9 = NULL , * V_10 = NULL ;
int V_11 ;
T_4 V_12 = 0 ;
T_5 * V_13 = NULL ;
unsigned char V_14 [ V_15 ] ;
T_6 * V_16 = NULL ;
T_7 * V_17 ;
if ( ! V_1 ) {
F_2 ( V_18 , V_19 ) ;
goto V_20;
}
if ( F_3 ( NULL , 0 , NULL , 0 , V_5 , V_6 , V_7 , 0 , NULL , 0 ) == 0 ) {
F_2 ( V_18 ,
V_21 ) ;
goto V_20;
}
V_11 = F_4 ( V_1 ) ;
if ( V_11 == V_22 ) {
F_2 ( V_18 ,
V_23 ) ;
goto V_20;
}
V_17 = F_5 ( V_11 ) ;
V_16 = F_6 () ;
if ( V_16 == NULL )
goto V_24;
V_8 = V_16 -> V_25 ;
V_8 -> V_26 = V_17 ;
V_8 -> V_27 = F_7 () ;
if ( V_8 -> V_27 == NULL )
goto V_24;
if ( F_8 ( V_1 ) ) {
if ( V_4 )
memcpy ( V_14 , V_4 , F_8 ( V_1 ) ) ;
else if ( F_9 ( V_14 , F_8 ( V_1 ) ) < 0 )
goto V_20;
}
V_13 = F_10 () ;
if ( V_13 == NULL )
goto V_24;
if ( F_11 ( V_13 , V_1 , NULL , NULL , V_14 , 0 ) == 0 )
goto V_20;
if ( F_12 ( V_13 , V_8 -> V_27 ) < 0 ) {
F_2 ( V_18 ,
V_28 ) ;
goto V_20;
}
F_13 ( V_13 ) ;
V_13 = NULL ;
if ( V_11 == V_29 )
V_12 = F_14 ( V_1 ) ;
F_15 ( V_16 -> V_30 ) ;
V_16 -> V_30 = F_16 ( V_2 , V_3 , V_12 , V_5 , V_6 , V_7 ) ;
if ( V_16 -> V_30 == NULL )
goto V_24;
V_10 = F_17 () ;
if ( V_10 == NULL )
goto V_24;
V_10 -> V_26 = F_5 ( V_31 ) ;
if ( F_18 ( F_19 ( T_6 ) , V_16 ,
& V_10 -> V_27 ) == NULL )
goto V_24;
F_20 ( V_16 ) ;
V_16 = NULL ;
return V_10 ;
V_24:
F_2 ( V_18 , V_32 ) ;
V_20:
F_20 ( V_16 ) ;
F_15 ( V_9 ) ;
F_15 ( V_10 ) ;
F_13 ( V_13 ) ;
return NULL ;
}
static T_1 * F_16 ( const unsigned char * V_2 , T_4 V_3 ,
T_4 V_12 , T_3 V_5 , T_3 V_6 ,
T_3 V_7 )
{
T_1 * V_30 = NULL ;
T_8 * V_33 = NULL ;
V_33 = F_21 () ;
if ( V_33 == NULL )
goto V_24;
if ( ! V_3 )
V_3 = V_34 ;
if ( F_22 ( V_33 -> V_2 , V_2 , V_3 ) == 0 )
goto V_24;
if ( V_2 == NULL && F_9 ( V_33 -> V_2 -> V_35 , V_3 ) <= 0 )
goto V_20;
if ( F_23 ( V_33 -> V_36 , V_5 ) == 0 )
goto V_24;
if ( F_23 ( V_33 -> V_37 , V_6 ) == 0 )
goto V_24;
if ( F_23 ( V_33 -> V_38 , V_7 ) == 0 )
goto V_24;
if ( V_12 > 0 ) {
V_33 -> V_39 = F_24 () ;
if ( V_33 -> V_39 == NULL )
goto V_24;
if ( F_25 ( V_33 -> V_39 , V_12 ) == 0 )
goto V_24;
}
V_30 = F_17 () ;
if ( V_30 == NULL )
goto V_24;
V_30 -> V_26 = F_5 ( V_40 ) ;
if ( F_18 ( F_19 ( T_8 ) , V_33 ,
& V_30 -> V_27 ) == NULL )
goto V_24;
F_26 ( V_33 ) ;
return V_30 ;
V_24:
F_2 ( V_41 , V_32 ) ;
V_20:
F_26 ( V_33 ) ;
F_15 ( V_30 ) ;
return NULL ;
}
int F_27 ( T_5 * V_13 , const char * V_42 ,
int V_43 , T_9 * V_44 ,
const T_2 * V_45 , const T_10 * V_46 , int V_47 )
{
unsigned char * V_2 , V_48 [ V_49 ] ;
T_3 V_7 , V_6 , V_5 ;
T_4 V_3 ;
T_4 V_12 = 0 ;
int V_50 = 0 ;
T_8 * V_33 = NULL ;
if ( F_28 ( V_13 ) == NULL ) {
F_29 ( V_51 , V_52 ) ;
goto V_20;
}
V_33 = F_30 ( F_19 ( T_8 ) , V_44 ) ;
if ( V_33 == NULL ) {
F_29 ( V_51 , V_53 ) ;
goto V_20;
}
V_12 = F_31 ( V_13 ) ;
if ( V_33 -> V_39 ) {
T_3 V_54 ;
if ( ( F_32 ( & V_54 , V_33 -> V_39 ) == 0 )
|| ( V_54 != V_12 ) ) {
F_29 ( V_51 ,
V_55 ) ;
goto V_20;
}
}
if ( F_32 ( & V_5 , V_33 -> V_36 ) == 0
|| F_32 ( & V_6 , V_33 -> V_37 ) == 0
|| F_32 ( & V_7 , V_33 -> V_38 ) == 0
|| F_3 ( NULL , 0 , NULL , 0 , V_5 , V_6 , V_7 , 0 , NULL , 0 ) == 0 ) {
F_29 ( V_51 ,
V_56 ) ;
goto V_20;
}
V_2 = V_33 -> V_2 -> V_35 ;
V_3 = V_33 -> V_2 -> V_57 ;
if ( F_3 ( V_42 , V_43 , V_2 , V_3 , V_5 , V_6 , V_7 , 0 , V_48 , V_12 )
== 0 )
goto V_20;
V_50 = F_11 ( V_13 , NULL , NULL , V_48 , NULL , V_47 ) ;
V_20:
if ( V_12 )
F_33 ( V_48 , V_12 ) ;
F_26 ( V_33 ) ;
return V_50 ;
}
