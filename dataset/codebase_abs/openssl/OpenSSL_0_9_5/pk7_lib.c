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
F_8 ( V_1 -> V_17 . V_18 -> V_19 ) ;
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
case V_24 :
V_1 -> type = V_27 ;
if ( ( V_1 -> V_17 . V_32 = F_16 () )
== NULL ) goto V_14;
F_12 ( V_1 -> V_17 . V_32 -> V_28 , 0 ) ;
break;
case V_20 :
default:
F_3 ( V_33 , V_26 ) ;
goto V_14;
}
return ( 1 ) ;
V_14:
return ( 0 ) ;
}
int F_17 ( T_1 * V_1 , T_3 * V_34 )
{
int V_16 , V_35 , V_5 ;
T_4 * V_36 ;
F_18 ( T_3 ) * V_37 ;
F_18 ( T_4 ) * V_38 ;
V_16 = F_2 ( V_1 -> type ) ;
switch ( V_16 )
{
case V_8 :
V_37 = V_1 -> V_17 . V_18 -> V_39 ;
V_38 = V_1 -> V_17 . V_18 -> V_40 ;
break;
case V_23 :
V_37 = V_1 -> V_17 . V_30 -> V_39 ;
V_38 = V_1 -> V_17 . V_30 -> V_40 ;
break;
default:
F_3 ( V_41 , V_42 ) ;
return ( 0 ) ;
}
V_5 = F_2 ( V_34 -> V_43 -> V_44 ) ;
V_35 = 0 ;
for ( V_16 = 0 ; V_16 < F_19 ( V_38 ) ; V_16 ++ )
{
V_36 = F_20 ( V_38 , V_16 ) ;
if ( F_2 ( V_36 -> V_44 ) == V_5 )
{
V_35 = 1 ;
break;
}
}
if ( ! V_35 )
{
if( ! ( V_36 = F_21 () )
|| ! ( V_36 -> V_45 = F_22 () ) ) {
F_3 ( V_41 , V_46 ) ;
return ( 0 ) ;
}
V_36 -> V_44 = F_10 ( V_5 ) ;
V_36 -> V_45 -> type = V_47 ;
F_23 ( V_38 , V_36 ) ;
}
F_24 ( V_37 , V_34 ) ;
return ( 1 ) ;
}
int F_25 ( T_1 * V_1 , T_5 * V_48 )
{
int V_16 ;
F_18 ( T_5 ) * * V_49 ;
V_16 = F_2 ( V_1 -> type ) ;
switch ( V_16 )
{
case V_8 :
V_49 = & ( V_1 -> V_17 . V_18 -> V_50 ) ;
break;
case V_23 :
V_49 = & ( V_1 -> V_17 . V_30 -> V_50 ) ;
break;
default:
F_3 ( V_51 , V_42 ) ;
return ( 0 ) ;
}
if ( * V_49 == NULL )
* V_49 = F_26 () ;
F_27 ( & V_48 -> V_52 , 1 , V_53 ) ;
F_28 ( * V_49 , V_48 ) ;
return ( 1 ) ;
}
int F_29 ( T_1 * V_1 , T_6 * V_54 )
{
int V_16 ;
F_18 ( T_6 ) * * V_49 ;
V_16 = F_2 ( V_1 -> type ) ;
switch ( V_16 )
{
case V_8 :
V_49 = & ( V_1 -> V_17 . V_18 -> V_54 ) ;
break;
case V_23 :
V_49 = & ( V_1 -> V_17 . V_30 -> V_54 ) ;
break;
default:
F_3 ( V_55 , V_42 ) ;
return ( 0 ) ;
}
if ( * V_49 == NULL )
* V_49 = F_30 () ;
F_27 ( & V_54 -> V_52 , 1 , V_56 ) ;
F_31 ( * V_49 , V_54 ) ;
return ( 1 ) ;
}
int F_32 ( T_3 * V_57 , T_5 * V_48 , T_7 * V_58 ,
T_8 * V_59 )
{
char V_60 ;
if ( V_58 -> type == V_61 ) V_60 = 1 ;
else V_60 = 0 ;
F_12 ( V_57 -> V_28 , 1 ) ;
F_33 ( & V_57 -> V_62 -> V_63 ,
F_34 ( V_48 ) ) ;
F_35 ( V_57 -> V_62 -> V_64 ) ;
V_57 -> V_62 -> V_64 =
F_36 ( F_37 ( V_48 ) ) ;
F_27 ( & V_58 -> V_52 , 1 , V_65 ) ;
V_57 -> V_58 = V_58 ;
if ( V_60 ) V_57 -> V_43 -> V_44 = F_10 ( V_66 ) ;
else
V_57 -> V_43 -> V_44 = F_10 ( F_38 ( V_59 ) ) ;
if ( V_57 -> V_43 -> V_45 != NULL )
F_39 ( V_57 -> V_43 -> V_45 ) ;
if ( ( V_57 -> V_43 -> V_45 = F_22 () ) == NULL )
goto V_14;
V_57 -> V_43 -> V_45 -> type = V_47 ;
V_57 -> V_67 -> V_44 = F_10 ( F_40 ( V_58 -> type ) ) ;
if ( V_57 -> V_67 -> V_45 != NULL )
F_39 ( V_57 -> V_67 -> V_45 ) ;
if( V_60 ) V_57 -> V_67 -> V_45 = NULL ;
else {
if ( ! ( V_57 -> V_67 -> V_45 = F_22 () ) )
goto V_14;
V_57 -> V_67 -> V_45 -> type = V_47 ;
}
return ( 1 ) ;
V_14:
return ( 0 ) ;
}
T_3 * F_41 ( T_1 * V_1 , T_5 * V_48 , T_7 * V_58 ,
T_8 * V_59 )
{
T_3 * V_68 ;
if ( ( V_68 = F_42 () ) == NULL ) goto V_14;
if ( ! F_32 ( V_68 , V_48 , V_58 , V_59 ) ) goto V_14;
if ( ! F_17 ( V_1 , V_68 ) ) goto V_14;
return ( V_68 ) ;
V_14:
return ( NULL ) ;
}
int F_43 ( T_9 * V_57 , T_5 * V_48 )
{
F_12 ( V_57 -> V_28 , 0 ) ;
F_33 ( & V_57 -> V_62 -> V_63 ,
F_34 ( V_48 ) ) ;
F_35 ( V_57 -> V_62 -> V_64 ) ;
V_57 -> V_62 -> V_64 =
F_36 ( F_37 ( V_48 ) ) ;
F_44 ( V_57 -> V_69 ) ;
V_57 -> V_69 = ( T_4 * ) F_45 ( V_70 ,
( char * (*)() ) V_71 ,
( char * ) V_48 -> V_72 -> V_73 -> V_74 ) ;
F_27 ( & V_48 -> V_52 , 1 , V_53 ) ;
V_57 -> V_50 = V_48 ;
return ( 1 ) ;
}
T_5 * F_46 ( T_1 * V_1 , T_3 * V_68 )
{
if ( F_47 ( V_1 ) )
return ( F_48 ( V_1 -> V_17 . V_18 -> V_50 ,
V_68 -> V_62 -> V_63 ,
V_68 -> V_62 -> V_64 ) ) ;
else
return ( NULL ) ;
}
int F_49 ( T_1 * V_1 , const T_10 * V_75 )
{
int V_16 ;
T_2 * V_76 ;
T_11 * V_77 ;
V_16 = F_2 ( V_1 -> type ) ;
switch ( V_16 )
{
case V_23 :
V_77 = V_1 -> V_17 . V_30 -> V_78 ;
break;
case V_22 :
V_77 = V_1 -> V_17 . V_31 -> V_78 ;
break;
default:
F_3 ( V_79 , V_42 ) ;
return ( 0 ) ;
}
V_16 = F_50 ( V_75 ) ;
if( V_16 == V_80 ) {
F_3 ( V_79 , V_81 ) ;
return ( 0 ) ;
}
V_76 = F_10 ( V_16 ) ;
V_77 -> V_75 = V_75 ;
return 1 ;
}
