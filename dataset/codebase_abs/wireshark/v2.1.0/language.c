static T_1
F_1 ( T_2 * V_1 , const T_2 * V_2 ,
void * T_3 V_3 , T_4 T_5 V_3 )
{
if ( strcmp ( V_1 , V_4 ) == 0 ) {
if ( V_5 )
F_2 ( V_5 ) ;
if ( ! V_2 || ! * V_2 || strcmp ( V_2 , L_1 ) == 0 ||
strcmp ( V_2 , L_2 ) == 0 )
V_5 = F_3 ( V_6 ) ;
else
V_5 = F_3 ( V_2 ) ;
}
return V_7 ;
}
void
F_4 ( void )
{
char * V_8 ;
T_6 * V_9 ;
V_8 = F_5 ( V_10 , FALSE ) ;
if ( ( V_9 = F_6 ( V_8 , L_3 ) ) != NULL ) {
F_7 ( V_8 , V_9 , F_1 , NULL ) ;
fclose ( V_9 ) ;
}
F_2 ( V_8 ) ;
}
T_4
F_8 ( void )
{
char * V_11 ;
char * V_8 ;
T_6 * V_9 ;
if ( F_9 ( & V_11 ) == - 1 ) {
F_10 ( V_12 , V_13 ,
L_4 , V_11 ,
F_11 ( V_14 ) ) ;
F_2 ( V_11 ) ;
return FALSE ;
}
V_8 = F_5 ( V_10 , FALSE ) ;
if ( ( V_9 = F_6 ( V_8 , L_5 ) ) == NULL ) {
F_10 ( V_12 , V_13 ,
L_6 , V_8 ,
F_11 ( V_14 ) ) ;
F_2 ( V_8 ) ;
return FALSE ;
}
F_2 ( V_8 ) ;
fputs ( L_7 V_15 L_8
L_9
L_10
L_11
L_12 , V_9 ) ;
fprintf ( V_9 , V_4 L_13 , V_5 ? V_5 : V_6 ) ;
fclose ( V_9 ) ;
return TRUE ;
}
