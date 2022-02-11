static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_1 * V_5 )
{
struct V_6 * V_7 = V_5 -> V_8 -> V_9 ;
V_5 -> V_10 = F_4 ( V_7 , L_1 ) ;
if ( F_5 ( V_5 -> V_10 ) ) {
F_6 ( V_5 -> V_8 , L_2 ) ;
return F_7 ( V_5 -> V_10 ) ;
}
return 0 ;
}
static void F_8 ( struct V_2 * V_4 )
{
}
static void F_9 ( struct V_2 * V_4 )
{
struct V_1 * V_5 = F_1 ( V_4 ) ;
int V_11 = F_10 ( V_5 -> V_8 -> V_9 , V_4 ) ;
F_11 ( V_5 -> V_10 , V_12 ,
V_13 ,
V_11 << V_14 ) ;
}
static int F_12 ( struct V_2 * V_4 ,
struct V_15 * V_16 ,
struct V_17 * V_18 )
{
struct V_19 * V_19 = F_13 ( V_16 ) ;
V_19 -> V_20 = V_21 ;
V_19 -> V_22 = 2 ;
V_19 -> V_23 = 3 ;
return 0 ;
}
static enum V_24 F_14 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
if ( V_28 -> clock < 13500 )
return V_29 ;
if ( V_28 -> clock > 216000 )
return V_30 ;
return V_31 ;
}
static enum V_24 F_15 ( struct V_25 * V_26 ,
struct V_27 * V_28 )
{
if ( V_28 -> clock < 13500 )
return V_29 ;
if ( V_28 -> clock > 216000 )
return V_30 ;
return V_31 ;
}
static int F_16 ( struct V_32 * V_8 , struct V_32 * V_33 ,
void * V_34 )
{
struct V_35 * V_36 = F_17 ( V_8 ) ;
const struct V_37 * V_38 ;
const struct V_39 * V_40 ;
struct V_41 * V_42 = V_34 ;
struct V_2 * V_4 ;
struct V_1 * V_5 ;
int V_43 ;
if ( ! V_36 -> V_8 . V_9 )
return - V_44 ;
V_5 = F_18 ( & V_36 -> V_8 , sizeof( * V_5 ) , V_45 ) ;
if ( ! V_5 )
return - V_46 ;
V_40 = F_19 ( V_47 , V_36 -> V_8 . V_9 ) ;
V_38 = V_40 -> V_34 ;
V_5 -> V_8 = & V_36 -> V_8 ;
V_4 = & V_5 -> V_4 ;
V_4 -> V_48 = F_20 ( V_42 , V_8 -> V_9 ) ;
if ( V_4 -> V_48 == 0 )
return - V_49 ;
V_43 = F_3 ( V_5 ) ;
if ( V_43 < 0 )
return V_43 ;
F_21 ( V_4 , & V_50 ) ;
F_22 ( V_42 , V_4 , & V_51 ,
V_52 , NULL ) ;
V_43 = F_23 ( V_36 , V_4 , V_38 ) ;
if ( V_43 )
F_24 ( V_4 ) ;
return V_43 ;
}
static void F_25 ( struct V_32 * V_8 , struct V_32 * V_33 ,
void * V_34 )
{
return F_26 ( V_8 ) ;
}
static int F_27 ( struct V_35 * V_36 )
{
return F_28 ( & V_36 -> V_8 , & V_53 ) ;
}
static int F_29 ( struct V_35 * V_36 )
{
F_30 ( & V_36 -> V_8 , & V_53 ) ;
return 0 ;
}
