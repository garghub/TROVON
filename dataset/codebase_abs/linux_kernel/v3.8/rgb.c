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
struct V_4 * V_5 = F_6 ( V_3 -> V_12 . V_13 ) ;
F_3 ( V_5 , V_14 , F_7 ( V_14 ) ) ;
return 0 ;
}
static int F_8 ( struct V_2 * V_3 )
{
struct V_4 * V_5 = F_6 ( V_3 -> V_12 . V_13 ) ;
F_3 ( V_5 , V_15 , F_7 ( V_15 ) ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_3 ,
struct V_16 * V_16 , unsigned long V_17 )
{
struct V_1 * V_18 = F_1 ( V_3 ) ;
return F_10 ( V_16 , V_18 -> V_19 ) ;
}
static int F_11 ( struct V_2 * V_3 ,
struct V_20 * V_21 ,
enum V_22 * V_23 )
{
* V_23 = V_24 ;
return 0 ;
}
int F_12 ( struct V_4 * V_5 )
{
struct V_25 * V_26 ;
struct V_1 * V_18 ;
int V_27 ;
V_26 = F_13 ( V_5 -> V_28 -> V_29 , L_1 ) ;
if ( ! V_26 || ! F_14 ( V_26 ) )
return - V_30 ;
V_18 = F_15 ( V_5 -> V_28 , sizeof( * V_18 ) , V_31 ) ;
if ( ! V_18 )
return - V_32 ;
V_18 -> V_16 = F_16 ( V_5 -> V_28 , NULL ) ;
if ( F_17 ( V_18 -> V_16 ) ) {
F_18 ( V_5 -> V_28 , L_2 ) ;
return F_19 ( V_18 -> V_16 ) ;
}
V_18 -> V_19 = F_16 ( V_5 -> V_28 , L_3 ) ;
if ( F_17 ( V_18 -> V_19 ) ) {
F_18 ( V_5 -> V_28 , L_4 ) ;
return F_19 ( V_18 -> V_19 ) ;
}
V_27 = F_10 ( V_18 -> V_16 , V_18 -> V_19 ) ;
if ( V_27 < 0 ) {
F_18 ( V_5 -> V_28 , L_5 , V_27 ) ;
return V_27 ;
}
V_18 -> V_3 . V_28 = V_5 -> V_28 ;
V_18 -> V_3 . V_29 = V_26 ;
V_27 = F_20 ( & V_18 -> V_3 ) ;
if ( V_27 < 0 )
return V_27 ;
V_5 -> V_18 = & V_18 -> V_3 ;
return 0 ;
}
int F_21 ( struct V_33 * V_34 , struct V_4 * V_5 )
{
struct V_1 * V_18 = F_1 ( V_5 -> V_18 ) ;
int V_27 ;
if ( ! V_5 -> V_18 )
return - V_30 ;
V_18 -> V_3 . type = V_35 ;
V_18 -> V_3 . V_36 = & V_37 ;
V_27 = F_22 ( V_5 -> V_38 . V_28 , & V_18 -> V_3 ) ;
if ( V_27 < 0 ) {
F_18 ( V_5 -> V_28 , L_6 , V_27 ) ;
return V_27 ;
}
V_18 -> V_3 . V_12 . V_39 = 1 << V_5 -> V_40 ;
return 0 ;
}
int F_23 ( struct V_4 * V_5 )
{
if ( V_5 -> V_18 ) {
int V_27 ;
V_27 = F_24 ( V_5 -> V_18 ) ;
if ( V_27 < 0 ) {
F_18 ( V_5 -> V_28 , L_7 , V_27 ) ;
return V_27 ;
}
V_27 = F_25 ( V_5 -> V_18 ) ;
if ( V_27 < 0 ) {
F_18 ( V_5 -> V_28 , L_8 , V_27 ) ;
return V_27 ;
}
V_5 -> V_18 = NULL ;
}
return 0 ;
}
