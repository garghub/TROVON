static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
V_4:
V_3 = F_2 ( V_5 , V_6 ) ;
if ( V_3 < V_6 ) {
int V_7 ;
V_7 = F_3 ( V_3 , V_5 ) ;
if ( V_7 )
goto V_4;
} else {
F_4 ( V_2 -> V_8 , L_1 ) ;
V_3 = - V_9 ;
}
return 0 ;
}
static void F_5 ( struct V_1 * V_2 , int V_3 )
{
int V_10 ;
if ( V_3 < 0 )
return;
V_10 = F_6 ( V_3 , V_5 ) ;
F_7 ( ! V_10 , L_2 ,
F_8 ( V_2 -> V_8 ) , V_3 ) ;
F_9 ( V_3 , V_5 ) ;
}
static int T_1 F_10 ( struct V_11 * V_12 ,
const struct V_13 * V_3 )
{
struct V_14 V_15 [ 2 ] ;
struct V_16 * V_17 ;
struct V_1 * V_2 ;
int V_10 = - V_9 ;
int V_18 ;
V_2 = F_11 ( sizeof( * V_2 ) , V_19 ) ;
if ( ! V_2 ) {
F_4 ( & V_12 -> V_8 , L_3 ) ;
goto V_20;
}
V_2 -> V_8 = & V_12 -> V_8 ;
V_10 = F_12 ( V_12 ) ;
if ( V_10 ) {
F_4 ( & V_12 -> V_8 , L_4 ) ;
goto V_21;
}
F_13 ( V_12 , V_22 ) ;
F_14 ( V_12 ) ;
V_18 = F_1 ( V_2 ) ;
if ( V_18 < 0 )
goto V_23;
V_17 = F_15 ( L_5 , V_18 ) ;
if ( ! V_17 ) {
F_4 ( & V_12 -> V_8 , L_6 ) ;
goto V_24;
}
memset ( V_15 , 0x00 , sizeof( struct V_14 ) * F_16 ( V_15 ) ) ;
V_15 [ 0 ] . V_25 = F_17 ( V_12 , 0 ) ;
V_15 [ 0 ] . V_26 = F_18 ( V_12 , 0 ) ;
V_15 [ 0 ] . V_27 = L_7 ;
V_15 [ 0 ] . V_28 = V_29 ;
V_15 [ 1 ] . V_25 = V_12 -> V_30 ;
V_15 [ 1 ] . V_27 = L_7 ;
V_15 [ 1 ] . V_28 = V_31 ;
V_10 = F_19 ( V_17 , V_15 , F_16 ( V_15 ) ) ;
if ( V_10 ) {
F_4 ( & V_12 -> V_8 , L_8 ) ;
goto V_32;
}
F_20 ( V_12 , V_2 ) ;
F_21 ( & V_17 -> V_8 , V_12 -> V_8 . V_33 ) ;
V_17 -> V_8 . V_34 = V_12 -> V_8 . V_34 ;
V_17 -> V_8 . V_35 = V_12 -> V_8 . V_35 ;
V_17 -> V_8 . V_36 = & V_12 -> V_8 ;
V_2 -> V_17 = V_17 ;
V_10 = F_22 ( V_17 ) ;
if ( V_10 ) {
F_4 ( & V_12 -> V_8 , L_9 ) ;
goto V_32;
}
return 0 ;
V_32:
F_20 ( V_12 , NULL ) ;
F_23 ( V_17 ) ;
V_24:
F_5 ( V_2 , V_18 ) ;
V_23:
F_24 ( V_12 ) ;
V_21:
F_25 ( V_12 ) ;
V_20:
return V_10 ;
}
static void T_2 F_26 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = F_27 ( V_12 ) ;
F_5 ( V_2 , V_2 -> V_17 -> V_3 ) ;
F_28 ( V_2 -> V_17 ) ;
F_20 ( V_12 , NULL ) ;
F_24 ( V_12 ) ;
F_25 ( V_2 ) ;
}
static int T_1 F_29 ( void )
{
return F_30 ( & V_37 ) ;
}
static void T_3 F_31 ( void )
{
F_32 ( & V_37 ) ;
}
