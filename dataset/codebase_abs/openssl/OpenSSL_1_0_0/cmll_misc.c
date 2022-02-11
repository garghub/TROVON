int F_1 ( const unsigned char * V_1 , const int V_2 ,
T_1 * V_3 )
{
if( ! V_1 || ! V_3 )
return - 1 ;
if( V_2 != 128 && V_2 != 192 && V_2 != 256 )
return - 2 ;
V_3 -> V_4 = F_2 ( V_2 , V_1 , V_3 -> V_5 . V_6 ) ;
return 0 ;
}
void F_3 ( const unsigned char * V_7 , unsigned char * V_8 ,
const T_1 * V_3 )
{
F_4 ( V_3 -> V_4 , V_7 , V_3 -> V_5 . V_6 , V_8 ) ;
}
void F_5 ( const unsigned char * V_7 , unsigned char * V_8 ,
const T_1 * V_3 )
{
F_6 ( V_3 -> V_4 , V_7 , V_3 -> V_5 . V_6 , V_8 ) ;
}
