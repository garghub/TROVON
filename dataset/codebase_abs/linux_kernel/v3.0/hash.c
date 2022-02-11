static T_1 F_1 ( T_1 V_1 )
{
T_1 V_2 = V_3 ^ V_1 ;
T_1 V_4 = V_1 ;
T_1 V_5 = 231232 ;
T_1 V_6 = 1232 ;
F_2 ( V_4 , V_5 , V_2 ) ;
F_2 ( V_6 , V_1 , V_2 ) ;
return V_2 ;
}
static T_1 F_3 ( T_1 V_1 , T_1 V_4 )
{
T_1 V_2 = V_3 ^ V_1 ^ V_4 ;
T_1 V_5 = 231232 ;
T_1 V_6 = 1232 ;
F_2 ( V_1 , V_4 , V_2 ) ;
F_2 ( V_5 , V_1 , V_2 ) ;
F_2 ( V_4 , V_6 , V_2 ) ;
return V_2 ;
}
static T_1 F_4 ( T_1 V_1 , T_1 V_4 , T_1 V_7 )
{
T_1 V_2 = V_3 ^ V_1 ^ V_4 ^ V_7 ;
T_1 V_5 = 231232 ;
T_1 V_6 = 1232 ;
F_2 ( V_1 , V_4 , V_2 ) ;
F_2 ( V_7 , V_5 , V_2 ) ;
F_2 ( V_6 , V_1 , V_2 ) ;
F_2 ( V_4 , V_5 , V_2 ) ;
F_2 ( V_6 , V_7 , V_2 ) ;
return V_2 ;
}
static T_1 F_5 ( T_1 V_1 , T_1 V_4 , T_1 V_7 , T_1 V_8 )
{
T_1 V_2 = V_3 ^ V_1 ^ V_4 ^ V_7 ^ V_8 ;
T_1 V_5 = 231232 ;
T_1 V_6 = 1232 ;
F_2 ( V_1 , V_4 , V_2 ) ;
F_2 ( V_7 , V_8 , V_2 ) ;
F_2 ( V_1 , V_5 , V_2 ) ;
F_2 ( V_6 , V_4 , V_2 ) ;
F_2 ( V_7 , V_5 , V_2 ) ;
F_2 ( V_6 , V_8 , V_2 ) ;
return V_2 ;
}
static T_1 F_6 ( T_1 V_1 , T_1 V_4 , T_1 V_7 , T_1 V_8 ,
T_1 V_9 )
{
T_1 V_2 = V_3 ^ V_1 ^ V_4 ^ V_7 ^ V_8 ^ V_9 ;
T_1 V_5 = 231232 ;
T_1 V_6 = 1232 ;
F_2 ( V_1 , V_4 , V_2 ) ;
F_2 ( V_7 , V_8 , V_2 ) ;
F_2 ( V_9 , V_5 , V_2 ) ;
F_2 ( V_6 , V_1 , V_2 ) ;
F_2 ( V_4 , V_5 , V_2 ) ;
F_2 ( V_6 , V_7 , V_2 ) ;
F_2 ( V_8 , V_5 , V_2 ) ;
F_2 ( V_6 , V_9 , V_2 ) ;
return V_2 ;
}
T_1 F_7 ( int type , T_1 V_1 )
{
switch ( type ) {
case V_10 :
return F_1 ( V_1 ) ;
default:
return 0 ;
}
}
T_1 F_8 ( int type , T_1 V_1 , T_1 V_4 )
{
switch ( type ) {
case V_10 :
return F_3 ( V_1 , V_4 ) ;
default:
return 0 ;
}
}
T_1 F_9 ( int type , T_1 V_1 , T_1 V_4 , T_1 V_7 )
{
switch ( type ) {
case V_10 :
return F_4 ( V_1 , V_4 , V_7 ) ;
default:
return 0 ;
}
}
T_1 F_10 ( int type , T_1 V_1 , T_1 V_4 , T_1 V_7 , T_1 V_8 )
{
switch ( type ) {
case V_10 :
return F_5 ( V_1 , V_4 , V_7 , V_8 ) ;
default:
return 0 ;
}
}
T_1 F_11 ( int type , T_1 V_1 , T_1 V_4 , T_1 V_7 , T_1 V_8 , T_1 V_9 )
{
switch ( type ) {
case V_10 :
return F_6 ( V_1 , V_4 , V_7 , V_8 , V_9 ) ;
default:
return 0 ;
}
}
const char * F_12 ( int type )
{
switch ( type ) {
case V_10 :
return L_1 ;
default:
return L_2 ;
}
}
