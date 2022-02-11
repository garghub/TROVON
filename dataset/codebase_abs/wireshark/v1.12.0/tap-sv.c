static int
F_1 ( void * T_1 V_1 , T_2 * V_2 , T_3 * T_4 V_1 , const void * V_3 )
{
int V_4 ;
const T_5 * V_5 = ( const T_5 * ) V_3 ;
printf ( L_1 , F_2 ( & V_2 -> V_6 ) , V_5 -> V_7 ) ;
for( V_4 = 0 ; V_4 < V_5 -> V_8 ; V_4 ++ ) {
printf ( L_2 , V_5 -> V_9 [ V_4 ] . V_10 ) ;
}
printf ( L_3 ) ;
return 0 ;
}
static void
F_3 ( const char * T_6 V_1 , void * T_7 V_1 )
{
T_8 * V_11 ;
V_11 = F_4 (
L_4 ,
NULL ,
NULL ,
0 ,
NULL ,
F_1 ,
NULL ) ;
if ( V_11 ) {
fprintf ( V_12 , L_5 ,
V_11 -> V_13 ) ;
F_5 ( V_11 , TRUE ) ;
exit ( 1 ) ;
}
}
void
F_6 ( void )
{
F_7 ( L_4 , F_3 , NULL ) ;
}
