static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return V_5 -> V_6 [ V_3 ] ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_4 ( V_5 -> V_9 -> V_10 . V_11 ) ;
return V_8 -> V_12 ( V_8 , V_5 -> V_13 , V_5 -> V_14 ,
( V_3 << V_5 -> V_15 ) & V_5 -> V_14 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_4 ( V_5 -> V_9 -> V_10 . V_11 ) ;
T_1 V_16 ;
int V_17 ;
V_17 = V_8 -> V_18 ( V_8 , V_5 -> V_13 , & V_16 ) ;
if ( V_17 )
return V_17 ;
return ( V_16 & V_5 -> V_14 ) >> V_5 -> V_15 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_4 ( V_5 -> V_9 -> V_10 . V_11 ) ;
return V_8 -> V_12 ( V_8 , V_5 -> V_19 , V_5 -> V_20 ,
V_5 -> V_20 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_4 ( V_5 -> V_9 -> V_10 . V_11 ) ;
return V_8 -> V_12 ( V_8 , V_5 -> V_19 , V_5 -> V_20 , 0 ) ;
}
static int F_8 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_7 * V_8 = F_4 ( V_5 -> V_9 -> V_10 . V_11 ) ;
T_1 V_16 ;
int V_17 ;
V_17 = V_8 -> V_18 ( V_8 , V_5 -> V_19 , & V_16 ) ;
if ( V_17 )
return V_17 ;
return V_16 & V_5 -> V_20 ? 1 : 0 ;
}
static struct V_4 * F_9 ( int V_21 )
{
struct V_4 * V_5 = NULL ;
int V_22 ;
for ( V_22 = 0 ; V_22 < F_10 ( V_23 ) ; V_22 ++ ) {
V_5 = & V_23 [ V_22 ] ;
if ( V_5 -> V_24 . V_21 == V_21 )
break;
}
if ( ! V_5 )
return NULL ;
V_5 -> V_19 = V_25 ;
V_5 -> V_26 = V_21 - V_27 ;
V_5 -> V_20 = 0x1 << V_5 -> V_26 ;
V_5 -> V_13 = ( V_21 - V_27 ) / 2 ?
V_28 : V_29 ;
V_5 -> V_15 = ( V_21 - V_27 ) % 2 ? 0 : 4 ;
V_5 -> V_14 = 0xF << V_5 -> V_15 ;
return V_5 ;
}
static int F_11 ( struct V_30 * V_9 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
V_5 = F_9 ( V_9 -> V_21 ) ;
if ( ! V_5 ) {
F_12 ( & V_9 -> V_10 , L_1 , V_9 -> V_21 ) ;
return - V_31 ;
}
V_5 -> V_9 = V_9 ;
V_2 = F_13 ( & V_5 -> V_24 , & V_9 -> V_10 ,
V_9 -> V_10 . V_32 , V_5 ) ;
if ( F_14 ( V_2 ) ) {
F_12 ( & V_9 -> V_10 , L_2 ,
V_5 -> V_24 . V_33 ) ;
return F_15 ( V_2 ) ;
}
F_16 ( V_9 , V_2 ) ;
return 0 ;
}
static int T_2 F_17 ( struct V_30 * V_9 )
{
struct V_1 * V_2 = F_18 ( V_9 ) ;
F_19 ( V_2 ) ;
return 0 ;
}
static int T_3 F_20 ( void )
{
return F_21 ( & V_34 ) ;
}
static void T_4 F_22 ( void )
{
F_23 ( & V_34 ) ;
}
