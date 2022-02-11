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
return F_8 ( V_9 -> V_20 -> V_21 , V_9 -> V_20 -> V_22 , V_19 ) ;
}
static int F_9 ( struct V_4 * V_6 , unsigned int V_23 ,
enum V_24 * V_16 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
if ( V_23 )
return - V_25 ;
* V_16 = V_9 -> V_14 . V_16 ;
return 0 ;
}
static int F_10 ( struct V_4 * V_6 ,
struct V_26 * V_27 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
V_27 -> V_28 . V_29 = 0 ;
V_27 -> V_28 . V_30 = 0 ;
V_27 -> V_28 . V_13 = V_9 -> V_14 . V_13 ;
V_27 -> V_28 . V_15 = V_9 -> V_14 . V_15 ;
V_27 -> type = V_31 ;
return 0 ;
}
static int F_11 ( struct V_4 * V_6 ,
struct V_32 * V_27 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
V_27 -> V_33 . V_29 = 0 ;
V_27 -> V_33 . V_30 = 0 ;
V_27 -> V_33 . V_13 = V_9 -> V_14 . V_13 ;
V_27 -> V_33 . V_15 = V_9 -> V_14 . V_15 ;
V_27 -> V_34 = V_27 -> V_33 ;
V_27 -> type = V_31 ;
V_27 -> V_35 . V_36 = 1 ;
V_27 -> V_35 . V_37 = 1 ;
return 0 ;
}
static int F_12 ( struct V_4 * V_6 ,
struct V_38 * V_39 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
V_39 -> V_40 = V_9 -> V_41 ;
V_39 -> type = V_9 -> V_42 ;
return 0 ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_43 * V_44 ;
struct V_1 * V_45 ;
struct V_8 * V_9 = V_3 -> V_46 . V_47 ;
struct V_48 * V_20 ;
int V_49 ;
if ( ! V_9 )
return - V_25 ;
if ( ! V_9 -> V_20 ) {
F_14 ( & V_3 -> V_46 ,
L_1 ) ;
return - V_25 ;
}
V_45 = F_15 ( sizeof( * V_45 ) , V_50 ) ;
if ( ! V_45 )
return - V_51 ;
V_20 = V_9 -> V_20 ;
F_16 ( V_3 , & V_45 -> V_5 ) ;
V_20 -> V_21 = & V_3 -> V_46 ;
V_44 = F_17 ( V_20 -> V_52 ) ;
F_18 ( & V_45 -> V_5 , & V_53 ) ;
F_19 ( & V_45 -> V_5 , V_9 ) ;
strncpy ( V_45 -> V_5 . V_54 , F_20 ( & V_3 -> V_46 ) , V_55 ) ;
V_49 = F_21 ( & V_44 -> V_56 , & V_45 -> V_5 ) ;
if ( V_49 )
goto V_57;
return V_49 ;
V_57:
F_16 ( V_3 , NULL ) ;
F_22 ( V_45 ) ;
return V_49 ;
}
static int F_23 ( struct V_2 * V_3 )
{
struct V_1 * V_45 = F_1 ( V_3 ) ;
struct V_8 * V_9 = F_5 ( & V_45 -> V_5 ) ;
V_9 -> V_20 -> V_21 = NULL ;
F_24 ( & V_45 -> V_5 ) ;
F_16 ( V_3 , NULL ) ;
F_22 ( V_45 ) ;
return 0 ;
}
