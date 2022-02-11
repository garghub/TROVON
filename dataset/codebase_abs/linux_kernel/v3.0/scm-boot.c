int F_1 ( T_1 V_1 , int V_2 )
{
struct {
unsigned int V_2 ;
T_1 V_1 ;
} V_3 ;
V_3 . V_1 = V_1 ;
V_3 . V_2 = V_2 ;
return F_2 ( V_4 , V_5 ,
& V_3 , sizeof( V_3 ) , NULL , 0 ) ;
}
