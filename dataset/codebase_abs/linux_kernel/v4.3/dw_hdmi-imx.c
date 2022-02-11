static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 -> V_6 ;
V_2 -> V_7 = F_2 ( V_4 , L_1 ) ;
if ( F_3 ( V_2 -> V_7 ) ) {
F_4 ( V_2 -> V_5 , L_2 ) ;
return F_5 ( V_2 -> V_7 ) ;
}
return 0 ;
}
static void F_6 ( struct V_8 * V_9 )
{
}
static bool F_7 ( struct V_8 * V_9 ,
const struct V_10 * V_11 ,
struct V_10 * V_12 )
{
return true ;
}
static void F_8 ( struct V_8 * V_9 ,
struct V_10 * V_11 ,
struct V_10 * V_12 )
{
}
static void F_9 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_10 ( V_9 , struct V_1 , V_9 ) ;
int V_13 = F_11 ( V_2 -> V_5 -> V_6 , V_9 ) ;
F_12 ( V_2 -> V_7 , V_14 ,
V_15 ,
V_13 << V_16 ) ;
}
static void F_13 ( struct V_8 * V_9 )
{
F_14 ( V_9 , V_17 ) ;
}
static enum V_18 F_15 ( struct V_19 * V_20 ,
struct V_10 * V_11 )
{
if ( V_11 -> clock < 13500 )
return V_21 ;
if ( V_11 -> clock > 266000 )
return V_22 ;
return V_23 ;
}
static enum V_18 F_16 ( struct V_19 * V_20 ,
struct V_10 * V_11 )
{
if ( V_11 -> clock < 13500 )
return V_21 ;
if ( V_11 -> clock > 270000 )
return V_22 ;
return V_23 ;
}
static int F_17 ( struct V_24 * V_5 , struct V_24 * V_25 ,
void * V_26 )
{
struct V_27 * V_28 = F_18 ( V_5 ) ;
const struct V_29 * V_30 ;
const struct V_31 * V_32 ;
struct V_33 * V_34 = V_26 ;
struct V_8 * V_9 ;
struct V_1 * V_2 ;
struct V_35 * V_36 ;
int V_37 ;
int V_38 ;
if ( ! V_28 -> V_5 . V_6 )
return - V_39 ;
V_2 = F_19 ( & V_28 -> V_5 , sizeof( * V_2 ) , V_40 ) ;
if ( ! V_2 )
return - V_41 ;
V_32 = F_20 ( V_42 , V_28 -> V_5 . V_6 ) ;
V_30 = V_32 -> V_26 ;
V_2 -> V_5 = & V_28 -> V_5 ;
V_9 = & V_2 -> V_9 ;
V_37 = F_21 ( V_28 , 0 ) ;
if ( V_37 < 0 )
return V_37 ;
V_36 = F_22 ( V_28 , V_43 , 0 ) ;
if ( ! V_36 )
return - V_44 ;
F_23 ( V_28 , V_2 ) ;
V_9 -> V_45 = F_24 ( V_34 , V_5 -> V_6 ) ;
if ( V_9 -> V_45 == 0 )
return - V_46 ;
V_38 = F_1 ( V_2 ) ;
if ( V_38 < 0 )
return V_38 ;
F_25 ( V_9 , & V_47 ) ;
F_26 ( V_34 , V_9 , & V_48 ,
V_49 ) ;
return F_27 ( V_5 , V_25 , V_26 , V_9 , V_36 , V_37 , V_30 ) ;
}
static void F_28 ( struct V_24 * V_5 , struct V_24 * V_25 ,
void * V_26 )
{
return F_29 ( V_5 , V_25 , V_26 ) ;
}
static int F_30 ( struct V_27 * V_28 )
{
return F_31 ( & V_28 -> V_5 , & V_50 ) ;
}
static int F_32 ( struct V_27 * V_28 )
{
F_33 ( & V_28 -> V_5 , & V_50 ) ;
return 0 ;
}
