static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
strncpy ( V_4 -> V_5 , L_1 , sizeof( V_4 -> V_5 ) - 1 ) ;
}
static int F_2 ( struct V_1 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
V_8 -> V_11 = V_10 -> V_12 . V_13 ;
V_8 -> V_14 = V_10 -> V_12 . V_15 ;
return 0 ;
}
static int F_4 ( struct V_1 * V_6 ,
struct V_7 * V_8 )
{
struct V_9 * V_10 = F_3 ( V_6 ) ;
int V_16 ;
if ( V_8 -> V_11 > 0xffff ||
V_8 -> V_14 > 0xffff )
return - V_17 ;
V_16 = F_5 ( V_10 -> V_18 , V_8 -> V_14 ,
V_8 -> V_11 ) ;
if ( V_16 && V_16 != - V_19 ) {
F_6 ( V_10 , L_2 , V_16 ) ;
return V_16 ;
}
V_10 -> V_12 . V_13 = V_8 -> V_11 ;
V_10 -> V_12 . V_15 = V_8 -> V_14 ;
return 0 ;
}
void F_7 ( struct V_1 * V_6 )
{
F_8 ( V_6 , & V_20 ) ;
}
