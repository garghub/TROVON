static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
int V_6 = V_2 -> V_7 . V_6 ;
int V_8 = V_2 -> V_7 . V_9 ;
if ( V_2 -> V_7 . V_10 != V_11 )
V_6 = 0 ;
if ( V_2 -> V_7 . V_12 != V_11 )
V_6 = 0 ;
if ( V_4 -> V_13 )
V_6 = V_4 -> V_13 ( V_4 -> V_5 , V_6 ) ;
if ( V_6 == 0 ) {
F_3 ( V_4 -> V_14 , 0 , V_4 -> V_15 ) ;
F_4 ( V_4 -> V_14 ) ;
} else {
V_6 = V_4 -> V_16 +
( V_6 * ( V_4 -> V_15 - V_4 -> V_16 ) / V_8 ) ;
F_3 ( V_4 -> V_14 , V_6 , V_4 -> V_15 ) ;
F_5 ( V_4 -> V_14 ) ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
return V_2 -> V_7 . V_6 ;
}
static int F_7 ( struct V_1 * V_2 ,
struct V_17 * V_18 )
{
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
return ! V_4 -> V_19 || V_4 -> V_19 ( V_4 -> V_5 , V_18 ) ;
}
static int F_8 ( struct V_20 * V_21 )
{
struct V_22 V_7 ;
struct V_23 * V_24 = V_21 -> V_5 . V_25 ;
struct V_1 * V_2 ;
struct V_3 * V_4 ;
int V_26 ;
if ( ! V_24 ) {
F_9 ( & V_21 -> V_5 , L_1 ) ;
return - V_27 ;
}
if ( V_24 -> V_28 ) {
V_26 = V_24 -> V_28 ( & V_21 -> V_5 ) ;
if ( V_26 < 0 )
return V_26 ;
}
V_4 = F_10 ( sizeof( * V_4 ) , V_29 ) ;
if ( ! V_4 ) {
F_9 ( & V_21 -> V_5 , L_2 ) ;
V_26 = - V_30 ;
goto V_31;
}
V_4 -> V_15 = V_24 -> V_32 ;
V_4 -> V_13 = V_24 -> V_13 ;
V_4 -> V_19 = V_24 -> V_19 ;
V_4 -> V_16 = V_24 -> V_16 *
( V_24 -> V_32 / V_24 -> V_9 ) ;
V_4 -> V_5 = & V_21 -> V_5 ;
V_4 -> V_14 = F_11 ( V_24 -> V_33 , L_3 ) ;
if ( F_12 ( V_4 -> V_14 ) ) {
F_9 ( & V_21 -> V_5 , L_4 ) ;
V_26 = F_13 ( V_4 -> V_14 ) ;
goto V_34;
} else
F_14 ( & V_21 -> V_5 , L_5 ) ;
memset ( & V_7 , 0 , sizeof( struct V_22 ) ) ;
V_7 . type = V_35 ;
V_7 . V_9 = V_24 -> V_9 ;
V_2 = F_15 ( F_16 ( & V_21 -> V_5 ) , & V_21 -> V_5 , V_4 ,
& V_36 , & V_7 ) ;
if ( F_12 ( V_2 ) ) {
F_9 ( & V_21 -> V_5 , L_6 ) ;
V_26 = F_13 ( V_2 ) ;
goto V_37;
}
V_2 -> V_7 . V_6 = V_24 -> V_38 ;
F_17 ( V_2 ) ;
F_18 ( V_21 , V_2 ) ;
return 0 ;
V_37:
F_19 ( V_4 -> V_14 ) ;
V_34:
F_20 ( V_4 ) ;
V_31:
if ( V_24 -> exit )
V_24 -> exit ( & V_21 -> V_5 ) ;
return V_26 ;
}
static int F_21 ( struct V_20 * V_21 )
{
struct V_23 * V_24 = V_21 -> V_5 . V_25 ;
struct V_1 * V_2 = F_22 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
F_23 ( V_2 ) ;
F_3 ( V_4 -> V_14 , 0 , V_4 -> V_15 ) ;
F_4 ( V_4 -> V_14 ) ;
F_19 ( V_4 -> V_14 ) ;
F_20 ( V_4 ) ;
if ( V_24 -> exit )
V_24 -> exit ( & V_21 -> V_5 ) ;
return 0 ;
}
static int F_24 ( struct V_20 * V_21 ,
T_1 V_39 )
{
struct V_1 * V_2 = F_22 ( V_21 ) ;
struct V_3 * V_4 = F_2 ( & V_2 -> V_5 ) ;
if ( V_4 -> V_13 )
V_4 -> V_13 ( V_4 -> V_5 , 0 ) ;
F_3 ( V_4 -> V_14 , 0 , V_4 -> V_15 ) ;
F_4 ( V_4 -> V_14 ) ;
return 0 ;
}
static int F_25 ( struct V_20 * V_21 )
{
struct V_1 * V_2 = F_22 ( V_21 ) ;
F_17 ( V_2 ) ;
return 0 ;
}
static int T_2 F_26 ( void )
{
return F_27 ( & V_40 ) ;
}
static void T_3 F_28 ( void )
{
F_29 ( & V_40 ) ;
}
