int F_1 ( struct V_1 V_2 )
{
struct V_3 * V_4 ;
struct V_5 V_6 ;
int V_7 = - V_8 ;
if ( V_2 . V_9 < ( V_10 >> 1 ) )
F_2 ( V_2 . V_11 , & V_6 ) ;
else
F_2 ( V_2 . V_11 + 1 , & V_6 ) ;
V_4 = F_3 ( V_12 ) ;
if ( V_4 ) {
if ( V_4 -> V_13 && ( V_4 -> V_13 -> V_14 || V_4 -> V_13 -> V_15 ) )
V_7 = F_4 ( V_4 , & V_6 ) ;
F_5 ( V_4 ) ;
}
return V_7 ;
}
