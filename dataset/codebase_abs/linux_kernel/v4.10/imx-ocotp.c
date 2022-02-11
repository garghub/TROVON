static int F_1 ( void * V_1 , unsigned int V_2 ,
void * V_3 , T_1 V_4 )
{
struct V_5 * V_6 = V_1 ;
unsigned int V_7 ;
T_2 * V_8 = V_3 ;
int V_9 , V_10 ;
T_2 V_11 ;
V_11 = V_2 >> 2 ;
V_7 = V_4 >> 2 ;
if ( V_7 > ( V_6 -> V_12 - V_11 ) )
V_7 = V_6 -> V_12 - V_11 ;
V_10 = F_2 ( V_6 -> V_13 ) ;
if ( V_10 < 0 ) {
F_3 ( V_6 -> V_14 , L_1 ) ;
return V_10 ;
}
for ( V_9 = V_11 ; V_9 < ( V_11 + V_7 ) ; V_9 ++ )
* V_8 ++ = F_4 ( V_6 -> V_15 + 0x400 + V_9 * 0x10 ) ;
F_5 ( V_6 -> V_13 ) ;
return 0 ;
}
static int F_6 ( struct V_16 * V_17 )
{
const struct V_18 * V_19 ;
struct V_20 * V_14 = & V_17 -> V_14 ;
struct V_21 * V_22 ;
struct V_5 * V_6 ;
struct V_23 * V_24 ;
V_6 = F_7 ( V_14 , sizeof( * V_6 ) , V_25 ) ;
if ( ! V_6 )
return - V_26 ;
V_22 = F_8 ( V_17 , V_27 , 0 ) ;
V_6 -> V_15 = F_9 ( V_14 , V_22 ) ;
if ( F_10 ( V_6 -> V_15 ) )
return F_11 ( V_6 -> V_15 ) ;
V_6 -> V_13 = F_12 ( & V_17 -> V_14 , NULL ) ;
if ( F_10 ( V_6 -> V_13 ) )
return F_11 ( V_6 -> V_13 ) ;
V_19 = F_13 ( V_28 , V_14 ) ;
V_6 -> V_12 = ( unsigned long ) V_19 -> V_29 ;
V_30 . V_31 = 4 * V_6 -> V_12 ;
V_30 . V_14 = V_14 ;
V_30 . V_6 = V_6 ;
V_24 = F_14 ( & V_30 ) ;
if ( F_10 ( V_24 ) )
return F_11 ( V_24 ) ;
F_15 ( V_17 , V_24 ) ;
return 0 ;
}
static int F_16 ( struct V_16 * V_17 )
{
struct V_23 * V_24 = F_17 ( V_17 ) ;
return F_18 ( V_24 ) ;
}
