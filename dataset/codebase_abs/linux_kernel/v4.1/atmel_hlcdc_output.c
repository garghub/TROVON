static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 ,
V_3 ) ;
}
static inline struct V_1 *
F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static inline struct V_6 *
F_4 ( struct V_1 * V_7 )
{
return F_2 ( V_7 , struct V_6 , V_8 ) ;
}
static void F_5 ( struct V_4 * V_5 )
{
struct V_1 * V_9 =
F_3 ( V_5 ) ;
struct V_6 * V_10 = F_4 ( V_9 ) ;
F_6 ( V_10 -> V_10 ) ;
}
static void F_7 ( struct V_4 * V_5 )
{
struct V_1 * V_9 =
F_3 ( V_5 ) ;
struct V_6 * V_10 = F_4 ( V_9 ) ;
F_8 ( V_10 -> V_10 ) ;
}
static bool
F_9 ( struct V_4 * V_5 ,
const struct V_11 * V_12 ,
struct V_11 * V_13 )
{
return true ;
}
static void
F_10 ( struct V_4 * V_5 ,
struct V_11 * V_12 ,
struct V_11 * V_13 )
{
struct V_1 * V_9 =
F_3 ( V_5 ) ;
struct V_14 * V_15 = & V_9 -> V_3 . V_16 ;
unsigned int V_17 ;
V_17 = 0 ;
if ( V_15 -> V_18 ) {
switch ( V_15 -> V_19 [ 0 ] ) {
case V_20 :
V_17 |= V_21 << 8 ;
break;
case V_22 :
V_17 |= V_23 << 8 ;
break;
default:
break;
}
}
F_11 ( V_9 -> V_24 -> V_25 -> V_26 , F_12 ( 5 ) ,
V_27 ,
V_17 ) ;
}
static void F_13 ( struct V_4 * V_5 )
{
F_14 ( V_5 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_1 * V_9 =
F_1 ( V_3 ) ;
struct V_6 * V_10 = F_4 ( V_9 ) ;
return V_10 -> V_10 -> V_28 -> V_29 ( V_10 -> V_10 ) ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
struct V_1 * V_9 =
F_1 ( V_3 ) ;
return F_17 ( V_9 -> V_24 , V_12 ) ;
}
static struct V_4 *
F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_9 =
F_1 ( V_3 ) ;
return & V_9 -> V_5 ;
}
static enum V_30
F_19 ( struct V_2 * V_3 , bool V_31 )
{
return V_32 ;
}
static void
F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_9 =
F_1 ( V_3 ) ;
struct V_6 * V_10 = F_4 ( V_9 ) ;
F_21 ( V_10 -> V_10 ) ;
F_22 ( V_3 ) ;
}
static int F_23 ( struct V_33 * V_34 ,
struct V_35 * V_36 )
{
struct V_37 * V_24 = V_34 -> V_38 ;
struct V_39 * V_40 ;
struct V_41 * V_42 = NULL ;
struct V_6 * V_10 ;
int V_43 ;
V_40 = F_24 ( V_36 -> V_44 ) ;
if ( ! V_40 )
return - V_45 ;
V_42 = F_25 ( V_40 ) ;
F_26 ( V_40 ) ;
if ( ! V_42 )
return - V_46 ;
V_10 = F_27 ( V_34 -> V_34 , sizeof( * V_10 ) , V_47 ) ;
if ( ! V_10 )
return - V_45 ;
V_10 -> V_8 . V_48 = V_49 ;
V_10 -> V_8 . V_24 = V_24 ;
F_28 ( & V_10 -> V_8 . V_5 ,
& V_50 ) ;
V_43 = F_29 ( V_34 , & V_10 -> V_8 . V_5 ,
& V_51 ,
V_52 ) ;
if ( V_43 )
return V_43 ;
V_10 -> V_8 . V_3 . V_48 = V_49 ;
V_10 -> V_8 . V_3 . V_53 = V_54 ;
F_30 ( & V_10 -> V_8 . V_3 ,
& V_55 ) ;
V_43 = F_31 ( V_34 , & V_10 -> V_8 . V_3 ,
& V_56 ,
V_57 ) ;
if ( V_43 )
goto V_58;
F_32 ( & V_10 -> V_8 . V_3 ,
& V_10 -> V_8 . V_5 ) ;
V_10 -> V_8 . V_5 . V_59 = 0x1 ;
F_33 ( V_42 , & V_10 -> V_8 . V_3 ) ;
V_10 -> V_10 = V_42 ;
return 0 ;
V_58:
F_14 ( & V_10 -> V_8 . V_5 ) ;
return V_43 ;
}
int F_34 ( struct V_33 * V_34 )
{
struct V_39 * V_60 , * V_40 ;
struct V_35 V_36 ;
int V_43 ;
V_60 = F_35 ( V_34 -> V_34 -> V_61 , L_1 ) ;
if ( ! V_60 )
return - V_45 ;
V_40 = F_35 ( V_60 , L_2 ) ;
F_26 ( V_60 ) ;
if ( ! V_40 )
return - V_45 ;
V_43 = F_36 ( V_40 , & V_36 ) ;
F_26 ( V_60 ) ;
if ( V_43 )
return V_43 ;
return F_23 ( V_34 , & V_36 ) ;
}
