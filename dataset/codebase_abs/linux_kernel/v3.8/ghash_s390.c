static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
return 0 ;
}
static int F_3 ( struct V_5 * V_6 ,
const T_1 * V_7 , unsigned int V_8 )
{
struct V_9 * V_10 = F_4 ( V_6 ) ;
if ( V_8 != V_11 ) {
F_5 ( V_6 , V_12 ) ;
return - V_13 ;
}
memcpy ( V_10 -> V_7 , V_7 , V_11 ) ;
memset ( V_10 -> V_14 , 0 , V_11 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const T_1 * V_15 , unsigned int V_16 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_2 -> V_6 ) ;
unsigned int V_17 ;
T_1 * V_18 = V_4 -> V_19 ;
int V_20 ;
if ( V_4 -> V_21 ) {
T_1 * V_22 = V_18 + ( V_11 - V_4 -> V_21 ) ;
V_17 = F_7 ( V_16 , V_4 -> V_21 ) ;
V_4 -> V_21 -= V_17 ;
V_16 -= V_17 ;
memcpy ( V_22 , V_15 , V_17 ) ;
V_15 += V_17 ;
if ( ! V_4 -> V_21 ) {
V_20 = F_8 ( V_23 , V_10 , V_18 ,
V_11 ) ;
if ( V_20 != V_11 )
return - V_24 ;
}
}
V_17 = V_16 & ~ ( V_11 - 1 ) ;
if ( V_17 ) {
V_20 = F_8 ( V_23 , V_10 , V_15 , V_17 ) ;
if ( V_20 != V_17 )
return - V_24 ;
V_15 += V_17 ;
V_16 -= V_17 ;
}
if ( V_16 ) {
V_4 -> V_21 = V_11 - V_16 ;
memcpy ( V_18 , V_15 , V_16 ) ;
}
return 0 ;
}
static int F_9 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
T_1 * V_18 = V_4 -> V_19 ;
int V_20 ;
if ( V_4 -> V_21 ) {
T_1 * V_22 = V_18 + ( V_11 - V_4 -> V_21 ) ;
memset ( V_22 , 0 , V_4 -> V_21 ) ;
V_20 = F_8 ( V_23 , V_10 , V_18 , V_11 ) ;
if ( V_20 != V_11 )
return - V_24 ;
}
V_4 -> V_21 = 0 ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_25 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_2 -> V_6 ) ;
int V_20 ;
V_20 = F_9 ( V_10 , V_4 ) ;
if ( ! V_20 )
memcpy ( V_25 , V_10 -> V_14 , V_11 ) ;
return V_20 ;
}
static int T_2 F_11 ( void )
{
if ( ! F_12 ( V_23 ,
V_26 | V_27 ) )
return - V_28 ;
return F_13 ( & V_29 ) ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_29 ) ;
}
