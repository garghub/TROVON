int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 = F_2 ( V_4 , 2 ) ;
if ( V_6 == 0 ) {
F_3 ( V_4 , 0 , V_7 , 1 ) ;
F_4 ( V_4 , V_2 -> V_8 ) ;
F_5 ( V_4 ) ;
}
return V_6 ;
}
static int
F_6 ( struct V_1 * V_2 ,
struct V_3 * V_9 , struct V_3 * V_4 )
{
return - V_10 ;
}
T_1
F_7 ( struct V_3 * V_4 )
{
return F_8 ( V_4 -> V_11 , 0x0048 ) ;
}
void
F_9 ( struct V_3 * V_4 )
{
struct V_12 * V_13 = V_4 -> V_2 ;
F_10 ( & V_13 -> V_14 ) ;
V_4 -> V_2 = NULL ;
F_11 ( V_13 ) ;
}
int
F_12 ( struct V_3 * V_4 )
{
struct V_12 * V_13 ;
V_13 = V_4 -> V_2 = F_13 ( sizeof( * V_13 ) , V_15 ) ;
if ( ! V_13 )
return - V_16 ;
F_14 ( & V_13 -> V_14 ) ;
V_13 -> V_14 . V_17 = F_1 ;
V_13 -> V_14 . V_18 = F_7 ;
V_13 -> V_14 . V_19 = F_6 ;
return 0 ;
}
void
F_15 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = V_21 -> V_2 ;
F_16 ( V_23 -> V_24 ) ;
if ( V_23 -> V_24 )
F_17 ( V_23 -> V_24 ) ;
F_18 ( NULL , & V_23 -> V_24 ) ;
V_21 -> V_2 = NULL ;
F_11 ( V_23 ) ;
}
int
F_19 ( struct V_20 * V_21 )
{
struct V_22 * V_23 ;
V_23 = V_21 -> V_2 = F_13 ( sizeof( * V_23 ) , V_15 ) ;
if ( ! V_23 )
return - V_16 ;
V_23 -> V_14 . V_25 = F_15 ;
V_23 -> V_14 . V_26 = F_12 ;
V_23 -> V_14 . V_27 = F_9 ;
F_20 ( & V_23 -> V_28 ) ;
return 0 ;
}
