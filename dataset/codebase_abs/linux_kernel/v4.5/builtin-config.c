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
V_4 = F_3 ( V_4 , V_5 , V_7 , V_8 ,
V_9 ) ;
switch ( V_10 ) {
case V_11 :
if ( V_4 ) {
F_4 ( L_3 ) ;
F_5 ( V_8 , V_7 , L_4 , 1 ) ;
} else {
V_6 = F_6 ( F_1 , NULL ) ;
if ( V_6 < 0 )
F_4 ( L_5
L_6 ) ;
}
break;
default:
F_7 ( V_8 , V_7 ) ;
}
return V_6 ;
}
