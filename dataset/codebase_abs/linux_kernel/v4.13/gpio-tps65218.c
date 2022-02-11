static int F_1 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
unsigned int V_6 ;
int V_7 ;
V_7 = F_3 ( V_5 -> V_8 , V_9 , & V_6 ) ;
if ( V_7 )
return V_7 ;
return ! ! ( V_6 & ( V_10 << V_3 ) ) ;
}
static void F_4 ( struct V_1 * V_2 , unsigned V_3 ,
int V_11 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
if ( V_11 )
F_5 ( V_5 , V_9 ,
V_10 << V_3 ,
V_10 << V_3 ,
V_12 ) ;
else
F_6 ( V_5 , V_9 ,
V_10 << V_3 ,
V_12 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned V_3 ,
int V_11 )
{
F_4 ( V_2 , V_3 , V_11 ) ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned V_3 )
{
return - V_13 ;
}
static int F_9 ( struct V_1 * V_2 , unsigned V_3 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
int V_7 ;
if ( F_10 ( V_2 , V_3 ) ) {
F_11 ( V_2 -> V_14 , L_1 ) ;
return - V_15 ;
}
switch ( V_3 ) {
case 0 :
if ( ! F_12 ( V_2 , V_3 ) ) {
F_11 ( V_2 -> V_14 , L_2 ) ;
return - V_15 ;
}
V_7 = F_6 ( V_5 , V_16 ,
V_17 ,
V_12 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_6 ( V_5 , V_18 ,
V_19 ,
V_12 ) ;
if ( V_7 )
return V_7 ;
break;
case 1 :
V_7 = F_6 ( V_5 , V_18 ,
V_19 ,
V_12 ) ;
if ( V_7 )
return V_7 ;
break;
case 2 :
if ( ! F_12 ( V_2 , V_3 ) ) {
F_11 ( V_2 -> V_14 , L_3 ) ;
return - V_15 ;
}
V_7 = F_6 ( V_5 , V_16 ,
V_20 ,
V_12 ) ;
if ( V_7 )
return V_7 ;
V_7 = F_6 ( V_5 , V_21 ,
V_22 ,
V_12 ) ;
if ( V_7 )
return V_7 ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_13 ( struct V_1 * V_2 , unsigned V_3 ,
unsigned long V_23 )
{
struct V_4 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_5 = V_4 -> V_5 ;
enum V_24 V_25 = F_14 ( V_23 ) ;
switch ( V_3 ) {
case 0 :
case 2 :
if ( V_25 == V_26 )
return 0 ;
return - V_27 ;
case 1 :
if ( V_25 == V_26 )
return F_6 ( V_5 ,
V_18 ,
V_28 ,
V_12 ) ;
if ( V_25 == V_29 )
return F_5 ( V_5 ,
V_18 ,
V_28 ,
V_28 ,
V_12 ) ;
return - V_27 ;
default:
break;
}
return - V_27 ;
}
static int F_15 ( struct V_30 * V_31 )
{
struct V_5 * V_5 = F_16 ( V_31 -> V_32 . V_14 ) ;
struct V_4 * V_4 ;
int V_7 ;
V_4 = F_17 ( & V_31 -> V_32 , sizeof( * V_4 ) ,
V_33 ) ;
if ( ! V_4 )
return - V_34 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_1 = V_35 ;
V_4 -> V_1 . V_14 = & V_31 -> V_32 ;
#ifdef F_18
V_4 -> V_1 . V_36 = V_31 -> V_32 . V_36 ;
#endif
V_7 = F_19 ( & V_31 -> V_32 , & V_4 -> V_1 ,
V_4 ) ;
if ( V_7 < 0 ) {
F_11 ( & V_31 -> V_32 , L_4 , V_7 ) ;
return V_7 ;
}
F_20 ( V_31 , V_4 ) ;
return V_7 ;
}
