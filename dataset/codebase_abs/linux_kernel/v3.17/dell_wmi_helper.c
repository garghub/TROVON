static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
struct V_5 * V_6 )
{
if ( V_7 )
V_7 ( V_2 , V_4 , V_6 ) ;
if ( ! V_6 || ! V_8 )
return;
if ( strcmp ( L_1 , V_6 -> V_9 . V_10 ) == 0 && V_6 -> V_9 . V_11 == 0 ) {
int V_12 = ( V_6 -> V_13 . integer . V_13 [ 0 ] || V_6 -> V_13 . integer . V_13 [ 1 ] ) ? 0 : 1 ;
if ( V_12 == V_14 )
return;
V_14 = V_12 ;
if ( V_8 )
V_8 ( V_15 , V_14 ) ;
}
}
static void F_2 ( struct V_1 * V_2 ,
const struct V_16 * V_17 , int V_18 )
{
struct V_19 * V_20 = V_2 -> V_20 ;
bool V_21 = false ;
if ( V_18 == V_22 ) {
if ( ! V_8 )
V_8 = F_3 ( V_23 ) ;
if ( ! V_8 ) {
F_4 ( V_2 , L_2 ) ;
return;
}
V_21 = true ;
if ( V_8 ( V_15 , false ) >= 0 ) {
V_14 = 0 ;
if ( V_20 -> V_24 . V_25 > 1 )
F_5 ( V_2 , L_3 ) ;
else {
V_7 = V_20 -> V_24 . V_26 ;
V_20 -> V_24 . V_26 = F_1 ;
V_21 = false ;
}
}
}
if ( V_8 && ( V_18 == V_27 || V_21 ) ) {
F_6 ( V_23 ) ;
V_8 = NULL ;
V_7 = NULL ;
}
}
static void F_2 ( struct V_1 * V_2 ,
const struct V_16 * V_17 , int V_18 )
{
}
