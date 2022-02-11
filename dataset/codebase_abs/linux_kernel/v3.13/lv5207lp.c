static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_2 ( V_2 -> V_5 , V_3 , V_4 ) ;
}
static int F_3 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
int V_8 = V_7 -> V_9 . V_8 ;
if ( V_7 -> V_9 . V_10 != V_11 ||
V_7 -> V_9 . V_12 != V_11 ||
V_7 -> V_9 . V_13 & ( V_14 | V_15 ) )
V_8 = 0 ;
if ( V_8 ) {
F_1 ( V_2 , V_16 ,
V_17 | V_18 | V_19 ) ;
F_1 ( V_2 , V_20 ,
V_21 | V_22 |
( V_8 - 1 ) ) ;
} else {
F_1 ( V_2 , V_16 , 0 ) ;
F_1 ( V_2 , V_20 , 0 ) ;
}
return 0 ;
}
static int F_5 ( struct V_6 * V_7 )
{
return V_7 -> V_9 . V_8 ;
}
static int F_6 ( struct V_6 * V_7 ,
struct V_23 * V_24 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
return V_2 -> V_25 -> V_26 == NULL || V_2 -> V_25 -> V_26 == V_24 -> V_27 ;
}
static int F_7 ( struct V_28 * V_5 ,
const struct V_29 * V_30 )
{
struct V_31 * V_25 = F_8 ( & V_5 -> V_27 ) ;
struct V_6 * V_7 ;
struct V_32 V_9 ;
struct V_1 * V_2 ;
if ( V_25 == NULL ) {
F_9 ( & V_5 -> V_27 , L_1 ) ;
return - V_33 ;
}
if ( ! F_10 ( V_5 -> V_34 ,
V_35 ) ) {
F_11 ( & V_5 -> V_27 ,
L_2 ) ;
return - V_36 ;
}
V_2 = F_12 ( & V_5 -> V_27 , sizeof( * V_2 ) , V_37 ) ;
if ( ! V_2 )
return - V_38 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_25 = V_25 ;
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . type = V_39 ;
V_9 . V_40 = F_13 (unsigned int, pdata->max_value,
LV5207LP_MAX_BRIGHTNESS) ;
V_9 . V_8 = F_14 (unsigned int, pdata->def_value, 0 ,
props.max_brightness) ;
V_7 = F_15 ( & V_5 -> V_27 ,
F_16 ( & V_5 -> V_27 ) , & V_2 -> V_5 -> V_27 ,
V_2 , & V_41 , & V_9 ) ;
if ( F_17 ( V_7 ) ) {
F_9 ( & V_5 -> V_27 , L_3 ) ;
return F_18 ( V_7 ) ;
}
F_19 ( V_7 ) ;
F_20 ( V_5 , V_7 ) ;
return 0 ;
}
static int F_21 ( struct V_28 * V_5 )
{
struct V_6 * V_7 = F_22 ( V_5 ) ;
V_7 -> V_9 . V_8 = 0 ;
F_19 ( V_7 ) ;
return 0 ;
}
