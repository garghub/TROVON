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
if( ! strcmp ( V_31 , V_32 ) &&
! strcmp ( V_21 , V_33 ) ) return 1 ;
if( ! strcmp ( V_31 , V_34 ) &&
! strcmp ( V_21 , V_33 ) ) return 1 ;
if( ! strcmp ( V_31 , V_35 ) &&
! strcmp ( V_21 , V_33 ) ) return 1 ;
if( ! strcmp ( V_31 , V_36 ) &&
! strcmp ( V_21 , V_33 ) ) return 1 ;
if( ! strcmp ( V_31 , V_37 ) &&
! strcmp ( V_21 , V_33 ) ) return 1 ;
if( ! strcmp ( V_31 , V_38 ) &&
! strcmp ( V_21 , V_39 ) ) return 1 ;
if( ! strcmp ( V_31 , V_40 ) &&
! strcmp ( V_21 , V_41 ) ) return 1 ;
if( ! strcmp ( V_31 , V_39 ) &&
! strcmp ( V_21 , V_42 ) ) return 1 ;
if( ! strcmp ( V_31 , V_38 ) &&
! strcmp ( V_21 , V_42 ) ) return 1 ;
if( ! strcmp ( V_31 , V_39 ) &&
! strcmp ( V_21 , V_43 ) ) return 1 ;
return 0 ;
}
int F_16 ( unsigned char * * V_44 , long * V_45 , char * * V_46 , const char * V_21 , T_4 * V_47 ,
T_3 * V_24 , void * V_25 )
{
T_5 V_48 ;
char * V_31 = NULL , * V_49 = NULL ;
unsigned char * V_50 = NULL ;
long V_18 ;
int V_27 = 0 ;
for (; ; )
{
if ( ! F_17 ( V_47 , & V_31 , & V_49 , & V_50 , & V_18 ) ) {
if( F_18 ( F_19 () ) ==
V_51 )
F_20 ( 2 , L_12 , V_21 ) ;
return 0 ;
}
if( F_15 ( V_31 , V_21 ) ) break;
F_21 ( V_31 ) ;
F_21 ( V_49 ) ;
F_21 ( V_50 ) ;
}
if ( ! F_22 ( V_49 , & V_48 ) ) goto V_52;
if ( ! F_23 ( & V_48 , V_50 , & V_18 , V_24 , V_25 ) ) goto V_52;
* V_44 = V_50 ;
* V_45 = V_18 ;
if ( V_46 )
* V_46 = V_31 ;
V_27 = 1 ;
V_52:
if ( ! V_27 || ! V_46 ) F_21 ( V_31 ) ;
F_21 ( V_49 ) ;
if ( ! V_27 ) F_21 ( V_50 ) ;
return V_27 ;
}
int F_24 ( T_6 * V_53 , const char * V_21 , T_2 * V_22 ,
char * V_23 , const T_7 * V_54 , unsigned char * V_55 ,
int V_56 , T_3 * V_57 , void * V_25 )
{
T_4 * V_26 ;
int V_27 ;
if ( ( V_26 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_58 , V_29 ) ;
return ( 0 ) ;
}
F_12 ( V_26 , V_22 , V_30 ) ;
V_27 = F_25 ( V_53 , V_21 , V_26 , V_23 , V_54 , V_55 , V_56 , V_57 , V_25 ) ;
F_14 ( V_26 ) ;
return ( V_27 ) ;
}
int F_25 ( T_6 * V_53 , const char * V_21 , T_4 * V_47 ,
char * V_23 , const T_7 * V_54 , unsigned char * V_55 ,
int V_56 , T_3 * V_57 , void * V_25 )
{
T_8 V_59 ;
int V_60 = 0 , V_7 , V_8 , V_27 = 0 ;
unsigned char * V_61 , * V_50 = NULL ;
const char * V_62 = NULL ;
char V_1 [ V_17 ] ;
unsigned char V_4 [ V_63 ] ;
unsigned char V_64 [ V_65 ] ;
if ( V_54 != NULL )
{
V_62 = F_26 ( F_27 ( V_54 ) ) ;
if ( V_62 == NULL )
{
F_3 ( V_66 , V_67 ) ;
goto V_52;
}
}
if ( ( V_60 = V_53 ( V_23 , NULL ) ) < 0 )
{
F_3 ( V_66 , V_68 ) ;
V_60 = 0 ;
goto V_52;
}
V_50 = ( unsigned char * ) F_28 ( ( unsigned int ) V_60 + 20 ) ;
if ( V_50 == NULL )
{
F_3 ( V_66 , V_69 ) ;
goto V_52;
}
V_61 = V_50 ;
V_7 = V_53 ( V_23 , & V_61 ) ;
if ( V_54 != NULL )
{
if ( V_55 == NULL )
{
if ( V_57 == NULL )
V_56 = F_1 ( V_1 , V_17 , 1 , V_25 ) ;
else
V_56 = (* V_57)( V_1 , V_17 , 1 , V_25 ) ;
if ( V_56 <= 0 )
{
F_3 ( V_66 , V_70 ) ;
goto V_52;
}
#ifdef F_29
F_30 ( V_1 , V_1 , V_56 ) ;
#endif
V_55 = ( unsigned char * ) V_1 ;
}
F_31 ( V_50 , V_7 , 0 ) ;
F_32 ( V_54 -> V_71 <= ( int ) sizeof( V_64 ) ) ;
if ( F_33 ( V_64 , V_54 -> V_71 ) < 0 )
goto V_52;
F_34 ( V_54 , F_35 () , V_64 , V_55 , V_56 , 1 , V_4 , NULL ) ;
if ( V_55 == ( unsigned char * ) V_1 ) F_36 ( V_1 , V_17 ) ;
F_32 ( strlen ( V_62 ) + 23 + 2 * V_54 -> V_71 + 13 <= sizeof V_1 ) ;
V_1 [ 0 ] = '\0' ;
F_6 ( V_1 , V_14 ) ;
F_8 ( V_1 , V_62 , V_54 -> V_71 , ( char * ) V_64 ) ;
F_37 ( & V_59 ) ;
F_38 ( & V_59 , V_54 , NULL , V_4 , V_64 ) ;
F_39 ( & V_59 , V_50 , & V_8 , V_50 , V_7 ) ;
F_40 ( & V_59 , & ( V_50 [ V_8 ] ) , & V_7 ) ;
F_41 ( & V_59 ) ;
V_7 += V_8 ;
V_27 = 1 ;
}
else
{
V_27 = 1 ;
V_1 [ 0 ] = '\0' ;
}
V_7 = F_42 ( V_47 , V_21 , V_1 , V_50 , V_7 ) ;
if ( V_7 <= 0 ) V_27 = 0 ;
V_52:
F_36 ( V_4 , sizeof( V_4 ) ) ;
F_36 ( V_64 , sizeof( V_64 ) ) ;
F_36 ( ( char * ) & V_59 , sizeof( V_59 ) ) ;
F_36 ( V_1 , V_17 ) ;
if ( V_50 != NULL )
{
F_36 ( V_50 , ( unsigned int ) V_60 ) ;
F_21 ( V_50 ) ;
}
return ( V_27 ) ;
}
int F_23 ( T_5 * V_48 , unsigned char * V_50 , long * V_45 ,
T_3 * V_57 , void * V_25 )
{
int V_7 , V_8 , V_72 , V_56 ;
long V_18 ;
T_8 V_59 ;
unsigned char V_4 [ V_63 ] ;
char V_1 [ V_17 ] ;
V_18 = * V_45 ;
if ( V_48 -> V_48 == NULL ) return ( 1 ) ;
if ( V_57 == NULL )
V_56 = F_1 ( V_1 , V_17 , 0 , V_25 ) ;
else
V_56 = V_57 ( V_1 , V_17 , 0 , V_25 ) ;
if ( V_56 <= 0 )
{
F_3 ( V_73 , V_74 ) ;
return ( 0 ) ;
}
#ifdef F_29
F_30 ( V_1 , V_1 , V_56 ) ;
#endif
F_34 ( V_48 -> V_48 , F_35 () , & ( V_48 -> V_64 [ 0 ] ) ,
( unsigned char * ) V_1 , V_56 , 1 , V_4 , NULL ) ;
V_8 = ( int ) V_18 ;
F_37 ( & V_59 ) ;
F_43 ( & V_59 , V_48 -> V_48 , NULL , V_4 , & ( V_48 -> V_64 [ 0 ] ) ) ;
F_44 ( & V_59 , V_50 , & V_7 , V_50 , V_8 ) ;
V_72 = F_45 ( & V_59 , & ( V_50 [ V_7 ] ) , & V_8 ) ;
F_41 ( & V_59 ) ;
F_36 ( ( char * ) V_1 , sizeof( V_1 ) ) ;
F_36 ( ( char * ) V_4 , sizeof( V_4 ) ) ;
V_8 += V_7 ;
if ( ! V_72 )
{
F_3 ( V_73 , V_75 ) ;
return ( 0 ) ;
}
* V_45 = V_8 ;
return ( 1 ) ;
}
int F_22 ( char * V_49 , T_5 * V_48 )
{
int V_72 ;
const T_7 * V_54 = NULL ;
char * V_61 , V_76 ;
char * * V_77 = & V_49 ;
V_48 -> V_48 = NULL ;
if ( ( V_49 == NULL ) || ( * V_49 == '\0' ) || ( * V_49 == '\n' ) )
return ( 1 ) ;
if ( strncmp ( V_49 , L_13 , 11 ) != 0 )
{ F_3 ( V_78 , V_79 ) ; return ( 0 ) ; }
V_49 += 11 ;
if ( * V_49 != '4' ) return ( 0 ) ; V_49 ++ ;
if ( * V_49 != ',' ) return ( 0 ) ; V_49 ++ ;
if ( strncmp ( V_49 , L_3 , 9 ) != 0 )
{ F_3 ( V_78 , V_80 ) ; return ( 0 ) ; }
for (; ( * V_49 != '\n' ) && ( * V_49 != '\0' ) ; V_49 ++ )
;
if ( * V_49 == '\0' )
{ F_3 ( V_78 , V_81 ) ; return ( 0 ) ; }
V_49 ++ ;
if ( strncmp ( V_49 , L_10 , 10 ) != 0 )
{ F_3 ( V_78 , V_82 ) ; return ( 0 ) ; }
V_49 += 10 ;
V_61 = V_49 ;
for (; ; )
{
V_76 = * V_49 ;
#ifndef F_29
if ( ! ( ( ( V_76 >= 'A' ) && ( V_76 <= 'Z' ) ) || ( V_76 == '-' ) ||
( ( V_76 >= '0' ) && ( V_76 <= '9' ) ) ) )
break;
#else
if ( ! ( isupper ( V_76 ) || ( V_76 == '-' ) ||
isdigit ( V_76 ) ) )
break;
#endif
V_49 ++ ;
}
* V_49 = '\0' ;
V_72 = F_46 ( V_61 ) ;
V_48 -> V_48 = V_54 = F_47 ( V_61 ) ;
* V_49 = V_76 ;
V_49 ++ ;
if ( V_54 == NULL )
{
F_3 ( V_78 , V_83 ) ;
return ( 0 ) ;
}
if ( ! F_48 ( V_77 , & ( V_48 -> V_64 [ 0 ] ) , V_54 -> V_71 ) )
return ( 0 ) ;
return ( 1 ) ;
}
static int F_48 ( char * * V_84 , unsigned char * V_85 , int V_2 )
{
int V_86 , V_7 ;
char * V_87 ;
V_87 = * V_84 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ ) V_85 [ V_7 ] = 0 ;
V_2 *= 2 ;
for ( V_7 = 0 ; V_7 < V_2 ; V_7 ++ )
{
if ( ( * V_87 >= '0' ) && ( * V_87 <= '9' ) )
V_86 = * V_87 - '0' ;
else if ( ( * V_87 >= 'A' ) && ( * V_87 <= 'F' ) )
V_86 = * V_87 - 'A' + 10 ;
else if ( ( * V_87 >= 'a' ) && ( * V_87 <= 'f' ) )
V_86 = * V_87 - 'a' + 10 ;
else
{
F_3 ( V_88 , V_89 ) ;
return ( 0 ) ;
}
V_87 ++ ;
V_85 [ V_7 / 2 ] |= V_86 << ( long ) ( ( ! ( V_7 & 1 ) ) * 4 ) ;
}
* V_84 = V_87 ;
return ( 1 ) ;
}
int F_49 ( T_2 * V_22 , char * V_21 , char * V_49 , unsigned char * V_50 ,
long V_18 )
{
T_4 * V_26 ;
int V_27 ;
if ( ( V_26 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_90 , V_29 ) ;
return ( 0 ) ;
}
F_12 ( V_26 , V_22 , V_30 ) ;
V_27 = F_42 ( V_26 , V_21 , V_49 , V_50 , V_18 ) ;
F_14 ( V_26 ) ;
return ( V_27 ) ;
}
int F_42 ( T_4 * V_47 , const char * V_21 , char * V_49 , unsigned char * V_50 ,
long V_18 )
{
int V_91 , V_92 , V_7 , V_8 , V_93 ;
unsigned char * V_1 = NULL ;
T_9 V_59 ;
int V_94 = V_29 ;
F_50 ( & V_59 ) ;
V_91 = strlen ( V_21 ) ;
if ( ( F_51 ( V_47 , L_14 , 11 ) != 11 ) ||
( F_51 ( V_47 , V_21 , V_91 ) != V_91 ) ||
( F_51 ( V_47 , L_15 , 6 ) != 6 ) )
goto V_52;
V_7 = strlen ( V_49 ) ;
if ( V_7 > 0 )
{
if ( ( F_51 ( V_47 , V_49 , V_7 ) != V_7 ) ||
( F_51 ( V_47 , L_8 , 1 ) != 1 ) )
goto V_52;
}
V_1 = F_28 ( V_17 * 8 ) ;
if ( V_1 == NULL )
{
V_94 = V_69 ;
goto V_52;
}
V_7 = V_8 = 0 ;
while ( V_18 > 0 )
{
V_92 = ( int ) ( ( V_18 > ( V_17 * 5 ) ) ? ( V_17 * 5 ) : V_18 ) ;
F_52 ( & V_59 , V_1 , & V_93 , & ( V_50 [ V_8 ] ) , V_92 ) ;
if ( ( V_93 ) && ( F_51 ( V_47 , ( char * ) V_1 , V_93 ) != V_93 ) )
goto V_52;
V_7 += V_93 ;
V_18 -= V_92 ;
V_8 += V_92 ;
}
F_53 ( & V_59 , V_1 , & V_93 ) ;
if ( ( V_93 > 0 ) && ( F_51 ( V_47 , ( char * ) V_1 , V_93 ) != V_93 ) ) goto V_52;
F_21 ( V_1 ) ;
V_1 = NULL ;
if ( ( F_51 ( V_47 , L_16 , 9 ) != 9 ) ||
( F_51 ( V_47 , V_21 , V_91 ) != V_91 ) ||
( F_51 ( V_47 , L_15 , 6 ) != 6 ) )
goto V_52;
return ( V_7 + V_93 ) ;
V_52:
if ( V_1 )
F_21 ( V_1 ) ;
F_3 ( V_95 , V_94 ) ;
return ( 0 ) ;
}
int F_54 ( T_2 * V_22 , char * * V_21 , char * * V_49 , unsigned char * * V_50 ,
long * V_18 )
{
T_4 * V_26 ;
int V_27 ;
if ( ( V_26 = F_10 ( F_11 () ) ) == NULL )
{
F_3 ( V_96 , V_29 ) ;
return ( 0 ) ;
}
F_12 ( V_26 , V_22 , V_30 ) ;
V_27 = F_17 ( V_26 , V_21 , V_49 , V_50 , V_18 ) ;
F_14 ( V_26 ) ;
return ( V_27 ) ;
}
int F_17 ( T_4 * V_47 , char * * V_21 , char * * V_49 , unsigned char * * V_50 ,
long * V_18 )
{
T_9 V_59 ;
int V_97 = 0 , V_7 , V_98 , V_99 = 0 , V_100 = 0 , V_101 = 0 ;
char V_1 [ 256 ] ;
T_10 * V_102 ;
T_10 * V_103 ;
T_10 * V_104 , * V_105 ;
V_102 = F_55 () ;
V_103 = F_55 () ;
V_104 = F_55 () ;
if ( ( V_102 == NULL ) || ( V_103 == NULL ) || ( V_104 == NULL ) )
{
F_56 ( V_102 ) ;
F_56 ( V_103 ) ;
F_56 ( V_104 ) ;
F_3 ( V_106 , V_69 ) ;
return ( 0 ) ;
}
V_1 [ 254 ] = '\0' ;
for (; ; )
{
V_7 = F_57 ( V_47 , V_1 , 254 ) ;
if ( V_7 <= 0 )
{
F_3 ( V_106 , V_51 ) ;
goto V_52;
}
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
if ( strncmp ( V_1 , L_14 , 11 ) == 0 )
{
V_7 = strlen ( & ( V_1 [ 11 ] ) ) ;
if ( strncmp ( & ( V_1 [ 11 + V_7 - 6 ] ) , L_15 , 6 ) != 0 )
continue;
if ( ! F_58 ( V_102 , V_7 + 9 ) )
{
F_3 ( V_106 , V_69 ) ;
goto V_52;
}
memcpy ( V_102 -> V_50 , & ( V_1 [ 11 ] ) , V_7 - 6 ) ;
V_102 -> V_50 [ V_7 - 6 ] = '\0' ;
break;
}
}
V_100 = 0 ;
if ( ! F_58 ( V_103 , 256 ) )
{ F_3 ( V_106 , V_69 ) ; goto V_52; }
V_103 -> V_50 [ 0 ] = '\0' ;
for (; ; )
{
V_7 = F_57 ( V_47 , V_1 , 254 ) ;
if ( V_7 <= 0 ) break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
if ( V_1 [ 0 ] == '\n' ) break;
if ( ! F_58 ( V_103 , V_100 + V_7 + 9 ) )
{ F_3 ( V_106 , V_69 ) ; goto V_52; }
if ( strncmp ( V_1 , L_16 , 9 ) == 0 )
{
V_101 = 1 ;
break;
}
memcpy ( & ( V_103 -> V_50 [ V_100 ] ) , V_1 , V_7 ) ;
V_103 -> V_50 [ V_100 + V_7 ] = '\0' ;
V_100 += V_7 ;
}
V_99 = 0 ;
if ( ! F_58 ( V_104 , 1024 ) )
{ F_3 ( V_106 , V_69 ) ; goto V_52; }
V_104 -> V_50 [ 0 ] = '\0' ;
if ( ! V_101 )
{
for (; ; )
{
V_7 = F_57 ( V_47 , V_1 , 254 ) ;
if ( V_7 <= 0 ) break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
if ( V_7 != 65 ) V_97 = 1 ;
if ( strncmp ( V_1 , L_16 , 9 ) == 0 )
break;
if ( V_7 > 65 ) break;
if ( ! F_59 ( V_104 , V_7 + V_99 + 9 ) )
{
F_3 ( V_106 , V_69 ) ;
goto V_52;
}
memcpy ( & ( V_104 -> V_50 [ V_99 ] ) , V_1 , V_7 ) ;
V_104 -> V_50 [ V_99 + V_7 ] = '\0' ;
V_99 += V_7 ;
if ( V_97 )
{
V_1 [ 0 ] = '\0' ;
V_7 = F_57 ( V_47 , V_1 , 254 ) ;
if ( V_7 <= 0 ) break;
while ( ( V_7 >= 0 ) && ( V_1 [ V_7 ] <= ' ' ) ) V_7 -- ;
V_1 [ ++ V_7 ] = '\n' ; V_1 [ ++ V_7 ] = '\0' ;
break;
}
}
}
else
{
V_105 = V_103 ;
V_103 = V_104 ;
V_104 = V_105 ;
V_99 = V_100 ;
}
V_7 = strlen ( V_102 -> V_50 ) ;
if ( ( strncmp ( V_1 , L_16 , 9 ) != 0 ) ||
( strncmp ( V_102 -> V_50 , & ( V_1 [ 9 ] ) , V_7 ) != 0 ) ||
( strncmp ( & ( V_1 [ 9 + V_7 ] ) , L_15 , 6 ) != 0 ) )
{
F_3 ( V_106 , V_107 ) ;
goto V_52;
}
F_60 ( & V_59 ) ;
V_7 = F_61 ( & V_59 ,
( unsigned char * ) V_104 -> V_50 , & V_99 ,
( unsigned char * ) V_104 -> V_50 , V_99 ) ;
if ( V_7 < 0 )
{
F_3 ( V_106 , V_108 ) ;
goto V_52;
}
V_7 = F_62 ( & V_59 , ( unsigned char * ) & ( V_104 -> V_50 [ V_99 ] ) , & V_98 ) ;
if ( V_7 < 0 )
{
F_3 ( V_106 , V_108 ) ;
goto V_52;
}
V_99 += V_98 ;
if ( V_99 == 0 ) goto V_52;
* V_21 = V_102 -> V_50 ;
* V_49 = V_103 -> V_50 ;
* V_50 = ( unsigned char * ) V_104 -> V_50 ;
* V_18 = V_99 ;
F_21 ( V_102 ) ;
F_21 ( V_103 ) ;
F_21 ( V_104 ) ;
return ( 1 ) ;
V_52:
F_56 ( V_102 ) ;
F_56 ( V_103 ) ;
F_56 ( V_104 ) ;
return ( 0 ) ;
}
