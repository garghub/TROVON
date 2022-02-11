static void F_1 ( void * V_1 , void * V_2 ,
T_1 * V_3 , int V_4 , long V_5 , void * V_6 )
{
if( V_2 )
{
T_2 * V_7 = ( T_2 * ) V_2 ;
if( V_7 -> V_8 )
F_2 ( V_7 -> V_8 ) ;
if( V_7 -> V_9 )
F_3 ( ( void * ) V_7 -> V_9 ) ;
if( V_7 -> V_10 )
F_3 ( ( void * ) V_7 -> V_10 ) ;
F_3 ( V_7 ) ;
}
}
static int F_4 ( T_3 * V_11 , T_2 * * V_7 )
{
T_2 * V_12 ;
V_12 = F_5 ( sizeof( T_2 ) ) ;
if( ! V_12 )
{
F_6 ( V_13 , V_14 ) ;
return 0 ;
}
memset ( V_12 , 0 , sizeof( T_2 ) ) ;
V_12 -> V_8 = NULL ;
V_12 -> V_15 = NULL ;
V_12 -> V_16 = NULL ;
V_12 -> V_9 = NULL ;
V_12 -> V_17 = 0 ;
V_12 -> V_10 = NULL ;
V_12 -> V_18 = 0 ;
V_12 -> V_19 = L_1 ;
V_12 -> V_20 = L_2 ;
F_7 ( V_21 ) ;
if( ( * V_7 = ( T_2 * ) F_8 ( V_11 ,
V_22 ) ) == NULL )
{
F_9 ( V_11 , V_22 , V_12 ) ;
* V_7 = V_12 ;
V_12 = NULL ;
}
F_10 ( V_21 ) ;
if( V_12 )
F_3 ( V_12 ) ;
return 1 ;
}
static T_2 * F_11 ( T_3 * V_11 )
{
T_2 * V_7 ;
if( V_22 < 0 )
{
int V_23 = F_12 ( 0 , NULL , NULL , NULL ,
F_1 ) ;
if( V_23 == - 1 )
{
F_6 ( V_24 , V_25 ) ;
return NULL ;
}
F_7 ( V_21 ) ;
if( V_22 < 0 )
{
V_22 = V_23 ;
V_23 = - 1 ;
}
F_10 ( V_21 ) ;
}
V_7 = ( T_2 * ) F_8 ( V_11 , V_22 ) ;
if( ( V_7 == NULL ) && ! F_4 ( V_11 , & V_7 ) )
return NULL ;
return V_7 ;
}
static T_3 * F_13 ( void )
{
T_3 * V_26 = F_14 () ;
if( ! V_26 )
return NULL ;
if( ! F_15 ( V_26 , V_27 ) ||
! F_16 ( V_26 , V_28 ) ||
! F_17 ( V_26 , V_29 ) ||
! F_18 ( V_26 , V_30 ) ||
! F_19 ( V_26 , V_31 ) ||
! F_20 ( V_26 , V_32 ) ||
! F_21 ( V_26 , V_33 ) )
{
F_22 ( V_26 ) ;
return NULL ;
}
return V_26 ;
}
void F_23 ( void )
{
T_3 * V_34 = F_13 () ;
if( ! V_34 ) return;
F_24 ( V_34 ) ;
F_22 ( V_34 ) ;
F_25 () ;
}
static int V_29 ( T_3 * V_11 )
{
return 0 ;
}
static int V_30 ( T_3 * V_11 )
{
return 0 ;
}
static int V_31 ( T_3 * V_11 , int V_35 , long V_36 , void * V_37 , void (* F_26)() )
{
T_2 * V_7 = F_11 ( V_11 ) ;
int V_38 ;
if( ! V_7 )
{
F_6 ( V_39 , V_40 ) ;
return 0 ;
}
V_38 = ( ( V_7 -> V_8 == NULL ) ? 0 : 1 ) ;
if( V_38 )
{
F_6 ( V_39 ,
V_41 ) ;
return 0 ;
}
switch( V_35 )
{
case V_42 :
if( V_37 && ( strlen ( ( const char * ) V_37 ) < 1 ) )
V_37 = NULL ;
if( V_7 -> V_9 )
F_3 ( ( void * ) V_7 -> V_9 ) ;
if( V_37 )
V_7 -> V_9 = F_27 ( V_37 ) ;
else
V_7 -> V_9 = NULL ;
return ( V_7 -> V_9 ? 1 : 0 ) ;
case V_43 :
V_7 -> V_17 = ( ( V_36 == 0 ) ? 0 : 1 ) ;
return 1 ;
case V_44 :
if( V_37 && ( strlen ( ( const char * ) V_37 ) < 1 ) )
V_37 = NULL ;
if( V_7 -> V_10 )
F_3 ( ( void * ) V_7 -> V_10 ) ;
if( V_37 )
V_7 -> V_10 = F_27 ( V_37 ) ;
else
V_7 -> V_10 = NULL ;
return ( V_7 -> V_10 ? 1 : 0 ) ;
case V_45 :
if( ( V_36 < 0 ) || ( V_36 > 2 ) )
{
F_6 ( V_39 ,
V_46 ) ;
return 0 ;
}
V_7 -> V_18 = ( int ) V_36 ;
return 1 ;
case V_47 :
return F_28 ( V_11 , V_7 ) ;
default:
break;
}
F_6 ( V_39 , V_48 ) ;
return 0 ;
}
static int F_28 ( T_3 * V_11 , T_2 * V_7 )
{
T_3 V_49 ;
T_4 V_50 ;
if( ! V_7 -> V_9 || ( ( V_7 -> V_8 = F_29 ( NULL ,
V_7 -> V_9 , NULL , 0 ) ) == NULL ) )
{
F_6 ( V_51 ,
V_52 ) ;
return 0 ;
}
if( ! ( V_7 -> V_16 = ( V_53 ) F_30 (
V_7 -> V_8 , V_7 -> V_20 ) ) )
{
V_7 -> V_16 = NULL ;
F_2 ( V_7 -> V_8 ) ;
V_7 -> V_8 = NULL ;
F_6 ( V_51 ,
V_54 ) ;
return 0 ;
}
if( ! V_7 -> V_17 )
{
unsigned long V_55 = 0 ;
V_7 -> V_15 = ( V_56 ) F_30 (
V_7 -> V_8 , V_7 -> V_19 ) ;
if( V_7 -> V_15 )
V_55 = V_7 -> V_15 ( V_57 ) ;
if( V_55 < V_58 )
{
V_7 -> V_16 = NULL ;
V_7 -> V_15 = NULL ;
F_2 ( V_7 -> V_8 ) ;
V_7 -> V_8 = NULL ;
F_6 ( V_51 ,
V_59 ) ;
return 0 ;
}
}
memcpy ( & V_49 , V_11 , sizeof( T_3 ) ) ;
V_50 . V_60 = F_31 () ;
V_50 . V_61 = F_32 () ;
F_33 ( & V_50 . V_62 . V_63 ,
& V_50 . V_62 . V_64 ,
& V_50 . V_62 . V_65 ) ;
V_50 . V_66 . V_67 = F_34 () ;
V_50 . V_66 . V_68 = F_35 () ;
V_50 . V_66 . V_69 = F_36 () ;
V_50 . V_66 . V_70 = F_37 () ;
V_50 . V_66 . V_71 = F_38 () ;
F_39 ( V_11 ) ;
if( ! V_7 -> V_16 ( V_11 , V_7 -> V_10 , & V_50 ) )
{
V_7 -> V_16 = NULL ;
V_7 -> V_15 = NULL ;
F_2 ( V_7 -> V_8 ) ;
V_7 -> V_8 = NULL ;
F_6 ( V_51 , V_72 ) ;
memcpy ( V_11 , & V_49 , sizeof( T_3 ) ) ;
return 0 ;
}
if( V_7 -> V_18 > 0 )
{
if( ! F_24 ( V_11 ) )
{
if( V_7 -> V_18 > 1 )
{
F_6 ( V_51 ,
V_73 ) ;
return 0 ;
}
F_25 () ;
}
}
return 1 ;
}
