static int F_1 ( struct V_1 * V_2 , int V_3 )
{
if ( V_3 == V_4 ) {
if ( ! ( V_5 & V_6 ) ) {
F_2 ( V_5 & V_7 ,
V_8 ) ;
F_2 ( 1 , V_9 ) ;
V_5 |= V_6 ;
}
} else {
if ( V_5 & V_6 ) {
F_2 ( 0 , V_8 ) ;
F_2 ( 0 , V_9 ) ;
V_5 &= ~ V_6 ;
}
}
return 0 ;
}
static int F_3 ( struct V_1 * V_2 , int V_10 )
{
if ( ( V_10 >= 0 ) && ( V_10 <= V_7 ) ) {
F_2 ( V_10 , V_8 ) ;
V_5 &= ~ V_7 ;
V_5 |= V_10 ;
}
return 0 ;
}
static int F_4 ( struct V_1 * V_2 )
{
if ( V_5 & V_6 )
return V_4 ;
else
return V_11 ;
}
static int F_5 ( struct V_1 * V_2 )
{
if ( ! ( V_5 & V_6 ) )
return 0 ;
return V_5 & V_7 ;
}
static int F_6 ( struct V_12 * V_13 ,
struct V_14 * V_15 )
{
return 0 ;
}
static void F_7 ( struct V_12 * V_13 )
{
}
static int F_8 ( struct V_12 * V_13 )
{
F_9 ( V_16 ,
V_16 ) ;
F_9 ( V_17 ,
V_17 ) ;
return 0 ;
}
static void F_10 ( struct V_12 * V_13 )
{
F_9 ( V_17 , 0 ) ;
F_9 ( V_16 , 0 ) ;
}
static unsigned long F_11 ( struct V_12 * V_13 )
{
return 0 ;
}
static int F_12 ( struct V_18 * V_19 )
{
struct V_1 * V_1 = NULL ;
#ifdef F_13
int V_20 ;
V_1 = F_14 ( L_1 , & V_19 -> V_2 , NULL ,
& V_21 ) ;
if ( F_15 ( V_1 ) ) {
V_20 = F_16 ( V_1 ) ;
F_17 ( & V_19 -> V_2 , L_2 ) ;
return V_20 ;
}
F_18 ( V_19 , V_1 ) ;
V_1 -> V_22 . V_23 = V_7 ;
#endif
F_3 ( V_1 , V_24 ) ;
F_1 ( V_1 , V_4 ) ;
F_19 ( & V_25 ) ;
return 0 ;
}
static int F_20 ( struct V_18 * V_19 )
{
return 0 ;
}
static int F_21 ( struct V_18 * V_19 ,
T_1 V_26 )
{
return 0 ;
}
static int F_22 ( struct V_18 * V_19 )
{
return 0 ;
}
