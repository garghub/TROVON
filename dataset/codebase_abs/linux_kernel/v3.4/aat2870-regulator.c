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
struct V_7 * V_8 = V_5 -> V_8 ;
return V_8 -> V_9 ( V_8 , V_5 -> V_10 , V_5 -> V_11 ,
V_3 << V_5 -> V_12 ) ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_13 ;
int V_14 ;
V_14 = V_8 -> V_15 ( V_8 , V_5 -> V_10 , & V_13 ) ;
if ( V_14 )
return V_14 ;
return ( V_13 & V_5 -> V_11 ) >> V_5 -> V_12 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
return V_8 -> V_9 ( V_8 , V_5 -> V_16 , V_5 -> V_17 ,
V_5 -> V_17 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
return V_8 -> V_9 ( V_8 , V_5 -> V_16 , V_5 -> V_17 , 0 ) ;
}
static int F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_5 -> V_8 ;
T_1 V_13 ;
int V_14 ;
V_14 = V_8 -> V_15 ( V_8 , V_5 -> V_16 , & V_13 ) ;
if ( V_14 )
return V_14 ;
return V_13 & V_5 -> V_17 ? 1 : 0 ;
}
static struct V_4 * F_8 ( int V_18 )
{
struct V_4 * V_5 = NULL ;
int V_19 ;
for ( V_19 = 0 ; V_19 < F_9 ( V_20 ) ; V_19 ++ ) {
V_5 = & V_20 [ V_19 ] ;
if ( V_5 -> V_21 . V_18 == V_18 )
break;
}
if ( V_19 == F_9 ( V_20 ) )
return NULL ;
V_5 -> V_16 = V_22 ;
V_5 -> V_23 = V_18 - V_24 ;
V_5 -> V_17 = 0x1 << V_5 -> V_23 ;
V_5 -> V_10 = ( V_18 - V_24 ) / 2 ?
V_25 : V_26 ;
V_5 -> V_12 = ( V_18 - V_24 ) % 2 ? 0 : 4 ;
V_5 -> V_11 = 0xF << V_5 -> V_12 ;
return V_5 ;
}
static int F_10 ( struct V_27 * V_28 )
{
struct V_4 * V_5 ;
struct V_1 * V_2 ;
V_5 = F_8 ( V_28 -> V_18 ) ;
if ( ! V_5 ) {
F_11 ( & V_28 -> V_29 , L_1 , V_28 -> V_18 ) ;
return - V_30 ;
}
V_5 -> V_8 = F_12 ( V_28 -> V_29 . V_31 ) ;
V_2 = F_13 ( & V_5 -> V_21 , & V_28 -> V_29 ,
V_28 -> V_29 . V_32 , V_5 , NULL ) ;
if ( F_14 ( V_2 ) ) {
F_11 ( & V_28 -> V_29 , L_2 ,
V_5 -> V_21 . V_33 ) ;
return F_15 ( V_2 ) ;
}
F_16 ( V_28 , V_2 ) ;
return 0 ;
}
static int T_2 F_17 ( struct V_27 * V_28 )
{
struct V_1 * V_2 = F_18 ( V_28 ) ;
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
