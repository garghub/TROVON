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
int V_4 ;
V_4 = F_4 ( V_5 , V_6 | V_7 , 0755 ) ;
if ( V_4 < 0 ) {
perror ( L_3 ) ;
exit ( 1 ) ;
}
V_1 = F_5 ( V_8 , V_3 , V_9 , V_10 , V_4 , 0 ) ;
if ( V_1 == V_11 ) {
perror ( L_4 ) ;
F_6 ( V_5 ) ;
exit ( 1 ) ;
}
printf ( L_5 , V_1 ) ;
F_1 ( V_1 ) ;
F_2 ( V_1 ) ;
F_3 ( V_1 ) ;
F_7 ( V_1 , V_3 ) ;
F_8 ( V_4 ) ;
F_6 ( V_5 ) ;
return 0 ;
}
