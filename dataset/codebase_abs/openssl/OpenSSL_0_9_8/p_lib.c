int F_1 ( T_1 * V_1 )
{
if ( 0 )
return 0 ;
#ifndef F_2
else if ( V_1 -> type == V_2 )
return ( F_3 ( V_1 -> V_1 . V_3 -> V_4 ) ) ;
#endif
#ifndef F_4
else if ( V_1 -> type == V_5 )
return ( F_3 ( V_1 -> V_1 . V_6 -> V_7 ) ) ;
#endif
#ifndef F_5
else if ( V_1 -> type == V_8 )
{
T_2 * V_9 = F_6 () ;
const T_3 * V_10 ;
int V_11 ;
if ( ! V_9 )
{
F_7 () ;
return 0 ;
}
V_10 = F_8 ( V_1 -> V_1 . V_12 ) ;
if ( ! F_9 ( V_10 , V_9 , NULL ) )
{
F_7 () ;
return 0 ;
}
V_11 = F_3 ( V_9 ) ;
F_10 ( V_9 ) ;
return V_11 ;
}
#endif
return ( 0 ) ;
}
int F_11 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return ( 0 ) ;
#ifndef F_2
if ( V_1 -> type == V_2 )
return ( F_12 ( V_1 -> V_1 . V_3 ) ) ;
else
#endif
#ifndef F_4
if ( V_1 -> type == V_5 )
return ( F_13 ( V_1 -> V_1 . V_6 ) ) ;
#endif
#ifndef F_14
if ( V_1 -> type == V_8 )
return ( F_15 ( V_1 -> V_1 . V_12 ) ) ;
#endif
return ( 0 ) ;
}
int F_16 ( T_1 * V_1 , int V_13 )
{
#ifndef F_4
if ( V_1 -> type == V_5 )
{
int V_11 = V_1 -> V_14 ;
if ( V_13 >= 0 )
V_1 -> V_14 = V_13 ;
return ( V_11 ) ;
}
#endif
#ifndef F_5
if ( V_1 -> type == V_8 )
{
int V_11 = V_1 -> V_14 ;
if ( V_13 >= 0 )
V_1 -> V_14 = V_13 ;
return ( V_11 ) ;
}
#endif
return ( 0 ) ;
}
int F_17 ( T_1 * V_15 , const T_1 * V_16 )
{
if ( V_15 -> type != V_16 -> type )
{
F_18 ( V_17 , V_18 ) ;
goto V_19;
}
if ( F_19 ( V_16 ) )
{
F_18 ( V_17 , V_20 ) ;
goto V_19;
}
#ifndef F_4
if ( V_15 -> type == V_5 )
{
T_2 * V_21 ;
if ( ( V_21 = F_20 ( V_16 -> V_1 . V_6 -> V_7 ) ) == NULL ) goto V_19;
if ( V_15 -> V_1 . V_6 -> V_7 != NULL ) F_10 ( V_15 -> V_1 . V_6 -> V_7 ) ;
V_15 -> V_1 . V_6 -> V_7 = V_21 ;
if ( ( V_21 = F_20 ( V_16 -> V_1 . V_6 -> V_22 ) ) == NULL ) goto V_19;
if ( V_15 -> V_1 . V_6 -> V_22 != NULL ) F_10 ( V_15 -> V_1 . V_6 -> V_22 ) ;
V_15 -> V_1 . V_6 -> V_22 = V_21 ;
if ( ( V_21 = F_20 ( V_16 -> V_1 . V_6 -> V_23 ) ) == NULL ) goto V_19;
if ( V_15 -> V_1 . V_6 -> V_23 != NULL ) F_10 ( V_15 -> V_1 . V_6 -> V_23 ) ;
V_15 -> V_1 . V_6 -> V_23 = V_21 ;
}
#endif
#ifndef F_5
if ( V_15 -> type == V_8 )
{
T_3 * V_10 = F_21 ( F_8 ( V_16 -> V_1 . V_12 ) ) ;
if ( V_10 == NULL )
goto V_19;
if ( F_22 ( V_15 -> V_1 . V_12 , V_10 ) == 0 )
goto V_19;
F_23 ( V_10 ) ;
}
#endif
return ( 1 ) ;
V_19:
return ( 0 ) ;
}
int F_19 ( const T_1 * V_1 )
{
#ifndef F_4
if ( V_1 -> type == V_5 )
{
T_4 * V_6 ;
V_6 = V_1 -> V_1 . V_6 ;
if ( ( V_6 -> V_7 == NULL ) || ( V_6 -> V_22 == NULL ) || ( V_6 -> V_23 == NULL ) )
return ( 1 ) ;
}
#endif
#ifndef F_5
if ( V_1 -> type == V_8 )
{
if ( F_8 ( V_1 -> V_1 . V_12 ) == NULL )
return ( 1 ) ;
}
#endif
return ( 0 ) ;
}
int F_24 ( const T_1 * V_21 , const T_1 * V_24 )
{
#ifndef F_4
if ( ( V_21 -> type == V_5 ) && ( V_24 -> type == V_5 ) )
{
if ( F_25 ( V_21 -> V_1 . V_6 -> V_7 , V_24 -> V_1 . V_6 -> V_7 ) ||
F_25 ( V_21 -> V_1 . V_6 -> V_22 , V_24 -> V_1 . V_6 -> V_22 ) ||
F_25 ( V_21 -> V_1 . V_6 -> V_23 , V_24 -> V_1 . V_6 -> V_23 ) )
return ( 0 ) ;
else
return ( 1 ) ;
}
#endif
#ifndef F_5
if ( V_21 -> type == V_8 && V_24 -> type == V_8 )
{
const T_3 * V_25 = F_8 ( V_21 -> V_1 . V_12 ) ,
* V_26 = F_8 ( V_24 -> V_1 . V_12 ) ;
if ( F_26 ( V_25 , V_26 , NULL ) )
return 0 ;
else
return 1 ;
}
#endif
return ( - 1 ) ;
}
int F_27 ( const T_1 * V_21 , const T_1 * V_24 )
{
if ( V_21 -> type != V_24 -> type )
return - 1 ;
if ( F_24 ( V_21 , V_24 ) == 0 )
return 0 ;
switch ( V_21 -> type )
{
#ifndef F_2
case V_2 :
if ( F_25 ( V_24 -> V_1 . V_3 -> V_4 , V_21 -> V_1 . V_3 -> V_4 ) != 0
|| F_25 ( V_24 -> V_1 . V_3 -> V_27 , V_21 -> V_1 . V_3 -> V_27 ) != 0 )
return 0 ;
break;
#endif
#ifndef F_4
case V_5 :
if ( F_25 ( V_24 -> V_1 . V_6 -> V_28 , V_21 -> V_1 . V_6 -> V_28 ) != 0 )
return 0 ;
break;
#endif
#ifndef F_5
case V_8 :
{
int V_29 ;
const T_3 * V_10 = F_8 ( V_24 -> V_1 . V_12 ) ;
const T_5 * V_30 = F_28 ( V_21 -> V_1 . V_12 ) ,
* V_31 = F_28 ( V_24 -> V_1 . V_12 ) ;
V_29 = F_29 ( V_10 , V_30 , V_31 , NULL ) ;
if ( V_29 != 0 )
{
if ( V_29 == 1 )
return 0 ;
else
return - 2 ;
}
}
break;
#endif
#ifndef F_30
case V_32 :
return - 2 ;
#endif
default:
return - 2 ;
}
return 1 ;
}
T_1 * F_31 ( void )
{
T_1 * V_11 ;
V_11 = ( T_1 * ) F_32 ( sizeof( T_1 ) ) ;
if ( V_11 == NULL )
{
F_18 ( V_33 , V_34 ) ;
return ( NULL ) ;
}
V_11 -> type = V_35 ;
V_11 -> V_36 = 1 ;
V_11 -> V_1 . V_37 = NULL ;
V_11 -> V_38 = NULL ;
V_11 -> V_14 = 1 ;
return ( V_11 ) ;
}
int F_33 ( T_1 * V_1 , int type , char * V_39 )
{
if ( V_1 == NULL ) return ( 0 ) ;
if ( V_1 -> V_1 . V_37 != NULL )
F_34 ( V_1 ) ;
V_1 -> type = F_35 ( type ) ;
V_1 -> V_40 = type ;
V_1 -> V_1 . V_37 = V_39 ;
return ( V_39 != NULL ) ;
}
int F_36 ( T_1 * V_1 , T_6 * V_39 )
{
int V_11 = F_37 ( V_1 , V_39 ) ;
if( V_11 )
F_38 ( V_39 ) ;
return V_11 ;
}
T_6 * F_39 ( T_1 * V_1 )
{
if( V_1 -> type != V_2 ) {
F_18 ( V_41 , V_42 ) ;
return NULL ;
}
F_38 ( V_1 -> V_1 . V_3 ) ;
return V_1 -> V_1 . V_3 ;
}
int F_40 ( T_1 * V_1 , T_4 * V_39 )
{
int V_11 = F_41 ( V_1 , V_39 ) ;
if( V_11 )
F_42 ( V_39 ) ;
return V_11 ;
}
T_4 * F_43 ( T_1 * V_1 )
{
if( V_1 -> type != V_5 ) {
F_18 ( V_43 , V_44 ) ;
return NULL ;
}
F_42 ( V_1 -> V_1 . V_6 ) ;
return V_1 -> V_1 . V_6 ;
}
int F_44 ( T_1 * V_1 , T_7 * V_39 )
{
int V_11 = F_45 ( V_1 , V_39 ) ;
if ( V_11 )
F_46 ( V_39 ) ;
return V_11 ;
}
T_7 * F_47 ( T_1 * V_1 )
{
if ( V_1 -> type != V_8 )
{
F_18 ( V_45 , V_46 ) ;
return NULL ;
}
F_46 ( V_1 -> V_1 . V_12 ) ;
return V_1 -> V_1 . V_12 ;
}
int F_48 ( T_1 * V_1 , T_8 * V_39 )
{
int V_11 = F_49 ( V_1 , V_39 ) ;
if( V_11 )
F_50 ( V_39 ) ;
return V_11 ;
}
T_8 * F_51 ( T_1 * V_1 )
{
if( V_1 -> type != V_32 ) {
F_18 ( V_47 , V_48 ) ;
return NULL ;
}
F_50 ( V_1 -> V_1 . V_49 ) ;
return V_1 -> V_1 . V_49 ;
}
int F_35 ( int type )
{
switch ( type )
{
case V_2 :
case V_50 :
return ( V_2 ) ;
case V_5 :
case V_51 :
case V_52 :
case V_53 :
case V_54 :
return ( V_5 ) ;
case V_32 :
return ( V_32 ) ;
case V_8 :
return ( V_8 ) ;
default:
return ( V_55 ) ;
}
}
void F_52 ( T_1 * V_56 )
{
int V_57 ;
if ( V_56 == NULL ) return;
V_57 = F_53 ( & V_56 -> V_36 , - 1 , V_58 ) ;
#ifdef F_54
F_54 ( L_1 , V_56 ) ;
#endif
if ( V_57 > 0 ) return;
#ifdef F_55
if ( V_57 < 0 )
{
fprintf ( V_59 , L_2 ) ;
abort () ;
}
#endif
F_34 ( V_56 ) ;
if ( V_56 -> V_38 )
F_56 ( V_56 -> V_38 , V_60 ) ;
F_57 ( V_56 ) ;
}
static void F_34 ( T_1 * V_56 )
{
switch ( V_56 -> type )
{
#ifndef F_2
case V_2 :
case V_50 :
F_58 ( V_56 -> V_1 . V_3 ) ;
break;
#endif
#ifndef F_4
case V_5 :
case V_52 :
case V_53 :
case V_54 :
F_59 ( V_56 -> V_1 . V_6 ) ;
break;
#endif
#ifndef F_5
case V_8 :
F_60 ( V_56 -> V_1 . V_12 ) ;
break;
#endif
#ifndef F_30
case V_32 :
F_61 ( V_56 -> V_1 . V_49 ) ;
break;
#endif
}
}
