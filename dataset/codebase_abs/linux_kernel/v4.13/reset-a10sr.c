static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static inline int F_3 ( unsigned long V_5 )
{
switch ( V_5 ) {
case V_6 :
return 1 ;
case V_7 :
case V_8 :
case V_9 :
case V_10 :
return V_5 + 11 ;
default:
return - V_11 ;
}
}
static int F_4 ( struct V_2 * V_4 ,
unsigned long V_5 , bool assert )
{
struct V_1 * V_12 = F_1 ( V_4 ) ;
int V_13 = F_3 ( V_5 ) ;
T_1 V_14 = F_5 ( V_13 ) ;
int V_15 = V_16 + F_6 ( V_13 ) ;
return F_7 ( V_12 -> V_17 , V_15 , V_14 , assert ? 0 : V_14 ) ;
}
static int F_8 ( struct V_2 * V_4 ,
unsigned long V_5 )
{
return F_4 ( V_4 , V_5 , true ) ;
}
static int F_9 ( struct V_2 * V_4 ,
unsigned long V_5 )
{
return F_4 ( V_4 , V_5 , false ) ;
}
static int F_10 ( struct V_2 * V_4 ,
unsigned long V_5 )
{
int V_18 ;
struct V_1 * V_12 = F_1 ( V_4 ) ;
int V_13 = F_3 ( V_5 ) ;
T_1 V_14 = F_5 ( V_13 ) ;
int V_15 = V_16 + F_6 ( V_13 ) ;
unsigned int V_19 ;
V_18 = F_11 ( V_12 -> V_17 , V_15 , & V_19 ) ;
if ( V_18 < 0 )
return V_18 ;
return ! ! ( V_19 & V_14 ) ;
}
static int F_12 ( struct V_20 * V_21 )
{
struct V_22 * V_23 = F_13 ( V_21 -> V_24 . V_25 ) ;
struct V_1 * V_12 ;
V_12 = F_14 ( & V_21 -> V_24 , sizeof( struct V_1 ) ,
V_26 ) ;
if ( ! V_12 )
return - V_27 ;
V_12 -> V_4 . V_28 = V_29 ;
V_12 -> V_4 . V_30 = V_31 ;
V_12 -> V_4 . V_32 = & V_33 ;
V_12 -> V_4 . V_34 = V_21 -> V_24 . V_34 ;
V_12 -> V_17 = V_23 -> V_17 ;
F_15 ( V_21 , V_12 ) ;
return F_16 ( & V_21 -> V_24 , & V_12 -> V_4 ) ;
}
