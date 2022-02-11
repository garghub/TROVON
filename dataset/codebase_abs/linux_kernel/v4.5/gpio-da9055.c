static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 = 0 ;
int V_7 ;
V_7 = F_3 ( V_5 -> V_8 , ( V_3 >> 1 ) + V_9 ) ;
if ( V_7 < 0 )
return V_7 ;
V_6 = V_7 & ( V_10 ) << F_4 ( V_3 ) ;
V_6 >>= F_4 ( V_3 ) ;
switch ( V_6 ) {
case V_11 :
V_7 = F_3 ( V_5 -> V_8 , V_12 ) ;
if ( V_7 < 0 )
return V_7 ;
break;
case V_13 :
V_7 = F_3 ( V_5 -> V_8 , V_14 ) ;
if ( V_7 < 0 )
return V_7 ;
}
return V_7 & ( 1 << V_3 ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned V_3 , int V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_6 ( V_5 -> V_8 ,
V_14 ,
1 << V_3 ,
V_15 << V_3 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned char V_16 ;
V_16 = ( V_17 | V_18 )
<< F_4 ( V_3 ) ;
return F_6 ( V_5 -> V_8 , ( V_3 >> 1 ) +
V_9 ,
V_10 <<
F_4 ( V_3 ) ,
V_16 ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned V_3 , int V_15 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned char V_16 ;
int V_7 ;
V_16 = ( V_19 | V_20 )
<< F_4 ( V_3 ) ;
V_7 = F_6 ( V_5 -> V_8 , ( V_3 >> 1 ) +
V_9 ,
V_10 <<
F_4 ( V_3 ) ,
V_16 ) ;
if ( V_7 < 0 )
return V_7 ;
F_5 ( V_2 , V_3 , V_15 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 , T_1 V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
struct V_8 * V_8 = V_5 -> V_8 ;
return F_10 ( V_8 -> V_21 ,
V_22 + V_3 ) ;
}
static int F_11 ( struct V_23 * V_24 )
{
struct V_4 * V_5 ;
struct V_25 * V_26 ;
int V_7 ;
V_5 = F_12 ( & V_24 -> V_27 , sizeof( * V_5 ) , V_28 ) ;
if ( ! V_5 )
return - V_29 ;
V_5 -> V_8 = F_13 ( V_24 -> V_27 . V_30 ) ;
V_26 = F_14 ( V_5 -> V_8 -> V_27 ) ;
V_5 -> V_31 = V_32 ;
if ( V_26 && V_26 -> V_33 )
V_5 -> V_31 . V_34 = V_26 -> V_33 ;
V_7 = F_15 ( & V_5 -> V_31 , V_5 ) ;
if ( V_7 < 0 ) {
F_16 ( & V_24 -> V_27 , L_1 , V_7 ) ;
goto V_35;
}
F_17 ( V_24 , V_5 ) ;
return 0 ;
V_35:
return V_7 ;
}
static int F_18 ( struct V_23 * V_24 )
{
struct V_4 * V_5 = F_19 ( V_24 ) ;
F_20 ( & V_5 -> V_31 ) ;
return 0 ;
}
static int T_2 F_21 ( void )
{
return F_22 ( & V_36 ) ;
}
static void T_3 F_23 ( void )
{
F_24 ( & V_36 ) ;
}
