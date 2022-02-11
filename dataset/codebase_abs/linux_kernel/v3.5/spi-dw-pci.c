static int T_1 F_1 ( struct V_1 * V_2 ,
const struct V_3 * V_4 )
{
struct V_5 * V_6 ;
struct V_7 * V_8 ;
int V_9 = 0 ;
int V_10 ;
F_2 ( V_11 L_1 ,
V_2 -> V_12 , V_2 -> V_13 ) ;
V_10 = F_3 ( V_2 ) ;
if ( V_10 )
return V_10 ;
V_6 = F_4 ( sizeof( struct V_5 ) , V_14 ) ;
if ( ! V_6 ) {
V_10 = - V_15 ;
goto V_16;
}
V_6 -> V_2 = V_2 ;
V_8 = & V_6 -> V_8 ;
V_8 -> V_17 = F_5 ( V_2 , V_9 ) ;
V_8 -> V_18 = F_6 ( V_2 , V_9 ) ;
V_10 = F_7 ( V_2 , V_9 , F_8 ( & V_2 -> V_19 ) ) ;
if ( V_10 )
goto V_20;
V_8 -> V_21 = F_9 ( ( unsigned long ) V_8 -> V_17 ,
F_6 ( V_2 , V_9 ) ) ;
if ( ! V_8 -> V_21 ) {
V_10 = - V_15 ;
goto V_22;
}
V_8 -> V_23 = & V_2 -> V_19 ;
V_8 -> V_24 = 0 ;
V_8 -> V_25 = 4 ;
V_8 -> V_26 = V_2 -> V_26 ;
if ( V_2 -> V_13 == 0x0800 ) {
V_10 = F_10 ( V_8 ) ;
if ( V_10 )
goto V_27;
}
V_10 = F_11 ( V_8 ) ;
if ( V_10 )
goto V_27;
F_12 ( V_2 , V_6 ) ;
return 0 ;
V_27:
F_13 ( V_8 -> V_21 ) ;
V_22:
F_14 ( V_2 , V_9 ) ;
V_20:
F_15 ( V_6 ) ;
V_16:
F_16 ( V_2 ) ;
return V_10 ;
}
static void T_2 F_17 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
F_12 ( V_2 , NULL ) ;
F_19 ( & V_6 -> V_8 ) ;
F_13 ( V_6 -> V_8 . V_21 ) ;
F_14 ( V_2 , 0 ) ;
F_15 ( V_6 ) ;
F_16 ( V_2 ) ;
}
static int F_20 ( struct V_1 * V_2 , T_3 V_28 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
int V_10 ;
V_10 = F_21 ( & V_6 -> V_8 ) ;
if ( V_10 )
return V_10 ;
F_22 ( V_2 ) ;
F_16 ( V_2 ) ;
F_23 ( V_2 , F_24 ( V_2 , V_28 ) ) ;
return V_10 ;
}
static int F_25 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_18 ( V_2 ) ;
int V_10 ;
F_23 ( V_2 , V_29 ) ;
F_26 ( V_2 ) ;
V_10 = F_3 ( V_2 ) ;
if ( V_10 )
return V_10 ;
return F_27 ( & V_6 -> V_8 ) ;
}
