static inline unsigned int F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
return F_2 ( V_4 -> V_6 + V_3 ) ;
}
static inline int F_3 ( struct V_1 * V_2 , unsigned int V_3 ,
unsigned int V_7 )
{
struct V_4 * V_4 = V_2 -> V_5 ;
F_4 ( V_7 , V_4 -> V_6 + V_3 ) ;
return 0 ;
}
static int F_5 ( struct V_8 * V_9 , int V_10 )
{
struct V_1 * V_2 = V_9 -> V_2 ;
T_1 V_3 = F_1 ( V_2 , V_11 ) & ~ V_12 ;
if ( V_10 )
F_3 ( V_2 , V_11 ,
V_3 | V_12 ) ;
else
F_3 ( V_2 , V_11 , V_3 ) ;
return 0 ;
}
static int F_6 ( struct V_8 * V_13 ,
int V_14 , unsigned int V_15 , int V_16 )
{
struct V_1 * V_2 = V_13 -> V_2 ;
struct V_4 * V_4 = V_2 -> V_5 ;
switch ( V_15 ) {
case 22579200 :
case 27000000 :
case 33868800 :
V_4 -> V_17 . V_18 = V_15 ;
return 0 ;
}
return - V_19 ;
}
static int F_7 ( struct V_1 * V_2 ,
enum V_20 V_21 )
{
switch ( V_21 ) {
case V_22 :
F_3 ( V_2 , V_23 ,
V_24 ) ;
break;
case V_25 :
break;
case V_26 :
F_3 ( V_2 , V_23 ,
V_27 ) ;
break;
case V_28 :
F_3 ( V_2 , V_23 ,
V_27 ) ;
break;
}
V_2 -> V_29 . V_30 = V_21 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_26 ) ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_4 * V_4 = V_2 -> V_31 -> V_32 ;
V_4 -> V_17 . V_2 = V_2 ;
V_2 -> V_5 = V_4 ;
F_10 ( V_2 , V_33 ,
F_11 ( V_33 ) ) ;
F_7 ( V_2 , V_26 ) ;
return 0 ;
}
static int F_12 ( struct V_1 * V_2 )
{
F_7 ( V_2 , V_28 ) ;
return 0 ;
}
static int F_13 ( struct V_34 * V_35 )
{
return F_14 ( & V_35 -> V_31 ,
& V_36 , & V_37 , 1 ) ;
}
static int F_15 ( struct V_34 * V_35 )
{
F_16 ( & V_35 -> V_31 ) ;
return 0 ;
}
