static void F_1 ( T_1 * V_1 , T_2 * V_2 ,
T_3 * V_3 )
{
T_4 V_4 = 0 ;
struct V_5 * V_6 ;
T_1 * V_7 ;
T_5 V_8 = FALSE ;
T_6 V_9 = F_2 ( L_1 ) ;
if ( ! V_9 ) {
return;
}
if ( ( V_10 ) F_3 ( V_1 , V_4 ) < ( 3 + 2 ) ) {
return;
}
V_6 = (struct V_5 * ) F_4 ( F_5 () , V_2 , V_11 , 0 ) ;
if ( V_6 == NULL ) {
V_6 = (struct V_5 * ) F_6 ( F_5 () , sizeof( struct V_5 ) ) ;
V_8 = FALSE ;
}
else {
V_8 = TRUE ;
}
if ( ! F_7 ( V_6 , V_1 , & V_4 ) ) {
return;
}
if ( ! V_8 ) {
F_8 ( F_5 () , V_2 , V_11 , 0 , V_6 ) ;
}
V_7 = F_9 ( V_1 , V_4 ) ;
F_10 ( V_9 , V_7 , V_2 , V_3 , NULL ) ;
}
void F_11 ( void )
{
V_12 = F_12 ( L_2 , L_3 , L_2 ) ;
F_13 ( L_2 , F_1 , V_12 ) ;
}
