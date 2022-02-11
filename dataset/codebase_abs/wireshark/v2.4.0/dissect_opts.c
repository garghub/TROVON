void
F_1 ( void )
{
V_1 . V_2 = V_3 ;
V_1 . V_4 = NULL ;
V_1 . V_5 = NULL ;
V_1 . V_6 = NULL ;
V_1 . V_7 = NULL ;
}
T_1
F_2 ( int V_8 , char * V_9 )
{
char V_10 ;
switch( V_8 ) {
case 'd' :
if ( ! F_3 ( V_9 ) )
return FALSE ;
break;
case 'K' :
#if F_4 ( V_11 ) || F_4 ( V_12 )
F_5 ( V_9 ) ;
#else
F_6 ( L_1 ) ;
return FALSE ;
#endif
break;
case 'n' :
F_7 () ;
break;
case 'N' :
V_10 = F_8 ( V_9 , & V_13 ) ;
if ( V_10 != '\0' ) {
F_6 ( L_2 ,
V_10 ) ;
F_9 ( L_3
L_4
L_5
L_6
L_7
L_8 ) ;
return FALSE ;
}
break;
case 't' :
if ( strcmp ( V_9 , L_9 ) == 0 )
V_1 . V_2 = V_14 ;
else if ( strcmp ( V_9 , L_10 ) == 0 )
V_1 . V_2 = V_15 ;
else if ( strcmp ( V_9 , L_11 ) == 0 )
V_1 . V_2 = V_16 ;
else if ( strcmp ( V_9 , L_12 ) == 0 )
V_1 . V_2 = V_17 ;
else if ( strcmp ( V_9 , L_13 ) == 0 )
V_1 . V_2 = V_18 ;
else if ( strcmp ( V_9 , L_14 ) == 0 )
V_1 . V_2 = V_19 ;
else if ( strcmp ( V_9 , L_15 ) == 0 )
V_1 . V_2 = V_20 ;
else if ( strcmp ( V_9 , L_16 ) == 0 )
V_1 . V_2 = V_21 ;
else if ( strcmp ( V_9 , L_17 ) == 0 )
V_1 . V_2 = V_22 ;
else if ( strcmp ( V_9 , L_18 ) == 0 )
V_1 . V_2 = V_23 ;
else {
F_6 ( L_19 , V_9 ) ;
F_9 ( L_20
L_21
L_22
L_23
L_24
L_25
L_26
L_27
L_28
L_29 ) ;
return FALSE ;
}
break;
case 'u' :
if ( strcmp ( V_9 , L_30 ) == 0 )
F_10 ( V_24 ) ;
else if ( strcmp ( V_9 , L_31 ) == 0 )
F_10 ( V_25 ) ;
else {
F_6 ( L_32 , V_9 ) ;
F_9 ( L_33
L_34 ) ;
return FALSE ;
}
break;
case V_26 :
V_1 . V_4 = F_11 ( V_1 . V_4 , V_9 ) ;
break;
case V_27 :
V_1 . V_6 = F_11 ( V_1 . V_6 , V_9 ) ;
break;
case V_28 :
V_1 . V_7 = F_11 ( V_1 . V_7 , V_9 ) ;
break;
case V_29 :
V_1 . V_5 = F_11 ( V_1 . V_5 , V_9 ) ;
break;
default:
F_12 () ;
}
return TRUE ;
}
T_1
F_13 ( void )
{
T_1 V_30 = TRUE ;
if ( V_1 . V_4 ) {
T_2 * V_31 ;
for ( V_31 = V_1 . V_4 ; V_31 != NULL ; V_31 = F_14 ( V_31 ) )
F_15 ( ( char * ) V_31 -> V_32 ) ;
}
if ( V_1 . V_5 ) {
T_2 * V_33 ;
for ( V_33 = V_1 . V_5 ; V_33 != NULL ; V_33 = F_14 ( V_33 ) )
F_16 ( ( char * ) V_33 -> V_32 ) ;
}
if ( V_1 . V_6 ) {
T_2 * V_34 ;
for ( V_34 = V_1 . V_6 ; V_34 != NULL ; V_34 = F_14 ( V_34 ) ) {
if ( ! F_17 ( ( char * ) V_34 -> V_32 , TRUE ) ) {
F_6 ( L_35 , ( char * ) V_34 -> V_32 ) ;
V_30 = FALSE ;
}
}
}
if ( V_1 . V_7 ) {
T_2 * V_35 ;
for ( V_35 = V_1 . V_7 ; V_35 != NULL ; V_35 = F_14 ( V_35 ) ) {
if ( ! F_17 ( ( char * ) V_35 -> V_32 , FALSE ) ) {
F_6 ( L_36 , ( char * ) V_35 -> V_32 ) ;
V_30 = FALSE ;
}
}
}
return V_30 ;
}
