void F_1 ( T_1 * V_1 , T_2 * V_2 )
{
int V_3 ;
const unsigned int * V_4 = ( const unsigned int * ) V_1 ;
fprintf ( V_2 , L_1 ) ;
for ( V_3 = 0 ; V_3 < 8 ; V_3 ++ ) {
fprintf ( V_2 , L_2 , V_4 [ V_3 ] ) ;
if ( V_3 != 7 ) fprintf ( V_2 , L_3 ) ;
}
fprintf ( V_2 , L_4 ) ;
}
