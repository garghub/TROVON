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
int V_9 = V_1 -> V_10 = V_8 ;
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
V_9 = ( T_1 * ) Malloc ( sizeof( T_1 ) ) ;
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
int F_17 ( T_1 * V_1 , int type , char * V_27 )
{
if ( V_1 == NULL ) return ( 0 ) ;
if ( V_1 -> V_1 . V_25 != NULL )
F_18 ( V_1 ) ;
V_1 -> type = F_19 ( type ) ;
V_1 -> V_28 = type ;
V_1 -> V_1 . V_25 = V_27 ;
return ( V_27 != NULL ) ;
}
int F_20 ( T_1 * V_1 , T_4 * V_27 )
{
int V_9 = F_21 ( V_1 , V_27 ) ;
if( V_9 ) F_22 ( & V_27 -> V_24 , 1 , V_29 ) ;
return V_9 ;
}
T_4 * F_23 ( T_1 * V_1 )
{
if( V_1 -> type != V_2 ) {
F_10 ( V_30 , V_31 ) ;
return NULL ;
}
F_22 ( & V_1 -> V_1 . V_3 -> V_24 , 1 , V_29 ) ;
return V_1 -> V_1 . V_3 ;
}
int F_24 ( T_1 * V_1 , T_3 * V_27 )
{
int V_9 = F_25 ( V_1 , V_27 ) ;
if( V_9 ) F_22 ( & V_27 -> V_24 , 1 , V_32 ) ;
return V_9 ;
}
T_3 * F_26 ( T_1 * V_1 )
{
if( V_1 -> type != V_5 ) {
F_10 ( V_33 , V_34 ) ;
return NULL ;
}
F_22 ( & V_1 -> V_1 . V_6 -> V_24 , 1 , V_32 ) ;
return V_1 -> V_1 . V_6 ;
}
int F_27 ( T_1 * V_1 , T_5 * V_27 )
{
int V_9 = F_28 ( V_1 , V_27 ) ;
if( V_9 ) F_22 ( & V_27 -> V_24 , 1 , V_35 ) ;
return V_9 ;
}
T_5 * F_29 ( T_1 * V_1 )
{
if( V_1 -> type != V_36 ) {
F_10 ( V_37 , V_38 ) ;
return NULL ;
}
F_22 ( & V_1 -> V_1 . V_39 -> V_24 , 1 , V_35 ) ;
return V_1 -> V_1 . V_39 ;
}
int F_19 ( int type )
{
switch ( type )
{
case V_2 :
case V_40 :
return ( V_2 ) ;
case V_5 :
case V_41 :
case V_42 :
case V_43 :
case V_44 :
return ( V_5 ) ;
case V_36 :
return ( V_36 ) ;
default:
return ( V_45 ) ;
}
}
void F_30 ( T_1 * V_46 )
{
int V_47 ;
if ( V_46 == NULL ) return;
V_47 = F_22 ( & V_46 -> V_24 , - 1 , V_48 ) ;
#ifdef F_31
F_31 ( L_1 , V_46 ) ;
#endif
if ( V_47 > 0 ) return;
#ifdef F_32
if ( V_47 < 0 )
{
fprintf ( V_49 , L_2 ) ;
abort () ;
}
#endif
F_18 ( V_46 ) ;
Free ( V_46 ) ;
}
static void F_18 ( T_1 * V_46 )
{
switch ( V_46 -> type )
{
#ifndef F_2
case V_2 :
case V_40 :
F_33 ( V_46 -> V_1 . V_3 ) ;
break;
#endif
#ifndef F_4
case V_5 :
case V_42 :
case V_43 :
case V_44 :
F_34 ( V_46 -> V_1 . V_6 ) ;
break;
#endif
#ifndef F_35
case V_36 :
F_36 ( V_46 -> V_1 . V_39 ) ;
break;
#endif
}
}
