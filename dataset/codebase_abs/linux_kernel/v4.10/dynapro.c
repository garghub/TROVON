static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_5 == ++ V_2 -> V_6 ) {
F_2 ( V_4 , V_7 , F_3 ( V_2 -> V_8 ) ) ;
F_2 ( V_4 , V_9 , F_4 ( V_2 -> V_8 ) ) ;
F_5 ( V_4 , V_10 ,
F_6 ( V_2 -> V_8 ) ) ;
F_7 ( V_4 ) ;
V_2 -> V_6 = 0 ;
}
}
static T_1 F_8 ( struct V_11 * V_11 ,
unsigned char V_8 , unsigned int V_12 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
V_2 -> V_8 [ V_2 -> V_6 ] = V_8 ;
if ( V_13 & V_2 -> V_8 [ 0 ] )
F_1 ( V_2 ) ;
else
F_10 ( & V_11 -> V_4 , L_1 ,
V_2 -> V_8 [ 0 ] ) ;
return V_14 ;
}
static void F_11 ( struct V_11 * V_11 )
{
struct V_1 * V_2 = F_9 ( V_11 ) ;
F_12 ( V_2 -> V_4 ) ;
F_13 ( V_2 -> V_4 ) ;
F_14 ( V_11 ) ;
F_15 ( V_11 , NULL ) ;
F_16 ( V_2 -> V_4 ) ;
F_17 ( V_2 ) ;
}
static int F_18 ( struct V_11 * V_11 , struct V_15 * V_16 )
{
struct V_1 * V_2 ;
struct V_3 * V_3 ;
int V_17 ;
V_2 = F_19 ( sizeof( struct V_1 ) , V_18 ) ;
V_3 = F_20 () ;
if ( ! V_2 || ! V_3 ) {
V_17 = - V_19 ;
goto V_20;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_4 = V_3 ;
snprintf ( V_2 -> V_21 , sizeof( V_2 -> V_21 ) ,
L_2 , V_11 -> V_21 ) ;
V_3 -> V_22 = L_3 ;
V_3 -> V_21 = V_2 -> V_21 ;
V_3 -> V_23 . V_24 = V_25 ;
V_3 -> V_23 . V_26 = V_27 ;
V_3 -> V_23 . V_28 = 0 ;
V_3 -> V_23 . V_29 = 0x0001 ;
V_3 -> V_4 . V_30 = & V_11 -> V_4 ;
V_3 -> V_31 [ 0 ] = F_21 ( V_32 ) | F_21 ( V_33 ) ;
V_3 -> V_34 [ F_22 ( V_10 ) ] = F_21 ( V_10 ) ;
F_23 ( V_2 -> V_4 , V_7 ,
V_35 , V_36 , 0 , 0 ) ;
F_23 ( V_2 -> V_4 , V_9 ,
V_37 , V_38 , 0 , 0 ) ;
F_15 ( V_11 , V_2 ) ;
V_17 = F_24 ( V_11 , V_16 ) ;
if ( V_17 )
goto V_39;
V_17 = F_25 ( V_2 -> V_4 ) ;
if ( V_17 )
goto V_40;
return 0 ;
V_40: F_14 ( V_11 ) ;
V_39: F_15 ( V_11 , NULL ) ;
V_20: F_26 ( V_3 ) ;
F_17 ( V_2 ) ;
return V_17 ;
}
