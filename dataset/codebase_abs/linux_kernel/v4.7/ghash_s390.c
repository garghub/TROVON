static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_5 * V_6 = F_3 ( V_2 -> V_7 ) ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
memcpy ( V_4 -> V_8 , V_6 -> V_8 , V_9 ) ;
return 0 ;
}
static int F_4 ( struct V_10 * V_7 ,
const T_1 * V_8 , unsigned int V_11 )
{
struct V_5 * V_6 = F_3 ( V_7 ) ;
if ( V_11 != V_9 ) {
F_5 ( V_7 , V_12 ) ;
return - V_13 ;
}
memcpy ( V_6 -> V_8 , V_8 , V_9 ) ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 ,
const T_1 * V_14 , unsigned int V_15 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
unsigned int V_16 ;
T_1 * V_17 = V_4 -> V_18 ;
int V_19 ;
if ( V_4 -> V_20 ) {
T_1 * V_21 = V_17 + ( V_9 - V_4 -> V_20 ) ;
V_16 = F_7 ( V_15 , V_4 -> V_20 ) ;
V_4 -> V_20 -= V_16 ;
V_15 -= V_16 ;
memcpy ( V_21 , V_14 , V_16 ) ;
V_14 += V_16 ;
if ( ! V_4 -> V_20 ) {
V_19 = F_8 ( V_22 , V_4 , V_17 ,
V_9 ) ;
if ( V_19 != V_9 )
return - V_23 ;
}
}
V_16 = V_15 & ~ ( V_9 - 1 ) ;
if ( V_16 ) {
V_19 = F_8 ( V_22 , V_4 , V_14 , V_16 ) ;
if ( V_19 != V_16 )
return - V_23 ;
V_14 += V_16 ;
V_15 -= V_16 ;
}
if ( V_15 ) {
V_4 -> V_20 = V_9 - V_15 ;
memcpy ( V_17 , V_14 , V_15 ) ;
}
return 0 ;
}
static int F_9 ( struct V_3 * V_4 )
{
T_1 * V_17 = V_4 -> V_18 ;
int V_19 ;
if ( V_4 -> V_20 ) {
T_1 * V_21 = V_17 + ( V_9 - V_4 -> V_20 ) ;
memset ( V_21 , 0 , V_4 -> V_20 ) ;
V_19 = F_8 ( V_22 , V_4 , V_17 , V_9 ) ;
if ( V_19 != V_9 )
return - V_23 ;
V_4 -> V_20 = 0 ;
}
return 0 ;
}
static int F_10 ( struct V_1 * V_2 , T_1 * V_24 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
int V_19 ;
V_19 = F_9 ( V_4 ) ;
if ( ! V_19 )
memcpy ( V_24 , V_4 -> V_25 , V_9 ) ;
return V_19 ;
}
static int T_2 F_11 ( void )
{
if ( ! F_12 ( V_26 , V_22 ) )
return - V_27 ;
return F_13 ( & V_28 ) ;
}
static void T_3 F_14 ( void )
{
F_15 ( & V_28 ) ;
}
