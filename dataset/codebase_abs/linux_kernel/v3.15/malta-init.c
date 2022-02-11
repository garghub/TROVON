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
T_2 F_9 ( void )
{
return V_12 ;
}
void T_1 F_10 ( void )
{
F_11 ( L_7 ) ;
V_13 = ( unsigned long ) F_12 ( V_14 , V_15 ) ;
V_16 = V_17 ;
if ( V_16 == V_18 ) {
if ( V_19 == 0x0001df53 ||
V_19 == 0x0003df53 )
V_16 = V_20 ;
else
V_16 = V_21 ;
}
V_22 = V_23 ;
if ( V_22 == V_24 ) {
switch ( V_16 ) {
case V_25 :
case V_26 :
case V_27 :
case V_28 :
V_22 = V_29 ;
break;
case V_20 :
case V_30 :
case V_31 :
V_22 = V_32 ;
break;
case V_33 :
case V_34 :
case V_35 :
V_22 = V_36 ;
break;
case V_37 :
case V_38 :
case V_39 :
case V_21 :
default:
V_22 = V_40 ;
break;
}
}
switch ( V_22 ) {
T_3 V_41 , V_42 , V_43 , V_44 ;
case V_29 :
V_45 = ( unsigned long ) F_12 ( V_46 , 0x2000 ) ;
#ifdef F_13
F_14 ( V_47 , V_48 |
V_49 ) ;
#else
F_14 ( V_47 , 0 ) ;
#endif
V_41 = F_15 ( V_50 ) ;
V_42 = F_15 ( V_51 ) ;
if ( ( V_41 & V_42 ) != 0 ) {
V_42 &= ~ V_41 ;
F_14 ( V_51 , V_42 ) ;
}
F_16 ( V_52 ) ;
break;
case V_32 :
V_53 = ( unsigned long ) F_12 ( V_54 , V_55 ) ;
V_56 = V_56 &
~ ( V_57 |
V_58 ) ;
#ifdef F_13
V_59 = V_59 &
~ ( V_60 |
V_61 ) ;
#else
V_59 = V_59 |
V_60 |
V_61 ;
#endif
F_16 ( V_62 ) ;
break;
case V_36 :
case V_40 :
V_63 = ( unsigned long ) F_12 ( V_64 , 0x2000 ) ;
V_65:
F_17 () ;
F_18 ( V_66 , V_44 ) ;
F_19 ( V_66 , V_44 & ~ V_67 ) ;
F_20 () ;
#ifdef F_13
F_19 ( V_68 , V_69 ) ;
#else
F_19 ( V_68 ,
V_70 << V_71 |
V_70 << V_72 |
V_70 << V_73 ) ;
#endif
#ifndef F_21
F_18 ( V_74 , V_43 ) ;
F_19 ( V_75 , V_43 & V_76 ) ;
#else
V_43 = V_77 | ( 1 << 3 ) ;
F_19 ( V_74 , V_43 ) ;
V_43 = V_77 ;
F_19 ( V_78 , V_43 ) ;
F_19 ( V_75 , V_43 ) ;
F_19 ( V_79 , V_43 ) ;
#endif
if ( ( V_44 & V_80 ) ==
V_80 )
V_44 = ( V_44 & ~ ( V_80 <<
V_81 ) ) |
( ( V_80 - 1 ) <<
V_81 ) ;
F_20 () ;
F_19 ( V_66 , V_44 ) ;
F_17 () ;
F_16 ( V_82 ) ;
break;
case V_83 :
case V_84 :
V_63 = ( unsigned long ) F_12 ( V_85 , 0x2000 ) ;
goto V_65;
default:
F_11 ( L_8 ) ;
while ( 1 ) ;
}
V_86 = F_6 ;
V_87 = F_8 ;
F_22 () ;
F_23 () ;
#ifdef F_24
F_1 () ;
#endif
F_25 () ;
F_26 () ;
if ( ! F_27 () )
return;
if ( ! F_28 () )
return;
if ( ! F_29 () )
return;
#ifdef F_30
F_31 ( & V_88 ) ;
#endif
}
