static inline struct V_1 * F_1 ( struct V_2 * V_3 )
{
return F_2 ( V_3 , struct V_1 , V_4 ) ;
}
static unsigned char F_3 ( unsigned V_5 )
{
return V_5 % 2 ;
}
static int F_4 ( struct V_2 * V_6 , unsigned V_5 )
{
struct V_1 * V_7 = F_1 ( V_6 ) ;
int V_8 = 0 ;
int V_9 ;
V_9 = F_5 ( V_7 -> V_10 ,
V_11 + ( V_5 >> 1 ) ) ;
if ( V_9 < 0 )
return V_9 ;
if ( F_3 ( V_5 ) ) {
V_8 = V_9 & V_12 ;
V_8 >>= 4 ;
} else {
V_8 = V_9 & V_13 ;
}
switch ( V_8 ) {
case V_14 :
if ( V_5 < V_15 )
V_9 = F_5 ( V_7 -> V_10 ,
V_16 ) ;
else
V_9 = F_5 ( V_7 -> V_10 ,
V_17 ) ;
if ( V_9 < 0 )
return V_9 ;
if ( V_9 & ( 1 << F_6 ( V_5 ) ) )
return 1 ;
else
return 0 ;
case V_18 :
if ( F_3 ( V_5 ) )
return V_9 & V_19 ;
else
return V_9 & V_20 ;
default:
return - V_21 ;
}
}
static void F_7 ( struct V_2 * V_6 , unsigned V_5 , int V_22 )
{
struct V_1 * V_7 = F_1 ( V_6 ) ;
int V_9 ;
if ( F_3 ( V_5 ) ) {
V_9 = F_8 ( V_7 -> V_10 , ( V_5 >> 1 ) +
V_11 ,
V_19 ,
V_22 << V_23 ) ;
if ( V_9 != 0 )
F_9 ( V_7 -> V_10 -> V_24 ,
L_1 ,
V_9 ) ;
} else {
V_9 = F_8 ( V_7 -> V_10 , ( V_5 >> 1 ) +
V_11 ,
V_20 ,
V_22 << V_25 ) ;
if ( V_9 != 0 )
F_9 ( V_7 -> V_10 -> V_24 ,
L_2 ,
V_9 ) ;
}
}
static int F_10 ( struct V_2 * V_6 , unsigned V_5 )
{
struct V_1 * V_7 = F_1 ( V_6 ) ;
unsigned char V_26 ;
int V_9 ;
V_26 = V_14 | V_27 << 2 |
V_28 << 3 ;
if ( F_3 ( V_5 ) )
V_9 = F_8 ( V_7 -> V_10 , ( V_5 >> 1 ) +
V_11 ,
V_29 ,
( V_26 <<
V_30 ) ) ;
else
V_9 = F_8 ( V_7 -> V_10 , ( V_5 >> 1 ) +
V_11 ,
V_31 ,
V_26 ) ;
return V_9 ;
}
static int F_11 ( struct V_2 * V_6 ,
unsigned V_5 , int V_22 )
{
struct V_1 * V_7 = F_1 ( V_6 ) ;
unsigned char V_26 ;
int V_9 ;
V_26 = V_18 | V_32 << 2 |
V_22 << 3 ;
if ( F_3 ( V_5 ) )
V_9 = F_8 ( V_7 -> V_10 , ( V_5 >> 1 ) +
V_11 ,
V_29 ,
( V_26 <<
V_30 ) ) ;
else
V_9 = F_8 ( V_7 -> V_10 , ( V_5 >> 1 ) +
V_11 ,
V_31 ,
V_26 ) ;
return V_9 ;
}
static int F_12 ( struct V_2 * V_6 , T_1 V_5 )
{
struct V_1 * V_7 = F_1 ( V_6 ) ;
struct V_10 * V_10 = V_7 -> V_10 ;
int V_33 ;
V_33 = F_13 ( V_10 -> V_34 , V_35 + V_5 ) ;
return V_33 ;
}
static int F_14 ( struct V_36 * V_37 )
{
struct V_1 * V_7 ;
struct V_38 * V_39 ;
int V_9 ;
V_7 = F_15 ( & V_37 -> V_24 , sizeof( * V_7 ) , V_40 ) ;
if ( V_7 == NULL )
return - V_41 ;
V_7 -> V_10 = F_16 ( V_37 -> V_24 . V_42 ) ;
V_39 = V_7 -> V_10 -> V_24 -> V_43 ;
V_7 -> V_4 = V_44 ;
if ( V_39 && V_39 -> V_45 )
V_7 -> V_4 . V_46 = V_39 -> V_45 ;
V_9 = F_17 ( & V_7 -> V_4 ) ;
if ( V_9 < 0 ) {
F_9 ( & V_37 -> V_24 , L_3 , V_9 ) ;
return V_9 ;
}
F_18 ( V_37 , V_7 ) ;
return 0 ;
}
static int F_19 ( struct V_36 * V_37 )
{
struct V_1 * V_7 = F_20 ( V_37 ) ;
return F_21 ( & V_7 -> V_4 ) ;
}
