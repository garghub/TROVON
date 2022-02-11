static int
F_1 ( struct V_1 * V_2 , T_1 V_3 , void * V_4 , T_1 V_5 )
{
return F_2 ( F_3 ( V_2 ) -> V_2 , V_3 , V_4 , V_5 ) ;
}
static int
F_4 ( struct V_1 * V_2 , T_1 V_3 ,
struct V_6 * * V_7 )
{
return F_5 ( F_3 ( V_2 ) -> V_2 , V_3 , V_7 ) ;
}
static int
F_6 ( struct V_1 * V_2 , T_2 * V_8 , T_1 * V_5 )
{
return F_7 ( F_3 ( V_2 ) -> V_2 , V_8 , V_5 ) ;
}
static int
F_8 ( struct V_1 * V_2 , T_2 V_8 , T_3 * V_4 )
{
return F_9 ( F_3 ( V_2 ) -> V_2 , V_8 , V_4 ) ;
}
static int
F_10 ( struct V_1 * V_2 , T_2 V_8 , T_4 * V_4 )
{
return F_11 ( F_3 ( V_2 ) -> V_2 , V_8 , V_4 ) ;
}
static int
F_12 ( struct V_1 * V_2 , T_2 V_8 , T_1 * V_4 )
{
return F_13 ( F_3 ( V_2 ) -> V_2 , V_8 , V_4 ) ;
}
static int
F_14 ( struct V_1 * V_2 , T_2 V_8 , T_3 V_4 )
{
return F_15 ( F_3 ( V_2 ) -> V_2 , V_8 , V_4 ) ;
}
static int
F_16 ( struct V_1 * V_2 , T_2 V_8 , T_4 V_4 )
{
return F_17 ( F_3 ( V_2 ) -> V_2 , V_8 , V_4 ) ;
}
static int
F_18 ( struct V_1 * V_2 , T_2 V_8 , T_1 V_4 )
{
return F_19 ( F_3 ( V_2 ) -> V_2 , V_8 , V_4 ) ;
}
static int
F_20 ( struct V_1 * V_2 , struct V_9 * V_10 ,
int V_11 , struct V_9 * * V_12 )
{
return F_21 ( F_3 ( V_2 ) -> V_2 ,
V_10 , V_11 , V_12 ) ;
}
static int
F_22 ( struct V_1 * V_2 , int V_13 ,
struct V_14 * V_15 )
{
struct F_3 * V_16 = F_3 ( V_2 ) ;
V_15 -> V_10 = V_16 -> V_2 ;
if ( ! V_16 -> V_2 -> V_17 -> V_18 )
return - V_19 ;
return V_16 -> V_2 -> V_17 -> V_18 ( V_16 -> V_2 , V_13 , V_15 ) ;
}
static int
F_23 ( struct V_1 * V_2 , bool V_20 )
{
struct F_3 * V_16 = F_3 ( V_2 ) ;
int V_21 ;
if ( V_16 -> V_17 -> V_22 [ 0 ] ) {
V_21 = V_16 -> V_17 -> V_22 [ 0 ] ( V_16 , V_20 ) ;
if ( V_21 && V_20 )
return V_21 ;
}
if ( V_16 -> V_2 -> V_17 -> V_22 ) {
V_21 = V_16 -> V_2 -> V_17 -> V_22 ( V_16 -> V_2 , V_20 ) ;
if ( V_21 && V_20 )
return V_21 ;
}
if ( V_16 -> V_17 -> V_22 [ 1 ] ) {
V_21 = V_16 -> V_17 -> V_22 [ 1 ] ( V_16 , V_20 ) ;
if ( V_21 && V_20 )
return V_21 ;
}
return 0 ;
}
static int
F_24 ( struct V_1 * V_2 )
{
struct F_3 * V_16 = F_3 ( V_2 ) ;
int V_21 ;
if ( V_16 -> V_17 -> V_23 [ 0 ] ) {
V_21 = V_16 -> V_17 -> V_23 [ 0 ] ( V_16 ) ;
if ( V_21 )
return V_21 ;
}
if ( V_16 -> V_2 -> V_17 -> V_23 ) {
V_21 = V_16 -> V_2 -> V_17 -> V_23 ( V_16 -> V_2 ) ;
if ( V_21 )
return V_21 ;
}
if ( V_16 -> V_17 -> V_23 [ 1 ] ) {
V_21 = V_16 -> V_17 -> V_23 [ 1 ] ( V_16 ) ;
if ( V_21 )
return V_21 ;
}
return 0 ;
}
static void *
F_25 ( struct V_1 * V_2 )
{
struct F_3 * V_16 = F_3 ( V_2 ) ;
if ( V_16 -> V_17 -> V_24 [ 0 ] )
V_16 -> V_17 -> V_24 [ 0 ] ( V_16 ) ;
F_26 ( & V_16 -> V_2 ) ;
if ( V_16 -> V_17 -> V_24 [ 1 ] )
V_16 -> V_17 -> V_24 [ 1 ] ( V_16 ) ;
return V_16 ;
}
void
F_27 ( const struct V_25 * V_17 ,
const struct V_14 * V_15 , struct F_3 * V_16 )
{
F_28 ( & V_25 , V_15 , & V_16 -> V_26 ) ;
V_16 -> V_17 = V_17 ;
}
int
F_29 ( const struct V_25 * V_17 ,
const struct V_14 * V_15 , struct F_3 * * V_27 )
{
if ( ! ( * V_27 = F_30 ( sizeof( * * V_27 ) , V_28 ) ) )
return - V_29 ;
F_27 ( V_17 , V_15 , * V_27 ) ;
return 0 ;
}
