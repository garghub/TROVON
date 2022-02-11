static T_1
F_1 ( struct V_1 * V_2 )
{
return ( F_2 ( V_2 -> V_3 , 0x101000 ) & 0x0000003c ) >> 2 ;
}
T_1
F_3 ( struct V_4 * V_5 )
{
struct V_6 V_7 ;
if ( ! V_6 ( V_5 , 'M' , & V_7 ) ) {
if ( V_7 . V_8 == 1 && V_7 . V_9 >= 5 )
return F_4 ( V_5 , V_7 . V_10 + 2 ) ;
if ( V_7 . V_8 == 2 && V_7 . V_9 >= 3 )
return F_4 ( V_5 , V_7 . V_10 + 0 ) ;
}
return 0x00 ;
}
T_1
F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = V_2 -> V_3 -> V_5 ;
T_1 V_11 = F_1 ( V_2 ) ;
T_2 V_12 = 0x00000000 ;
struct V_6 V_7 ;
struct V_13 V_14 ;
T_1 V_15 , V_16 ;
if ( ! V_6 ( V_5 , 'M' , & V_7 ) ) {
if ( V_7 . V_8 == 1 && V_7 . V_9 >= 5 )
V_12 = F_6 ( V_5 , V_7 . V_10 + 3 ) ;
if ( V_7 . V_8 == 2 && V_7 . V_9 >= 3 ) {
if ( V_7 . V_9 >= 7 &&
F_7 ( V_5 , V_11 , & V_15 , & V_16 , & V_14 ) )
return V_14 . V_17 ;
V_12 = F_6 ( V_5 , V_7 . V_10 + 1 ) ;
}
}
if ( V_12 )
V_11 = F_4 ( V_5 , V_12 + V_11 ) ;
return V_11 ;
}
