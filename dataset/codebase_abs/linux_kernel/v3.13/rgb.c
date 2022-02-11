static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_3 ) ;
}
static void F_3 ( struct V_4 * V_5 ,
const struct V_6 * V_7 ,
unsigned int V_8 )
{
unsigned int V_9 ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
F_4 ( V_5 , V_7 [ V_9 ] . V_10 , V_7 [ V_9 ] . V_11 ) ;
}
static int F_5 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_3 ( V_12 -> V_5 , V_13 , F_6 ( V_13 ) ) ;
return 0 ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
F_3 ( V_12 -> V_5 , V_14 , F_6 ( V_14 ) ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 ,
struct V_15 * V_15 , unsigned long V_16 )
{
struct V_1 * V_12 = F_1 ( V_3 ) ;
return F_9 ( V_15 , V_12 -> V_17 ) ;
}
static int F_10 ( struct V_2 * V_3 ,
struct V_18 * V_19 ,
enum V_20 * V_21 )
{
* V_21 = V_22 ;
return 0 ;
}
int F_11 ( struct V_4 * V_5 )
{
struct V_23 * V_24 ;
struct V_1 * V_12 ;
int V_25 ;
V_24 = F_12 ( V_5 -> V_26 -> V_27 , L_1 ) ;
if ( ! V_24 || ! F_13 ( V_24 ) )
return - V_28 ;
V_12 = F_14 ( V_5 -> V_26 , sizeof( * V_12 ) , V_29 ) ;
if ( ! V_12 )
return - V_30 ;
V_12 -> V_3 . V_26 = V_5 -> V_26 ;
V_12 -> V_3 . V_27 = V_24 ;
V_12 -> V_5 = V_5 ;
V_25 = F_15 ( & V_12 -> V_3 ) ;
if ( V_25 < 0 )
return V_25 ;
V_12 -> V_15 = F_16 ( V_5 -> V_26 , NULL ) ;
if ( F_17 ( V_12 -> V_15 ) ) {
F_18 ( V_5 -> V_26 , L_2 ) ;
return F_19 ( V_12 -> V_15 ) ;
}
V_12 -> V_17 = F_16 ( V_5 -> V_26 , L_3 ) ;
if ( F_17 ( V_12 -> V_17 ) ) {
F_18 ( V_5 -> V_26 , L_4 ) ;
return F_19 ( V_12 -> V_17 ) ;
}
V_25 = F_9 ( V_12 -> V_15 , V_12 -> V_17 ) ;
if ( V_25 < 0 ) {
F_18 ( V_5 -> V_26 , L_5 , V_25 ) ;
return V_25 ;
}
V_5 -> V_12 = & V_12 -> V_3 ;
return 0 ;
}
int F_20 ( struct V_4 * V_5 )
{
int V_25 ;
if ( ! V_5 -> V_12 )
return 0 ;
V_25 = F_21 ( V_5 -> V_12 ) ;
if ( V_25 < 0 )
return V_25 ;
return 0 ;
}
int F_22 ( struct V_31 * V_32 , struct V_4 * V_5 )
{
struct V_1 * V_12 = F_1 ( V_5 -> V_12 ) ;
int V_25 ;
if ( ! V_5 -> V_12 )
return - V_28 ;
V_12 -> V_3 . type = V_33 ;
V_12 -> V_3 . V_34 = & V_35 ;
V_25 = F_23 ( V_5 -> V_36 . V_26 , & V_12 -> V_3 ) ;
if ( V_25 < 0 ) {
F_18 ( V_5 -> V_26 , L_6 , V_25 ) ;
return V_25 ;
}
V_12 -> V_3 . V_37 . V_38 = 1 << V_5 -> V_39 ;
return 0 ;
}
int F_24 ( struct V_4 * V_5 )
{
if ( V_5 -> V_12 ) {
int V_25 ;
V_25 = F_25 ( V_5 -> V_12 ) ;
if ( V_25 < 0 ) {
F_18 ( V_5 -> V_26 , L_7 , V_25 ) ;
return V_25 ;
}
V_25 = F_26 ( V_5 -> V_12 ) ;
if ( V_25 < 0 ) {
F_18 ( V_5 -> V_26 , L_8 , V_25 ) ;
return V_25 ;
}
V_5 -> V_12 = NULL ;
}
return 0 ;
}
