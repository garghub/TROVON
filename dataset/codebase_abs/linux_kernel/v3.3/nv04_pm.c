int
F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
int V_5 ;
V_5 = F_2 ( V_2 , V_6 ) ;
if ( V_5 < 0 )
return V_5 ;
V_4 -> V_7 = V_5 ;
V_5 = F_2 ( V_2 , V_8 ) ;
if ( V_5 < 0 )
return V_5 ;
V_4 -> V_9 = V_5 ;
return 0 ;
}
static int
F_3 ( struct V_1 * V_2 , T_1 V_10 , int V_11 , struct V_12 * V_13 )
{
int V_5 ;
V_5 = F_4 ( V_2 , V_10 , & V_13 -> V_14 ) ;
if ( V_5 )
return V_5 ;
V_5 = F_5 ( V_2 , & V_13 -> V_14 , V_11 , & V_13 -> V_15 ) ;
if ( ! V_5 )
return - V_16 ;
return 0 ;
}
void *
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_17 * V_18 ;
int V_5 ;
V_18 = F_7 ( sizeof( * V_18 ) , V_19 ) ;
if ( ! V_18 )
return F_8 ( - V_20 ) ;
V_5 = F_3 ( V_2 , V_6 , V_4 -> V_7 , & V_18 -> V_7 ) ;
if ( V_5 )
goto error;
if ( V_4 -> V_9 ) {
V_5 = F_3 ( V_2 , V_8 , V_4 -> V_9 , & V_18 -> V_9 ) ;
if ( V_5 )
goto error;
}
return V_18 ;
error:
F_9 ( V_18 ) ;
return F_8 ( V_5 ) ;
}
static void
F_10 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_21 * V_22 = V_2 -> V_23 ;
T_1 V_24 = V_13 -> V_14 . V_24 ;
if ( V_22 -> V_25 >= V_26 )
V_24 += 4 ;
F_11 ( V_2 , V_24 , & V_13 -> V_15 ) ;
}
int
F_12 ( struct V_1 * V_2 , void * V_27 )
{
struct V_21 * V_22 = V_2 -> V_23 ;
struct V_28 * V_29 = & V_22 -> V_30 . V_31 ;
struct V_17 * V_32 = V_27 ;
F_10 ( V_2 , & V_32 -> V_7 ) ;
if ( V_32 -> V_9 . V_14 . V_24 ) {
F_10 ( V_2 , & V_32 -> V_9 ) ;
if ( V_22 -> V_25 < V_33 ) {
if ( V_22 -> V_25 == V_34 )
F_13 ( V_2 , 0x1002c4 , 0 , 1 << 20 ) ;
F_13 ( V_2 , 0x1002c0 , 0 , 1 << 8 ) ;
}
}
V_29 -> V_35 ( V_2 ) ;
F_9 ( V_32 ) ;
return 0 ;
}
