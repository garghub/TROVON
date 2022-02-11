static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 -> V_4 ;
}
static inline int F_3 ( struct V_5 * V_6 ,
int V_7 , int V_8 )
{
if ( V_7 < V_6 -> V_7 || V_7 > V_6 -> V_8 )
return - V_9 ;
return 0 ;
}
static int F_4 ( struct V_2 * V_3 ,
int V_7 , int V_8 , unsigned * V_10 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
T_1 V_12 , V_13 ;
if ( F_3 ( V_6 , V_7 , V_8 ) ) {
F_6 ( L_1 , V_7 , V_8 ) ;
return - V_9 ;
}
V_12 = F_7 ( V_7 - V_6 -> V_7 , V_6 -> V_14 ) ;
* V_10 = V_12 ;
V_12 <<= V_6 -> V_15 ;
V_13 = ( ( 1 << V_6 -> V_16 ) - 1 ) << V_6 -> V_15 ;
return F_8 ( V_11 , V_6 -> V_17 , V_12 , V_13 ) ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
T_1 V_12 , V_13 ;
int V_18 ;
V_18 = F_10 ( V_11 , V_6 -> V_17 , & V_12 ) ;
if ( V_18 )
return V_18 ;
V_13 = ( ( 1 << V_6 -> V_16 ) - 1 ) << V_6 -> V_15 ;
V_12 = ( V_12 & V_13 ) >> V_6 -> V_15 ;
return V_6 -> V_7 + V_6 -> V_14 * V_12 ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
return F_12 ( V_11 , V_6 -> V_19 ,
1 << V_6 -> V_20 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
return F_14 ( V_11 , V_6 -> V_19 ,
1 << V_6 -> V_20 ) ;
}
static int F_15 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
T_1 V_21 ;
int V_18 ;
V_18 = F_10 ( V_11 , V_6 -> V_19 , & V_21 ) ;
if ( V_18 )
return V_18 ;
return ! ! ( V_21 & ( 1 << V_6 -> V_20 ) ) ;
}
static int F_16 ( struct V_2 * V_3 , unsigned V_10 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
int V_18 ;
V_18 = V_6 -> V_7 + V_6 -> V_14 * V_10 ;
if ( V_18 > V_6 -> V_8 )
return - V_9 ;
return V_18 ;
}
static int F_17 ( struct V_2 * V_3 ,
int V_7 , int V_8 ,
unsigned * V_10 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
T_1 V_12 , V_13 ;
int V_18 ;
if ( F_3 ( V_6 , V_7 , V_8 ) ) {
F_6 ( L_1 , V_7 , V_8 ) ;
return - V_9 ;
}
V_12 = F_7 ( V_7 - V_6 -> V_7 , V_6 -> V_14 ) ;
* V_10 = V_12 ;
V_12 <<= V_6 -> V_15 ;
V_13 = ( ( 1 << V_6 -> V_16 ) - 1 ) << V_6 -> V_15 ;
V_12 |= V_23 ;
V_13 |= V_24 ;
V_18 = F_8 ( V_22 , V_6 -> V_17 , V_12 , V_13 ) ;
if ( V_18 )
return V_18 ;
return F_8 ( V_22 , V_6 -> V_17 , V_12 , V_13 ) ;
}
static int F_18 ( struct V_2 * V_3 ,
int V_7 , int V_8 ,
unsigned * V_10 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
T_1 V_12 , V_13 ;
int V_25 ;
if ( F_3 ( V_6 , V_7 , V_8 ) ) {
F_6 ( L_1 , V_7 , V_8 ) ;
return - V_9 ;
}
V_25 = ( V_6 -> V_8 + V_6 -> V_7 ) / 2 ;
if ( V_7 < V_25 ) {
V_12 = F_7 ( V_25 - V_7 , V_6 -> V_14 ) ;
V_12 |= 0x4 ;
} else {
V_12 = F_7 ( V_7 - V_25 , V_6 -> V_14 ) ;
}
* V_10 = V_12 ;
V_12 <<= V_6 -> V_15 ;
V_13 = ( ( 1 << V_6 -> V_16 ) - 1 ) << V_6 -> V_15 ;
return F_8 ( V_22 , V_6 -> V_17 , V_12 , V_13 ) ;
}
static int F_19 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
T_1 V_12 , V_13 ;
int V_18 ;
V_18 = F_10 ( V_22 , V_6 -> V_17 , & V_12 ) ;
if ( V_18 )
return V_18 ;
V_13 = ( ( 1 << V_6 -> V_16 ) - 1 ) << V_6 -> V_15 ;
V_12 = ( V_12 & V_13 ) >> V_6 -> V_15 ;
if ( V_12 & 0x4 )
return V_6 -> V_7 + V_6 -> V_14 * ( 3 - ( V_12 & ~ 0x4 ) ) ;
else
return ( V_6 -> V_8 + V_6 -> V_7 ) / 2 +
V_6 -> V_14 * ( V_12 & ~ 0x4 ) ;
}
static int F_20 ( struct V_2 * V_3 ,
int V_7 , int V_8 , unsigned * V_10 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
T_1 V_12 , V_13 ;
int V_18 ;
if ( F_3 ( V_6 , V_7 , V_8 ) ) {
F_6 ( L_1 , V_7 , V_8 ) ;
return - V_9 ;
}
V_12 = F_7 ( V_7 - V_6 -> V_7 , V_6 -> V_14 ) ;
* V_10 = V_12 ;
V_12 <<= V_6 -> V_15 ;
V_13 = ( ( 1 << V_6 -> V_16 ) - 1 ) << V_6 -> V_15 ;
V_18 = F_8 ( V_11 , V_6 -> V_17 , V_12 , V_13 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_12 ( V_11 , V_6 -> V_26 ,
1 << V_6 -> V_27 ) ;
return V_18 ;
}
static int F_21 ( struct V_2 * V_3 ,
int V_7 , int V_8 , unsigned * V_10 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
T_1 V_12 , V_13 ;
if ( F_3 ( V_6 , V_7 , V_8 ) ) {
F_6 ( L_1 , V_7 , V_8 ) ;
return - V_9 ;
}
V_12 = F_7 ( V_7 - V_6 -> V_7 , V_6 -> V_14 ) ;
V_12 = ( V_12 >= 20 ) ? V_12 - 12 : ( ( V_12 > 7 ) ? 8 : V_12 ) ;
* V_10 = V_12 ;
V_12 <<= V_6 -> V_15 ;
V_13 = ( ( 1 << V_6 -> V_16 ) - 1 ) << V_6 -> V_15 ;
return F_8 ( V_11 , V_6 -> V_17 , V_12 , V_13 ) ;
}
static int F_22 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_11 = F_1 ( V_3 ) ;
T_1 V_12 , V_13 ;
int V_18 ;
V_18 = F_10 ( V_11 , V_6 -> V_17 , & V_12 ) ;
if ( V_18 )
return V_18 ;
V_13 = ( ( 1 << V_6 -> V_16 ) - 1 ) << V_6 -> V_15 ;
V_12 = ( V_12 & V_13 ) >> V_6 -> V_15 ;
if ( V_12 >= 8 )
return 2700000 + V_6 -> V_14 * ( V_12 - 8 ) ;
return V_6 -> V_7 + V_6 -> V_14 * V_12 ;
}
static int F_23 ( struct V_2 * V_3 ,
unsigned V_10 )
{
if ( V_10 >= F_24 ( V_28 ) )
return - V_9 ;
return V_28 [ V_10 ] * 1000 ;
}
static inline struct V_5 * F_25 ( int V_29 )
{
struct V_5 * V_30 ;
int V_31 ;
for ( V_31 = 0 ; V_31 < F_24 ( V_5 ) ; V_31 ++ ) {
V_30 = & V_5 [ V_31 ] ;
if ( V_30 -> V_32 . V_29 == V_29 )
return V_30 ;
}
return NULL ;
}
static int T_2 F_26 ( struct V_33 * V_34 )
{
struct V_5 * V_30 = NULL ;
struct V_2 * V_3 ;
V_30 = F_25 ( V_34 -> V_29 ) ;
if ( V_30 == NULL ) {
F_27 ( & V_34 -> V_35 , L_2 ) ;
return - V_9 ;
}
if ( V_30 -> V_32 . V_29 == V_36 ) {
V_30 -> V_32 . V_37 = & V_38 ;
V_30 -> V_32 . V_39 = F_24 ( V_28 ) ;
}
if ( V_30 -> V_32 . V_29 == V_40 )
V_30 -> V_32 . V_37 = & V_41 ;
if ( V_30 -> V_32 . V_29 == V_42 || V_30 -> V_32 . V_29 == V_43 )
V_30 -> V_32 . V_37 = & V_44 ;
V_3 = F_28 ( & V_30 -> V_32 , & V_34 -> V_35 ,
V_34 -> V_35 . V_45 , V_30 , NULL ) ;
if ( F_29 ( V_3 ) ) {
F_27 ( & V_34 -> V_35 , L_3 ,
V_30 -> V_32 . V_46 ) ;
return F_30 ( V_3 ) ;
}
F_31 ( V_34 , V_3 ) ;
return 0 ;
}
static int T_3 F_32 ( struct V_33 * V_34 )
{
struct V_2 * V_3 = F_33 ( V_34 ) ;
F_34 ( V_3 ) ;
return 0 ;
}
static int T_4 F_35 ( void )
{
return F_36 ( & V_47 ) ;
}
static void T_5 F_37 ( void )
{
F_38 ( & V_47 ) ;
}
