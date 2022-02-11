static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
unsigned int V_6 ;
int V_7 ;
V_7 = F_3 ( V_5 , V_8 , & V_6 ) ;
if ( V_7 )
return V_7 ;
return ! ! ( V_6 & ( V_9 << V_3 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 ,
int V_10 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( V_10 )
F_5 ( V_5 , V_8 ,
V_9 << V_3 ,
V_9 << V_3 ,
V_11 ) ;
else
F_6 ( V_5 , V_8 ,
V_9 << V_3 ,
V_11 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 ,
int V_10 )
{
F_4 ( V_2 , V_3 , V_10 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
return - V_12 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_7 ;
if ( F_10 ( V_2 , V_3 ) ) {
F_11 ( V_2 -> V_13 , L_1 ) ;
return - V_14 ;
}
switch ( V_3 ) {
case 0 :
if ( ! F_12 ( V_2 , V_3 ) ) {
F_11 ( V_2 -> V_13 , L_2 ) ;
return - V_14 ;
}
V_7 = F_6 ( V_5 , V_15 ,
V_16 ,
V_11 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_6 ( V_5 , V_17 ,
V_18 ,
V_11 ) ;
if ( V_7 )
return V_7 ;
break;
case 1 :
V_7 = F_6 ( V_5 , V_17 ,
V_18 ,
V_11 ) ;
if ( V_7 )
return V_7 ;
break;
case 2 :
if ( ! F_12 ( V_2 , V_3 ) ) {
F_11 ( V_2 -> V_13 , L_3 ) ;
return - V_14 ;
}
V_7 = F_6 ( V_5 , V_15 ,
V_19 ,
V_11 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_6 ( V_5 , V_20 ,
V_21 ,
V_11 ) ;
if ( V_7 )
return V_7 ;
break;
default:
return - V_14 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 ,
unsigned V_3 ,
enum V_22 V_23 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
switch ( V_3 ) {
case 0 :
case 2 :
if ( V_23 == V_24 )
return 0 ;
return - V_25 ;
case 1 :
if ( V_23 == V_24 )
return F_6 ( V_5 ,
V_17 ,
V_26 ,
V_11 ) ;
if ( V_23 == V_27 )
return F_5 ( V_5 ,
V_17 ,
V_26 ,
V_26 ,
V_11 ) ;
return - V_25 ;
default:
break;
}
return - V_25 ;
}
static int F_14 ( struct V_28 * V_29 )
{
struct V_5 * V_5 = F_15 ( V_29 -> V_30 . V_13 ) ;
struct V_4 * V_4 ;
int V_7 ;
V_4 = F_16 ( & V_29 -> V_30 , sizeof( * V_4 ) ,
V_31 ) ;
if ( ! V_4 )
return - V_32 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_1 = V_33 ;
V_4 -> V_1 . V_13 = & V_29 -> V_30 ;
#ifdef F_17
V_4 -> V_1 . V_34 = V_29 -> V_30 . V_34 ;
#endif
V_7 = F_18 ( & V_29 -> V_30 , & V_4 -> V_1 ,
V_4 ) ;
if ( V_7 < 0 ) {
F_11 ( & V_29 -> V_30 , L_4 , V_7 ) ;
return V_7 ;
}
F_19 ( V_29 , V_4 ) ;
return V_7 ;
}
