static int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
return - V_4 ;
}
static int F_3 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_5 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
return F_5 ( V_7 -> V_8 -> V_9 , V_10 ,
F_6 ( V_3 * V_11 ) ,
V_5 ? F_6 ( V_3 * V_11 ) : 0 ) ;
}
static int F_7 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
int V_12 , V_13 ;
V_12 = F_8 ( V_7 -> V_8 -> V_9 , V_10 , & V_13 ) ;
if ( V_12 < 0 )
return V_12 ;
return V_13 & F_6 ( V_3 * V_11 ) ;
}
static void F_9 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_5 )
{
struct V_6 * V_7 = F_4 ( V_2 ) ;
F_5 ( V_7 -> V_8 -> V_9 , V_10 ,
F_6 ( V_3 * V_11 ) ,
V_5 ? F_6 ( V_3 * V_11 ) : 0 ) ;
}
static int F_10 ( struct V_1 * V_14 , unsigned int V_3 )
{
struct V_6 * V_7 = F_4 ( V_14 ) ;
int V_12 ;
switch ( V_3 ) {
case 0 :
break;
case 1 :
V_12 = F_5 ( V_7 -> V_8 -> V_9 , V_15 ,
V_16 , 0 ) ;
if ( V_12 )
return V_12 ;
break;
default:
return - V_4 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_14 , unsigned V_3 ,
unsigned long V_17 )
{
struct V_6 * V_7 = F_4 ( V_14 ) ;
switch ( F_12 ( V_17 ) ) {
case V_18 :
return F_5 ( V_7 -> V_8 -> V_9 ,
V_10 ,
F_6 ( V_3 * V_11 +
V_19 ) ,
F_6 ( V_3 * V_11 +
V_19 ) ) ;
case V_20 :
return F_5 ( V_7 -> V_8 -> V_9 ,
V_10 ,
F_6 ( V_3 * V_11 +
V_19 ) , 0 ) ;
default:
return - V_21 ;
}
}
static int F_13 ( struct V_22 * V_23 )
{
struct V_6 * V_7 ;
int V_12 ;
V_7 = F_14 ( & V_23 -> V_24 , sizeof( * V_7 ) , V_25 ) ;
if ( ! V_7 )
return - V_26 ;
F_15 ( V_23 , V_7 ) ;
V_7 -> V_8 = F_16 ( V_23 -> V_24 . V_27 ) ;
V_7 -> V_2 = V_28 ;
V_7 -> V_2 . V_27 = V_7 -> V_8 -> V_24 ;
V_12 = F_17 ( & V_23 -> V_24 , & V_7 -> V_2 , V_7 ) ;
if ( V_12 < 0 ) {
F_18 ( & V_23 -> V_24 , L_1 , V_12 ) ;
return V_12 ;
}
return 0 ;
}
