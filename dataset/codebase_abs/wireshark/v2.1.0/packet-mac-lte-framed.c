static int F_1 ( T_1 * V_1 , T_2 * V_2 ,
T_3 * V_3 , void * T_4 V_4 )
{
T_5 V_5 = 0 ;
struct V_6 * V_7 ;
T_1 * V_8 ;
T_6 V_9 = FALSE ;
T_7 V_10 = F_2 ( L_1 ) ;
if ( ! V_10 ) {
return 0 ;
}
if ( ( V_11 ) F_3 ( V_1 , V_5 ) < ( 3 + 2 ) ) {
return 5 ;
}
V_7 = (struct V_6 * ) F_4 ( F_5 () , V_2 , V_12 , 0 ) ;
if ( V_7 == NULL ) {
V_7 = (struct V_6 * ) F_6 ( F_5 () , sizeof( struct V_6 ) ) ;
V_9 = FALSE ;
}
else {
V_9 = TRUE ;
}
if ( ! F_7 ( V_7 , V_1 , & V_5 ) ) {
return V_5 ;
}
if ( ! V_9 ) {
F_8 ( F_5 () , V_2 , V_12 , 0 , V_7 ) ;
}
V_8 = F_9 ( V_1 , V_5 ) ;
F_10 ( V_10 , V_8 , V_2 , V_3 , NULL ) ;
return F_11 ( V_1 ) ;
}
void F_12 ( void )
{
V_13 = F_13 ( L_2 , L_3 , L_2 ) ;
F_14 ( L_2 , F_1 , V_13 ) ;
}
