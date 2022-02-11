static T_1
F_1 ( T_2 * V_1 , const T_2 * V_2 ,
void * T_3 V_3 , T_4 T_5 V_3 )
{
if ( strcmp ( V_1 , V_4 ) == 0 ) {
if ( V_5 )
F_2 ( V_5 ) ;
if ( ! V_2 || ( V_2 && ! * V_2 ) )
V_5 = F_3 ( L_1 ) ;
else
V_5 = F_3 ( V_2 ) ;
}
return V_6 ;
}
void
F_4 ( void )
{
char * V_7 ;
T_6 * V_8 ;
V_7 = F_5 ( V_9 , FALSE ) ;
if ( ( V_8 = F_6 ( V_7 , L_2 ) ) != NULL ) {
F_7 ( V_7 , V_8 , F_1 , NULL ) ;
fclose ( V_8 ) ;
}
F_2 ( V_7 ) ;
}
T_4
F_8 ( void )
{
char * V_10 ;
char * V_7 ;
T_6 * V_8 ;
if ( F_9 ( & V_10 ) == - 1 ) {
F_10 ( V_11 , V_12 ,
L_3 , V_10 ,
F_11 ( V_13 ) ) ;
F_2 ( V_10 ) ;
return FALSE ;
}
V_7 = F_5 ( V_9 , FALSE ) ;
if ( ( V_8 = F_6 ( V_7 , L_4 ) ) == NULL ) {
F_10 ( V_11 , V_12 ,
L_5 , V_7 ,
F_11 ( V_13 ) ) ;
F_2 ( V_7 ) ;
return FALSE ;
}
F_2 ( V_7 ) ;
fputs ( L_6 V_14 L_7
L_8
L_9
L_10
L_11 , V_8 ) ;
fprintf ( V_8 , V_4 L_12 , V_5 ) ;
fclose ( V_8 ) ;
return TRUE ;
}
