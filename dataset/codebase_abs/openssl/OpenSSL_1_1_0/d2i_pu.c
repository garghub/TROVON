T_1 * F_1 ( int type , T_1 * * V_1 , const unsigned char * * V_2 ,
long V_3 )
{
T_1 * V_4 ;
if ( ( V_1 == NULL ) || ( * V_1 == NULL ) ) {
if ( ( V_4 = F_2 () ) == NULL ) {
F_3 ( V_5 , V_6 ) ;
return ( NULL ) ;
}
} else
V_4 = * V_1 ;
if ( ! F_4 ( V_4 , type ) ) {
F_3 ( V_5 , V_6 ) ;
goto V_7;
}
switch ( F_5 ( V_4 ) ) {
#ifndef F_6
case V_8 :
if ( ( V_4 -> V_9 . V_10 = F_7 ( NULL , V_2 , V_3 ) ) == NULL ) {
F_3 ( V_5 , V_11 ) ;
goto V_7;
}
break;
#endif
#ifndef F_8
case V_12 :
if ( ! F_9 ( & V_4 -> V_9 . V_13 , V_2 , V_3 ) ) {
F_3 ( V_5 , V_11 ) ;
goto V_7;
}
break;
#endif
#ifndef F_10
case V_14 :
if ( ! F_11 ( & V_4 -> V_9 . V_15 , V_2 , V_3 ) ) {
F_3 ( V_5 , V_11 ) ;
goto V_7;
}
break;
#endif
default:
F_3 ( V_5 , V_16 ) ;
goto V_7;
}
if ( V_1 != NULL )
( * V_1 ) = V_4 ;
return ( V_4 ) ;
V_7:
if ( V_1 == NULL || * V_1 != V_4 )
F_12 ( V_4 ) ;
return ( NULL ) ;
}
