static int F_1 ( T_1 * V_1 , int type , int V_2 , void * V_3 )
{
switch( type )
{
case V_4 :
F_2 ( V_1 ) -> V_5 = V_6 ;
return 1 ;
case V_7 :
* ( int * ) V_3 = F_2 ( V_1 ) -> V_5 ;
return 1 ;
case V_8 :
switch( V_2 )
{
case V_9 :
case V_6 :
case V_10 :
F_2 ( V_1 ) -> V_5 = V_2 ;
return 1 ;
default:
F_3 ( V_11 , V_12 ) ;
return 0 ;
}
default:
return - 1 ;
}
}
static int F_4 ( T_1 * V_13 , const unsigned char * V_14 ,
const unsigned char * V_15 , int V_16 )
{
F_5 ( & F_2 ( V_13 ) -> V_17 , F_6 ( V_13 ) ,
V_14 , F_2 ( V_13 ) -> V_5 ) ;
return 1 ;
}
