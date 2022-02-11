int F_1 ( int V_1 , char * * V_2 )
{
static char V_3 [ 128 ] ;
static const char V_4 [] = L_1 ;
T_1 * V_5 = NULL , * V_6 = NULL , * V_7 = NULL , * V_8 = NULL , * V_9 =
NULL , * V_10 = NULL ;
T_2 * V_11 = NULL ;
const T_3 * V_12 = NULL , * V_13 ;
const T_4 * V_14 = NULL ;
char * V_15 = NULL , * V_16 = NULL , * V_17 = NULL , * V_18 ;
char * V_19 = NULL , * V_20 = NULL , * V_21 ;
char * V_22 = NULL , * V_23 = NULL , * V_24 = NULL , * V_25 = NULL ;
char V_26 [ sizeof V_4 - 1 ] ;
T_5 V_27 ;
int V_28 = V_29 , V_30 = 0 , V_31 = 0 , V_32 = 0 , V_33 = 0 ;
int V_34 = 1 , V_35 = 0 , V_36 , V_37 ;
int V_38 = 0 , V_39 = V_40 , V_41 = V_40 ;
int V_42 = 1 , V_43 , V_44 = 0 ;
unsigned char V_45 [ V_46 ] , V_47 [ V_48 ] ;
unsigned char * V_49 = NULL , V_50 [ V_51 ] ;
long V_52 ;
#ifdef F_2
int V_53 = 0 ;
T_1 * V_54 = NULL ;
#endif
V_21 = F_3 ( V_2 [ 0 ] ) ;
if ( strcmp ( V_21 , L_2 ) == 0 )
V_38 = 1 ;
#ifdef F_2
else if ( strcmp ( V_21 , L_3 ) == 0 )
V_53 = 1 ;
#endif
else {
V_12 = F_4 ( V_21 ) ;
if ( V_12 == NULL && strcmp ( V_21 , L_4 ) != 0 ) {
F_5 ( V_55 , L_5 , V_21 ) ;
goto V_56;
}
}
V_21 = F_6 ( V_1 , V_2 , V_57 ) ;
while ( ( V_27 = F_7 () ) != V_58 ) {
switch ( V_27 ) {
case V_58 :
case V_59 :
V_60:
F_5 ( V_55 , L_6 , V_21 ) ;
goto V_56;
case V_61 :
F_8 ( V_57 ) ;
V_42 = 0 ;
goto V_56;
case V_62 :
F_5 ( V_55 , L_7 ) ;
F_9 ( V_63 ,
V_64 , V_55 ) ;
F_5 ( V_55 , L_8 ) ;
goto V_56;
case V_65 :
V_34 = 1 ;
break;
case V_66 :
V_19 = F_10 () ;
break;
case V_67 :
V_20 = F_10 () ;
break;
case V_68 :
V_23 = F_10 () ;
break;
case V_69 :
( void ) F_11 ( F_10 () , 0 ) ;
break;
case V_70 :
V_34 = 0 ;
break;
case V_71 :
V_35 = 1 ;
break;
case V_72 :
V_30 = 1 ;
break;
case V_73 :
V_44 = 1 ;
break;
case V_74 :
V_33 = 0 ;
break;
case V_75 :
V_33 = 1 ;
break;
case V_76 :
V_31 = 1 ;
break;
case V_77 :
V_35 = 2 ;
break;
case V_78 :
V_32 = 1 ;
break;
case V_79 :
V_38 = 1 ;
break;
case V_80 :
#ifdef F_2
V_53 = 1 ;
#endif
break;
case V_81 :
V_18 = F_10 () ;
V_36 = ( int ) strlen ( V_18 ) - 1 ;
V_37 = V_36 >= 1 && V_18 [ V_36 ] == 'k' ;
if ( V_37 )
V_18 [ V_36 ] = '\0' ;
if ( ! F_12 ( F_10 () , & V_52 )
|| V_52 < 0 || ( V_37 && V_52 >= V_82 / 1024 ) )
goto V_60;
if ( V_37 )
V_52 *= 1024 ;
V_28 = ( int ) V_52 ;
break;
case V_83 :
V_22 = F_10 () ;
break;
case V_84 :
V_5 = F_13 ( F_10 () , 'r' , V_85 ) ;
if ( V_5 == NULL )
goto V_60;
V_36 = F_14 ( V_5 , V_3 , sizeof V_3 ) ;
F_15 ( V_5 ) ;
V_5 = NULL ;
if ( V_36 <= 0 ) {
F_5 ( V_55 ,
L_9 , V_21 , F_10 () ) ;
goto V_60;
}
while ( -- V_36 > 0 && ( V_3 [ V_36 ] == '\r' || V_3 [ V_36 ] == '\n' ) )
V_3 [ V_36 ] = '\0' ;
if ( V_36 <= 0 ) {
F_5 ( V_55 , L_10 , V_21 ) ;
goto V_60;
}
V_22 = V_3 ;
break;
case V_86 :
V_15 = F_10 () ;
break;
case V_87 :
V_17 = F_10 () ;
break;
case V_88 :
V_16 = F_10 () ;
break;
case V_89 :
if ( ! F_16 ( F_10 () , & V_14 ) )
goto V_60;
break;
case V_90 :
if ( ! F_17 ( F_18 () , & V_13 ) )
goto V_60;
V_12 = V_13 ;
break;
case V_91 :
V_12 = NULL ;
break;
}
}
if ( V_12 && F_19 ( V_12 ) & V_92 ) {
F_5 ( V_55 , L_11 , V_21 ) ;
goto V_56;
}
if ( V_12 && ( F_20 ( V_12 ) == V_93 ) ) {
F_5 ( V_55 , L_12 , V_21 ) ;
goto V_56;
}
if ( V_14 == NULL )
V_14 = F_21 () ;
if ( V_38 && V_28 < 80 )
V_28 = 80 ;
if ( V_30 )
F_5 ( V_55 , L_13 , V_28 ) ;
#ifdef F_2
if ( ! V_53 )
#endif
if ( V_38 ) {
if ( V_34 )
V_41 = V_94 ;
else
V_39 = V_94 ;
}
V_25 = F_22 ( V_95 , L_14 ) ;
V_49 = F_22 ( F_23 ( V_28 ) , L_15 ) ;
if ( V_19 == NULL ) {
F_24 ( V_96 ) ;
V_5 = F_25 ( V_39 ) ;
} else
V_5 = F_13 ( V_19 , 'r' , V_39 ) ;
if ( V_5 == NULL )
goto V_56;
if ( ! V_22 && V_23 ) {
if ( ! F_26 ( V_23 , NULL , & V_24 , NULL ) ) {
F_5 ( V_55 , L_16 ) ;
goto V_56;
}
V_22 = V_24 ;
}
if ( ( V_22 == NULL ) && ( V_12 != NULL ) && ( V_15 == NULL ) ) {
if ( 1 ) {
#ifndef F_27
for (; ; ) {
char V_97 [ 200 ] ;
F_28 ( V_97 , sizeof V_97 , L_17 ,
F_29 ( F_30 ( V_12 ) ) ,
( V_34 ) ? L_18 : L_19 ) ;
V_25 [ 0 ] = '\0' ;
V_36 = F_31 ( ( char * ) V_25 , V_95 , V_97 , V_34 ) ;
if ( V_36 == 0 ) {
if ( V_25 [ 0 ] == '\0' ) {
V_42 = 1 ;
goto V_56;
}
V_22 = V_25 ;
break;
}
if ( V_36 < 0 ) {
F_5 ( V_55 , L_20 ) ;
goto V_56;
}
}
} else {
#endif
F_5 ( V_55 , L_21 ) ;
goto V_56;
}
}
V_6 = F_13 ( V_20 , 'w' , V_41 ) ;
if ( V_6 == NULL )
goto V_56;
if ( V_31 ) {
F_32 ( V_5 , V_98 ) ;
F_32 ( V_6 , V_98 ) ;
F_33 ( V_5 , ( char * ) V_55 ) ;
F_33 ( V_6 , ( char * ) V_55 ) ;
}
V_9 = V_5 ;
V_10 = V_6 ;
#ifdef F_2
if ( V_53 ) {
if ( ( V_54 = F_34 ( F_35 () ) ) == NULL )
goto V_56;
if ( V_31 ) {
F_32 ( V_54 , V_98 ) ;
F_33 ( V_54 , ( char * ) V_55 ) ;
}
if ( V_34 )
V_10 = F_36 ( V_54 , V_10 ) ;
else
V_9 = F_36 ( V_54 , V_9 ) ;
}
#endif
if ( V_38 ) {
if ( ( V_7 = F_34 ( F_37 () ) ) == NULL )
goto V_56;
if ( V_31 ) {
F_32 ( V_7 , V_98 ) ;
F_33 ( V_7 , ( char * ) V_55 ) ;
}
if ( V_32 )
F_38 ( V_7 , V_99 ) ;
if ( V_34 )
V_10 = F_36 ( V_7 , V_10 ) ;
else
V_9 = F_36 ( V_7 , V_9 ) ;
}
if ( V_12 != NULL ) {
if ( V_22 != NULL ) {
unsigned char * V_100 ;
T_6 V_101 = strlen ( V_22 ) ;
if ( V_33 )
V_100 = NULL ;
else {
if ( V_34 ) {
if ( V_17 ) {
if ( ! F_39 ( V_17 , V_50 , sizeof V_50 ) ) {
F_5 ( V_55 , L_22 ) ;
goto V_56;
}
} else if ( F_40 ( V_50 , sizeof V_50 ) <= 0 )
goto V_56;
if ( ( V_35 != 2 )
&& ( F_41 ( V_10 , V_4 ,
sizeof V_4 - 1 ) != sizeof V_4 - 1
|| F_41 ( V_10 ,
( char * ) V_50 ,
sizeof V_50 ) != sizeof V_50 ) ) {
F_5 ( V_55 , L_23 ) ;
goto V_56;
}
} else if ( F_42 ( V_9 , V_26 , sizeof V_26 ) != sizeof V_26
|| F_42 ( V_9 ,
( unsigned char * ) V_50 ,
sizeof V_50 ) != sizeof V_50 ) {
F_5 ( V_55 , L_24 ) ;
goto V_56;
} else if ( memcmp ( V_26 , V_4 , sizeof V_4 - 1 ) ) {
F_5 ( V_55 , L_25 ) ;
goto V_56;
}
V_100 = V_50 ;
}
if ( ! F_43 ( V_12 , V_14 , V_100 ,
( unsigned char * ) V_22 ,
V_101 , 1 , V_45 , V_47 ) ) {
F_5 ( V_55 , L_26 ) ;
goto V_56;
}
if ( V_22 == V_25 )
F_44 ( V_22 , V_95 ) ;
else
F_44 ( V_22 , V_101 ) ;
}
if ( V_16 != NULL ) {
int V_102 = F_45 ( V_12 ) ;
if ( V_102 == 0 ) {
F_5 ( V_55 , L_27 ) ;
} else if ( ! F_39 ( V_16 , V_47 , sizeof V_47 ) ) {
F_5 ( V_55 , L_28 ) ;
goto V_56;
}
}
if ( ( V_16 == NULL ) && ( V_22 == NULL )
&& F_45 ( V_12 ) != 0 ) {
F_5 ( V_55 , L_29 ) ;
goto V_56;
}
if ( ( V_15 != NULL ) && ! F_39 ( V_15 , V_45 , F_46 ( V_12 ) ) ) {
F_5 ( V_55 , L_30 ) ;
goto V_56;
}
if ( ( V_8 = F_34 ( F_47 () ) ) == NULL )
goto V_56;
F_48 ( V_8 , & V_11 ) ;
if ( ! F_49 ( V_11 , V_12 , NULL , NULL , NULL , V_34 ) ) {
F_5 ( V_55 , L_31 ,
F_50 ( V_12 ) ) ;
F_51 ( V_55 ) ;
goto V_56;
}
if ( V_44 )
F_52 ( V_11 , 0 ) ;
if ( ! F_49 ( V_11 , NULL , NULL , V_45 , V_47 , V_34 ) ) {
F_5 ( V_55 , L_31 ,
F_50 ( V_12 ) ) ;
F_51 ( V_55 ) ;
goto V_56;
}
if ( V_31 ) {
F_32 ( V_8 , V_98 ) ;
F_33 ( V_8 , ( char * ) V_55 ) ;
}
if ( V_35 ) {
if ( ! V_33 ) {
printf ( L_32 ) ;
for ( V_36 = 0 ; V_36 < ( int ) sizeof( V_50 ) ; V_36 ++ )
printf ( L_33 , V_50 [ V_36 ] ) ;
printf ( L_8 ) ;
}
if ( F_46 ( V_12 ) > 0 ) {
printf ( L_34 ) ;
for ( V_36 = 0 ; V_36 < F_46 ( V_12 ) ; V_36 ++ )
printf ( L_33 , V_45 [ V_36 ] ) ;
printf ( L_8 ) ;
}
if ( F_45 ( V_12 ) > 0 ) {
printf ( L_35 ) ;
for ( V_36 = 0 ; V_36 < F_45 ( V_12 ) ; V_36 ++ )
printf ( L_33 , V_47 [ V_36 ] ) ;
printf ( L_8 ) ;
}
if ( V_35 == 2 ) {
V_42 = 0 ;
goto V_56;
}
}
}
if ( V_8 != NULL )
V_10 = F_36 ( V_8 , V_10 ) ;
for (; ; ) {
V_43 = F_42 ( V_9 , ( char * ) V_49 , V_28 ) ;
if ( V_43 <= 0 )
break;
if ( F_41 ( V_10 , ( char * ) V_49 , V_43 ) != V_43 ) {
F_5 ( V_55 , L_23 ) ;
goto V_56;
}
}
if ( ! F_53 ( V_10 ) ) {
F_5 ( V_55 , L_36 ) ;
goto V_56;
}
V_42 = 0 ;
if ( V_30 ) {
F_5 ( V_55 , L_37 V_103 L_8 , F_54 ( V_5 ) ) ;
F_5 ( V_55 , L_38 V_103 L_8 , F_55 ( V_6 ) ) ;
}
V_56:
F_51 ( V_55 ) ;
F_56 ( V_25 ) ;
F_56 ( V_49 ) ;
F_15 ( V_5 ) ;
F_57 ( V_6 ) ;
F_15 ( V_8 ) ;
F_15 ( V_7 ) ;
#ifdef F_2
F_15 ( V_54 ) ;
#endif
F_56 ( V_24 ) ;
return ( V_42 ) ;
}
static void V_64 ( const T_7 * V_104 , void * V_105 )
{
T_1 * V_106 = V_105 ;
static int V_52 ;
if ( ! islower ( ( unsigned char ) * V_104 -> V_104 ) )
return;
F_5 ( V_106 , L_39 , V_104 -> V_104 ) ;
if ( ++ V_52 == 3 ) {
F_5 ( V_106 , L_8 ) ;
V_52 = 0 ;
} else
F_5 ( V_106 , L_40 ) ;
}
static int F_39 ( char * V_5 , unsigned char * V_6 , int V_107 )
{
int V_36 , V_52 ;
unsigned char V_108 ;
V_52 = strlen ( V_5 ) ;
if ( V_52 > ( V_107 * 2 ) ) {
F_5 ( V_55 , L_41 ) ;
return ( 0 ) ;
}
memset ( V_6 , 0 , V_107 ) ;
for ( V_36 = 0 ; V_36 < V_52 ; V_36 ++ ) {
V_108 = ( unsigned char ) * V_5 ;
* ( V_5 ++ ) = '\0' ;
if ( V_108 == 0 )
break;
if ( ! isxdigit ( V_108 ) ) {
F_5 ( V_55 , L_42 ) ;
return ( 0 ) ;
}
V_108 = ( unsigned char ) F_58 ( V_108 ) ;
if ( V_36 & 1 )
V_6 [ V_36 / 2 ] |= V_108 ;
else
V_6 [ V_36 / 2 ] = ( V_108 << 4 ) ;
}
return ( 1 ) ;
}
