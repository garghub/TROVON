static int F_1 ( struct V_1 * V_2 )
{
struct V_3 V_4 ;
struct V_5 * V_6 ;
int V_7 ;
memset ( & V_4 , 0x00 , sizeof( V_4 ) ) ;
V_6 = F_2 ( L_1 , V_8 ) ;
if ( ! V_6 )
return - V_9 ;
V_2 -> V_10 = V_6 ;
V_4 . type = V_11 ;
V_7 = F_3 ( V_2 -> V_10 , & V_4 , sizeof( V_4 ) ) ;
if ( V_7 )
goto V_12;
V_6 = F_2 ( L_1 , V_8 ) ;
if ( ! V_6 ) {
V_7 = - V_9 ;
goto V_12;
}
V_2 -> V_13 = V_6 ;
V_4 . type = V_14 ;
V_7 = F_3 ( V_2 -> V_13 , & V_4 , sizeof( V_4 ) ) ;
if ( V_7 )
goto V_15;
V_7 = F_4 ( V_2 -> V_10 ) ;
if ( V_7 )
goto V_15;
V_7 = F_4 ( V_2 -> V_13 ) ;
if ( V_7 )
goto V_16;
return 0 ;
V_16:
F_5 ( V_2 -> V_10 ) ;
V_15:
F_6 ( V_2 -> V_13 ) ;
V_12:
F_6 ( V_2 -> V_10 ) ;
return V_7 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_5 * V_17 ;
struct V_1 * V_2 ;
struct V_18 * V_18 ;
struct V_19 * V_20 = & V_6 -> V_20 ;
int V_7 = - V_9 ;
V_2 = F_8 ( V_20 , sizeof( * V_2 ) , V_21 ) ;
if ( ! V_2 ) {
F_9 ( V_20 , L_2 ) ;
return - V_9 ;
}
if ( ! V_6 -> V_20 . V_22 )
V_6 -> V_20 . V_22 = & V_23 ;
F_10 ( V_6 , V_2 ) ;
V_7 = F_1 ( V_2 ) ;
if ( V_7 ) {
F_9 ( V_20 , L_3 ) ;
return V_7 ;
}
V_17 = F_2 ( L_4 , V_8 ) ;
if ( ! V_17 ) {
F_9 ( V_20 , L_5 ) ;
return - V_9 ;
}
V_18 = F_11 ( V_20 , L_6 ) ;
if ( F_12 ( V_18 ) ) {
F_9 ( V_20 , L_7 ) ;
V_7 = - V_24 ;
goto V_12;
}
F_13 ( & V_17 -> V_20 , V_20 -> V_25 ) ;
V_17 -> V_20 . V_26 = V_20 ;
V_17 -> V_20 . V_22 = V_20 -> V_22 ;
V_17 -> V_20 . V_27 = V_20 -> V_27 ;
V_2 -> V_17 = V_17 ;
V_2 -> V_20 = V_20 ;
V_2 -> V_18 = V_18 ;
F_14 ( V_2 -> V_18 ) ;
V_7 = F_15 ( V_17 , V_6 -> V_28 ,
V_6 -> V_29 ) ;
if ( V_7 ) {
F_9 ( V_20 , L_8 ) ;
goto V_15;
}
V_7 = F_4 ( V_17 ) ;
if ( V_7 ) {
F_9 ( V_20 , L_9 ) ;
goto V_15;
}
return 0 ;
V_15:
F_16 ( V_18 ) ;
V_12:
F_6 ( V_17 ) ;
return V_7 ;
}
static int F_17 ( struct V_5 * V_6 )
{
struct V_1 * V_2 = F_18 ( V_6 ) ;
F_19 ( V_2 -> V_17 ) ;
F_19 ( V_2 -> V_10 ) ;
F_19 ( V_2 -> V_13 ) ;
F_16 ( V_2 -> V_18 ) ;
return 0 ;
}
