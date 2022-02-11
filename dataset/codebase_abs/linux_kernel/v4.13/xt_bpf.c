static int F_1 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_4 * * V_5 )
{
struct V_6 V_7 ;
V_7 . V_3 = V_3 ;
V_7 . V_8 = V_2 ;
if ( F_2 ( V_5 , & V_7 ) ) {
F_3 ( L_1 ) ;
return - V_9 ;
}
return 0 ;
}
static int F_4 ( int V_10 , struct V_4 * * V_5 )
{
struct V_4 * V_11 ;
V_11 = F_5 ( V_10 , V_12 ) ;
if ( F_6 ( V_11 ) )
return F_7 ( V_11 ) ;
* V_5 = V_11 ;
return 0 ;
}
static int F_8 ( const struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 ;
return F_1 ( V_16 -> V_18 ,
V_16 -> V_19 ,
& V_16 -> V_8 ) ;
}
static int F_9 ( const struct V_13 * V_14 )
{
struct V_20 * V_16 = V_14 -> V_17 ;
if ( V_16 -> V_21 == V_22 )
return F_1 ( V_16 -> V_18 ,
V_16 -> V_19 ,
& V_16 -> V_8 ) ;
else if ( V_16 -> V_21 == V_23 ||
V_16 -> V_21 == V_24 )
return F_4 ( V_16 -> V_10 , & V_16 -> V_8 ) ;
else
return - V_9 ;
}
static bool F_10 ( const struct V_25 * V_26 , struct V_27 * V_14 )
{
const struct V_15 * V_16 = V_14 -> V_17 ;
return F_11 ( V_16 -> V_8 , V_26 ) ;
}
static bool F_12 ( const struct V_25 * V_26 , struct V_27 * V_14 )
{
const struct V_20 * V_16 = V_14 -> V_17 ;
return ! ! F_13 ( V_16 -> V_8 , (struct V_25 * ) V_26 ) ;
}
static void F_14 ( const struct V_28 * V_14 )
{
const struct V_15 * V_16 = V_14 -> V_17 ;
F_15 ( V_16 -> V_8 ) ;
}
static void F_16 ( const struct V_28 * V_14 )
{
const struct V_20 * V_16 = V_14 -> V_17 ;
F_15 ( V_16 -> V_8 ) ;
}
static int T_2 F_17 ( void )
{
return F_18 ( V_29 , F_19 ( V_29 ) ) ;
}
static void T_3 F_20 ( void )
{
F_21 ( V_29 , F_19 ( V_29 ) ) ;
}
