static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 V_6 [ 2 ] ;
struct V_7 * V_8 ;
struct V_9 * V_10 ;
int V_11 = - V_12 ;
int V_13 ;
V_10 = F_2 ( sizeof( * V_10 ) , V_14 ) ;
if ( ! V_10 ) {
F_3 ( & V_2 -> V_15 , L_1 ) ;
goto V_16;
}
V_10 -> V_15 = & V_2 -> V_15 ;
V_11 = F_4 ( V_2 ) ;
if ( V_11 ) {
F_3 ( & V_2 -> V_15 , L_2 ) ;
goto V_17;
}
F_5 ( V_2 , V_18 ) ;
F_6 ( V_2 ) ;
V_13 = F_7 () ;
if ( V_13 < 0 )
goto V_19;
V_8 = F_8 ( L_3 , V_13 ) ;
if ( ! V_8 ) {
F_3 ( & V_2 -> V_15 , L_4 ) ;
goto V_20;
}
memset ( V_6 , 0x00 , sizeof( struct V_5 ) * F_9 ( V_6 ) ) ;
V_6 [ 0 ] . V_21 = F_10 ( V_2 , 0 ) ;
V_6 [ 0 ] . V_22 = F_11 ( V_2 , 0 ) ;
V_6 [ 0 ] . V_23 = L_5 ;
V_6 [ 0 ] . V_24 = V_25 ;
V_6 [ 1 ] . V_21 = V_2 -> V_26 ;
V_6 [ 1 ] . V_23 = L_5 ;
V_6 [ 1 ] . V_24 = V_27 ;
V_11 = F_12 ( V_8 , V_6 , F_9 ( V_6 ) ) ;
if ( V_11 ) {
F_3 ( & V_2 -> V_15 , L_6 ) ;
goto V_28;
}
F_13 ( V_2 , V_10 ) ;
F_14 ( & V_8 -> V_15 , V_2 -> V_15 . V_29 ) ;
V_8 -> V_15 . V_30 = V_2 -> V_15 . V_30 ;
V_8 -> V_15 . V_31 = V_2 -> V_15 . V_31 ;
V_8 -> V_15 . V_32 = & V_2 -> V_15 ;
V_10 -> V_8 = V_8 ;
V_11 = F_15 ( V_8 ) ;
if ( V_11 ) {
F_3 ( & V_2 -> V_15 , L_7 ) ;
goto V_28;
}
return 0 ;
V_28:
F_13 ( V_2 , NULL ) ;
F_16 ( V_8 ) ;
V_20:
F_17 ( V_13 ) ;
V_19:
F_18 ( V_2 ) ;
V_17:
F_19 ( V_10 ) ;
V_16:
return V_11 ;
}
static void T_2 F_20 ( struct V_1 * V_2 )
{
struct V_9 * V_10 = F_21 ( V_2 ) ;
F_17 ( V_10 -> V_8 -> V_4 ) ;
F_22 ( V_10 -> V_8 ) ;
F_13 ( V_2 , NULL ) ;
F_18 ( V_2 ) ;
F_19 ( V_10 ) ;
}
static int T_1 F_23 ( void )
{
return F_24 ( & V_33 ) ;
}
static void T_3 F_25 ( void )
{
F_26 ( & V_33 ) ;
}
