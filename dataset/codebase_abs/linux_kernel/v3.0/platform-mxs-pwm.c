struct V_1 * T_1 F_1 ( T_2 V_2 , int V_3 )
{
struct V_4 V_5 = {
. V_6 = V_7 ,
} ;
V_5 . V_8 = V_2 + 0x10 + 0x20 * V_3 ;
V_5 . V_9 = V_5 . V_8 + 0x1f ;
return F_2 ( L_1 , V_3 , & V_5 , 1 , NULL , 0 ) ;
}
