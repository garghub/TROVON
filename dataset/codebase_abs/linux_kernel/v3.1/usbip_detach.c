void F_1 ( void )
{
printf ( L_1 , V_1 ) ;
}
static int F_2 ( char * V_2 )
{
int V_3 ;
T_1 V_4 ;
for ( unsigned int V_5 = 0 ; V_5 < strlen ( V_2 ) ; V_5 ++ )
if ( ! isdigit ( V_2 [ V_5 ] ) ) {
F_3 ( L_2 , V_2 ) ;
return - 1 ;
}
V_4 = atoi ( V_2 ) ;
V_3 = F_4 () ;
if ( V_3 < 0 ) {
F_3 ( L_3 ) ;
return - 1 ;
}
V_3 = F_5 ( V_4 ) ;
if ( V_3 < 0 )
return - 1 ;
F_6 () ;
return V_3 ;
}
int F_7 ( int V_6 , char * V_7 [] )
{
static const struct V_8 V_9 [] = {
{ L_4 , V_10 , NULL , 'p' } ,
{ NULL , 0 , NULL , 0 }
} ;
int V_11 ;
int V_3 = - 1 ;
for (; ; ) {
V_11 = F_8 ( V_6 , V_7 , L_5 , V_9 , NULL ) ;
if ( V_11 == - 1 )
break;
switch ( V_11 ) {
case 'p' :
V_3 = F_2 ( V_12 ) ;
goto V_13;
default:
goto V_14;
}
}
V_14:
F_1 () ;
V_13:
return V_3 ;
}
