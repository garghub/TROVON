static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
return F_3 ( V_5 -> V_6 , V_7 + V_3 ,
V_8 , V_8 ) ;
}
static int F_4 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
unsigned int V_9 ;
int V_10 ;
V_10 = F_5 ( V_5 -> V_6 , V_7 + V_3 , & V_9 ) ;
if ( V_10 < 0 )
return V_10 ;
if ( V_9 & V_11 )
return 1 ;
else
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
unsigned V_3 , int V_12 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( V_12 )
V_12 = V_11 ;
return F_3 ( V_5 -> V_6 , V_7 + V_3 ,
V_8 | V_11 , V_12 ) ;
}
static void F_7 ( struct V_1 * V_2 , unsigned V_3 , int V_12 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( V_12 )
V_12 = V_11 ;
F_3 ( V_5 -> V_6 , V_7 + V_3 ,
V_11 , V_12 ) ;
}
static int F_8 ( struct V_13 * V_14 )
{
struct V_5 * V_5 = F_9 ( V_14 -> V_15 . V_16 ) ;
struct V_17 * V_18 = F_10 ( V_5 -> V_15 ) ;
struct V_4 * V_4 ;
int V_10 ;
V_4 = F_11 ( & V_14 -> V_15 , sizeof( * V_4 ) ,
V_19 ) ;
if ( ! V_4 )
return - V_20 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_1 = V_21 ;
V_4 -> V_1 . V_16 = & V_14 -> V_15 ;
#ifdef F_12
V_4 -> V_1 . V_22 = V_5 -> V_15 -> V_22 ;
#endif
switch ( V_5 -> type ) {
case V_23 :
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
V_4 -> V_1 . V_29 = 5 ;
break;
case V_30 :
case V_31 :
V_4 -> V_1 . V_29 = 2 ;
break;
default:
F_13 ( & V_14 -> V_15 , L_1 ,
V_5 -> type ) ;
return - V_32 ;
}
if ( V_18 && V_18 -> V_33 )
V_4 -> V_1 . V_34 = V_18 -> V_33 ;
else
V_4 -> V_1 . V_34 = - 1 ;
V_10 = F_14 ( & V_14 -> V_15 , & V_4 -> V_1 ,
V_4 ) ;
if ( V_10 < 0 ) {
F_13 ( & V_14 -> V_15 , L_2 ,
V_10 ) ;
return V_10 ;
}
return 0 ;
}
