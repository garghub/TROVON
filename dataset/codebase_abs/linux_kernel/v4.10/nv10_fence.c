int
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
int V_6 = F_2 ( V_4 , 2 ) ;
if ( V_6 == 0 ) {
F_3 ( V_4 , 0 , V_7 , 1 ) ;
F_4 ( V_4 , V_2 -> V_8 . V_9 ) ;
F_5 ( V_4 ) ;
}
return V_6 ;
}
static int
F_6 ( struct V_1 * V_2 ,
struct V_3 * V_10 , struct V_3 * V_4 )
{
return - V_11 ;
}
T_1
F_7 ( struct V_3 * V_4 )
{
return F_8 ( & V_4 -> V_12 , 0x0048 ) ;
}
void
F_9 ( struct V_3 * V_4 )
{
struct V_13 * V_14 = V_4 -> V_2 ;
F_10 ( & V_14 -> V_8 ) ;
F_11 ( & V_14 -> V_15 ) ;
V_4 -> V_2 = NULL ;
F_12 ( & V_14 -> V_8 ) ;
}
static int
F_13 ( struct V_3 * V_4 )
{
struct V_13 * V_14 ;
V_14 = V_4 -> V_2 = F_14 ( sizeof( * V_14 ) , V_16 ) ;
if ( ! V_14 )
return - V_17 ;
F_15 ( V_4 , & V_14 -> V_8 ) ;
V_14 -> V_8 . V_18 = F_1 ;
V_14 -> V_8 . V_19 = F_7 ;
V_14 -> V_8 . V_20 = F_6 ;
return 0 ;
}
void
F_16 ( struct V_21 * V_22 )
{
struct V_23 * V_24 = V_22 -> V_2 ;
F_17 ( V_24 -> V_25 ) ;
if ( V_24 -> V_25 )
F_18 ( V_24 -> V_25 ) ;
F_19 ( NULL , & V_24 -> V_25 ) ;
V_22 -> V_2 = NULL ;
F_20 ( V_24 ) ;
}
int
F_21 ( struct V_21 * V_22 )
{
struct V_23 * V_24 ;
V_24 = V_22 -> V_2 = F_14 ( sizeof( * V_24 ) , V_16 ) ;
if ( ! V_24 )
return - V_17 ;
V_24 -> V_8 . V_26 = F_16 ;
V_24 -> V_8 . V_27 = F_13 ;
V_24 -> V_8 . V_28 = F_9 ;
V_24 -> V_8 . V_29 = 31 ;
V_24 -> V_8 . V_30 = F_22 ( V_24 -> V_8 . V_29 ) ;
F_23 ( & V_24 -> V_31 ) ;
return 0 ;
}
