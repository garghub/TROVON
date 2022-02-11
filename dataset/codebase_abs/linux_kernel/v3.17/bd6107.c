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
F_1 ( V_2 , V_16 , F_5 ( 2 ) |
F_5 ( 1 ) | F_5 ( 0 ) ) ;
F_1 ( V_2 , V_17 , V_8 ) ;
F_1 ( V_2 , V_18 , V_19 ) ;
} else {
F_6 ( V_2 -> V_20 -> V_21 , 0 ) ;
F_7 ( 24 ) ;
F_6 ( V_2 -> V_20 -> V_21 , 1 ) ;
}
return 0 ;
}
static int F_8 ( struct V_6 * V_7 ,
struct V_22 * V_23 )
{
struct V_1 * V_2 = F_4 ( V_7 ) ;
return V_2 -> V_20 -> V_24 == NULL || V_2 -> V_20 -> V_24 == V_23 -> V_25 ;
}
static int F_9 ( struct V_26 * V_5 ,
const struct V_27 * V_28 )
{
struct V_29 * V_20 = F_10 ( & V_5 -> V_25 ) ;
struct V_6 * V_7 ;
struct V_30 V_9 ;
struct V_1 * V_2 ;
int V_31 ;
if ( V_20 == NULL || ! V_20 -> V_21 ) {
F_11 ( & V_5 -> V_25 , L_1 ) ;
return - V_32 ;
}
if ( ! F_12 ( V_5 -> V_33 ,
V_34 ) ) {
F_13 ( & V_5 -> V_25 ,
L_2 ) ;
return - V_35 ;
}
V_2 = F_14 ( & V_5 -> V_25 , sizeof( * V_2 ) , V_36 ) ;
if ( ! V_2 )
return - V_37 ;
V_2 -> V_5 = V_5 ;
V_2 -> V_20 = V_20 ;
V_31 = F_15 ( & V_5 -> V_25 , V_20 -> V_21 ,
V_38 | V_39 , L_3 ) ;
if ( V_31 < 0 ) {
F_11 ( & V_5 -> V_25 , L_4 ) ;
return V_31 ;
}
memset ( & V_9 , 0 , sizeof( V_9 ) ) ;
V_9 . type = V_40 ;
V_9 . V_41 = 128 ;
V_9 . V_8 = F_16 (unsigned int, pdata->def_value, 0 ,
props.max_brightness) ;
V_7 = F_17 ( & V_5 -> V_25 ,
F_18 ( & V_5 -> V_25 ) ,
& V_2 -> V_5 -> V_25 , V_2 ,
& V_42 , & V_9 ) ;
if ( F_19 ( V_7 ) ) {
F_11 ( & V_5 -> V_25 , L_5 ) ;
return F_20 ( V_7 ) ;
}
F_21 ( V_7 ) ;
F_22 ( V_5 , V_7 ) ;
return 0 ;
}
static int F_23 ( struct V_26 * V_5 )
{
struct V_6 * V_7 = F_24 ( V_5 ) ;
V_7 -> V_9 . V_8 = 0 ;
F_21 ( V_7 ) ;
return 0 ;
}
