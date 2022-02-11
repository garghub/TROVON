static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
int V_7 ;
if ( V_3 ) {
V_5 -> V_8 ( 1 ) ;
V_7 = F_2 ( V_5 -> V_9 , V_10 , sizeof( V_10 ) ) ;
if ( V_7 < 0 )
F_3 ( V_2 -> V_11 , L_1 , V_7 ) ;
} else {
V_7 = F_2 ( V_5 -> V_9 , V_12 , sizeof( V_12 ) ) ;
if ( V_7 < 0 )
F_3 ( V_2 -> V_11 , L_2 , V_7 ) ;
V_5 -> V_8 ( 0 ) ;
}
}
static int F_4 ( struct V_1 * V_2 ,
struct V_13 * * V_14 )
{
* V_14 = V_15 ;
return 1 ;
}
static int F_5 ( struct V_16 * V_9 )
{
struct V_17 * V_18 ;
int V_7 ;
struct V_4 * V_6 ;
V_18 = V_9 -> V_11 . V_19 ;
if ( V_18 == NULL ) {
F_6 ( & V_9 -> V_11 , L_3 , V_20 ) ;
return - V_21 ;
}
V_9 -> V_22 = 16 ;
V_7 = F_7 ( V_9 ) ;
if ( V_7 < 0 ) {
F_6 ( & V_9 -> V_11 , L_4 , V_7 ) ;
return V_7 ;
}
V_6 = F_8 ( sizeof( * V_6 ) , V_23 ) ;
if ( V_6 == NULL )
return - V_24 ;
V_6 -> V_9 = V_9 ;
V_6 -> V_8 = V_18 -> V_25 ;
V_26 . V_6 = V_6 ;
V_26 . V_27 = V_18 -> V_27 ;
V_26 . V_11 = & V_9 -> V_11 ;
F_9 ( & V_26 ) ;
return 0 ;
}
