static int F_1 ( void * V_1 , const void * V_2 , T_1 V_3 ,
void * V_4 , T_1 V_5 )
{
struct V_6 * V_7 = V_1 ;
unsigned int V_8 = * ( V_9 * ) V_2 ;
unsigned int V_10 ;
int V_11 ;
V_9 V_12 ;
V_12 = V_8 >> 2 ;
V_10 = V_5 >> 2 ;
if ( V_10 > ( V_7 -> V_13 - V_12 ) )
V_10 = V_7 -> V_13 - V_12 ;
for ( V_11 = V_12 ; V_11 < ( V_12 + V_10 ) ; V_11 ++ ) {
* ( V_9 * ) V_4 = F_2 ( V_7 -> V_14 + 0x400 + V_11 * 0x10 ) ;
V_4 += 4 ;
}
return 0 ;
}
static int F_3 ( void * V_1 , const void * V_15 , T_1 V_10 )
{
return 0 ;
}
static bool F_4 ( struct V_16 * V_17 , unsigned int V_2 )
{
return false ;
}
static int F_5 ( struct V_18 * V_19 )
{
const struct V_20 * V_21 ;
struct V_16 * V_17 = & V_19 -> V_17 ;
struct V_22 * V_23 ;
struct V_24 * V_24 ;
struct V_6 * V_7 ;
struct V_25 * V_26 ;
V_7 = F_6 ( V_17 , sizeof( * V_7 ) , V_27 ) ;
if ( ! V_7 )
return - V_28 ;
V_23 = F_7 ( V_19 , V_29 , 0 ) ;
V_7 -> V_14 = F_8 ( V_17 , V_23 ) ;
if ( F_9 ( V_7 -> V_14 ) )
return F_10 ( V_7 -> V_14 ) ;
V_21 = F_11 ( V_30 , V_17 ) ;
V_7 -> V_13 = ( unsigned int ) V_21 -> V_15 ;
V_31 . V_32 = 4 * V_7 -> V_13 - 4 ;
V_24 = F_12 ( V_17 , & V_33 , V_7 ,
& V_31 ) ;
if ( F_9 ( V_24 ) ) {
F_13 ( V_17 , L_1 ) ;
return F_10 ( V_24 ) ;
}
V_34 . V_17 = V_17 ;
V_26 = F_14 ( & V_34 ) ;
if ( F_9 ( V_26 ) )
return F_10 ( V_26 ) ;
F_15 ( V_19 , V_26 ) ;
return 0 ;
}
static int F_16 ( struct V_18 * V_19 )
{
struct V_25 * V_26 = F_17 ( V_19 ) ;
return F_18 ( V_26 ) ;
}
