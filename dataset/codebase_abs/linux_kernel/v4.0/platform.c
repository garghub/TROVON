static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 ) ;
F_4 ( V_4 ) ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
const struct V_5 * V_6 ;
const struct V_7 * V_8 ;
struct V_7 V_9 ;
struct V_3 * V_4 ;
struct V_10 * V_11 ;
struct V_12 * V_12 ;
struct V_13 * V_14 ;
int V_15 ;
int V_16 ;
V_6 = F_6 ( V_17 , & V_2 -> V_2 ) ;
if ( V_6 && V_6 -> V_18 ) {
V_8 = V_6 -> V_18 ;
} else {
F_7 ( & V_9 , - 1 ) ;
V_8 = & V_9 ;
V_9 . V_19 = 0 ;
}
V_4 = F_8 ( & V_2 -> V_2 , sizeof( * V_4 ) , V_20 ) ;
if ( ! V_4 )
return - V_21 ;
V_4 -> V_2 = & V_2 -> V_2 ;
if ( ! V_2 -> V_2 . V_22 )
V_2 -> V_2 . V_22 = & V_2 -> V_2 . V_23 ;
V_15 = F_9 ( & V_2 -> V_2 , F_10 ( 32 ) ) ;
if ( V_15 )
return V_15 ;
V_16 = F_11 ( V_2 , 0 ) ;
if ( V_16 < 0 ) {
F_12 ( & V_2 -> V_2 , L_1 ) ;
return V_16 ;
}
F_13 ( V_4 -> V_2 , L_2 ,
V_16 ) ;
V_15 = F_14 ( V_4 -> V_2 , V_16 ,
V_24 , V_25 ,
F_15 ( V_4 -> V_2 ) , V_4 ) ;
if ( V_15 )
return V_15 ;
V_11 = F_16 ( V_2 , V_26 , 0 ) ;
V_4 -> V_27 = F_17 ( & V_2 -> V_2 , V_11 ) ;
if ( F_18 ( V_4 -> V_27 ) )
return F_19 ( V_4 -> V_27 ) ;
F_13 ( & V_2 -> V_2 , L_3 ,
( unsigned long ) V_11 -> V_28 , V_4 -> V_27 ) ;
V_4 -> V_29 = F_20 ( V_2 -> V_2 . V_30 ) ;
V_12 = F_21 ( & V_2 -> V_2 , L_4 ) ;
if ( F_18 ( V_12 ) ) {
V_4 -> V_12 = NULL ;
V_14 = F_22 ( & V_2 -> V_2 , V_31 ) ;
if ( F_18 ( V_14 ) )
V_4 -> V_14 = NULL ;
else
V_4 -> V_14 = V_14 ;
} else {
V_4 -> V_12 = V_12 ;
F_23 ( V_4 -> V_12 ) ;
F_24 ( V_4 -> V_12 ) ;
}
F_25 ( & V_4 -> V_32 ) ;
F_26 ( & V_4 -> V_33 ) ;
V_15 = F_27 ( V_4 , V_16 ) ;
if ( V_15 )
return V_15 ;
V_15 = F_28 ( V_4 , V_16 , V_8 ) ;
if ( V_15 )
return V_15 ;
F_29 ( V_2 , V_4 ) ;
return V_15 ;
}
static int T_1 F_30 ( struct V_34 * V_2 )
{
struct V_3 * V_35 = F_31 ( V_2 ) ;
int V_36 = 0 ;
if ( F_32 ( V_35 ) ) {
V_36 = F_33 ( V_35 ) ;
} else {
if ( V_35 -> V_37 == V_38 )
return 0 ;
F_34 ( V_35 -> V_12 ) ;
F_35 ( V_35 -> V_12 ) ;
}
return V_36 ;
}
static int T_1 F_36 ( struct V_34 * V_2 )
{
struct V_3 * V_35 = F_31 ( V_2 ) ;
int V_36 = 0 ;
if ( F_32 ( V_35 ) ) {
V_36 = F_37 ( V_35 ) ;
} else {
F_23 ( V_35 -> V_12 ) ;
F_24 ( V_35 -> V_12 ) ;
}
return V_36 ;
}
