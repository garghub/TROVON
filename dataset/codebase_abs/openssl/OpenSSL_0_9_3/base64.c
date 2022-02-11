main ()
{
int V_1 ;
T_1 * V_2 , * V_3 , * V_4 ;
char V_5 [ 512 ] ;
char * V_6 ;
V_2 = F_1 ( F_2 () ) ;
V_3 = F_1 ( F_3 () ) ;
V_4 = F_4 ( V_3 , V_2 ) ;
for (; ; )
{
V_1 = fread ( V_5 , 1 , 512 , V_7 ) ;
if ( V_1 <= 0 ) break;
F_5 ( V_4 , V_5 , V_1 ) ;
}
F_6 ( V_4 ) ;
printf ( L_1 , F_7 ( V_2 ) ) ;
V_1 = ( int ) F_8 ( V_2 , V_8 , 0 , ( char * ) & V_6 ) ;
printf ( L_2 , V_1 ) ;
fwrite ( L_3 , 1 , 4 , stdout ) ;
fwrite ( V_6 , 1 , V_1 , stdout ) ;
fwrite ( L_3 , 1 , 4 , stdout ) ;
F_9 ( V_4 ) ;
}
