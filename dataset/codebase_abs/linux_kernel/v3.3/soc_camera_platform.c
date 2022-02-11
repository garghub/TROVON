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
struct V_11 * V_12 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
V_12 -> V_13 = V_9 -> V_14 . V_13 ;
V_12 -> V_15 = V_9 -> V_14 . V_15 ;
V_12 -> V_16 = V_9 -> V_14 . V_16 ;
V_12 -> V_17 = V_9 -> V_14 . V_17 ;
V_12 -> V_18 = V_9 -> V_14 . V_18 ;
return 0 ;
}
static int F_7 ( struct V_4 * V_6 , unsigned int V_19 ,
enum V_20 * V_16 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
if ( V_19 )
return - V_21 ;
* V_16 = V_9 -> V_14 . V_16 ;
return 0 ;
}
static int F_8 ( struct V_4 * V_6 ,
struct V_22 * V_23 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
V_23 -> V_24 . V_25 = 0 ;
V_23 -> V_24 . V_26 = 0 ;
V_23 -> V_24 . V_13 = V_9 -> V_14 . V_13 ;
V_23 -> V_24 . V_15 = V_9 -> V_14 . V_15 ;
V_23 -> type = V_27 ;
return 0 ;
}
static int F_9 ( struct V_4 * V_6 ,
struct V_28 * V_23 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
V_23 -> V_29 . V_25 = 0 ;
V_23 -> V_29 . V_26 = 0 ;
V_23 -> V_29 . V_13 = V_9 -> V_14 . V_13 ;
V_23 -> V_29 . V_15 = V_9 -> V_14 . V_15 ;
V_23 -> V_30 = V_23 -> V_29 ;
V_23 -> type = V_27 ;
V_23 -> V_31 . V_32 = 1 ;
V_23 -> V_31 . V_33 = 1 ;
return 0 ;
}
static int F_10 ( struct V_4 * V_6 ,
struct V_34 * V_35 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
V_35 -> V_36 = V_9 -> V_37 ;
V_35 -> type = V_9 -> V_38 ;
return 0 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_39 * V_40 ;
struct V_1 * V_41 ;
struct V_8 * V_9 = V_3 -> V_42 . V_43 ;
struct V_44 * V_45 ;
int V_46 ;
if ( ! V_9 )
return - V_21 ;
if ( ! V_9 -> V_45 ) {
F_12 ( & V_3 -> V_42 ,
L_1 ) ;
return - V_21 ;
}
V_41 = F_13 ( sizeof( * V_41 ) , V_47 ) ;
if ( ! V_41 )
return - V_48 ;
V_45 = V_9 -> V_45 ;
F_14 ( V_3 , & V_41 -> V_5 ) ;
V_45 -> V_49 = & V_3 -> V_42 ;
V_40 = F_15 ( V_45 -> V_50 ) ;
F_16 ( & V_41 -> V_5 , & V_51 ) ;
F_17 ( & V_41 -> V_5 , V_9 ) ;
strncpy ( V_41 -> V_5 . V_52 , F_18 ( & V_3 -> V_42 ) , V_53 ) ;
V_46 = F_19 ( & V_40 -> V_54 , & V_41 -> V_5 ) ;
if ( V_46 )
goto V_55;
return V_46 ;
V_55:
F_14 ( V_3 , NULL ) ;
F_20 ( V_41 ) ;
return V_46 ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_41 = F_1 ( V_3 ) ;
struct V_8 * V_9 = F_5 ( & V_41 -> V_5 ) ;
V_9 -> V_45 -> V_49 = NULL ;
F_22 ( & V_41 -> V_5 ) ;
F_14 ( V_3 , NULL ) ;
F_20 ( V_41 ) ;
return 0 ;
}
