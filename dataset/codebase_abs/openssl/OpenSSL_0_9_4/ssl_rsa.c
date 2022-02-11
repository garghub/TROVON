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
int F_13 ( T_1 * V_1 , unsigned char * V_23 , int V_24 )
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
F_17 ( & V_26 -> V_30 , 1 , V_31 ) ;
F_18 ( V_27 , V_26 ) ;
V_10 = F_19 ( V_1 -> V_5 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
static int F_19 ( T_6 * V_32 , T_5 * V_27 )
{
int V_33 , V_34 = 0 , V_35 = 0 ;
V_33 = F_21 ( NULL , V_27 ) ;
if ( V_33 < 0 )
{
F_2 ( V_36 , V_37 ) ;
return ( 0 ) ;
}
if ( V_32 -> V_38 [ V_33 ] . V_39 != NULL )
{
T_5 * V_40 ;
V_40 = F_22 ( V_32 -> V_38 [ V_33 ] . V_39 ) ;
F_23 ( V_40 , V_27 ) ;
F_20 ( V_40 ) ;
F_24 () ;
#ifndef F_25
if ( ( V_27 -> type == V_41 ) &&
( F_26 ( V_27 -> V_27 . V_26 ) &
V_42 ) )
V_34 = 1 ;
else
#endif
if ( ! F_27 ( V_32 -> V_38 [ V_33 ] . V_39 , V_27 ) )
{
if ( ( V_33 == V_43 ) || ( V_33 == V_44 ) )
{
V_33 = ( V_33 == V_43 ) ?
V_44 : V_43 ;
if ( V_32 -> V_38 [ V_33 ] . V_39 == NULL )
V_34 = 1 ;
else
{
if ( ! F_27 (
V_32 -> V_38 [ V_33 ] . V_39 , V_27 ) )
V_35 = 1 ;
else
V_34 = 1 ;
}
}
else
V_35 = 1 ;
}
else
V_34 = 1 ;
}
else
V_34 = 1 ;
if ( V_35 )
{
F_11 ( V_32 -> V_38 [ V_33 ] . V_39 ) ;
V_32 -> V_38 [ V_33 ] . V_39 = NULL ;
return ( 0 ) ;
}
if ( V_32 -> V_38 [ V_33 ] . V_45 != NULL )
F_20 ( V_32 -> V_38 [ V_33 ] . V_45 ) ;
F_17 ( & V_27 -> V_30 , 1 , V_46 ) ;
V_32 -> V_38 [ V_33 ] . V_45 = V_27 ;
V_32 -> V_47 = & ( V_32 -> V_38 [ V_33 ] ) ;
V_32 -> V_48 = 0 ;
return ( 1 ) ;
}
int F_28 ( T_1 * V_1 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_4 * V_26 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL )
{
F_2 ( V_49 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 )
{
F_2 ( V_49 , V_14 ) ;
goto V_13;
}
if ( type == V_15 )
{
V_8 = V_16 ;
V_26 = F_29 ( V_9 , NULL ) ;
}
else if ( type == V_17 )
{
V_8 = V_18 ;
V_26 = F_30 ( V_9 , NULL ,
V_1 -> V_19 -> V_20 , V_1 -> V_19 -> V_21 ) ;
}
else
{
F_2 ( V_49 , V_22 ) ;
goto V_13;
}
if ( V_26 == NULL )
{
F_2 ( V_49 , V_8 ) ;
goto V_13;
}
V_10 = F_15 ( V_1 , V_26 ) ;
F_31 ( V_26 ) ;
V_13:
if ( V_9 != NULL ) F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_32 ( T_1 * V_1 , unsigned char * V_23 , long V_24 )
{
int V_10 ;
unsigned char * V_50 ;
T_4 * V_26 ;
V_50 = V_23 ;
if ( ( V_26 = F_33 ( NULL , & V_50 , ( long ) V_24 ) ) == NULL )
{
F_2 ( V_51 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_15 ( V_1 , V_26 ) ;
F_31 ( V_26 ) ;
return ( V_10 ) ;
}
int F_34 ( T_1 * V_1 , T_5 * V_27 )
{
int V_10 ;
if ( V_27 == NULL )
{
F_2 ( V_52 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_1 -> V_5 ) )
{
F_2 ( V_52 , V_6 ) ;
return ( 0 ) ;
}
V_10 = F_19 ( V_1 -> V_5 , V_27 ) ;
return ( V_10 ) ;
}
int F_35 ( T_1 * V_1 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_5 * V_27 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL )
{
F_2 ( V_53 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 )
{
F_2 ( V_53 , V_14 ) ;
goto V_13;
}
if ( type == V_17 )
{
V_8 = V_18 ;
V_27 = F_36 ( V_9 , NULL ,
V_1 -> V_19 -> V_20 , V_1 -> V_19 -> V_21 ) ;
}
else
{
F_2 ( V_53 , V_22 ) ;
goto V_13;
}
if ( V_27 == NULL )
{
F_2 ( V_53 , V_8 ) ;
goto V_13;
}
V_10 = F_34 ( V_1 , V_27 ) ;
F_20 ( V_27 ) ;
V_13:
if ( V_9 != NULL ) F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_37 ( int type , T_1 * V_1 , unsigned char * V_23 , long V_24 )
{
int V_10 ;
unsigned char * V_50 ;
T_5 * V_27 ;
V_50 = V_23 ;
if ( ( V_27 = F_38 ( type , NULL , & V_50 , ( long ) V_24 ) ) == NULL )
{
F_2 ( V_54 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_34 ( V_1 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
int F_39 ( T_7 * V_19 , T_2 * V_2 )
{
if ( V_2 == NULL )
{
F_2 ( V_55 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_19 -> V_5 ) )
{
F_2 ( V_55 , V_6 ) ;
return ( 0 ) ;
}
return ( F_4 ( V_19 -> V_5 , V_2 ) ) ;
}
static int F_4 ( T_6 * V_32 , T_2 * V_2 )
{
T_5 * V_27 ;
int V_33 , V_34 = 0 , V_35 = 0 ;
V_27 = F_22 ( V_2 ) ;
if ( V_27 == NULL )
{
F_2 ( V_56 , V_57 ) ;
return ( 0 ) ;
}
V_33 = F_21 ( V_2 , V_27 ) ;
if ( V_33 < 0 )
{
F_2 ( V_56 , V_37 ) ;
F_20 ( V_27 ) ;
return ( 0 ) ;
}
if ( V_32 -> V_38 [ V_33 ] . V_45 != NULL )
{
F_23 ( V_27 , V_32 -> V_38 [ V_33 ] . V_45 ) ;
F_24 () ;
#ifndef F_25
if ( ( V_32 -> V_38 [ V_33 ] . V_45 -> type == V_41 ) &&
( F_26 ( V_32 -> V_38 [ V_33 ] . V_45 -> V_27 . V_26 ) &
V_42 ) )
V_34 = 1 ;
else
#endif
{
if ( ! F_27 ( V_2 , V_32 -> V_38 [ V_33 ] . V_45 ) )
{
if ( ( V_33 == V_43 ) || ( V_33 == V_44 ) )
{
V_33 = ( V_33 == V_43 ) ?
V_44 : V_43 ;
if ( V_32 -> V_38 [ V_33 ] . V_45 == NULL )
V_34 = 1 ;
else
{
if ( ! F_27 ( V_2 ,
V_32 -> V_38 [ V_33 ] . V_45 ) )
V_35 = 1 ;
else
V_34 = 1 ;
}
}
else
V_35 = 1 ;
}
else
V_34 = 1 ;
}
}
else
V_34 = 1 ;
F_20 ( V_27 ) ;
if ( V_35 )
{
F_20 ( V_32 -> V_38 [ V_33 ] . V_45 ) ;
V_32 -> V_38 [ V_33 ] . V_45 = NULL ;
}
if ( V_32 -> V_38 [ V_33 ] . V_39 != NULL )
F_11 ( V_32 -> V_38 [ V_33 ] . V_39 ) ;
F_17 ( & V_2 -> V_30 , 1 , V_58 ) ;
V_32 -> V_38 [ V_33 ] . V_39 = V_2 ;
V_32 -> V_47 = & ( V_32 -> V_38 [ V_33 ] ) ;
V_32 -> V_48 = 0 ;
return ( 1 ) ;
}
int F_40 ( T_7 * V_19 , const char * V_7 , int type )
{
int V_8 ;
T_3 * V_9 ;
int V_10 = 0 ;
T_2 * V_2 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL )
{
F_2 ( V_59 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 )
{
F_2 ( V_59 , V_14 ) ;
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
F_2 ( V_59 , V_22 ) ;
goto V_13;
}
if ( V_2 == NULL )
{
F_2 ( V_59 , V_8 ) ;
goto V_13;
}
V_10 = F_39 ( V_19 , V_2 ) ;
V_13:
if ( V_2 != NULL ) F_11 ( V_2 ) ;
if ( V_9 != NULL ) F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_41 ( T_7 * V_19 , int V_24 , unsigned char * V_23 )
{
T_2 * V_2 ;
int V_10 ;
V_2 = F_14 ( NULL , & V_23 , ( long ) V_24 ) ;
if ( V_2 == NULL )
{
F_2 ( V_60 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_39 ( V_19 , V_2 ) ;
F_11 ( V_2 ) ;
return ( V_10 ) ;
}
int F_42 ( T_7 * V_19 , T_4 * V_26 )
{
int V_10 ;
T_5 * V_27 ;
if ( V_26 == NULL )
{
F_2 ( V_61 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_19 -> V_5 ) )
{
F_2 ( V_61 , V_6 ) ;
return ( 0 ) ;
}
if ( ( V_27 = F_16 () ) == NULL )
{
F_2 ( V_61 , V_29 ) ;
return ( 0 ) ;
}
F_17 ( & V_26 -> V_30 , 1 , V_31 ) ;
F_18 ( V_27 , V_26 ) ;
V_10 = F_19 ( V_19 -> V_5 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
int F_43 ( T_7 * V_19 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_4 * V_26 = NULL ;
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
if ( type == V_15 )
{
V_8 = V_16 ;
V_26 = F_29 ( V_9 , NULL ) ;
}
else if ( type == V_17 )
{
V_8 = V_18 ;
V_26 = F_30 ( V_9 , NULL ,
V_19 -> V_20 , V_19 -> V_21 ) ;
}
else
{
F_2 ( V_62 , V_22 ) ;
goto V_13;
}
if ( V_26 == NULL )
{
F_2 ( V_62 , V_8 ) ;
goto V_13;
}
V_10 = F_42 ( V_19 , V_26 ) ;
F_31 ( V_26 ) ;
V_13:
if ( V_9 != NULL ) F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_44 ( T_7 * V_19 , unsigned char * V_23 , long V_24 )
{
int V_10 ;
unsigned char * V_50 ;
T_4 * V_26 ;
V_50 = V_23 ;
if ( ( V_26 = F_33 ( NULL , & V_50 , ( long ) V_24 ) ) == NULL )
{
F_2 ( V_63 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_42 ( V_19 , V_26 ) ;
F_31 ( V_26 ) ;
return ( V_10 ) ;
}
int F_45 ( T_7 * V_19 , T_5 * V_27 )
{
if ( V_27 == NULL )
{
F_2 ( V_64 , V_4 ) ;
return ( 0 ) ;
}
if ( ! F_3 ( & V_19 -> V_5 ) )
{
F_2 ( V_64 , V_6 ) ;
return ( 0 ) ;
}
return ( F_19 ( V_19 -> V_5 , V_27 ) ) ;
}
int F_46 ( T_7 * V_19 , const char * V_7 , int type )
{
int V_8 , V_10 = 0 ;
T_3 * V_9 ;
T_5 * V_27 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL )
{
F_2 ( V_65 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 )
{
F_2 ( V_65 , V_14 ) ;
goto V_13;
}
if ( type == V_17 )
{
V_8 = V_18 ;
V_27 = F_36 ( V_9 , NULL ,
V_19 -> V_20 , V_19 -> V_21 ) ;
}
else
{
F_2 ( V_65 , V_22 ) ;
goto V_13;
}
if ( V_27 == NULL )
{
F_2 ( V_65 , V_8 ) ;
goto V_13;
}
V_10 = F_45 ( V_19 , V_27 ) ;
F_20 ( V_27 ) ;
V_13:
if ( V_9 != NULL ) F_12 ( V_9 ) ;
return ( V_10 ) ;
}
int F_47 ( int type , T_7 * V_19 , unsigned char * V_23 ,
long V_24 )
{
int V_10 ;
unsigned char * V_50 ;
T_5 * V_27 ;
V_50 = V_23 ;
if ( ( V_27 = F_38 ( type , NULL , & V_50 , ( long ) V_24 ) ) == NULL )
{
F_2 ( V_66 , V_16 ) ;
return ( 0 ) ;
}
V_10 = F_45 ( V_19 , V_27 ) ;
F_20 ( V_27 ) ;
return ( V_10 ) ;
}
int F_48 ( T_7 * V_19 , const char * V_7 )
{
T_3 * V_9 ;
int V_10 = 0 ;
T_2 * V_2 = NULL ;
V_9 = F_6 ( F_7 () ) ;
if ( V_9 == NULL )
{
F_2 ( V_67 , V_12 ) ;
goto V_13;
}
if ( F_8 ( V_9 , V_7 ) <= 0 )
{
F_2 ( V_67 , V_14 ) ;
goto V_13;
}
V_2 = F_10 ( V_9 , NULL , V_19 -> V_20 , V_19 -> V_21 ) ;
if ( V_2 == NULL )
{
F_2 ( V_67 , V_18 ) ;
goto V_13;
}
V_10 = F_39 ( V_19 , V_2 ) ;
if ( F_49 () != 0 )
V_10 = 0 ;
if ( V_10 )
{
T_2 * V_68 ;
int V_69 ;
unsigned long V_70 ;
if ( V_19 -> V_71 != NULL )
{
F_50 ( V_19 -> V_71 , F_11 ) ;
V_19 -> V_71 = NULL ;
}
while ( ( V_68 = F_10 ( V_9 , NULL , V_19 -> V_20 , V_19 -> V_21 ) )
!= NULL )
{
V_69 = F_51 ( V_19 , V_68 ) ;
if ( ! V_69 )
{
F_11 ( V_68 ) ;
V_10 = 0 ;
goto V_13;
}
}
V_70 = F_49 () ;
if ( F_52 ( V_70 ) == V_72 && F_53 ( V_70 ) == V_73 )
( void ) F_54 () ;
else
V_10 = 0 ;
}
V_13:
if ( V_2 != NULL ) F_11 ( V_2 ) ;
if ( V_9 != NULL ) F_12 ( V_9 ) ;
return ( V_10 ) ;
}
