void F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_4 , T_2 V_5 , T_1 * V_6 )
{
F_2 ( V_7 , V_2 ) ;
T_1 V_8 [ V_9 ] ;
V_7 -> V_2 = V_2 ;
F_3 ( V_7 ) ;
F_4 ( V_7 , V_3 , V_10 ) ;
F_4 ( V_7 , V_4 , V_5 - V_11 ) ;
F_5 ( V_7 , V_12 , V_11 , V_8 ) ;
memcpy ( V_6 , V_8 , V_11 ) ;
}
void F_6 ( struct V_1 * V_2 , const T_1 * V_3 ,
const T_1 * V_4 , T_2 V_5 , T_1 * V_6 )
{
F_2 ( V_7 , V_2 ) ;
V_7 -> V_2 = V_2 ;
F_3 ( V_7 ) ;
F_4 ( V_7 , V_3 , V_10 ) ;
F_4 ( V_7 , V_4 , V_5 - V_13 ) ;
F_5 ( V_7 , V_12 , V_13 , V_6 ) ;
}
struct V_1 * F_7 ( const T_1 V_14 [] ,
T_2 V_15 )
{
struct V_1 * V_2 ;
V_2 = F_8 ( L_1 , 0 , 0 ) ;
if ( ! F_9 ( V_2 ) )
F_10 ( V_2 , V_14 , V_15 ) ;
return V_2 ;
}
void F_11 ( struct V_1 * V_2 )
{
F_12 ( V_2 ) ;
}
