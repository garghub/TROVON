static int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_3 ( V_2 -> V_6 , V_5 -> V_7 , & V_3 ) ;
return ( V_3 & F_4 ( V_5 -> V_8 ) ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
int V_9 = 0 ;
struct V_4 * V_5 = F_2 ( V_2 ) ;
V_9 = F_6 ( V_2 -> V_6 , V_5 -> V_10 ,
F_4 ( V_5 -> V_8 ) ) ;
return V_9 ;
}
static int F_7 ( struct V_11 * V_12 )
{
unsigned int V_13 ;
struct V_4 * V_5 ;
struct V_14 * V_15 ;
struct V_16 V_17 = { } ;
struct V_1 * V_2 ;
V_15 = F_8 ( V_12 -> V_18 . V_19 ) ;
if ( ! V_15 ) {
F_9 ( & V_12 -> V_18 , L_1 ) ;
return - V_20 ;
}
V_5 = F_10 ( & V_12 -> V_18 , sizeof( * V_5 ) , V_21 ) ;
if ( ! V_5 )
return - V_22 ;
F_11 ( V_12 , V_5 ) ;
V_17 . V_18 = V_12 -> V_18 . V_19 ;
V_17 . V_6 = V_15 -> V_6 ;
V_17 . V_23 = V_5 ;
for ( V_13 = 0 ; V_13 < F_12 ( V_24 ) ; V_13 ++ ) {
V_2 = F_13 ( & V_12 -> V_18 ,
& V_24 [ V_13 ] . V_25 ,
& V_17 ) ;
if ( F_14 ( V_2 ) ) {
F_9 ( & V_12 -> V_18 , L_2 ,
V_5 -> V_25 . V_26 ) ;
return F_15 ( V_2 ) ;
}
}
return 0 ;
}
