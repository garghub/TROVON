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
static int F_7 ( struct V_2 * V_8 )
{
if ( V_8 -> V_16 >= V_17 ) {
F_8 ( V_18 L_1 ) ;
V_8 -> V_14 . V_15 = V_7 ;
return - V_19 ;
}
if ( V_8 -> V_16 < 5000 )
V_8 -> V_16 = 5000 ;
else
V_8 -> V_16 += V_8 -> V_16 >> 1 ;
if ( V_8 -> V_16 > V_17 )
V_8 -> V_16 = V_17 ;
F_8 ( V_18 L_2 ,
V_8 -> V_20 ? V_8 -> V_20 : L_3 ,
( unsigned long long ) V_8 -> V_16 ) ;
return 0 ;
}
static int F_9 ( struct V_2 * V_8 )
{
unsigned long long V_4 ;
T_2 V_21 ;
int V_22 ;
for ( V_22 = 0 ; ; ) {
V_21 = V_8 -> V_16 ;
V_8 -> V_14 = F_10 ( F_11 () , V_21 ) ;
if ( V_8 -> V_10 == V_13 )
return 0 ;
V_8 -> V_23 ++ ;
V_4 = ( ( unsigned long long ) V_21 * V_8 -> V_6 ) >> V_8 -> V_5 ;
if ( V_8 -> V_24 ( ( unsigned long ) V_4 , V_8 ) == 0 )
return 0 ;
if ( ++ V_22 > 2 ) {
if ( F_7 ( V_8 ) )
return - V_19 ;
V_22 = 0 ;
}
}
}
static int F_9 ( struct V_2 * V_8 )
{
unsigned long long V_4 ;
T_2 V_21 ;
V_21 = V_8 -> V_16 ;
V_8 -> V_14 = F_10 ( F_11 () , V_21 ) ;
if ( V_8 -> V_10 == V_13 )
return 0 ;
V_8 -> V_23 ++ ;
V_4 = ( ( unsigned long long ) V_21 * V_8 -> V_6 ) >> V_8 -> V_5 ;
return V_8 -> V_24 ( ( unsigned long ) V_4 , V_8 ) ;
}
int F_12 ( struct V_2 * V_8 , T_3 V_25 ,
bool V_26 )
{
unsigned long long V_4 ;
T_2 V_21 ;
int V_27 ;
if ( F_2 ( V_25 . V_15 < 0 ) ) {
F_13 ( 1 ) ;
return - V_19 ;
}
V_8 -> V_14 = V_25 ;
if ( V_8 -> V_10 == V_13 )
return 0 ;
if ( V_8 -> V_28 & V_29 )
return V_8 -> V_30 ( V_25 , V_8 ) ;
V_21 = F_14 ( F_15 ( V_25 , F_11 () ) ) ;
if ( V_21 <= 0 )
return V_26 ? F_9 ( V_8 ) : - V_19 ;
V_21 = F_16 ( V_21 , ( T_2 ) V_8 -> V_31 ) ;
V_21 = F_17 ( V_21 , ( T_2 ) V_8 -> V_16 ) ;
V_4 = ( ( unsigned long long ) V_21 * V_8 -> V_6 ) >> V_8 -> V_5 ;
V_27 = V_8 -> V_24 ( ( unsigned long ) V_4 , V_8 ) ;
return ( V_27 && V_26 ) ? F_9 ( V_8 ) : V_27 ;
}
int F_18 ( struct V_32 * V_33 )
{
unsigned long V_34 ;
int V_35 ;
F_19 ( & V_36 , V_34 ) ;
V_35 = F_20 ( & V_37 , V_33 ) ;
F_21 ( & V_36 , V_34 ) ;
return V_35 ;
}
static void F_22 ( unsigned long V_38 , void * V_8 )
{
F_23 ( & V_37 , V_38 , V_8 ) ;
}
static void F_24 ( void )
{
struct V_2 * V_8 ;
while ( ! F_25 ( & V_39 ) ) {
V_8 = F_26 ( V_39 . V_40 ,
struct V_2 , V_41 ) ;
F_27 ( & V_8 -> V_41 ) ;
F_28 ( & V_8 -> V_41 , & V_42 ) ;
F_22 ( V_43 , V_8 ) ;
}
}
void F_29 ( struct V_2 * V_8 )
{
unsigned long V_34 ;
F_30 ( V_8 -> V_10 != V_44 ) ;
if ( ! V_8 -> V_45 ) {
F_3 ( F_31 () > 1 ) ;
V_8 -> V_45 = F_32 ( F_33 () ) ;
}
F_19 ( & V_36 , V_34 ) ;
F_28 ( & V_8 -> V_41 , & V_42 ) ;
F_22 ( V_43 , V_8 ) ;
F_24 () ;
F_21 ( & V_36 , V_34 ) ;
}
void F_34 ( struct V_2 * V_8 , T_4 V_46 )
{
T_1 V_47 ;
if ( ! ( V_8 -> V_28 & V_48 ) )
return;
V_47 = V_8 -> V_49 ;
F_4 ( V_47 , V_46 ) ;
if ( ! V_47 )
V_47 = 1 ;
else if ( V_47 > 600 && V_8 -> V_49 > V_50 )
V_47 = 600 ;
F_35 ( V_8 , V_46 , V_47 ) ;
V_8 -> V_16 = F_1 ( V_8 -> V_51 , V_8 ) ;
V_8 -> V_31 = F_1 ( V_8 -> V_49 , V_8 ) ;
}
void F_36 ( struct V_2 * V_8 ,
T_4 V_46 , unsigned long V_52 ,
unsigned long V_53 )
{
V_8 -> V_51 = V_52 ;
V_8 -> V_49 = V_53 ;
F_34 ( V_8 , V_46 ) ;
F_29 ( V_8 ) ;
}
int F_37 ( struct V_2 * V_8 , T_4 V_46 )
{
F_34 ( V_8 , V_46 ) ;
if ( V_8 -> V_10 != V_12 )
return 0 ;
return F_12 ( V_8 , V_8 -> V_14 , false ) ;
}
void F_38 ( struct V_2 * V_8 )
{
}
void F_39 ( struct V_2 * V_54 ,
struct V_2 * V_55 )
{
unsigned long V_34 ;
F_40 ( V_34 ) ;
if ( V_54 ) {
F_5 ( V_54 , V_44 ) ;
F_27 ( & V_54 -> V_41 ) ;
F_28 ( & V_54 -> V_41 , & V_39 ) ;
}
if ( V_55 ) {
F_30 ( V_55 -> V_10 != V_44 ) ;
F_6 ( V_55 ) ;
}
F_41 ( V_34 ) ;
}
void F_42 ( void )
{
struct V_2 * V_8 ;
F_43 (dev, &clockevent_devices, list)
if ( V_8 -> V_56 )
V_8 -> V_56 ( V_8 ) ;
}
void F_44 ( void )
{
struct V_2 * V_8 ;
F_45 (dev, &clockevent_devices, list)
if ( V_8 -> V_57 )
V_8 -> V_57 ( V_8 ) ;
}
void F_46 ( unsigned long V_38 , void * V_58 )
{
struct V_2 * V_8 , * V_59 ;
unsigned long V_34 ;
int V_60 ;
F_19 ( & V_36 , V_34 ) ;
F_22 ( V_38 , V_58 ) ;
switch ( V_38 ) {
case V_61 :
F_47 (dev, tmp, &clockevents_released, list)
F_27 ( & V_8 -> V_41 ) ;
V_60 = * ( ( int * ) V_58 ) ;
F_47 (dev, tmp, &clockevent_devices, list) {
if ( F_48 ( V_60 , V_8 -> V_45 ) &&
F_49 ( V_8 -> V_45 ) == 1 &&
! F_50 ( V_8 ) ) {
F_30 ( V_8 -> V_10 != V_44 ) ;
F_27 ( & V_8 -> V_41 ) ;
}
}
break;
default:
break;
}
F_21 ( & V_36 , V_34 ) ;
}
