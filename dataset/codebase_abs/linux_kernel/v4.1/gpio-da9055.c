static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static int F_3 ( struct V_2 * V_5 , unsigned V_6 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
int V_8 = 0 ;
int V_9 ;
V_9 = F_4 ( V_7 -> V_10 , ( V_6 >> 1 ) + V_11 ) ;
if ( V_9 < 0 )
return V_9 ;
V_8 = V_9 & ( V_12 ) << F_5 ( V_6 ) ;
V_8 >>= F_5 ( V_6 ) ;
switch ( V_8 ) {
case V_13 :
V_9 = F_4 ( V_7 -> V_10 , V_14 ) ;
if ( V_9 < 0 )
return V_9 ;
break;
case V_15 :
V_9 = F_4 ( V_7 -> V_10 , V_16 ) ;
if ( V_9 < 0 )
return V_9 ;
}
return V_9 & ( 1 << V_6 ) ;
}
static void F_6 ( struct V_2 * V_5 , unsigned V_6 , int V_17 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
F_7 ( V_7 -> V_10 ,
V_16 ,
1 << V_6 ,
V_17 << V_6 ) ;
}
static int F_8 ( struct V_2 * V_5 , unsigned V_6 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
unsigned char V_18 ;
V_18 = ( V_19 | V_20 )
<< F_5 ( V_6 ) ;
return F_7 ( V_7 -> V_10 , ( V_6 >> 1 ) +
V_11 ,
V_12 <<
F_5 ( V_6 ) ,
V_18 ) ;
}
static int F_9 ( struct V_2 * V_5 ,
unsigned V_6 , int V_17 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
unsigned char V_18 ;
int V_9 ;
V_18 = ( V_21 | V_22 )
<< F_5 ( V_6 ) ;
V_9 = F_7 ( V_7 -> V_10 , ( V_6 >> 1 ) +
V_11 ,
V_12 <<
F_5 ( V_6 ) ,
V_18 ) ;
if ( V_9 < 0 )
return V_9 ;
F_6 ( V_5 , V_6 , V_17 ) ;
return 0 ;
}
static int F_10 ( struct V_2 * V_5 , T_1 V_6 )
{
struct V_1 * V_7 = F_1 ( V_5 ) ;
struct V_10 * V_10 = V_7 -> V_10 ;
return F_11 ( V_10 -> V_23 ,
V_24 + V_6 ) ;
}
static int F_12 ( struct V_25 * V_26 )
{
struct V_1 * V_7 ;
struct V_27 * V_28 ;
int V_9 ;
V_7 = F_13 ( & V_26 -> V_29 , sizeof( * V_7 ) , V_30 ) ;
if ( ! V_7 )
return - V_31 ;
V_7 -> V_10 = F_14 ( V_26 -> V_29 . V_32 ) ;
V_28 = F_15 ( V_7 -> V_10 -> V_29 ) ;
V_7 -> V_4 = V_33 ;
if ( V_28 && V_28 -> V_34 )
V_7 -> V_4 . V_35 = V_28 -> V_34 ;
V_9 = F_16 ( & V_7 -> V_4 ) ;
if ( V_9 < 0 ) {
F_17 ( & V_26 -> V_29 , L_1 , V_9 ) ;
goto V_36;
}
F_18 ( V_26 , V_7 ) ;
return 0 ;
V_36:
return V_9 ;
}
static int F_19 ( struct V_25 * V_26 )
{
struct V_1 * V_7 = F_20 ( V_26 ) ;
F_21 ( & V_7 -> V_4 ) ;
return 0 ;
}
static int T_2 F_22 ( void )
{
return F_23 ( & V_37 ) ;
}
static void T_3 F_24 ( void )
{
F_25 ( & V_37 ) ;
}
