int F_1 ( T_1 * V_1 )
{
#ifndef F_2
if ( V_1 -> type == V_2 )
return ( F_3 ( V_1 -> V_1 . V_3 -> V_4 ) ) ;
else
#endif
#ifndef F_4
if ( V_1 -> type == V_5 )
return ( F_3 ( V_1 -> V_1 . V_6 -> V_7 ) ) ;
#endif
return ( 0 ) ;
}
int F_5 ( T_1 * V_1 )
{
if ( V_1 == NULL )
return ( 0 ) ;
#ifndef F_2
if ( V_1 -> type == V_2 )
return ( F_6 ( V_1 -> V_1 . V_3 ) ) ;
else
#endif
#ifndef F_4
if ( V_1 -> type == V_5 )
return ( F_7 ( V_1 -> V_1 . V_6 ) ) ;
#endif
return ( 0 ) ;
}
int F_8 ( T_1 * V_1 , int V_8 )
{
#ifndef F_4
if ( V_1 -> type == V_5 )
{
int V_9 = V_1 -> V_10 ;
if ( V_8 >= 0 )
V_1 -> V_10 = V_8 ;
return ( V_9 ) ;
}
#endif
return ( 0 ) ;
}
int F_9 ( T_1 * V_11 , T_1 * V_12 )
{
if ( V_11 -> type != V_12 -> type )
{
F_10 ( V_13 , V_14 ) ;
goto V_15;
}
if ( F_11 ( V_12 ) )
{
F_10 ( V_13 , V_16 ) ;
goto V_15;
}
#ifndef F_4
if ( V_11 -> type == V_5 )
{
T_2 * V_17 ;
if ( ( V_17 = F_12 ( V_12 -> V_1 . V_6 -> V_7 ) ) == NULL ) goto V_15;
if ( V_11 -> V_1 . V_6 -> V_7 != NULL ) F_13 ( V_11 -> V_1 . V_6 -> V_7 ) ;
V_11 -> V_1 . V_6 -> V_7 = V_17 ;
if ( ( V_17 = F_12 ( V_12 -> V_1 . V_6 -> V_18 ) ) == NULL ) goto V_15;
if ( V_11 -> V_1 . V_6 -> V_18 != NULL ) F_13 ( V_11 -> V_1 . V_6 -> V_18 ) ;
V_11 -> V_1 . V_6 -> V_18 = V_17 ;
if ( ( V_17 = F_12 ( V_12 -> V_1 . V_6 -> V_19 ) ) == NULL ) goto V_15;
if ( V_11 -> V_1 . V_6 -> V_19 != NULL ) F_13 ( V_11 -> V_1 . V_6 -> V_19 ) ;
V_11 -> V_1 . V_6 -> V_19 = V_17 ;
}
#endif
return ( 1 ) ;
V_15:
return ( 0 ) ;
}
int F_11 ( T_1 * V_1 )
{
#ifndef F_4
if ( V_1 -> type == V_5 )
{
T_3 * V_6 ;
V_6 = V_1 -> V_1 . V_6 ;
if ( ( V_6 -> V_7 == NULL ) || ( V_6 -> V_18 == NULL ) || ( V_6 -> V_19 == NULL ) )
return ( 1 ) ;
}
#endif
return ( 0 ) ;
}
int F_14 ( T_1 * V_17 , T_1 * V_20 )
{
#ifndef F_4
if ( ( V_17 -> type == V_5 ) && ( V_20 -> type == V_5 ) )
{
if ( F_15 ( V_17 -> V_1 . V_6 -> V_7 , V_20 -> V_1 . V_6 -> V_7 ) ||
F_15 ( V_17 -> V_1 . V_6 -> V_18 , V_20 -> V_1 . V_6 -> V_18 ) ||
F_15 ( V_17 -> V_1 . V_6 -> V_19 , V_20 -> V_1 . V_6 -> V_19 ) )
return ( 0 ) ;
else
return ( 1 ) ;
}
#endif
return ( - 1 ) ;
}
T_1 * F_16 ( void )
{
T_1 * V_9 ;
V_9 = ( T_1 * ) F_17 ( sizeof( T_1 ) ) ;
if ( V_9 == NULL )
{
F_10 ( V_21 , V_22 ) ;
return ( NULL ) ;
}
V_9 -> type = V_23 ;
V_9 -> V_24 = 1 ;
V_9 -> V_1 . V_25 = NULL ;
V_9 -> V_26 = NULL ;
V_9 -> V_10 = 1 ;
return ( V_9 ) ;
}
int F_18 ( T_1 * V_1 , int type , char * V_27 )
{
if ( V_1 == NULL ) return ( 0 ) ;
if ( V_1 -> V_1 . V_25 != NULL )
F_19 ( V_1 ) ;
V_1 -> type = F_20 ( type ) ;
V_1 -> V_28 = type ;
V_1 -> V_1 . V_25 = V_27 ;
return ( V_27 != NULL ) ;
}
int F_21 ( T_1 * V_1 , T_4 * V_27 )
{
int V_9 = F_22 ( V_1 , V_27 ) ;
if( V_9 )
F_23 ( V_27 ) ;
return V_9 ;
}
T_4 * F_24 ( T_1 * V_1 )
{
if( V_1 -> type != V_2 ) {
F_10 ( V_29 , V_30 ) ;
return NULL ;
}
F_23 ( V_1 -> V_1 . V_3 ) ;
return V_1 -> V_1 . V_3 ;
}
int F_25 ( T_1 * V_1 , T_3 * V_27 )
{
int V_9 = F_26 ( V_1 , V_27 ) ;
if( V_9 )
F_27 ( V_27 ) ;
return V_9 ;
}
T_3 * F_28 ( T_1 * V_1 )
{
if( V_1 -> type != V_5 ) {
F_10 ( V_31 , V_32 ) ;
return NULL ;
}
F_27 ( V_1 -> V_1 . V_6 ) ;
return V_1 -> V_1 . V_6 ;
}
int F_29 ( T_1 * V_1 , T_5 * V_27 )
{
int V_9 = F_30 ( V_1 , V_27 ) ;
if( V_9 )
F_31 ( V_27 ) ;
return V_9 ;
}
T_5 * F_32 ( T_1 * V_1 )
{
if( V_1 -> type != V_33 ) {
F_10 ( V_34 , V_35 ) ;
return NULL ;
}
F_31 ( V_1 -> V_1 . V_36 ) ;
return V_1 -> V_1 . V_36 ;
}
int F_20 ( int type )
{
switch ( type )
{
case V_2 :
case V_37 :
return ( V_2 ) ;
case V_5 :
case V_38 :
case V_39 :
case V_40 :
case V_41 :
return ( V_5 ) ;
case V_33 :
return ( V_33 ) ;
default:
return ( V_42 ) ;
}
}
void F_33 ( T_1 * V_43 )
{
int V_44 ;
if ( V_43 == NULL ) return;
V_44 = F_34 ( & V_43 -> V_24 , - 1 , V_45 ) ;
#ifdef F_35
F_35 ( L_1 , V_43 ) ;
#endif
if ( V_44 > 0 ) return;
#ifdef F_36
if ( V_44 < 0 )
{
fprintf ( V_46 , L_2 ) ;
abort () ;
}
#endif
F_19 ( V_43 ) ;
F_37 ( V_43 ) ;
}
static void F_19 ( T_1 * V_43 )
{
switch ( V_43 -> type )
{
#ifndef F_2
case V_2 :
case V_37 :
F_38 ( V_43 -> V_1 . V_3 ) ;
break;
#endif
#ifndef F_4
case V_5 :
case V_39 :
case V_40 :
case V_41 :
F_39 ( V_43 -> V_1 . V_6 ) ;
break;
#endif
#ifndef F_40
case V_33 :
F_41 ( V_43 -> V_1 . V_36 ) ;
break;
#endif
}
}
