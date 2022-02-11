int F_1 ( T_1 V_1 , int V_2 )
{
struct {
T_2 V_2 ;
T_2 V_1 ;
} V_3 ;
V_3 . V_1 = F_2 ( V_1 ) ;
V_3 . V_2 = F_2 ( V_2 ) ;
return F_3 ( V_4 , V_5 ,
& V_3 , sizeof( V_3 ) , NULL , 0 ) ;
}
