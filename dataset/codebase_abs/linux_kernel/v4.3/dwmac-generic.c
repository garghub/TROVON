static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 V_6 ;
int V_7 ;
V_7 = F_2 ( V_2 , & V_6 ) ;
if ( V_7 )
return V_7 ;
if ( V_2 -> V_8 . V_9 ) {
V_4 = F_3 ( V_2 , & V_6 . V_10 ) ;
if ( F_4 ( V_4 ) ) {
F_5 ( & V_2 -> V_8 , L_1 ) ;
return F_6 ( V_4 ) ;
}
} else {
V_4 = F_7 ( & V_2 -> V_8 ) ;
if ( ! V_4 ) {
F_5 ( & V_2 -> V_8 , L_2 ) ;
return - V_11 ;
}
V_4 -> V_12 = V_13 ;
V_4 -> V_14 = 1 ;
}
if ( V_4 -> V_15 ) {
V_7 = V_4 -> V_15 ( V_2 , V_4 -> V_16 ) ;
if ( V_7 )
return V_7 ;
}
return F_8 ( & V_2 -> V_8 , V_4 , & V_6 ) ;
}
