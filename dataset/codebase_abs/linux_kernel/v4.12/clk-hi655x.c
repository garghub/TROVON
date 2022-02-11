static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
return 32768 ;
}
static int F_2 ( struct V_1 * V_2 , bool V_4 )
{
struct V_5 * V_5 =
F_3 ( V_2 , struct V_5 , V_1 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
return F_4 ( V_7 -> V_8 , V_9 ,
V_10 , V_4 ? V_10 : 0 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
return F_2 ( V_2 , true ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
F_2 ( V_2 , false ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_5 * V_5 =
F_3 ( V_2 , struct V_5 , V_1 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
int V_11 ;
T_1 V_12 ;
V_11 = F_8 ( V_7 -> V_8 , V_9 , & V_12 ) ;
if ( V_11 < 0 )
return V_11 ;
return V_12 & V_9 ;
}
static int F_9 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_17 . V_16 ;
struct V_6 * V_7 = F_10 ( V_16 ) ;
struct V_5 * V_5 ;
const char * V_18 = L_1 ;
struct V_19 V_20 = {
. V_21 = V_18 ,
. V_22 = & V_23
} ;
int V_11 ;
V_5 = F_11 ( & V_14 -> V_17 , sizeof( * V_5 ) , V_24 ) ;
if ( ! V_5 )
return - V_25 ;
F_12 ( V_16 -> V_26 , L_2 ,
0 , & V_18 ) ;
V_5 -> V_1 . V_20 = & V_20 ;
V_5 -> V_7 = V_7 ;
F_13 ( V_14 , V_5 ) ;
V_11 = F_14 ( & V_14 -> V_17 , & V_5 -> V_1 ) ;
if ( V_11 )
return V_11 ;
return F_15 ( V_16 -> V_26 , V_27 ,
& V_5 -> V_1 ) ;
}
