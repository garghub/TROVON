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
static void F_5 ( struct V_4 * V_5 ,
int V_9 )
{
struct V_1 * V_10 =
F_3 ( V_5 ) ;
struct V_6 * V_11 = F_4 ( V_10 ) ;
if ( V_9 != V_12 )
V_9 = V_13 ;
if ( V_9 == V_10 -> V_14 )
return;
if ( V_9 != V_12 )
F_6 ( V_11 -> V_11 ) ;
else
F_7 ( V_11 -> V_11 ) ;
V_10 -> V_14 = V_9 ;
}
static bool
F_8 ( struct V_4 * V_5 ,
const struct V_15 * V_9 ,
struct V_15 * V_16 )
{
return true ;
}
static void F_9 ( struct V_4 * V_5 )
{
F_5 ( V_5 , V_13 ) ;
}
static void F_10 ( struct V_4 * V_5 )
{
F_5 ( V_5 , V_12 ) ;
}
static void
F_11 ( struct V_4 * V_5 ,
struct V_15 * V_9 ,
struct V_15 * V_16 )
{
struct V_1 * V_10 =
F_3 ( V_5 ) ;
struct V_17 * V_18 = & V_10 -> V_3 . V_19 ;
unsigned int V_20 ;
V_20 = 0 ;
if ( V_18 -> V_21 ) {
switch ( V_18 -> V_22 [ 0 ] ) {
case V_23 :
V_20 |= V_24 << 8 ;
break;
case V_25 :
V_20 |= V_26 << 8 ;
break;
default:
break;
}
}
F_12 ( V_10 -> V_27 -> V_28 -> V_29 , F_13 ( 5 ) ,
V_30 ,
V_20 ) ;
}
static void F_14 ( struct V_4 * V_5 )
{
F_15 ( V_5 ) ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
}
static int F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_10 =
F_1 ( V_3 ) ;
struct V_6 * V_11 = F_4 ( V_10 ) ;
return V_11 -> V_11 -> V_31 -> V_32 ( V_11 -> V_11 ) ;
}
static int F_17 ( struct V_2 * V_3 ,
struct V_15 * V_9 )
{
struct V_1 * V_10 =
F_1 ( V_3 ) ;
return F_18 ( V_10 -> V_27 , V_9 ) ;
}
static struct V_4 *
F_19 ( struct V_2 * V_3 )
{
struct V_1 * V_10 =
F_1 ( V_3 ) ;
return & V_10 -> V_5 ;
}
static enum V_33
F_20 ( struct V_2 * V_3 , bool V_34 )
{
return V_35 ;
}
static void
F_21 ( struct V_2 * V_3 )
{
struct V_1 * V_10 =
F_1 ( V_3 ) ;
struct V_6 * V_11 = F_4 ( V_10 ) ;
F_22 ( V_11 -> V_11 ) ;
F_23 ( V_3 ) ;
}
static int F_24 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_40 * V_27 = V_37 -> V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 = NULL ;
struct V_6 * V_11 ;
int V_46 ;
V_43 = F_25 ( V_39 -> V_47 ) ;
if ( ! V_43 )
return - V_48 ;
V_45 = F_26 ( V_43 ) ;
F_27 ( V_43 ) ;
if ( ! V_45 )
return - V_49 ;
V_11 = F_28 ( V_37 -> V_37 , sizeof( * V_11 ) , V_50 ) ;
if ( ! V_11 )
return - V_48 ;
V_11 -> V_8 . V_14 = V_13 ;
V_11 -> V_8 . V_27 = V_27 ;
F_29 ( & V_11 -> V_8 . V_5 ,
& V_51 ) ;
V_46 = F_30 ( V_37 , & V_11 -> V_8 . V_5 ,
& V_52 ,
V_53 ) ;
if ( V_46 )
return V_46 ;
V_11 -> V_8 . V_3 . V_14 = V_13 ;
V_11 -> V_8 . V_3 . V_54 = V_55 ;
F_31 ( & V_11 -> V_8 . V_3 ,
& V_56 ) ;
V_46 = F_32 ( V_37 , & V_11 -> V_8 . V_3 ,
& V_57 ,
V_58 ) ;
if ( V_46 )
goto V_59;
F_33 ( & V_11 -> V_8 . V_3 ,
& V_11 -> V_8 . V_5 ) ;
V_11 -> V_8 . V_5 . V_60 = 0x1 ;
F_34 ( V_45 , & V_11 -> V_8 . V_3 ) ;
V_11 -> V_11 = V_45 ;
return 0 ;
V_59:
F_15 ( & V_11 -> V_8 . V_5 ) ;
return V_46 ;
}
int F_35 ( struct V_36 * V_37 )
{
struct V_42 * V_61 , * V_43 ;
struct V_38 V_39 ;
int V_46 ;
V_61 = F_36 ( V_37 -> V_37 -> V_62 , L_1 ) ;
if ( ! V_61 )
return - V_48 ;
V_43 = F_36 ( V_61 , L_2 ) ;
F_27 ( V_61 ) ;
if ( ! V_43 )
return - V_48 ;
V_46 = F_37 ( V_43 , & V_39 ) ;
F_27 ( V_61 ) ;
if ( V_46 )
return V_46 ;
return F_24 ( V_37 , & V_39 ) ;
}
