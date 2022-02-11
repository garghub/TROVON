static int F_1 ( T_1 * V_1 )
{
const T_2 * V_2 ;
if( ! F_2 ( V_1 , V_3 )
|| ! F_3 ( V_1 , V_4 )
|| ! F_4 ( V_1 , & V_5 )
|| ! F_5 ( V_1 , V_6 )
|| ! F_6 ( V_1 , V_7 )
|| ! F_7 ( V_1 , V_8 )
|| ! F_8 ( V_1 , V_9 )
|| ! F_9 ( V_1 , V_10 )
)
return 0 ;
F_10 () ;
return 1 ;
}
static int F_11 ( T_1 * V_1 , const char * V_11 )
{
if( V_11 && ( strcmp ( V_11 , V_3 ) != 0 ) )
return 0 ;
if( ! F_1 ( V_1 ) )
return 0 ;
return 1 ;
}
static T_1 * F_12 ( void )
{
T_1 * V_12 = F_13 () ;
if( ! V_12 )
return NULL ;
if( ! F_1 ( V_12 ) )
{
F_14 ( V_12 ) ;
return NULL ;
}
return V_12 ;
}
void F_15 ( void )
{
T_1 * V_13 = F_12 () ;
if( ! V_13 ) return;
F_16 ( V_13 ) ;
F_14 ( V_13 ) ;
F_17 () ;
}
static int V_9 ( T_1 * V_1 )
{
return 1 ;
}
static int V_10 ( T_1 * V_1 )
{
return 1 ;
}
static int V_8 ( T_1 * V_1 )
{
F_18 () ;
return 1 ;
}
static int F_19 ( T_3 * V_14 , const T_3 * V_15 , T_4 * V_16 )
{
F_20 ( V_17 , V_18 ) ;
return ( 0 ) ;
}
static int F_21 ( T_3 * V_19 , const T_3 * V_20 , const T_3 * V_21 ,
const T_3 * V_22 , T_5 * V_23 , T_6 * V_24 )
{
F_20 ( V_25 , V_18 ) ;
return ( 0 ) ;
}
static int F_22 ( T_3 * V_26 , unsigned char * V_27 , int V_28 )
{
int V_29 ;
V_29 = F_23 ( V_26 ) ;
if ( V_29 > V_28 )
{
F_20 ( V_30 , V_31 ) ;
return ( 0 ) ;
}
memset ( V_27 , 0 , ( unsigned int ) V_28 ) ;
if ( ! F_24 ( V_26 , & ( V_27 [ V_28 - V_29 ] ) ) )
return ( 0 ) ;
return ( 1 ) ;
}
static T_3 * F_25 ( unsigned char * V_26 , T_3 * V_27 , int V_28 )
{
int V_29 ;
T_3 * V_12 ;
for ( V_29 = 0 ; V_29 < V_28 ; V_29 ++ )
if ( V_26 [ V_29 ] ) break;
V_12 = F_26 ( & ( V_26 [ V_29 ] ) , V_28 - V_29 , V_27 ) ;
return ( V_12 ) ;
}
static int F_27 ( T_7 * V_26 , T_4 * V_27 )
{
V_27 -> V_32 = F_25 ( V_26 -> V_22 , NULL , V_33 ) ;
V_27 -> V_1 = F_25 ( V_26 -> V_1 , NULL , V_33 ) ;
if ( ( V_27 -> V_32 == NULL ) || ( V_27 -> V_1 == NULL ) ) return ( 0 ) ;
return ( 1 ) ;
}
static int F_28 ( T_4 * V_26 , T_8 * V_27 )
{
V_27 -> V_34 = F_29 ( V_26 -> V_32 ) ;
if ( ! F_22 ( V_26 -> V_32 , V_27 -> V_35 , V_36 ) ) return ( 0 ) ;
if ( ! F_22 ( V_26 -> V_1 , V_27 -> V_37 , V_36 ) ) return ( 0 ) ;
return ( 1 ) ;
}
static int F_30 ( T_9 * V_26 , T_4 * V_27 )
{
if ( ( V_27 -> V_32 = F_25 ( V_26 -> V_22 , NULL , V_33 ) ) == NULL )
return ( 0 ) ;
if ( ( V_27 -> V_1 = F_25 ( V_26 -> V_1 , NULL , V_33 ) ) == NULL )
return ( 0 ) ;
if ( ( V_27 -> V_38 = F_25 ( V_26 -> V_38 , NULL , V_33 ) ) == NULL )
return ( 0 ) ;
if ( ( V_27 -> V_21 = F_25 ( V_26 -> V_39 [ 0 ] , NULL , V_40 ) ) == NULL )
return ( 0 ) ;
if ( ( V_27 -> V_41 = F_25 ( V_26 -> V_39 [ 1 ] , NULL , V_40 ) ) == NULL )
return ( 0 ) ;
if ( ( V_27 -> V_42 = F_25 ( V_26 -> V_43 [ 0 ] , NULL , V_40 ) )
== NULL )
return ( 0 ) ;
if ( ( V_27 -> V_44 = F_25 ( V_26 -> V_43 [ 1 ] , NULL , V_40 ) )
== NULL )
return ( 0 ) ;
if ( ( V_27 -> V_45 = F_25 ( V_26 -> V_46 , NULL , V_40 ) ) == NULL )
return ( 0 ) ;
return ( 1 ) ;
}
static int F_31 ( T_4 * V_26 , T_10 * V_27 )
{
V_27 -> V_34 = F_29 ( V_26 -> V_32 ) ;
if ( ! F_22 ( V_26 -> V_32 , V_27 -> V_35 , V_36 ) ) return ( 0 ) ;
if ( ! F_22 ( V_26 -> V_1 , V_27 -> V_47 , V_36 ) ) return ( 0 ) ;
if ( ! F_22 ( V_26 -> V_38 , V_27 -> V_37 , V_36 ) ) return ( 0 ) ;
if ( ! F_22 ( V_26 -> V_21 , V_27 -> V_39 [ 0 ] , V_48 ) ) return ( 0 ) ;
if ( ! F_22 ( V_26 -> V_41 , V_27 -> V_39 [ 1 ] , V_48 ) ) return ( 0 ) ;
if ( ! F_22 ( V_26 -> V_42 , V_27 -> V_49 [ 0 ] , V_48 ) ) return ( 0 ) ;
if ( ! F_22 ( V_26 -> V_44 , V_27 -> V_49 [ 1 ] , V_48 ) ) return ( 0 ) ;
if ( ! F_22 ( V_26 -> V_45 , V_27 -> V_50 , V_48 ) ) return ( 0 ) ;
return ( 1 ) ;
}
static int F_32 ( int V_51 , const unsigned char * V_26 , unsigned char * V_27 ,
T_4 * V_16 , int V_52 )
{
int V_29 , V_53 = - 1 ;
T_10 V_54 ;
if ( ! F_31 ( V_16 , & V_54 ) )
goto V_55;
if ( ( V_29 = F_33 ( V_27 , ( unsigned int * ) & V_53 , ( unsigned char * ) V_26 , V_51 , & V_54 ) ) != 0 )
{
F_20 ( V_56 , V_29 ) ;
V_53 = - 1 ;
}
V_55:
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
return ( V_53 ) ;
}
static int F_34 ( int V_51 , const unsigned char * V_26 , unsigned char * V_27 ,
T_4 * V_16 , int V_52 )
{
int V_29 , V_53 = - 1 ;
T_10 V_54 ;
if ( V_52 != V_57 )
{
F_20 ( V_58 , V_59 ) ;
goto V_55;
}
if ( ! F_31 ( V_16 , & V_54 ) )
goto V_55;
if ( ( V_29 = F_35 ( V_27 , ( unsigned int * ) & V_53 , ( unsigned char * ) V_26 , V_51 , & V_54 ) ) != 0 )
{
F_20 ( V_58 , V_29 ) ;
V_53 = - 1 ;
}
V_55:
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
return ( V_53 ) ;
}
static int F_36 ( int V_51 , const unsigned char * V_26 , unsigned char * V_27 ,
T_4 * V_16 , int V_52 )
{
int V_29 , V_53 = - 1 ;
T_8 V_54 ;
if ( ! F_28 ( V_16 , & V_54 ) )
goto V_55;
if ( ( V_29 = F_37 ( V_27 , ( unsigned int * ) & V_53 , ( unsigned char * ) V_26 , V_51 , & V_54 ) ) != 0 )
{
F_20 ( V_60 , V_29 ) ;
V_53 = - 1 ;
}
V_55:
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
return ( V_53 ) ;
}
static int F_38 ( int V_51 , const unsigned char * V_26 , unsigned char * V_27 ,
T_4 * V_16 , int V_52 )
{
int V_53 = - 1 ;
int V_29 ;
T_8 V_54 ;
T_11 V_61 ;
unsigned char V_62 [ 16 ] ;
if ( V_52 != V_57 && V_52 != V_63 )
{
F_20 ( V_64 , V_59 ) ;
goto V_55;
}
F_39 ( & V_61 ) ;
F_40 ( ( unsigned int * ) & V_29 , & V_61 ) ;
while ( V_29 > 0 )
{
if ( F_41 ( V_62 , 16 ) <= 0 )
goto V_55;
F_42 ( & V_61 , V_62 , ( unsigned int ) ( ( V_29 > 16 ) ? 16 : V_29 ) ) ;
V_29 -= 16 ;
}
if ( ! F_28 ( V_16 , & V_54 ) )
goto V_55;
if ( ( V_29 = F_43 ( V_27 , ( unsigned int * ) & V_53 , ( unsigned char * ) V_26 , V_51 , & V_54 , & V_61 ) ) != 0 )
{
F_20 ( V_64 , V_29 ) ;
V_53 = - 1 ;
goto V_55;
}
V_55:
memset ( & V_54 , 0 , sizeof( V_54 ) ) ;
F_44 ( & V_61 ) ;
memset ( & V_61 , 0 , sizeof( V_61 ) ) ;
return ( V_53 ) ;
}
static int V_6 ( T_1 * V_1 , const T_12 * * V_65 ,
const int * * V_66 , int V_67 )
{
int V_68 = 1 ;
if( ! V_65 )
{
* V_66 = V_69 ;
return ( sizeof( V_69 ) - 1 ) / sizeof( V_69 [ 0 ] ) ;
}
switch ( V_67 )
{
case V_70 :
* V_65 = & V_71 ; break;
case V_72 :
* V_65 = & V_73 ; break;
case V_74 :
* V_65 = & V_75 ; break;
default:
V_68 = 0 ;
* V_65 = NULL ;
break;
}
return V_68 ;
}
static int V_7 ( T_1 * V_1 , const T_13 * * V_76 ,
const int * * V_66 , int V_67 )
{
int V_68 = 1 ;
if( ! V_76 )
{
* V_66 = V_77 ;
return ( sizeof( V_77 ) - 1 ) / sizeof( V_77 [ 0 ] ) ;
}
switch ( V_67 )
{
case V_78 :
* V_76 = & V_79 ; break;
case V_80 :
* V_76 = & V_81 ; break;
default:
V_68 = 0 ;
* V_76 = NULL ;
break;
}
return V_68 ;
}
static int F_45 ( T_14 * V_23 , const unsigned char * V_82 ,
const unsigned char * V_83 , int V_84 )
{
F_46 ( F_47 ( V_23 ) , ( unsigned char * ) V_82 , ( unsigned char * ) V_83 , V_84 ) ;
return 1 ;
}
static int F_48 ( T_14 * V_23 , unsigned char * V_85 ,
const unsigned char * V_86 , unsigned int V_87 )
{
int V_12 = F_49 ( F_47 ( V_23 ) , V_85 , ( unsigned char * ) V_86 , V_87 ) ;
switch ( V_12 )
{
case V_88 :
F_20 ( V_89 , V_90 ) ;
break;
case 0 :
break;
default:
F_20 ( V_89 , V_91 ) ;
}
return ! V_12 ;
}
static int F_50 ( T_14 * V_23 )
{
memset ( F_47 ( V_23 ) , 0 , V_23 -> V_65 -> V_92 ) ;
return 1 ;
}
static int F_51 ( T_14 * V_23 , const unsigned char * V_82 ,
const unsigned char * V_83 , int V_84 )
{
F_52 ( F_47 ( V_23 ) , ( unsigned char * ) V_82 , ( unsigned char * ) V_83 ,
V_84 ) ;
return 1 ;
}
static int F_53 ( T_14 * V_23 , unsigned char * V_85 ,
const unsigned char * V_86 , unsigned int V_87 )
{
int V_12 = F_54 ( F_47 ( V_23 ) , V_85 , ( unsigned char * ) V_86 , V_87 ) ;
switch ( V_12 )
{
case V_88 :
F_20 ( V_89 , V_90 ) ;
break;
case 0 :
break;
default:
F_20 ( V_89 , V_91 ) ;
}
return ! V_12 ;
}
static int F_55 ( T_14 * V_23 )
{
memset ( F_47 ( V_23 ) , 0 , V_23 -> V_65 -> V_92 ) ;
return 1 ;
}
static int F_56 ( T_14 * V_23 , const unsigned char * V_82 ,
const unsigned char * V_83 , int V_84 )
{
F_57 ( F_47 ( V_23 ) , ( unsigned char * ) V_82 , ( unsigned char * ) V_83 ,
V_84 ) ;
return 1 ;
}
static int F_58 ( T_14 * V_23 , unsigned char * V_85 ,
const unsigned char * V_86 , unsigned int V_87 )
{
int V_12 = F_59 ( F_47 ( V_23 ) , V_85 , ( unsigned char * ) V_86 , V_87 ) ;
switch ( V_12 )
{
case V_88 :
F_20 ( V_89 , V_90 ) ;
break;
case 0 :
break;
default:
F_20 ( V_89 , V_91 ) ;
}
return ! V_12 ;
}
static int F_60 ( T_14 * V_23 )
{
memset ( F_47 ( V_23 ) , 0 , V_23 -> V_65 -> V_92 ) ;
return 1 ;
}
static int F_61 ( T_15 * V_23 )
{
F_62 ( F_47 ( V_23 ) ) ;
return 1 ;
}
static int F_63 ( T_15 * V_23 , const void * F_47 ,
unsigned long V_93 )
{
F_64 ( F_47 ( V_23 ) , ( unsigned char * ) F_47 , ( unsigned int ) V_93 ) ;
return 1 ;
}
static int F_65 ( T_15 * V_23 , unsigned char * V_94 )
{
F_66 ( V_94 , F_47 ( V_23 ) ) ;
return 1 ;
}
static int F_67 ( T_15 * V_23 )
{
F_68 ( F_47 ( V_23 ) ) ;
return 1 ;
}
static int F_69 ( T_15 * V_23 , const void * F_47 ,
unsigned long V_93 )
{
F_70 ( F_47 ( V_23 ) , ( unsigned char * ) F_47 , ( unsigned int ) V_93 ) ;
return 1 ;
}
static int F_71 ( T_15 * V_23 , unsigned char * V_94 )
{
F_72 ( V_94 , F_47 ( V_23 ) ) ;
return 1 ;
}
