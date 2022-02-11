unsigned int F_1 ( struct V_1 * V_2 )
{
unsigned int V_3 = V_2 -> V_4 -> V_5 . V_3 ;
unsigned int V_6 ;
unsigned int V_7 ;
switch ( V_2 -> type ) {
case V_8 :
case V_9 :
case V_10 :
V_7 = 8 * F_2 ( V_2 ) ;
V_6 = ( V_3 + V_7 - 1 ) /
V_7 ;
break;
default:
V_6 = V_3 ;
break;
}
return V_6 * F_2 ( V_2 ) ;
}
void F_3 ( struct V_1 * V_2 , unsigned int V_11 )
{
struct V_12 * V_4 = V_2 -> V_4 ;
unsigned int V_13 = F_1 ( V_2 ) ;
V_4 -> V_14 += V_11 ;
if ( V_4 -> V_14 >= V_13 ) {
V_4 -> V_14 %= V_13 ;
V_4 -> V_15 |= V_16 ;
}
}
unsigned int F_4 ( struct V_1 * V_2 ,
void * V_17 , unsigned int V_11 )
{
struct V_12 * V_4 = V_2 -> V_4 ;
unsigned int V_18 ;
if ( V_11 == 0 )
return 0 ;
V_18 = F_5 ( V_4 , V_11 ) ;
if ( V_18 != V_11 ) {
F_6 ( V_2 -> V_19 -> V_20 , L_1 ) ;
V_4 -> V_15 |= V_21 ;
return 0 ;
}
F_7 ( V_4 , 0 , V_17 , V_11 ) ;
F_8 ( V_4 , V_11 ) ;
F_3 ( V_2 , V_11 ) ;
V_4 -> V_15 |= V_22 ;
return V_11 ;
}
unsigned int F_9 ( struct V_1 * V_2 ,
void * V_17 , unsigned int V_11 )
{
struct V_12 * V_4 = V_2 -> V_4 ;
if ( V_11 == 0 )
return 0 ;
V_11 = F_10 ( V_4 , V_11 ) ;
F_11 ( V_4 , 0 , V_17 , V_11 ) ;
F_12 ( V_4 , V_11 ) ;
F_3 ( V_2 , V_11 ) ;
V_4 -> V_15 |= V_22 ;
return V_11 ;
}
unsigned int F_13 ( struct V_23 * V_24 ,
struct V_1 * V_2 )
{
unsigned int V_15 = V_2 -> V_4 -> V_15 ;
if ( V_15 == 0 )
return V_15 ;
if ( V_15 & ( V_25 | V_26 | V_21 ) )
V_2 -> V_27 ( V_24 , V_2 ) ;
F_14 ( V_24 , V_2 ) ;
return V_15 ;
}
static int T_1 F_15 ( void )
{
return 0 ;
}
static void T_2 F_16 ( void )
{
}
