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
V_4 = V_3 -> V_11 ;
V_5 = V_3 -> V_6 ;
} else {
if ( ! ( V_3 -> V_9 & V_12 ) )
V_3 -> V_11 = V_4 ;
else
V_3 -> V_9 &= ~ V_12 ;
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
int V_20 = 0 ;
if ( V_3 -> V_9 & V_21 ) {
V_3 -> V_22 = V_8 ;
F_8 ( V_3 ) ;
V_3 -> V_9 &= ~ V_21 ;
}
if ( V_3 -> V_23 )
V_3 -> V_23 ( V_3 , V_3 -> V_22 ) ;
else if ( V_3 -> V_24 )
V_20 = V_3 -> V_24 ( V_3 ,
V_3 -> V_22 ) ;
else
V_20 = - V_25 ;
if ( V_20 < 0 )
F_9 ( V_3 -> V_26 ,
L_1 , V_20 ) ;
}
static void F_10 ( struct V_2 * V_3 ,
unsigned long V_27 ,
unsigned long V_28 )
{
int V_29 ;
V_29 = F_3 ( V_3 ) ;
if ( V_29 )
V_3 -> V_11 = V_29 ;
if ( ! V_3 -> V_11 )
V_3 -> V_11 = V_3 -> V_30 ;
V_3 -> V_6 = V_27 ;
V_3 -> V_7 = V_28 ;
if ( ! V_27 ) {
F_2 ( V_3 , V_8 ) ;
return;
}
if ( ! V_28 ) {
F_2 ( V_3 ,
V_3 -> V_11 ) ;
return;
}
F_4 ( & V_3 -> V_15 , V_16 + 1 ) ;
}
static void F_11 ( struct V_2 * V_3 ,
unsigned long * V_27 ,
unsigned long * V_28 )
{
if ( ! ( V_3 -> V_9 & V_13 ) &&
V_3 -> V_31 &&
! V_3 -> V_31 ( V_3 , V_27 , V_28 ) )
return;
if ( ! * V_27 && ! * V_28 )
* V_27 = * V_28 = 500 ;
F_10 ( V_3 , * V_27 , * V_28 ) ;
}
void F_12 ( struct V_2 * V_3 )
{
F_13 ( & V_3 -> V_19 , F_6 ) ;
F_14 ( & V_3 -> V_15 , F_1 ,
( unsigned long ) V_3 ) ;
}
void F_15 ( struct V_2 * V_3 ,
unsigned long * V_27 ,
unsigned long * V_28 )
{
F_16 ( & V_3 -> V_15 ) ;
V_3 -> V_9 &= ~ V_13 ;
V_3 -> V_9 &= ~ V_10 ;
F_11 ( V_3 , V_27 , V_28 ) ;
}
void F_17 ( struct V_2 * V_3 ,
unsigned long * V_27 ,
unsigned long * V_28 ,
int V_32 )
{
if ( ( V_3 -> V_9 & V_13 ) &&
F_18 ( & V_3 -> V_15 ) )
return;
V_3 -> V_9 |= V_13 ;
V_3 -> V_9 &= ~ V_10 ;
if ( V_32 )
V_3 -> V_9 |= V_14 ;
else
V_3 -> V_9 &= ~ V_14 ;
F_11 ( V_3 , V_27 , V_28 ) ;
}
void F_8 ( struct V_2 * V_3 )
{
F_16 ( & V_3 -> V_15 ) ;
V_3 -> V_6 = 0 ;
V_3 -> V_7 = 0 ;
}
void F_19 ( struct V_2 * V_3 ,
enum V_33 V_4 )
{
if ( V_3 -> V_6 || V_3 -> V_7 ) {
if ( V_4 == V_8 ) {
V_3 -> V_9 |= V_21 ;
F_20 ( & V_3 -> V_19 ) ;
} else {
V_3 -> V_9 |= V_12 ;
V_3 -> V_11 = V_4 ;
}
return;
}
F_2 ( V_3 , V_4 ) ;
}
void F_21 ( struct V_2 * V_3 ,
enum V_33 V_34 )
{
if ( V_3 -> V_23 ) {
V_3 -> V_23 ( V_3 , V_34 ) ;
return;
}
V_3 -> V_22 = V_34 ;
F_20 ( & V_3 -> V_19 ) ;
}
void F_2 ( struct V_2 * V_3 ,
enum V_33 V_34 )
{
V_3 -> V_4 = F_22 ( V_34 , V_3 -> V_30 ) ;
if ( V_3 -> V_9 & V_35 )
return;
F_21 ( V_3 , V_3 -> V_4 ) ;
}
int F_23 ( struct V_2 * V_3 ,
enum V_33 V_34 )
{
if ( V_3 -> V_6 || V_3 -> V_7 )
return - V_36 ;
V_3 -> V_4 = F_22 ( V_34 , V_3 -> V_30 ) ;
if ( V_3 -> V_9 & V_35 )
return 0 ;
if ( V_3 -> V_24 )
return V_3 -> V_24 ( V_3 ,
V_3 -> V_4 ) ;
return - V_25 ;
}
int F_24 ( struct V_2 * V_3 )
{
int V_20 = 0 ;
if ( V_3 -> V_37 ) {
V_20 = V_3 -> V_37 ( V_3 ) ;
if ( V_20 >= 0 ) {
V_3 -> V_4 = V_20 ;
return 0 ;
}
}
return V_20 ;
}
void F_25 ( struct V_2 * V_3 )
{
F_26 ( & V_3 -> V_38 ) ;
V_3 -> V_9 |= V_39 ;
}
void F_27 ( struct V_2 * V_3 )
{
F_26 ( & V_3 -> V_38 ) ;
V_3 -> V_9 &= ~ V_39 ;
}
