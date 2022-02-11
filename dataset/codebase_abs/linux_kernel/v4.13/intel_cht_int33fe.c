static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_4 ;
struct V_5 V_6 ;
struct V_7 * V_8 ;
unsigned long long V_9 ;
T_1 V_10 ;
int V_11 ;
V_10 = F_2 ( F_3 ( V_4 ) , L_1 , NULL , & V_9 ) ;
if ( F_4 ( V_10 ) ) {
F_5 ( V_4 , L_2 ) ;
return - V_12 ;
}
if ( V_9 != V_13 )
return - V_12 ;
V_11 = F_6 ( F_7 ( V_4 ) , 1 ) ;
if ( V_11 < 0 ) {
if ( V_11 != - V_14 )
F_5 ( V_4 , L_3 ) ;
return V_11 ;
}
V_8 = F_8 ( V_4 , sizeof( * V_8 ) , V_15 ) ;
if ( ! V_8 )
return - V_16 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
F_9 ( V_6 . type , L_4 , V_17 ) ;
V_6 . V_18 = V_19 ;
V_8 -> V_20 = F_10 ( V_4 , 1 , & V_6 ) ;
if ( ! V_8 -> V_20 )
return - V_14 ;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
F_9 ( V_6 . type , L_5 , V_17 ) ;
V_6 . V_21 = V_11 ;
V_8 -> V_22 = F_10 ( V_4 , 2 , & V_6 ) ;
if ( ! V_8 -> V_22 )
goto V_23;
memset ( & V_6 , 0 , sizeof( V_6 ) ) ;
F_9 ( V_6 . type , L_6 , V_17 ) ;
V_8 -> V_24 = F_10 ( V_4 , 3 , & V_6 ) ;
if ( ! V_8 -> V_24 )
goto V_25;
F_11 ( V_2 , V_8 ) ;
return 0 ;
V_25:
F_12 ( V_8 -> V_22 ) ;
V_23:
F_12 ( V_8 -> V_20 ) ;
return - V_14 ;
}
static int F_13 ( struct V_1 * V_26 )
{
struct V_7 * V_8 = F_14 ( V_26 ) ;
F_12 ( V_8 -> V_24 ) ;
F_12 ( V_8 -> V_22 ) ;
F_12 ( V_8 -> V_20 ) ;
return 0 ;
}
