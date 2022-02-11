static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
return V_7 -> V_8 ( V_7 , V_5 -> V_9 , V_5 -> V_10 ,
V_3 << V_5 -> V_11 ) ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_12 ;
int V_13 ;
V_13 = V_7 -> V_14 ( V_7 , V_5 -> V_9 , & V_12 ) ;
if ( V_13 )
return V_13 ;
return ( V_12 & V_5 -> V_10 ) >> V_5 -> V_11 ;
}
static int F_4 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
return V_7 -> V_8 ( V_7 , V_5 -> V_15 , V_5 -> V_16 ,
V_5 -> V_16 ) ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
return V_7 -> V_8 ( V_7 , V_5 -> V_15 , V_5 -> V_16 , 0 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_6 * V_7 = V_5 -> V_7 ;
T_1 V_12 ;
int V_13 ;
V_13 = V_7 -> V_14 ( V_7 , V_5 -> V_15 , & V_12 ) ;
if ( V_13 )
return V_13 ;
return V_12 & V_5 -> V_16 ? 1 : 0 ;
}
static struct V_4 * F_7 ( int V_17 )
{
struct V_4 * V_5 = NULL ;
int V_18 ;
for ( V_18 = 0 ; V_18 < F_8 ( V_19 ) ; V_18 ++ ) {
V_5 = & V_19 [ V_18 ] ;
if ( V_5 -> V_20 . V_17 == V_17 )
break;
}
if ( V_18 == F_8 ( V_19 ) )
return NULL ;
V_5 -> V_15 = V_21 ;
V_5 -> V_22 = V_17 - V_23 ;
V_5 -> V_16 = 0x1 << V_5 -> V_22 ;
V_5 -> V_9 = ( V_17 - V_23 ) / 2 ?
V_24 : V_25 ;
V_5 -> V_11 = ( V_17 - V_23 ) % 2 ? 0 : 4 ;
V_5 -> V_10 = 0xF << V_5 -> V_11 ;
return V_5 ;
}
static int F_9 ( struct V_26 * V_27 )
{
struct V_4 * V_5 ;
struct V_28 V_29 = { } ;
struct V_1 * V_2 ;
V_5 = F_7 ( V_27 -> V_17 ) ;
if ( ! V_5 ) {
F_10 ( & V_27 -> V_30 , L_1 , V_27 -> V_17 ) ;
return - V_31 ;
}
V_5 -> V_7 = F_11 ( V_27 -> V_30 . V_32 ) ;
V_29 . V_30 = & V_27 -> V_30 ;
V_29 . V_33 = V_5 ;
V_29 . V_34 = F_12 ( & V_27 -> V_30 ) ;
V_2 = F_13 ( & V_27 -> V_30 , & V_5 -> V_20 , & V_29 ) ;
if ( F_14 ( V_2 ) ) {
F_10 ( & V_27 -> V_30 , L_2 ,
V_5 -> V_20 . V_35 ) ;
return F_15 ( V_2 ) ;
}
F_16 ( V_27 , V_2 ) ;
return 0 ;
}
static int T_2 F_17 ( void )
{
return F_18 ( & V_36 ) ;
}
static void T_3 F_19 ( void )
{
F_20 ( & V_36 ) ;
}
