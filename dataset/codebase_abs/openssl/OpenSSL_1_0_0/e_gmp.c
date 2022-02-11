static int F_1 ( T_1 * V_1 )
{
#ifndef F_2
const T_2 * V_2 ;
#endif
if( ! F_3 ( V_1 , V_3 ) ||
! F_4 ( V_1 , V_4 ) ||
#ifndef F_2
! F_5 ( V_1 , & V_5 ) ||
#endif
! F_6 ( V_1 , V_6 ) ||
! F_7 ( V_1 , V_7 ) ||
! F_8 ( V_1 , V_8 ) ||
! F_9 ( V_1 , V_9 ) ||
! F_10 ( V_1 , V_10 ) )
return 0 ;
#ifndef F_2
V_2 = F_11 () ;
V_5 . V_11 = V_2 -> V_11 ;
V_5 . V_12 = V_2 -> V_12 ;
V_5 . V_13 = V_2 -> V_13 ;
V_5 . V_14 = V_2 -> V_14 ;
V_5 . V_15 = V_2 -> V_15 ;
#endif
F_12 () ;
return 1 ;
}
static T_1 * F_13 ( void )
{
T_1 * V_16 = F_14 () ;
if( ! V_16 )
return NULL ;
if( ! F_1 ( V_16 ) )
{
F_15 ( V_16 ) ;
return NULL ;
}
return V_16 ;
}
void F_16 ( void )
{
T_1 * V_17 = F_13 () ;
if( ! V_17 ) return;
F_17 ( V_17 ) ;
F_15 ( V_17 ) ;
F_18 () ;
}
static int V_6 ( T_1 * V_1 )
{
F_19 () ;
return 1 ;
}
static int V_7 ( T_1 * V_1 )
{
#ifndef F_2
if ( V_18 == - 1 )
V_18 = F_20 ( 0 ,
L_1 ,
NULL , NULL , NULL ) ;
#endif
if ( V_18 == - 1 )
return 0 ;
return 1 ;
}
static int V_8 ( T_1 * V_1 )
{
return 1 ;
}
static int V_9 ( T_1 * V_1 , int V_19 , long V_20 , void * V_21 , void (* F_21)( void ) )
{
int V_22 = 1 ;
switch( V_19 )
{
#if 0
case E_GMP_CMD_SO_PATH:
#endif
default:
F_22 ( V_23 ,
V_24 ) ;
V_22 = 0 ;
break;
}
return V_22 ;
}
static int F_23 ( const T_3 * V_25 , T_4 V_26 )
{
F_24 ( V_25 ) ;
if( ( ( sizeof( V_25 -> V_27 [ 0 ] ) * 8 ) == V_28 ) &&
( V_29 == V_28 ) )
{
if( ! F_25 ( V_26 , V_25 -> V_30 ) )
return 0 ;
memcpy ( & V_26 -> V_31 [ 0 ] , & V_25 -> V_27 [ 0 ] , V_25 -> V_30 * sizeof( V_25 -> V_27 [ 0 ] ) ) ;
V_26 -> V_32 = V_25 -> V_30 ;
if( V_25 -> V_33 )
V_26 -> V_32 = - V_26 -> V_32 ;
return 1 ;
}
else
{
int V_34 ;
char * V_35 = F_26 ( V_25 ) ;
if( ! V_35 ) return 0 ;
V_34 = ( F_27 ( V_26 , V_35 , 16 ) == 0 ? 1 : 0 ) ;
F_28 ( V_35 ) ;
return V_34 ;
}
}
static int F_29 ( T_4 V_26 , T_3 * V_25 )
{
if( ( ( sizeof( V_25 -> V_27 [ 0 ] ) * 8 ) == V_28 ) &&
( V_29 == V_28 ) )
{
int V_36 = ( V_26 -> V_32 >= 0 ) ? V_26 -> V_32 : - V_26 -> V_32 ;
F_30 ( V_25 ) ;
if( F_31 ( V_25 , V_36 ) == NULL )
return 0 ;
V_25 -> V_30 = V_36 ;
memcpy ( & V_25 -> V_27 [ 0 ] , & V_26 -> V_31 [ 0 ] , V_36 * sizeof( V_25 -> V_27 [ 0 ] ) ) ;
F_32 ( V_25 ) ;
V_25 -> V_33 = V_26 -> V_32 >= 0 ? 0 : 1 ;
return 1 ;
}
else
{
int V_34 ;
char * V_35 = F_33 ( F_34 ( V_26 , 16 ) + 10 ) ;
if( ! V_35 ) return 0 ;
F_35 ( V_35 , 16 , V_26 ) ;
V_34 = F_36 ( & V_25 , V_35 ) ;
F_28 ( V_35 ) ;
return V_34 ;
}
}
static T_5 * F_37 ( T_6 * V_37 )
{
T_5 * V_38 = F_38 ( V_37 , V_18 ) ;
if( V_38 ) return V_38 ;
V_38 = F_33 ( sizeof( T_5 ) ) ;
if( ! V_38 ) return NULL ;
F_39 ( V_38 -> V_39 ) ;
F_39 ( V_38 -> V_27 ) ;
F_39 ( V_38 -> V_1 ) ;
F_39 ( V_38 -> V_21 ) ;
F_39 ( V_38 -> V_40 ) ;
F_39 ( V_38 -> V_41 ) ;
F_39 ( V_38 -> V_42 ) ;
F_39 ( V_38 -> V_43 ) ;
F_39 ( V_38 -> V_44 ) ;
F_39 ( V_38 -> V_45 ) ;
F_39 ( V_38 -> V_46 ) ;
F_39 ( V_38 -> V_47 ) ;
if( ! F_23 ( V_37 -> V_39 , V_38 -> V_39 ) || ! F_23 ( V_37 -> V_1 , V_38 -> V_1 ) )
goto V_48;
if( ! V_37 -> V_21 || ! V_37 -> V_40 || ! V_37 -> V_27 || ! V_37 -> V_41 || ! V_37 -> V_42 || ! V_37 -> V_43 )
{
V_38 -> V_49 = 1 ;
return V_38 ;
}
if( ! F_23 ( V_37 -> V_27 , V_38 -> V_27 ) || ! F_23 ( V_37 -> V_21 , V_38 -> V_21 ) ||
! F_23 ( V_37 -> V_40 , V_38 -> V_40 ) || ! F_23 ( V_37 -> V_41 , V_38 -> V_41 ) ||
! F_23 ( V_37 -> V_42 , V_38 -> V_42 ) || ! F_23 ( V_37 -> V_43 , V_38 -> V_43 ) )
goto V_48;
V_38 -> V_49 = 0 ;
F_40 ( V_37 , V_18 , V_38 ) ;
return V_38 ;
V_48:
F_41 ( V_38 -> V_39 ) ;
F_41 ( V_38 -> V_27 ) ;
F_41 ( V_38 -> V_1 ) ;
F_41 ( V_38 -> V_21 ) ;
F_41 ( V_38 -> V_40 ) ;
F_41 ( V_38 -> V_41 ) ;
F_41 ( V_38 -> V_42 ) ;
F_41 ( V_38 -> V_43 ) ;
F_41 ( V_38 -> V_44 ) ;
F_41 ( V_38 -> V_45 ) ;
F_41 ( V_38 -> V_46 ) ;
F_41 ( V_38 -> V_47 ) ;
F_28 ( V_38 ) ;
return NULL ;
}
static int F_42 ( T_6 * V_37 )
{
T_5 * V_38 = F_38 ( V_37 , V_18 ) ;
if( ! V_38 ) return 0 ;
F_41 ( V_38 -> V_39 ) ;
F_41 ( V_38 -> V_27 ) ;
F_41 ( V_38 -> V_1 ) ;
F_41 ( V_38 -> V_21 ) ;
F_41 ( V_38 -> V_40 ) ;
F_41 ( V_38 -> V_41 ) ;
F_41 ( V_38 -> V_42 ) ;
F_41 ( V_38 -> V_43 ) ;
F_41 ( V_38 -> V_44 ) ;
F_41 ( V_38 -> V_45 ) ;
F_41 ( V_38 -> V_46 ) ;
F_41 ( V_38 -> V_47 ) ;
F_28 ( V_38 ) ;
F_40 ( V_37 , V_18 , NULL ) ;
return 1 ;
}
static int F_43 ( T_3 * V_50 , const T_3 * V_51 , T_6 * V_37 , T_7 * V_52 )
{
T_5 * V_38 ;
int V_22 = 0 ;
V_38 = F_37 ( V_37 ) ;
if( ! V_38 )
{
F_22 ( V_53 ,
V_54 ) ;
return 0 ;
}
if( V_38 -> V_49 )
{
F_22 ( V_53 ,
V_55 ) ;
return 0 ;
}
if( ! F_23 ( V_51 , V_38 -> V_46 ) )
return 0 ;
F_44 ( V_38 -> V_45 , V_38 -> V_46 , V_38 -> V_40 ) ;
F_45 ( V_38 -> V_47 , V_38 -> V_45 , V_38 -> V_42 , V_38 -> V_40 ) ;
F_44 ( V_38 -> V_45 , V_38 -> V_46 , V_38 -> V_21 ) ;
F_45 ( V_38 -> V_44 , V_38 -> V_45 , V_38 -> V_41 , V_38 -> V_21 ) ;
F_46 ( V_38 -> V_44 , V_38 -> V_44 , V_38 -> V_47 ) ;
if( F_47 ( V_38 -> V_44 ) < 0 )
F_48 ( V_38 -> V_44 , V_38 -> V_44 , V_38 -> V_21 ) ;
F_49 ( V_38 -> V_45 , V_38 -> V_44 , V_38 -> V_43 ) ;
F_44 ( V_38 -> V_44 , V_38 -> V_45 , V_38 -> V_21 ) ;
if( F_47 ( V_38 -> V_44 ) < 0 )
F_48 ( V_38 -> V_44 , V_38 -> V_44 , V_38 -> V_21 ) ;
F_49 ( V_38 -> V_45 , V_38 -> V_44 , V_38 -> V_40 ) ;
F_48 ( V_38 -> V_44 , V_38 -> V_45 , V_38 -> V_47 ) ;
if( F_29 ( V_38 -> V_44 , V_50 ) )
V_22 = 1 ;
return 1 ;
}
static int F_50 ( T_1 * V_1 , const char * V_56 )
{
if( V_56 && ( strcmp ( V_56 , V_3 ) != 0 ) )
return 0 ;
if( ! F_1 ( V_1 ) )
return 0 ;
return 1 ;
}
T_8
int F_51 ( T_1 * V_1 , const char * V_56 , const T_9 * V_57 ) { return 0 ; }
