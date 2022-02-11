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
V_11 = F_6 ( V_3 - V_2 -> V_3 , V_2 -> V_9 ) ;
* V_10 = V_11 ;
V_11 <<= V_2 -> V_15 ;
V_12 = ( ( 1 << V_2 -> V_16 ) - 1 ) << V_2 -> V_15 ;
return F_7 ( V_2 -> V_17 , V_2 -> V_18 , V_12 , V_11 ) ;
}
static int F_8 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned char V_11 , V_12 ;
int V_19 ;
V_19 = F_9 ( V_2 -> V_17 , V_2 -> V_18 ) ;
if ( V_19 < 0 )
return V_19 ;
V_12 = ( ( 1 << V_2 -> V_16 ) - 1 ) << V_2 -> V_15 ;
V_11 = ( V_19 & V_12 ) >> V_2 -> V_15 ;
return F_2 ( V_7 , V_11 ) ;
}
static int F_10 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
return F_7 ( V_2 -> V_17 , V_2 -> V_20 ,
V_21 << V_22 |
V_23 << V_24 ,
V_25 << V_22 |
V_26 << V_24 ) ;
}
static int F_11 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
return F_7 ( V_2 -> V_17 , V_2 -> V_20 ,
V_21 << V_22 |
V_23 << V_24 ,
V_25 << V_22 ) ;
}
static int F_12 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
int V_27 , V_19 ;
V_19 = F_9 ( V_2 -> V_17 , V_2 -> V_20 ) ;
if ( V_19 < 0 )
return V_19 ;
V_27 = ( V_19 >> V_22 ) & V_21 ;
if ( V_27 != V_25 )
return 1 ;
else
return V_19 & ( V_23 << V_24 ) ;
}
static int F_13 ( struct V_6 * V_7 , int V_28 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
unsigned char V_11 , V_12 ;
if ( V_28 < V_29 || V_28 > V_30 )
return - V_5 ;
V_11 = F_6 ( V_28 - V_29 , V_31 ) ;
V_11 <<= V_32 ;
V_12 = 3 << V_32 ;
return F_7 ( V_2 -> V_17 , V_2 -> V_20 , V_12 , V_11 ) ;
}
static int F_14 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
return F_7 ( V_2 -> V_17 , V_2 -> V_18 , 1 << V_33 ,
1 << V_33 ) ;
}
static int F_15 ( struct V_6 * V_7 )
{
struct V_1 * V_2 = F_3 ( V_7 ) ;
return F_7 ( V_2 -> V_17 , V_2 -> V_18 , 1 << V_33 , 0 ) ;
}
static struct V_1 * T_1 F_16 ( int V_34 )
{
struct V_1 * V_35 ;
int V_36 ;
for ( V_36 = 0 ; V_36 < F_17 ( V_1 ) ; V_36 ++ ) {
V_35 = & V_1 [ V_36 ] ;
if ( V_35 -> V_37 . V_34 == V_34 )
return V_35 ;
}
return NULL ;
}
static int T_1 F_18 ( struct V_38 * V_39 )
{
struct V_40 * V_13 = F_19 ( V_39 -> V_14 . V_41 ) ;
struct V_42 * V_43 = V_13 -> V_14 -> V_44 ;
struct V_1 * V_35 ;
struct V_6 * V_7 ;
V_35 = F_16 ( V_39 -> V_34 ) ;
if ( V_35 == NULL ) {
F_5 ( & V_39 -> V_14 , L_2 ) ;
return - V_5 ;
}
V_35 -> V_17 = V_13 -> V_17 ;
V_35 -> V_13 = V_13 ;
V_7 = F_20 ( & V_35 -> V_37 , & V_39 -> V_14 ,
V_43 -> V_45 [ V_39 -> V_34 ] , V_35 , NULL ) ;
if ( F_21 ( V_7 ) ) {
F_5 ( & V_39 -> V_14 , L_3 ,
V_35 -> V_37 . V_46 ) ;
return F_22 ( V_7 ) ;
}
F_23 ( V_39 , V_7 ) ;
return 0 ;
}
static int T_2 F_24 ( struct V_38 * V_39 )
{
struct V_6 * V_7 = F_25 ( V_39 ) ;
F_23 ( V_39 , NULL ) ;
F_26 ( V_7 ) ;
return 0 ;
}
static int T_3 F_27 ( void )
{
return F_28 ( & V_47 ) ;
}
static void T_4 F_29 ( void )
{
F_30 ( & V_47 ) ;
}
