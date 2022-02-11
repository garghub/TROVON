static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_5 -> V_8 == V_3 )
return;
if ( V_7 -> V_8 )
V_7 -> V_8 ( V_2 , V_3 ) ;
V_5 -> V_8 = V_3 ;
}
static bool F_4 ( struct V_1 * V_2 ,
const struct V_9 * V_3 ,
struct V_9 * V_10 )
{
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_7 -> V_11 == NULL )
return true ;
return V_7 -> V_11 ( V_2 , V_3 , V_10 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_12 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_1 ( V_2 , V_13 ) ;
}
static void F_7 ( struct V_1 * V_2 ,
struct V_9 * V_3 ,
struct V_9 * V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = F_3 ( V_2 ) ;
if ( V_7 -> V_14 )
V_7 -> V_14 ( V_2 , V_3 , V_10 ) ;
F_8 ( V_2 -> V_15 , V_5 -> V_16 -> V_17 ) ;
}
static void F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_1 ( V_2 , V_12 ) ;
F_10 ( V_2 ) ;
F_11 ( V_5 -> V_18 ) ;
}
int F_12 ( struct V_19 * V_20 ,
struct V_21 * V_16 , struct V_22 * V_23 )
{
struct V_1 * V_2 = F_13 ( V_16 ) ;
struct V_24 * V_25 ;
struct V_26 * V_27 ;
struct V_4 * V_5 ;
int V_28 ;
V_5 = F_14 ( V_20 -> V_18 , sizeof( * V_5 ) , V_29 ) ;
if ( V_5 == NULL )
return - V_30 ;
V_27 = F_15 ( V_23 ) ;
if ( ! V_27 || ! F_16 ( V_27 ) )
return - V_31 ;
V_5 -> V_18 = & V_27 -> V_18 ;
if ( V_5 -> V_18 -> V_25 == NULL ) {
V_28 = - V_31 ;
goto error;
}
V_25 = F_17 ( F_18 ( V_5 -> V_18 -> V_25 ) ) ;
V_28 = V_25 -> V_32 ( V_27 , V_20 -> V_33 , & V_16 -> V_34 ) ;
if ( V_28 < 0 )
goto error;
V_28 = F_19 ( V_20 -> V_33 , V_2 , & V_35 ,
V_36 ) ;
if ( V_28 < 0 )
goto error;
F_20 ( V_2 , & V_37 ) ;
V_16 -> V_38 = V_5 ;
V_5 -> V_16 = V_16 ;
return 0 ;
error:
F_11 ( V_5 -> V_18 ) ;
return V_28 ;
}
