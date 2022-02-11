static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
F_4 ( V_6 ) ;
V_7 = F_5 ( V_4 ) ;
if ( V_7 ) {
F_6 ( & V_4 -> V_2 , L_1 ) ;
return V_7 ;
}
V_7 = F_7 ( V_4 , V_8 ) ;
if ( V_7 ) {
F_6 ( & V_4 -> V_2 , L_2 ) ;
return V_7 ;
}
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 , struct V_3 , V_2 ) ;
struct V_5 * V_6 = F_3 ( V_4 ) ;
int V_7 ;
T_1 V_9 ;
V_9 = F_9 ( V_6 ) ;
if ( V_9 )
return 0 ;
V_7 = F_7 ( V_4 , V_10 ) ;
if ( V_7 ) {
F_6 ( & V_4 -> V_2 , L_3 ) ;
return V_7 ;
}
F_10 ( V_4 ) ;
F_11 ( V_6 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
int V_7 = F_13 ( V_2 , 500 ) ;
F_14 ( V_2 , L_4 ) ;
if ( V_7 != 0 )
return 0 ;
return - V_11 ;
}
static T_1 F_15 ( struct V_5 * V_2 )
{
return V_2 -> V_12 -> V_13 ;
}
static int F_16 ( struct V_3 * V_4 ,
const struct V_14 * V_15 )
{
struct V_5 * V_2 ;
struct V_16 * V_17 ;
int V_18 ;
struct V_19 * V_12 ;
if ( V_15 -> V_20 >= F_17 ( V_21 ) ) {
F_6 ( & V_4 -> V_2 , L_5 , V_22 ,
V_15 -> V_20 ) ;
return - V_23 ;
}
V_12 = & V_21 [ V_15 -> V_20 ] ;
V_18 = F_18 ( V_4 ) ;
if ( V_18 ) {
F_6 ( & V_4 -> V_2 , L_6 ,
V_18 ) ;
return V_18 ;
}
V_18 = F_19 ( V_4 , 1 << 0 , F_20 ( V_4 ) ) ;
if ( V_18 ) {
F_6 ( & V_4 -> V_2 , L_7 ) ;
return V_18 ;
}
V_2 = F_21 ( & V_4 -> V_2 , sizeof( struct V_5 ) , V_24 ) ;
if ( ! V_2 )
return - V_25 ;
F_22 ( & V_2 -> V_26 ) ;
F_23 ( & V_2 -> V_27 ) ;
V_2 -> V_28 = NULL ;
V_2 -> V_12 = V_12 ;
V_2 -> V_29 = F_15 ;
V_2 -> V_30 = F_24 ( V_4 ) [ 0 ] ;
V_2 -> V_2 = & V_4 -> V_2 ;
V_2 -> V_31 =
V_32 |
V_33 |
V_34 |
V_35 |
V_36 ;
V_2 -> V_37 = V_12 -> V_38 ;
F_25 ( V_4 , V_2 ) ;
V_2 -> V_39 = V_12 -> V_39 ;
V_2 -> V_40 = V_12 -> V_40 ;
V_18 = F_11 ( V_2 ) ;
if ( V_18 )
return V_18 ;
V_17 = & V_2 -> V_41 ;
F_26 ( V_17 , V_2 ) ;
V_17 -> V_42 = V_43 ;
V_17 -> V_44 = 0 ;
V_17 -> V_45 = & V_46 ;
V_17 -> V_2 . V_47 = & V_4 -> V_2 ;
V_17 -> V_48 = V_12 -> V_49 ;
snprintf ( V_17 -> V_50 , sizeof( V_17 -> V_50 ) , L_8 ,
V_17 -> V_48 ) ;
V_18 = F_27 ( & V_4 -> V_2 , V_4 -> V_51 , V_52 , V_53 ,
V_17 -> V_50 , V_2 ) ;
if ( V_18 ) {
F_6 ( & V_4 -> V_2 , L_9 , V_2 -> V_51 ) ;
return V_18 ;
}
F_28 ( V_2 ) ;
F_29 ( V_2 ) ;
V_18 = F_30 ( V_17 ) ;
if ( V_18 ) {
F_6 ( & V_4 -> V_2 , L_10 ) ;
return V_18 ;
}
F_31 ( & V_4 -> V_2 , 1000 ) ;
F_32 ( & V_4 -> V_2 ) ;
F_33 ( & V_4 -> V_2 ) ;
return 0 ;
}
static void F_34 ( struct V_3 * V_4 )
{
struct V_5 * V_2 = F_3 ( V_4 ) ;
F_4 ( V_2 ) ;
F_35 ( & V_4 -> V_2 ) ;
F_36 ( & V_4 -> V_2 ) ;
F_37 ( & V_2 -> V_41 ) ;
}
