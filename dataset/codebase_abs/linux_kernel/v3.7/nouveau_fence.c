void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 (fence, fnext, &fctx->pending, head) {
if ( V_4 -> V_7 )
V_4 -> V_7 ( V_4 -> V_8 , false ) ;
V_4 -> V_9 = NULL ;
F_4 ( & V_4 -> V_10 ) ;
F_5 ( & V_4 ) ;
}
F_6 ( & V_2 -> V_6 ) ;
}
void
F_7 ( struct V_1 * V_2 )
{
F_8 ( & V_2 -> V_11 ) ;
F_8 ( & V_2 -> V_12 ) ;
F_9 ( & V_2 -> V_6 ) ;
}
static void
F_10 ( struct V_13 * V_14 )
{
struct V_15 * V_8 = V_14 -> V_16 -> V_4 ;
struct V_1 * V_2 = V_14 -> V_4 ;
struct V_3 * V_4 , * V_5 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 (fence, fnext, &fctx->pending, head) {
if ( V_8 -> V_17 ( V_14 ) < V_4 -> V_18 )
break;
if ( V_4 -> V_7 )
V_4 -> V_7 ( V_4 -> V_8 , true ) ;
V_4 -> V_9 = NULL ;
F_4 ( & V_4 -> V_10 ) ;
F_5 ( & V_4 ) ;
}
F_6 ( & V_2 -> V_6 ) ;
}
int
F_11 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
struct V_15 * V_8 = V_14 -> V_16 -> V_4 ;
struct V_1 * V_2 = V_14 -> V_4 ;
int V_19 ;
V_4 -> V_9 = V_14 ;
V_4 -> V_20 = V_21 + ( 3 * V_22 ) ;
V_4 -> V_18 = ++ V_2 -> V_18 ;
V_19 = V_8 -> V_23 ( V_4 ) ;
if ( ! V_19 ) {
F_12 ( & V_4 -> V_24 ) ;
F_2 ( & V_2 -> V_6 ) ;
F_13 ( & V_4 -> V_10 , & V_2 -> V_12 ) ;
F_6 ( & V_2 -> V_6 ) ;
}
return V_19 ;
}
bool
F_14 ( struct V_3 * V_4 )
{
if ( V_4 -> V_9 )
F_10 ( V_4 -> V_9 ) ;
return ! V_4 -> V_9 ;
}
int
F_15 ( struct V_3 * V_4 , bool V_25 , bool V_26 )
{
unsigned long V_27 = V_28 / 1000 ;
T_1 V_29 ;
int V_19 = 0 ;
while ( ! F_14 ( V_4 ) ) {
if ( V_4 -> V_20 && F_16 ( V_21 , V_4 -> V_20 ) ) {
V_19 = - V_30 ;
break;
}
F_17 ( V_26 ? V_31 :
V_32 ) ;
if ( V_25 ) {
V_29 = F_18 ( 0 , V_27 ) ;
F_19 ( & V_29 , V_33 ) ;
V_27 *= 2 ;
if ( V_27 > V_28 )
V_27 = V_28 ;
}
if ( V_26 && F_20 ( V_34 ) ) {
V_19 = - V_35 ;
break;
}
}
F_17 ( V_36 ) ;
return V_19 ;
}
int
F_21 ( struct V_3 * V_4 , struct V_13 * V_14 )
{
struct V_15 * V_8 = V_14 -> V_16 -> V_4 ;
struct V_13 * V_37 ;
int V_19 = 0 ;
V_37 = V_4 ? V_4 -> V_9 : NULL ;
if ( V_37 ) {
if ( F_22 ( V_37 != V_14 && ! F_14 ( V_4 ) ) ) {
V_19 = V_8 -> V_38 ( V_4 , V_37 , V_14 ) ;
if ( F_22 ( V_19 ) )
V_19 = F_15 ( V_4 , true , false ) ;
}
}
return V_19 ;
}
static void
F_23 ( struct V_24 * V_24 )
{
struct V_3 * V_4 = F_24 ( V_24 , F_25 ( * V_4 ) , V_24 ) ;
F_26 ( V_4 ) ;
}
void
F_5 ( struct V_3 * * V_39 )
{
if ( * V_39 )
F_27 ( & ( * V_39 ) -> V_24 , F_23 ) ;
* V_39 = NULL ;
}
struct V_3 *
F_28 ( struct V_3 * V_4 )
{
F_12 ( & V_4 -> V_24 ) ;
return V_4 ;
}
int
F_29 ( struct V_13 * V_14 , struct V_3 * * V_39 )
{
struct V_3 * V_4 ;
int V_19 = 0 ;
if ( F_22 ( ! V_14 -> V_4 ) )
return - V_40 ;
V_4 = F_30 ( sizeof( * V_4 ) , V_41 ) ;
if ( ! V_4 )
return - V_42 ;
F_31 ( & V_4 -> V_24 ) ;
if ( V_14 ) {
V_19 = F_11 ( V_4 , V_14 ) ;
if ( V_19 )
F_5 ( & V_4 ) ;
}
* V_39 = V_4 ;
return V_19 ;
}
