static void F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 ) ;
}
static void
F_4 ( struct V_6 * V_7 )
{
struct V_8 * V_9 = V_7 -> V_9 ;
struct V_1 * V_2 = V_9 -> V_2 ;
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_5 ( V_2 , V_9 ) ;
F_6 ( V_2 , V_9 , 0 ) ;
F_7 ( V_2 , V_9 ) ;
V_9 -> V_10 = false ;
F_8 ( V_2 , V_9 ) ;
F_9 ( V_2 , V_9 ) ;
F_10 ( V_9 ) ;
F_11 ( & V_4 -> V_11 ) ;
F_12 ( V_7 ) ;
}
static void
F_13 ( struct V_12 * V_13 )
{
struct V_6 * V_7 = F_14 ( V_13 , struct V_6 , V_13 ) ;
F_4 ( V_7 ) ;
}
static struct V_6 * F_15 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_16 ( sizeof( * V_7 ) , V_14 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_2 = V_9 -> V_2 ;
V_7 -> V_9 = V_9 ;
return V_7 ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_8 * V_9 ,
bool V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_16 ;
int V_17 ;
T_1 V_18 = 0 ;
struct V_6 * V_7 ;
struct V_19 * V_20 ;
struct V_21 * V_22 ;
V_7 = F_15 ( V_9 ) ;
if ( ! V_7 )
return - V_23 ;
if ( V_15 ) {
V_16 = F_18 ( & V_4 -> V_11 ) ;
if ( V_16 ) {
F_12 ( V_7 ) ;
return - V_24 ;
}
} else {
V_16 = F_19 ( & V_4 -> V_11 ) ;
if ( V_16 ) {
F_12 ( V_7 ) ;
return V_16 ;
}
}
V_16 = F_20 ( V_2 , V_9 ) ;
if ( V_16 ) {
F_12 ( V_7 ) ;
F_11 ( & V_4 -> V_11 ) ;
return V_16 ;
}
F_21 (state, plane, new_state, i) {
if ( ( V_20 -> V_9 -> V_25 != V_22 -> V_25 ) && V_22 -> V_25 ) {
struct V_26 * V_27 =
F_22 ( V_22 -> V_25 , 0 ) ;
struct V_28 * V_29 = F_23 ( & V_27 -> V_30 ) ;
V_18 = F_24 ( V_29 -> V_31 , V_18 ) ;
}
}
F_25 ( V_9 , true ) ;
if ( V_15 ) {
F_26 ( V_2 , & V_7 -> V_13 , V_18 ,
F_13 ) ;
} else {
F_27 ( V_2 , V_18 , ~ 0ull , false ) ;
F_4 ( V_7 ) ;
}
return 0 ;
}
int F_28 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_16 ;
F_29 ( & V_4 -> V_11 , 1 ) ;
V_16 = F_30 ( V_2 , V_2 -> V_32 . V_33 ) ;
if ( V_16 < 0 ) {
F_31 ( V_2 -> V_2 , L_1 ) ;
return V_16 ;
}
V_2 -> V_32 . V_34 = 2048 ;
V_2 -> V_32 . V_35 = 2048 ;
V_2 -> V_32 . V_36 = & V_37 ;
V_2 -> V_32 . V_38 = 24 ;
V_2 -> V_32 . V_39 = true ;
F_32 ( V_2 ) ;
V_4 -> V_5 = F_33 ( V_2 , 32 ,
V_2 -> V_32 . V_33 ,
V_2 -> V_32 . V_40 ) ;
if ( F_34 ( V_4 -> V_5 ) )
V_4 -> V_5 = NULL ;
F_35 ( V_2 ) ;
return 0 ;
}
