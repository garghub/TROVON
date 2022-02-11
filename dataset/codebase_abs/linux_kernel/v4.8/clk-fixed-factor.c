static unsigned long F_1 ( struct V_1 * V_2 ,
unsigned long V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
unsigned long long int V_6 ;
V_6 = ( unsigned long long int ) V_3 * V_5 -> V_7 ;
F_3 ( V_6 , V_5 -> div ) ;
return ( unsigned long ) V_6 ;
}
static long F_4 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long * V_8 )
{
struct V_4 * V_5 = F_2 ( V_2 ) ;
if ( F_5 ( V_2 ) & V_9 ) {
unsigned long V_10 ;
V_10 = ( V_6 / V_5 -> V_7 ) * V_5 -> div ;
* V_8 = F_6 ( F_7 ( V_2 ) , V_10 ) ;
}
return ( * V_8 / V_5 -> div ) * V_5 -> V_7 ;
}
static int F_8 ( struct V_1 * V_2 , unsigned long V_6 ,
unsigned long V_3 )
{
return 0 ;
}
struct V_1 * F_9 ( struct V_11 * V_12 ,
const char * V_13 , const char * V_14 , unsigned long V_15 ,
unsigned int V_7 , unsigned int div )
{
struct V_4 * V_5 ;
struct V_16 V_17 ;
struct V_1 * V_2 ;
int V_18 ;
V_5 = F_10 ( sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 )
return F_11 ( - V_20 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> div = div ;
V_5 -> V_2 . V_17 = & V_17 ;
V_17 . V_13 = V_13 ;
V_17 . V_21 = & V_22 ;
V_17 . V_15 = V_15 | V_23 ;
V_17 . V_24 = & V_14 ;
V_17 . V_25 = 1 ;
V_2 = & V_5 -> V_2 ;
V_18 = F_12 ( V_12 , V_2 ) ;
if ( V_18 ) {
F_13 ( V_5 ) ;
V_2 = F_11 ( V_18 ) ;
}
return V_2 ;
}
struct V_26 * F_14 ( struct V_11 * V_12 , const char * V_13 ,
const char * V_14 , unsigned long V_15 ,
unsigned int V_7 , unsigned int div )
{
struct V_1 * V_2 ;
V_2 = F_9 ( V_12 , V_13 , V_14 , V_15 , V_7 ,
div ) ;
if ( F_15 ( V_2 ) )
return F_16 ( V_2 ) ;
return V_2 -> V_26 ;
}
void F_17 ( struct V_26 * V_26 )
{
struct V_1 * V_2 ;
V_2 = F_18 ( V_26 ) ;
if ( ! V_2 )
return;
F_19 ( V_26 ) ;
F_13 ( F_2 ( V_2 ) ) ;
}
void F_20 ( struct V_1 * V_2 )
{
struct V_4 * V_5 ;
V_5 = F_2 ( V_2 ) ;
F_21 ( V_2 ) ;
F_13 ( V_5 ) ;
}
void T_1 F_22 ( struct V_27 * V_28 )
{
struct V_26 * V_26 ;
const char * V_29 = V_28 -> V_13 ;
const char * V_14 ;
unsigned long V_15 = 0 ;
T_2 div , V_7 ;
if ( F_23 ( V_28 , L_1 , & div ) ) {
F_24 ( L_2 ,
V_30 , V_28 -> V_13 ) ;
return;
}
if ( F_23 ( V_28 , L_3 , & V_7 ) ) {
F_24 ( L_4 ,
V_30 , V_28 -> V_13 ) ;
return;
}
F_25 ( V_28 , L_5 , & V_29 ) ;
V_14 = F_26 ( V_28 , 0 ) ;
if ( F_27 ( V_31 , V_28 ) )
V_15 |= V_9 ;
V_26 = F_14 ( NULL , V_29 , V_14 , V_15 ,
V_7 , div ) ;
if ( ! F_15 ( V_26 ) )
F_28 ( V_28 , V_32 , V_26 ) ;
}
