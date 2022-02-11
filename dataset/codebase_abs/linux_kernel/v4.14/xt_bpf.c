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
static int F_8 ( const char * V_13 , struct V_4 * * V_5 )
{
T_2 V_14 = F_9 () ;
int V_15 , V_10 ;
F_10 ( V_16 ) ;
V_10 = F_11 ( V_13 ) ;
F_10 ( V_14 ) ;
if ( V_10 < 0 )
return V_10 ;
V_15 = F_4 ( V_10 , V_5 ) ;
F_12 ( V_10 ) ;
return V_15 ;
}
static int F_13 ( const struct V_17 * V_18 )
{
struct V_19 * V_20 = V_18 -> V_21 ;
return F_1 ( V_20 -> V_22 ,
V_20 -> V_23 ,
& V_20 -> V_8 ) ;
}
static int F_14 ( const struct V_17 * V_18 )
{
struct V_24 * V_20 = V_18 -> V_21 ;
if ( V_20 -> V_25 == V_26 )
return F_1 ( V_20 -> V_22 ,
V_20 -> V_23 ,
& V_20 -> V_8 ) ;
else if ( V_20 -> V_25 == V_27 )
return F_4 ( V_20 -> V_10 , & V_20 -> V_8 ) ;
else if ( V_20 -> V_25 == V_28 )
return F_8 ( V_20 -> V_13 , & V_20 -> V_8 ) ;
else
return - V_9 ;
}
static bool F_15 ( const struct V_29 * V_30 , struct V_31 * V_18 )
{
const struct V_19 * V_20 = V_18 -> V_21 ;
return F_16 ( V_20 -> V_8 , V_30 ) ;
}
static bool F_17 ( const struct V_29 * V_30 , struct V_31 * V_18 )
{
const struct V_24 * V_20 = V_18 -> V_21 ;
return ! ! F_18 ( V_20 -> V_8 , (struct V_29 * ) V_30 ) ;
}
static void F_19 ( const struct V_32 * V_18 )
{
const struct V_19 * V_20 = V_18 -> V_21 ;
F_20 ( V_20 -> V_8 ) ;
}
static void F_21 ( const struct V_32 * V_18 )
{
const struct V_24 * V_20 = V_18 -> V_21 ;
F_20 ( V_20 -> V_8 ) ;
}
static int T_3 F_22 ( void )
{
return F_23 ( V_33 , F_24 ( V_33 ) ) ;
}
static void T_4 F_25 ( void )
{
F_26 ( V_33 , F_24 ( V_33 ) ) ;
}
