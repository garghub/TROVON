static void F_1 ( const T_1 * V_1 , void * V_2 )
{
T_2 * V_3 = V_2 ;
static int V_4 ;
if ( ! islower ( ( unsigned char ) * V_1 -> V_1 ) )
return;
F_2 ( V_3 , L_1 , V_1 -> V_1 ) ;
if ( ++ V_4 == 3 ) {
F_2 ( V_3 , L_2 ) ;
V_4 = 0 ;
} else
F_2 ( V_3 , L_3 ) ;
}
int MAIN ( int V_5 , char * * V_6 )
{
static const char V_7 [] = L_4 ;
char V_8 [ sizeof V_7 - 1 ] ;
char * V_9 = NULL ;
unsigned char * V_10 = NULL , * V_11 = NULL ;
int V_12 = V_13 , V_14 = 0 ;
int V_15 = 1 , V_16 ;
int V_17 = 0 ;
unsigned char V_18 [ V_19 ] , V_20 [ V_21 ] ;
unsigned char V_22 [ V_23 ] ;
char * V_24 = NULL , * V_25 = NULL , * V_26 = NULL ;
char * V_27 = NULL , * V_28 = NULL , * V_29 = NULL ;
char * V_30 = NULL ;
int V_31 = 1 , V_32 = 0 , V_33 , V_34 = 0 ;
#ifdef F_3
int V_35 = 0 ;
T_2 * V_36 = NULL ;
#endif
int V_37 = 0 , V_38 = 0 , V_39 = 0 ;
const T_3 * V_40 = NULL , * V_41 ;
T_4 * V_42 = NULL ;
char * V_43 = NULL , * V_44 = NULL ;
T_2 * V_45 = NULL , * V_46 = NULL , * V_47 = NULL , * V_48 = NULL , * V_49 =
NULL , * V_50 = NULL ;
#define F_4 39
char V_51 [ F_4 + 1 ] ;
#ifndef F_5
char * V_52 = NULL ;
#endif
const T_5 * V_53 = NULL ;
int V_54 = 0 ;
F_6 () ;
if ( V_55 == NULL )
if ( ( V_55 = F_7 ( F_8 () ) ) != NULL )
F_9 ( V_55 , V_56 , V_57 | V_58 ) ;
if ( ! F_10 ( V_55 , NULL ) )
goto V_59;
F_11 ( V_6 [ 0 ] , V_51 , sizeof V_51 ) ;
if ( strcmp ( V_51 , L_5 ) == 0 )
V_34 = 1 ;
#ifdef F_3
if ( strcmp ( V_51 , L_6 ) == 0 )
V_35 = 1 ;
#endif
V_40 = F_12 ( V_51 ) ;
#ifdef F_3
if ( ! V_35 && ! V_34 && ( V_40 == NULL )
&& ( strcmp ( V_51 , L_7 ) != 0 ) )
#else
if ( ! V_34 && ( V_40 == NULL ) && ( strcmp ( V_51 , L_7 ) != 0 ) )
#endif
{
F_2 ( V_55 , L_8 , V_51 ) ;
goto V_60;
}
V_5 -- ;
V_6 ++ ;
while ( V_5 >= 1 ) {
if ( strcmp ( * V_6 , L_9 ) == 0 )
V_31 = 1 ;
else if ( strcmp ( * V_6 , L_10 ) == 0 ) {
if ( -- V_5 < 1 )
goto V_60;
V_43 = * ( ++ V_6 ) ;
} else if ( strcmp ( * V_6 , L_11 ) == 0 ) {
if ( -- V_5 < 1 )
goto V_60;
V_44 = * ( ++ V_6 ) ;
} else if ( strcmp ( * V_6 , L_12 ) == 0 ) {
if ( -- V_5 < 1 )
goto V_60;
V_25 = * ( ++ V_6 ) ;
}
#ifndef F_5
else if ( strcmp ( * V_6 , L_13 ) == 0 ) {
if ( -- V_5 < 1 )
goto V_60;
V_52 = * ( ++ V_6 ) ;
}
#endif
else if ( strcmp ( * V_6 , L_14 ) == 0 )
V_31 = 0 ;
else if ( strcmp ( * V_6 , L_15 ) == 0 )
V_32 = 1 ;
else if ( strcmp ( * V_6 , L_16 ) == 0 )
V_14 = 1 ;
else if ( strcmp ( * V_6 , L_17 ) == 0 )
V_17 = 1 ;
else if ( strcmp ( * V_6 , L_18 ) == 0 )
V_39 = 0 ;
else if ( strcmp ( * V_6 , L_19 ) == 0 )
V_39 = 1 ;
else if ( strcmp ( * V_6 , L_20 ) == 0 )
V_37 = 1 ;
else if ( strcmp ( * V_6 , L_21 ) == 0 )
V_32 = 2 ;
else if ( strcmp ( * V_6 , L_22 ) == 0 )
V_38 = 1 ;
else if ( strcmp ( * V_6 , L_23 ) == 0 )
V_34 = 1 ;
else if ( strcmp ( * V_6 , L_24 ) == 0 )
V_34 = 1 ;
#ifdef F_3
else if ( strcmp ( * V_6 , L_25 ) == 0 )
V_35 = 1 ;
#endif
else if ( strcmp ( * V_6 , L_26 ) == 0 ) {
if ( -- V_5 < 1 )
goto V_60;
V_11 = ( unsigned char * ) * ( ++ V_6 ) ;
} else if ( strcmp ( * V_6 , L_27 ) == 0 ) {
if ( -- V_5 < 1 )
goto V_60;
V_24 = * ( ++ V_6 ) ;
} else if ( strcmp ( * V_6 , L_28 ) == 0 ) {
static char V_61 [ 128 ] ;
T_6 * V_62 ;
char * V_63 ;
if ( -- V_5 < 1 )
goto V_60;
V_63 = * ( ++ V_6 ) ;
V_62 = fopen ( V_63 , L_29 ) ;
if ( V_62 == NULL ) {
F_2 ( V_55 , L_30 , V_63 ) ;
goto V_60;
}
V_61 [ 0 ] = '\0' ;
if ( ! fgets ( V_61 , sizeof V_61 , V_62 ) ) {
F_2 ( V_55 , L_30 , V_63 ) ;
goto V_60;
}
fclose ( V_62 ) ;
V_33 = strlen ( V_61 ) ;
if ( ( V_33 > 0 ) && ( ( V_61 [ V_33 - 1 ] == '\n' ) || ( V_61 [ V_33 - 1 ] == '\r' ) ) )
V_61 [ -- V_33 ] = '\0' ;
if ( ( V_33 > 0 ) && ( ( V_61 [ V_33 - 1 ] == '\n' ) || ( V_61 [ V_33 - 1 ] == '\r' ) ) )
V_61 [ -- V_33 ] = '\0' ;
if ( V_33 < 1 ) {
F_2 ( V_55 , L_31 ) ;
goto V_60;
}
V_24 = V_61 ;
} else if ( strcmp ( * V_6 , L_32 ) == 0 ) {
if ( -- V_5 < 1 )
goto V_60;
V_27 = * ( ++ V_6 ) ;
} else if ( strcmp ( * V_6 , L_33 ) == 0 ) {
if ( -- V_5 < 1 )
goto V_60;
V_29 = * ( ++ V_6 ) ;
} else if ( strcmp ( * V_6 , L_34 ) == 0 ) {
if ( -- V_5 < 1 )
goto V_60;
V_28 = * ( ++ V_6 ) ;
} else if ( strcmp ( * V_6 , L_35 ) == 0 ) {
if ( -- V_5 < 1 )
goto V_60;
V_30 = * ( ++ V_6 ) ;
} else if ( strcmp ( * V_6 , L_36 ) == 0 )
V_54 = 1 ;
else if ( ( V_6 [ 0 ] [ 0 ] == '-' ) &&
( ( V_41 = F_12 ( & ( V_6 [ 0 ] [ 1 ] ) ) ) != NULL ) ) {
V_40 = V_41 ;
} else if ( strcmp ( * V_6 , L_37 ) == 0 )
V_40 = NULL ;
else {
F_2 ( V_55 , L_38 , * V_6 ) ;
V_60:
F_2 ( V_55 , L_39 ) ;
F_2 ( V_55 , L_40 , L_41 ) ;
F_2 ( V_55 , L_42 , L_43 ) ;
F_2 ( V_55 , L_44 , L_45 ) ;
F_2 ( V_55 , L_46 , L_9 ) ;
F_2 ( V_55 , L_47 , L_14 ) ;
F_2 ( V_55 ,
L_48 ,
L_49 ) ;
F_2 ( V_55 , L_50 ,
L_27 ) ;
F_2 ( V_55 ,
L_51 ,
L_28 ) ;
F_2 ( V_55 ,
L_52 ,
L_35 ) ;
F_2 ( V_55 ,
L_53 ,
L_54 ) ;
F_2 ( V_55 , L_55 ,
L_33 ) ;
F_2 ( V_55 , L_56 ,
L_57 ) ;
F_2 ( V_55 , L_58 ,
L_59 ) ;
F_2 ( V_55 , L_60 , L_61 ) ;
F_2 ( V_55 , L_62 ,
L_17 ) ;
#ifndef F_5
F_2 ( V_55 ,
L_63 ,
L_64 ) ;
#endif
F_2 ( V_55 , L_65 ) ;
F_13 ( V_64 ,
F_1 , V_55 ) ;
F_2 ( V_55 , L_2 ) ;
goto V_59;
}
V_5 -- ;
V_6 ++ ;
}
#ifndef F_5
F_14 ( V_55 , V_52 , 0 ) ;
#endif
if ( V_40 && F_15 ( V_40 ) & V_65 ) {
F_2 ( V_55 ,
L_66 ) ;
goto V_59;
}
if ( V_40 && ( F_16 ( V_40 ) == V_66 ) ) {
F_2 ( V_55 ,
L_67 ) ;
goto V_59;
}
if ( V_30 && ( V_53 = F_17 ( V_30 ) ) == NULL ) {
F_2 ( V_55 , L_68 , V_30 ) ;
goto V_59;
}
if ( V_53 == NULL ) {
V_53 = F_18 () ;
}
if ( V_11 != NULL ) {
unsigned long V_4 ;
for ( V_4 = 0 ; * V_11 ; V_11 ++ ) {
V_33 = * V_11 ;
if ( ( V_33 <= '9' ) && ( V_33 >= '0' ) )
V_4 = V_4 * 10 + V_33 - '0' ;
else if ( V_33 == 'k' ) {
V_4 *= 1024 ;
V_11 ++ ;
break;
}
}
if ( * V_11 != '\0' ) {
F_2 ( V_55 , L_69 ) ;
goto V_59;
}
if ( V_34 && V_4 < 80 )
V_4 = 80 ;
V_12 = ( int ) V_4 ;
if ( V_14 )
F_2 ( V_55 , L_70 , V_12 ) ;
}
V_9 = F_19 ( V_67 ) ;
V_10 = ( unsigned char * ) F_19 ( F_20 ( V_12 ) ) ;
if ( ( V_10 == NULL ) || ( V_9 == NULL ) ) {
F_2 ( V_55 , L_71 ,
( long ) F_20 ( V_12 ) ) ;
goto V_59;
}
V_45 = F_7 ( F_8 () ) ;
V_46 = F_7 ( F_8 () ) ;
if ( ( V_45 == NULL ) || ( V_46 == NULL ) ) {
F_21 ( V_55 ) ;
goto V_59;
}
if ( V_37 ) {
F_22 ( V_45 , V_68 ) ;
F_22 ( V_46 , V_68 ) ;
F_23 ( V_45 , ( char * ) V_55 ) ;
F_23 ( V_46 , ( char * ) V_55 ) ;
}
if ( V_43 == NULL ) {
#ifndef F_24
if ( V_11 != NULL )
setvbuf ( V_69 , ( char * ) NULL , V_70 , 0 ) ;
#endif
F_9 ( V_45 , V_69 , V_57 ) ;
} else {
if ( F_25 ( V_45 , V_43 ) <= 0 ) {
perror ( V_43 ) ;
goto V_59;
}
}
if ( ! V_24 && V_25 ) {
if ( ! F_26 ( V_55 , V_25 , NULL , & V_26 , NULL ) ) {
F_2 ( V_55 , L_72 ) ;
goto V_59;
}
V_24 = V_26 ;
}
if ( ( V_24 == NULL ) && ( V_40 != NULL ) && ( V_27 == NULL ) ) {
for (; ; ) {
char V_61 [ 200 ] ;
F_27 ( V_61 , sizeof V_61 , L_73 ,
F_28 ( F_29 ( V_40 ) ) ,
( V_31 ) ? L_74 : L_75 ) ;
V_9 [ 0 ] = '\0' ;
V_33 = F_30 ( ( char * ) V_9 , V_67 , V_61 , V_31 ) ;
if ( V_33 == 0 ) {
if ( V_9 [ 0 ] == '\0' ) {
V_15 = 1 ;
goto V_59;
}
V_24 = V_9 ;
break;
}
if ( V_33 < 0 ) {
F_2 ( V_55 , L_76 ) ;
goto V_59;
}
}
}
if ( V_44 == NULL ) {
F_9 ( V_46 , stdout , V_57 ) ;
#ifndef F_24
if ( V_11 != NULL )
setvbuf ( stdout , ( char * ) NULL , V_70 , 0 ) ;
#endif
#ifdef F_31
{
T_2 * V_71 = F_7 ( F_32 () ) ;
V_46 = F_33 ( V_71 , V_46 ) ;
}
#endif
} else {
if ( F_34 ( V_46 , V_44 ) <= 0 ) {
perror ( V_44 ) ;
goto V_59;
}
}
V_49 = V_45 ;
V_50 = V_46 ;
#ifdef F_3
if ( V_35 ) {
if ( ( V_36 = F_7 ( F_35 () ) ) == NULL )
goto V_59;
if ( V_31 )
V_50 = F_33 ( V_36 , V_50 ) ;
else
V_49 = F_33 ( V_36 , V_49 ) ;
}
#endif
if ( V_34 ) {
if ( ( V_47 = F_7 ( F_36 () ) ) == NULL )
goto V_59;
if ( V_37 ) {
F_22 ( V_47 , V_68 ) ;
F_23 ( V_47 , ( char * ) V_55 ) ;
}
if ( V_38 )
F_37 ( V_47 , V_72 ) ;
if ( V_31 )
V_50 = F_33 ( V_47 , V_50 ) ;
else
V_49 = F_33 ( V_47 , V_49 ) ;
}
if ( V_40 != NULL ) {
if ( V_24 != NULL ) {
unsigned char * V_73 ;
if ( V_39 )
V_73 = NULL ;
else {
if ( V_31 ) {
if ( V_29 ) {
if ( ! F_38 ( V_29 , V_22 , sizeof V_22 ) ) {
F_2 ( V_55 , L_77 ) ;
goto V_59;
}
} else if ( F_39 ( V_22 , sizeof V_22 ) < 0 )
goto V_59;
if ( ( V_32 != 2 )
&& ( F_40 ( V_50 , V_7 ,
sizeof V_7 - 1 ) != sizeof V_7 - 1
|| F_40 ( V_50 ,
( char * ) V_22 ,
sizeof V_22 ) != sizeof V_22 ) ) {
F_2 ( V_55 , L_78 ) ;
goto V_59;
}
} else if ( F_41 ( V_49 , V_8 , sizeof V_8 ) != sizeof V_8
|| F_41 ( V_49 ,
( unsigned char * ) V_22 ,
sizeof V_22 ) != sizeof V_22 ) {
F_2 ( V_55 , L_79 ) ;
goto V_59;
} else if ( memcmp ( V_8 , V_7 , sizeof V_7 - 1 ) ) {
F_2 ( V_55 , L_80 ) ;
goto V_59;
}
V_73 = V_22 ;
}
F_42 ( V_40 , V_53 , V_73 ,
( unsigned char * ) V_24 , strlen ( V_24 ) , 1 , V_18 , V_20 ) ;
if ( V_24 == V_9 )
F_43 ( V_24 , V_67 ) ;
else
F_43 ( V_24 , strlen ( V_24 ) ) ;
}
if ( ( V_28 != NULL ) && ! F_38 ( V_28 , V_20 , sizeof V_20 ) ) {
F_2 ( V_55 , L_81 ) ;
goto V_59;
}
if ( ( V_28 == NULL ) && ( V_24 == NULL )
&& F_44 ( V_40 ) != 0 ) {
F_2 ( V_55 , L_82 ) ;
goto V_59;
}
if ( ( V_27 != NULL ) && ! F_38 ( V_27 , V_18 , sizeof V_18 ) ) {
F_2 ( V_55 , L_83 ) ;
goto V_59;
}
if ( ( V_48 = F_7 ( F_45 () ) ) == NULL )
goto V_59;
F_46 ( V_48 , & V_42 ) ;
if ( V_54 )
F_47 ( V_42 , V_74 ) ;
if ( ! F_48 ( V_42 , V_40 , NULL , NULL , NULL , V_31 ) ) {
F_2 ( V_55 , L_84 ,
F_49 ( V_40 ) ) ;
F_21 ( V_55 ) ;
goto V_59;
}
if ( V_17 )
F_50 ( V_42 , 0 ) ;
if ( ! F_48 ( V_42 , NULL , NULL , V_18 , V_20 , V_31 ) ) {
F_2 ( V_55 , L_84 ,
F_49 ( V_40 ) ) ;
F_21 ( V_55 ) ;
goto V_59;
}
if ( V_37 ) {
F_22 ( V_48 , V_68 ) ;
F_23 ( V_48 , ( char * ) V_55 ) ;
}
if ( V_32 ) {
if ( ! V_39 ) {
printf ( L_85 ) ;
for ( V_33 = 0 ; V_33 < ( int ) sizeof( V_22 ) ; V_33 ++ )
printf ( L_86 , V_22 [ V_33 ] ) ;
printf ( L_2 ) ;
}
if ( V_40 -> V_75 > 0 ) {
printf ( L_87 ) ;
for ( V_33 = 0 ; V_33 < V_40 -> V_75 ; V_33 ++ )
printf ( L_86 , V_18 [ V_33 ] ) ;
printf ( L_2 ) ;
}
if ( V_40 -> V_76 > 0 ) {
printf ( L_88 ) ;
for ( V_33 = 0 ; V_33 < V_40 -> V_76 ; V_33 ++ )
printf ( L_86 , V_20 [ V_33 ] ) ;
printf ( L_2 ) ;
}
if ( V_32 == 2 ) {
V_15 = 0 ;
goto V_59;
}
}
}
if ( V_48 != NULL )
V_50 = F_33 ( V_48 , V_50 ) ;
for (; ; ) {
V_16 = F_41 ( V_49 , ( char * ) V_10 , V_12 ) ;
if ( V_16 <= 0 )
break;
if ( F_40 ( V_50 , ( char * ) V_10 , V_16 ) != V_16 ) {
F_2 ( V_55 , L_78 ) ;
goto V_59;
}
}
if ( ! F_51 ( V_50 ) ) {
F_2 ( V_55 , L_89 ) ;
goto V_59;
}
V_15 = 0 ;
if ( V_14 ) {
F_2 ( V_55 , L_90 , F_52 ( V_45 ) ) ;
F_2 ( V_55 , L_91 , F_53 ( V_46 ) ) ;
}
V_59:
F_21 ( V_55 ) ;
if ( V_9 != NULL )
F_54 ( V_9 ) ;
if ( V_10 != NULL )
F_54 ( V_10 ) ;
if ( V_45 != NULL )
F_55 ( V_45 ) ;
if ( V_46 != NULL )
F_56 ( V_46 ) ;
if ( V_48 != NULL )
F_55 ( V_48 ) ;
if ( V_47 != NULL )
F_55 ( V_47 ) ;
#ifdef F_3
if ( V_36 != NULL )
F_55 ( V_36 ) ;
#endif
if ( V_26 )
F_54 ( V_26 ) ;
F_57 () ;
F_58 ( V_15 ) ;
}
int F_38 ( char * V_45 , unsigned char * V_46 , int V_77 )
{
int V_33 , V_4 ;
unsigned char V_78 ;
V_4 = strlen ( V_45 ) ;
if ( V_4 > ( V_77 * 2 ) ) {
F_2 ( V_55 , L_92 ) ;
return ( 0 ) ;
}
memset ( V_46 , 0 , V_77 ) ;
for ( V_33 = 0 ; V_33 < V_4 ; V_33 ++ ) {
V_78 = ( unsigned char ) * V_45 ;
* ( V_45 ++ ) = '\0' ;
if ( V_78 == 0 )
break;
if ( ( V_78 >= '0' ) && ( V_78 <= '9' ) )
V_78 -= '0' ;
else if ( ( V_78 >= 'A' ) && ( V_78 <= 'F' ) )
V_78 = V_78 - 'A' + 10 ;
else if ( ( V_78 >= 'a' ) && ( V_78 <= 'f' ) )
V_78 = V_78 - 'a' + 10 ;
else {
F_2 ( V_55 , L_93 ) ;
return ( 0 ) ;
}
if ( V_33 & 1 )
V_46 [ V_33 / 2 ] |= V_78 ;
else
V_46 [ V_33 / 2 ] = ( V_78 << 4 ) ;
}
return ( 1 ) ;
}
