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
static int T_1 F_7 ( struct V_5 * V_6 )
{
struct V_16 * V_4 = V_6 -> V_17 . V_18 ;
struct V_5 * V_19 ;
struct V_1 * V_2 ;
struct V_20 * V_20 ;
int V_21 ;
int V_7 = - V_8 ;
V_2 = F_8 ( sizeof( * V_2 ) , V_22 ) ;
if ( ! V_2 ) {
F_9 ( & V_6 -> V_17 , L_2 ) ;
goto V_23;
}
F_10 ( V_6 , V_2 ) ;
V_21 = F_11 () ;
if ( V_21 < 0 )
goto V_11;
V_7 = F_1 ( V_2 ) ;
if ( V_7 ) {
F_9 ( & V_6 -> V_17 , L_3 ) ;
goto V_11;
}
V_19 = F_2 ( L_4 , V_21 ) ;
if ( ! V_19 ) {
F_9 ( & V_6 -> V_17 , L_5 ) ;
goto V_14;
}
V_20 = F_12 ( & V_6 -> V_17 , L_6 ) ;
if ( F_13 ( V_20 ) ) {
F_9 ( & V_6 -> V_17 , L_7 ) ;
V_7 = - V_24 ;
goto V_15;
}
F_14 ( & V_19 -> V_17 , V_6 -> V_17 . V_25 ) ;
V_19 -> V_17 . V_26 = & V_6 -> V_17 ;
V_19 -> V_17 . V_27 = V_6 -> V_17 . V_27 ;
V_19 -> V_17 . V_28 = V_6 -> V_17 . V_28 ;
V_2 -> V_19 = V_19 ;
V_2 -> V_17 = & V_6 -> V_17 ;
V_2 -> V_20 = V_20 ;
F_15 ( V_2 -> V_20 ) ;
if ( ! V_4 ) {
F_16 ( & V_6 -> V_17 , L_8 ) ;
} else {
if ( V_4 -> V_29 )
V_4 -> V_29 ( V_6 , V_4 -> V_30 ) ;
}
V_7 = F_17 ( V_19 , V_6 -> V_31 ,
V_6 -> V_32 ) ;
if ( V_7 ) {
F_9 ( & V_6 -> V_17 , L_9 ) ;
goto V_33;
}
V_7 = F_4 ( V_19 ) ;
if ( V_7 ) {
F_9 ( & V_6 -> V_17 , L_10 ) ;
goto V_33;
}
return 0 ;
V_33:
if ( V_4 && V_4 -> V_34 )
V_4 -> V_34 ( V_6 , V_4 -> V_30 ) ;
F_18 ( V_20 ) ;
F_19 ( V_20 ) ;
V_15:
F_6 ( V_19 ) ;
V_14:
F_20 ( V_21 ) ;
V_11:
F_21 ( V_2 ) ;
V_23:
return V_7 ;
}
static int T_2 F_22 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_23 ( V_6 ) ;
struct V_16 * V_4 = V_6 -> V_17 . V_18 ;
F_24 ( V_2 -> V_19 ) ;
F_24 ( V_2 -> V_9 ) ;
F_24 ( V_2 -> V_12 ) ;
F_20 ( V_2 -> V_19 -> V_35 ) ;
if ( V_4 && V_4 -> V_34 )
V_4 -> V_34 ( V_6 , V_4 -> V_30 ) ;
F_18 ( V_2 -> V_20 ) ;
F_19 ( V_2 -> V_20 ) ;
F_21 ( V_2 ) ;
return 0 ;
}
