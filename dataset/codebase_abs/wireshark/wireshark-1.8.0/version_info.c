static void
F_1 ( T_1 * V_1 )
{
T_2 V_2 ;
char * V_3 , * V_4 ;
V_2 = V_1 -> V_5 ;
if ( V_2 == 0 || V_1 -> V_1 [ V_2 - 1 ] != '\n' )
F_2 ( V_1 , L_1 ) ;
V_3 = V_1 -> V_1 ;
while ( * V_3 != '\0' ) {
V_4 = strchr ( V_3 , '\n' ) ;
if ( V_4 - V_3 > 80 ) {
V_4 = V_3 + 80 ;
while ( V_4 > V_3 && * V_4 != ' ' )
V_4 -- ;
if ( V_4 != V_3 )
* V_4 = '\n' ;
}
V_3 = V_4 + 1 ;
}
}
void
F_3 ( T_1 * V_1 , void (* F_4)( T_1 * ) ,
void (* F_5)( T_1 * ) )
{
if ( sizeof( V_1 ) == 4 )
F_2 ( V_1 , L_2 ) ;
else
F_2 ( V_1 , L_3 ) ;
if ( F_4 )
(* F_4)( V_1 ) ;
F_2 ( V_1 , L_4 ) ;
F_6 ( V_1 ,
#ifdef F_7
L_5 , F_7 , V_6 ,
V_7 ) ;
#else
L_6 ) ;
void F_8 ( T_1 * V_1 )
{
#if F_9 ( V_8 )
T_3 V_9 ;
T_4 V_10 ;
T_5 V_11 ;
#elif F_9 ( V_12 )
struct V_13 V_14 ;
#endif
#if V_15
T_6 V_16 , V_17 , V_18 , V_19 ;
#endif
#if F_9 ( V_8 )
memset ( & V_9 , '\0' , sizeof V_9 ) ;
V_9 . V_20 = sizeof V_9 ;
if ( ! F_10 ( ( V_21 * ) & V_9 ) ) {
F_2 ( V_1 , L_7 ) ;
return;
}
memset ( & V_10 , '\0' , sizeof V_10 ) ;
V_11 = ( T_5 ) F_11 ( F_12 ( F_13 ( L_8 ) ) , L_9 ) ;
if( V_11 )
V_11 ( & V_10 ) ;
else
F_14 ( & V_10 ) ;
switch ( V_9 . V_22 ) {
case V_23 :
F_6 ( V_1 , L_10 ) ;
break;
case V_24 :
switch ( V_9 . V_25 ) {
case 4 :
switch ( V_9 . V_26 ) {
case 0 :
F_6 ( V_1 , L_11 ) ;
break;
case 10 :
F_6 ( V_1 , L_12 ) ;
break;
case 90 :
F_6 ( V_1 , L_13 ) ;
break;
default:
F_6 ( V_1 , L_14 ,
V_9 . V_25 , V_9 . V_26 ) ;
break;
}
break;
default:
F_6 ( V_1 , L_14 ,
V_9 . V_25 , V_9 . V_26 ) ;
break;
}
break;
case V_27 :
switch ( V_9 . V_25 ) {
case 3 :
case 4 :
F_6 ( V_1 , L_15 ,
V_9 . V_25 , V_9 . V_26 ) ;
break;
case 5 :
switch ( V_9 . V_26 ) {
case 0 :
F_6 ( V_1 , L_16 ) ;
break;
case 1 :
F_6 ( V_1 , L_17 ) ;
break;
case 2 :
if ( ( V_9 . V_28 == V_29 ) &&
( V_10 . V_30 == V_31 ) ) {
F_6 ( V_1 , L_18 ) ;
} else {
F_6 ( V_1 , L_19 ) ;
if ( V_10 . V_30 == V_31 )
F_6 ( V_1 , L_20 ) ;
}
break;
default:
F_6 ( V_1 , L_21 ,
V_9 . V_25 , V_9 . V_26 ) ;
break;
}
break;
case 6 : {
T_7 V_32 ;
if ( V_10 . V_30 == V_31 )
F_2 ( V_1 , L_22 ) ;
else if ( V_10 . V_30 == V_33 )
F_2 ( V_1 , L_23 ) ;
#ifndef V_29
#define V_29 0x01
V_32 = ( ( V_9 . V_34 [ 1 ] & 0xff ) == V_29 ) ;
#else
V_32 = ( V_9 . V_28 == V_29 ) ;
#endif
switch ( V_9 . V_26 ) {
case 0 :
F_6 ( V_1 , V_32 ? L_24 : L_25 ) ;
break;
case 1 :
F_6 ( V_1 , V_32 ? L_26 : L_27 ) ;
break;
default:
F_6 ( V_1 , L_21 ,
V_9 . V_25 , V_9 . V_26 ) ;
break;
}
break;
}
default:
F_6 ( V_1 , L_21 ,
V_9 . V_25 , V_9 . V_26 ) ;
break;
}
break;
default:
F_6 ( V_1 , L_28 ,
V_9 . V_22 , V_9 . V_25 , V_9 . V_26 ) ;
break;
}
if ( V_9 . V_35 [ 0 ] != '\0' )
F_6 ( V_1 , L_29 , F_15 ( V_9 . V_35 ) ) ;
F_6 ( V_1 , L_30 , V_9 . V_36 ) ;
#elif F_9 ( V_12 )
if ( F_16 ( & V_14 ) < 0 ) {
F_6 ( V_1 , L_31 ,
F_17 ( V_37 ) ) ;
return;
}
if ( strcmp ( V_14 . V_38 , L_32 ) == 0 ) {
F_6 ( V_1 , L_33 , V_14 . V_38 , V_14 . V_39 ,
V_14 . V_40 ) ;
} else {
#ifdef V_15
F_18 ( V_41 , & V_16 ) ;
if( V_16 >= 0x1040 ) {
F_18 ( V_42 , & V_17 ) ;
F_18 ( V_43 , & V_18 ) ;
F_18 ( V_44 , & V_19 ) ;
F_6 ( V_1 , L_34 ,
( long ) V_17 ,
( long ) V_18 ,
( long ) V_19 ) ;
} else {
F_6 ( V_1 , L_35 ,
( long ) V_16 ) ;
}
F_6 ( V_1 , L_36 , V_14 . V_38 , V_14 . V_40 ) ;
#else
F_6 ( V_1 , L_37 , V_14 . V_38 , V_14 . V_40 ) ;
#endif
}
#else
F_2 ( V_1 , L_38 ) ;
#endif
}
void
F_19 ( T_1 * V_1 , void (* F_20)( T_1 * ) )
{
#ifndef V_8
T_8 * V_45 ;
#endif
F_2 ( V_1 , L_39 ) ;
F_8 ( V_1 ) ;
#ifndef V_8
if ( ( V_45 = getenv ( L_40 ) ) != NULL )
F_6 ( V_1 , L_41 , V_45 ) ;
else
F_2 ( V_1 , L_42 ) ;
#endif
F_2 ( V_1 , L_43 ) ;
F_21 ( V_1 ) ;
#if F_9 ( V_46 ) && ! F_9 ( V_8 )
F_6 ( V_1 , L_44 , F_22 () ) ;
#endif
if ( F_20 )
(* F_20)( V_1 ) ;
F_2 ( V_1 , L_45 ) ;
#if F_9 ( V_47 ) && F_9 ( V_48 )
#if F_9 ( V_49 )
F_6 ( V_1 , L_46 , V_48 ) ;
#elif F_9 ( V_50 )
F_6 ( V_1 , L_47 , V_48 ) ;
#else
F_6 ( V_1 , L_48 , V_48 ) ;
#endif
#elif F_9 ( V_51 )
F_6 ( V_1 , L_49 , V_51 ) ;
#elif F_9 ( V_52 )
F_6 ( V_1 , L_50 ,
( V_52 >> 8 ) & 0xFF , V_52 & 0xFF ) ;
#ifdef F_23
if ( ( F_23 % 10 ) != 0 )
F_6 ( V_1 , L_51 , F_23 % 10 ) ;
#endif
F_6 ( V_1 , L_1 ) ;
#elif F_9 ( V_53 )
F_6 ( V_1 , L_52 ,
V_53 / 100 , ( V_53 / 10 ) % 10 ) ;
if ( ( V_53 % 10 ) != 0 )
F_6 ( V_1 , L_51 , V_53 % 10 ) ;
#ifdef F_24
F_25 ( V_1 , L_53 ,
F_24 / 10000 ,
( F_24 / 100 ) % 100 ,
F_24 % 100 ) ;
#endif
F_6 ( V_1 , L_1 ) ;
#elif F_9 ( V_54 )
# if V_54 > 99999999
F_6 ( V_1 , L_54 ,
( V_54 / 10000000 ) - 6 ,
( V_54 / 100000 ) % 100 ) ;
# if ( V_54 % 100000 ) != 0
F_6 ( V_1 , L_55 ,
V_54 % 100000 ) ;
# endif
# else
F_6 ( V_1 , L_54 ,
( V_54 / 1000000 ) - 6 ,
( V_54 / 10000 ) % 100 ) ;
# if ( V_54 % 10000 ) != 0
F_6 ( V_1 , L_55 ,
V_54 % 10000 ) ;
# endif
# endif
F_6 ( V_1 , L_1 ) ;
#elif F_9 ( V_55 )
F_6 ( V_1 , L_56 ,
( V_55 / 100 ) - 6 , V_55 % 100 ) ;
#elif F_9 ( V_56 )
F_6 ( V_1 , L_57 ,
( V_56 >> 8 ) & 0xF , ( V_56 >> 4 ) & 0xF ) ;
if ( ( V_56 & 0xF ) != 0 )
F_6 ( V_1 , L_51 , V_56 & 0xF ) ;
F_6 ( V_1 , L_1 ) ;
#endif
F_1 ( V_1 ) ;
}
const char *
F_26 ( void )
{
return
L_58
L_59
L_60 ;
}
T_9
F_27 ()
{
V_21 V_9 ;
V_9 . V_20 = sizeof V_9 ;
if ( F_10 ( & V_9 ) ) {
return V_9 . V_25 ;
}
return 0 ;
}
