int main ( int V_1 , char * * V_2 )
{
int V_3 , V_4 = 0 ;
T_1 * V_5 ;
if ( V_1 == 1 ) {
F_1 ( V_6 ) ;
} else {
for ( V_3 = 1 ; V_3 < V_1 ; V_3 ++ ) {
V_5 = fopen ( V_2 [ V_3 ] , L_1 ) ;
if ( V_5 == NULL ) {
perror ( V_2 [ V_3 ] ) ;
V_4 ++ ;
continue;
}
printf ( L_2 , V_2 [ V_3 ] ) ;
F_1 ( V_5 ) ;
fclose ( V_5 ) ;
}
}
exit ( V_4 ) ;
}
void F_1 ( T_1 * V_7 )
{
T_2 V_8 ;
unsigned char V_9 [ V_10 ] ;
int V_11 ;
int V_3 ;
static unsigned char V_12 [ V_13 ] ;
V_11 = fileno ( V_7 ) ;
F_2 ( & V_8 ) ;
for (; ; ) {
V_3 = F_3 ( V_11 , V_12 , sizeof V_12 ) ;
if ( V_3 <= 0 )
break;
F_4 ( & V_8 , V_12 , ( unsigned long ) V_3 ) ;
}
F_5 ( & ( V_9 [ 0 ] ) , & V_8 ) ;
F_6 ( V_9 ) ;
}
void F_6 ( unsigned char * V_9 )
{
int V_3 ;
for ( V_3 = 0 ; V_3 < V_10 ; V_3 ++ )
printf ( L_3 , V_9 [ V_3 ] ) ;
printf ( L_4 ) ;
}
