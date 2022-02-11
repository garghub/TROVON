long F_1 ( T_1 * V_1 , int V_2 , long V_3 , char * V_4 )
{
int V_5 ;
long V_6 ;
V_5 = F_2 ( V_1 -> type ) ;
switch ( V_2 )
{
case V_7 :
if ( V_5 == V_8 )
{
V_6 = V_1 -> V_9 = ( int ) V_3 ;
}
else
{
F_3 ( V_10 , V_11 ) ;
V_6 = 0 ;
}
break;
case V_12 :
if ( V_5 == V_8 )
{
V_6 = V_1 -> V_9 ;
}
else
{
F_3 ( V_10 , V_11 ) ;
V_6 = 0 ;
}
break;
default:
F_3 ( V_10 , V_13 ) ;
V_6 = 0 ;
}
return ( V_6 ) ;
}
int F_4 ( T_1 * V_1 , int type )
{
T_1 * V_6 = NULL ;
if ( ( V_6 = F_5 () ) == NULL ) goto V_14;
if ( ! F_6 ( V_6 , type ) ) goto V_14;
if ( ! F_7 ( V_1 , V_6 ) ) goto V_14;
return ( 1 ) ;
V_14:
if ( V_6 != NULL ) F_8 ( V_6 ) ;
return ( 0 ) ;
}
int F_7 ( T_1 * V_1 , T_1 * V_15 )
{
int V_16 ;
V_16 = F_2 ( V_1 -> type ) ;
switch ( V_16 )
{
case V_8 :
if ( V_1 -> V_17 . V_18 -> V_19 != NULL )
F_9 ( V_1 -> V_17 . V_18 -> V_19 ) ;
V_1 -> V_17 . V_18 -> V_19 = V_15 ;
break;
case V_20 :
case V_21 :
case V_22 :
case V_23 :
case V_24 :
default:
F_3 ( V_25 , V_26 ) ;
goto V_14;
}
return ( 1 ) ;
V_14:
return ( 0 ) ;
}
int F_6 ( T_1 * V_1 , int type )
{
T_2 * V_27 ;
F_9 ( V_1 ) ;
V_27 = F_10 ( type ) ;
switch ( type )
{
case V_8 :
V_1 -> type = V_27 ;
if ( ( V_1 -> V_17 . V_18 = F_11 () ) == NULL )
goto V_14;
F_12 ( V_1 -> V_17 . V_18 -> V_28 , 1 ) ;
break;
case V_21 :
V_1 -> type = V_27 ;
if ( ( V_1 -> V_17 . V_29 = F_13 () ) == NULL )
goto V_14;
break;
case V_23 :
V_1 -> type = V_27 ;
if ( ( V_1 -> V_17 . V_30 = F_14 () )
== NULL ) goto V_14;
F_12 ( V_1 -> V_17 . V_30 -> V_28 , 1 ) ;
break;
case V_22 :
V_1 -> type = V_27 ;
if ( ( V_1 -> V_17 . V_31 = F_15 () )
== NULL ) goto V_14;
F_12 ( V_1 -> V_17 . V_31 -> V_28 , 0 ) ;
break;
case V_20 :
case V_24 :
default:
F_3 ( V_32 , V_26 ) ;
goto V_14;
}
return ( 1 ) ;
V_14:
return ( 0 ) ;
}
int F_16 ( T_1 * V_1 , T_3 * V_33 )
{
int V_16 , V_34 , V_5 ;
T_4 * V_35 ;
F_17 ( T_3 ) * V_36 ;
F_17 ( T_4 ) * V_37 ;
V_16 = F_2 ( V_1 -> type ) ;
switch ( V_16 )
{
case V_8 :
V_36 = V_1 -> V_17 . V_18 -> V_38 ;
V_37 = V_1 -> V_17 . V_18 -> V_39 ;
break;
case V_23 :
V_36 = V_1 -> V_17 . V_30 -> V_38 ;
V_37 = V_1 -> V_17 . V_30 -> V_39 ;
break;
default:
F_3 ( V_40 , V_41 ) ;
return ( 0 ) ;
}
V_5 = F_2 ( V_33 -> V_42 -> V_43 ) ;
V_34 = 0 ;
for ( V_16 = 0 ; V_16 < F_18 ( V_37 ) ; V_16 ++ )
{
V_35 = F_19 ( V_37 , V_16 ) ;
if ( F_2 ( V_35 -> V_43 ) == V_5 )
{
V_34 = 1 ;
break;
}
}
if ( ! V_34 )
{
V_35 = F_20 () ;
V_35 -> V_43 = F_10 ( V_5 ) ;
F_21 ( V_37 , V_35 ) ;
}
F_22 ( V_36 , V_33 ) ;
return ( 1 ) ;
}
int F_23 ( T_1 * V_1 , T_5 * V_44 )
{
int V_16 ;
F_17 ( T_5 ) * * V_45 ;
V_16 = F_2 ( V_1 -> type ) ;
switch ( V_16 )
{
case V_8 :
V_45 = & ( V_1 -> V_17 . V_18 -> V_46 ) ;
break;
case V_23 :
V_45 = & ( V_1 -> V_17 . V_30 -> V_46 ) ;
break;
default:
F_3 ( V_47 , V_41 ) ;
return ( 0 ) ;
}
if ( * V_45 == NULL )
* V_45 = F_24 () ;
F_25 ( & V_44 -> V_48 , 1 , V_49 ) ;
F_26 ( * V_45 , V_44 ) ;
return ( 1 ) ;
}
int F_27 ( T_1 * V_1 , T_6 * V_50 )
{
int V_16 ;
F_17 ( T_6 ) * * V_45 ;
V_16 = F_2 ( V_1 -> type ) ;
switch ( V_16 )
{
case V_8 :
V_45 = & ( V_1 -> V_17 . V_18 -> V_50 ) ;
break;
case V_23 :
V_45 = & ( V_1 -> V_17 . V_30 -> V_50 ) ;
break;
default:
F_3 ( V_51 , V_41 ) ;
return ( 0 ) ;
}
if ( * V_45 == NULL )
* V_45 = F_28 () ;
F_25 ( & V_50 -> V_48 , 1 , V_52 ) ;
F_29 ( * V_45 , V_50 ) ;
return ( 1 ) ;
}
int F_30 ( T_3 * V_53 , T_5 * V_44 , T_7 * V_54 ,
T_8 * V_55 )
{
F_12 ( V_53 -> V_28 , 1 ) ;
F_31 ( & V_53 -> V_56 -> V_57 ,
F_32 ( V_44 ) ) ;
F_33 ( V_53 -> V_56 -> V_58 ) ;
V_53 -> V_56 -> V_58 =
F_34 ( F_35 ( V_44 ) ) ;
F_25 ( & V_54 -> V_48 , 1 , V_59 ) ;
V_53 -> V_54 = V_54 ;
if ( V_54 -> type == V_60 )
V_53 -> V_42 -> V_43 = F_10 ( V_61 ) ;
else
V_53 -> V_42 -> V_43 = F_10 ( F_36 ( V_55 ) ) ;
if ( V_53 -> V_42 -> V_62 != NULL )
F_37 ( V_53 -> V_42 -> V_62 ) ;
if ( ( V_53 -> V_42 -> V_62 = F_38 () ) == NULL )
goto V_14;
V_53 -> V_42 -> V_62 -> type = V_63 ;
V_53 -> V_64 -> V_43 = F_10 ( F_39 ( V_54 -> type ) ) ;
if ( V_53 -> V_64 -> V_62 != NULL )
F_37 ( V_53 -> V_64 -> V_62 ) ;
if ( ( V_53 -> V_64 -> V_62 = F_38 () ) == NULL )
goto V_14;
V_53 -> V_64 -> V_62 -> type = V_63 ;
return ( 1 ) ;
V_14:
return ( 0 ) ;
}
T_3 * F_40 ( T_1 * V_1 , T_5 * V_44 , T_7 * V_54 ,
T_8 * V_55 )
{
T_3 * V_65 ;
if ( ( V_65 = F_41 () ) == NULL ) goto V_14;
if ( ! F_30 ( V_65 , V_44 , V_54 , V_55 ) ) goto V_14;
if ( ! F_16 ( V_1 , V_65 ) ) goto V_14;
return ( V_65 ) ;
V_14:
return ( NULL ) ;
}
int F_42 ( T_9 * V_53 , T_5 * V_44 )
{
F_12 ( V_53 -> V_28 , 0 ) ;
F_31 ( & V_53 -> V_56 -> V_57 ,
F_32 ( V_44 ) ) ;
F_33 ( V_53 -> V_56 -> V_58 ) ;
V_53 -> V_56 -> V_58 =
F_34 ( F_35 ( V_44 ) ) ;
F_43 ( V_53 -> V_66 ) ;
V_53 -> V_66 = ( T_4 * ) F_44 ( V_67 ,
( char * (*)() ) V_68 ,
( char * ) V_44 -> V_69 -> V_70 -> V_71 ) ;
F_25 ( & V_44 -> V_48 , 1 , V_49 ) ;
V_53 -> V_46 = V_44 ;
return ( 1 ) ;
}
T_5 * F_45 ( T_1 * V_1 , T_3 * V_65 )
{
if ( F_46 ( V_1 ) )
return ( F_47 ( V_1 -> V_17 . V_18 -> V_46 ,
V_65 -> V_56 -> V_57 ,
V_65 -> V_56 -> V_58 ) ) ;
else
return ( NULL ) ;
}
int F_48 ( T_1 * V_1 , const T_10 * V_72 )
{
int V_16 ;
T_11 * V_73 ;
V_16 = F_2 ( V_1 -> type ) ;
switch ( V_16 )
{
case V_23 :
V_73 = V_1 -> V_17 . V_30 -> V_74 ;
break;
case V_22 :
V_73 = V_1 -> V_17 . V_31 -> V_74 ;
break;
default:
F_3 ( V_75 , V_41 ) ;
return ( 0 ) ;
}
V_73 -> V_72 = V_72 ;
return 1 ;
}
