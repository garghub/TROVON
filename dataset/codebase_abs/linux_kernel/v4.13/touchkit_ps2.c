static T_1 F_1 ( struct V_1 * V_1 )
{
unsigned char * V_2 = V_1 -> V_2 ;
struct V_3 * V_4 = V_1 -> V_4 ;
if ( V_1 -> V_5 != 5 )
return V_6 ;
F_2 ( V_4 , V_7 , F_3 ( V_2 ) ) ;
F_2 ( V_4 , V_8 , F_4 ( V_2 ) ) ;
F_5 ( V_4 , V_9 , F_6 ( V_2 ) ) ;
F_7 ( V_4 ) ;
return V_10 ;
}
int F_8 ( struct V_1 * V_1 , bool V_11 )
{
struct V_3 * V_4 = V_1 -> V_4 ;
unsigned char V_12 [ 3 ] ;
int V_13 ;
V_12 [ 0 ] = V_14 ;
V_12 [ 1 ] = V_15 ;
V_13 = F_9 ( 2 , 3 , V_16 ) ;
if ( F_10 ( & V_1 -> V_17 , V_12 , V_13 ) )
return - V_18 ;
if ( V_12 [ 0 ] != V_16 || V_12 [ 1 ] != 0x01 ||
V_12 [ 2 ] != V_15 )
return - V_18 ;
if ( V_11 ) {
V_4 -> V_19 [ 0 ] = F_11 ( V_20 ) | F_11 ( V_21 ) ;
V_4 -> V_22 [ F_12 ( V_23 ) ] = 0 ;
V_4 -> V_22 [ F_12 ( V_9 ) ] = F_11 ( V_9 ) ;
F_13 ( V_4 , V_7 , 0 , V_24 , 0 , 0 ) ;
F_13 ( V_4 , V_8 , 0 , V_25 , 0 , 0 ) ;
V_1 -> V_26 = L_1 ;
V_1 -> V_27 = L_2 ;
V_1 -> V_28 = F_1 ;
V_1 -> V_29 = 5 ;
}
return 0 ;
}
