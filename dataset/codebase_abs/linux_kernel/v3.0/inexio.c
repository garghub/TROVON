static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_4 ;
if ( V_5 == ++ V_2 -> V_6 ) {
F_2 ( V_4 , V_7 , F_3 ( V_2 -> V_8 ) ) ;
F_2 ( V_4 , V_9 , F_4 ( V_2 -> V_8 ) ) ;
F_5 ( V_4 , V_10 , F_6 ( V_2 -> V_8 ) ) ;
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
F_10 ( V_14 L_1 , V_2 -> V_8 [ 0 ] ) ;
return V_15 ;
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
static int F_18 ( struct V_11 * V_11 , struct V_16 * V_17 )
{
struct V_1 * V_2 ;
struct V_3 * V_3 ;
int V_18 ;
V_2 = F_19 ( sizeof( struct V_1 ) , V_19 ) ;
V_3 = F_20 () ;
if ( ! V_2 || ! V_3 ) {
V_18 = - V_20 ;
goto V_21;
}
V_2 -> V_11 = V_11 ;
V_2 -> V_4 = V_3 ;
snprintf ( V_2 -> V_22 , sizeof( V_2 -> V_22 ) , L_2 , V_11 -> V_22 ) ;
V_3 -> V_23 = L_3 ;
V_3 -> V_22 = V_2 -> V_22 ;
V_3 -> V_24 . V_25 = V_26 ;
V_3 -> V_24 . V_27 = V_28 ;
V_3 -> V_24 . V_29 = 0 ;
V_3 -> V_24 . V_30 = 0x0001 ;
V_3 -> V_4 . V_31 = & V_11 -> V_4 ;
V_3 -> V_32 [ 0 ] = F_21 ( V_33 ) | F_21 ( V_34 ) ;
V_3 -> V_35 [ F_22 ( V_10 ) ] = F_21 ( V_10 ) ;
F_23 ( V_2 -> V_4 , V_7 , V_36 , V_37 , 0 , 0 ) ;
F_23 ( V_2 -> V_4 , V_9 , V_38 , V_39 , 0 , 0 ) ;
F_15 ( V_11 , V_2 ) ;
V_18 = F_24 ( V_11 , V_17 ) ;
if ( V_18 )
goto V_40;
V_18 = F_25 ( V_2 -> V_4 ) ;
if ( V_18 )
goto V_41;
return 0 ;
V_41: F_14 ( V_11 ) ;
V_40: F_15 ( V_11 , NULL ) ;
V_21: F_26 ( V_3 ) ;
F_17 ( V_2 ) ;
return V_18 ;
}
static int T_2 F_27 ( void )
{
return F_28 ( & V_42 ) ;
}
static void T_3 F_29 ( void )
{
F_30 ( & V_42 ) ;
}
