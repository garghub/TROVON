int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = NULL ;
struct V_5 * V_6 = V_2 -> V_7 ;
if ( ! V_6 -> V_8 )
V_6 -> V_8 = V_9 ;
if ( ! V_6 -> V_10 )
V_6 -> V_10 = V_11 ;
V_4 = F_2 ( & V_12 , V_6 -> V_8 ,
V_6 -> V_10 ) ;
if ( F_3 ( V_4 ) )
return F_4 ( V_4 ) ;
V_6 -> V_4 = V_4 ;
return 0 ;
}
void F_5 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
F_6 ( V_6 -> V_4 ) ;
}
int F_7 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
int V_15 ;
if ( ! V_6 -> V_4 )
return 0 ;
V_14 -> V_16 = F_8 ( V_14 ,
sizeof( * V_14 -> V_16 ) ,
V_17 ) ;
if ( ! V_14 -> V_16 )
return - V_18 ;
F_9 ( V_14 , 0xffffffffu ) ;
if ( V_14 -> V_19 . V_4 )
F_10 ( V_14 ) ;
V_15 = F_11 ( V_14 , V_6 -> V_4 ) ;
if ( V_15 < 0 ) {
F_12 ( L_1 ) ;
return V_15 ;
}
return 0 ;
}
void F_13 ( struct V_1 * V_2 ,
struct V_13 * V_14 )
{
struct V_5 * V_6 = V_2 -> V_7 ;
struct V_3 * V_4 = V_6 -> V_4 ;
if ( ! V_4 || ! V_4 -> V_20 )
return;
F_10 ( V_14 ) ;
}
