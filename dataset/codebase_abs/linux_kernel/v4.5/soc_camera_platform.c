static struct V_1 * F_1 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_2 ( V_3 ) ;
return F_3 ( V_5 , struct V_1 , V_5 ) ;
}
static int F_4 ( struct V_4 * V_6 , int V_7 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
return V_9 -> V_10 ( V_9 , V_7 ) ;
}
static int F_6 ( struct V_4 * V_6 ,
struct V_11 * V_12 ,
struct V_13 * V_14 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
struct V_15 * V_16 = & V_14 -> V_14 ;
V_16 -> V_17 = V_9 -> V_14 . V_17 ;
V_16 -> V_18 = V_9 -> V_14 . V_18 ;
V_16 -> V_19 = V_9 -> V_14 . V_19 ;
V_16 -> V_20 = V_9 -> V_14 . V_20 ;
V_16 -> V_21 = V_9 -> V_14 . V_21 ;
return 0 ;
}
static int F_7 ( struct V_4 * V_6 , int V_22 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
return F_8 ( V_9 -> V_23 -> V_24 , & V_9 -> V_23 -> V_25 -> V_26 , NULL , V_22 ) ;
}
static int F_9 ( struct V_4 * V_6 ,
struct V_11 * V_12 ,
struct V_27 * V_19 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
if ( V_19 -> V_28 || V_19 -> V_29 )
return - V_30 ;
V_19 -> V_19 = V_9 -> V_14 . V_19 ;
return 0 ;
}
static int F_10 ( struct V_4 * V_6 ,
struct V_31 * V_32 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
V_32 -> V_33 . V_34 = 0 ;
V_32 -> V_33 . V_35 = 0 ;
V_32 -> V_33 . V_17 = V_9 -> V_14 . V_17 ;
V_32 -> V_33 . V_18 = V_9 -> V_14 . V_18 ;
V_32 -> type = V_36 ;
return 0 ;
}
static int F_11 ( struct V_4 * V_6 ,
struct V_37 * V_32 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
V_32 -> V_38 . V_34 = 0 ;
V_32 -> V_38 . V_35 = 0 ;
V_32 -> V_38 . V_17 = V_9 -> V_14 . V_17 ;
V_32 -> V_38 . V_18 = V_9 -> V_14 . V_18 ;
V_32 -> V_39 = V_32 -> V_38 ;
V_32 -> type = V_36 ;
V_32 -> V_40 . V_41 = 1 ;
V_32 -> V_40 . V_42 = 1 ;
return 0 ;
}
static int F_12 ( struct V_4 * V_6 ,
struct V_43 * V_12 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
V_12 -> V_44 = V_9 -> V_45 ;
V_12 -> type = V_9 -> V_46 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_47 * V_48 ;
struct V_1 * V_49 ;
struct V_8 * V_9 = V_3 -> V_50 . V_51 ;
struct V_52 * V_23 ;
if ( ! V_9 )
return - V_30 ;
if ( ! V_9 -> V_23 ) {
F_14 ( & V_3 -> V_50 ,
L_1 ) ;
return - V_30 ;
}
V_49 = F_15 ( & V_3 -> V_50 , sizeof( * V_49 ) , V_53 ) ;
if ( ! V_49 )
return - V_54 ;
V_23 = V_9 -> V_23 ;
F_16 ( V_3 , & V_49 -> V_5 ) ;
V_23 -> V_24 = & V_3 -> V_50 ;
V_48 = F_17 ( V_23 -> V_55 ) ;
F_18 ( & V_49 -> V_5 , & V_56 ) ;
F_19 ( & V_49 -> V_5 , V_9 ) ;
strncpy ( V_49 -> V_5 . V_57 , F_20 ( & V_3 -> V_50 ) , V_58 ) ;
return F_21 ( & V_48 -> V_59 , & V_49 -> V_5 ) ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_49 = F_1 ( V_3 ) ;
struct V_8 * V_9 = F_5 ( & V_49 -> V_5 ) ;
V_9 -> V_23 -> V_24 = NULL ;
F_23 ( & V_49 -> V_5 ) ;
return 0 ;
}
