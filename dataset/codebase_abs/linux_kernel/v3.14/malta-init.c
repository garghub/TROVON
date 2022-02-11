static void T_1 F_1 ( void )
{
char V_1 [ 40 ] ;
int V_2 = 0 ;
char V_3 = '\0' , V_4 = '\0' , V_5 = '\0' ;
char * V_6 ;
V_6 = F_2 ( L_1 ) ;
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
if ( ( strstr ( F_3 () , L_2 ) ) == NULL ) {
sprintf ( V_1 , L_3 , V_2 ,
V_3 , V_4 ) ;
F_4 ( V_1 ) ;
}
if ( ( strstr ( F_3 () , L_4 ) ) == NULL ) {
sprintf ( V_1 , L_5 , V_2 ,
V_3 , V_4 , V_5 ) ;
strcat ( F_3 () , V_1 ) ;
F_5 ( L_6 , V_1 ) ;
}
}
static void T_1 F_6 ( void )
{
void * V_7 ;
extern char V_8 ;
V_7 = V_9 ?
( void * ) ( V_10 + 0xa80 ) :
( void * ) ( V_10 + 0x380 ) ;
memcpy ( V_7 , & V_8 , 0x80 ) ;
F_7 ( ( unsigned long ) V_7 , ( unsigned long ) V_7 + 0x80 ) ;
}
static void T_1 F_8 ( void )
{
void * V_7 ;
extern char V_11 ;
V_7 = V_9 ?
( void * ) ( V_10 + 0xa00 ) :
( void * ) ( V_10 + 0x300 ) ;
memcpy ( V_7 , & V_11 , 0x80 ) ;
F_7 ( ( unsigned long ) V_7 , ( unsigned long ) V_7 + 0x80 ) ;
}
void T_1 F_9 ( void )
{
F_10 ( L_7 ) ;
V_12 = ( unsigned long ) F_11 ( V_13 , V_14 ) ;
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
V_44 = ( unsigned long ) F_11 ( V_45 , 0x2000 ) ;
#ifdef F_12
F_13 ( V_46 , V_47 |
V_48 ) ;
#else
F_13 ( V_46 , 0 ) ;
#endif
V_40 = F_14 ( V_49 ) ;
V_41 = F_14 ( V_50 ) ;
if ( ( V_40 & V_41 ) != 0 ) {
V_41 &= ~ V_40 ;
F_13 ( V_50 , V_41 ) ;
}
F_15 ( V_51 ) ;
break;
case V_31 :
V_52 = ( unsigned long ) F_11 ( V_53 , V_54 ) ;
V_55 = V_55 &
~ ( V_56 |
V_57 ) ;
#ifdef F_12
V_58 = V_58 &
~ ( V_59 |
V_60 ) ;
#else
V_58 = V_58 |
V_59 |
V_60 ;
#endif
F_15 ( V_61 ) ;
break;
case V_35 :
case V_39 :
V_62 = ( unsigned long ) F_11 ( V_63 , 0x2000 ) ;
V_64:
F_16 () ;
F_17 ( V_65 , V_43 ) ;
F_18 ( V_65 , V_43 & ~ V_66 ) ;
F_19 () ;
#ifdef F_12
F_18 ( V_67 , V_68 ) ;
#else
F_18 ( V_67 ,
V_69 << V_70 |
V_69 << V_71 |
V_69 << V_72 ) ;
#endif
F_17 ( V_73 , V_42 ) ;
F_18 ( V_74 , V_42 & V_75 ) ;
if ( ( V_43 & V_76 ) ==
V_76 )
V_43 = ( V_43 & ~ ( V_76 <<
V_77 ) ) |
( ( V_76 - 1 ) <<
V_77 ) ;
F_19 () ;
F_18 ( V_65 , V_43 ) ;
F_16 () ;
F_15 ( V_78 ) ;
break;
case V_79 :
case V_80 :
V_62 = ( unsigned long ) F_11 ( V_81 , 0x2000 ) ;
goto V_64;
default:
F_10 ( L_8 ) ;
while ( 1 ) ;
}
V_82 = F_6 ;
V_83 = F_8 ;
F_20 () ;
F_21 () ;
#ifdef F_22
F_1 () ;
#endif
if ( F_23 ( V_84 , V_85 ) )
if ( ! F_24 () )
return;
if ( ! F_25 () )
return;
#ifdef F_26
F_27 ( & V_86 ) ;
#endif
}
