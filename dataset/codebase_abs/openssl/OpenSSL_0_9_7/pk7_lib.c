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
if ( V_6 && F_3 ( V_1 -> V_10 . V_11 -> V_12 ) )
{
T_2 * V_13 ;
V_13 = V_1 -> V_10 . V_11 -> V_12 -> V_10 . V_14 ;
F_4 ( V_13 ) ;
V_1 -> V_10 . V_11 -> V_12 -> V_10 . V_14 = NULL ;
}
}
else
{
F_5 ( V_15 , V_16 ) ;
V_6 = 0 ;
}
break;
case V_17 :
if ( V_5 == V_8 )
{
if( ! V_1 -> V_10 . V_11 || ! V_1 -> V_10 . V_11 -> V_12 -> V_10 . V_18 )
V_6 = 1 ;
else V_6 = 0 ;
V_1 -> V_9 = V_6 ;
}
else
{
F_5 ( V_15 , V_16 ) ;
V_6 = 0 ;
}
break;
default:
F_5 ( V_15 , V_19 ) ;
V_6 = 0 ;
}
return ( V_6 ) ;
}
int F_6 ( T_1 * V_1 , int type )
{
T_1 * V_6 = NULL ;
if ( ( V_6 = F_7 () ) == NULL ) goto V_20;
if ( ! F_8 ( V_6 , type ) ) goto V_20;
if ( ! F_9 ( V_1 , V_6 ) ) goto V_20;
return ( 1 ) ;
V_20:
if ( V_6 != NULL ) F_10 ( V_6 ) ;
return ( 0 ) ;
}
int F_9 ( T_1 * V_1 , T_1 * V_21 )
{
int V_22 ;
V_22 = F_2 ( V_1 -> type ) ;
switch ( V_22 )
{
case V_8 :
if ( V_1 -> V_10 . V_11 -> V_12 != NULL )
F_10 ( V_1 -> V_10 . V_11 -> V_12 ) ;
V_1 -> V_10 . V_11 -> V_12 = V_21 ;
break;
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
default:
F_5 ( V_28 , V_29 ) ;
goto V_20;
}
return ( 1 ) ;
V_20:
return ( 0 ) ;
}
int F_8 ( T_1 * V_1 , int type )
{
T_3 * V_30 ;
V_30 = F_11 ( type ) ;
switch ( type )
{
case V_8 :
V_1 -> type = V_30 ;
if ( ( V_1 -> V_10 . V_11 = F_12 () ) == NULL )
goto V_20;
F_13 ( V_1 -> V_10 . V_11 -> V_31 , 1 ) ;
break;
case V_24 :
V_1 -> type = V_30 ;
if ( ( V_1 -> V_10 . V_14 = F_14 () ) == NULL )
goto V_20;
break;
case V_26 :
V_1 -> type = V_30 ;
if ( ( V_1 -> V_10 . V_32 = F_15 () )
== NULL ) goto V_20;
F_13 ( V_1 -> V_10 . V_32 -> V_31 , 1 ) ;
V_1 -> V_10 . V_32 -> V_33 -> V_34
= F_11 ( V_24 ) ;
break;
case V_25 :
V_1 -> type = V_30 ;
if ( ( V_1 -> V_10 . V_35 = F_16 () )
== NULL ) goto V_20;
F_13 ( V_1 -> V_10 . V_35 -> V_31 , 0 ) ;
V_1 -> V_10 . V_35 -> V_33 -> V_34
= F_11 ( V_24 ) ;
break;
case V_27 :
V_1 -> type = V_30 ;
if ( ( V_1 -> V_10 . V_36 = F_17 () )
== NULL ) goto V_20;
F_13 ( V_1 -> V_10 . V_36 -> V_31 , 0 ) ;
V_1 -> V_10 . V_36 -> V_33 -> V_34
= F_11 ( V_24 ) ;
break;
case V_23 :
default:
F_5 ( V_37 , V_29 ) ;
goto V_20;
}
return ( 1 ) ;
V_20:
return ( 0 ) ;
}
int F_18 ( T_1 * V_1 , T_4 * V_38 )
{
int V_22 , V_39 , V_5 ;
T_5 * V_40 ;
F_19 ( T_4 ) * V_41 ;
F_19 ( T_5 ) * V_42 ;
V_22 = F_2 ( V_1 -> type ) ;
switch ( V_22 )
{
case V_8 :
V_41 = V_1 -> V_10 . V_11 -> V_43 ;
V_42 = V_1 -> V_10 . V_11 -> V_44 ;
break;
case V_26 :
V_41 = V_1 -> V_10 . V_32 -> V_43 ;
V_42 = V_1 -> V_10 . V_32 -> V_44 ;
break;
default:
F_5 ( V_45 , V_46 ) ;
return ( 0 ) ;
}
V_5 = F_2 ( V_38 -> V_47 -> V_48 ) ;
V_39 = 0 ;
for ( V_22 = 0 ; V_22 < F_20 ( V_42 ) ; V_22 ++ )
{
V_40 = F_21 ( V_42 , V_22 ) ;
if ( F_2 ( V_40 -> V_48 ) == V_5 )
{
V_39 = 1 ;
break;
}
}
if ( ! V_39 )
{
if( ! ( V_40 = F_22 () )
|| ! ( V_40 -> V_49 = F_23 () ) ) {
F_5 ( V_45 , V_50 ) ;
return ( 0 ) ;
}
V_40 -> V_48 = F_11 ( V_5 ) ;
V_40 -> V_49 -> type = V_51 ;
F_24 ( V_42 , V_40 ) ;
}
F_25 ( V_41 , V_38 ) ;
return ( 1 ) ;
}
int F_26 ( T_1 * V_1 , T_6 * V_52 )
{
int V_22 ;
F_19 ( T_6 ) * * V_53 ;
V_22 = F_2 ( V_1 -> type ) ;
switch ( V_22 )
{
case V_8 :
V_53 = & ( V_1 -> V_10 . V_11 -> V_54 ) ;
break;
case V_26 :
V_53 = & ( V_1 -> V_10 . V_32 -> V_54 ) ;
break;
default:
F_5 ( V_55 , V_46 ) ;
return ( 0 ) ;
}
if ( * V_53 == NULL )
* V_53 = F_27 () ;
F_28 ( & V_52 -> V_56 , 1 , V_57 ) ;
F_29 ( * V_53 , V_52 ) ;
return ( 1 ) ;
}
int F_30 ( T_1 * V_1 , T_7 * V_58 )
{
int V_22 ;
F_19 ( T_7 ) * * V_53 ;
V_22 = F_2 ( V_1 -> type ) ;
switch ( V_22 )
{
case V_8 :
V_53 = & ( V_1 -> V_10 . V_11 -> V_58 ) ;
break;
case V_26 :
V_53 = & ( V_1 -> V_10 . V_32 -> V_58 ) ;
break;
default:
F_5 ( V_59 , V_46 ) ;
return ( 0 ) ;
}
if ( * V_53 == NULL )
* V_53 = F_31 () ;
F_28 ( & V_58 -> V_56 , 1 , V_60 ) ;
F_32 ( * V_53 , V_58 ) ;
return ( 1 ) ;
}
int F_33 ( T_4 * V_61 , T_6 * V_52 , T_8 * V_62 ,
const T_9 * V_63 )
{
char V_64 ;
if ( V_62 -> type == V_65 ) V_64 = 1 ;
else V_64 = 0 ;
F_13 ( V_61 -> V_31 , 1 ) ;
F_34 ( & V_61 -> V_66 -> V_67 ,
F_35 ( V_52 ) ) ;
F_36 ( V_61 -> V_66 -> V_68 ) ;
V_61 -> V_66 -> V_68 =
F_37 ( F_38 ( V_52 ) ) ;
F_28 ( & V_62 -> V_56 , 1 , V_69 ) ;
V_61 -> V_62 = V_62 ;
if ( V_64 ) V_61 -> V_47 -> V_48 = F_11 ( V_70 ) ;
else
V_61 -> V_47 -> V_48 = F_11 ( F_39 ( V_63 ) ) ;
if ( V_61 -> V_47 -> V_49 != NULL )
F_40 ( V_61 -> V_47 -> V_49 ) ;
if ( ( V_61 -> V_47 -> V_49 = F_23 () ) == NULL )
goto V_20;
V_61 -> V_47 -> V_49 -> type = V_51 ;
V_61 -> V_71 -> V_48 = F_11 ( F_41 ( V_62 -> type ) ) ;
if ( V_61 -> V_71 -> V_49 != NULL )
F_40 ( V_61 -> V_71 -> V_49 ) ;
if( V_64 ) V_61 -> V_71 -> V_49 = NULL ;
else {
if ( ! ( V_61 -> V_71 -> V_49 = F_23 () ) )
goto V_20;
V_61 -> V_71 -> V_49 -> type = V_51 ;
}
return ( 1 ) ;
V_20:
return ( 0 ) ;
}
T_4 * F_42 ( T_1 * V_1 , T_6 * V_52 , T_8 * V_62 ,
const T_9 * V_63 )
{
T_4 * V_72 ;
if ( ( V_72 = F_43 () ) == NULL ) goto V_20;
if ( ! F_33 ( V_72 , V_52 , V_62 , V_63 ) ) goto V_20;
if ( ! F_18 ( V_1 , V_72 ) ) goto V_20;
return ( V_72 ) ;
V_20:
return ( NULL ) ;
}
int F_44 ( T_10 * V_61 , T_6 * V_52 )
{
F_13 ( V_61 -> V_31 , 0 ) ;
F_34 ( & V_61 -> V_66 -> V_67 ,
F_35 ( V_52 ) ) ;
F_36 ( V_61 -> V_66 -> V_68 ) ;
V_61 -> V_66 -> V_68 =
F_37 ( F_38 ( V_52 ) ) ;
F_45 ( V_61 -> V_73 ) ;
V_61 -> V_73 = F_46 ( V_52 -> V_74 -> V_75 -> V_76 ) ;
F_28 ( & V_52 -> V_56 , 1 , V_57 ) ;
V_61 -> V_54 = V_52 ;
return ( 1 ) ;
}
T_6 * F_47 ( T_1 * V_1 , T_4 * V_72 )
{
if ( F_48 ( V_1 ) )
return ( F_49 ( V_1 -> V_10 . V_11 -> V_54 ,
V_72 -> V_66 -> V_67 ,
V_72 -> V_66 -> V_68 ) ) ;
else
return ( NULL ) ;
}
int F_50 ( T_1 * V_1 , const T_11 * V_77 )
{
int V_22 ;
T_3 * V_78 ;
T_12 * V_79 ;
V_22 = F_2 ( V_1 -> type ) ;
switch ( V_22 )
{
case V_26 :
V_79 = V_1 -> V_10 . V_32 -> V_33 ;
break;
case V_25 :
V_79 = V_1 -> V_10 . V_35 -> V_33 ;
break;
default:
F_5 ( V_80 , V_46 ) ;
return ( 0 ) ;
}
V_22 = F_51 ( V_77 ) ;
if( V_22 == V_81 ) {
F_5 ( V_80 , V_82 ) ;
return ( 0 ) ;
}
V_78 = F_11 ( V_22 ) ;
V_79 -> V_77 = V_77 ;
return 1 ;
}
