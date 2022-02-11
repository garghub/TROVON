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
if ( V_1 -> V_10 . V_24 -> V_12 != NULL )
F_10 ( V_1 -> V_10 . V_24 -> V_12 ) ;
V_1 -> V_10 . V_24 -> V_12 = V_21 ;
break;
case V_25 :
case V_26 :
case V_27 :
case V_28 :
default:
F_5 ( V_29 , V_30 ) ;
goto V_20;
}
return ( 1 ) ;
V_20:
return ( 0 ) ;
}
int F_8 ( T_1 * V_1 , int type )
{
T_3 * V_31 ;
V_31 = F_11 ( type ) ;
switch ( type )
{
case V_8 :
V_1 -> type = V_31 ;
if ( ( V_1 -> V_10 . V_11 = F_12 () ) == NULL )
goto V_20;
if ( ! F_13 ( V_1 -> V_10 . V_11 -> V_32 , 1 ) )
{
F_14 ( V_1 -> V_10 . V_11 ) ;
V_1 -> V_10 . V_11 = NULL ;
goto V_20;
}
break;
case V_25 :
V_1 -> type = V_31 ;
if ( ( V_1 -> V_10 . V_14 = F_15 () ) == NULL )
goto V_20;
break;
case V_27 :
V_1 -> type = V_31 ;
if ( ( V_1 -> V_10 . V_33 = F_16 () )
== NULL ) goto V_20;
F_13 ( V_1 -> V_10 . V_33 -> V_32 , 1 ) ;
if ( ! F_13 ( V_1 -> V_10 . V_33 -> V_32 , 1 ) )
goto V_20;
V_1 -> V_10 . V_33 -> V_34 -> V_35
= F_11 ( V_25 ) ;
break;
case V_26 :
V_1 -> type = V_31 ;
if ( ( V_1 -> V_10 . V_36 = F_17 () )
== NULL ) goto V_20;
if ( ! F_13 ( V_1 -> V_10 . V_36 -> V_32 , 0 ) )
goto V_20;
V_1 -> V_10 . V_36 -> V_34 -> V_35
= F_11 ( V_25 ) ;
break;
case V_28 :
V_1 -> type = V_31 ;
if ( ( V_1 -> V_10 . V_37 = F_18 () )
== NULL ) goto V_20;
if ( ! F_13 ( V_1 -> V_10 . V_37 -> V_32 , 0 ) )
goto V_20;
V_1 -> V_10 . V_37 -> V_34 -> V_35
= F_11 ( V_25 ) ;
break;
case V_23 :
V_1 -> type = V_31 ;
if ( ( V_1 -> V_10 . V_24 = F_19 () )
== NULL ) goto V_20;
if ( ! F_13 ( V_1 -> V_10 . V_24 -> V_32 , 0 ) )
goto V_20;
break;
default:
F_5 ( V_38 , V_30 ) ;
goto V_20;
}
return ( 1 ) ;
V_20:
return ( 0 ) ;
}
int F_20 ( T_1 * V_1 , int type , T_4 * V_39 )
{
V_1 -> type = F_11 ( type ) ;
V_1 -> V_10 . V_39 = V_39 ;
return 1 ;
}
int F_21 ( T_1 * V_1 , T_5 * V_40 )
{
int V_22 , V_41 , V_5 ;
T_6 * V_42 ;
F_22 ( T_5 ) * V_43 ;
F_22 ( T_6 ) * V_44 ;
V_22 = F_2 ( V_1 -> type ) ;
switch ( V_22 )
{
case V_8 :
V_43 = V_1 -> V_10 . V_11 -> V_45 ;
V_44 = V_1 -> V_10 . V_11 -> V_46 ;
break;
case V_27 :
V_43 = V_1 -> V_10 . V_33 -> V_45 ;
V_44 = V_1 -> V_10 . V_33 -> V_46 ;
break;
default:
F_5 ( V_47 , V_48 ) ;
return ( 0 ) ;
}
V_5 = F_2 ( V_40 -> V_49 -> V_50 ) ;
V_41 = 0 ;
for ( V_22 = 0 ; V_22 < F_23 ( V_44 ) ; V_22 ++ )
{
V_42 = F_24 ( V_44 , V_22 ) ;
if ( F_2 ( V_42 -> V_50 ) == V_5 )
{
V_41 = 1 ;
break;
}
}
if ( ! V_41 )
{
if( ! ( V_42 = F_25 () )
|| ! ( V_42 -> V_51 = F_26 () ) ) {
F_5 ( V_47 , V_52 ) ;
return ( 0 ) ;
}
V_42 -> V_50 = F_11 ( V_5 ) ;
V_42 -> V_51 -> type = V_53 ;
F_27 ( V_44 , V_42 ) ;
}
F_28 ( V_43 , V_40 ) ;
return ( 1 ) ;
}
int F_29 ( T_1 * V_1 , T_7 * V_54 )
{
int V_22 ;
F_22 ( T_7 ) * * V_55 ;
V_22 = F_2 ( V_1 -> type ) ;
switch ( V_22 )
{
case V_8 :
V_55 = & ( V_1 -> V_10 . V_11 -> V_56 ) ;
break;
case V_27 :
V_55 = & ( V_1 -> V_10 . V_33 -> V_56 ) ;
break;
default:
F_5 ( V_57 , V_48 ) ;
return ( 0 ) ;
}
if ( * V_55 == NULL )
* V_55 = F_30 () ;
F_31 ( & V_54 -> V_58 , 1 , V_59 ) ;
F_32 ( * V_55 , V_54 ) ;
return ( 1 ) ;
}
int F_33 ( T_1 * V_1 , T_8 * V_60 )
{
int V_22 ;
F_22 ( T_8 ) * * V_55 ;
V_22 = F_2 ( V_1 -> type ) ;
switch ( V_22 )
{
case V_8 :
V_55 = & ( V_1 -> V_10 . V_11 -> V_60 ) ;
break;
case V_27 :
V_55 = & ( V_1 -> V_10 . V_33 -> V_60 ) ;
break;
default:
F_5 ( V_61 , V_48 ) ;
return ( 0 ) ;
}
if ( * V_55 == NULL )
* V_55 = F_34 () ;
F_31 ( & V_60 -> V_58 , 1 , V_62 ) ;
F_35 ( * V_55 , V_60 ) ;
return ( 1 ) ;
}
int F_36 ( T_5 * V_63 , T_7 * V_54 , T_9 * V_64 ,
const T_10 * V_65 )
{
int V_5 ;
char V_66 ;
if ( V_64 -> type == V_67 || V_64 -> type == V_68 )
V_66 = 1 ;
else
V_66 = 0 ;
if ( ! F_13 ( V_63 -> V_32 , 1 ) )
goto V_20;
if ( ! F_37 ( & V_63 -> V_69 -> V_70 ,
F_38 ( V_54 ) ) )
goto V_20;
F_39 ( V_63 -> V_69 -> V_71 ) ;
if ( ! ( V_63 -> V_69 -> V_71 =
F_40 ( F_41 ( V_54 ) ) ) )
goto V_20;
F_31 ( & V_64 -> V_58 , 1 , V_72 ) ;
V_63 -> V_64 = V_64 ;
if ( V_66 ) V_63 -> V_49 -> V_50 = F_11 ( V_73 ) ;
else
V_63 -> V_49 -> V_50 = F_11 ( F_42 ( V_65 ) ) ;
if ( V_63 -> V_49 -> V_51 != NULL )
F_43 ( V_63 -> V_49 -> V_51 ) ;
if ( ( V_63 -> V_49 -> V_51 = F_26 () ) == NULL )
goto V_20;
V_63 -> V_49 -> V_51 -> type = V_53 ;
if ( V_63 -> V_74 -> V_51 != NULL )
F_43 ( V_63 -> V_74 -> V_51 ) ;
V_5 = F_44 ( V_64 -> type ) ;
if ( V_5 == V_75 )
{
V_63 -> V_74 -> V_50 = F_11 ( V_76 ) ;
if ( ! ( V_63 -> V_74 -> V_51 = F_26 () ) )
goto V_20;
V_63 -> V_74 -> V_51 -> type = V_53 ;
}
else if ( V_5 == V_67 )
{
#if 1
V_63 -> V_74 -> V_50 = F_11 ( V_77 ) ;
#else
V_63 -> V_74 -> V_50 = F_11 ( V_78 ) ;
#endif
V_63 -> V_74 -> V_51 = NULL ;
}
else if ( V_5 == V_68 )
{
V_63 -> V_74 -> V_50 = F_11 ( V_79 ) ;
if ( ! ( V_63 -> V_74 -> V_51 = F_26 () ) )
goto V_20;
V_63 -> V_74 -> V_51 -> type = V_53 ;
}
else
return ( 0 ) ;
return ( 1 ) ;
V_20:
return ( 0 ) ;
}
T_5 * F_45 ( T_1 * V_1 , T_7 * V_54 , T_9 * V_64 ,
const T_10 * V_65 )
{
T_5 * V_80 ;
if ( ( V_80 = F_46 () ) == NULL ) goto V_20;
if ( ! F_36 ( V_80 , V_54 , V_64 , V_65 ) ) goto V_20;
if ( ! F_21 ( V_1 , V_80 ) ) goto V_20;
return ( V_80 ) ;
V_20:
return ( NULL ) ;
}
int F_47 ( T_1 * V_1 , const T_10 * V_81 )
{
if ( F_48 ( V_1 ) )
{
if( ! ( V_1 -> V_10 . V_24 -> V_81 -> V_51 = F_26 () ) )
{
F_5 ( V_82 , V_52 ) ;
return 0 ;
}
V_1 -> V_10 . V_24 -> V_81 -> V_51 -> type = V_53 ;
V_1 -> V_10 . V_24 -> V_81 -> V_50 = F_11 ( F_49 ( V_81 ) ) ;
return 1 ;
}
F_5 ( V_82 , V_48 ) ;
return 1 ;
}
int F_50 ( T_11 * V_63 , T_7 * V_54 )
{
if ( ! F_13 ( V_63 -> V_32 , 0 ) )
return 0 ;
if ( ! F_37 ( & V_63 -> V_69 -> V_70 ,
F_38 ( V_54 ) ) )
return 0 ;
F_39 ( V_63 -> V_69 -> V_71 ) ;
if ( ! ( V_63 -> V_69 -> V_71 =
F_40 ( F_41 ( V_54 ) ) ) )
return 0 ;
F_51 ( V_63 -> V_83 ) ;
if ( ! ( V_63 -> V_83 = F_52 ( V_54 -> V_84 -> V_85 -> V_86 ) ) )
return 0 ;
F_31 ( & V_54 -> V_58 , 1 , V_59 ) ;
V_63 -> V_56 = V_54 ;
return ( 1 ) ;
}
T_7 * F_53 ( T_1 * V_1 , T_5 * V_80 )
{
if ( F_54 ( V_1 ) )
return ( F_55 ( V_1 -> V_10 . V_11 -> V_56 ,
V_80 -> V_69 -> V_70 ,
V_80 -> V_69 -> V_71 ) ) ;
else
return ( NULL ) ;
}
int F_56 ( T_1 * V_1 , const T_12 * V_87 )
{
int V_22 ;
T_3 * V_88 ;
T_13 * V_89 ;
V_22 = F_2 ( V_1 -> type ) ;
switch ( V_22 )
{
case V_27 :
V_89 = V_1 -> V_10 . V_33 -> V_34 ;
break;
case V_26 :
V_89 = V_1 -> V_10 . V_36 -> V_34 ;
break;
default:
F_5 ( V_90 , V_48 ) ;
return ( 0 ) ;
}
V_22 = F_57 ( V_87 ) ;
if( V_22 == V_91 ) {
F_5 ( V_90 , V_92 ) ;
return ( 0 ) ;
}
V_88 = F_11 ( V_22 ) ;
V_89 -> V_87 = V_87 ;
return 1 ;
}
