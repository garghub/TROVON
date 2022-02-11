static int T_1 F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
struct V_5 * V_6 ;
int V_7 ;
memset ( & V_4 , 0x00 , sizeof( V_4 ) ) ;
V_6 = F_2 ( L_1 , 0 ) ;
if ( ! V_6 )
return - V_8 ;
V_2 -> V_9 = V_6 ;
V_4 . type = V_10 ;
V_7 = F_3 ( V_2 -> V_9 , & V_4 , sizeof( V_4 ) ) ;
if ( V_7 )
goto V_11;
V_6 = F_2 ( L_1 , 1 ) ;
if ( ! V_6 ) {
V_7 = - V_8 ;
goto V_11;
}
V_2 -> V_12 = V_6 ;
V_4 . type = V_13 ;
V_7 = F_3 ( V_2 -> V_12 , & V_4 , sizeof( V_4 ) ) ;
if ( V_7 )
goto V_14;
V_7 = F_4 ( V_2 -> V_9 ) ;
if ( V_7 )
goto V_14;
V_7 = F_4 ( V_2 -> V_12 ) ;
if ( V_7 )
goto V_15;
return 0 ;
V_15:
F_5 ( V_2 -> V_9 ) ;
V_14:
F_6 ( V_2 -> V_12 ) ;
V_11:
F_6 ( V_2 -> V_9 ) ;
return V_7 ;
}
static int T_1 F_7 ( struct V_16 * V_17 ,
const struct V_18 * V_19 )
{
struct V_20 V_21 [ 2 ] ;
struct V_5 * V_22 ;
struct V_1 * V_2 ;
int V_7 = - V_8 ;
int V_23 ;
struct V_24 * V_25 = & V_17 -> V_25 ;
V_2 = F_8 ( V_25 , sizeof( * V_2 ) , V_26 ) ;
if ( ! V_2 ) {
F_9 ( V_25 , L_2 ) ;
return - V_8 ;
}
V_2 -> V_25 = V_25 ;
V_7 = F_10 ( V_17 ) ;
if ( V_7 ) {
F_9 ( V_25 , L_3 ) ;
return - V_27 ;
}
F_11 ( V_17 , V_28 ) ;
F_12 ( V_17 ) ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 ) {
F_9 ( V_25 , L_4 ) ;
return V_7 ;
}
V_23 = F_13 () ;
if ( V_23 < 0 ) {
V_7 = - V_8 ;
goto V_11;
}
V_22 = F_2 ( L_5 , V_23 ) ;
if ( ! V_22 ) {
F_9 ( V_25 , L_6 ) ;
V_7 = - V_8 ;
goto V_11;
}
memset ( V_21 , 0x00 , sizeof( struct V_20 ) * F_14 ( V_21 ) ) ;
V_21 [ 0 ] . V_29 = F_15 ( V_17 , 0 ) ;
V_21 [ 0 ] . V_30 = F_16 ( V_17 , 0 ) ;
V_21 [ 0 ] . V_31 = L_7 ;
V_21 [ 0 ] . V_32 = V_33 ;
V_21 [ 1 ] . V_29 = V_17 -> V_34 ;
V_21 [ 1 ] . V_31 = L_7 ;
V_21 [ 1 ] . V_32 = V_35 ;
V_7 = F_17 ( V_22 , V_21 , F_14 ( V_21 ) ) ;
if ( V_7 ) {
F_9 ( V_25 , L_8 ) ;
goto V_14;
}
F_18 ( V_17 , V_2 ) ;
F_19 ( & V_22 -> V_25 , V_25 -> V_36 ) ;
V_22 -> V_25 . V_37 = V_25 -> V_37 ;
V_22 -> V_25 . V_38 = V_25 -> V_38 ;
V_22 -> V_25 . V_39 = V_25 ;
V_2 -> V_22 = V_22 ;
V_7 = F_4 ( V_22 ) ;
if ( V_7 ) {
F_9 ( V_25 , L_9 ) ;
goto V_15;
}
return 0 ;
V_15:
F_18 ( V_17 , NULL ) ;
F_6 ( V_22 ) ;
V_14:
F_20 ( V_23 ) ;
V_11:
F_21 ( V_17 ) ;
return V_7 ;
}
static void T_2 F_22 ( struct V_16 * V_17 )
{
struct V_1 * V_2 = F_23 ( V_17 ) ;
F_24 ( V_2 -> V_9 ) ;
F_24 ( V_2 -> V_12 ) ;
F_20 ( V_2 -> V_22 -> V_19 ) ;
F_24 ( V_2 -> V_22 ) ;
F_18 ( V_17 , NULL ) ;
F_21 ( V_17 ) ;
}
