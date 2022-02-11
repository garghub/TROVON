int main ( int V_1 , char * * V_2 )
{
T_1 * V_3 = V_4 ;
bool V_5 = false ;
int V_6 ;
for ( V_6 = 1 ; V_6 < V_1 ; V_6 ++ ) {
if ( ! strncmp ( L_1 , V_2 [ V_6 ] , 2 ) ) {
V_5 = true ;
continue;
}
V_3 = fopen ( V_2 [ V_6 ] , L_2 ) ;
if ( ! V_3 ) {
V_3 = V_4 ;
continue;
}
break;
}
F_1 ( V_3 , V_5 ) ;
return 0 ;
}
