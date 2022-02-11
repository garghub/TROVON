static int F_1 ( struct V_1 * V_2 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
V_6 = F_3 ( V_5 -> V_8 , V_9 , & V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
return ! ! ( V_7 & F_4 ( V_3 ) ) ;
}
static void F_5 ( struct V_1 * V_2 , unsigned int V_3 ,
int V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_6 ( V_5 -> V_8 , V_11 ,
F_4 ( V_3 ) , V_10 ? F_4 ( V_3 ) : 0 ) ;
}
static int F_7 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
int V_6 , V_7 ;
V_6 = F_3 ( V_5 -> V_8 , V_12 , & V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
return ! ( V_7 & F_4 ( V_3 ) ) ;
}
static int F_8 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
return F_6 ( V_5 -> V_8 ,
V_12 ,
F_4 ( V_3 ) , 0 ) ;
}
static int F_9 ( struct V_1 * V_2 ,
unsigned int V_3 , int V_10 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
F_5 ( V_2 , V_3 , V_10 ) ;
return F_6 ( V_5 -> V_8 ,
V_12 ,
F_4 ( V_3 ) , F_4 ( V_3 ) ) ;
}
static int F_10 ( struct V_1 * V_13 , unsigned int V_3 )
{
struct V_4 * V_5 = F_2 ( V_13 ) ;
int V_6 ;
switch ( V_3 ) {
case 0 :
case 1 :
case 2 :
V_6 = F_6 ( V_5 -> V_8 ,
V_14 ,
F_4 ( V_3 ) , F_4 ( V_3 ) ) ;
if ( V_6 )
return V_6 ;
break;
default:
return - V_15 ;
}
return 0 ;
}
static int F_11 ( struct V_1 * V_13 , unsigned int V_3 ,
unsigned long V_16 )
{
struct V_4 * V_5 = F_2 ( V_13 ) ;
switch ( F_12 ( V_16 ) ) {
case V_17 :
return F_6 ( V_5 -> V_8 ,
V_12 ,
F_4 ( V_3 +
F_13 ( V_18 ) ) ,
F_4 ( V_3 +
F_13 ( V_18 ) ) ) ;
case V_19 :
return F_6 ( V_5 -> V_8 ,
V_12 ,
F_4 ( V_3 +
F_13 ( V_18 ) ) , 0 ) ;
default:
return - V_20 ;
}
}
static int F_14 ( struct V_21 * V_22 )
{
struct V_4 * V_5 ;
struct V_23 * V_23 ;
int V_6 ;
V_5 = F_15 ( & V_22 -> V_24 , sizeof( * V_5 ) , V_25 ) ;
if ( ! V_5 )
return - V_26 ;
V_23 = F_16 ( V_22 -> V_24 . V_27 ) ;
V_5 -> V_2 = V_28 ;
V_5 -> V_2 . V_27 = V_23 -> V_24 ;
V_5 -> V_8 = V_23 -> V_29 ;
V_6 = F_17 ( & V_22 -> V_24 , & V_5 -> V_2 , V_5 ) ;
if ( V_6 < 0 ) {
F_18 ( & V_22 -> V_24 , L_1 , V_6 ) ;
return V_6 ;
}
return 0 ;
}
