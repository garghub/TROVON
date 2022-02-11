static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
int V_6 ;
F_3 ( & V_5 -> V_7 ) ;
V_5 -> V_8 |= ( 1 << V_3 ) ;
V_6 = F_4 ( V_5 -> V_9 , V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_7 ) ;
return V_6 ;
}
static int F_6 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
T_1 V_10 ;
V_10 = F_7 ( V_5 -> V_9 ) ;
return ( V_10 < 0 ) ? 0 : ( V_10 & ( 1 << V_3 ) ) ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 , int V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
unsigned V_11 = 1 << V_3 ;
int V_6 ;
F_3 ( & V_5 -> V_7 ) ;
if ( V_10 )
V_5 -> V_8 |= V_11 ;
else
V_5 -> V_8 &= ~ V_11 ;
V_6 = F_4 ( V_5 -> V_9 , V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_7 ) ;
return V_6 ;
}
static void F_9 ( struct V_1 * V_2 , unsigned V_3 , int V_10 )
{
F_8 ( V_2 , V_3 , V_10 ) ;
}
static int F_10 ( struct V_12 * V_9 , T_2 V_13 )
{
T_3 V_14 [ 2 ] = { V_13 & 0xff , V_13 >> 8 , } ;
int V_6 ;
V_6 = F_11 ( V_9 , V_14 , 2 ) ;
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_12 ( struct V_12 * V_9 )
{
T_3 V_14 [ 2 ] ;
int V_6 ;
V_6 = F_13 ( V_9 , V_14 , 2 ) ;
if ( V_6 < 0 )
return V_6 ;
return ( V_14 [ 1 ] << 8 ) | V_14 [ 0 ] ;
}
static int F_14 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
int V_6 ;
F_3 ( & V_5 -> V_7 ) ;
V_5 -> V_8 |= ( 1 << V_3 ) ;
V_6 = F_10 ( V_5 -> V_9 , V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_7 ) ;
return V_6 ;
}
static int F_15 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
int V_10 ;
V_10 = F_12 ( V_5 -> V_9 ) ;
return ( V_10 < 0 ) ? 0 : ( V_10 & ( 1 << V_3 ) ) ;
}
static int F_16 ( struct V_1 * V_2 , unsigned V_3 , int V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
unsigned V_11 = 1 << V_3 ;
int V_6 ;
F_3 ( & V_5 -> V_7 ) ;
if ( V_10 )
V_5 -> V_8 |= V_11 ;
else
V_5 -> V_8 &= ~ V_11 ;
V_6 = F_10 ( V_5 -> V_9 , V_5 -> V_8 ) ;
F_5 ( & V_5 -> V_7 ) ;
return V_6 ;
}
static void F_17 ( struct V_1 * V_2 , unsigned V_3 , int V_10 )
{
F_16 ( V_2 , V_3 , V_10 ) ;
}
static int F_18 ( struct V_12 * V_9 ,
const struct V_15 * V_16 )
{
struct V_17 * V_18 ;
struct V_4 * V_5 ;
int V_6 ;
V_18 = V_9 -> V_19 . V_20 ;
if ( ! V_18 ) {
F_19 ( & V_9 -> V_19 , L_1 ) ;
}
V_5 = F_20 ( sizeof *V_5 , V_21 ) ;
if ( ! V_5 )
return - V_22 ;
F_21 ( & V_5 -> V_7 ) ;
V_5 -> V_2 . V_23 = V_18 ? V_18 -> V_24 : - 1 ;
V_5 -> V_2 . V_25 = 1 ;
V_5 -> V_2 . V_19 = & V_9 -> V_19 ;
V_5 -> V_2 . V_26 = V_27 ;
V_5 -> V_2 . V_28 = V_16 -> V_29 ;
if ( V_5 -> V_2 . V_28 == 8 ) {
V_5 -> V_2 . V_30 = F_1 ;
V_5 -> V_2 . V_31 = F_6 ;
V_5 -> V_2 . V_32 = F_8 ;
V_5 -> V_2 . V_33 = F_9 ;
if ( ! F_22 ( V_9 -> V_34 ,
V_35 ) )
V_6 = - V_36 ;
else
V_6 = F_7 ( V_9 ) ;
} else if ( V_5 -> V_2 . V_28 == 16 ) {
V_5 -> V_2 . V_30 = F_14 ;
V_5 -> V_2 . V_31 = F_15 ;
V_5 -> V_2 . V_32 = F_16 ;
V_5 -> V_2 . V_33 = F_17 ;
if ( ! F_22 ( V_9 -> V_34 , V_37 ) )
V_6 = - V_36 ;
else
V_6 = F_12 ( V_9 ) ;
} else {
F_19 ( & V_9 -> V_19 , L_2 ) ;
V_6 = - V_38 ;
}
if ( V_6 < 0 )
goto V_39;
V_5 -> V_2 . V_40 = V_9 -> V_41 ;
V_5 -> V_9 = V_9 ;
F_23 ( V_9 , V_5 ) ;
V_5 -> V_8 = V_18 ? ~ V_18 -> V_42 : ~ 0 ;
V_6 = F_24 ( & V_5 -> V_2 ) ;
if ( V_6 < 0 )
goto V_39;
F_25 ( & V_9 -> V_19 , L_3 ,
V_9 -> V_43 ? L_4 : L_5 ) ;
if ( V_18 && V_18 -> V_44 ) {
V_6 = V_18 -> V_44 ( V_9 ,
V_5 -> V_2 . V_23 , V_5 -> V_2 . V_28 ,
V_18 -> V_45 ) ;
if ( V_6 < 0 )
F_26 ( & V_9 -> V_19 , L_6 , V_6 ) ;
}
return 0 ;
V_39:
F_19 ( & V_9 -> V_19 , L_7 ,
V_6 , V_9 -> V_41 ) ;
F_27 ( V_5 ) ;
return V_6 ;
}
static int F_28 ( struct V_12 * V_9 )
{
struct V_17 * V_18 = V_9 -> V_19 . V_20 ;
struct V_4 * V_5 = F_29 ( V_9 ) ;
int V_6 = 0 ;
if ( V_18 && V_18 -> V_46 ) {
V_6 = V_18 -> V_46 ( V_9 ,
V_5 -> V_2 . V_23 , V_5 -> V_2 . V_28 ,
V_18 -> V_45 ) ;
if ( V_6 < 0 ) {
F_30 ( & V_9 -> V_19 , L_8 ,
L_9 , V_6 ) ;
return V_6 ;
}
}
V_6 = F_31 ( & V_5 -> V_2 ) ;
if ( V_6 == 0 )
F_27 ( V_5 ) ;
else
F_30 ( & V_9 -> V_19 , L_8 , L_10 , V_6 ) ;
return V_6 ;
}
static int T_4 F_32 ( void )
{
return F_33 ( & V_47 ) ;
}
static void T_5 F_34 ( void )
{
F_35 ( & V_47 ) ;
}
