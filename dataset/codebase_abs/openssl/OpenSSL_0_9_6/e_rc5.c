static int F_1 ( T_1 * V_1 , int type , int V_2 , void * V_3 )
{
switch( type ) {
case V_4 :
V_1 -> V_1 . V_5 . V_6 = V_7 ;
return 1 ;
case V_8 :
* ( int * ) V_3 = V_1 -> V_1 . V_5 . V_6 ;
return 1 ;
case V_9 :
switch( V_2 ) {
case V_10 :
case V_7 :
case V_11 :
V_1 -> V_1 . V_5 . V_6 = V_2 ;
return 1 ;
default:
F_2 ( V_12 , V_13 ) ;
return 0 ;
}
default:
return - 1 ;
}
}
static int F_3 ( T_1 * V_14 , const unsigned char * V_15 ,
const unsigned char * V_16 , int V_17 )
{
F_4 ( & ( V_14 -> V_1 . V_5 . V_18 ) , F_5 ( V_14 ) ,
V_15 , V_14 -> V_1 . V_5 . V_6 ) ;
return 1 ;
}
