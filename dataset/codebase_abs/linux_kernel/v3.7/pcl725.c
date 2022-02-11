static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
if ( V_7 [ 0 ] ) {
V_4 -> V_8 &= ~ V_7 [ 0 ] ;
V_4 -> V_8 |= ( V_7 [ 0 ] & V_7 [ 1 ] ) ;
F_2 ( V_4 -> V_8 , V_2 -> V_9 + V_10 ) ;
}
V_7 [ 1 ] = V_4 -> V_8 ;
return V_6 -> V_11 ;
}
static int F_3 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , unsigned int * V_7 )
{
V_7 [ 1 ] = F_4 ( V_2 -> V_9 + V_12 ) ;
return V_6 -> V_11 ;
}
static int F_5 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_3 * V_4 ;
unsigned long V_9 ;
int V_15 ;
V_9 = V_14 -> V_16 [ 0 ] ;
F_6 ( V_17 L_1 , V_2 -> V_18 , V_9 ) ;
if ( ! F_7 ( V_9 , V_19 , L_2 ) ) {
F_6 ( L_3 ) ;
return - V_20 ;
}
V_2 -> V_21 = L_2 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_22 = 0 ;
V_15 = F_8 ( V_2 , 2 ) ;
if ( V_15 )
return V_15 ;
V_4 = & V_2 -> V_23 [ 0 ] ;
V_4 -> type = V_24 ;
V_4 -> V_25 = V_26 ;
V_4 -> V_27 = 1 ;
V_4 -> V_28 = 8 ;
V_4 -> V_29 = F_1 ;
V_4 -> V_30 = & V_31 ;
V_4 = & V_2 -> V_23 [ 1 ] ;
V_4 -> type = V_32 ;
V_4 -> V_25 = V_33 ;
V_4 -> V_27 = 1 ;
V_4 -> V_28 = 8 ;
V_4 -> V_29 = F_3 ;
V_4 -> V_30 = & V_31 ;
F_6 ( V_17 L_4 ) ;
return 0 ;
}
static void F_9 ( struct V_1 * V_2 )
{
if ( V_2 -> V_9 )
F_10 ( V_2 -> V_9 , V_19 ) ;
}
