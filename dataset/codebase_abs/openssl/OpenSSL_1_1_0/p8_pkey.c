static int F_1 ( int V_1 , T_1 * * V_2 , const T_2 * V_3 ,
void * V_4 )
{
if ( V_1 == V_5 ) {
T_3 * V_6 = ( T_3 * ) * V_2 ;
if ( V_6 -> V_7 )
F_2 ( V_6 -> V_7 -> V_8 , V_6 -> V_7 -> V_9 ) ;
}
return 1 ;
}
int F_3 ( T_3 * V_10 , int V_11 , int type ,
const unsigned char * V_12 , int V_13 )
{
if ( F_4 ( & V_10 -> V_14 , V_11 , type , V_12 , V_13 ) != NULL )
return 1 ;
return 0 ;
}
