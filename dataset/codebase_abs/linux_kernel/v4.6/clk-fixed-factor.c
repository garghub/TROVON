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
struct V_11 * F_9 ( struct V_12 * V_13 , const char * V_14 ,
const char * V_15 , unsigned long V_16 ,
unsigned int V_7 , unsigned int div )
{
struct V_4 * V_5 ;
struct V_17 V_18 ;
struct V_11 * V_11 ;
V_5 = F_10 ( sizeof( * V_5 ) , V_19 ) ;
if ( ! V_5 )
return F_11 ( - V_20 ) ;
V_5 -> V_7 = V_7 ;
V_5 -> div = div ;
V_5 -> V_2 . V_18 = & V_18 ;
V_18 . V_14 = V_14 ;
V_18 . V_21 = & V_22 ;
V_18 . V_16 = V_16 | V_23 ;
V_18 . V_24 = & V_15 ;
V_18 . V_25 = 1 ;
V_11 = F_12 ( V_13 , & V_5 -> V_2 ) ;
if ( F_13 ( V_11 ) )
F_14 ( V_5 ) ;
return V_11 ;
}
void F_15 ( struct V_11 * V_11 )
{
struct V_1 * V_2 ;
V_2 = F_16 ( V_11 ) ;
if ( ! V_2 )
return;
F_17 ( V_11 ) ;
F_14 ( F_2 ( V_2 ) ) ;
}
void T_1 F_18 ( struct V_26 * V_27 )
{
struct V_11 * V_11 ;
const char * V_28 = V_27 -> V_14 ;
const char * V_15 ;
T_2 div , V_7 ;
if ( F_19 ( V_27 , L_1 , & div ) ) {
F_20 ( L_2 ,
V_29 , V_27 -> V_14 ) ;
return;
}
if ( F_19 ( V_27 , L_3 , & V_7 ) ) {
F_20 ( L_4 ,
V_29 , V_27 -> V_14 ) ;
return;
}
F_21 ( V_27 , L_5 , & V_28 ) ;
V_15 = F_22 ( V_27 , 0 ) ;
V_11 = F_9 ( NULL , V_28 , V_15 , 0 ,
V_7 , div ) ;
if ( ! F_13 ( V_11 ) )
F_23 ( V_27 , V_30 , V_11 ) ;
}
