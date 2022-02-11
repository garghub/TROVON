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
|| ! ( V_42 -> V_51 = F_26 () ) )
{
F_27 ( V_42 ) ;
F_5 ( V_47 , V_52 ) ;
return ( 0 ) ;
}
V_42 -> V_50 = F_11 ( V_5 ) ;
V_42 -> V_51 -> type = V_53 ;
if ( ! F_28 ( V_44 , V_42 ) )
{
F_27 ( V_42 ) ;
return 0 ;
}
}
if ( ! F_29 ( V_43 , V_40 ) )
return 0 ;
return ( 1 ) ;
}
int F_30 ( T_1 * V_1 , T_7 * V_54 )
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
* V_55 = F_31 () ;
if ( * V_55 == NULL )
{
F_5 ( V_57 , V_52 ) ;
return 0 ;
}
F_32 ( & V_54 -> V_58 , 1 , V_59 ) ;
if ( ! F_33 ( * V_55 , V_54 ) )
{
F_34 ( V_54 ) ;
return 0 ;
}
return ( 1 ) ;
}
int F_35 ( T_1 * V_1 , T_8 * V_60 )
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
* V_55 = F_36 () ;
if ( * V_55 == NULL )
{
F_5 ( V_61 , V_52 ) ;
return 0 ;
}
F_32 ( & V_60 -> V_58 , 1 , V_62 ) ;
if ( ! F_37 ( * V_55 , V_60 ) )
{
F_38 ( V_60 ) ;
return 0 ;
}
return ( 1 ) ;
}
int F_39 ( T_5 * V_63 , T_7 * V_54 , T_9 * V_64 ,
const T_10 * V_65 )
{
int V_6 ;
if ( ! F_13 ( V_63 -> V_32 , 1 ) )
goto V_20;
if ( ! F_40 ( & V_63 -> V_66 -> V_67 ,
F_41 ( V_54 ) ) )
goto V_20;
F_42 ( V_63 -> V_66 -> V_68 ) ;
if ( ! ( V_63 -> V_66 -> V_68 =
F_43 ( F_44 ( V_54 ) ) ) )
goto V_20;
F_32 ( & V_64 -> V_58 , 1 , V_69 ) ;
V_63 -> V_64 = V_64 ;
F_45 ( V_63 -> V_49 , F_11 ( F_46 ( V_65 ) ) ,
V_53 , NULL ) ;
if ( V_64 -> V_70 && V_64 -> V_70 -> V_71 )
{
V_6 = V_64 -> V_70 -> V_71 ( V_64 , V_72 ,
0 , V_63 ) ;
if ( V_6 > 0 )
return 1 ;
if ( V_6 != - 2 )
{
F_5 ( V_73 ,
V_74 ) ;
return 0 ;
}
}
F_5 ( V_73 ,
V_75 ) ;
V_20:
return 0 ;
}
T_5 * F_47 ( T_1 * V_1 , T_7 * V_54 , T_9 * V_64 ,
const T_10 * V_65 )
{
T_5 * V_76 = NULL ;
if ( V_65 == NULL )
{
int V_77 ;
if ( F_48 ( V_64 , & V_77 ) <= 0 )
goto V_20;
V_65 = F_49 ( V_77 ) ;
if ( V_65 == NULL )
{
F_5 ( V_78 ,
V_79 ) ;
goto V_20;
}
}
if ( ( V_76 = F_50 () ) == NULL ) goto V_20;
if ( ! F_39 ( V_76 , V_54 , V_64 , V_65 ) ) goto V_20;
if ( ! F_21 ( V_1 , V_76 ) ) goto V_20;
return ( V_76 ) ;
V_20:
if ( V_76 )
F_51 ( V_76 ) ;
return ( NULL ) ;
}
int F_52 ( T_1 * V_1 , const T_10 * V_80 )
{
if ( F_53 ( V_1 ) )
{
if( ! ( V_1 -> V_10 . V_24 -> V_80 -> V_51 = F_26 () ) )
{
F_5 ( V_81 , V_52 ) ;
return 0 ;
}
V_1 -> V_10 . V_24 -> V_80 -> V_51 -> type = V_53 ;
V_1 -> V_10 . V_24 -> V_80 -> V_50 = F_11 ( F_54 ( V_80 ) ) ;
return 1 ;
}
F_5 ( V_81 , V_48 ) ;
return 1 ;
}
void F_55 ( T_11 * V_82 , T_6 * * V_83 )
{
if ( V_83 )
* V_83 = V_82 -> V_84 ;
}
T_11 * F_56 ( T_1 * V_1 , T_7 * V_54 )
{
T_11 * V_82 ;
if ( ( V_82 = F_57 () ) == NULL ) goto V_20;
if ( ! F_58 ( V_82 , V_54 ) ) goto V_20;
if ( ! F_59 ( V_1 , V_82 ) ) goto V_20;
return V_82 ;
V_20:
if ( V_82 )
F_60 ( V_82 ) ;
return NULL ;
}
int F_59 ( T_1 * V_1 , T_11 * V_82 )
{
int V_22 ;
F_22 ( T_11 ) * V_55 ;
V_22 = F_2 ( V_1 -> type ) ;
switch ( V_22 )
{
case V_27 :
V_55 = V_1 -> V_10 . V_33 -> V_85 ;
break;
case V_26 :
V_55 = V_1 -> V_10 . V_36 -> V_85 ;
break;
default:
F_5 ( V_86 , V_48 ) ;
return ( 0 ) ;
}
if ( ! F_61 ( V_55 , V_82 ) )
return 0 ;
return ( 1 ) ;
}
int F_58 ( T_11 * V_63 , T_7 * V_54 )
{
int V_6 ;
T_9 * V_64 = NULL ;
if ( ! F_13 ( V_63 -> V_32 , 0 ) )
return 0 ;
if ( ! F_40 ( & V_63 -> V_66 -> V_67 ,
F_41 ( V_54 ) ) )
return 0 ;
F_42 ( V_63 -> V_66 -> V_68 ) ;
if ( ! ( V_63 -> V_66 -> V_68 =
F_43 ( F_44 ( V_54 ) ) ) )
return 0 ;
V_64 = F_62 ( V_54 ) ;
if ( ! V_64 || ! V_64 -> V_70 || ! V_64 -> V_70 -> V_71 )
{
F_5 ( V_87 ,
V_88 ) ;
goto V_20;
}
V_6 = V_64 -> V_70 -> V_71 ( V_64 , V_89 ,
0 , V_63 ) ;
if ( V_6 == - 2 )
{
F_5 ( V_87 ,
V_88 ) ;
goto V_20;
}
if ( V_6 <= 0 )
{
F_5 ( V_87 ,
V_90 ) ;
goto V_20;
}
F_63 ( V_64 ) ;
F_32 ( & V_54 -> V_58 , 1 , V_59 ) ;
V_63 -> V_56 = V_54 ;
return 1 ;
V_20:
if ( V_64 )
F_63 ( V_64 ) ;
return 0 ;
}
T_7 * F_64 ( T_1 * V_1 , T_5 * V_76 )
{
if ( F_65 ( V_1 ) )
return ( F_66 ( V_1 -> V_10 . V_11 -> V_56 ,
V_76 -> V_66 -> V_67 ,
V_76 -> V_66 -> V_68 ) ) ;
else
return ( NULL ) ;
}
int F_67 ( T_1 * V_1 , const T_12 * V_91 )
{
int V_22 ;
T_13 * V_92 ;
V_22 = F_2 ( V_1 -> type ) ;
switch ( V_22 )
{
case V_27 :
V_92 = V_1 -> V_10 . V_33 -> V_34 ;
break;
case V_26 :
V_92 = V_1 -> V_10 . V_36 -> V_34 ;
break;
default:
F_5 ( V_93 , V_48 ) ;
return ( 0 ) ;
}
V_22 = F_68 ( V_91 ) ;
if( V_22 == V_94 ) {
F_5 ( V_93 , V_95 ) ;
return ( 0 ) ;
}
V_92 -> V_91 = V_91 ;
return 1 ;
}
int F_69 ( unsigned char * * * V_96 , T_1 * V_1 )
{
T_2 * V_13 = NULL ;
switch ( F_2 ( V_1 -> type ) )
{
case V_25 :
V_13 = V_1 -> V_10 . V_14 ;
break;
case V_27 :
V_13 = V_1 -> V_10 . V_33 -> V_34 -> V_34 ;
if ( V_13 == NULL )
{
V_13 = F_15 () ;
V_1 -> V_10 . V_33 -> V_34 -> V_34 = V_13 ;
}
break;
case V_26 :
V_13 = V_1 -> V_10 . V_36 -> V_34 -> V_34 ;
if ( V_13 == NULL )
{
V_13 = F_15 () ;
V_1 -> V_10 . V_36 -> V_34 -> V_34 = V_13 ;
}
break;
case V_8 :
V_13 = V_1 -> V_10 . V_11 -> V_12 -> V_10 . V_14 ;
break;
default:
V_13 = NULL ;
break;
}
if ( V_13 == NULL )
return 0 ;
V_13 -> V_97 |= V_98 ;
* V_96 = & V_13 -> V_14 ;
return 1 ;
}
