int main ()
{
char * V_1 = L_1 ;
char * V_2 ;
char * V_3 ;
T_1 * V_4 ;
T_1 * V_5 ;
int V_6 ;
T_2 * V_7 ;
F_1 () ;
V_5 = F_2 ( V_8 ) ;
if ( ! V_5 )
{
F_3 ( V_9 ) ;
exit ( 1 ) ;
}
V_4 = F_4 ( V_10 ) ;
if( ! V_4 )
{
F_5 ( V_5 ) ;
fprintf ( V_9 , L_2 ) ;
exit ( 1 ) ;
}
V_2 = malloc ( F_6 ( V_4 ) ) ;
V_3 = malloc ( F_6 ( V_4 ) ) ;
V_6 = F_7 ( strlen ( V_1 ) + 1 , V_1 , V_2 , V_4 -> V_11 . V_12 , V_13 ) ;
if ( V_6 != F_6 ( V_4 ) )
{
fprintf ( V_9 , L_3 ) ;
exit ( 1 ) ;
}
F_8 ( V_6 , V_2 , V_3 , V_5 -> V_11 . V_12 , V_13 ) ;
printf ( L_4 , V_3 ) ;
F_5 ( V_5 ) ;
F_5 ( V_4 ) ;
free ( V_2 ) ;
free ( V_3 ) ;
}
