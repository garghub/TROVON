static void F_1 ( unsigned long V_1 )
{
struct V_2 * V_3 = ( void * ) V_1 ;
unsigned long V_4 ;
unsigned long V_5 ;
if ( ! V_3 -> V_6 || ! V_3 -> V_7 ) {
F_2 ( V_3 , V_8 ) ;
return;
}
if ( V_3 -> V_9 & V_10 ) {
V_3 -> V_9 &= ~ V_10 ;
return;
}
V_4 = F_3 ( V_3 ) ;
if ( ! V_4 ) {
if ( V_3 -> V_11 ) {
V_3 -> V_12 =
V_3 -> V_11 ;
V_3 -> V_11 = 0 ;
}
V_4 = V_3 -> V_12 ;
V_5 = V_3 -> V_6 ;
} else {
V_3 -> V_12 = V_4 ;
V_4 = V_8 ;
V_5 = V_3 -> V_7 ;
}
F_2 ( V_3 , V_4 ) ;
if ( V_3 -> V_9 & V_13 ) {
if ( V_3 -> V_9 & V_14 ) {
if ( V_4 )
V_3 -> V_9 |= V_10 ;
} else {
if ( ! V_4 )
V_3 -> V_9 |= V_10 ;
}
}
F_4 ( & V_3 -> V_15 , V_16 + F_5 ( V_5 ) ) ;
}
static void F_6 ( struct V_17 * V_18 )
{
struct V_2 * V_3 =
F_7 ( V_18 , struct V_2 , V_19 ) ;
F_8 ( V_3 ) ;
F_2 ( V_3 , V_3 -> V_11 ) ;
}
static void F_9 ( struct V_2 * V_3 ,
unsigned long V_20 ,
unsigned long V_21 )
{
int V_22 ;
V_22 = F_3 ( V_3 ) ;
if ( V_22 )
V_3 -> V_12 = V_22 ;
if ( ! V_3 -> V_12 )
V_3 -> V_12 = V_3 -> V_23 ;
V_3 -> V_6 = V_20 ;
V_3 -> V_7 = V_21 ;
if ( ! V_20 ) {
F_2 ( V_3 , V_8 ) ;
return;
}
if ( ! V_21 ) {
F_2 ( V_3 , V_3 -> V_12 ) ;
return;
}
F_4 ( & V_3 -> V_15 , V_16 + 1 ) ;
}
static void F_10 ( struct V_2 * V_3 ,
unsigned long * V_20 ,
unsigned long * V_21 )
{
if ( ! ( V_3 -> V_9 & V_13 ) &&
V_3 -> V_24 &&
! V_3 -> V_24 ( V_3 , V_20 , V_21 ) )
return;
if ( ! * V_20 && ! * V_21 )
* V_20 = * V_21 = 500 ;
F_9 ( V_3 , * V_20 , * V_21 ) ;
}
void F_11 ( struct V_2 * V_3 )
{
F_12 ( & V_3 -> V_19 , F_6 ) ;
F_13 ( & V_3 -> V_15 , F_1 ,
( unsigned long ) V_3 ) ;
}
void F_14 ( struct V_2 * V_3 ,
unsigned long * V_20 ,
unsigned long * V_21 )
{
F_15 ( & V_3 -> V_15 ) ;
V_3 -> V_9 &= ~ V_13 ;
V_3 -> V_9 &= ~ V_10 ;
F_10 ( V_3 , V_20 , V_21 ) ;
}
void F_16 ( struct V_2 * V_3 ,
unsigned long * V_20 ,
unsigned long * V_21 ,
int V_25 )
{
if ( ( V_3 -> V_9 & V_13 ) &&
F_17 ( & V_3 -> V_15 ) )
return;
V_3 -> V_9 |= V_13 ;
V_3 -> V_9 &= ~ V_10 ;
if ( V_25 )
V_3 -> V_9 |= V_14 ;
else
V_3 -> V_9 &= ~ V_14 ;
F_10 ( V_3 , V_20 , V_21 ) ;
}
void F_8 ( struct V_2 * V_3 )
{
F_15 ( & V_3 -> V_15 ) ;
V_3 -> V_6 = 0 ;
V_3 -> V_7 = 0 ;
}
void F_18 ( struct V_2 * V_3 ,
enum V_26 V_4 )
{
int V_27 = 0 ;
if ( V_3 -> V_6 || V_3 -> V_7 ) {
V_3 -> V_11 = V_4 ;
if ( V_4 == V_8 )
F_19 ( & V_3 -> V_19 ) ;
return;
}
if ( V_3 -> V_9 & V_28 ) {
F_2 ( V_3 , V_4 ) ;
return;
} else if ( V_3 -> V_9 & V_29 )
V_27 = F_20 ( V_3 , V_4 ) ;
else
V_27 = - V_30 ;
if ( V_27 < 0 )
F_21 ( V_3 -> V_31 , L_1 ,
V_27 ) ;
}
int F_22 ( struct V_2 * V_3 )
{
int V_27 = 0 ;
if ( V_3 -> V_32 ) {
V_27 = V_3 -> V_32 ( V_3 ) ;
if ( V_27 >= 0 ) {
V_3 -> V_4 = V_27 ;
return 0 ;
}
}
return V_27 ;
}
void F_23 ( struct V_2 * V_3 )
{
F_24 ( & V_3 -> V_33 ) ;
V_3 -> V_9 |= V_34 ;
}
void F_25 ( struct V_2 * V_3 )
{
F_24 ( & V_3 -> V_33 ) ;
V_3 -> V_9 &= ~ V_34 ;
}
