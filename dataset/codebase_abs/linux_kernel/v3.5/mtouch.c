static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_3 ;
if ( V_4 == ++ V_1 -> V_5 ) {
F_2 ( V_3 , V_6 , F_3 ( V_1 -> V_7 ) ) ;
F_2 ( V_3 , V_8 , V_9 - F_4 ( V_1 -> V_7 ) ) ;
F_5 ( V_3 , V_10 , F_6 ( V_1 -> V_7 ) ) ;
F_7 ( V_3 ) ;
V_1 -> V_5 = 0 ;
}
}
static void F_8 ( struct V_1 * V_1 )
{
if ( V_11 == V_1 -> V_7 [ V_1 -> V_5 ++ ] ) {
V_1 -> V_5 = 0 ;
} else if ( V_12 == V_1 -> V_5 ) {
F_9 ( V_13 L_1 ) ;
V_1 -> V_5 = 0 ;
}
}
static T_1 F_10 ( struct V_14 * V_14 ,
unsigned char V_7 , unsigned int V_15 )
{
struct V_1 * V_1 = F_11 ( V_14 ) ;
V_1 -> V_7 [ V_1 -> V_5 ] = V_7 ;
if ( V_16 & V_1 -> V_7 [ 0 ] )
F_1 ( V_1 ) ;
else if ( V_17 == V_1 -> V_7 [ 0 ] )
F_8 ( V_1 ) ;
else
F_9 ( V_18 L_2 , V_1 -> V_7 [ 0 ] ) ;
return V_19 ;
}
static void F_12 ( struct V_14 * V_14 )
{
struct V_1 * V_1 = F_11 ( V_14 ) ;
F_13 ( V_1 -> V_3 ) ;
F_14 ( V_1 -> V_3 ) ;
F_15 ( V_14 ) ;
F_16 ( V_14 , NULL ) ;
F_17 ( V_1 -> V_3 ) ;
F_18 ( V_1 ) ;
}
static int F_19 ( struct V_14 * V_14 , struct V_20 * V_21 )
{
struct V_1 * V_1 ;
struct V_2 * V_2 ;
int V_22 ;
V_1 = F_20 ( sizeof( struct V_1 ) , V_23 ) ;
V_2 = F_21 () ;
if ( ! V_1 || ! V_2 ) {
V_22 = - V_24 ;
goto V_25;
}
V_1 -> V_14 = V_14 ;
V_1 -> V_3 = V_2 ;
snprintf ( V_1 -> V_26 , sizeof( V_1 -> V_26 ) , L_3 , V_14 -> V_26 ) ;
V_2 -> V_27 = L_4 ;
V_2 -> V_26 = V_1 -> V_26 ;
V_2 -> V_28 . V_29 = V_30 ;
V_2 -> V_28 . V_31 = V_32 ;
V_2 -> V_28 . V_33 = 0 ;
V_2 -> V_28 . V_34 = 0x0100 ;
V_2 -> V_3 . V_35 = & V_14 -> V_3 ;
V_2 -> V_36 [ 0 ] = F_22 ( V_37 ) | F_22 ( V_38 ) ;
V_2 -> V_39 [ F_23 ( V_10 ) ] = F_22 ( V_10 ) ;
F_24 ( V_1 -> V_3 , V_6 , V_40 , V_41 , 0 , 0 ) ;
F_24 ( V_1 -> V_3 , V_8 , V_42 , V_9 , 0 , 0 ) ;
F_16 ( V_14 , V_1 ) ;
V_22 = F_25 ( V_14 , V_21 ) ;
if ( V_22 )
goto V_43;
V_22 = F_26 ( V_1 -> V_3 ) ;
if ( V_22 )
goto V_44;
return 0 ;
V_44: F_15 ( V_14 ) ;
V_43: F_16 ( V_14 , NULL ) ;
V_25: F_27 ( V_2 ) ;
F_18 ( V_1 ) ;
return V_22 ;
}
