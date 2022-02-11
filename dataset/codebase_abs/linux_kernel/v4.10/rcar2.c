static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( F_3 ( V_5 ) ) {
struct V_6 * V_6 = F_4 ( & V_2 -> V_7 , L_1 ) ;
if ( F_5 ( V_6 ) )
return F_6 ( V_6 ) ;
V_4 -> V_6 = V_6 ;
return 0 ;
}
if ( F_3 ( V_8 ) ) {
struct V_9 * V_9 = F_7 ( & V_2 -> V_7 , 0 ) ;
if ( F_5 ( V_9 ) )
return F_6 ( V_9 ) ;
V_4 -> V_9 = V_9 ;
return 0 ;
}
return - V_10 ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
if ( V_4 -> V_6 ) {
F_9 ( V_4 -> V_6 ) ;
V_4 -> V_6 = NULL ;
}
if ( V_4 -> V_9 ) {
F_10 ( V_4 -> V_9 ) ;
V_4 -> V_9 = NULL ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
void T_1 * V_11 , int V_12 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_13 = - V_14 ;
if ( V_4 -> V_6 ) {
if ( V_12 ) {
V_13 = F_12 ( V_4 -> V_6 ) ;
if ( ! V_13 )
V_13 = F_13 ( V_4 -> V_6 ) ;
} else {
F_14 ( V_4 -> V_6 ) ;
F_15 ( V_4 -> V_6 ) ;
V_13 = 0 ;
}
}
if ( V_4 -> V_9 ) {
if ( V_12 ) {
V_13 = F_16 ( V_4 -> V_9 ) ;
if ( ! V_13 )
V_13 = F_17 ( V_4 -> V_9 , 0 ) ;
} else {
F_17 ( V_4 -> V_9 , 1 ) ;
F_18 ( V_4 -> V_9 ) ;
V_13 = 0 ;
}
}
return V_13 ;
}
static int F_19 ( struct V_1 * V_2 )
{
return V_15 ;
}
