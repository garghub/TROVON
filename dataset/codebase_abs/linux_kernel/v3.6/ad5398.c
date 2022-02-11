static int F_1 ( struct V_1 * V_2 ,
unsigned V_3 )
{
unsigned V_4 = V_2 -> V_5 - V_2 -> V_6 ;
return V_2 -> V_6 + ( V_3 * V_4 / V_2 -> V_7 ) ;
}
static int F_2 ( struct V_8 * V_9 , unsigned short * V_10 )
{
unsigned short V_11 ;
int V_12 ;
V_12 = F_3 ( V_9 , ( char * ) & V_11 , 2 ) ;
if ( V_12 < 0 ) {
F_4 ( & V_9 -> V_13 , L_1 ) ;
return V_12 ;
}
* V_10 = F_5 ( V_11 ) ;
return V_12 ;
}
static int F_6 ( struct V_8 * V_9 , const unsigned short V_10 )
{
unsigned short V_11 ;
int V_12 ;
V_11 = F_7 ( V_10 ) ;
V_12 = F_8 ( V_9 , ( char * ) & V_11 , 2 ) ;
if ( V_12 < 0 )
F_4 ( & V_9 -> V_13 , L_2 ) ;
return V_12 ;
}
static int F_9 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned short V_10 ;
int V_12 ;
V_12 = F_2 ( V_9 , & V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
V_12 = ( V_10 & V_2 -> V_16 ) >> V_2 -> V_17 ;
return F_1 ( V_2 , V_12 ) ;
}
static int F_11 ( struct V_14 * V_15 , int V_6 , int V_5 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned V_4 = V_2 -> V_5 - V_2 -> V_6 ;
unsigned V_3 ;
unsigned short V_10 ;
int V_12 ;
if ( V_6 < V_2 -> V_6 )
V_6 = V_2 -> V_6 ;
if ( V_5 > V_2 -> V_5 )
V_5 = V_2 -> V_5 ;
if ( V_6 > V_2 -> V_5 || V_5 < V_2 -> V_6 )
return - V_18 ;
V_3 = F_12 ( ( V_6 - V_2 -> V_6 ) * V_2 -> V_7 ,
V_4 ) ;
if ( F_1 ( V_2 , V_3 ) > V_5 )
return - V_18 ;
F_13 ( & V_9 -> V_13 , L_3 ,
F_1 ( V_2 , V_3 ) ) ;
V_12 = F_2 ( V_9 , & V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
V_3 = ( V_3 << V_2 -> V_17 ) & V_2 -> V_16 ;
V_10 = ( unsigned short ) V_3 | ( V_10 & V_19 ) ;
V_12 = F_6 ( V_9 , V_10 ) ;
return V_12 ;
}
static int F_14 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned short V_10 ;
int V_12 ;
V_12 = F_2 ( V_9 , & V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_10 & V_19 )
return 1 ;
else
return 0 ;
}
static int F_15 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned short V_10 ;
int V_12 ;
V_12 = F_2 ( V_9 , & V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( V_10 & V_19 )
return 0 ;
V_10 |= V_19 ;
V_12 = F_6 ( V_9 , V_10 ) ;
return V_12 ;
}
static int F_16 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_10 ( V_15 ) ;
struct V_8 * V_9 = V_2 -> V_9 ;
unsigned short V_10 ;
int V_12 ;
V_12 = F_2 ( V_9 , & V_10 ) ;
if ( V_12 < 0 )
return V_12 ;
if ( ! ( V_10 & V_19 ) )
return 0 ;
V_10 &= ~ V_19 ;
V_12 = F_6 ( V_9 , V_10 ) ;
return V_12 ;
}
static int T_1 F_17 ( struct V_8 * V_9 ,
const struct V_20 * V_21 )
{
struct V_22 * V_23 = V_9 -> V_13 . V_24 ;
struct V_25 V_26 = { } ;
struct V_1 * V_2 ;
const struct V_27 * V_28 =
(struct V_27 * ) V_21 -> V_29 ;
int V_12 ;
if ( ! V_23 )
return - V_18 ;
V_2 = F_18 ( & V_9 -> V_13 , sizeof( * V_2 ) , V_30 ) ;
if ( ! V_2 )
return - V_31 ;
V_26 . V_13 = & V_9 -> V_13 ;
V_26 . V_23 = V_23 ;
V_26 . V_29 = V_2 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_6 = V_28 -> V_6 ;
V_2 -> V_5 = V_28 -> V_5 ;
V_2 -> V_7 = 1 << V_28 -> V_32 ;
V_2 -> V_17 = V_28 -> V_17 ;
V_2 -> V_16 = ( V_2 -> V_7 - 1 ) << V_2 -> V_17 ;
V_2 -> V_15 = F_19 ( & V_33 , & V_26 ) ;
if ( F_20 ( V_2 -> V_15 ) ) {
V_12 = F_21 ( V_2 -> V_15 ) ;
F_4 ( & V_9 -> V_13 , L_4 ,
V_21 -> V_34 , V_33 . V_34 ) ;
goto V_35;
}
F_22 ( V_9 , V_2 ) ;
F_13 ( & V_9 -> V_13 , L_5 , V_21 -> V_34 ) ;
return 0 ;
V_35:
return V_12 ;
}
static int T_2 F_23 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_24 ( V_9 ) ;
F_25 ( V_2 -> V_15 ) ;
return 0 ;
}
static int T_3 F_26 ( void )
{
return F_27 ( & V_36 ) ;
}
static void T_4 F_28 ( void )
{
F_29 ( & V_36 ) ;
}
