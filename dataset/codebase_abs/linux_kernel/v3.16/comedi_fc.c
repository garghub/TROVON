unsigned int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = & V_2 -> V_5 -> V_4 ;
unsigned int V_6 ;
unsigned int V_7 ;
switch ( V_2 -> type ) {
case V_8 :
case V_9 :
case V_10 :
V_7 = 8 * F_2 ( V_2 ) ;
V_6 = ( V_4 -> V_11 + V_7 - 1 ) /
V_7 ;
break;
default:
V_6 = V_4 -> V_11 ;
break;
}
return V_6 * F_2 ( V_2 ) ;
}
void F_3 ( struct V_1 * V_2 , unsigned int V_12 )
{
struct V_13 * V_5 = V_2 -> V_5 ;
unsigned int V_14 = F_1 ( V_2 ) ;
V_5 -> V_15 += V_12 ;
if ( V_5 -> V_15 >= V_14 ) {
V_5 -> V_15 %= V_14 ;
V_5 -> V_16 |= V_17 ;
}
}
unsigned int F_4 ( struct V_1 * V_2 ,
void * V_18 , unsigned int V_12 )
{
struct V_13 * V_5 = V_2 -> V_5 ;
unsigned int V_19 ;
if ( V_12 == 0 )
return 0 ;
V_19 = F_5 ( V_2 , V_12 ) ;
if ( V_19 != V_12 ) {
F_6 ( V_2 -> V_20 -> V_21 , L_1 ) ;
V_5 -> V_16 |= V_22 ;
return 0 ;
}
F_7 ( V_2 , 0 , V_18 , V_12 ) ;
F_8 ( V_2 , V_12 ) ;
F_3 ( V_2 , V_12 ) ;
V_5 -> V_16 |= V_23 ;
return V_12 ;
}
unsigned int F_9 ( struct V_1 * V_2 ,
void * V_18 , unsigned int V_12 )
{
if ( V_12 == 0 )
return 0 ;
V_12 = F_10 ( V_2 , V_12 ) ;
F_11 ( V_2 , 0 , V_18 , V_12 ) ;
F_12 ( V_2 , V_12 ) ;
F_3 ( V_2 , V_12 ) ;
V_2 -> V_5 -> V_16 |= V_23 ;
return V_12 ;
}
unsigned int F_13 ( struct V_24 * V_25 ,
struct V_1 * V_2 )
{
unsigned int V_16 = V_2 -> V_5 -> V_16 ;
if ( V_16 == 0 )
return V_16 ;
if ( V_16 & ( V_26 | V_27 | V_22 ) )
V_2 -> V_28 ( V_25 , V_2 ) ;
F_14 ( V_25 , V_2 ) ;
return V_16 ;
}
static int T_1 F_15 ( void )
{
return 0 ;
}
static void T_2 F_16 ( void )
{
}
