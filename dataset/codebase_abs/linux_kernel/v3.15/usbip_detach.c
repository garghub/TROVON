void F_1 ( void )
{
printf ( L_1 , V_1 ) ;
}
static int F_2 ( char * V_2 )
{
int V_3 ;
T_1 V_4 ;
char V_5 [ V_6 + 1 ] ;
for ( unsigned int V_7 = 0 ; V_7 < strlen ( V_2 ) ; V_7 ++ )
if ( ! isdigit ( V_2 [ V_7 ] ) ) {
F_3 ( L_2 , V_2 ) ;
return - 1 ;
}
V_4 = atoi ( V_2 ) ;
snprintf ( V_5 , V_6 , V_8 L_3 , V_4 ) ;
remove ( V_5 ) ;
F_4 ( V_8 ) ;
V_3 = F_5 () ;
if ( V_3 < 0 ) {
F_3 ( L_4 ) ;
return - 1 ;
}
V_3 = F_6 ( V_4 ) ;
if ( V_3 < 0 )
return - 1 ;
F_7 () ;
return V_3 ;
}
int F_8 ( int V_9 , char * V_10 [] )
{
static const struct V_11 V_12 [] = {
{ L_5 , V_13 , NULL , 'p' } ,
{ NULL , 0 , NULL , 0 }
} ;
int V_14 ;
int V_3 = - 1 ;
for (; ; ) {
V_14 = F_9 ( V_9 , V_10 , L_6 , V_12 , NULL ) ;
if ( V_14 == - 1 )
break;
switch ( V_14 ) {
case 'p' :
V_3 = F_2 ( V_15 ) ;
goto V_16;
default:
goto V_17;
}
}
V_17:
F_1 () ;
V_16:
return V_3 ;
}
