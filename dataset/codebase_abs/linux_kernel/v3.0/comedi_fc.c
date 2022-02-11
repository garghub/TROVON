static void F_1 ( struct V_1 * V_2 ,
unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_6 = F_2 ( V_2 ) ;
V_5 -> V_7 += V_3 ;
if ( V_5 -> V_7 >= V_6 ) {
V_5 -> V_7 %= V_6 ;
V_5 -> V_8 |= V_9 ;
}
}
unsigned int F_3 ( struct V_1 * V_2 ,
void * V_10 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
unsigned int V_11 ;
if ( V_3 == 0 )
return 0 ;
V_11 = F_4 ( V_5 , V_3 ) ;
if ( V_11 != V_3 ) {
F_5 ( V_12 L_1 ) ;
V_5 -> V_8 |= V_13 ;
return 0 ;
}
F_6 ( V_5 , 0 , V_10 , V_3 ) ;
F_7 ( V_5 , V_3 ) ;
F_1 ( V_2 , V_3 ) ;
V_5 -> V_8 |= V_14 ;
return V_3 ;
}
unsigned int F_8 ( struct V_1 * V_2 ,
void * V_10 , unsigned int V_3 )
{
struct V_4 * V_5 = V_2 -> V_5 ;
if ( V_3 == 0 )
return 0 ;
V_3 = F_9 ( V_5 , V_3 ) ;
F_10 ( V_5 , 0 , V_10 , V_3 ) ;
F_11 ( V_5 , V_3 ) ;
F_1 ( V_2 , V_3 ) ;
V_5 -> V_8 |= V_14 ;
return V_3 ;
}
unsigned int F_12 ( struct V_15 * V_16 ,
struct V_1 * V_2 )
{
unsigned int V_8 = V_2 -> V_5 -> V_8 ;
if ( V_8 == 0 )
return V_8 ;
if ( V_8 & ( V_17 | V_18 | V_13 ) )
V_2 -> V_19 ( V_16 , V_2 ) ;
F_13 ( V_16 , V_2 ) ;
return V_8 ;
}
static int T_1 F_14 ( void )
{
return 0 ;
}
static void T_2 F_15 ( void )
{
}
