static int F_1 ( T_1 V_1 )
{
T_2 V_2 ;
union V_3 V_4 [ 2 ] ;
struct V_5 V_6 ;
struct V_7 V_8 = { V_9 , NULL } ;
V_6 . V_10 = 2 ;
V_6 . V_11 = & V_4 [ 0 ] ;
V_4 [ 0 ] . type = V_12 ;
V_4 [ 0 ] . integer . V_13 = 0 ;
V_4 [ 1 ] . type = V_12 ;
V_4 [ 1 ] . integer . V_13 = 0 ;
V_2 = F_2 ( V_1 , L_1 , & V_6 , & V_8 ) ;
if ( F_3 ( V_2 ) && V_2 != V_14 ) {
F_4 ( V_15 L_2 , F_5 ( V_2 ) ) ;
F_6 ( V_8 . V_11 ) ;
return 1 ;
}
F_6 ( V_8 . V_11 ) ;
return 0 ;
}
int F_7 ( struct V_16 * V_17 )
{
T_1 V_1 ;
int V_18 ;
if ( ! F_8 ( V_17 ) || ! V_17 -> V_19 )
return 0 ;
V_1 = F_9 ( & V_17 -> V_20 -> V_21 ) ;
V_18 = F_1 ( V_1 ) ;
if ( V_18 )
return V_18 ;
return 0 ;
}
