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
static int F_17 ( struct V_8 * V_9 ,
const struct V_20 * V_21 )
{
struct V_22 * V_23 = F_18 ( & V_9 -> V_13 ) ;
struct V_24 V_25 = { } ;
struct V_1 * V_2 ;
const struct V_26 * V_27 =
(struct V_26 * ) V_21 -> V_28 ;
int V_12 ;
if ( ! V_23 )
return - V_18 ;
V_2 = F_19 ( & V_9 -> V_13 , sizeof( * V_2 ) , V_29 ) ;
if ( ! V_2 )
return - V_30 ;
V_25 . V_13 = & V_9 -> V_13 ;
V_25 . V_23 = V_23 ;
V_25 . V_28 = V_2 ;
V_2 -> V_9 = V_9 ;
V_2 -> V_6 = V_27 -> V_6 ;
V_2 -> V_5 = V_27 -> V_5 ;
V_2 -> V_7 = 1 << V_27 -> V_31 ;
V_2 -> V_17 = V_27 -> V_17 ;
V_2 -> V_16 = ( V_2 -> V_7 - 1 ) << V_2 -> V_17 ;
V_2 -> V_15 = F_20 ( & V_32 , & V_25 ) ;
if ( F_21 ( V_2 -> V_15 ) ) {
V_12 = F_22 ( V_2 -> V_15 ) ;
F_4 ( & V_9 -> V_13 , L_4 ,
V_21 -> V_33 , V_32 . V_33 ) ;
goto V_34;
}
F_23 ( V_9 , V_2 ) ;
F_13 ( & V_9 -> V_13 , L_5 , V_21 -> V_33 ) ;
return 0 ;
V_34:
return V_12 ;
}
static int F_24 ( struct V_8 * V_9 )
{
struct V_1 * V_2 = F_25 ( V_9 ) ;
F_26 ( V_2 -> V_15 ) ;
return 0 ;
}
static int T_1 F_27 ( void )
{
return F_28 ( & V_35 ) ;
}
static void T_2 F_29 ( void )
{
F_30 ( & V_35 ) ;
}
