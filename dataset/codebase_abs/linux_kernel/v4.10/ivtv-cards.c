const struct V_1 * F_1 ( T_1 V_2 )
{
if ( V_2 >= F_2 ( V_3 ) )
return NULL ;
return V_3 [ V_2 ] ;
}
int F_3 ( struct V_4 * V_5 , T_1 V_2 , struct V_6 * V_7 )
{
const struct V_8 * V_9 = V_5 -> V_10 -> V_11 + V_2 ;
static const char * const V_12 [] = {
L_1 ,
L_2 ,
L_3 ,
L_4 ,
L_5 ,
L_6
} ;
if ( V_2 >= V_5 -> V_13 )
return - V_14 ;
V_7 -> V_2 = V_2 ;
F_4 ( V_7 -> V_15 , V_12 [ V_9 -> V_16 - 1 ] ,
sizeof( V_7 -> V_15 ) ) ;
V_7 -> type = ( V_9 -> V_16 == V_17 ?
V_18 : V_19 ) ;
V_7 -> V_20 = ( 1 << V_5 -> V_21 ) - 1 ;
V_7 -> V_22 = ( V_7 -> type == V_18 ) ?
V_5 -> V_23 : V_24 ;
return 0 ;
}
int F_5 ( struct V_4 * V_5 , T_1 V_2 , struct V_25 * V_26 )
{
const struct V_27 * V_28 = V_5 -> V_10 -> V_29 + V_2 ;
if ( V_2 >= V_5 -> V_10 -> V_30 )
return - V_14 ;
V_26 -> V_2 = V_2 ;
F_4 ( V_26 -> V_15 , V_28 -> V_15 , sizeof( V_26 -> V_15 ) ) ;
V_26 -> type = V_31 ;
V_26 -> V_20 = 1 ;
V_26 -> V_22 = V_24 ;
return 0 ;
}
int F_6 ( struct V_4 * V_5 , T_1 V_2 , struct V_32 * V_33 )
{
const struct V_34 * V_35 = V_5 -> V_10 -> V_36 + V_2 ;
static const char * const V_12 [] = {
L_1 ,
L_7 ,
L_8
} ;
memset ( V_33 , 0 , sizeof( * V_33 ) ) ;
if ( V_2 >= V_5 -> V_21 )
return - V_14 ;
F_4 ( V_33 -> V_15 , V_12 [ V_35 -> V_37 - 1 ] ,
sizeof( V_33 -> V_15 ) ) ;
V_33 -> V_2 = V_2 ;
V_33 -> V_38 = V_39 ;
return 0 ;
}
int F_7 ( struct V_4 * V_5 , T_1 V_2 , struct V_40 * V_41 )
{
memset ( V_41 , 0 , sizeof( * V_41 ) ) ;
if ( V_5 -> V_10 -> V_29 == NULL || V_2 != 0 )
return - V_14 ;
F_4 ( V_41 -> V_15 , L_9 , sizeof( V_41 -> V_15 ) ) ;
return 0 ;
}
