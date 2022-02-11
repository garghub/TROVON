static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 = ( void * ) V_4 -> V_7 ;
struct V_8 * V_9 ;
struct V_10 V_11 [ 3 ] ;
int V_12 = 0 , V_13 = 2 ;
if ( ! V_6 ) {
F_2 ( & V_2 -> V_14 , L_1 ) ;
return - V_15 ;
}
V_12 = F_3 ( V_2 ) ;
if ( V_12 )
goto V_16;
if ( ! V_2 -> V_17 ) {
F_2 ( & V_2 -> V_14 , L_2 ) ;
V_12 = - V_15 ;
goto V_18;
}
F_4 ( V_2 , V_19 ) ;
F_5 ( V_2 ) ;
F_6 ( V_2 ) ;
V_9 = F_7 ( L_3 , - 1 ) ;
if ( ! V_9 ) {
F_2 ( & V_2 -> V_14 , L_4 ) ;
V_12 = - V_20 ;
goto V_18;
}
memset ( V_11 , 0 , sizeof( V_11 ) ) ;
V_11 [ 0 ] . V_21 = F_8 ( V_2 , 0 ) ;
V_11 [ 0 ] . V_22 = F_9 ( V_2 , 0 ) ;
V_11 [ 0 ] . V_23 = V_24 ;
V_11 [ 1 ] . V_21 = V_2 -> V_17 ;
V_11 [ 1 ] . V_23 = V_25 ;
V_12 = F_10 ( V_9 , V_11 , V_13 ) ;
if ( V_12 ) {
F_2 ( & V_2 -> V_14 , L_5 ) ;
goto V_26;
}
V_12 = F_11 ( V_9 , V_6 , sizeof( * V_6 ) ) ;
if ( V_12 )
goto V_26;
F_12 ( & V_9 -> V_14 , V_2 -> V_14 . V_27 ) ;
V_9 -> V_14 . V_28 = V_2 -> V_14 . V_28 ;
V_9 -> V_14 . V_29 = V_2 -> V_14 . V_29 ;
V_9 -> V_14 . V_30 = & V_2 -> V_14 ;
F_13 ( V_2 , V_9 ) ;
V_12 = F_14 ( V_9 ) ;
if ( V_12 )
goto V_26;
return 0 ;
V_26:
F_13 ( V_2 , NULL ) ;
F_15 ( V_9 ) ;
V_18:
F_16 ( V_2 ) ;
V_16:
return V_12 ;
}
static void T_2 F_17 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = F_18 ( V_2 ) ;
F_19 ( V_9 ) ;
F_13 ( V_2 , NULL ) ;
F_16 ( V_2 ) ;
}
