const char * F_1 ( const int V_1 ) {
const char * V_2 ;
if ( ( V_2 = F_2 ( V_1 , & V_3 ) ) != NULL )
return V_2 ;
V_2 = L_1 ;
#ifdef F_3
if ( V_4 . V_5 || V_4 . V_6 ||
V_4 . V_7 ) {
static char V_8 [ 128 ] ;
struct V_9 * V_10 ;
V_10 = F_4 ( V_1 ) ;
if ( V_10 ) {
F_5 ( V_8 , V_10 -> V_11 , sizeof( V_8 ) ) ;
V_2 = V_8 ;
}
}
#endif
return V_2 ;
}
static T_1 F_6 ( int V_1 )
{
switch ( V_1 ) {
case V_12 :
case V_13 :
case V_14 :
case V_15 :
case V_16 :
case V_17 :
case V_18 :
case V_19 :
case V_20 :
return TRUE ;
break;
default:
break;
}
return FALSE ;
}
const char * F_7 ( int V_1 )
{
if ( F_6 ( V_1 ) )
return F_1 ( V_1 ) ;
return NULL ;
}
