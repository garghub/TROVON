static int F_1 ( struct V_1 * V_2 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
return V_5 ;
}
static void F_3 ( struct V_1 * V_2 )
{
F_4 ( V_2 ) ;
F_5 ( V_2 ) ;
}
static enum V_6
F_6 ( struct V_1 * V_2 , bool V_7 )
{
return V_8 ;
}
static int F_7 ( struct V_9 * V_10 ,
struct V_11 * V_12 )
{
struct V_13 * V_14 ;
struct V_1 * V_2 ;
int V_15 ;
V_14 = F_8 ( V_10 -> V_16 , sizeof( * V_14 ) , V_17 ) ;
if ( V_14 == NULL )
return - V_18 ;
V_2 = & V_14 -> V_2 ;
V_2 -> V_19 . V_20 = 0 ;
V_2 -> V_19 . V_21 = 0 ;
V_15 = F_9 ( V_10 -> V_22 , V_2 , & V_23 ,
V_24 ) ;
if ( V_15 < 0 )
return V_15 ;
F_10 ( V_2 , & V_25 ) ;
V_15 = F_11 ( V_2 ) ;
if ( V_15 < 0 )
return V_15 ;
F_12 ( V_2 , V_26 ) ;
F_13 ( & V_2 -> V_27 ,
V_10 -> V_22 -> V_28 . V_29 , V_26 ) ;
V_15 = F_14 ( V_2 , & V_12 -> V_30 ) ;
if ( V_15 < 0 )
return V_15 ;
V_2 -> V_30 = & V_12 -> V_30 ;
V_14 -> V_30 = V_12 ;
return 0 ;
}
static void F_15 ( struct V_31 * V_30 , int V_4 )
{
}
static bool F_16 ( struct V_31 * V_30 ,
const struct V_3 * V_4 ,
struct V_3 * V_32 )
{
return true ;
}
int F_17 ( struct V_9 * V_10 ,
const struct V_33 * V_34 ,
unsigned int V_35 )
{
struct V_11 * V_12 ;
int V_15 ;
V_12 = F_8 ( V_10 -> V_16 , sizeof( * V_12 ) , V_17 ) ;
if ( V_12 == NULL )
return - V_18 ;
V_12 -> V_35 = V_35 ;
V_15 = F_18 ( V_10 -> V_22 , & V_12 -> V_30 , & V_36 ,
V_37 ) ;
if ( V_15 < 0 )
return V_15 ;
F_19 ( & V_12 -> V_30 , & V_38 ) ;
return F_7 ( V_10 , V_12 ) ;
}
