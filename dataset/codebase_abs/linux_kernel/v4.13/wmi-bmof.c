static T_1
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 ,
char * V_7 , T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 =
F_2 ( V_6 , struct V_10 , V_12 ) ;
if ( V_8 < 0 )
return - V_13 ;
if ( V_8 >= V_11 -> V_14 -> V_15 . V_16 )
return 0 ;
if ( V_9 > V_11 -> V_14 -> V_15 . V_16 - V_8 )
V_9 = V_11 -> V_14 -> V_15 . V_16 - V_8 ;
memcpy ( V_7 , V_11 -> V_14 -> V_15 . V_17 + V_8 , V_9 ) ;
return V_9 ;
}
static int F_3 ( struct V_18 * V_19 )
{
struct V_10 * V_11 ;
int V_20 ;
V_11 = F_4 ( & V_19 -> V_21 , sizeof( struct V_10 ) , V_22 ) ;
if ( ! V_11 )
return - V_23 ;
F_5 ( & V_19 -> V_21 , V_11 ) ;
V_11 -> V_14 = F_6 ( V_19 , 0 ) ;
if ( ! V_11 -> V_14 ) {
F_7 ( & V_19 -> V_21 , L_1 ) ;
return - V_24 ;
}
if ( V_11 -> V_14 -> type != V_25 ) {
F_7 ( & V_19 -> V_21 , L_2 ) ;
V_20 = - V_24 ;
goto V_26;
}
F_8 ( & V_11 -> V_12 ) ;
V_11 -> V_12 . V_6 . V_27 = L_3 ;
V_11 -> V_12 . V_6 . V_28 = 0400 ;
V_11 -> V_12 . V_29 = F_1 ;
V_11 -> V_12 . V_30 = V_11 -> V_14 -> V_15 . V_16 ;
V_20 = F_9 ( & V_19 -> V_21 . V_4 , & V_11 -> V_12 ) ;
if ( V_20 )
goto V_26;
return 0 ;
V_26:
F_10 ( V_11 -> V_14 ) ;
return V_20 ;
}
static int F_11 ( struct V_18 * V_19 )
{
struct V_10 * V_11 = F_12 ( & V_19 -> V_21 ) ;
F_13 ( & V_19 -> V_21 . V_4 , & V_11 -> V_12 ) ;
F_10 ( V_11 -> V_14 ) ;
return 0 ;
}
