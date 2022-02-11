static void
F_1 ( T_1 * V_1 )
{
int V_2 ;
char * V_3 , * V_4 , * V_5 ;
int V_6 ;
V_2 = F_2 ( & V_3 , L_1 , NULL ) ;
V_4 = F_3 ( V_3 ) ;
V_5 = F_4 ( L_2 , V_7 . V_8 ) ;
V_6 = F_5 ( V_1 , V_2 , V_5 ) ;
if ( V_6 != 0 ) {
F_6 ( V_5 ) ;
F_7 ( V_4 ? V_4 : L_3 ,
V_6 , V_9 ) ;
goto V_10;
}
F_8 ( & V_7 ) ;
V_6 = F_9 ( V_1 ) ;
if ( V_6 != 0 ) {
F_10 ( V_4 , V_6 ) ;
}
if ( F_11 ( & V_7 , V_4 , V_11 , TRUE , & V_6 ) != V_12 ) {
goto V_10;
}
switch ( F_12 ( & V_7 , FALSE ) ) {
case V_13 :
case V_14 :
break;
case V_15 :
break;
}
V_10:
F_6 ( V_4 ) ;
}
T_2
F_13 ( const char * V_16 , T_3 * V_17 , T_1 * V_1 )
{
char * error ;
error = F_14 ( V_17 , V_16 , V_1 ) ;
if ( error ) {
F_15 ( V_18 , V_19 , L_4 , error ) ;
F_6 ( error ) ;
return FALSE ;
}
F_1 ( V_1 ) ;
return TRUE ;
}
