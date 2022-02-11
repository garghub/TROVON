void
F_1 ( const char * V_1 , ... )
{
T_1 V_2 ;
va_start ( V_2 , V_1 ) ;
F_2 ( V_1 , V_2 ) ;
va_end ( V_2 ) ;
}
void
F_3 ( const char * V_1 , T_1 V_2 )
{
F_2 ( V_1 , V_2 ) ;
}
void
F_4 ( const char * V_3 , int V_4 , T_2 V_5 )
{
T_3 * V_6 ;
V_6 = F_5 ( V_3 ) ;
F_6 ( V_7 , NULL , NULL ,
F_7 ( V_4 , V_5 ) ,
V_6 ) ;
F_8 ( V_6 ) ;
}
void
F_9 ( const char * V_3 , int V_4 )
{
T_3 * V_6 ;
V_6 = F_5 ( V_3 ) ;
F_6 ( V_7 , NULL , NULL ,
L_1 ,
V_6 , F_10 ( V_4 ) ) ;
F_8 ( V_6 ) ;
}
void
F_11 ( const char * V_3 , int V_4 )
{
T_3 * V_6 ;
V_6 = F_5 ( V_3 ) ;
if ( V_4 < 0 ) {
switch ( V_4 ) {
case V_8 :
F_6 ( V_7 , NULL , NULL ,
L_2 ,
V_6 ) ;
break;
default:
F_6 ( V_7 , NULL , NULL ,
L_3 ,
V_6 , F_12 ( V_4 ) ) ;
break;
}
} else {
F_6 ( V_7 , NULL , NULL ,
F_13 ( V_4 ) , V_6 ) ;
}
F_8 ( V_6 ) ;
}
