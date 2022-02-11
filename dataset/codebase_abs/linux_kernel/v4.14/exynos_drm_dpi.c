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
F_17 ( V_7 , V_4 ) ;
return 0 ;
}
static void F_18 ( struct V_2 * V_4 ,
struct V_13 * V_14 ,
struct V_13 * V_26 )
{
}
static void F_19 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
if ( V_9 -> V_10 ) {
F_20 ( V_9 -> V_10 ) ;
F_21 ( V_9 -> V_10 ) ;
}
}
static void F_22 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
if ( V_9 -> V_10 ) {
F_23 ( V_9 -> V_10 ) ;
F_24 ( V_9 -> V_10 ) ;
}
}
static int F_25 ( struct V_1 * V_9 )
{
struct V_27 * V_15 = V_9 -> V_15 ;
struct V_28 * V_29 = V_15 -> V_30 ;
struct V_28 * V_31 ;
V_9 -> V_32 = F_26 ( V_29 , V_33 , 0 ) ;
V_31 = F_27 ( V_29 , L_3 ) ;
if ( V_31 ) {
struct V_34 * V_12 ;
int V_20 ;
F_28 ( V_31 ) ;
V_12 = F_29 ( V_15 , sizeof( * V_9 -> V_12 ) , V_35 ) ;
if ( ! V_12 )
return - V_36 ;
V_20 = F_30 ( V_29 , V_12 , 0 ) ;
if ( V_20 < 0 ) {
F_31 ( V_15 , V_12 ) ;
return V_20 ;
}
V_9 -> V_12 = V_12 ;
return 0 ;
}
if ( ! V_9 -> V_32 )
return - V_37 ;
return 0 ;
}
int F_32 ( struct V_38 * V_15 , struct V_2 * V_4 )
{
int V_20 ;
F_33 ( V_15 , V_4 , & V_39 ,
V_40 , NULL ) ;
F_34 ( V_4 , & V_41 ) ;
V_20 = F_35 ( V_4 , V_42 ) ;
if ( V_20 < 0 )
return V_20 ;
V_20 = F_14 ( V_4 ) ;
if ( V_20 ) {
F_11 ( L_4 , V_20 ) ;
F_36 ( V_4 ) ;
return V_20 ;
}
return 0 ;
}
struct V_2 * F_37 ( struct V_27 * V_15 )
{
struct V_1 * V_9 ;
int V_20 ;
V_9 = F_29 ( V_15 , sizeof( * V_9 ) , V_35 ) ;
if ( ! V_9 )
return F_38 ( - V_36 ) ;
V_9 -> V_15 = V_15 ;
V_20 = F_25 ( V_9 ) ;
if ( V_20 < 0 ) {
F_31 ( V_15 , V_9 ) ;
return NULL ;
}
if ( V_9 -> V_32 ) {
V_9 -> V_10 = F_39 ( V_9 -> V_32 ) ;
if ( ! V_9 -> V_10 )
return F_38 ( - V_43 ) ;
}
return & V_9 -> V_4 ;
}
int F_40 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
F_22 ( & V_9 -> V_4 ) ;
if ( V_9 -> V_10 )
F_41 ( V_9 -> V_10 ) ;
return 0 ;
}
