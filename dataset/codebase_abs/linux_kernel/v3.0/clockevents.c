T_1 F_1 ( unsigned long V_1 , struct V_2 * V_3 )
{
T_1 V_4 = ( T_1 ) V_1 << V_3 -> V_5 ;
if ( F_2 ( ! V_3 -> V_6 ) ) {
V_3 -> V_6 = 1 ;
F_3 ( 1 ) ;
}
F_4 ( V_4 , V_3 -> V_6 ) ;
if ( V_4 < 1000 )
V_4 = 1000 ;
if ( V_4 > V_7 )
V_4 = V_7 ;
return V_4 ;
}
void F_5 ( struct V_2 * V_8 ,
enum V_9 V_10 )
{
if ( V_8 -> V_10 != V_10 ) {
V_8 -> V_11 ( V_10 , V_8 ) ;
V_8 -> V_10 = V_10 ;
if ( V_10 == V_12 ) {
if ( F_2 ( ! V_8 -> V_6 ) ) {
V_8 -> V_6 = 1 ;
F_3 ( 1 ) ;
}
}
}
}
void F_6 ( struct V_2 * V_8 )
{
F_5 ( V_8 , V_13 ) ;
V_8 -> V_14 . V_15 = V_7 ;
}
int F_7 ( struct V_2 * V_8 , T_2 V_16 ,
T_2 V_17 )
{
unsigned long long V_4 ;
T_3 V_18 ;
if ( F_2 ( V_16 . V_15 < 0 ) ) {
F_8 ( 1 ) ;
return - V_19 ;
}
V_18 = F_9 ( F_10 ( V_16 , V_17 ) ) ;
if ( V_18 <= 0 )
return - V_19 ;
V_8 -> V_14 = V_16 ;
if ( V_8 -> V_10 == V_13 )
return 0 ;
if ( V_18 > V_8 -> V_20 )
V_18 = V_8 -> V_20 ;
if ( V_18 < V_8 -> V_21 )
V_18 = V_8 -> V_21 ;
V_4 = V_18 * V_8 -> V_6 ;
V_4 >>= V_8 -> V_5 ;
return V_8 -> V_22 ( ( unsigned long ) V_4 , V_8 ) ;
}
int F_11 ( struct V_23 * V_24 )
{
unsigned long V_25 ;
int V_26 ;
F_12 ( & V_27 , V_25 ) ;
V_26 = F_13 ( & V_28 , V_24 ) ;
F_14 ( & V_27 , V_25 ) ;
return V_26 ;
}
static void F_15 ( unsigned long V_29 , void * V_8 )
{
F_16 ( & V_28 , V_29 , V_8 ) ;
}
static void F_17 ( void )
{
struct V_2 * V_8 ;
while ( ! F_18 ( & V_30 ) ) {
V_8 = F_19 ( V_30 . V_31 ,
struct V_2 , V_32 ) ;
F_20 ( & V_8 -> V_32 ) ;
F_21 ( & V_8 -> V_32 , & V_33 ) ;
F_15 ( V_34 , V_8 ) ;
}
}
void F_22 ( struct V_2 * V_8 )
{
unsigned long V_25 ;
F_23 ( V_8 -> V_10 != V_35 ) ;
if ( ! V_8 -> V_36 ) {
F_3 ( F_24 () > 1 ) ;
V_8 -> V_36 = F_25 ( F_26 () ) ;
}
F_12 ( & V_27 , V_25 ) ;
F_21 ( & V_8 -> V_32 , & V_33 ) ;
F_15 ( V_34 , V_8 ) ;
F_17 () ;
F_14 ( & V_27 , V_25 ) ;
}
static void F_27 ( struct V_2 * V_8 ,
T_4 V_37 )
{
T_1 V_38 ;
if ( ! ( V_8 -> V_39 & V_40 ) )
return;
V_38 = V_8 -> V_41 ;
F_4 ( V_38 , V_37 ) ;
if ( ! V_38 )
V_38 = 1 ;
else if ( V_38 > 600 && V_8 -> V_41 > V_42 )
V_38 = 600 ;
F_28 ( V_8 , V_37 , V_38 ) ;
V_8 -> V_21 = F_1 ( V_8 -> V_43 , V_8 ) ;
V_8 -> V_20 = F_1 ( V_8 -> V_41 , V_8 ) ;
}
void F_29 ( struct V_2 * V_8 ,
T_4 V_37 , unsigned long V_44 ,
unsigned long V_45 )
{
V_8 -> V_43 = V_44 ;
V_8 -> V_41 = V_45 ;
F_27 ( V_8 , V_37 ) ;
F_22 ( V_8 ) ;
}
int F_30 ( struct V_2 * V_8 , T_4 V_37 )
{
F_27 ( V_8 , V_37 ) ;
if ( V_8 -> V_10 != V_12 )
return 0 ;
return F_7 ( V_8 , V_8 -> V_14 , F_31 () ) ;
}
void F_32 ( struct V_2 * V_8 )
{
}
void F_33 ( struct V_2 * V_46 ,
struct V_2 * V_47 )
{
unsigned long V_25 ;
F_34 ( V_25 ) ;
if ( V_46 ) {
F_5 ( V_46 , V_35 ) ;
F_20 ( & V_46 -> V_32 ) ;
F_21 ( & V_46 -> V_32 , & V_30 ) ;
}
if ( V_47 ) {
F_23 ( V_47 -> V_10 != V_35 ) ;
F_6 ( V_47 ) ;
}
F_35 ( V_25 ) ;
}
void F_36 ( unsigned long V_29 , void * V_48 )
{
struct V_2 * V_8 , * V_49 ;
unsigned long V_25 ;
int V_50 ;
F_12 ( & V_27 , V_25 ) ;
F_15 ( V_29 , V_48 ) ;
switch ( V_29 ) {
case V_51 :
F_37 (dev, tmp, &clockevents_released, list)
F_20 ( & V_8 -> V_32 ) ;
V_50 = * ( ( int * ) V_48 ) ;
F_37 (dev, tmp, &clockevent_devices, list) {
if ( F_38 ( V_50 , V_8 -> V_36 ) &&
F_39 ( V_8 -> V_36 ) == 1 &&
! F_40 ( V_8 ) ) {
F_23 ( V_8 -> V_10 != V_35 ) ;
F_20 ( & V_8 -> V_32 ) ;
}
}
break;
default:
break;
}
F_14 ( & V_27 , V_25 ) ;
}
