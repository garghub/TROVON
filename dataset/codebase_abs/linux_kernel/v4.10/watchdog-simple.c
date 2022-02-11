int main ( void )
{
int V_1 = F_1 ( L_1 , V_2 ) ;
int V_3 = 0 ;
if ( V_1 == - 1 ) {
perror ( L_2 ) ;
exit ( V_4 ) ;
}
while ( 1 ) {
V_3 = F_2 ( V_1 , L_3 , 1 ) ;
if ( V_3 != 1 ) {
V_3 = - 1 ;
break;
}
F_3 ( 10 ) ;
}
F_4 ( V_1 ) ;
return V_3 ;
}
