static void F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned char V_7 [] = V_8 ;
V_7 [ 4 ] = V_4 ;
F_3 ( V_6 -> V_9 , V_7 , sizeof( V_7 ) ) ;
V_6 -> V_10 . V_11 = V_4 ;
}
static int T_1 F_4 ( struct V_12 * V_13 )
{
struct V_14 * V_9 = F_5 ( V_13 -> V_15 . V_16 ) ;
struct V_5 * V_6 ;
int V_17 = 0 ;
V_6 = F_6 ( & V_13 -> V_15 , sizeof( * V_6 ) , V_18 ) ;
if ( V_6 == NULL )
return - V_19 ;
V_6 -> V_10 . V_20 = V_21 ;
V_6 -> V_10 . V_22 = F_1 ;
V_6 -> V_10 . V_23 = L_1 ;
V_6 -> V_10 . V_24 |= V_25 ;
V_6 -> V_9 = V_9 ;
F_7 ( V_13 , V_6 ) ;
V_17 = F_8 ( & V_13 -> V_15 , & V_6 -> V_10 ) ;
if ( V_17 < 0 )
return V_17 ;
V_6 -> V_10 . V_11 = 0 ;
return 0 ;
}
static int T_2 F_9 ( struct V_12 * V_13 )
{
struct V_5 * V_6 = F_10 ( V_13 ) ;
F_11 ( & V_6 -> V_10 ) ;
return 0 ;
}
