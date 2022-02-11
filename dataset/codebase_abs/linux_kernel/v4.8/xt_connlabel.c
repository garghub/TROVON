static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
enum V_8 V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
bool V_14 = V_6 -> V_15 & V_16 ;
V_13 = F_2 ( V_2 , & V_9 ) ;
if ( V_13 == NULL || F_3 ( V_13 ) )
return V_14 ;
V_11 = F_4 ( V_13 ) ;
if ( ! V_11 )
return V_14 ;
if ( F_5 ( V_6 -> V_17 , V_11 -> V_18 ) )
return ! V_14 ;
if ( V_6 -> V_15 & V_19 ) {
if ( ! F_6 ( V_6 -> V_17 , V_11 -> V_18 ) )
F_7 ( V_20 , V_13 ) ;
return ! V_14 ;
}
return V_14 ;
}
static int F_8 ( const struct V_21 * V_4 )
{
const int V_15 = V_16 |
V_19 ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_22 ;
if ( V_6 -> V_15 & ~ V_15 ) {
F_9 ( L_1 , V_6 -> V_15 ) ;
return - V_23 ;
}
V_22 = F_10 ( V_4 -> V_24 ) ;
if ( V_22 < 0 ) {
F_11 ( L_2 ,
V_4 -> V_24 ) ;
return V_22 ;
}
V_22 = F_12 ( V_4 -> V_25 , V_6 -> V_17 ) ;
if ( V_22 < 0 )
F_13 ( V_4 -> V_24 ) ;
return V_22 ;
}
static void F_14 ( const struct V_26 * V_4 )
{
F_15 ( V_4 -> V_25 ) ;
F_13 ( V_4 -> V_24 ) ;
}
static int T_1 F_16 ( void )
{
return F_17 ( & V_27 ) ;
}
static void T_2 F_18 ( void )
{
F_19 ( & V_27 ) ;
}
