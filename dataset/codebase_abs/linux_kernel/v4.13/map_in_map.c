struct V_1 * F_1 ( int V_2 )
{
struct V_1 * V_3 , * V_4 ;
struct V_5 V_6 ;
V_6 = F_2 ( V_2 ) ;
V_3 = F_3 ( V_6 ) ;
if ( F_4 ( V_3 ) )
return V_3 ;
if ( V_3 -> V_7 == V_8 ) {
F_5 ( V_6 ) ;
return F_6 ( - V_9 ) ;
}
if ( V_3 -> V_4 ) {
F_5 ( V_6 ) ;
return F_6 ( - V_10 ) ;
}
V_4 = F_7 ( sizeof( * V_4 ) , V_11 ) ;
if ( ! V_4 ) {
F_5 ( V_6 ) ;
return F_6 ( - V_12 ) ;
}
V_4 -> V_7 = V_3 -> V_7 ;
V_4 -> V_13 = V_3 -> V_13 ;
V_4 -> V_14 = V_3 -> V_14 ;
V_4 -> V_15 = V_3 -> V_15 ;
V_4 -> V_16 = V_3 -> V_16 ;
V_4 -> V_17 = V_3 -> V_17 ;
F_5 ( V_6 ) ;
return V_4 ;
}
void F_8 ( struct V_1 * V_18 )
{
F_9 ( V_18 ) ;
}
bool F_10 ( const struct V_1 * V_19 ,
const struct V_1 * V_20 )
{
return V_19 -> V_7 == V_20 -> V_7 &&
V_19 -> V_13 == V_20 -> V_13 &&
V_19 -> V_14 == V_20 -> V_14 &&
V_19 -> V_15 == V_20 -> V_15 &&
V_19 -> V_17 == V_20 -> V_17 ;
}
void * F_11 ( struct V_1 * V_21 ,
struct V_22 * V_23 ,
int V_24 )
{
struct V_1 * V_3 ;
struct V_5 V_6 ;
V_6 = F_2 ( V_24 ) ;
V_3 = F_3 ( V_6 ) ;
if ( F_4 ( V_3 ) )
return V_3 ;
if ( F_10 ( V_21 -> V_4 , V_3 ) )
V_3 = F_12 ( V_3 , false ) ;
else
V_3 = F_6 ( - V_10 ) ;
F_5 ( V_6 ) ;
return V_3 ;
}
void F_13 ( void * V_25 )
{
F_14 ( V_25 ) ;
}
T_1 F_15 ( void * V_25 )
{
return ( (struct V_1 * ) V_25 ) -> V_26 ;
}
