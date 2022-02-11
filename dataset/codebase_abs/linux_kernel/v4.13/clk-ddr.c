static int F_1 ( struct V_1 * V_2 , unsigned long V_3 ,
unsigned long V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
unsigned long V_7 ;
struct V_8 V_9 ;
F_3 ( V_6 -> V_10 , V_7 ) ;
F_4 ( V_11 , V_3 , 0 ,
V_12 ,
0 , 0 , 0 , 0 , & V_9 ) ;
F_5 ( V_6 -> V_10 , V_7 ) ;
return V_9 . V_13 ;
}
static unsigned long
F_6 ( struct V_1 * V_2 ,
unsigned long V_14 )
{
struct V_8 V_9 ;
F_4 ( V_11 , 0 , 0 ,
V_15 ,
0 , 0 , 0 , 0 , & V_9 ) ;
return V_9 . V_13 ;
}
static long F_7 ( struct V_1 * V_2 ,
unsigned long V_16 ,
unsigned long * V_4 )
{
struct V_8 V_9 ;
F_4 ( V_11 , V_16 , 0 ,
V_17 ,
0 , 0 , 0 , 0 , & V_9 ) ;
return V_9 . V_13 ;
}
static T_1 F_8 ( struct V_1 * V_2 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
int V_18 = F_9 ( V_2 ) ;
T_2 V_19 ;
V_19 = F_10 ( V_6 -> V_20 +
V_6 -> V_21 ) >> V_6 -> V_22 ;
V_19 &= F_11 ( V_6 -> V_23 - 1 , 0 ) ;
if ( V_19 >= V_18 )
return - V_24 ;
return V_19 ;
}
struct V_25 * F_12 ( const char * V_26 , int V_7 ,
const char * const * V_27 ,
T_1 V_18 , int V_21 ,
int V_22 , int V_23 ,
int V_28 , int V_29 ,
int V_30 , void T_3 * V_20 ,
T_4 * V_10 )
{
struct V_5 * V_6 ;
struct V_31 V_32 ;
struct V_25 * V_25 ;
V_6 = F_13 ( sizeof( * V_6 ) , V_33 ) ;
if ( ! V_6 )
return F_14 ( - V_34 ) ;
V_32 . V_26 = V_26 ;
V_32 . V_27 = V_27 ;
V_32 . V_18 = V_18 ;
V_32 . V_7 = V_7 ;
V_32 . V_7 |= V_35 ;
switch ( V_30 ) {
case V_36 :
V_32 . V_37 = & V_38 ;
break;
default:
F_15 ( L_1 , V_39 , V_30 ) ;
F_16 ( V_6 ) ;
return F_14 ( - V_24 ) ;
}
V_6 -> V_20 = V_20 ;
V_6 -> V_10 = V_10 ;
V_6 -> V_2 . V_32 = & V_32 ;
V_6 -> V_21 = V_21 ;
V_6 -> V_22 = V_22 ;
V_6 -> V_23 = V_23 ;
V_6 -> V_28 = V_28 ;
V_6 -> V_29 = V_29 ;
V_6 -> V_30 = V_30 ;
V_25 = F_17 ( NULL , & V_6 -> V_2 ) ;
if ( F_18 ( V_25 ) )
F_16 ( V_6 ) ;
return V_25 ;
}
