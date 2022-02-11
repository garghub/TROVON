static int F_1 ( void * V_1 , unsigned int V_2 ,
void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_1 ;
unsigned int V_7 ;
T_2 * V_8 = V_3 ;
int V_9 ;
T_2 V_10 ;
V_10 = V_2 >> 2 ;
V_7 = V_4 >> 2 ;
if ( V_7 > ( V_6 -> V_11 - V_10 ) )
V_7 = V_6 -> V_11 - V_10 ;
for ( V_9 = V_10 ; V_9 < ( V_10 + V_7 ) ; V_9 ++ )
* V_8 ++ = F_2 ( V_6 -> V_12 + 0x400 + V_9 * 0x10 ) ;
return 0 ;
}
static int F_3 ( struct V_13 * V_14 )
{
const struct V_15 * V_16 ;
struct V_17 * V_18 = & V_14 -> V_18 ;
struct V_19 * V_20 ;
struct V_5 * V_6 ;
struct V_21 * V_22 ;
V_6 = F_4 ( V_18 , sizeof( * V_6 ) , V_23 ) ;
if ( ! V_6 )
return - V_24 ;
V_20 = F_5 ( V_14 , V_25 , 0 ) ;
V_6 -> V_12 = F_6 ( V_18 , V_20 ) ;
if ( F_7 ( V_6 -> V_12 ) )
return F_8 ( V_6 -> V_12 ) ;
V_16 = F_9 ( V_26 , V_18 ) ;
V_6 -> V_11 = ( unsigned int ) V_16 -> V_27 ;
V_28 . V_29 = 4 * V_6 -> V_11 ;
V_28 . V_18 = V_18 ;
V_28 . V_6 = V_6 ;
V_22 = F_10 ( & V_28 ) ;
if ( F_7 ( V_22 ) )
return F_8 ( V_22 ) ;
F_11 ( V_14 , V_22 ) ;
return 0 ;
}
static int F_12 ( struct V_13 * V_14 )
{
struct V_21 * V_22 = F_13 ( V_14 ) ;
return F_14 ( V_22 ) ;
}
