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
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_16 * V_17 = V_16 ( V_15 ) ;
struct V_18 * V_19 = V_18 ( V_15 ) ;
int V_5 ;
V_5 = F_5 ( V_17 , V_10 , & V_13 -> V_20 ) ;
if ( V_5 )
return V_5 ;
V_5 = V_19 -> V_21 ( V_19 , & V_13 -> V_20 , V_11 , & V_13 -> V_22 ) ;
if ( ! V_5 )
return - V_23 ;
return 0 ;
}
void *
F_6 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
struct V_24 * V_25 ;
int V_5 ;
V_25 = F_7 ( sizeof( * V_25 ) , V_26 ) ;
if ( ! V_25 )
return F_8 ( - V_27 ) ;
V_5 = F_3 ( V_2 , V_6 , V_4 -> V_7 , & V_25 -> V_7 ) ;
if ( V_5 )
goto error;
if ( V_4 -> V_9 ) {
V_5 = F_3 ( V_2 , V_8 , V_4 -> V_9 , & V_25 -> V_9 ) ;
if ( V_5 )
goto error;
}
return V_25 ;
error:
F_9 ( V_25 ) ;
return F_8 ( V_5 ) ;
}
static void
F_10 ( struct V_1 * V_2 , struct V_12 * V_13 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_18 * V_19 = V_18 ( V_15 ) ;
T_1 V_28 = V_13 -> V_20 . V_28 ;
if ( V_15 -> V_29 >= V_30 )
V_28 += 4 ;
V_19 -> V_31 ( V_19 , V_28 , & V_13 -> V_22 ) ;
}
int
F_11 ( struct V_1 * V_2 , void * V_32 )
{
struct V_14 * V_15 = F_4 ( V_2 ) ;
struct V_33 * V_34 = V_33 ( V_15 ) ;
struct V_24 * V_35 = V_32 ;
F_10 ( V_2 , & V_35 -> V_7 ) ;
if ( V_35 -> V_9 . V_20 . V_28 ) {
F_10 ( V_2 , & V_35 -> V_9 ) ;
if ( V_15 -> V_29 < V_36 ) {
if ( V_15 -> V_29 == V_37 )
F_12 ( V_15 , 0x1002c4 , 0 , 1 << 20 ) ;
F_12 ( V_15 , 0x1002c0 , 0 , 1 << 8 ) ;
}
}
F_13 ( V_34 ) -> F_14 ( F_15 ( V_34 ) ) ;
F_9 ( V_35 ) ;
return 0 ;
}
