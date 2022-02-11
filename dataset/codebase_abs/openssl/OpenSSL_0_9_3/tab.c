main ()
{
int V_1 , V_2 ;
for ( V_1 = 0 ; V_1 < 256 ; V_1 ++ )
{
for ( V_2 = 0 ; V_2 < 256 ; V_2 ++ )
if ( V_3 [ V_2 ] == V_1 )
{
printf ( L_1 , V_2 ) ;
break;
}
}
}
