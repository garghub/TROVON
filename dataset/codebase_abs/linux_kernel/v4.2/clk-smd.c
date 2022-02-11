static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
T_1 V_4 ;
T_2 V_5 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
V_4 = F_3 ( V_9 , V_10 ) ;
V_5 = ( V_4 & V_11 ) >> V_12 ;
return V_3 / ( V_5 + 1 ) ;
}
static long F_4 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long * V_3 )
{
unsigned long div ;
unsigned long V_14 ;
unsigned long V_4 ;
if ( V_13 >= * V_3 )
return * V_3 ;
div = * V_3 / V_13 ;
if ( div > V_15 )
return * V_3 / ( V_15 + 1 ) ;
V_14 = * V_3 / div ;
V_4 = * V_3 / ( div + 1 ) ;
if ( V_14 - V_13 > V_13 - V_4 )
V_14 = V_4 ;
return V_14 ;
}
static int F_5 ( struct V_1 * V_2 , T_2 V_16 )
{
T_1 V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
if ( V_16 > 1 )
return - V_17 ;
V_4 = F_3 ( V_9 , V_10 ) & ~ V_18 ;
if ( V_16 )
V_4 |= V_18 ;
F_6 ( V_9 , V_10 , V_4 ) ;
return 0 ;
}
static T_2 F_7 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
return F_3 ( V_9 , V_10 ) & V_18 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long V_13 ,
unsigned long V_3 )
{
T_1 V_4 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_8 * V_9 = V_7 -> V_9 ;
unsigned long div = V_3 / V_13 ;
if ( V_3 % V_13 || div < 1 || div > ( V_15 + 1 ) )
return - V_17 ;
V_4 = F_3 ( V_9 , V_10 ) & ~ V_11 ;
V_4 |= ( div - 1 ) << V_12 ;
F_6 ( V_9 , V_10 , V_4 ) ;
return 0 ;
}
static struct V_19 * T_3
F_9 ( struct V_8 * V_9 , const char * V_20 ,
const char * * V_21 , T_2 V_22 )
{
struct V_6 * V_7 ;
struct V_19 * V_19 = NULL ;
struct V_23 V_24 ;
V_7 = F_10 ( sizeof( * V_7 ) , V_25 ) ;
if ( ! V_7 )
return F_11 ( - V_26 ) ;
V_24 . V_20 = V_20 ;
V_24 . V_27 = & V_28 ;
V_24 . V_21 = V_21 ;
V_24 . V_22 = V_22 ;
V_24 . V_29 = V_30 | V_31 ;
V_7 -> V_2 . V_24 = & V_24 ;
V_7 -> V_9 = V_9 ;
V_19 = F_12 ( NULL , & V_7 -> V_2 ) ;
if ( F_13 ( V_19 ) )
F_14 ( V_7 ) ;
return V_19 ;
}
void T_3 F_15 ( struct V_32 * V_33 ,
struct V_8 * V_9 )
{
struct V_19 * V_19 ;
int V_34 ;
int V_22 ;
const char * V_21 [ V_35 ] ;
const char * V_20 = V_33 -> V_20 ;
V_22 = F_16 ( V_33 ) ;
if ( V_22 <= 0 || V_22 > V_35 )
return;
for ( V_34 = 0 ; V_34 < V_22 ; V_34 ++ ) {
V_21 [ V_34 ] = F_17 ( V_33 , V_34 ) ;
if ( ! V_21 [ V_34 ] )
return;
}
F_18 ( V_33 , L_1 , & V_20 ) ;
V_19 = F_9 ( V_9 , V_20 , V_21 ,
V_22 ) ;
if ( F_13 ( V_19 ) )
return;
F_19 ( V_33 , V_36 , V_19 ) ;
}
