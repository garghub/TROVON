static void
F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 , * V_5 ;
F_2 (work, temp, &fence->work, head) {
F_3 ( & V_4 -> V_6 ) ;
F_4 ( & V_4 -> V_7 ) ;
}
V_2 -> V_8 = NULL ;
F_4 ( & V_2 -> V_7 ) ;
}
void
F_5 ( struct V_9 * V_10 )
{
struct V_1 * V_2 , * V_11 ;
F_6 ( & V_10 -> V_12 ) ;
F_2 (fence, fnext, &fctx->pending, head) {
F_1 ( V_2 ) ;
}
F_7 ( & V_10 -> V_12 ) ;
}
void
F_8 ( struct V_9 * V_10 )
{
F_9 ( & V_10 -> V_13 ) ;
F_9 ( & V_10 -> V_14 ) ;
F_10 ( & V_10 -> V_12 ) ;
}
static void
F_11 ( struct V_15 * V_16 )
{
struct V_3 * V_4 = F_12 ( V_16 , F_13 ( * V_4 ) , V_6 ) ;
V_4 -> V_17 ( V_4 -> V_18 ) ;
F_14 ( V_4 ) ;
}
void
F_15 ( struct V_1 * V_2 ,
void (* V_17)( void * ) , void * V_18 )
{
struct V_19 * V_20 = V_2 -> V_8 ;
struct V_9 * V_10 ;
struct V_3 * V_4 = NULL ;
if ( F_16 ( V_2 ) ) {
V_17 ( V_18 ) ;
return;
}
V_10 = V_20 -> V_2 ;
V_4 = F_17 ( sizeof( * V_4 ) , V_21 ) ;
if ( ! V_4 ) {
F_18 ( F_19 ( V_2 , false , false ) ) ;
V_17 ( V_18 ) ;
return;
}
F_6 ( & V_10 -> V_12 ) ;
if ( ! V_2 -> V_8 ) {
F_7 ( & V_10 -> V_12 ) ;
F_14 ( V_4 ) ;
V_17 ( V_18 ) ;
return;
}
F_20 ( & V_4 -> V_6 , F_11 ) ;
V_4 -> V_17 = V_17 ;
V_4 -> V_18 = V_18 ;
F_21 ( & V_4 -> V_7 , & V_2 -> V_4 ) ;
F_7 ( & V_10 -> V_12 ) ;
}
static void
F_22 ( struct V_19 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_2 ;
struct V_1 * V_2 , * V_11 ;
F_6 ( & V_10 -> V_12 ) ;
F_2 (fence, fnext, &fctx->pending, head) {
if ( V_10 -> V_22 ( V_20 ) < V_2 -> V_23 )
break;
F_1 ( V_2 ) ;
F_23 ( & V_2 ) ;
}
F_7 ( & V_10 -> V_12 ) ;
}
int
F_24 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_2 ;
int V_24 ;
V_2 -> V_8 = V_20 ;
V_2 -> V_25 = V_26 + ( 15 * V_27 ) ;
V_2 -> V_23 = ++ V_10 -> V_23 ;
V_24 = V_10 -> V_28 ( V_2 ) ;
if ( ! V_24 ) {
F_25 ( & V_2 -> V_29 ) ;
F_6 ( & V_10 -> V_12 ) ;
F_26 ( & V_2 -> V_7 , & V_10 -> V_14 ) ;
F_7 ( & V_10 -> V_12 ) ;
}
return V_24 ;
}
bool
F_16 ( struct V_1 * V_2 )
{
if ( V_2 -> V_8 )
F_22 ( V_2 -> V_8 ) ;
return ! V_2 -> V_8 ;
}
static int
F_27 ( struct V_30 * V_31 , int V_32 )
{
struct V_33 * V_34 =
F_12 ( V_31 , struct V_33 , V_35 ) ;
F_28 ( & V_34 -> V_36 -> V_37 ) ;
return V_38 ;
}
static int
F_29 ( struct V_1 * V_2 , bool V_39 )
{
struct V_19 * V_20 = V_2 -> V_8 ;
struct V_40 * V_41 = V_40 ( V_20 -> V_42 -> V_43 ) ;
struct V_44 * V_36 = V_20 -> V_42 -> V_2 ;
struct V_33 V_34 = {
. V_35 . V_17 = F_27 ,
. V_36 = V_36 ,
} ;
int V_24 = 0 ;
F_30 ( V_41 -> V_34 , 0 , & V_34 . V_35 ) ;
if ( V_2 -> V_25 ) {
unsigned long V_25 = V_2 -> V_25 - V_26 ;
if ( F_31 ( V_26 , V_2 -> V_25 ) ) {
if ( V_39 ) {
V_24 = F_32 (
V_36 -> V_37 ,
F_16 ( V_2 ) ,
V_25 ) ;
} else {
V_24 = F_33 ( V_36 -> V_37 ,
F_16 ( V_2 ) ,
V_25 ) ;
}
}
if ( V_24 >= 0 ) {
V_2 -> V_25 = V_26 + V_24 ;
if ( F_34 ( V_26 , V_2 -> V_25 ) )
V_24 = - V_45 ;
}
} else {
if ( V_39 ) {
V_24 = F_35 ( V_36 -> V_37 ,
F_16 ( V_2 ) ) ;
} else {
F_36 ( V_36 -> V_37 , F_16 ( V_2 ) ) ;
}
}
F_37 ( V_41 -> V_34 , 0 , & V_34 . V_35 ) ;
if ( F_38 ( V_24 < 0 ) )
return V_24 ;
return 0 ;
}
int
F_19 ( struct V_1 * V_2 , bool V_46 , bool V_39 )
{
struct V_19 * V_20 = V_2 -> V_8 ;
struct V_44 * V_36 = V_20 ? V_20 -> V_42 -> V_2 : NULL ;
unsigned long V_47 = V_48 / 1000 ;
T_1 V_49 ;
int V_24 = 0 ;
while ( V_36 && V_36 -> V_34 && V_46 && ! F_16 ( V_2 ) ) {
V_24 = F_29 ( V_2 , V_39 ) ;
if ( V_24 < 0 )
return V_24 ;
}
while ( ! F_16 ( V_2 ) ) {
if ( V_2 -> V_25 && F_34 ( V_26 , V_2 -> V_25 ) ) {
V_24 = - V_45 ;
break;
}
F_39 ( V_39 ? V_50 :
V_51 ) ;
if ( V_46 ) {
V_49 = F_40 ( 0 , V_47 ) ;
F_41 ( & V_49 , V_52 ) ;
V_47 *= 2 ;
if ( V_47 > V_48 )
V_47 = V_48 ;
}
if ( V_39 && F_42 ( V_53 ) ) {
V_24 = - V_54 ;
break;
}
}
F_39 ( V_55 ) ;
return V_24 ;
}
int
F_43 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_2 ;
struct V_19 * V_56 ;
int V_24 = 0 ;
V_56 = V_2 ? V_2 -> V_8 : NULL ;
if ( V_56 ) {
if ( F_38 ( V_56 != V_20 && ! F_16 ( V_2 ) ) ) {
V_24 = V_10 -> V_57 ( V_2 , V_56 , V_20 ) ;
if ( F_38 ( V_24 ) )
V_24 = F_19 ( V_2 , true , false ) ;
}
}
return V_24 ;
}
static void
F_44 ( struct V_29 * V_29 )
{
struct V_1 * V_2 = F_12 ( V_29 , F_13 ( * V_2 ) , V_29 ) ;
F_14 ( V_2 ) ;
}
void
F_23 ( struct V_1 * * V_58 )
{
if ( * V_58 )
F_45 ( & ( * V_58 ) -> V_29 , F_44 ) ;
* V_58 = NULL ;
}
struct V_1 *
F_46 ( struct V_1 * V_2 )
{
F_25 ( & V_2 -> V_29 ) ;
return V_2 ;
}
int
F_47 ( struct V_19 * V_20 , bool V_59 ,
struct V_1 * * V_58 )
{
struct V_1 * V_2 ;
int V_24 = 0 ;
if ( F_38 ( ! V_20 -> V_2 ) )
return - V_60 ;
V_2 = F_48 ( sizeof( * V_2 ) , V_21 ) ;
if ( ! V_2 )
return - V_61 ;
F_9 ( & V_2 -> V_4 ) ;
V_2 -> V_59 = V_59 ;
F_49 ( & V_2 -> V_29 ) ;
V_24 = F_24 ( V_2 , V_20 ) ;
if ( V_24 )
F_23 ( & V_2 ) ;
* V_58 = V_2 ;
return V_24 ;
}
