int main ( int V_1 , char * V_2 [] )
{
unsigned int V_3 = 10000 ;
char * V_4 ;
int V_5 , V_6 ;
if ( V_1 != 2 ) {
printf ( L_1 ) ;
return 0 ;
}
V_4 = V_2 [ 1 ] ;
printf ( L_2 , V_4 ) ;
V_5 = F_1 ( V_4 , V_7 ) ;
if ( V_5 < 0 ) {
printf ( L_3 , V_4 ) ;
return - 1 ;
}
printf ( L_4 ) ;
V_6 = F_2 ( V_5 , V_8 , & V_9 ) ;
if ( V_6 < 0 ) {
printf ( L_5 , V_4 , V_6 ) ;
V_6 = - 1 ;
goto V_10;
}
printf ( L_6 , * ( unsigned long long int * ) ( V_9 . V_9 ) ) ;
printf ( L_7 ) ;
V_6 = F_2 ( V_5 , V_11 , & V_12 ) ;
if ( V_6 < 0 ) {
printf ( L_8 , V_4 , V_6 ) ;
V_6 = - 1 ;
goto V_10;
}
printf ( L_9 , V_12 . V_13 ) ;
printf ( L_10 ) ;
memcpy ( V_14 . V_9 , V_9 . V_9 , 8 ) ;
V_6 = F_2 ( V_5 , V_15 , & V_14 ) ;
if ( V_6 < 0 ) {
printf ( L_11 , V_4 , V_6 ) ;
V_6 = - 1 ;
goto V_10;
}
printf ( L_12 ,
V_14 . V_16 , V_14 . V_17 ) ;
V_10:
F_3 ( V_5 ) ;
return V_6 ;
}
