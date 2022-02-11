static void * F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
struct V_5 * V_6 = & V_2 -> V_6 ;
V_4 = F_2 ( V_6 , sizeof( * V_4 ) , V_7 ) ;
if ( ! V_4 )
return F_3 ( - V_8 ) ;
V_4 -> V_9 = F_4 ( V_6 -> V_10 ) ;
V_4 -> V_11 = F_5 ( V_6 , L_1 ) ;
if ( F_6 ( V_4 -> V_11 ) ) {
F_7 ( V_6 , L_2 ) ;
return V_4 -> V_11 ;
}
V_4 -> V_12 = F_8 ( V_6 , L_3 ) ;
if ( F_6 ( V_4 -> V_12 ) ) {
if ( F_9 ( V_4 -> V_12 ) == - V_13 )
return F_3 ( - V_13 ) ;
F_10 ( V_6 , L_4 ) ;
V_4 -> V_12 = NULL ;
}
return V_4 ;
}
static int F_11 ( struct V_1 * V_2 , void * V_14 )
{
struct V_3 * V_4 = V_14 ;
int V_15 ;
if ( V_4 -> V_12 ) {
V_15 = F_12 ( V_4 -> V_12 ) ;
if ( V_15 )
return V_15 ;
}
if ( V_4 -> V_9 == V_16 ) {
F_13 ( V_4 -> V_11 , V_17 ) ;
F_14 ( V_4 -> V_11 ) ;
V_4 -> V_18 = 1 ;
} else {
F_13 ( V_4 -> V_11 , V_19 ) ;
F_15 ( V_4 -> V_11 ) ;
}
return 0 ;
}
static void F_16 ( struct V_1 * V_2 , void * V_14 )
{
struct V_3 * V_4 = V_14 ;
if ( V_4 -> V_18 ) {
F_17 ( V_4 -> V_11 ) ;
V_4 -> V_18 = 0 ;
}
F_18 ( V_4 -> V_11 ) ;
if ( V_4 -> V_12 )
F_19 ( V_4 -> V_12 ) ;
}
static void F_20 ( void * V_14 , unsigned int V_20 )
{
struct V_3 * V_4 = V_14 ;
if ( V_4 -> V_9 != V_21 )
return;
if ( V_4 -> V_18 ) {
F_17 ( V_4 -> V_11 ) ;
V_4 -> V_18 = 0 ;
}
F_18 ( V_4 -> V_11 ) ;
if ( V_20 == 1000 ) {
F_13 ( V_4 -> V_11 , V_17 ) ;
F_14 ( V_4 -> V_11 ) ;
V_4 -> V_18 = 1 ;
} else {
F_13 ( V_4 -> V_11 , V_19 ) ;
F_15 ( V_4 -> V_11 ) ;
}
}
