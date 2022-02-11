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
F_27 ( void * V_18 , T_1 type , int V_30 )
{
struct V_31 * V_32 = V_18 ;
F_28 ( & V_32 -> V_33 ) ;
return V_34 ;
}
static int
F_29 ( struct V_1 * V_2 , bool V_35 )
{
struct V_19 * V_20 = V_2 -> V_8 ;
struct V_36 * V_37 = V_36 ( V_20 -> V_38 -> V_39 ) ;
struct V_31 * V_32 = V_20 -> V_38 -> V_2 ;
struct V_40 * V_41 ;
int V_24 = 0 ;
V_24 = F_30 ( V_37 -> V_42 , 1 , 0 ,
F_27 ,
V_32 , & V_41 ) ;
if ( V_24 )
return V_24 ;
F_31 ( V_41 ) ;
if ( V_2 -> V_25 ) {
unsigned long V_25 = V_2 -> V_25 - V_26 ;
if ( F_32 ( V_26 , V_2 -> V_25 ) ) {
if ( V_35 ) {
V_24 = F_33 (
V_32 -> V_33 ,
F_16 ( V_2 ) ,
V_25 ) ;
} else {
V_24 = F_34 ( V_32 -> V_33 ,
F_16 ( V_2 ) ,
V_25 ) ;
}
}
if ( V_24 >= 0 ) {
V_2 -> V_25 = V_26 + V_24 ;
if ( F_35 ( V_26 , V_2 -> V_25 ) )
V_24 = - V_43 ;
}
} else {
if ( V_35 ) {
V_24 = F_36 ( V_32 -> V_33 ,
F_16 ( V_2 ) ) ;
} else {
F_37 ( V_32 -> V_33 , F_16 ( V_2 ) ) ;
}
}
F_38 ( NULL , & V_41 ) ;
if ( F_39 ( V_24 < 0 ) )
return V_24 ;
return 0 ;
}
int
F_19 ( struct V_1 * V_2 , bool V_44 , bool V_35 )
{
struct V_19 * V_20 = V_2 -> V_8 ;
struct V_31 * V_32 = V_20 ? V_20 -> V_38 -> V_2 : NULL ;
unsigned long V_45 = V_46 / 1000 ;
T_2 V_47 ;
int V_24 = 0 ;
while ( V_32 && V_32 -> V_42 && V_44 && ! F_16 ( V_2 ) ) {
V_24 = F_29 ( V_2 , V_35 ) ;
if ( V_24 < 0 )
return V_24 ;
}
while ( ! F_16 ( V_2 ) ) {
if ( V_2 -> V_25 && F_35 ( V_26 , V_2 -> V_25 ) ) {
V_24 = - V_43 ;
break;
}
F_40 ( V_35 ? V_48 :
V_49 ) ;
if ( V_44 ) {
V_47 = F_41 ( 0 , V_45 ) ;
F_42 ( & V_47 , V_50 ) ;
V_45 *= 2 ;
if ( V_45 > V_46 )
V_45 = V_46 ;
}
if ( V_35 && F_43 ( V_51 ) ) {
V_24 = - V_52 ;
break;
}
}
F_40 ( V_53 ) ;
return V_24 ;
}
int
F_44 ( struct V_1 * V_2 , struct V_19 * V_20 )
{
struct V_9 * V_10 = V_20 -> V_2 ;
struct V_19 * V_54 ;
int V_24 = 0 ;
V_54 = V_2 ? V_2 -> V_8 : NULL ;
if ( V_54 ) {
if ( F_39 ( V_54 != V_20 && ! F_16 ( V_2 ) ) ) {
V_24 = V_10 -> V_55 ( V_2 , V_54 , V_20 ) ;
if ( F_39 ( V_24 ) )
V_24 = F_19 ( V_2 , true , false ) ;
}
}
return V_24 ;
}
static void
F_45 ( struct V_29 * V_29 )
{
struct V_1 * V_2 = F_12 ( V_29 , F_13 ( * V_2 ) , V_29 ) ;
F_14 ( V_2 ) ;
}
void
F_23 ( struct V_1 * * V_56 )
{
if ( * V_56 )
F_46 ( & ( * V_56 ) -> V_29 , F_45 ) ;
* V_56 = NULL ;
}
struct V_1 *
F_47 ( struct V_1 * V_2 )
{
if ( V_2 )
F_25 ( & V_2 -> V_29 ) ;
return V_2 ;
}
int
F_48 ( struct V_19 * V_20 , bool V_57 ,
struct V_1 * * V_56 )
{
struct V_1 * V_2 ;
int V_24 = 0 ;
if ( F_39 ( ! V_20 -> V_2 ) )
return - V_58 ;
V_2 = F_49 ( sizeof( * V_2 ) , V_21 ) ;
if ( ! V_2 )
return - V_59 ;
F_9 ( & V_2 -> V_4 ) ;
V_2 -> V_57 = V_57 ;
F_50 ( & V_2 -> V_29 ) ;
V_24 = F_24 ( V_2 , V_20 ) ;
if ( V_24 )
F_23 ( & V_2 ) ;
* V_56 = V_2 ;
return V_24 ;
}
