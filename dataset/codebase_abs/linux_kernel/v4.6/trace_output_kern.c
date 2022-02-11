int F_1 ( struct V_1 * V_2 )
{
struct V_3 {
T_1 V_4 ;
T_1 V_5 ;
} V_6 ;
V_6 . V_4 = F_2 () ;
V_6 . V_5 = 0x12345678 ;
F_3 ( V_2 , & V_7 , 0 , & V_6 , sizeof( V_6 ) ) ;
return 0 ;
}
