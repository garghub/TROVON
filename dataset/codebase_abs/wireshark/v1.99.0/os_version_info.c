static char *
F_1 ( T_1 V_1 , T_2 V_2 )
{
T_2 V_3 ;
V_3 = ( T_2 ) F_2 ( ( V_4 ) V_1 ,
( const void * ) V_2 ) ;
if ( V_3 == NULL )
return NULL ;
if ( F_3 ( V_3 ) != F_4 () ) {
return NULL ;
}
return F_5 ( V_3 ) ;
}
static T_3
F_6 ( T_4 * V_5 )
{
static const T_5 V_6 [] =
L_1 ;
static const T_5 V_7 [] =
L_2 ;
T_6 V_8 ;
T_7 V_9 ;
V_4 V_10 ;
char * string ;
V_8 = F_7 ( NULL ,
V_6 , sizeof V_6 - 1 ,
false ) ;
if ( V_8 == NULL )
return FALSE ;
V_9 = F_8 ( NULL ,
V_8 ) ;
F_9 ( V_8 ) ;
if ( V_9 == NULL )
return FALSE ;
if ( ! F_10 ( V_9 ) ) {
F_9 ( V_9 ) ;
V_8 = F_7 ( NULL ,
V_7 , sizeof V_7 - 1 ,
false ) ;
if ( V_8 == NULL )
return FALSE ;
V_9 = F_8 ( NULL ,
V_8 ) ;
F_9 ( V_8 ) ;
if ( V_9 == NULL )
return FALSE ;
if ( ! F_10 ( V_9 ) ) {
F_9 ( V_9 ) ;
return FALSE ;
}
}
#ifdef F_11
V_10 = ( V_4 ) F_12 ( NULL ,
V_9 , 0 , V_11 ,
NULL , NULL ) ;
#else
V_10 = ( V_4 ) F_13 ( NULL ,
V_9 , 0 , V_11 ,
NULL , NULL ) ;
#endif
if ( V_10 == NULL ) {
F_9 ( V_9 ) ;
return FALSE ;
}
if ( F_3 ( V_10 ) != F_14 () ) {
F_9 ( V_10 ) ;
F_15 ( V_9 ) ;
F_9 ( V_9 ) ;
return FALSE ;
}
string = F_1 ( V_10 ,
F_16 ( L_3 ) ) ;
if ( string == NULL ) {
F_9 ( V_10 ) ;
F_15 ( V_9 ) ;
F_9 ( V_9 ) ;
return FALSE ;
}
F_17 ( V_5 , L_4 , string ) ;
F_18 ( string ) ;
string = F_1 ( V_10 ,
F_16 ( L_5 ) ) ;
if ( string == NULL ) {
F_9 ( V_10 ) ;
F_15 ( V_9 ) ;
F_9 ( V_9 ) ;
return FALSE ;
}
F_17 ( V_5 , L_6 , string ) ;
F_18 ( string ) ;
string = F_1 ( V_10 ,
F_16 ( L_7 ) ) ;
if ( string == NULL ) {
F_9 ( V_10 ) ;
F_15 ( V_9 ) ;
F_9 ( V_9 ) ;
return FALSE ;
}
F_17 ( V_5 , L_8 , string ) ;
F_18 ( string ) ;
F_9 ( V_10 ) ;
F_15 ( V_9 ) ;
F_9 ( V_9 ) ;
return TRUE ;
}
void
F_19 ( T_4 * V_5 )
{
#if F_20 ( V_12 )
T_8 V_13 ;
T_9 V_14 ;
T_10 V_15 ;
#elif F_20 ( V_16 )
struct V_17 V_18 ;
#endif
#if F_20 ( V_12 )
memset ( & V_13 , '\0' , sizeof V_13 ) ;
V_13 . V_19 = sizeof V_13 ;
if ( ! F_21 ( ( V_20 * ) & V_13 ) ) {
F_22 ( V_5 , L_9 ) ;
return;
}
memset ( & V_14 , '\0' , sizeof V_14 ) ;
V_15 = ( T_10 ) F_23 ( F_24 ( F_25 ( L_10 ) ) , L_11 ) ;
if( V_15 )
V_15 ( & V_14 ) ;
else
F_26 ( & V_14 ) ;
switch ( V_13 . V_21 ) {
case V_22 :
F_17 ( V_5 , L_12 ) ;
break;
case V_23 :
switch ( V_13 . V_24 ) {
case 4 :
switch ( V_13 . V_25 ) {
case 0 :
F_17 ( V_5 , L_13 ) ;
break;
case 10 :
F_17 ( V_5 , L_14 ) ;
break;
case 90 :
F_17 ( V_5 , L_15 ) ;
break;
default:
F_17 ( V_5 , L_16 ,
V_13 . V_24 , V_13 . V_25 ) ;
break;
}
break;
default:
F_17 ( V_5 , L_16 ,
V_13 . V_24 , V_13 . V_25 ) ;
break;
}
break;
case V_26 :
switch ( V_13 . V_24 ) {
case 3 :
case 4 :
F_17 ( V_5 , L_17 ,
V_13 . V_24 , V_13 . V_25 ) ;
break;
case 5 :
switch ( V_13 . V_25 ) {
case 0 :
F_17 ( V_5 , L_18 ) ;
break;
case 1 :
F_17 ( V_5 , L_19 ) ;
break;
case 2 :
if ( ( V_13 . V_27 == V_28 ) &&
( V_14 . V_29 == V_30 ) ) {
F_17 ( V_5 , L_20 ) ;
} else {
F_17 ( V_5 , L_21 ) ;
if ( V_14 . V_29 == V_30 )
F_17 ( V_5 , L_22 ) ;
}
break;
default:
F_17 ( V_5 , L_23 ,
V_13 . V_24 , V_13 . V_25 ) ;
break;
}
break;
case 6 : {
T_3 V_31 ;
if ( V_14 . V_29 == V_30 )
F_22 ( V_5 , L_24 ) ;
else if ( V_14 . V_29 == V_32 )
F_22 ( V_5 , L_25 ) ;
#ifndef V_28
#define V_28 0x01
V_31 = ( ( V_13 . V_33 [ 1 ] & 0xff ) == V_28 ) ;
#else
V_31 = ( V_13 . V_27 == V_28 ) ;
#endif
switch ( V_13 . V_25 ) {
case 0 :
F_17 ( V_5 , V_31 ? L_26 : L_27 ) ;
break;
case 1 :
F_17 ( V_5 , V_31 ? L_28 : L_29 ) ;
break;
case 2 :
F_17 ( V_5 , V_31 ? L_30 : L_31 ) ;
break;
case 3 :
F_17 ( V_5 , V_31 ? L_32 : L_33 ) ;
break;
default:
F_17 ( V_5 , L_23 ,
V_13 . V_24 , V_13 . V_25 ) ;
break;
}
break;
}
default:
F_17 ( V_5 , L_23 ,
V_13 . V_24 , V_13 . V_25 ) ;
break;
}
break;
default:
F_17 ( V_5 , L_34 ,
V_13 . V_21 , V_13 . V_24 , V_13 . V_25 ) ;
break;
}
if ( V_13 . V_34 [ 0 ] != '\0' )
F_17 ( V_5 , L_6 , F_27 ( V_13 . V_34 ) ) ;
F_17 ( V_5 , L_35 , V_13 . V_35 ) ;
#elif F_20 ( V_16 )
if ( F_28 ( & V_18 ) < 0 ) {
F_17 ( V_5 , L_36 ,
F_29 ( V_36 ) ) ;
return;
}
if ( strcmp ( V_18 . V_37 , L_37 ) == 0 ) {
F_17 ( V_5 , L_38 , V_18 . V_37 , V_18 . V_38 ,
V_18 . V_39 ) ;
} else {
#ifdef F_30
if ( F_6 ( V_5 ) ) {
F_17 ( V_5 , L_39 , V_18 . V_37 , V_18 . V_39 ) ;
} else {
F_17 ( V_5 , L_40 , V_18 . V_37 , V_18 . V_39 ) ;
}
#else
F_17 ( V_5 , L_40 , V_18 . V_37 , V_18 . V_39 ) ;
#endif
}
#else
F_22 ( V_5 , L_41 ) ;
#endif
}
T_11
F_31 ( void )
{
V_20 V_13 ;
V_13 . V_19 = sizeof V_13 ;
if ( F_21 ( & V_13 ) ) {
return V_13 . V_24 ;
}
return 0 ;
}
