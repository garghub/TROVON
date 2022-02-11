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
V_10 = F_5 ( V_8 ) ;
goto V_14;
}
if ( V_4 -> V_15 == V_16 ) {
V_9 = V_17 ;
} else if ( V_4 -> V_15 == V_18 ) {
V_9 = V_19 ;
} else {
F_7 ( & V_2 -> V_13 , L_3 ) ;
V_10 = - V_20 ;
goto V_14;
}
F_8 ( V_8 , V_21 ,
V_22 , V_9 ) ;
V_10 = F_9 ( & V_2 -> V_13 , V_4 , & V_6 ) ;
if ( V_10 )
goto V_14;
return 0 ;
V_14:
F_10 ( V_2 , V_4 ) ;
return V_10 ;
}
