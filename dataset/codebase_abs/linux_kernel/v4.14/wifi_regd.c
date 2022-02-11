static int F_1 ( int V_1 , int V_2 )
{
if ( V_1 == 14 )
return 2484 ;
else if ( V_1 < 14 )
return 2407 + V_1 * 5 ;
else
return 0 ;
}
static void F_2 ( struct V_3 * V_3 )
{
struct V_4 * V_5 = F_3 ( V_3 ) ;
struct V_6 * V_7 = & V_5 -> V_8 ;
T_1 * V_9 = V_7 -> V_9 ;
T_2 V_10 = V_7 -> V_10 ;
struct V_11 * V_12 ;
struct V_13 * V_14 ;
unsigned int V_15 , V_16 ;
T_3 V_17 ;
T_4 V_18 ;
for ( V_15 = 0 ; V_15 < V_19 ; V_15 ++ ) {
V_12 = V_3 -> V_20 [ V_15 ] ;
if ( V_12 ) {
for ( V_16 = 0 ; V_16 < V_12 -> V_21 ; V_16 ++ ) {
V_14 = & V_12 -> V_22 [ V_16 ] ;
if ( V_14 )
V_14 -> V_23 = V_24 ;
}
}
}
for ( V_15 = 0 ; V_15 < V_10 ; V_15 ++ ) {
V_17 = V_9 [ V_15 ] . V_25 ;
V_18 =
F_1 ( V_17 ,
V_26 ) ;
V_14 = F_4 ( V_3 , V_18 ) ;
if ( V_14 ) {
if ( V_9 [ V_15 ] . V_27 == V_28 )
V_14 -> V_23 = V_29 ;
else
V_14 -> V_23 = 0 ;
}
}
}
static int F_5 ( struct V_3 * V_3 ,
struct V_30 * V_31 ,
struct V_32 * V_33 )
{
F_2 ( V_3 ) ;
return 0 ;
}
static const struct V_34 * F_6 ( struct
V_32
* V_33 )
{
return & V_35 ;
}
static void F_7 ( struct V_32 * V_33 ,
struct V_3 * V_3 ,
void (* F_8)( struct V_3 * V_3 ,
struct
V_30 *
V_31 ) )
{
const struct V_34 * V_36 ;
V_3 -> F_8 = F_8 ;
V_3 -> V_37 |= V_38 ;
V_3 -> V_37 &= ~ V_39 ;
V_3 -> V_37 &= ~ V_40 ;
V_36 = F_6 ( V_33 ) ;
F_9 ( V_3 , V_36 ) ;
F_2 ( V_3 ) ;
}
int F_10 ( struct V_4 * V_5 ,
void (* F_8)( struct V_3 * V_3 ,
struct V_30 * V_31 ) )
{
struct V_3 * V_3 = V_5 -> V_41 -> V_3 ;
F_7 ( NULL , V_3 , F_8 ) ;
return 0 ;
}
void F_11 ( struct V_3 * V_3 , struct V_30 * V_31 )
{
struct V_32 * V_33 = NULL ;
F_12 ( L_1 , V_42 ) ;
F_5 ( V_3 , V_31 , V_33 ) ;
}
