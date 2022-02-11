static void
F_1 ( const char * V_1 , T_1 V_2 ,
const char * V_3 , T_2 T_3 V_4 )
{
T_4 V_5 ;
struct V_6 * V_7 ;
const char * V_8 ;
if( ( V_2 & V_9 & V_10 . V_11 ) == 0 &&
V_10 . V_11 != 0 ) {
return;
}
#ifdef F_2
if ( V_10 . V_12 != V_13 || V_2 & V_14 ) {
F_3 () ;
}
if ( F_4 () ) {
#endif
switch( V_2 & V_9 ) {
case V_14 :
V_8 = L_1 ;
break;
case V_15 :
V_8 = L_2 ;
break;
case V_16 :
V_8 = L_3 ;
break;
case V_17 :
V_8 = L_4 ;
break;
case V_18 :
V_8 = L_5 ;
break;
case V_19 :
V_8 = L_6 ;
break;
default:
fprintf ( V_20 , L_7 , V_2 ) ;
V_8 = NULL ;
F_5 () ;
}
time ( & V_5 ) ;
V_7 = localtime ( & V_5 ) ;
if ( V_7 != NULL ) {
fprintf ( V_20 , L_8 ,
V_7 -> V_21 , V_7 -> V_22 , V_7 -> V_23 ,
V_1 != NULL ? V_1 : L_9 ,
V_8 , V_3 ) ;
} else {
fprintf ( V_20 , L_10 ,
V_1 != NULL ? V_1 : L_9 ,
V_8 , V_3 ) ;
}
#ifdef F_2
if( V_2 & V_14 ) {
printf ( L_11 ) ;
F_6 () ;
}
} else {
F_7 ( V_1 , V_2 , V_3 , T_3 ) ;
}
#endif
}
void F_8 ( void )
{
T_1 V_24 ;
V_24 = ( T_1 )
( V_14 |
V_15 |
V_16 |
V_17 |
V_18 |
V_19 |
V_25 |
V_26 ) ;
F_9 ( NULL ,
V_24 ,
F_1 , NULL ) ;
F_9 ( V_27 ,
V_24 ,
F_1 , NULL ) ;
#ifdef F_10
F_9 ( V_28 ,
V_24 ,
F_1 , NULL ) ;
F_9 ( V_29 ,
V_24 ,
F_1 , NULL ) ;
#endif
}
