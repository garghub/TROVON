static int F_1 ( void * V_1 , unsigned int V_2 ,
void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_1 ;
unsigned int V_7 = V_4 >> 2 ;
T_2 V_8 = V_2 >> 2 ;
T_2 * V_9 = V_3 ;
int V_10 ;
if ( V_7 > ( V_11 - V_8 ) )
V_7 = V_11 - V_8 ;
for ( V_10 = V_8 ; V_10 < ( V_8 + V_7 ) ; V_10 ++ )
* V_9 ++ = F_2 ( V_6 -> V_12 + V_10 * V_13 ) ;
return 0 ;
}
static int F_3 ( struct V_14 * V_15 )
{
struct V_16 * V_17 ;
struct V_5 * V_6 ;
struct V_18 * V_19 ;
V_6 = F_4 ( & V_15 -> V_20 , sizeof( * V_6 ) , V_21 ) ;
if ( ! V_6 )
return - V_22 ;
V_19 = F_5 ( V_15 , V_23 , 0 ) ;
V_6 -> V_12 = F_6 ( & V_15 -> V_20 , V_19 ) ;
if ( F_7 ( V_6 -> V_12 ) )
return F_8 ( V_6 -> V_12 ) ;
V_24 . V_25 = V_11 ;
V_24 . V_20 = & V_15 -> V_20 ;
V_24 . V_26 = V_6 ;
V_17 = F_9 ( & V_24 ) ;
if ( F_7 ( V_17 ) )
return F_8 ( V_17 ) ;
F_10 ( V_15 , V_17 ) ;
return 0 ;
}
static int F_11 ( struct V_14 * V_15 )
{
struct V_16 * V_17 = F_12 ( V_15 ) ;
return F_13 ( V_17 ) ;
}
