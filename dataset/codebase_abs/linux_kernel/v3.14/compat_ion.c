static int F_1 (
struct V_1 T_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
T_2 V_5 ;
T_3 V_6 ;
T_4 V_7 ;
int V_8 ;
V_8 = F_2 ( V_5 , & V_2 -> V_9 ) ;
V_8 |= F_3 ( V_5 , & V_4 -> V_9 ) ;
V_8 |= F_2 ( V_5 , & V_2 -> V_10 ) ;
V_8 |= F_3 ( V_5 , & V_4 -> V_10 ) ;
V_8 |= F_2 ( V_6 , & V_2 -> V_11 ) ;
V_8 |= F_3 ( V_6 , & V_4 -> V_11 ) ;
V_8 |= F_2 ( V_6 , & V_2 -> V_12 ) ;
V_8 |= F_3 ( V_6 , & V_4 -> V_12 ) ;
V_8 |= F_2 ( V_7 , & V_2 -> V_13 ) ;
V_8 |= F_3 ( V_7 , & V_4 -> V_13 ) ;
return V_8 ;
}
static int F_4 (
struct V_14 T_1 * V_2 ,
struct V_15 T_1 * V_4 )
{
T_4 V_7 ;
int V_8 ;
V_8 = F_2 ( V_7 , & V_2 -> V_13 ) ;
V_8 |= F_3 ( V_7 , & V_4 -> V_13 ) ;
return V_8 ;
}
static int F_5 (
struct V_1 T_1 * V_2 ,
struct V_3 T_1 * V_4 )
{
T_2 V_5 ;
T_3 V_6 ;
T_4 V_7 ;
int V_8 ;
V_8 = F_2 ( V_5 , & V_4 -> V_9 ) ;
V_8 |= F_3 ( V_5 , & V_2 -> V_9 ) ;
V_8 |= F_2 ( V_5 , & V_4 -> V_10 ) ;
V_8 |= F_3 ( V_5 , & V_2 -> V_10 ) ;
V_8 |= F_2 ( V_6 , & V_4 -> V_11 ) ;
V_8 |= F_3 ( V_6 , & V_2 -> V_11 ) ;
V_8 |= F_2 ( V_6 , & V_4 -> V_12 ) ;
V_8 |= F_3 ( V_6 , & V_2 -> V_12 ) ;
V_8 |= F_2 ( V_7 , & V_4 -> V_13 ) ;
V_8 |= F_3 ( V_7 , & V_2 -> V_13 ) ;
return V_8 ;
}
static int F_6 (
struct V_16 T_1 * V_2 ,
struct V_17 T_1 * V_4 )
{
T_3 V_18 ;
T_5 V_19 ;
int V_8 ;
V_8 = F_2 ( V_18 , & V_2 -> V_18 ) ;
V_8 |= F_3 ( V_18 , & V_4 -> V_18 ) ;
V_8 |= F_2 ( V_19 , & V_2 -> V_19 ) ;
V_8 |= F_3 ( V_19 , & V_4 -> V_19 ) ;
return V_8 ;
}
long F_7 ( struct V_20 * V_21 , unsigned int V_18 , unsigned long V_19 )
{
long V_22 ;
if ( ! V_21 -> V_23 || ! V_21 -> V_23 -> V_24 )
return - V_25 ;
switch ( V_18 ) {
case V_26 :
{
struct V_1 T_1 * V_2 ;
struct V_3 T_1 * V_4 ;
int V_8 ;
V_2 = F_8 ( V_19 ) ;
V_4 = F_9 ( sizeof( * V_4 ) ) ;
if ( V_4 == NULL )
return - V_27 ;
V_8 = F_1 ( V_2 , V_4 ) ;
if ( V_8 )
return V_8 ;
V_22 = V_21 -> V_23 -> V_24 ( V_21 , V_28 ,
( unsigned long ) V_4 ) ;
V_8 = F_5 ( V_2 , V_4 ) ;
return V_22 ? V_22 : V_8 ;
}
case V_29 :
{
struct V_14 T_1 * V_2 ;
struct V_15 T_1 * V_4 ;
int V_8 ;
V_2 = F_8 ( V_19 ) ;
V_4 = F_9 ( sizeof( * V_4 ) ) ;
if ( V_4 == NULL )
return - V_27 ;
V_8 = F_4 ( V_2 , V_4 ) ;
if ( V_8 )
return V_8 ;
return V_21 -> V_23 -> V_24 ( V_21 , V_30 ,
( unsigned long ) V_4 ) ;
}
case V_31 : {
struct V_16 T_1 * V_2 ;
struct V_17 T_1 * V_4 ;
int V_8 ;
V_2 = F_8 ( V_19 ) ;
V_4 = F_9 ( sizeof( * V_4 ) ) ;
if ( V_4 == NULL )
return - V_27 ;
V_8 = F_6 ( V_2 , V_4 ) ;
if ( V_8 )
return V_8 ;
return V_21 -> V_23 -> V_24 ( V_21 , V_32 ,
( unsigned long ) V_4 ) ;
}
case V_33 :
case V_34 :
case V_35 :
case V_36 :
return V_21 -> V_23 -> V_24 ( V_21 , V_18 ,
( unsigned long ) F_8 ( V_19 ) ) ;
default:
return - V_37 ;
}
}
