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
static int F_7 ( struct V_4 * V_6 , int V_19 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
return F_8 ( V_9 -> V_20 -> V_21 , & V_9 -> V_20 -> V_22 -> V_23 , V_19 ) ;
}
static int F_9 ( struct V_4 * V_6 , unsigned int V_24 ,
enum V_25 * V_16 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
if ( V_24 )
return - V_26 ;
* V_16 = V_9 -> V_14 . V_16 ;
return 0 ;
}
static int F_10 ( struct V_4 * V_6 ,
struct V_27 * V_28 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
V_28 -> V_29 . V_30 = 0 ;
V_28 -> V_29 . V_31 = 0 ;
V_28 -> V_29 . V_13 = V_9 -> V_14 . V_13 ;
V_28 -> V_29 . V_15 = V_9 -> V_14 . V_15 ;
V_28 -> type = V_32 ;
return 0 ;
}
static int F_11 ( struct V_4 * V_6 ,
struct V_33 * V_28 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
V_28 -> V_34 . V_30 = 0 ;
V_28 -> V_34 . V_31 = 0 ;
V_28 -> V_34 . V_13 = V_9 -> V_14 . V_13 ;
V_28 -> V_34 . V_15 = V_9 -> V_14 . V_15 ;
V_28 -> V_35 = V_28 -> V_34 ;
V_28 -> type = V_32 ;
V_28 -> V_36 . V_37 = 1 ;
V_28 -> V_36 . V_38 = 1 ;
return 0 ;
}
static int F_12 ( struct V_4 * V_6 ,
struct V_39 * V_40 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
V_40 -> V_41 = V_9 -> V_42 ;
V_40 -> type = V_9 -> V_43 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_44 * V_45 ;
struct V_1 * V_46 ;
struct V_8 * V_9 = V_3 -> V_47 . V_48 ;
struct V_49 * V_20 ;
int V_50 ;
if ( ! V_9 )
return - V_26 ;
if ( ! V_9 -> V_20 ) {
F_14 ( & V_3 -> V_47 ,
L_1 ) ;
return - V_26 ;
}
V_46 = F_15 ( & V_3 -> V_47 , sizeof( * V_46 ) , V_51 ) ;
if ( ! V_46 )
return - V_52 ;
V_20 = V_9 -> V_20 ;
F_16 ( V_3 , & V_46 -> V_5 ) ;
V_20 -> V_21 = & V_3 -> V_47 ;
V_45 = F_17 ( V_20 -> V_53 ) ;
F_18 ( & V_46 -> V_5 , & V_54 ) ;
F_19 ( & V_46 -> V_5 , V_9 ) ;
strncpy ( V_46 -> V_5 . V_55 , F_20 ( & V_3 -> V_47 ) , V_56 ) ;
V_50 = F_21 ( & V_45 -> V_57 , & V_46 -> V_5 ) ;
if ( V_50 )
goto V_58;
return V_50 ;
V_58:
F_16 ( V_3 , NULL ) ;
return V_50 ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_1 * V_46 = F_1 ( V_3 ) ;
struct V_8 * V_9 = F_5 ( & V_46 -> V_5 ) ;
V_9 -> V_20 -> V_21 = NULL ;
F_23 ( & V_46 -> V_5 ) ;
F_16 ( V_3 , NULL ) ;
return 0 ;
}
