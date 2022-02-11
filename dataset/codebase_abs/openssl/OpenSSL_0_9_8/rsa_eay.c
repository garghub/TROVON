const T_1 * F_1 ( void )
{
return ( & V_1 ) ;
}
static int F_2 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 * V_7 , * V_8 ;
int V_9 , V_10 , V_11 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
if ( ( V_15 = F_3 () ) == NULL ) goto V_16;
F_4 ( V_15 ) ;
V_7 = F_5 ( V_15 ) ;
V_8 = F_5 ( V_15 ) ;
V_12 = F_6 ( V_5 -> V_17 ) ;
V_14 = F_7 ( V_12 ) ;
if ( ! V_7 || ! V_8 || ! V_14 )
{
F_8 ( V_18 , V_19 ) ;
goto V_16;
}
switch ( V_6 )
{
case V_20 :
V_9 = F_9 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
#ifndef F_10
case V_21 :
V_9 = F_11 ( V_14 , V_12 , V_3 , V_2 , NULL , 0 ) ;
break;
#endif
case V_22 :
V_9 = F_12 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_23 :
V_9 = F_13 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
default:
F_8 ( V_18 , V_24 ) ;
goto V_16;
}
if ( V_9 <= 0 ) goto V_16;
if ( F_14 ( V_14 , V_12 , V_7 ) == NULL ) goto V_16;
if ( F_15 ( V_7 , V_5 -> V_17 ) >= 0 )
{
F_8 ( V_18 , V_25 ) ;
goto V_16;
}
F_16 (rsa, ctx, n, rsa->flags & RSA_FLAG_CACHE_PUBLIC, goto err) ;
if ( ! V_5 -> V_26 -> V_27 ( V_8 , V_7 , V_5 -> V_28 , V_5 -> V_17 , V_15 ,
V_5 -> V_29 ) ) goto V_16;
V_10 = F_6 ( V_8 ) ;
V_9 = F_17 ( V_8 , & ( V_4 [ V_12 - V_10 ] ) ) ;
for ( V_11 = 0 ; V_11 < ( V_12 - V_9 ) ; V_11 ++ )
V_4 [ V_11 ] = 0 ;
V_13 = V_12 ;
V_16:
if ( V_15 != NULL )
{
F_18 ( V_15 ) ;
F_19 ( V_15 ) ;
}
if ( V_14 != NULL )
{
F_20 ( V_14 , V_12 ) ;
F_21 ( V_14 ) ;
}
return ( V_13 ) ;
}
static T_5 * F_22 ( T_2 * V_5 , T_3 * * V_13 , int * V_30 , T_4 * V_15 )
{
T_5 * V_8 ;
if ( V_5 -> V_31 == NULL )
{
if ( V_5 -> V_31 == NULL )
{
F_23 ( V_32 ) ;
if ( V_5 -> V_31 == NULL )
V_5 -> V_31 = F_24 ( V_5 , V_15 ) ;
F_25 ( V_32 ) ;
}
}
V_8 = V_5 -> V_31 ;
if ( V_8 == NULL )
return NULL ;
if ( F_26 ( V_8 ) != F_27 () )
{
* V_30 = 0 ;
if ( V_5 -> V_33 == NULL )
{
F_23 ( V_32 ) ;
if ( V_5 -> V_33 == NULL )
V_5 -> V_33 = F_24 ( V_5 , V_15 ) ;
F_25 ( V_32 ) ;
}
V_8 = V_5 -> V_33 ;
}
else
* V_30 = 1 ;
return V_8 ;
}
static int F_28 ( T_5 * V_34 , int V_30 , T_3 * V_7 ,
T_3 * V_13 , T_4 * V_15 )
{
if ( V_30 )
return F_29 ( V_7 , NULL , V_34 , V_15 ) ;
else
{
int V_8 ;
F_23 ( V_35 ) ;
V_8 = F_29 ( V_7 , V_13 , V_34 , V_15 ) ;
F_25 ( V_35 ) ;
return V_8 ;
}
}
static int F_30 ( T_5 * V_34 , int V_30 , T_3 * V_7 ,
T_3 * V_13 , T_4 * V_15 )
{
if ( V_30 )
return F_31 ( V_7 , NULL , V_34 , V_15 ) ;
else
{
int V_8 ;
F_32 ( V_35 ) ;
V_8 = F_31 ( V_7 , V_13 , V_34 , V_15 ) ;
F_33 ( V_35 ) ;
return V_8 ;
}
}
static int F_34 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 * V_7 , * V_8 , * V_36 , * V_37 ;
int V_9 , V_10 , V_11 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
int V_38 = 0 ;
T_5 * V_31 = NULL ;
if ( ( V_15 = F_3 () ) == NULL ) goto V_16;
F_4 ( V_15 ) ;
V_7 = F_5 ( V_15 ) ;
V_36 = F_5 ( V_15 ) ;
V_8 = F_5 ( V_15 ) ;
V_12 = F_6 ( V_5 -> V_17 ) ;
V_14 = F_7 ( V_12 ) ;
if( ! V_7 || ! V_8 || ! V_14 )
{
F_8 ( V_39 , V_19 ) ;
goto V_16;
}
switch ( V_6 )
{
case V_20 :
V_9 = F_35 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_40 :
V_9 = F_36 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_23 :
V_9 = F_13 ( V_14 , V_12 , V_3 , V_2 ) ;
break;
case V_22 :
default:
F_8 ( V_39 , V_24 ) ;
goto V_16;
}
if ( V_9 <= 0 ) goto V_16;
if ( F_14 ( V_14 , V_12 , V_7 ) == NULL ) goto V_16;
if ( F_15 ( V_7 , V_5 -> V_17 ) >= 0 )
{
F_8 ( V_39 , V_25 ) ;
goto V_16;
}
if ( ! ( V_5 -> V_41 & V_42 ) )
{
V_31 = F_22 ( V_5 , & V_36 , & V_38 , V_15 ) ;
if ( V_31 == NULL )
{
F_8 ( V_39 , V_43 ) ;
goto V_16;
}
}
if ( V_31 != NULL )
if ( ! F_28 ( V_31 , V_38 , V_7 , V_36 , V_15 ) )
goto V_16;
if ( ( V_5 -> V_41 & V_44 ) ||
( ( V_5 -> V_45 != NULL ) &&
( V_5 -> V_46 != NULL ) &&
( V_5 -> V_47 != NULL ) &&
( V_5 -> V_48 != NULL ) &&
( V_5 -> V_49 != NULL ) ) )
{
if ( ! V_5 -> V_26 -> V_50 ( V_8 , V_7 , V_5 , V_15 ) ) goto V_16;
}
else
{
T_3 V_51 ;
T_3 * V_52 = NULL ;
if ( ! ( V_5 -> V_41 & V_53 ) )
{
F_37 ( & V_51 ) ;
V_52 = & V_51 ;
F_38 ( V_52 , V_5 -> V_52 , V_54 ) ;
}
else
V_52 = V_5 -> V_52 ;
F_16 (rsa, ctx, n, rsa->flags & RSA_FLAG_CACHE_PUBLIC, goto err) ;
if ( ! V_5 -> V_26 -> V_27 ( V_8 , V_7 , V_52 , V_5 -> V_17 , V_15 ,
V_5 -> V_29 ) ) goto V_16;
}
if ( V_31 )
if ( ! F_30 ( V_31 , V_38 , V_8 , V_36 , V_15 ) )
goto V_16;
if ( V_6 == V_40 )
{
F_39 ( V_7 , V_5 -> V_17 , V_8 ) ;
if ( F_40 ( V_8 , V_7 ) )
V_37 = V_7 ;
else
V_37 = V_8 ;
}
else
V_37 = V_8 ;
V_10 = F_6 ( V_37 ) ;
V_9 = F_17 ( V_37 , & ( V_4 [ V_12 - V_10 ] ) ) ;
for ( V_11 = 0 ; V_11 < ( V_12 - V_9 ) ; V_11 ++ )
V_4 [ V_11 ] = 0 ;
V_13 = V_12 ;
V_16:
if ( V_15 != NULL )
{
F_18 ( V_15 ) ;
F_19 ( V_15 ) ;
}
if ( V_14 != NULL )
{
F_20 ( V_14 , V_12 ) ;
F_21 ( V_14 ) ;
}
return ( V_13 ) ;
}
static int F_41 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 * V_7 , * V_8 , * V_36 ;
int V_10 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_45 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
int V_38 = 0 ;
T_5 * V_31 = NULL ;
if( ( V_15 = F_3 () ) == NULL ) goto V_16;
F_4 ( V_15 ) ;
V_7 = F_5 ( V_15 ) ;
V_36 = F_5 ( V_15 ) ;
V_8 = F_5 ( V_15 ) ;
V_12 = F_6 ( V_5 -> V_17 ) ;
V_14 = F_7 ( V_12 ) ;
if( ! V_7 || ! V_8 || ! V_14 )
{
F_8 ( V_55 , V_19 ) ;
goto V_16;
}
if ( V_2 > V_12 )
{
F_8 ( V_55 , V_56 ) ;
goto V_16;
}
if ( F_14 ( V_3 , ( int ) V_2 , V_7 ) == NULL ) goto V_16;
if ( F_15 ( V_7 , V_5 -> V_17 ) >= 0 )
{
F_8 ( V_55 , V_25 ) ;
goto V_16;
}
if ( ! ( V_5 -> V_41 & V_42 ) )
{
V_31 = F_22 ( V_5 , & V_36 , & V_38 , V_15 ) ;
if ( V_31 == NULL )
{
F_8 ( V_55 , V_43 ) ;
goto V_16;
}
}
if ( V_31 != NULL )
if ( ! F_28 ( V_31 , V_38 , V_7 , V_36 , V_15 ) )
goto V_16;
if ( ( V_5 -> V_41 & V_44 ) ||
( ( V_5 -> V_45 != NULL ) &&
( V_5 -> V_46 != NULL ) &&
( V_5 -> V_47 != NULL ) &&
( V_5 -> V_48 != NULL ) &&
( V_5 -> V_49 != NULL ) ) )
{
if ( ! V_5 -> V_26 -> V_50 ( V_8 , V_7 , V_5 , V_15 ) ) goto V_16;
}
else
{
T_3 V_51 ;
T_3 * V_52 = NULL ;
if ( ! ( V_5 -> V_41 & V_53 ) )
{
V_52 = & V_51 ;
F_38 ( V_52 , V_5 -> V_52 , V_54 ) ;
}
else
V_52 = V_5 -> V_52 ;
F_16 (rsa, ctx, n, rsa->flags & RSA_FLAG_CACHE_PUBLIC, goto err) ;
if ( ! V_5 -> V_26 -> V_27 ( V_8 , V_7 , V_52 , V_5 -> V_17 , V_15 ,
V_5 -> V_29 ) )
goto V_16;
}
if ( V_31 )
if ( ! F_30 ( V_31 , V_38 , V_8 , V_36 , V_15 ) )
goto V_16;
V_45 = V_14 ;
V_10 = F_17 ( V_8 , V_45 ) ;
switch ( V_6 )
{
case V_20 :
V_13 = F_42 ( V_4 , V_12 , V_14 , V_10 , V_12 ) ;
break;
#ifndef F_10
case V_21 :
V_13 = F_43 ( V_4 , V_12 , V_14 , V_10 , V_12 , NULL , 0 ) ;
break;
#endif
case V_22 :
V_13 = F_44 ( V_4 , V_12 , V_14 , V_10 , V_12 ) ;
break;
case V_23 :
V_13 = F_45 ( V_4 , V_12 , V_14 , V_10 , V_12 ) ;
break;
default:
F_8 ( V_55 , V_24 ) ;
goto V_16;
}
if ( V_13 < 0 )
F_8 ( V_55 , V_57 ) ;
V_16:
if ( V_15 != NULL )
{
F_18 ( V_15 ) ;
F_19 ( V_15 ) ;
}
if ( V_14 != NULL )
{
F_20 ( V_14 , V_12 ) ;
F_21 ( V_14 ) ;
}
return ( V_13 ) ;
}
static int F_46 ( int V_2 , const unsigned char * V_3 ,
unsigned char * V_4 , T_2 * V_5 , int V_6 )
{
T_3 * V_7 , * V_8 ;
int V_9 , V_12 = 0 , V_13 = - 1 ;
unsigned char * V_45 ;
unsigned char * V_14 = NULL ;
T_4 * V_15 = NULL ;
if( ( V_15 = F_3 () ) == NULL ) goto V_16;
F_4 ( V_15 ) ;
V_7 = F_5 ( V_15 ) ;
V_8 = F_5 ( V_15 ) ;
V_12 = F_6 ( V_5 -> V_17 ) ;
V_14 = F_7 ( V_12 ) ;
if( ! V_7 || ! V_8 || ! V_14 )
{
F_8 ( V_58 , V_19 ) ;
goto V_16;
}
if ( V_2 > V_12 )
{
F_8 ( V_58 , V_56 ) ;
goto V_16;
}
if ( F_14 ( V_3 , V_2 , V_7 ) == NULL ) goto V_16;
if ( F_15 ( V_7 , V_5 -> V_17 ) >= 0 )
{
F_8 ( V_58 , V_25 ) ;
goto V_16;
}
F_16 (rsa, ctx, n, rsa->flags & RSA_FLAG_CACHE_PUBLIC, goto err) ;
if ( ! V_5 -> V_26 -> V_27 ( V_8 , V_7 , V_5 -> V_28 , V_5 -> V_17 , V_15 ,
V_5 -> V_29 ) ) goto V_16;
if ( ( V_6 == V_40 ) && ( ( V_8 -> V_52 [ 0 ] & 0xf ) != 12 ) )
F_39 ( V_8 , V_5 -> V_17 , V_8 ) ;
V_45 = V_14 ;
V_9 = F_17 ( V_8 , V_45 ) ;
switch ( V_6 )
{
case V_20 :
V_13 = F_47 ( V_4 , V_12 , V_14 , V_9 , V_12 ) ;
break;
case V_40 :
V_13 = F_48 ( V_4 , V_12 , V_14 , V_9 , V_12 ) ;
break;
case V_23 :
V_13 = F_45 ( V_4 , V_12 , V_14 , V_9 , V_12 ) ;
break;
default:
F_8 ( V_58 , V_24 ) ;
goto V_16;
}
if ( V_13 < 0 )
F_8 ( V_58 , V_57 ) ;
V_16:
if ( V_15 != NULL )
{
F_18 ( V_15 ) ;
F_19 ( V_15 ) ;
}
if ( V_14 != NULL )
{
F_20 ( V_14 , V_12 ) ;
F_21 ( V_14 ) ;
}
return ( V_13 ) ;
}
static int F_49 ( T_3 * V_59 , const T_3 * V_60 , T_2 * V_5 , T_4 * V_15 )
{
T_3 * V_61 , * V_62 , * V_63 ;
T_3 V_64 , V_65 ;
T_3 * V_47 , * V_48 ;
int V_8 = 0 ;
F_4 ( V_15 ) ;
V_61 = F_5 ( V_15 ) ;
V_62 = F_5 ( V_15 ) ;
V_63 = F_5 ( V_15 ) ;
F_16 (rsa, ctx, p, rsa->flags & RSA_FLAG_CACHE_PRIVATE, goto err) ;
F_16 (rsa, ctx, q, rsa->flags & RSA_FLAG_CACHE_PRIVATE, goto err) ;
F_16 (rsa, ctx, n, rsa->flags & RSA_FLAG_CACHE_PUBLIC, goto err) ;
if ( ! F_50 ( V_61 , V_60 , V_5 -> V_46 , V_15 ) ) goto V_16;
if ( ! ( V_5 -> V_41 & V_53 ) )
{
V_48 = & V_65 ;
F_38 ( V_48 , V_5 -> V_48 , V_54 ) ;
}
else
V_48 = V_5 -> V_48 ;
if ( ! V_5 -> V_26 -> V_27 ( V_62 , V_61 , V_48 , V_5 -> V_46 , V_15 ,
V_5 -> V_66 ) ) goto V_16;
if ( ! F_50 ( V_61 , V_60 , V_5 -> V_45 , V_15 ) ) goto V_16;
if ( ! ( V_5 -> V_41 & V_53 ) )
{
V_47 = & V_64 ;
F_38 ( V_47 , V_5 -> V_47 , V_54 ) ;
}
else
V_47 = V_5 -> V_47 ;
if ( ! V_5 -> V_26 -> V_27 ( V_59 , V_61 , V_47 , V_5 -> V_45 , V_15 ,
V_5 -> V_67 ) ) goto V_16;
if ( ! F_39 ( V_59 , V_59 , V_62 ) ) goto V_16;
if ( F_51 ( V_59 ) )
if ( ! F_52 ( V_59 , V_59 , V_5 -> V_45 ) ) goto V_16;
if ( ! F_53 ( V_61 , V_59 , V_5 -> V_49 , V_15 ) ) goto V_16;
if ( ! F_50 ( V_59 , V_61 , V_5 -> V_45 , V_15 ) ) goto V_16;
if ( F_51 ( V_59 ) )
if ( ! F_52 ( V_59 , V_59 , V_5 -> V_45 ) ) goto V_16;
if ( ! F_53 ( V_61 , V_59 , V_5 -> V_46 , V_15 ) ) goto V_16;
if ( ! F_52 ( V_59 , V_61 , V_62 ) ) goto V_16;
if ( V_5 -> V_28 && V_5 -> V_17 )
{
if ( ! V_5 -> V_26 -> V_27 ( V_63 , V_59 , V_5 -> V_28 , V_5 -> V_17 , V_15 , V_5 -> V_29 ) ) goto V_16;
if ( ! F_39 ( V_63 , V_63 , V_60 ) ) goto V_16;
if ( ! F_50 ( V_63 , V_63 , V_5 -> V_17 , V_15 ) ) goto V_16;
if ( F_51 ( V_63 ) )
if ( ! F_52 ( V_63 , V_63 , V_5 -> V_17 ) ) goto V_16;
if ( ! F_54 ( V_63 ) )
{
T_3 V_51 ;
T_3 * V_52 = NULL ;
if ( ! ( V_5 -> V_41 & V_53 ) )
{
V_52 = & V_51 ;
F_38 ( V_52 , V_5 -> V_52 , V_54 ) ;
}
else
V_52 = V_5 -> V_52 ;
if ( ! V_5 -> V_26 -> V_27 ( V_59 , V_60 , V_52 , V_5 -> V_17 , V_15 ,
V_5 -> V_29 ) ) goto V_16;
}
}
V_8 = 1 ;
V_16:
F_18 ( V_15 ) ;
return ( V_8 ) ;
}
static int F_55 ( T_2 * V_5 )
{
V_5 -> V_41 |= V_68 | V_69 ;
return ( 1 ) ;
}
static int F_56 ( T_2 * V_5 )
{
if ( V_5 -> V_29 != NULL )
F_57 ( V_5 -> V_29 ) ;
if ( V_5 -> V_67 != NULL )
F_57 ( V_5 -> V_67 ) ;
if ( V_5 -> V_66 != NULL )
F_57 ( V_5 -> V_66 ) ;
return ( 1 ) ;
}
