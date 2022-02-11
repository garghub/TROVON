static inline struct V_1 *
F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static inline struct V_1 *
F_3 ( struct V_4 * V_5 )
{
return F_2 ( V_5 , struct V_1 , V_5 ) ;
}
static int F_4 ( struct V_4 * V_5 )
{
struct V_1 * V_6 = F_3 ( V_5 ) ;
return F_5 ( V_6 -> V_7 ) ;
}
static int F_6 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
struct V_4 * V_5 = & V_6 -> V_5 ;
int V_8 ;
if ( ! V_3 -> V_9 ) {
F_7 ( L_1 ) ;
return - V_10 ;
}
F_8 ( V_5 , & V_11 ) ;
V_8 = F_9 ( V_3 -> V_12 , V_5 , & V_13 ,
V_14 ) ;
if ( V_8 ) {
F_7 ( L_2 ) ;
return V_8 ;
}
F_10 ( & V_6 -> V_5 , V_3 -> V_9 ) ;
V_8 = F_11 ( V_6 -> V_7 , & V_6 -> V_5 ) ;
if ( V_8 < 0 )
return V_8 ;
return 0 ;
}
static void F_12 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_13 ( V_6 -> V_7 ) ;
}
static void F_14 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_15 ( V_6 -> V_7 ) ;
}
static void F_16 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_17 ( V_6 -> V_7 ) ;
}
static void F_18 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_19 ( V_6 -> V_7 ) ;
}
static void F_20 ( struct V_2 * V_3 )
{
struct V_1 * V_6 = F_1 ( V_3 ) ;
F_21 ( V_6 -> V_7 ) ;
}
static int F_22 ( struct V_15 * V_16 )
{
struct V_1 * V_6 ;
struct V_17 * V_18 ;
struct V_17 * V_19 ;
struct V_17 * V_7 ;
V_6 = F_23 ( & V_16 -> V_12 , sizeof( * V_6 ) , V_20 ) ;
if ( ! V_6 )
return - V_21 ;
V_6 -> V_12 = & V_16 -> V_12 ;
F_24 ( V_16 , V_6 ) ;
V_6 -> V_3 . V_22 = & V_23 ;
V_6 -> V_3 . V_24 = V_16 -> V_12 . V_24 ;
V_18 = F_25 ( V_16 -> V_12 . V_24 , 1 ) ;
if ( ! V_18 ) {
F_26 ( & V_16 -> V_12 , L_3 ) ;
return - V_25 ;
}
V_19 = F_27 ( V_18 , L_4 ) ;
F_28 ( V_18 ) ;
if ( ! V_19 ) {
F_26 ( & V_16 -> V_12 , L_5 ) ;
return - V_25 ;
}
V_7 = F_29 ( V_19 ) ;
F_28 ( V_19 ) ;
if ( ! V_7 ) {
F_26 ( & V_16 -> V_12 , L_6 ) ;
return - V_25 ;
}
V_6 -> V_7 = F_30 ( V_7 ) ;
F_28 ( V_7 ) ;
if ( ! V_6 -> V_7 ) {
F_26 ( & V_16 -> V_12 , L_7 ) ;
return - V_26 ;
}
return F_31 ( & V_6 -> V_3 ) ;
}
static int F_32 ( struct V_15 * V_16 )
{
struct V_1 * V_9 = F_33 ( V_16 ) ;
F_34 ( & V_9 -> V_3 ) ;
return 0 ;
}
