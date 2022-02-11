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
F_9 ( & V_2 -> V_6 ) ;
}
void
F_10 ( struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_8 = F_11 ( V_15 , V_17 ) ;
struct V_1 * V_2 = V_13 -> V_18 [ V_17 ] ;
struct V_3 * V_4 , * V_5 ;
F_2 ( & V_2 -> V_6 ) ;
F_3 (fence, fnext, &fctx->pending, head) {
if ( V_8 -> V_19 ( V_13 ) < V_4 -> V_20 )
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
F_12 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_8 = F_11 ( V_15 , V_17 ) ;
struct V_1 * V_2 = V_13 -> V_18 [ V_17 ] ;
int V_21 ;
V_4 -> V_9 = V_13 ;
V_4 -> V_22 = V_23 + ( 3 * V_24 ) ;
V_4 -> V_20 = ++ V_2 -> V_20 ;
V_21 = V_8 -> V_25 ( V_4 ) ;
if ( ! V_21 ) {
F_13 ( & V_4 -> V_26 ) ;
F_2 ( & V_2 -> V_6 ) ;
F_14 ( & V_4 -> V_10 , & V_2 -> V_11 ) ;
F_6 ( & V_2 -> V_6 ) ;
}
return V_21 ;
}
bool
F_15 ( struct V_3 * V_4 )
{
if ( V_4 -> V_9 )
F_10 ( V_4 -> V_9 ) ;
return ! V_4 -> V_9 ;
}
int
F_16 ( struct V_3 * V_4 , bool V_27 , bool V_28 )
{
unsigned long V_29 = V_30 / 1000 ;
T_1 V_31 ;
int V_21 = 0 ;
while ( ! F_15 ( V_4 ) ) {
if ( V_4 -> V_22 && F_17 ( V_23 , V_4 -> V_22 ) ) {
V_21 = - V_32 ;
break;
}
F_18 ( V_28 ? V_33 :
V_34 ) ;
if ( V_27 ) {
V_31 = F_19 ( 0 , V_29 ) ;
F_20 ( & V_31 , V_35 ) ;
V_29 *= 2 ;
if ( V_29 > V_30 )
V_29 = V_30 ;
}
if ( V_28 && F_21 ( V_36 ) ) {
V_21 = - V_37 ;
break;
}
}
F_18 ( V_38 ) ;
return V_21 ;
}
int
F_22 ( struct V_3 * V_4 , struct V_12 * V_13 )
{
struct V_14 * V_15 = V_13 -> V_15 ;
struct V_16 * V_8 = F_11 ( V_15 , V_17 ) ;
struct V_12 * V_39 ;
int V_21 = 0 ;
V_39 = V_4 ? F_23 ( V_4 -> V_9 ) : NULL ;
if ( V_39 ) {
if ( F_24 ( V_39 != V_13 && ! F_15 ( V_4 ) ) ) {
V_21 = V_8 -> V_40 ( V_4 , V_39 , V_13 ) ;
if ( F_24 ( V_21 ) )
V_21 = F_16 ( V_4 , true , false ) ;
}
F_25 ( & V_39 ) ;
}
return V_21 ;
}
static void
F_26 ( struct V_26 * V_26 )
{
struct V_3 * V_4 = F_27 ( V_26 , F_28 ( * V_4 ) , V_26 ) ;
F_29 ( V_4 ) ;
}
void
F_5 ( struct V_3 * * V_41 )
{
if ( * V_41 )
F_30 ( & ( * V_41 ) -> V_26 , F_26 ) ;
* V_41 = NULL ;
}
struct V_3 *
F_31 ( struct V_3 * V_4 )
{
F_13 ( & V_4 -> V_26 ) ;
return V_4 ;
}
int
F_32 ( struct V_12 * V_13 , struct V_3 * * V_41 )
{
struct V_3 * V_4 ;
int V_21 = 0 ;
if ( F_24 ( ! V_13 -> V_18 [ V_17 ] ) )
return - V_42 ;
V_4 = F_33 ( sizeof( * V_4 ) , V_43 ) ;
if ( ! V_4 )
return - V_44 ;
F_34 ( & V_4 -> V_26 ) ;
if ( V_13 ) {
V_21 = F_12 ( V_4 , V_13 ) ;
if ( V_21 )
F_5 ( & V_4 ) ;
}
* V_41 = V_4 ;
return V_21 ;
}
