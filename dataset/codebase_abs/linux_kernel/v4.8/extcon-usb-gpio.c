static void F_1 ( struct V_1 * V_2 )
{
int V_3 ;
struct V_4 * V_5 = F_2 ( F_3 ( V_2 ) ,
struct V_4 ,
V_6 ) ;
V_3 = F_4 ( V_5 -> V_7 ) ;
if ( V_3 ) {
F_5 ( V_5 -> V_8 , V_9 , false ) ;
F_5 ( V_5 -> V_8 , V_10 , true ) ;
} else {
F_5 ( V_5 -> V_8 , V_10 , false ) ;
F_5 ( V_5 -> V_8 , V_9 , true ) ;
}
}
static T_1 F_6 ( int V_11 , void * V_12 )
{
struct V_4 * V_5 = V_12 ;
F_7 ( V_13 , & V_5 -> V_6 ,
V_5 -> V_14 ) ;
return V_15 ;
}
static int F_8 ( struct V_16 * V_17 )
{
struct V_18 * V_19 = & V_17 -> V_19 ;
struct V_20 * V_21 = V_19 -> V_22 ;
struct V_4 * V_5 ;
int V_23 ;
if ( ! V_21 && ! F_9 ( V_19 ) )
return - V_24 ;
V_5 = F_10 ( & V_17 -> V_19 , sizeof( * V_5 ) , V_25 ) ;
if ( ! V_5 )
return - V_26 ;
V_5 -> V_19 = V_19 ;
V_5 -> V_7 = F_11 ( & V_17 -> V_19 , L_1 , V_27 ) ;
if ( F_12 ( V_5 -> V_7 ) ) {
F_13 ( V_19 , L_2 ) ;
return F_14 ( V_5 -> V_7 ) ;
}
V_5 -> V_8 = F_15 ( V_19 , V_28 ) ;
if ( F_12 ( V_5 -> V_8 ) ) {
F_13 ( V_19 , L_3 ) ;
return - V_26 ;
}
V_23 = F_16 ( V_19 , V_5 -> V_8 ) ;
if ( V_23 < 0 ) {
F_13 ( V_19 , L_4 ) ;
return V_23 ;
}
V_23 = F_17 ( V_5 -> V_7 ,
V_29 * 1000 ) ;
if ( V_23 < 0 )
V_5 -> V_14 = F_18 ( V_29 ) ;
F_19 ( & V_5 -> V_6 , F_1 ) ;
V_5 -> V_30 = F_20 ( V_5 -> V_7 ) ;
if ( V_5 -> V_30 < 0 ) {
F_13 ( V_19 , L_5 ) ;
return V_5 -> V_30 ;
}
V_23 = F_21 ( V_19 , V_5 -> V_30 , NULL ,
F_6 ,
V_31 |
V_32 | V_33 ,
V_17 -> V_34 , V_5 ) ;
if ( V_23 < 0 ) {
F_13 ( V_19 , L_6 ) ;
return V_23 ;
}
F_22 ( V_17 , V_5 ) ;
F_23 ( V_19 , true ) ;
F_24 ( V_19 , V_5 -> V_30 ) ;
F_1 ( & V_5 -> V_6 . V_2 ) ;
return 0 ;
}
static int F_25 ( struct V_16 * V_17 )
{
struct V_4 * V_5 = F_26 ( V_17 ) ;
F_27 ( & V_5 -> V_6 ) ;
F_28 ( & V_17 -> V_19 ) ;
F_23 ( & V_17 -> V_19 , false ) ;
return 0 ;
}
static int F_29 ( struct V_18 * V_19 )
{
struct V_4 * V_5 = F_30 ( V_19 ) ;
int V_23 = 0 ;
F_31 ( V_5 -> V_30 ) ;
return V_23 ;
}
static int F_32 ( struct V_18 * V_19 )
{
struct V_4 * V_5 = F_30 ( V_19 ) ;
int V_23 = 0 ;
F_33 ( V_5 -> V_30 ) ;
if ( ! F_34 ( V_19 ) )
F_7 ( V_13 ,
& V_5 -> V_6 , 0 ) ;
return V_23 ;
}
