static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
T_1 V_7 ;
F_3 ( V_5 -> V_8 , V_9 , & V_6 ) ;
V_7 = ( V_6 & V_10 ) >> V_11 ;
return V_3 / ( V_7 + 1 ) ;
}
static long F_4 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned long * V_3 )
{
unsigned long div ;
unsigned long V_13 ;
unsigned long V_14 ;
if ( V_12 >= * V_3 )
return * V_3 ;
div = * V_3 / V_12 ;
if ( div > V_15 )
return * V_3 / ( V_15 + 1 ) ;
V_13 = * V_3 / div ;
V_14 = * V_3 / ( div + 1 ) ;
if ( V_13 - V_12 > V_12 - V_14 )
V_13 = V_14 ;
return V_13 ;
}
static int F_5 ( struct V_1 * V_2 , T_1 V_16 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( V_16 > 1 )
return - V_17 ;
F_6 ( V_5 -> V_8 , V_9 , V_18 ,
V_16 ? V_18 : 0 ) ;
return 0 ;
}
static T_1 F_7 ( struct V_1 * V_2 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned int V_6 ;
F_3 ( V_5 -> V_8 , V_9 , & V_6 ) ;
return V_6 & V_18 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long V_12 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long div = V_3 / V_12 ;
if ( V_3 % V_12 || div < 1 || div > ( V_15 + 1 ) )
return - V_17 ;
F_6 ( V_5 -> V_8 , V_9 , V_10 ,
( div - 1 ) << V_11 ) ;
return 0 ;
}
static struct V_19 * T_2
F_9 ( struct V_8 * V_8 , const char * V_20 ,
const char * * V_21 , T_1 V_22 )
{
struct V_4 * V_5 ;
struct V_19 * V_19 = NULL ;
struct V_23 V_24 ;
V_5 = F_10 ( sizeof( * V_5 ) , V_25 ) ;
if ( ! V_5 )
return F_11 ( - V_26 ) ;
V_24 . V_20 = V_20 ;
V_24 . V_27 = & V_28 ;
V_24 . V_21 = V_21 ;
V_24 . V_22 = V_22 ;
V_24 . V_29 = V_30 | V_31 ;
V_5 -> V_2 . V_24 = & V_24 ;
V_5 -> V_8 = V_8 ;
V_19 = F_12 ( NULL , & V_5 -> V_2 ) ;
if ( F_13 ( V_19 ) )
F_14 ( V_5 ) ;
return V_19 ;
}
static void T_2 F_15 ( struct V_32 * V_33 )
{
struct V_19 * V_19 ;
unsigned int V_22 ;
const char * V_21 [ V_34 ] ;
const char * V_20 = V_33 -> V_20 ;
struct V_8 * V_8 ;
V_22 = F_16 ( V_33 ) ;
if ( V_22 == 0 || V_22 > V_34 )
return;
F_17 ( V_33 , V_21 , V_22 ) ;
F_18 ( V_33 , L_1 , & V_20 ) ;
V_8 = F_19 ( F_20 ( V_33 ) ) ;
if ( F_13 ( V_8 ) )
return;
V_19 = F_9 ( V_8 , V_20 , V_21 ,
V_22 ) ;
if ( F_13 ( V_19 ) )
return;
F_21 ( V_33 , V_35 , V_19 ) ;
}
