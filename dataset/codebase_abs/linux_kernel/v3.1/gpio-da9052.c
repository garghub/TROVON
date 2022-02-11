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
unsigned char V_23 = 0 ;
int V_9 ;
if ( F_3 ( V_5 ) ) {
if ( V_22 ) {
V_23 = V_19 ;
V_9 = F_8 ( V_7 -> V_10 , ( V_5 >> 1 ) +
V_11 ,
V_19 ,
V_23 ) ;
if ( V_9 != 0 )
F_9 ( V_7 -> V_10 -> V_24 ,
L_1 ,
V_9 ) ;
}
} else {
if ( V_22 ) {
V_23 = V_20 ;
V_9 = F_8 ( V_7 -> V_10 , ( V_5 >> 1 ) +
V_11 ,
V_20 ,
V_23 ) ;
if ( V_9 != 0 )
F_9 ( V_7 -> V_10 -> V_24 ,
L_2 ,
V_9 ) ;
}
}
}
static int F_10 ( struct V_2 * V_6 , unsigned V_5 )
{
struct V_1 * V_7 = F_1 ( V_6 ) ;
unsigned char V_23 ;
int V_9 ;
V_23 = V_14 | V_25 << 2 |
V_26 << 3 ;
if ( F_3 ( V_5 ) )
V_9 = F_8 ( V_7 -> V_10 , ( V_5 >> 1 ) +
V_11 ,
V_27 ,
( V_23 <<
V_28 ) ) ;
else
V_9 = F_8 ( V_7 -> V_10 , ( V_5 >> 1 ) +
V_11 ,
V_29 ,
V_23 ) ;
return V_9 ;
}
static int F_11 ( struct V_2 * V_6 ,
unsigned V_5 , int V_22 )
{
struct V_1 * V_7 = F_1 ( V_6 ) ;
unsigned char V_23 ;
int V_9 ;
V_23 = V_18 | V_30 << 2 |
V_22 << 3 ;
if ( F_3 ( V_5 ) )
V_9 = F_8 ( V_7 -> V_10 , ( V_5 >> 1 ) +
V_11 ,
V_27 ,
( V_23 <<
V_28 ) ) ;
else
V_9 = F_8 ( V_7 -> V_10 , ( V_5 >> 1 ) +
V_11 ,
V_29 ,
V_23 ) ;
return V_9 ;
}
static int F_12 ( struct V_2 * V_6 , T_1 V_5 )
{
struct V_1 * V_7 = F_1 ( V_6 ) ;
struct V_10 * V_10 = V_7 -> V_10 ;
return V_10 -> V_31 + V_32 + V_5 ;
}
static int T_2 F_13 ( struct V_33 * V_34 )
{
struct V_1 * V_7 ;
struct V_35 * V_36 ;
int V_9 ;
V_7 = F_14 ( sizeof( * V_7 ) , V_37 ) ;
if ( V_7 == NULL )
return - V_38 ;
V_7 -> V_10 = F_15 ( V_34 -> V_24 . V_39 ) ;
V_36 = V_7 -> V_10 -> V_24 -> V_40 ;
V_7 -> V_4 = V_41 ;
if ( V_36 && V_36 -> V_42 )
V_7 -> V_4 . V_43 = V_36 -> V_42 ;
V_9 = F_16 ( & V_7 -> V_4 ) ;
if ( V_9 < 0 ) {
F_9 ( & V_34 -> V_24 , L_3 , V_9 ) ;
goto V_44;
}
F_17 ( V_34 , V_7 ) ;
return 0 ;
V_44:
F_18 ( V_7 ) ;
return V_9 ;
}
static int T_3 F_19 ( struct V_33 * V_34 )
{
struct V_1 * V_7 = F_20 ( V_34 ) ;
int V_9 ;
V_9 = F_21 ( & V_7 -> V_4 ) ;
if ( V_9 == 0 )
F_18 ( V_7 ) ;
return V_9 ;
}
static int T_4 F_22 ( void )
{
return F_23 ( & V_45 ) ;
}
static void T_5 F_24 ( void )
{
return F_25 ( & V_45 ) ;
}
