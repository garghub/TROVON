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
unsigned int V_9 , V_10 ;
int V_11 ;
V_9 = V_7 + V_3 ;
V_11 = F_5 ( V_5 -> V_6 , V_9 , & V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
if ( V_10 & V_8 ) {
V_11 = F_6 ( V_2 -> V_12 ) ;
if ( V_11 < 0 ) {
F_7 ( V_2 -> V_12 , L_1 , V_11 ) ;
return V_11 ;
}
V_11 = F_8 ( V_5 -> V_6 , V_9 , V_9 ) ;
if ( V_11 < 0 ) {
F_7 ( V_2 -> V_12 , L_2 ,
V_11 ) ;
return V_11 ;
}
V_11 = F_5 ( V_5 -> V_6 , V_9 , & V_10 ) ;
if ( V_11 < 0 )
return V_11 ;
F_9 ( V_2 -> V_12 ) ;
F_10 ( V_2 -> V_12 ) ;
}
if ( V_10 & V_13 )
return 1 ;
else
return 0 ;
}
static int F_11 ( struct V_1 * V_2 ,
unsigned V_3 , int V_14 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( V_14 )
V_14 = V_13 ;
return F_3 ( V_5 -> V_6 , V_7 + V_3 ,
V_8 | V_13 , V_14 ) ;
}
static void F_12 ( struct V_1 * V_2 , unsigned V_3 , int V_14 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( V_14 )
V_14 = V_13 ;
F_3 ( V_5 -> V_6 , V_7 + V_3 ,
V_13 , V_14 ) ;
}
static int F_13 ( struct V_15 * V_16 )
{
struct V_5 * V_5 = F_14 ( V_16 -> V_17 . V_12 ) ;
struct V_18 * V_19 = F_15 ( V_5 -> V_17 ) ;
struct V_4 * V_4 ;
int V_11 ;
V_4 = F_16 ( & V_16 -> V_17 , sizeof( * V_4 ) ,
V_20 ) ;
if ( ! V_4 )
return - V_21 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_1 = V_22 ;
V_4 -> V_1 . V_12 = & V_16 -> V_17 ;
#ifdef F_17
V_4 -> V_1 . V_23 = V_5 -> V_17 -> V_23 ;
#endif
switch ( V_5 -> type ) {
case V_24 :
case V_25 :
case V_26 :
case V_27 :
case V_28 :
case V_29 :
V_4 -> V_1 . V_30 = 5 ;
break;
case V_31 :
case V_32 :
V_4 -> V_1 . V_30 = 2 ;
break;
default:
F_7 ( & V_16 -> V_17 , L_3 ,
V_5 -> type ) ;
return - V_33 ;
}
if ( V_19 && V_19 -> V_34 )
V_4 -> V_1 . V_35 = V_19 -> V_34 ;
else
V_4 -> V_1 . V_35 = - 1 ;
V_11 = F_18 ( & V_16 -> V_17 , & V_4 -> V_1 ,
V_4 ) ;
if ( V_11 < 0 ) {
F_7 ( & V_16 -> V_17 , L_4 ,
V_11 ) ;
return V_11 ;
}
return 0 ;
}
