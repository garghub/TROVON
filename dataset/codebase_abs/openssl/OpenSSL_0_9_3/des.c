int main ( int V_1 , char * * V_2 )
{
int V_3 ;
struct V_4 V_5 , V_6 ;
char * V_7 ;
char * V_8 = NULL , * V_9 = NULL ;
V_10 = V_11 = V_12 = V_13 = V_14 = V_15 = V_16 = V_17 = V_18 = V_19 = V_20 = 0 ;
error = 0 ;
memset ( V_21 , 0 , sizeof( V_21 ) ) ;
for ( V_3 = 1 ; V_3 < V_1 ; V_3 ++ )
{
V_7 = V_2 [ V_3 ] ;
if ( ( V_7 [ 0 ] == '-' ) && ( V_7 [ 1 ] != '\0' ) )
{
V_7 ++ ;
while ( * V_7 )
{
switch ( * ( V_7 ++ ) )
{
case '3' :
V_20 = 1 ;
V_22 = 1 ;
break;
case 'c' :
V_11 = 1 ;
strncpy ( V_23 , V_7 , 200 ) ;
V_7 += strlen ( V_23 ) ;
break;
case 'C' :
V_11 = 1 ;
V_22 = 1 ;
strncpy ( V_23 , V_7 , 200 ) ;
V_7 += strlen ( V_23 ) ;
break;
case 'e' :
V_12 = 1 ;
break;
case 'v' :
V_10 = 1 ;
break;
case 'E' :
V_12 = 1 ;
V_22 = 1 ;
break;
case 'd' :
V_13 = 1 ;
break;
case 'D' :
V_13 = 1 ;
V_22 = 1 ;
break;
case 'b' :
V_16 = 1 ;
break;
case 'f' :
V_17 = 1 ;
break;
case 's' :
V_18 = 1 ;
break;
case 'u' :
V_19 = 1 ;
strncpy ( V_24 , V_7 , 200 ) ;
V_7 += strlen ( V_24 ) ;
break;
case 'h' :
V_15 = 1 ;
break;
case 'k' :
V_14 = 1 ;
if ( ( V_3 + 1 ) == V_1 )
{
fputs ( L_1 , V_25 ) ;
error = 1 ;
}
else
{
int V_26 ;
V_3 ++ ;
strncpy ( V_21 , V_2 [ V_3 ] , V_27 ) ;
for ( V_26 = strlen ( V_2 [ V_3 ] ) - 1 ; V_26 >= 0 ; V_26 -- )
V_2 [ V_3 ] [ V_26 ] = '\0' ;
}
break;
default:
fprintf ( V_25 , L_2 , V_7 [ - 1 ] ) ;
error = 1 ;
break;
}
}
}
else
{
if ( V_8 == NULL )
V_8 = V_2 [ V_3 ] ;
else if ( V_9 == NULL )
V_9 = V_2 [ V_3 ] ;
else
error = 1 ;
}
}
if ( error ) F_1 () ;
if ( ( ( V_12 + V_13 ) == 1 ) || V_11 )
{
if ( V_12 ) V_28 = V_29 ;
if ( V_13 ) V_28 = V_30 ;
}
else
{
if ( V_10 )
{
#ifndef F_2
fprintf ( V_25 , L_3 , V_31 ) ;
#endif
EXIT ( 1 ) ;
}
else F_1 () ;
}
#ifndef F_2
if ( V_10 ) fprintf ( V_25 , L_3 , V_31 ) ;
#endif
if ( ( V_8 != NULL ) &&
( V_9 != NULL ) &&
#ifndef F_3
( V_4 ( V_8 , & V_5 ) != - 1 ) &&
( V_4 ( V_9 , & V_6 ) != - 1 ) &&
( V_5 . V_32 == V_6 . V_32 ) &&
( V_5 . V_33 == V_6 . V_33 ) )
#else
( strcmp ( V_8 , V_9 ) == 0 ) )
#endif
{
fputs ( L_4 , V_25 ) ;
EXIT ( 3 ) ;
}
if (!kflag
void F_4 ( void )
{
#ifdef F_5
extern int F_6 ();
extern int F_7 ();
extern unsigned long time ();
#endif
register int V_3 ;
T_1 V_34 , V_35 ;
unsigned char V_36 [ 8 ] , V_37 [ 8 ] ;
char * V_7 ;
int V_38 = 0 , V_26 , V_39 , V_40 , V_41 , V_42 , V_43 , V_44 , V_45 = 0 ;
T_2 V_46 , V_47 ;
T_3 * V_48 ;
int Exit = 0 ;
#ifndef F_3
static unsigned char V_49 [ V_50 + 8 ] , V_51 [ V_50 + 8 ] ;
#else
static unsigned char * V_49 = NULL , * V_51 = NULL ;
if ( V_49 == NULL )
{
if ( ( ( V_49 = ( unsigned char * ) Malloc ( V_50 + 8 ) ) == NULL ) ||
( ( V_51 = ( unsigned char * ) Malloc ( V_50 + 8 ) ) == NULL ) )
{
fputs ( L_5 , V_25 ) ;
Exit = 10 ;
goto V_52;
}
}
#endif
if ( V_15 )
{
V_26 = ( V_20 ? 16 : 8 ) ;
V_7 = V_21 ;
for ( V_3 = 0 ; V_3 < V_26 ; V_3 ++ )
{
V_39 = 0 ;
if ( ( * V_7 <= '9' ) && ( * V_7 >= '0' ) )
V_39 = ( * V_7 - '0' ) << 4 ;
else if ( ( * V_7 <= 'f' ) && ( * V_7 >= 'a' ) )
V_39 = ( * V_7 - 'a' + 10 ) << 4 ;
else if ( ( * V_7 <= 'F' ) && ( * V_7 >= 'A' ) )
V_39 = ( * V_7 - 'A' + 10 ) << 4 ;
else
{
fputs ( L_6 , V_25 ) ;
Exit = 9 ;
goto V_52;
}
V_7 ++ ;
if ( ( * V_7 <= '9' ) && ( * V_7 >= '0' ) )
V_39 |= ( * V_7 - '0' ) ;
else if ( ( * V_7 <= 'f' ) && ( * V_7 >= 'a' ) )
V_39 |= ( * V_7 - 'a' + 10 ) ;
else if ( ( * V_7 <= 'F' ) && ( * V_7 >= 'A' ) )
V_39 |= ( * V_7 - 'A' + 10 ) ;
else
{
fputs ( L_6 , V_25 ) ;
Exit = 9 ;
goto V_52;
}
V_7 ++ ;
if ( V_3 < 8 )
V_46 [ V_3 ] = V_39 ;
else
V_47 [ V_3 - 8 ] = V_39 ;
}
F_8 ( ( V_53 * ) V_47 , V_35 ) ;
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
}
else if ( V_22 || V_20 )
{
if ( V_20 )
{
F_9 ( V_21 , ( V_53 * ) V_46 , ( V_53 * ) V_47 ) ;
F_8 ( ( V_53 * ) V_47 , V_35 ) ;
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
}
else
F_10 ( V_21 , ( V_53 * ) V_46 ) ;
}
else
for ( V_3 = 0 ; V_3 < V_54 ; V_3 ++ )
{
V_40 = 0 ;
V_39 = V_21 [ V_3 ] ;
for ( V_26 = 0 ; V_26 < 8 ; V_26 ++ )
{
if ( V_39 & 1 ) V_40 ++ ;
V_39 >>= 1 ;
}
if ( V_40 & 1 )
V_46 [ V_3 ] = V_21 [ V_3 ] & 0x7f ;
else
V_46 [ V_3 ] = V_21 [ V_3 ] | 0x80 ;
}
F_8 ( ( V_53 * ) V_46 , V_34 ) ;
memset ( V_21 , 0 , sizeof( V_21 ) ) ;
memset ( V_46 , 0 , sizeof( V_46 ) ) ;
memset ( V_36 , 0 , sizeof( V_36 ) ) ;
memset ( V_37 , 0 , sizeof( V_37 ) ) ;
V_40 = 1 ;
V_41 = 0 ;
if ( V_12 || ( ! V_13 && V_11 ) )
{
for (; ; )
{
V_38 = V_40 = fread ( & ( V_49 [ V_41 ] ) , 1 , V_50 , V_55 ) ;
V_40 += V_41 ;
V_38 += V_41 ;
if ( V_40 < 0 )
{
perror ( L_7 ) ;
Exit = 6 ;
goto V_52;
}
V_41 = V_40 % 8 ;
V_43 = V_40 - V_41 ;
if ( feof ( V_55 ) )
{
F_6 ( ( unsigned int ) time ( NULL ) ) ;
for ( V_3 = 7 - V_41 ; V_3 > 0 ; V_3 -- )
V_49 [ V_40 ++ ] = F_7 () & 0xff ;
V_49 [ V_40 ++ ] = V_41 ;
V_45 = 1 ;
V_43 += V_41 ;
}
else
V_40 -= V_41 ;
if ( V_11 )
{
F_11 ( ( V_53 * ) V_49 , ( V_53 * ) V_56 ,
( long ) V_43 , V_34 , ( V_53 * ) V_56 ) ;
if ( ! V_12 )
{
if ( feof ( V_55 ) ) break;
else continue;
}
}
if ( V_16 && ! V_20 )
for ( V_3 = 0 ; V_3 < V_40 ; V_3 += 8 )
F_12 (
( T_2 * ) & ( V_49 [ V_3 ] ) ,
( T_2 * ) & ( V_51 [ V_3 ] ) ,
V_34 , V_28 ) ;
else if ( V_20 && V_16 )
for ( V_3 = 0 ; V_3 < V_40 ; V_3 += 8 )
F_13 (
( T_2 * ) & ( V_49 [ V_3 ] ) ,
( T_2 * ) & ( V_51 [ V_3 ] ) ,
V_34 , V_35 , V_28 ) ;
else if ( V_20 && ! V_16 )
{
char V_57 [ 8 ] ;
if ( V_41 ) memcpy ( V_57 , & ( V_49 [ V_40 ] ) ,
( unsigned int ) V_41 ) ;
F_14 (
( T_2 * ) V_49 , ( T_2 * ) V_51 ,
( long ) V_40 , V_34 , V_35 , ( T_2 * ) V_36 ,
( T_2 * ) V_37 , V_28 ) ;
if ( V_41 ) memcpy ( & ( V_49 [ V_40 ] ) , V_57 ,
( unsigned int ) V_41 ) ;
}
else
{
F_15 (
( T_2 * ) V_49 , ( T_2 * ) V_51 ,
( long ) V_40 , V_34 , ( T_2 * ) V_36 , V_28 ) ;
if ( V_40 >= 8 ) memcpy ( V_36 , & ( V_51 [ V_40 - 8 ] ) , 8 ) ;
}
if ( V_41 ) memcpy ( V_49 , & ( V_49 [ V_40 ] ) , ( unsigned int ) V_41 ) ;
V_3 = 0 ;
while ( V_3 < V_40 )
{
if ( V_19 )
V_26 = F_16 ( V_51 , 1 , ( unsigned int ) V_40 - V_3 ,
V_58 ) ;
else
V_26 = fwrite ( V_51 , 1 , ( unsigned int ) V_40 - V_3 ,
V_58 ) ;
if ( V_26 == - 1 )
{
perror ( L_8 ) ;
Exit = 7 ;
goto V_52;
}
V_3 += V_26 ;
}
if ( feof ( V_55 ) )
{
if ( V_19 ) F_17 ( V_58 ) ;
break;
}
}
}
else
{
V_45 = 1 ;
for (; ; )
{
if ( V_45 ) {
if ( V_19 )
V_40 = F_18 ( V_49 , 1 , V_50 , V_55 ) ;
else
V_40 = fread ( V_49 , 1 , V_50 , V_55 ) ;
V_45 = 0 ;
V_41 = V_40 % 8 ;
V_40 -= V_41 ;
}
if ( V_40 < 0 )
{
perror ( L_7 ) ;
Exit = 6 ;
goto V_52;
}
if ( V_16 && ! V_20 )
for ( V_3 = 0 ; V_3 < V_40 ; V_3 += 8 )
F_12 (
( T_2 * ) & ( V_49 [ V_3 ] ) ,
( T_2 * ) & ( V_51 [ V_3 ] ) ,
V_34 , V_28 ) ;
else if ( V_20 && V_16 )
for ( V_3 = 0 ; V_3 < V_40 ; V_3 += 8 )
F_13 (
( T_2 * ) & ( V_49 [ V_3 ] ) ,
( T_2 * ) & ( V_51 [ V_3 ] ) ,
V_34 , V_35 , V_28 ) ;
else if ( V_20 && ! V_16 )
{
F_14 (
( T_2 * ) V_49 , ( T_2 * ) V_51 ,
( long ) V_40 , V_34 , V_35 , ( T_2 * ) V_36 ,
( T_2 * ) V_37 , V_28 ) ;
}
else
{
F_15 (
( T_2 * ) V_49 , ( T_2 * ) V_51 ,
( long ) V_40 , V_34 , ( T_2 * ) V_36 , V_28 ) ;
if ( V_40 >= 8 ) memcpy ( V_36 , & ( V_49 [ V_40 - 8 ] ) , 8 ) ;
}
if ( V_19 )
V_42 = F_18 ( & ( V_49 [ V_41 ] ) , 1 , V_50 , V_55 ) ;
else
V_42 = fread ( & ( V_49 [ V_41 ] ) , 1 , V_50 , V_55 ) ;
V_42 += V_41 ;
V_41 = V_42 % 8 ;
V_42 -= V_41 ;
if ( feof ( V_55 ) && ( V_42 == 0 ) )
{
V_44 = V_51 [ V_40 - 1 ] ;
if ( ( V_44 > 7 ) || ( V_44 < 0 ) )
{
fputs ( L_9 ,
V_25 ) ;
Exit = 8 ;
V_44 = 0 ;
}
V_40 = V_40 - 8 + V_44 ;
}
V_3 = 0 ;
if ( V_11 ) F_11 ( ( V_53 * ) V_51 ,
( V_53 * ) V_56 , ( long ) V_40 / 8 * 8 , V_34 ,
( V_53 * ) V_56 ) ;
while ( V_3 != V_40 )
{
V_26 = fwrite ( V_51 , 1 , ( unsigned int ) V_40 - V_3 , V_58 ) ;
if ( V_26 == - 1 )
{
perror ( L_8 ) ;
Exit = 7 ;
goto V_52;
}
V_3 += V_26 ;
}
V_40 = V_42 ;
if ( ( V_40 == 0 ) && feof ( V_55 ) ) break;
}
}
if ( V_11 )
{
V_40 = 0 ;
if ( V_23 [ 0 ] != '\0' )
{
if ( ( V_48 = fopen ( V_23 , L_10 ) ) != NULL )
{
V_59 = V_48 ;
V_40 = 1 ;
}
}
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ )
fprintf ( V_59 , L_11 , V_56 [ V_3 ] ) ;
fprintf ( V_59 , L_12 ) ;
if ( V_40 ) fclose ( V_59 ) ;
}
V_52:
memset ( V_49 , 0 , sizeof( V_49 ) ) ;
memset ( V_51 , 0 , sizeof( V_51 ) ) ;
memset ( V_34 , 0 , sizeof( V_34 ) ) ;
memset ( V_35 , 0 , sizeof( V_35 ) ) ;
memset ( V_36 , 0 , sizeof( V_36 ) ) ;
memset ( V_37 , 0 , sizeof( V_37 ) ) ;
memset ( V_46 , 0 , sizeof( V_46 ) ) ;
memset ( V_47 , 0 , sizeof( V_47 ) ) ;
memset ( V_60 , 0 , sizeof( V_60 ) ) ;
memset ( V_61 , 0 , sizeof( V_61 ) ) ;
memset ( V_62 , 0 , sizeof( V_62 ) ) ;
memset ( V_56 , 0 , sizeof( V_56 ) ) ;
if ( Exit ) EXIT ( Exit ) ;
}
int F_16 ( unsigned char * V_63 , int V_64 , unsigned int V_38 , T_3 * V_65 )
{
int V_3 , V_26 , V_66 , V_41 , V_67 = V_38 ;
static int V_68 = 1 ;
if ( V_68 )
{
fprintf ( V_65 , L_13 ,
( V_24 [ 0 ] == '\0' ) ? L_14 : V_24 ) ;
V_68 = 0 ;
}
if ( V_69 )
{
if ( V_69 + V_38 < 45 )
{
memcpy ( & ( V_60 [ V_69 ] ) , V_63 , ( unsigned int ) V_38 ) ;
V_69 += V_38 ;
return ( V_38 ) ;
}
else
{
V_3 = 45 - V_69 ;
memcpy ( & ( V_60 [ V_69 ] ) , V_63 , ( unsigned int ) V_3 ) ;
V_26 = F_19 ( ( unsigned char * ) V_60 , 45 , V_61 ) ;
fwrite ( V_61 , 1 , ( unsigned int ) V_26 , V_65 ) ;
V_69 = 0 ;
V_63 += V_3 ;
V_38 -= V_3 ;
}
}
for ( V_3 = 0 ; V_3 < ( ( ( int ) V_38 ) - V_70 ) ; V_3 += V_70 )
{
V_26 = F_19 ( & ( V_63 [ V_3 ] ) , V_70 , V_61 ) ;
fwrite ( V_61 , 1 , ( unsigned int ) V_26 , V_65 ) ;
}
V_41 = ( V_38 - V_3 ) % 45 ;
V_66 = ( V_38 - V_3 - V_41 ) ;
if ( V_66 )
{
V_26 = F_19 ( & ( V_63 [ V_3 ] ) , V_66 , V_61 ) ;
fwrite ( V_61 , 1 , ( unsigned int ) V_26 , V_65 ) ;
V_3 += V_66 ;
}
if ( V_3 != V_38 )
{
memcpy ( V_60 , & ( V_63 [ V_3 ] ) , ( unsigned int ) V_41 ) ;
V_69 = V_41 ;
}
return ( V_67 ) ;
}
void F_17 ( T_3 * V_65 )
{
int V_26 ;
static const char * V_71 = L_15 ;
if ( V_69 != 0 )
{
V_60 [ V_69 ] = '\0' ;
V_60 [ V_69 + 1 ] = '\0' ;
V_60 [ V_69 + 2 ] = '\0' ;
V_26 = F_19 ( V_60 , V_69 , V_61 ) ;
fwrite ( V_61 , 1 , ( unsigned int ) V_26 , V_65 ) ;
}
fwrite ( V_71 , 1 , strlen ( V_71 ) , V_65 ) ;
}
int F_18 ( unsigned char * V_9 , int V_64 , unsigned int V_38 , T_3 * V_65 )
{
int V_3 , V_26 , V_72 ;
static int V_73 = 0 ;
static int V_74 = 0 ;
static int V_68 = 1 ;
if ( V_68 )
{
for (; ; )
{
V_61 [ 0 ] = '\0' ;
fgets ( ( char * ) V_61 , 300 , V_65 ) ;
if ( V_61 [ 0 ] == '\0' )
{
fprintf ( V_25 , L_16 ) ;
return ( - 1 ) ;
}
if ( strncmp ( ( char * ) V_61 , L_17 , 6 ) == 0 ) break;
}
V_68 = 0 ;
}
if ( V_73 ) return ( 0 ) ;
V_72 = 0 ;
if ( V_74 )
{
memcpy ( V_9 , V_62 , ( unsigned int ) V_74 ) ;
V_72 = V_74 ;
V_74 = 0 ;
}
for (; ; )
{
V_61 [ 0 ] = '\0' ;
fgets ( ( char * ) V_61 , 300 , V_65 ) ;
if ( V_61 [ 0 ] == '\0' ) break;
V_3 = strlen ( ( char * ) V_61 ) ;
if ( ( V_61 [ 0 ] == 'e' ) && ( V_61 [ 1 ] == 'n' ) && ( V_61 [ 2 ] == 'd' ) )
{
V_73 = 1 ;
while ( ! feof ( V_65 ) )
{
fgets ( ( char * ) V_61 , 300 , V_65 ) ;
}
break;
}
V_3 = F_20 ( V_61 , V_3 , V_62 ) ;
if ( V_3 < 0 ) break;
if ( ( V_3 + V_72 + 8 ) > V_38 )
{
V_26 = ( V_38 / 8 * 8 ) - V_72 - 8 ;
memcpy ( & ( V_9 [ V_72 ] ) , V_62 , ( unsigned int ) V_26 ) ;
V_72 += V_26 ;
memcpy ( V_62 , & ( V_62 [ V_26 ] ) , ( unsigned int ) V_3 - V_26 ) ;
V_74 = V_3 - V_26 ;
break;
}
memcpy ( & ( V_9 [ V_72 ] ) , V_62 , ( unsigned int ) V_3 ) ;
V_72 += V_3 ;
}
return ( V_72 ) ;
}
int F_19 ( unsigned char * V_8 , int V_38 , unsigned char * V_9 )
{
int V_26 , V_3 , V_75 , V_72 = 0 ;
T_4 V_40 ;
register unsigned char * V_7 ;
V_7 = V_9 ;
for ( V_26 = 0 ; V_26 < V_38 ; V_26 += 45 )
{
if ( V_26 + 45 > V_38 )
V_3 = ( V_38 - V_26 ) ;
else V_3 = 45 ;
* ( V_7 ++ ) = V_3 + ' ' ;
for ( V_75 = 0 ; V_75 < V_3 ; V_75 += 3 )
{
F_21 ( V_8 , V_40 ) ;
* ( V_7 ++ ) = ( ( V_40 >> 18 ) & 0x3f ) + ' ' ;
* ( V_7 ++ ) = ( ( V_40 >> 12 ) & 0x3f ) + ' ' ;
* ( V_7 ++ ) = ( ( V_40 >> 6 ) & 0x3f ) + ' ' ;
* ( V_7 ++ ) = ( ( V_40 ) & 0x3f ) + ' ' ;
V_72 += 4 ;
}
* ( V_7 ++ ) = '\n' ;
V_72 += 2 ;
}
* V_7 = '\0' ;
V_40 = 0 ;
return ( V_72 ) ;
}
int F_20 ( unsigned char * V_8 , int V_38 , unsigned char * V_9 )
{
int V_26 , V_3 , V_39 ;
unsigned int V_75 = 0 , V_76 = 0 ;
T_4 V_40 ;
T_4 V_77 , V_78 , V_79 , V_80 ;
unsigned int V_81 = ( unsigned int ) '\n' - ' ' ;
for ( V_26 = 0 ; V_26 < V_38 ; )
{
V_75 = * ( V_8 ++ ) - ' ' ;
if ( V_75 == V_81 )
{
V_75 = 0 ;
V_8 -- ;
}
if ( V_75 > 60 )
{
fprintf ( V_25 , L_18 ) ;
return ( - 1 ) ;
}
V_26 ++ ;
for ( V_3 = 0 ; V_3 < V_75 ; V_26 += 4 , V_3 += 3 )
{
if ( V_76 )
{
V_77 = V_78 = V_79 = V_80 = 0 ;
}
else
{
V_77 = * ( V_8 ++ ) - ' ' ;
V_78 = * ( V_8 ++ ) - ' ' ;
V_79 = * ( V_8 ++ ) - ' ' ;
V_80 = * ( V_8 ++ ) - ' ' ;
}
if ( ( V_77 > 63 ) || ( V_78 > 63 ) || ( V_79 > 63 ) || ( V_80 > 63 ) )
{
V_39 = 0 ;
if ( V_77 == V_81 ) V_39 = 1 ;
if ( V_78 == V_81 ) V_39 = 2 ;
if ( V_79 == V_81 ) V_39 = 3 ;
if ( V_80 == V_81 ) V_39 = 4 ;
V_76 = 1 ;
switch ( V_39 ) {
case 1 : V_77 = 0 ; V_8 -- ;
case 2 : V_78 = 0 ; V_8 -- ;
case 3 : V_79 = 0 ; V_8 -- ;
case 4 : V_80 = 0 ; V_8 -- ;
break;
case 0 :
V_76 = 0 ;
fprintf ( V_25 , L_19 ) ;
V_77 = V_78 = V_79 = V_80 = 0 ;
return ( - 1 ) ;
break;
}
}
V_40 = ( V_77 << 18 ) | ( V_78 << 12 ) | ( V_79 << 6 ) | ( V_80 ) ;
F_22 ( V_40 , V_9 ) ;
}
if ( * ( V_8 ++ ) != '\n' )
{
fprintf ( V_25 , L_20 ) ;
V_77 = V_78 = V_79 = V_80 = 0 ;
return ( - 1 ) ;
}
V_26 ++ ;
}
* V_9 = '\0' ;
V_77 = V_78 = V_79 = V_80 = 0 ;
return ( V_75 ) ;
}
