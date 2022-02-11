static int F_1 ( T_1 * V_1 )
{
#ifndef F_2
const T_2 * V_2 ;
#endif
#ifndef F_3
const T_3 * V_3 ;
#endif
#ifndef F_4
const T_4 * V_4 ;
#endif
if( ! F_5 ( V_1 , V_5 ) ||
! F_6 ( V_1 , V_6 ) ||
#ifndef F_2
! F_7 ( V_1 , & V_7 ) ||
#endif
#ifndef F_3
! F_8 ( V_1 , & V_8 ) ||
#endif
#ifndef F_4
! F_9 ( V_1 , & V_9 ) ||
#endif
! F_10 ( V_1 , V_10 ) ||
! F_11 ( V_1 , V_11 ) ||
! F_12 ( V_1 , V_12 ) ||
! F_13 ( V_1 , V_13 ) ||
! F_14 ( V_1 , V_14 ) )
return 0 ;
#ifndef F_2
V_2 = F_15 () ;
V_7 . V_15 = V_2 -> V_15 ;
V_7 . V_16 = V_2 -> V_16 ;
V_7 . V_17 = V_2 -> V_17 ;
V_7 . V_18 = V_2 -> V_18 ;
#endif
#ifndef F_3
V_3 = F_16 () ;
V_8 . V_19 = V_3 -> V_19 ;
V_8 . V_20 = V_3 -> V_20 ;
V_8 . V_21 = V_3 -> V_21 ;
#endif
#ifndef F_4
V_4 = F_17 () ;
V_9 . V_22 = V_4 -> V_22 ;
V_9 . V_23 = V_4 -> V_23 ;
#endif
F_18 () ;
return 1 ;
}
static T_1 * F_19 ( void )
{
T_1 * V_24 = F_20 () ;
if( ! V_24 )
return NULL ;
if( ! F_1 ( V_24 ) )
{
F_21 ( V_24 ) ;
return NULL ;
}
return V_24 ;
}
void F_22 ( void )
{
T_1 * V_25 = F_19 () ;
if( ! V_25 ) return;
F_23 ( V_25 ) ;
F_21 ( V_25 ) ;
F_24 () ;
}
static const char * F_25 ( void )
{
if( V_26 )
return V_26 ;
return L_1 ;
}
static void F_26 ( void )
{
if( V_26 )
F_27 ( ( void * ) V_26 ) ;
V_26 = NULL ;
}
static long F_28 ( const char * V_27 )
{
F_26 () ;
return ( ( ( V_26 = F_29 ( V_27 ) ) != NULL ) ? 1 : 0 ) ;
}
static int V_10 ( T_1 * V_1 )
{
F_26 () ;
F_30 () ;
return 1 ;
}
static int V_11 ( T_1 * V_1 )
{
T_5 * V_28 ;
T_6 * V_29 ;
T_7 * V_30 ;
unsigned int V_31 [ 1024 ] ;
if( V_32 != NULL )
{
F_31 ( V_33 , V_34 ) ;
goto V_35;
}
V_32 = F_32 ( NULL , F_25 () , NULL , 0 ) ;
if( V_32 == NULL )
{
F_31 ( V_33 , V_36 ) ;
goto V_35;
}
if( ! ( V_28 = ( T_5 * ) F_33 (
V_32 , V_37 ) ) ||
! ( V_29 = ( T_6 * ) F_33 (
V_32 , V_38 ) ) ||
! ( V_30 = ( T_7 * ) F_33 (
V_32 , V_39 ) ) )
{
F_31 ( V_33 , V_36 ) ;
goto V_35;
}
V_40 = V_28 ;
V_41 = V_29 ;
V_42 = V_30 ;
if( V_28 ( 0L , V_31 ) != 0 )
{
F_31 ( V_33 , V_43 ) ;
goto V_35;
}
return 1 ;
V_35:
if( V_32 )
F_34 ( V_32 ) ;
V_32 = NULL ;
V_40 = NULL ;
V_41 = NULL ;
V_42 = NULL ;
return 0 ;
}
static int V_12 ( T_1 * V_1 )
{
F_26 () ;
if( V_32 == NULL )
{
F_31 ( V_44 , V_36 ) ;
return 0 ;
}
if( ! F_34 ( V_32 ) )
{
F_31 ( V_44 , V_43 ) ;
return 0 ;
}
V_32 = NULL ;
V_40 = NULL ;
V_41 = NULL ;
V_42 = NULL ;
return 1 ;
}
static int V_13 ( T_1 * V_1 , int V_45 , long V_46 , void * V_47 , void (* F_35)( void ) )
{
int V_48 = ( ( V_32 == NULL ) ? 0 : 1 ) ;
switch( V_45 )
{
case V_49 :
if( V_47 == NULL )
{
F_31 ( V_50 , V_51 ) ;
return 0 ;
}
if( V_48 )
{
F_31 ( V_50 , V_34 ) ;
return 0 ;
}
return F_28 ( ( const char * ) V_47 ) ;
default:
break;
}
F_31 ( V_50 , V_52 ) ;
return 0 ;
}
static int F_36 ( T_8 * V_53 , const T_8 * V_54 , const T_8 * V_47 ,
const T_8 * V_55 , T_9 * V_56 )
{
T_8 * V_57 ;
T_8 * V_58 ;
T_8 * V_59 ;
T_8 * V_60 ;
T_10 V_61 ;
int V_62 , V_63 ;
V_57 = V_58 = V_59 = V_60 = NULL ;
V_62 = 0 ;
if( ! V_32 )
{
F_31 ( V_64 , V_36 ) ;
goto V_35;
}
F_37 ( V_56 ) ;
V_57 = F_38 ( V_56 ) ;
V_58 = F_38 ( V_56 ) ;
V_59 = F_38 ( V_56 ) ;
V_60 = F_38 ( V_56 ) ;
if ( ! V_60 )
{
F_31 ( V_64 , V_65 ) ;
goto V_35;
}
if( ! F_39 ( V_57 , V_55 -> V_66 ) || ! F_39 ( V_58 , V_55 -> V_66 ) ||
! F_39 ( V_59 , V_55 -> V_66 ) || ! F_39 ( V_60 , V_55 -> V_66 ) )
{
F_31 ( V_64 , V_67 ) ;
goto V_35;
}
memset ( & V_61 , 0 , sizeof V_61 ) ;
V_63 = F_40 ( V_55 ) ;
memset ( V_58 -> V_68 , 0 , V_63 ) ;
memset ( V_57 -> V_68 , 0 , V_63 ) ;
F_41 ( V_47 , ( unsigned char * ) V_58 -> V_68 + V_63 - F_40 ( V_47 ) ) ;
F_41 ( V_55 , ( unsigned char * ) V_57 -> V_68 + V_63 - F_40 ( V_55 ) ) ;
V_61 . V_69 . V_70 = ( unsigned char * ) V_58 -> V_68 ;
V_61 . V_69 . V_71 = V_63 ;
V_61 . V_57 . V_70 = ( unsigned char * ) V_57 -> V_68 ;
V_61 . V_57 . V_71 = V_63 ;
memset ( V_59 -> V_68 , 0 , V_63 ) ;
memset ( V_60 -> V_68 , 0 , V_63 ) ;
F_41 ( V_54 , ( unsigned char * ) V_59 -> V_68 + V_63 - F_40 ( V_54 ) ) ;
if( V_41 ( & V_61 , ( unsigned char * ) V_60 -> V_68 ,
( unsigned char * ) V_59 -> V_68 ,
V_61 . V_57 . V_71 ) != 0 )
{
F_31 ( V_64 , V_72 ) ;
goto V_35;
}
F_42 ( ( unsigned char * ) V_60 -> V_68 , V_63 , V_53 ) ;
V_62 = 1 ;
V_35:
F_43 ( V_56 ) ;
return V_62 ;
}
static int F_44 ( T_8 * V_73 , const T_8 * V_74 , T_11 * V_75 , T_9 * V_56 )
{
int V_62 = 0 ;
if( ! V_32 )
{
F_31 ( V_76 , V_36 ) ;
goto V_35;
}
if( ! V_75 -> V_68 || ! V_75 -> V_77 )
{
F_31 ( V_76 , V_78 ) ;
goto V_35;
}
V_62 = F_36 ( V_73 , V_74 , V_75 -> V_68 , V_75 -> V_77 , V_56 ) ;
V_35:
return V_62 ;
}
static int F_45 ( T_12 * V_79 , T_8 * V_80 , T_8 * V_81 ,
T_8 * V_28 , T_8 * V_82 , T_8 * V_29 , T_8 * V_55 ,
T_9 * V_56 , T_13 * V_83 )
{
T_8 V_84 ;
int V_62 = 0 ;
F_46 ( & V_84 ) ;
if ( ! F_36 ( V_80 , V_81 , V_28 , V_55 , V_56 ) ) goto V_85;
if ( ! F_36 ( & V_84 , V_82 , V_29 , V_55 , V_56 ) ) goto V_85;
if ( ! F_47 ( V_80 , V_80 , & V_84 , V_55 , V_56 ) ) goto V_85;
V_62 = 1 ;
V_85:
F_48 ( & V_84 ) ;
return V_62 ;
}
static int F_49 ( T_12 * V_79 , T_8 * V_53 , T_8 * V_54 ,
const T_8 * V_47 , const T_8 * V_55 , T_9 * V_56 ,
T_13 * V_86 )
{
return F_36 ( V_53 , V_54 , V_47 , V_55 , V_56 ) ;
}
static int F_50 ( T_8 * V_53 , const T_8 * V_54 , const T_8 * V_47 ,
const T_8 * V_55 , T_9 * V_56 , T_13 * V_86 )
{
return F_36 ( V_53 , V_54 , V_47 , V_55 , V_56 ) ;
}
static int F_51 ( const T_14 * V_87 , T_8 * V_53 ,
const T_8 * V_54 , const T_8 * V_47 ,
const T_8 * V_55 , T_9 * V_56 , T_13 * V_86 )
{
return F_36 ( V_53 , V_54 , V_47 , V_55 , V_56 ) ;
}
static int F_52 ( T_1 * V_1 , const char * V_88 )
{
if( V_88 && ( strcmp ( V_88 , V_5 ) != 0 ) )
return 0 ;
if( ! F_1 ( V_1 ) )
return 0 ;
return 1 ;
}
