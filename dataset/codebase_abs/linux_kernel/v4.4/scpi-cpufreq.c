static struct V_1 * F_1 ( struct V_2 * V_3 )
{
int V_4 = F_2 ( V_3 -> V_5 ) ;
if ( V_4 < 0 )
return F_3 ( - V_6 ) ;
return V_7 -> V_8 ( V_4 ) ;
}
static int F_4 ( struct V_2 * V_3 , bool remove )
{
int V_9 , V_10 = 0 ;
struct V_11 * V_12 ;
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( F_5 ( V_13 ) )
return F_6 ( V_13 ) ;
if ( ! V_13 -> V_14 )
return - V_15 ;
for ( V_12 = V_13 -> V_14 , V_9 = 0 ; V_9 < V_13 -> V_16 ; V_9 ++ , V_12 ++ ) {
if ( remove )
F_7 ( V_3 , V_12 -> V_17 ) ;
else
V_10 = F_8 ( V_3 , V_12 -> V_17 ,
V_12 -> V_18 * 1000 ) ;
if ( V_10 ) {
F_9 ( V_3 , L_1 ,
V_12 -> V_17 , V_12 -> V_18 ) ;
while ( V_9 -- > 0 )
F_7 ( V_3 , ( -- V_12 ) -> V_17 ) ;
return V_10 ;
}
}
return V_10 ;
}
static int F_10 ( struct V_2 * V_3 )
{
struct V_1 * V_13 = F_1 ( V_3 ) ;
if ( F_5 ( V_13 ) )
return F_6 ( V_13 ) ;
return V_13 -> V_19 ;
}
static int F_11 ( struct V_2 * V_3 )
{
return F_4 ( V_3 , false ) ;
}
static void F_12 ( struct V_2 * V_3 )
{
F_4 ( V_3 , true ) ;
}
static int F_13 ( struct V_20 * V_21 )
{
V_7 = F_14 () ;
if ( ! V_7 )
return - V_15 ;
return F_15 ( & V_22 ) ;
}
static int F_16 ( struct V_20 * V_21 )
{
F_17 ( & V_22 ) ;
V_7 = NULL ;
return 0 ;
}
