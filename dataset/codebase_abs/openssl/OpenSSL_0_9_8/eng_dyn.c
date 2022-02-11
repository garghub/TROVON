static void F_1 ( void * V_1 ) { F_2 ( V_1 ) ; }
static void F_3 ( void * V_2 , void * V_3 ,
T_1 * V_4 , int V_5 , long V_6 , void * V_7 )
{
if( V_3 )
{
T_2 * V_8 = ( T_2 * ) V_3 ;
if( V_8 -> V_9 )
F_4 ( V_8 -> V_9 ) ;
if( V_8 -> V_10 )
F_2 ( ( void * ) V_8 -> V_10 ) ;
if( V_8 -> V_11 )
F_2 ( ( void * ) V_8 -> V_11 ) ;
if( V_8 -> V_12 )
F_5 ( V_8 -> V_12 , F_1 ) ;
F_2 ( V_8 ) ;
}
}
static int F_6 ( T_3 * V_13 , T_2 * * V_8 )
{
T_2 * V_14 ;
V_14 = F_7 ( sizeof( T_2 ) ) ;
if( ! V_14 )
{
F_8 ( V_15 , V_16 ) ;
return 0 ;
}
memset ( V_14 , 0 , sizeof( T_2 ) ) ;
V_14 -> V_9 = NULL ;
V_14 -> V_17 = NULL ;
V_14 -> V_18 = NULL ;
V_14 -> V_10 = NULL ;
V_14 -> V_19 = 0 ;
V_14 -> V_11 = NULL ;
V_14 -> V_20 = 0 ;
V_14 -> V_21 = L_1 ;
V_14 -> V_22 = L_2 ;
V_14 -> V_23 = 1 ;
V_14 -> V_12 = F_9 () ;
if( ! V_14 -> V_12 )
{
F_8 ( V_15 , V_16 ) ;
F_2 ( V_14 ) ;
return 0 ;
}
F_10 ( V_24 ) ;
if( ( * V_8 = ( T_2 * ) F_11 ( V_13 ,
V_25 ) ) == NULL )
{
F_12 ( V_13 , V_25 , V_14 ) ;
* V_8 = V_14 ;
V_14 = NULL ;
}
F_13 ( V_24 ) ;
if( V_14 )
F_2 ( V_14 ) ;
return 1 ;
}
static T_2 * F_14 ( T_3 * V_13 )
{
T_2 * V_8 ;
if( V_25 < 0 )
{
int V_26 = F_15 ( 0 , NULL , NULL , NULL ,
F_3 ) ;
if( V_26 == - 1 )
{
F_8 ( V_27 , V_28 ) ;
return NULL ;
}
F_10 ( V_24 ) ;
if( V_25 < 0 )
{
V_25 = V_26 ;
V_26 = - 1 ;
}
F_13 ( V_24 ) ;
}
V_8 = ( T_2 * ) F_11 ( V_13 , V_25 ) ;
if( ( V_8 == NULL ) && ! F_6 ( V_13 , & V_8 ) )
return NULL ;
return V_8 ;
}
static T_3 * F_16 ( void )
{
T_3 * V_29 = F_17 () ;
if( ! V_29 )
return NULL ;
if( ! F_18 ( V_29 , V_30 ) ||
! F_19 ( V_29 , V_31 ) ||
! F_20 ( V_29 , V_32 ) ||
! F_21 ( V_29 , V_33 ) ||
! F_22 ( V_29 , V_34 ) ||
! F_23 ( V_29 , V_35 ) ||
! F_24 ( V_29 , V_36 ) )
{
F_25 ( V_29 ) ;
return NULL ;
}
return V_29 ;
}
void F_26 ( void )
{
T_3 * V_37 = F_16 () ;
if( ! V_37 ) return;
F_27 ( V_37 ) ;
F_25 ( V_37 ) ;
F_28 () ;
}
static int V_32 ( T_3 * V_13 )
{
return 0 ;
}
static int V_33 ( T_3 * V_13 )
{
return 0 ;
}
static int V_34 ( T_3 * V_13 , int V_38 , long V_39 , void * V_40 , void (* F_29)( void ) )
{
T_2 * V_8 = F_14 ( V_13 ) ;
int V_41 ;
if( ! V_8 )
{
F_8 ( V_42 , V_43 ) ;
return 0 ;
}
V_41 = ( ( V_8 -> V_9 == NULL ) ? 0 : 1 ) ;
if( V_41 )
{
F_8 ( V_42 ,
V_44 ) ;
return 0 ;
}
switch( V_38 )
{
case V_45 :
if( V_40 && ( strlen ( ( const char * ) V_40 ) < 1 ) )
V_40 = NULL ;
if( V_8 -> V_10 )
F_2 ( ( void * ) V_8 -> V_10 ) ;
if( V_40 )
V_8 -> V_10 = F_30 ( V_40 ) ;
else
V_8 -> V_10 = NULL ;
return ( V_8 -> V_10 ? 1 : 0 ) ;
case V_46 :
V_8 -> V_19 = ( ( V_39 == 0 ) ? 0 : 1 ) ;
return 1 ;
case V_47 :
if( V_40 && ( strlen ( ( const char * ) V_40 ) < 1 ) )
V_40 = NULL ;
if( V_8 -> V_11 )
F_2 ( ( void * ) V_8 -> V_11 ) ;
if( V_40 )
V_8 -> V_11 = F_30 ( V_40 ) ;
else
V_8 -> V_11 = NULL ;
return ( V_8 -> V_11 ? 1 : 0 ) ;
case V_48 :
if( ( V_39 < 0 ) || ( V_39 > 2 ) )
{
F_8 ( V_42 ,
V_49 ) ;
return 0 ;
}
V_8 -> V_20 = ( int ) V_39 ;
return 1 ;
case V_50 :
return F_31 ( V_13 , V_8 ) ;
case V_51 :
if( ( V_39 < 0 ) || ( V_39 > 2 ) )
{
F_8 ( V_42 ,
V_49 ) ;
return 0 ;
}
V_8 -> V_23 = ( int ) V_39 ;
return 1 ;
case V_52 :
if( ! V_40 || ( strlen ( ( const char * ) V_40 ) < 1 ) )
{
F_8 ( V_42 ,
V_49 ) ;
return 0 ;
}
{
char * V_53 = F_30 ( V_40 ) ;
if( ! V_53 )
{
F_8 ( V_42 ,
V_16 ) ;
return 0 ;
}
F_32 ( V_8 -> V_12 , V_53 , - 1 ) ;
}
return 1 ;
default:
break;
}
F_8 ( V_42 , V_54 ) ;
return 0 ;
}
static int F_33 ( T_2 * V_8 )
{
int V_55 , V_56 ;
if( ( V_8 -> V_23 != 2 ) && ( F_34 ( V_8 -> V_9 ,
V_8 -> V_10 , NULL , 0 ) ) != NULL )
return 1 ;
if( ! V_8 -> V_23 || ( ( V_55 = F_35 ( V_8 -> V_12 ) ) < 1 ) )
return 0 ;
for( V_56 = 0 ; V_56 < V_55 ; V_56 ++ )
{
const char * V_1 = F_36 ( V_8 -> V_12 , V_56 ) ;
char * V_57 = F_37 ( V_8 -> V_9 , V_8 -> V_10 , V_1 ) ;
if( ! V_57 )
return 0 ;
if( F_34 ( V_8 -> V_9 , V_57 , NULL , 0 ) )
{
F_2 ( V_57 ) ;
return 1 ;
}
F_2 ( V_57 ) ;
}
return 0 ;
}
static int F_31 ( T_3 * V_13 , T_2 * V_8 )
{
T_3 V_58 ;
T_4 V_59 ;
if( ! V_8 -> V_9 )
V_8 -> V_9 = F_38 () ;
if( ! V_8 -> V_10 )
{
if( ! V_8 -> V_11 )
return 0 ;
V_8 -> V_10 =
F_39 ( V_8 -> V_9 , V_8 -> V_11 ) ;
}
if( ! F_33 ( V_8 ) )
{
F_8 ( V_60 ,
V_61 ) ;
F_4 ( V_8 -> V_9 ) ;
V_8 -> V_9 = NULL ;
return 0 ;
}
if( ! ( V_8 -> V_18 = ( V_62 ) F_40 (
V_8 -> V_9 , V_8 -> V_22 ) ) )
{
V_8 -> V_18 = NULL ;
F_4 ( V_8 -> V_9 ) ;
V_8 -> V_9 = NULL ;
F_8 ( V_60 ,
V_63 ) ;
return 0 ;
}
if( ! V_8 -> V_19 )
{
unsigned long V_64 = 0 ;
V_8 -> V_17 = ( V_65 ) F_40 (
V_8 -> V_9 , V_8 -> V_21 ) ;
if( V_8 -> V_17 )
V_64 = V_8 -> V_17 ( V_66 ) ;
if( V_64 < V_67 )
{
V_8 -> V_18 = NULL ;
V_8 -> V_17 = NULL ;
F_4 ( V_8 -> V_9 ) ;
V_8 -> V_9 = NULL ;
F_8 ( V_60 ,
V_68 ) ;
return 0 ;
}
}
memcpy ( & V_58 , V_13 , sizeof( T_3 ) ) ;
V_59 . V_69 = F_41 () ;
V_59 . V_70 = F_42 () ;
V_59 . V_71 = F_43 () ;
F_44 ( & V_59 . V_72 . V_73 ,
& V_59 . V_72 . V_74 ,
& V_59 . V_72 . V_75 ) ;
V_59 . V_76 . V_77 = F_45 () ;
V_59 . V_76 . V_78 = F_46 () ;
V_59 . V_76 . V_79 = F_47 () ;
V_59 . V_76 . V_80 = F_48 () ;
V_59 . V_76 . V_81 = F_49 () ;
F_50 ( V_13 ) ;
if( ! V_8 -> V_18 ( V_13 , V_8 -> V_11 , & V_59 ) )
{
V_8 -> V_18 = NULL ;
V_8 -> V_17 = NULL ;
F_4 ( V_8 -> V_9 ) ;
V_8 -> V_9 = NULL ;
F_8 ( V_60 , V_82 ) ;
memcpy ( V_13 , & V_58 , sizeof( T_3 ) ) ;
return 0 ;
}
if( V_8 -> V_20 > 0 )
{
if( ! F_27 ( V_13 ) )
{
if( V_8 -> V_20 > 1 )
{
F_8 ( V_60 ,
V_83 ) ;
return 0 ;
}
F_28 () ;
}
}
return 1 ;
}
