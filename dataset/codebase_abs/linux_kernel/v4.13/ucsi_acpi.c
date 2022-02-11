static int F_1 ( struct V_1 * V_2 , int V_3 )
{
union V_4 * V_5 ;
V_5 = F_2 ( F_3 ( V_2 -> V_6 ) , & V_2 -> V_7 , 1 , V_3 ,
NULL ) ;
if ( ! V_5 ) {
F_4 ( V_2 -> V_6 , L_1 ,
V_8 , V_3 ) ;
return - V_9 ;
}
F_5 ( V_5 ) ;
return 0 ;
}
static int F_6 ( struct V_10 * V_11 , struct V_12 * V_13 )
{
struct V_1 * V_2 = F_7 ( V_11 , struct V_1 , V_11 ) ;
V_11 -> V_14 -> V_13 . V_15 = V_13 -> V_15 ;
return F_1 ( V_2 , V_16 ) ;
}
static int F_8 ( struct V_10 * V_11 )
{
struct V_1 * V_2 = F_7 ( V_11 , struct V_1 , V_11 ) ;
return F_1 ( V_2 , V_17 ) ;
}
static void F_9 ( T_1 V_18 , T_2 V_19 , void * V_14 )
{
struct V_1 * V_2 = V_14 ;
F_10 ( V_2 -> V_20 ) ;
}
static int F_11 ( struct V_21 * V_22 )
{
struct V_1 * V_2 ;
struct V_23 * V_24 ;
T_3 V_25 ;
int V_26 ;
V_2 = F_12 ( & V_22 -> V_6 , sizeof( * V_2 ) , V_27 ) ;
if ( ! V_2 )
return - V_28 ;
V_24 = F_13 ( V_22 , V_29 , 0 ) ;
if ( ! V_24 ) {
F_4 ( & V_22 -> V_6 , L_2 ) ;
return - V_30 ;
}
V_2 -> V_11 . V_14 = F_14 ( & V_22 -> V_6 , V_24 -> V_31 , F_15 ( V_24 ) ) ;
if ( ! V_2 -> V_11 . V_14 )
return - V_28 ;
if ( ! V_2 -> V_11 . V_14 -> V_32 )
return - V_30 ;
V_26 = F_16 ( V_33 , & V_2 -> V_7 ) ;
if ( V_26 )
return V_26 ;
V_2 -> V_11 . V_34 = F_6 ;
V_2 -> V_11 . V_35 = F_8 ;
V_2 -> V_6 = & V_22 -> V_6 ;
V_25 = F_17 ( F_3 ( & V_22 -> V_6 ) ,
V_36 ,
F_9 , V_2 ) ;
if ( F_18 ( V_25 ) ) {
F_4 ( & V_22 -> V_6 , L_3 ) ;
return - V_30 ;
}
V_2 -> V_20 = F_19 ( & V_22 -> V_6 , & V_2 -> V_11 ) ;
if ( F_20 ( V_2 -> V_20 ) ) {
F_21 ( F_3 ( & V_22 -> V_6 ) ,
V_36 ,
F_9 ) ;
return F_22 ( V_2 -> V_20 ) ;
}
F_23 ( V_22 , V_2 ) ;
return 0 ;
}
static int F_24 ( struct V_21 * V_22 )
{
struct V_1 * V_2 = F_25 ( V_22 ) ;
F_26 ( V_2 -> V_20 ) ;
F_21 ( F_3 ( & V_22 -> V_6 ) , V_36 ,
F_9 ) ;
return 0 ;
}
