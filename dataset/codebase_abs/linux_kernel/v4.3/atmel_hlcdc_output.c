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
case V_24 :
V_17 |= V_25 << 8 ;
break;
case V_26 :
default:
break;
}
}
F_11 ( V_9 -> V_27 -> V_28 -> V_29 , F_12 ( 5 ) ,
V_30 ,
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
return V_10 -> V_10 -> V_31 -> V_32 ( V_10 -> V_10 ) ;
}
static int F_16 ( struct V_2 * V_3 ,
struct V_11 * V_12 )
{
struct V_1 * V_9 =
F_1 ( V_3 ) ;
return F_17 ( V_9 -> V_27 , V_12 ) ;
}
static struct V_4 *
F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_9 =
F_1 ( V_3 ) ;
return & V_9 -> V_5 ;
}
static enum V_33
F_19 ( struct V_2 * V_3 , bool V_34 )
{
return V_35 ;
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
static int F_23 ( struct V_36 * V_37 ,
struct V_38 * V_39 )
{
struct V_40 * V_27 = V_37 -> V_41 ;
struct V_42 * V_43 ;
struct V_44 * V_45 = NULL ;
struct V_6 * V_10 ;
int V_46 ;
V_43 = F_24 ( V_39 -> V_47 ) ;
if ( ! V_43 )
return - V_48 ;
V_45 = F_25 ( V_43 ) ;
F_26 ( V_43 ) ;
if ( ! V_45 )
return - V_49 ;
V_10 = F_27 ( V_37 -> V_37 , sizeof( * V_10 ) , V_50 ) ;
if ( ! V_10 )
return - V_48 ;
V_10 -> V_8 . V_51 = V_52 ;
V_10 -> V_8 . V_27 = V_27 ;
F_28 ( & V_10 -> V_8 . V_5 ,
& V_53 ) ;
V_46 = F_29 ( V_37 , & V_10 -> V_8 . V_5 ,
& V_54 ,
V_55 ) ;
if ( V_46 )
return V_46 ;
V_10 -> V_8 . V_3 . V_51 = V_52 ;
V_10 -> V_8 . V_3 . V_56 = V_57 ;
F_30 ( & V_10 -> V_8 . V_3 ,
& V_58 ) ;
V_46 = F_31 ( V_37 , & V_10 -> V_8 . V_3 ,
& V_59 ,
V_60 ) ;
if ( V_46 )
goto V_61;
F_32 ( & V_10 -> V_8 . V_3 ,
& V_10 -> V_8 . V_5 ) ;
V_10 -> V_8 . V_5 . V_62 = 0x1 ;
F_33 ( V_45 , & V_10 -> V_8 . V_3 ) ;
V_10 -> V_10 = V_45 ;
return 0 ;
V_61:
F_14 ( & V_10 -> V_8 . V_5 ) ;
return V_46 ;
}
int F_34 ( struct V_36 * V_37 )
{
struct V_42 * V_63 , * V_43 ;
struct V_38 V_39 ;
int V_46 ;
V_63 = F_35 ( V_37 -> V_37 -> V_64 , L_1 ) ;
if ( ! V_63 )
return - V_48 ;
V_43 = F_35 ( V_63 , L_2 ) ;
F_26 ( V_63 ) ;
if ( ! V_43 )
return - V_48 ;
V_46 = F_36 ( V_43 , & V_39 ) ;
F_26 ( V_63 ) ;
if ( V_46 )
return V_46 ;
return F_23 ( V_37 , & V_39 ) ;
}
