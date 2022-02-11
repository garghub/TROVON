static void F_1 ( struct V_1 * V_2 )
{
if ( ! F_2 ( V_2 , & V_3 ) )
return;
F_3 ( & V_4 ) ;
}
static void F_4 ( T_1 * V_5 , T_2 V_6 )
{
struct V_7 V_8 ;
F_5 ( & V_8 , V_5 , V_6 ) ;
F_6 ( V_2 , & V_8 , 1 , V_5 , V_9 ) ;
F_7 ( V_2 ) ;
}
static int F_8 ( struct V_10 * V_11 , void * V_5 , T_2 V_6 , bool V_12 )
{
int V_13 ;
if ( ! V_14 ) {
V_14 = true ;
F_9 ( & V_4 ) ;
F_4 ( V_5 , V_6 ) ;
}
if ( ! V_12 )
return 0 ;
V_13 = F_10 ( & V_4 ) ;
if ( V_13 < 0 )
return V_13 ;
V_14 = false ;
return V_3 ;
}
static void F_11 ( struct V_10 * V_11 )
{
if ( V_14 )
F_12 ( & V_4 ) ;
}
static int F_13 ( struct V_15 * V_16 )
{
int V_17 ;
if ( V_2 ) {
return - V_18 ;
}
V_2 = F_14 ( V_16 , F_1 , L_1 ) ;
if ( F_15 ( V_2 ) ) {
V_17 = F_16 ( V_2 ) ;
V_2 = NULL ;
return V_17 ;
}
V_17 = F_17 ( & V_19 ) ;
if ( V_17 ) {
V_16 -> V_20 -> V_21 ( V_16 ) ;
V_2 = NULL ;
return V_17 ;
}
return 0 ;
}
static void F_18 ( struct V_15 * V_16 )
{
V_16 -> V_20 -> V_22 ( V_16 ) ;
V_14 = false ;
F_19 ( & V_19 ) ;
V_16 -> V_20 -> V_21 ( V_16 ) ;
V_2 = NULL ;
}
static int F_20 ( struct V_15 * V_16 )
{
return F_13 ( V_16 ) ;
}
static void F_21 ( struct V_15 * V_16 )
{
F_18 ( V_16 ) ;
}
static int F_22 ( struct V_15 * V_16 )
{
F_18 ( V_16 ) ;
return 0 ;
}
static int F_23 ( struct V_15 * V_16 )
{
return F_13 ( V_16 ) ;
}
