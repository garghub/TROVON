static void T_1 F_1 ( void )
{
char V_1 [ 40 ] ;
int V_2 = 0 ;
char V_3 = '\0' , V_4 = '\0' , V_5 = '\0' ;
char * V_6 ;
if ( ( strstr ( F_2 () , L_1 ) ) == NULL ) {
V_6 = F_3 ( L_2 ) ;
if ( V_6 ) {
while ( * V_6 >= '0' && * V_6 <= '9' )
V_2 = V_2 * 10 + * V_6 ++ - '0' ;
if ( * V_6 == ',' )
V_6 ++ ;
if ( * V_6 )
V_3 = * V_6 ++ ;
if ( * V_6 == ',' )
V_6 ++ ;
if ( * V_6 )
V_4 = * V_6 ++ ;
if ( * V_6 == ',' )
V_6 ++ ;
if ( * V_6 == 'h' )
V_5 = 'r' ;
}
if ( V_2 == 0 )
V_2 = 38400 ;
if ( V_3 != 'n' && V_3 != 'o' && V_3 != 'e' )
V_3 = 'n' ;
if ( V_4 != '7' && V_4 != '8' )
V_4 = '8' ;
if ( V_5 == '\0' )
V_5 = 'r' ;
sprintf ( V_1 , L_3 , V_2 ,
V_3 , V_4 , V_5 ) ;
strcat ( F_2 () , V_1 ) ;
F_4 ( L_4 , V_1 ) ;
}
}
static void T_1 F_5 ( void )
{
void * V_7 ;
extern char V_8 ;
V_7 = V_9 ?
( void * ) ( V_10 + 0xa80 ) :
( void * ) ( V_10 + 0x380 ) ;
memcpy ( V_7 , & V_8 , 0x80 ) ;
F_6 ( ( unsigned long ) V_7 , ( unsigned long ) V_7 + 0x80 ) ;
}
static void T_1 F_7 ( void )
{
void * V_7 ;
extern char V_11 ;
V_7 = V_9 ?
( void * ) ( V_10 + 0xa00 ) :
( void * ) ( V_10 + 0x300 ) ;
memcpy ( V_7 , & V_11 , 0x80 ) ;
F_6 ( ( unsigned long ) V_7 , ( unsigned long ) V_7 + 0x80 ) ;
}
void T_1 F_8 ( void )
{
F_9 ( L_5 ) ;
V_12 = ( unsigned long ) F_10 ( V_13 , V_14 ) ;
V_15 = V_16 ;
if ( V_15 == V_17 ) {
if ( V_18 == 0x0001df53 ||
V_18 == 0x0003df53 )
V_15 = V_19 ;
else
V_15 = V_20 ;
}
V_21 = V_22 ;
if ( V_21 == V_23 ) {
switch ( V_15 ) {
case V_24 :
case V_25 :
case V_26 :
case V_27 :
V_21 = V_28 ;
break;
case V_19 :
case V_29 :
case V_30 :
V_21 = V_31 ;
break;
case V_32 :
case V_33 :
case V_34 :
V_21 = V_35 ;
break;
case V_36 :
case V_37 :
case V_38 :
case V_20 :
default:
V_21 = V_39 ;
break;
}
}
switch ( V_21 ) {
T_2 V_40 , V_41 , V_42 , V_43 ;
case V_28 :
V_44 = ( unsigned long ) F_10 ( V_45 , 0x2000 ) ;
#ifdef F_11
F_12 ( V_46 , V_47 |
V_48 ) ;
#else
F_12 ( V_46 , 0 ) ;
#endif
V_40 = F_13 ( V_49 ) ;
V_41 = F_13 ( V_50 ) ;
if ( ( V_40 & V_41 ) != 0 ) {
V_41 &= ~ V_40 ;
F_12 ( V_50 , V_41 ) ;
}
F_14 ( V_51 ) ;
break;
case V_31 :
V_52 = ( unsigned long ) F_10 ( V_53 , V_54 ) ;
V_55 = V_55 &
~ ( V_56 |
V_57 ) ;
#ifdef F_11
V_58 = V_58 &
~ ( V_59 |
V_60 ) ;
#else
V_58 = V_58 |
V_59 |
V_60 ;
#endif
F_14 ( V_61 ) ;
break;
case V_35 :
case V_39 :
V_62 = ( unsigned long ) F_10 ( V_63 , 0x2000 ) ;
V_64:
F_15 () ;
F_16 ( V_65 , V_43 ) ;
F_17 ( V_65 , V_43 & ~ V_66 ) ;
F_18 () ;
#ifdef F_11
F_17 ( V_67 , V_68 ) ;
#else
F_17 ( V_67 ,
V_69 << V_70 |
V_69 << V_71 |
V_69 << V_72 ) ;
#endif
F_16 ( V_73 , V_42 ) ;
F_17 ( V_74 , V_42 & V_75 ) ;
if ( ( V_43 & V_76 ) ==
V_76 )
V_43 = ( V_43 & ~ ( V_76 <<
V_77 ) ) |
( ( V_76 - 1 ) <<
V_77 ) ;
F_18 () ;
F_17 ( V_65 , V_43 ) ;
F_15 () ;
F_14 ( V_78 ) ;
break;
case V_79 :
case V_80 :
V_62 = ( unsigned long ) F_10 ( V_81 , 0x2000 ) ;
goto V_64;
default:
F_9 ( L_6 ) ;
while ( 1 ) ;
}
V_82 = F_5 ;
V_83 = F_7 ;
F_19 () ;
F_20 () ;
#ifdef F_21
F_1 () ;
#endif
if ( F_22 ( V_84 , V_85 ) )
if ( ! F_23 () )
return;
if ( ! F_24 () )
return;
#ifdef F_25
F_26 ( & V_86 ) ;
#endif
}
