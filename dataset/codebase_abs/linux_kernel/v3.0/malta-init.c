char * F_1 ( char * V_1 )
{
int V_2 , V_3 = 0 ;
V_2 = strlen ( V_1 ) ;
while ( F_2 ( V_3 ) ) {
if( strncmp ( V_1 , F_2 ( V_3 ) , V_2 ) == 0 ) {
return ( F_2 ( V_3 + 1 ) ) ;
}
V_3 += 2 ;
}
return NULL ;
}
static inline unsigned char F_3 ( unsigned char V_4 )
{
if ( V_4 >= '0' && V_4 <= '9' )
return V_4 - '0' ;
if ( V_4 >= 'a' && V_4 <= 'f' )
return V_4 - 'a' + 10 ;
return 0 ;
}
static inline void F_4 ( unsigned char * V_5 , unsigned char * V_6 )
{
int V_2 ;
for ( V_2 = 0 ; V_2 < 6 ; V_2 ++ ) {
unsigned char V_7 ;
if( ( * V_6 == '.' ) || ( * V_6 == ':' ) )
V_6 ++ ;
V_7 = F_3 ( * V_6 ++ ) << 4 ;
V_7 |= ( F_3 ( * V_6 ++ ) ) ;
V_5 [ V_2 ] = V_7 ;
}
}
int F_5 ( char * V_8 )
{
char * V_9 ;
V_9 = F_1 ( L_1 ) ;
if ( ! V_9 ) {
F_6 ( L_2 ) ;
return - 1 ;
}
F_4 ( V_8 , V_9 ) ;
if ( V_10 > 1 ) {
int V_2 ;
F_6 ( L_3 ) ;
for ( V_2 = 0 ; V_2 < 5 ; V_2 ++ )
F_6 ( L_4 , ( unsigned char ) * ( V_8 + V_2 ) ) ;
F_6 ( L_5 , * ( V_8 + V_2 ) ) ;
}
return 0 ;
}
static void T_1 F_7 ( void )
{
char V_11 [ 40 ] ;
int V_12 = 0 ;
char V_13 = '\0' , V_14 = '\0' , V_15 = '\0' ;
char * V_16 ;
if ( ( strstr ( F_8 () , L_6 ) ) == NULL ) {
V_16 = F_1 ( L_7 ) ;
if ( V_16 ) {
while ( * V_16 >= '0' && * V_16 <= '9' )
V_12 = V_12 * 10 + * V_16 ++ - '0' ;
if ( * V_16 == ',' ) V_16 ++ ;
if ( * V_16 ) V_13 = * V_16 ++ ;
if ( * V_16 == ',' ) V_16 ++ ;
if ( * V_16 ) V_14 = * V_16 ++ ;
if ( * V_16 == ',' ) V_16 ++ ;
if ( * V_16 == 'h' ) V_15 = 'r' ;
}
if ( V_12 == 0 )
V_12 = 38400 ;
if ( V_13 != 'n' && V_13 != 'o' && V_13 != 'e' )
V_13 = 'n' ;
if ( V_14 != '7' && V_14 != '8' )
V_14 = '8' ;
if ( V_15 == '\0' )
V_15 = 'r' ;
sprintf ( V_11 , L_8 , V_12 , V_13 , V_14 , V_15 ) ;
strcat ( F_8 () , V_11 ) ;
F_9 ( L_9 , V_11 ) ;
}
}
static void T_1 F_10 ( void )
{
void * V_17 ;
extern char V_18 ;
V_17 = V_19 ?
( void * ) ( V_20 + 0xa80 ) :
( void * ) ( V_20 + 0x380 ) ;
memcpy ( V_17 , & V_18 , 0x80 ) ;
F_11 ( ( unsigned long ) V_17 , ( unsigned long ) V_17 + 0x80 ) ;
}
static void T_1 F_12 ( void )
{
void * V_17 ;
extern char V_21 ;
V_17 = V_19 ?
( void * ) ( V_20 + 0xa00 ) :
( void * ) ( V_20 + 0x300 ) ;
memcpy ( V_17 , & V_21 , 0x80 ) ;
F_11 ( ( unsigned long ) V_17 , ( unsigned long ) V_17 + 0x80 ) ;
}
void T_1 F_13 ( void )
{
V_22 = V_23 ;
V_24 = ( int * ) V_25 ;
V_26 = ( int * ) V_27 ;
F_14 ( L_10 ) ;
V_28 = ( unsigned long ) F_15 ( V_29 , V_30 ) ;
V_31 = V_32 ;
if ( V_31 == V_33 ) {
if ( V_34 == 0x0001df53 ||
V_34 == 0x0003df53 )
V_31 = V_35 ;
else
V_31 = V_36 ;
}
V_37 = V_38 ;
if ( V_37 == V_39 ) {
switch ( V_31 ) {
case V_40 :
case V_41 :
case V_42 :
case V_43 :
V_37 = V_44 ;
break;
case V_35 :
case V_45 :
case V_46 :
V_37 = V_47 ;
break;
case V_48 :
case V_49 :
case V_50 :
V_37 = V_51 ;
break;
case V_52 :
case V_53 :
case V_54 :
case V_36 :
default:
V_37 = V_55 ;
break;
}
}
switch ( V_37 ) {
T_2 V_56 , V_57 , V_58 , V_59 ;
case V_44 :
V_60 = ( unsigned long ) F_15 ( V_61 , 0x2000 ) ;
#ifdef F_16
F_17 ( V_62 , V_63 |
V_64 ) ;
#else
F_17 ( V_62 , 0 ) ;
#endif
V_56 = F_18 ( V_65 ) ;
V_57 = F_18 ( V_66 ) ;
if ( ( V_56 & V_57 ) != 0 ) {
V_57 &= ~ V_56 ;
F_17 ( V_66 , V_57 ) ;
}
F_19 ( V_67 ) ;
break;
case V_47 :
V_68 = ( unsigned long ) F_15 ( V_69 , V_70 ) ;
V_71 = V_71 &
~ ( V_72 |
V_73 ) ;
#ifdef F_16
V_74 = V_74 &
~ ( V_75 |
V_76 ) ;
#else
V_74 = V_74 |
V_75 |
V_76 ;
#endif
F_19 ( V_77 ) ;
break;
case V_51 :
case V_55 :
V_78 = ( unsigned long ) F_15 ( V_79 , 0x2000 ) ;
V_80:
F_20 () ;
F_21 ( V_81 , V_59 ) ;
F_22 ( V_81 , V_59 & ~ V_82 ) ;
F_23 () ;
#ifdef F_16
F_22 ( V_83 , V_84 ) ;
#else
F_22 ( V_83 ,
V_85 << V_86 |
V_85 << V_87 |
V_85 << V_88 ) ;
#endif
F_21 ( V_89 , V_58 ) ;
F_22 ( V_90 , V_58 & V_91 ) ;
if ( ( V_59 & V_92 ) ==
V_92 )
V_59 = ( V_59 & ~ ( V_92 <<
V_93 ) ) |
( ( V_92 - 1 ) <<
V_93 ) ;
F_23 () ;
F_22 ( V_81 , V_59 ) ;
F_20 () ;
F_19 ( V_94 ) ;
break;
case V_95 :
case V_96 :
V_78 = ( unsigned long ) F_15 ( V_97 , 0x2000 ) ;
goto V_80;
default:
F_14 ( L_11 ) ;
while ( 1 ) ;
}
V_98 = F_10 ;
V_99 = F_12 ;
F_24 () ;
F_25 () ;
#ifdef F_26
F_7 () ;
#endif
#ifdef F_27
if ( F_28 ( V_100 , V_101 ) )
F_29 ( & V_102 ) ;
else
#endif
#ifdef F_30
F_29 ( & V_103 ) ;
#endif
#ifdef F_31
F_29 ( & V_104 ) ;
#endif
}
