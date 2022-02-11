int F_1 ( char * V_1 , int V_2 , int V_3 , void * V_4 )
{
#ifdef F_2
F_3 ( V_5 , V_6 ) ;
return ( - 1 ) ;
#else
int V_7 , V_8 ;
const char * V_9 ;
if( V_4 ) {
V_7 = strlen ( V_4 ) ;
V_7 = ( V_7 > V_2 ) ? V_2 : V_7 ;
memcpy ( V_1 , V_4 , V_7 ) ;
return ( V_7 ) ;
}
V_9 = F_4 () ;
if ( V_9 == NULL )
V_9 = L_1 ;
for (; ; )
{
V_7 = F_5 ( V_1 , V_10 , V_2 , V_9 , V_3 ) ;
if ( V_7 != 0 )
{
F_3 ( V_5 , V_11 ) ;
memset ( V_1 , 0 , ( unsigned int ) V_2 ) ;
return ( - 1 ) ;
}
V_8 = strlen ( V_1 ) ;
if ( V_8 < V_10 )
{
fprintf ( V_12 , L_2 , V_10 ) ;
}
else
break;
}
return ( V_8 ) ;
#endif
}
void F_6 ( char * V_1 , int type )
{
const char * V_13 ;
if ( type == V_14 )
V_13 = L_3 ;
else if ( type == V_15 )
V_13 = L_4 ;
else if ( type == V_16 )
V_13 = L_5 ;
else
V_13 = L_6 ;
F_7 ( V_1 , L_7 , V_17 ) ;
F_7 ( V_1 , V_13 , V_17 ) ;
F_7 ( V_1 , L_8 , V_17 ) ;
}
void F_8 ( char * V_1 , const char * type , int V_18 , char * V_13 )
{
static const unsigned char V_19 [ 17 ] = L_9 ;
long V_7 ;
int V_8 ;
F_7 ( V_1 , L_10 , V_17 ) ;
F_7 ( V_1 , type , V_17 ) ;
F_7 ( V_1 , L_11 , V_17 ) ;
V_8 = strlen ( V_1 ) ;
if ( V_8 + ( V_18 * 2 ) + 1 > V_17 )
return;
for ( V_7 = 0 ; V_7 < V_18 ; V_7 ++ )
{
V_1 [ V_8 + V_7 * 2 ] = V_19 [ ( V_13 [ V_7 ] >> 4 ) & 0x0f ] ;
V_1 [ V_8 + V_7 * 2 + 1 ] = V_19 [ ( V_13 [ V_7 ] ) & 0x0f ] ;
}
V_1 [ V_8 + V_7 * 2 ] = '\n' ;
V_1 [ V_8 + V_7 * 2 + 1 ] = '\0' ;
}
void * F_9 ( T_1 * V_20 , const char * V_21 , T_2 * V_22 , void * * V_23 ,
T_3 * V_24 , void * V_25 )
{
T_4 * V_26 ;
void * V_27 ;
if ( ( V_26 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_28 , V_29 ) ;
return ( 0 ) ;
}
F_12 ( V_26 , V_22 , V_30 ) ;
V_27 = F_13 ( V_20 , V_21 , V_26 , V_23 , V_24 , V_25 ) ;
F_14 ( V_26 ) ;
return ( V_27 ) ;
}
static int F_15 ( const char * V_31 , const char * V_21 )
{
if ( ! strcmp ( V_31 , V_21 ) ) return 1 ;
if( ! strcmp ( V_21 , V_32 ) )
{
int V_33 ;
const T_5 * V_34 ;
if( ! strcmp ( V_31 , V_35 ) )
return 1 ;
if( ! strcmp ( V_31 , V_36 ) )
return 1 ;
V_33 = F_16 ( V_31 , L_12 ) ;
if ( V_33 > 0 )
{
V_34 = F_17 ( NULL , V_31 , V_33 ) ;
if ( V_34 && V_34 -> V_37 )
return 1 ;
}
return 0 ;
}
if( ! strcmp ( V_21 , V_38 ) )
{
int V_33 ;
const T_5 * V_34 ;
V_33 = F_16 ( V_31 , L_13 ) ;
if ( V_33 > 0 )
{
T_6 * V_39 ;
V_34 = F_17 ( & V_39 , V_31 , V_33 ) ;
if ( V_34 )
{
int V_40 ;
if ( V_34 -> V_41 )
V_40 = 1 ;
else
V_40 = 0 ;
#ifndef F_18
if ( V_39 )
F_19 ( V_39 ) ;
#endif
return V_40 ;
}
}
return 0 ;
}
if( ! strcmp ( V_31 , V_42 ) &&
! strcmp ( V_21 , V_43 ) ) return 1 ;
if( ! strcmp ( V_31 , V_44 ) &&
! strcmp ( V_21 , V_45 ) ) return 1 ;
if( ! strcmp ( V_31 , V_43 ) &&
! strcmp ( V_21 , V_46 ) ) return 1 ;
if( ! strcmp ( V_31 , V_42 ) &&
! strcmp ( V_21 , V_46 ) ) return 1 ;
if( ! strcmp ( V_31 , V_43 ) &&
! strcmp ( V_21 , V_47 ) ) return 1 ;
if( ! strcmp ( V_31 , V_48 ) &&
! strcmp ( V_21 , V_47 ) ) return 1 ;
#ifndef F_20
if( ! strcmp ( V_31 , V_43 ) &&
! strcmp ( V_21 , V_49 ) ) return 1 ;
if( ! strcmp ( V_31 , V_47 ) &&
! strcmp ( V_21 , V_49 ) ) return 1 ;
#endif
return 0 ;
}
int F_21 ( unsigned char * * V_50 , long * V_51 , char * * V_52 , const char * V_21 , T_4 * V_53 ,
T_3 * V_24 , void * V_25 )
{
T_7 V_54 ;
char * V_31 = NULL , * V_55 = NULL ;
unsigned char * V_56 = NULL ;
long V_18 ;
int V_27 = 0 ;
for (; ; )
{
if ( ! F_22 ( V_53 , & V_31 , & V_55 , & V_56 , & V_18 ) ) {
if( F_23 ( F_24 () ) ==
V_57 )
F_25 ( 2 , L_14 , V_21 ) ;
return 0 ;
}
if( F_15 ( V_31 , V_21 ) ) break;
F_26 ( V_31 ) ;
F_26 ( V_55 ) ;
F_26 ( V_56 ) ;
}
if ( ! F_27 ( V_55 , & V_54 ) ) goto V_58;
if ( ! F_28 ( & V_54 , V_56 , & V_18 , V_24 , V_25 ) ) goto V_58;
* V_50 = V_56 ;
* V_51 = V_18 ;
if ( V_52 )
* V_52 = V_31 ;
V_27 = 1 ;
V_58:
if ( ! V_27 || ! V_52 ) F_26 ( V_31 ) ;
F_26 ( V_55 ) ;
if ( ! V_27 ) F_26 ( V_56 ) ;
return V_27 ;
}
int F_29 ( T_8 * V_59 , const char * V_21 , T_2 * V_22 ,
void * V_23 , const T_9 * V_60 , unsigned char * V_61 ,
int V_62 , T_3 * V_63 , void * V_25 )
{
T_4 * V_26 ;
int V_27 ;
if ( ( V_26 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_64 , V_29 ) ;
return ( 0 ) ;
}
F_12 ( V_26 , V_22 , V_30 ) ;
V_27 = F_30 ( V_59 , V_21 , V_26 , V_23 , V_60 , V_61 , V_62 , V_63 , V_25 ) ;
F_14 ( V_26 ) ;
return ( V_27 ) ;
}
int F_30 ( T_8 * V_59 , const char * V_21 , T_4 * V_53 ,
void * V_23 , const T_9 * V_60 , unsigned char * V_61 ,
int V_62 , T_3 * V_63 , void * V_25 )
{
T_10 V_65 ;
int V_66 = 0 , V_7 , V_8 , V_27 = 0 ;
unsigned char * V_67 , * V_56 = NULL ;
const char * V_68 = NULL ;
char V_1 [ V_17 ] ;
unsigned char V_4 [ V_69 ] ;
unsigned char V_70 [ V_71 ] ;
if ( V_60 != NULL )
{
V_68 = F_31 ( F_32 ( V_60 ) ) ;
if ( V_68 == NULL )
{
F_3 ( V_72 , V_73 ) ;
goto V_58;
}
}
if ( ( V_66 = V_59 ( V_23 , NULL ) ) < 0 )
{
F_3 ( V_72 , V_74 ) ;
V_66 = 0 ;
goto V_58;
}
V_56 = ( unsigned char * ) F_33 ( ( unsigned int ) V_66 + 20 ) ;
if ( V_56 == NULL )
{
F_3 ( V_72 , V_75 ) ;
goto V_58;
}
V_67 = V_56 ;
V_7 = V_59 ( V_23 , & V_67 ) ;
if ( V_60 != NULL )
{
if ( V_61 == NULL )
{
if ( V_63 == NULL )
V_62 = F_1 ( V_1 , V_17 , 1 , V_25 ) ;
else
V_62 = (* V_63)( V_1 , V_17 , 1 , V_25 ) ;
if ( V_62 <= 0 )
{
F_3 ( V_72 , V_76 ) ;
goto V_58;
}
#ifdef F_34
F_35 ( V_1 , V_1 , V_62 ) ;
#endif
V_61 = ( unsigned char * ) V_1 ;
}
F_36 ( V_56 , V_7 , 0 ) ;
F_37 ( V_60 -> V_77 <= ( int ) sizeof( V_70 ) ) ;
if ( F_38 ( V_70 , V_60 -> V_77 ) < 0 )
goto V_58;
F_39 ( V_60 , F_40 () , V_70 , V_61 , V_62 , 1 , V_4 , NULL ) ;
if ( V_61 == ( unsigned char * ) V_1 ) F_41 ( V_1 , V_17 ) ;
F_37 ( strlen ( V_68 ) + 23 + 2 * V_60 -> V_77 + 13 <= sizeof V_1 ) ;
V_1 [ 0 ] = '\0' ;
F_6 ( V_1 , V_14 ) ;
F_8 ( V_1 , V_68 , V_60 -> V_77 , ( char * ) V_70 ) ;
F_42 ( & V_65 ) ;
F_43 ( & V_65 , V_60 , NULL , V_4 , V_70 ) ;
F_44 ( & V_65 , V_56 , & V_8 , V_56 , V_7 ) ;
F_45 ( & V_65 , & ( V_56 [ V_8 ] ) , & V_7 ) ;
F_46 ( & V_65 ) ;
V_7 += V_8 ;
V_27 = 1 ;
}
else
{
V_27 = 1 ;
V_1 [ 0 ] = '\0' ;
}
V_7 = F_47 ( V_53 , V_21 , V_1 , V_56 , V_7 ) ;
if ( V_7 <= 0 ) V_27 = 0 ;
V_58:
F_41 ( V_4 , sizeof( V_4 ) ) ;
F_41 ( V_70 , sizeof( V_70 ) ) ;
F_41 ( ( char * ) & V_65 , sizeof( V_65 ) ) ;
F_41 ( V_1 , V_17 ) ;
if ( V_56 != NULL )
{
F_41 ( V_56 , ( unsigned int ) V_66 ) ;
F_26 ( V_56 ) ;
}
return ( V_27 ) ;
}
int F_28 ( T_7 * V_54 , unsigned char * V_56 , long * V_51 ,
T_3 * V_63 , void * V_25 )
{
int V_7 , V_8 , V_78 , V_62 ;
long V_18 ;
T_10 V_65 ;
unsigned char V_4 [ V_69 ] ;
char V_1 [ V_17 ] ;
V_18 = * V_51 ;
if ( V_54 -> V_54 == NULL ) return ( 1 ) ;
if ( V_63 == NULL )
V_62 = F_1 ( V_1 , V_17 , 0 , V_25 ) ;
else
V_62 = V_63 ( V_1 , V_17 , 0 , V_25 ) ;
if ( V_62 <= 0 )
{
F_3 ( V_79 , V_80 ) ;
return ( 0 ) ;
}
#ifdef F_34
F_35 ( V_1 , V_1 , V_62 ) ;
#endif
F_39 ( V_54 -> V_54 , F_40 () , & ( V_54 -> V_70 [ 0 ] ) ,
( unsigned char * ) V_1 , V_62 , 1 , V_4 , NULL ) ;
V_8 = ( int ) V_18 ;
F_42 ( & V_65 ) ;
F_48 ( & V_65 , V_54 -> V_54 , NULL , V_4 , & ( V_54 -> V_70 [ 0 ] ) ) ;
F_49 ( & V_65 , V_56 , & V_7 , V_56 , V_8 ) ;
V_78 = F_50 ( & V_65 , & ( V_56 [ V_7 ] ) , & V_8 ) ;
F_46 ( & V_65 ) ;
F_41 ( ( char * ) V_1 , sizeof( V_1 ) ) ;
F_41 ( ( char * ) V_4 , sizeof( V_4 ) ) ;
V_8 += V_7 ;
if ( ! V_78 )
{
F_3 ( V_79 , V_81 ) ;
return ( 0 ) ;
}
* V_51 = V_8 ;
return ( 1 ) ;
}
int F_27 ( char * V_55 , T_7 * V_54 )
{
const T_9 * V_60 = NULL ;
char * V_67 , V_82 ;
char * * V_83 = & V_55 ;
V_54 -> V_54 = NULL ;
if ( ( V_55 == NULL ) || ( * V_55 == '\0' ) || ( * V_55 == '\n' ) )
return ( 1 ) ;
if ( strncmp ( V_55 , L_15 , 11 ) != 0 )
{ F_3 ( V_84 , V_85 ) ; return ( 0 ) ; }
V_55 += 11 ;
if ( * V_55 != '4' ) return ( 0 ) ; V_55 ++ ;
if ( * V_55 != ',' ) return ( 0 ) ; V_55 ++ ;
if ( strncmp ( V_55 , L_3 , 9 ) != 0 )
{ F_3 ( V_84 , V_86 ) ; return ( 0 ) ; }
for (; ( * V_55 != '\n' ) && ( * V_55 != '\0' ) ; V_55 ++ )
;
if ( * V_55 == '\0' )
{ F_3 ( V_84 , V_87 ) ; return ( 0 ) ; }
V_55 ++ ;
if ( strncmp ( V_55 , L_10 , 10 ) != 0 )
{ F_3 ( V_84 , V_88 ) ; return ( 0 ) ; }
V_55 += 10 ;
V_67 = V_55 ;
for (; ; )
{
V_82 = * V_55 ;
#ifndef F_34
if ( ! ( ( ( V_82 >= 'A' ) && ( V_82 <= 'Z' ) ) || ( V_82 == '-' ) ||
( ( V_82 >= '0' ) && ( V_82 <= '9' ) ) ) )
break;
#else
if ( ! ( isupper ( V_82 ) || ( V_82 == '-' ) ||
isdigit ( V_82 ) ) )
break;
#endif
V_55 ++ ;
}
* V_55 = '\0' ;
V_54 -> V_54 = V_60 = F_51 ( V_67 ) ;
* V_55 = V_82 ;
V_55 ++ ;
if ( V_60 == NULL )
{
F_3 ( V_84 , V_89 ) ;
return ( 0 ) ;
}
if ( ! F_52 ( V_83 , & ( V_54 -> V_70 [ 0 ] ) , V_60 -> V_77 ) )
return ( 0 ) ;
return ( 1 ) ;
}
static int F_52 ( char * * V_90 , unsigned char * V_91 , int V_2 )
{
int V_92 , V_7 ;
char * V_93 ;
V_93 = * V_90 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) V_91 [ V_7 ] = 0 ;
V_2 *= 2 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
{
if ( ( * V_93 >= '0' ) && ( * V_93 <= '9' ) )
V_92 = * V_93 - '0' ;
else if ( ( * V_93 >= 'A' ) && ( * V_93 <= 'F' ) )
V_92 = * V_93 - 'A' + 10 ;
else if ( ( * V_93 >= 'a' ) && ( * V_93 <= 'f' ) )
V_92 = * V_93 - 'a' + 10 ;
else
{
F_3 ( V_94 , V_95 ) ;
return ( 0 ) ;
}
V_93 ++ ;
V_91 [ V_7 / 2 ] |= V_92 << ( long ) ( ( ! ( V_7 & 1 ) ) * 4 ) ;
}
* V_90 = V_93 ;
return ( 1 ) ;
}
int F_53 ( T_2 * V_22 , char * V_21 , char * V_55 , unsigned char * V_56 ,
long V_18 )
{
T_4 * V_26 ;
int V_27 ;
if ( ( V_26 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_96 , V_29 ) ;
return ( 0 ) ;
}
F_12 ( V_26 , V_22 , V_30 ) ;
V_27 = F_47 ( V_26 , V_21 , V_55 , V_56 , V_18 ) ;
F_14 ( V_26 ) ;
return ( V_27 ) ;
}
int F_47 ( T_4 * V_53 , const char * V_21 , char * V_55 , unsigned char * V_56 ,
long V_18 )
{
int V_97 , V_98 , V_7 , V_8 , V_99 ;
unsigned char * V_1 = NULL ;
T_11 V_65 ;
int V_100 = V_29 ;
F_54 ( & V_65 ) ;
V_97 = strlen ( V_21 ) ;
if ( ( F_55 ( V_53 , L_16 , 11 ) != 11 ) ||
( F_55 ( V_53 , V_21 , V_97 ) != V_97 ) ||
( F_55 ( V_53 , L_17 , 6 ) != 6 ) )
goto V_58;
V_7 = strlen ( V_55 ) ;
if ( V_7 > 0 )
{
if ( ( F_55 ( V_53 , V_55 , V_7 ) != V_7 ) ||
( F_55 ( V_53 , L_8 , 1 ) != 1 ) )
goto V_58;
}
V_1 = F_33 ( V_17 * 8 ) ;
if ( V_1 == NULL )
{
V_100 = V_75 ;
goto V_58;
}
V_7 = V_8 = 0 ;
while ( V_18 > 0 )
{
V_98 = ( int ) ( ( V_18 > ( V_17 * 5 ) ) ? ( V_17 * 5 ) : V_18 ) ;
F_56 ( & V_65 , V_1 , & V_99 , & ( V_56 [ V_8 ] ) , V_98 ) ;
if ( ( V_99 ) && ( F_55 ( V_53 , ( char * ) V_1 , V_99 ) != V_99 ) )
goto V_58;
V_7 += V_99 ;
V_18 -= V_98 ;
V_8 += V_98 ;
}
F_57 ( & V_65 , V_1 , & V_99 ) ;
if ( ( V_99 > 0 ) && ( F_55 ( V_53 , ( char * ) V_1 , V_99 ) != V_99 ) ) goto V_58;
F_41 ( V_1 , V_17 * 8 ) ;
F_26 ( V_1 ) ;
V_1 = NULL ;
if ( ( F_55 ( V_53 , L_18 , 9 ) != 9 ) ||
( F_55 ( V_53 , V_21 , V_97 ) != V_97 ) ||
( F_55 ( V_53 , L_17 , 6 ) != 6 ) )
goto V_58;
return ( V_7 + V_99 ) ;
V_58:
if ( V_1 ) {
F_41 ( V_1 , V_17 * 8 ) ;
F_26 ( V_1 ) ;
}
F_3 ( V_101 , V_100 ) ;
return ( 0 ) ;
}
int F_58 ( T_2 * V_22 , char * * V_21 , char * * V_55 , unsigned char * * V_56 ,
long * V_18 )
{
T_4 * V_26 ;
int V_27 ;
if ( ( V_26 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_102 , V_29 ) ;
return ( 0 ) ;
}
F_12 ( V_26 , V_22 , V_30 ) ;
V_27 = F_22 ( V_26 , V_21 , V_55 , V_56 , V_18 ) ;
F_14 ( V_26 ) ;
return ( V_27 ) ;
}
int F_22 ( T_4 * V_53 , char * * V_21 , char * * V_55 , unsigned char * * V_56 ,
long * V_18 )
{
T_11 V_65 ;
int V_103 = 0 , V_7 , V_104 , V_105 = 0 , V_106 = 0 , V_107 = 0 ;
char V_1 [ 256 ] ;
T_12 * V_108 ;
T_12 * V_109 ;
T_12 * V_110 , * V_111 ;
V_108 = F_59 () ;
V_109 = F_59 () ;
V_110 = F_59 () ;
if ( ( V_108 == NULL ) || ( V_109 == NULL ) || ( V_110 == NULL ) )
{
F_60 ( V_108 ) ;
F_60 ( V_109 ) ;
F_60 ( V_110 ) ;
F_3 ( V_112 , V_75 ) ;
return ( 0 ) ;
}
V_1 [ 254 ] = '\0' ;
for (; ; )
{
V_7 = F_61 ( V_53 , V_1 , 254 ) ;
if ( V_7 <= 0 )
{
F_3 ( V_112 , V_57 ) ;
goto V_58;
}
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
if ( strncmp ( V_1 , L_16 , 11 ) == 0 )
{
V_7 = strlen ( & ( V_1 [ 11 ] ) ) ;
if ( strncmp ( & ( V_1 [ 11 + V_7 - 6 ] ) , L_17 , 6 ) != 0 )
continue;
if ( ! F_62 ( V_108 , V_7 + 9 ) )
{
F_3 ( V_112 , V_75 ) ;
goto V_58;
}
memcpy ( V_108 -> V_56 , & ( V_1 [ 11 ] ) , V_7 - 6 ) ;
V_108 -> V_56 [ V_7 - 6 ] = '\0' ;
break;
}
}
V_106 = 0 ;
if ( ! F_62 ( V_109 , 256 ) )
{ F_3 ( V_112 , V_75 ) ; goto V_58; }
V_109 -> V_56 [ 0 ] = '\0' ;
for (; ; )
{
V_7 = F_61 ( V_53 , V_1 , 254 ) ;
if ( V_7 <= 0 ) break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
if ( V_1 [ 0 ] == '\n' ) break;
if ( ! F_62 ( V_109 , V_106 + V_7 + 9 ) )
{ F_3 ( V_112 , V_75 ) ; goto V_58; }
if ( strncmp ( V_1 , L_18 , 9 ) == 0 )
{
V_107 = 1 ;
break;
}
memcpy ( & ( V_109 -> V_56 [ V_106 ] ) , V_1 , V_7 ) ;
V_109 -> V_56 [ V_106 + V_7 ] = '\0' ;
V_106 += V_7 ;
}
V_105 = 0 ;
if ( ! F_62 ( V_110 , 1024 ) )
{ F_3 ( V_112 , V_75 ) ; goto V_58; }
V_110 -> V_56 [ 0 ] = '\0' ;
if ( ! V_107 )
{
for (; ; )
{
V_7 = F_61 ( V_53 , V_1 , 254 ) ;
if ( V_7 <= 0 ) break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
if ( V_7 != 65 ) V_103 = 1 ;
if ( strncmp ( V_1 , L_18 , 9 ) == 0 )
break;
if ( V_7 > 65 ) break;
if ( ! F_63 ( V_110 , V_7 + V_105 + 9 ) )
{
F_3 ( V_112 , V_75 ) ;
goto V_58;
}
memcpy ( & ( V_110 -> V_56 [ V_105 ] ) , V_1 , V_7 ) ;
V_110 -> V_56 [ V_105 + V_7 ] = '\0' ;
V_105 += V_7 ;
if ( V_103 )
{
V_1 [ 0 ] = '\0' ;
V_7 = F_61 ( V_53 , V_1 , 254 ) ;
if ( V_7 <= 0 ) break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
break;
}
}
}
else
{
V_111 = V_109 ;
V_109 = V_110 ;
V_110 = V_111 ;
V_105 = V_106 ;
}
V_7 = strlen ( V_108 -> V_56 ) ;
if ( ( strncmp ( V_1 , L_18 , 9 ) != 0 ) ||
( strncmp ( V_108 -> V_56 , & ( V_1 [ 9 ] ) , V_7 ) != 0 ) ||
( strncmp ( & ( V_1 [ 9 + V_7 ] ) , L_17 , 6 ) != 0 ) )
{
F_3 ( V_112 , V_113 ) ;
goto V_58;
}
F_64 ( & V_65 ) ;
V_7 = F_65 ( & V_65 ,
( unsigned char * ) V_110 -> V_56 , & V_105 ,
( unsigned char * ) V_110 -> V_56 , V_105 ) ;
if ( V_7 < 0 )
{
F_3 ( V_112 , V_114 ) ;
goto V_58;
}
V_7 = F_66 ( & V_65 , ( unsigned char * ) & ( V_110 -> V_56 [ V_105 ] ) , & V_104 ) ;
if ( V_7 < 0 )
{
F_3 ( V_112 , V_114 ) ;
goto V_58;
}
V_105 += V_104 ;
if ( V_105 == 0 ) goto V_58;
* V_21 = V_108 -> V_56 ;
* V_55 = V_109 -> V_56 ;
* V_56 = ( unsigned char * ) V_110 -> V_56 ;
* V_18 = V_105 ;
F_26 ( V_108 ) ;
F_26 ( V_109 ) ;
F_26 ( V_110 ) ;
return ( 1 ) ;
V_58:
F_60 ( V_108 ) ;
F_60 ( V_109 ) ;
F_60 ( V_110 ) ;
return ( 0 ) ;
}
int F_16 ( const char * V_115 , const char * V_116 )
{
int V_117 = strlen ( V_115 ) ;
int V_118 = strlen ( V_116 ) ;
const char * V_67 ;
if ( V_118 + 1 >= V_117 )
return 0 ;
V_67 = V_115 + V_117 - V_118 ;
if ( strcmp ( V_67 , V_116 ) )
return 0 ;
V_67 -- ;
if ( * V_67 != ' ' )
return 0 ;
return V_67 - V_115 ;
}
