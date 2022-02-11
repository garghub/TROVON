void F_1 ( void )
{
struct V_1 * V_2 ;
void T_1 * V_3 ;
V_2 = F_2 ( NULL , NULL , L_1 ) ;
if ( ! V_2 ) {
F_3 ( L_2 ) ;
return;
}
V_3 = F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
if ( ! V_3 ) {
F_3 ( L_3 ) ;
return;
}
F_6 ( 0x01 , V_3 ) ;
F_7 ( V_3 ) ;
}
void F_8 ( void )
{
struct V_1 * V_2 ;
void T_1 * V_3 ;
V_2 = F_2 ( NULL , NULL , L_4 ) ;
if ( ! V_2 ) {
F_3 ( L_5 ) ;
return;
}
V_3 = F_4 ( V_2 , 0 ) ;
F_5 ( V_2 ) ;
if ( ! V_3 ) {
F_3 ( L_3 ) ;
return;
}
if ( ! V_4 ) {
F_3 ( L_6 ) ;
goto exit;
}
F_6 ( V_5 , ( V_4 +
V_6 ) ) ;
F_6 ( V_7 , V_4 +
V_8 ) ;
F_6 ( V_9 , V_3 +
V_10 ) ;
exit:
F_7 ( V_3 ) ;
}
