static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 V_6 ;
struct V_7 * V_8 ;
T_1 V_9 ;
int V_10 ;
V_10 = F_2 ( V_2 , & V_6 ) ;
if ( V_10 )
return V_10 ;
V_4 = F_3 ( V_2 , & V_6 . V_11 ) ;
if ( F_4 ( V_4 ) )
return F_5 ( V_4 ) ;
V_4 -> V_12 = true ;
V_8 = F_6 ( L_1 ) ;
if ( F_4 ( V_8 ) ) {
F_7 ( & V_2 -> V_13 , L_2 ) ;
return F_5 ( V_8 ) ;
}
if ( V_4 -> V_14 == V_15 ) {
V_9 = V_16 ;
} else if ( V_4 -> V_14 == V_17 ) {
V_9 = V_18 ;
} else {
F_7 ( & V_2 -> V_13 , L_3 ) ;
return - V_19 ;
}
F_8 ( V_8 , V_20 ,
V_21 , V_9 ) ;
return F_9 ( & V_2 -> V_13 , V_4 , & V_6 ) ;
}
