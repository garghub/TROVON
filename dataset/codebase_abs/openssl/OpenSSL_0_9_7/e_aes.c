static int F_1 ( T_1 * V_1 , const unsigned char * V_2 ,
const unsigned char * V_3 , int V_4 ) {
if ( ( V_1 -> V_5 -> V_6 & V_7 ) == V_8
|| ( V_1 -> V_5 -> V_6 & V_7 ) == V_9
|| V_4 )
F_2 ( V_2 , V_1 -> V_10 * 8 , V_1 -> V_11 ) ;
else
F_3 ( V_2 , V_1 -> V_10 * 8 , V_1 -> V_11 ) ;
return 1 ;
}
