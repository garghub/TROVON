static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = V_2 -> V_6 . V_7 ;
struct V_8 V_9 ;
struct V_8 V_10 ;
struct V_8 * V_11 ;
unsigned int V_12 = 0 ;
int V_13 = 0 ;
int V_14 ;
const T_1 * V_15 ;
V_3 = F_2 ( V_5 , 0 , & V_9 ) ;
if ( V_3 ) {
F_3 ( & V_2 -> V_6 , L_1
L_2 ) ;
return - V_16 ;
}
V_3 = F_2 ( V_5 , 1 , & V_10 ) ;
if ( V_3 ) {
F_3 ( & V_2 -> V_6 , L_3
L_2 ) ;
return - V_16 ;
}
V_11 = F_4 ( V_2 , V_17 , 0 ) ;
V_15 = F_5 ( V_5 , L_4 , NULL ) ;
if ( V_15 )
V_12 = F_6 ( V_15 ) ;
V_15 = F_5 ( V_5 , L_5 , NULL ) ;
if ( V_15 ) {
V_13 = F_6 ( V_15 ) ;
if ( V_13 > 6 ) {
F_3 ( & V_2 -> V_6 , L_6 ) ;
return - V_16 ;
}
} else {
F_7 ( & V_2 -> V_6 , L_7 ) ;
}
V_14 = 1 << V_13 ;
V_14 |= ( 1 << V_13 ) - 1 ;
return F_8 ( & V_2 -> V_6 , & V_9 , & V_10 , V_11 ,
V_12 , V_14 ) ;
}
