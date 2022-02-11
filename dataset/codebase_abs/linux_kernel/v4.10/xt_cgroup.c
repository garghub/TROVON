static int F_1 ( const struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_6 & ~ 1 )
return - V_7 ;
return 0 ;
}
static int F_2 ( const struct V_1 * V_2 )
{
struct V_8 * V_4 = V_2 -> V_5 ;
struct V_9 * V_10 ;
if ( ( V_4 -> V_11 & ~ 1 ) || ( V_4 -> V_12 & ~ 1 ) )
return - V_7 ;
if ( ! V_4 -> V_13 && ! V_4 -> V_14 ) {
F_3 ( L_1 ) ;
return - V_7 ;
}
if ( V_4 -> V_13 && V_4 -> V_14 ) {
F_3 ( L_2 ) ;
return - V_7 ;
}
if ( V_4 -> V_13 ) {
V_10 = F_4 ( V_4 -> V_15 ) ;
if ( F_5 ( V_10 ) ) {
F_3 ( L_3 ,
F_6 ( V_10 ) ) ;
return - V_7 ;
}
V_4 -> V_16 = V_10 ;
}
return 0 ;
}
static bool
F_7 ( const struct V_17 * V_18 , struct V_19 * V_2 )
{
const struct V_3 * V_4 = V_2 -> V_5 ;
if ( V_18 -> V_20 == NULL || ! F_8 ( V_18 -> V_20 ) )
return false ;
return ( V_4 -> V_21 == F_9 ( & V_18 -> V_20 -> V_22 ) ) ^
V_4 -> V_6 ;
}
static bool F_10 ( const struct V_17 * V_18 , struct V_19 * V_2 )
{
const struct V_8 * V_4 = V_2 -> V_5 ;
struct V_23 * V_24 = & V_18 -> V_20 -> V_22 ;
struct V_9 * V_25 = V_4 -> V_16 ;
if ( ! V_18 -> V_20 || ! F_8 ( V_18 -> V_20 ) )
return false ;
if ( V_25 )
return F_11 ( F_12 ( V_24 ) , V_25 ) ^
V_4 -> V_11 ;
else
return ( V_4 -> V_26 == F_9 ( V_24 ) ) ^
V_4 -> V_12 ;
}
static void F_13 ( const struct V_27 * V_2 )
{
struct V_8 * V_4 = V_2 -> V_5 ;
if ( V_4 -> V_16 )
F_14 ( V_4 -> V_16 ) ;
}
static int T_1 F_15 ( void )
{
return F_16 ( V_28 , F_17 ( V_28 ) ) ;
}
static void T_2 F_18 ( void )
{
F_19 ( V_28 , F_17 ( V_28 ) ) ;
}
