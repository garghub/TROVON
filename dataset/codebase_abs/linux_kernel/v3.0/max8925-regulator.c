static inline int F_1 ( struct V_1 * V_2 ,
int V_3 , int V_4 )
{
if ( V_3 < V_2 -> V_3 || V_3 > V_2 -> V_4 )
return - V_5 ;
return 0 ;
}
static int F_2 ( struct V_6 * V_7 , unsigned V_8 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
return V_2 -> V_3 + V_8 * V_2 -> V_9 ;
}
static int F_4 ( struct V_6 * V_7 ,
int V_3 , int V_4 , unsigned int * V_10 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned char V_11 , V_12 ;
if ( F_1 ( V_2 , V_3 , V_4 ) ) {
F_5 ( V_2 -> V_13 -> V_14 , L_1 ,
V_3 , V_4 ) ;
return - V_5 ;
}
V_11 = ( V_3 - V_2 -> V_3 + V_2 -> V_9 - 1 ) / V_2 -> V_9 ;
* V_10 = V_11 ;
V_11 <<= V_2 -> V_15 ;
V_12 = ( ( 1 << V_2 -> V_16 ) - 1 ) << V_2 -> V_15 ;
return F_6 ( V_2 -> V_17 , V_2 -> V_18 , V_12 , V_11 ) ;
}
static int F_7 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned char V_11 , V_12 ;
int V_19 ;
V_19 = F_8 ( V_2 -> V_17 , V_2 -> V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
V_12 = ( ( 1 << V_2 -> V_16 ) - 1 ) << V_2 -> V_15 ;
V_11 = ( V_19 & V_12 ) >> V_2 -> V_15 ;
return F_2 ( V_7 , V_11 ) ;
}
static int F_9 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
return F_6 ( V_2 -> V_17 , V_2 -> V_20 ,
V_21 << V_2 -> V_22 ,
V_21 << V_2 -> V_22 ) ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
return F_6 ( V_2 -> V_17 , V_2 -> V_20 ,
V_21 << V_2 -> V_22 ,
V_23 << V_2 -> V_22 ) ;
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
int V_19 ;
V_19 = F_8 ( V_2 -> V_17 , V_2 -> V_20 ) ;
if ( V_19 < 0 )
return V_19 ;
return V_19 & ( 1 << V_2 -> V_22 ) ;
}
static int F_12 ( struct V_6 * V_7 , int V_24 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned char V_11 , V_12 ;
if ( V_24 < V_25 || V_24 > V_26 )
return - V_5 ;
V_11 = ( V_24 - V_25 + V_27 - 1 ) / V_27 ;
V_11 <<= V_28 ;
V_12 = 3 << V_28 ;
return F_6 ( V_2 -> V_17 , V_2 -> V_20 , V_12 , V_11 ) ;
}
static int F_13 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
return F_6 ( V_2 -> V_17 , V_2 -> V_18 , 1 << V_29 ,
1 << V_29 ) ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
return F_6 ( V_2 -> V_17 , V_2 -> V_18 , 1 << V_29 , 0 ) ;
}
static struct V_1 * T_1 F_15 ( int V_30 )
{
struct V_1 * V_31 ;
int V_32 ;
for ( V_32 = 0 ; V_32 < F_16 ( V_1 ) ; V_32 ++ ) {
V_31 = & V_1 [ V_32 ] ;
if ( V_31 -> V_33 . V_30 == V_30 )
return V_31 ;
}
return NULL ;
}
static int T_1 F_17 ( struct V_34 * V_35 )
{
struct V_36 * V_13 = F_18 ( V_35 -> V_14 . V_37 ) ;
struct V_38 * V_39 = V_13 -> V_14 -> V_40 ;
struct V_1 * V_31 ;
struct V_6 * V_7 ;
V_31 = F_15 ( V_35 -> V_30 ) ;
if ( V_31 == NULL ) {
F_5 ( & V_35 -> V_14 , L_2 ) ;
return - V_5 ;
}
V_31 -> V_17 = V_13 -> V_17 ;
V_31 -> V_13 = V_13 ;
V_7 = F_19 ( & V_31 -> V_33 , & V_35 -> V_14 ,
V_39 -> V_41 [ V_35 -> V_30 ] , V_31 ) ;
if ( F_20 ( V_7 ) ) {
F_5 ( & V_35 -> V_14 , L_3 ,
V_31 -> V_33 . V_42 ) ;
return F_21 ( V_7 ) ;
}
F_22 ( V_35 , V_7 ) ;
return 0 ;
}
static int T_2 F_23 ( struct V_34 * V_35 )
{
struct V_6 * V_7 = F_24 ( V_35 ) ;
F_22 ( V_35 , NULL ) ;
F_25 ( V_7 ) ;
return 0 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_43 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_43 ) ;
}
