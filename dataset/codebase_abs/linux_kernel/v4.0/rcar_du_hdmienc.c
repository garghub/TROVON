static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_3 != V_8 )
V_3 = V_9 ;
if ( V_5 -> V_10 == V_3 )
return;
if ( V_3 == V_8 && V_5 -> V_11 -> V_12 )
F_4 ( V_5 -> V_11 -> V_12 , V_2 -> V_13 , V_3 ) ;
if ( V_7 -> V_10 )
V_7 -> V_10 ( V_2 , V_3 ) ;
if ( V_3 != V_8 && V_5 -> V_11 -> V_12 )
F_4 ( V_5 -> V_11 -> V_12 , V_2 -> V_13 , V_3 ) ;
V_5 -> V_10 = V_3 ;
}
static bool F_5 ( struct V_1 * V_2 ,
const struct V_14 * V_3 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_5 -> V_11 -> V_12 )
V_15 -> clock = F_6 ( V_15 -> clock ,
30000 , 150000 ) ;
if ( V_7 -> V_16 == NULL )
return true ;
return V_7 -> V_16 ( V_2 , V_3 , V_15 ) ;
}
static void F_7 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_9 ) ;
}
static void F_8 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_8 ) ;
}
static void F_9 ( struct V_1 * V_2 ,
struct V_14 * V_3 ,
struct V_14 * V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_7 -> V_17 )
V_7 -> V_17 ( V_2 , V_3 , V_15 ) ;
F_10 ( V_2 -> V_13 , V_5 -> V_11 -> V_18 ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_1 ( V_2 , V_9 ) ;
F_12 ( V_2 ) ;
F_13 ( V_5 -> V_19 ) ;
}
int F_14 ( struct V_20 * V_21 ,
struct V_22 * V_11 , struct V_23 * V_24 )
{
struct V_1 * V_2 = F_15 ( V_11 ) ;
struct V_25 * V_26 ;
struct V_27 * V_28 ;
struct V_4 * V_5 ;
int V_29 ;
V_5 = F_16 ( V_21 -> V_19 , sizeof( * V_5 ) , V_30 ) ;
if ( V_5 == NULL )
return - V_31 ;
V_28 = F_17 ( V_24 ) ;
if ( ! V_28 || ! F_18 ( V_28 ) )
return - V_32 ;
V_5 -> V_19 = & V_28 -> V_19 ;
if ( V_5 -> V_19 -> V_26 == NULL ) {
V_29 = - V_32 ;
goto error;
}
V_26 = F_19 ( F_20 ( V_5 -> V_19 -> V_26 ) ) ;
V_29 = V_26 -> V_33 ( V_28 , V_21 -> V_34 , & V_11 -> V_35 ) ;
if ( V_29 < 0 )
goto error;
V_29 = F_21 ( V_21 -> V_34 , V_2 , & V_36 ,
V_37 ) ;
if ( V_29 < 0 )
goto error;
F_22 ( V_2 , & V_38 ) ;
V_11 -> V_39 = V_5 ;
V_5 -> V_11 = V_11 ;
return 0 ;
error:
F_13 ( V_5 -> V_19 ) ;
return V_29 ;
}
