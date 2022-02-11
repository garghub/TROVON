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
static struct V_2 *
F_14 ( struct V_6 * V_7 )
{
struct V_1 * V_9 = F_4 ( V_7 ) ;
return & V_9 -> V_4 ;
}
static int F_15 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
struct V_6 * V_7 = & V_9 -> V_7 ;
int V_20 ;
V_7 -> V_21 = V_22 ;
V_20 = F_16 ( V_4 -> V_15 , V_7 ,
& V_23 ,
V_24 ) ;
if ( V_20 ) {
F_11 ( L_2 ) ;
return V_20 ;
}
F_17 ( V_7 , & V_25 ) ;
F_18 ( V_7 ) ;
F_19 ( V_7 , V_4 ) ;
return 0 ;
}
static bool F_20 ( struct V_2 * V_4 ,
const struct V_13 * V_14 ,
struct V_13 * V_26 )
{
return true ;
}
static void F_21 ( struct V_2 * V_4 ,
struct V_13 * V_14 ,
struct V_13 * V_26 )
{
}
static void F_22 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
if ( V_9 -> V_10 ) {
F_23 ( V_9 -> V_10 ) ;
F_24 ( V_9 -> V_10 ) ;
}
}
static void F_25 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
if ( V_9 -> V_10 ) {
F_26 ( V_9 -> V_10 ) ;
F_27 ( V_9 -> V_10 ) ;
}
}
static struct V_27 *
F_28 ( struct V_27 * V_28 , const char * V_29 , T_1 V_30 )
{
struct V_27 * V_31 ;
F_29 (parent, np) {
T_1 V_32 ;
if ( ! V_31 -> V_29 || F_30 ( V_31 -> V_29 , V_29 ) )
continue;
if ( F_31 ( V_31 , L_3 , & V_32 ) < 0 )
V_32 = 0 ;
if ( V_30 == V_32 )
break;
}
return V_31 ;
}
static struct V_27 * F_32 ( struct V_27 * V_28 ,
T_1 V_30 )
{
struct V_27 * V_33 , * V_34 ;
V_33 = F_33 ( V_28 , L_4 ) ;
if ( V_33 )
V_28 = V_33 ;
V_34 = F_28 ( V_28 , L_5 , V_30 ) ;
F_34 ( V_33 ) ;
return V_34 ;
}
static struct V_27 *
F_35 ( struct V_27 * V_34 , T_1 V_30 )
{
return F_28 ( V_34 , L_6 , V_30 ) ;
}
static struct V_27 *
F_36 ( const struct V_27 * V_35 )
{
struct V_27 * V_31 ;
unsigned int V_36 ;
V_31 = F_37 ( V_35 , L_7 , 0 ) ;
for ( V_36 = 3 ; V_36 && V_31 ; V_36 -- ) {
V_31 = F_38 ( V_31 ) ;
if ( V_36 == 2 && F_30 ( V_31 -> V_29 , L_4 ) )
break;
}
return V_31 ;
}
static struct V_27 * F_39 ( struct V_37 * V_15 )
{
struct V_27 * V_31 , * V_38 ;
V_31 = F_32 ( V_15 -> V_39 , V_40 ) ;
if ( ! V_31 )
return NULL ;
V_38 = F_35 ( V_31 , 0 ) ;
F_34 ( V_31 ) ;
if ( ! V_38 )
return NULL ;
V_31 = F_36 ( V_38 ) ;
F_34 ( V_38 ) ;
return V_31 ;
}
static int F_40 ( struct V_1 * V_9 )
{
struct V_37 * V_15 = V_9 -> V_15 ;
struct V_27 * V_41 = V_15 -> V_39 ;
struct V_27 * V_31 ;
V_9 -> V_42 = F_39 ( V_15 ) ;
V_31 = F_33 ( V_41 , L_8 ) ;
if ( V_31 ) {
struct V_43 * V_12 ;
int V_20 ;
F_34 ( V_31 ) ;
V_12 = F_41 ( V_15 , sizeof( * V_9 -> V_12 ) , V_44 ) ;
if ( ! V_12 )
return - V_45 ;
V_20 = F_42 ( V_41 , V_12 , 0 ) ;
if ( V_20 < 0 ) {
F_43 ( V_15 , V_12 ) ;
return V_20 ;
}
V_9 -> V_12 = V_12 ;
return 0 ;
}
if ( ! V_9 -> V_42 )
return - V_46 ;
return 0 ;
}
int F_44 ( struct V_47 * V_15 , struct V_2 * V_4 )
{
int V_20 ;
V_20 = F_45 ( V_15 , V_48 ) ;
if ( V_20 < 0 )
return V_20 ;
V_4 -> V_49 = 1 << V_20 ;
F_46 ( L_9 , V_4 -> V_49 ) ;
F_47 ( V_15 , V_4 , & V_50 ,
V_51 , NULL ) ;
F_48 ( V_4 , & V_52 ) ;
V_20 = F_15 ( V_4 ) ;
if ( V_20 ) {
F_11 ( L_10 , V_20 ) ;
F_49 ( V_4 ) ;
return V_20 ;
}
return 0 ;
}
struct V_2 * F_50 ( struct V_37 * V_15 )
{
struct V_1 * V_9 ;
int V_20 ;
V_9 = F_41 ( V_15 , sizeof( * V_9 ) , V_44 ) ;
if ( ! V_9 )
return F_51 ( - V_45 ) ;
V_9 -> V_15 = V_15 ;
V_20 = F_40 ( V_9 ) ;
if ( V_20 < 0 ) {
F_43 ( V_15 , V_9 ) ;
return NULL ;
}
if ( V_9 -> V_42 ) {
V_9 -> V_10 = F_52 ( V_9 -> V_42 ) ;
if ( ! V_9 -> V_10 )
return F_51 ( - V_53 ) ;
}
return & V_9 -> V_4 ;
}
int F_53 ( struct V_2 * V_4 )
{
struct V_1 * V_9 = F_1 ( V_4 ) ;
F_25 ( & V_9 -> V_4 ) ;
if ( V_9 -> V_10 )
F_54 ( V_9 -> V_10 ) ;
return 0 ;
}
