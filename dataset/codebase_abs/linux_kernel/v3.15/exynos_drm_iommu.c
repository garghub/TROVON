int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_9 ;
if ( ! V_6 -> V_10 )
V_6 -> V_10 = V_11 ;
if ( ! V_6 -> V_12 )
V_6 -> V_12 = V_13 ;
V_4 = F_2 ( & V_14 , V_6 -> V_10 ,
V_6 -> V_12 ) ;
if ( F_3 ( V_4 ) )
return F_4 ( V_4 ) ;
V_9 -> V_15 = F_5 ( V_9 , sizeof( * V_9 -> V_15 ) ,
V_16 ) ;
if ( ! V_9 -> V_15 )
goto error;
F_6 ( V_9 , 0xffffffffu ) ;
V_9 -> V_17 . V_4 = V_4 ;
return 0 ;
error:
F_7 ( V_4 ) ;
return - V_18 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
F_7 ( V_9 -> V_17 . V_4 ) ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_8 * V_19 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_20 ;
if ( ! V_9 -> V_17 . V_4 ) {
F_10 ( L_1 ) ;
return - V_21 ;
}
V_19 -> V_15 = F_5 ( V_19 ,
sizeof( * V_19 -> V_15 ) ,
V_16 ) ;
if ( ! V_19 -> V_15 )
return - V_18 ;
F_6 ( V_19 , 0xffffffffu ) ;
V_20 = F_11 ( V_19 , V_9 -> V_17 . V_4 ) ;
if ( V_20 < 0 ) {
F_12 ( L_2 ) ;
return V_20 ;
}
if ( ! V_9 -> V_17 . V_22 )
V_9 -> V_17 . V_22 = V_19 -> V_17 . V_22 ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 ,
struct V_8 * V_19 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_3 * V_4 = V_9 -> V_17 . V_4 ;
if ( ! V_4 || ! V_4 -> V_23 )
return;
F_14 ( V_4 -> V_23 , V_19 ) ;
F_8 ( V_2 ) ;
}
