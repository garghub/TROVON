static T_1 F_1 ( struct V_1 * V_1 ,
unsigned char V_2 , unsigned int V_3 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
struct V_5 * V_6 = V_4 -> V_6 ;
if ( V_2 ) {
V_4 -> V_7 = 1 ;
V_4 -> V_2 [ V_4 -> V_8 ++ ] = V_2 ;
if ( V_4 -> V_8 == V_9 && V_4 -> V_2 [ 1 ] == V_4 -> V_2 [ 2 ] ) {
F_3 ( V_6 , V_10 , V_4 -> V_2 [ 0 ] ) ;
F_3 ( V_6 , V_11 , V_4 -> V_2 [ 1 ] ) ;
F_4 ( V_6 , V_12 , 1 ) ;
F_5 ( V_6 ) ;
V_4 -> V_8 = 0 ;
}
} else if ( V_4 -> V_7 ) {
F_4 ( V_6 , V_12 , 0 ) ;
F_5 ( V_6 ) ;
V_4 -> V_8 = 0 ;
V_4 -> V_7 = 0 ;
}
return V_13 ;
}
static void F_6 ( struct V_1 * V_1 )
{
struct V_4 * V_4 = F_2 ( V_1 ) ;
F_7 ( V_4 -> V_6 ) ;
F_8 ( V_4 -> V_6 ) ;
F_9 ( V_1 ) ;
F_10 ( V_1 , NULL ) ;
F_11 ( V_4 -> V_6 ) ;
F_12 ( V_4 ) ;
}
static int F_13 ( struct V_1 * V_1 , struct V_14 * V_15 )
{
struct V_4 * V_4 ;
struct V_5 * V_5 ;
int V_16 ;
V_4 = F_14 ( sizeof( struct V_4 ) , V_17 ) ;
V_5 = F_15 () ;
if ( ! V_4 || ! V_5 ) {
V_16 = - V_18 ;
goto V_19;
}
V_4 -> V_1 = V_1 ;
V_4 -> V_6 = V_5 ;
snprintf ( V_4 -> V_20 , sizeof( V_4 -> V_20 ) , L_1 , V_1 -> V_20 ) ;
V_5 -> V_21 = L_2 ;
V_5 -> V_20 = V_4 -> V_20 ;
V_5 -> V_22 . V_23 = V_24 ;
V_5 -> V_22 . V_25 = V_26 ;
V_5 -> V_22 . V_27 = 0 ;
V_5 -> V_22 . V_28 = 0x0100 ;
V_5 -> V_6 . V_29 = & V_1 -> V_6 ;
V_5 -> V_30 [ 0 ] = F_16 ( V_31 ) | F_16 ( V_32 ) ;
V_5 -> V_33 [ F_17 ( V_12 ) ] = F_16 ( V_12 ) ;
F_18 ( V_4 -> V_6 , V_10 , V_34 , V_35 , 0 , 0 ) ;
F_18 ( V_4 -> V_6 , V_11 , V_36 , V_37 , 0 , 0 ) ;
F_10 ( V_1 , V_4 ) ;
V_16 = F_19 ( V_1 , V_15 ) ;
if ( V_16 )
goto V_38;
V_16 = F_20 ( V_4 -> V_6 ) ;
if ( V_16 )
goto V_39;
return 0 ;
V_39: F_9 ( V_1 ) ;
V_38: F_10 ( V_1 , NULL ) ;
V_19: F_21 ( V_5 ) ;
F_12 ( V_4 ) ;
return V_16 ;
}
