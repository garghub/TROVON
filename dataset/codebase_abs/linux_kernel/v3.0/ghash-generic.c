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
if ( V_10 -> V_14 )
F_6 ( V_10 -> V_14 ) ;
V_10 -> V_14 = F_7 ( ( V_15 * ) V_7 ) ;
if ( ! V_10 -> V_14 )
return - V_16 ;
return 0 ;
}
static int F_8 ( struct V_1 * V_2 ,
const T_1 * V_17 , unsigned int V_18 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_2 -> V_6 ) ;
T_1 * V_19 = V_4 -> V_20 ;
if ( V_4 -> V_21 ) {
int V_22 = F_9 ( V_18 , V_4 -> V_21 ) ;
T_1 * V_23 = V_19 + ( V_11 - V_4 -> V_21 ) ;
V_4 -> V_21 -= V_22 ;
V_18 -= V_22 ;
while ( V_22 -- )
* V_23 ++ ^= * V_17 ++ ;
if ( ! V_4 -> V_21 )
F_10 ( ( V_15 * ) V_19 , V_10 -> V_14 ) ;
}
while ( V_18 >= V_11 ) {
F_11 ( V_19 , V_17 , V_11 ) ;
F_10 ( ( V_15 * ) V_19 , V_10 -> V_14 ) ;
V_17 += V_11 ;
V_18 -= V_11 ;
}
if ( V_18 ) {
V_4 -> V_21 = V_11 - V_18 ;
while ( V_18 -- )
* V_19 ++ ^= * V_17 ++ ;
}
return 0 ;
}
static void F_12 ( struct V_9 * V_10 , struct V_3 * V_4 )
{
T_1 * V_19 = V_4 -> V_20 ;
if ( V_4 -> V_21 ) {
T_1 * V_24 = V_19 + ( V_11 - V_4 -> V_21 ) ;
while ( V_4 -> V_21 -- )
* V_24 ++ ^= 0 ;
F_10 ( ( V_15 * ) V_19 , V_10 -> V_14 ) ;
}
V_4 -> V_21 = 0 ;
}
static int F_13 ( struct V_1 * V_2 , T_1 * V_19 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
struct V_9 * V_10 = F_4 ( V_2 -> V_6 ) ;
T_1 * V_25 = V_4 -> V_20 ;
F_12 ( V_10 , V_4 ) ;
memcpy ( V_19 , V_25 , V_11 ) ;
return 0 ;
}
static void F_14 ( struct V_26 * V_6 )
{
struct V_9 * V_10 = F_15 ( V_6 ) ;
if ( V_10 -> V_14 )
F_6 ( V_10 -> V_14 ) ;
}
static int T_2 F_16 ( void )
{
return F_17 ( & V_27 ) ;
}
static void T_3 F_18 ( void )
{
F_19 ( & V_27 ) ;
}
