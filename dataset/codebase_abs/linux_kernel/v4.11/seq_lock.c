void F_1 ( T_1 * V_1 , const char * V_2 , int line )
{
int V_3 = 5 * V_4 ;
if ( F_2 ( V_1 ) < 0 ) {
F_3 ( L_1 , F_2 ( V_1 ) , V_2 , line ) ;
return;
}
while ( F_2 ( V_1 ) > 0 ) {
if ( V_3 -- == 0 )
F_3 ( L_2 , F_2 ( V_1 ) , V_2 , line ) ;
F_4 ( 1 ) ;
}
}
