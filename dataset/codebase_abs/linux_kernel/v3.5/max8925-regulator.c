static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned char V_6 = V_2 -> V_7 -> V_8 - 1 ;
return F_3 ( V_5 -> V_9 , V_5 -> V_10 , V_6 , V_3 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned char V_11 , V_6 ;
int V_12 ;
V_12 = F_5 ( V_5 -> V_9 , V_5 -> V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
V_6 = V_2 -> V_7 -> V_8 - 1 ;
V_11 = V_12 & V_6 ;
return V_11 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 -> V_9 , V_5 -> V_13 ,
V_14 << V_15 |
V_16 << V_17 ,
V_18 << V_15 |
V_19 << V_17 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 -> V_9 , V_5 -> V_13 ,
V_14 << V_15 |
V_16 << V_17 ,
V_18 << V_15 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_20 , V_12 ;
V_12 = F_5 ( V_5 -> V_9 , V_5 -> V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
V_20 = ( V_12 >> V_15 ) & V_14 ;
if ( V_20 != V_18 )
return 1 ;
else
return V_12 & ( V_16 << V_17 ) ;
}
static int F_9 ( struct V_1 * V_2 , int V_21 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned char V_11 , V_6 ;
if ( V_21 < V_22 || V_21 > V_23 )
return - V_24 ;
V_11 = F_10 ( V_21 - V_22 , V_25 ) ;
V_11 <<= V_26 ;
V_6 = 3 << V_26 ;
return F_3 ( V_5 -> V_9 , V_5 -> V_13 , V_6 , V_11 ) ;
}
static int F_11 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 -> V_9 , V_5 -> V_10 , 1 << V_27 ,
1 << V_27 ) ;
}
static int F_12 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_3 ( V_5 -> V_9 , V_5 -> V_10 , 1 << V_27 , 0 ) ;
}
static struct V_4 * T_1 F_13 ( int V_28 )
{
struct V_4 * V_29 ;
int V_30 ;
for ( V_30 = 0 ; V_30 < F_14 ( V_4 ) ; V_30 ++ ) {
V_29 = & V_4 [ V_30 ] ;
if ( V_29 -> V_7 . V_28 == V_28 )
return V_29 ;
}
return NULL ;
}
static int T_1 F_15 ( struct V_31 * V_32 )
{
struct V_33 * V_34 = F_16 ( V_32 -> V_35 . V_36 ) ;
struct V_37 * V_38 = V_34 -> V_35 -> V_39 ;
struct V_40 V_41 = { } ;
struct V_4 * V_29 ;
struct V_1 * V_2 ;
V_29 = F_13 ( V_32 -> V_28 ) ;
if ( V_29 == NULL ) {
F_17 ( & V_32 -> V_35 , L_1 ) ;
return - V_24 ;
}
V_29 -> V_9 = V_34 -> V_9 ;
V_29 -> V_34 = V_34 ;
V_41 . V_35 = & V_32 -> V_35 ;
V_41 . V_42 = V_38 -> V_43 [ V_32 -> V_28 ] ;
V_41 . V_44 = V_29 ;
V_2 = F_18 ( & V_29 -> V_7 , & V_41 ) ;
if ( F_19 ( V_2 ) ) {
F_17 ( & V_32 -> V_35 , L_2 ,
V_29 -> V_7 . V_45 ) ;
return F_20 ( V_2 ) ;
}
F_21 ( V_32 , V_2 ) ;
return 0 ;
}
static int T_2 F_22 ( struct V_31 * V_32 )
{
struct V_1 * V_2 = F_23 ( V_32 ) ;
F_21 ( V_32 , NULL ) ;
F_24 ( V_2 ) ;
return 0 ;
}
static int T_3 F_25 ( void )
{
return F_26 ( & V_46 ) ;
}
static void T_4 F_27 ( void )
{
F_28 ( & V_46 ) ;
}
