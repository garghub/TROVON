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
struct V_11 * V_12 ,
struct V_31 * V_32 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
if ( V_32 -> V_33 != V_34 )
return - V_30 ;
switch ( V_32 -> V_35 ) {
case V_36 :
case V_37 :
case V_38 :
V_32 -> V_39 . V_40 = 0 ;
V_32 -> V_39 . V_41 = 0 ;
V_32 -> V_39 . V_17 = V_9 -> V_14 . V_17 ;
V_32 -> V_39 . V_18 = V_9 -> V_14 . V_18 ;
return 0 ;
default:
return - V_30 ;
}
}
static int F_11 ( struct V_4 * V_6 ,
struct V_42 * V_12 )
{
struct V_8 * V_9 = F_5 ( V_6 ) ;
V_12 -> V_43 = V_9 -> V_44 ;
V_12 -> type = V_9 -> V_45 ;
return 0 ;
}
static int F_12 ( struct V_2 * V_3 )
{
struct V_46 * V_47 ;
struct V_1 * V_48 ;
struct V_8 * V_9 = V_3 -> V_49 . V_50 ;
struct V_51 * V_23 ;
if ( ! V_9 )
return - V_30 ;
if ( ! V_9 -> V_23 ) {
F_13 ( & V_3 -> V_49 ,
L_1 ) ;
return - V_30 ;
}
V_48 = F_14 ( & V_3 -> V_49 , sizeof( * V_48 ) , V_52 ) ;
if ( ! V_48 )
return - V_53 ;
V_23 = V_9 -> V_23 ;
F_15 ( V_3 , & V_48 -> V_5 ) ;
V_23 -> V_24 = & V_3 -> V_49 ;
V_47 = F_16 ( V_23 -> V_54 ) ;
F_17 ( & V_48 -> V_5 , & V_55 ) ;
F_18 ( & V_48 -> V_5 , V_9 ) ;
strncpy ( V_48 -> V_5 . V_56 , F_19 ( & V_3 -> V_49 ) , V_57 ) ;
return F_20 ( & V_47 -> V_58 , & V_48 -> V_5 ) ;
}
static int F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_48 = F_1 ( V_3 ) ;
struct V_8 * V_9 = F_5 ( & V_48 -> V_5 ) ;
V_9 -> V_23 -> V_24 = NULL ;
F_22 ( & V_48 -> V_5 ) ;
return 0 ;
}
