__weak void T_1 * F_1 ( T_2 V_1 , unsigned long V_2 )
{
return F_2 ( V_1 , V_2 ) ;
}
static void * F_3 ( T_2 V_1 , T_3 V_2 )
{
struct V_3 * V_3 = F_4 ( V_1 >> V_4 ) ;
if ( ! F_5 ( V_3 ) )
return F_6 ( V_1 ) ;
return NULL ;
}
void * F_7 ( T_2 V_1 , T_3 V_2 , unsigned long V_5 )
{
int V_6 = F_8 ( V_1 , V_2 , L_1 ) ;
void * V_7 = NULL ;
if ( V_6 == V_8 ) {
F_9 ( 1 , L_2 ,
& V_1 , ( unsigned long ) V_2 ) ;
return NULL ;
}
if ( V_5 & V_9 ) {
V_5 &= ~ V_9 ;
if ( V_6 == V_10 )
V_7 = F_3 ( V_1 , V_2 ) ;
if ( ! V_7 )
V_7 = F_1 ( V_1 , V_2 ) ;
}
if ( ! V_7 && V_6 == V_10 && V_5 ) {
F_9 ( 1 , L_3 ,
& V_1 , ( unsigned long ) V_2 ) ;
return NULL ;
}
if ( ! V_7 && ( V_5 & V_11 ) ) {
V_5 &= ~ V_11 ;
V_7 = F_10 ( V_1 , V_2 ) ;
}
return V_7 ;
}
void F_11 ( void * V_7 )
{
if ( F_12 ( V_7 ) )
F_13 ( ( void T_1 * ) V_7 ) ;
}
static void F_14 ( struct V_12 * V_13 , void * V_14 )
{
F_11 ( V_14 ) ;
}
static int F_15 ( struct V_12 * V_13 , void * V_14 , void * V_15 )
{
return * ( void * * ) V_14 == V_15 ;
}
void * F_16 ( struct V_12 * V_13 , T_2 V_1 ,
T_3 V_2 , unsigned long V_5 )
{
void * * V_16 , * V_7 ;
V_16 = F_17 ( F_14 , sizeof( * V_16 ) , V_17 ) ;
if ( ! V_16 )
return NULL ;
V_7 = F_7 ( V_1 , V_2 , V_5 ) ;
if ( V_7 ) {
* V_16 = V_7 ;
F_18 ( V_13 , V_16 ) ;
} else
F_19 ( V_16 ) ;
return V_7 ;
}
void F_20 ( struct V_12 * V_13 , void * V_7 )
{
F_21 ( F_22 ( V_13 , F_14 , F_15 ,
V_7 ) ) ;
F_11 ( V_7 ) ;
}
static void F_23 ( struct V_12 * V_13 , void * V_14 )
{
struct V_18 * V_18 = V_14 ;
F_24 ( V_18 -> V_14 . V_19 , F_25 ( & V_18 -> V_14 ) ) ;
}
void * F_26 ( struct V_12 * V_13 , struct V_20 * V_14 )
{
int V_6 = F_8 ( V_14 -> V_19 , F_25 ( V_14 ) ,
L_1 ) ;
struct V_18 * V_18 ;
int error , V_21 ;
if ( V_6 == V_8 ) {
F_9 ( 1 , L_4 ,
V_22 , V_14 ) ;
return F_27 ( - V_23 ) ;
}
if ( V_6 == V_10 )
return F_6 ( V_14 -> V_19 ) ;
V_18 = F_17 ( F_23 ,
sizeof( * V_18 ) , V_17 ) ;
if ( ! V_18 )
return F_27 ( - V_24 ) ;
memcpy ( & V_18 -> V_14 , V_14 , sizeof( * V_14 ) ) ;
V_21 = F_28 ( V_13 ) ;
if ( V_21 < 0 )
V_21 = 0 ;
error = F_29 ( V_21 , V_14 -> V_19 , F_25 ( V_14 ) , true ) ;
if ( error ) {
F_19 ( V_18 ) ;
return F_27 ( error ) ;
}
F_18 ( V_13 , V_18 ) ;
return F_6 ( V_14 -> V_19 ) ;
}
