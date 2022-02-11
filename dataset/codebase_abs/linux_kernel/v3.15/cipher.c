static int F_1 ( struct V_1 * V_2 , const T_1 * V_3 ,
unsigned int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
unsigned long V_9 = F_2 ( V_2 ) ;
int V_10 ;
T_1 * V_11 , * V_12 ;
unsigned long V_13 ;
V_13 = V_4 + V_9 ;
V_11 = F_3 ( V_13 , V_14 ) ;
if ( ! V_11 )
return - V_15 ;
V_12 = ( T_1 * ) F_4 ( ( unsigned long ) V_11 , V_9 + 1 ) ;
memcpy ( V_12 , V_3 , V_4 ) ;
V_10 = V_6 -> V_16 ( V_2 , V_12 , V_4 ) ;
memset ( V_12 , 0 , V_4 ) ;
F_5 ( V_11 ) ;
return V_10 ;
}
static int F_6 ( struct V_1 * V_2 , const T_1 * V_3 , unsigned int V_4 )
{
struct V_5 * V_6 = & V_2 -> V_7 -> V_8 ;
unsigned long V_9 = F_2 ( V_2 ) ;
V_2 -> V_17 &= ~ V_18 ;
if ( V_4 < V_6 -> V_19 || V_4 > V_6 -> V_20 ) {
V_2 -> V_17 |= V_21 ;
return - V_22 ;
}
if ( ( unsigned long ) V_3 & V_9 )
return F_1 ( V_2 , V_3 , V_4 ) ;
return V_6 -> V_16 ( V_2 , V_3 , V_4 ) ;
}
static void F_7 ( void (* F_8)( struct V_1 * , T_1 * ,
const T_1 * ) ,
struct V_1 * V_2 ,
T_1 * V_23 , const T_1 * V_24 )
{
unsigned long V_9 = F_2 ( V_2 ) ;
unsigned int V_25 = F_9 ( V_2 ) ;
T_1 V_11 [ V_25 + V_9 ] ;
T_1 * V_26 = ( T_1 * ) F_4 ( ( unsigned long ) V_11 , V_9 + 1 ) ;
memcpy ( V_26 , V_24 , V_25 ) ;
F_8 ( V_2 , V_26 , V_26 ) ;
memcpy ( V_23 , V_26 , V_25 ) ;
}
static void F_10 ( struct V_1 * V_2 ,
T_1 * V_23 , const T_1 * V_24 )
{
unsigned long V_9 = F_2 ( V_2 ) ;
struct V_5 * V_27 = & V_2 -> V_7 -> V_8 ;
if ( F_11 ( ( ( unsigned long ) V_23 | ( unsigned long ) V_24 ) & V_9 ) ) {
F_7 ( V_27 -> V_28 , V_2 , V_23 , V_24 ) ;
return;
}
V_27 -> V_28 ( V_2 , V_23 , V_24 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
T_1 * V_23 , const T_1 * V_24 )
{
unsigned long V_9 = F_2 ( V_2 ) ;
struct V_5 * V_27 = & V_2 -> V_7 -> V_8 ;
if ( F_11 ( ( ( unsigned long ) V_23 | ( unsigned long ) V_24 ) & V_9 ) ) {
F_7 ( V_27 -> V_29 , V_2 , V_23 , V_24 ) ;
return;
}
V_27 -> V_29 ( V_2 , V_23 , V_24 ) ;
}
int F_13 ( struct V_1 * V_2 )
{
struct V_30 * V_31 = & V_2 -> V_32 ;
struct V_5 * V_27 = & V_2 -> V_7 -> V_8 ;
V_31 -> V_33 = F_6 ;
V_31 -> V_34 = F_2 ( V_2 ) ?
F_10 : V_27 -> V_28 ;
V_31 -> V_35 = F_2 ( V_2 ) ?
F_12 : V_27 -> V_29 ;
return 0 ;
}
void F_14 ( struct V_1 * V_2 )
{
}
