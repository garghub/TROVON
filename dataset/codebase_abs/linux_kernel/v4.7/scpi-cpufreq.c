static struct V_1 * F_1 ( struct V_2 * V_3 )
{
int V_4 = F_2 ( V_3 -> V_5 ) ;
if ( V_4 < 0 )
return F_3 ( - V_6 ) ;
return V_7 -> V_8 ( V_4 ) ;
}
static int F_4 ( struct V_2 * V_3 )
{
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( F_5 ( V_9 ) )
return F_6 ( V_9 ) ;
return V_9 -> V_10 ;
}
static int F_7 ( const struct V_11 * V_11 )
{
int V_12 , V_13 ;
struct V_14 * V_15 ;
struct V_2 * V_3 = F_8 ( F_9 ( V_11 ) ) ;
struct V_1 * V_9 = F_1 ( V_3 ) ;
if ( F_5 ( V_9 ) )
return F_6 ( V_9 ) ;
if ( ! V_9 -> V_16 )
return - V_17 ;
for ( V_15 = V_9 -> V_16 , V_12 = 0 ; V_12 < V_9 -> V_18 ; V_12 ++ , V_15 ++ ) {
V_13 = F_10 ( V_3 , V_15 -> V_19 , V_15 -> V_20 * 1000 ) ;
if ( V_13 ) {
F_11 ( V_3 , L_1 ,
V_15 -> V_19 , V_15 -> V_20 ) ;
while ( V_12 -- > 0 )
F_12 ( V_3 , ( -- V_15 ) -> V_19 ) ;
return V_13 ;
}
}
V_13 = F_13 ( V_3 , V_11 ) ;
if ( V_13 )
F_14 ( V_3 , L_2 ,
V_21 , V_13 ) ;
return V_13 ;
}
static int F_15 ( struct V_22 * V_23 )
{
V_7 = F_16 () ;
if ( ! V_7 )
return - V_17 ;
return F_17 ( & V_24 ) ;
}
static int F_18 ( struct V_22 * V_23 )
{
F_19 ( & V_24 ) ;
V_7 = NULL ;
return 0 ;
}
