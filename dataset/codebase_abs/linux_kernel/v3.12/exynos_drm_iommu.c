int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_8 * V_9 = V_2 -> V_9 ;
if ( ! V_6 -> V_10 )
V_6 -> V_10 = V_11 ;
if ( ! V_6 -> V_12 )
V_6 -> V_12 = V_13 ;
if ( ! V_6 -> V_14 )
V_6 -> V_14 = V_15 ;
V_4 = F_2 ( & V_16 , V_6 -> V_10 ,
V_6 -> V_12 ,
V_6 -> V_14 ) ;
if ( F_3 ( V_4 ) )
return F_4 ( V_4 ) ;
V_9 -> V_17 = F_5 ( V_9 , sizeof( * V_9 -> V_17 ) ,
V_18 ) ;
if ( ! V_9 -> V_17 )
goto error;
F_6 ( V_9 , 0xffffffffu ) ;
V_9 -> V_19 . V_4 = V_4 ;
return 0 ;
error:
F_7 ( V_4 ) ;
return - V_20 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
F_7 ( V_9 -> V_19 . V_4 ) ;
}
int F_9 ( struct V_1 * V_2 ,
struct V_8 * V_21 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
int V_22 ;
if ( ! V_9 -> V_19 . V_4 ) {
F_10 ( L_1 ) ;
return - V_23 ;
}
V_21 -> V_17 = F_5 ( V_21 ,
sizeof( * V_21 -> V_17 ) ,
V_18 ) ;
if ( ! V_21 -> V_17 )
return - V_20 ;
F_6 ( V_21 , 0xffffffffu ) ;
V_22 = F_11 ( V_21 , V_9 -> V_19 . V_4 ) ;
if ( V_22 < 0 ) {
F_12 ( L_2 ) ;
return V_22 ;
}
if ( ! V_9 -> V_19 . V_24 )
V_9 -> V_19 . V_24 = V_21 -> V_19 . V_24 ;
return 0 ;
}
void F_13 ( struct V_1 * V_2 ,
struct V_8 * V_21 )
{
struct V_8 * V_9 = V_2 -> V_9 ;
struct V_3 * V_4 = V_9 -> V_19 . V_4 ;
if ( ! V_4 || ! V_4 -> V_25 )
return;
F_14 ( V_4 -> V_25 , V_21 ) ;
F_8 ( V_2 ) ;
}
