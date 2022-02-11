static int F_1 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( ! V_2 -> V_5 )
return - V_6 ;
V_2 -> V_5 ( V_2 , V_4 ) ;
return 0 ;
}
static int F_2 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( ! V_2 -> V_7 )
return - V_6 ;
return V_2 -> V_7 ( V_2 , V_4 ) ;
}
static void F_3 ( unsigned long V_8 )
{
struct V_1 * V_2 = ( void * ) V_8 ;
unsigned long V_9 ;
unsigned long V_10 ;
if ( ! V_2 -> V_11 || ! V_2 -> V_12 ) {
F_4 ( V_2 , V_13 ) ;
V_2 -> V_14 &= ~ V_15 ;
return;
}
if ( V_2 -> V_14 & V_16 ) {
V_2 -> V_14 &= ~ ( V_16 | V_15 ) ;
return;
}
V_9 = F_5 ( V_2 ) ;
if ( ! V_9 ) {
V_9 = V_2 -> V_17 ;
V_10 = V_2 -> V_11 ;
} else {
if ( ! ( V_2 -> V_14 & V_18 ) )
V_2 -> V_17 = V_9 ;
else
V_2 -> V_14 &= ~ V_18 ;
V_9 = V_13 ;
V_10 = V_2 -> V_12 ;
}
F_4 ( V_2 , V_9 ) ;
if ( V_2 -> V_14 & V_19 ) {
if ( V_2 -> V_14 & V_20 ) {
if ( V_9 )
V_2 -> V_14 |= V_16 ;
} else {
if ( ! V_9 )
V_2 -> V_14 |= V_16 ;
}
}
F_6 ( & V_2 -> V_21 , V_22 + F_7 ( V_10 ) ) ;
}
static void F_8 ( struct V_23 * V_24 )
{
struct V_1 * V_2 =
F_9 ( V_24 , struct V_1 , V_25 ) ;
int V_26 = 0 ;
if ( V_2 -> V_14 & V_27 ) {
V_2 -> V_28 = V_13 ;
F_10 ( V_2 ) ;
V_2 -> V_14 &= ~ V_27 ;
}
V_26 = F_1 ( V_2 , V_2 -> V_28 ) ;
if ( V_26 == - V_6 )
V_26 = F_2 ( V_2 ,
V_2 -> V_28 ) ;
if ( V_26 < 0 &&
! ( V_26 == - V_29 && ( V_2 -> V_14 & V_30 ) &&
( V_2 -> V_14 & V_31 ) ) )
F_11 ( V_2 -> V_32 ,
L_1 , V_26 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned long V_33 ,
unsigned long V_34 )
{
int V_35 ;
V_35 = F_5 ( V_2 ) ;
if ( V_35 )
V_2 -> V_17 = V_35 ;
if ( ! V_2 -> V_17 )
V_2 -> V_17 = V_2 -> V_36 ;
V_2 -> V_11 = V_33 ;
V_2 -> V_12 = V_34 ;
if ( ! V_33 ) {
F_4 ( V_2 , V_13 ) ;
return;
}
if ( ! V_34 ) {
F_4 ( V_2 ,
V_2 -> V_17 ) ;
return;
}
V_2 -> V_14 |= V_15 ;
F_6 ( & V_2 -> V_21 , V_22 + 1 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
unsigned long * V_33 ,
unsigned long * V_34 )
{
if ( ! ( V_2 -> V_14 & V_19 ) &&
V_2 -> V_37 &&
! V_2 -> V_37 ( V_2 , V_33 , V_34 ) )
return;
if ( ! * V_33 && ! * V_34 )
* V_33 = * V_34 = 500 ;
F_12 ( V_2 , * V_33 , * V_34 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_25 , F_8 ) ;
F_16 ( & V_2 -> V_21 , F_3 ,
( unsigned long ) V_2 ) ;
}
void F_17 ( struct V_1 * V_2 ,
unsigned long * V_33 ,
unsigned long * V_34 )
{
F_18 ( & V_2 -> V_21 ) ;
V_2 -> V_14 &= ~ V_19 ;
V_2 -> V_14 &= ~ V_16 ;
F_13 ( V_2 , V_33 , V_34 ) ;
}
void F_19 ( struct V_1 * V_2 ,
unsigned long * V_33 ,
unsigned long * V_34 ,
int V_38 )
{
if ( ( V_2 -> V_14 & V_19 ) &&
F_20 ( & V_2 -> V_21 ) )
return;
V_2 -> V_14 |= V_19 ;
V_2 -> V_14 &= ~ V_16 ;
if ( V_38 )
V_2 -> V_14 |= V_20 ;
else
V_2 -> V_14 &= ~ V_20 ;
F_13 ( V_2 , V_33 , V_34 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_21 ) ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = 0 ;
V_2 -> V_14 &= ~ V_15 ;
}
void F_21 ( struct V_1 * V_2 ,
enum V_3 V_9 )
{
if ( V_2 -> V_14 & V_15 ) {
if ( V_9 == V_13 ) {
V_2 -> V_14 |= V_27 ;
F_22 ( & V_2 -> V_25 ) ;
} else {
V_2 -> V_14 |= V_18 ;
V_2 -> V_17 = V_9 ;
}
return;
}
F_4 ( V_2 , V_9 ) ;
}
void F_23 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( ! F_1 ( V_2 , V_4 ) )
return;
V_2 -> V_28 = V_4 ;
F_22 ( & V_2 -> V_25 ) ;
}
void F_4 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
V_2 -> V_9 = F_24 ( V_4 , V_2 -> V_36 ) ;
if ( V_2 -> V_14 & V_39 )
return;
F_23 ( V_2 , V_2 -> V_9 ) ;
}
int F_25 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( V_2 -> V_11 || V_2 -> V_12 )
return - V_40 ;
V_2 -> V_9 = F_24 ( V_4 , V_2 -> V_36 ) ;
if ( V_2 -> V_14 & V_39 )
return 0 ;
return F_2 ( V_2 , V_2 -> V_9 ) ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_26 = 0 ;
if ( V_2 -> V_41 ) {
V_26 = V_2 -> V_41 ( V_2 ) ;
if ( V_26 >= 0 ) {
V_2 -> V_9 = V_26 ;
return 0 ;
}
}
return V_26 ;
}
void F_27 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_42 ) ;
V_2 -> V_14 |= V_43 ;
}
void F_29 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_42 ) ;
V_2 -> V_14 &= ~ V_43 ;
}
