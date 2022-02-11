static T_1
F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 , 0x101000 ) & 0x0000003c ) >> 2 ;
}
T_1
F_3 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
if ( ! V_3 ( V_2 , 'M' , & V_4 ) ) {
if ( V_4 . V_5 == 1 && V_4 . V_6 >= 5 )
return F_4 ( V_2 , V_4 . V_7 + 2 ) ;
if ( V_4 . V_5 == 2 && V_4 . V_6 >= 3 )
return F_4 ( V_2 , V_4 . V_7 + 0 ) ;
}
return 0x00 ;
}
T_1
F_5 ( struct V_1 * V_2 )
{
T_1 V_8 = F_1 ( V_2 ) ;
T_2 V_9 = 0x00000000 ;
struct V_3 V_4 ;
if ( ! V_3 ( V_2 , 'M' , & V_4 ) ) {
if ( V_4 . V_5 == 1 && V_4 . V_6 >= 5 )
V_9 = F_6 ( V_2 , V_4 . V_7 + 3 ) ;
if ( V_4 . V_5 == 2 && V_4 . V_6 >= 3 )
V_9 = F_6 ( V_2 , V_4 . V_7 + 1 ) ;
}
if ( V_9 )
V_8 = F_4 ( V_2 , V_9 + V_8 ) ;
return V_8 ;
}
