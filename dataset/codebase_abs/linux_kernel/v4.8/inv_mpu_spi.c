static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_5 = 0 ;
V_5 = F_3 ( V_4 , true ) ;
if ( V_5 )
return V_5 ;
V_5 = F_4 ( V_4 -> V_6 , V_7 ,
V_8 ) ;
if ( V_5 ) {
F_3 ( V_4 , false ) ;
return V_5 ;
}
return F_3 ( V_4 , false ) ;
}
static int F_5 ( struct V_9 * V_10 )
{
struct V_11 * V_11 ;
const struct V_12 * V_13 ;
const struct V_14 * V_15 ;
const char * V_16 = NULL ;
enum V_17 V_18 ;
if ( ( V_13 = F_6 ( V_10 ) ) ) {
V_18 = (enum V_17 ) V_13 -> V_19 ;
V_16 = V_13 -> V_16 ;
} else if ( ( V_15 = F_7 ( V_10 -> V_20 . V_21 -> V_22 , & V_10 -> V_20 ) ) ) {
V_18 = (enum V_17 ) V_15 -> V_19 ;
} else {
return - V_23 ;
}
V_11 = F_8 ( V_10 , & V_24 ) ;
if ( F_9 ( V_11 ) ) {
F_10 ( & V_10 -> V_20 , L_1 ,
( int ) F_11 ( V_11 ) ) ;
return F_11 ( V_11 ) ;
}
return F_12 ( V_11 , V_10 -> V_25 , V_16 ,
F_1 , V_18 ) ;
}
static int F_13 ( struct V_9 * V_10 )
{
return F_14 ( & V_10 -> V_20 ) ;
}
