static void F_1 ( char * V_1 )
{
printf ( L_1 , * ( ( unsigned int * ) V_1 ) ) ;
}
static void F_2 ( char * V_1 )
{
unsigned long V_2 ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
* ( V_1 + V_2 ) = ( char ) V_2 ;
}
static void F_3 ( char * V_1 )
{
unsigned long V_2 ;
F_1 ( V_1 ) ;
for ( V_2 = 0 ; V_2 < V_3 ; V_2 ++ )
if ( * ( V_1 + V_2 ) != ( char ) V_2 ) {
printf ( L_2 , V_2 ) ;
break;
}
}
int main ( void )
{
void * V_1 ;
V_1 = F_4 ( V_4 , V_3 , V_5 , V_6 , 0 , 0 ) ;
if ( V_1 == V_7 ) {
perror ( L_3 ) ;
exit ( 1 ) ;
}
printf ( L_4 , V_1 ) ;
F_1 ( V_1 ) ;
F_2 ( V_1 ) ;
F_3 ( V_1 ) ;
F_5 ( V_1 , V_3 ) ;
return 0 ;
}
