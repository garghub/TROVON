static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static enum V_5
F_3 ( struct V_6 * V_7 , bool V_8 )
{
struct V_1 * V_9 = F_4 ( V_7 ) ;
if ( V_9 -> V_10 && ! V_9 -> V_10 -> V_7 )
F_5 ( V_9 -> V_10 , & V_9 -> V_7 ) ;
return V_11 ;
}
static void F_6 ( struct V_6 * V_7 )
{
F_7 ( V_7 ) ;
F_8 ( V_7 ) ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_9 = F_4 ( V_7 ) ;
if ( V_9 -> V_12 ) {
struct V_13 * V_14 ;
V_14 = F_10 ( V_7 -> V_15 ) ;
if ( ! V_14 ) {
F_11 ( L_1 ) ;
return 0 ;
}
F_12 ( V_9 -> V_12 , V_14 ) ;
V_14 -> type = V_16 | V_17 ;
F_13 ( V_7 , V_14 ) ;
return 1 ;
}
if ( V_9 -> V_10 )
return V_9 -> V_10 -> V_18 -> V_19 ( V_9 -> V_10 ) ;
return 0 ;
}
static int F_14 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_6 * V_7 = & V_9 -> V_7 ;
int V_20 ;
V_7 -> V_21 = V_22 ;
V_20 = F_15 ( V_4 -> V_15 , V_7 ,
& V_23 ,
V_24 ) ;
if ( V_20 ) {
F_11 ( L_2 ) ;
return V_20 ;
}
F_16 ( V_7 , & V_25 ) ;
F_17 ( V_7 ) ;
F_18 ( V_7 , V_4 ) ;
return 0 ;
}
static void F_19 ( struct V_2 * V_4 ,
struct V_13 * V_14 ,
struct V_13 * V_26 )
{
}
static void F_20 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
if ( V_9 -> V_10 ) {
F_21 ( V_9 -> V_10 ) ;
F_22 ( V_9 -> V_10 ) ;
}
}
static void F_23 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
if ( V_9 -> V_10 ) {
F_24 ( V_9 -> V_10 ) ;
F_25 ( V_9 -> V_10 ) ;
}
}
static struct V_27 * F_26 ( struct V_28 * V_15 )
{
struct V_27 * V_29 , * V_30 ;
V_30 = F_27 ( V_15 -> V_31 , V_32 , 0 ) ;
if ( ! V_30 )
return NULL ;
V_29 = F_28 ( V_30 ) ;
F_29 ( V_30 ) ;
return V_29 ;
}
static int F_30 ( struct V_1 * V_9 )
{
struct V_28 * V_15 = V_9 -> V_15 ;
struct V_27 * V_33 = V_15 -> V_31 ;
struct V_27 * V_29 ;
V_9 -> V_34 = F_26 ( V_15 ) ;
V_29 = F_31 ( V_33 , L_3 ) ;
if ( V_29 ) {
struct V_35 * V_12 ;
int V_20 ;
F_29 ( V_29 ) ;
V_12 = F_32 ( V_15 , sizeof( * V_9 -> V_12 ) , V_36 ) ;
if ( ! V_12 )
return - V_37 ;
V_20 = F_33 ( V_33 , V_12 , 0 ) ;
if ( V_20 < 0 ) {
F_34 ( V_15 , V_12 ) ;
return V_20 ;
}
V_9 -> V_12 = V_12 ;
return 0 ;
}
if ( ! V_9 -> V_34 )
return - V_38 ;
return 0 ;
}
int F_35 ( struct V_39 * V_15 , struct V_2 * V_4 )
{
int V_20 ;
V_20 = F_36 ( V_15 , V_40 ) ;
if ( V_20 < 0 )
return V_20 ;
V_4 -> V_41 = 1 << V_20 ;
F_37 ( L_4 , V_4 -> V_41 ) ;
F_38 ( V_15 , V_4 , & V_42 ,
V_43 , NULL ) ;
F_39 ( V_4 , & V_44 ) ;
V_20 = F_14 ( V_4 ) ;
if ( V_20 ) {
F_11 ( L_5 , V_20 ) ;
F_40 ( V_4 ) ;
return V_20 ;
}
return 0 ;
}
struct V_2 * F_41 ( struct V_28 * V_15 )
{
struct V_1 * V_9 ;
int V_20 ;
V_9 = F_32 ( V_15 , sizeof( * V_9 ) , V_36 ) ;
if ( ! V_9 )
return F_42 ( - V_37 ) ;
V_9 -> V_15 = V_15 ;
V_20 = F_30 ( V_9 ) ;
if ( V_20 < 0 ) {
F_34 ( V_15 , V_9 ) ;
return NULL ;
}
if ( V_9 -> V_34 ) {
V_9 -> V_10 = F_43 ( V_9 -> V_34 ) ;
if ( ! V_9 -> V_10 )
return F_42 ( - V_45 ) ;
}
return & V_9 -> V_4 ;
}
int F_44 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
F_23 ( & V_9 -> V_4 ) ;
if ( V_9 -> V_10 )
F_45 ( V_9 -> V_10 ) ;
return 0 ;
}
