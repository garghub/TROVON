static void F_1 ( void )
{
printf ( L_1 ) ;
printf ( L_2 ) ;
printf ( L_3 ) ;
printf ( L_4 ) ;
}
int main ( int V_1 , char * * V_2 )
{
const char * V_3 = NULL ;
int V_4 = - 1 ;
int V_5 = 0 ;
int V_6 = - 1 ;
int V_7 = - 1 ;
int V_8 ;
while ( ( V_8 = F_2 ( V_1 , V_2 , L_5 ) ) != - 1 ) {
switch ( V_8 ) {
case 'U' :
V_3 = V_9 ;
break;
case 'i' :
V_4 = atoi ( V_9 ) ;
break;
default:
F_1 () ;
goto V_10;
}
}
if ( V_4 < 0 || ! V_3 ) {
F_1 () ;
goto V_10;
}
V_6 = F_3 ( V_3 ) ;
if ( V_6 < 0 ) {
fprintf ( V_11 , L_6 ,
V_3 , strerror ( V_12 ) , V_12 ) ;
goto V_10;
}
V_7 = F_4 ( V_6 , & V_5 , & V_4 , 0 ) ;
if ( V_7 ) {
perror ( L_7 ) ;
goto V_10;
}
V_10:
if ( V_6 != - 1 )
F_5 ( V_6 ) ;
return V_7 ;
}
