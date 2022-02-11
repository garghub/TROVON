int main ( int V_1 , char * V_2 [] )
{
T_1 V_3 , V_4 ;
int V_5 ;
printf ( L_1 ) ;
if ( ( V_5 = F_1 ( & V_3 , L_2 , 0 ) ) == 0 ) {
printf ( L_3 ) ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ )
printf ( L_4 , V_3 [ V_5 ] ) ;
} else
printf ( L_5 , V_5 ) ;
printf ( L_6 ) ;
printf ( L_7 ) ;
if ( ( V_5 = F_2 ( & V_3 , & V_4 ,
L_8 , 1 ) ) == 0 ) {
printf ( L_9 ) ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ )
printf ( L_4 , V_3 [ V_5 ] ) ;
printf ( L_6 ) ;
printf ( L_10 ) ;
for ( V_5 = 0 ; V_5 < 8 ; V_5 ++ )
printf ( L_4 , V_4 [ V_5 ] ) ;
printf ( L_6 ) ;
exit ( 1 ) ;
} else {
printf ( L_5 , V_5 ) ;
exit ( 0 ) ;
}
#ifdef F_3
return ( 0 ) ;
#endif
}
