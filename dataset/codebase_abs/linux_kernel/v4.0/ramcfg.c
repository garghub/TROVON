static T_1
F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 , 0x101000 ) & 0x0000003c ) >> 2 ;
}
T_1
F_3 ( struct V_3 * V_4 )
{
struct V_5 V_6 ;
if ( ! V_5 ( V_4 , 'M' , & V_6 ) ) {
if ( V_6 . V_7 == 1 && V_6 . V_8 >= 5 )
return F_4 ( V_4 , V_6 . V_9 + 2 ) ;
if ( V_6 . V_7 == 2 && V_6 . V_8 >= 3 )
return F_4 ( V_4 , V_6 . V_9 + 0 ) ;
}
return 0x00 ;
}
T_1
F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_3 ( V_2 ) ;
T_1 V_10 = F_1 ( V_2 ) ;
T_2 V_11 = 0x00000000 ;
struct V_5 V_6 ;
struct V_12 V_13 ;
T_1 V_14 , V_15 ;
if ( ! V_5 ( V_4 , 'M' , & V_6 ) ) {
if ( V_6 . V_7 == 1 && V_6 . V_8 >= 5 )
V_11 = F_6 ( V_4 , V_6 . V_9 + 3 ) ;
if ( V_6 . V_7 == 2 && V_6 . V_8 >= 3 ) {
if ( V_6 . V_8 >= 7 &&
F_7 ( V_4 , V_10 , & V_14 , & V_15 , & V_13 ) )
return V_13 . V_16 ;
V_11 = F_6 ( V_4 , V_6 . V_9 + 1 ) ;
}
}
if ( V_11 )
V_10 = F_4 ( V_4 , V_11 + V_10 ) ;
return V_10 ;
}
