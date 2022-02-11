static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_6 -> V_9 ;
struct V_10 * V_11 = V_6 -> V_11 ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
int V_14 , V_15 ;
int V_16 ;
V_14 = F_3 ( V_4 ) ;
V_15 = 128 * V_14 ;
V_16 = F_4 ( & V_13 -> V_17 , V_14 , V_15 ) ;
if ( V_16 < 0 ) {
F_5 ( V_11 -> V_18 , L_1 ) ;
return V_16 ;
}
V_16 = F_6 ( V_9 , 0 , V_15 ,
V_19 ) ;
if ( V_16 < 0 ) {
F_5 ( V_11 -> V_18 , L_2 ) ;
return V_16 ;
}
return 0 ;
}
static int F_7 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_18 . V_24 ;
struct V_10 * V_11 = & V_25 ;
struct V_12 * V_13 ;
int V_26 ;
V_13 = F_8 ( & V_21 -> V_18 , sizeof( struct V_12 ) ,
V_27 ) ;
if ( ! V_13 )
return - V_28 ;
V_11 -> V_18 = & V_21 -> V_18 ;
F_9 ( V_11 , V_13 ) ;
V_29 . V_30 = F_10 ( V_23 ,
L_3 , 0 ) ;
if ( ! V_29 . V_30 ) {
F_5 ( & V_21 -> V_18 ,
L_4 ) ;
V_26 = - V_31 ;
goto V_16;
}
V_29 . V_32 = F_10 ( V_23 ,
L_5 , 0 ) ;
if ( ! V_29 . V_32 ) {
F_5 ( & V_21 -> V_18 ,
L_6 ) ;
V_26 = - V_31 ;
goto V_16;
}
V_29 . V_33 =
V_29 . V_32 ;
V_26 = F_11 ( & V_13 -> V_17 , & V_21 -> V_18 ) ;
if ( V_26 )
goto V_16;
V_26 = F_12 ( V_11 ) ;
if ( V_26 ) {
F_5 ( & V_21 -> V_18 , L_7 ,
V_26 ) ;
goto V_34;
}
return 0 ;
V_34:
F_13 ( & V_13 -> V_17 ) ;
V_16:
return V_26 ;
}
static int F_14 ( struct V_20 * V_21 )
{
struct V_10 * V_11 = F_15 ( V_21 ) ;
struct V_12 * V_13 = F_2 ( V_11 ) ;
F_16 ( V_11 ) ;
F_13 ( & V_13 -> V_17 ) ;
return 0 ;
}
