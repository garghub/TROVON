void
F_1 ( const char * V_1 , T_1 V_2 )
{
F_2 ( V_1 , V_2 ) ;
}
void
F_3 ( const char * V_3 , int V_4 , T_2 V_5 )
{
T_3 * V_6 ;
V_6 = F_4 ( V_3 ) ;
F_5 ( V_7 , NULL , NULL ,
F_6 ( V_4 , V_5 ) ,
V_6 ) ;
F_7 ( V_6 ) ;
}
void
F_8 ( const char * V_3 , int V_4 )
{
T_3 * V_6 ;
V_6 = F_4 ( V_3 ) ;
F_5 ( V_7 , NULL , NULL ,
L_1 ,
V_6 , F_9 ( V_4 ) ) ;
F_7 ( V_6 ) ;
}
void
F_10 ( const char * V_3 , int V_4 )
{
T_3 * V_6 ;
V_6 = F_4 ( V_3 ) ;
if ( V_4 < 0 ) {
switch ( V_4 ) {
case V_8 :
F_5 ( V_7 , NULL , NULL ,
L_2 ,
V_6 ) ;
break;
default:
F_5 ( V_7 , NULL , NULL ,
L_3 ,
V_6 , F_11 ( V_4 ) ) ;
break;
}
} else {
F_5 ( V_7 , NULL , NULL ,
F_12 ( V_4 ) , V_6 ) ;
}
F_7 ( V_6 ) ;
}
