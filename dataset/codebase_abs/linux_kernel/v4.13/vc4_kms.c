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
F_5 ( V_2 , V_9 , false ) ;
F_6 ( V_9 ) ;
F_7 ( V_2 , V_9 ) ;
F_8 ( V_2 , V_9 , 0 ) ;
F_9 ( V_2 , V_9 ) ;
V_9 -> V_10 = false ;
F_10 ( V_9 ) ;
F_11 ( V_2 , V_9 ) ;
F_12 ( V_2 , V_9 ) ;
F_13 ( V_9 ) ;
F_14 ( V_9 ) ;
F_15 ( & V_4 -> V_11 ) ;
F_16 ( V_7 ) ;
}
static void
F_17 ( struct V_12 * V_13 )
{
struct V_6 * V_7 = F_18 ( V_13 , struct V_6 , V_13 ) ;
F_4 ( V_7 ) ;
}
static struct V_6 * F_19 ( struct V_8 * V_9 )
{
struct V_6 * V_7 = F_20 ( sizeof( * V_7 ) , V_14 ) ;
if ( ! V_7 )
return NULL ;
V_7 -> V_2 = V_9 -> V_2 ;
V_7 -> V_9 = V_9 ;
return V_7 ;
}
static int F_21 ( struct V_1 * V_2 ,
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
V_7 = F_19 ( V_9 ) ;
if ( ! V_7 )
return - V_23 ;
V_16 = F_22 ( V_9 , V_15 ) ;
if ( V_16 )
return V_16 ;
V_16 = F_23 ( & V_4 -> V_11 ) ;
if ( V_16 ) {
F_16 ( V_7 ) ;
return V_16 ;
}
V_16 = F_24 ( V_2 , V_9 ) ;
if ( V_16 ) {
F_16 ( V_7 ) ;
F_15 ( & V_4 -> V_11 ) ;
return V_16 ;
}
F_25 (state, plane, new_state, i) {
if ( ( V_20 -> V_9 -> V_24 != V_22 -> V_24 ) && V_22 -> V_24 ) {
struct V_25 * V_26 =
F_26 ( V_22 -> V_24 , 0 ) ;
struct V_27 * V_28 = F_27 ( & V_26 -> V_29 ) ;
V_18 = F_28 ( V_28 -> V_30 , V_18 ) ;
}
}
F_29 ( V_9 , true ) ;
F_30 ( V_9 ) ;
if ( V_15 ) {
F_31 ( V_2 , & V_7 -> V_13 , V_18 ,
F_17 ) ;
} else {
F_32 ( V_2 , V_18 , ~ 0ull , false ) ;
F_4 ( V_7 ) ;
}
return 0 ;
}
static struct V_31 * F_33 ( struct V_1 * V_2 ,
struct V_32 * V_33 ,
const struct V_34 * V_35 )
{
struct V_34 V_36 ;
if ( ! ( V_35 -> V_37 & V_38 ) ) {
struct V_39 * V_40 ;
struct V_27 * V_28 ;
V_40 = F_34 ( V_33 ,
V_35 -> V_41 [ 0 ] ) ;
if ( ! V_40 ) {
F_35 ( L_1 ,
V_35 -> V_41 [ 0 ] ) ;
return F_36 ( - V_42 ) ;
}
V_28 = F_27 ( V_40 ) ;
V_36 = * V_35 ;
if ( V_28 -> V_43 ) {
V_36 . V_44 [ 0 ] =
V_45 ;
} else {
V_36 . V_44 [ 0 ] = V_46 ;
}
F_37 ( V_40 ) ;
V_35 = & V_36 ;
}
return F_38 ( V_2 , V_33 , V_35 ) ;
}
int F_39 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_16 ;
F_40 ( & V_4 -> V_11 , 1 ) ;
V_16 = F_41 ( V_2 , V_2 -> V_47 . V_48 ) ;
if ( V_16 < 0 ) {
F_42 ( V_2 -> V_2 , L_2 ) ;
return V_16 ;
}
V_2 -> V_47 . V_49 = 2048 ;
V_2 -> V_47 . V_50 = 2048 ;
V_2 -> V_47 . V_51 = & V_52 ;
V_2 -> V_47 . V_53 = 24 ;
V_2 -> V_47 . V_54 = true ;
F_43 ( V_2 ) ;
if ( V_2 -> V_47 . V_55 ) {
V_4 -> V_5 = F_44 ( V_2 , 32 ,
V_2 -> V_47 . V_55 ) ;
if ( F_45 ( V_4 -> V_5 ) )
V_4 -> V_5 = NULL ;
}
F_46 ( V_2 ) ;
return 0 ;
}
