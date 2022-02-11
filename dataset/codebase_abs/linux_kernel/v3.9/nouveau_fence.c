void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 (fence, fnext, &fctx->pending, head) {
V_4 -> V_7 = NULL ;
F_4 ( & V_4 -> V_8 ) ;
F_5 ( & V_4 ) ;
}
F_6 ( & V_2 -> V_6 ) ;
}
void
F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_9 ) ;
F_8 ( & V_2 -> V_10 ) ;
F_9 ( & V_2 -> V_6 ) ;
}
static void
F_10 ( struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_4 ;
struct V_3 * V_4 , * V_5 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 (fence, fnext, &fctx->pending, head) {
if ( V_2 -> V_13 ( V_12 ) < V_4 -> V_14 )
break;
V_4 -> V_7 = NULL ;
F_4 ( & V_4 -> V_8 ) ;
F_5 ( & V_4 ) ;
}
F_6 ( & V_2 -> V_6 ) ;
}
int
F_11 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_4 ;
int V_15 ;
V_4 -> V_7 = V_12 ;
V_4 -> V_16 = V_17 + ( 3 * V_18 ) ;
V_4 -> V_14 = ++ V_2 -> V_14 ;
V_15 = V_2 -> V_19 ( V_4 ) ;
if ( ! V_15 ) {
F_12 ( & V_4 -> V_20 ) ;
F_2 ( & V_2 -> V_6 ) ;
F_13 ( & V_4 -> V_8 , & V_2 -> V_10 ) ;
F_6 ( & V_2 -> V_6 ) ;
}
return V_15 ;
}
bool
F_14 ( struct V_3 * V_4 )
{
if ( V_4 -> V_7 )
F_10 ( V_4 -> V_7 ) ;
return ! V_4 -> V_7 ;
}
static int
F_15 ( struct V_21 * V_22 , int V_23 )
{
struct V_24 * V_25 =
F_16 ( V_22 , struct V_24 , V_26 ) ;
F_17 ( & V_25 -> V_27 -> V_28 ) ;
return V_29 ;
}
static int
F_18 ( struct V_3 * V_4 , bool V_30 )
{
struct V_11 * V_12 = V_4 -> V_7 ;
struct V_31 * V_32 = V_31 ( V_12 -> V_33 -> V_34 ) ;
struct V_35 * V_27 = V_12 -> V_33 -> V_4 ;
struct V_24 V_25 = {
. V_26 . V_36 = F_15 ,
. V_27 = V_27 ,
} ;
int V_15 = 0 ;
F_19 ( V_32 -> V_25 , 0 , & V_25 . V_26 ) ;
if ( V_4 -> V_16 ) {
unsigned long V_16 = V_4 -> V_16 - V_17 ;
if ( F_20 ( V_17 , V_4 -> V_16 ) ) {
if ( V_30 ) {
V_15 = F_21 (
V_27 -> V_28 ,
F_14 ( V_4 ) ,
V_16 ) ;
} else {
V_15 = F_22 ( V_27 -> V_28 ,
F_14 ( V_4 ) ,
V_16 ) ;
}
}
if ( V_15 >= 0 ) {
V_4 -> V_16 = V_17 + V_15 ;
if ( F_23 ( V_17 , V_4 -> V_16 ) )
V_15 = - V_37 ;
}
} else {
if ( V_30 ) {
V_15 = F_24 ( V_27 -> V_28 ,
F_14 ( V_4 ) ) ;
} else {
F_25 ( V_27 -> V_28 , F_14 ( V_4 ) ) ;
}
}
F_26 ( V_32 -> V_25 , 0 , & V_25 . V_26 ) ;
if ( F_27 ( V_15 < 0 ) )
return V_15 ;
return 0 ;
}
int
F_28 ( struct V_3 * V_4 , bool V_38 , bool V_30 )
{
struct V_11 * V_12 = V_4 -> V_7 ;
struct V_35 * V_27 = V_12 ? V_12 -> V_33 -> V_4 : NULL ;
unsigned long V_39 = V_40 / 1000 ;
T_1 V_41 ;
int V_15 = 0 ;
while ( V_27 && V_27 -> V_25 && V_38 && ! F_14 ( V_4 ) ) {
V_15 = F_18 ( V_4 , V_30 ) ;
if ( V_15 < 0 )
return V_15 ;
}
while ( ! F_14 ( V_4 ) ) {
if ( V_4 -> V_16 && F_23 ( V_17 , V_4 -> V_16 ) ) {
V_15 = - V_37 ;
break;
}
F_29 ( V_30 ? V_42 :
V_43 ) ;
if ( V_38 ) {
V_41 = F_30 ( 0 , V_39 ) ;
F_31 ( & V_41 , V_44 ) ;
V_39 *= 2 ;
if ( V_39 > V_40 )
V_39 = V_40 ;
}
if ( V_30 && F_32 ( V_45 ) ) {
V_15 = - V_46 ;
break;
}
}
F_29 ( V_47 ) ;
return V_15 ;
}
int
F_33 ( struct V_3 * V_4 , struct V_11 * V_12 )
{
struct V_1 * V_2 = V_12 -> V_4 ;
struct V_11 * V_48 ;
int V_15 = 0 ;
V_48 = V_4 ? V_4 -> V_7 : NULL ;
if ( V_48 ) {
if ( F_27 ( V_48 != V_12 && ! F_14 ( V_4 ) ) ) {
V_15 = V_2 -> V_49 ( V_4 , V_48 , V_12 ) ;
if ( F_27 ( V_15 ) )
V_15 = F_28 ( V_4 , true , false ) ;
}
}
return V_15 ;
}
static void
F_34 ( struct V_20 * V_20 )
{
struct V_3 * V_4 = F_16 ( V_20 , F_35 ( * V_4 ) , V_20 ) ;
F_36 ( V_4 ) ;
}
void
F_5 ( struct V_3 * * V_50 )
{
if ( * V_50 )
F_37 ( & ( * V_50 ) -> V_20 , F_34 ) ;
* V_50 = NULL ;
}
struct V_3 *
F_38 ( struct V_3 * V_4 )
{
F_12 ( & V_4 -> V_20 ) ;
return V_4 ;
}
int
F_39 ( struct V_11 * V_12 , bool V_51 ,
struct V_3 * * V_50 )
{
struct V_3 * V_4 ;
int V_15 = 0 ;
if ( F_27 ( ! V_12 -> V_4 ) )
return - V_52 ;
V_4 = F_40 ( sizeof( * V_4 ) , V_53 ) ;
if ( ! V_4 )
return - V_54 ;
V_4 -> V_51 = V_51 ;
F_41 ( & V_4 -> V_20 ) ;
V_15 = F_11 ( V_4 , V_12 ) ;
if ( V_15 )
F_5 ( & V_4 ) ;
* V_50 = V_4 ;
return V_15 ;
}
