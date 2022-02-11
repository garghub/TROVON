static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
return F_2 ( V_2 , V_3 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
return ( int ) F_4 ( V_2 ) ;
}
static int F_5 ( struct V_1 * V_2 , unsigned V_4 )
{
T_1 V_5 [ 2 ] = { V_4 & 0xff , V_4 >> 8 , } ;
int V_6 ;
V_6 = F_6 ( V_2 , V_5 , 2 ) ;
return ( V_6 < 0 ) ? V_6 : 0 ;
}
static int F_7 ( struct V_1 * V_2 )
{
T_1 V_5 [ 2 ] ;
int V_6 ;
V_6 = F_8 ( V_2 , V_5 , 2 ) ;
if ( V_6 < 0 )
return V_6 ;
return ( V_5 [ 1 ] << 8 ) | V_5 [ 0 ] ;
}
static int F_9 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_11 = F_10 ( V_8 , struct V_10 , V_8 ) ;
int V_6 ;
F_11 ( & V_11 -> V_12 ) ;
V_11 -> V_13 |= ( 1 << V_9 ) ;
V_6 = V_11 -> V_14 ( V_11 -> V_2 , V_11 -> V_13 ) ;
F_12 ( & V_11 -> V_12 ) ;
return V_6 ;
}
static int F_13 ( struct V_7 * V_8 , unsigned V_9 )
{
struct V_10 * V_11 = F_10 ( V_8 , struct V_10 , V_8 ) ;
int V_15 ;
V_15 = V_11 -> V_16 ( V_11 -> V_2 ) ;
return ( V_15 < 0 ) ? 0 : ( V_15 & ( 1 << V_9 ) ) ;
}
static int F_14 ( struct V_7 * V_8 , unsigned V_9 , int V_15 )
{
struct V_10 * V_11 = F_10 ( V_8 , struct V_10 , V_8 ) ;
unsigned V_17 = 1 << V_9 ;
int V_6 ;
F_11 ( & V_11 -> V_12 ) ;
if ( V_15 )
V_11 -> V_13 |= V_17 ;
else
V_11 -> V_13 &= ~ V_17 ;
V_6 = V_11 -> V_14 ( V_11 -> V_2 , V_11 -> V_13 ) ;
F_12 ( & V_11 -> V_12 ) ;
return V_6 ;
}
static void F_15 ( struct V_7 * V_8 , unsigned V_9 , int V_15 )
{
F_14 ( V_8 , V_9 , V_15 ) ;
}
static int F_16 ( struct V_1 * V_2 ,
const struct V_18 * V_19 )
{
struct V_20 * V_21 ;
struct V_10 * V_11 ;
int V_6 ;
V_21 = V_2 -> V_22 . V_23 ;
if ( ! V_21 ) {
F_17 ( & V_2 -> V_22 , L_1 ) ;
}
V_11 = F_18 ( sizeof *V_11 , V_24 ) ;
if ( ! V_11 )
return - V_25 ;
F_19 ( & V_11 -> V_12 ) ;
V_11 -> V_8 . V_26 = V_21 ? V_21 -> V_27 : - 1 ;
V_11 -> V_8 . V_28 = 1 ;
V_11 -> V_8 . V_22 = & V_2 -> V_22 ;
V_11 -> V_8 . V_29 = V_30 ;
V_11 -> V_8 . V_31 = F_13 ;
V_11 -> V_8 . V_32 = F_15 ;
V_11 -> V_8 . V_33 = F_9 ;
V_11 -> V_8 . V_34 = F_14 ;
V_11 -> V_8 . V_35 = V_19 -> V_36 ;
if ( V_11 -> V_8 . V_35 == 8 ) {
V_11 -> V_14 = F_1 ;
V_11 -> V_16 = F_3 ;
if ( ! F_20 ( V_2 -> V_37 ,
V_38 ) )
V_6 = - V_39 ;
else
V_6 = F_4 ( V_2 ) ;
} else if ( V_11 -> V_8 . V_35 == 16 ) {
V_11 -> V_14 = F_5 ;
V_11 -> V_16 = F_7 ;
if ( ! F_20 ( V_2 -> V_37 , V_40 ) )
V_6 = - V_39 ;
else
V_6 = F_7 ( V_2 ) ;
} else {
F_17 ( & V_2 -> V_22 , L_2 ) ;
V_6 = - V_41 ;
}
if ( V_6 < 0 )
goto V_42;
V_11 -> V_8 . V_43 = V_2 -> V_44 ;
V_11 -> V_2 = V_2 ;
F_21 ( V_2 , V_11 ) ;
V_11 -> V_13 = V_21 ? ~ V_21 -> V_45 : ~ 0 ;
V_6 = F_22 ( & V_11 -> V_8 ) ;
if ( V_6 < 0 )
goto V_42;
F_23 ( & V_2 -> V_22 , L_3 ,
V_2 -> V_46 ? L_4 : L_5 ) ;
if ( V_21 && V_21 -> V_47 ) {
V_6 = V_21 -> V_47 ( V_2 ,
V_11 -> V_8 . V_26 , V_11 -> V_8 . V_35 ,
V_21 -> V_48 ) ;
if ( V_6 < 0 )
F_24 ( & V_2 -> V_22 , L_6 , V_6 ) ;
}
return 0 ;
V_42:
F_17 ( & V_2 -> V_22 , L_7 ,
V_6 , V_2 -> V_44 ) ;
F_25 ( V_11 ) ;
return V_6 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_22 . V_23 ;
struct V_10 * V_11 = F_27 ( V_2 ) ;
int V_6 = 0 ;
if ( V_21 && V_21 -> V_49 ) {
V_6 = V_21 -> V_49 ( V_2 ,
V_11 -> V_8 . V_26 , V_11 -> V_8 . V_35 ,
V_21 -> V_48 ) ;
if ( V_6 < 0 ) {
F_28 ( & V_2 -> V_22 , L_8 ,
L_9 , V_6 ) ;
return V_6 ;
}
}
V_6 = F_29 ( & V_11 -> V_8 ) ;
if ( V_6 == 0 )
F_25 ( V_11 ) ;
else
F_28 ( & V_2 -> V_22 , L_8 , L_10 , V_6 ) ;
return V_6 ;
}
static int T_2 F_30 ( void )
{
return F_31 ( & V_50 ) ;
}
static void T_3 F_32 ( void )
{
F_33 ( & V_50 ) ;
}
