int F_1 ( T_1 * V_1 , T_2 * V_2 )
{
if ( V_2 == NULL )
{
F_2 ( V_3 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_1 -> V_5 ) )
{
F_2 ( V_3 , V_6 ) ;
return ( 0 ) ;
}
return ( F_4 ( V_1 -> V_5 , V_2 ) ) ;
}
int F_5 ( T_1 * V_1 , const char * V_7 , int type )
{
int V_8 ;
T_3 * V_9 ;
int V_10 = 0 ;
T_2 * V_2 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL )
{
F_2 ( V_11 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 )
{
F_2 ( V_11 , V_14 ) ;
goto V_13;
}
if ( type == V_15 )
{
V_8 = V_16 ;
V_2 = F_9 ( V_9 , NULL ) ;
}
else if ( type == V_17 )
{
V_8 = V_18 ;
V_2 = F_10 ( V_9 , NULL , V_1 -> V_19 -> V_20 , V_1 -> V_19 -> V_21 ) ;
}
else
{
F_2 ( V_11 , V_22 ) ;
goto V_13;
}
if ( V_2 == NULL )
{
F_2 ( V_11 , V_8 ) ;
goto V_13;
}
V_10 = F_1 ( V_1 , V_2 ) ;
V_13:
if ( V_2 != NULL ) F_11 ( V_2 ) ;
if ( V_9 != NULL ) F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_13 ( T_1 * V_1 , const unsigned char * V_23 , int V_24 )
{
T_2 * V_2 ;
int V_10 ;
V_2 = F_14 ( NULL , & V_23 , ( long ) V_24 ) ;
if ( V_2 == NULL )
{
F_2 ( V_25 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_1 ( V_1 , V_2 ) ;
F_11 ( V_2 ) ;
return ( V_10 ) ;
}
int F_15 ( T_1 * V_1 , T_4 * V_26 )
{
T_5 * V_27 ;
int V_10 ;
if ( V_26 == NULL )
{
F_2 ( V_28 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_1 -> V_5 ) )
{
F_2 ( V_28 , V_6 ) ;
return ( 0 ) ;
}
if ( ( V_27 = F_16 () ) == NULL )
{
F_2 ( V_28 , V_29 ) ;
return ( 0 ) ;
}
F_17 ( V_26 ) ;
F_18 ( V_27 , V_26 ) ;
V_10 = F_19 ( V_1 -> V_5 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
static int F_19 ( T_6 * V_30 , T_5 * V_27 )
{
int V_31 ;
V_31 = F_21 ( NULL , V_27 ) ;
if ( V_31 < 0 )
{
F_2 ( V_32 , V_33 ) ;
return ( 0 ) ;
}
if ( V_30 -> V_34 [ V_31 ] . V_35 != NULL )
{
T_5 * V_36 ;
V_36 = F_22 ( V_30 -> V_34 [ V_31 ] . V_35 ) ;
F_23 ( V_36 , V_27 ) ;
F_20 ( V_36 ) ;
F_24 () ;
#ifndef F_25
if ( ( V_27 -> type == V_37 ) &&
( F_26 ( V_27 -> V_27 . V_26 ) & V_38 ) )
;
else
#endif
if ( ! F_27 ( V_30 -> V_34 [ V_31 ] . V_35 , V_27 ) )
{
F_11 ( V_30 -> V_34 [ V_31 ] . V_35 ) ;
V_30 -> V_34 [ V_31 ] . V_35 = NULL ;
return 0 ;
}
}
if ( V_30 -> V_34 [ V_31 ] . V_39 != NULL )
F_20 ( V_30 -> V_34 [ V_31 ] . V_39 ) ;
F_28 ( & V_27 -> V_40 , 1 , V_41 ) ;
V_30 -> V_34 [ V_31 ] . V_39 = V_27 ;
V_30 -> V_42 = & ( V_30 -> V_34 [ V_31 ] ) ;
V_30 -> V_43 = 0 ;
return ( 1 ) ;
}
int F_29 ( T_1 * V_1 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_4 * V_26 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL )
{
F_2 ( V_44 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 )
{
F_2 ( V_44 , V_14 ) ;
goto V_13;
}
if ( type == V_15 )
{
V_8 = V_16 ;
V_26 = F_30 ( V_9 , NULL ) ;
}
else if ( type == V_17 )
{
V_8 = V_18 ;
V_26 = F_31 ( V_9 , NULL ,
V_1 -> V_19 -> V_20 , V_1 -> V_19 -> V_21 ) ;
}
else
{
F_2 ( V_44 , V_22 ) ;
goto V_13;
}
if ( V_26 == NULL )
{
F_2 ( V_44 , V_8 ) ;
goto V_13;
}
V_10 = F_15 ( V_1 , V_26 ) ;
F_32 ( V_26 ) ;
V_13:
if ( V_9 != NULL ) F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_33 ( T_1 * V_1 , unsigned char * V_23 , long V_24 )
{
int V_10 ;
const unsigned char * V_45 ;
T_4 * V_26 ;
V_45 = V_23 ;
if ( ( V_26 = F_34 ( NULL , & V_45 , ( long ) V_24 ) ) == NULL )
{
F_2 ( V_46 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_15 ( V_1 , V_26 ) ;
F_32 ( V_26 ) ;
return ( V_10 ) ;
}
int F_35 ( T_1 * V_1 , T_5 * V_27 )
{
int V_10 ;
if ( V_27 == NULL )
{
F_2 ( V_47 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_1 -> V_5 ) )
{
F_2 ( V_47 , V_6 ) ;
return ( 0 ) ;
}
V_10 = F_19 ( V_1 -> V_5 , V_27 ) ;
return ( V_10 ) ;
}
int F_36 ( T_1 * V_1 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_5 * V_27 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL )
{
F_2 ( V_48 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 )
{
F_2 ( V_48 , V_14 ) ;
goto V_13;
}
if ( type == V_17 )
{
V_8 = V_18 ;
V_27 = F_37 ( V_9 , NULL ,
V_1 -> V_19 -> V_20 , V_1 -> V_19 -> V_21 ) ;
}
else if ( type == V_15 )
{
V_8 = V_16 ;
V_27 = F_38 ( V_9 , NULL ) ;
}
else
{
F_2 ( V_48 , V_22 ) ;
goto V_13;
}
if ( V_27 == NULL )
{
F_2 ( V_48 , V_8 ) ;
goto V_13;
}
V_10 = F_35 ( V_1 , V_27 ) ;
F_20 ( V_27 ) ;
V_13:
if ( V_9 != NULL ) F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_39 ( int type , T_1 * V_1 , const unsigned char * V_23 , long V_24 )
{
int V_10 ;
const unsigned char * V_45 ;
T_5 * V_27 ;
V_45 = V_23 ;
if ( ( V_27 = F_40 ( type , NULL , & V_45 , ( long ) V_24 ) ) == NULL )
{
F_2 ( V_49 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_35 ( V_1 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
int F_41 ( T_7 * V_19 , T_2 * V_2 )
{
if ( V_2 == NULL )
{
F_2 ( V_50 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_19 -> V_5 ) )
{
F_2 ( V_50 , V_6 ) ;
return ( 0 ) ;
}
return ( F_4 ( V_19 -> V_5 , V_2 ) ) ;
}
static int F_4 ( T_6 * V_30 , T_2 * V_2 )
{
T_5 * V_27 ;
int V_31 ;
V_27 = F_22 ( V_2 ) ;
if ( V_27 == NULL )
{
F_2 ( V_51 , V_52 ) ;
return ( 0 ) ;
}
V_31 = F_21 ( V_2 , V_27 ) ;
if ( V_31 < 0 )
{
F_2 ( V_51 , V_33 ) ;
F_20 ( V_27 ) ;
return ( 0 ) ;
}
if ( V_30 -> V_34 [ V_31 ] . V_39 != NULL )
{
F_23 ( V_27 , V_30 -> V_34 [ V_31 ] . V_39 ) ;
F_24 () ;
#ifndef F_25
if ( ( V_30 -> V_34 [ V_31 ] . V_39 -> type == V_37 ) &&
( F_26 ( V_30 -> V_34 [ V_31 ] . V_39 -> V_27 . V_26 ) &
V_38 ) )
;
else
#endif
if ( ! F_27 ( V_2 , V_30 -> V_34 [ V_31 ] . V_39 ) )
{
F_20 ( V_30 -> V_34 [ V_31 ] . V_39 ) ;
V_30 -> V_34 [ V_31 ] . V_39 = NULL ;
F_24 () ;
}
}
F_20 ( V_27 ) ;
if ( V_30 -> V_34 [ V_31 ] . V_35 != NULL )
F_11 ( V_30 -> V_34 [ V_31 ] . V_35 ) ;
F_28 ( & V_2 -> V_40 , 1 , V_53 ) ;
V_30 -> V_34 [ V_31 ] . V_35 = V_2 ;
V_30 -> V_42 = & ( V_30 -> V_34 [ V_31 ] ) ;
V_30 -> V_43 = 0 ;
return ( 1 ) ;
}
int F_42 ( T_7 * V_19 , const char * V_7 , int type )
{
int V_8 ;
T_3 * V_9 ;
int V_10 = 0 ;
T_2 * V_2 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL )
{
F_2 ( V_54 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 )
{
F_2 ( V_54 , V_14 ) ;
goto V_13;
}
if ( type == V_15 )
{
V_8 = V_16 ;
V_2 = F_9 ( V_9 , NULL ) ;
}
else if ( type == V_17 )
{
V_8 = V_18 ;
V_2 = F_10 ( V_9 , NULL , V_19 -> V_20 , V_19 -> V_21 ) ;
}
else
{
F_2 ( V_54 , V_22 ) ;
goto V_13;
}
if ( V_2 == NULL )
{
F_2 ( V_54 , V_8 ) ;
goto V_13;
}
V_10 = F_41 ( V_19 , V_2 ) ;
V_13:
if ( V_2 != NULL ) F_11 ( V_2 ) ;
if ( V_9 != NULL ) F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_43 ( T_7 * V_19 , int V_24 , const unsigned char * V_23 )
{
T_2 * V_2 ;
int V_10 ;
V_2 = F_14 ( NULL , & V_23 , ( long ) V_24 ) ;
if ( V_2 == NULL )
{
F_2 ( V_55 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_41 ( V_19 , V_2 ) ;
F_11 ( V_2 ) ;
return ( V_10 ) ;
}
int F_44 ( T_7 * V_19 , T_4 * V_26 )
{
int V_10 ;
T_5 * V_27 ;
if ( V_26 == NULL )
{
F_2 ( V_56 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_19 -> V_5 ) )
{
F_2 ( V_56 , V_6 ) ;
return ( 0 ) ;
}
if ( ( V_27 = F_16 () ) == NULL )
{
F_2 ( V_56 , V_29 ) ;
return ( 0 ) ;
}
F_17 ( V_26 ) ;
F_18 ( V_27 , V_26 ) ;
V_10 = F_19 ( V_19 -> V_5 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
int F_45 ( T_7 * V_19 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_4 * V_26 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL )
{
F_2 ( V_57 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 )
{
F_2 ( V_57 , V_14 ) ;
goto V_13;
}
if ( type == V_15 )
{
V_8 = V_16 ;
V_26 = F_30 ( V_9 , NULL ) ;
}
else if ( type == V_17 )
{
V_8 = V_18 ;
V_26 = F_31 ( V_9 , NULL ,
V_19 -> V_20 , V_19 -> V_21 ) ;
}
else
{
F_2 ( V_57 , V_22 ) ;
goto V_13;
}
if ( V_26 == NULL )
{
F_2 ( V_57 , V_8 ) ;
goto V_13;
}
V_10 = F_44 ( V_19 , V_26 ) ;
F_32 ( V_26 ) ;
V_13:
if ( V_9 != NULL ) F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_46 ( T_7 * V_19 , const unsigned char * V_23 , long V_24 )
{
int V_10 ;
const unsigned char * V_45 ;
T_4 * V_26 ;
V_45 = V_23 ;
if ( ( V_26 = F_34 ( NULL , & V_45 , ( long ) V_24 ) ) == NULL )
{
F_2 ( V_58 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_44 ( V_19 , V_26 ) ;
F_32 ( V_26 ) ;
return ( V_10 ) ;
}
int F_47 ( T_7 * V_19 , T_5 * V_27 )
{
if ( V_27 == NULL )
{
F_2 ( V_59 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_19 -> V_5 ) )
{
F_2 ( V_59 , V_6 ) ;
return ( 0 ) ;
}
return ( F_19 ( V_19 -> V_5 , V_27 ) ) ;
}
int F_48 ( T_7 * V_19 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_5 * V_27 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL )
{
F_2 ( V_60 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 )
{
F_2 ( V_60 , V_14 ) ;
goto V_13;
}
if ( type == V_17 )
{
V_8 = V_18 ;
V_27 = F_37 ( V_9 , NULL ,
V_19 -> V_20 , V_19 -> V_21 ) ;
}
else if ( type == V_15 )
{
V_8 = V_16 ;
V_27 = F_38 ( V_9 , NULL ) ;
}
else
{
F_2 ( V_60 , V_22 ) ;
goto V_13;
}
if ( V_27 == NULL )
{
F_2 ( V_60 , V_8 ) ;
goto V_13;
}
V_10 = F_47 ( V_19 , V_27 ) ;
F_20 ( V_27 ) ;
V_13:
if ( V_9 != NULL ) F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_49 ( int type , T_7 * V_19 , const unsigned char * V_23 ,
long V_24 )
{
int V_10 ;
const unsigned char * V_45 ;
T_5 * V_27 ;
V_45 = V_23 ;
if ( ( V_27 = F_40 ( type , NULL , & V_45 , ( long ) V_24 ) ) == NULL )
{
F_2 ( V_61 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_47 ( V_19 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
int F_50 ( T_7 * V_19 , const char * V_7 )
{
T_3 * V_9 ;
int V_10 = 0 ;
T_2 * V_2 = NULL ;
F_24 () ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL )
{
F_2 ( V_62 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 )
{
F_2 ( V_62 , V_14 ) ;
goto V_13;
}
V_2 = F_51 ( V_9 , NULL , V_19 -> V_20 , V_19 -> V_21 ) ;
if ( V_2 == NULL )
{
F_2 ( V_62 , V_18 ) ;
goto V_13;
}
V_10 = F_41 ( V_19 , V_2 ) ;
if ( F_52 () != 0 )
V_10 = 0 ;
if ( V_10 )
{
T_2 * V_63 ;
int V_64 ;
unsigned long V_65 ;
if ( V_19 -> V_66 != NULL )
{
F_53 ( V_19 -> V_66 , F_11 ) ;
V_19 -> V_66 = NULL ;
}
while ( ( V_63 = F_10 ( V_9 , NULL , V_19 -> V_20 , V_19 -> V_21 ) )
!= NULL )
{
V_64 = F_54 ( V_19 , V_63 ) ;
if ( ! V_64 )
{
F_11 ( V_63 ) ;
V_10 = 0 ;
goto V_13;
}
}
V_65 = F_55 () ;
if ( F_56 ( V_65 ) == V_67 && F_57 ( V_65 ) == V_68 )
F_24 () ;
else
V_10 = 0 ;
}
V_13:
if ( V_2 != NULL ) F_11 ( V_2 ) ;
if ( V_9 != NULL ) F_12 ( V_9 ) ;
return ( V_10 ) ;
}
