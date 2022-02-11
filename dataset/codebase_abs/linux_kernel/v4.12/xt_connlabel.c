static bool
F_1 ( const struct V_1 * V_2 , struct V_3 * V_4 )
{
const struct V_5 * V_6 = V_4 -> V_7 ;
enum V_8 V_9 ;
struct V_10 * V_11 ;
struct V_12 * V_13 ;
bool V_14 = V_6 -> V_15 & V_16 ;
V_13 = F_2 ( V_2 , & V_9 ) ;
if ( V_13 == NULL )
return V_14 ;
V_11 = F_3 ( V_13 ) ;
if ( ! V_11 )
return V_14 ;
if ( F_4 ( V_6 -> V_17 , V_11 -> V_18 ) )
return ! V_14 ;
if ( V_6 -> V_15 & V_19 ) {
if ( ! F_5 ( V_6 -> V_17 , V_11 -> V_18 ) )
F_6 ( V_20 , V_13 ) ;
return ! V_14 ;
}
return V_14 ;
}
static int F_7 ( const struct V_21 * V_4 )
{
const int V_15 = V_16 |
V_19 ;
struct V_5 * V_6 = V_4 -> V_7 ;
int V_22 ;
if ( V_6 -> V_15 & ~ V_15 ) {
F_8 ( L_1 , V_6 -> V_15 ) ;
return - V_23 ;
}
V_22 = F_9 ( V_4 -> V_24 , V_4 -> V_25 ) ;
if ( V_22 < 0 ) {
F_10 ( L_2 ,
V_4 -> V_25 ) ;
return V_22 ;
}
V_22 = F_11 ( V_4 -> V_24 , V_6 -> V_17 ) ;
if ( V_22 < 0 )
F_12 ( V_4 -> V_24 , V_4 -> V_25 ) ;
return V_22 ;
}
static void F_13 ( const struct V_26 * V_4 )
{
F_14 ( V_4 -> V_24 ) ;
F_12 ( V_4 -> V_24 , V_4 -> V_25 ) ;
}
static int T_1 F_15 ( void )
{
return F_16 ( & V_27 ) ;
}
static void T_2 F_17 ( void )
{
F_18 ( & V_27 ) ;
}
