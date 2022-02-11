static int F_1 ( const char * V_1 , const char * V_2 ,
void * T_1 V_3 )
{
if ( V_2 )
printf ( L_1 , V_1 , V_2 ) ;
else
printf ( L_2 , V_1 ) ;
return 0 ;
}
int F_2 ( int V_4 , const char * * V_5 , const char * T_2 V_3 )
{
int V_6 = 0 ;
char * V_7 = F_3 ( L_3 , getenv ( L_4 ) ) ;
V_4 = F_4 ( V_4 , V_5 , V_8 , V_9 ,
V_10 ) ;
if ( V_11 && V_12 ) {
F_5 ( L_5 ) ;
F_6 ( V_9 , V_8 , L_6 , 0 ) ;
F_6 ( NULL , V_8 , L_7 , 0 ) ;
return - 1 ;
}
if ( V_11 )
V_13 = F_7 () ;
else if ( V_12 )
V_13 = V_7 ;
switch ( V_14 ) {
case V_15 :
if ( V_4 ) {
F_5 ( L_8 ) ;
F_6 ( V_9 , V_8 , L_9 , 1 ) ;
} else {
V_6 = F_8 ( F_1 , NULL ) ;
if ( V_6 < 0 ) {
const char * V_16 = V_13 ;
if ( ! V_13 )
V_16 = V_7 ;
F_5 ( L_10
L_11 , V_16 ) ;
}
}
break;
default:
F_9 ( V_9 , V_8 ) ;
}
return V_6 ;
}
