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
return;
}
if ( V_2 -> V_14 & V_15 ) {
V_2 -> V_14 &= ~ V_15 ;
return;
}
V_9 = F_5 ( V_2 ) ;
if ( ! V_9 ) {
V_9 = V_2 -> V_16 ;
V_10 = V_2 -> V_11 ;
} else {
if ( ! ( V_2 -> V_14 & V_17 ) )
V_2 -> V_16 = V_9 ;
else
V_2 -> V_14 &= ~ V_17 ;
V_9 = V_13 ;
V_10 = V_2 -> V_12 ;
}
F_4 ( V_2 , V_9 ) ;
if ( V_2 -> V_14 & V_18 ) {
if ( V_2 -> V_14 & V_19 ) {
if ( V_9 )
V_2 -> V_14 |= V_15 ;
} else {
if ( ! V_9 )
V_2 -> V_14 |= V_15 ;
}
}
F_6 ( & V_2 -> V_20 , V_21 + F_7 ( V_10 ) ) ;
}
static void F_8 ( struct V_22 * V_23 )
{
struct V_1 * V_2 =
F_9 ( V_23 , struct V_1 , V_24 ) ;
int V_25 = 0 ;
if ( V_2 -> V_14 & V_26 ) {
V_2 -> V_27 = V_13 ;
F_10 ( V_2 ) ;
V_2 -> V_14 &= ~ V_26 ;
}
V_25 = F_1 ( V_2 , V_2 -> V_27 ) ;
if ( V_25 == - V_6 )
V_25 = F_2 ( V_2 ,
V_2 -> V_27 ) ;
if ( V_25 < 0 &&
! ( V_25 == - V_28 && ( V_2 -> V_14 & V_29 ) &&
( V_2 -> V_14 & V_30 ) ) )
F_11 ( V_2 -> V_31 ,
L_1 , V_25 ) ;
}
static void F_12 ( struct V_1 * V_2 ,
unsigned long V_32 ,
unsigned long V_33 )
{
int V_34 ;
V_34 = F_5 ( V_2 ) ;
if ( V_34 )
V_2 -> V_16 = V_34 ;
if ( ! V_2 -> V_16 )
V_2 -> V_16 = V_2 -> V_35 ;
V_2 -> V_11 = V_32 ;
V_2 -> V_12 = V_33 ;
if ( ! V_32 ) {
F_4 ( V_2 , V_13 ) ;
return;
}
if ( ! V_33 ) {
F_4 ( V_2 ,
V_2 -> V_16 ) ;
return;
}
F_6 ( & V_2 -> V_20 , V_21 + 1 ) ;
}
static void F_13 ( struct V_1 * V_2 ,
unsigned long * V_32 ,
unsigned long * V_33 )
{
if ( ! ( V_2 -> V_14 & V_18 ) &&
V_2 -> V_36 &&
! V_2 -> V_36 ( V_2 , V_32 , V_33 ) )
return;
if ( ! * V_32 && ! * V_33 )
* V_32 = * V_33 = 500 ;
F_12 ( V_2 , * V_32 , * V_33 ) ;
}
void F_14 ( struct V_1 * V_2 )
{
F_15 ( & V_2 -> V_24 , F_8 ) ;
F_16 ( & V_2 -> V_20 , F_3 ,
( unsigned long ) V_2 ) ;
}
void F_17 ( struct V_1 * V_2 ,
unsigned long * V_32 ,
unsigned long * V_33 )
{
F_18 ( & V_2 -> V_20 ) ;
V_2 -> V_14 &= ~ V_18 ;
V_2 -> V_14 &= ~ V_15 ;
F_13 ( V_2 , V_32 , V_33 ) ;
}
void F_19 ( struct V_1 * V_2 ,
unsigned long * V_32 ,
unsigned long * V_33 ,
int V_37 )
{
if ( ( V_2 -> V_14 & V_18 ) &&
F_20 ( & V_2 -> V_20 ) )
return;
V_2 -> V_14 |= V_18 ;
V_2 -> V_14 &= ~ V_15 ;
if ( V_37 )
V_2 -> V_14 |= V_19 ;
else
V_2 -> V_14 &= ~ V_19 ;
F_13 ( V_2 , V_32 , V_33 ) ;
}
void F_10 ( struct V_1 * V_2 )
{
F_18 ( & V_2 -> V_20 ) ;
V_2 -> V_11 = 0 ;
V_2 -> V_12 = 0 ;
}
void F_21 ( struct V_1 * V_2 ,
enum V_3 V_9 )
{
if ( V_2 -> V_11 || V_2 -> V_12 ) {
if ( V_9 == V_13 ) {
V_2 -> V_14 |= V_26 ;
F_22 ( & V_2 -> V_24 ) ;
} else {
V_2 -> V_14 |= V_17 ;
V_2 -> V_16 = V_9 ;
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
V_2 -> V_27 = V_4 ;
F_22 ( & V_2 -> V_24 ) ;
}
void F_4 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
V_2 -> V_9 = F_24 ( V_4 , V_2 -> V_35 ) ;
if ( V_2 -> V_14 & V_38 )
return;
F_23 ( V_2 , V_2 -> V_9 ) ;
}
int F_25 ( struct V_1 * V_2 ,
enum V_3 V_4 )
{
if ( V_2 -> V_11 || V_2 -> V_12 )
return - V_39 ;
V_2 -> V_9 = F_24 ( V_4 , V_2 -> V_35 ) ;
if ( V_2 -> V_14 & V_38 )
return 0 ;
return F_2 ( V_2 , V_2 -> V_9 ) ;
}
int F_26 ( struct V_1 * V_2 )
{
int V_25 = 0 ;
if ( V_2 -> V_40 ) {
V_25 = V_2 -> V_40 ( V_2 ) ;
if ( V_25 >= 0 ) {
V_2 -> V_9 = V_25 ;
return 0 ;
}
}
return V_25 ;
}
void F_27 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_41 ) ;
V_2 -> V_14 |= V_42 ;
}
void F_29 ( struct V_1 * V_2 )
{
F_28 ( & V_2 -> V_41 ) ;
V_2 -> V_14 &= ~ V_42 ;
}
