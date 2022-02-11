static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_9 ;
struct V_10 * V_11 = V_7 -> V_11 ;
if ( V_11 -> V_12 ) {
F_2 ( V_2 -> V_13 , V_11 -> V_14 , V_15 ,
V_16 ) ;
F_3 ( V_11 -> V_12 ) ;
}
F_4 ( V_11 ) ;
V_7 -> V_11 = NULL ;
}
static int
F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_6 * V_7 = & V_4 -> V_8 . V_9 ;
struct V_10 * V_11 ;
V_11 = F_6 ( sizeof( * V_11 ) , V_17 ) ;
if ( ! V_11 )
return - V_18 ;
V_7 -> V_11 = V_11 ;
V_11 -> V_12 = F_7 ( V_17 | V_19 ) ;
if ( ! V_11 -> V_12 ) {
F_1 ( V_2 ) ;
return - V_18 ;
}
V_11 -> V_14 = F_8 ( V_2 -> V_13 , V_11 -> V_12 , 0 ,
V_15 , V_16 ) ;
if ( F_9 ( V_2 -> V_13 , V_11 -> V_14 ) ) {
F_1 ( V_2 ) ;
return - V_20 ;
}
return 0 ;
}
int
F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_5 ;
struct V_10 * V_11 ;
int V_21 ;
if ( ! V_4 -> V_8 . V_9 . V_11 ) {
V_21 = F_5 ( V_2 ) ;
if ( V_21 )
return V_21 ;
}
V_11 = V_4 -> V_8 . V_9 . V_11 ;
F_11 ( V_2 , 0x100c10 , V_11 -> V_14 >> 8 ) ;
return 0 ;
}
void
F_12 ( struct V_1 * V_2 )
{
F_1 ( V_2 ) ;
}
