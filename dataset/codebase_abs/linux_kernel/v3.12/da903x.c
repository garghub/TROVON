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
if ( V_3 -> V_9 -> V_15 == 1 )
return - V_10 ;
V_13 = V_11 << V_6 -> V_16 ;
V_14 = ( ( 1 << V_6 -> V_17 ) - 1 ) << V_6 -> V_16 ;
return F_6 ( V_12 , V_6 -> V_18 , V_13 , V_14 ) ;
}
static int F_7 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_13 , V_14 ;
int V_19 ;
if ( V_3 -> V_9 -> V_15 == 1 )
return 0 ;
V_19 = F_8 ( V_12 , V_6 -> V_18 , & V_13 ) ;
if ( V_19 )
return V_19 ;
V_14 = ( ( 1 << V_6 -> V_17 ) - 1 ) << V_6 -> V_16 ;
V_13 = ( V_13 & V_14 ) >> V_6 -> V_16 ;
return V_13 ;
}
static int F_9 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
return F_10 ( V_12 , V_6 -> V_20 ,
1 << V_6 -> V_21 ) ;
}
static int F_11 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
return F_12 ( V_12 , V_6 -> V_20 ,
1 << V_6 -> V_21 ) ;
}
static int F_13 ( struct V_2 * V_3 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_22 ;
int V_19 ;
V_19 = F_8 ( V_12 , V_6 -> V_20 , & V_22 ) ;
if ( V_19 )
return V_19 ;
return ! ! ( V_22 & ( 1 << V_6 -> V_21 ) ) ;
}
static int F_14 ( struct V_2 * V_3 ,
unsigned V_11 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_23 = F_1 ( V_3 ) ;
T_1 V_13 , V_14 ;
int V_19 ;
V_13 = V_11 << V_6 -> V_16 ;
V_14 = ( ( 1 << V_6 -> V_17 ) - 1 ) << V_6 -> V_16 ;
V_13 |= V_24 ;
V_14 |= V_25 ;
V_19 = F_6 ( V_23 , V_6 -> V_18 , V_13 , V_14 ) ;
if ( V_19 )
return V_19 ;
return F_6 ( V_23 , V_6 -> V_18 , V_13 , V_14 ) ;
}
static int F_15 ( struct V_2 * V_3 ,
int V_7 , int V_8 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
int V_26 , V_27 ;
if ( F_3 ( V_6 , V_7 , V_8 ) ) {
F_16 ( L_1 , V_7 , V_8 ) ;
return - V_10 ;
}
V_26 = ( V_6 -> V_8 + V_6 -> V_9 . V_7 ) / 2 ;
if ( V_7 < V_26 ) {
V_27 = F_17 ( V_26 - V_7 , V_6 -> V_9 . V_28 ) ;
V_27 |= 0x4 ;
} else {
V_27 = F_17 ( V_7 - V_26 , V_6 -> V_9 . V_28 ) ;
}
return V_27 ;
}
static int F_18 ( struct V_2 * V_3 ,
unsigned V_11 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
int V_29 ;
if ( V_11 & 0x4 )
V_29 = V_3 -> V_9 -> V_7 +
V_3 -> V_9 -> V_28 * ( 3 - ( V_11 & ~ 0x4 ) ) ;
else
V_29 = ( V_6 -> V_8 + V_3 -> V_9 -> V_7 ) / 2 +
V_3 -> V_9 -> V_28 * ( V_11 & ~ 0x4 ) ;
if ( V_29 > V_6 -> V_8 )
return - V_10 ;
return V_29 ;
}
static int F_19 ( struct V_2 * V_3 ,
unsigned V_11 )
{
struct V_5 * V_6 = F_5 ( V_3 ) ;
struct V_1 * V_12 = F_1 ( V_3 ) ;
T_1 V_13 , V_14 ;
int V_19 ;
V_13 = V_11 << V_6 -> V_16 ;
V_14 = ( ( 1 << V_6 -> V_17 ) - 1 ) << V_6 -> V_16 ;
V_19 = F_6 ( V_12 , V_6 -> V_18 , V_13 , V_14 ) ;
if ( V_19 )
return V_19 ;
V_19 = F_10 ( V_12 , V_6 -> V_30 ,
1 << V_6 -> V_31 ) ;
return V_19 ;
}
static inline struct V_5 * F_20 ( int V_32 )
{
struct V_5 * V_33 ;
int V_34 ;
for ( V_34 = 0 ; V_34 < F_21 ( V_5 ) ; V_34 ++ ) {
V_33 = & V_5 [ V_34 ] ;
if ( V_33 -> V_9 . V_32 == V_32 )
return V_33 ;
}
return NULL ;
}
static int F_22 ( struct V_35 * V_36 )
{
struct V_5 * V_33 = NULL ;
struct V_2 * V_3 ;
struct V_37 V_38 = { } ;
V_33 = F_20 ( V_36 -> V_32 ) ;
if ( V_33 == NULL ) {
F_23 ( & V_36 -> V_39 , L_2 ) ;
return - V_10 ;
}
if ( V_33 -> V_9 . V_32 == V_40 ) {
V_33 -> V_9 . V_41 = & V_42 ;
V_33 -> V_9 . V_15 = 16 ;
V_33 -> V_9 . V_43 = V_44 ;
V_33 -> V_9 . V_45 = F_21 ( V_44 ) ;
}
if ( V_33 -> V_9 . V_32 == V_46 )
V_33 -> V_9 . V_41 = & V_47 ;
if ( V_33 -> V_9 . V_32 == V_48 || V_33 -> V_9 . V_32 == V_49 )
V_33 -> V_9 . V_41 = & V_50 ;
V_38 . V_39 = & V_36 -> V_39 ;
V_38 . V_51 = F_24 ( & V_36 -> V_39 ) ;
V_38 . V_52 = V_33 ;
V_3 = F_25 ( & V_33 -> V_9 , & V_38 ) ;
if ( F_26 ( V_3 ) ) {
F_23 ( & V_36 -> V_39 , L_3 ,
V_33 -> V_9 . V_53 ) ;
return F_27 ( V_3 ) ;
}
F_28 ( V_36 , V_3 ) ;
return 0 ;
}
static int F_29 ( struct V_35 * V_36 )
{
struct V_2 * V_3 = F_30 ( V_36 ) ;
F_31 ( V_3 ) ;
return 0 ;
}
static int T_2 F_32 ( void )
{
return F_33 ( & V_54 ) ;
}
static void T_3 F_34 ( void )
{
F_35 ( & V_54 ) ;
}
