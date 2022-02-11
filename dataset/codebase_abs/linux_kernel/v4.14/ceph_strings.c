const char * F_1 ( int type )
{
switch ( type ) {
case V_1 : return L_1 ;
case V_2 : return L_2 ;
case V_3 : return L_3 ;
case V_4 : return L_4 ;
case V_5 : return L_5 ;
default: return L_6 ;
}
}
const char * F_2 ( int V_6 )
{
switch ( V_6 ) {
#define F_3 ( V_6 , T_1 , T_2 ) case CEPH_OSD_OP_##op: return (str);
F_4 (GENERATE_CASE)
#undef F_3
default:
return L_7 ;
}
}
const char * F_5 ( int V_7 )
{
switch ( V_7 ) {
case V_8 :
return L_8 ;
case V_9 :
return L_9 ;
case V_10 :
return L_10 ;
case V_11 :
return L_11 ;
default:
return L_7 ;
}
}
const char * F_6 ( int V_12 )
{
switch ( V_12 ) {
case V_13 :
return L_12 ;
case V_14 :
return L_13 ;
case V_15 :
return L_14 ;
case V_16 :
return L_15 ;
default:
return L_7 ;
}
}
