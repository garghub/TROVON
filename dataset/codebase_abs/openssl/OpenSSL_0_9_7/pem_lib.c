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
V_7 = F_5 ( V_1 , V_2 , V_9 , V_3 ) ;
if ( V_7 != 0 )
{
F_3 ( V_5 , V_10 ) ;
memset ( V_1 , 0 , ( unsigned int ) V_2 ) ;
return ( - 1 ) ;
}
V_8 = strlen ( V_1 ) ;
if ( V_8 < V_11 )
{
fprintf ( V_12 , L_2 , V_11 ) ;
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
strcat ( V_1 , L_7 ) ;
strcat ( V_1 , V_13 ) ;
strcat ( V_1 , L_8 ) ;
}
void F_7 ( char * V_1 , const char * type , int V_17 , char * V_13 )
{
static const unsigned char V_18 [ 17 ] = L_9 ;
long V_7 ;
int V_8 ;
strcat ( V_1 , L_10 ) ;
strcat ( V_1 , type ) ;
strcat ( V_1 , L_11 ) ;
V_8 = strlen ( V_1 ) ;
for ( V_7 = 0 ; V_7 < V_17 ; V_7 ++ )
{
V_1 [ V_8 + V_7 * 2 ] = V_18 [ ( V_13 [ V_7 ] >> 4 ) & 0x0f ] ;
V_1 [ V_8 + V_7 * 2 + 1 ] = V_18 [ ( V_13 [ V_7 ] ) & 0x0f ] ;
}
V_1 [ V_8 + V_7 * 2 ] = '\n' ;
V_1 [ V_8 + V_7 * 2 + 1 ] = '\0' ;
}
char * F_8 ( char * (* F_9)() , const char * V_19 , T_1 * V_20 , char * * V_21 ,
T_2 * V_22 , void * V_23 )
{
T_3 * V_24 ;
char * V_25 ;
if ( ( V_24 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_26 , V_27 ) ;
return ( 0 ) ;
}
F_12 ( V_24 , V_20 , V_28 ) ;
V_25 = F_13 ( F_9 , V_19 , V_24 , V_21 , V_22 , V_23 ) ;
F_14 ( V_24 ) ;
return ( V_25 ) ;
}
static int F_15 ( const char * V_29 , const char * V_19 )
{
if ( ! strcmp ( V_29 , V_19 ) ) return 1 ;
if( ! strcmp ( V_29 , V_30 ) &&
! strcmp ( V_19 , V_31 ) ) return 1 ;
if( ! strcmp ( V_29 , V_32 ) &&
! strcmp ( V_19 , V_31 ) ) return 1 ;
if( ! strcmp ( V_29 , V_33 ) &&
! strcmp ( V_19 , V_31 ) ) return 1 ;
if( ! strcmp ( V_29 , V_34 ) &&
! strcmp ( V_19 , V_31 ) ) return 1 ;
if( ! strcmp ( V_29 , V_35 ) &&
! strcmp ( V_19 , V_36 ) ) return 1 ;
if( ! strcmp ( V_29 , V_37 ) &&
! strcmp ( V_19 , V_38 ) ) return 1 ;
if( ! strcmp ( V_29 , V_36 ) &&
! strcmp ( V_19 , V_39 ) ) return 1 ;
if( ! strcmp ( V_29 , V_35 ) &&
! strcmp ( V_19 , V_39 ) ) return 1 ;
if( ! strcmp ( V_29 , V_36 ) &&
! strcmp ( V_19 , V_40 ) ) return 1 ;
return 0 ;
}
int F_16 ( unsigned char * * V_41 , long * V_42 , char * * V_43 , const char * V_19 , T_3 * V_44 ,
T_2 * V_22 , void * V_23 )
{
T_4 V_45 ;
char * V_29 = NULL , * V_46 = NULL ;
unsigned char * V_47 = NULL ;
long V_17 ;
int V_25 = 0 ;
for (; ; )
{
if ( ! F_17 ( V_44 , & V_29 , & V_46 , & V_47 , & V_17 ) ) {
if( F_18 ( F_19 () ) ==
V_48 )
F_20 ( 2 , L_12 , V_19 ) ;
return 0 ;
}
if( F_15 ( V_29 , V_19 ) ) break;
F_21 ( V_29 ) ;
F_21 ( V_46 ) ;
F_21 ( V_47 ) ;
}
if ( ! F_22 ( V_46 , & V_45 ) ) goto V_49;
if ( ! F_23 ( & V_45 , V_47 , & V_17 , V_22 , V_23 ) ) goto V_49;
* V_41 = V_47 ;
* V_42 = V_17 ;
if ( V_43 )
* V_43 = V_29 ;
V_25 = 1 ;
V_49:
if ( ! V_25 || ! V_43 ) F_21 ( V_29 ) ;
F_21 ( V_46 ) ;
if ( ! V_25 ) F_21 ( V_47 ) ;
return V_25 ;
}
int F_24 ( int (* F_25)() , const char * V_19 , T_1 * V_20 , char * V_21 ,
const T_5 * V_50 , unsigned char * V_51 , int V_52 ,
T_2 * V_53 , void * V_23 )
{
T_3 * V_24 ;
int V_25 ;
if ( ( V_24 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_54 , V_27 ) ;
return ( 0 ) ;
}
F_12 ( V_24 , V_20 , V_28 ) ;
V_25 = F_26 ( F_25 , V_19 , V_24 , V_21 , V_50 , V_51 , V_52 , V_53 , V_23 ) ;
F_14 ( V_24 ) ;
return ( V_25 ) ;
}
int F_26 ( int (* F_25)() , const char * V_19 , T_3 * V_44 , char * V_21 ,
const T_5 * V_50 , unsigned char * V_51 , int V_52 ,
T_2 * V_53 , void * V_23 )
{
T_6 V_55 ;
int V_56 = 0 , V_7 , V_8 , V_25 = 0 ;
unsigned char * V_57 , * V_47 = NULL ;
const char * V_58 = NULL ;
char V_1 [ V_59 ] ;
unsigned char V_4 [ V_60 ] ;
unsigned char V_61 [ V_62 ] ;
if ( V_50 != NULL )
{
V_58 = F_27 ( F_28 ( V_50 ) ) ;
if ( V_58 == NULL )
{
F_3 ( V_63 , V_64 ) ;
goto V_49;
}
}
if ( ( V_56 = F_25 ( V_21 , NULL ) ) < 0 )
{
F_3 ( V_63 , V_65 ) ;
V_56 = 0 ;
goto V_49;
}
V_47 = ( unsigned char * ) F_29 ( ( unsigned int ) V_56 + 20 ) ;
if ( V_47 == NULL )
{
F_3 ( V_63 , V_65 ) ;
goto V_49;
}
V_57 = V_47 ;
V_7 = F_25 ( V_21 , & V_57 ) ;
if ( V_50 != NULL )
{
if ( V_51 == NULL )
{
if ( V_53 == NULL )
V_52 = F_1 ( V_1 , V_59 , 1 , V_23 ) ;
else
V_52 = (* V_53)( V_1 , V_59 , 1 , V_23 ) ;
if ( V_52 <= 0 )
{
F_3 ( V_63 , V_66 ) ;
goto V_49;
}
#ifdef F_30
F_31 ( V_1 , V_1 , V_52 ) ;
#endif
V_51 = ( unsigned char * ) V_1 ;
}
F_32 ( V_47 , V_7 , 0 ) ;
F_33 ( V_50 -> V_67 <= sizeof V_61 ) ;
if ( F_34 ( V_61 , V_50 -> V_67 ) < 0 )
goto V_49;
F_35 ( V_50 , F_36 () , V_61 , V_51 , V_52 , 1 , V_4 , NULL ) ;
if ( V_51 == ( unsigned char * ) V_1 ) F_37 ( V_1 , V_59 ) ;
F_33 ( strlen ( V_58 ) + 23 + 2 * V_50 -> V_67 + 13 <= sizeof V_1 ) ;
V_1 [ 0 ] = '\0' ;
F_6 ( V_1 , V_14 ) ;
F_7 ( V_1 , V_58 , V_50 -> V_67 , ( char * ) V_61 ) ;
F_38 ( & V_55 ) ;
F_39 ( & V_55 , V_50 , NULL , V_4 , V_61 ) ;
F_40 ( & V_55 , V_47 , & V_8 , V_47 , V_7 ) ;
F_41 ( & V_55 , & ( V_47 [ V_8 ] ) , & V_7 ) ;
F_42 ( & V_55 ) ;
V_7 += V_8 ;
V_25 = 1 ;
}
else
{
V_25 = 1 ;
V_1 [ 0 ] = '\0' ;
}
V_7 = F_43 ( V_44 , V_19 , V_1 , V_47 , V_7 ) ;
if ( V_7 <= 0 ) V_25 = 0 ;
V_49:
F_37 ( V_4 , sizeof( V_4 ) ) ;
F_37 ( V_61 , sizeof( V_61 ) ) ;
F_37 ( ( char * ) & V_55 , sizeof( V_55 ) ) ;
F_37 ( V_1 , V_59 ) ;
if ( V_47 != NULL )
{
F_37 ( V_47 , ( unsigned int ) V_56 ) ;
F_21 ( V_47 ) ;
}
return ( V_25 ) ;
}
int F_23 ( T_4 * V_45 , unsigned char * V_47 , long * V_42 ,
T_2 * V_53 , void * V_23 )
{
int V_7 , V_8 , V_68 , V_52 ;
long V_17 ;
T_6 V_55 ;
unsigned char V_4 [ V_60 ] ;
char V_1 [ V_59 ] ;
V_17 = * V_42 ;
if ( V_45 -> V_45 == NULL ) return ( 1 ) ;
if ( V_53 == NULL )
V_52 = F_1 ( V_1 , V_59 , 0 , V_23 ) ;
else
V_52 = V_53 ( V_1 , V_59 , 0 , V_23 ) ;
if ( V_52 <= 0 )
{
F_3 ( V_69 , V_70 ) ;
return ( 0 ) ;
}
#ifdef F_30
F_31 ( V_1 , V_1 , V_52 ) ;
#endif
F_35 ( V_45 -> V_45 , F_36 () , & ( V_45 -> V_61 [ 0 ] ) ,
( unsigned char * ) V_1 , V_52 , 1 , V_4 , NULL ) ;
V_8 = ( int ) V_17 ;
F_38 ( & V_55 ) ;
F_44 ( & V_55 , V_45 -> V_45 , NULL , V_4 , & ( V_45 -> V_61 [ 0 ] ) ) ;
F_45 ( & V_55 , V_47 , & V_7 , V_47 , V_8 ) ;
V_68 = F_46 ( & V_55 , & ( V_47 [ V_7 ] ) , & V_8 ) ;
F_42 ( & V_55 ) ;
F_37 ( ( char * ) V_1 , sizeof( V_1 ) ) ;
F_37 ( ( char * ) V_4 , sizeof( V_4 ) ) ;
V_8 += V_7 ;
if ( ! V_68 )
{
F_3 ( V_69 , V_71 ) ;
return ( 0 ) ;
}
* V_42 = V_8 ;
return ( 1 ) ;
}
int F_22 ( char * V_46 , T_4 * V_45 )
{
int V_68 ;
const T_5 * V_50 = NULL ;
char * V_57 , V_72 ;
V_45 -> V_45 = NULL ;
if ( ( V_46 == NULL ) || ( * V_46 == '\0' ) || ( * V_46 == '\n' ) )
return ( 1 ) ;
if ( strncmp ( V_46 , L_13 , 11 ) != 0 )
{ F_3 ( V_73 , V_74 ) ; return ( 0 ) ; }
V_46 += 11 ;
if ( * V_46 != '4' ) return ( 0 ) ; V_46 ++ ;
if ( * V_46 != ',' ) return ( 0 ) ; V_46 ++ ;
if ( strncmp ( V_46 , L_3 , 9 ) != 0 )
{ F_3 ( V_73 , V_75 ) ; return ( 0 ) ; }
for (; ( * V_46 != '\n' ) && ( * V_46 != '\0' ) ; V_46 ++ )
;
if ( * V_46 == '\0' )
{ F_3 ( V_73 , V_76 ) ; return ( 0 ) ; }
V_46 ++ ;
if ( strncmp ( V_46 , L_10 , 10 ) != 0 )
{ F_3 ( V_73 , V_77 ) ; return ( 0 ) ; }
V_46 += 10 ;
V_57 = V_46 ;
for (; ; )
{
V_72 = * V_46 ;
#ifndef F_30
if ( ! ( ( ( V_72 >= 'A' ) && ( V_72 <= 'Z' ) ) || ( V_72 == '-' ) ||
( ( V_72 >= '0' ) && ( V_72 <= '9' ) ) ) )
break;
#else
if ( ! ( isupper ( V_72 ) || ( V_72 == '-' ) ||
isdigit ( V_72 ) ) )
break;
#endif
V_46 ++ ;
}
* V_46 = '\0' ;
V_68 = F_47 ( V_57 ) ;
V_45 -> V_45 = V_50 = F_48 ( V_57 ) ;
* V_46 = V_72 ;
V_46 ++ ;
if ( V_50 == NULL )
{
F_3 ( V_73 , V_78 ) ;
return ( 0 ) ;
}
if ( ! F_49 ( ( unsigned char * * ) & V_46 , & ( V_45 -> V_61 [ 0 ] ) , V_50 -> V_67 ) ) return ( 0 ) ;
return ( 1 ) ;
}
static int F_49 ( unsigned char * * V_79 , unsigned char * V_80 , int V_2 )
{
int V_81 , V_7 ;
unsigned char * V_82 ;
V_82 = * V_79 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) V_80 [ V_7 ] = 0 ;
V_2 *= 2 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
{
if ( ( * V_82 >= '0' ) && ( * V_82 <= '9' ) )
V_81 = * V_82 - '0' ;
else if ( ( * V_82 >= 'A' ) && ( * V_82 <= 'F' ) )
V_81 = * V_82 - 'A' + 10 ;
else if ( ( * V_82 >= 'a' ) && ( * V_82 <= 'f' ) )
V_81 = * V_82 - 'a' + 10 ;
else
{
F_3 ( V_83 , V_84 ) ;
return ( 0 ) ;
}
V_82 ++ ;
V_80 [ V_7 / 2 ] |= V_81 << ( long ) ( ( ! ( V_7 & 1 ) ) * 4 ) ;
}
* V_79 = V_82 ;
return ( 1 ) ;
}
int F_50 ( T_1 * V_20 , char * V_19 , char * V_46 , unsigned char * V_47 ,
long V_17 )
{
T_3 * V_24 ;
int V_25 ;
if ( ( V_24 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_85 , V_27 ) ;
return ( 0 ) ;
}
F_12 ( V_24 , V_20 , V_28 ) ;
V_25 = F_43 ( V_24 , V_19 , V_46 , V_47 , V_17 ) ;
F_14 ( V_24 ) ;
return ( V_25 ) ;
}
int F_43 ( T_3 * V_44 , const char * V_19 , char * V_46 , unsigned char * V_47 ,
long V_17 )
{
int V_86 , V_87 , V_7 , V_8 , V_88 ;
unsigned char * V_1 ;
T_7 V_55 ;
int V_89 = V_27 ;
F_51 ( & V_55 ) ;
V_86 = strlen ( V_19 ) ;
if ( ( F_52 ( V_44 , L_14 , 11 ) != 11 ) ||
( F_52 ( V_44 , V_19 , V_86 ) != V_86 ) ||
( F_52 ( V_44 , L_15 , 6 ) != 6 ) )
goto V_49;
V_7 = strlen ( V_46 ) ;
if ( V_7 > 0 )
{
if ( ( F_52 ( V_44 , V_46 , V_7 ) != V_7 ) ||
( F_52 ( V_44 , L_8 , 1 ) != 1 ) )
goto V_49;
}
V_1 = ( unsigned char * ) F_29 ( V_59 * 8 ) ;
if ( V_1 == NULL )
{
V_89 = V_65 ;
goto V_49;
}
V_7 = V_8 = 0 ;
while ( V_17 > 0 )
{
V_87 = ( int ) ( ( V_17 > ( V_59 * 5 ) ) ? ( V_59 * 5 ) : V_17 ) ;
F_53 ( & V_55 , V_1 , & V_88 , & ( V_47 [ V_8 ] ) , V_87 ) ;
if ( ( V_88 ) && ( F_52 ( V_44 , ( char * ) V_1 , V_88 ) != V_88 ) )
goto V_49;
V_7 += V_88 ;
V_17 -= V_87 ;
V_8 += V_87 ;
}
F_54 ( & V_55 , V_1 , & V_88 ) ;
if ( ( V_88 > 0 ) && ( F_52 ( V_44 , ( char * ) V_1 , V_88 ) != V_88 ) ) goto V_49;
F_21 ( V_1 ) ;
if ( ( F_52 ( V_44 , L_16 , 9 ) != 9 ) ||
( F_52 ( V_44 , V_19 , V_86 ) != V_86 ) ||
( F_52 ( V_44 , L_15 , 6 ) != 6 ) )
goto V_49;
return ( V_7 + V_88 ) ;
V_49:
F_3 ( V_90 , V_89 ) ;
return ( 0 ) ;
}
int F_55 ( T_1 * V_20 , char * * V_19 , char * * V_46 , unsigned char * * V_47 ,
long * V_17 )
{
T_3 * V_24 ;
int V_25 ;
if ( ( V_24 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_91 , V_27 ) ;
return ( 0 ) ;
}
F_12 ( V_24 , V_20 , V_28 ) ;
V_25 = F_17 ( V_24 , V_19 , V_46 , V_47 , V_17 ) ;
F_14 ( V_24 ) ;
return ( V_25 ) ;
}
int F_17 ( T_3 * V_44 , char * * V_19 , char * * V_46 , unsigned char * * V_47 ,
long * V_17 )
{
T_7 V_55 ;
int V_92 = 0 , V_7 , V_93 , V_94 = 0 , V_95 = 0 , V_96 = 0 ;
char V_1 [ 256 ] ;
T_8 * V_97 ;
T_8 * V_98 ;
T_8 * V_99 , * V_100 ;
V_97 = F_56 () ;
V_98 = F_56 () ;
V_99 = F_56 () ;
if ( ( V_97 == NULL ) || ( V_98 == NULL ) || ( V_99 == NULL ) )
{
F_3 ( V_101 , V_65 ) ;
return ( 0 ) ;
}
V_1 [ 254 ] = '\0' ;
for (; ; )
{
V_7 = F_57 ( V_44 , V_1 , 254 ) ;
if ( V_7 <= 0 )
{
F_3 ( V_101 , V_48 ) ;
goto V_49;
}
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
if ( strncmp ( V_1 , L_14 , 11 ) == 0 )
{
V_7 = strlen ( & ( V_1 [ 11 ] ) ) ;
if ( strncmp ( & ( V_1 [ 11 + V_7 - 6 ] ) , L_15 , 6 ) != 0 )
continue;
if ( ! F_58 ( V_97 , V_7 + 9 ) )
{
F_3 ( V_101 , V_65 ) ;
goto V_49;
}
memcpy ( V_97 -> V_47 , & ( V_1 [ 11 ] ) , V_7 - 6 ) ;
V_97 -> V_47 [ V_7 - 6 ] = '\0' ;
break;
}
}
V_95 = 0 ;
if ( ! F_58 ( V_98 , 256 ) )
{ F_3 ( V_101 , V_65 ) ; goto V_49; }
V_98 -> V_47 [ 0 ] = '\0' ;
for (; ; )
{
V_7 = F_57 ( V_44 , V_1 , 254 ) ;
if ( V_7 <= 0 ) break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
if ( V_1 [ 0 ] == '\n' ) break;
if ( ! F_58 ( V_98 , V_95 + V_7 + 9 ) )
{ F_3 ( V_101 , V_65 ) ; goto V_49; }
if ( strncmp ( V_1 , L_16 , 9 ) == 0 )
{
V_96 = 1 ;
break;
}
memcpy ( & ( V_98 -> V_47 [ V_95 ] ) , V_1 , V_7 ) ;
V_98 -> V_47 [ V_95 + V_7 ] = '\0' ;
V_95 += V_7 ;
}
V_94 = 0 ;
if ( ! F_58 ( V_99 , 1024 ) )
{ F_3 ( V_101 , V_65 ) ; goto V_49; }
V_99 -> V_47 [ 0 ] = '\0' ;
if ( ! V_96 )
{
for (; ; )
{
V_7 = F_57 ( V_44 , V_1 , 254 ) ;
if ( V_7 <= 0 ) break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
if ( V_7 != 65 ) V_92 = 1 ;
if ( strncmp ( V_1 , L_16 , 9 ) == 0 )
break;
if ( V_7 > 65 ) break;
if ( ! F_59 ( V_99 , V_7 + V_94 + 9 ) )
{
F_3 ( V_101 , V_65 ) ;
goto V_49;
}
memcpy ( & ( V_99 -> V_47 [ V_94 ] ) , V_1 , V_7 ) ;
V_99 -> V_47 [ V_94 + V_7 ] = '\0' ;
V_94 += V_7 ;
if ( V_92 )
{
V_1 [ 0 ] = '\0' ;
V_7 = F_57 ( V_44 , V_1 , 254 ) ;
if ( V_7 <= 0 ) break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
break;
}
}
}
else
{
V_100 = V_98 ;
V_98 = V_99 ;
V_99 = V_100 ;
V_94 = V_95 ;
}
V_7 = strlen ( V_97 -> V_47 ) ;
if ( ( strncmp ( V_1 , L_16 , 9 ) != 0 ) ||
( strncmp ( V_97 -> V_47 , & ( V_1 [ 9 ] ) , V_7 ) != 0 ) ||
( strncmp ( & ( V_1 [ 9 + V_7 ] ) , L_15 , 6 ) != 0 ) )
{
F_3 ( V_101 , V_102 ) ;
goto V_49;
}
F_60 ( & V_55 ) ;
V_7 = F_61 ( & V_55 ,
( unsigned char * ) V_99 -> V_47 , & V_94 ,
( unsigned char * ) V_99 -> V_47 , V_94 ) ;
if ( V_7 < 0 )
{
F_3 ( V_101 , V_103 ) ;
goto V_49;
}
V_7 = F_62 ( & V_55 , ( unsigned char * ) & ( V_99 -> V_47 [ V_94 ] ) , & V_93 ) ;
if ( V_7 < 0 )
{
F_3 ( V_101 , V_103 ) ;
goto V_49;
}
V_94 += V_93 ;
if ( V_94 == 0 ) goto V_49;
* V_19 = V_97 -> V_47 ;
* V_46 = V_98 -> V_47 ;
* V_47 = ( unsigned char * ) V_99 -> V_47 ;
* V_17 = V_94 ;
F_21 ( V_97 ) ;
F_21 ( V_98 ) ;
F_21 ( V_99 ) ;
return ( 1 ) ;
V_49:
F_63 ( V_97 ) ;
F_63 ( V_98 ) ;
F_63 ( V_99 ) ;
return ( 0 ) ;
}
