static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 ) -> V_4 -> V_4 ;
}
static inline int F_3 ( struct V_5 * V_6 ,
int V_7 , int V_8 )
{
if ( V_7 < V_6 -> V_9 . V_7 || V_7 > V_6 -> V_8 )
return - V_10 ;
return 0 ;
}
static int F_4 ( struct V_2 * V_3 , unsigned V_11 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_13 , V_14 ;
V_13 = V_11 << V_6 -> V_15 ;
V_14 = ( ( 1 << V_6 -> V_16 ) - 1 ) << V_6 -> V_15 ;
return F_6 ( V_12 , V_6 -> V_17 , V_13 , V_14 ) ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_13 , V_14 ;
int V_18 ;
V_18 = F_8 ( V_12 , V_6 -> V_17 , & V_13 ) ;
if ( V_18 )
return V_18 ;
V_14 = ( ( 1 << V_6 -> V_16 ) - 1 ) << V_6 -> V_15 ;
V_13 = ( V_13 & V_14 ) >> V_6 -> V_15 ;
return V_13 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
return F_10 ( V_12 , V_6 -> V_19 ,
1 << V_6 -> V_20 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
return F_12 ( V_12 , V_6 -> V_19 ,
1 << V_6 -> V_20 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_21 ;
int V_18 ;
V_18 = F_8 ( V_12 , V_6 -> V_19 , & V_21 ) ;
if ( V_18 )
return V_18 ;
return ! ! ( V_21 & ( 1 << V_6 -> V_20 ) ) ;
}
static int F_14 ( struct V_2 * V_3 ,
unsigned V_11 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_22 = F_1 ( V_3 ) ;
T_1 V_13 , V_14 ;
int V_18 ;
V_13 = V_11 << V_6 -> V_15 ;
V_14 = ( ( 1 << V_6 -> V_16 ) - 1 ) << V_6 -> V_15 ;
V_13 |= V_23 ;
V_14 |= V_24 ;
V_18 = F_6 ( V_22 , V_6 -> V_17 , V_13 , V_14 ) ;
if ( V_18 )
return V_18 ;
return F_6 ( V_22 , V_6 -> V_17 , V_13 , V_14 ) ;
}
static int F_15 ( struct V_2 * V_3 ,
int V_7 , int V_8 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
int V_25 , V_26 ;
if ( F_3 ( V_6 , V_7 , V_8 ) ) {
F_16 ( L_1 , V_7 , V_8 ) ;
return - V_10 ;
}
V_25 = ( V_6 -> V_8 + V_6 -> V_9 . V_7 ) / 2 ;
if ( V_7 < V_25 ) {
V_26 = F_17 ( V_25 - V_7 , V_6 -> V_9 . V_27 ) ;
V_26 |= 0x4 ;
} else {
V_26 = F_17 ( V_7 - V_25 , V_6 -> V_9 . V_27 ) ;
}
return V_26 ;
}
static int F_18 ( struct V_2 * V_3 ,
unsigned V_11 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
int V_28 ;
if ( V_11 & 0x4 )
V_28 = V_3 -> V_9 -> V_7 +
V_3 -> V_9 -> V_27 * ( 3 - ( V_11 & ~ 0x4 ) ) ;
else
V_28 = ( V_6 -> V_8 + V_3 -> V_9 -> V_7 ) / 2 +
V_3 -> V_9 -> V_27 * ( V_11 & ~ 0x4 ) ;
if ( V_28 > V_6 -> V_8 )
return - V_10 ;
return V_28 ;
}
static int F_19 ( struct V_2 * V_3 ,
unsigned V_11 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_13 , V_14 ;
int V_18 ;
V_13 = V_11 << V_6 -> V_15 ;
V_14 = ( ( 1 << V_6 -> V_16 ) - 1 ) << V_6 -> V_15 ;
V_18 = F_6 ( V_12 , V_6 -> V_17 , V_13 , V_14 ) ;
if ( V_18 )
return V_18 ;
V_18 = F_10 ( V_12 , V_6 -> V_29 ,
1 << V_6 -> V_30 ) ;
return V_18 ;
}
static int F_20 ( struct V_2 * V_3 ,
int V_7 , int V_8 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
int V_26 ;
if ( F_3 ( V_6 , V_7 , V_8 ) ) {
F_16 ( L_1 , V_7 , V_8 ) ;
return - V_10 ;
}
V_26 = F_17 ( V_7 - V_6 -> V_9 . V_7 , V_6 -> V_9 . V_27 ) ;
V_26 = ( V_26 >= 20 ) ? V_26 - 12 : ( ( V_26 > 7 ) ? 8 : V_26 ) ;
return V_26 ;
}
static int F_21 ( struct V_2 * V_3 ,
unsigned V_11 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
int V_28 ;
if ( V_11 >= 8 )
V_28 = 2700000 + V_3 -> V_9 -> V_27 * ( V_11 - 8 ) ;
else
V_28 = V_3 -> V_9 -> V_7 + V_3 -> V_9 -> V_27 * V_11 ;
if ( V_28 > V_6 -> V_8 )
return - V_10 ;
return V_28 ;
}
static inline struct V_5 * F_22 ( int V_31 )
{
struct V_5 * V_32 ;
int V_33 ;
for ( V_33 = 0 ; V_33 < F_23 ( V_5 ) ; V_33 ++ ) {
V_32 = & V_5 [ V_33 ] ;
if ( V_32 -> V_9 . V_31 == V_31 )
return V_32 ;
}
return NULL ;
}
static int T_2 F_24 ( struct V_34 * V_35 )
{
struct V_5 * V_32 = NULL ;
struct V_2 * V_3 ;
struct V_36 V_37 = { } ;
V_32 = F_22 ( V_35 -> V_31 ) ;
if ( V_32 == NULL ) {
F_25 ( & V_35 -> V_38 , L_2 ) ;
return - V_10 ;
}
if ( V_32 -> V_9 . V_31 == V_39 ) {
V_32 -> V_9 . V_40 = & V_41 ;
V_32 -> V_9 . V_42 = 16 ;
}
if ( V_32 -> V_9 . V_31 == V_43 )
V_32 -> V_9 . V_40 = & V_44 ;
if ( V_32 -> V_9 . V_31 == V_45 || V_32 -> V_9 . V_31 == V_46 )
V_32 -> V_9 . V_40 = & V_47 ;
V_37 . V_38 = & V_35 -> V_38 ;
V_37 . V_48 = V_35 -> V_38 . V_49 ;
V_37 . V_50 = V_32 ;
V_3 = F_26 ( & V_32 -> V_9 , & V_37 ) ;
if ( F_27 ( V_3 ) ) {
F_25 ( & V_35 -> V_38 , L_3 ,
V_32 -> V_9 . V_51 ) ;
return F_28 ( V_3 ) ;
}
F_29 ( V_35 , V_3 ) ;
return 0 ;
}
static int T_3 F_30 ( struct V_34 * V_35 )
{
struct V_2 * V_3 = F_31 ( V_35 ) ;
F_32 ( V_3 ) ;
return 0 ;
}
static int T_4 F_33 ( void )
{
return F_34 ( & V_52 ) ;
}
static void T_5 F_35 ( void )
{
F_36 ( & V_52 ) ;
}
