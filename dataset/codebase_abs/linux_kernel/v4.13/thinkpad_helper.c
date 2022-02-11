static bool F_1 ( struct V_1 * V_2 )
{
return ( V_2 -> V_3 . V_4 >> 16 == 0x17aa ) &&
( F_2 ( L_1 ) || F_2 ( L_2 ) ||
F_2 ( L_3 ) ) ;
}
static void F_3 ( void * V_5 , int V_6 )
{
if ( V_7 )
V_7 ( V_5 , V_6 ) ;
if ( V_8 )
V_8 ( V_9 , ! V_6 ) ;
}
static void F_4 ( struct V_1 * V_2 ,
struct V_10 * V_11 ,
struct V_12 * V_13 )
{
if ( ! V_13 || ! V_8 )
return;
if ( strcmp ( L_4 , V_13 -> V_14 . V_15 ) == 0 && V_13 -> V_14 . V_16 == 0 ) {
bool V_17 = V_13 -> V_18 . integer . V_18 [ 0 ] || V_13 -> V_18 . integer . V_18 [ 1 ] ;
V_8 ( V_19 , ! V_17 ) ;
}
}
static void F_5 ( struct V_1 * V_2 ,
const struct V_20 * V_21 , int V_22 )
{
struct V_23 * V_24 = V_2 -> V_24 ;
bool V_25 = false ;
if ( V_22 == V_26 ) {
if ( ! F_1 ( V_2 ) )
return;
if ( ! V_8 )
V_8 = F_6 ( V_27 ) ;
if ( ! V_8 ) {
F_7 ( V_2 ,
L_5 ) ;
return;
}
V_25 = true ;
if ( V_8 ( V_9 , false ) >= 0 ) {
V_7 = V_24 -> V_28 . V_29 ;
V_24 -> V_28 . V_29 = F_3 ;
V_25 = false ;
}
if ( V_8 ( V_19 , false ) >= 0 ) {
if ( V_24 -> V_30 > 1 && ! V_24 -> V_31 )
F_8 ( V_2 ,
L_6 ) ;
else {
V_24 -> V_32 = F_4 ;
V_25 = false ;
}
}
}
if ( V_8 && ( V_22 == V_33 || V_25 ) ) {
F_9 ( V_27 ) ;
V_8 = NULL ;
V_7 = NULL ;
}
}
static void F_5 ( struct V_1 * V_2 ,
const struct V_20 * V_21 , int V_22 )
{
}
