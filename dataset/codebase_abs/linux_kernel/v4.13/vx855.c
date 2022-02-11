static int F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
int V_5 ;
T_1 V_6 ;
V_5 = F_2 ( V_2 ) ;
if ( V_5 )
return - V_7 ;
F_3 ( V_2 , V_8 , & V_6 ) ;
if ( ! V_6 ) {
F_4 ( & V_2 -> V_9 ,
L_1 ) ;
V_5 = - V_7 ;
goto V_10;
}
V_6 &= 0xff80 ;
V_11 [ 0 ] . V_12 = V_6 + V_13 ;
V_11 [ 0 ] . V_14 = V_11 [ 0 ] . V_12 + 3 ;
V_11 [ 1 ] . V_12 = V_6 + V_15 ;
V_11 [ 1 ] . V_14 = V_11 [ 1 ] . V_12 + 3 ;
V_5 = F_5 ( & V_2 -> V_9 , - 1 , V_16 , F_6 ( V_16 ) ,
NULL , 0 , NULL ) ;
return - V_7 ;
V_10:
F_7 ( V_2 ) ;
return V_5 ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_9 ( & V_2 -> V_9 ) ;
F_7 ( V_2 ) ;
}
