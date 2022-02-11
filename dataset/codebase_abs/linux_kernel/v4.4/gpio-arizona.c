static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_2 ) ;
}
static int F_3 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
return F_4 ( V_5 -> V_6 , V_7 + V_4 ,
V_8 , V_8 ) ;
}
static int F_5 ( struct V_2 * V_3 , unsigned V_4 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
unsigned int V_9 ;
int V_10 ;
V_10 = F_6 ( V_5 -> V_6 , V_7 + V_4 , & V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_9 & V_11 )
return 1 ;
else
return 0 ;
}
static int F_7 ( struct V_2 * V_3 ,
unsigned V_4 , int V_12 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
if ( V_12 )
V_12 = V_11 ;
return F_4 ( V_5 -> V_6 , V_7 + V_4 ,
V_8 | V_11 , V_12 ) ;
}
static void F_8 ( struct V_2 * V_3 , unsigned V_4 , int V_12 )
{
struct V_1 * V_1 = F_1 ( V_3 ) ;
struct V_5 * V_5 = V_1 -> V_5 ;
if ( V_12 )
V_12 = V_11 ;
F_4 ( V_5 -> V_6 , V_7 + V_4 ,
V_11 , V_12 ) ;
}
static int F_9 ( struct V_13 * V_14 )
{
struct V_5 * V_5 = F_10 ( V_14 -> V_15 . V_16 ) ;
struct V_17 * V_18 = F_11 ( V_5 -> V_15 ) ;
struct V_1 * V_1 ;
int V_10 ;
V_1 = F_12 ( & V_14 -> V_15 , sizeof( * V_1 ) ,
V_19 ) ;
if ( ! V_1 )
return - V_20 ;
V_1 -> V_5 = V_5 ;
V_1 -> V_2 = V_21 ;
V_1 -> V_2 . V_15 = & V_14 -> V_15 ;
#ifdef F_13
V_1 -> V_2 . V_22 = V_5 -> V_15 -> V_22 ;
#endif
switch ( V_5 -> type ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
V_1 -> V_2 . V_29 = 5 ;
break;
default:
F_14 ( & V_14 -> V_15 , L_1 ,
V_5 -> type ) ;
return - V_30 ;
}
if ( V_18 && V_18 -> V_31 )
V_1 -> V_2 . V_32 = V_18 -> V_31 ;
else
V_1 -> V_2 . V_32 = - 1 ;
V_10 = F_15 ( & V_1 -> V_2 ) ;
if ( V_10 < 0 ) {
F_14 ( & V_14 -> V_15 , L_2 ,
V_10 ) ;
goto V_33;
}
F_16 ( V_14 , V_1 ) ;
return V_10 ;
V_33:
return V_10 ;
}
static int F_17 ( struct V_13 * V_14 )
{
struct V_1 * V_1 = F_18 ( V_14 ) ;
F_19 ( & V_1 -> V_2 ) ;
return 0 ;
}
