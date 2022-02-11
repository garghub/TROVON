static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_5 )
F_3 ( V_4 ) ;
if ( V_4 -> V_6 )
F_4 ( V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
const struct V_7 * V_8 ;
const struct V_9 * V_10 ;
struct V_9 V_11 ;
struct V_3 * V_4 ;
struct V_12 * V_13 ;
struct V_14 * V_14 ;
struct V_15 * V_16 ;
int V_17 ;
int V_18 ;
V_8 = F_6 ( V_19 , & V_2 -> V_2 ) ;
if ( V_8 && V_8 -> V_20 ) {
V_10 = V_8 -> V_20 ;
} else {
F_7 ( & V_11 , - 1 ) ;
V_10 = & V_11 ;
V_11 . V_21 = 0 ;
}
V_4 = F_8 ( & V_2 -> V_2 , sizeof( * V_4 ) , V_22 ) ;
if ( ! V_4 )
return - V_23 ;
V_4 -> V_2 = & V_2 -> V_2 ;
if ( ! V_2 -> V_2 . V_24 )
V_2 -> V_2 . V_24 = & V_2 -> V_2 . V_25 ;
V_17 = F_9 ( & V_2 -> V_2 , F_10 ( 32 ) ) ;
if ( V_17 )
return V_17 ;
V_18 = F_11 ( V_2 , 0 ) ;
if ( V_18 < 0 ) {
F_12 ( & V_2 -> V_2 , L_1 ) ;
return V_18 ;
}
F_13 ( V_4 -> V_2 , L_2 ,
V_18 ) ;
V_17 = F_14 ( V_4 -> V_2 , V_18 ,
V_26 , V_27 ,
F_15 ( V_4 -> V_2 ) , V_4 ) ;
if ( V_17 )
return V_17 ;
V_13 = F_16 ( V_2 , V_28 , 0 ) ;
V_4 -> V_29 = F_17 ( & V_2 -> V_2 , V_13 ) ;
if ( F_18 ( V_4 -> V_29 ) )
return F_19 ( V_4 -> V_29 ) ;
F_13 ( & V_2 -> V_2 , L_3 ,
( unsigned long ) V_13 -> V_30 , V_4 -> V_29 ) ;
V_4 -> V_31 = F_20 ( V_2 -> V_2 . V_32 ) ;
V_14 = F_21 ( & V_2 -> V_2 , L_4 ) ;
if ( F_18 ( V_14 ) ) {
V_4 -> V_14 = NULL ;
V_16 = F_22 ( & V_2 -> V_2 , V_33 ) ;
if ( F_18 ( V_16 ) )
V_4 -> V_16 = NULL ;
else
V_4 -> V_16 = V_16 ;
} else {
V_4 -> V_14 = V_14 ;
F_23 ( V_4 -> V_14 ) ;
F_24 ( V_4 -> V_14 ) ;
}
F_25 ( & V_4 -> V_34 ) ;
F_26 ( & V_4 -> V_35 ) ;
if ( V_4 -> V_31 != V_36 ) {
V_17 = F_27 ( V_4 , V_18 ) ;
if ( V_17 )
return V_17 ;
V_4 -> V_6 = 1 ;
}
if ( V_4 -> V_31 != V_37 ) {
V_17 = F_28 ( V_4 , V_18 , V_10 ) ;
if ( V_17 ) {
if ( V_4 -> V_6 )
F_4 ( V_4 ) ;
return V_17 ;
}
V_4 -> V_5 = 1 ;
}
F_29 ( V_2 , V_4 ) ;
return V_17 ;
}
static int T_1 F_30 ( struct V_38 * V_2 )
{
struct V_3 * V_39 = F_31 ( V_2 ) ;
int V_40 = 0 ;
if ( F_32 ( V_39 ) ) {
V_40 = F_33 ( V_39 ) ;
} else {
if ( V_39 -> V_41 == V_42 )
return 0 ;
F_34 ( V_39 -> V_14 ) ;
F_35 ( V_39 -> V_14 ) ;
}
return V_40 ;
}
static int T_1 F_36 ( struct V_38 * V_2 )
{
struct V_3 * V_39 = F_31 ( V_2 ) ;
int V_40 = 0 ;
if ( F_32 ( V_39 ) ) {
V_40 = F_37 ( V_39 ) ;
} else {
F_23 ( V_39 -> V_14 ) ;
F_24 ( V_39 -> V_14 ) ;
}
return V_40 ;
}
