static int F_1 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 , T_1 V_5 )
{
return F_2 ( V_2 -> V_6 , V_3 | V_5 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , 0 ) ;
}
static int F_4 ( struct V_1 * V_2 , T_1 V_3 , T_1 V_4 )
{
return F_1 ( V_2 , V_3 , V_4 , V_7 ) ;
}
static int F_5 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
F_4 ( V_2 , V_10 , V_11 ) ;
F_4 ( V_2 , V_10 , ~ V_12 ) ;
F_3 ( V_2 , V_10 , V_12 ) ;
F_4 ( V_2 , V_13 , ~ 0 ) ;
F_3 ( V_2 , V_13 , ( V_14 | V_15
| V_16 ) ) ;
F_4 ( V_2 , V_17 , ~ 0 ) ;
F_3 ( V_2 , V_10 , V_18 ) ;
F_3 ( V_2 , V_17 , ( V_19
| V_20 ) ) ;
F_4 ( V_2 , V_17 , ( V_21
| V_22 ) ) ;
F_4 ( V_2 , V_23 , ~ 0 ) ;
F_4 ( V_2 , V_24 , ~ 0 ) ;
F_4 ( V_2 , V_25 , ~ 0 ) ;
return 0 ;
}
static int F_7 ( struct V_8 * V_9 , int V_26 )
{
struct V_1 * V_2 = F_6 ( V_9 ) ;
if ( V_26 )
F_3 ( V_2 , V_17 , V_27 ) ;
else
F_4 ( V_2 , V_17 , V_27 ) ;
return 0 ;
}
static int F_8 ( struct V_28 * V_6 ,
const struct V_29 * V_30 )
{
struct V_1 * V_2 ;
struct V_8 * V_9 ;
V_2 = F_9 ( & V_6 -> V_31 , sizeof( * V_2 ) , V_32 ) ;
if ( ! V_2 )
return - V_33 ;
V_2 -> V_6 = V_6 ;
F_10 ( & V_2 -> V_34 ) ;
V_9 = & V_2 -> V_9 ;
V_9 -> V_31 = & V_6 -> V_31 ;
V_9 -> V_35 = V_36 ;
V_9 -> V_37 = F_5 ;
V_9 -> V_38 = F_7 ;
V_9 -> type = V_39 ;
F_11 ( V_6 , V_2 ) ;
F_12 ( V_9 ) ;
V_40 = V_6 ;
return 0 ;
}
static int F_13 ( struct V_28 * V_6 )
{
struct V_1 * V_2 = F_14 ( V_6 ) ;
F_15 ( & V_2 -> V_9 ) ;
V_40 = NULL ;
return 0 ;
}
static int F_16 ( struct V_41 * V_31 , void * V_42 )
{
struct V_43 * V_44 = (struct V_43 * ) V_42 ;
return ( V_31 -> V_45 == V_44 ) &&
( V_31 -> V_46 == & V_47 . V_46 ) ;
}
struct V_28 * F_17 ( struct V_43 * V_44 )
{
if ( V_44 ) {
struct V_41 * V_31 = F_18 ( & V_48 , NULL ,
V_44 , F_16 ) ;
if ( ! V_31 )
return NULL ;
return F_19 ( V_31 ) ;
} else {
return V_40 ;
}
}
