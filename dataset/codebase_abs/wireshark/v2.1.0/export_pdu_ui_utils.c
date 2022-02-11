static void
F_1 ( T_1 * V_1 )
{
int V_2 ;
char * V_3 , * V_4 ;
int V_5 ;
V_2 = F_2 ( & V_3 , L_1 , NULL ) ;
V_4 = F_3 ( V_3 ) ;
V_5 = F_4 ( V_1 , V_2 ,
F_5 ( L_2 , V_6 . V_7 ) ) ;
if ( V_5 != 0 ) {
F_6 ( V_4 ? V_4 : L_3 , V_5 , TRUE ) ;
goto V_8;
}
F_7 ( & V_6 ) ;
V_5 = F_8 ( V_1 ) ;
if ( V_5 != 0 ) {
F_9 ( V_4 , V_5 ) ;
}
if ( F_10 ( & V_6 , V_4 , V_9 , TRUE , & V_5 ) != V_10 ) {
F_6 ( V_4 , V_5 , FALSE ) ;
goto V_8;
}
switch ( F_11 ( & V_6 , FALSE ) ) {
case V_11 :
case V_12 :
break;
case V_13 :
break;
}
V_8:
F_12 ( V_4 ) ;
}
T_2
F_13 ( const char * V_14 , T_3 * V_15 , T_1 * V_1 )
{
char * error ;
error = F_14 ( V_15 , V_14 , V_1 ) ;
if ( error ) {
F_15 ( V_16 , V_17 , L_4 , error ) ;
F_12 ( error ) ;
return FALSE ;
}
F_1 ( V_1 ) ;
return TRUE ;
}
