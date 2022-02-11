int main ( void )
{
int V_1 , V_2 ;
const char * V_3 ;
printf ( L_1 ) ;
for ( V_1 = 0 ; V_1 < V_4 ; V_1 ++ ) {
for ( V_2 = 0 ; V_2 < 32 ; V_2 ++ ) {
V_3 = V_5 [ V_1 * 32 + V_2 ] ;
if ( V_1 == V_4 - 1 && V_2 == 31 ) {
if ( ! V_3 )
V_3 = L_2 ;
printf ( L_3 ,
V_1 , V_2 , V_3 ) ;
} else if ( V_3 ) {
printf ( L_4
L_5
L_6 ,
V_1 , V_2 , V_1 , V_2 , V_3 ) ;
}
}
}
printf ( L_7 ) ;
return 0 ;
}
