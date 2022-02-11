static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_8 != 2 )
return - V_9 ;
if ( V_7 [ 0 ] ) {
V_4 -> V_10 &= ~ V_7 [ 0 ] ;
V_4 -> V_10 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_2 ( V_4 -> V_10 , V_2 -> V_11 + V_12 ) ;
}
V_7 [ 1 ] = V_4 -> V_10 ;
return 2 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_6 -> V_8 != 2 )
return - V_9 ;
V_7 [ 1 ] = F_4 ( V_2 -> V_11 + V_13 ) ;
return 2 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_14 * V_15 )
{
struct V_3 * V_4 ;
unsigned long V_11 ;
V_11 = V_15 -> V_16 [ 0 ] ;
F_6 ( V_17 L_1 , V_2 -> V_18 , V_11 ) ;
if ( ! F_7 ( V_11 , V_19 , L_2 ) ) {
F_6 ( L_3 ) ;
return - V_20 ;
}
V_2 -> V_21 = L_2 ;
V_2 -> V_11 = V_11 ;
V_2 -> V_22 = 0 ;
if ( F_8 ( V_2 , 2 ) < 0 )
return - V_23 ;
V_4 = V_2 -> V_24 + 0 ;
V_4 -> type = V_25 ;
V_4 -> V_26 = V_27 ;
V_4 -> V_28 = 1 ;
V_4 -> V_29 = 8 ;
V_4 -> V_30 = F_1 ;
V_4 -> V_31 = & V_32 ;
V_4 = V_2 -> V_24 + 1 ;
V_4 -> type = V_33 ;
V_4 -> V_26 = V_34 ;
V_4 -> V_28 = 1 ;
V_4 -> V_29 = 8 ;
V_4 -> V_30 = F_3 ;
V_4 -> V_31 = & V_32 ;
F_6 ( V_17 L_4 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_11 )
F_10 ( V_2 -> V_11 , V_19 ) ;
}
